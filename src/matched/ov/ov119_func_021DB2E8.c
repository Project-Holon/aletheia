/*
 * function: func_021DB2E8
 * address: 0x021DB2E8
 * packet: pkt_ov119_021DB2E8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_2D_ClearCursorIfDisabled 0x021E707C thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   func_021DB290 0x021DB290 thumb ov119
 */
extern int POKETRADE_2D_ClearCursorIfDisabled(void *);
extern void POKETRADE_PROC_SetStep(void *,int),func_021DB290(void *);
void func_021DB2E8(void *p) {
 if(POKETRADE_2D_ClearCursorIfDisabled(p)==0) POKETRADE_PROC_SetStep(p,(int)func_021DB290);
}
