# Lane T18 — ov114 open SDK rows 10–18 (nine rows)

Measured 2026-09-30. Slice: `python scratch/a2/open_rows.py ov114 10 9`.

Harness lines (all `--lang c99 --arm`, no `--region`-less shortcut):

```
python tools/match.py one --src <file> --func <name> --addr 0xADDR --region ov114 \
    --arm --cc 1.1p1 --lang c99 --diff
```

Raw diffs: `scratch/laneT18/raw/<ADDR>.txt`. Variants: `scratch/laneT18/var/`.

**Result: 1 of 9 rows closed (0x021C2C28, EXACT). 8 rows parked, each with a residue
measured live in this lane, not copied from the parked header.**

## The row that closed

### ov114 0x021C2C28 — ghiPostStringStateDoPosting, 392 B — **EXACT**

Filed `src/matched/ov_sdk/ov114_func_021C2C28.c`, shard
`ov114/pkt_ov114_021C2C28` (`manifest --verify` exits 0, no `EXACT*` noise; evidence
`sole-ref self:0x021CE0B4`). 9/9 relocations resolve. Two wrong spellings, both
C-semantics-invisible; the second is the last 4 bytes:

1. **The copied global must carry its own object type, not `char[]` + cast.** The
   parked draft had `extern char g_021CE0B4[];` and `hex = *(Hex4 *)g_021CE0B4;`.
   With the cast, MWCC emits the 4-byte copy as four `ldrb` into four distinct
   registers followed by four `strb` — one solid block, 20 concrete bytes, and the
   independent `add sb, sl, #0x58` / `mov r6, #0` cannot be scheduled into it.
   Declaring `extern Hex4 g_021CE0B4;` and writing `hex = g_021CE0B4;` (no cast on
   either side) reproduces the image exactly: 2 `ldrb`, 2 `strb`, 2 `ldrb`, 2 `strb`
   with `add sb` / `mov r6` scheduled into the gaps. 48 → 4 concrete bytes on that
   change alone.

   ```
   image +0048 ldrb r2,[r0] / ldrb r1,[r0,#1] / add sb,sl,#0x58 / strb r2,[sp] /
              strb r1,[sp,#1] / ldrb r1,[r0,#2] / ldrb r0,[r0,#3] / mov r6,#0 /
              strb r1,[sp,#2] / strb r0,[sp,#3]
   draft +0048 ldrb r3,[r0] / ldrb r2,[r0,#1] / ldrb r1,[r0,#2] / ldrb r0,[r0,#3] /
              strb r3,[sp] / strb r2,[sp,#1] / strb r1,[sp,#2] / strb r0,[sp,#3]
   ```

2. **The two pool globals were swapped in the draft.** The image's literal pool is
   `+0180 = 0x021CEEB4`, `+0184 = 0x021CED88`. `+0180` feeds `r4`, which is the table
   indexed at `+00E4`/`+00E8` (`ldrsb r7,[r4,r3]`); `+0184` feeds `r5`, which is the
   first argument of `func_02094A28`. So the hex table is `g_021CEEB4` and the
   character-set string handed to `func_02094A28` is `g_021CED88` — the draft had
   them the other way round, which is the remaining 4 concrete bytes.

   This is the usable check: **on a size-exact row whose only residue is pool content
   (the `ABS32` words show as `*`, not `~`), read which register each pool word feeds
   and re-assign the global names accordingly.** The parked names were reconstruction
   guesses and one of them was wrong.

Rejected on the way (all 48 concrete bytes, all 392 B, `/var/c2c28_*`): declaration
with initializer `Hex4 hex = *(Hex4*)g_021CE0B4;`; `char hex[4]` with `*(Hex4*)hex`
copy; four scalar `hex.c[j] = g_021CE0B4[j]` assignments (53 bytes); pointer local
`{ Hex4 *hp = *(Hex4*)g_021CE0B4; hex = *hp; }`; `u16` pair copies (376 B, 261);
byte loop (388 B, 273).

## Parked rows (live residue each)

| address | function | image B | compiled B | concrete | first differing instruction |
|---|---|---|---|---|---|
| 0x021CC674 | CRYPTOi__BN_gen_exp_string | 408 | 408 | 43 | image `push {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}` \| ours `push {r4, r5, r6, r7, r8, sb, sl, lr}` (+0x00) |
| 0x021BC740 | NHTTPi_RecvProxyConnectHeader | 484 | 484 | 142 | image `str r0, [sp, #0xc]` \| ours `mov sl, r0` (+0x20) |
| 0x021C9B64 | DWCi_EncSessionCompleteCallback | 568 | 568 | 6 | image `ldr r3, [pc, #0x19c]` \| ours `ldr ip, [pc, #0x19c]` (+0x84) |
| 0x021C7644 | DWCi_Ndi_response_list | 640 | 724 | 507 | SIZE +84 |
| 0x021C68BC | req_callback | 648 | 664 | 513 | SIZE +16 |
| 0x021BD7E8 | NHTTPi_ThreadSendProc | 896 | 896 | 46 | image `mov r6, r0` \| ours `mov r7, r0` (+0x14) |
| 0x021C3218 | ghiPostStateDoPosting | 1564 | 628 | 537 | SIZE -936 |
| 0x021CD210 | CRYPTOi__BN_mod_exp_mont | 1908 | 1764 | 1505 | SIZE -144 |

### 0x021C9B64 — the cheapest row, 6 bytes, and it is a register tie

Everything is byte-identical except the two pointer temps of the 20-byte
`*(Key20 *)tmpbuf = *(Key20 *)g_021CF7AC.secretkey;` copy:

```
image +0084 ldr r3, [pc, #0x19c]      (source = &g_021CF7AC.secretkey)  -> r3
      +0088 add ip, sp, #0x11         (dest = tmpbuf)                   -> ip
ours  +0084 ldr ip, [pc, #0x19c]      -> ip
      +0088 add r3, sp, #0x11         -> r3
```

The copy *shape* is already right (post-indexed 2-byte pairs, same as the matching
17-byte `hextbl` initializer above it); only src/dst are inverted, and the knock-on is
two bytes. All 23 relocations resolve, so the row is genuinely 6 bytes from EXACT.

Tried this lane (all 568 B, all 6 bytes, `/var/c9b64_*`): source as a `Key20` struct
member of `Session` instead of `char[20]` and the cast dropped (the 0x021C2C28 lever —
**does not transfer here**); destination as a `union{char raw[52]; Key20 k;}` member so
neither side is cast; `Key20 *sk` named local both orders; `Key20 *dp`/`*sk` pair;
function-scope `Key20 *sk`; `char *dst = tmpbuf` reused by the two following calls;
`*tmpbuf = *&g_021CF7AC.secretkey`; byte-loop copy (564 B). The previous lane had
already burned 20+ spellings on the same two bytes (`lane_s9_structure_residues.md`).

Residue to hand on: the image reuses the register the `hextbl` loop just freed (`r3`)
for the **source** of the next copy; this build reuses it for the **destination**, and
schedules the pool load first regardless. No source spelling tried moves the allocator's
choice of which of the two address temps takes `r3`.

### 0x021BD7E8 — NHTTPi_ThreadSendProc, 46 bytes, one mirrored callee-saved pair

Every differing instruction is the same opcode with `r6`/`r7` exchanged:
`{sysInfo_p, threadInfo_p}` is in r6 (image) / r7 (ours) and
`{mutexInfo_p, connection_p, stat}` in r7 / r6, plus the knock-on constant registers
(image keeps 0 in `r5` and materialises `0xa`/`2` in `r1`; ours re-materialises `0` in
`r0` and uses `r0` for the constants) and the pool displacements.

Declaration-order permutations re-measured this lane, all inert on the pair except two
that move the **parameter** instead — a useful signal but the wrong direction:
`ThreadInfo *threadInfo_p;` (or `sysInfo_p` + `threadInfo_p`) moved to the top of the
declaration list makes `threadData_p` land in r6 (`/var/d7e8_Q*`), 896 B still.
`sysInfo_p` first / `sysInfo_p`+`mutexInfo_p` first / `mutexInfo_p` before `sysInfo_p`
/ swapping `connection_p`↔`threadInfo_p` all reproduce the baseline residue exactly.
Declaration order *does* move callee-saved assignments in this function (Q1/Q2/Q4), but
no permutation tried lands on the image's assignment. The parked header's candidate —
one extra long-lived value (`commBuf_p`) pinning the groups — is still the open lead;
nothing in this lane found it.

### 0x021CC674 — CRYPTOi__BN_gen_exp_string, three independent residues

(1) prologue reg set: the image keeps `0xff` in `fp` and pushes `r3`/`fp`
(`push {r3,r4,r5,r6,r7,r8,sb,sl,fp,lr}`, `pop` the same) where this build materialises
`0xff` in `sl` and pushes 8 registers; (2) the `e->d`/`e->top` pair load
(`ldm sb, {r2, r3}`) is scheduled at `+0x58`, after the two `p[-1] = 0` terminator
stores, where this build hoists it to `+0x44` — note the parked source *already* has
the load after `p[-1] = 0`, so the hoist is the compiler's, not the spelling's;
(3) `hi = 0` is emitted as `cmp r3,#1 / movle ip,r4` in the image and
`mov ip,r4 / cmp r3,#1` here. Three quarters of the row match, but the three residues
are independent and the earlier lane's declaration-order hill climb did not move any.

### Structural rows (not re-spelled this lane — baseline re-measured only)

`0x021C7644` (+84 B) and `0x021C68BC` (+16 B) both carry the parked claim that the
object was built by Metrowerks 4.0.0.1025 which no bundled `dsi/` front end writes; the
whole-array pin sweep in `docs/notes/overlay_sdk_residues_named.md` found no EXACT and no
new MATCH anywhere, so these stay capped as parked. `0x021C3218` (-936 B) is a partial
rewrite whose GHIPostData field roles are still approximate. `0x021CD210` (-144 B) has a
known pinned-residue floor of 1504 concrete under 1.6sp1/1.6sp2 (not the vendor front
end) and 1505 under its own pin.

`0x021BC740` (142 concrete, 484/484): prologue/frame shape only — the object spills
`threadInfo_p` into `[sp+0xc]` where this build spills `endFlag`, and `&tmpbuf[0]` /
`recvbyte` have `fp`/`sb` swapped. Not touched this lane.

## Compiles run

~39 `match.py one --diff` compiles (9 baselines + 30 variants) plus 2 `manifest
--verify` runs. Wall clock ≈ 50 min of the 85 min budget. No pin or flag sweep was run:
`docs/notes/overlay_sdk_residues_named.md` measured that axis shut for this exact row set
(4284 configurations, no EXACT and no new MATCH).
