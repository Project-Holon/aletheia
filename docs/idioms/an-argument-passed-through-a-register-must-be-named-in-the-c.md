# An argument passed through a register must be named in the C

summary: when a call's r0-r3 already hold the value the callee reads (the
caller's own incoming argument, or the previous call's return value), mwcc
emits no `mov`, so a C call with too few arguments still matches EXACT. The
native port then passes nothing. House rule: name every such value in the C;
the bytes do not change.

Found in: src/matched/arm9/func_020173D0.c (0x020173D0),
src/matched/arm9/func_0200523C.c (0x0200523C)

Two shapes hide an argument from the C:

* passthrough: the caller receives a value in rN and calls a function that
  reads rN, with nothing in between that writes rN;
* return chain: `bl f` then `bl g` with no `mov r0` between, where `g` reads
  r0. The C wrote `f(); g();` with `f` declared `void` or `g` given no
  argument.

Both compile to the same bytes as the honest spelling, because the register
allocator coalesces the value into the argument register. `match.py` cannot
tell them apart; the port can.

Before (EXACT, but the heap id is lost on the port):

```c
extern void func_0201AD88(void);
void func_020173D0(void)
{
    func_0201AD88();
    *(unsigned short *)(g_02146270 + 2) = 0x28b;
}
```

After (EXACT, same 24 bytes):

```c
extern void func_0201AD88(u32 heap);
void func_020173D0(u32 heap)
{
    func_0201AD88(heap);
    *(unsigned short *)(g_02146270 + 2) = 0x28b;
}
```

A return chain is fixed the same way, nesting the calls or going through a
local: in func_0200523C, `func_020070A4(); func_0200873C(); func_02008414();`
becomes `func_02008414(func_0200873C(func_020070A4()));`, with each extern
taking the prototype of its matched definition.

How to apply it:

* confirm against the listing: the register must be live from its source to
  the call. A register only looks passed if the callee actually reads it;
  check the callee's own listing or matched definition. func_02005B24 had
  been given `(u32 a0, u32 a1)` because its first call "forwarded" r0/r1,
  but that callee (func_020726D0) is `void (void)`; the fix there was to
  drop the phantom parameters.
* when a definition gains a parameter, update its prototype and its call in
  every matched caller, and check each caller's listing for what it holds in
  that register.
* two externs at one address to give one call fewer arguments is the same
  bug: func_02023EF4 matches with one three-argument prototype for
  G2x_SetBlendBrightness_, the first arm simply needing no `mov r2`.
