/*
 * function: func_021D9E50
 * address: 0x021D9E50
 * packet: pkt_ov121_021D9E50
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two trailing zero padding bytes at 0x021D9F06.
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   TCBL_Main 0x020310C4 arm
 *   APP_KEYCURSOR_Update  0x020286C4  thumb  arm9
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb  arm9
 *   PRINTSYS_CTRL_Update  0x02028484  thumb  arm9
 */
#include "../include/Obj00909.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
typedef signed int     s32;
struct Blk;
struct Ctx;
struct PrintSys;
struct Tcbl;
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void APP_KEYCURSOR_Update(struct Ctx *ctx, void *p, void *cell);
extern s32 PRINTSYS_CTRL_Update(struct Blk *blk, void *h);
extern void TCBL_Main(struct Tcbl *p);
void func_021D9E50(u8 *p)
{
    u32 q;
    switch (((struct Obj00909 *)p)->f28) {
    case 2:
        q = ((struct Obj00909 *)p)->f24;
        if (p[0x20]) {
            if (PRINTSYS_QUE_IsExistTarget((struct PrintSys *)q, (void *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj00909 *)p)->f1C))) == 0) {
                BMP_WIN_TransferChars((struct Descriptor *)((struct Obj00909 *)p)->f1C);
                p[0x20] = 0;
            }
        }
        break;
    case 0:
        q = ((struct Obj00909 *)p)->f24;
        if (p[0x20]) {
            if (PRINTSYS_QUE_IsExistTarget((struct PrintSys *)q, (void *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj00909 *)p)->f1C))) == 0) {
                BMP_WIN_TransferChars((struct Descriptor *)((struct Obj00909 *)p)->f1C);
                p[0x20] = 0;
            }
        }
        ((struct Obj00909 *)p)->f2C = p[0x20] == 0 ? 1 : 0;
        break;
    case 1:
        if (((struct Obj00909 *)p)->f8) {
            if (((struct Obj00909 *)p)->f30)
                APP_KEYCURSOR_Update((struct Ctx *)(((struct Obj00909 *)p)->f30), (void *)(((struct Obj00909 *)p)->f8), (void *)(((struct Obj00909 *)p)->f10));
            if (PRINTSYS_CTRL_Update((struct Blk *)(p + 0x34), (void *)(((struct Obj00909 *)p)->f8)))
                ((struct Obj00909 *)p)->f2C = 1;
        }
        break;
    case 3:
        break;
    }
    TCBL_Main((struct Tcbl *)(((struct Obj00909 *)p)->fC));
}
