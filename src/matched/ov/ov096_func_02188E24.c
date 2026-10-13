/*
 * function: func_02188E24
 * address:  0x02188E24
 * packet:   pkt_ov096_02188E24
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * Lever: x is a u16 local from the evidenced u16 callee return. Its word
 * spill reload stays after the outgoing fifth-argument store. All 5
 * relocation sites resolve; trailing two-byte padding is EXACT*.
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   func_0218A0F4  0x0218A0F4  thumb  ov096
 *   BTL_SERVER_FLOW_CalcPokeSpeedWrapper  0x021C81C8  thumb  ov093
 */
#include "../include/Obj06341.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern int func_0218A0F4(u8 *, int, int, int, int);
extern u16 BTL_SERVER_FLOW_CalcPokeSpeedWrapper(u8 *, u8 *, int);

int func_02188E24(struct Cursor *a, u8 *b)
{
    int k;
    int m;
    u16 x;
    int y;

    k = VM_GetU32(a);
    m = VM_GetU32(a);
    x = BTL_SERVER_FLOW_CalcPokeSpeedWrapper(*(u8 * *)&((struct Obj06341 *)b)->fB4, *(u8 * *)&((struct Obj06341 *)b)->fBC, 1);
    y = BTL_SERVER_FLOW_CalcPokeSpeedWrapper(*(u8 * *)&((struct Obj06341 *)b)->fB4, *(u8 * *)&((struct Obj06341 *)b)->fC0, 1);
    switch (k) {
    case 0:
        k = 1;
        break;
    case 1:
        k = 0;
        break;
    case 2:
        k = 2;
        break;
    }
    func_0218A0F4((u8 *)a, k, x, y, m);
    return ((struct Obj06341 *)b)->fC4;
}
