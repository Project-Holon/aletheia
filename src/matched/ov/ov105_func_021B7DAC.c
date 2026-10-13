/*
 * function: func_021B7DAC
 * address: 0x021B7DAC
 * packet: pkt_ov105_021B7DAC
 * region: ov105
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
#include "../include/Obj06374.h"
#include "../include/Obj22248.h"
struct Descriptor; struct PrintSys; extern void *BMP_WIN_GetBmp(struct Descriptor *); extern unsigned int PRINTSYS_QUE_IsExistTarget(struct PrintSys *,void *); extern void BMP_WIN_TransferChars(struct Descriptor *);
int func_021B7DAC(unsigned char *p,unsigned char *q) { struct PrintSys *s; s=*(struct PrintSys * *)&((struct Obj22248 *)q)->f8; if(p[8]) { if(!PRINTSYS_QUE_IsExistTarget(s,BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj06374 *)p)->f4))) { BMP_WIN_TransferChars(*(struct Descriptor * *)&((struct Obj06374 *)p)->f4); p[8]=0; } } if(!p[8]) return 1; return 0; }
