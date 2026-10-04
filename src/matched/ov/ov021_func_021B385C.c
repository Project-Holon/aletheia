/*
 * function: func_021B385C
 * address:  0x021B385C
 * packet:   pkt_ov021_021B385C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B385C 0x021B385C thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_020212B0 0x020212B0 thumb
 *   func_0201EF34 0x0201EF34 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201F898 0x0201F898 thumb
 *   func_0201F878 0x0201F878 thumb
 */

typedef unsigned short u16;

typedef unsigned int   u32;
struct WordSet;
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u16 func_020212B0(u16 id);
extern void func_0201EF34(struct WordSet *p, u32 i, u32 v);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
struct Slot;
extern void func_0201F898(struct Slot *table, u32 a, u32 b, u32 tag);
extern void func_0201F878(void *, int, int, int, int);

void func_021B385C(char *p, int idx, int mode, int val, int arg)
{
    if (mode == 1) {
        func_0201EFA4(*(void **)(p + 400), 0, val - 327, 2, 2, 1);
        func_0201EF34(*(void **)(p + 400), 1, func_020212B0(val));
        func_0201F250(*(void **)(p + 400), *(void **)(p + 408), *(void **)(p + 412));
        func_0201F898((struct Slot *)(*(char **)(p + 384) + idx * 8), (u32)(*(void **)(p + 408)), idx, *(u16 *)(p + 4));
    } else {
        func_0201F878(*(char **)(p + 384) + idx * 8, arg, val, idx, *(u16 *)(p + 4));
    }
}
