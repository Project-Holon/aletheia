# An RGB555 lerp in a loop is a static inline with u16 colour parameters

summary: when a loop blends two RGB555 colours per element (mask 0x1F, 0x3E0,
0x7C00, `(d - c) * t >> 12` per channel) and the original keeps the element
offset (`i*2` or the record pointer) in a callee-saved register while it
spills the shifted blue result, write the per-element blend as a
`static inline` helper with `u16` colour parameters and call it once per
element. Written flat in the loop body, the offset is spilled and the blue
result stays in a register; no declaration order or extraction order moves it.

Found in: `src/matched/ov/ov110_func_021BD348.c`,
`src/matched/ov/ov110_func_021C088C.c` (same body as the non-loop
`src/matched/ov/ov105_func_021B8734.c`).

The spelling:

```c
static inline void lerp(u16 *p, int n, u16 a, u16 b)
{
 u8 r,g,blue; int dr,dg,db;
 g=(a&0x3E0)>>5;
 r=a&31;
 blue=(a&0x7C00)>>10;
 db=((u8)((b&0x7C00)>>10)-blue)*n>>12;
 dr=((u8)(b&31)-r)*n>>12;
 dg=((u8)((b&0x3E0)>>5)-g)*n>>12;
 *p=(u8)(r+dr)|((u8)(g+dg)<<5)|((u8)(blue+db)<<10);
}
```

Tell-tale: the original computes green first (`ands 0x3E0; lsls 0x13;
lsrs 0x18`), then red, then blue, and hoists two separate copies of 0x7C00
(one per colour) above the loop.
