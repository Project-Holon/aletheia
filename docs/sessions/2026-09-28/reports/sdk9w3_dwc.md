# sdk9w3_dwc report

Territory: 4 arm9 SDK rows in libdwcbm and libdwccommon. Result: 3 filed EXACT (1,216 bytes) and 1 left
in pending (DIFF 62, down from 67). No `.c` or `.h` under `sdk/` was opened. All work came from
`tools/sdkobj.py`, `match.py show/one`, the permuter, and the string table of the compiler binary.

All three objects are stamped 4.0.0.1025. Each one reproduces with unchanged source under dsi/1.1p1
(1024), so every header says `compiler: 1.1p1`.

## Verdicts

Every `status:` is copied from `manifest --verify --force --shard arm9/pkt_<ADDR>`. Each shard was
verified twice, and the second pass rewrote 0.

| address | symbol (object) | bytes | verdict |
|---|---|---|---|
| 0x02058E20 | DWCi_AUTH_RemakeWiFiID (util_wifiidtool.o) | 404 | EXACT (dsi/1.1p1) |
| 0x02058BC0 | DWCi_AUTH_GetNewWiFiInfo (util_wifiidtool.o) | 456 | EXACT (dsi/1.1p1) |
| 0x02059FA8 | DWCi_Init (dwc_init.o) | 356 | EXACT (dsi/1.1p1) |
| 0x02058904 | DWCi_BACKUPlConvWifiInfo (dwc_backup.o) | 192 | DIFF 62 (was 67), pending |

## Files and shards

- Matched: `src/matched/arm9_sdk/func_02058E20.c`, `func_02058BC0.c`, `func_02059FA8.c`
- New header: `src/matched/arm9_sdk/libc/string.h`. This is my own two-prototype declaration
  (`strcpy`, `memcpy`, `size_t`). It is not SDK text. See DWCi_Init below. **Integrator: please
  confirm this placement.**
- Shards (all new): `layout/matched/arm9/pkt_02058E20.json`, `pkt_02058BC0.json`, `pkt_02059FA8.json`
- Pending deleted, each replaced by the matched file above: `src/pending/arm9_sdk/func_02058E20.c`,
  `func_02058BC0.c` and `func_02059FA8.c`. These were this session's earlier object-derived drafts. The
  matched files continue them.
- Pending overwritten: `src/pending/arm9_sdk/func_02058904.c` (62-byte spelling and a new notes line).
- Scratch: `scratchpad/sdk9w3_dwc/`.

No asm bodies.

## What closed each one

- **RemakeWiFiID / GetNewWiFiInfo (the LCG)**: I did not need a context struct, a volatile or an
  extern const. Two changes were enough, and both functions took them unchanged:
  1. **Statement order.** Compute `vend` and `macDW3` *before* the first step and the `pass` store:
     `vend = ...; macDW3 = ...; seed = (u32)seed * 0x5D588B65 + 0x269EC3; wifiinfo->pass = ...;`.
     With that order, mwcc loads mul/add once into r6/r7 before the first `mla` and the loop reuses
     them. With the step written first, it reloads them in the loop preheader. This alone took
     RemakeWiFiID from 189 to 88 bytes.
  2. **Inner loop shape.** Write the loop as a peeled while:
     `seed = STEP; while (cond) { seed = STEP; }`, not a do-while. For RemakeWiFiID the condition
     is `(u32)seed == 0 || wifiinfo->randomHistory == (u16)seed`, which gives the object's
     `b` to the next instruction plus the separate `mla`/`cmp`. For GetNewWiFiInfo it is
     `(u32)seed == 0`, which gives the duplicated `mul`/`adds` test.

  `seed` stays the DWARF `long long`, and no inline helper is needed. The two-shift `pass`
  expression is `(u16)((((u32)seed >> 16) * 1000) >> 16)`.
- **DWCi_Init**: the two host-name copies are real `strcpy(StatsServerHostname, "literal")`
  calls, which mwcc expands inline as a strlen+1 block copy. It evaluates the destination first,
  as in the object. mwcc does this only when `strcpy` is declared in a header whose file name is
  `string.h` (the binary carries the list `string.h,cstring,memory.h`).
  - A prototype in the .c gives a real call (66 bytes). So do `#line 1 "string.h"`, a header
    named `foo.h`, and `#pragma inlineintrinsics`/`block_assign`.
  - `#include "inc/string.h"` works, so the check is on the file name only, whatever directory
    the header is in.
  - The file includes `"libc/string.h"`, which `match.py` finds through its `-ir <src dir>`.
  - The symbols block declares the two literal templates as `@16103 0x020A8070 data a1` and
    `@16104 0x020A8084 data a1`.
  - With this spelling, StatsServerHostname (0x021A5850) now resolves as `sole-ref`. The
    previous report said it had no witness.

## Near miss left in pending

- **0x02058904 DWCi_BACKUPlConvWifiInfo, 62 bytes**: the Wifi[5] byte is now written
  `((tmp & 0x1F) << 3) | ((info->attestedUserId >> 40) & 7)` (operands swapped: 67 to 62).
  - **Residue:** after the first MI_CpuCopy8, the object computes `tmp >> 5` into ip/lr first,
    then the byte from r2. It stores both halves of tmp after the `strb`. Our build stores the low
    half before it. The first block also loads `info->notAttestedId` before the Wifi literal.
  - **Stayed at 62:**
    - 48 spellings: tmp load × first-copy arguments × shift form (`scratchpad/sdk9w3_dwc/cv2.py`)
    - 96 byte-expression variants (`cv.py`)
    - opaque-store casts of Address (`((u8 *)&Address)[9]` etc.)
    - dsi/1.1, 1.2, 1.2p1 and 1.3
  - **Worse:** TU-static `Address`/`Wifi` gives 137. mwcc does not rebuild the Address+9 base
    that way, so the struct overlay stays.
  - **Permuter:** seed 13701 (2,000 compiles) found no byte gain.
  - **Hypothesis for the next pass:** the object keeps the two tmp stores adjacent, as if the
    64-bit store of the shift result were one unit ordered after the Wifi[5] store. Look for a
    spelling that makes the shifted value a single expression stored after the byte.
- Its listing extent is 204 bytes, but the function is 192. The last 12 bytes are the next
  function, so a close would verify as EXACT*.

## Catalog / DWARF notes

- The DWARF for dwc_backup.o declares `Wifi` and `Address` as separate statics. The object
  addresses Wifi[5], [10] and [11] off Address's literal (+9, +0xE, +0xF). The pending draft keeps
  the `{Address; Wifi[14]}` overlay struct for that.
- OS_IsTickAvailable (0x02087058) is catalogued as `sdk GX_GetBankForLCDC`, and RTC_GetTime
  (0x0208890C) as `sdk RTC_GetDate`. Both resolve by label, but the catalog names look wrong.

## Next pass

- **0x02058904**, from the hypothesis above. The unused permuter seeds are 13702 to 13799.
- **Strcpy lead for other lanes:** the `libc/string.h` finding is general. Any SDK or DWC function
  whose object has an inline byte-copy loop from an `@N` string literal is probably
  `strcpy(dst, "lit")` (or `memcpy`) declared through a header named `string.h`.
