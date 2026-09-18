/*
 * function: func_02025404
 * address:  0x02025404
 * packet:   pkt_020251FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204AC18  0x0204AC18  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


extern u32  func_02025360(u32 a0, u32 a1, u32 a2);
extern void func_0204AC18(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);

void func_02025404(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5)
{
    u32 v = func_02025360(a0, a4, a3);

    func_0204AC18(a1, a2, a3, (v & 0x7ff) << 5, 0, (u16)a4, (u16)a5);
}
