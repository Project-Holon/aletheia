# A divide after a conditional subtract, with the divisor kept live, is a divide in each arm

summary: under dsi/1.1p1 -O4,p Thumb, when the original loads a constant K once, uses it
in a multiply `m = n * K`, then does `cmp t, m; blo L; subs t, t, m; b L; L: blx _u32_div_f`
with r1 still K (a no-op `b` to the next instruction), the source is an if/else that
divides in each arm, with the result in a block-local u16:

```
{
    u16 x;
    if (t >= m)
        x = (t - m) / K;
    else
        x = t / K;
    f(p, 8, x);
}
```

Tail merging shares the divide call and leaves the `b`. `if (t >= m) t -= m; f(.., t / K)`
reloads K and multiplies into K's register. The block scope matters: the same `u16 x`
declared at function scope adds a register copy before the truncation.

Found in: src/matched/ov/ov133_func_021B6100.c (0x021B6100).
