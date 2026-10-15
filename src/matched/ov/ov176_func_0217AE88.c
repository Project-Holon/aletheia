/*
 * function: BATTLE_CHAMPIONSHIP_FLOW_Delete
 * address:  0x0217AE88
 * packet:   pkt_ov176_0217AE88
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_CORE_IsSlotKind1Index15  0x021E8A78  thumb  ov093
 *   BATTLE_CHAMPIONSHIP_FLOW_DeleteText  0x0217AF9C  thumb  ov176
 *   BATTLE_CHAMPIONSHIP_FLOW_DeleteView  0x0217AF44  thumb  ov176
 *   BATTLE_CHAMPIONSHIP_FLOW_DeleteGraphic  0x0217AF04  thumb  ov176
 *   func_02034A5C  0x02034A5C  arm
 *   func_020315D4  0x020315D4  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 *   ov177_id       0x000000B1  data
 *   ov67_id        0x00000043  data
 */
#include "../include/Obj03869.h"

extern void BTLV_CORE_IsSlotKind1Index15(int);
extern void BATTLE_CHAMPIONSHIP_FLOW_DeleteText(int *);
extern void BATTLE_CHAMPIONSHIP_FLOW_DeleteView(int *);
extern void BATTLE_CHAMPIONSHIP_FLOW_DeleteGraphic(int *);
extern void func_02034A5C(int);
struct Proc;
extern void func_020315D4(struct Proc *);
extern void GFL_HEAP_DeleteChecked(unsigned int);
extern char ov177_id[];
extern char ov67_id[];

int BATTLE_CHAMPIONSHIP_FLOW_Delete(int a, int b, int c, int *p)
{
    BTLV_CORE_IsSlotKind1Index15(((struct Obj03869 *)p)->f4);
    BATTLE_CHAMPIONSHIP_FLOW_DeleteText(p);
    BATTLE_CHAMPIONSHIP_FLOW_DeleteView(p);
    BATTLE_CHAMPIONSHIP_FLOW_DeleteGraphic(p);
    func_02034A5C((int)ov177_id);
    func_02034A5C((int)ov67_id);
    func_020315D4((struct Proc *)a);
    GFL_HEAP_DeleteChecked(0x4e);
    return 1;
}
