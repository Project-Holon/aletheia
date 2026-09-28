/*
 * function: func_0204BB20
 * address:  0x0204BB20
 * packet:   pkt_0204B954
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A74   0x02146A74  data
 *
 * Store a word at +0xfc of the cell-actor singleton, silently doing nothing
 * before the system is constructed.  A leaf: the guarded store predicates to
 * `strne` and no lr is saved.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204BB20.c \
 *       --func func_0204BB20 --addr 0x0204BB20 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sys {
    u8  pad_000[0xfc];
    u32 unk_0fc;   /* 0xfc */
};

extern struct Sys *g_02146A74;

void func_0204BB20(u32 v)
{
    if (g_02146A74 != 0) {
        g_02146A74->unk_0fc = v;
    }
}
