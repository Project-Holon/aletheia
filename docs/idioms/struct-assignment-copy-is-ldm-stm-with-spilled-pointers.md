# A 64-byte struct assignment is four ldm!/stm! pairs with both pointers reloaded from the stack

summary: `*dst = tmp;` for a 64-byte struct compiles to `ldr r4,[sp,#s]; ldm r4!,{r0-r3}; str r4,[sp,#s]; ldr r4,[sp,#d]; stm r4!,{r0-r3}; str r4,[sp,#d]` repeated, which looks like inline asm. Its stack-resident pointers raise register pressure for the whole function, so the rest of the function spills early too.

Found in: src/matched/MTX_Concat44.c (0x0207BE14)

The tail was read as the MI_Copy64B inline asm. That draft was 92 bytes short,
with a 0x54 frame against 0x74, and none of the image's early spills of b
elements. Writing the vendor `if (p == &tmp) { *ab = tmp; }` reproduces the
copy, the eleven spill slots and the `addne sp`/`popne` early exit.
