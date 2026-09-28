/*
 * function: func_021FFEB4
 * address:  0x021FFEB4
 * packet:   pkt_021FFEB4
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_02203E58  0x02203E58  data  ov135

 * State-table dispatch through the table at 0x02203E58.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void *g_02203E58[];

void func_021FFEB4(u8 *p)
{
    ((void (*)(u8 *))g_02203E58[*(u32 *)(p + 0x28)])(p);
}
