/*
 * function: func_0204C024
 * address:  0x0204C024
 * packet:   pkt_0204BE84
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Forward the single argument to func_02063378 with the manager as the
 * block argument.
 *
 * Unlabelled in the current listings: the prologue saves nothing, so
 * disasm.py never auto-labelled it (see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  The
 * function starts at the computed address and its body ends at 0x0204C040.
 *
 * symbols:
 *   g_02146A74     0x02146A74  data
 *   func_02063378  0x02063378  arm
 */
typedef unsigned char u8;
typedef unsigned int  u32;

struct Mgr {
    u8 pad_000[0x20];
};

extern struct Mgr *g_02146A74;
extern void func_02063378(struct Mgr *m, u32 arg);

void func_0204C024(u32 arg)
{
    func_02063378(g_02146A74, arg);
}
