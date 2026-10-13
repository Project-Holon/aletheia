/*
 * function: DOWSING_IsTargetAvailable
 * address:  0x021EFEEC
 * packet:   pkt_ov033_021EFEEC
 * region:   ov033
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ZONEDATA_CheckEventFlag 0x020142E8 thumb
 *   INTRUDE_FindOfferSlotAt 0x021CFAC0 thumb ov021
 */
#include "../include/Obj07642.h"
#include "../include/Obj13070.h"

typedef signed int     s32;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 ZONEDATA_CheckEventFlag(void *bitmap, s32 id);
extern int INTRUDE_FindOfferSlotAt(u8 *base, int a, int b, int c, int d);

int DOWSING_IsTargetAvailable(char *p, int *q)
{
    int r;
    if (q[0] == 1) {
        unsigned short *s = *(unsigned short * *)&((struct Obj07642 *)q)->f4;
        return ZONEDATA_CheckEventFlag((void *)(((struct Obj13070 *)p)->f0), (unsigned short)(*s + 0x384)) == 0;
    }
    if (q[0] == 2) {
        short *s = *(short * *)&((struct Obj07642 *)q)->f8;
        r = 0;
        if (INTRUDE_FindOfferSlotAt((u8 *)(((struct Obj13070 *)p)->f8), (unsigned short)s[3], s[0], s[1], s[2]) != 0xFF)
            r = 1;
        return r;
    }
    return 0;
}
