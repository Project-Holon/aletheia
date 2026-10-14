/*
 * function: MB_COMM_SYS_VBlankRefreshBg
 * address: 0x021EEEB4
 * packet: pkt_ov107_021EEEB4
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gMbParentUi 0x021F6EA0 data ov107 a4
 *   func_02040618 0x02040618 arm
 */
typedef unsigned char u8;
extern u8 gMbParentUi[];
extern void func_02040618(unsigned,unsigned,unsigned);
void MB_COMM_SYS_VBlankRefreshBg(void) {
 if(gMbParentUi[0]>1) {
 gMbParentUi[0]=0;
 func_02040618(3,2,1); func_02040618(3,5,1);
 func_02040618(7,2,1); func_02040618(7,5,1);
 } else gMbParentUi[0]++;
}
