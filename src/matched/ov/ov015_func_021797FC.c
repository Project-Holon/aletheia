/*
 * unit: yes
 * function: IRCNET_CbStop, IRCNET_CbIsRunning
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
 *   IRCNET_Stop 0x02179998 thumb ov015
 *   IRCNET_IsRunning 0x021799F0 thumb ov015
 */
extern void IRCNET_Stop(void);
extern unsigned char IRCNET_IsRunning(void);
int IRCNET_CbStop(void) { IRCNET_Stop(); return 1; }
unsigned char IRCNET_CbIsRunning(void) { return IRCNET_IsRunning(); }
