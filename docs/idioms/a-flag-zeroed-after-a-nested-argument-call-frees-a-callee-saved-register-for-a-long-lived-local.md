# A flag zeroed after a nested argument call frees a callee-saved register for a long-lived local

summary: when the image zeroes a spilled flag (`movs r0, #0; str r0, [sp]; str r0, [sp, #N]`)
only after an inner call that computes another argument of the same outer call, the source assigns
the flag after that inner call (`k = inner(x); flag = 0; outer(..., k, ..., flag);`). Written as
`flag = 0; outer(..., inner(x), ..., flag);` the zero is set before the inner call, the flag takes a
callee-saved register, and a long-lived local elsewhere in the function is spilled, so the residue
looks like a whole-body allocation wall.

Found in: src/matched/ov/ov021_func_021B88DC.c (0x021B88DC, 2184 bytes)

The function is a four-arm direction dispatch. The image keeps `end` (p->f10) in r7 for the whole
body with a 0x6c frame. Every draft since 2026-09-26 spilled `end` (frame 0x54) and moved the arm
values from r6 to r7. Normalised op streams agreed on 988 of 993 instructions, so the difference
was allocation only.

How it was isolated: compile subsets of the arms (keep the entry and one, two or three arms, drop
the rest) and check where `ldr rN, [r5, #0x10]` lands. Arm f08 alone, f08+9404 and f08+9434
kept `end` in a register and matched the image's allocation for those arms exactly (modulo
register names). f08+93D4, 93D4 alone and 93D4+9404+9434 spilled `end`. f08+93D4+9404 kept it,
and there the 93D4 arm matched the image except for the flag's zero store, which came before the
`bl 9404` in the draft and after it in the image. The 93D4 arm was therefore the one tipping the
balance.

```c
/* image: flag = 0 after the 9404 call */
row = func_021B87D8(p->f24, seg->f00);
r = func_021B9404(dir);
flag = 0;
e1 = func_021B8514(row, r, p->f24, p->f28, flag);
```

`flag = 0` written as the argument expression (`..., flag = 0)`) is still scheduled before the
inner call. Only a statement after the call moves the store. With this one change the frame grew to
0x6c and `end` returned to r7 (1093 bytes out to begin with). The rest was control flow: one
else-if that was two sequential ifs in the image, and per-half locals.

General lesson: when one long-lived value is spilled in a big multi-arm function, compile arm
subsets to find the arm that tips the allocator. Then diff that arm alone, where the residue is
small enough to read.
