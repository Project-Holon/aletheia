# Initialise the result local before the input local, or every arm of the chain grows its own return

summary: in a function that classifies one loaded value into a result local, the
order of the two initialisations decides which register holds the result, and
that decides whether the arms branch to one `adds r0, rN, #0; bx lr` tail or
each carry its own `bx lr`; initialising the input first is 28 concrete bytes
wrong and two bytes short with identical control flow.

Found in: `src/matched/unit_02012AE4.c` (0x02012AE4)

`func_02012AE4` buckets a `u16` field into 0, 1, 2 or 3 with three ranged
tests. The original keeps the answer in `r1`, uses `r0` (the dead parameter
register) as the scratch for the four constants, and reaches one shared tail:

```
ldrh r2, [r0, #0x18]
movs r0, #2
lsls r0, r0, #0xc        /* 0x2000, in the scratch */
movs r1, #0              /* the result */
cmp  r2, r0
bls  .second
...
movs r1, #2
b    .end                /* every arm branches here */
...
.end:
adds r0, r1, #0
bx   lr
```

The obvious C for that is a chain of `&&` guards writing a local, and it is
right, but only in one of its two spellings:

```c
u16 v = p->unk18;                 /* input first:  DIFF, 64 bytes */
u32 r = 0;

u32 r = 0;                        /* result first: EXACT, 66 bytes */
u16 v = p->unk18;
```

With the input initialised first the compiler puts the result in `r0` and its
scratch in `r1`, and then each arm's `movs r0, #k` is already in the return
register, so there is nothing left for a shared tail to do and it duplicates
`bx lr` into all four arms instead of emitting the `b .end` / `adds r0, r1, #0`
pair. Twenty-eight bytes differ and the function is two bytes short, with the
*same* four comparisons, the same six branches and the same constants: the
control flow graph is identical and only the register numbering and the last
two instructions move.

Seven source shapes were compiled and ranked by diff count, and the split is
clean: every shape that initialises the result first is EXACT and every shape
that initialises the input first is 28 bytes wrong, whatever the types. `u32`
against `u16` for the input, `int` against `u32` for the result, nested ifs
instead of `else if`, and inlining the field read into all six comparisons all
change nothing else. One shape settles what the rule is about: declaring the
input first but *assigning* it after the result,

```c
u16 v;
u32 r = 0;
v = p->unk18;
```

is EXACT. So this is the order of the initialising assignments and not the
order of the declarations, which is the same distinction
`docs/idioms/assign-the-loop-counter-before-the-loop-bound-or-zero-costs-a-pool-word.md`
draws, and not
`docs/idioms/local-declaration-order-is-stack-order.md`, which is about stack
offsets and does not apply when nothing is spilled.

The reverse reading: a function whose arms all `b` to a single
`adds r0, rN, #0; bx lr` had its result variable introduced before the value it
tests, and one whose arms each end in their own `movs r0, #k; bx lr` had it
introduced after. The tail is two bytes, and finding it by reasoning about the
scheduler does not work; enumerate the orderings.
