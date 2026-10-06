/*
 * function: func_021A569C
 * address:  0x021A569C
 * packet:   pkt_ov021_021A569C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A5264  0x021A5264  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021A55DC  0x021A55DC  thumb  ov021
 */

typedef unsigned char  u8;
int func_021A5264(u8 *a, void *b, unsigned int c, int *d);
typedef unsigned short u16;
typedef unsigned int   u32;
u16 func_021AB0F0(u32 attr);
int func_021A55DC(int x);

int func_021A569C(u8 *a, void *b, int c, int *d)
{
    int r = func_021A5264(a, b, c, d);

    if (func_021A55DC(func_021AB0F0(*d)) == 1)
        r |= 0x100;
    return r;
}
