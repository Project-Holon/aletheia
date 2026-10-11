# ui_scene (ov067): 2 parts left (was 8, 5, 3)

Round 18 (L17b): one canonical `struct Scene` (by offset, 0x97 bytes) now replaces the 16 views S_021B796C, S_021B7A64,
S_021B7AB0, S_021B7B7C, S_021B7BE0, S_021B7CF8, S_021B7E70, S_p05, S_021B83A0, S_021B8460, S_021B8990, S_021B8A44,
S_021B8AE4, S_021B8B74, S_021B8C14, S_021B8C4C and the old p03 Scene; one `struct Ops` (fn, f4, f8) and `struct SceneEnt`
(f1c table entry). p02 and p03 are one part (p02, EXACT). fb[6] is u8 (the s8 reads cast), f48/f49 are u8, f3 is s8,
f74[5] is a byte array, bitfields at 0x86 are f86:5, ready, drag, trigger. `volatile u8 f94` is a marked stand-in for
func_021B83A0. func_020410D0 is declared `u8 index` (p03's call needs the narrowing temp).
Also unified between p01 and p02: `In`, `S_021B66FC` (the 0x38 element of S_021B63D0.ent[]), `struct Entry` split into
`CbEntry` (p01 handlers) and `SceneEnt` (p02).

Boundary left: p01 | p02, func_021B6608 (p01) calls func_021B6738 (p02). The original call passes the 4th argument
narrowed (lsls/lsrs of p->f10) and the last argument (heap) as is, and reads heap with `ldr`. The p02 definition takes
`u32 a3` and `u16 k10`, which is what its own bytes need (u16 a3 / u32 k10 shifts the callee). So the caller's view
and the definition disagree: a prototype matching the definition narrows heap and not a3; `u16 heap` in func_021B6608
turns the stack read into `ldrh`; an unprototyped `void func_021B6738();` is a redeclaration error against the later
definition. All the other p01+p02 conflicts are solved (merge compiles and every other function is EXACT with:
`void *a0` for func_021B6738, `Out fB0` in S_021B6DC0 with `&p->fB0`, `struct Obj_021B69A4 *` for func_0204B878,
`struct Obj_021B66FC *` for func_0204B294, casts at the func_021B67F8 call in func_021B62E0).
