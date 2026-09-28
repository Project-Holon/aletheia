/*
 * function: func_021C1A5C
 * address:  0x021C1A5C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stores a constant 1 at offset 0x14 and the argument at offset 0x18.
 * Reached only from the tail-call veneer func_021C118C.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct {
    u32 w[5];
    u32 flag;
    u32 value;
} Rec;

void func_021C1A5C(Rec *p, u32 v)
{
    p->flag = 1;
    p->value = v;
}
