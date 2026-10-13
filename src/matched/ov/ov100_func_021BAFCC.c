/*
 * function: IRCBATTLEMATCH_StepShowErrorMessage
 * address: 0x021BAFCC
 * packet: pkt_ov100_021BAFCC
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   IRCBATTLEMATCH_FreeMessageWindows 0x021BA5F4 thumb ov100
 *   IRCBATTLEMATCH_PrintMainMessage 0x021BA3A4 thumb ov100
 *   IRCBATTLEMATCH_OpenWaitMenu 0x021BA290 thumb ov100
 *   IRCBATTLEMATCH_SetStep 0x021B95B8 thumb ov100
 *   IRCBATTLEMATCH_StepWaitErrorDialogClose 0x021BAD78 thumb ov100
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Word { int x; };
extern void IRCBATTLEMATCH_FreeMessageWindows(unsigned a);
extern void IRCBATTLEMATCH_PrintMainMessage(struct Word *,int);
extern void IRCBATTLEMATCH_OpenWaitMenu(int,int);
extern void IRCBATTLEMATCH_SetStep(u8 *,u32);
extern void IRCBATTLEMATCH_StepWaitErrorDialogClose(unsigned a);
void IRCBATTLEMATCH_StepShowErrorMessage(int p) {
    struct Word x;
    IRCBATTLEMATCH_FreeMessageWindows(p);
    x.x=12;
    IRCBATTLEMATCH_PrintMainMessage(&x,p);
    IRCBATTLEMATCH_OpenWaitMenu(p,0);
    IRCBATTLEMATCH_SetStep((u8 *)p,(u32)IRCBATTLEMATCH_StepWaitErrorDialogClose);
}
