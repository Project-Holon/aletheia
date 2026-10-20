#ifndef GAME_OV021_FLDMMDL_DRAW_H
#define GAME_OV021_FLDMMDL_DRAW_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fldmmdl_draw.c, prototypes copied from their definitions. */

struct G3dCamera;
struct MmdlDrawWork;
struct MmdlDirAnimeState;
struct BbActSys;
typedef struct MmdlDrawWork MmdlDrawWork;
typedef struct MmdlDirAnimeState MmdlDirAnimeState;

#include "../ov010/fldmmdl_types.h"
#include "../types.h"
#include "../sdk_fx.h"
#include "../sdk_fx.h"

void FLDMMDL_DRAW_GetBlactAnime(Mmdl *mmdl, u16 *outAnime, u16 *outFrame);
void FLDMMDL_DRAW_SetBlactAnime(Mmdl *mmdl, u32 listIndex, u32 cursor);
void FLDMMDL_DRAW_InitDirAnime(Mmdl *mmdl);
void FLDMMDL_DRAW_DeleteDirAnime(Mmdl *mmdl, u32 kind);
void FLDMMDL_DRAW_DrawDirAnime(Mmdl *mmdl);
int FLDMMDL_DRAW_GetBlactIdDirAnime(Mmdl *mmdl, u32 kind);
void FLDMMDL_DRAW_DrawDirAnimeMoving(Mmdl *mmdl);
void FLDMMDL_DRAW_InitDirAnimeB(Mmdl *mmdl);
void FLDMMDL_DRAW_DeleteDirAnimeB(Mmdl *mmdl, u32 kind);
void FLDMMDL_DRAW_DrawDirAnimeB(Mmdl *mmdl);
void FLDMMDL_DRAW_DrawDirAnimeSized(Mmdl *mmdl);
void FLDMMDL_DRAW_DrawWalkAnime(Mmdl *mmdl);
void FLDMMDL_DRAW_DrawWalkAnimeB(Mmdl *mmdl);
int FLDMMDL_DRAW_GetBlactIdWalkAnime(Mmdl *mmdl, u32 kind);
void FLDMMDL_DRAW_DrawTwoFrame(Mmdl *mmdl);
void FLDMMDL_DRAW_DrawThreeFrame(Mmdl *mmdl);
void FLDMMDL_DRAW_SetState(Mmdl *mmdl, int state);
void FLDMMDL_DRAW_RotateByCamera(struct G3dCamera *camera, VecFx32 *vec, VecFx32 *out);
int FLDMMDL_DRAW_GetFrameOffsetZero(Mmdl *mmdl, u32 listIndex, u32 cursor, VecFx32 *out);
void FLDMMDL_DRAW_DrawBillboardOffset(Mmdl *mmdl);
void FLDMMDL_DRAW_DrawStatic(Mmdl *mmdl);
int FLDMMDL_DRAW_SyncFrameGroup(Mmdl *mmdl, u32 command);
void FLDMMDL_DRAW_DrawPositionOnly(Mmdl *mmdl);
void FLDMMDL_DRAW_InitFixedState(Mmdl *mmdl);
void FLDMMDL_DRAW_DeleteFixedState(Mmdl *mmdl, u32 kind);
void FLDMMDL_DRAW_DrawWalking(Mmdl *mmdl);
void FLDMMDL_DRAW_UpdateWalkOffset(Mmdl *mmdl, MmdlDrawWork *work, u8 dir);
void FLDMMDL_DRAW_ShiftOffsetByDir(Mmdl *mmdl, u32 dir, MmdlObjCodeParam *param, VecFx32 *offset);
int FLDMMDL_DRAW_CheckStepFrame(MmdlDrawWork *work, int dir, MmdlObjCodeParam *param);
int FLDMMDL_DRAW_GetBlactIdFixedState(Mmdl *mmdl, u32 kind);
void FLDMMDL_DRAW_InitDirAnimeC(Mmdl *mmdl);
void FLDMMDL_DRAW_DeleteDirAnimeC(Mmdl *mmdl, u32 kind);
void FLDMMDL_DRAW_DrawMultiPattern(Mmdl *mmdl);
int FLDMMDL_DRAW_GetBlactIdMultiPattern(Mmdl *mmdl, u32 kind);
int FLDMMDL_DRAW_GetBlactAnimeTypeA(Mmdl *mmdl, u16 *outAnime, u16 *outFrame);
int FLDMMDL_DRAW_GetBlactAnimeTypeB(Mmdl *mmdl, u16 *outAnime, u16 *outFrame);
void FLDMMDL_DRAW_DrawTwoPattern(Mmdl *mmdl);
void FLDMMDL_DRAW_DrawThreePattern(Mmdl *mmdl);
u32 FLDMMDL_DRAW_CheckBlactReady(Mmdl *mmdl);
void FLDMMDL_DRAW_ResetBlactAnime(Mmdl *mmdl);
int FLDMMDL_DRAW_InitDirState(MmdlDirAnimeState *state);
void FLDMMDL_DRAW_UpdateDirAnime(MmdlDirAnimeState *state, Mmdl *mmdl, struct BbActSys *bbActSys, u16 blactId);
void FLDMMDL_DRAW_AddHeightOffset(Mmdl *mmdl, VecFx32 *pos);
u32 FLDMMDL_DRAW_GetDirIndex(Mmdl *mmdl);
void FLDMMDL_DRAW_UpdateBlactFlags(Mmdl *mmdl, struct BbActSys *bbActSys, u32 blactId, u32 isUpdated, u32 checkMode);
void FLDMMDL_DRAW_InitBlactId(Mmdl *mmdl);
void FLDMMDL_DRAW_DrawEffect(Mmdl *mmdl);
void FLDMMDL_DRAW_DeleteEffect(Mmdl *mmdl);
void FLDMMDL_DRAW_DeleteEffectAlias(Mmdl *mmdl);
void FLDMMDL_DRAW_InitEffectAlias(Mmdl *mmdl);
/* END mkheaders: generated region */

#endif
