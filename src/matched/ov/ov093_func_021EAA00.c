/*
 * function: func_021EAA00
 * address:  0x021EAA00
 * packet:   pkt_ov093_021EAA00
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021E9100  0x021E9100  thumb  ov093
 *   func_021B9AF8  0x021B9AF8  thumb  ov093
 *   func_021EAA24  0x021EAA24  thumb  ov093
 */
typedef unsigned char u8;

extern u8 *func_021E9100(u8 *p, int n);
extern char *func_021B9AF8(char *p, int i);
extern void func_021EAA24(void *a, u8 *t);

void func_021EAA00(u8 *p)
{
    u8 *t;

    t = func_021E9100(p, 0x3c);
    func_021B9AF8(*(char **)(p + 8), p[0xc]);
    func_021EAA24(*(void **)(p + 0x180), t);
}
