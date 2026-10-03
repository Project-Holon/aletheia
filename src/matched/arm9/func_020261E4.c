/*
 * function: func_020261E4
 * address:  0x020261E4
 * packet:   pkt_020261E4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734   0x02030734  arm
 *   func_02012944   0x02012944  thumb
 *   func_020457B0   0x020457B0  arm
 *   func_02008500   0x02008500  thumb
 *   g_020A74B0      0x020A74B0  data
 *
 * Allocate the 0x88-byte sprite for a1 (tag 0xe0), keep a1 as its first word,
 * then attach six sub-buffers: each starts at +0x3c with a 0xc stride, gets
 * two 8-byte allocations out of the a0 heap and registers both with the
 * resource handle func_02012944 returned for a1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020261E4.c \
 *       --func func_020261E4 --addr 0x020261E4 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct U16Vec;
extern u8   *func_02012944(void *a0);
extern struct U16Vec *func_020457B0(u32 a0, u32 a1);
extern void  func_02008500(void *a0, void *a1);
extern u32   g_020A74B0[];

void *func_020261E4(u32 a0, void *a1)
{
    int i;
    u8 *p;
    u8 *base;
    u8 *e;
    u8 *q;

    p = func_02030734(a0, 0x88, 1, (const char *)g_020A74B0, 0xe0);
    *(void **)p = a1;
    q = func_02012944(a1);
    base = p + 0x3c;
    for (i = 0; i < 6; i++) {
        e = base + i * 0xc;
        *(struct U16Vec **)(e + 4) = func_020457B0(8, a0);
        *(struct U16Vec **)(e + 8) = func_020457B0(8, a0);
        func_02008500(q, *(struct U16Vec **)(e + 4));
        func_02008500(q, *(struct U16Vec **)(e + 8));
    }
    return p;
}
