/*
 * function: FLDEFF_D06DENKI_PulseInit
 * address:  0x021C92B0
 * packet:   pkt_ov021_021C92B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_EFFECT_GetObjectParam  0x021AC1AC  thumb  ov021
 *   FIELD_EFFECT_SetObjectPos  0x021AC1CC  thumb  ov021
 *   G3D_SYSTEM_CreateRender  0x02047400  arm
 *   G3D_SYSTEM_CreateAnime  0x02047564  arm
 *   G3D_SYSTEM_CreateObject  0x0204767C  arm
 *   G3D_SYSTEM_EnableObjectAnime  0x020477A4  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

typedef struct S4 { u32 v[4]; } S4;

struct G3dOwner;
struct G3dRec;
struct G3dSys;
extern int FIELD_EFFECT_GetObjectParam(u32 a);
extern void FIELD_EFFECT_SetObjectPos(u32, u32 *);
extern void *G3D_SYSTEM_CreateRender(void *a0, u32 n, void *a2);
extern struct G3dRec *G3D_SYSTEM_CreateAnime(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *G3D_SYSTEM_CreateObject(u32 a0, u32 *a1, int a2);
extern u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx);

void FLDEFF_D06DENKI_PulseInit(u32 a, u32 *q)
{
    *(S4 *)q = *((S4 *)FIELD_EFFECT_GetObjectParam(a));
    FIELD_EFFECT_SetObjectPos(a, q + 1);
    q[8] = (u32)G3D_SYSTEM_CreateRender((void *)(((u32 *)q[0])[3]), 0, (void *)(((u32 *)q[0])[3]));
    q[6] = (u32)G3D_SYSTEM_CreateAnime((struct G3dOwner *)q[8], (const struct G3dOwner *)(((u32 *)q[0])[8]), 0);
    q[7] = (u32)G3D_SYSTEM_CreateAnime((struct G3dOwner *)q[8], (const struct G3dOwner *)(((u32 *)q[0])[9]), 0);
    q[5] = (u32)G3D_SYSTEM_CreateObject(q[8], q + 6, 2);
    G3D_SYSTEM_EnableObjectAnime((struct G3dSys *)q[5], 0);
    G3D_SYSTEM_EnableObjectAnime((struct G3dSys *)q[5], 1);
}
