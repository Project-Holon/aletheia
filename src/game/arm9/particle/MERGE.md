# particle (arm9)

Parts p01..p06, all dsi/1.1p1 ARM. Round 3 merged p05 from three members. Round 6 wrote 16 hidden arena allocators (0x02050F1C..0x020511EC) and merged old p06|p07 (g_020A1578/84/90 are now Vec3 in both views).
Left:
- p01|p02: c99=DIFF (code changes when merged).
- p02|p03: p03 function returns void where p02 expects int (illegal implicit conversion from void to int, line 89).
- p03|p04: an AreaMan pointer parameter is called with int in p04 (illegal implicit conversion).
- p04|p05: struct tags Entry and Owner are defined twice with different fields (f1C missing in one view).
  Needs one canonical Entry and Owner built by offset.
- p05|p06: p06 uses a global as a struct that p05 declares as a scalar (not a struct/union at line 1028).
