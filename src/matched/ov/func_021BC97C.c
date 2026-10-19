/*
 * function: ZUKAN_DETAIL_COMMON_FreeBgPalette
 * address:  0x021BC97C
 * packet:   pkt_021BC97C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BG_SYS_FreeTileRun  0x0203FB44  arm  arm9
 *   (none)

 * Passes the byte at +4 and the two halfwords of the word at +0 on, then re-inits the object.
 */
#include "../include/Obj12112.h"


typedef unsigned int   u32;
extern void BG_SYS_FreeTileRun(u32 layer, u32 offset, u32 size);
extern u32 func_020307B0(void *p);

void ZUKAN_DETAIL_COMMON_FreeBgPalette(char *p)
{
    unsigned int w;

    w = ((struct Obj12112 *)p)->f0;
    BG_SYS_FreeTileRun(((struct Obj12112 *)p)->f4, (unsigned short)w, (unsigned short)(w >> 16));
    func_020307B0((void *)((int)p));
}

