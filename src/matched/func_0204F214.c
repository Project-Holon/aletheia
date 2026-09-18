/*
 * function: func_0204F214
 * address:  0x0204F214
 * packet:   pkt_0204F150
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_020A8144      0x020A8144  data
 *   g_020A814C      0x020A814C  data
 *
 * The unguarded entry teardown: it runs the two function-pointer globals over
 * the entry's +0x20 and +0x24 words unconditionally (their addresses in the
 * pools are the two ABS32 relocations), then clears the entry and stamps 5
 * into +0x14.
 *
 * A different file from func_0204F1A0, which is the same body behind the
 * "entry is live" guard, and from func_0204F150, which does the same work
 * through two direct calls.  The three are consecutive in the image and call
 * 0x0204F5A8-free leaf helpers, so each stands alone.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void (*g_020A8144)(u32 v);
extern void (*g_020A814C)(u32 v);

void func_0204F214(u8 *a0, int i)
{
    u32 off = i * 0x28;

    g_020A8144(*(u32 *)(*(u32 *)(a0 + 4) + off + 0x20));
    g_020A814C(*(u32 *)(*(u32 *)(a0 + 4) + off + 0x24));
    *(u32 *)(*(u32 *)(a0 + 4) + off) = 0;
    *(u32 *)(*(u32 *)(a0 + 4) + off + 0x14) = 5;
}
