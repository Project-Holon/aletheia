/*
 * function: func_021B96EC
 * address: 0x021B96EC
 * packet: pkt_ov100_021B96EC
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 94 bytes code followed by two zero alignment bytes before 021B974C.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int func_0204A6C8(u32, u32, u32, u32, u16);
extern int func_0204AC18(u32, u32, u32, u32, u16, u16, u16);
extern int func_0204AF28(u32, u32, u32, u32);
extern void func_02049238(void *);
void func_021B96EC(char *p)
{
    void *owner;
    owner = func_020490F4((void *)28, *(u16 *)(p + 0x278));
    *(int *)(p + 0x2bc) = func_0204A6C8((u32)owner, 7, 0, 0, *(u16 *)(p + 0x278));
    *(int *)(p + 0x2b8) = func_0204AC18((u32)owner, 3, 0, 0, 0, 3, *(u16 *)(p + 0x278));
    *(int *)(p + 0x2c0) = func_0204AF28((u32)owner, 9, 15, *(u16 *)(p + 0x278));
    func_02049238(owner);
}
