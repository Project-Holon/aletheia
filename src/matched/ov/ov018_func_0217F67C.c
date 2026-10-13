/*
 * function: EVENT_COMM_COMMON_CreateExitSyncEvent
 * address: 0x0217F67C
 * packet: pkt_ov018_0217F67C
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   EVENT_COMM_COMMON_ExitSyncEventMain 0x0217F6A0 thumb ov018
 */
#include "../include/Obj19364.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern int EVENT_COMM_COMMON_ExitSyncEventMain(int, int *, void *);
void *EVENT_COMM_COMMON_CreateExitSyncEvent(void *owner, u16 *out)
{
    void *task;
    u8 *work;
    int zero;
    zero = 0;
    task = func_020122C0(owner, 0, EVENT_COMM_COMMON_ExitSyncEventMain, 0x10);
    work = func_020124E8(task);
    *(u16 * *)&((struct Obj19364 *)work)->fC = out;
    *out = zero;
    return task;
}
