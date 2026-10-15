/*
 * function: func_0220B6C4
 * address: 0x0220B6C4
 * packet: pkt_ov197_0220B6C4
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   B_BAG_MAIN_PrintLabel 0x0220B1D4 thumb ov197
 */
#include "../include/Obj00314.h"
#include "../include/Obj25004.h"
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
typedef unsigned char  u8;
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void B_BAG_MAIN_PrintLabel(char *,int,int,int,unsigned short);
void func_0220B6C4(char *p)
{
    BMP_Clear((struct CharBuf *)((int)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj00314 *)p)->f110)),0);
    if(((struct Obj25004 *)(*(char * *)&((struct Obj00314 *)p)->f0))->f8!=1) {
        switch(((unsigned char *)p)[0x533]) {
        case 0:B_BAG_MAIN_PrintLabel(p,29,22,4,0x3c40);B_BAG_MAIN_PrintLabel(p,29,23,20,0x3c40);break;
        case 1:B_BAG_MAIN_PrintLabel(p,29,24,4,0x3c40);B_BAG_MAIN_PrintLabel(p,29,25,20,0x3c40);break;
        case 2:B_BAG_MAIN_PrintLabel(p,29,26,12,0x3c40);break;
        case 3:B_BAG_MAIN_PrintLabel(p,29,27,12,0x3c40);break;
        }
    } else BMP_WIN_TransferChars((struct Descriptor *)((struct Obj00314 *)p)->f110);
}
