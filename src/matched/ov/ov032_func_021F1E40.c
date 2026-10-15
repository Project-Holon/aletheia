/*
 * function: BEACON_VIEW_StartIconWait
 * address:  0x021F1E40
 * packet:   pkt_ov032_021F1E40
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BEACON_VIEW_StartIconWait 0x021F1E40 thumb
 *   BEACON_VIEW_IconWaitTask 0x021F1EAC thumb
 *   BEACON_VIEW_LoadEntryStatus 0x021F0FC8 thumb
 *   BEACON_VIEW_SetEntryStatusVisible 0x021F0ED0 thumb
 *   TCBL_AddTask 0x020311B8 arm
 *   TCBL_GetWork 0x02031290 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GAME_BEACON_ACCESSOR_GetActionNo 0x02165E24 thumb ov010
 *   GAME_BEACON_ACCESSOR_GetActionViewVariant 0x02165FC0 thumb ov010
 */
#include "../include/Obj00225.h"
#include "../include/Obj05121.h"
#include "../include/Obj20436.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void BEACON_VIEW_IconWaitTask(void *task, u8 *s);
extern void BEACON_VIEW_LoadEntryStatus(char *p, u8 *q, int r);
extern void BEACON_VIEW_SetEntryStatusVisible(char *q, int a);
extern void *TCBL_AddTask(u32 a, void *fn, u32 sz, u32 a3);
struct S02030FB4;
extern void *TCBL_GetWork(struct S02030FB4 *p);
extern void MI_CpuFill8(void *p, int v, int n);
extern int GAME_BEACON_ACCESSOR_GetActionNo(int a0);
extern u8 GAME_BEACON_ACCESSOR_GetActionViewVariant(u32 type);

void BEACON_VIEW_StartIconWait(char *p, char *q, void *x, int flag)
{
    void *t;
    u8 *r;

    t = TCBL_AddTask(((struct Obj20436 *)p)->fA0, (void *)BEACON_VIEW_IconWaitTask, 0x18, 0);
    r = TCBL_GetWork(t);
    MI_CpuFill8(r, 0, 0x18);
    *(char * *)&((struct Obj05121 *)r)->f10 = p;
    *(char * *)&((struct Obj05121 *)r)->f8 = q;
    r[1] = 0x5a;
    ((struct Obj00225 *)q)->f30 = t;
    if (flag)
        ((struct Obj05121 *)r)->fC = 1;
    else
        ((struct Obj05121 *)r)->fC = GAME_BEACON_ACCESSOR_GetActionNo((int)x);
    BEACON_VIEW_LoadEntryStatus(p, (u8 *)q, GAME_BEACON_ACCESSOR_GetActionViewVariant(((struct Obj05121 *)r)->fC));
    BEACON_VIEW_SetEntryStatusVisible(q, flag ? 0 : 1);
}
