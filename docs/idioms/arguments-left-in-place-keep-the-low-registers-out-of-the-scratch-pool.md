# Arguments left in place keep the low registers out of the scratch pool

summary: When a call site sets only r0 and leaves r1/r2 untouched, those
registers may be live incoming arguments rather than leftovers, and the
constraint they impose on the allocator is visible as a higher-numbered
scratch register.

The case is `src/matched/unit_02041F28.c` (0x02041F28, ARM).  Each of the
three functions computes an address into r0 and then calls a helper:

```
02041F28  push {r3, r4, r5, lr}
02041F2C  ldr r4, [pc, #0x34]      ; &g_02146A44
02041F30  mov r5, r0               ; which
02041F34  ldr r3, [r4]             ; g_02146A44
02041F38  mov r0, #0x2c            ; the 0x2c stride
02041F3C  add r3, r3, #8
02041F40  mla r0, r5, r0, r3       ; r0 = &slots[which]
02041F44  bl   0x02043228
```

The call target is the three-argument `sub_02043228(obj, op, value)`
(`src/matched/sub_02043228.c`, `EXACT`), so `op` and `value` are passed in
r1 and r2 and the call site needs no instructions for them: they are
already there, having come in as this function's own second and third
parameters.  Written as a one-argument call,

```c
void func_02041F28(u32 which)
{
    func_02043228(&g_02146A44->slots[which]);
    g_02146A44->unk_04 |= (u16)(1 << which);
}
```

every instruction of the body is correct but the context value lands in
**r1** (`ldr r1, [r4]` / `add r1, r1, #8` / `mla r0, r5, r0, r1`): the
allocator reuses the lowest free register, and with nothing live in r1 it
takes it.  With the pass-through parameters declared

```c
void func_02041F28(u32 which, u32 op, u16 value)
{
    func_02043228(&g_02146A44->slots[which], op, value);
    g_02146A44->unk_04 |= (u16)(1 << which);
}
```

r1 and r2 are live across the address computation, so the scratch goes to
**r3** and the range goes `EXACT`.  Four bytes per function, and the whole
of the difference is the allocator's register choice - thirteen other
source spellings of the address expression (slot pointer local, `slots +
which`, byte arithmetic, explicit stride, named `u16` temporaries) are all
byte-identical to the one-argument form.

So: when a call site prepares only r0 and the callee is known to take more
parameters, try declaring the extra parameters and forwarding them.  The
register the *other* temporaries land in is the tell - a scratch in r3 or
r6 where r1 would do means something else in the function is holding r1.

The companion idiom
(`a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md`) is
the opposite reading of the same shape: a `bl` at the very top of a
function, with no address computation in between, usually forwards only its
first parameter.  The distinction is whether the untouched registers are
live *into* the call by construction - here they are, because the source
names them as the callee's arguments.
