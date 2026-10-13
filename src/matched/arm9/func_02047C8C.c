/*
 * function: G3D_SYSTEM_DrawRenderObj
 * address:  0x02047C8C
 * packet:   pkt_020479D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   _G3dSystem   0x02146A5C  data
 *   func_0206B6A4 0x0206B6A4  arm
 *
 * Add two halfwords of the object's +4 pointer into the global's two
 * counters (0x26 first, then 0x24), then run the global context's +0x98
 * callback if it is set - passing the object itself, which is still in r0,
 * and the +0x9c argument - and finally hand the object to func_0206B6A4.
 *
 * blocker:  label/matched: the only branch to 0x0206B6A4 in the image is the `bl` at +0x4c inside this function, so its PC24 has no outside witness and no cut can free it (the call is inside the only function that makes it).  Closing 0x0206B6A4 as an EXACT entry would promote this file with no change to the C.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/G3D_SYSTEM_DrawRenderObj.c \
 *       --func G3D_SYSTEM_DrawRenderObj --addr 0x02047C8C --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct G02146A5C {
    struct Ctx *obj;    /* +0x00 */
    u32         f4;     /* +0x04 */
    u32         f8;     /* +0x08 */
};

struct Ctx {
    u8   pad00[0x98];
    void (*f98)(void *p, u32 v);    /* +0x98 */
    u32  f9c;                       /* +0x9C */
};

struct P02047C8C {
    u8        pad00[0x04];
    struct Ov *f4;      /* +0x04 */
};

struct Ov {
    u8  pad00[0x24];
    u16 h24;            /* +0x24 */
    u16 h26;            /* +0x26 */
};

extern struct G02146A5C _G3dSystem;
struct Obj0206B6A4;
extern void func_0206B6A4(struct Obj0206B6A4 *p);

void G3D_SYSTEM_DrawRenderObj(struct P02047C8C *p)
{
    _G3dSystem.f4 += p->f4->h26;
    _G3dSystem.f8 += p->f4->h24;
    if (_G3dSystem.obj->f98 != 0)
        _G3dSystem.obj->f98(p, _G3dSystem.obj->f9c);
    func_0206B6A4((struct Obj0206B6A4 *)p);
}
