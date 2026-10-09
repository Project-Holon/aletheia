# unit_021B7560.c (ov103)

Merged as far as the verifier and the compile allow. Remaining parts:

- `unit_021B7560_p01.c`: func_021B7560 .. func_021B7954 (9 functions)
- `unit_021B7560_p02.c`: func_021B795C .. func_021B91B4 (69 functions)

Blockers:

- data labels d_021B92D4, d_021B924C, d_021B927C, d_021B9310, d_021B9298, d_021B9228/34/40, d_021B92B4, d_021B925C, d_021B926C, func_021B9220 (data) have no witness outside a whole-TU window. Needed casts: (struct State *)(p+0xcc), (u32 *)p, (u8 **)(p+0x160), extra unused int parameter on func_021B8C14. func_020409B4 uses a u8 parameter (definition has u32) because the original masks the argument; a u32 prototype loses 4 bytes in func_021B8FA0.

Shared rule: the part files must stay separate where a data label only has witnesses in the other part.
