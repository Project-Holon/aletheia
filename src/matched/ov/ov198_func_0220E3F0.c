/*
 * function: func_0220E3F0
 * address: 0x0220E3F0
 * packet: pkt_ov198_0220E3F0
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 */
typedef unsigned short u16;
extern void *func_020490F4(unsigned int id, u16 heap);
extern int func_0204A6C8(void *, unsigned, unsigned, unsigned, u16);
extern int func_0204ABF0(void *, unsigned, unsigned, unsigned, u16);
extern int func_0204AF28(void *, unsigned, unsigned, u16);
extern void func_02049238(void *);
void func_0220E3F0(char *p)
{
    void *owner;
    owner = func_020490F4(83,(*(u16 *)(*(char **)p + 16) & 0x7fff) | 0x8000);
    *(int *)(p + 0x24bc) = func_0204A6C8(owner, 12, 0, 1, *(u16 *)(*(char **)p + 16));
    *(int *)(p + 0x2510) = func_0204ABF0(owner, 11, 1, 96, *(u16 *)(*(char **)p + 16));
    *(int *)(p + 0x2528) = func_0204AF28(owner, 13, 16, *(u16 *)(*(char **)p + 16));
    func_02049238(owner);
}
