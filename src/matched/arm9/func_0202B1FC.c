/*
 * function: ISS_ROAD_SYS_Start
 * address:  0x0202B1FC
 * packet:   pkt_0202B1F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A bare tail-call thunk to ISS_ROAD_SYS_Activate.
 *
 * symbols:
 *   ISS_ROAD_SYS_Activate  0x0202B20C  thumb
 */

typedef unsigned char  u8;
extern void ISS_ROAD_SYS_Activate(u8 *p);

void ISS_ROAD_SYS_Start(u8 *a0)
{
    ISS_ROAD_SYS_Activate(a0);
}
