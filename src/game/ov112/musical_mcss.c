/*
 * file:     musical_mcss.c
 * unit:     yes
 * function: MUSICAL_MCSS_AllocRenderPool, MUSICAL_MCSS_FreeRenderPool, MUSICAL_MCSS_TickMCAnim, MUSICAL_MCSS_DrawMC, MUSICAL_MCSS_DrawSprite, MUSICAL_MCSS_LoadMC, MUSICAL_MCSS_FreeMC, MUSICAL_MCSS_SetCameraBack, MUSICAL_MCSS_SetCellVramBase, MUSICAL_MCSS_SetAnimVramBase, MUSICAL_MCSS_SetMCAnimPos, MUSICAL_MCSS_SetMCAnimScale, MUSICAL_MCSS_SetMCAnimFrame, MUSICAL_MCSS_EnableDrawOffset, MUSICAL_MCSS_DisableDrawOffset, MUSICAL_MCSS_PauseMCAnim, MUSICAL_MCSS_ResumeMCAnim, MUSICAL_MCSS_SetMCAnim, MUSICAL_MCSS_IsMCAnimHidden, MUSICAL_MCSS_HideMCAnim, MUSICAL_MCSS_ShowMCAnim, MUSICAL_MCSS_CopyField, MUSICAL_MCSS_LoadCellBank, MUSICAL_MCSS_FreeCellBank, MUSICAL_MCSS_InitMCAnim, MUSICAL_MCSS_SetupG3, MUSICAL_MCSS_CalcMatrix, MUSICAL_MCSS_GetMonValue
 * address:  0x021F55F8
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from musical_shot_sys.c, musical_mcss.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   TCB_DeleteTask 0x02030EAC arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   MUSICAL_MCSS_SetRenderCellVramBase 0x021F5438 thumb ov112
 *   FX_SinCosTable_ 0x020A1B38 data a2
 *   BILLBOARD_AddElem 0x0204F428 arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   d_021F83D4 0x021F83D4 data a1
 *   d_02FFFC3C 0x02FFFC3C data a4
 *   NNS_G2dTickMCAnimation 0x020649D4 arm
 *   G3i_LookAt_ 0x0207D7C4 arm
 *   MTX_Inverse43 0x0207B67C arm
 *   MI_Copy36B 0x02082B60 arm
 *   MTX_Copy33To44_ 0x0207ADE8 arm
 *   MTX_Copy43To44_ 0x0207B5C0 arm
 *   MTX_Concat44 0x0207BE14 arm
 *   FX_Div 0x0207C768 arm
 *   G3_MultMtx44 0x0207D8FC arm
 *   G3_RotZ 0x0207D888 arm
 *   MTX_RotZ33_ 0x0207AF38 thumb
 *   MTX_MultVec33 0x0207B51C arm
 *   VEC_Subtract 0x0207CA00 arm
 *   _ffix 0x0209C494 arm
 *   _ll_mul 0x0209C054 arm
 *   d_02148D8C 0x02148D8C data
 *   d_02148D98 0x02148D98 data
 *   d_02148DA4 0x02148DA4 data
 *   d_021F8310 0x021F8310 data ov112
 *   d_021F831C 0x021F831C data ov112
 *   d_021F8304 0x021F8304 data ov112
 *   d_02148B98 0x02148B98 data
 *   d_02148B54 0x02148B54 data
 *   G3i_OrthoW_ 0x0207D760 arm
 *   NNS_G2dGetAnimSequenceByIdx 0x020627D8 arm
 *   NNS_G2dSetAnimSequenceToMCAnimation 0x0206469C arm
 *   NNSi_G2dInitVramHandle 0x02063790 arm
 *   NNSi_G2dInitVramHandleEx 0x020637D4 arm
 *   ARC_UTIL_LoadCellBankFromArchive 0x02049FBC arm
 *   ARC_UTIL_LoadMultiCellBankFromArchive 0x0204A03C arm
 *   ARC_UTIL_LoadAnimBankFromArchive 0x0204A0BC arm
 *   ARC_UTIL_LoadMultiAnimBankFromArchive 0x0204A13C arm
 *   ARC_TOOL_LoadMember 0x02048F60 arm
 *   ARC_UTIL_LoadBgCharDataFromArchive 0x02049DB4 arm
 *   ARC_UTIL_LoadPaletteBlockFromArchive 0x02049F34 arm
 *   MCSS_TOOL_DrawSpindaSpots 0x020172D8 thumb
 *   NNSi_G2dLoadVramResourceSub 0x02063A54 arm
 *   NNSi_G2dLoadVramResourceBySel 0x02063E54 arm
 *   NNS_G2dGetMCWorkAreaSize 0x020648B4 arm
 *   NNS_G2dInitMCAnimation 0x02064754 arm
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 */
#include "musical_shot_sys_shared_types.h"
#include "mus_shot_photo_shared_types.h"
#include "mus_item_draw_shared_types.h"
#include "mus_poke_draw_shared_types.h"

extern void *GFL_USE_AddMainTask(u32,u32,u32);

extern void TCB_DeleteTask(struct Node *n);

extern u32 GFL_HEAP_Free(void *p);

#define REG(a) (*(volatile u32 *)(a))

#define SLOT (*(char ***)(a+4))[i]

struct AnimBank;

struct AnimSequence;

struct Out;

struct Res;

typedef long long      s64;

typedef struct {
    u16 id;
    u16 rot;
    int sx;
    int sy;
    s16 dx;
    s16 dz;
} Pose;

typedef struct {
    u32 spriteX, spriteY, spriteW, spriteH, spriteU, spriteV;
    u32 overlayX, overlayY, overlayW, overlayH, overlayU, overlayV;
    u8 parts[8];
} Ent;

typedef struct {
    u32 f0;
    u32 kind;
    int x;
    int z;
    u32 rotation;
} Part;

typedef struct {
    u16 f0;
    s16 x;
    s16 z;
    u16 h;
} TabEnt;

typedef struct {
    u16 count;
    u16 pad;
    TabEnt *ents;
} Tab;

typedef struct {
    int w;
    int z;
    McssMatrixInput in;
} CB;

typedef struct { int m[12]; } Mtx43;

typedef struct { int m[16]; } Mtx44;

typedef struct { int m[9]; } Mtx33;

typedef struct { u16 id; u16 pad; s16 dx; s16 dz; } PoseSrc;

typedef struct { u32 addr; u32 f04; u32 f08; u32 s; u32 t; u32 fmt; u32 f18; u32 pltt0; } TexInfo;

typedef enum { GX_TEXFMT_NONE = 0, GX_TEXFMT_PLTT4 = 2 } GXTexFmt;

typedef enum { GX_TEXGEN_NONE = 0, GX_TEXGEN_TEXCOORD = 1 } GXTexGen;

typedef enum { GX_TEXSIZE_S8 = 0 } GXTexSizeS;

typedef enum { GX_TEXSIZE_T8 = 0 } GXTexSizeT;

typedef enum { GX_TEXREPEAT_NONE = 0, GX_TEXREPEAT_ST = 3 } GXTexRepeat;

typedef enum { GX_TEXFLIP_NONE = 0, GX_TEXFLIP_ST = 3 } GXTexFlip;

typedef enum { GX_TEXPLTTCOLOR0_USE = 0, GX_TEXPLTTCOLOR0_TRNS = 1 } GXTexPlttColor0;

/* The sprite set reached as obj+0x6C; its Tab table sits at 0x4. */
struct McssSpriteSet { int p0; Tab *tbl; };

typedef struct { u32 a:1,b:1,c:1,rest:29; } Flags;

typedef unsigned long long u64;

/*
 * The render pool (allocated 28 bytes by MUSICAL_MCSS_AllocRenderPool). Holds
 * the child MC anim pointers and the VRAM bases for the cell and anim banks.
 * cellVram/animVram start as 3<<16 and 1<<12 and are rewritten by
 * MUSICAL_MCSS_SetRenderCellVramBase/SetRenderFieldB.
 */
typedef struct McssRenderPool {
    int count;              /* 0x00 number of child slots */
    void **children;        /* 0x04 child MC anim pointers */
    union {
        u32 flags;          /* 0x08 */
        struct {
            u32 cameraBack : 1;  /* bit 0 set by MUSICAL_MCSS_SetCameraBack */
            u32 rest : 31;
        } bits;
    };
    u32 cellVram;           /* 0x0C cell bank VRAM base */
    u32 animVram;           /* 0x10 anim bank VRAM base */
    u32 heap;               /* 0x14 heap id */
    u32 lastTick;           /* 0x18 last tick timestamp */
} McssRenderPool;

/*
 * A child MC animation instance (allocated 292 bytes by MUSICAL_MCSS_LoadMC).
 * 0x00..0x24 are resource handles, 0x28 is the embedded NNS MC animation,
 * 0x8C is the NNS work area and the tail holds per-child state words.
 */
typedef struct McssMcAnim {
    void *cellBank;         /* 0x00 */
    int cellBankArg;        /* 0x04 passed to NNS_G2dInitMCAnimation */
    void *animBank;         /* 0x08 */
    void *cellArg;          /* 0x0C passed to NNS_G2dInitMCAnimation */
    void *multiCellBank;    /* 0x10 */
    void *cellAnimBankData;  /* 0x14 passed to NNS_G2dInitMCAnimation */
    void *multiAnimBank;    /* 0x18 */
    void *animSequenceBank; /* 0x1C */
    void *cellTable;        /* 0x20 */
    void *partTable;         /* 0x24 table+4+56*count, Part records */
    u8 pad_28[0x64];        /* 0x28 embedded NNS MC animation */
    void *workArea;         /* 0x8C NNS MC work area */
    u8 pad_90[0x38];        /* 0x90 */
    int posX;                /* 0xC8 MUSICAL_MCSS_SetMCAnimPos[0] */
    int posY;                /* 0xCC MUSICAL_MCSS_SetMCAnimPos[1] */
    int posZ;                /* 0xD0 MUSICAL_MCSS_SetMCAnimPos[2] */
    int scaleX;              /* 0xD4 MUSICAL_MCSS_SetMCAnimScale[0] */
    int scaleY;              /* 0xD8 MUSICAL_MCSS_SetMCAnimScale[1] */
    int scaleZ;              /* 0xDC MUSICAL_MCSS_SetMCAnimScale[2] */
    u8 pad_E0[0x0C];        /* 0xE0 */
    union {
        u32 flags;          /* 0xEC MC anim state bits */
        struct {
            u32 drawOffset : 1;  /* bit 0 adjusts the drawn position */
            u32 paused : 1;      /* bit 1 cleared by MUSICAL_MCSS_ResumeMCAnim */
            u32 stopped : 1;     /* bit 2 read by GetFieldG, toggled by SetRenderMode */
            u32 rest : 29;
        } bits;
    };
    u32 childIndex;         /* 0xF0 index in the render pool */
    u32 heapTag;            /* 0xF4 heap tag */
    void *ownerSlot;        /* 0xF8 slot passed to MUSICAL_MCSS_LoadMC */
    u16 frame;              /* 0xFC MUSICAL_MCSS_SetMCAnimFrame */
    u8 pad_FE[0x26];        /* 0xFE */
} McssMcAnim;

/* The multi-cell bank loaded by MUSICAL_MCSS_LoadCellBank: a count at 0x00 and
   56-byte cell entries at 0x04. */
typedef struct McssMultiCellBank {
    u32 count;              /* 0x00 */
} McssMultiCellBank;

/* The resource passed to MCSS_TOOL_DrawSpindaSpots (job[0]); a pointer at 0x14. */
typedef struct McssSpindaRes {
    u8 pad_0[0x14];         /* 0x00 */
    void *spots;            /* 0x14 */
} McssSpindaRes;

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern void *GFL_HEAP_Alloc(u32, u32, int, const char *, u16);

extern void NNS_G2dTickMCAnimation(char *, int);

extern void G3i_LookAt_(const struct Vec3 *a, const struct Vec3 *b, const struct Vec3 *c, int d, void *e);

extern void MTX_Inverse43(const Mtx43 *a, Mtx43 *m);

extern void MI_Copy36B(Mtx43 *a, Mtx33 *b);

extern void MTX_Copy33To44_(Mtx33 *a, Mtx44 *b);

extern void MTX_Copy43To44_(const Mtx43 *src, Mtx44 *dst);

extern void MTX_Concat44(const Mtx44 *a, const Mtx44 *b, Mtx44 *ab);

extern u32 FX_Div(u32 a, u32 b);

extern void G3_MultMtx44(Mtx44 *m);

extern void G3_RotZ(int s, int c);

extern void MTX_RotZ33_(Mtx33 *m, int s, int c);

extern void MTX_MultVec33(void *v, Mtx33 *m, void *out);

extern void VEC_Subtract(void *a, void *b, void *c);

extern void G3i_OrthoW_(int a, int b, int c, int d, int e, int f, int g, int h, int i);

extern struct AnimSequence *NNS_G2dGetAnimSequenceByIdx(struct AnimBank *bank, u32 idx);

extern void NNS_G2dSetAnimSequenceToMCAnimation(void *,void *);

extern void NNSi_G2dInitVramHandle(u32 *);

extern void NNSi_G2dInitVramHandleEx(u32 *);

extern void *ARC_UTIL_LoadCellBankFromArchive(u32 archiveID, u32 memberIdx, u32 heapID, u32 unpackedOut, u16 flags);

extern void *ARC_UTIL_LoadMultiCellBankFromArchive(u32,u32,u32,u32,u16);

extern void *ARC_UTIL_LoadAnimBankFromArchive(u32,u32,u32,u32,u16);

extern void *ARC_UTIL_LoadMultiAnimBankFromArchive(u32,u32,u32,u32,u16);

extern void *ARC_TOOL_LoadMember(u32 archive_id, u32 member, u32 heap);

extern void *ARC_UTIL_LoadBgCharDataFromArchive(u32 archiveID, u32 memberIdx, u32 heapID, u32 unpackedOut, u16 flags);

extern void *ARC_UTIL_LoadPaletteBlockFromArchive(u32 archiveID, u32 memberIdx, u32 unpackedOut, u32 flags);

extern void MCSS_TOOL_DrawSpindaSpots(u8 *,u32);

extern void NNSi_G2dLoadVramResourceSub(struct Res *r, u32 dst, int mode, struct Out *out);

extern void NNSi_G2dLoadVramResourceBySel(void *,void *,int,void *);

extern int NNS_G2dGetMCWorkAreaSize(u32,u32);

extern void NNS_G2dInitMCAnimation(char *,char *,void *,int,void *,int);

extern u32 POKE_TOOL_GetPartyValue(void *,u32,u32);

void *MUSICAL_MCSS_AllocRenderPool(int count, u32 heap);

void MUSICAL_MCSS_FreeRenderPool(char *p);

void MUSICAL_MCSS_TickMCAnim(char *p);

void MUSICAL_MCSS_DrawMC(int *p, void (*arg)(unsigned, McssMatrixInput *, Big *));

void MUSICAL_MCSS_DrawSprite(char *p, int offsetX, int offsetY, int width, int height, int texU, int texV, Pose *s, u16 *pa, int entIndex, int flag, int *pz, u8 mode);

char *MUSICAL_MCSS_LoadMC(char *a,u32 b,u32 c,u32 d,u32 e,u32 f,u32 g);

void MUSICAL_MCSS_FreeMC(char *a, char *p);

void MUSICAL_MCSS_SetCameraBack(void *p);

void MUSICAL_MCSS_SetCellVramBase(char *p,int b);

void MUSICAL_MCSS_SetAnimVramBase(u8 *p, int a);

void MUSICAL_MCSS_SetMCAnimPos(char *p, int *q);

void MUSICAL_MCSS_SetMCAnimScale(char *p, int *q);

void MUSICAL_MCSS_SetMCAnimFrame(char *p, unsigned short v);

void MUSICAL_MCSS_EnableDrawOffset(u8 *p);

void MUSICAL_MCSS_DisableDrawOffset(u8 *p);

void MUSICAL_MCSS_PauseMCAnim(u8 *p);

void MUSICAL_MCSS_ResumeMCAnim(char *p);

void MUSICAL_MCSS_SetMCAnim(char *p,u32 n);

u32 MUSICAL_MCSS_IsMCAnimHidden(u8 *p);

void MUSICAL_MCSS_HideMCAnim(char *p);

void MUSICAL_MCSS_ShowMCAnim(char *p);

void MUSICAL_MCSS_CopyField(Object *a,Object *b);

void MUSICAL_MCSS_LoadCellBank(u8 *a,int index,u32 *res,u32 mode);

void MUSICAL_MCSS_FreeCellBank(void *a, void **p);

void MUSICAL_MCSS_InitMCAnim(char *p, int kind);

void MUSICAL_MCSS_SetupG3(void);

void MUSICAL_MCSS_CalcMatrix(const int *p, const int *m, u32 *out, u32 *w);

int MUSICAL_MCSS_GetMonValue(void *p);

extern s16 FX_SinCosTable_[];

extern const char d_021F83D4[];

extern u32 d_02FFFC3C;

extern const struct Vec3 d_02148D8C;

extern const struct Vec3 d_02148D98;

extern const struct Vec3 d_02148DA4;

extern const struct Vec3 d_021F8310;

extern const struct Vec3 d_021F831C;

extern const struct Vec3 d_021F8304;

extern const Mtx43 d_02148B98;

extern const Mtx44 d_02148B54;

void *MUSICAL_MCSS_AllocRenderPool(int count, u32 heap)
{
    char *p;
    p = GFL_HEAP_Alloc(heap, 28, 1, d_021F83D4, 132);
    ((McssRenderPool *)p)->count = count;
    ((McssRenderPool *)p)->heap = heap;
    ((McssRenderPool *)p)->children = GFL_HEAP_Alloc(heap, count * 4, 1, d_021F83D4, 137);
    ((McssRenderPool *)p)->lastTick = d_02FFFC3C;
    ((McssRenderPool *)p)->cellVram = 3 << 16;
    ((McssRenderPool *)p)->animVram = 1 << 12;
    return p;
}

void MUSICAL_MCSS_FreeRenderPool(char *renderPool) { int i; char *q; for(i=0;i<((McssRenderPool *)renderPool)->count;i++) { q=(*(char ***)(renderPool+4))[i]; if(q)MUSICAL_MCSS_FreeMC(renderPool,q); } GFL_HEAP_Free(((McssRenderPool *)renderPool)->children); GFL_HEAP_Free(renderPool); }

void MUSICAL_MCSS_TickMCAnim(char *renderPool)
{
    int i;
    u32 now;
    int delta;
    char *child;
    i = 0;
    now = d_02FFFC3C;
    delta = now - ((McssRenderPool *)renderPool)->lastTick;
    for (; i < ((McssRenderPool *)renderPool)->count; i++) {
        child = (*(char ***)(renderPool + 4))[i];
        if (child && !((McssMcAnim *)child)->bits.paused)
            NNS_G2dTickMCAnimation(child + 40, delta << 12);
    }
    ((McssRenderPool *)renderPool)->lastTick = now;
}

static inline int FxMul(s64 a, s64 b)
{
    return (int)((a * b + 0x800) >> 12);
}

static inline int RoundF(int v)
{
    return (int)(v > 0 ? (float)(v << 12) + 0.5f : (float)(v << 12) - 0.5f);
}

static inline void LoadPose(Pose *r, char *src, int one)
{
    switch ((u16)*(u32 *)(*(char **)(src + 0x1c) + 4)) {
    case 0: {
        const PoseSrc *s = **(PoseSrc ***)src;
        r->id = s->id;
        r->rot = 0;
        r->sx = one;
        r->sy = one;
        r->dx = 0;
        r->dz = 0;
        break;
    }
    case 1:
        *r = ***(Pose ***)src;
        break;
    case 2: {
        const PoseSrc *s = **(PoseSrc ***)src;
        r->id = s->id;
        r->rot = 0;
        r->sx = one;
        r->sy = one;
        r->dx = s->dx;
        r->dz = s->dz;
        break;
    }
    }
}

static inline void G3_TexImageParam(GXTexFmt texFmt, GXTexGen texGen, GXTexSizeS s, GXTexSizeT t, GXTexRepeat repeat, GXTexFlip flip, GXTexPlttColor0 pltt0, u32 addr)
{
    REG(0x040004A8) = (u32)((addr >> 3) | (texFmt << 26) | (texGen << 30) | (s << 20) |
                                  (t << 23) | (repeat << 16) | (flip << 18) | (pltt0 << 29));
}

static inline void VEC_Set(struct Vec3 *a, int x, int y, int z)
{
    a->x = x;
    a->y = y;
    a->z = z;
}

static inline void G3_Translate(int x, int y, int z)
{
    REG(0x04000470) = (u32)x;
    REG(0x04000470) = (u32)y;
    REG(0x04000470) = (u32)z;
}

static inline void G3_Scale(int x, int y, int z)
{
    REG(0x0400046C) = (u32)x;
    REG(0x0400046C) = (u32)y;
    REG(0x0400046C) = (u32)z;
}

/*
 * note (2026-10-04, wave D3 lane 03): first complete structural draft, not tuned.
 *   Listing extent 021F56BC..021F5EDC (2080 bytes), frame 0x254, mid pool at 021F5A24
 *   (0x04000444, 02148D8C/98/A4, 021F8310/1C/04, 02148B98, 0xFFFFF000, 0xFFFA0000,
 *   02148B54, 0x04000470, 020A1B38 sin/cos table, 0x0400046C) and tail pool 021F5ED0.
 *   Shape: G3 setup (push, mode 0, store 0, mode 3, identity, mode 2); camera pick by
 *   p->f8 bit 0; outer loop i < p[0] over p[1][i] objects, skip null or (fEC >> 2) & 1;
 *   per object a 16-byte pose rec at sp+0x244 filled by kind 0/1/2 of
 *   obj+0x28 -> [0x1c] -> f4; translation/rotation/scale writes; MUSICAL_MCSS_SetupG3;
 *   polygon attr word built from bitfields at obj+0x90; inner loop j over parts of
 *   p->f6C->f4[rec.id]; second pose rec at sp+0x234; two MUSICAL_MCSS_DrawSprite calls;
 *   innermost k < 8 over bytes ent[0x30+k] != 0xFF with s64 fixed point math and
 *   an indirect call through p->fF8.
 *   Known hard parts: the compiler derives small constants from register-held I/O
 *   addresses (lsrs r1, r0, #0x13 = 0x80 from 0x04000470; lsrs #0xe = 0x1000 from
 *   0x0400046C; r0 >> 0x12 = 0x100), the float rounding idiom
 *   (v > 0 ? (float)(v << 12) + 0.5f : (float)(v << 12) - 0.5f) then _ffix, and the
 *   many spilled loop-invariant offsets at sp+0x80..0xAC (0x80 constants and
 *   field offsets r5-8, r5-4 with r5 = 0x10C).
 *   The innermost k-loop math is an approximation of the listing (021F5BD4..021F5E8C),
 *   re-derive it from the listing before tuning.
 *   Verdict of this draft: DIFF, compiled 1680 bytes vs 2080, 1623 bytes differ, 52 of 55
 *   relocations resolved. Prologue already differs (push r3 extra, frame 0x198 vs 0x254):
 *   the original keeps more stack locals (spilled invariants at sp+0x80..0xAC, s64 halves
 *   at sp+0x68..0x74, sub-pose rec at sp+0x234, 0x5C-byte source records).
 *   Siblings: MUSICAL_MCSS_DrawSprite (callee, 13 args, see 021F5B6A..021F5BCC for the stack layout).
 *
 * note (2026-10-05, wave D4 lane 06): p->f8 bit 0 is now read through a one-bit bitfield
 *   (McssRenderPool.flags bit 0): the camera pick now gives the original lsls #0x1f; lsrs #0x1f test (1623 -> 1611
 *   bytes differ, compiled 1684 vs 2080).  Still open: the frame (0x254 vs 0x198, push without
 *   r3), the zero local stored at [sp] at entry, the spilled invariants, and the innermost k-loop
 *   which still needs re-deriving from the listing (021F5BD4..021F5E8C).
 *
 * note (2026-10-05, wave D5 lane 06): body rewritten from a fresh reading of the listing
 *   (the code after the mid pool needs `show --addr 0x021F5A5C --size 0x480 --thumb`, the
 *   default show desyncs at 021F5A44).  Fixes: r4 is obj for the whole loop, so the j/k loops
 *   read obj+0x6C/0x68/0x20/0x24/0xF8, MUSICAL_MCSS_DrawSprite takes obj (not p) and &cb.z (sp+0xB8,
 *   zeroed per object), and the indirect call goes through the second parameter `arg`
 *   (`arg((u8)pt->f4, &cb.in.a, obj->fF8)`); a 0x3C-byte callback record at sp+0xB4 (w out
 *   word, z, pos with y negated, x2/y2 scaled by obj->fD4/16 and fD8/16, z, obj+0xD4 vec,
 *   obj+0x100 vec, obj->fFC, ang + (pt->f10 << 11)); on pt->f4 == 5 the result goes to
 *   obj+0x100/0x104/0x108.  k loop: two rotations (part by pose.rot + sub.rot scaled by the
 *   pose*sub scale, then the table entry (x, z at +2/+4) plus pose.dx/dz by pose.rot scaled by
 *   pose.sx/sy), operand order (s64)vec * scale.  Else-branch: a local 4x4 matrix filled with
 *   constants at sp+0x114, MTX_Copy43To44_(&d_02148B98, &m4), MTX_Concat44(&m4, &d_02148B54,
 *   &m4), second MUSICAL_MCSS_CalcMatrix uses that matrix.  Sub-pose kind 0 leaves dz unset.  obj skip
 *   test reads p[1][i] twice and bit 2 of obj->fEC as a bitfield; obj+0x90 and obj+0x68 are
 *   loop-level pointer locals (sp+0x5C, sp+0x50).  Result: compiled 1996 vs 2080 (was 1684),
 *   frame 0x248 vs 0x254, prologue and the obj test now line up modulo slot numbers.
 *   Open: the zero stored at [sp] at entry (push without r3 in the original), the i slot
 *   (0x5C vs 0x58), mid-pool placement (original after the attr word at 021F5A20), LoadPose
 *   register shape (original keeps src = obj+0x28 in r0), the eight spilled 0x800 rounding
 *   words at sp+0x80..0x94/0x9C/0xA0 and the 0x100/0x10C offsets at sp+0x98/0xA4..0xAC.
 * note (2026-10-05, wave D6 lane 01): three fixes from a fresh reading of the head and the pose loader.
 *   (1) G3i_LookAt_ takes a fifth argument (NULL, as in the matched callers): the zero stored at [sp]
 *   at entry is that stack argument, written once before the camera-pick branch. The prologue now
 *   matches to 021F56F8 apart from the frame size. (2) LoadPose is a switch on the u16 kind with a
 *   compare chain (beq 0, cmp 1, cmp 2, b out), and the id is a u16 read (ldrh) through a
 *   {u16 id; u16 pad; s16 dx; s16 dz} source record. (3) obj+0x90, obj+0x68 and obj+0x28 come from
 *   static inline accessors (ObjAttr, ObjSrcs, ObjAnim): the parameter copy gives the original
 *   `adds r0,r4,#0; str [sp,#K]; adds r0,#0x90; str [sp,#K]` double store for srcs and keeps src =
 *   obj+0x28 in r0 for the kind load (`ldr r3,[r0,#0x1c]`). Compiled 2008 vs 2080 (was 1996).
 *   Open: frame 0x24C vs 0x254 (8 bytes of locals missing, every sp offset is 8 low), attr (obj+0x90)
 *   stays in r5 where the original spills it to sp+0x5C, the zero/kind registers in the obj head
 *   (original zero r2, kind r3; ours zero r3, kind r1), and everything after 021F57BC not re-checked.
 * note (2026-10-05, wave D7 lane 01): read only, no new build. The original spills attr (obj+0x90) to
 *   sp+0x5C and reloads it three times for the attr word (021F59EE, 021F59F0, 021F5A00); r5 is a
 *   short-lived temp there (0x10C offset at 021F59A6). So the original has more long-lived values than
 *   ours; the 8 missing frame bytes are likely two more spilled locals. Also: the callback arg is
 *   ov112 MUSICAL_MCSS_SetMatrix (mode = (u8)pt->f4, in = &cb.in.a, p = obj->fF8), see that draft for the
 *   0x38-byte slot layout of obj->fF8.
 * note (2026-10-05, wave D8 lane 01): three local shape fixes from the listing at 021F58C4..021F591E.
 *   (1) The pos and (ox, oy, 0) MTX_TRANS writes are a G3_Translate(x, y, z) static inline: the
 *   original loads all three values before the three stores (ldr r3,[sp,#0x230]; ldr r2; ldr r1;
 *   str; str; str); 0x0400046C writes are G3_Scale(sx, sy, 0x1000). (2) The flag increment is
 *   `flag++` on the u8 local: the original reloads the spilled zero and does adds/lsls/lsrs, where
 *   `flag = (u8)(flag + 1)` folds to movs #1. (3) The rotation ternary has no inner (u16) cast:
 *   `u16 a = (flag & 1) ? 0x10000 - pose.rot : pose.rot;` truncates once after the join, as in the
 *   original. Compiled 2012 vs 2080 (byte count is not comparable, every later offset shifts).
 *   Still open: frame 0x24C vs 0x254. The original spill area is 8 bytes larger (struct locals start
 *   at sp+0xB4 in the original, sp+0xAC in ours), so the original spills two more values; attr
 *   (obj+0x90) is one of them (sp+0x5C, ours keeps it in r5). G3_Translate(pos) still takes r2/r1/r0
 *   for z/y/x and r3 for the register base, the original r3/r2/r1 and r0. The rounding constant
 *   0x800 is derived from the halfword offset 2 held in r6 (`movs r6,#2; ldrsh r1,[r2,r6]` then
 *   `lsls r2,r6,#0xa`), ours does the same from r7. The k-loop past 021F5A5C was not re-checked.
 * note (2026-10-05, wave D9 lane 04): six fixes from a fresh reading of the j/k loops (compiled 2064 vs
 *   2080; on a register-blind instruction diff 94 lines differ, was 210).  (1) obj->f6C has one more
 *   level: the record table is at obj->f6C->f4 (as in matched MUSICAL_MCSS_DrawSprite, McssSpriteSet/Tab/TabEnt), both in
 *   the j-loop test and for the entry reads.  (2) The sub-pose uses the same LoadPose switch: kind 0
 *   also zeroes dz, by cross-jumping into the kind 2 tail (listing 021F5AE6 b 021F5B1A).  The entry
 *   te and the part pt are not locals: j*8 and b*0x14 are spilled CSE values and every read is
 *   written inline.  (3) The 0x1D write goes to 0x0400044C (MTX_STORE), not 0x04000450.  (4) Every
 *   fixed-point product is a FxMul(s64 a, s64 b) static inline: it puts the vector in r0:r1 and the
 *   scale in r2:r3 and spills fx/fz with s/c in r5/r6, as in the original.  psx/psy are s64 locals
 *   assigned before the first product (the original sign-extends both before the first _ll_mul).
 *   (5) obj->fEC bit 0 is a one-bit bitfield.  (6) Declaration order `fx, fz, c, s, X, c2, Z, s2`
 *   gives the original registers in both rotations; the attr word is written right-nested
 *   a7 | (0xF0000 | (a4 | (a3 | (a5 | a0 | 0x40000000)))) to get the original OR order.
 *   Still open: frame 0x250 + push r3 vs 0x254. The original spills attr (obj+0x90) to sp+0x5C and
 *   keeps &pos in r7 across the two MUSICAL_MCSS_CalcMatrix calls; ours keeps attr in r5 and rematerialises
 *   &pos.  Tried without effect: attr declaration position, block scope, a struct type, a PolyAttr
 *   inline, a Persp inline and a `Vec *pp` local for the 660C calls.  A separate `int w` local (not
 *   cb.w) gives the 0x254 frame but puts w at sp+0xB0, not 0xB4, so it is not the answer.  The k-loop
 *   head schedules the fx/fz loads before `ang` (original: ang first); `ent->parts[k]` inline instead
 *   of `b` is worse.  `j = 0` sits after the first scale product in the original; only an unnatural
 *   split of the sy/sx block reproduces it.
 * note (2026-10-05, wave D9r lane 22): 94 -> 0 instruction lines differ; 5 bytes left (two spill slots).
 *   (1) The 0x040004A8 word is the SDK inline G3_TexImageParam with enum parameter types, as in the
 *   matched sibling arm9 MCSS_Draw (same renderer: same matrix calls, Pose switch, TexInfo record
 *   at obj+0x90 with addr/s/t/fmt/pltt0 at 0/0xC/0x10/0x14/0x1C).  With it, attr spills to sp+0x5C and
 *   &pos stays in r7 across the MUSICAL_MCSS_CalcMatrix calls; the frame is 0x254 and the push has no r3.
 *   (2) attr, srcs and a new ctrl (obj+0x28) are plain assignments in the order attr, ctrl, srcs (the
 *   accessor inlines are gone; they made no difference once attr spills).  (3) Declaration order
 *   ent, attr, i, j, srcs, k gives the original slots.  (4) for (j = 0; ...) without the early
 *   j = 0 statement: the 0 is shared with the first FxMul high word, as in the original.  (5) ang is an int
 *   (u16 cast at the assignment).  (6) X = te.x; X += pose.dx; (same for Z) gives the te.x-first load
 *   order.  (7) c2 (the cos of pr) is written inline at both uses: the original spills it as a CSE
 *   temp (lowest slot, reload with no copy).  (8) The obj+0x100 write is VEC_Set(v, x2, y2, 0), which
 *   loads y2 before x2.
 *   Residue: the CSE temps j*8 and c2 have swapped slots (original j*8 sp+0x34, c2 sp+0x30; ours the
 *   reverse).  A diagnostic without the j-loop use of ents[j] gives the original order, so the j*8
 *   temp is created later than c2 in ours.  Tried without effect: s2 inline too, c/s inline (worse),
 *   an idx local, operand order of the c2 products, k-loop locals at function scope, a te local in
 *   the k loop, src passed straight to LoadPose, named c2 in any scope (goes to the named slots).
 * note (2026-10-05, wave D9r lane 53): residue unchanged at 5 bytes (j*8 CSE temp at sp+0x30, cos(pr) temp
 *   at sp+0x34; original reverse).  One clean-up: the `one` local (0x1000 for the sub-pose LoadPose) is
 *   gone; LoadPose(&sub, src, 0x1000) gives the same bytes (the 0x1000 reload from sp+0x64 is the
 *   compiler's own hoisted constant).  Tried without effect on the slot pair (each a real compile): a TabEnt
 *   pointer or a u16 h local for the head read; `int id = j` alias at head or in the k loop; the j loop and the
 *   k loop as if/do-while; pose.rot inline (no pr local; same bytes); s2 load moved above the X/Z reads; X/Z
 *   reads as (ents + j)->x, as a Cell() inline, or as byte offsets (j * 8 + 2) in both head and k loop
 *   (byte offsets in the k loop only stop the j*8 CSE and LICM-hoist a second copy); cos(pr) spelled four
 *   other ways (1 + idx, (T + idx)[1], &T[idx][1], idx << 1) and through a Cos() inline; RotX/RotZ inlines and
 *   an FX_MUL-style macro for the second rotation (worse); a `const s16 *sc` pointer for s2/cos (worse);
 *   k-loop declaration order.  The pair stays swapped in every variant, so its order is probably fixed by the
 *   colouring tie-break, not by source position of the two expressions.
 * note (2026-10-05, wave D9r lane 90): residue unchanged at 5 bytes (same slot pair).  Compared with the
 *   matched twin arm9 MCSS_Draw line by line and tested new forms, each a real compile.  Same 5 bytes:
 *   outer i loop as the twin's `i = 0; if (n > 0) do { } while (++i < n);`; a typed MAnim/Frame chain
 *   (`((Obj *)obj)->anim->frames[pose.id]`) instead of the raw obj+0x6C casts; the node as a 0x5C-byte
 *   struct array (`&(*nodes)[idx]`, as the twin); a frame-cells pointer local at the head; a named int
 *   node index at the head; SDK FX_SinIdx/FX_CosIdx inlines (int idx, fx16 return) for every table
 *   read; the break test as `if (ent->parts[k] == 0xFF) break; b = ent->parts[k];`; the rotated vector
 *   in vx/vz locals before the two FxMul calls.  Worse: the head index through a NodeIdx() inline
 *   (loses the loop-condition entry pointer, 1056 B); the k loop as a static inline (not inlined,
 *   1832 B); `k < 8 && parts[k] != 0xFF` in the for condition (744 B); X/Z as one expression each
 *   (64 B).  Diagnostics (not candidates): a third use of the cos(pr) temp, X/Z reads moved to the top
 *   of the k loop, and no Z read all keep ours order (j*8 below cos(pr), b*0x14 lowest), so the order
 *   does not follow use count or program position of the k-loop reads.
 * note (2026-10-05, wave D9r lane 107): residue unchanged at 5 bytes (j*8 temp sp+0x30, cos(pr) temp sp+0x34;
 *   original reverse).  New tries, each a real compile: FxMul with int (fx32) parameters as in the twin's
 *   FX_MUL, with s64 or int psx/psy (89 B, worse); cos(pr) as an int-typed value ((int) cast at both uses,
 *   or an int-returning CosI() inline; same 5 B); 5EDC prototype and Ent fields as int, as in the matched
 *   MUSICAL_MCSS_DrawSprite, and 660C with its matched const int / u32 parameters (same 5 B); `int b` for the part
 *   byte (same 5 B); s16 (fx16) locals for s2, for c/s, or for all three (508 to 728 B, worse); named c2 in
 *   three placements (430+ B, adds a copy); mixed spellings for the X/Z reads (index for one, byte offset
 *   for the other: 870 B; `(ents + j)->x` for X only: same 5 B).  Diagnostics: `int pr` swaps the pr and
 *   flag slots (0x38/0x3C), so local width moves slot order; an extra k-loop use of ents[j] does not move
 *   j*8 off sp+0x30.  The slot order of the two CSE temps does not follow use count or type.
 * note (2026-10-05, wave D9r lane 124): residue unchanged at 5 bytes (j*8 temp sp+0x30, cos(pr) temp
 *   sp+0x34; original reverse).  Tested the inline-return-temp idiom (ov125 021D6B40) on every helper in
 *   the j/k loops, each a real compile: LoadPose hand-expanded for sub, and for both pose and sub (output
 *   identical to the draft, byte for byte); RoundF hand-expanded as a plain ternary and with a block-local
 *   `int v` (identical); the two second-rotation FxMul calls hand-expanded with a block-local s64 operand
 *   (identical) or as one expression (2084 B, worse); a Cell() inline returning &ents[j] at all three
 *   uses, head included (1056 B).  So the inlines are transparent here; no inline temp sets this pair.
 *   Also tried: the head .h read as a byte offset (j*8+6: 1040 B) or as (ents + j) cast to char * (same
 *   5 B); an index local for s2/cos(pr) as u32, int (same 5 B) or u16 (483 B).  Diagnostics: `u32 j`
 *   and a branch between the two cos(pr) uses keep ours order.
 * note (2026-10-05, wave D9r lane 135): residue unchanged at 5 bytes (j*8 temp sp+0x30, cos(pr) temp
 *   sp+0x34; original reverse).  New head-of-j-loop forms, each a real compile, all give the same 5 B
 *   (the front end normalises them to one tree): a `Tab *tab` assigned in the loop condition
 *   (`j < (tab = &T[pose.id])->count`) and read at the head as tab->ents[j].h, also through a TabEnt
 *   pointer local taken from tab (te = tab->ents; te[j].h, or te = &tab->ents[j]); entries as a u16/s16
 *   halfword array at all three uses (`((u16 *)ents)[j * 4 + 3]`, x/z at j * 4 + 1 / + 2); getters that
 *   take the already-computed ents (or &T[pose.id]) plus j: EntH(e, j), EntAt(e, j)->h, EntIdx(e, j),
 *   TabEntAt(t, j)->h (head only: same 5 B; also at the X/Z reads: 6 B, add operand swap); src at
 *   function scope.  Worse: a struct copy `TabEnt e = ents[j]` at the head (1100 B); h as an 8-bit
 *   bitfield pair (u16, s16 or u32 fields: 998 to 1056 B, lsls/lsrs instead of and/asr); the u16 head
 *   read only (X/Z left as fields: 1040 B); tab also used at the X/Z reads (1136 B, tab held in a register).
 *   Off the head, also same 5 B: a non-const `s16` table (as in the twin), the table named
 *   FX_SinCosTable_, s2 and the second rotation in a nested block.  Diagnostics: without cos(pr) as a CSE
 *   (second use replaced) j*8 stays at sp+0x30, so it is the cos(pr) temp that lands above j*8; without
 *   the head use j*8 becomes a LICM temp at sp+0x3C (above the narrow pr/flag locals) and cos(pr) drops
 *   to sp+0x30.  No head spelling reached changes the temp order.
 * note (2026-10-05, wave D9r lane 152): residue unchanged at 5 bytes; the file body is unchanged.
 *   New tries, each a real compile.  The slot order of the late group (flag, pr, j*8, cos(pr), b*0x14)
 *   moves with the declared TYPE of j, not with any spelling of the expressions:
 *   - `long j` (or s32/unsigned long): j*8 goes to sp+0x38, above pr (pr 0x34, cos 0x30 correct, b*0x14
 *     0x2c correct): 6 B.  `unsigned int j` keeps ours order (7 B).  The type of i, of the k-loop
 *     locals (long/fx32), of b (int), of u32 (unsigned long), and fx32 struct fields do not move it.
 *   - `long j` plus `int pr` (or long pr): j*8 0x34 and cos 0x30 are correct, but pr and flag swap
 *     (pr 0x3C, flag 0x38): 9 B.  So the original needs u16 pr with j*8 between pr and cos; no type
 *     pair of (j, pr) gives that.
 *   - reusing the first-rotation `c` (or `s` and `c`) for the second rotation: j*8 goes to 0x34, but
 *     the second web of c gets the lowest slot (0x2C, below b*0x14) and the rz product gains a copy
 *     (431 B).  A named s16 c2 also adds the copy and stays at 0x34.
 *   - pose.rot spelled in place of pr in ang, s2, or one/both cos reads: j*8 goes to 0x34, but pr
 *     takes a late slot (0x30) and cos moves to 0x38 (5 to 10 B; split spellings also break the
 *     shared T+idx address).
 *   - same 5 B: cos and sin as a {sin, cos} struct table (cast or extern), five mixed spellings of one
 *     cos read (1 + idx, (T + idx)[1], *(&T[i] + 1), (idx << 1) + 1, (&T[i])[1]), FX_SinIdx/FX_CosIdx
 *     with int or long idx (with long j), pr declared with an initialiser in a block, pr at function
 *     scope reused for the G3 rotation angles (with long j: still 6 B), b assigned after its
 *     declaration, an unreferenced label between the products, byte-offset j * sizeof(TabEnt) reads.
 *   Worse: RotA/RotB inlines taking cos as a parameter (432 B, rz product copy); a `const s16 *sc`
 *   pointer (432 B); a 5EDC prototype with a long j parameter (j itself moves to the late group).
 *   Reading of the pattern: the late slots look like spill temporaries in the order the allocator
 *   spills them (round by round, then by definition order).  cos(pr) is in the first round in every
 *   variant; the original needs it in a later round than pr.  No natural source change found that
 *   does this without moving another slot.
 * note (2026-10-05, wave D9r lane 198): residue unchanged at 5 bytes; the file body is unchanged.  Lane 152's
 *   suggestion (long j or s32 plus a way to push pr back above j*8 with pr still u16) tested as a table; every row a
 *   real compile.  Slots low to high (b*0x14 is 0x2C in every row):
 *   original                     cos 30, j*8 34, pr 38, flag 3C
 *   base (int j)                 j*8 30, cos 34, pr 38, flag 3C: 5 B
 *   long j / unsigned long j     cos 30, pr 34, j*8 38, flag 3C: 6 B (8 B for unsigned long: extra loop-test byte)
 *   unsigned int / size_t j      as base, 7 B (loop-test byte differs)
 *   named `int jo = j * 8;` (head, X and Z read through ((TabEnt *)((char *)ents + jo))), int or u32, any
 *   declaration order of {jo, pr, flag} at function scope (6 orders), jo at function or j-body scope:
 *                                cos 30, pr 34, jo 38, flag 3C: 7 B (the X/Z add operand order also changes)
 *   named jo plus a redundant second `jo = j * 8;` BEFORE the last use (idiom a-redundant-second-assignment...;
 *   after the loadpose, before the 5EDC calls, before the k loop, first or after the break test in the k body):
 *                                jo 30, cos 34, pr 38, flag 3C: 6 B.  A second assignment after the last use
 *                                (after cb.in.a or at the end of the k body) is dead and gives the single-assign row.
 *   jo declared long or as a char * / void *: long moves it to a high named slot (22 B); a pointer is the base row.
 *   jo split into jh (head) and jk (k loop): as the double-assign row.
 *   So j*8 only ever lands at one of two places: below cos (temp) or above pr (named, or long-typed); the original
 *   needs the slot between them.  Declaration order and scope of jo, pr and flag never moved any slot.
 *   pr changes with long j: `int`, `long`, `u32` or `unsigned long` pr give j*8 34 and cos 30 (correct) but pr 3C and
 *   flag 38 (5 B differ); flag as u16, s16 (same 5 B), int, u32, long with `flag = (flag + 1) & 0xFF` (1429 to 1462 B);
 *   pr s16 or u8 (740 B); pr at function scope as int (14 to 43 B, pr 0x48).  pr read earlier (at the top of the j
 *   body, 1034 B; before the k loop, 309 B; first statement of the k body or declared with an initialiser before
 *   the break test, 19 B: the load schedule changes), later (just before the s2 read: 1780 B).  pr declared at j
 *   body scope: same as base (5 B) or, with long j, 6 B.
 *   The angle through u16 helpers SinA(u16)/CosA(u16): with pr passed or with pose.rot passed directly, no pr local
 *   used at the reads: same slots as base (5 B) or as long j (6 B).  j as an enum type: 1091 B; signed char j: 91 B.
 *   Diagnostic only: a third pr use does not give a comparable build (frame changes).
 *   Reading: the slot order is a ranking, not a source position: with j*8 a CSE temp it ranks below cos(pr), with
 *   j*8 named (or long) it ranks above pr, and the original has it between.  No natural form found for the middle rank.
 * note (2026-10-05, wave D9r lane S8): residue unchanged at 5 bytes; the file body is unchanged (the earlier
 *   lane left only notes, body identical to HEAD).  Slot facts measured with a Thumb decode of the compiled
 *   bytes (7 real compiles, none repeating a lane 152 or 198 row):
 *   - the compound byte-offset idiom of the sibling 021F546C (`u32 jo = j; jo *= 8;`, head, X and Z read
 *     through (TabEnt *)((char *)ents + jo)): b 2C, cos 30, pr 34, jo 38, flag 3C (7 B).  j*8 is not a named
 *     byte offset: any named local lands above pr, the original has j*8 below pr.
 *   - named locals order by first assignment in the code, not by declaration: with `u16 pr;` declared in the
 *     j body BEFORE jo, pr still lands below jo (pr 34, jo 38).  So declaration order cannot place jo.
 *   - the spilled CSE temps (b*0x14, cos, j*8) always sit below every named local.  The original j*8 (0x34)
 *     is in the temp band, above cos, which is the only pair left swapped.
 *   - statement order tests (second rotation before the first; fz read after the Z read) change the frame
 *     and schedule (836 and 842 B), so they cannot show the pair order.
 *   mwcc source (inspiredrobot/mwcc): Coloring_SelectColors flags a web Spilled in select-stack order and
 *   SpillCode_00531800 (slot assignment, not reconstructed there) runs per retry round; Coloring_SimplifyGraph
 *   picks potential spills by min spill_cost / degree.  Our listing and the original are instruction identical,
 *   so cost and degree of j*8 and cos are equal in both builds; only the web numbering or tie order differs.
 *   Lane 22's diagnostic (no head use of ents[j] gives the original order) fits a numbering reading: the head
 *   use makes j*8 a temp that is created before cos in ours.  No source form that creates cos(pr) before j*8
 *   without moving code was found (cos has no occurrence before the k body in the original listing).
 * note (2026-10-05, final push G2L5, rounds 2 and 3): 16 more real compiles, all DIFF, none better than 5 B.  `u16 j`, `s16 j`
 *   (94/93 B); rx and rz as one expression each with both products (836 B); `long j` with `int pr` at function scope
 *   (18 B), with pr assigned at object level (1794 B), with `u16`/`s16`/`unsigned short` flag (11 B), plus opt_lifetimes
 *   or scheduling off (9 B); head chain through a named `int id = pose.id` (723 B); second rotation rz before rx (652 B);
 *   `Z * cos` operand order (5 B, same).  Also off: opt_unroll_loops, opt_vectorize_loops, opt_findoffsets (5 B).  mwcc
 *   SpillCode.c: spill cost is use count times block weight; earlier lanes' extra-use diagnostics did not move the pair, so
 *   slot order is not cost-driven.  Twin arm9 MCSS_Draw re-read: no k-body pr rotation, nothing to borrow.
 * note (pass 2 2026-10-06 P2L09): residue unchanged at 5 bytes; the body is unchanged.  40 real compiles.
 *   Slots low to high of the triple j*8 / cos(pr) / pr (flag 0x3C in all rows unless said):
 *   - `#pragma opt_strength_reduction off`: cos 30, pr 34, j*8 38 (6 B), the same as `long j`.  So strength
 *     reduction is what ranks j*8 below cos.  Under SR off: pose.rot for pr everywhere, pr at j-body or function
 *     scope (3 positions), u16 pr with an int/u32 `pi = pr >> 4` index, `(pr = pose.rot) + sub.rot`: SR-off row
 *     (6 to 7 B); int or u32 pr: cos 30, j*8 34 (correct), flag 38, pr 3C (9 to 10 B); pose.rot in ang only:
 *     pr 30, cos 34, j*8 38 (8 B).  SR off plus opt_loop_invariants off: 1501 B; plus opt_lifetimes off: SR-off row.
 *   - SR on, pose.rot spelled in ang only (pr kept for s2 and both cos reads): pr 30, j*8 34 (correct), cos 38,
 *     5 B.  In that form, same 5 B and same slots: ang before `pr = pose.rot`, pr declared at function scope,
 *     j-body scope or first in the k body, pr assigned right before s2, SinA/CosA(u16) inlines on pr.  Back to
 *     the base order (5 B): int pr, an int `pi = pr >> 4` or `pi = pose.rot >> 4` index, SinA/CosA(pose.rot).
 *     u32 pr 6 B; plus long j 8 B.  pose.rot in rz cos only 653 B, rx cos only 505 B, both cos or s2 only 10 B.
 *   - j*8 written as `(char *)ents + (j << 3)` at all three uses: base slots, 6 B (add operand byte); at the head
 *     only or the k loop only: 1040 B (CSE lost).  opt_loop_invariants plus opt_lifetimes off: 5 B (base).
 *   Four orders of the triple are reachable (j8<cos<pr, cos<pr<j8, pr<j8<cos, cos<j8 with pr above flag); the
 *   original cos<j8<pr<flag was not produced.
 * note (pass 3 2026-10-06 P3L04): residue unchanged at 5 bytes; the body is unchanged.  40 real compiles.
 *   New regime: the second-rotation cos stored in the first-rotation `c` with `rz += FxMul(X * s2 + Z * c, psy)`
 *   (operand order Z * c removes lane 152's extra copy): 7 B, j*8 0x34 and pr 0x38 now correct, but the c web
 *   takes 0x2C and b*0x14 moves to 0x30 (original b*0x14 0x2C, cos 0x30).  In that regime, same 7 B: s also
 *   reused for s2, s or fx reused for cos, int/u32 b, the assignment inside the rx argument, opt_loop_invariants
 *   off.  Worse: `c * X` (18 B), plus pose.rot in ang (13 B), plus SR off (13 B), plus opt_lifetimes off (546 B),
 *   c at function scope (684 B), c and s2 moved above the X/Z reads (851 B), CosA/SinA(u16) inlines (14 B).
 *   Same 5 B base slots: s reused for s2 only; an int idx index local for s2 only; RotX/RotZ inlines reading the
 *   table; a named TabEnt *e for the k-loop reads; rx/rz as a local struct; c assigned from one read with the other
 *   read inline (either order); opt_strength_reduction_strict on.  Worse: idx local in some cos reads only
 *   (508 B / 9 B), a const s16 *sc pair pointer for one cos read (502/508 B), named c2 with Z * c2 at three
 *   declaration places (14/23/64 B), separate x1/z1/x2/z2 running locals (898 B); SR off plus an `int id = j`
 *   alias at the head or in the k loop gives the SR-off row (6 B).  Reading: a reused variable's second web ranks
 *   below every optimizer temp, a first named web ranks in the named band, so cos in the original is a temp made
 *   after the SR-created j*8 web and before b*0x14; no source form found that delays the cos CSE that way.
 * note (pass 4 2026-10-06 P4L03): residue unchanged at 5 bytes; the body is unchanged.  40 real compiles.
 *   Same 5 B: RotA/RotB inlines with cos as a parameter and `Z * c`; a `const s16 *sc` pair pointer with
 *   `Z * sc[1]` (with or without s2); `s16 sc[2]` with `Z * sc[1]`; rx/rz as `int r[2]` (const or non-const
 *   table); `register` on pr or j.  Long-j row (6 B, flag 3C, j*8 38, pr 34, cos 30): u16 pr reused at
 *   function scope for either G3 angle; s2 read above the X/Z reads (77 B, same slots); the head .h read as
 *   a byte offset `j * 8 + 6` or `(j << 3) + 6` (merged under long j); `u16 pr = 0;` initialisers.  Long j
 *   plus int pr with `pr >>= 4`: 9 B (pr 3C, flag 38); with u16 pr: 10 B (pr 3C, lsrs).  Long j plus int pr
 *   reused for the obj+0xFC G3 angle: 18 B (pr 0x48).  `int sc[2]` for s2/cos: 14 B (the array-to-register
 *   web takes 0x3C above flag).  Worse: `pr / 16` (15 B all reads, 656 B rz only), a {s, c} struct copied
 *   from the table (576 B), one cos read as a char* byte offset (495/504 B: the table load is never merged
 *   after CSE0), opt_propagation off (1898 B), opt_common_subs off (1438 B).  Reading (research in the lane
 *   folder): the global table load is merged only by the first CSE, so cos is always numbered before the SR
 *   j*8 web; without SR on j, j*8 is numbered at the j-loop head, before the k-top pr.  The original order
 *   (flag, pr, j*8, cos) needs one of the two moved, and no source form found does that.
 * note (pass 5 2026-10-06 P5L02): residue unchanged at 5 bytes; the body is unchanged.  41 real compiles.
 *   New forms, none better: `int b` reused as the Part byte offset (`b *= sizeof(Part)`) with the cos stored in the
 *   first-rotation c (or s, fx): instructions identical, 7 B, j*8 and pr right but b*0x14 30 above the c web 2C (both
 *   are second webs and rank by def position, so b*0x14 at the k top always ranks above the cos); declaration order
 *   of b and c in that form: same or 593/684 B.  A local struct {int s, c} for s2/cos: 14 B (promoted, cos 3C above
 *   flag).  Function-scope `s16 sn, cs` shared with the object-level G3 rotation, cs reused for the k-loop cos: 5 B
 *   base slots (narrow reuse is transparent); as int: 23 B (decl slot 0x48); a j-body `int n` node index reused for
 *   the cos: 23 B; the function-scope int ox reused: 821 B.  Same 5 B: a `u16 pr2 = pr` (or int) copy for the rz
 *   cos read (value numbering sees through it), a k-loop `const s16 *tab` for all table reads, pose.rot spelled
 *   everywhere, a named s16 c2, the break as a goto, pr first assigned at the object-level G3 angle.  Named jo
 *   (head or k loop): 7 B or 1040 B.  Strength reduction off or long j in the reuse forms: 13 B (J P B C order).
 *   Reading (research in scratchpad wD9r/p5_P5L02): every measured order fits one birth-phase ranking (decl webs and
 *   promoted aggregates, then code-order webs flag/pr/cos with the head j*8 first when not strength reduced, then
 *   strength-reduced j*8, then load-deletion temps, then b*0x14, then second webs of reused ints).  The original
 *   needs j*8 between pr and cos, which no tested source form produces.
 * note (pass 6 2026-10-06 P6L10): residue unchanged at 5 bytes; the body is unchanged.  4 real compiles plus about 25
 *   traced compiler runs (tools in scratchpad wD9r/p6_P6L10).  FX_SinIdx/FX_CosIdx inlines (`T[((idx >> 4) << 1)]`, + 1):
 *   5 B, the parameter is propagated before the first CSE and cos stays a first-run temp.  The b*0x14 split at the first
 *   CSE is caused by any branch between the uses, but only for the b chain (index under a memory-loaded base); the
 *   const-table pr/cos chain crosses the same branches at the first CSE.  Single-use locals for the rz read (pointer,
 *   cos value, second pose.rot read) are propagated back before the first CSE or leave the load read twice.  `long j`
 *   plus `int pr`: 9 B with j*8, cos and b*0x14 correct and only pr/flag swapped; the trace shows that the flag slot
 *   is the CAST(flag) temp and a named int pr outranks every temp, so the original pr must be a temp created between
 *   the flag temp and the k-preheader j*8 temp, where no pr occurrence exists.  `#pragma opt_loop_invariants off`
 *   with s2 above the X/Z reads: 77 B (the head j*8 stops being a CSE candidate).
 * note (pass 6 2026-10-06 P6L02, round 2): residue unchanged at 5 bytes; the body is unchanged.  Traced why j*8 and
 *   b*0x14 are second-run CSE temps: their uses differ at the first CSE (k-loop j*8 rewritten into CAST/MUL temps by the
 *   loop transforms; b uses split by the arg() call) and become equal after copy propagation.  Tried for cos(pr), each
 *   traced: an index local for the rz read only (propagated back before the first CSE, 5 B); an index local for s2 and
 *   rz (508 B, the loads stay different); a cos local (441 B); a const s16 *sc for s2 and rz (508 B).  Both cos reads
 *   are in one block with no call between, so the first CSE always merges them; a store, a call or a struct copy put between the
 *   two rotations (diagnostics) does not split them either.  A CSE run names each temp at the first reuse of the
 *   expression (pr at the s2 read, cos at the rz read), so j*8 between them needs a j*8 reuse inside the rx statement.
 * note (pass 6 2026-10-06 P6L02): residue unchanged at 5 bytes; the body is unchanged.  New method: mwccarm traced
 *   under a debugger (tools in scratchpad wD9r/p6_P6L02).  Measured: spill slots follow the creation order of the
 *   compiler temps ("@N" names, lower N = higher slot).  The temps are made by IRO_CommonSubs, which runs twice here;
 *   each run names its temps in IR program order.  Ours: the (int)pr temp and cos(pr) are made by the first run, j*8
 *   only by the second run (at the j-loop head), b*0x14 later in the second run.  With long j the first run names
 *   j*8 at the head (above pr).  The original order needs cos(pr) to become common only in the second run (its two
 *   reads must differ at the first CSE and become equal through the copy/expression propagation that runs between
 *   the two CSE runs), or j*8 named in the first run between the s2 read and the rz cos read.  No such form found:
 *   a pr2 copy is removed before the first run (5 B), a second pr = pose.rot reloads pose (653 B).  The same 5 B with
 *   dsi 1.1 to 1.6sp2; the hidden opt_* pragmas tested have no effect.
 * note (pass 6 2026-10-06 P6L12): EXACT (c99 and c).  The residue was the declaration-order ranking of named
 *   spill webs, not CSE timing.  Measured with the temp tracer: named locals take spill slots in declaration order,
 *   above all compiler temps.  Three changes together give the original slots (flag 3C, pr 38, j*8 34, cos 30):
 *   (1) `long j` (NitroSDK s32): j*8 becomes a first-run CSE temp at the k preheader, above cos;
 *   (2) the MUSICAL_MCSS_DrawSprite prototype takes the flag as `u8` (the matched callee is EXACT with `u8 mode` as well),
 *   so the u8 flag is passed without a widening cast and keeps its own named web (no CAST(flag) temp);
 *   (3) C89-style function-scope declarations: the k-loop ints (ang, fx, ... rz) before `u8 flag`, then `int pr`.
 *   With int pr and the u8 flag named, declaration order places ang/fx/X, flag, pr in the original order.
 */
/*
 * note (2026-10-04, wave D3 lane 03): first complete structural draft, not tuned.
 *   Listing extent 021F56BC..021F5EDC (2080 bytes), frame 0x254, mid pool at 021F5A24
 *   (0x04000444, 02148D8C/98/A4, 021F8310/1C/04, 02148B98, 0xFFFFF000, 0xFFFA0000,
 *   02148B54, 0x04000470, 020A1B38 sin/cos table, 0x0400046C) and tail pool 021F5ED0.
 *   Shape: G3 setup (push, mode 0, store 0, mode 3, identity, mode 2); camera pick by
 *   p->f8 bit 0; outer loop i < p[0] over p[1][i] objects, skip null or (fEC >> 2) & 1;
 *   per object a 16-byte pose rec at sp+0x244 filled by kind 0/1/2 of
 *   obj+0x28 -> [0x1c] -> f4; translation/rotation/scale writes; MUSICAL_MCSS_SetupG3;
 *   polygon attr word built from bitfields at obj+0x90; inner loop j over parts of
 *   p->f6C->f4[rec.id]; second pose rec at sp+0x234; two MUSICAL_MCSS_DrawSprite calls;
 *   innermost k < 8 over bytes ent[0x30+k] != 0xFF with s64 fixed point math and
 *   an indirect call through p->fF8.
 *   Known hard parts: the compiler derives small constants from register-held I/O
 *   addresses (lsrs r1, r0, #0x13 = 0x80 from 0x04000470; lsrs #0xe = 0x1000 from
 *   0x0400046C; r0 >> 0x12 = 0x100), the float rounding idiom
 *   (v > 0 ? (float)(v << 12) + 0.5f : (float)(v << 12) - 0.5f) then _ffix, and the
 *   many spilled loop-invariant offsets at sp+0x80..0xAC (0x80 constants and
 *   field offsets r5-8, r5-4 with r5 = 0x10C).
 *   The innermost k-loop math is an approximation of the listing (021F5BD4..021F5E8C),
 *   re-derive it from the listing before tuning.
 *   Verdict of this draft: DIFF, compiled 1680 bytes vs 2080, 1623 bytes differ, 52 of 55
 *   relocations resolved. Prologue already differs (push r3 extra, frame 0x198 vs 0x254):
 *   the original keeps more stack locals (spilled invariants at sp+0x80..0xAC, s64 halves
 *   at sp+0x68..0x74, sub-pose rec at sp+0x234, 0x5C-byte source records).
 *   Siblings: MUSICAL_MCSS_DrawSprite (callee, 13 args, see 021F5B6A..021F5BCC for the stack layout).
 *
 * note (2026-10-05, wave D4 lane 06): p->f8 bit 0 is now read through a one-bit bitfield
 *   (Bits.b0): the camera pick now gives the original lsls #0x1f; lsrs #0x1f test (1623 -> 1611
 *   bytes differ, compiled 1684 vs 2080).  Still open: the frame (0x254 vs 0x198, push without
 *   r3), the zero local stored at [sp] at entry, the spilled invariants, and the innermost k-loop
 *   which still needs re-deriving from the listing (021F5BD4..021F5E8C).
 *
 * note (2026-10-05, wave D5 lane 06): body rewritten from a fresh reading of the listing
 *   (the code after the mid pool needs `show --addr 0x021F5A5C --size 0x480 --thumb`, the
 *   default show desyncs at 021F5A44).  Fixes: r4 is obj for the whole loop, so the j/k loops
 *   read obj+0x6C/0x68/0x20/0x24/0xF8, MUSICAL_MCSS_DrawSprite takes obj (not p) and &cb.z (sp+0xB8,
 *   zeroed per object), and the indirect call goes through the second parameter `arg`
 *   (`arg((u8)pt->f4, &cb.pos, obj->fF8)`); a 0x3C-byte callback record at sp+0xB4 (w out
 *   word, z, pos with y negated, x2/y2 scaled by obj->fD4/16 and fD8/16, z, obj+0xD4 vec,
 *   obj+0x100 vec, obj->fFC, ang + (pt->f10 << 11)); on pt->f4 == 5 the result goes to
 *   obj+0x100/0x104/0x108.  k loop: two rotations (part by pose.rot + sub.rot scaled by the
 *   pose*sub scale, then the table entry (x, z at +2/+4) plus pose.dx/dz by pose.rot scaled by
 *   pose.sx/sy), operand order (s64)vec * scale.  Else-branch: a local 4x4 matrix filled with
 *   constants at sp+0x114, MTX_Copy43To44_(&d_02148B98, &m4), MTX_Concat44(&m4, &d_02148B54,
 *   &m4), second MUSICAL_MCSS_CalcMatrix uses that matrix.  Sub-pose kind 0 leaves dz unset.  obj skip
 *   test reads p[1][i] twice and bit 2 of obj->fEC as a bitfield; obj+0x90 and obj+0x68 are
 *   loop-level pointer locals (sp+0x5C, sp+0x50).  Result: compiled 1996 vs 2080 (was 1684),
 *   frame 0x248 vs 0x254, prologue and the obj test now line up modulo slot numbers.
 *   Open: the zero stored at [sp] at entry (push without r3 in the original), the i slot
 *   (0x5C vs 0x58), mid-pool placement (original after the attr word at 021F5A20), LoadPose
 *   register shape (original keeps src = obj+0x28 in r0), the eight spilled 0x800 rounding
 *   words at sp+0x80..0x94/0x9C/0xA0 and the 0x100/0x10C offsets at sp+0x98/0xA4..0xAC.
 * note (2026-10-05, wave D6 lane 01): three fixes from a fresh reading of the head and the pose loader.
 *   (1) G3i_LookAt_ takes a fifth argument (NULL, as in the matched callers): the zero stored at [sp]
 *   at entry is that stack argument, written once before the camera-pick branch. The prologue now
 *   matches to 021F56F8 apart from the frame size. (2) LoadPose is a switch on the u16 kind with a
 *   compare chain (beq 0, cmp 1, cmp 2, b out), and the id is a u16 read (ldrh) through a
 *   {u16 id; u16 pad; s16 dx; s16 dz} source record. (3) obj+0x90, obj+0x68 and obj+0x28 come from
 *   static inline accessors (ObjAttr, ObjSrcs, ObjAnim): the parameter copy gives the original
 *   `adds r0,r4,#0; str [sp,#K]; adds r0,#0x90; str [sp,#K]` double store for srcs and keeps src =
 *   obj+0x28 in r0 for the kind load (`ldr r3,[r0,#0x1c]`). Compiled 2008 vs 2080 (was 1996).
 *   Open: frame 0x24C vs 0x254 (8 bytes of locals missing, every sp offset is 8 low), attr (obj+0x90)
 *   stays in r5 where the original spills it to sp+0x5C, the zero/kind registers in the obj head
 *   (original zero r2, kind r3; ours zero r3, kind r1), and everything after 021F57BC not re-checked.
 * note (2026-10-05, wave D7 lane 01): read only, no new build. The original spills attr (obj+0x90) to
 *   sp+0x5C and reloads it three times for the attr word (021F59EE, 021F59F0, 021F5A00); r5 is a
 *   short-lived temp there (0x10C offset at 021F59A6). So the original has more long-lived values than
 *   ours; the 8 missing frame bytes are likely two more spilled locals. Also: the callback arg is
 *   ov112 MUSICAL_MCSS_SetMatrix (mode = (u8)pt->f4, in = &cb.pos, p = obj->fF8), see that draft for the
 *   0x38-byte slot layout of obj->fF8.
 * note (2026-10-05, wave D8 lane 01): three local shape fixes from the listing at 021F58C4..021F591E.
 *   (1) The pos and (ox, oy, 0) MTX_TRANS writes are a G3_Translate(x, y, z) static inline: the
 *   original loads all three values before the three stores (ldr r3,[sp,#0x230]; ldr r2; ldr r1;
 *   str; str; str); 0x0400046C writes are G3_Scale(sx, sy, 0x1000). (2) The flag increment is
 *   `flag++` on the u8 local: the original reloads the spilled zero and does adds/lsls/lsrs, where
 *   `flag = (u8)(flag + 1)` folds to movs #1. (3) The rotation ternary has no inner (u16) cast:
 *   `u16 a = (flag & 1) ? 0x10000 - pose.rot : pose.rot;` truncates once after the join, as in the
 *   original. Compiled 2012 vs 2080 (byte count is not comparable, every later offset shifts).
 *   Still open: frame 0x24C vs 0x254. The original spill area is 8 bytes larger (struct locals start
 *   at sp+0xB4 in the original, sp+0xAC in ours), so the original spills two more values; attr
 *   (obj+0x90) is one of them (sp+0x5C, ours keeps it in r5). G3_Translate(pos) still takes r2/r1/r0
 *   for z/y/x and r3 for the register base, the original r3/r2/r1 and r0. The rounding constant
 *   0x800 is derived from the halfword offset 2 held in r6 (`movs r6,#2; ldrsh r1,[r2,r6]` then
 *   `lsls r2,r6,#0xa`), ours does the same from r7. The k-loop past 021F5A5C was not re-checked.
 * note (2026-10-05, wave D9 lane 04): six fixes from a fresh reading of the j/k loops (compiled 2064 vs
 *   2080; on a register-blind instruction diff 94 lines differ, was 210).  (1) obj->f6C has one more
 *   level: the record table is at obj->f6C->f4 (as in matched MUSICAL_MCSS_DrawSprite, McssSpriteSet/Tab/TabEnt), both in
 *   the j-loop test and for the entry reads.  (2) The sub-pose uses the same LoadPose switch: kind 0
 *   also zeroes dz, by cross-jumping into the kind 2 tail (listing 021F5AE6 b 021F5B1A).  The entry
 *   te and the part pt are not locals: j*8 and b*0x14 are spilled CSE values and every read is
 *   written inline.  (3) The 0x1D write goes to 0x0400044C (MTX_STORE), not 0x04000450.  (4) Every
 *   fixed-point product is a FxMul(s64 a, s64 b) static inline: it puts the vector in r0:r1 and the
 *   scale in r2:r3 and spills fx/fz with s/c in r5/r6, as in the original.  psx/psy are s64 locals
 *   assigned before the first product (the original sign-extends both before the first _ll_mul).
 *   (5) obj->fEC bit 0 is a one-bit bitfield.  (6) Declaration order `fx, fz, c, s, X, c2, Z, s2`
 *   gives the original registers in both rotations; the attr word is written right-nested
 *   a7 | (0xF0000 | (a4 | (a3 | (a5 | a0 | 0x40000000)))) to get the original OR order.
 *   Still open: frame 0x250 + push r3 vs 0x254. The original spills attr (obj+0x90) to sp+0x5C and
 *   keeps &pos in r7 across the two MUSICAL_MCSS_CalcMatrix calls; ours keeps attr in r5 and rematerialises
 *   &pos.  Tried without effect: attr declaration position, block scope, a struct type, a PolyAttr
 *   inline, a Persp inline and a `Vec *pp` local for the 660C calls.  A separate `int w` local (not
 *   cb.w) gives the 0x254 frame but puts w at sp+0xB0, not 0xB4, so it is not the answer.  The k-loop
 *   head schedules the fx/fz loads before `ang` (original: ang first); `ent->parts[k]` inline instead
 *   of `b` is worse.  `j = 0` sits after the first scale product in the original; only an unnatural
 *   split of the sy/sx block reproduces it.
 * note (2026-10-05, wave D9r lane 22): 94 -> 0 instruction lines differ; 5 bytes left (two spill slots).
 *   (1) The 0x040004A8 word is the SDK inline G3_TexImageParam with enum parameter types, as in the
 *   matched sibling arm9 MCSS_Draw (same renderer: same matrix calls, Pose switch, TexInfo record
 *   at obj+0x90 with addr/s/t/fmt/pltt0 at 0/0xC/0x10/0x14/0x1C).  With it, attr spills to sp+0x5C and
 *   &pos stays in r7 across the MUSICAL_MCSS_CalcMatrix calls; the frame is 0x254 and the push has no r3.
 *   (2) attr, srcs and a new ctrl (obj+0x28) are plain assignments in the order attr, ctrl, srcs (the
 *   accessor inlines are gone; they made no difference once attr spills).  (3) Declaration order
 *   ent, attr, i, j, srcs, k gives the original slots.  (4) for (j = 0; ...) without the early
 *   j = 0 statement: the 0 is shared with the first FxMul high word, as in the original.  (5) ang is an int
 *   (u16 cast at the assignment).  (6) X = te.x; X += pose.dx; (same for Z) gives the te.x-first load
 *   order.  (7) c2 (the cos of pr) is written inline at both uses: the original spills it as a CSE
 *   temp (lowest slot, reload with no copy).  (8) The obj+0x100 write is VEC_Set(v, x2, y2, 0), which
 *   loads y2 before x2.
 *   Residue: the CSE temps j*8 and c2 have swapped slots (original j*8 sp+0x34, c2 sp+0x30; ours the
 *   reverse).  A diagnostic without the j-loop use of ents[j] gives the original order, so the j*8
 *   temp is created later than c2 in ours.  Tried without effect: s2 inline too, c/s inline (worse),
 *   an idx local, operand order of the c2 products, k-loop locals at function scope, a te local in
 *   the k loop, src passed straight to LoadPose, named c2 in any scope (goes to the named slots).
 * note (2026-10-05, wave D9r lane 53): residue unchanged at 5 bytes (j*8 CSE temp at sp+0x30, cos(pr) temp
 *   at sp+0x34; original reverse).  One clean-up: the `one` local (0x1000 for the sub-pose LoadPose) is
 *   gone; LoadPose(&sub, src, 0x1000) gives the same bytes (the 0x1000 reload from sp+0x64 is the
 *   compiler's own hoisted constant).  Tried without effect on the slot pair (each a real compile): a TabEnt
 *   pointer or a u16 h local for the head read; `int id = j` alias at head or in the k loop; the j loop and the
 *   k loop as if/do-while; pose.rot inline (no pr local; same bytes); s2 load moved above the X/Z reads; X/Z
 *   reads as (ents + j)->x, as a Cell() inline, or as byte offsets (j * 8 + 2) in both head and k loop
 *   (byte offsets in the k loop only stop the j*8 CSE and LICM-hoist a second copy); cos(pr) spelled four
 *   other ways (1 + idx, (T + idx)[1], &T[idx][1], idx << 1) and through a Cos() inline; RotX/RotZ inlines and
 *   an FX_MUL-style macro for the second rotation (worse); a `const s16 *sc` pointer for s2/cos (worse);
 *   k-loop declaration order.  The pair stays swapped in every variant, so its order is probably fixed by the
 *   colouring tie-break, not by source position of the two expressions.
 * note (2026-10-05, wave D9r lane 90): residue unchanged at 5 bytes (same slot pair).  Compared with the
 *   matched twin arm9 MCSS_Draw line by line and tested new forms, each a real compile.  Same 5 bytes:
 *   outer i loop as the twin's `i = 0; if (n > 0) do { } while (++i < n);`; a typed MAnim/Frame chain
 *   (`((Obj *)obj)->anim->frames[pose.id]`) instead of the raw obj+0x6C casts; the node as a 0x5C-byte
 *   struct array (`&(*nodes)[idx]`, as the twin); a frame-cells pointer local at the head; a named int
 *   node index at the head; SDK FX_SinIdx/FX_CosIdx inlines (int idx, fx16 return) for every table
 *   read; the break test as `if (ent->parts[k] == 0xFF) break; b = ent->parts[k];`; the rotated vector
 *   in vx/vz locals before the two FxMul calls.  Worse: the head index through a NodeIdx() inline
 *   (loses the loop-condition entry pointer, 1056 B); the k loop as a static inline (not inlined,
 *   1832 B); `k < 8 && parts[k] != 0xFF` in the for condition (744 B); X/Z as one expression each
 *   (64 B).  Diagnostics (not candidates): a third use of the cos(pr) temp, X/Z reads moved to the top
 *   of the k loop, and no Z read all keep ours order (j*8 below cos(pr), b*0x14 lowest), so the order
 *   does not follow use count or program position of the k-loop reads.
 * note (2026-10-05, wave D9r lane 107): residue unchanged at 5 bytes (j*8 temp sp+0x30, cos(pr) temp sp+0x34;
 *   original reverse).  New tries, each a real compile: FxMul with int (fx32) parameters as in the twin's
 *   FX_MUL, with s64 or int psx/psy (89 B, worse); cos(pr) as an int-typed value ((int) cast at both uses,
 *   or an int-returning CosI() inline; same 5 B); 5EDC prototype and Ent fields as int, as in the matched
 *   MUSICAL_MCSS_DrawSprite, and 660C with its matched const int / u32 parameters (same 5 B); `int b` for the part
 *   byte (same 5 B); s16 (fx16) locals for s2, for c/s, or for all three (508 to 728 B, worse); named c2 in
 *   three placements (430+ B, adds a copy); mixed spellings for the X/Z reads (index for one, byte offset
 *   for the other: 870 B; `(ents + j)->x` for X only: same 5 B).  Diagnostics: `int pr` swaps the pr and
 *   flag slots (0x38/0x3C), so local width moves slot order; an extra k-loop use of ents[j] does not move
 *   j*8 off sp+0x30.  The slot order of the two CSE temps does not follow use count or type.
 * note (2026-10-05, wave D9r lane 124): residue unchanged at 5 bytes (j*8 temp sp+0x30, cos(pr) temp
 *   sp+0x34; original reverse).  Tested the inline-return-temp idiom (ov125 021D6B40) on every helper in
 *   the j/k loops, each a real compile: LoadPose hand-expanded for sub, and for both pose and sub (output
 *   identical to the draft, byte for byte); RoundF hand-expanded as a plain ternary and with a block-local
 *   `int v` (identical); the two second-rotation FxMul calls hand-expanded with a block-local s64 operand
 *   (identical) or as one expression (2084 B, worse); a Cell() inline returning &ents[j] at all three
 *   uses, head included (1056 B).  So the inlines are transparent here; no inline temp sets this pair.
 *   Also tried: the head .h read as a byte offset (j*8+6: 1040 B) or as (ents + j) cast to char * (same
 *   5 B); an index local for s2/cos(pr) as u32, int (same 5 B) or u16 (483 B).  Diagnostics: `u32 j`
 *   and a branch between the two cos(pr) uses keep ours order.
 * note (2026-10-05, wave D9r lane 135): residue unchanged at 5 bytes (j*8 temp sp+0x30, cos(pr) temp
 *   sp+0x34; original reverse).  New head-of-j-loop forms, each a real compile, all give the same 5 B
 *   (the front end normalises them to one tree): a `Tab *tab` assigned in the loop condition
 *   (`j < (tab = &T[pose.id])->count`) and read at the head as tab->ents[j].h, also through a TabEnt
 *   pointer local taken from tab (te = tab->ents; te[j].h, or te = &tab->ents[j]); entries as a u16/s16
 *   halfword array at all three uses (`((u16 *)ents)[j * 4 + 3]`, x/z at j * 4 + 1 / + 2); getters that
 *   take the already-computed ents (or &T[pose.id]) plus j: EntH(e, j), EntAt(e, j)->h, EntIdx(e, j),
 *   TabEntAt(t, j)->h (head only: same 5 B; also at the X/Z reads: 6 B, add operand swap); src at
 *   function scope.  Worse: a struct copy `TabEnt e = ents[j]` at the head (1100 B); h as an 8-bit
 *   bitfield pair (u16, s16 or u32 fields: 998 to 1056 B, lsls/lsrs instead of and/asr); the u16 head
 *   read only (X/Z left as fields: 1040 B); tab also used at the X/Z reads (1136 B, tab held in a register).
 *   Off the head, also same 5 B: a non-const `s16` table (as in the twin), the table named
 *   FX_SinCosTable_, s2 and the second rotation in a nested block.  Diagnostics: without cos(pr) as a CSE
 *   (second use replaced) j*8 stays at sp+0x30, so it is the cos(pr) temp that lands above j*8; without
 *   the head use j*8 becomes a LICM temp at sp+0x3C (above the narrow pr/flag locals) and cos(pr) drops
 *   to sp+0x30.  No head spelling reached changes the temp order.
 * note (2026-10-05, wave D9r lane 152): residue unchanged at 5 bytes; the file body is unchanged.
 *   New tries, each a real compile.  The slot order of the late group (flag, pr, j*8, cos(pr), b*0x14)
 *   moves with the declared TYPE of j, not with any spelling of the expressions:
 *   - `long j` (or s32/unsigned long): j*8 goes to sp+0x38, above pr (pr 0x34, cos 0x30 correct, b*0x14
 *     0x2c correct): 6 B.  `unsigned int j` keeps ours order (7 B).  The type of i, of the k-loop
 *     locals (long/fx32), of b (int), of u32 (unsigned long), and fx32 struct fields do not move it.
 *   - `long j` plus `int pr` (or long pr): j*8 0x34 and cos 0x30 are correct, but pr and flag swap
 *     (pr 0x3C, flag 0x38): 9 B.  So the original needs u16 pr with j*8 between pr and cos; no type
 *     pair of (j, pr) gives that.
 *   - reusing the first-rotation `c` (or `s` and `c`) for the second rotation: j*8 goes to 0x34, but
 *     the second web of c gets the lowest slot (0x2C, below b*0x14) and the rz product gains a copy
 *     (431 B).  A named s16 c2 also adds the copy and stays at 0x34.
 *   - pose.rot spelled in place of pr in ang, s2, or one/both cos reads: j*8 goes to 0x34, but pr
 *     takes a late slot (0x30) and cos moves to 0x38 (5 to 10 B; split spellings also break the
 *     shared T+idx address).
 *   - same 5 B: cos and sin as a {sin, cos} struct table (cast or extern), five mixed spellings of one
 *     cos read (1 + idx, (T + idx)[1], *(&T[i] + 1), (idx << 1) + 1, (&T[i])[1]), FX_SinIdx/FX_CosIdx
 *     with int or long idx (with long j), pr declared with an initialiser in a block, pr at function
 *     scope reused for the G3 rotation angles (with long j: still 6 B), b assigned after its
 *     declaration, an unreferenced label between the products, byte-offset j * sizeof(TabEnt) reads.
 *   Worse: RotA/RotB inlines taking cos as a parameter (432 B, rz product copy); a `const s16 *sc`
 *   pointer (432 B); a 5EDC prototype with a long j parameter (j itself moves to the late group).
 *   Reading of the pattern: the late slots look like spill temporaries in the order the allocator
 *   spills them (round by round, then by definition order).  cos(pr) is in the first round in every
 *   variant; the original needs it in a later round than pr.  No natural source change found that
 *   does this without moving another slot.
 * note (2026-10-05, wave D9r lane 198): residue unchanged at 5 bytes; the file body is unchanged.  Lane 152's
 *   suggestion (long j or s32 plus a way to push pr back above j*8 with pr still u16) tested as a table; every row a
 *   real compile.  Slots low to high (b*0x14 is 0x2C in every row):
 *   original                     cos 30, j*8 34, pr 38, flag 3C
 *   base (int j)                 j*8 30, cos 34, pr 38, flag 3C: 5 B
 *   long j / unsigned long j     cos 30, pr 34, j*8 38, flag 3C: 6 B (8 B for unsigned long: extra loop-test byte)
 *   unsigned int / size_t j      as base, 7 B (loop-test byte differs)
 *   named `int jo = j * 8;` (head, X and Z read through ((TabEnt *)((char *)ents + jo))), int or u32, any
 *   declaration order of {jo, pr, flag} at function scope (6 orders), jo at function or j-body scope:
 *                                cos 30, pr 34, jo 38, flag 3C: 7 B (the X/Z add operand order also changes)
 *   named jo plus a redundant second `jo = j * 8;` BEFORE the last use (idiom a-redundant-second-assignment...;
 *   after the loadpose, before the 5EDC calls, before the k loop, first or after the break test in the k body):
 *                                jo 30, cos 34, pr 38, flag 3C: 6 B.  A second assignment after the last use
 *                                (after cb.pos or at the end of the k body) is dead and gives the single-assign row.
 *   jo declared long or as a char * / void *: long moves it to a high named slot (22 B); a pointer is the base row.
 *   jo split into jh (head) and jk (k loop): as the double-assign row.
 *   So j*8 only ever lands at one of two places: below cos (temp) or above pr (named, or long-typed); the original
 *   needs the slot between them.  Declaration order and scope of jo, pr and flag never moved any slot.
 *   pr changes with long j: `int`, `long`, `u32` or `unsigned long` pr give j*8 34 and cos 30 (correct) but pr 3C and
 *   flag 38 (5 B differ); flag as u16, s16 (same 5 B), int, u32, long with `flag = (flag + 1) & 0xFF` (1429 to 1462 B);
 *   pr s16 or u8 (740 B); pr at function scope as int (14 to 43 B, pr 0x48).  pr read earlier (at the top of the j
 *   body, 1034 B; before the k loop, 309 B; first statement of the k body or declared with an initialiser before
 *   the break test, 19 B: the load schedule changes), later (just before the s2 read: 1780 B).  pr declared at j
 *   body scope: same as base (5 B) or, with long j, 6 B.
 *   The angle through u16 helpers SinA(u16)/CosA(u16): with pr passed or with pose.rot passed directly, no pr local
 *   used at the reads: same slots as base (5 B) or as long j (6 B).  j as an enum type: 1091 B; signed char j: 91 B.
 *   Diagnostic only: a third pr use does not give a comparable build (frame changes).
 *   Reading: the slot order is a ranking, not a source position: with j*8 a CSE temp it ranks below cos(pr), with
 *   j*8 named (or long) it ranks above pr, and the original has it between.  No natural form found for the middle rank.
 * note (2026-10-05, wave D9r lane S8): residue unchanged at 5 bytes; the file body is unchanged (the earlier
 *   lane left only notes, body identical to HEAD).  Slot facts measured with a Thumb decode of the compiled
 *   bytes (7 real compiles, none repeating a lane 152 or 198 row):
 *   - the compound byte-offset idiom of the sibling 021F546C (`u32 jo = j; jo *= 8;`, head, X and Z read
 *     through (TabEnt *)((char *)ents + jo)): b 2C, cos 30, pr 34, jo 38, flag 3C (7 B).  j*8 is not a named
 *     byte offset: any named local lands above pr, the original has j*8 below pr.
 *   - named locals order by first assignment in the code, not by declaration: with `u16 pr;` declared in the
 *     j body BEFORE jo, pr still lands below jo (pr 34, jo 38).  So declaration order cannot place jo.
 *   - the spilled CSE temps (b*0x14, cos, j*8) always sit below every named local.  The original j*8 (0x34)
 *     is in the temp band, above cos, which is the only pair left swapped.
 *   - statement order tests (second rotation before the first; fz read after the Z read) change the frame
 *     and schedule (836 and 842 B), so they cannot show the pair order.
 *   mwcc source (inspiredrobot/mwcc): Coloring_SelectColors flags a web Spilled in select-stack order and
 *   SpillCode_00531800 (slot assignment, not reconstructed there) runs per retry round; Coloring_SimplifyGraph
 *   picks potential spills by min spill_cost / degree.  Our listing and the original are instruction identical,
 *   so cost and degree of j*8 and cos are equal in both builds; only the web numbering or tie order differs.
 *   Lane 22's diagnostic (no head use of ents[j] gives the original order) fits a numbering reading: the head
 *   use makes j*8 a temp that is created before cos in ours.  No source form that creates cos(pr) before j*8
 *   without moving code was found (cos has no occurrence before the k body in the original listing).
 * note (2026-10-05, final push G2L5, rounds 2 and 3): 16 more real compiles, all DIFF, none better than 5 B.  `u16 j`, `s16 j`
 *   (94/93 B); rx and rz as one expression each with both products (836 B); `long j` with `int pr` at function scope
 *   (18 B), with pr assigned at object level (1794 B), with `u16`/`s16`/`unsigned short` flag (11 B), plus opt_lifetimes
 *   or scheduling off (9 B); head chain through a named `int id = pose.id` (723 B); second rotation rz before rx (652 B);
 *   `Z * cos` operand order (5 B, same).  Also off: opt_unroll_loops, opt_vectorize_loops, opt_findoffsets (5 B).  mwcc
 *   SpillCode.c: spill cost is use count times block weight; earlier lanes' extra-use diagnostics did not move the pair, so
 *   slot order is not cost-driven.  Twin arm9 MCSS_Draw re-read: no k-body pr rotation, nothing to borrow.
 * note (pass 2 2026-10-06 P2L09): residue unchanged at 5 bytes; the body is unchanged.  40 real compiles.
 *   Slots low to high of the triple j*8 / cos(pr) / pr (flag 0x3C in all rows unless said):
 *   - `#pragma opt_strength_reduction off`: cos 30, pr 34, j*8 38 (6 B), the same as `long j`.  So strength
 *     reduction is what ranks j*8 below cos.  Under SR off: pose.rot for pr everywhere, pr at j-body or function
 *     scope (3 positions), u16 pr with an int/u32 `pi = pr >> 4` index, `(pr = pose.rot) + sub.rot`: SR-off row
 *     (6 to 7 B); int or u32 pr: cos 30, j*8 34 (correct), flag 38, pr 3C (9 to 10 B); pose.rot in ang only:
 *     pr 30, cos 34, j*8 38 (8 B).  SR off plus opt_loop_invariants off: 1501 B; plus opt_lifetimes off: SR-off row.
 *   - SR on, pose.rot spelled in ang only (pr kept for s2 and both cos reads): pr 30, j*8 34 (correct), cos 38,
 *     5 B.  In that form, same 5 B and same slots: ang before `pr = pose.rot`, pr declared at function scope,
 *     j-body scope or first in the k body, pr assigned right before s2, SinA/CosA(u16) inlines on pr.  Back to
 *     the base order (5 B): int pr, an int `pi = pr >> 4` or `pi = pose.rot >> 4` index, SinA/CosA(pose.rot).
 *     u32 pr 6 B; plus long j 8 B.  pose.rot in rz cos only 653 B, rx cos only 505 B, both cos or s2 only 10 B.
 *   - j*8 written as `(char *)ents + (j << 3)` at all three uses: base slots, 6 B (add operand byte); at the head
 *     only or the k loop only: 1040 B (CSE lost).  opt_loop_invariants plus opt_lifetimes off: 5 B (base).
 *   Four orders of the triple are reachable (j8<cos<pr, cos<pr<j8, pr<j8<cos, cos<j8 with pr above flag); the
 *   original cos<j8<pr<flag was not produced.
 * note (pass 3 2026-10-06 P3L04): residue unchanged at 5 bytes; the body is unchanged.  40 real compiles.
 *   New regime: the second-rotation cos stored in the first-rotation `c` with `rz += FxMul(X * s2 + Z * c, psy)`
 *   (operand order Z * c removes lane 152's extra copy): 7 B, j*8 0x34 and pr 0x38 now correct, but the c web
 *   takes 0x2C and b*0x14 moves to 0x30 (original b*0x14 0x2C, cos 0x30).  In that regime, same 7 B: s also
 *   reused for s2, s or fx reused for cos, int/u32 b, the assignment inside the rx argument, opt_loop_invariants
 *   off.  Worse: `c * X` (18 B), plus pose.rot in ang (13 B), plus SR off (13 B), plus opt_lifetimes off (546 B),
 *   c at function scope (684 B), c and s2 moved above the X/Z reads (851 B), CosA/SinA(u16) inlines (14 B).
 *   Same 5 B base slots: s reused for s2 only; an int idx index local for s2 only; RotX/RotZ inlines reading the
 *   table; a named TabEnt *e for the k-loop reads; rx/rz as a local struct; c assigned from one read with the other
 *   read inline (either order); opt_strength_reduction_strict on.  Worse: idx local in some cos reads only
 *   (508 B / 9 B), a const s16 *sc pair pointer for one cos read (502/508 B), named c2 with Z * c2 at three
 *   declaration places (14/23/64 B), separate x1/z1/x2/z2 running locals (898 B); SR off plus an `int id = j`
 *   alias at the head or in the k loop gives the SR-off row (6 B).  Reading: a reused variable's second web ranks
 *   below every optimizer temp, a first named web ranks in the named band, so cos in the original is a temp made
 *   after the SR-created j*8 web and before b*0x14; no source form found that delays the cos CSE that way.
 * note (pass 4 2026-10-06 P4L03): residue unchanged at 5 bytes; the body is unchanged.  40 real compiles.
 *   Same 5 B: RotA/RotB inlines with cos as a parameter and `Z * c`; a `const s16 *sc` pair pointer with
 *   `Z * sc[1]` (with or without s2); `s16 sc[2]` with `Z * sc[1]`; rx/rz as `int r[2]` (const or non-const
 *   table); `register` on pr or j.  Long-j row (6 B, flag 3C, j*8 38, pr 34, cos 30): u16 pr reused at
 *   function scope for either G3 angle; s2 read above the X/Z reads (77 B, same slots); the head .h read as
 *   a byte offset `j * 8 + 6` or `(j << 3) + 6` (merged under long j); `u16 pr = 0;` initialisers.  Long j
 *   plus int pr with `pr >>= 4`: 9 B (pr 3C, flag 38); with u16 pr: 10 B (pr 3C, lsrs).  Long j plus int pr
 *   reused for the obj+0xFC G3 angle: 18 B (pr 0x48).  `int sc[2]` for s2/cos: 14 B (the array-to-register
 *   web takes 0x3C above flag).  Worse: `pr / 16` (15 B all reads, 656 B rz only), a {s, c} struct copied
 *   from the table (576 B), one cos read as a char* byte offset (495/504 B: the table load is never merged
 *   after CSE0), opt_propagation off (1898 B), opt_common_subs off (1438 B).  Reading (research in the lane
 *   folder): the global table load is merged only by the first CSE, so cos is always numbered before the SR
 *   j*8 web; without SR on j, j*8 is numbered at the j-loop head, before the k-top pr.  The original order
 *   (flag, pr, j*8, cos) needs one of the two moved, and no source form found does that.
 * note (pass 5 2026-10-06 P5L02): residue unchanged at 5 bytes; the body is unchanged.  41 real compiles.
 *   New forms, none better: `int b` reused as the Part byte offset (`b *= sizeof(Part)`) with the cos stored in the
 *   first-rotation c (or s, fx): instructions identical, 7 B, j*8 and pr right but b*0x14 30 above the c web 2C (both
 *   are second webs and rank by def position, so b*0x14 at the k top always ranks above the cos); declaration order
 *   of b and c in that form: same or 593/684 B.  A local struct {int s, c} for s2/cos: 14 B (promoted, cos 3C above
 *   flag).  Function-scope `s16 sn, cs` shared with the object-level G3 rotation, cs reused for the k-loop cos: 5 B
 *   base slots (narrow reuse is transparent); as int: 23 B (decl slot 0x48); a j-body `int n` node index reused for
 *   the cos: 23 B; the function-scope int ox reused: 821 B.  Same 5 B: a `u16 pr2 = pr` (or int) copy for the rz
 *   cos read (value numbering sees through it), a k-loop `const s16 *tab` for all table reads, pose.rot spelled
 *   everywhere, a named s16 c2, the break as a goto, pr first assigned at the object-level G3 angle.  Named jo
 *   (head or k loop): 7 B or 1040 B.  Strength reduction off or long j in the reuse forms: 13 B (J P B C order).
 *   Reading (research in scratchpad wD9r/p5_P5L02): every measured order fits one birth-phase ranking (decl webs and
 *   promoted aggregates, then code-order webs flag/pr/cos with the head j*8 first when not strength reduced, then
 *   strength-reduced j*8, then load-deletion temps, then b*0x14, then second webs of reused ints).  The original
 *   needs j*8 between pr and cos, which no tested source form produces.
 * note (pass 6 2026-10-06 P6L10): residue unchanged at 5 bytes; the body is unchanged.  4 real compiles plus about 25
 *   traced compiler runs (tools in scratchpad wD9r/p6_P6L10).  FX_SinIdx/FX_CosIdx inlines (`T[((idx >> 4) << 1)]`, + 1):
 *   5 B, the parameter is propagated before the first CSE and cos stays a first-run temp.  The b*0x14 split at the first
 *   CSE is caused by any branch between the uses, but only for the b chain (index under a memory-loaded base); the
 *   const-table pr/cos chain crosses the same branches at the first CSE.  Single-use locals for the rz read (pointer,
 *   cos value, second pose.rot read) are propagated back before the first CSE or leave the load read twice.  `long j`
 *   plus `int pr`: 9 B with j*8, cos and b*0x14 correct and only pr/flag swapped; the trace shows that the flag slot
 *   is the CAST(flag) temp and a named int pr outranks every temp, so the original pr must be a temp created between
 *   the flag temp and the k-preheader j*8 temp, where no pr occurrence exists.  `#pragma opt_loop_invariants off`
 *   with s2 above the X/Z reads: 77 B (the head j*8 stops being a CSE candidate).
 * note (pass 6 2026-10-06 P6L02, round 2): residue unchanged at 5 bytes; the body is unchanged.  Traced why j*8 and
 *   b*0x14 are second-run CSE temps: their uses differ at the first CSE (k-loop j*8 rewritten into CAST/MUL temps by the
 *   loop transforms; b uses split by the arg() call) and become equal after copy propagation.  Tried for cos(pr), each
 *   traced: an index local for the rz read only (propagated back before the first CSE, 5 B); an index local for s2 and
 *   rz (508 B, the loads stay different); a cos local (441 B); a const s16 *sc for s2 and rz (508 B).  Both cos reads
 *   are in one block with no call between, so the first CSE always merges them; a store, a call or a struct copy put between the
 *   two rotations (diagnostics) does not split them either.  A CSE run names each temp at the first reuse of the
 *   expression (pr at the s2 read, cos at the rz read), so j*8 between them needs a j*8 reuse inside the rx statement.
 * note (pass 6 2026-10-06 P6L02): residue unchanged at 5 bytes; the body is unchanged.  New method: mwccarm traced
 *   under a debugger (tools in scratchpad wD9r/p6_P6L02).  Measured: spill slots follow the creation order of the
 *   compiler temps ("@N" names, lower N = higher slot).  The temps are made by IRO_CommonSubs, which runs twice here;
 *   each run names its temps in IR program order.  Ours: the (int)pr temp and cos(pr) are made by the first run, j*8
 *   only by the second run (at the j-loop head), b*0x14 later in the second run.  With long j the first run names
 *   j*8 at the head (above pr).  The original order needs cos(pr) to become common only in the second run (its two
 *   reads must differ at the first CSE and become equal through the copy/expression propagation that runs between
 *   the two CSE runs), or j*8 named in the first run between the s2 read and the rz cos read.  No such form found:
 *   a pr2 copy is removed before the first run (5 B), a second pr = pose.rot reloads pose (653 B).  The same 5 B with
 *   dsi 1.1 to 1.6sp2; the hidden opt_* pragmas tested have no effect.
 * note (pass 6 2026-10-06 P6L12): EXACT (c99 and c).  The residue was the declaration-order ranking of named
 *   spill webs, not CSE timing.  Measured with the temp tracer: named locals take spill slots in declaration order,
 *   above all compiler temps.  Three changes together give the original slots (flag 3C, pr 38, j*8 34, cos 30):
 *   (1) `long j` (NitroSDK s32): j*8 becomes a first-run CSE temp at the k preheader, above cos;
 *   (2) the MUSICAL_MCSS_DrawSprite prototype takes the flag as `u8` (the matched callee is EXACT with `u8 mode` as well),
 *   so the u8 flag is passed without a widening cast and keeps its own named web (no CAST(flag) temp);
 *   (3) C89-style function-scope declarations: the k-loop ints (ang, fx, ... rz) before `u8 flag`, then `int pr`.
 *   With int pr and the u8 flag named, declaration order places ang/fx/X, flag, pr in the original order.
 */
void MUSICAL_MCSS_DrawMC(int *p, void (*arg)(unsigned, McssMatrixInput *, Big *))
{
    Pose pose;
    Pose sub;
    struct Vec3 pos;
    Mtx44 m3;
    Mtx43 m1;
    Mtx33 m2;
    Mtx44 m4;
    Mtx44 proj;
    Mtx33 m5;
    CB cb;
    Ent *ent;
    TexInfo *attr;
    int i;
    long j;
    char **srcs;
    u8 k;
    char *obj;
    char *ctrl;
    int ox, oy;
    int ang, fx, fz, c, s, X, Z, s2, rx, rz;
    u8 flag;
    int pr;

    REG(0x04000444) = 0;
    REG(0x04000440) = 0;
    REG(0x0400044C) = 0;
    REG(0x04000440) = 3;
    REG(0x04000454) = 0;
    REG(0x04000440) = 2;
    if ((((McssRenderPool *)p)->bits.cameraBack) == 0)
        G3i_LookAt_(&d_02148D8C, &d_02148D98, &d_02148DA4, 1, 0);
    else
        G3i_LookAt_(&d_021F8310, &d_021F831C, &d_021F8304, 1, 0);
    MTX_Inverse43(&d_02148B98, &m1);
    MI_Copy36B(&m1, &m2);
    MTX_Copy33To44_(&m2, &m3);

    for (i = 0; i < p[0]; i++) {
        if (((char **)p[1])[i] == 0 || ((McssMcAnim *)((char **)p[1])[i])->bits.stopped)
            continue;
        REG(0x04000444) = 0;
        obj = ((char **)p[1])[i];
        attr = (TexInfo *)(obj + 0x90);
        ctrl = obj + 0x28;
        srcs = (char **)(obj + 0x68);
        cb.z = 0;
        LoadPose(&pose, ctrl, 0x1000);
        pos.x = *(int *)(obj + 0xC8);
        pos.y = *(int *)(obj + 0xCC);
        pos.z = *(int *)(obj + 0xD0);
        if ((((McssRenderPool *)p)->bits.cameraBack) == 0) {
            ox = pose.dx << 8;
            oy = -pose.dz << 8;
        } else {
            proj.m[0] = 0x80000;
            proj.m[1] = 0;
            proj.m[2] = 0;
            proj.m[3] = 0x80000;
            proj.m[4] = 0;
            proj.m[5] = 0x60000;
            proj.m[6] = 0;
            proj.m[7] = (int)0xFFFA0000;
            proj.m[8] = 0;
            proj.m[9] = 0;
            proj.m[10] = (int)0xFFFFF000;
            proj.m[11] = 0x1000;
            proj.m[12] = 0;
            proj.m[13] = 0;
            proj.m[14] = 0;
            proj.m[15] = (int)0xFFFFF000;
            MTX_Copy43To44_(&d_02148B98, &m4);
            MTX_Concat44(&m4, &d_02148B54, &m4);
            MUSICAL_MCSS_CalcMatrix((const int *)(&pos), (const int *)(&m4), (u32 *)(&pos), (u32 *)(&cb.w));
            pos.x = FX_Div(pos.x, cb.w);
            pos.y = FX_Div(pos.y, cb.w);
            MUSICAL_MCSS_CalcMatrix((const int *)(&pos), (const int *)(&proj), (u32 *)(&pos), (u32 *)(&cb.w));
            ox = RoundF(pose.dx);
            oy = RoundF(-pose.dz);
        }
        pos.z = *(int *)(obj + 0xD0);
        flag = 0;
        if (*(int *)(obj + 0xD4) < 0)
            flag++;
        G3_Translate(pos.x, pos.y, pos.z);
        if ((((McssRenderPool *)p)->bits.cameraBack) == 0)
            G3_MultMtx44(&m3);
        G3_Translate(ox, oy, 0);
        {
            u16 a = (flag & 1) ? 0x10000 - pose.rot : pose.rot;
            G3_RotZ(-FX_SinCosTable_[(a >> 4) * 2], FX_SinCosTable_[(a >> 4) * 2 + 1]);
        }

        {
            int sy = FxMul(pose.sy, *(int *)(obj + 0xD8));
            int sx = FxMul(pose.sx, *(int *)(obj + 0xD4));
            G3_Scale(sx, sy, 0x1000);
        }
        {
            u16 a = *(u16 *)(obj + 0xFC);
            MTX_RotZ33_(&m5, -FX_SinCosTable_[(a >> 4) * 2], FX_SinCosTable_[(a >> 4) * 2 + 1]);
            MTX_MultVec33(obj + 0x100, &m5, obj + 0x10C);
            VEC_Subtract(obj + 0x100, obj + 0x10C, obj + 0x10C);
            *(int *)(obj + 0x10C) = FX_Div(*(int *)(obj + 0x10C), *(int *)(obj + 0xD4));
            *(int *)(obj + 0x110) = FX_Div(*(int *)(obj + 0x110), *(int *)(obj + 0xD8));
        }
        REG(0x0400044C) = 0x1D;
        MUSICAL_MCSS_SetupG3();
        {
            G3_TexImageParam(attr->fmt, GX_TEXGEN_TEXCOORD, attr->s, attr->t, GX_TEXREPEAT_ST, GX_TEXFLIP_ST, attr->pltt0, attr->addr);
        }
        for (j = 0; j < (*(Tab **)(*(char **)(obj + 0x6C) + 4))[pose.id].count; j++) {
            char *src;
            src = *srcs + (((*(Tab **)(*(char **)(obj + 0x6C) + 4))[pose.id].ents[j].h & 0xFF00) >> 8) * 0x5C;
            LoadPose(&sub, src, 0x1000);
            ent = (Ent *)(*(char **)(obj + 0x20) + 4 + sub.id * 0x38);
            if (ent->overlayW != 0) {
                if (((McssMcAnim *)obj)->bits.drawOffset)
                    MUSICAL_MCSS_DrawSprite(obj, ent->overlayX, ent->overlayY, ent->overlayW, ent->overlayH, ent->overlayU,
                                  ent->overlayV + ent->overlayH, &sub, (u16 *)(&pose), j, ((McssRenderPool *)p)->bits.cameraBack, &cb.z, flag);
                else
                    MUSICAL_MCSS_DrawSprite(obj, ent->overlayX, ent->overlayY, ent->overlayW, ent->overlayH, ent->overlayU,
                                  ent->overlayV, &sub, (u16 *)(&pose), j, ((McssRenderPool *)p)->bits.cameraBack, &cb.z, flag);
            }
            MUSICAL_MCSS_DrawSprite(obj, ent->spriteX, ent->spriteY, ent->spriteW, ent->spriteH, ent->spriteU, ent->spriteV,
                          &sub, (u16 *)(&pose), j, ((McssRenderPool *)p)->bits.cameraBack, &cb.z, flag);
            for (k = 0; k < 8; k++) {
                u8 b = ent->parts[k];

                s64 psx, psy;
                if (b == 0xFF)
                    break;
                pr = pose.rot;
                ang = (u16)(pr + sub.rot);
                fx = (*(Part **)(obj + 0x24))[b].x;
                fz = (*(Part **)(obj + 0x24))[b].z;
                s = FX_SinCosTable_[(ang >> 4) * 2];
                c = FX_SinCosTable_[(ang >> 4) * 2 + 1];
                psx = pose.sx;
                psy = pose.sy;
                rx = FxMul(fx * c - fz * s, FxMul(psx, sub.sx));
                rz = FxMul(fx * s + fz * c, FxMul(psy, sub.sy));
                X = (*(Tab **)(*(char **)(obj + 0x6C) + 4))[pose.id].ents[j].x;
                X += pose.dx;
                Z = (*(Tab **)(*(char **)(obj + 0x6C) + 4))[pose.id].ents[j].z;
                Z += pose.dz;
                s2 = FX_SinCosTable_[(pr >> 4) * 2];
                rx += FxMul(X * FX_SinCosTable_[(pr >> 4) * 2 + 1] - Z * s2, psx);
                rz += FxMul(X * s2 + FX_SinCosTable_[(pr >> 4) * 2 + 1] * Z, psy);
                rx += RoundF(sub.dx);
                rz += RoundF(sub.dz);
                cb.in.a = pos;
                cb.in.a.y = -cb.in.a.y;
                cb.in.b.x = FxMul(rx, *(int *)(obj + 0xD4) / 16);
                cb.in.b.y = FxMul(rz, *(int *)(obj + 0xD8) / 16);
                cb.in.b.z = cb.z;
                cb.in.d = *(struct Vec3 *)(obj + 0x100);
                cb.in.e = *(u16 *)(obj + 0xFC);
                cb.in.c = *(struct Vec3 *)(obj + 0xD4);
                cb.in.f = (u16)(ang + ((*(Part **)(obj + 0x24))[b].rotation << 11));
                arg((u8)(*(Part **)(obj + 0x24))[b].kind, &cb.in, *(Big **)(obj + 0xF8));
                if ((*(Part **)(obj + 0x24))[b].kind == 5) {
                    VEC_Set((struct Vec3 *)(obj + 0x100), cb.in.b.x, cb.in.b.y, 0);
                }
            }
        }
        REG(0x04000448) = 1;
    }
    REG(0x04000448) = 1;
}

static inline void G3_TexPlttBase(u32 addr, int fmt)
{
    u32 param = (u32)(addr >> (4 - (fmt == 2)));
    *(volatile u32 *)0x040004AC = param;
}

static inline u32 pk(int v)
{
    return (u16)((v << 8) >> 16);
}

static inline void G3_TexCoord(u32 s, u32 t)
{
    *(volatile u32 *)0x04000488 = s | (t << 16);
}

static inline void G3_Vtx(u32 xy, u32 z)
{
    *(volatile u32 *)0x0400048C = xy;
    *(volatile u32 *)0x0400048C = z;
}

/*
 * 2026-10-05 wD5 lane16: EXACT. The record access is written in full at each use
 *   (`(*(struct McssSpriteSet **)(p + 0x6C))->tbl[*pa].ents[a9].x` and `.z`), not through e1/e2 pointer locals.
 *   The CSE of the two full expressions colours pa in r2, so its load can move above the 0x4AC store.
 */
void MUSICAL_MCSS_DrawSprite(char *p, int offsetX, int offsetY, int width, int height, int texU, int texV, Pose *s, u16 *pa, int entIndex, int flag, int *pz, u8 mode)
{
    u16 ang;
    int x;
    int y;
    u32 s0;
    u32 s1;
    u32 t0;
    u32 t1;

    if (flag != 0) {
        G3i_OrthoW_(0x60000, 0xFFFA1000, 0xFFF81000, 0x80000, 0x1000, 0x3E8000, 0x1000, 1, 0);
        *(volatile u32 *)0x04000440 = 2;
    }
    *(volatile u32 *)0x04000450 = 0x1D;
    G3_TexPlttBase(*(u32 *)(p + 0xBC), *(int *)(p + 0xB4));
    *(volatile u32 *)0x040004A4 = 0x001F00C0;
    x = (s->dx + (*(struct McssSpriteSet **)(p + 0x6C))->tbl[*pa].ents[entIndex].x) << 8;
    y = -((*(struct McssSpriteSet **)(p + 0x6C))->tbl[*pa].ents[entIndex].z + s->dz) << 8;
    if (mode == 0) {
        ang = *(u16 *)(p + 0xFC);
    } else if ((mode & 1) != 0) {
        ang = (u16)(0x10000 - *(u16 *)(p + 0xFC));
    }
    G3_RotZ(-FX_SinCosTable_[(ang >> 4) * 2], FX_SinCosTable_[(ang >> 4) * 2 + 1]);
    G3_Translate(x, y, *pz);
    G3_RotZ(-FX_SinCosTable_[(*(u16 *)((char *)s + 2) >> 4) * 2], FX_SinCosTable_[(*(u16 *)((char *)s + 2) >> 4) * 2 + 1]);
    if (mode == 0) {
        G3_Scale(s->sx, s->sy, 0x1000);
        G3_Translate(offsetX, offsetY, 0);
        G3_Scale(width, height, 0x1000);
    } else if ((mode & 1) != 0) {
        G3_Scale(-s->sx, s->sy, 0x1000);
        G3_Translate(-offsetX, offsetY, 0);
        G3_Scale(width, height, 0x1000);
        G3_Translate(-0x100, 0, 0);
        texU = 0x200000 - texU - width;
    }
    *(volatile u32 *)0x04000500 = 1;
    t0 = pk(texV) << 16;
    s0 = pk(texU);
    *(volatile u32 *)0x04000488 = s0 | t0;
    G3_Vtx(0, 0);
    s1 = pk(texU + width);
    *(volatile u32 *)0x04000488 = s1 | t0;
    G3_Vtx(0x100, 0);
    t1 = pk(texV + height) << 16;
    *(volatile u32 *)0x04000488 = s1 | t1;
    G3_Vtx(0xFF000100, 0);
    *(volatile u32 *)0x04000488 = s0 | t1;
    G3_Vtx(0xFF000000, 0);
    *(volatile u32 *)0x04000504 = 0;
    *(volatile u32 *)0x04000440 = 0;
    *(volatile u32 *)0x04000450 = 0;
    *(volatile u32 *)0x04000440 = 2;
    if (flag == 0) {
        *pz = *pz - 0x100;
    } else {
        *pz = *pz - 0x400;
    }
}

char *MUSICAL_MCSS_LoadMC(char *a,u32 b,u32 c,u32 d,u32 e,u32 f,u32 g)
{
    int i;
    for(i=0;i<((McssRenderPool *)a)->count;i++) {
        if(SLOT==0) {
            SLOT=GFL_HEAP_Alloc((u16)((McssRenderPool *)a)->heap,292,1,d_021F83D4,763);
            *(u32 *)(SLOT+240)=i;
            *(u32 *)(SLOT+244)=((McssRenderPool *)a)->heap;
            *(u32 *)(SLOT+200)=b;
            *(u32 *)(SLOT+204)=c;
            *(u32 *)(SLOT+208)=d;
            *(u16 *)(SLOT+252)=0;
            *(u32 *)(SLOT+212)=4096;
            *(u32 *)(SLOT+216)=4096;
            *(u32 *)(SLOT+220)=4096;
            *(u32 *)(SLOT+248)=f;
            MUSICAL_MCSS_LoadCellBank((u8 *)a,i,(u32 *)e,g);
            break;
        }
    }
    return SLOT;
}

void MUSICAL_MCSS_FreeMC(char *a, char *mcAnim)
{
    GFL_HEAP_Free(((McssMcAnim *)mcAnim)->cellBank);
    GFL_HEAP_Free(((McssMcAnim *)mcAnim)->multiCellBank);
    GFL_HEAP_Free(((McssMcAnim *)mcAnim)->animBank);
    GFL_HEAP_Free(((McssMcAnim *)mcAnim)->multiAnimBank);
    GFL_HEAP_Free(((McssMcAnim *)mcAnim)->workArea);
    GFL_HEAP_Free(((McssMcAnim *)mcAnim)->cellTable);
    (*(u32 **)(a+4))[((McssMcAnim *)mcAnim)->childIndex] = 0;
    GFL_HEAP_Free(mcAnim);
}

void MUSICAL_MCSS_SetCameraBack(void *renderPool)
{
    unsigned int v = ((McssRenderPool *)renderPool)->flags;
    ((McssRenderPool *)renderPool)->flags = (v & ~1u) | 1u;
}

/*
 * note: blocker leaf of MUSICAL_MCSS_SetRenderCellVramBase; following 021F6230 is already matched.
 */
void MUSICAL_MCSS_SetCellVramBase(char *renderPool,int b) { ((McssRenderPool *)renderPool)->cellVram=b; }

void MUSICAL_MCSS_SetAnimVramBase(u8 *renderPool, int a)
{
    ((McssRenderPool *)renderPool)->animVram = a;
}

void MUSICAL_MCSS_SetMCAnimPos(char *mcAnim, int *q)
{
    ((McssMcAnim *)mcAnim)->posX = q[0];
    ((McssMcAnim *)mcAnim)->posY = q[1];
    ((McssMcAnim *)mcAnim)->posZ = q[2];
}

void MUSICAL_MCSS_SetMCAnimScale(char *mcAnim, int *q)
{
    ((McssMcAnim *)mcAnim)->scaleX = q[0];
    ((McssMcAnim *)mcAnim)->scaleY = q[1];
    ((McssMcAnim *)mcAnim)->scaleZ = q[2];
}

void MUSICAL_MCSS_SetMCAnimFrame(char *mcAnim, unsigned short v)
{
    ((McssMcAnim *)mcAnim)->frame = v;
}

void MUSICAL_MCSS_EnableDrawOffset(u8 *p) { ((Flags *)(p+236))->a=1; }

void MUSICAL_MCSS_DisableDrawOffset(u8 *p) { ((Flags *)(p+236))->a=0; }

void MUSICAL_MCSS_PauseMCAnim(u8 *p) { ((Flags *)(p+236))->b=1; }

void MUSICAL_MCSS_ResumeMCAnim(char *mcAnim) {((McssMcAnim *)mcAnim)->flags&=~2u;}

void MUSICAL_MCSS_SetMCAnim(char *mcAnim,u32 n) {void *a; a=NNS_G2dGetAnimSequenceByIdx(((McssMcAnim *)mcAnim)->animSequenceBank,n);MUSICAL_MCSS_InitMCAnim(mcAnim,1);NNS_G2dSetAnimSequenceToMCAnimation(mcAnim+40,a);}

u32 MUSICAL_MCSS_IsMCAnimHidden(u8 *mcAnim) { return (((McssMcAnim *)mcAnim)->flags << 29) >> 31; }

void MUSICAL_MCSS_HideMCAnim(char *mcAnim) {((McssMcAnim *)mcAnim)->flags|=4u;}

void MUSICAL_MCSS_ShowMCAnim(char *mcAnim) {((McssMcAnim *)mcAnim)->flags&=~4u;}

void MUSICAL_MCSS_CopyField(Object *a,Object *b)
{
    b->a=a->a; b->b=a->b; b->c=a->c;
    b->b0=a->b0; b->b1=a->b1; b->b2=a->b2;
    b->h=a->h; b->d=a->d; b->e=a->e;
}

/*
 * lever: an unqualified resource pointer keeps constant r2 setup before resource loads.
 * prototype: 6469C receives the sequence in r1 despite its one-argument matched definition.
 * prototype: 48F60/49F34/30734 heap inputs are narrowed immediately before each original call.
 */
void MUSICAL_MCSS_LoadCellBank(u8 *renderPool,int index,u32 *res,u32 mode)
{
    u8 *q=(*(u8 ***)(renderPool+4))[index];
    void **job;
    struct AnimSequence *sequence;
    u8 *table;
    ((McssMcAnim *)q)->flags |= 4;
    NNSi_G2dInitVramHandle((u32 *)(q+144));
    NNSi_G2dInitVramHandleEx((u32 *)(q+180));
    ((McssMcAnim *)q)->cellBank=ARC_UTIL_LoadCellBankFromArchive(res[0],res[3],0,(u32)(q+4),((McssMcAnim *)q)->heapTag);
    ((McssMcAnim *)q)->multiCellBank=ARC_UTIL_LoadMultiCellBankFromArchive(res[0],res[4],1,(u32)(q+20),((McssMcAnim *)q)->heapTag);
    ((McssMcAnim *)q)->animBank=ARC_UTIL_LoadAnimBankFromArchive(res[0],res[5],0,(u32)(q+12),((McssMcAnim *)q)->heapTag);
    ((McssMcAnim *)q)->multiAnimBank=ARC_UTIL_LoadMultiAnimBankFromArchive(res[0],res[6],0,(u32)(q+28),((McssMcAnim *)q)->heapTag);
    sequence=NNS_G2dGetAnimSequenceByIdx(*(struct AnimBank * *)&((McssMcAnim *)q)->animSequenceBank,0);
    MUSICAL_MCSS_InitMCAnim((char *)q,1);
    NNS_G2dSetAnimSequenceToMCAnimation(q+40,sequence);
    table=ARC_TOOL_LoadMember(res[0],res[7],(u16)(((McssMcAnim *)q)->heapTag));
    *(u8 * *)&((McssMcAnim *)q)->cellTable=table;
    *(u8 * *)&((McssMcAnim *)q)->partTable=table+4+56* ((McssMultiCellBank *)table)->count;
    job=GFL_HEAP_Alloc((u16)((McssMcAnim *)q)->heapTag,36,1,d_021F83D4,1104);
    job[2]=q+144;
    job[3]=q+180;
    job[6]=*(u8 * *)&((McssRenderPool *)renderPool)->cellVram+index*16384;
    job[7]=*(u8 * *)&((McssRenderPool *)renderPool)->animVram+index*32;
    job[8]=q;
    job[4]=ARC_UTIL_LoadBgCharDataFromArchive(res[0],res[1],1,(u32)job,((McssMcAnim *)q)->heapTag);
    job[5]=ARC_UTIL_LoadPaletteBlockFromArchive(res[0],res[2],(u32)(job+1),(u16)(((McssMcAnim *)q)->heapTag));
    if(res[7]==6548) MCSS_TOOL_DrawSpindaSpots(*(u8 * *)&((McssSpindaRes *)((u8 *)job[0]))->spots,res[8]);
    if(mode==1) GFL_USE_AddMainTask((u32)MUSICAL_MCSS_FreeCellBank,(u32)job,0);
    else MUSICAL_MCSS_FreeCellBank(0,job);
}

/*
 * extent: Two zero padding bytes follow the compiled body.
 */
void MUSICAL_MCSS_FreeCellBank(void *a, void **p)
{
    if(p[8]) ((McssMcAnim *)((char *)p[8]))->flags &= ~4u;
    if(p[4]) { NNSi_G2dLoadVramResourceSub(p[0],(u32)p[6],0,p[2]); GFL_HEAP_Free(p[4]); }
    if(p[1]) { NNSi_G2dLoadVramResourceBySel(p[1],p[7],0,p[3]); GFL_HEAP_Free(p[5]); }
    GFL_HEAP_Free(p);
    if(a) TCB_DeleteTask(a);
}

void MUSICAL_MCSS_InitMCAnim(char *mcAnim, int kind)
{
    ((McssMcAnim *)mcAnim)->workArea=GFL_HEAP_Alloc((u16)((McssMcAnim *)mcAnim)->heapTag,NNS_G2dGetMCWorkAreaSize(*(u32 *)&((McssMcAnim *)mcAnim)->cellArg,kind),0,d_021F83D4,1216);
    NNS_G2dInitMCAnimation(mcAnim+40,*(char * *)&((McssMcAnim *)mcAnim)->workArea,((McssMcAnim *)mcAnim)->cellAnimBankData,((McssMcAnim *)mcAnim)->cellBankArg,((McssMcAnim *)mcAnim)->cellArg,kind);
}

/*
 * volatile: Hardware register stores at listing 021F65F0,021F65F4,021F65FA.
 */
void MUSICAL_MCSS_SetupG3(void) {*(volatile u32 *)0x040004c0=0x4210ffff;*(volatile u32 *)0x040004c4=0x4210;*(volatile u32 *)0x040004a4=0x001f00c0;}

/*
 * extent: 310-byte code; 021F6742 is two zero alignment bytes.
 * lever: a named unsigned 64-bit sum pins carry accumulation before translation.
 * semantics: signed 32-bit products fit s64; u64 additions wrap like ADDS/ADCS.
 */
void MUSICAL_MCSS_CalcMatrix(const int *p, const int *m, u32 *out, u32 *w)
{
    s64 y = p[1];
    s64 x = p[0];
    s64 z = p[2];
    u64 sum;
    sum = (u64)(x * m[0]) + (u64)(y * m[4]) + (u64)(z * m[8]);
    out[0] = (u32)(sum >> 12) + (u32)m[12];
    sum = (u64)(x * m[1]) + (u64)(y * m[5]) + (u64)(z * m[9]);
    out[1] = (u32)(sum >> 12) + (u32)m[13];
    sum = (u64)(x * m[2]) + (u64)(y * m[6]) + (u64)(z * m[10]);
    out[2] = (u32)(sum >> 12) + (u32)m[14];
    sum = (u64)(x * m[3]) + (u64)(y * m[7]) + (u64)(z * m[11]);
    *w = (u32)(sum >> 12) + (u32)m[15];
}

/*
 * note: Two-byte zero alignment padding follows the compiled body.
 */
int MUSICAL_MCSS_GetMonValue(void *p) {int r; r=0;if(POKE_TOOL_GetPartyValue(p,170,0)!=1)r=1;return r;}
