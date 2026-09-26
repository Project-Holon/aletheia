# A two-case switch reproduces branch form where `if`/`return` if-converts

summary: ARM `-O4,p` if-converts a chain of `if (v == k) return r;` into
predicated `moveq`/`bxeq`, so the branch form of the original can be recovered
by rewriting the same tests as a `switch` with explicit `case` labels and a
fall-through default.

Found in: `src/matched/ov114_func_021C866C.c` (0x021C866C)

The function is an unlabelled ARM leaf in a `.word` run (see
`unlabelled-leaf-functions-hide-in-word-runs.md`), so the only way to attest it
is to compile it to `EXACT` ourselves. Its 60 bytes are branchy:

```
ldr r1, [pc, #0x30]     ; r1 = &d_021D3D2C
ldr r0, [r1]            ; v = d_021D3D2C[0]
cmp r0, #1
beq .ret1
cmp r0, #0x18
beq .set1
b   .ret0
.ret1: mov r0, #1
       bx  lr
.set1: mov r0, #1
       str r0, [r1]
       bx  lr
.ret0: mov r0, #0
       bx  lr
```

Written the obvious way,

```c
if (d_021D3D2C[0] == 1)
    return 1;
if (d_021D3D2C[0] == 0x18) {
    d_021D3D2C[0] = 1;
    return 1;
}
return 0;
```

this front end if-converts the whole thing to 44 bytes and no branches:

```
cmp  r0, #1
moveq r0, #1
bxeq lr
cmp  r0, #0x18
moveq r0, #1
streq r0, [r1]
movne r0, #0
bx  lr
```

The original's branch shape reappears when the same three outcomes are spelled
as case labels with the default falling through:

```c
switch (d_021D3D2C[0]) {
case 1:
    return 1;
case 0x18:
    d_021D3D2C[0] = 1;
    return 1;
}
return 0;
```

which is byte-for-byte the 60-byte branchy form. The tell is a small ARM leaf
whose original has `beq`/`b` to separate `mov ...,#1; bx lr` blocks while the
compiled `if` chain has only conditional moves: reach for a `switch` before
reworking the C.
