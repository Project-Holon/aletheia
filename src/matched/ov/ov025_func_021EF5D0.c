/*
 * function: func_021EF5D0
 * address:  0x021EF5D0
 * packet:   pkt_ov025_021EF5D0
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EF5D0 0x021EF5D0 thumb ov025
 *   func_021A2630 0x021A2630 thumb ov021
 *   func_021A2638 0x021A2638 thumb ov021
 *   func_021A2640 0x021A2640 thumb ov021
 *   func_021A21E0 0x021A21E0 thumb ov021
 *   _s32_div_f    0x0209C0A4 arm
 */

typedef signed short s16;

extern int *func_021A2630(int);
extern int *func_021A2638(int);
struct PtS;
extern void func_021A2640(unsigned char *, struct PtS *);
extern void func_021A21E0(int);

void func_021EF5D0(int a)
{
    int *p;
    s16 v[2];

    p = func_021A2630(a);
    func_021A2638(a);
    func_021A2640((unsigned char *)a, (struct PtS *)v);
    *p = *p + 1;
    if (*p % p[4] == 0) {
        v[0] = v[0] + (s16)p[2];
    }
    if (*p % p[5] == 0) {
        v[1] = v[1] + (s16)p[3];
    }
    if (*p >= p[1]) {
        func_021A21E0(a);
    }
}
