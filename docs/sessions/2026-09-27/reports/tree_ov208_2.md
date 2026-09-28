# tree_ov208_2 (ov208, relaunch)

## Tree

Root 0x021C6E98 (1456 B, soft-float) is now EXACT, and its whole tree is closed. After that the lane walked down into the tree of the parent 0x021C3D3C (1372 B). That tree has about 45 open functions, so the cap applied. The parent itself was not attempted.

## Salvaged (9, each re-verified, shard verified twice with 0 rewritten)

021BC3BC, 021BDAAC, 021BDCF8, 021BDD98, 021BE3C4, 021BE504, 021C4D68 (EXACT\*, an enum y keeps 0x11 converted at run time), 021C5F34, 021C7D80. The old `src/pending/ov208_func_021C4D68.c` was moved to matched.

## New EXACT/EXACT\* (35)

- 021C6E98: see the new idiom file `docs/idioms/a-flag-argument-written-as-a-ternary-statement-keeps-left-to-right-argument-loads.md`. Two levers closed it: byte-pointer entry fields, and a ternary statement for the shiny flag. The second pair of models bobs by -16.0f.
- 021BD148: EXACT against the 021BD634 label. The extern says u32 because the image passes the heap without narrowing it.
- Small functions: 021BDAD0, 021BDAD4, 021BE840, 021BE844, 021BE854, 021BE864, 021BEA00, 021BC4C8, 021BC4D8, 021BC4E4.
- Other functions: 021BC46C, 021BC758, 021BC844, 021BC9BC, 021BE1BC, 021BDBB8, 021C48CC, 021C4B2C, 021C5000, 021C5090, 021C5128, 021C5214, 021C5248, 021C569C, 021C5C64, 021C6BB4, 021C6C00, 021C6D10, 021C6DD8, 021C6E60, 021C7E74, 021C7EF8, 021C7F6C.

## Pending

- 021BD634: DIFF, 8 bytes. 021C5CF0: DIFF, 19 bytes. Fresh tries are appended to their notes; nothing closed them.
- 021C4F78: DIFF, 18 bytes. A result is moved to r1 before a store. Permuter seed 9101 was used. The notes file is new.
- 021C52F0: MATCH\*. The code is exact, but three callees in ARM9 have no label: 0x0201BC3C, 0x0201BC78, 0x0201BCEC.

## Next lane (open under 0x021C3D3C)

021C53F4 (624), then 021C5664 (its caller), 021C580C, 021C5D64, 021C692C, 021C75FC, then 021C3D3C. After that the roots 021C625C, 021C7860, 021BF9B0, then ov135.

## Seeds / integrator

- These unlabelled starts are now EXACT:
  - 0x021BDAD0, 0x021BDAD4, 0x021BE840, 0x021BE844, 0x021BE854: bl from 021C3D3C.
  - 0x021BE864: pool word at 0x021BE774.
  - 0x021C5248: pool word at 0x021C519C.
  - 0x021BC4C8, 0x021BC4D8, 0x021BC4E4, 0x021BEA00: no witness was found, but each is a bx-lr body between a pop and a push.
- ARM9 seeds: 0x0201BC3C, 0x0201BC78, 0x0201BCEC (bl sites at 0x021C5304, 0x021C531E, 0x021C5324).
- Symbols: the runtime name for 0x0209BDBC is `_fflt`, and 0x0200CA1C and 0x0200CA98 are Thumb.
