# Reassigning a parameter to the callee result keeps it in the same register

summary: When a function replaces a parameter with a later call's result (a
builder that returns its own object), write `a = f(a, ...)` rather than a new
local. mwccarm then treats the parameter and the result as one value, keeps it
in the one callee-saved register it already chose, and the register colouring
matches the original. A distinct result local instead shifts the whole
allocation and spills values the original kept live.

Found in: src/matched/ov100_func_021BB414.c (0x021BB414)

The original keeps `a` in r4 from entry, then overwrites the same r4 with the
return of the builder call and uses that as the base for every following field
store and the next call:

```
adds r4, r0, #0        ; a
...
blx  #0x0203159C       ; a = build(a, 0xcf0, 0x1f)
adds r4, r0, #0        ; same r4, not a fresh register
str  r6, [r4, r1]      ; a->f0 = c
...
```

The C that reproduces this is a single reassigned parameter:

```c
a = func_0203159C(a, r5, 0x1f);
func_02082BCC(a, 0, r5);
*(int *)(a + 0x244) = c;
```

Keeping the result in its own local instead:

```c
int r4 = func_0203159C(a, r5, 0x1f);   /* r4 collides with the base */
func_02082BCC(r4, 0, r5);
```

made mwccarm colour `a` into r6 and `c` into r7 (instead of a=r4, c=r6) and
rematerialise a `0x1f` the original had hoisted into r7, so the 132-byte
function came out with the two parameters swapped in every instruction, a
`DIFF` whose byte count also drifted.

The same tell appeared at 0x02188D5C, 0x021B6B8C and 0x021B8934, where keeping
a parameter and a later value as separate locals made the allocator spill the
value the original held in a register and grow the frame (0x10 -> 0x18). It is
worth a first attempt on any builder-style overlay function where the first
parameter is reused after a call.
