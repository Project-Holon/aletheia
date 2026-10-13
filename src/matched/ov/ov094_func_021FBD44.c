/*
 * function: func_021FBD44
 * address:  0x021FBD44
 * packet:   pkt_ov094_021FBD44
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   func_021FDBB0  0x021FDBB0  thumb  ov094
 *   func_021FBDD4  0x021FBDD4  thumb  ov094
 */
typedef struct {
    char pad[0x23c];
    int f23c;
} State;

typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern int func_021FDBB0(State *s, int i);
extern void func_021FBDD4(int a, int b, int c, int d, int e);

int func_021FBD44(struct Cursor *a, State *s)
{
    int x = func_021FDBB0(s, VM_GetU32(a));
    int op = VM_GetU32(a);
    int y = VM_GetU32(a);
    int z = VM_GetU32(a);

    func_021FBDD4((int)a, x, y, op, z);
    return s->f23c;
}
