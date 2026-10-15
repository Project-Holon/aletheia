/*
 * function: MANUAL_CATEGORY_UpdateOptionSlots
 * address: 0x021BBD28
 * packet: pkt_ov225_021BBD28
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj06736.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Descriptor;
struct Cfg;
struct PrintSys;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p,void *value);
extern void BMP_WIN_TransferChars(struct Descriptor *p);
extern void BMP_WIN_MakeScreen(struct Cfg *p);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32 channel);
void MANUAL_CATEGORY_UpdateOptionSlots(u8 *p)
{
    u8 index;
    u8 *slot;
    struct Descriptor *descriptor;
    for(index=0;index<3;index++) {
        slot=p+index*4;
        if(((struct Obj06736 *)slot)->f28!=0) {
            if(PRINTSYS_QUE_IsExistTarget(*(struct PrintSys * *)&((struct Obj06736 *)slot)->f1C,BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj06736 *)slot)->f10))==0) {
                descriptor=*(struct Descriptor * *)&((struct Obj06736 *)slot)->f10;
                BMP_WIN_TransferChars(descriptor);
                BMP_WIN_MakeScreen((struct Cfg *)descriptor);
                func_02041B6C(BMP_WIN_GetBgLayer(descriptor));
                ((struct Obj06736 *)slot)->f28=0;
            }
        }
    }
}
