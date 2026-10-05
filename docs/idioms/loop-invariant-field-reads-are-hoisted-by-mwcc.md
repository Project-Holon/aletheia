# Loop-invariant field reads are hoisted by mwcc

Seen in wave D6 lane 20 (2026-10-05): ov103 func_021B8F00 (closed EXACT*).

## Symptom

The prologue loads `pa->x`, `pa->y`, `pb->x`, `pb->y` once, before the loop, and spills
some of them. A draft that reads them into locals before the loop (`ax = pa->x; ...`)
gets the right instructions but a different prologue order, spill set and colouring.

## Source

Read the fields inside the loop: `dx1 = a[i].x - pa->x;`. The loop has no stores, so
mwcc hoists the loads itself, and the hoisted values get the image's order and slots.

## Two smaller facts from the same function

- `if (d1 > d2) d = d1 - d2; else d = d2 - d1;` with a u16 `d` keeps the explicit
  `cmp r0,#0` after the `lsls/lsrs` truncation. The ternary form drops it (flags from `lsrs`).
- Two values that swap registers inside one loop body were a tie: declaring
  `int dy1, dx1, dy2, dx2;` (image register order) and assigning x first closed it
  (rule 3 of two-long-lived-values-in-each-others-registers.md).
