# Returning the callee's result keeps it live in r0 and pushes the next temp to r1

summary: A wrapper that hands its callee's return value back to its own caller
must keep that value in r0 across the store it does in between, so the first
free temporary of that store is allocated r1, not r0. Spelling the function
`void` (or discarding the call result) frees r0 and lands the temp in r0
instead, a three-instruction `DIFF` with no size change.

Found in: src/matched/func_02200228.c (0x02200228)

The original is `int` and its tail is `blx #0x204A298`, then a load/shift/store
of an out-value, then the epilogue, with r0 never rewritten:

```
blx  #0x0204A298
ldr  r1, [sp, #4]      ; the out-value lands in r1, not r0
lsrs r1, r1, #1
str  r1, [r4]          ; *out = local >> 1
add  sp, #8
pop  {r4, pc}          ; r0 still holds the callee's result
```

The C that reproduces it keeps the callee result in a live local that is the
return value:

```c
int func_02200228(void *a, unsigned *out)
{
    int local;
    int r = func_0204A298(0x62, 5, 0, a, &local);
    *out = (unsigned)local >> 1;
    return r;
}
```

Every spelling that drops the result — `void` return type, or assigning to a
local that is never read again — lets mwccarm reuse r0, giving the same three
instructions with r0 substituted for r1:

```
ldr  r0, [sp, #4]
lsrs r0, r0, #1
str  r0, [r4]
```

That variant is byte-identical in size and differs only in those three
registers, so it is a `DIFF` that looks like an allocator tie but is really a
missing live return value. The tell is a first free temporary that is not r0
right after a call.
