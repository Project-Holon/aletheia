/*
 * function: func_021FD4D4
 * address: 0x021FD4D4
 * packet: pkt_ov135_021FD4D4
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 */
typedef unsigned int u32;
struct Obj;
extern void func_0204B3DC(struct Obj *, unsigned int);
extern void func_0202208C(u32, u32, u32, u32, u32, u32, u32);
int func_021FD4D4(unsigned char *p)
{
    func_0204B3DC((struct Obj *)*(u32 *)(p + 0xd34), 0);
    if (*(int *)(p + 0x20) != 15) {
        if (*(int *)(p + 0x20) == 6)
            func_0202208C(0, 0, 0, 0, 6, 1, 0x48);
        else
            func_0202208C(3, 0, 0, 0, 6, 1, 0x48);
    }
    *(int *)(p + 0x28) = 0;
    return 3;
}
