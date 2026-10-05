# A width stored in the handle temp it replaces keeps the original colours

summary: when a text block gets a string handle into a temp and then the string's width, and a
separate width local swaps two callee-saved registers or hoists a constant, the original reused
the handle temp for the width (`x = (u16)Width(x)`), as people do with scratch variables.

Found in: src/matched/ov/ov222_func_021B9964.c (0x021B9964); also src/matched/ov/ov220_func_021B9CBC.c (0x021B9CBC)

Shape: `x = GetString(...); x = (u16)GetWidth(x, ...);` or `h = (u16)f2(); n = w1 + 8 + h;`
with `h` reused later for an unrelated value.

Wrong C: a fresh `u16 w = ...` local for the width. The new value gets a new virtual register,
created later than the neighbouring values, so the colouring order changes (registers swap, a
constant is hoisted into a callee-saved register, an extra spill appears).

Right C: assign the width back into the temp that held the handle (or into the scratch temp
already used in the block). Keep the temp `u32` and truncate at the assignment.

Human reading: reusing one scratch variable for successive values in a block is ordinary code;
it is not a stand-in. Try it whenever a residue is a register swap among values that live in
one text or draw block.
