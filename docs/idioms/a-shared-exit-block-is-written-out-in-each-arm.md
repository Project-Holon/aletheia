# A shared exit block is written out in every arm, and a bare goto in front of it is two bytes short

summary: when several paths end in the same store and return, the original
reaches them with `bcc` over a `b` to one copy; reproducing that means writing
the statements out in each arm and letting the compiler cross-jump them, not
putting one copy behind a label and jumping to it.

Found in: `src/matched/unit_0200C3F4.c` (0x0200C480),
`src/matched/unit_0200DA64.c` (0x0200DC0C)

`func_0200C480` has three paths into `a[pos] = id; return pos;` and a fourth
that returns without storing. The original spends one copy of each:

```
        ldrb r0, [r5, r4]
        cmp  r0, #0x19
        bne  .next          /* offset 0: skips exactly the next halfword */
        b    .store
.next:  ...
        blo  .loop
        b    .ret
        ...
        bgt  .store
        ...
.store: strb r7, [r5, r4]
.ret:   adds r0, r4, #0
        pop  {r3, r4, r5, r6, r7, pc}
```

Three source shapes were tried for the loop's early exit and only one of them
is those four bytes.

```c
if (a[pos] == 25) { a[pos] = id; return pos; }   /* 8 bytes: the block is emitted twice */
if (a[pos] == 25) { goto store; }                /* 2 bytes: one beq straight to .store */
if (a[pos] == 25) { a[pos] = id; goto out; }     /* 4 bytes: bne over b, and one copy   */
```

The middle one looks like the obvious way to express "jump to the shared
tail", and it is wrong in a way that is easy to misread as a scheduling
problem: with a label directly in front of the store, the conditional branch
reaches the target itself and the `b` disappears. The third one gives the
compiler two *identical* blocks, cross-jumps them into one, and leaves behind
the inverted conditional over an unconditional branch to the survivor. The
`return pos` at the end of the function is the same tail, reached by the
`goto out`, which is why the loop-exhausted path is a `b .ret` rather than a
second epilogue.

`func_0200DC0C` is the same finding on a switch: its two arms both end in
`func_0200DBA0(p, 0, op); p->unk02 = v;` with different constants, written out
in full in each arm, and the compiler emits the call and the store once with
each arm branching to it after setting up its own arguments. Hoisting the
common part out of the switch by hand changes which side of the merge the
default path lands on and reallocates the function, exactly as
`docs/idioms/switch-arms-tail-merge.md` records for the assignment case.

So the rule for reading it back: a `bcc` whose displacement is zero, followed
by a `b`, is a cross-jumped block, and the source repeated those statements.
A single conditional branch straight to the shared block is a label in the
source. The two are two bytes apart and nothing else in the function moves.
