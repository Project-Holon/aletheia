# Lane T3 - ov009 open SDK rows 16-23

Slice: `python scratch/a2/open_rows.py ov009 16 8`. 8 rows, 1,800 bytes of image.
Filed 3 (648 bytes). Parked 5 with a named, measured residue.

## Filed (src/matched/ov_sdk/, shard written through the harness)

| # | address | bytes | name | verdict | lever |
|---|---|---|---|---|---|
| 16 | 0x0219B73C | 192 | get_sockaddrin (qr2.o) | EXACT | body shape |
| 18 | 0x02181C2C | 228 | gsXmlCreateStreamReader | EXACT | wrong data symbol |
| 19 | 0x021A153C | 228 | ProcessIncomingData | EXACT | condition polarity |

- **0x0219B73C** — the parked body cleared the struct with a byte loop; the image keeps SIX
  individual `strb`s (offsets 2..7, in that order, with the port-swap `orr` scheduled into the
  middle) plus `len` and the family byte afterwards. Six separate statements through an
  `unsigned char *` reproduce it; a loop (CW leaves it rolled) and `memset` (a call) both miss.
  Pin/flag sweep was run first and failed (best 77 diffs at `-O4,p`; 24 cells), so the lever was
  body shape, not the pin.
- **0x02181C2C** — both failure paths report through the SAME diagnostic string `g_021A3EA8`; the
  parked source used `g_021A3E74` for the element-array failure. Using the shared string fixes the
  literal-pool order (`g_021A3E74, gsiXmlUtilElementFree, g_021A3EA8, gsiXmlUtilAttributeFree`) and
  with it every PC-relative pool offset. Was 9 concrete bytes, now 0.
- **0x021A153C** — the decrypt guard is an OR, not an AND. The image does
  `cmp r1,#2 / beq <decrypt>`: `state == 2` jumps STRAIGHT INTO the decrypt block, and only the
  not-2 path falls through to the `crypt <= 0` skip. Source is `slist->state == 2 || slist->crypt > 0`;
  the parked nested `if (state != 2) if (crypt > 0)` if-converts to `ldrne/cmpne` and compiles 8 bytes
  short. Was 104 concrete bytes, now 0.

## Parked (src/pending/ov_sdk/, residue in each header)

| # | address | bytes | name | compiled | class | first differing instruction |
|---|---|---|---|---|---|---|
| 17 | 0x02195278 | 200 | gti2SendFilterCallback | 200 | size-exact | +0024 image `cmp r0, #0` \| ours `movs r2, r0` |
| 20 | 0x02182554 | 232 | gsiXmlUtilParseString | 224 | structure -8 | +0050 image `ldr r3, [r6]` \| ours `ldr r2, [r6]` |
| 21 | 0x0219FE44 | 236 | SetupListChallenge | 236 | size-exact | +007C image `eor r0, r0, r2` \| ours `eor r0, r2, r0` |
| 22 | 0x02176164 | 240 | DWCi_NodeInfoList_RemoveAID | 236 | structure -4 | +0080 image `bge #0x217623c` \| ours `bge #0x2176238` |
| 23 | 0x02176CF8 | 244 | DWCi_InsertReliableQueue | 236 | structure -8 | +0004 image `ldr r3, [pc, #0xe0]` \| ours `ldr r6, [pc, #0xdc]` |

Measured evidence per row is in the `residue (lane T3, 2026-09-30, measured)` line of each parked
header. Summary of the levers that were spent:

- **Pin/flag sweep** (`match.py sweep`, 9 compiler dirs x 7 flag sets = 63 cells) on all five:
  - 0x0219FE44  best `1.1p1 -O4,p` = 4 diffs; every other cell 176-251.
  - 0x02195278  best 38 diffs; `-O2/-O3` also 38; `-O1` 164; `-O0` 225.
  - 0x02176CF8  best `-O4,p` 188 diffs (that is the current state); `-O4,s/-O4` are 90 -> worse.
  - 0x02182554  best 78 diffs at `-O4,p`; every other flag 101-239.
  - 0x0219B73C  best 77 at `-O4,p`, then used a body change.
- **Body shapes** where budget allowed:
  - 0x0219FE44 three shapes (flat left-assoc chain 38 diffs; named a/b/c/d/e left-nested tree 4
    diffs, byte-identical to the committed spelling; three sequential compound assignments 40
    diffs). CW canonicalises the XOR tree, so the operand/destination order of the last two `eor`s
    is a register-allocation decision the source cannot reach.
  - 0x02195278 three shapes (assignment-inside-if 38; `void *` + cast 38; function-pointer value 63).
    The callback pointer lands in r2 rather than r0 and every temporary follows it.
  - 0x02176164 two shapes (copy through a member at offset 0x54 of a 0x28-stride node, 236 B;
    `(i-1)` respell, 244 B with a worse prologue). The image keeps the first `func_02175F3C()`
    result raw (`mov r7, r0`) and emits both `mla`s after the second call; ours folds the first
    `mla` immediately. Loop induction-variable scheduling.

## Notes for the next lane

- 0x0219FE44 and 0x02195278 are 4- and 38-byte register-allocation rows on a size-exact body: the
  pin sweep and the tree spellings are both spent, so treat them as capped unless a lever outside
  `match.py` (a different allocator root, an inline/ipa variant) appears.
- 0x02182554 and 0x02176CF8 were not re-spelled at all (budget); both keep the full parked body and
  their residue lines carry the first divergence, so a fresh lane can start from the diff.
- 0x02176164 is the cheapest remaining: it is 4 bytes and needs only the scheduling of the two
  `func_02175F3C` calls in the shift-down loop to move.
