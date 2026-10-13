/*
 * function: FIELD_G3D_MAP_DrawPlacedModels
 * address:  0x02169710
 * packet:   pkt_ov010_02169710
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Draws each placed model of a list: for every 0x14-byte entry at +0x9C
 * (count u16 at +0xA4) whose index is valid in the resource table at +0x98,
 * loads the base matrix g_renderStateDrawParams (G3 cmd 0x17, MTX_LOAD_4x3), multiplies
 * in a Y rotation by the entry's angle translated by obj+4 plus the entry's
 * position (cmd 0x19, MTX_MULT_4x3), and draws it.  The handed 240-byte
 * extent also holds an unlabelled 32-byte leaf at 0x021697E0.
 *
 * symbols:
 *   G3D_SYSTEM_GetObjectRender  0x02047788  arm
 *   G3D_SYSTEM_GetRenderObj  0x0204755C  arm
 *   NNS_G3dGeBufferOP_N  0x0206DDA4  arm
 *   VEC_Add        0x0207C9D0  arm
 *   MTX_RotY33_    0x0207AF1C  thumb
 *   FIELD_G3D_MAP_TestModelBox  0x021699A0  thumb  ov010
 *   G3D_SYSTEM_DrawRenderObj  0x02047C8C  arm
 *   FX_SinCosTable_   0x020A1B38  data
 *   g_renderStateDrawParams     0x02148B98  data
 */

typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

typedef struct Vec {
    int x, y, z;
} Vec;

typedef struct Mtx43 {
    int m[9];
    Vec t;
} Mtx43;

typedef struct Res {
    void *f00;
    void *f04;
} Res;

typedef struct ResTbl {
    Res *tbl;
    u32 count;
} ResTbl;

typedef struct Ent {
    u32 idx;        /* 0x00 */
    Vec pos;        /* 0x04 */
    u16 angle;      /* 0x10 */
    u16 pad12;
} Ent;

typedef struct Obj {
    u32 f00;
    Vec pos;        /* 0x04 */
    char pad10[0x98 - 0x10];
    ResTbl *res;    /* 0x98 */
    Ent *ents;      /* 0x9C */
    char padA0[4];
    u16 nents;      /* 0xA4 */
} Obj;

extern s16 FX_SinCosTable_[];
extern char g_renderStateDrawParams[];

extern int G3D_SYSTEM_GetObjectRender(int *p);
extern int G3D_SYSTEM_GetRenderObj(int *p);
struct P02047C8C;
extern void NNS_G3dGeBufferOP_N(u32 cmd, const void *params, u32 n);
extern void  VEC_Add(const Vec *a, const Vec *b, Vec *dst);
extern void  MTX_RotY33_(void *m, s16 sinv, s16 cosv);
extern int   FIELD_G3D_MAP_TestModelBox(void *p);
extern void G3D_SYSTEM_DrawRenderObj(struct P02047C8C *p);

void FIELD_G3D_MAP_DrawPlacedModels(Obj *obj)
{
    Res *tbl = obj->res->tbl;
    u32 count = obj->res->count;
    int i;

    if (count == 0 || tbl == 0) {
        return;
    }
    for (i = 0; i < obj->nents; i++) {
        u32 idx = obj->ents[i].idx;
        void *r;
        void *mdl;
        Mtx43 m;
        s16 s;
        s16 c;
        int a;

        if (idx == (u32)-1 || idx >= count) {
            continue;
        }
        r = (void *)G3D_SYSTEM_GetRenderObj((int *)G3D_SYSTEM_GetObjectRender(tbl[idx].f00));
        mdl = ((void **)r)[1];
        if (mdl == 0) {
            continue;
        }
        a = obj->ents[i].angle >> 4;
        s = FX_SinCosTable_[a * 2];
        c = FX_SinCosTable_[a * 2 + 1];
        NNS_G3dGeBufferOP_N(0x17, g_renderStateDrawParams, 12);
        VEC_Add(&obj->pos, &obj->ents[i].pos, &m.t);
        MTX_RotY33_(&m, s, c);
        NNS_G3dGeBufferOP_N(0x19, &m, 12);
        if (FIELD_G3D_MAP_TestModelBox(mdl) == 1) {
            G3D_SYSTEM_DrawRenderObj(r);
        }
    }
}
