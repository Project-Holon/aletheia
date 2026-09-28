# tree_ov021_2

## Relabel of 0x021CA5C4: blocked, needs a tool change

`layout/function_starts.txt` can only add seeds (`load_function_starts` feeds `add_seed`). No layout file removes a label. `disasm.py` gives every `bl` target a `func_` label (see docs/idioms/a-bl-target-inside-a-function-cuts-its-extent.md). 0x021CA5C4 uses `bl` as a long branch to about 50 inner targets (0x021CAB72 through 0x021CB6CA), so each one gets a label.

The fix needs a "not a function start" row type in tools/disasm.py, which the integrator owns. I edited nothing and regenerated no listing, so no shard extents changed. I did not attempt 0x021CA5C4.

## Tree under 021AA944 / 021A9F40

I filed 36 functions:

- **30 EXACT or EXACT\***, in src/matched/ov/ov021_func_<addr>.c with one shard each at layout/matched/ov021/pkt_ov021_<addr>.json. Each shard was verified twice and the second pass rewrote nothing.
  - 02188CFC 0219E2F4 021A30C8 021A3644 021A54B4 021A9508 021A954C 021A957C 021A996C 021A99A8 021A99E4 021A9B00 021A9B68 021A9C58 021A9CAC 021A9D30 021A9DC8
  - 021AA304 021AA35C 021AA3E0 021AA3FC 021AA490 021AA548 021AA69C 021AA6E0 021AA6F8 021AA728 021AB140 021AB580 021B7E60
  - I also widened the parameter of 021AB580 to u16 and re-verified it.
- **6 DIFF**, in src/pending/ov, with notes in docs/notes:
  - 021A9BE8: loop count reloaded (pkt_ov021_021A9BE8).
  - 021A9A5C: switch register allocation (pkt_ov021_021A9A5C).
  - 021A9780 and 021A96B8: argument scheduling before the func_02017588 call (pkt_ov021_021A9780).
  - 021B7DC0 and 021B7CD8: pairing in the Rect4 halfword copy (pkt_ov021_021B7DC0).

`manifest --check` is clean.

## Seeds (permuter)

| Seed | Function | Result |
| --- | --- | --- |
| 11501 | BE8 | no close |
| 11502 | A5C | no close |
| 11503 | 9780 | no close |
| 11504 | 96B8 | no close |
| 11505 | B7DC0 | closes only with a volatile param, not taken |

No new start seeds.

## ovstats ov021

tools/ovstats.py was re-committed at 14:01, which changed how it counts bytes. On the old tool the line read 75076 B, 1188 funcs, 28.39%. On the current tool:

| | Bytes | Funcs | Coverage |
| --- | --- | --- | --- |
| Before | 25242 | 1188 | 9.55% |
| After | 27556 | 1218 | 10.42% |

## Remainder

- **Roots:** 021A9F40, 021A9350, 021A9828.
- **021A30C8 deep subtree:** B7DE0, B7EE4, B91F8, B8848, B8894, B80E0, B810C, B88DC, B9238, B97D0, B97FC, B977C, B976C.
- **Other roots from the brief:** AA80C AA248 A2FE4 A3128 A3504 A3524 C868C AE0CC CFAC0 CFC14 CD440 A2F20 A2F6C 8DAEC 8B408 8AED4 8AF90 8ACA8 C3378, AAB1C AAFA0 AB018 AB070 AB0AC.
- **Other open ov021 roots:** CD6D0 8E7DC C1E7C 955EC 8F460 C82C4.
- **Near misses:** 89BD0 and B88DC are untouched.

There are no ov010 blockers from this pass.
