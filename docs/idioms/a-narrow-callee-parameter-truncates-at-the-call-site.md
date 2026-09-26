# A narrow callee parameter type is truncated at the call site, not in the callee

summary: passing a 32-bit argument to a callee whose parameter is declared
`unsigned short` makes mwcc zero-extend the argument in the caller
(`lsls`/`lsrs #0x10`, or `ldr` + mask for a stacked argument); if the parameter
is declared wider the truncation disappears and the whole tail shifts.

Found in: src/matched/func_021BEA48.c (0x021BEA48),
src/matched/func_021BBB48.c (0x021BBB48)

`func_021BEA48` forwards its own sixth parameter as the callee's fourth. The
image zero-extends it into r3 just before the call:

```
021BEA66  ldr  r3, [sp, #0xc]     /* the int a5 */
021BEA6A  lsls r3, r3, #0x10
021BEA6C  lsrs r3, r3, #0x10      /* (unsigned short)a5, at the call site */
021BEA6E  bl   #0x201b7b4
```

Declaring the callee as `void f(int, int, u16, u16)` and passing `a5` (an
`int`) reproduces it. Declaring the fourth parameter `int` emits no truncation;
declaring `a5` itself `u16` also removes it because the value arrives already
zero-extended. The same mechanism gives the `(u16)i` pair in `func_021BBB48`:
its accessor's second parameter is `u16`, so passing the `int` index `i`
truncates in the caller.
