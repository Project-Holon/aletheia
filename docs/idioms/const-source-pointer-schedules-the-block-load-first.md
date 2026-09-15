# A `const` source pointer schedules a struct assignment's block load before the destination address

summary: in `dst->field = *src`, a `const`-qualified `src` emits the `ldm` of
the source before the `add` that forms the destination address, and a plain
pointer emits them the other way round; the two instructions are otherwise
independent, so this qualifier is the only thing that picks the order.

Found in: src/matched/sub_0204B728.c (0x0204B728)

The original ends with a twenty-byte struct assignment, inlined as the usual
writeback `ldm`/`stm` pair plus a trailing word:

```
  bl  #0x206380c
  ldm r4!, {r0, r1, r2, r3}     ; source block load
  add ip, r5, #0x40             ; destination address
  stm ip!, {r0, r1, r2, r3}
  ldr r0, [r4]
  str r0, [ip]
```

The obvious C,

```c
void f(struct Obj *o, struct Xform *m) { ... o->unk_40 = *m; }
```

compiles to the same sixty bytes with those two middle instructions swapped:
`add ip, r5, #0x40` first, then the `ldm`. Nothing else differs. Neither
instruction depends on the other, so no rewriting of the assignment moves them:
naming the destination in a local, naming the source in a temporary, casting the
destination through `(struct Xform *)((u8 *)o + 0x40)`, spelling the struct as
five named fields, `*m++`, or an `inline` helper taking `(src, dst)` all produce
the destination-first order (a non-`inline` `static` helper is not inlined at all
at `-O4,p` and becomes a real `bl`).

What flips it is qualifying the source:

```c
void f(struct Obj *o, const struct Xform *m) { ... o->unk_40 = *m; }
```

With `const` the front end can treat the source block as loadable ahead of
anything that might alias the destination, and it emits the load first. Casting
`const` away at an intervening call site does not undo it; the qualifier on the
pointer whose target is being read is what counts.

The practical rule: when a struct assignment is byte-correct except that the
source load and the destination address computation are transposed, do not look
for a different spelling of the copy. Look at whether the source pointer was
declared `const` in the original, which is usually decidable by reading the
callee that the same pointer is passed to (here 0x0206380C only reads it).
