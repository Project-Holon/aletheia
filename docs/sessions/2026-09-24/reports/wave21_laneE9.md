# Wave 21, lane E9: blink_palanm 0x0202E1F0 (pragmas, flags, ws/w types, TU context)

Every verdict comes from `tools/match.py one --diff` or `tu` (dsi/1.1p1, -O4,p, Thumb). There were about
390 compiles, all scripted, and the permuter was not used. Scratch files are in `/tmp/aletheia_laneE9`
(`run.py`, `prag.py`, `wsobj.py`, `wtype.py`, `buildtu.py`, `oself.py`, `scope.py`, each with its `.c` and
`.out` files).

## Result

| function | before | after | where |
|---|---|---|---|
| 0x0202E1F0 blink_palanm (412 B) | DIFF 2 | DIFF 2 | `docs/notes/pkt_0202E1F0.c.txt`, section "wave 21 (lane E9)" |

Nothing was filed. Nothing was written to `src/matched/`, `src/pending/`, `tools/` or `layout/`.

## Measurements

Two sources were used. "base" is the wave-19 source (2 out). "s21" is base with the g call passed `w` (21 out,
o/w swapped).

| angle | what was measured | base / s21 |
|---|---|---|
| pragmas (push/pop around the function) | 45 optimizer pragmas, each set off and on, plus optimization_level 0-4 | 2 / 21 for almost all of them. The ones that do change code move the frame or the whole allocation, never only o/w (below) |
| | opt_lifetimes off | 17 (r4/r5 swap) / 35 |
| | opt_common_subs off | 122 / 120 (o goes to r5) |
| | opt_propagation off, opt_optimizecontrolflow off, optimization_level 3 | 208-217 (frame 0x4c) |
| pragma acceptance (`-w all`) | `scheduling` and `register_coloring` are rejected as illegal; `opt_pointer_analysis on` stops the compile | - |
| flags (`sweep --extra`, four versions) | -inline off/all, -ipa function; in the whole unit also -ipa file, -inline deferred, -opt nopeephole | 2 / 21 |
| | -inline auto (in the unit) | 472/476 bytes, because it inlines func_0202E040 |
| object behind &ws | 16 types: u64, s64, double, u16[4], s16[4], s32[2], void*[2], u8[2][4], float[2], u64[1], two unions, four structs | 2 / 21 each |
| ws position and scope | ws declared last, ws in a nested block, ws and marks in a nested block | 2 / 21 |
| w's declared type (s21 form) | 15 integer, pointer and function-pointer types | 21 each |
| TU context | the whole unit 0x0202E040-0x0202E38C with `match.py tu` | 2 bytes out; all four neighbours exact |
| | callee func_0202E040 defined before the target; the target declared static | 2 / 21 |
| language / definition | K&R definition | 428 / 424 bytes |
| | -lang c, c++, ec++ | 2 / 21 |
| | `inline` / `extern inline` | the function is not emitted |
| o self-defs (s21) | `&o->f00`, `&o[0]`, `&o[1] - 1`, `n ? o : o`, `& ~0u` | 21 (folded) |
| | `(u8 *)&o->f04 - 4` or `(u8 *)o->f20 - 0x20` before `o->f04 = 1` | 416/206: o=r6, w=r7, image-exact to +00C8, but it adds `adds; subs` |

## Findings

- **Pragmas.** No file in `src/matched` uses a pragma, so a pragma could only ever be a finding. None of them
  gives the image's registers without also changing other code.
- **The object behind &ws and the type of w.** The allocator ignores both. Every spelling tried gives the
  same 2 or 21 result.
- **The translation unit.** In its real unit, the four neighbours compile byte-exact. The target keeps the
  same +008E residue. A known callee body, the definition order and `static` change nothing.
- **A redefinition of o.** An unfolded self-redefinition of o before loop 2 reproduces the image's allocation
  through +00C8. This confirms that the residue is one o reference outside the loops. Every codeless spelling
  of that reference is folded before costing.

## Conclusion

The verdict stays DIFF 2. The best source is unchanged: the wave-19 source, or lane E7's fresh draft (both
412/412, 2 bytes out at +008E).
