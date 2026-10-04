/*
 * function: func_021F2E5C
 * address:  0x021F2E5C
 * packet:   pkt_021F2E5C
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F2E5C 0x021F2E5C thumb
 *   func_0204B3B4 0x0204B3B4 arm
 */

struct Obj;
extern void func_0204B3B4(struct Obj *p);

void func_021F2E5C(char *p)
{
    func_0204B3B4((struct Obj *)(*(int *)(p + 8)));
}
