/*
 * function: func_021DF998
 * address: 0x021DF998
 * packet: pkt_ov137_021DF998
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: BG0CNT 0x04000008 read at 021DF9F2, written 021DF9FC.
 * symbols:
 *   func_02040588 0x02040588 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   func_0207D63C 0x0207D63C arm
 */
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern void func_0207D63C(unsigned, int, int, int, int);
static inline void G2_SetBG0Priority(int priority)
{
    *(volatile u16 *)0x04000008 = (u16)((*(volatile u16 *)0x04000008 & ~3) | priority);
}
void func_021DF998(char *a0)
{
    func_02040588(0, 1);
    func_02040588(1, 1);
    func_02040588(2, 1);
    func_02040588(3, 1);
    func_02040588(4, 0);
    func_02040588(5, 0);
    func_02040588(6, 1);
    func_02040588(7, 1);
    BG_SYS_SetMainPlaneVisible(16, 1);
    BG_SYS_SetSubPlaneVisible(16, 1);
    G2_SetBG0Priority(1);
    func_0207D63C(0x04000050, 4, 40, 11, 10);
}
