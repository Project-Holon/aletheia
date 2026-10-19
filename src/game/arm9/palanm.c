/*
 * file:     palanm.c
 * unit:     yes
 * function: ITEM_IsBerry, PALANM_IsOutsideReservedIdRange, PALANM_LookupPairedCode, PALANM_GetPairedCodeForFirst, PALANM_StopTimer, PALANM_StartTimer, PALANM_UpdateTimer, PALANM_Create, PALANM_Delete, PALANM_SetSlotBuffers, PALANM_AllocSlotBuffers, PALANM_FreeSlotBuffers, PALANM_CopyToSlot, PALANM_LoadArcPaletteToSlotAt, PALANM_LoadArcPaletteToSlot, PALANM_LoadHandlePaletteToSlotAt, PALANM_LoadHandlePaletteToSlot, PALANM_CopyHwPaletteToSlot, PALANM_GetDefaultWork, PALANM_GetTransWork, PALANM_RequestFade, PALANM_RequestFadeOverwrite, PALANM_CheckBit, PALANM_SetTransBit, PALANM_MaskColorBits, PALANM_SetFadeParam, PALANM_FadeTask, PALANM_ForceStopFade, PALANM_StepBgFades, PALANM_StepObjFades, PALANM_StepFadeWait, PALANM_ApplyFade, PALANM_CalcFadeColors, PALANM_StepFadeValue, PALANM_TransferPalettes, PALANM_GetFadeRequestBits, PALANM_SetAutoTransfer, PALANM_RequestFullTransfer, PALANM_GetColor, PALANM_BlendColors, PALANM_BlendChannel, PALANM_BlendChannelMask, PALANM_ConvertGrayTable
 * address:  0x020213C0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sItemBerryTable  0x0209E968  data
 *   sPalAnmCodePairTable  0x0209E904  data
 *   sPalAnmTimer  0x02146788  data
 *   OS_GetTick  0x020870D0  arm
 *   _ll_udiv    0x0209C00C  arm
 *   GFL_HEAP_Alloc      0x02030734  arm
 *   MI_CpuFill8        0x02082BCC  arm
 *   sPalAnmFileName 0x020A73BC  data
 *   GFL_HEAP_Free  0x020307B0  arm
 *   sPalAnmFileName 0x020A73BC  data
 *   MIi_CpuCopy16  0x02082A60  arm
 *   ARC_UTIL_LoadPaletteBlockFromArchive  0x02049F34  arm
 *   ARC_UTIL_LoadPaletteBlockFromHandle  0x02049F78  arm
 *   TCB_DeleteTask   0x02030EAC  arm
 *   DC_FlushRange   0x020862F0  arm
 *   GX_LoadBGPltt   0x0207E3D0  arm
 *   GXS_LoadBGPltt   0x0207E468  arm
 *   GX_LoadOBJPltt   0x0207E51C  arm
 *   GXS_LoadOBJPltt   0x0207E5D0  arm
 *   GX_BeginLoadBGExtPltt   0x0207F308  arm
 *   GX_LoadBGExtPltt   0x0207F394  arm
 *   GX_EndLoadBGExtPltt   0x0207F428  arm
 *   GX_BeginLoadOBJExtPltt   0x0207F47C  arm
 *   GX_LoadOBJExtPltt   0x0207F4C4  arm
 *   GX_EndLoadOBJExtPltt   0x0207F560  arm
 *   GXS_BeginLoadBGExtPltt   0x0207F5B0  arm
 *   GXS_LoadBGExtPltt   0x0207F5C8  arm
 *   GXS_EndLoadBGExtPltt   0x0207F65C  arm
 *   GXS_BeginLoadOBJExtPltt   0x0207F6A8  arm
 *   GXS_LoadOBJExtPltt   0x0207F6C0  arm
 *   GXS_EndLoadOBJExtPltt   0x0207F754  arm
 *   GAME_DATA_AddPlayTime  0x02012FBC  thumb
 *   TCB_AddTask  0x02030DA8  arm
 *   0  0x05000000  main BG
 *   1  0x05000400  sub BG
 *   2  0x05000200  main OBJ
 *   3  0x05000600  sub OBJ
 */
struct PalAnmSlot;
typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned char  u8;

typedef unsigned long long u64;

struct PalAnmTimer {
    u32 active;
    u64 lastTick;
    u64 doneUnits;
    u64 baseTick;
};

struct PalAnmSlot {
    u16 *rawBuf;
    u16 *workBuf;
    u32 size;
    u32 spare0;
    u32 spare1;
};

struct PalAnmRes {
    u32  format;
    u32  extFlag;
    u32  byteSize;
    u16 *data;
};

extern u64 OS_GetTick(void);
extern u32 GAME_DATA_AddPlayTime(u8 *target, u32 elapsedUnits);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 allocTag);
extern void MI_CpuFill8(void *dest, u32 data, u32 size);
extern u32 GFL_HEAP_Free(void *block);
extern void MIi_CpuCopy16(const void *src, void *dest, u32 size);
extern void *ARC_UTIL_LoadPaletteBlockFromArchive(u32 archiveID, u32 memberIdx, u32 unpackedOut, u32 flags);
extern void *ARC_UTIL_LoadPaletteBlockFromHandle(void *arc, u32 memberIdx, u32 unpackedOut, u32 flags);
int ITEM_IsBerry(u32 colorCode);
u32 PALANM_IsOutsideReservedIdRange(u16 id);
u16 PALANM_LookupPairedCode(int value, int column);
unsigned short PALANM_GetPairedCodeForFirst(int value);
void PALANM_StopTimer(void);
void PALANM_StartTimer(void);
void PALANM_UpdateTimer(u8 *target);
void *PALANM_Create(u32 heapId);
u32 PALANM_Delete(void *ctx);
void PALANM_SetSlotBuffers(struct PalAnmSlot *palSlots, u32 slotIdx, void *rawBuf, void *workBuf, u32 size);
void PALANM_AllocSlotBuffers(struct PalAnmSlot *palSlots, u32 slotIdx, u32 size, u32 heapId);
void PALANM_FreeSlotBuffers(struct PalAnmSlot *palSlots, u32 slotIdx);
void PALANM_CopyToSlot(struct PalAnmSlot *palSlots, const void *src, u32 slotIdx, u32 dstOffset, u16 size);
void PALANM_LoadArcPaletteToSlotAt(struct PalAnmSlot *palSlots, u32 arcId, u32 fileId, u32 heapId, u32 slotIdx, u32 byteSize, u16 dstOffset, u16 srcOffset);
void PALANM_LoadArcPaletteToSlot(struct PalAnmSlot *palSlots, u32 arcId, u32 fileId, u32 heapId, u32 slotIdx, u32 byteSize, u16 dstOffset);
void PALANM_LoadHandlePaletteToSlotAt(struct PalAnmSlot *palSlots, void *arcHandle, u32 fileId, u32 heapId, u32 slotIdx, u32 byteSize, u16 dstOffset, u16 srcOffset);
void PALANM_LoadHandlePaletteToSlot(struct PalAnmSlot *palSlots, void *arcHandle, u32 fileId, u32 heapId, u32 slotIdx, u32 byteSize, u16 dstOffset);
void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *palSlots, u32 bank, u32 dstOffset, u32 size);
extern u16 sItemBerryTable[];
extern u16 sPalAnmCodePairTable[][2];
extern struct PalAnmTimer sPalAnmTimer;
extern const char sPalAnmFileName[];
extern const char sPalAnmFileName[];

struct Node;

typedef signed int     s32;

typedef signed   short s16;

typedef struct {
    u16 paletteBits;
    u16 wait     : 6;
    u16 current    : 5;
    u16 end    : 5;
    u16 color : 15;
    u16 direction   : 1;
    u16 speed   : 5;
    u16 waitCount   : 6;
    u16 pad    : 5;
} PaletteFadeParam;

typedef struct {
    u16 *defaultWork;
    u16 *transWork;
    u32 size;
    PaletteFadeParam param;
} PaletteFadeWork;

typedef struct {
    PaletteFadeWork work[14];
    u16 requestFlag : 2;
    u16 requestBits  : 14;
    u16 transBits : 14;
    u16 taskActive  : 1;
    u16 autoTrans : 1;
    u8  forceStop;
} PaletteFade;

struct Rgb555 {
    u16 r : 5;
    u16 g : 5;
    u16 b : 5;
    u16 pad : 1;
};

extern u32 TCB_DeleteTask(struct Node *n);

extern void DC_FlushRange(void *a, u32 b);

extern void GX_LoadBGPltt(void *a, u32 b, u32 c);

extern void GXS_LoadBGPltt(void *a, u32 b, u32 c);

extern void GX_LoadOBJPltt(void *a, u32 b, u32 c);

extern void GXS_LoadOBJPltt(void *a, u32 b, u32 c);

extern void GX_BeginLoadBGExtPltt(void);

extern void GX_LoadBGExtPltt(void *a, u32 b, u32 c);

extern void GX_EndLoadBGExtPltt(void);

extern void GX_BeginLoadOBJExtPltt(void);

extern void GX_LoadOBJExtPltt(void *a, u32 b, u32 c);

extern void GX_EndLoadOBJExtPltt(void);

extern void GXS_BeginLoadBGExtPltt(void);

extern void GXS_LoadBGExtPltt(void *a, u32 b, u32 c);

extern void GXS_EndLoadBGExtPltt(void);

extern void GXS_BeginLoadOBJExtPltt(void);

extern void GXS_LoadOBJExtPltt(void *a, u32 b, u32 c);

extern void GXS_EndLoadOBJExtPltt(void);

int PALANM_GetDefaultWork(char *p, int i);

int PALANM_GetTransWork(char *p, int i);

int PALANM_RequestFade(PaletteFade *p, u16 mask, u16 col, s16 step, u8 b, u8 c, u16 d, void *ctx);

int PALANM_RequestFadeOverwrite(PaletteFade *p, u16 mask, u16 col, s16 step, u8 b, u8 c, u16 d, void *ctx);

u8 PALANM_CheckBit(u32 val, int bit);

void PALANM_SetTransBit(PaletteFade *p, int channel);

void PALANM_MaskColorBits(s32 idx, PaletteFadeWork *c, u16 *pv);

void PALANM_SetFadeParam(PaletteFadeParam *s, u16 f0, s32 a, u8 b, u8 c, u16 d);

void PALANM_FadeTask(void *a, PaletteFade *p);

void PALANM_ForceStopFade(PaletteFade *o);

void PALANM_StepBgFades(PaletteFade *p);

void PALANM_StepObjFades(PaletteFade *p);

void PALANM_StepFadeWait(PaletteFade *p, u32 idx, u32 arg);

void PALANM_ApplyFade(PaletteFade *p, u32 idx, u32 arg);

void PALANM_CalcFadeColors(u16 *src, u16 *dst, PaletteFadeParam *c, u32 count);

void PALANM_StepFadeValue(PaletteFade *p, u32 idx, PaletteFadeParam *s);

void PALANM_TransferPalettes(PaletteFade *p);

u32 PALANM_GetFadeRequestBits(const PaletteFade *ptr);

void PALANM_SetAutoTransfer(PaletteFade *o, int v);

void PALANM_RequestFullTransfer(PaletteFade *o, int v);

u16 PALANM_GetColor(PaletteFadeWork *s, int idx, int which, u16 pos);

void PALANM_BlendColors(u16 *src, u16 *dst, u32 count, int weight, u16 color);

void PALANM_BlendChannel(PaletteFadeWork *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);

void PALANM_BlendChannelMask(PaletteFadeWork *p, u32 idx, u16 m, u8 weight, u16 color);

void PALANM_ConvertGrayTable(u16 *pal, int n, const u8 *table);

int ITEM_IsBerry(u32 colorCode)
{
    u32 i;

    for (i = 0; i < 0x40; i++)
        if (sItemBerryTable[i] == colorCode)
            return 1;
    return 0;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/PALANM_IsOutsideReservedIdRange.c  *       --func PALANM_IsOutsideReservedIdRange --addr 0x020213E0 --cc 1.1p1 --thumb
 */
u32 PALANM_IsOutsideReservedIdRange(u16 id)
{
    if ((u16)(id + 0xFE14) > 8) {
        return 1;
    }
    return 0;
}

u16 PALANM_LookupPairedCode(int value, int column)
{
    u32 i;

    for (i = 0; i < 0x19; i++)
        if (sPalAnmCodePairTable[i][column] == value)
            return sPalAnmCodePairTable[i][column ^ 1];
    return 0;
}

unsigned short PALANM_GetPairedCodeForFirst(int value)
{
    return PALANM_LookupPairedCode(value, 0);
}

/*
 * Clears the one word at 0x02146788.  Four bytes of code and its pool word.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PALANM_StopTimer.c \
 *       --func PALANM_StopTimer --addr 0x02021438 --cc 1.1p1 --thumb
 */
void PALANM_StopTimer(void)
{
    sPalAnmTimer.active = 0;
}

/*
 * Reset the palette-animation module state block and stamp it with the
 * current tick.  The same global's first word is the one PALANM_StopTimer
 * clears, so the block is a struct starting at 0x02146788, not five
 * unrelated globals.
 *
 * The tick is a `u64` field at +0x14: OS_GetTick returns the pair in r0:r1
 * and both halves are stored with plain word stores at +0x14 and +0x18,
 * which is a 4-aligned `long long`
 * (docs/idioms/long-long-aligns-to-four.md), not two `u32`s assigned from a
 * split helper.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PALANM_StartTimer.c \
 *       --func PALANM_StartTimer --addr 0x02021444 --cc 1.1p1 --thumb
 */
void PALANM_StartTimer(void)
{
    sPalAnmTimer.active = 1;
    sPalAnmTimer.lastTick = 0;
    sPalAnmTimer.doneUnits = 0;
    sPalAnmTimer.baseTick = OS_GetTick();
}

/*
 * Palette-animation tick pump.  sPalAnmTimer is the same state block
 * PALANM_StartTimer resets; unk_04, unk_0c and tick are 4-aligned u64 fields
 * (docs/idioms/long-long-aligns-to-four.md).  The divisor 0x01FF6210 is the
 * OS tick-to-unit scale applied after a <<6, through _ll_udiv
 * (docs/idioms/runtime-helper-reloc.md).
 *
 * The last four bytes were the arm order: the equal case is written first
 * so the `bne` reaches the OS_GetTick arm
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PALANM_UpdateTimer.c \
 *       --func PALANM_UpdateTimer --addr 0x02021464 --cc 1.1p1 --thumb
 */
void PALANM_UpdateTimer(u8 *target)
{
    u64 now;
    u64 units;

    if (sPalAnmTimer.active == 0) {
        return;
    }
    now = OS_GetTick();
    if (now < sPalAnmTimer.lastTick) {
        now = now + sPalAnmTimer.lastTick;
    } else {
        sPalAnmTimer.lastTick = now;
    }
    units = ((now - sPalAnmTimer.baseTick) << 6) / 0x01FF6210;
    if (sPalAnmTimer.doneUnits >= units) {
        return;
    }
    GAME_DATA_AddPlayTime(target, (u32)(units - sPalAnmTimer.doneUnits));
    if (sPalAnmTimer.lastTick == now) {
        sPalAnmTimer.doneUnits = units;
    } else {
        now = OS_GetTick();
        sPalAnmTimer.baseTick = now;
        sPalAnmTimer.doneUnits = (now << 6) / 0x01FF6210;
        sPalAnmTimer.lastTick = now;
    }
}

/*
 * Allocate and zero the 0x120-byte palette-animation context.  0x120 is out
 * of Thumb immediate range, so the compiler materialises the allocation tag 88 first
 * and derives the size from it with `adds r4, #0xc8`, the
 * docs/idioms/consecutive-line-numbers-are-one-pool-word-and-adds.md shape
 * applied to two unrelated constants that happen to be close.
 *
 * The heap id is truncated to 16 bits before the call (`lsls #16 / lsrs
 * #16`), so the value reaching the allocator is narrower than the parameter
 * this function receives.  A plain `u16` parameter forwarded unchanged does
 * not produce the pair, since mwcc assumes an incoming narrow parameter is
 * already truncated; the equally byte-exact reading is a `u16` heap-id
 * slot on the allocator prototype itself, which every other call site in
 * src/matched/ spells `u32`.
 *
 * EXACT*: the extent runs to 48 bytes because the next function at
 * 0x02021548 saves no lr and carries no label.
 *
 * 0x020A73BC is this translation unit's allocation-site pointer, the
 * palanm.c anchor in layout/file_anchors.txt.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PALANM_Create.c \
 *       --func PALANM_Create --addr 0x02021518 --cc 1.1p1 --thumb
 */
void *PALANM_Create(u32 heapId)
{
    void *ctx = GFL_HEAP_Alloc((u16)heapId, 0x120, 0, sPalAnmFileName, 88);
    MI_CpuFill8(ctx, 0, 0x120);
    return ctx;
}

/*
 * Unlabelled Thumb leaf: a bare tail call to GFL_HEAP_Free with no arguments
 * (`ldr r3,[pc,#0]; bx r3`; the pool word names 0x020307B0).  Disasm.py gave
 * it no func_ label because it has no prologue.
 */
u32 PALANM_Delete(void *ctx)
{
    return GFL_HEAP_Free(ctx);
}

/*
 * Fill one 0x14-byte slot of the palette-animation buffer array: the two
 * buffer pointers and their common size.  No relocations.
 *
 * The fifth argument arrives on the stack; with two registers pushed and no
 * frame it reads back at [sp, #8].
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PALANM_SetSlotBuffers.c \
 *       --func PALANM_SetSlotBuffers --addr 0x02021548 --cc 1.1p1 --thumb
 */
void PALANM_SetSlotBuffers(struct PalAnmSlot *palSlots, u32 slotIdx, void *rawBuf,
                   void *workBuf, u32 size)
{
    palSlots[slotIdx].rawBuf = rawBuf;
    palSlots[slotIdx].workBuf = workBuf;
    palSlots[slotIdx].size = size;
}

/*
 * Allocate the double buffer for one palette-animation slot: two blocks of
 * the same size out of the same heap, tags 142 and 143, then hand both plus
 * the size to the slot setter.
 *
 * The size is the allocator's second argument and the setter's fifth, and
 * it is never reloaded, which is what pins it as a parameter rather than a
 * field of the slot.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PALANM_AllocSlotBuffers.c \
 *       --func PALANM_AllocSlotBuffers --addr 0x0202155C --cc 1.1p1 --thumb
 */
void PALANM_AllocSlotBuffers(struct PalAnmSlot *palSlots, u32 slotIdx, u32 size, u32 heapId)
{
    void *rawBuf = GFL_HEAP_Alloc(heapId, size, 0, sPalAnmFileName, 142);
    void *workBuf = GFL_HEAP_Alloc(heapId, size, 0, sPalAnmFileName, 143);
    PALANM_SetSlotBuffers((struct PalAnmSlot *)palSlots, slotIdx, rawBuf, workBuf, size);
}

/*
 * Release the double buffer of one palette-animation slot, the inverse of
 * PALANM_AllocSlotBuffers.  The two slot pointers are read back from the array rather
 * than passed in, which is what makes the 0x14 stride multiply live.
 *
 * EXACT*: the extent runs long because the next function at 0x020215BC has
 * no label.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PALANM_FreeSlotBuffers.c \
 *       --func PALANM_FreeSlotBuffers --addr 0x020215A0 --cc 1.1p1 --thumb
 */
void PALANM_FreeSlotBuffers(struct PalAnmSlot *palSlots, u32 slotIdx)
{
    GFL_HEAP_Free(palSlots[slotIdx].rawBuf);
    GFL_HEAP_Free(palSlots[slotIdx].workBuf);
}

/*
 * Copy the same source halfwords into both buffers of one palette-animation
 * slot at the same halfword offset.  The offset is scaled once (`lsls r4,
 * r3, #1`) and reused for both destinations, which is the `u16 *` pointer
 * arithmetic rather than a byte offset the caller already doubled.
 *
 * The fifth argument is a `u16` on the stack, read with `ldrh` at [sp,#0x18]
 * behind six pushed registers, and widened into the copier's `u32` length.
 *
 * EXACT*: the next function at 0x020215EC follows immediately with no label gap in the walk.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PALANM_CopyToSlot.c \
 *       --func PALANM_CopyToSlot --addr 0x020215BC --cc 1.1p1 --thumb
 */
void PALANM_CopyToSlot(struct PalAnmSlot *palSlots, const void *src, u32 slotIdx,
                   u32 dstOffset, u16 size)
{
    MIi_CpuCopy16(src, palSlots[slotIdx].rawBuf + dstOffset, size);
    MIi_CpuCopy16(src, palSlots[slotIdx].workBuf + dstOffset, size);
}

/*
 * Load a palette resource, copy a run of it into both buffers of one
 * palette-animation slot, then release the loaded block.  PALANM_LoadHandlePaletteToSlotAt is
 * the same function against the sibling loader at 0x02049F78.
 *
 * The loader's fourth argument is `(u16)((arg & 0x7fff) | 0x8000)`: the
 * constant is materialised once as 0x7fff for the mask and re-derived as
 * 0x8000 with `adds r3, r4, #1` for the flag, so the two constants are one
 * pool word.
 *
 * The byteSize argument doubles as "use the resource's own size": zero falls
 * through to the loaded header's +0x08, and only the merged value is
 * truncated to 16 bits, which is what puts the `lsls/lsrs` pair after the
 * join rather than in each arm.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PALANM_LoadArcPaletteToSlotAt.c \
 *       --func PALANM_LoadArcPaletteToSlotAt --addr 0x020215EC --cc 1.1p1 --thumb
 */
void PALANM_LoadArcPaletteToSlotAt(struct PalAnmSlot *palSlots, u32 arcId, u32 fileId, u32 heapId,
                   u32 slotIdx, u32 byteSize, u16 dstOffset, u16 srcOffset)
{
    struct PalAnmRes *res;
    void *block;

    block = ARC_UTIL_LoadPaletteBlockFromArchive(arcId, fileId, (u32)(&res), (u16)((heapId & 0x7fff) | 0x8000));
    if (byteSize == 0) {
        byteSize = res->byteSize;
    }
    PALANM_CopyToSlot((struct PalAnmSlot *)palSlots, res->data + srcOffset, slotIdx, dstOffset, (u16)byteSize);
    GFL_HEAP_Free(block);
}

/*
 * Forward to PALANM_LoadArcPaletteToSlotAt with a source offset of zero, i.e. copy from the
 * start of the loaded palette.  The four register arguments are never
 * touched, only the three stack arguments are re-pushed and the eighth is
 * appended; the seventh is re-read with `ldrh`, which is what pins it as a
 * `u16` in both prototypes.
 *
 * EXACT*: the extent runs long because the next function has no label.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PALANM_LoadArcPaletteToSlot.c \
 *       --func PALANM_LoadArcPaletteToSlot --addr 0x02021640 --cc 1.1p1 --thumb
 */
void PALANM_LoadArcPaletteToSlot(struct PalAnmSlot *palSlots, u32 arcId, u32 fileId, u32 heapId,
                   u32 slotIdx, u32 byteSize, u16 dstOffset)
{
    PALANM_LoadArcPaletteToSlotAt((struct PalAnmSlot *)palSlots, arcId, fileId, heapId, slotIdx, byteSize, dstOffset, 0);
}

/*
 * Load a palette resource, copy a run of it into both buffers of one
 * palette-animation slot, then release the loaded block.  PALANM_LoadArcPaletteToSlotAt is
 * the same function against the sibling loader at 0x02049F34.
 *
 * The loader's fourth argument is `(u16)((arg & 0x7fff) | 0x8000)`: the
 * constant is materialised once as 0x7fff for the mask and re-derived as
 * 0x8000 with `adds r3, r4, #1` for the flag, so the two constants are one
 * pool word.
 *
 * The byteSize argument doubles as "use the resource's own size": zero falls
 * through to the loaded header's +0x08, and only the merged value is
 * truncated to 16 bits, which is what puts the `lsls/lsrs` pair after the
 * join rather than in each arm.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PALANM_LoadHandlePaletteToSlotAt.c \
 *       --func PALANM_LoadHandlePaletteToSlotAt --addr 0x02021660 --cc 1.1p1 --thumb
 */
void PALANM_LoadHandlePaletteToSlotAt(struct PalAnmSlot *palSlots, void *arcHandle, u32 fileId, u32 heapId,
                   u32 slotIdx, u32 byteSize, u16 dstOffset, u16 srcOffset)
{
    struct PalAnmRes *res;
    void *block;

    block = ARC_UTIL_LoadPaletteBlockFromHandle(arcHandle, fileId, (u32)(&res), (u16)((heapId & 0x7fff) | 0x8000));
    if (byteSize == 0) {
        byteSize = res->byteSize;
    }
    PALANM_CopyToSlot((struct PalAnmSlot *)palSlots, res->data + srcOffset, slotIdx, dstOffset, (u16)byteSize);
    GFL_HEAP_Free(block);
}

/*
 * Forward to PALANM_LoadHandlePaletteToSlotAt with a source offset of zero, i.e. copy from the
 * start of the loaded palette.  The four register arguments are never
 * touched, only the three stack arguments are re-pushed and the eighth is
 * appended; the seventh is re-read with `ldrh`, which is what pins it as a
 * `u16` in both prototypes.
 *
 * EXACT*: the extent runs long because the next function has no label.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PALANM_LoadHandlePaletteToSlot.c \
 *       --func PALANM_LoadHandlePaletteToSlot --addr 0x020216B4 --cc 1.1p1 --thumb
 */
void PALANM_LoadHandlePaletteToSlot(struct PalAnmSlot *palSlots, void *arcHandle, u32 fileId, u32 heapId,
                   u32 slotIdx, u32 byteSize, u16 dstOffset)
{
    PALANM_LoadHandlePaletteToSlotAt((struct PalAnmSlot *)palSlots, arcHandle, fileId, heapId, slotIdx, byteSize, dstOffset, 0);
}

/*
 * Snapshot one palette bank into the animation slot that shadows it.  The
 * bank selector indexes both the hardware palette base and the slot array,
 * so 0..3 are the four DS palette RAM windows in the order
 * main BG / sub BG / main OBJ / sub OBJ:
 *
 *   0  0x05000000  main BG
 *   1  0x05000400  sub BG
 *   2  0x05000200  main OBJ
 *   3  0x05000600  sub OBJ
 *
 * Only 0x05000000 is built with `movs #5 / lsls #24`; the other three need a
 * pool word each, which is why the dense halfword table has one arm that is
 * two instructions and three that are one.
 *
 * The offset is added as `u16 *` arithmetic to the bank base and passed
 * again, unscaled, as the callee's own halfword offset.
 *
 * EXACT*: the extent runs to 106 bytes because the switch pools and the next function at 0x0202173E are pulled in.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PALANM_CopyHwPaletteToSlot.c \
 *       --func PALANM_CopyHwPaletteToSlot --addr 0x020216D4 --cc 1.1p1 --thumb
 */
void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *palSlots, u32 bank, u32 dstOffset, u32 size)
{
    u16 *palBase;

    switch (bank) {
    case 0:
        palBase = (u16 *)0x05000000;
        break;
    case 1:
        palBase = (u16 *)0x05000400;
        break;
    case 2:
        palBase = (u16 *)0x05000200;
        break;
    case 3:
        palBase = (u16 *)0x05000600;
        break;
    default:
        return;
    }

    PALANM_CopyToSlot((struct PalAnmSlot *)palSlots, palBase + dstOffset, bank, dstOffset, (u16)size);
}

int PALANM_GetDefaultWork(char *p, int i)
{
    return *(int *)(p + i * 0x14);
}

/*
 * Unlabelled Thumb leaf in the ARM9 module: word field of a 0x14-byte strided
 * array.
 *
 * Addresses are Black-image addresses.
 */
int PALANM_GetTransWork(char *p, int i)
{
    return *(int *)(p + i * 0x14 + 4);
}

/*
 * Palette-animation engine (palanm.c). For each of the fourteen channels
 * whose bit is set in `mask` and not yet
 * set in p->requestBits: narrow the colour to the channel's
 * width (PALANM_MaskColorBits, through the address of `col`, which is why all
 * four register parameters are pushed), initialise the channel's
 * animation sub-object at +0xC, mark the channel (PALANM_SetTransBit), run it
 * once (PALANM_ApplyFade, 0x10 for channels 0..3, 0x100 for 4..0xD) and
 * restore `col`. If any channel started, OR the mask into requestBits and, when the tick
 * is not registered yet (b_x), set b_x, requestFlag = 1, clear the latch and
 * register PALANM_FadeTask with TCB_AddTask at priority -2. Returns 1 when
 * a channel started.
 *
 * Written fresh in wave 20 (lane palanm_fresh). The 33-byte residue of
 * earlier waves (the entry `str r3, [sp, #8]` sliding behind the stack
 * parameter copies) closes with the parameter types read from the callee:
 * `step` is narrow (s16 here; u16 and s8 give the same bytes), and b, c,
 * d are u8, u8, u16 both here and in the PALANM_SetFadeParam prototype (its own
 * matched body). The narrow step's home store is then emitted at the
 * front of the prologue
 * (docs/idioms/a-narrow-parameter-pins-its-home-store-to-the-front-of-the-prologue.md).
 * With u32 b, c, d in the prototype the same source is 236 bytes.
 * PALANM_SetFadeParam is declared with six parameters: the caller passes six and
 * the callee's seventh (never read) is whatever sits at [sp, #8].
 */
int PALANM_RequestFade(PaletteFade *p, u16 mask, u16 col, s16 step, u8 b, u8 c, u16 d, void *ctx)
{
    u16 keep = col;
    int ret = 0;
    u8 i;

    for (i = 0; i < 14; i++) {
        if (PALANM_CheckBit(mask, i) == 1 && PALANM_CheckBit(p->requestBits, i) == 0) {
            PALANM_MaskColorBits(i, &p->work[i], &col);
            PALANM_SetFadeParam(&p->work[i].param, col, step, b, c, d);
            PALANM_SetTransBit(p, i);
            if (i >= 4) {
                PALANM_ApplyFade(p, i, 0x100);
            } else {
                PALANM_ApplyFade(p, i, 0x10);
            }
            col = keep;
            ret = 1;
        }
    }
    if (ret == 1) {
        p->requestBits |= mask;
        if (p->taskActive == 0) {
            p->taskActive = 1;
            p->requestFlag = 1;
            p->forceStop = 0;
            TCB_AddTask(ctx, (void (*)(void *, PaletteFade *))PALANM_FadeTask, p, -2);
        }
    }
    return ret;
}

/*
 * Palette-animation engine (palanm.c). For each of the fourteen channels
 * whose bit is set in `mask`: narrow the colour to the channel's
 * width (PALANM_MaskColorBits, through the address of `col`, which is why all
 * four register parameters are pushed), initialise the channel's
 * animation sub-object at +0xC, mark the channel (PALANM_SetTransBit), run it
 * once (PALANM_ApplyFade, 0x10 for channels 0..3, 0x100 for 4..0xD) and
 * restore `col`. If any channel started, store the mask to requestBits and, when the tick
 * is not registered yet (b_x), set b_x, requestFlag = 1, clear the latch and
 * register PALANM_FadeTask with TCB_AddTask at priority -2. Returns 1 when
 * a channel started.
 *
 * Written fresh in wave 20 (lane palanm_fresh). The 33-byte residue of
 * earlier waves (the entry `str r3, [sp, #8]` sliding behind the stack
 * parameter copies) closes with the parameter types read from the callee:
 * `step` is narrow (s16 here; u16 and s8 give the same bytes), and b, c,
 * d are u8, u8, u16 both here and in the PALANM_SetFadeParam prototype (its own
 * matched body). The narrow step's home store is then emitted at the
 * front of the prologue
 * (docs/idioms/a-narrow-parameter-pins-its-home-store-to-the-front-of-the-prologue.md).
 * With u32 b, c, d in the prototype the same source is 236 bytes.
 * PALANM_SetFadeParam is declared with six parameters: the caller passes six and
 * the callee's seventh (never read) is whatever sits at [sp, #8].
 */
int PALANM_RequestFadeOverwrite(PaletteFade *p, u16 mask, u16 col, s16 step, u8 b, u8 c, u16 d, void *ctx)
{
    u16 keep = col;
    int ret = 0;
    u8 i;

    for (i = 0; i < 14; i++) {
        if (PALANM_CheckBit(mask, i) == 1) {
            PALANM_MaskColorBits(i, &p->work[i], &col);
            PALANM_SetFadeParam(&p->work[i].param, col, step, b, c, d);
            PALANM_SetTransBit(p, i);
            if (i >= 4) {
                PALANM_ApplyFade(p, i, 0x100);
            } else {
                PALANM_ApplyFade(p, i, 0x10);
            }
            col = keep;
            ret = 1;
        }
    }
    if (ret == 1) {
        p->requestBits = mask;
        if (p->taskActive == 0) {
            p->taskActive = 1;
            p->requestFlag = 1;
            p->forceStop = 0;
            TCB_AddTask(ctx, (void (*)(void *, PaletteFade *))PALANM_FadeTask, p, -2);
        }
    }
    return ret;
}

u8 PALANM_CheckBit(u32 val, int bit)
{
    u8 ret;

    if (val & (1 << bit)) {
        ret = 1;
    } else {
        ret = 0;
    }
    return ret;
}

void PALANM_SetTransBit(PaletteFade *p, int channel)
{
    if (PALANM_CheckBit(p->transBits, channel) == 1)
        return;
    p->transBits |= 1 << channel;
}

/*
 * Narrows *pv to the channel's own bit width. The width is an 8-bit field of
 * the channel record's word at +8: bits[5:13) for channels 0..3 and
 * bits[9:17) for 4..0xD. The mask is not built with a shift -- the original
 * really does accumulate `1 << n` in a u16 loop, so the source has to be
 * written as the loop, not as `(1 << w) - 1`.
 *
 * Three spellings are load-bearing. The `(u8)` narrowing of the width is
 * applied AFTER the if/else, not inside each arm, so both arms share the
 * `lsrs r4, r0, #0x18` (the shared-exit idiom). `w` is u32, not u8, or the
 * narrowing costs a second shift pair. And the do-while guard must be
 * spelled `if (n < w)` against the already-zeroed counter, not `if (w != 0)`
 * or `if (0 < w)`: only that form emits the original's `bls`, the others
 * emit `beq` -- a single byte, and the last one left in this function.
 *
 * EXACT* only: 62 bytes compiled, listing extent 64; the extra halfword at
 * 0x020219C2 is alignment padding, not an unlabelled follower.
 */
void PALANM_MaskColorBits(s32 idx, PaletteFadeWork *c, u16 *pv)
{
    u32 t;
    u16 m;
    u8 n;
    u32 w;

    if (idx < 4) {
        t = c->size << 0x13;
    } else {
        t = c->size >> 9 << 0x18;
    }
    w = t >> 0x18;

    m = 0;
    n = 0;
    if (n < w) {
        do {
            m = (u16)(m + (u16)(1 << n));
            n++;
        } while (n < w);
    }

    *pv = *pv & m;
}

/*
 * Seven-argument initialiser for one 8-byte animation slot (the `+0xc`
 * sub-object of the 0x14-byte per-channel record; both callers, 0x0202173E
 * and 0x0202184A, pass `p + idx*0x14 + 0xc`). Arguments 5..7 arrive on the
 * caller's stack (visible as `add r5,sp,#0x10` with a bare `push {r4-r7}`
 * and no frame). Argument 7 is never read.
 *
 * Halfword layout of the slot:
 *   +0x00  u16 f0            (= arg2, stored whole)
 *   +0x02  lo:6, mid:5, hi:5
 *   +0x04  val:15, flag:1
 *   +0x06  step:5, copy:6, pad:5
 *
 * The narrow parameter types are load-bearing, not cosmetic. Args 5 and 6
 * are read with `ldrb [r5]` / `ldrh [r5,#4]` off the stack-arg area, which
 * only happens when they are declared u8 / u16; and arg 4 must be u8 (not
 * u32 or u16), or the 5-bit bitfield store costs an extra u16-truncation
 * shift pair -- 8 bytes over 192, and the whole tail shifts with it.
 */
void PALANM_SetFadeParam(PaletteFadeParam *s, u16 f0, s32 a, u8 b, u8 c, u16 d)
{
    u8 n;

    if (a < 0) {
        n = (u8)((a < 0 ? -a : a) + 2);
        if (n > 0x10) {
            n = 0x10;
        }
        s->speed = n;
        s->wait = 0;
    } else {
        s->speed = 2;
        s->wait = (u16)a;
    }

    s->paletteBits = f0;
    s->current = b;
    s->end = c;
    s->color = d;
    s->waitCount = s->wait;

    if (b < c) {
        s->direction = 0;
    } else {
        s->direction = 1;
    }
}

/*
 * Per-frame tick on the slot header at p+0x118. Two halfword bitfields sit
 * there, each `lo:14, hi:2` (the +0x11A one is the field PALANM_SetTransBit
 * sets bits in), followed by a u8 latch at p+0x11C.
 *
 * If the latch is set, the tick is a teardown: clear the latch, clear both
 * lo fields and bit 14 of the +0x11A one, and call out through 0x02030EAC.
 * Otherwise, when the low two bits of the +0x118 field read 1 (the "running"
 * mode), copy that field's 14 bits over the +0x11A field, step all fourteen
 * channels (PALANM_StepBgFades for 0..3, PALANM_StepObjFades for 4..0xD), and when the
 * +0x118 field has drained to zero, clear bit 14 of +0x11A and call out.
 *
 * EXACT* only: the compiled function is 148 bytes and correct throughout;
 * the listing's 168-byte extent runs on past the literal pool at 0x02021B10
 * into an unlabelled leaf at 0x02021B18 (`movs r0,#0x46; lsls r0,#2;
 * ldrh r2,[r0,r5]; ... strb r2,[r0,r1]; bx lr` -- a no-lr-saving accessor,
 * so disasm.py never labelled it). Worth seeding into
 * layout/function_starts.txt; reported rather than edited here.
 */
void PALANM_FadeTask(void *a, PaletteFade *p)
{
    if (p->forceStop == 1) {
        p->forceStop = 0;
        p->transBits = 0;
        p->requestBits = 0;
        p->taskActive = 0;
        TCB_DeleteTask(a);
        return;
    }

    if (p->requestFlag != 1) {
        return;
    }

    p->transBits = p->requestBits;
    PALANM_StepBgFades(p);
    PALANM_StepObjFades(p);
    if (p->requestBits == 0) {
        p->taskActive = 0;
        TCB_DeleteTask(a);
    }
}

/*
 * An unlabelled leaf (saves no lr, see docs/idioms/
 * unlabelled-leaf-functions-hide-in-word-runs.md).  Reads the 14-bit field
 * above the low two bits of the halfword at +0x118 and, when it is
 * non-zero, sets the byte at +0x11c to 1.
 *
 * The `lsls #0x10 / lsrs #0x12` pair is the unequal-shift narrowing form
 * (docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md):
 * a u16 truncation folded with a >> 2.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PALANM_ForceStopFade.c \
 *       --func PALANM_ForceStopFade --addr 0x02021B18 --cc 1.1p1 --thumb
 */
void PALANM_ForceStopFade(PaletteFade *o)
{
    if (o->requestBits)
        o->forceStop = 1;
}

void PALANM_StepBgFades(PaletteFade *p)
{
    u8 i;

    for (i = 0; i < 4; i++) {
        PALANM_StepFadeWait(p, i, 0x10);
    }
}

void PALANM_StepObjFades(PaletteFade *p)
{
    u8 i;

    for (i = 4; i < 0xE; i++) {
        PALANM_StepFadeWait(p, i, 0x100);
    }
}

void PALANM_StepFadeWait(PaletteFade *p, u32 idx, u32 arg)
{

    if (PALANM_CheckBit(p->requestBits, idx) == 0) {
        return;
    }

    {
        PaletteFadeWork *s = &p->work[idx];

        if (s->param.waitCount < s->param.wait) {
            s->param.waitCount = s->param.waitCount + 1;
        } else {
            s->param.waitCount = 0;
            PALANM_ApplyFade(p, idx, arg);
        }
    }
}

void PALANM_ApplyFade(PaletteFade *p, u32 idx, u32 arg)
{
    u32 i;
    PaletteFadeWork *s = &p->work[idx];

    for (i = 0; i < 0x10; i++) {
        if (PALANM_CheckBit(s->param.paletteBits, (u16)i)) {
            u32 off = (i * arg) * 2;
            PALANM_CalcFadeColors((u16 *)((u8 *)s->defaultWork + off),
                          (u16 *)((u8 *)s->transWork + off),
                          &s->param,
                          arg);
        }
    }

    PALANM_StepFadeValue(p, (u8)idx, &s->param);
}

/*
 * palanm.c: the per-pixel RGB555 blend loop.  Each channel of src[i] moves
 * weight/16 of the way toward the matching channel of the anim sub-object's
 * 15-bit target colour; the result is written to dst[i].
 *
 * Closed in wave 13 by the shape BLINK_PALANM_Update (blink_palanm.c) proved the
 * same day: the source pixel and the target are u16 LOCALS (an `int` pixel
 * is 20 bytes out), the channel extractions are written inline in each
 * blend rather than bound to sb/sg/sr locals, and the pack is
 * `r | ((b << 10) | (g << 5))` -- the channel ORed last is the one the
 * compiler evaluates first, which is the image's red, blue, green order.
 * The earlier 69-byte reading (int px, t/w/sb/sg/sr locals) is in
 * docs/notes/PALANM_CalcFadeColors.c.txt.
 */
void PALANM_CalcFadeColors(u16 *src, u16 *dst, PaletteFadeParam *c, u32 count)
{
    u32 i;
    u16 a;
    u16 t;
    s32 r;
    s32 g;
    s32 b;

    for (i = 0; i < count; i++) {
        a = src[i];
        t = c->color;
        r = (u8)((a & 0x1f) + ((((t & 0x1f) - (a & 0x1f)) * c->current) >> 4));
        b = (u8)(((a >> 10) & 0x1f) + (((((t >> 10) & 0x1f) - ((a >> 10) & 0x1f)) * c->current) >> 4));
        g = (u8)(((a >> 5) & 0x1f) + (((((t >> 5) & 0x1f) - ((a >> 5) & 0x1f)) * c->current) >> 4));
        dst[i] = (u16)(r | ((b << 10) | (g << 5)));
    }
}

/*
 * Steps or clears one slider on the record at `s`. The halfword at s+2 is
 * three fields: lo6:6, cur:5, max:5. When cur has already reached max, the
 * function instead toggles bit `idx` of the 14-bit flag field at p[0x118]
 * bits[2:16) (pool word 0xFFFF0003 preserves the low two bits) and returns,
 * doing nothing at all if that bit was already clear. Otherwise the sign bit
 * of the halfword at s+4 picks the direction and s->step (5 bits at s+6) the
 * amount: cur moves up and is clamped down to max, or down and clamped up to
 * max, and is written back through pool word 0xFFFFF83F.
 *
 * Three things the earlier note (docs/notes/PALANM_StepFadeValue.c.txt) left open,
 * all settled here:
 *   - the write target in blocks 2a/2b really is `cur` (bits[6:11)), which
 *     is what 0xFFFFF83F clears; the note's own "re-check before trusting
 *     this paragraph" was right to doubt the bits[11:16) reading.
 *   - blocks 2a and 2b each carry their own copy of the read-mask-or-store
 *     writeback. Factoring it out after the if/else costs a register and the
 *     `pop {r4,r5}` grows to `pop {r3,r4,r5,r6}`.
 *   - the value sign-extended at the top of each arm is `(s16)s->cur`, the
 *     already-extracted 5-bit field, NOT a fresh s16 read of the raw
 *     halfword at s+2. Both spell `lsls #0x10; asrs #0x10`, but reading the
 *     raw halfword keeps it live in a fifth register across the whole
 *     function and was the last 105 bytes of the diff; using the field
 *     lets the compiler re-derive it and closes the function outright.
 * The p[0x118] flag field is the same bits[2:16) register PALANM_StepFadeWait
 * uses, as the note suspected.
 */
void PALANM_StepFadeValue(PaletteFade *p, u32 idx, PaletteFadeParam *s)
{
    u32 bit;
    s32 v;

    if (s->current == s->end) {
        bit = 1 << idx;
        if (p->requestBits & bit) {
            p->requestBits ^= bit;
        }
        return;
    }

    if (!s->direction) {
        v = (s16)((s16)s->current + (s32)s->speed);
        if (v > (s32)s->end) {
            v = (s16)s->end;
        }
        s->current = v;
    } else {
        v = (s16)((s16)s->current - (s32)s->speed);
        if (v < (s32)s->end) {
            v = (s16)s->end;
        }
        s->current = v;
    }
}

/*
 * The apply pass of the slot object: walks the 14 channel records and pushes
 * each one's current value out through the graphics-engine setter that the
 * channel index selects (a dense 14-entry halfword switch table at
 * 0x02021DBA). Runs only when the +0x11A field's top bit is set or the
 * +0x118 field's mode is 1.
 *
 * Two types are load-bearing. `i` must be u32 for the switch's own range
 * guard to come out `cmp #0xd; bhi` (signed makes it a `bgt`/`bhi` pair),
 * but the loop's own bound must be compared signed -- `(int)i < 14` -- or
 * the back edge is `bhs` where the original has `bge`. And the bit index
 * handed to PALANM_CheckBit is truncated, `(u16)i`, which is the
 * `lsls #0x10 / lsrs #0x10` pair at +0x3E.
 *
 * The final `if` re-reads p->transBits out of memory rather than reusing the
 * value just stored; testing p->requestBits instead loses the reload.
 *
 * EXACT* only: 392 bytes compiled and correct throughout. The listing's
 * 532-byte extent runs past the literal pool at 0x02021ED0 into a run of
 * unlabelled leaf accessors starting at 0x02021EE4 (none saves lr, so
 * disasm.py never labelled them; the first is
 * `movs r1,#0x46; lsls r1,#2; ldrh r0,[r0,r1]; lsls #0x10; lsrs #0xc;
 * bx lr`). Worth seeding into layout/function_starts.txt; reported rather
 * than edited here.
 */
void PALANM_TransferPalettes(PaletteFade *p)
{
    PaletteFadeWork *c;
    u32 k;
    u32 i;

    if (p->autoTrans == 0 && p->requestFlag != 1) {
        return;
    }

    k = 0x2000;
    for (i = 0; (int)i < 14; i++) {
        if (p->autoTrans == 0) {
            if (p->work[i].transWork == 0) {
                continue;
            }
            if (PALANM_CheckBit(p->transBits, (u16)i) == 0) {
                continue;
            }
        }
        c = &p->work[i];
        DC_FlushRange(c->transWork, c->size);
        switch (i) {
        case 0:
            GX_LoadBGPltt(c->transWork, 0, c->size);
            break;
        case 1:
            GXS_LoadBGPltt(c->transWork, 0, c->size);
            break;
        case 2:
            GX_LoadOBJPltt(c->transWork, 0, c->size);
            break;
        case 3:
            GXS_LoadOBJPltt(c->transWork, 0, c->size);
            break;
        case 4:
            GX_BeginLoadBGExtPltt();
            GX_LoadBGExtPltt(c->transWork, 0, c->size);
            GX_EndLoadBGExtPltt();
            break;
        case 5:
            GX_BeginLoadBGExtPltt();
            GX_LoadBGExtPltt(c->transWork, k, c->size);
            GX_EndLoadBGExtPltt();
            break;
        case 6:
            GX_BeginLoadBGExtPltt();
            GX_LoadBGExtPltt(c->transWork, 0x4000, c->size);
            GX_EndLoadBGExtPltt();
            break;
        case 7:
            GX_BeginLoadBGExtPltt();
            GX_LoadBGExtPltt(c->transWork, 0x6000, c->size);
            GX_EndLoadBGExtPltt();
            break;
        case 8:
            GXS_BeginLoadBGExtPltt();
            GXS_LoadBGExtPltt(c->transWork, 0, c->size);
            GXS_EndLoadBGExtPltt();
            break;
        case 9:
            GXS_BeginLoadBGExtPltt();
            GXS_LoadBGExtPltt(c->transWork, k, c->size);
            GXS_EndLoadBGExtPltt();
            break;
        case 10:
            GXS_BeginLoadBGExtPltt();
            GXS_LoadBGExtPltt(c->transWork, 0x4000, c->size);
            GXS_EndLoadBGExtPltt();
            break;
        case 11:
            GXS_BeginLoadBGExtPltt();
            GXS_LoadBGExtPltt(c->transWork, 0x6000, c->size);
            GXS_EndLoadBGExtPltt();
            break;
        case 12:
            GX_BeginLoadOBJExtPltt();
            GX_LoadOBJExtPltt(c->transWork, 0, c->size);
            GX_EndLoadOBJExtPltt();
            break;
        case 13:
            GXS_BeginLoadOBJExtPltt();
            GXS_LoadOBJExtPltt(c->transWork, 0, c->size);
            GXS_EndLoadOBJExtPltt();
            break;
        }
    }

    p->transBits = p->requestBits;
    if (p->transBits == 0) {
        p->requestFlag = 0;
    }
}

u32 PALANM_GetFadeRequestBits(const PaletteFade *ptr)
{
    return ptr->requestBits;
}

/*
 * EXACT*: the inferred extent ran to 0x02021F64 because the next function,
 * at 0x02021F08, saves no lr and so carries no label.  0x02021F08 is an
 * unlabelled follower and wants seeding into layout/function_starts.txt.
 *
 * An unlabelled leaf setter (saves no lr).  Writes the top bit of the
 * halfword at +0x11a from the low bit of the argument.  The pool words are
 * plain literals: 0x0000011A (the offset, past the Thumb ldrh immediate
 * reach of +62, see docs/idioms/thumb-immediate-reach-costs-an-adds.md) and
 * 0xFFFF7FFF (the clear mask), neither a relocation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PALANM_SetAutoTransfer.c \
 *       --func PALANM_SetAutoTransfer --addr 0x02021EE4 --cc 1.1p1 --thumb
 */
void PALANM_SetAutoTransfer(PaletteFade *o, int v)
{
    o->autoTrans = (u16)v;
}

/*
 * An unlabelled leaf (push {r3, r4} for alignment only, no lr save), newly
 * seeded as the follower of PALANM_SetAutoTransfer.  Arms the palette-animation
 * header at +0x118: sets the 2-bit mode field from the low bit of the
 * argument and then turns on all fourteen channel bits above it.
 *
 * The header halfword is the same `requestFlag:2, requestBits:14` pair PALANM_FadeTask
 * and PALANM_TransferPalettes use.  The two pool words are plain literals, not
 * relocations: 0xFFFF0003 is the requestBits clear mask and 0x0000FFFC the
 * all-ones requestBits value written back, exactly the `<< 2` bitfield insert.
 *
 * EXACT*: 52 bytes compiled (44 of code plus the two pool words at
 * 0x02021F34/0x02021F38), against a 92-byte inferred extent that runs on
 * into the unlabelled `.word` run before PALANM_BlendColors.
 *
 * The `(v & 1)` is narrowed to u16 before the field store (`lsls #0x10 /
 * lsrs #0x10` at +0x10), which is what an `int` argument masked into a
 * 2-bit u16 bitfield produces; a u16 parameter loses the pair.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PALANM_RequestFullTransfer.c \
 *       --func PALANM_RequestFullTransfer --addr 0x02021F08 --cc 1.1p1 --thumb
 */
void PALANM_RequestFullTransfer(PaletteFade *o, int v)
{
    o->requestFlag = (u16)(v & 1);
    o->requestBits = 0x3FFF;
}

/*
 * Witness leaf for ov071 MONOLITH_TOOL_UpdateHighlight (tiny unlabelled arm9 leaf).
 */
u16 PALANM_GetColor(PaletteFadeWork *s, int idx, int which, u16 pos)
{
    if (which == 1) {
        return s[idx].defaultWork[pos];
    }
    if (which == 0) {
        return s[idx].transWork[pos];
    }
    return 0;
}

/*
 * A per-pixel RGB555 alpha-blend loop, same family as PALANM_CalcFadeColors and
 * PALANM_ApplyFade: each channel of src[i] is pulled toward the corresponding
 * channel of `color` by `weight`/16 and the three results repacked into
 * dst[i].  `color` is the fifth argument and arrives on the caller's stack
 * (the entry `add r0,sp,#0x20; ldrh r0,[r0]`).
 *
 * No relocations: the function calls nothing and reads no globals.
 *
 * EXACT*, not EXACT: the next function has no label, so the inferred extent
 * runs two bytes long (116 vs the 114 compiled, the difference being the
 * alignment halfword at 0x02021FD6).
 *
 * Two levers, both recorded in docs/notes/PALANM_BlendColors.c.txt:
 *   - the per-pixel channels must be read through a bitfield pointer into
 *     src[i] itself, ((struct Rgb555 *)&src[i])->r, not through a value-copy
 *     union: the copy spills the pixel to a stack slot the image never uses.
 *   - `weight` is a SIGNED int.  As u32 the products (t - s) * weight become
 *     unsigned and the three `>> 4` compile to `lsrs`; the image has `asrs`
 *     at +0x3E, +0x4A and +0x54.  That signedness was the whole residue.
 */
void PALANM_BlendColors(u16 *src, u16 *dst, u32 count, int weight,
                   u16 color)
{
    u16 i;
    int tr = ((struct Rgb555 *)&color)->r;
    int tg = ((struct Rgb555 *)&color)->g;
    int tb = ((struct Rgb555 *)&color)->b;

    for (i = 0; i < count; i++) {
        int sr = ((struct Rgb555 *)&src[i])->r;
        int sg = ((struct Rgb555 *)&src[i])->g;
        int sb = ((struct Rgb555 *)&src[i])->b;
        int rb = sb + ((tb - sb) * weight >> 4);
        int rr = sr + ((tr - sr) * weight >> 4);
        int rg = sg + ((tg - sg) * weight >> 4);

        dst[i] = (u16)(rr | (rg << 5) | (rb << 10));
    }
}

/*
 * Thin forwarding wrapper: picks channel `idx` out of the 0x14-byte record
 * array, advances both of its pointers by `c` halfwords, and hands them to
 * the RGB555 blend loop at 0x02021F64 (see docs/notes/PALANM_BlendColors.c.txt --
 * that function is still a documented DIFF, so this wrapper's own
 * relocation is attested by the `label` class, not by a matched entry).
 * Arguments 5 and 6 arrive on the caller's stack and must be u8 / u16, which
 * is what makes them `ldrb [r5]` and `ldrh [r5, #4]`.
 *
 * EXACT* only: 42 bytes compiled, the listing extent is 44 -- the two extra
 * bytes are the `00 00` alignment halfword at 0x02022002, not a follower.
 */
void PALANM_BlendChannel(PaletteFadeWork *p, u32 idx, u32 c, u32 count,
                   u8 weight, u16 color)
{
    PALANM_BlendColors(p[idx].defaultWork + c, p[idx].transWork + c, count, weight, color);
}

void PALANM_BlendChannelMask(PaletteFadeWork *p, u32 idx, u16 mask, u8 weight, u16 color)
{
    u32 i = 0;

    if (mask == 0) {
        return;
    }
    do {
        if (mask & 1) {
            PALANM_BlendChannel(p, idx, (u16)i, 0x10, weight, color);
        }
        mask = (u16)(mask >> 1);
        i += 0x10;
    } while (mask != 0);
}

void PALANM_ConvertGrayTable(u16 *pal, int n, const u8 *table)
{
    int i;
    int r, g, b;
    u8 v;

    for (i = 0; i < n; i++) {
        r = *pal & 0x1f;
        g = (*pal >> 5) & 0x1f;
        b = (*pal >> 10) & 0x1f;
        v = table[(r * 76 + g * 151 + b * 29) >> 8];
        *pal = (v << 10) | (v << 5) | v;
        pal++;
    }
}
