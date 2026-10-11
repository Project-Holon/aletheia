# unit_021B3018 (ov013)

Reduced from 5 parts to 2 (round 16, lane L13): p01 = 0x021B3018..0x021B3084 (func_021B3018, func_021B3064), p02 = 0x021B3250..end (the former p03..p05). Shared types are in `unit_021B3018_types.h` (VadCfg with f8/fC, VadState, the filter state with its ring buffer and renamed hp_prev/hp_y, the TCV session struct G_021B60CC with its callback). func_021B33E0 was an `asm` stand-in: it is a tail call `MIi_CpuCopyFast(a, d_021B4C8C, b)`.

Left: the only blocker is the hidden 460-byte function func_021B3084 (0x021B3084..0x021B3250), 6 bytes off; notes and all passes in src/pending/ov/ov013_func_021B3084.c. When it is EXACT, add it between p01 and p02 and merge the two parts into `unit_021B3018.c` (types header can then be inlined).

In func_021B3364 the three arrays d_021B50CC, d_021B4C74 and d_021B4C5C stay separate externs for the same addresses as buf, x and c of the filter state: written as fields of the struct the function is 12 bytes shorter.
