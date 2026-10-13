/*
 * function: FLDEFF_D06DENKI_FollowStartEnding
 * address:  0x021C90AC
 * packet:   pkt_ov021_021C90AC
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
typedef struct { u8 pad[0x15]; u8 f15; u8 f16; u8 f17; u32 f18; } E;
typedef signed int     s32;
struct AnmCtl;
extern int FIELD_EFFECT_GetObjectWork(u32 a);
extern u32 G3D_SYSTEM_SetObjectAnimeFrame(struct AnmCtl *c, u16 idx, s32 *frame);
void FLDEFF_D06DENKI_FollowStartEnding(u32 a)
{
    u32 z;
    E *e;
    if (a != 0) {
        z = 0;
        e = (E *)FIELD_EFFECT_GetObjectWork(a);
        e->f15 = 1;
        e->f16 = 0;
        G3D_SYSTEM_SetObjectAnimeFrame((struct AnmCtl *)e->f18, 1, (s32 *)(&z));
    }
}
