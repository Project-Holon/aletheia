/*
 * function: FLDEFF_ENCOUNT_BuildDrawSet
 * address:  0x021AD82C
 * packet:   pkt_ov021_021AD82C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   G3D_SYSTEM_CreateRender  0x02047400  arm
 *   G3D_SYSTEM_CreateAnime  0x02047564  arm
 *   G3D_SYSTEM_CreateObject  0x0204767C  arm
 *   G3D_SYSTEM_EnableObjectAnime  0x020477A4  arm
 *
 * Lever: G3D_SYSTEM_CreateObject takes three arguments (see ov019_func_0217FA10); the
 * third is b->f88, which is what keeps the loop bound in r2.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct G3dOwner;
struct G3dRec;
struct G3dSys;
extern void *G3D_SYSTEM_CreateRender(void *a0, u32 n, void *a2);
extern struct G3dRec *G3D_SYSTEM_CreateAnime(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *G3D_SYSTEM_CreateObject(u32 a0, u32 *a1, int a2);
extern u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx);

typedef struct A {
    u32 f0;
    u32 f4[4];
    u32 f14;
} A;

typedef struct B {
    u8 pad0[8];
    u32 f8[4];
    u32 f18[28];
    u8 f88;
} B;

void FLDEFF_ENCOUNT_BuildDrawSet(A *a, B *b, int c)
{
    int i = 0;

    a->f14 = (u32)G3D_SYSTEM_CreateRender((void *)b->f8[c], 0, (void *)b->f8[c]);
    for (; i < b->f88; i++)
        a->f4[i] = (u32)G3D_SYSTEM_CreateAnime((struct G3dOwner *)a->f14, (const struct G3dOwner *)b->f18[c * b->f88 + i], 0);
    a->f0 = (u32)G3D_SYSTEM_CreateObject(a->f14, a->f4, b->f88);
    for (i = 0; i < b->f88; i++)
        G3D_SYSTEM_EnableObjectAnime((struct G3dSys *)a->f0, (u16)i);
}
