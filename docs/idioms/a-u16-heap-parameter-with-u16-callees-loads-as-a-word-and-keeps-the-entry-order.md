# A u16 heap parameter with u16 callees loads as a word and keeps the entry order

summary: a heap id that arrives as a stack parameter and is loaded with a word
`ldr rX,[sp,#K]` can still be a `u16` parameter. When the callees that take it
declare a `u16` heap parameter, mwcc loads the u16 stack parameter with a word
`ldr` (no `add rN,sp,#K; ldrh`). With only u32 consumers it uses `ldrh`. The
type also changes the scheduling of the entry block.

Found in: `src/matched/ov/ov096_func_02187F00.c` (wave D9r lane 35, 2026-10-05).

## Symptom

The function takes `heap` as its fifth parameter and first calls the debug
allocator `func_02030734(heap, size, 1, file, line)`. The image homes the
register parameters, then loads heap (`ldr r5,[sp,#0x20]`), then the line pool
word, then the file pool word. With `u32 heap` and u32 heap parameters on the
callees, the build hoists the line pool load above the parameter homing
(14 bytes). Ten lanes tried parameter and tag types, inline helpers, K&R forms
and labels without a change. `u16 heap` with the u32 callee prototypes gives
`add r0,sp,#0x20; ldrh r5,[r0]` (wrong size), so earlier lanes rejected it.

## Fix

Declare the parameter `u16 heap` and give the heap-taking callees their house
`u16 heap` parameters (`func_02030734(u16, ...)`, `func_020490F4(u32, u16)`,
`func_02020F14(u16)`, ...). The heap load becomes a word `ldr` and the line pool
load stays below the homing. EXACT. Changing only one callee to u16 is not
enough; with most of the consumers u16 it closes.

Compare ov177 021E7520 (`u16 heap` as the 11th parameter, loaded by `ldr r4,
[sp,#0x58]`), which has the same entry order.
