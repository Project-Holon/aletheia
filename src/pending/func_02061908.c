/*
 * function: func_02061908
 * address:  0x02061908
 * packet:   pkt_020618E4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * PARKED AT MATCH: every concrete byte is right; the PC24 at +0x0018 is
 * wildcarded because 0x0207FC48 (GX_LoadClearImageDepth) has exactly one
 * branch reference image wide and it is that call.  Same class and same
 * unblock as src/pending/func_020618E4.c: label/matched, no outside witness.
 * The `*` is disasm.py's extent for the original running past the leaf.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02061908.c \
 *       --func func_02061908 --addr 0x02061908 --arm --cc 1.1p1
 */

typedef unsigned int u32;

extern void func_0207FB2C(void);
extern void func_0207FC48(u32 a, u32 c);
extern void func_0207FCE4(void);

void func_02061908(u32 a, u32 b, u32 c)
{
    func_0207FB2C();
    func_0207FC48(a, c);
    func_0207FCE4();
}
