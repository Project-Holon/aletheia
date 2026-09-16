/*
 * unit:     no
 * function: sub_0202CB18
 * address:  0x0202CB18
 * packet:   pkt_0202C794
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02049EF4       0x02049EF4  arm
 *   sub_0202CAC4        0x0202CAC4  thumb
 *   ENV_SetResourceSet  0x020307B0  arm
 *
 * Loads one archive member, copies the tile image 0xc bytes into it through
 * src/matched/sub_0202CAC4.c, and releases the allocation again through
 * ENV_SetResourceSet. The window manager's u32 at +8 is the heap id and is
 * narrowed to u16 by the loader's prototype, which is why it is an `ldr`
 * plus a shift pair rather than an `ldrh`.
 *
 * Identical in shape to its neighbour src/matched/sub_0202CAE4.c, which
 * differs only in calling func_02049EB4 instead of func_02049EF4.
 * func_02049EF4 has a second caller at 0x02027652, so its relocation
 * resolves through the `label` class.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202CB18.c \
 *       --func sub_0202CB18 --addr 0x0202CB18 --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct WinMgr {
    void *wins;
    u16 pad_04;
    u16 pad_06;
    u32 heap;
};

extern void *func_02049EF4(u32 arc, u32 member, u32 alloc, void **out,
                           u16 heap);
extern void sub_0202CAC4(struct WinMgr *mgr, u32 idx, const void *src);
extern void ENV_SetResourceSet(void *p);

void sub_0202CB18(struct WinMgr *mgr, u32 idx, u32 arc, u32 member, u32 alloc)
{
    void *buf;
    void *res;

    res = func_02049EF4(arc, member, alloc, &buf, mgr->heap);
    sub_0202CAC4(mgr, idx, (char *)buf + 0xc);
    ENV_SetResourceSet(res);
}
