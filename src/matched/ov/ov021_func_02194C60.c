/*
 * function: func_02194C60
 * address:  0x02194C60
 * packet:   pkt_ov021_02194C60
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02195E70  0x02195E70  thumb  ov021
 *   func_0201CCE4  0x0201CCE4  thumb
 *   func_02194B3C  0x02194B3C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02195E70(u8 *p, u8 *e);
extern u32 func_0201CCE4(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32);
extern void func_02194B3C(u8 *p, u8 *e);

void func_02194C60(u8 *p, u8 *e)
{
    u32 t;

    switch (*(u16 *)e) {
    case 2:
        *(u16 *)(e + 0x5E) = 0;
        *(u16 *)e = 3;
    case 3:
        *(u16 *)e = 4;
        t = *(u32 *)(e + 0x60);
        func_02195E70(p, e);
        *(u32 *)(e + 8) = func_0201CCE4(*(u32 *)(e + 0xC), e[0x5C], e[0x5D], *(u32 *)(e + 0x14),
                                        *(u32 *)(p + 8), t, *(u32 *)(p + 0xC98), 0, *(u16 *)p, 15);
        return;
    case 5:
        *(u16 *)e = 6;
        return;
    case 6:
        func_02194B3C(p, e);
        return;
    }
}
