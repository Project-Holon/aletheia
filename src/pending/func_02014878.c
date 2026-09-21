/*
 * function: func_02014878
 * address:  0x02014878
 * packet:   pkt_02014808
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * note:     re-verified 2026-09-20: MATCH; see verify output
 * note:     re-verified 2026-09-22 (family wave 6, field_status.c): still
 *           MATCH, 4 of 6 sites resolved, no change to the C.  The two
 *           own-pool words are unaffected by the widened sole-ref rules,
 *           and necessarily so: sole-ref/data and sole-ref/self both
 *           require the target to lie in a DATA SECTION, but 0x0000005B
 *           and 0x00000083 are absolute small integers that land nowhere
 *           in the image at all.  No widening of an address-based
 *           evidence class can ever reach them; only a second referrer
 *           elsewhere in the image (a `literal` witness) would, and there
 *           is none.  This row is closed at the bottom.
 * blocker:  own-pool: the two pooled small constants 0x0000005B and 0x00000083
 *           appear exactly once each in the whole arm9 image, in this
 *           function's own pool (0x02014900 and 0x02014908), so no `literal`
 *           witness exists and no cut can free them.
 *
 * symbols:
 *   ov091_id        0x0000005B  data
 *   ov131_id        0x00000083  data
 *   g_021BED00      0x021BED00  data
 *   g_021DC800      0x021DC800  data
 *
 * A six-state machine on obj->f1e.  Every concrete byte matches: 152 of 152
 * against the listing extent, the two relocation sites that are attestable
 * (both calls) resolve as `label`, and both 0x021BED00/0x021DC800 pool words
 * resolve as `literal`; only the two small pooled words stay wildcarded.
 *
 * The small pooled words are the SDK's FS_OVERLAY_ID() shape (see
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md): a
 * value that mwccarm materialises with `movs` for any literal in 0..255, and
 * therefore cannot be written as a number - the source passes an address the
 * linker resolved to 91 / 131, and is declared here as a symbol of that
 * absolute value.
 *
 * Two levers mattered, both from the wave-r6 list:
 *   * the switch value is read once into a local before the dispatch
 *     (`ldr r1, [r4]` before `cmp r1, #5`), which is what puts p[0] in r0;
 *   * a case that ends in "return 0" must `break` instead, so every arm
 *     shares the one epilogue at 0x020148FC instead of duplicating it.
 * The state-2 arm is three statements - `if (v == 0) { *mode = 5; break; }`,
 * `if (v == 1) { ...; *mode = 3; break; }` and a trailing `*mode = 5;` - and
 * only that spelling reproduces the arm's out-of-line `movs r0, #5` block at
 * 0x020148D2 with the second test as `bne` rather than `beq`.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02014878.c \
 *       --func func_02014878 --addr 0x02014878 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_020120B4(u32 a0, u32 a1, void *a2, u32 a3);
extern u32  func_020120F0(void);
extern u8   ov091_id[];
extern u8   ov131_id[];

u32 func_02014878(u32 a0, u32 *mode, u32 *p)
{
    u32 v = p[0];

    switch (*mode) {
    case 0:
        func_020120B4(v, (u32)ov091_id, (void *)0x021BED00, p[2]);
        *mode = 1;
        break;
    case 1:
        if (func_020120F0() != 0)
            break;
        *mode = 2;
        break;
    case 2:
        if (*(u32 *)(p[2] + 0x40) == 0) {
            *mode = 5;
            break;
        }
        if (*(u32 *)(p[2] + 0x40) == 1) {
            *(u8 *)(p[3] + 0xf) = (u8)*(u32 *)(p[2] + 0x3c);
            *mode = 3;
            break;
        }
        *mode = 5;
        break;
    case 3:
        func_020120B4(v, (u32)ov131_id, (void *)0x021DC800, p[3]);
        *mode = 4;
        break;
    case 4:
        if (func_020120F0() != 0)
            break;
        *(u32 *)(p[2] + 0x3c) = *(u8 *)(p[3] + 0xf);
        *mode = 0;
        break;
    case 5:
        return 1;
    default:
        break;
    }
    return 0;
}
