/*
 * function: func_02048010
 * address:  0x02048010
 * packet:   pkt_02047E88
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   G3D_UTIL_LoadUnitResourcesFromArchive  0x02048258  arm
 *   G3D_UTIL_BuildUnitObjectsLoaded  0x02048744  arm
 *
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
 *   python tools/match.py one --src src/matched/func_02048010.c --func func_02048010 --addr 0x02048010 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 resIdx;
    u16 resCount;
    u16 objIdx;
    u16 objCount;
} Unit;

typedef struct {
    void **res;
    u8    *resStat;
    u16    resCount;
    void **obj;
    u8    *objStat;
    u16    objCount;
    Unit   unit[0x40];
    u16    heapID;
} Util;

typedef struct {
    void *resTbl;
    u16   resCount;
    void *objTbl;
    u16   objCount;
} Setup;

struct Holder;
struct Owner;
extern void G3D_UTIL_LoadUnitResourcesFromArchive(struct Owner *owner, u16 index, struct Holder *p, u32 a4, u32 a5);
extern void G3D_UTIL_BuildUnitObjectsLoaded(Util *u, u16 idx, const Setup *s, u16 heapID);

u16 func_02048010(Util *util, const Setup *setup, u32 extra)
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
            G3D_UTIL_LoadUnitResourcesFromArchive((struct Owner *)util, i, (struct Holder *)setup, util->heapID, extra);
            G3D_UTIL_BuildUnitObjectsLoaded(util, i, setup, util->heapID);
            return i;
        }
        resIdx = util->unit[i].resIdx + util->unit[i].resCount;
        objIdx = util->unit[i].objIdx + util->unit[i].objCount;
    }
    return 0xffff;
}
