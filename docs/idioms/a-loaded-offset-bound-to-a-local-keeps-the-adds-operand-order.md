# A loaded offset bound to a local keeps the adds operand order

summary: A loaded word used in an address sum emits adds with the loaded register first only when the load is bound to a named local. Swapping the operands of the inline sum leaves the reversed encoding unchanged.

Found in: src/matched/ov/ov110_func_021B99A4.c (0x021B99A4), src/matched/ov/ov110_func_021B99C4.c (0x021B99C4).

Both originals load an indexed word into r1, then add an entry parameter in r2 with `adds r1, r1, r2` before scaling the sum and loading a halfword. Inlining the word load as either operand of the sum gives `adds r1, r2, r1`, one concrete byte wrong in each function.

Binding the word load first reproduces the original instruction without changing any other bytes:

```c
unsigned int value;
value = *(unsigned int *)(a + b * 4 + 0x38);
return *(unsigned short *)(a + (value + c) * 2 + 0x68);
```

Both functions reached EXACT* with the named local, fixed dsi/1.1p1 `-O4,p`, Thumb c99. This is the loaded-word counterpart of `commutative-operand-order-names-the-temporary.md`, which covers a call result.
