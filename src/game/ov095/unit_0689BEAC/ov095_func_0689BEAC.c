/*
 * function: func_0689BEAC
 * address:  0x0689BEAC
 * packet:   pkt_ov095_0689BEAC
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0689BEEC   0x0689BEEC  thumb  ov095
 *   func_0689BEFC   0x0689BEFC  thumb  ov095
 *   func_0689BF0C   0x0689BF0C  thumb  ov095
 *   func_0689BF1C   0x0689BF1C  thumb  ov095
 *   func_0689BF2C   0x0689BF2C  thumb  ov095
 */

typedef unsigned char u8;

typedef struct Rec {
    u8 pad[4];
    int f04;
    u8 f08;
    u8 pad2[11];
    u8 f14;
} Rec;

extern int func_0689BEEC(void *, int);
extern int func_0689BEFC(int);
extern int func_0689BF0C(void *, int);
extern Rec *func_0689BF1C(void *, int, int);
extern void func_0689BF2C(void *, Rec *);

void func_0689BEAC(void *a, void *b, int c)
{
    Rec *r;
    int t;

    t = func_0689BEEC(b, 0x17);
    if (func_0689BF0C(b, func_0689BEFC(t)) == 0) {
        r = func_0689BF1C(a, 0xb, c);
        r->f04 = 0x17;
        r->f08 = c;
        r->f14 = 1;
        func_0689BF2C(a, r);
    }
}
