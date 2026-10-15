/*
 * function: NNS_SndReadTrackInfo
 * address:  0x02072894
 * packet:   pkt_02072894
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * blocker:  label class: 0x0208A0A4 (SDK) has exactly one caller in the image
 *           and it is this function, so no branch outside 0x02072894..0x020728E8
 *           witnesses it.  Every concrete byte reproduces.
 *
 * symbols:
 *   g_0214BAC0   0x0214BAC0  data
 *   g_0214BB00   0x0214BB00  data
 *   SND_ReadTrackInfo 0x0208A0A4  arm
 *
 * r1 (b) is parked in lr as soon as it is read, because the predicated
 * `ldrge r1, [pc]` that materialises the table base clobbers r1 before the
 * call; the fourth argument (c) is copied into r3 first for the same reason,
 * r2 being needed for b again at the call.
 */

#include "../include/G_Ctl.h"

typedef unsigned char  u8;
typedef signed char    s8;
typedef unsigned int   u32;

extern struct Ctl g_0214BAC0;
extern u8  g_0214BB00[];
struct SNDDriverInfo;
struct SNDTrackInfo;
extern int SND_ReadTrackInfo(struct SNDDriverInfo *, int playerNo, int trackNo, struct SNDTrackInfo *trackInfo);

int NNS_SndReadTrackInfo(int playerNo, int trackNo, struct SNDTrackInfo *trackInfo)
{
    s8 idx = ((s8 *)&g_0214BAC0)[0];
    u8 *p;

    if (idx < 0) p = 0;
    else         p = g_0214BB00 + idx * 0x11E0;
    if (p == 0) return 0;
    return SND_ReadTrackInfo((struct SNDDriverInfo *)p, playerNo, trackNo, trackInfo);
}
