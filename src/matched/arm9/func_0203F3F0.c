/*
 * unit:     no
 * function: GF_STANDARD_Setup
 * address:  0x0203F3F0
 * packet:   pkt_0203EF5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469FC     0x021469FC  data
 *   GF_STANDARD_GetRtc  0x0203F46C  arm
 *
 * TU: gf_standard.c.
 *
 * Per-frame tick on the block at 0x021469FC: while +0x04 is clear, count
 * frames in +0x08 and every eleventh one reset the counter and run
 * GF_STANDARD_GetRtc.  The `ble` says +0x08 is signed.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_STANDARD_Setup.c \
 *       --func GF_STANDARD_Setup --addr 0x0203F3F0 --cc 1.1p1 --arm
 */

#include "../include/G_021469FC.h"

typedef unsigned char u8;
typedef unsigned int  u32;
typedef signed int    s32;

extern struct G_021469FC g_021469FC;

struct RtcRequest;
extern void GF_STANDARD_GetRtc(struct RtcRequest *req);

void GF_STANDARD_Setup(void)
{
    if (g_021469FC.unk_04 != 0) {
        return;
    }
    g_021469FC.unk_08++;
    if (g_021469FC.unk_08 <= 10) {
        return;
    }
    g_021469FC.unk_08 = 0;
    GF_STANDARD_GetRtc((struct RtcRequest *)(&g_021469FC));
}
