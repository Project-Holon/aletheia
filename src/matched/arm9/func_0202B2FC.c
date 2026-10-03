/*
 * function: func_0202B2FC
 * address:  0x0202B2FC
 * packet:   pkt_0202B2FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocker func_0202B3A0.c is now a manifest entry (matched class)
 *
 * Builds a table node: a count byte is fetched from func_02049030, then that
 * many 0x1c-byte records are allocated and each one formatted in place.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0202B2FC.c \
 *       --func func_0202B2FC --addr 0x0202B2FC --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_02049030(u32 a);
extern void   func_02048F74(u8 *dst, u32 a, u32 b, u32 c, u32 d);

u8 *func_0202B2FC(u32 heapId)
{
    u32 i;
    u8 *p = (u8 *)func_02030734(heapId, 8, 0, (const void *)0x020A7718, 0x77);

    p[0] = (u8)func_02049030(0x92);
    *(u32 *)(p + 4) = (u32)func_02030734(heapId, 0x1c * p[0], 0,
                                         (const void *)0x020A7718, 0x79);

    for (i = 0; (int)i < (int)p[0]; i++) {
        func_02048F74((u8 *)(*(u32 *)(p + 4) + i * 0x1c), 0x92, i, 0, 0x1c);
    }
    return p;
}
