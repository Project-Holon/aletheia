# tree_ov016 report (2026-09-27)

Filed: nothing. Every open function I reached in ov016 is TwlDWC libdwcutil vendor code, so after the SDK-lane notice I pulled my filed work back into scratch (two shards and seven files, all mine and untracked; `manifest --check` clean afterwards).

## Roots
- func_021D88D6 (14186 B) and func_021D7D48 (2958 B): phantoms. They are stale Thumb labels in atermset.o rodata. Code ends at the pool word at 0x021D77A8. From 0x021D77AC there is a code-pointer table, the AES rcon table and the Td2/Td3/Td4/Te0-Te4/Td0/Td1 tables (for example Te0 at 0x021D83F8 and Te4 at 0x021D93F8).
- func_021B62C0 (AOSS_Init_old): the SDK lane took it and filed its tree.
- func_021BBC8C (MD5Transform): tree of 2.

## Held in scratch, not filed (SDK lane: take these as they are)
All compiled with `../2.0/sp1p2 -O4,p` (atermset.o carries the 3.0.0.126 stamp).
- EXACT: MD5Transform 0x021BBC8C (RFC 1321 reference; dsi/1.1p1 misses by 1011 bytes in pool layout), MD5_memset 0x021BC544 (EXACT*), aeskw_xor64 0x021BAF90 (EXACT*), rijndaelKeySetupEnc 0x021BAFD8, rijndaelKeySetupDec 0x021BB290, rijndaelEncrypt 0x021BB420, rijndaelDecrypt 0x021BB7DC (rijndael-alg-fst v3.0, the non-FULL_UNROLL loop). All of the table relocations resolve through sole-ref.
- Near: keywrap_decrypt 0x021BADD8, 6 bytes out (one r2/r3 swap in the second 8-byte copy). keywrap_encrypt 0x021BAC20: the compiler strength-reduces `i*8` into an induction register, while the original recomputes `lsls r1,r4,#3` on each pass.
- Lever: the inline 8-byte copies are `{u8 *d_=d; u8 *s_=s; unsigned k_; for(k_=8;k_!=0;k_--) *d_++=*s_++;}`.
- The file ov016_func_021BBC8C.c holds Decode (0x021BC500), not 0x021BBC8C, so the name is misleading.

## Remainder
There is no game code in ov016. All 89 open addresses without a symbols_sdk row that have a scannable run of bytes turn up verbatim in libdwcutil objects (libaoss.o, rakuraku.o, scene*.o, wds.o and others). Those rows are gaps in libmatch, and the addresses belong to the SDK lane. Scratch holds the list: tree_ov016/vscan.txt.
