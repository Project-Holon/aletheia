/*
 * function: func_021BA2F8
 * address:  0x021BA2F8
 * packet:   pkt_ov016_021BA2F8
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * sdk:      GetMacEncKey (libdwcutil.TWL.HYB.a(atermset.o))
 *
 * symbols:
 *   func_021BA2EC  0x021ba2ec  thumb  ov016
 *   func_020923F0  0x020923f0  arm
 *   func_021BC608  0x021bc608  thumb  ov016
 *   sAtermsetTable2  0x021dac18  data
 *   g_021DD480  0x021dd480  data
 *   g_021DD478  0x021dd478  data
 *   g_021DAB58  0x021dab58  data
 *   memcmp  0x020923F0  arm
 */

#include "../arm9_sdk/libc/string.h"

extern const unsigned char sAtermsetTable2[];
extern unsigned char g_021DD480[6];
extern unsigned char g_021DD478[6];
extern unsigned char *g_021DAB58[];
extern int func_021BA2EC(unsigned char *lpmac);
extern int memcmp(const void *a, const void *b, unsigned long n);
extern int func_021BC608(char *lpwrite, char *lps);

int func_021BA2F8(unsigned char *lpkey)
{
    char strmac[32];
    char strap[32];
    unsigned char ap_mac[6];
    unsigned char sta_mac[6];
    int ret;

    memcpy(lpkey + 12, sAtermsetTable2, 4);
    memcpy(ap_mac, g_021DD480, 6);
    ap_mac[0] &= 0xfd;
    func_021BA2EC(sta_mac);
    memcpy(g_021DD478, sta_mac, 6);
    ret = memcmp(ap_mac, sta_mac, 6);
    if (ret <= 0) {
        memcpy(lpkey, sta_mac, 6);
        memcpy(lpkey + 6, ap_mac, 6);
    } else {
        memcpy(lpkey, ap_mac, 6);
        memcpy(lpkey + 6, sta_mac, 6);
    }
    if (g_021DAB58[1]) {
        func_021BC608(strmac, (char *)sta_mac);
        func_021BC608(strap, (char *)ap_mac);
    }
    return 1;
}
