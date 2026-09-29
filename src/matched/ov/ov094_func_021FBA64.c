/*
 * function: func_021FBA64
 * address:  0x021FBA64
 * packet:   pkt_ov094_021FBA64
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_021F9858  0x021F9858  thumb  ov094
 */
typedef struct {
    char pad[0x23c];
    int f23c;
} State;

extern int func_0201134C(int);
extern void func_021F9858(int a, int b, int c, int d, int e, int f, int g, int h, int i);

int func_021FBA64(int a, State *s)
{
    int v0 = func_0201134C(a);
    int v1 = func_0201134C(a);
    int v2 = func_0201134C(a);
    int v3 = func_0201134C(a);
    int v4 = func_0201134C(a);
    int v5 = func_0201134C(a);
    int v6 = func_0201134C(a);
    int v7 = func_0201134C(a);

    func_0201134C(a);
    func_021F9858(a, v0, v1, v2, v4, v5, v6, v7, v3);
    return s->f23c;
}
