#include "config.h"

#include <filesystem>
#include <fstream>

#include "../../external/json/json.hpp"

#include "../core/interfaces.h"

void Config::Setup()
{
	ExistCheck();
	Refresh();
}

void Config::ExistCheck()
{
	if (!std::filesystem::exists(baseDir))
	{
		std::filesystem::create_directory(baseDir);

		if (!std::filesystem::exists(configDir))
			std::filesystem::create_directory(configDir);
	}
}

void Config::Refresh()
{
	ExistCheck();

	// Flush the config list
	configs.clear();

	for (const auto& dir : std::filesystem::recursive_directory_iterator(configDir))
	{
		if (!dir.exists() || !dir.is_regular_file())
			continue;

		const auto& path = dir.path();

		if (!path.has_filename() || !path.has_extension())
			continue;

		if (!path.extension().generic_string().ends_with(".json"))
			continue;

		configs.push_back(path.filename().generic_string());
	}
}

void Config::Create()
{
	ExistCheck();

	// Create a string to use *modern* string functions
	auto name = std::string(nameBuffer);

	if (name.empty())
		return;

	if (!name.ends_with(".json"))
		name += std::string(".json");

	const auto file = std::ofstream(configDir + std::string("/") + name);

	Refresh();
}

void Config::Delete()
{
	ExistCheck();

	if (configs.empty())
		return;

	std::filesystem::remove(configDir + std::string("/") + GetSelectedName());

	Refresh();
}

#define READ(j, var) v::var = j[#var];
#define READ_ARR(j, var) std::copy(j[#var].begin(), j[#var].end(), v::space::var);
#define WRITE(j, var) j[#var] = v::var;

void Config::Load() {

	if (GetSelectedName() == NULL)
		return;
	nlohmann::json j;
	std::fstream read(configDir + std::string("/") + GetSelectedName());
	read >> j;
	read.close();

	READ(j, visuals.visible.first)
	READ(j, visuals.visible.second)
	READ(j, visuals.hidden.first)

	READ(j, visuals.hidden.second)
	READ(j, misc.sniperCrosshair.first)
	READ(j, misc.sniperCrosshair.second)

	READ(j, visuals.box.first)
	READ(j, visuals.box.second)
	READ(j, visuals.filled.first)

	READ(j, visuals.filled.second)
	READ(j, visuals.outlined.first)
	READ(j, visuals.outlined.second)

	READ(j, visuals.name.first)
	READ(j, visuals.name.second)
	READ(j, visuals.weapName.first)

	READ(j, visuals.weapName.second)
	READ(j, visuals.headdot.first)
	READ(j, visuals.headdot.second)

	READ(j, visuals.snaplines.first)
	READ(j, visuals.snaplines.second)
	READ(j, visuals.health.first)

	READ(j, visuals.health.second)
	READ(j, visuals.skeleton.first)
	READ(j, visuals.skeleton.second)

	READ(j, visuals.item.first)
	READ(j, visuals.item.second)
	READ(j, visuals.arm.first)

	READ(j, visuals.arm.second)
	READ(j, visuals.sleeve.first)
	READ(j, visuals.sleeve.second)

	READ(j, visuals.player.first)
	READ(j, visuals.player.second)
	READ(j, visuals.weapon.first)

	READ(j, visuals.weapon.second)
	READ(j, visuals.grenade.first)
	READ(j, visuals.grenade.second)

	READ(j, visuals.bomb.first)
	READ(j, visuals.bomb.second)
	READ(j, visuals.chicken.first)

	READ(j, visuals.chicken.second)
	READ(j, aim.aimbot)
	READ(j, misc.bunnyHop)

	READ(j, misc.ranks)
	READ(j, misc.radar)
	READ(j, misc.votes)

	READ(j, misc.money)
	READ(j, misc.viewModelFov)
	READ(j, misc.worldFov)

	READ(j, misc.hitEffect.first)
	READ(j, misc.hitEffect.second)
	READ(j, misc.fov)
	// etc, etc etc

}

void Config::Save() {
	if (GetSelectedName() == NULL)
		return;
	nlohmann::json j;

	WRITE(j, visuals.visible.first)
	WRITE(j, visuals.visible.second)
	WRITE(j, visuals.hidden.first)

	WRITE(j, visuals.hidden.second)
	WRITE(j, misc.sniperCrosshair.first)
	WRITE(j, misc.sniperCrosshair.second)

	WRITE(j, visuals.box.first)
	WRITE(j, visuals.box.second)
	WRITE(j, visuals.filled.first)

	WRITE(j, visuals.filled.second)
	WRITE(j, visuals.outlined.first)
	WRITE(j, visuals.outlined.second)

	WRITE(j, visuals.name.first)
	WRITE(j, visuals.name.second)
	WRITE(j, visuals.weapName.first)

	WRITE(j, visuals.weapName.second)
	WRITE(j, visuals.headdot.first)
	WRITE(j, visuals.headdot.second)

	WRITE(j, visuals.snaplines.first)
	WRITE(j, visuals.snaplines.second)
	WRITE(j, visuals.health.first)

	WRITE(j, visuals.health.second)
	WRITE(j, visuals.skeleton.first)
	WRITE(j, visuals.skeleton.second)

	WRITE(j, visuals.item.first)
	WRITE(j, visuals.item.second)
	WRITE(j, visuals.arm.first)

	WRITE(j, visuals.arm.second)
	WRITE(j, visuals.sleeve.first)
	WRITE(j, visuals.sleeve.second)

	WRITE(j, visuals.player.first)
	WRITE(j, visuals.player.second)
	WRITE(j, visuals.weapon.first)

	WRITE(j, visuals.weapon.second)
	WRITE(j, visuals.grenade.first)
	WRITE(j, visuals.grenade.second)

	WRITE(j, visuals.bomb.first)
	WRITE(j, visuals.bomb.second)
	WRITE(j, visuals.chicken.first)

	WRITE(j, visuals.chicken.second)
	WRITE(j, aim.aimbot)
	WRITE(j, misc.bunnyHop)

	WRITE(j, misc.ranks)
	WRITE(j, misc.radar)
	WRITE(j, misc.votes)

	WRITE(j, misc.money)
	WRITE(j, misc.viewModelFov)
	WRITE(j, misc.worldFov)

	WRITE(j, misc.hitEffect.first)
	WRITE(j, misc.hitEffect.second)
	WRITE(j, misc.fov)

	std::ofstream write(configDir + std::string("/") + GetSelectedName());
	write << j << std::endl;
	write.close();
}
