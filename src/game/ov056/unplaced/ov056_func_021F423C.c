/*
 * function: func_021F423C
 * address:  0x021F423C
 * packet:   pkt_ov056_021F423C
 * region:   ov056
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02006148  0x02006148  thumb
 *   func_020061F8  0x020061F8  thumb
 */

typedef unsigned short u16;
typedef unsigned char  u8;
typedef unsigned int   u32;

extern int func_02006148(u32 a0);
extern void func_020061F8(int i);

void func_021F423C(u8 *p, u32 idx)
{
    u16 v = *(u16 *)(p + idx * 2 + 8);

    if (v != 0xffff) {
        func_020061F8(func_02006148(v));
    }
}
