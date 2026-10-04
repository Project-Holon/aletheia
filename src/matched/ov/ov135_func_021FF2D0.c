/*
 * function: func_021FF2D0
 * address: 0x021FF2D0
 * packet: pkt_ov135_021FF2D0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B98C 0x0204B98C arm
 *   func_021FE9B0 0x021FE9B0 thumb ov135
 *   func_0204B878 0x0204B878 arm
 *   func_020355C4 0x020355C4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   d_02203D4A 0x02203D4A data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_0204B98C(u32);
extern int func_021FE9B0(u8 *);
extern void func_0204B878(u32, u16);
extern u8 func_020355C4(void);
struct Obj;
extern void func_0204B3DC(struct Obj *, unsigned int);
extern const u16 d_02203D4A[][4];
int func_021FF2D0(u8 *p)
{
    if (func_0204B98C(*(u32 *)(p + 0xBF4)) == 0) {
        func_0204B878(*(u32 *)(p + 0xBF4), d_02203D4A[func_021FE9B0(p)][0]);
        if (func_020355C4() == 1) {
            func_0204B3DC((struct Obj *)*(u32 *)(p + 0xBF4), 0);
        } else {
            func_0204B3DC((struct Obj *)*(u32 *)(p + 0xBF4), 1);
        }
        *(u32 *)(p + 0x28) = 1;
    }
    return 2;
}
