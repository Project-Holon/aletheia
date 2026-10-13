/*
 * function: FIELD_FK_DEMO_GetAnimeEndFrame
 * address:  0x021F36D4
 * packet:   pkt_ov056_021F36D4
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   G3D_SYSTEM_GetAnimeObj  0x02047674  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { char pad[4]; u16 f4; } Inner;
typedef struct { char pad[8]; Inner *f8; } Outer;

extern Outer *G3D_SYSTEM_GetAnimeObj(u32 a);

int FIELD_FK_DEMO_GetAnimeEndFrame(u32 a)
{
    return G3D_SYSTEM_GetAnimeObj(a)->f8->f4 << 12;
}
