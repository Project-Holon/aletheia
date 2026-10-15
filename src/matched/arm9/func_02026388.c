/*
 * function: GAME_COMM_CallHandler
 * address:  0x02026388
 * packet:   pkt_0202627C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Parked: every concrete byte is right; the only unresolved site is the
 * data table base 0x0209FB70, whose word has no witness outside this range
 * (`literal` has nothing to stand on, and no branch anywhere names it).
 * Blocker: 0x0209FB70 (data).
 *
 * symbols:
 *   gGameCommHandlers  0x0209FB70  data
 */

typedef signed char    s8;
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj {
    u8  pad0[4];
    u8  f4;
    u8  f5;
    u8  pad6[0xA];
    u8  f10;
    u8  pad11[3];
    u32 f14;
    u32 f18;
};

typedef void (*Fn)(u32 a, u32 b, u32 c);

extern u8 gGameCommHandlers[];

void GAME_COMM_CallHandler(struct Obj *p, u32 a)
{
    if (p->f10 != 5) {
        Fn fn = *(Fn *)(gGameCommHandlers + p->f5 * 0x1C);

        if (fn != 0) {
            fn(p->f14, p->f18, a);
        }
    }
}
