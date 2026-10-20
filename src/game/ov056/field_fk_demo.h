#ifndef GAME_OV056_FIELD_FK_DEMO_H
#define GAME_OV056_FIELD_FK_DEMO_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_fk_demo.c, prototypes copied from their definitions. */

struct GameEvent;
struct GameSystem;
struct FieldMap;
struct G3dAnime;
struct TcbTask;
struct BuildModelMan;
struct FieldCamera;
struct FieldPlayer;
struct MyStatus;
struct FieldSubproc;

#include "../types.h"
#include "../ov056/field_fk_demo_types.h"

struct GameEvent *FIELD_FK_DEMO_StartEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 variant);
u32 FIELD_FK_DEMO_GetCameraSettingId(u32 variant);
int FIELD_FK_DEMO_GetAnimeEndFrame(struct G3dAnime *anime);
void FIELD_FK_DEMO_UploadModelTask(struct TcbTask *tcb, FkDemoWork *work);
struct GameEvent *FIELD_FK_DEMO_CreateEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 variant);
int FIELD_FK_DEMO_EventMain(struct GameEvent *event, int *seq, FkDemoWork *work);
void FIELD_FK_DEMO_InitBuildAnime(FkBuildModelAnime *anime, struct BuildModelMan *man, int variant);
void FIELD_FK_DEMO_DeleteBuildAnime(FkBuildModelAnime *anime);
void FIELD_FK_DEMO_StartBuildAnime(FkBuildModelAnime *anime);
int FIELD_FK_DEMO_IsBuildAnimeDone(FkBuildModelAnime *anime);
void FIELD_FK_DEMO_InitCamera(FkDemoCamera *demoCamera, struct FieldCamera *fieldCamera, u16 heapId, int variant);
void FIELD_FK_DEMO_ExitCamera(FkDemoCamera *demoCamera);
int FIELD_FK_DEMO_StepCamera(FkDemoCamera *demoCamera);
void FIELD_FK_DEMO_ApplyCameraAnime(FkDemoCamera *demoCamera);
void FIELD_FK_DEMO_InitModel(FkDemoModel *model, struct FieldPlayer *player, struct MyStatus *myStatus, int heapId, int variant);
void FIELD_FK_DEMO_CreateModelObject(FkDemoModel *model);
void FIELD_FK_DEMO_DeleteModel(FkDemoModel *model);
int FIELD_FK_DEMO_StepModel(FkDemoModel *model);
void FIELD_FK_DEMO_SetPlayerHidden(FkDemoModel *model, int hide);
void FIELD_FK_DEMO_UploadModelOnce(FkDemoModel *model);
void FIELD_FK_DEMO_DrawModel(FkDemoModel *model);
void FIELD_FK_DEMO_DrawProc(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkDemoDrawWork *work);
void FIELD_FK_DEMO_CreateSoundAnime(FkSoundAnime **out, int variant, u16 heapId);
void FIELD_FK_DEMO_DeleteSoundAnime(FkSoundAnime **soundAnime);
int FIELD_FK_DEMO_StepSoundAnime(FkSoundAnime **soundAnime);
void FIELD_FK_BUILD_SOUND_Init(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkAnimeSoundWork *work);
void FIELD_FK_BUILD_SOUND_Exit(struct FieldSubproc *proc, struct FieldMap *fieldMap);
void FIELD_FK_BUILD_SOUND_Update(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkAnimeSoundWork *work);
/* END mkheaders: generated region */

#endif
