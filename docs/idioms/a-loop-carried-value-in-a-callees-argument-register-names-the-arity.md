# A loop-carried value the compiler parks in r1 across a call is that call's second argument

summary: `docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md`
warns that a call which leaves r1 to r3 alone says nothing about its arity;
this is the case where it says everything, because the register the value sits
in is not a leftover but a *choice* the allocator made, and it only makes that
choice when the value is an argument.

Found in: `src/matched/unit_0201C6B4.c` (0x0201C6C4), against
`src/matched/unit_0201D7C4.c` (0x0201D7C4)

`sub_0201C6C4` walks a linked ring, testing one field of each record:

```
0201C6C4  push {r3, r4, r5, lr}
0201C6C6  adds r5, r0, #0
0201C6C8  adds r4, r1, #0          /* the searched-for value */
0201C6CA  ldr  r1, [r5, #0x10]     /* q, in r1 */
...
0201C6D2  ldr  r0, [r1, #0x14]
0201C6D4  cmp  r0, r4
0201C6D6  bne  .next
0201C6D8  movs r0, #1
0201C6DA  pop  {r3, r4, r5, pc}
.next:
0201C6DC  adds r0, r5, #0
0201C6DE  bl   func_0201D7C4       /* r1 still holds q */
0201C6E2  adds r1, r0, #0          /* ... and the result goes back into r1 */
0201C6E4  bne  .loop
```

Written with a one-parameter `func_0201D7C4(p)`, every source shape tried keeps
`q` in **r0**, which is free, needs no move, and is the same length: the
`adds r1, r0, #0` becomes a `cmp r0, #0` and eight of the thirty-eight bytes
are wrong with the control flow, the stack layout and every other register
identical. Thirty spellings were compiled (guard shapes, `for` against
`while`, pointer and integer types, casts on the call result, extra locals,
declaration orders) and all thirty gave r0. Declaring the callee with two
parameters and writing `q = func_0201D7C4(p, q);` is `EXACT` on the first try.

The reason is that mwccarm assigns the argument registers first. With two
declared parameters `q`'s live range ends at r1, the callee's second argument
register, so the allocator puts it there for the whole loop and spends the move
to get the result back in; with one declared parameter r1 is an ordinary
caller-saved scratch and r0 is the cheaper home.

The reverse reading, which is the useful one: **a value that is live across a
call, reassigned from that call's result, and held in r1, r2 or r3 rather than
r0 when r0 was free, is an argument of the call.** The cost of getting it wrong
is a move that looks like a scheduling artefact, so it is worth checking before
spending an hour on register allocation.

The three ways this can be corroborated, in order of strength: another call
site that has to set the register up (the `unit_0200C9EC.c` case in the
forwarding-call idiom), a matched file that already declares the callee, or the
callee's own body. Here the third settles it: `func_0201D7C4` reads its second
parameter as the cursor it is stepping from, and it is matched.
