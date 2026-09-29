# A store into a stack local that the next statement overwrites is still emitted, and which value the second statement is computed from decides whether there are two stores or one

summary: `d = a; d = a + k;` over a spilled local emits both stores with the
add in between and no reload, `d = a; d = d + k;` emits a reload, and
`d = a + k;` emits one store; so a `str` immediately followed by an `adds` and
a second `str` to the same slot is not an aggregate, not a `volatile` and not a
missed optimisation, it is two ordinary statements whose second one recomputes
from the source value rather than from the variable.

Found in: the 0x020182A8 near miss recorded in the header of
`src/pending/unit_02018238.c`

The original opens by building three dispatcher ids out of one slot number, and
each of the three looks like this:

```
020182B0  ldr  r1, [sp]            /* the slot number */
020182B4  str  r1, [sp, #0xc]      /* ... stored, and immediately dead */
020182B6  adds r1, #0x36
020182BC  str  r1, [sp, #0xc]      /* ... and stored again */
```

Two stores to one slot with nothing in between that could read the first, three
times over. The obvious reading is that the slot may not be optimised away, and
that sends the search after a `volatile`, an aggregate whose address has
escaped, or a union: something that would make the first store observable.
None of them is there. Measured on this function, holding everything else
fixed:

```
d = slot;  d = slot + 0x36;    ->  str; adds; str          128 bytes, and right
d = slot;  d = d + 0x36;       ->  str; ldr; adds; str     the reload is wrong
d = slot + 0x36;               ->  adds; str               122 bytes, six short
volatile u32 d;                ->  a reload before every use, 134 bytes
u32 ids[4] / struct / union    ->  folded exactly like the scalar
a by-value struct parameter    ->  132 bytes, every use reads the home slot
```

Two separate behaviours are in play and both are worth having.

**mwccarm does not dead-store-eliminate a write to a local that has a stack
home.** Once the allocator has given `d` a frame slot, every assignment to `d`
in the source is a `str`, whether or not anything can read it. A local that
stays in a register loses the same store, which is why this only ever shows up
in functions under enough pressure to spill.

**The second statement's right-hand side decides whether there is a reload.**
`d = d + 0x36` is a read of `d`, and a read of a spilled local is a `ldr` even
when the value was stored one instruction earlier: the same refusal to forward
that `docs/idioms/compound-assignment-rereads-the-field-plain-assignment-reuses-the-cached-load.md`
records for a struct field. `d = slot + 0x36` reads `slot`, whose value is
already in a register from the previous statement, so the add runs off that
register and no `ldr` appears.

The reverse reading is mechanical, and it is what the file is for: **two stores
to one stack slot with an `adds` between them and no load are two assignments
to one ordinary local**, and the second one was written against the original
value. Reading them as evidence of an aggregate or of a qualifier invents a
declaration that is not there, and the three source shapes above are cheap to
measure before doing that.

## Two constants into the same local

Found in: src/matched/ov/ov094_func_02205E30.c (0x02205E30),
src/matched/ov/ov094_func_02205E80.c (0x02205E80)

Both functions spill a handful of dead offset locals (0x11c then 0x14c, 0x240 then 0x17c, and
0x110 then 0x180 three times over) that a loop then adds to a base pointer. mwcc materialises the
second constant from the register still holding the first, which is why the second store looks like an
`adds`/`subs` of a small delta.

What each spelling gave (ov094_func_02205E80):

- `x = A; x = (Off)(x + d)` with an enum type: the double store appears, but three locals that end
  with the same value (0x180) are merged into one slot and the frame is 8 bytes short.
- a local struct of enum members: every field is stored twice through memory, the frame is 16 bytes over.
- `int` locals, `x = 0x110; x = 0x180;` (both literals), one local per slot: EXACT, including the three
  separate 0x180 slots and the descending slot order. In 02205E30 the same shape needs the counter
  initialised before the offset (`i = 0; off = 0x11c; off = 0x14c; for (; i < 2; i++)`) so the stores
  follow `str i`.
