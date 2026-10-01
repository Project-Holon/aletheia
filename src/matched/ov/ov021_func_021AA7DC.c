/*
 * function: func_021AA7DC
 * address:  0x021AA7DC
 * packet:   pkt_ov021_021AA7DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021D8E70  0x021D8E70  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 a;
    u8 b;
} Pair;

typedef struct {
    u8 pad[7];
    u8 k : 7;
    u8 hi : 1;
} R;

typedef struct {
    int pad[3];
    R *fc;
} S;

typedef struct {
    char pad[0x5b8];
    u16 a;
    u16 b;
} D;

extern const Pair d_021D8E70[];

void func_021AA7DC(S *s, D *d)
{
    unsigned int k = s->fc->k;
    if (k > 2) {
        k = 0;
    }
    d->a = d_021D8E70[k].a;
    d->b = d_021D8E70[k].b;
}
