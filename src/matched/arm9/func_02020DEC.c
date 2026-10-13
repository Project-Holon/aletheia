/*
 * unit:     no
 * address:  0x02020DEC
 * packet:   pkt_02020D5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: FILE_UTIL_OpenById
 *
 * symbols:
 *   func_0200575C  0x0200575C  thumb
 *   FS_InitFile  0x020788AC  arm
 *   FS_OpenFile  0x02078C18  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FILE_UTIL_OpenById.c \
 *       --func FILE_UTIL_OpenById --addr 0x02020DEC --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern void *func_0200575C(u32 x);
extern void  FS_InitFile(void *p);
extern void  FS_OpenFile(void *p, void *q);

void FILE_UTIL_OpenById(void *p, u32 x)
{
    void *q;

    q = func_0200575C(x);
    FS_InitFile(p);
    FS_OpenFile(p, q);
}
