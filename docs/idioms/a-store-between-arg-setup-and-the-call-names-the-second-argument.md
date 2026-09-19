# A store scheduled between the argument setup and the `bl` names the call's second argument

summary: when a call result is both stored to a field and copied into `r1`
that is *not* the store's source register, the value is a second argument of
the next call: the store just got scheduled into the gap.

## The shape

```asm
    adds r0, r5, #0        ; r0 = a2
    bl   .getter           ; r0 = value
    adds r1, r0, #0        ; <-- the tell: a copy nothing stores from yet
    adds r0, r4, #0        ; r0 = first argument
    str  r1, [r7, #0x5c]   ; the field store, scheduled after the arg setup
    bl   .next             ; f(first_arg, value)
```

Read as "this is just a late store" it costs one instruction and two bytes:
the natural spelling

```c
p->f5c = getter(a2);
next(t);
```

compiles to `str r0, [r7, #0x5c]` straight after the call, then the argument
setup, and the function comes out 106 bytes against the original's 108.  With

```c
v = getter(a2);
p->f5c = v;
next(t, v);
```

the value is genuinely live across the argument setup, the compiler keeps it
in `r1` (the second argument register, free because `next` needs only `r0`
for `t`), and the store lands in the same gap the original has it in.

## How to spot it

- An `adds rN, r0, #0` (or `mov`) directly after a `bl`, whose destination is
  an argument register and which is *not* the source of the immediately
  following store, is an argument, not a temporary.
- The store that does use it can sit *after* the next call's argument setup;
  mwcc moved it there, so the "obvious" reading of the instruction order
  (store first, args second) is wrong by one statement.
- Widening the callee's prototype by one parameter is the whole fix; the
  caller's byte count then lands on the original exactly.

Found on `sub_020138C4` (0x020138C4, pkt_020138C4): `sub_02008314(t, v)`
versus `sub_02008314(t)` is 108 bytes versus 106, and the two extra bytes are
exactly the `adds r1, r0, #0`.
