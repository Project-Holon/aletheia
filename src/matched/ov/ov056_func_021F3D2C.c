/*
 * function: func_021F3D2C
 * address:  0x021F3D2C
 * packet:   pkt_021F3D2C
 * region:   ov056
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02047204  0x02047204  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Tagged;
extern u32 func_02047204(struct Tagged *p);

void func_021F3D2C(u8 *p)
{
    if (*(u32 *)(p + 0xc) != 0) {
        func_02047204((struct Tagged *)(*(u32 *)p));
        *(u32 *)(p + 0xc) = 0;
    }
}
