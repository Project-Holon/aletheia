# A store stays above the argument constant only when the call result is stored next

summary: in `p->a = k; p->b = f(x, 1);` the first store is placed before `movs r1, #1`.
With the result discarded (`p->a = k; f(x, 1);`) mwcc puts `movs r1, #1` first.

## The shape

```asm
    ldr  r0, [sp, #4]      ; x reloaded
    strb r6, [r5, #4]      ; p[4] = k, stays above the constant
    movs r1, #1
    bl   .f
    strb r0, [r5, #5]      ; p[5] = result
```

## Evidence (real compiles, 2026-10-05, wave D9r lane 190)

Twin: ov093 021E4EC4 (matched `ov093_func_021E4EC4.c`, around 021E4F18). Edits of the twin:

- as filed: strb, movs r1,#1 (store first).
- `p[5] = f(b, 1)` changed to a discarded `f(b, 1)`: movs r1,#1, strb.
- `f(b, 1); p[5] = 0;`, `p[5] = f(b, 1) + 1;`: movs, strb.
- `p[5] = f(b, 1)` kept, the first store through another base: strb first.
- result bound to a local that is then stored: strb first.

So the order follows the use of the call result by a store, not the base or the value
of the first store. Use it when a store sits before the argument constant and the
call result is stored afterwards.

Not a fix for ov039 021F41A8 case 5: there the callee is void and nothing stores its result.

Found in: src/matched/ov/ov093_func_021E4EC4.c
