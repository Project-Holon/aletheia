/*
 * function: FLDEFF_IAIGIRI_Init
 * address:  0x021C95D8
 * packet:   pkt_ov021_021C95D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * The `adds r4, r6, #0` before the first loop is the second loop's counter
 * initialised to 0 and shared as the first loop's constant 0 argument; both
 * loops use one counter i. Callee widths from arm9 G3D_UTIL_BuildUnitObjectsLoaded.
 * symbols:
 *   FIELD_EFFECT_GetObjectParam  0x021AC1AC  thumb  ov021
 *   FIELD_EFFECT_SetObjectPos  0x021AC1CC  thumb  ov021
 *   G3D_SYSTEM_CreateRender  0x02047400  arm
 *   G3D_SYSTEM_CreateAnime  0x02047564  arm
 *   G3D_SYSTEM_CreateObject  0x0204767C  arm
 *   G3D_SYSTEM_EnableObjectAnime  0x020477A4  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;

struct G3dOwner;
struct G3dRec;
extern int FIELD_EFFECT_GetObjectParam(u32 a);
extern void FIELD_EFFECT_SetObjectPos(u32 a, u32 *b);
extern void *G3D_SYSTEM_CreateRender(void *a0, u32 n, void *a2);
extern struct G3dRec *G3D_SYSTEM_CreateAnime(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *G3D_SYSTEM_CreateObject(u32 a0, u32 *a1, int a2);
struct G3dSys;
extern u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx);

void FLDEFF_IAIGIRI_Init(u32 a, u32 *b)
{
    u32 *p = (u32 *)FIELD_EFFECT_GetObjectParam(a);
    int i;

    b[0] = p[0];
    FIELD_EFFECT_SetObjectPos(a, p + 1);
    b[5] = (u32)G3D_SYSTEM_CreateRender((void *)(((u32 *)b[0])[1]), 0, (void *)(((u32 *)b[0])[1]));
    for (i = 0; i < 3; i++)
        b[2 + i] = (u32)G3D_SYSTEM_CreateAnime((struct G3dOwner *)b[5], (const struct G3dOwner *)(((u32 *)b[0])[2 + i]), 0);
    b[1] = (u32)G3D_SYSTEM_CreateObject(b[5], b + 2, 3);
    for (i = 0; i < 3; i++)
        G3D_SYSTEM_EnableObjectAnime((struct G3dSys *)b[1], (u16)i);
}
