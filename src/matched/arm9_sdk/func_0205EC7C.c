/*
 * function: makeUsbWepKey
 * address:  0x0205EC7C
 * packet:   pkt_0205EC7C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      makeUsbWepKey (libdwcac.TWL.HYB.a(shop_usb.o))
 *
 * symbols:
 *   MI_CpuCopy8                      0x02082d44 arm
 *   SHMASKkey0                       0x020a80b0 data
 *   CONV_BYTE_TABLE                  0x020a1668 data
 *   CONV_4BIT_TABLE                  0x020a1675 data
 *   g_020A80B0                       0x020A80B0 data
 *   g_020A1668                       0x020A1668 data
 *   g_020A1675                       0x020A1675 data
 */

extern char *g_020A80B0[4];
extern const unsigned char g_020A1668[13];
extern const unsigned char g_020A1675[16];
extern void MI_CpuCopy8(const void *srcp, void *dstp, unsigned long size);

void makeUsbWepKey(unsigned char *seed, unsigned char *wepkey)
{
    int i;
    unsigned char keytemp[13];

    for (i = 0; i < 13; i++) {
        wepkey[i] = seed[i] ^ seed[13 + i % 7];
    }
    for (i = 0; i < 7; i++) {
        wepkey[3 + i] = wepkey[3 + i] ^ seed[13 + i];
    }
    for (i = 0; i < 13; i++) {
        wepkey[i] = wepkey[i] ^ g_020A80B0[1][i];
    }
    MI_CpuCopy8(wepkey, keytemp, 13);
    for (i = 0; i < 13; i++) {
        wepkey[g_020A1668[i]] = keytemp[i];
    }
    for (i = 0; i < 13; i++) {
        wepkey[i] = wepkey[i] ^ g_020A80B0[3][i];
    }
    for (i = 0; i < 13; i++) {
        wepkey[i] = (unsigned char)((g_020A1675[(wepkey[i] >> 4) & 0xf] << 4) | g_020A1675[wepkey[i] & 0xf]);
    }
    for (i = 0; i < 3; i++) {
        wepkey[i] ^= wepkey[i + 6];
        wepkey[i + 3] ^= wepkey[i + 9];
        wepkey[i + 6] ^= wepkey[i + 3];
        wepkey[i + 9] ^= wepkey[i];
        wepkey[12] ^= wepkey[i];
    }
}
