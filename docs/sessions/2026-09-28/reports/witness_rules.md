# witness_rules: vendor-object evidence rules in match.py, crt0 stub seed

Tooling lane. Files owned: `tools/match.py`, `layout/function_starts.txt`. No
`.c`/`.h` under `sdk/` was opened; vendor objects were read only through
`tools/sdkobj.py` (member symbols, relocations, section bytes).

## Common precondition (all three rules)

`vendor_function(place)`: the function under test has exactly one
`layout/symbols_sdk.json` row at `place` in region `arm9`, and
`sdkobj.locate()` finds that row's member with **0 concrete mismatches**
against the image (every byte outside the member's own relocation fields
agrees). Only then is the member's relocation table read as a statement about
the image. The member's relocation at the site's offset must be ABS32, like
ours. Every rule is tried only after `attest()` has refused the site.

## Rule 1: `linker` (new evidence class, `attest_linker()`)

Acceptance test, all of:

1. our relocation's symbol is named `SDK_[A-Z0-9_]+`, addend 0;
2. the member's relocation at the same offset is against an **undefined**
   symbol (shndx 0) of the same name, addend 0;
3. no member of the member's archive defines that name (so only the linker
   supplies it);
4. the value is proven, never from the word under comparison:
   - (a) if `LINKER_LAYOUT` has a derivation for the symbol, the derivation
     from `layout/layout.json` must equal the declared value; a disagreeing
     derivation refuses outright;
   - (b) otherwise, other ARM9 rows of the same archive, each located with 0
     mismatches, relocate the same symbol (ABS32, undefined, addend 0) at
     slots outside the compared range, and the image word at every such slot
     equals the declared value (one disagreeing slot refuses; no slot refuses).

`LINKER_LAYOUT` (the only layout derivations accepted):

| symbol | derivation | value |
|---|---|---|
| SDK_OVERLAY_NUMBER | `counts.overlays`, which must equal `len(overlays)` | 237 (0xED) |
| SDK_LTDAUTOLOAD_LTDMAIN_START | `twl.ram_start` | 0x02700000 |
| SDK_LTDAUTOLOAD_LTDMAIN_BSS_END | `twl.bss_end` | 0x02735B40 |

Accepted symbols in this change:

| site | symbol | how the value is proven |
|---|---|---|
| FS_LoadOverlayInfo 0x02078D34 +0x174 | SDK_OVERLAY_NUMBER = 0xED | layout (a) |
| FS_StartOverlay 0x0207902C +0x120 | SDK_LTDAUTOLOAD_LTDMAIN_START = 0x02700000 | layout (a) |
| FS_StartOverlay 0x0207902C +0x124 | SDK_LTDAUTOLOAD_LTDMAIN_BSS_END = 0x02735B40 | layout (a) |
| OS_InitThread 0x02085264 +0x120 | SDK_SYS_STACKSIZE = 0x1800 | (b): os_arena.o OS_GetInitArenaHi relocates it at 0x02086684 |
| OS_InitThread 0x02085264 +0x124 | SDK_SECTION_ARENA_DTCM_START = 0x02FE00C0 | (b): OS_GetInitArenaHi 0x0208668C and OS_GetInitArenaLo 0x02086758 |

The suggested extension of the ARM9 `literal` class to unlabelled pool
continuation words was **not** implemented. It is not needed (prong (b) reads
exactly those words, but only where the vendor object says which symbol they
are), it would not have reached 0x02086758 anyway (OS_GetInitArenaLo's pool is
an unlabelled `.word` run with no `pool_` label), and for small linker
constants such as 0x1800 a value match in some pool is precisely the
coincidental-value evidence the project refuses. It would also move figures
project-wide.

Negative self-tests: 0xEC for SDK_OVERLAY_NUMBER; the twl bounds swapped
between the two FS_StartOverlay slots; a slot the member relocates against
another symbol (FSiOverlayContext, +0x170); 0x1000 for SDK_SYS_STACKSIZE;
the other row's slot inside the compared range; a non-`SDK_` name
(OSi_ThreadInfo); a game function with no SDK row (0x02005E50).

## Rule 2: `template` (new evidence class, `attest_template()`)

Header syntax: a `symbols:` line whose name is the **vendor member's** `@N`
(the only stable spelling, since our compile's `@M` number differs), e.g.
`@12151  0x020A5CB8  data`. Any relocation whose name is `@N` is routed to this
rule only (it never falls through to the ordinary classes).

Acceptance test, all of:

1. the member's relocation at the slot is ABS32 to a LOCAL `STT_OBJECT` named
   `@N`, size S > 0, in a PROGBITS section, addend 0 on both sides, and that
   `@N` is declared in the `symbols:` block;
2. no member relocation falls inside the S template bytes (a template with
   relocations refuses);
3. the template has a non-zero byte;
4. the declared address is aligned to the template section's alignment and
   lies in an ARM9 static data section (`in_data_section()`);
5. the image holds exactly the S template bytes at that address;
6. the pattern occurs at no other aligned address of the ARM9 static module;
7. our compile's own `@M` object (recorded by `extract_function()` in the new
   `FuncBytes.anon`) has the same S bytes.

Accepted: MATH_CalcHMACSHA1 0x020816FC +0x84, `@12151` of dgt_sha1.o, 28 bytes
at 0x020A5CB8.

Also accepted, not by this lane: `src/matched/arm9_sdk/func_02059FA8.c`
(DWCi_Init, another lane's untracked file) already carries
`@16103 0x020A8070` (19 bytes) and `@16104 0x020A8084` (30 bytes) lines. Before
this change the header parser silently skipped them. Both now resolve under
`template`, and that file's shard reads EXACT. I did not touch that file or its
shard.

Negative self-tests: the declared address 4 bytes off; our template bytes
differing from the member's; a slot the member relocates against a function
(MATH_SHA1Init, +0x88).

## Rule 3: section-relative `.bss` (`attest_section_rel()`, no new class)

Header syntax: `.bss  0xBASE  data`, the address of the member's .bss start.
A `.bss` relocation is routed to this rule only.

Acceptance test, all of:

1. the member relocates the slot (ABS32) against its own `.bss` section
   symbol, with the same addend as ours;
2. 0 <= addend < the member's .bss size; the base is aligned to the member's
   .bss alignment;
3. the member's whole .bss placed at the base lies inside the ARM9 static
   module's .bss (`layout.json` `arm9.static.bss_start..bss_end`). No map file
   gives one member's exact placement, so this is the bound the layout gives;
4. the ordinary `attest()` (called exactly as the resolver calls it for any
   ABS32 data site) finds a witness for base+addend. The reported class is
   that witness's class (here `sole-ref/self`). This rule lets the site be
   named; it adds no evidence of its own.

Accepted: OS_InitLock 0x02084B90 +0x80, os_spinlock.o `.bss`+0 at 0x02150FCC.

Negative self-tests: a base outside the static .bss (0x020A5CB8); addend 4; a
slot the member relocates against a function (+0x44).

Parser: `SYMBOL_RE` now also accepts `@[0-9]+` and `.bss` as names. A
self-test checks that `.text` is still rejected.

## Rule 4: crt0 stubs

- `layout/function_starts.txt`: seeded `arm9_main 0x02004EA8 arm` (witness: the
  `b` at 0x02004D3C in INITi_DoAutoload, the crt0 member's PC24
  `_start_AutoloadDoneCallback` at +0x188). 0x02004EAC (bl from 0x02004984) and
  0x02004EB0 (bl from 0x02059F84) were already labelled, so they needed no seed.
- Listing regenerated (`python tools/disasm.py arm9 --split`, after checking
  that no asm/ file had changed in the previous two minutes): 5654 functions
  (was 5653). `layout/units_arm9.json` changed (the unit cut points moved).
- `src/matched/arm9_sdk/func_02004EA8.c` (`void func_02004EA8(void) {}`):
  EXACT, new shard `arm9/pkt_02004EA8`.
- 0x02004EAC and 0x02004EB0 are **already EXACT** as the game_unit
  `src/matched/arm9/unit_02004EAC.c` (shard `arm9/pkt_02004EAC`). I left them
  there rather than create duplicate entries. Refiling that unit as SDK is the
  integrator's decision. The crt0 member has no catalogue rows for the three
  stubs, and the order of NitroStartUp and OSi_ReferSymbol is not established.
- Side effect: 0x02004DF4 MIi_UncompressBLZ (`arm9/pkt_02004DF4`, not my shard)
  was EXACT* only because its listing extent ran over the stub. `match.py one`
  now says EXACT. I did not re-verify that shard; it needs a
  `manifest --verify --force --shard pkt_02004DF4`.

## Rows changed (all `manifest --verify --force --shard`, then a plain `--verify` rewrote 0)

| address | symbol | before | after | rule | shard |
|---|---|---|---|---|---|
| 0x02078D34 | FS_LoadOverlayInfo | MATCH (pending) | EXACT | linker | arm9/pkt_02078D34 |
| 0x0207902C | FS_StartOverlay | MATCH (pending) | EXACT | linker | arm9/pkt_0207902C |
| 0x02085264 | OS_InitThread | MATCH* (pending) | EXACT* (listing extent 348 vs 332 compiled) | linker | arm9/pkt_02085264 |
| 0x020816FC | MATH_CalcHMACSHA1 | MATCH (pending) | EXACT | template | arm9/pkt_020816FC |
| 0x02084B90 | OS_InitLock | MATCH (pending) | EXACT | .bss naming | arm9/pkt_02084B90 |
| 0x02004BB4 | INITi_DoAutoload | MATCH (pending) | EXACT | stub seed (target now a traced start and a matched entry) | arm9/pkt_02004BB4 |
| 0x02004EA8 | _start_AutoloadDoneCallback | not a function | EXACT (new) | stub seed | arm9/pkt_02004EA8 |

Rows affected but not edited by this lane: 0x02059FA8 DWCi_Init (another lane's
file, EXACT through `template`); 0x02004DF4 MIi_UncompressBLZ (EXACT* now
verifies EXACT, shard not re-verified).

Only these six pending files changed. The other `SDK_*`-declaring matched
files are unaffected, because the rules only run after `attest()` has refused a
site. I checked 0x0208459C and 0x02084614: they stay EXACT* because of their
listing extents.

## Checks

- `python tools/match.py selftest --quick`: 259 cases, 0 failures. There are 20
  new cases, with at least one negative per rule. The full `selftest` gives 265
  cases, 0 failures.
- `python tools/match.py manifest --check`: 6 duplicate entries, all
  pre-existing overlay pairs (ov091, ov093, ov099, ov104, ov110 x2). None is
  arm9, and none is from this lane.
- `python tools/worklist.py --refresh` / `--summary`, working tree as is: 5654
  functions, SDK 1095 of 1119 matched, game **99.9800%** with 2 open
  (0x020312CC, 0x020312F8, 80 bytes). These two are **not** from this change:
  the uncommitted `layout/symbols_sdk.json` from the libmatch lane (modified at
  18:58) drops the two `EL_LinkFileEx` rows that HEAD has at those addresses,
  so they became game code.
- The same refresh with HEAD's `symbols_sdk.json`/`.txt` (patched in-process,
  output to the scratchpad, nothing in layout/ written): 5654 functions, SDK
  **1038 of 1064** matched, game **100.0000%** (404170 / 404170 bytes, 0 open).
  This lane moves SDK by +6 (1032 to 1038 on HEAD's table; 1089 to 1095 on the
  working-tree table) and game by +1 function (0x02004EA8), which stays at
  100.0000%. The session-start figure (1021 of 1070) was the committed
  worklist.json, read without a refresh.
- ROM rebuild (`build.py --split --pack`, `ndsrom.py build ... --override
  build/pack`): sha1 26ad0b9967aa279c4a266ee69f52b9b2332399a5.
- `layout/worklist.json` was refreshed against the working-tree SDK table
  (open=2 as above). The integrator should refresh again once the libmatch
  lane lands.

## Exact file list

- `tools/match.py` (the rules, header parser, `FuncBytes.anon`, resolver
  hooks, class list, self-tests)
- `layout/function_starts.txt` (one seed)
- `layout/units_arm9.json` (regenerated by disasm.py)
- `layout/worklist.json` (refresh)
- new: `src/matched/arm9_sdk/func_02004EA8.c`, `layout/matched/arm9/pkt_02004EA8.json`
- moved from `src/pending/arm9_sdk/` (plain mv) with header status and notes
  updated: `src/matched/arm9_sdk/func_02004BB4.c`, `func_02078D34.c`,
  `func_0207902C.c`, `func_020816FC.c` (symbols line `@30` -> `@12151`),
  `func_02084B90.c` (added `.bss 0x02150FCC data`), `func_02085264.c`
- new shards: `layout/matched/arm9/pkt_02004BB4.json`, `pkt_02078D34.json`,
  `pkt_0207902C.json`, `pkt_020816FC.json`, `pkt_02084B90.json`,
  `pkt_02085264.json`
- `docs/sessions/2026-09-28/reports/witness_rules.md` (this report)
- asm/ listings (untracked) regenerated.
