/*
 * file:     unit_021F5260.c
 * unit:     yes
 * function: ENCEFF_BuildModelSceneKind00, ENCEFF_BuildModelSceneKind01, ENCEFF_BuildModelSceneKind05, ENCEFF_BuildModelSceneKind06, ENCEFF_BuildModelSceneKind31, ENCEFF_BuildModelSceneKind35, ENCEFF_StartModelScene, ENCEFF_UpdateModelScene
 * address:  0x021F5260
 * region:   ov076
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   FIELDMAP_GetEncEff 0x02189A08 thumb ov021
 *   ENCEFF_GetWork 0x021CF560 thumb ov021
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   ENCEFF_AllocWork  0x021CF52C  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   ENCEFF_ModelSceneEventMain  0x021F5334  thumb  ov076
 *   SCREENTEX_SetupCamera 0x0202E688 thumb
 */
#include "enceff_model_types.h"

struct Desc;

extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int ENCEFF_ModelSceneEventMain(void *task, int *state);
extern void SCREENTEX_SetupCamera(void *object);
void *ENCEFF_BuildModelSceneKind00(void *gameSystem, struct FieldMap *fieldMap, int useSubScreen);
void *ENCEFF_BuildModelSceneKind01(void *gameSystem, struct FieldMap *fieldMap, int useSubScreen);
void *ENCEFF_BuildModelSceneKind05(void *gameSystem, struct FieldMap *fieldMap, int useSubScreen);
void *ENCEFF_BuildModelSceneKind06(void *gameSystem, struct FieldMap *fieldMap, int useSubScreen);
void *ENCEFF_BuildModelSceneKind31(void *gameSystem, struct FieldMap *fieldMap, int useSubScreen);
void *ENCEFF_BuildModelSceneKind35(void *gameSystem, struct FieldMap *fieldMap, int useSubScreen);
void *ENCEFF_StartModelScene(void *gameSystem, struct FieldMap *fieldMap, u32 modelIndex, u32 animeIndex, int useSubScreen);
void ENCEFF_UpdateModelScene(struct EncEffWork *eff);

void *ENCEFF_BuildModelSceneKind00(void *gameSystem, struct FieldMap *fieldMap, int useSubScreen) { return ENCEFF_StartModelScene(gameSystem, fieldMap, 7, 6, useSubScreen); }

void *ENCEFF_BuildModelSceneKind01(void *gameSystem, struct FieldMap *fieldMap, int useSubScreen) { return ENCEFF_StartModelScene(gameSystem, fieldMap, 9, 8, useSubScreen); }

void *ENCEFF_BuildModelSceneKind05(void *gameSystem, struct FieldMap *fieldMap, int useSubScreen) { return ENCEFF_StartModelScene(gameSystem, fieldMap, 5, 4, useSubScreen); }

void *ENCEFF_BuildModelSceneKind06(void *gameSystem, struct FieldMap *fieldMap, int useSubScreen) { return ENCEFF_StartModelScene(gameSystem, fieldMap, 3, 2, useSubScreen); }

/*
 * Extent tail: two bytes of alignment padding.
 */
void *ENCEFF_BuildModelSceneKind31(void *gameSystem, struct FieldMap *fieldMap, int useSubScreen) { return ENCEFF_StartModelScene(gameSystem, fieldMap, 1, 0, useSubScreen); }

void *ENCEFF_BuildModelSceneKind35(void *gameSystem, struct FieldMap *fieldMap, int useSubScreen) {
    void *event;
    event = ENCEFF_StartModelScene(gameSystem, fieldMap, 11, 10, useSubScreen);
    ENCEFF_GetWork(FIELDMAP_GetEncEff(fieldMap))->soundId = 0x7F3;
    return event;
}


void *ENCEFF_StartModelScene(void *gameSystem, struct FieldMap *fieldMap, u32 modelIndex, u32 animeIndex, int useSubScreen)
{
    EncEffModelScene *scene;
    void *event;

    scene = ENCEFF_AllocWork(FIELDMAP_GetEncEff(GAMESYSTEM_GetFieldMap(gameSystem)), sizeof(EncEffModelScene), 0x50);
    event = func_020122C0(gameSystem, 0, ENCEFF_ModelSceneEventMain, 0);
    scene->fieldMap = fieldMap;
    scene->modelIndex = modelIndex;
    scene->animeIndex = animeIndex;
    scene->soundId = -1;
    if (useSubScreen != 0) {
        scene->fadeScreens = 0xC;
    } else {
        scene->fadeScreens = 3;
    }
    return event;
}

void ENCEFF_UpdateModelScene(struct EncEffWork *eff) { SCREENTEX_SetupCamera(ENCEFF_GetWork(eff)->object); }
