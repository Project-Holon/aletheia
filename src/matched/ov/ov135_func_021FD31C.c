/*
 * function: func_021FD31C
 * address: 0x021FD31C
 * packet: pkt_ov135_021FD31C
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
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
int func_021FD31C(unsigned char *p)
{
    func_0204B3DC((struct Obj *)*(u32 *)(p + 0xd38), 0);
    if (*(int *)(p + 0x20) == 16) {
        func_0202208C(0, 1, 1, 0, 16, 1, 0x48);
        *(int *)(p + 0x28) = 7;
    } else {
        *(int *)(p + 0x28) = 1;
        func_0204B3DC((struct Obj *)*(u32 *)(p + 0xd34), 1);
    }
    return 2;
}
