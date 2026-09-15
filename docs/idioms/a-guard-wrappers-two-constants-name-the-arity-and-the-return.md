# A guard wrapper's two constants name the inner call's arity and the wrapper's return type

summary: in a thin wrapper that sets a flag, calls one function and clears the
flag again, the register each of the two constants lands in is the only evidence
of the wrapper's own signature: `mov ip, #1` before the call says all four
argument registers are live, so the wrapper forwards four parameters, and a
constant after the call that avoids r0 says the wrapper returns the callee's
result rather than discarding it; four bytes across two instructions, with a
`void` one-parameter reading otherwise byte for byte right.

Found in: `src/pending/unit_02030DA8.c` (0x02030DA8), against
`src/matched/sub_02030DA8.c` as first written

The whole function is eight instructions and the original is:

```
02030DA8  push {r4, lr}
02030DAC  mov  r4, r0
02030DB0  mov  ip, #1           /* not r1, r2 or r3 */
02030DB4  str  ip, [r4, #0x2c]
02030DB8  bl   #0x2030dc8
02030DBC  mov  r1, #0           /* not r0 */
02030DC0  str  r1, [r4, #0x2c]
02030DC4  pop  {r4, pc}
```

Nothing here sets r1, r2 or r3 before the `bl`, and nothing reads r0 after it,
so the obvious reading is a one-parameter `void` wrapper:

```c
void sub_02030DA8(struct Ctx *c)     /* wrong, four bytes out */
{
    c->busy = 1;
    sub_02030DC8(c);
    c->busy = 0;
}
```

which compiles to `mov r1, #1` and `mov r0, #0`: with only r0 live the allocator
takes the lowest free scratch register on each side, and it takes a different
one on each side because the sides are separated by a call. Both constants are
wrong, and each is wrong for its own reason.

**Before the call, `ip` means the argument registers are all taken.** mwccarm
reaches for r12 only when r0-r3 are unavailable, which in a function that has
not yet called anything means they are all holding live parameters. So the
wrapper has four parameters and forwards them untouched:

```c
sub_02030DC8(c, a, b, key);
```

The absence of any `mov` into r1-r3 is not evidence of a one-argument call;
it is what forwarding your own parameters in order looks like. This is the same
trap as
`docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md`
read from the other end: there the leftovers were leftovers, here they are real,
and `ip` is what tells the two apart without needing the callee's own bytes.

**After the call, avoiding r0 means the result is live.** r0 is the first free
scratch register once the call has returned, and mwccarm takes it unless the
value in it is still needed. It is needed exactly when the wrapper returns it:

```c
struct Node *sub_02030DA8(struct Ctx *c, u32 a, u32 b, u32 key)
{
    struct Node *n;

    c->busy = 1;
    n = sub_02030DC8(c, a, b, key);
    c->busy = 0;
    return n;
}
```

The `return` costs no instruction of its own, because the value is already in
the right register; its only trace in the bytes is that the clearing constant
had to go somewhere else. A wrapper that dropped the result would clear the flag
through r0 and be four bytes different.

Both halves are needed: with four parameters but a `void` return the second
constant is still `mov r0, #0`, and with the return but one parameter the first
is still `mov r1, #1`. Together they are exact.

The practical rule for a flag-guarded wrapper: read the two constants before
reading anything else. `ip` before the call counts the arguments, and whatever
the constant after the call avoids is what the wrapper hands back.
