/*
 * function: FLDEFF_IWAKUDAKI_Exit
 * address:  0x021ADE4C
 * packet:   pkt_ov021_021ADE4C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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

typedef struct Q { u32 f0; u32 f4; u32 arr[4]; u32 f18; u32 f1c; } Q;

struct Rec;
extern void G3D_SYSTEM_DeleteAnime(struct Rec *p);
extern void G3D_SYSTEM_DeleteObject(struct Rec *p);
extern void G3D_SYSTEM_DeleteRender(struct Rec *p);

void FLDEFF_IWAKUDAKI_Exit(u32 a, Q *q)
{
    int i;

    for (i = 0; i < 4; i++)
        G3D_SYSTEM_DeleteAnime((struct Rec *)q->arr[i]);
    G3D_SYSTEM_DeleteObject((struct Rec *)q->f4);
    G3D_SYSTEM_DeleteRender((struct Rec *)q->f18);
}
