/*
 * function: func_021E2094
 * address: 0x021E2094
 * packet: pkt_ov170_021E2094
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02035C60 0x02035C60 arm
 *   func_020362DC 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   func_020061E4 0x020061E4 thumb
 */

typedef unsigned int u32;
extern int func_02035C60(void);
extern u32 func_020362DC(void);
typedef unsigned char  u8;
extern void func_020355D8(u8 v);
extern void func_020061E4(unsigned);
int func_021E2094(char *p)
{
    if (func_02035C60() == 1) {
        func_020061E4(0x54C);
        func_020355D8(1);
        return *(int *)(p + 0x28);
    }
    if (func_020362DC() & 3) {
        func_020061E4(0x54C);
        func_020355D8(0);
        return *(int *)(p + 0x28);
    }
    return 6;
}
