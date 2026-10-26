#ifndef GAME_OV204_INTRO_GRAPHIC_H
#define GAME_OV204_INTRO_GRAPHIC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of intro_graphic.c, prototypes copied from their definitions. */

struct Proc;
struct IntroDisplay;
struct IntroClact;
struct DispVramCfg;
struct IntroCamera;
typedef struct IntroDisplay IntroDisplay;
typedef struct IntroClact IntroClact;
typedef struct IntroCamera IntroCamera;

#include "../types.h"

struct TcbTask;

int INTRO_GRAPHIC_Create(struct Proc *owner, int unused, char *args);
int INTRO_GRAPHIC_Delete(struct Proc *owner, int unused1, int unused2, char *p);
int INTRO_GRAPHIC_Main(int a, int b, int c, void *p);
void INTRO_GRAPHIC_Setup3d(void);
void *INTRO_GRAPHIC_CreateDisplay(int swap, int mode, u16 heap);
void INTRO_GRAPHIC_DeleteDisplay(unsigned char *p);
void INTRO_GRAPHIC_UpdateDisplay(u8 *p);
void INTRO_GRAPHIC_Draw3d(char *p);
void INTRO_GRAPHIC_Draw3dEnd(char *p);
void *INTRO_GRAPHIC_GetClactOwner(char *p);
void INTRO_GRAPHIC_VBlank(struct TcbTask *a, void *arg);
void INTRO_GRAPHIC_InitBg(IntroDisplay *disp, u16 heap);
void INTRO_GRAPHIC_ExitBg(IntroDisplay *disp);
void INTRO_GRAPHIC_ResetBgSlot(IntroDisplay *disp);
void INTRO_GRAPHIC_UpdateBg(void *unused);
void INTRO_GRAPHIC_InitBg7(IntroDisplay *disp,u16 heap);
void INTRO_GRAPHIC_InitClact(IntroClact *clact, struct DispVramCfg *a, int b);
void INTRO_GRAPHIC_DeleteClact(IntroClact *clact);
void INTRO_GRAPHIC_DrawClact(void *unused);
void INTRO_GRAPHIC_VBlankClact(void *unused);
void *INTRO_GRAPHIC_GetClactBank(IntroClact *clact);
void INTRO_GRAPHIC_InitCamera(IntroCamera *cam, u16 heap);
void INTRO_GRAPHIC_InitCamera7(IntroCamera *cam, u16 heap);
void INTRO_GRAPHIC_DeleteCamera(IntroCamera *cam);
void INTRO_GRAPHIC_DrawCamera(IntroCamera *cam);
void INTRO_GRAPHIC_DrawEnd(IntroCamera *unused);
int INTRO_GRAPHIC_NoOp(void);
int INTRO_GRAPHIC_SetScenario(char *p, u32 b, int *c);
u32 INTRO_GRAPHIC_CmdSetScenario(u8 *p);
void INTRO_GRAPHIC_DrawMenuEntry(char *p, int which);
int INTRO_GRAPHIC_CmdMenu(char *p, int *state, int *values);
int INTRO_GRAPHIC_CmdRunHandler(char *p, int unused, unsigned *q);
int INTRO_GRAPHIC_CmdLoadPalette(char *p,void *unused,int *state);
int INTRO_GRAPHIC_CmdSetArg(char *p,void *unused,u32 *r);
int INTRO_GRAPHIC_CmdWaitFrame(void *unused,int *q,int *r);
/* END mkheaders: generated region */

#endif
