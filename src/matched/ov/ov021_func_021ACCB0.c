/*
 * function: FLDEFF_NAMIPOKE_PlaceObjects
 * address:  0x021ACCB0
 * packet:   pkt_ov021_021ACCB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sNamipokeWaveAngles     0x021D9198  data  a2
 *   FIELD_EFFECT_GetFieldMapData  0x021ABE18  thumb  ov021
 *   FIELD_G3DOBJ_GetObjectTrans  0x021C6658  thumb  ov021
 *   BUTTON_MAN_MakeRotMtxXYZ  0x020520FC  arm
 *   FIELD_EFFECT_GetObjectPos  0x021AC1B8  thumb  ov021
 *   sNamipokeWakeOffsets     0x021D91C8  data  a4
 *   sNamipokeWakeAngles     0x021D91B0  data  a2
 *   FIELD_G3DOBJ_SetObjectHidden  0x021C6678  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

typedef struct V3 { s32 x, y, z; } V3;
typedef struct Ang { u16 x, y, z; } Ang;
typedef struct AngTbl { Ang e[4]; } AngTbl;
typedef struct PosTbl { V3 e[4]; } PosTbl;

typedef struct Node {
    V3 pos;
    V3 scale;
    u8 mtx[0x24];
} Node;

typedef struct Inner {
    u16 a;
    u16 b;
    u8 pad[0x18];
    u16 c;
    u16 pad2;
    V3 scale;
    V3 pos;
} Inner;

typedef struct B {
    u8 pad0[0xc];
    u16 fc;
    u8 pad1[0xa];
    u16 f18;
    u8 pad2[2];
    u32 *f1c;
    u8 pad3[0x18];
    Inner in;
} B;

extern AngTbl sNamipokeWaveAngles;
extern PosTbl sNamipokeWakeOffsets;
extern AngTbl sNamipokeWakeAngles;
extern u32 FIELD_EFFECT_GetFieldMapData(u8 *p);
extern int FIELD_G3DOBJ_GetObjectTrans(u32 a, u32 b);
struct Mtx33;
extern void BUTTON_MAN_MakeRotMtxXYZ(int ax, int ay, int az, struct Mtx33 *dst);
extern void FIELD_EFFECT_GetObjectPos(u32 a, Node *n);
extern void FIELD_G3DOBJ_SetObjectHidden(u32 a, u32 b, u32 c);

void FLDEFF_NAMIPOKE_PlaceObjects(u32 a, B *b)
{
    AngTbl t = sNamipokeWaveAngles;
    Ang *e = &t.e[b->fc];
    u32 obj;
    Node *n;

    obj = FIELD_EFFECT_GetFieldMapData((u8 *)(*b->f1c));
    n = (Node *)FIELD_G3DOBJ_GetObjectTrans(obj, b->f18);
    BUTTON_MAN_MakeRotMtxXYZ(e->x, e->y, e->z, (struct Mtx33 *)n->mtx);
    FIELD_EFFECT_GetObjectPos(a, n);
    if (b->in.a == 0) {
        Inner *in = &b->in;
        PosTbl pt = sNamipokeWakeOffsets;
        AngTbl at = sNamipokeWakeAngles;
        V3 *p = &pt.e[b->fc];
        Ang *g = &at.e[b->fc];
        n = (Node *)FIELD_G3DOBJ_GetObjectTrans(obj, in->c);
        BUTTON_MAN_MakeRotMtxXYZ(g->x, g->y, g->z, (struct Mtx33 *)n->mtx);
        FIELD_EFFECT_GetObjectPos(a, n);
        n->pos.x = n->pos.x + (in->pos.x + p->x);
        n->pos.y = n->pos.y + (in->pos.y + p->y);
        n->pos.z = n->pos.z + (in->pos.z + p->z);
        n->scale = in->scale;
        FIELD_G3DOBJ_SetObjectHidden(obj, in->c, 0);
    } else {
        FIELD_G3DOBJ_SetObjectHidden(obj, b->in.c, 1);
    }
}
