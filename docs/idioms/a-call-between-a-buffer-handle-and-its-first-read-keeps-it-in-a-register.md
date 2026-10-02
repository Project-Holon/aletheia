# A call between a buffer handle and its first read keeps it in a register

summary: a local `u32 p = (u32)buf;` holding a stack buffer's address is
rematerialised (`add rX, sp, #0` at every use) when its first read follows the
assignment with no call in between. A repeated constant (here the `0` passed
five times) then takes the free callee-saved register instead. If a call lies
between the assignment and the first read of `p`, mwcc keeps `p` as a register
variable and the constant is rebuilt per call. Passing the buffer itself
(`func(buf)`, not `func(p)`) to the first call after the assignment supplies
that call without adding code: the address is still read from `p`'s register.

Found in: src/matched/ov/ov021_func_021AD410.c (0x021AD410).

Original:

```
bl   func_021ABE24
add  r7, sp, #0        /* buffer handle, set right after the getter */
adds r4, r0, #0
adds r0, r7, #0
bl   func_021C6AE0
...
adds r1, r7, #0
movs r2, #0            /* constant rebuilt at each of five calls */
bl   func_021C6574
```

Plain `buf` arguments, or `p = (u32)buf;` followed directly by
`func_021C6AE0(p)`, build `movs r7, #0` and `add r0, sp, #0` at every buffer
use. Assigning `p` before the getter call keeps r7 but puts `add r7, sp, #0`
before that `bl`. The fix:

```
r4 = func_021ABE24(a[0]);
p = (u32)buf;
func_021C6AE0(buf);        /* the buffer, not p */
func_021C6AF0(p, r4, 0x37);
```

The first call's argument must not be exactly `(u32)buf`; any pointer form
(`buf` to a `u32 *` or `void *` parameter, `(u32)(u32 *)buf`) works.
Changes with no effect: a pointer-typed holder (`u32 *p = buf;`), `const`,
`register` or `volatile` on the holder, a `goto` or label after the
assignment, an unreachable call, and a holder declared in another position.

How to spot it: a function that sets a callee-saved register to a stack
address right after a call, uses it for many calls, and rebuilds a constant
that appears three or more times with `movs` at each use.
