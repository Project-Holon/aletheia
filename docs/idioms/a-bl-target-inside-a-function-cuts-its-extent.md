# A `bl` target inside a function gets its own `func_` label and cuts the extent

summary: disasm.py labels every call target `func_XXXXXXXX`, including a call
target that lies inside the function making the call. When a body uses a shared
tail reached by `bl` (not only `b`), that tail is labelled, `target_extent`
stops there, and `match.py show` reports the head as a fraction of its real
size. The tail has no prologue and reads the head's registers; the two labels
are one function.

Found in: asm/overlays/ov195.s (`func_022040E0` / `func_02204BB2`, 0x022040E0,
overlay `ov195`; asm/overlays/ov094.s holds unrelated code at the same
overlapping address)

`ov195`:

```
func_022040E0:                    /* 022040E0 */
	push	{r4, r5, r6, r7, lr}
	sub	sp, #0x24
	...
	bl	func_02204BB2     /* 02204102 -- the only `bl` to the tail */
	...

func_02204BB2:                    /* 02204BB2, no push, no lr save */
	adds	r0, r5, #0
	adds	r1, r4, #0
	bl	func_02204DE0
	...
	add	sp, #0x24        /* 02204C14 */
	pop	{r4, r5, r6, r7, pc}    /* 02204C16 */
```

`func_02204BB2` is the function's shared exit block: the head branches to it
with `b` on most paths (`b #0x2204bb2` throughout) and, on one path, calls it
with `bl` at 0x02204102. Because disasm.py emits a `func_` label for call
targets (its emission rule: "Call targets become `func_02xxxxxx`, other branch
targets …"), the `bl` mints a second label inside the head, and the head's
listed extent collapses to 0x022040E0..0x02204BB2. The real body runs to the
`pop` at 0x02204C16 (and only then does `push {r3,r4,r5,r6,r7,lr}` start the
next genuine function, func_02204C24).

Tell: a `func_` label whose first instruction is not a prologue (no
`push`/`stmdb sp!` that saves `lr`), that is entered both by `b` and by `bl`,
and that reads callee-saved registers the preceding label is known to set. It
is the mirror of
`a-second-push-saving-lr-splits-a-function-into-two-labels.md` (there the head
fails to save `lr` and the *next* push steals the label; here the head saves
`lr` but a `bl` to its own tail mints the label). Work the whole range from the
head to the tail's epilogue; do not write a file whose extent ends at the
minted label. If the follow-on match needs it, the true extent is the argument
to pass to `show --size`.
