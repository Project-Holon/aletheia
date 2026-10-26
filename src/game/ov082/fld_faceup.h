#ifndef GAME_OV082_FLD_FACEUP_H
#define GAME_OV082_FLD_FACEUP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fld_faceup.c, prototypes copied from their definitions. */

struct GameEvent;
struct GameSystem;
struct FieldMap;

#include "../ov082/fld_faceup_types.h"

struct TcbTask;

struct GameEvent *FLD_FACEUP_Create(int faceType, int unusedVariant, int fadeBothScreens, struct GameSystem *gameSystem, void *scrcmdWork);
int FLD_FACEUP_OpenEventMain(struct GameEvent *event, int *seq, void *eventWork);
void FLD_FACEUP_SetupBg(FaceupWork *work, struct FieldMap *fieldMap);
struct GameEvent *FLD_FACEUP_StartClose(struct GameSystem *gameSystem);
void FLD_FACEUP_Delete(struct FieldMap *fieldMap);
void FLD_FACEUP_ResumeLipSync(struct FieldMap *fieldMap);
int FLD_FACEUP_CloseEventMain(struct GameEvent *event, int *seq, void *eventWork);
void FLD_FACEUP_Release(struct FieldMap *fieldMap, FaceupWork *work);
void FLD_FACEUP_SaveBgPriorities(FaceupWork *work);
void FLD_FACEUP_SaveVisiblePlanes(FaceupWork *work);
void FLD_FACEUP_RestoreBgPriorities(FaceupWork *work);
void FLD_FACEUP_RestoreVisiblePlanes(FaceupWork *work);
int FLD_FACEUP_StepFadeIn(FaceupWork *work);
void FLD_FACEUP_UpdateTaskMain(struct TcbTask *tcb, void *arg);
void FLD_FACEUP_VBlankUpload(struct TcbTask * tcbArg, void * workArg);
void FLD_FACEUP_StepAnim(const FaceupAnimFrame *frames, unsigned frameCount, unsigned firstTile, unsigned tileStride, unsigned long tileWidth, FaceupAnim *anim);
void FLD_FACEUP_InitAnim(FaceupAnim *anim);
/* END mkheaders: generated region */

#endif
