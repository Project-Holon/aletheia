/*
 * function: func_021FE840
 * address: 0x021FE840
 * packet: pkt_ov186_021FE840
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0207D63C 0x0207D63C arm
 *   func_020434DC 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 */
extern void func_0207D63C(unsigned, int, int, int, int);
typedef unsigned int   u32;
extern void func_020434DC(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
void func_021FE840(int unused, int mask, int value)
{
    if (mask & 1) {
        func_0207D63C(0x04000050, 7, 31, value, 16 - value);
        if (value == 0) {
            func_020434DC(1, 0);
            func_020434DC(2, 0);
            func_020434DC(4, 0);
        } else {
            func_020434DC(1, 1);
            func_020434DC(2, 1);
            func_020434DC(4, 1);
        }
    }
    if (mask & 2) {
        func_0207D63C(0x04001050, 3, 7, value, 16 - value);
        if (value == 0) {
            BG_SYS_SetSubPlaneVisible(1, 0);
            BG_SYS_SetSubPlaneVisible(2, 0);
        } else {
            BG_SYS_SetSubPlaneVisible(1, 1);
            BG_SYS_SetSubPlaneVisible(2, 1);
        }
    }
}
