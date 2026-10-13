/*
 * function: func_02028590
 * address:  0x02028590
 * packet:   pkt_02028590
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  020285A4 label
 * blocker:  0209FD10 literal
 *
 * symbols:
 *   _KeyCursorDefaultPixels  0x0209FD10  data
 *   APP_KEYCURSOR_Create  0x020285A4  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


extern char _KeyCursorDefaultPixels[];

void func_02028590(u32 a0, u32 a1, u32 a2, u16 a3)
{
    APP_KEYCURSOR_Create(a0, a1, a2, a3, _KeyCursorDefaultPixels);
}
