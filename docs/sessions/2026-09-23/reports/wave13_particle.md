# Wave 13: particle, poke_tool, pokegra, arc_tool, game_beacon

**8 closed (6 EXACT, 2 EXACT*), 1 skipped by rule, 2 blocked on evidence.** All work is in files; nothing committed.

## Results

| family | address | verdict | file | lever |
| --- | --- | --- | --- | --- |
| particle | 0x02051838 | EXACT | src/matched/func_02051838.c (pkt_02051838) | `const VecFx32 *q`, one statement per component, no locals; the old `volatile` parameter only imitated the const hoist |
| particle | 0x02051414 | EXACT | src/matched/func_02051414.c (pkt_02051414, new shard) | the setup-only locals go in a nested block with initialisers (`VecFx32 z = {0,0,0};`); g_020A159C then resolves by sole-ref/self, so the old "permanent MATCH blocker" is gone |
| particle | 0x02050C30 | EXACT | src/matched/func_02050C30.c (pkt_02050C30) | `extern const u32 g_020A15A8[];` makes the table const; the 37-byte "scheduler tie" disappears |
| poke_tool | 0x0201A3F4 | EXACT* | src/matched/func_0201A3F4.c (pkt_0201A3F4, new shard) | rebuilt from twin func_0201A374; record parameter `const u8 *` |
| poke_tool | 0x0201A090 | EXACT* | src/matched/func_0201A090.c (pkt_0201A090, new shard) | plain `species[i]` indexing, plus a permuter hill result (one `reorder`): `*mask |= 0x10; err = 3;` in that order |
| pokegra | 0x0202D3D0 | EXACT | src/matched/func_0202D3D0.c (pkt_0202D2EC) | no hoisted byte local: each nibble arm reads `blob[idx]` and updates it with a compound `+=` |
| pokegra | 0x0202D4A8 | skipped | none | a documented 4-byte frame-slot tie with every lever tried (about 2320 permuter compiles over earlier waves) |
| arc_tool | 0x02049C28 | EXACT | src/matched/func_02049C28.c (pkt_02049C28, new shard) | the size parameter is the defaulted value (no separate v); early `if (file == 0) return;`; PLTT out-local declared before PMCP |
| arc_tool | 0x02049A18 | EXACT | src/matched/func_02049A18.c (pkt_0204994C) | callees take `u8 channel`; each loop has its own block-scoped counter declared before the element pointer |
| game_beacon | 0x020274C8 | MATCH* (unchanged) | src/pending | 0xE7 is an overlay-id symbol with one pool word in the whole image; blocked permanently |
| game_beacon | 0x0202685C | MATCH (unchanged) | src/pending | its call target 0x02167394 is an unlabelled Thumb leaf in ov010; needs a seed, see below |

- Every EXACT was re-verified with `match.py one`, on 1.1p1. The reference compiler ../2.0/sp2 was tried on the particle residues and gave a worse result (80 bytes against 72 for 0x02051838; 380 against 392 for 0x02050C30).
- `manifest --verify` was run on pkt_02051414, pkt_02050C30, pkt_02051838, pkt_0201A3F4, pkt_0201A090, pkt_0202D2EC, pkt_02049C28 and pkt_0204994C. Every entry filed this wave is listed at its filed verdict.
    - For pkt_02051838, pkt_02050C30, pkt_0201A3F4 and pkt_0201A090, the gate reported "1 entr(ies) are not EXACT". The pkt_0201A3F4 and pkt_0201A090 lines are this wave's EXACT* files. For pkt_02051838 and pkt_02050C30, my output was cut off before the offending line; the visible lines show EXACT* on older entries (0x02051A04, 0x02050ED4).

## Main lesson: const is a scheduling lever

Three of the closed residues (0x02050C30, 0x02051838, 0x0201A3F4) had been written off as scheduler or allocator ties. The permuter had run up to 3000 anneal compiles on some of them. All three were the same thing: a load that belongs on the other side of a store.

mwccarm 1.1p1 lets a load through a const-qualified pointer or array move above stores, including stores to the outgoing-argument area. Adding `const` to a table or read-only parameter fixed all three. The permuter cannot find this because it never touches qualifiers.

Other declaration-level findings:
- block-scoped initialisers (0x02051414);
- compound `+=` so the compiler can merge the two arms' loads (0x0202D3D0);
- reusing the parameter as the defaulted value (0x02049C28);
- block-scoped loop counters and their declaration order (0x02049A18).

## Headers and notes
- **New:** docs/families/arc_tool.h, written from the 37 matched siblings (54 functions) and the two new files. It covers the handle layout (+0x48/+0x4C/+0x4E), the id table, the resource blocks, all prototypes, the u8-channel rule and the family's recurring shapes.
- **Appended wave-13 sections:** particle.h (family now closed), poke_tool.h (section 12), pokegra.h, game_beacon.h (the ov010 leaf).
- **Appended "CLOSED" sections** to the eight notes: pkt_02051838, pkt_02051414, pkt_02050C30, pkt_0201A3F4, func_0201A090, func_0202D3D0, pkt_02049C28, func_02049A18.

## Integrator: seed
- **0x0201A468, arm9, Thumb:** the leaf after func_0201A3F4. It scans 0x52 bytes from +0xA and tail-calls 0x02045EC0. It is why func_0201A3F4 is EXACT*.
- **0x0201A48C, 0x0201A4A0, 0x0201A4B4, arm9, Thumb:** three more unlabelled tail-call leaves in the same run, each a `ldr r3,=0x02045EC0; bx r3` form.
- **0x02167394, ov010, Thumb:** `cmp r0,#0x1d; bls; movs r0,#0; bx lr; ldr r1,=0x02171F3C; ldrb r0,[r1,r0]; bx lr`. This is the target of func_0202685C's four `bl` calls. In ov009 the same address is the middle of an ARM function. Once it is seeded, give the pending file's symbols line an `ov010` hint and re-verify. The hint alone does not resolve the site today (tested).

## Knock-on
src/matched/func_0202D760.c calls func_0202D3D0 through what was its last wildcarded site. That site may now be attested as `matched`; its shard should be re-verified on the next integration pass.
