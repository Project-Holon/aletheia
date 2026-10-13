/*
 * function: func_02205138
 * address:  0x02205138
 * packet:   pkt_ov195_022040E0
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Leaf of the func_022040E0 dependency tree: when the scene object has the
 * +0x60 pointer set, tear down the six +0x48 handles.
 *
 * symbols:
 *   CLACT_SetActorAnimIndex  0x0204B908  arm
 *   func_0204B92C  0x0204B92C  arm
 */
extern void CLACT_SetActorAnimIndex(int, int);
struct Obj;
extern void func_0204B92C(struct Obj *p, unsigned int v);

void func_02205138(int a, int *p)
{
    unsigned char i;

    if (p[0x18] == 0)
        return;
    for (i = 0; i < 6; i++) {
        CLACT_SetActorAnimIndex(p[0x12 + i], 0);
        func_0204B92C((struct Obj *)p[0x12 + i], 1);
    }
}
