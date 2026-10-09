# pokemontrade_demo_up (ov118): merge status

Files left (address order):

- pokemontrade_demo_up_p01.c: func_021D4664 to func_021D4C08 (11 functions)
- pokemontrade_demo_up_p02.c: func_021D4C20 to func_021D572C (11 functions)
- pokemontrade_demo_up_p03.c: func_021D5748 to func_021D5A60 (8 functions)
- pokemontrade_demo_up_p04.c: func_021D5B74 to func_021D67F8 (14 functions)

Boundaries and reasons:

Four parts remain. Parts use the same macro views (OBJ(i), SLOT0, FRAME over p + offset) with different parameter types for the same callees: part 1 prototypes take void * (func_02015EA0, func_020307B0, func_021DFD24, func_02015C48) while parts 2 to 4 pass u32 values, and func_021DFC68 takes (int, u8 *) in one view and (void *, u8 *) in another. Merging needs one struct for the object at p (fields 0x818 FADE, 0x844 OBJ[], 0x85C SLOT0, 0x860 SLOT1, 0x5F4 HEAP, 0xF2C FRAME) so that every call site passes pointers. The automatic caster stops on nested calls. Fixed this pass: func_021D4480 style stubs (func_021D6734 is now int f(int a) { return a; }).

Every file above verifies EXACT or MATCH with tools/match.py.

Round 5 (lane s11): OBJ(i), SLOT0 and SLOT1 are void * lvalues in p01 and p03 (casts at call sites removed); both still EXACT.
p02 and p04 still use the u32 view: SLOT0 + 0x16 arithmetic, *(u16 *)(SLOT0 + 0x16), (u32)func_021DFB84(...) results,
and u32 prototypes for func_02015F50, func_02015EA0/EB0, func_02015C48/C94/CAC, func_020307B0, func_021DFD24, func_021DFB4C,
func_021DFC68. Flipping their macros to void * gives about 90 'unsigned int to void *' errors. The real fix is one struct for p
(0x0C work, 0x5F4 heap, 0x818 fade, 0x844 obj[6], 0x85C slot0, 0x860 slot1, 0xF2C frame) and void * prototypes in p02 and p04.
