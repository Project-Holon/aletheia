# A loop-invariant load that is still reloaded inside the loop means the loop was never rotated, and only `goto` keeps it that way

summary: mwccarm rotates every structured loop (`while`, `do`/`while`,
`for(;;)` with breaks) into a peeled first test plus a single back edge, and
once a loop has one back edge it also hoists any invariant load out of the
body; an original that reloads the invariant every iteration therefore had two
exits and no rotation, which in C is a labelled block with explicit `goto`s.

Found in: `src/matched/func_0204BBC8.c` (0x0204BBC8), contrasted with
`src/matched/func_0204BB8C.c` (0x0204BB8C)

## The tell

The loop body contains no store and no call, yet the original reloads the same
field at the bottom of every iteration:

```
0204BC00  ldrb r1, [r2, #0xf]       ; cur->prio
0204BC04  cmp  r1, r3
0204BC08  bhi  #0x204bc1c           ; exit 1: found the slot
0204BC0C  ldr  r2, [r2, #0x10]      ; cur = cur->next
0204BC10  ldr  r1, [ip, #0x100]     ; <- the invariant, reloaded
0204BC14  cmp  r2, r1
0204BC18  bne  #0x204bc00           ; exit 2: wrapped to the head
```

Nothing between the two reads of `[ip, #0x100]` can write it, so a compiler
that had the chance would have hoisted it. It did not, because the loop has
two exits and was emitted exactly as written.

## What the structured spellings do instead

All three of `while (cur->prio <= bank->prio) { cur = cur->next; if (cur ==
g->head) break; }`, the `do`/`while` transcription of the same, and
`for (;;)` with two `break`s compile to the same twelve-byte-longer shape:

```
      ldrb ip, [r0, #0xf]        ; peeled: the first priority test
      ldrb r1, [r3, #0xf]
      cmp  r1, ip
      bhi  exit
      mov  r2, r3                ; g->head hoisted into r2, once
loop: ldr  r3, [r3, #0x10]
      cmp  r3, r2
      beq  exit
      ldrb r1, [r3, #0xf]
      cmp  r1, ip
      bls  loop
exit:
```

The peel is the rotation; the `mov r2, r3` is the hoist that the rotation
enabled. Neither is reachable from the source text, and no flag in the
documented matrix moves it (see
`a-materialised-shift-temporary-is-not-reachable-from-c-or-from-flags.md`).

## The fix

Write the loop out as labels and `goto`, one label per test, in the original's
own order:

```c
cur = g_02146A74->head;
loop:
    if (cur->prio > bank->prio) {
        goto found;
    }
    cur = cur->next;
    if (cur != g_02146A74->head) {
        goto loop;
    }
found:
```

That is byte-for-byte the image.

## When not to reach for it

A call in the loop body is already an optimisation barrier: it stops the hoist
on its own, and the rotation costs nothing visible because the reload was going
to happen anyway. `func_0204BB8C` walks the same ring with a call in the body
and reproduces exactly as a plain `do`/`while`. So the rule is narrow: reach
for `goto` only when the body is pure *and* the original still reloads
something.
