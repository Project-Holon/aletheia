/*
 * function: DWCi_BM_GetWiFiInfo
 * address:  0x02058518
 * packet:   pkt_02058518
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_BM_GetWiFiInfo (libdwcbm.TWL.HYB.a dwc_backup.o)
 *
 * symbols:
 *   MI_CpuCopy8 0x02082D44 arm
 *   Wifi        0x02146A94 data
 */

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned long      u32;
typedef unsigned long long u64;

typedef struct tagDWCWiFiInfo {
    u64 attestedUserId;
    u64 notAttestedId;
    u16 pass;
    u16 randomHistory;
} DWCWiFiInfo;

extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
extern u8 Wifi[14];

void DWCi_BM_GetWiFiInfo(DWCWiFiInfo *buf)
{
    MI_CpuCopy8(&Wifi[0], &buf->attestedUserId, 6);
    buf->attestedUserId &= 0x7FFFFFFFFFFULL;
    MI_CpuCopy8(&Wifi[5], &buf->notAttestedId, 6);
    buf->notAttestedId >>= 3;
    buf->notAttestedId &= 0x7FFFFFFFFFFULL;
    MI_CpuCopy8(&Wifi[10], &buf->pass, 2);
    buf->pass = buf->pass >> 6;
    buf->pass &= 0x3FF;
    MI_CpuCopy8(&Wifi[12], &buf->randomHistory, 2);
}
