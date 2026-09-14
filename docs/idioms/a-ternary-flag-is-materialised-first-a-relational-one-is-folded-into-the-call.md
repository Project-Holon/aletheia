# A rounding flag written as a ternary is materialised first; the relational form is folded into the call

summary: `(x & m) ? 1 : 0` and `(x & m) != 0` are both `tst`/`movne`/`moveq`, but only the ternary is computed before the rest of the argument list, and the difference reschedules the whole call.

Found in: src/matched/sub_02043094.c (0x02043094), src/matched/sub_02042FF8.c (0x02042FF8)

The original rounds a byte length up to 32-byte units and passes it as the
third argument of a call whose first argument is a field of a global:

```
  tst   r2, #0x1f
  movne ip, #1
  moveq ip, #0
  ldr   r3, [pc, #0x54]      ; &g
  add   r2, ip, r2, lsr #5   ; third argument complete
  ldr   ip, [r3]             ; only now is the global dereferenced
  add   r0, ip, r0, lsl #2
  ldr   r3, [r0, #0x190]
  ldr   r0, [ip, #0x168]
  add   r1, r1, r3
  lsr   r1, r1, #5
  bl    #0x203422c
```

The obvious C is

```c
func(g->arena, (offset + g->base[idx]) >> 5, ((size & 0x1f) != 0) + (size >> 5));
```

and it is wrong, though every instruction it emits is one of the above. The
relational subexpression stays part of the argument tree, the scheduler is
free to hoist the pool load and the global dereference to the top of the
block, `ip` is then busy holding the global, and the flag is spilled into
`lr`:

```
  ldr   r3, [pc, #0x60]
  tst   r2, #0x1f
  ldr   ip, [r3]
  movne lr, #1
  add   r0, ip, r0, lsl #2
  ...
  add   r2, lr, r2, lsr #5   ; third argument completed last
```

Eight of the thirteen instructions in the block differ. Spelling the flag as
a ternary fixes it outright:

```c
u32 count = ((size & 0x1f) ? 1 : 0) + (size >> 5);
func(g->arena, (offset + g->base[idx]) >> 5, count);
```

The ternary is materialised as a value in its own right before the argument
list is evaluated, so the flag is dead by the time the global is loaded and
`ip` is free to be reused for it, exactly as in the original.

What does *not* work, and is worth not re-deriving: binding the relational
form to a named local changes nothing (the scheduler still hoists the load
past it), and neither does reordering the local declarations, hoisting them
to function scope, or splitting the second argument into its own local. The
distinction is the ternary itself, not the presence of a temporary. Compare
docs/idioms/an-inline-call-argument-is-scheduled-per-site-a-local-is-not.md,
which is the same scheduler seen from the other side: there a local pins the
order, here only a ternary does.
