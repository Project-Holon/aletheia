/*
 * function: func_021E84F8
 * address: 0x021E84F8
 * packet: pkt_ov177_021E84F8
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 */
#include "../include/Obj10713.h"
typedef unsigned int   u32;
struct Descriptor;
struct PrintSys;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
int func_021E84F8(char *p, void *q)
{
 int result=1;
 unsigned i;
 for(i=0;(int)i<6;i++) {
 if(*(void **)(p+i*4+0x68)!=0) {
 unsigned char *e=(unsigned char *)p+i*8;
 if(e[0x84]!=0) {
 if(PRINTSYS_QUE_IsExistTarget(q,BMP_WIN_GetBmp(((struct Obj10713 *)e)->f80))==0) {
 BMP_WIN_TransferChars(*(void **)((unsigned)p+(int)i*8+0x80));*(unsigned char *)((unsigned)p+(int)i*8+0x84)=0;
 }
 }
 result &= e[0x84]==0;
 }
 }
 return result;
}
