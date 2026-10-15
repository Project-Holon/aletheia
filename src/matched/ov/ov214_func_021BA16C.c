/*
 * function: BTL_REC_SEL_WaitPrint
 * address: 0x021BA16C
 * packet: pkt_ov214_021BA16C
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_REC_SEL_PrintStep 0x021BA190 thumb ov214
 *   func_02035630 0x02035630 arm
 */
typedef unsigned char  u8;
extern int BTL_REC_SEL_PrintStep(int,char *);
extern u8 func_02035630(void);
int BTL_REC_SEL_WaitPrint(int a,char *p){int result=BTL_REC_SEL_PrintStep(a,p);if(result==0){if(func_02035630()==30)result=BTL_REC_SEL_PrintStep(a,p);}return result;}
