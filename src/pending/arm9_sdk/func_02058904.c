/*
 * function: func_02058904
 * address:  0x02058904
 * packet:   pkt_02058904
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * notes:    99 bytes: the object loads notAttestedId as two ldr and needs one fewer callee-saved register; every spelling tried gives ldm/stm and r7
 *
 * sdk:      DWCi_BACKUPlConvWifiInfo (libdwcbm.TWL.HYB.a dwc_backup.o)
 *
 * symbols:
 *   MI_CpuCopy8 0x02082D44 arm
 *   Wifi        0x02146A94 data
 *   Address     0x02146A90 data a4
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

/* dwc_backup.o's statics from Address on, in their laid-out order: the object writes
 * Wifi[5], Wifi[10] and Wifi[11] off Address's literal while the copies take Wifi's own */
typedef struct {
    u32 Address;
    u8  Wifi[14];
} DWCBackupStatics;

extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
extern DWCBackupStatics Address;
extern u8 Wifi[14];

u8 *func_02058904(DWCWiFiInfo *info)
{
    u64 tmp;

    tmp = info->notAttestedId;
    MI_CpuCopy8(&info->attestedUserId, &Wifi[0], 5);
    Address.Wifi[5] = (u8)(((info->attestedUserId >> 40) & 7) | ((tmp & 0x1F) << 3));
    tmp >>= 5;
    MI_CpuCopy8(&tmp, &Wifi[6], 4);
    Address.Wifi[10] = (u8)(((tmp >> 32) & 0x3F) | ((info->pass & 3) << 6));
    Address.Wifi[11] = (u8)(info->pass >> 2);
    MI_CpuCopy8(&info->randomHistory, &Wifi[12], 2);
    return Wifi;
}
