/*
 * function: func_021BA9E0
 * address:  0x021BA9E0
 * packet:   pkt_021BA9E0
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct {
    u32 a;
    u32 b;
    u32 c;
} Blk;

void func_021BA9E0(u8 *p, Blk *out)
{
    *out = *(Blk *)(p + 0x44);
}
