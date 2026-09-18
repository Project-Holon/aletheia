# A sub-word parameter type is what decides where a constant's live range ends

summary: changing a parameter from `u32` to `u16` changed nothing in the body of the function, yet it
moved the constant zero's live range, which moved six registers, which produced the missing
instruction. Liveness-respelling attempts at source level all failed; the parameter's *type* is what
did it, because a sub-word parameter makes the parameter's value sub-word-typed throughout the body.

Found in: `sub_0202FC48` (packet `pkt_0202FC48`), closed EXACT at 380 bytes after three DIFF readings
at 376 bytes, 117 differing bytes each

The function is the heap environment constructor. Its second parameter is a slot count. With

```c
int sub_0202FC48(const struct EnvRes *res, u32 count, u32 idCount, u32 extra)
```

the compiled function was 376 bytes and 117 bytes differed. With

```c
int sub_0202FC48(const struct EnvRes *res, u16 count, u16 idCount, u32 extra)
```

it is 380 bytes and exact. The body was byte-for-byte identical C; only the declared types changed.
Four runs, same C otherwise:

| spelling | result |
| --- | --- |
| `count u32, idCount u32` | DIFF 376, 117 bytes differ |
| `count u32, idCount u16` | DIFF 376, 117 bytes differ |
| `count u16, idCount u32` (cast at use) | **EXACT 380** |
| `count u16, idCount u16` (cast at use) | **EXACT 380** |

`count u16` is the lever; `idCount`'s type is free. What it buys: the zero the function materialises
for its clearing loop now has a live range that ends at that loop, so `total` takes `sb`, both indexes
take `r4`/`r8`, and the final loop's preheader re-materialises the zero as `mov sb, r4` off the `r4`
that `error = 0` just set. That instruction, plus the six-register prologue, is the whole difference.

What did not work, each compiled and compared at 376/117:

```c
/* all loops sharing one counter */          /* no move */
/* slot declared first (137 diffs, still 376) */   /* no move */
/* total = 0x18 + count */                   /* no move */
/* u32 total */                              /* no move */
/* u16 on idCount only */                    /* no move */
```

None of those changed where the zero's live range ends; the parameter type did, with no source-level
liveness change at all. So when a function's residue is a constant that is materialised twice and a
callee-saved register that should not be live, look at the declared types of the parameters that
produced it before respelling the loops.

The type was visible in the caller the whole time: `sub_02030608` truncates both middle arguments
with an `lsl #16` / `lsr #16` pair before the call, which only makes sense for a `u16` parameter.
When a signature is in doubt, read the call site's truncation, not the callee's body.
