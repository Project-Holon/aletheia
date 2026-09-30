# A hoisted array base must be a named local written inside a guard before a do/while

summary: when a scan loop recomputes `p = base + i` and the image keeps `base`
in a callee-saved register while the counter sits in `lr` and a third value in
`ip`, the base is a **named** local (a compiler temporary goes to `ip`), and the
`add` that materialises it lands **after** the loop-entry rotation guard only
when the base is assigned inside an explicit `if (i < n) { base = ...; do { }
while (i < n); }` gate.  A plain `for` with the base assigned in front of it
hoists the `add` above the guard and swaps the two lower registers.

Found in: src/matched/ov_sdk/ov009_func_02165DCC.c (0x02165DCC, WcmAllocApList,
aplist.o of libwcm.TWL.HYB.a, dsi/1.1p1, ARM)

The target loop over the ap-list box (208-byte elements behind a 12-byte
header) compiles like this:

```
mov  lr, r0          ; i = 0
cmp  ip, #0          ; maxBlock
bls  out
add  r4, r1, #0xc    ; base = pHeader + 1
mov  r2, #0xd0
loop:
mul  r0, lr, r2
ldrb r3, [r4, r0]
add  r0, r4, r0      ; p = base + i
cmp  r3, #0
beq  out
add  lr, lr, #1
cmp  lr, ip
blo  loop
out:
cmp  lr, ip          ; second read of i, the i < n test again
pophs ...
```

Two things are unusual and both come from the spelling.

1. **The base is a named local.**  With the base as an inline expression
   (`p = (struct WCMApList *)(pHeader + 1) + i`) the register allocator colours
   `i`→`lr`, `maxBlock`→`r4`, and the temporary→`ip`.  Declaring
   `struct WCMApList *pList;` and writing `p = pList + i` flips the preference
   list to `[ip, lr, r4]` over the named locals **in declaration order**, so
   the order `unsigned long maxBlock; long i; struct WCMApList *pList;` yields
   exactly `maxBlock`→`ip`, `i`→`lr`, `pList`→`r4`.  This also explains the
   DWARF local list, which shows five variables (`i` in `r14`, `maxBlock` in
   `r12`, `p`/`w` in `r0`, `pHeader` in `r1`) but not the sixth: the base lives
   in a callee-saved register and the debug list records register-located
   variables only.

2. **The `add` sits after the rotation guard.**  Assigned before the loop
   (`pList = (pHeader + 1);` then `for`) the base is hoisted into the pre-guard
   block: `cmp ip,#0; add r4,r1,#0xc; bls out`.  The image has the add in the
   loop-entry block instead, which the scheduler only produces when the
   assignment is textually inside the guarded region of a **bottom-tested**
   loop, so the top test is the explicit gate and the `add` is the first
   instruction of the entry block.  The exact spelling is:

```c
i = 0;
if (i < maxBlock) {
    pList = (struct WCMApList *)(pHeader + 1);
    do {
        p = pList + i;
        if (p->state == 0)
            break;
        i++;
    } while (i < maxBlock);
}
```

(an infinite `for (;;)` with an internal `if (i >= maxBlock) break;` compiles
identically, so both are acceptable, but the do/while is the readable one).

Three one-byte traps in this shape, each measured:

- the gate and bottom test must be `i < maxBlock` (compares on the unsigned
  `maxBlock` give `bls`/`blo`).  Writing `if (maxBlock > 0)` folds the add-in
  gate to `beq` and leaves the loop right;
- the base must be `(struct WCMApList *)(pHeader + 1)` (an `add #0xc`).
  Casting first, `(struct WCMApList *)pHeader + 1`, scales the offset to `#0xd0`;
- `i` must be declared `long` (unsigned too works here, 0x02165DCC) but the
  mixed `i < maxBlock` test is otherwise a signed/unsigned divide/comparison
  puzzle — test both spellings, the branch pair decides.