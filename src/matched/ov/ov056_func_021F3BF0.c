/*
 * function: FIELD_FK_DEMO_CreateModelObject
 * address:  0x021F3BF0
 * packet:   pkt_ov056_021F3BF0
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3D_SYSTEM_CreateRender  0x02047400  arm
 *   G3D_SYSTEM_CreateAnime  0x02047564  arm
 *   G3D_SYSTEM_CreateObject  0x0204767C  arm
 *   G3D_SYSTEM_SetObjectAnimeFrame  0x0204784C  arm
 *   G3D_SYSTEM_EnableObjectAnime  0x020477A4  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct G3dOwner;
struct G3dRec;
extern void *G3D_SYSTEM_CreateRender(void *a0, u32 n, void *a2);
extern struct G3dRec *G3D_SYSTEM_CreateAnime(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *G3D_SYSTEM_CreateObject(u32 a0, u32 *a1, int a2);
typedef signed int     s32;
struct AnmCtl;
extern u32 G3D_SYSTEM_SetObjectAnimeFrame(struct AnmCtl *c, u16 idx, s32 *frame);
struct G3dSys;
extern u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx);

void FIELD_FK_DEMO_CreateModelObject(u32 *p)
{
    int i;
    int v;

    i = 0;
    p[4] = (u32)G3D_SYSTEM_CreateRender((void *)p[0], 0, (void *)p[0]);
    p[5] = (u32)G3D_SYSTEM_CreateAnime((struct G3dOwner *)p[4], (const struct G3dOwner *)p[1], 0);
    p[6] = (u32)G3D_SYSTEM_CreateAnime((struct G3dOwner *)p[4], (const struct G3dOwner *)p[2], 0);
    p[7] = (u32)G3D_SYSTEM_CreateObject(p[4], &p[5], 2);
    v = 0;
    for (; i < 2; i++) {
        G3D_SYSTEM_SetObjectAnimeFrame((struct AnmCtl *)p[7], (u16)i, &v);
        G3D_SYSTEM_EnableObjectAnime((struct G3dSys *)p[7], (u16)i);
    }
}
