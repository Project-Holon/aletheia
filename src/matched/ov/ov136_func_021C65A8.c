/*
 * function: func_021C65A8
 * address:  0x021C65A8
 * packet:   pkt_ov136_021C65A8
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020434DC   0x020434DC  arm
 *   func_02043598   0x02043598  arm
 *   func_0204A48C   0x0204A48C  arm
 *   func_0204B100   0x0204B100  arm
 *   func_0204B270   0x0204B270  arm
 *   d_021C78E0 0x021C78E0 data a4
 *   d_021C7BA0 0x021C7BA0 data a4
 */
#include "../include/Obj23593.h"

typedef unsigned char u8;
typedef unsigned int u32;
extern const u8 d_021C7BA0[];
extern const u8 d_021C78E0[];
struct Cfg;
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
struct Bank;
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_020434DC(u32, u32);
extern void func_02043598(u32, u32);
void func_021C65A8(u8 *p)
{
    void *bank;

    func_0204A48C((const struct Cfg *)d_021C7BA0, (u32)d_021C78E0, 0x66);
    bank = func_0204B100(8, 0, 0x66);
    ((struct Obj23593 *)p)->f1EC = bank;
    func_0204B270(bank);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}
