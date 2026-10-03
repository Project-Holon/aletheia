/*
 * function: func_021C7830
 * address:  0x021C7830
 * packet:   pkt_ov111_021C7830
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocking arm9 callees labelled and matched by seeds_3 (2026-09-28)
 *
 * symbols:
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_02048AD0  0x02048AD0  arm
 *   func_02048A18  0x02048A18  arm
 *   func_0204779C  0x0204779C  arm
 *   func_02047828  0x02047828  arm
 *   func_0204784C  0x0204784C  arm
 *   func_02047964  0x02047964  arm
 *   func_020479D8  0x020479D8  arm
 *   func_02047A60  0x02047A60  arm
 *   func_02047970  0x02047970  arm
 *   d_021C8E80  0x021C8E80  data
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;

typedef struct {
    u8 pad0[0xC];
    void *fC;
} Res;

typedef struct {
    u8 pad0[4];
    void *f4;
    u8 pad8[4];
    int fC;
    int f10;
} Parent;

typedef struct {
    void *f0;
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x20 - 0x18];
    void *f20;
    void *f24;
    void *f28;
    void *f2C[7];
    void *f48;
    void *f4C;
    void *f50;
    void *f54;
    void *f58;
    void *f5C[8];
    void *f7C[24];
    void *fDC;
    void *fE0;
    void *fE4;
    void *fE8;
    void *fEC;
    void *fF0;
    void *fF4;
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    Parent *f108;
    int state;
    int f110;
    u16 f114;
    u16 f116;
    int f118;
    int f11C;
    u8 pad120[0x13C - 0x120];
    int f13C;
    int f140;
    int f144;
    u8 pad148[0x14C - 0x148];
    void *f14C[3];
    Res *f158[3];
    void *f164[3];
    Res *f170[3];
    u8 f17C[8];
    void *f184;
    int f188[8];
    u8 f1A8[8];
    u8 f1B0[8];
} Work;

typedef int fx32;
typedef struct { fx32 x, y, z; } VecFx32;
typedef struct { fx32 m[3][3]; } MtxFx33;

typedef struct {
    VecFx32 trans;
    VecFx32 scale;
    MtxFx33 rot;
} Transform;

typedef struct {
    int f0;
    int f4;
} Counter;

extern void func_0207ADC4(MtxFx33 *m);
typedef signed int     s32;
struct AnmCtl;
struct Light;
extern void func_02048AD0(struct Light *l);
extern void *func_02048A18(void *p, u16 id);
extern int func_0204779C(int *p);
extern u32 func_02047828(struct AnmCtl *c, u32 idx, s32 *frame);
extern void func_0204784C(void *mdl, u16 i, void *q);
extern void func_02047964(void);
extern void func_020479D8(void);
extern void func_02047A60(void *mdl, Transform *t);
extern void func_02047970(void);
extern Counter d_021C8E80;

void func_021C7830(Work *p)
{
    void *mdl;
    int out;
    Transform t;
    int n;
    int i;

    i = 0;
    t.scale.x = 0x1000;
    t.scale.y = 0x1000;
    t.scale.z = 0x1000;
    t.trans.x = 0;
    t.trans.y = 0;
    t.trans.z = 0;
    func_0207ADC4(&t.rot);
    func_02048AD0(p->f104);
    mdl = func_02048A18(p->fF8, p->fFC);
    n = func_0204779C(mdl);
    func_02047828(mdl, 0, &out);
    for (; i < n; i++) {
        func_0204784C(mdl, i, &p->f13C);
    }
    func_02047964();
    func_020479D8();
    func_02047A60(func_02048A18(p->fF8, p->fFC), &t);
    func_02047970();
    d_021C8E80.f0 += d_021C8E80.f4;
}
