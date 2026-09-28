# An int local passed through a (u32 *) cast to an inline getter keeps its stack slot

summary: when the original reserves `sub sp, sp, #8` for two int locals (DWARF `[fb+0]`,
`[fb+4]`) that are never read from the stack, their addresses went into an inlined
`G2_GetOBJPosition(oam, (u32 *)&x, (u32 *)&y)`; 1.1p1 keeps the frame only when the
address reaches the u32-pointer parameters through a cast, and promotes both with no frame
when the inline takes `int *`.

Found in: src/matched/ov016_func_021BDCAC.c (0x021BDCAC, taskStart0 in keyboard.o); also
taskStart1..3, taskEnd0..4 and src/matched/ov016_func_021C98E4.c (setOffset in scenesetlist.o)

The original of taskStart0 is the whole body plus an unused 8-byte frame:

```
push {r3, r4, r5, lr}
sub sp, sp, #8
ldr r4, [pc, #0x60]       ; MemKb
...
ldr r0, [r0]              ; key[0]->attr01
and r0, r0, #0xff         ; y
sub r2, r0, #0xc
```

Declaring `int x, y;` and reading the attribute directly, or through an inline getter whose
parameters are `int *`, gives the same instructions without `sub sp` / `add sp` (12 bytes
short). The SDK getter's parameters are `u32 *`, so the vendor passes the int locals with a
cast, and that cast is what keeps the slots:

```c
static inline void G2_GetOBJPosition(const GXOamAttr *oam, unsigned long *x, unsigned long *y)
{
    *x = (oam->attr01 & 0x01FF0000) >> 16;
    *y = (oam->attr01 & 0x000000FF) >> 0;
}

int x, y;
G2_GetOBJPosition(MemKb->key[0], (unsigned long *)&x, (unsigned long *)&y);
y -= 12;
```

The same spelling closed scenesetlist.o's setOffset, whose 8-byte frame had been the
standing residue of an earlier lane (permuter flat).
