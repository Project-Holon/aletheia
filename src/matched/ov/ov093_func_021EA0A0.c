/*
 * function: func_021EA0A0
 * address:  0x021EA0A0
 * packet:   pkt_ov093_021EA0A0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B8E70  0x021B8E70  thumb  ov093
 *   func_021ED118  0x021ED118  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 func_021B8E70(u8 *p, u32 k);
extern void func_021ED118(u32 p, u32 a1, u32 a2, u32 a3, u32 a5, u32 a6, u8 a7);

void func_021EA0A0(u32 *p, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u8 s7)
{
    u32 r7;
    u32 r2;

    r7 = func_021B8E70((u8 *)p[0], a1);
    if (a2 != 6) {
        r2 = func_021B8E70((u8 *)p[0], a2);
    } else {
        r2 = 0xff;
    }
    func_021ED118(p[0x5f], r7, r2, a3, s5, s6, s7);
}
