/*
 * function: BILLBOARD_ACT_UpdateEntry
 * address:  0x02050550
 * packet:   pkt_02050340
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   BILLBOARD_ACT_IsControlCommand  0x02050920  arm
 *   BILLBOARD_ACT_RunControlCommand  0x02050944  arm
 *   BILLBOARD_ACT_UploadSlotFrame  0x020506B8  arm
 *   BILLBOARD_SetElemCell  0x0204F66C  arm
 *   BILLBOARD_SetElemFlipS  0x0204F764  arm
 *   BILLBOARD_SetElemFlipT  0x0204F794  arm
 */
#include "../include/Obj06991.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct Cmd {
    u16 a : 14;
    u16 b : 1;
    u16 c : 1;
    u16 f02;
} Cmd;

typedef struct Ent {
    u32   f00;
    u16   f04;
    u16   f06;
    u32 **f08;
    u16   f0c;
    u16   f0e;
    u16   f10;
    u16   f12;
    u32   f14;
    u32   f18;
} Ent;

typedef struct Own {
    u32  f00;
    u32  f04;
    u32  f08;
    u8  *f0c;
} Own;

struct Entry;
struct Owner;
struct S14;
extern int BILLBOARD_ACT_IsControlCommand(struct S14 *p);
extern int BILLBOARD_ACT_RunControlCommand(void *p, struct S14 *q);
extern void BILLBOARD_ACT_UploadSlotFrame(struct Owner *o, struct Entry *e, u32 a2);
extern void BILLBOARD_SetElemCell(int p0, int p1, int p2);
extern void BILLBOARD_SetElemFlipS(void *p, u32 idx, u32 *val);
extern void BILLBOARD_SetElemFlipT(void *p, u32 idx, u32 *val);

void BILLBOARD_ACT_UpdateEntry(Own *o, Ent *e)
{
    Cmd *c;
    u32  s2;
    u32  s1;
    u16  s0;
    u16  rem;
    u8  *p;

    if (e->f08 == 0 || e->f18 == 0) {
        return;
    }
    if (e->f12 != 0) {
        e->f12 = e->f12 - 1;
        return;
    }

    c = (Cmd *)((u8 *)e->f08[e->f0e] + e->f10 * 4);
    while (BILLBOARD_ACT_IsControlCommand((struct S14 *)c)) {
        if (BILLBOARD_ACT_RunControlCommand(e, (struct S14 *)c)) {
            return;
        }
        c = (Cmd *)((u8 *)e->f08[e->f0e] + e->f10 * 4);
    }

    e->f10 = e->f10 + 1;
    s0 = c->a;
    rem = c->f02;

    p = (u8 *)(e->f04 * 8);
    p = p + (u32)o->f0c;
    if (((struct Obj06991 *)p)->f4 != 0) {
        BILLBOARD_ACT_UploadSlotFrame((struct Owner *)o, (struct Entry *)p, s0);
    } else {
        BILLBOARD_SetElemCell(o->f04, e->f00, (int)(&s0));
    }

    if (c->b) {
        s2 = 1;
    } else {
        s2 = 0;
    }
    if (c->c) {
        s1 = 1;
    } else {
        s1 = 0;
    }

    BILLBOARD_SetElemFlipS((void *)o->f04, e->f00, &s2);
    BILLBOARD_SetElemFlipT((void *)o->f04, e->f00, &s1);

    if (rem != 0) {
        rem = rem - 1;
    }
    e->f12 = rem;
}
