# ov095 unit_0689CFF0: boundaries left

Each boundary below is a real file boundary for now (uncovered bytes, an ARM/Thumb switch, a lang change, or an asm veneer).

- unit_0689CFF0_p01.c | unit_0689CFF0_p02.c: ISA change thumb -> arm; lang change "" -> "c99" (merge not tried across it); 2 uncovered bytes before the next part (stub, pool or padding)
- unit_0689CFF0_p02.c | unit_0689CFF0_p03.c: ISA change arm -> thumb; lang change "c99" -> "" (merge not tried across it)
