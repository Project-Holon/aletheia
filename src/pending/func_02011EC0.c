/*
 * function: func_02011EC0
 * address:  0x02011EC0
 * packet:   pkt_02011EC0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH, every concrete byte right
 *
 * symbols:
 *   func_02012088     0x02012088  thumb
 *   func_020315D4     0x020315D4  arm
 *   func_020306F0     0x020306F0  arm
 *   func_02087BCC     0x02087BCC  arm
 *
 * The fourth parameter again (moved out of r3 at entry), then the first; the
 * three func_020306F0 calls with consecutive ids 3, 4, 5 and a final
 * func_02087BCC(0).  Returns the constant 1.
 *
 * blocker:  label.  The only branch to 0x02012088 in the image is the call at
 *           +0x06 (no outside branch, no EXACT entry covering the target).
 *           src/matched/unit_02012088.c is the file that would close it, and
 *           that one is itself capped on the call to 0x02011F90 - so the pair
 *           graduates together or not at all.
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02011EC0.c \
 *       --func func_02011EC0 --addr 0x02011EC0 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern void func_02012088(u32 v);
extern void func_020315D4(u32 v);
extern void func_020306F0(u32 v);
extern void func_02087BCC(u32 v);

u32 func_02011EC0(u32 a0, u32 a1, u32 a2, u32 a3)
{
    func_02012088(a3);
    func_020315D4(a0);
    func_020306F0(3);
    func_020306F0(4);
    func_020306F0(5);
    func_02087BCC(0);
    return 1;
}
