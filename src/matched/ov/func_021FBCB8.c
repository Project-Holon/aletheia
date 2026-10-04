/*
 * function: func_021FBCB8
 * address:  0x021FBCB8
 * packet:   pkt_021FBCB8
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FAAD4  0x021FAAD4  thumb  ov135
 *   func_021F4FF4  0x021F4FF4  thumb  ov135
 *   g_0220320E  0x0220320E  data  ov135
 *   g_0220320F  0x0220320F  data  ov135

 * Reset, re-arm the 6 frame, then index the two parallel stride-2 tables from the cursor at +0x44.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_021FAAD4(u8 *p);
extern void func_021F4FF4(u32 v, u32 a, u32 b);
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);
extern u8 g_0220320E[];
extern u8 g_0220320F[];

int func_021FBCB8(u8 *p)
{
    u32 i;

    *(u32 *)(p + 0x44) = 0;
    func_021FAAD4(p);
    func_0204B878((struct Obj *)(*(u32 *)(p + 8)), 6);
    i = *(u32 *)(p + 0x44);
    func_021F4FF4(*(u32 *)(p + 8), g_0220320E[i * 2], g_0220320F[i * 2]);
    *(u32 *)(p + 0x48) = 1;
    *(u32 *)(p + 0x4c) = 0x1f;
    return -1;
}
