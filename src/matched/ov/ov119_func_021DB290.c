/*
 * function: POKETRADE_PROC_StepExitSubScreen
 * address: 0x021DB290
 * packet: pkt_ov119_021DB290
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware read/write at 021DB2AA/021DB2AE
 * symbols:
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   POKETRADE_2D_ClearSubScreen 0x021E5D84 thumb ov119
 *   POKETRADE_SAVE_CloseMessageWindowClear 0x021E1098 thumb ov119
 *   POKETRADE_NEGO_SetOfferMarkersState 0x021DF7AC thumb ov119
 *   POKETRADE_2D_FadePaletteAll 0x021E71E0 thumb ov119
 *   POKETRADE_PROC_UpdateTouchbarButtons 0x021DBB6C thumb ov119
 *   POKETRADE_2D_SetupSubBlend 0x021E6700 thumb ov119
 *   POKETRADE_2D_DeleteCursorActor 0x021E7058 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepCloseSubScreenDone 0x021DB278 thumb ov119
 */
typedef unsigned int   u32;
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern void POKETRADE_2D_ClearSubScreen(char *p);
extern void POKETRADE_SAVE_CloseMessageWindowClear(char *p);
extern void POKETRADE_NEGO_SetOfferMarkersState(void *,int);
extern void POKETRADE_2D_FadePaletteAll(void *,int);
extern void POKETRADE_PROC_UpdateTouchbarButtons(char *p);
extern void POKETRADE_2D_SetupSubBlend(void *);
extern void POKETRADE_2D_DeleteCursorActor(void *);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_PROC_StepCloseSubScreenDone(void *);
void POKETRADE_PROC_StepExitSubScreen(void *p)
{
    BG_SYS_SetSubVisiblePlanes(0x1a);
    POKETRADE_2D_ClearSubScreen(p);
    POKETRADE_SAVE_CloseMessageWindowClear(p);
    *(volatile unsigned *)0x04001000 &= 0xffff1fff;
    POKETRADE_NEGO_SetOfferMarkersState(p,1);
    POKETRADE_2D_FadePaletteAll(p,0);
    POKETRADE_PROC_UpdateTouchbarButtons(p);
    POKETRADE_2D_SetupSubBlend(p);
    POKETRADE_2D_DeleteCursorActor(p);
    POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepCloseSubScreenDone);
}
