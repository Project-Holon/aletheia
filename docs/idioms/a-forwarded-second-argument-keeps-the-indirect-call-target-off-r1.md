# A forwarded second argument keeps the indirect call target off r1

summary: For `return (*(T (*)(void *, int))((char *)p + 0x10))(p, a);` the
compiler loads the function pointer into r2; the one-argument form loads it
into r1 and is four bytes shorter than the original.

Found in: src/matched/ov067_unit_021B69B8.c (0x021B69C8)

The original, an 8-byte Thumb leaf:

```
push {r3, lr}
ldr  r2, [r0, #0x10]
blx  r2
pop  {r3, pc}
```

The register holding the loaded target is decided by whether the caller has to
keep r1 live across the `ldr`. If the callee is declared as taking only the
object pointer,

```c
int f(void *p)
{
    return (*(int (**)(void *))((char *)p + 0x10))(p);
}
```

the compiler is free to reuse r1 for the loaded pointer, because nothing needs
r1 after the load:

```
ldr  r1, [r0, #0x10]
blx  r1
```

That is the same size but two concrete bytes different, so it reports `DIFF`,
not `MATCH`. Declaring the forwarded second parameter forces the compiler to
preserve r1 for the call and it picks r2 as the scratch register:

```c
int f(void *p, int a)
{
    return (*(int (**)(void *, int))((char *)p + 0x10))(p, a);
}
```

The second parameter is genuinely part of the function's signature: the
original never re-loads or restores r1, it simply passes it straight through.
A named local holding the pointer (`int (*f)(void *); f = ...; return f(p);`)
does not change the register choice; only the live second argument does.
