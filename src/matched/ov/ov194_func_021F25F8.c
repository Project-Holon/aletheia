/*
 * function: func_021F25F8
 * address:  0x021F25F8
 * packet:   pkt_021F25F8
 * region:   ov194
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F4D94 0x021F4D94 thumb
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_021F4D94(const u8 *p, u32 i);

void func_021F25F8(int *a, int b, int c)
{
    *a = func_021F4D94((const u8 *)c, b);
}
