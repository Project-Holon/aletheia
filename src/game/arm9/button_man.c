/*
 * file:     button_man.c
 * unit:     yes
 * function: BUTTON_MAN_GetBlock, BUTTON_MAN_GetPos, BUTTON_MAN_SetPos, BUTTON_MAN_GetRot, BUTTON_MAN_GetScaleX, BUTTON_MAN_SetScaleX, BUTTON_MAN_GetScaleY, BUTTON_MAN_SetScaleY, BUTTON_MAN_GetOffsetX, BUTTON_MAN_SetOffsetX, BUTTON_MAN_GetOffsetY, BUTTON_MAN_SetOffsetY, BUTTON_MAN_GetAngle, BUTTON_MAN_GetAlpha, BUTTON_MAN_SetEmitterPos, BUTTON_MAN_SetRot, BUTTON_MAN_SetAngle, BUTTON_MAN_SetAlpha, BUTTON_MAN_FindRowData, BUTTON_MAN_SetRow2, BUTTON_MAN_SetRow3Half, BUTTON_MAN_SetRow5, BUTTON_MAN_SetCallback, BUTTON_MAN_SetUserData, BUTTON_MAN_GetUserData, BUTTON_MAN_Func1A3C, BUTTON_MAN_AppendList0, BUTTON_MAN_Func1AA0, BUTTON_MAN_AppendList1, BUTTON_MAN_GetResourceType, BUTTON_MAN_CallHandlerById, BUTTON_MAN_Create, BUTTON_MAN_ClearSlot, BUTTON_MAN_Delete, BUTTON_MAN_UpdateSlots, BUTTON_MAN_SlotHandlerIdle, BUTTON_MAN_SlotHandlerPressed, BUTTON_MAN_SlotSetKind, BUTTON_MAN_RotScaleMtx22, BUTTON_MAN_InitSphere, BUTTON_MAN_SegmentSphereTest, BUTTON_MAN_InitSegment, BUTTON_MAN_ScaleVec, BUTTON_MAN_MakeRotMtxXYZ, BUTTON_MAN_MakeLookAtMtx, BUTTON_MAN_ConvertUcs2ToSjis, BUTTON_MAN_Ucs2CharToSjis
 * address:  0x02051788
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Own object: the button_man.c __FILE__ string (layout/file_anchors.txt, pool
 * of BUTTON_MAN_Create).  Builds EXACT with 1.1p1 and dsi/1.2, DIFF with
 * ../1.2/sp2 (the compiler of unit_020524C8.c next to it) and with
 * -proc arm7tdmi (the flags of unit_0205841C.c).
 *
 * symbols:
 *   func_02057EF8  0x02057EF8  arm
 *   func_02057F8C  0x02057F8C  arm
 *   func_020580A8  0x020580A8  arm
 *   func_02058180  0x02058180  arm
 *   func_02058204  0x02058204  arm
 *   func_020582CC  0x020582CC  arm
 *   g_020A8140   0x020A8140  data
 *   g_pParticleMan   0x02146A88  data
 *   g_020A8148   0x020A8148  data
 *   func_0207E1F8  0x0207E1F8  arm
 *   func_0207E24C  0x0207E24C  arm
 *   func_0207E2A0  0x0207E2A0  arm
 *   func_0207E330  0x0207E330  arm
 *   func_0207E22C  0x0207E22C  arm
 *   func_0207E280  0x0207E280  arm
 *   func_0207E2F0  0x0207E2F0  arm
 *   func_0207E388  0x0207E388  arm
 *   func_02030734   0x02030734  arm
 *   func_020307B0   0x020307B0  arm
 *   g_020A7FCC      0x020A7FCC  data
 *   g_020A15E8    0x020A15E8  data
 *   TOUCHPANEL_GetCont 0x02035C38  arm
 *   TOUCHPANEL_HitCont 0x02035BA4  arm
 *   TOUCHPANEL_HitTrg 0x02035C08  arm
 *   TOUCHPANEL_GetTrg 0x02035C60  arm
 *   MTX_Rot22_       0x0207AD64  thumb
 *   MTX_ScaleApply22 0x0207AD70  arm
 *   FX_Inv    0x0207C778  arm
 *   FX_SinCosTable_     0x020A1B38  data
 *   VEC_Subtract    0x0207CA00  arm
 *   VEC_DotProduct  0x0207CA68  arm
 *   VEC_Mag         0x0207CBD0  arm
 *   VEC_Normalize   0x0207CCA4  arm
 *   FX_Div          0x0207C768  arm
 *   MTX_Identity33_  0x0207ADC4  arm
 *   MTX_RotX33_      0x0207AF00  thumb
 *   MTX_RotY33_      0x0207AF1C  thumb
 *   MTX_RotZ33_      0x0207AF38  thumb
 *   MTX_Concat33     0x0207B388  arm
 *   FX_Atan2Idx    0x0207CFB8  arm
 *   STRBUF_GetEosChar  0x02045A98  arm
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;
typedef long long      s64;

typedef struct {
    s32 x, y, z;
} Vec3;

typedef struct {
    u16 x, y, z;
} Vec3U16;

typedef struct {
    s32 m[4];
} Mtx22;

typedef struct {
    s32 m[9];
} Mtx33;

/* Segment p0 -> dir with a capsule radius. */
typedef struct {
    Vec3 p0;
    Vec3 dir;
    s32  radius;
} Seg;

typedef struct {
    Vec3 c;
    s32  r;
} Sphere;

/* Result block of the segment-versus-sphere test. */
typedef struct {
    u32  hit;
    Vec3 n;
    s32  d;
} HitInfo;

/* 8-byte row of the table at Obj3D.blk->ents; fn is the row's handler. */
struct Ent {
    void *fn;
    void *data;
};

struct BlkInner {
    u8   pad00[0x04];
    Vec3 pos;               /* +0x04 */
};

struct Blk {
    struct BlkInner *inner; /* +0x00, re-read per statement */
    u8               pad04[0x14];
    struct Ent      *ents;  /* +0x18 */
    u16              count; /* +0x1C */
};

/* The 3D object the accessors at 0x02051788..0x02051B04 work on. */
struct Obj3D {
    u8      pad00[0x20];
    struct Blk *blk;        /* +0x20 */
    u8      pad24[0x04];
    Vec3    emitPos;        /* +0x28 */
    Vec3    pos;            /* +0x34 */
    u8      pad40[0x10];
    Vec3U16 rot;            /* +0x50 */
    u8      pad56[0x06];
    s32     scaleX;
    s32     scaleY;
    s32     offsetX;
    s32     offsetY;
    s32     angle;
    u16     alpha;
    u8      pad72[0x1E];
    s32     callback;
    s32     userData;
};

/* Pair of handle lists the two append functions fill. */
struct HandleLists {
    u8  pad00[0x58];
    u32 list0[0x40];        /* +0x58 */
    u32 list1[0x40];        /* +0x158 */
    u8  pad258[0x04];
    u16 count0;             /* +0x25C */
    u16 count1;             /* +0x25E */
};

struct SysCtx {
    u8                 pad00[0x44];
    struct HandleLists *base;  /* +0x44 */
};

struct Slot {
    u8  kind;               /* index into g_020A15E8: 0 idle, 1 pressed */
    u8  state;
    u16 count;
};

struct ButtonMan {
    u8          *rects;     /* +0x00, 4-byte entries ended by 0xFF */
    u32          n;         /* +0x04 */
    void       (*cb)(s32, s32, s32);  /* +0x08 */
    s32          arg;       /* +0x0C */
    struct Slot *slots;     /* +0x10 */
};

/* Rows of the 3D rig; only their addresses are compared. */
extern void func_02057EF8(void *a, void *b);
extern void func_02057F8C(void *a, void *s, int unused, void *c);
extern void func_020580A8(void *o, u8 *dst);
extern void func_02058180(void *a, void *b, int *c);
extern void func_02058204(void *o, void *s, int *dst);
extern void func_020582CC(void *o, void *s, int *dst);
extern u32 func_020616CC(u32 size, u32 flag, u32 dir);
extern int func_020614D4(int a, int b, int c);
extern void *func_0207E1F8(void);
extern void *func_0207E24C(void);
extern void *func_0207E2A0(void);
extern void *func_0207E330(void);
extern int func_0207E22C(void);
extern int func_0207E280(void);
extern void *func_0207E2F0(void);
extern void *func_0207E388(void);
extern void *func_02030734(u16 id, u32 size, u32 flags, void *file, u32 line);
extern u32 func_020307B0(void *p);
extern s32 TOUCHPANEL_GetCont(void);
extern int TOUCHPANEL_HitCont(const void *p);
extern int TOUCHPANEL_HitTrg(const void *p);
extern s32 TOUCHPANEL_GetTrg(void);
extern void MTX_Rot22_(Mtx22 *mtx, s32 sinVal, s32 cosVal);
extern void MTX_ScaleApply22(const Mtx22 *src, Mtx22 *dst, s32 x, s32 y);
extern long FX_Inv(long v);
extern void VEC_Subtract(const Vec3 *a, const Vec3 *b, Vec3 *d);
extern int  VEC_DotProduct(const Vec3 *a, const Vec3 *b);
extern int  VEC_Mag(const Vec3 *v);
extern void VEC_Normalize(const Vec3 *v, Vec3 *d);
extern int  FX_Div(int a, int b);
extern void MTX_Identity33_(Mtx33 *m);
extern void MTX_RotX33_(Mtx33 *m, s16 sinv, s16 cosv);
extern void MTX_RotY33_(Mtx33 *m, s16 sinv, s16 cosv);
extern void MTX_RotZ33_(Mtx33 *m, s16 sinv, s16 cosv);
extern void MTX_Concat33(const Mtx33 *a, const Mtx33 *b, Mtx33 *dst);
extern int  FX_Atan2Idx(int y, int x);
extern u16 STRBUF_GetEosChar(void);

extern struct SysCtx *g_pParticleMan;
extern char g_020A7FCC[];
extern s16 FX_SinCosTable_[];
extern u32 (*g_020A8140)(u32 a, u32 b, u32 c);
extern u32 (*g_020A8148)(u32 a, u32 b, u32 c);
extern s32 (*const g_020A15E8[])(struct Slot *, s32, s32);

int BUTTON_MAN_GetBlock(struct Obj3D *p);
void BUTTON_MAN_GetPos(struct Obj3D *p, Vec3 *out);
void BUTTON_MAN_SetPos(struct Obj3D *p, const Vec3 *v);
void BUTTON_MAN_GetRot(struct Obj3D *p, Vec3U16 *out);
int BUTTON_MAN_GetScaleX(struct Obj3D *p);
void BUTTON_MAN_SetScaleX(struct Obj3D *p, int v);
int BUTTON_MAN_GetScaleY(struct Obj3D *p);
void BUTTON_MAN_SetScaleY(struct Obj3D *p, int v);
short BUTTON_MAN_GetOffsetX(struct Obj3D *p);
void BUTTON_MAN_SetOffsetX(struct Obj3D *p, int v);
short BUTTON_MAN_GetOffsetY(struct Obj3D *p);
void BUTTON_MAN_SetOffsetY(struct Obj3D *p, int v);
short BUTTON_MAN_GetAngle(struct Obj3D *p);
unsigned short BUTTON_MAN_GetAlpha(struct Obj3D *p);
void BUTTON_MAN_SetEmitterPos(struct Obj3D *e, const Vec3 *q);
void BUTTON_MAN_SetRot(struct Obj3D *o, const Vec3U16 *v);
void BUTTON_MAN_SetAngle(struct Obj3D *o, u32 v);
void BUTTON_MAN_SetAlpha(struct Obj3D *o, u16 v);
void *BUTTON_MAN_FindRowData(struct Obj3D *obj, int kind);
void BUTTON_MAN_SetRow2(struct Obj3D *p, Vec3 *q);
void BUTTON_MAN_SetRow3Half(struct Obj3D *p, u16 *q);
void BUTTON_MAN_SetRow5(struct Obj3D *p, Vec3 *q);
void BUTTON_MAN_SetCallback(struct Obj3D *p, int v);
void BUTTON_MAN_SetUserData(struct Obj3D *p, int v);
int BUTTON_MAN_GetUserData(struct Obj3D *p);
unsigned int BUTTON_MAN_Func1A3C(int a0, int a1, int a2, int a3);
u32 BUTTON_MAN_AppendList0(u32 a, u32 b);
int BUTTON_MAN_Func1AA0(int a, int b);
u32 BUTTON_MAN_AppendList1(u32 a, u32 b);
u16 BUTTON_MAN_GetResourceType(void *res);
int BUTTON_MAN_CallHandlerById(int i);
struct ButtonMan *BUTTON_MAN_Create(u8 *rects, void (*cb)(s32, s32, s32), s32 arg, int heap);
void BUTTON_MAN_ClearSlot(struct Slot *slot);
void BUTTON_MAN_Delete(struct ButtonMan *bm);
s32 BUTTON_MAN_UpdateSlots(struct ButtonMan *c);
int BUTTON_MAN_SlotHandlerIdle(struct Slot *p, int a, int b);
int BUTTON_MAN_SlotHandlerPressed(struct Slot *p, u32 x);
void BUTTON_MAN_SlotSetKind(struct Slot *p, int a);
void BUTTON_MAN_RotScaleMtx22(Mtx22 *mtx, u32 ang, long scaleX, long scaleY, u8 mode);
void BUTTON_MAN_InitSphere(Sphere *dst, Vec3 *src, unsigned radius);
u32 BUTTON_MAN_SegmentSphereTest(Seg *seg, Sphere *b, HitInfo *out);
void BUTTON_MAN_InitSegment(Seg *p, Vec3 *q, Vec3 *r, u32 v);
void BUTTON_MAN_ScaleVec(const Vec3 *v, int s, Vec3 *dst);
void BUTTON_MAN_MakeRotMtxXYZ(int ax, int ay, int az, Mtx33 *dst);
void BUTTON_MAN_MakeLookAtMtx(const Vec3 *v, Mtx33 *dst);
void BUTTON_MAN_ConvertUcs2ToSjis(u8 *a, u8 *b, u32 n);
int BUTTON_MAN_Ucs2CharToSjis(u16 *src, char *dst, u32 *stop);

/*
 * Returns the word at offset 0x20. Filed as the witness for ov094 func_021FA458.
 */
int BUTTON_MAN_GetBlock(struct Obj3D *p)
{
    return (int)p->blk;
}

/*
 * Copies the vector at offset 0x34 out. Filed as the witness for ov094 func_021FD1CC.
 */
void BUTTON_MAN_GetPos(struct Obj3D *p, Vec3 *out)
{
    *out = p->pos;
}

/*
 * Stores a vector at offset 0x34. Filed as the witness for ov094 func_021FD1CC.
 */
void BUTTON_MAN_SetPos(struct Obj3D *p, const Vec3 *v)
{
    p->pos = *v;
}

/*
 * Copies the three halfwords at offset 0x50 out. Filed as the witness for ov094 func_021FD1CC.
 */
void BUTTON_MAN_GetRot(struct Obj3D *p, Vec3U16 *out)
{
    *out = p->rot;
}

/*
 * Returns the word at offset 0x5c. Filed as the witness for ov094 func_021FD1CC.
 */
int BUTTON_MAN_GetScaleX(struct Obj3D *p)
{
    return p->scaleX;
}

/*
 * Stores the word at offset 0x5c. Filed as the witness for ov094 func_021FD1CC.
 */
void BUTTON_MAN_SetScaleX(struct Obj3D *p, int v)
{
    p->scaleX = v;
}

/*
 * Returns the word at offset 0x60. Filed as the witness for ov094 func_021FD1CC.
 */
int BUTTON_MAN_GetScaleY(struct Obj3D *p)
{
    return p->scaleY;
}

/*
 * Stores the word at offset 0x60. Filed as the witness for ov094 func_021FD1CC.
 */
void BUTTON_MAN_SetScaleY(struct Obj3D *p, int v)
{
    p->scaleY = v;
}

/*
 * Returns the word at offset 0x64 as a short. Filed as the witness for ov094 func_021FD1CC.
 */
short BUTTON_MAN_GetOffsetX(struct Obj3D *p)
{
    return p->offsetX;
}

/*
 * Stores the word at offset 0x64. Filed as the witness for ov094 func_021FD1CC.
 */
void BUTTON_MAN_SetOffsetX(struct Obj3D *p, int v)
{
    p->offsetX = v;
}

/*
 * Returns the word at offset 0x68 as a short. Filed as the witness for ov094 func_021FD1CC.
 */
short BUTTON_MAN_GetOffsetY(struct Obj3D *p)
{
    return p->offsetY;
}

/*
 * Stores the word at offset 0x68. Filed as the witness for ov094 func_021FD1CC.
 */
void BUTTON_MAN_SetOffsetY(struct Obj3D *p, int v)
{
    p->offsetY = v;
}

/*
 * Returns the word at offset 0x6c as a short. Filed as the witness for ov094 func_021FD1CC.
 */
short BUTTON_MAN_GetAngle(struct Obj3D *p)
{
    return p->angle;
}

/*
 * Returns the halfword at offset 0x70. Filed as the witness for ov094 func_021FD1CC.
 */
unsigned short BUTTON_MAN_GetAlpha(struct Obj3D *p)
{
    return p->alpha;
}

/*
 * particle.c (wave 13): the emitter's three-word position at +0x28..+0x30 is
 * the caller's vector plus the vector at +4 of the block the private 3D
 * block's first word names (+0x20 -> +0x00 -> +0x04/+0x08/+0x0C).
 *
 * WHAT CLOSED IT (docs/notes/pkt_02051838.c.txt: 72 against 72 with 10 bytes
 * out via a `volatile` parameter, permuter exhausted at 3000): the caller's
 * vector is a `const VecFx32 *`.  mwccarm lets a load through a const-
 * qualified pointer move above a store through a non-const one, so all three
 * q reads are hoisted to the top in the image's order (r4, r3, r2 -- a
 * descending run the peephole cannot merge into one ldm), while the block's
 * inner pointer is still re-read before each sum because the stores to the
 * emitter may alias it.  No named locals: each component is one statement.
 * The `volatile` spelling only imitated that hoisting and allocated
 * differently; plain non-const spellings keep the q reads in place and merge
 * two of them into an ldm (68 bytes).
 */
void BUTTON_MAN_SetEmitterPos(struct Obj3D *e, const Vec3 *q)
{
    e->emitPos.x = q->x + e->blk->inner->pos.x;
    e->emitPos.y = q->y + e->blk->inner->pos.y;
    e->emitPos.z = q->z + e->blk->inner->pos.z;
}

/*
 * Setter on the same object as its packet-mate src/matched/BUTTON_MAN_FindRowData.c:
 * copies a three-component 16-bit vector into the object's 0x50..0x54
 * triple.  The three loads come out ahead of the three stores, which is the
 * plain field-by-field spelling; a struct assignment would be ldm/stm.
 */
void BUTTON_MAN_SetRot(struct Obj3D *o, const Vec3U16 *v)
{
    o->rot.x = v->x;
    o->rot.y = v->y;
    o->rot.z = v->z;
}

/*
 * Word setter on the same object as its packet-mate
 * src/matched/BUTTON_MAN_FindRowData.c: stores the argument into field 0x6c.
 */
void BUTTON_MAN_SetAngle(struct Obj3D *o, u32 v)
{
    o->angle = v;
}

/*
 * Halfword setter on the same object as its packet-mate
 * src/matched/BUTTON_MAN_FindRowData.c: stores the argument into field 0x70.
 */
void BUTTON_MAN_SetAlpha(struct Obj3D *o, u16 v)
{
    o->alpha = v;
}

/*
 * Linear search of the block at obj+0x20 for the first 8-byte entry whose
 * first word is the handler address selected by `kind`, returning that
 * entry's second word (or NULL).  The six handlers are the 3D-rig rows at
 * 0x02057EF8..0x020582CC, all pool words and all attested by the sibling
 * pool at 0x02052DB0.
 *
 * Two tells decide the shape.  Declaring the index BEFORE the count is what
 * puts the count in r4 and the index in lr (declaration-order-decides-which-
 * register-a-local-gets).  And the image's `adds ip, r5, lr, lsl #3` / `beq`
 * pair at +0040 is a redundant null test on the entry pointer: the `adds`
 * form only appears when the source writes `if (e == 0) continue;`, which
 * folds into the address computation.  Without it the switch is four bytes
 * shorter and every branch target shifts.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BUTTON_MAN_FindRowData.c \
 *       --func BUTTON_MAN_FindRowData --addr 0x020518AC --cc 1.1p1 --arm
 */
void *BUTTON_MAN_FindRowData(struct Obj3D *obj, int kind)
{
    struct Blk *b = obj->blk;
    int i;
    int n = b->count;

    if (n == 0)
        return 0;

    for (i = 0; i < n; i++) {
        struct Ent *e = &b->ents[i];
        if (e == 0)
            continue;
        switch (kind) {
        case 0:
            if (e->fn == (void *)func_020582CC)
                return e->data;
            break;
        case 1:
            if (e->fn == (void *)func_02058204)
                return e->data;
            break;
        case 2:
            if (e->fn == (void *)func_02058180)
                return e->data;
            break;
        case 3:
            if (e->fn == (void *)func_020580A8)
                return e->data;
            break;
        case 4:
            if (e->fn == (void *)func_02057F8C)
                return e->data;
            break;
        case 5:
            if (e->fn == (void *)func_02057EF8)
                return e->data;
            break;
        default:
            return 0;
        }
    }
    return 0;
}

/*
 * Copies a 12-byte record into the slot BUTTON_MAN_FindRowData hands back for class 2.
 * Verified with:
 *   python tools/match.py one --src src/matched/BUTTON_MAN_SetRow2.c \
 *       --func BUTTON_MAN_SetRow2 --addr 0x020519C4 --cc 1.1p1 --arm
 */
void BUTTON_MAN_SetRow2(struct Obj3D *p, Vec3 *q)
{
    Vec3 *r = BUTTON_MAN_FindRowData(p, 2);

    if (r != 0)
        *r = *q;
}

/*
 * The class-3 slot carries only a halfword at +2.
 * Verified with:
 *   python tools/match.py one --src src/matched/BUTTON_MAN_SetRow3Half.c \
 *       --func BUTTON_MAN_SetRow3Half --addr 0x020519E4 --cc 1.1p1 --arm
 */
void BUTTON_MAN_SetRow3Half(struct Obj3D *p, u16 *q)
{
    u16 *r = BUTTON_MAN_FindRowData(p, 3);

    if (r != 0)
        r[1] = *q;
}

/*
 * Same 12-byte copy as BUTTON_MAN_SetRow2, out of the class-5 slot.
 * Verified with:
 *   python tools/match.py one --src src/matched/BUTTON_MAN_SetRow5.c \
 *       --func BUTTON_MAN_SetRow5 --addr 0x02051A04 --cc 1.1p1 --arm
 */
void BUTTON_MAN_SetRow5(struct Obj3D *p, Vec3 *q)
{
    Vec3 *r = BUTTON_MAN_FindRowData(p, 5);

    if (r != 0)
        *r = *q;
}

/*
 * Unlabelled ARM leaf in the ARM9 module: an 8-byte store helper,
 * `p[0x90/4] = v`. With BUTTON_MAN_SetUserData (the +0x94 twin) it is the storage
 * setter pair the ov118 functions func_021D6EAC/func_021D6F0C call.
 *
 * Addresses are Black-image addresses.
 */
void BUTTON_MAN_SetCallback(struct Obj3D *p, int v)
{
    p->callback = v;
}

/*
 * Unlabelled ARM leaf in the ARM9 module: an 8-byte store helper,
 * `p[0x94/4] = v`. The +0x94 twin of BUTTON_MAN_SetCallback.
 *
 * Addresses are Black-image addresses.
 */
void BUTTON_MAN_SetUserData(struct Obj3D *p, int v)
{
    p->userData = v;
}

/*
 * Unlabelled ARM leaf in the ARM9 module: an 8-byte load helper,
 * `return p[0x94/4]`. The getter half of BUTTON_MAN_SetUserData.
 *
 * Addresses are Black-image addresses.
 */
int BUTTON_MAN_GetUserData(struct Obj3D *p)
{
    return p->userData;
}

/*
 * Calls func_020614D4 with a constant 0 as its third argument and returns the
 * low halfword of the result scaled by eight (a2 and a3 are unused).
 */
unsigned int BUTTON_MAN_Func1A3C(int a0, int a1, int a2, int a3)
{
    int t0 = func_020614D4(a0, a1, 0);

    return (unsigned int)(t0 << 16) >> 13;
}

/*
 * The caller's registered handler (the function pointer in the clact.c global
 * 0x020A8140) is invoked with the two incoming arguments and a literal 0 in
 * r2; r1 is never written, so the callee takes at least two arguments and the
 * third is a constant zero.
 *
 * The result is appended to the current context's u32 table: the count
 * halfword at base+0x25c is loaded once, incremented and stored back, and the
 * value is written to base+0x58+count*4 - the store uses the OLD count, so the
 * table is indexed before the increment.  The return value is the low
 * halfword of the result scaled by eight, which the compiler writes as the
 * fused unequal shift pair lsl #16 / lsr #13 (a u16 cast folded into the
 * multiply, see
 * docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md).
 *
 * The twin at 0x02051AB8 is the same shape over the parallel table 0x100
 * higher (count at +0x25e, elements at +0x158).
 */
u32 BUTTON_MAN_AppendList0(u32 a, u32 b)
{
    u32 v = g_020A8140(a, b, 0);
    struct HandleLists *base = g_pParticleMan->base;
    u16 n = base->count0;

    base->count0 = n + 1;
    base->list0[n] = v;

    return (u16)v * 8;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/BUTTON_MAN_Func1AA0.c \
 *       --func BUTTON_MAN_Func1AA0 --addr 0x02051AA0 --cc 1.1p1 --arm
 */
int BUTTON_MAN_Func1AA0(int a, int b)
{
    return (u16)func_020616CC(a, b, 1) << 3;
}

/*
 * Byte-for-byte the twin of BUTTON_MAN_AppendList0 over the second table: same
 * indirect call through the handler at 0x020A8140 (two arguments forwarded,
 * a literal 0 in r2), same append-and-count shape, but the count halfword is
 * at base+0x25e and the elements at base+0x158, i.e. the parallel table 0x100
 * bytes higher with its own counter.
 */
u32 BUTTON_MAN_AppendList1(u32 a, u32 b)
{
    u32 v = g_020A8148(a, b, 0);
    struct HandleLists *base = g_pParticleMan->base;
    u16 n = base->count1;

    base->count1 = n + 1;
    base->list1[n] = v;

    return (u16)v * 8;
}

/*
 * ARM leaf, seeded 2026-09-27 from the ov195 call site 0x02208954
 * (func_0220887C). Returns the u16 at +8 of its argument.
 *
 * Addresses are Black-image addresses.
 */
u16 BUTTON_MAN_GetResourceType(void *res)
{
    return ((u16 *)res)[4];
}

/*
 * Eight-way dispatch on a button-man handler id: each of the eight ids tail
 * calls its own handler and returns that handler's value, and any id above 7
 * falls out of the switch to `return 0;`.  That trailing `return 0;` is what
 * the image has at +0x7C (`mov r0, #0; pop {r3, pc}`) and it is also the
 * addls-skipped target at +0x0C, so the `switch` has no `default:` label at
 * all - writing the arms as bare calls (or with `break`) instead of
 * `return f();` loses those eight bytes and the arms' `pop {r3, pc}` with
 * them.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BUTTON_MAN_CallHandlerById.c \
 *       --func BUTTON_MAN_CallHandlerById --addr 0x02051B0C --cc 1.1p1 --arm
 */
int BUTTON_MAN_CallHandlerById(int i)
{
    switch (i) {
    case 0: return (int)func_0207E1F8();
    case 1: return (int)func_0207E24C();
    case 2: return (int)func_0207E2A0();
    case 3: return (int)func_0207E330();
    case 4: return func_0207E22C();
    case 5: return func_0207E280();
    case 6: return (int)func_0207E2F0();
    case 7: return (int)func_0207E388();
    }
    return 0;
}

struct ButtonMan *BUTTON_MAN_Create(u8 *rects, void (*cb)(s32, s32, s32), s32 arg, int heap)
{
    struct ButtonMan *r;
    int i = 0;
    unsigned j;

    while (i < 0xff) {
        if (rects[i * 4] == 0xff) {
            break;
        }
        i++;
    }
    r = func_02030734((u16)heap, 0x14, 0, g_020A7FCC, 0x6b);
    if (r != 0) {
        r->rects = rects;
        r->n = i;
        r->cb = cb;
        r->arg = arg;
        r->slots = func_02030734((u16)heap, i * 4, 0, g_020A7FCC, 0x73);
        if (r->slots != 0) {
            for (j = 0; j < i; j++) {
                BUTTON_MAN_ClearSlot(&r->slots[j]);
            }
        } else {
            func_020307B0(r);
            r = 0;
        }
    }
    return r;
}

void BUTTON_MAN_ClearSlot(struct Slot *slot)
{
    slot->kind = 0;
    slot->state = 0;
    slot->count = 0;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/BUTTON_MAN_Delete.c \
 *       --func BUTTON_MAN_Delete --addr 0x02051C6C --cc 1.1p1 --arm
 */
void BUTTON_MAN_Delete(struct ButtonMan *bm)
{
    func_020307B0(bm->slots);
    func_020307B0(bm);
}

/*
 * The per-frame slot refresh: every slot state byte is rewritten to
 * (a == i) or (b == i) by its previous value, then every slot is dispatched
 * through the handler table at 0x020A15E8 and each result other than -1 is
 * forwarded to c->cb(i, v, c->arg).  Returns whether a slot newly took the
 * hover.
 *
 * THE LEVER (wave 18, lane ties_a; it was DIFF 352/352, 19 bytes out for
 * five waves, docs/notes/pkt_02051C88.c.txt): the loop index is
 * `unsigned long`, not u32 (unsigned int).  With u32 the first loop's
 * index and the slots base swap ip / lr over 13 instructions; mwcc colours
 * long and int as different types (the same fact wave 16 found with
 * `long i, j` in 0x02048744).  The unsigned compare against the s32 slot
 * indices is kept, which is what holds the fourth 1 in fp.
 */
s32 BUTTON_MAN_UpdateSlots(struct ButtonMan *c)
{
    s32 a;
    s32 b;
    s32 h, sel;
    s32 ret = 0;
    unsigned long i;

    a = 0;
    h = TOUCHPANEL_GetCont();
    if (h != 0) {
        a = TOUCHPANEL_HitCont(c->rects);
        b = TOUCHPANEL_HitTrg(c->rects);
        sel = TOUCHPANEL_GetTrg();

        for (i = 0; i < c->n; i++) {
            if (c->slots[i].state != 0) {
                c->slots[i].state = (u8)((a == i) ? 1 : 0);
            } else {
                c->slots[i].state = (u8)((b == i) ? 1 : 0);
                if (c->slots[i].state != 0)
                    ret = 1;
            }
        }
    } else {
        sel = 0;
        for (i = 0; i < c->n; i++)
            c->slots[i].state = (u8)a;
    }

    for (i = 0; i < c->n; i++) {
        s32 v = g_020A15E8[c->slots[i].kind](&c->slots[i], h, sel);
        if (v != -1)
            c->cb((s32)i, v, c->arg);
    }

    return ret;
}

/*
 * The conjunction shares one exit; `*(u8 *)(p+1)` is the armed flag the
 * 0x02051E10 sibling also tests.
 * Verified with:
 *   python tools/match.py one --src src/matched/BUTTON_MAN_SlotHandlerIdle.c \
 *       --func BUTTON_MAN_SlotHandlerIdle --addr 0x02051DE8 --cc 1.1p1 --arm
 */
int BUTTON_MAN_SlotHandlerIdle(struct Slot *p, int a, int b)
{
    if (p->state == 0 || b == 0)
        return -1;
    BUTTON_MAN_SlotSetKind(p, 1);
    return 0;
}

/*
 * State-machine step over a small ARM struct: if the flag byte at +1 is set,
 * bump the halfword at +2 while it is below 0xFFFF and report state 2;
 * otherwise it clears the second argument's slot through BUTTON_MAN_SlotSetKind and
 * reports 1 or 3 depending on whether the incoming second argument was zero.
 * The shared `mov r1, #0` before the compare is the constant both arms pass.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BUTTON_MAN_SlotHandlerPressed.c \
 *       --func BUTTON_MAN_SlotHandlerPressed --addr 0x02051E10 --cc 1.1p1 --arm
 */
int BUTTON_MAN_SlotHandlerPressed(struct Slot *p, u32 x)
{
    if (p->state != 0) {
        u16 v = p->count;

        if (v < 0xFFFF)
            p->count = (u16)(v + 1);
        return 2;
    }
    if (x != 0) {
        BUTTON_MAN_SlotSetKind(p, 0);
        return 3;
    }
    BUTTON_MAN_SlotSetKind(p, 0);
    return 1;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/BUTTON_MAN_SlotSetKind.c \
 *       --func BUTTON_MAN_SlotSetKind --addr 0x02051E64 --cc 1.1p1 --arm
 */
void BUTTON_MAN_SlotSetKind(struct Slot *p, int a)
{
    p->kind = (u8)a;
    p->count = 0;
}

/*
 * Scaled 2x2 rotation: convert the angle to a 16-bit turn fraction (mode 1:
 * (ang * 0xFFFF) >> 8; mode 2: degrees, (ang * 0xFFFF) / 360, the umull by
 * 0x6C16C16D with the add-and-halve fix-up), rotate with the sin/cos pair
 * from the shared table at index ang >> 4 (FX_SinIdx/FX_CosIdx shape), then
 * scale by the two vector magnitudes.  EXACT* because the 24-byte leaf that
 * follows at 0x02051F1C (struct copy of three words plus a fourth store) has
 * no label.
 *
 * Wave 9: closed by writing the two conversions as the plain unsigned
 * expressions (the wave-7 note hand-expanded the division and kept a 19-byte
 * register residue) and the table as the extern data symbol; the old
 * "label wall" on MTX_Rot22_/MTX_ScaleApply22 is now carried by the sdk class.
 */
void BUTTON_MAN_RotScaleMtx22(Mtx22 *mtx, u32 ang, long scaleX, long scaleY, u8 mode)
{
    if (mode == 1)
        ang = (u16)((ang * 0xFFFF) >> 8);
    else if (mode == 2)
        ang = (u16)((ang * 0xFFFF) / 360);

    MTX_Rot22_(mtx, FX_SinCosTable_[((s32)ang >> 4) * 2], FX_SinCosTable_[((s32)ang >> 4) * 2 + 1]);
    MTX_ScaleApply22(mtx, mtx, FX_Inv(scaleX), FX_Inv(scaleY));
}

void BUTTON_MAN_InitSphere(Sphere *dst, Vec3 *src, unsigned radius)
{
    dst->c = *src;
    dst->r = radius;
}

/*
 * Segment-versus-sphere test: project the ball's centre onto the segment
 * p0 -> dir (t = FX_Div(dot(d, c - p0), dot(d, d)), d = dir - p0); on the
 * segment compare the distance against b->r + seg->radius, off it compare the
 * distance to the far end and then to p0 against b->r.  Fills a 20-byte
 * { hit, normal, dist } block copied to *out when out is non-null; returns hit.
 * Compiler pin dsi/1.1p1 (a PART 1 math helper of cluster_02051E64).
 *
 * What closed it (wave 9, from the wave-7 note's 72-byte point): the distance
 * is a register local `d` compared at the shared join, and res.d is stored
 * AFTER the limit is loaded (`d = VEC_Mag(..); lim = ..; res.d = d;`).
 * Comparing res.d itself reloads it from the stack at the join.
 */
u32 BUTTON_MAN_SegmentSphereTest(Seg *seg, Sphere *b, HitInfo *out)
{
    HitInfo      res;    /* sp+0x24: res.hit, n, d -- copied out as one block */
    Vec3 sd;     /* sp+0x18 */
    Vec3 bc;     /* sp+0x0c */
    Vec3 tmp;    /* sp+0x00 */
    int t;
    int d;
    int lim;

    res.hit = 0;
    VEC_Subtract(&seg->dir, &seg->p0, &sd);
    VEC_Subtract(&b->c, &seg->p0, &bc);

    t = FX_Div(VEC_DotProduct(&sd, &bc), VEC_DotProduct(&sd, &sd));
    if (t >= 0 && t <= 0x1000) {
        BUTTON_MAN_ScaleVec(&sd, t, &sd);
        VEC_Subtract(&sd, &bc, &tmp);
        d = VEC_Mag(&tmp);
        lim = b->r + seg->radius;
        res.d = d;
    } else {
        VEC_Subtract(&b->c, &seg->dir, &tmp);
        d = VEC_Mag(&tmp);
        lim = b->r;
        res.d = d;
        if (d <= lim) {
            res.hit = 1;
            goto done;
        }
        tmp = bc;
        d = VEC_Mag(&tmp);
        lim = b->r;
        res.d = d;
    }
    if (d <= lim)
        res.hit = 1;
done:
    if (out != 0) {
        VEC_Normalize(&tmp, &res.n);
        *out = res;
    }
    return res.hit;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/BUTTON_MAN_InitSegment.c \
 *       --func BUTTON_MAN_InitSegment --addr 0x0205207C --cc 1.1p1 --arm
 */
void BUTTON_MAN_InitSegment(Seg *p, Vec3 *q, Vec3 *r, u32 v)
{
    p->p0 = *q;
    p->dir = *r;
    p->radius = v;
}

/*
 * VEC_MultAdd-style scale: dst = v * s in 1.19.12 fixed point, component by
 * component, with the SDK's own rounding.  Each component is the inlined body
 * of FX_Mul: a 32x32 signed `smull`, +0x800 for round-to-nearest with the
 * carry folded into the high word by `adc`, then the 64-bit >> 12 spelled as
 * `lsr #12` of the low word `orr`ed with `lsl #20` of the high word.  Writing
 * it as a (s64) multiply and shift is what makes the compiler emit exactly
 * that quartet rather than a call to a runtime helper.
 *
 * All three components are computed before any store, which is why the first
 * two land as one `stm r2,{r4,ip}` and only the third takes its own `str`
 * (the source order is x, y, z and the compiler interleaves the three
 * independent multiplies freely).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BUTTON_MAN_ScaleVec.c \
 *       --func BUTTON_MAN_ScaleVec --addr 0x020520A4 --cc 1.1p1 --arm
 */
void BUTTON_MAN_ScaleVec(const Vec3 *v, int s, Vec3 *dst)
{
    dst->x = (int)((((s64)v->x * s) + 0x800) >> 12);
    dst->y = (int)((((s64)v->y * s) + 0x800) >> 12);
    dst->z = (int)((((s64)v->z * s) + 0x800) >> 12);
}

/*
 * Build a 3x3 rotation matrix from three angles, composed X, then Y, then Z.
 * The destination (r3) is used both as the identity seed and as the running
 * accumulator; a 0x24-byte stack scratch holds the per-axis rotation before
 * each MTX_Concat33 folds it in.
 *
 * Each angle feeds the shared interleaved sin/cos halfword table at
 * 0x020A1B38 (see src/matched/func_0203F684.c): index i = angle >> 4, with
 * sin at tbl[2*i] and cos at tbl[2*i+1].  The `asr #4` is a shift, not a
 * division, and the arguments are signed, which is what makes `ldrsh` with a
 * register offset the load (docs/idioms/ldrsh-register-offset-is-signedness.md).
 *
 * The X rotation is applied straight onto the identity in the destination,
 * with no scratch; the Y and Z rotations each build into the stack scratch and
 * are folded in by MTX_Concat33(dst, &tmp, dst).  Both Concat33 calls take the
 * destination as the LEFT operand: swapping the last one to
 * MTX_Concat33(&tmp, dst, dst) is byte-correct everywhere except the two
 * `mov` bytes at +00A4/+00A8, the only residue the whole function had.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BUTTON_MAN_MakeRotMtxXYZ.c \
 *       --func BUTTON_MAN_MakeRotMtxXYZ --addr 0x020520FC --cc 1.1p1 --arm
 *
 * Addresses are Black-image addresses.
 */
void BUTTON_MAN_MakeRotMtxXYZ(int ax, int ay, int az, Mtx33 *dst)
{
    Mtx33 tmp;
    int i;

    MTX_Identity33_(dst);

    i = ax >> 4;
    MTX_RotX33_(dst, FX_SinCosTable_[2 * i], FX_SinCosTable_[2 * i + 1]);

    i = ay >> 4;
    MTX_RotY33_(&tmp, FX_SinCosTable_[2 * i], FX_SinCosTable_[2 * i + 1]);
    MTX_Concat33(dst, &tmp, dst);

    i = az >> 4;
    MTX_RotZ33_(&tmp, FX_SinCosTable_[2 * i], FX_SinCosTable_[2 * i + 1]);
    MTX_Concat33(dst, &tmp, dst);
}

/*
 * Turn a direction vector into a look-at rotation matrix: pitch about X, yaw
 * about Y, composed into the caller's 3x3.
 *
 * The horizontal run is measured by flattening a copy of the vector: the whole
 * 12-byte vector is copied to a stack scratch with one ldm/stm pair
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md), its y component is zeroed,
 * and VEC_Mag of that gives the run.  Pitch is then FX_Atan2Idx(-v->y, run)
 * and yaw is FX_Atan2Idx(v->x, v->z) - note the argument order is (y, x), the
 * SDK's own, and the pitch numerator carries the `rsb r0, r2, #0` negation.
 *
 * Both angle indices feed the shared interleaved sin/cos halfword table at
 * 0x020A1B38 (see src/matched/func_0203F684.c) at i = angle >> 4, sin at
 * tbl[2*i] and cos at tbl[2*i+1], exactly as in BUTTON_MAN_MakeRotMtxXYZ next door.
 *
 * Declaration order is the whole difference between 184 correct bytes and four
 * wrong ones: the frame lays `flat` at sp+0x48, `mx` at sp+0x24 and `my` at
 * sp+0x00, so the locals must be declared flat, mx, my - the later declaration
 * takes the LOWER stack address
 * (docs/idioms/local-declaration-order-is-stack-order.md).  Declaring my, mx,
 * flat reproduces every instruction and misses only the three `add rN, sp, #k`
 * immediates and the `str r1, [sp, #0x4c]` offset.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BUTTON_MAN_MakeLookAtMtx.c \
 *       --func BUTTON_MAN_MakeLookAtMtx --addr 0x020521BC --cc 1.1p1 --arm
 *
 * Addresses are Black-image addresses.
 */
void BUTTON_MAN_MakeLookAtMtx(const Vec3 *v, Mtx33 *dst)
{
    Vec3         flat;
    Mtx33        mx;
    Mtx33        my;
    int          i;
    int          run;

    flat = *v;
    flat.y = 0;
    run = VEC_Mag(&flat);

    i = FX_Atan2Idx(-v->y, run) >> 4;
    MTX_RotX33_(&mx, FX_SinCosTable_[2 * i], FX_SinCosTable_[2 * i + 1]);

    i = FX_Atan2Idx(v->x, v->z) >> 4;
    MTX_RotY33_(&my, FX_SinCosTable_[2 * i], FX_SinCosTable_[2 * i + 1]);

    MTX_Concat33(&mx, &my, dst);
}

/*
 * Convert a run of n wide characters at `a` into the narrow buffer at `b`,
 * stopping early when the converter raises its flag.  BUTTON_MAN_Ucs2CharToSjis is the
 * per-character encoder next door; it returns 1 when it wrote two bytes and
 * something else when it wrote one, and it reports "stop" by storing 1 into
 * the scratch word it is handed.
 *
 * Four declaration-level levers carry this function, three of them measured
 * by an earlier lane (docs/notes/pkt_02052274.c.txt) and the fourth the one
 * that finally closed it:
 *
 *  1. BOTH cursors are initialised BEFORE the `n == 0` guard.  That is what
 *     gives the original its nine-register push and `sub sp, sp, #4` pad;
 *     guard-first drops to eight callee-saved registers and 92 bytes.
 *  2. The scratch word is reset INSIDE the loop from a separate zero-valued
 *     local `z`, not once outside: `scratch = z;` is the `mov r5, r6` /
 *     `str r5, [sp]` pair.
 *  3. `i++` sits BEFORE the `scratch == 1` early return, not after it.
 *  4. `&scratch` is written INLINE at the call, NOT bound to a `u32 *p`
 *     hoisted above the loop.  With the pointer local, the scratch pointer
 *     and the zero seed trade r4 and r5 -- eight bytes out, and a residue no
 *     permuter mutation moves (164 single mutations tried, none improved,
 *     and ten hand spellings before that).  Written inline, the compiler
 *     materialises the seed first and colours it r5 exactly as the image
 *     does.  This is the same lever that closed func_02052770 in this
 *     cluster: hoisting an address-of into a named local gives that value
 *     the lower colour and displaces the values the image wanted there.
 *
 * Unlike most of this cluster this row is dsi/1.1p1, not the 1.2 front end:
 * under ../1.2/sp2 the same C compiles to 132 bytes.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BUTTON_MAN_ConvertUcs2ToSjis.c \
 *       --func BUTTON_MAN_ConvertUcs2ToSjis --addr 0x02052274 --cc 1.1p1 --arm
 */
void BUTTON_MAN_ConvertUcs2ToSjis(u8 *a, u8 *b, u32 n)
{
    u32 scratch;
    u32 z;
    u32 i;
    u32 j;

    i = 0;
    j = 0;
    if (n == 0)
        return;
    z = i;
    do {
        scratch = z;
        if (BUTTON_MAN_Ucs2CharToSjis((u16 *)(a + i * 2), (char *)(b + j), &scratch) == 1)
            j += 2;
        else
            j += 1;
        i++;
        if (scratch == 1)
            return;
    } while (i < n);
}

/*
 * The per-character encoder behind BUTTON_MAN_ConvertUcs2ToSjis: one UCS-2 code unit to
 * Shift-JIS.  The terminator (STRBUF_GetEosChar's value) writes a NUL and raises
 * *stop; printable ASCII is copied; hiragana, both katakana runs and the
 * full-width A-Z, a-z and 0-9 are offset into their Shift-JIS rows and
 * written high byte first; the long-vowel mark, U+8140 (passed through as the
 * SJIS ideographic space), and the two gender signs are special-cased; any
 * other code writes '?'.  Returns 1 when two bytes were written.
 *
 * Levers: dst is plain (signed) char -- the 0x81 lead byte is `mvn r1,#0x7e`
 * and the trail bytes 0x89/0x8a are derived from it by `add` -- and the
 * result `two` is declared BEFORE the character (declaration order decides
 * the r4/r5 colours).  dsi/1.1p1; 1.2 and 2.0 are 170-220 bytes longer.
 */
int BUTTON_MAN_Ucs2CharToSjis(u16 *src, char *dst, u32 *stop)
{
    int two = 0;
    u16 c = *src;
    u16 v;

    if (c == STRBUF_GetEosChar()) {
        *dst = 0;
        if (stop != 0)
            *stop = 1;
    } else if (c >= 0x20 && c <= 0x7e) {
        *dst = c;
    } else if (c >= 0x3041 && c <= 0x3093) {
        v = c + 0x525E;
        dst[0] = (v & 0xff00) >> 8;
        dst[1] = v;
        two = 1;
    } else if (c >= 0x30A1 && c <= 0x30DF) {
        v = c + 0x529F;
        dst[0] = (v & 0xff00) >> 8;
        dst[1] = v;
        two = 1;
    } else if (c >= 0x30E0 && c <= 0x30F3) {
        v = c + 0x52A0;
        dst[0] = (v & 0xff00) >> 8;
        dst[1] = v;
        two = 1;
    } else if (c >= 0xFF21 && c <= 0xFF3A) {
        v = c - 0x7CC1;
        dst[0] = (v & 0xff00) >> 8;
        dst[1] = v;
        two = 1;
    } else if (c >= 0xFF41 && c <= 0xFF5A) {
        v = c - 0x7CC0;
        dst[0] = (v & 0xff00) >> 8;
        dst[1] = v;
        two = 1;
    } else if (c >= 0xFF10 && c <= 0xFF19) {
        v = c - 0x7CC1;
        dst[0] = (v & 0xff00) >> 8;
        dst[1] = v;
        two = 1;
    } else if (c == 0x30FC) {
        dst[0] = 0x81;
        dst[1] = 0x5B;
        two = 1;
    } else if (c == 0x8140) {
        dst[0] = 0x81;
        dst[1] = 0x40;
        two = 1;
    } else if (c == 0x2642) {
        dst[0] = 0x81;
        dst[1] = 0x89;
        two = 1;
    } else if (c == 0x2640) {
        dst[0] = 0x81;
        dst[1] = 0x8A;
        two = 1;
    } else {
        *dst = '?';
    }
    return two;
}
