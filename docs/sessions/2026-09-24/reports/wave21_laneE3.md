# Wave 21, lane E3: blink_palanm 0x0202E1F0

Every verdict below comes from `tools/match.py one` (dsi/1.1p1, -O4,p, Thumb). About 150 compiles, all
written by hand. The permuter was not used.

## Result

| function | before | after | where |
|---|---|---|---|
| 0x0202E1F0 blink_palanm (412 B) | DIFF 2 | DIFF 2 | `docs/notes/pkt_0202E1F0.c.txt`, new dated section |

The residue is unchanged. At +008E the image passes w (`adds r0, r7, #0`) to func_02024368, while
o stays in r6. Two kinds of spelling were already known:
- **The g call reads w.** Then o and w swap registers (21 bytes out).
- **The g call does not read w.** The operand is then rematerialised as `add r0, sp, #0x38` (2 bytes out).

## What the measurements show

1. **The swap is a one-unit cost balance, not a tie.** Removing one post-loop o use from the 2-byte
   source flips o and w back. Adding one o use to the 21-byte source, in the tail or in the entry
   block, puts o in r6.
2. **w uses in the entry block after `w = ws` cost nothing.** Value numbering folds them to the constant
   in the same block, so they are not counted for w:
   - removing the func_0202465C use does not flip the swap;
   - adding a w use at the end of the block does not flip it.

   o uses in the same block do count. The w use at the g call sits in a later block, so it counts, and
   that one unit is the whole residue.
3. **Loop weights come from the CFG.** goto loops and `do/while(0)` or `for(;;)/break` wrappers change
   nothing.
4. **w must have exactly one explicit def and a live entry value.** A second `w = ws` anywhere folds the
   whole variable to the rematerialised constant (374 out). A dead stack parameter reused for ws does
   the same. So any copy of w is either folded to &ws (2 out) or copy-propagated back into w (21 out).
   The copy containers tried were a struct, a pointer array and an unsigned long copy of a void * w.
   All gave 2.
5. **The `volatile u16 c3` parameter is not needed.** `u16 c3` with `cnt = *(u16 *)&c3;` gives the same
   bytes (2 out in the best source). The re-read comes from c3 being address-taken, since the `o->f00`
   store may alias it. This spelling is more plausible than the volatile parameter.

The dead ends are listed with numbers in the notes:
- g-argument identities: `+0`, `|0`, `*1`, `&~0`, `^0`, `>>0`, `-0`, and an enum-zero add;
- o spellings that should emit no code: a cast through u32, `(void)o->f00`, an empty `if`, inline
  helpers, volatile fields;
- bitfield tail variants;
- actor/f20 index spellings and an explicit `ent`;
- a separate loop-2 counter, declaration moves and condition spellings;
- renaming o or w;
- temporaries inside a loop (these take w out of its register).

Still open: an o reference that survives until costing but emits no code.

## Files touched

- `docs/notes/pkt_0202E1F0.c.txt` (dated section appended)
- `docs/sessions/2026-09-24/reports/wave21_laneE3.md` (this file)

No source was filed to `src/matched/` or `src/pending/`. No shard was written, because there is no
EXACT or MATCH result. `tools/`, `layout/` and 0x0206DC00 were not touched. This lane used no other
decompilation or reconstruction project: no NitroSDK/NitroSystem reconstructions and no Pokemon decomps.
