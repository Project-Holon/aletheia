# A reload of a struct field right after a store to a sibling field cannot be forced

summary: when the original re-loads a struct member immediately after storing
to another member of the same struct, `-O4,p` forwards the stored value
instead, and no C spelling tried recovers the extra `ldr`; expect to be
exactly four bytes short and stop rather than grind.

Found in: docs/notes/func_02046110.c.txt (0x02046110), docs/notes/func_0206296C.c.txt (0x0206296C)

Two unrelated ARM functions in this wave show the identical shape. The
original computes a value from a struct field, stores it back, and then loads
the same field again:

```
ldr   r1, [r0, #4]      ; bank->array
add   r1, r1, r0
str   r1, [r0, #4]
ldr   r1, [r0, #8]      ; bank->nodeBase, strictly after, same scratch reg
add   r1, r1, r0
str   r1, [r0, #8]
ldrh  r1, [r0]
ldr   r4, [r0, #4]      ; <-- fresh load of the value just stored
```

and at 0x02046110 the same tell in a predicated arm:

```
ldr   r2, [r4]          ; msg->archive, feeding the offset table
...
ldreq r0, [r4]          ; <-- second load of msg->archive
addeq r0, r0, r5
```

`-O4,p` keeps the stored value live and emits `add r4, r3, r0` /
`addeq r0, r2, r5`, losing exactly one instruction. Everything tried to
defeat it failed, all of them otherwise byte-identical:

- plain member assignment, and the same written through `(u32)` casts;
- retyping the member as `u32` instead of a pointer, or the reverse;
- binding the value to an extra local before the store;
- an anonymous `union { T *a; u8 *b; }` at the member's offset, using one
  member for the store and the other for the reload (MWCC still CSEs the two
  union members' loads);
- a fully type-punned store, `*(u32 *)((u8 *)p + 4) = *(u32 *)((u8 *)p + 4) + x`;
- an inlined `static void unpack(u32 *p, void *base) { *p += (u32)base; }`
  taking the field's address, so the store escapes through a `u32 *`;
- writing the shared subexpression out once per branch and hoping for partial
  redundancy elimination, which instead loses the hoist entirely and costs
  eight bytes rather than saving four.

Two things are worth knowing when this shape turns up. First, it is purely a
reload: the concrete bytes on both sides of it are right, so it is a clean
four-byte `SIZE`-class miss, not evidence that the C is wrong. Second, the
register allocation *is* still steerable even though the reload is not: at
0x0206296C, swapping the declaration order of the loop counter and the array
local moved the counter into `lr` and the array into `r4`, matching the
original exactly, while the forwarded load stayed forwarded
(see `docs/idioms/declaration-order-decides-which-register-a-local-gets.md`).
So fix the allocation first; if the only remaining difference is the missing
`ldr`, that is this idiom and the function is done.

What would genuinely block the forwarding is a store the compiler cannot prove
disjoint, or a `volatile`/`const` qualification on the member. Neither fits
the surrounding code in either case, which suggests the original translation
unit reached these fields through something this tree has not reconstructed
yet (a header-level accessor macro over a differently-qualified type, most
likely) rather than that the C shape above is wrong.
