/*
 * function: func_021BBD28
 * address: 0x021BBD28
 * packet: pkt_ov225_021BBD28
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj06736.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Descriptor;
struct Cfg;
struct PrintSys;
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p,void *value);
extern void BMP_WIN_TransferChars(struct Descriptor *p);
extern void BMP_WIN_MakeScreen(struct Cfg *p);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 channel);
void func_021BBD28(u8 *p)
{
    u8 index;
    u8 *slot;
    struct Descriptor *descriptor;
    for(index=0;index<3;index++) {
        slot=p+index*4;
        if(((struct Obj06736 *)slot)->f28!=0) {
            if(func_0201C6C4(*(struct PrintSys * *)&((struct Obj06736 *)slot)->f1C,func_02045770(*(struct Descriptor * *)&((struct Obj06736 *)slot)->f10))==0) {
                descriptor=*(struct Descriptor * *)&((struct Obj06736 *)slot)->f10;
                BMP_WIN_TransferChars(descriptor);
                BMP_WIN_MakeScreen((struct Cfg *)descriptor);
                func_02041B6C(func_02045730(descriptor));
                ((struct Obj06736 *)slot)->f28=0;
            }
        }
    }
}
