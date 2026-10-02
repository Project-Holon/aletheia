/*
 * function: func_021E5958
 * address: 0x021E5958
 * packet: pkt_ov119_021E5958
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049990 0x02049990 arm
 *   func_02049238 0x02049238 arm
 */
typedef unsigned short u16;
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049990(int, int, int, int, u16, int, int, u16);
extern void func_02049238(int);
void func_021E5958(int p)
{
    void *a = func_020490F4(0x66, *(u16 *)(p + 0x5f4));
    func_02049990(a, 0x1d, 2, 0, *(int *)(p + 0x86c), 0, 0, *(u16 *)(p + 0x5f4));
    func_02049238(a);
}
