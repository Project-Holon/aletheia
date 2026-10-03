# An enum flag local keeps zero-first if/else before a call

summary: `if (*q == 0) flag = FALSE; else flag = TRUE;` retains zero-first Thumb branch polarity only when the local itself is enum-typed. Enum constants assigned to a u32 local still fold into one-first Boolean materialisation.

Found in: src/matched/ov/ov204_func_021BE770.c, src/matched/ov/ov204_func_021BE78C.c.

The originals load the object and flag, then emit `cmp r1,#0; bne one; movs r1,#0; b join; one: movs r1,#1` before calling the setter.

```c
typedef enum { B_FALSE, B_TRUE } Bool;
Bool flag;
if (*q == 0) flag = B_FALSE;
else flag = B_TRUE;
setter(obj, flag);
```

With a u32 local, integer ternaries, integer if/else and enum-constant if/else all produced the same three-byte polarity DIFF. Changing only that local to Bool gave EXACT* on both functions under dsi/1.1p1 -O4,p. The two-byte remainder is alignment padding.

This complements a-flag-ternary-over-enum-constants-keeps-the-bne-to-one-polarity.md: its narrow ternary case keeps a u16 local, while this full-width if/else case needs the enum local itself. Wave70 S14 run3/run4/run5 logs retain the paired evidence.
