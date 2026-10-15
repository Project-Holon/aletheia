/*
 * function: INTRUDE_COMM_GetSessionElapsed
 * address: 0x02175894
 * packet: pkt_ov011_02175894
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GF_STANDARD_GetTime 0x0203F4FC arm
 */
#include "../include/Obj19190.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 GF_STANDARD_GetTime(void);
int INTRUDE_COMM_GetSessionElapsed(u8 *p)
{
    u32 now = GF_STANDARD_GetTime();
    u32 stamp = ((struct Obj19190 *)p)->f190;
    if (now < stamp) now += 86400;
    return now - stamp;
}
