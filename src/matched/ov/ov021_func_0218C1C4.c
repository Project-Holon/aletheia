/*
 * function: FIELD_BUILDMODEL_UpdateAnimSetSlots
 * address:  0x0218C1C4
 * packet:   pkt_ov021_0218C1C4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Per-slot state machine step over four slots.
 *
 * symbols:
 *   G3D_SYSTEM_IncObjectAnimeFrame  0x020478B8  arm
 *   G3D_SYSTEM_SetObjectAnimeFrame  0x0204784C  arm
 *   G3D_SYSTEM_LoopObjectAnimeFrame  0x02047910  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef signed int     s32;
struct AnmCtl;
extern int G3D_SYSTEM_IncObjectAnimeFrame(void *a, int idx, int amount);
extern u32 G3D_SYSTEM_SetObjectAnimeFrame(struct AnmCtl *c, u16 idx, s32 *frame);
extern int G3D_SYSTEM_LoopObjectAnimeFrame(void *a, int idx, int amount);

void FIELD_BUILDMODEL_UpdateAnimSetSlots(u32 unused, u32 *st)
{
    int i;

    for (i = 0; i < 4; i++) {
        switch (st[2 + i]) {
        case 0:
        case 2:
            break;
        case 3:
            if (G3D_SYSTEM_IncObjectAnimeFrame((void *)st[0], (u16)i, 0x1000) == 0)
                st[2 + i] = 2;
            break;
        case 4:
            if (G3D_SYSTEM_IncObjectAnimeFrame((void *)st[0], (u16)i, -0x1000) == 0) {
                G3D_SYSTEM_SetObjectAnimeFrame((struct AnmCtl *)st[0], (u16)i, 0);
                st[2 + i] = 2;
            }
            break;
        case 1:
            G3D_SYSTEM_LoopObjectAnimeFrame((void *)st[0], (u16)i, 0x1000);
            break;
        }
    }
}
