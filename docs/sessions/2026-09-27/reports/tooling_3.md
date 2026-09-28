# tooling_3: ovstats code_end, determinism, soft-float names

## 1. Entries past code_end

disasm.py has no code range: "classified N bytes code" counts CODE bytes over the whole span (disasm.py line 976), interleaved with data. ovstats.py read it as a range (`code_end = base + N`). Instruction bytes in every listing sum to its header count exactly. Instructions sit past base+N in 178 of 237 overlays (425948 bytes).

Rows past base+N: 646 symbols_sdk (110476 B), 282 src/matched (173928 B), 13 src/pending (6478 B), 0 function_starts. 66 of them start at bytes the listing classifies as data.

Proposed rule (not applied, figure-moving): a function's bytes are the CODE bytes in [start, next boundary). Measured effect: SDK 473226 -> 514240 and game 1902770 -> 1861756. Matched game bytes drop to 143818 (7.7%). Today's extents include pools and trailing data: 91 matched functions are an overlay's last label and run to span end (ov021 0x021D3554: 45484 B, 64 of them code). 309 matched game functions start at data-classified bytes (15918 B), and are absent from the denominator.

## 2. Determinism

Shards are now read in sorted order and keyed by their own address: an address matches if any of its entries is EXACT or EXACT\*, and bytes are a disjoint union. Three runs identical. Same tree:

| | before | after |
|---|---|---|
| game matched | 379056 B, 5416 fn | 382558 B, 5771 fn |
| SDK matched | 82520 B, 745 fn | 110146 B, 947 fn |

Gain: 565 entries whose names never resolved to a listing label (static SDK names, unlabelled addresses). The .inst regex fix moves nothing.

## 3. Soft float

0x0209C95C adds magnitudes on equal signs (`adds`, 0x0209C9B4) and is the add; 0x0209CB8C is the subtract (`subs`, 0x0209CBE8). Swapped in runtime_arm9.txt, the note, fsub_fadd.c and its shard. Fixed func_02011B8C (`h += 360.0f`), func_0202BFF0 (`_fsub`), func_0204CC6C (+/-0.5f rounding). All EXACT. Idiom doc corrected.
