/*
 * function: func_021BA4E8
 * address: 0x021BA4E8
 * packet: pkt_ov214_021BA4E8
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes zero alignment at 021BA5C6.
 * lever: indexed struct members keep the fixed field offset inside the loop;
 *   raw pointer form was DIFF236/217, integer form DIFF222/66.
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj01588.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Descriptor; struct PrintSys;
struct S { u8 pad[0x8C]; struct Descriptor *descriptors[2]; struct Descriptor *other1,*other2; u32 flags[2]; };
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *,void *);
extern void BMP_WIN_TransferChars(struct Descriptor *);
struct Cfg;
extern void BMP_WIN_MakeScreen(struct Cfg *);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *);
extern void func_02041B6C(u32);
void func_021BA4E8(void *unused,struct S *p)
{
    u8 i;
    struct Descriptor *d;
    for (i=0;i<=1;i++) {
        if (p->flags[i]==0) {
            if (PRINTSYS_QUE_IsExistTarget(*(struct PrintSys * *)&((struct Obj01588 *)p)->f10,BMP_WIN_GetBmp(p->descriptors[i]))==0) {
                d=p->descriptors[i];
                BMP_WIN_TransferChars(d);
                BMP_WIN_MakeScreen((struct Cfg *)d);
                func_02041B6C(BMP_WIN_GetBgLayer(d));
                p->flags[i]=1;
            }
        }
    }
    if (((struct Obj01588 *)p)->fA4==0) {
        if (PRINTSYS_QUE_IsExistTarget(*(struct PrintSys * *)&((struct Obj01588 *)p)->f14,BMP_WIN_GetBmp(p->other1))==0) {
            d=p->other1;
            BMP_WIN_TransferChars(d);
            BMP_WIN_MakeScreen((struct Cfg *)d);
            func_02041B6C(BMP_WIN_GetBgLayer(d));
            ((struct Obj01588 *)p)->fA4=1;
        }
    }
    if (((struct Obj01588 *)p)->fA8==0) {
        if (PRINTSYS_QUE_IsExistTarget(*(struct PrintSys * *)&((struct Obj01588 *)p)->f18,BMP_WIN_GetBmp(p->other2))==0) {
            d=p->other2;
            BMP_WIN_TransferChars(d);
            BMP_WIN_MakeScreen((struct Cfg *)d);
            func_02041B6C(BMP_WIN_GetBgLayer(d));
            ((struct Obj01588 *)p)->fA8=1;
        }
    }
}
