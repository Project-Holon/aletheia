/*
 * function: func_021E867C
 * address: 0x021E867C
 * packet: pkt_ov177_021E867C
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   APP_KEYCURSOR_Update 0x020286C4 thumb
 *   PRINTSYS_CTRL_Update 0x02028484 thumb
 *   TCBL_Main 0x020310C4 arm
 */
#include "../include/Obj00842.h"
typedef unsigned int   u32;
struct Ctx;
struct Descriptor;
struct PrintSys;
struct Tcbl;
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void APP_KEYCURSOR_Update(struct Ctx *ctx, void *p, void *cell);
typedef signed int     s32;
struct Blk;
extern s32 PRINTSYS_CTRL_Update(struct Blk *blk, void *h);
extern void TCBL_Main(struct Tcbl *p);
void func_021E867C(char *p)
{
 void *q;
 PRINTSYS_QUE_Main(((struct Obj00842 *)p)->f28);
 switch(((struct Obj00842 *)p)->f2C) {
 case 2:
 q=((struct Obj00842 *)p)->f28;
 if(((struct Obj00842 *)p)->f24!=0 && PRINTSYS_QUE_IsExistTarget(q,(void *)((unsigned)BMP_WIN_GetBmp(((struct Obj00842 *)p)->f20)))==0) {
 BMP_WIN_TransferChars(((struct Obj00842 *)p)->f20);((struct Obj00842 *)p)->f24=0;
 }
 break;
 case 0:
 q=((struct Obj00842 *)p)->f28;
 if(((struct Obj00842 *)p)->f24!=0 && PRINTSYS_QUE_IsExistTarget(q,(void *)((unsigned)BMP_WIN_GetBmp(((struct Obj00842 *)p)->f20)))==0) {
 BMP_WIN_TransferChars(((struct Obj00842 *)p)->f20);((struct Obj00842 *)p)->f24=0;
 }
 ((struct Obj00842 *)p)->f30=((struct Obj00842 *)p)->f24==0;
 break;
 case 1:
 if(((struct Obj00842 *)p)->f8!=0) {
 if(((struct Obj00842 *)p)->f34!=0)APP_KEYCURSOR_Update(((struct Obj00842 *)p)->f34,((struct Obj00842 *)p)->f8,((struct Obj00842 *)p)->f14);
 if(PRINTSYS_CTRL_Update((struct Blk *)(p+0x38),((struct Obj00842 *)p)->f8)!=0)((struct Obj00842 *)p)->f30=1;
 }
 break;
 case 3:break;
 }
 TCBL_Main(((struct Obj00842 *)p)->fC);
}
