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
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 */
typedef unsigned char u8;
extern u8 gMbParentUi[];
extern void BG_SYS_ChangeScrollImmediate(unsigned,unsigned,unsigned);
void MB_COMM_SYS_VBlankRefreshBg(void) {
 if(gMbParentUi[0]>1) {
 gMbParentUi[0]=0;
 BG_SYS_ChangeScrollImmediate(3,2,1); BG_SYS_ChangeScrollImmediate(3,5,1);
 BG_SYS_ChangeScrollImmediate(7,2,1); BG_SYS_ChangeScrollImmediate(7,5,1);
 } else gMbParentUi[0]++;
}
