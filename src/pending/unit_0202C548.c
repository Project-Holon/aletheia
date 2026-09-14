/*
 * unit:     yes
 * address:  0x0202C548
 * packet:   pkt_0202C4CC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * function: sub_0202C548, sub_0202C558, sub_0202C560,
 *           sub_0202C568, sub_0202C570, sub_0202C578, sub_0202C580,
 *           sub_0202C588
 *
 * symbols:
 *   func_0202C5AC  0x0202C5AC  thumb
 *   func_0202C5C4  0x0202C5C4  thumb
 *   func_0202C6A0  0x0202C6A0  thumb
 *   func_0202C6AC  0x0202C6AC  thumb
 *
 * Nine pool-word-and-bx tail calls back to back
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md), 4 bytes each with no
 * gap. Every concrete byte matches.
 *
 * sub_0202C550 was split out to src/matched/sub_0202C550.c (EXACT) to
 * witness sub_0202C3E0's call site. Of the rest: sub_0202C548
 * forward to the two unlabelled leaves hiding in the neighbouring pools
 * (src/matched/sub_0202C5AC.c, src/matched/sub_0202C5C4.c); sub_0202C570
 * and sub_0202C578 forward to the two unlabelled leaves of
 * src/matched/unit_0202C6A0.c; sub_0202C558 forwards to sub_0202C72C,
 * which has two direct callers elsewhere. All five resolve through the
 * `matched` or `label` class once
 * `python tools/match.py manifest --verify --shard pkt_0202C4CC` has
 * written those entries to disk.
 *
 * The remaining four were none of them called by a direct `bl`/`b`
 * anywhere in the image; each is reached only through the matching
 * trampoline here, which is inside the range under test. Two are now
 * matched: sub_0202C670 (src/matched/sub_0202C670.c, EXACT*) and
 * sub_0202C688 (src/matched/sub_0202C688.c, EXACT*, which needed
 * sub_0202C760 matched first as sub_0202C688's only witness for it).
 *
 * sub_0202C5F0 (src/pending/unit_0202C5F0.c) is a documented codegen near
 * miss, not an evidence gap: every concrete byte matches except a
 * register letter in its switch dispatch. sub_0202C710 needs
 * sub_0202C6C4 matched first, the same way sub_0202C688 needed
 * sub_0202C760: sub_0202C6C4's only caller in the ROM is the `bl` inside
 * sub_0202C710 itself, so it needs its own EXACT entry, not just a cut.
 * Neither has been written yet.
 *
 * Closes when the last two of the four are matched, or when the image
 * acquires a second, non-trampoline caller for one of them.
 *
 * Verified with:
 *   python tools/match.py tu --src src/pending/unit_0202C548.c \
 *       --addr 0x0202C548 --thumb
 */

typedef unsigned int u32;

extern u32 func_0202C5AC(void *p);
extern u32 func_0202C5C4(void *p, u32 a, u32 b);
extern u32 sub_0202C72C(void *p);
extern u32 sub_0202C670(void *p);
extern u32 sub_0202C688(void *p);
extern u32 func_0202C6A0(void *p);
extern u32 func_0202C6AC(void *p);
extern u32 sub_0202C5F0(void *p);
extern u32 sub_0202C710(void *p, u32 v);

u32 sub_0202C548(void *p)
{
    return func_0202C5AC(p);
}

u32 sub_0202C558(void *p)
{
    return sub_0202C72C(p);
}

u32 sub_0202C560(void *p)
{
    return sub_0202C670(p);
}

u32 sub_0202C568(void *p)
{
    return sub_0202C688(p);
}

u32 sub_0202C570(void *p)
{
    return func_0202C6A0(p);
}

u32 sub_0202C578(void *p)
{
    return func_0202C6AC(p);
}

u32 sub_0202C580(void *p)
{
    return sub_0202C5F0(p);
}

u32 sub_0202C588(void *p, u32 v)
{
    return sub_0202C710(p, v);
}
