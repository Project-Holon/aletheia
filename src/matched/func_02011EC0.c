/*
 * function: func_02011EC0
 * address:  0x02011EC0
 * packet:   pkt_02011EC0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012088     0x02012088  thumb
 *   func_020315D4     0x020315D4  arm
 *   func_020306F0     0x020306F0  arm
 *   func_02087BCC     0x02087BCC  arm
 *
 * Promoted from src/pending/ in the second 0-64 byte band pass (lane 1).  It
 * was parked there on the call to 0x02012088 only; func_02012088 now has an
 * EXACT entry of its own, so the site resolves through the `matched` class and
 * the file needs no change.  The fourth parameter is moved out of r3 at entry
 * and passed first; then the first parameter; the three func_020306F0 calls
 * with consecutive ids 3, 4, 5 and a final func_02087BCC(0).  Returns 1.
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02011EC0.c \
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
