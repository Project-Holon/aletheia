/*
 * file:     unit_020584E0_p01.c
 * unit:     yes
 * function: func_020584E0, func_020584F4, func_02058518
 * address:  0x020584E0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
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

extern int ReadSlotInfo(void *buf, int offset, unsigned long num);
extern int ReadSlotInfoEx(void *buf, int offset, unsigned long num);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
int DWCi_BM_GetApInfo(void *buf);
int DWCi_BM_GetApInfoEx(void *buf);
void func_02058518(DWCWiFiInfo *buf);
extern u8 Wifi[14];


int DWCi_BM_GetApInfo(void *buf)
{
    return ReadSlotInfo(buf, 0, 3);
}


int DWCi_BM_GetApInfoEx(void *buf)
{
    if (ReadSlotInfoEx(buf, 0, 3) != 0)
        return 1;
    return 0;
}


/*
 * sdk:      DWCi_BM_GetWiFiInfo (libdwcbm.TWL.HYB.a dwc_backup.o)
 */
void func_02058518(DWCWiFiInfo *buf)
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
