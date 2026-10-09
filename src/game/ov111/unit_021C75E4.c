/*
 * file:     unit_021C75E4.c
 * unit:     yes
 * function: func_021C75E4, func_021C7658, func_021C76A4, func_021C7730, func_021C7744, func_021C7808, func_021C7830, func_021C78C4, func_021C78F8, func_021C7908, func_021C7934, func_021C795C, func_021C7970, func_021C79A0, func_021C79B8, func_021C79D0, func_021C79F4, func_021C7A44, func_021C7A70, func_021C7AD4, func_021C7B20, func_021C7C78, func_021C7C94, func_021C7CD0, func_021C7E48, func_021C7EF8, func_021C7F2C, func_021C8078, func_021C80B4, func_021C80E8, func_021C810C, func_021C81A4, func_021C81C0, func_021C8208, func_021C829C, func_021C82C0, func_021C832C, func_021C8364, func_021C83DC, func_021C840C, func_021C8414
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
 *   func_0204B98C  0x0204B98C  arm
 *   func_0202208C  0x0202208C  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201C724  0x0201C724  thumb
 *   d_021C8894  0x021C8894  data
 *   func_020457B0  0x020457B0  arm
 *   sub_02008A54  0x02008A54  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02045808  0x02045808  arm
 *   d_021C88B4  0x021C88B4  data
 *   func_02035C08  0x02035C08  arm
 *   func_02035BA4  0x02035BA4  arm
 *   func_02035CB8  0x02035CB8  arm
 *   func_020362DC  0x020362DC  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_021C842C  0x021C842C  thumb
 *   d_021C898C  0x021C898C  data
 *   d_021C8808  0x021C8808  data
 *   func_0204B878  0x0204B878  arm
 *   func_020355D8  0x020355D8  arm
 *   func_02012BF8  0x02012BF8  thumb
 *   func_02012BE0  0x02012BE0  thumb
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_02012F08  0x02012F08  thumb
 *   func_0200C234  0x0200C234  thumb
 *   func_0203F49C  0x0203F49C  arm
 *   sub_02008A34  0x02008A34  thumb
 *   sub_02008ADC  0x02008ADC  thumb
 *   sub_02008A44  0x02008A44  thumb
 *   sub_02008ACC  0x02008ACC  thumb
 *   RTC_ConvertDateTimeToSecond  0x02089004  arm
 *   RTC_ConvertSecondToDateTime  0x020891E0  arm
 *   _ll_sdiv  0x0209BE5C  arm
 *   func_0207E51C  0x0207E51C  arm
 *   func_02048A0C  0x02048A0C  arm
 *   func_02047250  0x02047250  arm
 *   func_02061CA4  0x02061CA4  arm
 *   d_021C8874  0x021C8874  data
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
struct U16Vec;
struct WordSet;
struct Blk34;
struct RtcDate;
struct RtcTime;
struct Sub020089A8Obj;
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
    int f148;
    void *f14C[3];
    Res *f158[3];
    void *f164[3];
    Res *f170[3];
    u8 f17C[8];
    void *f184;
    int f188[8];
    u8 f1A8[8];
    u8 f1B0[8];
} Work;

typedef struct {
    u8 a;
    u8 b;
    u8 c;
    u8 d;
} Rec;

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
} Work_021C7E48;

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
} Work_021C8364;

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
} Work_021C7C94;

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
    u8 pad120[2];
    u16 f122;
    u8 pad124[4];
    int f128;
    int f12C;
    int f130;
    u8 pad134[4];
    int f138;
    int f13C;
    int f140;
    int f144;
    int f148;
    void *f14C[3];
    Res *f158[3];
    void *f164[3];
    Res *f170[3];
    u8 f17C[8];
    void *f184;
    int f188[8];
    u8 f1A8[8];
    u8 f1B0[8];
} Work_021C7CD0;

typedef struct {
    u8 pad0[4];
    void *f4;
    u8 pad8[4];
    int fC;
    int f10;
} Parent_021C7EF8;

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
    Parent_021C7EF8 *f108;
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
    int f148;
    void *f14C[3];
    Res *f158[3];
    void *f164[3];
    Res *f170[3];
    u8 f17C[8];
    void *f184;
    int f188[8];
    u8 f1A8[8];
    u8 f1B0[8];
} Work_021C7EF8;

typedef struct {
    u8 pad0[4];
    void *f4;
} Parent_021C8078;

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
    u8 pad48[0x58 - 0x48];
    void *f58;
    void *f5C[8];
    void *f7C[24];
    u8 padDC[0xF4 - 0xDC];
    void *fF4;
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    Parent_021C8078 *f108;
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
} Work_021C8078;

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
} Work_021C80B4;

typedef struct {
    u8 pad0[4];
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x7C - 0x18];
    void *f7C[12];
    u8 padAC[0xF8 - 0xAC];
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    u8 pad108[4];
    int state;
} Work_021C80E8;

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
    Parent_021C7EF8 *f108;
    int state;
    int f110;
    u16 f114;
    u16 f116;
    int f118;
    int f11C;
    u8 pad120[2];
    u16 f122;
    u8 pad124[4];
    int f128;
    int f12C;
    int f130;
    u8 pad134[4];
    int f138;
    int f13C;
    int f140;
    int f144;
    int f148;
    void *f14C[3];
    Res *f158[3];
    void *f164[3];
    Res *f170[3];
    u8 f17C[8];
    void *f184;
    int f188[8];
    u8 f1A8[8];
    u8 f1B0[8];
} Work_021C810C;

typedef struct {
    u8 pad0[0xC];
    void *fC;
} Res_021C81C0;

typedef struct {
    u8 pad0[4];
    void *f4;
} Parent_021C81C0;

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
    u8 pad48[0x58 - 0x48];
    void *f58;
    void *f5C[8];
    void *f7C[24];
    u8 padDC[0xF4 - 0xDC];
    void *fF4;
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    Parent_021C81C0 *f108;
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
    Res_021C81C0 *f158[3];
    void *f164[3];
    u8 pad170[0x17C - 0x170];
    u8 f17C[8];
    void *f184;
    int f188[8];
    u8 f1A8[8];
    u8 f1B0[8];
} Work_021C81C0;

typedef struct { u32 year, month, day, week; } RTCDate;

typedef struct { u32 hour, minute, second; } RTCTime;

typedef struct {
    u8 pad0[0xC];
    void *fC;
} Res_021C8208;

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
    u8 pad48[0x58 - 0x48];
    void *f58;
    void *f5C[8];
    void *f7C[24];
    u8 padDC[0xF4 - 0xDC];
    void *fF4;
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    Parent_021C81C0 *f108;
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
    Res_021C8208 *f158[3];
    void *f164[3];
    u8 pad170[0x17C - 0x170];
    u8 f17C[8];
    void *f184;
    int f188[8];
    u8 f1A8[8];
    u8 f1B0[8];
} Work_021C8208;

typedef struct {
    unsigned char pad0[0xC];
    unsigned char *fC;
} Res_021C829C;

typedef struct {
    unsigned char pad0[0x158];
    Res_021C829C *res[3];
} Work_021C829C;

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
} Work_021C82C0;

typedef struct {
    u8 rev;
    u8 numEntry;
    u16 sizeDictBlk;
    u16 dummy;
    u16 ofsEntry;
} Dict;

typedef struct {
    u16 sizeUnit;
    u16 ofsName;
    u8 data[4];
} DictEntryHdr;

typedef struct {
    u8 pad0[0x2C];
    u8 *plttData;
    u8 pad30[4];
    u16 ofsDict;
} Tex;

typedef signed int     s32_021C7EF8;

typedef signed char s8;

typedef int s32_021C83DC;

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
extern u32 func_0204B98C(struct Actor *a);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern Rec sub_02008A54(void *obj, int i);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *vec);
extern int func_02035C08(const void *rects);
extern int func_02035BA4(const void *rects);
extern u32 func_02035CB8(u32 *outA, u32 *outB);
extern u32 func_020362DC(void);
extern void func_020061E4(u32 a);
extern void func_021C842C(Work_021C7E48 *p, int idx);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_020355D8(u8 v);
extern int func_02012BF8(int a0, int a1);
extern void func_02012BE0(void *p, u32 a, u32 b);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void *func_02012F08(int *p);
extern u32 func_0200C234(struct Blk34 *p, u32 bit);
extern void func_0203F49C(struct RtcDate *date, struct RtcTime *time);
extern s64 RTC_ConvertDateTimeToSecond(const RTCDate *date, const RTCTime *time);
extern void sub_02008A34(struct Sub020089A8Obj *obj, u32 lo, u32 hi);
extern void sub_02008ADC(struct Sub020089A8Obj *obj, int i, int value);
extern void RTC_ConvertSecondToDateTime(RTCDate *date, RTCTime *time, s64 sec);
extern unsigned long long sub_02008A44(const struct Sub020089A8Obj *obj);
extern u16 sub_02008ACC(const struct Sub020089A8Obj *obj, u32 i);
extern void func_0207E51C(const void *src, int ofs, int size);
extern u32 func_02048A0C(u8 *a0, int i);
extern Tex *func_02047250(void *p);
extern s32_021C7EF8 func_02061CA4(void *p, u32 a, u32 b, s32_021C7EF8 size);
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
void func_021C7B20(Work *p, int mode, int idx);
int func_021C7C78(int a, int b);
void func_021C7C94(Work_021C7C94 *p);
void func_021C7CD0(Work_021C7CD0 *p, int unused, int touch, int x);
int func_021C7E48(Work_021C7E48 *p);
int func_021C7EF8(int v);
void func_021C7F2C(Work_021C7EF8 *p, int sel, int flag);
void func_021C8078(Work_021C8078 *p);
void func_021C80B4(Work_021C80B4 *p);
void func_021C80E8(Work_021C80E8 *p, int row, int v);
void func_021C810C(Work_021C810C *p, int a, int b);
void func_021C81A4(Work_021C7EF8 *p, u16 v);
void func_021C81C0(Work_021C81C0 *p);
void func_021C8208(Work_021C8208 *p);
void func_021C829C(Work_021C829C *p, int idx, int k);
void func_021C82C0(Work_021C82C0 *p, int idx, int k);
void func_021C832C(Work_021C7EF8 *p, int row, int n);
void func_021C8364(Work_021C8364 *p);
void func_021C83DC(u8 *p, int value);
void func_021C840C(u8 *p);
void func_021C8414(u8 *p, int idx);
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
extern const int d_021C88B4[8];
extern const unsigned char d_021C898C[];
extern const unsigned char d_021C8808[];
extern const int d_021C8874[];




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
    func_021C7E48((Work_021C7E48 *)p);
    func_021C8364((Work_021C8364 *)p);
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




/*
 * callee:   0x02008A54 (arm9, labelled by seeds_3) is still a near miss; its one call site
 *           here attests through the sole-ref class (docs/notes/pkt_02008A54.c.txt)
 *
 * Addresses are Black-image addresses.
 */
void func_021C7B20(Work *p, int mode, int idx)
{
    void *str;
    Rec r;
    void *v;
    int i;

    str = func_020457B0(0x68, 0x27);
    func_02043B5C(func_02045770(p->f8), 0xF);
    switch (mode) {
    case 0:
        r = sub_02008A54(p->f184, idx);
        func_0201EFA4(p->f24, 0, r.a + 0x7D0, 4, 0, 1);
        func_0201EFA4(p->f24, 1, r.b, 2, 0, 1);
        func_0201EFA4(p->f24, 2, r.c, 2, 0, 1);
        func_02045CAC(p->f20, idx * 3 + 0x58, str);
        func_0201F250(p->f24, p->f28, str);
        v = p->f14;
        func_0201C724(v, (u32)func_02045770(p->fC), (int)0, (s16)0, (u32)p->f28, (u32)p->f4, (int)0x44F);
        p->f10 = 1;
        for (i = 1; i < 3; i++) {
            func_02045CAC(p->f20, i + (idx * 3 + 0x58), str);
            v = p->f14;
            func_0201C724(v, (u32)func_02045770(p->fC), (int)0, (s16)(i << 5), (u32)str, (u32)p->f4, (int)0x44F);
            p->f10 = 1;
        }
        break;
    case 1:
        for (i = 0; i < 2; i++) {
            func_021C7AD4((Work_021C7AD4 *)p, i, idx, (int)str);
        }
        if (p->f17C[idx]) {
            func_021C7AD4((Work_021C7AD4 *)p, 2, idx, (int)str);
        }
        break;
    }
    func_02045808(str);
}



int func_021C7C78(int a, int b)
{
    if (a >= b) {
        return a % b;
    }
    if (a < 0) {
        a += 0x100000;
    }
    return a;
}



void func_021C7C94(Work_021C7C94 *p)
{
    int v = p->f140;

    if (v > 0x1000) {
        p->f140 = v - 0x190;
    } else if (v < -0x1000) {
        p->f140 = v + 0x190;
    } else if (v == 0) {
        p->f140 = 0x1000;
    }
}





void func_021C7CD0(Work_021C7CD0 *p, int unused, int touch, int x)
{
    int i;
    int v;
    int d;

    if (p->f122 == 0 && touch != 0) {
        p->f138 = p->f13C;
        p->f130 = x;
    } else if (p->f122 == 1 && touch == 1) {
        p->f13C = p->f138 + ((x - p->f130) << 10);
        p->f13C = func_021C7C78(p->f13C, 0x100000);
    } else if (p->f122 == 1 && touch == 0) {
        if (p->f12C != 0) {
            p->f140 = (p->f128 - p->f12C) << 11;
        }
        if (p->f140 > 40000) {
            p->f140 = 40000;
        } else if (p->f140 < -40000) {
            p->f140 = -40000;
        }
    }
    if (p->f122 == 0 && touch == 0) {
        p->f13C = p->f13C + p->f140;
        p->f13C = func_021C7C78(p->f13C, 0x100000);
        if (p->f144 >= 0) {
            if (p->f148 > p->f13C - 50000 && p->f148 < p->f13C + 50000) {
                p->f140 = 0;
                p->f13C = p->f148;
                p->f144 = -1;
            }
        } else {
            func_021C7C94((Work_021C7C94 *)p);
            for (i = 0; i < 8; i++) {
                v = d_021C88B4[i];
                if (v > p->f13C - 10000 && v < p->f13C + 10000) {
                    d = p->f140;
                    if (d < 0) {
                        d = -d;
                    }
                    if (d < 10000) {
                        p->f13C = v;
                        p->f140 = 0;
                    }
                }
            }
        }
    }
    p->f12C = p->f128;
    p->f128 = x;
    p->f122 = touch;
}





int func_021C7E48(Work_021C7E48 *p)
{
    int x = 0;
    int y = 0;
    int flag = 0;
    int ret;
    int b;
    int a;
    int c;

    ret = func_02035C08(d_021C898C);
    a = func_02035BA4(d_021C898C);
    b = func_02035C08(d_021C8808);
    c = func_02035BA4(d_021C8808);
    func_02035CB8((u32 *)(&x), (u32 *)(&y));
    if (func_020362DC() & 2) {
        func_020061E4(0x551);
        flag = 1;
        ret = 0x13;
    } else if (func_020362DC() & 0x400) {
        func_020061E4(0x551);
        ret = 0x12;
    } else if (func_020362DC() & 0x800) {
        ret = 0x11;
    } else if (func_020362DC() & 1) {
        ret = 0x10;
    }
    func_021C7F2C((Work_021C7EF8 *)p, ret, flag);
    func_021C7CD0((Work_021C7CD0 *)p, b, c + 1, x);
    func_021C842C((Work_021C7E48 *)p, a);
    return ret;
}













int func_021C7EF8(int v)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (d_021C88B4[i] > v - 10000 && d_021C88B4[i] < v + 10000) {
            break;
        }
    }
    if (i == 8) {
        i = 0;
    }
    return i;
}













void func_021C7F2C(Work_021C7EF8 *p, int sel, int flag)
{
    int idx;

    if (sel == -1) {
        return;
    }
    switch (sel) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        if (p->f17C[sel] == 0) {
            return;
        }
        func_020061E4(0x65F);
        func_021C7B20((Work *)p, 0, sel);
        func_021C7908((Work_021C7908 *)p);
        p->f144 = 0;
        p->f148 = d_021C88B4[sel];
        p->f140 = 40000;
        return;
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        if (p->f140 != 0) {
            return;
        }
        idx = func_021C7EF8(p->f13C);
        func_020061E4(0x65E);
        func_021C7B20((Work *)p, 1, (sel - 8 + idx) % 8);
        func_021C7908((Work_021C7908 *)p);
        return;
    case 16:
        p->state = 2;
        p->f110 = sel;
        func_020061E4(0x54C);
        func_0204B878(p->f4C, 0xC);
        return;
    case 17:
        func_021C8078((Work_021C8078 *)p);
        return;
    case 18:
        func_020061E4(0x556);
        p->state = 2;
        p->f110 = sel;
        func_0204B878(p->f54, 8);
        return;
    case 19:
        func_020061E4(0x551);
        p->state = 2;
        p->f110 = sel;
        func_0204B878(p->f50, 9);
        if (flag) {
            func_020355D8(0);
        } else {
            func_020355D8(1);
        }
        return;
    }
}













void func_021C8078(Work_021C8078 *p)
{
    int v = func_02012BF8((int)p->f108->f4, 0x17) ^ 1;

    func_0204B878(p->f58, v + 6);
    func_02012BE0(p->f108->f4, 0x17, v);
    func_020061E4(0x646);
}













void func_021C80B4(Work_021C80B4 *p)
{
    p->f114 = 0;
    p->f116 = p->f118 / 10;
    if (p->f118 % 10) {
        p->f116++;
    }
}













void func_021C80E8(Work_021C80E8 *p, int row, int v)
{
    int i;

    for (i = 0; i < 3; i++) {
        func_0204B3DC(p->f7C[row * 3 + i], v);
    }
}











void func_021C810C(Work_021C810C *p, int a, int b)
{
    void *obj;
    int i;

    obj = func_02012F08(p->f108->f4);
    for (i = 0; i < 8; i++) {
        if (func_0200C234(obj, i)) {
            func_0204B3DC(p->f5C[i], 1);
            func_021C80E8((Work_021C80E8 *)p, i, 1);
            p->f17C[i] = 1;
        } else {
            func_0204B3DC(p->f5C[i], 0);
            func_021C80E8((Work_021C80E8 *)p, i, 0);
            p->f17C[i] = 0;
        }
    }
    func_0204B878(p->f58, func_02012BF8((int)p->f108->f4, 0x17) + 6);
}










void func_021C81A4(Work_021C7EF8 *p, u16 v)
{
    p->f114 = v;
    func_021C810C((Work_021C810C *)p, v, p->f116);
    func_021C8364((Work_021C8364 *)p);
}










void func_021C81C0(Work_021C81C0 *p)
{
    RTCDate date;
    RTCTime time;
    s64 sec;
    int i;

    func_0203F49C((struct RtcDate *)(&date), (struct RtcTime *)(&time));
    sec = RTC_ConvertDateTimeToSecond(&date, &time);
    sub_02008A34(p->f184, (u32)sec, (u32)(sec >> 32));
    for (i = 0; i < 8; i++) {
        sub_02008ADC(p->f184, i, p->f188[i]);
    }
}










void func_021C8208(Work_021C8208 *p)
{
    RTCDate date;
    RTCDate date2;
    RTCTime time;
    RTCTime time2;
    s64 saved;
    s64 hours;
    int i;

    saved = sub_02008A44(p->f184);
    RTC_ConvertSecondToDateTime(&date2, &time2, saved);
    func_0203F49C((struct RtcDate *)(&date), (struct RtcTime *)(&time));
    hours = (RTC_ConvertDateTimeToSecond(&date, &time) - saved) / 3600;
    if (hours < 0) {
        hours = 0;
    }
    for (i = 0; i < 8; i++) {
        p->f188[i] = sub_02008ACC(p->f184, i);
        p->f188[i] -= hours * 2;
        if (p->f188[i] < 0) {
            p->f188[i] = 0;
        }
    }
    for (i = 0; i < 8; i++) {
        p->f1B0[i] = 0xFF;
    }
}










void func_021C829C(Work_021C829C *p, int idx, int k)
{
    if (k > 2) {
        k = 2;
    }
    func_0207E51C((unsigned short *)p->res[k]->fC + idx * 16, idx * 32, 32);
}








static inline void *DictGetByIdx(const Dict *d, u32 idx)
{
    if (d && idx < d->numEntry) {
        const DictEntryHdr *h = (const DictEntryHdr *)((const u8 *)d + d->ofsEntry);
        return (void *)((const u8 *)h->data + h->sizeUnit * idx);
    }
    return 0;
}








static inline const u16 *TexGetPltt(const Tex *t, u32 idx)
{
    if (t && t->ofsDict) {
        return DictGetByIdx((const Dict *)((const u8 *)t + t->ofsDict), idx);
    }
    return 0;
}








void func_021C82C0(Work_021C82C0 *p, int idx, int k)
{
    u8 *dst;
    Tex *tex;
    const u16 *e;

    if (k > 2) {
        k = 2;
    }
    dst = p->f170[k]->fC;
    tex = func_02047250((void *)func_02048A0C(p->fF8, 0));
    e = TexGetPltt(tex, idx);
    func_02061CA4((void *)1, (u32)(tex->plttData + *e * 8), (u32)(dst + d_021C8874[idx] * 32), 0x20);
}







void func_021C832C(Work_021C7EF8 *p, int row, int n)
{
    int i;
    int lim = n - 3;

    for (i = 0; i < 3; i++) {
        if (n < 3) {
            func_0204B3DC(p->f7C[row * 3 + i], 0);
        } else if (i <= lim) {
            func_0204B3DC(p->f7C[row * 3 + i], 1);
        } else {
            func_0204B3DC(p->f7C[row * 3 + i], 0);
        }
    }
}






void func_021C8364(Work_021C8364 *p)
{
    int i;

    for (i = 0; i < 8; i++) {
        p->f1A8[i] = p->f188[i] / 0x60;
        if (p->f1A8[i] > 5) {
            p->f1A8[i] = 5;
        }
        if (p->f1A8[i] != p->f1B0[i]) {
            func_021C829C((Work_021C829C *)p, i, p->f1A8[i]);
            func_021C82C0((Work_021C82C0 *)p, i, p->f1A8[i]);
            func_021C832C((Work_021C7EF8 *)p, i, p->f1A8[i]);
        }
        p->f1B0[i] = p->f1A8[i];
    }
}






void func_021C83DC(u8 *p, int value)
{
    if (p[5] == 0) {
        func_020061E4(value > 0x210 ? 0x661 : 0x660);
        p[5] = 5;
    } else {
        p[5]--;
    }
}






void func_021C840C(u8 *p) { p[2] = 0; p[3] = 0; }






void func_021C8414(u8 *p, int idx)
{
    s32_021C83DC *count = (s32_021C83DC *)(p + 0x188);

    if (count[idx] < 0x23F) {
        count[idx]++;
    }
}
