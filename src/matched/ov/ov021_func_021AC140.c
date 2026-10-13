/*
 * function: FIELD_EFFECT_InitObject
 * address:  0x021AC140
 * packet:   pkt_ov021_021AC140
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
typedef signed short   s16;
typedef signed char    s8;

typedef struct V3 { int x, y, z; } V3;
typedef struct Obj Obj;
typedef void (*ObjCb)(Obj *o, void *work);
struct Obj {
    u32 active;
    u32 f4;
    u32 f8;
    V3 pos;
    u8 work[0xa4];
    ObjCb init;
    ObjCb exit;
    ObjCb f_c4;
    ObjCb f_c8;
    u32 fcc;
    void *fd0;
};

void FIELD_EFFECT_InitObject(Obj *o)
{
    if (o != 0)
        o->init(o, o->work);
}
