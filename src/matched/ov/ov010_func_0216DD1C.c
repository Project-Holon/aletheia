/*
 * function: func_0216DD1C
 * address:  0x0216DD1C
 * packet:   pkt_ov010_0216DD1C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Iterator: advances *iter over the 0x100-byte records at +0x18 and
 * returns TRUE with *out set at the next record func_0216D55C accepts.
 *
 * symbols:
 *   func_0216D4F0  0x0216D4F0  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Rec {
    u8 data[0x100];
} Rec;

typedef struct Ctx {
    u8 pad[0x18];
    Rec *recs;
} Ctx;

extern u16 func_0216D4F0(void *p);
extern int func_0216D55C(Rec *r, int kind);

int func_0216DD1C(Ctx *c, Rec **out, u32 *iter)
{
    u32 n;
    Rec *r;

    n = func_0216D4F0(c);
    if (*iter < n) {
        r = &c->recs[*iter];
        do {
            (*iter)++;
            if (func_0216D55C(r, 1)) {
                *out = r;
                return 1;
            }
            r++;
        } while (*iter < n);
    }
    return 0;
}
