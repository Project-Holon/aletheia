# unit_021F3D04 (ov107): merge status

Files left (address order):

- unit_021F3D04_p01.c: func_021F3D04 to func_021F42A4 (12 functions)
- unit_021F3D04_p02.c: func_021F42D4 to func_021F4538 (2 functions)

Boundaries and reasons:

Boundary at 0x021F42D4 (MB library, mb_gameinfo.o). Part 1 reaches a static block through raw offsets of g_021F6EF4. Part 2 reaches the same block as one struct (sUnlockFunc). The real layout: four unused-looking static pointers (0x10 bytes), a lock flag (0x10), the unlock function pointer (0x14), then the send status struct MbSendStatus at 0x18 (top, nowGInfop, nowFixedp, state, pad, seqNoVolat, fragmentNo, fragmentMaxNum, beaconNo). It builds fully typed (named MbGameInfo fields, one MbBeacon, one copy of the MI_Cpu inline helpers), but the .bss layout is not reproducible yet: as separate statics the compiler drops the four unused pointers and moves sUnlockFunc to offset 0 (one byte differs in MB_InitSendGameInfoStatus, and the register allocation of MBi_SendVolatBeacon and MBi_CheckMBParent differs); as one struct, MBi_SendFixedBeacon schedules loads differently (22 bytes). Needs the real uses of the four pointers (functions in another file of the library) or a layout trick that keeps them.

Every file above verifies EXACT or MATCH with tools/match.py.

Round 18 (lane L16): the first pointer of the four (offset 0) is the game info list head, read and written by
func_021F3F34 (MB_AddGameInfo): `g_021F6EF4.list`. The 0x21F6EF0 word belongs to the previous TU (unit_021F2F1C,
MB_RegisterFile function static `update`), so this TU's .bss starts at 0x21F6EF4. Statics that no function of the TU
reads are dropped by the compiler, so the three other pointers (offsets 4, 8, 0xC) must be read by code in this TU
that is not yet written, or be non-static (external) objects. Not resolved. Also see the alias lesson in
unit_021F4560/MERGE.md: file-scope statics are in the unknown-memory alias set, members of one struct are one object;
that explains scheduling differences between "separate statics" and "one struct".
