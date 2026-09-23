# Seed round 10: audit fixes, seeds, ov115 tables

Figure: exact 95.88 to 94.70 percent (379328/395634 to 379122/400350 bytes), reproduced 96.00 to 94.80, functions 4371 to 4373. ROM sha1 26ad0b99... verified by foldin.

Denominator +4716 bytes: +5004 from the runtime rows restored (0x02094B8C 2892, 0x0209953C 2112; 0x02099228 was stale and already matched, 0); -348 from the four strong SDK rows (FS_EndOverlay 232, FS_UnloadOverlayImage 16, FS_UnloadOverlay 76, CARDi_WaitAsync 24); +60 from the new seed labels. Numerator -206: -348 SDK, +92 from two promotions (worklist counts 30 + 62 code bytes), +6 from three veneers, +44 from the relabelled extents.

1. runtime_arm9.txt: three rows removed. The header now states the rule (hand-written assembly only) with the structural tell for each block, and cites the two notes that exist. 0x0209AC04 has no note of its own. It stays, with its tell (0x0209AF40 branches into its interior) marked weaker than the per-row proofs.
2. 0x0208CF34 is renamed STD_TSScanf and 0x0208D80C STD_TSNPrintf. The overrule now applies only to rows flagged `?` or whose name appears more than once in the file. Overruled rows: 26 before, 22 after. The src/matched files for the four stay; those functions count as SDK now.
3. Status gate: load_matched filters on MATCHED_STATUS, and plain `manifest` writes "unverified". Hint refusal (_hint_contested) is in sole-ref/data, with a 0x021D6338/ov021 case. The old case "ov021 hint attests" was inverted to "ov115 hint refused". Selftest: 168 cases, 0 failures. Open: sole-ref/self is not guarded. Guarding it would demote the committed func_0202F9F8 (ov179 hint, ov070/ov098 starts).
4. foldin exits non-zero on a sha1 mismatch. commit runs foldin first and refuses unless it passes and figures exist.
5. Seeds added: 0x02094530 (removes the 0x02094534 label), 0x0200AD7C/8C/94 and 0x020141E0/F0, all witnessed. The 21 src-only rows now name bl or pool sites. The three `bx pc` veneers are filed as asm like func_02091284 and are EXACT.
6. data_objects.txt accepts ovNNN rows, read by match.py overlay_declared_starts. Both ov115 tables are declared. func_02010AC4 and func_02010C34 are promoted EXACT: 0x021D654C via sole-ref/data, 0x021D6338 via sole-ref/self on the ov115 hint with the 0x73 overlay_id site.
7. func_020A8FE6 was NOT removed. disasm.py does not read data_objects.txt, so that row feeds match.py only. It also sits outside datamap.py's regenerated output.
