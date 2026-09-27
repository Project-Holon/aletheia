# libmatch_overlays report (2026-09-27)

Every archive and every overlay was already scanned, so the missed rows did not come from a skipped family, variant or region. There were three causes in tools/libmatch.py:

1. **BL rewritten to BLX.** The R_ARM_PC24/CALL mask covered only the low 24 bits. When the target is Thumb, the linker rewrites the top byte of an unconditional `bl` (0xEB) to 0xFA/0xFB. TwlDWC code calls Thumb objects, so the verify step failed (libaoss.o, rakuraku.o). Fix: that byte must be one of EB/FA/FB. It is never wildcarded.
2. **No key for `push; bl` Thumb openers.** The 2-byte first run was too short, so 723 patterns were never indexed (apc.o, atermset.o, aoss.o). Fix: the index keys on the first 4+ byte run at its offset. verify() still checks every run from the start of the function.
3. **MAX_HITS.** Each scene*.o has its own identical static procInit/procInit2/endScene, so each pattern hit more than 8 places and was dropped. Fix: a second pass keeps such a hit only where it is the next or previous function, in the object's section order, after a function already resolved from that object, and flush against it (at most 3 bytes of padding). The pass runs to a fixed point.

The NOTYPE and minimum-length rules were not factors. A new `--outdir` flag keeps dry runs out of layout/.

**Rows:** I merged 155 rows into the committed files. No existing row changed. Hand rows are kept, owner removals stay removed, and twl rows are not added. By region: arm9 38, ov016 104, ov009 10, ov114 3. ov016 is all libdwcutil. The other overlays: libdwcmatch 3, libdwcauth 3, libdwcnd 2, and 1 each from cps, ssl, wcm, gscommon and gsghttp.

**Withheld (12):** 10 rows are short Thumb hits from `.thumb`/LTD/NTR archives with no unique sibling, in ov014/015/021/029/099/172/231 and arm9. The other 2 are rows the owner removed (0203CFF0, 0203D000).

**Figures (same moment, old versus new json):**
- Overlay SDK: 466350 to 473226 B (+6876). Overlay game: 1909646 to 1902770. ov016 +6696, ov009 +120, ov114 +60.
- Overlay matched game: 362820 to 360844 (18.9993% to 18.9641%).
- arm9 (worklist): matched game 401976 to 400424 B (21 functions to SDK). 8 GX rows are overruled because their names repeat. The rows are all additions; worklist.json had been stale before this run.

**Matched game files at new SDK addresses (58):**
- arm9: 29 (0205A10C, 02075DA0 through 02091150)
- ov009: 7
- ov016: 19 (initGraphics copies, RAKUlEnd, MSGlEnd, HLlEnd)
- ov114: 3

The list is in scratch libmatch_ov/conf.txt. No src/pending file conflicts.

**Left open:** ov016 021B6100/6154/6190 match no object. 021D7D48 and 021D88D6 are the known phantoms.

**Caution:** a plain `libmatch.py scan` overwrites both files, drops the hand rows and adds 211 twl rows.
