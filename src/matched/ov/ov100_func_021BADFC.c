/*
 * function: IRCBATTLEMATCH_StepOpenWirelessWaitMenu
 * address: 0x021BADFC
 * packet: pkt_ov100_021BADFC
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   IRCBATTLEMATCH_OpenWaitMenu 0x021BA290 thumb ov100
 *   IRCBATTLEMATCH_SetStep 0x021B95B8 thumb ov100
 *   IRCBATTLEMATCH_StepWaitWirelessStep 0x021BADB0 thumb ov100
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void IRCBATTLEMATCH_OpenWaitMenu(int,int),IRCBATTLEMATCH_SetStep(u8 *,u32);
extern void IRCBATTLEMATCH_StepWaitWirelessStep(int);
void IRCBATTLEMATCH_StepOpenWirelessWaitMenu(int p) { IRCBATTLEMATCH_OpenWaitMenu(p,0); IRCBATTLEMATCH_SetStep((u8 *)p,(u32)IRCBATTLEMATCH_StepWaitWirelessStep); }
