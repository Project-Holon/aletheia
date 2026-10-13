/*
 * function: FLDEFF_IAIGIRI_Exit
 * address:  0x021C963C
 * packet:   pkt_ov021_021C963C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3D_SYSTEM_DeleteRender  0x02047504  arm
 *   G3D_SYSTEM_DeleteAnime  0x0204762C  arm
 *   G3D_SYSTEM_DeleteObject  0x02047738  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 f0; u32 f4; u32 f8[3]; u32 f14; } Q;
struct Rec;
extern void G3D_SYSTEM_DeleteAnime(struct Rec *p);
extern void G3D_SYSTEM_DeleteObject(struct Rec *p);
extern void G3D_SYSTEM_DeleteRender(struct Rec *p);
void FLDEFF_IAIGIRI_Exit(void *task, Q *q)
{
    int i;
    for (i = 0; i < 3; i++)
        G3D_SYSTEM_DeleteAnime((struct Rec *)q->f8[i]);
    G3D_SYSTEM_DeleteObject((struct Rec *)q->f4);
    G3D_SYSTEM_DeleteRender((struct Rec *)q->f14);
}
