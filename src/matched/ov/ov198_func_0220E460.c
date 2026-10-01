/*
 * function: func_0220E460
 * address: 0x0220E460
 * packet: pkt_ov198_0220E460
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
 *   func_020275F8 0x020275F8 thumb
 *   func_02027610 0x02027610 thumb
 */
typedef unsigned short u16;
extern void *func_020490F4(void *, u16);
extern int func_0204A6C8(unsigned, unsigned, unsigned, unsigned, u16);
extern int func_0204ABF0(unsigned, unsigned, unsigned, unsigned, u16);
extern int func_0204AF28(unsigned, unsigned, unsigned, u16);
extern void func_02049238(void *);
extern unsigned func_020275F8(unsigned);
extern unsigned func_02027610(unsigned);
void func_0220E460(char *p)
{
    void *owner;
    unsigned i;
    owner = func_020490F4((void *)83, (*(u16 *)(*(char **)p + 16) & 0x7fff) | 0x8000);
    *(int *)(p + 0x2518) = func_0204ABF0((unsigned)owner, 33, 1, 160, *(u16 *)(*(char **)p + 16));
    *(int *)(p + 0x2530) = func_0204AF28((unsigned)owner, 59, 62, *(u16 *)(*(char **)p + 16));
    for (i = 8; i <= 21; i++)
        ((int *)(p + 0x24a4))[i] = func_0204A6C8((unsigned)owner, func_020275F8(0), 0, 1, *(u16 *)(*(char **)p + 16));
    *(int *)(p + 0x24fc) = func_0204A6C8((unsigned)owner, func_02027610(0), 0, 1, *(u16 *)(*(char **)p + 16));
    *(int *)(p + 0x2500) = func_0204A6C8((unsigned)owner, func_02027610(0), 0, 1, *(u16 *)(*(char **)p + 16));
    func_02049238(owner);
}
