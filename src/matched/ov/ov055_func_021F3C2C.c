/*
 * function: CROWD_CreatePerson
 * address:  0x021F3C2C
 * packet:   pkt_ov055_021F3C2C
 * region:   ov055
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The pool carries 0x021F4620 twice (0x021F3CDC, 0x021F3CE0): the store and
 * the call argument name it through two externs.
 *
 * symbols:
 *   func_020056EC  0x020056EC  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   gCrowdMmdlHeader     0x021F4620  data  ov055  a4
 *   d_021F4620_b   0x021F4620  data  ov055  a4
 *   FLDMMDL_AddMmdl  0x0216CE60  thumb  ov010
 *   CROWD_GetWalkCmdBase  0x021F40F4  thumb  ov055
 *   FLDMMDL_SetStatusBitVanish  0x0216DAC8  thumb  ov010
 *   FLDMMDL_SetMoveBitAttrEffectOff  0x0216DCCC  thumb  ov010
 *   FLDMMDL_SetDrawOffset  0x0216D8C0  thumb  ov010
 */

#include "../include/G_V.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct V V;

typedef struct O {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    u16 h4;
    u16 h6;
    u16 h8;
    u16 ha;
    int fc;
    void *f10;
    u16 h14;
    u16 h16;
} O;

typedef struct Ent {
    int key;
    u16 h[6];
} Ent;

typedef struct T {
    u8 pad0[0xd];
    u8 n;
    u16 h[21];
    Ent *f38;
    u32 f3c;
} T;

extern struct V gCrowdMmdlHeader;
extern struct V d_021F4620_b;

extern u32 func_020056EC(u32);
extern int FLDMMDL_AddMmdl(int, void *, int);
extern u32 CROWD_GetWalkCmdBase(u8 *p);
extern void FLDMMDL_SetStatusBitVanish(unsigned int *p, unsigned int v);
extern int FLDMMDL_SetMoveBitAttrEffectOff(void *a0, int a1);
extern void FLDMMDL_SetDrawOffset(int, int *);

void CROWD_CreatePerson(O *o, int a, int b, const T *s, int i)
{
    u32 k;
    u32 r;
    u16 x;

    k = 0;
    x = s->h[func_020056EC(0) % s->n];
    gCrowdMmdlHeader.h2 = x;
    r = func_020056EC(0);
    o->h8 = i + 0x30;
    for (k = 0; k < s->f3c; k++) {
        if (x == s->f38[k].key) {
            o->h6 = s->f38[k].h[r % 6];
            break;
        }
    }
    o->fc = FLDMMDL_AddMmdl(a, &d_021F4620_b, b);
    o->f0 = 0;
    o->f1 = 0;
    o->f2 = 0;
    o->f3 = 0;
    o->ha = CROWD_GetWalkCmdBase((u8 *)s);
    FLDMMDL_SetStatusBitVanish((unsigned int *)o->fc, 1);
    FLDMMDL_SetMoveBitAttrEffectOff((void *)o->fc, 1);
    {
        int v[3] = {0, 0, 0};
        v[0] = func_020056EC(0x8000) - 0x4000;
        FLDMMDL_SetDrawOffset(o->fc, v);
    }
}
