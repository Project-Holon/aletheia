/*
 * function: FLDEFF_D06DENKI_FollowExit
 * address:  0x021C9164
 * packet:   pkt_ov021_021C9164
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   G3D_SYSTEM_DeleteRender  0x02047504  arm
 *   G3D_SYSTEM_DeleteAnime  0x0204762C  arm
 *   G3D_SYSTEM_DeleteObject  0x02047738  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 x, y, z; } V;
typedef struct { u8 pad[0x10]; u8 f10; u8 f11; u8 f12; u8 f13; u32 f14; u32 f18; u32 f1C; u32 f20; u32 f24; u8 pad28[0xc]; u32 f34; u32 f38; } E;
struct Rec;
extern void G3D_SYSTEM_DeleteAnime(struct Rec *p);
extern void G3D_SYSTEM_DeleteObject(struct Rec *p);
extern void G3D_SYSTEM_DeleteRender(struct Rec *p);
void FLDEFF_D06DENKI_FollowExit(void *task, E *e)
{
    G3D_SYSTEM_DeleteAnime((struct Rec *)e->f1C);
    G3D_SYSTEM_DeleteAnime((struct Rec *)e->f20);
    G3D_SYSTEM_DeleteObject((struct Rec *)e->f18);
    G3D_SYSTEM_DeleteRender((struct Rec *)e->f24);
    G3D_SYSTEM_DeleteObject((struct Rec *)e->f34);
    G3D_SYSTEM_DeleteRender((struct Rec *)e->f38);
}
