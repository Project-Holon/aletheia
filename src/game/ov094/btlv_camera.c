/*
 * file:     btlv_camera.c
 * unit:     yes
 * function: func_021F6E3C, func_021F6EC0, func_021F6ED4, func_021F6EDC, func_021F6F20, func_021F6F48, func_021F7000, func_021F70F0, func_021F7108, func_021F7208, func_021F722C, func_021F723C, func_021F73A4
 * address:  0x021F6E3C
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
 *   sub_02030734 0x02030734 arm
 *   func_020307B0  0x020307B0  arm
 *   G3D_CAMERA_Create  0x02048A24  arm
 *   G3D_CAMERA_Reset  0x02048AD0  arm
 *   d_0220AC60     0x0220AC60  data   ov094  a1
 *   d_02209CF4     0x02209CF4  data   ov094
 *   d_02209D00     0x02209D00  data   ov094
 *   d_02209CE8     0x02209CE8  data   ov094
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   func_02048AFC  0x02048AFC  arm
 *   func_02048B44  0x02048B44  arm
 *   func_0207C768  0x0207C768  arm
 *   G3D_CAMERA_GetEye 0x02048AE8 arm
 *   G3D_CAMERA_GetUp 0x02048B30 arm
 *   FX_SinCosTable_ 0x020A1B38 data a2
 *   func_0207CFB8  0x0207CFB8  arm
 *   func_0207CBD0  0x0207CBD0  arm
 *   func_021F918C 0x021F918C thumb ov094
 *   func_021F9260  0x021F9260  thumb  ov094
 *   func_021F9220 0x021F9220 thumb ov094
 */
#include "../../matched/include/Obj18557.h"
#include "btlv_effvm_types.h"
#include "btlv_camera_shared_types.h"

struct Light;

extern void *sub_02030734(u32, u32, int, const char *, u16);

extern u32 func_020307B0(void *p);

extern u32 G3D_CAMERA_Create(int, int, int, int, int, int, int, int, void *, void *, void *, int);

extern void G3D_CAMERA_Reset(struct Light *l);

extern unsigned int G3D_CAMERA_Delete(void *ptr);

extern void func_02048AFC(int, const int *);

extern void func_02048B44(int, int);

extern u32 func_0207C768(u32 a, u32 b);

extern void G3D_CAMERA_GetEye(void *, void *);

extern void G3D_CAMERA_GetUp(void *, int);

extern int func_0207CFB8(int, int);

extern int func_0207CBD0(int *);

Obj_021F6E3C *func_021F6E3C(int a, u16 b);

void func_021F6EC0(void **p);

void func_021F6ED4(int *p);

void func_021F6EDC(int *p, int *a, int *b);

void func_021F6F20(Obj_021F6F20 *p, int a, int b);

void func_021F6F48(Cam_021F6F48 *c, VecFx32_v6560 *a, VecFx32_v6560 *b, int n, int s, int t);

void func_021F7000(Cam_021F7000 *c, int mode, fx32 v, int unused, int n, int g, int h);

void func_021F70F0(void **p, void *b, int c);

void func_021F7108(int *p, int a, int b, int *out, int *base);

void func_021F7208(VecFx32_v6560 *a, VecFx32_v6560 *b);

int func_021F722C(char *p);

void func_021F723C(int *p);

void func_021F73A4(int *p);

void func_021F918C(const VecFx32_021F8F30 *a, const VecFx32_021F8F30 *b, VecFx32_021F8F30 *out, fx32 div);

void func_021F9220(int *p, int *d, int *lim, int *flag);

int func_021F9260(Mover_v8204 *m, VecFx32_021F8F30 *out);

extern const char d_0220AC60[];

extern char d_02209CF4[];

extern char d_02209D00[];

extern char d_02209CE8[];

extern const s16_021F6560 FX_SinCosTable_[];

#define FX_INT_TO_FX32(x) ((fx32)(((x) > 0) ? ((float)((x) << 12) + .5f) \
                                            : ((float)((x) << 12) - .5f)))

#define MUL(a,b) ((int)(((long long)(a) * (b) + 0x800) >> 12))

Obj_021F6E3C *func_021F6E3C(int a, u16 b)
{
    Obj_021F6E3C *o = sub_02030734(b, 0xb8, 1, d_0220AC60, 0x56);

    o->hb4 = b;
    o->f0 = a;
    o->h4 = G3D_CAMERA_Create(0, 0x399, 0xf97, 0x159a, 0, 0x1000, 0x200000, 0,
                          d_02209CF4, d_02209D00, d_02209CE8, b);
    func_021F73A4((int *)o);
    G3D_CAMERA_Reset((struct Light *)o->h4);
    func_021F7208((VecFx32_v6560 *)(&o->v18), (VecFx32_v6560 *)(&o->v24));
    return o;
}

/*
 * Releases the handle at word 1, then frees the object.
 */
void func_021F6EC0(void **p)
{
    G3D_CAMERA_Delete(p[1]);
    func_020307B0(p);
}

void func_021F6ED4(int *p)
{
    func_021F723C(p);
}

/*
 * EXACT*: inferred extent is two bytes long; the follower is an unlabelled
 * leaf that disasm.py did not label.
 */
void func_021F6EDC(int *p, int *a, int *b)
{
    if (a) {
        p[6] = a[0];
        p[7] = a[1];
        p[8] = a[2];
        func_02048AFC(p[1], a);
    }
    if (b) {
        p[9] = b[0];
        p[10] = b[1];
        p[11] = b[2];
        func_02048B44(p[1], (int)b);
    }
    G3D_CAMERA_Reset((struct Light *)p[1]);
    func_021F73A4(p);
}

/*
 * Builds the transform at 0x18/0x24, then loads it into the handle at word 1 and commits.
 */
void func_021F6F20(Obj_021F6F20 *p, int a, int b)
{
    func_021F7108((int *)p, a, b, p->m, p->v);
    func_02048AFC((int)p->h, (const int *)p->m);
    G3D_CAMERA_Reset(p->h);
}

void func_021F6F48(Cam_021F6F48 *c, VecFx32_v6560 *a, VecFx32_v6560 *b, int n, int s, int t)
{
    c->f74 = t;
    c->f6c = s;
    c->f70 = s;
    if (a != 0) {
        c->dst0.x = a->x;
        c->dst0.y = a->y;
        c->dst0.z = a->z;
        func_021F918C((const VecFx32_021F8F30 *)((const VecFx32_v6560 *)(&c->cur0)), (const VecFx32_021F8F30 *)((const VecFx32_v6560 *)a), (VecFx32_021F8F30 *)((VecFx32_v6560 *)(&c->step0)), FX_INT_TO_FX32(n));
        c->flags |= 1;
    }
    if (b != 0) {
        c->dst1.x = b->x;
        c->dst1.y = b->y;
        c->dst1.z = b->z;
        func_021F918C((const VecFx32_021F8F30 *)((const VecFx32_v6560 *)(&c->cur1)), (const VecFx32_021F8F30 *)((const VecFx32_v6560 *)b), (VecFx32_021F8F30 *)((VecFx32_v6560 *)(&c->step1)), FX_INT_TO_FX32(n));
        c->flags |= 2;
    }
}

/*
 * Follower of func_021F6F48; bl from ov094 at 0x021FA08E.
 */
void func_021F7000(Cam_021F7000 *c, int mode, fx32 v, int unused, int n, int g, int h)
{
    c->f78 = 3;
    c->fa0 = n;
    c->fa4 = n;
    c->fa8 = 0;
    c->fac = g;
    c->f7c = 0;
    c->fb0 = h * 4;
    c->f80 = 0;
    c->f84 = 0;
    if (mode == 1) {
        c->f88 = v;
        c->f8c = 0;
        c->f94 = func_0207C768(v, FX_INT_TO_FX32(n));
        c->f98 = 0;
    } else {
        c->f88 = 0;
        c->f8c = v;
        c->f94 = 0;
        c->f98 = func_0207C768(v, FX_INT_TO_FX32(n));
    }
    c->f90 = 0;
    c->f9c = 0;
    c->flags |= 4;
}

/*
 * EXACT*: the listing extent includes two bytes of trailing alignment padding.
 *
 * Copies the light at word 1's vectors at +0x20 and +0x38 out to b and c.
 */
void func_021F70F0(void **p, void *b, int c)
{
    G3D_CAMERA_GetEye(p[1], b);
    G3D_CAMERA_GetUp(p[1], c);
}

void func_021F7108(int *p, int a, int b, int *out, int *base)
{
    G3D_CAMERA_GetUp((void *)p[1], (int)base);
    p[2] += a;
    p[3] += b;
    out[0] = MUL(FX_SinCosTable_[(p[3] >> 4) * 2 + 1], FX_SinCosTable_[(p[2] >> 4) * 2 + 1]);
    out[1] = FX_SinCosTable_[(p[2] >> 4) * 2];
    out[2] = MUL(FX_SinCosTable_[(p[3] >> 4) * 2], FX_SinCosTable_[(p[2] >> 4) * 2 + 1]);
    out[0] = MUL(out[0], p[4]);
    out[1] = MUL(out[1], p[4]);
    out[2] = MUL(out[2], p[4]);
    out[0] += base[0];
    out[1] += base[1];
    out[2] += base[2];
}

void func_021F7208(VecFx32_v6560 *a, VecFx32_v6560 *b)
{
    a->x = 0x6b33;
    a->y = 0x6b33;
    a->z = 0x114cd;
    b->x = 0;
    b->y = 0x299a;
    b->z = 0;
}

int func_021F722C(char *p)
{
    return ((struct Obj18557 *)p)->f14 != 0;
}

void func_021F723C(int *p)
{
    int a[3];
    int b[3];
    int ret = 1;
    int n;
    if (p[5] == 0) return;
    if (p[27] == 0) {
        p[27] = p[28];
        if (p[29] != 0) {
            if (--p[29] == 0) {
                n = p[18] >> 1; if (n) p[18] = n;
                n = p[19] >> 1; if (n) p[19] = n;
                n = p[20] >> 1; if (n) p[20] = n;
                n = p[21] >> 1; if (n) p[21] = n;
                n = p[22] >> 1; if (n) p[22] = n;
                n = p[23] >> 1; if (n) p[23] = n;
            }
        }
        if (p[5] & 1) {
            func_021F9220(&p[6], &p[18], &p[12], &ret);
            func_021F9220(&p[7], &p[19], &p[13], &ret);
            func_021F9220(&p[8], &p[20], &p[14], &ret);
            if (ret == 1) p[5] &= ~1;
        }
        if (p[5] & 2) {
            func_021F9220(&p[9], &p[21], &p[15], &ret);
            func_021F9220(&p[10], &p[22], &p[16], &ret);
            func_021F9220(&p[11], &p[23], &p[17], &ret);
            if (ret == 1) p[5] &= ~2;
        }
        if (p[5] & 4) {
            ret = func_021F9260((Mover_v8204 *)(&p[30]), (VecFx32_021F8F30 *)(&p[24]));
            if (ret == 1) p[5] &= ~4;
        }
        a[0] = p[6] + p[24];
        a[1] = p[7] + p[25];
        a[2] = p[8] + p[26];
        b[0] = p[9] + p[24];
        b[1] = p[10] + p[25];
        b[2] = p[11] + p[26];
        func_02048AFC(p[1], (const int *)a);
        func_02048B44(p[1], (int)b);
        G3D_CAMERA_Reset((struct Light *)p[1]);
        func_021F73A4(p);
    } else {
        p[27]--;
    }
}

void func_021F73A4(int *p)
{
    int a[3];
    int b[3];
    G3D_CAMERA_GetEye((void *)p[1], a);
    G3D_CAMERA_GetUp((void *)p[1], (int)b);
    a[0] -= b[0];
    a[1] -= b[1];
    a[2] -= b[2];
    p[2] = func_0207CFB8(a[1], a[2]);
    p[3] = func_0207CFB8(a[2], a[0]);
    p[4] = func_0207CBD0(a);
}
