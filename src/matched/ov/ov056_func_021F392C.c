/*
 * function: func_021F392C
 * address:  0x021F392C
 * packet:   pkt_ov056_021F392C
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Camera setup; the func_02048A24 call is spelled as in ov111_func_021C7744
 * (the pool word 0x020A1EB8 is FX_SinCosTable_ + 0x380, the load reach of
 * elements 0x1C6/0x1C7). The zeroed vector handed to func_0218ECD4 is a
 * byte buffer viewed through a VecFx32 pointer: the image keeps its address
 * in r4 and stores through it. A declared VecFx32 (field stores, a
 * VEC_Set-style inline, a pointer local, or a {0,0,0} initialiser) folds the
 * stores to sp (a-declared-struct-local-folds-to-sp-relative-a-cast-buffer-does-not.md).
 * func_0218ED20 is an unlabelled ov021 leaf filed alongside this function.
 *
 * symbols:
 *   func_02011510  0x02011510  thumb
 *   func_0218EC2C  0x0218EC2C  thumb  ov021
 *   func_02048B30  0x02048B30  arm
 *   func_02048AE8  0x02048AE8  arm
 *   func_02048A24  0x02048A24  arm
 *   func_0218E138  0x0218E138  thumb  ov021
 *   func_0218E13C  0x0218E13C  thumb  ov021
 *   func_0218F1B4  0x0218F1B4  thumb  ov021
 *   func_0218F1AC  0x0218F1AC  thumb  ov021
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_0218ECC4  0x0218ECC4  thumb  ov021
 *   func_0218ECD4  0x0218ECD4  thumb  ov021
 *   func_0218ED20  0x0218ED20  thumb  ov021
 *   func_021F3AB0  0x021F3AB0  thumb  ov056
 *   d_021F4338     0x021F4338  data  a4
 *   d_021F42B0     0x021F42B0  data  a4
 *   FX_SinCosTable_  0x020A1B38  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;
typedef int            fx32;

typedef struct { fx32 x, y, z; } VecFx32;

typedef struct Obj {
    void *f0;
    void *cam;
    int f8;
    u16 hc;
    u16 he;
    VecFx32 f10;
    VecFx32 f1c;
    int f28;
    u32 f2c;
} Obj;

extern void *func_02011510(u32 heap, u32 a1, u32 a2, u32 a3);
extern u32 func_0218EC2C(u8 *p);
extern void func_02048B30(u32 cam, VecFx32 *out);
extern void func_02048AE8(u32 cam, VecFx32 *out);
extern void *func_02048A24(int a, int s, int c, int d, int e, int f, int g, int h, VecFx32 *pos, VecFx32 *up, VecFx32 *tgt, int heap);
extern u32 func_0218E138(u8 *p);
extern void func_0218E13C(u8 *a, u32 s);
extern u8 func_0218F1B4(u8 *p);
extern void func_0218F1AC(u8 *p, u32 v);
extern void func_0218EC54(u8 *p);
extern void func_0218ECC4(int a, VecFx32 *v);
extern void func_0218ECD4(int a, VecFx32 *v);
extern void func_0218ED20(void *p, void *out);
extern void func_021F3AB0(u32 *p);

extern const VecFx32 d_021F4338;
extern const u32 d_021F42B0[];
extern const s16 FX_SinCosTable_[];

void func_021F392C(Obj *o, int a1, int heap, int idx)
{
    VecFx32 tgt;
    VecFx32 pos;
    u8 zero[12];
    VecFx32 up;
    u32 cam;
    VecFx32 *pz;

    o->f28 = 0;
    o->f0 = func_02011510(heap, 0x96, idx + 0x18, 10);
    cam = func_0218EC2C((u8 *)a1);
    func_02048B30(cam, &tgt);
    func_02048AE8(cam, &pos);
    up = d_021F4338;
    o->cam = func_02048A24(0, FX_SinCosTable_[0x1C6], FX_SinCosTable_[0x1C7], 0x1555, 0, 0x1000, 0x400000, 0, &pos, &up, &tgt, heap);
    o->f8 = a1;
    o->hc = func_0218E138((u8 *)a1);
    func_0218E13C((u8 *)o->f8, 2);
    o->he = func_0218F1B4((u8 *)o->f8);
    func_0218F1AC((u8 *)o->f8, 0);
    func_0218EC54((u8 *)o->f8);
    pz = (VecFx32 *)zero;
    pz->x = 0;
    pz->y = 0;
    pz->z = 0;
    func_0218ECC4(o->f8, &o->f10);
    func_0218ECD4(o->f8, pz);
    func_0218ED20((void *)o->f8, &o->f1c);
    func_021F3AB0((u32 *)o);
    o->f2c = d_021F42B0[idx];
}
