/*
 * function: func_0204AB84
 * address:  0x0204AB84
 * packet:   pkt_0204A9D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A74     0x02146A74  data
 *
 * Copy the 36-byte header of a 64-byte-stride record out of the actor
 * table hung off the manager's pointer member at +0x10c into the caller's
 * buffer.  The whole copy is one aggregate assignment: two ldm/stm pairs
 * of four registers and a trailing word.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Mgr {
    u8  pad_000[0x10c];
    u8 *tbl;
};

extern struct Mgr *g_02146A74;

struct Rec {
    u32 w[9];
};

void func_0204AB84(u32 idx, struct Rec *dst)
{
    struct Rec *src = (struct Rec *)(g_02146A74->tbl + idx * 64);

    *dst = *src;
}
