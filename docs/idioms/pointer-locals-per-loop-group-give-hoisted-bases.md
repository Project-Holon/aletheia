# Pointer locals per loop group give hoisted bases and early derived offsets

summary: Pointer locals assigned together before a loop, one set per group, give a hoisted `p + K`
base and early derived offsets for the stores after the loop.

Seen in wave D7 lane 20 (2026-10-05): ov209 func_021BD9B4 (closed EXACT from 307 bytes).

## Symptom

- A loop stores to `p + K + i*4`. The image computes `p + K` once before the loop
  (often spilled, `str r0,[sp,#N]`) and stores with `str r0,[base, i*4]`.
  The build computes `p + i*4` first and adds the offset `K` inside the loop.
- Offsets for stores AFTER the loop (`p->b[0]`, `p->c[0]`) are derived from a live constant
  BEFORE the loop (`ldr r0,[sp,#8]; adds r0,#4; str r0,[sp,#0xc]`) and spilled until use.

## Source

Pointer locals, assigned together before the loop, one set per group:

```c
arr = p->a;  pb = &p->b[0];  pc = &p->c[0];
for (i = 0; i < 0x10; i++)
    arr[i] = f(...);
*pb = g(...);
*pc = h(...);
```

`pb` and `pc` have one use each, so mwcc propagates them, but it keeps the offset
constant at the assignment point. That gives the early derived offsets.

## Constants in callee-saved registers

In the same function the image kept 0 in r6 (copied to r4 for loop arguments) and 0x6b in r7
for stack arguments. Earlier drafts modelled these with `z = i = 0;` and a zero local `z`.
The real source had literal zeros (`f(0, 0, 0, 0)`, `for (i = 0; ...)`): mwcc kept the constants
in registers itself once the pointer locals were in place. A residue of `movs r6,#0` one slot
too early was the sign that the zero local was a stand-in.
