/*
 * function: func_021D7C14
 * address: 0x021D7C14
 * packet: pkt_ov125_021D7C14
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * symbols:
 *   func_021D7CAC 0x021D7CAC arm ov125
 *   func_021D7BCC 0x021D7BCC arm ov125
 *   func_021D7CC0 0x021D7CC0 arm ov125
 *   d_021D9E40 0x021D9E40 data a4
 */
extern void func_021D7CAC(void);
extern unsigned func_021D7BCC(void);
extern void func_021D7CC0(void);
extern char d_021D9E40[];
int func_021D7C14(void){func_021D7CAC();if(func_021D7BCC()!=8){func_021D7CC0();return -1;}else{func_021D7CC0();return *(int*)(d_021D9E40+0x25c);}}
