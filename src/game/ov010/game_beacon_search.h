#ifndef GAME_OV010_GAME_BEACON_SEARCH_H
#define GAME_OV010_GAME_BEACON_SEARCH_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of game_beacon_search.c, prototypes copied from their definitions. */

struct GameBeaconSearchWork;
struct GameSystem;
struct GameBeaconSearchTarget;
struct GameBeaconSearchBeacon;
struct GameData;
typedef struct GameBeaconSearchWork GameBeaconSearchWork;
typedef struct GameBeaconSearchTarget GameBeaconSearchTarget;
typedef struct GameBeaconSearchBeacon GameBeaconSearchBeacon;

GameBeaconSearchWork *GAME_BEACON_SEARCH_Init(void *unused, struct GameSystem *gameSystem);
int GAME_BEACON_SEARCH_InitWait(int *seq, void *unused, GameBeaconSearchWork *work);
void GAME_BEACON_SEARCH_OnSessionStarted(void *arg);
int GAME_BEACON_SEARCH_Exit(void *unused0, void *unused1, GameBeaconSearchWork *work);
int GAME_BEACON_SEARCH_FreeWork(void *unused0, void *unused1, GameBeaconSearchWork *work);
void GAME_BEACON_SEARCH_OnNetExit(void *arg);
void GAME_BEACON_SEARCH_Update(void *unused, struct GameSystem *gameSystem, GameBeaconSearchWork *work);
GameBeaconSearchTarget *GAME_BEACON_SEARCH_PollScanResult(GameBeaconSearchWork *work, int *index);
GameBeaconSearchBeacon *GAME_BEACON_SEARCH_PickBestScanResult(GameBeaconSearchWork *work, int *index);
GameBeaconSearchBeacon *GAME_BEACON_SEARCH_GetBeaconData(GameBeaconSearchWork *work);
void GAME_BEACON_SEARCH_BuildBeaconHeader(GameBeaconSearchBeacon *beacon, struct GameData *gameData);
int GAME_BEACON_SEARCH_GetBeaconSize(void);
int GAME_BEACON_SEARCH_CompareBeacon(void);
int GAME_BEACON_SEARCH_OnConnected(void *unused0, void *unused1, GameBeaconSearchWork *work);
void GAME_BEACON_SEARCH_DummyCallback(void);
GameBeaconSearchBeacon *GAME_BEACON_SEARCH_SelectBetterEntry(GameBeaconSearchBeacon *beacon, GameBeaconSearchBeacon *best);
void GAME_BEACON_SEARCH_SetStartDelay(GameBeaconSearchWork *work);
void GAME_BEACON_SEARCH_StartConnectEvent(void *arg, int cancel);
/* END mkheaders: generated region */

#endif
