# Wave 16, bg_sys / gf_standard / g3d_util / palanm lane

EXACT 2 (2064 bytes), MATCH 0, DIFF 4 (one moved 18 -> 14).

- bg_sys.c 0x020433E0 (188 B): 6 -> EXACT. The two OBJ-VRAM mapping words as GXOBJVRamModeChar enum fields
  passed straight into the SDK inlines GX_SetOBJVRamModeChar / GXS_SetOBJVRamModeChar (enum parameter), with a
  `const` descriptor. u32 types 33, non-const or volatile descriptor 29, a/b locals 6.
- bg_sys.c 0x0203FCA0 (1876 B): 1860/1171 -> EXACT. The wave 11/12 SDK BGxCNT inline setters, now with the
  SDK's enum parameter types (GXBGScrSizeText/Affine, ColorMode, ScrBase, CharBase, ExtPltt, AreaOver); int
  parameters still 1860/1171. Type-2 arm is a game-side inline (no 0x80 ext bit, charBase before screenBase).
  Both are the lever already in docs/idioms/an-enum-type-keeps-values-out-of-constant-folding.md.
- g3d_util.c 0x02048744 (468 B): 18 -> 14. `long i, j` (TwlSDK s32 is long) puts objTbl/j in r8 as the image;
  left: resIdx r7 / i sb swapped. Permuter hill 600 + anneal 1500 --types flat at 14. Best source in note.
- gf_standard.c 0x0203F0A8 (340 B): 16 -> 16. Reference-code types (unsigned long, UL masks), long kk, scopes,
  reassociated subscripts, volatile cast read, const mag01: all 16. Loop 2 is one instruction off.
- palanm.c 0x02021848 / 0x0202173C: 33 -> 33. u8 callee return, callee prototype facts, unprototyped callee,
  narrow/enum/long `a`, volatile copies, sp2/sp2p2: 33 or worse. Reading recorded: the image orders the [sp,#8]
  store and reload with the other stack stores (memory object, not a spill). Listings still give 2-byte extents.

Notes appended: func_020433E0.c.txt, func_0203FCA0.c.txt (closures), pkt_02048330.c.txt, func_0203F0A8.c.txt,
func_0202173C.c.txt.

Integrator: seed: none (both filed addresses are labelled).
Integrator: 0x0202173C and 0x02021848 still show 2-byte extents in `match.py show`; the listings need regenerating.

Shards verified: pkt_020433E0 (1 entry EXACT), pkt_0203FCA0 (1 entry EXACT). They do not witness each other.
