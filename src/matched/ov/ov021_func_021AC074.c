/*
 * function: FIELD_EFFECT_DrawObjectMgr
 * address:  0x021AC074
 * packet:   pkt_ov021_021AC074
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_EFFECT_DrawObject  0x021AC18C  thumb  ov021
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

typedef struct Mgr { u32 count; u32 f4; Obj *objs; } Mgr;

extern void FIELD_EFFECT_DrawObject(Obj *o);

void FIELD_EFFECT_DrawObjectMgr(Mgr *m)
{
    u32 i;

    for (i = 0; i < m->count; i++) {
        if (m->objs[i].active != 0)
            FIELD_EFFECT_DrawObject(&m->objs[i]);
    }
}
