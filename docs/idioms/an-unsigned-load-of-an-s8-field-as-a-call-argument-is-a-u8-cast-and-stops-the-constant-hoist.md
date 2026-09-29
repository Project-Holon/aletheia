# A `ldrb` of a field the function otherwise loads with `ldrsb` is a `(u8)` cast at the call, and it also stops mwcc hoisting the offset constant

summary: when the same s8 field is read with `movs rN,#5; ldrsb rM,[rB,rN]` everywhere
except one call argument, which is `ldrb rM,[rB,#5]`, write that argument as
`(u8)p[5]`; leaving it `p[5]` makes mwcc keep `#5` in a callee-saved register across
the whole function and spill a real local, shifting every register and the frame.

Found in: src/matched/ov/ov039_func_021F4740.c (0x021F4740)

The `ldrsb` register-offset form needs the offset in a register, and the original
rematerialises `movs r0,#5` in each block. With every access spelled `s8 p[5]` we
hoisted `movs r7,#5` at the first use, which took r7 from the u8 local `v` (spilled to
`[sp,#4]`, frame 8 bytes bigger). Casting the one argument that reaches a u8 parameter
(`func_021F47D8(b, v, (u8)p[5])`) folds that load to `ldrb [r5,#5]`, removes a use of
the constant, and the hoist and the spill both disappear. Same function: the store
`*(p+i+0x21EC) = q[0x10+i] + i*2` needs the shift first and the byte read as
`i * 2 + *(u8 *)(q + i + 0x10)` (`q + i` then `#0x10` as the load offset, load in r0,
shift in r1).
