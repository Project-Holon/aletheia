/*
 * function: BR_RES_GetWordSet
 * address: 0x021FC21C
 * packet: pkt_ov186_021FC21C
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * trailing: two zero padding bytes at 021FC222, then existing matched 021FC224.
 */
#include "../include/Obj24831.h"
int BR_RES_GetWordSet(char *p)
{
    return ((struct Obj24831 *)p)->fF0;
}
