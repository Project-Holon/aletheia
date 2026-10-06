# btl_setup.c (arm9)

Three parts (`_p01`, `_p02`, `_p03`) and two singles (func_020136E0, func_02013734) remain, in address order
p01, p02, func_020136E0, func_02013734, p03.
Done in this pass: p01 absorbed the old parts 02, 03, 04, 05, 06 (prototypes of func_020127A4 and func_0201333C
unified to the definitions, casts added at calls, two generated stubs rewritten with typed pointers: func_02012DAC,
func_0201333C, bytes unchanged).
Blockers left:
- p01 + p02: func_0201A920 is declared `struct Party *func_0201A920(u32 heap)` in p01 but p02 passes a u16 value; with a
  u32 parameter p02's func_02013528 changes (DIFF), with a u16 parameter p01 changes. Neither a K&R `()` declaration
  nor a u16/u32 swap works; the true prototype is in another TU. Needs the argument types of all callers checked.
- func_020136E0, func_02013734: local structs Obj020136E0 / Obj02013734 are views of the same battle-setup object as
  BigObj*/Obj00155 in p01; the code passes them where u8 * is expected. A struct pass that merges the BigObj views
  (offsets in p01: BigObj_0201283C, BigObj_02012914, BigObj, BigObj_02012AE4, BigObj_02012C0C) is needed first.
- p03: struct Obj/ZoneData views, same issue.
