/*
 * function: func_021A25DC
 * address:  0x021A25DC
 * packet:   pkt_ov021_021A25DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02005C64  0x02005C64  thumb
 *   func_02028A7C  0x02028A7C  thumb
 *   func_020061E4  0x020061E4  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

int func_02005C64(void);
void func_02028A7C(u32 x, int a);
void func_020061E4(u32 a);

void func_021A25DC(u8 *p, int a)
{
    if (func_02005C64() == 0) {
        if (*(u32 *)(p + 0x48) != 0)
            func_02028A7C(*(u32 *)(p + 0xC), a);
        else
            func_020061E4(a);
    }
}
