/*
 * function: EFFECT_ENCOUNT_CountStep
 * address:  0x021AABC4
 * packet:   pkt_ov021_021AABC4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    char pad[0x5b8];
    u16 a;
} D;

typedef struct {
    int pad[3];
    u32 fc;
} S;

int EFFECT_ENCOUNT_CountStep(S *s, D *d)
{
    u32 *c = &s->fc;
    if (*c < 0xffffffff) {
        (*c)++;
    }
    if (*c >= d->a) {
        return 1;
    }
    return 0;
}
