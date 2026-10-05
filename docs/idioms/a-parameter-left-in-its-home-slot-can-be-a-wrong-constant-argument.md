# A parameter left in its home slot can come from a wrong constant argument elsewhere

summary: when the image keeps a parameter in memory (one `ldr; str` back to its
home slot at entry, then a reload at every use) and the draft keeps it in a
callee-saved register, look for a constant the image holds in that register
first. A constant argument written as a variable in the draft frees the register
and changes which value the allocator spills.

Found in: src/pending/ov/ov208_func_021BEB18.c (0x021BEB18), wave D5.

## The shape

```asm
    ldr  r0, [sp, #0x88]    ; ctx, the fifth parameter
    str  r0, [sp, #0x88]    ; stored back: ctx is spilled for the whole body
    ...
    movs r5, #0             ; a zero, set before an unrelated call
    ...
    adds r7, r5, #0         ; r7 = 0 before the loop (not a copy of i)
loop:
    cmp  r5, #1
    ...
    adds r0, r5, #0
    adds r1, r7, #0
    adds r2, r7, #0
    blx  func_02040618      ; f(i, 0, 0)
```

The draft called `func_02040618(i, i, i)` and `func_02040618(i, 3, i)`. The
loop back edge goes to `cmp r5, #1`, after the `adds r7, r5, #0`, so r7 is the
loop's start value 0, not i. Other callers of `func_02040618` pass
`(i, 0, 0)` and `(i, 3, 0)`. With the right arguments the compiler keeps the
zero in r7 and spills ctx exactly as the image does. Two more argument and
layout fixes (a `(2, 0, 1)` argument triple, local declaration order) then gave
a MATCH that only waits for three unlabelled callees.

## How to use it

- Before you treat a home-slot parameter as an allocator wall, check every
  `adds rX, rY, #0` copy: find where the loop back edge lands. A copy above
  the target runs once and is a constant.
- Grep `src/matched` for other callers of each callee and compare constant
  arguments.
