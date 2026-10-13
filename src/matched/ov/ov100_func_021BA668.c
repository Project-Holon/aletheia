/*
 * function: func_021BA668
 * address: 0x021BA668
 * packet: pkt_ov100_021BA668
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA3A4 0x021BA3A4 thumb ov100
 *   func_021BA454 0x021BA454 thumb ov100
 *   func_021BA530 0x021BA530 thumb ov100
 *   GAME_DATA_GetWifiList 0x0201283C thumb
 *   func_02009A34 0x02009A34 thumb
 *   d_021BB694 0x021BB694 data a4
 *   d_021BB690 0x021BB690 data a4
 *   d_021BB670 0x021BB670 data a4
 *   d_021BB680 0x021BB680 data a4
 *   d_021BB684 0x021BB684 data a4
 *   d_021BB67C 0x021BB67C data a4
 *   d_021BB66C 0x021BB66C data a4
 *   d_021BB6A0 0x021BB6A0 data a4
 *   d_021BB698 0x021BB698 data a4
 */
#include "../include/Obj00060.h"
struct Word { int x; };
extern const struct Word d_021BB694,d_021BB690,d_021BB670,d_021BB680,d_021BB684,d_021BB67C,d_021BB66C,d_021BB6A0,d_021BB698;
extern void func_021BA3A4(struct Word *,int),func_021BA454(int,int),func_021BA530(int,int);
typedef unsigned int   u32;
struct BigObj;
struct Sub020097BCObj;
extern u32 GAME_DATA_GetWifiList(const struct BigObj *p);
extern u32 func_02009A34(struct Sub020097BCObj *obj);
void func_021BA668(int a) {
 if(((struct Obj00060 *)a)->fCA0==1) {struct Word t=d_021BB694;func_021BA3A4(&t,a);return;}
 if(((struct Obj00060 *)a)->f24C==7) {
  if(func_02009A34((struct Sub020097BCObj *)GAME_DATA_GetWifiList((const struct BigObj *)(**(int * *)&((struct Obj00060 *)a)->f244)))==32) {struct Word t=d_021BB690;func_021BA3A4(&t,a);return;}
  else {struct Word t=d_021BB670;func_021BA3A4(&t,a);func_021BA454(0x22,a);return;}
 }
 if(((struct Obj00060 *)a)->f24C==6) {struct Word t=d_021BB680;func_021BA3A4(&t,a);return;}
 if(((struct Obj00060 *)a)->f24C==5) {struct Word t=d_021BB684;func_021BA3A4(&t,a);return;}
 if(((struct Obj00060 *)a)->f24C==9) {struct Word t=d_021BB67C;func_021BA3A4(&t,a);func_021BA530(0x27,a);return;}
 if(((struct Obj00060 *)a)->f24C==10) {struct Word t=d_021BB66C;func_021BA3A4(&t,a);return;}
 if(((struct Obj00060 *)a)->f24C==11) {struct Word t=d_021BB6A0;func_021BA3A4(&t,a);return;}
 else {struct Word t=d_021BB698;func_021BA3A4(&t,a);return;}
}
