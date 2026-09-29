/*
 * function: func_021B7B7C
 * address:  0x021B7B7C
 * packet:   pkt_ov067_021B7B7C
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct S {
    u8 pad00[0x18];
    u8 f18;
    u8 f19;
    u16 f1a;
    u8 pad1c[0x4c - 0x1c];
    u16 f4c;
    u8 pad4e[0x5c - 0x4e];
    u16 f5c;
    u16 f5e;
    u16 f60;
    u16 f62;
    u16 f64;
} S;

void func_021B7B7C(S *p)
{
    if (p->f19 > p->f4c) {
        p->f5e = p->f4c;
    } else {
        p->f5e = p->f19;
    }
    if (p->f4c < p->f19) {
        p->f64 = 0;
    } else {
        p->f64 = p->f4c - p->f19;
    }
    if (p->f18 > p->f5e || p->f1a > p->f64) {
        p->f5c = 0;
        p->f62 = 0;
    } else {
        p->f5c = p->f18;
        p->f62 = p->f1a;
    }
}
