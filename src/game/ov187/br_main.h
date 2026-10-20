#ifndef GAME_OV187_BR_MAIN_H
#define GAME_OV187_BR_MAIN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of br_main.c, prototypes copied from their definitions. */

struct BrLaunchParam;
struct BrMainWork;
struct BrSceneManager;
struct BrSceneEntry;
struct BrListSceneWork;
struct BattleSetupParam;
typedef struct BrLaunchParam BrLaunchParam;
typedef struct BrMainWork BrMainWork;
typedef struct BrSceneManager BrSceneManager;
typedef struct BrSceneEntry BrSceneEntry;
typedef struct BrListSceneWork BrListSceneWork;

#include "../types.h"

int BR_MAIN_Init(void *proc, unsigned unused, BrLaunchParam *launch);
int BR_MAIN_Exit(int a, int b, int c, BrMainWork *work);
int BR_MAIN_Main(void *a, int *state, int b, BrMainWork *work);
void BR_MAIN_InitSceneManager(BrSceneManager *mgr, const BrSceneEntry *scenes, void *owner, u32 heapId);
int BR_MAIN_RunSceneStep(BrSceneManager *mgr);
void BR_MAIN_FreeSceneManager(BrSceneManager *mgr);
void BR_MAIN_SetDesiredScene(BrMainWork *work, u32 scene);
BrListSceneWork *BR_MAIN_CreateListScene(unsigned short heapId, BrMainWork *work, int mode);
void BR_MAIN_DeleteListScene(BrListSceneWork *listWork, BrMainWork *work);
void *BR_MAIN_CreateReplayScene(u16 heapId, BrMainWork *work);
void BR_MAIN_DeleteReplayScene(struct BattleSetupParam *setup, BrMainWork *work);
void BR_MAIN_SanitizeBgmIds(u16 *battleBgm, u16 *winBgm);
/* END mkheaders: generated region */

#endif
