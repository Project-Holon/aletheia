# Wave 17, lane 17A (text_font_anime): report

One function moved, nothing closed. Every measurement is in the function's note under a wave 17 heading.

| address | before -> after (bytes out) | verdict | what moved it / what was learned |
|---|---|---|---|
| 0x0201C7D0 | 2 (sp2) / 37 (1.1p1) -> same | DIFF | Compiled on all 18 front ends: every dsi build gives 37 and every 2.0 build gives 2, so no single front end has both traits and no pin can be taken. Three 1.1p1 pool-reload spellings: 37. |
| 0x0201C8BC | 17 -> 17 | DIFF | The "address-taken plain done" idea is refuted: `(void)&done`, a pointer local, an inline `int *` fill and a `{done; buf[3]}` struct all forward the zero (180/156, 184/149). |
| 0x0201D768 | 66 -> 66 | DIFF | Image operand and statement order gives 69. `register` is ignored. |
| 0x0201DB20 | 15 -> 15 (at 154) | DIFF | `register` on m or hi: 15. The residue is colouring order: hi takes r4 before m. |
| 0x02011688 | 26 -> 26 | DIFF | Diffed the 14-out early-return form. Two copy-and-multiply spellings: 26. |
| 0x02011D9C | 14 -> **8** | DIFF (a byte-exact source would still be MATCH) | `off = 0;` above the test, with the call in both arms. What remains: a cross-jump `b` and the CSE'd 4. Permuter hill 800: flat. |
| 0x0201B2B0 | 12 -> 12 | DIFF | func_02020FE4 prototype taken from its body (`void *` first): 12. |
| 0x0201FDA0 | 2 -> 2 | DIFF | A winDat local rebind and `(void)&` gave nothing. Front ends 1.2 to 1.6sp2: all 2. |
| 0x02013528 | 6 -> 6 | DIFF | A K&R definition gives 92. Callee arity checked: func_020130C4 takes one argument. |

Files written (notes only, appended): docs/notes/pkt_0201C7D0.c.txt, pkt_0201C8BC.c.txt,
func_0201D768.diff.c.txt, sub_0201DB20.c.txt, pkt_02011688.c.txt, pkt_02011D9C.c.txt (new best source),
sub_0201B2B0.c.txt, pkt_0201FC5C.c.txt, pkt_02013528.c.txt. No src files and no idiom files; no shards
verified.

Seeds: none.

For the integrator:
- The same residue class shows up three times: 0x0201FDA0, 0x02013528 and 0x0201B2B0. In each, the image keeps a parameter home store or stack-parameter load in its source position, and the compile schedules it across a neighbouring stack access. It may be worth one cross-function investigation.
- tools/match.py was briefly unparseable (another lane was mid-edit adding the `overlay_id` class). The D9C figure above still shows the three ov230 call sites as unresolved.
