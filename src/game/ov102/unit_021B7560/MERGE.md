# unit_021B7560.c (ov102)

Merged as far as the verifier and the compile allow. Remaining parts:

- `unit_021B7560_p01.c`: func_021B7560 .. func_021B78E4 (6 functions)
- `unit_021B7560_p02.c`: func_021B78EC .. func_021B8A40 (53 functions)

Blockers:

- data labels: merged range would cover the whole TU, so d_021B8B2C, d_021B8AC4, d_021B8AEC, d_021B8B0C, d_021B8B5C and d_020A1448 lose every witness outside the window (match.py: 'has no witness outside'). The compile itself works once these casts are made: func_021B8464((State_021B81B0 *)..), (Row_021B81B0 *), (Rec *)(p+0xac), (struct State *)p, func_021B7C04() called without argument, func_021B7AAC(unsigned, void *) with two unused parameters. Structural, not fixable in source.

Shared rule: the part files must stay separate where a data label only has witnesses in the other part.
