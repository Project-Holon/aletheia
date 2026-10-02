/*
 * function: func_0202B958
 * address:  0x0202B958
 * packet:   pkt_0202B744
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocker  is now a manifest entry (matched class)
 *
 * Same list dance as func_0202BEEC, on a node whose record table sits at
 * 0x264 and whose record count at 0x268; the node's own u16 id supplies the
 * selector.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0202B958.c \
 *       --func func_0202B958 --addr 0x0202B958 --thumb --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void  *func_020490F4(u32 heapId, u16 sel);
extern u16    func_0204961C(void *obj);
extern void  *func_02030734(u32 heapId, u32 size, u32 zero,
                            const void *file, u32 line);
extern void   func_0204932C(void *h, u32 idx, void *src);
extern void   func_02049238(void *h);

void func_0202B958(u8 *p)
{
    u32  id = *(u16 *)p;
    void *h = func_020490F4(0xb9, (u16)((id & 0x7fff) | 0x8000));
    u8   n = (u8)func_0204961C(h);
    u32  i;

    p[0x268] = n;
    *(u32 *)(p + 0x264) = (u32)func_02030734(id, (u32)(n << 3), 0,
                                             (const void *)0x020A7738, 0x178);

    for (i = 0; i < (u32)n; i++) {
        func_0204932C(h, i, (void *)(*(u32 *)(p + 0x264) + (i << 3)));
    }
    func_02049238(h);
}
