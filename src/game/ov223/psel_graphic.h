#ifndef GAME_OV223_PSEL_GRAPHIC_H
#define GAME_OV223_PSEL_GRAPHIC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of psel_graphic.c, prototypes copied from their definitions. */

struct PselWork;
struct PselGraphicSystem;
struct Unit;
struct DispVram;
struct G3dCamera;

#include "../types.h"

void PSEL_GRAPHIC_OpenMenu(char *work);
void PSEL_GRAPHIC_CloseMenu(char *work);
void PSEL_GRAPHIC_UpdateMenu(char *work);
unsigned PSEL_GRAPHIC_IsMenuFinished(char *work);
int PSEL_GRAPHIC_GetMenuChoice(int *work);
void PSEL_GRAPHIC_SplitColor(int v, unsigned short *a, unsigned short *b, unsigned short *c);
void PSEL_GRAPHIC_LoadFadeSources(u8 *work);
void PSEL_GRAPHIC_NopFade(void *unused);
void PSEL_GRAPHIC_StepFade(struct PselWork *work);
void PSEL_GRAPHIC_LoadPaletteBuffers(char *work);
void PSEL_GRAPHIC_NopBlend(void *unused);
void PSEL_GRAPHIC_BlendPalettes(char *work);
void PSEL_GRAPHIC_InitFadePalettes(char *work);
void PSEL_GRAPHIC_UpdateFadeNop(char *work);
void PSEL_GRAPHIC_UpdateFade(char *work);
void PSEL_GRAPHIC_SetRecordState(unsigned char *work,unsigned index,int cmd);
void PSEL_GRAPHIC_SetFadeSource(unsigned char *work,int value);
int PSEL_GRAPHIC_IsReady(void);
int PSEL_GRAPHIC_Init(char *work);
int PSEL_GRAPHIC_InitSelect(char *work);
int PSEL_GRAPHIC_StateFadeIn(char *work, int *state);
int PSEL_GRAPHIC_StateFadeAnim(char *work,u32 *state);
int PSEL_GRAPHIC_StateFadeOut(char *work, int *state);
int PSEL_GRAPHIC_StateExit(unsigned char *work);
int PSEL_GRAPHIC_StateEnter(char *work);
int PSEL_GRAPHIC_StateRun(char *work,unsigned *state);
int PSEL_GRAPHIC_Main(char *work,u32 *state);
int PSEL_GRAPHIC_StateEnd(char *work,unsigned *state);
int PSEL_GRAPHIC_StateCleanup(char *work);
int PSEL_GRAPHIC_Delete(int *work);
int PSEL_GRAPHIC_GetMaxState(void);
void PSEL_GRAPHIC_G3dCallback(void);
void *PSEL_GRAPHIC_Create(int a,int heap);
void PSEL_GRAPHIC_Destroy(struct PselGraphicSystem *sys);
void PSEL_GRAPHIC_Draw(struct PselGraphicSystem *sys);
void PSEL_GRAPHIC_ApplyLight(struct PselGraphicSystem *sys);
void PSEL_GRAPHIC_DrawEnd(struct PselGraphicSystem *sys);
struct Unit *PSEL_GRAPHIC_GetClactBank(struct PselGraphicSystem *sys);
void *PSEL_GRAPHIC_GetCamera(struct PselGraphicSystem *sys);
void PSEL_GRAPHIC_VBlank(void *unused, char *sys);
void PSEL_GRAPHIC_InitBg(void *sys,int heap);
void PSEL_GRAPHIC_ExitBg(void *sys);
void PSEL_GRAPHIC_NopDraw(void *unused);
void PSEL_GRAPHIC_UpdateBg(void *unused);
void PSEL_GRAPHIC_InitClact(struct Unit **out, const struct DispVram *a, int b);
void PSEL_GRAPHIC_ExitClact(struct Unit **bank);
void PSEL_GRAPHIC_ClactDraw(void *unused);
void PSEL_GRAPHIC_ClactVBlank(void *unused);
void *PSEL_GRAPHIC_LoadWord(const u32 *word);
void PSEL_GRAPHIC_InitG3d(struct G3dCamera **camera,int heap);
void PSEL_GRAPHIC_ExitG3d(struct G3dCamera **camera);
void PSEL_GRAPHIC_ApplyLookAt(struct G3dCamera **camera);
void PSEL_GRAPHIC_G3dDrawEnd(unsigned char *unused);
struct Unit *PSEL_GRAPHIC_LoadWordC6F8(unsigned char *handle);
/* END mkheaders: generated region */

#endif
