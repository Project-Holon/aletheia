/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, GIMMICK57_DeleteModelScene, GIMMICK57_AdvanceModelScene
 * address:  0x021F36C0
 * region:   ov057
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   func_020490F4  0x020490F4  arm
 *   G3D_SYSTEM_CreateResourceArcHandle  0x02046E24  arm
 *   G3D_SYSTEM_CheckResourceType  0x02046F50  arm
 *   G3D_SYSTEM_TransVramTexture  0x02046FF8  arm
 *   G3D_SYSTEM_CreateRender  0x02047400  arm
 *   G3D_SYSTEM_CreateAnime  0x02047564  arm
 *   G3D_SYSTEM_CreateObject  0x0204767C  arm
 *   G3D_SYSTEM_EnableObjectAnime  0x020477A4  arm
 *   G3D_SYSTEM_SetSwapBuffersMode  0x02046BE0  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   d_021F38A8     0x021F38A8  data  a4
 *   d_021F387C     0x021F387C  data  a4
 *   d_021F3888     0x021F3888  data  a4
 *   d_021F3898     0x021F3898  data  a4
 *   G3D_SYSTEM_DeleteObject  0x02047738  arm
 *   G3D_SYSTEM_DeleteAnime  0x0204762C  arm
 *   G3D_SYSTEM_DeleteRender  0x02047504  arm
 *   G3D_SYSTEM_FreeVramTexture  0x020470D0  arm
 *   G3D_SYSTEM_DeleteResource  0x02046EFC  arm
 *   G3D_SYSTEM_LoopObjectAnimeFrame  0x02047910  arm
 */
#include "../ov021/fld_exp_obj_types.h"
#include "unit_021F36C0_types.h"

extern u16 FIELDMAP_GetHeapId(struct FieldMap *fieldMap);
extern void *func_020490F4(u32 archiveId, u32 heapId);
extern G3dResource *G3D_SYSTEM_CreateResourceArcHandle(void *archiveHandle, u32 fileId);
extern u32 G3D_SYSTEM_CheckResourceType(G3dResource *resource, u32 kind);
extern int G3D_SYSTEM_TransVramTexture(G3dResource *resource);
extern G3dRender *G3D_SYSTEM_CreateRender(G3dResource *model, u32 modelIndex, G3dResource *texture);
extern G3dAnime *G3D_SYSTEM_CreateAnime(G3dRender *render, G3dResource *animeResource, int unused);
extern G3dObject *G3D_SYSTEM_CreateObject(G3dRender *render, G3dAnime **animeTable, int animeCount);
extern u32 G3D_SYSTEM_EnableObjectAnime(G3dObject *object, u32 animeIndex);
extern void G3D_SYSTEM_SetSwapBuffersMode(u32 sortMode, u32 bufferMode);
extern void ARC_TOOL_DeleteHandle(void *archiveHandle);
extern void G3D_SYSTEM_DeleteObject(G3dObject *object);
extern void G3D_SYSTEM_DeleteAnime(G3dAnime *anime);
extern void G3D_SYSTEM_DeleteRender(G3dRender *render);
extern int G3D_SYSTEM_FreeVramTexture(G3dResource *resource);
extern void G3D_SYSTEM_DeleteResource(G3dResource *resource);
extern int G3D_SYSTEM_LoopObjectAnimeFrame(G3dObject *object, int animeIndex, int amount);

void func_021F36C0(void *unused, struct FieldMap *fieldMap, ModelScene *scene);
void GIMMICK57_DeleteModelScene(void *unused, struct FieldMap *fieldMap, ModelScene *scene);
void GIMMICK57_AdvanceModelScene(void *unused, struct FieldMap *fieldMap, ModelScene *scene);

/* File ids in the archive of the seven resources. */
extern const u32 d_021F38A8[];
/* Resource each render object takes its model (and its own texture) from. */
extern const u32 d_021F387C[];
/* Render object each animation is allocated against. */
extern const u32 d_021F3888[];
/* Resource each animation is read from. */
extern const u32 d_021F3898[];

/* Load the resources and build the render objects, animations and objects. */
void func_021F36C0(void *unused, struct FieldMap *fieldMap, ModelScene *scene)
{
    void *archiveHandle;
    int i;
    u32 modelIndex;

    archiveHandle = func_020490F4(0xbe, (u16)((FIELDMAP_GetHeapId(fieldMap) & 0x7fff) | 0x8000));
    for (i = 0; i < MODEL_SCENE_RESOURCE_COUNT; i++) {
        scene->resource[i] = G3D_SYSTEM_CreateResourceArcHandle(archiveHandle, d_021F38A8[i]);
        if (G3D_SYSTEM_CheckResourceType(scene->resource[i], G3D_RES_KIND_TEX)) {
            G3D_SYSTEM_TransVramTexture(scene->resource[i]);
        }
    }
    for (i = 0; i < MODEL_SCENE_RENDER_COUNT; i++) {
        modelIndex = d_021F387C[i];
        if (G3D_SYSTEM_CheckResourceType(scene->resource[modelIndex], G3D_RES_KIND_TEX)) {
            scene->render[i] = G3D_SYSTEM_CreateRender(scene->resource[modelIndex], 0, scene->resource[modelIndex]);
        } else {
            scene->render[i] = G3D_SYSTEM_CreateRender(scene->resource[modelIndex], 0, 0);
        }
    }
    for (i = 0; i < MODEL_SCENE_ANIME_COUNT; i++) {
        scene->anime[i] = G3D_SYSTEM_CreateAnime(scene->render[d_021F3888[i]], scene->resource[d_021F3898[i]], 0);
    }
    for (i = 0; i < MODEL_SCENE_OBJECT_COUNT; i++) {
        scene->object[i] = G3D_SYSTEM_CreateObject(scene->render[i], scene->anime, MODEL_SCENE_ANIME_COUNT);
    }
    G3D_SYSTEM_EnableObjectAnime(scene->object[0], 0);
    G3D_SYSTEM_EnableObjectAnime(scene->object[0], 3);
    G3D_SYSTEM_EnableObjectAnime(scene->object[1], 1);
    G3D_SYSTEM_EnableObjectAnime(scene->object[2], 2);
    G3D_SYSTEM_SetSwapBuffersMode(1, 1);
    ARC_TOOL_DeleteHandle(archiveHandle);
}

/* Free everything the load built, last created first. */
void GIMMICK57_DeleteModelScene(void *unused, struct FieldMap *fieldMap, ModelScene *scene)
{
    int i;

    for (i = 0; i < MODEL_SCENE_OBJECT_COUNT; i++)
        G3D_SYSTEM_DeleteObject(scene->object[i]);
    for (i = 0; i < MODEL_SCENE_ANIME_COUNT; i++)
        G3D_SYSTEM_DeleteAnime(scene->anime[i]);
    for (i = 0; i < MODEL_SCENE_RENDER_COUNT; i++)
        G3D_SYSTEM_DeleteRender(scene->render[i]);
    for (i = 0; i < MODEL_SCENE_RESOURCE_COUNT; i++) {
        if (G3D_SYSTEM_CheckResourceType(scene->resource[i], G3D_RES_KIND_TEX))
            G3D_SYSTEM_FreeVramTexture(scene->resource[i]);
        G3D_SYSTEM_DeleteResource(scene->resource[i]);
    }
}

/* Advance the animations of the three objects by one frame. */
void GIMMICK57_AdvanceModelScene(void *unused, struct FieldMap *fieldMap, ModelScene *scene)
{
    u32 frameStep = 1 << 12;

    G3D_SYSTEM_LoopObjectAnimeFrame(scene->object[0], 0, frameStep);
    G3D_SYSTEM_LoopObjectAnimeFrame(scene->object[0], 3, frameStep);
    G3D_SYSTEM_LoopObjectAnimeFrame(scene->object[1], 1, frameStep);
    G3D_SYSTEM_LoopObjectAnimeFrame(scene->object[2], 2, frameStep);
    G3D_SYSTEM_SetSwapBuffersMode(1, 1);
}
