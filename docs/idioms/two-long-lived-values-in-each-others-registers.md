# Two long-lived values in each other's callee-saved registers

summary: Two values live across calls that sit in each other's callee-saved registers are a
colouring-order difference. Missing call arguments, per-arm consumers and declaration order change
it.

Seen in wave D5 lane 01 (2026-10-05): ov217 func_021B96C8, ov096 func_02189548,
ov099 func_021BC14C, ov210 func_021BCF0C (all closed EXACT); ov055 func_021F3DD4 (still open).

## Symptom

Everything matches except two values that live across calls (or across a loop).
Each one sits in the register of the other: for example the image has `p` in r4
and `q` in r5, and the build has `p` in r5 and `q` in r4. Size, branches and
instruction order are the same.

## What decides it

mwcc 1.1p1 gives each value the lowest free register in a fixed colouring order.
The residue says that this order differs between the image and the build. The
order is not the order of first use, not the use count, and not the parameter
order. These source facts change it:

1. **A missing call argument.** If the callee reads r0/r1 from the caller, the
   values that the caller leaves there interfere with those registers at the
   call, and that changes the order. Read the first instructions of every callee.
   ov217 021B96C8: `func_021B970C()` is really `func_021B970C(a, p)`; the
   `p`/`c` swap went away with no other change.
2. **A value local that merges at a join.** A local that is set in each arm of an
   if/else (or a ternary) and used once after the join adds a node that changes the
   order of the long-lived values. Write the consumer in each arm instead.
   Tail merging builds the same single join block in the image.
   - ov096 02189548: `if (...) v = 0; else v = f(q); p[0x38] = v;` became
     `if (...) p[0x38] = 0; else p[0x38] = f(q);`.
   - ov099 021BC14C: `r = 0x42; / r = 0x49;` then `off -= 0x76; p[off] = r;` after
     the join became `off -= 0x76; *(int *)(p + off) = 0x42;` (and `0x49`) in each arm.
     The image still has one shared `subs r5,#0x76; str r0,[r4,r5]`.
3. **Declaration order, for a tie.** When the values have the same live span
   (for example three values live through one leaf loop), the local that you
   declare first gets the lowest register. Declare them at the top, without
   initialisers, in the order of their image registers.
   ov210 021BCF0C: `u32 i; u8 v; u8 *rec;` gives i r2, v r3, rec r4, as in the image.
   Order v, i, rec gives v r2, i r3, rec r4 (the rule predicts this).

Declaration order is not general. In ov055 021F3DD4 (six locals across calls)
no declaration order moves any register.

## Model tests (scratch, Thumb, ov096 slot)

`q = G(p, F(x));` then uses of `q`, then `p[0x38] = ...; return p[0xC4];`:

| body after the call | p | q |
|---|---|---|
| `if (H(q) != 1) H(q); p[0x38] = 0;` | r4 | r5 |
| `if (H(q) == 1) v = 0; else v = H(q); p[0x38] = v;` | r5 | r4 |
| `p[0x38] = (H(q) != 1) ? 0 : H(q);` | r5 | r4 |
| `if (H(q) != 1) p[0x38] = 0; else p[0x38] = H(q);` | r4 | r5 |
| `w = 7; p[0x38] = w;` (a constant local, propagated) | r4 | r5 |

Other effects that the tests show (ov055 slot):
- More callee-saved locals (two extra results of calls held across later calls)
  move a parameter from r4 to r5 when the rest is the same.
- One more use of the parameter after the last use of the other value can move
  the parameter to the lower register.

## Steps

1. Check every callee for arguments that the caller leaves in r0..r3.
2. Look for a value local or ternary that merges at a join and is used once:
   write its consumer in each arm.
3. For values with the same live span, set the declaration order from the image.
4. If none of these moves it, record the residue. Do not try all orders.
