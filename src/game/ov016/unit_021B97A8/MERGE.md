# unit_021B97A8 (ov016)

Round 5 (lane s13): 2 files, all verified by tools/match.py.

- `unit_021B97A8_p01.c`: func_021B97A8 .. func_021B9A2C (compiler ../2.0/sp1p2, flags -O4,p, isa thumb)
- `unit_021B97A8_p02.c`: ScanAP, func_021B9E8C, func_021B9EA4 (compiler ../2.0/sp1p2, flags -O4,p -ipa file, isa thumb)

Boundaries:
- `p01` | `p02`: blocker: with p01 and p02 in one file under -ipa file, DisconnectAP, func_021B9A2C and ScanAP change (5 / 442 / 268 bytes). p02 needs `-ipa file` (DIFF without it). Struct views of WMBssDesc, OSAlarm, WLAN_BSSID, ATERMSET_BSS were unified in round 5 (p01 builds EXACT with and without -ipa file); the remaining difference is an ipa effect, not a type one.
