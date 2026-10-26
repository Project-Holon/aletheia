#ifndef GAME_OV121_MYSTERY_GRAPHIC_H
#define GAME_OV121_MYSTERY_GRAPHIC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of mystery_graphic.c, prototypes copied from their definitions. */

struct DispVramCfg;

#include "../types.h"
#include "../ov121/mystery_net_types.h"

struct TcbTask;

u8 *MYSTERY_GRAPHIC_Create(int arg,u16 heap);
void MYSTERY_GRAPHIC_Delete(u8 *p);
void MYSTERY_GRAPHIC_Draw(u8 *p);
void MYSTERY_GRAPHIC_DrawScene(char *p);
void MYSTERY_GRAPHIC_DrawEnd(char *p);
void *MYSTERY_GRAPHIC_GetClactUnit(char *p);
void MYSTERY_GRAPHIC_StartRender(u8 *p);
void MYSTERY_GRAPHIC_StopRender(char *p);
void MYSTERY_GRAPHIC_VBlank(struct TcbTask *a, void *qArg);
void MYSTERY_GRAPHIC_InitBg(void *p, u32 a);
void MYSTERY_GRAPHIC_ExitBg(void *p);
void MYSTERY_GRAPHIC_Dummy(void *work);
void MYSTERY_GRAPHIC_UpdateBg(void *work);
void MYSTERY_GRAPHIC_InitClact(MysteryGraphicClact *p, const struct DispVramCfg *a, u32 heap);
void MYSTERY_GRAPHIC_ExitClact(MysteryGraphicClact *p);
void MYSTERY_GRAPHIC_DrawClact(void *work);
void MYSTERY_GRAPHIC_VBlankClact(void *work);
void *MYSTERY_GRAPHIC_GetFirstWord(MysteryGraphicClact *p);
void MYSTERY_GRAPHIC_InitCamera(MysteryGraphicCamera *p, u32 heap);
void MYSTERY_GRAPHIC_ExitCamera(char *p);
void MYSTERY_GRAPHIC_RenderScene(MysteryGraphicCamera *p);
void MYSTERY_GRAPHIC_FinishScene(MysteryGraphicCamera *p);
/* END mkheaders: generated region */

#endif
