# A conditional expression predicates a load that the equivalent `if` statement will not

summary: `ldrne`/`ldreq` in a loop body comes from `p = cond ? p->next : p;`,
a conditional *expression*; the same guard written as `if (cond) p = p->next;`
is never if-converted at -O4,p and costs a separate compare and branch.

Found in: docs/notes/sub_02060CD0.c.txt (0x02060CD0)

This front end if-converts freely at -O4,p, including loads and stores: a
guarded block that ends the function comes out as `movne`/`strne`/`popne`
(src/matched/func_0204E074.c), and a guard chain fuses into
`cmp` / `cmpne` / `beq`. Two of those happen from ordinary `if` statements.
A load inside a loop does not.

The free-list walk at 0x02060D1C is

```
loop:
  cmp   r6, r0
  ldrne r6, [r6, #0xc]
  cmpne r6, #0
  bne   loop
```

Every `if`-shaped spelling of that walk, and there are a dozen of them in
the note above (top-tested `while`, guarded `do`/`while`, `while (1)` with
two `break`s, an explicit `goto` loop, the conjunction with the assignment
inside it), produces the same unpredicated five instructions:

```
loop:
  cmp  r6, r0
  beq  out
  ldr  r6, [r6, #0xc]
  cmp  r6, #0
  bne  loop
```

Rewriting the update as a conditional expression is what predicates it:

```c
do {
    p = (p != end) ? p->next : p;
} while (p != 0 && p != end);
```

```
loop:
  cmp   r8, r0
  ldrne r8, [r8, #0xc]      <- predicated
  cmp   r8, #0
  beq   out
  cmp   r8, r0
  bne   loop
```

So the rule is about the syntactic form of the assignment, not about whether
the operation is a memory reference. If a loop body is one assignment under a
guard and the original shows a predicated load or store there, reach for the
ternary before concluding the compiler refuses to predicate memory.

The converse is the trap, and it is why this did not close 0x02060CD0: the
ternary leaves the variable unchanged on the false arm, so the guard's
condition is no longer recoverable from the new value and the loop's own test
has to re-evaluate both operands. A guarded *block* can let the backedge reuse
the guard's flags (`cmpne` above); an expression cannot. Where the original
reuses those flags, the ternary buys the predicated load and immediately loses
two instructions elsewhere.
