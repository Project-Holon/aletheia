/*
 * function: func_02194B84
 * address:  0x02194B84
 * packet:   pkt_ov021_02194B84
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02195338  0x02195338  thumb  ov021
 *   func_02195E80  0x02195E80  thumb  ov021
 *   func_0201CCE4  0x0201CCE4  thumb
 *   func_02194B3C  0x02194B3C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_02195338(u8 *p, u8 *e);
extern void func_02195E80(u8 *p, u8 *e);
extern u32 func_0201CCE4(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32);
extern void func_02194B3C(u8 *p, u8 *e);

void func_02194B84(u8 *p, u8 *e)
{
    u32 t;

    switch (*(u16 *)e) {
    case 0:
    case 1:
        break;
    case 2:
        func_02195338(p, e);
        *(u16 *)(e + 0x5E) = 0;
        *(u16 *)e = 3;
        return;
    case 3:
        func_02195338(p, e);
        if (*(u16 *)(e + 0x5E) < 8) {
            *(u16 *)(e + 0x5E) += 1;
            return;
        }
        *(u16 *)e = 4;
        t = *(u32 *)(e + 0x60);
        func_02195E80(p, e);
        *(u32 *)(e + 8) = func_0201CCE4(*(u32 *)(e + 0xC), e[0x5C], e[0x5D], *(u32 *)(e + 0x14),
                                        *(u32 *)(p + 8), t, *(u32 *)(p + 0xC98), 0, *(u16 *)p, 15);
        return;
    case 4:
        if (func_02195338(p, e) == 1) {
            func_02195E80(p, e);
        }
        return;
    case 5:
        if (*(u16 *)(e + 0x5E) != 0) {
            *(u16 *)(e + 0x5E) -= 1;
            return;
        }
        *(u16 *)e = 6;
        return;
    case 6:
        func_02194B3C(p, e);
        return;
    }
}
