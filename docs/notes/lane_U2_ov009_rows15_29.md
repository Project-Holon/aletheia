# Lane U2 — ov009 open SDK rows 15-29 (15 rows)

Slice: `python scratch/a2/open_rows.py ov009 15 15`.
Method: `tools/sdkobj.py <addr> --region ov009` first (vendor member, compiler stamp, DWARF
prototype and every local **with its register**), diff by byte offset, fix the first divergence.

## Filed EXACT (4)

| address | bytes | function | shard |
|---|---|---|---|
| 0x0219A52C | 244 | SendConnectAck (libdwcgsnatneg.TWL.HYB.a natneg.o) | `ov009/pkt_ov009_0219A52C.json` |
| 0x02194B74 | 248 | gti2GetChallenge (libdwcgsgt2.TWL.HYB.a gt2auth.o) | `ov009/pkt_ov009_02194B74.json` |
| 0x02182414 | 320 | gsiXmlUtilParseName (libdwcgscommon.TWL.HYB.a gsxml.o) | `ov009/pkt_ov009_02182414.json` |
| 0x021986C4 | 324 | gt2StringToAddress (libdwcgsgt2.TWL.HYB.a gt2utility.o) | `ov009/pkt_ov009_021986C4.json` |

All four are `src/matched/ov_sdk/ov009_func_<ADDR>.c`, verified with
`python tools/match.py one --src … --func … --addr … --region ov009 --arm --cc 1.1p1 --lang c99 --diff`.

## The lever that carried this lane: get the vendor source

`scratch/U2/gs` is a shallow clone of the open GameSpy SDK
(`github.com/nitrocaster/GameSpy`). Three of the four rows above are GameSpy middleware and
their bodies came out byte-exact **on the first compile** once the vendor text was transcribed,
after the parked drafts had spent pin sweeps on them:

- `gt2auth.c` gave the `CALCULATEODDMODE(buffer, i, oddmode)` macro. The parked draft had the
  six-term xor chain hand-flattened and re-parenthesised; the macro's own left-associative
  order is what fixes `eor r0, r0, r2` / `eor r8, r0, r1` — the last two xor operand orders.
- `gsXML.c` gave `if (!isalnum(buffer[*pos]) || isdigit(buffer[*pos]))`. The parked draft used a
  `char c` local and was 7 bytes out (a register pair swap). The exact spelling is the local for
  the **first** test and the raw expression for the **second**:
  `if (!isalnum(c) || isdigit(buffer[*pos]))`.
- `gt2Utility.c` gave a body **shape**, not just a spelling: the parked draft had flattened
  `host = string` to the top of the function and dropped `srcPort = 0;` from the `!colon` arm.
  Restoring the vendor's nested `if/else` with `host = NULL; srcIP = 0;` in the `colon == string`
  arm and `host = string; srcPort = 0;` in the `!colon` arm makes the two zero constants come out
  of the live `srcIP`/`srcPort` registers instead of fresh `mov rX, #0` — the exact residue the
  parked note named.

Bit convention for `__ctype_map[]` on this build (needed for the `isalnum`/`isdigit` macros):
alpha `0x1`, digit `0x8`, space `0x100`, xdigit `0x400`. `isalnum` is `map[c] & 0x9` (alpha|digit),
`isdigit` is `map[c] & 0x8`.

## Parked, with the first differing instruction

| address | bytes (image/ours) | residue |
|---|---|---|
| 0x02157290 reset_network_vars | 256/256, 16 | image `str r0, [r2, #0x4c]` @0x10 \| ours `mov r5, #0` — the loop's shared zero constant is hoisted into the `ldr r1,[r1,#0x50]` delay slot; the image materialises it at 0x30, next to `mov r3, #1`. Tried had_ip declared first, reason store first, re-tested had_ip, all worse. |
| 0x0215D92C SOCLi_CopyCPSBuffer | 264/260, 101 | image `beq #0x…` @0x40 (disp 0x17) \| ours 0x16 — one instruction short in the first arm. |
| 0x021782B4 DWCi_Auth_Start | 264/256, 182 | image `ldr r5, [pc, #0xe4]` @0x4 \| ours `ldr r5, [pc, #0xe0]`. |
| 0x021685CC DWCi_GetMathRand32 | 276/268, 108 | image `ldr r6, [pc, #0xf0]` @0x8 \| ours `ldr r4, [pc, #0xec]`. |
| 0x0216C8DC DWC_AddMatchKeyInt | 296/296, 134 | image `movs r6, r1` @0x4 \| ours `movs r7, r1` — one callee-saved register too many live; keyID lands in r8 instead of r7 and every later register shifts. The image's `r4` is `(keyID-0x64)*12` and `r8` is the `+8` pool word, so exactly five are in use. |
| 0x0216CA04 DWC_AddMatchKeyString | 300/300, 133 | same prologue rotation: image `movs r6, r1` \| ours `movs r7, r1`. |
| 0x02164D74 WCM_InitEx | 364/364, 18 | image `ldr sb, [pc, #0x148]` @0x18 \| ours `mov r1, #0` — two-instruction rotation at +0x18..+0x28: the image sinks `str r1,[sp]` (spill of `expectLen`) below `mov r5, r0`, ours spills immediately. Declaration-initialiser and later-assignment spellings are both worse (396). |
| 0x021894D8 gpiSendData | 364/364, 21 | image `ldr r2, [r1]` @0x118 \| ours `ldr r3, [r1]` — the GSIDebug raw-dump call in the `rcode > 0` arm: the image loads the *format* pointer before `sendCount++`, ours increments first. Already recorded as `docs/idioms/a-varargs-counter-increment-is-scheduled-before-a-later-format-pointer.md`; every other call site in the file is byte-exact. |
| 0x0219C5B8 qr2_process_ip_verify | 364/364, 46 | image `mov r0, r5` @0x24 \| ours `sub r8, r5, #1` — the `i`/`firstFreeIndex` prologue. |
| 0x0215C910 CPS_Resolve | 380/380, 24 | image `ldr r2, [pc, #0x164]` @0x8 \| ours `mov r1, #0`. |
| 0x0215CB24 SOCLi_StartupCPS | 380/388, 17 relocation sites | image `ldr r0, [r6, #0x28]` @0x60 \| ours `ldr r1, [r6, #0x28]`. **Harness wart:** the parked file defines `SOCLi_StartupCPS`, not `func_0215CB24`, so `--func func_0215CB24` aborts with *"not found in tu.o"*; use `--func SOCLi_StartupCPS` (or rename on filing). |

## Naming repairs found

- 0x0215CB24's parked TU names its entry point `SOCLi_StartupCPS`; the house convention is
  `func_<ADDR>`. Any lane that closes it must decide which name goes on the shard.
- 0x02164D74's parked header already carries the repair note that its `symbols:` block needed
  `0x` prefixes; that is still correct and the block now resolves 18/18.
