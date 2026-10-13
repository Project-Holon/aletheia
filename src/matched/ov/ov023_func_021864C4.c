/*
 * function: OEKAKI_MakeStroke
 * address:  0x021864C4
 * packet:   pkt_ov023_021864C4
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct {
    u16 n;
    u16 a;
    u16 b;
    u16 pad;
} Ent;

typedef struct {
    u8 b[4];
    u8 lo : 3;
    u8 mid : 3;
    u8 hi : 2;
} Rec;

void OEKAKI_MakeStroke(Rec *d, Ent *s, int a, int c)
{
    int i;
    Ent *e;

    if (s[0].n != 0) {
        d->b[0] = s[0].a;
        d->b[2] = s[0].b;
        e = &s[s[0].n - 1];
        d->b[1] = e->a;
        d->b[3] = e->b;
        for (i = 0; i < 2; i++) {
            if (d->b[i] + d->b[i + 2] == 0) {
                s[0].n = 0;
            }
        }
    }
    if (s[0].n >= 2) {
        d->mid = 2;
    } else {
        d->mid = s[0].n;
    }
    d->lo = a;
    d->hi = c;
}
