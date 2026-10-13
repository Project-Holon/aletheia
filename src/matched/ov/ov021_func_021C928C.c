/*
 * function: FLDEFF_D06DENKI_PulseTrigger
 * address:  0x021C928C
 * packet:   pkt_ov021_021C928C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   G3D_SYSTEM_SetObjectAnimeFrame  0x0204784C  arm
 *   FIELD_EFFECT_GetObjectWork  0x021AC1E0  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 x, y, z; } V;
typedef struct { u8 pad[0x10]; u8 f10; u8 f11; u8 f12; u8 f13; u32 f14; u32 f18; u32 f1C; u32 f20; u32 f24; u8 pad28[0xc]; u32 f34; u32 f38; } E;
typedef signed int     s32;
struct AnmCtl;
extern int FIELD_EFFECT_GetObjectWork(u32 a);
extern u32 G3D_SYSTEM_SetObjectAnimeFrame(struct AnmCtl *c, u16 idx, s32 *frame);
void FLDEFF_D06DENKI_PulseTrigger(u32 a)
{
    u32 z;
    E *e;
    if (a != 0) {
        e = (E *)FIELD_EFFECT_GetObjectWork(a);
        if (e->f10 == 0) {
            z = 0;
            e->f10 = 1;
            G3D_SYSTEM_SetObjectAnimeFrame((struct AnmCtl *)e->f14, 1, (s32 *)(&z));
        }
    }
}
