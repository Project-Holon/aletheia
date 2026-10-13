/*
 * function: AREAMAN_ClearByteRun
 * address:  0x02034394
 * packet:   pkt_02033CA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   Areaman_RunMask  0x020A048C  data
 *
 * areaman.c.  Clears a run of `len` bits starting at bit `start` inside one
 * bitmap byte, using the same 0x020A048C run-mask table as the two scanners.
 * The `and r1, r1, #0xff` after the complement is the u8 truncation, not a
 * mask written in the source.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/AREAMAN_ClearByteRun.c \
 *       --func AREAMAN_ClearByteRun --addr 0x02034394 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern const u8 Areaman_RunMask[];

void AREAMAN_ClearByteRun(u8 *p, u32 start, u32 len)
{
    u8 mask = Areaman_RunMask[len] >> start;

    *p = *p & (u8)~mask;
}
