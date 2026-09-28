/*
 * function: func_021EEEA8
 * address:  0x021EEEA8
 * packet:   pkt_021EEEA8
 * region:   ov188
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EEFE4  0x021EEFE4  thumb  ov188
 *   func_021EF090  0x021EF090  thumb  ov188
 *   func_021EF1D8  0x021EF1D8  thumb  ov188
 *   func_021EF2D4  0x021EF2D4  thumb  ov188
 *   g_0214616C     0x0214616C  data
 */
typedef unsigned int u32;

extern void func_021EEFE4(void *p, void *q, u32 c);
extern void func_021EF090(void *p, void *q);
extern void func_021EF1D8(void *p, void *q);
extern void func_021EF2D4(void *p, void *q);
extern char *g_0214616C;

void func_021EEEA8(void *p, u32 c)
{
    char *q = g_0214616C + 0xc4;

    func_021EEFE4(p, q, c);
    func_021EF090(p, q);
    func_021EF1D8(p, q);
    func_021EF2D4(p, q);
}
