/*
 * function: FLDMMDL_BLACT_AddActorPosPalette
 * address:  0x0219C780
 * packet:   pkt_ov021_0219C780
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_BLACT_AddActorPos  0x0219C6B8  thumb  ov021
 *   FLDMMDL_SysGetBlActCont  0x0216D520  thumb  ov010
 *   BILLBOARD_ACT_SetEntryPaletteFromSlot  0x02050894  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { int x, y, z; } V3;
extern u32 FLDMMDL_BLACT_AddActorPos(u32 a, V3 *b, int c, u32 d, u16 e);
extern u32 FLDMMDL_SysGetBlActCont(void *p);
extern int BILLBOARD_ACT_SetEntryPaletteFromSlot(void *p, int idx, int j);

u32 FLDMMDL_BLACT_AddActorPosPalette(u32 a, V3 *b, int c, u32 d, u16 e, u16 g)
{
    u32 r = FLDMMDL_BLACT_AddActorPos(a, b, c, d, e);
    if (g != 0xFFFF) {
        BILLBOARD_ACT_SetEntryPaletteFromSlot((void *)(*(u32 *)(FLDMMDL_SysGetBlActCont((void *)a) + 4)), r, g);
    }
    return r;
}
