/*
 * function: FLDEFF_IWAKUDAKI_Init
 * address:  0x021ADDE8
 * packet:   pkt_ov021_021ADDE8
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
 *   G3D_SYSTEM_CreateRender  0x02047400  arm  arm9
 *   G3D_SYSTEM_CreateAnime  0x02047564  arm  arm9
 *   G3D_SYSTEM_CreateObject  0x0204767C  arm  arm9
 *   G3D_SYSTEM_EnableObjectAnime  0x020477A4  arm  arm9
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct Src { u32 f0; u32 f4; u32 arr[4]; } Src;
typedef struct Q { Src *src; u32 f4; u32 arr[4]; u32 f18; } Q;

struct G3dOwner;
struct G3dRec;
extern int FIELD_EFFECT_GetObjectParam(u32 a);
extern void FIELD_EFFECT_SetObjectPos(u32 a, u32 *b);
extern void *G3D_SYSTEM_CreateRender(void *a0, u32 n, void *a2);
extern struct G3dRec *G3D_SYSTEM_CreateAnime(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *G3D_SYSTEM_CreateObject(u32 a0, u32 *a1, int a2);
struct G3dSys;
extern u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx);

void FLDEFF_IWAKUDAKI_Init(u32 a, Q *q)
{
    u32 *p = (u32 *)FIELD_EFFECT_GetObjectParam(a);
    int i;

    q->src = (Src *)p[0];
    FIELD_EFFECT_SetObjectPos(a, p + 1);
    q->f18 = (u32)G3D_SYSTEM_CreateRender((void *)q->src->f4, 0, (void *)q->src->f4);
    for (i = 0; i < 4; i++)
        q->arr[i] = (u32)G3D_SYSTEM_CreateAnime((struct G3dOwner *)q->f18, (const struct G3dOwner *)q->src->arr[i], 0);
    q->f4 = (u32)G3D_SYSTEM_CreateObject(q->f18, q->arr, 4);
    for (i = 0; i < 4; i++)
        G3D_SYSTEM_EnableObjectAnime((struct G3dSys *)q->f4, (u16)i);
}
