/*
 * file:     btlv_clact.c
 * unit:     yes
 * function: func_02201A8C, func_02201AC4, func_02201AF0, func_02201AF8, func_02201B20, func_02201CA4, func_02201CD0, func_02201D5C, func_02201DA0, func_02201DB4, func_02201E04, func_02201F98, func_02201FD8, func_02201FF4, func_0220203C
 * address:  0x02201A8C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from btlv_effvm.c, btlv_b_gauge.c, btlv_bg.c, btlv_finger_cursor.c by tools/splitfile.py.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   func_0207C768  0x0207C768  arm
 *   func_02030DA8  0x02030DA8  arm
 *   PALANM_RequestFade  0x0202173C  thumb
 *   TCBL_GetTaskUserData   0x02030EE8  arm
 *   func_02030734  0x02030734  arm
 *   d_0220AE88  0x0220AE88  data  a4
 *   CLACT_DrawSystem  0x0204A600  arm
 *   d_0220A368 0x0220A368 data a4
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_GetPaletteVramAddress 0x0204AEF4 arm
 *   PALANM_LoadArcPaletteToSlot 0x02021640 thumb
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_CreateAffineActor 0x0204B324 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   CLACT_SetActorAffineMode  0x0204B570  arm
 *   CLACT_SetActorScale  0x0204B5AC  arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   func_021F86E0 0x021F86E0 thumb ov094
 *   func_021F86D4 0x021F86D4 thumb ov094
 *   func_021F896C 0x021F896C thumb ov094
 *   func_021F89BC 0x021F89BC thumb ov094
 *   func_021F918C 0x021F918C thumb ov094
 *   func_021F9260  0x021F9260  thumb  ov094
 */
#include "../../matched/include/Obj03216.h"
#include "../../matched/include/Obj07895.h"
#include "../../matched/include/Obj21735.h"
#include "../../matched/include/Obj21736.h"
#include "btlv_effvm_types.h"
#include "btlv_camera_shared_types.h"
#include "btlv_effect_shared_types.h"
#include "btlv_effvm_shared_types.h"
#include "btlv_clact_shared_types.h"

typedef struct Config { s16_02201B20 x, y; u32 rest[2]; u32 a, b, last; } Config;

typedef struct {
    int x, y, z;
} Vec_v1B20;

typedef struct { void *owner; Vec start; int idx, mode; Vec a, b, delta; int n1, n2, zero, s2, s3; } Job;

extern u32 func_020307B0(void *p);

extern u32 func_0207C768(u32 a, u32 b);

extern void *func_02030DA8(void *owner, void (*fn)(void *, void *), void *p, u32 n);

extern int PALANM_RequestFade(void *p, u16 mask, u16 col, s16_021F6560 step, u8 b, u8 c, u16 d, void *ctx);

extern u32 TCBL_GetTaskUserData(struct S02030EE8 *p);

extern u32 TCBL_GetTaskUserData(struct S02030EE8 *p);

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern float _fflt(int);

extern float _fadd(float, float);

extern float _fsub(float, float);

extern int _ffix(float);

extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);

extern unsigned int CLACT_DeleteUnit(struct Bank *bank);

void CLACT_DrawSystem(void);

extern void *func_020490F4(u32 id, u32 heap);

extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);

extern int CLACT_RegisterPaletteCompressed(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);

extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);

extern int CLACT_GetPaletteVramAddress(u32 idx, u32 alternate);

extern void PALANM_LoadArcPaletteToSlot(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);

extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);

extern struct Obj *CLACT_CreateAffineActor(u32 owner, u32 i, u32 j, u32 k, u32 e, u16 f, u16 g);

extern void CLACT_SetActorAutoAnim(struct Obj *, unsigned int);

extern void ARC_TOOL_DeleteHandle(void *);

extern void CLACT_ReleaseCharacter(u32 i);

extern void CLACT_ReleasePalette(u32 i);

extern void CLACT_ReleaseCellAnim(u32 i);

extern void CLACT_DeleteActor(struct Obj *p);

extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);

extern u32 CLACT_SetActorAnimSeq(void *obj, u16 v);

extern void CLACT_AddActorSurfacePos(struct Obj_02201DA0 *p, const struct Vec2 *delta, u32 which);

extern void CLACT_SetActorAffineMode(struct Actor *actor, u32 value);

extern void CLACT_SetActorScale(struct Obj_02201DA0 *dst, struct Pair_02201B20 *src);

void *func_021F86D4(void);

int func_021F86E0(void);

void func_021F896C(void *h, void (*cb)(void *), int arg);

void func_021F89BC(void *h);

void func_021F918C(const VecFx32_021F8F30 *a, const VecFx32_021F8F30 *b, VecFx32_021F8F30 *out, fx32 div);

int func_021F9260(Mover_v8204 *m, VecFx32_021F8F30 *out);

Res_02201894 *func_02201A8C(void *owner, u16 heap);

void func_02201AC4(Res_02201AC4 *r);

void func_02201AF0(void *a0);

int func_02201AF8(int a, int b, int c, short d, short e, int f, int g);

int func_02201B20(char *p, u32 archiveId, int a, u32 b, int c, int d, s16_02201B20 x, s16_02201B20 y, u32 e, u32 f);

void func_02201CA4(Res_02201B20 *r, int i);

void func_02201CD0(char *o, int idx, int c, s16_02201B20 *p, int s1, int s2, int s3);

void func_02201D5C(char *o, int idx, int c, void *d, int s1, int s2, int s3);

u32 func_02201DA0(char *p, int i, int v);

void func_02201DB4(char *base, int idx, u8 b, u8 c, s8 step, u16 d);

void func_02201E04(char *o, int idx, u32 mode, Vec *v, Vec *w, int s1, int s2, int s3, void (*f1)(void *, void *), void (*f2)(void *));

void func_02201F98(void *a, void *b);

void func_02201FD8(void *h);

void func_02201FF4(void *a, void *b);

void func_0220203C(void *h);

extern const char d_0220AE88[];

extern const Config d_0220A368;

Res_02201894 *func_02201A8C(void *owner, u16 heap)
{
    Res_02201894 *r = func_02030734(heap, 0x84, 1, d_0220AE88, 0x4f);
    r->owner = owner;
    r->heap = heap;
    r->h = CLACT_CreateUnit(7, 0, heap);
    return r;
}

void func_02201AC4(Res_02201AC4 *r)
{
    int i;
    for (i = 0; i < 7; i++) {
        if (r->e[i].h8 != 0)
            func_02201CA4((Res_02201B20 *)((struct Res *)r), i);
    }
    CLACT_DeleteUnit(r->h);
    func_020307B0(r);
}

void func_02201AF0(void *a0)
{
    CLACT_DrawSystem();
}

int func_02201AF8(int a, int b, int c, short d, short e, int f, int g)
{
    return func_02201B20((char *)a, b, c, c + 1, c + 2, c + 3, d, e, f, g);
}

int func_02201B20(char *p, u32 archiveId, int a, u32 b, int c, int d, s16_02201B20 x, s16_02201B20 y, u32 e, u32 f)
{
    Config cfg = d_0220A368;
    void *archive = func_020490F4(archiveId, (u16)((((struct Obj03216 *)p)->f80 & 0x7fff) | 0x8000));
    int i, off;
    void *slots;
    u32 pal;
    for (i = 0; i < 7; i++) {
        if (*(u32 *)(p + i * 16 + 8) == 0) break;
    }
    off = i * 16;
    *(int *)(p + 12 + off) = CLACT_RegisterCharacter(archive, a, 0, 0, ((struct Obj03216 *)p)->f80);
    *(int *)(p + 16 + off) = CLACT_RegisterPaletteCompressed(archive, b, 0, (u16)(i * 32 + 0x140), ((struct Obj03216 *)p)->f80);
    *(int *)(p + 20 + off) = CLACT_RegisterCellAnim(archive, c, d, ((struct Obj03216 *)p)->f80);
    slots = (void *)func_021F86E0();
    pal = CLACT_GetPaletteVramAddress(*(int *)(p + 16 + off), 0);
    PALANM_LoadArcPaletteToSlot(slots, archiveId, b, ((struct Obj03216 *)p)->f80, 2, 32, (pal & 0x3ff) >> 1);
    cfg.x = x;
    cfg.y = y;
    if (e == 0 && f == 0) {
        *(u32 *)(p + 8 + off) = (u32)CLACT_CreateActor((void *)((struct Obj03216 *)p)->f4, *(u32 *)(p + 12 + off), *(u32 *)(p + 16 + off), *(u32 *)(p + 20 + off), &cfg, 0, ((struct Obj03216 *)p)->f80);
    } else {
        cfg.a = e;
        cfg.b = f;
        *(u32 *)(p + 8 + off) = (u32)CLACT_CreateAffineActor(((struct Obj03216 *)p)->f4, *(u32 *)(p + 12 + off), *(u32 *)(p + 16 + off), *(u32 *)(p + 20 + off), (u32)(&cfg), 0, ((struct Obj03216 *)p)->f80);
    }
    CLACT_SetActorAutoAnim((struct Obj *)*(u32 *)(p + 8 + off), 1);
    ARC_TOOL_DeleteHandle(archive);
    return i;
}

void func_02201CA4(Res_02201B20 *r, int i)
{
    CLACT_ReleaseCharacter((u32)r->e[i].hc);
    CLACT_ReleasePalette((u32)r->e[i].h10);
    CLACT_ReleaseCellAnim((u32)r->e[i].h14);
    CLACT_DeleteActor(r->e[i].h8);
    r->e[i].h8 = 0;
}

void func_02201CD0(char *o, int idx, int c, s16_02201B20 *p, int s1, int s2, int s3)
{
    Vec_v1B20 b;
    Vec_v1B20 a;
    s16_02201B20 t[2];

    a.x = p[0] << 12;
    a.y = p[1] << 12;
    a.z = 0;
    CLACT_GetActorSurfacePos(*(void **)(o + idx * 16 + 8), (struct PtS *)t, 0);
    b.x = t[0] << 12;
    b.y = t[1] << 12;
    b.z = 0;
    if (c == 1) {
        a.x += b.x;
        a.y += b.y;
        a.z += b.z;
    }
    func_02201E04((char *)o, idx, c, (Vec *)&b, (Vec *)&a, s1, s2, s3, func_02201F98, func_02201FD8);
    ((struct Obj07895 *)o)->f78 |= 1 << idx;
}

/*
 * lever: a brace-initialised Vec_v1B20 local compiles to an @N rodata template; three field stores do not.
 */
/*
 * lever: a brace-initialised Vec local compiles to an @N rodata template; three field stores do not.
 */
void func_02201D5C(char *o, int idx, int c, void *d, int s1, int s2, int s3)
{
    Vec_v1B20 v;

    v.x = 0x1000;
    v.y = 0x1000;
    v.z = 0x1000;

    func_02201E04((char *)o, idx, c, (Vec *)&v, (Vec *)d, s1, s2, s3, func_02201FF4, func_0220203C);
    ((struct Obj07895 *)o)->f7C |= 1 << idx;
}

u32 func_02201DA0(char *p, int i, int v)
{
    return CLACT_SetActorAnimSeq(*(void **)(p + i * 16 + 8), (u16)v);
}

void func_02201DB4(char *base, int idx, u8 b, u8 c, s8 step, u16 d)
{
    u16 m = 1 << (((u32)CLACT_GetPaletteVramAddress((u32)(*(void **)(base + idx * 16 + 0x10)), (int)0) & 0x3FF) >> 5);
    void *p = (void *)func_021F86E0();

    PALANM_RequestFade(p, 4, m, step, b, c, d, func_021F86D4());
}

static inline int Round(int x)
{
    if (x > 0) return _ffix(_fadd(0.5f, _fflt(x << 12)));
    else return _ffix(_fsub(_fflt(x << 12), 0.5f));
}

void func_02201E04(char *o, int idx, u32 mode, Vec *v, Vec *w, int s1, int s2, int s3,
                   void (*f1)(void *, void *), void (*f2)(void *))
{
    Job *p;
    p = func_02030734((u16)((((struct Obj07895 *)o)->f80 & 0x7fff) | 0x8000), 0x50, 0, d_0220AE88, 0x197);
    p->owner = o;
    p->idx = idx;
    p->start.x = v->x;
    p->start.y = v->y;
    p->start.z = v->z;
    p->mode = mode;
    p->n1 = s1;
    p->n2 = s1;
    p->zero = 0;
    p->s2 = s2;
    p->s3 = s3 * 2;
    p->a.x = v->x;
    p->a.y = v->y;
    p->a.z = v->z;
    p->b.x = w->x;
    p->b.y = w->y;
    p->b.z = w->z;
    switch (mode) {
    case 1:
        func_021F918C((const VecFx32_021F8F30 *)(&p->a), (const VecFx32_021F8F30 *)w, (VecFx32_021F8F30 *)(&p->delta), Round(s1));
        break;
    case 3:
        p->n2 *= 2;
        p->s3 *= 2;
    case 2:
        p->delta.x = func_0207C768(w->x, Round(s1));
        p->delta.y = func_0207C768(w->y, Round(s1));
        p->delta.z = func_0207C768(w->z, Round(s1));
        break;
    case 0:
    default:
        break;
    }
    func_021F896C(func_02030DA8(((struct Obj07895 *)o)->f0, f1, p, 0), f2, 0);
}

void func_02201F98(void *a, void *b)
{
    Obj_02201DA0 *o = (Obj_02201DA0 *)b;
    Ent_02201DA0 *t = o->tbl;
    int r = func_021F9260((Mover_v8204 *)o->mover, (VecFx32_021F8F30 *)(&o->x));
    short v[2];

    v[0] = o->x >> 12;
    v[1] = o->y >> 12;
    CLACT_AddActorSurfacePos((struct Obj_02201DA0 *)(t[o->idx].h), (const struct Vec2 *)v, 0);
    if (r == 1)
        func_021F89BC(a);
}

void func_02201FD8(void *h)
{
    int *q = (int *)TCBL_GetTaskUserData(h);
    char *p = (char *)q[0];
    ((struct Obj21735 *)p)->f78 &= (1 << q[4]) ^ -1;
}

void func_02201FF4(void *a, void *b)
{
    Obj_02201DA0 *o = (Obj_02201DA0 *)b;
    Ent_02201DA0 *t = o->tbl;
    int r = func_021F9260((Mover_v8204 *)o->mover, (VecFx32_021F8F30 *)(&o->x));
    int v[2];

    v[0] = o->x;
    v[1] = o->y;
    CLACT_SetActorAffineMode(t[o->idx].h, 1);
    CLACT_SetActorScale((struct Obj_02201DA0 *)(t[o->idx].h), (struct Pair_02201B20 *)v);
    if (r == 1)
        func_021F89BC(a);
}

void func_0220203C(void *h)
{
    int *q = (int *)TCBL_GetTaskUserData(h);
    char *p = (char *)q[0];
    ((struct Obj21736 *)p)->f7C &= (1 << q[4]) ^ -1;
}
