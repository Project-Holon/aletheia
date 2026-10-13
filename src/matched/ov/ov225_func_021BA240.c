/*
 * function: func_021BA240
 * address: 0x021BA240
 * packet: pkt_ov225_021BA240
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj26151.h"
#include "../include/Obj26152.h"
typedef unsigned char u8;
struct Descriptor;
struct Cfg;
struct PrintSys;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern unsigned PRINTSYS_QUE_IsExistTarget(struct PrintSys *,void *);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void BMP_WIN_MakeScreen(struct Cfg *);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *);
extern void func_02041B6C(unsigned);
void func_021BA240(char *p)
{
    u8 i;
    for(i=0;i<2;i++) {
        if(*(unsigned *)(p+i*4+0x18)!=0) {
            if(PRINTSYS_QUE_IsExistTarget(*(struct PrintSys * *)&((struct Obj26152 *)(*(char * *)&((struct Obj26151 *)p)->f0))->f18,BMP_WIN_GetBmp(*(struct Descriptor **)(p+i*4+0x10)))==0) {
                struct Descriptor *d=*(struct Descriptor **)(p+i*4+0x10);
                BMP_WIN_TransferChars(d);BMP_WIN_MakeScreen((struct Cfg *)d);
                func_02041B6C(BMP_WIN_GetBgLayer(d));
                *(unsigned *)(p+i*4+0x18)=0;
            }
        }
    }
}
