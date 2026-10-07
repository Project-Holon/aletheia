/*
 * file:     fieldmap_func_p02.c
 * unit:     yes
 * function: func_021BB648, func_021BB68C
 * address:  0x021BB648
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0216E1C4  0x0216E1C4  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   func_021BB808  0x021BB808  thumb  ov021
 *   d_021D9AA4       0x021D9AA4  data  a4
 *   _fflt            0x0209BDBC  arm
 *   _fadd            0x0209C95C  arm
 *   _fsub            0x0209CB8C  arm
 *   _ffix            0x0209C494  arm
 *   _ll_mul          0x0209C054  arm
 *   MIi_CpuCopyFast  0x02082B0C  arm
 *   func_0206A854    0x0206A854  arm
 *   func_0206DB80    0x0206DB80  arm
 *   func_0207ADC4    0x0207ADC4  arm
 *   func_021AC1B8    0x021AC1B8  thumb  ov021
 *   func_02047AC8    0x02047AC8  arm
 *   g_02148B54       0x02148B54  data
 *   g_02148BCC       0x02148BCC  data
 */
#include "../../matched/include/G_Glb.h"

#define FX_MUL(a, b) ((fx32)(((fx64)(a) * (b) + 0x800) >> 12))
#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? \
                                  ((x) * (1 << 12) + 0.5f) : \
                                  ((x) * (1 << 12) - 0.5f)))
struct Actor;
struct VecFx32;
struct Vec;
struct Arg;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef int fx32;

typedef long long fx64;

typedef struct { fx32 m[4][4]; } MtxFx44;

typedef struct { fx32 x, y, z; } V3;

typedef struct Node {
    V3 pos;
    V3 scale;
    u8 mtx[0x24];
} Node;

typedef struct {
    u8 pad[0x7C];
    u32 flag;
} Glb;

typedef struct {
    u8 pad0[0x24];
    u32 f24[4];
    u16 f34;
} Info;

typedef struct {
    u32 f0;
    u32 f4;
    Info *f8;
} Arg;

int func_0216E1C4(int a, int b);
void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
void func_021AC154(int a);
void func_021AC1CC(int a, int *b);
void func_021BB808(int *o, struct Vec *out);
extern void MIi_CpuCopyFast(const void *src, void *dst, u32 size);
extern void func_0206A854(void);
extern void func_0206DB80(void);
extern void func_0207ADC4(void *mtx);
extern void func_021AC1B8(u32 a, Node *n);
extern int func_02047AC8(void *a0, struct Arg *a1);
void func_021BB648(int a, int *b);
void func_021BB68C(u32 a, Arg *b);
extern const Node d_021D9AA4;
extern MtxFx44 g_02148B54;
extern struct Glb g_02148BCC;


void func_021BB648(int a, int *b)
{
    int v[3];

    if (b[9] == 1 || func_0216E1C4(b[3], (int)(b + 4)) == 0) {
        func_021AC154(a);
        return;
    }
    func_0216D88C((const struct Actor *)b[3], (struct VecFx32 *)v);
    func_021BB808(b, (struct Vec *)v);
    func_021AC1CC(a, v);
}


/*
 * Twin of ov021_func_02189810 (save/modify/restore of the projection matrix
 * g_02148B54).  Here the matrix is read through a pointer local initialised
 * at its declaration, which is what loads its address before the soft-float
 * conversion; `saved = g_02148B54` loads it after (22 bytes off with the
 * pointer declared first, r4/r5 swapped with it declared last).
 *
 * Addresses are Black-image addresses.
 */
void func_021BB68C(u32 a, Arg *b)
{
    Node n = d_021D9AA4;
    MtxFx44 *g = &g_02148B54;
    MtxFx44 saved;
    MtxFx44 m;
    fx32 z;

    z = FX_F32_TO_FX32(b->f8->f34);
    saved = *g;
    m = saved;
    m.m[3][2] += FX_MUL(m.m[2][2], z);
    MIi_CpuCopyFast(&m, &g_02148B54, 0x40);
    g_02148BCC.flag &= ~0x50;
    func_0206A854();
    func_0206DB80();
    func_0207ADC4(n.mtx);
    func_021AC1B8(a, &n);
    func_02047AC8((void *)b->f8->f24[b->f0], (struct Arg *)(&n));
    MIi_CpuCopyFast(&saved, &g_02148B54, 0x40);
    g_02148BCC.flag &= ~0x50;
    func_0206A854();
    func_0206DB80();
}
