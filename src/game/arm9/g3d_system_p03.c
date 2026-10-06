/*
 * file:     g3d_system_p03.c
 * unit:     yes
 * function: func_02047970, func_02047990, func_020479D8, func_02047A60, func_02047AC8, func_02047B4C, func_02047C04, func_02047C8C, func_02047CE4, func_02047CFC, func_02047E54, func_02047E88, func_02047F4C, func_02048010, func_020480E4, func_02048120, func_02048258, func_020482B4, func_02048330, func_02048744, func_02048918, sub_020489F4, sub_02048A00, sub_02048A0C, sub_02048A18, func_02048A24, func_02048AC4, func_02048AD0, func_02048AE8, func_02048AFC, func_02048B0C, func_02048B20, func_02048B30, func_02048B44, func_02048B54, func_02048B60, func_02048B6C, func_02048B78, func_02048B80, func_02048B88, func_02048B94, func_02048B9C, func_02048BA8, func_02048BB0, func_02048BBC, func_02048BC4
 * address:  0x02047970
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_02146A5C     0x02146A5C  data
 *   func_0206DB80  0x0206DB80  arm
 *   NNS_G3dGlb     0x02148B4C  data
 *   MTX_LookAt     0x0207BCA0  arm
 *   g_02148B4C      0x02148B4C  data
 *   g_02148C08      0x02148C08  data
 *   func_02047788   0x02047788  arm
 *   func_0204755C   0x0204755C  arm
 *   func_0206A9DC   0x0206A9DC  arm
 *   func_0206AA0C   0x0206AA0C  arm
 *   MI_Copy36B      0x02082B60  arm
 *   func_0206DDA4  0x0206DDA4  arm
 *   func_0207DEA4  0x0207DEA4  arm
 *   func_0206B6A4 0x0206B6A4  arm
 *   g3d_util_file  0x020A7EB8  data
 *   func_02030734  0x02030734  arm
 *   func_020307B0   0x020307B0  arm
 *   func_02046DB8       0x02046DB8  arm
 *   func_02046E90       0x02046E90  arm
 *   func_02046C94       0x02046C94  arm
 *   func_02046CE0       0x02046CE0  arm
 *   func_02048F60       0x02048F60  arm
 *   func_02048F9C       0x02048F9C  arm
 *   func_02046E24   0x02046E24  arm
 *   func_02046F50   0x02046F50  arm
 *   func_020470D0   0x020470D0  arm
 *   func_02046EFC   0x02046EFC  arm
 *   func_02046FF8  0x02046FF8  arm
 *   func_02047348  0x02047348  arm
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_0204779C  0x0204779C  arm
 *   func_02047790  0x02047790  arm
 *   func_0204762C  0x0204762C  arm
 *   func_02047554  0x02047554  arm
 *   func_0204754C  0x0204754C  arm
 *   func_02047504  0x02047504  arm
 *   func_02047738  0x02047738  arm
 *   g_020A7EC4     0x020A7EC4  data
 *   func_02046858  0x02046858  arm
 *   func_02046B40  0x02046B40  arm
 *   func_02048BC4_File  0x020A7ED4  data
 */
#include "../../matched/include/Obj17329.h"
#include "../../matched/include/Obj17330.h"

struct P02047C8C;
struct Obj0206B6A4;
struct Holder;
struct Owner;
struct S02046CE0;
struct Tagged;
struct G3dOwner;
struct G3dRec;
struct Layer;
struct Rec;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef int fx32;

typedef struct { fx32 x, y, z; } VecFx32_020479D8;

struct Ctx {
    u8  pad_00[0x5C];
    VecFx32_020479D8 view0;
    VecFx32_020479D8 view1;
    VecFx32_020479D8 view2;
    u32 sortMode;
    u32 bufferMode;
    void (*f88)(void);
    u8  pad_8c[0x94 - 0x8c];
    u32 unk_94;
    void (*f98)(void *p, u32 v);
    u32 f9c;
};

struct G3dSys {
    void *obj;
    u32 f4;
    u32 f8;
};

typedef struct { fx32 m[4][3]; } MtxFx43;

typedef struct { fx32 m[4][4]; } MtxFx44;

typedef struct { fx32 m[3][3]; } MtxFx33_020479D8;

typedef struct {
    u32 cmd0;
    u32 mtxmode_proj;
    MtxFx44 projMtx;
    u32 mtxmode_posvec;
    MtxFx43 cameraMtx;
    u32 cmd1;
    u32 lightVec[4];
    u32 cmd2;
    u32 prmMatColor0;
    u32 prmMatColor1;
    u32 prmPolygonAttr;
    u32 prmViewPort;
    u32 cmd3;
    u32 lightColor[4];
    u32 cmd4;
    MtxFx33_020479D8 prmBaseRot;
    VecFx32_020479D8 prmBaseTrans;
    VecFx32_020479D8 prmBaseScale;
    u32 prmTexImageParam;
    u32 flag;
    MtxFx43 invCameraMtx;
    MtxFx43 srtCameraMtx;
    MtxFx43 invSrtCameraMtx;
    MtxFx43 invBaseMtx;
    MtxFx44 invProjMtx;
    MtxFx44 invCameraProjMtx;
    VecFx32_020479D8 camPos;
    VecFx32_020479D8 camUp;
    VecFx32_020479D8 camTarget;
} NNSG3dGlb;

typedef struct { u32 x, y, z; } VecFx32_02047A60;

typedef struct { u32 m[9]; } MtxFx33_02047A60;

struct Arg {
    u8      pad_00[0x0C];
    VecFx32_02047A60 v0c;
    MtxFx33_02047A60 m18;
};

typedef struct { u32 x, y, z; } VecFx32_02047AC8;

typedef struct { u32 m[9]; } MtxFx33_02047AC8;

typedef signed short   s16;

struct Rec_0 {
    u32 pad_00[6];
    s16 f18;
    s16 f1a;
    s16 f1c;
    s16 f1e;
    s16 f20;
    s16 f22;
    u32 f24;
};

struct Owner {
    u32  unk_00;
    u8  *unk_04;
};

struct Block {
    s16 f00;
    s16 f02;
    s16 f04;
    s16 f06;
    s16 f08;
    s16 f0a;
};

typedef signed int     s32;

typedef unsigned short u16;

struct P02047C8C {
    u8        pad00[0x04];
    struct Ov *f4;      /* +0x04 */
};

struct Ov {
    u8  pad00[0x24];
    u16 h24;            /* +0x24 */
    u16 h26;            /* +0x26 */
};

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

struct Rec_1 {
    void *unk_00;
    void *unk_04;
    void *unk_08;
    void *unk_0c;
    void *unk_10;
};

struct Slot {
    u8  pad_00[0x16];
    u16 unk_16;
    u16 unk_18;
};

struct Rec_02048120 {
    u32 unk_00;
    u16 unk_04;
    u8  pad_06[2];
    u32 unk_08;
};

struct Rig {
    u32 unk_00;
};

struct Desc {
    struct Rec_02048120 *unk_00;
};

struct Rec_02048258 {
    u8  pad_00[4];
    u16 unk_04;
    u8  pad_06[6];
};

struct Holder {
    struct Rec_02048258 *unk_00;
};

typedef struct {
    void *resTbl;
    u16   resCount;
    void *objTbl;
    u16   objCount;
} Setup_02048918;

typedef struct {
    u32 x;
    u32 y;
    u32 z;
} Vec3;

typedef struct {
    int x;
    int y;
    int z;
} VecFx32;

struct Light {
    u32     unk00;
    u32     unk04;
    u32     unk08;
    u8      pad0C[8];
    u32     unk14;
    u32     unk18;
    u8      pad1C[4];
    VecFx32 unk20;
    VecFx32 unk2C;
    VecFx32 unk38;
};

struct LightSlot {
    u16 unk00;
    u16 unk02;
    u16 unk04;
    u16 unk06;
};

struct LightRec {
    u8               slot;
    u8               pad01;
    struct LightSlot val;
};

struct LightSet {
    struct LightRec *recs;
    u8               count;
};

extern void func_0206DB80(void);
extern void MTX_LookAt(const VecFx32_020479D8 *camPos, const VecFx32_020479D8 *camUp,
                       const VecFx32_020479D8 *target, MtxFx43 *mtx);
extern int func_02047788(int *p);
extern int func_0204755C(int *p);
extern void  func_0206A9DC(void *p);
extern void  func_0206AA0C(VecFx32_02047A60 *p);
extern void  MI_Copy36B(const void *src, void *dst);
extern void func_0206DDA4(u32 cmd, const void *params, u32 n);
extern int func_0207DEA4(s32 *in);
extern void func_0206B6A4(struct Obj0206B6A4 *p);
extern void *func_02030734(u16 heapID, u32 size, int clear, const char *file, int line);
extern u32 func_020307B0(void *p);
extern void *func_02046DB8(u32 a0, u32 a1);
extern void *func_02046E90(u32 a0, u32 a1);
extern int func_02046C94(void);
extern void func_02046CE0(struct S02046CE0 *out, u32 *tag);
extern void *func_02048F60(u32 archive_id, u32 member, u32 heap);
extern void *func_02048F9C(const char *path, u32 a, u32 heap);
extern void *func_02046E24(u32 a0, u32 a1);
extern u32 func_02046F50(struct Tagged *p, u32 sel);
extern int func_020470D0(u32 *p);
extern void func_02046EFC(struct Tagged *p);
extern int func_02046FF8(int *self);
extern int func_02047348(struct Layer *layer);
extern void *func_02047400(void *a0, u32 n, void *a2);
extern struct G3dRec *func_02047564(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *func_0204767C(u32 a0, u32 *a1, int a2);
extern u16   func_0204779C(void *obj);
extern int func_02047790(int *p, int i);
extern void func_0204762C(struct Rec *p);
extern int func_02047554(int *p);
extern int func_0204754C(int *p);
extern void func_02047504(struct Rec *p);
extern void func_02047738(struct Rec *p);
extern void func_02046858(const u32 *src);
extern void func_02046B40(u8 *a0);
void func_02047970(void);
void func_02047990(void);
void func_020479D8(void);
void func_02047A60(void *a0, struct Arg *a1);
int func_02047AC8(void *a0, struct Arg *a1);
int func_02047B4C(void *a0);
int func_02047C04(void *obj);
void func_02047C8C(struct P02047C8C *p);
void func_02047CE4(void);
Util *func_02047CFC(u16 resCount, u16 objCount, u16 heapID);
void func_02047E54(struct Rec_1 *p);
u16 func_02047E88(Util *util, const Setup *setup);
u16 func_02047F4C(Util *util, const Setup *setup);
u16 func_02048010(Util *util, const Setup *setup, u32 extra);
void func_020480E4(Util *util, u32 i);
void func_02048120(Util *util, u16 index, const Setup *setup, u16 heapID);
void func_02048258(struct Owner *owner, u16 index, struct Holder *p, u32 a4, u32 a5);
void func_020482B4(struct Owner *owner, u32 index);
void func_02048330(Util *util, u16 unitIdx, const Setup *setup, u16 heapID);
void func_02048744(Util *util, u16 unitIdx, const Setup *setup, u16 heapID);
void func_02048918(Util *util, u32 unitIdx);
u32 sub_020489F4(u8 *a0, int i);
u32 sub_02048A00(u8 *a0, int i);
u32 sub_02048A0C(u8 *a0, int i);
u32 sub_02048A18(u8 *a0, int i);
u32 *func_02048A24(u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8, Vec3 *a9, Vec3 *a10, Vec3 *a11, u16 heap);
u32 func_02048AC4(void *ptr);
void func_02048AD0(struct Light *l);
void func_02048AE8(struct Light *l, VecFx32 *out);
void func_02048AFC(struct Light *l, const VecFx32 *in);
void func_02048B0C(struct Light *l, VecFx32 *out);
void func_02048B20(struct Light *l, const VecFx32 *in);
void func_02048B30(struct Light *l, VecFx32 *out);
void func_02048B44(struct Light *l, const VecFx32 *in);
void func_02048B54(struct Light *l, u32 *out);
void func_02048B60(struct Light *l, const u32 *in);
void func_02048B6C(struct Light *l, const u32 *in);
int func_02048B78(struct Light *l);
void func_02048B80(struct Light *l, u32 v);
void func_02048B88(struct Light *l, u32 *out);
void func_02048B94(struct Light *l, u32 v);
void func_02048B9C(struct Light *l, u32 *out);
void func_02048BA8(struct Light *l, u32 v);
void func_02048BB0(struct Light *l, u32 *out);
void func_02048BBC(struct Light *l, u32 v);
struct LightSlot *func_02048BC4(const struct LightSet *s, u16 heap);
extern struct G3dSys g_02146A5C;
extern NNSG3dGlb NNS_G3dGlb;
extern u32 g_02148B4C[];
extern u32 g_02148C08[];
extern const char g3d_util_file[];
extern char  g_020A7EC4[];
extern const char func_02048BC4_File[];










/*
 * Set the context's +0x94 word to one, after letting func_0206DB80 run
 * first; the context pointer is read from its slot after the call, so it is
 * a fresh `ldr` and not a saved one.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02047970.c \
 *       --func func_02047970 --addr 0x02047970 --cc 1.1p1 --arm
 */
void func_02047970(void)
{
    func_0206DB80();
    ((struct Ctx *)g_02146A5C.obj)->unk_94 = 1;
}










#define reg_G3_SWAP_BUFFERS (*(volatile u32 *)0x04000540)









/*
 * The 3D buffer-swap flush, called once per frame from NitroMain (blx at
 * 0x02005176).  When the swap requested by func_02047970 is pending (+0x94
 * set to 1), it writes G3_SWAP_BUFFERS with the sort mode (+0x80) and the
 * buffer mode (+0x84) and clears the request.  The listing carried it as raw
 * words until NitroMain was seeded in layout/function_starts.txt.
 */
void func_02047990(void)
{
    struct Ctx *c = ((struct Ctx *)g_02146A5C.obj);

    if (c == 0)
        return;
    if (c->unk_94 != 1)
        return;
    reg_G3_SWAP_BUFFERS = (c->bufferMode << 1) | c->sortMode;
    ((struct Ctx *)g_02146A5C.obj)->unk_94 = 0;
}










static inline void NNS_G3dGlbLookAt(const VecFx32_020479D8 *camPos, const VecFx32_020479D8 *camUp,
                                    const VecFx32_020479D8 *target)
{
    NNS_G3dGlb.camPos = *camPos;
    NNS_G3dGlb.camUp = *camUp;
    NNS_G3dGlb.camTarget = *target;
    MTX_LookAt(camPos, camUp, target, &NNS_G3dGlb.cameraMtx);
    NNS_G3dGlb.flag &= ~(0x08 | 0x80 | 0x20 | 0x40);
}










/*
 * g3d_system.c.  Re-apply the context's camera (position, up and target at
 * +0x5C/+0x68/+0x74) through NitroSystem's NNS_G3dGlbLookAt inline, then run
 * the context's +0x88 callback.
 *
 * The lever (wave 15) is the library shape: the three destination blocks
 * 0x02148D8C/0x02148D98/0x02148DA4, the camera matrix 0x02148B98 and the flag
 * word 0x02148B4C+0xFC are all fields of ONE object, NNS_G3dGlb (camPos,
 * camUp, camTarget at +0x240/+0x24C/+0x258, cameraMtx at +0x4C, flag at
 * +0xFC), and the copies plus MTX_LookAt plus the flag clear are the
 * NitroSystem inline NNS_G3dGlbLookAt(const VecFx32 *, const VecFx32 *,
 * const VecFx32 *) (glbstate_inline.h, NitroSystem-071126).  The inline's
 * three pointer parameters are what keep the three addresses in lr/ip/r5
 * for the call; every hand spelling with separate externs came out one
 * callee-saved register wider (22 to 31 bytes out,
 * docs/notes/pkt_020479D8.c.txt).  0xE8 is INVCAMERA | INVBASECAMERA |
 * INVCAMERAPROJ | BASECAMERA.  The layout below reproduces the NitroSystem
 * struct up to camTarget; the offsets are fixed by the image's pool words.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020479D8.c \
 *       --func func_020479D8 --addr 0x020479D8 --arm
 */
void func_020479D8(void)
{
    NNS_G3dGlbLookAt(&((struct Ctx *)g_02146A5C.obj)->view0, &((struct Ctx *)g_02146A5C.obj)->view1, &((struct Ctx *)g_02146A5C.obj)->view2);
    ((struct Ctx *)g_02146A5C.obj)->f88();
}










void func_02047A60(void *a0, struct Arg *a1)
{
    void *r;

    r = (void *)func_0204755C((int *)func_02047788(a0));
    func_0206A9DC(a1);
    MI_Copy36B(&a1->m18, g_02148C08);
    g_02148B4C[63] = g_02148B4C[63] & ~0xa4u;
    func_0206AA0C(&a1->v0c);
    ((struct Ctx *)g_02146A5C.obj)->f88();
    func_02047C8C(r);
}










/*
 * The sibling of func_02047A60 with a result: the same bring-up (the two
 * sub-objects of the argument at +0xC and +0x18, the `bic 0xa4` on word 63
 * of 0x02148B4C, the context's +0x88 callback) and then func_02047B4C,
 * whose value is returned and whose `== 1` gates the func_02047C8C release.
 *
 * NOTE ON func_02047B4C's ARITY.  src/matched/func_02047B4C.c declares it
 * `int func_02047B4C(void)` and is EXACT that way; here it must be declared
 * as taking one pointer, because the original saves this function's own
 * first argument in r5 across the whole body purely to set r0 before the
 * call (+0x0008 `mov r5, r0`, +0x0054 `mov r0, r5`).  A `void` declaration
 * drops those two instructions and the function comes out eight bytes
 * short.  The callee ignoring r0 is consistent with both files being exact:
 * the argument is passed and unused.
 */
int func_02047AC8(void *a0, struct Arg *a1)
{
    void *r;
    int   s;

    r = (void *)func_0204755C((int *)func_02047788(a0));
    func_0206A9DC(a1);
    MI_Copy36B(&a1->m18, g_02148C08);
    g_02148B4C[63] = g_02148B4C[63] & ~0xa4u;
    func_0206AA0C(&a1->v0c);
    ((struct Ctx *)g_02146A5C.obj)->f88();
    s = func_02047B4C(a0);
    if (s == 1)
        func_02047C8C(r);
    return s;
}










/*
 * Copy the six s16 of the sub-record at +0x18..0x22 into a local, register
 * it via func_0206DDA4 (the three-argument command/buffer/count shape of
 * src/matched/func_0206A884.c), broadcast the +0x24 word into a three-word
 * buffer, hand the halfword block to func_02047C04, and report failure as
 * zero.  The `+ 0x14` is folded with a null test on the owning pointer, so
 * a null owner leaves the base at zero rather than at 0x14.
 *
 * Addresses are Black-image addresses.
 */
int func_02047B4C(void *a0)
{
    struct Block blk;
    u32 buf[3];
    int one;
    struct Rec_0 *r;
    char *p;
    int ret;

    ret = 1;
    p = (char *)((struct Owner *)func_0204755C((int *)func_02047788(a0)))->unk_04;
    r = (struct Rec_0 *)(p != 0 ? p + 0x14 : 0);

    blk.f00 = r->f18;
    blk.f02 = r->f1a;
    blk.f04 = r->f1c;
    blk.f06 = r->f1e;
    blk.f08 = r->f20;
    blk.f0a = r->f22;
    func_0206DDA4(0x11, 0, 0);

    buf[0] = r->f24;
    buf[1] = buf[0];
    buf[2] = buf[0];
    func_0206DDA4(0x1B, buf, 3);

    if (func_02047C04(&blk) == 0) {
        ret = 0;
    }

    one = 1;
    func_0206DDA4(0x12, &one, 1);
    return ret;
}









/*
 * Four registrations through func_0206DDA4 (same three-argument shape as
 * src/matched/func_0206A884.c: command, buffer, count), then func_0206DB80
 * and a spin on func_0207DEA4 over the first slot until it reports zero.
 * The value returned is that slot, still holding the 1 it was seeded with.
 *
 * Addresses are Black-image addresses.
 */
int func_02047C04(void *obj)
{
    int done;
    int arg;
    int zero;

    done = 1;
    arg  = 0x30C1;
    func_0206DDA4(0x29, &arg, 1);
    zero = 0;
    func_0206DDA4(0x40, &zero, 1);
    func_0206DDA4(0x41, 0, 0);
    func_0206DDA4(0x70, obj, 3);
    func_0206DB80();
    while (func_0207DEA4(&done) != 0) {
        ;
    }
    return done;
}









/*
 * Add two halfwords of the object's +4 pointer into the global's two
 * counters (0x26 first, then 0x24), then run the global context's +0x98
 * callback if it is set - passing the object itself, which is still in r0,
 * and the +0x9c argument - and finally hand the object to func_0206B6A4.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02047C8C.c \
 *       --func func_02047C8C --addr 0x02047C8C --cc 1.1p1 --arm
 */
void func_02047C8C(struct P02047C8C *p)
{
    g_02146A5C.f4 += p->f4->h26;
    g_02146A5C.f8 += p->f4->h24;
    if (((struct Ctx *)g_02146A5C.obj)->f98 != 0)
        ((struct Ctx *)g_02146A5C.obj)->f98(p, ((struct Ctx *)g_02146A5C.obj)->f9c);
    func_0206B6A4((struct Obj0206B6A4 *)p);
}









/*
 * An unlabelled ARM leaf that follows func_02047C8C's pool word: it clears
 * the two counters at +4 and +8 of the global at 0x02146A5C (the same global
 * func_02046A94 indexes through, whose first word is the context pointer).
 * One `mov r1, #0` feeds both stores.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02047CE4.c \
 *       --func func_02047CE4 --addr 0x02047CE4 --cc 1.1p1 --arm
 */
void func_02047CE4(void)
{
    g_02146A5C.f4 = 0;
    g_02146A5C.f8 = 0;
}









/*
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








/*
 * Free the four pointers of one record, in decreasing address order, and
 * then the record itself.  The object pointer is the only callee-saved
 * value, which is why the frame is two words.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02047E54.c \
 *       --func func_02047E54 --addr 0x02047E54 --cc 1.1p1 --arm
 */
void func_02047E54(struct Rec_1 *p)
{
    func_020307B0(p->unk_10);
    func_020307B0(p->unk_0c);
    func_020307B0(p->unk_04);
    func_020307B0(p->unk_00);
    func_020307B0(p);
}








/*
 * g3d_util.c (the __FILE__ word 0x020A7EB8 of this family).  The utility
 * object is 0x218 bytes: resource handle table and status bytes at +0x00 /
 * +0x04 with a u16 count at +0x08, object table and status bytes at +0x0c /
 * +0x10 with a u16 count at +0x14, 0x40 eight-byte unit records from +0x16
 * {resIdx, resCount, objIdx, objCount}, and the u16 heap id at +0x216.  See
 * docs/families/g3d_util.h.
 *
 * Add one unit: take the first free record (resIdx == 0xffff), place its
 * resource and object runs right after the previous record's, then load the
 * resources (func_02048120) and build the objects (func_02048330).  The lever
 * that closed it is the prototypes: the unit index and heap id are u16
 * parameters of both callees, so each call site truncates `i` on its own
 * (the lsl/lsr pair appears twice plus once for the u16 return), which an
 * explicit (u16) cast does not reproduce.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02047E88.c --func func_02047E88 --addr 0x02047E88 --cc 1.1p1 --arm
 */
u16 func_02047E88(Util *util, const Setup *setup)
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
            func_02048120(util, i, setup, util->heapID);
            func_02048330(util, i, setup, util->heapID);
            return i;
        }
        resIdx = util->unit[i].resIdx + util->unit[i].resCount;
        objIdx = util->unit[i].objIdx + util->unit[i].objCount;
    }
    return 0xffff;
}








/*
 * g3d_util.c (the __FILE__ word 0x020A7EB8 of this family).  The utility
 * object is 0x218 bytes: resource handle table and status bytes at +0x00 /
 * +0x04 with a u16 count at +0x08, object table and status bytes at +0x0c /
 * +0x10 with a u16 count at +0x14, 0x40 eight-byte unit records from +0x16
 * {resIdx, resCount, objIdx, objCount}, and the u16 heap id at +0x216.  See
 * docs/families/g3d_util.h.
 *
 * Twin of func_02047E88 with the second callee func_02048744 (the object
 * builder that binds textures itself); same u16 prototype lever.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02047F4C.c --func func_02047F4C --addr 0x02047F4C --cc 1.1p1 --arm
 */
u16 func_02047F4C(Util *util, const Setup *setup)
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
            func_02048120(util, i, setup, util->heapID);
            func_02048744(util, i, setup, util->heapID);
            return i;
        }
        resIdx = util->unit[i].resIdx + util->unit[i].resCount;
        objIdx = util->unit[i].objIdx + util->unit[i].objCount;
    }
    return 0xffff;
}







/*
 * g3d_util.c (the __FILE__ word 0x020A7EB8 of this family).  The utility
 * object is 0x218 bytes: resource handle table and status bytes at +0x00 /
 * +0x04 with a u16 count at +0x08, object table and status bytes at +0x0c /
 * +0x10 with a u16 count at +0x14, 0x40 eight-byte unit records from +0x16
 * {resIdx, resCount, objIdx, objCount}, and the u16 heap id at +0x216.  See
 * docs/families/g3d_util.h.
 *
 * Third twin: the resource loader is func_02048258, which takes a fifth
 * argument forwarded from this function's third parameter.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02048010.c --func func_02048010 --addr 0x02048010 --cc 1.1p1 --arm
 */
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
            func_02048258((struct Owner *)util, i, (struct Holder *)setup, util->heapID, extra);
            func_02048744(util, i, setup, util->heapID);
            return i;
        }
        resIdx = util->unit[i].resIdx + util->unit[i].resCount;
        objIdx = util->unit[i].objIdx + util->unit[i].objCount;
    }
    return 0xffff;
}







/*
 * PARKED AT MATCH.  Every one of the 60 concrete bytes is right; the PC24 at
 * +0x000C is wildcarded because 0x02048918 has exactly one branch reference
 * image wide and it is that call, so no cut of a one-function range frees it.
 * Blocking evidence class: label/matched, no outside witness.  The site
 * unsticks the moment 0x02048918 (220 bytes, packet pkt_02048330) is itself
 * EXACT -- the `matched` class then resolves it with no change to this C.
 * The sibling site, the call to 0x020482B4 at +0x0018, resolves today
 * (`matched`, src/matched/func_020482B4.c).
 *
 * Seed one OAM slot of a cell actor and stamp four -1 halfwords into the
 * 8-byte record the actor keeps for it: the two calls initialise the slot and
 * the four stores write the record at +0x16 of the indexed base, which is why
 * the index scales by 8 (`lsl #3`) while the displacement 0x16 rides the
 * stores.  The -1 cannot be encoded as a halfword immediate, so it takes the
 * pool word 0x0000ffff and is loaded once for all four stores.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_020480E4.c \
 *       --func func_020480E4 --addr 0x020480E4 --cc 1.1p1 --arm
 */
void func_020480E4(Util *util, u32 i)
{
    func_02048918(util, i);
    func_020482B4((struct Owner *)util, i);
    util->unit[i].resIdx = -1;
    util->unit[i].resCount = -1;
    util->unit[i].objIdx = -1;
    util->unit[i].objCount = -1;
}







static inline struct Slot *rig_cfg(struct Rig *rig)
{
    return (struct Slot *)((u8 *)rig + 0x200);
}







/*
 * Load one row of resources for the 3D utility rig.  The 8-byte slot at
 * `rig + index * 8` names a run of the handle array at `rig->f00`: the u16 at
 * +0x18 is the count and the u16 at +0x16 is the first index.  Each element is
 * described by a 0xc-byte record in `desc->f00`, whose +8 word selects the
 * source:
 *
 *   0  a plain archive member by id            (func_02046DB8)
 *   1  the same id through the second table    (func_02046E90)
 *   2  a heap-allocated node wrapping a member read by archive id
 *   3  the same, with the member read by path
 *
 * The heap id is the u16 at `rig + 0x200 + 0x16`, re-read at every use, and
 * `rig->f00` is re-read once per iteration because func_02046CE0 may store
 * through it.  The __FILE__ argument is "g3d_util.c" at 0x020A7EB8.
 *
 * The two __LINE__ values are 342 and 355; the image hoists 355 out of the
 * loop as one pool word and derives 342 from it with `sub r0, r0, #0xd`,
 * spilling the result once
 * (docs/idioms/consecutive-line-numbers-are-one-pool-word-and-adds.md).
 *
 * The rig's config base (`rig + 0x200`) must NOT be a named local: binding it
 * to one schedules `add r8, fp, #0x200` ahead of the empty-row guard, where
 * the image computes it after the `pople`.  Spelled as a re-evaluated inline
 * accessor the compiler sinks it below the guard and the whole 312 bytes
 * match.  Declaration order of the remaining locals is slotno/out/i/rec,
 * which is what puts them in r4/r5/r6/r7
 * (docs/idioms/declaration-order-decides-which-register-a-local-gets.md).
 * Probed once under `../2.0/sp2` on the one-instruction scheduling residue:
 * 340 bytes, 290 out -- not a pinned file, the fix is the C.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02048120.c \
 *       --func func_02048120 --addr 0x02048120 --cc 1.1p1 --arm
 */
void func_02048120(Util *util, u16 index, const Setup *setup, u16 heapID)
{
    struct Rig *rig = (struct Rig *)util;
    struct Desc *desc = (struct Desc *)setup;
    struct Slot *slot = (struct Slot *)((u8 *)rig + index * 8);
    int count = slot->unk_18;
    u32 base = slot->unk_16;
    u32 slotno;
    u32 *out;
    int i;
    struct Rec_02048120 *rec;
    void *node;

    for (i = 0; i < count; i++) {
        out = (u32 *)rig->unk_00;
        slotno = base + i;
        rec = &desc->unk_00[i];

        switch (rec->unk_08) {
        case 0:
            out[slotno] = (u32)func_02046DB8(rec->unk_00, rec->unk_04);
            break;
        case 1:
            out[slotno] = (u32)func_02046E90(rec->unk_00, rec->unk_04);
            break;
        case 2:
            node = func_02030734(rig_cfg(rig)->unk_16, func_02046C94(), 0,
                                 g3d_util_file, 342);
            func_02046CE0(node,
                          (u32 *)((u32)func_02048F60(rec->unk_00, rec->unk_04,
                                             rig_cfg(rig)->unk_16)));
            out[slotno] = (u32)node;
            break;
        case 3:
            node = func_02030734(rig_cfg(rig)->unk_16, func_02046C94(), 0,
                                 g3d_util_file, 355);
            func_02046CE0(node,
                          (u32 *)((u32)func_02048F9C((const char *)rec->unk_00, rec->unk_04,
                                             rig_cfg(rig)->unk_16)));
            out[slotno] = (u32)node;
            break;
        }
    }
}







/*
 * Build one row of the array the slot record at `owner + index * 8`
 * describes: the u16 at +0x18 is the element count and the u16 at +0x16 is
 * the row's first index, and each element is the result of func_02046E24
 * on the corresponding 0xc-byte record's +4 halfword, with the caller's
 * fifth argument forwarded as its first.
 *
 * The count is signed in the original (`cmp` plus `pople` for the empty
 * row, `blt` on the back edge), and the destination is written through the
 * owner's own +0 pointer, re-read once per iteration because the callee may
 * store it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02048258.c \
 *       --func func_02048258 --addr 0x02048258 --cc 1.1p1 --arm
 */
void func_02048258(struct Owner *owner, u16 index, struct Holder *p, u32 a4,
                   u32 a5)
{
    struct Slot *slot = (struct Slot *)((u8 *)owner + index * 8);
    u16 count = slot->unk_18;
    u16 base = slot->unk_16;
    int i;

    for (i = 0; i < count; i++) {
        ((u32 *)owner->unk_00)[base + i] =
            (u32)func_02046E24(a5, p->unk_00[i].unk_04);
    }
}






/*
 * Tear down one row of the array: for each of the slot record's +0x18
 * elements (starting at the +0x16 index) that is not null, clear the
 * matching byte of the owner's second array (base + index), then run
 * func_02046F50 with mode 2 and, only when it answers exactly one,
 * func_020470D0, and finally func_02046EFC on the element either way.
 *
 * The same signed count and `blt` back edge as func_02048258, and the same
 * re-read of the owner's element pointer per iteration.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020482B4.c \
 *       --func func_020482B4 --addr 0x020482B4 --cc 1.1p1 --arm
 */
void func_020482B4(struct Owner *owner, u32 index)
{
    struct Slot *slot = (struct Slot *)((u8 *)owner + index * 8);
    u16 count = slot->unk_18;
    u16 base = slot->unk_16;
    int i;

    for (i = 0; i < count; i++) {
        u32 v = ((u32 *)owner->unk_00)[base + i];

        if (v != 0) {
            owner->unk_04[base + i] = 0;

            if (func_02046F50((struct Tagged *)v, 2) == 1)
                func_020470D0((u32 *)v);

            func_02046EFC((struct Tagged *)v);
        }
    }
}






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






/*
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





static inline void *getResSlot(Util *util, u16 resIdx, u16 idx)
{
    return util->res[resIdx + idx];
}





static inline void *useRes(Util *util, u16 resIdx, u16 idx)
{
    util->resStat[resIdx + idx] = 1;
    return util->res[resIdx + idx];
}





/*
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
            if (func_02046F50(getResSlot(util, resIdx, os->texResIdx), 1) == 1) {
                tex = useRes(util, resIdx, os->texResIdx);
            } else {
                tex = getResSlot(util, resIdx, os->texResIdx);
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
                a = func_02047564(rnd, getResSlot(util, resIdx, os->anmTbl[j].anmResIdx),
                                  os->anmTbl[j].anmDatIdx);
            anm[j] = a;
        }
        util->obj[objIdx + i] = func_0204767C((u32)rnd, (u32 *)anm, os->anmCount);
        func_020307B0(anm);
    }
}





/*
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
void func_02048918(Util *util, u32 unitIdx)
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




/*
 * Four twelve-byte accessors on the 8-byte record array that func_02048918
 * walks: two halfword getters at +0x1a and +0x1c of record `i`, and two word
 * getters through the pointers at +0 and +0xc of a different object.
 *
 * None of them carries a label in the generated listing: they are leaves whose
 * prologue saves nothing, and `disasm.py` only auto-labels a function whose
 * prologue saves `lr`
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  They were
 * read out of the bytes.  The worklist's own function list for pkt_02048330
 * stops at the labelled bodies, so these four are the 48-byte hole between
 * func_02048918 and func_02048A24 - the range is contiguous and this unit
 * reproduces all of it.
 *
 * Three of the four instructions in the first pair are the same in both:
 * `add r0, r0, r1, lsl #3` is the record stride of 8 folded into the add, and
 * the halfword offset rides in the load.
 */
u32 sub_020489F4(u8 *a0, int i)
{
    return *(u16 *)(a0 + i * 8 + 0x1a);
}




/*
 * Four twelve-byte accessors on the 8-byte record array that func_02048918
 * walks: two halfword getters at +0x1a and +0x1c of record `i`, and two word
 * getters through the pointers at +0 and +0xc of a different object.
 *
 * None of them carries a label in the generated listing: they are leaves whose
 * prologue saves nothing, and `disasm.py` only auto-labels a function whose
 * prologue saves `lr`
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  They were
 * read out of the bytes.  The worklist's own function list for pkt_02048330
 * stops at the labelled bodies, so these four are the 48-byte hole between
 * func_02048918 and func_02048A24 - the range is contiguous and this unit
 * reproduces all of it.
 *
 * Three of the four instructions in the first pair are the same in both:
 * `add r0, r0, r1, lsl #3` is the record stride of 8 folded into the add, and
 * the halfword offset rides in the load.
 */
u32 sub_02048A00(u8 *a0, int i)
{
    return *(u16 *)(a0 + i * 8 + 0x1c);
}




/*
 * Four twelve-byte accessors on the 8-byte record array that func_02048918
 * walks: two halfword getters at +0x1a and +0x1c of record `i`, and two word
 * getters through the pointers at +0 and +0xc of a different object.
 *
 * None of them carries a label in the generated listing: they are leaves whose
 * prologue saves nothing, and `disasm.py` only auto-labels a function whose
 * prologue saves `lr`
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  They were
 * read out of the bytes.  The worklist's own function list for pkt_02048330
 * stops at the labelled bodies, so these four are the 48-byte hole between
 * func_02048918 and func_02048A24 - the range is contiguous and this unit
 * reproduces all of it.
 *
 * Three of the four instructions in the first pair are the same in both:
 * `add r0, r0, r1, lsl #3` is the record stride of 8 folded into the add, and
 * the halfword offset rides in the load.
 */
u32 sub_02048A0C(u8 *a0, int i)
{
    return *(u32 *)((u8 *)((struct Obj17329 *)a0)->f0 + i * 4);
}




/*
 * Four twelve-byte accessors on the 8-byte record array that func_02048918
 * walks: two halfword getters at +0x1a and +0x1c of record `i`, and two word
 * getters through the pointers at +0 and +0xc of a different object.
 *
 * None of them carries a label in the generated listing: they are leaves whose
 * prologue saves nothing, and `disasm.py` only auto-labels a function whose
 * prologue saves `lr`
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  They were
 * read out of the bytes.  The worklist's own function list for pkt_02048330
 * stops at the labelled bodies, so these four are the 48-byte hole between
 * func_02048918 and func_02048A24 - the range is contiguous and this unit
 * reproduces all of it.
 *
 * Three of the four instructions in the first pair are the same in both:
 * `add r0, r0, r1, lsl #3` is the record stride of 8 folded into the add, and
 * the halfword offset rides in the load.
 */
u32 sub_02048A18(u8 *a0, int i)
{
    return *(u32 *)((u8 *)((struct Obj17330 *)a0)->fC + i * 4);
}




/*
 * Constructor for a 0x44-byte record: eight words straight from the
 * parameters, then three 12-byte (three-word) aggregates at +0x20, +0x2C and
 * +0x38, each copied with `ldm`/`stm` because a three-word aggregate is above
 * the point where the compiler moves them word by word.  The last parameter
 * is a `u16` heap id -- it arrives at [sp+0x34] and is read with `ldrh`, and
 * it is forwarded widened to the allocator, which is the same
 * func_02030734(heap, size, 0, file, line) debug allocator every other site
 * in src/matched/ spells the same way (the pool word is this translation
 * unit's allocation-site string, 0x020A7EC4).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02048A24.c \
 *       --func func_02048A24 --addr 0x02048A24 --cc 1.1p1 --arm
 */
u32 *func_02048A24(u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8,
                   Vec3 *a9, Vec3 *a10, Vec3 *a11, u16 heap)
{
    u32 *p = (u32 *)func_02030734(heap, 0x44, 0, g_020A7EC4, 0x38);

    p[0] = a1;
    p[1] = a2;
    p[2] = a3;
    p[3] = a4;
    p[4] = a5;
    p[5] = a6;
    p[6] = a7;
    p[7] = a8;
    *(Vec3 *)(p + 8) = *a9;
    *(Vec3 *)(p + 11) = *a10;
    *(Vec3 *)(p + 14) = *a11;
    return p;
}




u32 func_02048AC4(void *ptr)
{
    return func_020307B0(ptr);
}




/*
 * g3d_light.c's accessor run, 0x02048AD0-0x02048BC4.  Seventeen functions,
 * fifteen of them `bx lr` leaves that save no lr and therefore carry no
 * disasm.py label of their own (see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); the whole run
 * is one translation unit.
 *
 *   0x02048AD0  two-stage reset: the sibling at 0x02046858 over the object,
 *               then 0x02046B40 over the vector block at +0x20
 *   0x02048AE8  read the vector at +0x20 out to the caller's VecFx32
 *   0x02048AFC  write it
 *   0x02048B0C  read the vector at +0x2C, 0x02048B20 writes it
 *   0x02048B30  read the vector at +0x38, 0x02048B44 writes it
 *   0x02048B54  read +0x14 out through a pointer, 0x02048B60 writes it
 *   0x02048B6C  write +0x18 through a pointer
 *   0x02048B78  return +0x00 by value
 *   0x02048B80  store +0x04 by value
 *   0x02048B88  read +0x08 out through a pointer, 0x02048B94 stores it by
 *               value
 *   0x02048B9C  read +0x04 out through a pointer, 0x02048BA8 stores it
 *   0x02048BB0  read +0x08 out through a pointer, 0x02048BBC stores it
 *
 * The last six are byte-for-byte duplicates of the pair at 0x02048B80 and
 * 0x02048B88: the same three offsets accessed twice over, which is what a
 * second object type sharing the first three words looks like in source.
 * They are written out here as separate functions over a second struct tag
 * rather than folded, because the image has six separate entry points.
 *
 * The twelve-byte vector moves are plain aggregate assignments; the paired
 * `ldm`/`stm` is the inlined struct copy, not a loop
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02048AD0.c \
 *       --addr 0x02048AD0 --cc 1.1p1 --arm
 */
void func_02048AD0(struct Light *l)
{
    func_02046858((const u32 *)l);
    func_02046B40((u8 *)(&l->unk20));
}



/*
 * g3d_light.c's accessor run, 0x02048AD0-0x02048BC4.  Seventeen functions,
 * fifteen of them `bx lr` leaves that save no lr and therefore carry no
 * disasm.py label of their own (see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); the whole run
 * is one translation unit.
 *
 *   0x02048AD0  two-stage reset: the sibling at 0x02046858 over the object,
 *               then 0x02046B40 over the vector block at +0x20
 *   0x02048AE8  read the vector at +0x20 out to the caller's VecFx32
 *   0x02048AFC  write it
 *   0x02048B0C  read the vector at +0x2C, 0x02048B20 writes it
 *   0x02048B30  read the vector at +0x38, 0x02048B44 writes it
 *   0x02048B54  read +0x14 out through a pointer, 0x02048B60 writes it
 *   0x02048B6C  write +0x18 through a pointer
 *   0x02048B78  return +0x00 by value
 *   0x02048B80  store +0x04 by value
 *   0x02048B88  read +0x08 out through a pointer, 0x02048B94 stores it by
 *               value
 *   0x02048B9C  read +0x04 out through a pointer, 0x02048BA8 stores it
 *   0x02048BB0  read +0x08 out through a pointer, 0x02048BBC stores it
 *
 * The last six are byte-for-byte duplicates of the pair at 0x02048B80 and
 * 0x02048B88: the same three offsets accessed twice over, which is what a
 * second object type sharing the first three words looks like in source.
 * They are written out here as separate functions over a second struct tag
 * rather than folded, because the image has six separate entry points.
 *
 * The twelve-byte vector moves are plain aggregate assignments; the paired
 * `ldm`/`stm` is the inlined struct copy, not a loop
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02048AD0.c \
 *       --addr 0x02048AD0 --cc 1.1p1 --arm
 */
void func_02048AE8(struct Light *l, VecFx32 *out)
{
    *out = l->unk20;
}



/*
 * g3d_light.c's accessor run, 0x02048AD0-0x02048BC4.  Seventeen functions,
 * fifteen of them `bx lr` leaves that save no lr and therefore carry no
 * disasm.py label of their own (see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); the whole run
 * is one translation unit.
 *
 *   0x02048AD0  two-stage reset: the sibling at 0x02046858 over the object,
 *               then 0x02046B40 over the vector block at +0x20
 *   0x02048AE8  read the vector at +0x20 out to the caller's VecFx32
 *   0x02048AFC  write it
 *   0x02048B0C  read the vector at +0x2C, 0x02048B20 writes it
 *   0x02048B30  read the vector at +0x38, 0x02048B44 writes it
 *   0x02048B54  read +0x14 out through a pointer, 0x02048B60 writes it
 *   0x02048B6C  write +0x18 through a pointer
 *   0x02048B78  return +0x00 by value
 *   0x02048B80  store +0x04 by value
 *   0x02048B88  read +0x08 out through a pointer, 0x02048B94 stores it by
 *               value
 *   0x02048B9C  read +0x04 out through a pointer, 0x02048BA8 stores it
 *   0x02048BB0  read +0x08 out through a pointer, 0x02048BBC stores it
 *
 * The last six are byte-for-byte duplicates of the pair at 0x02048B80 and
 * 0x02048B88: the same three offsets accessed twice over, which is what a
 * second object type sharing the first three words looks like in source.
 * They are written out here as separate functions over a second struct tag
 * rather than folded, because the image has six separate entry points.
 *
 * The twelve-byte vector moves are plain aggregate assignments; the paired
 * `ldm`/`stm` is the inlined struct copy, not a loop
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02048AD0.c \
 *       --addr 0x02048AD0 --cc 1.1p1 --arm
 */
void func_02048AFC(struct Light *l, const VecFx32 *in)
{
    l->unk20 = *in;
}



/*
 * g3d_light.c's accessor run, 0x02048AD0-0x02048BC4.  Seventeen functions,
 * fifteen of them `bx lr` leaves that save no lr and therefore carry no
 * disasm.py label of their own (see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); the whole run
 * is one translation unit.
 *
 *   0x02048AD0  two-stage reset: the sibling at 0x02046858 over the object,
 *               then 0x02046B40 over the vector block at +0x20
 *   0x02048AE8  read the vector at +0x20 out to the caller's VecFx32
 *   0x02048AFC  write it
 *   0x02048B0C  read the vector at +0x2C, 0x02048B20 writes it
 *   0x02048B30  read the vector at +0x38, 0x02048B44 writes it
 *   0x02048B54  read +0x14 out through a pointer, 0x02048B60 writes it
 *   0x02048B6C  write +0x18 through a pointer
 *   0x02048B78  return +0x00 by value
 *   0x02048B80  store +0x04 by value
 *   0x02048B88  read +0x08 out through a pointer, 0x02048B94 stores it by
 *               value
 *   0x02048B9C  read +0x04 out through a pointer, 0x02048BA8 stores it
 *   0x02048BB0  read +0x08 out through a pointer, 0x02048BBC stores it
 *
 * The last six are byte-for-byte duplicates of the pair at 0x02048B80 and
 * 0x02048B88: the same three offsets accessed twice over, which is what a
 * second object type sharing the first three words looks like in source.
 * They are written out here as separate functions over a second struct tag
 * rather than folded, because the image has six separate entry points.
 *
 * The twelve-byte vector moves are plain aggregate assignments; the paired
 * `ldm`/`stm` is the inlined struct copy, not a loop
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02048AD0.c \
 *       --addr 0x02048AD0 --cc 1.1p1 --arm
 */
void func_02048B0C(struct Light *l, VecFx32 *out)
{
    *out = l->unk2C;
}



/*
 * g3d_light.c's accessor run, 0x02048AD0-0x02048BC4.  Seventeen functions,
 * fifteen of them `bx lr` leaves that save no lr and therefore carry no
 * disasm.py label of their own (see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); the whole run
 * is one translation unit.
 *
 *   0x02048AD0  two-stage reset: the sibling at 0x02046858 over the object,
 *               then 0x02046B40 over the vector block at +0x20
 *   0x02048AE8  read the vector at +0x20 out to the caller's VecFx32
 *   0x02048AFC  write it
 *   0x02048B0C  read the vector at +0x2C, 0x02048B20 writes it
 *   0x02048B30  read the vector at +0x38, 0x02048B44 writes it
 *   0x02048B54  read +0x14 out through a pointer, 0x02048B60 writes it
 *   0x02048B6C  write +0x18 through a pointer
 *   0x02048B78  return +0x00 by value
 *   0x02048B80  store +0x04 by value
 *   0x02048B88  read +0x08 out through a pointer, 0x02048B94 stores it by
 *               value
 *   0x02048B9C  read +0x04 out through a pointer, 0x02048BA8 stores it
 *   0x02048BB0  read +0x08 out through a pointer, 0x02048BBC stores it
 *
 * The last six are byte-for-byte duplicates of the pair at 0x02048B80 and
 * 0x02048B88: the same three offsets accessed twice over, which is what a
 * second object type sharing the first three words looks like in source.
 * They are written out here as separate functions over a second struct tag
 * rather than folded, because the image has six separate entry points.
 *
 * The twelve-byte vector moves are plain aggregate assignments; the paired
 * `ldm`/`stm` is the inlined struct copy, not a loop
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02048AD0.c \
 *       --addr 0x02048AD0 --cc 1.1p1 --arm
 */
void func_02048B20(struct Light *l, const VecFx32 *in)
{
    l->unk2C = *in;
}



/*
 * g3d_light.c's accessor run, 0x02048AD0-0x02048BC4.  Seventeen functions,
 * fifteen of them `bx lr` leaves that save no lr and therefore carry no
 * disasm.py label of their own (see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); the whole run
 * is one translation unit.
 *
 *   0x02048AD0  two-stage reset: the sibling at 0x02046858 over the object,
 *               then 0x02046B40 over the vector block at +0x20
 *   0x02048AE8  read the vector at +0x20 out to the caller's VecFx32
 *   0x02048AFC  write it
 *   0x02048B0C  read the vector at +0x2C, 0x02048B20 writes it
 *   0x02048B30  read the vector at +0x38, 0x02048B44 writes it
 *   0x02048B54  read +0x14 out through a pointer, 0x02048B60 writes it
 *   0x02048B6C  write +0x18 through a pointer
 *   0x02048B78  return +0x00 by value
 *   0x02048B80  store +0x04 by value
 *   0x02048B88  read +0x08 out through a pointer, 0x02048B94 stores it by
 *               value
 *   0x02048B9C  read +0x04 out through a pointer, 0x02048BA8 stores it
 *   0x02048BB0  read +0x08 out through a pointer, 0x02048BBC stores it
 *
 * The last six are byte-for-byte duplicates of the pair at 0x02048B80 and
 * 0x02048B88: the same three offsets accessed twice over, which is what a
 * second object type sharing the first three words looks like in source.
 * They are written out here as separate functions over a second struct tag
 * rather than folded, because the image has six separate entry points.
 *
 * The twelve-byte vector moves are plain aggregate assignments; the paired
 * `ldm`/`stm` is the inlined struct copy, not a loop
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02048AD0.c \
 *       --addr 0x02048AD0 --cc 1.1p1 --arm
 */
void func_02048B30(struct Light *l, VecFx32 *out)
{
    *out = l->unk38;
}



/*
 * g3d_light.c's accessor run, 0x02048AD0-0x02048BC4.  Seventeen functions,
 * fifteen of them `bx lr` leaves that save no lr and therefore carry no
 * disasm.py label of their own (see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); the whole run
 * is one translation unit.
 *
 *   0x02048AD0  two-stage reset: the sibling at 0x02046858 over the object,
 *               then 0x02046B40 over the vector block at +0x20
 *   0x02048AE8  read the vector at +0x20 out to the caller's VecFx32
 *   0x02048AFC  write it
 *   0x02048B0C  read the vector at +0x2C, 0x02048B20 writes it
 *   0x02048B30  read the vector at +0x38, 0x02048B44 writes it
 *   0x02048B54  read +0x14 out through a pointer, 0x02048B60 writes it
 *   0x02048B6C  write +0x18 through a pointer
 *   0x02048B78  return +0x00 by value
 *   0x02048B80  store +0x04 by value
 *   0x02048B88  read +0x08 out through a pointer, 0x02048B94 stores it by
 *               value
 *   0x02048B9C  read +0x04 out through a pointer, 0x02048BA8 stores it
 *   0x02048BB0  read +0x08 out through a pointer, 0x02048BBC stores it
 *
 * The last six are byte-for-byte duplicates of the pair at 0x02048B80 and
 * 0x02048B88: the same three offsets accessed twice over, which is what a
 * second object type sharing the first three words looks like in source.
 * They are written out here as separate functions over a second struct tag
 * rather than folded, because the image has six separate entry points.
 *
 * The twelve-byte vector moves are plain aggregate assignments; the paired
 * `ldm`/`stm` is the inlined struct copy, not a loop
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02048AD0.c \
 *       --addr 0x02048AD0 --cc 1.1p1 --arm
 */
void func_02048B44(struct Light *l, const VecFx32 *in)
{
    l->unk38 = *in;
}



/*
 * g3d_light.c's accessor run, 0x02048AD0-0x02048BC4.  Seventeen functions,
 * fifteen of them `bx lr` leaves that save no lr and therefore carry no
 * disasm.py label of their own (see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); the whole run
 * is one translation unit.
 *
 *   0x02048AD0  two-stage reset: the sibling at 0x02046858 over the object,
 *               then 0x02046B40 over the vector block at +0x20
 *   0x02048AE8  read the vector at +0x20 out to the caller's VecFx32
 *   0x02048AFC  write it
 *   0x02048B0C  read the vector at +0x2C, 0x02048B20 writes it
 *   0x02048B30  read the vector at +0x38, 0x02048B44 writes it
 *   0x02048B54  read +0x14 out through a pointer, 0x02048B60 writes it
 *   0x02048B6C  write +0x18 through a pointer
 *   0x02048B78  return +0x00 by value
 *   0x02048B80  store +0x04 by value
 *   0x02048B88  read +0x08 out through a pointer, 0x02048B94 stores it by
 *               value
 *   0x02048B9C  read +0x04 out through a pointer, 0x02048BA8 stores it
 *   0x02048BB0  read +0x08 out through a pointer, 0x02048BBC stores it
 *
 * The last six are byte-for-byte duplicates of the pair at 0x02048B80 and
 * 0x02048B88: the same three offsets accessed twice over, which is what a
 * second object type sharing the first three words looks like in source.
 * They are written out here as separate functions over a second struct tag
 * rather than folded, because the image has six separate entry points.
 *
 * The twelve-byte vector moves are plain aggregate assignments; the paired
 * `ldm`/`stm` is the inlined struct copy, not a loop
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02048AD0.c \
 *       --addr 0x02048AD0 --cc 1.1p1 --arm
 */
void func_02048B54(struct Light *l, u32 *out)
{
    *out = l->unk14;
}



/*
 * g3d_light.c's accessor run, 0x02048AD0-0x02048BC4.  Seventeen functions,
 * fifteen of them `bx lr` leaves that save no lr and therefore carry no
 * disasm.py label of their own (see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); the whole run
 * is one translation unit.
 *
 *   0x02048AD0  two-stage reset: the sibling at 0x02046858 over the object,
 *               then 0x02046B40 over the vector block at +0x20
 *   0x02048AE8  read the vector at +0x20 out to the caller's VecFx32
 *   0x02048AFC  write it
 *   0x02048B0C  read the vector at +0x2C, 0x02048B20 writes it
 *   0x02048B30  read the vector at +0x38, 0x02048B44 writes it
 *   0x02048B54  read +0x14 out through a pointer, 0x02048B60 writes it
 *   0x02048B6C  write +0x18 through a pointer
 *   0x02048B78  return +0x00 by value
 *   0x02048B80  store +0x04 by value
 *   0x02048B88  read +0x08 out through a pointer, 0x02048B94 stores it by
 *               value
 *   0x02048B9C  read +0x04 out through a pointer, 0x02048BA8 stores it
 *   0x02048BB0  read +0x08 out through a pointer, 0x02048BBC stores it
 *
 * The last six are byte-for-byte duplicates of the pair at 0x02048B80 and
 * 0x02048B88: the same three offsets accessed twice over, which is what a
 * second object type sharing the first three words looks like in source.
 * They are written out here as separate functions over a second struct tag
 * rather than folded, because the image has six separate entry points.
 *
 * The twelve-byte vector moves are plain aggregate assignments; the paired
 * `ldm`/`stm` is the inlined struct copy, not a loop
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02048AD0.c \
 *       --addr 0x02048AD0 --cc 1.1p1 --arm
 */
void func_02048B60(struct Light *l, const u32 *in)
{
    l->unk14 = *in;
}



/*
 * g3d_light.c's accessor run, 0x02048AD0-0x02048BC4.  Seventeen functions,
 * fifteen of them `bx lr` leaves that save no lr and therefore carry no
 * disasm.py label of their own (see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); the whole run
 * is one translation unit.
 *
 *   0x02048AD0  two-stage reset: the sibling at 0x02046858 over the object,
 *               then 0x02046B40 over the vector block at +0x20
 *   0x02048AE8  read the vector at +0x20 out to the caller's VecFx32
 *   0x02048AFC  write it
 *   0x02048B0C  read the vector at +0x2C, 0x02048B20 writes it
 *   0x02048B30  read the vector at +0x38, 0x02048B44 writes it
 *   0x02048B54  read +0x14 out through a pointer, 0x02048B60 writes it
 *   0x02048B6C  write +0x18 through a pointer
 *   0x02048B78  return +0x00 by value
 *   0x02048B80  store +0x04 by value
 *   0x02048B88  read +0x08 out through a pointer, 0x02048B94 stores it by
 *               value
 *   0x02048B9C  read +0x04 out through a pointer, 0x02048BA8 stores it
 *   0x02048BB0  read +0x08 out through a pointer, 0x02048BBC stores it
 *
 * The last six are byte-for-byte duplicates of the pair at 0x02048B80 and
 * 0x02048B88: the same three offsets accessed twice over, which is what a
 * second object type sharing the first three words looks like in source.
 * They are written out here as separate functions over a second struct tag
 * rather than folded, because the image has six separate entry points.
 *
 * The twelve-byte vector moves are plain aggregate assignments; the paired
 * `ldm`/`stm` is the inlined struct copy, not a loop
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02048AD0.c \
 *       --addr 0x02048AD0 --cc 1.1p1 --arm
 */
void func_02048B6C(struct Light *l, const u32 *in)
{
    l->unk18 = *in;
}



/*
 * g3d_light.c's accessor run, 0x02048AD0-0x02048BC4.  Seventeen functions,
 * fifteen of them `bx lr` leaves that save no lr and therefore carry no
 * disasm.py label of their own (see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); the whole run
 * is one translation unit.
 *
 *   0x02048AD0  two-stage reset: the sibling at 0x02046858 over the object,
 *               then 0x02046B40 over the vector block at +0x20
 *   0x02048AE8  read the vector at +0x20 out to the caller's VecFx32
 *   0x02048AFC  write it
 *   0x02048B0C  read the vector at +0x2C, 0x02048B20 writes it
 *   0x02048B30  read the vector at +0x38, 0x02048B44 writes it
 *   0x02048B54  read +0x14 out through a pointer, 0x02048B60 writes it
 *   0x02048B6C  write +0x18 through a pointer
 *   0x02048B78  return +0x00 by value
 *   0x02048B80  store +0x04 by value
 *   0x02048B88  read +0x08 out through a pointer, 0x02048B94 stores it by
 *               value
 *   0x02048B9C  read +0x04 out through a pointer, 0x02048BA8 stores it
 *   0x02048BB0  read +0x08 out through a pointer, 0x02048BBC stores it
 *
 * The last six are byte-for-byte duplicates of the pair at 0x02048B80 and
 * 0x02048B88: the same three offsets accessed twice over, which is what a
 * second object type sharing the first three words looks like in source.
 * They are written out here as separate functions over a second struct tag
 * rather than folded, because the image has six separate entry points.
 *
 * The twelve-byte vector moves are plain aggregate assignments; the paired
 * `ldm`/`stm` is the inlined struct copy, not a loop
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02048AD0.c \
 *       --addr 0x02048AD0 --cc 1.1p1 --arm
 */
int func_02048B78(struct Light *l)
{
    return l->unk00;
}



/*
 * g3d_light.c's accessor run, 0x02048AD0-0x02048BC4.  Seventeen functions,
 * fifteen of them `bx lr` leaves that save no lr and therefore carry no
 * disasm.py label of their own (see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); the whole run
 * is one translation unit.
 *
 *   0x02048AD0  two-stage reset: the sibling at 0x02046858 over the object,
 *               then 0x02046B40 over the vector block at +0x20
 *   0x02048AE8  read the vector at +0x20 out to the caller's VecFx32
 *   0x02048AFC  write it
 *   0x02048B0C  read the vector at +0x2C, 0x02048B20 writes it
 *   0x02048B30  read the vector at +0x38, 0x02048B44 writes it
 *   0x02048B54  read +0x14 out through a pointer, 0x02048B60 writes it
 *   0x02048B6C  write +0x18 through a pointer
 *   0x02048B78  return +0x00 by value
 *   0x02048B80  store +0x04 by value
 *   0x02048B88  read +0x08 out through a pointer, 0x02048B94 stores it by
 *               value
 *   0x02048B9C  read +0x04 out through a pointer, 0x02048BA8 stores it
 *   0x02048BB0  read +0x08 out through a pointer, 0x02048BBC stores it
 *
 * The last six are byte-for-byte duplicates of the pair at 0x02048B80 and
 * 0x02048B88: the same three offsets accessed twice over, which is what a
 * second object type sharing the first three words looks like in source.
 * They are written out here as separate functions over a second struct tag
 * rather than folded, because the image has six separate entry points.
 *
 * The twelve-byte vector moves are plain aggregate assignments; the paired
 * `ldm`/`stm` is the inlined struct copy, not a loop
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02048AD0.c \
 *       --addr 0x02048AD0 --cc 1.1p1 --arm
 */
void func_02048B80(struct Light *l, u32 v)
{
    l->unk04 = v;
}



/*
 * g3d_light.c's accessor run, 0x02048AD0-0x02048BC4.  Seventeen functions,
 * fifteen of them `bx lr` leaves that save no lr and therefore carry no
 * disasm.py label of their own (see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); the whole run
 * is one translation unit.
 *
 *   0x02048AD0  two-stage reset: the sibling at 0x02046858 over the object,
 *               then 0x02046B40 over the vector block at +0x20
 *   0x02048AE8  read the vector at +0x20 out to the caller's VecFx32
 *   0x02048AFC  write it
 *   0x02048B0C  read the vector at +0x2C, 0x02048B20 writes it
 *   0x02048B30  read the vector at +0x38, 0x02048B44 writes it
 *   0x02048B54  read +0x14 out through a pointer, 0x02048B60 writes it
 *   0x02048B6C  write +0x18 through a pointer
 *   0x02048B78  return +0x00 by value
 *   0x02048B80  store +0x04 by value
 *   0x02048B88  read +0x08 out through a pointer, 0x02048B94 stores it by
 *               value
 *   0x02048B9C  read +0x04 out through a pointer, 0x02048BA8 stores it
 *   0x02048BB0  read +0x08 out through a pointer, 0x02048BBC stores it
 *
 * The last six are byte-for-byte duplicates of the pair at 0x02048B80 and
 * 0x02048B88: the same three offsets accessed twice over, which is what a
 * second object type sharing the first three words looks like in source.
 * They are written out here as separate functions over a second struct tag
 * rather than folded, because the image has six separate entry points.
 *
 * The twelve-byte vector moves are plain aggregate assignments; the paired
 * `ldm`/`stm` is the inlined struct copy, not a loop
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02048AD0.c \
 *       --addr 0x02048AD0 --cc 1.1p1 --arm
 */
void func_02048B88(struct Light *l, u32 *out)
{
    *out = l->unk08;
}



/*
 * g3d_light.c's accessor run, 0x02048AD0-0x02048BC4.  Seventeen functions,
 * fifteen of them `bx lr` leaves that save no lr and therefore carry no
 * disasm.py label of their own (see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); the whole run
 * is one translation unit.
 *
 *   0x02048AD0  two-stage reset: the sibling at 0x02046858 over the object,
 *               then 0x02046B40 over the vector block at +0x20
 *   0x02048AE8  read the vector at +0x20 out to the caller's VecFx32
 *   0x02048AFC  write it
 *   0x02048B0C  read the vector at +0x2C, 0x02048B20 writes it
 *   0x02048B30  read the vector at +0x38, 0x02048B44 writes it
 *   0x02048B54  read +0x14 out through a pointer, 0x02048B60 writes it
 *   0x02048B6C  write +0x18 through a pointer
 *   0x02048B78  return +0x00 by value
 *   0x02048B80  store +0x04 by value
 *   0x02048B88  read +0x08 out through a pointer, 0x02048B94 stores it by
 *               value
 *   0x02048B9C  read +0x04 out through a pointer, 0x02048BA8 stores it
 *   0x02048BB0  read +0x08 out through a pointer, 0x02048BBC stores it
 *
 * The last six are byte-for-byte duplicates of the pair at 0x02048B80 and
 * 0x02048B88: the same three offsets accessed twice over, which is what a
 * second object type sharing the first three words looks like in source.
 * They are written out here as separate functions over a second struct tag
 * rather than folded, because the image has six separate entry points.
 *
 * The twelve-byte vector moves are plain aggregate assignments; the paired
 * `ldm`/`stm` is the inlined struct copy, not a loop
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02048AD0.c \
 *       --addr 0x02048AD0 --cc 1.1p1 --arm
 */
void func_02048B94(struct Light *l, u32 v)
{
    l->unk08 = v;
}



/*
 * g3d_light.c's accessor run, 0x02048AD0-0x02048BC4.  Seventeen functions,
 * fifteen of them `bx lr` leaves that save no lr and therefore carry no
 * disasm.py label of their own (see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); the whole run
 * is one translation unit.
 *
 *   0x02048AD0  two-stage reset: the sibling at 0x02046858 over the object,
 *               then 0x02046B40 over the vector block at +0x20
 *   0x02048AE8  read the vector at +0x20 out to the caller's VecFx32
 *   0x02048AFC  write it
 *   0x02048B0C  read the vector at +0x2C, 0x02048B20 writes it
 *   0x02048B30  read the vector at +0x38, 0x02048B44 writes it
 *   0x02048B54  read +0x14 out through a pointer, 0x02048B60 writes it
 *   0x02048B6C  write +0x18 through a pointer
 *   0x02048B78  return +0x00 by value
 *   0x02048B80  store +0x04 by value
 *   0x02048B88  read +0x08 out through a pointer, 0x02048B94 stores it by
 *               value
 *   0x02048B9C  read +0x04 out through a pointer, 0x02048BA8 stores it
 *   0x02048BB0  read +0x08 out through a pointer, 0x02048BBC stores it
 *
 * The last six are byte-for-byte duplicates of the pair at 0x02048B80 and
 * 0x02048B88: the same three offsets accessed twice over, which is what a
 * second object type sharing the first three words looks like in source.
 * They are written out here as separate functions over a second struct tag
 * rather than folded, because the image has six separate entry points.
 *
 * The twelve-byte vector moves are plain aggregate assignments; the paired
 * `ldm`/`stm` is the inlined struct copy, not a loop
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02048AD0.c \
 *       --addr 0x02048AD0 --cc 1.1p1 --arm
 */
void func_02048B9C(struct Light *l, u32 *out)
{
    *out = l->unk04;
}



/*
 * g3d_light.c's accessor run, 0x02048AD0-0x02048BC4.  Seventeen functions,
 * fifteen of them `bx lr` leaves that save no lr and therefore carry no
 * disasm.py label of their own (see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); the whole run
 * is one translation unit.
 *
 *   0x02048AD0  two-stage reset: the sibling at 0x02046858 over the object,
 *               then 0x02046B40 over the vector block at +0x20
 *   0x02048AE8  read the vector at +0x20 out to the caller's VecFx32
 *   0x02048AFC  write it
 *   0x02048B0C  read the vector at +0x2C, 0x02048B20 writes it
 *   0x02048B30  read the vector at +0x38, 0x02048B44 writes it
 *   0x02048B54  read +0x14 out through a pointer, 0x02048B60 writes it
 *   0x02048B6C  write +0x18 through a pointer
 *   0x02048B78  return +0x00 by value
 *   0x02048B80  store +0x04 by value
 *   0x02048B88  read +0x08 out through a pointer, 0x02048B94 stores it by
 *               value
 *   0x02048B9C  read +0x04 out through a pointer, 0x02048BA8 stores it
 *   0x02048BB0  read +0x08 out through a pointer, 0x02048BBC stores it
 *
 * The last six are byte-for-byte duplicates of the pair at 0x02048B80 and
 * 0x02048B88: the same three offsets accessed twice over, which is what a
 * second object type sharing the first three words looks like in source.
 * They are written out here as separate functions over a second struct tag
 * rather than folded, because the image has six separate entry points.
 *
 * The twelve-byte vector moves are plain aggregate assignments; the paired
 * `ldm`/`stm` is the inlined struct copy, not a loop
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02048AD0.c \
 *       --addr 0x02048AD0 --cc 1.1p1 --arm
 */
void func_02048BA8(struct Light *l, u32 v)
{
    l->unk04 = v;
}



/*
 * g3d_light.c's accessor run, 0x02048AD0-0x02048BC4.  Seventeen functions,
 * fifteen of them `bx lr` leaves that save no lr and therefore carry no
 * disasm.py label of their own (see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); the whole run
 * is one translation unit.
 *
 *   0x02048AD0  two-stage reset: the sibling at 0x02046858 over the object,
 *               then 0x02046B40 over the vector block at +0x20
 *   0x02048AE8  read the vector at +0x20 out to the caller's VecFx32
 *   0x02048AFC  write it
 *   0x02048B0C  read the vector at +0x2C, 0x02048B20 writes it
 *   0x02048B30  read the vector at +0x38, 0x02048B44 writes it
 *   0x02048B54  read +0x14 out through a pointer, 0x02048B60 writes it
 *   0x02048B6C  write +0x18 through a pointer
 *   0x02048B78  return +0x00 by value
 *   0x02048B80  store +0x04 by value
 *   0x02048B88  read +0x08 out through a pointer, 0x02048B94 stores it by
 *               value
 *   0x02048B9C  read +0x04 out through a pointer, 0x02048BA8 stores it
 *   0x02048BB0  read +0x08 out through a pointer, 0x02048BBC stores it
 *
 * The last six are byte-for-byte duplicates of the pair at 0x02048B80 and
 * 0x02048B88: the same three offsets accessed twice over, which is what a
 * second object type sharing the first three words looks like in source.
 * They are written out here as separate functions over a second struct tag
 * rather than folded, because the image has six separate entry points.
 *
 * The twelve-byte vector moves are plain aggregate assignments; the paired
 * `ldm`/`stm` is the inlined struct copy, not a loop
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02048AD0.c \
 *       --addr 0x02048AD0 --cc 1.1p1 --arm
 */
void func_02048BB0(struct Light *l, u32 *out)
{
    *out = l->unk08;
}



/*
 * g3d_light.c's accessor run, 0x02048AD0-0x02048BC4.  Seventeen functions,
 * fifteen of them `bx lr` leaves that save no lr and therefore carry no
 * disasm.py label of their own (see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); the whole run
 * is one translation unit.
 *
 *   0x02048AD0  two-stage reset: the sibling at 0x02046858 over the object,
 *               then 0x02046B40 over the vector block at +0x20
 *   0x02048AE8  read the vector at +0x20 out to the caller's VecFx32
 *   0x02048AFC  write it
 *   0x02048B0C  read the vector at +0x2C, 0x02048B20 writes it
 *   0x02048B30  read the vector at +0x38, 0x02048B44 writes it
 *   0x02048B54  read +0x14 out through a pointer, 0x02048B60 writes it
 *   0x02048B6C  write +0x18 through a pointer
 *   0x02048B78  return +0x00 by value
 *   0x02048B80  store +0x04 by value
 *   0x02048B88  read +0x08 out through a pointer, 0x02048B94 stores it by
 *               value
 *   0x02048B9C  read +0x04 out through a pointer, 0x02048BA8 stores it
 *   0x02048BB0  read +0x08 out through a pointer, 0x02048BBC stores it
 *
 * The last six are byte-for-byte duplicates of the pair at 0x02048B80 and
 * 0x02048B88: the same three offsets accessed twice over, which is what a
 * second object type sharing the first three words looks like in source.
 * They are written out here as separate functions over a second struct tag
 * rather than folded, because the image has six separate entry points.
 *
 * The twelve-byte vector moves are plain aggregate assignments; the paired
 * `ldm`/`stm` is the inlined struct copy, not a loop
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02048AD0.c \
 *       --addr 0x02048AD0 --cc 1.1p1 --arm
 */
void func_02048BBC(struct Light *l, u32 v)
{
    l->unk08 = v;
}


/*
 * g3d_light.c's light-set builder, 0x02048BC4-0x02048C48 plus its one pool
 * word.  It allocates a 0x20-byte table of four eight-byte slots through the
 * debug allocator at 0x02030734 (file 0x020A7ED4, which spells "g3d_light.c",
 * line 43) and scatters a packed ten-byte record array into it: each record
 * names its destination slot in its first byte and carries four halfwords.
 *
 * The record stride is a `mov r2, #0xa` and a `mul`, not a shift chain, so
 * the record really is ten bytes wide and the index really is an `int`.
 *
 * The loop bound is an unsigned char compared signed (`ble` on the rotation
 * test, `blt` on the back edge), which is the plain `int i; i < s->count`
 * shape after integer promotion, not an unsigned loop.
 *
 * The header pointer is `const`, and that is the whole difference between
 * this file and a sixteen-byte-longer near miss: both `s->recs` and
 * `s->count` are still reloaded on every iteration, but with `const` the
 * closing test's `ldrb r3, [r4, #4]` schedules at the *top* of the body,
 * above the halfword stores, which costs one more callee-saved register and
 * turns the five-register push into the six-register one that carries the
 * outgoing fifth argument without a `sub sp, sp, #4`.  See
 * docs/idioms/const-hoists-the-loop-test-load-above-the-body-stores.md.
 *
 * The next thing in the image after this function's pool is the eight-byte
 * ARM long-branch veneer at 0x02048C4C, so no unit may run past 0x02048C4C
 * (docs/idioms/a-four-byte-arm-function-in-a-thumb-packet-is-a-long-branch-veneer.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02048BC4.c \
 *       --addr 0x02048BC4 --cc 1.1p1 --arm
 */
struct LightSlot *func_02048BC4(const struct LightSet *s, u16 heap)
{
    struct LightSlot *out;
    int i;

    out = (struct LightSlot *)func_02030734(heap, 0x20, 1,
                                            func_02048BC4_File, 43);
    for (i = 0; i < s->count; i++) {
        struct LightRec *r = &s->recs[i];
        u32 slot = r->slot;

        out[slot] = r->val;
    }
    return out;
}
