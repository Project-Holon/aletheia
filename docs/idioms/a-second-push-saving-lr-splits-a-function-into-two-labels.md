# A function whose first instruction is a param-homing push is split by the next lr-saving push

summary: `disasm.py` auto-labels any instruction that saves `lr`, so when a
function opens with `push {r0, r1, r2, r3}` (it took the address of a register
parameter) and the *real* frame push immediately follows, that second push gets
a `func_` label and the outer function's listed extent collapses to the four
bytes before it. The short extent is a labelling artefact, not a real 4-byte
function; writing C for that extent is impossible.

Found in: asm/overlays/ov114.s (`func_021CA734`, 0x021CA734; overlay `ov114`)

`ov114`:

```
func_021CA734:
	push	{r0, r1, r2, r3}            /* 021CA734  0F 00 2D E9 */

	.org	0x11198
func_021CA738:
	push	{r3, r4, r5, r6, r7, r8, sb, lr} /* 021CA738  F8 43 2D E9 */
	add	r7, sp, #0x20
	...
	pop	{r3, r4, r5, r6, r7, r8, sb, lr}
	add	sp, sp, #0x10
	bx	lr
```

The `func_021CA734` label is real and load-bearing — `func_021CA8EC` calls it
with `bl func_021CA734` at 0x021CA984, and the callee homes the four register
parameters at `[sp]`/`[sp,#4]`/`[sp,#8]`/`[sp,#0xc]` for a varargs-style decode
loop. `func_021CA738` exists only because its push saves `lr`, so
`ovstats`/`match.py show` treat it as the next function and report
`func_021CA734` as `4 bytes, ARM`.

Tell: a listed function that is one or two instructions long and ends in a
`push` (not a return) with the next `func_` label at the byte right after is
the head of a larger function the labeller cut in two. Confirm by checking that
some `bl`/pool word in the overlay names the short label, then work the whole
range from the short label to the real epilogue; do not write a 4-byte source
file. This is the mirror image of
`unlabelled-leaf-functions-hide-in-word-runs.md`, where the labeller misses a
function instead of inventing one.
