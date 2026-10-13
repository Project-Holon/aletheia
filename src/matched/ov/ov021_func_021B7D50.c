/*
 * function: FIELD_RAIL_GetLocationWidthGrid
 * address:  0x021B7D50
 * packet:   pkt_ov021_021B7D50
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_RAIL_WORK_SetLocation  0x021B7EE4  thumb ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 pad[0x18];
    int x18;
} Inner;

typedef struct {
    u8 pad[0x1C];
    Inner *x1c;
} Outer;

extern void FIELD_RAIL_WORK_SetLocation(Inner *, void *);

int FIELD_RAIL_GetLocationWidthGrid(Outer *o, void *out)
{
    FIELD_RAIL_WORK_SetLocation(o->x1c, out);
    return o->x1c->x18 / 16;
}
