/*
 * function: func_02047564
 * address:  0x02047564
 * packet:   pkt_02047564
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   _G3dSystem     0x02146A5C  data
 *   G3D_SYSTEM_FileName     0x020A7EA8  data
 *   func_02030734  0x02030734  arm
 *   func_0206E9A4  0x0206E9A4  arm
 *   G3D_SYSTEM_GetRenderTexRes  0x02047554  arm
 *   func_0206E964  0x0206E964  arm
 *   NNS_G3dAllocAnmObj  0x0206E364  arm
 *   func_02069C74  0x02069C74  arm
 *
 * g3d_system.c.  Allocate a 12-byte record from the context heap (tag
 * 0x59D1, owner a1), fetch animation a2 from a1's resource
 * (func_0206E9A4), allocate the animation object against a0's model
 * (NNS_G3dAllocAnmObj) and initialise it with a0's texture when a0 has one
 * (G3D_SYSTEM_GetRenderTexRes / func_0206E964, then func_02069C74).
 *
 * The lever (wave 16) is `const` on the read-only owner parameter a1 (and
 * the record field that keeps it): with a1 const the a1->f04 load may move
 * above the tag store, and the scheduler then issues the tag's pool load
 * first exactly as the image does.  Without const every spelling left the
 * four instructions after the allocation in the other order (11 bytes out,
 * docs/notes/pkt_02047564.c.txt).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02047564.c  *       --func func_02047564 --addr 0x02047564 --arm
 */


typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct G3dCtx {
    u8  pad_00[0x18];
    u16 heap_id;
};

struct G3dSub {
    u32 pad_00;
    u32 handle;
};

struct G3dOwner {
    u32            pad_00;
    struct G3dSub *f04;
    u32            pad_08;
    struct G3dSub *f0c;
};

struct G3dRec {
    u16 tag;
    u16 unk_02;
    u32 unk_04;
    const struct G3dOwner *unk_08;
};

extern struct G3dCtx *_G3dSystem;
extern char G3D_SYSTEM_FileName[];

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u8 *func_0206E9A4(u8 *p, u32 idx);
extern int G3D_SYSTEM_GetRenderTexRes(int *p);
extern unsigned char *func_0206E964(unsigned char *p);
extern u32  NNS_G3dAllocAnmObj(struct G3dCtx *a0, int a1, u32 a2);
extern void func_02069C74(u32 a0, int a1, u32 a2, int a3);

struct G3dRec *func_02047564(struct G3dOwner *a0, const struct G3dOwner *a1, int a2)
{
    struct G3dRec *r;
    int x;
    u32 y;
    int z = 0;

    r = func_02030734(_G3dSystem->heap_id, 0xC, 0, G3D_SYSTEM_FileName, 0x6D2);
    r->tag = 0x59D1;
    r->unk_08 = a1;
    x = (int)func_0206E9A4((u8 *)a1->f04, a2);
    y = a0->f04->handle;
    if (G3D_SYSTEM_GetRenderTexRes((int *)a0) != 0)
        z = (int)func_0206E964((unsigned char *)a0->f0c->handle);
    r->unk_04 = NNS_G3dAllocAnmObj(_G3dSystem, x, y);
    func_02069C74(r->unk_04, x, y, z);
    return r;
}
