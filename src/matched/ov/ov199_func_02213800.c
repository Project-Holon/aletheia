/*
 * function: WIFIBATTLEMATCH_SYS_GetResult
 * address: 0x02213800
 * packet: pkt_ov199_02213800
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj25299.h"
int WIFIBATTLEMATCH_SYS_GetResult(char *p)
{
    return ((struct Obj25299 *)p)->f1C;
}
