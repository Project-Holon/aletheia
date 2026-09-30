# A null-guarded bool field test keeps the zero hoisted; a single conjunction branches

summary: For `result = (p != 0) && (p->f & 1);` (and the `if (p && (p->f & 1)) result = 1;` spellings) mwccarm selects the value in r0 with a branch; wrapping the same bool `!= 0` test in a null guard (`if (p != 0) result = (p->f & 1) != 0;`) hoists `mov r1,#0` above the branch and predicates `movne r1,#1`, which is what the image has.

Found in: src/matched/ov_sdk/ov009_func_0215E6B8.c (0x0215E6B8)

`SOCL_Shutdown` reads a `flags` halfword and turns bit 0 into a `long result`:

```
cmp r4, #0
mov r1, #0
beq .L
ldrsh r0, [r4, #0xac]
tst r0, #1
movne r1, #1
.L:
cmp r1, #0
mvneq r0, #0x26
popeq {r3, r4, r5, pc}
```

The image's `mov r1,#0` sits *before* the `beq`, and the set is the predicated
`movne r1,#1`. The obvious one-expression spellings all lose that:

```c
result = (socket != 0) && (socket->flags & 1);            /* r0 select + bne  */
if (socket && (socket->flags & 1)) result = 1;            /* r0 select + bne  */
result = (socket != 0) && (socket->flags & 1) ? 1 : 0;    /* r0 select + bne  */
```

each producing

```
cmp r7, #0
beq .L
ldrsh r0, [r7, #0xac]
tst r0, #1
movne r0, #1
bne .M
mov r0, #0
.M:
cmp r0, #0
```

The assignment the image actually came from keeps the operand in a distinct
register by binding the field test to a bool *inside* the null guard:

```c
result = 0;
if (socket != 0)
    result = (socket->flags & 1) != 0;
```

Note the field itself has to be `volatile`: the image re-reads `flags` with a
fresh `ldrsh` at each of its four tests (`& 1`, `& 4`, `& 8`, `|= 8`), and a
plain `short flags` lets 1.1p1 CSE the load down to one.
