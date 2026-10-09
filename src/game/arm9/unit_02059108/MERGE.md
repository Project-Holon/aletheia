# unit_02059108 (arm9)

Round 5 (lane s13): 3 files, all verified by tools/match.py.

- `unit_02059108_p01.c`: func_02059108 .. DWCi_IsBuddyMsgAlreadySent (compiler 1.2, flags -O4,p, isa arm)
- `unit_02059108_p02.c`: DWCi_Acc_SetFlags .. DWC_IsValidFriendData (compiler 1.2, flags -O4,p, isa arm)
- `unit_02059108_p03.c`: DWC_CreateUserData .. func_020597F0 (compiler 1.2, flags -O4,p, isa arm)

Boundaries:
- `p01` | `p02`: real: a 12-byte linker veneer at 0x0205919C is not covered by any function.
- Round 5: p02, func_02059588 (the 1.2 part) and func_02059644 were merged into p02 after the 1.1p1 parts were retagged to 1.2 (they build EXACT under 1.2).
- `p02` | `p03`: a 12-byte linker veneer at 0x020596F0 before DWC_CreateUserData is not covered by any function; real boundary.
