# A two-word struct copy from a returned record recolours the destination pointer

summary: when a function copies two adjacent words from a returned record into
a destination struct (`ldr [r0]; ldr [r0, #4]; str [d, #8]; str [d, #4]`) and
then uses the same values as locals, writing it as two field assignments from
locals leaves the codegen identical except for a rotated callee-saved
assignment (the destination pointer coloured last, r7). Writing it as one
struct assignment `d->src = *s;` and reading the locals back from `d->src`
(the copy's loads are reused, no reload is emitted) gives the original
colouring (destination pointer r5, loop counter r6, scaled index r7).

Found in: `src/matched/ov/ov021_func_021D029C.c` (0x021D029C), sibling shape
of ov021 0x021C95D8.

```c
s = func_021AC1AC(p);
d->src = *s;            /* not: tbl = s->tbl; cnt = s->cnt; d->cnt = cnt; d->tbl = tbl; */
tbl = d->src.tbl;
cnt = d->src.cnt;
```

Signal: the store order is reversed (+8 before +4) and the whole residue is
one register rotation that no declaration order, counter type or local copy
of the pointer moves. Inert spellings measured first: local copy of the
pointer at every declaration position, `register`, enum/unsigned counters,
shared or per-loop counters, inline helpers for either loop.
