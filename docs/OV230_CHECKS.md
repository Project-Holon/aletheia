# Overlay 230 checks: genuine-run behaviour

Source: src/game/ov230 (matched C), the callers in src/game/arm9/gamesystem.c,
src/game/ov010/event_battle.c and src/game/ov020/event_mapchange.c, and
asm/ov230d/ov230d.s for data. Line numbers refer to those files. Hex sums
below were computed from the constants in the C; they assume the genuine
conditions listed in section 3.

## 1. Call path and genuine result

Every OV230_CallSealedBodyN(hook, hookArg, unused) is a stub
(sealed_call_stubs_a.c to _f.c). The stub reads its own parameter block and
jumps to OV230_CallDispatcher (sealed_body.c:77). The dispatcher opens (decrypts
in place) the sealed body named by the block, calls it with the caller's
r0-r3 unchanged, seals it again with an advanced seed, and returns the body's
result (sealed_body.c:77-96). Bodies 0 to 5 are the six chain checks
(sealed_checks_chain.c), so for bodies 0 to 5 the body signature is
(u32 (*hook)(u32), u32 hookArg) and it receives:

* hook = the stub's first argument (the caller function),
* hookArg = the stub's second argument,
* the stub's third argument (always 0) is ignored.

A chain adds the results of its checks to 0x30EB87 and tests the sum. If the
test says "fail" it returns hook(hookArg). In all three
call sites the caller is a function of the shape `if (fn) fn(); return ~fn;`
(GAMESYSTEM_CallIfSet, EVENT_BATTLE_CallAndInvert, EVENT_MAPCHANGE_CallHookAndInvert).
So on the fail path the target runs and the result is ~target. On the other
path neither callback runs and the result is the sum.

The two tests are not symmetric. Even chains (0, 2, 4) fail when
sum % 241 != 0. Odd chains (1, 3, 5) fail when sum % 251 == 0
(sealed_checks_chain.c:66, 86, 106, 126, 145, 164). With genuine inputs the
even chains pass and the odd chains take the fail path. So for the odd chains
the hook call is the genuine path.

| Body | Stub | Chain | Checks added (stub numbers) | Test | Genuine sum | Genuine path | Genuine result |
|---|---|---|---|---|---|---|---|
| 0 | 0x021882A0 | IntegrityChain0 | 14 (CardImage0), 8 (Sig2) | fail if %241 != 0 | 0x325507 | passes, no callback | sum |
| 1 | 0x021882DC | IntegrityChain1 | 15 (CardImage1), 9 (Sig3) | fail if %251 == 0 | 0x325A39 | fail path, hook(hookArg) runs | ~target |
| 2 | 0x02188318 | IntegrityChain2 | 10 (Console0), 6 (Sig0) | fail if %241 != 0 | 0x324415 | passes, no callback | sum |
| 3 | 0x02188354 | IntegrityChain3 | 11 (Console1), 7 (Sig1) | fail if %251 == 0 | 0x325843 | fail path, hook(hookArg) runs | ~target |
| 4 | 0x02188390 | IntegrityChain4 | 16 (ReturnTag0) | fail if %241 != 0 | 0x31A138 | passes, no callback | sum |
| 5 | 0x021883CC | IntegrityChain5 | 17 (ReturnTag1) | fail if %251 == 0 | 0x31ACAE | fail path, hook(hookArg) runs | ~target |

Chains 4 and 5 add only a constant tag, so their outcome never depends on the
host (chain 4 always passes, chain 5 always calls hook(hookArg)), as long as
the sealed bytes open correctly.

### Per call site

| Call site | Body | Caller / target | Genuine return | What the code does with it | Genuine side effects |
|---|---|---|---|---|---|
| gamesystem.c:475 (GAMESYSTEM_ProcInit) | 0 | CallIfSet / GAMESYSTEM_ApplyTamperPenalty | sum (not ~target) | intact stays 0, adds 0 to checkSum | none; ApplyTamperPenalty is NOT called |
| gamesystem.c:480 | 3 | CallIfSet / GAMESYSTEM_ProbeHeapCreate | ~target | intact stays 1, penalty 0 | ProbeHeapCreate runs: creates child heap 5 in heap 9 (size 5<<10), calls GAMESYSTEM_GetWorkSize, deletes heap 5 (gamesystem.c:396-401) |
| gamesystem.c:486 | 4 | CallIfSet / GAMESYSTEM_ApplyTamperPenaltyRepeat | sum | result ignored | none; ApplyTamperPenaltyRepeat is NOT called |
| event_battle.c:682 (state 6) | 1 | CallAndInvert / EVENT_BATTLE_IntegrityProbeA | ~target | probeOk = 1, adds 0 | ProbeA runs: two GF_STANDARD_Rand calls (event_battle.c:969-973) |
| event_battle.c:690 (state 6) | 3 | CallAndInvert / EVENT_BATTLE_IntegrityProbeB | ~target | probeOk = 1, adds 0 | ProbeB runs: two GF_STANDARD_Rand calls |
| event_battle.c:698 (state 7) | 4 | CallAndInvert / EVENT_BATTLE_IntegrityDecoyC | sum | probeOk = 0, adds 0 (probeOk * 0x9D) | none; ProbeC is NOT called |
| event_mapchange.c:1091 (state 3) | 0 | CallHookAndInvert / TamperLeakA | sum | result ignored | none; TamperLeakA is NOT called |
| event_mapchange.c:1102 | 2 | CallHookAndInvert / TamperLeakB | sum | result ignored | none; TamperLeakB is NOT called |
| event_mapchange.c:1108 | 5 | CallHookAndInvert / NopHook | ~NopHook | result ignored | CallHookAndInvert(NopHook) runs, which calls the empty NopHook |

Penalty arithmetic confirms the genuine column. gamesystem.c:494 tests
(checkSum + checkPenalty) % 0x12AF with checkSum starting at 0xC35FFB. This is
0 only when body 0 does not return ~target (adds 0) and body 3 does (penalty
0). event_battle.c:737 tests integritySum % 0x1933 with a start value 0x013A1AB5
(0 mod 0x1933); it stays 0 only when A and B return ~target (adds 0) and C does
not (adds 0x9D). Both start values are exact multiples (checked), so the
genuine path is the one in the table.

Effect of tampering, for reference:

* Body 0 fails (card image or stub signature wrong): ApplyTamperPenalty runs,
  tamperCount += 1, checkSum += 0x47, so the final test fails and
  ApplyTamperPenalty runs once per badge (gamesystem.c:494-498).
* Body 3 fails to take the fail path (console wrong): ProbeHeapCreate does not
  run, checkPenalty = 0x191, same loop as above. In the battle, state 6 adds
  0x5D1 (probe B) or 0x3D1 (probe A).
* Body 4 fails (cannot happen from host data; sealed-byte damage only):
  ApplyTamperPenaltyRepeat or DecoyC runs, and the battle adds 0x9D.
* Body 0, 2 failing in the map change: TamperLeakA or B runs and leaks a
  0x1000-byte allocation (heap id 0x8004). There is no penalty counter there.

### Names: genuine path or tamper path

| Name | Path | Verdict |
|---|---|---|
| GAMESYSTEM_ApplyTamperPenalty, ...Repeat | tamper only | name is right |
| GAMESYSTEM_ProbeHeapCreate | genuine (body 3 fail path) | name is right |
| EVENT_BATTLE_IntegrityProbeA, B | genuine | name is right |
| EVENT_BATTLE_IntegrityProbeC | tamper only (body 4) | misleading, see proposals |
| EVENT_MAPCHANGE_AllocWorkBufferA, B | tamper or wrong console only | misleading, see proposals |
| EVENT_MAPCHANGE_StartMarker | genuine (body 5) | misleading: it is a call-hook-and-invert helper, not a range start; the comment at event_mapchange.c:1050-1052 and :2667-2671 that calls the arguments a range is wrong |
| OV230_IntegrityChain* parameter onFail | genuine for chains 1, 3, 5 | misleading |
| OV230_IntegrityChain* parameter arg | it receives the stub's second argument | the stub's third argument is never read |

## 2. Map: body index to function

Block layout (from the stub DCDs): word 1 seed, word 2 body address + 0x1600,
word 3 size word, word 5 dispatcher address + 0x1600. Body address = word 2 -
0x1600. A chain reaches its checks through a table of "stub + 0x1600 + 0x320"
addresses (sealed_checks_chain.c:55-66); the call subtracts 0x1920.

| Body | Stub address | Sealed body at | Function | Used by |
|---|---|---|---|---|
| 0 | 0x021882A0 | 0x02187F00 | OV230_IntegrityChain0 | gamesystem, mapchange |
| 1 | 0x021882DC | 0x02187FA0 | OV230_IntegrityChain1 | event_battle |
| 2 | 0x02188318 | 0x02188040 | OV230_IntegrityChain2 | mapchange |
| 3 | 0x02188354 | 0x021880E0 | OV230_IntegrityChain3 | gamesystem, event_battle |
| 4 | 0x02188390 | 0x02188180 | OV230_IntegrityChain4 | gamesystem, event_battle |
| 5 | 0x021883CC | 0x02188210 | OV230_IntegrityChain5 | mapchange |
| 6 | 0x021888C0 | 0x02188450 | OV230_CheckStubSignature0 (checks stub 10) | chain 2 |
| 7 | 0x021888FC | 0x0218856C | OV230_CheckStubSignature1 (checks stub 11) | chain 3 |
| 8 | 0x02188938 | 0x02188688 | OV230_CheckStubSignature2 (checks stub 14) | chain 0 |
| 9 | 0x02188974 | 0x021887A4 | OV230_CheckStubSignature3 (checks stub 15) | chain 1 |
| 10 | 0x02188E3C | 0x02188CDC | OV230_CheckConsoleIdentity0 | chain 2 |
| 11 | 0x02188E78 | 0x02188D8C | OV230_CheckConsoleIdentity1 | chain 3 |
| 12 | 0x02189098 | 0x02188EB4 | OV230_ReadCardBytes | CardImage0/1 |
| 13 | 0x021890D4 | 0x02189004 | OV230_Crc32 | CardImage0/1 |
| 14 | 0x02189340 | 0x02189110 | OV230_CheckCardImage0 | chain 0 |
| 15 | 0x0218937C | 0x02189228 | OV230_CheckCardImage1 | chain 1 |
| 16 | 0x021893D0 | 0x021893B8 | OV230_ReturnTag0 (0xB5B1) | chain 4 |
| 17 | 0x0218940C | 0x021893C4 | OV230_ReturnTag1 (0xC127) | chain 5 |

Genuine values of each check:

| Check | Genuine value | Why |
|---|---|---|
| Sig0, Sig2 | 0xB5B1 | all 16 stub bytes match; mismatch gives 0xBD3B |
| Sig1, Sig3 | 0xBD3B | all 16 bytes match; mismatch gives 0xB5B1 |
| Console0 | 0xF1 * 0xAD | any console that is neither the fixed one nor all-zero MAC |
| Console1 | 0xFB * 0xB3 | same condition, tags swapped |
| CardImage0 | 0xF1 * 0xBF | crc[0..2] == crc[3], and crc[4], crc[5] not both equal to crc[3] |
| CardImage1 | 0xFB * 0xB5 | same condition, tags swapped |

Genuine tag values were derived from the C and from the callers' penalty
arithmetic (section 1), which only closes with these values.

## 3. Would each check pass on a host, run as C?

| Function | Reads | Passes by itself on a host? | What a host must provide |
|---|---|---|---|
| Dispatcher, OV230_OpenSealedBody, SealBody, cipher | the overlay's own sealed body bytes (original ciphertext, key from seed, size, body address), the parameter block | No. It needs the original encrypted bytes, the exact load address (0x02188xxx), and writes the code back sealed with a changed seed after every call, so a body is only valid once per key state | Either the original overlay image mapped at its address and executed as ARM (not as host C), or bypass the dispatcher and call the C bodies directly |
| IntegrityChain0-5 | the chain table built from the stubs' addresses; calls the stubs by address (stub + 0x1600 + 0x320 - 0x1920) | Only if the stub symbols are real addresses of working stubs | Direct C calls to the check functions, plus the sums in section 1 |
| CheckStubSignature0-3 | 16 bytes at the start of stubs 10, 11, 14, 15, read through a pointer computed from the stub address | No on a host, unless the stub bytes sit at that address. The values are the first 4 ARM instructions of the plain stubs: E18FC00F, E01CC00C, 03A0C000, 128CC01C | A byte array holding the plain stub prefix (these are decrypted-overlay bytes, not secret), or hard-code the result (Sig0, Sig2 = 0xB5B1; Sig1, Sig3 = 0xBD3B) |
| CheckConsoleIdentity0/1 | OS_GetMacAddress, OS_GetOwnerInfo (birthday month and day, nickname length), a 6-byte complemented fixed MAC at 0x0218996C in the overlay tail (FF F6 40 FF FF CE, so the fixed MAC is 00:09:BF:00:00:31), plain data in the listing | Passes only if the host MAC is non-zero and different from 00:09:BF:00:00:31. A host that reports an all-zero MAC (common default) gets the swapped tags: chain 2 then fails (AllocWorkBufferB runs, a leak) and chain 3 does not take the fail path (ProbeHeapCreate and ProbeB do not run, body 3 returns the sum, penalty 0x191 and 0x5D1 apply) | A non-zero MAC that is not the fixed one, via OS_GetMacAddress. Owner info does not matter unless the MAC is the fixed one. No real console data is needed, only any such MAC |
| OV230_ReadCardBytes | Card registers directly: EXMEMCNT 0x04000204, MCCNT1 0x040001A4, MCCNT0 0x040001A1, command bytes 0x040001A8, data 0x04100010, the ROM control word from the header copy at 0x027FFE60 or 0x02FFFE60 (chosen by bit 0 of 0x04004000), command 0xB7, 0x200-byte pages | No. It cannot run as C on a host; there are no card registers | A reimplementation that returns bytes from the cartridge image for (offset, size). It is called with offsets 0x1000, 0x1200, 0x1400 and size 0x200 |
| OV230_Crc32 | only its input buffer (non-standard bit test, polynomial 0xEDB88320) | Yes, pure. Only equality of the results matters | Nothing |
| CheckCardImage0/1 | OS_GetLockID, CARD_LockRom, CARD_UnlockRom, OS_ReleaseLockID, CARDi_ReadRom (SDK ROM read at offset + 0x7000, i.e. 0x8000, 0x8200, 0x8400), ReadCardBytes at 0x1000, 0x1200, 0x1400, CRCs | Passes only if the cartridge image answers like a real card: the three raw reads at 0x1000-0x15FF must give the same 0x200 bytes as the SDK read at 0x8000 (the card mirrors the area below 0x8000 onto the 0x200 bytes at 0x8000; this mirroring is hardware behaviour, not shown in the C, but it is the only way crc[0..2] can equal crc[3] at different offsets), and the sectors at 0x8200 and 0x8400 must not match the one at 0x8000 | A cartridge image (the real ROM, from the user) and a read function with the rule: offset below 0x8000 maps to 0x8000 + (offset & 0x1FF); otherwise plain file bytes. The SDK path (CARDi_ReadRom) must read the same image. The lock functions can be no-ops |
| ReturnTag0/1 | nothing | Yes | Nothing |

The checks that need the real cartridge: CardImage0 and CardImage1 (chains 0
and 1). Only the plain ROM bytes at 0x1000-0x15FF mirror and at
0x8000-0x85FF are read; the secure area (0x4000-0x7FFF) is not touched. The
checks that need original ciphertext: only the dispatcher path (opening a
body). The checks that need the console: Console0 and Console1 (chains 2, 3),
and only a non-zero, non-fixed MAC.

## 4. What the port should do to match a genuine run

The simplest exact equivalent skips the dispatcher and returns the genuine
outcome directly. For each body N, called as (hook, hookArg, 0):

* Bodies 1, 3, 5: call hook(hookArg) if hook is non-null, return ~hookArg.
  Side effects that must happen: probe A and B (two GF_STANDARD_Rand calls each,
  which advance the game's RNG state), ProbeHeapCreate (heap create, work size,
  delete), CallHookAndInvert(NopHook).
* Bodies 0, 2, 4: do not call hook; return the genuine sum (0x325507,
  0x324415, 0x31A138). Callers either ignore the value or compare it with
  ~target, where it differs.

If instead the port runs the real chain, checks and card logic as C, it must
supply: a non-zero, non-fixed MAC; the plain stub prefix bytes; a cartridge
read with the below-0x8000 mirroring; and direct calls instead of the
encrypted dispatcher.

RNG note: the battle's two probe calls consume four GF_STANDARD_Rand values per
battle (A and B, state 6). Skipping them desynchronises the RNG from a genuine
console.

## 5. Rename proposals (not applied)

| Old | New | Reason |
|---|---|---|
| EVENT_BATTLE_IntegrityProbeC | EVENT_BATTLE_IntegrityDecoyC | called only when chain 4 fails (tamper); A and B are on the genuine path |
| EVENT_MAPCHANGE_AllocWorkBufferA, B | EVENT_MAPCHANGE_TamperLeakA, B | called only on a tamper or wrong-console path; they leak a buffer |
| EVENT_MAPCHANGE_StartMarker | EVENT_MAPCHANGE_CallHookAndInvert | runs its argument and returns its complement, same as GAMESYSTEM_CallIfSet and EVENT_BATTLE_CallAndInvert; it is not a range start. Fix the comments at event_mapchange.c:1050 and :2667 |
| EVENT_MAPCHANGE_EndMarker | EVENT_MAPCHANGE_NopHook | it is the hook argument of body 5, not a range end |
| OV230_IntegrityChain0-5 parameter onFail | hook | for chains 1, 3, 5 the call is the genuine path |
| OV230_IntegrityChain0-5 parameter arg | hookArg | it is the stub's second argument; the third is unused |
| OV230_CallSealedBodyN parameters (caller, target, arg) | (hook, hookArg, unused) | match the chain parameters |
| GAMESYSTEM_ApplyTamperPenalty/Repeat, ProbeHeapCreate, IntegrityProbeA/B | no change | names agree with their path |
