/*
 * function: G3D_UTIL_FreeUnitObjects
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
 *   G3D_SYSTEM_GetObjectRender  0x02047788  arm
 *   G3D_SYSTEM_GetObjectAnimeCount  0x0204779C  arm
 *   G3D_SYSTEM_GetObjectAnime  0x02047790  arm
 *   G3D_SYSTEM_DeleteAnime  0x0204762C  arm
 *   G3D_SYSTEM_GetRenderTexRes  0x02047554  arm
 *   G3D_SYSTEM_FreeVramTexture  0x020470D0  arm
 *   G3D_SYSTEM_DeleteResource  0x02046EFC  arm
 *   G3D_SYSTEM_GetRenderMdlRes  0x0204754C  arm
 *   G3D_SYSTEM_DeleteRender  0x02047504  arm
 *   G3D_SYSTEM_DeleteObject  0x02047738  arm
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
 *   python tools/match.py one --src src/matched/G3D_UTIL_FreeUnitObjects.c --func G3D_UTIL_FreeUnitObjects --addr 0x02048918 --cc 1.1p1 --arm
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


extern int G3D_SYSTEM_GetObjectRender(int *p);
extern u16   G3D_SYSTEM_GetObjectAnimeCount(void *obj);
extern int G3D_SYSTEM_GetObjectAnime(int *p, int i);
struct Rec;
struct Tagged;
extern void G3D_SYSTEM_DeleteAnime(struct Rec *p);
extern int G3D_SYSTEM_GetRenderTexRes(int *p);
extern int G3D_SYSTEM_FreeVramTexture(u32 *p);
extern void G3D_SYSTEM_DeleteResource(struct Tagged *p);
extern int G3D_SYSTEM_GetRenderMdlRes(int *p);
extern void G3D_SYSTEM_DeleteRender(struct Rec *p);
extern void G3D_SYSTEM_DeleteObject(struct Rec *p);

void G3D_UTIL_FreeUnitObjects(Util *util, u16 unitIdx)
{
    u16 objIdx = util->unit[unitIdx].objIdx;
    u16 objCount = util->unit[unitIdx].objCount;
    void *rnd;
    void *obj;
    u16 anmCount;
    int i, j;

    for (i = 0; i < objCount; i++) {
        obj = util->obj[objIdx + i];
        rnd = (void *)G3D_SYSTEM_GetObjectRender(obj);
        anmCount = G3D_SYSTEM_GetObjectAnimeCount(obj);
        for (j = 0; j < anmCount; j++)
            G3D_SYSTEM_DeleteAnime((struct Rec *)G3D_SYSTEM_GetObjectAnime(obj, (u16)j));
        if (util->objStat[objIdx + i] & 0xfd) {
            void *tex = (void *)G3D_SYSTEM_GetRenderTexRes(rnd);
            G3D_SYSTEM_FreeVramTexture(tex);
            G3D_SYSTEM_DeleteResource(tex);
        }
        if (util->objStat[objIdx + i] & 0xfe)
            G3D_SYSTEM_DeleteResource((struct Tagged *)G3D_SYSTEM_GetRenderMdlRes(rnd));
        G3D_SYSTEM_DeleteRender(rnd);
        G3D_SYSTEM_DeleteObject(obj);
    }
}
