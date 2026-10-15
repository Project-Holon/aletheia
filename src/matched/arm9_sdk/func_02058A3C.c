/*
 * function: DWCi_Util_WiFiId_scrambleUid
 * address:  0x02058A3C
 * packet:   pkt_02058A3C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Util_WiFiId_scrambleUid (libdwcbm.TWL.HYB.a util_wifiidtool.o)
 *
 * symbols:
 *   MI_CpuCopy8               0x02082D44 arm
 *   DWCi_util_wifiid_ttable   0x020A1608 data a1
 *   DWCi_util_wifiid_exctable 0x020A15F0 data a1
 */

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned long      u32;
typedef unsigned long long u64;

typedef union tagUNI64 {
    u64 data;
    u32 half[2];
    u8  i[8];
} UNI64;

extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
extern const u8 DWCi_util_wifiid_ttable[16];
extern const u8 DWCi_util_wifiid_exctable[8];

u64 DWCi_Util_WiFiId_scrambleUid(u16 rand, u32 mac, u8 vend, u8 mainunit)
{
    UNI64 uni64;
    u8 uidtemp[8];
    int i;

    uni64.data = ((u64)mainunit & 0x3) | (((u64)vend & 0x1) << 2)
               | (((u64)mac & 0xFFFFFF) << 3) | (((u64)rand & 0xFFFF) << 27);
    for (i = 0; i < 6; i++)
        uni64.i[i] ^= 0xD6;
    for (i = 0; i < 5; i++)
        uni64.i[i] = (u8)((DWCi_util_wifiid_ttable[(uni64.i[i] >> 4) & 0xF] << 4) | DWCi_util_wifiid_ttable[uni64.i[i] & 0xF]);
    MI_CpuCopy8(uni64.i, uidtemp, sizeof(uidtemp));
    for (i = 0; i < 5; i++)
        uni64.i[DWCi_util_wifiid_exctable[i]] = uidtemp[i];
    uni64.i[7] = 0;
    uni64.i[6] = 0;
    uni64.i[5] &= 7;
    uni64.data <<= 1;
    uni64.i[0] |= (uni64.i[5] >> 3) & 1;
    for (i = 0; i < 6; i++)
        uni64.i[i] ^= 0x67;
    uni64.i[7] = 0;
    uni64.i[6] = 0;
    uni64.i[5] &= 7;
    return uni64.data;
}
