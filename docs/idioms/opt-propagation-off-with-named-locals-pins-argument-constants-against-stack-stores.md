# opt_propagation off with named locals pins argument constants against stack stores

summary: when a call with stack arguments has its register-argument constants (`movs r1..r3,#N`)
scheduled on the wrong side of the outgoing stack store of a call result, write the call result
and the constant as named locals just before the call and wrap the function in
`#pragma opt_propagation off` / `#pragma opt_propagation reset`. With propagation on, the
locals are folded back into the call and the order stays wrong; either piece alone does nothing.

Found in: src/matched/ov/ov172_func_021B97AC.c (0x021B97AC), case 1:

```c
pos = func_021BA15C(st->f10);
off = 0x800;
func_021B9E5C((int)ctx, (char *)st, (s16 *)(v + off), 9, pos, 0xC000);
```

Lead came from the matched ov010 02163F40, which has the same `bl; movs rN,#imm; str r0,[sp]`
order with an explicit local for the call result.

Check first: the brief's callee-declaration rule; this is for when the order is not explained
by callee parameter types.
