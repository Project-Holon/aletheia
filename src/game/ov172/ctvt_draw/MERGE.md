# ctvt_draw (ov172)

Translation unit 021BA174..021BE0B0. Two Thumb parts, each byte-exact (round 5 lane s11 merged the old p02 and p03).

- p01: 021BA174 .. (old p01+p02).
- p02: old p02+p03 merged. func_021BE210 is (char *a, u8 idx); func_021BDEF0's caller local v is a u8.

Open boundary p01 | p02:
- merged build differs in func_021BCC40 (13 bytes, r6/r7 swap). The function is exact with the getters
  func_021BE034/03C/044/00C declared extern; with their definitions (p02) in the same file the register
  allocation changes. Return type of the getters did not help.
- func_0201C724 has two prototypes: p01 (void *owner, six u32_021BCC40 (unsigned long) values, u16 f) and p02
  (u32 owner, void *b, short y, u32 c, void *d, u32 e, u32 f). func_021BDEF0 needs short on its x argument
  (sign extension at the caller), so one canonical prototype breaks func_021BCC40.
- func_02040588 is (unsigned char, unsigned char) in p01 and (u32, unsigned char) in p02; p01 passes constants only,
  so p01 can take the u32 form.
