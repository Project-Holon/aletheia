/*
 * function: func_021EAB50
 * address: 0x021EAB50
 * packet: pkt_ov170_021EAB50
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 */
#include "../include/Obj08242.h"
#define WORK(p) (*(char **)((p)+0x2C))
typedef unsigned int   u32;
struct Descriptor;
struct PrintSys;
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
void func_021EAB50(unsigned char *w) {
 unsigned i; void *print;
 PRINTSYS_QUE_Main(((struct Obj08242 *)w)->f8C);
 for(i=0;i<28;i++) {
  print=((struct Obj08242 *)w)->f8C;
  if(w[0x98+i*8]) {
   if(PRINTSYS_QUE_IsExistTarget(print,BMP_WIN_GetBmp(*(void **)(w+i*8+0x94)))==0) {
    BMP_WIN_TransferChars(*(void **)(w+i*8+0x94));
    w[0x98+i*8]=0;
   }
  }
 }
}
