/*
 * function: func_0204FE94
 * address:  0x0204FE94
 * packet:   pkt_0204FE94
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02030734     0x02030734  arm
 *   func_0204EBD4     0x0204EBD4  arm
 *   func_02033C00     0x02033C00  arm
 *   func_02050088     0x02050088  arm
 *   func_020500B8     0x020500B8  arm
 *   sBillboardAct     0x020A7FB0  data
 *   gBillboardActTpl  0x020A155C  data  a4
 *
 * The billboard_act.c system constructor, and the function that NAMES the
 * family: its __FILE__ word at 0x0204FFF4 is 0x020A7FB0, and
 * layout/file_anchors.txt fixes the string there as "billboard_act.c" (the NUL
 * of "billboard.c" at 0x020A7FAF is what pins its start).  Three allocations,
 * at source lines 94, 119 and 123, monotone in address -- the second,
 * independent check that this is one original translation unit.
 *
 * Allocate the 0x24-byte system object, stamp in the caller's heap id, the
 * two counts and the mode word, build the sub-board by copying a 28-byte
 * template out of rodata onto the stack and overwriting its first two
 * halfwords with the two counts, then allocate the two parallel arrays (the
 * count0 * 8 slot array and the count1 * 0x28 entry array) with their two
 * index pools, and finally run the per-element initialisers over both.
 *
 * Three shapes are load-bearing:
 *
 *   - The 28-byte template is ONE aggregate assignment from a rodata object
 *     into a `struct Blob28` LOCAL, which mwcc expands to a 16-byte ldm/stm
 *     pair with write-back plus a 12-byte pair without, reusing the bases the
 *     write-back left in sl and sb (the same expansion as the sibling
 *     constructor func_0204EBD4, src/matched/func_0204EBD4.c).  A byte array
 *     or a memcpy compiles to a copy loop instead.
 *   - The two halfword patches are written through casts ONTO the local
 *     (`*(u16 *)&tmp`), re-reading h->f10 and h->f1C rather than reusing the
 *     incoming parameters: the image issues `ldrh r2, [r6, #0x10]` and
 *     `ldrh r2, [r6, #0x1c]` between the stm and the call, which the
 *     parameters would not produce.
 *   - Both element loops use SEPARATE counters (`i` and `j`) and re-read
 *     their bound from the object at the bottom of the loop; the compare is
 *     signed (`blt`) on the promoted u16, so the counters are plain `int`.
 *
 * The template at 0x020A155C is attested `sole-ref` (its only referrer image
 * wide is this function's own pool word at 0x0204FFF8); the file string is
 * attested `string`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204FE94.c \
 *       --func func_0204FE94 --addr 0x0204FE94 --cc 1.1p1 --arm
 *   EXACT, 360 bytes, 10 relocation sites, all resolved.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Blob28 { u32 w[7]; };

struct Sys {
    u16   f00;
    u16   f02;
    void *f04;
    u32   f08;
    void *f0C;
    u16   f10;
    u16   f12;
    void *f14;
    void *f18;
    u16   f1C;
    u16   f1E;
    void *f20;
};

struct AreaMan;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_0204EBD4(u8 *src, void *heap);
extern struct AreaMan *func_02033C00(u32 size, u32 heap);
extern void  func_02050088(void *p);
extern void  func_020500B8(void *p);
extern const char sBillboardAct[];
extern const struct Blob28 gBillboardActTpl;

void *func_0204FE94(u16 a0, u16 a1, u32 a2, int heap)
{
    const char *file = sBillboardAct;
    struct Sys *h;
    struct Blob28 tmp;
    int i;
    int j;

    h = (struct Sys *)func_02030734(heap, 0x24, 1, file, 94);
    h->f00 = (u16)heap;
    h->f08 = a2;
    h->f10 = a0;
    h->f1C = a1;

    tmp = gBillboardActTpl;
    *(u16 *)&tmp = h->f10;
    *((u16 *)&tmp + 1) = h->f1C;
    h->f04 = func_0204EBD4((u8 *)(&tmp), (void *)heap);

    h->f0C = func_02030734(heap, h->f10 * 8, 1, file, 119);
    h->f14 = func_02033C00(h->f10, heap);
    h->f18 = func_02030734(heap, h->f1C * 0x28, 1, file, 123);
    h->f20 = func_02033C00(h->f1C, heap);

    for (i = 0; i < h->f10; i++) {
        func_02050088((u8 *)h->f0C + i * 8);
    }
    for (j = 0; j < h->f1C; j++) {
        func_020500B8((u8 *)h->f18 + j * 0x28);
    }
    return h;
}
