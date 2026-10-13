/*
 * function: FLDEFF_D06DENKI_PulseUpdate
 * address:  0x021C9334
 * packet:   pkt_ov021_021C9334
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3D_SYSTEM_IncObjectAnimeFrame  0x020478B8  arm
 *   G3D_SYSTEM_LoopObjectAnimeFrame  0x02047910  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 x, y, z; } V;
typedef struct { u8 pad[0x10]; u8 f10; u8 f11; u8 f12; u8 f13; u32 f14; u32 f18; u32 f1C; u32 f20; u32 f24; u8 pad28[0xc]; u32 f34; u32 f38; } E;
extern int G3D_SYSTEM_LoopObjectAnimeFrame(void *a, int idx, int amount);
extern int G3D_SYSTEM_IncObjectAnimeFrame(void *a, int idx, int amount);
void FLDEFF_D06DENKI_PulseUpdate(void *task, E *e)
{
    G3D_SYSTEM_LoopObjectAnimeFrame((void *)e->f14, 0, 0x1000);
    if (e->f10 == 1 && G3D_SYSTEM_IncObjectAnimeFrame((void *)e->f14, 1, 0x1000) == 0)
        e->f10 = 0;
}
