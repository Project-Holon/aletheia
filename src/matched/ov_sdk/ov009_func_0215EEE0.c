/*
 * function: func_0215EEE0
 * address:  0x0215EEE0
 * packet:   pkt_ov009_0215EEE0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCL_SetResolver (libsoc.TWL.HYB.a(socl_resolve.o))
 *
 * symbols:
 *   func_0215EF48  0x0215EF48  arm  ov009
 *   g_021A8278     0x021A8278  data
 *   g_021A82DC     0x021A82DC  data
 */

extern unsigned long g_021A8278;
extern unsigned long g_021A82DC[2];
extern unsigned long func_0215EF48(void);

int func_0215EEE0(unsigned long dns1, unsigned long dns2)
{
    if (func_0215EF48() == 0)
        return -0x27;
    g_021A82DC[0] = dns1;
    if (dns1 == 0) {
        g_021A8278 &= ~2;
        g_021A82DC[1] = 0;
    } else {
        g_021A8278 |= 2;
        g_021A82DC[1] = dns2;
    }
    return 0;
}
