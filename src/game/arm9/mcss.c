/*
 * file:     mcss.c
 * unit:     yes
 * function: func_02014910, func_0201493C, func_02014A10, func_02014A20, func_02014A80, func_02014B08, func_02014BA8, func_02014C08, func_02014CB8, func_02014CD4, func_02014CEC, func_02014CF0, func_02014CF8, func_02014D2C, func_02014D90, func_02015590, func_020155A0, func_020159C8, func_02015BA4, func_02015BF0, func_02015C00, func_02015C0C, func_02015C1C, func_02015C30, func_02015C48, func_02015C60, func_02015C78, func_02015C94, func_02015CAC, func_02015CC4, func_02015CDC, func_02015CF8, func_02015D14, func_02015D30, func_02015D4C, func_02015D64, func_02015D80, func_02015D88, func_02015D94, func_02015DB0, func_02015DC0, func_02015DD4, func_02015DF8, func_02015E04, func_02015E28, func_02015E4C, func_02015E70, func_02015E94, func_02015EA0, func_02015EB0, func_02015EC4, func_02015EE8, func_02015EEC, func_02015EF4, func_02015EFC, func_02015F04, func_02015F0C, func_02015F14, func_02015F1C, func_02015F24, func_02015F2C, func_02015F40, func_02015F50, func_02015FAC, func_02015FBC, func_02015FD4, func_02015FF0, func_0201600C, func_02016020, func_02016024, func_02016028, func_02016068, sub_02016078, func_020160C0, func_020160C4, func_020160CC, func_020160D4, func_0201624C, func_02016374, func_02016380, func_02016394, func_020163B0, func_020163B4, func_020163C4, func_02016630, func_02016880, func_0201691C, func_02016984, func_020169D4, func_020169E8, func_02016BA0, func_02016C0C, func_02016C38, func_02016C60, func_02016FC8, func_02017100, func_02017114, func_02017168, func_02017214, func_02017270, func_020172AC, func_020172BC, func_020172D8, func_020173B4, sub_020173C8, func_020173D0, func_020173E8, func_020173EC, func_020173F0, func_02017430, func_0201747C, func_02017528, func_02017550, func_0201756C, func_02017588, func_02017600, func_0201761C, func_020178D8, func_02017900, func_02017988, func_020179B8, func_02017A20, func_02017B24, func_02017B4C, func_02017BC8, func_02017C50, func_02017CC8, func_02017D30, func_02017D70, func_02017DBC, func_02017DE4, func_02017E1C, func_02017E40, func_02017E64, func_02017E88, func_02017EAC, func_02017EB4, func_02017ED8, func_02017F00, func_02017F08, func_02017F50, func_02017F90, func_02017F9C, func_02017FB0, func_0201808C, func_02018094, func_020180F4, func_020180FC, func_02018198, func_020181A0, func_020181F4, func_020181FC, func_02018238, func_02018240, func_020182A0, func_020182A8, func_02018328, func_02018430, func_02018438, func_02018480, func_02018488, func_0201850C, func_02018544, func_0201854C, func_02018584, func_02018598, func_020185A0, func_020185B0, func_020185C4, func_020185F0, func_020185F4, func_020185F8, func_0201862C, func_020186C8, func_02018790, func_02018820, func_020188AC, func_020188B4, func_020188E0, func_0201891C, func_02018948, func_020189D0, func_020189D8, func_020189F0, func_02018A00, func_02018A08, func_02018A7C, func_02018D10, func_02018D34, func_02018D6C, func_02018D8C, func_02018DB4, func_02018E34, func_02019308, func_02019388
 * address:  0x02014910
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02013F2C  0x02013F2C  thumb
 *   func_02013B38  0x02013B38  thumb
 *   func_0201407C  0x0201407C  thumb
 *   func_020140DC  0x020140DC  thumb
 *   func_020140B4  0x020140B4  thumb
 *   sub_020307B0   0x020307B0  arm
 *   sub_0209E054_Map  0x0209E054  data
 *   func_020490A8       0x020490A8  arm
 *   func_02048F60       0x02048F60  arm
 *   _u32_div_f          0x0209C2B0  arm
 *   VEC_Fx16Normalize   0x0207CDB8  arm
 *   func_02011400  0x02011400  thumb
 *   func_02030734     0x02030734  arm
 *   func_020637D4     0x020637D4  arm
 *   func_02049F34     0x02049F34  arm
 *   func_020056A0     0x020056A0  thumb
 *   sFile_020A72CC    0x020A72CC  data
 *   func_02014CD4   0x02014CD4  thumb
 *   func_02030EE8   0x02030EE8  arm
 *   func_020307B0   0x020307B0  arm
 *   func_02030EAC   0x02030EAC  arm
 *   func_02015BA4   0x02015BA4  thumb
 *   func_02016374  0x02016374  thumb
 *   func_020490F4         0x020490F4  arm
 *   ENV_SetResourceSet_2  0x02049238  arm
 *   func_02016BA0  0x02016BA0  thumb
 *   func_0206DB80    0x0206DB80  arm
 *   MTX_Inverse43    0x0207B67C  arm
 *   MI_Copy36B       0x02082B60  arm
 *   MTX_Copy33To44_  0x0207ADE8  arm
 *   MTX_Copy43To44_  0x0207B5C0  arm
 *   MTX_Concat44     0x0207BE14  arm
 *   G3i_LookAt_      0x0207D7C4  arm
 *   G3_RotX          0x0207D810  arm
 *   G3_RotZ          0x0207D888  arm
 *   G3_MultMtx44     0x0207D8FC  arm
 *   sub_0207C768     0x0207C768  arm
 *   _ll_mul          0x0209C054  arm
 *   _fflt            0x0209BDBC  arm
 *   _ffix            0x0209C494  arm
 *   _fadd            0x0209C95C  arm
 *   _fsub            0x0209CB8C  arm
 *   g_02148B98       0x02148B98  data
 *   g_02148B54       0x02148B54  data
 *   g_02148D8C       0x02148D8C  data
 *   g_02148D98       0x02148D98  data
 *   g_02148DA4       0x02148DA4  data
 *   FX_SinCosTable_  0x020A1B38  data
 *   d_0209E090       0x0209E090  data
 *   d_0209E09C       0x0209E09C  data
 *   G3i_FrustumW_    0x0207D760  arm
 *   func_020159C8_File  0x020A72CC  data
 *   func_02016C0C  0x02016C0C  thumb
 *   func_02063000  0x02063000  arm
 *   func_02064D70  0x02064D70  arm
 *   func_020627D8  0x020627D8  arm
 *   func_0206469C  0x0206469C  arm
 *   data_020A72CC  0x020A72CC  data
 *   func_02021F64  0x02021F64  thumb
 *   func_02030DA8  0x02030DA8  arm
 *   func_02082A60  0x02082A60  arm
 *   MIi_CpuCopy16  0x02082A60  arm
 *   func_02064CBC  0x02064CBC  arm
 *   func_02063A54  0x02063A54  arm
 *   func_02063E54  0x02063E54  arm
 *   sub_02030EAC   0x02030EAC  arm
 *   _s32_to_double  0x0209B750  arm
 *   func_0209AB80   0x0209AB80  arm
 *   _d2s            0x0209C508  arm
 *   func_0202D060  0x0202D060  thumb
 *   func_0202D09C  0x0202D09C  thumb
 *   func_0202D0D4  0x0202D0D4  thumb
 *   func_0202D110  0x0202D110  thumb
 *   func_0202D144  0x0202D144  thumb
 *   func_0202D178  0x0202D178  thumb
 *   func_0202D1AC  0x0202D1AC  thumb
 *   func_0202D1E0  0x0202D1E0  thumb
 *   func_0202D5CC  0x0202D5CC  thumb
 *   func_0202D5F8  0x0202D5F8  thumb
 *   func_0202D61C  0x0202D61C  thumb
 *   func_0202D640  0x0202D640  thumb
 *   func_0202D664  0x0202D664  thumb
 *   func_0202D688  0x0202D688  thumb
 *   func_0202D6AC  0x0202D6AC  thumb
 *   func_0202D6D0  0x0202D6D0  thumb
 *   sMcssTable  0x020A72D4  data
 *   g_02146270      0x02146270  data
 *   sPokeToolFile  0x020A72E4  data
 *   func_02008F08  0x02008F08  thumb
 *   func_02019A50  0x02019A50  thumb
 *   func_02019C54  0x02019C54  thumb
 *   func_020056EC  0x020056EC  thumb
 *   func_0203F0A8  0x0203F0A8  arm
 *   func_02045F5C  0x02045F5C  arm
 *   func_0201AE1C  0x0201AE1C  thumb
 *   func_02019C7C  0x02019C7C  thumb
 *   g0209DF0C      0x0209DF0C  data  a1
 *   gMsgBank       0x020A7370  data
 *   gNameBuf       0x021462F0  data
 *   g0209DF08      0x0209DF08  data  a1
 *   func_02017CC8  0x02017CC8  thumb
 *   g_020A7370     0x020A7370  data
 *   g_021462F0     0x021462F0  data
 *   sMoveTbl       0x0209E298  data  a2
 *   func_0202F1B4  0x0202F1B4  thumb
 *   func_0201AF6C  0x0201AF6C  thumb
 *   func_02019A9C  0x02019A9C  thumb
 *   func_0201ADD0  0x0201ADD0  thumb
 *   func_02018094  0x02018094  thumb
 *   gLearnBuf      0x02146330  data
 *   func_0201BD28  0x0201BD28  thumb
 *   func_0201C158  0x0201C158  thumb
 *   func_0201808C  0x0201808C  thumb
 *   func_02018488  0x02018488  thumb
 *   g_021462B0  0x021462B0  data
 *   gWordBuf  0x02146398  data
 *   func_02019BA4  0x02019BA4  thumb
 *   func_02019C90  0x02019C90  thumb
 *   func_02018790_Table  0x0209E288  data
 *   func_02019C38        0x02019C38  thumb
 *   tbl_0209E2A4   0x0209E2A4  data  a1
 *   _s32_div_f  0x0209C0A4  arm
 *   sub_02008F3C   0x02008F3C  thumb
 *   _ll_shl        0x0209C074  arm
 *   func_02019BBC  0x02019BBC  thumb
 *   func_02045A38  0x02045A38  arm
 */
#include "../../matched/include/Obj02990.h"
#include "../../matched/include/Obj03429.h"
#include "../../matched/include/Obj11255.h"
#include "../../matched/include/Obj15656.h"
#include "../../matched/include/Obj01459.h"
#include "../../matched/include/Obj15658.h"
#include "../../matched/include/Obj11718.h"
#include "../../matched/include/Obj02638.h"
#include "../../matched/include/Obj11824.h"
#include "../../matched/include/Obj17197.h"
#include "../../matched/include/Obj17198.h"
#include "../../matched/include/Obj17199.h"
#include "../../matched/include/Obj08751.h"
#include "../../matched/include/Obj00933.h"
#include "../../matched/include/Obj08752.h"
#include "../../matched/include/Obj08754.h"
#include "../../matched/include/Obj08756.h"
#include "../../matched/include/Obj08757.h"
#include "../../matched/include/Obj08759.h"
#include "../../matched/include/Obj08761.h"
#include "../../matched/include/Obj08763.h"
#include "../../matched/include/Obj08765.h"
#include "../../matched/include/Obj08767.h"
#include "../../matched/include/Obj08769.h"
#include "../../matched/include/Obj15659.h"
#include "../../matched/include/Obj15660.h"
#include "../../matched/include/Obj08771.h"
#include "../../matched/include/Obj15661.h"
#include "../../matched/include/Obj15662.h"
#include "../../matched/include/Obj15663.h"
#include "../../matched/include/Obj15664.h"
#include "../../matched/include/Obj15665.h"
#include "../../matched/include/Obj15667.h"
#include "../../matched/include/Obj15669.h"
#include "../../matched/include/Obj11257.h"
#include "../../matched/include/Obj15670.h"
#include "../../matched/include/Obj02301.h"
#include "../../matched/include/Obj16729.h"
#include "../../matched/include/Obj15671.h"
#include "../../matched/include/Obj15672.h"
#include "../../matched/include/Obj01093.h"
#include "../../matched/include/Obj01612.h"
#include "../../matched/include/Obj06864.h"
#include "../../matched/include/Obj15676.h"
#include "../../matched/include/Obj15677.h"
#include "../../matched/include/Obj15678.h"
#include "../../matched/include/Obj15679.h"
#include "../../matched/include/Obj15680.h"
#include "../../matched/include/Obj15681.h"
#include "../../matched/include/Obj01613.h"
#include "../../matched/include/Obj06865.h"
#include "../../matched/include/Obj11719.h"
#include "../../matched/include/Obj15687.h"
#include "../../matched/include/Obj01018.h"
#include "../../matched/include/Obj00696.h"
#include "../../matched/include/Obj00353.h"
#include "../../matched/include/Obj01104.h"
#include "../../matched/include/Obj07131.h"
#include "../../matched/include/Obj11258.h"
#include "../../matched/include/Obj15713.h"
#include "../../matched/include/Obj15715.h"

#define REG_MTX_MODE     (*(vu32 *)0x04000440)
#define REG_MTX_PUSH     (*(vu32 *)0x04000444)
#define REG_MTX_POP      (*(vu32 *)0x04000448)
#define REG_MTX_STORE    (*(vu32 *)0x0400044C)
#define REG_MTX_IDENTITY (*(vu32 *)0x04000454)
#define REG_MTX_SCALE    (*(vu32 *)0x0400046C)
#define REG_MTX_TRANS    (*(vu32 *)0x04000470)
#define REG_TEXIMAGE_PARAM (*(vu32 *)0x040004A8)
#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? \
                                  ((x) * (1 << 12) + 0.5f) : \
                                  ((x) * (1 << 12) - 0.5f)))
#define REG_MTX_RESTORE  (*(vu32 *)0x04000450)
#define REG_TEXCOORD     (*(vu32 *)0x04000488)
#define REG_VTX_16       (*(vu32 *)0x0400048C)
#define REG_POLYGON_ATTR (*(vu32 *)0x040004A4)
#define REG_TEXPLTT_BASE (*(vu32 *)0x040004AC)
#define REG_BEGIN_VTXS   (*(vu32 *)0x04000500)
#define REG_END_VTXS     (*(vu32 *)0x04000504)
struct Desc;
struct Obj_02014910;
struct Sub020140BCObj;
struct Obj_02016880;
struct Node;
struct Sub02014CB8Obj;
struct S02030EE8;
struct Obj02014CF0;
struct Ctx;
struct Src;
struct McssSys_02014910;
struct McssWork_02014910;
struct MtxFx44;
struct Pose;
struct Tex;
struct VecFx32;
struct AnimBank;
struct AnimSequence;
struct Obj0206469C;
struct Obj_0201691C;
struct Obj_0;
struct Task;
struct Work;
struct ArcFile;
struct Out;
struct Res;
struct Obj;
struct Rec;
struct Stats;
struct Sub150;
struct Pokemon;
struct Pokemon;
struct Pokemon;
struct MsgData;
struct Personal;
struct Pokemon;
struct Sub0200852CObj;
struct Pokemon;
struct Sub02008F80Obj;
struct MsgBank;
struct Strbuf;
struct U16Vec;
typedef unsigned int u32;

typedef unsigned short u16;

typedef signed int     s32_02014910;

typedef unsigned char  u8;

typedef signed short s16;

typedef struct {
    u8  pad00[0xc];
    void *f0c;
    u32 f10;
    u32 f14;
    u8  f18[0x18];
    u32 f30;
    u32 f34;
    u8  pad38[8];
    void *f40;
    u32 f44;
} Obj_02014910;

typedef struct {
    u8  f00[4];
    u8  f04[8];
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    Obj_02014910 *f20;
} Sub;

typedef struct B1 { unsigned int b0 : 1; } B1;

struct Sub02014CB8Obj {
    void *f00;
    u32   f04;
    u32   pad08[0xE];
    u32   f40;
};

struct Sub02014CF8Rec {
    u32 w[9];
};

struct Sub02014CF8Ctx {
    u32                    pad000[(0x148 - 0) / 4];
    void                  *f148;
    u32                    pad14C;
    struct Sub02014CF8Rec  f150;
};

typedef signed long long s64;

typedef s32_02014910 fx32;

typedef s64 fx64;

typedef volatile u32 vu32;

typedef struct { fx32 x, y, z; } VecFx32;

typedef struct { fx32 m[4][3]; } MtxFx43;

typedef struct { fx32 m[3][3]; } MtxFx33;

typedef struct { fx32 m[4][4]; } MtxFx44;

typedef enum { GX_TEXFMT_NONE = 0, GX_TEXFMT_PLTT4 = 2 } GXTexFmt;

typedef enum { GX_TEXGEN_NONE = 0, GX_TEXGEN_TEXCOORD = 1 } GXTexGen;

typedef enum { GX_TEXSIZE_S8 = 0 } GXTexSizeS;

typedef enum { GX_TEXSIZE_T8 = 0 } GXTexSizeT;

typedef enum { GX_TEXREPEAT_NONE = 0, GX_TEXREPEAT_ST = 3 } GXTexRepeat;

typedef enum { GX_TEXFLIP_NONE = 0, GX_TEXFLIP_ST = 3 } GXTexFlip;

typedef enum { GX_TEXPLTTCOLOR0_USE = 0, GX_TEXPLTTCOLOR0_TRNS = 1 } GXTexPlttColor0;

struct Pose {
    u16  f00;
    u16  rot;
    fx32 sx;
    fx32 sy;
    s16  ox;
    s16  oy;
};

struct PoseT { u16 f00; u16 pad; s16 ox; s16 oy; };

struct AnimFrame { void *content; u16 frames; u16 pad; };

struct AnimSeq   { u16 numFrames; u16 loopStart; u32 type; };

struct AnimCtrl {
    struct AnimFrame *cur;
    u8   pad04[0x1c - 0x04];
    struct AnimSeq *seq;
};

struct Node {
    struct AnimCtrl ctrl;
    u8   pad20[0x5c - 0x20];
};

struct Cell_02014910  { s16 f00; s16 f02; s16 f04; u16 f06; };

struct Frame_02014910 { u16 count; u16 pad; struct Cell_02014910 *cells; };

struct MAnim { u32 f00; struct Frame_02014910 *frames; };

struct Quad  { s32_02014910 x, y, w, h, s, t; };

struct Rec_02014910   { struct Quad q0; struct Quad q1; };

struct TexInfo {
    u32 addr;
    u32 f04;
    u32 f08;
    u32 s;
    u32 t;
    u32 fmt;
    u32 f18;
    u32 pltt0;
};

struct McssTex { s32_02014910 fmt; u32 f04; u32 plttBase; };

struct McssSys_02014910 {
    u8   pad00[0x10];
    s32_02014910  count;
    struct McssWork_02014910 **slots;
    struct McssTex tex;
    u8   pad24[0x2c - 0x24];
    u32  f2c_0 : 1;
    u32  f2c_r : 31;
    u8   pad30[0x44 - 0x30];
    fx32 f44;
    s32_02014910  f48;
};

struct McssWork_02014910 {
    u8   pad00[0x2c];
    u8  *f2c;
    u8   pad30[0x34 - 0x30];
    struct AnimCtrl ctrl;
    u8   pad54[0x74 - 0x54];
    struct Node *nodes;
    struct MAnim *anim;
    u8   pad7c[0x9c - 0x7c];
    struct TexInfo tex;
    u8   padbc[0xe0 - 0xbc];
    fx32 fe0, fe4, fe8;
    fx32 fec, ff0, ff4;
    u8   padf8[0x100 - 0xf8];
    fx32 f100;
    fx32 f104, f108, f10c;
    fx32 f110, f114, f118;
    fx32 f11c, f120, f124;
    fx32 f128, f12c, f130;
    u8   pad134[0x140 - 0x134];
    u32  b0  : 8;
    u32  b8  : 1;
    u32  b9  : 2;
    u32  b11 : 1;
    u32  b12 : 1;
    u32  b13 : 1;
    u32  b14 : 9;
    u32  b23 : 1;
    u32  b24 : 5;
    u32  b29 : 1;
    u32  b30 : 1;
    u32  b31 : 1;
    u8   pad144[0x178 - 0x144];
    u16  f178;
    u16  f17a;
    fx32 f17c, f180, f184;
};

struct McssSys_020155A0 {
    u8   pad00[0x2c];
    u32  f2c_0 : 1;
    u32  f2c_1 : 1;     /* far plane 512 vs 1024, depth step 0x100 vs 0x400 */
    u32  f2c_r : 30;
    u8   pad30[0x48 - 0x30];
    s32_02014910  f48;           /* depth step override when non-zero */
};

struct Cell_020155A0  { s16 f00; s16 f02; s16 f04; s16 f06; };

struct Frame_020155A0 { u32 f00; struct Cell_020155A0 *f04; };

struct Anim  { u32 f00; struct Frame_020155A0 *f04; };

struct McssWork_020155A0 {
    u8   pad00[0x78];
    struct Anim *f78;
    u8   pad7c[0xc0 - 0x7c];
    s32_02014910  fc0;           /* texture format; 2 = GX_TEXFMT_PLTT4 */
    u32  fc4;
    u32  fc8;           /* palette base */
    u8   padcc[0x140 - 0xcc];
    u32  b0  : 8;       /* the flag word, docs/families/mcss.h */
    u32  b1  : 6;
    u32  b4  : 9;
    u32  b23 : 1;
    u32  b24 : 6;
    u32  b30 : 1;
    u32  b31 : 1;
};

struct Tex { s32_02014910 fmt; u32 f04; u32 plttBase; };

struct Sub150 {
    u32 w[9];
};

struct Rec_020159C8 {
    u32 pad000[0x38];
    u32 unk0E0;
    u32 unk0E4;
    u32 unk0E8;
    u32 unk0EC;
    u32 unk0F0;
    u32 unk0F4;
    u32 pad0F8[6];
    u32 unk110;
    u32 unk114;
    u32 unk118;
    u32 unk11C;
    u32 unk120;
    u32 unk124;
    u32 unk128;
    u32 unk12C;
    u32 unk130;
    u32 pad134[3];
    u32 f0 : 8;
    u32 f1 : 3;
    u32 f2 : 1;
    u32 f3 : 2;
    u32 f4 : 9;
    u32 f5 : 6;
    u32 f6 : 1;
    u32 f7 : 2;
    u32 unk144;
    u32 unk148;
    u32 unk14C;
    struct Sub150 unk150;
    u32 unk174;
    u16 unk178;
    u16 unk17A;
    u32 unk17C;
    u32 unk180;
    u32 unk184;
};

struct Obj_02014910 {
    u32 pad00[4];
    s32_02014910 unk10;
    struct Rec_020159C8 **unk14;
    u32 pad18[10];
    u32 unk40;
};

struct R_02015DD4 {
    unsigned int : 8;
    unsigned int f : 1;
};

typedef struct {
    char pad[0x140];
    unsigned int lo : 9;
    unsigned int b : 2;
    unsigned int hi : 21;
} R_02015DF8;

struct Reg02015Exx {
    unsigned int : 9;
    unsigned int f : 2;
};

struct R_02015E28 {
    unsigned int : 9;
    unsigned int f : 2;
};

struct Reg02015E4C {
    unsigned int : 9;
    unsigned int f : 2;
};

struct R {
    unsigned int : 9;
    unsigned int f : 2;
};

typedef struct {
    char pad[0x140];
    unsigned int lo : 11;
    unsigned int b : 1;
    unsigned int hi : 20;
} R;

typedef struct {
    char pad[0x30];
    u8 *p30;
} S;

typedef signed char   s8;

struct McssFade {
    u8  pad[0x134];
    s8  f134;       /* +0x134  current value */
    s8  f135;       /* +0x135  target value  */
    u8  f136;
    u8  f137;
    s32_02014910 f138;       /* +0x138  step          */
    u32 f13c;
    u32 f140;       /* +0x140  flag word     */
};

typedef struct {
    char pad[0x140];
    unsigned int value : 8;
} Data_0;

struct Flags0201600C {
    u32   : 12;
    u32 f : 1;
};

typedef struct {
    char pad[0x140];
    unsigned int padbits : 24;
    unsigned int value : 4;
} Data_02016068;

struct Sub02016078Word {
    u32 low24 : 24;
    u32 mode  : 4;
    u32 hi4   : 4;
};

typedef struct {
    char pad[0x28];
    u16 *p28;
} S_0;

struct Inner {
    u32 f00;
    u32 f04;
    u32 f08;
    void *f0c;
};

struct Obj_0 {
    u8 pad00[4];
    struct Inner *f04;
    u8 pad08[4];
    void *f0c;
    u8 pad10[0xc];
    u32 f1c;
    void *f20;
    void *f24;
    u32 f28;
};

typedef struct {
    char pad[0x140];
    unsigned int lo : 30;
    unsigned int f : 1;
    unsigned int hi : 1;
} S_1;

typedef struct {
    char pad[0x2c];
    unsigned int b0 : 1;
    unsigned int b1 : 1;
} Obj_0;

struct Obj_020163C4 {
    void *f00;
    void *f04;
    void *f08;
    void *f0c;
    void *f10;
    void *f14;
    u32 f18;
    u32 f1c;
    void *f20;
    void *f24;
    u32 f28;
};

struct Ctx {
    void *f00;
    void *f04;
    void *f08;
    u8 pad0c[8];
    void **f14;
    u8 pad18[0x18];
    u32 f30;
    u32 f34;
    u32 (*f38)(void *, void *, u32);
    u32 f3c;
};

struct Src {
    void *f00;
    void *f04;
    void *f08;
    void *f0c;
    void *f10;
    void *f14;
    void *f18;
    void *f1c;
    u32 f20;
};

struct Obj_020160C4 {
    void *f00;
    void *f04;
    void *f08;
    void *f0c;
    void *f10;
    void *f14;
    u32 f18;
    u32 f1c;
    void *f20;
    void *f24;
    u32 f28;
};

struct Obj_02016880 {
    void *f00;                    /* +0x00 */
    void *f04;                    /* +0x04 */
    u32  f08;                     /* +0x08 */
    u32  f0c;                     /* +0x0c */
    void *f10;                    /* +0x10 */
    void *f14;                    /* +0x14 */
    u32  f18;                     /* +0x18 */
    u32  f1c;                     /* +0x1c */
    struct Obj20_02016880 *f20;   /* +0x20 */
    u32 *f24;                     /* +0x24 */
    u32  f28;                     /* +0x28 */
};

struct Obj20_02016880 {
    u8   pad00[0xc];
    void *f0c;                    /* +0x0c */
};

struct Obj24_0201691C {
    u8   pad00[4];
    void *f04;      /* +0x04 */
    void *f08;      /* +0x08 */
};

struct Obj04_0201691C {
    u8   pad00[0xc];
    void *f0c;      /* +0x0c */
};

struct Obj_0201691C {
    u8   pad00[4];
    struct Obj04_0201691C *f04;   /* +0x04 */
    u8   pad08[4];
    void *f0c;                    /* +0x0c */
    u8   pad10[0xc];
    u32  f1c;                     /* +0x1c */
    u8   pad20[4];
    struct Obj24_0201691C *f24;   /* +0x24 */
    u32  f28;                     /* +0x28 */
};

struct Obj {
    u8 pad00[4];
    struct Inner *f04;
    u8 pad08[4];
    void *f0c;
    u8 pad10[0xc];
    u32 f1c;
    void *f20;
    void *f24;
    u32 f28;
};

struct Rec
{
  s32_02014910 f00;
  s32_02014910 f04;
  s32_02014910 f08;
  s32_02014910 f0c;
  s32_02014910 f10;
  s32_02014910 f14;
  s32_02014910 f18;
  s32_02014910 f1c;
  s32_02014910 f20;
  s32_02014910 f24;
  s32_02014910 f28;
  s32_02014910 f2c;
  s32_02014910 f30;
  s32_02014910 f34;
  s32_02014910 f38;
};

struct Work
{
  u8 pad00[0x2c];
  s32_02014910 *f2c;
  u8 pada8[0xa8 - 0x30];
  s32_02014910 fa8;
  u8 padac[4];
  s32_02014910 fb0;
  u8 padb4[0x140 - 0xb4];
  u32 f140;
};

struct Task
{
  u8 **f00;
};

struct VecFx32 {
    s32_02014910 x;
    s32_02014910 y;
    s32_02014910 z;
};

struct MtxFx44 {
    s32_02014910 m[4][4];
};

struct Stats {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
};

typedef unsigned long long u64;

/* the header plus the masked block area: 0x22 words, whose eight-byte
 * ldm/stm step and 0x11 trip count are what the copy loop below proves */
struct Mon_0 { u32 w[0x22]; };

struct Mail {
    u8 unk00[0x38];
};

/* One Pokemon record, 0xDC bytes: seed word, flag bits and checksum, the
 * 0x80 byte masked block area at +0x08, and the 0x54 byte masked party
 * area at +0x88. */
struct Pokemon {
    u32 unk00;
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 13;
    u16 unk06;
    u8  unk08[0x80];
    u32 unk88;
    u8  unk8C;
    u8  unk8D;
    u16 unk8E;
    u16 unk90;
    u16 unk92;
    u16 unk94;
    u16 unk96;
    u16 unk98;
    u16 unk9A;
    struct Mail unk9C;
    u8  padD4[8];
};

struct MoveTbl { u16 v[6]; };

struct Learn { u16 move; u16 level; };

typedef int            s32_0201808C;

typedef signed int     s32;

struct Hdr {
    u32 unk00;
};

struct RecA {
    u8  unk00[0x1C];
    u32 unk1C;
};

struct RecB {
    u8  unk00[0x14];
    u32 unk14;
};

struct RecC {
    u8  unk00[0x18];
    u64 unk18;
};

struct BlockA {
    u16 species;
    u16 item;
    u32 otId;
    u32 exp;
    u8  unk0C;
    u8  unk0D;
    u8  unk0E;
    u8  unk0F;
    u8  unk10[6];
    u8  unk16[6];
    u32 unk1C;
};

struct BlockB {
    u16 moves[4];
    u8  pp[4];
    u8  ppUp[4];
    u32 iv0 : 5;
    u32 iv1 : 5;
    u32 iv2 : 5;
    u32 iv3 : 5;
    u32 iv4 : 5;
    u32 iv5 : 5;
    u32 iv6 : 1;
    u32 iv7 : 1;
    u32 unk14;
    u8  f0 : 1;
    u8  f1 : 2;
    u8  f2 : 5;
    u8  unk19;
    u16 g0 : 1;
    u16 g1 : 15;
    u32 unk1C;
};

struct BlockC {
    u16 unk00[11];
    u8  unk16;
    u8  unk17;
    u64 unk18;
};

struct BlockD {
    u16 unk00[8];
    u8  unk10;
    u8  unk11;
    u8  unk12;
    u8  unk13;
    u8  unk14;
    u8  unk15;
    u16 unk16;
    u16 unk18;
    u8  unk1A;
    u8  unk1B;
    u8  h0 : 7;
    u8  h1 : 1;
    u8  unk1D;
    u16 unk1E;
};

extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj_02014910 *p);
extern u32 func_02014878(u32 a0, u32 *mode, u32 *p);
extern u32 func_02013F2C(u32 id);
extern u32 func_02013B38(u32 id);
extern void *func_0201407C(u16 heap, u32 a, u32 b);
extern u8 func_020140DC(struct Sub020140BCObj *p);
extern u32 func_020140B4(void *a);
extern u32 sub_020307B0(void *p);
extern u32   func_020490A8(u32 a, u32 b);
extern void *func_02048F60(u32 archive, u32 member, u32 heap);
extern u32   _u32_div_f(u32 a, u32 b);
extern void  VEC_Fx16Normalize(void *dest, const void *src);
extern u8 func_02011400(int row, int col);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_020637D4(u32 *p);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern void *func_020056A0(void *fn, Sub *s, u32 a);
extern void func_02014CD4(struct Sub02014CB8Obj *o);
extern u32 func_02030EE8(struct S02030EE8 *p);
extern u32 func_020307B0(void *p);
extern void func_02030EAC(struct Node *n);
extern void  func_02015BA4(void *a0, void *a1);
extern void func_020649D4(char *member, int value);
extern void func_02016374(void *obj);
extern void *func_020490F4(u32 id, u32 heap);
extern void  ENV_SetResourceSet_2(void *p);
extern void func_02016BA0(void *obj);
extern void func_0206DB80(void);
extern int  MTX_Inverse43(const MtxFx43 *src, MtxFx43 *dst);
extern void MI_Copy36B(const void *src, void *dst);
extern void MTX_Copy33To44_(const MtxFx33 *src, MtxFx44 *dst);
extern void MTX_Copy43To44_(const MtxFx43 *src, MtxFx44 *dst);
extern void MTX_Concat44(const MtxFx44 *a, const MtxFx44 *b, MtxFx44 *ab);
extern void G3i_LookAt_(const VecFx32 *camPos, const VecFx32 *camUp,
                        const VecFx32 *target, int draw, MtxFx43 *mtx);
extern void G3_RotX(fx32 s, fx32 c);
extern void G3_RotZ(fx32 s, fx32 c);
extern void G3_MultMtx44(const MtxFx44 *m);
extern u32 sub_0207C768(u32 a, u32 b);
extern void G3i_FrustumW_(fx32 t, fx32 b, fx32 l, fx32 r, fx32 n, fx32 f,
                          fx32 scaleW, int draw, void *mtx);
extern void func_02016C0C(void *id);
extern void func_02063000(int p0, int p1, int p2, int p3);
extern void func_02064D70(void *, void *, unsigned);
extern struct AnimSequence *func_020627D8(struct AnimBank *bank, u32 idx);
extern void func_0206469C(struct Obj0206469C *o, void *bank);
extern void *func_02030DA8(void *a0, void *callback, void *ctx, int a3);
extern void  func_02021F64(int a, int b, u16 c, int d, u16 e);
extern void  func_02082A60(int a, int b, int c);
extern void MIi_CpuCopy16(const void *src, void *dest, u32 size);
extern void func_02064CBC(struct Obj_0 *x);
extern void *func_02049FBC(void *a0, void *a1, u32 a2, void *a3, u32 a4);
extern void *func_0204A03C(void *a0, void *a1, u32 a2, void *a3, u32 a4);
extern void *func_0204A0BC(void *a0, void *a1, u32 a2, void *a3, u32 a4);
extern void *func_0204A13C(void *a0, void *a1, u32 a2, void *a3, u32 a4);
extern void *func_02049DB4(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_02063790(u32 *p);
extern void *func_02049FFC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void *func_0204A07C(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void *func_0204A0FC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void *func_0204A17C(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void *func_02049250(struct ArcFile *arc, u32 member, u32 heap);
extern void *func_02049DF4(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02063A54(struct Res *r, u32 dst, int mode, struct Out *out);
extern void func_02063E54(void *a, u32 b, int c, u32 d);
extern void sub_02030EAC(struct Node *n);
extern int func_020648B4(u32 a, u32 b);
extern void func_02064754(char *o, char *buf, void *set, int a3, void *bank, int kind);
extern double _s32_to_double(s32_02014910 v);
extern double func_0209AB80(double a, double b);
extern s32_02014910 _d2s(double d);
extern int func_0202D060(void);
extern s32_02014910 func_0202D09C(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern s32_02014910 func_0202D0D4(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern s32_02014910 func_0202D110(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern s32_02014910 func_0202D144(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern s32_02014910 func_0202D178(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern s32_02014910 func_0202D1AC(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern s32_02014910 func_0202D1E0(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern u32 func_0202D5CC(u32 a);
extern u32 func_0202D5F8(u32 id, u32 flags);
extern u32 func_0202D61C(u32 id, u32 flags);
extern u32 func_0202D640(u32 id, u32 flags);
extern u32 func_0202D664(u32 id, u32 flags);
extern u32 func_0202D688(u32 id, u32 flags);
extern u32 func_0202D6AC(u32 id, u32 flags);
extern u32 func_0202D6D0(u32 id, u32 flags);
extern void func_0201AD88(u32 heap);
extern void *func_02008F08(int a0);
extern void MIi_CpuClearFast(u32 value, void *dest, u32 size);
extern void func_02019A50(u16 *p, u32 size, u32 seed);
extern void *func_02019C54(u32 a, u16 b);
extern u32   func_020056EC(u32 a);
extern u32   func_0203F0A8(void);
extern void func_02045F5C(struct MsgData *msg, u32 msgIndex, u16 *str, u32 maxLen);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern u32   func_02019C7C(void *a);
extern void func_02017CC8(void *a0, void *a1, void *a2);
extern void func_0202F1B4(u32 a, u32 b, u32 c, u32 d, u32 e);
extern u32 sub_02017E1C(void *p, u32 id, u32 v);
extern void sub_02017E40(void *p, u32 id, u32 v);
extern u32  func_0201AF6C(u32 a0);
extern u16 func_02019A9C(const u16 *p, u32 size);
extern void func_0201ADD0(u32 species, int form, void *dest);
extern u32 func_0201BD28(u16 id, u32 field);
extern u8 func_0201C158(u16 move, u32 ppUp);
extern u32 func_02018488(void *p, void *mail);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u32 func_020084F8(void *dst, u32 value, u32 size);
extern u32 func_0201F448(const u16 *a, const u16 *b);
extern void  func_02019B94(u32 a, void *b);
extern u32 func_02019BA4(u32 x, u32 i);
extern u32 func_02019C90(u16 a, u16 b, u32 k);
extern void *func_02019C38(struct Pokemon *p, u32 pid, u32 n);
extern u32  func_02019B04(u32 a, u32 b, u32 n);
extern void sub_02008F3C(const struct Sub02008F80Obj *src, struct Sub02008F80Obj *dest);
extern u32 func_02019BBC(u32 item);
extern void func_0201F41C(const u16 *src, u16 *dst, u32 n);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32  func_02019ABC(struct Pokemon *p);
extern void func_02045A38(struct U16Vec *src, u16 *dest, u32 n);
void *func_02014910(char *a0, int a1, int a2, int a3);
void func_0201493C(u32 id, u32 a1, u32 a2, u32 a3, u32 b0, u16 *b1, u16 heap);
u16 func_02014A10(u32 i);
void *func_02014A20(u32 archive, u32 member, u32 *count_out, u32 heap);
void func_02014A80(u8 *a0, u32 a1, s32_02014910 a2, u32 a3, u16 *out);
void *func_02014B08(u32 id, void *heap);
void func_02014BA8(u8 *a0);
void func_02014C08(char *self);
void sub_02014CB8(struct Sub02014CB8Obj *o, u32 x);
void sub_02014CD4(struct Sub02014CB8Obj *o);
void func_02014CEC(u8 *p, u32 value);
void sub_02014CF0(struct Obj02014CF0 *o, int v1, int v2);
void sub_02014CF8(void *a, struct Sub02014CF8Ctx *b, const struct Sub02014CF8Rec *c);
void func_02014D2C(struct McssSys_02014910 *sys);
void func_020155A0(struct McssSys_020155A0 *sys, struct McssWork_020155A0 *w, fx32 x, fx32 y, fx32 width, fx32 height, fx32 s, fx32 t, struct Pose *pose, u16 *frame, struct Tex *tex, int id, int proj, u32 *z, u8 flip);
struct Rec_020159C8 *func_020159C8(struct Obj_02014910 *obj, u32 a1, u32 a2, u32 a3, const struct Sub150 *src);
void sub_02015BA4(void *sys, void *obj);
void sub_02015BF0(void *obj);
void sub_02015C00(void *obj);
void sub_02015C0C(void *obj);
void sub_02015C1C(void *obj);
void func_02015C30(void *p, u32 *out);
void func_02015C48(void *p, u32 *src);
void func_02015C60(void *p, u32 *out);
void func_02015C78(void *p, u32 *src);
void func_02015C94(void *p, u32 *out);
void func_02015CAC(void *p, u32 *src);
void func_02015CC4(void *p, u32 *out);
void func_02015CDC(void *p, u32 *src);
void func_02015CF8(void *p, u32 *out);
void func_02015D14(void *p, u32 *src);
void func_02015D30(void *p, u32 *src);
void func_02015D4C(void *p, u32 *out);
void func_02015D64(void *p, u32 *src);
void func_02015D80(u8 *p, u16 v);
void func_02015D88(char *p, u16 value);
void func_02015D94(char *p, int *src);
void func_02015DB0(void *p);
void func_02015DC0(void *p);
void func_02015DD4(void *p);
int func_02015DF8(R_02015DF8 *p);
void func_02015E04(void *p);
void func_02015E28(void *p);
void func_02015E4C(void *p);
void func_02015E70(void *p);
int func_02015E94(R *p);
void func_02015EA0(void *p);
void func_02015EB0(void *p);
void func_02015EC4(R *p);
void *func_02015EE8(void *p);
u16 func_02015EEC(char *p);
u8 func_02015EF4(char *p);
u8 func_02015EFC(char *p, u8 i);
u16 func_02015F04(void *p);
u16 func_02015F0C(void *p);
s16 func_02015F14(void *p);
s16 func_02015F1C(void *p);
u8 func_02015F24(S *s);
void sub_02015F2C(void *a, u32 arg1, u32 arg2);
void func_02015F40(char *p, unsigned flags, void *callback);
void func_02015F50(struct McssFade *w, u32 cur, u32 target, s32_02014910 step, u32 e);
u8 func_02015FAC(Data_0 *p);
void func_02015FBC(char *p, int v);
void func_02015FD4(char *p, int v);
void func_02015FF0(char *p, int v);
int func_0201600C(void *p);
void func_02016020(void *p, u32 v);
void func_02016024(char *p, unsigned int v);
void sub_02016028(void *a, u32 flag);
u8 func_02016068(Data_02016068 *p);
void sub_02016078(void *a, void *b, int mode);
void func_020160C0(char *p, unsigned int v);
void func_020160C4(char *p, int v);
u16 func_020160CC(S_0 *s);
void func_020160D4(char *a0, char *a1, u16 a2, int a3);
void func_0201624C(u8 *a0, u8 *a1);
void sub_02016374(void *obj);
void sub_02016380(void *o);
void func_02016394(S_1 *s, int f);
void func_020163B0(char *p, int v);
void func_020163B4(Obj_0 *p, int v);
void func_020163C4(struct Ctx *a0, u32 idx, const struct Src *a2);
void func_02016630(struct Ctx *a0, u32 idx, const struct Src *a2);
void func_02016880(void *a0, struct Obj_02016880 *a1);
void func_0201691C(void *a0, struct Obj_0201691C *a1);
void func_02016984(char *a0, int a1);
void sub_020169D4(void);
void func_020169E8(u8 *a0, u8 *a1);
void sub_02016BA0(void *obj);
void sub_02016C0C(void *id);
void func_02016C38(int a0);
void func_02016C60(struct Work *a0, struct Task *a1);
void func_02016FC8(const struct VecFx32 *v, const struct MtxFx44 *mtx, struct VecFx32 *dst, s32_02014910 *w);
void func_02017100(void *p, struct Stats *out, u32 lvl);
void func_02017114(void *p, struct Stats *out, u32 lvl);
void func_02017168(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, struct Stats *out, u32 a6);
void func_02017214(void *p, struct Stats *out, void *q);
void *func_02017270(void *a0, void *a1, u32 a2, u32 a3, u32 a4, u32 a5);
void func_020172AC(int a0, int a1);
u32 func_020172BC(u8 *a0, u8 **a1, u32 a2);
void func_020172D8(u8 *a0, u32 a1);
int func_020173B4(int a0);
void sub_020173C8(void *o);
void func_020173D0(u32 heap);
u32 func_020173E8(void);
u32 func_020173EC(void);
void *func_020173F0(u16 species, u16 level, u64 id, u16 heap);
void *func_02017430(u16 species, u16 level, u64 id, u32 pow, u64 rnd, u16 heap);
void *func_0201747C(struct Mon_0 *p, u16 heap);
void func_02017528(struct Pokemon *p);
void func_02017550(struct Pokemon *p);
void func_0201756C(void *obj, u16 species, u16 level, u64 id);
void func_02017588(struct Pokemon *p, u16 species, u16 level, u64 id, u32 pow, u64 rnd);
void func_02017600(void *obj, u16 species, u16 level, u64 id);
void func_0201761C(void *obj, u16 species, u16 level, u64 id, u32 pow, u64 rnd);
void func_020178D8(void *p, u32 a);
u32 func_02017900(void *a0, u32 a1);
u32 func_02017988(void *p, u32 a);
int func_020179B8(int a0, int a1);
u32 func_02017A20(void *p, u32 idx, u32 val);
void func_02017B24(void *p, u32 a, u32 b, u32 c);
u32 func_02017B4C(void *a0, u32 a1, u32 a2, u32 a3);
void func_02017BC8(u8 *p, u32 i);
void func_02017C50(int a0, int a1, int a2);
void sub_02017CC8(void *a0, void *a1, void *a2);
u32 func_02017D30(struct Pokemon *p);
u32 func_02017D70(struct Pokemon *p, u32 f);
u32 func_02017DBC(struct Pokemon *p);
u32 func_02017DE4(struct Pokemon *p, u32 f);
u32 func_02017E1C(void *p, u32 id, u32 v);
void func_02017E40(void *p, u32 id, u32 v);
void func_02017E64(void *p, u32 id, u32 v);
u32 func_02017E88(void *p, u32 id, u32 v);
u32 func_02017EAC(void *p);
u32 func_02017EB4(void *p);
u32 func_02017ED8(u32 a, u32 b);
u8 func_02017F00(void *p);
u8 func_02017F08(void *p);
u8 func_02017F50(u32 a, u16 b, u32 c);
u32 func_02017F90(void *p);
void func_02017F9C(void *p, u32 v);
u32 func_02017FA8(void *p);
u32 func_02017FB0(void *p);
u16 func_0201808C(void *p, u16 move);
u16 func_02018094(void *p, u16 move);
void func_020180F4(void *p, u16 move);
void func_020180FC(void *p, u16 v);
void func_02018198(void *mon);
void func_020181A0(void *p);
void func_020181F4(void *p, u16 move, u32 slot);
void func_020181FC(void *p, u16 move, u32 slot);
u32 func_02018238(void *p, u16 move);
u32 func_02018240(void *p, u16 move);
void func_020182A0(void *p, u16 move, u8 slot);
void func_020182A8(void *p, u16 move, u8 slot);
u16 func_02018328(void *p, u32 *idx, u32 heap);
u32 func_02018430(void *p);
u32 func_02018438(void *p);
int func_02018480(void *p, int q);
u32 sub_02018488(void *p, void *mail);
u32 func_0201850C(u16 species, u16 form, u32 exp);
u32 func_02018544(void *p);
u32 func_0201854C(void *p);
u32 func_02018584(u16 a, u16 b, u16 c);
u8 func_02018598(void *p);
u8 func_020185A0(void *p);
void func_020185B0(void *p, u32 v);
void func_020185C4(void *p);
void func_020185F0(void);
void *func_020185F4(void *p);
u32 func_020185F8(int a, u16 b, int c);
u32 func_0201862C(u32 a0, u16 a1, u16 a2, u8 a3, u8 a4, int a5);
u32 func_020186C8(u32 a0, int a1, u16 a2, int a3, int a4, int a5);
u32 func_02018790(void *p);
u32 func_02018820(void *p);
u32 func_020188AC(void *p, int v);
u32 func_020188B4(void *p, s32 v);
u32 func_020188E0(u16 a, u16 b, s32 v);
u32 func_0201891C(void *p, s32 v);
u32 func_02018948(u16 a, u16 b, s32 v);
u32 func_0201897C(struct Hdr *p);
int func_020189D0(void *m, int b);
s8 func_020189D8(void *m, u32 a1);
s8 func_020189F0(u8 nature, u32 stat);
void func_02018A00(void *p, u32 a, u32 b);
void func_02018A08(void *p, u32 a, u32 b);
void func_02018A7C(void *p);
u32 func_02018D10(struct Pokemon *p);
u32 func_02018D34(struct Pokemon *p);
void func_02018D6C(struct Pokemon *p);
void func_02018D8C(struct Pokemon *p);
u32 func_02018DB4(struct Pokemon *p, u32 id, u32 v);
u32 func_02018E34(struct Pokemon *p, u32 id, u32 v);
void func_02019308(struct Pokemon *p, u32 id, u32 v);
void func_02019388(struct Pokemon *p, u32 id, u32 v);
extern u32 sub_0209E054_Map[];
extern char  sFile_020A72CC[];
extern MtxFx43 g_02148B98;
extern MtxFx44 g_02148B54;
extern VecFx32 g_02148D8C;
extern VecFx32 g_02148D98;
extern VecFx32 g_02148DA4;
extern s16 FX_SinCosTable_[];
extern const VecFx32 d_0209E090;
extern const VecFx32 d_0209E09C;
extern const char func_020159C8_File[];
extern char data_020A72CC[];
extern const u8 *sMcssTable[4];
extern unsigned char g_02146270[];
extern u8    sPokeToolFile;
extern u8   g0209DF0C;
extern void *gMsgBank;
extern u16  gNameBuf[];
extern u8   g0209DF08;
extern void *g_020A7370;
extern u8    g_021462F0[];
extern const struct MoveTbl sMoveTbl;
extern struct Learn gLearnBuf[];
extern u8 g_021462B0[];
extern u32 gWordBuf[];
extern const u8 func_02018790_Table[];
extern const s8 tbl_0209E2A4[][5];

















/*
 *           Closed at the bottom, not unfiled: no branch anywhere in the image
 *           reaches 0x02014878, so only a `matched` entry could attest it, and
 *           func_02014878 is itself capped at MATCH by two own-pool words
 *           (0x0000005B at 0x02014900, 0x00000083 at 0x02014908 - each occurs
 *           exactly once in arm9, inside its own compared range).  See
 *           docs/notes/pkt_02014808.c.txt.
 */
void *func_02014910(char *a0, int a1, int a2, int a3)
{
    void *r = func_020122C0(a0, 0, (void *)((int)func_02014878), 0x10);
    u32 *p = func_020124E8((struct Obj_02014910 *)r);

    p[0] = (u32)a0;
    p[1] = a1;
    p[2] = a2;
    p[3] = a3;
    return r;
}
















/*
 * The three-way fallback load of the 0x34-byte time-of-day table (member
 * 0x3e for an explicit id, 0x52 for the id func_02013F2C maps, else 0x3d
 * built through func_0201407C), then func_02014A80 over it and a free.
 *
 * Closed in wave 13 by the declaration, not the body: the seventh
 * parameter is a u16 heap id (the ov094 caller at 0x021F7702 loads it
 * with ldrh), written `(heap & 0x7fff) | 0x8000` at each of the four
 * uses.  The earlier note (docs/notes/pkt_0201493C.c.txt) read it as the
 * low half of a word through `*(u16 *)((char *)&b0 + 8)` and had to spell
 * the first tag as 0x10000000; with the real parameter type both of its
 * "back-end tie-breaks" (the pooled 0x0FFFFFFF + 1 tag and the late b0
 * reload) disappear.
 */
void func_0201493C(u32 id, u32 a1, u32 a2, u32 a3,
                   u32 b0, u16 *b1, u16 heap)
{
    u32 count;
    void *p = 0;
    s32_02014910 o2;
    s32_02014910 o1;

    o1 = a2 * 0x3c;
    o2 = a1 * 0xe10;

    if (a3 != 0) {
        p = func_02014A20(0x3e, func_02014A10(a3), &count, (u16)((heap & 0x7fff) | 0x8000));
    }
    if (p == 0) {
        u32 t = func_02013F2C((u16)id);
        if (t != 0xfffffff)
            p = func_02014A20(0x52, t, &count, (u16)((heap & 0x7fff) | 0x8000));
    }
    if (p == 0) {
        void *q = func_0201407C((heap & 0x7fff) | 0x8000, func_02013B38((u16)id), b0);
        p = func_02014A20(0x3d, func_020140DC(q), &count, (u16)((heap & 0x7fff) | 0x8000));
        func_020140B4((void *)q);
    }
    func_02014A80(p, count, o1 + o2, b0, b1);
    sub_020307B0(p);
}

















u16 func_02014A10(u32 i)
{
    return sub_0209E054_Map[i];
}

















/*
 * Load a record table out of an archive sub-file: the sub-file's byte size
 * divided by 0x34 is the record count (unsigned divide, `_u32_div_f`), the
 * count is handed back through a3's slot and the block itself is loaded by
 * func_02048F60.  Each 0x34-byte record carries four 6-byte vectors at +0x10
 * (a VecFx16 triple plus a spare halfword) and each is normalized in place
 * before the count is returned.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02014A20.c \
 *       --func func_02014A20 --addr 0x02014A20 --cc 1.1p1 --thumb
 */
void *func_02014A20(u32 archive, u32 member, u32 *count_out, u32 heap)
{
    u32 n;
    u32 i;
    u8 *q;
    u8 *p;
    int j;

    n = func_020490A8(archive, member) / 0x34;
    *count_out = n;
    p = func_02048F60(archive, member, heap);
    for (i = 0; i < n; i++) {
        q = p + i * 0x34 + 0x10;
        for (j = 0; j < 4; j++) {
            VEC_Fx16Normalize(q + j * 6, q + j * 6);
        }
    }
    return p;
}

















/*
 * Scans the 0x34-byte-stride table at a0 for the element whose 3600*hour +
 * 60*minute value first climbs past a2 while the best so far is still at or
 * below it, then returns that element's eight halfword fields through the
 * caller's buffer (the four at +8 and the four at +0x28).
 *
 * Shape notes:
 *  - the index runs from 0 and the loop is entered only when a1 != 0, so the
 *    counter's first comparison sits at the bottom (`cmp r4, a1 / blo`) and
 *    the guard at the top is a bare `adds r0, r1, #0 / beq`);
 *  - the element's +2 field is signed (`ldrsh` with a register offset,
 *    docs/idioms/ldrsh-register-offset-is-signedness.md), which is why both
 *    comparisons on the running value are `bgt`;
 *  - `i % a1` is one call to the unsigned divmod helper with the remainder
 *    read out of r1, so the source must stay a modulo expression and not a
 *    hand-rolled subtraction loop;
 *  - the two products are two statements (`v = 0xE10 * ...; v += ...;`).
 *    Written as one expression mwcc evaluates the s16 arm first and the
 *    15-byte window at +0x2C comes out in the other order.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02014A80.c \
 *       --func func_02014A80 --addr 0x02014A80 --cc 1.1p1 --thumb
 */
void func_02014A80(u8 *a0, u32 a1, s32_02014910 a2, u32 a3, u16 *out)
{
    u32 i;
    s32_02014910 best;
    s32_02014910 v;
    u32 k;
    u8 *e;

    best = 0;
    i = 0;
    if (a1 != 0) {
        do {
            e = a0 + i * 0x34;
            v = 0xE10 * (s32_02014910)func_02011400(a3, *(u16 *)(a0 + i * 0x34));
            v += ((struct Obj02990 *)e)->f2 * 0x3C;
            if (best <= a2 && v > a2) {
                break;
            }
            best = v;
            i++;
        } while (i < a1);
    }

    k = i % a1;
    e = a0 + k * 0x34;
    out[0] = ((struct Obj02990 *)e)->f8;
    out[1] = ((struct Obj02990 *)e)->fA;
    out[2] = ((struct Obj02990 *)e)->fC;
    out[3] = ((struct Obj02990 *)e)->fE;
    out[4] = ((struct Obj02990 *)e)->f28;
    out[5] = ((struct Obj02990 *)e)->f2A;
    out[6] = ((struct Obj02990 *)e)->f2C;
    out[7] = ((struct Obj02990 *)e)->f2E;
}

















void *func_02014B08(u32 id, void *heap)
{
    Obj_02014910 *o;
    Sub *s;
    u32 m;

    o = func_02030734((u32)heap, 0x4c, 1, sFile_020A72CC, 0x78);
    o->f10 = id;
    o->f40 = heap;
    o->f44 = 0x1000;
    o->f14 = (u32)func_02030734((u32)heap, id * 4, 1, sFile_020A72CC, 0x7f);
    o->f30 = 9 << 14;
    o->f34 = 0x1000;
    func_020637D4((u32 *)o->f18);
    m = ((u32)heap & 0x7fff) | 0x8000;
    s = func_02030734((u32)((void *)(u16)m), 0x2c, 1, sFile_020A72CC, 0x8e);
    s->f20 = o;
    s->f0c = (u32)o->f18;
    s->f1c = 0x1100;
    s->f14 = (u32)func_02049F34(0xb, 0x58, (u32)s->f04, (u16)m);
    o->f0c = func_020056A0((void *)func_02016880, s, 0);
    return o;
}

















/*
 * Tear-down of a "list of arrays" record: close the open sub-object at +0xC
 * (three frees through the handle returned by func_02030EE8, then the handle
 * itself), then walk the +0x14 array of +0x10 entries and release each live
 * one through func_02015BA4, finally the array and the record itself.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02014BA8.c \
 *       --func func_02014BA8 --addr 0x02014BA8 --cc 1.1p1 --thumb
 */
void func_02014BA8(u8 *a0)
{
    int i;

    func_02014CD4((struct Sub02014CB8Obj *)a0);
    if (*(u8 * *)&((struct Obj03429 *)a0)->fC != 0) {
        u8 *p = (u8 *)func_02030EE8((struct S02030EE8 *)(*(u8 * *)&((struct Obj03429 *)a0)->fC));

        func_020307B0(*(u8 * *)&((struct Obj15656 *)(*(u8 * *)&((struct Obj11255 *)p)->f4))->fC);
        func_020307B0(*(u8 * *)&((struct Obj11255 *)p)->f4);
        func_020307B0(p);
        func_02030EAC((struct Node *)(*(u8 * *)&((struct Obj03429 *)a0)->fC));
        *(u8 * *)&((struct Obj03429 *)a0)->fC = 0;
    }
    for (i = 0; i < ((struct Obj03429 *)a0)->f10; i++) {
        u32 *arr = *(u32 * *)&((struct Obj03429 *)a0)->f14;
        u32 e = arr[i];

        if (e != 0) {
            func_02015BA4(a0, (u8 *)e);
        }
    }
    func_020307B0(*(u8 * *)&((struct Obj03429 *)a0)->f14);
    func_020307B0(a0);
}

















/*
 * Closed in the second pass (2026-09-22) from the 7-byte near miss in
 * docs/notes/pkt_02014C08.c.txt.  That note, and the two full permuter
 * runs made on it today (tools/permuter.py --mode hill, 171 single
 * mutations; --mode anneal, 2000 compiles) could not move the residue by
 * a single byte, which is the tell the brief names: a residue nothing in
 * the body reaches lives in the DECLARATIONS.
 *
 * THE LEVER IS func_02016374's ARITY.  The original leaves the slot
 * pointer live in r0 through the third bit test:
 *
 *     02014C7C  ldr r0, [r5, #0x14]     ; the slot array
 *     02014C7E  ldr r1, [sp, #4]        ; the offset constant 0x144
 *     02014C80  ldr r0, [r0, r4]        ; the slot -- STAYS in r0
 *     02014C82  ldr r1, [r0, r1]        ; the flag word into r1
 *     ...
 *     02014C8C  bl  #0x2016374          ; called with r0 already set
 *
 * Declared `void func_02016374(void)` the compiler has no reason to keep
 * the slot in r0, puts the flag word there instead and the six
 * instructions at +0x0076..+0x0080 come out with r0 and r1 swapped, the
 * whole 7-byte residue.  Declared `func_02016374(char *w)` and CALLED
 * with the slot, the allocation the image shows is the only legal one and
 * every byte closes.  This confirms the prototype
 * docs/families/mcss.h already carried (`void func_02016374(struct
 * McssWork_02014910 *w)`), which the note had not applied at the call site.
 *
 * The 0x020169E8 site resolves through sole-ref/code (and, since
 * src/matched/func_020169E8.c was filed in the same pass, through
 * `matched` as well).
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02014C08.c \
 *       --func func_02014C08 --addr 0x02014C08 --cc 1.1p1 --thumb
 */
void func_02014C08(char *self)
{
    int i;

    for (i = 0; i < ((struct Obj01459 *)self)->f10; i++) {
        if (*(int *)(((struct Obj01459 *)self)->f14 + i * 4) == 0)
            continue;
        if (((*(unsigned int *)(*(int *)(((struct Obj01459 *)self)->f14 + i * 4) + 0x140) << 0x15) >> 0x1e) == 0)
            func_020649D4((char *)(*(int *)(((struct Obj01459 *)self)->f14 + i * 4) + 0x34),
                          *(int *)(*(int *)(((struct Obj01459 *)self)->f14 + i * 4) + 0x174));
        if (((*(unsigned int *)(*(int *)(((struct Obj01459 *)self)->f14 + i * 4) + 0x140) << 0x13) >> 0x1f) != 0)
            func_020169E8((u8 *)self, (u8 *)(*(int *)(((struct Obj01459 *)self)->f14 + i * 4)));
        if (((B1 *)(*(int *)(((struct Obj01459 *)self)->f14 + i * 4) + 0x144))->b0 == 1) {
            func_02016374((char *)(*(int *)(((struct Obj01459 *)self)->f14 + i * 4)));
            func_020649D4((char *)(*(int *)(((struct Obj01459 *)self)->f14 + i * 4) + 0x34), 0);
            *(unsigned int *)(*(int *)(((struct Obj01459 *)self)->f14 + i * 4) + 0x144) &= ~1u;
        }
    }
}

















/*
 * A whole translation unit, matched as one byte range.
 *
 * alias: an acquire/release pair on the same object. sub_02014CB8 only
 * acts the first time (its own field at +0 is the guard); it records the
 * argument at +4 and installs whatever func_020490F4 returns at +0.
 * sub_02014CD4 is the release: if +0 is set it tears it down and clears
 * both fields.
 *
 * ENV_SetResourceSet_2 is not the same call site as
 * src/matched/unit_02014444.c's ENV_SetResourceSet: `layout/symbols_sdk.txt`
 * recovers three separate addresses for that SDK name (0x020307B0,
 * 0x02049238, 0x0204B084), one per statically linked object that pulled the
 * small library routine in, and this file only ever reaches the second one.
 * The two extern declarations therefore differ (three registers forwarded
 * there, one used here), which is a property of each call site, not a
 * disagreement about the routine.
 *
 * The one detail that pinned the source: the field at +0x40 is read with a
 * plain `ldr` (word reach, +124) and truncated to u16 afterwards rather than
 * loaded with `ldrh` (reach +62) directly, which only happens when the field
 * itself is declared u32 and truncated at the call, matching
 * docs/idioms/thumb-immediate-reach-costs-an-adds.md's family of reach-driven
 * tells. Declaring it u16 outright produces an extra `adds` to reach the
 * offset and is 4 bytes wrong.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02014CB8.c \
 *       --addr 0x02014CB8 --thumb
 */
void sub_02014CB8(struct Sub02014CB8Obj *o, u32 x)
{
    if (o->f00 == 0) {
        o->f04 = x;
        o->f00 = func_020490F4(x, (u16)o->f40);
    }
}
















void sub_02014CD4(struct Sub02014CB8Obj *o)
{
    if (o->f00 != 0) {
        ENV_SetResourceSet_2(o->f00);
        o->f04 = 0;
        o->f00 = 0;
    }
}















void func_02014CEC(u8 *p, u32 value)
{
    ((struct Obj15658 *)p)->f8 = value;
}

















/*
 * Two consecutive word stores through the object pointer - a plain field
 * pair setter with no prologue, so no label, attested by the pool word
 * 0x02014CF1.  The stores are in source order.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02014CF0.c \
 *       --func sub_02014CF0 --addr 0x02014CF0 --cc 1.1p1 --thumb
 */
void sub_02014CF0(struct Obj02014CF0 *o, int v1, int v2)
{
    ((struct Obj11718 *)o)->f38 = v1;
    ((struct Obj11718 *)o)->f3C = v2;
}
















/*
 * Prepares b (a validation call, func_02016BA0), copies a 0x24-byte record
 * from c into b's field at +0x150 (the inlined ldm/stm loop plus one trailing
 * word is docs/idioms/aggregate-assignment-is-ldm-stm.md), then forwards a,
 * a pointer field of b at +0x148, and the original record pointer c to
 * func_020163C4.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02014CF8.c \
 *       --func sub_02014CF8 --addr 0x02014CF8 --thumb --cc 1.1p1
 */
void sub_02014CF8(void *a, struct Sub02014CF8Ctx *b, const struct Sub02014CF8Rec *c)
{
    func_02016BA0(b);
    b->f150 = *c;
    func_020163C4(a, (u32)b->f148, (const struct Src *)((struct Sub02014CF8Rec *)c));
}
















static inline fx32 FX_MUL(fx32 v1, fx32 v2)
{
    return (fx32)(((fx64)v1 * v2 + 0x800LL) >> 12);
}
















static inline void G3_Translate(fx32 x, fx32 y, fx32 z)
{
    REG_MTX_TRANS = (u32)x;
    REG_MTX_TRANS = (u32)y;
    REG_MTX_TRANS = (u32)z;
}
















static inline void G3_Scale(fx32 x, fx32 y, fx32 z)
{
    REG_MTX_SCALE = (u32)x;
    REG_MTX_SCALE = (u32)y;
    REG_MTX_SCALE = (u32)z;
}
















static inline void G3_LookAt(const VecFx32 *camPos, const VecFx32 *camUp,
                             const VecFx32 *target, MtxFx43 *mtx)
{
    G3i_LookAt_(camPos, camUp, target, 1, mtx);
}















static inline void G3_TexImageParam(GXTexFmt texFmt, GXTexGen texGen, GXTexSizeS s, GXTexSizeT t, GXTexRepeat repeat, GXTexFlip flip, GXTexPlttColor0 pltt0, u32 addr)
{
    REG_TEXIMAGE_PARAM = (u32)((addr >> 3) | (texFmt << 26) | (texGen << 30) | (s << 20) |
                                  (t << 23) | (repeat << 16) | (flip << 18) | (pltt0 << 29));
}















static inline void G3_StoreMtx(int num) { REG_MTX_STORE = (u32)num; }
















/* func_02014D2C is one function over 0x02014D2C..0x020155A0.  The labels
 * func_02014D90 (0x02014D90) and func_02015590 (0x02015590) are not
 * function starts: they are the targets of two long-branch bl pairs inside
 * it (the shared epilogue and the outer loop head). */
/*
 * Verified with:
 *   python tools/match.py tu --src src/matched/func_02014D2C.c \
 *       --addr 0x02014D2C --thumb
 *
 * The mcss.c frame walker, ONE function over 0x02014D2C..0x020155A0
 * (2164 bytes).  0x02014D90 and 0x02015590 are not function starts: they
 * are the targets of two bl instructions the compiler emits as long
 * branches (0x02014D74 to the shared epilogue, 0x0201558C back to the
 * outer loop head), both beyond Thumb b reach.  They are listed on the
 * function line only so the three worklist rows are attested by this one
 * compared range; the integrator may drop them as starts.
 *
 * The lever that closed it (wave 15, from 43 bytes out): the texture
 * parameter write is the SDK inline G3_TexImageParam with the SDK's ENUM
 * parameter types (GXTexFmt, GXTexGen, GXTexSizeS/T, GXTexRepeat,
 * GXTexFlip, GXTexPlttColor0).  With int parameters the inline is 2168
 * bytes (540 out); with a hand-written or-chain 43 out (the STORE constant
 * 0x1e CSE'd with 0x1e << 15).  Enum parameters are materialised as
 * temporaries before the body, which is what keeps 0x1e rematerialised.
 * See docs/idioms/an-enum-type-keeps-values-out-of-constant-folding.md.
 * History: docs/notes/pkt_02014D2C_boundary.c.txt.
 */
void func_02014D2C(struct McssSys_02014910 *sys)
{
    struct Pose pose;
    struct Pose part;
    VecFx32 pos;
    MtxFx44 bb;
    MtxFx43 inv;
    MtxFx33 rot33;
    u32 z;
    s32_02014910 wv;
    struct McssWork_02014910 *w;
    struct AnimCtrl *ctrl;
    int k;
    int idx;
    u16 rot;
    fx32 tx, ty;
    fx32 sx, sy;
    struct TexInfo *tex;
    int i;
    struct Node **nodes;
    u8 flip;
    fx32 c;
    fx32 s;
    int billboard;
    int param;

    func_0206DB80();
    REG_MTX_PUSH = 0;
    REG_MTX_MODE = 0;
    REG_MTX_STORE = 0;
    REG_MTX_MODE = 3;
    REG_MTX_IDENTITY = 0;
    REG_MTX_MODE = 2;
    MTX_Inverse43(&g_02148B98, &inv);
    MI_Copy36B(&inv, &rot33);
    MTX_Copy33To44_(&rot33, &bb);

    i = 0;
    if (sys->count > 0) {
    do {
        if (sys->slots[i] == 0 || sys->slots[i]->b11 != 0 || sys->slots[i]->b13 != 1) {
            continue;
        }
        billboard = 0;
        z = 0;
        if (sys->f2c_0) {
            billboard = sys->slots[i]->b29;
        }
        w = sys->slots[i];
        tex = &w->tex;
        if (billboard == 0) {
            G3_LookAt(&g_02148D8C, &g_02148D98, &g_02148DA4, 0);
        } else {
            VecFx32 camPos = { 0, 0, 0 };
            VecFx32 camUp = d_0209E090;
            VecFx32 camTgt = d_0209E09C;
            G3_LookAt(&camPos, &camUp, &camTgt, 0);
        }
        ctrl = &w->ctrl;
        nodes = &w->nodes;
        switch ((u16)ctrl->seq->type) {
        case 0:
            pose.f00 = *(u16 *)ctrl->cur->content;
            pose.rot = 0;
            pose.sx = 0x1000;
            pose.sy = 0x1000;
            pose.ox = 0;
            pose.oy = 0;
            break;
        case 1:
            pose = *(struct Pose *)ctrl->cur->content;
            break;
        case 2: {
            struct PoseT *t = (struct PoseT *)ctrl->cur->content;
            pose.f00 = t->f00;
            pose.rot = 0;
            pose.sx = 0x1000;
            pose.sy = 0x1000;
            pose.ox = t->ox;
            pose.oy = t->oy;
            break;
        }
        }
        pos.x = w->fe0 + w->f11c;
        pos.y = w->fe4 + w->f120;
        pos.z = w->fe8 + w->f124;
        if (billboard == 0) {
            tx = FX_MUL(pose.ox << 8, sys->f44);
            ty = FX_MUL(-pose.oy << 8, sys->f44);
        } else {
            MtxFx44 m;
            sx = FX_MUL(w->fec, w->f128);
            sy = FX_MUL(w->ff0, w->f12c);
            MTX_Copy43To44_(&g_02148B98, &m);
            MTX_Concat44(&m, &g_02148B54, &m);
            func_02016FC8((const struct VecFx32 *)(&pos), (const struct MtxFx44 *)(&m), (struct VecFx32 *)(&pos), &wv);
            pos.x = FX_MUL(sub_0207C768(pos.x, wv), 0x80000);
            pos.y = FX_MUL(sub_0207C768(pos.y, wv), 0x60000);
            pos.z = -pos.z;
            tx = FX_F32_TO_FX32(pose.ox);
            ty = FX_F32_TO_FX32(-pose.oy);
            tx = FX_MUL(tx, sx / 16);
            ty = FX_MUL(ty, sy / 16);
        }
        G3_Translate(pos.x, pos.y, pos.z);
        if (billboard == 0) {
            G3_MultMtx44(&bb);
        }
        rot = pose.rot + (w->f100 >> 12);
        G3_Translate(tx, ty, 0);
        flip = 0;
        idx = rot >> 4;
        c = FX_SinCosTable_[idx * 2 + 1];
        s = -FX_SinCosTable_[idx * 2];
        G3_RotZ(s, c);
        G3_Scale(FX_MUL(FX_MUL(pose.sx, w->fec), w->f128),
                 FX_MUL(FX_MUL(pose.sy, w->ff0), w->f12c), 0x1000);
        if (w->fec < 0) {
            flip++;
        }
        G3_StoreMtx(29);
        G3_LookAt(&g_02148D8C, &g_02148D98, &g_02148DA4, 0);
        G3_Translate(w->fe0 + w->f11c + w->f17c, w->fe4 + w->f180,
                     w->fe8 + w->f124 + w->f184);
        idx = w->f178 >> 4;
        G3_RotX(FX_SinCosTable_[idx * 2], FX_SinCosTable_[idx * 2 + 1]);
        G3_Translate(FX_MUL(FX_MUL(pose.ox << 8, sys->f44), w->f104),
                     FX_MUL(FX_MUL(-pose.oy << 8, sys->f44), w->f108), 0);
        idx = w->f17a >> 4;
        G3_RotZ(-FX_SinCosTable_[idx * 2], FX_SinCosTable_[idx * 2 + 1]);
        G3_RotZ(s, c);
        G3_Scale(FX_MUL(FX_MUL(FX_MUL(pose.sx, w->f104), w->f110), w->f128),
                 FX_MUL(FX_MUL(FX_MUL(pose.sy, w->f108), w->f114), w->f12c),
                 0x1000);
        G3_StoreMtx(30);
        sub_020169D4();
        G3_TexImageParam(tex->fmt, GX_TEXGEN_TEXCOORD, tex->s, tex->t, GX_TEXREPEAT_ST, GX_TEXFLIP_ST, tex->pltt0, tex->addr);
        for (k = 0; k < w->anim->frames[pose.f00].count; k++) {
            struct Node *node;
            struct Rec_02014910 *rec;
            int id;
            if (w->b0 != 0x1f || w->b30) {
                id = w->anim->frames[pose.f00].count - 1 - k;
            } else {
                id = k;
            }
            node = &(*nodes)[(w->anim->frames[pose.f00].cells[id].f06 & 0xff00) >> 8];
            switch ((u16)node->ctrl.seq->type) {
            case 0:
                part.f00 = *(u16 *)node->ctrl.cur->content;
                part.rot = 0;
                part.sx = 0x1000;
                part.sy = 0x1000;
                part.ox = 0;
                part.oy = 0;
                break;
            case 1:
                part = *(struct Pose *)node->ctrl.cur->content;
                break;
            case 2: {
                struct PoseT *t = (struct PoseT *)node->ctrl.cur->content;
                part.f00 = t->f00;
                part.rot = 0;
                part.sx = 0x1000;
                part.sy = 0x1000;
                part.ox = t->ox;
                part.oy = t->oy;
                break;
            }
            }
            rec = (struct Rec_02014910 *)(w->f2c + 0xc) + part.f00;
            if (rec->q1.w != 0 && w->b30 == 0) {
                if (w->b8) {
                    func_020155A0((struct McssSys_020155A0 *)sys, (struct McssWork_020155A0 *)w, rec->q1.x, rec->q1.y, rec->q1.w, rec->q1.h, rec->q1.s, rec->q1.t + rec->q1.h, &part, &pose.f00, (struct Tex *)(&sys->tex), id, billboard, &z, flip);
                } else {
                    func_020155A0((struct McssSys_020155A0 *)sys, (struct McssWork_020155A0 *)w, rec->q1.x, rec->q1.y, rec->q1.w, rec->q1.h, rec->q1.s, rec->q1.t, &part, &pose.f00, (struct Tex *)(&sys->tex), id, billboard, &z, flip);
                }
            }
            func_020155A0((struct McssSys_020155A0 *)sys, (struct McssWork_020155A0 *)w, rec->q0.x, rec->q0.y, rec->q0.w, rec->q0.h, rec->q0.s, rec->q0.t, &part, &pose.f00, (struct Tex *)(&sys->tex), id, billboard, &z, flip);
            if (rec->q1.w != 0 && w->b30 == 1) {
                if (w->b8) {
                    func_020155A0((struct McssSys_020155A0 *)sys, (struct McssWork_020155A0 *)w, rec->q1.x, rec->q1.y, rec->q1.w, rec->q1.h, rec->q1.s, rec->q1.t + rec->q1.h, &part, &pose.f00, (struct Tex *)(&sys->tex), id, billboard, &z, flip);
                } else {
                    func_020155A0((struct McssSys_020155A0 *)sys, (struct McssWork_020155A0 *)w, rec->q1.x, rec->q1.y, rec->q1.w, rec->q1.h, rec->q1.s, rec->q1.t, &part, &pose.f00, (struct Tex *)(&sys->tex), id, billboard, &z, flip);
                }
            }
        }
    } while (++i < sys->count);
    }
    REG_MTX_POP = 1;
}














/* fx32 texture coordinate to the 12.4 halfword TEXCOORD wants */
#define ST(x) ((u32)(u16)(s16)((x) >> 8))














/*
 * mcss.c's per-cell quad drawer (wave 11, third lane on the family).  Its
 * three callers are the 0x02014D2C..0x020155A0 frame walker (0x020154D0,
 * 0x02015506, 0x02015562), which pass a cell record's six words as
 * x, y, width, height, s, t and a stack record as `pose`.  The body is a
 * straight run of G3 register writes: optional projection, texture palette
 * base, polygon attributes, translate / rotate / scale, one textured quad,
 * then (when the slot is not hidden and alpha is non-zero) the same quad
 * again with polygon id 1, and finally a depth step on *z.
 *
 * FOUR THINGS THE BYTES SETTLED, in the order they were found:
 *  1. FX_SinCosTable_ is declared WITHOUT const.  The second G3_RotZ
 *     re-reads pose->rot and both table entries after the call; const lets
 *     mwcc keep sin/cos across the call in two extra frame slots (0x58
 *     frame against the original's 0x50).  The index is recomputed too.
 *  2. G3_Translate / G3_Scale are the SDK inline functions, not three
 *     plain stores: the original loads pose->sx AND pose->sy (and *z)
 *     before the first register store, which only argument evaluation
 *     produces (58 -> 31 bytes).
 *  3. The second G3_TexPlttBase is written as the SDK's inline expression
 *     `addr >> (4 - (fmt == GX_TEXFMT_PLTT4))`; its 0/1 is a compiler
 *     temporary homed at sp+0x20, the LOWEST slot, which is how the slot
 *     order told a temporary from a declared local.  The alpha value goes
 *     through a block-local `a`, and polyId is declared last: slot order
 *     here follows creation order, not declaration order alone.
 *  4. The depth pointer is `u32 *`, not `fx32 *`.  With a signed pointee
 *     the two +-0x100 tails pick the other register for the 0x140 field
 *     offset the original re-uses to build 0x100 (`subs r0, #0x40`); 22
 *     bytes over four tails that 547 hill and 2000 anneal permuter compiles
 *     could not move, closed by the declaration alone (wave-10 lesson).
 */
void func_020155A0(struct McssSys_020155A0 *sys, struct McssWork_020155A0 *w, fx32 x, fx32 y,
                   fx32 width, fx32 height, fx32 s, fx32 t,
                   struct Pose *pose, u16 *frame, struct Tex *tex, int id,
                   int proj, u32 *z, u8 flip)
{
    u32 alpha;
    fx32 tx, ty;
    u32 st0, st1, st2, st3;
    u32 sa, ta, sb, tb;
    int idx;
    int polyId;

    {
        u32 a = w->b4;
        if (a == 0x20) {
            a = w->b0 >> 1;
        }
        alpha = (u8)a;
    }
    if (w->b0 == 0x1f || w->b31) {
        polyId = 0;
    } else {
        polyId = id;
        if (polyId > 0x3f) {
            polyId = 0x3f;
        }
    }

    if (proj != 0) {
        G3i_FrustumW_(6 << 16, -6 << 16, -8 << 16, 8 << 16, 0x1000,
                      (sys->f2c_1 ? 0x200 : 0x400) << 12, 0x1000, 1, 0);
        REG_MTX_MODE = 2;
    }
    REG_MTX_RESTORE = 0x1d;

    REG_TEXPLTT_BASE = w->fc8 >> (4 - (w->fc0 == 2));
    REG_POLYGON_ATTR = (w->b0 << 16) | (0xc0 | (polyId << 24));

    tx = (w->f78->f04[*frame].f04[id].f02 + pose->ox) << 8;
    ty = -(w->f78->f04[*frame].f04[id].f04 + pose->oy) << 8;
    G3_Translate(tx, ty, *z);
    idx = pose->rot >> 4;
    G3_RotZ(-FX_SinCosTable_[idx * 2], FX_SinCosTable_[idx * 2 + 1]);

    if (flip == 0) {
        G3_Scale(pose->sx, pose->sy, 0x1000);
        G3_Translate(x, y, 0);
        G3_Scale(width, height, 0x1000);
    } else if (flip & 1) {
        G3_Scale(-pose->sx, pose->sy, 0x1000);
        G3_Translate(-x, y, 0);
        G3_Scale(width, height, 0x1000);
        G3_Translate(-0x100, 0, 0);
        s = 0x200000 - s - width;
    }

    REG_BEGIN_VTXS = 1;
    ta = ST(t) << 16;
    sa = ST(s);
    st0 = sa | ta;
    REG_TEXCOORD = st0;
    REG_VTX_16 = 0;
    REG_VTX_16 = 0;
    tb = ST(t + height) << 16;
    st1 = sa | tb;
    REG_TEXCOORD = st1;
    REG_VTX_16 = 0xFF000000;
    REG_VTX_16 = 0;
    sb = ST(s + width);
    st2 = tb | sb;
    REG_TEXCOORD = st2;
    REG_VTX_16 = 0xFF000100;
    REG_VTX_16 = 0;
    st3 = sb | ta;
    REG_TEXCOORD = st3;
    REG_VTX_16 = 0x100;
    REG_VTX_16 = 0;
    REG_END_VTXS = 0;

    REG_MTX_MODE = 0;
    REG_MTX_RESTORE = 0;
    REG_MTX_MODE = 2;
    REG_MTX_RESTORE = 0x1e;

    if (!w->b23 && alpha != 0) {
        REG_TEXPLTT_BASE = tex->plttBase >> (4 - (tex->fmt == 2));
        REG_POLYGON_ATTR = (alpha << 16) | 0x010000C0;
        G3_Translate(tx, ty, 0);
        idx = pose->rot >> 4;
        G3_RotZ(-FX_SinCosTable_[idx * 2], FX_SinCosTable_[idx * 2 + 1]);
        G3_Scale(pose->sx, pose->sy, 0x1000);
        G3_Translate(x, y, 0);
        G3_Scale(width, height, 0x1000);
        REG_BEGIN_VTXS = 1;
        REG_TEXCOORD = st0;
        REG_VTX_16 = 0;
        REG_VTX_16 = 0;
        REG_TEXCOORD = st1;
        REG_VTX_16 = 0xFF000000;
        REG_VTX_16 = 0;
        REG_TEXCOORD = st2;
        REG_VTX_16 = 0xFF000100;
        REG_VTX_16 = 0;
        REG_TEXCOORD = st3;
        REG_VTX_16 = 0x100;
        REG_VTX_16 = 0;
        REG_END_VTXS = 0;
    }

    if (proj == 0) {
        if (sys->f48 == 0) {
            *z -= ((w->b0 != 0x1f) | w->b30) ? -0x100 : 0x100;
        } else {
            *z -= ((w->b0 != 0x1f) | w->b30) ? -sys->f48 : sys->f48;
        }
    } else if (sys->f2c_1) {
        *z -= ((w->b0 != 0x1f) | w->b30) ? -0x100 : 0x100;
    } else {
        *z -= ((w->b0 != 0x1f) | w->b30) ? -0x400 : 0x400;
    }
}
















/*
 * 476 bytes, one function, 29 field stores and no branches but the loop.
 *
 * "Take the first free slot of the module's array, allocate a 0x188 byte
 * record into it, fill it in and hand it back."  The loop walks
 * obj->unk14[0 .. obj->unk10) looking for a NULL entry, and on the first one
 * it allocates, initialises and breaks; the return is obj->unk14[i] either way,
 * so a full array returns the one-past-the-end element, which is the game's
 * behaviour and not a transcription error.
 *
 * ---------------------------------------------------------------------------
 * THE FILE NAME, AND WHAT IT SETTLES
 * ---------------------------------------------------------------------------
 * The allocator call passes 0x020A72CC and 906, which are __FILE__ and
 * __LINE__.  The bytes at 0x020A72CC spell **mcss.c**, so this function and
 * its neighbours in pkt_02014D90 are that original source file, at line 906.
 * The string is attested the ordinary way, seven literal-pool witnesses
 * elsewhere in the image, so it needed no widening of the `string` class; see
 * docs/idioms/file-string-is-an-abs32-into-the-string-area.md for why it is
 * declared as an extern array rather than written `__FILE__`.  The strings on
 * either side of it in the packed area are "field_status.c" and a run of four
 * pointer words, which is the shape
 * docs/idioms/a-string-after-a-data-table-has-no-witness.md warns about for
 * the *next* file name in that area rather than for this one.
 *
 * ---------------------------------------------------------------------------
 * WHAT COST THE TIME
 * ---------------------------------------------------------------------------
 * **The loop bound is the field, not a local.**  `n = obj->unk10;` before the
 * loop and `i < n` inside it compiles to the same 476 bytes with `n` in r1
 * instead of r2, which spills the second parameter one instruction later and
 * leaves nine bytes wrong in the prologue and one at the loop's `cmp`.
 * Written `for (i = 0; i < obj->unk10; i++)` the compiler hoists the load
 * itself, into r2, and the whole function is EXACT.  Nothing in the body reads
 * the field, and the only call inside the loop is on the path that breaks out
 * of it, so the hoist is legal and the original took it.
 *
 * **sizeof is in the source, and it is what pays for the field offsets.**
 * The allocation size arrives as `movs r7, #0x62` / `lsls r7, r7, #2`, which is
 * 0x188, and r7 then stays live for the whole body: every field past the Thumb
 * immediate reach is addressed as `adds r0, r7, #0` / `subs r0, #k` with k the
 * distance back from the end of the record, and the halfword 0xC400 stored at
 * +0x178 is `lsls r2, r7, #7` off the same register.  That only happens if the
 * size the source passes to the allocator is literally `sizeof(struct Rec_020159C8)`
 * and the struct is exactly 0x188 bytes, which makes the declaration
 * self-checking: a struct one word too long or too short changes the constant
 * and every offset derived from it.  The same front end goes on to reuse the
 * constant 0x1F (a bitfield value, parked in `ip`) as the base for the offsets
 * 0x110, 0x114 and 0x118, which is the extreme end of the same behaviour.
 *
 * **Every store reloads the array and the element.**  `obj->unk14[i]->f = v`
 * appears 29 times and the original reloads `obj->unk14` and then
 * `obj->unk14[i]` before each one, because the store it just made could alias
 * either.  Writing the element pointer into a local once, which is what a
 * person would do, removes 28 pairs of loads and is a different function.  The
 * counterpart is docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md:
 * there the qualifier removes the reloads, here its absence is the match.
 *
 * **The 36 byte record at +0x150 is one struct assignment.**  It compiles to a
 * counted `ldm`/`stm` loop of four iterations plus a trailing word, which is
 * docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md; declaring it as a
 * byte array instead gives a `ldrb`/`strb` loop of 36 iterations, so the
 * source's type has at least four byte alignment and `u32 w[9]` is what
 * reproduces it.
 *
 * The word at +0x140 is a bitfield container: the three writes are the low
 * eight bits set to 0x1F, the nine bits at 14 set to 0x20 and bit 11 cleared,
 * and then bit 29 set after the struct copy.  Written as masks and shifts over
 * a plain `u32` the compiler materialises each mask from a literal pool; as
 * bitfields it emits the original's `bics`/`orrs` against the small constants
 * and only the two nine-bit masks reach the pool.
 *
 * Nothing here is version specific: every constant is a structure offset, a
 * fixed-point 1.0 (0x1000), a bitfield value or the source line number.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/sub_020159C8.c  *       --func func_020159C8 --addr 0x020159C8 --cc 1.1p1
 */
struct Rec_020159C8 *func_020159C8(struct Obj_02014910 *obj, u32 a1, u32 a2, u32 a3,
                          const struct Sub150 *src)
{
    s32_02014910 i;

    for (i = 0; i < obj->unk10; i++) {
        if (obj->unk14[i] == 0) {
            obj->unk14[i] = (struct Rec_020159C8 *)func_02030734((u16)obj->unk40,
                                                        sizeof(struct Rec_020159C8), 1,
                                                        func_020159C8_File,
                                                        906);
            obj->unk14[i]->unk148 = i;
            obj->unk14[i]->unk14C = obj->unk40;
            obj->unk14[i]->unk0E0 = a1;
            obj->unk14[i]->unk0E4 = a2;
            obj->unk14[i]->unk0E8 = a3;
            obj->unk14[i]->unk0EC = 0x1000;
            obj->unk14[i]->unk0F0 = 0x1000;
            obj->unk14[i]->unk0F4 = 0x1000;
            obj->unk14[i]->unk11C = 0;
            obj->unk14[i]->unk120 = 0;
            obj->unk14[i]->unk124 = 0;
            obj->unk14[i]->unk128 = 0x1000;
            obj->unk14[i]->unk12C = 0x1000;
            obj->unk14[i]->unk130 = 0x1000;
            obj->unk14[i]->f0 = 0x1F;
            obj->unk14[i]->f4 = 0x20;
            obj->unk14[i]->f2 = 0;
            obj->unk14[i]->unk178 = 0xC400;
            obj->unk14[i]->unk17A = 0;
            obj->unk14[i]->unk17C = 0;
            obj->unk14[i]->unk180 = 0;
            obj->unk14[i]->unk184 = 0xFFFFF000;
            obj->unk14[i]->unk110 = 0x1000;
            obj->unk14[i]->unk114 = 0x1000;
            obj->unk14[i]->unk118 = 0x1000;
            obj->unk14[i]->unk150 = *src;
            obj->unk14[i]->unk174 = 0x1000;
            obj->unk14[i]->f6 = 1;
            func_020163C4((struct Ctx *)obj, i, (const struct Src *)src);
            break;
        }
    }
    return obj->unk14[i];
}














/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02015C1C
 *
 * alias: sub_02015BA4 tears down an object: it calls func_02016BA0(obj), then
 * for each of the three word fields at +0, +4 and +8 that is non-zero it
 * passes that field's *value* (not the object) to a cleanup call
 * (func_02016C0C for +0, func_02016C38 for +4 and +8) and zeroes the field;
 * it then clears a slot this object owns in an array reached through
 * sys->+0x14, indexed by the object's own field at +0x148, and finally
 * hands the object to func_020307B0 through an interworking blx.
 *
 * The four followers are unlabelled leaf accessors on the same class of
 * object, found in the .word run disasm.py left undecoded immediately
 * after sub_02015BA4 (its prologue has no register-saving push that a
 * two-word bit-flag accessor shares); see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md. Two work a
 * flag at +0x2c: sub_02015BF0 clears then re-sets bit 0 (a clear/set pair
 * rather than a plain |=, which is what tells apart the extra bics), and
 * sub_02015C00 only clears it. The other two work a flag at +0x140, too far
 * from the object base for an immediate str, which is why the compiler
 * computes the offset into a register instead of folding it into the
 * instruction: sub_02015C0C sets bit 0x1D (0x20000000) and sub_02015C1C
 * clears it via the pool word 0xDFFFFFFF immediately after it.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02015BA4.c \
 *       --addr 0x02015BA4 --thumb
 */
void sub_02015BA4(void *sys, void *obj)
{
    u32 *p = (u32 *)obj;
    u32 idx;
    u32 *arr;

    func_02016BA0(obj);

    if (p[0] != 0) {
        func_02016C0C((void *)p[0]);
        p[0] = 0;
    }
    if (p[1] != 0) {
        func_02016C38(p[1]);
        p[1] = 0;
    }
    if (p[2] != 0) {
        func_02016C38(p[2]);
        p[2] = 0;
    }

    idx = ((struct Obj02638 *)obj)->f148;
    arr = *(u32 * *)&((struct Obj03429 *)sys)->f14;
    arr[idx] = 0;

    func_020307B0(obj);
}














void sub_02015BF0(void *obj)
{
    ((struct Obj11824 *)obj)->f2C &= ~1;
    ((struct Obj11824 *)obj)->f2C |= 1;
}














void sub_02015C00(void *obj)
{
    ((struct Obj17197 *)obj)->f2C &= ~1;
}














void sub_02015C0C(void *obj)
{
    ((struct Obj17198 *)obj)->f140 |= 0x20000000;
}














void sub_02015C1C(void *obj)
{
    ((struct Obj17199 *)obj)->f140 &= ~0x20000000;
}














/*
 * Unlabelled Thumb leaf in the ARM9 module (saves nothing, so disasm.py emits
 * it as a run of .word). Copies three words out of the structure at +0xE0.
 * The inverse of func_02015C48; in the ov118 event state machine
 * (0x021D7130) it is the out-direction marshaller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015C30(void *p, u32 *out)
{
    out[0] = ((struct Obj08751 *)p)->fE0;
    out[1] = ((struct Obj08751 *)p)->fE4;
    out[2] = ((struct Obj08751 *)p)->fE8;
}














/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words into the
 * structure at +0xE0. The inverse of func_02015C30; in the ov118 event state
 * machine (0x021D7130) and func_021D6E04 it is the in-direction marshaller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015C48(void *p, u32 *src)
{
    ((struct Obj00933 *)p)->fE0 = src[0];
    ((struct Obj00933 *)p)->fE4 = src[1];
    ((struct Obj00933 *)p)->fE8 = src[2];
}














/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words out of +0x11C. Twin of func_02015C78.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015C60(void *p, u32 *out)
{
    out[0] = ((struct Obj08752 *)p)->f11C;
    out[1] = ((struct Obj08752 *)p)->f120;
    out[2] = ((struct Obj08752 *)p)->f124;
}















/*
 * Unlabelled Thumb leaf in the ARM9 module (mcss.c). Copies three words
 * into the structure at +0x11C; same shape as func_02015C48 further
 * back.
 *
 * Addresses are Black-image addresses.
 */
void func_02015C78(void *p, u32 *src)
{
    ((struct Obj08754 *)p)->f11C = src[0];
    ((struct Obj08754 *)p)->f120 = src[1];
    ((struct Obj08754 *)p)->f124 = src[2];
}















/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words out of the
 * structure at +0xEC. The inverse of func_02015CAC; same shape as
 * func_02015C30 one word-group further along.
 *
 * Addresses are Black-image addresses.
 */
void func_02015C94(void *p, u32 *out)
{
    out[0] = ((struct Obj08756 *)p)->fEC;
    out[1] = ((struct Obj08756 *)p)->fF0;
    out[2] = ((struct Obj08756 *)p)->fF4;
}















/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words into the
 * structure at +0xEC. The inverse of func_02015C94.
 *
 * Addresses are Black-image addresses.
 */
void func_02015CAC(void *p, u32 *src)
{
    ((struct Obj00933 *)p)->fEC = src[0];
    ((struct Obj00933 *)p)->fF0 = src[1];
    ((struct Obj00933 *)p)->fF4 = src[2];
}















/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words out of +0x128.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015CC4(void *p, u32 *out)
{
    out[0] = ((struct Obj08757 *)p)->f128;
    out[1] = ((struct Obj08757 *)p)->f12C;
    out[2] = ((struct Obj08757 *)p)->f130;
}















/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words into +0x128. Inverse of func_02015CC4.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015CDC(void *p, u32 *src)
{
    ((struct Obj08759 *)p)->f128 = src[0];
    ((struct Obj08759 *)p)->f12C = src[1];
    ((struct Obj08759 *)p)->f130 = src[2];
}















/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words out of +0xF8.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015CF8(void *p, u32 *out)
{
    out[0] = ((struct Obj08761 *)p)->fF8;
    out[1] = ((struct Obj08761 *)p)->fFC;
    out[2] = ((struct Obj08761 *)p)->f100;
}















/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words into +0xF8. Inverse of func_02015CF8.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015D14(void *p, u32 *src)
{
    ((struct Obj08763 *)p)->fF8 = src[0];
    ((struct Obj08763 *)p)->fFC = src[1];
    ((struct Obj08763 *)p)->f100 = src[2];
}















/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words into +0x104.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015D30(void *p, u32 *src)
{
    ((struct Obj08765 *)p)->f104 = src[0];
    ((struct Obj08765 *)p)->f108 = src[1];
    ((struct Obj08765 *)p)->f10C = src[2];
}















/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words out of +0x110.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015D4C(void *p, u32 *out)
{
    out[0] = ((struct Obj08767 *)p)->f110;
    out[1] = ((struct Obj08767 *)p)->f114;
    out[2] = ((struct Obj08767 *)p)->f118;
}














/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words into +0x110. Inverse of func_02015D4C.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015D64(void *p, u32 *src)
{
    ((struct Obj08769 *)p)->f110 = src[0];
    ((struct Obj08769 *)p)->f114 = src[1];
    ((struct Obj08769 *)p)->f118 = src[2];
}












/*
 * note: halfword setter at +0x178; called from ov131 func_021D785C (bl at
 *   +0x78 and +0xB6) with the pooled full-width value 0xD555.
 */
void func_02015D80(u8 *p, u16 v)
{
    ((struct Obj15659 *)p)->f178 = v;
}


















/*
 * Unlabelled Thumb leaf in the ARM9 module. Stores a halfword at +0x17A.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015D88(char *p, u16 value)
{
    ((struct Obj15660 *)p)->f17A = value;
}



















/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words into +0x17C.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015D94(char *p, int *src)
{
    ((struct Obj08771 *)p)->f17C = src[0];
    ((struct Obj08771 *)p)->f180 = src[1];
    ((struct Obj08771 *)p)->f184 = src[2];
}



















/*
 * Unlabelled Thumb leaf in the ARM9 module. Sets bit 8 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015DB0(void *p)
{
    ((struct Obj15661 *)p)->f140 |= 0x100u;
}



















/*
 * Unlabelled Thumb leaf in the ARM9 module. Clears bit 8 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015DC0(void *p)
{
    ((struct Obj15662 *)p)->f140 &= ~0x100u;
}


















/*
 * Unlabelled Thumb leaf in the ARM9 module. Toggles bit 8 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015DD4(void *p)
{
    ((struct R_02015DD4 *)((char *)p + 0x140))->f ^= 1;
}


















/*
 * Unlabelled Thumb leaf in the ARM9 module. Reads the two-bit field at bits 9..10 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
int func_02015DF8(R_02015DF8 *p)
{
    return p->b;
}


















/*
 * Unlabelled Thumb leaf in the ARM9 module. Compound-OR of the 2-bit
 * bitfield at bits 9..10 of the register at +0x140 with 1. The access is
 * non-volatile in the original: mwcc reads the word once and reinserts the
 * field without a reload (a `volatile` spelling forces a second `ldr` and
 * diverges). Pairs with func_02015E4C, which clears bit 9.
 *
 * Addresses are Black-image addresses.
 */
void func_02015E04(void *p)
{
    ((struct Reg02015Exx *)((char *)p + 0x140))->f |= 1;
}


















/*
 * Unlabelled Thumb leaf in the ARM9 module. Sets bit 10 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015E28(void *p)
{
    ((struct R_02015E28 *)((char *)p + 0x140))->f |= 2;
}


















/*
 * Unlabelled Thumb leaf in the ARM9 module. Compound-AND of the 2-bit
 * bitfield at bits 9..10 of the register at +0x140 with ~1 (clears bit 9).
 * Same non-volatile codegen lever as func_02015E04.
 *
 * Addresses are Black-image addresses.
 */
void func_02015E4C(void *p)
{
    ((struct Reg02015E4C *)((char *)p + 0x140))->f &= ~1u;
}

















/*
 * Unlabelled Thumb leaf in the ARM9 module. Clears bit 10 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015E70(void *p)
{
    ((struct R *)((char *)p + 0x140))->f &= ~2u;
}

















/*
 * Unlabelled Thumb leaf in the ARM9 module. Reads bit 11 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
int func_02015E94(R *p)
{
    return p->b;
}

















/*
 * Unlabelled Thumb leaf in the ARM9 module. Sets bit 11 (0x800) of the
 * 32-bit register at +0x140. Pairs with func_02015EB0, which clears it.
 *
 * Addresses are Black-image addresses.
 */
void func_02015EA0(void *p)
{
    *(volatile u32 *)&((struct Obj15663 *)p)->f140 |= 0x800u;
}

















/*
 * Unlabelled Thumb leaf in the ARM9 module (saves nothing, so disasm.py emits
 * it as a run of .word; the live bytes decode as Thumb). Clears bit 11
 * (0x800) of the 32-bit field at +0x140. This is one of the pair
 * func_02015EA0/func_02015EB0 that set and clear the same bit; it is called
 * from the ov118 event state machine at 0x021D7130 and from
 * func_021D6E04, and is an image-wide-only reference target (no func_ label),
 * so matching it supplies the `matched` witness those callers lack.
 *
 * Addresses are Black-image addresses.
 */
void func_02015EB0(void *p)
{
    *(volatile u32 *)&((struct Obj15664 *)p)->f140 &= 0xFFFFF7FFu;
}

















/*
 * Unlabelled Thumb leaf in the ARM9 module. Toggles bit 11 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015EC4(R *p)
{
    p->b = p->b ^ 1;
}
















/*
 * Unlabelled Thumb leaf in the ARM9 module (mcss.c). Returns the address
 * of the embedded renderer sub-object at +0x34.
 *
 * Addresses are Black-image addresses.
 */
void *func_02015EE8(void *p)
{
    return (char *)p + 0x34;
}

















u16 func_02015EEC(char *p)
{
    return **(u16 * *)&((struct Obj15665 *)p)->f28;
}

















u8 func_02015EF4(char *p)
{
    return **(u8 * *)&((struct Obj15667 *)p)->f30;
}

















u8 func_02015EFC(char *p, u8 i)
{
    return (*(u8 * *)&((struct Obj15669 *)p)->f30 + i)[2];
}

















/*
 * Unlabelled Thumb leaf in the ARM9 module (mcss.c). Reads the u16 at
 * +4 of the table the word at +0x2C points to (`ldrh` proves unsigned).
 * Witness for the call from ov119 func_021E33FC at 0x021E3520.
 */
u16 func_02015F04(void *p)
{
    return (*(u16 **)((char *)p + 0x2C))[2];
}

















/*
 * Unlabelled Thumb leaf in the ARM9 module (mcss.c). Reads the u16 at
 * +6 of the table the word at +0x2C points to (`ldrh` proves unsigned).
 *
 * Addresses are Black-image addresses.
 */
u16 func_02015F0C(void *p)
{
    return (*(u16 **)((char *)p + 0x2C))[3];
}

















/*
 * Unlabelled Thumb leaf in the ARM9 module (mcss.c). Reads the s16 at
 * +8 of the table the word at +0x2C points to (`ldrsh` with a register
 * offset proves signed).
 *
 * Addresses are Black-image addresses.
 */
s16 func_02015F14(void *p)
{
    return (*(s16 **)((char *)p + 0x2C))[4];
}

















/*
 * Unlabelled Thumb leaf in the ARM9 module (mcss.c). Reads the s16 at
 * +0xA of the table the word at +0x2C points to; sibling of
 * func_02015F14.
 *
 * Addresses are Black-image addresses.
 */
s16 func_02015F1C(void *p)
{
    return (*(s16 **)((char *)p + 0x2C))[5];
}

















/*
 * Unlabelled Thumb leaf in the ARM9 module. Reads byte 1 of the record behind the pointer at +0x30.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
u8 func_02015F24(S *s)
{
    return s->p30[1];
}

















/*
 * A pure forwarder: tail-calls func_02063000 on a member 0x34 bytes into
 * the object, with a fixed 1 as the second argument.
 *
 * EXACT* because the 18 compiled bytes fall far short of the disasm.py
 * extent (252 bytes): the packet's next several functions carry no
 * register-saving prologue and disasm.py's extent runs to the following
 * labelled function; they are not matched here.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02015F2C.c \
 *       --func sub_02015F2C --addr 0x02015F2C --cc 1.1p1
 */
void sub_02015F2C(void *a, u32 arg1, u32 arg2)
{
    func_02063000((int)((char *)a + 0x34), 1, arg1, arg2);
}

















void func_02015F40(char *p, unsigned flags, void *callback)
{
    func_02064D70(p + 0x68, callback, flags);
}

















/*
 * Unlabelled Thumb function in the ARM9 module (mcss.c). Starts the
 * +0x134 fade: sets bit 12 of the +0x140 flag word, stores the current
 * and target bytes (+0x134, +0x135), the fifth argument at +0x13C, clears
 * +0x136, splits the signed step into +0x137 and the s32_02014910 step at +0x138
 * (1 - step when negative), and negates the step when the current value
 * is above the target (`cmp r1, r2 / bls`, so both are unsigned bytes).
 *
 * The step is stored as a field in each arm and the negation re-reads the
 * field (the original reloads +0x138 with a fresh `0x4e << 2` base).
 * Written through raw char offsets with the step in a local, mwcc forwards
 * the stored value into the `muls` and colours the 0x140 base into r5;
 * the struct spelling below is byte-exact. `* 0xFFFFFFFF` rather than
 * `-x` is what emits the `mvns`/`muls` pair.
 *
 * Addresses are Black-image addresses.
 */
void func_02015F50(struct McssFade *w, u32 cur, u32 target, s32_02014910 step, u32 e)
{
    w->f140 |= 0x1000;
    w->f134 = cur;
    w->f135 = target;
    w->f13c = e;
    w->f136 = 0;
    if (step < 0) {
        w->f137 = 0;
        w->f138 = -(step - 1);
    } else {
        w->f137 = step;
        w->f138 = 1;
    }
    if (cur > target) {
        w->f138 *= 0xFFFFFFFF;
    }
}












/*
 * Unlabelled Thumb leaf in the ARM9 module. Reads the low byte of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
u8 func_02015FAC(Data_0 *p)
{
    return p->value;
}












/*
 * Unlabelled leaf accessor matched to give overlay call sites a `matched`
 * witness (ov117 func_021D49F4): the low byte of the word at +0x140.
 * Addresses are Black-image addresses.
 */
void func_02015FBC(char *p, int v)
{
    ((struct Obj00933 *)p)->f140 = (((struct Obj00933 *)p)->f140 & ~0xFF) | (unsigned char)v;
}













/*
 * Unlabelled leaf accessor, the follower of func_02015FBC: a 9-bit field at
 * bit 14 of the word at +0x140. Labelled so that func_02015FBC's extent ends
 * at its own bx lr. Addresses are Black-image addresses.
 */
void func_02015FD4(char *p, int v)
{
    ((struct Obj11257 *)p)->f140 = (((struct Obj11257 *)p)->f140 & 0xFF803FFF) | ((v & 0x1FF) << 14);
}













/*
 * Unlabelled leaf accessor matched to give overlay call sites a `matched`
 * witness.  Addresses are Black-image addresses.
 */
void func_02015FF0(char *p, int v)
{
    ((struct Obj00933 *)p)->f140 = (((struct Obj00933 *)p)->f140 & 0xFF7FFFFF) | ((v & 1) << 23);
}













/*
 * Unlabelled Thumb leaf in the ARM9 module (mcss.c). Tests bit 12 of the
 * flag word at +0x140 (the bit func_02015F50 sets). A one-bit bitfield
 * keeps the original's lsls/lsrs pair; a mask would fold to `ands`.
 *
 * Addresses are Black-image addresses.
 */
int func_0201600C(void *p)
{
    if (((struct Flags0201600C *)((char *)p + 0x140))->f) {
        return 1;
    }
    return 0;
}













/*
 * Unlabelled Thumb leaf in the ARM9 module (mcss.c). Stores its second
 * argument into the word at +0x30. Seeded from overlay call sites.
 *
 * Addresses are Black-image addresses.
 */
void func_02016020(void *p, u32 v)
{
    ((struct Obj15670 *)p)->f30 = v;
}












void func_02016024(char *p, unsigned int v)
{
    *(unsigned int *)(p + 52) = v;
}













/*
 * promoted: from src/pending on 2026-09-19, no C change: its blocker is filed,
 *           every relocation site resolves and match.py one reports EXACT*.
 *
 * Reconfigures the object: derives a value from func_020627D8 on field
 * +0x28 and a caller-supplied flag truncated to 16 bits (the explicit
 * lsls/lsrs #0x10 pair in the original is exactly that narrowing cast in
 * the callee, not something the caller is trusted to have done), releases
 * the handle at +0x98 through func_020307B0 if one is set, calls
 * func_02016984(a, 1), passes the derived value into func_0206469C on the
 * member at +0x34, then clears bit 0 of the word at +0x144.
 *
 * Every concrete byte matches; func_02016984 (0x02016984, later in this
 * same packet, not yet matched) is called from exactly this one site in
 * the whole ROM, so that relocation stays unresolved under the honesty
 * rule.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02016028.c \
 *       --func sub_02016028 --addr 0x02016028 --cc 1.1p1
 *
 * The `matched` class does not reach it: func_02016984 is not matched, so
 * no EXACT entry covers that address. Closes to EXACT the day it is
 * matched, or gets a second caller elsewhere in the image.
 */
void sub_02016028(void *a, u32 flag)
{
    u8 *p = (u8 *)a;
    u32 value = (u32)func_020627D8((struct AnimBank *)(((struct Obj02301 *)p)->f28), (u16)flag);

    if (((struct Obj02301 *)p)->f98 != 0) {
        func_020307B0((void *)(((struct Obj02301 *)p)->f98));
    }

    func_02016984(a, 1);
    func_0206469C((struct Obj0206469C *)(p + 0x34), (void *)value);
    ((struct Obj02301 *)p)->f144 &= ~1u;
}












/*
 * Unlabelled Thumb leaf in the ARM9 module. Reads bits 24..27 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
u8 func_02016068(Data_02016068 *p)
{
    return p->value;
}












/*
 * Updates a packed 4-bit mode field at b+0x140 (bits 24-27 of that word;
 * see docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md) if
 * the caller's requested mode (clamped to 15) differs from the current
 * one, then reinitialises through func_02016BA0 and forwards a nested
 * word and struct pointer into func_020163C4. The bitfield pointer is
 * recomputed fresh for the store rather than kept in a local across the
 * clamp branch: the original re-issues the same "5 << 6" multiply instead
 * of reusing the register from the read, the same shape as
 * docs/idioms/keeping-a-cursor-in-a-named-local-costs-a-callee-saved-register.md.
 *
 * EXACT* because the 72 compiled bytes fall short of the disasm.py extent
 * (92 bytes): the extent runs into the next function's own literal pool,
 * not a byte difference.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02016078.c \
 *       --func sub_02016078 --addr 0x02016078 --cc 1.1p1
 */
void sub_02016078(void *a, void *b, int mode)
{
    u8 *pb = (u8 *)b;

    if (((struct Sub02016078Word *)(pb + 0x140))->mode != (u32)mode) {
        if (mode > 15) {
            mode = 15;
        }
        ((struct Sub02016078Word *)(pb + 0x140))->mode = mode;

        func_02016BA0(b);
        func_020163C4(a, ((struct Obj16729 *)pb)->f148, (const struct Src *)(pb + 0x150));
    }
}









void func_020160C0(char *p, unsigned int v)
{
    ((struct Obj15671 *)p)->f44 = v;
}












void func_020160C4(char *p, int v)
{
    ((struct Obj15672 *)p)->f174 = v;
}













/*
 * Unlabelled Thumb leaf in the ARM9 module. Reads the halfword behind the pointer at +0x28.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
u16 func_020160CC(S_0 *s)
{
    return *s->p28;
}













/*
 * mcss.c: builds the per-scene fade/transition context.  Three debug
 * allocations out of the heap named by the u16 at +0x14c (masked to
 * 0x7fff and forced into the 0x8000 bank), then a palette blend and a
 * copy, and finally either a task registration (func_0201691C as the
 * callback, through the owner-aware path or the plain one) or, if the
 * caller has already set the "skip" bit at +0x140, an immediate teardown
 * of everything just allocated.  Either way the done bit 0x10000000 is
 * latched into the same word at +0x140.
 *
 * The three heap ids are recomputed rather than cached: each is a fresh
 * `ldr`+lsls/lsrs of the int field at +0x14c, so the field is an `int`
 * truncated at the call, not a u16 member (see func_02016984 in this
 * same file).  The two __LINE__ pool words 0x761 and 0x769 are the
 * consecutive-line idiom: 0x76e is derived from 0x769 with `adds #5`.
 *
 * Closed in the second pass (2026-09-22) from the 12-byte prologue-spill
 * near miss in docs/notes/func_020160D4.c.txt.  The lever is the THIRD
 * PARAMETER'S TYPE: `u16 a2`, not `int a2`.
 *
 * That note's own list had tried `u16` on a3 (which made it worse, 168
 * bytes) and `u32` on a2, but never `u16` on a2.  tools/permuter.py
 * found it as `type:p(a2:int->u16)` on the 306th compile of a
 * `--mode hill --budget 800 --types` run, taking 12 concrete bytes to 0
 * in one mutation.  A 16-bit parameter arrives already narrowed, so the
 * front end spills it BEFORE it touches the literal pool -- which is
 * exactly the `str r2,[sp,#4]` / `ldr r0,[pc,#0x158]` / `str r3,[sp,#8]`
 * order the note recorded and could not reach.  The note's "untried
 * lever" guess (make a2 reach a call earlier) was not needed.
 *
 * This is also a data point for the family: the value at +0x13C that
 * func_020169E8 hands to func_02021F64 as `(u16)` is 16-bit AT THE
 * PARAMETER here, not only at the call.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_020160D4.c \
 *       --func func_020160D4 --addr 0x020160D4 --cc 1.1p1 --thumb
 */
void func_020160D4(char *a0, char *a1, u16 a2, int a3)
{
    char *o;

    o = (char *)func_02030734(
            (u16)(((u16)((struct Obj01093 *)a1)->f14C & 0x7fff) | 0x8000),
            0x2c, 1, (const char *)data_020A72CC, 0x761);

    *(char * *)&((struct Obj01612 *)o)->f20 = a0;
    ((struct Obj01612 *)o)->f28 = (((struct Obj06864 *)a0)->f8 != 0);
    *(char * *)&((struct Obj01612 *)o)->f24 = a1;
    *(char * *)&((struct Obj01612 *)o)->fC = a1 + 0xc0;
    ((struct Obj01612 *)o)->f1C = ((struct Obj06864 *)a0)->f34 + (((struct Obj01093 *)a1)->f148 << 5);

    *(char * *)&((struct Obj01612 *)o)->f4 = (char *)func_02030734(
            (u16)(((u16)((struct Obj01093 *)a1)->f14C & 0x7fff) | 0x8000),
            0x10, 0, (const char *)data_020A72CC, 0x769);

    **(int * *)&((struct Obj01612 *)o)->f4 = ((struct Obj01093 *)a1)->fC0;
    ((struct Obj15676 *)(*(char * *)&((struct Obj01612 *)o)->f4))->f4 = 0;
    ((struct Obj15677 *)(*(char * *)&((struct Obj01612 *)o)->f4))->f8 = ((struct Obj01093 *)a1)->fDC;
    ((struct Obj15678 *)(*(char * *)&((struct Obj01612 *)o)->f4))->fC = (int)func_02030734(
            (u16)(((u16)((struct Obj01093 *)a1)->f14C & 0x7fff) | 0x8000),
            ((struct Obj01093 *)a1)->fDC, 0, (const char *)data_020A72CC, 0x76e);

    func_02021F64(((struct Obj01093 *)a1)->fD4,
                  ((struct Obj15679 *)(*(char * *)&((struct Obj01612 *)o)->f4))->fC,
                  (u16)(((struct Obj01093 *)a1)->fDC / 2),
                  a2, (u16)a3);
    func_02082A60(((struct Obj15680 *)(*(char * *)&((struct Obj01612 *)o)->f4))->fC,
                  ((struct Obj01093 *)a1)->fD8, ((struct Obj01093 *)a1)->fDC);

    if (((struct Obj01093 *)a1)->f8 != 0) {
        func_02016C38(((struct Obj01093 *)a1)->f8);
        ((struct Obj01093 *)a1)->f8 = 0;
    }

    if (((u32)(((struct Obj01093 *)a1)->f140 << 0x13) >> 0x1f) == 0) {
        if (((struct Obj06864 *)a0)->f8 != 0) {
            ((struct Obj01093 *)a1)->f8 = (int)func_02030DA8((void *)((struct Obj06864 *)a0)->f8,
                                             func_0201691C, o, 0);
        } else {
            ((struct Obj01093 *)a1)->f8 = (int)func_020056A0(func_0201691C, (Sub *)o, 0);
        }
    } else {
        func_020307B0((void *)(((struct Obj15681 *)(*(char * *)&((struct Obj01612 *)o)->f4))->fC));
        func_020307B0((void *)(*(int *)&((struct Obj01612 *)o)->f4));
        func_020307B0((void *)((int)o));
    }

    *(int *)&((struct Obj01093 *)a1)->f140 |= 0x10000000;
}















void func_0201624C(u8 *a0, u8 *a1)
{
    struct Obj_0 *p;
    u32 flag;
    void *ret;

    flag = 1;
    p = (struct Obj_0 *)func_02030734((u16)(((u16)((struct Obj01613 *)a1)->f14C & 0x7FFF) | 0x8000), 0x2C, 1, data_020A72CC, 1942);
    p->f20 = a0;
    if (((struct Obj06865 *)a0)->f8 == 0) {
        flag = 0;
    }
    p->f28 = flag;
    p->f24 = a1;
    p->f0c = a1 + 0xC0;
    p->f1c = ((struct Obj06865 *)a0)->f34 + (((struct Obj01613 *)a1)->f148 << 5);

    flag = 0;
    p->f04 = (struct Inner *)func_02030734((u16)(((u16)*((u32 *)(a1 + 0x148) + 1) & 0x7FFF) | 0x8000), 0x10, 0, data_020A72CC, 1950);
    p->f04->f00 = ((struct Obj01613 *)a1)->fC0;
    p->f04->f04 = flag;
    p->f04->f08 = ((struct Obj01613 *)a1)->fDC;

    p->f04->f0c = func_02030734((u16)(((u16)*((u32 *)(a1 + 0x148) + 1) & 0x7FFF) | 0x8000), ((struct Obj01613 *)a1)->fDC, 0, data_020A72CC, 1950 + 5);
    MIi_CpuCopy16(((struct Obj01613 *)a1)->fD4, p->f04->f0c, ((struct Obj01613 *)a1)->fDC);

    if (((struct Obj01613 *)a1)->f8 != 0) {
        func_02016C38((int)(((struct Obj01613 *)a1)->f8));
        ((struct Obj01613 *)a1)->f8 = (void *)flag;
    }

    if (((struct Obj06865 *)a0)->f8 != 0) {
        ret = func_02030DA8(((struct Obj06865 *)a0)->f8, func_0201691C, p, 0);
    } else {
        ret = func_020056A0(func_0201691C, (Sub *)p, 0);
    }
    ((struct Obj01613 *)a1)->f8 = ret;

    *(u32 *)(a1 + (5 << 6)) &= 0xEFFFFFFF;
}















/*
 * A single matched function.
 *
 * alias: an argument-adjusting tail call: it shifts the object pointer to
 * a member 0x34 bytes in and hands off to func_02064CBC. See
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/unit_02016374.c \
 *       --func sub_02016374 --addr 0x02016374 --cc 1.1p1 --thumb
 */
void sub_02016374(void *obj)
{
    func_02064CBC((struct Obj_0 *)((u8 *)obj + 0x34));
}
















/*
 * Set bit 0 of the word at +0x144: read, clear, set, write back.  The two
 * `movs r1, #1` are the two separate constants of the `& ~1` / `| 1` pair
 * (Thumb has no ORR immediate, so both go through r1).  Entry attested by
 * the pool word 0x02016381 in sub_020173C8's own pool.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02016380.c \
 *       --func sub_02016380 --addr 0x02016380 --cc 1.1p1 --thumb
 */
void sub_02016380(void *o)
{
    u32 v = ((struct Obj11719 *)o)->f144;

    v = v & ~1u;
    v = v | 1u;
    ((struct Obj11719 *)o)->f144 = v;
}















/*
 * Unlabelled Thumb leaf in the ARM9 module. Sets bit 30 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02016394(S_1 *s, int f)
{
    s->f = f;
}















/*
 * Unlabelled Thumb leaf in the ARM9 module. Stores a word at +0x48.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_020163B0(char *p, int v)
{
    ((struct Obj15687 *)p)->f48 = v;
}













/*
 * Unlabelled Thumb leaf in the ARM9 module. Sets bit 1 of the flag word at +0x2C.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_020163B4(Obj_0 *p, int v)
{
    p->b1 = v;
}












/*
 * The mcss.c bind-slot routine (line 0x840).  Closed in wave 15 from 16
 * bytes out by one declaration: the descriptor parameter is
 * const struct Src *.  Without const, the four constructor call sites
 * load a2 for the first argument before the second; with it the image's
 * order (second-argument base first, then the first, then the out
 * pointer copy) comes out.  History: docs/notes/func_020163C4.c.txt.
 */
void func_020163C4(struct Ctx *a0, u32 idx, const struct Src *a2)
{
    u8 *a1 = (u8 *)a0->f14[idx];
    struct Obj_020163C4 *p;
    u32 h;
    u32 flag;
    u32 *q;

    {
        u32 t;
        if (a2->f20 == 1) {
            t = (u16)(((u16)((struct Obj01018 *)a1)->f14C & 0x7FFF) | 0x8000);
        } else {
            t = ((struct Obj01018 *)a1)->f14C;
        }
        h = (u16)t;
    }

    if (a0->f00 != 0 && a0->f04 == a2->f00) {
        func_02016630(a0, idx, a2);
        return;
    }

    *(u32 *)(a1 + (5 << 6)) &= 0xFFFFDFFF;
    func_02063790((u32 *)(a1 + 0x9C));
    func_020637D4((u32 *)(a1 + 0xC0));

    ((struct Obj01018 *)a1)->fC = func_02049FBC(a2->f00, a2->f0c, 0, a1 + 0x10, h);
    ((struct Obj01018 *)a1)->f1C = func_0204A03C(a2->f00, a2->f10, 1, a1 + 0x20, h);
    flag = 1;
    ((struct Obj01018 *)a1)->f14 = func_0204A0BC(a2->f00, a2->f14, 0, a1 + 0x18, h);
    ((struct Obj01018 *)a1)->f24 = func_0204A13C(a2->f00, a2->f18, 0, a1 + 0x28, h);
    sub_02016028(a1, 0);

    q = func_02048F60((u32)a2->f00, (u32)a2->f1c, h);
    *(u32 * *)&((struct Obj01018 *)a1)->f2C = q;
    *(u32 * *)&((struct Obj01018 *)a1)->f30 = (u32 *)((u8 *)q + ((0x30 * q[0] + 0xC) & ~3u));

    p = (struct Obj_020163C4 *)func_02030734((u16)(((u16)*(u32 *)(a1 + (5 << 6) + 0xC) & (0xFFFFDFFFu >> 0x11)) | (flag << 0xF)),
                                    0x2C, 1, data_020A72CC, 0x840);
    p->f20 = a0;
    if (a0->f08 == 0) {
        flag = 0;
    }
    p->f28 = flag;
    p->f08 = a1 + 0x9C;
    p->f0c = a1 + 0xC0;
    p->f18 = a0->f30 + (idx << 0xE);
    p->f1c = a0->f34 + (idx << 5);
    p->f24 = a1;

    p->f10 = func_02049DB4((u32)a2->f00, (u32)a2->f04, 1, (u32)p,
                           (u16)(((u16)((struct Obj01018 *)a1)->f14C & 0x7FFF) | 0x8000));
    p->f14 = func_02049F34((u32)a2->f00, (u32)a2->f08, (u32)(&p->f04),
                           (u16)(((u16)((struct Obj01018 *)a1)->f14C & 0x7FFF) | 0x8000));

    ((struct Obj01018 *)a1)->fD4 = func_02030734(h,
                                          (u32)((struct Src *)p->f04)->f08, 0,
                                          data_020A72CC, 0x858);
    ((struct Obj01018 *)a1)->fD8 = func_02030734(h,
                                          (u32)((struct Src *)p->f04)->f08, 0,
                                          data_020A72CC, 0x858 + 1);
    ((struct Obj01018 *)a1)->fDC = ((struct Src *)p->f04)->f08;
    MIi_CpuCopy16(((struct Src *)p->f04)->f0c, ((struct Obj01018 *)a1)->fD4,
                  (u32)((struct Src *)p->f04)->f08);

    if (a0->f38 != 0) {
        if (a0->f38((void*)a2, p, a0->f3c) == 1) {
            a0->f38 = 0;
            a0->f3c = 0;
        }
    }
    if (((*(u32 *)(a1 + (5 << 6)) << 4) >> 0x1C) != 0) {
        func_02016C60((struct Work *)a1, (struct Task *)p);
    }
    if (a0->f08 != 0) {
        ((struct Obj01018 *)a1)->f0 = func_02030DA8(a0->f08, func_02016880, p, 0);
    } else {
        ((struct Obj01018 *)a1)->f0 = func_020056A0(func_02016880, (Sub *)p, 0);
    }
}











/*
 * The mcss.c rebind routine (line 0x8AB), twin of func_020163C4.  Closed
 * in wave 15 from 21 bytes out by the same declaration: the descriptor
 * parameter is const struct Src *, which fixes the argument load order
 * at every constructor call site.  History:
 * docs/notes/func_02016630.c.txt.
 */
void func_02016630(struct Ctx *a0, u32 idx, const struct Src *a2)
{
    u8 *a1 = (u8 *)a0->f14[idx];
    void *h;
    struct Obj_020160C4 *p;
    u32 flag;
    u32 *q;

    h = a0->f00;
    *(u32 *)(a1 + (5 << 6)) &= 0xFFFFDFFF;
    func_02063790((u32 *)(a1 + 0x9C));
    func_020637D4((u32 *)(a1 + 0xC0));

    ((struct Obj00696 *)a1)->fC = func_02049FFC(h, (u32)(((struct Src *)a2)->f0c), 0,
                                          (u32)((void *)(a1 + 0x10)),
                                          (u16)*(u32 *)(a1 + (5 << 6) + 0xC));
    ((struct Obj00696 *)a1)->f1C = func_0204A07C(h, (u32)a2->f10, 1, (u32)(a1 + 0x20),
                                          (u16)*(u32 *)(a1 + (5 << 6) + 0xC));
    flag = 1;
    ((struct Obj00696 *)a1)->f14 = func_0204A0FC(h, (u32)a2->f14, 0, (u32)(a1 + 0x18),
                                          (u16)*(u32 *)(a1 + (5 << 6) + 0xC));
    ((struct Obj00696 *)a1)->f24 = func_0204A17C(h, (u32)a2->f18, 0, (u32)(a1 + 0x28),
                                          (u16)*(u32 *)(a1 + (5 << 6) + 0xC));
    sub_02016028(a1, 0);

    q = func_02049250(h, (u32)a2->f1c, (u16)*(u32 *)(a1 + (5 << 6) + 0xC));
    *(u32 * *)&((struct Obj00696 *)a1)->f2C = q;
    *(u32 * *)&((struct Obj00696 *)a1)->f30 = (u32 *)((u8 *)q + ((0x30 * q[0] + 0xC) & ~3u));

    p = (struct Obj_020160C4 *)func_02030734((u16)(((u16)*(u32 *)(a1 + (5 << 6) + 0xC) & (0xFFFFDFFFu >> 0x11)) | (flag << 0xF)),
                                    0x2C, 1, data_020A72CC, 0x8AB);
    p->f20 = a0;
    if (a0->f08 == 0) {
        flag = 0;
    }
    p->f28 = flag;
    p->f08 = a1 + 0x9C;
    p->f0c = a1 + 0xC0;
    p->f18 = a0->f30 + (idx << 0xE);
    p->f1c = a0->f34 + (idx << 5);
    p->f24 = a1;

    p->f10 = func_02049DF4(h, (u32)a2->f04, 1, (u32)p,
                           (u16)(((u16)((struct Obj00696 *)a1)->f14C & 0x7FFF) | 0x8000));
    p->f14 = func_02049F78(h, (u32)a2->f08, (u32)(&p->f04),
                           (u16)(((u16)((struct Obj00696 *)a1)->f14C & 0x7FFF) | 0x8000));

    ((struct Obj00696 *)a1)->fD4 = func_02030734((u16)((struct Obj00696 *)a1)->f14C,
                                          (u32)((struct Src *)p->f04)->f08, 0,
                                          data_020A72CC, 0x8C3);
    ((struct Obj00696 *)a1)->fD8 = func_02030734((u16)((struct Obj00696 *)a1)->f14C,
                                          (u32)((struct Src *)p->f04)->f08, 0,
                                          data_020A72CC, 0x8C3 + 1);
    ((struct Obj00696 *)a1)->fDC = ((struct Src *)p->f04)->f08;
    MIi_CpuCopy16(((struct Src *)p->f04)->f0c, ((struct Obj00696 *)a1)->fD4,
                  (u32)((struct Src *)p->f04)->f08);

    if (a0->f38 != 0) {
        if (a0->f38((void *)a2, p, a0->f3c) == 1) {
            a0->f38 = 0;
            a0->f3c = 0;
        }
    }
    if (((*(u32 *)(a1 + (5 << 6)) << 4) >> 0x1C) != 0) {
        func_02016C60((struct Work *)a1, (struct Task *)p);
    }
    if (a0->f08 != 0) {
        ((struct Obj00696 *)a1)->f0 = func_02030DA8(a0->f08, func_02016880, p, 0);
    } else {
        ((struct Obj00696 *)a1)->f0 = func_020056A0(func_02016880, (Sub *)p, 0);
    }
}










void func_02016880(void *a0, struct Obj_02016880 *a1)
{
    if (a1->f28 == 0) {
        u32 v = *(volatile u16 *)0x04000006;

        if (v < 0xc0 || v > 0xc8)
            return;
    }
    if (a1->f10 != 0) {
        func_02063A54(a1->f00, a1->f18, 0, (struct Out *)a1->f08);
        sub_020307B0(a1->f10);
        if (((a1->f24[0x140 / 4] << 4) >> 0x1c) == 0) {
            a1->f10 = 0;
            return;
        }
    }
    if (a1->f24 != 0)
        a1->f24[0x140 / 4] |= 0x2000;
    if (a1->f14 != 0) {
        func_02063E54(a1->f04, a1->f1c, 0, a1->f0c);
        sub_020307B0(a1->f14);
    }
    if (a1->f24 != 0)
        a1->f24[0] = 0;
    if (a1->f20 != 0 && a1->f20->f0c != 0)
        a1->f20->f0c = 0;
    sub_020307B0(a1);
    sub_02030EAC(a0);
}











void func_0201691C(void *a0, struct Obj_0201691C *a1)
{
    if (a1->f28 == 0) {
        u32 v = *(volatile u16 *)0x04000006;

        if (v < 0xc0 || v > 0xc8)
            return;
    }
    func_020637D4(a1->f0c);
    func_02063E54(a1->f04, a1->f1c, 0, (u32)a1->f0c);
    if (a1->f24 != 0) {
        if (a1->f24->f04 == a0)
            a1->f24->f04 = 0;
        if (a1->f24->f08 == a0)
            a1->f24->f08 = 0;
    }
    sub_020307B0(((struct Obj04_0201691C *)a1->f04)->f0c);
    sub_020307B0(a1->f04);
    sub_020307B0(a1);
    sub_02030EAC(a0);
}










/*
 * A two-call registrar.  The first call is five arguments wide: the value
 * loaded from +0x14c is an `int` truncated to `u16` at the call (the listing
 * shows `ldr` + the lsls/lsrs 0x10 pair, not a `ldrh` - declaring the field
 * itself `u16` is what produces a `ldrh` and loses four bytes), and 0x970 is
 * the fifth argument on the stack.  The result is stored back into +0x98,
 * which the second call reads as its own second argument, so the field is a
 * genuine `int`.
 *
 * The pool word at 0x020169D0 is 0x020A72CC; that same word sits in eight
 * other functions' pools in this image (0x02014B9C, 0x02015B94, 0x02016240,
 * 0x02016360, 0x02016624, 0x02016870, 0x02016B84, ...), all outside the
 * compared range, which is what attests the site through the `literal` class.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02016984.c \
 *       --func func_02016984 --addr 0x02016984 --cc 1.1p1 --thumb
 */
void func_02016984(char *a0, int a1)
{
    *(int *)&((struct Obj02301 *)a0)->f98 = (int)func_02030734((unsigned short)((struct Obj02301 *)a0)->f14C,
                                        func_020648B4(((struct Obj02301 *)a0)->f18, a1),
                                        0, data_020A72CC, 0x970);
    func_02064754((char *)((int)(a0 + 0x34)), (char *)(*(int *)&((struct Obj02301 *)a0)->f98), (void *)(((struct Obj02301 *)a0)->f20),
                  ((struct Obj02301 *)a0)->f10, (void *)(((struct Obj02301 *)a0)->f18), a1);
}










/*
 * A single matched function.
 *
 * alias: a direct write of a fixed 32-bit value to a hardware register pair
 * at 0x040004C0: the low word gets the full constant, the high word (at
 * +4) gets its upper halfword. This is a raw I/O register store, not an
 * SDK call, which is why it is game code sitting on hardware address space.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/unit_020169D4.c \
 *       --func sub_020169D4 --addr 0x020169D4 --cc 1.1p1 --thumb
 */
void sub_020169D4(void)
{
    u32 v = 0x4210FFFF;
    *(volatile u32 *)0x040004C0 = v;
    *(volatile u32 *)0x040004C4 = v >> 16;
}










/*
 * Closed in the second pass (2026-09-22) from the 4-byte near miss in
 * docs/notes/func_020169E8.c.txt.  The residue was NOT the pool-word
 * shape that note predicted; it was two misreadings of the image:
 *
 *   1. the flag mask is 0xFFFFEFFF (bit 12), not 0xEFFFFFFF (bit 28).
 *      The pool word at 0x02016B94 is `ff ef ff ff`.  Fixing it alone
 *      took the diff from 4 concrete bytes to 2.
 *   2. the second clamp reads +0x135 / +0x134, not +0x137 / +0x136.
 *      The `ldr r0,[pc,#0x3c]` at 0x02016B58 resolves to 0x02016B98,
 *      the SECOND pool word (0x135), while the `ldr r0,[pc,#0x30]` at
 *      0x02016B6A resolves to 0x02016B9C, the THIRD (0x137).  Reading
 *      both as 0x137 is what made the 0x135 pool word disappear and the
 *      function come out 436 bytes instead of 440.  The missing pool
 *      word was a symptom, not the cause.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_020169E8.c \
 *       --func func_020169E8 --addr 0x020169E8 --cc 1.1p1 --thumb
 */
void func_020169E8(u8 *a0, u8 *a1)
{
    struct Obj *p;
    u32 flag;
    void *ret;
    s32_02014910 step;
    s8 cur;
    s8 tgt;

    if (((struct Obj00353 *)a1)->f136 != 0) {
        goto dec;
    }

    flag = 1;
    p = (struct Obj *)func_02030734((u16)(((u16)((struct Obj00353 *)a1)->f14C & 0x7FFF) | 0x8000), 0x2C, 1, data_020A72CC, 0x9A1);
    p->f20 = a0;
    if (((struct Obj01459 *)a0)->f8 == 0) {
        flag = 0;
    }
    p->f28 = flag;
    p->f24 = a1;
    p->f0c = a1 + 0xC0;
    p->f1c = ((struct Obj01459 *)a0)->f34 + (((struct Obj00353 *)a1)->f148 << 5);

    flag = 0;
    p->f04 = (struct Inner *)func_02030734((u16)(((u16)((struct Obj00353 *)a1)->f14C & 0x7FFF) | 0x8000), 0x10, 0, data_020A72CC, 0x9A9);
    p->f04->f00 = ((struct Obj00353 *)a1)->fC0;
    p->f04->f04 = flag;
    p->f04->f08 = ((struct Obj00353 *)a1)->fDC;
    p->f04->f0c = func_02030734((u16)(((u16)((struct Obj00353 *)a1)->f14C & 0x7FFF) | 0x8000), ((struct Obj00353 *)a1)->fDC, 0, data_020A72CC, 0x9A9 + 5);

    if ((((struct Obj00353 *)a1)->f140 << 3) >> 0x1F) {
        func_02021F64((int)(((struct Obj00353 *)a1)->fD8), (int)p->f04->f0c, ((s32_02014910)((struct Obj00353 *)a1)->fDC / 2), *(u8 *)&((struct Obj00353 *)a1)->f134, (u16)((struct Obj00353 *)a1)->f13C);
    } else {
        func_02021F64((int)(((struct Obj00353 *)a1)->fD4), (int)p->f04->f0c, ((s32_02014910)((struct Obj00353 *)a1)->fDC / 2), *(u8 *)&((struct Obj00353 *)a1)->f134, (u16)((struct Obj00353 *)a1)->f13C);
    }

    if (((struct Obj00353 *)a1)->f4 != 0) {
        func_02016C38((int)(((struct Obj00353 *)a1)->f4));
        ((struct Obj00353 *)a1)->f4 = 0;
    }

    if (((struct Obj01459 *)a0)->f8 != 0) {
        ret = func_02030DA8(((struct Obj01459 *)a0)->f8, func_0201691C, p, 0);
    } else {
        ret = func_020056A0(func_0201691C, (Sub *)p, 0);
    }
    ((struct Obj00353 *)a1)->f4 = ret;

    cur = ((struct Obj00353 *)a1)->f134;
    tgt = ((struct Obj00353 *)a1)->f135;
    if (cur == tgt) {
        ((struct Obj00353 *)a1)->f140 &= 0xFFFFEFFF;
    } else {
        step = ((struct Obj00353 *)a1)->f138;
        ((struct Obj00353 *)a1)->f134 = (s8)(cur + (s8)step);
        if (step < 0 || ((struct Obj00353 *)a1)->f134 < tgt) {
            if (step < 0) {
                tgt = ((struct Obj00353 *)a1)->f135;
                if (((struct Obj00353 *)a1)->f134 > tgt) {
                    goto done;
                }
            } else {
                goto done;
            }
        }
        ((struct Obj00353 *)a1)->f134 = tgt;
    }
done:
    ((struct Obj00353 *)a1)->f136 = ((struct Obj00353 *)a1)->f137;
    return;
dec:
    ((struct Obj00353 *)a1)->f136 = ((struct Obj00353 *)a1)->f136 - 1;
}










/*
 * A whole translation unit, matched as one byte range.
 *
 * alias: a teardown chain on the same object class as unit_02015BA4.c.
 * sub_02016BA0 releases eight pointer fields of the object through
 * func_020307B0 (a generic release call reached by blx, so it is ARM),
 * zeroes three of them (+0x98, +0xd4, +0xd8, all past the immediate str
 * reach so the compiler adds the offset into a register first), then
 * zeroes the other four (+0xc, +0x1c, +0x14, +0x24, +0x2c) and, if the
 * object's own field at +0 is non-zero, recurses into sub_02016C0C with
 * that field's value before zeroing it too. sub_02016C0C turns an id into
 * an object through func_02030EE8, releases one or two of the object's own
 * pointer fields the same way, releases the object itself, and finally
 * releases the id through func_02030EAC.
 *
 * The immediate follower, sub_02016C38 (38 bytes, same shape over a third
 * field, one level of extra indirection), is a documented near miss: this
 * front end assigns it only two callee-saved registers (padding a filler
 * into r3) where the original spends three (r4, r5, r6), so the second
 * fetch of the inner pointer is a register move here and a reload from
 * memory in every source shape tried. Left out rather than forced.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02016BA0.c \
 *       --addr 0x02016BA0 --thumb
 */
void sub_02016BA0(void *obj)
{
    u8 *o = (u8 *)obj;

    func_020307B0(((struct Obj01104 *)o)->fC);
    func_020307B0(((struct Obj01104 *)o)->f1C);
    func_020307B0(((struct Obj01104 *)o)->f14);
    func_020307B0(((struct Obj01104 *)o)->f24);
    func_020307B0(((struct Obj01104 *)o)->f98);
    func_020307B0(((struct Obj01104 *)o)->f2C);
    func_020307B0(((struct Obj01104 *)o)->fD4);
    func_020307B0(((struct Obj01104 *)o)->fD8);

    ((struct Obj01104 *)o)->f98 = 0;
    ((struct Obj01104 *)o)->fD4 = 0;
    ((struct Obj01104 *)o)->fD8 = 0;

    {
        void *v = ((struct Obj01104 *)o)->f0;
        ((struct Obj01104 *)o)->fC = 0;
        ((struct Obj01104 *)o)->f1C = 0;
        ((struct Obj01104 *)o)->f14 = 0;
        ((struct Obj01104 *)o)->f24 = 0;
        ((struct Obj01104 *)o)->f2C = 0;
        if (v != 0) {
            func_02016C0C(v);
            ((struct Obj01104 *)o)->f0 = 0;
        }
    }
}










void sub_02016C0C(void *id)
{
    void *obj = (void *)func_02030EE8(id);

    if (((struct Obj07131 *)obj)->f10 != 0) {
        func_020307B0(((struct Obj07131 *)obj)->f10);
    }
    if (((struct Obj07131 *)obj)->f14 != 0) {
        func_020307B0(((struct Obj07131 *)obj)->f14);
    }
    func_020307B0(obj);
    func_02030EAC(id);
}













void func_02016C38(int a0)
{
    u32 t0 = func_02030EE8((struct S02030EE8 *)a0);
    func_020307B0((void *)*(int *)((char *)((struct Obj11258 *)t0)->f4 + 12));
    func_020307B0((void *)((struct Obj11258 *)t0)->f4);
    func_020307B0((void *)t0);
    func_02030EAC((struct Node *)a0);
}












/*
 * mcss.c, the two-pass nibble fill over a0->f2c's 0x30-byte records.
 * EXACT* (870 bytes; the 872-byte listing extent carries 2 pad bytes).
 * Closed in wave 21 (lane B2) from 16 bytes out.  The lever is w2: it is
 * read raw into the guard (`w2 = R->f2c; if (w2 != 0)`) and shifted
 * later (`w2 >>= 12;`), and the pass-2 header follows pass 1's order,
 * sx2, sy2, w2, h2, then `i2 = 0; y = 0;`.  The raw w2 web spans the
 * sx2/sy2 reads and is coloured before the record pointer, which puts
 * the pointer in r1 and both zeros in r0, as the image has them.
 * History: docs/notes/pkt_02016C60.c.txt.
 */
void func_02016C60(struct Work *a0, struct Task *a1)
{
  s32_02014910 scale;
  u8 *base;
  s32_02014910 k;
  s32_02014910 sx;
  s32_02014910 sy;
  s32_02014910 w;
  s32_02014910 h;
  s32_02014910 step;
  s32_02014910 nib;
  s32_02014910 found;
  s32_02014910 x;
  s32_02014910 y;
  s32_02014910 i;
  s32_02014910 j;
  s32_02014910 sx2;
  s32_02014910 sy2;
  s32_02014910 w2;
  s32_02014910 h2;
  s32_02014910 i2;
  s32_02014910 j2;
  s32_02014910 bw;
  s32_02014910 bh;
  s32_02014910 r;
  s32_02014910 c;
  s32_02014910 addr;
  s32_02014910 t;
  s32_02014910 v;
  s32_02014910 tmp1;
  s32_02014910 tmp2;
  s32_02014910 tmp3;
  s32_02014910 tmp4;
  s32_02014910 tmp5;
  s32_02014910 tmp8;
  s32_02014910 tmp10;
  if (a0->fb0 != 3)
  {
    return;
  }
  scale = _d2s(func_0209AB80(2.0, _s32_to_double(a0->fa8 + 2)));
  base = a1->f00[5];
  k = 0;
  while (((u32) k) < ((u32) a0->f2c[0]))
  {
    sx = ((struct Rec *) (((u8 *) a0->f2c) + (k * 0x30)))->f1c >> 12;
    sy = ((struct Rec *) (((u8 *) a0->f2c) + (k * 0x30)))->f20 >> 12;
    w = ((struct Rec *) (((u8 *) a0->f2c) + (k * 0x30)))->f14 >> 12;
    h = ((struct Rec *) (((u8 *) a0->f2c) + (k * 0x30)))->f18 >> 12;
    step = ((s32_02014910) ((a0->f140 << 4) >> 0x1c)) + 1;
    i = 0;
    y = 0;
    if (h > 0)
    {
      do
      {
        for (j = 0, x = 0; x < w; j++, x += step)
        {
          {
            s32_02014910 hi;
            if ((x + step) > w)
            {
              bw = w - (step * j);
            }
            else
            {
              bw = step;
            }
            if ((y + step) > h)
            {
              bh = h - (step * i);
            }
            else
            {
              bh = step;
            }
            found = 0;
            for (r = 0; r < bh; r++)
            {
              for (c = 0; c < bw; c++)
              {
                t = (sx + x) + c;
                tmp3 = (sy + y) + r;
                addr = (t / 2) + (tmp3 * scale);
                if (c & 1)
                {
                  v = (base[addr] & 0xf0) >> 4;
                }
                else
                {
                  v = base[addr] & 0x0f;
                }
                if (v != 0)
                {
                  found = v;
                  break;
                }
              }

              if (found != 0)
              {
                break;
              }
            }

            nib = (u8) found;
            hi = nib << 4;
            for (r = 0; r < bh; r++)
            {
              for (c = 0; c < bw; c++)
              {
                tmp10 = sx + x;
                t = tmp10 + c;
                tmp4 = sy + y;
                tmp1 = tmp4 + r;
                addr = (t / 2) + (tmp1 * scale);
                if (addr < (1 << 14))
                {
                  if (t & 1)
                  {
                    base[addr] = (base[addr] & 0x0f) | hi;
                  }
                  else
                  {
                    base[addr] = (base[addr] & 0xf0) | nib;
                  }
                }
              }

            }

          }
        }

        i++;
        y += step;
      }
      while (y < h);
    }
    w2 = ((struct Rec *) (((u8 *) a0->f2c) + (k * 0x30)))->f2c;
    if (w2 != 0)
    {
      sx2 = ((struct Rec *) (((u8 *) a0->f2c) + (k * 0x30)))->f34 >> 12;
      sy2 = ((struct Rec *) (((u8 *) a0->f2c) + (k * 0x30)))->f38 >> 12;
      w2 >>= 12;
      h2 = (((struct Rec *) (((u8 *) a0->f2c) + (k * 0x30)))->f30 >> 12) << 1;
      i2 = 0;
      y = 0;
      if (h2 > 0)
      {
        do
        {
          for (j2 = 0, x = 0; x < w2; j2++, x += step)
          {
            {
              s32_02014910 hi2;
              if ((x + step) > w2)
              {
                bw = w2 - (step * j2);
              }
              else
              {
                bw = step;
              }
              if ((y + step) > h2)
              {
                bh = h2 - (step * i2);
              }
              else
              {
                bh = step;
              }
              found = 0;
              for (r = 0; r < bh; r++)
              {
                for (c = 0; c < bw; c++)
                {
                  t = (sx2 + x) + c;
                  tmp8 = (sy2 + y) + r;
                  addr = (t / 2) + (tmp8 * scale);
                  if (c & 1)
                  {
                    v = (base[addr] & 0xf0) >> 4;
                  }
                  else
                  {
                    v = base[addr] & 0x0f;
                  }
                  if (v != 0)
                  {
                    found = v;
                    break;
                  }
                }

                if (found != 0)
                {
                  break;
                }
              }

              nib = (u8) found;
              hi2 = nib << 4;
              for (r = 0; r < bh; r++)
              {
                for (c = 0; c < bw; c++)
                {
                  t = sx2 + x;
                  t = t + c;
                  tmp5 = sy2 + y;
                  tmp2 = tmp5 + r;
                  addr = (t / 2) + (tmp2 * scale);
                  if (addr < (1 << 14))
                  {
                    if (t & 1)
                    {
                      base[addr] = (base[addr] & 0x0f) | hi2;
                    }
                    else
                    {
                      base[addr] = (base[addr] & 0xf0) | nib;
                    }
                  }
                }

              }

            }
          }

          i2++;
          y += step;
        }
        while (y < h2);
      }
    }
    k++;
  }

}









/*
 * 310 bytes, one function, and two bytes of linker fill after it before the
 * next function at 0x02017100; the range this entry owns is 0x02016FC8 plus
 * 310, which is why it is written as a unit rather than as a single function
 * entry (`match.py one` measures the extent to the next label, sees 312 and
 * reports EXACT* over two bytes the compiler never emitted).
 *
 * The 4x4 fixed-point transform of a three-component vector: the ordinary
 * Nitro row-vector convention, out = v * M with the translation row added
 * afterwards, computed in 64 bit and shifted back down by the 12 fractional
 * bits at the end of each component.  The fourth component does not go into
 * the destination vector; it is written through a separate `s32_02014910 *`, which is
 * what makes this the projection form rather than MTX_MultVec: the caller
 * gets x, y, z and w separately and divides by w itself.
 *
 *   dst->x = (s32_02014910)((vx * m[0][0] + vy * m[1][0] + vz * m[2][0]) >> 12)
 *            + m[3][0];        and the same for columns 1, 2 and 3
 *
 * Every product is a call to the compiler's 64 bit multiply helper at
 * 0x0209C054, twelve of them, and the `asrs rN, rM, #0x1f` in front of each
 * operand is the sign extension an `s32_02014910` costs on the way to `long long`; see
 * docs/idioms/consecutive-ll-udiv-calls-are-one-chained-64-bit-expression.md
 * for the same family of helpers seen from the division side.  The name the
 * relocation carries is `_ll_mul`, not `_ull_mul`: both spellings name the
 * same routine at 0x0209C054 (`umull` plus two `mla` is correct for either
 * signedness), and which one mwccarm emits follows the signedness of the
 * operands, so `src/matched/unit_020056A0.c` pins the same address under the
 * other name.  The helper's contract is r0:r1 and r2:r3 in, r0:r1 out.
 *
 * The 64 bit shift is not a call.  `lsls r0, rHi, #0x14` / `lsrs r1, rLo, #0xc`
 * / `orrs r1, r0` is the low word of a `>> 12` on a 64 bit value with the high
 * word dead, which is what the cast back to `s32_02014910` makes of it; the shift of
 * the low half is `lsrs` and not `asrs` whatever the sign of the value,
 * because it is a bit-field splice and not an arithmetic shift.
 *
 * ---------------------------------------------------------------------------
 * WHAT COST THE TIME
 * ---------------------------------------------------------------------------
 * **The shifted product needs a named local, or the translation row is loaded
 * ten bytes too early.**  Written as one expression,
 *
 *     dst->x = (s32_02014910)((...) >> 12) + mtx->m[3][0];
 *
 * the compiler loads `mtx->m[3][0]` before the last two adds of the 64 bit
 * accumulation, which then needs two register copies to get the helper's
 * result out of r0:r1; the function grows twelve bytes and 248 concrete bytes
 * differ, all of them scheduling.  Splitting the statement,
 *
 *     r = (s32_02014910)((...) >> 12);
 *     dst->x = r + mtx->m[3][0];
 *
 * is EXACT.  Holding the 64 bit sum in an `s64` local instead and casting at
 * the store is byte-identical, so the image does not say which of the two the
 * source wrote, only that it was not one expression.
 *
 * **The three vector components are read into locals, and the sign extension
 * is what they are read for.**  `v` is `const` and `dst` is not, so a store
 * through `dst` may alias `v`; written as `v->x` inside all twelve products
 * the compiler reloads and re-extends each component for every output and
 * comes out four bytes short with the whole body rescheduled.  Three `s32_02014910`
 * locals assigned at the top make the six words of sign-extended vector one
 * CSE that lives on the stack at sp+4 through sp+0x18 for the whole function,
 * which is the original's frame.  The same three values held as `s64` locals
 * are twelve bytes longer, so the source's locals are 32 bit and the cast is
 * at the multiply.
 *
 * Nothing here is version specific: every constant is a matrix offset or the
 * fixed-point shift.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_02016FC8.c  *       --addr 0x02016FC8 --thumb
 */
void func_02016FC8(const struct VecFx32 *v, const struct MtxFx44 *mtx,
                   struct VecFx32 *dst, s32_02014910 *w)
{
    s32_02014910 vx;
    s32_02014910 vy;
    s32_02014910 vz;
    s32_02014910 r;

    vx = v->x;
    vy = v->y;
    vz = v->z;

    r = (s32_02014910)(((s64)vx * mtx->m[0][0] + (s64)vy * mtx->m[1][0]
                    + (s64)vz * mtx->m[2][0]) >> 12);
    dst->x = r + mtx->m[3][0];
    r = (s32_02014910)(((s64)vx * mtx->m[0][1] + (s64)vy * mtx->m[1][1]
                    + (s64)vz * mtx->m[2][1]) >> 12);
    dst->y = r + mtx->m[3][1];
    r = (s32_02014910)(((s64)vx * mtx->m[0][2] + (s64)vy * mtx->m[1][2]
                    + (s64)vz * mtx->m[2][2]) >> 12);
    dst->z = r + mtx->m[3][2];
    r = (s32_02014910)(((s64)vx * mtx->m[0][3] + (s64)vy * mtx->m[1][3]
                    + (s64)vz * mtx->m[2][3]) >> 12);
    *w = r + mtx->m[3][3];
}










/*
 * The first of two parallel fillers of the same nine word record.
 * func_02017168 builds it from the five values func_02017114 reads out of the
 * save block and writes 0 into the last word; its twin at 0x02017214 builds
 * the same record from a pair of pointers and writes 1, so that word is the
 * tag saying which of the two produced it.  The twin is parked in
 * src/pending/unit_02017214.c: it is the only caller of six of its eight
 * callees.
 *
 * func_02017100 passes its first argument through func_020185F4 rather than
 * holding it in a callee-saved register, which is only possible because that
 * function returns its argument: it is the two byte `bx lr` at 0x020185F4 that
 * src/matched/unit_020185F0.c matches as an empty hook.  Written as a void
 * call followed by func_02017114(p, ...) the first argument would have to be
 * saved across it and the function grows a register.
 */
void func_02017100(void *p, struct Stats *out, u32 lvl)
{
    func_02017114(func_020185F4(p), out, lvl);
}








void func_02017114(void *p, struct Stats *out, u32 lvl)
{
    u32 a0 = func_02017E88(p, 5, 0);
    u32 a1 = func_02017E88(p, 0x6F, 0);
    u32 a2 = func_02017E88(p, 0x6E, 0);
    u32 a3 = func_02017EB4(p);
    u32 a4 = func_02017E88(p, 0x4C, 0);

    func_02017168(a0, a1, a2, a3, a4, out, lvl);
}








void func_02017168(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, struct Stats *out,
                   u32 a6)
{
    out->unk00 = func_0202D060();
    out->unk04 = func_0202D09C(out->unk00, a0, a1, a2, a3, a6, a4);
    out->unk08 = func_0202D0D4(out->unk00, a0, a1, a2, a3, a6, a4);
    out->unk0C = func_0202D110(out->unk00, a0, a1, a2, a3, a6, a4);
    out->unk10 = func_0202D144(out->unk00, a0, a1, a2, a3, a6, a4);
    out->unk14 = func_0202D178(out->unk00, a0, a1, a2, a3, a6, a4);
    out->unk18 = func_0202D1AC(out->unk00, a0, a1, a2, a3, a6, a4);
    out->unk1C = func_0202D1E0(out->unk00, a0, a1, a2, a3, a6, a4);
    out->unk20 = 0;
}









/*
 * Promoted from src/pending/ during a shard verify sweep: all six of its
 * previously witness-less callees (func_0202D5F8, func_0202D640,
 * func_0202D664, func_0202D688, func_0202D6AC, func_0202D6D0) are now
 * EXACT matched entries elsewhere in the tree, so the `matched` class
 * resolves every site that was stuck wildcarded and this closes to
 * EXACT with no change to the C.
 *
 * This is the twin of func_02017168 in src/matched/unit_02017100.c: the
 * same nine word record, built from a pair of pointers instead of from
 * five save block fields, with 1 in the last word where the other
 * writes 0.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02017214.c \
 *       --addr 0x02017214 --thumb
 */
void func_02017214(void *p, struct Stats *out, void *q)
{
    out->unk00 = func_0202D5CC((u32)q);
    out->unk04 = func_0202D5F8((u32)p, (u32)q);
    out->unk08 = func_0202D61C((u32)p, (u32)q);
    out->unk0C = func_0202D640((u32)p, (u32)q);
    out->unk10 = func_0202D664((u32)p, (u32)q);
    out->unk14 = func_0202D688((u32)p, (u32)q);
    out->unk18 = func_0202D6AC((u32)p, (u32)q);
    out->unk1C = func_0202D6D0((u32)p, (u32)q);
    out->unk20 = 1;
}









/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02017270.c \
 *       --func func_02017270 --addr 0x02017270 --cc 1.1p1 --thumb
 */
void *func_02017270(void *a0, void *a1, u32 a2, u32 a3, u32 a4, u32 a5)
{
    u8 buf[0x24];

    func_020172AC((int)a0, func_02017E1C(a1, 0, 0));
    func_02017100(a1, (struct Stats *)buf, a2);
    return (struct Rec *)func_020159C8((struct Obj_02014910 *)a0, a3, a4, a5, (const struct Sub150 *)buf);
}









/*
 * A four-instruction tail call: the second argument is replaced by a function
 * pointer (the pool word 0x020172BD, the Thumb bit set), the first and third
 * pass through, and the target is loaded from the pool and branched to with
 * `bx r3`.  The callee is the label-less Thumb leaf src/matched/sub_02014CF0.c.
 *
 * The `symbols:` line is load-bearing.  Without it the name `func_02014CF0`
 * carries the address but the naming convention can only guess the ISA, and
 * an address no `func_` label was traced at is guessed ARM -- so the site
 * was reported as "02014CF0 (arm, from name) has no witness" and the file sat
 * at MATCH, because sub_02014CF0 is a Thumb manifest entry and the `matched`
 * class refuses an ISA that does not agree with it.  Declaring the ISA
 * explicitly (origin "header") resolves the word to 0x02014CF1, which is what
 * the image holds.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020172AC.c \
 *       --func func_020172AC --addr 0x020172AC --cc 1.1p1 --thumb
 */
void func_020172AC(int a0, int a1)
{
    sub_02014CF0((struct Obj02014CF0 *)a0, (int)func_020172BC, a1);
}










/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020172BC.c \
 *       --func func_020172BC --addr 0x020172BC --cc 1.1p1 --thumb
 */
u32 func_020172BC(u8 *a0, u8 **a1, u32 a2)
{
    if (((struct Obj15713 *)a0)->f1C == 0x1994) {
        func_020172D8((u8 *)(((struct Obj15715 *)(*a1))->f14), a2);
    }
    return 1;
}










/*
 * mcss.c.  Walks four (x, y) offset lists and bumps the matching nibble of
 * two bytes per point.  Lever (wave 16): the read-modify-write of a0[p] is a
 * compound assignment `a0[p] += 0x50` / `a0[p] += 5`; the spelled-out
 * `a0[p] = (u8)(val + 0x50)` left a three-register rotation (a0/k/b0, 47
 * bytes out) that no declaration order, scope, type or permuter run moved.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020172D8.c \
 *       --func func_020172D8 --addr 0x020172D8 --cc 1.1p1 --thumb
 */
void func_020172D8(u8 *a0, u32 a1)
{
    const u8 *cur;
    s32_02014910 i;
    s32_02014910 n;
    s32_02014910 d[2];

    for (i = 0; i < 4; i++) {
        cur = sMcssTable[i];
        n = 0;
        if (cur[0] != 0xff) {
            d[1] = (a1 & 0xf) - 8;
            d[0] = ((a1 & 0xf0) >> 4) - 8;
            do {
                u8 b0 = (u8)(d[1] + cur[n * 2]);
                u32 b1 = (u8)(d[0] + cur[n * 2 + 1]);
                u32 idx[2];
                s32_02014910 k;
                idx[0] = ((u32)b0 >> 1) + (b1 << 7);
                idx[1] = ((u32)b0 >> 1) + ((b1 + 0x28) << 7);
                for (k = 0; k < 2; k++) {
                    if ((b0 & 1) != 0) {
                        u32 p = idx[k];
                        u8 val = a0[p];
                        s32_02014910 v = val & 0xf0;
                        if (v >= 0x10 && v <= 0x30) {
                            a0[p] += 0x50;
                        }
                    } else {
                        u32 p = idx[k];
                        u8 val = a0[p];
                        s32_02014910 v = 0xf & val;
                        if (v >= 1 && v <= 3) {
                            a0[p] += 5;
                        }
                    }
                }
                n = (u8)(n + 1);
            } while (cur[n * 2] != 0xff);
        }
        a1 = a1 >> 8;
    }
}








int func_020173B4(int a0){ int t0 = func_02015F2C((int)a0, (int)(a0 + 0), (int)0x20173C9, (int)1); return t0; }







/*
 * A four-byte tail call: the pool word 0x02016381 (Thumb) is loaded and
 * `bx r3` jumps with the incoming r0 untouched, i.e. sub_02016380 itself.
 * Its witness is the EXACT entry for 0x02016380 in this same shard - the
 * `matched` class - which is what makes the pool word resolve.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020173C8.c \
 *       --func sub_020173C8 --addr 0x020173C8 --cc 1.1p1 --thumb
 */
void sub_020173C8(void *o)
{
    sub_02016380(o);
}







void func_020173D0(u32 heap)
{
    func_0201AD88(heap);
    *(unsigned short *)(g_02146270 + 2) = 0x28b;
}








/*
 * The two record sizes this region's files open with, `movs r0, #imm; bx lr`,
 * neither of them labelled in the generated listing because neither saves lr.
 * 0xDC is exactly what func_02017528 in src/matched/unit_02017528.c clears and
 * 0x88 exactly what func_02017550 clears, so the two constants and the struct
 * declaration check each other.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * The three functions in front of them are parked in
 * src/pending/unit_020173B4.c.
 *
 * The original file name of the two constructors after them is recoverable
 * even though neither is matched yet: func_020173F0 and func_02017430 both
 * pass 0x020A72E4 to the debug allocator at 0x02030734, and the bytes there
 * spell "poke_tool.c".  Its left neighbours in the packed string area are
 * "d_status.c" at 0x020A72C0 and "mcss.c" at 0x020A72CC, and between "mcss.c"
 * and it sit four pointer words at 0x020A72D4, so the `string` class cannot
 * reach it (docs/idioms/a-string-after-a-data-table-has-no-witness.md).  The
 * `literal` class can: two pool words name it, 0x0201742C and 0x02017478, so
 * a range holding exactly one of the two constructors attests it.  Neither is
 * matched here because each is in turn the only caller of its worker.
 */
u32 func_020173E8(void)
{
    return 0x88;
}








u32 func_020173EC(void)
{
    return 0xDC;
}








/*
 * Allocate a record (0xA0 is the __LINE__ passed to func_02030734 with the
 * poke_tool.c __FILE__ anchor) and initialise it through func_0201756C.
 * Wave 11, 2026-09-23.  The "one remaining codegen wall" of
 * docs/families/poke_tool.h section 11 was a declaration error: the id is a
 * single u64 in r2:r3, not two u32s.  A u64 parameter gets a memory home at
 * entry and is reloaded at the call, which is exactly the str/ldr pair the
 * earlier passes could not force.
 */
void *func_020173F0(u16 species, u16 level, u64 id, u16 heap)
{
    void *v = func_02030734(heap, func_020173EC(), 1, (const char *)&sPokeToolFile, 0xa0);
    if (v != 0) {
        func_0201756C(v, species, level, id);
    }
    return v;
}








/*
 * Allocate a record (line 0xBA) and initialise it through func_02017588,
 * forwarding the u64 id, the packed IVs `pow` and the u64 personality
 * `rnd`; the heap id (u16, `ldrh`) is the LAST parameter, after rnd.
 * Wave 11, 2026-09-23: closed by the u64 id/rnd declarations (see
 * func_020173F0.c).
 */
void *func_02017430(u16 species, u16 level, u64 id, u32 pow, u64 rnd, u16 heap)
{
    void *v = func_02030734(heap, func_020173EC(), 1, (const char *)&sPokeToolFile, 0xba);
    if (v != 0) {
        func_02017588((struct Pokemon *)v, species, level, id, pow, rnd);
    }
    return v;
}










/*
 * "Clone this Pokemon into a fresh allocation on heap `heap`."
 *
 * It takes the block lock (func_02017DBC), reads species (id 0x05), level
 * (id 0x9E) and OT id (id 0x07) -- all three through the block-lock getter
 * func_02017E88, and species and level truncated to u16 at the assignment,
 * which is what the two `lsls #0x10 / lsrs #0x10` pairs at +0x18 and +0x26
 * are -- builds a fresh record with func_020173F0(species, level, otId, 0,
 * heap), releases the lock, copies the WHOLE 0x88-word record over the fresh
 * one, then zeroes the three party-area ids the clone must not inherit
 * (0x9D, 0xA0 current HP, 0xA1 max HP), attaches a fresh mail block and
 * recomputes the stats.
 *
 * THE ONE LEVER, and the whole residue of the first draft:
 *
 *   THE RECORD COPY IS A STRUCT ASSIGNMENT, NOT A HAND-WRITTEN WORD LOOP.
 *
 * The original's copy is
 *
 *     020174C8  adds r3, r4, #0
 *     020174CA  movs r2, #0x11
 *     020174CC  ldm r5!, {r0, r1}
 *     020174CE  stm r3!, {r0, r1}
 *     020174D0  subs r2, r2, #1
 *     020174D2  bne #0x20174cc
 *
 * i.e. 0x11 iterations of an eight-byte ldm/stm pair, which is exactly
 * docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md: above the unroll
 * threshold mwcc turns a whole-struct assignment into a counted ldm/stm loop
 * whose step is the struct's alignment.  Writing the same copy as an explicit
 * `d[0] = s[0]; d[1] = s[1]; s += 2; d += 2;` loop compiles to four separate
 * `ldr`/`str` plus two pointer bumps -- eight bytes longer and the whole tail
 * shifted (the first draft was 180 bytes against 172, with everything up to
 * +0x4C already byte-identical).  Only the aggregate assignment reaches it.
 *
 * The copy is 0x22 words = 0x88 bytes, NOT the record's full 0xDC: it copies
 * the plaintext header and the 0x80-byte masked block area and stops at the
 * party area, which is what the three explicit zeroes that follow then
 * rebuild.  That is why `struct Pokemon` here is declared as 0x22 words and not
 * as docs/families/poke_tool.h's full record -- the declared size IS the
 * evidence, since it is what sets the loop's trip count to 0x11.
 *
 * The heap tag handed to func_02008F08 is `(heap & 0x7fff) | 0x8000`: the pool
 * word at 0x02017524 is 0x00007FFF and the original derives the OR mask from
 * it with `adds r0, r0, #1` rather than pooling 0x8000 separately
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md).
 *
 * Nothing here is version specific: 0x05, 0x07, 0x9D, 0x9E, 0xA0, 0xA1 and
 * 0xA7 are all field selectors.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/func_0201747C.c \
 *       --func func_0201747C --addr 0x0201747C --cc 1.1p1 --thumb
 */
void *func_0201747C(struct Mon_0 *p, u16 heap)
{
    u32 t = func_02017DBC((struct Pokemon *)p);
    u16 species = (u16)func_02017E88(p, 5, 0);
    u16 level = (u16)func_02017E88(p, 0x9e, 0);
    u32 otId = func_02017E88(p, 7, 0);
    void *q = func_020173F0(species, level, otId, heap);
    void *m;

    func_02017DE4((struct Pokemon *)p, t);

    *(struct Mon_0 *)q = *p;

    func_02017E40(q, 0x9d, 0);
    func_02017E40(q, 0xa0, 0);
    func_02017E40(q, 0xa1, 0);
    m = func_02008F08((u16)((heap & 0x7fff) | 0x8000));
    func_02017E40(q, 0xa7, (u32)m);
    func_020307B0(m);
    func_020185C4(q);
    return q;
}






/*
 * The two clears of the 0xDC byte record src/matched/unit_02017D30.c and
 * src/matched/unit_02018D10.c work on: func_02017528 wipes the whole of it and
 * re-masks both areas, func_02017550 wipes only the first 0x88 bytes and
 * re-masks the 0x80 byte one.  The masking calls are what say the record's
 * seed word and checksum halfword survive a clear in the caller's copy: the
 * value handed to func_02019A50 is read back out of the object *after*
 * MIi_CpuClearFast has zeroed it, so both areas are masked with zero and the
 * call is the identity.
 *
 * The range stops at 0x0201756C.  That function and its twin at 0x02017600
 * are five argument entry points to eight argument workers, passing
 * 0xFFFFFFFF, 0 and 0xFFFFFFFF for the three arguments they do not take, and
 * neither reproduces: the original spends a third callee-saved register on
 * the incoming fifth argument and stores it into the outgoing frame last,
 * after all three constants, while every forwarding spelling tried loads it
 * first and reuses one register for it and for the zero.  Eighteen bytes, all
 * of them register numbers and store order.
 */
void func_02017528(struct Pokemon *p)
{
    MIi_CpuClearFast(0, p, sizeof(struct Pokemon));
    func_02019A50((u16 *)p->unk08, 0x80, p->unk06);
    func_02019A50((u16 *)&p->unk88, 0x54, p->unk00);
}





void func_02017550(struct Pokemon *p)
{
    MIi_CpuClearFast(0, p, 0x88);
    func_02019A50((u16 *)p->unk08, 0x80, p->unk06);
}







/*
 * Forwarder: func_02017588(obj, species, level, id, 0xFFFFFFFF,
 * 0xFFFFFFFF00000000) -- random IVs, random personality.  Wave 11,
 * 2026-09-23: the u64 `id` straddles r3 and the first stack word; declaring
 * it u64 is the whole fix for the 18-byte prologue residue (push {r4,r5,r6}
 * and the late `ldr r6,[sp,#0x20]`).
 */
void func_0201756C(void *obj, u16 species, u16 level, u64 id)
{
    func_02017588(obj, species, level, id, 0xFFFFFFFF, 0xFFFFFFFF00000000ULL);
}







/*
 * Build a full party record: clear it (func_02017528), initialise the block
 * area (func_0201761C), mask the party area with seed 0 then with the PID,
 * write the level (id 0x9E) through the party-lock setter, attach a fresh
 * mail block (tag 0x8000, id 0xA7, then freed), and refresh the stats
 * (func_020185C4).  Wave 11, 2026-09-23.  EXACT* only because the listing
 * extent includes the two alignment bytes at 0x020175FE.
 */
void func_02017588(struct Pokemon *p, u16 species, u16 level, u64 id, u32 pow, u64 rnd)
{
    void *mail;

    func_02017528((struct Pokemon *)p);
    func_0201761C(p, species, level, id, pow, rnd);
    func_02019A50((u16 *)&p->unk88, 0x54, 0);
    func_02019A50((u16 *)&p->unk88, 0x54, p->unk00);
    func_02017E40(p, 0x9e, level);
    mail = func_02008F08(0x8000);
    func_02017E40(p, 0xa7, (u32)mail);
    func_020307B0(mail);
    func_020185C4(p);
}






/*
 * Forwarder: func_0201761C(obj, species, level, id, 0xFFFFFFFF,
 * 0xFFFFFFFF00000000).  Twin of func_0201756C; wave 11, 2026-09-23, closed
 * by the u64 `id` parameter.
 */
void func_02017600(void *obj, u16 species, u16 level, u64 id)
{
    func_0201761C(obj, species, level, id, 0xFFFFFFFF, 0xFFFFFFFF00000000ULL);
}






/*
 * Initialise a record's block area: species, level, a 64-bit trainer id and
 * a 64-bit personality with two sentinel values each, and packed IVs (or
 * 0xFFFFFFFF for six fresh draws).  Wave 11, 2026-09-23.  The levers
 * that closed it after 2026-09-21's 612-against-700 DIFF:
 *   - the 4th parameter is a u64 `id` straddling r3 and the first stack
 *     word; the 7th is a u64 `rnd`.  Sentinels: id == ~0 (draw a fresh one),
 *     id == 0xFFFFFFFF00000000 (search for a non-shiny id: the
 *     func_02017ED8 retry loop, `id = (u32)(rnd + 1)` then
 *     `id = (id + 1) & 0xFFFFFFFF`); rnd == 0xFFFFFFFF00000000 (draw),
 *     rnd == 0xFFFFFFFF00000001 (take id).  Callers 0x0201756C/0x02017600
 *     pass pow = -1, rnd = 0xFFFFFFFF00000000.
 *   - the IV draws are `(u64)func_0203F0A8() * 32 >> 32`
 *     (docs/idioms/random-below-n-is-a-64-bit-multiply-high.md).
 *   - func_02017550 takes `obj` (it is unit_02017528.c's area clear).  The
 *     last ten prologue bytes (r1 vs r0 as the scratch for the stack-param
 *     home rewrite) came from that alone: r0 must survive to the call.
 *     The permuter (hill 800 + anneal 1000, --types) could not move them.
 *     gNameBuf (passed by address), as docs/families/poke_tool.h says.
 */
void func_0201761C(void *obj, u16 species, u16 level, u64 id, u32 pow, u64 rnd)
{
    void *rec;
    u32 flag;
    u32 v;

    func_02017550((struct Pokemon *)obj);
    flag = func_02017DBC((struct Pokemon *)obj);
    rec = func_02019C54(species, 0);

    if (rnd == 0xFFFFFFFF00000000ULL) {
        rnd = func_020056EC(0);
        func_0203F0A8();
    } else if (rnd == 0xFFFFFFFF00000001ULL) {
        rnd = id;
    }
    func_02017E64(obj, 0, (u32)rnd);

    if (id == 0xFFFFFFFFFFFFFFFFULL) {
        id = func_020056EC(0);
    } else if (id == 0xFFFFFFFF00000000ULL) {
        id = (u32)(rnd + 1);
        while (func_02017ED8((u32)id, (u32)rnd)) {
            id = (id + 1) & 0xFFFFFFFF;
        }
    }
    func_02017E64(obj, 7, (u32)id);
    func_02017E64(obj, 0xc, g0209DF0C);
    func_02017E64(obj, 5, species);
    func_02045F5C(gMsgBank, species, gNameBuf, 0x20);
    func_02017E64(obj, 0x74, (u32)gNameBuf);
    func_02017E64(obj, 8, func_02018584(species, 0, level));
    func_02017E64(obj, 9, func_0201AE1C(rec, 0x16));
    func_02017E64(obj, 0x99, level);
    func_02017E64(obj, 0x77, g0209DF08);
    func_02017E64(obj, 0x98, 4);

    if (pow == 0xFFFFFFFF) {
        func_02017E64(obj, 0x46, (u32)(((u64)func_0203F0A8() * 32) >> 32));
        func_02017E64(obj, 0x47, (u32)(((u64)func_0203F0A8() * 32) >> 32));
        func_02017E64(obj, 0x48, (u32)(((u64)func_0203F0A8() * 32) >> 32));
        func_02017E64(obj, 0x4a, (u32)(((u64)func_0203F0A8() * 32) >> 32));
        func_02017E64(obj, 0x4b, (u32)(((u64)func_0203F0A8() * 32) >> 32));
        func_02017E64(obj, 0x49, (u32)(((u64)func_0203F0A8() * 32) >> 32));
    } else {
        func_02017E64(obj, 0x46, (u8)(pow & 0x1f));
        func_02017E64(obj, 0x47, (u8)((pow >> 5) & 0x1f));
        func_02017E64(obj, 0x48, (u8)((pow >> 10) & 0x1f));
        func_02017E64(obj, 0x4a, (u8)((pow >> 15) & 0x1f));
        func_02017E64(obj, 0x4b, (u8)((pow >> 20) & 0x1f));
        func_02017E64(obj, 0x49, (u8)((pow >> 25) & 0x1f));
    }

    v = 0x1a;
    if (func_02019C7C(rec) == 2 && (rnd & 0x10000) != 0) {
        v = 0x1b;
    }
    func_02017E64(obj, 0xa, func_0201AE1C(rec, v));
    func_02017E64(obj, 0x6e, func_02017F08(obj));
    func_02017E64(obj, 0x70, func_020056EC(0x19));
    func_02017FB0(obj);
    func_02017DE4((struct Pokemon *)obj, flag);
}






/*
 * Verified with:
 *   python tools/match.py one --src src/pending/func_020178D8.c \
 *       --func func_020178D8 --addr 0x020178D8 --cc 1.1p1 --thumb
 */
void func_020178D8(void *p, u32 a)
{
    u8 v = (u8)func_02017D30((struct Pokemon *)p);

    func_02017900(p, a);
    func_020185C4(p);
    func_02017D70((struct Pokemon *)p, v);
}







/*
 * poke_tool.c: "change this record's species to a1".  It takes the block
 * lock, reads the current species (id 5) and does nothing at all when it
 * already matches.  Otherwise it touches id 0x6F for its side effect, reads
 * the "nickname is not the default" bit (id 0x75), writes the new species,
 * refreshes the two derived type fields through func_02017C50 and
 * func_02017CC8, and -- only when the nickname was still the default -- also
 * renders the new species' name into the shared buffer at 0x021462F0 and
 * stores it back as id 0x74.  Then it releases the lock.
 *
 * The id 0x75 guard is what makes this correct game behaviour: a record the
 * player has renamed keeps its nickname across a species change, and one that
 * never was renamed follows the species.  func_02019ABC (unit_02019ABC.c) is
 * what sets that bit, and func_02018E34 reads it back as id 0x75.
 *
 * WHAT WAS WRONG IN THE EARLIER NOTE, AND WHAT CLOSED IT
 * -----------------------------------------------------
 * docs/notes/func_02017900.diff.c.txt records this as a DIFF and its skeleton
 * is correct in every structural respect -- the guard, the nested 0x75 test,
 * the call order.  Only the extern declarations are wrong, and in exactly the
 * same way as its sibling src/matched/func_02017B4C.c, which the same note
 * file pairs it with.
 *
 * The note declares the accessors narrow (`u8 func_02017DBC`, `u16
 * func_02017E88`).  With the callee declared narrow the compiler emits no
 * truncation at all and then spills the live values to the frame.  The
 * original truncates at the ASSIGNMENT with a `lsls`/`lsrs` pair and keeps
 * both narrowed values in callee-saved registers.  That shape needs the
 * callee declared returning a full word and the LOCAL declared narrow, so the
 * cast belongs to the source rather than to the callee.  Declaring
 * func_02017DBC and func_02017E88 u32 and keeping `u8 v` / `u16 w` is the
 * entire fix; the body is the note's, unchanged.
 *
 * This is docs/families/poke_tool.h's adjudication rule: a truncation at the
 * call constrains the callee's width, a truncation at the assignment
 * constrains the local's.  Every other matched file in the family
 * (unit_02017E64.c, unit_0201854C.c, unit_02018430.c) already declares
 * func_02017E88 returning u32, so the note's spelling was the outlier.
 *
 * The third argument of func_02017E64 is a plain u32, not a `void *`: ids 5
 * and 0x74 take an integer and a buffer address respectively, and spelling
 * the parameter as a pointer is a claim the bytes do not make.
 *
 * Nothing here is version specific: 5, 0x6F, 0x74 and 0x75 are field
 * selectors and 0x20 is a halfword count.  g_020A7370 and g_021462F0 are
 * globals, so their addresses are build properties and must be re-derived
 * for a White build rather than copied.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02017900.c \
 *       --func func_02017900 --addr 0x02017900 --cc 1.1p1 --thumb
 */
u32 func_02017900(void *a0, u32 a1)
{
    u8  v = (u8)func_02017DBC((struct Pokemon *)a0);
    u16 w = (u16)func_02017E88(a0, 5, 0);

    if (w != a1) {
        u32 x;

        func_02017E88(a0, 0x6f, 0);
        x = func_02017E88(a0, 0x75, 0);
        func_02017E64(a0, 5, a1);
        func_02017C50((int)a0, a1, w);
        func_02017CC8(a0, (void *)a1, (void *)w);
        if (x == 0) {
            func_02045F5C(g_020A7370, a1, (u16 *)g_021462F0, 0x20);
            func_02017E64(a0, 0x74, (u32)g_021462F0);
        }
    }
    return func_02017DE4((struct Pokemon *)a0, v);
}







/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02017988.c \
 *       --func func_02017988 --addr 0x02017988 --cc 1.1p1 --thumb
 */
u32 func_02017988(void *p, u32 a)
{
    u8 v = (u8)func_02017D30((struct Pokemon *)p);
    u32 r = func_020179B8((int)p, a);

    if (r == 1) {
        func_020185C4(p);
    }
    func_02017D70((struct Pokemon *)p, v);
    return r;
}







/*
 * A "select and apply" pair, structurally the sibling of func_02017900.
 * The value at selector 5 is compared against a1; when they already agree
 * nothing but the +0x18 restore happens.  Otherwise the old selection is read
 * back out of selector 0x6f into r4 (the local that was 0, which is why the
 * clearing write passes r4 and not a literal 0) and the new value is written
 * with selector 0x6f before the two geometry calls run with it.
 *
 * The `cmp` operand order is the tell: `(u16)func_02017E88(...)` only reaches
 * cmp's left slot because it was first bound to a named local (`t`), see
 * docs/idioms/cmp-operand-order-names-the-temporary.md.  Comparing the call
 * result directly emits `cmp a1, r0` and differs by one byte.
 *
 * EXACT*: the compared extent ran into the follower's four-byte pad, which is
 * identical in both objects.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020179B8.c \
 *       --func func_020179B8 --addr 0x020179B8 --cc 1.1p1 --thumb
 */
int func_020179B8(int a0, int a1)
{
    int r4 = 0;
    int r7 = (unsigned char)func_02017DBC((struct Pokemon *)a0);
    int t = (unsigned short)func_02017E88((void *)a0, 0x6f, 0);

    if (t != a1) {
        func_02017E88((void *)a0, 0x6f, r4);
        r4 = (unsigned short)func_02017E88((void *)a0, 5, r4);
        func_02017E64((void *)a0, 0x6f, a1);
        func_02017C50(a0, r4, r4);
        func_02017CC8((void *)a0, (void *)r4, (void *)r4);
        r4 = 1;
    }
    func_02017DE4((struct Pokemon *)a0, r7);
    return r4;
}







/*
 * Species check (id 5 == 0x1DF), then teach the move tbl[idx] from a
 * six-entry u16 table {0, 0x13B, 0x38, 0x3B, 0x193, 0x1B5} at 0x0209E298:
 * any slot already holding one of tbl[1..5] is overwritten (first hit) or
 * deleted (func_02017BC8, then the slot is re-examined), else the first
 * empty slot, else slot `val`; slot 0 empty gets move 0x54; finally
 * func_02017988(p, idx).  Wave 11, 2026-09-23.
 *
 * The straight-line six ldrh/strh copy with TWO `add rN, sp, #8` is a
 * 12-byte, 2-aligned aggregate copy scoped AFTER the guard: in the original
 * very likely a local initializer `u16 tbl[6] = {...}` inside a block (that
 * spelling is byte-identical but its anonymous rodata symbol cannot be named
 * in `symbols:`), written here as the equivalent struct copy from a named
 * extern so the relocation resolves (sole-ref).  Also load-bearing: `v` and
 * `val` are u32, so the (u16)/(u8) truncations land at the func_020181F4
 * calls; `k` is unsigned (`blo`), `i` signed (`blt`); `r != 0 && r ==
 * tbl.v[k]` is the inner test.
 */
u32 func_02017A20(void *p, u32 idx, u32 val)
{
    u32 v;
    int i;
    u32 k;

    if (func_02017E1C(p, 5, 0) != 0x1df)
        return 0;
    {
    struct MoveTbl tbl = sMoveTbl;
    v = tbl.v[idx];
    for (i = 0; i < 4; i++) {
        u32 r = func_02017E1C(p, i + 0x36, 0);

        for (k = 1; k < 6; k++) {
            if (r != 0 && r == tbl.v[k]) {
                if (v != 0) {
                    func_020181F4(p, v, (u8)i);
                    v = 0;
                } else {
                    func_02017BC8(p, i);
                    i--;
                }
                break;
            }
        }
    }
    }
    if (v != 0) {
        for (i = 0; i < 4; i++) {
            if (func_02017E1C(p, i + 0x36, 0) == 0) {
                func_020181F4(p, v, (u8)i);
                break;
            }
        }
        if (i == 4)
            func_020181F4(p, v, (u8)val);
    }
    if (func_02017E1C(p, 0x36, 0) == 0)
        func_020181F4(p, 0x54, (u8)0);
    func_02017988(p, (u16)idx);
    return 1;
}







/*
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02017B24.c \
 *       --func func_02017B24 --addr 0x02017B24 --cc 1.1p1 --thumb
 */
void func_02017B24(void *p, u32 a, u32 b, u32 c)
{
    u8 v = (u8)func_02017D30((struct Pokemon *)p);

    func_02017B4C(p, a, b, c);
    func_02017D70((struct Pokemon *)p, v);
}







/*
 * poke_tool.c: the "reset this record to a fresh hatched state" writer.  It
 * takes the block lock, reads the species (id 5) and the form (id 0x6F, for
 * its side effect only -- the result is discarded, which is why the call is a
 * statement), clears the egg flag (id 0x4C), stores 0x78 into id 9, renders
 * the species name into the shared 0x20 halfword buffer at 0x021462F0 and
 * writes it back as the nickname (id 0x74), then hands the record and the
 * three caller arguments to func_0202F1B4 before releasing the lock.
 *
 * WHAT WAS WRONG IN THE EARLIER NOTE, AND WHAT CLOSED IT
 * -----------------------------------------------------
 * docs/notes/func_02017B4C.diff.c.txt records this function as a 104-byte
 * DIFF at 120 bytes against 124, and that source is four bytes short with the
 * whole body misaligned.  The note's skeleton is correct; only two
 * declarations are wrong, and they are the whole difference.
 *
 * The note declares the two accessor externs as returning narrow types --
 * `u8 func_02017DBC((struct Pokemon *)...)` and `u16 func_02017E88(...)` -- and assigns their
 * results to same-width locals.  With the callee declared narrow the compiler
 * believes the value is already truncated, emits no shift pair, and then has
 * nothing cheap to keep the value in, so it spills BOTH to the frame
 * (`str r0, [sp, #4]` / `str r0, [sp, #8]`) and burns the two argument
 * registers r6 and r7 on a1 and a2 instead.
 *
 * The original does the opposite: it truncates at the ASSIGNMENT
 * (`lsls r0, r0, #0x18` / `lsrs r7, r0, #0x18` for the u8 and
 * `lsls r0, r0, #0x10` / `lsrs r6, r0, #0x10` for the u16) and keeps both
 * narrowed values live in r7 and r6, which frees the frame slots for a1 and
 * a2 (`str r1, [sp, #4]` / `str r2, [sp, #8]`).  That shape only compiles
 * when the CALLEE is declared to return a full word and the LOCAL is declared
 * narrow, so the cast is the source's own and not the callee's.  Declaring
 * both externs u32 and both locals u8/u16 is the entire fix; nothing else in
 * the note's body changed.
 *
 * This is the same adjudication rule docs/families/poke_tool.h states: a
 * truncation emitted at the call constrains the callee's parameter width,
 * while a truncation emitted at the assignment constrains the local's.  Here
 * it is the assignment, so the accessors stay u32 -- which also agrees with
 * every other matched file in the family (unit_02017E64.c, unit_0201854C.c,
 * unit_02018430.c all declare func_02017E88 returning u32).
 *
 * The third argument of func_02017E64 is a plain u32 and not a pointer: the
 * note spells it `void *` and passes `(void *)0x78`, which compiles the same
 * here but is a claim the bytes do not support, since id 9 is a byte field.
 *
 * Nothing here is version specific: 5, 9, 0x4C, 0x6F and 0x74 are field
 * selectors and 0x20 is a halfword count.  g_020A7370 and g_021462F0 are
 * globals, so their addresses are build properties.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02017B4C.c \
 *       --func func_02017B4C --addr 0x02017B4C --cc 1.1p1 --thumb
 */
u32 func_02017B4C(void *a0, u32 a1, u32 a2, u32 a3)
{
    u8  v = (u8)func_02017DBC((struct Pokemon *)a0);
    u16 w = (u16)func_02017E88(a0, 5, 0);

    func_02017E88(a0, 0x6f, 0);
    func_02017E64(a0, 0x4c, 0);
    func_02017E64(a0, 9, 0x78);
    func_02045F5C(g_020A7370, w, (u16 *)g_021462F0, 0x20);
    func_02017E64(a0, 0x74, (u32)g_021462F0);
    func_0202F1B4((u32)a0, 2, a1, a2, a3);
    return func_02017DE4((struct Pokemon *)a0, v);
}







/*
 * Three "rows" of a dialog/UI record: for each row index below 3, read the
 * three fields at +0x37/+0x3B/+0x3F and write the copies back at
 * +0x36/+0x3A/+0x3E (the field before each), then clear the three
 * single-byte fields at 0x39/0x3D/0x41.
 *
 * The loop counter is the function's own second parameter -- there is no
 * initialiser, the entry test is `cmp r4, #3 / bhs` straight off the
 * argument, and the back edge is `cmp r4, #3 / blo`, so the source is
 * `for (; i < 3; i++)` over an unsigned i, not a local counter.
 *
 * The u16/u8 shift pairs are the destination widths of the three temporaries
 * (`lsls #16 / lsrs #16` versus `lsls #24 / lsrs #24` for a u8), which is
 * what fixes the return type of sub_02017E1C as wider than both.  The first
 * temporary is live across the other two reads and spills to the `push`
 * home area (`str r0, [sp]` / `ldr r2, [sp]`), which is why r3 is in the
 * push list without being read anywhere.
 *
 * EXACT*: the listing extent runs to 136 bytes because the follower at
 * 0x02017C50 saves no lr and carries no label.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02017BC8.c \
 *       --func func_02017BC8 --addr 0x02017BC8 --cc 1.1p1 --thumb
 */
void func_02017BC8(u8 *p, u32 i)
{
    for (; i < 3; i++) {
        u16 a = sub_02017E1C(p, i + 0x37, 0);
        u8  b = sub_02017E1C(p, i + 0x3b, 0);
        u8  c = sub_02017E1C(p, i + 0x3f, 0);

        sub_02017E40(p, i + 0x36, a);
        sub_02017E40(p, i + 0x3a, b);
        sub_02017E40(p, i + 0x3e, c);
    }
    sub_02017E40(p, 0x39, 0);
    sub_02017E40(p, 0x3d, 0);
    sub_02017E40(p, 0x41, 0);
}






/*
 * Picks one of three record types and writes selector 0xa.  `mask` is a
 * bit test against the byte returned by selector 0, and which bit it is
 * depends on selector 0x77: below 0x14 the mask is bit 0, at or above it the
 * mask is bit 16.  The comparison against 0x14 is *unsigned* in the original
 * (`bhs`, not `bge`), so func_02017E88 must be declared returning an unsigned
 * type - an `int` declaration emits `bge` and costs four bytes.
 *
 * Declaration order is load bearing: `r6` (the 0x1a/0x1b/0x1c selector) is
 * declared first and takes the higher register, `mask` second and takes the
 * lower one.  Reversing them keeps the same instruction count but swaps r4
 * and r6 in nine places.
 *
 * EXACT*: the extent runs into the follower's four-byte pad.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02017C50.c \
 *       --func func_02017C50 --addr 0x02017C50 --cc 1.1p1 --thumb
 */
void func_02017C50(int a0, int a1, int a2)
{
    int v = (int)func_02019C54(a1, (unsigned short)func_02017E88((void *)a0, 0x6f, 0));
    int r7 = func_02017E88((void *)a0, 0, 0);
    int r6 = 0x1a;
    u32 mask = 1 << 16;

    if (func_02017E88((void *)a0, 0x77, 0) < 0x14) {
        mask = 1;
    }
    if (func_02017E88((void *)a0, 0x71, 0) != 0) {
        r6 = 0x1c;
    } else if (func_02019C7C((void *)v) == 2 && (r7 & mask) != 0) {
        r6 = 0x1b;
    }
    func_02017E64((void *)a0, 0xa, func_0201AE1C((const struct Personal *)v, r6));
}






/*
 * verdict:  EXACT* (match.py: compiled 102, listing extent 104).  The two
 *           trailing bytes at 0x02017D2E are `00 00` padding after the `pop`
 *           and the follower at 0x02017D30 carries no label, so the inferred
 *           extent runs two bytes long.  Never a byte difference; the follower
 *           is reported for the integrator rather than seeded here
 *           (layout/function_starts.txt is not this lane's file).
 */
void sub_02017CC8(void *a0, void *a1, void *a2)
{
    u32 v = func_02017E88(a0, 0x6f, 0);
    u32 t = func_0201AE1C((const struct Personal *)func_02019C54((u32)a1, v), 0x14);
    u32 w = func_0201AE1C((const struct Personal *)func_02019C54((u32)a2, v), 0x14);

    if (func_0201AF6C(t) == 1 && w != 0xff) {
        return;
    }
    func_02017E64(a0, 0x6e, func_02017F50((u32)a1, v, func_02017E88(a0, 0, 0)));
}






u32 func_02017D30(struct Pokemon *p)
{
    u32 r = 0;

    if (p->b0 == 0) {
        r = 1;
        p->b0 = 1;
        p->b1 = 1;
        func_02019A50((u16 *)&p->unk88, 0x54, p->unk00);
        func_02019A50((u16 *)p->unk08, 0x80, p->unk06);
    }
    return r;
}





u32 func_02017D70(struct Pokemon *p, u32 f)
{
    u32 r = 0;

    if (p->b0 == 1 && f == 1) {
        p->b0 = 0;
        p->b1 = 0;
        r = 1;
        func_02019A50((u16 *)&p->unk88, 0x54, p->unk00);
        p->unk06 = func_02019A9C((const u16 *)p->unk08, 0x80);
        func_02019A50((u16 *)p->unk08, 0x80, p->unk06);
    }
    return r;
}





u32 func_02017DBC(struct Pokemon *p)
{
    u32 r = 0;

    if (p->b1 == 0) {
        p->b1 = 1;
        r = 1;
        func_02019A50((u16 *)p->unk08, 0x80, p->unk06);
    }
    return r;
}





u32 func_02017DE4(struct Pokemon *p, u32 f)
{
    u32 r = 0;

    if (p->b1 == 1 && f == 1) {
        r = 1;
        p->b1 = 0;
        p->unk06 = func_02019A9C((const u16 *)p->unk08, 0x80);
        func_02019A50((u16 *)p->unk08, 0x80, p->unk06);
    }
    return r;
}






/*
 * 0x02017E1C..0x02017E40, 36 bytes, one function.
 *
 * The read wrapper for the party area of the 0xDC byte record: unlock, call
 * the party-area dispatcher func_02018DB4 (src/matched/sub_02018DB4.c), lock
 * again and return its result.  It is the exact counterpart of func_02017E88
 * in src/matched/unit_02017E64.c, which does the same around func_02018E34,
 * and it is the entry point 240 call sites in the image use.
 *
 * What held it open, and what closed it: the `bl` at 0x02017E2E is the only
 * branch to func_02018DB4 anywhere in the image, so the `label` class has no
 * witness once the compared range holds it, and the range cannot be cut
 * smaller than the one function.  The `matched` class carries it instead:
 * 0x02018DB4 is src/matched/sub_02018DB4.c, an EXACT entry whose own byte
 * comparison covered a range this file does not touch, so the witness is our
 * compiled proof rather than anything inside 0x02017E1C..0x02017E40.  Its
 * setter twin src/matched/unit_02017E40.c closes the same way over
 * func_02019308.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_02017E1C.c \
 *       --addr 0x02017E1C --thumb
 */
u32 func_02017E1C(void *p, u32 id, u32 v)
{
    u32 r;

    func_02018D10((struct Pokemon *)p);
    r = func_02018DB4(p, id, v);
    func_02018D6C((struct Pokemon *)p);
    return r;
}






/*
 * 0x02017E40..0x02017E64, 36 bytes, one function.
 *
 * The write wrapper for the party area of the 0xDC byte record, and the twin
 * of src/matched/unit_02017E1C.c: unlock, and only if the unlock reports 1
 * call the party-area setter func_02019308 (src/matched/sub_02019308.c), then
 * lock again.  It is the counterpart of func_02017E64 in
 * src/matched/unit_02017E64.c, which does the same around func_02019388.
 *
 * What held it open, and what closed it: the `bl` at 0x02017E56 is the only
 * branch to func_02019308 anywhere in the image, so no image class could
 * attest it from outside this range.  The `matched` class does:
 * 0x02019308 is src/matched/sub_02019308.c, an EXACT entry proved against the
 * original bytes over a range this file does not touch.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_02017E40.c \
 *       --addr 0x02017E40 --thumb
 */
void func_02017E40(void *p, u32 id, u32 v)
{
    if (func_02018D10((struct Pokemon *)p) == 1) {
        func_02019308(p, id, v);
    }
    func_02018D6C((struct Pokemon *)p);
}






/*
 *           func_02017ED8, func_02017F00, func_02017F08, func_02017F50,
 *           func_02017F90, func_02017F9C, func_02017FA8
 *
 * Five of the eleven carry no label in the generated listing: the three eight
 * to twelve byte pool-word tail calls at 0x02017EAC, 0x02017F00 and
 * 0x02017FA8, and the two twelve byte argument-setting thunks at 0x02017F90
 * and 0x02017F9C, all of them
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md.  func_02017EAC, func_02017F00
 * and func_02017FA8 each tail call the function immediately after them, which
 * makes two of the three sites the `local` class.
 *
 * func_02017ED8 folds two words to sixteen bits and its four XOR operands have
 * exactly one source order, which is not the order the `eors` appear in; see
 * docs/idioms/the-accumulator-of-a-commutative-chain-is-its-second-operand.md.
 *
 * func_02017F50 dispatches 0, 0xFE and 0xFF out of a byte and falls through to
 * a comparison for everything else.  The three tests are one `switch`: written
 * as a chain of `if (n == k) return v;` statements each return gets its own
 * epilogue, while the switch puts the three bodies after the compare chain and
 * shares one `pop`, which is what the original does.  The `lsls`/`lsrs` pair
 * that truncates the call result is only emitted when the callee is declared
 * wider than `u8`, so func_0201AE1C returns a word and the source assigns it to
 * a byte local.
 */
void func_02017E64(void *p, u32 id, u32 v)
{
    if (func_02018D34((struct Pokemon *)p) == 1) {
        func_02019388(p, id, v);
    }
    func_02018D8C((struct Pokemon *)p);
}






u32 func_02017E88(void *p, u32 id, u32 v)
{
    u32 r;

    func_02018D34((struct Pokemon *)p);
    r = func_02018E34(p, id, v);
    func_02018D8C((struct Pokemon *)p);
    return r;
}






u32 func_02017EAC(void *p)
{
    return func_02017EB4(p);
}






u32 func_02017EB4(void *p)
{
    u32 a = func_02017E88(p, 7, 0);

    return func_02017ED8(a, func_02017E88(p, 0, 0));
}






u32 func_02017ED8(u32 a, u32 b)
{
    u32 x = ((a & 0xFFFF0000) >> 16) ^ (u16)a ^ ((b & 0xFFFF0000) >> 16) ^ (u16)b;

    if (x < 8) {
        return 1;
    }
    return 0;
}






u8 func_02017F00(void *p)
{
    return func_02017F08(p);
}






u8 func_02017F08(void *p)
{
    u32 t = func_02017DBC((struct Pokemon *)p);
    u16 a = (u16)func_02017E88(p, 5, 0);
    u32 b = func_02017E88(p, 0x6F, 0);
    u32 c = func_02017E88(p, 0, 0);

    func_02017DE4((struct Pokemon *)p, t);
    return func_02017F50(a, (u16)b, c);
}






u8 func_02017F50(u32 a, u16 b, u32 c)
{
    u8 n = func_0201AE1C((void *)func_02019C54((u32)a, b), 0x14);
    u8 r;

    switch (n) {
    case 0x00:
        return 0;
    case 0xFE:
        return 1;
    case 0xFF:
        return 2;
    }
    if ((u8)c < n) {
        r = 1;
    } else {
        r = 0;
    }
    return r;
}






u32 func_02017F90(void *p)
{
    return func_02017E1C(p, 0x9D, 0);
}






void func_02017F9C(void *p, u32 v)
{
    func_02017E40(p, 0x9D, v);
}






u32 func_02017FA8(void *p)
{
    return func_02017FB0(p);
}






static inline int Learn_IsEnd(const struct Learn *t)
{
    int end = 0;
    if (t->move == 0xFFFF && t->level == 0xFFFF)
        end = 1;
    return end;
}





/*
 * Reset a record's moves to its level-up set: clear the four move/PP/PP-up
 * slots, load the species/form learnset into the shared buffer at
 * 0x02146330, then teach every entry at or below the current level
 * (func_02018094; 0xFFFF = no free slot, so push it in with func_020180FC).
 * Block-lock sandwich (func_02017DBC / func_02017DE4).  Wave 11, 2026-09-23.
 *
 * Load-bearing: ONE loop variable `i` for both phases (the clearing loop
 * and the learnset walk, re-zeroed in between).  With two variables the
 * zero value argument and the walk index take separate registers and every
 * callee-saved register shifts (docs/idioms: reusing a loop variable
 * across phases); the permuter's hill (800, --types) found only volatile
 * hacks.  The frame's four entry copies and the pointer-taking terminator
 * inline follow func_02018328.c exactly (declaration order e, d, t, cur).
 */
u32 func_02017FB0(void *p)
{
    u32 flag;
    u16 species;
    u32 form;
    u8 level;
    int i;
    struct Learn e;
    struct Learn d;
    struct Learn t;
    struct Learn cur;

    flag = func_02017DBC((struct Pokemon *)p);
    species = func_02017E88(p, 5, 0);
    form = func_02017E88(p, 0x6f, 0);
    level = func_02018438(p);
    func_0201ADD0(species, (u16)form, gLearnBuf);

    for (i = 0; i < 4; i++) {
        func_02017E64(p, 0x36 + i, 0);
        func_02017E64(p, 0x3a + i, 0);
        func_02017E64(p, 0x3e + i, 0);
    }
    i = 0;
    while (cur = gLearnBuf[i], t = cur, !Learn_IsEnd(&t)) {
        e = cur;
        if (e.level > level)
            break;
        d = cur;
        if (func_02018094(p, d.move) == 0xFFFF)
            func_020180FC(p, d.move);
        i++;
    }
    return func_02017DE4((struct Pokemon *)p, flag);
}




/*
 * poke_tool.c: "teach this move if there is room".  func_02018094 unlocks the
 * record, walks the four move slots (ids 0x36 to 0x39 of the getter
 * func_02017E88), and writes the move into the first empty one through
 * func_020181FC (src/matched/unit_020181A0.c), locking again on the way out.
 * It answers with the move it wrote, 0xFFFE if the record already knows it,
 * and 0xFFFF if all four slots are full; func_0201808C is a bare tail call to
 * it under a second name (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 *
 * 0xFFFE and 0xFFFF are ordinary integer constants and not relocations: both
 * are past the 255 an immediate reaches, so they arrive from the pool the way
 * any wide literal does.  The result is a stack local because it is live
 * across the unlock call, and it is assigned before the lock is taken, which
 * is what puts the `str` of 0xFFFF in front of the first `bl`.
 *
 * The third argument of every getter call comes out of a register that
 * already holds the loop counter's initial zero (`adds r7, r4, #0`), which is
 * docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md
 * seen from the sharing side.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201808C.c \
 *       --addr 0x0201808C --thumb
 */
u16 func_0201808C(void *p, u16 move)
{
    return func_02018094(p, move);
}




u16 func_02018094(void *p, u16 move)
{
    u16 r = 0xFFFF;
    u32 lock = func_02017DBC(p);
    s32_0201808C i;

    for (i = 0; i < 4; i++) {
        u16 cur = (u16)func_02017E88(p, (u32)(0x36 + i), 0);

        if (cur == 0) {
            func_020181FC(p, move, (u8)i);
            r = move;
            break;
        }
        if (cur == move) {
            r = 0xFFFE;
            break;
        }
    }
    func_02017DE4(p, lock);
    return r;
}




/*
 * An eight-byte Thumb tail thunk: `ldr r3, =func_020180FC; bx r3` with the
 * pool word immediately after.  It is the only callee of ov121 func_021DEFAC
 * with no `func_` label of its own (disasm.py sees the two-halfword stub as
 * data between func_020180FC's neighbour and func_020180FC).  Matching it
 * separately is what lets func_021DEFAC's `bl 0x020180F4` resolve as
 * `matched` rather than wildcarded; the veneer class is ARM-only, so the Thumb
 * stub has no other witness.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020180F4.c \
 *       --func func_020180F4 --addr 0x020180F4 --cc 1.1p1 --thumb --region arm9
 */
void func_020180F4(void *p, u16 move)
{
    func_020180FC(p, move);
}







/* Three parallel 4-entry channel tables.  They are three separate locals, NOT
 * one 16-byte struct: as a struct mwcc folds the member offset into the store
 * (`add r1, sp, #8 / adds r1, r1, r2 / strh r0, [r1, #8]`, three instructions
 * per element) where three arrays let it hoist `add r7, sp, #0x10` out of the
 * loop and emit `lsls r1, r4, #1 / strh r0, [r7, r1]`.  Declaration order
 * a, b, c (later declarator at the lower stack address) is what puts them at
 * sp+0x10 / sp+0xc / sp+8.  The fourth entry of each table is filled from a
 * different source: a[3] the parameter, b[3] a lookup, c[3] zero. */
/*
 * EXACT*: the listing extent runs 10 bytes past the body to 0x02018196
 * because the follower there is unlabelled -- 0x02018196 is two bytes of
 * padding and then a 4-byte ARM `ldr r3, [pc]; bx r3` veneer at 0x02018198.
 * No byte differs; the compiler's 154 bytes are byte-identical.
 */
void func_020180FC(void *p, u16 v)
{
    u16 a[4];
    u8  b[4];
    u8  c[4];
    u32 h;
    int i;
    int j;

    h = func_02017DBC(p);

    for (i = 0; i < 3; i++) {
        a[i] = func_02017E88(p, i + 0x37, 0);
        b[i] = func_02017E88(p, i + 0x3b, 0);
        c[i] = func_02017E88(p, i + 0x3f, 0);
    }

    a[3] = v;
    b[3] = func_0201BD28(v, 5);
    c[3] = 0;

    for (j = 0; j < 4; j++) {
        func_02017E64(p, j + 0x36, a[j]);
        func_02017E64(p, j + 0x3a, b[j]);
        func_02017E64(p, j + 0x3e, c[j]);
    }

    func_02017DE4(p, h);
}











/*
 * Unlabelled Thumb tail-call stub after func_020180FC (ldr r3, =func_020181A0;
 * bx r3). Filed as the witness for ov021 func_021C4340.
 */
void func_02018198(void *mon)
{
    func_020181A0(mon);
}











/*
 * Two move-slot writers over the record's ids 0x36..0x39 (the four move ids),
 * 0x3A..0x3D (their current PP) and 0x3E..0x41 (their PP-up counts), the same
 * three groups func_02018E34 reads.  func_020181A0 refills every non-empty
 * slot's PP to the maximum func_0201C158 computes from the move and its PP-up
 * count; func_020181FC writes one slot outright, clearing the PP-up count and
 * setting the PP to the fresh maximum, or to zero when the move is zero.
 * func_020181F4 in front of it is an eight byte
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md thunk, `local` because its
 * target is the next function in this unit.
 *
 * func_020181FC is what makes this unit and src/matched/unit_02018094.c-shaped
 * callers attest each other: its two call sites in the image are the thunk
 * here and one inside func_02018094, so neither range can hold both.
 *
 * Two spellings are load bearing.  func_020181A0's loop counter is unsigned,
 * because the bound test is `blo` and not `blt`; the counter of the otherwise
 * identical loop in func_02018094 and func_02018240 is signed and those use
 * `blt`.  And the two truncations in func_020181A0 sit at the call, `(u16)m`
 * and `(u8)u` on word locals, rather than on narrower locals, which is the
 * same shape as src/matched/unit_02018430.c.
 *
 * Nothing here is version specific: 0x36, 0x3A and 0x3E are field selectors.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_020181A0.c \
 *       --addr 0x020181A0 --thumb
 */
void func_020181A0(void *p)
{
    u32 t = func_02017DBC(p);
    u32 i;

    for (i = 0; i < 4; i++) {
        u32 m = func_02017E88(p, 0x36 + i, 0);

        if (m != 0) {
            u32 u = func_02017E88(p, 0x3E + i, 0);

            func_02017E64(p, 0x3A + i, func_0201C158((u16)m, (u8)u));
        }
    }
    func_02017DE4(p, t);
}











void func_020181F4(void *p, u16 move, u32 slot)
{
    func_020181FC(p, move, slot);
}











void func_020181FC(void *p, u16 move, u32 slot)
{
    u32 pp = 0;

    func_02017E64(p, 0x36 + slot, move);
    func_02017E64(p, 0x3E + slot, 0);
    if (move != 0) {
        pp = func_0201C158(move, 0);
    }
    func_02017E64(p, 0x3A + slot, pp);
}











u32 func_02018238(void *p, u16 move)
{
    return func_02018240(p, move);
}











/*
 * status note: EXACT* -- the extent runs long because the unlabelled 8-byte
 *           thunk at 0x020182A0 follows without a label; never a byte
 *           difference.  Report it as an unlabelled follower for
 *           layout/function_starts.txt.
 *
 * WAS BLOCKED, now resolved (2026-09-22): the only branch to 0x020182A8 in the
 *           image is this function's own call at +0x30, so the `label` class
 *           had no outside witness and this file was capped at MATCH.
 *           src/matched/func_020182A8.c now reproduces that address, so the
 *           site resolves through `matched` and this file is EXACT* with no
 *           edit to its C.
 *
 * "Put this move in the first empty slot": walks ids 0x36..0x39 and returns
 * 0xFFFF when no slot was touched, the move when one was filled, and 0xFFFE
 * when the move was already known.  The loop counter is signed (`blt`), unlike
 * the otherwise identical loop in func_020181A0, which is `blo`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02018240.c \
 *       --func func_02018240 --addr 0x02018240 --cc 1.1p1 --thumb
 */
u32 func_02018240(void *p, u16 move)
{
    u32 r = 0xFFFF;
    u32 t = func_02017DBC(p);
    int i;

    for (i = 0; i < 4; i++) {
        u32 m = (u16)func_02017E88(p, 0x36 + i, 0);

        if (m == 0) {
            func_020182A8(p, move, (u8)i);
            r = move;
            break;
        }
        if (m == move) {
            r = 0xFFFE;
            break;
        }
    }
    func_02017DE4(p, t);
    return r;
}











void func_020182A0(void *p, u16 move, u8 slot)
{
    func_020182A8(p, move, slot);
}











/*
 * "Write this move into slot `slot`, keeping the PP the slot already had".
 * The twin of func_020181FC (src/matched/unit_020181A0.c), which writes the
 * slot outright: this one remembers whether the slot held a move (b), reads
 * the slot's current PP (0x3A + slot, as a u8), writes the move id
 * (0x36 + slot), clears the PP-up count (0x3E + slot), and finally writes a PP
 * that is the fresh maximum func_0201C158 computes -- except that when the
 * slot was previously occupied the PP is clamped down to whatever the old
 * slot had, so replacing a move never raises its remaining PP.
 *
 * THE LEVER, and the whole 128-byte residue this file's earlier attempts hit
 * (docs/notes/pkt_02018240.c.txt records ten prologue bytes wrong across every
 * statement-shape and declaration-order spelling tried, and tools/permuter.py
 * -- 197 single mutations, --types -- cannot move any of them):
 *
 *     THE THIRD PARAMETER IS u8, NOT u32.
 *
 * That is the family's own first-pass rule -- a truncation emitted at the CALL
 * constrains the CALLEE's parameter width -- read off the single caller,
 * func_02018240 at 0x02018268:
 *
 *     02018268  lsls r2, r4, #0x18
 *     0201826E  lsrs r2, r2, #0x18      <- (u8)i at the call site
 *
 * With `u8 slot` the front end gives the parameter a memory home at sp+0 and
 * reloads it (`str r2,[sp]` ... `ldr r1,[sp]`), which is exactly the prologue
 * the original has; with `u32 slot` it keeps the incoming r2 in a register
 * (`adds r1, r2, #0`) and the five entry halfwords permute.  No statement
 * shape, declaration order, volatile, address-taking or extra parameter
 * reaches it -- only the width does.
 *
 * Filing this address also unblocks src/pending/func_02018240.c, whose only
 * missing witness was a manifest entry at 0x020182A8 (its own call at +0x30 is
 * the sole branch to this address in the image, so the `label` class had no
 * outside witness).  That file turns EXACT with no edit.
 *
 * Nothing here is version specific: 0x36, 0x3A and 0x3E are field selectors.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/func_020182A8.c \
 *       --func func_020182A8 --addr 0x020182A8 --cc 1.1p1 --thumb
 */
void func_020182A8(void *p, u16 move, u8 slot)
{
    u32 b;
    u32 d;
    u32 c;
    u32 v = 0;
    u32 pp;

    d = slot + 0x36;
    if (func_02017E88(p, d, 0) != 0) {
        b = 1;
    } else {
        b = 0;
    }
    c = slot + 0x3A;
    pp = (u8)func_02017E88(p, c, 0);
    func_02017E64(p, d, move);
    func_02017E64(p, slot + 0x3E, 0);
    if (move != 0) {
        v = func_0201C158(move, 0);
        if (b != 0) {
            if (v <= pp) {
                pp = v;
            }
            v = (u8)pp;
        }
    }
    func_02017E64(p, c, v);
}







/*
 * Level-up learnset scan: load the species/form learnset (func_0201ADD0) into
 * a 0x68-byte heap block (poke_tool.c line 0x644), then walk it from *idx
 * until the {0xFFFF, 0xFFFF} terminator.  For an entry at the record's
 * level, try to teach it (func_0201808C): 0xFFFF (no free slot) answers the
 * move with bit 15 set, 0xFFFE (already known) keeps scanning, anything else
 * is returned; *idx is left one past the entry.  Wave 11, 2026-09-23.
 *
 * Load-bearing, found by hand after the permuter's hill (800, --types) and
 * the r12 lane's register swap:
 *   - `species` is u16 (truncated at the assignment) but `form` is u32 and
 *     the (u16) lands at the func_0201ADD0 call; `level` is u8.
 *   - FIVE 4-byte struct copies live in the frame, in this declaration
 *     order (later declaration at the lower address): e, d, f, t, cur.
 *     They are by-value copies of the entry (e for the level test, d for the
 *     move, f for the final re-read, t for the terminator test).  Written
 *     as inline helpers taking the struct by value, the compiler elides one
 *     copy and swaps two slots; spelled as explicit locals it does not.
 *   - the terminator test is an inline taking `const struct Learn *` with
 *     the `end = 0; if (..) end = 1;` accumulator, called in the `while`
 *     condition so the loop is rotated (entry `b` to the test).
 *   - `level == e.level` (level first: cmp r0, r1).
 */
u16 func_02018328(void *p, u32 *idx, u32 heap)
{
    struct Learn *tbl;
    u16 species;
    u32 form;
    u8 level;
    u16 ret = 0;
    struct Learn e;
    struct Learn d;
    struct Learn f;
    struct Learn t;
    struct Learn cur;

    tbl = func_02030734((u16)((heap & 0x7fff) | 0x8000), 0x68, 0, (const char *)&sPokeToolFile, 0x644);
    species = func_02017E1C(p, 5, 0);
    form = func_02017E1C(p, 0x6f, 0);
    level = func_02017E1C(p, 0x9e, 0);
    func_0201ADD0(species, (u16)form, tbl);

    while (cur = tbl[*idx], t = cur, !Learn_IsEnd(&t)) {
        e = cur;
        if (level == e.level) {
            d = cur;
            ret = func_0201808C(p, d.move);
            if (ret == 0xFFFF) {
                f = tbl[*idx];
                ret = f.move | 0x8000;
                (*idx)++;
                break;
            }
            if (ret != 0xFFFE) {
                (*idx)++;
                break;
            }
        }
        (*idx)++;
    }
    func_020307B0(tbl);
    return ret;
}








/*
 * The record's level accessor: it unlocks the block area, reads ids 5, 0x6F
 * and 8 out of it (species, form and experience), locks it again and hands the
 * three to func_0201850C (src/matched/unit_0201850C.c), which is the same
 * computation id 0x9E of func_02018E34 performs directly on the substructs.
 * func_02018430 in front of it is an eight byte
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md thunk with no prologue, and
 * its pool word is `local` because its target is the next function in the same
 * unit.
 *
 * The three values are held in word locals and truncated at the call, not at
 * the assignment: the two `lsls #0x10` / `lsrs #0x10` pairs sit immediately in
 * front of the `bl`, after the lock call, which is what fixes func_0201850C's
 * first two parameters as u16 and func_02017E88's return as a word.  The same
 * shape appears in src/matched/unit_02017E64.c and src/matched/unit_0201854C.c.
 *
 * The range stops at 0x02018480, where another eight byte thunk forwards to
 * func_02018488; that thunk's pool word is the only reference to func_02018488
 * in the image, and func_02018488 in turn is the only caller of 0x020084F8, so
 * neither can be attested and both are left out.
 *
 * Nothing here is version specific: 5, 0x6F and 8 are field selectors.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_02018430.c \
 *       --addr 0x02018430 --thumb
 */
u32 func_02018430(void *p)
{
    return func_02018438(p);
}








u32 func_02018438(void *p)
{
    u32 t = func_02017DBC(p);
    u32 species = func_02017E88(p, 5, 0);
    u32 form = func_02017E88(p, 0x6F, 0);
    u32 exp = func_02017E88(p, 8, 0);

    func_02017DE4(p, t);
    return func_0201850C((u16)species, (u16)form, exp);
}








/*
 * Eight byte thunk (pool word and bx) that forwards both arguments to
 * func_02018488. Witness for the ov093 caller func_021BCFAC.
 */
int func_02018480(void *p, int q)
{
    return func_02018488(p, (void *)q);
}








/*
 * note:     132 bytes, one function
 * note:     re-verified 2026-09-21: EXACT.  The MATCH cap was lifted by the
 *           sole-ref widening of 2026-09-21, not by any edit to the C:
 *           the data address this file reaches now attests as
 *           sole-ref/data.  Promoted from src/pending/ unchanged.
 *
 * Why it WAS capped (historical, resolved 2026-09-21): the ABS32 against the 0x021462B0 scratch buffer.  A scan
 * of every word in all 242 regions finds 0x021462B0 exactly once, in the pool
 * word at 0x02018508 that this function owns, so the `literal` class discards
 * its only witness and no cut helps.  The buffer's neighbour 0x021462F0 is
 * named by six pool words and resolves; the two are 0x40 apart and are two
 * statics in one bss run rather than one object with an offset, so declaring
 * a single symbol at the attested one and reaching this one as a negative
 * addend would be a claim about the data layout the image does not support.
 * It closes the day anything else in the image names 0x021462B0.
 *
 * poke_tool.c: "does this record still belong to the trainer that owns this
 * mail", the comparison that unlocks the record with func_02017DBC
 * (src/matched/unit_02017D30.c), reads the trainer id (field 0x07) and the
 * second name field (0x9A) out of it, reads the same two out of the mail
 * object through func_02008530 and func_02008550, copies both names into the
 * two 0x20 byte scratch buffers at 0x021462F0 and 0x021462B0, and compares
 * the strings with func_0201F448.
 *
 * The three tests are one conjunction: all three conditional branches land on
 * the same address and there is one `movs r6, #1`
 * (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md).
 *
 * The four comparison operands are stack locals rather than registers because
 * they are live across the calls that follow them, and they sit at sp+0,
 * sp+4, sp+8 and sp+0xC in the order the source declares them last to first
 * (docs/idioms/local-declaration-order-is-stack-order.md).
 *
 * The lock flag is truncated to u8 on the way out of func_02017DBC, which is
 * the `lsls #0x18` / `lsrs #0x18` pair at 0x02018494.
 *
 * Verified with
 *   python tools/match.py tu --src src/pending/sub_02018488.c \
 *       --addr 0x02018488 --thumb
 */
u32 sub_02018488(void *p, void *mail)
{
    u32 d;
    u32 c;
    u32 b;
    u32 a;
    u8  lock = (u8)func_02017DBC(p);
    u32 r = 0;

    a = func_02008530(mail);
    b = func_02017E88(p, 7, 0);
    c = func_02008550(mail);
    d = func_02017E88(p, 0x9A, 0);
    func_020084F8(mail, (u32)g_021462F0, 0x20);
    func_02017E88(p, 0x8E, (u32)g_021462B0);
    if (a == b && c == d && func_0201F448((const u16 *)g_021462F0, (const u16 *)g_021462B0) != 0) {
        r = 1;
    }
    func_02017DE4(p, lock);
    return r;
}








/*
 * Experience to level.  This is the callee of id 0x9E of func_02018E34
 * (src/pending/sub_02018E34.c), which passes it a species id, the five bit
 * form field of substruct B +0x18 and the experience word of substruct A +8.
 * It reads field 0x17 of the species' record, which is the growth-rate
 * selector, fills the shared word buffer at 0x02146398 with that curve through
 * func_02019B94, and then walks entries 1 to 0x64 for the first one that
 * exceeds the experience, returning the index before it.
 *
 * The loop is a `for` whose bound test the compiler rotates to the bottom, so
 * the first table read happens before any comparison with 0x65; the counter is
 * u16, which is what the `lsls #0x10` / `lsrs #0x10` pair after each increment
 * is, and writing it `u32` drops that pair and the function is four bytes
 * short.
 *
 * The range stops at 0x02018544, where an eight byte
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md thunk forwards to
 * func_0201854C.  That thunk's pool word is the only reference to
 * func_0201854C in the image, so including it caps the file at MATCH; it is
 * left out and this function is clean.
 *
 * 0x02146398 is the same scratch buffer func_02019BA4 fills in
 * src/matched/unit_02019B58.c, which is what attests it here and what this
 * file's pool word attests there: the pairwise case of docs/MATCHING.md.
 *
 * Nothing here is version specific; 0x17 is a field selector and 0x65 is the
 * level table's length.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_0201850C.c \
 *       --addr 0x0201850C --thumb
 */
u32 func_0201850C(u16 species, u16 form, u32 exp)
{
    u16 i;

    func_02019B94((u16)func_0201AE1C(func_02019C54(species, form), 0x17),
                  gWordBuf);
    for (i = 1; i < 0x65; i = (u16)(i + 1)) {
        if (gWordBuf[i] > exp) {
            break;
        }
    }
    return i - 1;
}







u32 func_02018544(void *p) { return func_0201854C(p); }









/*
 * 0x0201854C..0x02018598, 76 bytes, two functions.
 *
 * What held it open, and what closed it: func_02018584 is the only caller of
 * func_02019BA4 in the whole image, so the `label` class has no witness once
 * the compared range holds that call, and no cut helps because the range
 * cannot be made smaller than the one function that needs it.  The `matched`
 * class carries it: 0x02019BA4 is inside src/matched/unit_02019B58.c, an
 * EXACT entry whose byte comparison covered that address over a range this
 * file does not touch.  Keeping func_0201854C with func_02018584 costs
 * nothing, since func_0201854C is in turn the only caller of func_02018584.
 *
 * The three ids this reads, 5, 0x6F and 0x9E, are the same three
 * func_020188B4 and func_02019CA0 read, and all three values are truncated to
 * u16 at the call rather than at the assignment, which is what fixes
 * func_02018584's parameters as u16 and the accessor's return as a word.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_0201854C.c \
 *       --addr 0x0201854C --thumb
 */
u32 func_0201854C(void *p)
{
    u32 a = func_02017E88(p, 5, 0);
    u32 b = func_02017E88(p, 0x6F, 0);
    u32 c = func_02017E88(p, 0x9E, 0);

    return func_02018584((u16)a, (u16)b, (u16)c);
}









u32 func_02018584(u16 a, u16 b, u16 c)
{
    return func_02019BA4(func_02019C90(a, b, 0x17), c);
}









/*
 * The middle piece of the run 0x0201854C..0x0201862C.  Its two neighbours are
 * parked in src/pending/: func_02018584 is the only caller of func_02019BA4
 * in the image and func_020185C4 the only caller of func_02018A7C, so neither
 * has a witness outside itself and no cut reaches them.
 *
 * func_02018598 carries no label: it is the eight byte pool-word tail call of
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md to the function that follows
 * it, so the site is the `local` class.
 */
u8 func_02018598(void *p)
{
    return func_020185A0(p);
}









u8 func_020185A0(void *p)
{
    return (u8)func_02017E88(p, 0x70, 0);
}









void func_020185B0(void *p, u32 v)
{
    func_02017E40(p, 0x70, v);
    func_020185C4(p);
}









/*
 * 0x020185C4..0x020185F0, 44 bytes, one function.
 *
 * The shape is the lock/recompute/unlock sandwich the whole region uses:
 * func_02017D30 takes the lock and returns whether it actually took it, and
 * that flag is what func_02017D70 is handed back.  Between them it refreshes
 * the level (id 0x9E, from func_02018430) and then recalculates the six stats
 * with func_02018A7C.
 *
 * What held it open, and what closed it: this is the only caller of
 * func_02018A7C anywhere in the image, so the `label` class discards its only
 * witness under the honesty rule and no cut helps, because the range cannot be
 * made smaller than the one function that holds the call.  The `matched` class
 * carries it now: 0x02018A7C is src/matched/sub_02018A7C.c, an EXACT entry
 * proved byte for byte against the original over a range this file does not
 * touch.  It was parked in src/pending/ until that entry existed.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_020185C4.c \
 *       --addr 0x020185C4 --thumb
 */
void func_020185C4(void *p)
{
    u32 f = func_02017D30(p);

    func_02017E40(p, 0x9E, func_02018430(p));
    func_02018A7C(p);
    func_02017D70(p, f);
}









/*
 * func_020185F0 and func_020185F4 are a bare `bx lr` padded to four bytes,
 * which is `void f(void) {}`: a hook that was never filled in.  Neither
 * carries a label in the generated listing.  func_020185F0 is reached from
 * func_02019B58, which is what attests the pair's addresses.
 */
void func_020185F0(void)
{
}









void *func_020185F4(void *p)
{
    return p;
}









u32 func_020185F8(int a, u16 b, int c)
{
    u32 r = 8;
    u8 n = (u8)func_0201AE1C(func_02019C54(a, b), 0x14);

    if (func_0201AF6C(n) != 1) {
        if (c == 0) {
            r = n;
        } else {
            r = n - 1;
            if (n == 0) {
                r = 0;
            }
        }
    }
    return r;
}









/*
 * Force a personality value's shininess against trainer id a0: with a5 set,
 * a fresh value from func_020185F8 whose high half is made to xor to the
 * id's key; otherwise an all-0xFF00 construction plus the species' stage
 * byte.  Bit 16 is then forced to a4.  Wave 11, 2026-09-23.
 *
 * The 9-byte residue of 2026-09-22 (permuter floor, `commute(^)`) closed by
 * naming the id key as a block-scoped local, `k = hi(a0) ^ (u16)a0`, and
 * writing `k ^ (u16)v`: the key is computed first into r2 and the chain
 * stays in r1/r2, as the image has it.  No inline form of the same xor
 * reached it (docs/notes/pkt_0201862C.c.txt).
 */
u32 func_0201862C(u32 a0, u16 a1, u16 a2, u8 a3, u8 a4, int a5)
{
    if (a5 != 0) {
        u32 v = func_020185F8(a1, a2, a3);

        {
            u32 k = ((a0 & 0xFFFF0000u) >> 16) ^ (u16)a0;

            a0 = v | ((k ^ (u16)v) << 16);
        }
        if ((a0 & 0x10000u) != ((u32)a4 << 16)) {
            a0 ^= 0x10000u;
        }
    } else {
        u8 b = (u8)func_0201AE1C(func_02019C54(a1, a2), 0x14);

        a0 = (0xFF00u ^ ((((a0 & 0xFFFF0000u) >> 16) ^ (u16)a0) & 0xFF00u)) << 16;
        if ((a0 & 0x10000u) != ((u32)a4 << 16)) {
            a0 ^= 0x10000u;
        }
        if (func_0201AF6C(b) == 1) {
            goto done;
        }
        a0 |= b;
        if (a3 == 1) {
            a0 -= 1;
        }
    }
done:
    return a0;
}









/*
 * Build a personality value for trainer id a0: a3 selects the gender
 * handling (2 = fully random), a5 the shininess (1 = force shiny through
 * the id key, 0 = force NOT shiny by flipping bit 28 when func_02017ED8
 * says shiny, 2 = leave), and bit 16 is forced to a4 (read as a word, so
 * a4 is int-sized).  Wave 11, 2026-09-23.
 *
 * The 8-byte shortfall of the r4-3/r4-6 lanes ("duplicated compare, shared
 * eors", judged a cross-jump no source can request) is the SOURCE shape:
 * case 1 carries its own bit-16 fix and `break`s, case 0 FALLS THROUGH into
 * case 2, which carries the other copy; the compiler tail-merges the two
 * `v ^= 0x10000` statements and nothing else.  Case bodies in the order
 * 1, 0, 2; the case-1 key written `hi(a0) ^ (u16)a0` first.
 */
u32 func_020186C8(u32 a0, int a1, u16 a2, int a3, int a4, int a5)
{
    u32 v;

    if (a3 == 2) {
        v = func_020056EC(0);
    } else {
        u32 t = func_020056EC(0) & ~0xFFu;

        v = func_020185F8(a1, a2, (u8)a3);
        if (a3 == 0) {
            if (func_0201AF6C(v) == 0) {
                v = v + func_020056EC(0xFE - v);
                goto L;
            }
        }
        if (a3 == 1) {
            if (func_0201AF6C(v) == 0) {
                v = func_020056EC(v) + 1;
            }
        }
    L:
        v |= t;
    }
    switch (a5) {
    case 1:
        v = (u8)v | (((((a0 & 0xFFFF0000u) >> 16) ^ (u16)a0) ^ (u8)v) << 16);
        if ((v & 0x10000u) != ((u32)a4 << 16)) {
            v ^= 0x10000u;
        }
        break;
    case 0:
        if (func_02017ED8(a0, v) == 1) {
            v ^= 0x10000000u;
        }
    case 2:
        if ((v & 0x10000u) != ((u32)a4 << 16)) {
            v ^= 0x10000u;
        }
        break;
    }
    return v;
}









/*
 * note:     144 bytes, one function
 *
 * The type half of the Hidden Power pair; the power half is
 * src/matched/unit_02018820.c and is EXACT.  It folds bit 0 of each of the six
 * 5 bit fields at substruct B +0x10 into a 0..63 index, scales it by 15/63,
 * reduces it below 17 with a subtract loop rather than a modulo, and indexes a
 * byte table at 0x0209E288.
 *
 * Why it WAS capped (historical, resolved 2026-09-21): the pool word at 0x0201881C is the only word in the whole
 * image that holds 0x0209E288, so the `literal` class discards its only
 * witness and the table cannot be attested.  Same shape as
 * docs/idioms/a-string-after-a-data-table-has-no-witness.md.  No cut helps:
 * the load and the pool word are in the one function.
 *
 * The reduction is a `while (n > 16) n -= 16;` and not `n %= 16`, which would
 * be a single `ands`; and the division is unsigned, so the whole expression is
 * `n * 15 / 63`.
 *
 * VERSION SENSITIVITY: the 17 byte table at 0x0209E288 is type ids, which is
 * content numbering; it is expected to be identical in a White build, but it
 * is data rather than structure and should be re-read.
 *
 * Verified with
 *   python tools/match.py tu --src src/pending/unit_02018790.c \
 *       --addr 0x02018790 --thumb
 *
 * RESOLVED 2026-09-21: the sole-ref widening accepts 0x0209E288 as
 * sole-ref/data, so the table now attests and this unit verifies EXACT with no
 * change to its C.  The one edit this wave made is the missing `_u32_div_f`
 * line in the symbols: block below -- without it that site was unresolved and
 * the unit reported MATCH for a reason that had nothing to do with the table.
 *
 * Historical note, no longer binding:
 * The `matched` class does not reach it either: an EXACT entry attests the code
 * it reproduced, never a data object one of its instructions loads, and
 * 0x0209E288 is a table.
 */
u32 func_02018790(void *p)
{
    u32 n = 0;

    if (func_02017E1C(p, 0x46, 0) & 1) {
        n += 1;
    }
    if (func_02017E1C(p, 0x47, 0) & 1) {
        n += 2;
    }
    if (func_02017E1C(p, 0x48, 0) & 1) {
        n += 4;
    }
    if (func_02017E1C(p, 0x49, 0) & 1) {
        n += 8;
    }
    if (func_02017E1C(p, 0x4A, 0) & 1) {
        n += 16;
    }
    if (func_02017E1C(p, 0x4B, 0) & 1) {
        n += 32;
    }
    n = n * 15 / 63;
    while (n > 16) {
        n -= 16;
    }
    return func_02018790_Table[n];
}









/*
 * Folds the six ids 0x46 to 0x4B, the six 5 bit fields of substruct B +0x10
 * that func_02018E34 reads, into a 0 to 63 index on bit 1 of each and scales
 * it to 30..70.  Its neighbour func_02018790 is the same fold on bit 0 with a
 * table lookup at the end, and the two are the pair a Hidden Power power and
 * type are computed with.
 *
 * The range is one function on purpose.  func_02018790, immediately before,
 * reads a byte table at 0x0209E288 whose only reference anywhere in the image
 * is the pool word under test, so it caps at MATCH however it is written; and
 * func_020188AC, immediately after, is an eight byte
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md thunk whose pool word is the
 * only reference to func_020188B4 in the image, so it caps too.  Both are
 * byte-correct and neither can be cut free; this middle function is what is
 * left, and it is clean.
 *
 * The six tests are `(x & 3) > 1` rather than a bit test, which is `movs #3` /
 * `ands` / `cmp #1` / `bls`; the accumulator takes `adds rD, rN, #imm3` for 1,
 * 2 and 4 and `adds rD, #imm8` from 8 up, which is encoding and not source.
 * The scale is one `muls` by 40 and one `_u32_div_f` by 63, so the division is
 * unsigned and written as `n * 40 / 63 + 30`; `+ 30` folds into the `adds`
 * after the call.
 *
 * Nothing here is version specific: the six ids are structure field selectors.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_02018820.c \
 *       --addr 0x02018820 --thumb
 */
u32 func_02018820(void *p)
{
    u32 n = 0;

    if ((func_02017E1C(p, 0x46, 0) & 3) > 1) {
        n += 1;
    }
    if ((func_02017E1C(p, 0x47, 0) & 3) > 1) {
        n += 2;
    }
    if ((func_02017E1C(p, 0x48, 0) & 3) > 1) {
        n += 4;
    }
    if ((func_02017E1C(p, 0x49, 0) & 3) > 1) {
        n += 8;
    }
    if ((func_02017E1C(p, 0x4A, 0) & 3) > 1) {
        n += 16;
    }
    if ((func_02017E1C(p, 0x4B, 0) & 3) > 1) {
        n += 32;
    }
    return n * 40 / 63 + 30;
}









/*
 * Eight byte tail-call thunk to func_020188B4
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md). Filed as the relocation
 * witness for ov021 func_021B62C8 (wave A1).
 */
u32 func_020188AC(void *p, int v)
{
    return func_020188B4(p, v);
}








/*
 *           func_0201897C
 *
 * The three functions at 0x020189D0, 0x020189D8 and 0x020189F0 sit between
 * this file and src/matched/unit_02018A00.c and are a documented near miss:
 * every concrete byte of them is reproduced, but func_020189F0 loads the
 * s8[][5] table at 0x0209E2A4 and the only word in the image that holds that
 * address is the pool word under test, so no cut attests it.  See
 * docs/idioms/a-string-after-a-data-table-has-no-witness.md for the same
 * shape on a string.
 */
u32 func_020188B4(void *p, s32 v)
{
    u16 a = (u16)func_02017E88(p, 5, 0);
    u16 b = (u16)func_02017E88(p, 0x6F, 0);

    return func_020188E0(a, b, v);
}








u32 func_020188E0(u16 a, u16 b, s32 v)
{
    u32 r;

    if (a == 0x28A) {
        r = 0;
    } else if (func_02019C90(a, b, v / 32 + 0x27) & (1 << (v % 32))) {
        r = 1;
    } else {
        r = 0;
    }
    return r;
}








u32 func_0201891C(void *p, s32 v)
{
    u16 a = (u16)func_02017E1C(p, 5, 0);
    u16 b = (u16)func_02017E1C(p, 0x6F, 0);

    return func_02018948(a, b, v);
}








u32 func_02018948(u16 a, u16 b, s32 v)
{
    u32 r;

    if (a == 0x28A) {
        r = 0;
    } else if (func_02019C90(a, b, 0x2B) & (1 << (v % 32))) {
        r = 1;
    } else {
        r = 0;
    }
    return r;
}








u32 func_0201897C(struct Hdr *p)
{
    u32 r;
    struct RecA *a;
    struct RecB *b;
    struct RecC *c;

    func_02018D10((struct Pokemon *)p);
    r = 0;
    a = func_02019C38((struct Pokemon *)p, p->unk00, 0);
    b = func_02019C38((struct Pokemon *)p, p->unk00, 1);
    c = func_02019C38((struct Pokemon *)p, p->unk00, 2);
    if (a->unk1C != 0 || b->unk14 != 0 || c->unk18 != 0) {
        r = 1;
    }
    func_02018D6C((struct Pokemon *)p);
    return r;
}






int func_020189D0(void *m, int b)
{
    return func_020189D8(m, b);
}







s8 func_020189D8(void *m, u32 a1)
{
    return func_020189F0((u8)func_02017E88(m, 0x70, 0), a1);
}








/*
 * The nature table lookup: a signed byte out of the s8[25][5] table at
 * 0x0209E2A4 (row = nature, column = stat).  func_020189D8 is the one
 * caller, and it truncates the nature to u8 at the call.  Wave 11,
 * 2026-09-23.
 *
 * Closes the "one byte the language cannot express" of
 * docs/notes/func_020189F0.c.txt: earlier lanes read the SECOND argument as
 * a base pointer (`b[o + (u32)tbl]`), which makes the scaled index the
 * running operand of the final add.  It is an integer column index and the
 * natural two-dimensional subscript gives the image's `adds r0, r0, r2`
 * (table as accumulator) directly.
 */
s8 func_020189F0(u8 nature, u32 stat)
{
    return tbl_0209E2A4[nature][stat];
}








/*
 * The two functions after src/matched/unit_020188B4.c and the three that its
 * header records as a near miss.  func_02018A00 is the eight byte
 * `ldr r3, [pc, #0]; bx r3` tail call that
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md describes; its callee is the
 * next function in this same range, so the site is the `local` class.
 */
void func_02018A00(void *p, u32 a, u32 b)
{
    func_02018A08(p, a, b);
}








void func_02018A08(void *p, u32 a, u32 b)
{
    void *h;
    u32 t;
    u32 k;
    u32 v;

    v = func_02019C90((u16)a, (u16)b, 0x1C);
    if (v != 0) {
        func_02017E64(p, 0xA, v);
        func_02017E64(p, 0x71, 1);
        return;
    }
    h = func_02019C54((u16)a, (u16)b);
    t = func_02017E88(p, 0, 0);
    k = 0x1A;
    if (func_02019C7C(h) == 2 && (t & (1 << 16))) {
        k = 0x1B;
    }
    func_02017E64(p, 0xA, func_0201AE1C(h, k));
}








/*
 * 660 bytes, one function, no jump table.
 *
 * The six-stat recalculation of poke_tool.c, and the only thing in the region
 * that reads and writes the record through both halves of the dispatcher
 * quartet at once.  It takes no arguments but the record pointer: everything
 * it needs is read back through func_02017E1C (src/matched/unit_02017E1C.c)
 * and everything it produces is written through func_02017E40
 * (src/matched/unit_02017E40.c), so the whole function is seventeen reads, a
 * base-stat table lookup, six formulas and six writes.
 *
 * Its single caller is func_020185C4 (src/pending/unit_020185C4.c), which was
 * MATCH-capped on exactly this address; with this entry EXACT the `matched`
 * class carries that site and the parked file graduates.
 *
 * ---------------------------------------------------------------------------
 * THE IDS, AND WHERE THE FIELD MAP FOR THEM IS
 * ---------------------------------------------------------------------------
 * The party-area ids are func_02018DB4's (src/matched/sub_02018DB4.c) and the
 * block-area ids are func_02018E34's (src/pending/sub_02018E34.c, whose header
 * carries the full map).  What this function uses:
 *
 *   read  0x9E  level          0xA1  current max HP   0xA0  current HP
 *   read  0x46..0x4B           the six 5 bit IVs, in stat order
 *   read  0x0D..0x12           the six effort values, capped at 510 together
 *   read  0x6F  form           0x05  species
 *   write 0xA1  max HP
 *   write 0xA2..0xA6           attack, defence, speed, sp. attack, sp. defence
 *   write 0xA0  current HP, and only when the result is non zero
 *
 * func_02019C54(species, form) returns the species' base-stat record and the
 * first six bytes of it are the six base stats, indexed here in the same order
 * the ids are: HP, attack, defence, speed, sp. attack, sp. defence.  The
 * nature multiplier func_02019B04 (src/matched/unit_02019B04.c) is indexed
 * differently, 1, 2, 5, 3, 4 for that same sequence, so its table is in
 * attack, defence, sp. attack, sp. defence, speed order.  That permutation is
 * in the game and not in this reconstruction; the two orderings are visible
 * side by side in the five `movs r2, #k` immediates.
 *
 * The formulas are the ordinary third-generation-onwards ones, in signed
 * arithmetic throughout (the divides are `_s32_div_f`, and `ev / 4` carries
 * the rounding correction a signed shift needs):
 *
 *   max HP = (base * 2 + iv + ev / 4) * level / 100 + level + 10
 *   stat   = ((base * 2 + iv + ev / 4) * level / 100 + 5) scaled by nature
 *
 * Species 292 is the exception: its max HP is 1 and its current HP is 1,
 * whatever its level, IVs or EVs are.  The constant appears twice and the
 * compiler materialises it two different ways, `0x6F + 0xB5` off the id
 * constant that is still live from the id 0x6F read, and `0x49 << 2` in the
 * tail where nothing is live; both are written `292` in the source.
 *
 * ---------------------------------------------------------------------------
 * THE THREE THINGS THAT COST THE MOST TIME
 * ---------------------------------------------------------------------------
 * **The nature multiplier's first argument is a named local.**  Written
 * inline, `func_02019B04(func_02018598(p), (u16)stat, k)`, the first three
 * stats are byte for byte right and the last two are not: the compiler hoists
 * the `bl func_02018598` in front of the arithmetic, which costs the `adds r5,
 * r0, #5` its fold and adds three instructions per stat, twelve bytes and 203
 * concrete bytes in total.  Binding the call result to a local before the
 * outer call, `nature = func_02018598(p);`, pins the evaluation order for all
 * five and is EXACT.  This is the store form of
 * docs/idioms/a-store-that-lands-after-the-next-call-names-a-local-temporary.md
 * seen at an argument rather than at a field, and the new file
 * docs/idioms/an-inline-call-argument-is-scheduled-per-site-a-local-is-not.md
 * records it, because the asymmetry (three sites right, two wrong, from one
 * source shape) is what makes it expensive to read back.
 *
 * **The named local also decides the two callee-saved registers.**  With the
 * call inline, level lands in r7 and the current HP in r6; with `nature`
 * bound, they are the original's r6 and r7.  Nothing about the register
 * numbering points at the argument that caused it.
 *
 * **Max HP is two statements, not one.**  The original stores the running
 * value into the max-HP slot, adds ten, and stores it again; the dead first
 * store is what says the source wrote `newMax = ... + level;` and then
 * `newMax = newMax + 10;`.  Written as one expression the `+ 10` folds into
 * the same instruction stream, the first `str` disappears, and the species 292
 * arm's `b` then cross-jumps onto a different store.
 *
 * The five IVs and five EVs that reach the stack are grouped, all five IVs at
 * sp+0x30 down to sp+0x20 and then all five EVs at sp+0x1C down to sp+0x0C,
 * which is what says they were declared in two runs rather than interleaved in
 * the order they are read; declared read-interleaved every slot is right by
 * four bytes and nothing else moves.  See
 * docs/idioms/local-declaration-order-is-stack-order.md.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * One content id: 292, the species whose max HP is forced to 1.  It appears
 * twice, at the max-HP branch and in the current-HP tail.  Black and White
 * share their species numbering, so it is expected to be identical in IRAO,
 * but it is the one number to re-read.  Everything else here is a structure
 * offset, a stat index or a formula constant (2, 4, 100, 5, 10), and the stat
 * formulas themselves are content in the sense that they decide the game's
 * numbers: if a White build ever diverges here, it diverges on 292 or on the
 * base-stat table func_02019C54 hands back, not on this code.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/sub_02018A7C.c \
 *       --func func_02018A7C --addr 0x02018A7C --cc 1.1p1
 */
void func_02018A7C(void *p)
{
    s32 cur;
    s32 level;
    s32 form;
    s32 iv0;
    s32 oldMax;
    s32 iv1;
    s32 iv2;
    s32 iv3;
    s32 iv4;
    s32 iv5;
    s32 ev1;
    s32 ev2;
    s32 ev3;
    s32 ev4;
    s32 ev5;
    s32 species;
    const u8 *base;
    s32 newMax;
    s32 ev0;
    s32 stat;
    u32 nature;
    s32 delta;

    level = func_02017E1C(p, 0x9E, 0);
    oldMax = func_02017E1C(p, 0xA1, 0);
    cur = func_02017E1C(p, 0xA0, 0);
    iv0 = func_02017E1C(p, 0x46, 0);
    ev0 = func_02017E1C(p, 0x0D, 0);
    iv1 = func_02017E1C(p, 0x47, 0);
    ev1 = func_02017E1C(p, 0x0E, 0);
    iv2 = func_02017E1C(p, 0x48, 0);
    ev2 = func_02017E1C(p, 0x0F, 0);
    iv3 = func_02017E1C(p, 0x49, 0);
    ev3 = func_02017E1C(p, 0x10, 0);
    iv4 = func_02017E1C(p, 0x4A, 0);
    ev4 = func_02017E1C(p, 0x11, 0);
    iv5 = func_02017E1C(p, 0x4B, 0);
    ev5 = func_02017E1C(p, 0x12, 0);
    form = func_02017E1C(p, 0x6F, 0);
    species = func_02017E1C(p, 0x05, 0);
    base = func_02019C54((u16)species, (u16)form);

    if (species == 292) {
        newMax = 1;
    } else {
        newMax = (base[0] * 2 + iv0 + ev0 / 4) * level / 100 + level;
        newMax = newMax + 10;
    }
    func_02017E40(p, 0xA1, newMax);

    stat = (base[1] * 2 + iv1 + ev1 / 4) * level / 100 + 5;
    nature = func_02018598(p);
    func_02017E40(p, 0xA2, func_02019B04(nature, (u16)stat, 1));

    stat = (base[2] * 2 + iv2 + ev2 / 4) * level / 100 + 5;
    nature = func_02018598(p);
    func_02017E40(p, 0xA3, func_02019B04(nature, (u16)stat, 2));

    stat = (base[3] * 2 + iv3 + ev3 / 4) * level / 100 + 5;
    nature = func_02018598(p);
    func_02017E40(p, 0xA4, func_02019B04(nature, (u16)stat, 5));

    stat = (base[4] * 2 + iv4 + ev4 / 4) * level / 100 + 5;
    nature = func_02018598(p);
    func_02017E40(p, 0xA5, func_02019B04(nature, (u16)stat, 3));

    stat = (base[5] * 2 + iv5 + ev5 / 4) * level / 100 + 5;
    nature = func_02018598(p);
    func_02017E40(p, 0xA6, func_02019B04(nature, (u16)stat, 4));

    if (cur != 0 || oldMax == 0) {
        if (species == 292) {
            cur = 1;
        } else if (cur == 0) {
            cur = newMax;
        } else {
            delta = newMax - oldMax;
            if (delta < 0) {
                if (cur > newMax) {
                    cur = newMax;
                }
            } else {
                cur = cur + delta;
            }
        }
    }
    if (cur != 0) {
        func_02017E40(p, 0xA0, cur);
    }
}







/*
 * The four lock/unlock helpers every accessor wrapper in this region opens and
 * closes with.  The object is the same record as src/matched/unit_02017D30.c:
 * a seed word at +0x00, three flag bits at +0x04, a halfword checksum at
 * +0x06, an 0x80 byte area at +0x08 and a 0x54 byte area at +0x88, each
 * area XOR masked in place by func_02019A50.  Bit 2 of +0x04 is the sticky
 * "checksum did not match" flag func_02018D34 sets.
 *
 * The three flag tests are `lsls`/`lsrs` pairs of width one, which is the
 * bitfield shape of docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md;
 * spelling them as masks gives movs/ands instead.
 */
u32 func_02018D10(struct Pokemon *p)
{
    u32 r = 1;

    if (p->b0 == 0) {
        func_02019A50((u16 *)&p->unk88, 0x54, p->unk00);
        r = func_02018D34(p);
    }
    return r;
}





u32 func_02018D34(struct Pokemon *p)
{
    u32 r = 1;
    u16 sum;

    if (p->b1 == 0) {
        func_02019A50((u16 *)p->unk08, 0x80, p->unk06);
        sum = func_02019A9C((const u16 *)p->unk08, 0x80);
        if (sum != p->unk06) {
            r = 0;
            p->b2 = 1;
        }
    }
    return r;
}





void func_02018D6C(struct Pokemon *p)
{
    if (p->b0 == 0) {
        func_02019A50((u16 *)&p->unk88, 0x54, p->unk00);
        func_02018D8C(p);
    }
}





void func_02018D8C(struct Pokemon *p)
{
    if (p->b1 == 0) {
        p->unk06 = func_02019A9C((const u16 *)p->unk08, 0x80);
        func_02019A50((u16 *)p->unk08, 0x80, p->unk06);
    }
}






/*
 * The party-data half of the record's read accessor, and the outer half of the
 * get/set dispatcher quartet of poke_tool.c.  The record is the 0xDC byte
 * structure src/matched/unit_02017D30.c and src/matched/unit_02018D10.c
 * describe: a seed word at +0x00, three flag bits and a checksum at +0x04, an
 * 0x80 byte XOR masked block area at +0x08 and an 0x54 byte XOR masked party
 * area at +0x88.  This function owns the twelve ids that live in the party
 * area, 0x9D to 0xA8, and tail calls func_02018E34 for everything else, which
 * is the 176 case accessor over the block area (src/pending/sub_02018E34.c).
 *
 * The twelve ids are a dense switch from 0x9D, so the `cmp r3, #0xb` / `bhi` /
 * `add pc, r3` preamble and the twelve halfword table come out of a plain C
 * switch; see docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md.
 * Only 0xA7 and 0xA8 have bodies that are not a field load: 0xA7 copies the
 * 0x38 byte object at +0x9C out through the third argument with
 * sub_02008F3C (the same whole-object copy src/matched/unit_02008F80.c
 * describes), and 0xA8 returns 1 with no field at all.  Both return 1 out of
 * their own `movs r0, #1` / `pop`, not a shared one.
 *
 * The setter half is func_02019308, src/matched/sub_02019308.c, which has the
 * same twelve ids in the same order over the same offsets.
 *
 * Nothing here is version specific: the ids are structure offsets, not species
 * or version tables.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/sub_02018DB4.c \
 *       --func func_02018DB4 --addr 0x02018DB4 --cc 1.1p1
 */
u32 func_02018DB4(struct Pokemon *p, u32 id, u32 v)
{
    switch (id) {
    case 0x9D: return p->unk88;
    case 0x9E: return p->unk8C;
    case 0x9F: return p->unk8D;
    case 0xA0: return p->unk8E;
    case 0xA1: return p->unk90;
    case 0xA2: return p->unk92;
    case 0xA3: return p->unk94;
    case 0xA4: return p->unk96;
    case 0xA5: return p->unk98;
    case 0xA6: return p->unk9A;
    case 0xA7:
        sub_02008F3C((const struct Sub02008F80Obj *)(&p->unk9C), (struct Sub02008F80Obj *)v);
        return 1;
    case 0xA8:
        return 1;
    }
    return func_02018E34((struct Pokemon *)p, id, v);
}





/*
 * 1236 bytes, one function, a 176 case jump table.  The read accessor over
 * the encrypted block area of the 0xDC byte record, and the larger half of
 * poke_tool.c's get/set dispatcher quartet.  func_02018DB4
 * (src/matched/sub_02018DB4.c) owns ids 0x9D to 0xA8 and forwards everything
 * else here; the writer twin is func_02019388 (src/matched/sub_02019388.c).
 *
 * Of the eighteen relocation sites, three are calls to 0x0209C074 (_ll_shl,
 * the compiler's own 64 bit shift helper) and one is to func_02019BBC; a scan
 * of every Thumb BL and BLX in the image finds those four sites and no
 * others, all four inside this one function, so neither the `label` nor
 * `matched` class alone ever had an outside witness for both.  func_02019BBC
 * resolves via the `matched` class (src/matched/unit_02019B58.c, an EXACT
 * entry proved over a range this file does not touch); 0x0209C074 resolves
 * via the `runtime` class, layout/runtime_arm9.txt's curated identification
 * of the MSL/runtime.a routines mwccarm links in, which carries the same
 * evidentiary standing as an SDK symbol without needing a label or an
 * outside call.  See docs/AGENT-BRIEF.md's attestation section.
 *
 * ---------------------------------------------------------------------------
 * THE FIELD MAP
 * ---------------------------------------------------------------------------
 * func_02019C38(p, p->unk00, n) returns the n-th of four 0x20 byte substructs
 * inside the 0x80 byte block area at +0x08, permuted by the seed word; so the
 * four pointers a, b, c, d below are the substructs and every id is one field
 * of one of them.  Ids not listed fall to `default` and read back 0.
 *
 *   id         where                       what the code does
 *   0x00       record +0x00 u32            the seed word
 *   0x01/02/03 record +0x04 bits 0/1/2     the three lock flags
 *   0x04       record +0x06 u16            the block-area checksum
 *   0x05       A +0x00 u16                 species; 650 when flag bit 2 is set
 *   0x06       A +0x02 u16                 held item; 0 when above 626
 *   0x07       A +0x04 u32
 *   0x08       A +0x08 u32                 experience
 *   0x09       A +0x0C u8
 *   0x0A       A +0x0D u8                  ability (see 0xAE below)
 *   0x0B       A +0x0E u8
 *   0x0C       A +0x0F u8
 *   0x0D..0x12 A +0x10..0x15 u8 x6         the six the setter caps at 510 total
 *   0x13..0x18 A +0x16..0x1B u8 x6
 *   0x19..0x35 A +0x1C u32                 29 flag bits, bit (id - 0x19)
 *   0x36..0x39 B +0x00 u16[4]
 *   0x3A..0x3D B +0x08 u8[4]
 *   0x3E..0x41 B +0x0C u8[4]
 *   0x42..0x45 derived                     func_0201C158(B move[i], B +0x0C[i])
 *                                          when the move is non zero, else 0
 *   0x46..0x4B B +0x10 bits 0..29          six 5 bit fields
 *   0x4C       B +0x10 bit 30              1 when flag bit 2 is set
 *   0x4D..0x6C B +0x14 u32                 32 flag bits, bit (id - 0x4D)
 *   0x6D       B +0x18 bit 0
 *   0x6E       derived, and it WRITES      func_02017F50(species, form, seed),
 *                                          stored into B +0x18 bits 1..2, then
 *                                          the block-area checksum is recomputed
 *   0x6F       B +0x18 bits 3..7           form
 *   0x70       B +0x19 u8
 *   0x71       B +0x1A bit 0
 *   0x72       B +0x1C u32
 *   0x73       C +0x00                     copied out through the third
 *                                          argument, or the id 651 string from
 *                                          the bank at 0x020A7370 when flag
 *                                          bit 2 is set
 *   0x74       C +0x00                     the same, length 11
 *   0x75       B +0x10 bit 31
 *   0x76       C +0x16 u8
 *   0x77       C +0x17 u8
 *   0x78..0x8C C +0x18 u64                 21 flag bits, bit (id - 0x78)
 *   0x8D/0x8E  D +0x00                     copied out, length 8 for 0x8E
 *   0x8F..0x94 D +0x10..0x15 u8 x6
 *   0x95       D +0x16 u16
 *   0x96       D +0x18 u16
 *   0x97       D +0x1A u8
 *   0x98       D +0x1B u8
 *   0x99       D +0x1C bits 0..6
 *   0x9A       D +0x1C bit 7
 *   0x9B       D +0x1D u8
 *   0x9C       D +0x1E u16
 *   0x9E       derived                     func_0201850C(species, form, exp)
 *   0x9D, 0x9F..0xA8                       gaps here; the party area, owned by
 *                                          func_02018DB4
 *   0xA9       derived                     species != 0
 *   0xAA       derived                     flag bit 2, else B +0x10 bit 30
 *   0xAB       derived                     species, or 650 when it is an egg
 *                                          or flag bit 2 is set
 *   0xAC       derived                     B +0x10 bits 0..29 repacked
 *   0xAD       derived                     0 for species 29 or 32 with
 *                                          B +0x10 bit 31 clear, else 1
 *   0xAE/0xAF  derived                     func_02019BBC(item) for species 493
 *                                          with A +0x0D == 121, otherwise
 *                                          func_02019C90(species, form,
 *                                          id - 0xA8)
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * Six numeric constants in this function are content ids rather than structure
 * offsets, and they are the only things here that could differ between the two
 * paired versions: 650 (ids 0x05 and 0xAB), 651 (the string id for ids 0x73
 * and 0x74), 626 (the item ceiling for id 0x06), 493 and 121 (the species and
 * ability that select the item-derived type at ids 0xAE and 0xAF) and 29 and
 * 32 (the two species id 0xAD special cases).  There is no
 * version-exclusive-species table and no version flag anywhere in this
 * function; Black and White share their species, item and ability numbering,
 * so all six are expected to be identical in IRAO, but they are the addresses
 * to re-read first if a White build diverges here.  The message bank pointer
 * at 0x020A7370 is a global, so its address will differ between builds and
 * must be re-derived rather than copied.
 *
 * ---------------------------------------------------------------------------
 * WHAT PINNED THE SOURCE
 * ---------------------------------------------------------------------------
 * The 176 entry halfword table is read as
 * docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md: the entries
 * that point at the default body are the ids with no case label, and the
 * addresses the other entries point at, sorted, are the source order of the
 * arms.  That order is not the numeric order and reconstructing it is most of
 * the work: the switch opens with `default`, then 0x00 to 0x04, then 0xA9,
 * 0xAA, 0xAB and 0x9E, and only then 0x05 onwards, with 0x75 sitting between
 * 0x4C and the 0x4D group.  Writing the arms in numeric order instead is a
 * whole-function diff with the size still exactly right.
 *
 * Three further details each cost bytes:
 *
 *   * `u32 r = 0;` has to be declared before the four substruct calls and
 *     `u32 ok = 1;` after them.  The original's `movs r4, #0` sits in front of
 *     the first call and its `str r2, [sp, #8]` just after it, and the two
 *     stack slots are assigned in that declaration order, which is
 *     docs/idioms/local-declaration-order-is-stack-order.md.
 *   * `default:` has to be the first arm written, not a statement after the
 *     switch.  Written after the switch its block lands at the end and all 176
 *     displacements move.
 *   * ids 0x4C and 0xAA are the same two-line test and both have to be written
 *     `r = p->b2; if (r == 0) { r = b->iv6; }`, so that the flag bit lands
 *     directly in the result register.  Written as
 *     `if (p->b2 != 0) { r = 1; } else { r = b->iv6; }` the compiler computes
 *     the bit into a scratch register and 0x4C loses the two byte `b` to the
 *     shared exit that id 0x42's `beq` needs to reach, which turns that `beq`
 *     into a `bne` plus a long `b` and shifts everything after it by two.
 *
 * The three 64 bit flag-bit tests are one shape: `((u64)ok << n) & field`,
 * with the field zero extended, compared against zero in 64 bits.  The u64 is
 * what calls 0x0209C074 (_ll_shl).
 *
 * Verified with
 *   python tools/match.py one --src src/pending/sub_02018E34.c \
 *       --func func_02018E34 --addr 0x02018E34 --cc 1.1p1
 */
u32 func_02018E34(struct Pokemon *p, u32 id, u32 v)
{
    u32 r = 0;
    struct BlockA *a = (struct BlockA *)func_02019C38((struct Pokemon *)p, p->unk00, 0);
    struct BlockB *b = (struct BlockB *)func_02019C38((struct Pokemon *)p, p->unk00, 1);
    struct BlockC *c = (struct BlockC *)func_02019C38((struct Pokemon *)p, p->unk00, 2);
    struct BlockD *d = (struct BlockD *)func_02019C38((struct Pokemon *)p, p->unk00, 3);
    u32 ok = 1;

    switch (id) {
    default:
        r = 0;
        break;
    case 0x00: r = p->unk00; break;
    case 0x01: r = p->b0; break;
    case 0x02: r = p->b1; break;
    case 0x03: r = p->b2; break;
    case 0x04: r = p->unk06; break;
    case 0xA9:
        if (a->species == 0) {
            ok = 0;
        }
        r = ok;
        break;
    case 0xAA:
        r = p->b2;
        if (r == 0) {
            r = b->iv6;
        }
        break;
    case 0xAB:
        r = a->species;
        if (r != 0) {
            if (b->iv6 != 0 || p->b2 != 0) {
                r = 650;
            }
        }
        break;
    case 0x9E:
        r = func_0201850C(a->species, b->f2, a->exp);
        break;
    case 0x05:
        if (p->b2 != 0) {
            r = 650;
        } else {
            r = a->species;
        }
        break;
    case 0x06:
        r = a->item;
        if (r > 626) {
            r = 0;
        }
        break;
    case 0x07: r = a->otId; break;
    case 0x08: r = a->exp; break;
    case 0x09: r = a->unk0C; break;
    case 0x0A: r = a->unk0D; break;
    case 0x0B: r = a->unk0E; break;
    case 0x0C: r = a->unk0F; break;
    case 0x0D: r = a->unk10[0]; break;
    case 0x0E: r = a->unk10[1]; break;
    case 0x0F: r = a->unk10[2]; break;
    case 0x10: r = a->unk10[3]; break;
    case 0x11: r = a->unk10[4]; break;
    case 0x12: r = a->unk10[5]; break;
    case 0x13: r = a->unk16[0]; break;
    case 0x14: r = a->unk16[1]; break;
    case 0x15: r = a->unk16[2]; break;
    case 0x16: r = a->unk16[3]; break;
    case 0x17: r = a->unk16[4]; break;
    case 0x18: r = a->unk16[5]; break;
    case 0x19: case 0x1A: case 0x1B: case 0x1C: case 0x1D: case 0x1E:
    case 0x1F: case 0x20: case 0x21: case 0x22: case 0x23: case 0x24:
    case 0x25: case 0x26: case 0x27: case 0x28: case 0x29: case 0x2A:
    case 0x2B: case 0x2C: case 0x2D: case 0x2E: case 0x2F: case 0x30:
    case 0x31: case 0x32: case 0x33: case 0x34: case 0x35:
        id -= 0x19;
        if ((((u64)ok << id) & a->unk1C) == 0) {
            ok = 0;
        }
        r = ok;
        break;
    case 0x36: case 0x37: case 0x38: case 0x39:
        id -= 0x36;
        r = b->moves[id];
        break;
    case 0x3A: case 0x3B: case 0x3C: case 0x3D:
        id -= 0x3A;
        r = b->pp[id];
        break;
    case 0x3E: case 0x3F: case 0x40: case 0x41:
        id -= 0x3E;
        r = b->ppUp[id];
        break;
    case 0x42: case 0x43: case 0x44: case 0x45:
        id -= 0x42;
        if (b->moves[id] != 0) {
            r = func_0201C158(b->moves[id], b->ppUp[id]);
        }
        break;
    case 0x46: r = b->iv0; break;
    case 0x47: r = b->iv1; break;
    case 0x48: r = b->iv2; break;
    case 0x49: r = b->iv3; break;
    case 0x4A: r = b->iv4; break;
    case 0x4B: r = b->iv5; break;
    case 0x4C:
        r = p->b2;
        if (r == 0) {
            r = b->iv6;
        }
        break;
    case 0x75: r = b->iv7; break;
    case 0x4D: case 0x4E: case 0x4F: case 0x50: case 0x51: case 0x52:
    case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: case 0x58:
    case 0x59: case 0x5A: case 0x5B: case 0x5C: case 0x5D: case 0x5E:
    case 0x5F: case 0x60: case 0x61: case 0x62: case 0x63: case 0x64:
    case 0x65: case 0x66: case 0x67: case 0x68: case 0x69: case 0x6A:
    case 0x6B: case 0x6C:
        id -= 0x4D;
        if ((((u64)ok << id) & b->unk14) == 0) {
            ok = 0;
        }
        r = ok;
        break;
    case 0x6D: r = b->f0; break;
    case 0x6E:
        r = func_02017F50(a->species, b->f2, p->unk00);
        b->f1 = (u8)r;
        p->unk06 = func_02019A9C((const u16 *)p->unk08, 0x80);
        break;
    case 0x6F: r = b->f2; break;
    case 0x70: r = b->unk19; break;
    case 0x71: r = b->g0; break;
    case 0x72: r = b->unk1C; break;
    case 0x73:
        if (p->b2 != 0) {
            func_02045CAC(gMsgBank, 651, (void *)v);
        } else {
            func_02045924((void *)v, c->unk00);
        }
        break;
    case 0x74:
        if (p->b2 != 0) {
            func_02045F5C(gMsgBank, 651, (void *)v, 11);
        } else {
            func_0201F41C(c->unk00, (void *)v, 11);
        }
        break;
    case 0x76: r = c->unk16; break;
    case 0x77: r = c->unk17; break;
    case 0x78: case 0x79: case 0x7A: case 0x7B: case 0x7C: case 0x7D:
    case 0x7E: case 0x7F: case 0x80: case 0x81: case 0x82: case 0x83:
    case 0x84: case 0x85: case 0x86: case 0x87: case 0x88: case 0x89:
    case 0x8A: case 0x8B: case 0x8C:
        id -= 0x78;
        if ((((u64)ok << id) & c->unk18) == 0) {
            ok = 0;
        }
        r = ok;
        break;
    case 0x8D:
        func_02045924((void *)v, d->unk00);
        break;
    case 0x8E:
        func_0201F41C(d->unk00, (void *)v, 8);
        break;
    case 0x8F: r = d->unk10; break;
    case 0x90: r = d->unk11; break;
    case 0x91: r = d->unk12; break;
    case 0x92: r = d->unk13; break;
    case 0x93: r = d->unk14; break;
    case 0x94: r = d->unk15; break;
    case 0x95: r = d->unk16; break;
    case 0x96: r = d->unk18; break;
    case 0x97: r = d->unk1A; break;
    case 0x98: r = d->unk1B; break;
    case 0x99: r = d->h0; break;
    case 0x9A: r = d->h1; break;
    case 0x9B: r = d->unk1D; break;
    case 0x9C: r = d->unk1E; break;
    case 0xAC:
        r = b->iv0 | (b->iv1 << 5) | (b->iv2 << 10) | (b->iv3 << 15)
            | (b->iv4 << 20) | (b->iv5 << 25);
        break;
    case 0xAD:
        if ((a->species == 29 || a->species == 32) && b->iv7 == 0) {
            r = 0;
        } else {
            r = 1;
        }
        break;
    case 0xAE:
    case 0xAF:
        if (a->species == 493 && a->unk0D == 121) {
            r = func_02019BBC(a->item);
        } else {
            id -= 0xA8;
            r = func_02019C90(a->species, b->f2, id);
        }
        break;
    }
    return r;
}





/*
 * The setter twin of func_02018DB4 (src/matched/sub_02018DB4.c): the same
 * twelve party-area ids 0x9D to 0xA8 over the same offsets of the 0xDC byte
 * record, with everything else forwarded to func_02019388, the 178 case
 * writer over the block area (src/matched/sub_02019388.c).
 *
 * Two details cost the time here and both are about where the two ids that
 * store nothing send control.
 *
 * The forwarding call has to be written as `default:` inside the switch rather
 * than as a statement after it.  Written after the switch the compiler places
 * the forwarding block first, at the head of the case bodies, and every one of
 * the twelve table displacements moves.
 *
 * `case 0xA8` has to be an empty arm ending in `break`, not `return`.  Both
 * spellings produce the same twelve entry table and the same eleven bodies,
 * and they differ in one byte: the twelfth displacement.  With `break` the
 * empty arm lands on the function's last `pop`, the one the forwarding call
 * falls into; with `return` it lands on the `pop` that ends case 0xA7's body
 * instead, four bytes earlier.  The original names the last one.
 *
 * Nothing here is version specific.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/sub_02019308.c \
 *       --func func_02019308 --addr 0x02019308 --cc 1.1p1
 */
void func_02019308(struct Pokemon *p, u32 id, u32 v)
{
    switch (id) {
    case 0x9D: p->unk88 = v; return;
    case 0x9E: p->unk8C = (u8)v; return;
    case 0x9F: p->unk8D = (u8)v; return;
    case 0xA0: p->unk8E = (u16)v; return;
    case 0xA1: p->unk90 = (u16)v; return;
    case 0xA2: p->unk92 = (u16)v; return;
    case 0xA3: p->unk94 = (u16)v; return;
    case 0xA4: p->unk96 = (u16)v; return;
    case 0xA5: p->unk98 = (u16)v; return;
    case 0xA6: p->unk9A = (u16)v; return;
    case 0xA7:
        sub_02008F3C((const struct Sub02008F80Obj *)v, (struct Sub02008F80Obj *)(&p->unk9C));
        return;
    case 0xA8:
        break;
    default:
        func_02019388((struct Pokemon *)p, id, v);
        break;
    }
}



/*
 * 1736 bytes, one function, 178 case jump table.
 *
 * The write accessor over the encrypted block area of the 0xDC byte record,
 * and the largest of poke_tool.c's get/set dispatcher quartet.  func_02019308
 * (src/matched/sub_02019308.c) owns the party-area ids 0x9D to 0xA8 and
 * forwards everything else here; the reader twin is func_02018E34
 * (src/pending/sub_02018E34.c), whose header carries the full field map.  The
 * two dispatchers agree field for field, so only what is specific to writing
 * is repeated below.
 *
 * What held it open, and what closed it: two of the thirteen relocation sites
 * call func_02019ABC, both from inside this function, and a scan of every
 * Thumb BL and BLX in the image finds no third site.  The `label` class
 * therefore has no witness and no cut helps, because the range cannot be made
 * smaller than the one function that holds both calls.  The `matched` class
 * carries both: 0x02019ABC is src/matched/unit_02019ABC.c, an EXACT entry
 * proved against the original bytes over a range this file does not touch.
 *
 * ---------------------------------------------------------------------------
 * WHAT THE WRITER ADDS OVER THE READER
 * ---------------------------------------------------------------------------
 * Two ids exist here that the reader does not have, 0xB0 and 0xB1, and they
 * sit in the source between 0x74 and 0x76.  They are 0x73 and 0x74 without the
 * trailing recomputation, so the pairs read: 0x73 copies 11 halfwords into
 * substruct C and then sets C's "renamed" bit from func_02019ABC, 0xB0 copies
 * the same 11 halfwords and leaves the bit alone; 0x74 and 0xB1 are the same
 * pair through the other copier.
 *
 * Nine ids the reader answers are absent here and fall to `default`, which
 * writes nothing: 0x42 to 0x45 (derived from a move and its use count), 0x75,
 * 0x9D to 0xAB (the party area plus the derived species, egg and level
 * queries) and 0xAD to 0xAF (the derived nickname and type queries).
 *
 * Ids 0x0D to 0x12, the six bytes at A +0x10, are the only arms with real
 * logic: each sums all six, clamps the increment so that the total cannot pass
 * 510, and then clamps the single value to 255.  The comparison is signed
 * (`ble`) while the values are unsigned bytes, so the clamp has to be written
 * through an explicit signed cast or the compiler emits `bls` and the arm is
 * a byte short.
 *
 * Id 0x06 refuses any value above 626 by branching into the `default` body,
 * which is why the writer's `default` is the last arm and the reader's is the
 * first: here it is a shared do-nothing exit that two arms jump to.
 *
 * ---------------------------------------------------------------------------
 * THE TWO THINGS THAT COST THE MOST TIME
 * ---------------------------------------------------------------------------
 * **One u64 mask serves all three flag-bit groups, and its complement is
 * written `mask ^ -1`, not `~mask`.**  Ids 0x19..0x35, 0x4D..0x6C and
 * 0x78..0x8C are all `mask = 1 << n; if (v) field |= mask; else field &=
 * complement;`, with `mask` a single function-scope `u64`.  The 64 bit type is
 * what makes the two u32 fields behave the way the original does: the shift
 * stays a plain `lsls` because only the low half is ever used, while the
 * complement is emitted as the low half of a 64 bit NOT, which mwccarm builds
 * as `movs r1, #3` / `subs r1, r1, #4` / `eors` rather than as `mvns`.
 * Spelling it `~mask` gives `mvns` and 904 wrong bytes; spelling it
 * `mask ^ 0xFFFFFFFF` gives the right size but 346 wrong bytes, because the
 * constant then fits one word and the 21 bit group at C +0x18 loses its
 * second `eors`.  Declaring `mask` u32, or one mask per group, also sinks the
 * shift into both arms of the test and costs a further eight bytes.
 * Getting this wrong is also what decides the register allocation: with three
 * separate 32 bit masks the record pointer loses r7 to the id and is reloaded
 * from the frame before each of the four substruct calls.
 *
 * **Id 0xAC writes the six 5 bit fields in the order 0, 1, 2, 4, 5, 3, and the
 * value it takes them from is permuted.**  The masks the original ANDs in are,
 * in order, 0xFFFFFC1F, 0xFFFF83FF, 0xFE0FFFFF, 0xC1FFFFFF and one derived
 * from the last by `asrs #0xa`, which is 0xFFF07FFF: that is bits 5, 10, 20,
 * 25 and 15, in that order.  Matching them against the shift amounts gives
 * field[4] = (v >> 15) & 0x1F, field[5] = (v >> 20) & 0x1F and
 * field[3] = (v >> 25) & 0x1F, so the packed argument orders the last three
 * fields differently from the structure.  The reader's 0xAC is a plain
 * identity repack of the same word, so the asymmetry is real and is in the
 * game, not in this reconstruction; writing 0xAC as an identity here is 89
 * wrong bytes and four bytes long, because the derived mask becomes a fifth
 * pool word.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * Only one content id appears here, 626, the item ceiling at id 0x06, and it
 * is the same constant the reader uses.  There is no version-exclusive-species
 * table, no version flag and no message bank in this function; everything else
 * is a structure offset or a field width.  Black and White share their item
 * numbering, so 626 is expected to be identical in IRAO, but it is the one
 * number to re-read.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/sub_02019388.c \
 *       --func func_02019388 --addr 0x02019388 --cc 1.1p1
 */
void func_02019388(struct Pokemon *p, u32 id, u32 v)
{
    struct BlockA *a = (struct BlockA *)func_02019C38((struct Pokemon *)p, p->unk00, 0);
    struct BlockB *b = (struct BlockB *)func_02019C38((struct Pokemon *)p, p->unk00, 1);
    struct BlockC *c = (struct BlockC *)func_02019C38((struct Pokemon *)p, p->unk00, 2);
    struct BlockD *d = (struct BlockD *)func_02019C38((struct Pokemon *)p, p->unk00, 3);
    u32 sum;
    u64 mask;

    switch (id) {
    case 0x00: p->unk00 = v; break;
    case 0x01: p->b0 = (u16)v; break;
    case 0x02: p->b1 = (u16)v; break;
    case 0x03: p->b2 = (u16)v; break;
    case 0x04: p->unk06 = (u16)v; break;
    case 0x05: a->species = (u16)v; break;
    case 0x06:
        if (v > 626) {
            break;
        }
        a->item = (u16)v;
        break;
    case 0x07: a->otId = v; break;
    case 0x08: a->exp = v; break;
    case 0x09: a->unk0C = (u8)v; break;
    case 0x0A: a->unk0D = (u8)v; break;
    case 0x0B: a->unk0E = (u8)v; break;
    case 0x0C: a->unk0F = (u8)v; break;
    case 0x0D:
        sum = a->unk10[0] + a->unk10[1] + a->unk10[2] + a->unk10[3]
            + a->unk10[4] + a->unk10[5];
        if ((s32)(v - a->unk10[0]) > (s32)(510 - sum)) {
            v = a->unk10[0] + (510 - sum);
        }
        if (v > 255) {
            v = 255;
        }
        a->unk10[0] = (u8)v;
        break;
    case 0x0E:
        sum = a->unk10[0] + a->unk10[1] + a->unk10[2] + a->unk10[3]
            + a->unk10[4] + a->unk10[5];
        if ((s32)(v - a->unk10[1]) > (s32)(510 - sum)) {
            v = a->unk10[1] + (510 - sum);
        }
        if (v > 255) {
            v = 255;
        }
        a->unk10[1] = (u8)v;
        break;
    case 0x0F:
        sum = a->unk10[0] + a->unk10[1] + a->unk10[2] + a->unk10[3]
            + a->unk10[4] + a->unk10[5];
        if ((s32)(v - a->unk10[2]) > (s32)(510 - sum)) {
            v = a->unk10[2] + (510 - sum);
        }
        if (v > 255) {
            v = 255;
        }
        a->unk10[2] = (u8)v;
        break;
    case 0x10:
        sum = a->unk10[0] + a->unk10[1] + a->unk10[2] + a->unk10[3]
            + a->unk10[4] + a->unk10[5];
        if ((s32)(v - a->unk10[3]) > (s32)(510 - sum)) {
            v = a->unk10[3] + (510 - sum);
        }
        if (v > 255) {
            v = 255;
        }
        a->unk10[3] = (u8)v;
        break;
    case 0x11:
        sum = a->unk10[0] + a->unk10[1] + a->unk10[2] + a->unk10[3]
            + a->unk10[4] + a->unk10[5];
        if ((s32)(v - a->unk10[4]) > (s32)(510 - sum)) {
            v = a->unk10[4] + (510 - sum);
        }
        if (v > 255) {
            v = 255;
        }
        a->unk10[4] = (u8)v;
        break;
    case 0x12:
        sum = a->unk10[0] + a->unk10[1] + a->unk10[2] + a->unk10[3]
            + a->unk10[4] + a->unk10[5];
        if ((s32)(v - a->unk10[5]) > (s32)(510 - sum)) {
            v = a->unk10[5] + (510 - sum);
        }
        if (v > 255) {
            v = 255;
        }
        a->unk10[5] = (u8)v;
        break;
    case 0x13: a->unk16[0] = (u8)v; break;
    case 0x14: a->unk16[1] = (u8)v; break;
    case 0x15: a->unk16[2] = (u8)v; break;
    case 0x16: a->unk16[3] = (u8)v; break;
    case 0x17: a->unk16[4] = (u8)v; break;
    case 0x18: a->unk16[5] = (u8)v; break;
    case 0x19: case 0x1A: case 0x1B: case 0x1C: case 0x1D: case 0x1E:
    case 0x1F: case 0x20: case 0x21: case 0x22: case 0x23: case 0x24:
    case 0x25: case 0x26: case 0x27: case 0x28: case 0x29: case 0x2A:
    case 0x2B: case 0x2C: case 0x2D: case 0x2E: case 0x2F: case 0x30:
    case 0x31: case 0x32: case 0x33: case 0x34: case 0x35:
        id -= 0x19;
        mask = 1 << id;
        if (v != 0) {
            a->unk1C |= mask;
        } else {
            a->unk1C &= (mask ^ -1);
        }
        break;
    case 0x36: case 0x37: case 0x38: case 0x39:
        id -= 0x36;
        b->moves[id] = (u16)v;
        break;
    case 0x3A: case 0x3B: case 0x3C: case 0x3D:
        id -= 0x3A;
        b->pp[id] = (u8)v;
        break;
    case 0x3E: case 0x3F: case 0x40: case 0x41:
        id -= 0x3E;
        b->ppUp[id] = (u8)v;
        break;
    case 0x46: b->iv0 = v; break;
    case 0x47: b->iv1 = v; break;
    case 0x48: b->iv2 = v; break;
    case 0x49: b->iv3 = v; break;
    case 0x4A: b->iv4 = v; break;
    case 0x4B: b->iv5 = v; break;
    case 0x4C: b->iv6 = v; break;
    case 0x4D: case 0x4E: case 0x4F: case 0x50: case 0x51: case 0x52:
    case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: case 0x58:
    case 0x59: case 0x5A: case 0x5B: case 0x5C: case 0x5D: case 0x5E:
    case 0x5F: case 0x60: case 0x61: case 0x62: case 0x63: case 0x64:
    case 0x65: case 0x66: case 0x67: case 0x68: case 0x69: case 0x6A:
    case 0x6B: case 0x6C:
        id -= 0x4D;
        mask = 1 << id;
        if (v != 0) {
            b->unk14 |= mask;
        } else {
            b->unk14 &= (mask ^ -1);
        }
        break;
    case 0x6D: b->f0 = (u8)v; break;
    case 0x6E:
        b->f1 = func_02017F50(a->species, b->f2, p->unk00);
        break;
    case 0x6F: b->f2 = (u8)v; break;
    case 0x70: b->unk19 = (u8)v; break;
    case 0x71: b->g0 = (u16)v; break;
    case 0x72: b->unk1C = v; break;
    case 0x73:
        func_02045A38((struct U16Vec *)v, c->unk00, 11);
        b->iv7 = func_02019ABC((struct Pokemon *)p);
        break;
    case 0x74:
        func_0201F41C((const void *)v, c->unk00, 11);
        b->iv7 = func_02019ABC((struct Pokemon *)p);
        break;
    case 0xB0:
        func_02045A38((struct U16Vec *)v, c->unk00, 11);
        break;
    case 0xB1:
        func_0201F41C((const void *)v, c->unk00, 11);
        break;
    case 0x76: c->unk16 = (u8)v; break;
    case 0x77: c->unk17 = (u8)v; break;
    case 0x78: case 0x79: case 0x7A: case 0x7B: case 0x7C: case 0x7D:
    case 0x7E: case 0x7F: case 0x80: case 0x81: case 0x82: case 0x83:
    case 0x84: case 0x85: case 0x86: case 0x87: case 0x88: case 0x89:
    case 0x8A: case 0x8B: case 0x8C:
        id -= 0x78;
        mask = 1 << id;
        if (v != 0) {
            c->unk18 |= mask;
        } else {
            c->unk18 &= (mask ^ -1);
        }
        break;
    case 0x8D:
        func_02045A38((struct U16Vec *)v, d->unk00, 8);
        break;
    case 0x8E:
        func_0201F41C((const void *)v, d->unk00, 8);
        break;
    case 0x8F: d->unk10 = (u8)v; break;
    case 0x90: d->unk11 = (u8)v; break;
    case 0x91: d->unk12 = (u8)v; break;
    case 0x92: d->unk13 = (u8)v; break;
    case 0x93: d->unk14 = (u8)v; break;
    case 0x94: d->unk15 = (u8)v; break;
    case 0x95: d->unk16 = (u16)v; break;
    case 0x96: d->unk18 = (u16)v; break;
    case 0x97: d->unk1A = (u8)v; break;
    case 0x98: d->unk1B = (u8)v; break;
    case 0x99: d->h0 = (u8)v; break;
    case 0x9A: d->h1 = (u8)v; break;
    case 0x9B: d->unk1D = (u8)v; break;
    case 0x9C: d->unk1E = (u16)v; break;
    case 0xAC:
        b->iv0 = (u8)(v & 0x1F);
        b->iv1 = (u8)((v >> 5) & 0x1F);
        b->iv2 = (u8)((v >> 10) & 0x1F);
        b->iv4 = (u8)((v >> 15) & 0x1F);
        b->iv5 = (u8)((v >> 20) & 0x1F);
        b->iv3 = (u8)((v >> 25) & 0x1F);
        break;
    default:
        break;
    }
}
