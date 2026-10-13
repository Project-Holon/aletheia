/*
 * function: EVENT_COMM_COMMON_CreateTalkedStartEvent
 * address:  0x0217FC6C
 * packet:   pkt_ov018_0217FC6C
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 *   INTRUDE_COMM_ClearRequestOpen  0x0217545C  thumb ov011
 *   EVENT_COMM_COMMON_TalkedStartEventMain  0x0217FCAC  thumb ov018
 */
#include "../include/Obj07367.h"

typedef unsigned short u16;

typedef unsigned int   u32;
struct Desc;
struct Obj;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
void MI_CpuFill8(void *p, int v, int n);
typedef unsigned char  u8;
void INTRUDE_COMM_ClearRequestOpen(u8 *p);
int EVENT_COMM_COMMON_TalkedStartEventMain(int x, int *st, int *obj);

void *EVENT_COMM_COMMON_CreateTalkedStartEvent(void *p, int a, int b, int c, int d, u16 e)
{
    void *r = func_020122C0(p, 0, EVENT_COMM_COMMON_TalkedStartEventMain, 0x10);
    int *q = func_020124E8(r);

    MI_CpuFill8(q, 0, 0x10);
    q[0] = a;
    q[1] = c;
    q[2] = d;
    ((struct Obj07367 *)q)->fC = e;
    INTRUDE_COMM_ClearRequestOpen((u8 *)b);
    return r;
}
