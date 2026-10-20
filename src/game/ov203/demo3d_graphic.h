#ifndef GAME_OV203_DEMO3D_GRAPHIC_H
#define GAME_OV203_DEMO3D_GRAPHIC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of demo3d_graphic.c, prototypes copied from their definitions. */

struct Demo3dGraphicClact;
struct Demo3dGraphicG3d;
typedef struct Demo3dGraphicClact Demo3dGraphicClact;
typedef struct Demo3dGraphicG3d Demo3dGraphicG3d;

#include "../ov203/demo3d_graphic_shared_types.h"
#include "../types.h"

Demo3dGraphic *DEMO3D_GRAPHIC_Create(unsigned swap, void *config, u8 heap);
void DEMO3D_GRAPHIC_Delete(Demo3dGraphic *ctx);
void DEMO3D_GRAPHIC_Draw(Demo3dGraphic *p);
void DEMO3D_GRAPHIC_UpdateLookAt(Demo3dGraphic *p);
void DEMO3D_GRAPHIC_EndDraw(Demo3dGraphic *p);
int DEMO3D_GRAPHIC_GetUnit(Demo3dGraphic *p);
void DEMO3D_GRAPHIC_SetupLightBlock(Demo3dGraphic *graphic, unsigned short *colors, int unused);
void DEMO3D_GRAPHIC_SetLightSlot(Demo3dGraphic *p,unsigned i,unsigned short val);
void DEMO3D_GRAPHIC_SetLightVector(Demo3dGraphic *p, int a, int b);
void DEMO3D_GRAPHIC_VBlank(u32 unused, Demo3dGraphic *p);
void DEMO3D_GRAPHIC_InitBg(Demo3dGraphic *ctx, u16 heap);
void DEMO3D_GRAPHIC_DeleteBg(Demo3dGraphic *ctx);
void DEMO3D_GRAPHIC_Noop(void *unused);
void DEMO3D_GRAPHIC_UpdateBg(void *unused);
void DEMO3D_GRAPHIC_InitClact(Demo3dGraphicClact *p, int a, int b);
void DEMO3D_GRAPHIC_DeleteClact(Demo3dGraphicClact *p);
void DEMO3D_GRAPHIC_DrawClact(void *unused);
void DEMO3D_GRAPHIC_VBlankClact(u8 *unused);
int DEMO3D_GRAPHIC_GetClactUnit(Demo3dGraphicClact *p);
void DEMO3D_GRAPHIC_InitG3d(Demo3dGraphicG3d *p, u8 heap);
void DEMO3D_GRAPHIC_DeleteG3d(Demo3dGraphicG3d *p);
void DEMO3D_GRAPHIC_ApplyLookAt(void *a);
void DEMO3D_GRAPHIC_DrawEnd(void *p);
void DEMO3D_GRAPHIC_DeleteDouble3d(void);
void DEMO3D_GRAPHIC_DeleteCamera(void *p);
/* END mkheaders: generated region */

#endif
