/*
 * A2xTech - A platform game engine ported from old source code for VB6
 *
 * Copyright (c) 2009-2011 Andrew Spinks, original VB6 code
 * Copyright (c) 2020-2020 Vitaly Novichkov <admin@wohlnet.ru>
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include "globals.h"

FrmMain frmMain;
GFX_t GFX;

bool GameIsActive = false;
std::string AppPath;

int numSavedEvents = 0;
RangeArr<std::string, 1, MaxSavedEvents> SavedEvents;
RangeArrI<bool, 1, 4, false> BlockSwitch;
RangeArrI<bool, 2, 7, false> PowerUpUnlock;
long myBackBuffer = 0;
long myBufferBMP = 0;
int AllCharBlock = 0;
bool StartMenu = false;
int BlockFlash = 0;
bool ScrollRelease = false;
bool TakeScreen = false;
std::string LB;
std::string EoT;
RangeArr<ConKeyboard_t, 1, 2> conKeyboard;
RangeArr<ConJoystick_t, 1, 2> conJoystick;
RangeArrI<int, 1, 2, 0> useJoystick;

int ScreenShake = 0;
std::string Checkpoint;
std::vector<Checkpoint_t> CheckpointsList;
bool MagicHand = false;
RangeArr<Player_t, 1, 2> testPlayer;
bool ClearBuffer = false;
int numLocked = 0;
bool resChanged = false;
int inputKey = 0;
bool getNewKeyboard = false;
bool getNewJoystick = false;
int lastJoyButton = 0;
bool GamePaused = false;
std::string MessageText;
int NumSelectWorld  = 0;
RangeArr<SelectWorld_t, 1, maxSelectWorlds> SelectWorld;
bool ShowFPS = false;
double PrintFPS = 0.0;
RangeArr<vScreen_t, 0, 2> vScreen;
int ScreenType = 0;
int DScreenType = 0;
bool LevelEditor = false;
bool WorldEditor = false;
RangeArr<Location_t, 1, 2> PlayerStart;
RangeArrI<bool, 0, 20, false> blockCharacter;
RangeArrI<int, 0, maxPlayers, 0> OwedMount;
RangeArrI<int, 0, maxPlayers, 0> OwedMountType;
RangeArr<float, 0, maxSections> AutoX;
RangeArr<float, 0, maxSections> AutoY;
int numStars = 0;
RangeArr<Water_t, 0, maxWater> Water;
int numWater = 0;
RangeArr<Star_t, 1, 1000> Star;
std::string GoToLevel;
std::string StartLevel;
bool NoMap = false;
bool RestartLevel = false;
float LevelChop[maxSections + 1];
RangeArr<int, -FLBlocks, FLBlocks> FirstBlock;
RangeArr<int, -FLBlocks, FLBlocks> LastBlock;
int MidBackground = 1;
int LastBackground = 1;
int iBlocks = 0;
RangeArrI<int, 0, maxBlocks, 0> iBlock;
int numTiles = 0;
int numScenes = 0;
RangeArr<std::string, 0, maxSections> CustomMusic;
RangeArr<Location_t, 0, maxSections> level;
RangeArrI<bool, 0, maxSections, false> LevelWrap;
RangeArrI<bool, 0, maxSections, false> OffScreenExit;
RangeArrI<int, 0, maxSections, 0> bgMusic;
RangeArrI<int, 0, maxSections, 0> bgMusicREAL;
RangeArrI<int, 0, maxSections, 0> Background2REAL;
RangeArr<Location_t, 0, maxSections> LevelREAL;
int curMusic = 0;
RangeArrI<long, 0, maxSections, 0> bgColor;
RangeArrI<int, 0, maxSections, 0> Background2;
RangeArr<WorldPath_t, 1, maxWorldPaths> WorldPath;
int numWorldPaths = 0;
int numWarps = 0;
RangeArr<Warp_t, 1, maxWarps> Warp;
RangeArr<Tile_t, 1, maxTiles> Tile;
RangeArr<Scene_t, 1, maxScenes> Scene;
RangeArr<CreditLine_t, 1, maxCreditsLines> Credit;
int numCredits = 0;
int numBlock = 0;
int numBackground = 0;
int numNPCs = 0;
int numEffects = 0;
int numPlayers = 0;
int numWorldLevels = 0;
RangeArr<WorldMusic_t, 1, maxWorldMusic> WorldMusic;
int numWorldMusic = 0;
RangeArr<WorldLevel_t, 1, maxWorldLevels> WorldLevel;
RangeArr<Background_t, 1, maxBackgrounds> Background;
RangeArr<Effect_t, 1, maxEffects> Effect;
RangeArr<NPC_t, -128, maxNPCs> NPC;
RangeArr<Block_t, 0, maxBlocks> Block;
RangeArr<Player_t, 0, maxPlayers> Player;
RangeArrI<int, 0, maxPlayerFrames, 0> MarioFrameX;
RangeArrI<int, 0, maxPlayerFrames, 0> MarioFrameY;
RangeArrI<int, 0, maxPlayerFrames, 0> LuigiFrameX;
RangeArrI<int, 0, maxPlayerFrames, 0> LuigiFrameY;
RangeArrI<int, 0, maxPlayerFrames, 0> PeachFrameX;
RangeArrI<int, 0, maxPlayerFrames, 0> PeachFrameY;
RangeArrI<int, 0, maxPlayerFrames, 0> ToadFrameX;
RangeArrI<int, 0, maxPlayerFrames, 0> ToadFrameY;
RangeArrI<int, 0, maxPlayerFrames, 0> LinkFrameX;
RangeArrI<int, 0, maxPlayerFrames, 0> LinkFrameY;
RangeArrI<bool, 0, maxBackgroundType, false> BackgroundFence;
RangeArrI<int, 0, maxNPCType, 0> NPCFrameOffsetX;
RangeArrI<int, 0, maxNPCType, 0> NPCFrameOffsetY;
RangeArrI<int, 0, maxNPCType, 0> NPCWidth;
RangeArrI<int, 0, maxNPCType, 0> NPCHeight;
RangeArrI<int, 0, maxNPCType, 0> NPCWidthGFX;
RangeArrI<int, 0, maxNPCType, 0> NPCHeightGFX;
RangeArr<float, 0, maxNPCType> NPCSpeedvar;
RangeArrI<bool, 0, maxNPCType, false> NPCIsAShell;
RangeArrI<bool, 0, maxNPCType, false> NPCIsABlock;
RangeArrI<bool, 0, maxNPCType, false> NPCIsAHit1Block;
RangeArrI<bool, 0, maxNPCType, false> NPCIsABonus;
RangeArrI<bool, 0, maxNPCType, false> NPCIsACoin;
RangeArrI<bool, 0, maxNPCType, false> NPCIsAVine;
RangeArrI<bool, 0, maxNPCType, false> NPCIsAnExit;
RangeArrI<bool, 0, maxNPCType, false> NPCIsAParaTroopa;
RangeArrI<bool, 0, maxNPCType, false> NPCIsCheep;
RangeArrI<bool, 0, maxNPCType, false> NPCJumpHurt;
RangeArrI<bool, 0, maxNPCType, false> NPCNoClipping;
RangeArrI<int, 0, maxNPCType, 0> NPCScore;
RangeArrI<bool, 0, maxNPCType, false> NPCCanWalkOn;
RangeArrI<bool, 0, maxNPCType, false> NPCGrabFromTop;
RangeArrI<bool, 0, maxNPCType, false> NPCTurnsAtCliffs;
RangeArrI<bool, 0, maxNPCType, false> NPCWontHurt;
RangeArrI<bool, 0, maxNPCType, false> NPCMovesPlayer;
RangeArrI<bool, 0, maxNPCType, false> NPCStandsOnPlayer;
RangeArrI<bool, 0, maxNPCType, false> NPCIsGrabbable;
RangeArrI<bool, 0, maxNPCType, false> NPCIsBoot;
RangeArrI<bool, 0, maxNPCType, false> NPCIsYoshi;
RangeArrI<bool, 0, maxNPCType, false> NPCIsToad;
RangeArrI<bool, 0, maxNPCType, false> NPCNoYoshi;
RangeArrI<bool, 0, maxNPCType, false> NPCForeground;
RangeArrI<bool, 0, maxNPCType, false> NPCIsABot;
RangeArrI<bool, 0, maxNPCType, false> NPCDefaultMovement;
RangeArrI<bool, 0, maxNPCType, false> NPCIsVeggie;
RangeArrI<bool, 0, maxNPCType, false> NPCNoFireBall;
RangeArrI<bool, 0, maxNPCType, false> NPCNoIceBall;
RangeArrI<bool, 0, maxNPCType, false> NPCNoGravity;

RangeArrI<int, 0, maxNPCType, 0> NPCFrame;
RangeArrI<int, 0, maxNPCType, 0> NPCFrameSpeed;
RangeArrI<int, 0, maxNPCType, 0> NPCFrameStyle;

NPCDefaults_t NPCDefaults;

RangeArrI<bool, 0, maxBlockType, false> BlockIsSizable;
RangeArrI<int, 0, maxBlockType, 0> BlockSlope;
RangeArrI<int, 0, maxBlockType, 0> BlockSlope2;
RangeArr<double, 0, maxPlayers> vScreenX;
RangeArr<double, 0, maxPlayers> vScreenY;

RangeArr<double, 0, maxPlayers> qScreenX;
RangeArr<double, 0, maxPlayers> qScreenY;
bool qScreen = false;

RangeArrI<int, 0, maxBlockType, 0> BlockWidth;
RangeArrI<int, 0, maxBlockType, 0> BlockHeight;
RangeArrI<int, 0, maxBlockType, 0> BonusWidth;
RangeArrI<int, 0, maxBlockType, 0> BonusHeight;
RangeArrI<int, 0, maxBlockType, 0> EffectWidth;
RangeArrI<int, 0, maxBlockType, 0> EffectHeight;

EffectDefaults effectDefaults;
RangeArrI<int, 1, maxSceneType, 0> SceneWidth;
RangeArrI<int, 1, maxSceneType, 0> SceneHeight;
RangeArrI<int, 0, 100, 0> SpecialFrame;
RangeArr<float, 0, 100> SpecialFrameCount;
RangeArrI<bool, 1, maxBackgroundType, false> BackgroundHasNoMask;
RangeArrI<bool, 0, maxBackgroundType, false> Foreground;
RangeArrI<int, 1, maxBackgroundType, 0> BackgroundWidth;
RangeArrI<int, 1, maxBackgroundType, 0> BackgroundHeight;
RangeArrI<int, 1, maxBackgroundType, 0> BackgroundFrame;
RangeArrI<int, 1, maxBackgroundType, 0> BackgroundFrameCount;
RangeArrI<int, 1, maxBlockType, 0> BlockFrame;
RangeArrI<int, 1, maxBlockType, 0> BlockFrame2;
RangeArrI<int, 1, 1000, 0> sBlockArray;
int sBlockNum = 0;
RangeArrI<int, 1, maxSceneType, 0> SceneFrame;
RangeArrI<int, 1, maxSceneType, 0> SceneFrame2;
RangeArrI<int, 1, maxTileType, 0> TileWidth;
RangeArrI<int, 1, maxTileType, 0> TileHeight;
RangeArrI<int, 1, maxTileType, 0> TileFrame;
RangeArrI<int, 1, maxTileType, 0> TileFrame2;
RangeArrI<int, 1, 100, 0> LevelFrame;
RangeArrI<int, 1, 100, 0> LevelFrame2;
RangeArrI<bool, 1, maxBlockType, false> BlockHasNoMask;
RangeArrI<bool, 1, 100, false> LevelHasNoMask;
RangeArrI<bool, 0, maxBlockType, false> BlockOnlyHitspot1;
RangeArrI<bool, 0, maxBlockType, false> BlockKills;
RangeArrI<bool, 0, maxBlockType, false> BlockKills2;
RangeArrI<bool, 0, maxBlockType, false> BlockHurts;
RangeArrI<bool, 0, maxBlockType, false> BlockPSwitch;
RangeArrI<bool, 0, maxBlockType, false> BlockNoClipping;
RangeArrI<int, 1, 10, 0> CoinFrame;
RangeArrI<int, 1, 10, 0> CoinFrame2;
EditorCursor_t EditorCursor;

RangeArrI<int, 1, numSounds, 0> Sound;
RangeArrI<int, 1, numSounds, 0> SoundPause;
bool EndLevel = false;
int LevelMacro = 0;
int LevelMacroCounter = 0;
int numJoysticks = 0;
std::string FileName;
std::string FileNameFull;
bool IsEpisodeIntro = false;
int Coins = 0;
float Lives = 0.0f;
bool EndIntro = false;
bool ExitMenu = false;
bool LevelSelect = false;
RangeArr<WorldPlayer_t, 0, 1> WorldPlayer;
int LevelBeatCode = 0;
int curWorldLevel = 0;
int curWorldMusic = 0;
std::string curWorldMusicFile;
RangeArrI<bool, 0, maxSections, false> NoTurnBack;
RangeArrI<bool, 0, maxSections, false> UnderWater;
bool TestLevel = false;
std::string FullFileName;
std::string FileNamePath;
bool GameMenu = false;
std::string WorldName;
int selWorld = 0;
int selSave = 0;
int PSwitchTime = 0;
int PSwitchStop = 0;
int PSwitchPlayer = 0;
RangeArrI<int, 1, 3, 0> SaveSlot;
RangeArrI<int, 1, 3, 0> SaveStars;
int BeltDirection = 0;
bool BeatTheGame = false;
int cycleCount = 0;
double fpsTime = 0.0;
double fpsCount = 0.0;
bool FrameSkip = false;
double GoalTime = 0.0;
double overTime = 0.0;
int worldCurs = 0;
int minShow = 0;
int maxShow = 0;

RangeArr<Layer_t, 0, maxLayers> Layer;
RangeArr<Events_t, 0, maxEvents> Events;
int ReturnWarp = 0;
int ReturnWarpSaved = 0;
int StartWarp = 0;
Physics_t Physics;
int MenuCursor = 0;
int MenuMode = 0;
bool MenuCursorCanMove = false;
bool MenuCursorCanMove2 = false;
bool NextFrame = false;
int StopHit = 0;
bool MouseRelease = false;
bool TestFullscreen = false;
bool keyDownAlt = false;
bool keyDownEnter = false;
bool BlocksSorted = false;
int SingleCoop = 0;
std::string CheatString;
bool GameOutro = false;
float CreditChop = 0.0f;
int EndCredits = 0;
int curStars = 0;
int maxStars = 0;
bool ShadowMode = false;
bool MultiHop = false;
bool SuperSpeed = false;
bool WalkAnywhere = false;
bool FlyForever = false;
bool FreezeNPCs = false;
bool CaptainN = false;
bool FlameThrower = false;
bool CoinMode = false;
bool WorldUnlock = false;
bool MaxFPS = false;
bool GodMode = false;
bool GrabAll = false;
bool Cheater = false;
Uint32 RenderMode = 1;
RangeArr<std::string, 1, maxWorldCredits> WorldCredits;
int Score = 0;
RangeArrI<int, 1, 13, 0> Points;
int oldJumpJoy = 0;
int MaxWorldStars = 0;
bool Debugger = false;
RangeArr<Player_t, 0, 10> SavedChar;

int LoadCoins = 0;
float LoadCoinsT = 0.0f;

RangeArrI<bool, 1, maxBlockType, false> GFXBlockCustom;
//RangeArrI<long, 1, maxBlockType, 0> GFXBlock;
RangeArrI<long, 1, maxBlockType, 0> GFXBlockMask;
RangeArr<StdPicture, 1, maxBlockType> GFXBlockBMP;
RangeArr<StdPicture, 1, maxBlockType> GFXBlockMaskBMP;
RangeArrI<bool, 1, numBackground2, false> GFXBackground2Custom;
//RangeArrI<long, 1, numBackground2, 0> GFXBackground2;
RangeArr<StdPicture, 1, numBackground2> GFXBackground2BMP;
RangeArrI<int, 1, numBackground2, 0> GFXBackground2Height;
RangeArrI<int, 1, numBackground2, 0> GFXBackground2Width;
RangeArrI<bool, 1, maxNPCType, false> GFXNPCCustom;
//RangeArrI<long, 1, maxNPCType, 0> GFXNPC;
RangeArrI<long, 1, maxNPCType, 0> GFXNPCMask;
RangeArr<StdPicture, 1, maxNPCType> GFXNPCBMP;
RangeArr<StdPicture, 1, maxNPCType> GFXNPCMaskBMP;
RangeArrI<int, 1, maxNPCType, 0> GFXNPCHeight;
RangeArrI<int, 1, maxNPCType, 0> GFXNPCWidth;
RangeArrI<bool, 1, maxEffectType, false> GFXEffectCustom;
//RangeArrI<long, 1, maxEffectType, 0> GFXEffect;
RangeArrI<long, 1, maxEffectType, 0> GFXEffectMask;
RangeArr<StdPicture, 1, maxEffectType> GFXEffectBMP;
RangeArr<StdPicture, 1, maxEffectType> GFXEffectMaskBMP;
RangeArrI<int, 1, maxEffectType, 0> GFXEffectHeight;
RangeArrI<int, 1, maxEffectType, 0> GFXEffectWidth;
RangeArrI<bool, 1, maxBackgroundType, false> GFXBackgroundCustom;
//RangeArrI<long, 1, maxBackgroundType, 0> GFXBackground;
RangeArrI<long, 1, maxBackgroundType, 0> GFXBackgroundMask;
RangeArr<StdPicture, 1, maxBackgroundType> GFXBackgroundBMP;
RangeArr<StdPicture, 1, maxBackgroundType> GFXBackgroundMaskBMP;
RangeArrI<int, 1, maxBackgroundType, 0> GFXBackgroundHeight;
RangeArrI<int, 1, maxBackgroundType, 0> GFXBackgroundWidth;
RangeArrI<bool, 1, 10, false> GFXMarioCustom;
//RangeArrI<long, 1, 10, 0> GFXMario;
RangeArrI<long, 1, 10, 0> GFXMarioMask;
RangeArr<StdPicture, 1, 10> GFXMarioBMP;
RangeArr<StdPicture, 1, 10> GFXMarioMaskBMP;
RangeArrI<int, 1, 10, 0> GFXMarioHeight;
RangeArrI<int, 1, 10, 0> GFXMarioWidth;
RangeArrI<bool, 1, 10, false> GFXLuigiCustom;
//RangeArrI<long, 1, 10, 0> GFXLuigi;
RangeArrI<long, 1, 10, 0> GFXLuigiMask;
RangeArr<StdPicture, 1, 10> GFXLuigiBMP;
RangeArr<StdPicture, 1, 10> GFXLuigiMaskBMP;
RangeArrI<int, 1, 10, 0> GFXLuigiHeight;
RangeArrI<int, 1, 10, 0> GFXLuigiWidth;
RangeArrI<bool, 1, 10, false> GFXPeachCustom;
//RangeArrI<long, 1, 10, 0> GFXPeach;
RangeArrI<long, 1, 10, 0> GFXPeachMask;
RangeArr<StdPicture, 1, 10> GFXPeachBMP;
RangeArr<StdPicture, 1, 10> GFXPeachMaskBMP;
RangeArrI<int, 1, 10, 0> GFXPeachHeight;
RangeArrI<int, 1, 10, 0> GFXPeachWidth;
RangeArrI<bool, 1, 10, false> GFXToadCustom;
//RangeArrI<long, 1, 10, 0> GFXToad;
RangeArrI<long, 1, 10, 0> GFXToadMask;
RangeArr<StdPicture, 1, 10> GFXToadBMP;
RangeArr<StdPicture, 1, 10> GFXToadMaskBMP;
RangeArrI<int, 1, 10, 0> GFXToadHeight;
RangeArrI<int, 1, 10, 0> GFXToadWidth;

RangeArrI<bool, 1, 10, false> GFXLinkCustom;
//RangeArrI<long, 1, 10, 0> GFXLink;
RangeArrI<long, 1, 10, 0> GFXLinkMask;
RangeArr<StdPicture, 1, 10> GFXLinkBMP;
RangeArr<StdPicture, 1, 10> GFXLinkMaskBMP;
RangeArrI<int, 1, 10, 0> GFXLinkHeight;
RangeArrI<int, 1, 10, 0> GFXLinkWidth;

RangeArrI<bool, 1, maxYoshiGfx, false> GFXYoshiBCustom;
//RangeArrI<long, 1, 10, 0> GFXYoshiB;
RangeArrI<long, 1, 10, 0> GFXYoshiBMask;
RangeArr<StdPicture, 1, 10> GFXYoshiBBMP;
RangeArr<StdPicture, 1, 10> GFXYoshiBMaskBMP;
RangeArrI<bool, 1, 10, false> GFXYoshiTCustom;
//RangeArrI<long, 1, 10, 0> GFXYoshiT;
RangeArrI<long, 1, 10, 0> GFXYoshiTMask;
RangeArr<StdPicture, 1, 10> GFXYoshiTBMP;
RangeArr<StdPicture, 1, 10> GFXYoshiTMaskBMP;
RangeArrI<bool, 1, maxTileType, false> GFXTileCustom;
//RangeArrI<long, 1, maxTileType, 0> GFXTile;
RangeArr<StdPicture, 1, maxTileType> GFXTileBMP;
RangeArrI<int, 1, maxTileType, 0> GFXTileHeight;
RangeArrI<int, 1, maxTileType, 0> GFXTileWidth;
RangeArrI<bool, 0, maxLevelType, false> GFXLevelCustom;
//RangeArrI<long, 0, maxLevelType, 0> GFXLevel;
RangeArrI<long, 0, maxLevelType, 0> GFXLevelMask;
RangeArr<StdPicture, 0, maxLevelType> GFXLevelBMP;
RangeArr<StdPicture, 0, maxLevelType> GFXLevelMaskBMP;
RangeArrI<int, 0, maxLevelType, 0> GFXLevelHeight;
RangeArrI<int, 0, maxLevelType, 0> GFXLevelWidth;
RangeArrI<bool, 0, maxLevelType, false> GFXLevelBig;
RangeArrI<bool, 1, maxSceneType, false> GFXSceneCustom;
//RangeArrI<long, 1, maxSceneType, 0> GFXScene;
RangeArrI<long, 1, maxSceneType, 0> GFXSceneMask;
RangeArr<StdPicture, 1, maxSceneType> GFXSceneBMP;
RangeArr<StdPicture, 1, maxSceneType> GFXSceneMaskBMP;
RangeArrI<int, 1, maxSceneType, 0> GFXSceneHeight;
RangeArrI<int, 1, maxSceneType, 0> GFXSceneWidth;
RangeArrI<bool, 1, maxPathType, false> GFXPathCustom;
//RangeArrI<long, 1, maxPathType, 0> GFXPath;
RangeArrI<long, 1, maxPathType, 0> GFXPathMask;
RangeArr<StdPicture, 1, maxPathType> GFXPathBMP;
RangeArr<StdPicture, 1, maxPathType> GFXPathMaskBMP;
RangeArrI<int, 1, maxPathType, 0> GFXPathHeight;
RangeArrI<int, 1, maxPathType, 0> GFXPathWidth;

RangeArrI<bool, 1, numCharacters, false> GFXPlayerCustom;
//RangeArrI<long, 1, numCharacters, 0> GFXPlayer;
RangeArrI<long, 1, numCharacters, 0> GFXPlayerMask;
RangeArr<StdPicture, 1, numCharacters> GFXPlayerBMP;
RangeArr<StdPicture, 1, numCharacters> GFXPlayerMaskBMP;
RangeArrI<int, 1, numCharacters, 0> GFXPlayerHeight;
RangeArrI<int, 1, numCharacters, 0> GFXPlayerWidth;

int PlayerCharacter = 0;
int PlayerCharacter2 = 0;
double MenuMouseX = 0.0;
double MenuMouseY = 0.0;
bool MenuMouseDown = false;
bool MenuMouseBack = false;
bool MenuMouseRelease = false;
bool MenuMouseMove = false;
bool MenuMouseClick = false;

RangeArr<std::string, 1, maxEvents> NewEvent;
RangeArrI<int, 1, maxEvents, 0> newEventDelay;
int newEventNum = 0;
bool ForcedControls = false;
Controls_t ForcedControl;
int SyncCount = 0;
bool noUpdate = false;
double gameTime = 0.0;
bool noSound = false;
bool neverPause = false;
double tempTime = 0.0;
bool BattleMode = false;
int BattleWinner = 0;
RangeArrI<int, 1, maxPlayers, 0> BattleLives;
int BattleIntro = 0;
int BattleOutro = 0;
std::string LevelName;

void DoEvents()
{
    frmMain.doEvents();
}

int showCursor(int show)
{
    return SDL_ShowCursor(show);
}

Uint8 getKeyState(SDL_Scancode key)
{
    return frmMain.getKeyState(key);
}

Uint8 getKeyStateI(int key)
{
    if(key < 0)
        return 0;
    return frmMain.getKeyState(static_cast<SDL_Scancode>(key));
}

const char *getKeyName(int key)
{
    if(key < 0)
        return " ... ";
    SDL_Scancode k = static_cast<SDL_Scancode>(key);
    return SDL_GetScancodeName(k);
}


void initAll()
{
    SavedEvents.fill(std::string());
    BlockSwitch.fill(false);
    PowerUpUnlock.fill(false);
    conKeyboard.fill(ConKeyboard_t());
    conJoystick.fill(ConJoystick_t());
    useJoystick.fill(0);
    testPlayer.fill(Player_t());
    SelectWorld.fill(SelectWorld_t());
    vScreen.fill(vScreen_t());
    PlayerStart.fill(Location_t());
    blockCharacter.fill(false);
    OwedMount.fill(0);
    OwedMountType.fill(0);
    AutoX.fill(0.f);
    AutoY.fill(0.f);
    Water.fill(Water_t());
    Star.fill(Star_t());
    FirstBlock.fill(0);
    LastBlock.fill(0);
    iBlock.fill(0);
    CustomMusic.fill(std::string());
    level.fill(Location_t());
    LevelWrap.fill(false);
    OffScreenExit.fill(false);
    bgMusic.fill(0);
    bgMusicREAL.fill(0);
    Background2REAL.fill(0);
    Background2.fill(0);
    SpecialFrameCount.fill(0.f);
    NPCSpeedvar.fill(0.f);
    vScreenX.fill(0.0);
    vScreenY.fill(0.0);
    qScreenX.fill(0.0);
    qScreenY.fill(0.0);

    Block.fill(Block_t());
    Background.fill(Background_t());
    NPC.fill(NPC_t());
}
