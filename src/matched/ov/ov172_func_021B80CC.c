/*
 * function: CTVT_COMM_IsSessionEnded
 * address: 0x021B80CC
 * packet: pkt_ov172_021B80CC
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 */
#include "../include/Obj24075.h"
typedef unsigned char u8;
typedef unsigned int u32;
u32 CTVT_COMM_IsSessionEnded(int unused, char *p)
{
    if (((struct Obj24075 *)p)->f8 == 12)
        return 1;
    return 0;
}
