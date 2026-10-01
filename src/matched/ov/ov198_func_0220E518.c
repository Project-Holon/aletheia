/*
 * function: func_0220E518
 * address: 0x0220E518
 * packet: pkt_ov198_0220E518
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
extern void *func_020490F4(void *, u16);
extern int func_0204A6C8(unsigned, unsigned, unsigned, unsigned, u16);
extern int func_0204ABF0(unsigned, unsigned, unsigned, unsigned, u16);
extern int func_0204AF28(unsigned, unsigned, unsigned, u16);
extern void func_02049238(void *);
void func_0220E518(char *p)
{
    void *owner;
    owner = func_020490F4((void *)83, (*(u16 *)(*(char **)p + 16) & 0x7fff) | 0x8000);
    *(int *)(p + 0x24c0) = func_0204A6C8((unsigned)owner, 65, 0, 1, *(u16 *)(*(char **)p + 16));
    *(int *)(p + 0x2514) = func_0204ABF0((unsigned)owner, 66, 1, 128, *(u16 *)(*(char **)p + 16));
    *(int *)(p + 0x252c) = func_0204AF28((unsigned)owner, 67, 70, *(u16 *)(*(char **)p + 16));
    func_02049238(owner);
}
