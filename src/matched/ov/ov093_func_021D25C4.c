/*
 * function: func_021D25C4
 * address:  0x021D25C4
 * packet:   pkt_ov093_021D25C4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 *   func_021CD9E0  0x021CD9E0  thumb  ov093
 *   func_021B8590  0x021B8590  thumb  ov093
 *   func_021EA838  0x021EA838  thumb  ov093
 *   func_021EA850  0x021EA850  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021B8D8C(void *p, void *a, u8 b);
extern int func_021CD9E0(void *p);
extern int func_021B8590(void *p);
extern void func_021EA838(void *w, int v);
extern int func_021EA850(void *w, int v);

int func_021D25C4(u8 *p, int *st, u32 *c)
{
    int t = func_021B8D8C(*(void **)p, *(void **)(p + 4), *c);

    switch (*st) {
    case 0:
        if (func_021CD9E0(p))
            return 1;
        if (!func_021B8590(*(void **)p))
            return 1;
        func_021EA838(*(void **)(p + 0x54), t);
        (*st)++;
        break;
    case 1:
        if (func_021EA850(*(void **)(p + 0x54), t))
            return 1;
        break;
    }
    return 0;
}
