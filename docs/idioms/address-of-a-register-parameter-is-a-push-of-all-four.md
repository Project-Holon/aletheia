# Taking the address of a register parameter opens the function with `push {r0, r1, r2, r3}`

summary: a function whose prologue is `push {r0, r1, r2, r3}` before its real
register save, and whose epilogue is `pop {r3}` / `add sp, #0x10` / `bx r3`,
has taken the address of one of its first four parameters; the four words are
the home area the ABI does not otherwise reserve, and `sp + 0x10 + <saved>` is
which parameter it was.

Found in: `src/matched/unit_02019A50.c` (0x02019A50)

`func_02019A50` XOR masks a byte range with a pseudo-random stream and steps
the generator through a pointer:

```
02019A50  0f b4     push {r0, r1, r2, r3}          /* the home area */
02019A52  f8 b5     push {r3, r4, r5, r6, r7, lr}
...
02019A5C  08 af     add  r7, sp, #0x20             /* &seed: the third slot */
02019A5E  38 1c     adds r0, r7, #0
02019A60  ..        bl   func_02019A7C
...
02019A72  f8 bc     pop  {r3, r4, r5, r6, r7}
02019A74  08 bc     pop  {r3}                      /* lr, out of the home area */
02019A76  04 b0     add  sp, #0x10                 /* discard the four words */
02019A78  18 47     bx   r3
```

mwccarm passes the first four arguments in registers and reserves no stack for
them, so a parameter whose address is taken has nowhere to live. Rather than
allocating a separate local and copying, this front end pushes all four
argument registers on entry and treats that block as the parameters' storage.
Three things follow, and all three are visible in the bytes.

**The frame offset names the parameter.** With six registers saved after the
push, `sp + 0x20` is the third of the four words, so the address taken is
`&seed`, the third parameter. Reading `add rN, sp, #k` as a pointer to a local
instead sends the search after a local that is not there, and every other
stack offset in the function is then off by 16.

**The epilogue is not a `pop {..., pc}`.** `lr` was saved inside the second
push, so the return address comes back into `r3` and the function ends
`add sp, #0x10; bx r3` rather than the usual `pop {..., pc}`. That shape, not
the prologue, is usually what is noticed first.

**The parameter is still by value.** The callee writes through the pointer,
but it is writing into its own home slot, so the caller's variable is
untouched. Here that is load bearing: `func_02018D34` masks the same 0x80
bytes twice with the same seed to undo the mask, which only works because the
first call did not advance the caller's seed.

The C is the obvious C; nothing about it is special except that the address is
taken:

```c
void func_02019A50(u16 *p, u32 size, u32 seed)
{
    u32 i = 0;
    u32 n = size >> 1;

    if (n != 0) {
        u32 *s = &seed;

        do {
            p[i] ^= func_02019A7C(s);
            i++;
        } while (i < n);
    }
}
```

Two placement details cost time. `u32 i = 0;` has to be assigned before
`n = size >> 1`, or the zero arrives from a literal pool, which is
`docs/idioms/assign-the-loop-counter-before-the-loop-bound-or-zero-costs-a-pool-word.md`.
And `u32 *s = &seed;` has to sit **inside** the `if`, because the original's
`add r7, sp, #0x20` is after the `beq` that skips the loop; hoisting it to the
top of the function swaps those two halfwords and nothing else.

Writing `func_02019A7C(&seed)` at the call site instead of binding the pointer
first is four bytes shorter: the compiler then rematerialises `add r0, sp,
#0x20` inside the loop and never spends a callee-saved register on it.
