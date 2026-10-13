/*
 * function: func_021BC6CC
 * address: 0x021BC6CC
 * packet: pkt_ov211_021BC6CC
 * region: ov211
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * volatile: hardware halfword clear at 021BC6DA to04000050 and021BC6DE to04001050.
 * symbols:
 *   func_021BC30C 0x021BC30C thumb ov211
 *   func_021BC43C 0x021BC43C thumb ov211
 *   func_02043534 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 */
extern void func_021BC30C(unsigned char *),func_021BC43C(void),func_02043534(unsigned),BG_SYS_SetSubVisiblePlanes(unsigned);
int func_021BC6CC(unsigned char *p){func_021BC30C(p);func_021BC43C();*(volatile unsigned short *)0x04000050=0;*(volatile unsigned short *)0x04001050=0;func_02043534(0);BG_SYS_SetSubVisiblePlanes(0);return 6;}
