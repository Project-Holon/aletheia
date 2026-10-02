/*
 * function: func_021B960C
 * address:  0x021B960C
 * packet:   pkt_ov021_021B960C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B87FC  0x021B87FC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef struct { u32 key[4]; u32 val[4]; } T;
extern int func_021B87FC(u32 c, u32 k);
u32 func_021B960C(T *t, int b, u32 c)
{
    int i;
    int r;
    for (i = 0; i < 4; i++) {
        r = func_021B87FC(c, t->key[i]);
        if (r == b)
            return t->val[i];
    }
    return 0;
}
