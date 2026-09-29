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

extern void func_0201EFA4(void *, int, int, int, int, int);
extern int func_020212B0(u16);
extern void func_0201EF34(void *, int, int);
extern void func_0201F250(void *, void *, void *);
extern void func_0201F898(void *, void *, int, int);
extern void func_0201F878(void *, int, int, int, int);

void func_021B385C(char *p, int idx, int mode, int val, int arg)
{
    if (mode == 1) {
        func_0201EFA4(*(void **)(p + 400), 0, val - 327, 2, 2, 1);
        func_0201EF34(*(void **)(p + 400), 1, func_020212B0(val));
        func_0201F250(*(void **)(p + 400), *(void **)(p + 408), *(void **)(p + 412));
        func_0201F898(*(char **)(p + 384) + idx * 8, *(void **)(p + 408), idx, *(u16 *)(p + 4));
    } else {
        func_0201F878(*(char **)(p + 384) + idx * 8, arg, val, idx, *(u16 *)(p + 4));
    }
}
