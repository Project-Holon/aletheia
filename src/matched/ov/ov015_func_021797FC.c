/*
 * unit: yes
 * function: func_021797FC, func_02179808
 * address: 0x021797FC
 * packet: pkt_ov015_021797FC
 * region: ov015
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: includes tail getter follower 02179808; root claimed.
 * symbols:
 *   func_02179998 0x02179998 thumb ov015
 *   IRCNET_IsRunning 0x021799F0 thumb ov015
 */
extern void func_02179998(void);
extern unsigned char IRCNET_IsRunning(void);
int func_021797FC(void) { func_02179998(); return 1; }
unsigned char func_02179808(void) { return IRCNET_IsRunning(); }
