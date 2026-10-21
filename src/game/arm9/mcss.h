#ifndef GAME_ARM9_MCSS_H
#define GAME_ARM9_MCSS_H

typedef struct McssSys McssSys;
typedef struct McssWork McssWork;
typedef struct McssAddWork McssAddWork;
typedef struct McssPose McssPose;
typedef struct McssPlttProxy McssPlttProxy;
typedef struct McssTransTask McssTransTask;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of mcss.c, prototypes copied from their definitions. */

struct McssSys;
struct McssWork;
struct McssPose;
struct McssPlttProxy;
struct TcbTask;
struct McssTransTask;
typedef struct McssSys McssSys;
typedef struct McssWork McssWork;
typedef struct McssPose McssPose;
typedef struct McssPlttProxy McssPlttProxy;
typedef struct McssTransTask McssTransTask;

#include "../types.h"
#include "../arm9/mcss_types.h"
#include "../sdk_fx.h"
#include "../sdk_fx.h"
#include "../sdk_fx.h"

McssSys *MCSS_Init(u32 maxCount, u32 heapId);
void MCSS_Exit(McssSys *sys);
void MCSS_Main(McssSys *sys);
void MCSS_OpenHandle(McssSys *sys, u32 arcId);
void MCSS_CloseHandle(McssSys *sys);
void MCSS_SetTaskSystem(McssSys *sys, void *taskSys);
void MCSS_ReloadResource(McssSys *sys, McssWork *work, const McssAddWork *addWork);
void MCSS_Draw(McssSys *sys);
void MCSS_DrawShadow(McssSys *sys, McssWork *work, fx32 x, fx32 y, fx32 width, fx32 height, fx32 s, fx32 t, McssPose *pose, u16 *frameIndex, McssPlttProxy *shadowPltt, int cellId, int ortho, u32 *depth, u8 flip);
McssWork *MCSS_Add(McssSys *sys, fx32 x, fx32 y, fx32 z, const McssAddWork *addWork);
void MCSS_Del(McssSys *sys, McssWork *work);
void MCSS_SetOrthoMode(McssSys *sys);
void MCSS_ResetOrthoMode(McssSys *sys);
void MCSS_SetOrthoBillboardFlag(McssWork *work);
void MCSS_ResetOrthoBillboardFlag(McssWork *work);
void MCSS_GetPosition(McssWork *work, u32 *out);
void MCSS_SetPosition(McssWork *work, u32 *src);
void MCSS_GetOfsPosition(McssWork *work, u32 *out);
void MCSS_SetOfsPosition(McssWork *work, u32 *src);
void MCSS_GetScale(McssWork *work, u32 *out);
void MCSS_SetScale(McssWork *work, u32 *src);
void MCSS_GetShadowScale(McssWork *work, u32 *out);
void MCSS_SetShadowScale(McssWork *work, u32 *src);
void MCSS_GetRotate(McssWork *work, u32 *out);
void MCSS_SetRotate(McssWork *work, u32 *src);
void MCSS_SetOfsScale(McssWork *work, u32 *src);
void MCSS_GetDrawScale(McssWork *work, u32 *out);
void MCSS_SetDrawScale(McssWork *work, u32 *src);
void MCSS_SetShadowRotateX(McssWork *work, u16 rotX);
void MCSS_SetShadowRotateZ(McssWork *work, u16 rotZ);
void MCSS_SetShadowOffset(McssWork *work, int *src);
void MCSS_SetMepachiFlag(McssWork *work);
void MCSS_ResetMepachiFlag(McssWork *work);
void MCSS_FlipMepachiFlag(McssWork *work);
int MCSS_GetAnmStopFlag(McssWork *work);
void MCSS_SetAnmStopFlag(McssWork *work);
void MCSS_SetAnmStopFlagAlways(McssWork *work);
void MCSS_ResetAnmStopFlag(McssWork *work);
void MCSS_ResetAnmStopFlagAlways(McssWork *work);
int MCSS_GetVanishFlag(McssWork *work);
void MCSS_SetVanishFlag(McssWork *work);
void MCSS_ResetVanishFlag(McssWork *work);
void MCSS_FlipVanishFlag(McssWork *work);
void *MCSS_GetAnimCtrl(McssWork *work);
u16 MCSS_GetAnimSeqNum(McssWork *work);
u8 MCSS_GetStopCellNum(McssWork *work);
u8 MCSS_GetStopCellIndex(McssWork *work, u8 i);
u16 MCSS_GetSizeX(McssWork *work);
u16 MCSS_GetSizeY(McssWork *work);
s16 MCSS_GetOfsX(McssWork *work);
s16 MCSS_GetOfsY(McssWork *work);
u8 MCSS_GetStopCellFlags(McssWork *work);
int MCSS_SetAnimCallback(McssWork *work, u32 callback, u32 callbackWork, u32 unusedArg);
void MCSS_SetCellCallback(McssWork *work, unsigned flags, int (*callback)(void *, void *, void *, int));
void MCSS_SetPaletteFade(McssWork *work, u32 start, u32 end, s32 wait, u32 color);
u8 MCSS_GetAlpha(McssWork *work);
void MCSS_SetAlpha(McssWork *work, int alpha);
void MCSS_SetShadowAlpha(McssWork *work, int alpha);
void MCSS_SetShadowVanishFlag(McssWork *work, int flag);
int MCSS_CheckPaletteFade(McssWork *work);
void MCSS_SetTextureTransAdrs(McssSys *sys, u32 adrs);
void MCSS_SetPaletteTransAdrs(McssSys *sys, unsigned int adrs);
void MCSS_SetAnimeIndex(McssWork *work, u32 animeIndex);
u8 MCSS_GetMosaic(McssWork *work);
void MCSS_SetMosaic(McssSys *sys, McssWork *work, int mosaic);
void MCSS_SetGlobalScale(McssSys *sys, unsigned int scale);
void MCSS_SetAnimeSpeed(McssWork *work, int speed);
u16 MCSS_GetAnimSeqNumEx(McssWork *work);
void MCSS_CreatePaletteTransTask(McssSys *sys, McssWork *work, u16 fadeLevel, int fadeColor);
void MCSS_CreatePaletteCopyTask(McssSys *sys, McssWork *work);
void MCSS_RestartAnime(McssWork *work);
void MCSS_RequestAnimeStopAtStart(McssWork *work);
void MCSS_SetMepachiDrawLast(McssWork *work, int flag);
void MCSS_SetDepthStep(McssSys *sys, int depthStep);
void MCSS_SetNearDepthRange(McssSys *sys, int flag);
void MCSS_LoadResource(McssSys *sys, u32 index, const McssAddWork *addWork);
void MCSS_LoadResourceShared(McssSys *sys, u32 index, const McssAddWork *addWork);
void MCSS_TransTextureTask(struct TcbTask *taskHandle, void *taskWork);
void MCSS_TransPaletteTask(struct TcbTask *taskHandle, void *taskWork);
void MCSS_InitAnimCtrl(McssWork *work, int kind);
void MCSS_InitEdgeColor(void);
void MCSS_UpdatePaletteFade(McssSys *sys, McssWork *work);
void MCSS_FreeResource(McssWork *work);
void MCSS_DeleteTextureTask(void *taskHandle);
void MCSS_DeletePaletteTask(void *taskHandle);
void MCSS_ApplyMosaic(McssWork *work, McssTransTask *task);
void MCSS_MulVecMtx44(const VecFx32 *v, const MtxFx44 *mtx, VecFx32 *dst, s32 *w);
void MCSS_TOOL_MakeAddWorkFromPP(void *pp, McssAddWork *out, u32 direction);
void MCSS_TOOL_MakeAddWorkFromPPP(void *pokemon, McssAddWork *out, u32 direction);
void MCSS_TOOL_MakeAddWorkFromParam(u32 species, u32 form, u32 gender, u32 isShiny, u32 isEgg, McssAddWork *out, u32 direction);
void MCSS_TOOL_MakeAddWorkFromTrainer(void *trainerClass, McssAddWork *out, void *trainerGender);
McssWork *MCSS_TOOL_AddPokeMcss(McssSys *sys, void *pp, u32 direction, fx32 x, fx32 y, fx32 z);
void MCSS_TOOL_SetSpindaSpotHook(McssSys *sys, u32 personality);
u32 MCSS_TOOL_SpindaSpotHook(const McssAddWork *addWork, McssTransTask *task, u32 personality);
void MCSS_TOOL_DrawSpindaSpots(u8 *pixels, u32 personality);
int MCSS_TOOL_SetAnimeStopCallback(McssWork *work);
void MCSS_TOOL_AnimeStopCallback(McssWork *work);
/* END mkheaders: generated region */

#endif
