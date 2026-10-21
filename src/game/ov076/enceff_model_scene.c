/*
 * file:     enceff_model_scene.c
 * unit:     yes
 * function: ENCEFF_BuildModelSceneKind00, ENCEFF_BuildModelSceneKind01, ENCEFF_BuildModelSceneKind05, ENCEFF_BuildModelSceneKind06, ENCEFF_BuildModelSceneKind31, ENCEFF_BuildModelSceneKind35, ENCEFF_StartModelScene, ENCEFF_UpdateModelScene, ENCEFF_ModelSceneEventMain
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
 * Byte-correct; the only wildcard is the THM_CALL at +0x118 to the arm9
 * leaf G3D_SYSTEM_GetObjectAnimeFrameMax (unlabelled ARM, 48 bytes, the integrator's), which has no
 * witness outside this range.  Reading the frame count into `cur` before
 * the f38 test is what loads it ahead of the compare (3 lines otherwise).
 * blocker:
 *   0x02047888 arm9 ARM, verified EXACT (--arm, no --region) by the ov021
 *   FLDEFF_BUBBLE_Update lane; copied from src/pending/ov/FLDEFF_BUBBLE_Update.c:
 *     typedef unsigned short u16;
 *     int G3D_SYSTEM_GetObjectAnimeFrameMax(int *a, int idx, int *out) {
 *         int *p = ((int **)a[2])[idx];
 *         if (p == 0) { return 0; }
 *         *out = ((u16 *)((int *)p[1])[2])[2] << 12;
 *         return 1;
 *     }
 * Task callback that ENCEFF_StartModelScene registers: ov073 ENCEFF_NameCutInEventMain's fade
 * states 0-2, then a 3D model load, a frame-count wait with a fade-out
 * and the teardown.  The work block is the 0x44 bytes ENCEFF_StartModelScene
 * allocates (an EncEffModelScene).
 *
 * symbols:
 *   FIELDMAP_GetEncEff 0x02189A08 thumb ov021
 *   ENCEFF_GetWork 0x021CF560 thumb ov021
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   ENCEFF_AllocWork  0x021CF52C  thumb  ov021
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   SCREENTEX_SetupCamera 0x0202E688 thumb
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   FADE_Start  0x0204E720  arm
 *   FADE_IsActive  0x0204E804  arm
 *   GX_GetBankForTex  0x02080C44  arm
 *   GX_SetBankForTex  0x02080294  arm
 *   G3D_SYSTEM_CreateResourceArc  0x02046DB8  arm
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   SCREENTEX_Create  0x0202E560  thumb
 *   G3D_SYSTEM_CreateRender  0x02047400  arm
 *   G3D_SYSTEM_CreateAnime  0x02047564  arm
 *   G3D_SYSTEM_CreateObject  0x0204767C  arm
 *   G3D_SYSTEM_EnableObjectAnime  0x020477A4  arm
 *   SCREENTEX_CaptureDisplay  0x0202E610  thumb
 *   FIELDMAP_GetDrawMode  0x021899F0  thumb  ov021
 *   FIELDMAP_SetDrawMode  0x021899F8  thumb  ov021
 *   G3D_SYSTEM_GetObjectAnimeFrameMax  0x02047888  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   G3D_SYSTEM_GetObjectAnimeFrame  0x02047828  arm
 *   G3D_SYSTEM_IncObjectAnimeFrame  0x020478B8  arm
 *   G3D_SYSTEM_DeleteObject  0x02047738  arm
 *   G3D_SYSTEM_DeleteAnime  0x0204762C  arm
 *   G3D_SYSTEM_DeleteRender  0x02047504  arm
 *   G3D_SYSTEM_DeleteResource  0x02046EFC  arm
 */
struct GameSystem;
#include "../arm9/game_event.h"
#include "enceff_model_types.h"

struct Desc;
struct GameEvent;
struct AnmCtl;
struct G3dOwner;
struct G3dRec;
struct G3dSys;
struct Rec;
struct Tagged;
#include "../arm9/screentex.h"
#include "../arm9/fade.h"
#include "../sdk_gx.h"
#include "../arm9/gx_vramcnt_types.h"
#include "../arm9/gx_vramcnt.h"
struct G3dResource;
#include "../arm9/g3d_system.h"
#include "../ov021/fieldmap.h"
struct G3dRender;
struct G3dAnime;
struct G3dObject;
#include "../arm9/gfl_use.h"
void *ENCEFF_BuildModelSceneKind00(void *gameSystem, struct FieldMap *fieldMap, int useSubScreen);
void *ENCEFF_BuildModelSceneKind01(void *gameSystem, struct FieldMap *fieldMap, int useSubScreen);
void *ENCEFF_BuildModelSceneKind05(void *gameSystem, struct FieldMap *fieldMap, int useSubScreen);
void *ENCEFF_BuildModelSceneKind06(void *gameSystem, struct FieldMap *fieldMap, int useSubScreen);
void *ENCEFF_BuildModelSceneKind31(void *gameSystem, struct FieldMap *fieldMap, int useSubScreen);
void *ENCEFF_BuildModelSceneKind35(void *gameSystem, struct FieldMap *fieldMap, int useSubScreen);
void *ENCEFF_StartModelScene(void *gameSystem, struct FieldMap *fieldMap, u32 modelIndex, u32 animeIndex, int useSubScreen);
void ENCEFF_UpdateModelScene(struct EncEffWork *eff);
int ENCEFF_ModelSceneEventMain(struct GameEvent *event, u32 *state, void *eventWork);


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
    ((EncEffModelScene *)ENCEFF_GetWork(FIELDMAP_GetEncEff(fieldMap)))->soundId = 0x7F3;
    return event;
}



void *ENCEFF_StartModelScene(void *gameSystem, struct FieldMap *fieldMap, u32 modelIndex, u32 animeIndex, int useSubScreen)
{
    EncEffModelScene *scene;
    void *event;

    scene = ENCEFF_AllocWork(FIELDMAP_GetEncEff(GAMESYSTEM_GetFieldMap(gameSystem)), sizeof(EncEffModelScene), 0x50);
    event = GAME_EVENT_Create(gameSystem, 0, ENCEFF_ModelSceneEventMain, 0);
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


void ENCEFF_UpdateModelScene(struct EncEffWork *eff) { SCREENTEX_SetupCamera((((EncEffModelScene *)ENCEFF_GetWork(eff))->object)); }


int ENCEFF_ModelSceneEventMain(struct GameEvent *event, u32 *state, void *eventWork)
{
    EncEffModelScene *scene;
    s32 frameMax;
    s32 frame;
    s32 current;

    scene = ENCEFF_GetWork(FIELDMAP_GetEncEff(GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(event))));
    switch (*state) {
    case 0:
        FADE_Start(4, 0, 0x10, 0);
        *state = *state + 1;
    case 1:
        if (FADE_IsActive() == 0) {
            FADE_Start(4, 0x10, 0, 0);
            *state = *state + 1;
        }
        break;
    case 2:
        if (FADE_IsActive() == 0) {
            scene->flashCount = scene->flashCount + 1;
            if (scene->flashCount < 2) {
                FADE_Start(4, 0, 0x10, 0);
                *state = 1;
            } else {
                *state = *state + 1;
            }
        }
        break;
    case 3:
        scene->texBankMask = GX_GetBankForTex();
        scene->texBankAdded = 0;
        if ((scene->texBankMask & 8) == 0) {
            scene->texBankAdded = 1;
            scene->texBankMask |= 8;
            GX_SetBankForTex(scene->texBankMask);
        }
        scene->modelResource = G3D_SYSTEM_CreateResourceArc(0x81, scene->modelIndex);
        scene->animeResource = G3D_SYSTEM_CreateResourceArc(0x81, scene->animeIndex);
        scene->screenTex = SCREENTEX_Create(FIELDMAP_GetHeapId(scene->fieldMap), 3);
        scene->renderObj = G3D_SYSTEM_CreateRender(scene->modelResource, 0, scene->screenTex);
        scene->animeObj = G3D_SYSTEM_CreateAnime(scene->renderObj, scene->animeResource, 0);
        scene->object = G3D_SYSTEM_CreateObject(scene->renderObj, (struct G3dAnime **)(&scene->animeObj), 1);
        G3D_SYSTEM_EnableObjectAnime(scene->object, 0);
        SCREENTEX_CaptureDisplay(3, 3);
        scene->savedDrawMode = FIELDMAP_GetDrawMode(scene->fieldMap);
        FIELDMAP_SetDrawMode(scene->fieldMap, 2);
        scene->fadeStarted = 0;
        G3D_SYSTEM_GetObjectAnimeFrameMax(scene->object, 0, &frameMax);
        scene->fadeStartFrame = frameMax - 0x14000;
        if (scene->soundId != -1) {
            GFL_USE_PlaySeDefaultVolume(scene->soundId);
        }
        *state = *state + 1;
        break;
    case 4:
        G3D_SYSTEM_GetObjectAnimeFrame(scene->object, 0, &frame);
        current = frame;
        if (scene->fadeStarted == 0 && current >= scene->fadeStartFrame) {
            FADE_Start(scene->fadeScreens, 0, 0x10, 3);
            scene->fadeStarted = 1;
        }
        if (G3D_SYSTEM_IncObjectAnimeFrame(scene->object, 0, 0x1000) == 0 && FADE_IsActive() == 0) {
            *state = *state + 1;
        }
        break;
    case 5:
        if (scene->texBankAdded == 1) {
            scene->texBankMask &= ~8;
            GX_SetBankForTex(scene->texBankMask);
        }
        G3D_SYSTEM_DeleteObject(scene->object);
        G3D_SYSTEM_DeleteAnime(scene->animeObj);
        G3D_SYSTEM_DeleteRender(scene->renderObj);
        G3D_SYSTEM_DeleteResource(scene->animeResource);
        G3D_SYSTEM_DeleteResource(scene->screenTex);
        G3D_SYSTEM_DeleteResource(scene->modelResource);
        FIELDMAP_SetDrawMode(scene->fieldMap, scene->savedDrawMode);
        return 1;
    }
    return 0;
}
