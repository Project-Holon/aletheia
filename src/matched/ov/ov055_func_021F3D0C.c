/*
 * function: CROWD_StartPerson
 * address:  0x021F3D0C
 * packet:   pkt_ov055_021F3D0C
 * region:   ov055
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_SetStatusBitVanish  0x0216DAC8  thumb  ov010
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   FLDMMDL_InitPosRecord  0x0216E618  thumb  ov010
 *   FLDMMDL_ChangeHeader  0x0216E0AC  thumb  ov010
 *   FLDMMDL_SetMoveBitAttrEffectOff  0x0216DCCC  thumb  ov010
 *   gCrowdMmdlHeader     0x021F4620  data  ov055  a4
 *   gCrowdPersonInitFuncs     0x021F45C8  data  ov055  a4
 */

#include "../include/G_V.h"

typedef unsigned char u8;
typedef unsigned short u16;

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

extern struct V gCrowdMmdlHeader;
extern void (* const gCrowdPersonInitFuncs[])(O *);

extern void FLDMMDL_SetStatusBitVanish(unsigned int *p, unsigned int v);
extern u16 FLDMMDL_GetObjCode(void *p);
extern void FLDMMDL_InitPosRecord(V *, int, int, int);
extern void FLDMMDL_ChangeHeader(void *a0, void *a1);
extern int FLDMMDL_SetMoveBitAttrEffectOff(void *a0, int a1);

void CROWD_StartPerson(O *o, int a1, int a2, int idx, u16 p4, u16 p5, u16 p6, u16 p7, void *p8)
{
    V v;

    o->f0 = 1;
    FLDMMDL_SetStatusBitVanish((unsigned int *)o->fc, 0);
    v = gCrowdMmdlHeader;
    v.h2 = FLDMMDL_GetObjCode((void *)o->fc);
    v.hc = p6;
    v.h0 = o->h8;
    FLDMMDL_InitPosRecord(&v, p4, p5, 0);
    FLDMMDL_ChangeHeader((void *)o->fc, &v);
    o->f2 = idx;
    o->f3 = p6;
    o->f1 = 0;
    o->h4 = p7;
    o->h14 = 0;
    o->h16 = 0;
    FLDMMDL_SetMoveBitAttrEffectOff((void *)o->fc, 1);
    o->f10 = p8;
    gCrowdPersonInitFuncs[idx](o);
}
