/*
 * function: func_021BA058
 * address: 0x021BA058
 * packet: pkt_ov214_021BA058
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Tail: two zero alignment bytes at 021BA072.
 * symbols:
 *   TCBL_Main 0x020310C4 arm
 *   func_02035630 0x02035630 arm
 */
#include "../include/Obj14699.h"
struct Tcbl;
extern void TCBL_Main(struct Tcbl *);
typedef unsigned char  u8;
extern u8 func_02035630(void);
void func_021BA058(int unused,char *p){TCBL_Main(*(struct Tcbl * *)&((struct Obj14699 *)p)->f68);if(func_02035630()==30)TCBL_Main(*(struct Tcbl * *)&((struct Obj14699 *)p)->f68);}
