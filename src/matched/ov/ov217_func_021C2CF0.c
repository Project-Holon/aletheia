/*
 * function: func_021C2CF0
 * address:  0x021C2CF0
 * packet:   pkt_ov217_021C2CF0
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02021F64  0x02021F64  thumb
 *   func_0209C2B0  0x0209C2B0  arm
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void func_02021F64(u32 a, u32 b, u32 c, u32 d, u32 e);
extern u32 func_0209C2B0(u32 a, u32 b);

void func_021C2CF0(void *p)
{
    u32 n = *(u32 *)((char *)p + 0x1c);
    u8 v;
    if (n < 0x14)
        v = (u8)func_0209C2B0(n * 7, 0x14);
    else
        v = 7;
    func_02021F64(*(u32 *)((char *)p + 0xc), *(u32 *)((char *)p + 8), *(u8 *)((char *)p + 0x10), v, *(u16 *)((char *)p + 0x12));
    (*(u32 *)((char *)p + 0x1c))++;
}
