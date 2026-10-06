# field_sound_system (arm9)

Parts field_sound_system_p01..p05 (EXACT) plus member unit_02028F18.c (between p04 and p05 by address).

Blocked by one object seen through several local structs (struct Sys_020288C4, Sys_02028DCC, Sys_02028E0C, Sys_02028E48 vs struct Sys) and by two prototypes of func_02028F30 (struct SoundParam2 * vs u8 *). Unify the Sys views by offset (struct pass), then merge.
