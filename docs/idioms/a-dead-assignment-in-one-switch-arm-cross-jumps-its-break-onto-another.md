# A semantically dead assignment in one switch arm cross-jumps its `break` onto another arm's body

summary: when two switch arms end by assigning the same constant to the same
result variable, the compiler cross-jumps them, and the earlier arm's `break`
then compiles to a branch onto the LATER arm's own copy of the assignment
rather than onto the shared tail; the assignment can be semantically dead and
you still cannot omit it, because omitting it moves that one branch target by
two bytes and nothing else in the function changes.

Found in: `src/matched/func_0202363C.c` (0x0202363C, where it was already
right), and it closed `src/matched/func_02022A44.c` (0x02022A44),
`src/matched/func_020234C0.c` (0x020234C0) and `src/matched/func_0202390C.c`
(0x0202390C) in one edit each.

The wipe_sub family runs four independent screen-wipe effects and drives every
one of them through the same four-arm phase machine:

```c
u32 step(struct WipeTask *t)
{
    void *obj = t->obj;
    u32   ret = 0;

    switch (t->phase) {
    case 1:
        if (poll(obj) == 1) { ...; t->phase += 1; }
        break;
    case 2:
        release(obj);
        free(t->obj);
        t->phase += 1;
        t->obj = 0;
        ret = 1;          /* <- this line */
        break;
    case 3:
        ret = 1;
        break;
    default:
        break;
    }

    return ret;
}
```

Written without `ret = 1;` in case 2, three of the four functions compile to
the right size with every byte right except one branch displacement:

```
  +003A    str r0, [r5, #0xc]      | str r0, [r5, #0xc]
* +003C    b #0x2022a82            | b #0x2022a84
  +003E    movs r4, #1             | movs r4, #1
  +0040    adds r0, r4, #0         | adds r0, r4, #0
  +0042    pop {r3, r4, r5, pc}    | pop {r3, r4, r5, pc}
```

The image branches to `0x2022a82`, which is case 3's own `movs r4, #1`, two
bytes before the shared tail the compiler picks. With the assignment restored
the two arms' `movs r4, #1` are identical, cross-jumping merges them onto case
3's copy, and case 2's `break` lands there: `EXACT`.

The assignment is dead in the effect's own terms — the caller re-polls and
phase 3 answers 1 on the next frame anyway — so there is no behavioural test
that would ever suggest it. It is a fact about the original source, recoverable
only from the branch displacement.

**Nothing else reaches it.** On `func_02022A44` the residue survived 131 single
mutations of `tools/permuter.py --mode hill` and 3000 compiles of
`--mode anneal --budget 3000 --types`, both spending their full budget and both
reporting `asm=5 bytes-out=2` unchanged from the baseline, because this is a
cross-jumping decision and the permuter's mutation table targets register
allocation. The `--explain` map is empty — there are no register substitutions
at all, which is itself the tell that the residue is control flow rather than
allocation. Every other spelling of the switch is the same two bytes out or
worse: a `goto` into case 3 (66 bytes, 10 out), a reordered case set (26 out),
`default` before case 3, an if/else-if chain (66 bytes, 51 out), an added empty
case (80 bytes, 73 out), `return ret` in place of the `break`, and swapping the
declaration order of the two locals.

The general shape to watch for: **a `b` whose target is the immediately
following instruction.** The compiler never emits one from a plain `break`, so
when the image has one, some arm's exit was merged onto a copy of shared code
that the compiler would otherwise have kept only once. Look for what the two
arms have in common at their ends, and write it out in both.

This is the same mechanism as
`docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md`, seen from the
other side: there, writing shared statements in every arm is what lets the
compiler cross-jump them; here, the cross-jump's surviving copy is what a third
arm's `break` is measured against, so an arm you did not write the statement
into is the one whose branch comes out wrong.
