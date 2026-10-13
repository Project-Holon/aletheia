/*
 * function: PMSIV_WORDWIN_StartClose
 * address: 0x021BFB7C
 * packet: pkt_ov110_021BFB7C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: two trailing zero alignment bytes.
 * symbols:
 *   PMSIV_FADE_StartBlend 0x021BC868 thumb ov110
 */
#include "../include/Obj22403.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void PMSIV_FADE_StartBlend(u8 *p, int a, int b, int start, int end, int frames);
void PMSIV_WORDWIN_StartClose(u8 *p) {
    ((struct Obj22403 *)p)->f88=0;
    PMSIV_FADE_StartBlend(p+0x4c,4,63,124,0,12);
}
