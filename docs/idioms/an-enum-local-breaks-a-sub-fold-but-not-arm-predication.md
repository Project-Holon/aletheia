# An enum local breaks a `sub`-off-zero fold but does not stop the arm predicating

summary: when an `if` arm `x = C` is folded to `sub<cond> x, x, #k` off a
`mov x, #0` that precedes the test, an enum-typed local holding `C` restores the
image's separate `mvn`/`mov` materialisation of the constant and gets the byte
count right, but the one-instruction arm is *still* if-converted to
`mov<cond> x, rT`; the leftover branch is the front-end "kept branches" tell, so
the enum local separates a fixable fold from an unfixable predication.

Found in: `src/pending/ov_sdk/ov009_func_02167E20.c` (0x02167E20)

The image computes a result that defaults to zero:

```
ldrh r0, [r4, #0x24]
mov  r5, #0            ; default
cmp  r0, #0
beq  .join
mvn  r5, #4            ; r5 = -5
.join:
```

Written the obvious `wcmResult = 0; if (field != 0) wcmResult = -5;`, 1.1p1
`-O4,p` folds the `-5` off the live zero into a predicated subtract: 100 bytes,
`mov r5,#0 / cmp / subne r5,r5,#5`, and the following callback load also hoists
above the compare. That is
`an-enum-local-materialises-a-large-complement-constant.md` applied to a zero:
the enum object stops the "derive from the adjacent constant" rewrite.

```c
typedef enum { WCM_RES_OK = 0, WCM_RES_ERR = -5 } WcmResult;
...
WcmResult err = WCM_RES_ERR;
wcmResult = 0;
if (*(unsigned short *)((char *)wcmiw + 0x24) != 0)
    wcmResult = err;
```

now compiles to 104 bytes -- the image's size -- with the materialisation back:

```
mvn  r1, #4
mov  r5, #0
cmp  r0, #0
movne r5, r1
```

but the arm is predicated (`movne`, not the image's `beq` + `mvn`). So the enum
local fixes the *fold* and leaves the *predication*: the residual is exactly one
branch decision, and neither `if`/`else`, a ternary, a `goto` join, a nested
`if`, `&&`, a one-trip loop with an explicit `continue`/`break`, nor six
repeated `wcmResult = -5;` dead stores (which CSE back before the predication
pass) change it.

Read the residue before choosing a lever. `sub<cond> x, x, #k` off a just-set
`mov x, #0` is an enum-local fix; a *branch* the compiler will not emit because
it predicates any arm of five instructions or fewer is
`predication-of-short-guard-arms-is-the-front-end-not-the-shape.md` and needs the
2.0 front end, not another spelling.
