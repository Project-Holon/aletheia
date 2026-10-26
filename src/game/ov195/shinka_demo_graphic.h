#ifndef GAME_OV195_SHINKA_DEMO_GRAPHIC_H
#define GAME_OV195_SHINKA_DEMO_GRAPHIC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of shinka_demo_graphic.c, prototypes copied from their definitions. */

struct Unit;
struct TcbTask;
struct DispVramCfg;

#include "../ov195/shinka_demo_graphic_shared_types.h"
#include "../types.h"

ShinkaGraphic *SHINKA_DEMO_GRAPHIC_Create(u32 lcdSwap, u16 heap);
void SHINKA_DEMO_GRAPHIC_Destroy(ShinkaGraphic *graphic);
void SHINKA_DEMO_GRAPHIC_Draw(ShinkaGraphic *graphic);
void SHINKA_DEMO_GRAPHIC_Update(ShinkaGraphic *graphic);
void SHINKA_DEMO_GRAPHIC_DrawEnd(ShinkaGraphic *graphic);
struct Unit *SHINKA_DEMO_GRAPHIC_GetCamera(ShinkaGraphic *graphic);
void SHINKA_DEMO_GRAPHIC_SetupSubBg(void);
void SHINKA_DEMO_GRAPHIC_ReleaseSubBg(void *unused);
void SHINKA_DEMO_GRAPHIC_VBlank(struct TcbTask *unused, void *graphicArg);
void SHINKA_DEMO_GRAPHIC_SetupMainBg(void *mainBg, u16 heap);
void SHINKA_DEMO_GRAPHIC_ReleaseMainBg(void *mainBg);
void SHINKA_DEMO_GRAPHIC_Noop(void *unused);
void SHINKA_DEMO_GRAPHIC_UpdateSubBg(void *unused);
void SHINKA_DEMO_GRAPHIC_InitClact(ShinkaClact *clact, struct DispVramCfg *vramBanks, u32 heap);
void SHINKA_DEMO_GRAPHIC_ExitClact(ShinkaClact *clact);
void SHINKA_DEMO_GRAPHIC_DrawClact(void *unused);
void SHINKA_DEMO_GRAPHIC_VBlankClact(void *unused);
struct Unit *SHINKA_DEMO_GRAPHIC_GetCameraId(ShinkaClact *camera);
void SHINKA_DEMO_GRAPHIC_Init3d(ShinkaG3d *cameraOut, u16 heap);
void SHINKA_DEMO_GRAPHIC_Exit3d(ShinkaG3d *camera);
void SHINKA_DEMO_GRAPHIC_Update3d(ShinkaG3d *g3d);
void SHINKA_DEMO_GRAPHIC_Draw3dEnd(void *unused);
/* END mkheaders: generated region */

#endif
