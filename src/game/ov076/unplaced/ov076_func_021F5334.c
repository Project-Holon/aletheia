/*
 * function: func_021F5334
 * address:  0x021F5334
 * packet:   pkt_ov076_021F5334
 * region:   ov076
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte-correct; the only wildcard is the THM_CALL at +0x118 to the arm9
 * leaf func_02047888 (unlabelled ARM, 48 bytes, the integrator's), which has no
 * witness outside this range.  Reading the frame count into `cur` before
 * the f38 test is what loads it ahead of the compare (3 lines otherwise).
 *
 * blocker:
 *   0x02047888 arm9 ARM, verified EXACT (--arm, no --region) by the ov021
 *   func_021D0750 lane; copied from src/pending/ov/ov021_func_021D0750.c:
 *     typedef unsigned short u16;
 *     int func_02047888(int *a, int idx, int *out) {
 *         int *p = ((int **)a[2])[idx];
 *         if (p == 0) { return 0; }
 *         *out = ((u16 *)((int *)p[1])[2])[2] << 12;
 *         return 1;
 *     }
 *
 * Task callback that func_021F52D8 registers: ov073 func_021F53C8's fade
 * states 0-2, then a 3D model load, a frame-count wait with a fade-out
 * and the teardown.  The work block is the 0x44 bytes func_021F52D8
 * allocates (an EncEffModelScene).
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02189A08  0x02189A08  thumb  ov021
 *   func_021CF560  0x021CF560  thumb  ov021
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 *   func_02080C44  0x02080C44  arm
 *   func_02080294  0x02080294  arm
 *   func_02046DB8  0x02046DB8  arm
 *   func_02188C84  0x02188C84  thumb  ov021
 *   SCREENTEX_Create  0x0202E560  thumb
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_020477A4  0x020477A4  arm
 *   SCREENTEX_CaptureDisplay  0x0202E610  thumb
 *   func_021899F0  0x021899F0  thumb  ov021
 *   func_021899F8  0x021899F8  thumb  ov021
 *   func_02047888  0x02047888  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_02047828  0x02047828  arm
 *   func_020478B8  0x020478B8  arm
 *   func_02047738  0x02047738  arm
 *   func_0204762C  0x0204762C  arm
 *   func_02047504  0x02047504  arm
 *   func_02046EFC  0x02046EFC  arm
 */
#include "../enceff_model_types.h"

struct GameEvent;
struct AnmCtl;
struct G3dOwner;
struct G3dRec;
struct G3dSys;
struct Rec;
struct Tagged;
extern struct GameSystem *func_020124E4(struct GameEvent *event);
extern void func_0204E720(u32 planes, s32 startLevel, s32 endLevel, s32 wait);
extern int func_0204E804(void);
extern u16 func_02080C44(void);
extern void func_02080294(u32 bank);
extern void *func_02046DB8(u32 archiveId, u32 memberIndex);
extern u16 func_02188C84(struct FieldMap *fieldMap);
extern void *SCREENTEX_Create(u32 heapId, u32 sel);
extern void *func_02047400(void *modelResource, u32 modelIndex, void *screenTex);
extern struct G3dRec *func_02047564(struct G3dOwner *render, const struct G3dOwner *animeResource, int index);
extern void *func_0204767C(void *render, void **animes, int count);
extern u32 func_020477A4(struct G3dSys *object, u32 index);
extern void SCREENTEX_CaptureDisplay(u32 a0, u32 a1);
extern u32 func_021899F0(struct FieldMap *fieldMap);
extern void func_021899F8(struct FieldMap *fieldMap, u32 mode);
extern int func_02047888(int *object, int index, int *frameMax);
extern void func_020061E4(u32 id);
extern u32 func_02047828(struct AnmCtl *object, u32 index, s32 *frame);
extern int func_020478B8(void *object, int index, int amount);
extern void func_02047738(struct Rec *object);
extern void func_0204762C(struct Rec *anime);
extern void func_02047504(struct Rec *render);
extern void func_02046EFC(struct Tagged *resource);

int func_021F5334(struct GameEvent *event, int *state)
{
    EncEffModelScene *scene;
    s32 frameMax;
    s32 frame;
    s32 current;

    scene = func_021CF560(func_02189A08(func_0201210C(func_020124E4(event))));
    switch (*state) {
    case 0:
        func_0204E720(4, 0, 0x10, 0);
        *state = *state + 1;
    case 1:
        if (func_0204E804() == 0) {
            func_0204E720(4, 0x10, 0, 0);
            *state = *state + 1;
        }
        break;
    case 2:
        if (func_0204E804() == 0) {
            scene->flashCount = scene->flashCount + 1;
            if (scene->flashCount < 2) {
                func_0204E720(4, 0, 0x10, 0);
                *state = 1;
            } else {
                *state = *state + 1;
            }
        }
        break;
    case 3:
        scene->texBankMask = func_02080C44();
        scene->texBankAdded = 0;
        if ((scene->texBankMask & 8) == 0) {
            scene->texBankAdded = 1;
            scene->texBankMask |= 8;
            func_02080294(scene->texBankMask);
        }
        scene->modelResource = func_02046DB8(0x81, scene->modelIndex);
        scene->animeResource = func_02046DB8(0x81, scene->animeIndex);
        scene->screenTex = SCREENTEX_Create(func_02188C84(scene->fieldMap), 3);
        scene->renderObj = func_02047400(scene->modelResource, 0, scene->screenTex);
        scene->animeObj = func_02047564(scene->renderObj, scene->animeResource, 0);
        scene->object = func_0204767C(scene->renderObj, &scene->animeObj, 1);
        func_020477A4(scene->object, 0);
        SCREENTEX_CaptureDisplay(3, 3);
        scene->savedDrawMode = func_021899F0(scene->fieldMap);
        func_021899F8(scene->fieldMap, 2);
        scene->fadeStarted = 0;
        func_02047888(scene->object, 0, &frameMax);
        scene->fadeStartFrame = frameMax - 0x14000;
        if (scene->soundId != -1) {
            func_020061E4(scene->soundId);
        }
        *state = *state + 1;
        break;
    case 4:
        func_02047828(scene->object, 0, &frame);
        current = frame;
        if (scene->fadeStarted == 0 && current >= scene->fadeStartFrame) {
            func_0204E720(scene->fadeScreens, 0, 0x10, 3);
            scene->fadeStarted = 1;
        }
        if (func_020478B8(scene->object, 0, 0x1000) == 0 && func_0204E804() == 0) {
            *state = *state + 1;
        }
        break;
    case 5:
        if (scene->texBankAdded == 1) {
            scene->texBankMask &= ~8;
            func_02080294(scene->texBankMask);
        }
        func_02047738(scene->object);
        func_0204762C(scene->animeObj);
        func_02047504(scene->renderObj);
        func_02046EFC(scene->animeResource);
        func_02046EFC(scene->screenTex);
        func_02046EFC(scene->modelResource);
        func_021899F8(scene->fieldMap, scene->savedDrawMode);
        return 1;
    }
    return 0;
}
