/*
 * function: func_0219CBE0
 * address:  0x0219CBE0
 * packet:   pkt_ov021_0219CBE0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D4F8  0x0216D4F8  thumb  ov010
 *   func_0216D4F0  0x0216D4F0  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   d_021DDD70     0x021DDD70  data ov021 a4

 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_0216D4F8(u8 *p);
extern u16 func_0216D4F0(void *p);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern unsigned char d_021DDD70[];

void func_0219CBE0(u8 *o)
{
    u32 h = func_0216D4F8((u8 *)(*(u32 *)(o + 0x10)));
    u8 *p = func_02030734(h, 0x18, 1, (const char *)d_021DDD70, 1491);
    u16 *e;
    int i;
    *(u16 *)(p + 4) = *(u16 *)(o + 2);
    *(u16 *)(p + 8) = func_0216D4F0((void *)(*(u32 *)(o + 0x10)));
    *(u16 *)(p + 6) = 1;
    e = (u16 *)func_02030734(h, 0xc * *(u16 *)(p + 4), 1, (const char *)d_021DDD70, 1498);
    *(u16 **)(p + 0xc) = e;
    i = 0;
    if (i < *(u16 *)(p + 4)) {
        for (; i < *(u16 *)(p + 4); i++, e += 6)
            *e = 0xFFFF;
    }
    *(u32 *)(p + 0x10) = (u32)func_02030734(h, 0x14 * *(u16 *)(p + 6), 1, (const char *)d_021DDD70, 1511);
    *(u32 *)(p + 0x14) = (u32)func_02030734(h, 0x28 * *(u16 *)(p + 8), 1, (const char *)d_021DDD70, 1513);
    *(u32 *)p = 1;
    *(u8 **)(o + 0x1c) = p;
}
