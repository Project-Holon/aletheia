# w3_tools: overlay `template` class, string.h, overlay SDK stubs

Tooling lane. Owned files: `tools/match.py`, `layout/function_starts.txt`,
`layout/symbols_sdk.json`, `src/matched/arm9_sdk/libc/string.h`. I opened no
`.c`/`.h` under `sdk/`, and I read the vendor objects only through `tools/sdkobj.py`.

## 1. `template` extended to overlays (tools/match.py)

### Overlay scope (same conditions as ARM9)

- `vendor_function(place, region, overlays=False)`: with `overlays=True`, the row
  is looked up in the overlay that the code is compared in (`region` = `ovNNN`, and
  that overlay's image must hold `place`). The overlay is never guessed from the
  address. The cache key now includes the region. Only `vendor_template()` passes
  `overlays=True`, so the `linker` and `.bss` rules stay ARM9-only.
- `attest_template()`: the template's module is the function's own overlay. The
  declared address must be:
  - in that overlay's image;
  - aligned to the template section's alignment;
  - data in that overlay's listing (`in_overlay_data()`).

  The image must hold exactly the S bytes there, and our `@M` must hold the same
  bytes. Uniqueness is checked over the aligned addresses of that overlay.
- `_region_word(reg, addr)` reads a word from a named region. The old
  `_image_word()` returns whichever region holds the address first, which is wrong
  for overlays.

### New prong (b): elimination

This rule is new, and it goes beyond "same conditions". I am flagging it because
it moves figures.

**Case that needed it.** ov114 `dwc_encsession.o` has two byte-identical 17-byte
`hextbl` templates:
- `@16077`, used by ValidateResponse;
- `@16117`, used by CompleteCallback.

The pattern therefore sits at 2 aligned addresses (0x021CE1B8 and 0x021CE1CC), so
uniqueness can never hold.

**Acceptance test.** Accept when every other aligned occurrence is claimed by a
different template, meaning all of these hold:
- a row of the same archive, in the same region, is located with 0 mismatches;
- it relocates (ABS32, addend 0) a local `@K` that has the same bytes;
- that `@K` is in a PROGBITS section without SHF_MERGE;
- the relocation slot is outside the compared range;
- the image word at that slot is the occurrence.

**Basis.** Distinct local objects in non-merge sections take disjoint storage.
So once every other copy is claimed, the remaining copy is the only address `@N`
can have.

**Refused when any of these happens:**
- a claim word is not an occurrence;
- another template claims the declared address;
- two templates claim one address;
- a claim of `@N` itself points elsewhere;
- any occurrence stays unclaimed.

**Witness count.** The class reports `template xK`, where K = occurrences - 1.

### Self-tests (`selftest --quick`: 281 cases, 0 failures; 11 are new `template/ov`)

Positive:
- `@14079` of gstats.o is 16 bytes at 0x021A1A54 (ov009), unique.
- `@13818` of gstats.o is 256 bytes at 0x021A1A64 (ov009), unique.
- (b) `@16077` is at 0x021CE1B8, because 0x021CE1CC is `@16117` at CompleteCallback's slot +0x224.
- (b) `@16117` is at 0x021CE1CC, by the converse elimination.

Negative:
- the ov009 row with no region named (an overlay is never inferred);
- an address 16 bytes off;
- our template bytes differing;
- `@16077` declared at the copy that `@16117` claims;
- (b) with the claiming slot inside the compared range, so the other copy is unclaimed;
- the right row named in the wrong overlay (ov009);
- `vendor_function` without `overlays` returning None for an overlay row, so `linker` and `.bss` stay ARM9-only.

## 2. string.h

I added `void *memset(void *dst, int c, size_t n);` and `size_t strlen(const char *s);`
to `src/matched/arm9_sdk/libc/string.h`, plus a comment line. The only ARM9 file that
includes it is `src/matched/arm9_sdk/func_02059FA8.c`:
`manifest --verify --force --shard arm9/pkt_02059FA8` gives EXACT.

`ov114_func_021C26B8.c` now uses `#include "../arm9_sdk/libc/string.h"` in place of its
`extern unsigned long strlen` line.

## 3. Overlay SDK stubs

### Evidence for each stub

For each stub, both of the following hold:
1. The vendor member's function symbol matches the image at the address with 0
   mismatches. None of the stubs has a relocation inside it.
2. At least one SDK row, located with 0 mismatches, relocates a slot against that
   name, and the image word (ABS32) or the decoded `bl` target (PC24) at the slot is
   that address.

Every relocation I found agrees; none disagrees. Pairs of byte-identical stubs
(ElementFree/AttributeFree, EncryptFunc/DecryptFunc) are named by those relocations,
not by their bytes. In gsxml.o, `gsXmlCloseWriterNoNamespace` (16 B) is dead-stripped:
the 24-byte gap 0x02181E10..0x02181E28 is exactly sections 49..52.

| region | address | vendor symbol (member) | B | witness (located row, reloc -> image) |
|---|---|---|---|---|
| ov009 | 0x02181E10 | gsiXmlUtilElementFree (gsxml.o) | 4 | gsXmlCreateStreamReader +0xD8 ABS32, word 0x02181D04 |
| ov009 | 0x02181E14 | gsiXmlUtilAttributeFree (gsxml.o) | 4 | gsXmlCreateStreamReader +0xE0 ABS32, word 0x02181D0C |
| ov009 | 0x02181E18 | gsXmlWriterGetData (gsxml.o) | 8 | ghiPostXmlStateDoPosting PC24, bl at 0x021C2E24 and 0x021C2EC4 |
| ov009 | 0x02181E20 | gsXmlWriterGetDataLength (gsxml.o) | 8 | 10 PC24 bl sites: ghiPostGetNoFilesContentLength 0x021C2698, ghiPostGetHasFilesContentLength, ghiPostXmlStateDoPosting, ghiPostStateDoPosting |
| ov114 | 0x021C1C88 | ghiEncryptorSslEncryptFunc (ghttpencryption.o) | 8 | ghttpSetRequestEncryptionEngine +0xE0 ABS32, word 0x021C117C |
| ov114 | 0x021C1C90 | ghiEncryptorSslDecryptFunc (ghttpencryption.o) | 8 | ghttpSetRequestEncryptionEngine +0xE4 ABS32, word 0x021C1180 |
| ov114 | 0x021C9B60 | DWCi_EncSessionProgressCallback (dwc_encsession.o) | 4 | DWCi_EncSessionProcess +0xE4 ABS32, word 0x021CA184 |

0x02181E18 was not in the brief. It is in the same run with the same kind of
evidence, and the other lane's pending ov114 0x021C2DB0 calls it.

### Catalog rows, seeds and listings

**symbols_sdk.json.** I inserted 7 rows in (address, name) order. Each has
`concrete = size` and `dupes = 1`, and `siblings` is the count after insertion
(gsxml.o ov009: 13, ghttpencryption ov114: 10, dwc_encsession ov114: 16). Each row
also has a new optional key `"referenced": true`, meaning it was placed by a located
row's relocation rather than by libmatch. That key works the same way as the existing
optional `adjacent` key. No existing row changed: the diff is 91 added lines.
`symbols_sdk.txt` is not touched (it has no overlay rows).

**function_starts.txt.** I seeded the 7 starts, each with a witness comment. Before
regenerating, I checked that no `asm/` file had changed in the previous two minutes.
Then `python tools/disasm.py overlay 9` gives 1614 funcs, and `overlay 114` gives 479
funcs. The only label changes are the 7 new `func_` globals.

**Stub files.** All seven verify EXACT with `manifest --verify --force` and are in
`src/matched/ov_sdk/`:
- ov009_func_02181E10.c, ov009_func_02181E14.c, ov009_func_02181E18.c, ov009_func_02181E20.c
- ov114_func_021C1C88.c, ov114_func_021C1C90.c, ov114_func_021C9B60.c

Their prototypes follow the DWARF (`(void)` for the free and encrypt stubs, `void *stream`
for the getters, with the sibling `GSIXmlStreamWriter` struct).

## 4. Re-verified pending files

| file | before | after | what unblocked it |
|---|---|---|---|
| ov114_func_021C2620 (152 B) | MATCH | EXACT, moved | 0x02181E20 |
| ov114_func_021C26B8 (708 B) | DIFF | EXACT, moved | string.h strlen + 0x02181E20 |
| ov114_func_021C109C (232 B) | MATCH | EXACT, moved | 0x021C1C88 and 0x021C1C90 |
| ov114_func_021CA0A0 (232 B) | MATCH | EXACT, moved | 0x021C9B60 |
| ov114_func_021C99D0 (400 B) | MATCH* | EXACT, moved | template prong (b); the 0x021C9B60 seed fixed the 404-byte extent |
| ov009_func_02194614 (224 B) | MATCH | EXACT, moved | overlay template (unique) |
| ov009_func_02193F00 (208 B) | MATCH | MATCH, stays | template now resolves; strcat 0x020948B0 (ARM9, no witness) is the only blocker. Note updated |
| ov009_func_02181C2C (228 B) | DIFF | DIFF, stays | both callees now resolve; the pool order still differs. Note updated |

In total, 6 files (1,948 B) moved to EXACT, plus the 7 stubs (44 B). Each moved
file's header status was copied from the verify output, and its stale blocker notes
were rewritten. A second plain `--verify` pass rewrote 0.

### Side effects (extents shortened by the new seeds)

- `ov009/pkt_ov009_02181DE8` gsXmlCloseWriter went from EXACT* to EXACT. I changed the
  header of `src/matched/ov_sdk/ov009_func_02181DE8.c` to EXACT, which is one word.
- `ov114/pkt_021B9500`: the entry for 0x021C1C80 (`src/matched/ov/ov114_func_021C1C80.c`,
  whose header already says EXACT) went from EXACT* to EXACT in the shard. The other
  entries of that shard are unchanged.

### Checked, not moved

- **ov114_func_021C2DB0.c** (another lane's pending file, written at 01:01). `match.py one`
  now says **EXACT**, because both its gsxml callees resolve. I did not touch it; its
  owner or the integrator should move it.
- ov114_func_021C9B64 is still DIFF (register swap). Its `@16117` site now resolves as
  `template`.
- ov009_func_0217CF5C (DIFF draft) is unaffected.

The ARM9 template files `arm9/pkt_020816FC` and the `func_0205EA08` entry of
`arm9/pkt_0205DC74` still verify EXACT.

## Final checks

- `python tools/match.py selftest --quick`: 281 cases, 0 failures.
- `python tools/match.py manifest --check`: clean (9098 shard files, no duplicates).
- `python tools/build.py --split --pack`, then
  `python tools/ndsrom.py build extract -o build/pokeblack.nds --override build/pack`:
  sha1 26ad0b9967aa279c4a266ee69f52b9b2332399a5.
- Coverage and worklist were not regenerated; that is for the integrator.

## Exact file list

Modified:
- tools/match.py
- layout/function_starts.txt
- layout/symbols_sdk.json
- src/matched/arm9_sdk/libc/string.h
- layout/matched/arm9/pkt_02059FA8.json, layout/matched/arm9/pkt_020816FC.json,
  layout/matched/arm9/pkt_0205DC74.json (re-verified; any content change is status/evidence only)
- layout/matched/ov009/pkt_ov009_02181DE8.json, src/matched/ov_sdk/ov009_func_02181DE8.c
  (status EXACT* to EXACT)
- layout/matched/ov114/pkt_021B9500.json (0x021C1C80 EXACT* to EXACT)
- src/pending/ov_sdk/ov009_func_02193F00.c, src/pending/ov_sdk/ov009_func_02181C2C.c (notes only)

New:
- src/matched/ov_sdk/ov009_func_02181E10.c, ov009_func_02181E14.c, ov009_func_02181E18.c,
  ov009_func_02181E20.c, ov114_func_021C1C88.c, ov114_func_021C1C90.c, ov114_func_021C9B60.c
- layout/matched/ov009/pkt_ov009_02181E10.json, pkt_ov009_02181E14.json, pkt_ov009_02181E18.json,
  pkt_ov009_02181E20.json
- layout/matched/ov114/pkt_ov114_021C1C88.json, pkt_ov114_021C1C90.json, pkt_ov114_021C9B60.json

Moved from src/pending/ov_sdk to src/matched/ov_sdk (header status and notes updated), each
with a new shard:
- ov114_func_021C2620.c (layout/matched/ov114/pkt_ov114_021C2620.json)
- ov114_func_021C26B8.c (pkt_ov114_021C26B8.json)
- ov114_func_021C109C.c (pkt_ov114_021C109C.json)
- ov114_func_021CA0A0.c (pkt_ov114_021CA0A0.json)
- ov114_func_021C99D0.c (pkt_ov114_021C99D0.json)
- ov009_func_02194614.c (layout/matched/ov009/pkt_ov009_02194614.json)

Regenerated, untracked: asm/overlays/ov009.s, asm/overlays/ov114.s.

This report: docs/sessions/2026-09-29/reports/w3_tools.md
