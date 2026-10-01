/*
 * function: func_021AAFC0
 * address:  0x021AAFC0
 * packet:   pkt_ov021_021AAFC0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021ADAAC  0x021ADAAC  thumb
 *   func_02082BCC  0x02082BCC  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u16 h0;
    u16 h2;
    u16 h4;
    u16 h6;
    int f8;
    u8 bc;
    u8 pad[3];
} R;

typedef struct {
    int f0;
    char pad[0x5b0];
    int f5b4;
} D;

extern int func_021ADAAC(int a, int b, u16 c, u16 d, int e, u8 f);
extern void func_02082BCC(void *p, int v, int n);

void func_021AAFC0(int a, D *d, R *r)
{
    if (d->f5b4 == 0) {
        d->f5b4 = func_021ADAAC(a, d->f0, r->h2, r->h6, r->f8, r->bc);
        if (d->f5b4 == 0) {
            func_02082BCC(r, 0, 0x10);
        }
    }
}
