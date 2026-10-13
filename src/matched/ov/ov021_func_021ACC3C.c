/*
 * function: FLDEFF_NAMIPOKE_Init
 * address:  0x021ACC3C
 * packet:   pkt_ov021_021ACC3C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_EFFECT_GetObjectParam  0x021AC1AC  thumb  ov021
 *   FIELD_EFFECT_SetObjectPos  0x021AC1CC  thumb  ov021
 *   FIELD_EFFECT_GetFieldMapData  0x021ABE18  thumb  ov021
 *   FIELD_EFFECT_GetObjectMode  0x021AC1A0  thumb  ov021
 *   FIELD_EFFECT_UpdateObject  0x021AC178  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19874.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Blk { u32 w[7]; } Blk;
typedef struct Inner { u16 a; u16 b; u8 pad[0x18]; u16 c; u16 pad2; u32 d, e, f; } Inner;
typedef struct B {
    u8 pad0[9];
    u8 f9;
    u8 pad1[2];
    u16 fc;
    u8 pad2[2];
    u32 f10;
    u32 f14;
    u16 f18;
    u8 pad3[2];
    Blk blk;
    Inner in;
} B;

extern int FIELD_EFFECT_GetObjectParam(u32 a);
extern void FIELD_EFFECT_SetObjectPos(u32 a, u8 *b);
extern u32 FIELD_EFFECT_GetFieldMapData(u8 *p);
extern int FIELD_EFFECT_GetObjectMode(u32 a);
extern void FIELD_EFFECT_UpdateObject(u32 a);

void FLDEFF_NAMIPOKE_Init(u32 a, B *b)
{
    u8 *p = (u8 *)FIELD_EFFECT_GetObjectParam(a);
    Inner *q;
    u32 k = 0x1000;
    b->blk = *(Blk *)p;
    FIELD_EFFECT_SetObjectPos(a, p + 0x10);
    b->fc = ((struct Obj19874 *)p)->fC;
    FIELD_EFFECT_GetFieldMapData((u8 *)(*(u32 *)b->blk.w[0]));
    b->f18 = *(u16 *)(b->blk.w[0] + 8);
    b->f9 = FIELD_EFFECT_GetObjectMode(a);
    b->f10 = k;
    b->f14 = k >> 2;
    q = &b->in;
    q->c = *(u16 *)(b->blk.w[0] + 0xa);
    b->in.a = 1;
    q->b = 9;
    q->d = k;
    q->e = k;
    q->f = k;
    FIELD_EFFECT_UpdateObject(a);
}
