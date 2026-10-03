/*
 * function: func_021D2628
 * address:  0x021D2628
 * packet:   pkt_ov093_021D2628
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 *   func_021EA384  0x021EA384  thumb  ov093
 *   func_021EA3A0  0x021EA3A0  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021B8D8C(void *p, void *a, u32 b);
extern void func_021EA384(char *ctx, int a);
extern int func_021EA3A0(u32 *p);

int func_021D2628(u8 *p, int *st, u32 *c)
{
    u8 id = *c;

    switch (*st) {
    case 0:
        func_021EA384(*(void **)(p + 0x54), func_021B8D8C(*(void **)p, *(void **)(p + 4), id));
        (*st)++;
        break;
    case 1:
        if (func_021EA3A0(*(void **)(p + 0x54)))
            return 1;
        break;
    }
    return 0;
}
