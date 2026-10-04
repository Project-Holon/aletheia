/*
 * function: func_021B75E8
 * address:  0x021B75E8
 * packet:   pkt_021B75E8
 * region:   ov180
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B3B4  0x0204B3B4  arm
 */

struct Obj;
extern void func_0204B3B4(struct Obj *p);

void func_021B75E8(char *p, int i)
{
    if (*(int *)(p + 0x9048 + i * 4) != 0) {
        func_0204B3B4((struct Obj *)(*(int *)(p + 0x9048 + i * 4)));
        *(int *)(p + 0x9048 + i * 4) = 0;
    }
}
