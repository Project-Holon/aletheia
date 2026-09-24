# A constant compared from a register is a variable assigned in another switch arm

summary: when the image does `mov rX, #imm; cmp rY, rX` for an immediate that
fits the `cmp`, the source compares against a variable whose only
assignment sits in another arm of the same state machine. The front end
cannot fold it, so the back end rematerialises the constant at each use.
A literal, an enum, a `static const` or an initialised local all fold to
`cmp rY, #imm`.

Found in: docs/notes/pkt_02094B8C.c.txt (0x02094B8C, MSL __strtold, 1.1p1, ARM; still DIFF on an unrelated rotation)

The hex digit arms of __strtold test the digit count against 14:

```
ldr  r2, [sp, #8]     <- intdigits
mov  r0, #0xe
cmp  r2, r0
bhs  ...
mov  r0, r2           <- the copy that follows from r0 being taken
add  r0, r0, #1
str  r0, [sp, #8]
```

`if (intdigits < 14)` gives `ldr r0; cmp r0, #0xe; add r0, r0, #1` (one
word shorter per arm). An enum, a `static const`, `sizeof`, reversed
operands, casts and `unsigned max = 14;` (a local initialised at its
declaration) all fold the same way. This spelling is right:

```c
unsigned maxdigits;             /* function scope, no initialiser */
...
case hex_start:
    ...
    intdigits = 0;
    maxdigits = 14;
    ...
case hex_int_digit_loop:
    ...
    if (intdigits < maxdigits)
```

The value comes back as `mov #0xe` at each use, not from a stack slot, and
the frame does not change. The extra web also changed the colouring of an
unrelated zero-copy chain at function entry and closed a one-copy residue
there. A member of a local struct initialised to 14 gives the same `cmp r2,
r0` / `mov r0, r2` shape, but it takes a stack slot (+16 bytes).
