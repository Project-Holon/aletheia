/*
 * function: func_021C02C8
 * address: 0x021C02C8
 * packet: pkt_ov217_021C02C8
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: trailing 00 00 at 021C0356 is two-byte alignment padding.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
extern void *func_020490F4(unsigned int id, u16 heap);
extern int func_0204A6C8(u32, u32, u32, u32, u16);
extern int func_0204AC18(u32, u32, u32, u32, u16, u16, u16);
extern int func_0204AF28(u32, u32, u32, u32);
extern void func_02049238(void *);
void func_021C02C8(char *p)
{
    u16 heap = *(u16 *)(p + 4);
    void *h = func_020490F4(192, heap);
    int a = func_0204A6C8((u32)h, 15, 0, 0, heap);
    int b = func_0204AC18((u32)h, 16, 0, 192, 0, 3, heap);
    int c = func_0204AF28((u32)h, 14, 17, heap);
    int d;
    func_02049238(h);
    h = func_020490F4(83, heap);
    d = func_0204AC18((u32)h, 31, 0, 128, 0, 2, heap);
    func_02049238(h);
    *(int *)(p + 0x368) = a;
    *(int *)(p + 0x36c) = b;
    *(int *)(p + 0x374) = d;
    *(int *)(p + 0x370) = c;
}
