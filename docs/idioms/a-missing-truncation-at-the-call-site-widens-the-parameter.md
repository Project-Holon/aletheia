# A caller that does not truncate its argument pins the callee's parameter wider than the callee's own body suggests

summary: a `u16` parameter costs the *caller* a `lsl`/`lsr` pair at every call
site that passes a wider value, so an original whose call site has no such pair
is telling you the real prototype takes `int`/`u32`, even when the callee's body
only ever stores the value as a halfword.

Found in: src/matched/sub_02045874.c (0x02045874), src/matched/sub_020457B0.c (0x020457B0)

The callee, 0x020457B0, uses its first parameter twice: once shifted left by
one and once stored with `strh`. Both uses are consistent with `u16`, and
declaring it `u16` reproduces the callee byte for byte:

```c
struct U16Vec *sub_020457B0(u16 capacity, u32 heapId)
{
    ...
    vec->capacity = capacity;
}
```

The caller at 0x02045874 then comes out eight bytes too long. Its original is

```
ldrh r0, [r4, #2]
add  r0, r0, #1
bl   #0x20457b0
```

three instructions, with no narrowing of `used + 1` before the call. With the
`u16` prototype in scope the compiler has to produce the narrowing itself, and
the ARM way to narrow to sixteen bits without a spare constant is a shift pair:

```
ldrh r0, [r4, #2]
add  r0, r0, #1
lsl  r0, r0, #0x10      /* the two extra instructions */
lsr  r0, r0, #0x10
bl   #0x20457b0
```

Widening the parameter to `u32` removes them, and the callee still matches,
because inside the callee nothing observes the high halfword: `lsl ip, r5, #1`
is the same instruction either way, and the store is `strh` either way. The
narrowing simply moves into the one place it is visible, the assignment to the
`u16` field, written as an explicit cast:

```c
struct U16Vec *sub_020457B0(u32 capacity, u32 heapId)
{
    ...
    vec->capacity = (u16)capacity;
}
```

The general point is that a narrow integer parameter is a statement about the
*caller*, not the callee. On this ABI the callee is entitled to assume its
argument already fits, so a `u16` parameter emits no code at all in the callee
and emits two instructions in every caller that cannot prove the value fits.
That makes the call sites the only evidence for parameter width, and it makes
the width a cross-file property: a function matched in isolation with a narrow
parameter can be silently wrong in a way that only shows up when someone
decompiles a caller.

Two practical consequences. When a caller is a clean multiple of eight bytes
too long at a call, check for a shift pair against the prototype before
suspecting the caller's own expression. And when writing a callee whose body
only ever stores a parameter narrowly, prefer the wide parameter with an
explicit cast at the store: it matches the callee equally well and does not
lay a trap for whoever takes the caller's packet.
