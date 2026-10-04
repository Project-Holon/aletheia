/*
 * function: func_021FF26C
 * address: 0x021FF26C
 * packet: pkt_ov135_021FF26C
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
 *   func_021FF318 0x021FF318 thumb ov135
 *   func_021F4E98 0x021F4E98 thumb ov135
 *   d_02203D4A 0x02203D4A data a2
 */
typedef unsigned short u16;
extern int func_0204B98C(unsigned);
extern int func_021FE9B0(char *);
extern void func_0204B878(unsigned, u16);
typedef unsigned char  u8;
extern u8 func_020355C4(void);
struct Obj;
extern void func_0204B3DC(struct Obj *, unsigned int);
extern const u16 d_02203D4A[][4];
extern void func_021FF318(char *, int, int, int, int);
extern void func_021F4E98(char *, unsigned, unsigned);
int func_021FF26C(char *p)
{
    if (func_0204B98C(*(unsigned *)(p + 0xbf4)) == 0) {
        func_0204B878(*(unsigned *)(p + 0xbf4), d_02203D4A[func_021FE9B0(p)][0]);
        if (func_020355C4() == 1)
            func_0204B3DC((struct Obj *)*(unsigned *)(p + 0xbf4), 0);
        else
            func_0204B3DC((struct Obj *)*(unsigned *)(p + 0xbf4), 1);
        func_021FF318(p, 15, 1, 0, 0xf0f);
        func_021F4E98(p, 23, 26);
    }
    return 2;
}
