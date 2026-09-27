# Low Level, High Speed — C++ / SFML Game

**Low Level, High Speed** is a 2D driving game developed in **C++ with SFML** as a university programming project.

Rather than relying on a game engine, the project implements gameplay systems directly in C++, including movement, enemy spawning and sequencing, collisions, projectiles, animation, scrolling backgrounds, UI, audio, game states, and manual data structures.

![Low Level, High Speed](Trabajo%20Final%20MAVI%20Pilar%20Marco/lowlevelhighspeed.png)

## Technical Highlights

- C++ gameplay programming without a game engine
- SFML graphics, windowing, system, and audio modules
- Delta-time-based player and enemy movement
- Acceleration, deceleration, velocity limits, and boundary handling
- Scrolling road/background system driven by player velocity
- Enemy traffic managed through custom linked-list queues
- Multiple enemy waves with different lanes, directions, and speeds
- Collision detection between the player, traffic, projectiles, and an animated NPC
- Temporary invulnerability after collisions
- Damage feedback with a damaged-car state and animated smoke
- Projectile/bomb mechanic with limited uses
- Win, lose, and restart game states
- Sprite-sheet animation
- Background music, ambience, and gameplay sound effects

## Gameplay

The player drives through traffic while avoiding collisions and progressing through successive waves of vehicles.

The car can move horizontally and change its forward/backward velocity. The road scroll is tied to the player's vertical velocity, creating the sensation of driving through the level.

The player has **3 lives** and a limited bomb/projectile mechanic that can remove enemy vehicles. After the first traffic sequence, an animated NPC appears before the second wave begins. Clearing the complete sequence triggers the victory state.

## Controls

- **Arrow keys** — control the car
- **Space** — launch a bomb/projectile
- **Enter** — restart the game

## Architecture

The code is separated into gameplay-focused classes:

- **`Player`** — movement, acceleration/deceleration, velocity and screen limits.
- **`Enemigo`** — enemy vehicle data, sprites, speed, and linked-list node information.
- **`Colas`** — custom enemy queues and traffic-wave sequencing.
- **`Colisiones`** — player/enemy, projectile/enemy and NPC/player collision logic, damage states, invulnerability, and smoke animation.
- **`Proyectil`** — bomb spawning and movement.
- **`Background`** — continuous scrolling background.
- **`Inocente`** — animated NPC movement.
- **`Audio`** — music, ambience, engine, collision, and bomb sounds using SFML Audio.
- **`UI` / animation classes** — countdown and game-state visuals plus sprite animation.

The main game loop coordinates these systems at a **60 FPS limit** while movement calculations use frame delta time.

## Data Structures

One of the project's main programming exercises is the traffic system.

Enemy vehicles are organized through manually implemented **linked-list queues**. Each lane maintains pointers to its first and last enemy, and enemies are inserted, removed, repositioned, and advanced through multiple waves.

This project therefore combines gameplay programming with lower-level C++ concepts such as:

- pointers
- dynamic allocation
- linked structures
- object-oriented decomposition
- state management
- real-time update loops

## Audio

Audio is implemented directly through **SFML Audio**.

The project loads and controls:

- looping background music
- looping ambience
- engine audio
- collision SFX
- bomb SFX

## Built With

- **C++**
- **SFML 2.5.1**
- **Visual Studio / MSVC v143**
- Windows 10 SDK
- x64 project configuration

The Visual Studio project currently references SFML 2.5.1 for its include and library paths.

## Running / Building

The repository contains the Visual Studio project and the game's assets.

For a local build:

1. Install **SFML 2.5.1**.
2. Open the Visual Studio solution/project.
3. Update the SFML include/library paths if SFML is installed somewhere other than `C:\\SFML-2.5.1`.
4. Build the x64 configuration.
5. Keep the required image/audio assets and SFML runtime DLLs available to the executable.

## About

This project was developed as part of my **Video Game Design and Programming** studies.

It is included in my portfolio as an example of gameplay programming in C++ outside a commercial engine, with particular emphasis on real-time systems, object-oriented organization, manual data structures, collision logic, animation, and audio integration.
