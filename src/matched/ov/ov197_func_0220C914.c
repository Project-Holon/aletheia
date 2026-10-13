/*
 * function: func_0220C914
 * address: 0x0220C914
 * packet: pkt_ov197_0220C914
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0220D3B0 0x0220D3B0 thumb ov197
 *   func_0220BF40 0x0220BF40 thumb ov197
 *   func_0220B980 0x0220B980 thumb ov197
 *   func_020310C4 0x020310C4 arm
 *   BGWINFRM_UpdateMoves 0x0202CD94 thumb
 *   d_0220DF40 0x0220DF40 data a4
 */
#include "../include/Obj00846.h"
#include "../include/Obj25048.h"
#include "../include/Obj25049.h"
#include "../include/Obj25050.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Tcbl;
struct WinMgr;
extern int (*const d_0220DF40[])(char *);
struct Node;
extern int func_0220D3B0(struct Node *task, char *p);
extern void func_0220BF40(char *);
extern int func_0220B980(char *);
extern void func_020310C4(struct Tcbl *);
extern void BGWINFRM_UpdateMoves(struct WinMgr *mgr);
void func_0220C914(void *task, char *p)
{
    if (((struct Obj25048 *)(*(char * *)&((struct Obj00846 *)p)->f0))->f24 == 1) {
        ((struct Obj25049 *)(*(char * *)&((struct Obj00846 *)p)->f0))->f16 = 0;
        ((struct Obj25050 *)(*(char * *)&((struct Obj00846 *)p)->f0))->f18 = 0;
        ((struct Obj00846 *)p)->f530 = 20;
    }
    if (((struct Obj00846 *)p)->f530 != 20) ((struct Obj00846 *)p)->f530 = d_0220DF40[*(u8 *)(p + 0x530)](p);
    if (((struct Obj00846 *)p)->f530 == 20 && func_0220D3B0(task, p) == 1) return;
    func_020310C4(*(struct Tcbl * *)&((struct Obj00846 *)p)->f4);
    func_0220BF40(p);
    BGWINFRM_UpdateMoves(*(struct WinMgr * *)&((struct Obj00846 *)p)->f520);
    func_0220B980(p);
}
