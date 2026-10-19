# A stack parameter spilled to its home slot follows logic fixes elsewhere

summary: A stack parameter that is stored back to its home slot depends on register weights, which
logic errors elsewhere change. Fix the other listing-backed differences first.

Seen in wave D9r lane 66 (2026-10-05): ov208 func_021C4298 (closed EXACT, 1288 bytes,
after six waves at DIFF with "ev in r7").

## Symptom

The image loads a stack parameter at entry and stores it back to the same slot
(`ldr r1,[r0,#4] ... str r1,[r0,#4]`), then reloads it before every use
(`ldr rX,=K; add rX,sp; ldr rX,[rX,#4]`). The build keeps the parameter in a
callee-saved register and spills other values instead (more spill slots, a
larger frame). Local changes to the parameter (types, volatile, struct by value,
declaration order) do not move it.

## What decides it

The parameter sits just above the spill threshold. Its weight against the other
values that want the same register decides it. Small logic errors in OTHER parts
of the function change those weights. In 021C4298, three listing-backed fixes in
two switch cases moved the parameter to its home slot:

1. A `%` on two u16 fields is a signed division (`_s32_div_f`). The image called
   `_u32_div_f` four times, so each divisor is u32 (`n = H(k); x % n`, or
   `x % (u32)H(k)`).
2. A field re-read after a compare: the image reloads `H(k + 8)` after
   `if (H(k + 6) == H(k + 8))`. `H(k + 8) = H(k + 8) + 1` reuses the compare load;
   `H(k + 8)++` and `H(k + 8) += d` reload it.
3. Operand order `ldrh H; subs n-1; adds H, n-1`: `H(k + 8) += (u16)(n - 1)`,
   not `H(k + 8) = H(k + 8) + (u16)(n - 1)` (that computes `n - 1` first).

After that, the remaining residues were frame order (declaration order of the
arrays and of the spilled scalars) and the case order of the last switch.

## Rule

Before calling a "parameter in a register" residue an allocator wall, compare
every block of the function with the listing, including blocks that already look
right apart from registers: a call to the wrong division helper, a missing
reload, or an operand-order difference in one case can be the cause.
