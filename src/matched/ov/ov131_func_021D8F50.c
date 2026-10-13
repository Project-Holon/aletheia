/*
 * function: P_STA_RIBBON_Init
 * address: 0x021D8F50
 * packet: pkt_ov131_021D8F50
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   P_STA_RIBBON_GetRowOwnedIndex 0x021D9428 thumb ov131
 *   P_STA_RIBBON_DrawRow 0x021D91F0 thumb ov131
 */
#include "../include/Obj02845.h"

typedef unsigned char  u8;
extern unsigned int P_STA_RIBBON_GetRowOwnedIndex(unsigned char *p, unsigned int target);
extern void P_STA_RIBBON_DrawRow(u8 *a, u8 *p, u8 *entry);
void P_STA_RIBBON_Init(void *a, unsigned char *p)
{
    unsigned char i;
    p[0x58]=255;
    p[0x59]=255;
    p[0x5a]=255;
    ((struct Obj02845 *)p)->f14=0;
    ((struct Obj02845 *)p)->f0=1;
    ((struct Obj02845 *)p)->f4=0;
    ((struct Obj02845 *)p)->f8=0;
    ((struct Obj02845 *)p)->fC=1;
    ((struct Obj02845 *)p)->f20=0;
    ((struct Obj02845 *)p)->f24=0;
    for(i=0;i<10;i++) {
        *(unsigned short *)(p+i*20+0x70)=P_STA_RIBBON_GetRowOwnedIndex(p,i);
        P_STA_RIBBON_DrawRow(a,p,p+0x70+i*20);
    }
}
