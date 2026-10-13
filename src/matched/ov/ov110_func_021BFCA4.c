/*
 * function: PMSIV_WORDWIN_Scroll
 * address: 0x021BFCA4
 * packet: pkt_ov110_021BFCA4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of alignment padding follow the return.
 * symbols:
 *   PMSIV_WORDWIN_ClearRows 0x021BFED0 thumb ov110
 *   PMS_INPUT_GetListItemCount 0x021BF734 thumb ov110
 *   PMSIV_WORDWIN_DrawCell 0x021BFF7C thumb ov110
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   PMSIV_BGSCROLL_Start 0x021BC78C thumb ov110
 */
#include "../include/Obj03756.h"
typedef unsigned char u8;
extern void PMSIV_WORDWIN_ClearRows(u8 *,int);
extern unsigned PMS_INPUT_GetListItemCount(u8 *);
extern void PMSIV_WORDWIN_DrawCell(u8 *,unsigned,unsigned);
struct Descriptor;
extern void BMP_WIN_TransferChars(struct Descriptor *);
struct Cfg;
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void PMSIV_BGSCROLL_Start(u8 *,int,int,int,int);
void PMSIV_WORDWIN_Scroll(u8 *p,int amount) {
    int count,i;
    u8 newy;
    int newstart,start,step;
    u8 y;
    PMSIV_WORDWIN_ClearRows(p,amount);
    count=amount*2;
    start=((struct Obj03756 *)p)->f98;
    newstart=start+count;
    step=24*amount;
    newy=(u8)(((struct Obj03756 *)p)->f94+step);
    if(amount<0) {
        start=newstart;
        y=newy;
        count=-count;
        amount=-amount;
    } else {
        y=(u8)(((struct Obj03756 *)p)->f94+192);
        start+=16;
        if(count+start>PMS_INPUT_GetListItemCount(*(u8 * *)&((struct Obj03756 *)p)->f4)) count--;
    }
    for(i=0;i<count;i++) {
        PMSIV_WORDWIN_DrawCell(p,start+i,y);
        if(i&1) y+=24;
    }
    ((struct Obj03756 *)p)->f94=newy;
    ((struct Obj03756 *)p)->f98=newstart;
    BMP_WIN_TransferChars((struct Descriptor *)((struct Obj03756 *)p)->fC);
    BMP_WIN_MakeScreen((struct Cfg *)(((struct Obj03756 *)p)->fC));
    PMSIV_BGSCROLL_Start(p+0x6c,2,1,step,amount);
}
