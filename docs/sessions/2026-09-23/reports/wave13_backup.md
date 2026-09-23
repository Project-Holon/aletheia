# Wave 13: backup_system / areaman / key lane

Result: **2 EXACT**, both in key.c. The other four targets are still DIFF. Two of them moved: 0x0203422C and 0x020343C0 are now size-exact.

| addr | size | ISA / cc | verdict | where filed |
| --- | --- | --- | --- | --- |
| 0x020360B8 | 412 (the worklist's "68" is only the tail past a stale label; the function runs 0x020360B8..0x02036254) | ARM / 1.1p1 | **EXACT** | src/matched/func_020360B8.c, packet pkt_020360B8 |
| 0x02035F38 | 368 | ARM / 1.1p1 | **EXACT** | src/matched/func_02035F38.c, packet pkt_02035F38 |
| 0x0203335C | 156 | ARM / 1.1p1 | DIFF 21 (unchanged) | docs/notes/sub_0203335C.c.txt (appended) |
| 0x02031FE0 | 1704 incl. pool | ARM / 1.1p1 | DIFF 9 (unchanged) | docs/notes/pkt_02031FE0.c.txt (appended) |
| 0x0203422C | 204 | ARM / 1.1p1 | DIFF 17, **now size-exact** (was 196/204) | docs/notes/pkt_0203422C.c.txt (appended, best source) |
| 0x020343C0 | 260 | ARM / 1.1p1 | DIFF 44, **now size-exact** with the right prologue (was 256/260) | docs/notes/sub_020343C0.c.txt (appended, best source) |

Manifest gates, both passed:
- `python3 tools/match.py manifest --verify --shard pkt_020360B8` -> 1 entry, EXACT
- `python3 tools/match.py manifest --verify --shard pkt_02035F38` -> 1 entry, EXACT

## Family headers
- docs/families/areaman.h (new): struct AreaMan, the five mask and run-length tables, and the prototypes of all 17 matched functions plus the 2 open ones.
- docs/families/key.h (new): struct Key (0x4C bytes), the context object, the remap record, the SDK PAD inlines, and prototypes.
- Both files were written this session. Integrator commit ca2b4ae ("wave 13 first set") already picked them up while this lane was running.

## What closed each one
- **0x020360B8 (key.c remap walk).** The case-2 accumulator has to be a fresh `u32 v = 0;` for each state word. That can be a per-word inline helper or a block-scoped local.
  - The old source kept three function-scope zeros a/b/c and copied them into one v. Every instruction matched, but 0xFFFF and the temporaries rotated through r4/r5/r6/lr (127 bytes out).
  - With three separate zeros, the optimiser hoists them into r3/r2/r1 and 0xFFFF lands in lr.
  - The wave-6 fix (`*f &= mask; *f |= v;` as two statements, not one merge) is still required.
- **0x02035F38 (per-frame pad update).** It matched on the first transcription, using the NitroSDK `PAD_DetectFold` / `PAD_Read` inline shapes (SDK library shapes only).
  - The 0x2FFF mask is not its own pool word. It is the 0x02FFFFA8 pool word shifted right by 12.
  - Both hardware addresses are cast constants.
  - The frame-parity test is a signed `% 2` on a u8 byte.

## Levers found on the open ones
- **0x0203422C.** Two callee prototypes were wrong in the old note. The matched siblings show:
  - `func_02034394(u8 *q, u32 start, u32 len)` takes three arguments; the len in r2 is a real argument.
  - The function and `func_020344C8` both return void.
  - With those fixes and `(u8)~mask` on both clears, it is size-exact. The permuter's temp mutation then took it from 31 to 17.
  - The remaining 17 bytes are an idx/counter/zero rotation in the fill loop.
- **0x020343C0.**
  - Spell the pointer from the parameter: `q = &p->bits[start / 8]`, with idx computed before the if. This gives push {r4, lr} and 260 bytes.
  - Write `tail = 0;` before `nfull = 0;` in the then-arm (71 -> 44).
  - The remaining 44 bytes are the else-arm schedule plus an idx/nfull/tail rotation.
- **0x02031FE0.** The allocator's real prototype (u16 tag) with an explicit `(u16)heap` cast is also 9 bytes out; adopt it when this closes.
  - No change moved the B / A+B swap: web or variable sharing, pointer spellings, inline helpers, or parameter shapes.
  - Permuter runs: a focused anneal (500) and a full anneal (3500) both stayed at 9.
- **0x0203335C.** No change moved it:
  - a type grid of 16 combinations by 3 positions of `i++`;
  - rewrites of the swap and the mask;
  - a permuter hill under ../2.0/sp2.
  - It stays at 21 on every front end.

## Permuter best lines
| addr | run | result |
| --- | --- | --- |
| 0x0203335C | hill, ../2.0/sp2, --types, budget 800 | asm=105, 21 out |
| 0x02031FE0 | anneal, --types, budget 3500 | asm=45, 9 out |
| 0x0203422C | hill, --types, budget 800 | asm=85, 17 out |
| 0x0203422C | anneal, --types, budget 2500 | asm=70, 17 out |
| 0x020343C0 | hill, --types, budget 800 | asm=525, 44 out |
| 0x020343C0 | anneal, --types, budget 1400 | asm=525, 44 out |

## Integrator: seed
- Stale label: layout/worklist.json cuts pkt_020360B8 as "68 code bytes" (404 extent). match.py show and the EXACT compile both say 0x020360B8 is one 412-byte function ending in the 0x0000FFFF pool word at 0x02036250. It looks like a stale interior function start near 0x020360FC; please re-check function_starts for that range.
- No unlabelled leaves were found as witnesses.

## Nothing touched outside the write set
- Only the files above changed: two src/matched files, two shards written by manifest --verify, five appended notes and two family headers.
- Nothing is committed.
- The untracked src/matched files for other addresses belong to other lanes.
