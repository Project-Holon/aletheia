# A one-element array initialiser keeps its address for the call, not the later store

summary: an arm that zeroes a u16 stack slot, stores a call result into it and
passes its address on (`add rX, sp, #N; movs r0, #0; strh r0, [rX]; bl f;
add r1, sp, #N; strh r0, [r1]; ... adds r1, rX, #0; bl g`) is a block-scope
`u16 s[1] = {0}; s[0] = f(); g(x, s);`. A scalar `u16 c = 0; c = f();
g(x, &c);` (or any pointer-local, cast, helper or comma spelling of it)
compiles the other way round: the callee-saved register holds the address for
both stores and the call argument gets the fresh `add r1, sp`. The address is
also computed before the zero (`add` then `movs`), which the scalar never does.

Found in: `src/matched/ov/ov021_func_021B6628.c` (0x021B6628, ov021)

```
add r6, sp, #0x10
movs r0, #0
strh r0, [r6]
blx func_02045A98
add r1, sp, #0x10
strh r0, [r1]
adds r0, r4, #0
adds r1, r6, #0
blx func_02045924
```

Source: `u16 s[1] = {0}; s[0] = func_02045A98(); func_02045924(x, s);` in the
else arm. `*s = ...` and `&s[0]` as the argument give the same bytes.
