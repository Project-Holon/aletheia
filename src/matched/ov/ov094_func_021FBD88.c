/*
 * function: func_021FBD88
 * address:  0x021FBD88
 * packet:   pkt_ov094_021FBD88
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_021FDBB0  0x021FDBB0  thumb  ov094
 *   func_021FBDD4  0x021FBDD4  thumb  ov094
 */
typedef struct {
    char pad[0x23c];
    int f23c;
} State;

extern int func_0201134C(int);
extern int func_021FDBB0(State *s, int i);
extern void func_021FBDD4(int a, int b, int c, int d, int e);

int func_021FBD88(int a, State *s)
{
    int x = func_021FDBB0(s, func_0201134C(a));
    int op = func_0201134C(a);
    int y = func_021FDBB0(s, func_0201134C(a));
    int z = func_0201134C(a);

    func_021FBDD4(a, x, y, op, z);
    return s->f23c;
}
