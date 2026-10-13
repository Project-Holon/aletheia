/*
 * function: ISS_ROAD_SYS_Update
 * address:  0x0202B1F4
 * packet:   pkt_0202B1F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * A bare tail-call thunk to ISS_ROAD_SYS_UpdateVolume.

 * Closed by the `matched` class: 0x0202B230 was filed as an EXACT entry in this wave.
 *
 * symbols:
 *   ISS_ROAD_SYS_UpdateVolume  0x0202B230  thumb
 */

typedef unsigned char  u8;
extern void ISS_ROAD_SYS_UpdateVolume(u8 *p);

void ISS_ROAD_SYS_Update(u8 *a0)
{
    ISS_ROAD_SYS_UpdateVolume(a0);
}
