# Wave 14: net_irc_wireless.c and __dec2num

EXACT 9: 0x0203E420, 0x0203DAC4, 0x0203D8F0 (the three open territory rows) plus six unlabelled leaves filed as witnesses: 0x0203DC68, 0x0203DC4C, 0x0203D010, 0x0203B1B0, 0x0203CFF0, 0x0203D000.
MATCH 1: 0x0203DC70 (src/pending, 1968/1968 bytes, 78 of 80 sites). The unwitnessed sites are +0x484 func_0203CFF0 and +0x4F0 func_0203D000.
DIFF 1: 0x0209739C __dec2num (unchanged at 721 bytes out, 1520 of 1524).

Levers:
- E420 takes an argument: r0 is passed straight through to the +0x78 method.
- DAC4: `u8 buf[6] = {0,...}` in a block scope takes the array address first. New idiom: an-initialised-local-array-takes-its-address-before-the-stores.md.
- D8F0: the header parameter is `const Base *`.
- DC70: its "64 B" row is really the whole 19-state switch. The only lever was `i = 0;` before the func_02087C6C(mac) call.

Blocker for DC70: layout/symbols_sdk.txt/.json list 0x0203CFF0 (DWC_IsSendableReliable) and 0x0203D000 (FATFS_FormatDrive) as THUMB. These are false signature hits: the bytes are ARM tail-call wrappers, now EXACT. Integrator: drop the two rows, set both symbols lines in src/pending/func_0203DC70.c to `arm`, and re-verify. It should come out EXACT.

__dec2num: the MSL ansi_fp.c shape, with MSL's helper split kept as calls (__str2dec, __less_dec, __equals_dec, __minus_dec, __num2dec_internal, copysign, pow, ldexp, __fpclassifyd), is the wave-9 source. Its residue after this attempt: 721 bytes out, 1520 of 1524. hill 800 and anneal 2000 (--types) give only the rejected u8-counter size compensation (373/380).
New finding, from bisection: 1.1p1 hoists the loop invariants (&dec, &x64, the 0 of the `& 1` mask) to the top of the region where registers are free. That is +0x2A0, or the function entry once the chunk loop is gone. The image keeps them in the loop preheader. Loop spelling does not move this. Use count and register pressure do (the struct swap and the latch copy). Recorded in docs/notes/pkt_0209739C.c.txt.

Near misses: none open in net_irc. dec2num is a 4-byte size gap: one `mov r0, #0` is lost to the shared zero.

Integrator: seed (ARM, all with matched sources): 0x0203DC4C, 0x0203DC68 (func_0203DC4C.c, func_0203DC68.c, pkt_0203DAC4); 0x0203CFF0, 0x0203D000, 0x0203D010, 0x0203B1B0 (pkt_0203DC70). Remove the bogus SDK rows 0x0203CFF0 and 0x0203D000.
Family header written: docs/families/net_irc_wireless.h.
Shards verified: pkt_0203DAC4 (x2), pkt_0203DC70 (x2), pkt_0203D8F0.
