# A paired holder pointer formed before allocation keeps its destination live

summary: when an allocation result is stored in the second pointer of a grid/bitmap pair, form a pointer to the pair before the allocation and store through its bitmap member. This keeps the destination address live across the call and reproduces the image's callee-saved register allocation.

Found in: `src/matched/ov/ov180_func_021B7814.c` (204 bytes) and `src/matched/ov/ov180_func_021B79F4.c` (532 bytes), Thumb, dsi/1.1p1 `-O4,p -lang c99`.

The original constructs adjacent grid and bitmap pointers. Its bitmap allocation result goes to the pair's second word, then becomes the bitmap field of the grid-construction parameters. Spell the pair and its destination explicitly:

```c
typedef struct { struct Grid *grid; struct Bmp *bmp; } Holder;
Holder *h;
h=(Holder *)(p+0x9120);
h->bmp=func_02043678(22,2,32,141);
d.bmp=h->bmp;
```

In `021B7814`, the direct raw-offset store and reload compiled to 196 instead of 204 bytes with 167 differing bytes. Forming `h` before the allocation and using its member gave EXACT 204. The same form at `p+0x9130` and `p+0x9138` in `021B79F4` gave EXACT 532 on its first compile. The original stores establish the two-pointer pair; the holder describes that observed layout rather than an inferred array bound.
