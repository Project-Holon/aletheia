/*
 * function: func_021BCA84
 * address: 0x021BCA84
 * packet: pkt_ov210_021BCA84
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
extern void *func_020490F4(u32 id, u32 heap);
extern void func_020498F4(void *, u32, u32, u32, u32, u32, u16);
extern void func_02049238(void *);
void func_021BCA84(void *a0)
{
    void *h = func_020490F4(159, 0x807b);
    func_020498F4(h, 93, 0, 0, 0, 0, 123);
    func_020498F4(h, 92, 3, 0, 0, 0, 123);
    func_02049238(h);
}
