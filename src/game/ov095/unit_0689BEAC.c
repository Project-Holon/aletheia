/*
 * file:     unit_0689BEAC.c
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
 *   func_021C88A4  0x021C88A4  thumb
 *   func_021C88C8  0x021C88C8  thumb
 *   func_021D55A0  0x021D55A0  thumb
 *   func_021D6314  0x021D6314  thumb
 *   func_021E8B80  0x021E8B80  thumb
 */

typedef unsigned char u8;

typedef struct Rec {
    u8 pad[4];
    int f04;
    u8 f08;
    u8 pad2[11];
    u8 f14;
} Rec;

extern int func_021D6314(void *, int);
extern int func_021E8B80(int);
extern int func_021D55A0(void *, int);
extern Rec *func_021C88A4(void *, int, int);
extern void func_021C88C8(void *, Rec *);

void func_0689BEAC(void *a, void *b, int c)
{
    Rec *r;
    int t;

    t = func_021D6314(b, 0x17);
    if (func_021D55A0(b, func_021E8B80(t)) == 0) {
        r = func_021C88A4(a, 0xb, c);
        r->f04 = 0x17;
        r->f08 = c;
        r->f14 = 1;
        func_021C88C8(a, r);
    }
}
