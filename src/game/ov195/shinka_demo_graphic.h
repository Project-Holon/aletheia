#ifndef GAME_OV195_SHINKA_DEMO_GRAPHIC_H
#define GAME_OV195_SHINKA_DEMO_GRAPHIC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of shinka_demo_graphic.c, prototypes copied from their definitions. */

#include "../types.h"

char *SHINKA_DEMO_GRAPHIC_Create(u32 lcdSwap, u16 heap);
void SHINKA_DEMO_GRAPHIC_Destroy(char *graphic);
void SHINKA_DEMO_GRAPHIC_Draw(char *graphic);
void SHINKA_DEMO_GRAPHIC_Update(char *graphic);
void SHINKA_DEMO_GRAPHIC_DrawEnd(char *graphic);
int SHINKA_DEMO_GRAPHIC_GetCamera(char *graphic);
void SHINKA_DEMO_GRAPHIC_SetupSubBg(void);
void SHINKA_DEMO_GRAPHIC_ReleaseSubBg(void *unused);
void SHINKA_DEMO_GRAPHIC_VBlank(struct TcbTask *unused, void *graphic);
void SHINKA_DEMO_GRAPHIC_SetupMainBg(void *mainBg, u16 heap);
void SHINKA_DEMO_GRAPHIC_ReleaseMainBg(void *mainBg);
void SHINKA_DEMO_GRAPHIC_Noop(void *unused);
void SHINKA_DEMO_GRAPHIC_UpdateSubBg(void *unused);
void SHINKA_DEMO_GRAPHIC_InitClact(unsigned char *clact, struct DispVramCfg *vramBanks, u32 heap);
void SHINKA_DEMO_GRAPHIC_ExitClact(char *clact);
void SHINKA_DEMO_GRAPHIC_DrawClact(void *unused);
void SHINKA_DEMO_GRAPHIC_VBlankClact(void *unused);
int SHINKA_DEMO_GRAPHIC_GetCameraId(int *camera);
void SHINKA_DEMO_GRAPHIC_Init3d(u32 *cameraOut, u16 heap);
void SHINKA_DEMO_GRAPHIC_Exit3d(int *camera);
void SHINKA_DEMO_GRAPHIC_Update3d(char *g3d);
void SHINKA_DEMO_GRAPHIC_Draw3dEnd(void *unused);
/* END mkheaders: generated region */

#endif
