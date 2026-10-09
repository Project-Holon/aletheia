# unit_02165B80 (ov009)

2 parts remain (p01, p02), both use the canonical WCM types in ../wcm_types.h (WCMWork,
WCMApList, WCMApListHeader, WMBssDesc, WMGameInfo). p01 is EXACT, p02 is MATCH.

Round 5 (r5 s05): old p02 and p03 are joined (0x02165CAC..0x02166304). The statics
WcmGetOldestApList, WcmSearchApList and WcmSearchIndexedApList are called by their
names now (were func_02165E98 / func_02165EC8 externs).

p01 | p02 is a 12-byte linker veneer at 0x02165CA0..0x02165CAC (no function covers it):
real file boundary. Nothing else left to merge.
