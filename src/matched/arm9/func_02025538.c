/*
 * function: func_02025538
 * address:  0x02025538
 * packet:   pkt_02025518
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734   0x02030734  arm
 *   func_020490F4   0x020490F4  arm
 *   g_020A7494      0x020A7494  data
 *
 * Allocate the 0x18-byte header for one 2-D tile set (tag 0x73), record the
 * row count and the pixel base, seed the three column cursors with -1 and
 * allocate the descriptor buffer through func_020490F4 with the palette field
 * forced to a 0x8000-based value.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02025538.c \
 *       --func func_02025538 --addr 0x02025538 --cc 1.1p1 --thumb
 */
#include "../include/Obj08785.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_02030734(u32 a0, u32 a1, int clear, const char *site, u16 tag);
extern void *func_020490F4(unsigned int id, u16 heap);
extern u32   g_020A7494[];

void *func_02025538(u32 a0, void *a1)
{
    u8 *p;
    int i;

    p = func_02030734(a0, 0x18, 1, (const char *)g_020A7494, 0x73);
    ((struct Obj08785 *)p)->f4 = a0;
    ((struct Obj08785 *)p)->f0 = a1;
    for (i = 0; i < 3; i++) {
        *(u32 *)(p + 0xc + i * 4) = -1;
    }
    ((struct Obj08785 *)p)->f8 = func_020490F4(0x33, (a0 & 0x7fff) | 0x8000);
    return p;
}
