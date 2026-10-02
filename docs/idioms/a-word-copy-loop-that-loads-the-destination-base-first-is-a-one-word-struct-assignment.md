# A word copy loop that loads the destination base first is a one-word struct assignment

summary: in a Thumb loop `dst[k] = src[k]` over 32-bit cells, the image loads
the destination base before the source value and puts the value in the dying
source-base register. Plain `u32` arrays compile the value load first into a
fresh register, and no spelling of the subscripts (element pointers, named
locals, casts, `*(p + k)`, counter types, declaration order) moves it. Making
the cell a one-word struct (`typedef struct { u32 v; } Tile;`) and copying
whole elements is EXACT.

Found in: src/matched/ov/ov021_func_0218CD20.c (0x0218CD20)

The image (Thumb, 1.1p1 -O4,p), copy-back loop:

    ldr   r1, [sp, #0x1c]       ; buf
    lsls  r3, r0, #2
    ldr   r2, [r5, #0x1c]       ; m->tiles, loaded before the value
    ldr   r1, [r1, r3]          ; buf[k] into the dying base
    adds  r0, r0, #1
    str   r1, [r2, r3]

`m->tiles[k] = buf[k]` with `u32 *` on both sides gives `ldr r2, [r1, r3]`
then `ldr r1, [r5, #0x1c]`: same instructions, swapped registers and order.
With `Tile *tiles` and `Tile *buf` the struct assignment gives the image
order. The same change fixed a second loop in the function
(`buf[i * nw + j] = m->tiles[i * m->w + j]`), where the `u32` form copied
`m->w` before `muls` instead of consuming it (`muls r6, r4, r6`), shifting
the rest of the function by 2 bytes. A third loop that stores block words from
a plain `u32 *` into the same buffer is `buf[..].v = src[..]`; making that
source a `Tile *` too adds pressure (bw spilled, 456 bytes).

Note: only the struct form with index `i * m->w + j` is EXACT; with
`m->w * i + j` the struct copy also blows the colouring. When a word-copy loop
has the right instructions but rigid load order or colours, try one-word
struct elements before register-level levers.
