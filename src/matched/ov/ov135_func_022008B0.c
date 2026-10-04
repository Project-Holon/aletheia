/*
 * function: func_022008B0
 * address: 0x022008B0
 * packet: pkt_ov135_022008B0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B98C 0x0204B98C arm
 *   func_0204B878 0x0204B878 arm
 *   func_020355C4 0x020355C4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0220053C 0x0220053C thumb ov135
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Actor;
struct Obj;
extern u32 func_0204B98C(struct Actor *a);
extern void func_0204B878(struct Obj *p, u16 value);
extern u8 func_020355C4(void);
struct Obj;
extern void func_0204B3DC(struct Obj *, unsigned int);
extern void func_0220053C(u8 *p, int mode);
int func_022008B0(u8 *p)
{
    if (func_0204B98C((struct Actor *)(*(u32 *)(p + 0xbf4))) == 0) {
        func_0204B878((struct Obj *)(*(u32 *)(p + 0xbf4)), 0);
        if (func_020355C4() == 1)
            func_0204B3DC((struct Obj *)*(u32 *)(p + 0xbf4), 0);
        else
            func_0204B3DC((struct Obj *)*(u32 *)(p + 0xbf4), 1);
        func_0220053C(p, *(u16 *)(p + 0xc0));
    }
    return 2;
}
