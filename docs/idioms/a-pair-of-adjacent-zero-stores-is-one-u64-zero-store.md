# A pair of adjacent zero stores is one `u64` zero store

summary: two consecutive word stores with the same zero register
(`str r2, [r0, #0x608]; str r2, [r0, #0x60c]`) are not two `int` field
assignments writing a literal 0; they are a single `unsigned long long`
store of zero over the two words.  Written as two `int` stores the compiler
materialises the zero in a different scratch register (r1 instead of r2) and
the entry never lines up.

Found in: `src/matched/ov_sdk/ov009_func_0216E5B0.c` (0x0216E5B0)

The original at 0x0216E724 is:

```
    bl   DWCi_GetMatchCnt
    mov  r2, #0
    str  r2, [r0, #0x608]
    str  r2, [r0, #0x60c]
```

Both stored words are the same zero register, and nothing loads either word
in between.  The natural source spelling

```c
m = DWCi_GetMatchCnt();
m->f_608 = 0;
m->f_60c = 0;
```

compiles the zero into whatever scratch register is free (r1 here) and stays
three bytes off for the whole function.  Using the two words as one 8-byte
datum closes it:

```c
*(unsigned long long *)&DWCi_GetMatchCnt()->f_608 = 0;
```

The single `bl` is produced either way because `DWCi_GetMatchCnt()` is
opaque (an `extern` in the reconstructed TU, a visible static in the vendor
TU).  The tell that it is one `u64` and not two `int`s is the shared zero
register; the tell that it is not a `u64` local is that both stores reuse one
register rather than a register pair.
