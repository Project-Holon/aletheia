#ifndef GAME_OV203_DEMO3D_ENGINE_H
#define GAME_OV203_DEMO3D_ENGINE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of demo3d_engine.c, prototypes copied from their definitions. */

struct Demo3dEngineCtx;
struct Demo3dGraphicCfg;
struct Light;
struct Demo3dEngineConfig;
struct Demo3dEngineRecord;

#include "../types.h"

struct Demo3dEngineCtx *DEMO3D_ENGINE_Create(void *owner, struct Demo3dGraphicCfg *cfg, u16 heap);
void DEMO3D_ENGINE_Delete(struct Demo3dEngineCtx *ctx);
void DEMO3D_ENGINE_SetClipPlanes(struct Demo3dEngineCtx *p,struct Light *q);
int DEMO3D_ENGINE_Update(const struct Demo3dEngineCtx *ctx, u32 frames);
int DEMO3D_ENGINE_GetFrame(struct Demo3dEngineCtx *p);
u32 DEMO3D_ENGINE_GetFrameNum(struct Demo3dEngineCtx *p);
void DEMO3D_ENGINE_SetMode(struct Demo3dEngineCtx *p,int a);
void DEMO3D_ENGINE_SetupLighting(struct Demo3dEngineCtx *ctx,struct Demo3dEngineConfig *cfg,const struct Demo3dEngineRecord *record,u16 heap);
unsigned DEMO3D_ENGINE_ClampDemoId(unsigned x);
u32 DEMO3D_ENGINE_GetCameraRecord(u32 id);
void *DEMO3D_ENGINE_CreateAnimeStream(u32 a, u32 b, u32 c);
u8 DEMO3D_ENGINE_GetAnimeKind(unsigned x);
/* END mkheaders: generated region */

#endif
