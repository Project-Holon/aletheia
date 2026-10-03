/*
 * function: func_021841F8
 * address: 0x021841F8
 * packet: pkt_ov168_021841F8
 * region: ov168
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02049B40 0x02049B40 arm
 *   func_02049624 0x02049624 arm
 *   func_0204989C 0x0204989C arm
 */
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02049624(int, int, int, int, int, int, u16);
extern void func_0204989C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 flags);
void func_021841F8(void *p, int heap)
{
    func_02049B40(106, 0, 0, 0, 32, heap);
    func_02049B40(106, 1, 4, 0, 32, heap);
    func_02049B40(23, 5, 0, 416, 32, heap);
    func_02049B40(23, 5, 4, 416, 32, heap);
    func_02049624(106, 4, 5, 0, 0, 0, heap);
    func_0204989C(106, 5, 5, 0, 0, 0, heap);
    func_02049624(106, 2, 1, 0, 0, 0, heap);
    func_0204989C(106, 3, 1, 0, 0, 0, heap);
}
