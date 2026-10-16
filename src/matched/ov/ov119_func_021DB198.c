/*
 * function: POKETRADE_PROC_StepSlideInSubScreen
 * address: 0x021DB198
 * packet: pkt_ov119_021DB198
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   G2x_SetBlendBrightness_ 0x0207D658 arm
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepShowSummaryMessage 0x021DB164 thumb ov119
 */
typedef unsigned int   u32;
extern void G2x_SetBlendBrightness_(u32 addr, int plane, int brightness);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_PROC_StepShowSummaryMessage(char *p);
void POKETRADE_PROC_StepSlideInSubScreen(void *p) {
 G2x_SetBlendBrightness_((u32)((void *)0x04001050),27,-8);
 POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepShowSummaryMessage);
}
