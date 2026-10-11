# ov095 unit_06899DD8: boundaries left

Every boundary below is a linker veneer (rechecked 2026-10-11, bytes decoded; the earlier ISA/lang notes were the veneers):

- p01 | p02: 16-byte veneer at 0x06899DFC; p02 is the 8-byte ARM veneer 'ldr pc,[pc,#-4]' at 0x06899E0C
- p02 | p03: 16-byte veneer at 0x06899E14; p03 is the ARM veneer at 0x06899E24
- p03 | p04: p03 is an ARM veneer ('ldr pc,[pc,#-4]'), not source
- p04 | p05: three 16-byte veneers at 0x06899FA4..0x06899FD4
- p05 | p06: p06 is the ARM veneer at 0x0689A3E4
