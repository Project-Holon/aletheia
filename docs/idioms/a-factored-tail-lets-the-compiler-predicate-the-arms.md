# A tail factored out after an if/else lets the compiler predicate the arms, writing it into both arms forbids it

summary: the same statement after an if/else versus repeated inside both arms
is not only a cross-jumping question, it decides whether mwccarm if-converts
the arms at all; factored out, one-instruction arms become `addge`/`mlalt` and
the function loses four bytes per branch pair, so a real `cmp`/`b<cond>` in the
original means the arms were bigger than one statement in the source.

Found in: `src/matched/func_02040F84.c` (0x02040F84)

`docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md` records that
shared statements should be written into every arm and cross-jumped rather than
factored behind a label. This is the other half of the same lever, and it is
the half that changes the instruction count rather than the branch target.

0x02040F84 has four switch arms, three of which contain an if/else that assigns
a u16 index and then adds it to an accumulator. Written like this:

```c
case 0:
    if (w2 >= 0) { idx = x + y * 32; }
    else         { idx = x + y * w;  }
    base += idx;
    break;
```

each arm of the inner if/else is one instruction, and mwccarm if-converts the
whole thing:

```
cmp    ip, #0
addge  r0, r0, r1, lsl #5
mlalt  r0, r1, r2, r0
```

Writing the accumulate into both arms instead:

```c
case 0:
    if (w2 >= 0) { idx = x + y * 32; base += idx; }
    else         { idx = x + y * w;  base += idx; }
    break;
```

pushes each arm past the if-conversion threshold, so real branches come back
and the repeated tail is cross-jumped into one block, which is what the image
has:

```
cmp  lr, #0
blt  L1
add  r0, r0, r1, lsl #5
b    L2
L1: mla  r0, r1, r2, r0
L2: lsl  r0, r0, #0x10
    add  r0, ip, r0, lsr #16
```

Four bytes per if/else, twelve across this function, and the cross-jumped tail
also folds its `lsr #16` into the add's shifter operand, which the factored
form emits as a separate `lsr`.

The contrast inside one function is what makes the reading safe: case 1 of the
same switch has a genuinely one-statement if/else, and the original predicates
that one (`addge r2, ip, #0x400` / `lsllt r2, r3, #0x15`). So a function that
mixes predicated and branched two-arm conditionals is telling you, arm by arm,
which of them carried a second statement in the source.

Rule: when the original has a real conditional branch over a body that would
obviously if-convert, do not go looking for a different condition or a
different expression. Look for the statement after the if/else that belongs
inside both arms.
