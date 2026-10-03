/*
 * function: func_02156C00
 * address:  0x02156C00
 * packet:   pkt_ov009_02156C00
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_021A8264  0x021A8264  data  ov009  a4
 *   func_02156BD8  0x02156BD8  thumb  ov009
 *   func_0203D798  0x0203D798  arm
 *   func_0203D7C8  0x0203D7C8  arm
 *   func_021770EC  0x021770EC  arm  ov009
 *   d_021A1C60  0x021A1C60  data  ov009  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 *g_021A8264;
extern u8 d_021A1C60[];
extern void func_02156BD8(u32);
extern void *func_0203D798(void);
extern u32 func_0203D7C8(u32, u32, void *, u32);
extern void func_021770EC(u8, u32, u32);

void func_02156C00(u32 a)
{
    u8 *p = func_0203D798();
    func_02156BD8(a);
    if (*(u32 *)(g_021A8264 + a * 4 + 0x174) == 0) {
        u32 n = 0x1000;
        *(u32 *)(g_021A8264 + a * 4 + 0x174) =
            func_0203D7C8(*(u16 *)(p + 0x56), n, d_021A1C60, 0xb74);
        func_021770EC(a, *(u32 *)(g_021A8264 + a * 4 + 0x174), n);
    }
}
