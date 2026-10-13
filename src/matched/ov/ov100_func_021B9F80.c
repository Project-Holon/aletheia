/*
 * function: IRCBATTLEMATCH_StepRegisterCommands
 * address: 0x021B9F80
 * packet: pkt_ov100_021B9F80
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_COMMAND_AddCommandTable 0x0203A574 arm
 *   gIrcBattleMatchCommandTable 0x021BB6C0 data a4
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   GFL_NET_SetAutoExit 0x0203D7B0 arm
 *   GFL_NET_SetLoginOption 0x0203D7BC arm
 *   IRCBATTLEMATCH_SetStep 0x021B95B8 thumb ov100
 *   IRCBATTLEMATCH_StepSendMode 0x021B9EF8 thumb ov100
 */
extern void GFL_NET_COMMAND_AddCommandTable(unsigned,unsigned,unsigned,unsigned);
extern const unsigned gIrcBattleMatchCommandTable[];
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *p, unsigned int lo, unsigned int hi);
typedef unsigned char  u8;
extern void GFL_NET_SetAutoExit(u8 a0);
extern void GFL_NET_SetLoginOption(u8 a0);
extern void IRCBATTLEMATCH_SetStep(unsigned char *,unsigned);
extern void IRCBATTLEMATCH_StepSendMode(u8 *a);
void IRCBATTLEMATCH_StepRegisterCommands(unsigned a)
{
 GFL_NET_COMMAND_AddCommandTable(0xc00,(unsigned)gIrcBattleMatchCommandTable,6,a);
 GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x78,12);
 GFL_NET_SetAutoExit(1);GFL_NET_SetLoginOption(1);
 IRCBATTLEMATCH_SetStep((unsigned char *)a,(unsigned)IRCBATTLEMATCH_StepSendMode);
}
