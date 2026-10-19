/*
 * function: LOCAL_TVT_SYS_VBlankHandler
 * address: 0x021B63B0
 * packet: pkt_ov174_021B63B0
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   func_02005728 0x02005728 thumb
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 */
extern void CLACT_VBlankSystem(void);extern int func_02005728(int);extern void BG_SYS_ChangeScrollImmediate(unsigned,unsigned,unsigned);
void LOCAL_TVT_SYS_VBlankHandler(void) {CLACT_VBlankSystem();BG_SYS_ChangeScrollImmediate(1,0,func_02005728(256));BG_SYS_ChangeScrollImmediate(1,3,func_02005728(256));}
