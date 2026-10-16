/*
 * function: POKETRADE_PROC_StepOpenMenu
 * address: 0x021D9DC4
 * packet: pkt_ov119_021D9DC4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_PROC_SendSideMon 0x021DB0A0 thumb ov119
 *   POKETRADE_SAVE_OpenTaskMenu 0x021E1410 thumb ov119
 *   G2x_SetBlendBrightness_ 0x0207D658 arm
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepMenuChoice 0x021D9D60 thumb ov119
 *   gOpenMenuPos 0x021E7584 data a4
 */

typedef struct { int a,b; } Pair;
extern const Pair gOpenMenuPos;
typedef unsigned int   u32;
extern int POKETRADE_PROC_SendSideMon(char *p);
extern void POKETRADE_SAVE_OpenTaskMenu(void *p, int *ids, int count);
extern void G2x_SetBlendBrightness_(u32 addr, int plane, int brightness);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_PROC_StepMenuChoice(char *p);
void POKETRADE_PROC_StepOpenMenu(void *p)
{
    if (POKETRADE_PROC_SendSideMon(p)) {
        Pair t = gOpenMenuPos;
        POKETRADE_SAVE_OpenTaskMenu(p,(int *)(&t),2);
        G2x_SetBlendBrightness_(0x04001050,0x1B,-8);
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepMenuChoice);
    }
}
