/*
 * function: DWC_RAP_GetNewClientAid
 * address:  0x02156B8C
 * packet:   pkt_02156B8C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Recursive MATCH unblocker: callee of WIFICLUB_HasNewClientAid (ov099) +0002. Coherent
 * Thumb code only in ov009 (ov010 holds the tail of another function), so the
 * ov009 shard makes that site attest as `matched`.
 *
 * symbols:
 *   g_021A8264  0x021A8264  data  ov009
 */
#include "../include/Obj18652.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int g_021A8264;

int DWC_RAP_GetNewClientAid(void)
{
    int *p = (int *)g_021A8264;

    if (p != 0)
        return ((struct Obj18652 *)p)->f774;
    return 0;
}
