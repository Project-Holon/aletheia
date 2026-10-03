/*
 * function: func_021D2374
 * address:  0x021D2374
 * packet:   pkt_ov093_021D2374
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 *   func_021EA438  0x021EA438  thumb  ov093
 *   func_021EA448  0x021EA448  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021B8D8C(void *p, void *a, u8 b);
extern void func_021EA438(u32 *p, u32 a2);
extern int func_021EA448(void *w);

int func_021D2374(u8 *p, int *st, u32 *c)
{
    switch (*st) {
    case 0:
        func_021EA438(*(void **)(p + 0x54), func_021B8D8C(*(void **)p, *(void **)(p + 4), *c));
        (*st)++;
        break;
    case 1:
        if (func_021EA448(*(void **)(p + 0x54)))
            return 1;
        break;
    }
    return 0;
}
