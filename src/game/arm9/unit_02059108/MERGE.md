# unit_02059108 (arm9)

Parts p01..p05, all ARM.
- p01|p02: a 12-byte linker veneer (ldr ip,[pc]; bx ip; .word) at 0x0205919C is not covered by any
  function. Real boundary. (Round 3 removed the type and arity conflicts between p01 and p02: asm
  func_0205911C now takes the user data pointer, the func_02059108 alias is DWCi_Acc_GetFlags.)
- p02|p03, p03|p04: p03 (func_02059588) is compiled with the 1.2 compiler: real boundary.
- p04|p05: another 12-byte veneer (ldr ip,[pc]; bx ip; .word) at 0x020596F0, before DWC_CreateUserData.
