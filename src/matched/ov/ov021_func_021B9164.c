/*
 * function: func_021B9164
 * address:  0x021B9164
 * packet:   pkt_ov021_021B9164
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The mode value 2 is an enum-typed local initialised at declaration: the enum
 * keeps it out of constant propagation, so it is materialised at entry, overlaps
 * s and the loaded x2c (r1) and takes r3, which the later zero then reuses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 pad[0x2C];
    void *x2c;
} Src;

typedef struct {
    u16 h0;
    u16 h2;
    int x4;
    u16 h8;
    u16 ha;
    int xc;
    int x10;
    int x14;
    int x18;
    void *x1c;
    int x20;
    Src *x24;
    u8 *x28;
    u8 b2c;
    u8 pad2d[5];
    u8 b32;
    u8 b33;
    u8 pad34[0x40];
    u8 b74;
    u8 pad75[3];
    u8 *x78;
} Obj;


typedef enum { MODE_0, MODE_1, MODE_2 } Mode;

void func_021B9164(Obj *o, Src *s, u8 *b)
{
    Mode m = MODE_2;
    o->x24 = s;
    o->x1c = s->x2c;
    o->h0 = m;
    o->b33 = 0;
    o->b32 = 0;
    o->b2c = 0;
    o->x78 = b;
    o->x4 = 0;
    o->xc = 0;
    o->x14 = 0;
    o->x20 = 0;
    o->x28 = b + 0x50;
    o->b74 = 0;
    o->h8 = 0;
}
