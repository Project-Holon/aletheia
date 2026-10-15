/*
 * function: wsiServiceAvailable
 * address:  0x021E2290
 * packet:   pkt_021E2290
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_SNPrintf  0x02084F80  arm
 *   g_021ACEF8     0x021ACEF8  data
 *   g_021ACEFC     0x021ACEFC  data
 *   sWsAuthUrlFormat     0x021E49D0  data
 *   gWsAuthServiceUrl     0x021E53BC  data
 *
 * Session gate: only in state 1, and only while the 0x021E53BC flag byte is
 * clear, hand the 0x021E49D0 table to OS_SNPrintf with the 0x021ACEFC base.
 */

typedef unsigned int u32;
typedef signed int s32;
typedef signed char s8;

extern u32 g_021ACEF8;
extern u32 g_021ACEFC[];
extern u32 sWsAuthUrlFormat[];
extern s8 gWsAuthServiceUrl[];
extern int OS_SNPrintf(char *dst, unsigned int len, const char *fmt, ...);

s32 wsiServiceAvailable(void)
{
    if (g_021ACEF8 == 1) {
        if (gWsAuthServiceUrl[0] == 0)
            OS_SNPrintf((char *)gWsAuthServiceUrl, 0x80, (const char *)sWsAuthUrlFormat, g_021ACEFC);
        return 1;
    }
    return 0;
}
