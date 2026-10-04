/*
 * function: func_021D4988
 * address:  0x021D4988
 * packet:   pkt_ov120_021D4988
 * region:   ov120
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocker resolved: the call to func_0203C3EC (site +0050) was the only
 *          unresolved relocation.  It is an unlabelled ARM leaf in the ARM9
 *          image; it was matched in arm9 (src/matched/func_0203C3EC.c, shard
 *          pkt_0203C3EC) so `attest_matched` now resolves the BL field.  All
 *          17 relocations and all 152 bytes agree.
 * symbols:
 *   func_021D7C10  0x021D7C10  thumb  ov120
 *   func_021D8638  0x021D8638  thumb  ov120
 *   func_021D4244  0x021D4244  thumb  ov120
 *   func_021D7B38  0x021D7B38  thumb  ov120
 *   func_021D7A74  0x021D7A74  thumb  ov120
 *   func_021D8648  0x021D8648  thumb  ov120
 *   func_020362DC  0x020362DC  arm
 *   func_0203CD98  0x0203CD98  arm
 *   func_0203C554  0x0203C554  arm
 *   func_020355D8  0x020355D8  arm
 *   func_0203C3EC  0x0203C3EC  arm
 *   func_0203D7B0  0x0203D7B0  arm
 *   func_0203D7BC  0x0203D7BC  arm
 *   func_020061E4  0x020061E4  thumb
 */
#include "../include/Obj05343.h"

typedef unsigned int u32;

extern int func_021D7C10(char *p);
extern u32 func_020362DC(void);
extern void func_021D8638(int);
extern int func_0203CD98(void);
typedef unsigned char  u8;
extern void func_0203C554(u32 a);
extern void func_020355D8(u8 v);
extern void func_020061E4(u32 a);
extern void func_021D4244(int, int, int);
extern int func_0203C3EC(void);
extern void func_0203D7B0(int);
extern void func_0203D7BC(int);
extern void func_021D7B38(char *p);
extern void func_021D7A74(int, int);
extern void func_021D8648(int);

void func_021D4988(int a)
{
    func_021D7C10((char *)(((struct Obj05343 *)a)->f40));
    if (func_020362DC() == 2) {
        func_021D8638(((struct Obj05343 *)a)->f40);
        if (func_0203CD98() != 0)
            func_0203C554(1);
        func_020355D8(0);
        func_020061E4(0x551);
        func_021D4244(a, 0x021D4FF5, 0x360);
    }
    if (func_0203CD98() == 0) {
        if (func_020362DC() != 1)
            return;
    } else {
        if (func_0203C3EC() != 1)
            return;
        func_0203D7B0(1);
        func_0203D7BC(1);
    }
    func_021D7B38((char *)(((struct Obj05343 *)a)->f40));
    func_021D7A74(((struct Obj05343 *)a)->f40, 0x10);
    ((struct Obj05343 *)a)->f14 = 0xb4;
    func_021D8648(((struct Obj05343 *)a)->f40);
    func_021D4244(a, 0x021D4931, 0x377);
}
