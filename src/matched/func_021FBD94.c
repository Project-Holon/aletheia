/*
 * function: func_021FBD94
 * address:  0x021FBD94
 * packet:   pkt_021FBD94
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FAB70  0x021FAB70  thumb  ov135
 *   func_021F4FF4  0x021F4FF4  thumb  ov135
 *   g_02203216  0x02203216  data  ov135
 *   g_02203217  0x02203217  data  ov135

 * Reset, re-arm the 6 frame, then index the two parallel stride-2 tables from the cursor at +0x44.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_021FAB70(u8 *p);
extern void func_021F4FF4(u32 v, u32 a, u32 b);
extern u32 func_0204B878(u32 v, u32 k);
extern u8 g_02203216[];
extern u8 g_02203217[];

int func_021FBD94(u8 *p)
{
    u32 i;

    *(u32 *)(p + 0x44) = 0;
    func_021FAB70(p);
    func_0204B878(*(u32 *)(p + 8), 6);
    i = *(u32 *)(p + 0x44);
    func_021F4FF4(*(u32 *)(p + 8), g_02203216[i * 2], g_02203217[i * 2]);
    *(u32 *)(p + 0x48) = 1;
    *(u32 *)(p + 0x4c) = 0x22;
    return -1;
}
