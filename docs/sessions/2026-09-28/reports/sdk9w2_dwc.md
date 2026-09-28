# sdk9w2_dwc report

Territory: 11 arm9 SDK rows (libdwcac, libdwcaccount, libdwcbm, libdwccommon). Result: 6 filed
(EXACT or EXACT*, 1,748 bytes), 1 MATCH left in pending (code identical, one literal has no
witness), 4 DIFF left in pending. No `.c` or `.h` under `sdk/` was opened. All work came from
`tools/sdkobj.py`, `match.py show/one` and the permuter.

## Verdicts

Every `status:` is copied from `manifest --verify --shard arm9/pkt_<ADDR>`. Each shard was
verified twice, and the second pass rewrote 0.

| address | symbol (object) | bytes | verdict |
|---|---|---|---|
| 0x0205B148 | DWCi_AC_CallBackWCM (callback.o) | 156 | EXACT |
| 0x0205B1E4 | DWCi_AC_CloseNetwork (close.o) | 128 | EXACT |
| 0x0205AF5C | SortList (beacon.o) | 492 | EXACT |
| 0x0205EB30 | decodeSSID (shop_usb.o) | 252 | EXACT |
| 0x02059CBC | DWC_Base64Decode (dwc_base64.o) | 348 | EXACT* (listing extent 664 vs 348) |
| 0x02059588 | DWCi_Acc_CreateTempLoginId (dwc_account.o) | 188 | EXACT, **compiled with dsi/1.2** (see below) |
| 0x0205B2F8 | CloseSocket (close.o) | 68 | MATCH, pending |
| 0x02059FA8 | DWCi_Init (dwc_init.o) | 356 | DIFF 15, pending |
| 0x02058904 | DWCi_BACKUPlConvWifiInfo (dwc_backup.o) | 204 | DIFF 67 (was 99), pending |
| 0x02058E20 | DWCi_AUTH_RemakeWiFiID (util_wifiidtool.o) | 404 | DIFF 189, pending |
| 0x02058BC0 | DWCi_AUTH_GetNewWiFiInfo (util_wifiidtool.o) | 456 | DIFF 250, not reworked |

## Files and shards

- Matched: `src/matched/arm9_sdk/func_{0205B148,0205B1E4,0205AF5C,0205EB30,02059CBC,02059588}.c`
- Shards (all new): `layout/matched/arm9/pkt_{0205B148,0205B1E4,0205AF5C,0205EB30,02059CBC,02059588}.json`
- Pending deleted (each replaced by the matched file above): `func_0205B148.c` and `func_0205B1E4.c`
  (older drafts; I did not read them and wrote both from the object), plus `func_0205AF5C.c`,
  `func_0205EB30.c`, `func_02059CBC.c` and `func_02059588.c`.
- Pending overwritten: `func_0205B2F8.c`, with my own draft from the object (the older draft was not
  read); `func_02058904.c`, with the better 67-byte spelling; `func_02058E20.c` and `func_02059FA8.c`,
  with extended notes lines only.
- Scratch: `scratchpad/sdk9w2_dwc/`.

No asm bodies.

## What closed each one

- **SortList**: the fix was not a goto. The WPA branch had to be spelled
  `if (rssi_no < rssi_i) { if (!WPA(i)) swap = 1; } else swap = 1;`, and the type-range branch had to
  put its two leaves in one condition, `if ((type_i in 0x13..0x16) || sum == 0) swap = 1;`. The
  third branch stays as it was. I found this by brute-forcing 36 branch-shape combinations
  (`scratchpad/sdk9w2_dwc/sort2.py`). A real goto label reproduces the shared block, but it
  disturbs register allocation (the hoisted constant 1 is lost).
- **decodeSSID**: both indices are set from `i` independently (`destnum = (u8)i; srcnum = (u8)i;`).
  The loop tests `ctable_inv[srcnum]` and reads the table twice through different variables:
  `dest = buf[ct[srcnum]]; buf[ct[destnum]] = src; destnum = ct[srcnum]; ct[srcnum] = 0xff;
  srcnum = destnum; src = dest;`. If either index is initialised from the other, mwcc merges the
  two registers.
- **DWC_Base64Decode**: `required_dstsize = (int)(required_dstsize / 8);`. The redundant cast gives
  the division result its own register (ip) and moves the counter to r5, with i in r6. I also
  dropped the block-local `char c`, which is not in the DWARF.
- **CallBackWCM / CloseNetwork**: plain first-attempt C (a switch on `parameter[1].n`, and an
  if/else-if phase chain).

## DWCi_Acc_CreateTempLoginId filed with dsi/1.2 (integrator: please confirm the policy)

The residue under 1.1p1 is 4 bytes, and no spelling closes it: 20+ spellings plus permuter seed 13304
(1,500 compiles) all stay 4 bytes out. The unchanged source compiles EXACT under dsi/1.2, 1.2p1,
1.2p2, 1.3 and 1.3p1, and DIFF under 1.1, 1.1p1, 1.6sp1 and 1.6sp2. The object's stamp is
4.0.0.1025, which sits between 1.1p1 (1024) and 1.2 (1026) in `sdkobj.py`'s table, so a
1.2-family codegen is a defensible reading of the object. The header says `compiler: 1.2` and the
shard records `dsi/1.2`. If the project rule is that 1025 objects must build with 1.1p1, move this
file back to pending (the 1.1p1 residue is the `ldr r1, [r4, r2, lsl #2]` indexed load).

Lead: other 1025-stamped near misses in any DWC lane may close the same way under 1.2. For this
lane's remaining near misses I checked, and none moved: 0x02059FA8, 0x02058904, 0x02058E20 and
0x02058BC0 give the same counts under 1.2, 1.2p1 and 1.3.

## Near misses left in pending

- **0x0205B2F8 CloseSocket, MATCH**: the code bytes are identical. The ABS32 literal
  SOCLiConfigPtr (0x021A1CD8) has no witness outside the function. Only an ov009 literal-pool word
  refers to it, and overlay pool words are not admitted as evidence. This closes as soon as a
  matched arm9 entry, an sdk-table row or a data-object entry covers 0x021A1CD8.
- **0x02059FA8 DWCi_Init, 15 bytes**: the two inlined host-name copies still evaluate src before
  dst. I tried string-literal struct casts, local and static struct initialisers, compound
  literals, inline copy helpers with either parameter order, switch forms, `strcpy` with restrict
  prototypes, `__builtin_strcpy`/`__builtin_memcpy` (these emit calls, not the inline copy), and
  every dsi compiler. Permuter seed 13302 found nothing. The object's pool order is dst first in
  both copies.
- **0x02058904 ConvWifiInfo, 67 bytes (from 99)**: `tmp = (u64)info->notAttestedId` gives the two
  plain ldr/str. What remains is scheduling after the first MI_CpuCopy8: the object computes
  `tmp >> 5` before the Wifi[5] byte. A volatile read reaches 59 but is not the right shape.
  Permuter seed 13303 (1,500 compiles) found nothing.
- **0x02058E20 / 0x02058BC0**: the multiplier and addend 0x5D588B65 and 0x269EC3 are
  MATHRandContext16's. The object keeps mul in r6 and add in r7 (loaded once, before the first
  step) and the state in r4, which fits an inlined `{x, mul, add}` context. Writing it with local
  MATH_InitRand16/MATH_Rand16 inlines changes nothing (189), because mwcc propagates the constant
  fields. The next attempt should make mul/add opaque to constant propagation while keeping the
  same code, or restructure so the first step sits inside the loop's preheader.

## Catalog / DWARF notes

- CloseNetwork calls DisConnectAP (0x0205B264), which is matched as
  `src/matched/arm9_sdk/DisConnectAP.c` under a symbol name, not `func_`. I declared it as
  `func_0205B264`, and it resolved by label.
- DWC_Base64Decode: DWARF gives `char *src`, and the draft keeps `const char *`. This is harmless
  to the bytes.

## Next pass

Take 0x02058E20 and 0x02058BC0 together (same RNG shape), then 0x02059FA8 and 0x02058904. Settle
the dsi/1.2 policy for 1025 objects first; if 1.2 is accepted, re-run the other DWC lanes'
leftovers under it.
