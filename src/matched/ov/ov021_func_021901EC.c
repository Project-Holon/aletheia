/*
 * function: func_021901EC
 * address:  0x021901EC
 * packet:   pkt_ov021_021901EC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201C440  0x0201C440  thumb
 *   func_021931F4  0x021931F4  thumb
 *   d_021DDA50  0x021DDA50  data  ov021  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern const char d_021DDA50[];
extern u32 func_0201D7EC(int a, int b, int c, int d, u16 heap);
extern u32 func_0201C440(u16 heap);
extern u32 func_0203101C(u16 a, u16 b, int c, int d);
extern void func_021931F4(void *p);
extern int func_0204A1BC(int a0, int a1, int a2, int a3);
extern void func_02062A4C(u32 a, void *b);

u8 *func_021901EC(u16 heap, u32 b)
{
    u8 *o = func_02030734(heap, 0x17c, 1, d_021DDA50, 0x1a4);
    *(u16 *)o = heap;
    *(u16 *)(o + 2) = 0xff;
    *(u16 *)(o + 4) = 0xff;
    *(u32 *)(o + 0x168) = b;
    *(u32 *)(o + 8) = func_0201D7EC(0x17, 0, 0, 0, *(u16 *)o);
    *(u32 *)(o + 0xc) = func_0201C440(*(u16 *)o);
    *(u32 *)(o + 0x164) = func_0203101C(*(u16 *)o, *(u16 *)o, 1, 4);
    func_021931F4(o + 0x160);
    *(u32 *)(o + 0x174) = func_0204A1BC(5, 0xc, 0, heap);
    func_02062A4C(*(u32 *)(o + 0x174), o + 0x178);
    return o;
}
