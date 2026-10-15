/*
 * function: CTVT_MIC_OnVBlank
 * address: 0x021BA098
 * packet: pkt_ov172_021BA098
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: 36 bytes; next instruction at 021BA0BC belongs to separate owned lead.
 * evidence: Singleton pointer re-read at 021BA0AA after stores to its object.
 * symbols:
 *   gCtvtMic 0x021C88EC data a4
 */
#include "../include/Obj08260.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void *gCtvtMic;
void CTVT_MIC_OnVBlank(void)
{
    u8 *p = gCtvtMic;
    if (((struct Obj08260 *)p)->fC == 1) (((struct Obj08260 *)p)->f14)++;
    p = gCtvtMic;
    if (p[16] < 180) p[16]++;
}
