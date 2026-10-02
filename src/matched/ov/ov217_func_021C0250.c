/*
 * function: func_021C0250
 * address: 0x021C0250
 * packet: pkt_ov217_021C0250
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: trailing 00 00 at 021C02A6 is two-byte alignment padding.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int func_0204A6C8(u32, u32, u32, u32, u16);
extern int func_0204ABF0(u32, u32, u32, u32, u16);
extern int func_0204AF28(u32, u32, u32, u32);
extern void func_02049238(void *);
void func_021C0250(char *p)
{
    u16 heap = *(u16 *)(p + 4);
    void *h = func_020490F4((void *)192, heap);
    int a = func_0204A6C8((u32)h, 15, 0, 1, heap);
    int b = func_0204ABF0((u32)h, 16, 1, 0, heap);
    int c = func_0204AF28((u32)h, 14, 17, heap);
    *(int *)(p + 0x378) = a;
    *(int *)(p + 0x37c) = b;
    *(int *)(p + 0x380) = c;
    func_02049238(h);
}
