/*
 * function: func_0220887C
 * address:  0x0220887C
 * packet:   pkt_0220887C
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * promoted: from src/pending on 2026-09-27, no C change. Its blocker, the
 *   call at +0xD8 to the unlabelled ARM leaf 0x02051B04, closed when that
 *   leaf was seeded in layout/function_starts.txt and matched
 *   (src/matched/func_02051B04.c); all 13 relocations resolve.
 *
 * symbols:
 *   d_02208F24 0x02208F24 data
 *   d_02208F30 0x02208F30 data
 *   d_02208E9C 0x02208E9C data
 *   d_02208F7C 0x02208F7C data
 *   FX_SinCosTable_ 0x020A1B38 data
 *   func_02030734 0x02030734 arm
 *   func_02050B80 0x02050B80 arm
 *   func_02050C30 0x02050C30 arm
 *   func_02051758 0x02051758 arm
 *   func_02051648 0x02051648 arm
 *   func_0205121C 0x0205121C arm
 *   func_02051B04 0x02051B04 arm
 *   func_02051230 0x02051230 arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef s32 fx32;

typedef struct VecFx32 {
    fx32 x, y, z;
} VecFx32;

typedef struct EmitParam {
    u32 f00;
    fx32 f04;
    fx32 f08;
    u32 f0c;
    u32 f10;
    fx32 f14;
    u32 f18;
    u32 f1c;
} EmitParam;

typedef struct Ptc {
    u16 f00;
    u16 f02;
    u16 f04;
    u16 pad06;
    void *f08;
    u8 work[0x4800];
    void *spl;
    u8 f4810;
    u8 pad4811[3];
    u32 f4814;
    s32 f4818;
} Ptc;

extern const VecFx32 d_02208F24;
extern const VecFx32 d_02208F30;
extern const u32 d_02208E9C[2];
extern char d_02208F7C[];
extern s16 FX_SinCosTable_[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02050B80(u32 heap);
extern void *func_02050C30(void *buf, u32 size, u32 a2, u32 a3, u32 a4, u32 a5, u32 heap);
extern void func_02051758(void *spl);
extern void func_02051648(void *spl, void *src, u32 a2, void *a3, void *a4, void *a5, u32 a6);
extern int func_0205121C(u32 a, u32 b, u32 c);
extern u16 func_02051B04(u32 res);
extern void func_02051230(void *spl, u32 res, u32 a2, u32 a3);

Ptc *func_0220887C(u16 heap, u16 a, void *b)
{
    VecFx32 v1 = d_02208F24;
    VecFx32 v2 = d_02208F30;
    VecFx32 v3 = {0, 0, 0};
    EmitParam prm;
    Ptc *p;
    u32 res;

    prm.f00 = 0;
    prm.f04 = FX_SinCosTable_[0xe3 * 2];
    prm.f08 = FX_SinCosTable_[0xe3 * 2 + 1];
    prm.f0c = 0x1555;
    prm.f10 = 0;
    prm.f14 = 0x1000;
    prm.f18 = 0x400000;
    prm.f1c = 0;

    p = func_02030734(heap, sizeof(Ptc), 1, d_02208F7C, 0x2e5);
    p->f00 = 0;
    p->f02 = 0;
    p->f04 = a;
    p->f08 = b;
    p->f4814 = 0;
    p->f4818 = -1;
    func_02050B80(heap);
    p->spl = func_02050C30(p->work, sizeof(p->work), 1, 5, 6, 0x3b, heap);
    func_02051758(p->spl);
    func_02051648(p->spl, &prm, 0x2000, &v1, &v2, &v3, heap);
    res = func_0205121C(d_02208E9C[0], d_02208E9C[1], heap);
    p->f4810 = func_02051B04(res);
    func_02051230(p->spl, res, 1, 0);
    return p;
}
