/*
 * function: GAMESYSTEM_ProcEnd
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
 *   GAMESYSTEM_Delete     0x02012088  thumb
 *   func_020315D4     0x020315D4  arm
 *   GFL_HEAP_DeleteChecked     0x020306F0  arm
 *   OS_ResetSystem     0x02087BCC  arm
 *
 * Promoted from src/pending/ in the second 0-64 byte band pass (lane 1).  It
 * was parked there on the call to 0x02012088 only; GAMESYSTEM_Delete now has an
 * EXACT entry of its own, so the site resolves through the `matched` class and
 * the file needs no change.  The fourth parameter is moved out of r3 at entry
 * and passed first; then the first parameter; the three GFL_HEAP_DeleteChecked calls
 * with consecutive ids 3, 4, 5 and a final OS_ResetSystem(0).  Returns 1.
 * Verified with:
 *   python tools/match.py one --src src/matched/GAMESYSTEM_ProcEnd.c \
 *       --func GAMESYSTEM_ProcEnd --addr 0x02011EC0 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

struct IcaAnime;
extern void GAMESYSTEM_Delete(struct IcaAnime *p);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *p);
extern void GFL_HEAP_DeleteChecked(u32 v);
extern void OS_ResetSystem(u32 v);

u32 GAMESYSTEM_ProcEnd(u32 a0, u32 a1, u32 a2, u32 a3)
{
    GAMESYSTEM_Delete((struct IcaAnime *)a3);
    func_020315D4((struct S020315D4 *)a0);
    GFL_HEAP_DeleteChecked(3);
    GFL_HEAP_DeleteChecked(4);
    GFL_HEAP_DeleteChecked(5);
    OS_ResetSystem(0);
    return 1;
}
