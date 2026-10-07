/*
 * file:     unit_021C75E4_p01.c
 * unit:     yes
 * function: func_021C75E4, func_021C7658, func_021C76A4, func_021C7730, func_021C7744, func_021C7808, func_021C7830, func_021C78C4, func_021C78F8, func_021C7908, func_021C7934, func_021C795C, func_021C7970, func_021C79A0, func_021C79B8, func_021C79D0, func_021C79F4, func_021C7A44, func_021C7A70, func_021C7AD4
 * address:  0x021C75E4
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   d_021C8AA0  0x021C8AA0  data
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_02046440  0x02046440  arm
 *   func_02048BC4  0x02048BC4  arm
 *   func_02048C58  0x02048C58  arm
 *   func_02046858  0x02046858  arm
 *   func_02040588  0x02040588  arm
 *   d_021C8810  0x021C8810  data
 *   d_021C896C  0x021C896C  data
 *   FX_SinCosTable_  0x020A1B38  data
 *   func_02048C4C  0x02048C4C  arm
 *   func_02046788  0x02046788  arm
 *   func_02047CFC  0x02047CFC  arm
 *   func_02047E88  0x02047E88  arm
 *   func_02048A18  0x02048A18  arm
 *   func_0204779C  0x0204779C  arm
 *   func_020477A4  0x020477A4  arm
 *   func_02048A24  0x02048A24  arm
 *   d_021C8834  0x021C8834  data
 *   d_021C8950  0x021C8950  data
 *   d_021C8938  0x021C8938  data
 *   d_021C8944  0x021C8944  data
 *   func_02048AC4  0x02048AC4  arm
 *   func_020480E4  0x020480E4  arm
 *   func_02047E54  0x02047E54  arm
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_02048AD0  0x02048AD0  arm
 *   func_02047828  0x02047828  arm
 *   func_0204784C  0x0204784C  arm
 *   func_02047964  0x02047964  arm
 *   func_020479D8  0x020479D8  arm
 *   func_02047A60  0x02047A60  arm
 *   func_02047970  0x02047970  arm
 *   d_021C8E80  0x021C8E80  data
 *   func_02045088  0x02045088  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_020452E8  0x020452E8  arm
 *   func_020450C8  0x020450C8  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201C440  0x0201C440  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_0201D83C  0x0201D83C  thumb
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_0201C6C4  0x0201C6C4  thumb
 *   d_021C8E58  0x021C8E58  data
 *   func_020221A4  0x020221A4  thumb
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_021C7E48  0x021C7E48  thumb
 *   func_021C8364  0x021C8364  thumb
 *   func_0204B98C  0x0204B98C  arm
 *   func_0202208C  0x0202208C  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201C724  0x0201C724  thumb
 *   d_021C8894  0x021C8894  data
 */
struct Obj;
struct Bank;
struct LightSlot;
struct LightSet;
struct G3dSys;
struct Ctx;
struct Rec;
struct AnmCtl;
struct Light;
struct Arg;
struct CharBuf;
struct Descriptor;
struct Cfg;
struct GfFont;
struct PrintSys;
struct Actor;
struct MsgBank;
typedef unsigned char u8;

typedef unsigned short u16;

typedef struct {
    int x;
    int y;
    int z;
    int cell;
    int chr;
    int anm;
} ObjTemplate;

typedef struct {
    u16 x;
    u16 y;
    u16 z;
    u8 pri;
    u8 f7;
} ObjPos;

typedef struct {
    u8 pad0[0x48];
    void *res;
    void *obj[36];
    void *set[6];
} Work_021C75E4;

typedef unsigned int   u32;

typedef long long s64;

typedef unsigned long long u64;

typedef struct {
    u8 pad0[0xC];
    void *fC;
} Res;

typedef struct {
    u8 pad0[4];
    void *f4;
    u8 pad8[4];
    int fC;
    int f10;
} Parent;

typedef struct {
    void *f0;
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x20 - 0x18];
    void *f20;
    void *f24;
    void *f28;
    void *f2C[7];
    void *f48;
    void *f4C;
    void *f50;
    void *f54;
    void *f58;
    void *f5C[8];
    void *f7C[24];
    void *fDC;
    void *fE0;
    void *fE4;
    void *fE8;
    void *fEC;
    void *fF0;
    void *fF4;
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    Parent *f108;
    int state;
    int f110;
    u16 f114;
    u16 f116;
    int f118;
    int f11C;
    u8 pad120[0x140 - 0x120];
    int f140;
    int f144;
    u8 pad148[0x14C - 0x148];
    void *f14C[3];
    Res *f158[3];
    void *f164[3];
    u8 pad170[0x17C - 0x170];
    u8 f17C[8];
    void *f184;
    int f188[8];
    u8 f1A8[8];
    u8 f1B0[8];
} Work_021C7658;

typedef struct {
    void *f0;
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x20 - 0x18];
    void *f20;
    void *f24;
    void *f28;
    void *f2C[7];
    void *f48;
    void *f4C;
    void *f50;
    void *f54;
    void *f58;
    void *f5C[8];
    void *f7C[24];
    void *fDC;
    void *fE0;
    void *fE4;
    void *fE8;
    void *fEC;
    void *fF0;
    void *fF4;
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    Parent *f108;
    int state;
    int f110;
    u16 f114;
    u16 f116;
    int f118;
    int f11C;
    u8 pad120[0x140 - 0x120];
    int f140;
    int f144;
    u8 pad148[0x14C - 0x148];
    void *f14C[3];
    Res *f158[3];
    void *f164[3];
    Res *f170[3];
    u8 f17C[8];
    void *f184;
    int f188[8];
    u8 f1A8[8];
    u8 f1B0[8];
} Work_021C76A4;

typedef short s16;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
    int f1C;
} Camera;

typedef struct {
    unsigned char pad0[0x100];
    void *f100;
} Work_021C7730;

typedef struct {
    void *f0;
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x20 - 0x18];
    void *f20;
    void *f24;
    void *f28;
    void *f2C[7];
    void *f48;
    void *f4C;
    void *f50;
    void *f54;
    void *f58;
    void *f5C[8];
    void *f7C[24];
    void *fDC;
    void *fE0;
    void *fE4;
    void *fE8;
    void *fEC;
    void *fF0;
    void *fF4;
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    Parent *f108;
    int state;
    int f110;
    u16 f114;
    u16 f116;
    int f118;
    int f11C;
    u8 pad120[0x13C - 0x120];
    int f13C;
    int f140;
    int f144;
    u8 pad148[0x14C - 0x148];
    void *f14C[3];
    Res *f158[3];
    void *f164[3];
    Res *f170[3];
    u8 f17C[8];
    void *f184;
    int f188[8];
    u8 f1A8[8];
    u8 f1B0[8];
} Work_021C7744;

typedef int fx32;

typedef struct { fx32 x, y, z; } VecFx32;

typedef struct {
    u8 pad0[4];
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x7C - 0x18];
    void *f7C[4][3];
    u8 padAC[0xF8 - 0xAC];
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    u8 pad108[4];
    int state;
} Work_021C7808;

typedef struct {
    void *f0;
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x20 - 0x18];
    void *f20;
    void *f24;
    void *f28;
    void *f2C[7];
    void *f48;
    void *f4C;
    void *f50;
    void *f54;
    void *f58;
    void *f5C[8];
    void *f7C[24];
    void *fDC;
    void *fE0;
    void *fE4;
    void *fE8;
    void *fEC;
    void *fF0;
    void *fF4;
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    Parent *f108;
    int state;
    int f110;
    u16 f114;
    u16 f116;
    int f118;
    int f11C;
    u8 pad120[0x13C - 0x120];
    int f13C;
    int f140;
    int f144;
    u8 pad148[0x14C - 0x148];
    void *f14C[3];
    Res *f158[3];
    void *f164[3];
    Res *f170[3];
    u8 f17C[8];
    void *f184;
    int f188[8];
    u8 f1A8[8];
    u8 f1B0[8];
} Work_021C7830;

typedef struct { fx32 m[3][3]; } MtxFx33;

typedef struct {
    VecFx32 trans;
    VecFx32 scale;
    MtxFx33 rot;
} Transform;

typedef struct {
    int f0;
    int f4;
} Counter;

typedef signed int     s32;

typedef struct {
    u8 pad0[4];
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x58 - 0x18];
    void *f58;
    void *f5C[8];
    void *f7C[24];
    u8 padDC[0xF8 - 0xDC];
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    void *f108;
    int state;
    u8 pad110[4];
    u16 f114;
    u16 f116;
    int f118;
    int f11C;
    u8 pad120[0x140 - 0x120];
    int f140;
    u8 pad144[0x14C - 0x144];
    void *f14C[3];
    Res *f158[3];
    void *f164[3];
    u8 pad170[0x17C - 0x170];
    u8 f17C[8];
} Work_021C78C4;

typedef struct {
    u8 pad0[4];
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x7C - 0x18];
    void *f7C[4][3];
    u8 padAC[0xF8 - 0xAC];
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    u8 pad108[4];
    int state;
} Work_021C78F8;

typedef struct {
    u8 pad0[4];
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x7C - 0x18];
    void *f7C[4][3];
    u8 padAC[0xF8 - 0xAC];
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    u8 pad108[4];
    int state;
} Work_021C7908;

typedef struct {
    u8 pad0[4];
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x7C - 0x18];
    void *f7C[4][3];
    u8 padAC[0xF8 - 0xAC];
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    u8 pad108[4];
    int state;
} Work_021C7934;

typedef struct {
    unsigned char pad0[4];
    void *f4;
    unsigned char pad8[0xC];
    void *f14;
} Work_021C795C;

typedef struct {
    u8 pad0[4];
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x7C - 0x18];
    void *f7C[4][3];
    u8 padAC[0xF8 - 0xAC];
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    u8 pad108[4];
    int state;
} Work_021C7970;

typedef struct Work_021C79A0 Work_021C79A0;

struct Work_021C79A0 {
    unsigned char pad0[0x10C];
    int state;
};

typedef struct {
    unsigned char pad0[0x10C];
    int state;
} Work_021C79B8;

typedef struct {
    unsigned char pad0[0x14];
    void *f14;
} Work_021C79D0;

typedef struct {
    void *f0;
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x20 - 0x18];
    void *f20;
    void *f24;
    void *f28;
    void *f2C[7];
    void *f48;
    void *f4C;
    void *f50;
    void *f54;
    void *f58;
    void *f5C[8];
    void *f7C[24];
    void *fDC;
    void *fE0;
    void *fE4;
    void *fE8;
    void *fEC;
    void *fF0;
    void *fF4;
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    Parent *f108;
    int state;
    int f110;
    u16 f114;
    u16 f116;
    int f118;
    int f11C;
    u8 pad120[0x140 - 0x120];
    int f140;
    int f144;
    u8 pad148[0x14C - 0x148];
    void *f14C[3];
    Res *f158[3];
    void *f164[3];
    u8 pad170[0x17C - 0x170];
    u8 f17C[8];
    void *f184;
    int f188[8];
    u8 f1A8[8];
    u8 f1B0[8];
} Work_021C79F4;

typedef struct {
    u8 pad0[4];
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x7C - 0x18];
    void *f7C[4][3];
    u8 padAC[0xF8 - 0xAC];
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    u8 pad108[4];
    int state;
} Work_021C7A44;

typedef struct {
    void *f0;
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x20 - 0x18];
    void *f20;
    void *f24;
    void *f28;
    void *f2C[7];
    void *f48;
    void *f4C;
    void *f50;
    void *f54;
    void *f58;
    void *f5C[8];
    void *f7C[24];
    void *fDC;
    void *fE0;
    void *fE4;
    void *fE8;
    void *fEC;
    void *fF0;
    void *fF4;
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    Parent *f108;
    int state;
    int f110;
    u16 f114;
    u16 f116;
    int f118;
    int f11C;
    u8 pad120[0x140 - 0x120];
    int f140;
    int f144;
    u8 pad148[0x14C - 0x148];
    void *f14C[3];
    Res *f158[3];
    void *f164[3];
    u8 pad170[0x17C - 0x170];
    u8 f17C[8];
    void *f184;
    int f188[8];
    u8 f1A8[8];
    u8 f1B0[8];
} Work_021C7A70;

typedef struct {
    void *f0;
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x20 - 0x18];
    void *f20;
    void *f24;
    void *f28;
    void *f2C[7];
    void *f48;
    void *f4C;
    void *f50;
    void *f54;
    void *f58;
    void *f5C[8];
    void *f7C[24];
    void *fDC;
    void *fE0;
    void *fE4;
    void *fE8;
    void *fEC;
    void *fF0;
    void *fF4;
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    Parent *f108;
    int state;
    int f110;
    u16 f114;
    u16 f116;
    int f118;
    int f11C;
    u8 pad120[0x140 - 0x120];
    int f140;
    int f144;
    u8 pad148[0x14C - 0x148];
    void *f14C[3];
    Res *f158[3];
    void *f164[3];
    u8 pad170[0x17C - 0x170];
    u8 f17C[8];
    void *f184;
    int f188[8];
    u8 f1A8[8];
    u8 f1B0[8];
} Work_021C7AD4;

extern struct Obj *func_0204B294(void *res, unsigned int a, unsigned int b, unsigned int c, const void *pos, u16 f, u16 heap);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0204AFD8(u32 i);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_02046440(u32 texMode, u32 texSize, u32 plttMode, u32 plttSize, u16 fifoSize, s16 heap, void (*setup)(void));
extern struct LightSlot *func_02048BC4(const struct LightSet *s, u32 heap);
extern void func_02048C58(struct LightSlot *slots);
extern void func_02046858(const u32 *src);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02048C4C(void *p);
extern void func_02046788(void);
extern void *func_02047CFC(int a, int b, int heap);
extern u16 func_02047E88(void *p, const void *q);
extern u32 func_02048A18(u8 *a0, int i);
extern int func_0204779C(int *p);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
extern void *func_02048A24(int a, int s, int c, int d, int e, int f, int g, int h, VecFx32 *pos, VecFx32 *up, VecFx32 *tgt, int heap);
extern u32 func_02048AC4(void *ptr);
extern void func_020480E4(struct Ctx *c, u32 i);
extern void func_02047E54(struct Rec *p);
extern void func_0207ADC4(MtxFx33 *m);
extern void func_02048AD0(struct Light *l);
extern u32 func_02047828(struct AnmCtl *c, u32 idx, s32 *frame);
extern u32 func_0204784C(struct AnmCtl *c, u16 idx, s32 *frame);
extern void func_02047964(void);
extern void func_020479D8(void);
extern void func_02047A60(void *a0, struct Arg *a1);
extern void func_02047970(void);
extern void func_02045088(u16 heapId);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_020450C8(void);
extern void func_0201F73C(void *p, int a, int b, int c);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(unsigned int index);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201C440(void *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0201D83C(void *ptr);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern u32 func_020221A4(void);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_021C7E48(Work_021C79D0 *p);
extern void func_021C8364(Work_021C79D0 *p);
extern u32 func_0204B98C(struct Actor *a);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
void func_021C75E4(Work_021C75E4 *p);
void func_021C7658(Work_021C7658 *p);
void func_021C76A4(Work_021C76A4 *p);
void func_021C7730(Work_021C7730 *p);
void func_021C7744(Work_021C7744 *p);
void func_021C7808(Work_021C7808 *p);
void func_021C7830(Work_021C7830 *p);
void func_021C78C4(Work_021C78C4 *p);
void func_021C78F8(Work_021C78F8 *p);
void func_021C7908(Work_021C7908 *p);
void func_021C7934(Work_021C7934 *p);
void func_021C795C(Work_021C795C *p);
void func_021C7970(Work_021C7970 *p);
int func_021C79A0(Work_021C79A0 *p);
int func_021C79B8(Work_021C79B8 *p);
int func_021C79D0(Work_021C79D0 *p);
int func_021C79F4(Work_021C79F4 *p);
int func_021C7A44(Work_021C7A44 *p);
int func_021C7A70(Work_021C7A70 *p);
void func_021C7AD4(Work_021C7AD4 *p, int x, int k, int col);
extern const ObjTemplate d_021C8AA0[36];
extern const void *const d_021C8810;
extern const Camera d_021C896C;
extern const s16 FX_SinCosTable_[];
extern const unsigned char d_021C8834[];
extern const VecFx32 d_021C8950;
extern const VecFx32 d_021C8938;
extern const VecFx32 d_021C8944;
extern Counter d_021C8E80;
extern const int d_021C8894[];


/*
 * Addresses are Black-image addresses.
 */
void func_021C75E4(Work_021C75E4 *p)
{
    ObjPos pos;
    int i;

    for (i = 0; i < 36; i++) {
        pos.x = d_021C8AA0[i].x;
        pos.y = d_021C8AA0[i].y;
        pos.z = d_021C8AA0[i].z;
        pos.f7 = 0;
        pos.pri = 0x24 - i;
        p->obj[i] = func_0204B294(p->res, (unsigned int)p->set[d_021C8AA0[i].cell], (unsigned int)p->set[d_021C8AA0[i].chr], (unsigned int)p->set[d_021C8AA0[i].anm], &pos, 0, 0x27);
        func_0204B92C(p->obj[i], 1);
    }
}


void func_021C7658(Work_021C7658 *p)
{
    func_0204A8D4((u32)p->fEC);
    func_0204ADA4((u32)p->fE8);
    func_0204AFD8((u32)p->fF0);
    func_0204A8D4((u32)p->fE0);
    func_0204ADA4((u32)p->fDC);
    func_0204AFD8((u32)p->fE4);
    func_0204B1CC(p->f48);
    func_0204A5AC();
}


void func_021C76A4(Work_021C76A4 *p)
{
    Camera cam;
    void *light;

    func_02046440(0, 1, 0, 1, 0x1000, 0x27, 0);
    light = func_02048BC4((const struct LightSet *)(&d_021C8810), 0x27);
    p->f100 = light;
    func_02048C58(light);
    cam = d_021C896C;
    cam.f4 = FX_SinCosTable_[0x16C];
    cam.f8 = FX_SinCosTable_[0x16D];
    func_02046858((const u32 *)(&cam));
    func_02040588(0, 1);
    *(volatile u16 *)0x04000060 = (u16)((*(volatile u16 *)0x04000060 & ~(0x2000 | 0x1000)) | 0x8);
}


void func_021C7730(Work_021C7730 *p)
{
    func_02048C4C(p->f100);
    func_02046788();
}


void func_021C7744(Work_021C7744 *p)
{
    void *mdl;
    int i;
    int n;
    VecFx32 a;
    VecFx32 b;
    VecFx32 c;

    p->fF8 = func_02047CFC(10, 10, 0x27);
    p->fFC = func_02047E88(p->fF8, d_021C8834);
    mdl = (void *)func_02048A18(p->fF8, p->fFC);
    n = func_0204779C(mdl);
    for (i = 0; i < n; i++) {
        func_020477A4(mdl, (u16)i);
    }
    a = d_021C8950;
    b = d_021C8938;
    c = d_021C8944;
    p->f104 = func_02048A24(0, FX_SinCosTable_[0x1C6], FX_SinCosTable_[0x1C7], 0x1555, 0, 0x1000, 0x400000, 0, &a, &c, &b, 0x27);
}


void func_021C7808(Work_021C7808 *p)
{
    func_02048AC4(p->f104);
    func_020480E4(p->fF8, p->fFC);
    func_02047E54(p->fF8);
}


/*
 * closed:   blocking arm9 callees labelled and matched by seeds_3 (2026-09-28)
 *
 * Addresses are Black-image addresses.
 */
void func_021C7830(Work_021C7830 *p)
{
    void *mdl;
    int out;
    Transform t;
    int n;
    int i;

    i = 0;
    t.scale.x = 0x1000;
    t.scale.y = 0x1000;
    t.scale.z = 0x1000;
    t.trans.x = 0;
    t.trans.y = 0;
    t.trans.z = 0;
    func_0207ADC4(&t.rot);
    func_02048AD0(p->f104);
    mdl = (void *)func_02048A18(p->fF8, p->fFC);
    n = func_0204779C(mdl);
    func_02047828(mdl, 0, &out);
    for (; i < n; i++) {
        func_0204784C(mdl, (u16)i, &p->f13C);
    }
    func_02047964();
    func_020479D8();
    func_02047A60((void *)func_02048A18(p->fF8, p->fFC), (struct Arg *)(&t));
    func_02047970();
    d_021C8E80.f0 += d_021C8E80.f4;
}


void func_021C78C4(Work_021C78C4 *p)
{
    func_02045088(0x27);
    p->f8 = (void *)func_020450F0(4, 2, 10, 0x1C, 0xC, 0xF, 1);
    func_02043B5C(func_02045770(p->f8), 0xF);
}


void func_021C78F8(Work_021C78F8 *p)
{
    func_020452E8(p->f8);
    func_020450C8();
}


void func_021C7908(Work_021C7908 *p)
{
    void *v;

    func_0201F73C(p->f8, 0, 1, 0xE);
    v = p->f8;
    func_02045334(v);
    func_02045374(v);
    func_020409B4(func_02045730(v));
}


void func_021C7934(Work_021C7934 *p)
{
    p->f4 = func_0201D7EC(0x17, 0, 0, 0, 0x27);
    p->f14 = (void *)func_0201C440((void *)0x27);
    p->fC = p->f8;
    p->f10 = 0;
}


void func_021C795C(Work_021C795C *p)
{
    func_0201C4C0(p->f14);
    func_0201D83C(p->f4);
}


void func_021C7970(Work_021C7970 *p)
{
    void *w;

    func_0201C4E4(p->f14);
    w = p->f14;
    if (p->f10) {
        if (func_0201C6C4(w, func_02045770(p->fC)) == 0) {
            func_02045334(p->fC);
            p->f10 = 0;
        }
    }
}


extern int (*const d_021C8E58[])(Work_021C79A0 *p);


int func_021C79A0(Work_021C79A0 *p)
{
    return d_021C8E58[p->state](p);
}


int func_021C79B8(Work_021C79B8 *p)
{
    if (func_020221A4()) {
        p->state = 1;
    }
    return 1;
}


int func_021C79D0(Work_021C79D0 *p)
{
    if (func_0201C6B4(p->f14) == 0) {
        return 1;
    }
    func_021C7E48(p);
    func_021C8364(p);
    return 1;
}


int func_021C79F4(Work_021C79F4 *p)
{
    switch (p->f110) {
    case 0x12:
        if (func_0204B98C(p->f54) == 0) {
            p->state = 3;
        }
    case 0x13:
        if (func_0204B98C(p->f50) == 0) {
            p->state = 3;
        }
    case 0x10:
        if (func_0204B98C(p->f4C) == 0) {
            p->state = 3;
        }
    }
    return 1;
}


int func_021C7A44(Work_021C7A44 *p)
{
    func_0202208C(0, 0, 0, 0, 6, 1, 0x27);
    p->state = 4;
    return 1;
}


int func_021C7A70(Work_021C7A70 *p)
{
    if (func_020221A4()) {
        if (p->f110 == 0x12) {
            p->f108->fC = 0;
            p->f108->f10 = 1;
            p->state = 0;
        } else if (p->f110 == 0x13) {
            p->f108->fC = 0;
            p->f108->f10 = 0;
            p->state = 0;
        } else if (p->f110 == 0x10) {
            p->f108->fC = 3;
            p->state = 0;
        }
        return 0;
    }
    return 1;
}


void func_021C7AD4(Work_021C7AD4 *p, int x, int k, int col)
{
    void *v;

    func_02045CAC(p->f20, x + d_021C8894[k], (void *)col);
    v = p->f14;
    func_0201C724(v, (u32)func_02045770(p->fC), (int)0, (s16)(x << 5), (int)col, (u32)p->f4, (int)0x44F);
    p->f10 = 1;
}
