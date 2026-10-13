/*
 * function: WCMi_BssDescCopy
 * address:  0x02166040
 * packet:   pkt_ov009_02166040
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WCMi_BssDescCopy (libwcm.TWL.HYB.a(aplist.o))
 *
 * symbols:
 *   WCMi_GetSystemWork  0x021657C8  arm  ov009
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   MIi_CpuCopyFast  0x02082B0C  arm
 *   func_02082E74  0x02082E74  arm
 *   func_02082EA4  0x02082EA4  arm
 *   @12407  0x021A19B4  data
 *   @12409  0x021A19B8  data
 *
 * wpaTag and wmmTag are initialized from their templates after the length store,
 * so they live in an inner block. The DWARF has both tags at function scope; this
 * compiler rejects a declaration after a statement. The TWL branch's final add
 * zero-extends ieLength through lsl/lsr, which (ieLength & 0xffff) reproduces.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef struct WCMBssDesc {
    u16 length;             /* +0x00 */
    u16 rssi;               /* +0x02 */
    u8 bssid[6];            /* +0x04 */
    u16 ssidLength;         /* +0x0a */
    u8 ssid[32];            /* +0x0c */
    u16 capaInfo;           /* +0x2c */
    u16 rateSet[2];         /* +0x2e */
    u16 beaconPeriod;       /* +0x32 */
    u16 dtimPeriod;         /* +0x34 */
    u16 channel;            /* +0x36 */
    u16 cfpPeriod;          /* +0x38 */
    u16 cfpMaxDuration;     /* +0x3a */
    u16 gameInfoLength;     /* +0x3c */
    u16 elementCount;       /* +0x3e */
    u16 elements[64];       /* +0x40 */
} WCMBssDesc;

typedef struct WCMWork {
    char pad[0x12df];
    u8 deviceId;            /* +0x12df */
} WCMWork;

extern int WCMi_GetSystemWork(void);
extern void MIi_CpuClearFast(u32 data, void *destp, u32 size);
extern void MIi_CpuCopyFast(const void *srcp, void *destp, u32 size);
extern int func_02082E74(const void *mem1, const void *mem2, u32 size);
extern void func_02082EA4(const void *srcp, void *destp, u32 size);

void WCMi_BssDescCopy(WCMBssDesc *srcBssDesc, WCMBssDesc *destBssDesc)
{
    WCMWork *w;
    u8 *pSrc;
    u8 *pDest;
    u8 ieLength;
    u16 i;
    u8 id;
    u8 len;

    w = (WCMWork *)WCMi_GetSystemWork();
    MIi_CpuClearFast(0, destBssDesc, sizeof(WCMBssDesc));
    MIi_CpuCopyFast(srcBssDesc, destBssDesc, 0x40);
    destBssDesc->elementCount = 0;
    if (w->deviceId == 1)
        destBssDesc->length = 0x20;
    else
        destBssDesc->length = 0x40;
    {
        u8 wpaTag[4] = { 0x00, 0x50, 0xf2, 0x01 };
        u8 wmmTag[5] = { 0x00, 0x50, 0xf2, 0x02, 0x00 };

        ieLength = 0;
        pSrc = (u8 *)srcBssDesc->elements;
        pDest = (u8 *)destBssDesc->elements;
        for (i = 0; i < srcBssDesc->elementCount; i++) {
            id = pSrc[0];
            len = pSrc[1];
            if (id == 0x32 || id == 0x2a || id == 0x2f || id == 0x07 || id == 0x30) {
                func_02082EA4(pSrc, pDest, (u8)(len + 2));
                pDest += len + 2;
                ieLength += (u8)(len + 2);
                destBssDesc->elementCount++;
            } else if (id == 0xdd) {
                if (func_02082E74(pSrc + 2, wpaTag, 4) == 0 || func_02082E74(pSrc + 2, wmmTag, 5) == 0) {
                    func_02082EA4(pSrc, pDest, (u8)(len + 2));
                    pDest += len + 2;
                    ieLength += (u8)(len + 2);
                    destBssDesc->elementCount++;
                }
            }
            pSrc += len + 2;
        }
    }
    if (w->deviceId == 1)
        destBssDesc->length += (u16)(ieLength & 0xffff);
    else
        destBssDesc->length += ieLength;
}
