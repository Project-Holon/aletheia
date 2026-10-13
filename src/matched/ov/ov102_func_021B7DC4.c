/*
 * function: func_021B7DC4
 * address: 0x021B7DC4
 * packet: pkt_ov102_021B7DC4
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 */
#include "../include/Obj06365.h"
#include "../include/Obj22147.h"
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *); extern int PRINTSYS_QUE_IsExistTarget(int,int); extern void BMP_WIN_TransferChars(struct Descriptor *);
int func_021B7DC4(unsigned char *p,unsigned char *q) { int a=((struct Obj22147 *)q)->f8; if (p[8]) { if (!PRINTSYS_QUE_IsExistTarget(a,(int)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj06365 *)p)->f4))) { BMP_WIN_TransferChars((struct Descriptor *)((struct Obj06365 *)p)->f4); p[8]=0; } } if (!p[8]) return 1; return 0; }
