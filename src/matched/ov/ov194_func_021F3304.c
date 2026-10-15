/*
 * function: NAMEIN_GRAPHIC_IsGridDrawDone
 * address: 0x021F3304
 * packet: pkt_ov194_021F3304
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 */
#include "../include/Obj05512.h"
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *); extern int PRINTSYS_QUE_IsExistTarget(int,int); extern void BMP_WIN_TransferChars(struct Descriptor *d);
int NAMEIN_GRAPHIC_IsGridDrawDone(char *p) {
 int q;
 q=((struct Obj05512 *)p)->fF8;
 if(((struct Obj05512 *)p)->fF0) {
 if(PRINTSYS_QUE_IsExistTarget(q,(int)BMP_WIN_GetBmp((struct Descriptor *)*(int *)&((struct Obj05512 *)p)->fEC))==0) {
 BMP_WIN_TransferChars(((struct Obj05512 *)p)->fEC);((struct Obj05512 *)p)->fF0=0;
 }}
 if(((struct Obj05512 *)p)->fF0==0)return 1;return 0;
}
