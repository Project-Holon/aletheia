/*
 * function: func_0207292C
 * address:  0x0207292C
 * packet:   pkt_0207292C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020895D8  0x020895D8  arm
 *   g_0214DEC0     0x0214DEC0  data
 *
 * Channel allocator, claim-by-mask.  Refuses an empty mask (returns 1), refuses
 * a mask that overlaps the in-use word at g_0214DEC0+8 (returns 0), otherwise
 * locks it through func_020895D8 and ORs it in.  Matched func_02072974 is the
 * matching release and reads the same +0x08 word.
 *
 * PIN ../2.0/sp2, the "kept constants" tell (docs/FRONTEND-PINS.md, and
 * docs/families/cluster_020726D0.h).  THE C BELOW IS UNCHANGED from the version
 * this file carried while it was parked in src/pending as DIFF: only the
 * compiler moved.  Under dsi/1.1p1 -O4,p the base pool word 0x0214DEC0 is live
 * at two points (the `tst` before the call and the `orr` after it), so 1.1p1
 * hoists it into callee-saved r4 and the parameter into r5, giving
 * `push {r3, r4, r5, lr}` for the image's `push {r4, lr}` and folding the two
 * pool entries into one: 68 bytes against the original's 72, 26 concrete bytes
 * out.  The image RELOADS the pool word after the call
 * (`ldr r1,[pc,#0x10]` at 0x0207295C, a second entry at 0x02072970) which is
 * exactly what the pin reproduces.  Under ../2.0/sp2: 72 bytes, 0 mismatches.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0207292C.c \
 *       --func func_0207292C --addr 0x0207292C --cc ../2.0/sp2 --arm
 */

struct Global0214DEC0 {
    char pad[8];
    int flags8;
};

extern struct Global0214DEC0 g_0214DEC0;
typedef unsigned int   u32;
extern void func_020895D8(u32 chBitMask, u32 flags);

int func_0207292C(int mask)
{
    if (mask == 0) return 1;
    if ((mask & g_0214DEC0.flags8) != 0) return 0;
    func_020895D8(mask, 0);
    g_0214DEC0.flags8 |= mask;
    return 1;
}
