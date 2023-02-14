#include "aim.h"

#include "../core/hooks.h"
#include "../sdk/definitions.h"
#include "../core/netvar.h"
#include"../sdk/data/vector.h"
#include <string>

void Aim::Aimbot(UserCmd* cmd)
{
	if (v::aim.aimbot)
	{
		if (!(cmd->buttons & UserCmd::IN_ATTACK))
			return;

		if (g::localPlayer->IsDefusing())
			return;

		BaseAttributableItem* activeWeapon = g::localPlayer->GetActiveWeapon();

		if (!activeWeapon)
			return;

		const auto data = i::weapon->GetWeaponData(activeWeapon->ItemDefinitionIndex());

		const int WeaponType = data->weaponType;

		switch (WeaponType)
		{
		case WeaponType::WEAPONTYPE_MACHINEGUN:
		case WeaponType::WEAPONTYPE_RIFLE:
		case WeaponType::WEAPONTYPE_SHOTGUN:
		case WeaponType::WEAPONTYPE_SNIPER:
		case WeaponType::WEAPONTYPE_PISTOL:
		{
			if (WeaponType == WeaponType::WEAPONTYPE_SNIPER)
			{
				if (!g::localPlayer->IsScoped())
					return;
			}

			break;
		}

		default:
			return;
		}

		Vector bestAngle{ };
		float bestFov{ 5.f };
		bestFov = v::misc.fov;
		for (const auto& player : g::entities.playerList)
		{
			if (!player)
				continue;

			if (player->IsDormant() || !player->IsAlive())
				continue;

			if (player->GetTeam() == g::localPlayer->GetTeam() && player == g::localPlayer)
				continue;

			if (player->HasGunGameImmunity())
				continue;

			

			Matrix3x4 bones[128];
			if (!player->SetupBones(bones, 128, 256, i::globals->currentTime))
				continue;

			Vector localEyePos = g::localPlayer->GetEyePosition();

			switch (WeaponType)
			{
			case WeaponType::WEAPONTYPE_MACHINEGUN:
			case WeaponType::WEAPONTYPE_RIFLE:
			case WeaponType::WEAPONTYPE_SUBMACHINEGUN:
				Vector aimPunch = g::localPlayer->GetAimPunch();
			}

			Trace trace;

			TraceFilter lol(g::localPlayer);

			i::trace->TraceRay(
				Ray{ localEyePos,bones[8].at(3) },
				MASK_SHOT,
				&lol,
				&trace
			);
			
			if (!trace.entity || trace.fraction < 0.97f)
				return;

			Vector enemyAngle
			{
				(bones[8].at(3) - localEyePos).ToAngle() - (cmd->viewPoint + g::localPlayer->GetAimPunch())
			};

			if (const float fov = std::hypot(enemyAngle.x, enemyAngle.y); fov < bestFov)
			{
				bestFov = fov;
				bestAngle = enemyAngle;

			}
		}

		

		cmd->viewPoint = cmd->viewPoint + bestAngle;
	}
}

