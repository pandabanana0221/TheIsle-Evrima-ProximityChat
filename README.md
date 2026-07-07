# TheIsle-Evrima-ProximityChat
DX11 positional audio helper for The Isle Evrima (MumbleLink)
How to Use the Evrima Proximity Chat Helper

Start The Isle: Evrima first.
The helper needs the game running so it can detect the process and read your position.

Open Mumble and make sure positional audio is enabled.
Go to Configure, then Settings, then Plugins, and make sure the MumbleLink plugin is turned on.

Run the helper executable.
The file is located in:
src\x64\Release\TheIsle_Evrima_MumbleLink_DX11.exe

Watch the console window.
It should show messages like:
Starting
Found Evrima process
Module base found
MumbleLink initialized

Leave the helper running while you play.
It will constantly read your player position and send it to Mumble.

Talk in Mumble normally.
Other players will hear you based on your in‑game distance and direction.

If the helper cannot find your position, update the memory offsets.
The current version uses a placeholder offset.
When the correct offset is added, positional audio will match your exact location.

Close the helper when you exit the game.
It does not modify any game files and is safe to close at any time.
Troubleshooting

The helper says it cannot find the Evrima process.
Make sure The Isle: Evrima is already running before you start the helper.
The helper looks for the process name TheIsle-Win64-Shipping.exe.
If the game updated and changed the process name, update the code to match.

The helper window closes immediately.
Run it from a command prompt so you can see the error message.
This usually means the game was not running or MumbleLink failed to initialize.

Mumble does not show positional audio.
Open Mumble, go to Configure, then Settings, then Plugins.
Make sure the MumbleLink plugin is enabled.
Restart Mumble after enabling it.

Voices sound the same distance no matter where players are.
This means the player position offset in the helper is incorrect.
The current version uses a placeholder offset.
You must update the offset after each Evrima patch.

The helper finds the process but does not update position.
This also means the memory offset is wrong or the game updated.
You will need to scan for the correct player position address.

The helper runs but Mumble shows no movement.
Make sure you are in a Mumble server that supports positional audio.
Some servers disable positional audio for privacy or moderation reasons.

Antivirus flags the helper.
This is normal for any program that reads memory from another process.
Add an exception for the helper if needed.

The helper stops working after an Evrima update.
Updates change memory layouts.
You will need to update the offsets and rebuild the helper.
