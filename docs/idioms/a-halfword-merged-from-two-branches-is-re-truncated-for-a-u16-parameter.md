# A halfword merged from two branches is re-truncated for a u16 parameter; one straight from ldrh is not

summary: an `lsls`/`lsrs #0x10` pair right before a call, just after an `ldrh`
or a small constant that two branches feed, means the callee's parameter is
`u16` and the merged value was an `int` (a ternary of two table loads, or an
`int` local set in an if/else); a `u16` local set in the same if/else, or one
`ldrh` passed directly, gets no pair.

Found in: src/pending/ov/ov018_func_0218123C.c (0x0218123C),
src/pending/ov/ov018_func_02181584.c (0x02181584),
src/matched/ov/ov018_func_02182214.c (0x02182214)

The ov018 state machines all call `func_0217F3C4(obj, tbl[c->f42])`. When the
argument is one `ldrh r1, [r1, r2]` the call follows at once, whatever the
prototype. In three of them the value comes from one of two branches:

```
    ldr  r0, =tblA      ; or tblB on the other arm
    ldrh r1, [r0, r1]   ; tail-merged load
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    bl   func_0217F3C4
```

What reproduces the pair is `void func_0217F3C4(Ov018Obj *, u16);` plus
either `f(o, cond ? tblA[i] : tblB[i])` or `int idx; if (...) idx = tbl[...];
else idx = 5; f(o, idx);`. With an `int` parameter the pair disappears (4 bytes
short). With a `u16 idx` local the pair also disappears, because the compiler
treats the local as already narrow. Declaring the callee `u16` does not change
the call sites that pass one `ldrh` directly, so the same prototype is safe
everywhere else it is called.
