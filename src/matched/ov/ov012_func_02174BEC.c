/*
 * function: func_02174BEC
 * address:  0x02174BEC
 * packet:   pkt_ov012_02174BEC
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_02082D44  0x02082D44  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Entry;
extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(u32 v);
extern void func_02082D44(void *src, void *dst, u32 n);

void func_02174BEC(u32 a, u32 b, void *c, u8 *d)
{
    u8 *w = *(u8 **)(d + 0x355C);

    if (a == func_0203D1A4((u32)func_020399A8())) {
        return;
    }
    if (w == 0 || *(int *)w == 0) {
        return;
    }
    if (*(void **)(w + a * 4 + 0x134) == 0) {
        return;
    }
    func_02082D44(c, *(void **)(w + a * 4 + 0x134), b);
    (w + a)[0x144] = 1;
}
