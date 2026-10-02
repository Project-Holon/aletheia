/*
 * function: func_021C0B0C
 * address: 0x021C0B0C
 * packet: pkt_ov217_021C0B0C
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int func_0204A6C8(u32, u32, u32, u32, u16);
extern int func_0204AC18(u32, u32, u32, u32, u16, u16, u16);
extern int func_0204AF28(u32, u32, u32, u32);
extern void func_02049238(void *);
void func_021C0B0C(u8 *p)
{
    u16 heap = *(u16 *)p;
    void *h = func_020490F4((void *)83, (u16)((heap & 0x7FFF) | 0x8000));
    int a = func_0204A6C8((u32)h, 20, 0, 0, heap);
    int b = func_0204AC18((u32)h, 19, 0, 0, 0, 4, heap);
    int c = func_0204AF28((u32)h, 21, 24, heap);
    *(int *)(p + 20) = a;
    *(int *)(p + 24) = b;
    *(int *)(p + 28) = c;
    func_02049238(h);
}
