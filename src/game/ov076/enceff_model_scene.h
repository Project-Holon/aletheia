#ifndef GAME_OV076_ENCEFF_MODEL_SCENE_H
#define GAME_OV076_ENCEFF_MODEL_SCENE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of enceff_model_scene.c, prototypes copied from their definitions. */

struct FieldMap;
struct EncEffWork;
struct GameEvent;

#include "../types.h"

void *ENCEFF_BuildModelSceneKind00(void *gameSystem, struct FieldMap *fieldMap, int useSubScreen);
void *ENCEFF_BuildModelSceneKind01(void *gameSystem, struct FieldMap *fieldMap, int useSubScreen);
void *ENCEFF_BuildModelSceneKind05(void *gameSystem, struct FieldMap *fieldMap, int useSubScreen);
void *ENCEFF_BuildModelSceneKind06(void *gameSystem, struct FieldMap *fieldMap, int useSubScreen);
void *ENCEFF_BuildModelSceneKind31(void *gameSystem, struct FieldMap *fieldMap, int useSubScreen);
void *ENCEFF_BuildModelSceneKind35(void *gameSystem, struct FieldMap *fieldMap, int useSubScreen);
void *ENCEFF_StartModelScene(void *gameSystem, struct FieldMap *fieldMap, u32 modelIndex, u32 animeIndex, int useSubScreen);
void ENCEFF_UpdateModelScene(struct EncEffWork *eff);
int ENCEFF_ModelSceneEventMain(struct GameEvent *event, int *state, void *eventWork);
/* END mkheaders: generated region */

#endif
