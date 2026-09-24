# Wave 21, lane C6: 0x02067080 (g2d DoAffineTransforme_)

**Verdict: DIFF 2, unchanged.** I re-verified the wave-13 source in `docs/notes/pkt_02066E30.c.txt`
with `match.py one` under `../2.0/sp2`: 704/704, 2 bytes out. The y read at +0x21C lands in ip,
where the image has r6. None of the research lane's five spellings, alone or combined, beats 2.

## What was done

- 65 `match.py one` runs, all built from the wave-13 source by text substitution
  (`/tmp/aletheia_laneC6/gen.py`, run with `mone.sh`).
- Each result is classed by its compiled instruction stream:
  - BASE: identical to the wave-13 output.
  - ITEM1: identical to wave 20C item 1 (y in r6, dy mla in ip).
  - new: any other output.

## Results (bytes out, 704 bytes unless stated)

| # | Spelling | Result |
| --- | --- | --- |
| 1 | `effectTypeAfter = G2_GetOBJEffect(pOam);` then `const BOOL b = effectTypeAfter == ...` | 2, BASE (byte-identical) |
| 1 | Assignment inside the initialiser: `(effectTypeAfter = G2_GetOBJEffect(pOam)) == ...` | 2, BASE |
| 1 | The comparison passed directly as the inline's argument | 684 bytes, 214 |
| 2 | `pV->y = GetY_(pV) + (dy + _11*halfH)`, and two operand-order variants | 5, new (y goes to r0 and coalesces with the sum; _11 goes to ip) |
| 2 | `GetY_(pV) + dy + _11*halfH` | 9 (re-associated) |
| 2 | `AddY_` (three bodies), `Add_(a, b)` in both orders, `Sum_(dy, _11, halfH)`, `AddX_` on x | 2, BASE |
| 3 | `pV->y += dy; pV->y += _11*halfH;` | 708 bytes, 150 (extra store kept). Discarded |
| 3 | The same split on x, then on both | 708/190, 712/208. Discarded |
| 4 | Block-scope `y` opened after the dy mla (5 forms: operand orders, `y +=`, `const`, GetY_) | 2, BASE |
| 5 | `short` halfW, halfH, both | 708/228, 708/201, 712/219. Each adds `lsl #0xf; asr #0x10`. Discarded |

Combinations: I ran items 1a and 1b against every item 2 and item 4 form, against item 1 of
wave 20C (with the y read spelled plain and through GetY_), and with the x-side helper.

- Every combination gives BASE, ITEM1 or the 5-byte GetY_ residue.
- None gives a fourth register assignment.

## Reading

- Variable identity of the effect web is inert under sp2: merging it with effectTypeAfter gives
  byte-identical code.
- Nested helpers either vanish (AddY_, Add_, Sum_) or move the tie to a worse one (GetY_ inside
  the expression).
- The split and short spellings change the code size.
- This is consistent with lane C5's model. The image pair needs an r6/r7 web coloured before
  the dy window, and none of these spellings creates one.

## Files touched

- `docs/notes/pkt_02066E30.c.txt`: one appended section, "2026-09-24, wave 21 (lane C6)".
- `docs/sessions/2026-09-24/reports/wave21_laneC6.md`: this report.

Nothing went to `src/matched/`, `src/pending/`, `tools/` or `layout/`. Scratch is under
`/tmp/aletheia_laneC6`.
