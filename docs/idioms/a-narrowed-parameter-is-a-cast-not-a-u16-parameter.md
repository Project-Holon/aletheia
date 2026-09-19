# A narrowed parameter is a cast, not a `u16` parameter

summary: mwccarm does not narrow a `u16` parameter at function entry, so a
two-variable four-shift narrowing run that sits at a call site is an explicit
conversion in the C and the parameters it converts must be declared wider than
`u16`: declaring them `u16` produces no shifts and the function comes out short.

Found in: `src/matched/func_0202A994.c` (0x0202A994)

**Symptom.** The original opens the argument setup of a call with
`lsls r0, r0, #0x10` / `lsls r1, r1, #0x10` / `lsrs r0, r0, #0x10` /
`lsrs r1, r1, #0x10` -- the two-variable, four-shift narrowing pattern --
placed *at the call site*, after the guards and after the stack argument
has been loaded. Declaring the parameters `u16` produces no shifts at all
and the function comes out shorter than the original.

**Cause.** This front end does not narrow a `u16` parameter at function
entry: it assumes the caller already passed a correctly narrowed value.
So a narrowing run that appears anywhere other than the prologue is an
explicit conversion in the C, and the parameter it converts must be
declared *wider* than `u16`.

**Fix.** Declare the parameters at their promoted width (`u32` / `int`)
and write the cast at the call:

```c
void f(u32 a, u32 b, int c, u32 *out, u16 d)
{
    ...
    v = callee((u16)a, (u16)b, d);   /* this is what emits the four shifts */
}
```

The fifth parameter read with `ldrh` from the incoming stack slot is a
real `u16` and needs no cast -- that asymmetry inside one call is the tell.

**Worked example.** `func_0202A994` (`0x0202A994`, 96 bytes, thumb):
`u16` parameters gave `DIFF`, four bytes short, with the two shifts missing
before the `bl`; `u32` parameters plus `(u16)` casts at the call site gave
`EXACT`. `extern u32 callee(...)` + `(u8)` on the return is the matching
tell on the result side (see `docs/notes/pkt_0202AF74.c.txt`).
