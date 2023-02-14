#pragma once
#include <array>
#include <map>

namespace v
{
	struct Aim
	{
		bool triggerbot = false;
		bool silentAim = false;
		bool aimbot = false;
		bool rcs = false;
		bool rageAim = false;
	};
	inline auto aim = Aim{ };

	struct Visuals
	{
		std::pair<bool, std::array<float, 4U>> box{ false, {0.40f, 0.00f, 0.80f, 1.00f} };
		std::pair<bool, std::array<float, 4U>> filled{ false, {0.40f, 0.00f, 0.80f, 0.10f} };
		std::pair<bool, std::array<float, 4U>> outlined{ false, {0.40f, 0.00f, 0.80f, 1.00f} };
		std::pair<bool, std::array<float, 4U>> name{ false, {0.40f, 0.00f, 0.80f, 1.00f} };
		std::pair<bool, std::array<float, 4U>> weapName{ false, {0.40f, 0.00f, 0.80f, 1.00f} };
		std::pair<bool, std::array<float, 4U>> headdot{ false, {0.40f, 0.00f, 0.80f, 1.00f} };
		std::pair<bool, std::array<float, 4U>> snaplines{ false, {0.40f, 0.00f, 0.80f, 1.00f} };
		std::pair<bool, std::array<float, 4U>> snapToTarg{ false, {0.40f, 0.00f, 0.80f, 1.00f} };
		std::pair<bool, std::array<float, 4U>> health{ false, {0.40f, 0.00f, 0.80f, 1.00f} };
		std::pair<bool, std::array<float, 4U>> skeleton{ false, {0.40f, 0.00f, 0.80f, 1.00f} };
		std::pair<bool, std::array<float, 4U>> setAll{ false, {0.40f, 0.00f, 0.80f, 1.00f} };
		std::pair<bool, std::array<float, 4U>> fovCirc{ false, {0.40f, 0.00f, 0.80f, 1.00f} };

		std::array<float, 4U> world = { 1.f, 1.f, 1.f, 1.f };
		std::array<float, 4U> props = { 1.f, 1.f, 1.f, 1.f };
		std::array<float, 4U> sky = { 1.f, 1.f, 1.f, 1.f };

		std::pair<bool, std::array<float, 4U>> visible{ false, {0.40f, 0.00f, 0.80f, 1.00f} };
		std::pair<bool, std::array<float, 4U>> hidden{ false, {0.1f, 1.f, 1.f, 1.f} };
		std::pair<bool, std::array<float, 4U>> item{ false, {0.40f, 0.00f, 0.80f, 1.00f} };
		std::pair<bool, std::array<float, 4U>> arm{ false, {0.40f, 0.00f, 0.80f, 1.00f} };
		std::pair<bool, std::array<float, 4U>> sleeve{ false, {0.40f, 0.00f, 0.80f, 1.00f} };

		std::pair<bool, std::array<float, 4U>> player{ false, {0.40f, 0.00f, 0.80f, 1.00f} };
		std::pair<bool, std::array<float, 4U>> weapon{ false, {0.40f, 0.00f, 0.80f, 1.00f} };
		std::pair<bool, std::array<float, 4U>> grenade{ false, {0.40f, 0.00f, 0.80f, 1.00f} };
		std::pair<bool, std::array<float, 4U>> bomb{ false, {0.40f, 0.00f, 0.80f, 1.00f} };
		std::pair<bool, std::array<float, 4U>> chicken{ false, {0.40f, 0.00f, 0.80f, 1.00f} };
	};
	inline auto visuals = Visuals{ };

	struct Misc
	{
		bool bunnyHop = false;
		bool ranks = false;
		bool radar = false;
		bool votes = false;
		bool money = false;
		bool knife = false;

		bool karam = false;
		bool bayonet = false;
		bool m9bayo = false;
		bool butterfly = false;
		int fov = 0;
		float viewModelFov = 62.f;
		float worldFov = 90.f;

		std::pair<bool, std::array<float, 4U>> sniperCrosshair = { false, {0.40f, 0.00f, 0.80f, 1.00f} };
		std::pair<bool, std::array<float, 4U>> hitEffect = { false, {0.40f, 0.00f, 0.80f, 1.00f} };
	};
	inline auto misc = Misc{ };

	struct Skins
	{

	};
	inline auto skins = Skins{ };
}
