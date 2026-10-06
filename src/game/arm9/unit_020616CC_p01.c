/*
 * file:     unit_020616CC_p01.c
 * unit:     yes
 * function: func_020616CC
 * address:  0x020616CC
 * packet:   pkt_020611D4
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146B74     0x02146B74  data
 *
 * VRAM (or comparable fixed-arena) BUMP ALLOCATOR STEP, against the {cur, end}
 * pair at 0x02146B74 that src/matched/func_02061808.c also exposes.  `size` is
 * rounded up to eight bytes (zero meaning eight) and refused above 0x7FFF8;
 * `dir == 1` allocates off the low cursor, anything else off the high one;
 * `flag` picks whether the alignment pad is derived from 8 or from 16, and in
 * the 8-byte case additionally caps the arena at 0x10000.  The packed result
 * is the allocated offset over eight in the low halfword and the rounded size
 * over eight in the high halfword, zero when the request cannot be satisfied.
 *
 * THE COMPILER PIN.  This function is `../2.0/sp2`, not the project default.
 * It is the *only* pinned file in this cluster; every other matched source in
 * 0x020611D4..0x02061824 is 1.1p1.  The evidence is recorded in
 * docs/FRONTEND-PINS.md and is the "kept constants" tell: 1.1p1 CSEs the pool
 * load of &g_02146B74 to function entry and keeps it live across the whole
 * body, which costs `push {r3, r4, r5, lr}` where the image has
 * `push {r4, lr}` and spends r5 on a value the image never names.  The image
 * re-materialises the address from the pool six times, at 0x020616FC,
 * 0x02061724, 0x02061754, 0x02061778, 0x02061798 and 0x020617C4, against the
 * single ABS32 at 0x02061804.  2.0/sp2 reproduces that rematerialisation
 * exactly, and with it the narrower push, with no change to the C at all.
 *
 * docs/notes/pkt_020613D8.c.txt records two "walls" measured for this function
 * under 1.1p1 across some thirty spellings.  BOTH ARE COMPILER ARTEFACTS AND
 * BOTH VANISH UNDER THE PIN:
 *   WALL 2 (the pool-address hoist, ~200 differing bytes, which the note
 *     correctly localised to "only when BOTH halves are present") is exactly
 *     the tell above.
 *   WALL 1 (the pad if/else in the `dir == 1` arm: 1.1p1 predicates both arms
 *     and emits no `beq`, where the image predicates the first and branches
 *     over the second) also disappears -- 2.0/sp2 emits the `beq` from a plain
 *     if/else, provided the `flag != 0` arm is written FIRST.  The note's
 *     nineteen pad spellings were all correct C fighting the wrong front end.
 *
 * Three source facts the byte comparison pins, all measured under the pin:
 *
 * 1. THE FAILURE PATHS ARE TWO DIFFERENT SHAPES, and writing them uniformly
 *    costs bytes either way.  The two "arena too small" refusals (`goto fail1`
 *    / `goto fail2`) reach a shared `mov lr, #0` block that each half owns, so
 *    they are gotos; the two `>= 0x10000` refusals are predicated in place
 *    (`movhi lr, #0` / `bhi`), so they are ordinary `ok = 0;` assignments
 *    followed by a jump to the tail.  Writing all four as `ok = 0` gives
 *    `movlo lr, #0` before every `blo` (two extra instructions); writing all
 *    four as gotos loses the predication on the 0x10000 pair.
 * 2. THE 0x10000 TEST IS `>`, NOT `>=`.  The image's `cmp rN, #0x10000` with
 *    `movhi`/`bhi` is the strictly-greater form; `>= 0x10000u` gives
 *    `movhs`/`bhs`, four conditions wrong.  Spelling the same boundary as
 *    `> 0xffffu` instead costs a pool word, because 0xFFFF is not an ARM
 *    rotated immediate while 0x10000 is.
 * 3. THE TWO HALVES NAME THEIR LENGTH SEPARATELY.  `len` in the `dir == 1`
 *    half and `ln` in the other are the same quantity `n + off`, but sharing
 *    one local across both halves puts the else half's `end` in ip and its
 *    length in r4, where the image has `end` in lr and the length in ip: eight
 *    concrete bytes, and the last residue tools/permuter.py could not move
 *    (2200 anneal candidates and 310 exhausted single mutations, both flat at
 *    eight).  Two locals is what separates the live ranges.
 *
 * The permuter did find the rest of the way in from the 73-byte hand-written
 * start: expand(addr), expand(len), commute(|), then temp(tmp = cur),
 * temp(tmp1 = cur + len) -- which is why `tmp1` names `cur + len` and the
 * return is written high-half-first.
 *
 * Filing this entry also unblocks src/pending/func_02051AA0.c in pkt_02051A54,
 * whose `bl` at +0x08 was capped at MATCH for want of a manifest entry here.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_020616CC.c \
 *       --func func_020616CC --addr 0x020616CC --arm --cc ../2.0/sp2
 *   EXACT, 316 bytes, 1 relocation site, resolved.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Arena02146B74 {
    u32 cur;    /* 0x00  low  cursor, grows upward   */
    u32 end;    /* 0x04  high cursor, grows downward */
};

extern struct Arena02146B74 g_02146B74;

/*
 * VRAM (or comparable fixed-arena) BUMP ALLOCATOR STEP, against the {cur, end}
 * pair at 0x02146B74 that src/matched/func_02061808.c also exposes.  `size` is
 * rounded up to eight bytes (zero meaning eight) and refused above 0x7FFF8;
 * `dir == 1` allocates off the low cursor, anything else off the high one;
 * `flag` picks whether the alignment pad is derived from 8 or from 16, and in
 * the 8-byte case additionally caps the arena at 0x10000.  The packed result
 * is the allocated offset over eight in the low halfword and the rounded size
 * over eight in the high halfword, zero when the request cannot be satisfied.
 *
 * THE COMPILER PIN.  This function is `../2.0/sp2`, not the project default.
 * It is the *only* pinned file in this cluster; every other matched source in
 * 0x020611D4..0x02061824 is 1.1p1.  The evidence is recorded in
 * docs/FRONTEND-PINS.md and is the "kept constants" tell: 1.1p1 CSEs the pool
 * load of &g_02146B74 to function entry and keeps it live across the whole
 * body, which costs `push {r3, r4, r5, lr}` where the image has
 * `push {r4, lr}` and spends r5 on a value the image never names.  The image
 * re-materialises the address from the pool six times, at 0x020616FC,
 * 0x02061724, 0x02061754, 0x02061778, 0x02061798 and 0x020617C4, against the
 * single ABS32 at 0x02061804.  2.0/sp2 reproduces that rematerialisation
 * exactly, and with it the narrower push, with no change to the C at all.
 *
 * docs/notes/pkt_020613D8.c.txt records two "walls" measured for this function
 * under 1.1p1 across some thirty spellings.  BOTH ARE COMPILER ARTEFACTS AND
 * BOTH VANISH UNDER THE PIN:
 *   WALL 2 (the pool-address hoist, ~200 differing bytes, which the note
 *     correctly localised to "only when BOTH halves are present") is exactly
 *     the tell above.
 *   WALL 1 (the pad if/else in the `dir == 1` arm: 1.1p1 predicates both arms
 *     and emits no `beq`, where the image predicates the first and branches
 *     over the second) also disappears -- 2.0/sp2 emits the `beq` from a plain
 *     if/else, provided the `flag != 0` arm is written FIRST.  The note's
 *     nineteen pad spellings were all correct C fighting the wrong front end.
 *
 * Three source facts the byte comparison pins, all measured under the pin:
 *
 * 1. THE FAILURE PATHS ARE TWO DIFFERENT SHAPES, and writing them uniformly
 *    costs bytes either way.  The two "arena too small" refusals (`goto fail1`
 *    / `goto fail2`) reach a shared `mov lr, #0` block that each half owns, so
 *    they are gotos; the two `>= 0x10000` refusals are predicated in place
 *    (`movhi lr, #0` / `bhi`), so they are ordinary `ok = 0;` assignments
 *    followed by a jump to the tail.  Writing all four as `ok = 0` gives
 *    `movlo lr, #0` before every `blo` (two extra instructions); writing all
 *    four as gotos loses the predication on the 0x10000 pair.
 * 2. THE 0x10000 TEST IS `>`, NOT `>=`.  The image's `cmp rN, #0x10000` with
 *    `movhi`/`bhi` is the strictly-greater form; `>= 0x10000u` gives
 *    `movhs`/`bhs`, four conditions wrong.  Spelling the same boundary as
 *    `> 0xffffu` instead costs a pool word, because 0xFFFF is not an ARM
 *    rotated immediate while 0x10000 is.
 * 3. THE TWO HALVES NAME THEIR LENGTH SEPARATELY.  `len` in the `dir == 1`
 *    half and `ln` in the other are the same quantity `n + off`, but sharing
 *    one local across both halves puts the else half's `end` in ip and its
 *    length in r4, where the image has `end` in lr and the length in ip: eight
 *    concrete bytes, and the last residue tools/permuter.py could not move
 *    (2200 anneal candidates and 310 exhausted single mutations, both flat at
 *    eight).  Two locals is what separates the live ranges.
 *
 * The permuter did find the rest of the way in from the 73-byte hand-written
 * start: expand(addr), expand(len), commute(|), then temp(tmp = cur),
 * temp(tmp1 = cur + len) -- which is why `tmp1` names `cur + len` and the
 * return is written high-half-first.
 *
 * Filing this entry also unblocks src/pending/func_02051AA0.c in pkt_02051A54,
 * whose `bl` at +0x08 was capped at MATCH for want of a manifest entry here.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_020616CC.c \
 *       --func func_020616CC --addr 0x020616CC --arm --cc ../2.0/sp2
 *   EXACT, 316 bytes, 1 relocation site, resolved.
 */
u32 func_020616CC(u32 size, u32 flag, u32 dir)
{
    u32 n;
    u32 off;
    u32 len;
    u32 addr = 0;
    u32 ok;
    int cur2;
    u32 top;
    u32 ln;

    if (size == 0) {
        n = 8;
    } else {
        n = (size + 7) & ~7u;
    }
    if (n >= 0x7fff8u) {
        return 0;
    }

    if (dir == 1) {
        u32 cur = g_02146B74.cur;

        if (flag != 0) {
            off = (8 - (cur & 7)) & 7;
        } else {
            off = (16 - (cur & 0xf)) & 0xf;
        }
        len = n + off;
        if (g_02146B74.end - cur < len) {
            goto fail1;
        }
        top = cur + len;
        if (flag != 0 && top > 0x10000u) {
            ok = 0;
            goto done;
        }
        addr = cur + off;
        g_02146B74.cur = g_02146B74.cur + len;
        ok = 1;
        goto done;
fail1:
        ok = 0;
        goto done;
    } else {
        u32 end = g_02146B74.end;

        if (end < n) {
            goto fail2;
        }
        if (flag != 0) {
            off = (end - n) & 7;
        } else {
            off = (end - n) & 0xf;
        }
        ln = n + off;
        cur2 = g_02146B74.cur;
        if (end - cur2 < ln) {
            goto fail2;
        }
        if (flag != 0 && end > 0x10000u) {
            ok = 0;
            goto done;
        }
        ok = 1;
        g_02146B74.end = g_02146B74.end - ln;
        addr = g_02146B74.end;
        goto done;
fail2:
        ok = 0;
        goto done;
    }

done:
    if (ok == 0) {
        return 0;
    }
    return ((n >> 3) << 16) | ((addr << 13) >> 16);
}
