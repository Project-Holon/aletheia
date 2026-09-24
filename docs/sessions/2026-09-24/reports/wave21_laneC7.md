# Wave 21, lane C7: 0x02067080 (g2d DoAffineTransforme_)

**Verdict: DIFF 2, unchanged.** I re-verified the wave-13 source in `docs/notes/pkt_02066E30.c.txt`
with `match.py one` under `../2.0/sp2 -O4,p`: 704/704, 2 bytes out. The y read at +0x21C lands in
ip, where the image has r6. Nothing was filed, and src/, tools/ and layout/ are untouched.

## What was done

- About 320 `match.py one` compiles, all generated from the wave-13 source by script.
  Scratch is in `/tmp/aletheia_laneC7`: `run.py`, `runf.py` and `gen*.py`, with `R_*.txt` holding
  the results.
- Each result is classed by a hash of the whole compiled column. BASE means byte-identical to the
  wave-13 output. ITEM1 means byte-identical to wave 20C item 1.

## Angles (bytes out, 704 bytes unless stated)

| Angle | Result |
| --- | --- |
| Optimizer pragmas, one at a time, push/pop around everything: 38 pragmas off/on, mem limits 1..500, pointer-analysis modes, inline_depth, optimization_level 2-4 | All BASE, including opt_lifetimes, opt_loop_invariants, opt_strength_reduction, scheduling and peephole |
| Pragmas that change code | opt_common_subs off 712/493, opt_propagation off 696/238, opt_dead_code off 684/301, opt_dead_assignments off 716/494, opt_prelinearize off 13 (first block recoloured, residue kept), others 500+ |
| Pragma house style | No src/matched or src/pending source uses any `#pragma`, so nothing here would be fileable |
| Command-line flags | -O2,p, -O3,p and `-opt level=2..4,speed` are BASE, so level-4 repeated CSE is not the cause. `-opt no{cse,prop,lifetimes,...}` do nothing in this build. -pid 4, -pic 486, `-enum min` 598. -O4, -O4,s and `-inline off` stop inlining |
| Unswept compilers | ../1.2/base, sp2, sp2p3 744/612; ../1.2/sp3 740/607; dsi/1.1 684/323; dsi/1.1p1 and dsi/1.2 676/560. Every build in tools/ has now been measured |
| Types | fx32, s32, fields, halfW/halfH, dx/dy as int, long, u32 or fx32: BASE. Size inlines returning u32 4, GXOamShape u32 4, attr01 s32 3, BOOL u8 4 (residue plus a sign/test change). u32 fields 772/531 |
| Qualifiers | `volatile pV` 17 (residue kept), `const volatile pM` 89, `const volatile pOam` 712/487, `const BOOL` 684/214, all `*const` 692/232 |
| By-value matrix | Copy in the inline 724/646, a by-value parameter 724/645, a copy in the caller 728/636 |
| Order of inline definitions (28 orders behind prototypes) | All BASE. Definitions placed after the function are not inlined (200/158) |
| Named `hw12`/`hh12` shifts, both declaration orders, dx/dy initialised at declaration | All BASE (CSE'd back). halfH before halfW 22 |
| Single-statement dy | 700/164..168, or BASE |
| Item 1 with the above | Item-1 residue, or 8 |
| Vector layout: separate x/y pointers, an fx32 array pointer, `objTrans[1]`, `{fx32 p[2];}` | All BASE |

## Conclusion

The residue does not move under any pragma, flag, compiler build, scalar type, qualifier,
definition order or vector layout. Every lever that acts either changes code elsewhere or
reproduces one of the two known ip ties. This agrees with lanes C2-C5: the image's r6 needs a web
that the image never shows. The TU angle is now closed, between lane C2's neighbour units and this
lane's definition-order sweep.

**Best source:** the wave-13 source in the notes, unchanged (704/704, 2 bytes out, ../2.0/sp2).
