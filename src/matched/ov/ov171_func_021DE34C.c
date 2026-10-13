/*
 * function: func_021DE34C
 * address:  0x021DE34C
 * packet:   pkt_ov171_021DE34C
 * region:   ov171
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_DeleteActor  0x0204B3B4  arm
 */

struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);

void func_021DE34C(char *p, int i)
{
    if (*(int *)(p + 0xb74 + i * 4) != 0) {
        CLACT_DeleteActor((struct Obj *)(*(int *)(p + 0xb74 + i * 4)));
        *(int *)(p + 0xb74 + i * 4) = 0;
    }
}
