/*
 * file:     ica_anime.c
 * unit:     yes
 * function: ICA_ANIME_CreateWithFullBuffer, ICA_ANIME_CreateWithStreamBuffer, ICA_ANIME_CreateFull, ICA_ANIME_CreateStream, ICA_ANIME_Delete, ICA_ANIME_IncFrameLoop, ICA_ANIME_IncFrameNoLoop, ICA_ANIME_SetFrame, ICA_ANIME_GetFrameNum, ICA_ANIME_GetFrame, ICA_ANIME_GetTranslate, ICA_ANIME_GetRotate, ICA_ANIME_GetScale, ICA_ANIME_GetTranslateAt, ICA_ANIME_Clear, ICA_ANIME_LoadHeader, ICA_ANIME_AllocBuffer, ICA_ANIME_SetBuffer, ICA_ANIME_LoadFrames, ICA_ANIME_SetCameraStatus, ICA_ANIME_SetCameraPos, ICA_ANIME_SetCameraTarget
 * address:  0x02011428
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from ica_anime.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GFL_HEAP_Alloc   0x02030734  arm
 *   ICA_ANIME_AllocBuffer  0x02011770  thumb
 *   _IcaAnimeFileName  0x020A7270  data
 *   ARC_TOOL_DeleteHandle     0x02049238  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   ARC_TOOL_ReadHandleMemberRange  0x0204944C  arm
 *   _ffixu         0x0209C4C8  arm
 *   _IcaCameraForward  0x0209DF84  data
 *   _IcaCameraUp  0x0209DF90  data
 *   G3D_CAMERA_SetEye  0x02048AFC  arm
 *   G3D_CAMERA_SetCamUp  0x02048B20  arm
 *   G3D_CAMERA_SetCamTarget  0x02048B44  arm
 *   BUTTON_MAN_MakeRotMtxXYZ  0x020520FC  arm
 *   MTX_MultVec33  0x0207B51C  arm
 *   VEC_Add  0x0207C9D0  arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   _fdiv                        0x0209CE10  arm
 *   _ffix                        0x0209C494  arm
 *   _fflt                        0x0209BDBC  arm
 *   _fgr                         0x0209BBB0  arm
 *   _fls                         0x0209BC74  arm
 *   _fmul                        0x0209C77C  arm
 *   _u32_div_f                   0x0209C2B0  arm
 */
#include "script_vm_types.h"
#include "vm_shared_types.h"
#include "ica_anime_shared_types.h"

struct IcaAnime;

struct ArcFile;

#include "../sdk_fx.h"

/*
 * ICA camera animation (0x38 bytes): per-frame translate, rotate and scale
 * tracks read from an archive member, buffered bufFrameNum frames at a time
 * starting at bufTopFrame.
 */
struct IcaAnime {
    u16 heapId;
    u16 reserved02;
    struct ArcFile *arcHandle;
    u32 dataId;
    u32 frameNum;
    s32 frame;
    s32 bufTopFrame;
    s32 bufFrameNum;
    struct VecFx32 *transBuf;
    struct VecFx32 *rotBuf;
    struct VecFx32 *scaleBuf;
    u32 hasTrans;
    u32 hasRot;
    u32 hasScale;
    u32 bufAllocated;
};

#include "gfl_heap_wrap.h"



#include "arc_tool.h"
struct ArcHandle;


#include "g3d_camera.h"



#include "button_man.h"

#include "fx_mtx33.h"

#include "fx_vec.h"

struct IcaAnime *ICA_ANIME_CreateWithFullBuffer(u32 heapId, u32 arcId, u32 dataId, void *buffer, u32 bufferSize);

struct IcaAnime *ICA_ANIME_CreateWithStreamBuffer(u32 heapId, u32 arcId, u32 dataId, u32 bufFrameNum, void *buffer, u32 bufferSize);

struct IcaAnime *ICA_ANIME_CreateFull(u32 heapId, u32 arcId, u32 dataId);

struct IcaAnime *ICA_ANIME_CreateStream(u32 heapId, u32 arcId, u32 dataId, u32 bufFrameNum);

void ICA_ANIME_Delete(struct IcaAnime *anime);

u32 ICA_ANIME_IncFrameLoop(struct IcaAnime *anime, s32 step);

u32 ICA_ANIME_IncFrameNoLoop(struct IcaAnime *anime, s32 step);

void ICA_ANIME_SetFrame(struct IcaAnime *anime, s32 frame);

u32 ICA_ANIME_GetFrameNum(struct IcaAnime *anime);

u32 ICA_ANIME_GetFrame(struct IcaAnime *anime);

u32 ICA_ANIME_GetTranslate(struct IcaAnime *anime, struct VecFx32 *trans);

u32 ICA_ANIME_GetRotate(struct IcaAnime *anime, struct VecFx32 *rot);

u32 ICA_ANIME_GetScale(struct IcaAnime *anime, struct VecFx32 *scale);

u32 ICA_ANIME_GetTranslateAt(struct IcaAnime *anime, struct VecFx32 *trans, u32 frame);

void ICA_ANIME_Clear(struct IcaAnime *anime);

void ICA_ANIME_LoadHeader(struct IcaAnime *anime, u32 arcId, u32 dataId, u32 heapId);

void ICA_ANIME_AllocBuffer(struct IcaAnime *anime, int bufFrameNum);

int ICA_ANIME_SetBuffer(struct IcaAnime *anime, int bufFrameNum, u8 *buffer, int bufferSize);

void ICA_ANIME_LoadFrames(struct IcaAnime *anime, s32 frame);

void ICA_ANIME_SetCameraStatus(void *camera, struct IcaAnime *anime);

void ICA_ANIME_SetCameraPos(void *camera, struct IcaAnime *anime);

void ICA_ANIME_SetCameraTarget(void *camera, struct IcaAnime *anime);

extern const char _IcaAnimeFileName[];

extern struct VecFx32 _IcaCameraForward;

extern struct VecFx32 _IcaCameraUp;

/*
 * ica_anime.c's 0x38-byte-object constructor: allocate, shared init, the
 * class-specific initialiser, then the load call.  Only the load call's
 * result is tested, so the failure path is the plain `return 0` and the
 * success path stores through the sibling and returns the object.  The
 * +0x0c field is re-read after ICA_ANIME_LoadHeader because the callee sets it.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ICA_ANIME_CreateWithFullBuffer.c \
 *       --func ICA_ANIME_CreateWithFullBuffer --addr 0x02011428 --cc 1.1p1 --thumb
 */
struct IcaAnime *ICA_ANIME_CreateWithFullBuffer(u32 heapId, u32 arcId, u32 dataId, void *buffer, u32 bufferSize)
{
    struct IcaAnime *anime = GFL_HEAP_Alloc(heapId, sizeof(struct IcaAnime), 0, _IcaAnimeFileName, 0x54);

    ICA_ANIME_Clear(anime);
    ICA_ANIME_LoadHeader(anime, arcId, dataId, heapId);
    if (ICA_ANIME_SetBuffer(anime, anime->frameNum, buffer, bufferSize) == 0) {
        return 0;
    }
    ICA_ANIME_LoadFrames(anime, 0);
    return anime;
}

/*
 * The 0x74-byte sibling of ICA_ANIME_CreateWithFullBuffer in the same original file: same
 * allocation, shared init and class initialiser, but the load call forwards
 * the two stacked arguments rather than a field.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ICA_ANIME_CreateWithStreamBuffer.c \
 *       --func ICA_ANIME_CreateWithStreamBuffer --addr 0x0201147C --cc 1.1p1 --thumb
 */
struct IcaAnime *ICA_ANIME_CreateWithStreamBuffer(u32 heapId, u32 arcId, u32 dataId, u32 bufFrameNum, void *buffer, u32 bufferSize)
{
    struct IcaAnime *anime = GFL_HEAP_Alloc(heapId, sizeof(struct IcaAnime), 0, _IcaAnimeFileName, 0x74);

    ICA_ANIME_Clear(anime);
    ICA_ANIME_LoadHeader(anime, arcId, dataId, heapId);
    if (ICA_ANIME_SetBuffer(anime, bufFrameNum, buffer, bufferSize) == 0) {
        return 0;
    }
    ICA_ANIME_LoadFrames(anime, 0);
    return anime;
}

/*
 * ica_anime.c: the third constructor (line 0x90 of "ica_anime.c").  The
 * object is 0x38 bytes and the four-argument initialiser gets the heap back
 * as its last argument, which is where r3 = r5 comes from.  ICA_ANIME_Clear gets
 * the object straight from the allocator, which is why no move precedes it.
 *
 * The tail is the pair every one of these constructors ends with -
 * ICA_ANIME_AllocBuffer(anime, anime->frameNum) and ICA_ANIME_LoadFrames(anime, 0).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ICA_ANIME_CreateFull.c \
 *       --func ICA_ANIME_CreateFull --addr 0x020114D0 --cc 1.1p1 --thumb
 */
struct IcaAnime *ICA_ANIME_CreateFull(u32 heapId, u32 arcId, u32 dataId)
{
    struct IcaAnime *anime;

    anime = GFL_HEAP_Alloc(heapId, sizeof(struct IcaAnime), 0, _IcaAnimeFileName, 0x90);
    ICA_ANIME_Clear(anime);
    ICA_ANIME_LoadHeader(anime, arcId, dataId, heapId);
    ICA_ANIME_AllocBuffer(anime, anime->frameNum);
    ICA_ANIME_LoadFrames(anime, 0);
    return anime;
}

/*
 * ica_anime.c, the third constructor of the group: same prologue, same
 * 0x38-byte allocation (a different source line), but the class
 * initialiser is ICA_ANIME_AllocBuffer and the result is not tested - it always
 * runs the shared teardown initialiser and returns the object.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ICA_ANIME_CreateStream.c \
 *       --func ICA_ANIME_CreateStream --addr 0x02011510 --cc 1.1p1 --thumb
 */
struct IcaAnime *ICA_ANIME_CreateStream(u32 heapId, u32 arcId, u32 dataId, u32 bufFrameNum)
{
    struct IcaAnime *anime = GFL_HEAP_Alloc(heapId, sizeof(struct IcaAnime), 0, _IcaAnimeFileName, 0xae);

    ICA_ANIME_Clear(anime);
    ICA_ANIME_LoadHeader(anime, arcId, dataId, heapId);
    ICA_ANIME_AllocBuffer(anime, bufFrameNum);
    ICA_ANIME_LoadFrames(anime, 0);
    return anime;
}

/*
 * ica_anime.c: destroy.  The one field that is a plain pointer (+0x04) goes
 * through the archive/handle call first, and the three heap buffers at
 * +0x1C, +0x20 and +0x24 are released only when the 0x34 flag says they were
 * allocated - all four calls are the same free function, including the last
 * one on the object itself.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02011558.c \
 *       --addr 0x02011558 --thumb
 *   (tu, not one: the last two bytes of the extent are the linker's
 *    alignment padding up to the next function, which `one` reports as a
 *    size mismatch and would mark EXACT*.  The code itself is 54/22 bytes.)
 */
void ICA_ANIME_Delete(struct IcaAnime *anime)
{
    ARC_TOOL_DeleteHandle(anime->arcHandle);
    if (anime->bufAllocated != 0) {
        if (anime->transBuf != 0)
            GFL_HEAP_Free(anime->transBuf);
        if (anime->rotBuf != 0)
            GFL_HEAP_Free(anime->rotBuf);
        if (anime->scaleBuf != 0)
            GFL_HEAP_Free(anime->scaleBuf);
    }
    GFL_HEAP_Free(anime);
}

/*
 * ica_anime.c, 0x02011590..0x02011610: the frame-clock advance and its two
 * neighbours, plus the two four-byte getters that sit between them (they
 * carry no label because they have no prologue, so they are written here as
 * what they are).
 *
 *   ICA_ANIME_IncFrameLoop   advance the clock, reset it if the frame count is
 *                   reached, and poke the animation when the new frame falls
 *                   outside [bufTopFrame, bufTopFrame + bufFrameNum)
 *   ICA_ANIME_IncFrameNoLoop   the same advance but returning "already finished" when
 *                   the frame at entry is past the count
 *   ICA_ANIME_SetFrame   set the clock outright
 *   (0x02011608)    getter: +0x0C
 *   (0x0201160C)    getter: +0x10
 *
 * The range check is one disjunction in every case: the original reaches the
 * single `bl ICA_ANIME_LoadFrames` from both compares.
 *
 * Signedness: the frame index is `frame >> 12` with an arithmetic shift
 * (asrs), but the compare against frameNum is unsigned (bhi/bhs), so frameNum
 * is a u32 field while frame, bufTopFrame and bufFrameNum are s32.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02011590.c \
 *       --addr 0x02011590 --thumb
 */
u32 ICA_ANIME_IncFrameLoop(struct IcaAnime *anime, s32 step)
{
    s32 frameIndex;
    u32 looped = 0;

    anime->frame = anime->frame + step;
    frameIndex = anime->frame >> 12;
    if (anime->frameNum <= (u32)frameIndex) {
        anime->frame = 0;
        frameIndex = 0;
        looped = 1;
    }
    if (frameIndex < anime->bufTopFrame || (anime->bufTopFrame + anime->bufFrameNum) <= frameIndex)
        ICA_ANIME_LoadFrames(anime, anime->frame);
    return looped;
}

u32 ICA_ANIME_IncFrameNoLoop(struct IcaAnime *anime, s32 step)
{
    s32 frameIndex = anime->frame >> 12;

    if ((u32)frameIndex < anime->frameNum) {
        anime->frame = anime->frame + step;
        frameIndex = anime->frame >> 12;
        if (frameIndex < anime->bufTopFrame || (anime->bufTopFrame + anime->bufFrameNum) <= frameIndex)
            ICA_ANIME_LoadFrames(anime, anime->frame);
        return 0;
    }
    return 1;
}

void ICA_ANIME_SetFrame(struct IcaAnime *anime, s32 frame)
{
    s32 frameIndex = frame >> 12;

    anime->frame = frame;
    if (frameIndex < anime->bufTopFrame || (anime->bufTopFrame + anime->bufFrameNum) <= frameIndex)
        ICA_ANIME_LoadFrames(anime, frame);
}

u32 ICA_ANIME_GetFrameNum(struct IcaAnime *anime)
{
    return anime->frameNum;
}

u32 ICA_ANIME_GetFrame(struct IcaAnime *anime)
{
    return anime->frame;
}

/*
 * ica_anime.c, 0x02011610..0x02011688: three copies of one accessor on three
 * parallel field pairs, each of which copies a twelve-byte record out of a
 * table indexed by the current frame.
 *
 *   ICA_ANIME_GetTranslate   guard +0x28, table +0x1C
 *   ICA_ANIME_GetRotate   guard +0x2C, table +0x20
 *   (0x02011660)    guard +0x30, table +0x24 - unlabelled in the listing
 *                   (no prologue: the function saves nothing), written here
 *                   as the third copy
 *
 * The index is `(frame >> 12) - bufTopFrame`, which is why the original does an asrs
 * by twelve and then a subtract before the multiply by twelve, and the copy
 * itself is one twelve-byte struct assignment (ldm/stm pair plus the third
 * word).  Returning 0 when the table pointer is null is what makes the two
 * epilogues.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02011610.c \
 *       --addr 0x02011610 --thumb
 */
u32 ICA_ANIME_GetTranslate(struct IcaAnime *anime, struct VecFx32 *trans)
{
    if (anime->hasTrans != 0) {
        *trans = anime->transBuf[(anime->frame >> 12) - anime->bufTopFrame];
        return 1;
    }
    return 0;
}

u32 ICA_ANIME_GetRotate(struct IcaAnime *anime, struct VecFx32 *rot)
{
    if (anime->hasRot != 0) {
        *rot = anime->rotBuf[(anime->frame >> 12) - anime->bufTopFrame];
        return 1;
    }
    return 0;
}

u32 ICA_ANIME_GetScale(struct IcaAnime *anime, struct VecFx32 *scale)
{
    if (anime->hasScale != 0) {
        *scale = anime->scaleBuf[(anime->frame >> 12) - anime->bufTopFrame];
        return 1;
    }
    return 0;
}

/*
 * Copy frame `idx % count` of the transBuf VecFx32 table out to dst when the table
 * length at +0x18 equals the count at +0x0C; returns 1, else 0.  EXACT* because
 * the listing extent (56) includes the 2-byte `movs r0, r0` pad after the
 * second epilogue; the 54 code bytes are exact.
 *
 * Load-bearing (wave 20, after five waves at 14 to 26 out):
 *  - `idx %= n;` writes the remainder back into the PARAMETER, which homes it
 *    in r2 (`adds r2, r1, #0` before the compare).  A named local coalesces
 *    with the helper's r1 return instead.
 *  - the table base as an integer: `u32 src = (u32)anime->transBuf;` with a u32 byte
 *    offset `off = idx * 12`, the first field read at base + off and the
 *    cursor advanced in place (`base += off`) for +4 and +8.  With the base as
 *    an integer the multiply goes into a copy of idx (`adds r3, r2, #0;
 *    muls r3, r0, r3`) and the base is loaded after 12, as in the image;
 *    every pointer spelling (&transBuf[frame], t[frame], a struct cursor) multiplies
 *    idx in place.  Same family as
 *    docs/idioms/a-region-symbol-cast-to-u32-keeps-the-bound-an-add.md.
 *  - the two-return shape `if (==) { ...; return 1; } return 0;` gives the
 *    image's fall-through body and its two epilogues.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ICA_ANIME_GetTranslateAt.c \
 *       --func ICA_ANIME_GetTranslateAt --addr 0x02011688 --cc 1.1p1 --thumb
 */
u32 ICA_ANIME_GetTranslateAt(struct IcaAnime *anime, struct VecFx32 *trans, u32 frame)
{
    u32 frameNum = anime->frameNum;

    frame %= frameNum;
    if (anime->bufFrameNum == frameNum) {
        /* stand-in: the image adds the byte offset after the first load;
           transBuf[frame].x/.y/.z is 4 bytes longer, a VecFx32 pointer 4 bytes shorter */
#ifdef __MWERKS__
        u32 offset = frame * sizeof(struct VecFx32);
        u32 src = (uptr)anime->transBuf;

        trans->x = *(s32 *)(src + offset);
        src += offset;
        trans->y = ((struct VecFx32 *)src)->y;
        trans->z = ((struct VecFx32 *)src)->z;
#else
        const struct VecFx32 *src = (const struct VecFx32 *)anime->transBuf + frame;

        trans->x = src->x;
        trans->y = src->y;
        trans->z = src->z;
#endif
        return 1;
    }
    return 0;
}

void ICA_ANIME_Clear(struct IcaAnime *anime)
{
    anime->heapId = 0;
    anime->arcHandle = 0;
    anime->dataId = 0;
    anime->frameNum = 0;
    anime->frame = 0;
    anime->bufTopFrame = 0;
    anime->bufFrameNum = 0;
    anime->transBuf = 0;
    anime->rotBuf = 0;
    anime->scaleBuf = 0;
    anime->hasTrans = 0;
    anime->hasRot = 0;
    anime->hasScale = 0;
    anime->bufAllocated = 0;
}

/*
 * Open four channels: a halfword tag at +0, a handset object at +4, a peer
 * object at +8, and then ARC_TOOL_ReadHandleMemberRange(arcHandle, dataId, offset, len, dest) for
 * ids 0, 4, 5 and 6 -- the last three writing one byte each into buf[2],
 * buf[1] and buf[0], i.e. backwards from the end of the four-byte buffer.
 *
 * `v = 1;` is a SEPARATE statement after the four calls, not the
 * declaration initialiser.  As `u32 v = 1;` at the top of the body the
 * assignment is hoisted to the function entry (r6 = 1 before the first
 * call, the zero constant landing in r4), and the result is a diff of two
 * instructions at the end: the original keeps 1 in r4 (the register the
 * dead a2 parameter was homed to) and the 0 in r6, and the guard stores
 * `r4 = r6` on the equal arm instead of `r6 = r4`.  Sinking the assignment
 * to its own statement after the last call reproduces the original
 * allocation exactly.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ICA_ANIME_LoadHeader.c \
 *       --func ICA_ANIME_LoadHeader --addr 0x020116E0 --cc 1.1p1 --thumb
 */
void ICA_ANIME_LoadHeader(struct IcaAnime *anime, u32 arcId, u32 dataId, u32 heapId)
{
    u8 channelFlags[4];
    u32 hasScale;

    anime->heapId = (u16)heapId;
    anime->arcHandle = ARC_TOOL_CreateHandle(arcId, heapId);
    anime->dataId = dataId;
    ARC_TOOL_ReadHandleMemberRange((struct ArcHandle *)anime->arcHandle, dataId, 0, 4, &anime->frameNum);
    ARC_TOOL_ReadHandleMemberRange((struct ArcHandle *)anime->arcHandle, anime->dataId, 4, 1, channelFlags + 2);
    ARC_TOOL_ReadHandleMemberRange((struct ArcHandle *)anime->arcHandle, anime->dataId, 5, 1, channelFlags + 1);
    ARC_TOOL_ReadHandleMemberRange((struct ArcHandle *)anime->arcHandle, anime->dataId, 6, 1, channelFlags);
    hasScale = 1;
    if (channelFlags[2] == 0) {
        hasScale = 0;
    }
    anime->hasScale = hasScale;
    anime->hasRot = (channelFlags[1] != 0);
    anime->hasTrans = (channelFlags[0] != 0);
}

void ICA_ANIME_AllocBuffer(struct IcaAnime *anime, int bufFrameNum)
{
    anime->bufFrameNum = bufFrameNum;
    if (anime->hasTrans != 0) {
        anime->transBuf = GFL_HEAP_Alloc(anime->heapId, bufFrameNum * sizeof(struct VecFx32),
                                        0, _IcaAnimeFileName, 0x25c);
    }
    if (anime->hasRot != 0) {
        anime->rotBuf = GFL_HEAP_Alloc(anime->heapId, bufFrameNum * sizeof(struct VecFx32),
                                      0, _IcaAnimeFileName, 0x260);
    }
    if (anime->hasScale != 0) {
        anime->scaleBuf = GFL_HEAP_Alloc(anime->heapId, bufFrameNum * sizeof(struct VecFx32),
                                        0, _IcaAnimeFileName, 0x264);
    }
    anime->bufAllocated = 1;
}

/*
 * Carve the caller's buffer into the translate, rotate and scale tracks
 * (bufFrameNum VecFx32 each), only for the tracks the header enables.
 * bufferSize is the caller's byte budget: if it is smaller than
 * bufFrameNum * 12 times the number of enabled tracks nothing is written and
 * the call answers 0.  bufFrameNum is recorded in the object.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ICA_ANIME_SetBuffer.c \
 *       --func ICA_ANIME_SetBuffer --addr 0x020117D8 --cc 1.1p1 --thumb
 */
int ICA_ANIME_SetBuffer(struct IcaAnime *anime, int bufFrameNum, u8 *buffer, int bufferSize)
{
    int needSize;
    int trackSize;
    int track;

    needSize = 0;
    trackSize = bufFrameNum * sizeof(struct VecFx32);
    track = 0;
    if (anime->hasTrans != 0) {
        needSize += trackSize;
    }
    if (anime->hasRot != 0) {
        needSize += trackSize;
    }
    if (anime->hasScale != 0) {
        needSize += trackSize;
    }
    if (bufferSize < needSize) {
        return 0;
    }
    if (anime->hasTrans != 0) {
        anime->transBuf = (struct VecFx32 *)buffer;
        track++;
    }
    if (anime->hasRot != 0) {
        anime->rotBuf = (struct VecFx32 *)(buffer + trackSize * track);
        track++;
    }
    if (anime->hasScale != 0) {
        anime->scaleBuf = (struct VecFx32 *)(buffer + trackSize * track);
        track++;
    }
    anime->bufFrameNum = bufFrameNum;
    return 1;
}

#define FX_F32_TO_FX32(x) ((s32)(((x) > 0) ? ((x) * 4096.0f + .5f) : ((x) * 4096.0f - .5f)))

/*
 * Load a window of an ICA animation: the frame index is (frame >> 12) modulo
 * anime->frameNum; the file offset is 8 + 12 * index per enabled track and
 * the read size 12 * anime->bufFrameNum per enabled track.  The floats are
 * read into a scratch buffer (ARC_TOOL_ReadHandleMemberRange, fifth argument = destination),
 * converted with the TwlSDK FX_F32_TO_FX32 macro into the three VecFx32 tables
 * (hasScale gates scaleBuf, hasRot rotBuf, hasTrans transBuf), then freed;
 * anime->bufTopFrame = frame >> 12.
 *
 * Levers (wave 10), each measured; together 631 bytes out -> EXACT:
 *  - 0x0209C95C is _fadd and 0x0209CB8C is _fsub (layout/runtime_arm9.txt
 *    had them swapped until 2026-09-28).  With them declared that way the
 *    plain SDK macro `x > 0 ? x*4096.0f + .5f : x*4096.0f - .5f` reproduces
 *    both arms, including the (0.5, prod) / (prod, 0.5) argument orders.
 *  - the conversion is a MACRO over `floats[value + j]`, not an inline
 *    function, and the buffer is `volatile float *` (stand-in: plain RAM, but
 *    without volatile the element is loaded once; the image loads it for the
 *    compare and again in the taken arm, off a byte offset that gets its own
 *    stack slot per site, the nine slots sp+0x18..0x38).
 *  - ARC_TOOL_ReadHandleMemberRange takes five arguments; the fifth is the buffer ([sp]).
 *  - `frame >> 12` is written twice (the modulo and the final store) and
 *    never named: its CSE temporary takes the lowest spill slot (sp+4).  A
 *    named index local lands above the i*12 temporaries (14 bytes out).
 *  - `i = 0` sits between the alloc and the fill call (the image stores it
 *    there, sharing the alloc's zero), and the loop is `for (; i < ...)`.
 *  - declaration order frameIdx, value, floats, size, offset, index.
 */
void ICA_ANIME_LoadFrames(struct IcaAnime *anime, s32 frame)
{
    s32 frameIdx;
    s32 value;
    volatile float *floats;
    u32 size;
    u32 offset;
    u32 index;

    index = (frame >> 12) % anime->frameNum;

    offset = 8;
    size = 0;
    if (anime->hasScale != 0) offset += index * 0xc;
    if (anime->hasRot != 0) offset += index * 0xc;
    if (anime->hasTrans != 0) offset += index * 0xc;
    if (anime->hasScale != 0) size += anime->bufFrameNum * 0xc;
    if (anime->hasRot != 0) size += anime->bufFrameNum * 0xc;
    if (anime->hasTrans != 0) size += anime->bufFrameNum * 0xc;

    floats = (volatile float *)GFL_HEAP_Alloc((u16)((anime->heapId & 0x7fff) | 0x8000), size, 0, _IcaAnimeFileName, 0x2bd);
    frameIdx = 0;
    ARC_TOOL_ReadHandleMemberRange((struct ArcHandle *)anime->arcHandle, anime->dataId, offset, size, (void *)floats);

    value = 0;
    for (; frameIdx < anime->bufFrameNum; frameIdx++) {
        if (anime->hasScale != 0) {
            anime->scaleBuf[frameIdx].x = FX_F32_TO_FX32(floats[value]);
            anime->scaleBuf[frameIdx].y = FX_F32_TO_FX32(floats[value + 1]);
            anime->scaleBuf[frameIdx].z = FX_F32_TO_FX32(floats[value + 2]);
            value += 3;
        }
        if (anime->hasRot != 0) {
            anime->rotBuf[frameIdx].x = FX_F32_TO_FX32(floats[value]);
            anime->rotBuf[frameIdx].y = FX_F32_TO_FX32(floats[value + 1]);
            anime->rotBuf[frameIdx].z = FX_F32_TO_FX32(floats[value + 2]);
            value += 3;
        }
        if (anime->hasTrans != 0) {
            anime->transBuf[frameIdx].x = FX_F32_TO_FX32(floats[value]);
            anime->transBuf[frameIdx].y = FX_F32_TO_FX32(floats[value + 1]);
            anime->transBuf[frameIdx].z = FX_F32_TO_FX32(floats[value + 2]);
            value += 3;
        }
    }
    GFL_HEAP_Free((void *)floats);
    anime->bufTopFrame = frame >> 12;
}

/*
 * Sets a camera from the current ICA frame: the rotate track gives three
 * angles in degrees (fx 4.12); each is converted to float, wrapped into
 * 0..360 by repeated addition, rescaled to the 0..65535 angle units
 * BUTTON_MAN_MakeRotMtxXYZ wants, and turned into a rotation matrix.  The two constant
 * vectors _IcaCameraForward and _IcaCameraUp (copied in as whole 12-byte
 * aggregates, ldm/stm) are rotated by it; the translate track gives the
 * camera position, position + rotated forward the target, and the rotated
 * up vector the camera up.
 *
 * Shape notes that cost real time and are worth keeping:
 *   - the three angle values must be bound to named `u16' locals
 *     before the BUTTON_MAN_MakeRotMtxXYZ call.  Written inline as
 *     `(u16)(u32)(65535.0f * (h / 360.0f))' the lsls/lsrs #0x10 pair
 *     after each _ffixu disappears (about 10 bytes short).
 *   - the scratch the two MTX_MultVec33 calls share is a whole MtxFx33 (36
 *     bytes); a single VecFx32 comes out `sub sp, #0x68' instead of
 *     `sub sp, #0x80'.
 *   - the wrap-around is `h += 360.0f': 0x0209C95C is the soft-float
 *     add.  `h = h + 360.0f' puts the constant first (see docs/idioms/
 *     a-soft-float-add-puts-the-constant-first-unless-it-is-a-compound-
 *     assignment.md) and no longer matches.
 *   - declaration order is stack order: rotMtx highest, then rotDeg,
 *     forward, up, position, target, rotForward, rotUp.  Any other order shifts every sp offset.
 */
void ICA_ANIME_SetCameraStatus(void *camera, struct IcaAnime *anime)
{
    MtxFx33 rotMtx;
    struct VecFx32 rotDeg;
    struct VecFx32 forward;
    struct VecFx32 up;
    struct VecFx32 position;
    struct VecFx32 target;
    struct VecFx32 rotForward;
    struct VecFx32 rotUp;
    u16 angleX;
    u16 angleY;
    u16 angleZ;
    float degX;
    float degY;
    float degZ;

    forward = _IcaCameraForward;
    up = _IcaCameraUp;

    ICA_ANIME_GetRotate(anime, &rotDeg);

    degX = rotDeg.x / 4096.0f;
    degY = rotDeg.y / 4096.0f;
    degZ = rotDeg.z / 4096.0f;

    while (degX < 0.0f) {
        degX += 360.0f;
    }
    while (degY < 0.0f) {
        degY += 360.0f;
    }
    while (degZ < 0.0f) {
        degZ += 360.0f;
    }

    angleX = (u16)(u32)(65535.0f * (degX / 360.0f));
    angleY = (u16)(u32)(65535.0f * (degY / 360.0f));
    angleZ = (u16)(u32)(65535.0f * (degZ / 360.0f));
    BUTTON_MAN_MakeRotMtxXYZ(angleX, angleY, angleZ, &rotMtx);

    MTX_MultVec33(&forward, &rotMtx, &rotForward);
    MTX_MultVec33(&up, &rotMtx, &rotUp);

    ICA_ANIME_GetTranslate(anime, &position);
    VEC_Add(&position, &rotForward, &target);

    G3D_CAMERA_SetEye(camera, &position);
    G3D_CAMERA_SetCamTarget(camera, &target);
    G3D_CAMERA_SetCamUp(camera, &rotUp);
}

/*
 * Twelve bytes of stack filled by ICA_ANIME_GetTranslate from the *second* argument
 * (the first word handed to it is r1, not r0), then the buffer goes to the ARM
 * function G3D_CAMERA_SetEye together with the original first argument.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ICA_ANIME_SetCameraPos.c \
 *       --func ICA_ANIME_SetCameraPos --addr 0x02011CF0 --cc 1.1p1 --thumb
 */
void ICA_ANIME_SetCameraPos(void *camera, struct IcaAnime *anime)
{
    struct VecFx32 position;

    ICA_ANIME_GetTranslate(anime, &position);
    G3D_CAMERA_SetEye(camera, &position);
}

/*
 * Identical to ICA_ANIME_SetCameraPos except for the second callee, G3D_CAMERA_SetCamTarget.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ICA_ANIME_SetCameraTarget.c \
 *       --func ICA_ANIME_SetCameraTarget --addr 0x02011D0C --cc 1.1p1 --thumb
 */
void ICA_ANIME_SetCameraTarget(void *camera, struct IcaAnime *anime)
{
    struct VecFx32 target;

    ICA_ANIME_GetTranslate(anime, &target);
    G3D_CAMERA_SetCamTarget(camera, &target);
}
