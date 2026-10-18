# Naming standards

Rules for the renaming phase. Every rule below comes from names that the
game binary itself contains. Rules marked (inferred) extend that evidence.

## Evidence

| Source | What it gives | Count |
|---|---|---|
| Assert expression strings (`tools/assertnames.py`) | Original identifiers: locals, fields with struct path, constants, file statics | 31 distinct strings, 42 pool references, 35 functions, all in arm9 (none found in overlays) |
| `layout/file_anchors.txt` | Source file base names (`__FILE__`), no directories | 564 distinct names, 1056 anchors; all end in `.c` |
| `layout/symbols_sdk.json` | Real SDK/library names matched to library objects | 4771 symbols |

Run `python tools/assertnames.py --out FILE` to regenerate the assert table. It
prints region, string address, referencing function, expression and the
identifiers in it. The output holds expression text, so keep it out of git.

Limits: the 31 asserts cover only the save system (`savedata.c`,
`backup_system.c`, `flash_access.c`) and the network library (`net*.c`).
Asserts without an operator (for example `assert(sv)`) are not found by the
tool. One string is cut short in the ROM: `_BaseTable.listNum > co`. The overlays
hold no assert strings of this form, so the naming style of game code
(fields, battle, scripts) is known only from file names.

## Rules for source file names

Evidence: 557 names.

| Rule | Evidence |
|---|---|
| Lowercase ASCII, digits, `_` as the only separator, extension `.c` | 555 of 557 are all lowercase; 0 contain `-`; 0 have a directory part |
| Two exceptions keep camel case: `double3Ddisp.c`, `ghttpEncryption.c` | Keep them as they are |
| Shape is `module.c` or `module_part.c` or `module_part_part.c` | 75 one-part, 337 two-part, 133 three-part, 12 four-part |
| The first token is the module prefix | see table below |
| Last token names the role | `sys` 22, `graphic` 22, `data` 10, `tool` 9, `main` 9, `menu` 9, `system` 8, `util` 6 |
| `_data` files hold tables, `_graphic` files hold display setup, `_sys` or `_main` hold the module core | from the counts above |
| Digits stay glued to the word: `box2_main`, `demo3d`, `wf2dmap_map`, `guru2_comm`, `fld3d_ci` | no digit has its own token |

Module prefixes (first token, count of files):

| Prefix | Files | Area | Examples |
|---|---|---|---|
| `field` | 41 | field map | `field_camera`, `field_encount` |
| `fldeff` | 17 | field effects | `fldeff_d06denki` |
| `btlv` | 16 | battle view | `btlv_core`, `btlv_camera` |
| `net` | 13 | network | `net_system`, `net_handle` |
| `scrcmd` | 13 | script commands | `scrcmd_shop`, `scrcmd_work` |
| `btl` | 12 | battle logic | `btl_server`, `btl_calc` |
| `br` | 12 | battle recorder | `br_btn`, `br_main` |
| `event` | 12 | events | |
| `pokemontrade`, `zukan` | 11 each | trade, Pokedex | |
| `fld` | 9 | field helpers | `fld_trade`, `fld_scenearea` |
| `sta` | 9 | musical staging | `sta_acting`, `sta_act_bg` |
| `g3d`, `gf`, `mb`, `pms` | 4, 3, 4, 6 | 3D, GF library, multiboot, easy chat | `g3d_system`, `gf_overlay` |

Compound prefixes exist: `b_plist_*`, `b_bag_*` (bag/party screens in battle),
`p_sta_*` (status screen), `c_gear*` (C-Gear), `scrcmd_*`, `wf2dmap_*`,
`field_wfbc_*`. A prefix with one underscore is still one module token.
75 files have no underscore (`savedata.c`, `procsys.c`, `net.c`, `mcss.c`):
the module is the whole name.

Rule for new file names: reuse the module prefix of the nearest anchored file;
keep it lowercase; add one role token at the end if the module has more than
one file.

## Rules for SDK and library names (keep real names)

Do not rename a symbol that is in `layout/symbols_sdk.json`. The real names are
the names. Conventions, from the 4456 symbols counted before the twl rows were added (4771 now):

| Pattern | Count | Meaning | Examples |
|---|---|---|---|
| `PREFIXi_Name` (upper prefix, lowercase `i`) | 1548 with a lowercase tag | internal to the library | `DWCi_` 800, `NHTTPi_` 117, `OSi_` 73, `MBi_` 67, `SOCLi_` 66, `FSi_`, `CRYPTOi_`, `CPSi_`, `CARDi_`, `WCMi_` |
| `DWCs_` | 14 | static-linkage variant | `DWCs_GetRequiredHeaderSize` |
| `PREFIX_CamelCase` | 987 | public API: prefix, then verb, then object | `OS_SendMessage`, `DWC_ShutdownGHTTP`, `RTC_GetDateTime`, `NHTTP_WaitForConnection` |
| `GX_`, `G3X_`, `GXS_`, `MTX_`, `VEC_`, `FX_` | 84, 16, 19, 31, 13, 14 | graphics and math | |
| `NNS_` | - | not present in the matched set | |
| `Wcm`, `Wm`, `Yos` (CamelCase, no underscore) | 21, 11, 12 | older Nintendo network code | |
| `gp`, `gs`, `gh`, `sake`, `sc`, `gpi`, `ghi`, `gsi` plus camelCase | about 970 | GameSpy library: lowercase module tag, `i` suffix for internal | `gsXmlWriteDateTimeElement`, `gpiProfileMap`, `sakei` |
| lowercase snake and plain CamelCase | about 650 | third-party support code (BSD sockets, DHCP, base64) | `enum_local_ips`, `db64`, `string_put_char` |

Verbs seen after the prefix: `Get` 230, `Set` 163, `Init` 91, `Is` 81, `Send`
53, `Check` 41, `Read` 40, `Load` 40. The internal `i` is part of the prefix,
never a separate token: write `DWCi_InitReliableQueue`, not `DWC_i_Init...`.
Game code must not use these prefixes.

## Rules for game functions

GF style, from the file names and the network asserts: module prefix, then
verb, then object.

1. Module prefix: the first token (or compound prefix) of the file's anchor
   name, used for every function of the file group: `btl_server.c` and
   `btl_server_flow.c` both use `btl_`/`BTL_`. The one library with observed
   function-style evidence is the network code, which uses the library tag
   `GFL_NET_` in constants and `net_` in file names.
2. Case: the evidence has two styles. (a) Network library: `GFL_NET_Verb`
   (upper module, camel verb). (b) Save system: snake_case locals and fields.
   Pick one per function kind: functions `MODULE_VerbObject` (matches (a)
   and the SDK), constants `MODULE_NAME`, data fields snake or camel as in the
   field table below (inferred).
3. Module per file: use the anchor file name of the nearest function (same unit
   in `layout/file_anchors.txt`). If the unit has none, use the module of the
   functions that call it most (inferred).
4. Verb: from behaviour, first word `Init`, `Exit`, `Get`, `Set`, `Is`,
   `Check`, `Create`, `Delete`, `Main`, `Proc` (inferred, same verbs as the SDK
   list).
5. Decided 2026-10-12 (owner): game functions use an upper-case module
   prefix, then a CamelCase verb and object: `MODULE_VerbObject`. The module
   is the file name in upper case with its underscores kept.
6. Examples: `field_effect.c` gives `FIELD_EFFECT_Init`; `savedata.c` gives
   `SAVEDATA_GetWork`; `btl_calc.c` gives `BTL_CALC_*`; `scrcmd_shop.c` gives
   `SCRCMD_SHOP_*`; network library functions keep `GFL_NET_*`.

## Rules for struct types, fields, locals, statics and constants

Observed identifiers, with the struct offset the function reads (decoded from
the load or compare nearest to the assert in the arm9 listings).

Constants: `UPPER_SNAKE` with a module prefix.

| Name | Where | Evidence |
|---|---|---|
| `GFL_NET_MACHINE_MAX` | `netID < ...`, `maxConnectNum <= ...` | `cmp #8` in `0203D680` |
| `GFL_NET_HANDLE_MAX`, `GFL_NET_NETID_SERVER`, `GFL_NET_IRC_SEND_MAX` | `net_handle.c`, `net.c` | |
| `GFL_NET_TYPE_WIFI`, `_WIFI_LOBBY`, `_WIFI_GTS` | `bNetType` values | |
| `OS_LOCK_ID_ERROR` | `flash_access.c` | SDK name |
| `_HUGEDATA_DIFFBYTE`, `_COLLECTMAC_NUM` | file-local constants, leading `_` | `cmp #4` in `0203E484` |

Constants local to a file start with `_`; global ones start with the module tag.

File statics: `_p` + CamelCase for pointers (`_pNetState`, `_pBaseWork`,
`_pCommandWork`); `_CamelCase` for non-pointers (`_BaseTable`).

Locals and parameters: `netID`, `netId`, `index`, `sendID`, `id`, `gmdataid`,
`size`, `lock_id`, `next_frame`, `svwk_size`. Network code is camelCase;
save code is snake_case.

Hungarian prefixes: `p` pointer (`pNet`, `pNetIni`, `pNetInit`, `pTemp`), `a`
array (`aNetHugeRecv`, `aNetInit`, `aMacAddress`), `b` boolean-like or byte
(`bMPMode`, `bNetType`). Prefix letters apply to struct fields, not to
file names.

Struct types (inferred from variable names): the pointer `pNetIni` points to
`GFLNetInitializeStruct`-like data; a work variable `xxxWork` is a pointer to a
`xxxWork` struct; `sv`, `svsys`, `svdt` are pointers to save-system structs.

Field offsets decoded from the code (offset within the struct whose pointer the
named variable holds):

| Expression | Function | Offset | Basis |
|---|---|---|---|
| `sv->savearea_size` | `0203174C` | +0x08 (u32) | `ldr r0,[r4,#8]; cmp sl,r0` after the init stores to `+0..+0xC` |
| `svdt->table_max` | `02033A3C`, `02033B68` | +0x04 (u32) | `ldr r2,[r0,#4]; cmp r5,r2` |
| `pNetIni->bMPMode` | `020385C4` | +0x64 (u8) | `ldrb r0,[r5,#0x64]; cmp r0,#0` |
| `pNetIni->bNetType` | `020385C4`, `0203CA04` | +0x65 (u8) | `ldrb r1,[r5,#0x65]` |
| `aNetInit.maxConnectNum` | `0203D680` | +0x60 (u8) within `aNetInit` | `ldrb r0,[r4,#0x60]; cmp r0,#8` |
| `_pBaseWork->timingSend[i]` | `02039D94` | +0x10 or +0x18 (u8 array, 9 entries) | `ldrb [r1,#0x10]`, `ldrb [r1,#0x18]`, loop `cmp sb,#9` |
| `_pCommandWork->aNetHugeRecv[index].used` | `0203A958` | +0xCA (u8) from element base | `ldrb r0,[r0,#0xca]; cmp r0,#0` |
| `_pCommandWork->aNetHugeRecv[index].data` | `0203A958` | +0xBC (pointer) | `ldr r0,[r0,#0xbc]; cmp r0,#0` |
| `_BaseTable.listNum` | `0203A67C` | +0x04, table of 4 entries of 16 bytes | `ldr r1,[r0,#4]` with `r0 = base + r2<<4`, `cmp r2,#4` |
| `_pNetState->aMacAddress` | `0203B0C4` | +0x40 | `add r0,r0,#0x40` |
| `netLdataWork->postWork[netId]` | `0203E808` | +0x00 (pointer array) | `ldr r0,[r0,r6,lsl #2]` |
| `netLdataWork->sendData` | `0203E758` | +0x20 | `ldr r0,[r0,#0x20]` |
| `pTemp->num` | `0203E484` | +0x00 (u32, limit 4) | `ldr r0,[r4]; cmp r0,#4` |

These rows are the only places where a field name and its offset are both
known. Treat other fields at the same offsets as unnamed until another assert
or a behaviour argument names them.

## Name everything in one pass (user decision, 2026-10-13)
The cleanup pass names EVERYTHING it touches, so there is never a second
renaming round: every function, struct type, field, file static, local,
parameter and constant gets a descriptive name inferred from how the code uses
it (what is stored, compared, passed, returned, allocated, freed; callers and
callees; asserts; strings). Placeholders are not allowed: no `unkNN`,
`fieldNN`, `GetField5C`, `FuncXXXX`, `SlotHandlerDE8`, `pad_NN` (except true
padding nothing reads), or address-suffixed names. When the evidence is thin,
pick the best descriptive name anyway; it can be refined later, but it must
say what the thing does or holds. Something that looks odd is still named,
never left out; at most it gets an optional one-line note.
The only exception: functions that look like they belong to another original
file are left with their current name and flagged in misplaced.tsv (their home
file decides their module prefix).

## Conventions the cleanup lanes settled

| Kind | Form | Example |
|---|---|---|
| File static (variable) | `s` + PascalCase | `sFrameCounter` |
| Global | `g` + PascalCase | `gMessageTable` |
| Handler or callback table | `g<Name>Handlers` | `gBattleEventHandlers` |
| Struct field, local, parameter | camelCase | `partySlot`, `moveId` |
| Function | `MODULE_VerbObject` | `BTL_CALC_GetDamage` |
| Type | PascalCase, module word first | `BtlPokeParam` |

Battle handler prefixes (ov093, settled): ability handlers `HAND_TOKUSEI_`,
item handlers `HAND_ITEM_`, move handlers `HAND_WAZA_`. A handler is the
callback a battle event factor registers for one ability, item or move
(`HAND_WAZA_MagnitudeOnWazaStart`). The shared event variable keys are one enum,
`BtlEventVarKey`, in `hand_common_types.h`. Helpers shared by all three groups use
`HAND_COMMON_` (`hand_common.c`).

Field, position and side handlers (ov095) use `HAND_FIELD_`, `HAND_POS_` and
`HAND_SIDE_`; status condition code uses `BTL_SICK_`. Library code in game
overlays keeps the library style for internal names (`DWCi_` for DWC internals):
library prefix, then `i` for internal.

Wave 5 applied the same table to the remaining overlays. The module prefix of a
function comes from the name of the file that holds it (`vct.c` gives `VCT_`,
`irc_internal.c` gives `IRC_`, `worldtrade_*.c` files give `WORLDTRADE_`); data
objects follow the same rule with the `s` or `g` prefix in front of the module
word (`sVctWork`, `gIrcCommandTable`). Internal helpers of a file keep the module
prefix of the file, not the prefix of the caller.

Wave 6 applied it to the four small-overlay sweep blocks, ov094 btlv_input, ov119,
ov123, ov135, ov137, ov170, ov172, ov186, ov208, ov209, ov217 and the ARM9 os, mi,
heap, lib, save and sound clusters. The applied names fit the table above, so no
new convention was needed.

Wave 7 applied it to the remaining sweep blocks (ov095 to ov231), the ARM9
graphics cluster, the two logic groups, the filesystem, wifi and msl_c_lib
clusters, the remaining ov009 files, and the ov137, ov170, ov172, ov186 and
ov119 continuations. The applied names fit the table above, so no new convention
was needed.

Wave 8 applied it to the ten naming continuations (ov210-215, ov181-199,
ov203-207, ov216-222, ov223-231, ov111-118, ov115-121, ov127-134, ov132-198,
ov175-195), the ARM9 graphics, logic and wifi clusters, the remaining ov009
files named from the SDK symbol table, and the ov137, ov170, ov172, ov186,
ov119, ov209 and ov217 continuations. The applied names fit the table above, so
no new convention was needed. The same wave split 61 aggregated files into their
originals; each piece keeps the module prefix of the original it belongs to
(`ARC_TOOL_`, `ARC_UTIL_`, `MCSS_`, `WIFILOGIN_`, `STA_ACT_`), and a shared
`_types.h` header carries the types the pieces of one original share.

Wave 9 applied it to the 24 `Obj`-view lanes (ov112, ov121, ov128, ov129, ov133,
ov170, ov173, ov175, ov176, ov194, ov197, ov198, ov204, ov208, ov210, ov215,
ov223 and ov225, the two mixed rest blocks, and the arm9 and ov009
continuations), removing 5,052 view references and taking 12 regions to zero
views. The applied names fit the table above, so no new convention was needed.
The same wave added one owner header per region (ov211, ov215, ov204, ov198,
ov173, ov210, ov133, ov128, ov121) and split the last two aggregated originals:
ov133 into `dup_fitting.c` and `dup_fitting_item.c`, and arm9
`misc_savedata.c` into `misc_savedata.c`, `battle_examination.c` and
`misc_savedata_2.c`; each piece keeps the module prefix of the original it
belongs to.

Wave 10 applied it to the 22 `Obj`-removal lanes (ov093, ov112, ov116, ov121,
ov122, ov128, ov129, ov175, ov176, ov185, ov204, ov214, ov216 and ov225, the two
mixed rest blocks, and the arm9 and ov009 continuations), taking 15 regions to
zero views. The two opaque PROSYS spellings `struct Obj0203159C` and
`struct S020315D4` became the one name `struct Proc` across 886 references in 325
files. The applied names fit the table above, so no new convention was needed.
The same wave folded four standing per-file `*_shared_types.h` into their owner
headers and added three owner headers (ov176 `livebattlematch_shared_types.h`,
ov185 `br_pokesearch_types.h`, ov223 `psel_types.h`).

The wave 10 gap-fix lanes then merged arm9 `ui_p02.c` into one whole `ui.c` and
split the ov194 `namein_graphic` range into five originals at their real
boundaries (`namein_graphic_main.c`, `namein_graphic_field.c`,
`namein_graphic.c`, `namein_data.c`, `nsbtx_to_clwk.c`); each piece keeps the
module prefix of the original it belongs to, and no new convention was needed.

File names (rule used by the file-rename pass): the original file name when the
`__FILE__` anchors or the SDK object tables give it; otherwise a descriptive
snake_case name from the module prefix and role (`hand_waza.c`, `btl_client.c`).
Files of SDK and vendor objects keep their object name with its real case from the SDK symbol table (`os_irqTable.c`, `os_spinLock.c`,
`dwc_match.c`); a generic object name that clashes inside one overlay gets the
library word in front (`dwcutil_main.c`). No `unit_XXXXXXXX.c` name stays when
the evidence names the file; groups that tools/renamefile.py cannot merge are
numbered `<name>_<n>.c` in address order.

## How to apply

1. Assert-derived names first. For each function in the assert table, name the
   function for its file module, and give the variables, fields, statics and
   constants in the expression exactly the spelling above. Mark these as
   `evidence: assert`.
2. File names: apply the file rules; the anchor name of a unit is its file name
   unless the file is in the exceptions.
3. SDK functions keep their names from `layout/symbols_sdk.json`. Never rename
   them; never reuse their prefixes in game code.
4. Everything else: derive the name from behaviour with the module prefix of
   its file and a verb from the verb list. Record each as `inferred` in the
   rename table, with a one-line reason.
5. A name may change only to a name with stronger evidence (assert, anchor,
   SDK) than the current one.
6. No renames in `src/` happen before a rename table with the evidence level
   for each row exists.

## Open questions

- Case of game function names: decided as `MODULE_VerbObject` (rule 5 of
  the game function rules); the evidence alone does not prove it.
- Which of the offsets +0x10 and +0x18 is `timingSend` in `_pBaseWork`.
- Whether overlays contain asserts with no operator, or with a different
  macro; the tool finds none in overlays.
- The truncated string `_BaseTable.listNum > co` (maybe a length limit of the
  assert macro); other long expressions may be cut the same way.
- Whether file name case exceptions (`double3Ddisp`, `ghttpEncryption`) show
  third-party or older code.
- Directory structure of the original tree: `__FILE__` holds only the base name.

## Measured-unread fields (not naming debt)

Recorded by INT12 on 2026-10-16. These fields are written but read by no
function anywhere in `src/game`, `src/matched` or `layout`. They are
`reserved`/`pad` by measurement, not unnamed debt: the write site is known and
the absence of a reader was searched for tree-wide. They must not be reopened as
naming debt. Sources: `S/APL-1/measured_unread.tsv` and
`S/APL-2/measured_unread.tsv`.

| struct | field | offset | size | writer |
| --- | --- | --- | --- | --- |
| MysteryAlbumSlotWork | pokeBank | 0x9C | 4 | mystery_util.c (written 0/4) |
| BeaconDetailWork | wipeState | 0xC314 | 4 | BEACON_DETAIL_Update cases 0 and 20 |
| BeaconDetailWork | padC0B4 | 0xC0B4 | 0x228 | untouched gap; only MI_CpuFill8(p,0,0xc3bc) at init |
| BrDownloadOwner | downloadMode | 0x1C | 4 | BR_DOWNLOAD_HandleTouch (0/1); ov185 sibling ends at 0x18 |
| LightActor | paramA / paramB | 0x14 / 0x18 | 4 each | STA_ACT_LIGHT_SetElemB; no reader |
| WifiBattleMatchNetTask | field2C | 0x2C | 4 | none read in ov175/ov177/ov199 |
| WifiBattleMatchNetTask | postTimer | 0xE0 | 4 | only a zero store in TaskStepQ |
| CommBtlDemoArgs | pad48 | 0x48 | 4 | BuildSetupRecord; write-only |
| CommBtlDemoSide | pad08[0] | 0x08 | 1 | always 0 (MI_CpuFill8 of the 0x58 record) |
| CommBtlDemoSide | pad08[1] | 0x09 | 1 | written from recordVersion; no reader |
| WifiBattleMatchSysSetupOut | whole record | 0x00 | 0x50 | FillSetupRecord at p+0x1d0; no reader |
| WifiBattleMatchSysWork | setupRuleValue / setupRecordVersion | 0x1B4 | 8 | ApplySetup; passed as FillSetupRecord `other`, never read |

## Stale references (the corrected rename status)

Recorded by INT14 on 2026-10-16. Every rename check before this one counted only
DEFINITIONS (the brace parser over `src/game`, `countall.py`, the `function:`
lists), so it reported renaming done while the tree still held `func_NNNN` names
used as REFERENCES. A reference is a hand-written `extern` prototype, a
file-scope prototype, a call site or a `symbols:`/`function:` header row whose
name is `func_XXXXXXXX` or `sub_XXXXXXXX` while a real name exists at that
address.

INT14 re-measured over `src/game` (`S/INT14/measure.py`, output
`S/INT14/stale_refs.tsv`), resolving a name against the region of the file that
holds it and falling back to arm9 (overlays call arm9 functions). Unlike an
address-only scan this does not cross regions: overlays share the address space,
so an address-only index mixes a name from another overlay into the count. The
figures:

- 1,544 distinct `func_`/`sub_` names are used in `src/game`;
- 1,033 are STALE (a different, real name exists at that address);
- 412 are UNKNOWN (no name at that address);
- 36 are GENUINE (the name matches the address);
- 21,441 occurrences in 8,453 `(name, region, kind)` rows.

The raw address-only count is 1,096 stale; the 63-name difference is the
cross-region false positives (the address holds a name in another region while
the name is still correct in the region that references it). Report the
region-corrected 1,033 as the stale figure and the 1,096 as the raw count.

111 names are blocked and must not be renamed as a plain reference fix:

- 99 naming gaps: the target name is still `unit_XXXX`/`sub_XXXX`/`func_XXXX`,
  so there is no correct name to move to yet; name the definition first.
- 2 ambiguous addresses: the address carries a different name in another region
  and the name is referenced from more than one region, so a name-keyed rename
  is ambiguous; apply per file.
- 10 accepted-duplicate names (the same vendor symbol at two addresses):
  `sdkrename.py` refuses the second region; keep both.

Applying the renames is byte-neutral: they are identifier changes to
declarations and call sites, and a one-file test batch (`func_02030734` ->
`GFL_HEAP_Alloc` and `func_020307B0` -> `GFL_HEAP_Free` in `arm9/net_save.c`)
kept the file EXACT. Wave 14 applies the unblocked rows in three batches with
`tools/sdkrename.py` (map columns `old, new, address, region`), verifying each
changed file after the batch; the tree must be quiet because the tool edits every
caller.

### Result (2026-10-18)

All stale references are renamed. `src/game` holds no `func_XXXXXXXX` or
`sub_XXXXXXXX` name, in code, header rows, comments or folder notes. Every
changed file stays EXACT.

How the last names were closed:

- Names were resolved per region. A file's own region comes first, then the
  overlays the file's `symbols:` rows show as loaded with it, then arm9.
  Overlays are not all loaded at the same time, so this removes most ambiguous
  addresses.
- Where a name had two signatures, the wrong prototype was fixed (the SDK or
  GameSpy signature, one prototype per file). A second name was not added.
- The `DWCi_IsFold` copies in ov016 are each scene object's own static helper.
  Each copy now starts the file that calls it.
- Three entries were not functions: `sub_02011292` and `sub_020113D2` (bytes
  inside `VM_End` and `VM_SetWait`) and `func_02050084` (a label on the final
  `bx lr` of a getter in `arm9/particle.c`). They were removed from the matched
  layout, so the function count is 3 lower.
- One second name stays on purpose: `MIi_CpuClearFastAlias` in
  `ov013/vct_main.c` is a second extern for `MIi_CpuClearFast` (0x02082AC0).
  The original has two calls to that address in `VCT_SESSION_MixVoices`; with
  one name mwcc merges them and the code is 4 bytes short on every compiler
  build. See
  `docs/idioms/a-duplicated-pool-word-is-a-second-extern-name-for-the-same-address.md`.
