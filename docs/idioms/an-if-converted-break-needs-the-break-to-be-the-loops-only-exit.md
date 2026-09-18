# An if-converted break needs the break to be the loop's only exit

summary: mwccarm folds a loop's `break` into the loop's continuation condition, producing the
predicated shape `cmp / beq EXIT / cmp / ldrne / cmpne / bne`, only when that break is the loop's ONLY
exit. Give the loop a second exit and the compiler emits the break as a real branch instead, which
costs one extra branch at the end whose target is the fall-through of the complementary `bne`. On the
function below that is the entire remaining difference, and 1.1p1 at `-O4,p` never performs the
redundant-exit-branch deletion that would close it.

Found in: `0x02060CD0` (packet `pkt_02060CD0`), still open at 352 of 352 bytes with 50 differing bytes,
`src/pending/func_02060CD0.c`, reading 7 of `docs/notes/pkt_02060CD0.c.txt`

The original loop test, `0x02060D10..0x02060D28`:

```
cmp  r6, #0
beq  0x02060D2C
cmp  r6, r0
ldrne r6, [r6, #0xc]
cmpne r6, #0
bne  0x02060D1C
```

The two C spellings that bracket it, compiled and byte-compared:

```c
/* 348 bytes: the original minus `cmpne r6, #0`. One exit, so the break folds into the
   continuation condition, but the folded-in test of the advanced node is missing. */
if (node != 0) { while (1) { if ((u32)node == end) break; node = node->next; } }

/* 356 bytes: the entire original loop byte for byte, PLUS one redundant `beq EXIT` whose
   target is the fall-through of the complementary `bne`. Two exits, so mwcc emits the
   break as a real branch and drops the predicate. */
while (node != 0) { if ((u32)node == end) break; node = node->next; if (node == 0) break; }
```

So the two halves of the shape are each reachable and never both: the predicated test needs one exit,
and reaching the original's instruction stream needs the compiler to delete a branch it does not
delete. The exhaustive sweep that establishes this: 4266 mechanically generated loop spellings, nine
wrappers by two outer guards by roughly 230 break, goto, continue, `||` and `&&` bodies, run in an
isolated micro-harness, produced zero occurrences of the original's predicated `cmpne` immediately
feeding its `bne`. A pragma matrix (peephole, ipa, opt_dead_code, opt_common_subs,
optimization_level 3 and 4, inline) came back byte-identical to no pragma at all, and volatile, a
pointer-cast bound, a union member and an inline helper changed nothing.

The lesson beyond this function: when the residue is a missing fold rather than a wrong instruction,
the search space is C spellings and the compiler owns the difference, so no amount of spelling reaches
it. Record the two bracketing spellings, the sweep size and the exact missing instruction, stop, and
treat the function as compiler-blocked rather than as unfinished work. Two independent attempts have
now spent about 4400 variants on this one region.
