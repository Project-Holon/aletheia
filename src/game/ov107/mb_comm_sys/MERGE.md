# mb_comm_sys.c (ov107)

Round 5 (lane s11): 10 parts reduced to 2. Both verify EXACT.

- p01: 021EE740 .. 021F1230 (everything that was p01 to p09).
- p02: 021F1370 .. 021F1404 (func_021F1370, func_021F13AC, func_021F13BC, func_021F13E8,
  func_021F13F4, func_021F13F8, func_021F1400).

Why two files: nothing covers 021F1230 .. 021F1370 (0x140 bytes). It is unmatched code, so the
merged build would pull p02 0x140 bytes too early. Match the code in that range, then p01 and p02 merge.

Done in this pass: d_021F6EAC is one struct Masks { f00, f04, f08, f0A..f14, f18 } with named fields
(no offset arithmetic, no H()/P() macros); d_021F6EA0 accesses use struct Counter; d_021F6E1C,
E24, E08, E0C are const char[]; File is the real file struct in every use; func_02040588,
func_02049658, func_020413B0 have one prototype each (bg is a u8 in func_021EF444);
func_021F1060 returns int; func_021EFE3C takes an unused u8 * parameter.
