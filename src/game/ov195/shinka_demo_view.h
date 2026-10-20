#ifndef GAME_OV195_SHINKA_DEMO_VIEW_H
#define GAME_OV195_SHINKA_DEMO_VIEW_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of shinka_demo_view.c, prototypes copied from their definitions. */

struct Owner;
struct Grid;
typedef struct Owner Owner;
typedef struct Grid Grid;

#include "../types.h"

Owner *SHINKA_DEMO_VIEW_Create(u16 heap, u32 mode, void *res0, u16 evolvedSpecies);
void SHINKA_DEMO_VIEW_Destroy(char *owner);
void SHINKA_DEMO_VIEW_Main(char *p);
void SHINKA_DEMO_VIEW_Draw(Owner *o);
void SHINKA_DEMO_VIEW_RequestStart(int *p);
int SHINKA_DEMO_VIEW_IsStartDone(int *p);
void SHINKA_DEMO_VIEW_RequestConfirm(int *p);
int SHINKA_DEMO_VIEW_IsConfirmDone(int *p);
void SHINKA_DEMO_VIEW_RequestEvolve(int *p);
void SHINKA_DEMO_VIEW_RequestFadeOut(int *p);
int SHINKA_DEMO_VIEW_IsEvolveReady(int *p);
int SHINKA_DEMO_VIEW_IsEvolveStarted(int *p);
int SHINKA_DEMO_VIEW_IsEvolveDone(int *p);
int SHINKA_DEMO_VIEW_TrySecondForm(int *p);
void SHINKA_DEMO_VIEW_InitMcss(char *owner);
void SHINKA_DEMO_VIEW_ExitMcss(char *owner);
fx32 SHINKA_DEMO_VIEW_GetModelOffset(void *p);
void SHINKA_DEMO_VIEW_CreateModels(Owner *o);
void SHINKA_DEMO_VIEW_DeleteModels(Owner *o);
u8 SHINKA_DEMO_VIEW_OtherSlot(u8 i);
void SHINKA_DEMO_VIEW_UpdateModelOffsets(Owner *o);
void SHINKA_DEMO_VIEW_SetModelPosX(char *a, u32 v);
void SHINKA_DEMO_VIEW_CreateWork(Owner *o);
void SHINKA_DEMO_VIEW_DeleteWork(char *owner);
void SHINKA_DEMO_VIEW_Update(Owner *o);
void SHINKA_DEMO_VIEW_Draw3d(Owner *o);
void SHINKA_DEMO_VIEW_BeginIntro(Owner *o);
int SHINKA_DEMO_VIEW_IsMenuReady(int *owner);
void SHINKA_DEMO_VIEW_ShowMenu(int *owner);
void SHINKA_DEMO_VIEW_SetModelsPos(char *owner, u32 x, u32 y, u32 z);
void SHINKA_DEMO_VIEW_SetModelOffset(char *grid, int unused, int c, int d, int e);
void SHINKA_DEMO_VIEW_StartFadeOut(Owner *o);
int SHINKA_DEMO_VIEW_AreModelsState0(char *owner);
int SHINKA_DEMO_VIEW_AreModelsState4(char *owner);
Grid *SHINKA_DEMO_VIEW_CreateGrid(u32 monsNo, u32 formNo, u32 sex, u32 isShiny, u32 dir, u32 isEgg, u32 tex, u32 pltt, u16 heap);
void SHINKA_DEMO_VIEW_DeleteGrid(char *grid, int unused);
void SHINKA_DEMO_VIEW_InitGrid(Grid *grid, u16 heap);
void SHINKA_DEMO_VIEW_SetupGridCells(Grid *p, u16 heap);
void SHINKA_DEMO_VIEW_DrawGrid(Grid *w, u16 heap);
void SHINKA_DEMO_VIEW_DrawGridRotated(Owner *o);
void SHINKA_DEMO_VIEW_InitGridFromPokemon(char *p,u16 heap);
void SHINKA_DEMO_VIEW_StartGridFade(Grid *p, int unused, u16 color, s16 cur, s16 end, s16 wait, s16 step);
int SHINKA_DEMO_VIEW_IsGridFadeDone(Grid *p, int x);
void SHINKA_DEMO_VIEW_StepGridFade(Grid *p, int x);
void SHINKA_DEMO_VIEW_ApplyGridPalette(Grid *p, int x);
int SHINKA_DEMO_VIEW_IsGridState0(char *grid, u16 unused);
int SHINKA_DEMO_VIEW_IsGridState1(char *grid, u16 heap);
void SHINKA_DEMO_VIEW_StartGridFadeOut(Grid *p, int x);
int SHINKA_DEMO_VIEW_IsGridState3(char *grid, u16 heap);
int SHINKA_DEMO_VIEW_IsGridState4(char *grid, u16 heap);
void SHINKA_DEMO_VIEW_UpdateGridFade(Grid *grid, int x);
void SHINKA_DEMO_VIEW_FreeQuad(void *p,int n);
void SHINKA_DEMO_VIEW_SetQuadOffset(char *quad, int unused, int c, int d, int e);
/* END mkheaders: generated region */

#endif
