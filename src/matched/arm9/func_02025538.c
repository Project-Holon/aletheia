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

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_02030734(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);
extern u32   func_020490F4(u32 a0, u32 a1);
extern u32   g_020A7494[];

void *func_02025538(u32 a0, u32 a1)
{
    u8 *p;
    int i;

    p = func_02030734(a0, 0x18, 1, (u32)g_020A7494, 0x73);
    *(u16 *)(p + 4) = a0;
    *(u32 *)p = a1;
    for (i = 0; i < 3; i++) {
        *(u32 *)(p + 0xc + i * 4) = -1;
    }
    *(u32 *)(p + 8) = func_020490F4(0x33, (u16)((a0 & 0x7fff) | 0x8000));
    return p;
}
