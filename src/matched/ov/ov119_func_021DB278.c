/*
 * function: func_021DB278
 * address: 0x021DB278
 * packet: pkt_ov119_021DB278
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   func_021DBE70 0x021DBE70 thumb ov119
 */
extern void BG_SYS_SetSubVisiblePlanes(unsigned);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void func_021DBE70(char *p);
void func_021DB278(void *p) {
 BG_SYS_SetSubVisiblePlanes(30);
 POKETRADE_PROC_SetStep(p,(int)func_021DBE70);
}
