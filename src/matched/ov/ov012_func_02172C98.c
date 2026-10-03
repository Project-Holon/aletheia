/*
 * function: func_02172C98
 * address:  0x02172C98
 * packet:   pkt_ov012_02172C98
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     unlabelled callback leaf (a .word run in the listing); passed as
 *           a function pointer (pool words 0x02172C74 and 0x02172E44).
 * symbols:
 *   func_0203D8C4  0x0203D8C4  arm
 */

typedef unsigned char u8;

typedef unsigned int   u32;
extern void func_0203D8C4(u32 a);

void func_02172C98(u8 *p)
{
    p[0x3560] = 2;
    func_0203D8C4(0);
}
