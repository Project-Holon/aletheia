/*
 * function: func_021DD090
 * address:  0x021DD090
 * packet:   pkt_ov170_021DD090
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202CF98 0x0202CF98 thumb
 *   func_0202CFC0 0x0202CFC0 thumb
 *   func_0202CF8C 0x0202CF8C thumb
 */
#include "../include/Obj23825.h"
#include "../include/Obj23826.h"
#include "../include/Obj23827.h"

typedef struct {
    unsigned char pad[0x1A6];
    unsigned char flag : 1;
    unsigned char id : 7;
    unsigned char lo : 4;
    unsigned char hi : 4;
    unsigned char state;
    unsigned char count;
    unsigned char x;
    unsigned char y;
    unsigned char w;
    unsigned char h;
} Work;

typedef struct {
    unsigned char pad[0x2C];
    Work *work;
} Sys;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
struct WinMgr;
extern void func_0202CF98(struct WinMgr *mgr, u32 idx, s8 *x, s8 *y);
extern void func_0202CFC0(struct WinMgr *mgr, u32 idx, u16 *w, u16 *h);
extern u8 func_0202CF8C(struct WinMgr *mgr, u32 idx);

void func_021DD090(Sys *p, unsigned idx)
{
    unsigned short w;
    unsigned short h;
    signed char pos[2];
    func_0202CF98(*(struct WinMgr * *)&((struct Obj23825 *)((char *)p->work))->f74, idx, &pos[1], &pos[0]);
    func_0202CFC0(*(struct WinMgr * *)&((struct Obj23826 *)((char *)p->work))->f74, idx, &w, &h);
    p->work->flag = 1;
    p->work->id = func_0202CF8C(*(struct WinMgr * *)&((struct Obj23827 *)((char *)p->work))->f74, idx);
    p->work->lo = 0xD;
    p->work->hi = 0xC;
    p->work->state = 0;
    p->work->count = 0;
    p->work->x = pos[1];
    p->work->y = pos[0];
    p->work->w = w;
    p->work->h = h;
}
