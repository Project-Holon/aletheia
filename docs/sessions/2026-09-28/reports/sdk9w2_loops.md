# sdk9w2_loops report (ARM9 SDK wave 2, loop-entry sign)

All work comes from the vendor objects (sdkobj DWARF and relocations, a line-table dump of
`.debug_line`, byte scans of the TWL.HYB archives) and from match.py. I did not open any
file under `sdk/`.

## Filed (EXACT, manifest --verify run twice, 0 rewritten on the second pass)

| address | symbol (object) | bytes | verdict |
| --- | --- | --- | --- |
| 0x020898A8 | SND_CommandInit (libsnd.TWL.HYB.a snd_command.o) | 208 | EXACT |
| 0x0208E038 | WmInitCore (libwm.TWL.HYB.a wm_system.o, static) | 640 | EXACT |

Neither file uses asm. In both, the loop condition is written `(c) ? 1 : 0`. The card/fs
lane found this lever on CARDi_LockResource and the coordinator passed it on.

- WmInitCore: the ternary fixes both loops. Loop 2 then still had the fifoBuf base and the
  0x8000 constant in swapped registers (r4 and sl, 5 lines). Writing the header store as
  `((u16 *)fifoBuf)[i * (sizeof(fifoBuf[0]) / sizeof(u16))] = 0x8000;` closes it. The
  row-0 form `((u16 *)fifoBuf[0])[i * 128]` also closes it. `*(u16 *)fifoBuf[i]`,
  `&fifoBuf[i][0]`, casts, volatile and an enum constant all leave the swap.
- SND_CommandInit: I wrote a fresh draft from the object. With the ternary it is EXACT. The
  .bss block is one struct, `sCommandBss` at 0x0215146C, with the layout from the snd
  report.

## Files and shards written

- src/matched/arm9_sdk/func_020898A8.c, layout/matched/arm9/pkt_020898A8.json
- src/matched/arm9_sdk/func_0208E038.c, layout/matched/arm9/pkt_0208E038.json
- docs/idioms/a-loop-entered-by-a-branch-to-its-bottom-test-has-a-ternary-condition.md
- Deleted the superseded pending copies src/pending/arm9_sdk/func_020898A8.c (not read)
  and src/pending/arm9_sdk/func_0208E038.c (the earlier lane's `asm { .align 4 }` draft).
- `match.py idioms` rewrote docs/MATCHING.md's index when I ran it to check that my idiom
  file parses. I removed those two lines by hand, so docs/MATCHING.md is unchanged by this
  lane. The integrator's index run will pick up the new idiom.

## The asm-helper hypothesis: findings

- **DWARF.** mwcc emits no inlined-subroutine or abstract-origin entries. wm_system.o has
  27 subprogram DIEs, exactly its 27 emitted functions, and no lexical blocks. It has no
  DIEs for inline helpers at all, so DWARF cannot name an inlined helper.
- **Line tables.** Every row of WmInitCore, SND_CommandInit and CTRDGi_InitModuleInfo is in
  the function's own `.c` file; there is no switch to a header file. A helper that emits
  no code would leave no row anyway.
- **What asm mode does.** Any surviving asm statement turns the mode on. So does an asm
  helper whose call site folds to dead code (`h(0)` with `if (x) asm{...}`), and in that
  case the dead test is not folded either (`movs`/`movne` stays). An empty `asm {}`,
  intrinsic-looking calls, an asm function that is called or declared inline, K&R calls,
  switch, goto, a static local, struct copy or return, and compile-assert typedefs and
  externs do not turn it on. The asm statement's position matters: in SND, asm near the
  top turns the loop counter's zero into a pool load, which the image does not have.
- **Where genuine asm shows.** Across the ARM9 TWL.HYB archives, the only inline asm
  instruction found in compiled C functions is `clz` (the math count-leading-zeros
  helper). Most loops in those functions are entered with the `b`-to-test shape.
  DSPi_MapProcessSlotDefault and DSP_AttachProcessMemory are in my sign list for that
  reason. So asm does cause the sign, but WmInitCore and SND_CommandInit contain no asm
  instruction, and the ternary closes both with plain C.
- **Conclusion.** No genuine asm helper exists in either function. The idiom file records
  the ternary fix and states when to reach for the asm reading instead: only when the body
  also shows an asm instruction.

Other ARM9 SDK functions with the sign and no asm instruction (from an object scan). None
of them is a BW image row: CTRDGi_InitModuleInfo, VIB_StartPulse, MBi_SendVolatBeacon,
CARD_InitRomHashContext, Yos_JpegEncoderHuffmanEncoderBuildTable (x2, jpegenc/jpegencfast).

## Checked, not edited (card lane's rows)

- 0x02075ED4 CARDi_LockResource: has the sign (the `while` is entered by `b` to
  `ldr/cmp/bne`). It is already matched EXACT in src/matched/arm9_sdk/func_02075ED4.c
  using the ternary, with no asm.
- 0x02076E4C CARDi_ReadRomWithCPU: has the sign on the outer `while (length > 0)` (`b` to
  `cmp r8, #0; bne`). It also shows constants that were not folded (`mov r0, #0x200;
  rsb r0, r0, #0` for the page mask, and `mov r0, r7; cmp r8, r0`), probably a page-size
  local spelled through a variable. It has no asm instruction and no header rows in its
  line table. Next step for the card lane: write the outer loop as
  `while ((length > 0) ? 1 : 0)` first.

## Permuter

Seeds 13501 (hill, 200 budget) and 13502 (random, 150 budget) on WmInitCore's loop-2
register swap. Neither improved on the baseline; I found the fix by hand.

## Next pass

- Apply the ternary to any other open row that shows the `b`-to-bottom-test sign.
  CARDi_ReadRomWithCPU is first.
