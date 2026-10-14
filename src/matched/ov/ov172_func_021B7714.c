/*
 * function: CTVT_CAMVIEW_MarkWindowDirty
 * address: 0x021B7714
 * packet: pkt_ov172_021B7714
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj24069.h"
typedef unsigned char u8;
void CTVT_CAMVIEW_MarkWindowDirty(void *a, char *b, int c)
{
    ((struct Obj24069 *)b)->f10 |= (u8)(1 << c);
}
