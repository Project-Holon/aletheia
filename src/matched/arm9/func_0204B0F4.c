/*
 * function: CLACT_SetRendererCulling
 * address:  0x0204B0F4
 * packet:   pkt_0204B0F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * blocker:  ABS32 CLACT_SetSurfaceCulling at +0x08: no branch anywhere outside this range reaches 0x0204BE38
 *
 * symbols:
 *   CLACT_SetSurfaceCulling  0x0204BE38  arm
 */

struct Obj;
extern void CLACT_SetSurfaceCulling(struct Obj *obj, int on);
struct Actor;

void CLACT_SetRendererCulling(struct Actor *a0, int a1)
{
    CLACT_SetSurfaceCulling((struct Obj *)a0, a1);
}
