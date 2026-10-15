/*
 * function: DWCi_AC_GetPostalCode
 * address:  0x0205EA70
 * packet:   pkt_0205EA70
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_AC_GetPostalCode (libdwcac.TWL.HYB.a(shop_usb.o))
 *
 * symbols:
 *   decodeSSID                       0x0205eb30 arm
 *   memcmp                           0x020923f0 arm
 *   MI_CpuCopy8                      0x02082d44 arm
 *   g_020A8118                       0x020A8118 data
 */

extern const char g_020A8118[];
extern void decodeSSID(char *ssid, unsigned char *buf);
extern int memcmp(const void *s1, const void *s2, unsigned long n);
extern void MI_CpuCopy8(const void *srcp, void *dstp, unsigned long size);

int DWCi_AC_GetPostalCode(char *ssid, unsigned char *pos)
{
    int i;
    unsigned char buf[24];

    decodeSSID(ssid, buf);
    if (memcmp(buf, g_020A8118, 8) == 0) {
        MI_CpuCopy8(&buf[8], pos, 10);
        for (i = 0; i < 10; i++) {
            if (pos[i] < 0x20 || pos[i] > 0x7e) {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}
