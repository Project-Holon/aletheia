/*
 * function: func_02207EA8
 * address:  0x02207EA8
 * packet:   pkt_ov094_02207EA8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Lever: the clamp bound p->f58 is read from the struct twice (no local).
 *
 * symbols:
 */

typedef unsigned char u8;

typedef struct S {
    u8 pad0[0x54];
    int f54;
    int f58;
    int pad5c;
    int f60;
    int f64;
    u8 pad68[4];
    u8 f6c;
    u8 pad6d[3];
    unsigned int f70;
} S;

void func_02207EA8(S *p, int a)
{
    int t;
    int x;

    if (p->f6c != 100) {
        t = p->f54;
        p->f64 = 0x80000000;
        x = t + a;
        if (x < 0) {
            a -= x;
        }
        x = t + a;
        if (x > p->f58) {
            a -= x - p->f58;
        }
        p->f60 = -a;
        if (p->f54 < 0) {
            p->f54 = 0;
        }
        if (p->f54 > p->f58) {
            p->f54 = p->f58;
        }
        p->f70 |= 2;
    }
}
