# vendor_scan report (2026-09-27)

## Cause: the premise is a display artifact

The per-overlay table in `ovstats.py` prints `code_bytes` (SDK included) and divides matched game bytes by it. The denominator already leaves the SDK out (`ovstats.py --json`):

| overlay | code B | SDK B | game B | matched game | real % |
|---|---|---|---|---|---|
| ov009 | 275192 | 264912 | 10280 | 1228 | 11.9 |
| ov016 | 115398 | 114454 | 944 | 836 | 88.6 |
| ov114 | 74896 | 65304 | 9592 | 1560 | 16.3 |

So the game figure is not inflated by about 460 KB. The three overlays hold 20.8 KB of game bytes in total.

## Sample: every open non-SDK function (102; fewer than 40 in ov016 and ov114)

I checked every member of every archive, all variants, with relocations wildcarded. Scripts and output are in `scratch/vendor_scan/`.

| overlay | class | fns | bytes | archive result |
|---|---|---|---|---|
| ov009 | Thumb glue 02155168-02157170 | 57 | 7780 | none (best near hit is at least 18% different, which is noise); one 16 B generic hit |
| ov009 | ARM split labels | 9 | 1360 | none by themselves; each one is prev SDK row + 4 |
| ov009 | phantoms 021A2CEC, 021A3248 | 2 | (data) | none (CA certificate blobs) |
| ov016 | Thumb glue 021B6100/6154/6190 | 3 | 152 | none |
| ov016 | phantoms (AES tables) | 2 | (data) | none |
| ov114 | Thumb glue 021B95D4-021B9AA8 | 7 | 940 | none |
| ov114 | ARM block 021C7BA0-021C97E0 | 21 | 6680 | none |
| ov114 | ARM split label 021CA738 | 1 | 436 | none (ParseSignHash + 4) |

What each class is:
- **Thumb glue:** game code. It is Thumb, and it calls ARM9 game functions (heap and so on) plus the public DWC/NHTTP API. The file anchors in the data are the game's own wrappers: `net_devwifi.c`, `dwc_rap.c`, `dwc_rapcommon.c`, `nhttp_rap.c`, `nhttp_rap_evilcheck.c`.
- **Split labels:** vendor code miscounted. The function opens with `stmfd sp!,{r0-r3}` and then a second push. The disassembler labels the second push. The SDK row covers 4 bytes, and the rest of the verified pattern body is counted as game.
- **ov114 ARM block:** a Pokemon GTS and Battle Subway web client. Its strings are `/web/worldexchange/*.asp`, `/web/battletower/*.asp` and a `syachi2ds` key string, and it calls DWCi_EncSession. It is ARM-built middleware (Dpw-like) with no archive in `sdk/`.
- **Also seen:** about 2.2 KB of already-matched "game" entries (4-16 B accessors) match generic DWC/GameSpy patterns ambiguously. That is not a basis to move them. There are also two stray `EXT_TestResetCounter` rows inside the ov114 block (021C8658, 021C93BC). They are false positives with no effect, because no label sits there.

## Byte estimate

- Vendor bytes with a real basis still counted as game: 1796 B (the split labels).
- Vendor by provenance only, no object to match: 6680 B (ov114).
- Game: about 8.9 KB of glue plus the matched rows.

## Recommendation

1. **ovstats display (figure unchanged):** print SDK and game columns, and take the percentage over `game_bytes`.
2. **Split-label rule (moves the figure by 1796 B; for the owner to approve):** when a verified SDK pattern is longer than the gap to the next listing label, `ovstats` should attribute the pattern's full size to the SDK. The basis is byte identity over the whole pattern.
3. **ov114 ARM block:** no change. There is no vendor object to match against, so it stays game until such an object turns up.
