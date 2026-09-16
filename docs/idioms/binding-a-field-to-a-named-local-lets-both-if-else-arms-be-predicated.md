# Binding a field to a named local is what lets both if/else arms be predicated

summary: an if/else whose arms both read the same field compiles to one
predicated arm plus a branch while the field is re-read inline, and to two
predicated arms with no branch at all once the field is read once into a local.

Found in: `src/matched/func_02058300.c` (0x02058300)

The unlink routine ends with a two-arm choice in which both arms need
`node->next`, and the original predicates both, with no branch between them:

```
ldr   r2, [r0]
cmp   r2, r1
streq r3, [r0]          /* list->head = next  -- r3 still holds next      */
ldreq r2, [r0]
moveq r3, #0            /* and only now is r3 clobbered                   */
streq r3, [r2, #4]
ldrne r2, [r1, #4]
strne r2, [r3, #4]      /* the ne arm reads r3 as next, unclobbered here  */
ldrne r3, [r1]
ldrne r2, [r1, #4]
strne r3, [r2]
```

Written with the field read inline in both arms:

```c
if (list->head == node) {
    list->head = node->next;
    list->head->prev = 0;
} else {
    node->next->prev = node->prev;
    node->prev->next = node->next;
}
```

`-O4,p` predicates exactly one arm and branches around the other, and the
predicated arm reloads `node->next` into a scratch register rather than using
the value already live from the entry compare. Swapping the polarity moves
which arm gets predicated but never produces two. Writing the pair as two
separate `if`s on a cached local gets both arms predicated but duplicates the
`cmp` and turns the else arm into an `ldm`.

The whole difference is one declaration:

```c
struct Node *next;

next = node->next;
if (next == 0) { ... } else {
    if (list->head == node) {
        list->head = next;
        list->head->prev = 0;
    } else {
        next->prev = node->prev;
        node->prev->next = node->next;
    }
}
```

Naming the value pins it in a register across the whole if/else, and the
compiler then sees both arms as cheap enough to predicate, including the
conditional clobber of that register in the first arm. Note the asymmetry in
the second arm: the first use spells the local and the second spells
`node->next` again, because the intervening store may alias it and the original
does reload there (`ldrne r3, [r1]`). Both spellings are load-bearing.

This is the opposite of what the neighbouring push-front at 0x020583CC needs,
where the original predicates *neither* arm; do not apply it blind to every
two-armed list routine.
