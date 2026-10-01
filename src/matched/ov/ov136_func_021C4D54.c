/*
 * function: func_021C4D54
 * address: 0x021C4D54
 * packet: pkt_ov136_021C4D54
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C440 0x0201C440 thumb
 *   func_0204B100 0x0204B100 arm
 *   func_0202DE5C 0x0202DE5C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_0201C440(u16);
extern void *func_0204B100(int, int, u32);
extern void *func_0202DB0C(u32, u32, u32, u32, u8, u8, u16);
extern void func_0202DE5C(void *, int);
void func_021C4D54(u8 *p)
{
    *(void **)(p + 0x158) = func_0201C440((u16)*(u32 *)p);
    *(void **)(p + 0x154) = func_0204B100(8, 1, (u16)*(u32 *)p);
    *(void **)(p + 0x148) = func_0202DB0C(*(u32 *)(p + 0x154), 0, *(u32 *)(p + 0x158), *(u32 *)(p + 0x24), 0, 4, (u16)*(u32 *)p);
    func_0202DE5C(*(void **)(p + 0x148), 0);
}
