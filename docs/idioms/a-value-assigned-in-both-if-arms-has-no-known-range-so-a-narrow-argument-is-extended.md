# A value assigned in both arms of an if/else has no known range, so a narrow argument is sign-extended

summary: when the original shifts an argument left and right by 16 (`lsls #0x10; asrs #0x10`) although the value comes from a plain `ldrb`, the source assigned the value in each arm of a preceding if/else. A single assignment after the join (`y = p[6];`) is copy-propagated as the u8 expression, so the compiler knows the range and drops the extension.

Found in: `src/matched/ov/ov217_func_021C0F78.c` (0x021C0F78)

The callee takes `s16 x, s16 y`. `x` is `p[5]` or `p[5] + f(p, text)` and is extended in both builds. `y` is `p[6]`.

```c
if (*(int *)(p + 0xC) != 0) {
    x = p[5] + func_021C1090(p, text);
    y = p[6];
} else {
    x = p[5];
    y = p[6];
}
```

With `y = p[6];` after the join the call compiled 4 bytes shorter (no `lsls/asrs` on `y`) and the `ldrb` was scheduled after the stack stores. With the load in each arm the join value is a phi with no range, the extension appears, and the `ldrb` sits at the join top as in the image.

Related: a-singleton-global lever files for register colour; this one is about value-range knowledge, not colour.
