/*
 * function: func_021F3A68
 * address:  0x021F3A68
 * packet:   pkt_ov045_021F3A68
 * region:   ov045
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Levers: func_021F39A8's result held in a u8 local curState (truncated in
 * place, lsls r0 / lsrs r3, where passing the call inline copies it to r3
 * first); newState = 1 written after work's assignment (before it, it takes
 * r0 and lands after the copy of expObj). The extent past 0x021F3B36 is rodata.
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_021F39A8  0x021F39A8  thumb  ov045
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE6BC  0x021BE6BC  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   GFL_USE_StopAllSe  0x02006210  thumb
 *   func_021F3938  0x021F3938  thumb  ov045
 */
#include "../unit_021F36C0_types.h"

struct FieldMap;
struct GameSystem;
struct GameData;
struct FieldSave;
struct FldExpObj;
struct FldExpAnime;
struct GameEvent;

extern struct GameSystem *func_020124E4(struct GameEvent *event);
extern struct FieldMap *func_0201210C(const struct GameSystem *gameSystem);
extern struct FldExpObj *func_02188D2C(struct FieldMap *fieldMap);
extern Gimmick45Work *func_021897BC(struct FieldMap *fieldMap, int workId);
extern struct GameSystem *func_02188C80(struct FieldMap *fieldMap);
extern struct GameData *func_020120F4(const struct GameSystem *gameSystem);
extern struct FieldSave *func_02012EC4(struct GameData *gameData);
extern Gimmick45Save *func_0200B3A4(struct FieldSave *fieldSave, u32 blockId);
extern int func_021F39A8(Gimmick45Save *save, int switchIndex);
extern struct FldExpAnime *func_021BE674(struct FldExpObj *expObj, int unitIndex, unsigned int modelIndex, int animIndex);
extern void func_021BE6B0(struct FldExpAnime *anime, int paused);
extern int func_021BE6BC(struct FldExpAnime *anime);
extern void func_020061E4(u32 se);
extern void GFL_USE_StopAllSe(void);
extern void func_021F3938(struct FldExpObj *expObj, int switchOn, int switchIndex, int usePrimaryModel);

int func_021F3A68(struct GameEvent *event, int *state)
{
    int newState;
    struct FieldMap *fieldMap;
    struct FldExpObj *expObj;
    Gimmick45Work *work;
    Gimmick45Save *save;
    int switchIdx;
    u8 curState;

    fieldMap = func_0201210C(func_020124E4(event));
    expObj = func_02188D2C(fieldMap);
    work = func_021897BC(fieldMap, 1);
    newState = 1;
    save = func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(fieldMap))), GIMMICK45_SAVE_BLOCK_ID);
    switch (*state) {
    case 0:
        switchIdx = work->switchIndex;
        curState = func_021F39A8(save, switchIdx);
        func_021BE6B0(func_021BE674(expObj, 0, (u8)switchIdx, (u8)curState), 0);
        func_020061E4(GIMMICK45_SE_SWITCH_PRESS);
        (*state)++;
        break;
    case 1:
        switchIdx = work->switchIndex;
        curState = func_021F39A8(save, switchIdx);
        if (func_021BE6BC(func_021BE674(expObj, 0, (u8)switchIdx, (u8)curState))) {
            GFL_USE_StopAllSe();
            func_020061E4(GIMMICK45_SE_SWITCH_DONE);
            if (save->switchOn[work->switchIndex] != 0)
                newState = 0;
            func_021F3938(expObj, newState, work->switchIndex, 1);
            save->switchOn[work->switchIndex] = save->switchOn[work->switchIndex] ? 0 : 1;
            return 1;
        }
        break;
    }
    return 0;
}
