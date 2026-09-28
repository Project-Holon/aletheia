/*
 * function: func_021F3758
 * address:  0x021F3758
 * packet:   pkt_021F3758
 * region:   ov063
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02030EAC  0x02030EAC  arm
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_02030EAC(u32 a);
extern void func_020307B0(u32 a);

void func_021F3758(u8 *p)
{
    func_02030EAC(*(u32 *)(p + 0x80));
    func_020307B0((u32)p);
}
