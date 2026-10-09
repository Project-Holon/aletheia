# gds_rap merge status (lane 044b)

parts p01..p03 remain (was 6). p01 and p03 are c99 files; p02 is ov125_func_021D770C (0x021D770C), a single ARM
function with no `lang: c99` in its settings. Settings differ from its neighbours (compiler flags), so it is a real
file boundary: never merge it into p01 or p03.

Round 5 (lane s13): p02 gained lang: c99 and builds EXACT with it. p01|p02 is a Thumb to ARM change (real). p02|p03 (both ARM, 1.1p1, c99) merges to DIFF; not located.
