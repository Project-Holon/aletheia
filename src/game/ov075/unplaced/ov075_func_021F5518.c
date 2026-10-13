/*
 * function: func_021F5518
 * address:  0x021F5518
 * packet:   pkt_ov075_021F5518
 * region:   ov075
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Four-state proc; its states 1-3 are func_021F536C's states 4-6, and the
 * shape follows ov073's func_021F53C8.
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_021F54A0  0x021F54A0  thumb  ov075
 *   func_0204047C  0x0204047C  arm
 *   func_021899F0  0x021899F0  thumb  ov021
 *   func_02080C44  0x02080C44  arm
 *   func_02080B98  0x02080B98  arm
 *   func_02080294  0x02080294  arm
 *   func_021F54E0  0x021F54E0  thumb  ov075
 *   func_02040588  0x02040588  arm
 *   func_021899F8  0x021899F8  thumb  ov021
 *   func_02189A08  0x02189A08  thumb  ov021
 *   func_021CF560  0x021CF560  thumb  ov021
 *   func_02012374  0x02012374  thumb
 */
#include "../../ov021/fieldmap_types.h"
#include "../unit_021F5260_types.h"

extern struct GameSystem *func_020124E4(struct GameEvent *event);
extern struct FieldMap *func_0201210C(const struct GameSystem *gameSystem);
extern void func_021F54A0(EncEffScreenTexWork *work);
extern void func_0204047C(int idx, u16 val);
extern int func_021899F0(struct FieldMap *fieldMap);
extern void func_021899F8(struct FieldMap *fieldMap, int drawMode);
extern u16 func_02080C44(void);
extern void func_02080B98(void);
extern void func_02080294(u32 bank);
extern void func_02040588(unsigned char which, unsigned char enable);
extern struct EncEff *func_02189A08(struct FieldMap *fieldMap);
extern void *func_021CF560(struct EncEff *eff);
extern void func_02012374(struct GameEvent *parent, struct GameEvent *child);
extern u32 func_021F54E0(void);

int func_021F5518(struct GameEvent *event, int *state, EncEffScreenTexWork *work)
{
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    u32 texBanks;
    struct GameEvent *child;

    gameSystem = func_020124E4(event);
    fieldMap = func_0201210C(gameSystem);
    switch (*state) {
    case 0:
        func_021F54A0(work);
        *state = *state + 1;
        break;
    case 1:
        if (work->captureDone != 0) {
            func_0204047C(0, 0);
            func_0204047C(2, 3);
            work->savedDrawMode = func_021899F0(fieldMap);
            texBanks = func_02080C44();
            work->texBanks = texBanks;
            work->addedTexBank = 0;
            if ((texBanks & 8) == 0) {
                work->texBanks = texBanks | 8;
                work->addedTexBank = 1;
            }
            func_02080B98();
            func_02080294(work->texBanks);
            work->texParam = func_021F54E0();
            *state = *state + 1;
        }
        break;
    case 2:
        func_02040588(2, 1);
        func_02040588(0, 1);
        func_021899F8(fieldMap, 2);
        child = work->start(gameSystem);
        work->effectWork = func_021CF560(func_02189A08(fieldMap));
        func_02012374(event, child);
        *state = *state + 1;
        break;
    case 3:
        if (work->addedTexBank == 1) {
            work->texBanks &= ~8;
            func_02080294(work->texBanks);
        }
        func_021899F8(fieldMap, work->savedDrawMode);
        return 1;
    }
    return 0;
}
