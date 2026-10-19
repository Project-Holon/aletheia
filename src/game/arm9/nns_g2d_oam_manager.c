/*
 * file:     nns_g2d_oam_manager.c
 * unit:     yes
 * function: NNSi_G2dCpuLoadOamSub, NNSi_G2dCpuLoadOamMain, NNS_G2dInitOamManagerModule, NNSi_G2dReserveOamManagerSpan, NNSi_G2dEntryOamManagerOam, NNS_G2dEntryOamManagerAffine, NNS_G2dApplyOamManagerToHW, NNS_G2dResetOamManagerBuffer, NNSi_G2dGetVramHandle, NNSi_G2dInitVramHandle, NNSi_G2dSetVramHandle, NNSi_G2dGetVramHandleValue, NNSi_G2dIsVramHandleSet, NNSi_G2dInitVramHandleEx, NNSi_G2dSetVramHandleEx, NNSi_G2dGetVramHandleEx, NNSi_G2dIsVramHandleSetEx, NNSi_G2dLoadVramResourceMain, NNSi_G2dLoadVramResourceSub, NNSi_G2dSetupVramResource, NNSi_G2dLoadVramResourceBySel, NNSi_G2dLoadVramResourceList
 * address:  0x02063054
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MIi_CpuCopy16  0x02082A60  arm
 *   MIi_CpuClear16  0x02082A48  arm
 *   g_02146BC8      0x02146BC8  data
 *   g_02146BC4      0x02146BC4  data  a2
 *   g_020A81E4     0x020A81E4  data  a4
 *   DC_FlushRange  0x020862F0  arm
 *   GX_LoadOAM  0x0207E684  arm
 *   GXS_LoadOAM  0x0207E708  arm
 *   GXi_DmaId     0x020A84C0  data  a4
 *   DC_InvalidateRange  0x020862B8  arm
 *   MIi_DmaFill32  0x020821C0  arm
 *   MIi_CpuClear32  0x02082A7C  arm
 *   DC_FlushRange   0x020862F0  arm
 *   GX_BeginLoadTex 0x0207F7A0  arm
 *   GX_LoadTex      0x0207F7FC  arm
 *   GX_EndLoadTex   0x0207F9B4  arm
 *   GX_LoadOBJ      0x0207E780  arm
 *   GXS_LoadOBJ     0x0207E804  arm
 *   GX_BeginLoadOBJExtPltt  0x0207F47C  arm
 *   GX_LoadOBJExtPltt  0x0207F4C4  arm
 *   GX_EndLoadOBJExtPltt  0x0207F560  arm
 *   GX_LoadOBJPltt  0x0207E51C  arm
 *   GXS_BeginLoadOBJExtPltt  0x0207F6A8  arm
 *   GXS_LoadOBJExtPltt  0x0207F6C0  arm
 *   GXS_EndLoadOBJExtPltt  0x0207F754  arm
 *   GXS_LoadOBJPltt  0x0207E5D0  arm
 *   GX_BeginLoadTexPltt  0x0207FA0C  arm
 *   GX_LoadTexPltt  0x0207FA40  arm
 *   GX_EndLoadTexPltt  0x0207FADC  arm
 */
typedef unsigned int u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short s16;

typedef int s32;

typedef s32 fx32;

typedef union {
    struct { u16 attr0; u16 attr1; u16 attr2; u16 attr3; };
    struct { u32 attr01; u32 attr23; };
    struct {
        u32 y:8; u32 rsMode:2; u32 objMode:2; u32 mosaic:1; u32 colorMode:1; u32 shape:2;
        u32 x:9; u32 rsParam:5; u32 size:2;
        u32 charNo:10; u32 priority:2; u32 cParam:4; u32 _3:16;
    };
} GXOamAttr;

typedef struct OamAttributeCache {
    u16 reservationTable[128];
    GXOamAttr oamBuffer[128];
} OamAttributeCache;

typedef struct OamAffineCache {
    u16 reservationTable[32];
} OamAffineCache;

typedef struct OamCache {
    OamAttributeCache attributeCache;
    OamAffineCache affineCache;
} OamCache;

struct Span {
    u32 which;
    u16 first;
    u16 last;
    u16 cur;
    u16 afirst;
    u16 alast;
    u16 acur;
    u16 id;
    u16 pad_12;
    u32 live;
};

struct OamWindow { u32 bank; u16 min_oam; u16 max_oam; u16 cur_oam; };

typedef int BOOL;

typedef struct { fx32 _00, _01, _10, _11; } MtxFx22;

typedef struct {
    u16 _0, _1, _2; s16 PA;
    u16 _4, _5, _6; s16 PB;
    u16 _8, _9, _10; s16 PC;
    u16 _12, _13, _14; s16 PD;
} GXOamAffine;

typedef enum { NNS_G2D_OAMTYPE_MAIN = 0, NNS_G2D_OAMTYPE_SUB = 1, NNS_G2D_OAMTYPE_SOFTWAREEMULATION = 2 } NNSG2dOamType;

typedef struct NNSG2dOAMManageArea {
    u16 fromIdx;
    u16 toIdx;
    u16 currentIdx;
} NNSG2dOAMManageArea;

typedef struct NNSG2dOamManagerInstance {
    NNSG2dOamType type;
    NNSG2dOAMManageArea managedAttrArea;
    NNSG2dOAMManageArea managedAffineArea;
    u16 GUID;
    u16 pad16_;
    BOOL bFastTransferEnable;
    fx32 spriteZoffsetStep;
} NNSG2dOamManagerInstance;

typedef void (OBJLoadFunction)(const void *pSrc, u32 offset, u32 szByte);

struct VramResource {
    u16  width;   /* +0x00 pixel width */
    u16  height;  /* +0x02 pixel height */
    int  offset;  /* +0x04 destination offset */
    u32  bank;    /* +0x08 2D/3D VRAM control word, 0 selects the size-code path */
    int  pad_fc;  /* +0x0c never read */
    u32  size;    /* +0x10 source size in bytes */
    void *src;    /* +0x14 source pointer */
};

struct VramHandle {
    int vramAddrMode0;  /* +0x00 destination for mode 0, written by NNSi_G2dSetVramHandle */
    int vramAddrMode1;  /* +0x04 mode 1 */
    int vramAddrMode2;  /* +0x08 mode 2 */
    int heightCode;     /* +0x0c GX size code of the resource height */
    int widthCode;      /* +0x10 GX size code of the resource width */
    int offset;         /* +0x14 */
    int reserved18;     /* +0x18 written 0, never read */
    int isSet;          /* +0x1c written 1, never read */
    u32 bank;           /* +0x20 */
};

typedef struct VramResourceSel {
    u32 formatCode;  /* +0x00 format code copied to the handle */
    u32 handle;      /* +0x04 non-zero selects the func_0207F* upload path */
    u32 size;        /* +0x08 source size in bytes */
    u32 src;         /* +0x0c source pointer */
} VramResourceSel;

typedef struct VramHandleSel {
    u32 formatCode;  /* +0x00 */
    u32 handle;      /* +0x04 */
} VramHandleSel;

typedef struct VramResourceList {
    u32 formatCode;  /* +0x00 format code, 3 selects the 0x20 element step */
    u32 handle;      /* +0x04 non-zero selects the func_0207F* upload path */
    u32 size;        /* +0x08 source size in bytes */
    u32 src;         /* +0x0c source base pointer */
} VramResourceList;

typedef struct VramHandleList {
    u32 formatCode;  /* +0x00 */
    u32 handle;      /* +0x04 */
} VramHandleList;

typedef struct VramResourceIndices {
    u16  count;
    u16 *items;
} VramResourceIndices;

extern void MIi_CpuCopy16(void *src, u32 dest);
extern void MIi_CpuClear16(u16 data, void *dest, u32 size);
extern void DC_FlushRange(const void *startAddr, u32 nBytes);         /* DC_FlushRange */
extern void GX_LoadOAM(const void *pSrc, u32 offset, u32 szByte);  /* GX_LoadOAM */
extern void GXS_LoadOAM(const void *pSrc, u32 offset, u32 szByte);  /* GXS_LoadOAM */
extern void DC_InvalidateRange(const void *startAddr, u32 nBytes);          /* DC_InvalidateRange */
extern void MIi_DmaFill32(u32 dmaNo, void *dest, u32 data, u32 size, BOOL flag);  /* MIi_DmaFill32 */
extern void MIi_CpuClear32(u32 data, void *dest, u32 size);            /* MIi_CpuClear32 */
extern void GX_BeginLoadTex(void);
extern void GX_LoadTex(void *src, u32 off, u32 n);
extern void GX_EndLoadTex(void);
extern void GX_LoadOBJ(void *src, u32 off, u32 n);
extern void GXS_LoadOBJ(void *src, u32 off, u32 n);
extern void GX_BeginLoadOBJExtPltt(u32 a);
extern void GX_LoadOBJExtPltt(u32 a, u32 b, u32 c);
extern void GX_EndLoadOBJExtPltt(void);
extern void GX_LoadOBJPltt(u32 a, u32 b, u32 c);
extern void GXS_BeginLoadOBJExtPltt(u32 a);
extern void GXS_LoadOBJExtPltt(u32 a, u32 b, u32 c);
extern void GXS_EndLoadOBJExtPltt(void);
extern void GXS_LoadOBJPltt(u32 a, u32 b, u32 c);
extern void GX_BeginLoadTexPltt(void);
extern void GX_LoadTexPltt(u32 a, u32 b, u32 c);
extern void GX_EndLoadTexPltt(void);
void NNSi_G2dCpuLoadOamSub(void *src, u32 offset);
void NNSi_G2dCpuLoadOamMain(void *src, u32 offset);
void NNS_G2dInitOamManagerModule(void);
u32 NNSi_G2dReserveOamManagerSpan(struct Span *s, u16 first, u16 count, u32 which);
u32 NNSi_G2dEntryOamManagerOam(struct OamWindow *win, GXOamAttr *src, u32 mode);
u16 NNS_G2dEntryOamManagerAffine(NNSG2dOamManagerInstance *pMan, const MtxFx22 *mtx);
void NNS_G2dApplyOamManagerToHW(NNSG2dOamManagerInstance *pMan, u32 bound);
void NNS_G2dResetOamManagerBuffer(NNSG2dOamManagerInstance *pMan);
int NNSi_G2dGetVramHandle(unsigned short *p, int i);
void NNSi_G2dInitVramHandle(u32 *p);
void NNSi_G2dSetVramHandle(int *p, int i, int v);
int NNSi_G2dGetVramHandleValue(int *p, int i);
int NNSi_G2dIsVramHandleSet(const u32 *p, u32 i);
void NNSi_G2dInitVramHandleEx(u32 *p);
void NNSi_G2dSetVramHandleEx(char *p, int i, int v);
int NNSi_G2dGetVramHandleEx(char *p, int i);
int NNSi_G2dIsVramHandleSetEx(char *p, int i);
void NNSi_G2dLoadVramResourceMain(struct VramResource *r, u32 dst, int mode, struct VramHandle *out);
void NNSi_G2dLoadVramResourceSub(struct VramResource *r, u32 dst, int mode, struct VramHandle *out);
void NNSi_G2dSetupVramResource(struct VramResource *r, u32 dst, int mode, struct VramHandle *out);
void NNSi_G2dLoadVramResourceBySel(VramResourceSel *self, u32 offset, int sel, VramHandleSel *out);
void NNSi_G2dLoadVramResourceList(VramResourceList *self, VramResourceIndices *list, u32 base, int sel, VramHandleList *out);
extern OamCache g_02146BC8[3];
extern u16 g_02146BC4;
extern OBJLoadFunction *g_020A81E4[5];  /* GetOBJLoadFunction_'s funcTbl */
extern u32 GXi_DmaId;                  /* GXi_DmaId */



/*
 * The sub-engine twin of src/matched/NNSi_G2dCpuLoadOamMain.c, biasing the caller's byte
 * offset by 0x07000400 instead of 0x07000000 and tail-calling the transfer
 * routine at 0x02082A60.
 *
 * -proc evidence, measured 2026-09-19 by wave r8 lane small-3 (the packet's
 * proc_hints line reads arm946e, but this row's bytes say otherwise): at
 * -proc arm946e the two-instruction bias is scheduled as
 *   +0000 add r1, r1, #0x400
 *   +0004 ldr ip, [pc, #4]
 *   +0008 add r1, r1, #0x7000000
 *   +000C bx ip
 * i.e. mwcc hoists the first `add` above the load of the tail-call target,
 * while the image loads the target first and then emits both adds
 * (+0000 ldr ip, [pc, #8]; +0004 add; +0008 add; +000C bx ip).  Every spelling
 * of the sum tried under arm946e (single expression, reversed add order, named
 * local, `|`, pointer-typed second parameter) hoists the add; under
 * `-proc arm7tdmi` the same C reproduces the image's four instructions with
 * zero concrete mismatches.  dsi/../1.2/sp2 is worse (it materialises the bias
 * in r2 and needs 24 bytes).  The trailing `*` is the unlabelled follower at
 * 0x02063068 (already matched as src/matched/NNSi_G2dCpuLoadOamMain.c): disasm.py gives
 * a prologue-less leaf no label, so the listing extent runs from 0x02063054 to
 * 0x02063078.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_G2dCpuLoadOamSub.c \
 *       --func NNSi_G2dCpuLoadOamSub --addr 0x02063054 --arm \
 *       --flags "-O4,p -proc arm7tdmi"
 */
void NNSi_G2dCpuLoadOamSub(void *src, u32 offset)
{
    MIi_CpuCopy16(src, offset + 0x400 + 0x7000000);
}



/*
 * An OAM-address thunk: bias the caller's byte offset into an absolute
 * main-engine OAM address and tail-call the transfer routine at
 * 0x02082A60.  A tail call is a pool word and a `bx`, never a displacement
 * branch (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 *
 * It saves nothing, so disasm.py gives it no label and it prints as a run
 * of `.word`s (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md);
 * the attesting instruction is the vtable word at 0x020A81E4, which holds
 * this address.  Seeding 0x02063068 into layout/function_starts.txt is what
 * makes the listing agree; the byte comparison is EXACT either way.
 *
 * Its sub-engine twin at 0x02063054 (vtable word 0x020A81E8, biasing by
 * 0x07000400 instead) is byte-correct but two instructions out of order:
 * 0x07000400 is not an ARM rotated immediate, so it comes out as two
 * `add`s, and every spelling tried emits the first `add` before the `ldr`
 * of the tail-call target where the original loads the target first.  The
 * one-`add` form here has no such freedom and matches exactly.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_G2dCpuLoadOamMain.c \
 *       --func NNSi_G2dCpuLoadOamMain --addr 0x02063068 --cc 1.1p1 --arm
 */
void NNSi_G2dCpuLoadOamMain(void *src, u32 offset)
{
    MIi_CpuCopy16(src, offset + 0x07000000);
}







/*
 * The cell/OAM bank reset: nine MIi_CpuClear16 calls that blank all three
 * 0x540-byte bank records of g_02146BC8 -- the OAM mirror at +0x100 (0x400
 * bytes, fill 0xC0) and the two free-slot tables, slotsA at +0x000 (0x100
 * bytes) and slotsB at +0x500 (0x40 bytes), both filled with the 0xFFFF
 * free sentinel that NNSi_G2dReserveOamManagerSpan tests for.
 *
 * COMPILER PIN, ../2.0/sp2, the cluster's "kept constants" tell.  The image
 * rematerialises each call's fill value and size into r0/r2 at every one of
 * the nine sites (`mov r0,#0xc0` at 0x02063080/0x02063090/0x020630A0, then
 * `ldr r0,[pc,#0x68]` naming the same 0xFFFF pool word at 0x0206311C six
 * times over, and `mov r2,#0x40` at 0x020630E4/0x020630F4/0x02063104) and
 * spends no callee-saved register at all: `push {r3, lr}` / `pop {r3, pc}`.
 * dsi/1.1p1 -O4,p CSEs 0xFFFF into r5 and 0x40 into r4 and holds both live
 * across the call chain, widening the prologue to `push {r3, r4, r5, lr}`
 * and replacing each rematerialisation with `mov r0,r5` / `mov r2,r4`:
 * same 192 bytes, 30 concrete out.  Under the pin this identical C is 0
 * mismatches on the first compile.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/NNS_G2dInitOamManagerModule.c \
 *       --func NNS_G2dInitOamManagerModule --addr 0x02063078 --cc ../2.0/sp2 --arm
 */
void NNS_G2dInitOamManagerModule(void)
{
    MIi_CpuClear16(0xC0, g_02146BC8[0].attributeCache.oamBuffer, 0x400);
    MIi_CpuClear16(0xC0, g_02146BC8[1].attributeCache.oamBuffer, 0x400);
    MIi_CpuClear16(0xC0, g_02146BC8[2].attributeCache.oamBuffer, 0x400);
    MIi_CpuClear16(0xFFFF, g_02146BC8[0].attributeCache.reservationTable, 0x100);
    MIi_CpuClear16(0xFFFF, g_02146BC8[1].attributeCache.reservationTable, 0x100);
    MIi_CpuClear16(0xFFFF, g_02146BC8[2].attributeCache.reservationTable, 0x100);
    MIi_CpuClear16(0xFFFF, g_02146BC8[0].affineCache.reservationTable, 0x40);
    MIi_CpuClear16(0xFFFF, g_02146BC8[1].affineCache.reservationTable, 0x40);
    MIi_CpuClear16(0xFFFF, g_02146BC8[2].affineCache.reservationTable, 0x40);
}







static inline void Fill(u16 *tbl, u16 first, u16 last, u16 id)
{
    MIi_CpuClear16(id, (u8 *)tbl + first * 2, (last - first + 1) * 2);
}







static inline u32 IsFree(u16 *tbl, u16 first, u16 last)
{
    u16 *p = &tbl[first];
    u16 *end = &tbl[last];
    for (; p <= end; p++) {
        if (*p != 0xFFFF)
            return 0;
    }
    return 1;
}







/*
 * Reserves a span of OAM entries in bank g_02146BC8[which]: checks that
 * slotsA[first..last] are all free (0xFFFF), stamps them with the next
 * allocation id out of g_02146BC4, then does the same on the coarse
 * slotsB table at 1/4 granularity, fills the span record *s and returns 1
 * (0 as soon as either range is taken).
 *
 * WHAT CLOSED IT (wave 10), from 165 bytes out: the body is two inline
 * helpers used twice each, IsFree(tbl, first, last) (a pointer walk from
 * &tbl[first] to &tbl[last]) and Fill(tbl, first, last, id) (the
 * MIi_CpuClear16 call), with each check written `if (IsFree(..)) {...}
 * else return 0;` -- then-block first, which is what gives the image's two
 * branched-to `mov r0,#0; pop` failure tails.  Two register levers on top:
 *  - Fill's destination is spelled `(u8 *)tbl + first * 2`, a different
 *    expression from IsFree's `&tbl[first]`, so the image recomputes the
 *    address (`add r1, r4, r7, lsl #1`) instead of carrying a CSE copy
 *    across the loop;
 *  - the coarse table base is bound to a local (`coarse = bank->slotsB`),
 *    which becomes the image's in-place `add r4, r4, #0x500`.
 * ../2.0/sp2 as for the rest of the cluster.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/NNSi_G2dReserveOamManagerSpan.c
 *       --func NNSi_G2dReserveOamManagerSpan --addr 0x02063138 --arm --cc ../2.0/sp2
 */
u32 NNSi_G2dReserveOamManagerSpan(struct Span *s, u16 first, u16 count, u32 which)
{
    OamCache *bank = &g_02146BC8[which];
    u16 last = first + (count - 1);
    u16 afirst, alast;
    u16 *coarse;

    if (IsFree(bank->attributeCache.reservationTable, first, last)) {
        s->id = g_02146BC4++;
        s->first = first;
        s->last = last;
        s->cur = first;
        Fill(bank->attributeCache.reservationTable, first, last, s->id);
    } else {
        return 0;
    }

    afirst = first >> 2;
    alast = afirst + ((u16)(count >> 2) - 1);
    coarse = bank->affineCache.reservationTable;
    if (IsFree(coarse, afirst, alast)) {
        s->afirst = afirst;
        s->alast = alast;
        s->acur = afirst;
        Fill(coarse, afirst, alast, s->id);
    } else {
        return 0;
    }

    s->live = 1;
    s->which = which;
    return 1;
}






/*
 * Writes one OAM entry (attr0/attr1/attr2) into the next free slot of a
 * reserved span of bank g_02146BC8[win->bank]'s OAM shadow (+0x100), and,
 * when the entry is affine (rsMode bit 0) and mode != 0xFFFE, stamps the
 * affine parameter index into attr1 bits 9-13.  Returns 1, or 0 when the
 * span is full.
 *
 * WHAT CLOSED IT (wave 10), after 16 hand spellings at 13 bytes out:
 *  1. The permuter's split-assign(ptr): `ptr = g_02146BC8; ptr = ptr +
 *     win->bank * 0x540;` -- two statements on ONE variable -- coalesces the
 *     mla's addend with its destination (image `mla ip, r4, r3, ip`), which
 *     the one-expression spelling never does.  The "mla destination is not
 *     source-addressable" wall of cluster_02063000.h was a declarations
 *     question here.  (13 -> 7 bytes out.)
 *  2. The attribute read-modify-write is the SDK GXOamAttr bitfield union:
 *     `if (dst->rsMode & 1) dst->rsParam = mode;`.  The shift pair
 *     (<<22, >>30) is the 2-bit rsMode field at bits 8-9 and the 0x3E000000
 *     mask is the 5-bit rsParam at bits 25-29; the explicit shift/mask
 *     spelling puts the loaded word and the test in swapped registers.
 *     (7 -> 0.)
 * dsi/1.1p1 is 220 bytes (it predicates the count block): the ../2.0/sp2
 * "kept branches" pin, as for the rest of the cluster.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/NNSi_G2dEntryOamManagerOam.c
 *       --func NNSi_G2dEntryOamManagerOam --addr 0x02063294 --arm --cc ../2.0/sp2
 */
u32 NNSi_G2dEntryOamManagerOam(struct OamWindow *win, GXOamAttr *src, u32 mode)
{
    u16 max_oam = win->max_oam;
    u16 cur_oam = *(volatile u16 *)&win->cur_oam;
    u32 valid = 0;
    u32 count;
    u32 ge;
    u8 *ptr;
    u32 idx;
    if (!((int)cur_oam > (int)max_oam + 1)) {
        if (win->min_oam <= max_oam) valid = 1;
    }
    if (valid == 0) count = 0;
    else count = (u16)(max_oam - cur_oam + 1);
    if (count >= 1) ge = 1; else ge = 0;
    if (ge == 0) goto fail;
    ptr = (u8 *)g_02146BC8;
    ptr = ptr + win->bank * 0x540;
    idx = win->cur_oam;
    ptr = ptr + 0x100;
    {
        GXOamAttr *dst = (GXOamAttr *)(ptr + idx * 8);
        dst->attr0 = src->attr0;
        dst->attr1 = src->attr1;
        dst->attr2 = src->attr2;
        if (mode != 0xFFFE) {
            if (dst->rsMode & 1) {
                dst->rsParam = mode;
            }
        }
    }
    win->cur_oam = win->cur_oam + 1;
    return 1;
fail:
    return 0;
}





static inline BOOL IsManageAreaValid_(const NNSG2dOAMManageArea *pArea)
{
    return (BOOL)((pArea->currentIdx <= pArea->toIdx + 1) &&
                  (pArea->fromIdx <= pArea->toIdx));
}





static inline OamCache *GetOamCachePtr_(NNSG2dOamType type)
{
    return &g_02146BC8[type];
}





static inline GXOamAttr *GetOamBufferPtr_(NNSG2dOamType type, u16 index)
{
    {
        OamCache *pOamCache = GetOamCachePtr_(type);

        return pOamCache->attributeCache.oamBuffer + index;
    }
}





static inline GXOamAffine *GetAffineBufferPtr_(NNSG2dOamType type, u16 index)
{
    {
        GXOamAffine *pAff = (GXOamAffine *)GetOamBufferPtr_(type, 0);

        return pAff + index;
    }
}





static inline u16 GetCapacity_(const NNSG2dOAMManageArea *pArea)
{
    if (IsManageAreaValid_(pArea)) {
        return (u16)((int)pArea->toIdx - pArea->currentIdx + 1);
    } else {
        return 0;
    }
}





static inline BOOL HasEnoughCapacity_(const NNSG2dOAMManageArea *pArea, u16 num)
{
    return (BOOL)(GetCapacity_(pArea) >= num);
}





static inline void G2_SetOBJAffine(GXOamAffine *oam, const MtxFx22 *mtx)
{
    oam->PA = (s16)(mtx->_00 >> 4);
    oam->PB = (s16)(mtx->_01 >> 4);
    oam->PC = (s16)(mtx->_10 >> 4);
    oam->PD = (s16)(mtx->_11 >> 4);
}





static inline void SetAffineParams_(NNSG2dOamType type, const MtxFx22 *mtx, u16 idx)
{
    {
        GXOamAffine *pAff = GetAffineBufferPtr_(type, idx);

        G2_SetOBJAffine(pAff, mtx);
    }
}





/*
 * NitroSystem g2d_OAM.c NNS_G2dEntryOamManagerAffine(pMan, mtx) -> u16:
 * if the managed affine area has room for one more entry, write the 2x2
 * matrix (each term >> 4, the TwlSDK G2_SetOBJAffine inline) into the
 * GXOamAffine slot at managedAffineArea.currentIdx of oamCache_[pMan->type]
 * (g_02146BC8, three 0x540-byte OamCache records), bump currentIdx and
 * return the old index; otherwise NNS_G2D_OAM_AFFINE_IDX_NONE (0xFFFE).
 *
 * Closed in wave 13 on the first compile of the library body with its
 * inlines (IsManageAreaValid_, GetCapacity_, HasEnoughCapacity_,
 * GetOamCachePtr_, GetOamBufferPtr_, GetAffineBufferPtr_, SetAffineParams_,
 * G2_SetOBJAffine) and the NitroSDK GXOamAttr / GXOamAffine types.  The
 * "mla destination wall" earlier waves measured (22 spellings, the
 * permuter, 5 then 4 bytes) was the inline boundaries: the buffer address
 * comes out of GetAffineBufferPtr_(type, 0) + index, which is what keeps
 * base, destination and index in three registers.  ../2.0/sp2 and sp2p2
 * identical; 1.1p1 is 188 bytes.
 */
u16 NNS_G2dEntryOamManagerAffine(NNSG2dOamManagerInstance *pMan, const MtxFx22 *mtx)
{
    if (HasEnoughCapacity_(&pMan->managedAffineArea, 1)) {
        const u16 currentAffineIdx = pMan->managedAffineArea.currentIdx;

        SetAffineParams_(pMan->type, mtx, currentAffineIdx);

        pMan->managedAffineArea.currentIdx++;

        return currentAffineIdx;
    } else {
        return 0xFFFE;
    }
}




static inline OBJLoadFunction *GetOBJLoadFunction_(NNSG2dOamType type)
{
    return g_020A81E4[type];
}




static inline void LoadOneAffine_(const GXOamAffine *pAff, u32 offset, OBJLoadFunction *pOBJLoadFunc)
{
    offset += sizeof(u16) * 3;

    (*pOBJLoadFunc)(&pAff->PA, offset + sizeof(GXOamAttr) * 0, sizeof(u16));
    (*pOBJLoadFunc)(&pAff->PB, offset + sizeof(GXOamAttr) * 1, sizeof(u16));
    (*pOBJLoadFunc)(&pAff->PC, offset + sizeof(GXOamAttr) * 2, sizeof(u16));
    (*pOBJLoadFunc)(&pAff->PD, offset + sizeof(GXOamAttr) * 3, sizeof(u16));
}




static inline void LoadOamAndAffineFast_(NNSG2dOamType type, u16 fromIdx, u16 toIdx)
{
    GXOamAttr *pFrom = GetOamBufferPtr_(type, fromIdx);
    const u16 szByte = (u16)(sizeof(GXOamAttr) * (toIdx - fromIdx + 1));
    u16 offset = (u16)(sizeof(GXOamAttr) * fromIdx);

    DC_FlushRange(pFrom, szByte);

    switch (type) {
    case NNS_G2D_OAMTYPE_MAIN:
        GX_LoadOAM(pFrom, offset, szByte);
        break;
    case NNS_G2D_OAMTYPE_SUB:
        GXS_LoadOAM(pFrom, offset, szByte);
        break;
    default:
        break;
    }
}




static inline void LoadOam_(NNSG2dOamType type, u16 fromIdx, u16 toIdx)
{
    GXOamAttr *pFrom = GetOamBufferPtr_(type, fromIdx);
    const u16 numArea = (u16)(toIdx - fromIdx + 1);
    u16 offset = (u16)(sizeof(GXOamAttr) * fromIdx);
    u16 i;
    OBJLoadFunction *pOBJLoadFunc = GetOBJLoadFunction_(type);

    for (i = 0; i < numArea; i++) {
        (*pOBJLoadFunc)(pFrom, offset, sizeof(u16) * 3);

        offset += sizeof(GXOamAttr);
        pFrom++;
    }
}




static inline void LoadAffine_(NNSG2dOamType type, u16 fromIdx, u16 toIdx)
{
    GXOamAffine *pFrom = GetAffineBufferPtr_(type, fromIdx);
    const u16 numArea = (u16)(toIdx - fromIdx + 1);
    u16 offset = (u16)(sizeof(GXOamAffine) * fromIdx);
    u16 i;
    OBJLoadFunction *pOBJLoadFunc = GetOBJLoadFunction_(type);

    for (i = 0; i < numArea; i++) {
        LoadOneAffine_(pFrom, offset, pOBJLoadFunc);

        offset += sizeof(GXOamAffine);
        pFrom++;
    }
}




/*
 * NitroSystem g2d_OAM.c NNS_G2dApplyOamManagerToHW(pMan).  Fast-transfer
 * managers: LoadOamAndAffineFast_ (DC_FlushRange DC_FlushRange over the
 * span, then GX_LoadOAM GX_LoadOAM or GXS_LoadOAM GXS_LoadOAM by
 * type).  Otherwise LoadOam_ pushes each entry's three attribute halfwords
 * through the per-type loader, and when the affine area is valid
 * LoadAffine_ pushes PA..PD of each GXOamAffine (LoadOneAffine_) the same
 * way.  g_020A81E4 is GetOBJLoadFunction_'s static funcTbl
 * { CpuLoadOAMMain_ = NNSi_G2dCpuLoadOamMain, CpuLoadOAMSub_ = NNSi_G2dCpuLoadOamSub, 0, 0, 0 }.
 *
 * Closed in wave 13 on the first compile of the library body with its
 * inlines; the wave-10 transcription sat at 99 out on callee-saved
 * allocation, which was the inline boundaries.  ../2.0/sp2 and sp2p2
 * identical; 1.1p1 is 508 bytes.
 */
void NNS_G2dApplyOamManagerToHW(NNSG2dOamManagerInstance *pMan, u32 bound)
{
    {
        if (pMan->bFastTransferEnable) {
            LoadOamAndAffineFast_(pMan->type,
                                  pMan->managedAttrArea.fromIdx,
                                  pMan->managedAttrArea.toIdx);
        } else {
            LoadOam_(pMan->type,
                     pMan->managedAttrArea.fromIdx,
                     pMan->managedAttrArea.toIdx);

            if (IsManageAreaValid_(&pMan->managedAffineArea)) {
                LoadAffine_(pMan->type,
                            pMan->managedAffineArea.fromIdx,
                            pMan->managedAffineArea.toIdx);
            }
        }
    }
}



static inline u32 GX_GetDefaultDMA(void)
{
    return (GXi_DmaId > 3) ? (u32)~0 : GXi_DmaId;
}



static inline void MI_DmaFill32(u32 dmaNo, void *dest, u32 data, u32 size)
{
    MIi_DmaFill32(dmaNo, dest, data, size, 1);
}



static inline void MI_CpuFill32(void *dest, u32 data, u32 size)
{
    MIi_CpuClear32(data, dest, size);
}



static inline void NNSi_G2dDmaFill32(u32 dmaNo, void *dest, u32 data, u32 size)
{
    if (dmaNo != (u32)~0) {
        MI_DmaFill32(dmaNo, dest, data, size);
    } else {
        MI_CpuFill32(dest, data, size);
    }
}



static inline GXOamAttr *GetOamFromPtr_(NNSG2dOamManagerInstance *pMan)
{
    {
        GXOamAttr *pFrom = GetOamBufferPtr_(pMan->type, pMan->managedAttrArea.fromIdx);

        return pFrom;
    }
}



static inline u32 GetSizeOfManageArea_(const NNSG2dOAMManageArea *pArea)
{
    if (IsManageAreaValid_(pArea)) {
        return (u32)(sizeof(GXOamAttr) * (u16)(pArea->toIdx - pArea->fromIdx + 1));
    } else {
        return 0;
    }
}



static inline void ResetOam_(NNSG2dOamType type, u16 fromIdx, u16 toIdx)
{
    GXOamAttr *pFrom = GetOamBufferPtr_(type, fromIdx);
    const u16 numArea = (u16)(toIdx - fromIdx + 1);
    u16 i;

    for (i = 0; i < numArea; i++) {
        *((u16 *)pFrom) = 192;
        pFrom++;
    }
}



/*
 * NitroSystem g2d_OAM.c NNS_G2dResetOamManagerBuffer(pMan).  Fast-transfer
 * managers: DC_InvalidateRange (DC_InvalidateRange) over the managed OAM span,
 * then NNSi_G2dDmaFill32(NNS_G2D_DMA_NO, span, 0xC0, size) -- MIi_DmaFill32
 * (MIi_DmaFill32, five arguments, the fifth on the stack) on the default
 * DMA channel, MIi_CpuClear32 (MIi_CpuClear32) when GX_GetDefaultDMA()
 * reports GX_DMA_NOT_USE; otherwise ResetOam_ writes 0xC0 into attr0 of
 * each entry.  Both cursors are then rewound to fromIdx.
 *
 * GXi_DmaId is GXi_DmaId; this build's GX_GetDefaultDMA clamps it,
 * `id > 3 ? GX_DMA_NOT_USE : id` (the image's `cmp #3 / mvnhi`), so the
 * register-held -1 the wave-10 notes chased is the SDK's own sentinel.
 * Closed in wave 13 on the first compile of the library body and inlines
 * (GetSizeOfManageArea_, GetOamFromPtr_, GetOamBufferPtr_, ResetOam_,
 * NNSi_G2dDmaFill32, MI_DmaFill32, MI_CpuFill32): the "mla destination"
 * residue was the inline boundary.  ../2.0/sp2 and sp2p2 identical; 1.1p1
 * is 320 bytes.
 */
void NNS_G2dResetOamManagerBuffer(NNSG2dOamManagerInstance *pMan)
{
    {
        if (pMan->bFastTransferEnable) {
            const u32 szByte = GetSizeOfManageArea_(&pMan->managedAttrArea);
            void *pData = GetOamFromPtr_(pMan);

            DC_InvalidateRange(pData, szByte);
            NNSi_G2dDmaFill32(GX_GetDefaultDMA(), pData, 192, szByte);

        } else {
            ResetOam_(pMan->type,
                      pMan->managedAttrArea.fromIdx,
                      pMan->managedAttrArea.toIdx);
        }
    }

    {
        pMan->managedAttrArea.currentIdx = pMan->managedAttrArea.fromIdx;
        pMan->managedAffineArea.currentIdx = pMan->managedAffineArea.fromIdx;
    }
}






int NNSi_G2dGetVramHandle(unsigned short *p, int i){ return p[i]; }







void NNSi_G2dInitVramHandle(u32 *p)
{
    int i;

    for (i = 0; i < 3; i++) {
        p[i] = 0xffffffff;
    }
}






void NNSi_G2dSetVramHandle(int *p, int i, int v){ p[i] = v; }





int NNSi_G2dGetVramHandleValue(int *p, int i){ return p[i]; }





/*
 * Slot-occupied test of the NNSi_G2dIsVramHandleSetEx accessor family: the word at
 * p[i] is not the sentinel -1.  The register-held sentinel tell
 * (docs/FRONTEND-PINS.md): the image materialises `mvn r0, #0` at
 * 0x020637C0 and compares `cmp r1, r0` at 0x020637C4; every dsi 1.x front
 * end folds the constant to `cmn r0, #1` (20 bytes, 12 out, ten spellings
 * measured by earlier lanes).  Under ../2.0/sp2 (also sp2p2, 2.0 base and
 * ../1.2/sp4) the same C is 24 bytes, 0 mismatches.
 */
int NNSi_G2dIsVramHandleSet(const u32 *p, u32 i)
{
    return p[i] != 0xffffffff;
}






void NNSi_G2dInitVramHandleEx(u32 *p)
{
    int i;

    for (i = 0; i < 3; i++) {
        p[i + 2] = 0xffffffff;
    }
}





void NNSi_G2dSetVramHandleEx(char *p, int i, int v){ *(int *)(p + i * 4 + 8) = v; }




int NNSi_G2dGetVramHandleEx(char *p, int i){ return *(int *)(p + i * 4 + 8); }






/*
 * Neighbour of NNSi_G2dGetVramHandleEx (same accessor family): that one returns the
 * slot's raw word, this one reports whether the slot is occupied, i.e. not
 * the sentinel -1.
 */
int NNSi_G2dIsVramHandleSetEx(char *p, int i){ int v = *(int *)(p + i * 4 + 8); int s = -1; return v != s; }







/*
 * Upload one VRAM resource: optionally repoint the 2D/3D VRAM control word,
 * flush the source range, hand it to the matching GX loader (3D texture,
 * main OBJ, sub OBJ), then fill the caller's descriptor.  When f8 (the bank
 * control word) is zero the two halfword dimensions are translated from
 * pixel sizes (1,2,4,8,0x10,0x20) to GX size codes 0..5; otherwise they are
 * stored raw.
 *
 * 1.1p1 CSEs the shared zero into a callee-saved register (costing r8 and a
 * six-register frame) and cross-jumps the two VRAM-control arms, giving 532
 * bytes against the original's 556; under ../2.0/sp2 the same C is 556
 * bytes, 0 mismatches.  See docs/FRONTEND-PINS.md.
 */
void NNSi_G2dLoadVramResourceMain(struct VramResource *r, u32 dst, int mode, struct VramHandle *out)
{
    u32 bank = r->bank;

    switch (mode) {
    case 0:
        break;
    case 1:
        *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & 0xFFCFFFEF) | bank;
        break;
    case 2:
        *(volatile u32 *)0x04001000 = (*(volatile u32 *)0x04001000 & 0xFFCFFFEF) | bank;
        break;
    }
    DC_FlushRange(r->src, r->size);
    switch (mode) {
    case 0:
        GX_BeginLoadTex();
        GX_LoadTex(r->src, dst, r->size);
        GX_EndLoadTex();
        break;
    case 1:
        GX_LoadOBJ(r->src, dst, r->size);
        break;
    case 2:
        GXS_LoadOBJ(r->src, dst, r->size);
        break;
    }
    if (r->bank == 0) {
        int a, b;
        switch (r->height) {
        case 1:    a = 0; break;
        case 2:    a = 1; break;
        case 4:    a = 2; break;
        case 8:    a = 3; break;
        case 0x10: a = 4; break;
        case 0x20: a = 5; break;
        default:   a = 0; break;
        }
        out->heightCode = a;
        switch (r->width) {
        case 1:    b = 0; break;
        case 2:    b = 1; break;
        case 4:    b = 2; break;
        case 8:    b = 3; break;
        case 0x10: b = 4; break;
        case 0x20: b = 5; break;
        default:   b = 0; break;
        }
        out->widthCode = b;
    } else {
        out->heightCode = r->height;
        out->widthCode = r->width;
    }
    out->offset = r->offset;
    out->reserved18 = 0;
    out->isSet = 1;
    out->bank = r->bank;
    NNSi_G2dSetVramHandle((int *)out, mode, dst);
}







void NNSi_G2dLoadVramResourceSub(struct VramResource *r, u32 dst, int mode, struct VramHandle *out)
{
    u32 bank = r->bank;

    switch (mode) {
    case 0:
        break;
    case 1:
        *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & 0xFFCFFFEF) | bank;
        break;
    case 2:
        *(volatile u32 *)0x04001000 = (*(volatile u32 *)0x04001000 & 0xFFCFFFEF) | bank;
        break;
    }
    DC_FlushRange(r->src, r->size);
    switch (mode) {
    case 0:
        GX_BeginLoadTex();
        GX_LoadTex(r->src, dst, r->size);
        GX_EndLoadTex();
        break;
    case 1:
        GX_LoadOBJ(r->src, dst, r->size);
        break;
    case 2:
        GXS_LoadOBJ(r->src, dst, r->size);
        break;
    }
    if (r->bank == 0) {
        int a, b;
        switch (r->height) {
        case 1:    a = 0; break;
        case 2:    a = 1; break;
        case 4:    a = 2; break;
        case 8:    a = 3; break;
        case 0x10: a = 4; break;
        case 0x20: a = 5; break;
        default:   a = 0; break;
        }
        out->heightCode = a;
        switch (r->width) {
        case 1:    b = 0; break;
        case 2:    b = 1; break;
        case 4:    b = 2; break;
        case 8:    b = 3; break;
        case 0x10: b = 4; break;
        case 0x20: b = 5; break;
        default:   b = 0; break;
        }
        out->widthCode = b;
    } else {
        out->heightCode = r->height;
        out->widthCode = r->width;
    }
    out->offset = r->offset;
    out->reserved18 = 0;
    out->isSet = 1;
    out->bank = r->bank;
    NNSi_G2dSetVramHandle((int *)out, mode, dst);
}







/*
 * Upload one VRAM resource: optionally repoint the 2D/3D VRAM control word,
 * flush the source range, then fill the caller's descriptor.  Sibling of
 * NNSi_G2dLoadVramResourceMain/NNSi_G2dLoadVramResourceSub with the GX upload itself left out (the
 * caller has already moved the bytes).  When f8 (the bank
 * control word) is zero the two halfword dimensions are translated from
 * pixel sizes (1,2,4,8,0x10,0x20) to GX size codes 0..5; otherwise they are
 * stored raw.
 *
 * 1.1p1 CSEs the shared zero into a callee-saved register (costing r8 and a
 * six-register frame) and cross-jumps the two VRAM-control arms, giving 444
 * bytes against the original's 468; under ../2.0/sp2 the same C is 468
 * bytes, 0 mismatches.  See docs/FRONTEND-PINS.md.
 */
void NNSi_G2dSetupVramResource(struct VramResource *r, u32 dst, int mode, struct VramHandle *out)
{
    u32 bank;

    DC_FlushRange(r->src, r->size);
    bank = r->bank;
    switch (mode) {
    case 0:
        break;
    case 1:
        *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & 0xFFCFFFEF) | bank;
        break;
    case 2:
        *(volatile u32 *)0x04001000 = (*(volatile u32 *)0x04001000 & 0xFFCFFFEF) | bank;
        break;
    }
    if (r->bank == 0) {
        int a, b;
        switch (r->height) {
        case 1:    a = 0; break;
        case 2:    a = 1; break;
        case 4:    a = 2; break;
        case 8:    a = 3; break;
        case 0x10: a = 4; break;
        case 0x20: a = 5; break;
        default:   a = 0; break;
        }
        out->heightCode = a;
        switch (r->width) {
        case 1:    b = 0; break;
        case 2:    b = 1; break;
        case 4:    b = 2; break;
        case 8:    b = 3; break;
        case 0x10: b = 4; break;
        case 0x20: b = 5; break;
        default:   b = 0; break;
        }
        out->widthCode = b;
    } else {
        out->heightCode = r->height;
        out->widthCode = r->width;
    }
    out->offset = r->offset;
    out->reserved18 = 0;
    out->isSet = 1;
    out->bank = r->bank;
    NNSi_G2dSetVramHandle((int *)out, mode, dst);
}





void NNSi_G2dLoadVramResourceBySel(VramResourceSel *self, u32 offset, int sel, VramHandleSel *out)
{
    u32 a = self->src;
    u32 b = self->size;

    DC_FlushRange((const void *)a, b);

    switch (sel) {
    case 1:
        if (self->handle != 0) {
            GX_BeginLoadOBJExtPltt(self->handle);
            GX_LoadOBJExtPltt(a, offset, b);
            GX_EndLoadOBJExtPltt();
        } else {
            GX_LoadOBJPltt(a, offset, b);
        }
        break;
    case 2:
        if (self->handle != 0) {
            GXS_BeginLoadOBJExtPltt(self->handle);
            GXS_LoadOBJExtPltt(a, offset, b);
            GXS_EndLoadOBJExtPltt();
        } else {
            GXS_LoadOBJPltt(a, offset, b);
        }
        break;
    case 0:
        GX_BeginLoadTexPltt();
        GX_LoadTexPltt(a, offset, b);
        GX_EndLoadTexPltt();
        break;
    }

    out->formatCode = self->formatCode;
    out->handle = self->handle;
    NNSi_G2dSetVramHandleEx((char *)out, sel, offset);
}




/*
 * The LIST form of src/matched/NNSi_G2dLoadVramResourceBySel.c: the same three-arm dispatch on
 * `sel`, the same twelve callees in the same order, the same
 * `out->formatCode = self->formatCode; out->handle = self->handle; NNSi_G2dSetVramHandleEx(out, sel, base);`
 * tail -- but run once per entry of a (count, u16 *items) list instead of once
 * per call.  Reading it as "NNSi_G2dLoadVramResourceBySel with a loop around it" is what made
 * the body writable at all; every callee declaration below is lifted unchanged
 * from that already-exact sibling.
 *
 * THE ELEMENT SIZE, and what `self->formatCode == 3` means.  Both operands of the
 * per-entry address arithmetic are scaled by one `step` that is 0x20 when
 * self->formatCode == 3 and 0x200 otherwise (`moveq r8, #0x20` / `movne r8, #0x200`,
 * one predicated pair at 0x02063F68 and 0x02063F80 that the two `mul`s then
 * consume).  self->formatCode is also the word copied to out->formatCode, so it is a format
 * code and not a count -- the same field NNSi_G2dLoadVramResourceBySel copies out untouched.
 *
 * FOUR THINGS THE BYTES FORCED, in the order they cost time:
 *
 *   1. The two products are NAMED LOCALS computed before DC_FlushRange, not
 *      expressions at the six call sites.  Writing `a + step * i` inline gives
 *      `mla r0, r6, r4, r5` repeated in every arm where the image has one
 *      `mul r4, r8, r7` / `mul r6, r8, r0` pair at 0x02063FA8 and a plain
 *      `add r0, r5, r4` per arm -- 325 concrete bytes, and 24 bytes of size.
 *
 *   2. The loop is `if (n != 0) { do { ... } while (n > i); }`, not a `while`.
 *      The image tests the count once with `movs r0, r0 / beq #0x2064080`
 *      before the body and then closes with `cmp r0, r1, lsr #16 / bhi` at the
 *      bottom; `i` is a u16, which is what the `lsl #0x10` / `lsr #0x10` pair
 *      around the increment is.
 *
 *   3. DECLARATION ORDER.  `d` (the destination product) must be declared
 *      BEFORE `a` (the self->src base).  Declared the other way round the two
 *      swap registers, giving `mul r5, r8, r7` / `mov r0, r4` /
 *      `add r0, r4, r5` for the image's `mul r4, r8, r7` / `mov r0, r5` /
 *      `add r0, r5, r4` -- 14 concrete bytes and nothing else, exactly
 *      docs/idioms/declaration-order-decides-which-register-a-local-gets.md.
 *
 *   4. The `default:` arm of the switch is explicit and empty, the same tell
 *      as src/matched/NNS_SndWaveOutStart.c: without it the last case is
 *      if-converted into the compare chain instead of getting its own `beq`.
 *
 *   5. THE `../2.0/sp2` PIN.  With all of the above right, dsi/1.1p1 is
 *      size-exact at 356 bytes with exactly ONE concrete byte out, and the
 *      permuter cannot move it: `--explain` reports no register substitution
 *      at all, `--mode hill --budget 800 --types` exhausts 271 single
 *      mutations with no improvement, and `--mode anneal --budget 2000 --types`
 *      compiles 2000 candidates and plateaus twice at the same point.  The
 *      byte is the first half of the step selection: the image predicates BOTH
 *      arms (`moveq r8, #0x20` then `movne r8, #0x200`), 1.1p1 makes the first
 *      unconditional (`mov r8, #0x20` then `movne r8, #0x200`).  Neither the
 *      ternary, the spelled-out if/else, nor the initialise-then-override form
 *      moves it, because under 1.1p1 the variable is provably dead before the
 *      selection and the front end drops the redundant predicate.  ../2.0/sp2
 *      keeps both predicates and is byte-exact; ../1.2/sp2 is 360 bytes.
 *      Five of this cluster's seven other matched rows are already 2.0
 *      (NNSi_G2dIsVramHandleSetEx, NNSi_G2dLoadVramResourceMain, NNSi_G2dLoadVramResourceSub, NNSi_G2dSetupVramResource,
 *      NNSi_G2dLoadVramResourceBySel is 1.1p1) -- see docs/families/cluster_020637F4.h.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_G2dLoadVramResourceList.c \
 *       --func NNSi_G2dLoadVramResourceList --addr 0x02063F4C --arm --cc ../2.0/sp2
 *   -> EXACT, compiled 356 = original 356, 13 of 13 sites resolved
 */
void NNSi_G2dLoadVramResourceList(VramResourceList *self, VramResourceIndices *list, u32 base, int sel,
                   VramHandleList *out)
{
    u32 step;
    u16 n;
    u16 i;
    u32 d;
    u32 a;
    u32 t;

    step = (self->formatCode == 3) ? 0x20 : 0x200;
    n = list->count;
    i = 0;
    if (n != 0) {
        do {
            a = self->src;
            d = step * i;
            t = step * list->items[i];
            DC_FlushRange((const void *)a, self->size);
            switch (sel) {
            case 1:
                if (self->handle != 0) {
                    GX_BeginLoadOBJExtPltt(self->handle);
                    GX_LoadOBJExtPltt(a + d, base + t, step);
                    GX_EndLoadOBJExtPltt();
                } else {
                    GX_LoadOBJPltt(a + d, base + t, step);
                }
                break;
            case 2:
                if (self->handle != 0) {
                    GXS_BeginLoadOBJExtPltt(self->handle);
                    GXS_LoadOBJExtPltt(a + d, base + t, step);
                    GXS_EndLoadOBJExtPltt();
                } else {
                    GXS_LoadOBJPltt(a + d, base + t, step);
                }
                break;
            case 0:
                GX_BeginLoadTexPltt();
                GX_LoadTexPltt(a + d, base + t, step);
                GX_EndLoadTexPltt();
                break;
            default:
                break;
            }
            i = i + 1;
        } while (n > i);
    }
    out->formatCode = self->formatCode;
    out->handle = self->handle;
    NNSi_G2dSetVramHandleEx((char *)((VramHandleSel *)((char *)out)), sel, base);
}
