/*
 * function: func_021BA16C
 * address: 0x021BA16C
 * packet: pkt_ov214_021BA16C
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA190 0x021BA190 thumb ov214
 *   func_02035630 0x02035630 arm
 */
typedef unsigned char  u8;
extern int func_021BA190(int,char *);
extern u8 func_02035630(void);
int func_021BA16C(int a,char *p){int result=func_021BA190(a,p);if(result==0){if(func_02035630()==30)result=func_021BA190(a,p);}return result;}
