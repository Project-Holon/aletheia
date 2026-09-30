# Lane U15 — ov009 SDK slice (10 rows, 34.6 kB), results and named residues

Slice `scratch/a2/slices/u15.txt`: the largest remaining ov009 SDK rows.  Two are excluded by the
slice note itself (`0x0219091C` gpiProcessSearch = lane S10's, and `0x021870B8` has a verified cap:
the image's zero fill is a rolled `strb` memset expansion we only emit as `bl memset`).

## Object stamps decide the class (read this first)

| addr | function | object stamp | front end we have |
|---|---|---|---|
| 0x02159A80 | dt_ack (libcps) | 4.0.0.1024 | **dsi/1.1p1 — calibrated** |
| 0x02163628 | CPSi_sha1_block (libssl) | 4.0.0.1024 | **dsi/1.1p1 — calibrated** |
| 0x02174FE8 | DWCi_NNCompletedCallback | 4.0.0.1025 | none (parked class) |
| 0x0217E078 | gsLargeIntPowerMod | 4.0.0.1025 | none |
| 0x0216C230 | DWCi_GT2ClosedProcess | 4.0.0.1025 | none |
| 0x0217AB78 | DWCi_Netcheck_Thread | 4.0.0.1025 | none |
| 0x0216D57C | DWCi_MatchProcess | 4.0.0.1025 | none |
| 0x021702A0 | DWCi_ProcessRecvMatchCommand | 4.0.0.1025 | none |

`python tools/sdkobj.py <addr> --region ov009` prints the stamp and the calibrated front end.
Only the two `.1024` rows can be closed to EXACT with the toolchains in this tree; the rest are the
allocator-signature class of `docs/notes/lane_U4_ov009_sdk_rows45_59.md` ("the parameters take one
register higher than ours and one local takes the free slot", cyclic rename, size already exact).

## What changed this lane

**0x02174FE8 DWCi_NNCompletedCallback — 713 → 65 concrete bytes, size exact 1008/1008.**
The row was 8 bytes short (1000) and it was *not* allocation.  The status select

```c
if (MC->f_61c == 0xe) status = 0xf; else status = 6;   /* moveq/movne, 4 bytes */
DWCi_SetMatchStatus(status);
```

is if-converted by dsi/1.1p1; the image carries the branch form with one tail-merged `bl`
(`cmp r0,#0xe / bne / mov r0,#0xf / b / mov r0,#6 / bl`).  Writing the call into **both** arms

```c
if (MC->f_61c == 0xe) DWCi_SetMatchStatus(0xf); else DWCi_SetMatchStatus(6);
```

gives the image's shape, the exact 1008 bytes, and removes 648 of the 713 mismatch bytes.
This is the small-immediate case of
`docs/idioms/a-constant-argument-selected-into-a-local-if-converts-where-a-call-in-each-arm-does-not.md`
(that idiom was recorded for pool-word constants; the same lever fires on two literals).

Residue: 49 sites, all the `result` ↔ constant-zero register swap (image r6/r7, ours r7/r6),
cascading into the pidStr address (+00CC) and the `-1` length (`r5-0x19` vs `r4-0x19`).
Inert levers measured on it: every declaration order, pidStr declared first/last, a named zero
local (`int`/`unsigned`/enum-typed, first or last position), `result = result;`, forwarding through
`res = result;`, and a nameless second parameter.  This is the 4.0.0.1025 signature — park.

## DWARF of dwc_match.o / dwc_auth.o — the missing reconstruction for the partials

`python tools/sdkobj.py <addr> --region ov009` (or `scratch/u15/dwdump.py ov009 <addr>` for the raw
DIE walk, including lexical-block nesting).  The three partial bodies need these, not another
spelling sweep:

* **0x0217AB78 DWCi_Netcheck_Thread** (1696/3184 compiled) — `static void (void)`;
  locals: `DWCCalInfo calinfo [fb+56]`, `int wait_sec r11`, `int wait_len r10`, `char *wait r9`,
  `int data_len r11`, `char *data r8`, `int url_len [fb+8]`, `char *url r7`, `char retcode[4] [fb+32]`,
  `char *bodywayport r10`, `char *body302 r11`, `void (*free)(unsigned long,void*,long) r6`,
  `void *(*alloc)(unsigned long,long) r5`, `DWCAuthResult authresult [fb+204]`,
  `struct tagDWCWiFiInfo DWC_netcheck_wifiinfo [fb+36]`, `int httpretcodei r10`,
  `char *httpretcode r0`.  Note `free`/`alloc` — the parked body has no such locals and drives the
  DWChttp object through a fabricated `DWCNetcheckWork` struct.
* **0x0216D57C DWCi_MatchProcess** (1028/3908) — `void (int fullSpec)` (fullSpec r5); locals
  `pNodeInfo r6`, `connection r0`, `i r5`, `info r0`, `noResponseHosts u32 r6`, `mc r5`,
  `idx u8 r0`, `node r6`, `sbError enum r0`, `result int r0`, `sbInterval u32 r5`, plus a second
  `i r5` and a second `pNodeInfo r0` in nested scopes.
* **0x021702A0 DWCi_ProcessRecvMatchCommand** (852/4396) — `static int (u8 command r9, int srcPid r8,
  u32 srcIP r10, u16 srcPort r11, u32 *data r7, int len r6)`; locals include
  `u8 AID r0`, `u8 suspend r8`, `u8 fromSV r5`, `u8 beforeCloseState r8`, `u32 senddata[1] [fb+16]`,
  `DWCstNodeInfo *tmpNode r6`, `enum error r0`, `enum sbError r0`, `u8 data_idx r5`,
  **`struct DWCstNodeInfo peerNodeInfo [fb+28]` and `[fb+68]`** (two by-value structs, 12-byte each,
  = two 0x1c frames), **`struct SOCSockAddrIn remoteaddr [fb+20]`**, `enum nnError r0`, `int i r5`,
  `int result r0`, `int sendlen r5`, `int profileID r6`, **`u32 senddata[65] [fb+108]`**,
  `u32 ip r6`, `u16 port r5`, `u8 aid r5`, `u8 sendCommand r7`.  The frame offsets alone explain why
  the parked skeleton is 3.5 kB short.

## Named residues (one line each, first differing instruction)

* `0x02159A80 dt_ack` 1384/1384, 820 B, 256 sites — **body-level, not a rename**: the image spills
  `enabled` (the `func_02087988()` result) to `[sp]` and reloads it with `ldr r0,[sp]` at 8 call
  sites, and gives `fp` to the `chunks[ci]` byte offset (`mul fp, r8, r0` / `add sl, r6, fp`);
  ours keeps `enabled` in `fp` and the offset in `sb`.  First site `+00A8` image `str r0,[sp]` |
  ours `mov fp, r0`; the `sl`/`sb` roles then diverge at `+0104` (`add sb, r7, r4` | `add sl, r7, r4`).
  The image's `fp` is pushed and never otherwise used, so its local set must have one more live
  value than ours — start from the DWARF below, not from a spelling sweep.
* `0x02163628 CPSi_sha1_block` 1652/1652, 142 B, 89 sites — pure register rename of the eight
  locals; first site `+0010` image `add r7, sp, #0x10` | ours `add r8, sp, #0x10`.  Previous lane
  measured all sampled declaration orders, all 120 state-load orders and 4000 permuter compiles.
  Park with that number.
* `0x0216C230 DWCi_GT2ClosedProcess` 1368/1368, 326 B — first site `+0080` image `bne #0x216c3b0` |
  ours `bne #0x216c410` (block ordering / jump-table arm placement, 0x60 apart), plus the r5/r6/r8
  rotation from `+0150`.  4.0.0.1025 class.
* `0x0217E078 gsLargeIntPowerMod` 1092/1164, 401 B — structural, 72 B of code missing; first site
  `+0000`-region frame/`sub` divergence.  4.0.0.1025 class.
* `0x0217AB78` / `0x0216D57C` / `0x021702A0` — partial bodies (1696/3184, 1028/3908, 852/4396);
  the DWARF local lists above are the next step, all three are 4.0.0.1025.
* `0x021870B8 gpiProcessRecvBuddyMessage` — verified cap (rolled `strb` memset), not attempted.
* `0x0219091C gpiProcessSearch` — lane S10, not attempted.

Nothing in this slice reached EXACT this lane; the only filed-side change is the improved parked
body at `src/pending/ov_sdk/ov009_func_02174FE8.c` (size-exact, 65 B residue, was 713 B).
