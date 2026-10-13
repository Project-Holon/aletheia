/*
 * function: FLDEFF_BUBBLE_LoadResources
 * address:  0x021D0648
 * packet:   pkt_ov021_021D0648
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FIELD_EFFECT_GetArcHandle  0x021ABE24  thumb  ov021
 *   G3D_SYSTEM_CreateResourceArcHandle  0x02046E24  arm
 *   G3D_SYSTEM_CheckResourceType  0x02046F50  arm
 *   G3D_SYSTEM_TransVramTexture  0x02046FF8  arm
 *   G3D_SYSTEM_CreateRender  0x02047400  arm
 *   G3D_SYSTEM_CreateAnime  0x02047564  arm
 *   G3D_SYSTEM_CreateObject  0x0204767C  arm
 *   G3D_SYSTEM_EnableObjectAnime  0x020477A4  arm
 *   d_021DB95C     0x021DB95C  data  a4
 *   d_021DB950     0x021DB950  data  ov021  a4
 *   d_021DB954     0x021DB954  data  ov021  a4
 */

typedef unsigned short u16;

typedef struct S {
    int f0;
    int a[3];
    int f10;
    int b[2];
    int f1c;
} S;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct G3dOwner;
struct G3dRec;
struct Tagged;
extern u32 FIELD_EFFECT_GetArcHandle(u8 *p);
extern void *G3D_SYSTEM_CreateResourceArcHandle(u32 a0, u32 a1);
extern u32 G3D_SYSTEM_CheckResourceType(struct Tagged *p, u32 sel);
extern int G3D_SYSTEM_TransVramTexture(int *self);
extern void *G3D_SYSTEM_CreateRender(void *a0, u32 n, void *a2);
extern struct G3dRec *G3D_SYSTEM_CreateAnime(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
struct G3dSys;
extern void *G3D_SYSTEM_CreateObject(u32 a0, u32 *a1, int a2);
extern u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx);

extern int d_021DB95C[3];
extern int d_021DB950;
extern int d_021DB954[2];

void FLDEFF_BUBBLE_LoadResources(S *p)
{
    int h;
    int i;
    int j;
    int k;

    h = FIELD_EFFECT_GetArcHandle((u8 *)p->f0);
    for (i = 0; i < 3; i++) {
        p->a[i] = (int)G3D_SYSTEM_CreateResourceArcHandle(h, d_021DB95C[i]);
        if (G3D_SYSTEM_CheckResourceType((struct Tagged *)p->a[i], 2)) {
            G3D_SYSTEM_TransVramTexture((int *)p->a[i]);
        }
    }
    j = 0;
    p->f10 = (int)G3D_SYSTEM_CreateRender((void *)p->a[d_021DB950], 0, (void *)p->a[d_021DB950]);
    k = j;
    for (i = 0; i < 2; i++) {
        p->b[i] = (int)G3D_SYSTEM_CreateAnime((struct G3dOwner *)p->f10, (const struct G3dOwner *)p->a[d_021DB954[i]], k);
    }
    p->f1c = (int)G3D_SYSTEM_CreateObject((int)p->f10, (u32 *)p->b, 2);
    for (k = 0; k < 2; k++) {
        G3D_SYSTEM_EnableObjectAnime((struct G3dSys *)p->f1c, (u16)k);
    }
}
