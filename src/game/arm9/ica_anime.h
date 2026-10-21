#ifndef GAME_ARM9_ICA_ANIME_H
#define GAME_ARM9_ICA_ANIME_H

#include "../types.h"

struct IcaAnime *ICA_ANIME_CreateWithFullBuffer(u32 heapId, u32 arcId, u32 dataId, void *buffer, u32 bufferSize);
struct IcaAnime *ICA_ANIME_CreateWithStreamBuffer(u32 heapId, u32 arcId, u32 dataId, u32 bufFrameNum, void *buffer, u32 bufferSize);
struct IcaAnime *ICA_ANIME_CreateFull(u32 heapId, u32 arcId, u32 dataId);
struct IcaAnime *ICA_ANIME_CreateStream(u32 heapId, u32 arcId, u32 dataId, u32 bufFrameNum);

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of ica_anime.c, prototypes copied from their definitions. */

struct IcaAnime;
struct VecFx32;

#include "../types.h"

struct IcaAnime *ICA_ANIME_CreateWithFullBuffer(u32 heapId, u32 arcId, u32 dataId, void *buffer, u32 bufferSize);
struct IcaAnime *ICA_ANIME_CreateWithStreamBuffer(u32 heapId, u32 arcId, u32 dataId, u32 bufFrameNum, void *buffer, u32 bufferSize);
struct IcaAnime *ICA_ANIME_CreateFull(u32 heapId, u32 arcId, u32 dataId);
struct IcaAnime *ICA_ANIME_CreateStream(u32 heapId, u32 arcId, u32 dataId, u32 bufFrameNum);
void ICA_ANIME_Delete(struct IcaAnime *anime);
u32 ICA_ANIME_IncFrameLoop(struct IcaAnime *anime, s32 step);
u32 ICA_ANIME_IncFrameNoLoop(struct IcaAnime *anime, s32 step);
void ICA_ANIME_SetFrame(struct IcaAnime *anime, s32 frame);
u32 ICA_ANIME_GetFrameNum(struct IcaAnime *anime);
u32 ICA_ANIME_GetFrame(struct IcaAnime *anime);
u32 ICA_ANIME_GetTranslate(struct IcaAnime *anime, struct VecFx32 *trans);
u32 ICA_ANIME_GetRotate(struct IcaAnime *anime, struct VecFx32 *rot);
u32 ICA_ANIME_GetScale(struct IcaAnime *anime, struct VecFx32 *scale);
u32 ICA_ANIME_GetTranslateAt(struct IcaAnime *anime, struct VecFx32 *trans, u32 frame);
void ICA_ANIME_Clear(struct IcaAnime *anime);
void ICA_ANIME_LoadHeader(struct IcaAnime *anime, u32 arcId, u32 dataId, u32 heapId);
void ICA_ANIME_AllocBuffer(struct IcaAnime *anime, int bufFrameNum);
int ICA_ANIME_SetBuffer(struct IcaAnime *anime, int bufFrameNum, u8 *buffer, int bufferSize);
void ICA_ANIME_LoadFrames(struct IcaAnime *anime, s32 frame);
void ICA_ANIME_SetCameraStatus(void *camera, struct IcaAnime *anime);
void ICA_ANIME_SetCameraPos(void *camera, struct IcaAnime *anime);
void ICA_ANIME_SetCameraTarget(void *camera, struct IcaAnime *anime);
/* END mkheaders: generated region */

#endif
