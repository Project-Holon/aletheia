/*
 * function: FIELD_G3DOBJ_DestroyObject
 * address:  0x021C6A90
 * packet:   pkt_ov021_021C6A90
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3D_SYSTEM_DeleteAnime  0x0204762C  arm
 *   G3D_SYSTEM_GetObjectRender  0x02047788  arm
 *   G3D_SYSTEM_DeleteObject  0x02047738  arm
 *   G3D_SYSTEM_DeleteRender  0x02047504  arm
 *   func_02082C60  0x02082C60  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Rec;
extern void G3D_SYSTEM_DeleteAnime(struct Rec *p);
extern int G3D_SYSTEM_GetObjectRender(int *p);
extern void G3D_SYSTEM_DeleteObject(struct Rec *p);
extern void G3D_SYSTEM_DeleteRender(struct Rec *p);
extern void func_02082C60(void *p, int v, int n);

void FIELD_G3DOBJ_DestroyObject(u32 *p, u8 *q)
{
    u32 t;
    int i;

    if (p + 0x12) {
        for (i = 0; i < q[0x28]; i++)
            G3D_SYSTEM_DeleteAnime((struct Rec *)p[0x12 + i]);
    }
    if (p[0x11] != 0) {
        t = G3D_SYSTEM_GetObjectRender((int *)p[0x11]);
        G3D_SYSTEM_DeleteObject((struct Rec *)p[0x11]);
        G3D_SYSTEM_DeleteRender((struct Rec *)t);
    }
    func_02082C60(p, 0, 0x68);
}
