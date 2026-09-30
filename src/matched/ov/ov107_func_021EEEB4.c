/*
 * function: func_021EEEB4
 * address: 0x021EEEB4
 * packet: pkt_ov107_021EEEB4
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F6EA0 0x021F6EA0 data ov107 a4
 *   func_02040618 0x02040618 arm
 */
typedef unsigned char u8;
extern u8 d_021F6EA0[];
extern void func_02040618(unsigned,unsigned,unsigned);
void func_021EEEB4(void) {
 if(d_021F6EA0[0]>1) {
 d_021F6EA0[0]=0;
 func_02040618(3,2,1); func_02040618(3,5,1);
 func_02040618(7,2,1); func_02040618(7,5,1);
 } else d_021F6EA0[0]++;
}
