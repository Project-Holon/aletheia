/*
 * file:     g3d_system.c
 * unit:     yes
 * function: func_02046440, func_02046788, func_020467EC, func_02046858, func_02046A94, func_02046AFC, func_02046B40, func_02046BE0, func_02046BFC, func_02046C10, func_02046C24, func_02046C88, func_02046C94, sub_02046C9C, func_02046CE0, func_02046DB8, func_02046E24, func_02046E90, func_02046EFC, func_02046F48, func_02046F50, func_02046FCC, func_02046FF8, func_020470A8, func_020470D0, func_02047180, func_02047204, DWCi_LSTlPopFront, func_02047260, func_020472F8, func_02047348, func_02047388, func_020473B8, func_020473D8, func_020473EC, func_02047400, func_02047504, func_0204754C, func_02047554, func_0204755C, func_02047564, func_0204762C, func_02047674, func_0204767C, func_02047738, func_02047788, func_02047790, func_0204779C, func_020477A4, func_020477D4, func_02047804, func_02047828, func_0204784C, func_02047888, func_020478B8, func_02047910, func_02047964, func_02047970, func_02047990, func_020479D8, func_02047A60, func_02047AC8, func_02047B4C, func_02047C04, func_02047C8C, func_02047CE4, func_02047CFC, func_02047E54, func_02047E88, func_02047F4C, func_02048010, func_020480E4, func_02048120, func_02048258, func_020482B4, func_02048330, func_02048744, func_02048918, sub_020489F4, sub_02048A00, sub_02048A0C, sub_02048A18, func_02048A24, func_02048AC4, func_02048AD0, func_02048AE8, func_02048AFC, func_02048B0C, func_02048B20, func_02048B30, func_02048B44, func_02048B54, func_02048B60, func_02048B6C, func_02048B78, func_02048B80, func_02048B88, func_02048B94, func_02048B9C, func_02048BA8, func_02048BB0, func_02048BBC, func_02048BC4, func_02048C4C, func_02048C58, func_02048C80, func_02048CA4, func_02048CCC, func_02048CDC, func_02048CEC, func_02048D00, func_02048D54, func_02048DDC, func_02048E34, func_02048F4C, func_02048F60, func_02048F74, func_02048F88, func_02048F9C, func_02049030, func_020490A8, sub_020490F4, func_0204913C, func_0204919C, func_02049238, func_02049250, func_0204932C, func_020493D4, func_0204944C, func_020494F4, func_02049578, func_020495F4, NHTTPi_GetConnection, func_0204961C, func_02049624, sub_02049658, sub_0204968C, sub_020496E4, sub_02049740, sub_0204979C, sub_02049800, sub_0204982C, sub_0204989C, sub_020498F4, func_0204994C, func_02049990, func_020499D4, func_02049A18, sub_02049B40, sub_02049B68, func_02049B90, func_02049BDC, func_02049C28, func_02049DB4, func_02049DF4, func_02049E34, func_02049E74, func_02049EB4, func_02049EF4, func_02049F34, func_02049F78, func_02049FBC, func_02049FFC, func_0204A03C, func_0204A07C, func_0204A0BC, func_0204A0FC, func_0204A13C, func_0204A17C, func_0204A1BC, func_0204A298, func_0204A380, func_0204A39C
 * address:  0x02046440
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
 *   g_02146A5C         0x02146A5C  data
 *   g_020A7EA8         0x020A7EA8  data
 *   d_020A1308         0x020A1308  data
 *   d_020A1E38         0x020A1E38  data
 *   d_020A1300         0x020A1300  data
 *   d_020A1328         0x020A1328  data
 *   func_02030734      0x02030734  arm
 *   func_0206DF14      0x0206DF14  arm
 *   G3X_InitMtxStack   0x0207DB1C  arm
 *   func_0206A700      0x0206A700  arm
 *   func_02030BBC      0x02030BBC  arm
 *   func_0206DB40      0x0206DB40  arm
 *   func_020307C8      0x020307C8  arm
 *   func_0206210C      0x0206210C  arm
 *   func_02062114      0x02062114  arm
 *   func_020613D8      0x020613D8  arm
 *   func_0206246C      0x0206246C  arm
 *   func_02062474      0x02062474  arm
 *   G3X_SetFog         0x0207DC44  arm
 *   G3X_SetClearColor  0x0207DD24  arm
 *   func_020307B0   0x020307B0  arm
 *   func_0206DB24   0x0206DB24  arm
 *   func_0206DB60   0x0206DB60  arm
 *   func_02030BC8   0x02030BC8  arm
 *   g_02148B54     0x02148B54  data
 *   g_02148B4C     0x02148B4C  data
 *   func_0207C408  0x0207C408  arm
 *   func_0207C1D0  0x0207C1D0  arm
 *   func_0207C554  0x0207C554  arm
 *   func_0206AA3C 0x0206AA3C  arm
 *   func_0206AA78 0x0206AA78  arm
 *   func_0207BCA0    0x0207BCA0  arm
 *   g_02148B98       0x02148B98  data
 *   g_02148D8C       0x02148D8C  data
 *   g_02148D98       0x02148D98  data
 *   g_02148DA4       0x02148DA4  data
 *   func_0206A884   0x0206A884  arm
 *   func_0206A8FC   0x0206A8FC  arm
 *   func_0206A854  0x0206A854  arm
 *   func_0206E964      0x0206E964  arm
 *   sG3dSystemFile  0x020A7EA8  data
 *   func_020307E0  0x020307E0  arm
 *   func_02069FF8  0x02069FF8  arm
 *   func_0206A124  0x0206A124  arm
 *   func_020862F0  0x020862F0  arm
 *   func_0206A00C  0x0206A00C  arm
 *   func_0206A12C  0x0206A12C  arm
 *   DC_FlushRange  0x020862F0  arm
 *   func_02069FD0  0x02069FD0  arm
 *   func_02069FE4  0x02069FE4  arm
 *   g_020A8140     0x020A8140  data
 *   g_020A8148     0x020A8148  data
 *   func_0206A110  0x0206A110  arm
 *   g_szG3DSystem   0x020A7EA8  data
 *   func_0206E954   0x0206E954  arm
 *   func_0206E348   0x0206E348  arm
 *   func_0206A2CC   0x0206A2CC  arm
 *   func_0206A4AC   0x0206A4AC  arm
 *   func_02069D14   0x02069D14  arm
 *   func_0206E358   0x0206E358  arm
 *   func_0206E9A4  0x0206E9A4  arm
 *   func_0206E364  0x0206E364  arm
 *   func_02069C74  0x02069C74  arm
 *   func_0206E388   0x0206E388  arm
 *   str_020A7EA8   0x020A7EA8  data
 *   func_02069E88  0x02069E88  arm
 *   func_02069F7C   0x02069F7C  arm
 *   func_0207DA8C  0x0207DA8C  arm
 *   func_0206DB80  0x0206DB80  arm
 *   NNS_G3dGlb     0x02148B4C  data
 *   MTX_LookAt     0x0207BCA0  arm
 *   g_02148C08      0x02148C08  data
 *   func_0206A9DC   0x0206A9DC  arm
 *   func_0206AA0C   0x0206AA0C  arm
 *   MI_Copy36B      0x02082B60  arm
 *   func_0206DDA4  0x0206DDA4  arm
 *   func_0207DEA4  0x0207DEA4  arm
 *   func_0206B6A4 0x0206B6A4  arm
 *   g3d_util_file  0x020A7EB8  data
 *   g_020A7EC4     0x020A7EC4  data
 *   func_02048BC4_File  0x020A7ED4  data
 *   g_02146A68     0x02146A68  data
 *   func_02078A80  0x02078A80  arm
 *   func_02078B70  0x02078B70  arm
 *   func_02048D54_File  0x020A7EE0  data
 *   FS_InitFile             0x020788AC  arm
 *   CRYPTOi__BN_lshift1     0x02078C18  arm
 *   FS_CreateFileFromMemory 0x0207A940  arm
 *   FS_SeekFile             0x02078B44  arm
 *   FS_ReadFile             0x02078B70  arm
 *   func_02034734           0x02034734  arm
 *   func_02048DDC_File      0x020A7EE0  data
 *   func_02048DDC_Msg       0x020A7EEC  data
 *   func_02048F9C_File 0x020A7EE0  data
 *   func_02078B44  0x02078B44  arm
 *   sub_020490F4_File  0x020A7EE0  data
 *   func_0204913C_File      0x020A7EE0  data
 *   func_02049250_File 0x020A7EE0  data
 *   func_02049250_Msg  0x020A7F18  data
 *   func_0204932C_File 0x020A7EE0  data
 *   func_0204932C_Msg  0x020A7F18  data
 *   func_020493D4_File 0x020A7EE0  data
 *   func_020493D4_Msg  0x020A7F18  data
 *   func_0204944C_File 0x020A7EE0  data
 *   func_0204944C_Msg  0x020A7F18  data
 *   func_020494F4_File 0x020A7EE0  data
 *   func_020494F4_Msg  0x020A7F18  data
 *   func_02049578_File 0x020A7EE0  data
 *   func_02049578_Msg  0x020A7F18  data
 *   func_0204968C  0x0204968C  arm
 *   sub_0204A380   0x0204A380  arm
 *   func_02062A4C       0x02062A4C  arm
 *   func_02040B1C       0x02040B1C  arm
 *   ENV_SetResourceSet  0x020307B0  arm
 *   func_0204979C       0x0204979C  arm
 *   func_02040B58  0x02040B58  arm
 *   func_0204982C  0x0204982C  arm
 *   func_02062A00       0x02062A00  arm
 *   g_020A135C          0x020A135C  data
 *   sub_02049A18   0x02049A18  arm
 *   func_02062B30  0x02062B30  arm
 *   func_0204169C  0x0204169C  arm
 *   func_0204162C  0x0204162C  arm
 *   func_02040AF0  0x02040AF0  arm
 *   func_020409E0  0x020409E0  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02041B6C  0x02041B6C  arm
 *   sub_02049B90   0x02049B90  arm
 *   sub_02049BDC   0x02049BDC  arm
 *   g_020A1364     0x020A1364  data
 *   func_02062AD4  0x02062AD4  arm
 *   func_02062A98  0x02062A98  arm
 *   func_0207F308  0x0207F308  arm
 *   func_0207F428  0x0207F428  arm
 *   func_0207F5B0  0x0207F5B0  arm
 *   func_0207F65C  0x0207F65C  arm
 *   func_0207F47C  0x0207F47C  arm
 *   func_0207F560  0x0207F560  arm
 *   func_0207F6A8  0x0207F6A8  arm
 *   func_0207F754  0x0207F754  arm
 *   func_02062820  0x02062820  arm
 *   func_02062670  0x02062670  arm
 *   func_02062920  0x02062920  arm
 *   func_0206267C  0x0206267C  arm
 *   func_020834C0  0x020834C0  arm
 *   sArcUtil3730   0x020A7F30  data
 *   MI_UncompressLZ8 0x020834C0 arm
 *   lbl_020A7F30     0x020A7F30 data
 */
#include "../../matched/include/Obj01315.h"
#include "../../matched/include/Obj06969.h"
#include "../../matched/include/Obj04802.h"
#include "../../matched/include/Obj03459.h"
#include "../../matched/include/Obj16033.h"
#include "../../matched/include/Obj16034.h"
#include "../../matched/include/Obj04073.h"
#include "../../matched/include/Obj09057.h"
#include "../../matched/include/Obj11417.h"
#include "../../matched/include/Obj16035.h"
#include "../../matched/include/Obj16042.h"
#include "../../matched/include/Obj16046.h"
#include "../../matched/include/Obj06972.h"
#include "../../matched/include/Obj16059.h"
#include "../../matched/include/Obj16062.h"
#include "../../matched/include/Obj17329.h"
#include "../../matched/include/Obj17330.h"
#include "../../matched/include/Obj05745.h"
#include "../../matched/include/Obj08859.h"
#include "../../matched/include/Obj17354.h"
#include "../../matched/include/Obj16074.h"
#include "../../matched/include/Obj16075.h"
#include "../../matched/include/Obj16076.h"

#define reg_G3X_DISP3DCNT   (*(volatile u16 *)0x04000060)
#define reg_G3_SWAP_BUFFERS (*(volatile u32 *)0x04000540)
#define reg_G3_VIEWPORT     (*(volatile u32 *)0x04000580)
struct S02046CE0;
struct ArcFile;
struct Up;
struct Layer_020472F8;
struct Tagged;
struct Tex;
struct P02047C8C;
struct Obj0206B6A4;
struct Holder;
struct Owner_02047970;
struct G3dOwner;
struct G3dRec;
struct Layer;
struct Rec;
struct FSFile;
struct ArcHandle;
struct NitroFileHeader;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16_0;

typedef int            BOOL;

struct Setup32 { u32 w[8]; };

struct Setup36 { u32 w[9]; };

struct Rect16  { u16 h[4]; };

typedef short          s16_1;

struct Rec {
    u16 tag;
    u16 unk_02;
    u32 unk_04;
    void *unk_08;
};

struct S02046CE0 {
    u16 unk00;
    u16 result;
    u32 *tag;
};

struct Tagged {
    u16   tag;
    u16   kind;
    void *buf;
};

struct Record {
    u8  pad00[0x14];
    u32 size;
};

struct BufHdr {
    u32 unk00;
    u32 unk04;
    u32 size;
};

struct Layer_020472F8 {
    u8  pad_00[0x1c];
    u16 pad_1c;
    u16 unk_1e;
    u16 unk_20;
};

struct Layer_02047348 {
    u8    pad_00[4];
    void *unk_04;
};

struct Ctl {
    u8  pad_00[8];
    u32 unk_08;
    u8  pad_0c[4];
    u16 unk_10;
    u8  pad_12[6];
    u32 unk_18;
    u8  pad_1c[4];
    u16 unk_20;
    u8  pad_22[0xa];
    u32 unk_2c;
    u8  pad_30[2];
    u16 unk_32;
};

typedef int s32_0;

typedef signed short   s16;

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

struct Desc_02046440 {
    u16 tag;
    u8  pad_02[2];
    u32 key;
    u32 array;
    u16 count;
};

struct G3dSlot {
    u32   unk_00;
    void *unk_04;
};

struct G3dInner {
    u32   unk_00;
    void *unk_04;
};

struct G3dSys_1 {
    u32               unk_00;
    struct G3dInner  *unk_04;
    struct G3dSlot  **slots;
};

struct Sub {
    u32 pad_00;
    u32 unk_04;
};

struct Mid {
    u32 pad_00;
    u32 unk_04;
};

struct Owner_02046440 {
    u32      pad_00;
    struct Mid *unk_04;
    struct Sub **unk_08;
};

typedef signed int     s32_1;

struct AnmRes {
    u32 f0;
    u16 numFrame;       /* +4 */
};

struct AnmObj {
    s32_1 frame;          /* +0, fx32 */
    u32 f4;
    struct AnmRes *res; /* +8 */
};

struct AnmSlot {
    u32 f0;
    struct AnmObj *obj; /* +4 */
};

struct AnmCtl {
    u32 f0;
    u32 f4;
    struct AnmSlot **slots; /* +8 */
};

struct Run {
    u32 cur;
    u32 pad_04;
    u8 *desc;
};

struct Obj {
    u32 pad_00;
    struct Run *run;
};

typedef int fx32;

typedef struct { fx32 x, y, z; } VecFx32_020479D8;

typedef VecFx32_020479D8 Blk;

struct G3dEnt {
    u16 x;
    u16 y;
    u16 z;
    u16 w;
};

struct G3dCtx {
    u8   pad00[0x10];
    void *f10;
    void *f14;
    u16  heap_id;           /* 0x18 */
    u8   pad1A[2];
    u32  mode;              /* 0x1C */
    u32  f20;
    u32  f24;
    u32  f28;
    u32  f2c;
    u32  f30;
    u32  f34;
    u32  f38;
    struct G3dEnt ent[4];   /* 0x3C */
    VecFx32_020479D8 view0; /* 0x5C */
    VecFx32_020479D8 view1;
    VecFx32_020479D8 view2;
    u32  sortMode;          /* 0x80 */
    u32  bufferMode;
    void (*f88)(void);
    u32  f8c;
    u32  f90;
    u32  f94;
    void (*f98)(void *p, u32 v);
    u32  f9c;
};

struct G3dSys {
    struct G3dCtx *obj;
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

struct Owner_02047970 {
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

struct Desc_02047970 {
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

struct LightSlot_02046440 {
    u16 unk00;
    u16 unk02;
    u16 unk04;
    u16 unk06;
};

struct LightRec {
    u8               slot;
    u8               pad01;
    struct LightSlot_02046440 val;
};

struct LightSet {
    struct LightRec *recs;
    u8               count;
};

struct Rgb555 {
    u16 r;
    u16 g;
    u16 b;
};

struct LightSlot_02048C58 {
    struct Rgb555 col;
    u16           unk06;
};

struct LightGlobal {
    u32 * volatile unk00;
    u32            unk04;
    u32            unk08;
};

struct ArcFile {
    u8 file[0x48];
};

struct ArcHandle {
    u8  file[0x48];
    u32 imageBase;
    u16 fatOffset;
    u16 count;
};

struct ArcRecord {
    u32          start;
    volatile u32 end;
};

struct FatInfo {
    u32 offset;
    u16 count;
};

struct Arc {
    u8  file[0x48];
    u32 imageBase;
    u16 fatOffset;
    u16 count;
};

struct ArcFile_0204932C {
    u8  file[0x48];
    u32 imageBase;
    u16 fatOffset;
    u16 count;
};

struct ArcFile_020493D4 {
    u8  file[0x48];
    u32 imageBase;
    u16 fatOffset;
    u16 count;
};

struct ArcFile_0204944C {
    u8  file[0x48];
    u32 imageBase;
    u16 fatOffset;
    u16 count;
};

struct ArcFile_020494F4 {
    u8  file[0x48];
    u32 imageBase;
    u16 fatOffset;
    u16 count;
};

struct ArcFile_02049578 {
    u8  file[0x48];
    u32 imageBase;
    u16 fatOffset;
    u16 count;
};

struct ArcFile_020495F4 {
    u8 raw[0x50];
};

struct Res {
    u8 pad_00[0x10];
    u32 unk_10;
    void *unk_14;
};

struct Pal {
    u8  pad00[8];
    u32 size;
    u8  data[1];
};

struct Pltt {
    u32 fmt;
    u8  pad04[4];
    u32 size;
    u32 data;
};

typedef void (*LoadFn)(u32 data, u32 dest, u32 size);

extern void *func_02030734(u16 heapID, u32 size, int clear, const char *file, int line);
extern void  func_0206DF14(void);
extern void  G3X_InitMtxStack(void);
extern void  func_0206A700(void);
extern void *func_02030BBC(u32 a0);
extern void  func_0206DB40(u32 *p);
extern void  func_020307C8(void *p, u16 heap, u32 n);
extern int func_0206210C(int v);
extern void func_02062114(u32 a, u32 b, u32 c, u32 d, u32 e);
extern void  func_020613D8(u32 mode, u32 flag);
extern int func_0206246C(int v);
extern void func_02062474(u32 a, u32 b, u32 c, u32 d);
extern void  G3X_SetFog(BOOL enable, int mode, int slope, int offset);
extern void  G3X_SetClearColor(u16 rgb, int alpha, int depth, int polygonID, BOOL fog);
extern u32 func_020307B0(void *p);
extern u32   func_0206DB24(void);
extern void *func_0206DB60(void);
extern int   func_02030BC8(u32 idx);
extern void func_0207C408(u32 a0, u32 a1, u32 a2, u32 a3, u32 s0, u32 s1, void *s2);
extern void func_0207C1D0(u32 a0, u32 a1, u32 a2, u32 a3, u32 s0, u32 s1, u32 s2, void *s3);
extern void func_0207C554(u32 a0, u32 a1, u32 a2, u32 a3, u32 s0, u32 s1, u32 s2, void *s3);
extern void func_0206AA3C(int idx, s16 a, s16 b, s16 c);
extern void func_0206AA78(int idx, u32 v);
extern void func_0207BCA0(void *a0, void *a1, void *a2, void *a3);
extern void func_0206A884(void);
extern void func_0206A8FC(void);
extern void func_0206A854(void);
extern unsigned char *func_0206E964(unsigned char *p);
extern void func_020307E0(void *p, u32 size);
extern void func_02069FF8(char *p, int a, int b);
extern void func_0206A124(int *p, int v);
extern void func_020862F0(int a, int b);
extern void func_0206A00C(struct Up *u, u32 wrap);
extern void func_0206A12C(int a, int b);
extern void func_0206A0C4(struct Tex *t, u32 *a, u32 *b);
extern u32   func_0206A17C(u8 *p);
extern void  DC_FlushRange(void *addr, u32 size);
extern int func_02069FD0(int p);
extern int func_02069FE4(int p);
extern int func_0206A110(int p);
extern int func_0206E954(int p0);
extern void *func_0206E348(struct G3dCtx *);
extern void func_0206A2CC(void *, void *);
extern void func_0206A4AC(void *, void *);
extern void func_02069D14(void *, void *);
extern void func_0206E358(struct G3dCtx *ctx, int field);
extern u8 *func_0206E9A4(u8 *p, u32 idx);
extern u32  func_0206E364(struct G3dCtx *a0, int a1, u32 a2);
extern void func_02069C74(u32 a0, int a1, u32 a2, int a3);
extern void func_0206E388(struct G3dCtx *ctx, int field);
extern void func_02069E88(void *a, void *b);
extern void func_02069F7C(u32 a, u32 b);
extern void func_0207DA8C(void);
extern void func_0206DB80(void);
extern void MTX_LookAt(const VecFx32_020479D8 *camPos, const VecFx32_020479D8 *camUp,
                       const VecFx32_020479D8 *target, MtxFx43 *mtx);
extern void  func_0206A9DC(void *p);
extern void  func_0206AA0C(VecFx32_02047A60 *p);
extern void  MI_Copy36B(const void *src, void *dst);
extern void func_0206DDA4(u32 cmd, const void *params, u32 n);
extern int func_0207DEA4(s32 *in);
extern void func_0206B6A4(struct Obj0206B6A4 *p);
extern s32 func_02078B70(struct FSFile *file, void *buffer, s32 length);
extern void func_02078A80(void *p);
extern void FS_InitFile(void *file);
extern void CRYPTOi__BN_lshift1(struct ArcFile *arc, u32 value);
extern void FS_CreateFileFromMemory(void *file, void *src, u32 size);
extern void FS_SeekFile(struct ArcHandle *arc, u32 pos, u32 origin);
extern void FS_ReadFile(struct ArcHandle *arc, void *dst, u32 size);
extern void func_02034734(const char *file, u32 line, const char *msg, ...);
extern void func_020788AC(struct ArcFile *f);
extern void func_02078C18(struct ArcFile *f, const char *path);
extern int func_02078B44(struct FSFile *file, long offset, int origin);
extern u32 func_0204968C(void *buf, u32 a1, u32 a2, u32 a3, u32 unused);
extern void *sub_0204A380(void *a0, u32 a1, u32 a2, u32 a3);
extern s32 func_02062A4C(struct NitroFileHeader *file, void **out);
extern void func_02040B1C(int index, const void *src, u32 size, u32 tile);
extern void ENV_SetResourceSet(void *p);
extern u32 func_0204979C(void *buf, u32 a1, u32 a2);
extern u32 func_02040B58(u32 index, const void *src, u32 size);
extern u32 func_0204982C(void *buf, u32 kind, u32 a2, u32 size);
extern s32 func_02062A00(struct NitroFileHeader *file, void **out);
extern u32 sub_02049A18(void *file, u32 channel, u32 a2, u32 add, u32 size, u32 flag);
extern int func_02062B30(void *file, void **out);
extern u8 func_0204169C(int channel);
extern u32 func_0204162C(int channel);
extern void func_02040AF0(u32 index, const void *src, u32 mode, u32 offset);
extern void func_020409E0(u32 index, const void *src, u32 mode, u32 offset);
extern void func_020409B4(u8 channel);
extern void func_02041B6C(u8 channel);
extern void sub_02049B90(u32 a, u32 b, u32 c, u32 zero, u32 d, u32 e, u16 f);
extern void sub_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern s32 func_02062AD4(struct NitroFileHeader *file, void **out);
extern s32 func_02062A98(struct NitroFileHeader *file, void **out);
extern void func_0207F308(void);
extern void func_0207F428(void);
extern void func_0207F5B0(void);
extern void func_0207F65C(void);
extern void func_0207F47C(void);
extern void func_0207F560(void);
extern void func_0207F6A8(void);
extern void func_0207F754(void);
extern int func_02062820(int a, int *out);
extern int   func_02062670(void *ptr, u32 val);
extern int func_02062920(u32 a, u32 *out);
extern int   func_0206267C(void *ptr, u32 val);
extern int         func_020834C0(int a0, int a1);
extern void MI_UncompressLZ8(const void *src, void *dest);
void func_02046440(u32 texMode, u32 texSize, u32 plttMode, u32 plttSize, u16 fifoSize, s16_0 heap, void (*setup)(void));
void func_02046788(void);
void func_020467EC(int p0);
void func_02046858(const u32 *src);
void func_02046A94(u32 idx, const u16 *src);
void func_02046AFC(u8 *dst);
void func_02046B40(u8 *a0);
void func_02046BE0(u32 a, u32 b);
int func_02046BFC(void);
int func_02046C10(void);
void func_02046C24(u32 mode);
void func_02046C88(void);
int func_02046C94(void);
void sub_02046C9C(struct Rec *rec, u32 mode, u32 value);
void func_02046CE0(struct S02046CE0 *out, u32 *tag);
void *func_02046DB8(u32 a0, u32 a1);
void *func_02046E24(struct Arc *a0, u32 a1);
void *func_02046E90(u32 a0, u32 a1);
void func_02046EFC(struct Tagged *p);
void *func_02046F48(struct Tagged *p);
u32 func_02046F50(struct Tagged *p, u32 sel);
void func_02046FCC(struct Tagged *p);
int func_02046FF8(int *self);
u32 func_020470A8(void *p);
int func_020470D0(u32 *p);
int func_02047180(u32 *p);
u32 func_02047204(struct Tagged *p);
asm void DWCi_LSTlPopFront(void);
int func_02047260(u32 a0, u32 *a1, u32 *a2);
int func_020472F8(struct Layer_020472F8 *layer, u32 *out);
int func_02047348(struct Layer_02047348 *layer);
u32 func_02047388(struct Layer_02047348 *layer);
u32 func_020473B8(struct Layer_02047348 *layer);
int func_020473D8(int a0);
int func_020473EC(int a0);
void *func_02047400(void *a0, u32 n, void *a2);
void func_02047504(struct Rec *p);
int func_0204754C(int *p);
int func_02047554(int *p);
int func_0204755C(int *p);
struct G3dRec *func_02047564(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
void func_0204762C(struct Rec *p);
int func_02047674(int p);
void *func_0204767C(u32 a0, u32 *a1, int a2);
void func_02047738(struct Rec *p);
int func_02047788(int *p);
int func_02047790(int *p, int i);
u16 func_0204779C(void *p);
u32 func_020477A4(struct G3dSys_1 *sys, u32 idx);
int func_020477D4(struct Owner_02046440 *owner, u32 index);
u32 func_02047804(struct AnmCtl *c, u16 idx);
u32 func_02047828(struct AnmCtl *c, u32 idx, s32_1 *frame);
u32 func_0204784C(struct AnmCtl *c, u16 idx, s32_1 *frame);
int func_02047888(int *a, int idx, int *out);
int func_020478B8(void *a, int idx, int amount);
int func_02047910(void *a, int idx, int amount);
void func_02047964(void);
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
u16 func_02048010(Util *util, const Setup *setup, struct Arc *extra);
void func_020480E4(Util *util, u32 i);
void func_02048120(Util *util, u16 index, const Setup *setup, u16 heapID);
void func_02048258(struct Owner_02047970 *owner, u16 index, struct Holder *p, u32 a4, struct Arc *a5);
void func_020482B4(struct Owner_02047970 *owner, u32 index);
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
struct LightSlot_02046440 *func_02048BC4(const struct LightSet *s, u16 heap);
u32 func_02048C4C(void *p);
void func_02048C58(struct LightSlot_02048C58 *slots);
void func_02048C80(struct LightSlot_02048C58 *slots, u8 i, struct Rgb555 *out);
void func_02048CA4(struct LightSlot_02048C58 *slots, u32 i, struct Rgb555 *in);
void func_02048CCC(struct LightSlot_02048C58 *slots, u8 i, u16 *out);
void func_02048CDC(struct LightSlot_02048C58 *slots, u32 i, u16 *in);
void func_02048CEC(u32 a, u32 b);
void func_02048D00(void *dst, u32 archive_id, u32 member, u32 mode, u32 *size_out);
void *func_02048D54(u32 archive_id, u32 member, u16 heap, u32 mode, u32 *size_out);
void func_02048DDC(struct ArcFile *arc, u32 id);
u32 func_02048E34(struct ArcHandle *arc, u32 member, u32 base, u32 size);
void func_02048F4C(void *dst, u32 archive_id, u32 member);
void *func_02048F60(u32 archive_id, u32 member, u16 heap);
void func_02048F74(void *dst, u32 archive_id, u32 member, u32 mode, u32 *size_out);
void *func_02048F88(u32 archive_id, u32 member, u16 heap, u32 mode, u32 *size_out);
void *func_02048F9C(const char *path, u32 a, u16 heap);
u32 func_02049030(u32 a);
u32 func_020490A8(u32 a, u32 b);
void *sub_020490F4(u32 id, u16 heap);
void *func_0204913C(void *a0, u32 a1, u16 heap);
void func_0204919C(u8 *p);
asm void func_02049238(void *arc);
void *func_02049250(struct Arc *arc, u32 member, u16 heap);
void func_0204932C(struct ArcFile_0204932C *arc, u32 member, void *dst);
u32 func_020493D4(struct ArcFile_020493D4 *arc, u32 member);
void func_0204944C(struct ArcFile_0204944C *arc, u32 member, u32 offset, u32 size, void *dst);
void func_020494F4(struct ArcFile_020494F4 *arc, u32 member, u32 *out);
u32 func_02049578(struct ArcFile_02049578 *arc, u32 member);
void func_020495F4(struct ArcFile_020495F4 *arc, u32 size, void *dst);
asm void NHTTPi_GetConnection(void);
u16 func_0204961C(void *obj);
u32 func_02049624(void *a0, void *a1, void *a2, void *a3, u32 a4, u32 a5, u16 a6);
u32 sub_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
u32 sub_0204968C(void *buf, u32 a1, u32 a2, u32 a3, u32 unused);
u32 sub_020496E4(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
u32 sub_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
u32 sub_0204979C(void *buf, u32 a1, u32 a2);
u32 sub_02049800(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
u32 sub_0204982C(void *buf, u32 kind, u32 a2, u32 size);
void sub_0204989C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 flags);
void sub_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
u32 func_0204994C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
u32 func_020499D4(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
u32 func_02049A18(void *file, u32 channel, u32 a2, u32 add, u32 size, u32 flag);
void sub_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
void sub_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
void func_02049B90(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
void func_02049C28(void *file, u32 kind, u32 offset, u32 dest, u32 size);
void *func_02049DB4(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
void *func_02049DF4(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
void *func_02049E34(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
void *func_02049E74(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
void *func_02049EB4(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
void *func_02049EF4(void *a0, u32 a1, u32 a2, void **out, u16 a4);
void *func_02049F34(u32 a0, u32 a1, u32 a2, u16 a3);
void *func_02049F78(void *a0, u32 a1, u32 a2, u16 a3);
void *func_02049FBC(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
void *func_02049FFC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
void *func_0204A03C(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
void *func_0204A07C(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
void *func_0204A0BC(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
void *func_0204A0FC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
void *func_0204A13C(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
void *func_0204A17C(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
int func_0204A1BC(int a0, int a1, int a2, u16 a3);
int func_0204A298(int a0, int a1, int a2, u16 a3, u32 *out);
void *func_0204A380(void *a0, u32 a1, u32 a2, u16 a3);
void *func_0204A39C(void *narc, int fileId, int decompress, u32 heapId, u32 *out_size);
extern struct G3dSys g_02146A5C;
extern char g_020A7EA8[];
extern const struct Setup32 d_020A1308;
extern const u8 d_020A1E38[];
extern const struct Rect16 d_020A1300;
extern const struct Setup36 d_020A1328;
extern u8  g_02148B54[];
extern u32 g_02148B4C[];
extern Blk g_02148D8C;
extern Blk g_02148D98;
extern Blk g_02148DA4;
extern Blk g_02148B98;
extern u8 sG3dSystemFile;
extern char g_szG3DSystem[];
extern char        str_020A7EA8[];
extern NNSG3dGlb NNS_G3dGlb;
extern u32 g_02148C08[];
extern const char g3d_util_file[];
extern char  g_020A7EC4[];
extern const char func_02048BC4_File[];
extern struct LightGlobal g_02146A68;
extern const char func_02048D54_File[];
extern const char func_02048DDC_File[];
extern const char func_02048DDC_Msg[];
extern const char func_02048F9C_File[];
extern const char sub_020490F4_File[];
extern const char func_0204913C_File[];
extern const char func_02049250_File[];
extern const char func_02049250_Msg[];
extern const char func_0204932C_File[];
extern const char func_0204932C_Msg[];
extern const char func_020493D4_File[];
extern const char func_020493D4_Msg[];
extern const char func_0204944C_File[];
extern const char func_0204944C_Msg[];
extern const char func_020494F4_File[];
extern const char func_020494F4_Msg[];
extern const char func_02049578_File[];
extern const char func_02049578_Msg[];
extern const LoadFn g_020A1364[];
extern const char  sArcUtil3730[];
extern const char lbl_020A7F30[];











/*
 * The g3d_system.c constructor (line 92 allocation): allocates the 0xA0
 * context into g_02146A5C, brings up the geometry engine, optionally
 * sizes the command FIFO buffer (clamped to 0x1800), sets up texture and
 * palette VRAM managers (or the fixed-bank mode when the mode argument is
 * non-zero; note the palette arm's else-branch clears +0x14, not +0x10,
 * as the image does), pushes the default projection, four viewport
 * rectangles and the three view blocks, and finally either calls the
 * caller's setup hook or applies the SDK defaults (G3X_SetShading(0),
 * AntiAlias/AlphaTest/AlphaBlend/EdgeMarking off, G3X_SetFog off,
 * G3X_SetClearColor(0, 0, 0x7fff, 63, FALSE), G3_ViewPort(0, 0, 255, 191)).
 *
 * Written from scratch in wave 11.  Two declarations close it: the three
 * stack buffers are declared s32, s36, r (the later declaration takes the
 * lower address: sp+0x30, +0x0C, +0x04), and the heap parameter is s16
 * (tools/permuter.py, type:p(heap:u16->s16)); as u16 the compiler re-reads
 * it from its stack home instead of holding it in r8 across the first
 * allocation, and the whole body shifts by one instruction.
 */
void func_02046440(u32 texMode, u32 texSize, u32 plttMode, u32 plttSize,
                   u16 fifoSize, s16_0 heap, void (*setup)(void))
{
    struct Setup32 s32;
    struct Setup36 s36;
    struct Rect16 r;
    u32 size;

    g_02146A5C.obj = func_02030734((u16)heap, 0xa0, 0, g_020A7EA8, 0x5c);
    g_02146A5C.obj->heap_id = heap;
    g_02146A5C.obj->f8c = texMode;
    g_02146A5C.obj->f90 = plttMode;

    func_0206DF14();
    G3X_InitMtxStack();
    func_0206A700();

    if (fifoSize != 0)
        func_0206DB40(func_02030BBC(fifoSize > 0x1800 ? 0x1800 : fifoSize));

    reg_G3_SWAP_BUFFERS = 2;
    func_020307C8(g_02146A5C.obj, g_02146A5C.obj->heap_id, 4);

    if (texMode == 0) {
        size = func_0206210C(texSize << 7);
        g_02146A5C.obj->f14 = func_02030734(g_02146A5C.obj->heap_id, size, 0, g_020A7EA8, 0x7e);
        func_02062114(texSize << 17, 0, (u32)g_02146A5C.obj->f14, size, 1);
    } else {
        func_020613D8((u16)texSize, 1);
        g_02146A5C.obj->f14 = 0;
    }

    if (plttMode == 0) {
        size = func_0206246C(plttSize << 9);
        g_02146A5C.obj->f10 = func_02030734(g_02146A5C.obj->heap_id, size, 0, g_020A7EA8, 0x8d);
        func_02062474(plttSize << 14, (u32)g_02146A5C.obj->f10, size, 1);
    } else {
        func_020613D8((u16)(plttSize << 14), 1);
        g_02146A5C.obj->f14 = 0;
    }

    s32 = d_020A1308;
    s32.w[1] = *(s16_0 *)(d_020A1E38 + 0x8c);
    s32.w[2] = *(s16_0 *)(d_020A1E38 + 0x8e);
    func_02046858((const u32 *)(&s32));

    r = d_020A1300;
    func_02046A94(0, (const u16 *)(&r));
    func_02046A94(1, (const u16 *)(&r));
    func_02046A94(2, (const u16 *)(&r));
    func_02046A94(3, (const u16 *)(&r));

    s36 = d_020A1328;
    func_02046B40((u8 *)(&s36));
    func_02046BE0(0, 1);
    func_02046C24(0);

    if (setup != 0) {
        setup();
    } else {
        reg_G3X_DISP3DCNT = (u16)((reg_G3X_DISP3DCNT & ~(0x0002 | 0x3000)) | (0 << 1));
        reg_G3X_DISP3DCNT &= ~(0x0010 | 0x3000);
        reg_G3X_DISP3DCNT &= ~(0x0004 | 0x3000);
        reg_G3X_DISP3DCNT &= ~(0x0008 | 0x3000);
        reg_G3X_DISP3DCNT &= ~(0x0020 | 0x3000);
        G3X_SetFog(0, 0, 0, 0);
        G3X_SetClearColor(0, 0, 0x7fff, 63, 0);
        reg_G3_VIEWPORT = 0xBFFF0000;
    }

    g_02146A5C.obj->f98 = 0;
    g_02146A5C.obj->f9c = 0;
}










/*
 * Shut the module down: free the two owned pointers at +0x10 and +0x14 if
 * they are set, run the paired stop only when func_0206DB24 answers exactly
 * one, and finally free the context itself and null its slot.
 *
 * The context pointer is re-read from its slot for every use, so the two
 * guards each carry their own `ldr`; only the last statement caches the
 * slot's address in r4, because it needs it again for the store of zero.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02046788.c \
 *       --func func_02046788 --addr 0x02046788 --cc 1.1p1 --arm
 *
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 *
 * Every concrete byte is right; the site(s) above stay wildcarded because 0206DB24
 * has exactly one witness image wide and it is the branch inside this very range.
 * Blocking evidence class: label/matched, no outside witness.  It unsticks when the
 * callee is itself EXACT (the `matched` class) or a second caller turns up.
 *
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 * Blocking evidence class: label/matched, no outside witness.  0x0206DB24 is
 * called from this site and nowhere else the harness can see, so its PC24
 * stays wildcarded; matching 0x0206DB24 elsewhere (or a second caller)
 * closes it.
 */
void func_02046788(void)
{
    if (g_02146A5C.obj->f10 != 0)
        func_020307B0(g_02146A5C.obj->f10);
    if (g_02146A5C.obj->f14 != 0)
        func_020307B0(g_02146A5C.obj->f14);

    if (func_0206DB24() == 1) {
        func_02030BC8((u32)func_0206DB60());
    }

    func_020307B0(g_02146A5C.obj);
    g_02146A5C.obj = 0;
}












void func_020467EC(int p0){ *(int *)&((struct Obj01315 *)p0)->f0 = (int)*(int *)((*(int *)(0x2146A5C) + 28)); *(int *)&((struct Obj01315 *)p0)->f4 = (int)*(int *)((*(int *)(0x2146A5C) + 32)); *(int *)&((struct Obj01315 *)p0)->f8 = (int)*(int *)((*(int *)(0x2146A5C) + 36)); *(int *)&((struct Obj01315 *)p0)->fC = (int)*(int *)((*(int *)(0x2146A5C) + 40)); *(int *)&((struct Obj01315 *)p0)->f10 = (int)*(int *)((*(int *)(0x2146A5C) + 44)); *(int *)&((struct Obj01315 *)p0)->f14 = (int)*(int *)((*(int *)(0x2146A5C) + 48)); *(int *)&((struct Obj01315 *)p0)->f18 = (int)*(int *)((*(int *)(0x2146A5C) + 52)); *(int *)&((struct Obj01315 *)p0)->f1C = (int)*(int *)((*(int *)(0x2146A5C) + 56)); }










/*
 * Store an eight-word projection setup into the context (+0x1C mode,
 * +0x20..+0x38 parameters), then program it through one of three setup
 * calls selected by the mode; a zero +0x38 is replaced by 0x1000.  Every
 * arm clears bits 0x50 of g_02148B4C[0x3F] and returns on its own.
 *
 * Closed in wave 11.  What the older notes were missing:
 *   - the register-block pointer is taken into a named local (`hw`)
 *     BEFORE the dispatch; it is what lives in r4 across each call, which
 *     is why the image pushes r4 and can use it as the second prologue
 *     temporary (without it the push is {r3, lr} and the pipelined stores
 *     alternate ip/r3);
 *   - +0x38 selects between two calls per mode (0x1000 when zero, the
 *     field itself otherwise), not an OR with 0x1000;
 *   - mode 0 passes seven arguments (no +0x2C), modes 1 and 2 eight.
 */
void func_02046858(const u32 *src)
{
    u32 *hw;

    g_02146A5C.obj->mode = src[0];
    g_02146A5C.obj->f20 = src[1];
    g_02146A5C.obj->f24 = src[2];
    g_02146A5C.obj->f28 = src[3];
    g_02146A5C.obj->f2c = src[4];
    g_02146A5C.obj->f30 = src[5];
    g_02146A5C.obj->f34 = src[6];
    g_02146A5C.obj->f38 = src[7];
    hw = g_02148B4C;

    switch (g_02146A5C.obj->mode) {
    case 0:
        if (g_02146A5C.obj->f38 == 0) {
            func_0207C408(g_02146A5C.obj->f20, g_02146A5C.obj->f24, g_02146A5C.obj->f28, g_02146A5C.obj->f30,
                g_02146A5C.obj->f34, 0x1000, g_02148B54);
            hw[0x3F] &= ~0x50u;
            return;
        }
        func_0207C408(g_02146A5C.obj->f20, g_02146A5C.obj->f24, g_02146A5C.obj->f28, g_02146A5C.obj->f30,
            g_02146A5C.obj->f34, g_02146A5C.obj->f38, g_02148B54);
        hw[0x3F] &= ~0x50u;
        return;
    case 1:
        if (g_02146A5C.obj->f38 == 0) {
            func_0207C1D0(g_02146A5C.obj->f20, g_02146A5C.obj->f24, g_02146A5C.obj->f28, g_02146A5C.obj->f2c,
                g_02146A5C.obj->f30, g_02146A5C.obj->f34, 0x1000, g_02148B54);
            hw[0x3F] &= ~0x50u;
            return;
        }
        func_0207C1D0(g_02146A5C.obj->f20, g_02146A5C.obj->f24, g_02146A5C.obj->f28, g_02146A5C.obj->f2c,
            g_02146A5C.obj->f30, g_02146A5C.obj->f34, g_02146A5C.obj->f38, g_02148B54);
        hw[0x3F] &= ~0x50u;
        return;
    case 2:
        if (g_02146A5C.obj->f38 == 0) {
            func_0207C554(g_02146A5C.obj->f20, g_02146A5C.obj->f24, g_02146A5C.obj->f28, g_02146A5C.obj->f2c,
                g_02146A5C.obj->f30, g_02146A5C.obj->f34, 0x1000, g_02148B54);
            hw[0x3F] &= ~0x50u;
            return;
        }
        func_0207C554(g_02146A5C.obj->f20, g_02146A5C.obj->f24, g_02146A5C.obj->f28, g_02146A5C.obj->f2c,
            g_02146A5C.obj->f30, g_02146A5C.obj->f34, g_02146A5C.obj->f38, g_02148B54);
        hw[0x3F] &= ~0x50u;
        return;
    }
}









/*
 * A four-halfword record written into an eight-byte slot of the global
 * context at index `idx` (the slot base is ctx + idx*8 and the record starts
 * at +0x3c of it), then the same fields read back signed for the first
 * notification call and unsigned for the second.  The context pointer is
 * re-read from its slot once per statement group because each call may
 * replace it, which is why the field accesses are not CSE'd into one load.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02046A94.c \
 *       --func func_02046A94 --addr 0x02046A94 --cc 1.1p1 --arm
 */
void func_02046A94(u32 idx, const u16 *src)
{
    struct G3dCtx *p = (struct G3dCtx *)((u8 *)g_02146A5C.obj + idx * 8);

    p->ent[0].x = src[0];
    p->ent[0].y = src[1];
    p->ent[0].z = src[2];
    p->ent[0].w = src[3];

    func_0206AA3C(idx, g_02146A5C.obj->ent[idx].x,
                  g_02146A5C.obj->ent[idx].y,
                  g_02146A5C.obj->ent[idx].z);
    func_0206AA78(idx, g_02146A5C.obj->ent[idx].w);
}







/*
 * Copy three twelve-byte groups out of the context: +0x5c to the caller's
 * +0, +0x68 to +0xc and +0x74 to +0x18.  Each group is one nested struct
 * assignment, which this compiler emits as a paired ldm/stm of three words
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md) - three separate field
 * copies would be nine loads and nine stores.
 *
 * The context is read once: the three assignments are not separated by any
 * call, so the pointer stays live in ip, and the calling argument is kept in
 * lr while the first two destinations are built into r0/r3.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02046AFC.c \
 *       --func func_02046AFC --addr 0x02046AFC --cc 1.1p1 --arm
 */
void func_02046AFC(u8 *dst)
{
    struct G3dCtx *o = g_02146A5C.obj;

    *(VecFx32_020479D8 *)(dst + 0x00) = o->view0;
    *(VecFx32_020479D8 *)(dst + 0x0c) = o->view1;
    *(VecFx32_020479D8 *)(dst + 0x18) = o->view2;
}







void func_02046B40(u8 *a0)
{
    struct G3dCtx *o = g_02146A5C.obj;

    o->view0 = *(Blk *)a0;
    o->view1 = *(Blk *)(a0 + 0xC);
    o->view2 = *(Blk *)(a0 + 0x18);
    g_02148D8C = o->view0;
    g_02148D98 = o->view1;
    g_02148DA4 = o->view2;
    func_0207BCA0(&o->view0, &o->view1, &o->view2, &g_02148B98);
    g_02148B4C[0x3F] &= ~0xE8u;
}





/*
 * Store the pair of words at +0x80 and +0x84 of the context at 0x02146A5C.
 * The context pointer is re-read from its own slot between the two stores,
 * because the first store cannot be proven not to alias it; the second load
 * therefore goes to r0, the register the outgoing value no longer needs.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02046BE0.c \
 *       --func func_02046BE0 --addr 0x02046BE0 --cc 1.1p1 --arm
 */
void func_02046BE0(u32 a, u32 b)
{
    g_02146A5C.obj->sortMode = a;
    g_02146A5C.obj->bufferMode = b;
}






int func_02046BFC(void){ return *(int *)((*(int *)(0x2146A5C) + 140)); }




int func_02046C10(void){ return *(int *)((*(int *)(0x2146A5C) + 144)); }






/*
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 *
 * Install one of three handlers into the context's +0x88 word.  Modes 1 and
 * 2 have their own constant; mode 0 and everything else share the third
 * block, which is why the comparison chain starts at zero and the shared
 * body sits immediately after the last compare.
 *
 * The three values are code addresses: 0x0206A884 and 0x0206A8FC are
 * ordinary functions and 0x02046C88 is the eight-byte ARM tail stub
 * `ldr ip, [pc, #0]; bx ip; .word 0x0206A854` (attested as `veneer`), so the
 * mode-0 handler goes through one extra hop.
 *
 * Two of the four sites stay wildcarded: 0x0206A884 and 0x0206A8FC each have
 * exactly one witness image wide and it is the pool word inside this range.
 * Blocking evidence class: label/matched, no outside witness.  Either address
 * being matched elsewhere (`matched` class) closes it.
 *
 * The `*` is the unlabelled follower at 0x02046C88 - the tail stub itself is
 * inside this listing's extent because nothing in it saves lr.
 */
void func_02046C24(u32 mode)
{
    switch (mode) {
    case 0:
    default:
        g_02146A5C.obj->f88 = func_02046C88;
        break;
    case 1:
        g_02146A5C.obj->f88 = func_0206A884;
        break;
    case 2:
        g_02146A5C.obj->f88 = func_0206A8FC;
        break;
    }
}




void func_02046C88(void)
{
    func_0206A854();
}
















int func_02046C94(void){ return 8; }

















/*
 * Initialise a counted record: the mode picks the halfword written at +2
 * (2, 3 and 4 for modes 1, 2 and 3), then the caller's value goes into the
 * word at +4 and the constant 0x48BF into the halfword at +0.  Modes other
 * than one to three leave the +2 field alone entirely, which is why the
 * last arm stores inside its own arm and the first two meet at a shared
 * store: the comparison chain tests 1, 2 and 3 in that order and falls
 * through to the tail for everything else.
 *
 * The function saves no lr because it calls nothing, so disasm.py gives it
 * no label; 0x48BF is too wide for a `mov` and is the pool word at the end.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02046C9C.c \
 *       --func sub_02046C9C --addr 0x02046C9C --cc 1.1p1 --arm
 */
void sub_02046C9C(struct Rec *rec, u32 mode, u32 value)
{
    switch (mode) {
    case 1:
        rec->unk_02 = 2;
        break;
    case 2:
        rec->unk_02 = 3;
        break;
    case 3:
        rec->unk_02 = 4;
        break;
    }

    rec->unk_04 = value;
    rec->tag = 0x48BF;
}

















/*
 * Classify a 4-byte archive/container tag and record the result.
 *
 * `out` is a three-field record: a u16 at +00 (constant 0x48BF), a u16
 * result code at +02, and the tag pointer itself at +04.  The tag is one
 * of the little-endian ASCII magics; the five audio-ish containers
 * (BVA0/BMA0/BCA0/BTA0/BTP0) all report 4, BMD0 reports 1 or 2 depending
 * on func_0206E964, BTX0 reports 3, anything else 0.
 *
 * Shape notes:
 *  - The case bodies are laid out in *source* order, not value order.  The
 *    comparison tree is value-ordered either way, but writing BMD0 first,
 *    BTX0 second, then the five 4-reporting cases puts the BMD0 arm at
 *    +0x80 and the shared `result = 4` arm at +0xA8, which is what the
 *    original does; the natural ascending order puts the 4-arm right after
 *    the tree and moves all four branch targets.
 *  - The five 4-reporting cases share one store because the arms are
 *    identical; only the value in r0 differs.
 *  - BMD0's two stores are the if/else written out (`= 2` in one arm,
 *    `= 1` in the other), which mwcc predicates rather than folds into a
 *    select.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02046CE0.c \
 *       --func func_02046CE0 --addr 0x02046CE0 --cc 1.1p1 --arm
 */
void func_02046CE0(struct S02046CE0 *out, u32 *tag)
{
    switch (*tag) {
    case 0x30444D42:
        if (func_0206E964((unsigned char *)tag) == 0) {
            out->result = 2;
        } else {
            out->result = 1;
        }
        break;
    case 0x30585442:
        out->result = 3;
        break;
    case 0x30415642:
    case 0x30414D42:
    case 0x30414342:
    case 0x30415442:
    case 0x30505442:
        out->result = 4;
        break;
    default:
        out->result = 0;
        break;
    }
    out->tag = tag;
    out->unk00 = 0x48BF;
}

















/*
 * g3d_system.c's eight-byte-node allocators.  Three siblings, identical but
 * for the loader they call and the source line: read the size from the
 * global's +0x18 halfword, allocate eight bytes with file name and line, run
 * the loader for (arg0, arg1, that same halfword) and hand its result to
 * func_02046CE0 together with the new node.  The global is re-read after the
 * allocator call - the callee may have replaced it - which is why the second
 * `ldr r1, [r4]` is there.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02046DB8.c \
 *       --func func_02046DB8 --addr 0x02046DB8 --cc 1.1p1 --arm
 */
void *func_02046DB8(u32 a0, u32 a1)
{
    u8 *node = func_02030734(g_02146A5C.obj->heap_id, 8, 0,
                             (const char *)&sG3dSystemFile, 0x2b4);

    func_02046CE0((struct S02046CE0 *)node, func_02048F60(a0, a1, g_02146A5C.obj->heap_id));
    return node;
}

















/*
 * g3d_system.c's eight-byte-node allocators.  Three siblings, identical but
 * for the loader they call and the source line: read the size from the
 * global's +0x18 halfword, allocate eight bytes with file name and line, run
 * the loader for (arg0, arg1, that same halfword) and hand its result to
 * func_02046CE0 together with the new node.  The global is re-read after the
 * allocator call - the callee may have replaced it - which is why the second
 * `ldr r1, [r4]` is there.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02046E24.c \
 *       --func func_02046E24 --addr 0x02046E24 --cc 1.1p1 --arm
 */
void *func_02046E24(struct Arc *a0, u32 a1)
{
    u8 *node = func_02030734(g_02146A5C.obj->heap_id, 8, 0,
                             (const char *)&sG3dSystemFile, 0x2c8);

    func_02046CE0((struct S02046CE0 *)node, func_02049250(a0, a1, g_02146A5C.obj->heap_id));
    return node;
}

















/*
 * g3d_system.c's eight-byte-node allocators.  Three siblings, identical but
 * for the loader they call and the source line: read the size from the
 * global's +0x18 halfword, allocate eight bytes with file name and line, run
 * the loader for (arg0, arg1, that same halfword) and hand its result to
 * func_02046CE0 together with the new node.  The global is re-read after the
 * allocator call - the callee may have replaced it - which is why the second
 * `ldr r1, [r4]` is there.
 *
 * Promoted by parks lane 2: the loader 0x02048F9C was filed first as an
 * EXACT entry (src/matched/func_02048F9C.c, shard pkt_02048F9C) and the call
 * at +0x48 now resolves through the `matched` class.  No change to the C.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02046E90.c \
 *       --func func_02046E90 --addr 0x02046E90 --cc 1.1p1 --arm
 */
void *func_02046E90(u32 a0, u32 a1)
{
    u8 *node = func_02030734(g_02146A5C.obj->heap_id, 8, 0,
                             (const char *)&sG3dSystemFile, 0x2dc);

    func_02046CE0((struct S02046CE0 *)node, func_02048F9C((const char *)a0, a1, g_02146A5C.obj->heap_id));
    return node;
}

















/*
 * The guarded destructor of the 0x48BF-tagged object, 0x02046EFC-0x02046F48
 * including its one pool word.  A NULL handle is a no-op, and so is a handle
 * whose tag halfword is not 0x48BF; otherwise the tag is stamped down to
 * 0x48BE ("freed"), the owned buffer at +4 is released and nulled, and the
 * object itself is released.
 *
 * The two tags are one pool word and a `sub r1, r1, #1`: 0x48BF is not an
 * ARM rotated immediate so it costs a pool word, and 0x48BE is then derived
 * from it rather than pooled a second time, the same accounting as
 * docs/idioms/consecutive-line-numbers-are-one-pool-word-and-adds.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02046EFC.c \
 *       --addr 0x02046EFC --cc 1.1p1 --arm
 */
void func_02046EFC(struct Tagged *p)
{
    if (p == 0) {
        return;
    }
    if (p->tag != 0x48BF) {
        return;
    }
    p->tag = 0x48BE;
    if (p->buf != 0) {
        func_020307B0(p->buf);
        p->buf = 0;
    }
    func_020307B0(p);
}

















/*
 * The buffer accessor of the 0x48BF-tagged object whose destructor is
 * src/matched/unit_02046EFC.c: the pointer at +4, returned by value.  No
 * relocation, two instructions, no label of its own in the listing
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02046F48.c \
 *       --func func_02046F48 --addr 0x02046F48 --cc 1.1p1 --arm
 */
void *func_02046F48(struct Tagged *p)
{
    return p->buf;
}
















/*
 * A five-way predicate over the halfword at +2: the second argument picks
 * which set of values counts as a hit.  The dispatch is the ARM dense-switch
 * form, `addls pc, pc, r1, lsl #2` over four `b`s with the default reached by
 * the `b` that falls out of the bounds test, so the cases really are 0 to 3
 * with nothing missing (docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md
 * is the Thumb form of the same tell).
 *
 * Case 1 is a range test written as one in the source, not a disjunction:
 * this front end does not fold `v == 1 || v == 2` into a range, it emits the
 * `cmp`/`cmpne` pair that cases 2 and 3 show.  The `lsl #16`/`lsr #16`
 * narrowing and the unsigned `cmp #1` are likewise spelled in the C.
 *
 * The bias is written `+ 0xFFFF`, not `- 1`.  Both mean the same thing after
 * the halfword narrowing, but `- 1` compiles to a single `sub r0, r0, #1`
 * and `+ 0xFFFF` to the pair `add r0, r0, #0xff` / `add r0, r0, #0xff00`,
 * because 0xFFFF is not an ARM rotated immediate and splits into two that
 * are.  Four bytes, and the only thing that separates the two readings.  See
 * docs/idioms/a-plus-0xffff-bias-is-two-adds-and-a-minus-one-is-one-sub.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02046F50.c \
 *       --func func_02046F50 --addr 0x02046F50 --cc 1.1p1 --arm
 */
u32 func_02046F50(struct Tagged *p, u32 sel)
{
    u16 v = p->kind;

    switch (sel) {
    case 0:
        return v == 0;
    case 1:
        return (u16)(v + 0xFFFF) <= 1;
    case 2:
        return v == 1 || v == 3;
    case 3:
        return v == 4;
    }
    return 0;
}
















/*
 * Shrink the 0x48BF-tagged object's buffer to exactly what it holds:
 * 0x0206E964 walks the buffer and returns the address of its last record,
 * that record's own length lives at +0x14, and the new size handed to the
 * heap trimmer at 0x020307E0 is the distance from the buffer's base to the
 * end of that record.
 *
 * The returned pointer is copied out of r0 into r2 before it is used, which
 * is the tell that it is a named local and not an inline call argument
 * (docs/idioms/an-inline-call-argument-is-scheduled-per-site-a-local-is-not.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02046FCC.c \
 *       --func func_02046FCC --addr 0x02046FCC --cc 1.1p1 --arm
 */
void func_02046FCC(struct Tagged *p)
{
    void          *buf = p->buf;
    struct Record *last = (struct Record *)func_0206E964(buf);

    func_020307E0(buf, (u32)((u8 *)last + last->size - (u8 *)buf));
}















/*
 * First guard exits through the shared epilogue at the end of the function
 * (a plain `return 0` there is if-converted and loses the branch).
 */
int func_02046FF8(int *self)
{
    int v8;
    int v4;
    int v0;
    int h;
    int p;

    h = self[1];
    p = (int)func_0206E964((unsigned char *)h);
    if (p == 0)
        goto fail;
    if (func_02047260(p, (u32 *)(&v8), (u32 *)(&v4)) == 0)
        return 0;
    if (func_020472F8((struct Layer_020472F8 *)p, (u32 *)(&v0)) == 0)
        return 0;
    func_02069FF8((char *)p, v8, v4);
    func_0206A124((int *)p, v0);
    func_020862F0(h, *(int *)&((struct Obj04802 *)h)->f8);
    func_0206A00C((struct Up *)p, 1);
    func_0206A12C(p, 1);
    return 1;
fail:
    return 0;
}















/*
 * "Build, then trim": run the builder at 0x02046FF8 over the tagged object
 * and, only if it reports success, shrink the buffer with 0x02046FCC.  The
 * zero return is predicated (`moveq`/`popeq`) rather than branched, which is
 * the whole body being two statements long.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020470A8.c \
 *       --func func_020470A8 --addr 0x020470A8 --cc 1.1p1 --arm
 */
u32 func_020470A8(void *p)
{
    if (func_02046FF8(p) == 0) {
        return 0;
    }
    func_02046FCC(p);
    return 1;
}














/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * 176 bytes, 0x020470D0..0x02047180, one function, every concrete byte
 * reproduced (0 differing bytes of 176) -- the diff is empty apart from the
 * two wildcarded call fields.
 *
 * Blocked on the `label` class at two addresses, both of which are in
 * ANOTHER PACKET (the pair lives in pkt_0206A12C and above, which this lane
 * does not own):
 *
 *   +0x40  bl func_0206A0C4   the reader, called (p, &x, &y)
 *   +0x8C  bl func_0206A17C   reached only through the callback below
 *
 * Neither address is matched, parked or labelled outside this range, so both
 * sites stay wildcarded.  Nothing in this C changes when they are filed.
 *
 * Two spellings in here are worth keeping:
 *
 *  - The two "is this bit set" locals are spelled as an int initialised to 0
 *    and set to 1 in the body, NOT as `f = (x & 1) != 0`.  The boolean form
 *    makes mwcc emit a movne/moveq pair per local and loses the original's
 *    `movs r5, #0 / movs r6, r5` up front; the explicit init keeps them.
 *  - The closing callback takes func_0206A17C's RETURN value as its
 *    argument: `(*(void (**)(u32))0x020A814C)(func_0206A17C(r))`.  Spelled as
 *    a bare `(...)()` call mwcc uses r0 for the loaded pointer and blx r0;
 *    the original loads into r1 and blx r1 precisely because r0 is already
 *    holding the argument.  Passing the call's result is what forces r1.
 *
 * The three callbacks are called through globals at 0x020A8144 and
 * 0x020A814C, written as numeric casts so the pool word stays a plain
 * literal rather than a relocation.
 */
int func_020470D0(u32 *p)
{
    u8  *r;
    int  f1;
    int  f2;
    u32  x;
    u32  y;

    r = func_0206E964((unsigned char *)p[1]);
    f1 = 0;
    f2 = 0;
    if (((struct Obj03459 *)r)->f10 & 1)
        f1 = 1;
    if (((struct Obj03459 *)r)->f20 & 1)
        f2 = 1;
    func_0206A0C4((struct Tex *)r, &x, &y);
    if (f1)
        (*(void (**)(u32))0x020A8144)(x);
    if (f2)
        (*(void (**)(u32))0x020A8144)(y);
    if ((((struct Obj03459 *)r)->f32 & 1) != 0 && ((struct Obj03459 *)r)->f30 != 0)
        (*(void (**)(u32))0x020A814C)(func_0206A17C(r));
    return 1;
}














int func_02047180(u32 *p)
{
    u32 h;
    u32 a;
    u32 b;
    u32 c;

    h = (u32)func_0206E964((unsigned char *)p[1]);
    if (h == 0)
        goto fail;
    if (func_02047260(h, &a, &b) == 0)
        return 0;
    if (func_020472F8((struct Layer_020472F8 *)h, &c) == 0)
        return 0;
    func_02069FF8((char *)h, a, b);
    func_0206A124((int *)h, c);
    return 1;
fail:
    return 0;
}














/*
 * Publish the built buffer: locate its last record with 0x0206E964, bail out
 * if there is none, flush the buffer's own byte length (the word at +8 of
 * the buffer header) out of the data cache, then hand the record to the two
 * upload routines and report success.
 *
 * The literal 1 is materialised once into r4 and serves as both upload
 * calls' second argument and the return value
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md,
 * read in the direction where the argument does share it).
 *
 * `movs r5, r0` doing the NULL test on the way into the callee-saved
 * register is what a named local assigned from the call and then tested
 * looks like.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02047204.c \
 *       --func func_02047204 --addr 0x02047204 --cc 1.1p1 --arm
 */
u32 func_02047204(struct Tagged *p)
{
    struct BufHdr *buf = p->buf;
    void          *last = func_0206E964((unsigned char *)buf);

    if (last == 0) {
        return 0;
    }
    DC_FlushRange(buf, buf->size);
    func_0206A00C(last, 1);
    func_0206A12C((int)last, 1);
    return 1;
}













asm void DWCi_LSTlPopFront(void)
{
    ldr r0, [r0, #4]
    ldr ip, =func_0206E964
    bx ip
}













extern u32 (*g_020A8140)(void *p, u32 mode, u32 a2);













/*
 * The two probes are looked up independently; the same dispatcher is called
 * for each, once in mode 0 and once in mode 1, with the first probe's handle
 * (which is necessarily null in the second branch) in r0.  Either failure
 * report is a bare zero.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02047260.c \
 *       --func func_02047260 --addr 0x02047260 --cc 1.1p1 --arm
 */
int func_02047260(u32 a0, u32 *a1, u32 *a2)
{
    void *p = (void *)func_02069FD0(a0);
    void *q = (void *)func_02069FE4(a0);

    if (p != 0) {
        *a1 = g_020A8140(p, 0, 0);
        if (*a1 == 0)
            return 0;
    }
    if (q != 0) {
        *a2 = g_020A8140(p, 1, 0);
        if (*a2 == 0)
            return 0;
    }
    return 1;
}













extern u32 (*g_020A8148)(u32 handle, u32 flags, u32 zero);













/*
 * Open one layer: ask func_0206A110 for the layer's handle (a zero handle
 * is the failure path and answers 1), then call the current handler out of
 * the function pointer at 0x020A8148 with the handle, the layer's bit
 * 0x8000 of the halfword at +0x20 and a zero, and store what it returns
 * through the caller's out pointer.
 *
 * `h != 0` is spelled as two statements, not as a comparison: the zero is
 * already live in r4 (it was r2 for the indirect call), so the failure path
 * is a predicated `moveq r0, r4` plus `popeq`, and the success path is the
 * plain `mov r0, #1`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020472F8.c \
 *       --func func_020472F8 --addr 0x020472F8 --cc 1.1p1 --arm
 */
int func_020472F8(struct Layer_020472F8 *layer, u32 *out)
{
    u32 h;

    h = func_0206A110((int)layer);
    if (h == 0)
        goto ret1;

    h = g_020A8148(h, layer->unk_20 & 0x8000, 0);
    *out = h;
    if (h == 0)
        return 0;
ret1:
    return 1;
}













/*
 * Three consecutive accessors on the object a layer record points at
 * through +4, 64 + 48 + 32 bytes with no padding between them.  The object
 * carries three "ready" bits, one per halfword at +0x10, +0x20 and +0x32,
 * and each bit guards the word at +8, +0x18 and +0x2c respectively.
 *
 * func_02047348 asks whether any of the three is set: the first two tests
 * are early `return 1`s, which is why they branch forward to a shared
 * one-exit and the third is written as the inverted guard (`if (!bit)
 * return 0;`) whose fall-through carries the `return 1`.
 *
 * func_02047388 and func_020473B8 return the guarded word itself, so their
 * arms are single instructions and the compiler if-converts them into
 * predicated `ldrne` / `moveq` on the entry compare; the third test in
 * func_02047388 is the one that stays a real branch pair.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02047348.c \
 *       --addr 0x02047348 --arm
 */
int func_02047348(struct Layer_02047348 *layer)
{
    struct Ctl *p = (struct Ctl *)func_0206E964(layer->unk_04);

    if ((p->unk_10 & 1) || (p->unk_20 & 1) || (p->unk_32 & 1))
        return 1;
    return 0;
}












u32 func_02047388(struct Layer_02047348 *layer)
{
    struct Ctl *p = (struct Ctl *)func_0206E964(layer->unk_04);

    if (p->unk_10 & 1)
        return p->unk_08;
    if (p->unk_20 & 1)
        return p->unk_18;
    return 0;
}












u32 func_020473B8(struct Layer_02047348 *layer)
{
    struct Ctl *p = (struct Ctl *)func_0206E964(layer->unk_04);

    if (p->unk_32 & 1)
        return p->unk_2c;
    return 0;
}













int func_020473D8(int a0){ int t0 = func_02047250(); return (t0 + ((struct Obj16033 *)((char *)(t0)))->f14); }












int func_020473EC(int a0){ int t0 = func_02047250(); return (t0 + ((struct Obj16034 *)((char *)(t0)))->f38); }












/*
 * Construct a 0x7A14-tagged record (the sibling of func_02047564's 0x59D1
 * one): look the owner's +4 handle up through func_0206E954, index its
 * table by `n` to a byte offset, turn that into a pointer, optionally take
 * a second handle from a2, allocate 0x10 bytes out of the context's heap
 * with `g3d_system.c:1544` as the __FILE__/__LINE__ pair, fill the tag and
 * the two owner slots, and register it.
 *
 * WHY THE GOTOS.  Two earlier waves (see docs/notes/pkt_02047400.c.txt)
 * landed three instructions (12 bytes) short with the structured
 * `if (p) { b = p + 8; if (b) { if (n < p[9]) { ... } } }` plus a ternary
 * for q, in five spellings.  The residue was a front-end if-conversion:
 * mwcc predicated the five-instruction `ofs` body (`ldrhlo`/`addlo`/
 * `mlalo`) and therefore hoisted `ofs = 0` before the guards as
 * `mov r2, r4`, and it predicated the q selection as `moveq r5, #0`.
 *
 * The image does neither.  It gives `ofs = 0` its own out-of-line block at
 * +0x50 with TWO predecessors (the `b == 0` and the `n >= p[9]` guards) and
 * an unconditional `b` over it from the body, and it sends the `p == 0`
 * test straight to an out-of-line `q = 0` at +0x64.  Writing those two
 * join blocks as explicit `goto` targets is what reproduces them: with the
 * body no longer the only path into its successor, the front end has no
 * single-block region left to predicate, so the five instructions come out
 * bare and the missing `b` and `bne` appear.  This is the general form of
 * docs/idioms/guards-separated-by-statements-share-an-exit-only-through-goto.md
 * applied to a join rather than to an exit.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02047400.c \
 *       --func func_02047400 --addr 0x02047400 --cc 1.1p1 --arm
 */
void *func_02047400(void *a0, u32 n, void *a2)
{
    u32 z;
    u8 *p;
    u8 *b;
    void *q;
    void *obj;
    u8 *ofs;
    u32 idx;
    u32 cnt;

    z = 0;
    p = (u8 *)func_0206E954((int)(((struct Obj09057 *)a0)->f4));
    if (p == 0) goto qzero;
    b = p + 8;
    if (b == 0) goto ozero;
    if (n >= p[9]) goto ozero;
    idx = ((struct Obj11417 *)p)->fE;
    cnt = *(u16 *)(b + idx);
    ofs = (u8 *)(cnt * n + (s32_0)(b + idx + 4));
    goto join;
ozero:
    ofs = 0;
join:
    if (ofs != 0) { q = (void *)(p + ((struct Obj16035 *)ofs)->f0); goto have; }
qzero:
    q = 0;
have:
    ;

    if (a2 != 0) z = (u32)func_0206E964(((struct Obj09057 *)a2)->f4);

    obj = func_02030734(g_02146A5C.obj->heap_id,
                        0x10, 0, g_szG3DSystem, 0x608);
    ((struct Obj04073 *)obj)->f0 = 0x7A14;
    ((struct Obj04073 *)obj)->f8 = a0;
    ((struct Obj04073 *)obj)->fC = a2;
    ((struct Obj04073 *)obj)->f4 = func_0206E348(g_02146A5C.obj);
    if (z != 0) {
        func_0206A2CC(q, (void *)z);
        func_0206A4AC(q, (void *)z);
    }
    func_02069D14(((struct Obj04073 *)obj)->f4, q);
    return obj;
}












/*
 * Release one tagged record: nothing at all for a null pointer, and nothing
 * for a record whose halfword tag at +0 is not 0x7A14.  Otherwise hand the
 * pointer's +4 field to func_0206E358, drop the tag to one below its own
 * value and free the record.
 *
 * The tag is pooled once (0x7A14 is past a `mov` immediate) and reused for
 * the decrement, which is why the new value arrives as `sub r1, r4, #1`
 * rather than as a second literal; the `mov r0, r5` before the store is the
 * free call's argument being set up early.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02047504.c \
 *       --func func_02047504 --addr 0x02047504 --cc 1.1p1 --arm
 */
void func_02047504(struct Rec *p)
{
    if (p == 0)
        return;
    if (p->tag != 0x7A14)
        return;

    func_0206E358(g_02146A5C.obj, p->unk_04);
    p->tag = 0x7A14 - 1;
    func_020307B0(p);
}










int func_0204754C(int *p){ return p[2]; }










int func_02047554(int *p){ return p[3]; }










int func_0204755C(int *p){ return p[1]; }











/*
 * g3d_system.c.  Allocate a 12-byte record from the context heap (tag
 * 0x59D1, owner a1), fetch animation a2 from a1's resource
 * (func_0206E9A4), allocate the animation object against a0's model
 * (func_0206E364) and initialise it with a0's texture when a0 has one
 * (func_02047554 / func_0206E964, then func_02069C74).
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
struct G3dRec *func_02047564(struct G3dOwner *a0, const struct G3dOwner *a1, int a2)
{
    struct G3dRec *r;
    int x;
    u32 y;
    int z = 0;

    r = func_02030734(g_02146A5C.obj->heap_id, 0xC, 0, g_020A7EA8, 0x6D2);
    r->tag = 0x59D1;
    r->unk_08 = a1;
    x = (int)func_0206E9A4((u8 *)a1->f04, a2);
    y = a0->f04->handle;
    if (func_02047554((int *)a0) != 0)
        z = (int)func_0206E964((unsigned char *)a0->f0c->handle);
    r->unk_04 = func_0206E364(g_02146A5C.obj, x, y);
    func_02069C74(r->unk_04, x, y, z);
    return r;
}








/*
 * The sibling of func_02047504 for the other record tag: 0x59D1 instead of
 * 0x7A14 and func_0206E388 instead of func_0206E358.  Everything else,
 * including the register allocation and the reuse of the pooled tag for the
 * decrement, is identical.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204762C.c \
 *       --func func_0204762C --addr 0x0204762C --cc 1.1p1 --arm
 */
void func_0204762C(struct Rec *p)
{
    if (p == 0)
        return;
    if (p->tag != 0x59D1)
        return;

    func_0206E388(g_02146A5C.obj, p->unk_04);
    p->tag = 0x59D1 - 1;
    func_020307B0(p);
}










/*
 * Unlabelled ARM leaf getter: return the word at +4.  disasm.py never
 * traced a func_ start here (the listing emits these bytes as data words),
 * so the caller func_021BE748 in ov021 had no witness for its bl; this
 * entry supplies the `matched` class.
 */
int func_02047674(int p)
{
    return ((struct Obj16042 *)p)->f4;
}









/*
 * Allocate a 0x10-byte descriptor from the module heap: a 0x2185 tag, the
 * caller's key, the count, and -- only when the count is non-zero -- a second
 * allocation of count*4 bytes holding a copy of the caller's array.  Both
 * allocations pass the same module name and differ only in their line
 * constant (0x75b and 0x765).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204767C.c \
 *       --func func_0204767C --addr 0x0204767C --cc 1.1p1 --arm
 */
void *func_0204767C(u32 a0, u32 *a1, int a2)
{
    struct Desc_02046440 *d;
    int i;

    d = (struct Desc_02046440 *)func_02030734(g_02146A5C.obj->heap_id, 0x10, 0, str_020A7EA8,
                                     0x75b);
    d->tag = 0x2185;
    d->key = a0;
    d->count = (u16)a2;
    if (a2 == 0) {
        d->array = 0;
    } else {
        d->array = (u32)func_02030734(g_02146A5C.obj->heap_id, a2 * 4, 1, str_020A7EA8,
                                 0x765);
        if (a1 != 0 && (int)a2 > 0) {
            for (i = 0; i < a2; i++)
                ((u32 *)d->array)[i] = a1[i];
        }
    }
    return d;
}









/*
 * Retire one record: a null pointer and a mismatched tag 0x2185 are both
 * passed over by predicated returns, then the owned pointer at +8 is freed
 * and cleared (only if it was set) before the tag is left at 0x2184 and the
 * record itself is freed.  Both tags are past a `mov` immediate and so are
 * two pool words at the end of the function.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02047738.c \
 *       --func func_02047738 --addr 0x02047738 --cc 1.1p1 --arm
 */
void func_02047738(struct Rec *p)
{
    if (p == 0)
        return;
    if (p->tag != 0x2185)
        return;

    if (p->unk_08 != 0) {
        func_020307B0(p->unk_08);
        p->unk_08 = 0;
    }

    p->tag = 0x2184;
    func_020307B0(p);
}







int func_02047788(int *p){ return p[1]; }







int func_02047790(int *p, int i){ return ((int *)p[2])[i]; }








u16 func_0204779C(void *p){ return ((struct Obj16046 *)p)->fC; }








/*
 * Dispatch one slot of the G3D system's object table, reporting whether the
 * slot was occupied.  The empty case is the conditional early return
 * `moveq r0, #0 / popeq {r3, pc}`, so the two exits carry different constants
 * and neither arm is shared.
 *
 * The three `ldr ..., #4` loads interleave two independent chains, the
 * system's own +0x04 -> +0x04 pointer walk and the slot's +0x04 payload;
 * scheduling them together is what puts the slot's load in the middle.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020477A4.c \
 *       --func func_020477A4 --addr 0x020477A4 --cc 1.1p1 --arm
 */
u32 func_020477A4(struct G3dSys_1 *sys, u32 idx)
{
    struct G3dSlot *slot = sys->slots[idx];

    if (slot == 0) {
        return 0;
    }

    func_02069E88(sys->unk_04->unk_04, slot->unk_04);
    return 1;
}







/*
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 *
 * Hand the indexed sub-record's +4 word to func_02069F7C, along with the
 * owner's own +4 record's +4 word: the pointer chain is two `ldr`s deep on
 * the owner side and one on the sub-record side, and nothing is loaded until
 * the null test has passed, because the failure path is a predicated
 * `moveq`/`popeq` off the compare.
 *
 * Every concrete byte is right.  The single PC24 stays wildcarded: 0x02069F7C
 * is called from this site and nowhere else the harness can see, it is not in
 * the manifest, and a one-function range admits no cut (--suggest-split cannot
 * help).  Blocking evidence class: label/matched, no witness.  It unsticks the
 * moment 0x02069F7C is itself EXACT (`matched` class) or a second caller of it
 * turns up in an overlay.
 *
 * The `*` is the unlabelled follower at 0x02047804 (a leaf with no lr-saving
 * prologue) making disasm.py's extent for the original run to 0x02047970.
 */
int func_020477D4(struct Owner_02046440 *owner, u32 index)
{
    struct Sub *sub = owner->unk_08[index];

    if (sub == 0)
        return 0;

    func_02069F7C(owner->unk_04->unk_04, sub->unk_04);
    return 1;
}







/*
 * Two siblings of func_0204784C over the same slot table at +8: a null slot
 * returns 0; otherwise the first clears the slot object's frame and the
 * second stores it to *frame, and both return 1.  Seeded from ov021
 * 0x0218C064 and 0x0218C486 (blx).
 *
 * Addresses are Black-image addresses.
 */
u32 func_02047804(struct AnmCtl *c, u16 idx)
{
    struct AnmSlot *s = c->slots[idx];

    if (s == 0) {
        return 0;
    }
    s->obj->frame = 0;
    return 1;
}






u32 func_02047828(struct AnmCtl *c, u32 idx, s32_1 *frame)
{
    struct AnmSlot *s = c->slots[idx];

    if (s == 0) {
        return 0;
    }
    *frame = s->obj->frame;
    return 1;
}







/*
 * ARM leaf, seeded 2026-09-27 from the ov195 call sites 0x02208B3E and
 * 0x02208B48 (func_02208AB0). Looks up slot idx of the table at +8; a
 * null slot returns 0. Otherwise it sets the slot object's frame to
 * *frame, clamped from above to numFrame << 12 (the u16 at +4 of the
 * object's resource), with a signed compare (strge/strlt), and returns 1.
 * Siblings at 0x02047804, 0x02047828, 0x020478B8 and 0x02047910 share the
 * slot lookup and are still unlabelled.
 *
 * Addresses are Black-image addresses.
 */
u32 func_0204784C(struct AnmCtl *c, u16 idx, s32_1 *frame)
{
    struct AnmSlot *s = c->slots[idx];
    struct AnmObj *a;

    if (s == 0) {
        return 0;
    }
    a = s->obj;
    if (*frame >= (s32_1)(a->res->numFrame << 12)) {
        a->frame = a->res->numFrame << 12;
    } else {
        a->frame = *frame;
    }
    return 1;
}







/*
 * Looks up entry idx of the table at a[2]; on a hit stores the u16 at
 * entry->f4->f8->f4 shifted to 20.12 fixed point and returns 1.  Filed as the
 * witness for ov021 func_021D0750.
 */
int func_02047888(int *a, int idx, int *out)
{
    int *p = ((int **)a[2])[idx];
    if (p == 0) {
        return 0;
    }
    *out = ((u16 *)((int *)p[1])[2])[2] << 12;
    return 1;
}






/*
 * Unlabelled ARM leaf: advance a clamped counter.  a is a table base whose
 * slot [idx] holds an object; the object's word at +4 points at a run state
 * (counter at +0, descriptor pointer at +8) whose descriptor's u16 at +4 is a
 * limit in units of 0x1000.  Adds amount to the counter; if it reaches the
 * limit it rewinds by one 0x1000 and returns 0, if it goes negative it pins to
 * zero and returns 0, otherwise returns 1.
 */
int func_020478B8(void *a, int idx, int amount)
{
    struct Obj **tbl = *(struct Obj ** *)&((struct Obj06972 *)a)->f8;
    struct Obj *e = tbl[idx];
    struct Run *r;
    int nv;
    u32 lim;

    if (e == 0) {
        return 0;
    }

    r = e->run;
    nv = (int)r->cur + amount;
    r->cur = (u32)nv;

    lim = (u32)((struct Obj16059 *)(r->desc))->f4 << 12;
    if (nv >= (int)lim) {
        r->cur = lim - 0x1000;
        return 0;
    }
    if (nv < 0) {
        r->cur = 0;
        return 0;
    }
    return 1;
}






/*
 * Unlabelled ARM leaf: the sibling of func_020478B8 with a different clamp
 * policy.  Advance the counter of the run state reached through a's table slot
 * [idx]; if it reaches the descriptor limit it pins the counter to zero and
 * returns 0, if it goes negative it pins it to the limit and returns 0,
 * otherwise returns 1.
 */
int func_02047910(void *a, int idx, int amount)
{
    struct Obj **tbl = *(struct Obj ** *)&((struct Obj06972 *)a)->f8;
    struct Obj *e = tbl[idx];
    struct Run *r;
    int nv;
    u32 lim;

    if (e == 0) {
        return 0;
    }

    r = e->run;
    nv = (int)r->cur + amount;
    r->cur = (u32)nv;

    lim = (u32)((struct Obj16062 *)(r->desc))->f4 << 12;
    if (nv >= (int)lim) {
        r->cur = 0;
        return 0;
    }
    if (nv < 0) {
        r->cur = lim;
        return 0;
    }
    return 1;
}




void func_02047964(void)
{
    func_0207DA8C();
}












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
    g_02146A5C.obj->f94 = 1;
}











/*
 * The 3D buffer-swap flush, called once per frame from NitroMain (blx at
 * 0x02005176).  When the swap requested by func_02047970 is pending (+0x94
 * set to 1), it writes G3_SWAP_BUFFERS with the sort mode (+0x80) and the
 * buffer mode (+0x84) and clears the request.  The listing carried it as raw
 * words until NitroMain was seeded in layout/function_starts.txt.
 */
void func_02047990(void)
{
    struct G3dCtx *c = g_02146A5C.obj;

    if (c == 0)
        return;
    if (c->f94 != 1)
        return;
    reg_G3_SWAP_BUFFERS = (c->bufferMode << 1) | c->sortMode;
    g_02146A5C.obj->f94 = 0;
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
    NNS_G3dGlbLookAt(&g_02146A5C.obj->view0, &g_02146A5C.obj->view1, &g_02146A5C.obj->view2);
    g_02146A5C.obj->f88();
}












void func_02047A60(void *a0, struct Arg *a1)
{
    void *r;

    r = (void *)func_0204755C((int *)func_02047788(a0));
    func_0206A9DC(a1);
    MI_Copy36B(&a1->m18, g_02148C08);
    g_02148B4C[63] = g_02148B4C[63] & ~0xa4u;
    func_0206AA0C(&a1->v0c);
    g_02146A5C.obj->f88();
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
    g_02146A5C.obj->f88();
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
    p = (char *)((struct Owner_02047970 *)func_0204755C((int *)func_02047788(a0)))->unk_04;
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
    if (g_02146A5C.obj->f98 != 0)
        g_02146A5C.obj->f98(p, g_02146A5C.obj->f9c);
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
u16 func_02048010(Util *util, const Setup *setup, struct Arc *extra)
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
            func_02048258((struct Owner_02047970 *)util, i, (struct Holder *)setup, util->heapID, extra);
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
    func_020482B4((struct Owner_02047970 *)util, i);
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
    struct Desc_02047970 *desc = (struct Desc_02047970 *)setup;
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
void func_02048258(struct Owner_02047970 *owner, u16 index, struct Holder *p, u32 a4,
                   struct Arc *a5)
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
void func_020482B4(struct Owner_02047970 *owner, u32 index)
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






u32 sub_02048A00(u8 *a0, int i)
{
    return *(u16 *)(a0 + i * 8 + 0x1c);
}






u32 sub_02048A0C(u8 *a0, int i)
{
    return *(u32 *)((u8 *)((struct Obj17329 *)a0)->f0 + i * 4);
}






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





void func_02048AE8(struct Light *l, VecFx32 *out)
{
    *out = l->unk20;
}





void func_02048AFC(struct Light *l, const VecFx32 *in)
{
    l->unk20 = *in;
}





void func_02048B0C(struct Light *l, VecFx32 *out)
{
    *out = l->unk2C;
}





void func_02048B20(struct Light *l, const VecFx32 *in)
{
    l->unk2C = *in;
}





void func_02048B30(struct Light *l, VecFx32 *out)
{
    *out = l->unk38;
}





void func_02048B44(struct Light *l, const VecFx32 *in)
{
    l->unk38 = *in;
}





void func_02048B54(struct Light *l, u32 *out)
{
    *out = l->unk14;
}





void func_02048B60(struct Light *l, const u32 *in)
{
    l->unk14 = *in;
}





void func_02048B6C(struct Light *l, const u32 *in)
{
    l->unk18 = *in;
}





int func_02048B78(struct Light *l)
{
    return l->unk00;
}





void func_02048B80(struct Light *l, u32 v)
{
    l->unk04 = v;
}





void func_02048B88(struct Light *l, u32 *out)
{
    *out = l->unk08;
}





void func_02048B94(struct Light *l, u32 v)
{
    l->unk08 = v;
}





void func_02048B9C(struct Light *l, u32 *out)
{
    *out = l->unk04;
}





void func_02048BA8(struct Light *l, u32 v)
{
    l->unk04 = v;
}





void func_02048BB0(struct Light *l, u32 *out)
{
    *out = l->unk08;
}





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
struct LightSlot_02046440 *func_02048BC4(const struct LightSet *s, u16 heap)
{
    struct LightSlot_02046440 *out;
    int i;

    out = (struct LightSlot_02046440 *)func_02030734(heap, 0x20, 1,
                                            func_02048BC4_File, 43);
    for (i = 0; i < s->count; i++) {
        struct LightRec *r = &s->recs[i];
        u32 slot = r->slot;

        out[slot] = r->val;
    }
    return out;
}



u32 func_02048C4C(void *p)
{
    return func_020307B0(p);
}









/*
 * g3d_light.c's tail, 0x02048C58-0x02048D00: the four-slot upload loop and
 * the per-slot colour accessors over the same eight-byte slot the builder at
 * 0x02048BC4 fills, three halfwords of colour and one spare.
 *
 *   0x02048C58  push all four slots through 0x02046A94; the `and r0, #0xff`
 *               on the loop counter is the callee's `u8` first parameter,
 *               not a narrow counter (the counter itself increments and
 *               compares as a plain `int`)
 *   0x02048C80  read slot i's colour out, 0x02048CA4 writes it
 *   0x02048CCC  read slot i's spare halfword out, 0x02048CDC writes it
 *   0x02048CEC  seed the three-word global at 0x02146A68 from two arguments
 *               and a zero
 *
 * 0x02048CA4 pushes {r3, lr} and calls nothing: lr is spilled purely as a
 * scratch register for the third halfword of the copy.  Its source pointer
 * must not be `const`: with `const` mwcc proves the two halfword stores
 * cannot reach the source and hoists all three loads ahead of them, which is
 * thirteen bytes wrong; without it the third load stays after the first two
 * stores, in source order.
 *
 * The six-byte colour moves are aggregate assignments of the nested struct,
 * which is why the loads pair up ahead of the stores rather than
 * interleaving one field at a time
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md, halfword form).
 *
 * The unit starts at 0x02048C58 and not earlier because 0x02048C4C holds an
 * ARM long-branch veneer that no `tu` range may span.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02048C58.c \
 *       --addr 0x02048C58 --cc 1.1p1 --arm
 */
void func_02048C58(struct LightSlot_02048C58 *slots)
{
    int i;

    for (i = 0; i < 4; i++) {
        func_02046A94((u8)i, (const u16 *)(&slots[i]));
    }
}









void func_02048C80(struct LightSlot_02048C58 *slots, u8 i, struct Rgb555 *out)
{
    *out = slots[i].col;
}









void func_02048CA4(struct LightSlot_02048C58 *slots, u32 i, struct Rgb555 *in)
{
    slots[i].col = *in;
}









void func_02048CCC(struct LightSlot_02048C58 *slots, u8 i, u16 *out)
{
    *out = slots[i].unk06;
}









void func_02048CDC(struct LightSlot_02048C58 *slots, u32 i, u16 *in)
{
    slots[i].unk06 = *in;
}









void func_02048CEC(u32 a, u32 b)
{
    g_02146A68.unk00 = (u32 *)a;
    g_02146A68.unk04 = b;
    g_02146A68.unk08 = 0;
}










/*
 * Read one sub-file of one archive into a buffer the caller owns.  The whole
 * archive handle is a 0x48 byte stack local: func_02048DDC binds it to the
 * archive named by `archive_id` (it indexes the 235-entry a/x/y/z name table
 * at 0x020A6C58), func_02048E34 seeks the member and returns its byte size,
 * func_02078B70 is the read and func_02078A80 closes the handle again.
 *
 * Nothing survives the call, so this is the one-shot form: a caller that wants
 * the archive to stay open uses func_020490F4 instead.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02048D00.c \
 *       --func func_02048D00 --addr 0x02048D00 --cc 1.1p1 --arm
 */
void func_02048D00(void *dst, u32 archive_id, u32 member, u32 mode,
                   u32 *size_out)
{
    struct ArcFile h;

    func_02048DDC(&h, archive_id);
    func_02078B70((struct FSFile *)(&h), dst, func_02048E34((struct ArcHandle *)&h, member, mode, (u32)size_out));
    func_02078A80(&h);
}










/*
 * The allocating twin of func_02048D00: bind a temporary 0x48-byte archive
 * handle to `archive_id`, size the member, take a block of exactly that size
 * from the caller's heap, read the member into it, close the handle and hand
 * the block back.  The __FILE__ argument is "arc_tool.c" at 0x020A7EE0, the
 * same string src/matched/sub_020490F4.c already pins, with line 0xbb.
 *
 * This is the function the whole map-model path goes through: func_02048F60
 * calls it as func_02048D54(9, matrix_id, heap, 0, NULL), and ov010's
 * func_02159B94 is what supplies archive id 9 (a/0/0/9) and the matrix id
 * read out of the zone record's +0x04 lane.  See docs/ASSETS.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02048D54.c \
 *       --func func_02048D54 --addr 0x02048D54 --cc 1.1p1 --arm
 */
void *func_02048D54(u32 archive_id, u32 member, u16 heap, u32 mode,
                    u32 *size_out)
{
    struct ArcFile h;
    u32 size;
    void *buf;

    func_02048DDC(&h, archive_id);
    size = func_02048E34((struct ArcHandle *)&h, member, mode, (u32)size_out);
    buf = func_02030734(heap, size, 0, func_02048D54_File, 0xbb);
    func_02078B70((struct FSFile *)(&h), buf, size);
    func_02078A80(&h);
    return buf;
}









/*
 * The whole of packet pkt_02048DDC, 0x02048DDC-0x02048F4C: arc_tool.c's
 * archive binder (func_02048DDC) and the member resolver it hands off to
 * (func_02048E34), both open functions on the eidos port's blocked list.
 * Verified as one translation unit, so the literal pool at 0x02048E30
 * between the two functions and the two pool words at 0x02048F44/0x02048F48
 * are inside the compared range: 2 sections, 368 bytes, no padding, 16 of 16
 * relocation sites resolved (attestation classes: label for the five SDK
 * entry points and func_02034734, literal for g_02146A68 and the arc_tool.c
 * string, string for the assertion text).
 *
 * ---------------------------------------------------------------------------
 * func_02048DDC - "open archive by id"
 *
 * FS_InitFile binds the caller's 0x48-byte handle, then the one global at
 * 0x02146A68 picks the archive's storage: with its +0x08 flag clear the
 * +0x00 pointer is the 235-entry name table (installed by
 * func_02048CEC(0x020A6C58, 0xeb), see docs/ASSETS.md) and the member's name
 * is opened by path; with the flag set the same table is an array of 8-byte
 * {start, end} extents and the member is bound straight out of memory as
 * (start, end - start).  Nothing in the image ever sets +0x08, so the second
 * arm is dead code kept for the id-as-pointer build.
 *
 * The two arms must each read the +0x00 table pointer themselves: the
 * original spends a separate `ldr` in each arm and the record arm's pointer
 * lands in r3.  Three things in this spelling are shape, not semantics, and
 * each is load-bearing for -O4,p at 1.1p1 - each was measured against a
 * variant that differs only in the qualifier or the declaration:
 *
 *   - `u32 * volatile unk00`: without `volatile` the optimizer
 *     common-subexpresses the two arms' table-pointer loads, hoists the one
 *     load above the `bne` (the word arm then begins with `mov r0, r5` at
 *     +0x20 instead of +0x24) and the record arm reuses it.  A volatile load
 *     cannot be CSE'd, so each arm reloads, and the function is 88 bytes
 *     instead of 76.
 *   - `volatile u32 end` in the extent type: without it mwcc merges the
 *     record's two field loads into `ldm r2, {r1, r2}`, which is four bytes
 *     short and re-tiles the low word onto the materialised address.
 *   - `u32 *tbl` bound before the record pointer: with the pointer expression
 *     inlined into the subscript
 *     (`(struct ArcRecord *)g_02146A68.unk00 + id`) the same code comes out
 *     with the table in r1 and the materialised address in r2, i.e. every
 *     register in the record arm is off by one slot.  Naming the loaded table
 *     first makes mwcc keep it in r3 and use r1 for the address, as the
 *     original does.
 *
 * The 8-byte extent is {start, end} and the requested length is end - start;
 * the two locals mirror the original's evaluation order, which loads the high
 * word first.  A plain `u32 *` (or a plain `u32` plus a cast in the word arm)
 * instead of `u32 * volatile` is 76-84 bytes, never 88.  The sibling unit
 * src/matched/unit_02048C58.c declares the same global as three plain u32
 * fields, which is right for what it does (func_02048CEC writes it) and is
 * not enough for this reader.  See docs/notes/pkt_02048DDC.c.txt.
 *
 * ---------------------------------------------------------------------------
 * func_02048E34 - resolve one member's extent
 *
 * Read the FAT offset out of the file header at +0xc, read the tail of the
 * table it points to ({u32 image delta, u16 count} at fatOffset+4), range
 * check the member index, walk to the member's {u32 start, u32 end} pair at
 * fatOffset+0xc+member*8 and seek to its first byte at base+image+8+start.
 * Returns the member's byte length, or `size` when the caller supplied one
 * (that is the `size_out` argument the sibling readers in src/matched/ pass
 * as 0).  The u32 at +4 doubles as the scratch the first two reads share,
 * which is why it is zeroed before the 2-byte read: the top half of the
 * u32 stays clear.
 *
 * The assertion's variadic tail is two values, the count and the member: r3
 * is never written on the assert path, so the `ldrh` that fed the guard's
 * `cmp` is still live and only the member reaches the stack
 * (docs/idioms/a-free-variadic-argument-is-the-value-the-guard-compared.md).
 * 0x020A7EE0 is the arc_tool.c anchor src/matched/func_02048D54.c already
 * pins; 0x020A7EEC is the assertion text, fixed from outside by the
 * terminator of the string in front of it.  The `ldreq`/`subeq` tail is
 * "take the caller's size if it is non-zero, else end - start".
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02048DDC.c \
 *       --addr 0x02048DDC --cc 1.1p1 --arm
 * (both halves were also verified individually as `one` before folding them
 * into this unit: func_02048DDC 88 bytes, func_02048E34 280 bytes.)
 */
void func_02048DDC(struct ArcFile *arc, u32 id)
{
    FS_InitFile(arc);
    if (g_02146A68.unk08 == 0) {
        CRYPTOi__BN_lshift1(arc, g_02146A68.unk00[id]);
    } else {
        u32 *tbl = (u32 *)g_02146A68.unk00;
        struct ArcRecord *rec = (struct ArcRecord *)tbl + id;
        u32 end = rec->end;
        u32 start = rec->start;

        FS_CreateFileFromMemory(arc, (void *)start, end - start);
    }
}








u32 func_02048E34(struct ArcHandle *arc, u32 member, u32 base, u32 size)
{
    u32 range[2];
    struct FatInfo info;
    u32 tmp = 0;
    u32 fatOffset;
    u32 off;

    FS_SeekFile(arc, 0xc, 0);
    FS_ReadFile(arc, &tmp, 2);
    fatOffset = tmp;

    FS_SeekFile(arc, fatOffset + 4, 0);
    FS_ReadFile(arc, &info, 6);
    if (info.count <= member) {
        func_02034734(func_02048DDC_File, 0xfb, func_02048DDC_Msg, info.count,
                      member);
    }

    off = fatOffset + info.offset;
    FS_SeekFile(arc, off + 4, 0);
    FS_ReadFile(arc, &tmp, 4);
    off += tmp;
    FS_SeekFile(arc, fatOffset + 0xc + member * 8, 0);

    FS_ReadFile(arc, range, 8);
    FS_SeekFile(arc, base + (off + 8 + range[0]), 0);

    if (size == 0) {
        size = range[1] - range[0];
    }
    return size;
}









/*
 * "Read one archive sub-file into a caller-supplied buffer", the defaulting
 * wrapper around func_02048D00.  func_02048D00 takes five arguments
 * (dst, archive id, member, mode, size_out); this entry point supplies zero
 * for the last two, which is why the body is a single `mov r3, #0` doing
 * double duty: the same zero reaches r3 (the fourth argument) and the one
 * word of outgoing stack area (the fifth).  The `push {r3, lr}` is the home
 * slot for that stack argument, not a saved register.
 *
 * func_02048D00 itself opens a temporary archive handle with func_02048DDC,
 * sizes the member with func_02048E34, reads it and closes the handle again.
 *
 * Kept in its own file so that the branch to func_02048D00 is witnessed from
 * outside this range by src/matched/func_02048F74.c, which calls the same
 * target (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02048F4C.c \
 *       --func func_02048F4C --addr 0x02048F4C --cc 1.1p1 --arm
 */
void func_02048F4C(void *dst, u32 archive_id, u32 member)
{
    func_02048D00(dst, archive_id, member, 0, 0);
}









/*
 * "Load one archive sub-file into a fresh heap block", the defaulting wrapper
 * around func_02048D54.  Same shape as func_02048F4C one entry above: the
 * callee takes (archive id, member, heap, mode, size_out) and this entry
 * point supplies zero for the last two, so one `mov r3, #0` feeds both r3 and
 * the single outgoing stack word, and `push {r3, lr}` is that word's home
 * slot rather than a saved register.
 *
 * This is the call the field code uses to pull a map matrix out of a/0/1/2's
 * sibling archive: func_02159B94 in ov010 calls it as
 * func_02048F60(9, matrix_id, heap), i.e. archive id 9 = a/0/0/9, with the
 * matrix id taken straight from the zone record's +0x04 lane.  See the
 * "Zone to map model" section of docs/ASSETS.md.
 *
 * Kept in its own file so the branch to func_02048D54 is witnessed from
 * outside this range by src/matched/func_02048F88.c
 * (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02048F60.c \
 *       --func func_02048F60 --addr 0x02048F60 --cc 1.1p1 --arm
 */
void *func_02048F60(u32 archive_id, u32 member, u16 heap)
{
    return func_02048D54(archive_id, member, heap, 0, 0);
}









/*
 * The five-argument entry point of the same read: a pure forwarder to
 * func_02048D00 that copies the caller's one stack argument down into its own
 * outgoing stack area (`ldr ip, [sp, #8]` reads it across the two words this
 * function pushed) and leaves r0-r3 untouched.
 *
 * Kept in its own file so the branch to func_02048D00 is witnessed from
 * outside this range by src/matched/func_02048F4C.c.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02048F74.c \
 *       --func func_02048F74 --addr 0x02048F74 --cc 1.1p1 --arm
 */
void func_02048F74(void *dst, u32 archive_id, u32 member, u32 mode,
                   u32 *size_out)
{
    func_02048D00(dst, archive_id, member, mode, size_out);
}








/*
 * The five-argument entry point of the allocating load: a pure forwarder to
 * func_02048D54, with the caller's single stack argument copied down through
 * ip exactly as func_02048F74 does for func_02048D00.
 *
 * Kept in its own file so the branch to func_02048D54 is witnessed from
 * outside this range by src/matched/func_02048F60.c.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02048F88.c \
 *       --func func_02048F88 --addr 0x02048F88 --cc 1.1p1 --arm
 */
void *func_02048F88(u32 archive_id, u32 member, u16 heap, u32 mode,
                    u32 *size_out)
{
    return func_02048D54(archive_id, member, heap, mode, size_out);
}








/*
 * Promote-first callee of src/pending/func_02046E90.c (parks lane 2).
 * Open one member of an archive by path, size it, allocate the block from
 * the debug allocator, read the bytes in and close.  Same shape as its
 * sibling func_02049250 in the same cluster; the 0x4c frame is the 0x48
 * ArcFile handle at sp+4 plus the allocator's one outgoing stack word.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02048F9C.c \
 *       --func func_02048F9C --addr 0x02048F9C --cc 1.1p1 --arm
 */
void *func_02048F9C(const char *path, u32 a, u16 heap)
{
    struct ArcFile file;
    void *p;
    u32 size;

    func_020788AC(&file);
    func_02078C18(&file, path);
    size = func_02048E34((struct ArcHandle *)(&file), a, 0, 0);
    p = func_02030734(heap, size, 0, func_02048F9C_File, 0x182);
    func_02078B70((struct FSFile *)(&file), p, size);
    func_02078A80(&file);
    return p;
}







u32 func_02049030(u32 a)
{
    char buf[0x48];
    int off;
    u16 hdr[3];

    off = 0;
    func_02048DDC((struct ArcFile *)buf, a);
    func_02078B44((struct FSFile *)buf, 0xc, 0);
    func_02078B70((struct FSFile *)buf, &off, 2);
    func_02078B44((struct FSFile *)buf, off + 4, 0);
    func_02078B70((struct FSFile *)buf, hdr, 6);
    func_02078A80(buf);
    return hdr[2];
}







u32 func_020490A8(u32 a, u32 b)
{
    char buf[0x48];
    u32 r;

    func_02048DDC((struct ArcFile *)buf, a);
    r = func_02048E34((struct ArcHandle *)buf, b, 0, 0);
    func_02078A80(buf);
    return r;
}






/*
 * Constructor: take a 0x50-byte record from the debug allocator, tie it to
 * the caller's object through func_02048DDC, run the one-time init at
 * func_0204919C and hand the record back.  The allocator's __FILE__/__LINE__
 * pair is the usual ABS32 into the packed string area plus a pooled 0x209,
 * which is not an ARM rotated immediate.
 */
void *sub_020490F4(u32 id, u16 heap)
{
    void *rec = func_02030734(heap, 0x50, 0, sub_020490F4_File, 0x209);

    func_02048DDC(rec, id);
    func_0204919C(rec);
    return rec;
}






/*
 * arc_tool.c's memory-file opener: carve a 0x50-byte FSFile with the
 * three-argument allocator (the heap id is this function's THIRD parameter
 * and reaches the allocator first), initialise it, bind it to the caller's
 * buffer and length, run the reader over it, and hand the FSFile back.
 *
 * The __FILE__ argument is the arc_tool.c anchor at 0x020A7EE0 that
 * src/matched/func_02048D54.c and the rest of the 0x02049xxx run already
 * pin; the stacked fifth argument is __LINE__ = 0x21f.  Its own pool word
 * (0x02049198) sits inside the compared range, so the site resolves through
 * the `string` class - the anchor's address is fixed by the terminator of the
 * string in front of it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204913C.c \
 *       --func func_0204913C --addr 0x0204913C --cc 1.1p1 --arm
 */
void *func_0204913C(void *a0, u32 a1, u16 heap)
{
    void *f = func_02030734(heap, 0x50, 0, func_0204913C_File, 0x21f);

    FS_InitFile(f);
    FS_CreateFileFromMemory(f, a0, a1);
    func_0204919C(f);
    return f;
}






/*
 * Walk the reader past its own header.  A halfword count at +0x4c is read
 * first, then skipped by, then a six-byte record is read into a stack buffer
 * whose first word is added to that count and whose third halfword lands in
 * the object at +0x4e; the running total then skips the following four-byte
 * field, which is read into the second half of the same buffer and added to
 * the total for the final offset at +0x48.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204919C.c \
 *       --func func_0204919C --addr 0x0204919C --cc 1.1p1 --arm
 */
void func_0204919C(u8 *p)
{
    u8 buf[12];
    u32 off;

    ((struct Obj05745 *)p)->f4C = 0;
    func_02078B44((struct FSFile *)p, 0xc, 0);
    func_02078B70((struct FSFile *)p, p + 0x4c, 2);
    func_02078B44((struct FSFile *)p, ((struct Obj05745 *)p)->f4C + 4, 0);
    func_02078B70((struct FSFile *)p, buf, 6);
    ((struct Obj05745 *)p)->f4E = ((struct Obj08859 *)buf)->f4;
    off = ((struct Obj05745 *)p)->f4C + ((struct Obj08859 *)buf)->f0;
    func_02078B44((struct FSFile *)p, off + 4, 0);
    func_02078B70((struct FSFile *)p, buf + 8, 4);
    ((struct Obj05745 *)p)->f48 = off + ((struct Obj08859 *)buf)->f8;
}






asm void func_02049238(void *arc)
{
    stmfd sp!, {r4, lr}
    mov	r4, r0
    bl func_02078A80
    mov	r0, r4
    bl func_020307B0
    ldmfd sp!, {r4, pc}
}





/*
 * Read one member out of an open archive into a fresh heap block.  The
 * handle is an FSFile (0x48 bytes) with the archive's own bookkeeping
 * appended: the FAT offset at +0x4c and the member count at +0x4e, both
 * halfwords, and the image base at +0x48.
 *
 * The FAT entry is a pair of words (start, end) at
 * `fatOffset + 0xc + member * 8`, read into an on-stack two-word buffer;
 * the member's bytes then start at `imageBase + 8 + start` and run
 * `end - start` long.  The difference is written out twice, not cached in a
 * local: the original recomputes `sub r2, r3, r2` after the allocation from
 * two fresh stack loads.
 *
 * The assertion's variadic tail is two values, the count and the member,
 * not one.  The tell is that r3 is never written on the assert path: the
 * `ldrh r3, [r5, #0x4e]` that fed the guard's own `cmp` is still live, so
 * the first variadic argument costs no instruction at all, and only the
 * second reaches the stack.  Declared with a single variadic argument the
 * member lands in r3 instead and the `str r7, [sp]` disappears; see
 * docs/idioms/a-free-variadic-argument-is-the-value-the-guard-compared.md.
 *
 * 0x020A7EE0 is the arc_tool.c anchor this translation unit already uses in
 * func_02048D54; 0x020A7F18 is the assertion message, attested by the
 * terminator of the string in front of it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02049250.c \
 *       --func func_02049250 --addr 0x02049250 --cc 1.1p1 --arm
 */
void *func_02049250(struct Arc *arc, u32 member, u16 heap)
{
    u32 range[2];
    void *buf;

    if (arc->count <= member) {
        func_02034734(func_02049250_File, 613, func_02049250_Msg,
                      arc->count, member);
    }

    func_02078B44((struct FSFile *)arc, arc->fatOffset + 0xc + member * 8, 0);
    func_02078B70((struct FSFile *)arc, range, 8);
    func_02078B44((struct FSFile *)arc, arc->imageBase + 8 + range[0], 0);

    buf = func_02030734(heap, range[1] - range[0], 0, func_02049250_File, 619);
    if (buf != 0) {
        func_02078B70((struct FSFile *)arc, buf, range[1] - range[0]);
    }
    return buf;
}





/*
 * Read one archive member straight into a caller-supplied buffer: the
 * allocating variant is func_02049250 one function above, and the FAT
 * lookup, the image-base offset and the length are identical.
 *
 * The bounds assertion is the same five-argument call func_02049250 uses:
 * the count is already in r3 from the guard's own `cmp`, so only the member
 * reaches the stack (docs/idioms/a-free-variadic-argument-is-the-value-the-guard-compared.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204932C.c  *       --func func_0204932C --addr 0x0204932C --cc 1.1p1 --arm
 */
void func_0204932C(struct ArcFile_0204932C *arc, u32 member, void *dst)
{
    u32 range[2];

    if (arc->count <= member) {
        func_02034734(func_0204932C_File, 642, func_0204932C_Msg,
                      arc->count, member);
    }

    func_02078B44((struct FSFile *)arc, arc->fatOffset + 0xc + member * 8, 0);
    func_02078B70((struct FSFile *)arc, range, 8);
    func_02078B44((struct FSFile *)arc, arc->imageBase + 8 + range[0], 0);
    func_02078B70((struct FSFile *)arc, dst, range[1] - range[0]);
}





/*
 * Return the byte length of one archive member without reading it: the
 * FAT entry's two words are fetched and subtracted, and the file cursor is
 * left parked on the FAT rather than on the member's data.
 *
 * The bounds assertion is the same five-argument call func_02049250 uses:
 * the count is already in r3 from the guard's own `cmp`, so only the member
 * reaches the stack (docs/idioms/a-free-variadic-argument-is-the-value-the-guard-compared.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020493D4.c  *       --func func_020493D4 --addr 0x020493D4 --cc 1.1p1 --arm
 */
u32 func_020493D4(struct ArcFile_020493D4 *arc, u32 member)
{
    u32 range[2];

    if (arc->count <= member) {
        func_02034734(func_020493D4_File, 665, func_020493D4_Msg,
                      arc->count, member);
    }

    func_02078B44((struct FSFile *)arc, arc->fatOffset + 0xc + member * 8, 0);
    func_02078B70((struct FSFile *)arc, range, 8);
    return range[1] - range[0];
}





/*
 * Read a window out of the middle of one archive member.  Only the FAT
 * entry's first word is fetched (a 4-byte read, not 8), because the end
 * offset is never needed: the caller supplies both the offset into the
 * member and the length.
 *
 * The seek target is `offset + (imageBase + 8 + start)`: the accumulator of
 * the final `add` is the register holding the computed base, which is what
 * puts the caller's offset on the left of the source expression
 * (docs/idioms/the-accumulator-of-a-commutative-chain-is-its-second-operand.md).
 *
 * The bounds assertion is the same five-argument call func_02049250 uses:
 * the count is already in r3 from the guard's own `cmp`, so only the member
 * reaches the stack (docs/idioms/a-free-variadic-argument-is-the-value-the-guard-compared.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204944C.c  *       --func func_0204944C --addr 0x0204944C --cc 1.1p1 --arm
 */
void func_0204944C(struct ArcFile_0204944C *arc, u32 member, u32 offset, u32 size,
                   void *dst)
{
    u32 start;

    if (arc->count <= member) {
        func_02034734(func_0204944C_File, 689, func_0204944C_Msg,
                      arc->count, member);
    }

    func_02078B44((struct FSFile *)arc, arc->fatOffset + 0xc + member * 8, 0);
    func_02078B70((struct FSFile *)arc, &start, 4);
    func_02078B44((struct FSFile *)arc, offset + (arc->imageBase + 8 + start), 0);
    func_02078B70((struct FSFile *)arc, dst, size);
}





/*
 * Store the absolute image offset of one archive member through an out
 * parameter.  Only the FAT entry's start word is read; the end word is
 * never touched, which is the 4-byte read rather than 8.
 *
 * The bounds assertion is the same five-argument call func_02049250
 * uses: the count is already in r3 from the guard's own `cmp`, so only
 * the member reaches the stack
 * (docs/idioms/a-free-variadic-argument-is-the-value-the-guard-compared.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020494F4.c  *       --func func_020494F4 --addr 0x020494F4 --cc 1.1p1 --arm
 */
void func_020494F4(struct ArcFile_020494F4 *arc, u32 member, u32 *out)
{
    u32 start;

    if (arc->count <= member) {
        func_02034734(func_020494F4_File, 713, func_020494F4_Msg,
                      arc->count, member);
    }

    func_02078B44((struct FSFile *)arc, arc->fatOffset + 0xc + member * 8, 0);
    func_02078B70((struct FSFile *)arc, &start, 4);
    *out = arc->imageBase + 8 + start;
}





/*
 * Return the absolute image offset of one archive member, the value
 * func_020494F4 writes through a pointer instead.
 *
 * The bounds assertion is the same five-argument call func_02049250
 * uses: the count is already in r3 from the guard's own `cmp`, so only
 * the member reaches the stack
 * (docs/idioms/a-free-variadic-argument-is-the-value-the-guard-compared.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02049578.c  *       --func func_02049578 --addr 0x02049578 --cc 1.1p1 --arm
 */
u32 func_02049578(struct ArcFile_02049578 *arc, u32 member)
{
    u32 start;

    if (arc->count <= member) {
        func_02034734(func_02049578_File, 725, func_02049578_Msg,
                      arc->count, member);
    }

    func_02078B44((struct FSFile *)arc, arc->fatOffset + 0xc + member * 8, 0);
    func_02078B70((struct FSFile *)arc, &start, 4);
    return arc->imageBase + 8 + start;
}





/*
 * Argument-swapping shim in front of the FS read: this entry point takes the
 * length before the destination, the reader takes them the other way round.
 * The swap costs the three-way `mov r3, r1 / mov r1, r2 / mov r2, r3`
 * shuffle and nothing else, so there is no frame at all and the call is a
 * tail call through a pool word and `bx ip`
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020495F4.c \
 *       --func func_020495F4 --addr 0x020495F4 --cc 1.1p1 --arm
 */
void func_020495F4(struct ArcFile_020495F4 *arc, u32 size, void *dst)
{
    func_02078B70((struct FSFile *)arc, dst, size);
}




asm void NHTTPi_GetConnection(void)
{
    ldr ip, =func_02078B44
    mov r2, #0
    bx ip
}





u16 func_0204961C(void *obj)
{
    return ((struct Obj17354 *)obj)->f4E;
}





u32 func_02049624(void *a0, void *a1, void *a2, void *a3, u32 a4, u32 a5, u16 a6)
{
    u32 ret = func_0204A1BC((int)a0, (int)a1, a5, a6);
    return func_0204968C((void *)ret, (u32)a2, (u32)a3, a4, a5);
}





/*
 * Seven-argument entry point of the text-printing layer: resolve a handle
 * through sub_0204A380 from the first two arguments and the last two, then
 * hand that handle plus the middle arguments to sub_0204968C.
 *
 * The sixth argument is read from the caller's stack slot twice, once as
 * sub_0204A380's third argument and once as sub_0204968C's fifth: the
 * compiler will not keep it in a callee-saved register across the first
 * call, because re-reading the incoming slot is free
 * (docs/idioms/keeping-a-cursor-in-a-named-local-costs-a-callee-saved-register.md).
 * The seventh is read with `ldrh`, which is what names it u16.  The third
 * and fourth arguments are parked in r5/r4 because they are live across
 * the first call.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02049658.c \
 *       --func sub_02049658 --addr 0x02049658 --cc 1.1p1 --arm
 */
u32 sub_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g)
{
    return sub_0204968C((void *)((u32)sub_0204A380(a, b, f, g)), c, d, e, f);
}





/*
 * The write-into-an-existing-slot counterpart of src/matched/sub_0204979C.c:
 * the same func_02062A4C lookup and the same "size of zero means the object's
 * own size at +0x10" rule, but the result goes straight into func_02040B1C
 * instead of coming back as a packed handle, and the caller's handle is
 * released either way. The whole body sits inside the `if`, which is why the
 * failed lookup is a forward branch to the release rather than a shared exit
 * block.
 *
 * `and r0, r6, #0xff` is func_02040B1C's first parameter being `u8`, not a
 * mask written in the source.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204968C.c \
 *       --func sub_0204968C --addr 0x0204968C --cc 1.1p1 --arm
 */
u32 sub_0204968C(void *buf, u32 a1, u32 a2, u32 a3, u32 unused)
{
    struct Res *res;

    if (func_02062A4C(buf, (void **)(&res)) != 0) {
        if (a3 == 0) {
            a3 = res->unk_10;
        }
        func_02040B1C((u8)a1, (const void *)res->unk_14, a3, a2);
    }

    ENV_SetResourceSet(buf);
    return a3;
}





/*
 * Loads an archive member with the top bit of its allocation flag word
 * forced on, hands the loaded buffer to func_0204979C to be registered, and
 * releases the loader's handle again. Returning 0 on a failed load is the
 * `movs`/`moveq`/`popeq` triple: the load result is tested by the move that
 * stores it, so no separate `cmp` appears.
 *
 * The flag word is the sixth argument and arrives as a halfword, and
 * func_0204A1BC's fourth parameter is `u16`, which is what turns
 * `(flags & 0x7FFF) | 0x8000` into an `and`/`orr` pair followed by a
 * `lsl #16`/`lsr #16` truncation rather than a single `orr`.
 *
 * The twin of src/matched/sub_02049740.c, differing only in which loader it
 * calls. func_0204A1BC has thirteen further callers image-wide and
 * func_0204979C its second caller at 0x02049780, so both resolve through the
 * `label` class.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020496E4.c \
 *       --func sub_020496E4 --addr 0x020496E4 --cc 1.1p1 --arm
 */
u32 sub_020496E4(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags)
{
    void *buf;
    u32 res;

    buf = (void *)func_0204A1BC((u32)a0, (u32)a1, (u32)a4, (u16)((flags & 0x7FFF) | 0x8000));
    if (buf == 0) {
        return 0;
    }

    res = func_0204979C(buf, a2, a3);
    ENV_SetResourceSet(buf);
    return res;
}





/*
 * Loads an archive member with the top bit of its allocation flag word
 * forced on, hands the loaded buffer to func_0204979C to be registered, and
 * releases the loader's handle again. Returning 0 on a failed load is the
 * `movs`/`moveq`/`popeq` triple: the load result is tested by the move that
 * stores it, so no separate `cmp` appears.
 *
 * The flag word is the sixth argument and arrives as a halfword, and
 * func_0204A380's fourth parameter is `u16`, which is what turns
 * `(flags & 0x7FFF) | 0x8000` into an `and`/`orr` pair followed by a
 * `lsl #16`/`lsr #16` truncation rather than a single `orr`.
 *
 * func_0204A380 resolves through the `matched` class against
 * src/matched/func_0204A380.c; func_0204979C through the `label` class, its
 * outside witness being the second caller at 0x02049724.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02049740.c \
 *       --func sub_02049740 --addr 0x02049740 --cc 1.1p1 --arm
 */
u32 sub_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags)
{
    void *buf;
    u32 res;

    buf = func_0204A380(a0, a1, a4, (u16)((flags & 0x7FFF) | 0x8000));
    if (buf == 0) {
        return 0;
    }

    res = func_0204979C(buf, a2, a3);
    ENV_SetResourceSet(buf);
    return res;
}





/*
 * Registers a loaded graphics buffer and answers a packed handle: the slot
 * index in the low halfword and the size the caller asked for (or the
 * object's own size at +0x10, when the caller passed zero) in the high one.
 * A failed lookup and a -1 from the allocator both return a plain 0.
 *
 * The two failure paths share one `mov r0, #0` / `pop` block at 0x020497F8.
 * Statements sit between the two guards, so only an explicit `goto` to a
 * trailing `return 0` reproduces that; written as two plain `return 0`
 * statements mwcc predicates both epilogues instead and 53 of 100 bytes move
 * (docs/idioms/guards-separated-by-statements-share-an-exit-only-through-goto.md).
 *
 * The packed result is written `((u16)a2 << 16) | (u16)slot`, not the other
 * way round: the accumulator of a commutative chain is its second operand
 * (docs/idioms/the-accumulator-of-a-commutative-chain-is-its-second-operand.md),
 * and only this order leaves the low half in r0 and folds the high half in as
 * `orr r0, r0, r1, lsl #16`.
 *
 * func_02062A4C fills a caller-owned pointer through its second argument, so
 * the local is read back twice, once inside the `a2 == 0` arm and once for
 * the unconditional `+0x14` field. That is why the pair of `ldr` from `[sp]`
 * straddles the predicated `ldreq`: the conditional read cannot be shared
 * with the unconditional one.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204979C.c \
 *       --func sub_0204979C --addr 0x0204979C --cc 1.1p1 --arm
 */
u32 sub_0204979C(void *buf, u32 a1, u32 a2)
{
    struct Res *res;
    s32 slot;

    if (func_02062A4C(buf, (void **)(&res)) == 0) {
        goto fail;
    }

    if (a2 == 0) {
        a2 = res->unk_10;
    }

    slot = func_02040B58(a1, (const void *)res->unk_14, a2);
    if (slot == -1) {
        goto fail;
    }

    return ((u16)a2 << 16) | (u16)slot;

fail:
    return 0;
}





/*
 * Byte-correct, capped at MATCH. Blocked on: func_0204982C (0x0204982C) has
 * exactly one branch reference in the whole image, the `bl` at 0x02049824
 * inside this function, and it begins at the first byte past this function's
 * own extent (02049800..0204982C), so no evidence class witnesses it. This
 * used to print EXACT anyway (`compare()` claimed EXACT from literal byte
 * equality alone, without checking that every relocation field had actually
 * been resolved), because the PC24 field's compiler-emitted displacement to
 * the immediately-following address happens to coincide with the image's
 * bytes by plain adjacency, not by attestation; `compare()` now requires
 * `fb.mask` to be entirely hard before claiming EXACT, so this correctly
 * reports MATCH. It graduates for real only once 0x0204982C has an EXACT
 * entry of its own: src/pending/sub_0204982C.c is the C for it, stuck at
 * MATCH on the unattestable data address 0x020A135C. func_0204A380 resolves
 * normally (label, and src/matched/func_0204A380.c).
 *
 * A seven-argument front end that loads an archive member and hands the
 * buffer to the flush-and-dispatch worker; the flag word is passed straight
 * through as a halfword rather than having its top bit forced on, which is
 * what distinguishes this family member from src/matched/sub_02049740.c.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02049800.c \
 *       --func sub_02049800 --addr 0x02049800 --cc 1.1p1 --arm
 */
u32 sub_02049800(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6)
{
    return func_0204982C(func_0204A380(a0, a1, a5, a6), a2, a3, a4);
}




extern void (*g_020A135C[])(void *addr, u32 a1, u32 size);





/*
 * Byte-correct, capped at MATCH. Blocked on: g_020A135C (0x020A135C) is named
 * by exactly one word in the whole image, the pool word at 0x02049898 inside
 * this function, so the `literal` class has no witness outside the compared
 * range, and being plain data it has no other class available. The range is a
 * single function, so there is no cut to make. It needs a second reference
 * somewhere in the image, which does not exist, or an attested data
 * definition at 0x020A135C. The other three relocations resolve.
 *
 * This is the DMA-flush variant of src/matched/sub_0204968C.c: the same
 * func_02062A00 lookup (the sibling of func_02062A4C), the same "a size of
 * zero means the object's own size at +0x10" rule, then a `DC_FlushRange`
 * over the object's buffer and a dispatch through the five-entry function
 * table at 0x020A135C indexed by the second argument.
 *
 * The buffer pointer is read from the caller-owned local twice, once for the
 * flush and once for the dispatch, because the call between them may write
 * through the pointer the local holds.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0204982C.c \
 *       --func sub_0204982C --addr 0x0204982C --cc 1.1p1 --arm
 */
u32 sub_0204982C(void *buf, u32 kind, u32 a2, u32 size)
{
    struct Res *res;

    if (func_02062A00(buf, (void **)(&res)) != 0) {
        if (size == 0) {
            size = res->unk_10;
        }
        DC_FlushRange(res->unk_14, size);
        g_020A135C[kind](res->unk_14, a2, size);
    }

    ENV_SetResourceSet(buf);
    return size;
}




/*
 * Seven-argument front end: load an archive member with the top allocation
 * bit forced on, exactly as src/matched/sub_020496E4.c does, and forward the
 * buffer to func_02049A18 with two of its six arguments pinned to zero. The
 * handle is not released here; func_02049A18 does that itself (see its
 * near-miss note in docs/notes/func_02049A18.c.txt, which is where its
 * six-argument shape comes from).
 *
 * The two zeros are one `mov r3, #0` reused for the register argument and
 * the stack argument, so the stack store of a4 has to be emitted between the
 * two: writing the zeros first costs a second materialisation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204989C.c \
 *       --func sub_0204989C --addr 0x0204989C --cc 1.1p1 --arm
 */
void sub_0204989C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 flags)
{
    func_02049A18((void *)func_0204A1BC((u32)a0, (u32)a1, (u32)a5, (u16)((flags & 0x7FFF) | 0x8000)),
                  a2, a3, 0, a4, 0);
}




/*
 * The same two-step shape as sub_02049658, but the handle lookup forces
 * the top bit of its u16 selector on: `(g & 0x7fff) | 0x8000`.  0x7fff
 * does not fit an ARM rotated immediate, so it costs a pool word, while
 * 0x8000 is `orr r2, r2, #0x8000` in one instruction; the `lsl #16` /
 * `lsr #16` pair after them is the u16 truncation of the result, not a
 * bitfield (docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md
 * read the other way: an equal-amount pair is the narrowing cast).
 *
 * The second call gets two spliced zeros, one in r3 and one in the second
 * outgoing stack slot; a single `mov r3, #0` serves both, which is why it
 * lands between the two stack stores rather than before them.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020498F4.c \
 *       --func sub_020498F4 --addr 0x020498F4 --cc 1.1p1 --arm
 */
void sub_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g)
{
    sub_02049A18(sub_0204A380(a, b, f, (u16)((g & 0x7fff) | 0x8000)),
                 c, d, 0, e, 0);
}




/*
 * A whole translation unit, matched as one byte range.
 *
 * Sound / audio event trigger wrappers.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204994C.c \
 *       --addr 0x0204994C --arm
 */
u32 func_0204994C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7)
{
    u32 res = func_0204A1BC(a0, a1, a6, a7);
    return func_02049A18((void *)res, a2, a3, a4, a5, 0);
}




u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7)
{
    u32 res = (u32)func_0204A380(a0, a1, a6, a7);
    return func_02049A18((void *)res, a2, a3, a4, a5, 0);
}




u32 func_020499D4(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7)
{
    u32 res = (u32)func_0204A380(a0, a1, a6, a7);
    return func_02049A18((void *)res, a2, a3, a4, a5, 1);
}




/*
 * arc_tool.c (wave 13): the palette-upload worker the sound/palette front
 * ends of unit_0204994C.c, sub_0204989C.c and sub_020498F4.c forward to.
 * Look up the resource's palette block; default the size to the block's own
 * (+0x08); when `add` is non-zero, add it to every entry of the data at +0x0C
 * -- as halfwords (size / 2 of them) when func_0204169C says the channel is
 * not 8-bit, else as bytes; then upload through func_02040AF0 plus the
 * flag-selected commit (func_02041B6C / func_020409B4) or func_020409E0, and
 * release the resource either way.  Every `and rN, r7, #0xff` is a callee's
 * u8 channel parameter, not a cast in the source.
 *
 * WHAT CLOSED IT (docs/notes/func_02049A18.c.txt: 300 against 296, 122 out):
 * the callees take `u8 channel` and the caller passes the u32 unchanged; the
 * two loops each own a block-scoped counter (a shared `i` makes the compiler
 * hoist one `mov r3, #0` above the arm test, 4 bytes short); and inside each
 * block the counter is declared BEFORE the element pointer (the other order
 * swaps the two registers in both loops, 17 bytes).
 */
u32 func_02049A18(void *file, u32 channel, u32 a2, u32 add, u32 size, u32 flag)
{
    struct Pal *pal;

    if (func_02062B30(file, (void **)(&pal)) != 0) {
        if (size == 0)
            size = pal->size;
        if (add != 0) {
            if (func_0204169C((u8)channel) == 0) {
                u32 i;
                u16 *p = (u16 *)pal->data;
                for (i = 0; i < size / 2; i++)
                    p[i] += (u16)add;
            } else {
                u32 i;
                u8 *p = pal->data;
                for (i = 0; i < size; i++)
                    p[i] += (u8)add;
            }
        }
        if ((int)func_0204162C((u8)channel) != 0) {
            func_02040AF0((u8)channel, pal->data, size, a2);
            if (flag != 0)
                func_02041B6C(channel);
            else
                func_020409B4(channel);
        } else {
            func_020409E0((u8)channel, pal->data, size, a2);
        }
    }
    return func_020307B0(file);
}




/*
 * A whole translation unit range, matched as one byte range.
 *
 * Two sibling entry points of the text-printing layer, each a six-to-seven
 * argument forwarder that splices a zero in as the fourth argument of the
 * real worker (sub_02049B90 and sub_02049BDC respectively).
 *
 * The shape is the whole content: `stmdb sp!, {lr}` plus `sub sp, #0xc`
 * builds the outgoing stack argument area, the two incoming stack
 * arguments are lifted out at [sp,#0x10] and [sp,#0x14], and `stm sp,
 * {r3, lr}` writes the displaced r3 and the first lifted argument into
 * the callee's slots in one go.  Only then is r3 reloaded with the
 * spliced 0.  The last argument is read with `ldrh`, which is the only
 * evidence that it is a u16 rather than a word.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02049B40.c \
 *       --addr 0x02049B40 --arm
 */
void sub_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f)
{
    sub_02049B90(a, b, c, 0, d, e, f);
}




void sub_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f)
{
    sub_02049BDC(a, b, c, 0, d, e, f);
}




/*
 * One of two seven-argument entry points on the cell-actor system, an
 * address apart, that differ only in which half of func_02049C28's dispatch
 * they reach first (func_0204A380 in func_02049BDC, 0x0204A1BC here); both
 * then forward into 0x02049C28 itself.
 *
 * The seventh parameter is a u16: it is read off the caller's stack with
 * `ldrh` (a 32-bit parameter would be `ldr`), masked with the pooled 0x7FFF
 * and re-set to the 0x8000 bit before being passed as the fourth argument of
 * the dispatch call.  0x7FFF is not an ARM immediate, which is why it costs a
 * pool word rather than a `mov`.
 *
 * The second call's first argument is the first call's result: no register is
 * written for it, r0 is simply left as the callee returned it.  Declaring the
 * dispatch call's own first argument as a saved parameter instead costs the
 * function a callee-saved register, a 4-byte frame and 16 bytes.
 *
 * Complements func_02049BDC, which is a separate file on purpose: 0x02049C28
 * has five branch references image wide and three of them are inside
 * 0x02049C28 itself, so a `tu` spanning both wrappers loses every witness and
 * only the two single-function ranges keep one each.
 */
void func_02049B90(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6)
{
    u32 r = func_0204A1BC(a0, a1, 0, (u16)((a6 & 0x7fff) | 0x8000));
    func_02049C28((void *)r, a2, a3, a4, a5);
}




/*
 * The second half of the pair described in src/matched/func_02049B90.c: same
 * seven-argument shape, reaching func_0204A380 rather than func_0204A1BC
 * before forwarding into 0x02049C28.
 *
 * Kept as its own file deliberately.  Both halves call 0x02049C28, and
 * 0x02049C28 has five branch references image wide with three of them inside
 * 0x02049C28 itself, so a `tu` span over both wrappers has no witness left
 * for either call and caps at MATCH; as two single-function ranges each is the
 * other's witness and both are EXACT.
 */
void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6)
{
    u32 r = (u32)func_0204A380(a0, a1, 0, (u16)((a6 & 0x7fff) | 0x8000));
    func_02049C28((void *)r, a2, a3, a4, a5);
}




/*
 * arc_tool.c (wave 13): load a palette resource into VRAM.  With a loaded
 * resource file: look up its PMCP block (optional) and its PLTT block; when
 * the PLTT block is there, advance its data pointer by `offset`, and when the
 * caller passed size 0 take the block's own size (no PMCP) or the PMCP count
 * times 0x20 (format 3) / 0x200 (anything else), less `offset`; flush the
 * range and dispatch through the eight-entry loader table 0x020A1364 by
 * `kind`, wrapping kinds 2/6/3/7 (source order, which is what the emitted
 * bodies say) in the matching Begin/End extended-palette calls.  The file is
 * released either way.
 *
 * WHAT CLOSED IT (docs/notes/pkt_02049C28.c.txt: 20 bytes out, "a4 in r5 at
 * entry, v separately"):
 *   - there is no separate `v`: the size PARAMETER is the value that is
 *     defaulted, reduced by offset and passed on (`size = ...; size -=
 *     offset;`), which is why the image loads it into r5 at entry and keeps
 *     it there;
 *   - the early `if (file == 0) return;` the note's shape omitted (the
 *     image's `movs sb, r0` / `addeq` / `popeq`);
 *   - the two out-pointer locals declared PLTT first, PMCP second, so PMCP
 *     lands at sp+0 and PLTT at sp+4.
 * The table's const qualifier does not change the bytes.
 */
void func_02049C28(void *file, u32 kind, u32 offset, u32 dest, u32 size)
{
    struct Pltt *pltt;
    u16 *pmcp;
    int cmp;

    if (file == 0)
        return;
    cmp = func_02062AD4(file, (void **)(&pmcp));
    if (func_02062A98(file, (void **)(&pltt)) != 0) {
        pltt->data += offset;
        if (size == 0) {
            if (cmp == 0)
                size = pltt->size;
            else
                size = *pmcp * (pltt->fmt == 3 ? 0x20 : 0x200);
            size -= offset;
        }
        func_020862F0(pltt->data, size);
        switch (kind) {
        case 2:
            func_0207F308();
            g_020A1364[kind](pltt->data, dest, size);
            func_0207F428();
            break;
        case 6:
            func_0207F5B0();
            g_020A1364[kind](pltt->data, dest, size);
            func_0207F65C();
            break;
        case 3:
            func_0207F47C();
            g_020A1364[kind](pltt->data, dest, size);
            func_0207F560();
            break;
        case 7:
            func_0207F6A8();
            g_020A1364[kind](pltt->data, dest, size);
            func_0207F754();
            break;
        case 0:
        case 1:
        case 4:
        case 5:
        default:
            g_020A1364[kind](pltt->data, dest, size);
            break;
        }
    }
    func_020307B0(file);
}




/*
 * Cell-actor binding helpers.  Each binds an actor of a given kind through
 * func_0204A1BC (kind table 1, 5-argument form) or func_0204A380 (kind
 * table 2, wrapper over func_0204A39C), runs the per-kind hook, and releases
 * the actor again when the hook fails.  func_02049F34 / func_02049F78 are
 * the 4-argument forms and pass 0 as the third argument.
 */
void *func_02049DB4(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = (void *)func_0204A1BC(a0, a1, a2, a4);
    if (res != 0) {
        if (!func_02062A4C(res, (void **)a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}




void *func_02049DF4(void *a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = func_0204A380(a0, a1, a2, a4);
    if (res != 0) {
        if (!func_02062A4C(res, (void **)a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}




void *func_02049E34(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = (void *)func_0204A1BC(a0, a1, a2, a4);
    if (res != 0) {
        if (!func_02062A00(res, (void **)a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}




void *func_02049E74(void *a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = func_0204A380(a0, a1, a2, a4);
    if (res != 0) {
        if (!func_02062A00(res, (void **)a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}




void *func_02049EB4(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = (void *)func_0204A1BC(a0, a1, a2, a4);
    if (res != 0) {
        if (!func_02062B30(res, (void **)a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}




void *func_02049EF4(void *a0, u32 a1, u32 a2, void **out, u16 a4)
{
    void *res = func_0204A380(a0, a1, a2, a4);
    if (res != 0) {
        if (!func_02062B30(res, out)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}




void *func_02049F34(u32 a0, u32 a1, u32 a2, u16 a3)
{
    void *res = (void *)func_0204A1BC(a0, a1, 0, a3);
    if (res != 0) {
        if (!func_02062A98(res, (void **)a2)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}




void *func_02049F78(void *a0, u32 a1, u32 a2, u16 a3)
{
    void *res = func_0204A380(a0, a1, 0, a3);
    if (res != 0) {
        if (!func_02062A98(res, (void **)a2)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}




void *func_02049FBC(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = (void *)func_0204A1BC(a0, a1, a2, a4);
    if (res != 0) {
        if (!func_02062820((int)res, (int *)a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}




void *func_02049FFC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = func_0204A380(a0, a1, a2, a4);
    if (res != 0) {
        if (!func_02062820((int)res, (int *)a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}




void *func_0204A03C(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = (void *)func_0204A1BC(a0, a1, a2, a4);
    if (res != 0) {
        if (!func_02062670(res, a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}




/*
 * A whole translation unit, matched as one byte range.
 */
void *func_0204A07C(void *a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = func_0204A380(a0, a1, a2, a4);
    if (res != 0) {
        if (!func_02062670(res, a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}




void *func_0204A0BC(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = (void *)func_0204A1BC(a0, a1, a2, a4);
    if (res != 0) {
        if (!func_02062920((u32)res, (u32 *)a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}




void *func_0204A0FC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = func_0204A380(a0, a1, a2, a4);
    if (res != 0) {
        if (!func_02062920((u32)res, (u32 *)a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}




void *func_0204A13C(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = (void *)func_0204A1BC(a0, a1, a2, a4);
    if (res != 0) {
        if (!func_0206267C(res, a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}




void *func_0204A17C(void *a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = func_0204A380(a0, a1, a2, a4);
    if (res != 0) {
        if (!func_0206267C(res, a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}




/*
 * arc_util.c's "open a member and read it" entry.  The three __LINE__
 * constants 1599, 1603 and 1611 are the only three the pool carries, and
 * each is the fifth argument of a func_02030734 call whose fourth
 * argument is the file-name word at 0x020A7F30 ("arc_util.c").
 */
int func_0204A1BC(int a0, int a1, int a2, u16 a3)
{
    int t;
    int r;
    int t2;

    if (a2 != 0) {
        t = func_020490A8(a0, a1);
        r = (int)func_02030734((u16)((a3 & 0x7fff) | 0x8000), t, 0, sArcUtil3730, 1599);
    } else {
        t = func_020490A8(a0, a1);
        r = (int)func_02030734(a3, t, 0, sArcUtil3730, 1603);
    }
    func_02048F4C((void *)r, a0, a1);
    if (a2 != 0) {
        t2 = (int)func_02030734(a3, ((struct Obj16074 *)r)->f0 >> 8, 0, sArcUtil3730, 1611);
        func_020834C0(r, t2);
        func_020307B0((void *)r);
        r = t2;
    }
    return r;
}




/*
 * The out-parameter twin of func_0204A1BC directly above it: the handle
 * func_020490A8 returns is written through the fifth (stack) argument and
 * the same three arc_util.c line numbers appear, shifted by 43.
 */
int func_0204A298(int a0, int a1, int a2, u16 a3, u32 *out)
{
    int r;
    int t;

    *out = func_020490A8(a0, a1);
    if (a2 != 0) {
        r = (int)func_02030734((u16)((a3 & 0x7fff) | 0x8000), *out, 0, sArcUtil3730, 1642);
    } else {
        r = (int)func_02030734(a3, *out, 0, sArcUtil3730, 1646);
    }
    func_02048F4C((void *)r, a0, a1);
    if (a2 != 0) {
        *out = ((struct Obj16075 *)r)->f0 >> 8;
        t = (int)func_02030734(a3, *out, 0, sArcUtil3730, 1656);
        func_020834C0(r, t);
        func_020307B0((void *)r);
        r = t;
    }
    return r;
}




void *func_0204A380(void *a0, u32 a1, u32 a2, u16 a3)
{
    u32 unk;
    return func_0204A39C(a0, a1, a2, a3, &unk);
}




/*
 * arc_util.c: load one archive member into a fresh heap block, optionally
 * LZ8-decompressing it into a second block.  ARM, not Thumb (the old
 * pending file compiled Thumb and read ISA).
 *
 * Shape facts the image fixes: the allocation is written in both arms of
 * the decompress test (the image cross-jumps them onto one call, with
 * *out_size re-read at the join); the heap id is a u32 narrowed at each
 * use; the NULL check wraps the rest rather than returning early, so every
 * exit shares `mov r0, r4; pop`; on a failed second allocation the result
 * is the NULL block (buf = d unconditionally).  The decompressing arm is
 * line 1709 and the plain arm 1713: the pool order says so.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204A39C.c  *       --func func_0204A39C --addr 0x0204A39C --arm --cc 1.1p1
 */
void *func_0204A39C(void *narc, int fileId, int decompress, u32 heapId, u32 *out_size)
{
    void *buf;
    void *d;

    *out_size = func_020493D4(narc, fileId);
    if (decompress != 0) {
        buf = func_02030734((u16)(((u16)heapId & 0x7FFF) | 0x8000), *out_size, 0, lbl_020A7F30, 1709);
    } else {
        buf = func_02030734((u16)heapId, *out_size, 0, lbl_020A7F30, 1713);
    }
    if (buf != 0) {
        func_0204932C(narc, fileId, buf);
        if (decompress != 0) {
            *out_size = ((struct Obj16076 *)buf)->f0 >> 8;
            d = func_02030734((u16)heapId, *out_size, 0, lbl_020A7F30, 1725);
            if (d != 0) {
                MI_UncompressLZ8(buf, d);
                func_020307B0(buf);
            }
            buf = d;
        }
    }
    return buf;
}
