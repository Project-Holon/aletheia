/*
 * function: FIELD_ENCOUNT_GetEncountType
 * address:  0x021AA35C
 * packet:   pkt_ov021_021AA35C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 *
 * symbols:
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb
 *   FIELD_PLAYER_GetNowAttribute  0x021A30C8  thumb
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb
 *   MAP_ATTR_GetFlags  0x021AB0F8  thumb
 *   MAP_ATTR_IsPresent  0x021AB100  thumb
 *   MAP_ATTR_IsTallGrass  0x021AB140  thumb
 *   MAP_ATTR_IsAnyDoubleGrass  0x021AB29C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern u32 FIELDMAP_GetG3dMapper(u8 *p);
extern u32 FIELD_PLAYER_GetNowAttribute(void **ctx);
extern int MAP_ATTR_IsPresent(u32 attr);
extern u16 MAP_ATTR_GetFlags(u32 attr);
extern u16 MAP_ATTR_GetTerrainId(u32 attr);
extern int MAP_ATTR_IsTallGrass(int x);
extern int MAP_ATTR_IsAnyDoubleGrass(u16 x);

int FIELD_ENCOUNT_GetEncountType(void **ctx, int mode, u8 *out)
{
    void *y = FIELDMAP_GetFieldPlayer(ctx[0]);
    u32 attr;
    u16 fl;
    u16 t;

    FIELDMAP_GetG3dMapper(ctx[0]);
    *out = 0;
    attr = FIELD_PLAYER_GetNowAttribute(y);
    if (MAP_ATTR_IsPresent(attr) == 0)
        return 0xFF;
    fl = MAP_ATTR_GetFlags(attr);
    if (mode != 1 && (fl & 4) == 0)
        return 0xFF;
    t = MAP_ATTR_GetTerrainId(attr);
    if (MAP_ATTR_IsTallGrass(t))
        *out += 10;
    if (fl & 2) {
        if (mode == 1)
            return 4;
        return 3;
    }
    if (mode == 1)
        return 2;
    if (MAP_ATTR_IsAnyDoubleGrass(t))
        return 1;
    return 0;
}
