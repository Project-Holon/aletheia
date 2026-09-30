# Lane T27: ov016 open SDK rows 26..33

Slice: `python scratch/a2/open_rows.py ov016 26 8` under the current numbering — seven parked
`libdwcutil.TWL.HYB.a` rows, 660..996 bytes. All seven were read whole and re-measured under their
own header pin, ISA and lang; the first divergence of every row was located before anything else was
judged (this lane's numbers agree with T17's table, adjusted for the row renumbering).

Nothing reached EXACT. **One row's body was materially improved and filed** (row 29
ParentStateCallback: 245 -> 99 concrete, 96 -> 34 diff lines, size class unchanged at -4). The
remaining six keep their parked bodies with the residues below.

Rule 4 was honoured: no pin or flag sweep. Every cell below is a body-shape cell, and the two cells
that landed were found by *reading the diff*, not by permuting flags.

## Residues, all seven rows (extent | compiled | concrete | first divergence)

| # | address | function | extent | compiled | concrete | first divergence | pin |
|---|---|---|---|---|---|---|---|
| 26 | 0x021B9BF8 | ScanAP | 660 | 652 | 355 | `+000A ldr r0,[pc,#0x26c]` | `ldr r0,[pc,#0x264]` | ../2.0/sp1p2 |
| 27 | 0x021C73D0 | input | 704 | 748 | 601 | `+001C bgt 0x21c73f8` | `ble 0x21c7580` | 1.1p1 |
| 28 | 0x021D1208 | DWCi_WINlInitEx | 796 | 784 | 567 | `+0000 push {r4..fp,lr}` | `push {r3,r4..fp,lr}` | 1.1p1 |
| 29 | 0x021D2450 | ParentStateCallback | 796 | 792 | **99** | `+029C ldr r0,[r4]` | `ldr r2,[r4]` | 1.1p1 |
| 30 | 0x021C7D80 | drawMessage | 824 | 828 | 479 | `+001C ldr r0,[pc,#0x2e8]` | `ldr r0,[pc,#0x2ec]` | 1.1p1 |
| 31 | 0x021BD8D8 | DWCi_KBlInit | 844 | 876 | 519 | `+0000 push {r3..fp,lr}` | `push {r4..fp,lr}` | 1.1p1 |
| 32 | 0x021BA804 | AutoConfigThreadEx | 996 | 952 | 801 | `+0000 push {r4,r5,r6,r7,lr}` | `push {r3,r4,r5,r6,r7,lr}` | ../2.0/sp1p2 |

(Row 26 is 0x021B9BF8 ScanAP under this numbering; T17's row 27. Rows 26..32 here are T17's
27..33.)

## Row 29 ParentStateCallback: two levers landed, filed 245 -> 99

`src/pending/ov_sdk/ov016_func_021D2450.c` is rewritten and re-measured: **792 of 796 bytes, 34 diff
lines, 99 concrete bytes** (T17 and the residue index both record 245 concrete / 96 lines for the
same 792). `push {r4, r5, r6, r7, r8, lr}` now matches the image byte for byte.

**Lever 1 — hoist the work pointer above the call (the whole register shift).** The image loads
`*g_021DE65C` into r6 *before* `bl OS_DisableInterrupts` and uses it for the `|=` after the call:
the value is live across the call, so it needs a callee-saved register, which is why the object has
five of them (`push {r4..r8,lr}`). Written as `g_021DE65C->mbpState.connectChildBmp |= 1 << child_aid;`
after `u32 enabled = OS_DisableInterrupts();`, 1.1p1 defers the global load to after the call into a
scratch register (r3), needs only four callee-saved values, pads the save area with r3, and every
register in the function lands one lower (r7/r6/r3 for the object's r8/r7/r6). Spelling the operand
as a named local declared *before* the call is what fixes it:

```c
DWCi_MOV_WPB_WORK *w = g_021DE65C;
u32 enabled = OS_DisableInterrupts();
u8 *mac;

w->mbpState.connectChildBmp |= 1 << child_aid;   /* the rest of the case still uses g_021DE65C */
```

The following `mac` computation goes on reading `g_021DE65C` itself, which is why the object reloads
the base at `+0094` and drops r6 after `+0080`; a named local used for the whole case would have kept
it live across `OS_RestoreInterrupts` instead and does not match.

**Lever 2 — case 10's arms are inverted in the source.** The image is
`if (DWCi_MOV_MBP_GetState() != 2) DWCi_MOV_MBP_KickChild(child_aid); else { ... }`: the KickChild arm
is the fallthrough at `+0170` and the `beq` at `+016C` jumps *forward* into the body at `+017C`. With
`== 2` written first, 1.1p1 emits `bne` and puts the body first. Written with the test inverted, the
case-10 block matches instruction for instruction.

Residue, two named causes, both lowering/colouring and not source shape:

- **(a) `+029C`, the 0x1b144/0x1b140 pair.** Image: `ldr r0,[r4]; add r0,r0,#0x1b000;
  ldr r1,[r0,#0x144]; cmp r1,#0; movne r1,#0; strne r1,[r0,#0x144]` — one base `(g+0x1b000)` in r0,
  value in r1, reused for load and store. Ours associates the store address as
  `(g + 0x144) + 0x1b000` and keeps g alive in r0 (`add r0,r2,#0x144; add r1,r0,#0x1b000`), two
  instructions longer per block. Spelling both accesses as
  `((u32 *)((char *)g_021DE65C + 0x1b000))[0x51]` / `[0x50]` reproduces the image's association
  exactly — measured in `scratch/t27/gen4/w3.c`: **776 bytes, 51 concrete, 25 lines** — and what is
  left there is only the base/value r0/r1 swap. Not filed: it moves the row's recorded class from -4
  to -20 (the same call T17 made about ScanAP's 644/382 grid cell).
- **(b) `+02D0`, case 13's `switch (userInfo->f0)` over {1,2,9}.** The object lowers it as a range
  tree — `cmp #8 / bgt`, `popge`, `cmp #2 / popgt`, `cmp #1 / poplt`, `cmpne #2 / beq`, then
  `cmp #9 / popne` on the high path — around one shared `DWCi_MOV_MBP_ChangeState(7)`. 1.1p1 emits a
  linear chain: `cmp #1 / cmpne #2 / beq / cmp #9 / popne`. The tree is 28 bytes larger.
  Sixteen spellings of the case body leave the chain untouched: case order 9,2,1 / 1,2,9 / 9,1,2,
  with and without `default:`, the value bound to a `u16` local and to an `int`, the field as `u16`
  and as `short`, `switch ((short)userInfo->f0)`, an `if (…||…)` chain of the three cases, an
  explicit `(u16)(f0 - 1) <= 1 || f0 == 9` range test (784 bytes — bigger, still two compares), and a
  nested `if (f0 > 8) / else if (f0 >= 1 && f0 <= 2)` tree (800 bytes — right shape, but it emits
  two ChangeState call sites where the object has one). All measured; `scratch/t27/gen4/`.
- `dwc_mov_mbp.o` carries `.comment` 4.0.0.1025 (1.1p1 is 1024, 1.2 is 1026), so both residues may
  be front end rather than source.

## Row 30 drawMessage: err's register is the whole gap, 15 cells flat

Residue restated from T17 with the mechanism identified: the object keeps the compared `ErrorCode`
value in **r1** and uses r0 as the threshold scratch (`ldr r1,[r0]; cmp r1,r2; sub r0,r2,#1;
cmp r1,r0`), 1.1p1 keeps it in **r0** and uses r1 (`ldr r0,[r0]; cmp r0,r2; sub r1,r2,#1;
cmp r0,r1`). That single colouring difference is also the whole +4 bytes: with err in r0, the
`prm == 2` blocks load prm into r0 and the later `prm - 2000` test has to reload prm from `sp+0x18`
(`ldr r1,[sp,#0x18]; sub r1,r1,#0x7d0`) where the object still has prm in r0 from `+012C`. Fix the
colour and the reload disappears and the size is 824.

Fifteen cells tried, **every one byte-identical to the parked body** (828 bytes, 479 concrete,
first divergence `+001C` unmoved): `int err = ErrorCode;` as a declaration initialiser in place and
at the top, `register int err`, `long err`, `unsigned err`, `u32/u16/s8` spellings of `err`, `prm`
as `u32/long`, `id` as `u16/s16/u32`, `err = ErrorCode;` twice, `err` reached through
`int *perr = &ErrorCode`, no `err` local at all (the compiler CSEs the global into r0 anyway),
`id = 0;` moved after the chain read, `err` read before `DWCi_GetParam2_` (this one moves the first
divergence to `+0008`, the constant load is hoisted — worse), the two `(prm == 2) ? :` arms as
`mov/movne` (465 concrete, the same +4 intact) and as `id = 5; if (prm != 2) id = …` (844, worse).
`/tmp` cells in `scratch/t27/gen/` and `scratch/t27/gen2/`; the `a_perr` cell is byte-identical to
the base, so the allocator canonicalises these spellings. Parked, not improved.

## Rows 26, 27, 28, 31, 32: residues unchanged from T17, restated one line each

- **26 ScanAP (652/660, thumb, ../2.0/sp1p2, 355 concrete).** The 8 missing bytes are the loop tail:
  the object increments `retry` *and* re-reads it for the bound test out of its stack slot at
  `sp+0x1c` (`ldr r0,[sp,#0x1c]; adds r0,r0,#1; str r0,[sp,#0x1c]; ldr r0,[sp,#0x1c]; cmp r0,#0x1e`)
  and the same 8 bytes move the two `break` branches onto the canceled-check; this front end keeps
  the counter in a register. Second half of the same residue: the `gAPMac` copy computes `pBssid+0x28`
  twice in the object (byte 0 through one register, bytes 1..5 through a copy held in another) where
  an unrolled front end kills `n` too. Both were re-read here, not re-swept.
- **27 input (748/704, 1.1p1, 601 concrete).** The two arms of the first dispatch are laid out
  inverted: the object puts the jump table and `default` so that `p <= 0` is the fallthrough
  (`bgt Lswitch; popeq {..pc}; b Ldefault`) and carries a dead `pop {r3..r7,pc}` at 0x021C7418 that
  1.1p1 never emits; ours emits `ble Ldefn` with the switch as fallthrough. Provence-capped at
  .comment 4.0.0.1025.
- **28 DWCi_WINlInitEx (784/796, 1.1p1, 567 concrete).** First divergence is the prologue: the object
  has one more callee-saved register than ours (frame `0x24` vs `0x20`, and its five
  `ldrb sl/sb/r8/r7/r6` from the byte table at `+0010` against our `sl/ip/sb/r8/r7` — the object's
  second byte keeps a real callee-saved register where ours falls to `ip`). The object also hoists
  the `DWCiMsgCmn` pool word to r4 where ours defers it to r5. This is the same *class* as row 29's
  lever 1 (a value that must be live across a call being kept in a scratch register instead), and it
  is the first place to look if this row is picked up again. Provenance-capped at 4.0.0.1025.
- **31 DWCi_KBlInit (876/844, 1.1p1, 519 concrete).** Prologue: object `push {r3,r4..fp,lr}` +
  `sub sp,#0x20`, ours `push {r4..fp,lr}` + `sub sp,#0x24` — the object spends the pad register and
  a smaller frame, i.e. it holds two small constants in registers that ours spills to `sp+0x10`
  (`strh r3,[sp,#0x1c]` / `strh r2,[sp,#0x1e]` against our `[sp,#0x20]` / `[sp,#0x22]`), and it
  materialises `0x480` per call where 1.1p1 hoists it. Provenance-capped at 4.0.0.1025.
- **32 AutoConfigThreadEx (952/996, thumb, ../2.0/sp1p2, 801 concrete).** Prologue: object
  `push {r4,r5,r6,r7,lr}` + `sub sp,#0x2c`, ours `push {r3,r4,r5,r6,r7,lr}` + `sub sp,#0x28`; at
  `+000E` the object *spills* a value twice (`str r4,[sp,#0xc]; str r4,[sp,#4]`) where ours copies
  it into two registers (`adds r6,r4,#0; adds r7,r4,#0`) — a spill-vs-copy allocation difference to
  attack before the zero-fill idiom. The residual zero-fill of `g_021DD224` is unchanged: the object
  emits the 2x-unrolled `stm` large-aggregate idiom, a plain `for` zero loop and `memset()` both come
  out ~40 bytes short. Seven data globals still want an outside witness.

## Verdicts

Nothing promoted. Row 29's body was replaced with a strictly closer one at the same size class
(99 concrete / 34 lines against 245 / 96). Rows 26, 27, 28, 30, 31, 32 keep their parked bodies.
Measured cells for this lane live in `scratch/t27/` (`gen/`, `gen2/`, `gen3/`, `gen4/`, `vrun.py`).
