/*
 * function: func_0204B084
 * address:  0x0204B084
 * packet:   pkt_0204B084
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_0204BE28 0x0204BE28 arm
 */

typedef unsigned int u32;
struct OamState;
extern void func_0204BE28(struct OamState *p);
extern u32 sub_020307B0(void *p);

void func_0204B084(struct OamState *p)
{
    func_0204BE28(p);
    sub_020307B0(p);
}
