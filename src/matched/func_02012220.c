/*
 * function: func_02012220
 * address:  0x02012220
 * packet:   pkt_02012158
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201214C     0x0201214C  thumb
 *   func_02012158     0x02012158  thumb
 *
 * ica_anime.c: when func_0201214C(p) says yes, stop the playback
 * (func_02012158(p, 0), which is the tail call in the pending file
 * src/pending/func_02012158.c) and set bit 0 of the byte at +0x33.
 *
 * The bit update is one expression, `(f & ~1) | 1`: the original loads the
 * byte once, clears with `bics` and sets with `orrs` - two statements would
 * be two loads and two stores (see
 * docs/idioms/an-and-not-is-what-emits-bic.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02012220.c \
 *       --func func_02012220 --addr 0x02012220 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

struct IcaAnime {
    u8  pad00[0x33];
    u8  f33;        /* +0x33 */
};

extern u32 func_0201214C(struct IcaAnime *p);
extern void func_02012158(struct IcaAnime *p, u32 v);

void func_02012220(struct IcaAnime *p)
{
    if (func_0201214C(p) != 0) {
        func_02012158(p, 0);
        p->f33 = (p->f33 & ~1) | 1;
    }
}
