/*
 * function: func_02175214
 * address: 0x02175214
 * packet: pkt_ov012_02175214
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Two trailing alignment bytes.
 * Caller consumes 0203D1B4's live r0 despite its filed void return.
 * symbols:
 *   func_0203D1B4 0x0203D1B4 arm
 */
typedef unsigned char u8;
extern int func_0203D1B4(void);
int func_02175214(u8 *p)
{
    int n = 0;
    int i;
    for (i = 0; i < 4; i++) if (p[0x158 + i] == 1) n++;
    if (n >= func_0203D1B4()) return 1;
    return 0;
}
