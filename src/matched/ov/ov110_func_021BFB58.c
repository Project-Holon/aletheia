/*
 * function: PMSIV_WORDWIN_IsOpen
 * address: 0x021BFB58
 * packet: pkt_ov110_021BFB58
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: two trailing zero alignment bytes.
 * symbols:
 *   PMSIV_FADE_IsBlendDone 0x021BC898 thumb ov110
 */
#include "../include/Obj22402.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int PMSIV_FADE_IsBlendDone(u8 *p);
int PMSIV_WORDWIN_IsOpen(u8 *p) {
    if(((struct Obj22402 *)p)->f88==0) {
        if(PMSIV_FADE_IsBlendDone(p+0x4c)) return 1;
        else return 0;
    } else return 1;
}
