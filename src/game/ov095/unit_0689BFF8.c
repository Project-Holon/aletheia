/*
 * file:     unit_0689BFF8.c
 * function: func_0689BFF8
 * address:  0x0689BFF8
 * packet:   pkt_ov095_0689BFF8
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C88A4  0x021C88A4  thumb
 *   func_021C88C8  0x021C88C8  thumb
 *   func_021D5440  0x021D5440  thumb
 *   func_021D62A8  0x021D62A8  thumb
 *   func_021D7B8C  0x021D7B8C  thumb
 *   func_021E8940  0x021E8940  thumb
 */

typedef unsigned char u8;

typedef struct Rec {
    int f00;
    int f04;
    int f08;
    u8 f0c;
    u8 f0d;
    u8 f0e;
    u8 f0f;
} Rec;

extern int func_021D7B8C(int, int);
extern int func_021D62A8(void *);
extern int func_021D5440(void *);
extern Rec *func_021C88A4(void *, int, int);
extern int func_021E8940(u8);
extern void func_021C88C8(void *, Rec *);

void func_0689BFF8(void *a, void *b)
{
    int n;
    int k;
    Rec *r;

    n = func_021D7B8C(2, 4);
    if (n > 0) {
        if (func_021D62A8(b) == 0) {
            k = func_021D5440(b);
            r = func_021C88A4(a, 0xc, k);
            r->f0c = 1;
            r->f04 = 2;
            r->f08 = func_021E8940(n);
            r->f0f = k;
            func_021C88C8(a, r);
        }
    }
}
