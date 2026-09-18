/*
 * function: func_02025518
 * address:  0x02025518
 * packet:   pkt_02025518
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  020253D4 label
 *
 * symbols:
 *   func_0204ADA4  0x0204ADA4  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


extern u32  func_02025508(u32 a0, u32 a1, u32 a2);
extern void func_020253D4(u8 *p, u32 i, u32 sel);
extern void func_0204ADA4(u32 a0);

void func_02025518(u32 a0, u32 a1, u32 a2)
{
    u32 v = func_02025508(a0, a1, a2);

    func_020253D4((u8 *)a0, v, a2);
    func_0204ADA4(a1);
}
