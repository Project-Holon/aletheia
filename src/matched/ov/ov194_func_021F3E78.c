/*
 * function: NAMEIN_GRAPHIC_IsMsgDrawDone
 * address: 0x021F3E78
 * packet: pkt_ov194_021F3E78
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
#include "../include/Obj05513.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct PrintSys;
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
struct Descriptor;
extern void BMP_WIN_TransferChars(struct Descriptor *d);
int NAMEIN_GRAPHIC_IsMsgDrawDone(u8 *p) {int window;window=((struct Obj05513 *)p)->f10;if(p[12]) {if(PRINTSYS_QUE_IsExistTarget((struct PrintSys *)window,(void *)((int)BMP_WIN_GetBmp((struct Descriptor *)*(int *)&((struct Obj05513 *)p)->f8)))==0) {BMP_WIN_TransferChars(((struct Obj05513 *)p)->f8);p[12]=0;}}if(!p[12]) return 1;return 0;}
