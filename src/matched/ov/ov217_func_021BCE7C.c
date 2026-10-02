/*
 * function: func_021BCE7C
 * address: 0x021BCE7C
 * packet: pkt_ov217_021BCE7C
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204AF28 0x0204AF28 arm
 * Original narrows heap at 020490F4; its extern takes u16.
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int func_0204A6C8(u32, u32, u32, u32, u16);
extern int func_0204AC18(u32, u32, u32, u32, u16, u16, u16);
extern int func_0204AF28(u32, u32, u32, u32);
extern void func_02049238(void *);
void func_021BCE7C(char *p)
{
    u16 heap;
    void *arc;
    int a, b, c, d;
    heap = *(u16 *)(p + 8);
    arc = func_020490F4((void *)192, (heap & 0x7FFF) | 0x8000);
    a = func_0204A6C8((u32)arc, 15, 0, 0, heap);
    b = func_0204AC18((u32)arc, 16, 0, 192, 0, 4, heap);
    c = func_0204AF28((u32)arc, 14, 17, heap);
    func_02049238(arc);
    arc = func_020490F4((void *)83, heap);
    d = func_0204AC18((u32)arc, 31, 0, 128, 0, 2, heap);
    func_02049238(arc);
    *(int *)(p + 0xF8) = a;
    *(int *)(p + 0xFC) = b;
    *(int *)(p + 0x100) = c;
    *(int *)(p + 0x104) = d;
}
