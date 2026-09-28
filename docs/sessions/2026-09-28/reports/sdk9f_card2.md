# sdk9f_card2 report (libcard, arm9 SDK rows)

All work comes from `tools/sdkobj.py`, `match.py one`, and the ELF symbol and section tables of the
vendor members already extracted to `scratchpad/sdk9w3_card/` (card_backup.o, card_rom.o). No `.c` or
`.h` under `sdk/` was opened. No asm statements, no asm mode, no pragmas. No git writes. No permuter
runs (seeds 14301 to 14399 unused).

## Result

| address | symbol | bytes | verdict |
|---|---|---|---|
| 0x02076540 | CARDi_RequestStreamCommandCore (card_backup.o, static) | 408 | EXACT (was DIFF 21), filed |
| 0x02076E4C | CARDi_ReadRomWithCPU (card_rom.o) | 284 | EXACT (was DIFF 165, 280/284), filed |

Status is copied from `manifest --verify --force --shard`. The first pass wrote each shard, and the
second pass (forced) and a third (plain) both rewrote 0.

## Files and shards

- `src/matched/arm9_sdk/func_02076540.c` (new; continues this session's draft)
- `src/matched/arm9_sdk/func_02076E4C.c` (new; continues this session's draft)
- `layout/matched/arm9/pkt_02076540.json` (new shard, one entry, EXACT)
- `layout/matched/arm9/pkt_02076E4C.json` (new shard, one entry, EXACT)
- Deleted: `src/pending/arm9_sdk/CARDi_RequestStreamCommandCore.c`, `src/pending/arm9_sdk/func_02076E4C.c`
- Scratch: `scratchpad/sdk9f_card2/`

## What closed both: the buffer's 32-byte alignment

Both buffers are file-local statics in `.bss` sections whose `sh_addralign` is 32:

- card_backup.o: `CARDi_backup_cache_page_buf` is STB_LOCAL, 256 bytes, alone in a `.bss` section with align 32.
- card_rom.o: `CARDi_cache_buf` is STB_LOCAL, 512 bytes, alone in a `.bss` section with align 32
  (every other card_rom.o `.bss` object has align 4).

Declaring that alignment, `extern u8 CARDi_backup_cache_page_buf[256] __attribute__((aligned(32)));`
and `extern u8 CARDi_cache_buf[512] __attribute__((aligned(32)));`, changes nothing else in either
body:

- 0x02076540: the hoisted buffer address now takes r4, then req_type r5, req_mode r6 and size r7, which is
  the image's permutation. It verifies EXACT with const or non-const req_type/req_mode/retry_count
  in DWARF order (reversed printout: req_type, req_mode, retry_count, size, block-scope len). The filed
  version uses plain non-const locals. `static u8 ...[256] __attribute__((aligned(32)))` is EXACT too,
  but `static` without the alignment stays at 21, so the lever is the alignment, not the linkage. The
  extern spelling was kept so the file defines no data.
- 0x02076E4C: with the alignment, plain `while (length > 0)` is EXACT: the `mov r0,r7; cmp r8,r0`
  copy and the r1 to r3 poll-loop colouring both come out right. The earlier ternary loop condition and
  `#pragma unused(userdata)` were removed. The pragma was not needed, and the ternary with the
  alignment is 80 bytes out.

This explains why earlier passes saw asm mode or `opt_loop_invariants off` close both rows. They were
changing how the address of an array is treated, not the source shape.

## Leads tried first (no effect)

- Coordinator lead 1 (DWARF order): `sdkobj.py` prints `len, size, retry_count, req_mode, req_type`.
  Reversing that gives the draft's existing order. The literal reading (function-scope `len` first, then
  size, retry, mode, type), with bare or initialised declarations and all six assignment orders,
  went from 21 to 32-35 bytes.
- Coordinator lead 2 (const): the sweep covered 64 combinations of const on the parameter `p`, const on
  `len`, const on type, mode and retry, and size-first ordering. Nothing went below the known 12 (size
  first) or 21.
- `x = x;` self-assignments of each local and of `p`, at four points, left the result flat.
- `&buf[0]` versus plain `buf` at each of the six buffer uses (64 combinations): all 21.
- Loop shape (for(;;) with break, while(1), and goto with returns): 21 to 29 bytes.

## Catalog / DWARF names

No disagreements.

## asm bodies

None.

## For the idiom index / other lanes

One candidate idiom: when a register permutation or a missing copy involves the address of a static
array, check the defining object's section alignment (`sh_addralign`) and declare it with
`__attribute__((aligned(N)))`. Alignment 32 is the SDK's `ATTRIBUTE_ALIGN(32)` cache-line buffers. The
evidence is in the object's section table, so this is not a pragma. The declaration changes how mwcc
treats the array's address (hoisting and propagation), not only the data layout. Any other open row
that uses a 32-aligned SDK buffer and shows an "asm mode closes it" note should be rechecked.

## Next pass

Nothing left in this territory.
