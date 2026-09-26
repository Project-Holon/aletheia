# SDK code in the overlay denominator (coverage fact-check)

Date: 2026-09-26. Fact-check of a claim that the overlay headline folds SDK
code into the denominator, so the true game-only overlay coverage is higher
than the reported figure. Applies to `tools/ovstats.py`, `tools/coveragemap.py`
and the README overlay line.

## Finding: the claim is correct in substance

A 237-overlay census by function start shows the overlay listings mix in code
that belongs to statically linked TwlSDK libraries (DWC/GameSpy networking,
libcrypto, camera, DSP). Those functions are catalogued per overlay in
`layout/symbols_sdk.json` (`region: ovNNN`, with a recorded `size`).

Counting every `func_`/`sub_` start that is *not* an SDK symbol as game code,
and every SDK symbol start as SDK code (extent to the next function label,
clipped to the listing's own `classified ... code` header):

| part | bytes |
| --- | ---: |
| overlay code (sum of listing headers) | 2,375,996 |
| overlay SDK code | ~466,350 |
| overlay **game** code | ~1,909,646 |

So roughly **20%** of the overlay "code" is SDK library code that no
decompilation lane should be credited (or charged) for. The denominator should
be the game-only figure.

## Second-order: the matched numerator also splits

The matched bytes counted from `layout/matched/ovNNN/` shards are not all game
functions either: some functions were matched at addresses that
`symbols_sdk.json` catalogues as SDK. Splitting the current matched set the same
way:

| part | bytes | functions |
| --- | ---: | ---: |
| overlay matched (all) | 340,916 | 5,649 |
| overlay matched, game | ~274,872 | ~5,021 |
| overlay matched, SDK | ~66,044 | ~628 |

Two defensible headline figures follow:

- **game coverage** = matched game / game code = 274,872 / 1,909,646 = **14.39%**
- **all matched over game code** = 340,916 / 1,909,646 = **17.85%**

The 16.8% figure in the flag was the *pre-wave-6* all-matched total over the
game-only denominator. The correct game-only figure is ~14.4%; the ~66 KB of
matched SDK is real decompilation progress but is not game code, so it is
reported separately (and drawn in its own colour).

## Caveats in this census

- The split is by function **start address** membership in the SDK symbol
  table. An SDK routine that `disasm.py` did not label (no `lr`-saving
  prologue) is counted as game; a game function that happens to share an
  address with a catalogued SDK symbol in an overlapping overlay is counted as
  SDK. Both are rare but nonzero.
- Using the SDK symbols' recorded `size` instead of the label extent
  over-counts badly (some recorded sizes overlap or exceed the overlay's code
  header), which is why the label-extent rule is used here.

## Recommendation

1. `ovstats.py` should exclude per-region SDK bytes from the overlay
   denominator and report `matched game` and `matched SDK` separately.
2. `coveragemap.py` should tint SDK blocks (dark) and matched-SDK blocks (its
   own colour) in the overlay treemap, and use the game-only denominator for
   the headline.
3. The README overlay line should quote the game-only figure and name the SDK
   share explicitly.

## Duplication note (for completeness)

Overlays are independently linked, but byte-identical game functions across
overlays are negligible: 230 functions / 14,520 bytes (0.76%) of overlay game
code, almost all in paired variants (ov117/ov118, ov122/ov123, ov221/ov222).
Only 34 SDK functions appear in more than one overlay. The 237 overlays are
effectively independent, so no free progress is available from cross-overlay
dedup.
