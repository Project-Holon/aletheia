/*
 * function: FLDEFF_IAIGIRI_FreeResources
 * address:  0x021C952C
 * packet:   pkt_ov021_021C952C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   G3D_SYSTEM_DeleteResource  0x02046EFC  arm
 *   G3D_SYSTEM_FreeVramTexture  0x020470D0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
typedef struct { u32 f0; u32 f4; u32 f8[3]; } Q;
struct Tagged;
extern void G3D_SYSTEM_DeleteResource(struct Tagged *p);
extern int G3D_SYSTEM_FreeVramTexture(u32 *p);
void FLDEFF_IAIGIRI_FreeResources(Q *q)
{
    int i;
    for (i = 0; i < 3; i++)
        G3D_SYSTEM_DeleteResource((struct Tagged *)q->f8[i]);
    G3D_SYSTEM_FreeVramTexture((u32 *)q->f4);
    G3D_SYSTEM_DeleteResource((struct Tagged *)q->f4);
}
