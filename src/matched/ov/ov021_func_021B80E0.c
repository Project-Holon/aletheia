/*
 * function: FIELD_RAIL_WORK_StartStep
 * address:  0x021B80E0
 * packet:   pkt_ov021_021B80E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 pad[0x2C];
    u8 b2c;
    u8 b2d;
    u16 h2e;
    u16 h30;
} Obj;

int FIELD_RAIL_WORK_StartStep(Obj *o, u16 a, u16 b)
{
    if (o->b2c == 0) {
        o->b2c = 1;
        o->b2d = 0;
        o->h2e = b;
        o->h30 = a;
        return 1;
    }
    return 0;
}
