# Wave 13: upper-half leftovers

**Result: 12 filed (11 EXACT, 1 EXACT\*). 2 are still DIFF. 1 pending file is still MATCH.** Nothing is committed.

## Filed to src/matched

| addr | packet | cc | what it was / the lever |
|---|---|---|---|
| 0x020604AC | pkt_0205D1BC | ../2.0/sp2 | NitroSystem NNS_FndAppendListObject. The fix was three things: GetLink's `u32` add, no `volatile`, and an `else` arm. The old 4-byte swap came from the pointer-typed add. |
| 0x02060500 | pkt_0205D1BC | ../2.0/sp2 | NNS_FndPrependListObject, same fix as the row above |
| 0x02068FF0 | pkt_02068E78 | ../2.0/sp2 | g2d CharCanvas OBJ1D init. The inline-asm `clz` helper handles the clz. The [sp,#0xc] word is a 4-byte bitfield struct passed BY VALUE, so the callee takes 7 arguments, not 8. The last fix was the pair-pointer local `p = tbl[h][w]`. |
| 0x02075FCC | pkt_02075DA0 | 1.1p1 | EXACT\*. Builds a permission mask from the access-control bits at +0x1B4 of the TWL ROM header. Exact on the first compile. |
| 0x020730B8 | pkt_02073098 | ../2.0/sp2 | The "if-conversion wall" was not real: a WRAPPING `if` plus sp2 is exact. |
| 0x020733E8 | pkt_02073098 | ../2.0/sp2 | Arity fix. SND_PrepareSeq takes 4 arguments, so this function forwards r1..r3. SND_SetTrackAllocatableChannel takes 3, so r2 is the channel mask. |
| 0x02073438 | pkt_02073098 | ../2.0/sp2 | Arity fix: func_02075BAC takes 3 arguments (fader, target, frames). |
| 0x02087FBC | pkt_02087AE4 | 1.1p1 | TwlSDK os_argument encode. Fixes: HW addresses written as cast constants, MI_CpuCopy8(src, dest, size) argument order, and one local pointer for the title-ID and byte stores. 0x02151390 resolves as sole-ref. |
| 0x0208B8B0 | pkt_02087AE4 | 1.1p1 | TwlSDK PM_Init. Fix: one volatile VBlank-count read assigned in a chain. 0x02FFF684 is a constant, so the old "unwitnessed" site is gone. |
| 0x02060B6C | pkt_02060764 | 1.1p1 | NitroSystem expheap RecycleRegion in the library's own shape (region copied by value, no volatile). Last fix: `val + (u32)ptr` in the inline end-address helper. |
| 0x020712A8 | pkt_02070B64 | ../2.0/sp2 | g3d texture-SRT matrix. Fixes: the real MatAnmResult/MtxFx44 types, and the `_30` factor negated in `u32`. The permuter anneal found the negation: `temp(tmp=-t) ; cast(u32)`. |
| 0x02070A24 | pkt_0207010C | ../2.0/sp2 | Was DIFF 60 in src/pending; I deleted the pending file (not committed). The second parameter is a dictionary index forwarded to func_0206E62C. The bitfield-looking reads are NNS_GfdGetTexKeyAddr(vramKey)>>3. |

Every filed source was re-verified with `match.py one`. Two data-flow checks back the arity readings:
- **0x020733E8 and 0x02070A24:** the callers already pass the extra arguments.
- **0x02073438:** the callee func_02075BAC saves and stores r2.

## Still DIFF (appended to the notes)

- **0x02071104, 6 bytes out, sp2** (docs/notes/pkt_02071104.c.txt). The source is now a readable single expression with the real types. The residue is still scaleT/transT allocated around the smull. The permuter found nothing: hill 129 singles was flat, anneal 1500 was flat, and 6 hand orderings did not help.
- **0x02051C88, 19 bytes out, 1.1p1** (docs/notes/pkt_02051C88.c.txt). The first loop's index and slots base are exchanged between ip and lr. Four more loop shapes all stayed at 19. It is game code, not a library.

## Pending

- **0x0206DC00, still MATCH (sp2).** All concrete bytes are right, and 11 of 14 relocations resolve. Three sites are still unwitnessed:
  - 0x027300F0 and 0x0272FEF4: TWL-ltd code with no label.
  - 0x0206DBF4: an unlabelled leaf. `symbols_sdk.txt` lists it as NHTTPi_InitRequestInfo, but `symbols_sdk.json` does not, so the `sdk` class does not fire. The .txt row looks like a stale false hit.

## Integrator: seed

- **0x02076050** (ARM leaf, already EXACT): func_02075FCC's follower. Seeding it turns 0x02075FCC from EXACT\* into EXACT.
- **0x0206DBF4** (ARM, 12-byte leaf `mov r1,#0; str r1,[r0]; bx lr`, inside func_0206DBDC's extent): seeding it clears one of the three blocking sites for src/pending/func_0206DC00.c.

## Docs written

- Appended DIFF sections: pkt_02071104, pkt_02051C88, pkt_0206DC00.
- Appended one-line closure notes to the notes for every closed function.
- Appended correction blocks to cluster headers 0205D1BC, 02073098, 02068E78, 02087AE4, 02060764 and 02070B64. Two corrections matter most:
  - **0205D1BC:** its compiler pin and volatile claims were wrong.
  - **02073098:** its "if-conversion wall" does not exist.
- New header: docs/families/cluster_02075DA0.h.

## Lessons worth carrying

- **Identify the library first.** Nine of the twelve came from recognising NitroSystem or TwlSDK code (fnd list/expheap, g2d, g3d, snd, os_argument, pm).
- **Leftover argument registers were real callee arguments.** In three functions they were the arguments of a callee whose real arity is larger than the note assumed.
- **Fixed HW addresses are cast constants, not relocations.**
- **The `-(u32)x + C` trick.** Negating in `u32` stops the fold of `-x + C` into one `rsb`.
- **Lead for the related sibling 0x02072EA8** (another packet): it is in the same "if-conversion" class as 0x020730B8 and should be tried with a wrapping `if` under ../2.0/sp2.

## Verification

`manifest --verify --shard` was run for pkt_0205D1BC, pkt_02068E78, pkt_02075DA0, pkt_02073098, pkt_02087AE4, pkt_02060764, pkt_0207010C and pkt_02070B64. Every entry is EXACT, with 0x02075FCC at EXACT\*.
