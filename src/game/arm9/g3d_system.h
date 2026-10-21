#ifndef GAME_ARM9_G3D_SYSTEM_H
#define GAME_ARM9_G3D_SYSTEM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of g3d_system.c, prototypes copied from their definitions. */

struct ArcHandle;

#include "../types.h"
#include "../arm9/g3d_system_types.h"
#include "../arm9/nns_g3d_anm_calc_types.h"
#include "../arm9/nns_g3d_anm_types.h"

void G3D_SYSTEM_Init(u32 texManMode, u32 texManSize, u32 plttManMode, u32 plttManSize, u16 geBufSize, s16 heapId, void (*setUpFunc)(void));
void G3D_SYSTEM_Exit(void);
void G3D_SYSTEM_GetProjection(G3dProjection *proj);
void G3D_SYSTEM_SetProjection(const G3dProjection *proj);
void G3D_SYSTEM_SetLight(u32 lightIdx, const G3dLight *light);
void G3D_SYSTEM_GetLookAt(G3dLookAt *lookAt);
void G3D_SYSTEM_SetLookAt(const G3dLookAt *lookAt);
void G3D_SYSTEM_SetSwapBuffersMode(u32 sortMode, u32 bufferMode);
u32 G3D_SYSTEM_GetTexManagerMode(void);
u32 G3D_SYSTEM_GetPlttManagerMode(void);
void G3D_SYSTEM_SetGlbFlushMode(u32 mode);
void G3D_SYSTEM_FlushGlbDefault(void);
u32 G3D_SYSTEM_GetResourceSize(void);
void G3D_SYSTEM_InitResourceByKind(G3dResource *res, u32 kind, void *file);
void G3D_SYSTEM_InitResourceByFile(G3dResource *res, NNSG3dResFileHeader *file);
G3dResource *G3D_SYSTEM_CreateResourceArc(u32 arcId, u32 dataId);
G3dResource *G3D_SYSTEM_CreateResourceArcHandle(struct ArcHandle *arc, u32 dataId);
G3dResource *G3D_SYSTEM_CreateResourcePath(const char *path, u32 dataId);
void G3D_SYSTEM_DeleteResource(G3dResource *res);
void *G3D_SYSTEM_GetResourceFile(G3dResource *res);
u32 G3D_SYSTEM_CheckResourceType(G3dResource *res, u32 kind);
void G3D_SYSTEM_CutTexture(G3dResource *res);
BOOL G3D_SYSTEM_TransVramTexture(G3dResource *res);
BOOL G3D_SYSTEM_TransVramTextureAndCut(G3dResource *res);
BOOL G3D_SYSTEM_FreeVramTexture(G3dResource *res);
BOOL G3D_SYSTEM_AllocVramTexture(G3dResource *res);
BOOL G3D_SYSTEM_TransAllocatedTexture(G3dResource *res);
NNSG3dResTex *G3D_SYSTEM_GetResourceTex(G3dResource *res);
BOOL G3D_SYSTEM_AllocTexVramKeys(NNSG3dResTex *tex, u32 *texKey, u32 *tex4x4Key);
BOOL G3D_SYSTEM_AllocPlttVramKey(NNSG3dResTex *tex, u32 *plttKey);
BOOL G3D_SYSTEM_IsTextureInVram(G3dResource *res);
u32 G3D_SYSTEM_GetTexVramKey(G3dResource *res);
u32 G3D_SYSTEM_GetPlttVramKey(G3dResource *res);
void *G3D_SYSTEM_GetTexDataAddr(G3dResource *res);
void *G3D_SYSTEM_GetPlttDataAddr(G3dResource *res);
G3dRender *G3D_SYSTEM_CreateRender(G3dResource *mdlRes, u32 mdlIdx, G3dResource *texRes);
void G3D_SYSTEM_DeleteRender(G3dRender *render);
G3dResource *G3D_SYSTEM_GetRenderMdlRes(G3dRender *render);
G3dResource *G3D_SYSTEM_GetRenderTexRes(G3dRender *render);
NNSG3dRenderObj *G3D_SYSTEM_GetRenderObj(G3dRender *render);
G3dAnime *G3D_SYSTEM_CreateAnime(G3dRender *render, const G3dResource *anmRes, u32 anmIdx);
void G3D_SYSTEM_DeleteAnime(G3dAnime *anime);
NNSG3dAnmObj *G3D_SYSTEM_GetAnimeObj(G3dAnime *anime);
G3dObject *G3D_SYSTEM_CreateObject(G3dRender *render, G3dAnime **anmTbl, int anmCount);
void G3D_SYSTEM_DeleteObject(G3dObject *obj);
G3dRender *G3D_SYSTEM_GetObjectRender(G3dObject *obj);
G3dAnime *G3D_SYSTEM_GetObjectAnime(G3dObject *obj, int anmIdx);
u16 G3D_SYSTEM_GetObjectAnimeCount(G3dObject *obj);
BOOL G3D_SYSTEM_EnableObjectAnime(G3dObject *obj, u32 anmIdx);
BOOL G3D_SYSTEM_DisableObjectAnime(G3dObject *obj, u32 anmIdx);
BOOL G3D_SYSTEM_ResetObjectAnimeFrame(G3dObject *obj, u16 anmIdx);
BOOL G3D_SYSTEM_GetObjectAnimeFrame(G3dObject *obj, u32 anmIdx, fx32 *frame);
BOOL G3D_SYSTEM_SetObjectAnimeFrame(G3dObject *obj, u16 anmIdx, const fx32 *frame);
BOOL G3D_SYSTEM_GetObjectAnimeFrameMax(G3dObject *obj, int anmIdx, fx32 *frameMax);
BOOL G3D_SYSTEM_IncObjectAnimeFrame(G3dObject *obj, int anmIdx, fx32 step);
BOOL G3D_SYSTEM_LoopObjectAnimeFrame(G3dObject *obj, int anmIdx, fx32 step);
void G3D_SYSTEM_DrawStart(void);
void G3D_SYSTEM_DrawEnd(void);
void G3D_SYSTEM_SwapBuffersMain(void);
void G3D_SYSTEM_ApplyLookAt(void);
void G3D_SYSTEM_DrawObject(G3dObject *obj, G3dObjectStatus *status);
BOOL G3D_SYSTEM_DrawObjectCulling(G3dObject *obj, G3dObjectStatus *status);
BOOL G3D_SYSTEM_CheckObjectCulling(G3dObject *obj);
void G3D_SYSTEM_DrawRenderObj(NNSG3dRenderObj *rndObj);
void G3D_SYSTEM_ResetDrawCounts(void);
/* END mkheaders: generated region */

#endif
