# An eight byte out-parameter in a five argument call is what makes the frame four bytes bigger

summary: a function whose only stack use is two out-parameters passed to a five-argument call compiles a `u32` pair to `push {lr}` plus `sub sp, #0xC`, but the original says `push {r3, lr}` plus `sub sp, #0x10`; the second local is eight bytes wide (`u64`), not four, and only that spelling reproduces the extra word, the pushed scratch register and the wider epilogue.

Found in: src/matched/func_02019E54.c (0x02019E54)

The call is `func_0201A5FC(a0, a1, a2, &q, &r)`: the fourth argument goes in
r3 and the fifth on the stack, so the frame has to hold the two locals and the
outgoing word.  With `u32 q; u32 r;` that is `push {lr}; sub sp, #0xC`, and the
whole body reproduces byte for byte — eighteen instructions, same registers,
same displacements — except that every `add sp` / `pop` / `sub sp` in the
function is four bytes and one register off.

The fix is the *width* of the first out-parameter: declaring it `u64 q` makes
the slot eight bytes and 8-byte aligned, and the compiler then reserves the
extra word.  Nothing reads `q`, so no instruction in the body changes; only the
prologue and the seven epilogues do, and the residue goes to zero.

The same accounting explains `push {r3, r4, r5, r6, r7, lr}` in front of a
`sub sp, #8` where five callee-saved registers would already have been enough:
the dummy register push is the compiler keeping the frame a multiple of eight
bytes.  A frame size that is four bytes *larger* than the locals need is
therefore a statement about a local's width, not about padding.
