/*
 * unit:     yes
 * function: func_06898E1C, func_06898E28, func_06898E38, func_06898E44
 * address:  0x06898E1C
 * packet:   pkt_ov095_06898E1C
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Handed extent 0x06898E0C (72 bytes) opens with a 16-byte `bx pc` veneer
 * to 0x021D70A8 (ARM linker stub, not compilable); the four functions after
 * it (0x06898E1C..0x06898E54) are this unit. 0x06898E1C and 0x06898E38 are
 * entries of the {key, fn} tables at 0x0689D6F0 / 0x0689D710.
 *
 * symbols:
 *   func_06898E54  0x06898E54  thumb  ov095
 *   d_0689D6F0     0x0689D6F0  data   ov095  a4
 *   d_0689D710     0x0689D710  data   ov095  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 d_0689D6F0[];
extern u8 d_0689D710[];
extern void func_06898E54(int a, int b, int c);

u8 *func_06898E1C(u32 *p)
{
    *p = 1;
    return d_0689D6F0;
}

void func_06898E28(int a, int b, int c)
{
    func_06898E54(b, c, 1);
}

u8 *func_06898E38(u32 *p)
{
    *p = 1;
    return d_0689D710;
}

void func_06898E44(int a, int b, int c)
{
    func_06898E54(b, c, 2);
}
