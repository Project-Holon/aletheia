/*
 * function: func_021F44C0
 * address:  0x021F44C0
 * packet:   pkt_ov038_021F44C0
 * region:   ov038
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note: The handed extent includes rodata after 0x021F45E8.
 *         0200B3A4 receives the visibly loaded second argument 6.
 *         Enum id plus u16 extern arguments preserves the observed #16
 *         truncations at 021F4594/459A and 021F45C4/45CA; u16 local alone
 *         folds them away. Matched callee's wide id receives the same bits.
 * symbols:
 *   func_020124E4 0x020124E4 thumb
 *   func_0201210C 0x0201210C thumb
 *   func_02188D2C 0x02188D2C thumb ov021
 *   func_021897BC 0x021897BC thumb ov021
 *   func_02188C80 0x02188C80 thumb ov021
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EC4 0x02012EC4 thumb
 *   func_0200B3A4 0x0200B3A4 thumb
 *   func_021BE700 0x021BE700 thumb ov021
 *   func_021BE674 0x021BE674 thumb ov021
 *   func_021BE6B0 0x021BE6B0 thumb ov021
 *   func_021BE6CC 0x021BE6CC thumb ov021
 *   func_021BE480 0x021BE480 thumb ov021
 *   func_021BE6BC 0x021BE6BC thumb ov021
 *   func_02158780 0x02158780 thumb ov010
 *   func_021587B0 0x021587B0 thumb ov010
 *   d_021F465C 0x021F465C data a4
 */
#include "../unit_021F36C0_types.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
/* The enum type keeps the narrowing of the script event ids, see the note above. */
typedef enum { SCRIPT_EVENT_ID_ZERO } ScriptEventId;
struct GameSystem;
struct GameData;
struct GimmickWork;
struct GameEvent;
extern void *func_020124E4(struct GameEvent *event);
extern void *func_0201210C(const struct GameSystem *gameSystem);
extern int func_02188D2C(int *fieldMap);
extern struct Gimmick38Runtime *func_021897BC(char *fieldMap, int idx);
extern void *func_02188C80(void *fieldMap);
extern void *func_020120F4(const struct GameSystem *gameSystem);
extern struct GimmickWork *func_02012EC4(struct GameData *gameData);
extern void *func_0200B3A4(struct GimmickWork *gimmickSave, u32 gimmickId);
extern void func_021BE700(void *expObj, int unitIdx, int modelIdx, int animeIdx, int enable);
extern void *func_021BE674(char *expObj, int unitIdx, unsigned int modelIdx, u16 animeIdx);
extern void func_021BE6B0(u8 *anime, int paused);
extern void func_021BE6CC(int expObj, int unitIdx, int modelIdx, u16 animeIdx, int frame);
extern VecFx32 *func_021BE480(void *expObj, int unitIdx, u16 modelIdx);
extern int func_021BE6BC(int *anime);
extern int func_02158780(void *gameSystem, u16 scriptId, int arg1, int arg2, u16 flags);
extern int func_021587B0(int gameSystem, int scriptId, int arg1, int flags);
extern const VecFx32 d_021F465C[];

/*
 * Event: shows the effect model at the position of the variant, calls the
 * first script event, waits for the effect animation and calls the second.
 */
int func_021F44C0(void *event, int *state)
{
    void *fieldMap;
    void *expObj;
    Gimmick38Runtime *runtime;
    u8 *anime;
    int i;
    ScriptEventId scriptId;

    fieldMap = (void *)func_0201210C(func_020124E4(event));
    expObj = (void *)func_02188D2C(fieldMap);
    runtime = func_021897BC(fieldMap, 1);
    func_0200B3A4(func_02012EC4((struct GameData *)func_020120F4((void *)func_02188C80(fieldMap))), 6);
    switch (*state) {
    case 0:
        for (i = 0; i < 2; i++) {
            func_021BE700(expObj, 0, 0x20, (u16)i, 1);
            func_021BE6B0(func_021BE674(expObj, 0, 0x20, i), 0);
            func_021BE6CC((int)expObj, 0, 0x20, i, 0);
        }
        *func_021BE480(expObj, 0, 0x20) = d_021F465C[runtime->scriptVariant];
        *state = *state + 1;
        break;
    case 1:
        scriptId = 4;
        if (runtime->scriptVariant == 0)
            scriptId = 3;
        func_02158780(event, (u16)scriptId, 0, 0, 0x8015);
        *state = *state + 1;
        break;
    case 2:
        if (func_021BE6BC(func_021BE674(expObj, 0, 0x20, 0))) {
            scriptId = 6;
            if (runtime->scriptVariant == 0)
                scriptId = 5;
            func_021587B0((int)event, (u16)scriptId, 0, 0x8015);
            *state = *state + 1;
        }
        break;
    case 3:
        return 1;
    }
    return 0;
}
