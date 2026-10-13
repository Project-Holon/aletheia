/*
 * function: FLDEFF_REFLECT_UpdateTask
 * address:  0x021BC048
 * packet:   pkt_ov021_021BC048
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_CheckCheckInfo  0x0216E1C4  thumb  ov010
 *   FLDMMDL_CheckMoveBitReflect  0x0216DC34  thumb  ov010
 *   FLDMMDL_CallDrawGetProc  0x0216D7A8  thumb  ov010
 *   FLDMMDL_GetObjCodeParam  0x0216E3C4  thumb  ov010
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 *   FLDMMDL_BLACT_AddActorPosOrReserve  0x0219C928  thumb  ov021
 *   FLDMMDL_BLACT_GetActorSize  0x0219C9E0  thumb  ov021
 *   FLDEFF_REFLECT_UpdateActor  0x021BC138  thumb  ov021
 *
 * The zeroed V3 is a block-scope declaration with an initialiser: that is
 * what materialises `add r6, sp, #0xc` before the three stores and keeps r6
 * across the FLDMMDL_GetObjCodeParam call (plain element stores fold to sp-relative).
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int x, y, z; } V3;

typedef struct Obj {
    int f0;
    int f4;
    int f8;
    int fC;
    u8 b10;
    u8 b11;
    u8 pad12[0x1c - 0x12];
    u32 f1c;
    u32 f20;
    u8 pad24[4];
    u16 h28;
    u16 h2a;
    u8 f2c[4];
} Obj;

extern int FLDMMDL_CheckCheckInfo(int a0, int a1);
extern int FLDMMDL_CheckMoveBitReflect(void *a0);
extern int FLDMMDL_CallDrawGetProc(void *p, unsigned int v);
extern void *FLDMMDL_GetObjCodeParam(void *p);
extern u32 FIELD_EFFECT_DeleteObject(u32 a);
extern int FLDMMDL_BLACT_AddActorPosOrReserve(u32 a, const u8 *b, u16 *c, V3 *d, u32 s0, u32 s1);
extern void FLDMMDL_BLACT_GetActorSize(u32 a, u16 *b, u16 *c);
extern void FLDEFF_REFLECT_UpdateActor(void);

void FLDEFF_REFLECT_UpdateTask(u32 a0, Obj *p)
{
    u16 s[2];
    int h;

    if (FLDMMDL_CheckCheckInfo(p->f1c, (int)p->f2c) == 0 || FLDMMDL_CheckMoveBitReflect((void *)p->f1c) == 0) {
        FIELD_EFFECT_DeleteObject(a0);
        return;
    }
    h = FLDMMDL_CallDrawGetProc((void *)p->f1c, 0);
    if (p->b10 == 0) {
        if (h == 0xFFFF) return;
        {
            V3 v = {0, 0, 0};
            FLDMMDL_BLACT_AddActorPosOrReserve(p->f20, FLDMMDL_GetObjCodeParam((void *)p->f1c), &p->h28, &v,
                          (u32)FLDEFF_REFLECT_UpdateActor, (u32)p);
        }
        p->b10 = 1;
    }
    if (p->h2a == 0xFFFF) return;
    if (p->b11 == 0) {
        int t;
        FLDMMDL_BLACT_GetActorSize(p->f1c, &s[1], &s[0]);
        t = s[1];
        p->f0 = t;
        p->f4 = s[0];
        p->f8 = t;
        p->b11 = 1;
    }
    p->f8 += p->fC;
    if (p->f8 >= p->f0 + 0x400) {
        p->f8 = p->f0 + 0x400;
        p->fC = -p->fC;
        return;
    }
    if (p->f8 <= p->f0 - 0x400) {
        p->f8 = p->f0 - 0x400;
        p->fC = -p->fC;
    }
}
