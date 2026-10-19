# A stack parameter copy in the lowest slot is coalesced

summary: A local that sits in the lowest spill slot despite its declaration is a plain copy that
coalesces with its source. Give it the callee's type and use it at the second use.

Seen in ov198 func_0220BEB8 (wave D9r, 2026-10-05).

## Symptom
All spill slots follow declaration order except one or two values that sit at the lowest
slots, right above the spilled register parameters. Moving their declarations does not move
them. Here: `ex = extra;` (a copy of a u8 stack parameter) and `rec = base + off;`.

## Cause
The value is not a separate variable after optimisation:
- `u8 ex = extra;` is a plain copy of the parameter, so it coalesces with the parameter's
  vreg and gets the parameter's slot.
- `rec = base + off;` with a later `*(void **)(base + off)` is CSE'd into a compiler temp,
  and rec takes the temp's identity.

## Fix
- Give the copy the type the callee parameter has (here `s16 ex;`, the 0201C724 parameter
  type). The u8 to s16 assignment is a real conversion, so the local keeps its own vreg and
  its declared slot. Assign it where the image loads it (here in each head arm).
- Use the variable at the second use: `*(void **)rec` instead of `*(void **)(base + off)`.
  mwcc still folds the address into `ldr [base, off]`, but rec stays a declared variable.

Also check the parameter types against matched callers: a2 as u16 (the caller passes
`(u16)i`) put the entry parameter spill stores back in parameter order.
