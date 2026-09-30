# Lane T8 — ov114 open SDK rows 0-9 (the ten smallest open rows)

Measured 2026-09-30. Slice from `python scratch/a2/open_rows.py ov114 0 10`.
Every verdict below was produced by `tools/match.py one ... --lang c99 --arm` against the
live image, not copied from the parked header. **1 of 10 closed (EXACT); 9 parked with a
named residue.**

## Closed

| region | address | function | image B | compiled B | verdict |
|---|---|---|---|---|---|
| ov114 | 0x021C7A74 | `DWCi_Ndi_intToStrFigure` | 212 | 212 | **EXACT** |

Filed `src/matched/ov_sdk/ov114_func_021C7A74.c`, shard
`ov114/pkt_ov114_021C7A74` (`match.py manifest --verify --shard` → `0x021C7A74 sdk
func_021C7A74 dsi/1.2 EXACT`). Two levers, both necessary:

1. **Statement position of the 64-bit update.** `n -= (u64)x * g_021CE138[i];` must be
   written *before* `p[len] = x + '0';`, not after it. With the store first, the scheduler
   keeps the `umull`/`mla` scratch pair one register lower (`r2/r1` instead of `r3/r2`) and
   sinks the store above the `subs`/`sbc` — 15 concrete bytes. Reordering alone took the row
   from 119 to 2 bytes.
2. **Both counters cleared in the `for` initialiser.** `for (i = 0, b = 0; i < 16; i++)`.
   With `b = 0;` on its own line ahead of the loop the initialiser is emitted `mov r0, r5`
   before `mov r4, r5` — the last 2 bytes. (The equivalent standalone `i = 0; b = 0;` plus an
   empty init clause, and the comma form `i = 0, b = 0;`, are also EXACT.)

**This row is a later build than the rest of the region.** With the closed body, 1.1 and
1.1p1 produce **208 bytes** (four short) with 118 concrete bytes off; 1.2, 1.2p1, 1.2p2, 1.3,
1.3p1, 1.6sp1 and 1.6sp2 all reproduce the 212-byte original byte for byte at `-O4,p`,
`-O4,s`, `-O4` and `-O3`. This is the "size-exact with a prologue difference is a different
build" case, so the pin was checked once and the header now carries `compiler: 1.2`. The
parked header's `1.1p1` cannot be right for this function. Note no other filed ov_sdk source
currently uses 1.2, so this is also a lead for the region's other open rows.

## Parked

| address | function | image B | compiled B | residue |
|---|---|---|---|---|
| 0x021BACFC | `NHTTPi_setReqQueue` | 152 | 152 | 17 B, one redundant reload |
| 0x021BBA14 | `NHTTPi_CancelRequestAsync` | 152 | 148 | 66 B, **4 bytes missing** |
| 0x021CA5E4 | `ASN1Skip` | 184 | 180 | 80 B, **4 bytes missing** |
| 0x021CB3B4 | `CRYPTOi__BN_add_word` | 224 | 224 | 48 B, zero not hoisted |
| 0x021C98E0 | `DWCi_EncValidateKey` | 240 | 240 | 4 B, r0/r1 swapped in the copy loop |
| 0x021C07B8 | `ghiTrySendThenBuffer` | 248 | 248 | 26 B, `rcode == -1` return predicated |
| 0x021C60C8 | `DWCi_Ndi_encodeBASE64` | 248 | 248 | 95 B, whole allocation one register high |
| 0x021BBBC8 | `NHTTPi_getHeaderValue` | 296 | 292 | 186 B, param-home order + 4 bytes missing |
| 0x021CB764 | `CRYPTOi__BN_usub` | 332 | 332 | 24 B, `min`/`max` home registers swapped |

### 0x021BACFC NHTTPi_setReqQueue — 17 concrete, first `+0064`

image `ldr r2, [r6, #4]` | ours `mvn r1, #0`.
Everything up to +0x64 matches. The object loads `listInfo_p->field_0x04` **twice**: `r4` for
the returned `id`, then a fresh `r2` for the increment, and only then stores
`list_p->field_0x08 = id`. Our body already stores `field_0x08` before the increment (the w8
lever) and loads once. Re-spelling the increment (`++`, `+= 1`, `= x + 1`, `1 + x`, a named
reload local, both store orders) either keeps the single load or moves `id` out of `r4` and
`req_p` out of `r5` (the 46-byte state the parked header records). The reload is the same
"increment re-reads the field" shape as `a-field-bound-to-a-local-is-hoisted-above-an-earlier-store-reading-it-twice-keeps-the-order`.

### 0x021BBA14 NHTTPi_CancelRequestAsync — 66 concrete, first `+0030`, **compiled 4 short**

image `beq #0x21bba7c` | ours `beq #0x21bba78` (every later branch target is 4 low).
The guarded block in the image re-loads `reqCurrent_p->field_0x0c` into `r0` for the store
(`+004C ldr r0, [r6, #0xc]`) where ours reuses the predicated `r1` from the condition
(`ldreq r1, [r6, #0xc]`). No source shape tried — nested ifs, `rc = 1` before the store,
`!*p`, a volatile/unsigned deref, a listInfo_p local, static inline helpers for the flag test
and/or the flag store — re-reads the field; the compiler keeps CSE-ing the two derefs into one
load, exactly as documented in `a-field-reload-after-a-sibling-store-cannot-be-forced`.

### 0x021CA5E4 ASN1Skip — 80 concrete, first `+0004`, **compiled 4 short**

image `ldr r4, [r0]` | ours `ldr lr, [r0]`.
Purely the register colouring of the four locals: the object keeps `data` in **r4**, `tag` and
the `dlen` temp in **lr**, `len` in **ip**; ours puts `data` in lr and the temps in r4, with the
same instruction stream afterwards (the `beq`/`b` arms and the `ldrb`/`add ip` loop are
byte-identical). Declaration order and the `dlen` CSE forms (compound decrement, named temp,
`--dlen`/`dlen--`) do not move `data` off lr.

### 0x021CB3B4 CRYPTOi__BN_add_word — 48 concrete, first `+0010`

image `mov r2, #0` | ours `moveq r0, r4`.
The object materialises the literal `0` into **r2 at +0x0010**, before the `if (w == 0)`
return, and keeps it live to +0x006C where it serves all three clears (`a->neg = 0` twice,
`a->top = 0`). Ours materialises the zero at its first use and therefore also has to
re-materialise it in r0 at +0x005C, and `a->d` lands in r2 instead of r1 with `d[0]` in r1
instead of r0 — the whole 48 bytes is downstream of the missing entry hoist. Tried:
`int i = 0;`/`i = 0;` as the first statement (the zero sinks and is elided — the compiler
emits nothing at +0x0010), a named `zero` local, and a first-statement `i = 0` plus a
`for (;;)`. The obvious "the hoisted zero is `i`" reading is wrong: with `i = 0` first the
entry `mov` does not appear at all. See
`a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it`: the
0 is most likely CSE'd with a literal elsewhere in the source that our body spells
differently (`w == 0`, `a->top > 1`, `l < w` are the candidates).

### 0x021C98E0 DWCi_EncValidateKey — 4 concrete, first `+00A8`

image `ldrb r0, [r8, #1]` | ours `ldrb r1, [r8, #1]` (and the matching swap at +AC/+B4/+B8).
The function is otherwise byte-identical. The image's 20-byte copy is the 2-byte loop
`ldrb r0,[s,#1]` / `ldrb r1,[s],#2` / `strb r0,[d,#1]` / `strb r1,[d],#2`; ours emits the same
four instructions with the two temps exchanged. **Every spelling tried reproduces the swap**:
the explicit pointer loop in both declaration and store orders, a `char[0x14]` struct
assignment, a two-member `Pair` struct copy, a byte `for` loop, `unsigned short` element copy,
function-scope temps, `int` temps, while/-`++s` variants — 20 compiles, all 240 bytes / 4 diffs
or worse. The compiler gives the offset-form load (and its offset store) the lower register and
the post-increment load the higher; the image has the opposite. Capped.

### 0x021C07B8 ghiTrySendThenBuffer — 26 concrete, first `+00AC`

image `beq #0x21c087c` | ours `beq #0x21c0888`.
Size-exact and byte-identical outside the `ghiDoSend` result block. The image lowers
`rcode == -1 → return 0` as an **unpredicated out-of-line block**
(`bne #0x21c0884` ; `mov r0, #0` ; `pop`) with the `return 2` block placed immediately after it
and `beq`-shared from the `-2` test; ours if-converts the same return to
`moveq r0, #0` / `popeq`, which is 4 bytes short. The image's `-2`/`-1` tests themselves match
ours instruction for instruction (`mvn r0,#1` / `cmp r6, r0` / `add r0,r0,#1` / `cmp r4, r0`),
so the difference is purely the return lowering. Tried and all still 26 bytes: the parked
nested `if (rcode != -2) {...} else return 2;`; an early-return chain (`rcode == -2` / `-1` /
`len` as three flat ifs and as an `else if` ladder); `switch (rcode)`; `return 1 - 1;`; a
block-local `int z = 0; return z;`; a dummy self-assignment before the return; a `goto ret2;`.
This is the `a-bare-constant-return-guard-is-predicated-unless-its-exit-is-shared` shape, but
the image's exit block at 0x21c0874 has no second predecessor, so the "shared exit" tell does
not apply and no re-spelling found the branch.

### 0x021C60C8 DWCi_Ndi_encodeBASE64 — 95 concrete, first `+0004`

image `mov r7, r2` | ours `mov r8, r2`.
Size-exact; the code shape matches everywhere and the whole allocation is shifted one register.
Image: `length` r7, `srcbin` r8, `encstr` sb, `len` r6, the two zeros r5/r4, table base **sl**,
`'*'` fp. Ours: `length` r8, `srcbin` sb, `encstr` sl, `len` r7, zeros r6/r5, table base **r4**.
Both push the same ten registers. This reads like one extra callee-saved value at the top of
the image's function (which is also where `a-second-zero-must-be-spelled-as-a-copy-of-the-first`
lives: the image's `mov r5,#0` / `mov r4,r5` pair is the copy-of-zero shape, and ours is a
straight `mov r6,#0`). Making the second zero depend on the first (`mov r4, r5` in the source)
is the untried lever and is where the next lane should start.

### 0x021BBBC8 NHTTPi_getHeaderValue — 186 concrete, first `+0008`, **compiled 4 short**

image `mov sl, r0` | ours `mov r3, #0`.
The size-exact-but-prologue-differs case. The image's prologue homes its parameters in the
order `res_p→sl`, `0`, `pos_p→fp`, `label_p→sb`, `r5 = sp+8`, `str 0`, `r6 = sp+4`; ours
initialises the frame local first (`mov r3,#0` / `add r6,sp,#4` / `str r3,[sp,#4]`) and homes
the parameters last, which is the whole -4 and every later target. Independently, at +0x8C the
image loads `labelend` into r1 and `len` into r0 (`ldr r1,[sp,#8]` / `ldr r0,[sl]` /
`add r1,r1,#1` / `cmp r1,r0`) where ours uses r0/r2 — the "first of two loads gets the lower
register" colouring again. The parked header's reverse-DWARF local order fixes the stack slots
and r7/r8 but not this prologue.

### 0x021CB764 CRYPTOi__BN_usub — 24 concrete, first `+000C` (was 51)

image `ldr r5, [r6, #4]` | ours `ldr r4, [r6, #4]`.
**Improved from 51 to 24 bytes** by the previously-recorded lever: `i` declared **`long`, not
`int`** (332 bytes, 23 lines). That is the only change that helps — declaration orders,
removing `register`, `int`/`long` combinations for `carry`, extra `diff` locals, the guard
written `min > max` or against `a->top`/`b->top` directly, and both assignment orders all land
back on 44 lines. The remaining 23 lines are a single permutation: the object homes
`min` in **r5** and `max` in **r4**, this build homes `min` in r4 and `max` in r5; loading and
storing order (`ldr r5,[r6,#4]` before `ldr r4,[r7,#4]`) matches, and every use of the pair
(`cmp r4,r5`, the loop bounds, the `t1`/`r1` temps of the four-word copy, `r->top = max`)
differs only by which of the two registers holds which. Neither declaration order nor
assignment order moves it, so the lever has to be a body-shape change that makes `min`'s live
range start earlier than `max`'s.

## Notes on method

- No pin or flag sweep is reported as a verdict. The only pin check made was 021C7A74, which
  was size-exact with a differing prologue; it returned six compiler trees that are byte-EXACT
  and confirmed the parked `1.1p1` is not this translation unit's build.
- All 10 rows had `git status --porcelain` checked before any edit; none of the ten parked
  files was already modified by another writer.
- Scratch: `scratch/laneT8/` (`base_<addr>.txt` live diffs, `try*.py` variant drivers).
