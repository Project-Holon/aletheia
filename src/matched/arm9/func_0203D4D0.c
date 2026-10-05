/*
 * unit:     no
 * function: func_0203D4D0
 * address:  0x0203D4D0
 * packet:   pkt_0203D1B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203D798  0x0203D798  arm
 *   func_0203D394  0x0203D394  arm
 *   func_020395EC  0x020395EC  arm
 *   func_02039468  0x02039468  arm
 *   func_02038C18  0x02038C18  arm
 *
 * TU: net.c.
 *
 * The explicit-mask sibling of func_0203D3F8: identical guards, but the
 * destination bitmask arrives as the second parameter instead of being
 * derived from a send id, so there is no assert and no `lsl`, and the mask
 * stays in r6 across the whole body.  The two stack arguments that live
 * next to each other go out as one `stmib`.
 *
 * EXACT*, not EXACT: the inferred extent runs to 0x0203D578 because the
 * follower at 0x0203D56C has no label.  It is not a byte difference; the
 * follower is a twelve-byte ARM long-branch veneer (ldr ip, [pc]; bx ip;
 * .word 0x020394C0) that saves no lr and so is invisible to disasm.py.  It
 * wants seeding into layout/function_starts.txt, which is the integrator's
 * file.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D4D0.c \
 *       --func func_0203D4D0 --addr 0x0203D4D0 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern void *func_0203D798(void);
struct NetEntry;
extern u32 func_0203D394(struct NetEntry *e);
struct Entry;
extern int func_020395EC(struct Entry *a);
extern u32   func_02039468(u32 a, u32 b);
extern int func_02038C18(u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);

u32 func_0203D4D0(u32 entry, u32 mask, u32 c, u32 d, u32 e, u32 f, u32 g,
                  u32 h)
{
    func_0203D798();
    if (func_0203D394((struct NetEntry *)entry) == 0 && c >= 0x11) {
        return 0;
    }
    if (g != 0 && func_02039468(c, func_020395EC((void *)entry)) != 0) {
        return 0;
    }
    return func_02038C18(c, e, d, f, func_020395EC((void *)entry), mask, h);
}
