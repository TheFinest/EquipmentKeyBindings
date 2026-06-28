# Equipment Key Bindings (Client-Side)

A Satisfactory mod that binds your 6 arm/hand equipment slots to specific keys, so you can switch weapons/tools directly instead of scrolling through them in combat.

This is a **client-only** fork, ported to **Satisfactory 1.2**. The back-equipment swapping and unequip features from the original mod have been removed, so it no longer needs to be installed on the server — install it on your client only and it works when joining any host (vanilla or modded).

> **Not on the Mod Manager (SMR).** This mod is **not** published to [ficsit.app](https://ficsit.app) and cannot be installed through the Satisfactory Mod Manager's search. You install it manually from the [Releases](../../releases) page on this repo. This README walks you through that.

---

## TL;DR (if you already know Satisfactory modding)

- Game: Satisfactory `CL# >=491125` (1.2)
- Requires: SML `3.12.0` or newer
- Folder is a **GameFeature mod** → install into `FactoryGame/Mods/GameFeatures/EquipmentKeyBindings/`
- Client-side only (`RequiredOnRemote: false`)

---

## What this mod does

Adds six rebindable keybinds (visible under **Options → Controls → Keybindings**) that directly select arm-equipment slots 1–6. It calls the base-game's `Server_SetActiveEquipmentIndex` RPC, which the server honors even without the mod installed, so it works in multiplayer without server-side setup.

---

## How Satisfactory mods are organized (read this first)

If you've never modded Satisfactory, there are a few concepts worth knowing before you install anything. These apply to **every** Satisfactory mod, not just this one:

1. **SML (Satisfactory Mod Loader)** is the thing that makes mods load at all. Most mods depend on it. You install SML once, and then drop mod folders next to it.
2. **A mod is just a folder** containing an `EquipmentKeyBindings.uplugin` file plus subfolders (`Binaries/`, `Content/`, etc.). The folder name **must exactly match** the name in its `.uplugin` (here: `EquipmentKeyBindings`).
3. **Two install locations exist**, chosen by the mod's `GameFeature` field (found inside the `.uplugin`):
   - `GameFeature: true` → goes in `FactoryGame/Mods/GameFeatures/`
   - `GameFeature: false` (or absent) → goes in `FactoryGame/Mods/`

   This mod is a **GameFeature mod**, so it belongs under `GameFeatures/`. For the full explanation, see the official **[Manual Installation](https://docs.ficsit.app/satisfactory-modding/latest/ManualInstallDirections.html)** guide.

4. **SMM (Satisfactory Mod Manager) vs manual install:** SMM is the easy, one-click installer, but it only works for mods published to the SMR website. Since this mod isn't on SMR, you install it **manually** — which is exactly what the rest of this README covers.

These concepts are explained in the official docs at [docs.ficsit.app](https://docs.ficsit.app/satisfactory-modding/latest/ForUsers/Welcome.html).

---

## Requirements

- **Satisfactory** version `CL# 491125` or newer (the 1.2 release line).
- **SML 3.12.0** or newer. SML is the mod loader; this mod won't run without it.

You can check your game's CL# in-game from **Options → "About"**, or by looking at the Satisfactory install's file properties. See the [Modding FAQ](https://docs.ficsit.app/satisfactory-modding/latest/faq.html#Files_GameInstall) if you can't find your install directory.

---

## Installation

You do **not** need Unreal Engine, Visual Studio, or any development tools to install the mod. The Releases page contains a ready-to-use, pre-built package.

### Step 0 — Install SML (only once)

If you haven't installed SML yet, follow the official **[Manual Installation → Installing SML](https://docs.ficsit.app/satisfactory-modding/latest/ManualInstallDirections.html#_installing_sml)** section. In short: download the SML mod from its [SMR page](https://ficsit.app/mod/SML), then unzip it so you end up with:

```
<Satisfactory install>/FactoryGame/Mods/SML/SML.uplugin
```

Note that the `Mods` folder is **inside `FactoryGame/`**, not at the game root. Create the `Mods` folder if it doesn't exist.

> If you already use the Satisfactory Mod Manager, it has already installed SML for you and you can skip this step.

### Step 1 — Download the mod

Go to the **[Releases](../../releases)** tab of this repo and download the `.zip` from the latest release (e.g. `EquipmentKeyBindings.zip`).

### Step 2 — Unzip it into the GameFeatures folder

Because this is a `GameFeature` mod, its files go under `FactoryGame/Mods/GameFeatures/`. Unzip the downloaded archive so that you end up with:

```
<Satisfactory install>/FactoryGame/Mods/GameFeatures/EquipmentKeyBindings/EquipmentKeyBindings.uplugin
<Satisfactory install>/FactoryGame/Mods/GameFeatures/EquipmentKeyBindings/Binaries/...
<Satisfactory install>/FactoryGame/Mods/GameFeatures/EquipmentKeyBindings/Content/...
```

The inner folder **must be named exactly `EquipmentKeyBindings`** (matching the `.uplugin` filename). If your unzipper nests it one level deep, flatten it so `EquipmentKeyBindings.uplugin` sits directly inside the `EquipmentKeyBindings/` folder.

#### Finding your Satisfactory install

Common locations:

- Steam (Windows): `C:\Program Files (x86)\Steam\steamapps\common\Satisfactory`
- Epic (Windows): `C:\Program Files\Epic Games\Satisfactory`

If you're unsure, the [official FAQ](https://docs.ficsit.app/satisfactory-modding/latest/faq.html#Files_GameInstall) describes how to locate it for each store.

### Step 3 — Launch the game

Launch Satisfactory normally (through Steam/Epic — no special launcher needed). The mod loads automatically. The six keybinds appear under **Options → Controls → Keybindings**, where you can rebind them to whatever keys you prefer.

### Step 4 — Verify it works

- Open the keybind menu; you should see six entries for equipment slots 1–6.
- In-game, press a bound key; the matching hand-equipment slot is selected directly.
- If nothing happens, confirm SML is installed and the `GameVersion` in `EquipmentKeyBindings.uplugin` (`>=491125`) matches your game's CL#.

---

## Multiplayer / Dedicated servers

This mod is **client-side only**. It uses a base-game client→server RPC to switch equipment, so:

- You can install it on your client only.
- You can join any host — vanilla or modded — without the server needing this mod.
- The host does **not** need SML or this mod installed.

Because `RequiredOnRemote` is `false` in the `.uplugin`, the game won't block you from joining servers that don't have it.

---

## Updating

To update to a newer release later:

1. Delete the old `FactoryGame/Mods/GameFeatures/EquipmentKeyBindings/` folder.
2. Repeat the installation steps above with the new zip.

There's no need to uninstall SML or other mods.

---

## Troubleshooting

- **Mod doesn't load / keybinds missing:** Double-check the folder is at `FactoryGame/Mods/GameFeatures/EquipmentKeyBindings/` (the `GameFeatures` subfolder is required for this mod — see [How Satisfactory mods are organized](#how-satisfactory-mods-are-organized-read-this-first)). The folder name must be exactly `EquipmentKeyBindings`.
- **"Mod is outdated" / game won't launch:** Your Satisfactory version is older than the mod's `GameVersion` (`>=491125`). Update Satisfactory, or use an older release of this mod if one exists.
- **Keybinds show but don't do anything:** Make sure SML is installed and up to date (≥ 3.12.0). The mod depends on SML being present at load time.
- **Nothing else helped:** The [Modding FAQ](https://docs.ficsit.app/satisfactory-modding/latest/faq.html) covers common install issues.

---

## For modders / building from source

You only need this section if you want to **modify or recompile** the mod. Players just installing it can ignore everything below.

### Prerequisites

Building requires the full Satisfactory modding toolchain — there is no way around installing Unreal Engine if you want to edit Blueprint assets or compile the C++:

1. **Visual Studio 2022** with the MSVC v143 toolset used by UE 5.3.
2. The custom **Unreal Engine 5.3.2-CSS** build (the one Satisfactory ships with). You can't use a stock Epic launcher UE install.
3. The **Satisfactory Modding Starter Project** matching your game/SML version, from the [starter project docs](https://docs.ficsit.app/satisfactory-modding/latest/Development/BeginnersGuide/StarterProject/ObtainStarterProject.html).

The official **[Getting Started](https://docs.ficsit.app/satisfactory-modding/latest/Development/BeginnersGuide/index.html)** guide walks through all of the above in detail.

### Placing this mod in the starter project

This mod is a **GameFeature plugin**, which means it **must** live under `Mods/GameFeatures/` inside the starter project for the Game Feature to activate correctly (plugins elsewhere fail with an `Invalid PluginProtocol` error). So:

```
<StarterProject>/Mods/GameFeatures/EquipmentKeyBindings/
```

Drop this repo's contents there. The folder name must be `EquipmentKeyBindings` (matching the `.uplugin`).

### Building & packaging

Follow the official guide for compiling and packaging with **Alpakit**:

- [Create a Simple Mod (overview)](https://docs.ficsit.app/satisfactory-modding/latest/Development/BeginnersGuide/SimpleMod/index.html)
- [Releasing Your Mod](https://docs.ficsit.app/satisfactory-modding/latest/Development/BeginnersGuide/ReleaseMod.html) — covers the **Alpakit Release** flow (all three targets: Windows, WindowsServer, LinuxServer) that produces the multi-target zip distributed in Releases.

To produce a Windows-client-only build for quick local testing, use Alpakit's **Development** packaging (copies the mod into your game's `FactoryGame/Mods/GameFeatures/` directly). For a redistributable package, use **Alpakit Release** and attach the resulting zip from `Saved/ArchivedPlugins/EquipmentKeyBindings/` to a GitHub Release.

### What this fork changed (port notes)

The following changes were made when porting from the original to Satisfactory 1.2 / SML 3.12:

- `.uplugin`: `GameVersion` → `>=491125`, SML dependency → `^3.12.0`, `RequiredOnRemote` removed (client-only), `BuiltInInitialFeatureState: "Active"` added so the Game Feature loads without manual activation.
- An `FGGameFeatureData` asset named `EquipmentKeyBindings` (matching the mod reference) with a primary-asset scan rule for `FGChildInputMappingContext` under `Content/Inputs`. (It must be the Satisfactory `FGGameFeatureData` subclass, not the plain Unreal `GameFeatureData`, for the feature to activate.)
- Removed all back-equipment swap logic, RCO, config widgets, and the swap Input Actions/subsystem — only the six arm-equipment select actions remain.
- C++ helper `SelectArmEquipmentByIndex(AFGCharacterPlayer*, int32)` calls the base-game `UFGInventoryComponentEquipment::Server_SetActiveEquipmentIndex` (a client→server RPC), so the mod works without server-side installation.
- A `BP_EquipmentInputHandler` actor (spawned by the Game World Module) wires the six `IA_TriggerSelectEquipment_0X` Enhanced Input actions to `SelectArmEquipmentByIndex` with indices 0–5.

For the underlying concepts (Game Features, Enhanced Input, Mod Subsystems), see the Satisfactory modding docs:
- [Game Feature Data Asset](https://docs.ficsit.app/satisfactory-modding/latest/Development/Satisfactory/GameFeatureDataAsset.html)
- [Enhanced Input System](https://docs.ficsit.app/satisfactory-modding/latest/Development/Satisfactory/EnhancedInputSystem.html)
- [Mod Subsystems](https://docs.ficsit.app/satisfactory-modding/latest/Development/ModLoader/Subsystems.html)

---

## Credits

Based on the original **Equipment Key Bindings** mod by Vanzin. This fork ports it to Satisfactory 1.2 (SML 3.12) and trims it to a client-only hand-equipment keybind mod.

## License

See the upstream repository for license terms.
