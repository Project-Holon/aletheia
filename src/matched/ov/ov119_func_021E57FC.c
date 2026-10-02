/*
 * function: func_021E57FC
 * address: 0x021E57FC
 * packet: pkt_ov119_021E57FC
 * region: ov119
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
typedef unsigned short u16;
extern void *func_020490F4(unsigned int id, u16 heap);
extern int func_0204A6C8(void *, int, int, int, u16);
extern int func_0204AC18(void *, int, int, int, u16, u16, u16);
extern int func_0204AF28(void *, int, int, u16);
extern void func_02049238(void *);
void func_021E57FC(int p)
{
    void *a;
    if (*(int *)(p + 0x898) == 0) {
        a = func_020490F4(0x66, *(u16 *)(p + 0x5f4));
        *(int *)(p + 0x898) = func_0204A6C8(a, 0x15, 0, 0, *(u16 *)(p + 0x5f4));
        *(int *)(p + 0x884) = func_0204AC18(a, 0x12, 0, 0xc0, 0, 6, *(u16 *)(p + 0x5f4));
        *(int *)(p + 0x8b4) = func_0204AF28(a, 0x14, 0x13, *(u16 *)(p + 0x5f4));
        func_02049238(a);
    }
}
