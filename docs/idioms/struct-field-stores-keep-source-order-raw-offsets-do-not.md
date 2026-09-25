# Field stores through a struct type keep source order; raw pointer offsets get rescheduled

summary: two field stores at fixed offsets written through a typed struct keep their source order and the object base in r0, while the same stores spelled `*(int *)(p + n)` are reordered and the base register is freed for a later pool load.

Found in: src/matched/func_021D77F8.c (0x021D77F8)

The original loads the first byte, stores the fourth argument, and only then
increments and writes the bytes:

```
ldrb r4, [r0]
str  r3, [r0, #4]
movs r3, #0
adds r4, r4, #1
strb r4, [r0]
strb r3, [r0, #1]
strb r1, [r0, #2]
strb r2, [r0, #3]
```

Spelled with a raw pointer (`unsigned char *p; p[0] = p[0] + 1;
*(int *)(p + 4) = c; p[1] = 0; p[2] = a; p[3] = b;`) the scheduler hoists the
`p[2]` store and moves `str r3,[r0,#4]` after the increment, so the function
comes out DIFF.  Declaring the same layout as a struct with named members at the
same offsets reproduces the original byte for byte:

```c
struct hdr { unsigned char f0, f1, f2, f3; int f4; };
void f(struct hdr *p, unsigned char a, unsigned char b, int c)
{
    p->f0 = p->f0 + 1;
    p->f4 = c;
    p->f1 = 0;
    p->f2 = a;
    p->f3 = b;
}
```

When a raw-offset body schedules stores in an order the source does not call
for, retyping the block as a struct is worth one attempt before assuming a
compiler quirk.
