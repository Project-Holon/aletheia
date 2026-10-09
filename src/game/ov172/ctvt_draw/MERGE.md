# ctvt_draw (ov172)

Translation unit 021BA174..021BE0B0. Three Thumb parts, each byte-exact.

- p01: old p01+p02 merged (func_021BA280 takes `u16 b` and returns `char *`; its call site
  casts the result; func_0201C724 and func_02045EC0 use the u32_021BCC40 typedef in the
  shared declarations).
- p01 | p02: merged build differs only in func_021BCC40 (13 bytes, r6/r7 swap). The
  function is exact with the getters func_021BE034/03C/044/00C declared extern; when
  their definitions (p02) are in the same file it changes register allocation. Return
  type of the getters (u32 vs the u32_021BCC40 `unsigned long` typedef) did not help.
  func_0201C724 needs `short` on its x argument in func_021BDEF0 (sign-extension in the
  caller); a canonical prototype with a short parameter breaks func_021BCC40.
- p02 | p03: extra zero-extensions and shifted pools; func_021BD820's bgId must be u8
  (passed to a u8 parameter), func_021BE210(p, v) has `u8 *` versus `char *` views.
