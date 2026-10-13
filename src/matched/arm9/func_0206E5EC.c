/*
 * function: NNS_G3dMdlSetMdlPolygonIDAll
 * address:  0x0206E5EC
 * packet:   pkt_0206E394
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNS_G3dMdlSetMdlPolygonID    0x0206E4FC  arm
 *
 * Walks the count byte at +0x18, calling NNS_G3dMdlSetMdlPolygonID with the counter and the
 * caller's second argument; the counter is zeroed before the entry test (which
 * is why the original's `mov r4, #0` precedes `cmp`/`popls`) and the count is
 * re-read from memory every iteration.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G3dMdlSetMdlPolygonIDAll.c \
 *       --func NNS_G3dMdlSetMdlPolygonIDAll --addr 0x0206E5EC --cc 1.1p1 --arm
 */

typedef unsigned int u32;
typedef unsigned char u8;

typedef struct {
    u8 unk00[0x18];
    u8 count18;
} Obj0206E5EC;

extern void NNS_G3dMdlSetMdlPolygonID(Obj0206E5EC *p, u32 idx, u32 a);

void NNS_G3dMdlSetMdlPolygonIDAll(Obj0206E5EC *p, u32 a)
{
    u32 i = 0;

    for (i = 0; i < p->count18; i++) {
        NNS_G3dMdlSetMdlPolygonID(p, i, a);
    }
}
