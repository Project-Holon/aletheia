/*
 * function: func_021CE1F4
 * address:  0x021CE1F4
 * packet:   pkt_ov021_021CE1F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocker: func_02008494 (arm9 unlabelled thumb tail-call stub, Ilias's:
 * ldr r3,=0x02082D44; movs r2,#0x20; bx r3) has no witness outside the range.
 * Verified C for the leaf: void func_02008494(void *a, void *b) { func_02082D44(a, b, 0x20); }
 * (verified EXACT, 12 bytes, thumb, with func_02082D44 0x02082D44 arm; leaf not filed here.)
 *
 * symbols:
 *   func_02008494  0x02008494  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

extern void func_02008494(void *a, void *b);

u8 func_021CE1F4(u8 *p)
{
    u8 i;
    u8 mask;
    u8 *buf;
    u8 *e;

    mask = 0;
    i = 0;
    e = p + 0x50;
    buf = p + 0x494;
    for (; i < 4; i++) {
        if (p[0x70 + i * 0x2c]) {
            func_02008494(e + i * 0x2c, buf + i * 32);
            mask |= 1 << i;
        }
    }
    p[0x514] = mask;
    return 1 | mask;
}
