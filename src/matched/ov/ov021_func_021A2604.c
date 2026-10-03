/*
 * function: func_021A2604
 * address:  0x021A2604
 * packet:   pkt_ov021_021A2604
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02005C64  0x02005C64  thumb
 *   func_02028ACC  0x02028ACC  thumb
 *   func_020061F0  0x020061F0  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

int func_02005C64(void);
void func_02028ACC(u32 x, int a, int b);
void func_020061F0(u32 a, u32 b);

void func_021A2604(u8 *p, int a, int b)
{
    if (func_02005C64() == 0) {
        if (*(u32 *)(p + 0x48) != 0)
            func_02028ACC(*(u32 *)(p + 0xC), a, b);
        else
            func_020061F0(a, b);
    }
}
