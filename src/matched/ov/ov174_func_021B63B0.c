/*
 * function: func_021B63B0
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
 *   func_02040618 0x02040618 arm
 */
extern void CLACT_VBlankSystem(void);extern int func_02005728(int);extern void func_02040618(unsigned,unsigned,unsigned);
void func_021B63B0(void) {CLACT_VBlankSystem();func_02040618(1,0,func_02005728(256));func_02040618(1,3,func_02005728(256));}
