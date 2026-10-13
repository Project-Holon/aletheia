/*
 * function: FIELD_G3DOBJ_TransferResourceTexture
 * address:  0x021C6854
 * packet:   pkt_ov021_021C6854
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3D_SYSTEM_TransVramTexture  0x02046FF8  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 f0; u32 f4; u32 f8[8]; u8 f28; u8 f29; } S;
extern int G3D_SYSTEM_TransVramTexture(int *self);
void FIELD_G3DOBJ_TransferResourceTexture(S *s)
{
    s->f29 = 0; if (s->f4 != 0) G3D_SYSTEM_TransVramTexture((int *)s->f4); else G3D_SYSTEM_TransVramTexture((int *)s->f0); s->f29 = 1;
}
