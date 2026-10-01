/*
 * function: func_021BCDF0
 * address: 0x021BCDF0
 * packet: pkt_ov217_021BCDF0
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 * 0204ABF0 is void in its source but forwards to the int-returning
 * 0204AC18; the original stores its live r0 result. 020490F4 narrows heap.
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(void *, u16);
extern int func_0204A6C8(u32, u32, u32, u32, u16);
extern int func_0204ABF0(u32, u32, u32, u32, u16);
extern int func_0204AF28(u32, u32, u32, u32);
extern void func_02049238(void *);
void func_021BCDF0(char *p)
{
    u16 heap;
    void *arc;
    int a, b, c;
    heap = *(u16 *)(p + 8);
    arc = func_020490F4((void *)192, (heap & 0x7FFF) | 0x8000);
    a = func_0204A6C8((u32)arc, 15, 0, 1, heap);
    b = func_0204ABF0((u32)arc, 16, 1, 0, heap);
    c = func_0204AF28((u32)arc, 14, 17, heap);
    *(int *)(p + 0x108) = a;
    *(int *)(p + 0x10C) = b;
    *(int *)(p + 0x110) = c;
    func_02049238(arc);
}
