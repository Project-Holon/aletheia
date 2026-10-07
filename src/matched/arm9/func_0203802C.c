/*
 * function: func_0203802C
 * address:  0x0203802C
 * packet:   pkt_02037F48
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469D0     0x021469D0  data
 *   d_020A7A20     0x020A7A20  data
 *   func_0203D788  0x0203D788  arm
 *   func_020366A8  0x020366A8  arm
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3A8  0x0203D3A8  arm
 *   func_0203D6BC  0x0203D6BC  arm
 *   func_02037D98  0x02037D98  arm
 *   func_020381D8  0x020381D8  arm
 *
 * Fourth entry of this packet's chain, and the one the lane table expected to
 * need two callees filed: it calls func_020381D8, whose own entry is in this
 * shard, so that site resolves through `matched`; 0x020366A8 and 0x0203D3A8,
 * the other two the table named, turn out to have outside witnesses
 * (0x02038B48 and 0x02039AAC) once the compared range is this one function
 * rather than the whole packet.
 *
 * The two literals in the tail are different objects: the first argument to
 * func_020381D8 is one dereference of the 0x021469D0 pointer word, and the
 * final store is into the byte at 0x020A7A20 + 1.  Reading them as the same
 * symbol makes the compiler pool the address once and spend a second
 * callee-saved register on the transfer value.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203802C.c \
 *       --func func_0203802C --addr 0x0203802C --cc 1.1p1 --arm
 */
#include "../include/Obj15934.h"
#include "../include/G_LinkState.h"

typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;

struct Entry;
extern void *func_0203D788(void);
struct Conn;
extern int func_020366A8(struct Conn *p);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern struct Entry *func_020399A8(void);
extern u32 func_0203D6BC(void);
extern int func_02037D98(int a);
extern void func_020381D8(u32 a, u32 b);
extern struct LinkState *g_021469D0;
extern u8 d_020A7A20[];

void func_0203802C(void)
{
    u8 *p;
    u32 v;

    p = func_0203D788();

    if (func_020366A8((struct Conn *)(((u8 *)g_021469D0) + 0xCC)) != 0)
        func_0203D3A8(func_020399A8(), 0x10, 0, 0);

    v = *(u32 *)(((struct Obj15934 *)p)->f340 + 0x9C);
    if (v != 0)
        ((void (*)(void))v)();
    if (((u32 (*)(void)) * (u32 *)(*(u32 *)(p + 0x340) + 0x6C))() != 1)
        return;

    v = func_0203D6BC();
    if (((u32 (*)(void)) * (u32 *)(*(u32 *)(p + 0x340) + 0xA0))() != 1)
        return;
    if (func_02037D98(0) == 0)
        return;

    func_020381D8(*(u32 *)((u8 *)g_021469D0), v);
    *(u8 *)(d_020A7A20 + 1) = 4;
}
