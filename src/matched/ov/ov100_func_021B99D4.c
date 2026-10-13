/*
 * function: IRCBATTLEMATCH_StepWaitTouchThenExit
 * address: 0x021B99D4
 * packet: pkt_ov100_021B99D4
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   IRCBATTLEMATCH_AbortSession 0x021B95C0 thumb ov100
 *   IRCBATTLEMATCH_SetStep 0x021B95B8 thumb ov100
 *   IRCBATTLEMATCH_StartExitWipe 0x021B96B8 thumb ov100
 */
extern int TOUCHPANEL_GetTrg(void);
extern int IRCBATTLEMATCH_AbortSession(unsigned char *p);
extern void IRCBATTLEMATCH_SetStep(unsigned char *,unsigned);
typedef unsigned char  u8;
extern void IRCBATTLEMATCH_StartExitWipe(u8 *a);
void IRCBATTLEMATCH_StepWaitTouchThenExit(unsigned char *a)
{
 if(TOUCHPANEL_GetTrg()!=0) {
  IRCBATTLEMATCH_AbortSession(a);
  IRCBATTLEMATCH_SetStep((unsigned char *)a,(unsigned)IRCBATTLEMATCH_StartExitWipe);
 }
}
