/*
 * function: func_021C5924
 * address:  0x021C5924
 * packet:   pkt_ov136_021C5924
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C5924 0x021C5924 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_020457B0 0x020457B0 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void *func_02045B38(u32 a, u32 b, u32 c, u32 d);
extern void *func_0201EC64(u32 a);
extern void *func_020457B0(u32 a, u32 b);
void func_021C5924(u8 *p)
{
    *(void **)(p + 0x1D0) = func_02045B38(0, 2, 0x3b, 0x66);
    *(void **)(p + 0x1D4) = func_0201EC64(0x66);
    *(void **)(p + 0x1D8) = func_020457B0(0x400, 0x66);
}
