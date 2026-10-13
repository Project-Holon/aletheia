/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, func_021F37BC, func_021F381C
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
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_020490F4  0x020490F4  arm
 *   func_02046E24  0x02046E24  arm
 *   func_02046F50  0x02046F50  arm
 *   func_02046FF8  0x02046FF8  arm
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_020477A4  0x020477A4  arm
 *   func_02046BE0  0x02046BE0  arm
 *   func_02049238  0x02049238  arm
 *   d_021F38A8     0x021F38A8  data  a4
 *   d_021F387C     0x021F387C  data  a4
 *   d_021F3888     0x021F3888  data  a4
 *   d_021F3898     0x021F3898  data  a4
 *   func_02047738  0x02047738  arm
 *   func_0204762C  0x0204762C  arm
 *   func_02047504  0x02047504  arm
 *   func_020470D0  0x020470D0  arm
 *   func_02046EFC  0x02046EFC  arm
 *   func_02047910  0x02047910  arm
 */
#include "../ov021/fld_exp_obj_types.h"
#include "unit_021F36C0_types.h"

extern u16 func_02188C84(struct FieldMap *fieldMap);
extern void *func_020490F4(u32 archiveId, u32 heapId);
extern G3dResource *func_02046E24(void *archiveHandle, u32 fileId);
extern u32 func_02046F50(G3dResource *resource, u32 kind);
extern int func_02046FF8(G3dResource *resource);
extern G3dRender *func_02047400(G3dResource *model, u32 modelIndex, G3dResource *texture);
extern G3dAnime *func_02047564(G3dRender *render, G3dResource *animeResource, int unused);
extern G3dObject *func_0204767C(G3dRender *render, G3dAnime **animeTable, int animeCount);
extern u32 func_020477A4(G3dObject *object, u32 animeIndex);
extern void func_02046BE0(u32 sortMode, u32 bufferMode);
extern void func_02049238(void *archiveHandle);
extern void func_02047738(G3dObject *object);
extern void func_0204762C(G3dAnime *anime);
extern void func_02047504(G3dRender *render);
extern int func_020470D0(G3dResource *resource);
extern void func_02046EFC(G3dResource *resource);
extern int func_02047910(G3dObject *object, int animeIndex, int amount);

void func_021F36C0(void *unused, struct FieldMap *fieldMap, ModelScene *scene);
void func_021F37BC(void *unused, struct FieldMap *fieldMap, ModelScene *scene);
void func_021F381C(void *unused, struct FieldMap *fieldMap, ModelScene *scene);

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

    archiveHandle = func_020490F4(0xbe, (u16)((func_02188C84(fieldMap) & 0x7fff) | 0x8000));
    for (i = 0; i < MODEL_SCENE_RESOURCE_COUNT; i++) {
        scene->resource[i] = func_02046E24(archiveHandle, d_021F38A8[i]);
        if (func_02046F50(scene->resource[i], G3D_RES_KIND_TEX)) {
            func_02046FF8(scene->resource[i]);
        }
    }
    for (i = 0; i < MODEL_SCENE_RENDER_COUNT; i++) {
        modelIndex = d_021F387C[i];
        if (func_02046F50(scene->resource[modelIndex], G3D_RES_KIND_TEX)) {
            scene->render[i] = func_02047400(scene->resource[modelIndex], 0, scene->resource[modelIndex]);
        } else {
            scene->render[i] = func_02047400(scene->resource[modelIndex], 0, 0);
        }
    }
    for (i = 0; i < MODEL_SCENE_ANIME_COUNT; i++) {
        scene->anime[i] = func_02047564(scene->render[d_021F3888[i]], scene->resource[d_021F3898[i]], 0);
    }
    for (i = 0; i < MODEL_SCENE_OBJECT_COUNT; i++) {
        scene->object[i] = func_0204767C(scene->render[i], scene->anime, MODEL_SCENE_ANIME_COUNT);
    }
    func_020477A4(scene->object[0], 0);
    func_020477A4(scene->object[0], 3);
    func_020477A4(scene->object[1], 1);
    func_020477A4(scene->object[2], 2);
    func_02046BE0(1, 1);
    func_02049238(archiveHandle);
}

/* Free everything the load built, last created first. */
void func_021F37BC(void *unused, struct FieldMap *fieldMap, ModelScene *scene)
{
    int i;

    for (i = 0; i < MODEL_SCENE_OBJECT_COUNT; i++)
        func_02047738(scene->object[i]);
    for (i = 0; i < MODEL_SCENE_ANIME_COUNT; i++)
        func_0204762C(scene->anime[i]);
    for (i = 0; i < MODEL_SCENE_RENDER_COUNT; i++)
        func_02047504(scene->render[i]);
    for (i = 0; i < MODEL_SCENE_RESOURCE_COUNT; i++) {
        if (func_02046F50(scene->resource[i], G3D_RES_KIND_TEX))
            func_020470D0(scene->resource[i]);
        func_02046EFC(scene->resource[i]);
    }
}

/* Advance the animations of the three objects by one frame. */
void func_021F381C(void *unused, struct FieldMap *fieldMap, ModelScene *scene)
{
    u32 frameStep = 1 << 12;

    func_02047910(scene->object[0], 0, frameStep);
    func_02047910(scene->object[0], 3, frameStep);
    func_02047910(scene->object[1], 1, frameStep);
    func_02047910(scene->object[2], 2, frameStep);
    func_02046BE0(1, 1);
}
