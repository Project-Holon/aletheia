/*
 * function: func_021CE84C
 * address:  0x021CE84C
 * packet:   pkt_ov021_021CE84C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0219077C  0x0219077C  thumb  ov021
 *   func_02190794  0x02190794  thumb  ov021
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02190758  0x02190758  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern int func_0219077C(u32 h);
struct Slot;
struct WordSet;
extern void func_02190794(struct Slot **p, int x, int y, int w, int h);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern int func_02190758(u32 a, u32 b, u32 c, u32 d);

int func_021CE84C(u32 *p, int n)
{
    if (p[3] && func_0219077C(p[3]) == 1) {
        func_02190794((struct Slot **)p[3], 0, 0x40, 0x90, 0x50);
        func_0201EFA4((struct WordSet *)p[1], 0, *(u8 *)((u8 *)p + 0x51d) - n, 1, 0, 1);
        func_0201F250((struct WordSet *)p[1], (void *)p[10], (void *)p[9]);
        func_02190758(p[3], 0, 0x40, p[10]);
        return 1;
    }
    return 0;
}
