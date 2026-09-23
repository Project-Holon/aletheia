# Audit of the coverage rules, 2026-09-23

Independent, read-only audit. HEAD moved during the audit (ffccd7c to e442072). The headline is now
95.88 percent (379328 of 395634 bytes, 4371 functions), and README.md, layout/worklist.json and the
commit message agree on it.

## Verdicts

| Rule | Verdict | Reason |
|---|---|---|
| EXACT verdict (compare()) | sound | Every byte has to be equal and unmasked; a wildcard that happens to be equal only earns MATCH. |
| EXACT* | sound | Recompiled all 502 ARM9 non-unit EXACT* entries. The worklist extent is never longer than the compiled body (gap 0 in 394 cases, negative in 103 where the excess is pool data), so no uncompared code byte is credited. |
| Shards from manifest --verify | sound, gated | Re-derived all 3720 HEAD entries in memory: 3720 of 3720 still EXACT/EXACT*. There are 39 metadata drifts: 25 evidence lists that got stronger after seeding, and 8 cases where the star flag flipped because the listing extent moved. |
| Header `status:` never trusted | weak | Plain `manifest` (without --verify) copies the header status, and worklist.load_matched() never reads `status`. The only thing that catches this is build.py/csrc.py, which recompile and refuse anything that is not EXACT or still has wildcards. |
| worklist counts shard bytes only | sound | It counts code bytes only. Implied unit members come from definitions in an EXACT TU. |
| local, matched, label (incl. ovNNN), literal (incl. hidden pools), string, veneer, runtime, data_table, sdk, sole-ref data/code/string/self, overlay data/self, matched-overlay | sound for the figure | Every class only decides whether a declared value gets hardened. The value is still compared against the image, so none of them can make wrong bytes EXACT. A loose class can only mislabel which symbol a correct word names. Selftest: 167 cases, 0 failures. |
| overlay_id | sound | The pool word stays a compared byte, so a wrong id gives DIFF. I checked the one listing-only consumer, 0x020312CC, against asm/arm9/src/013_0202EC44.s: `mov r4,r0 ... mov r1,r4; bl func_020314F4`. |
| per-overlay sole-ref/data with a hint | weak (semantic only) | Reproduced: `attest_sole_ref_overlay_data(0x021D6338, region_hint='ov021')` attests, because ov021's own listing has a start there. The hint is an unchecked claim among 9 overlapping overlays. No committed entry uses this path (only 3 ARM9 entries touch overlay addresses, all code/self). No selftest case covers a wrong hint that lands on another overlay's real start. |
| listing_files (17G) | sound | Stale split labels no longer cut extents. |
| Seeds, rounds 7 to 9 | sound | 61 rows; checked all of them, not just a sample of 20. Every ARM9 row is a matched function with real code at its start, and none begins on a pad or pool word. 20 rows cite only their src/matched file. HANDOFF step 4 allows that, but the header of function_starts.txt says the witness must be an image instruction. |
| SDK denominator | sound, minor naming | The 9 weak ARM9 rows total 146 bytes. The 15-row sample and both rulings have a libmatch or hand-comparison basis. Two rows have the wrong name but are still SDK: 0x0208CF34 calls STD_TVSScanf, so it is STD_TSScanf, not OS_SPrintf; 0x0208D80C is STD_TSNPrintf, not OS_SNPrintf. |
| Runtime denominator | unsound (2 rows) | See finding 1. |
| ROM claim | sound | `build.py --split --only arm9_main`: PASS, 3615 C entries, 433974 bytes spliced. foldin prints the sha1 line but never asserts it. |
| Wording | weak | See findings 2 and 5. |

## Findings, ranked by effect on the figure

1. **Runtime rows exclude MSL C (about -1.2 points).** 0x02094B8C `_msl_scanf_strtod_core` (2892 B) and 0x0209953C
   `_msl_double_fn_2` (2112 B, 60 soft-float `bl`) are compiled C according to their own notes
   (pkt_02094B8C: "ceiling today is MATCH"), yet the table's header calls them hand-written assembly. That is the same
   error as the removed pow and rem_pio2 rows. Restoring them gives 94.68 percent. The 0x02099228 row is stale
   (__kernel_cos is EXACT), and the citation docs/notes/pkt_0209AC04.c.txt does not exist.
   Fix: remove both rows and the stale one, and keep only rows with a per-row structural proof.
2. **MSL is counted inconsistently (up to about -0.2 points).** HANDOFF says "Vendor library bodies are library code,
   not game code", but matched MSL C (printf family, pow, rem_pio2, kernel_cos, floor, strcpy) is credited as game code.
   The address window 0x020929E8..0x0209BDBC has 57 matched functions (17600 B); treat that as an upper bound on the MSL
   bytes. Fix: pick one rule. Either all MSL C goes in the denominator (finding 1), or it all leaves the denominator
   and is reported separately the way sdk_matched is. Then say "game and MSL C" or "game code" to match.
3. **SDK overrule applied to strong rows (-0.004 points).** The overrule was meant for weak patterns, but 0x02079164
   FS_EndOverlay, 0x02079254 FS_UnloadOverlayImage, 0x020792B8 FS_UnloadOverlay (44-byte FSOverlayInfo, calls
   FS_LoadOverlayInfo) and 0x02076050 CARDi_WaitAsync sit between SDK-classified fs_overlay.o / card members.
   match.py itself cites 0x020792B8 as symbols_sdk. Together that is 348 B of SDK credited as game.
   Fix: let a matched entry override only rows flagged `?` or rows whose name appears more than once.
4. **Status is not a gate in worklist (0 today).** Fix: load_matched() skips any status not in MATCHED_STATUS,
   plain `manifest` writes `status: unverified`, and wave.py foldin fails if the sha1 differs.
5. **Wording (0).** HANDOFF line 3 still gives 93.91 as the "current" figure. HANDOFF line 9 says the byte-identical ROM
   is rebuilt "from the split units", but it does not say that unmatched functions come from the reassembled listings.
   README says so only indirectly ("links against remaining assembly"). Fix: update line 3 and add that clause.
6. **Overlay hint (0).** Fix: refuse a hint when another overlay in the window also has a start at that address, and
   add a selftest case for 0x021D6338 with ov021.

No finding shows wrong bytes counted as verified. The 95.88 figure is byte-true. What is not principled is how the
denominator treats MSL, and that moves the figure by about 1.2 points.
