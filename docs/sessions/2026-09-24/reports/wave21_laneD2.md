# Wave 21, lane D2: 0x02048744 (g3d_util.c, 468 bytes), colouring-order experiments

**Verdict: DIFF 14, unchanged.** The best source is still the wave-16 long source in
`docs/notes/pkt_02048330.c.txt`. I re-verified it at the start and end of the lane with
`match.py one`: 468/468 bytes, 14 concrete bytes out, 9 of 9 relocations resolved. The residue
is unchanged: resIdx is r7 in the image and sb in the compile, and i is sb in the image and r7
in the compile.

## Method

This lane did not add another blind sweep. Every compile's `--diff` was read back for four
register webs: resIdx (+0x14), i (+0x28), objTbl (+0x50) and j (+0x134). That gives each lever
a direction, not only a byte count. It took about 183 compiles, with no permuter run. Each
spelling and its bytes out are in the dated section "2026-09-24, wave 21 (lane D2)" of the
notes file.

## Findings

Rank order is written sb > r8 > r7. The image order is i > tbl/j > res.

1. **tbl and j always share one slot, and j's type decides where it goes.** A named tbl local
   is copy-propagated and makes no difference.
2. **There are three bands:**
   - Int-class webs rank above resIdx. The int class is int, u32, unsigned, enum and pointer.
   - Long-class webs rank below resIdx. The long class is long, unsigned long and
     register long.
   - Inside the int band, tbl/j outranks i. This holds for every declaration order,
     every placement of j's definition and every statement order.

   The effect of the types:
   - int/int gives tbl/j > i > res (18 bytes).
   - long/long gives res > tbl/j > i (14 bytes).
   - int i with long j gives i > res > tbl/j (18 bytes).
   - Long webs rank among themselves by declaration order, with the later declaration higher.
3. **`short i; int j;` reproduces the image ranking exactly** (res r7, i sb, tbl/j r8), at
   476 bytes. Every other byte is right; the extra 8 bytes are the sign-extending increment.
   So the rank comes from the IR shape of i's back-edge definition, not from a type rank. No
   32-bit spelling reproduces it. I tried eight increment forms that fold away, while and goto
   loops, carried copies, `n = i + 1` copies, and moving the increment into the body. Moving
   the increment into the body pushes i down, not up.
4. **The inner loop's `a` merge is what keeps an int j above i.** The image copies the `a = 0`
   constant from j's zero (`mov fp, r8`). Writing the stores in each arm, or using a `continue`
   arm, drops int j below resIdx: i becomes sb as in the image, but resIdx and tbl/j swap
   (23 bytes) and the merged store is lost.
5. **These are inert:**
   - Source-level use counts (all CSE'd away before colouring).
   - The type of `a`.
   - Block scope for j.
   - resIdx as int or u32 with matching helper parameters.

   These make things worse:
   - Long resIdx sends resIdx to r4 (58 bytes).
   - An inline worker taking the unit fields as parameters (36 to 47 bytes, or 472 bytes).
   - A per-object inline with i as a parameter (45 to 47 bytes).
   - unitIdx reused as j (472 bytes).
6. The C99 `for (int j = 0; ...)` declaration is a CCERR under 1.1p1 with -lang c99.

What would close it: a 32-bit spelling in which i's back-edge definition is not an in-place add
(the property short has), or one in which j keeps the `a` merge but ranks below i. Neither was
found.

## Best bytes out

14 (unchanged).

## Files touched

- `docs/notes/pkt_02048330.c.txt`: appended the section "2026-09-24, wave 21 (lane D2)".
- `docs/sessions/2026-09-24/reports/wave21_laneD2.md` (this report).

Nothing was filed in `src/matched/` or `src/pending/`, and no shard was written or
re-verified, because there was no EXACT or MATCH. Scratch work is in
/tmp/aletheia_laneD2/w; `log.txt` has one line per compile with its register readout.
No outside decompilation or reconstruction was consulted at any point in this lane.
