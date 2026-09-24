# Wave 21, lane E12: blink_palanm 0x0202E1F0 (statement structure), closed EXACT

Every verdict comes from `tools/match.py one --diff` (dsi/1.1p1, -O4,p, Thumb). There were about 40 compiles,
all scripted, and the permuter was not used. Scratch files are in `/tmp/aletheia_laneE12` (`run.py`, `t1.py` to
`t4.py`, each variant as `v_*.c` with its `.out`).

## Result

| function | before | after | where |
|---|---|---|---|
| 0x0202E1F0 blink_palanm (412 B) | DIFF 2 | EXACT | `src/matched/func_0202E1F0.c`, `layout/matched/arm9/pkt_0202E1F0.json` |

`python tools/match.py manifest --verify --shard arm9/pkt_0202E1F0` reports EXACT with 0 entries rewritten. This
was the last open function. Nothing in `tools/` was touched, and nothing was committed.

## The close: two changes that do nothing alone

1. The call to func_02024368 after loop 1 takes the reused parameter (`param`/`w`) and not `&mp`. This is s21,
   21 out: +0x8E is already `adds r0, r7, #0`, but o and w have swapped registers.
2. The two stores after func_0202465C are written `wk->msg = a3; wk->active = 0;`, not active first. The
   scheduler emits `strb` before `str` in both orders, so the listing never showed the order. Only the register
   allocation reflected it.

Measured on each base:

| change | on s21 | on base (2) |
|---|---|---|
| store swap | EXACT | 2 |

The filed source is lane E7's fresh draft, with its callee widths read from the matched callees. Only those two
lines are changed. The same pair is also EXACT with each of these variants:

- `void *w`
- `u16 c3` plus `cnt = *(u16 *)&c3`
- func_0201D478 declared as `(void)`

## Shapes measured (s21 / base, 412 bytes unless noted)

| shape | s21 | base |
|---|---|---|
| `f04 = 0` first statement | 30, o=r6 | 32 |
| `f04 = 0` between the first call and `w = ws` | 18, o=r6 | 20 |
| **`f04 = 0` after `f00 = a3`** | **0** | 2 |
| `f04 = 0` after the 441C call / after 0201D478 | 17 / 26, o=r6 | 19 / 28 |
| `f00 = a3` first statement | 38, o=r6 | 40 |
| both stores first / between the call and the def | 55 / 47, o=r7 | 42 / 33 |
| `w = ws` def after 465C, after the o stores, after cnt / after 441C / after `n =` | 37 / 47 / 56, o=r7 | 22 / 33 / 364 |
| `o->f04 = i = 0`, `i = 0; o->f04 = i;` | 21 | 2 |
| `o->f04 = marks[0]` | 412/344 | 412/344 |
| marks initialised by statements (3 forms) | 408 bytes | 408 bytes |

The loop-merging, inline-helper and early-return shapes in the brief were not run because the store order closed
the function first. Wherever `f04 = 0` is placed other than directly after `f00 = a3`, o gets r6, but the placement
moves the `strb`.
