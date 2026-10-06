/*
 * function: func_02048744
 * address:  0x02048744
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
 *
 * g3d_util.c, same utility object as func_02048330 (see that file and
 * docs/families/g3d_util.h).  Build the render objects of one unit whose
 * resources are already loaded: per object, mark the model resource used,
 * resolve the texture resource (mark it used when func_02046F50 reports type
 * 1, else release it through func_02046FF8; a shared model/texture resource is
 * released when func_02047348 reports 0), create the render object, allocate
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
    void     *resTbl;
    u16       resCount;
    ObjSetup *objTbl;
    u16       objCount;
} Setup;

extern const char g3d_util_file[];
extern void *func_02030734(u16 heapID, u32 size, int clear, const char *file, int line);
extern u32 func_020307B0(void *p);
struct G3dOwner;
struct G3dRec;
struct Layer;
struct Tagged;
extern u32 func_02046F50(struct Tagged *p, u32 sel);
extern int func_02046FF8(int *self);
extern int func_02047348(struct Layer *layer);
extern void *func_02047400(void *a0, u32 n, void *a2);
extern struct G3dRec *func_02047564(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *func_0204767C(u32 a0, u32 *a1, int a2);

static inline void *getRes(Util *util, u16 resIdx, u16 idx)
{
    return util->res[resIdx + idx];
}

static inline void *useRes(Util *util, u16 resIdx, u16 idx)
{
    util->resStat[resIdx + idx] = 1;
    return util->res[resIdx + idx];
}

void func_02048744(Util *util, u16 unitIdx, const Setup *setup, u16 heapID)
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

    for (i = 0; i < objCount; i = (int)((char *)0 + i + 1)) {
        os = &setup->objTbl[i];
        mdl = useRes(util, resIdx, setup->objTbl[i].mdlResIdx);
        if (os->texResIdx != setup->objTbl[i].mdlResIdx) {
            if (func_02046F50(getRes(util, resIdx, os->texResIdx), 1) == 1) {
                tex = useRes(util, resIdx, os->texResIdx);
            } else {
                tex = getRes(util, resIdx, os->texResIdx);
                func_02046FF8(tex);
            }
        } else {
            tex = mdl;
            if (func_02047348(mdl) == 0)
                func_02046FF8(mdl);
        }
        rnd = func_02047400(mdl, os->mdlDatIdx, tex);
        anm = func_02030734((heapID & 0x7fff) | 0x8000, os->anmCount * 4, 1,
                            g3d_util_file, 609);
        for (j = 0; j < os->anmCount; j++) {
            if (os->anmTbl[j].anmResIdx == 0xff)
                a = 0;
            else
                a = func_02047564(rnd, getRes(util, resIdx, os->anmTbl[j].anmResIdx),
                                  os->anmTbl[j].anmDatIdx);
            anm[j] = a;
        }
        util->obj[objIdx + i] = func_0204767C((u32)rnd, (u32 *)anm, os->anmCount);
        func_020307B0(anm);
    }
}
