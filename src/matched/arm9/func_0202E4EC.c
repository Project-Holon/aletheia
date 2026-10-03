/*
 * function: func_0202E4EC
 * address:  0x0202E4EC
 * packet:   pkt_0202E4EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Levers that decided this one:
 *   - the heap parameter must be u32 with an explicit (u16) cast at each use;
 *     declared u16 the allocator kept the wrong value in r7 and the frame
 *     came out 88 bytes instead of 96.
 *   - `int i;` is declared BEFORE the result pointer, which is what puts the
 *     loop counter in r4 and the result in r5
 *     (docs/idioms/declaration-order-decides-which-register-a-local-gets.md).
 *   - the struct has a dead u32 at +0x18 between items[4] and w1c, so the
 *     allocator's size argument is 0x24, not 0x20.
 *
 * TU: codein_param.c (__FILE__ 0x020A77D0, line 0x37).
 *
 * symbols:
 *   func_02030734    0x02030734  arm
 *   func_020457B0    0x020457B0  arm
 *   codein_param_File 0x020A77D0  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern const char codein_param_File[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020457B0(u32 n, u16 heap);

struct Param {
    u32 w0;        /* 0x00 */
    u32 w4;        /* 0x04 */
    u32 items[4];  /* 0x08 */
    u32 w18;       /* 0x18 */
    u32 w1c;       /* 0x1c */
    u32 w20;       /* 0x20 */
};

struct Param *func_0202E4EC(u32 heap, u32 a1, u32 a2, u32 a3, u32 *src)
{
    int i;
    struct Param *p;

    p = func_02030734((u16)heap, sizeof(struct Param), 0, codein_param_File, 0x37);
    p->w0 = a1;
    p->w4 = a3;
    p->w20 = func_020457B0(a3 + 1, (u16)heap);
    p->w1c = a2;
    for (i = 0; i < 3; i++) {
        p->items[i] = src[i];
    }
    p->items[i] = src[i - 1];

    return p;
}
