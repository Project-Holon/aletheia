/*
 * unit:     no
 * function: GF_STANDARD_Reset
 * address:  0x0203F3B4
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
 *   RTC_Init  0x02088788  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   GF_STANDARD_GetRtc  0x0203F46C  arm
 *
 * Reset of the 0x48-byte block at 0x021469FC: zero it wholesale, then write
 * its first three words explicitly (the redundant stores are in the source;
 * the memset has already cleared them) and hand it to GF_STANDARD_GetRtc.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_STANDARD_Reset.c \
 *       --func GF_STANDARD_Reset --addr 0x0203F3B4 --cc 1.1p1 --arm
 */

#include "../include/G_021469FC.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern struct G_021469FC g_021469FC;

extern void RTC_Init(void);
extern void MI_CpuFill8(void *dst, u32 value, u32 size);
struct RtcRequest;
extern void GF_STANDARD_GetRtc(struct RtcRequest *req);

void GF_STANDARD_Reset(void)
{
    RTC_Init();
    MI_CpuFill8(&g_021469FC, 0, 0x48);
    g_021469FC.unk_00 = 0;
    g_021469FC.unk_04 = 0;
    g_021469FC.unk_08 = 0;
    GF_STANDARD_GetRtc((struct RtcRequest *)(&g_021469FC));
}
