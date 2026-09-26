# A local array's `= {0}` initializer survives where equivalent element stores are dead-store-eliminated

summary: for a stack array whose address is passed to a call, `u32 buf[3] = {0};`
compiles to `movs r0, #0` plus three `str`, and those zero stores remain even
though every element is overwritten before the first call; writing the same three
zeros as statements after the declaration (`buf[0]=0; buf[1]=0; buf[2]=0;`) gets
them eliminated, eight bytes short. A `volatile` array reproduces the stores but
reallocates the registers.

Found in: src/matched/func_021BFCE8.c (0x021BFCE8)

The original opens by zeroing a three-word stack record and then filling it from
the four argument registers, before handing its address to a helper three times:

```
021BFCE8  push {r4, r5, lr}
021BFCEA  sub  sp, #0xc
021BFCEC  adds r5, r0, #0      /* p = a0            */
021BFCEE  add  r4, sp, #0      /* buf = (u32*)&sp   */
021BFCF0  movs r0, #0
021BFCF2  str  r0, [r4]
021BFCF4  str  r0, [r4, #4]
021BFCF6  str  r0, [r4, #8]    /* these three are dead: overwritten below */
021BFCF8  str  r1, [sp]
021BFCFA  str  r2, [sp, #4]
021BFCFC  str  r3, [sp, #8]
021BFCFE  ldr  r0, [r5, #8]
...
```

Every element is overwritten by the `str r1/r2/r3` before any call can read the
slot, so a reader's first instinct is that something must be keeping the zeros
observable. Measured on this function at `-O4,p -thumb`:

```
u32 *p = a0; u32 buf[3]; buf[0]=0; buf[1]=0; buf[2]=0; buf[0]=a1; ...
    -> 48 bytes, the movs/three-str prologue is gone (DSE'd), wrong
u32 *p = a0; volatile u32 buf[3]; buf[0]=0; ... (same stores)
    -> 56 bytes, right size, but a0 lands in r4 and buf in r5, whole-body diff
u32 *p = a0; u32 buf[3] = { 0 }; buf[0]=a1; buf[1]=a2; buf[2]=a3; ...
    -> 56 bytes, EXACT
```

So the zeroing is a *declaration initializer*, not three assignment statements:
mwcc materialises `= {0}` for the array (its address escapes into the call) and
keeps it, while the same zeros written as later element assignments are ordinary
dead stores it removes. Do not reach for `volatile` first: it keeps the stores
but changes which callee-saved register each live value gets, which is a larger
diff than the missing prologue. Declare the struct/array pointer first and the
initialised array second, and `{0}` gives both the stores and the register order.
