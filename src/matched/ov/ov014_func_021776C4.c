/*
 * function: func_021776C4
 * address:  0x021776C4
 * packet:   pkt_ov014_021776C4
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_021797A4     0x021797A4  data   a4
 *   func_02179498  0x02179498  thumb  ov014
 *   func_0217727C  0x0217727C  thumb  ov014
 *   func_02177660  0x02177660  thumb  ov014
 */

typedef unsigned char u8;

extern u8 *g_021797A4;
extern int func_02179498(void);
extern void func_0217727C(u8 *w, void (*fn)(u8 *));
extern void func_02177660(u8 *p);

int func_021776C4(void)
{
    u8 *w = g_021797A4;

    if (w == 0)
        return 1;
    if (w[0xCE7] == 0 && func_02179498() != 0) {
        w[0xCF5] = 0xFF;
        func_0217727C(g_021797A4, func_02177660);
        return 1;
    }
    return 0;
}
