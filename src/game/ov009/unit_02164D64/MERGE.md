# unit_02164D64 (ov009): 2 parts left

- `unit_02164D64_p01.c` (02164D64..02165B5C): one file, one canonical WCMWork struct, the two
  system.o statics (WCMi_OverridedDeviceId, wcmw) as file statics. Verdict MATCH, not EXACT: the
  ABS32 pool words that point at the ov009 .bss statics cannot be attested by match.py (the
  tool cannot resolve a .bss-relative target in an overlay), so every use of `wcmw` shows as
  unresolved. The code bytes are identical. Round 5: the 16-byte asm stand-in at 0x02164D64 is
  now plain C (`void CRYPTOi__BN_lshift1(void *buf, long len) { WCM_InitEx(buf, len, 1); }`,
  mwcc emits the tail call by itself).
- `unit_02164D64_p02.c` (02165B68 WCMi_GetDefaultDeviceId): EXACT.

Boundary p01 | p02: 12-byte linker veneer at 0x02165B5C..0x02165B68 (WcmKeepAliveAlarm).
A real boundary: the code after it comes from another object. Nothing left to unify.
