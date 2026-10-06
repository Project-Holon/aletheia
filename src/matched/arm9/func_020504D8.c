/*
 * function: func_020504D8
 * address:  0x020504D8
 * packet:   pkt_02050340
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02050550  0x02050550  arm
 *
 * Tick every live entry of the 0x28-stride array at o->f18: for each index
 * below the live count at o->f1C, skip the entry whose first word is the
 * sentinel 0xFFFF, otherwise call its per-entry hook (a function pointer at
 * +0x20, taking the owner, the index and the entry's +0x24 word) when one is
 * installed, then hand the entry to func_02050550.
 *
 * Two shapes are load-bearing:
 *
 *   - The live count is re-read from o->f1C at the BOTTOM of the loop
 *     (`ldrh r0, [r5, #0x1c]` at +0x60) as well as at the top, because the
 *     hook and func_02050550 may both change it.  Caching it in a local gives
 *     one load and a different loop shape.
 *   - The count is a u16 but the comparison is SIGNED (`blt`, and `pople` on
 *     the entry guard), so the index is a plain `int` and the count is
 *     promoted, not an unsigned compare.
 *
 * The 0xFFFF sentinel lives in the pool at 0x0205054C rather than as an
 * immediate, which is why r7 is loaded once before the loop.
 *
 * UNBLOCKED 2026-09-21: func_02050550 was filed EXACT
 * (src/matched/func_02050550.c, shard arm9/pkt_02050340.json), so the single
 * relocation site, the `bl` at +0x5C, is now attested `matched` and this file
 * verifies EXACT unchanged.  No C was altered to promote it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020504D8.c \
 *       --func func_020504D8 --addr 0x020504D8 --cc 1.1p1 --arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Entry {
    u32 f00;             /* 0x00 */
    u8  pad_04[0x1C];
    void (*f20)(void *o, int i, u32 a); /* 0x20 */
    u32 f24;             /* 0x24 */
};

struct Owner {
    u8            pad_00[0x18];
    struct Entry *f18;   /* 0x18 */
    u16           f1C;   /* 0x1C */
};

struct Ent;
struct Own;
extern void func_02050550(struct Own *o, struct Ent *e);

void func_020504D8(struct Owner *o)
{
    int i = 0;
    int n = o->f1C;

    if (n <= 0) {
        return;
    }
    do {
            struct Entry *e = (struct Entry *)((u8 *)o->f18 + i * 0x28);

            if (e->f00 != 0xFFFF) {
                if (e->f20 != 0) {
                    e->f20(o, i, e->f24);
                }
                func_02050550((struct Own *)o, (struct Ent *)e);
            }
        i++;
    } while (i < o->f1C);
}
