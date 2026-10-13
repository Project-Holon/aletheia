/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, func_021F3740, func_021F3764, func_021F3770, func_021F37F0, func_021F390C, func_021F392C
 * address:  0x021F36C0
 * region:   ov044
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F39E8     0x021F39E8  data  ov044
 *   d_021F3A1C     0x021F3A1C  data  a4
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE4A4  0x021BE4A4  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021897BC 0x021897BC thumb ov021
 *   func_021897A0 0x021897A0 thumb ov021
 *   func_02188C80 0x02188C80 thumb ov021
 *   func_021BE418 0x021BE418 thumb ov021
 *   func_021BE580 0x021BE580 thumb ov021
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EC4 0x02012EC4 thumb
 *   func_0200B3A4 0x0200B3A4 thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E4  0x020124E4  thumb
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218EC5C  0x0218EC5C  thumb  ov021
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_0218EC30  0x0218EC30  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_021BE6BC  0x021BE6BC  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021A3044  0x021A3044  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 */
#include "unit_021F36C0_types.h"

struct GameEvent;

extern void *func_02188D2C(void *fieldMap);
extern u16 func_02188C84(u8 *fieldMap);
extern void *func_02189764(unsigned char *fieldMap, int id, int a, int size);
extern void  func_021BE760(void *expObj, void *unitDesc, int b);
extern VecFx32 *func_021BE480(void *expObj, unsigned unit, int model);
extern void func_021BE4A4(void *expObj, int unit, int model, int visible);
extern void *func_021BE674(void *expObj, int unit, unsigned int model, int animeIdx);
extern void func_021BE6B8(unsigned char *anime, int loop);
extern void func_021BE6B0(unsigned char *anime, int paused);
extern void *func_021897BC(void *fieldMap, int id);
extern void func_021897A0(void *fieldMap, int id);
extern void func_021BE418(u8 *expObj, u16 unit);
extern void func_021BE580(void *expObj);
extern void *func_0201210C(void *gameSystem);
extern void  func_021BE700(void *expObj, int unit, int model, int animeIdx, int enabled);
extern struct GameEvent *func_020122C0(void *owner, void *a, void *eventFunc, u32 size);
extern void *func_020124E4(struct Obj *p);
extern void *func_02188C58(void *fieldMap);
extern u32 func_0218EC5C(u8 *camera);
extern void func_0218EC54(u8 *camera);
extern void func_0218EC30(u8 *camera, int target);
extern void func_020061E4(u32 seId);
extern int func_021BE6BC(void *anime);
extern void *func_02188CB4(void *fieldMap);
extern void func_021A3038(unsigned char *player, VecFx32 *out);
extern void func_021A3044(u8 *player, VecFx32 *pos);
extern void func_021BE6CC(void *expObj, int unit, int model, int animeIdx, int frame);
void func_021F36C0(void *fieldMap);
void func_021F3740(u8 *fieldMap);
void func_021F3764(void *fieldMap);
void func_021F3770(void *gameSystem, int isDescending);
int func_021F37F0(void *event, int *seq);
int func_021F390C(Gimmick44Work *work);
void func_021F392C(void *expObj);
extern int d_021F39E8;
extern VecFx32 d_021F3A1C;


void func_021F36C0(void *fieldMap)
{
    void *expObj;
    VecFx32 *modelPos;
    void *anime;
    int animeIdx;

    expObj = func_02188D2C(fieldMap);
    func_02189764(fieldMap, 1, func_02188C84(fieldMap), sizeof(Gimmick44Work));
    func_021BE760(expObj, &d_021F39E8, 0);
    modelPos = func_021BE480(expObj, 0, 0);
    *modelPos = d_021F3A1C;
    func_021BE4A4(expObj, 0, 0, 1);
    for (animeIdx = 0; animeIdx < 2; animeIdx++) {
        anime = func_021BE674(expObj, 0, 0, (u16)animeIdx);
        func_021BE6B8(anime, 0);
        func_021BE6B0(anime, 1);
    }
    func_021F392C(expObj);
}

void func_021F3740(u8 *fieldMap)
{
    void *expObj = func_02188D2C(fieldMap);
    func_021897BC(fieldMap, 1);
    func_021897A0(fieldMap, 1);
    func_021BE418(expObj, 0);
}


void func_021F3764(void *fieldMap)
{
    func_021BE580(func_02188D2C(fieldMap));
}


void func_021F3770(void *gameSystem, int isDescending)
{
    void *fieldMap;
    Gimmick44Work *work;
    void *expObj;
    int step;

    fieldMap = func_0201210C(gameSystem);
    work = func_021897BC(fieldMap, 1);
    work->isDescending = isDescending;
    if (isDescending) {
        work->curY = 0;
        work->goalY = -0x50000;
    } else {
        work->curY = -0x50000;
        work->goalY = 0;
        expObj = func_02188D2C(fieldMap);
        func_021BE700(expObj, 0, 0, 0, 1);
        func_021BE700(expObj, 0, 0, 1, 0);
    }
    step = work->goalY - work->curY;
    if (step < 0) {
        step = -0x2000;
    } else {
        step = 0x2000;
    }
    work->stepY = step;
    func_020122C0(gameSystem, 0, func_021F37F0, 0);
}


/*
 * Once filed EXACT* because the extent ran into the unlabelled leaf func_021F390C
 * (filed as ov044_func_021F390C.c).
 */
int func_021F37F0(void *event, int *seq)
{
    void *fieldMap;
    void *expObj;
    Gimmick44Work *work;
    u8 *camera;
    void *player;
    VecFx32 pos;

    fieldMap = func_0201210C(func_020124E4(event));
    expObj = func_02188D2C(fieldMap);
    work = func_021897BC(fieldMap, 1);
    camera = func_02188C58(fieldMap);
    switch (*seq) {
    case 0:
        if (work->isDescending != 0) {
            work->savedCameraTarget = func_0218EC5C(camera);
            func_0218EC54(camera);
        }
        func_020061E4(work->isDescending == 0 ? 0x6da : 0x6ca);
        (*seq)++;
        break;
    case 1:
        work->curY += work->stepY;
        if (func_021F390C(work)) {
            work->curY = work->goalY;
            if (work->isDescending == 0) {
                func_020061E4(0x6cb);
            }
            (*seq)++;
        }
        func_021BE480(expObj, 0, 0)->y = work->curY;
        player = func_02188CB4(fieldMap);
        func_021A3038(player, &pos);
        pos.y = work->curY;
        func_021A3044(player, &pos);
        break;
    case 2:
        if (work->isDescending != 0) {
            return 1;
        }
        if (work->savedCameraTarget != 0) {
            func_0218EC30(camera, work->savedCameraTarget);
        }
        func_021BE6B0(func_021BE674(expObj, 0, 0, 0), 0);
        (*seq)++;
        break;
    case 3:
        if (func_021BE6BC(func_021BE674(expObj, 0, 0, 0))) {
            func_021F392C(expObj);
            return 1;
        }
        break;
    }
    return 0;
}

/*
 * Unlabelled leaf called only from func_021F37F0.
 */
int func_021F390C(Gimmick44Work *work)
{
    if (work->stepY < 0) {
        if (work->goalY >= work->curY) {
            return 1;
        }
    } else {
        if (work->goalY <= work->curY) {
            return 1;
        }
    }
    return 0;
}


void func_021F392C(void *expObj)
{
    void *anime;

    func_021BE700(expObj, 0, 0, 1, 1);
    func_021BE700(expObj, 0, 0, 0, 0);
    func_021BE6CC(expObj, 0, 0, 1, 0);
    anime = func_021BE674(expObj, 0, 0, 1);
    func_021BE6B0(anime, 1);
}
