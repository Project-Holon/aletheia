# A re-read of a field the previous statement stored is one volatile read, not a volatile field

summary: when the original loads a word it has just stored, the compiler proves
the load redundant and degrades it to `mov rN, rN`; the spelling that restores
it is a single `*(volatile u32 *)&p->f` read into a local, because qualifying
the field or the pointer `volatile` also un-predicates every read-modify-write
around it.

Found in: `src/matched/func_02067B78.c` (0x02067B78)

The NNS G2D flip setter writes bit 0 of `p->flip` from one BOOL, then reads the
same word back before writing bit 1 from a second BOOL:

```
02067B78  cmp   r1, #0
02067B7C  ldr   r1, [r0, #0x24]
02067B80  orrne r1, r1, #1
02067B84  biceq r1, r1, #1
02067B88  str   r1, [r0, #0x24]
02067B8C  ldr   r1, [r0, #0x24]     <- the re-read
02067B90  cmp   r2, #0
02067B94  orrne r1, r1, #2
02067B98  biceq r1, r1, #2
02067B9C  str   r1, [r0, #0x24]
02067BA0  bx    lr
```

The obvious C loses that one instruction:

```c
if (h) p->flip |= 1; else p->flip &= ~1u;
if (v) p->flip |= 2; else p->flip &= ~2u;   /* mov r1, r1 in the ldr's slot */
```

and every way of defeating the store-to-load forwarding by re-deriving the
address fails the same way, because the address is what the compiler compares,
not the expression that produced it: a `u32 *` cast off a `u8 *` base, a
subscript `((u32 *)p)[9]`, and a named local copy of the field all still give
`mov r1, r1`.

`volatile` does restore the load, but only the narrow form is free. Qualifying
the member or the parameter makes both halves volatile, so each arm of the
first `if` becomes its own load-modify-store instead of the predicated
`orrne`/`biceq` pair and the function grows from 44 to 60 bytes. Reading only
the re-read through a volatile lvalue leaves the first half a plain
read-modify-write:

```c
if (h) p->flip |= 1; else p->flip &= ~1u;
w = *(volatile u32 *)&p->flip;              /* the ldr, and nothing else */
if (v) w |= 2; else w &= ~2u;
p->flip = w;
```

The general shape: `volatile` is a property of the access here, not of the
object. Apply it at the one load the original performs and leave every other
access to the same field plain.
