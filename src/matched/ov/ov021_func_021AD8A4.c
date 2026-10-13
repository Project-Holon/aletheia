/*
 * function: FLDEFF_ENCOUNT_DeleteDrawSet
 * address:  0x021AD8A4
 * packet:   pkt_ov021_021AD8A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   G3D_SYSTEM_DeleteRender  0x02047504  arm  arm9
 *   G3D_SYSTEM_DeleteAnime  0x0204762C  arm  arm9
 *   G3D_SYSTEM_DeleteObject  0x02047738  arm  arm9
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct Z { u32 f0; u32 arr[4]; u32 f14; } Z;
typedef struct W { u8 pad[0x88]; u8 n; } W;

struct Rec;
extern void G3D_SYSTEM_DeleteAnime(struct Rec *p);
extern void G3D_SYSTEM_DeleteObject(struct Rec *p);
extern void G3D_SYSTEM_DeleteRender(struct Rec *p);

void FLDEFF_ENCOUNT_DeleteDrawSet(Z *z, W *w)
{
    int i;

    for (i = 0; i < w->n; i++)
        G3D_SYSTEM_DeleteAnime((struct Rec *)z->arr[i]);
    G3D_SYSTEM_DeleteObject((struct Rec *)z->f0);
    G3D_SYSTEM_DeleteRender((struct Rec *)z->f14);
}
