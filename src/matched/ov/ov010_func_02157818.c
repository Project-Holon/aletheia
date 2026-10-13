/*
 * function: DELIVERY_BEACON_DecodePieces
 * address:  0x02157818
 * packet:   pkt_ov010_02157818
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203F328  0x0203F328  arm
 *   func_02082D44  0x02082D44  arm
 */
#include "../include/Obj04914.h"
#include "../include/Obj18737.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_0203F328(u16 *p, u32 size, u32 seed);
extern void func_02082D44(void *, void *, u32);

void DELIVERY_BEACON_DecodePieces(u8 *p)
{
    u8 *base;
    int i;

    base = p;
    i = 0;
    base = p + 0x7C;

    for (; i < 0x12; i++) {
        u32 off = i * 0x54;
        u8 *e = base + i * 100;
        u32 n;

        func_0203F328((u16 *)(e + 8), 0x54, ((struct Obj18737 *)e)->f4);
        n = (u16)off;
        if (((struct Obj04914 *)p)->f8 > (int)(n + 0x54))
            func_02082D44(e + 8, (u8 *)((struct Obj04914 *)p)->fC + off, 0x54);
        else
            func_02082D44(e + 8, (u8 *)((struct Obj04914 *)p)->fC + off, ((struct Obj04914 *)p)->f8 - n);
    }
}
