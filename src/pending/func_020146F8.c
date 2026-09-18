/*
 * function: func_020146F8
 * address:  0x020146F8
 * packet:   pkt_02014628
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * Verified with:
 *   python tools/match.py one --src src/pending/func_020146F8.c \
 *       --func func_020146F8 --addr 0x020146F8 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

extern void *sub_020122C0(void *owner, void *a, void *b, u32 size);
extern u32  *sub_020124E8(void *d);
extern void  func_02014628(void);

void *func_020146F8(void *a0, u32 a1, u32 a2, u32 a3, u32 a5)
{
    void *d = sub_020122C0(a0, 0, func_02014628, 0x14);
    u32 *p = sub_020124E8(d);

    p[0] = (u32)a0;
    p[1] = a1;
    p[2] = a2;
    p[3] = a3;
    p[4] = a5;
    return d;
}
