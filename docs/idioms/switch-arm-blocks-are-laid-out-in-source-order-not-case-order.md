# A compare-chain switch tests its cases in label order but emits its arm blocks in source order

summary: when mwccarm turns a small dense switch into a chain of `cmp`/`beq`
instead of a table, the chain is always in ascending case-label order whatever
the source does, but the blocks those branches point at are laid out in the
order the cases appear in the source; so the arms have to be written in the
image's block order, which is not necessarily numeric order.

Found in: `src/matched/func_0204D768.c` (0x0204D768)

## The tell

The compare chain and the block order disagree. At 0x0204D768 the chain runs
0, 1, 2:

```
0204D778  cmp r1, #0
0204D77C  beq #0x204d794        ; case 0 block, first
0204D780  cmp r1, #1
0204D784  beq #0x204d7b4        ; case 1 block, LAST
0204D788  cmp r1, #2
0204D78C  beq #0x204d7a4        ; case 2 block, second
```

while the blocks are laid out 0 at +0x2c, 2 at +0x3c and 1 at +0x4c. Written
in numeric order, the C compiles to the same chain with the two `beq`
displacements swapped and the two blocks swapped: 14 bytes differ, every one of
them inside those four instructions.

## The fix

Write the cases in the image's block order and leave the labels alone:

```c
switch (cmd->op) {
case 0: ... break;
case 2: ... break;
case 1: ... break;
}
```

The chain still comes out 0, 1, 2.

## Why a chain and not a table

Three cases dense from zero would normally build the PC-relative halfword table
of `dense-switch-is-a-pc-relative-halfword-table.md`. It does not here because
every arm is a single call followed by the epilogue: there is no shared tail to
jump to, so the table plus its load and add would cost more than three compares.
Read the absence of a table as a statement about arm size, not about case
density, and keep checking the block order when you get one.
