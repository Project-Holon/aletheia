/*
 * function: FLDEFF_BTRAIN_Init
 * address:  0x021D029C
 * packet:   pkt_ov021_021D029C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_EFFECT_GetObjectParam  0x021AC1AC  thumb  ov021
 *   G3D_SYSTEM_CreateAnime  0x02047564  arm
 *   G3D_SYSTEM_CreateObject  0x0204767C  arm
 *   G3D_SYSTEM_DisableObjectAnime  0x020477D4  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    int pad[9];
    int a24[4];
    int a34[1];
} Tbl;

typedef struct {
    Tbl *tbl;
    int cnt;
} Src;

typedef struct {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    Src src;
    int obj;
    int sub[4];
} Dst;

typedef unsigned int   u32;
struct Owner;
extern int FIELD_EFFECT_GetObjectParam(u32 a);
struct G3dOwner;
struct G3dRec;
extern struct G3dRec *G3D_SYSTEM_CreateAnime(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *G3D_SYSTEM_CreateObject(u32 a0, u32 *a1, int a2);
extern int G3D_SYSTEM_DisableObjectAnime(struct Owner *owner, u32 index);

void FLDEFF_BTRAIN_Init(void *p, Dst *d)
{
    Src *s;
    Tbl *tbl;
    int cnt;
    int j;
    int i;

    s = (Src *)FIELD_EFFECT_GetObjectParam((u32)p);
    d->src = *s;
    tbl = d->src.tbl;
    cnt = d->src.cnt;
    for (i = 0; i < 4; i++)
        d->sub[i] = (int)G3D_SYSTEM_CreateAnime((struct G3dOwner *)tbl->a34[cnt], (const struct G3dOwner *)tbl->a24[i], 0);
    d->f2 = 4;
    d->obj = (int)G3D_SYSTEM_CreateObject((int)tbl->a34[cnt], (u32 *)d->sub, 4);
    for (j = 0; j < 4; j++)
        G3D_SYSTEM_DisableObjectAnime((struct Owner *)d->obj, (u16)j);
}
