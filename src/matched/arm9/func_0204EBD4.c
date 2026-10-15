/*
 * function: BILLBOARD_Create
 * address:  0x0204EBD4
 * packet:   pkt_0204EBD4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * billboard.c's board constructor; the only allocation site in the image
 * whose __FILE__ word is 0x020A7FA4 ("billboard.c", the NUL of
 * "battle_disp.c" at 0x020A7FA3 fixes where it starts).  Caller is
 * func_0204FF18.  Three func_02030734 calls at lines 153, 159 and 161: the
 * 0x3c-byte board, its count0 * 0x28 record array and its count1 * 0x1c
 * element array.
 *
 * The whole payload is ONE 28-byte aggregate assignment at +0x0c, which mwcc
 * expands to a 16-byte ldm/stm pair with write-back followed by a 12-byte
 * pair without: the second pair reuses the bases the write-back left in r8
 * (source + 16) and sb (dest + 0x10), so the three bytes of `add` that a
 * spelled-out second copy costs are absent from the original.  The source
 * must be a 4-aligned aggregate; a struct of bytes compiles to a byte-copy
 * loop instead.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   sBillboard     0x020A7FA4  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Blob28 { u32 w[7]; };   /* 28 bytes, align 4 -> ldm/stm 16 + 12 */

struct Board {
    u16 id;             /* 0x00 */
    u16 pad0;
    u32 ptr0;           /* 0x04 */
    u32 ptr1;           /* 0x08 */
    u16 count0;         /* 0x0c */
    u16 count1;         /* 0x0e */
    u8  blob[0x18];     /* 0x10 .. 0x27 */
    u32 a28;            /* 0x28 */
    u32 a2c;            /* 0x2c */
    u16 b30;            /* 0x30 */
    u16 b32;
    u16 b34;
    u16 b36;
    u16 b38;
};

struct BigElem { u32 f00; u32 f04; u32 f08; u32 f0c; u32 f10; u32 f14; u32 f18; u32 f1c; u32 f20; u32 f24; };  /* 0x28 */

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern const char sBillboard[];

void *BILLBOARD_Create(u8 *src, void *heap)
{
    struct Board *h;
    const char *file;
    int i;

    file = sBillboard;
    h = (struct Board *)func_02030734((int)heap, sizeof(struct Board), 1, file, 153);
    h->id = (u16)(int)heap;
    *(struct Blob28 *)((u8 *)h + 0x0c) = *(struct Blob28 *)src;
    h->ptr0 = (u32)func_02030734((int)heap, h->count0 * 0x28, 1, file, 159);
    h->ptr1 = (u32)func_02030734((int)heap, h->count1 * 0x1c, 1, file, 161);
    for (i = 0; i < h->count0; i++) {
        ((struct BigElem *)h->ptr0)[i].f00 = 0;
        ((struct BigElem *)h->ptr0)[i].f14 = 5;
    }
    for (i = 0; i < h->count1; i++) {
        u16 *q = (u16 *)(h->ptr1 + i * 0x1c);
        *q = (u16)((*q & ~0x3FFFu) | 0x3FFFu);
    }
    h->a2c = 0;
    h->b30 = 0;
    h->b32 = 0;
    h->b34 = 0;
    h->a28 = 0;
    h->b36 = 0;
    h->b38 = 0;
    return h;
}
