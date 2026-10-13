/*
 * function: FLDEFF_SHADOW_Init
 * address:  0x021AC2F0
 * packet:   pkt_ov021_021AC2F0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 *   FIELD_EFFECT_UpdateObject  0x021AC178  thumb  ov021
 *   FIELD_EFFECT_GetObjectParam  0x021AC1AC  thumb  ov021
 *   FLDMMDL_GetCheckInfo  0x0216E1A4  thumb  ov010
 *   BILLBOARD_SetElemPolyId  0x0204F6DC  arm  arm9
 *   BILLBOARD_ACT_CreateEntries  0x02050340  arm  arm9
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct V3 { int x, y, z; } V3;

typedef struct Desc {
    u16 slot;
    u16 v12;
    u16 v14;
    u8 k;
    u8 pad;
    u32 flag;
    u32 w;
    V3 pos;
    void (*f1c)(void);
    u32 f20;
} Desc;

typedef struct Sys { u8 pad[0x10]; u32 f10; u32 f14; u32 f18; } Sys;
typedef struct Arg4 { u8 b0; } Arg4;

typedef struct P {
    u32 f0;
    Sys *sys;
    u32 f8;
    u16 fc[4];
    u32 f14;
} P;

struct BbActDesc;
struct BbActSys;
extern int FIELD_EFFECT_GetObjectParam(u32 a);
extern int FLDMMDL_GetCheckInfo(int a0, int a1);
extern u16 BILLBOARD_ACT_CreateEntries(struct BbActSys *o, u16 base, const struct BbActDesc *d, u32 count, u32 mode);
extern void FIELD_EFFECT_DeleteObject(u32 a);
extern void BILLBOARD_SetElemPolyId(u8 *a0, int i, u8 *px);
extern void FIELD_EFFECT_UpdateObject(u32 a);

void FLDEFF_SHADOW_Init(u32 a, P *p)
{
    u32 *q = (u32 *)FIELD_EFFECT_GetObjectParam(a);
    Arg4 t;
    Desc s;

    p->sys = (Sys *)q[0];
    p->f8 = q[1];
    FLDMMDL_GetCheckInfo(q[1], (int)p->fc);
    s.slot = 0;
    s.v12 = 0x1000;
    s.v14 = 0x1000;
    s.k = 0x13;
    s.flag = 1;
    s.w = 1;
    {
        V3 zero = {0, 0, 0};

        s.pos = zero;
    }
    s.f1c = 0;
    s.f20 = (u32)p;
    p->f14 = BILLBOARD_ACT_CreateEntries((struct BbActSys *)p->sys->f10, (u16)p->sys->f18, (const struct BbActDesc *)(&s), 1, 3);
    if (p->f14 == 0xFFFF) {
        FIELD_EFFECT_DeleteObject(a);
        return;
    }
    t.b0 = 2;
    BILLBOARD_SetElemPolyId((u8 *)p->sys->f14, p->f14, (u8 *)(&t));
    FIELD_EFFECT_UpdateObject(a);
}
