/*
 * function: func_0204B0F4
 * address:  0x0204B0F4
 * packet:   pkt_0204B0F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * blocker:  ABS32 func_0204BE38 at +0x08: no branch anywhere outside this range reaches 0x0204BE38
 */

struct Obj;
extern void func_0204BE38(struct Obj *obj, int on);
struct Actor;

void func_0204B0F4(struct Actor *a0, int a1)
{
    func_0204BE38((struct Obj *)a0, a1);
}
