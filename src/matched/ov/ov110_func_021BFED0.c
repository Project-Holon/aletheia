/*
 * function: PMSIV_WORDWIN_ClearRows
 * address: 0x021BFED0
 * packet: pkt_ov110_021BFED0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of alignment padding follow the return.
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_FillRect 0x02043AF4 arm
 */
#include "../include/Obj06392.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
typedef unsigned int   u32;
struct Bmp;
extern void BMP_FillRect(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
void PMSIV_WORDWIN_ClearRows(u8 *p,int amount) {
    int start,end;
    if(amount>0) {
        start=(u8)(((struct Obj06392 *)p)->f94+192);
        end=(u8)(start+24*amount);
    } else {
        end=((struct Obj06392 *)p)->f94;
        start=(u8)(end+24*amount);
    }
    if(start<end) {
        BMP_FillRect(BMP_WIN_GetBmp((struct Descriptor *)((struct Obj06392 *)p)->fC),(s16)0,(s16)start,(u16)208,(u16)(end-start),(u8)0);
    } else {
        BMP_FillRect(BMP_WIN_GetBmp((struct Descriptor *)((struct Obj06392 *)p)->fC),(s16)0,(s16)start,(u16)208,(u16)(256-start),(u8)0);
        BMP_FillRect(BMP_WIN_GetBmp((struct Descriptor *)((struct Obj06392 *)p)->fC),(s16)0,(s16)0,(u16)208,(u16)end,(u8)0);
    }
}
