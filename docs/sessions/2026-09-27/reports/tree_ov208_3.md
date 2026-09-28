# tree_ov208_3 (ov208)

## Tree

Subtree of the parent 0x021C3D3C (1372 B): the six named functions were worked in order. Four are EXACT, one is MATCH and one is DIFF. The parent and the roots 021C625C, 021C7860 and 021BF9B0 were not started, because the lane's context budget ran out.

## New EXACT (4; each shard verified twice, second pass 0 rewritten)

- 021C5664: a wrapper that passes `p + 0x148` and five u16 slots at 0x548..0x550 to 021C53F4.
- 021C580C: EXACT on the first draft. The `W(0x124) != 0 ? 0 : 4` ternaries give the right polarity.
- 021C5D64: the result-5 arm has to sit outside the switch, as `if (r != 5) switch ... else ...`. Otherwise mwcc builds a six-entry table where the image has 0..3 plus a separate compare.
- 021C692C: byte-pointer entry fields, with the operand order as the lever. `p + 0x614 + i * 0x28` (base first) is used for the switch state and the partner object; `p + i * 0x28 + off` is used everywhere else.

## Pending

- 021C75FC: MATCH. All bytes are correct. The one wildcard is `x >= tx`, which compiles to `_fgeq` at 0x0209BB54: the unlisted float comparator noted in src/matched/compares.c. The header records the blocker. `_fleq` resolves to 0x0209BC0C (__fcmp_2).
- 021C53F4: DIFF, 20 bytes. Only the spill slots of `species` and `i` are swapped. The levers and every sweep are in docs/notes/pkt_ov208_021C53F4.c.txt. Permuter seed 9901 was used.

## Next lane

021C3D3C. All its ov208 callees except 53F4/75FC/52F0/4F78/625C/7860 are now witnesses. Then 021C625C, 021C7860, 021BF9B0, and after that the fresh drafts of 021BD634, 021C5CF0 and 021C4F78.

## Integrator

- Add a runtime row: `0209BB54  _fgeq  MSL/runtime.a  arm9_main`. That makes 021C75FC EXACT; move it to matched and verify shard pkt_ov208_021C75FC.
- Files: src/matched/ov208_func_021C5664.c, _021C580C.c, _021C5D64.c, _021C692C.c; src/pending/ov208_func_021C53F4.c, _021C75FC.c; the four pkt_ov208_* shards; docs/notes/pkt_ov208_021C53F4.c.txt.
- 021C53F4's body is still in the permuter's two-space layout and needs normalising.
