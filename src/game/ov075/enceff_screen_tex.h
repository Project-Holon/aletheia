#ifndef GAME_OV075_ENCEFF_SCREEN_TEX_H
#define GAME_OV075_ENCEFF_SCREEN_TEX_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of enceff_screen_tex.c, prototypes copied from their definitions. */

struct GameEvent;
struct GameSystem;
struct TcbTask;

#include "../sdk_fx.h"
#include "../ov075/enceff_screen_tex_types.h"
#include "../ov075/enceff_screen_tex_types.h"
#include "../types.h"

struct GameEvent *ENCEFF_StartScreenTexEffectFlash(struct GameSystem *gameSystem, VecFx32 *cameraPos, EncEffScreenTexStartFunc start, EncEffScreenTexDrawFunc draw);
struct GameEvent *ENCEFF_StartScreenTexEffect(struct GameSystem *gameSystem, VecFx32 *cameraPos, EncEffScreenTexStartFunc start, EncEffScreenTexDrawFunc draw);
void ENCEFF_DrawScreenTexEffect(EncEffScreenTexWork *work);
int ENCEFF_ScreenTexFlashEventMain(struct GameEvent *event, int *state, EncEffScreenTexWork *work);
void ENCEFF_RequestScreenCapture(EncEffScreenTexWork *work);
void ENCEFF_ScreenCaptureTask(struct TcbTask *task, void *work_);
u32 ENCEFF_GetScreenTexParam(void);
int ENCEFF_ScreenTexEventMain(struct GameEvent *event, int *state, EncEffScreenTexWork *work);
/* END mkheaders: generated region */

#endif
