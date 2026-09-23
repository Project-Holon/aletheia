# Wave 17 lane 17G: printf accounting

Seeds (layout/function_starts.txt, arm9_main, arm), each a home-area `push {r0, r1, r2, r3}` (0f 00 2d e9), confirmed with match.py show:

- 0x020929E8 long2str: comment corrected (home-area push of a by-value-aggregate function, not a veneer); bl from 0x0209323C, 0x02093F94
- 0x02092C38 longlong2str: bl from 0x02093F68
- 0x02092F0C double2hex: bl from 0x02094044
- 0x020934CC float2str: bl encoded as `.word 0xEBFFFD36` at 0x02093FEC (in __pformatter)
- 0x02093BDC __pformatter: bl from 0x020944F8

0x020933B8 needed nothing: its extent was clipped by the new 0x020934CC label.

Regenerated arm9 with `disasm.py arm9 --split` and refreshed the worklist. The +4 labels (0x02092C3C, 0x02092F10, 0x020934D0, 0x02093BE0) are gone from the current listings and from `worklist.py --targets 80`. The unit 30 boundary moved, so unit 31 is now 031_0209C554.s (layout/units_arm9.json changed). disasm.py was not edited.

Verdicts (before, then after two verify runs): 020929E8 EXACT*, EXACT*; 02092C38 EXACT*, EXACT*; 02092F0C EXACT*, EXACT*; 020933B8 EXACT*, EXACT; 020934CC EXACT, EXACT*; 02093BDC EXACT*, EXACT*; 0209455C EXACT, EXACT.

Blocker: match.py's listing_files() reads every asm/arm9/src/*.s file. That directory holds 195 stale split files from older runs, which are not in units_arm9.json. Their labels still create 4-byte extents. There are 12 stale labels: 0x0202173E, 0x0202184A, 0x0203F32C, 0x02040EC0, 0x020507A4, 0x02091E48, 0x020929EC, 0x02092C3C, 0x02092F10, 0x020934D0, 0x02093BE0 and 0x020979C0 (17F's function). Moving the stale files out was denied by the permission system. `wave.py foldin` was also denied, so there is no FIGURES line and no sha1 check. selftest: 166 cases, 0 failures.

## Follow-up: tools/match.py reads only the listings named in the manifests

The coordinator ruled: fix match.py and delete nothing. There is a new helper, `unit_files(sub, manifest)`. It returns the files listed in layout/units_arm9.json (or units_itcm.json). If the manifest is missing, it falls back to reading the whole directory. `listing_files()` (arm9 and ITCM) and `evidence_files()` now use it. Overlays need no change: each overlay has one listing file (asm/overlays/ovNNN.s), and asm/arm9/*.s holds no split units. A new selftest case builds a temporary tree with a stale unit and checks that only the unit in the manifest is read. Result: 167 cases, 0 failures.

Two verify runs of pkt_020929E8, identical: all seven entries are EXACT (020929E8, 02092C38, 02092F0C, 020933B8, 020934CC, 02093BDC, 0209455C).

Extents (both were 2 bytes before the fix): 0x0202173C is 268 bytes (to 0x02021848), and 0x02021848 is 232 bytes (to 0x02021930).
