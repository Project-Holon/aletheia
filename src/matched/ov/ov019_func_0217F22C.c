/*
 * function: func_0217F22C
 * address: 0x0217F22C
 * packet: pkt_ov019_0217F22C
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02188C54 0x02188C54 thumb ov021
 *   func_02190BE4 0x02190BE4 thumb ov021
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 *func_02188C54(u32 a);
extern u32 *func_02190BE4(u16 *a, u32 b);
void func_0217F22C(u8 *p, u32 a)
{
    if (*(u32 **)(p + 0x2814) == 0) {
        *(u32 **)(p + 0x2814) = func_02190BE4(func_02188C54(a), 0);
    }
}
