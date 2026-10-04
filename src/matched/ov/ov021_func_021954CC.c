/*
 * function: func_021954CC
 * address:  0x021954CC
 * packet:   pkt_ov021_021954CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020414EC  0x020414EC  arm
 *   func_02049B40  0x02049B40  arm
 *   func_02049624  0x02049624  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04218.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_020414EC(u32 a);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049624(void *a0, void *a1, void *a2, void *a3, u32 a4, u32 a5, u16 a6);

void func_021954CC(u32 p, u8 *e)
{
    u32 k;

    func_020414EC(((struct Obj04218 *)e)->f10 & 0xFF);
    k = 0;
    switch (((struct Obj04218 *)e)->f10) {
    case 0:
    case 1:
    case 2:
    case 3:
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        k = 4;
        break;
    }
    func_02049B40(5, 0, k, e[0x14] << 5, 0x20, ((struct Obj04218 *)e)->f0);
    func_02049624((void *)5, (void *)5, (void *)(((struct Obj04218 *)e)->f10), (void *)(((struct Obj04218 *)e)->fC), 0, 0, ((struct Obj04218 *)e)->f0);
}
