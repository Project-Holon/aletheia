/*
 * function: IRCBATTLEMATCH_StepShowDisconnectMessage
 * address: 0x021BB154
 * packet: pkt_ov100_021BB154
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   IRCBATTLEMATCH_FreeMessageWindows 0x021BA5F4 thumb ov100
 *   IRCBATTLEMATCH_PrintMainMessage 0x021BA3A4 thumb ov100
 *   IRCBATTLEMATCH_SetStep 0x021B95B8 thumb ov100
 *   IRCBATTLEMATCH_StepWaitTouchThenCancel 0x021BAEB4 thumb ov100
 *   gIrcBattleMatchMsgDisconnected 0x021BB660 data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Word { int x; };
extern const struct Word gIrcBattleMatchMsgDisconnected;
extern void IRCBATTLEMATCH_FreeMessageWindows(unsigned a);
extern void IRCBATTLEMATCH_PrintMainMessage(struct Word *,int);
extern void IRCBATTLEMATCH_SetStep(u8 *,u32);
extern void IRCBATTLEMATCH_StepWaitTouchThenCancel(int);
void IRCBATTLEMATCH_StepShowDisconnectMessage(int p) {
    struct Word x=gIrcBattleMatchMsgDisconnected;
    IRCBATTLEMATCH_FreeMessageWindows(p);
    IRCBATTLEMATCH_PrintMainMessage(&x,p);
    IRCBATTLEMATCH_SetStep((u8 *)p,(u32)IRCBATTLEMATCH_StepWaitTouchThenCancel);
}
