/*
 * function: func_02073484
 * address:  0x2073484
 * packet:   pkt_020733E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * blocker:  0x02089398 has no witness outside this range: its only caller is 0x020734A0, inside this function
 *
 * The comparison has to be spelled `v == x->b2e`: the other operand order
 *  * emits `cmp r0, r4` where the original has `cmp r4, r0`, two bytes of operand
 *  * numbering and nothing else. The x == 0 test and the value test share one
 *  * predicated exit, which is the `||` form of the guard chain.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct X { u8 pad00[0x2e]; u8 b2e; u8 pad2[0x3c - 0x2f]; u8 b3c; };
extern void func_02089398(u32);

void func_02073484(struct X *x, u8 v)
{
    if (x == 0) return;
    if (v == x->b2e) return;
    func_02089398(x->b3c);
    x->b2e = v;
}
