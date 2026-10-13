/*
 * function: PMSIV_WORDWIN_UpdateScroll
 * address: 0x021BFD60
 * packet: pkt_ov110_021BFD60
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMSIV_BGSCROLL_Step 0x021BC7DC thumb ov110
 *   PMS_INPUT_GetScrollRange 0x021BF7EC thumb ov110
 *   PMSIV_WORDWIN_SetThumbRow 0x021BFDB0 thumb ov110
 */
#include "../include/Obj13802.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern int PMSIV_BGSCROLL_Step(u8 *);
extern void PMS_INPUT_GetScrollRange(const u8 *,u16 *,u16 *);
extern void PMSIV_WORDWIN_SetThumbRow(u8 *,u32,u32);
int PMSIV_WORDWIN_UpdateScroll(u8 *p) { u16 x,y; if(PMSIV_BGSCROLL_Step(p+0x6c)) { PMS_INPUT_GetScrollRange(*(const u8 * *)&((struct Obj13802 *)p)->f4,&x,&y); PMSIV_WORDWIN_SetThumbRow(p,x,y); return 1; } return 0; }
