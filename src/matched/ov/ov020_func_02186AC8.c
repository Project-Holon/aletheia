/*
 * function: func_02186AC8
 * address:  0x02186AC8
 * packet:   pkt_ov020_02186AC8
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02186B08  0x02186B08  thumb
 *   func_02186B2C  0x02186B2C  thumb
 *   func_02161E78  0x02161E78  thumb  ov010
 *   func_0218677C  0x0218677C  thumb
 */

extern int func_02186B08(char *);
extern char *func_02186B2C(char *, char *);
extern void func_02161E78(char *);
extern void func_0218677C(char *, int);

void func_02186AC8(char *p, int b, char *c, int d)
{
    char *q;

    if (func_02186B08(p + 8) == 1) {
        func_02186B2C(p + 0xF8, p + 0xE0);
        func_02161E78(p + 0xE0);
    }
    q = p + 8;
    q = func_02186B2C(q, c);
    if (d != 0)
        func_0218677C(q, b);
}
