/*
 * file:     g3d_util.c
 * unit:     yes
 * function: func_02047CFC, func_02047E54, func_02047E88, func_02047F4C, func_02048010, func_020480E4, func_02048120, func_02048258, func_020482B4, func_02048330, func_02048744, func_02048918, sub_020489F4, sub_02048A00, sub_02048A0C, sub_02048A18, func_02048A24, func_02048AC4, func_02048AD0, func_02048AE8, func_02048AFC, func_02048B0C, func_02048B20, func_02048B30, func_02048B44, func_02048B54, func_02048B60, func_02048B6C, func_02048B78, func_02048B80, func_02048B88, func_02048B94, func_02048B9C, func_02048BA8, func_02048BB0, func_02048BBC, func_02048BC4, func_02048C4C, func_02048C58, func_02048C80, func_02048CA4, func_02048CCC, func_02048CDC, func_02048CEC, func_02048D00, func_02048D54, func_02048DDC, func_02048E34, func_02048F4C, func_02048F60, func_02048F74, func_02048F88, func_02048F9C, func_02049030, func_020490A8, sub_020490F4, func_0204913C, func_0204919C, func_02049238, func_02049250, func_0204932C, func_020493D4, func_0204944C, func_020494F4, func_02049578, func_020495F4, NHTTPi_GetConnection, func_0204961C, func_02049624, sub_02049658, sub_0204968C, sub_020496E4, sub_02049740, sub_0204979C, sub_02049800, sub_0204982C, sub_0204989C, sub_020498F4, func_0204994C, func_02049990, func_020499D4, func_02049A18, sub_02049B40, sub_02049B68, func_02049B90, func_02049BDC, func_02049C28, func_02049DB4, func_02049DF4, func_02049E34, func_02049E74, func_02049EB4, func_02049EF4, func_02049F34, func_02049F78, func_02049FBC, func_02049FFC, func_0204A03C, func_0204A07C, func_0204A0BC, func_0204A0FC, func_0204A13C, func_0204A17C, func_0204A1BC, func_0204A298, func_0204A380, func_0204A39C
 * address:  0x02047CFC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from g3d_system.c at 0x02047CFC (__FILE__ anchor boundary, certain cut).
 *
 * symbols:
 *   func_02030734      0x02030734  arm
 *   func_020307B0   0x020307B0  arm
 *   func_020862F0  0x020862F0  arm
 *   DC_FlushRange  0x020862F0  arm
 *   g3d_util_file  0x020A7EB8  data
 *   g_020A7EC4     0x020A7EC4  data
 *   func_02048BC4_File  0x020A7ED4  data
 *   g_02146A68     0x02146A68  data
 *   func_02078A80  0x02078A80  arm
 *   func_02078B70  0x02078B70  arm
 *   func_02048D54_File  0x020A7EE0  data
 *   FS_InitFile             0x020788AC  arm
 *   FS_OpenFile     0x02078C18  arm
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
 *   func_02046858 0x02046858 arm
 *   func_02046A94 0x02046A94 arm
 *   func_02046B40 0x02046B40 arm
 *   func_02046C94 0x02046C94 arm
 *   func_02046CE0 0x02046CE0 arm
 *   func_02046DB8 0x02046DB8 arm
 *   func_02046E24 0x02046E24 arm
 *   func_02046E90 0x02046E90 arm
 *   func_02046EFC 0x02046EFC arm
 *   func_02046F50 0x02046F50 arm
 *   func_02046FF8 0x02046FF8 arm
 *   func_020470D0 0x020470D0 arm
 *   func_02047348 0x02047348 arm
 *   func_02047400 0x02047400 arm
 *   func_02047504 0x02047504 arm
 *   func_0204754C 0x0204754C arm
 *   func_02047554 0x02047554 arm
 *   func_02047564 0x02047564 arm
 *   func_0204762C 0x0204762C arm
 *   func_0204767C 0x0204767C arm
 *   func_02047738 0x02047738 arm
 *   func_02047788 0x02047788 arm
 *   func_02047790 0x02047790 arm
 *   func_0204779C 0x0204779C arm
 */
struct G3dNodeInit;
struct ArcFile;
struct G3dResourceRef;
struct G3dRenderObj;
struct G3dAnim;
struct G3dNode;
struct FSFile;
struct ArcHandle;
struct NitroFileHeader;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct G3dNode {
    u16 tag;
    u16 kind;
    u32 link;
    void *owner;
};

struct G3dNodeInit {
    u16 status;
    u16 result;
    u32 *tag;
};

struct G3dResourceRef {
    u16   tag;
    u16   kind;
    void *buf;
};

struct G3dModelRef {
    u8    pad_00[4];
    void *data;
};

struct G3dResHandle {
    u32 pad_00;
    u32 handle;
};

struct G3dRenderObj {
    u32            pad_00;
    struct G3dResHandle *texture;
    u32            pad_08;
    struct G3dResHandle *model;
};

struct G3dAnim {
    u16 tag;
    u16 kind;
    u32 link;
    const struct G3dRenderObj *renderObj;
};

typedef signed int     s32;

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

struct G3dCamera {
    u32     mode;
    u32     nearClip;
    u32     farClip;
    u32     fieldOfView;
    u32     aspectRatio;
    u32     scale;
    u32     roll;
    u32     flags;
    VecFx32 eye;
    VecFx32 target;
    VecFx32 up;
};

struct LightSlotValue {
    u16 red;
    u16 green;
    u16 blue;
    u16 flags;
};

struct LightSlotDesc {
    u8               slot;
    u8               pad01;
    struct LightSlotValue val;
};

struct LightSetDesc {
    struct LightSlotDesc *recs;
    u8               count;
};

struct Rgb555 {
    u16 r;
    u16 g;
    u16 b;
};

struct LightSlot {
    struct Rgb555 col;
    u16           flags;
};

struct ArcTableInfo {
    u32 * volatile entries;
    u32  count;
    u32  useRecords;
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

struct ArcHeaderScan {
    u32 fatSize;
    u16 fileCount;
    u8  pad_06[2];
    u32 nameTableSize;
};
struct LzHeader {
    u32 sizeAndType;
};
struct FatInfo {
    u32 offset;
    u16 count;
};







struct ArcHandleRaw {
    u8 raw[0x50];
};

struct UnpackedGfxBlock {
    u8 pad_00[0x10];
    u32 size;
    void *data;
};

struct UnpackedPalette {
    u8  pad00[8];
    u32 size;
    u8  data[1];
};

struct PaletteBlock {
    u32 fmt;
    u8  pad04[4];
    u32 size;
    u32 data;
};

typedef void (*GfxLoadFn)(u32 data, u32 dest, u32 size);

extern void *func_02030734(u16 heapID, u32 size, int clear, const char *file, int line);
extern u32 func_020307B0(void *p);
extern void func_020862F0(int a, int b);
extern void  DC_FlushRange(void *addr, u32 size);
extern s32 func_02078B70(struct FSFile *file, void *buffer, s32 length);
extern void func_02078A80(void *p);
extern void FS_InitFile(void *file);
extern void FS_OpenFile(struct ArcFile *arc, u32 value);
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
void func_02046858(const u32 *src);
void func_02046A94(u32 idx, const u16 *src);
void func_02046B40(u8 *a0);
int func_02046C94(void);
void func_02046CE0(struct G3dNodeInit *out, u32 *tag);
void *func_02046DB8(u32 a0, u32 a1);
void *func_02046E24(struct ArcHandle *a0, u32 a1);
void *func_02046E90(u32 a0, u32 a1);
void func_02046EFC(struct G3dResourceRef *p);
u32 func_02046F50(struct G3dResourceRef *p, u32 sel);
int func_02046FF8(int *self);
int func_020470D0(u32 *p);
int func_02047348(struct G3dModelRef *layer);
void *func_02047400(void *a0, u32 n, void *a2);
void func_02047504(struct G3dNode *p);
int func_0204754C(int *p);
int func_02047554(int *p);
struct G3dAnim *func_02047564(struct G3dRenderObj *a0, const struct G3dRenderObj *a1, int a2);
void func_0204762C(struct G3dNode *p);
void *func_0204767C(u32 a0, u32 *a1, int a2);
void func_02047738(struct G3dNode *p);
int func_02047788(int *p);
int func_02047790(int *p, int i);
u16 func_0204779C(void *p);
Util *func_02047CFC(u16 resCount, u16 objCount, u16 heapID);
void func_02047E54(Util *util);
u16 func_02047E88(Util *util, const Setup *setup);
u16 func_02047F4C(Util *util, const Setup *setup);
u16 func_02048010(Util *util, const Setup *setup, struct ArcHandle *extra);
void func_020480E4(Util *util, u32 i);
void func_02048120(Util *util, u16 index, const Setup *setup, u16 heapID);
void func_02048258(Util *util, u16 index, const Setup *setup, u32 heapID, struct ArcHandle *arc);
void func_020482B4(Util *util, u32 index);
void func_02048330(Util *util, u16 unitIdx, const Setup *setup, u16 heapID);
void func_02048744(Util *util, u16 unitIdx, const Setup *setup, u16 heapID);
void func_02048918(Util *util, u32 unitIdx);
u32 sub_020489F4(Util *util, int i);
u32 sub_02048A00(Util *util, int i);
u32 sub_02048A0C(Util *util, int i);
u32 sub_02048A18(Util *util, int i);
u32 *func_02048A24(u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8, Vec3 *a9, Vec3 *a10, Vec3 *a11, u16 heap);
u32 func_02048AC4(void *ptr);
void func_02048AD0(struct G3dCamera *l);
void func_02048AE8(struct G3dCamera *l, VecFx32 *out);
void func_02048AFC(struct G3dCamera *l, const VecFx32 *in);
void func_02048B0C(struct G3dCamera *l, VecFx32 *out);
void func_02048B20(struct G3dCamera *l, const VecFx32 *in);
void func_02048B30(struct G3dCamera *l, VecFx32 *out);
void func_02048B44(struct G3dCamera *l, const VecFx32 *in);
void func_02048B54(struct G3dCamera *l, u32 *out);
void func_02048B60(struct G3dCamera *l, const u32 *in);
void func_02048B6C(struct G3dCamera *l, const u32 *in);
int func_02048B78(struct G3dCamera *l);
void func_02048B80(struct G3dCamera *l, u32 v);
void func_02048B88(struct G3dCamera *l, u32 *out);
void func_02048B94(struct G3dCamera *l, u32 v);
void func_02048B9C(struct G3dCamera *l, u32 *out);
void func_02048BA8(struct G3dCamera *l, u32 v);
void func_02048BB0(struct G3dCamera *l, u32 *out);
void func_02048BBC(struct G3dCamera *l, u32 v);
struct LightSlotValue *func_02048BC4(const struct LightSetDesc *s, u16 heap);
u32 func_02048C4C(void *p);
void func_02048C58(struct LightSlot *slots);
void func_02048C80(struct LightSlot *slots, u8 i, struct Rgb555 *out);
void func_02048CA4(struct LightSlot *slots, u32 i, struct Rgb555 *in);
void func_02048CCC(struct LightSlot *slots, u8 i, u16 *out);
void func_02048CDC(struct LightSlot *slots, u32 i, u16 *in);
void func_02048CEC(u32 a, u32 b);
void func_02048D00(void *dst, u32 archive_id, u32 member, u32 offset, u32 size);
void *func_02048D54(u32 archive_id, u32 member, u16 heap, u32 offset, u32 size);
void func_02048DDC(struct ArcFile *arc, u32 id);
u32 func_02048E34(struct ArcHandle *arc, u32 member, u32 base, u32 size);
void func_02048F4C(void *dst, u32 archive_id, u32 member);
void *func_02048F60(u32 archive_id, u32 member, u16 heap);
void func_02048F74(void *dst, u32 archive_id, u32 member, u32 offset, u32 size);
void *func_02048F88(u32 archive_id, u32 member, u16 heap, u32 offset, u32 size);
void *func_02048F9C(const char *path, u32 a, u16 heap);
u32 func_02049030(u32 a);
u32 func_020490A8(u32 a, u32 b);
void *sub_020490F4(u32 id, u16 heap);
void *func_0204913C(void *a0, u32 a1, u16 heap);
void func_0204919C(struct ArcHandle *arc);
void func_02049238(void *arc);
void *func_02049250(struct ArcHandle *arc, u32 member, u16 heap);
void func_0204932C(struct ArcHandle *arc, u32 member, void *dst);
u32 func_020493D4(struct ArcHandle *arc, u32 member);
void func_0204944C(struct ArcHandle *arc, u32 member, u32 offset, u32 size, void *dst);
void func_020494F4(struct ArcHandle *arc, u32 member, u32 *out);
u32 func_02049578(struct ArcHandle *arc, u32 member);
void func_020495F4(struct ArcHandleRaw *arc, u32 size, void *dst);
int NHTTPi_GetConnection(struct FSFile *file, long offset);
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
extern const char g3d_util_file[];
extern char  g_020A7EC4[];
extern const char func_02048BC4_File[];
extern struct ArcTableInfo g_02146A68;
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
extern const GfxLoadFn g_020A1364[];
extern const char  sArcUtil3730[];
extern const char lbl_020A7F30[];











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
void func_02047E54(Util *util)
{
    func_020307B0(util->objStat);
    func_020307B0(util->obj);
    func_020307B0(util->resStat);
    func_020307B0(util->res);
    func_020307B0(util);
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
u16 func_02048010(Util *util, const Setup *setup, struct ArcHandle *archive)
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
            func_02048258(util, i, setup, util->heapID, archive);
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
void func_020480E4(Util *util, u32 unitIdx)
{
    func_02048918(util, unitIdx);
    func_020482B4(util, unitIdx);
    util->unit[unitIdx].resIdx = -1;
    util->unit[unitIdx].resCount = -1;
    util->unit[unitIdx].objIdx = -1;
    util->unit[unitIdx].objCount = -1;
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
void func_02048120(Util *util, u16 unitIdx, const Setup *setup, u16 heapID)
{
    int count = util->unit[unitIdx].resCount;
    u32 base = util->unit[unitIdx].resIdx;
    u32 slotno;
    u32 *out;
    int i;
    const ResSetup *rec;
    void *node;

    for (i = 0; i < count; i++) {
        out = (u32 *)util->res;
        slotno = base + i;
        rec = &setup->resTbl[i];

        switch (rec->type) {
        case 0:
            out[slotno] = (u32)func_02046DB8(rec->arc, rec->dat);
            break;
        case 1:
            out[slotno] = (u32)func_02046E90(rec->arc, rec->dat);
            break;
        case 2:
            node = func_02030734(util->heapID, func_02046C94(), 0,
                                 g3d_util_file, 342);
            func_02046CE0(node,
                          (u32 *)((u32)func_02048F60(rec->arc, rec->dat,
                                             util->heapID)));
            out[slotno] = (u32)node;
            break;
        case 3:
            node = func_02030734(util->heapID, func_02046C94(), 0,
                                 g3d_util_file, 355);
            func_02046CE0(node,
                          (u32 *)((u32)func_02048F9C((const char *)rec->arc, rec->dat,
                                             util->heapID)));
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
void func_02048258(Util *util, u16 unitIdx, const Setup *setup, u32 heapID,
                   struct ArcHandle *arc)
{
    u16 count = util->unit[unitIdx].resCount;
    u16 base = util->unit[unitIdx].resIdx;
    int i;

    for (i = 0; i < count; i++) {
        ((u32 *)util->res)[base + i] =
            (u32)func_02046E24(arc, setup->resTbl[i].dat);
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
void func_020482B4(Util *util, u32 unitIdx)
{
    u16 count = util->unit[unitIdx].resCount;
    u16 base = util->unit[unitIdx].resIdx;
    int i;

    for (i = 0; i < count; i++) {
        u32 res = ((u32 *)util->res)[base + i];

        if (res != 0) {
            util->resStat[base + i] = 0;

            if (func_02046F50((struct G3dResourceRef *)res, 2) == 1)
                func_020470D0((u32 *)res);

            func_02046EFC((struct G3dResourceRef *)res);
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
    void *model;
    void *texture;
    void *renderObj;
    void **anims;
    const ObjSetup *objSetup;
    void *anim;
    int i, j;

    for (i = 0; i < objCount; i++) {
        objSetup = &setup->objTbl[i];
        if (getRes(util, resIdx, setup->objTbl[i].mdlResIdx, setup, &model) == 1)
            util->objStat[objIdx + i] |= 1;
        if (objSetup->texResIdx != objSetup->mdlResIdx) {
            if (func_02046F50(util->res[resIdx + objSetup->texResIdx], 1) == 1) {
                if (getRes(util, resIdx, objSetup->texResIdx, setup, &texture) == 1) {
                    util->objStat[objIdx + i] |= 2;
                    func_02046FF8(texture);
                }
            } else {
                texture = util->res[resIdx + objSetup->texResIdx];
                func_02046FF8(texture);
            }
        } else {
            texture = model;
            if (func_02047348(model) == 0)
                func_02046FF8(model);
        }
        renderObj = func_02047400(model, objSetup->mdlDatIdx, texture);
        anims = func_02030734((heapID & 0x7fff) | 0x8000, objSetup->anmCount * 4, 1,
                            g3d_util_file, 534);
        for (j = 0; j < objSetup->anmCount; j++) {
            if (objSetup->anmTbl[j].anmResIdx == 0xff)
                anim = 0;
            else
                anim = func_02047564(renderObj, util->res[resIdx + objSetup->anmTbl[j].anmResIdx],
                                  objSetup->anmTbl[j].anmDatIdx);
            anims[j] = anim;
        }
        util->obj[objIdx + i] = func_0204767C((u32)renderObj, (u32 *)anims, objSetup->anmCount);
        func_020307B0(anims);
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
    void *model;
    void *texture;
    void *renderObj;
    void **anims;
    const ObjSetup *objSetup;
    void *anim;
    int i, j;

    for (i = 0; i < objCount; i = (int)((char *)0 + i + 1)) {
        objSetup = &setup->objTbl[i];
        model = useRes(util, resIdx, setup->objTbl[i].mdlResIdx);
        if (objSetup->texResIdx != setup->objTbl[i].mdlResIdx) {
            if (func_02046F50(getResSlot(util, resIdx, objSetup->texResIdx), 1) == 1) {
                texture = useRes(util, resIdx, objSetup->texResIdx);
            } else {
                texture = getResSlot(util, resIdx, objSetup->texResIdx);
                func_02046FF8(texture);
            }
        } else {
            texture = model;
            if (func_02047348(model) == 0)
                func_02046FF8(model);
        }
        renderObj = func_02047400(model, objSetup->mdlDatIdx, texture);
        anims = func_02030734((heapID & 0x7fff) | 0x8000, objSetup->anmCount * 4, 1,
                            g3d_util_file, 609);
        for (j = 0; j < objSetup->anmCount; j++) {
            if (objSetup->anmTbl[j].anmResIdx == 0xff)
                anim = 0;
            else
                anim = func_02047564(renderObj, getResSlot(util, resIdx, objSetup->anmTbl[j].anmResIdx),
                                  objSetup->anmTbl[j].anmDatIdx);
            anims[j] = anim;
        }
        util->obj[objIdx + i] = func_0204767C((u32)renderObj, (u32 *)anims, objSetup->anmCount);
        func_020307B0(anims);
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
    void *renderObj;
    void *object;
    u16 anmCount;
    int i, j;

    for (i = 0; i < objCount; i++) {
        object = util->obj[objIdx + i];
        renderObj = (void *)func_02047788(object);
        anmCount = func_0204779C(object);
        for (j = 0; j < anmCount; j++)
            func_0204762C((struct G3dNode *)func_02047790(object, (u16)j));
        if (util->objStat[objIdx + i] & 0xfd) {
            void *texture = (void *)func_02047554(renderObj);
            func_020470D0(texture);
            func_02046EFC(texture);
        }
        if (util->objStat[objIdx + i] & 0xfe)
            func_02046EFC((struct G3dResourceRef *)func_0204754C(renderObj));
        func_02047504(renderObj);
        func_02047738(object);
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
u32 sub_020489F4(Util *util, int unitIdx)
{
    return util->unit[unitIdx].objIdx;
}






u32 sub_02048A00(Util *util, int unitIdx)
{
    return util->unit[unitIdx].objCount;
}






u32 sub_02048A0C(Util *util, int resIdx)
{
    return *(u32 *)((u8 *)util->res + resIdx * 4);
}






u32 sub_02048A18(Util *util, int objIdx)
{
    return *(u32 *)((u8 *)util->obj + objIdx * 4);
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
u32 *func_02048A24(u32 mode, u32 nearClip, u32 farClip, u32 fieldOfView, u32 aspectRatio, u32 scale, u32 roll, u32 flags,
                   Vec3 *eye, Vec3 *target, Vec3 *up, u16 heapID)
{
    u32 *p = (u32 *)func_02030734(heapID, 0x44, 0, g_020A7EC4, 0x38);

    p[0] = mode;
    p[1] = nearClip;
    p[2] = farClip;
    p[3] = fieldOfView;
    p[4] = aspectRatio;
    p[5] = scale;
    p[6] = roll;
    p[7] = flags;
    *(Vec3 *)(p + 8) = *eye;
    *(Vec3 *)(p + 11) = *target;
    *(Vec3 *)(p + 14) = *up;
    return p;
}






u32 func_02048AC4(void *camera)
{
    return func_020307B0(camera);
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
void func_02048AD0(struct G3dCamera *camera)
{
    func_02046858((const u32 *)camera);
    func_02046B40((u8 *)(&camera->eye));
}





void func_02048AE8(struct G3dCamera *camera, VecFx32 *out)
{
    *out = camera->eye;
}





void func_02048AFC(struct G3dCamera *camera, const VecFx32 *in)
{
    camera->eye = *in;
}





void func_02048B0C(struct G3dCamera *camera, VecFx32 *out)
{
    *out = camera->target;
}





void func_02048B20(struct G3dCamera *camera, const VecFx32 *in)
{
    camera->target = *in;
}





void func_02048B30(struct G3dCamera *camera, VecFx32 *out)
{
    *out = camera->up;
}





void func_02048B44(struct G3dCamera *camera, const VecFx32 *in)
{
    camera->up = *in;
}





void func_02048B54(struct G3dCamera *camera, u32 *out)
{
    *out = camera->scale;
}





void func_02048B60(struct G3dCamera *camera, const u32 *in)
{
    camera->scale = *in;
}





void func_02048B6C(struct G3dCamera *camera, const u32 *in)
{
    camera->roll = *in;
}





int func_02048B78(struct G3dCamera *camera)
{
    return camera->mode;
}





void func_02048B80(struct G3dCamera *camera, u32 v)
{
    camera->nearClip = v;
}





void func_02048B88(struct G3dCamera *camera, u32 *out)
{
    *out = camera->farClip;
}





void func_02048B94(struct G3dCamera *camera, u32 v)
{
    camera->farClip = v;
}





void func_02048B9C(struct G3dCamera *camera, u32 *out)
{
    *out = camera->nearClip;
}





void func_02048BA8(struct G3dCamera *camera, u32 v)
{
    camera->nearClip = v;
}





void func_02048BB0(struct G3dCamera *camera, u32 *out)
{
    *out = camera->farClip;
}





void func_02048BBC(struct G3dCamera *camera, u32 v)
{
    camera->farClip = v;
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
struct LightSlotValue *func_02048BC4(const struct LightSetDesc *set, u16 heapID)
{
    struct LightSlotValue *slots;
    int i;

    slots = (struct LightSlotValue *)func_02030734(heapID, 0x20, 1,
                                            func_02048BC4_File, 43);
    for (i = 0; i < set->count; i++) {
        struct LightSlotDesc *desc = &set->recs[i];
        u32 slot = desc->slot;

        slots[slot] = desc->val;
    }
    return slots;
}



u32 func_02048C4C(void *slots)
{
    return func_020307B0(slots);
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
void func_02048C58(struct LightSlot *slots)
{
    int i;

    for (i = 0; i < 4; i++) {
        func_02046A94((u8)i, (const u16 *)(&slots[i]));
    }
}









void func_02048C80(struct LightSlot *slots, u8 i, struct Rgb555 *out)
{
    *out = slots[i].col;
}









void func_02048CA4(struct LightSlot *slots, u32 i, struct Rgb555 *in)
{
    slots[i].col = *in;
}









void func_02048CCC(struct LightSlot *slots, u8 i, u16 *out)
{
    *out = slots[i].flags;
}









void func_02048CDC(struct LightSlot *slots, u32 i, u16 *in)
{
    slots[i].flags = *in;
}









void func_02048CEC(u32 entries, u32 count)
{
    g_02146A68.entries = (u32 *)entries;
    g_02146A68.count = count;
    g_02146A68.useRecords = 0;
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
void func_02048D00(void *dst, u32 archiveID, u32 memberIdx, u32 offset,
                   u32 size)
{
    struct ArcFile h;

    func_02048DDC(&h, archiveID);
    func_02078B70((struct FSFile *)(&h), dst, func_02048E34((struct ArcHandle *)&h, memberIdx, offset, size));
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
void *func_02048D54(u32 archiveID, u32 memberIdx, u16 heapID, u32 offset,
                    u32 size)
{
    struct ArcFile h;
    u32 memberSize;
    void *buf;

    func_02048DDC(&h, archiveID);
    memberSize = func_02048E34((struct ArcHandle *)&h, memberIdx, offset, size);
    buf = func_02030734(heapID, memberSize, 0, func_02048D54_File, 0xbb);
    func_02078B70((struct FSFile *)(&h), buf, memberSize);
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
void func_02048DDC(struct ArcFile *arc, u32 archiveID)
{
    FS_InitFile(arc);
    if (g_02146A68.useRecords == 0) {
        FS_OpenFile(arc, g_02146A68.entries[archiveID]);
    } else {
        u32 *tbl = (u32 *)g_02146A68.entries;
        struct ArcRecord *rec = (struct ArcRecord *)tbl + archiveID;
        u32 end = rec->end;
        u32 start = rec->start;

        FS_CreateFileFromMemory(arc, (void *)start, end - start);
    }
}








u32 func_02048E34(struct ArcHandle *arc, u32 memberIdx, u32 skip, u32 size)
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
    if (info.count <= memberIdx) {
        func_02034734(func_02048DDC_File, 0xfb, func_02048DDC_Msg, info.count,
                      memberIdx);
    }

    off = fatOffset + info.offset;
    FS_SeekFile(arc, off + 4, 0);
    FS_ReadFile(arc, &tmp, 4);
    off += tmp;
    FS_SeekFile(arc, fatOffset + 0xc + memberIdx * 8, 0);

    FS_ReadFile(arc, range, 8);
    FS_SeekFile(arc, skip + (off + 8 + range[0]), 0);

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
void func_02048F4C(void *dst, u32 archiveID, u32 memberIdx)
{
    func_02048D00(dst, archiveID, memberIdx, 0, 0);
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
void *func_02048F60(u32 archiveID, u32 memberIdx, u16 heapID)
{
    return func_02048D54(archiveID, memberIdx, heapID, 0, 0);
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
void func_02048F74(void *dst, u32 archiveID, u32 memberIdx, u32 offset,
                   u32 size)
{
    func_02048D00(dst, archiveID, memberIdx, offset, size);
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
void *func_02048F88(u32 archiveID, u32 memberIdx, u16 heapID, u32 offset,
                    u32 size)
{
    return func_02048D54(archiveID, memberIdx, heapID, offset, size);
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
void *func_02048F9C(const char *path, u32 memberIdx, u16 heapID)
{
    struct ArcFile file;
    void *p;
    u32 size;

    func_020788AC(&file);
    func_02078C18(&file, path);
    size = func_02048E34((struct ArcHandle *)(&file), memberIdx, 0, 0);
    p = func_02030734(heapID, size, 0, func_02048F9C_File, 0x182);
    func_02078B70((struct FSFile *)(&file), p, size);
    func_02078A80(&file);
    return p;
}







u32 func_02049030(u32 archiveID)
{
    char buf[0x48];
    int headerSize;
    u16 header[3];

    headerSize = 0;
    func_02048DDC((struct ArcFile *)buf, archiveID);
    func_02078B44((struct FSFile *)buf, 0xc, 0);
    func_02078B70((struct FSFile *)buf, &headerSize, 2);
    func_02078B44((struct FSFile *)buf, headerSize + 4, 0);
    func_02078B70((struct FSFile *)buf, header, 6);
    func_02078A80(buf);
    return header[2];
}







u32 func_020490A8(u32 archiveID, u32 memberIdx)
{
    char buf[0x48];
    u32 size;

    func_02048DDC((struct ArcFile *)buf, archiveID);
    size = func_02048E34((struct ArcHandle *)buf, memberIdx, 0, 0);
    func_02078A80(buf);
    return size;
}






/*
 * Constructor: take a 0x50-byte record from the debug allocator, tie it to
 * the caller's object through func_02048DDC, run the one-time init at
 * func_0204919C and hand the record back.  The allocator's __FILE__/__LINE__
 * pair is the usual ABS32 into the packed string area plus a pooled 0x209,
 * which is not an ARM rotated immediate.
 */
void *sub_020490F4(u32 archiveID, u16 heapID)
{
    void *rec = func_02030734(heapID, 0x50, 0, sub_020490F4_File, 0x209);

    func_02048DDC(rec, archiveID);
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
void *func_0204913C(void *buf, u32 size, u16 heapID)
{
    void *handle = func_02030734(heapID, 0x50, 0, func_0204913C_File, 0x21f);

    FS_InitFile(handle);
    FS_CreateFileFromMemory(handle, buf, size);
    func_0204919C(handle);
    return handle;
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
void func_0204919C(struct ArcHandle *arc)
{
    struct ArcHeaderScan scan;
    u32 off;

    arc->fatOffset = 0;
    func_02078B44((struct FSFile *)arc, 0xc, 0);
    func_02078B70((struct FSFile *)arc, &arc->fatOffset, 2);
    func_02078B44((struct FSFile *)arc, arc->fatOffset + 4, 0);
    func_02078B70((struct FSFile *)arc, &scan, 6);
    arc->count = scan.fileCount;
    off = arc->fatOffset + scan.fatSize;
    func_02078B44((struct FSFile *)arc, off + 4, 0);
    func_02078B70((struct FSFile *)arc, &scan.nameTableSize, 4);
    arc->imageBase = off + scan.nameTableSize;
}






void func_02049238(void *handle)
{
    func_02078A80(handle);
    func_020307B0(handle);
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
void *func_02049250(struct ArcHandle *arc, u32 memberIdx, u16 heapID)
{
    u32 range[2];
    void *buf;

    if (arc->count <= memberIdx) {
        func_02034734(func_02049250_File, 613, func_02049250_Msg,
                      arc->count, memberIdx);
    }

    func_02078B44((struct FSFile *)arc, arc->fatOffset + 0xc + memberIdx * 8, 0);
    func_02078B70((struct FSFile *)arc, range, 8);
    func_02078B44((struct FSFile *)arc, arc->imageBase + 8 + range[0], 0);

    buf = func_02030734(heapID, range[1] - range[0], 0, func_02049250_File, 619);
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
void func_0204932C(struct ArcHandle *arc, u32 memberIdx, void *dst)
{
    u32 range[2];

    if (arc->count <= memberIdx) {
        func_02034734(func_0204932C_File, 642, func_0204932C_Msg,
                      arc->count, memberIdx);
    }

    func_02078B44((struct FSFile *)arc, arc->fatOffset + 0xc + memberIdx * 8, 0);
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
u32 func_020493D4(struct ArcHandle *arc, u32 memberIdx)
{
    u32 range[2];

    if (arc->count <= memberIdx) {
        func_02034734(func_020493D4_File, 665, func_020493D4_Msg,
                      arc->count, memberIdx);
    }

    func_02078B44((struct FSFile *)arc, arc->fatOffset + 0xc + memberIdx * 8, 0);
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
void func_0204944C(struct ArcHandle *arc, u32 memberIdx, u32 offset, u32 size,
                   void *dst)
{
    u32 start;

    if (arc->count <= memberIdx) {
        func_02034734(func_0204944C_File, 689, func_0204944C_Msg,
                      arc->count, memberIdx);
    }

    func_02078B44((struct FSFile *)arc, arc->fatOffset + 0xc + memberIdx * 8, 0);
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
void func_020494F4(struct ArcHandle *arc, u32 memberIdx, u32 *out)
{
    u32 start;

    if (arc->count <= memberIdx) {
        func_02034734(func_020494F4_File, 713, func_020494F4_Msg,
                      arc->count, memberIdx);
    }

    func_02078B44((struct FSFile *)arc, arc->fatOffset + 0xc + memberIdx * 8, 0);
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
u32 func_02049578(struct ArcHandle *arc, u32 memberIdx)
{
    u32 start;

    if (arc->count <= memberIdx) {
        func_02034734(func_02049578_File, 725, func_02049578_Msg,
                      arc->count, memberIdx);
    }

    func_02078B44((struct FSFile *)arc, arc->fatOffset + 0xc + memberIdx * 8, 0);
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
void func_020495F4(struct ArcHandleRaw *arc, u32 size, void *dst)
{
    func_02078B70((struct FSFile *)arc, dst, size);
}




int NHTTPi_GetConnection(struct FSFile *file, long offset)
{
    return func_02078B44(file, offset, 0);
}





u16 func_0204961C(void *obj)
{
    return ((struct ArcHandle *)obj)->count;
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
    struct UnpackedGfxBlock *res;

    if (func_02062A4C(buf, (void **)(&res)) != 0) {
        if (a3 == 0) {
            a3 = res->size;
        }
        func_02040B1C((u8)a1, (const void *)res->data, a3, a2);
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
    struct UnpackedGfxBlock *res;
    s32 slot;

    if (func_02062A4C(buf, (void **)(&res)) == 0) {
        goto fail;
    }

    if (a2 == 0) {
        a2 = res->size;
    }

    slot = func_02040B58(a1, (const void *)res->data, a2);
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
    struct UnpackedGfxBlock *res;

    if (func_02062A00(buf, (void **)(&res)) != 0) {
        if (size == 0) {
            size = res->size;
        }
        DC_FlushRange(res->data, size);
        g_020A135C[kind](res->data, a2, size);
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
    struct UnpackedPalette *pal;

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
    struct PaletteBlock *pltt;
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
int func_0204A1BC(int archiveID, int memberIdx, int decompress, u16 heapID)
{
    int size;
    int buf;
    int outBuf;

    if (decompress != 0) {
        size = func_020490A8(archiveID, memberIdx);
        buf = (int)func_02030734((u16)((heapID & 0x7fff) | 0x8000), size, 0, sArcUtil3730, 1599);
    } else {
        size = func_020490A8(archiveID, memberIdx);
        buf = (int)func_02030734(heapID, size, 0, sArcUtil3730, 1603);
    }
    func_02048F4C((void *)buf, archiveID, memberIdx);
    if (decompress != 0) {
        outBuf = (int)func_02030734(heapID, ((struct LzHeader *)buf)->sizeAndType >> 8, 0, sArcUtil3730, 1611);
        func_020834C0(buf, outBuf);
        func_020307B0((void *)buf);
        buf = outBuf;
    }
    return buf;
}




/*
 * The out-parameter twin of func_0204A1BC directly above it: the handle
 * func_020490A8 returns is written through the fifth (stack) argument and
 * the same three arc_util.c line numbers appear, shifted by 43.
 */
int func_0204A298(int archiveID, int memberIdx, int decompress, u16 heapID, u32 *out)
{
    int buf;
    int outBuf;

    *out = func_020490A8(archiveID, memberIdx);
    if (decompress != 0) {
        buf = (int)func_02030734((u16)((heapID & 0x7fff) | 0x8000), *out, 0, sArcUtil3730, 1642);
    } else {
        buf = (int)func_02030734(heapID, *out, 0, sArcUtil3730, 1646);
    }
    func_02048F4C((void *)buf, archiveID, memberIdx);
    if (decompress != 0) {
        *out = ((struct LzHeader *)buf)->sizeAndType >> 8;
        outBuf = (int)func_02030734(heapID, *out, 0, sArcUtil3730, 1656);
        func_020834C0(buf, outBuf);
        func_020307B0((void *)buf);
        buf = outBuf;
    }
    return buf;
}




void *func_0204A380(void *narc, u32 fileID, u32 decompress, u16 heapID)
{
    u32 size;
    return func_0204A39C(narc, fileID, decompress, heapID, &size);
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
void *func_0204A39C(void *narc, int fileID, int decompress, u32 heapID, u32 *out_size)
{
    void *buf;
    void *outBuf;

    *out_size = func_020493D4(narc, fileID);
    if (decompress != 0) {
        buf = func_02030734((u16)(((u16)heapID & 0x7FFF) | 0x8000), *out_size, 0, lbl_020A7F30, 1709);
    } else {
        buf = func_02030734((u16)heapID, *out_size, 0, lbl_020A7F30, 1713);
    }
    if (buf != 0) {
        func_0204932C(narc, fileID, buf);
        if (decompress != 0) {
            *out_size = ((struct LzHeader *)buf)->sizeAndType >> 8;
            outBuf = func_02030734((u16)heapID, *out_size, 0, lbl_020A7F30, 1725);
            if (outBuf != 0) {
                MI_UncompressLZ8(buf, outBuf);
                func_020307B0(buf);
            }
            buf = outBuf;
        }
    }
    return buf;
}
