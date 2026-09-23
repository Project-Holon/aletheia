# Wave 10: clact.c + ica_anime.c

**6 exact** (5 EXACT, 1 EXACT*), 1 byte-correct MATCH* parked in pending, 3 DIFF with notes. Nothing committed.

## clact.c (ARM)
| addr | size | verdict | file |
|---|---|---|---|
| 0x0204BE38 | 76 | EXACT | src/matched/func_0204BE38.c (pkt_0204BE38) |
| 0x0204C2C8 | 260 | DIFF, 58 out (was 183) | appended to docs/notes/pkt_0204C060.c.txt |
| 0x0204C3CC | 660 | EXACT | src/matched/func_0204C3CC.c (pkt_0204C2C8) |
| 0x0204DD08 | 480 | EXACT | src/matched/func_0204DD08.c (pkt_0204DD08) |
| 0x0204DEE8 | 296 | EXACT | src/matched/func_0204DEE8.c (pkt_0204DD08) |

- **BE38**: installs the cull callback func_0204C2C8 at +0x40 of each 0x48-byte element. Two changes closed it: the `on != 0` arm is written first, and the permuter found that `i` has to be declared before `fn`.
- **C3CC**: an 8-argument, 2x2-matrix corner cull. The four `+= d` translations are separate statements before the `&&` chain. The locals are declared max-first and seeded `min = p; max = p;`. The permuter took it from 37 to 25 bytes out; a sweep of all 240 declaration/seed orders closed it.
- **DD08**: the materialised `lsl r0, r3, #5` that the note and idiom file call unreachable from C comes from `unsigned long long ofs = head * 32;`.
  - Any 32-bit local gets folded into both consumers.
  - A u16 or s16 local keeps the temporary but narrows it.
  - The permuter found the materialising temp as u16 (5 bytes out) and the tail's `hi` temp. Sweeping the temp's width by hand found the 64-bit form.
- **DEE8**: returns void. Closed by two changes: the out-locals are declared `b` then `a`, and the 0x200 test is written small-arm-first.
- **C2C8**: the pool word is **0xC000C000**, not 0x00C000C0 as every older note has it. The function computes a GXOamAttr bounding rectangle.
  - The two different clamps come from one inline s16 `RepeatX`/`RepeatY` helper applied twice.
  - The call passes 8 arguments.
  - The 58 bytes left are register names only. Hill and anneal are both flat at 58: `best DIFF asm=655 bytes-out=58 size=260/260`.

## ica_anime.c (Thumb)
| addr | size | verdict | file |
|---|---|---|---|
| 0x0201183C | 848 | EXACT (was 631 out) | src/matched/func_0201183C.c (pkt_0201183C) |
| 0x02011D9C | 272 | DIFF, 157 out | appended to docs/notes/pkt_02011D9C.c.txt |
| 0x02011F28 | 104 | EXACT* (pad) | src/matched/func_02011F28.c (pkt_02011F28) |
| 0x02012164 | 104 | MATCH* | src/pending/func_02012164.c |
| 0x02011688 | 56 | DIFF, 26 out (was 32) | appended to docs/notes/pkt_02011688.c.txt |

- **1183C** was closed by five changes:
  - `layout/runtime_arm9.txt` has the soft-float names **swapped**: 0x0209C95C is really `_fadd` and 0x0209CB8C is `_fsub`. With that fixed, the plain SDK `FX_F32_TO_FX32` macro matches.
  - The macro reads through a `volatile float *` buffer, which gives the reload in each arm and a stack slot per site.
  - Two callees take 5 arguments: func_0204944C (the fifth is the buffer) and func_02030734 (the `__LINE__` 0x2bd).
  - `q >> 12` is never put in a named local.
  - `i = 0` goes between the alloc call and the fill call.
- **11F28 / 12164**: both "register ties" were really callee arity:
  - func_020261E4 takes `(id, p->f1c)`.
  - func_02013D34 takes the result of `func_02012AC8(func_020120F8(p))`.
- **12164** is capped only by func_02158318. ov010 labels it, but its only caller in the image is inside this range.
- **11D9C**:
  - The note misread the pool words: they are Thumb pointers to func_02011D28/40/60/7C.
  - The 0xE6 argument is an overlay-id symbol.
  - Evidence caps it at MATCH even if the bytes match: three ov230 probe calls, func_0215FA00, and the id word.
  - The remaining byte miss is a constant-4 CSE in the second func_0203064C call.
- **11688**: `idx %= n` (reusing the parameter) recovers one of the two missing copies.

## Other findings
- func_02011B8C.c (already matched) writes `h - 360.0f`, but the bytes are an add. That is the same name swap as above. Recorded in the family header; the file was not edited.
- The permuter's `copy` mutation produced non-value-preserving C on 11D9C (it reads `p` before `p` is assigned). Its generated C99 mid-block declarations also fail to compile under match.py. Both were rejected and applied by hand where useful.
- src/pending/func_0204AC18.c is still DIFF on codegen, even though DD08 is now EXACT.
- Family headers updated: docs/families/clact.h and docs/families/ica_anime.h. Short "CLOSED" lines were appended to the DD08, DEE8, 1183C, 11F28 and 12164 notes.

## Manifests
`manifest --verify` was run for pkt_0204BE38, pkt_0204C2C8, pkt_0204DD08, pkt_0201183C and pkt_02011F28; every entry is EXACT or EXACT*.
