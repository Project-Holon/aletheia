/*
 * function: FIELD_PLAYER_GetNowAttribute
 * address:  0x021A30C8
 * packet:   pkt_ov021_021A30C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   FIELDMAP_GetNogridMapper  0x02188C5C  thumb
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb
 *   FIELDMAP_GetMoveKind  0x02188CFC  thumb
 *   FLDMMDL_RAIL_GetNextLocation  0x0219E2F4  thumb
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb
 *   MAP_ATTR_GetAt  0x021AB0D4  thumb
 *   FIELD_NOGRID_MAPPER_GetAttribute  0x021BB3C4  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

typedef struct { s32 x, y, z; } VecFx32;
typedef struct { s32 a, b; } Pair;

extern u32 FIELDMAP_GetMoveKind(u8 *p);
extern u16 FIELDMAP_GetG3dMapper(void *p);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *ctx, struct VecFx32 *out);
extern int MAP_ATTR_GetAt(void *a, void *b);
extern void *FIELD_PLAYER_GetMmdl(u8 *p);
extern u32 FIELDMAP_GetNogridMapper(u8 *p);
extern void FLDMMDL_RAIL_GetNextLocation(void *o, void *out);
extern u32 FIELD_NOGRID_MAPPER_GetAttribute(u8 *p, char *a1);

u32 FIELD_PLAYER_GetNowAttribute(void **ctx)
{
    u32 r;

    if (FIELDMAP_GetMoveKind(ctx[0]) == 0) {
        VecFx32 pos;
        u16 z = FIELDMAP_GetG3dMapper(ctx[0]);
        FIELD_PLAYER_GetPos((unsigned char *)ctx, (struct VecFx32 *)&pos);
        r = MAP_ATTR_GetAt((void *)z, &pos);
    } else if (FIELDMAP_GetMoveKind(ctx[0]) == 1) {
        Pair v;
        void *o = FIELD_PLAYER_GetMmdl((u8 *)ctx);
        void *w = (void *)FIELDMAP_GetNogridMapper(ctx[0]);
        FLDMMDL_RAIL_GetNextLocation(o, &v);
        r = FIELD_NOGRID_MAPPER_GetAttribute(w, (char *)(&v));
    }
    return r;
}
