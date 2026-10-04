/*
 * function: func_021CD624
 * address:  0x021CD624
 * packet:   pkt_ov021_021CD624
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
 * (verified EXACT, 12 bytes, thumb, with func_02082D44 0x02082D44 arm.)
 *
 * symbols:
 *   func_02008494  0x02008494  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_021CEA84  0x021CEA84  thumb  ov021
 *   func_021CEAB0  0x021CEAB0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_02008494(void *src, void *dst);
extern void func_02082D44(void *src, void *dst, int n);
extern void func_021CEA84(u8 *p, u8 i);
extern void func_021CEAB0(u8 *p);

void func_021CD624(u8 *p, int i, u32 a, u32 b, void *c)
{
    u8 *e;

    e = p + 0x50 + i * 0x2c;
    func_02008494((void *)a, e);
    e[0x20] = 1;
    e[0x21] = b;
    func_02082D44(c, e + 0x23, 6);
    func_021CEA84(p, i);
    func_021CEAB0(p);
    if (*(u32 *)(p + 0x48c)) {
        (*(void (**)(u32, u32, void *))(p + 0x48c))(*(u32 *)(p + 0x488), a, c);
    }
}
