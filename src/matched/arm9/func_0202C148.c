/*
 * function: func_0202C148
 * address:  0x0202C148
 * packet:   pkt_0202C148
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Build the unit table of a block: n = func_02049030(0x93) members, the
 * count stored at +4, an n-word pointer array allocated from heapId at +8
 * (file word 0x020A7758, line 0x13A), then one unit per slot from
 * func_0202C2EC(heapId), initialised by func_0202C318(unit, i, heapId).
 *
 * What closed it (wave 17, from 17 out): heapId is a u16 PARAMETER.  With
 * a u32 heapId 1.1p1 hoists the heapId reload and the file pool word above
 * the `strb` of the count; narrowed, its home store `str r1, [sp, #4]`
 * sits at the front of the prologue and the image's order falls out
 * (docs/idioms/a-narrow-parameter-pins-its-home-store-to-the-front-of-the-prologue.md).
 * The callee prototypes take the same u16 heap id.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202C148.c \
 *       --func func_0202C148 --addr 0x0202C148 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_02049030(u32 a);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u8   *func_0202C2EC(u16 heapId);
extern void  func_0202C318(u8 *unit, u32 i, u16 heapId);

void func_0202C148(u8 *p, u16 heapId)
{
    u32 i;
    int n;

    n = func_02049030(0x93);
    p[4] = (u8)n;
    *(u32 *)(p + 8) = (u32)func_02030734(heapId, (u32)(n << 2), 0,
                                         (const void *)0x020A7758, 0x13a);
    for (i = 0; (int)i < n; i++) {
        u8 *r = func_0202C2EC(heapId);
        func_0202C318(r, i, heapId);
        *(u32 *)(*(u32 *)(p + 8) + (i << 2)) = (u32)r;
    }
}
