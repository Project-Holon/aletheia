/*
 * function: func_021DFA14
 * address: 0x021DFA14
 * packet: pkt_ov137_021DFA14
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02040588 0x02040588 arm
 *   func_020434DC 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 */
typedef unsigned int   u32;
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_020434DC(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
void func_021DFA14(char *a0)
{
    func_02040588(0, 0);
    func_02040588(1, 0);
    func_02040588(2, 0);
    func_02040588(3, 0);
    func_02040588(4, 0);
    func_02040588(5, 0);
    func_02040588(6, 0);
    func_02040588(7, 0);
    func_020434DC(16, 0);
    BG_SYS_SetSubPlaneVisible(16, 0);
}
