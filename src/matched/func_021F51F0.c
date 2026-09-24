/*
 * function: func_021F51F0
 * address:  0x021F51F0
 * packet:   pkt_021F51F0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_02203B0C  0x02203B0C  data  ov135

 * State-table dispatch through the table at 0x02203B0C.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void *g_02203B0C[];

void func_021F51F0(u8 *p)
{
    ((void (*)(u8 *))g_02203B0C[*(u32 *)(p + 0x28)])(p);
}
