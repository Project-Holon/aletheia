/*
 * function: func_02048330
 * address:  0x02048330
 * packet:   pkt_02048330
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02046F50  0x02046F50  arm
 *   func_02046FF8  0x02046FF8  arm
 *   func_02047348  0x02047348  arm
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   g3d_util_file  0x020A7EB8  data
 *   func_02046DB8  0x02046DB8  arm
 *   func_02046E90  0x02046E90  arm
 *   func_02046C94  0x02046C94  arm
 *   func_02046CE0  0x02046CE0  arm
 *   func_02048F60  0x02048F60  arm
 *   func_02048F9C  0x02048F9C  arm
 *
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
 * when it is a separate resource that answers func_02046F50(res, 1) == 1
 * (bit 1, then func_02046FF8), bind them with func_02047400, build the
 * animation array in a low-heap scratch block (__LINE__ 534) and create the
 * object with func_0204767C.
 *
 * The two inline helpers are the lever: createRes writes its result
 * through the caller's out pointer in every case (no local result), which
 * is what keeps the model handle in its stack home [sp,#0x14] and the
 * texture handle in fp without a copy.  With a helper that returns the
 * handle the compiler adds a register copy after each inlined switch
 * (1048 bytes).  The switch is the one func_02048120 carries, __LINE__ 342
 * and 355 (the second copy derives 355 from the live constant 1 with rsb).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02048330.c --func func_02048330 --addr 0x02048330 --cc 1.1p1 --arm
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
    u16 anmResIdx;
    u16 anmDatIdx;
} AnmSetup;

typedef struct {
    u16       mdlResIdx;
    u16       mdlDatIdx;
    u16       texResIdx;
    u16       pad_06;
    AnmSetup *anmTbl;
    u16       anmCount;
} ObjSetup;

typedef struct {
    u32 arc;
    u16 dat;
    u16 pad_06;
    u32 type;
} ResSetup;

typedef struct {
    ResSetup *resTbl;
    u16       resCount;
    ObjSetup *objTbl;
    u16       objCount;
} Setup;

extern const char g3d_util_file[];
extern void *func_02030734(u16 heapID, u32 size, int clear, const char *file, int line);
extern void  func_020307B0(void *p);
struct G3dOwner;
struct G3dRec;
struct Layer;
struct S02046CE0;
struct Tagged;
extern void *func_02046DB8(u32 a0, u32 a1);
extern void *func_02046E90(u32 a0, u32 a1);
extern int func_02046C94(void);
extern void func_02046CE0(struct S02046CE0 *out, u32 *tag);
extern void *func_02048F60(u32 archive_id, u32 member, u32 heap);
extern void *func_02048F9C(const char *path, u32 a, u32 heap);
extern u32 func_02046F50(struct Tagged *p, u32 sel);
extern int func_02046FF8(int *self);
extern int func_02047348(struct Layer *layer);
extern void *func_02047400(void *a0, u32 n, void *a2);
extern struct G3dRec *func_02047564(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *func_0204767C(u32 a0, u32 *a1, int a2);

static inline void createRes(Util *util, const ResSetup *rs, void **out)
{
    switch (rs->type) {
    case 0:
        *out = func_02046DB8(rs->arc, rs->dat);
        break;
    case 1:
        *out = func_02046E90(rs->arc, rs->dat);
        break;
    case 2:
        *out = func_02030734(util->heapID, func_02046C94(), 0, g3d_util_file, 342);
        func_02046CE0(*out, func_02048F60(rs->arc, rs->dat, util->heapID));
        break;
    case 3:
        *out = func_02030734(util->heapID, func_02046C94(), 0, g3d_util_file, 355);
        func_02046CE0(*out, func_02048F9C((const char *)rs->arc, rs->dat, util->heapID));
        break;
    }
}

static inline int getRes(Util *util, u16 resIdx, u16 idx, const Setup *setup, void **out)
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

void func_02048330(Util *util, u16 unitIdx, const Setup *setup, u16 heapID)
{
    u16 resIdx = util->unit[unitIdx].resIdx;
    u16 objIdx = util->unit[unitIdx].objIdx;
    u16 objCount = util->unit[unitIdx].objCount;
    void *mdl;
    void *tex;
    void *rnd;
    void **anm;
    const ObjSetup *os;
    void *a;
    int i, j;

    for (i = 0; i < objCount; i++) {
        os = &setup->objTbl[i];
        if (getRes(util, resIdx, setup->objTbl[i].mdlResIdx, setup, &mdl) == 1)
            util->objStat[objIdx + i] |= 1;
        if (os->texResIdx != os->mdlResIdx) {
            if (func_02046F50(util->res[resIdx + os->texResIdx], 1) == 1) {
                if (getRes(util, resIdx, os->texResIdx, setup, &tex) == 1) {
                    util->objStat[objIdx + i] |= 2;
                    func_02046FF8(tex);
                }
            } else {
                tex = util->res[resIdx + os->texResIdx];
                func_02046FF8(tex);
            }
        } else {
            tex = mdl;
            if (func_02047348(mdl) == 0)
                func_02046FF8(mdl);
        }
        rnd = func_02047400(mdl, os->mdlDatIdx, tex);
        anm = func_02030734((heapID & 0x7fff) | 0x8000, os->anmCount * 4, 1,
                            g3d_util_file, 534);
        for (j = 0; j < os->anmCount; j++) {
            if (os->anmTbl[j].anmResIdx == 0xff)
                a = 0;
            else
                a = func_02047564(rnd, util->res[resIdx + os->anmTbl[j].anmResIdx],
                                  os->anmTbl[j].anmDatIdx);
            anm[j] = a;
        }
        util->obj[objIdx + i] = func_0204767C((u32)rnd, (u32 *)anm, os->anmCount);
        func_020307B0(anm);
    }
}
