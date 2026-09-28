/*
 * function: func_0202C9B4
 * address:  0x0202C9B4
 * packet:   pkt_0202C9B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * TU: bgwinfrm.c (__FILE__ 0x020A7790, lines 0x56 and 0x5d).
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   bgwinfrm_File  0x020A7790  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern const char bgwinfrm_File[];
extern void *func_02030734(u32 heap, u32 size, u32 clear, const char *file,
                           u32 line);

struct BgWinFrm {
    void *buf;       /* 0x00 */
    u16   h4;        /* 0x04 */
    u16   lo : 15;   /* 0x06 */
    u16   hi : 1;    /* 0x06 */
    u32   w8;        /* 0x08 */
};

struct BgWinFrm *func_0202C9B4(u32 a0, u32 a1, u32 heap)
{
    struct BgWinFrm *p;

    p = func_02030734(heap, sizeof(struct BgWinFrm), 0, bgwinfrm_File, 0x56);
    p->h4 = a1;
    p->w8 = heap;
    p->lo = a0;
    p->hi = 0;
    p->buf = func_02030734(heap, a1 << 4, 1, bgwinfrm_File, 0x5d);

    return p;
}
