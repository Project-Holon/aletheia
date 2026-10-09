# unit_021D7CEC merge status (lane 044b)

parts p01..p03 remain (was 6). Every boundary left is a 12-byte linker veneer that no function covers:
- p01|p02: veneer at 0x021D7D24 (`ldr ip,[pc]; bx ip; .word target`, reached as func_021D7D24) between func_021D7D20 and func_021D7D30.
- p02|p03: veneer at 0x021D85DC between func_021D85C0 and func_021D85E8.
Merging across either gap gives DIFF because the veneer bytes are not emitted. Veneers are not matched work.
