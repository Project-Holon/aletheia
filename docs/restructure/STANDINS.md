# Source census: code the developers would not have written

Snapshot taken 2026-10-11 23:13 local time over 2090 files in src/game (.c and .h, files starting with an underscore skipped). Other lanes were editing src/game at the same time, so the numbers are a snapshot and will drift.

Goal: the final src/game files should read like the original source. This census counts constructs that look like workarounds for the compiler or for missing type information, not like code a person would write. Each kind is a candidate for cleanup, not a defect by itself: some entries are legitimate (SDK CPU helpers in asm, volatile on hardware registers, K&R style in old SDK code). Counts come from a script (scratchpad r18/L21/census.py) that strips comments and string literals first, so text inside comments is not counted, except stand-in comments, which are counted in the raw text.

## Kinds counted

| Kind | What is counted |
|---|---|
| asm functions | `asm` function definitions (bodies only, not prototypes) and inline `__asm` or `asm { }` blocks |
| fn-ptr casts | `((T (*)(...))f)(...)` style casts of a value to a function pointer type |
| raw offsets | `(u8 *)p + 0x..` or `(char *)p + 0x..` style byte-offset arithmetic. The script cannot tell whether a struct is in scope, so this is an upper bound on the avoidable ones |
| volatile (hw reg) | `volatile` on a line that names an address 0x04xxxxxx or a REG_/HW_ symbol |
| volatile (other) | any other `volatile`: shared state or untied to a visible register address |
| 64-bit params | function declarations or definitions with `long long`, s64 or u64 parameters (often two ints packed in one) |
| dup symbol rows | `symbols:` rows (addresses from 0x01000000 up, so overlay ids are excluded) whose address appears under a different name elsewhere in src/game (two externs for one address). Rows counted in every file that holds one of the names |
| stand-in comments | comments that open with `stand-in` |
| per-fn struct clones | struct typedef or tag names that end in an address, such as Obj_0204C83C or Q_06899E48 (distinct names per file) |
| goto into loop | a `goto` whose label sits inside a braced loop that does not contain the goto (heuristic scan) |
| unprototyped/K&R | `T f();` declarations with empty parentheses, `T f() {` definitions and K&R identifier-list definitions |
| settings pragmas | any `#pragma` other than `thumb on/off/reset` (opt_* and similar) |

## Totals by kind and region

| Kind | arm9 | ITCM | twl | overlays | all |
|---|---|---|---|---|---|
| asm functions | 239 | 7 | 222 | 47 | 515 |
| fn-ptr casts | 76 | 0 | 0 | 353 | 429 |
| raw offsets | 132 | 0 | 0 | 683 | 815 |
| volatile (hw reg) | 283 | 5 | 13 | 1245 | 1546 |
| volatile (other) | 343 | 3 | 7 | 271 | 624 |
| 64-bit params | 53 | 0 | 0 | 63 | 116 |
| dup symbol rows | 2538 | 6 | 221 | 18477 | 21242 |
| stand-in comments | 0 | 0 | 0 | 3 | 3 |
| per-fn struct clones | 583 | 0 | 0 | 4745 | 5328 |
| goto into loop | 0 | 0 | 1 | 4 | 5 |
| unprototyped/K&R | 5 | 0 | 0 | 494 | 499 |
| settings pragmas | 2 | 0 | 0 | 88 | 90 |
| files scanned | 431 | 4 | 89 | 1565 | 2089 |

Notes: the word "stand-in" appears 75 times in all comment text (including notes that say a stand-in was removed); the table counts only comments that open with it. Distinct addresses with more than one name: 2125.

Of those addresses, 603 have only address-named variants (func_, sub_, d_, g_ prefixes of the same hex) and 1522 have at least one human-given name (for example SVC_WaitByLoop beside func_02004490). The table counts rows per file, so one address shared by many files counts many times.

## asm functions

- 316: game function: stand-in or unknown
- 145: SDK symbol (symbols_sdk.txt): real asm likely
- 39: unknown
- 8: SDK-style name, not in symbol list: likely real asm
- 7: inline block, unknown

| File | Function | Class |
|---|---|---|
| arm9/app_taskmenu.c | OS_SetPrintBlockingMode | SDK-style name, not in symbol list: likely real asm |
| arm9/backup_system.c | FSi_ConvertStringSjisToUnicode | SDK-style name, not in symbol list: likely real asm |
| arm9/bg_sys.c | func_020414AC | game function: stand-in or unknown |
| arm9/bgm_info.c | ArrayDeleteAt | SDK symbol (symbols_sdk.txt): real asm likely |
| arm9/clact_p01.c | func_0204B084 | game function: stand-in or unknown |
| arm9/g3d_system.c | DWCi_LSTlPopFront | SDK-style name, not in symbol list: likely real asm |
| arm9/g3d_system.c | func_02049238 | game function: stand-in or unknown |
| arm9/g3d_system.c | NHTTPi_GetConnection | SDK symbol (symbols_sdk.txt): real asm likely |
| arm9/net_err.c | CTRDGi_IsTaskAvailable_02010054 | SDK-style name, not in symbol list: likely real asm |
| arm9/particle.c | KeyValHashKey | SDK symbol (symbols_sdk.txt): real asm likely |
| arm9/procsys.c | func_0203129C | game function: stand-in or unknown |
| arm9/tcbl.c | func_020307C8 | game function: stand-in or unknown |
| arm9/tcbl.c | func_02030BA4 | game function: stand-in or unknown |
| arm9/ui.c | func_02034F74 | game function: stand-in or unknown |
| arm9/ui.c | func_02034F84 | game function: stand-in or unknown |
| arm9/ui.c | func_02034FD4 | game function: stand-in or unknown |
| arm9/ui.c | func_02034FE8 | game function: stand-in or unknown |
| arm9/ui.c | func_0203516C | game function: stand-in or unknown |
| arm9/ui.c | func_020351D0 | game function: stand-in or unknown |
| arm9/unit_0200421A.c | func_0200421A | game function: stand-in or unknown |
| arm9/unit_02004490.c | func_02004490 | game function: stand-in or unknown |
| arm9/unit_02004632.c | func_02004632 | game function: stand-in or unknown |
| arm9/crt0.c | _start | SDK symbol (crt0.HYB.TWL.o): real asm in the SDK source |
| arm9/crt0.c | INITi_CpuClear32 | SDK symbol (crt0.HYB.TWL.o): real asm in the SDK source |
| arm9/crt0.c | INITi_InitCoprocessor | SDK symbol (crt0.HYB.TWL.o): real asm in the SDK source |
| arm9/crt0.c | INITi_InitRegion | SDK symbol (crt0.HYB.TWL.o): real asm in the SDK source |
| arm9/crt0.c | INITi_DoAutoload | SDK symbol (crt0.HYB.TWL.o): real asm in the SDK source |
| arm9/crt0.c | INITi_ShelterStaticInitializer | SDK symbol (crt0.HYB.TWL.o): real asm in the SDK source |
| arm9/crt0.c | INITi_CallStaticInitializers | SDK symbol (crt0.HYB.TWL.o): real asm in the SDK source |
| arm9/crt0.c | MIi_UncompressBackward | SDK symbol (crt0.HYB.TWL.o): real asm in the SDK source |
| arm9/crt0.c | INITi_Copy32 | SDK symbol (crt0.HYB.TWL.o): real asm in the SDK source |
| arm9/crt0.c | INITi_Fill32 | SDK symbol (crt0.HYB.TWL.o): real asm in the SDK source |
| arm9/unit_0202FB34.c | func_0202FB34 | game function: stand-in or unknown |
| arm9/unit_02035390.c | DWCi_IsFold | SDK symbol (symbols_sdk.txt): real asm likely |
| arm9/unit_020461E4.c | DWCi_Language | SDK symbol (symbols_sdk.txt): real asm likely |
| arm9/unit_020590AC.c | DWCi_Acc_GetFriendKey | SDK symbol (symbols_sdk.txt): real asm likely |
| arm9/unit_02059108.c | func_0205911C | game function: stand-in or unknown |
| arm9/unit_02059108.c | DWC_CheckFriendKey | SDK symbol (symbols_sdk.txt): real asm likely |
| arm9/unit_0205A134.c | func_0205A148 | game function: stand-in or unknown |
| arm9/unit_0205B1E4.c | DisConnectAP | SDK symbol (symbols_sdk.txt): real asm likely |
| arm9/unit_0205D0E4.c | GetProgramaError | SDK symbol (symbols_sdk.txt): real asm likely |
| arm9/unit_0205D1C4.c | GetNotFoundAP | SDK symbol (symbols_sdk.txt): real asm likely |
| arm9/unit_0205D91C.c | DWC_AC_CancelGetWDSInfo | SDK symbol (symbols_sdk.txt): real asm likely |
| arm9/unit_0205FAA8.c | NCFG_ReadConfig | SDK symbol (symbols_sdk.txt): real asm likely |
| arm9/unit_02061B2C_p02.c | DWCi_TSKlForm | SDK symbol (symbols_sdk.txt): real asm likely |
| arm9/unit_020627D8.c | func_020627F0 | game function: stand-in or unknown |
| arm9/unit_020627D8.c | func_02062810 | game function: stand-in or unknown |
| arm9/unit_020627D8.c | func_0206295C | game function: stand-in or unknown |
| arm9/unit_02066B84.c | CARD_SetPulledOutCallback | SDK symbol (symbols_sdk.txt): real asm likely |
| arm9/unit_02066B84.c | CTRDGi_CallbackForSetPhi | SDK-style name, not in symbol list: likely real asm |
| arm9/unit_02066B84.c | func_02066E10 | game function: stand-in or unknown |
| arm9/unit_02067FE4_p01.c | (inline asm block) | inline block, unknown |
| arm9/unit_02067FE4_p01.c | (inline asm block) | inline block, unknown |
| arm9/unit_02067FE4_p02.c | (inline asm block) | inline block, unknown |
| arm9/unit_020775B8.c | CP_SaveContext | SDK symbol (symbols_sdk.txt): real asm likely |
| arm9/unit_020775B8.c | CPi_RestoreContext | SDK symbol (symbols_sdk.txt): real asm likely |
| arm9/unit_02077634.c | func_02078530 | game function: stand-in or unknown |
| arm9/unit_020787A0.c | FS_CloseFile | SDK symbol (symbols_sdk.txt): real asm likely |
| arm9/unit_020787A0.c | CRYPTOi__BN_lshift1 | unknown |
| arm9/unit_0207A7C4.c | FSi_MemArchiveProc | SDK symbol (symbols_sdk.txt): real asm likely |
| arm9/unit_0207AD04.c | func_0207AD40 | game function: stand-in or unknown |
| arm9/unit_0207AD58.c | func_0207AD58 | game function: stand-in or unknown |
| arm9/unit_0207AD58.c | MTX_Rot22_ | SDK symbol (symbols_sdk.txt): real asm likely |
| arm9/unit_0207ADC4.c | func_0207ADC4 | game function: stand-in or unknown |
| arm9/unit_0207ADC4.c | func_0207ADE8 | game function: stand-in or unknown |
| arm9/unit_0207ADC4.c | func_0207AE24 | game function: stand-in or unknown |
| arm9/unit_0207ADC4.c | MTX_RotX33_ | SDK symbol (symbols_sdk.txt): real asm likely |
| arm9/unit_0207ADC4.c | MTX_RotY33_ | SDK symbol (symbols_sdk.txt): real asm likely |
| arm9/unit_0207ADC4.c | MTX_RotZ33_ | SDK symbol (symbols_sdk.txt): real asm likely |
| arm9/unit_0207B598.c | func_0207B598 | game function: stand-in or unknown |
| arm9/unit_0207B598.c | func_0207B5C0 | game function: stand-in or unknown |
| arm9/unit_0207B598.c | MTX_Scale43_ | SDK symbol (symbols_sdk.txt): real asm likely |
| arm9/unit_0207B598.c | func_0207B640 | game function: stand-in or unknown |
| arm9/unit_0207BDB4.c | func_0207BDB4 | game function: stand-in or unknown |
| arm9/unit_0207BDB4.c | func_0207BDE0 | game function: stand-in or unknown |
| arm9/unit_0207D988.c | func_0207DECC | game function: stand-in or unknown |
| arm9/unit_0207F7A0.c | GX_BeginLoadClearImage | SDK symbol (symbols_sdk.txt): real asm likely |

(435 more rows not listed)

## Top 40 files by total count

| # | File | Total | Kinds |
|---|---|---|---|
| 1 | ov094/btlv_effvm.c | 480 | fn-ptr casts 14, raw offsets 3, volatile (hw reg) 17, volatile (other) 3, dup symbol rows 97, per-fn struct clones 342, settings pragmas 4 |
| 2 | ov119/pokemontrade_3d.c | 331 | fn-ptr casts 1, raw offsets 12, volatile (hw reg) 49, volatile (other) 5, dup symbol rows 150, per-fn struct clones 114 |
| 3 | ov175/wifibattlematch_net.c | 249 | fn-ptr casts 1, raw offsets 3, 64-bit params 1, dup symbol rows 81, per-fn struct clones 157, unprototyped/K&R 6 |
| 4 | ov208/zukan_detail_graphic.c | 246 | fn-ptr casts 2, volatile (hw reg) 13, volatile (other) 4, dup symbol rows 166, per-fn struct clones 59, unprototyped/K&R 2 |
| 5 | ov021/field_effect_p01.c | 213 | fn-ptr casts 1, volatile (hw reg) 1, volatile (other) 1, 64-bit params 1, dup symbol rows 78, per-fn struct clones 131 |
| 6 | ov010/comm_player.c | 181 | raw offsets 5, volatile (other) 1, 64-bit params 1, dup symbol rows 95, per-fn struct clones 48, unprototyped/K&R 31 |
| 7 | ov018/intrude_subdisp.c | 181 | fn-ptr casts 6, raw offsets 34, volatile (hw reg) 5, volatile (other) 1, dup symbol rows 80, per-fn struct clones 44, unprototyped/K&R 9, settings pragmas 2 |
| 8 | ov021/field_msgbg.c | 179 | fn-ptr casts 1, raw offsets 9, volatile (hw reg) 1, volatile (other) 2, dup symbol rows 96, per-fn struct clones 70 |
| 9 | ov217/research_top.c | 168 | fn-ptr casts 1, raw offsets 29, volatile (hw reg) 36, volatile (other) 1, dup symbol rows 61, per-fn struct clones 27, unprototyped/K&R 13 |
| 10 | ov099/unit_021BF050.c | 164 | raw offsets 1, dup symbol rows 48, per-fn struct clones 112, unprototyped/K&R 3 |
| 11 | ov071/monolith_tool.c | 163 | fn-ptr casts 2, raw offsets 21, volatile (hw reg) 8, volatile (other) 1, dup symbol rows 99, per-fn struct clones 28, settings pragmas 4 |
| 12 | ov131/p_sta_oam.c | 157 | raw offsets 6, volatile (hw reg) 17, volatile (other) 1, 64-bit params 1, dup symbol rows 105, per-fn struct clones 27 |
| 13 | ov112/musical_mcss.c | 155 | volatile (hw reg) 19, volatile (other) 4, 64-bit params 1, dup symbol rows 83, per-fn struct clones 48 |
| 14 | ov121/mystery_util.c | 151 | fn-ptr casts 4, raw offsets 3, volatile (hw reg) 26, volatile (other) 2, 64-bit params 1, dup symbol rows 73, per-fn struct clones 34, settings pragmas 8 |
| 15 | ov123/gsync_state.c | 148 | fn-ptr casts 2, raw offsets 2, volatile (hw reg) 6, volatile (other) 3, dup symbol rows 111, per-fn struct clones 24 |
| 16 | ov208/zukan_detail_form.c | 146 | raw offsets 11, dup symbol rows 130, per-fn struct clones 5 |
| 17 | ov135/worldtrade_adapter.c | 145 | fn-ptr casts 5, volatile (hw reg) 5, volatile (other) 1, dup symbol rows 109, per-fn struct clones 23, unprototyped/K&R 2 |
| 18 | ov009/unit_0216F014.c | 142 | volatile (other) 3, dup symbol rows 134, per-fn struct clones 4, unprototyped/K&R 1 |
| 19 | ov137/guru2_main.c | 139 | fn-ptr casts 10, raw offsets 1, volatile (hw reg) 6, volatile (other) 6, dup symbol rows 90, per-fn struct clones 24, settings pragmas 2 |
| 20 | ov172/ctvt_draw_p01.c | 136 | raw offsets 1, volatile (hw reg) 24, volatile (other) 4, dup symbol rows 65, per-fn struct clones 42 |
| 21 | arm9/net_state.c | 133 | fn-ptr casts 17, raw offsets 4, volatile (other) 20, 64-bit params 1, dup symbol rows 67, per-fn struct clones 24 |
| 22 | ov107/mb_comm_sys.c | 131 | fn-ptr casts 3, volatile (hw reg) 5, volatile (other) 2, dup symbol rows 98, per-fn struct clones 23 |
| 23 | ov110/pmsiv_menu.c | 127 | raw offsets 3, dup symbol rows 60, per-fn struct clones 64 |
| 24 | ov021/field_wfbc.c | 126 | raw offsets 2, volatile (hw reg) 14, 64-bit params 1, dup symbol rows 76, per-fn struct clones 22, unprototyped/K&R 11 |
| 25 | ov133/dup_fitting_item.c | 126 | volatile (hw reg) 9, volatile (other) 1, dup symbol rows 88, per-fn struct clones 28 |
| 26 | ov010/fldmmdl.c | 125 | raw offsets 15, dup symbol rows 43, per-fn struct clones 47, unprototyped/K&R 16, settings pragmas 4 |
| 27 | arm9/button_man_p03.c | 124 | volatile (hw reg) 56, volatile (other) 9, dup symbol rows 38, per-fn struct clones 20, unprototyped/K&R 1 |
| 28 | ov088/startmenu.c | 124 | raw offsets 1, volatile (hw reg) 5, volatile (other) 2, dup symbol rows 95, per-fn struct clones 21 |
| 29 | ov106/irc_ranking.c | 124 | volatile (hw reg) 4, volatile (other) 1, dup symbol rows 75, per-fn struct clones 44 |
| 30 | ov021/field_place_name.c | 122 | raw offsets 3, dup symbol rows 43, per-fn struct clones 76 |
| 31 | ov111/unit_021C3CC0.c | 119 | volatile (hw reg) 9, dup symbol rows 55, per-fn struct clones 55 |
| 32 | ov128/unit_021C6180.c | 117 | raw offsets 6, volatile (hw reg) 9, volatile (other) 1, 64-bit params 2, dup symbol rows 91, per-fn struct clones 8 |
| 33 | ov170/box2_seq.c | 116 | fn-ptr casts 5, raw offsets 1, volatile (hw reg) 4, dup symbol rows 74, per-fn struct clones 32 |
| 34 | ov072/townmap.c | 115 | raw offsets 3, volatile (hw reg) 4, dup symbol rows 76, per-fn struct clones 32 |
| 35 | arm9/mcss.c | 113 | raw offsets 13, volatile (hw reg) 4, volatile (other) 3, 64-bit params 12, dup symbol rows 57, per-fn struct clones 24 |
| 36 | ov110/pms_select_graphic.c | 113 | raw offsets 1, volatile (hw reg) 8, dup symbol rows 57, per-fn struct clones 47 |
| 37 | ov119/pokemontrade_proc.c | 113 | fn-ptr casts 1, raw offsets 3, volatile (hw reg) 5, 64-bit params 1, dup symbol rows 66, per-fn struct clones 37 |
| 38 | ov135/worldtrade_box.c | 111 | fn-ptr casts 3, volatile (hw reg) 4, volatile (other) 7, dup symbol rows 83, per-fn struct clones 14 |
| 39 | ov216/beacon_detail_gra.c | 111 | fn-ptr casts 4, raw offsets 1, volatile (hw reg) 10, volatile (other) 3, dup symbol rows 83, per-fn struct clones 6, settings pragmas 4 |
| 40 | ov099/unit_021BD8D8.c | 110 | fn-ptr casts 1, volatile (hw reg) 4, dup symbol rows 51, per-fn struct clones 52, unprototyped/K&R 2 |

## Unprototyped and K&R entries (may be legitimate)

499 entries in 124 files. First 40:

- arm9/app_taskmenu.c: decl: func_02166C7C
- arm9/btl_setup_p01.c: decl: func_0203516C
- arm9/button_man_p03.c: empty-paren def: SPLRandom_Next
- arm9/net_err.c: decl: func_0203CF5C
- arm9/pokeparty.c: decl: func_020185F0
- ov009/unit_02164D64.c: decl: func_02731BF8
- ov009/unit_02164D64.c: decl: func_02731D6C
- ov009/unit_02165B80.c: decl: func_02703250
- ov009/unit_02166384.c: decl: func_02731E50
- ov009/unit_02166680.c: decl: _s32_div_f
- ov009/unit_0216AB20.c: decl: func_0216E5B0
- ov009/unit_0216AB20_p02.c: decl: func_0216E5B0
- ov009/unit_0216C858.c: decl: func_02174C2C
- ov009/unit_0216C858.c: decl: func_02174C30
- ov009/unit_0216C858.c: decl: func_02174CF0
- ov009/unit_0216C858.c: decl: func_02174CF8
- ov009/unit_0216C858.c: decl: func_02174D04
- ov009/unit_0216F014.c: decl: func_021763AC
- ov009/unit_0217FD7C.c: decl: func_021C2304
- ov009/unit_0217FD7C.c: decl: func_021C2338
- ov009/unit_0218A1D0.c: decl: func_02094694
- ov009/unit_0218E3B0.c: decl: func_02189644
- ov009/unit_02194AD8.c: decl: srand
- ov009/unit_02194AD8.c: decl: rand
- ov009/unit_02194AD8.c: decl: strlen
- ov009/unit_02194AD8.c: decl: gti2VerifyChallenge
- ov009/unit_02194AD8.c: decl: abs
- ov009/unit_02195B44.c: decl: gt2StringToAddress
- ov009/unit_02195B44.c: decl: gti2NewOutgoingConnection
- ov009/unit_02195B44.c: decl: gti2StartConnectionAttempt
- ov009/unit_02195B44.c: decl: gti2FreeSocketConnection
- ov009/unit_02195B44.c: decl: gt2Think
- ov009/unit_02195B44.c: decl: msleep
- ov009/unit_02195E80.c: decl: gti2CheckResponse
- ov009/unit_02196C34.c: decl: gti2SocketFindConnection
- ov009/unit_02196C34.c: decl: gti2DumpCallback
- ov009/unit_02196C34.c: decl: memcmp
- ov009/unit_02196C34.c: decl: gti2BufferShorten
- ov009/unit_02198620.c: decl: strchr
- ov009/unit_02198620.c: decl: memcpy

## Goto into loop

- ov016/unit_021D0B44.c: next, next, next
- ov172/camera_system.c: test
- twl/unit_02700078.c: entry

## Settings pragmas by name

- opt_propagation: 37
- opt_lifetimes: 19
- opt_common_subs: 18
- opt_loop_invariants: 6
- opt_dead_assignments: 4
- explicit_zero_data: 2
- unused(data): 1
- unused(tag,: 1
- pack(4): 1
- pack(): 1

## Duplicate address rows (first 20)

- 0x02004490: SVC_WaitByLoop, func_02004490
- 0x02004632: SVC_GetCRC16, func_02004632
- 0x02004EB0: OSi_ReferSymbol, func_02004EB0 (one name since the crt0 merge: OSi_ReferSymbol)
- 0x02005624: func_02005624, sub_02005624
- 0x020056A0: func_020056A0, sub_020056A0
- 0x020056BC: func_020056BC, sub_020056BC
- 0x020056EC: func_020056EC, sub_020056EC
- 0x02005924: func_02005924, sub_02005924
- 0x02005C28: func_02005C28, sub_02005C28
- 0x02005D28: func_02005D28, sub_02005D28
- 0x02005D90: func_02005D90, sub_02005D90
- 0x02005E50: func_02005E50, sub_02005E50
- 0x02005F38: func_02005F38, sub_02005F38
- 0x02006148: func_02006148, sub_02006148
- 0x020061E4: func_020061E4, func_020061E4_2, sound, sub_020061E4
- 0x02006224: func_02006224, sub_02006224
- 0x02006BD0: func_02006BD0, sub_02006BD0
- 0x020071CC: func_020071CC, sub_020071CC
- 0x020071EC: func_020071EC, sub_020071EC
- 0x0200725C: func_0200725C, sub_0200725C
