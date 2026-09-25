# A guard whose take branch is the function exit leaves a bare cmp before bx lr

summary: When a guard's body is the function's own return, the compiler folds
the guard's branch onto the trailing `bx lr`; the condition's `cmp` survives
with no branch after it. An equivalent value-returning ternary drops that
`cmp` and comes out two bytes short.

Found in: src/matched/func_021B79E4.c (0x021B79E4)

The image is twelve bytes:

```
021B79E4  ldrh r1, [r0, #2]
021B79E6  cmp  r1, #0
021B79E8  beq  021B79EE
021B79EA  ldrh r0, [r0, #4]
021B79EC  cmp  r0, #0
021B79EE  bx   lr
```

The second `cmp` has no branch after it: its take branch *is* the fall-through
`bx lr`, so the compiler emitted the comparison and nothing else. What produces
this is two early returns whose bodies are empty, i.e. the guard is the exit:

```c
void func_021B79E4(unsigned short *p)
{
    if (p[1] == 0)
        return;
    if (p[2])
        return;
}
```

The obvious-looking reconstruction of the same read is a value-returning
ternary, and it is wrong by two bytes:

```c
int func_021B79E4(unsigned short *p) { return p[1] ? p[2] : (int)p; }
```

That emits the first load/compare/branch and then `ldrh r0` immediately before
`bx lr` (ten bytes); there is no exit block for the second condition to test, so
no `cmp r0, #0` is generated. The dead-looking `cmp` is the tell that the
function returned `void` through guards rather than returning a value.
