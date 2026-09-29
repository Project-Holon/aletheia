/*
 * function: func_021D266C
 * address:  0x021D266C
 * packet:   pkt_ov093_021D266C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B8DEC  0x021B8DEC  thumb  ov093
 *   func_021B8E70  0x021B8E70  thumb  ov093
 *   func_021B9AEC  0x021B9AEC  thumb  ov093
 *   func_021B9C10  0x021B9C10  thumb  ov093
 *   func_021EA904  0x021EA904  thumb  ov093
 *   func_021EA950  0x021EA950  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021B8DEC(void *p, u32 k);
extern u8 func_021B8E70(void *p, u32 k);
extern void *func_021B9AEC(void *p, u32 k);
extern void func_021B9C10(void *p, int a, int b);
extern void func_021EA904(void *w, u32 a, u32 b, u32 c, int d, int e);
extern int func_021EA950(void *w);

int func_021D266C(u8 *p, int *st, u32 *c)
{
    switch (*st) {
    case 0: {
        u8 a = c[0];
        u32 b = (u8)c[1];
        u32 d = (u8)c[2];
        int x = func_021B8DEC(*(void **)p, b);
        int y = func_021B8DEC(*(void **)p, d);
        u32 m = func_021B8E70(*(void **)p, b);
        u32 n = func_021B8E70(*(void **)p, d);
        func_021B9C10(func_021B9AEC(*(void **)(p + 4), a), x, y);
        func_021EA904(*(void **)(p + 0x54), a, m, n, x, y);
        (*st)++;
        break;
    }
    case 1:
        if (func_021EA950(*(void **)(p + 0x54)))
            return 1;
        break;
    }
    return 0;
}
