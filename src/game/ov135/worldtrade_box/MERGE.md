# worldtrade_box (ov135): 6 parts (was 7)

w11d (2026-10-10): old p02+p03 merged (greedy driver with the harmonizer, EXACT). Boundaries left, none proven real:
- p01 | p02: typedef Menu (and Ctx_021F4D50) differ between the parts; func_020120F4 uses an undeclared struct in a
  parameter list; one `struct [3]` array passed where a struct pointer is declared.
- p02 | p03: `Work` is declared with different layouts (Work_021F5CD4 / Work_021F5E44 views of one object);
  func_021F68A4 takes a struct pointer, the caller passes a different view.
- p03 | p04: `Work` redeclared with a different layout again (`void *win` at 0xD40, `wins[6]` at 0xD90).
- p04 | p05: u8 * passed where a local struct pointer is expected (func_021F8358, func_021F875C); g_02203C00 declared two
  ways; func_021F91A0 prototype differs.
- p05 | p06: tbl_02202FC4 / tbl_0220301C declared as arrays of two different row structs.
Next step: one canonical Work (same object as worldtrade_adapter and worldtrade_enter, offsets 0xB6C, 0xD40, 0xFA0 seen in all three).
