/*
 * function: func_021BE904
 * address:  0x021BE904
 * packet:   pkt_ov099_021BE904
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BA8BC  0x021BA8BC  thumb  ov099
 *   func_021BAAB8  0x021BAAB8  thumb  ov099
 *   func_020362DC  0x020362DC  arm
 */
typedef unsigned int u32;
extern u32 func_020362DC(void);
extern int func_021BA8BC(void *p);
extern void func_021BAAB8(char *p, int a, int b);

int func_021BE904(char *p, int v)
{
    int n = *(int *)(p + 0x1E0);
    if (n > 0) {
        *(int *)(p + 0x1E0) = n - 1;
        return v;
    }
    if (func_020362DC() & 3) {
        *(int *)(p + 0x19C) = func_021BA8BC((void *)(*(int *)(p + 0x19C)));
        func_021BAAB8(p, 0x37, 0);
        *(int *)(p + 0x1CC) = 2;
    }
    return v;
}
