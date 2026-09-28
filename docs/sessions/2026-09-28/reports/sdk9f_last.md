# sdk9f_last: the last 14 open ARM9 SDK rows

Lane sdk9f_last, 2026-09-28. No .c or .h under `sdk/` was opened. Vendor evidence came from
`tools/sdkobj.py` (its archive reader and ObjView, called from a scratch script because
neither address has a `symbols_sdk.json` row) and `match.py show`.

## Worklist summary

| | before | after |
|---|---|---|
| SDK excluded | 1119 fn, 129800 B | 1119 fn, 129800 B |
| matched SDK | 1105 fn, 127548 B | 1107 fn, 128464 B |
| open SDK rows (cls sdk, no matched_name) | 14 rows, 2252 B | 12 rows, 1336 B |
| game coverage | 100.0000% (400710 / 400710) | unchanged |

The 12 rows still open are the interior labels below. Their bytes are already compared.
Only the worklist accounting misses them.

## Whole functions

| address | vendor symbol (object) | bytes | verdict |
|---|---|---|---|
| 0x0202FB34 | CRYPTO_RC4Encrypt (libcrypto.TWL.HYB.a rc4s-arm4cw.o) | 120 | EXACT (manifest), asm |
| 0x02081E7C | MATHi_SHA1ProcessBlock (libmath.TWL.HYB.a sha1.o), catalog name MATHi_SHA1Transform | 796 | EXACT (manifest), asm |

Evidence for the asm bodies (each file's header has it in one line):

- rc4s-arm4cw.o: the STT_FILE symbol names `rc4s-arm4cw.s`. The object has no `.comment`, no
  DWARF and no relocations. Its only symbol is CRYPTO_RC4Encrypt (NOTYPE, 120 bytes), and its
  `.text` equals the image byte for byte. rc4.o, the object the catalog lane first assumed,
  defines only CRYPTO_RC4Init and CRYPTO_RC4FastInit.
- sha1.o: the STT_FILE symbol names `sha1.s`. The object has no `.comment`, no DWARF and no
  relocations. Its `.text` is 812 bytes: a `$d` block at offset 0 (the four SHA-1 round
  constants 0x5A827999, 0x6ED9EBA1, 0x8F1BBCDC, 0xCA62C1D6), then `$a` at offset 16.
  MATHi_SHA1ProcessBlock has value 16, and its st_size of 812 is the section size. The code is
  796 bytes and equals the image at 0x02081E7C. The constants are the four words at
  0x02081E6C, which the listing shows after the pool of the function before this one. The code
  reads them with `ldr ip, [pc, #-N]`. The body spells those four loads with literal negative
  pc offsets. The original assembler resolved them from a local label, so sha1.o carries no
  relocation for them either. The 16 data bytes are outside the compared range and this entry
  does not claim them.

## Interior labels (12 rows, 1336 B)

| label | parent (vendor object) | parent vendor size | parent shard / entry | compiled and compared |
|---|---|---|---|---|
| 0x02082F48, 0x02082F90, 0x02083028, 0x020830C0 | MI_CpuCopy 0x02082EA4 (mi_memory.o) | 752 | pkt_02082EA4 / MI_CpuCopy, EXACT | 752 B |
| 0x02083250, 0x02083298, 0x02083334, 0x020833D0 | MI_CpuMove 0x02083194 (mi_memory.o) | 788 | pkt_02083194 / MI_CpuMove, EXACT* | 788 B |
| 0x02084F44 | OS_SPrintf 0x02084F40 (os_printf.o) | 40 | pkt_02084F44 / OS_SPrintf, EXACT | 40 B |
| 0x0208CF38 | STD_TSScanf 0x0208CF34 (std_string.o) | 40 | pkt_0208CF34 / "OS_SPrintf", EXACT | 40 B |
| 0x0208D7E4 | STD_TSPrintf 0x0208D7E0 (std_sprintf.o) | 44 | pkt_02087AE4 / STD_TSPrintf, EXACT | 44 B |
| 0x0208D810 | STD_TSNPrintf 0x0208D80C (std_sprintf.o) | 40 | pkt_02087AE4 / "OS_SNPrintf", EXACT | 40 B |

Every label is inside a single vendor symbol whose st_size covers it. None of them is a
separate function, so none gets its own file.

- The four printf labels sit at +4. The vendor function starts with `stmdb sp!, {r0-r3}`
  (0xE92D000F), and disasm.py wrote that word as `.word` data and put the label on the second
  instruction.
- The MI_CpuCopy and MI_CpuMove labels are the interior kernels of the hand-written routines
  (owner decision 2026-09-23).

**How the parent is compared.** `run_one()` in tools/match.py compares the compiled function's
full length at the entry address (`target_bytes(addr, len(fb.data))`). The listing extent
(`target_extent`, label to next label) is used only to add the `*` to EXACT when the two
lengths differ. The extent is not what gets compared. I re-ran `match.py one` on all six
parents, and each compiles to exactly the vendor size (752, 788, 40, 40, 44, 40) and comes
out EXACT or EXACT*. So every interior byte has already been compared against the image. The
interior bytes are not missing from any comparison.

**Why the rows still show open.** In `worklist.py classify()`, the `sdk_interior` branch sets
`matched_name` only from `matched.get(addr)`, which is keyed by the label's own address.
Nothing in a shard maps an interior label back to its parent entry.

**No existing mechanism fits honestly.** The only one that would make worklist count these
labels is a unit header: `unit: yes` plus `function: OS_SPrintf, func_02084F44`. That header
makes a `game_unit` entry whose `functions` list worklist reads, and run_tu compares the same
40 bytes. But match.py `matched_index()` also reads that list. It would then attest
0x02084F44 as a verified function entry point for relocation resolution (attest_matched rule
3), which is false. It would also rename the entry after the file stem and change its kind. I
did not use it, and I did not touch any parent file or shard.

**Minimal tools change (not made; tools are out of this lane's scope).** It is worklist-only
and needs no shard rewrite:

1. In `tools/worklist.py`, add `sdk_interior_parent(extents, addr)`, which returns the
   `(start, end, name)` tuple that `sdk_interior()` already finds.
2. In `classify()`, in the `sdk_interior` branch, after setting `sdk_name`: if `ment is None`
   and `matched.get(start)` is an entry with status EXACT/EXACT* (load_matched already filters
   on that), set `fn["matched_name"] = "%s+0x%X" % (parent["name"], addr - start)` and
   `fn["matched_interior"] = True`.
3. The credit relies on the parent comparison covering `[start, end)`, and the shard does not
   record the compared length. The honest guard is to also record the compared byte count in
   the manifest entry, but only when it runs past the next listing label. That is a small
   `entry_from_source()` addition (`entry["size"] = r.size` when `r.size >
   (r.target_size or r.size)`), so it rewrites only the six parent shards above, not every
   shard. worklist then credits an interior label only when `addr < start + size`.
   Without step 3, the credit rests on the catalog size, and today that equals the compiled
   size for all six parents.

This moves no figure in the game denominator, because the rows are already SDK-excluded. It
moves "matched SDK" from 1107 fn / 128464 B to 1119 fn / 129800 B and closes the ARM9 SDK.
Per the honest-denominator rule, the owner should see it before it lands.

## Files and shards written

- `src/matched/arm9_sdk/func_0202FB34.c` (new). The entry was added to the existing shard
  `layout/matched/arm9/pkt_0202FB34.json`, whose other three entries (unit_0202FBAC,
  sub_020304B8, sub_020304C0) stayed as they were. I ran `manifest --verify --force --shard
  arm9/pkt_0202FB34` twice. The first pass rewrote 1 and the second rewrote 0. Status EXACT,
  kind sdk.
- `src/matched/arm9_sdk/func_02081E7C.c` (new), with the new shard
  `layout/matched/arm9/pkt_02081E7C.json`. I ran `manifest --verify --force --shard
  arm9/pkt_02081E7C` twice. The first pass rewrote 1 and the second rewrote 0. Status EXACT,
  kind sdk. I drafted it in `src/pending/arm9_sdk/func_02081E7C.c` (a new file of mine, not a
  pre-existing one) and moved it to matched once it verified, so no pending file remains.
- `layout/worklist.json` was rewritten by `worklist.py --refresh`, the brief's step, not by
  hand.
- No tools, docs/MATCHING.md or other shard was edited. Scratch is in
  `scratchpad/sdk9f_last/`.

## Catalog and name disagreements

- 0x02081E7C: the catalog says MATHi_SHA1Transform in `libdgt.TWL.HYB.a(dgt_sha1.o)`. The
  vendor object is `libmath.TWL.HYB.a(sha1.o)`, and the symbol is MATHi_SHA1ProcessBlock.
  dgt_sha1.o is compiled C (stamp 4.0.0.1024) and does not define this code.
- 0x0202FB34: the catalog object `rc4s-arm4cw.o` is correct. The row has no
  `symbols_sdk.json` entry, so `sdkobj.py 0x0202FB34` reports nothing for it.
- Shard entry names that disagree with the vendor symbol: 0x0208CF34 is filed as `OS_SPrintf`,
  but the vendor symbol is STD_TSScanf and it calls STD_TVSScanf at 0x0208CFD8. 0x0208D80C is
  filed as `OS_SNPrintf`, but the vendor symbol is STD_TSNPrintf. The bytes are EXACT; only the
  name in the file and shard is off.

## Next pass

There are no ARM9 SDK functions left to match. The last 12 rows need the worklist change
above, with owner approval.
