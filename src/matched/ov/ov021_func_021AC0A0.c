/*
 * function: FIELD_EFFECT_AddObjectToMgr
 * address:  0x021AC0A0
 * packet:   pkt_ov021_021AC0A0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_EFFECT_ObjectTask  0x021AC134  thumb  ov021
 *   FIELD_EFFECT_InitObject  0x021AC140  thumb  ov021
 *   MI_CpuFill8  0x02082BCC  arm  arm9
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct V3 { int x, y, z; } V3;
typedef struct Obj Obj;
typedef struct Mgr Mgr;
typedef void (*ObjCb)(Obj *o, void *work);
typedef struct ObjFuncs { ObjCb f0; ObjCb init; ObjCb exit; ObjCb f_c4; ObjCb f_c8; } ObjFuncs;
struct Obj {
    u32 active;
    u32 f4;
    u32 f8;
    V3 pos;
    u8 work[0xa0];
    ObjFuncs funcs;
    Mgr *mgr;
    void *fd0;
};
struct Mgr { u32 count; u32 f4; Obj *objs; u32 heap; };

extern void MI_CpuFill8(void *p, int v, int n);
extern void *func_02030DA8(u32 heap, void (*cb)(void), void *arg, u32 pri);
extern void FIELD_EFFECT_ObjectTask(u32 a, u32 b);
extern void FIELD_EFFECT_InitObject(Obj *o);

Obj *FIELD_EFFECT_AddObjectToMgr(Mgr *m, const ObjFuncs *funcs, const V3 *pos, u32 f4, u32 f8, u32 pri)
{
    u32 i = 0;
    Obj *o = m->objs;

    do {
        if (o->active == 0) {
            MI_CpuFill8(o, 0, sizeof(Obj));
            o->active = 1;
            o->funcs = *funcs;
            o->f4 = f4;
            o->f8 = f8;
            if (pos != 0)
                o->pos = *pos;
            o->mgr = m;
            o->fd0 = func_02030DA8(m->heap, (void (*)(void))FIELD_EFFECT_ObjectTask, o, pri);
            break;
        }
        i++;
        o++;
    } while (i < m->count);
    if (i < m->count) {
        FIELD_EFFECT_InitObject(o);
        return o;
    }
    return 0;
}
