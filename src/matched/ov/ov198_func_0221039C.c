/*
 * function: B_PLIST_MAIN_CheckBusyFlag
 * address: 0x0221039C
 * packet: pkt_ov198_0221039C
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:

 */
#include "../include/Obj25236.h"
typedef unsigned char u8;
struct Flag {u8 low:7;u8 bit:1;};
int B_PLIST_MAIN_CheckBusyFlag(char *p)
{
    if (((struct Flag *)(p+0x1e9b))->bit==0) return ((struct Obj25236 *)p)->f217C;
    return 0x1d;
}
