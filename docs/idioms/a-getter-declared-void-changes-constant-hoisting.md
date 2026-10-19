# A getter declared void changes constant hoisting

summary: A callee that returns a value but is declared void makes mwcc hoist a repeated constant
into a free callee-saved register. Declare the real return type from a matched sibling.

Symptom: a whole function matches except that one repeated small constant (for example `movs r0,#5`
used twice in the last block) is hoisted into a free callee-saved register in ours, while the
original rematerialises it at each use.

Cause: a callee that really returns a value (a status `int` that the caller ignores) is declared
`void` in the draft. The declared return type changes how mwcc allocates around the call, and the
free register then takes the constant.

Fix: declare the callee with its real return type, taken from a matched sibling that calls it.
ov217 func_021B9920 closed (28 B to EXACT) when `func_02062B30` was declared `int` (as in the
matched sibling ov217 func_021B9A24) instead of `void`. Before this, the only form that closed it
was a pointer-integer-pointer cast round trip on the last handle, which is a stand-in.

Check first: grep src/matched for each callee's `extern` line and copy the return type.
