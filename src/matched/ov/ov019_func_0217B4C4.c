/*
 * function: UNION_CHARA_ActionIdle
 * address:  0x0217B4C4
 * packet:   pkt_ov019_0217B4C4
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   UNION_CHARA_SetNextAction  0x0217AE38  thumb  ov019
 *   UNION_CHARA_MakeObjId  0x0217AED4  thumb  ov019
 *   UNION_CHARA_GetMmdl  0x0217AFB0  thumb  ov019
 *   UNION_MSG_GetCategoryTableValue  0x0217F060  thumb  ov019
 *   func_0217F858  0x0217F858  thumb  ov019
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FLDMMDL_GetMoveCode  0x0216D5A0  thumb  ov010
 *   FLDMMDL_ChangeMoveCode  0x0216E0E8  thumb  ov010
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12518.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Rec {
    u8 pad0[6];
    u8 b6;
    u8 f7_lo : 1;
    u8 valid : 1;
    u8 f7_hi : 6;
} Rec;

typedef struct Entry {
    u8   pad0[6];
    u8   n : 3;
    u8   f6_hi : 5;
    u8   f7_lo : 5;
    u8   kind : 3;
    u8   pad8[3];
    u8   bB;
    u8   padC[0x28 - 0xC];
    Rec  recs[8];
    u8   pad68[4];
    u16  h6C;
} Entry;

typedef struct Msg {
    Entry *e;
    u8     b4;
    u8     b5;
    u8     idx;
} Msg;

extern int UNION_CHARA_SetNextAction(char *p, char v);
extern u16 UNION_CHARA_MakeObjId(u8 *a, u8 *b);
extern void *UNION_CHARA_GetMmdl(void **a, u8 *b, u8 *c);
extern int UNION_MSG_GetCategoryTableValue(int i);
extern int func_0217F858(int a);
extern int FLDMMDL_CheckPossibleAcmd(int a0);
extern void FLDMMDL_SetAcmd(void *a0, u16 a1);
extern u16 FLDMMDL_GetMoveCode(void *p);
extern int FLDMMDL_ChangeMoveCode(int a0, int a1);

int UNION_CHARA_ActionIdle(u8 *w, Msg *m)
{
    Entry *e;
    u8 *s;
    int t;
    int v;
    void *r;

    s = w + 0x2830;
    e = m->e;
    if (e->h6C == 0) {
        UNION_CHARA_SetNextAction((char *)m, 2);
        return 1;
    }
    if (!e->recs[m->idx].valid || m->b4 != e->recs[m->idx].b6) {
        UNION_CHARA_SetNextAction((char *)m, 2);
        return 1;
    }
    t = func_0217F858(e->bB);
    if (((struct Obj12518 *)s)->f58 == UNION_CHARA_MakeObjId((u8 *)m->e, (u8 *)m)) {
        UNION_CHARA_SetNextAction((char *)m, 3);
        return 1;
    }
    v = s[2];
    if (v != 0 && (v == t || (t == 0 && v == e->kind)) && m->idx == 0
        && UNION_MSG_GetCategoryTableValue(e->bB) > e->n) {
        r = UNION_CHARA_GetMmdl((void **)w, (u8 *)m->e, (u8 *)m);
        if (FLDMMDL_CheckPossibleAcmd((int)r) == 1) {
            FLDMMDL_SetAcmd(r, 0x31);
        }
    } else if (m->idx == 0 && e->n > 1) {
        r = UNION_CHARA_GetMmdl((void **)w, (u8 *)m->e, (u8 *)m);
        if (FLDMMDL_GetMoveCode(r) == 2) {
            FLDMMDL_ChangeMoveCode((int)r, 0xF);
        }
    } else if (m->idx == 0 && e->n <= 1) {
        r = UNION_CHARA_GetMmdl((void **)w, (u8 *)m->e, (u8 *)m);
        if (FLDMMDL_GetMoveCode(r) == 0xF) {
            FLDMMDL_ChangeMoveCode((int)r, 2);
        }
    }
    return 0;
}
