# fld3d_ci (ov021)

Six parts, every one EXACT (was 8). Open boundaries (compile errors, not byte changes):
- p01|p02: func_021C1A84 (u8 * against four u32). p02|p03: func_021C1C24 (u32 x4 against char *, char *).
- p03|p04: func_020124E8 result indexed as void * in p04 (needs u32 * or a typed accessor); Obj,
  Obj_021C2764 and Obj_021C2CF4 are one object. The harmonizer also broke a cast on func_020124F0.
- p04|p05: func_021C3248 is void in p05 and takes void * in p04.
- p05|p06: func_0200BCB8 is called with four arguments in one part and defined with one.