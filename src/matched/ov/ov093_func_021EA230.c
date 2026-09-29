/*
 * function: func_021EA230
 * address:  0x021EA230
 * packet:   pkt_ov093_021EA230
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E9100  0x021E9100  thumb  ov093
 *   func_021ED268  0x021ED268  thumb  ov093
 *   func_021ED280  0x021ED280  thumb  ov093
 *   func_021EA32C  0x021EA32C  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *func_021E9100(u8 *p, int n);
extern void func_021ED268(char *p, u8 k, u32 a);
extern int func_021ED280(char *p);
extern void func_021EA32C(char *p, int k);

int func_021EA230(int *st, char *ctx)
{
    u8 *t;

    t = func_021E9100((u8 *)ctx, 0xc);
    switch (*st) {
    case 0:
        func_021ED268(*(char **)(ctx + 0x17c), t[0xa], *(u16 *)t);
        func_021EA32C(ctx, *(int *)(t + 4));
        *st = *st + 1;
        break;
    case 1:
        if (func_021ED280(*(char **)(ctx + 0x17c)) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}
