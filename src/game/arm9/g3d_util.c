/*
 * file:     g3d_util.c
 * unit:     yes
 * function: G3D_UTIL_Create, G3D_UTIL_Delete, G3D_UTIL_AddUnit, G3D_UTIL_AddUnitLoaded, G3D_UTIL_AddUnitFromArchive, G3D_UTIL_RemoveUnit, G3D_UTIL_LoadUnitResources, G3D_UTIL_LoadUnitResourcesFromArchive, G3D_UTIL_FreeUnitResources, G3D_UTIL_BuildUnitObjects, G3D_UTIL_BuildUnitObjectsLoaded, G3D_UTIL_FreeUnitObjects, G3D_UTIL_GetUnitObjIdx, G3D_UTIL_GetUnitObjCount, G3D_UTIL_GetResource, G3D_UTIL_GetObject
 * address:  0x02047CFC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from g3d_util.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc      0x02030734  arm
 *   GFL_HEAP_Free   0x020307B0  arm
 *   g3d_util_file  0x020A7EB8  data
 *   G3D_SYSTEM_GetResourceSize 0x02046C94 arm
 *   G3D_SYSTEM_InitResourceByFile 0x02046CE0 arm
 *   G3D_SYSTEM_CreateResourceArc 0x02046DB8 arm
 *   G3D_SYSTEM_CreateResourceArcHandle 0x02046E24 arm
 *   G3D_SYSTEM_CreateResourcePath 0x02046E90 arm
 *   G3D_SYSTEM_DeleteResource 0x02046EFC arm
 *   G3D_SYSTEM_CheckResourceType 0x02046F50 arm
 *   G3D_SYSTEM_TransVramTexture 0x02046FF8 arm
 *   G3D_SYSTEM_FreeVramTexture 0x020470D0 arm
 *   G3D_SYSTEM_IsTextureInVram 0x02047348 arm
 *   G3D_SYSTEM_CreateRender 0x02047400 arm
 *   G3D_SYSTEM_DeleteRender 0x02047504 arm
 *   G3D_SYSTEM_GetRenderMdlRes 0x0204754C arm
 *   G3D_SYSTEM_GetRenderTexRes 0x02047554 arm
 *   G3D_SYSTEM_CreateAnime 0x02047564 arm
 *   G3D_SYSTEM_DeleteAnime 0x0204762C arm
 *   G3D_SYSTEM_CreateObject 0x0204767C arm
 *   G3D_SYSTEM_DeleteObject 0x02047738 arm
 *   G3D_SYSTEM_GetObjectRender 0x02047788 arm
 *   G3D_SYSTEM_GetObjectAnime 0x02047790 arm
 *   G3D_SYSTEM_GetObjectAnimeCount 0x0204779C arm
 *   ARC_TOOL_LoadMember 0x02048F60 arm arm9
 *   ARC_TOOL_LoadMemberFromPath 0x02048F9C arm arm9
 */
#include "g3d_util_shared_types.h"
#include "g3d_util_types.h"

struct G3dNodeInit;

struct G3dResourceRef;

struct G3dRenderObj;

struct G3dAnim;

struct G3dNode;

struct G3dNode {
    u16 tag;
    u16 kind;
    u32 link;
    void *owner;
};

struct G3dNodeInit {
    u16 status;
    u16 result;
    u32 *tag;
};

struct G3dResourceRef {
    u16   tag;
    u16   kind;
    void *buf;
};

struct G3dModelRef {
    u8    pad_00[4];
    void *data;
};

struct G3dResHandle {
    u32 pad_00;
    u32 handle;
};

struct G3dRenderObj {
    u32            pad_00;
    struct G3dResHandle *texture;
    u32            pad_08;
    struct G3dResHandle *model;
};

struct G3dAnim {
    u16 tag;
    u16 kind;
    u32 link;
    const struct G3dRenderObj *renderObj;
};


/* Kept local: the heap id is a u16 here (gfl_heap_wrap.h takes u32). */
#ifdef __MWERKS__
extern void *GFL_HEAP_Alloc(u16 heapID, u32 size, int clear, const char *file, int line); /* original prototype; the definition differs in argument width */
extern u32 GFL_HEAP_Free(void *p);
#else
#include "gfl_heap_wrap.h"
#endif


#include "nns_g3d_anm_calc_types.h"
#include "nns_g3d_anm_types.h"
#include "../sdk_fx.h"
#include "../sdk_nnsfnd.h"
#include "g3d_system.h"

#ifdef __MWERKS__
void G3D_SYSTEM_InitResourceByFile(struct G3dNodeInit *out, u32 *tag); /* original prototype; the definition differs in pointer type */
#else
struct G3dResource;
struct NNSG3dResFileHeader;
void G3D_SYSTEM_InitResourceByFile(struct G3dResource *res, struct NNSG3dResFileHeader *file);
#define G3D_SYSTEM_InitResourceByFile(out, file) (G3D_SYSTEM_InitResourceByFile)((struct G3dResource *)(out), (struct NNSG3dResFileHeader *)(file))
#endif
struct G3dResource;

struct ArcHandle;







struct G3dRender;




struct G3dAnime;


struct G3dObject;






G3dUtil *G3D_UTIL_Create(u16 resCount, u16 objCount, u16 heapID);

void G3D_UTIL_Delete(G3dUtil *util);

u16 G3D_UTIL_AddUnit(G3dUtil *util, const G3dUtilSetup *setup);

u16 G3D_UTIL_AddUnitLoaded(G3dUtil *util, const G3dUtilSetup *setup);

u16 G3D_UTIL_AddUnitFromArchive(G3dUtil *util, const G3dUtilSetup *setup, struct ArcHandle *extra);

void G3D_UTIL_RemoveUnit(G3dUtil *util, u32 i);

void G3D_UTIL_LoadUnitResources(G3dUtil *util, u16 index, const G3dUtilSetup *setup, u16 heapID);

void G3D_UTIL_LoadUnitResourcesFromArchive(G3dUtil *util, u16 index, const G3dUtilSetup *setup, u32 heapID, struct ArcHandle *arc);

void G3D_UTIL_FreeUnitResources(G3dUtil *util, u32 index);

void G3D_UTIL_BuildUnitObjects(G3dUtil *util, u16 unitIdx, const G3dUtilSetup *setup, u16 heapID);

void G3D_UTIL_BuildUnitObjectsLoaded(G3dUtil *util, u16 unitIdx, const G3dUtilSetup *setup, u16 heapID);

void G3D_UTIL_FreeUnitObjects(G3dUtil *util, u32 unitIdx);

u32 G3D_UTIL_GetUnitObjIdx(G3dUtil *util, int i);

u32 G3D_UTIL_GetUnitObjCount(G3dUtil *util, int i);

u32 G3D_UTIL_GetResource(G3dUtil *util, int i);

u32 G3D_UTIL_GetObject(G3dUtil *util, int i);

#include "arc_tool.h"


extern const char g3d_util_file[];

/*
 * g3d_util.c (the __FILE__ word 0x020A7EB8 of this family).  The utility
 * object is 0x218 bytes: resource handle table and status bytes at +0x00 /
 * +0x04 with a u16 count at +0x08, object table and status bytes at +0x0c /
 * +0x10 with a u16 count at +0x14, 0x40 eight-byte unit records from +0x16
 * {resIdx, resCount, objIdx, objCount}, and the u16 heap id at +0x216.  See
 * docs/families/g3d_util.h.
 *
 * Create the utility object: allocate it, the two handle tables and the two
 * status arrays (__LINE__ 92, 97, 98, 105, 106), clear the status bytes and
 * mark all 0x40 unit records free with 0xffff.  The three parameters are
 * u16 (resource count, object count, heap id); with s32 parameters the
 * compiler CSEs the second half's constants and the frame loses a register.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/G3D_UTIL_Create.c --func G3D_UTIL_Create --addr 0x02047CFC --cc 1.1p1 --arm
 */
G3dUtil *G3D_UTIL_Create(u16 resCount, u16 objCount, u16 heapID)
{
    G3dUtil *util;
    int i;

    util = GFL_HEAP_Alloc(heapID, sizeof(G3dUtil), 1, g3d_util_file, 92);
    util->heapID = heapID;

    util->res = GFL_HEAP_Alloc(heapID, resCount * 4, 1, g3d_util_file, 97);
    util->resStat = GFL_HEAP_Alloc(heapID, resCount, 1, g3d_util_file, 98);
    util->resCount = resCount;
    for (i = 0; i < resCount; i++)
        util->resStat[i] = 0;

    util->obj = GFL_HEAP_Alloc(heapID, objCount * 4, 1, g3d_util_file, 105);
    util->objStat = GFL_HEAP_Alloc(heapID, objCount, 1, g3d_util_file, 106);
    util->objCount = objCount;
    for (i = 0; i < objCount; i++)
        util->objStat[i] = 0;

    for (i = 0; i < 0x40; i++) {
        util->unit[i].resIdx = 0xffff;
        util->unit[i].resCount = 0xffff;
        util->unit[i].objIdx = 0xffff;
        util->unit[i].objCount = 0xffff;
    }
    return util;
}

/*
 * Free the four pointers of one record, in decreasing address order, and
 * then the record itself.  The object pointer is the only callee-saved
 * value, which is why the frame is two words.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/G3D_UTIL_Delete.c \
 *       --func G3D_UTIL_Delete --addr 0x02047E54 --cc 1.1p1 --arm
 */
void G3D_UTIL_Delete(G3dUtil *util)
{
    GFL_HEAP_Free(util->objStat);
    GFL_HEAP_Free(util->obj);
    GFL_HEAP_Free(util->resStat);
    GFL_HEAP_Free(util->res);
    GFL_HEAP_Free(util);
}

/*
 * g3d_util.c (the __FILE__ word 0x020A7EB8 of this family).  The utility
 * object is 0x218 bytes: resource handle table and status bytes at +0x00 /
 * +0x04 with a u16 count at +0x08, object table and status bytes at +0x0c /
 * +0x10 with a u16 count at +0x14, 0x40 eight-byte unit records from +0x16
 * {resIdx, resCount, objIdx, objCount}, and the u16 heap id at +0x216.  See
 * docs/families/g3d_util.h.
 *
 * Add one unit: take the first free record (resIdx == 0xffff), place its
 * resource and object runs right after the previous record's, then load the
 * resources (G3D_UTIL_LoadUnitResources) and build the objects (G3D_UTIL_BuildUnitObjects).  The lever
 * that closed it is the prototypes: the unit index and heap id are u16
 * parameters of both callees, so each call site truncates `i` on its own
 * (the lsl/lsr pair appears twice plus once for the u16 return), which an
 * explicit (u16) cast does not reproduce.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/G3D_UTIL_AddUnit.c --func G3D_UTIL_AddUnit --addr 0x02047E88 --cc 1.1p1 --arm
 */
u16 G3D_UTIL_AddUnit(G3dUtil *util, const G3dUtilSetup *setup)
{
    u16 resIdx = 0;
    u16 objIdx = 0;
    int i;

    for (i = 0; i < 0x40; i++) {
        if (util->unit[i].resIdx == 0xffff) {
            util->unit[i].resIdx = resIdx;
            util->unit[i].resCount = setup->resCount;
            util->unit[i].objIdx = objIdx;
            util->unit[i].objCount = setup->objCount;
            G3D_UTIL_LoadUnitResources(util, i, setup, util->heapID);
            G3D_UTIL_BuildUnitObjects(util, i, setup, util->heapID);
            return i;
        }
        resIdx = util->unit[i].resIdx + util->unit[i].resCount;
        objIdx = util->unit[i].objIdx + util->unit[i].objCount;
    }
    return 0xffff;
}

/*
 * g3d_util.c (the __FILE__ word 0x020A7EB8 of this family).  The utility
 * object is 0x218 bytes: resource handle table and status bytes at +0x00 /
 * +0x04 with a u16 count at +0x08, object table and status bytes at +0x0c /
 * +0x10 with a u16 count at +0x14, 0x40 eight-byte unit records from +0x16
 * {resIdx, resCount, objIdx, objCount}, and the u16 heap id at +0x216.  See
 * docs/families/g3d_util.h.
 *
 * Twin of G3D_UTIL_AddUnit with the second callee G3D_UTIL_BuildUnitObjectsLoaded (the object
 * builder that binds textures itself); same u16 prototype lever.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/G3D_UTIL_AddUnitLoaded.c --func G3D_UTIL_AddUnitLoaded --addr 0x02047F4C --cc 1.1p1 --arm
 */
u16 G3D_UTIL_AddUnitLoaded(G3dUtil *util, const G3dUtilSetup *setup)
{
    u16 resIdx = 0;
    u16 objIdx = 0;
    int i;

    for (i = 0; i < 0x40; i++) {
        if (util->unit[i].resIdx == 0xffff) {
            util->unit[i].resIdx = resIdx;
            util->unit[i].resCount = setup->resCount;
            util->unit[i].objIdx = objIdx;
            util->unit[i].objCount = setup->objCount;
            G3D_UTIL_LoadUnitResources(util, i, setup, util->heapID);
            G3D_UTIL_BuildUnitObjectsLoaded(util, i, setup, util->heapID);
            return i;
        }
        resIdx = util->unit[i].resIdx + util->unit[i].resCount;
        objIdx = util->unit[i].objIdx + util->unit[i].objCount;
    }
    return 0xffff;
}

/*
 * g3d_util.c (the __FILE__ word 0x020A7EB8 of this family).  The utility
 * object is 0x218 bytes: resource handle table and status bytes at +0x00 /
 * +0x04 with a u16 count at +0x08, object table and status bytes at +0x0c /
 * +0x10 with a u16 count at +0x14, 0x40 eight-byte unit records from +0x16
 * {resIdx, resCount, objIdx, objCount}, and the u16 heap id at +0x216.  See
 * docs/families/g3d_util.h.
 *
 * Third twin: the resource loader is G3D_UTIL_LoadUnitResourcesFromArchive, which takes a fifth
 * argument forwarded from this function's third parameter.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/G3D_UTIL_AddUnitFromArchive.c --func G3D_UTIL_AddUnitFromArchive --addr 0x02048010 --cc 1.1p1 --arm
 */
u16 G3D_UTIL_AddUnitFromArchive(G3dUtil *util, const G3dUtilSetup *setup, struct ArcHandle *archive)
{
    u16 resIdx = 0;
    u16 objIdx = 0;
    int i;

    for (i = 0; i < 0x40; i++) {
        if (util->unit[i].resIdx == 0xffff) {
            util->unit[i].resIdx = resIdx;
            util->unit[i].resCount = setup->resCount;
            util->unit[i].objIdx = objIdx;
            util->unit[i].objCount = setup->objCount;
            G3D_UTIL_LoadUnitResourcesFromArchive(util, i, setup, util->heapID, archive);
            G3D_UTIL_BuildUnitObjectsLoaded(util, i, setup, util->heapID);
            return i;
        }
        resIdx = util->unit[i].resIdx + util->unit[i].resCount;
        objIdx = util->unit[i].objIdx + util->unit[i].objCount;
    }
    return 0xffff;
}

/*
 * PARKED AT MATCH.  Every one of the 60 concrete bytes is right; the PC24 at
 * +0x000C is wildcarded because 0x02048918 has exactly one branch reference
 * image wide and it is that call, so no cut of a one-function range frees it.
 * Blocking evidence class: label/matched, no outside witness.  The site
 * unsticks the moment 0x02048918 (220 bytes, packet pkt_02048330) is itself
 * EXACT -- the `matched` class then resolves it with no change to this C.
 * The sibling site, the call to 0x020482B4 at +0x0018, resolves today
 * (`matched`, src/matched/G3D_UTIL_FreeUnitResources.c).
 *
 * Seed one OAM slot of a cell actor and stamp four -1 halfwords into the
 * 8-byte record the actor keeps for it: the two calls initialise the slot and
 * the four stores write the record at +0x16 of the indexed base, which is why
 * the index scales by 8 (`lsl #3`) while the displacement 0x16 rides the
 * stores.  The -1 cannot be encoded as a halfword immediate, so it takes the
 * pool word 0x0000ffff and is loaded once for all four stores.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/G3D_UTIL_RemoveUnit.c \
 *       --func G3D_UTIL_RemoveUnit --addr 0x020480E4 --cc 1.1p1 --arm
 */
void G3D_UTIL_RemoveUnit(G3dUtil *util, u32 unitIdx)
{
    G3D_UTIL_FreeUnitObjects(util, unitIdx);
    G3D_UTIL_FreeUnitResources(util, unitIdx);
    util->unit[unitIdx].resIdx = -1;
    util->unit[unitIdx].resCount = -1;
    util->unit[unitIdx].objIdx = -1;
    util->unit[unitIdx].objCount = -1;
}

/*
 * Load one row of resources for the 3D utility rig.  The 8-byte slot at
 * `rig + index * 8` names a run of the handle array at `rig->f00`: the u16 at
 * +0x18 is the count and the u16 at +0x16 is the first index.  Each element is
 * described by a 0xc-byte record in `desc->f00`, whose +8 word selects the
 * source:
 *
 *   0  a plain archive member by id            (G3D_SYSTEM_CreateResourceArc)
 *   1  the same id through the second table    (G3D_SYSTEM_CreateResourcePath)
 *   2  a heap-allocated node wrapping a member read by archive id
 *   3  the same, with the member read by path
 *
 * The heap id is the u16 at `rig + 0x200 + 0x16`, re-read at every use, and
 * `rig->f00` is re-read once per iteration because G3D_SYSTEM_InitResourceByFile may store
 * through it.  The __FILE__ argument is "g3d_util.c" at 0x020A7EB8.
 *
 * The two __LINE__ values are 342 and 355; the image hoists 355 out of the
 * loop as one pool word and derives 342 from it with `sub r0, r0, #0xd`,
 * spilling the result once
 * (docs/idioms/consecutive-line-numbers-are-one-pool-word-and-adds.md).
 *
 * The rig's config base (`rig + 0x200`) must NOT be a named local: binding it
 * to one schedules `add r8, fp, #0x200` ahead of the empty-row guard, where
 * the image computes it after the `pople`.  Spelled as a re-evaluated inline
 * accessor the compiler sinks it below the guard and the whole 312 bytes
 * match.  Declaration order of the remaining locals is slotno/out/i/rec,
 * which is what puts them in r4/r5/r6/r7
 * (docs/idioms/declaration-order-decides-which-register-a-local-gets.md).
 * Probed once under `../2.0/sp2` on the one-instruction scheduling residue:
 * 340 bytes, 290 out -- not a pinned file, the fix is the C.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/G3D_UTIL_LoadUnitResources.c \
 *       --func G3D_UTIL_LoadUnitResources --addr 0x02048120 --cc 1.1p1 --arm
 */
void G3D_UTIL_LoadUnitResources(G3dUtil *util, u16 unitIdx, const G3dUtilSetup *setup, u16 heapID)
{
    int count = util->unit[unitIdx].resCount;
    u32 base = util->unit[unitIdx].resIdx;
    u32 slotno;
    u32 *out;
    int i;
    const G3dUtilResSetup *rec;
    void *node;

    for (i = 0; i < count; i++) {
        out = (u32 *)util->res;
        slotno = base + i;
        rec = &setup->resTbl[i];

        switch (rec->type) {
        case 0:
            out[slotno] = (uptr)G3D_SYSTEM_CreateResourceArc(rec->arc, rec->dat);
            break;
        case 1:
            out[slotno] = (uptr)G3D_SYSTEM_CreateResourcePath((char *)rec->arc, rec->dat);
            break;
        case 2:
            node = GFL_HEAP_Alloc(util->heapID, G3D_SYSTEM_GetResourceSize(), 0,
                                 g3d_util_file, 342);
            G3D_SYSTEM_InitResourceByFile(node,
                          (u32 *)((uptr)ARC_TOOL_LoadMember(rec->arc, rec->dat,
                                             util->heapID)));
            out[slotno] = (uptr)node;
            break;
        case 3:
            node = GFL_HEAP_Alloc(util->heapID, G3D_SYSTEM_GetResourceSize(), 0,
                                 g3d_util_file, 355);
            G3D_SYSTEM_InitResourceByFile(node,
                          (u32 *)((uptr)ARC_TOOL_LoadMemberFromPath((const char *)rec->arc, rec->dat,
                                             util->heapID)));
            out[slotno] = (uptr)node;
            break;
        }
    }
}

/*
 * Build one row of the array the slot record at `owner + index * 8`
 * describes: the u16 at +0x18 is the element count and the u16 at +0x16 is
 * the row's first index, and each element is the result of G3D_SYSTEM_CreateResourceArcHandle
 * on the corresponding 0xc-byte record's +4 halfword, with the caller's
 * fifth argument forwarded as its first.
 *
 * The count is signed in the original (`cmp` plus `pople` for the empty
 * row, `blt` on the back edge), and the destination is written through the
 * owner's own +0 pointer, re-read once per iteration because the callee may
 * store it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/G3D_UTIL_LoadUnitResourcesFromArchive.c \
 *       --func G3D_UTIL_LoadUnitResourcesFromArchive --addr 0x02048258 --cc 1.1p1 --arm
 */
void G3D_UTIL_LoadUnitResourcesFromArchive(G3dUtil *util, u16 unitIdx, const G3dUtilSetup *setup, u32 heapID,
                   struct ArcHandle *arc)
{
    u16 count = util->unit[unitIdx].resCount;
    u16 base = util->unit[unitIdx].resIdx;
    int i;

    for (i = 0; i < count; i++) {
        ((u32 *)util->res)[base + i] =
            (uptr)G3D_SYSTEM_CreateResourceArcHandle(arc, setup->resTbl[i].dat);
    }
}

/*
 * Tear down one row of the array: for each of the slot record's +0x18
 * elements (starting at the +0x16 index) that is not null, clear the
 * matching byte of the owner's second array (base + index), then run
 * G3D_SYSTEM_CheckResourceType with mode 2 and, only when it answers exactly one,
 * G3D_SYSTEM_FreeVramTexture, and finally G3D_SYSTEM_DeleteResource on the element either way.
 *
 * The same signed count and `blt` back edge as G3D_UTIL_LoadUnitResourcesFromArchive, and the same
 * re-read of the owner's element pointer per iteration.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/G3D_UTIL_FreeUnitResources.c \
 *       --func G3D_UTIL_FreeUnitResources --addr 0x020482B4 --cc 1.1p1 --arm
 */
void G3D_UTIL_FreeUnitResources(G3dUtil *util, u32 unitIdx)
{
    u16 count = util->unit[unitIdx].resCount;
    u16 base = util->unit[unitIdx].resIdx;
    int i;

    for (i = 0; i < count; i++) {
        u32 res = ((u32 *)util->res)[base + i];

        if (res != 0) {
            util->resStat[base + i] = 0;

            if (G3D_SYSTEM_CheckResourceType((struct G3dResource *)res, 2) == 1)
                G3D_SYSTEM_FreeVramTexture((struct G3dResource *)res);

            G3D_SYSTEM_DeleteResource((struct G3dResource *)res);
        }
    }
}

static inline void createRes(G3dUtil *util, const G3dUtilResSetup *rs, void **out)
{
    switch (rs->type) {
    case 0:
        *out = G3D_SYSTEM_CreateResourceArc(rs->arc, rs->dat);
        break;
    case 1:
        *out = G3D_SYSTEM_CreateResourcePath((char *)rs->arc, rs->dat);
        break;
    case 2:
        *out = GFL_HEAP_Alloc(util->heapID, G3D_SYSTEM_GetResourceSize(), 0, g3d_util_file, 342);
        G3D_SYSTEM_InitResourceByFile(*out, ARC_TOOL_LoadMember(rs->arc, rs->dat, util->heapID));
        break;
    case 3:
        *out = GFL_HEAP_Alloc(util->heapID, G3D_SYSTEM_GetResourceSize(), 0, g3d_util_file, 355);
        G3D_SYSTEM_InitResourceByFile(*out, ARC_TOOL_LoadMemberFromPath((const char *)rs->arc, rs->dat, util->heapID));
        break;
    }
}

static inline int getRes(G3dUtil *util, u16 resIdx, u16 idx, const G3dUtilSetup *setup, void **out)
{
    if (util->resStat[resIdx + idx] == 1) {
        createRes(util, &setup->resTbl[idx], out);
        return 1;
    } else {
        util->resStat[resIdx + idx] = 1;
        *out = util->res[resIdx + idx];
        return 0;
    }
}

/*
 * g3d_util.c (the __FILE__ word 0x020A7EB8 of this family).  The utility
 * object is 0x218 bytes: resource handle table and status bytes at +0x00 /
 * +0x04 with a u16 count at +0x08, object table and status bytes at +0x0c /
 * +0x10 with a u16 count at +0x14, 0x40 eight-byte unit records from +0x16
 * {resIdx, resCount, objIdx, objCount}, and the u16 heap id at +0x216.  See
 * docs/families/g3d_util.h.
 *
 * Build the objects of one unit, loading any model or texture resource the
 * unit's resource status says is still pending.  Per object: resolve the
 * model through getRes (load it by its setup record's type when its status
 * byte is 1, else mark it and take the loaded handle), set bit 0 of the
 * object status when it had to be loaded; resolve the texture the same way
 * when it is a separate resource that answers G3D_SYSTEM_CheckResourceType(res, 1) == 1
 * (bit 1, then G3D_SYSTEM_TransVramTexture), bind them with G3D_SYSTEM_CreateRender, build the
 * animation array in a low-heap scratch block (__LINE__ 534) and create the
 * object with G3D_SYSTEM_CreateObject.
 *
 * The two inline helpers are the lever: createRes writes its result
 * through the caller's out pointer in every case (no local result), which
 * is what keeps the model handle in its stack home [sp,#0x14] and the
 * texture handle in fp without a copy.  With a helper that returns the
 * handle the compiler adds a register copy after each inlined switch
 * (1048 bytes).  The switch is the one G3D_UTIL_LoadUnitResources carries, __LINE__ 342
 * and 355 (the second copy derives 355 from the live constant 1 with rsb).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/G3D_UTIL_BuildUnitObjects.c --func G3D_UTIL_BuildUnitObjects --addr 0x02048330 --cc 1.1p1 --arm
 */
void G3D_UTIL_BuildUnitObjects(G3dUtil *util, u16 unitIdx, const G3dUtilSetup *setup, u16 heapID)
{
    u16 resIdx = util->unit[unitIdx].resIdx;
    u16 objIdx = util->unit[unitIdx].objIdx;
    u16 objCount = util->unit[unitIdx].objCount;
    void *model;
    void *texture;
    void *renderObj;
    void **anims;
    const G3dUtilObjSetup *objSetup;
    void *anim;
    int i, j;

    for (i = 0; i < objCount; i++) {
        objSetup = &setup->objTbl[i];
        if (getRes(util, resIdx, setup->objTbl[i].mdlResIdx, setup, &model) == 1)
            util->objStat[objIdx + i] |= 1;
        if (objSetup->texResIdx != objSetup->mdlResIdx) {
            if (G3D_SYSTEM_CheckResourceType(util->res[resIdx + objSetup->texResIdx], 1) == 1) {
                if (getRes(util, resIdx, objSetup->texResIdx, setup, &texture) == 1) {
                    util->objStat[objIdx + i] |= 2;
                    G3D_SYSTEM_TransVramTexture(texture);
                }
            } else {
                texture = util->res[resIdx + objSetup->texResIdx];
                G3D_SYSTEM_TransVramTexture(texture);
            }
        } else {
            texture = model;
            if (G3D_SYSTEM_IsTextureInVram(model) == 0)
                G3D_SYSTEM_TransVramTexture(model);
        }
        renderObj = G3D_SYSTEM_CreateRender(model, objSetup->mdlDatIdx, texture);
        anims = GFL_HEAP_Alloc((heapID & 0x7fff) | 0x8000, objSetup->anmCount * 4, 1,
                            g3d_util_file, 534);
        for (j = 0; j < objSetup->anmCount; j++) {
            if (objSetup->anmTbl[j].anmResIdx == 0xff)
                anim = 0;
            else
                anim = G3D_SYSTEM_CreateAnime(renderObj, util->res[resIdx + objSetup->anmTbl[j].anmResIdx],
                                  objSetup->anmTbl[j].anmDatIdx);
            anims[j] = anim;
        }
        util->obj[objIdx + i] = G3D_SYSTEM_CreateObject(renderObj, (struct G3dAnime **)anims, objSetup->anmCount);
        GFL_HEAP_Free(anims);
    }
}

static inline void *getResSlot(G3dUtil *util, u16 resIdx, u16 idx)
{
    return util->res[resIdx + idx];
}

static inline void *useRes(G3dUtil *util, u16 resIdx, u16 idx)
{
    util->resStat[resIdx + idx] = 1;
    return util->res[resIdx + idx];
}

/*
 * g3d_util.c, same utility object as G3D_UTIL_BuildUnitObjects (see that file and
 * docs/families/g3d_util.h).  Build the render objects of one unit whose
 * resources are already loaded: per object, mark the model resource used,
 * resolve the texture resource (mark it used when G3D_SYSTEM_CheckResourceType reports type
 * 1, else release it through G3D_SYSTEM_TransVramTexture; a shared model/texture resource is
 * released when G3D_SYSTEM_IsTextureInVram reports 0), create the render object, allocate
 * and fill its animation array (0xff = no animation), bind them into the
 * object slot, and free the array.
 *
 * Register lever (waves 16-21, 14 bytes out at best): with plain `int i, j`
 * the outer counter colours before the inner counter (i r8, objTbl/j sb, the
 * image has i sb, objTbl/j r8); `long i, j` swaps resIdx and i instead.  The
 * increment spelled as a null-based pointer step,
 * `i = (int)((char *)0 + i + 1)`, emits the same `add sb, sb, #1` but moves
 * i's loop-carried web to the end of the colouring order, exactly as a
 * sign-extending `short i` did at the cost of 8 bytes.  `(u8 *)0` is equally
 * EXACT; `(int)((char *)i + 1)`, `(int)((u8 *)0 + (i + 1))` and
 * `(int)&((u8 *)0)[i + 1]` stay at 18 (wave 21, lane D4).
 */
void G3D_UTIL_BuildUnitObjectsLoaded(G3dUtil *util, u16 unitIdx, const G3dUtilSetup *setup, u16 heapID)
{
    u16 resIdx = util->unit[unitIdx].resIdx;
    u16 objIdx = util->unit[unitIdx].objIdx;
    u16 objCount = util->unit[unitIdx].objCount;
    void *model;
    void *texture;
    void *renderObj;
    void **anims;
    const G3dUtilObjSetup *objSetup;
    void *anim;
    int i, j;

    for (i = 0; i < objCount; i = (sptr)((char *)0 + i + 1)) {
        objSetup = &setup->objTbl[i];
        model = useRes(util, resIdx, setup->objTbl[i].mdlResIdx);
        if (objSetup->texResIdx != setup->objTbl[i].mdlResIdx) {
            if (G3D_SYSTEM_CheckResourceType(getResSlot(util, resIdx, objSetup->texResIdx), 1) == 1) {
                texture = useRes(util, resIdx, objSetup->texResIdx);
            } else {
                texture = getResSlot(util, resIdx, objSetup->texResIdx);
                G3D_SYSTEM_TransVramTexture(texture);
            }
        } else {
            texture = model;
            if (G3D_SYSTEM_IsTextureInVram(model) == 0)
                G3D_SYSTEM_TransVramTexture(model);
        }
        renderObj = G3D_SYSTEM_CreateRender(model, objSetup->mdlDatIdx, texture);
        anims = GFL_HEAP_Alloc((heapID & 0x7fff) | 0x8000, objSetup->anmCount * 4, 1,
                            g3d_util_file, 609);
        for (j = 0; j < objSetup->anmCount; j++) {
            if (objSetup->anmTbl[j].anmResIdx == 0xff)
                anim = 0;
            else
                anim = G3D_SYSTEM_CreateAnime(renderObj, getResSlot(util, resIdx, objSetup->anmTbl[j].anmResIdx),
                                  objSetup->anmTbl[j].anmDatIdx);
            anims[j] = anim;
        }
        util->obj[objIdx + i] = G3D_SYSTEM_CreateObject(renderObj, (struct G3dAnime **)anims, objSetup->anmCount);
        GFL_HEAP_Free(anims);
    }
}

/*
 * g3d_util.c (the __FILE__ word 0x020A7EB8 of this family).  The utility
 * object is 0x218 bytes: resource handle table and status bytes at +0x00 /
 * +0x04 with a u16 count at +0x08, object table and status bytes at +0x0c /
 * +0x10 with a u16 count at +0x14, 0x40 eight-byte unit records from +0x16
 * {resIdx, resCount, objIdx, objCount}, and the u16 heap id at +0x216.  See
 * docs/families/g3d_util.h.
 *
 * Delete the objects of one unit: per object take the render object
 * (0x02047788) and the animation count (0x0204779C), delete every animation
 * (0x0204762C on 0x02047790's result), release the texture paths chosen by
 * the status byte, then delete the render object and the object.  The
 * listing extent (268) runs into the unlabelled accessors of
 * src/matched/unit_020489F4.c, hence EXACT* until 0x020489F4 is seeded.
 * The one register tie documented in docs/notes/pkt_02048330.c.txt closed
 * with the library shape plus `rnd` declared before `obj`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/G3D_UTIL_FreeUnitObjects.c --func G3D_UTIL_FreeUnitObjects --addr 0x02048918 --cc 1.1p1 --arm
 */
void G3D_UTIL_FreeUnitObjects(G3dUtil *util, u32 unitIdx)
{
    u16 objIdx = util->unit[unitIdx].objIdx;
    u16 objCount = util->unit[unitIdx].objCount;
    void *renderObj;
    void *object;
    u16 anmCount;
    int i, j;

    for (i = 0; i < objCount; i++) {
        object = util->obj[objIdx + i];
        renderObj = (void *)G3D_SYSTEM_GetObjectRender(object);
        anmCount = G3D_SYSTEM_GetObjectAnimeCount(object);
        for (j = 0; j < anmCount; j++)
            G3D_SYSTEM_DeleteAnime((struct G3dAnime *)G3D_SYSTEM_GetObjectAnime(object, (u16)j));
        if (util->objStat[objIdx + i] & 0xfd) {
            void *texture = (void *)G3D_SYSTEM_GetRenderTexRes(renderObj);
            G3D_SYSTEM_FreeVramTexture(texture);
            G3D_SYSTEM_DeleteResource(texture);
        }
        if (util->objStat[objIdx + i] & 0xfe)
            G3D_SYSTEM_DeleteResource((struct G3dResource *)G3D_SYSTEM_GetRenderMdlRes(renderObj));
        G3D_SYSTEM_DeleteRender(renderObj);
        G3D_SYSTEM_DeleteObject(object);
    }
}

/*
 * Four twelve-byte accessors on the 8-byte record array that G3D_UTIL_FreeUnitObjects
 * walks: two halfword getters at +0x1a and +0x1c of record `i`, and two word
 * getters through the pointers at +0 and +0xc of a different object.
 *
 * None of them carries a label in the generated listing: they are leaves whose
 * prologue saves nothing, and `disasm.py` only auto-labels a function whose
 * prologue saves `lr`
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  They were
 * read out of the bytes.  The worklist's own function list for pkt_02048330
 * stops at the labelled bodies, so these four are the 48-byte hole between
 * G3D_UTIL_FreeUnitObjects and G3D_CAMERA_Create - the range is contiguous and this unit
 * reproduces all of it.
 *
 * Three of the four instructions in the first pair are the same in both:
 * `add r0, r0, r1, lsl #3` is the record stride of 8 folded into the add, and
 * the halfword offset rides in the load.
 */
u32 G3D_UTIL_GetUnitObjIdx(G3dUtil *util, int unitIdx)
{
    return util->unit[unitIdx].objIdx;
}

u32 G3D_UTIL_GetUnitObjCount(G3dUtil *util, int unitIdx)
{
    return util->unit[unitIdx].objCount;
}

u32 G3D_UTIL_GetResource(G3dUtil *util, int resIdx)
{
    return *(u32 *)((u8 *)util->res + resIdx * 4);
}

u32 G3D_UTIL_GetObject(G3dUtil *util, int objIdx)
{
    return *(u32 *)((u8 *)util->obj + objIdx * 4);
}
