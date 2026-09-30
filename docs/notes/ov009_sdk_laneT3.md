# Lane T3 - ov009 open SDK rows 16-23

Slice: `python scratch/a2/open_rows.py ov009 16 8`. 8 rows, 1,800 bytes of image code.
**6 of 8 filed EXACT (1,324 bytes).** 2 parked with a named, measured residue.

Every row was worked by reading the diff by byte offset and re-spelling the body against the
idiom index (`docs/idioms/`). No row was closed by a compiler swap; the pin/flag axis was swept
once, reported, and then dropped as dead per project policy.

## Filed (src/matched/ov_sdk/, shard written through the harness)

| # | address | bytes | name | lever |
|---|---|---|---|---|
| 16 | 0x0219B73C | 192 | get_sockaddrin (qr2.o) | six explicit byte stores, not a loop |
| 18 | 0x02181C2C | 228 | gsXmlCreateStreamReader | both failure paths share one string |
| 19 | 0x021A153C | 228 | ProcessIncomingData | decrypt guard is OR, not AND |
| 20 | 0x02182554 | 232 | gsiXmlUtilParseString | doubled loop guard + store position |
| 22 | 0x02176164 | 240 | DWCi_NodeInfoList_RemoveAID | two raw call results, arithmetic deferred |
| 23 | 0x02176CF8 | 244 | DWCi_InsertReliableQueue | second extern name for one address |

- **0x0219B73C** - the parked body cleared the struct with a byte loop; the image keeps SIX
  individual `strb`s (offsets 2..7, in that order, with the port-swap `orr` scheduled into the
  middle) plus `len` and the family byte afterwards. Six separate statements through an
  `unsigned char *` reproduce it; a loop (CW leaves it rolled) and `memset` (a call) both miss.
- **0x02181C2C** - both failure paths report through the SAME diagnostic string `g_021A3EA8`; the
  parked source used `g_021A3E74` for the element-array failure. The shared literal fixes the
  literal-pool order (`g_021A3E74, gsiXmlUtilElementFree, g_021A3EA8, gsiXmlUtilAttributeFree`)
  and with it every PC-relative pool offset. Was 9 concrete bytes, now 0.
- **0x021A153C** - the decrypt guard is an OR, not an AND. The image does
  `cmp r1,#2 / beq <decrypt>`: `state == 2` jumps STRAIGHT INTO the decrypt block and only the
  not-2 path falls through to the `crypt <= 0` skip. Source is `slist->state == 2 || slist->crypt > 0`;
  the parked nested `if (state != 2) if (crypt > 0)` if-converts to `ldrne/cmpne` and is 8 bytes
  short. Was 104 concrete bytes, now 0.
- **0x02182554** - two levers, both from `docs/idioms/`. (a)
  `a-doubled-loop-entry-guard-is-an-explicit-if-around-the-for`: the image tests
  `buffer[*pos] != startCh` twice (`bne` into the scan loop at +0068, same-flags `beq` out of it at
  +0084), so the source has the loop test written as an explicit `if` in front of the `while`.
  Adds the missing 8 bytes (224 -> 232). (b) taking `strStart = &buffer[*pos]` BEFORE
  `strOut->length = 0` keeps the `(*pos)++` register live and makes the length/quote tests re-read
  `*pos` into a fresh register (`ldr r3, [r6]`) instead of through the computed pointer; that is the
  last 7 register-field bytes.
- **0x02176164** - `docs/idioms/a-store-that-lands-after-the-next-call-names-a-local-temporary`:
  two raw `char *` locals hold the two `func_02175F3C()` results and the index arithmetic is
  deferred to after both calls. That is what makes the image keep the first result raw in r7
  (`mov r7, r0`) and emit both `mla`s after the second call; folding the arithmetic into the first
  call site loses the 4 bytes. Was 66 concrete bytes in 236 B, now 240 B EXACT.
- **0x02176CF8** - `docs/idioms/a-duplicated-pool-word-is-a-second-extern-name-for-the-same-address`:
  the image carries TWO pool words for the queue info (r3 for the count/head reads, r6 for the
  `target` cursor). mwccarm emits one pool word per (symbol, addend), so two words for one address
  means the source reached it through two names. Declaring `g_021AB178_head 0x021AB178 data` and
  using it for `target = &g_021AB178_head` closes the whole 188-byte diff in one step.

## Parked (src/pending/ov_sdk/, residue in each header)

| # | address | bytes | name | compiled | class | first differing instruction |
|---|---|---|---|---|---|---|
| 17 | 0x02195278 | 200 | gti2SendFilterCallback | 200 | size-exact | +0024 image `cmp r0, #0` \| ours `movs r2, r0` |
| 21 | 0x0219FE44 | 236 | SetupListChallenge | 236 | size-exact | +007C image `eor r0, r0, r2` \| ours `eor r0, r2, r0` |

Both are size-exact rows whose first divergence is a register-field-only difference, and both are
on the allocator axis that this project has already measured shut. Twelve and ten additional
spellings respectively (trees, named locals, block placement) all land on the same bytes or worse;
the per-spelling numbers are in each header's `extra (lane T3, second pass)` line.

- **0x02195278**: the callback pointer's home register is r0 in the image and r2 in ours, so the
  image's increment temporaries start at r1/r2/r3 and ours at r0/r1. Nothing in the statement
  shape moves it: assignment-in-if 38, negated form 38, `void *`+cast 38, hoisted list local 38,
  hoisted `connection->8` local 38, body-inside-the-if 121.
- **0x0219FE44**: the last two `eor`s have their operands swapped - the image's accumulator is the
  Rn slot. Ten more trees tried, best 33 diffs against the committed 4: left-nested 38,
  `D^E^C^B^A` 38, `(D^E)^(C^(B^E))` 43, `(D^E)^((C^B)^A)` 39, `((D^E)^(C^B))^A` 35,
  `(C^(D^E))^(B^A)` 44, `A^(B^C^D^E)` 33. CW canonicalises the XOR tree, so the source cannot
  reach the operand order.

## Notes for the next lane

- Both residuals are final unless a lever outside `match.py` appears (a different allocator root,
  an inline/ipa variant). Everything reachable from the C source has been spent.
- The idiom index is where the yield came from on this slice: three of the six closes came from a
  named idiom (`a-doubled-loop-entry-guard-...`, `a-store-that-lands-after-the-next-call-...`,
  `a-duplicated-pool-word-...`). Read `docs/idioms/` before re-spelling anything.
