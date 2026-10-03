/*
 * function: func_021D2320
 * address:  0x021D2320
 * packet:   pkt_ov093_021D2320
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 *   func_021EA40C  0x021EA40C  thumb  ov093
 *   func_021EA428  0x021EA428  thumb  ov093
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021D646C  0x021D646C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021B8D8C(void *p, void *a, u8 b);
extern void func_021EA40C(char *ctx, int a);
extern int func_021EA428(void *w);
extern u8 *func_021B9934(void *p, u8 i);
extern void func_021D646C(void *p);

int func_021D2320(u8 *p, int *st, u32 *c)
{
    switch (*st) {
    case 0:
        func_021EA40C(*(void **)(p + 0x54), func_021B8D8C(*(void **)p, *(void **)(p + 4), *c));
        (*st)++;
        break;
    case 1:
        if (func_021EA428(*(void **)(p + 0x54))) {
            func_021D646C(func_021B9934(*(void **)(p + 4), *c));
            return 1;
        }
        break;
    }
    return 0;
}
