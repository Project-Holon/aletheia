# A lone `p = q` arm if-converts to `movne`, branch over the other arm

summary: In an ARM loop, a two-arm `if` whose entire body is one register move
is if-converted by armcc to a predicated `movne` followed by a conditional
branch over the other arm.  Writing the same move as an unconditional tail
statement instead puts the `mov` after the branch and shifts every following
byte by four.

Found in: src/matched/ov114_func_021BFA70.c (0x021BFA70)

The original walks a singly linked list and unlinks a node `x`:

```
        cmp   r2, r0            ; q == x ?
        movne r1, r2            ; p = q
        bne   body              ; not found -> advance
        ldr   r4, [r1, #0x1c]   ; found: n = p->next
        ...
body:   ldr   r2, [r2, #0x1c]   ; q = q->next
        cmp   r2, #0
        bne   top
```

The `movne` is the tell: `p = q` only ever executes on the not-found path, so
the compiler predicated it and made the branch skip the found arm.

The natural C shape puts the advance at the bottom of the loop:

```c
for (;;) {
    if (q == x) {
        Node *n = p->next;
        p->next = n->next;
        func_0205A1B0(6, n, 0);
        return;
    }
    p = q;
    q = q->next;
    if (q == 0)
        return;
}
```

That compiles to `bne body` first and an unconditional `mov r1, r2` at the
branch target, four bytes later than the original.  A `while`, a `do`/`while`,
a `break`, and a `goto` all give the same wrong shape.

The shape the original wants is to make the move its own arm, so it is the
only thing on that path and the compiler predicates it:

```c
for (;;) {
    if (q != x) {
        p = q;
    } else {
        Node *n = p->next;
        p->next = n->next;
        func_0205A1B0(6, n, 0);
        return;
    }
    q = q->next;
    if (q == 0)
        return;
}
```

Note the polarity: the condition is `q != x`, the move is the then-arm, and the
removal is the else-arm.  Flip it back to `q == x` and the bytes move again.
