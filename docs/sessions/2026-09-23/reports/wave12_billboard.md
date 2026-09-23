# Wave 12: billboard.c and billboard_act.c

**Result: 8 functions filed EXACT (7 EXACT, 1 EXACT*), 4,540 bytes.** One DIFF is left in the two families (func_0204EEC8, 58 bytes). One worklist row is an artifact. Nothing was committed.

## Filed in src/matched

| address | function | bytes | verdict | packet | what closed it |
|---|---|---|---|---|---|
| 0x0204F044 | func_0204F044 | 200 | EXACT | pkt_0204F044 | Size fields written `(u32)(f20 << 16) >> 13`, the spelling the sibling func_0204EE64 uses. `(u32)(u16)f20 << 3` gives the same instructions but a different allocation (the old 52-byte "coin flip"). |
| 0x0204F428 | func_0204F428 | 384 | EXACT | pkt_0204F428 | Plain bitfield assignments on Elem (14/2 at +0, and 5/4/1/1/1/4 at +0x18), through `b->ptr1[i]`. |
| 0x0204F7DC | func_0204F7DC | 1720 | EXACT | pkt_0204F7DC | Written from scratch as the draw pass: camera look-at, 4 rotation matrices, lights, one textured quad per element. Uses the NitroSDK G3 immediate inlines copied from sdk/TwlSDK/include/nitro/gx/g3imm.h. The levers are in the file header. |
| 0x0204FFFC | func_0204FFFC | 132 | EXACT* | pkt_0204FFFC | func_0204F5A8 takes (board, entry word). The r1 "destination register" residue was that second argument. |
| 0x02050278 | func_02050278 | 140 | EXACT | pkt_02050278 | func_0204F150 takes (board, id), and plain `o->f0C[first + i]` subscripts. |
| 0x02050340 | func_02050340 | 296 | EXACT | pkt_02050340 | No prior source; written fresh. A **const** descriptor array took it from 62 bytes to 15. The element id is kept in a local. Locals are at function scope in the order p, e, idx, i, r. |
| 0x02050468 | func_02050468 | 112 | EXACT | pkt_02050340 | Plain `o->f18[first + i]` in a for loop, with no stride local. |
| 0x020500F0 | func_020500F0 | 328 | EXACT | pkt_020500F0 | The request array is **const**. That was the whole "scheduling wall" the permuter could not move. |

The following manifest checks passed, each with its entries at the verdicts above:
- `manifest --verify --shard pkt_0204F044`
- `manifest --verify --shard pkt_0204F428`
- `manifest --verify --shard pkt_0204F7DC`
- `manifest --verify --shard pkt_0204FFFC`
- `manifest --verify --shard pkt_02050278`
- `manifest --verify --shard pkt_02050340`
- `manifest --verify --shard pkt_020500F0`

In pkt_02050340, 4 older entries are still not EXACT. I did not touch them.

All of these are ARM and compiled with 1.1p1. I tried ../2.0/sp2 on every residue and it was always worse (for example 85 against 58 on EEC8, and 1456 against 69 on F7DC).

## Not closed

- **0x0204EEC8 (144 bytes): DIFF, 64 → 58 bytes.** All 5 relocations resolve (sole-ref).
  - **What changed:** writing the divisions as explicit `_s32_div_f(...)` calls reproduces the image's reload of f09 after the first call, and the whole tail after that call now matches.
  - **Store order:** I compiled all 240 orders of the seven stores that keep f04 first. The floor with correct pool order is 58, at the order `f04 f06 f09 f14 f18 f1c f08`.
  - **Tables:** the two parameter tables can be one table of {S, T} pairs; it compiles to the same bytes.
  - **Permuter:** hill 800 and anneal 2000 are both flat, with best `DIFF asm=1015 bytes-out=58 size=144/144`.
  - **What is left:** only the prologue schedule and register choice.
  - The section is appended to docs/notes/pkt_0204EEC8.c.txt with the best source.
- **0x020507A4 is an artifact row.** It is func_020507A0, already EXACT (billboard_act.h says so).

## Lessons (added to the family headers)

1. **Write the natural source first.** Every closure this wave was the plain C: bitfields, `x[first + i]` subscripts, a local for a call result. The old hand-built byte-offset, stride-local and mask spellings were what held these functions at their DIFF residues.
2. **`const` on a read-only input array.** It lets field loads move above the stores into the output arrays and the outgoing-argument stores. That was the batched-load schedule in 020500F0 and 02050340.
3. **Check the callee's real arity.** For both func_0204F150 and func_0204F5A8, the value "leftover" in r1 is a real second argument.
4. **In a large function, spill slots follow declaration order.** A separate counter for a second loop moves which slot the first loop's counter gets (this was the last 12 bytes of F7DC).

## Integrator: seed

- **0x02050080, ARM, 8 bytes:** `void *f(struct BbActSys *o) { return o->f04; }` (`ldr r0,[r0,#4]; bx lr`). It is blx'd from ov021 at 0x02188EFE, 0x02188F3C, 0x021891EC, 0x0219C4C8 and 0x0219C53A, and it compiles EXACT. The source is below; I did not file it.
  - `layout/function_starts.txt` line 364 seeds **0x02050084**, which is only this getter's `bx lr`. src/matched/func_02050084.c ("empty leaf") matches that lone instruction.
  - That row should move to 0x02050080 and func_02050084 should be retired or replaced.
  - This getter is why func_0204FFFC is EXACT* and not EXACT.

```c
struct BbActSys { unsigned short f00, f02; void *f04; };
void *func_02050080(struct BbActSys *o) { return o->f04; }
```

## Files

- **New:**
  - src/matched/func_0204F044.c
  - src/matched/func_0204F428.c
  - src/matched/func_0204F7DC.c
  - src/matched/func_0204FFFC.c
  - src/matched/func_02050278.c
  - src/matched/func_02050340.c
  - src/matched/func_02050468.c
  - src/matched/func_020500F0.c
- **Shards:**
  - Created: layout/matched/arm9/pkt_0204F044.json, pkt_0204F428.json, pkt_0204F7DC.json, pkt_0204FFFC.json, pkt_02050278.json, pkt_020500F0.json
  - Updated: pkt_02050340.json
- **Notes:**
  - DIFF section appended to docs/notes/pkt_0204EEC8.c.txt.
  - Short closure sections appended to pkt_0204F044, pkt_0204F428, pkt_0204F7DC, func_02050278, pkt_02050340, pkt_020500F0 and func_020500F0.
- **Headers:** docs/families/billboard.h and docs/families/billboard_act.h.
  - Updated prototypes and statuses.
  - Slot +0x0c..+0x1c are texture address, palette address, format, S size and T size.
  - Board blob fields are named. +0x36 and +0x38 are s16 (read with ldrsh).
  - The names of the Elem +0x18 bitfields.
  - The BbActDesc and BbActRec layouts.
  - The const and subscript notes, and the 0x02050080 finding.
- **Cleanup:** during F7DC filing, an unquoted heredoc created two empty files, `offS` and `scale`, in the repo root. I deleted them.
