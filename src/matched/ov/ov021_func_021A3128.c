/*
 * function: FIELD_PLAYER_GetFrontAttribute
 * address:  0x021A3128
 * packet:   pkt_ov021_021A3128
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetMoveKind  0x02188CFC  thumb
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb
 *   FIELDMAP_GetNogridMapper  0x02188C5C  thumb
 *   FIELD_PLAYER_GetPosInDir  0x021A3364  thumb
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb
 *   MAP_ATTR_GetAt  0x021AB0D4  thumb
 *   FLDMMDL_RAIL_GetLocationByDir  0x0219E664  thumb
 *   FIELD_NOGRID_MAPPER_GetAttribute  0x021BB3C4  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 FIELDMAP_GetMoveKind(u8 *p);
extern u32 FIELDMAP_GetG3dMapper(u8 *p);
extern u32 FIELDMAP_GetNogridMapper(u8 *p);
extern void FIELD_PLAYER_GetPosInDir(u32 *a, int b, int *out);
extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern int MAP_ATTR_GetAt(void *a, void *b);
extern int FLDMMDL_RAIL_GetLocationByDir(void *o, u32 k, void *buf);
extern u32 FIELD_NOGRID_MAPPER_GetAttribute(u8 *p, char *a1);

u32 FIELD_PLAYER_GetFrontAttribute(u32 *a, u32 b)
{
    u32 r;
    u8 d[12];
    u8 c[8];

    if (FIELDMAP_GetMoveKind((u8 *)a[0]) == 0) {
        u32 h = FIELDMAP_GetG3dMapper((u8 *)a[0]);

        FIELD_PLAYER_GetPosInDir(a, b, (int *)d);
        r = MAP_ATTR_GetAt((void *)h, d);
    } else if (FIELDMAP_GetMoveKind((u8 *)a[0]) == 1) {
        void *t = FIELD_PLAYER_GetMmdl((u8 *)a);
        u32 h = FIELDMAP_GetNogridMapper((u8 *)a[0]);

        FLDMMDL_RAIL_GetLocationByDir(t, b, c);
        r = FIELD_NOGRID_MAPPER_GetAttribute((u8 *)h, (char *)c);
    }
    return r;
}
