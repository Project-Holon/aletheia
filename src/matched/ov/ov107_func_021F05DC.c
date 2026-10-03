/*
 * function: func_021F05DC
 * address: 0x021F05DC
 * packet: pkt_ov107_021F05DC
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F6EA0 0x021F6EA0 data a4
 *   func_02043534 0x02043534 arm
 *   func_020435F4 0x020435F4 arm
 *   func_02040588 0x02040588 arm
 */
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
extern u8 d_021F6EA0[];extern void func_02043534(int),func_020435F4(int),func_02040588(u32,u32);
int func_021F05DC(void) { func_02043534(0);func_020435F4(0);func_02040588(*(int *)(d_021F6EA0+4)==1?4:2,1);return 1; }
