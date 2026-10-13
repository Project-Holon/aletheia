/*
 * function: INTRUDE_FIELD_CreateAreaChangeTask
 * address: 0x0217B1DC
 * packet: pkt_ov018_0217B1DC
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   FIELD_PLAYER_GetMmdl 0x021A3074 thumb ov021
 *   INTRUDE_FIELD_TaskAreaChange 0x0217B214 thumb ov018
 */
#include "../include/Obj09386.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void INTRUDE_FIELD_TaskAreaChange();
extern void MI_CpuFill8(void *, int, int);
extern void *FIELD_PLAYER_GetMmdl(u8 *p);
void *INTRUDE_FIELD_CreateAreaChangeTask(void *a, int b, int c, unsigned short d) {
    void *t;
    u8 *p;
    t = func_020122C0(a, 0, INTRUDE_FIELD_TaskAreaChange, 0x30);
    p = func_020124E8(t);
    MI_CpuFill8(p, 0, 0x30);
    ((struct Obj09386 *)p)->f0 = b;
    ((struct Obj09386 *)p)->f4 = (int)FIELD_PLAYER_GetMmdl((u8 *)c);
    ((struct Obj09386 *)p)->f14 = d;
    return t;
}
