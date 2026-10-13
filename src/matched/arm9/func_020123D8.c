/*
 * function: GAME_EVENT_StartByCreator
 * address:  0x020123D8
 * packet:   pkt_020123D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetEvent     0x02012104  thumb
 *   GAMESYSTEM_SetEvent     0x02012108  thumb
 *
 * The packet's driver: reject when GAMESYSTEM_GetEvent says the object is busy,
 * reject a null callback, run the callback with the object and the second
 * argument, reject a zero result, hand a non-zero result to GAMESYSTEM_SetEvent and
 * report 1.
 *
 * The two spellings differ by four bytes of layout.  Written with the
 * "invert the guard" shape
 *
 *     if (GAMESYSTEM_GetEvent(o) != 0) return 0;
 *     if (fn == 0) return 0;
 *     r = fn(o, a2);
 *     if (r != 0) { GAMESYSTEM_SetEvent(o, r); return 1; }
 *     return 0;
 *
 * mwccarm lays the two `movs r0, #0; pop` arms inline and falls through into
 * the success arm, which is what the original does.  Swapping the last pair to
 * `if (r == 0) return 0; else { ... return 1; }` makes it test `bne` and move
 * the success arm out of line (+0x24 onward), and a `goto fail` spelling
 * reproduces only 44 of the 52 bytes: the goto drops the `adds r1, r0, #0`
 * copy that keeps the callback result live for GAMESYSTEM_SetEvent and reorders the
 * callback call.  The reachable spelling is the plain one.
 * Verified with:
 *   python tools/match.py one --src src/matched/GAME_EVENT_StartByCreator.c \
 *       --func GAME_EVENT_StartByCreator --addr 0x020123D8 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

struct Ctx;
extern u32 GAMESYSTEM_GetEvent(const struct Ctx *p);
extern void GAMESYSTEM_SetEvent(struct Ctx *p, u32 v);

int GAME_EVENT_StartByCreator(void *o, u32 (*fn)(void *, void *), void *a2)
{
    u32 r;

    if (GAMESYSTEM_GetEvent(o) != 0)
        return 0;
    if (fn == 0)
        return 0;
    r = fn(o, a2);
    if (r != 0) {
        GAMESYSTEM_SetEvent(o, r);
        return 1;
    }
    return 0;
}
