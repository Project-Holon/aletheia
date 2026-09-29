/*
 * function: func_0218DEFC
 * address:  0x0218DEFC
 * packet:   pkt_ov021_0218DEFC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02169598  0x02169598  thumb ov010
 *   func_021694FC  0x021694FC  thumb ov010
 *   func_02169538  0x02169538  thumb ov010
 */

typedef unsigned char  u8;

extern int func_02169598(int o);
extern int func_021694FC(int o);
extern void func_02169538(int o, int *out);

void func_0218DEFC(char *p, int o, int v)
{
    int a;
    int b;
    int t;
    int c;
    int i;

    if (func_02169598(o) == 0)
        return;
    if (func_021694FC(o) == 0)
        return;
    func_02169538(o, &a);
    t = *(int *)(p + 0x48) - a;
    for (i = *(u8 *)(p + 0x41); i > 0; i--) {
        func_02169538(*(int *)(*(char **)(p + 0x24) + *(u8 *)(*(int *)(p + 0x44) + i - 1) * 0x28), &b);
        c = *(int *)(p + 0x48) - b;
        if (c >= 0 && t >= c)
            break;
        if (t < 0)
            break;
        *(u8 *)(*(int *)(p + 0x44) + i) = *(u8 *)(*(int *)(p + 0x44) + i - 1);
    }
    *(u8 *)(*(int *)(p + 0x44) + i) = v;
    *(u8 *)(p + 0x41) = *(u8 *)(p + 0x41) + 1;
}
