/*
 * file:     field_effect_p53.c
 * unit:     yes
 * function: func_021AC074, func_021AC0A0
 * address:  0x021AC074
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021AC18C  0x021AC18C  thumb  ov021
 *   func_021AC134  0x021AC134  thumb  ov021
 *   func_021AC140  0x021AC140  thumb  ov021
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct V3 { int x, y, z; } V3;

typedef struct Obj_021AC074 Obj_021AC074;

typedef void (*ObjCb)(Obj_021AC074 *o, void *work);

struct Obj_021AC074 {
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

typedef struct Mgr_021AC074 { u32 count; u32 f4; Obj_021AC074 *objs; } Mgr_021AC074;

typedef struct Obj_021AC0A0 Obj_021AC0A0;

typedef struct Mgr_021AC0A0 Mgr_021AC0A0;

typedef struct ObjFuncs { ObjCb f0; ObjCb init; ObjCb exit; ObjCb f_c4; ObjCb f_c8; } ObjFuncs;

struct Obj_021AC0A0 {
    u32 active;
    u32 f4;
    u32 f8;
    V3 pos;
    u8 work[0xa0];
    ObjFuncs funcs;
    Mgr_021AC0A0 *mgr;
    void *fd0;
};

struct Mgr_021AC0A0 { u32 count; u32 f4; Obj_021AC0A0 *objs; u32 heap; };

extern void func_021AC18C(Obj_021AC074 *o);
extern void func_02082BCC(void *p, int v, int n);
extern void *func_02030DA8(u32 heap, void (*cb)(void), void *arg, u32 pri);
extern void func_021AC134(u32 a, u32 b);
extern void func_021AC140(Obj_021AC0A0 *o);
void func_021AC074(Mgr_021AC074 *m);
Obj_021AC0A0 *func_021AC0A0(Mgr_021AC0A0 *m, const ObjFuncs *funcs, const V3 *pos, u32 f4, u32 f8, u32 pri);


void func_021AC074(Mgr_021AC074 *m)
{
    u32 i;

    for (i = 0; i < m->count; i++) {
        if (m->objs[i].active != 0)
            func_021AC18C(&m->objs[i]);
    }
}


Obj_021AC0A0 *func_021AC0A0(Mgr_021AC0A0 *m, const ObjFuncs *funcs, const V3 *pos, u32 f4, u32 f8, u32 pri)
{
    u32 i = 0;
    Obj_021AC0A0 *o = m->objs;

    do {
        if (o->active == 0) {
            func_02082BCC(o, 0, sizeof(Obj_021AC0A0));
            o->active = 1;
            o->funcs = *funcs;
            o->f4 = f4;
            o->f8 = f8;
            if (pos != 0)
                o->pos = *pos;
            o->mgr = m;
            o->fd0 = func_02030DA8(m->heap, (void (*)(void))func_021AC134, o, pri);
            break;
        }
        i++;
        o++;
    } while (i < m->count);
    if (i < m->count) {
        func_021AC140(o);
        return o;
    }
    return 0;
}
