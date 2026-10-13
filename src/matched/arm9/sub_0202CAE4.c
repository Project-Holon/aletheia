/*
 * unit:     no
 * function: sub_0202CAE4
 * address:  0x0202CAE4
 * packet:   pkt_0202C794
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ARC_UTIL_LoadPaletteDataFromArchive       0x02049EB4  arm
 *   sub_0202CAC4        0x0202CAC4  thumb
 *   ENV_SetResourceSet  0x020307B0  arm
 *
 * The archive-loader wrapper of src/matched/sub_0202CB18.c with a different
 * loader entry point: ARC_UTIL_LoadPaletteDataFromArchive instead of ARC_UTIL_LoadPaletteDataFromHandle. Loads one
 * archive member, copies the tile image 0xc bytes into it through
 * src/matched/sub_0202CAC4.c, and releases the allocation again through
 * ENV_SetResourceSet. The window manager's u32 heap id at +8 is narrowed to
 * u16 by the loader's prototype, hence the `ldr` plus shift pair rather than
 * an `ldrh`.
 *
 * ARC_UTIL_LoadPaletteDataFromArchive is called only once from the ARM9 static module, by this
 * function, but has seven more callers across the overlays (e.g. 0x021B8B08),
 * so the `label` class does have an outside witness.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202CAE4.c \
 *       --func sub_0202CAE4 --addr 0x0202CAE4 --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct WinMgr {
    void *wins;
    u16 pad_04;
    u16 pad_06;
    u32 heap;
};

extern void *ARC_UTIL_LoadPaletteDataFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void sub_0202CAC4(struct WinMgr *mgr, u32 idx, const void *src);
extern void ENV_SetResourceSet(void *p);

void sub_0202CAE4(struct WinMgr *mgr, u32 idx, u32 arc, u32 member, u32 alloc)
{
    void *buf;
    void *res;

    res = ARC_UTIL_LoadPaletteDataFromArchive(arc, member, alloc, (u32)(&buf), mgr->heap);
    sub_0202CAC4(mgr, idx, (char *)buf + 0xc);
    ENV_SetResourceSet(res);
}
