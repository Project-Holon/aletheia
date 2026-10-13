/*
 * function: IRC_RHYTHM_UpdateTextWindow
 * address: 0x021B7EE4
 * packet: pkt_ov104_021B7EE4
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow compiled code.
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 */
#include "../include/Obj06372.h"
#include "../include/Obj22224.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;
struct PrintSys;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *);
int IRC_RHYTHM_UpdateTextWindow(u8 *p,u8 *q) { void *v; v=((struct Obj22224 *)q)->f8; if(p[8]) { if(!PRINTSYS_QUE_IsExistTarget(v,BMP_WIN_GetBmp(((struct Obj06372 *)p)->f4))) { BMP_WIN_TransferChars(*(struct Descriptor * *)&((struct Obj06372 *)p)->f4); p[8]=0; } } if(!p[8]) return 1; return 0; }
