# A case/default arm whose only body is a register copy is hoisted above the compare chain; a pool load is not

summary: when the image's compare chain has one shared `case 1: default:` block
that is a lone `mov r6, r1` (`copyDest = sendBuf`) followed by `b join`, 1.1p1
store-motions that copy to the top of the function (`mov r6, r1; cmp r0, #1;
beq join; cmp r0, #2; bne join; ...`) and drops the arm's `b`, costing four
bytes and recolouring every register below. The identical switch shape with a
pool load in the arm (`ldr r8, [pc, ...]`) keeps the block out of line. The
difference is that a parameter already in a register is trivially
rematerialisable at entry, so the arm is reduced to the entry value plus a
predicated override; a load cannot be hoisted and stays in its block.

Found in: `src/pending/ov_sdk/ov009_func_02166600.c` (0x02166600,
WCMi_MergeToBuffer, cpsif.o)

The image (ARM, 1.1p1 -O4,p, 128 B):

```
  cmp   r0, #1
  add   r4, r5, r4
  beq   #0x2166620          ; case 1 -> the shared block
  cmp   r0, #2
  beq   #0x2166628          ; case 2
  mov   r6, r1              ; case 1 / default, out of line
  b     #0x216664c          ;   -> join
  ...                        ; case 2 (sets r6 = r1 + 0xe and falls into join)
```

Every spelling (`switch { case 1: default: ... }`, separate identical arms,
`if`/`else if`/`else` with the store duplicated, `case 2` first, `default`
first, an `if (id == 1 || id != 2)` chain, a one-trip `for (;;)` wrapper, and
a cast on the stored value) compiles to the same 124 B with the copy hoisted.
Removing the default arm entirely (`case 1:` only, `copyDest` unset on the
unknown path) reproduces the register allocation and byte-swap exactly at
132 B; the sole residue is the extra `b join` the compiler inserts for the
default path, which restoring the default store then removes by hoisting.

This is the switch-side twin of
`both-arms-of-an-if-else-sharing-a-step-are-factored-into-one-unpredicated-instruction.md`:
the common step here is assigned by `case 1` and `default`, and the front end
factors it to the nearest dominator because it is a register copy of a live
parameter. Contrast `two-cases-with-one-body-are-written-as-case-then-default.md`,
where the shared arm holds a pool load and does stay out of line: when the
shared arm's value is a parameter register, a fallen-through `case: default:`
is not enough, and there is no control-flow spelling that keeps the copy in
the arm. Read the arm's instruction -- `mov r6, r1` versus `ldr r8, [pc, ...]`
-- before spending a wave on switch orderings; a lone register copy in a
fallen-through arm is this front-end canonicalisation, and the only way past
it is a different front end.
