/*
 * function: func_021FF218
 * address: 0x021FF218
 * packet: pkt_ov135_021FF218
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
 *   func_021FE264 0x021FE264 thumb ov135
 *   d_02203D4A 0x02203D4A data a2
 */
typedef unsigned short u16;
typedef unsigned int   u32;
struct Actor;
struct Obj;
extern u32 func_0204B98C(struct Actor *a);
extern int func_021FE9B0(char *);
extern void func_0204B878(struct Obj *p, u16 value);
typedef unsigned char  u8;
extern u8 func_020355C4(void);
struct Obj;
extern void func_0204B3DC(struct Obj *, unsigned int);
extern const u16 d_02203D4A[][4];
extern void func_021FE264(char *, int);
int func_021FF218(char *p)
{
    if (func_0204B98C((struct Actor *)(*(unsigned *)(p + 0xbf4))) == 0) {
        func_0204B878((struct Obj *)(*(unsigned *)(p + 0xbf4)), d_02203D4A[func_021FE9B0(p)][0]);
        if (func_020355C4() == 1)
            func_0204B3DC((struct Obj *)*(unsigned *)(p + 0xbf4), 0);
        else
            func_0204B3DC((struct Obj *)*(unsigned *)(p + 0xbf4), 1);
        func_021FE264(p, func_021FE9B0(p));
    }
    return 2;
}
