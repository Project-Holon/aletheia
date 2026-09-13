# A compound assignment re-reads the field, the spelled out assignment reuses the cached load

summary: `x->f += 8` and `x->f = x->f + 8` are not the same code when a local
already holds `x->f`: the compound form emits a fresh `ldrb`, the spelled out
form folds into the register that has the value, and the difference is three
bytes in the middle of an otherwise byte for byte function.

Found in: `src/matched/unit_02007454.c` (0x020074D8)

`sub_020074D8` reads the box count into a local inside its loop and still has
it in r1 when the loop ends:

```
020074F8  ldr  r0, =0x3DD
020074FA  adds r4, r4, #1
020074FC  ldrb r1, [r5, r0]        /* n = h->unk3DD, kept in r1 */
...
0200750A  cmp  r1, #0x18           /* the cached copy, no reload */
0200750C  beq  .out
0200750E  ldr  r0, =0x3DD
02007510  ldrb r2, [r5, r0]        /* ... and now a reload */
02007512  adds r2, #8
02007514  strb r2, [r5, r0]
```

The `cmp` uses the register and the read-modify-write three instructions later
does not. Both spellings of the increment produce identical control flow, so
this looks like scheduling noise and is not:

```c
h->unk3DD += 8;              /* ldr pool; ldrb r2; adds r2, #8; strb  -- EXACT */
h->unk3DD = h->unk3DD + 8;   /* adds r2, r1, #0; adds r2, #8; strb    -- 4 bytes wrong */
h->unk3DD = (u8)(h->unk3DD + 8);   /* the same 4 bytes wrong */
h->unk3DD = n + 8;                 /* the same 4 bytes wrong */
```

So mwccarm treats the compound operator as a read of the lvalue in its own
right and does not let common subexpression elimination supply it from an
earlier load of the same field, while the explicit `x = x + k` form is an
ordinary expression and is folded. There is no aliasing reason for the
difference: nothing is called between the two reads and the pointer is the same
register.

The reverse reading is the useful one. A field that is loaded, compared against
a constant, and then loaded again to be incremented is not evidence of a
volatile object or of a call in between; it says the source used `+=` at the
second site and a named local at the first. A field incremented from a value
the function already has in hand says the opposite, that the source wrote the
assignment out.
