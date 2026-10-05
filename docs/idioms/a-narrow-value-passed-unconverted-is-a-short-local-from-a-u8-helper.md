# A narrow value passed unconverted is a short local from a u8 helper

summary: when the image spills a centred x (masked with `lsls #0x17; lsrs #0x18` after a signed /2),
passes it to a callee with an s16 x and does NOT emit `lsls/asrs #0x10`, and reloads it below
the outgoing stack stores, the source has a static inline helper that returns u8. The result
goes into a `short` local. The helper's u8 return value is known to fit in s16, so the s16
conversion is removed. A `short` local (not a u8 local) keeps its declaration slot.

Found in: src/matched/ov/ov198_func_0220DA6C.c (0x0220DA6C, ov198, Thumb), wave D9r. Thirteen
earlier lanes left it at DIFF 153 to 160.

```c
static inline u8 center_x(int w)
{
    return w / 2;
}

static inline void put(u8 *p, void *win, void *sel, short x, u32 y, void *h, u16 color)
{
    func_0201C724(win, func_02045770(sel), x, y, h, *(u32 *)(*(u8 **)p + 0xc), color);
    *(u8 *)(p + 0x1F74) = 1;           /* the dirty flag is part of the helper */
}
...
u8 t;
short half;
...
half = center_x(func_02045738(o) * 8 - t - a - b);
put(p, *(void **)(p + 0x1EAC), *(void **)(p + 0x1F70), half, 7, vec, 0x3DC0);
```

Measured on that function (bytes that differ):
- int half with the plain expression: 153. u8 t and u8 half with no helper: 274 (bigger frame).
- u8 t, u8 half, center_x helper, int put x: 147 (frame and size now right).
- The flag store moved into put: 37. mwcc keeps the 0x1EAC base in r5 across the msg2 arms and
  derives 0x1F74 from it, as in the image. With the store after each call, the base is reloaded.
- put x and callee x as short: 9. Only the slot of half was wrong (a u8 half takes the lowest slot).
- `short half`: EXACT. A u16 or int half brings the conversion back (214).

Check order: first the helper (the conversion), then the stores that follow each call (do they
belong in the helper), then the local's width for its stack slot.
