/*
 * function: func_0202BEEC
 * address:  0x0202BEEC
 * packet:   pkt_0202BEDC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sibling of func_0202B958: builds a selector out of the caller's id, takes
 * a handle from func_020490F4, sizes the record table from func_0204961C's
 * count and allocates it with func_02030734, then reads every 8-byte record
 * into the handle with func_0204944C and releases it with func_02049238.
 * The record table is at +8 and the count byte at +4 rather than the +0x264
 * and +0x268 func_0202B958 uses, and the count here stays a signed int (the
 * guard is `ble`), which is the whole difference between the two.
 *
 * The five-argument window read is the same call func_0204944C makes from
 * its other sites; the buffer is its own stack word because the argument
 * count already spends r0-r3.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202BEEC.c \
 *       --func func_0202BEEC --addr 0x0202BEEC --thumb --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_020490F4(unsigned int id, u16 heap);
extern int    func_0204961C(void *handle);
extern void  *func_02030734(u32 heapId, u32 size, u32 zero,
                            const void *file, u32 line);
extern void   func_0204944C(void *handle, u32 idx, u32 a2, u32 len,
                            void *buf);
extern void   func_02049238(void *handle);

void func_0202BEEC(u8 *p, u32 id)
{
    void *h = func_020490F4(0x88, (id & 0x7fff) | 0x8000);
    int   n = func_0204961C(h);
    int   i;

    p[4] = (u8)n;
    *(u32 *)(p + 8) = (u32)func_02030734(id, (u32)(n << 3), 0,
                                         (const void *)0x020A7748, 0xd2);

    for (i = 0; i < n; i++) {
        func_0204944C(h, (u32)i, 0, 8,
                      (void *)(*(u32 *)(p + 8) + ((u32)i << 3)));
    }
    func_02049238(h);
}
