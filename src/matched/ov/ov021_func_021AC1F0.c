/*
 * function: FIELD_EFFECT_ApplyPaletteTable
 * address:  0x021AC1F0
 * packet:   pkt_ov021_021AC1F0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PALANM_ConvertGrayTable  0x02022040  thumb
 *   G3D_SYSTEM_GetResourceFile  0x02046F48  arm  arm9
 *   NNS_G3dGetTex  0x0206E964  arm  arm9
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct Res { u8 pad[0x30]; u16 h30; u16 pad32; u32 f34; u32 f38; } Res;
typedef struct X { u8 pad[0x24]; u32 f24; } X;

struct Tagged;
extern void *G3D_SYSTEM_GetResourceFile(struct Tagged *p);
extern unsigned char *NNS_G3dGetTex(unsigned char *p);
extern void PALANM_ConvertGrayTable(u16 *pal, int n, const u8 *table);

void FIELD_EFFECT_ApplyPaletteTable(X *x, void *b)
{
    Res *p;

    if (x->f24 != 0) {
        p = (Res *)NNS_G3dGetTex(G3D_SYSTEM_GetResourceFile(b));
        PALANM_ConvertGrayTable((u16 *)((u8 *)p + p->f38), p->h30 * 8u / 2, (const u8 *)x->f24);
    }
}
