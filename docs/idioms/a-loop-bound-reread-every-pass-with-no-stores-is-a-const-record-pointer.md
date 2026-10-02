# A loop bound reread every pass with no stores in the body is a const record pointer

summary: when a read-only scan loop (`for (i = 0; i < r->n; i++, p++) if (...) return 1;`)
reloads its u16 bound `ldrh rX, [r0, #n]` at the bottom of every pass, and the
record pointer stays in r0 with a small push (`push {r3, r4}`), while yours
hoists the bound into a callee-saved register (`push {r4, r5}`), declare the
record pointer and the element pointers `const`. The body has no stores, so
nothing else explains the reload; index forms and parameter reuse are inert.

Found in: src/matched/ov/ov021_func_0219CCF0.c (0x0219CCF0)

```
original                         non-const draft
ldrh r2, [r0, #4]   <- reload    adds r3, r3, #1
adds r3, r3, #1                  adds r4, #0xc
adds r4, #0xc                    cmp r3, r5        <- hoisted bound
cmp r3, r2
```

```c
const R *r = *(const R **)(s + 0x1c);
const A *a;
...
a = r->a;
for (i = 0; i < r->n0; i++, a++) {
    if (a->id != 0xFFFF) {
        return 1;
    }
}
```

Same family as `const-hoists-the-loop-test-load-above-the-body-stores.md` and
`a-const-record-pointer-moves-the-outgoing-stack-store-below-the-register-copies.md`:
`const` on a read-only pointer changes where mwcc places its loads. Wave A2
used it three more times in ov021: 0x0219EAD8 (`const Rect *s` loads the last
halfword before the previous store), 0x021A066C (`const W *w` keeps a
5-argument call's `str rN, [sp]` after the field load of argument 0).
