# sdk9w2_os: ARM9 libos second pass

Territory: the six libos rows the first pass (sdk9_os) left in pending, plus
the uncatalogued callees that block their witnesses. Worked from the vendor
objects only (sdkobj.py, relocations, a scratch ELF reader over the member);
no `.c`/`.h` under `sdk/` was opened. The pending files at these addresses are
the first-pass lane's own object-derived drafts and were continued as
instructed.

## Totals

- 4 functions filed EXACT/EXACT*: 348 bytes (2 catalogue rows, 2 uncatalogued
  callees).
- 4 rows still pending: OS_InitThread (MATCH*), OS_InitLock (MATCH),
  OSi_UnlockMutexCore (DIFF), OS_GetLowEntropyData (DIFF).

Every filed file's `status:` is copied from `manifest --verify --force`; each
shard was then verified again with and without `--force`, rewriting 0.
Note for the integrator: a plain `--verify` on a freshly written shard reports
the status already in the shard without recompiling, so the first check of a
new shard must use `--force` (0x02086DD8 first showed EXACT, live is EXACT*).

## Filed

| address | sdk symbol | verdict | bytes | shard |
|---|---|---|---|---|
| 0x02085B20 | OSi_IdleThreadProc (os_thread.o static, no catalogue row) | EXACT | 16 | arm9/pkt_02085B20 |
| 0x02087BCC | OS_ResetSystem (os_reset.o) | EXACT | 160 | arm9/pkt_02087BCC |
| 0x02086DD8 | OS_InitException (os_exception.o) | EXACT* | 104 | arm9/pkt_02086DD8 |
| 0x027315A8 | PMi_ExecutePostExitCallbackList (libspi pm.o, .ltdmain, no catalogue row) | EXACT | 24 | twl/pkt_027315A8 |

Files written:

- `src/matched/arm9_sdk/func_02085B20.c`, `layout/matched/arm9/pkt_02085B20.json`
- `src/matched/arm9_sdk/func_02087BCC.c`, `layout/matched/arm9/pkt_02087BCC.json`
  (moved from `src/pending/arm9_sdk/func_02087BCC.c`, which is removed)
- `src/matched/arm9_sdk/func_02086DD8.c`, `layout/matched/arm9/pkt_02086DD8.json`
  (moved from `src/pending/arm9_sdk/func_02086DD8.c`, which is removed)
- `src/matched/twl_sdk/func_027315A8.c`, `layout/matched/twl/pkt_027315A8.json`
- pending notes updated: `src/pending/arm9_sdk/func_02085264.c`,
  `func_02084B90.c`, `func_02086164.c`; `func_02088168.c` rewritten (better draft).

Details:

- OSi_IdleThreadProc: `OS_EnableInterrupts(); for (;;) OS_Halt();`. Its
  matched entry now attests OS_InitThread's pool word 0x02085B20 (`matched`
  class).
- OS_ResetSystem: C unchanged. The only unresolved site was the bl to
  0x027315A8; filing that callee made it EXACT.
- PMi_ExecutePostExitCallbackList is a TWL-region (ltdmain) function. It is
  outside "ARM9 static" strictly, but it is ARM9 code, has no catalogue row
  and no lane, and it was the sole blocker of OS_ResetSystem. The integrator
  can drop it (and OS_ResetSystem falls back to MATCH) if twl is out of scope.
- OS_InitException: the `biceq` comes out when the vector address is held in a
  pointer local: `u32 *vec = (u32 *)0x02FFFD9C; *vec = h; if (!OS_IsRunOnTwl())
  *(u32 *)((u32)vec & ~0x800000) = h;`. Every constant-address spelling folds
  to `subeq`. The object's DWARF lists only `ex`, so `vec` is not a DWARF
  local; the bytes are identical. The verdict is EXACT* because of the sdk-class
  witness on OSi_ExceptionHandler.

## Pending

| address | sdk symbol | verdict | bytes | residue |
|---|---|---|---|---|
| 0x02085264 | OS_InitThread | MATCH* | 332 | code identical; two linker-absolute pool words unwitnessed (below) |
| 0x02084B90 | OS_InitLock | MATCH | 140 | code identical; the .bss-relative relocation cannot be named in a symbols: block |
| 0x02086164 | OSi_UnlockMutexCore | DIFF | 216 | count kept in r5, original keeps it in r0 and reloads it on the STD/W path |
| 0x02088168 | OS_GetLowEntropyData | DIFF | 204 | 77 bytes (was 140); system-work base not kept across the OS_GetTickLo call |

### OS_InitThread linker symbols: what evidence exists

OSi_IdleThreadProc now resolves. Two words remain:

- SDK_SYS_STACKSIZE = 0x00001800 (pool +0x120)
- SDK_SECTION_ARENA_DTCM_START = 0x02FE00C0 (pool +0x124)

Both are linker-defined absolutes; no object or file in the repo gives their
values. The image has other pool copies outside the range: 0x02086684 (0x1800)
and 0x0208668C (0x02FE00C0) in OS_GetInitArenaHi's pool, and 0x02086758
(0x02FE00C0) in OS_GetInitArenaLo's pool. The vendor objects of those two
functions relocate against the same two symbols (checked with sdkobj), so these
are the same linker symbols. The `literal` class does not count them because
evidence() only records pool words at a `pool_XXXXXXXX:` label: 0x02086684 and
0x0208668C are unlabelled continuation words of `pool_02086680`, and
0x02086758 sits in a run disasm.py never labelled (OS_GetInitArenaHi/Lo are
jump-table functions whose bodies are emitted as `.word`). The only other 0x1800
word, 0x0209DA20, is in an unrelated data table. No witness was invented; the
entry stays MATCH*. Both arena functions are matched as asm bodies with the
values as plain words, so the `matched` class (addresses only) does not help.
Lifting this needs a tools decision: count continuation words of an ARM9 pool
run (as the overlay rule already does), or disasm.py labelling those pools.

### OS_InitLock

Both the vendor object and our compile relocate the flag's pool word against
the `.bss` section symbol with addend 0. sdkobj shows the vendor name
`_ZZ11OS_InitLockvE13isInitialized` only because it maps .bss+0 to the local
symbol there. match.py resolves by relocation symbol name, and a `.bss` line in
the symbols: block is not accepted, so the site stays wildcarded even though
0x02150FCC has a sole-ref witness. Every extern spelling (extern, defined
global, `__restrict` lock pointer, reordered stores) keeps the flag store above
the lock-word stores: 36 bytes DIFF at best. Permuter seed 13201 (extern
variant, 300 rounds): no gain. A tool change that lets a symbols: line name a
section-relative target would make this EXACT with the current C.

### OSi_UnlockMutexCore

DWARF locals are only mutex (r6), type (r5), unlocked (r1), e (r4). Tried
fall-through STD/W into R, goto into R, duplicated bodies, no currentThread
local (worse), swapped type test. Permuter seed 13202 (500 rounds): no gain.
The shape suggests the STD/W path's count availability is killed in the
original (a reload is emitted rather than a spare register), which none of the
C spellings reproduce.

### OS_GetLowEntropyData

VCOUNT is now read into a callee-saved register before the call, as in the
original (a block-local `u16`). The remaining residue is the 0x02FFFC00 base:
the original loads it into r4 before the call and keeps it across; every
spelling tried (struct pointer, inline getter, absolute addresses, `register`)
loads it after the call. Direct field access without the macAddress pointer
reproduces the +0x300 rebasing but not the separate +0x3A8 base. Correction to
the first-pass note: OSi_TickCounter (0x02151338) now resolves (sole-ref), so an
exact spelling would verify EXACT, not MATCH. Permuter seed 13203 (400 rounds):
73 bytes at best, not kept.

## Catalogue and classification notes

- 0x02087EA0 OsCountZeroBits (os_vramexclusive.o static, `clz r0,r0; bx lr`)
  is already matched EXACT as `src/matched/arm9/func_02087EA0.c`, shard
  `arm9/pkt_02087EA0` (kind `game`, asm body without an evidence line). The
  classifier filed it as game because it has no catalogue row. It is SDK code;
  it was not moved because that shard is not this lane's. Suggest the
  integrator refile it under `src/matched/arm9_sdk/` with kind `sdk` and the
  evidence line "clz has no C spelling; object DWARF has only the parameter".
- 0x02085B20 OSi_IdleThreadProc and 0x027315A8 PMi_ExecutePostExitCallbackList
  have no catalogue row; both are confirmed from their vendor objects with 0
  concrete mismatches (sdkobj over a synthetic row).
- OS_GetInitArenaHi/Lo (0x02086594, 0x02086694) are filed as kind `game` asm
  bodies under `src/matched/arm9_sdk/` with no evidence line; not touched.

## For the next pass

1. Tools decision on ARM9 pool continuation words (lifts OS_InitThread) and on
   section-relative relocation naming (lifts OS_InitLock). Both need no C work.
2. OS_GetLowEntropyData: find why the base is live across the call (possibly
   an inline system-work accessor with a side effect, or an earlier use).
3. OSi_UnlockMutexCore: what kills the count on the STD/W path.

Permuter seeds used: 13201 (OS_InitLock), 13202 (OSi_UnlockMutexCore), 13203
(OS_GetLowEntropyData).
