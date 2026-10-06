/*
 * function: func_021BF9D0
 * address: 0x021BF9D0
 * packet: pkt_ov203_021BF9D0
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 021BFA1E..021BFA20 is two zero alignment bytes.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 */
typedef unsigned short u16;

extern void *func_020490F4(unsigned int id, u16 heap);
extern void func_02049B68(void *, unsigned, unsigned, unsigned, unsigned, unsigned short);
typedef unsigned int   u32;
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned short);
extern void func_02049238(void *);
void func_021BF9D0(unsigned short heap)
{
    void *h = func_020490F4(85, heap);
    func_02049B68(h, 3, 4, 0, 0, heap);
    func_02049658(h, 9, 6, 0, 0, 0, heap);
    func_020498F4(h, 18, 6, 0, 0, 0, heap);
    func_02049238(h);
}
