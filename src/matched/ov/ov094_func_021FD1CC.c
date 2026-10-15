/*
 * function: BTLV_EFFVM_ParticleStartCallback
 * address: 0x021FD1CC
 * packet: pkt_ov094_021FD1CC
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 *
 * 2026-10-02: the kind == 4 swap closed. It is a per-axis swap through
 * temps from a (tx = a.x; a.x = b.x; ...), then the sums read the new a:
 * b.x = tx + a.x. Grouped temps, temps from b and `b.x = b.x + tx` all
 * leave the spill on old b.y or the add operands reversed.
 * symbols:
 *   func_02051774 0x02051774 arm
 *   BTLV_EFFVM_ResolveSideFromVm 0x021FD070 thumb ov094
 *   BTLV_EFFVM_ResolveSlotKey 0x021FCF2C thumb ov094
 *   BTLV_EFFVM_ResolveAnchorSlot 0x021FD088 thumb ov094
 *   BTLV_EFFECT_GetMcss 0x021F8694 thumb ov094
 *   BTLV_EFFECT_GetMode 0x021F8710 thumb ov094
 *   BTLV_MCSS_GetSlotPositionForRule 0x021FF3FC thumb ov094
 *   BTLV_MCSS_GetSlotPosition 0x021FF3F4 thumb ov094
 *   BTLV_EFFVM_TransformVecByMtx44 0x021FE1B8 thumb ov094
 *   BTLV_EFFVM_ParticleMotionStep 0x021FD8CC thumb ov094
 *   VM_GetUserData 0x02011324 thumb
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   BUTTON_MAN_SetUserData 0x02051A2C arm
 *   BUTTON_MAN_SetCallback 0x02051A24 arm
 *   func_0207C768 0x0207C768 arm
 *   VEC_Distance 0x0207CF3C arm
 *   VEC_Normalize 0x0207CCA4 arm
 *   VEC_DotProduct 0x0207CA68 arm
 *   FX_AcosIdx 0x0207D184 arm
 *   VEC_CrossProduct 0x0207CAE8 arm
 *   MTX_RotAxis43 0x0207B65C arm
 *   MTX_MultVec43 0x0207BC08 arm
 *   BUTTON_MAN_SetRow2 0x020519C4 arm
 *   BUTTON_MAN_SetRow5 0x02051A04 arm
 *   BUTTON_MAN_GetRot 0x020517B4 arm
 *   BUTTON_MAN_SetRow3Half 0x020519E4 arm
 *   BUTTON_MAN_SetRot 0x02051880 arm
 *   BUTTON_MAN_GetScaleX 0x020517D0 arm
 *   BUTTON_MAN_GetAlpha 0x02051830 arm
 *   BUTTON_MAN_GetAngle 0x02051820 arm
 *   BUTTON_MAN_GetScaleY 0x020517E0 arm
 *   BUTTON_MAN_SetScaleX 0x020517D8 arm
 *   BUTTON_MAN_SetScaleY 0x020517E8 arm
 *   BUTTON_MAN_SetAlpha 0x020518A4 arm
 *   BUTTON_MAN_SetAngle 0x0205189C arm
 *   BUTTON_MAN_GetPos 0x02051790 arm
 *   BUTTON_MAN_SetPos 0x020517A4 arm
 *   BUTTON_MAN_GetOffsetX 0x020517F0 arm
 *   BUTTON_MAN_SetOffsetX 0x02051800 arm
 *   BUTTON_MAN_GetOffsetY 0x02051808 arm
 *   BUTTON_MAN_SetOffsetY 0x02051818 arm
 *   BUTTON_MAN_SetEmitterPos 0x02051838 arm
 *   _ll_mul 0x0209C054 arm
 *   d_0220AE68 0x0220AE68 data
 *   FX_SinCosTable_ 0x020A1B38 data
 */
#include "../include/Obj07881.h"
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef long long s64;
typedef struct { int x, y, z; } Vec;
typedef struct { s16 x, y, z; } Vec16;
typedef struct { int m[12]; } Mtx;
typedef struct { u16 on; Vec16 dir; } Dir;
typedef struct {
    int vm;         /* 0x00 */
    int k1;         /* 0x04 */
    int k2;         /* 0x08 */
    Vec ofs;        /* 0x0c */
    int f18;        /* 0x18 */
    int f1c;        /* 0x1c */
    int kind;       /* 0x20 */
    int f24;        /* 0x24 */
    Vec pa;         /* 0x28 */
    Vec pb;         /* 0x34 */
    int mode;       /* 0x40 */
    int f44;        /* 0x44 */
    int f48;        /* 0x48 */
    int f4c;        /* 0x4c */
    int f50;        /* 0x50 */
    int f54;        /* 0x54 */
    int flip;       /* 0x58 */
} Rec;
typedef struct {
    int m[9];       /* 0x00 */
    Vec pos;        /* 0x24 */
    int f30;        /* 0x30 */
    int f34;        /* 0x34 */
    int f38;        /* 0x38 */
    int f3c;        /* 0x3c */
    int f40;        /* 0x40 */
    int f44;        /* 0x44 */
    int f48;        /* 0x48 */
    int f4c;        /* 0x4c */
    int f50;        /* 0x50 */
    int f54;        /* 0x54 */
    int f58;        /* 0x58 */
    int f5c;        /* 0x5c */
} Obj;
extern char d_0220AE68[];
extern const s16 FX_SinCosTable_[];
struct Obj;
struct S12;
struct Vec3;
extern u32 func_02051774(void);
extern int BTLV_EFFVM_ResolveSideFromVm(int a, int b);
extern int BTLV_EFFVM_ResolveSlotKey(int a, int idx);
extern int BTLV_EFFVM_ResolveAnchorSlot(int a, int *out);
struct ScriptVm;
extern int BTLV_EFFECT_GetMcss(void);
extern int BTLV_EFFECT_GetMode(void);
extern void BTLV_MCSS_GetSlotPositionForRule(const Vec *def, Vec *out, int idx, int kind);
extern void BTLV_MCSS_GetSlotPosition(void *obj, void *out, int idx);
extern void BTLV_EFFVM_TransformVecByMtx44(Vec *v, const Vec *ofs);
extern void BTLV_EFFVM_ParticleMotionStep(void *p, int active);
extern void *VM_GetUserData(struct ScriptVm *vm);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void BUTTON_MAN_SetUserData(void *p, int v);
extern void BUTTON_MAN_SetCallback(void *p, int v);
extern u32 func_0207C768(u32 a, u32 b);
extern int VEC_Distance(const Vec *a, const Vec *b);
extern void VEC_Normalize(const Vec *a, Vec *b);
extern int VEC_DotProduct(const Vec *a, const Vec *b);
extern u16 FX_AcosIdx(int a);
extern void VEC_CrossProduct(const Vec *a, const Vec *b, Vec *c);
extern void MTX_RotAxis43(void *m, const Vec *axis, int s, int c);
extern void MTX_MultVec43(const Vec *a, const void *m, Vec *out);
extern void BUTTON_MAN_SetRow2(void *p, struct S12 *q);
extern void BUTTON_MAN_SetRow5(void *p, struct S12 *q);
extern void BUTTON_MAN_GetRot(void *p, Vec16 *v);
extern void BUTTON_MAN_SetRow3Half(void *p, u16 *q);
extern void BUTTON_MAN_SetRot(struct Obj *o, const struct Vec3 *v);
extern int BUTTON_MAN_GetScaleX(char *p);
extern unsigned short BUTTON_MAN_GetAlpha(char *p);
extern short BUTTON_MAN_GetAngle(char *p);
extern int BUTTON_MAN_GetScaleY(char *p);
extern void BUTTON_MAN_SetScaleX(char *p, int v);
extern void BUTTON_MAN_SetScaleY(char *p, int v);
extern void BUTTON_MAN_SetAlpha(struct Obj *o, u16 v);
extern void BUTTON_MAN_SetAngle(struct Obj *o, u32 v);
extern void BUTTON_MAN_GetPos(void *p, Vec *v);
extern void BUTTON_MAN_SetPos(void *p, const Vec *v);
extern short BUTTON_MAN_GetOffsetX(char *p);
extern void BUTTON_MAN_SetOffsetX(char *p, int v);
extern short BUTTON_MAN_GetOffsetY(char *p);
extern void BUTTON_MAN_SetOffsetY(char *p, int v);
extern void BUTTON_MAN_SetEmitterPos(void *p, const Vec *v);
#define MUL(a, b) ((int)(((s64)(a) * (b) + 0x800) >> 12))

void BTLV_EFFVM_ParticleStartCallback(void *p)
{
    Vec a;
    Vec b;
    Vec c;
    Vec axis;
    Vec d;
    Vec e;
    Mtx m;
    Vec v1;
    Vec v2;
    Vec axis2;
    Vec sc;
    Dir dir;
    Rec *r;
    int flip;
    char *s;
    Obj *o;
    u16 ang;
    int t0, t1, t2, t3;
    int n;
    int tx, ty, tz;

    r = (Rec *)func_02051774();
    flip = r->flip;
    switch (r->k1) {
    case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
        r->k1 = BTLV_EFFVM_ResolveSideFromVm(r->vm, r->k1);
        break;
    case 9:
    case 11:
        r->k1 = BTLV_EFFVM_ResolveSlotKey(r->vm, r->k1 + 5);
        break;
    case 8:
        a.x = r->pa.x;
        a.y = r->pa.y;
        a.z = r->pa.z;
        break;
    case 14: case 15: case 16: case 17:
        BTLV_MCSS_GetSlotPositionForRule((const Vec *)BTLV_EFFECT_GetMcss(), &a, r->k1 - 12, 1);
        r->k1 = -1;
        break;
    case 18: case 19: case 20: case 21:
        BTLV_MCSS_GetSlotPositionForRule((const Vec *)BTLV_EFFECT_GetMcss(), &a, r->k1 - 16, 1);
        switch (r->k1) {
        case 18: a.z += 0x1a00; break;
        case 19: a.z += 0x2600; break;
        case 20: a.z += 0x600; break;
        case 21: a.z += 0x3900; break;
        }
        r->k1 = -1;
        break;
    }
    if (r->k1 != -1 && r->k1 != 8)
        BTLV_MCSS_GetSlotPosition((void *)BTLV_EFFECT_GetMcss(), &a, r->k1);
    switch (r->k2) {
    case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
        r->k2 = BTLV_EFFVM_ResolveSideFromVm(r->vm, r->k2);
        break;
    case 9:
        r->k2 = BTLV_EFFVM_ResolveSlotKey(r->vm, r->k2 + 5);
        break;
    case 10:
        flip = 1;
        r->k2 = BTLV_EFFVM_ResolveSlotKey(r->vm, r->k2 + 4);
        break;
    case 12:
        flip = 1;
    case 11:
        n = BTLV_EFFVM_ResolveAnchorSlot(r->vm, &r->k2);
        BTLV_MCSS_GetSlotPositionForRule((const Vec *)BTLV_EFFECT_GetMcss(), &b, r->k2, n);
        r->k2 = -1;
        break;
    case 8:
        b.x = r->pb.x;
        b.y = r->pb.y;
        b.z = r->pb.z;
        break;
    case 14: case 15: case 16: case 17:
        BTLV_MCSS_GetSlotPositionForRule((const Vec *)BTLV_EFFECT_GetMcss(), &b, r->k2 - 12, 1);
        r->k2 = -1;
        break;
    case 18: case 19: case 20: case 21:
        BTLV_MCSS_GetSlotPositionForRule((const Vec *)BTLV_EFFECT_GetMcss(), &b, r->k2 - 16, 1);
        switch (r->k1) {
        case 18: b.z += 0x1a00; break;
        case 19: b.z += 0x2600; break;
        case 20: b.z += 0x600; break;
        case 21: b.z += 0x3900; break;
        }
        r->k2 = -1;
        break;
    }
    if (r->k2 != -1 && r->k2 != 8)
        BTLV_MCSS_GetSlotPosition((void *)BTLV_EFFECT_GetMcss(), &b, r->k2);
    BTLV_EFFECT_GetMode();
    a.z += 0x500;
    b.z += 0x500;
    if ((u32)(r->mode - 1) <= 1) {
        BTLV_EFFVM_TransformVecByMtx44(&a, &r->ofs);
        BTLV_EFFVM_TransformVecByMtx44(&b, &r->ofs);
    } else if (r->mode == 3) {
        c.x = a.x;
        c.y = a.y;
        c.z = a.z;
        a.y += r->ofs.y;
        BTLV_EFFVM_TransformVecByMtx44(&c, &r->ofs);
    } else {
        a.y += r->ofs.y;
    }
    b.y += r->ofs.y;
    if (r->kind != 0) {
        s = VM_GetUserData((struct ScriptVm *)r->vm);
        *(Obj **)(s + 0x1f4 + ((struct Obj07881 *)s)->f234 * 4) = func_02030734((u16)((((struct Obj07881 *)s)->f238 & 0x7fff) | 0x8000), 0x60, 0, d_0220AE68, 0x194a);
        o = *(Obj **)(s + 0x1f4 + ((struct Obj07881 *)s)->f234 * 4);
        BUTTON_MAN_SetUserData(p, (int)o);
        BUTTON_MAN_SetCallback(p, (int)BTLV_EFFVM_ParticleMotionStep);
        ((struct Obj07881 *)s)->f234 += 1;
        o->f38 = 0;
        o->f50 = 0;
        o->f54 = 0;
        o->f58 = 0;
        o->f4c = r->kind;
        o->f48 = r->f24 >> 12;
        o->f5c = r->mode;
        if (r->kind == 3) {
            o->f40 = func_0207C768(0x6000000, r->f24);
        } else if ((u32)(r->kind - 5) <= 1) {
            o->f40 = func_0207C768(0x8000000, r->f24);
            o->f44 = func_0207C768(0x10000000, r->f24);
            o->f44 = MUL(o->f44, r->f54);
        } else {
            o->f40 = func_0207C768(0x8000000, r->f24);
        }
        if (o->f40 == 0)
            o->f40 = 1;
        o->f30 = VEC_Distance(&a, &b) / 2;
        if (r->kind == 1 || r->kind == 4)
            o->f34 = 0;
        else
            o->f34 = r->f1c;
        if (r->kind == 4) {
            tx = a.x;
            a.x = b.x;
            ty = a.y;
            a.y = b.y;
            tz = a.z;
            a.z = b.z;
            b.x = tx + a.x;
            b.y = ty + a.y;
            b.z = tz + a.z;
        }
        d.x = b.x - a.x;
        d.y = b.y - a.y;
        d.z = b.z - a.z;
        VEC_Normalize(&d, &d);
        e.x = 0x1000;
        e.y = 0;
        e.z = 0;
        ang = FX_AcosIdx(VEC_DotProduct(&e, &d));
        VEC_CrossProduct(&e, &d, &axis);
        VEC_Normalize(&axis, &axis);
        MTX_RotAxis43(o, &axis, FX_SinCosTable_[(ang >> 4) * 2], FX_SinCosTable_[(ang >> 4) * 2 + 1]);
        o->pos.x = a.x;
        o->pos.y = a.y;
        o->pos.z = a.z;
    }
    if (r->k1 != 8 && r->k2 != 8 && r->k1 != r->k2) {
        dir.on = 2;
        b.x -= a.x;
        b.y -= a.y;
        b.z -= a.z;
        BUTTON_MAN_SetRow2(p, (struct S12 *)(&b));
        BUTTON_MAN_SetRow5(p, (struct S12 *)(&b));
        v2.x = b.x;
        v2.y = 0;
        v2.z = b.z;
        BUTTON_MAN_GetRot(p, &dir.dir);
        v1.x = dir.dir.x;
        v1.y = 0;
        v1.z = dir.dir.z;
        VEC_Normalize(&v1, &v1);
        VEC_Normalize(&v2, &v2);
        ang = FX_AcosIdx(VEC_DotProduct(&v1, &v2));
        VEC_CrossProduct(&v1, &v2, &axis2);
        VEC_Normalize(&axis2, &axis2);
        MTX_RotAxis43(&m, &axis2, FX_SinCosTable_[(ang >> 4) * 2], FX_SinCosTable_[(ang >> 4) * 2 + 1]);
        v1.x = dir.dir.x;
        v1.y = dir.dir.y;
        v1.z = dir.dir.z;
        MTX_MultVec43(&v1, &m, &v1);
        VEC_Normalize(&v1, &v1);
        if (flip == 1) {
            v1.x *= -1;
            v1.z *= -1;
        }
        dir.dir.x = v1.x;
        dir.dir.y = v1.y;
        dir.dir.z = v1.z;
        if (ang < 0x2000 || (ang > 0x6000 && ang < 0xa000) || ang > 0xe000)
            dir.on = 0;
        BUTTON_MAN_SetRow3Half(p, (u16 *)(&dir));
        BUTTON_MAN_SetRot(p, (const struct Vec3 *)(&dir.dir));
    }
    if ((r->mode != 0 && (r->k1 & 1)) || r->mode == 0 || (u32)(r->mode - 2) <= 1) {
        t0 = BUTTON_MAN_GetScaleX(p);
        t1 = BUTTON_MAN_GetAlpha(p) << 12;
        t2 = BUTTON_MAN_GetAngle(p);
        t3 = BUTTON_MAN_GetScaleY(p);
        if (r->f44 != 0) {
            BUTTON_MAN_SetScaleX(p, MUL(t0, r->f44));
            BUTTON_MAN_SetScaleY(p, MUL(t3, r->f44));
        }
        if (r->f48 != 0)
            BUTTON_MAN_SetAlpha(p, (u16)(MUL(t1, r->f48) >> 12));
        if (r->f4c != 0)
            BUTTON_MAN_SetAngle(p, (s16)MUL(t2, r->f4c));
        if (r->f50 != 0) {
            BUTTON_MAN_GetPos(p, &sc);
            sc.x = MUL(sc.x, r->f50);
            sc.y = MUL(sc.y, r->f50);
            sc.z = MUL(sc.z, r->f50);
            BUTTON_MAN_SetPos(p, &sc);
            t0 = BUTTON_MAN_GetOffsetX(p);
            BUTTON_MAN_SetOffsetX(p, (s16)MUL(t0, r->f50));
            t0 = BUTTON_MAN_GetOffsetY(p);
            BUTTON_MAN_SetOffsetY(p, (s16)MUL(t0, r->f50));
        }
    }
    if (r->mode == 3)
        BUTTON_MAN_SetEmitterPos(p, &c);
    else
        BUTTON_MAN_SetEmitterPos(p, &a);
    func_020307B0(r);
}
