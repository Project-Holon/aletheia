# ov095 btlv_scd: boundaries left

Each boundary below is a real file boundary for now (uncovered bytes, an ARM/Thumb switch, a lang change, or an asm veneer).

- btlv_scd_p01.c | btlv_scd_p02.c: ISA change thumb -> arm
- btlv_scd_p02.c | btlv_scd_p03.c: 32 uncovered bytes before the next part (stub, pool or padding)
