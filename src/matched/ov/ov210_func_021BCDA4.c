/*
 * function: func_021BCDA4
 * address: 0x021BCDA4
 * packet: pkt_ov210_021BCDA4
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 2-byte alignment padding at 0x021BCE0A.
 * symbols:
 *   BG_SYS_ResetSlot 0x02041EE4 arm
 *   BGWINFRM_PutFrame 0x0202CB4C thumb
 *   BGWINFRM_UpdateMoves 0x0202CD94 thumb
 *   func_021BEE58 0x021BEE58 thumb ov210
 *   func_021BEE38 0x021BEE38 thumb ov210
 * BEE38 parameters widened: original call uses signed full-width loads.
 */
#include "../include/Obj14673.h"
typedef unsigned int u32;
typedef signed char s8;
struct WinMgr;
extern void BG_SYS_ResetSlot(u32 index, u32 a, u32 b);
extern void BGWINFRM_PutFrame(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern void BGWINFRM_UpdateMoves(struct WinMgr *mgr);
extern void func_021BEE58(char *, int, short *, short *, unsigned short);
extern void func_021BEE38(char *p, int idx, int a, short b, unsigned short c);
void func_021BCDA4(char *p)
{
    unsigned int i;
    short x, y;
    BG_SYS_ResetSlot(4, 3, 48);
    BG_SYS_ResetSlot(7, 3, 48);
    BGWINFRM_PutFrame(*(struct WinMgr * *)&((struct Obj14673 *)p)->f20, 0, 0, 27);
    BGWINFRM_UpdateMoves(*(struct WinMgr * *)&((struct Obj14673 *)p)->f20);
    for (i = 2; i <= 4; i++) {
        func_021BEE58(p, i, &x, &y, 0);
        y += 48;
        func_021BEE38(p, i, x, y, 0);
    }
}
