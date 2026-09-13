# A small constant is rematerialised off a register that already holds zero, unless an argument shares it first

summary: mwccarm spells a loop counter's initial 1 as `adds rD, rZ, #1` off the
register holding the loop index's zero, but only if nothing earlier in the
function already needed the literal 1; move the initialisation across a call
and the constant is common-subexpression-eliminated with an argument instead
and the instruction disappears.

Found in: `src/matched/unit_02006E40.c` (0x02006EA4),
`src/matched/unit_02007454.c` (0x02007464)

`sub_02006EA4` registers one debug record for the object and then three per
element, with a running record id. The original materialises the id's initial
value like this:

```
02006EA4  push {r3, r4, r5, r6, r7, lr}
02006EA8  movs r1, #1
02006EAA  str  r1, [sp]            /* the fifth argument of the first call */
...
02006EB4  movs r4, #0              /* the loop index */
02006EB6  blx  func_02048F74
...
02006EC8  adds r6, r4, #1          /* the record id, off the zero in r4 */
02006ECA  blx  func_02030734
```

Two instructions produce the value 1 and neither is shared with the other. That
is what says the id is a variable and not a constant folded into an expression,
and it is also a trap, because the obvious C deletes one of them:

```c
k = 1;                        /* movs r6, #1, hoisted to 02006EA8 and shared */
                              /*   with the str; 02006EC8 disappears and the */
                              /*   rest of the function shifts by two bytes  */
k = 0; f(obj, ..., k, 1); k++;  /* movs r1, #1 for the argument, adds r6, r4, #1 */
                              /*   for the id:  EXACT                        */
```

The increment also has to sit at the right place. Written after the two
allocations that follow it, the compiler has r7 free, hoists the file name pool
word into it and loads it once instead of twice, and puts the heap id in r6:
same instruction count, every general register shifted by one. Written between
the first call and the allocations, the value is live across them and the
register assignment is the original's.

`sub_02007464` is the same effect on a narrower point. It clears two locals to
zero before a loop and copies one of the zeroes into a third register to reset
the counter with (`adds r4, r1, #0`); which of the two the copy is taken from is
decided by which is assigned first, so the counter has to be cleared in the
`for` initialiser next to the index rather than in the statement above it.

The general rule: when a function is one instruction short in its prologue and
the missing instruction is an `adds rD, rZ, #imm` with a small immediate, look
for a literal of that value elsewhere in the function that the compiler has
common-subexpression-eliminated it with, and change the source so the two
values are not the same literal.
