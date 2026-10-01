# A record array type multiplies a dying index into a fresh register

summary: when a Thumb leaf copies its index before multiplying by a record stride and folds the array header into field immediates, use an actual record array member. Raw integer address arithmetic and a pointer to stride-sized byte arrays multiply into the stride constant's register and omit the copy.

Found in: src/matched/ov/ov132_func_021FD3D8.c (0x021FD3D8), src/matched/ov/ov132_func_021FD3F0.c (0x021FD3F0).

The initialization loop at 0x021FC862..0x021FC93E proves four 48-byte records from object offset 0x60, with a word flag at record offset 4 and an allocated buffer pointer at 0x1C. The leaves write the flag and read the pointer:

```c
struct Record { int f0; int flag; char pad8[0x14]; char *data; char pad20[0x10]; };
struct Context { char pad0[0x60]; struct Record rec[4]; };
void *func_021FD3F0(long i, struct Context *p)
{
    p->rec[i].flag = 0;
    return p->rec[i].data;
}
```

This gives `movs r2,#0x30; adds r3,r0,#0; muls r3,r2,r3; movs r2,#0; adds r0,r1,r3; str r2,[r0,#0x64]; ldr r0,[r0,#0x7c]`. The array header is folded into the field immediates.

`*(int *)(p+i*0x30+0x64)` with an integer base and a matching buffer load is two instruction bytes shorter: it multiplies into r2 and advances the base in r1. A `char (*p)[0x30]` with integer-cast element addresses has the same wrong shape. The struct member spelling closes both the 22-byte setter and the 16-byte getter without extra uses of the index.
