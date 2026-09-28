# A two-value byte test kept as two compares is a switch, because `x == 0 || x == 1` folds to one unsigned range check

summary: mwcc turns `if (b == 0 || b == 1)` on a byte into `cmp r0, #1; bhi exit`. When the image shows `cmp r0, #0; beq body; cmp r0, #1; bne exit`, the source is `switch (b) { case 0: case 1: ...; break; }`, which keeps both compares and costs nothing else.

Found in: src/matched/ov010_func_02160A94.c (0x02160A94)

The original, in the `mode == 6` arm:

```
ldrb r0, [r6, #0x12]
cmp  r0, #0
beq  body
cmp  r0, #1
bne  exit
body:
```

`if (src->f12 == 0 || src->f12 == 1) { ... }` compiles to `cmp r0, #1; bhi exit`
(the front end proves the two values are a contiguous unsigned range), which
changes the function's length by four bytes and every branch behind it.
Rewriting the test as

```c
switch (src->f12) {
case 0:
case 1:
    ...
    break;
}
```

gives the two-compare chain and the function came out EXACT with no other change.
