# unit_02164D64 (ov009): 2 parts left

- `unit_02164D64_p01.c` (02164D64..02165B5C): one file, one canonical WCMWork struct, the two
  system.o statics (WCMi_OverridedDeviceId, wcmw) as file statics. Verdict MATCH, not EXACT: the
  ABS32 pool words that point at the ov009 .bss statics cannot be attested by match.py (the
  tool cannot resolve a .bss-relative target in an overlay), so every use of `wcmw` shows as
  unresolved. The code bytes are identical. 0x02164D64 is still a 16-byte `asm` stand-in
  (`ldr ip,=WCM_InitEx; mov r2,#1; bx ip`, a tail call mwcc does not emit from plain C).
- `unit_02164D64_p02.c` (02165B68 WCMi_GetDefaultDeviceId): EXACT.

Boundary p01 | p02: 12-byte linker veneer at 0x02165B5C..0x02165B68 (WcmKeepAliveAlarm).
A real boundary: the code after it comes from another object. Nothing left to unify.
