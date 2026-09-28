# sdk9_os: ARM9 libos lane report

Territory: every open arm9 SDK row of libos.TWL.HYB.a (28 objects, 86 rows,
9,080 bytes at the start of this lane). Worked from the vendor objects only
(sdkobj.py, DWARF, relocations, .debug_line read through a scratch script);
no `.c`/`.h` under `sdk/` was opened. No existing pending file was read or
salvaged; none existed at any address this lane wrote.

## Totals

- 80 functions EXACT/EXACT* and filed: 7,768 bytes.
- 6 functions in pending (3 MATCH, 3 DIFF): 1,156 bytes.
- 0 rows left untouched.

Every filed file's `status:` is copied from `manifest --verify`; each shard
was verified twice and the second pass rewrote 0.

## Filed (src/matched/arm9_sdk/func_<ADDR>.c, shard layout/matched/arm9/pkt_<ADDR>.json)

| address | sdk symbol | verdict | bytes |
|---|---|---|---|
| 0x0208459C | OS_WaitIrq | EXACT* | 116 |
| 0x02084614 | OSi_IrqCallback | EXACT* | 136 |
| 0x02084A38 | OSi_CommonCallback | EXACT | 76 |
| 0x02084C78 | OSi_DoUnlockByWord | EXACT* | 116 |
| 0x02084CFC | OSi_DoTryLockByWord | EXACT* | 108 |
| 0x02084D78 | OS_LockCartridge | EXACT | 32 |
| 0x02084E54 | OSi_AllocateCardBus | EXACT | 68 |
| 0x02084EB8 | OS_GetLockID | EXACT | 88 |
| 0x02084F10 | OS_ReleaseLockID | EXACT* | 48 |
| 0x02085078 | OSi_RemoveSpecifiedLinkFromQueue | EXACT | 84 |
| 0x020850CC | OSi_RemoveMutexLinkFromQueue | EXACT | 48 |
| 0x020850FC | OSi_InsertThreadToList | EXACT | 92 |
| 0x02085158 | OSi_RemoveThreadFromList | EXACT | 72 |
| 0x020853B0 | OS_IsThreadAvailable | EXACT | 16 |
| 0x020853C0 | OS_CreateThread | EXACT | 240 |
| 0x020854D0 | OSi_ExitThread_ArgSpecified | EXACT | 88 |
| 0x02085528 | OSi_ExitThread | EXACT | 56 |
| 0x02085560 | OSi_ExitThread_Destroy | EXACT | 92 |
| 0x020855BC | OS_DestroyThread | EXACT | 124 |
| 0x0208565C | OS_KillThreadWithPriority | EXACT | 156 |
| 0x02085710 | OS_JoinThread | EXACT | 60 |
| 0x02085760 | OS_SleepThreadDirect | EXACT | 80 |
| 0x02085868 | OS_WakeupThreadDirect | EXACT | 40 |
| 0x020858D8 | OS_YieldThread | EXACT | 176 |
| 0x02085988 | OS_SetThreadPriority | EXACT | 168 |
| 0x02085A38 | OS_Sleep | EXACT* | 160 |
| 0x02085AD8 | OSi_SleepAlarmCallback | EXACT | 32 |
| 0x02085AF8 | OS_SetSwitchThreadCallback | EXACT* | 40 |
| 0x02085B30 | OS_DisableScheduler | EXACT | 48 |
| 0x02085B60 | OS_EnableScheduler | EXACT | 52 |
| 0x02085B9C | OS_InitContext | EXACT | 108 |
| 0x02085CBC | OS_GetConsoleType | EXACT | 80 |
| 0x02085D94 | OS_InitMessageQueue | EXACT | 40 |
| 0x02085F8C | OS_ReadMessage | EXACT | 120 |
| 0x02086004 | OS_InitMutex | EXACT | 36 |
| 0x02086028 | OS_LockMutex | EXACT | 80 |
| 0x02086088 | OSi_UnlockAllMutex | EXACT | 72 |
| 0x020860D0 | OS_TryLockMutex | EXACT | 148 |
| 0x0208623C | OSi_EnqueueTail | EXACT | 36 |
| 0x02086260 | OSi_DequeueItem | EXACT | 36 |
| 0x020864FC | OS_InitArenaEx | EXACT | 112 |
| 0x02086A50 | OS_InitAlloc | EXACT | 168 |
| 0x02086AF8 | OS_CreateHeap | EXACT | 160 |
| 0x02086B98 | OS_CreateExtraHeap | EXACT | 188 |
| 0x02086C70 | OS_IsOnExtendedMainMemory | EXACT | 76 |
| 0x02086D04 | OS_DisableProtectionUnit | EXACT | 16 |
| 0x02086DB0 | OS_SetProtectionRegionEx | EXACT | 40 |
| 0x02086E40 | OSi_ExceptionHandler | EXACT | 116 |
| 0x02086EC8 | OSi_SetExContext | EXACT | 128 |
| 0x02086F48 | OSi_DisplayExContext | EXACT | 124 |
| 0x02086FC4 | OSi_SetTimerReserved | EXACT | 36 |
| 0x02086FE8 | OS_InitTick | EXACT | 112 |
| 0x02087068 | OSi_CountUpTick | EXACT | 104 |
| 0x02087208 | OS_InitAlarm | EXACT | 60 |
| 0x020873F8 | OS_CancelAlarm | EXACT | 132 |
| 0x0208748C | OSi_ArrangeTimer | EXACT | 236 |
| 0x02087578 | OS_InitVAlarm | EXACT | 64 |
| 0x020875B8 | OSi_InsertVAlarm | EXACT | 124 |
| 0x02087634 | OSi_AppendVAlarm | EXACT | 56 |
| 0x0208766C | OSi_DetachVAlarm | EXACT | 56 |
| 0x020876B8 | OS_SetVAlarm | EXACT | 140 |
| 0x02087744 | OSi_SetNextVAlarm | EXACT | 64 |
| 0x02087784 | OSi_VAlarmHandler | EXACT | 360 |
| 0x020878EC | OSi_CompareVCount | EXACT | 76 |
| 0x02087938 | OSi_GetVFrame | EXACT | 60 |
| 0x02087A3C | OS_WaitInterrupt | EXACT | 168 |
| 0x02087B20 | OSi_IsCodecTwlMode | EXACT | 88 |
| 0x02087B78 | OS_InitReset | EXACT | 84 |
| 0x02087C88 | OS_GetOwnerInfo | EXACT | 128 |
| 0x02087D28 | OS_GetOwnerInfoEx | EXACT | 156 |
| 0x02087DE0 | OS_IsAgreeEULA | EXACT | 60 |
| 0x02087E1C | OS_GetAgreedEULAVersion | EXACT | 36 |
| 0x02087E60 | OS_GetParentalControlInfoPtr | EXACT | 36 |
| 0x02087EA8 | OSi_InitVramExclusive | EXACT | 52 |
| 0x02087EDC | OSi_UnlockVram | EXACT | 132 |
| 0x02087F60 | OS_InitDeliverArgInfo | EXACT | 92 |
| 0x0208812C | OS_GetTitleIdFromDeliverArg | EXACT | 36 |
| 0x020882F0 | OS_WaitEventEx | EXACT | 168 |
| 0x02088398 | OS_SignalEvent | EXACT | 60 |
| 0x020883D4 | OSi_InitPrevTitleId | EXACT | 196 |

Files written: `src/matched/arm9_sdk/func_<ADDR>.c` and
`layout/matched/arm9/pkt_<ADDR>.json` for exactly the 80 addresses above
(one shard per function, shard id `pkt_<ADDR>`).

## Pending (src/pending/arm9_sdk/func_<ADDR>.c)

| address | sdk symbol | verdict | bytes | residue |
|---|---|---|---|---|
| 0x02085264 | OS_InitThread | MATCH* | 332 | code bytes identical; pool words SDK_SYS_STACKSIZE (0x1800), SDK_SECTION_ARENA_DTCM_START (0x02FE00C0) and OSi_IdleThreadProc (0x02085B20) have no witness outside the function |
| 0x02084B90 | OS_InitLock | MATCH | 140 | identical with `isInitialized` as a function-local static, but its .bss relocation (0x02150FCC) cannot be named; as an extern the compiler stops hoisting the lock-word store (DIFF). Permuter seed 12402, 400 rounds, no gain |
| 0x02087BCC | OS_ResetSystem | MATCH | 160 | code bytes identical; bl to PMi_ExecutePostExitCallbackList (0x027315A8, ltdmain) has no witness |
| 0x02086164 | OSi_UnlockMutexCore | DIFF | 216 | original reloads count on the STD/W path (`ldr r0,[r6,#0xc]; b` to the next instruction) and keeps the switch value in r0; switch, fall-through and if-chain spellings plus permuter seed 12401 (400 rounds) keep it in r5 |
| 0x02086DD8 | OS_InitException | DIFF | 104 | one instruction: original `biceq r0,r4,#0x800000` for the mirror vector address; every spelling tried folds the constant to `subeq`. Permuter seed 12404, 300 rounds, no gain |
| 0x02088168 | OS_GetLowEntropyData | DIFF | 204 | draft; original reads VCOUNT before the OS_GetTickLo call and rebases system-work reads off 0x02FFFC00. Capped at MATCH regardless: the OSi_TickCounter+8 pool word (0x02151338) has no witness |

## asm bodies and their evidence

Each asm file carries the evidence line in its header. The line-table
evidence came from a scratch `.debug_line` decoder over the vendor object:
hand-written functions show one strictly increasing source line per
instruction, and compiled functions show interleaved lines.

- 0x02085B9C OS_InitContext: no DW_TAG_variable; 27 instructions on 27 increasing lines (43..78). The C spelling tried first gave DIFF: it schedules the stores and emits tst, not ands.
- 0x02084EB8 OS_GetLockID: needs clz; no variables; one line per instruction (836..898).
- 0x02084F10 OS_ReleaseLockID: no variables; one line per instruction (914..929).
- 0x02086D04 OS_DisableProtectionUnit: mrc/mcr on cp15 c1; one line per instruction.
- 0x02086EC8 OSi_SetExContext: mrs/msr on CPSR/SPSR, reads the frame through r12 outside the ABI; one line per instruction (376..449).
- 0x02086E40 OSi_ExceptionHandler: no-prologue vector entry that uses r12 and a private stack, and mrs; one line per instruction (285..332).
- 0x02086F48 OSi_DisplayExContext: a C function (the early return is compiled) with an `asm {}` block for the mode switch (mrs/msr). The block has one line per instruction (497..536) between the C lines 462 and 541.

## Catalogue and DWARF name disagreements

- 0x02084D78 is catalogued as OS_LockCartridge. The image's pool words are
  OSi_FreeCartridgeBus (0x02084DDC) and OSi_DoUnlockByWord (0x02084C78), so
  the function is OS_UnlockCartridge (same 32-byte shape, `mov r3,#1`). It is
  filed as func_02084D78 with a header note.
- 0x02084C78 is named OSi_DoUnlockByWord by the catalogue, but in
  OS_LockCartridge's relocation the object calls it OSi_DoLockByWord. The
  object's own symbol table puts OSi_DoLockByWord at 0x02084C1C, so the
  catalogue row name is right and the disagreement comes from the mislabelled
  0x02084D78 row above.
- 0x02085D0C (OSi_DetectDeviceType, os_emulator.o local) is labelled
  `DWCi_CMNlFontFlag` by the image symbol map.
- 0x02085B20 OSi_IdleThreadProc (16 bytes, os_thread.o local) and 0x02087EA0
  OsCountZeroBits (os_vramexclusive.o) have no open catalogue row. Matching
  OSi_IdleThreadProc would attest one of OS_InitThread's three unresolved
  words. The other two words are linker constants, so that alone does not
  lift OS_InitThread.
- OSi_CommonCallback's DWARF gives one parameter (`data`), but the body reads
  the PXI callback's second register. The file uses `(int tag, u32 data, BOOL err)`.
- Several objects (os_spinlock, os_emulator, os_systemwork, os_exception,
  os_argument) name function-local statics with Itanium-style `_ZZ...`
  mangling. Every file here compiles as c99 and matches. Where a static is
  addressed section-relative it is reached through a per-object .bss/.data
  overlay struct `g_<base>`. The C++ spelling was tested on OS_GetConsoleType
  and made no difference.

## Shape notes for the integrator

- Per-object preludes are uniform: os_thread (OSThread/OSMutex/OSiAlarm and
  the `OsThreadBss` overlay at 0x02150FD0, now with named +0x10/+0x14), the
  mutex count/type mask macros, alarm, valarm, tick, alloc, lock and
  owner-info headers. The same object always uses the same text.
- Base-plus-offset section accesses use an overlay struct named
  `g_<section base>`. Accesses the image makes through their own named literal
  use the SDK name with a symbols line.

## For the next pass

1. OS_InitLock (0x02084B90): look for a spelling that lets the flag store sink
   below the first lock-word store with `isInitialized` extern (for example a
   different lock-word access type).
2. OS_InitException (0x02086DD8): find a non-folded spelling of the
   `& ~0x800000` vector mirror.
3. OSi_UnlockMutexCore (0x02086164): control-flow shape of the STD/W case.
4. OS_GetLowEntropyData (0x02088168): the VCOUNT-before-call ordering
   (probably an inline helper taking the value as an argument). It stays
   MATCH after that.
5. OS_InitThread and OS_ResetSystem are byte-identical; they need witnesses
   (match OSi_IdleThreadProc 0x02085B20 and the ltdmain
   PMi_ExecutePostExitCallbackList), not C work.

Permuter seeds used: 12401 (UnlockMutexCore), 12402 (InitLock), 12403
(GetConsoleType, later matched by hand), 12404 (InitException).
