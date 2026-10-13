/*
 * function: FLDEFF_IAIGIRI_Update
 * address:  0x021C9660
 * packet:   pkt_ov021_021C9660
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3D_SYSTEM_IncObjectAnimeFrame  0x020478B8  arm
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 f0; u32 f4; u32 f8[3]; u32 f14; } Q;
extern int G3D_SYSTEM_IncObjectAnimeFrame(void *a, int idx, int amount);
extern void FIELD_EFFECT_DeleteObject(u32 a);
void FLDEFF_IAIGIRI_Update(u32 a, Q *q)
{
    int done = 1;
    int i;
    for (i = 0; i < 3; i++) {
        if (G3D_SYSTEM_IncObjectAnimeFrame((void *)q->f4, (u16)i, (u32)0x1000) == 1)
            done = 0;
    }
    if (done)
        FIELD_EFFECT_DeleteObject(a);
}
