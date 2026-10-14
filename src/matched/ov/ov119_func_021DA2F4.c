/*
 * function: func_021DA2F4
 * address: 0x021DA2F4
 * packet: pkt_ov119_021DA2F4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   func_021DBE70 0x021DBE70 thumb ov119
 */
typedef unsigned int   u32;
extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void func_021DBE70(char *p);
void func_021DA2F4(void *p) {
 int a,b;
 if(!TOUCHPANEL_GetPointCont((u32 *)(&a),(u32 *)(&b))) POKETRADE_PROC_SetStep(p,(int)func_021DBE70);
}
