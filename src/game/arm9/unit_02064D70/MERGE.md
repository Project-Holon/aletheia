# unit_02064D70 (arm9)

Round 17 (lane L11): 3 parts -> 2.

- `unit_02064D70_p01.c`: func_02064D70 .. func_02065134 (compiler 1.1p1)
- `unit_02064D70_p02.c`: func_020651B8 .. func_02066754 (compiler ../2.0/sp2; old p02, p03, p04)

p03 (func_0206615C, func_02066380, func_020663D0) is now written over the big RendererBss (unk_04 is
bDonotUseSRTransform, slot is stackPos_, obj->flags is pCurrentInstance_->rendererCore.flag, tx/ty are _20/_21).
That is EXACT for func_0206615C and func_02066380. func_020663D0 is EXACT only through a second symbol at the
same address, `g_02147B88_head` (struct RendererBssHead, the first 0x14 bytes, no arrays): with the big struct the
scheduler hoists the stackPos_ load above the stores to the local matrix (44 bytes out). Guess: this is a
stand-in for whatever declaration the original had in view (probably the original file declared the manager
head differently); only func_020663D0 uses the alias.

Boundary left: p01 | p02 is a compiler change (1.1p1 / 2.0), tested both ways in round 5 and w10d.

Round 18 (L19): p01 under 2.0/sp2 and p02 under 1.1p1 are both DIFF again, so the compiler boundary stands (two
different libraries' objects). func_020663D0 still needs the g_02147B88_head view (marked stand-in in p02); tried a
static inline stackPos_ accessor and plain fields of the full struct: both leave the same 44 bytes (the 2.0
scheduler hoists the stackPos_ load above the stores to the local matrix).
