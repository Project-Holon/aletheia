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

extern void func_021EEFE4(void *p, char *b, u32 c);
typedef unsigned char  u8;
extern void func_021EF090(u8 *a, u8 *b);
extern int func_021EF1D8(char *p, char *a1);
extern int func_021EF2D4(u8 *a, const u8 *b);
extern char *g_0214616C;

void func_021EEEA8(void *p, u32 c)
{
    char *q = g_0214616C + 0xc4;

    func_021EEFE4(p, q, c);
    func_021EF090(p, (u8 *)q);
    func_021EF1D8(p, q);
    func_021EF2D4(p, (const u8 *)q);
}
