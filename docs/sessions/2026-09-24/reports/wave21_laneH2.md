# Wave 21, lane H2: the three ov230 probe targets of func_02011D9C

Target: 0x02011D9C (ica_anime.c, Thumb, 272 bytes), `src/pending/func_02011D9C.c`.
Verdict (tools/match.py one, dsi/1.1p1 -O4,p): **MATCH**, 272 of 272 bytes, 22 of 25
relocations resolved. Unchanged. It stays in src/pending. Nothing was moved and no shard was written.

## Answer

0x021882A0, 0x02188354 and 0x02188390 are real ARM entry points in **ov230**. ov230 stores
them encrypted. They become code only after ov230's static initialiser decrypts them
in RAM. The initialiser runs from FS_LoadOverlay → FS_StartOverlay, which is reached
through the `sub_02034AC4(ov230_id)` call that func_02011D9C makes just before the first probe.
The integrator's "identical repeated non-code bytes" in ov230 are the ciphertext of six
identical 0x3C-byte thunks.

## Evidence

1. **Decoding is correct.** At +0x20, +0x48 and +0x72 the halfwords are F176 EA70, F176 EAB6 and F176 EAC0.
   The second halfword's prefix is 11101, which is BLX (to ARM). A BL to Thumb would use 11111.
   The recomputed targets are 0x021882A0, 0x02188354 and (0x02011E12+0x176580)&~3 = 0x02188390. All are ARM and word aligned.
2. **Which overlay is loaded.** The only reference to the function is the word 0x02011D9D at 0x0209DF9C.
   That word is the init slot of an {init 0x02011D9C, main 0x02011EAC, exit 0x02011EC0} proc triple.
   The function loads ov230 immediately before the probes and unloads it after them. FS_LoadOverlay (0x02079264)
   calls FS_StartOverlay (0x0207902C) at 0x020792A4. ov230's image [0x02187F00, 0x021899A0)
   covers all three targets, so the executed bytes are ov230's whatever was resident before.
3. **No other region.** The y9 entries covering the targets, counting bss, are only ov009, ov021, ov096
   and ov230. The twl window (0x02700000..0x02732DA0) does not contain them. The DSi key was not needed.
4. **ov009 is mid-function at all three addresses.** 0x021882A0 is `cmp r0,#0` after a `bl`. 0x02188354 is
   4 bytes past loc_02188350, and entering there skips its `add r0,sp,#0x14`. 0x02188390 is `mov r1,r5`
   right after `mov r5,#1`. No return or pool comes before any of them. In the caller, r5 is a
   callee-saved flag that is set to 0 or 1 before each BLX, so it is not an argument.
5. **The ov230 mechanism.** I traced it from asm/overlays/ov230.s and emulated it in
   /tmp/aletheia_laneH2/decrypt230.py.
   - The sinit table is 0x02188408, 0x021889B0, 0x02188CB0, 0x02189448, 0x02189908. Each entry is
     `orr r0,pc,#0; adds r0,r0,#4; bne loc_02188A48` followed by (start+0x1600, end-code) pairs.
   - loc_02188A48 decrypts each range in place. It fixes up branch words (via func_02188A0C), decodes the
     other words with a rolling XOR key (0xF0618C46), then flushes the cache (func_021889E4).
   - The table at 0x02188414 names 0x021882A0, 0x021882DC, 0x02188318, **0x02188354**, **0x02188390** and
     0x021883CC, each biased by +0x1600 and each 0x24 bytes long. The three targets are entries 0, 3 and 4.
   - Decrypted, each slot is `orr ip,pc,pc; ands; moveq; addne ip,#0x1C; ldr ip,[ip,#0x14];
     sub ip,#0x1600; push {ip}; orr ip,pc,pc; ldm sp!,{pc}` followed by a 6-word parameter block.
     The slot jumps to the dispatcher at 0x02188C60, which is itself a decrypted range.
   - The dispatcher does `push {r0-r3}`, decrypts the body, restores r0..r3 and runs `blx ip`, then
     re-encrypts. The caller's (start, end, 0) arguments therefore reach the checksum body unchanged.
     Every slot ends in `ldm sp!,{pc}`, so no slot falls into the next.

## What match.py allows

- **Region hints on scratch copies.** I tried ov009, ov021, ov096, ov230, twl and no hint. Every run gave MATCH, 22 of 25, with the three sites
  unresolved. The reason is that no listing carries a func_ label at those addresses, and the only branches
  to them are inside the function under test. The printed reason is the same whatever the hint.
- **Mechanical test only, not a verdict.** I copied layout to /tmp/aletheia_laneH2/layout and added
  `overlay_230 0x021882A0|0x02188354|0x02188390 arm` to function_starts.txt, then ran disasm.py overlay 230 into scratch.
  Running match.py one with ov230's listing patched in-process to that scratch listing
  (/tmp/aletheia_laneH2/patched_one.py) gives **EXACT, 25/25, sole-ref x1** for all three.
- **Why that seed is not allowed.** The labelled "function" is ciphertext (`mvnne r4,sb,asr #24; ands ...; ldrb pc,[r2,#-0x34d]`).
  That is exactly the "plausible nonsense" that function_starts.txt must not produce. Its evidence would also be a
  data table the decryptor reads, not an instruction elsewhere that branches there. Under current rules the
  seed is not justified, and the function stays MATCH.

## Proposed changes (for the integrator/owner, none applied)

- **No layout change is recommended as-is.** Seeding function_starts.txt would make the function EXACT only by
  labelling ciphertext.
- **Honest route (a tools change, the owner's call).** Produce an ov230 listing from the image after running
  ov230's sinit decryptor, with verification conditions stated (every table range decodes to valid code, and the thunks end in
  `ldm sp!,{pc}`). Then attest `ovNNN`-hinted labels against that listing, the same way the `twl` hint attests the
  decrypted arm9i listing. With that listing in place, the existing `ov230` hints on the symbols: lines would resolve
  as sole-ref/code with no source change.
- The symbols: lines already carry the correct `ov230` hint, so I made no source edit.

## Files written

- docs/notes/pkt_02011D9C.c.txt (appended a wave-21 lane H2 section)
- docs/sessions/2026-09-24/reports/wave21_laneH2.md (this report)
- Scratch only: /tmp/aletheia_laneH2/{decrypt230.py, patched_one.py, hint_*.c, layout/, asm/}
