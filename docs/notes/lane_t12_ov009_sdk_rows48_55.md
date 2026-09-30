# Lane T12 — ov009 SDK rows 48–55 (8 rows, all parked at hand-off)

Slice as handed out (`python scratch/a2/open_rows.py ov009 48 8`):
0x02160A7C rcv_certificate, 0x021674BC WcmWmcbConnect, 0x0217CF5C gsCryptRSAVerifySignedHash,
0x021732F8 DWCi_ProcessMatchSynTimeout, 0x02169934 DWCi_GPProfileSearchCallback, 0x021671C0 WcmWmcbScanEx,
0x02173064 DWCi_SendMatchSynPacket, 0x0219D5C4 QEStartQuery.

**Verdict: none closed. No parked source edited** (all eight were clean in `git status`; every experiment
was written to `scratch/t12/v_*.c`). Compiles: 47 single-function compiles (`match.py one --cc 1.1p1
--arm --lang c99`), plus the baseline of all eight rows. Working files: `scratch/t12/`
(`vex.py` variant driver, `d_<ADDR>.txt` baselines, `v_*` variant sources).

The pin axis was checked once per row (2.0/sp2p2, 2.0/base, 1.2/sp3, 1.6sp1) only to rule it out:
**no tree beats 1.1p1 on any of the eight**, and 1.6sp1 reproduces 1.1p1 byte for byte on all of them.

## One real lever found (row not closed, but −4 bytes)

**`0x0217CF5C` 564 → 560** with the i+1 CSE: the image keeps `i + 1` in a register across four uses
(`add r0, r1, #0x22`, `add r1, r4, r1`, `add r0, r1, #0x23`, `add r1, r4, r1`); the parked source
re-spells `i + 1 + 18 + 16` and this front end reassociates it to `i + 0x23`, emitting a fresh
`add r1, r5, #1` per branch. Naming the subexpression

```c
    k = i + 1;                                     /* int k; */
    if (k + 18 + 16 == lintRSASignature.mLength * 4) { ... }
    else if (k + 15 + 20 == lintRSASignature.mLength * 4) { ... }
```

collapses the two `add r1, r5, #1` into one and takes the row 564 → 560 (delta 2 → 1 instruction).
`(i + 1) + (18 + 16)`, `(i + 1) + 0x22` and naming the `&packet[...]` arguments are all flat; only the
named local moves the CSE. Remaining 4 bytes: see the residue row below.

## Residues (first differing instruction, image | ours)

| addr | fn | bytes (ours/image) | residue |
|---|---|---|---|
| 0x02160A7C | rcv_certificate | 592/544 | +0004 image `push {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}` \| ours `push {r4, ..., lr}`; +000C image `ldr r4, [sp, #0x44]` \| ours `ldr r1, [sp, #0x44]`. 510 concrete bytes: parameter home and the whole body colour `s`=r4/`con`=sl from instruction 4. Needs a body rewrite from the vendor object's field map, not a spelling |
| 0x021674BC | WcmWmcbConnect | 552/552 | 3 concrete slots, all `pop` vs branch: +0088 image `pop {r4, r5, r6, pc}` \| ours `b #0x2167670`; +00B8 and +00C8 image `pop {r4, r5, r6, pc}` \| ours `b #0x21675b8` (both). Tried this lane: `case 11:` split from `default:`, `case 6:` as `goto`/`break`, a statement added to the `case 10:` fall-through (564, much worse). The nested errcode→state→phase dispatch makes 1.1p1 share one epilogue where the image inlines a copy per slot |
| 0x0217CF5C | gsCryptRSAVerifySignedHash | 564→560 /556 | +007C image `ldr r2, [sp, #0x140]` \| ours `ldr r1, [sp, #0x140]`, and ours reloads the same slot at +00A8 (image keeps one web in r2 from the bound compare through the `memcpy` length argument). With the `k = i + 1` fix the other half is closed; the residue is now exactly this one reload plus `k` landing in r3 where the image has r1 (the two choices are coupled — if sigLen took r2, r1 would be free for `k`). 12 variants tried: named `unsigned int len` used for compare/`/4`/argument, `len = sigLen` as a statement and as an initialiser, `>> 2`, swapped compare operands, `sigLen / 4` hoisted, `int sigLen`. Also note +022C/+0230 are the vendor `@18`/`@20` template literals: no vendor template here, so the ceiling is MATCH* even size-exact |
| 0x021732F8 | DWCi_ProcessMatchSynTimeout | 560/564 | at 0x021734B8 image `bl DWCi_GetMatchCnt; add r0, r0, #0x154; ldrb r5, [r0, #0x416]` \| ours `bl DWCi_GetMatchCnt; ldrb r5, [r0, #0x56a]`. The image keeps the inner object's base (+0x154) apart from its field offset (0x416) instead of folding to one displacement; the parked note's pin sweep and this lane's (2.0/sp2p2 568, 1.2/sp3 600, 1.6sp1 560) say the fold is the vendor compiler's (stamp 4.0.0.1025) |
| 0x02169934 | DWCi_GPProfileSearchCallback | 636/636 | +0030 image `mul r6, r8, r0` \| ours `mul r7, r8, r0`; +00D4 image `mov r7, #0` \| ours `mov r5, #0`. Pure rotation of `{r5,r6,r7}`: image match_index*0xc=r6, j=r7, j*0xb0=r5; ours r7/r5/r6. Tried: `j` declared first, `register int j`, `i` reused for the second loop (680), a named `pid` local (46 diffs), declaration orders. Allocator tie; r4=i and the whole stream otherwise identical |
| 0x021671C0 | WcmWmcbScanEx | 636/648 | 0x0216732C is a live `clz r0, r0; rsb r0, r0, #0x20` on `cb->channelList`; no C spelling of count-leading-zeros maps to `clz` in this front end (`docs/idioms/a-clz-means-a-hand-written-asm-body-not-an-intrinsic.md`), so the pair can never be emitted from C. Capped: needs an `asm void` transcription |
| 0x02173064 | DWCi_SendMatchSynPacket | 624 → 616 /660 | the parked source re-calls `DWCi_GetMatchCnt()` per field; the image calls it **once** per arm (`+003c bl`, then `add r1, r0, #0x154; add r1, r1, #0x400` = the node base, reused for f16/f17/f4/f8/f_c/f_e/f_24, with f0 read as `[r0, #0x554]` off the raw base), writes the success flag with a **word** store (`streq r0, [r6]`, not `strbeq`), and **masks** the shifted halves (`and r5, r2, r5, lsl #16` with r2 = -0x10000, the S6 masked-shift-chain shape). Caching the pointer + `pSendBuf[0] = 1` + `((f17 << 16) & 0xffff0000) \| f16` gets 624 → 616 and aligns both masked sites; the remaining 44 bytes are the same pool (`sendSize` in fp, `pSendBuf` r6, `i` r5 in the image) plus the two-step node base |
| 0x0219D5C4 | QEStartQuery | 672/672 | +000C image `mov r8, #0` \| ours `mov r7, #0`; +0010 image `mov r5, r1` \| ours `mov r4, r1`. Whole-pool rotation: image flag=r4, server=r5, engine=r6, zeros=r7/r8, queryBuffer=sb; ours server=r4, engine=r5, zeros=r6/r7, queryBuffer=r8, flag=sb — i.e. the same pseudo order starting one register lower, with the success flag allocated first in the image and last here. Tried this lane: buffer pointer local (`unsigned char *qb = queryBuffer`, 664 and loses sl), flag as a statement not an initialiser, `unsigned int` flag, `unsigned char i` (676), an extra live local, swapped declarations, `saddr.family = 2;` moved next to the `sendto`. Matches the S5 264-config sweep: no pin, no flag set |

## Where the next pass should aim

- `0x0217CF5C` is the closest: one allocation decision (sigLen in r2 and no reload) closes it; the
  `k = i + 1` shape is already banked. If it lands, it can only be MATCH* because of the `@18`/`@20`
  template literals.
- `0x02173064` and `0x021732F8` are the same object (`dwc_match.o`, vendor stamp 4.0.0.1025) and both
  show the *unfolded* base+field displacement (`add #0x154` then a field offset). That fold is what
  1.1p1 does differently, so both are capped on this front end unless a body shape is found that
  forces the split (a two-step pointer expression is the shape to try for 02173064's node base).
- `0x021671C0` (clz) and `0x021674BC` (per-slot epilogue in a nested dispatch) are architecture-in-C
  blockers rather than spelling residues.
