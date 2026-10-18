/*
 * function: FIELD_LIGHT_Apply
 * address:  0x021A066C
 * packet:   pkt_ov021_021A066C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3D_LIGHT_SetDirection  0x02048CA4  arm
 *   G3D_LIGHT_SetColor  0x02048CDC  arm
 *   NNS_G3dGlbMaterialColorDiffAmb  0x0206AA8C  arm
 *   NNS_G3dGlbMaterialColorSpecEmi  0x0206AAB0  arm
 *   FIELD_FOG_SetColorRgb  0x021A01C4  thumb  ov021
 *   G3X_SetClearColor  0x0207DD24  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 x, y, z;
} V3s;

typedef struct {
    u8 pad[0x35A];
    u8 used[4];
    u16 c[4];
    V3s b[4];
    u16 f37E;
    u16 f380;
    u16 f382;
    u16 f384;
    u16 f386;
    u16 f388;
    u16 active;
} W;

extern void G3D_LIGHT_SetDirection(u32, u8, const V3s *);
struct LightSlot;
extern void G3D_LIGHT_SetColor(struct LightSlot *slots, u32 i, u16 *in);
extern void NNS_G3dGlbMaterialColorDiffAmb(u32 v, u32 bits, u32 flag);
extern void NNS_G3dGlbMaterialColorSpecEmi(u32 v, u32 bits, u32 flag);
extern int FIELD_FOG_SetColorRgb(u32 a, u32 b);
extern void G3X_SetClearColor(u16, int, int, int, int);

void FIELD_LIGHT_Apply(const W *w, u32 a, u32 p)
{
    int i;
    V3s zb = {0, 0, 0};
    u16 zc = 0;

    if (w->active == 0) {
        return;
    }
    for (i = 0; i < 4; i++) {
        if (w->used[i]) {
            G3D_LIGHT_SetDirection(p, i, &w->b[i]);
            G3D_LIGHT_SetColor((struct LightSlot *)p, (u8)i, (u16 *)(&w->c[i]));
        } else {
            G3D_LIGHT_SetDirection(p, i, &zb);
            G3D_LIGHT_SetColor((struct LightSlot *)p, (u8)i, &zc);
        }
    }
    NNS_G3dGlbMaterialColorDiffAmb(w->f37E, w->f380, 1);
    NNS_G3dGlbMaterialColorSpecEmi(w->f382, w->f384, 0);
    FIELD_FOG_SetColorRgb(a, w->f386);
    G3X_SetClearColor(w->f388, 0x1F, 0x7FFF, 0, 0);
}
