# Lane U7 — ov114 open SDK rows 0-14

Slice: `python scratch/a2/open_rows.py ov114 0 15` (indices 0..14, smallest first).
15 rows, 4,456 bytes. Compiler start pin `--cc 1.2` per the wave lead (the ov114
`DWCi_Ndi_intToStrFigure` result); every row below was also checked at `1.1p1`,
and where the two disagree it is noted. No pin or flag sweep was run.

## Filed EXACT

| address | bytes | function | shard |
|---|---|---|---|
| 0x021C07B8 | 248 | func_021C07B8 (`ghiTrySendThenBuffer`, libdwcgsghttp) | `layout/matched/ov114/pkt_ov114_021C07B8.json` |

Source `src/matched/ov_sdk/ov114_func_021C07B8.c`, EXACT under both `dsi/1.1p1`
and `dsi/1.2` (byte-identical), `-O4,p`, arm, c99. Verified with
`python tools/match.py one ... --cc 1.1p1 --lang c99` and filed with
`python tools/match.py manifest --verify --shard ov114/pkt_ov114_021C07B8`.

### The lever that closed it

`docs/idioms/a-bare-constant-return-guard-is-predicated-unless-its-exit-is-shared.md`
applies verbatim, but the shape that works is *not* the else-if chain in the
parked source. The image puts the shared `return 2` block **between** the
`return 0` of the `-1` guard and the `rcode == len` test:

```
00ac beq 00c4   ; rcode == -2 -> shared return 2   (real branch, not moveq/popeq)
00b8 bne 00cc   ; rcode != -1 -> fall past the return 0 (_unpredicated_ return 0)
00bc mov r0,#0; pop
00c4 mov r0,#2; pop     <- the shared exit, sits BEFORE the len test
00cc cmp r4,r5; moveq r0,#1; popeq
```

The spelling that emits that layout is a two-guard `if/else` whose then-arm is
the `-1` guard and whose else is the `-2` return, with the `len` test as a
*separate* `if` after the whole if/else statement:

```c
rcode = ghiDoSend(connection, buffer, len);
if (rcode != -2) {
    if (rcode == -1)
        return 0;
} else {
    return 2;
}
if (rcode == len)
    return 1;
```

Measured against the parked spelling (9 concrete mismatches, 26 bytes):
else-if chain `if (rcode != -2) { if (-1) return 0; else if (len) return 1; }
else return 2;` -> 9; three flat guards (`if (-2) return 2; if (-1) return 0;
if (len) return 1;`) -> 18; `switch` -> 19; `goto ret2` -> 16; **the shape above
-> EXACT**.

## Parked, with residues

Image is the left column, ours the right.

- **0x021BACFC** NHTTPi_setReqQueue, 152 B, 5 instr / 17 B off. `+0064 ldr r2,
  [r6, #4]` | `mvn r1, #0`. The object stores `list_p->field_0x08` *after* the
  counter increment, and its `f4++` reloads `field_0x04` (into r2) instead of
  reusing the r4 load. That reload only survives because an aliasing store sits
  between the two loads — with the store after the increment, MWCC CSEs the
  reload away and shifts `id` to r6 / `req_p` to r4 (measured 22 instr off for
  all four spellings: `f4++`, `id = f4++`, `f4 = id + 1`, and the doubled-load
  spelling). Needs a shape that forces the reload without a register flip.
- **0x021BBA14** NHTTPi_CancelRequestAsync, 152 B, 22 instr. `+0030 beq
  0x21bba7c` | `beq 0x21bba78` — block layout of the shadow-callback test; the
  same shared-exit class as 021C07B8, not yet found.
- **0x021CA5E4** ASN1Skip, 184 B, 32 instr. `+0004 ldr r4, [r0]` | ours starts
  with a `ldr`/`ldr lr` pair — prologue and loop register set differ.
- **0x021CB3B4** CRYPTOi__BN_add_word, 224 B, 20 instr. `+0010 mov r2, #0` |
  `moveq` — ours predicates a guard the object branches on (same class as
  021C07B8; the row is 224 B and the divergence is at the top, so the whole
  body shifts).
- **0x021C98E0** DWCi_EncValidateKey, 240 B, **4 instr / 20 B off** (closest
  park). `+00A8 ldrb r0, [r8, #1]` | `ldrb r1, [r8, #1]`: the 20-byte secretkey
  copy loop is instruction-for-instruction identical except that r0 and r1 are
  swapped in both the load pair and the store pair. Nine spellings tried
  (temp declaration order, store order, `s += 2` position, no temps, struct
  assignment, byte loop, `while`) all give the same 4 swapped instructions;
  the flip is an allocator tie-break this front end makes for the two symmetric
  byte temps, not a source-order effect.
- **0x021C60C8** DWCi_Ndi_encodeBASE64, 248 B, 44 instr. `+0004 mov r7, r2` |
  `mov r8, r2` — third-parameter home register; body shape differs downstream.
- **0x021BBBC8** NHTTPi_getHeaderValue, 292/296 B (4 short). `+0008 mov sl, r0`
  | `mov r3, r0` — a parameter the object keeps in a callee-saved register.
- **0x021CB764** CRYPTOi__BN_usub, 332 B, 44 instr. `+0004 mov r7, r1` |
  `mov r5, r1`.
- **0x021CC674** CRYPTOi__BN_gen_exp_string, 408 B, 16 instr. `+0000 push {r3,
  r4, r5, r6, r7, r8, sb, sl, fp, lr}` | `push {r4, r5, r6, r7, r8, sb, sl,
  lr}` — the object saves ten registers, ours eight: a local our body does not
  have.
- **0x021BC740** NHTTPi_RecvProxyConnectHeader, 484 B, 58 instr. `+0020 str r0,
  [sp, #0xc]` | `mov sl, r0` — the object spills the argument, we hoist it.
- **0x021C9B64** DWCi_EncSessionCompleteCallback, 568 B, **6 instr**. `+0084
  ldr r3, [pc, #0x19c]` | `ldr ip, [pc, #0x19c]`: the 20-byte `hextbl` literal
  copy has the literal pointer and the stack destination in opposite registers
  (object r3 = literal, ip = sp+0x11; ours r3 = sp+0x11, ip = literal). Also
  noted in the parked header: the `hextbl` template (vendor @16117, 0x021CE1CC)
  has no overlay attestation class, so this row tops out at MATCH even with the
  register order fixed. Declaration-order swap measured worse (10).
- **0x021C7644** DWCi_Ndi_response_list, 640 B, 150 instr. `+0030 ldr r1, [pc,
  #0x244]` | `ldr r1, [pc, #0x298]` and a `ldrgt` vs `ble` at +0080 — literal
  pool layout and branch polarity both differ.
- **0x021C68BC** req_callback, 648 B, 161 instr. `+0008 mov r8, r0` | `mov r7,
  r0`.
- **0x021BD7E8** NHTTPi_ThreadSendProc, 896 B, 33 instr. `+0014 mov r6, r0` |
  `mov r7, r0` — argument register homes differ from the start.

## Compiles

Roughly 60 compiles: 15 rows x 2 pins for the baseline, then 5 + 5 + 5 variants
for 021C98E0, 5 + 5 for 021C07B8, 1 + 4 for the last pass. Wall clock inside
the lane: ~70 min.
