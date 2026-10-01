/*
 * function: func_02192F74
 * address:  0x02192F74
 * packet:   pkt_ov021_02192F74
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020403F4  0x020403F4  arm  arm9
 *   func_02192EE0  0x02192EE0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct W {
    u16 f00;
    u16 f02;
    u16 f04;
    u8  pad[0x16A];
    u8  f170;
} W;

extern void func_020403F4(u32 a);
extern void func_02192EE0(u32 a);

void func_02192F74(W *w)
{
    if (w->f170 != 0) {
        w->f170 = 0;
        if (w->f04 == 0xFF) {
            func_020403F4(2);
            func_02192EE0(1);
            w->f04 = 2;
        } else {
            func_02192EE0(0);
        }
    }
}
