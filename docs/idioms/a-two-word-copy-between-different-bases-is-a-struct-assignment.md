# A two-word copy between different bases is a struct assignment

summary: Two loads into r2/r0 then two stores is an 8-byte struct assignment, not two field assignments; two locals hoist the loads but allocate the registers the wrong way round.

Found in: src/matched/ov072_func_021BA69C.c (0x021BA69C), also 0x021BB190, 0x021CDD94.

The original shape is

```
ldr r2, [r0, #0x10]      ; first source word
ldr r0, [r0, #0x14]      ; second source word, base register reused
str r2, [r1]             ; first destination word
str r0, [r1, #4]         ; second destination word
bx lr
```

The obvious C

```c
void f(int *p, int *o)
{
    int a = p[4];
    int b = p[5];
    o[0] = a;
    o[1] = b;
}
```

does hoist both loads (they are register copies), but the register allocator
gives the **first-stored** value `r0` and the second `r2`, so the object comes
out `ldr r2,[r0,#0x14]; ldr r0,[r0,#0x10]; str r0,[r1]; str r2,[r1,#4]` — a
4-byte DIFF. Swapping the stores only swaps the mismatch.

The source was an aggregate copy:

```c
typedef struct { int a; int b; } S;
void f(char *p, int *o)
{
    *(S *)o = *(S *)(p + 0x10);
}
```

which the compiler emits as exactly the original: it hoists both loads, keeps
the first destination word in `r2`, and reuses the dead base register `r0` for
the second. The same tell appears whenever the source and destination bases
differ and the copy is two words; above the unroll threshold it becomes the
`ldm`/`stm` loop of `big-struct-assignment-is-an-ldm-stm-loop.md`.
