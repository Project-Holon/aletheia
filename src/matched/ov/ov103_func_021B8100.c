/*
 * function: func_021B8100
 * address: 0x021B8100
 * packet: pkt_ov103_021B8100
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: Two-byte zero alignment padding follows the compiled body.
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 */
#include "../include/Obj06367.h"
#include "../include/Obj22190.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *); extern int PRINTSYS_QUE_IsExistTarget(int,int); extern void BMP_WIN_TransferChars(struct Descriptor *);
int func_021B8100(u8 *p,u8 *q) {int a; a=((struct Obj22190 *)q)->f8; if(p[8]!=0) {if(PRINTSYS_QUE_IsExistTarget(a,(int)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj06367 *)p)->f4))==0) {BMP_WIN_TransferChars((struct Descriptor *)((struct Obj06367 *)p)->f4);p[8]=0;}} if(p[8]==0)return 1;return 0;}
