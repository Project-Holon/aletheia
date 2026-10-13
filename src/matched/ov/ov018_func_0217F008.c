/*
 * function: INTRUDE_SUBDISP_UpdateTownState
 * address:  0x0217F008
 * packet:   pkt_ov018_0217F008
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012B58  0x02012B58  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_02080D24  0x02080D24  arm
 *   EVENT_COMM_COMMON_GetMissionState  0x0217F5A0  thumb  ov018
 *   INTRUDE_COMM_GetSessionRemaining  0x021758C8  thumb  ov011
 *   INTRUDE_COMM_GetActiveSessionRequest  0x02175B34  thumb  ov011
 *   INTRUDE_FIELD_IsStartRequested  0x0217C070  thumb  ov018
 */
#include "../include/Obj00399.h"
#include "../include/Obj12492.h"

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct { u16 lo : 3; u16 hi : 13; } Bf;
typedef struct { u8 pad[0x28]; u8 idx; } T;
typedef struct {
    u8 a, b, c, d;
    int e;
    int f;
    T *g;
    u8 h, i, j;
} O;

struct BigObj;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern u8 func_02012B58(const struct BigObj *p);
extern void MI_CpuFill8(void *, int, int);
extern int func_02080D24(unsigned int x);
extern int EVENT_COMM_COMMON_GetMissionState(char *);
extern int INTRUDE_COMM_GetSessionRemaining(u8 *o);
extern u8 *INTRUDE_COMM_GetActiveSessionRequest(u8 *p);
extern int INTRUDE_FIELD_IsStartRequested(u8 *p);

void INTRUDE_SUBDISP_UpdateTownState(char *p, char *q)
{
    O *o;
    int h;
    int n;
    int i;

    o = (O *)(p + 0xd8);
    h = (int)func_020120F4((const struct Ctx *)(*(int *)&((struct Obj00399 *)p)->f0));
    if (q == 0) {
        MI_CpuFill8(p + 0xd8, 0, 0x14);
        *(p + 0x11e) = 1;
        return;
    }
    n = func_02012B58((const struct BigObj *)h);
    o->a = ((Bf *)(q + 0x86))->lo;
    o->b = ((struct Obj12492 *)q)->f8FB;
    o->c = func_02080D24(o->b);
    o->d = ((struct Obj12492 *)q)->f910;
    o->e = EVENT_COMM_COMMON_GetMissionState(q + 0x1ac);
    o->f = INTRUDE_COMM_GetSessionRemaining((u8 *)(q + 0x1ac));
    o->g = (T *)INTRUDE_COMM_GetActiveSessionRequest((u8 *)(q + 0x1ac));
    if (o->g != 0) {
        o->h = ((Bf *)(q + o->g->idx * 0x1c + 0xa2))->lo;
    }
    o->i = INTRUDE_FIELD_IsStartRequested((u8 *)q);
    o->j = 0;
    for (i = 0; i < 3; i++) {
        if (i != n && o->a == ((Bf *)(q + i * 0x1c + 0xa2))->lo) {
            o->j = 1;
            return;
        }
    }
}
