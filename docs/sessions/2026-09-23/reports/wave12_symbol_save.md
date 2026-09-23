# Wave 12: symbol_save.c / app_taskmenu.c / game_data.c

**Result: 10 EXACT/EXACT\* filed.** That is 9 of the targets plus 1 witness leaf. Nothing was committed.

Every closure came from a declaration fact or from a wrong reading of the image. None of them was an allocator tie.

## 1. symbol_save.c (0x0200E2BC..0x0200F6B8)
| addr | verdict | file | what closed it |
|---|---|---|---|
| 0x0200EBD0 | EXACT* | src/matched/func_0200EBD0.c (pkt_0200EA3C) | The callee func_0200EA3C takes 4 args, and EBD0 forwards its r1..r3 (obj, a1, date, heap). The index cannot take r1, so it lands in r6. After that fix, the permuter hill closed the rest with `expand(idx)` (the index read inline in the call arg). |
| 0x0200EA3C | EXACT* | src/matched/func_0200EA3C.c (pkt_0200EA3C) | Written from scratch (402 B). It snapshots the party into six 0x3c-byte entries and puts the RTC date at +0x168. The one needed lever: `i = 0` after the memset and before `n = 0` (stack slots). |
| 0x0200F43C | EXACT* | src/matched/func_0200F43C.c (pkt_0200F43C) | The friend key is ONE `u64` (DWC_CheckFriendKey/CreateFriendKeyToken). The array is a 12-byte DWCFriendData type indexed `arr[i]`. Both profile lookups stay per-iteration, which is semantically faithful. |
| 0x0200E7BC | EXACT* | src/matched/func_0200E7BC.c (pkt_0200E7BC) | The note's struct had a stray `pad1a`, which put every field from +0x1a on one byte off. Each field is also written as `o[idx].field`. |

Group A (E3A4, E3E8, E488, F17C, F234, F698) was re-verified and is unchanged: MATCH at the overlay wall. It was skipped as instructed.

## 2. app_taskmenu.c (0x02027778..0x02028590)
| addr | verdict | file | what closed it |
|---|---|---|---|
| 0x02027F60 | EXACT | src/matched/func_02027F60.c (pkt_02027F60) | func_020275E4()'s result is argument 1 of func_02049DB4/func_02049B40. The calls are `(h,0x20,0,&r->f04,heap)` and `(h,0x1f,sel,a1<<5,0x40,heap)`. `&heap` is not needed. |
| 0x02027778 | EXACT | src/matched/func_02027778.c (pkt_02027778) | Template parameter made non-const, so the +0x12 load is no longer hoisted above the stores. Promoted from src/pending (the pending file was deleted; the deletion is unstaged). |
| 0x02027BF4 | EXACT | src/matched/func_02027BF4.c (pkt_02027BF4) | The `mode` parameter is `u16`. It was found inside an 11-mutation permuter anneal result and reduced by hand to that single change. |
| 0x02027D44 | EXACT | src/matched/func_02027D44.c (pkt_02027D44) | Up/down play 0x548, not 0x54C (pool order 548/551/54C); this took it from 84 to 16 bytes out. In the B arm the cursor store comes before `m->f0C = 1`. The permuter never moves one store past another, so hill and anneal both stayed at 16. |

## 3. game_data.c (0x020124F4..0x02013080)
| addr | verdict | file | notes |
|---|---|---|---|
| 0x02012BC8 | EXACT | src/matched/func_02012BC8.c (pkt_02012BC8) | `func_02008450(*(u32*)(p+0x198), on ? 1 : 0)`. It was MATCH until the witness below was sharded. |
| 0x02008450 | EXACT | src/matched/func_02008450.c (pkt_02012BC8) | Unlabelled bit-10 setter leaf (`p->flag = (u16)on`, `int on`). Filed as a compiled witness; resolves BC8's call via the `matched` class. |

0x020124F4 and 0x02012704 were re-verified and are unchanged: MATCH at the ov009/ov010 overlay wall. No C problem.

## Integrator: seed
- **0x02008450** (thumb): unlabelled leaf, witness filed, and its only reference is the pool word at 0x02012BDC.
- 0x0200EC14 (thumb): unlabelled follower of func_0200EBD0 (the cause of its EXACT\*).
- 0x0200E874, 0x0200E878 (thumb): unlabelled followers of func_0200E7BC (the cause of its EXACT\*).

## Docs updated
- Family headers:
  - symbol_save.h: GROUP B replaced with the closures and the proven prototypes.
  - app_taskmenu.h: wave-12 section added; the constructor is now byte-proven.
  - game_data.h: BC8 and the 0x02008450 witness recorded.
- Notes: a short CLOSED line was appended to func_0200EBD0, pkt_0200EA3C, func_0200F43C, pkt_0200E7BC, func_02027F60, func_02027BF4 and func_02027D44.

## Lessons worth keeping
- Before calling a residue an allocator tie, read the callee's prologue for its arity: EA3C homes r0..r3, and that fixed EBD0.
- Recompute every Thumb `ldr [pc]` pool target: 0x548 had been misread as 0x54C, which cost 68 bytes in D44.
- A `const` pointer parameter lets mwcc hoist loads above stores into other objects. Dropping it pins source order.
- The permuter keeps stores in order relative to each other, so the order of two independent field stores has to be swept by hand.

## Gates
Ran `manifest --verify --shard` on pkt_0200EA3C, pkt_0200F43C, pkt_0200E7BC, pkt_02027F60, pkt_02027778, pkt_02027BF4, pkt_02027D44 and pkt_02012BC8. All entries are EXACT or EXACT\*.
