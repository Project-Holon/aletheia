/*
 * function: WIFIBATTLEMATCH_SYS_GetKind
 * address: 0x02213804
 * packet: pkt_ov199_02213804
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj25300.h"
unsigned char WIFIBATTLEMATCH_SYS_GetKind(char *p)
{
    return ((struct Obj25300 *)p)->f18;
}
