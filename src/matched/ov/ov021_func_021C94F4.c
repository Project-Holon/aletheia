/*
 * function: FLDEFF_IAIGIRI_LoadResources
 * address:  0x021C94F4
 * packet:   pkt_ov021_021C94F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sIaigiriAnimeFiles  0x021DE56C  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   G3D_SYSTEM_CreateResourceArcHandle  0x02046E24  arm
 *   G3D_SYSTEM_TransVramTexture  0x02046FF8  arm
 *   FIELD_EFFECT_GetArcHandle  0x021ABE24  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
typedef struct { u32 f0; u32 f4; u32 f8[3]; } Q;
extern u32 sIaigiriAnimeFiles[3];
extern u32 FIELD_EFFECT_GetArcHandle(u8 *p);
extern void *G3D_SYSTEM_CreateResourceArcHandle(u32 a0, u32 a1);
extern int G3D_SYSTEM_TransVramTexture(int *self);
void FLDEFF_IAIGIRI_LoadResources(Q *q)
{
    u32 h = FIELD_EFFECT_GetArcHandle((u8 *)q->f0);
    int i;
    q->f4 = (u32)G3D_SYSTEM_CreateResourceArcHandle(h, 0x52);
    G3D_SYSTEM_TransVramTexture((int *)q->f4);
    for (i = 0; i < 3; i++)
        q->f8[i] = (u32)G3D_SYSTEM_CreateResourceArcHandle(h, sIaigiriAnimeFiles[i]);
}
