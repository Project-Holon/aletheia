/*
 * function: PMS_INPUT_VIEW_TaskScrollWordwin
 * address: 0x021BA9D0
 * packet: pkt_ov110_021BA9D0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero alignment padding.
 * symbols:
 *   PMS_INPUT_GetScrollDelta 0x021BF7A0 thumb ov110
 *   PMSIV_WORDWIN_Scroll 0x021BFCA4 thumb ov110
 *   PMSIV_WORDWIN_UpdateScroll 0x021BFD60 thumb ov110
 *   PMS_INPUT_VIEW_EndTask 0x021B9CBC thumb ov110
 */
#include "../include/Obj10266.h"
#include "../include/Obj10267.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int PMS_INPUT_GetScrollDelta(u8 *);
extern void PMSIV_WORDWIN_Scroll(u8 *, int);
extern int PMSIV_WORDWIN_UpdateScroll(u8 *);
extern void PMS_INPUT_VIEW_EndTask(u8 *);
void PMS_INPUT_VIEW_TaskScrollWordwin(void *unused, u8 *p)
{
    u8 *q;
    q = *(u8 * *)&((struct Obj10266 *)p)->f0;
    switch (((struct Obj10266 *)p)->f14) {
    case 0:
        PMSIV_WORDWIN_Scroll(*(u8 * *)&((struct Obj10267 *)q)->f5C, PMS_INPUT_GetScrollDelta(*(u8 * *)&((struct Obj10267 *)q)->f18));
        (((struct Obj10266 *)p)->f14)++;
        break;
    case 1:
        if (PMSIV_WORDWIN_UpdateScroll(*(u8 * *)&((struct Obj10267 *)q)->f5C)) PMS_INPUT_VIEW_EndTask(p);
        break;
    }
}
