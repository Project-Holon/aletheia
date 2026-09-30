# Lane U11 — ov009 SDK slice (`scratch/a2/slices/u11.txt`), 12 rows: none closed, all already being edited by lane U1

Lane U11 was handed the frozen slice `scratch/a2/slices/u11.txt` (12 rows, all ov009, 1,816 bytes).
**All twelve rows were worked, and their parked sources edited, by lane U1 during this run**: every
`src/pending/ov_sdk/ov009_func_<ADDR>.c` below carries a fresh `u1:` residue line
(`git status` = `M`, `git diff --numstat` = `1 insert / 0 delete` each, so the bodies are untouched
and U1's edits are comment-only). Per the brief's rule for a source another lane has modified, U11
ed its bodies and worked from copies under `scratch/laneU11/`. The independent measurements below
therefore agree with, and in two places extend, U1's per-row lines.

## Compiler stamps (sdkobj `.comment`) and the "2.0 family" question

Six of the twelve are stamped **4.0.0.1025** ("no tools/mwccarm build writes this stamp"); the other
six are 4.0.0.1024, i.e. `dsi/1.1p1`:

| address | function | stamp |
|---|---|---|
| 0x0217D8E0 | gsLargeIntDiv (gslargeint.o) | 4.0.0.1025 |
| 0x021990A0 | GetClientUniqueID (natneg.o) | 4.0.0.1025 |
| 0x021700C8 | DWCi_EncodeBinaryMsgCommand (dwc_match.o) | 4.0.0.1025 |
| 0x0217D280 | HexEncode16 (gsdebug.o) | 4.0.0.1025 |
| 0x0216980C | DWCi_GetFriendBuddyStatus | 4.0.0.1025 |
| 0x021A174C | SBSendNatNegotiateCookieToServ | 4.0.0.1025 |
| 0x02167E20 | WcmWmcbSetDCFDataAsync (wmif.o) | 4.0.0.1024 = 1.1p1 |
| 0x02163E40 | CPSi_rc4_init (arc4.o) | 4.0.0.1024 = 1.1p1 |
| 0x02166600 | WCMi_MergeToBuffer (cpsif.o) | 4.0.0.1024 = 1.1p1 |
| 0x0215F0F0 | SOCLi_IsIPv4ValidDNSAddr (socl_misc.o) | 4.0.0.1024 = 1.1p1 |
| 0x02158524 | send_ping | 4.0.0.1024 = 1.1p1 |
| 0x0215D070 | SOCL_CreateSocket | 4.0.0.1024 = 1.1p1 |

A single check per 1025 row of `../2.0/base` (the family the new rule 4b points at) shows the 2.0
family is **not** the build for any of them — it is strictly worse than `dsi/1.1p1` on five of the
six and identical on the sixth (compiled bytes / concrete differing bytes):

| address | dsi/1.1p1 | ../2.0/base |
|---|---|---|
| 0x0217D8E0 | 32 B / 17 | 32 B / 17 |
| 0x021990A0 | **52 B / 3** | 56 B / 23 |
| 0x021700C8 | **160 B / 20** | 160 B / 24 |
| 0x0217D280 | **172 B / 9** | 164 B / 105 |
| 0x0216980C | **184 B / 86** | 192 B / 113 |
| 0x021A174C | 180 B / 112 | 180 B / 112 |

(For 0x021990A0 the image's listing extent is 52 bytes, not 56: 56 is what 2.0 compiles. In the
24-tree sweep it is the `../1.2/*` trees that give 64-76 bytes, not the 1.x dsi ones.)

## 0x021990A0 GetClientUniqueID — the closest row on the slice, and its wall

24-tree sweep, `-O4,p -lang c99`:

    dsi/1.1 1.1p1 1.2 1.2p1 1.2p2 1.3 1.3p1 1.6sp1 1.6sp2   52 B / 3
    ../1.2/base sp2 sp2p3                                    76 B / 64
    ../1.2/sp3 sp4                                           68 B / 61
    ../2.0/base sp1 sp1p2 sp1p5 sp1p6 sp1p7 sp2 sp2p2 sp2p3 sp2p4  56 B / 23

`../1.2/sp3` *does* emit the image's `mvn r1, #0x80000000`, but in its own 3-instruction
conditional-return codegen (`cmp / addne sp,#4 / ldmne sp!, {pc}` where the image has
`popne {r4, pc}`), so it is a different front end, not this build. Ten further spellings compiled
under 1.1p1 (local for the bound, `unsigned` local, declaration initialiser, enum constant,
`~0u>>1`, `0x7ffffffe+1`, `0x80000000u-1u`, decimal literal, result local) all give
`sub r1, r0, #0x80000002`: the peephole folds the constant against the live `r0 == 1` from the low
bound.

Residue: image `mvn r1, #0x80000000` | ours `sub r1, r0, #0x80000002` (3 bytes, one instruction).
Everything else in the 52 bytes is identical, DWARF registers included.

## Residues of the remaining rows (first differing instruction, image | ours)

- **0x0217D8E0** gsLargeIntDiv, 36 vs 32 B: image `mov lr, r1` then `mov ip, r2` before `str r3,[sp]`
  and `mov r2,lr` / `mov r3,ip` at the call (DWARF: divisor→r14, dest→r12); 1.1p1 and 2.0 both keep
  dest in r3, so the fifth argument's stack store and one copy disappear. Vendor 4-move shuffle.
- **0x02167E20** WcmWmcbSetDCFDataAsync, 104 vs 100 B: image keeps a real branch
  `cmp r0,#0 / beq / mvn r5,#4` and schedules `ldr r6,[r4,#0x2c]` after it; ours if-converts to
  `subne r5, r5, #5` and hoists the callback load. Seven more spellings compiled here (declaration
  initialiser 100/72, if/else both arms 100/37, inverted if/else 100/35, switch case0/default
  100/35, `~4` 100/35, self-assigned arm 100/35, both-arms-plus-self-assign 100/37) — all still
  if-convert; the arm is not steerable from the source.
- **0x02163E40** CPSi_rc4_init, 120 B: mirrored four-register swap. Image `add r4, r0, #2` (table `m`
  in r4, `m_i` in lr, chain r3, k-temp r0) | ours `add lr, r0, #2` (m in lr, `m_i` in r4, chain r0,
  k-temp r3). 21 bytes, all four register numbers.
- **0x02166600** WCMi_MergeToBuffer, 128 vs 120 B: image carries the shared default arm as a real
  block after the dispatch (`cmp r0,#1 / beq 0x2166620`, `cmp r0,#2 / beq 0x2166628`, then
  fall-through `mov r6,r1 / b 0x216664c`); ours hoists `mov r6, r1` above both compares. Five
  restructures compiled here (if/else-if/else 120/94, split-if 128/48, switch 1/2/default 120/94,
  goto-shared-arm 120/94, chain reordered 112/84): only the split-if form reaches the image's 128 B,
  and it if-converts the default arm to `moveq r6, r1`. The image's byte swap is
  `lsl r0,r4,#16 / lsr r3,r0,#16 / lsl r0,r3,#24 / and r3,r3,#0xff00 / lsr r0,r0,#16 /
  orr r0,r0,r3,lsr #8`, i.e. `(len << 8) | (len >> 8)` on a `u16` local — the parked
  `((u8)len << 8) | (len >> 8)` emits an `asr r3, r3, #8` instead.
- **0x0215F0F0** SOCLi_IsIPv4ValidDNSAddr, 148 vs 152 B: image `push {r4, lr}` | ours
  `push {r3, r4, r5, lr}` — the two inline predicates are folded into `eor r3,r2,r1 / tst r0,r3 /
  mvn r3,r0 / tst r1,r3` with no extra callee-saved register; ours allocates r5 and a result temp.
- **0x021700C8** DWCi_EncodeBinaryMsgCommand, 160 B: image `ldr ip, [pc, #0x64]` + `lsl r0, r6, #2`
  (id base in ip, len*4 in r0, 0x5a in r1) | ours `ldr r0, [pc, #0x64]` + `lsl r1, r6, #2` (r0/r1/r2):
  a pure three-register rotation over 20 otherwise identical bytes.
- **0x0217D280** HexEncode16, 172 B: image `add r6, sb, #0x29` and `ldrb r7, [sl], #1`
  (aTextOutStream→r6, aChar→r7) | ours `add r7, sb, #0x29` and `ldrb r6, [sl], #1`. 9 bytes. The
  self-assignment lever does not move it either: `aTextOutStream = aTextOutStream;` before the memset
  call, `aChar = aChar;` after the load, and `aTextOutStream = aTextOutStream;` before the load all
  stay at 9; `aChar` declared first makes it 11.
- **0x02158524** send_ping, 180 B: image `ldr r2,[pc,#0x90] / strh r4,[r5,#0x22] / ldr r2,[r2,#4] /
  ldrh lr,[r3,#8]` | ours `strh r4,[r5,#0x22] / ldr r2,[pc,#0x8c] / ldrh ip,[r3,#8] /
  ldr r7,[r2,#4]` (pool word and halfword load scheduled before the store, different registers).
- **0x0215D070** SOCL_CreateSocket, 184 vs 180 B: image `ldr r1, [pc, #0x9c]` | ours
  `ldr r1, [pc, #0xa0]` — pool layout off by one word from the first instruction on; 78 bytes.
- **0x0216980C** DWCi_GetFriendBuddyStatus, 184 vs 180 B: image `ldr r4,[pc,#0xa4] / mov r5,#0`
  | ours `mov r5,#0 / ldr r4,[pc,#0xa4]` (pool load vs zero order), 86 bytes.
- **0x021A174C** SBSendNatNegotiateCookieToServ, 184 vs 180 B: image `ldr r5, [sp, #0x44]` | ours
  `ldr r4, [sp, #0x44]` — the incoming argument and the byte-swap temporary trade r4/r5 through the
  whole 4-byte-swap block; 112 bytes.

## What U11 added that U1's lines do not already carry

- the 24-tree sweep table for 0x021990A0 with the `../1.2/sp3` mvn-but-wrong-epilogue finding, and
  the ten-spelling probe file (`scratch/laneU11/probe_mvn.c`, all ten give the same `sub`);
- the 2.0-vs-1.1p1 side-by-side for all six 1025-stamped rows (rule 4b does not hold on this slice);
- the self-assignment lever result for 0x0217D280 and the seven arm spellings for 0x02167E20;
- the five dispatch restructures and the byte-swap shape for 0x02166600.
