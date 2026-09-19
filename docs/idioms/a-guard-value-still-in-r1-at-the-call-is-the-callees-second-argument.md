# A guard's value still sitting in r1 at the call is the callee's second argument

summary: when a field load feeds a `cmp ... #0` guard and the *same* register
is never reloaded before the guarded `bl`, the original call passes that value
a second time - `f(block, p->f08)` - not `f(block)`.  Writing the one-argument
form does not just cost an argument: the compiler allocates the load into r0
(the call's first argument register) instead of r1, and six bytes differ.

Found in: src/pending/func_0206B6A4.c (0x0206B6A4), three sites at +0x004C,
+0x0060 and +0x0074, ../2.0/sp2

## The shape

The original, for each of the object's three sub-blocks:

```
0206B6A4  ...                      ; the three clear calls, r1 = &block
0206B714  ldr  r1, [r4, #8]        ; the guard's field
0206B718  cmp  r1, #0
0206B71C  beq  #0x206b718
0206B724  add  r0, r4, #0x3c       ; r0 = the block
0206B728  bl   #0x206b63c          ; r1 is still the field value
```

`r1` is not a leftover here.  The one-argument spelling

```c
if (p->f08 != 0)
    func_0206B63C((char *)p + 0x3c);
```

compiles to `ldr r0, [r4, #8] / cmp r0, #0 / ... / add r0, r4, #0x3c`, i.e. the
guard's temporary takes r0 because nothing else needs it, and the block address
then overwrites it.  Six bytes, two instructions per site.  Every other site,
relocation field and pool word of the function is identical, and the function
still comes out the right length, so this reads as an allocation quirk rather
than a difference in the source.

The two-argument spelling

```c
if (p->f08 != 0)
    func_0206B63C((char *)p + 0x3c, p->f08);
```

reproduces the original exactly: the load goes to r1 because r1 *is* the
second argument register, and the value the guard already needed is neither
reloaded nor copied.  Confirm it against the callee's own prologue -
`0x0206B63C` opens `cmp r1, #0 / popeq {r3, r4, r5, pc}`, which is a function
that takes a second argument and returns immediately when it is zero, exactly
the `if (value != 0)` guard the caller wrote.

## Why it is easy to miss

The call is a *release* call, `f(block, value)` frees the block and takes the
value along, and the value is the very thing the guard tested.  Reading only
the caller, the second argument costs no instruction at all, so nothing in the
emitted code advertises it; the only tell is which register the load landed in.
This is the third member of the family whose other two are
docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md
(a bare argument register at the *top* of a function is usually a leftover) and
docs/idioms/a-loop-carried-value-in-a-callees-argument-register-names-the-arity.md
(a loop-carried value in an argument register is a real argument).  The rule to
apply: a register that is *loaded immediately before a guard* and survives the
guard into the call is a real argument, because a leftover would have been the
callee's own earlier value, not a fresh load.
