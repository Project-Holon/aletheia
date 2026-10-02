# A value returned on the early path precolours its register to r0

summary: when a value loaded before a branch keeps r0 through the next block while a constant built after the branch takes r1 (`ldr r0, [..]; cmp r0, rX; ble out; movs r1, #K; lsls r1, ...; subs r0, r0, r1`), and the branch target is the epilogue, the function returns that value on the early path. The void form always colours the block-2 constant first into r0 and gives `subs r0, r1, r0`.

Found in: src/matched/ov/ov021_func_021A4F58.c (0x021A4F58, ov021, Thumb)

The residue was 5 bytes: the original keeps v.y in r0 and the constant
0x8000 in r1; the void transcription swapped them. Three rounds measured
dozens of spellings as inert (compare order, declaration order, compound
forms, helpers, unions, type-punned reloads, self-assignments, goto and loop
shapes). In MWCC the block-2 constant is coloured before the cross-block
value, so it always takes r0 unless r0 is already claimed. A `return v.y;`
on the path that branches to the epilogue moves the value into r0 at the
return, the allocator coalesces that copy, and v.y is then precoloured r0
for its whole live range: the constant falls to r1 and the subtract result
biases back onto r0.

The other path must return too (here `return 7;`, the state just stored).
Without it, the `movs r0, #7` of the store recolours to r1.

How to spot it: a scan of every overlay found this shape (constant in the
higher register, the other operand the destination in r0, the operand not a
call result) only in this function. Every other instance has a call result
in r0. So when a value sits in r0 for no visible reason and the branch over
it lands directly on `add sp; pop {.., pc}`, check whether r0 is the return
value on that path. The caller can still declare the function void and
ignore the value.
