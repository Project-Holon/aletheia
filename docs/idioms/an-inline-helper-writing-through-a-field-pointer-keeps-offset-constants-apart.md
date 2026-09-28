# An inline helper that writes through a field pointer keeps the offset constants apart

summary: when an original rebuilds every out-of-reach field offset from scratch
(`movs #7; lsls #6; subs #6` for 0x1BA right after 0x1C0 was built the same way),
the source computed those accesses inside a `static inline` helper that takes
`&p->field`; writing the same code open in the caller lets mwccarm pool one
offset and derive its neighbours with `adds`, and no reordering of the open code
undoes that.

Found in: src/matched/ov111_func_021C842C.c (0x021C842C)

The original compares a stored touch position against a new one on both axes.
For each axis it takes the absolute difference and stores the direction (-1 or
+1) in a byte next to the stored position:

```
movs r1, #7
lsls r1, r1, #6
subs r1, r1, #6        /* 0x1BA, built fresh */
strb r2, [r5, r1]
...
movs r0, #0x71
lsls r0, r0, #2        /* 0x1C4, built fresh again */
ldr r1, [r5, r0]
```

Written open in the caller, with the struct or with byte offsets, the same
logic compiled to a pool word for 0x1BA and `adds r0, #0xa` for 0x1C4: the
offsets became one shared constant chain, the dx value moved to another
register, and the function grew by 14 bytes (207 bytes out). Splitting the
guard chain into separate `goto` exits, struct versus raw offsets and a
permuter run (seed 7801) changed nothing.

The closing spelling moves the per-axis code into a helper:

```c
static inline int Delta(s8 *dir, u32 prev, u32 cur)
{
    int d;

    if (prev > cur) {
        d = prev - cur;
        *dir = -1;
    } else {
        d = cur - prev;
        *dir = 1;
    }
    return d;
}

dx = Delta(&p->sx, PREV_X, x);
```

That brought it to 8 bytes out. The rest was ordinary: declare the `hit` flag
before the two stack locals and set it before the call rather than after.
If a diff shows a pool word plus `adds` where the original rebuilt each offset
with `movs`/`lsls`/`subs`, look for code that the source wrote once as a
helper taking a field address.
