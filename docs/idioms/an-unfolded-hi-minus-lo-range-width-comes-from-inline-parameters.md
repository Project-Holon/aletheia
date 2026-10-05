# An unfolded hi minus lo range width comes from inline parameters

Found in wave D9 (2026-10-05): `src/matched/ov/ov186_func_021FB4CC.c` (EXACT*).

## Symptom

The image computes both bounds and subtracts them at run time, although the
width is a constant or a plain field:

```
adds r4, r1, r4      ; hi = x + w
subs r1, r4, r1      ; hi - x   (not folded to w)
...
adds r2, r3, #0
subs r2, #0x10       ; lo = y - 16
adds r3, #0x10       ; hi = y + 16
subs r0, r3, r2      ; hi - lo  (not folded to 32)
```

Written directly in the function, or with `x`, `y` as locals, mwcc folds
`(x + w) - x` to `w` and `(y + 16) - (y - 16)` to `cmp #0x20`.

## Source

The range test is a static inline with the bounds as parameters. The parameters
are separate values to the folder, so `hi - lo` stays:

```c
static inline int in_range(int v, int lo, int hi)
{
    return (u32)(v - lo) <= (u32)(hi - lo);
}

hx = in_range(a1, pos.x, pos.x + p[5]);
return in_range(a2, pos.y - 16, pos.y + 16) & hx;
```

The order of the two calls sets the schedule: the first result as a named local
written before the second call gives `r7 = 0` early (its zero is reused as the
`ldrsh` index) and `ands r0, r7` at the end. One expression
`in_range(...) & in_range(...)` loads `pos.y` first.
