# The register a scratch temporary lands in counts the arguments a forwarding call still holds

summary: when a function computes something into a scratch register and then
calls an extern that never sets r1, r2 or r3, the temporary's register number
is the argument count: it lands in the lowest scratch register the incoming
arguments do not already occupy, so r1 means one parameter, r2 two, r3 three,
and reading those untouched registers as "leftovers" leaves the arity one, two
or three short.

Found in: `src/matched/func_02041EE4.c` (0x02041EE4),
`src/pending/func_0204D324.c` (0x0204D324)

This is the mirror of
`docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md`.
That one says an untouched argument register usually is a leftover. This one
says when to conclude the opposite, and gives the test that separates the two
cases: not whether the register is written before the call, but which register
the function's own temporary was given.

`func_02041EE4` resets one slot of a global array and sets a bit for it:

```
02041EE4  push {r3, r4, r5, lr}
02041EE8  ldr  r4, [pc, #0x34]      /* &g_02146A44         */
02041EEC  mov  r5, r0               /* the index           */
02041EF0  ldr  r3, [r4]             /* the temporary: r3   */
02041EF4  mov  r0, #0x2c
02041EF8  add  r3, r3, #8
02041EFC  mla  r0, r5, r0, r3
02041F00  bl   #0x2042360
```

Nothing sets r1 or r2 before the `bl`, so the obvious reading is
`func_02042360(&g->slots[index])` with one argument and two leftovers. That
spelling is 64 of 68 bytes right, and the four wrong ones are the three
instructions above: the temporary comes out in r1, not r3.

Adding one parameter moves the temporary to r2 and leaves the same three
instructions wrong. Adding a second moves it to r3 and the function is EXACT:

```c
void func_02041EE4(u32 index)                /* temp -> r1: 4 bytes wrong */
void func_02041EE4(u32 index, u32 a)         /* temp -> r2: 4 bytes wrong */
void func_02041EE4(u32 index, u32 a, u32 b)  /* temp -> r3: EXACT         */
```

The allocator hands out scratch registers from r1 upward for values that do not
cross a call, and a live parameter holds its own register until the call
consumes it. So the first free scratch register is exactly `1 + (number of
parameters still live)`, and the temporary's number counts them for you.

`func_0204D324` is the two-instruction version of the same finding: a dispatch
through a table, `g_020A13B8[obj->kind](obj)`, where the kind index and the
table base take r2 and r1 in the one-parameter spelling and r3 and r2 in the
original. One extra forwarded parameter, and the six wrong bytes go away.

The rule to apply: when a function is byte for byte right except that its own
temporaries are all one, two or three registers higher than yours, do not look
for a scheduling or an aliasing reason. Count the gap from r1 and add that many
forwarded parameters to both the function and the callee it forwards to.
