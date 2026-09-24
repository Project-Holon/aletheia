# Wave 21, lane C2: 0x02067080 (g2d DoAffineTransforme_)

**Verdict: DIFF 2, unchanged.** The best source is still the wave-13 source in
`docs/notes/pkt_02066E30.c.txt`. It re-verified with `match.py one` at the start of the
lane: 704/704 bytes, 2 bytes out under `../2.0/sp2`. The y read at +0x21C lands in ip,
where the image has r6.

## Angle

Lane C's reading was that the image's r6 needs ip held across +0x21C by a value that no
image instruction names. This lane tested that reading directly: first the listed kinds
of hidden live value, then the translation-unit context. About 115 compiles, no permuter
run. Every figure below is a `match.py` output.

## Results (bytes out; the full list is in the notes)

- **Dead stores kept** (`pV->y += 0`, `dead = halfW`, `dead = dead`, `pV->x = pV->x`):
  2 each. All were folded before allocation.
- **Volatile read with an unused result:** 708 bytes. The load is emitted, and y stays in ip.
- **Struct copies** (adjust core on a local copy, tail on a copy, pBaseTrans copied):
  704/79 to 720/637.
- **Arguments evaluated early and held** (pBaseTrans->x/y read at the top): 704/552 and
  704/512. The loads stay early, so there is no downward move.
- **64-bit intermediates** (s64 dy, (s64) products, the (s64) y sum): 708 bytes, or 704/43.
  One of them does put y in r6, but it does so through `smull` or a reordered block.
- **Parameters kept live** (an unused 4th parameter, an unused local, `register` on each
  local): 2 each. All 23 parameter orders of the adjust inline: 2 each.
- **Enum typing** (new dimension; the permuter's `--types` has no enum). Tried on dx, dy,
  halfW, halfH, the y local, the _11 operand, the flag, the NNSG2dFVec2 fields and the
  MtxFx22 fields: 2 each. An early enum y read gives the item-1 residue instead. The split
  point is still the dy mla.
- **The copy-terminated redefinition idiom on dx/dy:** 696 to 700 bytes. mwcc
  re-associates the expression into the whole-sum form.
- **Translation unit** (`match.py tu`, the matched neighbours' own sources merged):
  - 0x02067080 with 0x02067340: only the same 2 bytes out; both neighbours are
    byte-exact inside the unit.
  - 0x02066E30 with 0x02067080 and 0x02067340: the same 2 bytes.
  - The same unit with a static DoAffineTransforme_: the same 2 bytes.

  Putting the neighbours in the same file does not change allocation.

## Reading

In the image, halfW is the only value that uses ip. It dies at the same `mla` as _01, and
_01 shares r6 with the y read. So under the first-free order r0-r3, ip, lr, r4..., no
pre-allocation order of the image's instructions can keep halfW live across the y read.

For that order to produce the image, the hidden ip value would need every one of its
instructions deleted after allocation. Every candidate measured here was either folded
before allocation or emitted.

The first block (+0x008..+0x1D4) never uses ip or lr, even while they are free. So the
first-free order does not explain the whole function either. What is missing is a model of
the allocator, not another source spelling.

## Files touched

- `docs/notes/pkt_02066E30.c.txt`: one appended dated section, "2026-09-24, wave 21 (lane C2)".
- `docs/sessions/2026-09-24/reports/wave21_laneC2.md`: this report.

Nothing was written to `src/matched/` or `src/pending/`, because nothing reached MATCH or
EXACT, and no shard was written. `tools/` and `layout/` are untouched. Scratch files are
under `/tmp/aletheia_laneC2`.
