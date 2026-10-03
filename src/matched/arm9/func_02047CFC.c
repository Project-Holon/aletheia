/*
 * function: func_02047CFC
 * address:  0x02047CFC
 * packet:   pkt_02047CFC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g3d_util_file  0x020A7EB8  data
 *   func_02030734  0x02030734  arm
 *
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
 *   python tools/match.py one --src src/matched/func_02047CFC.c --func func_02047CFC --addr 0x02047CFC --cc 1.1p1 --arm
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

extern const char g3d_util_file[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

Util *func_02047CFC(u16 resCount, u16 objCount, u16 heapID)
{
    Util *util;
    int i;

    util = func_02030734(heapID, sizeof(Util), 1, g3d_util_file, 92);
    util->heapID = heapID;

    util->res = func_02030734(heapID, resCount * 4, 1, g3d_util_file, 97);
    util->resStat = func_02030734(heapID, resCount, 1, g3d_util_file, 98);
    util->resCount = resCount;
    for (i = 0; i < resCount; i++)
        util->resStat[i] = 0;

    util->obj = func_02030734(heapID, objCount * 4, 1, g3d_util_file, 105);
    util->objStat = func_02030734(heapID, objCount, 1, g3d_util_file, 106);
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
