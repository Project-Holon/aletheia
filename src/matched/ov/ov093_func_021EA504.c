/*
 * function: func_021EA504
 * address:  0x021EA504
 * packet:   pkt_ov093_021EA504
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E9100  0x021E9100  thumb  ov093
 *   func_021CD9E0  0x021CD9E0  thumb  ov093
 *   func_021ED3D4  0x021ED3D4  thumb  ov093
 *   func_021ED450  0x021ED450  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *func_021E9100(u8 *p, int n);
extern u32 func_021CD9E0(u8 *p);
extern void func_021ED3D4(char *p, u8 k, int a, u8 b, int flag);
extern int func_021ED450(char *p);

int func_021EA504(int *st, char *ctx)
{
    u8 *t;

    t = func_021E9100((u8 *)ctx, 4);
    switch (*st) {
    case 0:
        func_021ED3D4(*(char **)(ctx + 0x17c), t[0], t[1], t[2], func_021CD9E0(*(u8 **)(ctx + 4)));
        *st = *st + 1;
        break;
    case 1:
        if (func_021ED450(*(char **)(ctx + 0x17c)) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}
