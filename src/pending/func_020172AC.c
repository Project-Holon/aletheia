/*
 * function: func_020172AC
 * address:  0x020172AC
 * packet:   pkt_020172AC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  +000C ABS32 func_02014CF0          : 02014CF0 (arm, from name) has no witness outside 020172AC..020172BC
 */

extern void func_02014CF0(int a0, int a1, int a2);
extern void func_020172BC(void);

void func_020172AC(int a0, int a1)
{
    func_02014CF0(a0, (int)func_020172BC, a1);
}
