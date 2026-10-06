/*
 * function: func_02048918
 * address:  0x02048918
 * packet:   pkt_02048330
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02047788  0x02047788  arm
 *   func_0204779C  0x0204779C  arm
 *   func_02047790  0x02047790  arm
 *   func_0204762C  0x0204762C  arm
 *   func_02047554  0x02047554  arm
 *   func_020470D0  0x020470D0  arm
 *   func_02046EFC  0x02046EFC  arm
 *   func_0204754C  0x0204754C  arm
 *   func_02047504  0x02047504  arm
 *   func_02047738  0x02047738  arm
 *
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
 *   python tools/match.py one --src src/matched/func_02048918.c --func func_02048918 --addr 0x02048918 --cc 1.1p1 --arm
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


extern int func_02047788(int *p);
extern u16   func_0204779C(void *obj);
extern int func_02047790(int *p, int i);
struct Rec;
struct Tagged;
extern void func_0204762C(struct Rec *p);
extern int func_02047554(int *p);
extern int func_020470D0(u32 *p);
extern void func_02046EFC(struct Tagged *p);
extern int func_0204754C(int *p);
extern void func_02047504(struct Rec *p);
extern void func_02047738(struct Rec *p);

void func_02048918(Util *util, u16 unitIdx)
{
    u16 objIdx = util->unit[unitIdx].objIdx;
    u16 objCount = util->unit[unitIdx].objCount;
    void *rnd;
    void *obj;
    u16 anmCount;
    int i, j;

    for (i = 0; i < objCount; i++) {
        obj = util->obj[objIdx + i];
        rnd = (void *)func_02047788(obj);
        anmCount = func_0204779C(obj);
        for (j = 0; j < anmCount; j++)
            func_0204762C((struct Rec *)func_02047790(obj, (u16)j));
        if (util->objStat[objIdx + i] & 0xfd) {
            void *tex = (void *)func_02047554(rnd);
            func_020470D0(tex);
            func_02046EFC(tex);
        }
        if (util->objStat[objIdx + i] & 0xfe)
            func_02046EFC((struct Tagged *)func_0204754C(rnd));
        func_02047504(rnd);
        func_02047738(obj);
    }
}
