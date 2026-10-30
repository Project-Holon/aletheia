# A branch to next and a hop in a row select are stores and tails written per arm

summary: `cmp r0,#4; bls X; b Y; X: adds r0,#5; Y: b Z` and `bls Z; subs r0,#5; b Z; Z: str`
come from if/else arms that each store the result, with the shared tail statement written
again at the end of each outer arm. The compiler cross-jumps the copies after branch
threading, so the hops stay. A ternary, a named local or an inline helper compile without
the extra `b`.

Found in: src/game/ov135/worldtrade_input.c (Japanese UpdateCategoryGrid and
UpdateCategoryGridAlt).

The source form that matches:

    if (p->pos > 4) {
        if (p->last > 4) {
            p->pos = p->last;
        } else {
            p->pos = p->last + 5;
        }
        p->last = p->pos;
    } else {
        if (p->last > 4) {
            p->pos = p->last - 5;
        } else {
            p->pos = p->last;
        }
        p->last = p->pos;
    }

Tried without success: `p->pos = p->last; if (p->pos <= 4) p->pos += 5;` (stores early and
compares signed), `p->pos = p->last > 4 ? p->last : p->last + 5;`, a `u8` or `u32` block local,
two static inline helpers with early returns, and a nested ternary. With the stores per arm
but one shared `p->last = p->pos;` after the outer if, the then-arm branch goes straight to
the join (the hop through `b Z` is threaded away).

See also an-if-else-storing-to-one-target-keeps-the-empty-else-branch-to-next.md and
a-conditional-branch-onto-an-unconditional-b-is-a-cross-jumped-tail-copy.md.
