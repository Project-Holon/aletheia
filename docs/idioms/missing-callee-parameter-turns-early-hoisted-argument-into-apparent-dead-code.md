# A missing callee parameter turns an early hoisted argument into apparent dead code

summary: when a function ends with a call whose arguments are known constants or
incoming frame addresses (like a trailing memset of a local buffer), the CodeWarrior
scheduler hoists those argument loads all the way to the prologue and pins the scratch
registers (r0, r2) across the entire function body; if the callee prototype is missing
that parameter, the compiler never emits the hoisted setup, making the original's
hoisted instructions look like unexplainable "dead code" and causing a multi-register
cascade across every intervening statement.

Found in: `src/pending/ov009_func_02184AB4.c` (0x02184AB4)

## The tell

The disassembly shows an argument register (like `r2` or `r0`) loaded near the
prologue with a constant or frame pointer, and then never read or written for
hundreds or thousands of bytes of computation:

```arm
02184AC0  add r5, sp, #0x34
02184AC4  mov fp, #0x40         /* 64 */
02184AC8  mov r0, r5            /* &x[0] */
02184ACC  mov r2, fp            /* 64 */
...
02184B28  mov r0, r5            /* re-hoist &x[0] into r0 before r5 overwritten */
...
02184B4C  mov r2, fp            /* re-hoist 64 into r2 before fp overwritten */
... [3,000 bytes of 64 MD5 rounds with NO reads or writes to r2 or r0] ...
02185684  mov r1, #0            /* zero value */
02185688  str r5, [r4, #0xc]
0218568C  bl  #0x2185848        /* trailing call (memset) */
```

Naive inspection concludes:
1. `mov r2, fp` at offset `+0x0098` is "dead code" because `r2` is never read in the function.
2. The compiled output is 24 bytes shorter than the original binary (3276 vs 3300 bytes) across every compiler version.
3. Every compiler version is blamed or assumed to have a dead-code elimination flaw.

## The cause

The trailing call `func_02185848` was declared with two arguments instead of three:

```c
extern void func_02185848(void *dst, u32 val); // WRONG: missing size_t count
...
func_02185848(x, 0);
```

In reality, `func_02185848` is a runtime thunk to `memset(void *dst, int c, size_t n)`,
taking `(r0 = dst, r1 = val, r2 = count)`.

Because `sizeof(x)` (64) is an invariant known at the start of the function and `r0`
is the local buffer address `x`, the compiler at `-O4,p` pinned `r0` and `r2` from the
top of the function to avoid recomputing them after the 64 rounds.

Declaring `func_02185848(void *dst, u32 val, u32 count)` and passing `sizeof(x)` (64):
1. Immediately emits the missing prologue setups `mov r0, r5` and `mov r2, fp`.
2. Restores the register pressure that forced identical stack spills across the body.
3. Completely closes the 24-byte size gap (3276 -> 3300 bytes).
4. Restores the exact `pop` register list and stack allocation (`sub sp, sp, #0x74`).

## The rule to apply

When an instruction in the prologue or early body loads a constant or pointer into an
argument register (`r0`-`r3`) and is never referenced by the immediate local logic:
Look at the calls in the function's epilogue. Check if one of them is missing an
argument in your C prototype that matches the value loaded into that scratch register.
