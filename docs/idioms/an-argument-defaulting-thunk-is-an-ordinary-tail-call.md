# An argument-defaulting thunk is an ordinary tail call and is producible from C

summary: A wrapper that pins some arguments to constants and tail-calls the real callee compiles to `ldr ip,[pc,#8]; mov r1,#0; mov r2,#0xa; bx ip` (plus the pool word) from a plain `return f(a0, 0, 10);`, so `label`/`sole-ref/code` are not needed to file it -- matching the thunk gives its callers a `matched` witness.

Found in: src/matched/func_020964E0.c (0x020964E0), src/matched/func_020964F4.c (0x020964F4)

An "argument-defaulting thunk" is the shape mwcc emits for a small wrapper
that forwards its first argument and supplies constants for the rest, for
example the `atoi` entry point over the s32 decimal parser at 0x02095F40:

```
  020964E0  ldr ip, [pc, #8]      ; address of func_02095F40
  020964E4  mov r1, #0            ; default out-pointer
  020964E8  mov r2, #0xa          ; default radix 10
  020964EC  bx ip
  020964F0  .word 0x02095F40
```

A previous lane recorded this as "neither is producible from C" and left the
callers capped at MATCH.  It is producible; the wrapper is an ordinary tail
call:

```c
typedef unsigned int u32;
extern int func_02095F40(u32 a0, u32 *a1, u32 a2);
int func_020964E0(u32 a0) { return func_02095F40(a0, 0, 10); }
```

The compiler schedules the pool load (`ldr ip`) before the constant moves,
which is what makes the shape look special; the C does not need to say
anything about it.  Match the thunk once and its unlabelled address becomes a
`matched` witness for every overlay caller, converting a whole set of
witness-starved MATCH files to EXACT.

The plausible wrong C is a wrapper that materialises the constants before the
call target, or an `int` local for the constants and the call on a separate
statement; both lose the exact schedule.  The s64 sibling at 0x020964F4 is the
same shape against func_020963F8.
