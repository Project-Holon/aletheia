#ifndef GAME_OV021_FLD_EXP_OBJ_H
#define GAME_OV021_FLD_EXP_OBJ_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fld_exp_obj.c, prototypes copied from their definitions. */

struct G3dObject;

#include "../ov021/fld_exp_obj_types.h"
#include "../types.h"
#include "../arm9/g3d_util_types.h"
#include "../arm9/g3d_system_types.h"

FldExpObjCnt *FLD_EXP_OBJ_Create(u32 resCount, u32 objCount, u32 heapId);
void FLD_EXP_OBJ_Delete(FldExpObjCnt *cnt);
void FLD_EXP_OBJ_AddUnit(FldExpObjCnt *cnt, G3dUtilSetup *setup, u16 unitIdx);
void FLD_EXP_OBJ_RemoveUnit(FldExpObjCnt *cnt, u16 unitIdx);
G3dObjectStatus *FLD_EXP_OBJ_GetModelStatus(FldExpObjCnt *cnt, unsigned unitIdx, u16 modelIdx);
void FLD_EXP_OBJ_SetModelCullDraw(FldExpObjCnt *cnt, int unitIdx, u16 modelIdx, int cullDraw);
void FLD_EXP_OBJ_SetModelHidden(FldExpObjCnt *cnt, int unitIdx, u16 modelIdx, int hidden);
struct G3dObject *FLD_EXP_OBJ_GetModelObject(FldExpObjCnt *cnt, u32 unitIdx, int modelIdx);
void FLD_EXP_OBJ_Draw(FldExpObjCnt *cnt);
void FLD_EXP_OBJ_UpdateAnimes(FldExpObjCnt *cnt);
void FLD_EXP_OBJ_InitAnimeSet(FldExpObjAnimeSet *animeSet, int count, int heapId);
void *FLD_EXP_OBJ_GetAnime(FldExpObjCnt *cnt, int unitIdx, u16 modelIdx, u16 animeIdx);
void FLD_EXP_OBJ_SetAnimePaused(FldExpObjAnime *anime, int paused);
u8 FLD_EXP_OBJ_IsAnimePaused(FldExpObjAnime *anime);
void FLD_EXP_OBJ_SetAnimeLoop(FldExpObjAnime *anime, int loop);
int FLD_EXP_OBJ_IsAnimeStopped(FldExpObjAnime *anime);
void FLD_EXP_OBJ_SetAnimeFrame(FldExpObjCnt *cnt, int unitIdx, u16 modelIdx, u16 animeIdx, int frame);
int FLD_EXP_OBJ_GetAnimeFrame(FldExpObjCnt *cnt, int unitIdx, int modelIdx, int animeIdx);
void FLD_EXP_OBJ_SetAnimeEnabled(FldExpObjCnt *cnt, int unitIdx, u16 modelIdx, u16 animeIdx, int enable);
int FLD_EXP_OBJ_GetAnimeLastFrame(FldExpObjAnime *anime);
void FLD_EXP_OBJ_AddUnitFromArchive(FldExpObjCnt *cnt, const G3dUtilSetup *setup, u16 unitIdx);
/* END mkheaders: generated region */

#endif
