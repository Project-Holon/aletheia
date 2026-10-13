/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, func_021F37C4, func_021F37DC, func_021F385C, func_021F38BC
 * address:  0x021F36C0
 * region:   ov065
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F3918     0x021F3918  data  a4
 *   d_021F38F8     0x021F38F8  data  a4
 *   d_021F3970     0x021F3970  data  a4
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02012984  0x02012984  thumb
 *   func_020113D8  0x020113D8  thumb
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE4A4  0x021BE4A4  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE418 0x021BE418 thumb ov021
 *   func_021897A0 0x021897A0 thumb ov021
 *   func_021BE580  0x021BE580  thumb  ov021
 *   func_021BE6E8  0x021BE6E8  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_021BE6BC  0x021BE6BC  thumb  ov021
 *   func_020122C0 0x020122C0 thumb
 *   func_021F38D0 0x021F38D0 thumb ov065
 */
#include "unit_021F36C0_types.h"

struct GameData;
struct FieldSave;

extern void *func_02188C80(void *fieldMap);
extern void *func_020120F4(void *gameSystem);
extern struct FieldSave *func_02012EC4(void *gameData);
extern Gimmick65Save *func_0200B3A4(struct FieldSave *fieldSave, u32 blockId);
extern void *func_02188D2C(void *fieldMap);
extern u16 func_02188C84(u8 *fieldMap);
extern void *func_02189764(unsigned char *fieldMap, int id, int a, int size);
extern Gimmick65Work *func_021897BC(void *fieldMap, int id);
extern u8 func_02012984(void *gameData);
extern u32 func_020113D8(u32 season);
extern void func_021BE760(void *expObj, void *unitDesc, int b);
extern VecFx32 *func_021BE480(void *expObj, int unit, u16 model);
extern void func_021BE4A4(void *expObj, int unit, int model, int visible);
extern void func_021BE4B4(void *expObj, int unit, int model, int hidden);
extern void *func_021BE674(void *expObj, int unit, unsigned int model, int animeIdx);
extern void func_021BE6B8(unsigned char *anime, int loop);
extern void func_021BE6B0(unsigned char *anime, int paused);
extern void func_021BE700(void *expObj, int unit, u16 model, u16 animeIdx, int enabled);
extern void func_021BE418(unsigned char *expObj, unsigned short unit);
extern void func_021897A0(unsigned char *fieldMap, int id);
extern void func_021BE580(int expObj);
extern int func_021BE6E8(int expObj, int unit, int model, int animeIdx);
extern void func_020061E4(u32 seId);
extern int func_021BE6BC(void *anime);
extern void *func_020122C0(void *owner, void *a, void *eventFunc, u32 size);
extern int func_021F38D0(void *event);
void func_021F36C0(void *fieldMap);
void func_021F37C4(unsigned char *fieldMap);
void func_021F37DC(int fieldMap);
void func_021F385C(int fieldMap);
void *func_021F38BC(void *gameSystem);
extern char d_021F3918[];
extern char d_021F38F8[];
extern VecFx32 d_021F3970;


void func_021F36C0(void *fieldMap)
{
    void *gameData;
    Gimmick65Save *save;
    Gimmick65Work *work;
    int i;
    void *anime;
    void *expObj;

    gameData = func_020120F4(func_02188C80(fieldMap));
    save = func_0200B3A4(func_02012EC4(gameData), GIMMICK65_SAVE_BLOCK);
    expObj = func_02188D2C(fieldMap);
    func_02189764(fieldMap, 1, func_02188C84(fieldMap), sizeof(Gimmick65Work));
    work = func_021897BC(fieldMap, 1);
    work->isPlaying = 0;
    if (func_020113D8(func_02012984(gameData)) - GIMMICK65_FIRST_NIGHT_TIME_ZONE <= 1) {
        func_021BE760(expObj, d_021F3918, 0);
        work->isNight = 1;
    } else {
        func_021BE760(expObj, d_021F38F8, 0);
        work->isNight = 0;
    }
    *func_021BE480(expObj, 0, 0) = d_021F3970;
    func_021BE4A4(expObj, 0, 0, 1);
    func_021BE4B4(expObj, 0, 0, save->isEffectPending == 0);
    for (i = 0; i < GIMMICK65_ANIME_COUNT; i++) {
        anime = func_021BE674(expObj, 0, (u16)0, (u16)i);
        func_021BE6B8(anime, 0);
        func_021BE6B0(anime, 1);
        func_021BE700(expObj, 0, 0, i, save->isEffectPending != 0);
    }
}


void func_021F37C4(unsigned char *fieldMap)
{
    func_021BE418(func_02188D2C(fieldMap), 0);
    func_021897A0(fieldMap, 1);
}


void func_021F37DC(int fieldMap)
{
    int expObj;
    Gimmick65Work *work;

    expObj = (int)func_02188D2C((void *)fieldMap);
    work = func_021897BC((void *)fieldMap, 1);
    if (work->isPlaying != 0) {
        func_021BE580(expObj);
        if (work->isNight == 0) {
            if (func_021BE6E8(expObj, 0, 0, 0) == GIMMICK65_PEAK_FRAME)
                func_020061E4(GIMMICK65_SE_DAY_PEAK);
        }
        if (func_021BE6BC(func_021BE674((void *)expObj, 0, 0, 0)) != 0) {
            func_021BE4B4((void *)expObj, 0, 0, 1);
            work->isPlaying = 0;
            func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80((void *)fieldMap))), GIMMICK65_SAVE_BLOCK)->isEffectPending = 0;
        }
    }
}


void func_021F385C(int fieldMap)
{
    int i;
    int expObj;
    Gimmick65Work *work;

    expObj = (int)func_02188D2C((void *)fieldMap);
    work = func_021897BC((void *)fieldMap, 1);
    work->isPlaying = 1;
    func_021BE4B4((void *)expObj, 0, 0, 0);
    for (i = 0; i < GIMMICK65_ANIME_COUNT; i++)
        func_021BE6B0(func_021BE674((void *)expObj, 0, 0, (unsigned short)i), 0);
    if (work->isNight != 0)
        func_020061E4(GIMMICK65_SE_START_NIGHT);
    else
        func_020061E4(GIMMICK65_SE_START_DAY);
}


void *func_021F38BC(void *gameSystem)
{
    return func_020122C0(gameSystem, 0, (void *)func_021F38D0, 0);
}
