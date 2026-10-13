/*
 * function: FIELD_BUILDMODEL_FreeAnimSet
 * address:  0x0218C0D8
 * packet:   pkt_ov021_0218C0D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   G3D_SYSTEM_GetObjectAnimeCount  0x0204779C  arm
 *   G3D_SYSTEM_GetObjectAnime  0x02047790  arm
 *   G3D_SYSTEM_DeleteAnime  0x0204762C  arm
 *   G3D_SYSTEM_GetObjectRender  0x02047788  arm
 *   G3D_SYSTEM_DeleteObject  0x02047738  arm
 *   G3D_SYSTEM_DeleteRender  0x02047504  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Rec;
extern int G3D_SYSTEM_GetObjectAnimeCount(int *p);
extern int G3D_SYSTEM_GetObjectAnime(int *p, int i);
extern void G3D_SYSTEM_DeleteAnime(struct Rec *p);
extern int G3D_SYSTEM_GetObjectRender(int *p);
extern void G3D_SYSTEM_DeleteObject(struct Rec *p);
extern void G3D_SYSTEM_DeleteRender(struct Rec *p);

void FIELD_BUILDMODEL_FreeAnimSet(void **s)
{
    int n;
    int i;
    void *r;

    if (s[0] != 0) {
        n = G3D_SYSTEM_GetObjectAnimeCount(s[0]);
        for (i = 0; i < n; i++) {
            void *o = (void *)G3D_SYSTEM_GetObjectAnime(s[0], (u16)i);
            if (o != 0)
                G3D_SYSTEM_DeleteAnime(o);
        }
        r = (void *)G3D_SYSTEM_GetObjectRender(s[0]);
        G3D_SYSTEM_DeleteObject(s[0]);
        s[0] = 0;
        s[1] = 0;
        G3D_SYSTEM_DeleteRender(r);
    }
}
