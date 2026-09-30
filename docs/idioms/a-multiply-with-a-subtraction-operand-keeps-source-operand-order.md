# Multiplication with a subtraction operand keeps source operand order

summary: when Thumb interpolation differs only at the two registers feeding a multiply, placing the subtraction before the halfword load in the C expression can reproduce the original without a temporary or type change.

Found in: src/matched/ov/ov121_func_021D928C.c (0x021D928C), src/matched/ov/ov121_func_021D933C.c (0x021D933C).

Both functions interpolate from a base toward a negative target using a halfword counter. The original loads the counter into r0, computes target minus base in r1, and multiplies into r0:

```c
base + ((target - base) * *(u16 *)(p + 8)) / 60
```

This is EXACT in both functions with dsi/1.1p1 and -O4,p. The equivalent operand order `base + (*(u16 *)(p + 8) * (target - base)) / 60` produces the same extent and two concrete byte differences: the load chooses r1 and the subtraction chooses r0. The multiply itself is unchanged. This concerns expression operands without a call result; the existing named-call-result idiom addresses a different register tie.
