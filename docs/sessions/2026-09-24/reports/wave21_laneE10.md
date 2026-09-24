# Wave 21, lane E10: blink_palanm 0x0202E1F0 (an o reference on an existing instruction)

Every verdict comes from `tools/match.py one --diff` (dsi/1.1p1, -O4,p, Thumb). There were 71 compiles, all
scripted, and the permuter was not used. Scratch files are in `/tmp/aletheia_laneE10` (`run.py`, `t1.py` to
`t6.py`, each variant as `v_*.c` with its `.out`).

## Result

| function | before | after | where |
|---|---|---|---|
| 0x0202E1F0 blink_palanm (412 B) | DIFF 2 | DIFF 2 | `docs/notes/pkt_0202E1F0.c.txt`, section "wave 21 (lane E10)" |

Nothing was filed. Nothing was written to `src/matched/`, `src/pending/`, `tools/` or `layout/`.

## Attribution: image instructions that touch o (r6)

| image | instruction(s) | our source |
|---|---|---|
| +0004 | `adds r6, r0, #0` | o's entry def |
| +0036 | `strb r4, [r6, #4]` | `o->f04 = 0` (r4 is the shared zero) |
| +0038 | `str r0, [r6]` | `o->f00 = a3` |
| +0064-68 | `lsls; adds r0, r6, r0; str r5, [r0, #0x20]` | loop 1 `o->f20[i] = 1` |
| +0096 | `ldr r0, [r6]` | g block `func_02045770(o->f00)` (for 02043B5C) |
| +00A2 | `ldr r0, [r6]` | g block `func_02045770(o->f00)` (for 0201C724) |
| +00CE | `strb r0, [r6, #4]` | `o->f04 = 1` |
| +00D8-DE | `lsls; adds r1, r6, r0; str r1, [sp, #0x18]; ldr r1, [r1, #0x20]` | loop 2 o + 4i (CSE'd, spilled), `o->f20[i]` |
| +0110-14 | `ldr r0, [sp, #0x18]; ldr r0, [r0, #8]` | loop 2 `o->actor[i]` through the slot (no o read) |
| +0172 | `ldr r0, [r6]` | tail `func_02045374(o->f00)` |
| +0178 | `ldr r0, [r6]` | tail `func_02045730(o->f00)` |
| +0182 / +0190 | `ldr r1, [r6, #0x18]` ... `str r0, [r6, #0x18]` | `f18.b0 = 1; f18.b1 = 1` (one merged RMW) |

The remaining memory accesses are marks at sp+0x40, cs->f00/f04 through two reloads of the spilled cs, c3/c1
through the stack-parameter base sp+0x60, and spill slots. None of them can be o + k. Every call argument is
set by its own instruction or is the previous call's r0 (h for func_0201D478, 02045730's result for
func_02041B6C). No call gets r6 or a value derived from it, and no callee prototype in `src/matched` has a
spare trailing parameter that could take o without a mov.

## Measurements (from s21 = the g call passed w, 21 out, o=r7; base stays 2 throughout)

| candidate | result |
|---|---|
| `u8 *act = &o->f04` (both f04 stores, or either one) | 21 (folds back into o) |
| `u32 *msg = &o->f00` (all f00 accesses, or the tail only) | 21 |
| `u32 *bl = o->f20` (loop 1 / loop 2 / both) | 424/383, 424/401, 436/414 (own web) |
| `void **ac = o->actor`; `struct Flags *fl = &o->f18` | 424/401, 424/406 |
| explicit element `((struct Obj *)((u32 *)o + i))->f20[0]` / `actor[0]`, a variable `e`, `u32 *e` | 21 (the same o + 4i web); only one of the two: 416/163 |
| bitfields as two RMWs (`*(u32 *)&o->f18 \|= 2`, `((u32 *)o)[6] \|= 2`, masks) | 21 (merged before costing); `\|= 1`/`\| 3` forms 408 bytes |
| E9's unfolded address used as an access base (f04, f00, g-block and tail reads) | 21 (folded) |
| 12 more o self-def spellings (zero offsets, no-cast `&o->f04 - 4`, `o->f20 - 8`, `o->actor - 2`, pointer differences) | 21 (folded) |
| `return o;` | 412/6: o=r6, w=r7, image-exact +0000 to +0190; the added `adds r0, r6, #0` takes the pad |
| `return *(u32 *)&o->f18` | 21 (forwarded) |

## Conclusion

The image's 12 instructions that read or write o correspond one to one to ours. No existing instruction
carries an o reference that our source spells through another variable, a derived pointer or a call argument.
Derived pointers fold into o or become their own webs. Merged and forwarded accesses are merged before costing.
Only a (u8 *) cast stops an o self-def from folding, and every unfolded form emits arithmetic. The verdict
stays DIFF 2. The best source is unchanged: the wave-19 source, or lane E7's fresh draft (both 412/412, 2
bytes out at +008E).
