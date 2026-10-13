/*
 * function: PMSIV_WORDWIN_DrawList
 * address: 0x021BF9F0
 * packet: pkt_ov110_021BF9F0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   PMSIV_WORDWIN_ResetScroll 0x021BFF60 thumb ov110
 *   PMSIV_WORDWIN_DrawCell 0x021BFF7C thumb ov110
 *   PMS_INPUT_GetListItemCount 0x021BF734 thumb ov110
 */
#include "../include/Obj02166.h"
typedef unsigned char u8;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void PMSIV_WORDWIN_ResetScroll(u8 *);
extern void PMSIV_WORDWIN_DrawCell(u8 *,unsigned,unsigned);
extern unsigned PMS_INPUT_GetListItemCount(u8 *);
void PMSIV_WORDWIN_DrawList(u8 *p) {
    unsigned y,i,n;
    BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)((struct Obj02166 *)p)->fC),0);
    PMSIV_WORDWIN_ResetScroll(p);
    n=PMS_INPUT_GetListItemCount(*(u8 * *)&((struct Obj02166 *)p)->f4);
    if(n>16) n=16;
    i=0;
    y=((struct Obj02166 *)p)->f94;
    for(;i<n;i++) {
        PMSIV_WORDWIN_DrawCell(p,i,y);
        if(i&1) y+=24;
    }
    BMP_WIN_TransferChars((struct Descriptor *)((struct Obj02166 *)p)->fC);
}
