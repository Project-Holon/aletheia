/*
 * file:     bmp.c
 * unit:     yes
 * function: func_0204335C, func_020433E0, func_0204349C, func_020434B4, func_020434CC, func_020434DC, func_02043534, func_02043558, func_02043570, func_02043588, func_02043598, func_020435F4, func_0204361C, func_0204363C, func_02043658, func_02043668, func_02043678, func_020436FC, func_02043754, func_020437AC, func_020437D4, func_020437DC, func_020437E4, func_020437EC, func_02043814, func_0204384C, func_02043900, func_02043994, func_020439A0, func_02043AAC, func_02043AF4, sub_02043B5C, func_02043B98, func_02043F4C, func_0204427C, func_020445F4, func_02044954, func_02044BF0, func_02044CE0, func_02044D88, func_02044EBC, func_02044F64, func_02045088, func_020450C8, func_020450F0, func_02045180, func_02045210, func_020452E8, func_02045334, func_02045374, func_020454E0, func_020456F8, func_02045730, func_02045738, func_02045740, func_02045748, func_02045750, func_02045758, func_02045760, func_02045768, func_02045770, func_02045778, func_02045780, func_02045788, func_02045790, func_02045798, func_020457A0, func_020457B0, func_02045808, func_0204581C, sub_02045838, sub_02045874, func_0204589C, sub_020458F8, sub_02045900, func_02045924, func_02045994, func_02045A00, func_02045A38, sub_02045A90, func_02045A98, func_02045AA8, func_02045AFC, func_02045B38, func_02045C04, func_02045C44, func_02045CAC, func_02045E04, func_02045E3C, func_02045EC0, func_02045F50, func_02045F5C, func_02046084, func_02046110, sub_02046180, sub_020461B8
 * address:  0x0204335C
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
 *   func_0208068C  0x0208068C  arm
 *   func_02082AC0  0x02082AC0  arm
 *   func_02080B98  0x02080B98  arm
 *   func_020808F4  0x020808F4  arm
 *   func_0208091C  0x0208091C  arm
 *   func_020809A0  0x020809A0  arm
 *   func_020809C8  0x020809C8  arm
 *   func_02080908  0x02080908  arm
 *   func_02080940  0x02080940  arm
 *   func_020809B4  0x020809B4  arm
 *   func_020809F0  0x020809F0  arm
 *   func_02080964  0x02080964  arm
 *   func_02080978  0x02080978  arm
 *   func_0207FDCC  0x0207FDCC  arm
 *   func_02080100  0x02080100  arm
 *   func_020806B0  0x020806B0  arm
 *   func_020807BC  0x020807BC  arm
 *   func_0207FFD0  0x0207FFD0  arm
 *   func_020801F8  0x020801F8  arm
 *   func_0208074C  0x0208074C  arm
 *   func_0208083C  0x0208083C  arm
 *   func_02080294  0x02080294  arm
 *   func_0208040C  0x0208040C  arm
 *   g_02146A48     0x02146A48  data
 *   gVisiblePlane  0x02146A48  data
 *   func_02043558  0x02043558  arm
 *   func_0207D46C  0x0207D46C  arm
 *   func_02030734  0x02030734  arm
 *   bmp_File       0x020A7E68  data
 *   func_020307B0  0x020307B0  arm
 *   func_02082A90  0x02082A90  arm
 *   func_0204384C_File  0x020A7E68  data
 *   func_0204A1BC       0x0204A1BC  arm
 *   func_02062A4C       0x02062A4C  arm
 *   OS_Terminate        0x02088234  arm
 *   func_02043900_File  0x020A7E68  data
 *   MIi_CpuCopy32       0x02082A90  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   g_02146A50     0x02146A50  data
 *   str_020A7E70   0x020A7E70  data
 *   func_0204169C  0x0204169C  arm
 *   func_0203FA08  0x0203FA08  arm
 *   func_0203FAF0  0x0203FAF0  arm
 *   sub_0203FB44  0x0203FB44  arm
 *   sub_020437AC  0x020437AC  arm
 *   sub_020307B0  0x020307B0  arm
 *   sub_020416B8  0x020416B8  arm
 *   sub_020437D4  0x020437D4  arm
 *   sub_02040B1C  0x02040B1C  arm
 *   func_02041680  0x02041680  arm
 *   func_020410D0  0x020410D0  arm
 *   func_02041300  0x02041300  arm
 *   sub_02041300  0x02041300  arm
 *   g_020A7E7C  0x020A7E7C  data
 *   sub_02030734  0x02030734  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   sStrbufEnd      0x020A7E7C  data
 *   d_020A7E7C  0x020A7E7C  data
 *   g_020A7E8C     0x020A7E8C  data
 *   func_020461B8  0x020461B8  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02049578  0x02049578  arm
 *   func_02049238  0x02049238  arm
 *   func_0204581C  0x0204581C  arm
 *   func_02045E04  0x02045E04  arm
 *   func_02046180  0x02046180  arm
 *   func_020495F4  0x020495F4  arm
 *   func_0204960C  0x0204960C  arm
 *   sub_02045E3C  0x02045E3C  arm
 *   sub_0204960C  0x0204960C  arm
 *   sub_020495F4  0x020495F4  arm
 *   sub_02045CAC  0x02045CAC  arm
 *   func_02082D44  0x02082D44  arm
 *   sub_02046110  0x02046110  arm
 *   sub_020461E4  0x020461E4  arm
 */
#include "../../matched/include/Obj04758.h"
#include "../../matched/include/Obj11411.h"
#include "../../matched/include/Obj03010.h"
#include "../../matched/include/Obj11412.h"
#include "../../matched/include/Obj08850.h"

struct BmpInfo;
struct NitroFileHeader;
struct Bmp;
struct Obj020437AC;
struct ArcFile;
struct Header;
struct MsgDataVol;
struct Buf;
struct Obj;
struct U16Vec;
struct MsgData;
typedef unsigned int u32;

typedef enum {
    GX_OBJVRAMMODE_CHAR_2D      = 0x00000000,
    GX_OBJVRAMMODE_CHAR_1D_32K  = 0x00000010,
    GX_OBJVRAMMODE_CHAR_1D_64K  = 0x00100010,
    GX_OBJVRAMMODE_CHAR_1D_128K = 0x00200010,
    GX_OBJVRAMMODE_CHAR_1D_256K = 0x00300010
} GXOBJVRamModeChar;

typedef enum { GX_VRAM_NONE = 0 } GXVRam;

struct DispVram {
    GXVRam main_bg;             /* +0x00 */
    GXVRam main_bg_expltt;      /* +0x04 */
    GXVRam sub_bg;              /* +0x08 */
    GXVRam sub_bg_expltt;       /* +0x0C */
    GXVRam main_obj;            /* +0x10 */
    GXVRam main_obj_expltt;     /* +0x14 */
    GXVRam sub_obj;             /* +0x18 */
    GXVRam sub_obj_expltt;      /* +0x1C */
    GXVRam teximage;            /* +0x20 */
    GXVRam texpltt;             /* +0x24 */
    GXOBJVRamModeChar main_mapping;     /* +0x28 */
    GXOBJVRamModeChar sub_mapping;      /* +0x2C */
};

struct Flags {
    u32 unk_00;
    u32 unk_04;
};

typedef unsigned short u16;

typedef unsigned char u8;

struct Bmp {
    u8  *pixels; /* 0x00 */
    u16  width;  /* 0x04 */
    u16  height; /* 0x06 */
    u16  depth;  /* 0x08 */
    u16  kind;   /* 0x0a */
};

struct Obj020437AC {
    void *buffer; /* 0x00 */
    u16   pad04[3];
    u16   unk0a;  /* 0x0a */
};

typedef signed int     s32;

struct BmpInfo {
    u16   cellsX;
    u16   cellsY;
    u32   format;
    u8    pad08[8];
    u32   size;
    void *src;
};

typedef short          s16;

struct CharBuf {
    u8  *pixels;
    u16 width;
    u16 height;
    u16 tileSize;
};

typedef signed short   s16_p07;

struct BgLayer {
    u16 tag : 15;
    u16 is8bpp : 1;
    u8  layer;
    u8  screenBase;
    u8  charBase;
    u8  width;
    u8  height;
    u8  width2;
    u8  height2;
    u8  palette;
    u16 charOffset;
    void *tiles;
};

struct Descriptor {
    u16   unk0_0 : 15;
    u16   unk0_15 : 1;
    u8    unk2;
    u8    unk3;
    u8    unk4;
    u8    unk5;
    u8    unk6;
    u8    unk7;
    u8    unk8;
    u8    unk9;
    u16   unkA;
    void *heap;
};

struct Descriptor_02045334 {
    u16   unk0;
    u8    unk2;
    u8    unk3;
    u8    unk4;
    u8    unk5;
    u8    unk6;
    u8    unk7;
    u8    unk8;
    u8    unk9;
    u16   unkA;
    void *heap;
};

struct Cfg {
    u8  pad_00[2];
    u8  unk_02;
    u8  unk_03;
    u8  unk_04;
    u8  unk_05;
    u8  unk_06;
    u8  unk_07;
    u8  unk_08;
    u8  unk_09;
    u16 unk_0a;
};



struct Descriptor_02045730 {
    u8    unk0;
    u8    unk1;
    u8    unk2;
    u8    unk3;
    u8    unk4;
    u8    unk5;
    u8    unk6;
    u8    unk7;
    u8    unk8;
    u8    unk9;
    u16   unkA;
    void *heap;
};

/*
 * The global based at 0x020A7E7C is one small object, not two independent
 * words: sub_020457B0 loads 0x020A7E80 out of a pool as the allocators
 * fourth argument, and that word is this symbol plus four
 * (docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md).
 * Reading it as a separate object splits one symbol into two and loses
 * the relocation: 0x020A7E80 has exactly one pool reference image-wide
 * and so no witness of its own, while the base has thirty-six.
 */
struct AllocStamp {
    u16  value;      /* 0x020A7E7C, the stamp every object copies to +0x8 */
    u16  pad;
    char site[1];    /* 0x020A7E80, the allocators fourth argument */
};

struct U16Vec {
    u16 capacity;
    u16 used;
    u32 magic;
    u16 slots[1];
};

struct Buf {
    u8  pad00[8];
    u16 w[0];
};

struct Strbuf {
    u16     cap;            /* +0x00 */
    u16     n;              /* +0x02 */
    u8      pad04[4];
    u16     buf[1];         /* +0x08 */
};

struct Buf_p12 {
    u16 len;
    u16 count;
    u32 unk_04;
    u8  data[0];
};

struct MsgEntry {
    u32 off;
    u16 len;
    u16 pad_06;
};

struct MsgFile {
    u16 langCount;
    u16 count;
    u32 size;
    u32 unk_08;
    u32 langOff[1];
};

struct MsgBank_22 {
    const struct MsgFile *file;
    void                 *base;
    struct MsgEntry       cache;
    u32                   origin;
    void                 *stream;
    u16                   heapId;
    u8                    langIndex;
    u8                    resident;
};

struct Rec {
    void *unk_00;
    void *unk_04;
    u8    pad_08[0xc];
    void *unk_14;
};

struct MsgFile_p14 {
    u16 langCount;
    u16 count;
    u32 unk_04;
    u32 unk_08;
    u32 langOff[1];
};

struct MsgBank_23 {
    const struct MsgFile_p14 *file;
    void                 *base;
    struct MsgEntry       cache;
    u32                   origin;
    void                 *stream;
    u16                   heapId;
    u8                    langIndex;
    u8                    resident;
};

struct Obj_02045E04 {
    u8 unk_00[1];
};

struct Head {
    u8  pad_00[2];
    u16 unk_02;
};

struct Obj_02045F50 {
    struct Head *head;
};

struct MsgEntry_p15 {
    u32 offset;
    u16 count;
    u16 pad;
};

struct MsgArchive {
    u16 bankCount;
    u16 unk02;
    u32 unk04;
    u32 unk08;
    u32 bankOffset[1];
};

struct MsgData {
    struct MsgArchive *archive; /* +0x00 */
    void *bank;                 /* +0x04 */
    struct MsgEntry_p15 entry;      /* +0x08 */
    u32 baseOffset;             /* +0x10 */
    void *file;                 /* +0x14 */
    u16 unk18;                  /* +0x18 */
    u8 bankIndex;               /* +0x1A */
    u8 mode;                    /* +0x1B */
};

struct MsgFileHdr {
    u16 langCount;
    u16 count;
    u32 size;
    u32 unk_08;
};

struct MsgDataVol {
    struct MsgArchive * volatile archive;
    void *bank;
    u32 unk08;
    u32 unk0C;
    u32 baseOffset;
    void *file;
    u16 unk18;
    u8 bankIndex;
    u8 mode;
};

struct Header {
    u16 count;
};

struct Obj {
    struct Header *header;
    u8             pad_04[0x16];
    u8             index;
    u8             enabled;
};

extern void func_0208068C(u32 banks);
extern void func_02082AC0(u32 data, void *dest, u32 size);
extern void func_02080B98(void);
extern int func_020808F4(void);
extern void func_02043558(void);
extern void func_0207D46C(void);
void sub_0204349C(void);
void sub_020434B4(void);
void sub_020434CC(void);
void sub_020434DC(u32 mask, u32 enable);
void sub_02043534(u32 planes);
void sub_02043558(void);
void func_02043570(void);
void func_02043588(void);
void sub_02043598(u32 mask, u32 enable);
void sub_020435F4(u32 planes);
void func_0204361C(void);
void func_0204363C(u32 swap);
u32 func_02043658(void);
u32 func_02043668(void);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void func_02082A90(void *dst, const void *src, u32 size);
extern int func_0204A1BC(int a0, int a1, int a2, int a3);
extern s32 func_02062A4C(struct NitroFileHeader *file, void **out);
extern void  OS_Terminate(void);
extern void MIi_CpuCopy32(const void *src, void *dst, u32 size);
extern void MI_CpuFill8(void *dest, u8 data, u32 size);
extern u8 func_0204169C(int channel);
extern u32 func_0203FA08(u32 layer, u32 size, u32 top);
extern u32 func_0203FAF0(u32 layer, u32 offset, u32 units);
extern void sub_0203FB44(u32 layer, u32 offset, u32 size);
extern void sub_020437AC(struct Obj020437AC *p);
extern u32 sub_020307B0(void *p);
extern u8 sub_020416B8(int channel);
extern void *sub_020437D4(const struct Bmp *bmp);
extern void sub_02040B1C(int index, const void *src, u32 size, u32 tile);
extern u8 func_02041680(int channel);
extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void func_02041300(u32 index, u16 tile, u8 x, u8 y, u8 w, u8 h, u8 m);
extern void sub_02041300(int a, int b, int c, int d, int e, int f, int g);
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site,
                          u16 tag);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern u32 func_02049578(struct ArcFile *arc, u32 member);
extern s32 func_020461B8(struct Header *h);
extern void func_02049238(void *handle);
extern void func_020495F4(struct ArcFile *arc, u32 size, void *dst);
extern void func_0204960C(void *stream, u32 pos);
extern void func_0204581C(struct U16Vec *vec);
extern void func_02045E04(struct Obj *o, u32 mode);
extern void func_02046180(struct Obj *o);
extern u32 sub_02045E3C(u16 *str, u32 count, u32 msgIndex);
extern void  sub_0204960C(void *stream, u32 offset);
extern void sub_020495F4(struct ArcFile *arc, u32 size, void *dst);
extern void  sub_02045CAC(struct MsgBank_23 *bank, u32 index, void *buf);
extern void func_02082D44(const void *src, void *dest, u32 size);
extern void sub_02046110(struct MsgData *msg);
extern s32 sub_020461E4(struct Header *h);
void sub_0204335C(u32 keep);
struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
struct Bmp *func_020436FC(void *pixels, u32 width, u32 height, u32 depth, u16 heap);
struct Bmp *func_02043754(void *pixels, u32 width, u32 height, u32 depth, u16 heap);
void func_020437AC(struct Obj020437AC *p);
void *func_020437D4(const struct Bmp *bmp);
u16 func_020437DC(const struct Bmp *bmp);
u16 func_020437E4(const struct Bmp *bmp);
u32 func_020437EC(const struct Bmp *bmp);
void func_02043814(struct Bmp *dst, const struct Bmp *src);
struct Bmp *func_0204384C(u32 arc, u32 member, u32 heap2, u32 heap);
void func_02043900(struct Bmp *b, struct BmpInfo *info, u32 heap);
u8 func_02043994(struct Bmp *b);
void func_020439A0(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u16 key);
void func_02043AAC(struct Bmp *dst, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8, u16 a9, u16 a10);
void func_02043AF4(struct Bmp *b, u32 a2, u32 a3, u32 a4, u16 a5, u8 a6);
void sub_02043B5C(struct CharBuf *buf, u8 value);
void func_02043B98(struct Bmp *src, struct Bmp *dst, s32 x, s32 y, s32 dx, s32 dy, u32 w, u32 h, u16 key);
void func_02043F4C(struct Bmp *src, struct Bmp *dst, s32 x, s32 y, s32 dx, s32 dy, u32 w, u32 h, u16 key);
void func_0204427C(struct Bmp *src, struct Bmp *dst, s32 x, s32 y, s32 dx, s32 dy, u32 w, u32 h, u16 key, u8 pal);
void func_020445F4(struct Bmp *src, struct Bmp *dst, u16 x, u16 y, s16_p07 dx, s16_p07 dy, u16 w, u16 h, u16 key);
void func_02044954(struct Bmp *src, struct Bmp *dst, u16 x, u16 y, s16_p07 dx, s16_p07 dy, u16 w, u16 h, u16 key);
void func_02044BF0(struct Bmp *s, s32 x, s32 y, s32 w, u16 h, u32 value);
void func_02044CE0(struct Bmp *s, s32 x, s32 y, s32 w, u16 h, u8 value);
void func_02044D88(struct Bmp *s, s32 x, s32 y, s32 w, u16 h, u8 value);
void func_02044EBC(struct Bmp *s, s32 x, s32 y, s32 w, u16 h, u8 value);
struct Bmp *func_02044F64(struct Bmp *src, u32 keep, u16 heap);
void sub_02045088(u16 heapId);
void sub_020450C8(void);
u32 sub_020450F0(u32 layer, u32 a, u32 b, u8 tiles, u8 c, u8 d, u8 slot);
u32 sub_02045180(u32 layer, u32 a, u32 b, u8 tiles, u8 c, u8 d, u32 offset);
struct BgLayer *sub_02045210(u32 layer, u32 screenBase, u32 charBase, u8 width, u8 height, u8 palette, u32 charOffset, u8 is8bpp);
u32 sub_020452E8(struct Descriptor *d);
void sub_02045334(struct Descriptor_02045334 *d);
void sub_02045374(struct Cfg *cfg);
void func_020454E0(struct Cfg *cfg, u16 base, u32 pal);
void sub_020456F8(struct Descriptor_02045334 *d);
u8 sub_02045730(struct Descriptor_02045730 *p);
u8 sub_02045738(struct Descriptor_02045730 *p);
u8 sub_02045740(struct Descriptor_02045730 *p);
u8 sub_02045748(struct Descriptor_02045730 *p);
u8 sub_02045750(struct Descriptor_02045730 *p);
u8 sub_02045758(struct Descriptor_02045730 *p);
u8 sub_02045760(struct Descriptor_02045730 *p);
u16 sub_02045768(struct Descriptor_02045730 *p);
void *sub_02045770(struct Descriptor_02045730 *p);
u8 sub_02045778(struct Descriptor_02045730 *p);
void sub_02045780(struct Descriptor_02045730 *p, u8 v);
void sub_02045788(struct Descriptor_02045730 *p, u8 v);
void sub_02045790(struct Descriptor_02045730 *p, u8 v);
void sub_02045798(struct Descriptor_02045730 *p, u8 v);
void sub_020457A0(u16 stamp);
struct U16Vec *sub_020457B0(u32 capacity, u32 heapId);
void sub_02045808(struct U16Vec *vec);
void sub_0204581C(struct U16Vec *vec);
void sub_02045838(struct U16Vec *dst, struct U16Vec *src);
struct U16Vec *sub_02045874(struct U16Vec *src, u32 heapId);
int func_0204589C(struct Buf *a, struct Buf *b);
u16 sub_020458F8(struct U16Vec *vec);
void sub_02045900(struct U16Vec *vec, u32 index);
void func_02045924(struct Strbuf *o, const u16 *src);
void func_02045994(struct Strbuf *o, const u16 *src, u32 len);
void func_02045A00(struct Buf_p12 *buf, const void *src, u32 n);
void sub_02045A38(struct U16Vec *vec, u16 *out, u32 n);
u16 *sub_02045A90(struct U16Vec *vec);
u16 func_02045A98(void);
void sub_02045AA8(struct U16Vec *dst, struct U16Vec *src);
void sub_02045AFC(struct U16Vec *vec, u16 value);
struct MsgBank_22 *sub_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
u32 func_02045C04(struct Rec *rec);
struct MsgBank_23 *func_02045C44(const void *file, u32 heapId);
void func_02045CAC(struct MsgBank_23 *bank, u32 index, void *dest);
void sub_02045E04(struct Obj_02045E04 *o, u32 mode);
u32 func_02045E3C(u16 *str, u32 count, u32 msgIndex);
void *sub_02045EC0(struct MsgBank_23 *bank, u32 index);
u16 sub_02045F50(const struct Obj_02045F50 *o);
void func_02045F5C(struct MsgData *msg, u32 msgIndex, u16 *str, u32 maxLen);
struct MsgFile *func_02046084(void *stream, u32 origin, u16 heapId);
void func_02046110(struct MsgDataVol *msg);
void sub_02046180(struct Obj *o);
s32 sub_020461B8(struct Header *h);
extern struct Flags g_02146A48;
extern u32 gVisiblePlane[2];
extern const char bmp_File[];
extern const char func_0204384C_File[];
extern const char func_02043900_File[];
extern u16 *g_02146A50;
extern const char str_020A7E70[];
extern struct AllocStamp g_020A7E7C;
extern u16 sStrbufEnd;
extern volatile u16 d_020A7E7C;
extern char g_020A7E8C[];



/*
 * Blank the graphics state: disable every VRAM bank the caller's mask does
 * not name, then zero main VRAM (0x06800000, 0xa4000 bytes), both OAM
 * halves (0x07000000 and 0x07000400, filled with 0xc0 so every sprite sits
 * off-screen) and both palette halves (0x05000000 and 0x05000400).
 * func_02082AC0 is the four-byte-granular clear helper, taking the fill
 * word first and the destination second.
 *
 * The 0x1ff mask is never pooled: the compiler already has 0xffff in a
 * register for the complement and rematerialises 0x1ff from it with
 * `sub r0, r1, #0xfe00`
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md).
 */
void sub_0204335C(u32 keep)
{
    func_0208068C((keep ^ 0xffff) & 0x1ff);

    func_02082AC0(0, (void *)0x06800000, 0xa4000);
    func_02080B98();

    func_02082AC0(0xc0, (void *)0x07000000, 0x400);
    func_02082AC0(0, (void *)0x05000000, 0x400);
    func_02082AC0(0xc0, (void *)0x07000400, 0x400);
    func_02082AC0(0, (void *)0x05000400, 0x400);
}


extern void func_0208091C(void);   /* GX_ResetBankForBGExtPltt */
extern int func_020809A0(void);
extern void func_020809C8(void);   /* GX_ResetBankForSubBGExtPltt */
extern void func_02080908(void);
extern void func_02080940(void);   /* GX_ResetBankForOBJExtPltt */
extern void func_020809B4(void);
extern void func_020809F0(void);   /* GX_ResetBankForSubOBJExtPltt */
extern int func_02080964(void);
extern void func_02080978(void);
extern void func_0207FDCC(GXVRam v);   /* GX_SetBankForBG */
extern void func_02080100(GXVRam v);   /* GX_SetBankForBGExtPltt */
extern void func_020806B0(GXVRam v);   /* GX_SetBankForSubBG */
extern void func_020807BC(GXVRam v);   /* GX_SetBankForSubBGExtPltt */
extern void func_0207FFD0(GXVRam v);   /* GX_SetBankForOBJ */
extern void func_020801F8(GXVRam v);   /* GX_SetBankForOBJExtPltt */
extern void func_0208074C(GXVRam v);   /* GX_SetBankForSubOBJ */
extern void func_0208083C(GXVRam v);   /* GX_SetBankForSubOBJExtPltt */
extern void func_02080294(GXVRam v);   /* GX_SetBankForTex */
extern void func_0208040C(GXVRam v);   /* GX_SetBankForTexPltt */

#define reg_GX_DISPCNT      (*(volatile u32 *)0x04000000)
#define reg_GXS_DB_DISPCNT  (*(volatile u32 *)0x04001000)

static inline void GX_SetOBJVRamModeChar(GXOBJVRamModeChar mode)
{
    reg_GX_DISPCNT = (u32)(reg_GX_DISPCNT & ~(0x00300000 | 0x00000010) | mode);
}

static inline void GXS_SetOBJVRamModeChar(GXOBJVRamModeChar mode)
{
    reg_GXS_DB_DISPCNT = (u32)(reg_GXS_DB_DISPCNT & ~(0x00300000 | 0x00000010) | mode);
}

/*
 * bg_sys.c: apply a VRAM bank descriptor.  Disable every bank, set the ten
 * bank assignments (TwlSDK GX_SetBankFor*, 0x0207FDCC..0x0208040C), then the
 * main and sub OBJ-VRAM character mapping through the SDK inlines
 * GX_SetOBJVRamModeChar / GXS_SetOBJVRamModeChar (nitro/gx/gx.h).
 *
 * Closed in wave 16 by the SDK-inline lever: the two mapping words are
 * GXOBJVRamModeChar enum fields passed straight into the inlines, and the
 * descriptor is `const`.  With u32 fields and parameters the same body is
 * 33 bytes out; with a non-const or volatile descriptor 29; every earlier
 * spelling (locals a/b, volatile struct) capped at 6 (r3/ip pair in the
 * DISPCNT tail, docs/notes/func_020433E0.c.txt).
 */
void func_020433E0(const struct DispVram *c)
{
    func_020808F4();
    func_0208091C();
    func_020809A0();
    func_020809C8();
    func_02080908();
    func_02080940();
    func_020809B4();
    func_020809F0();
    func_02080964();
    func_02080978();
    func_0207FDCC(c->main_bg);
    func_02080100(c->main_bg_expltt);
    func_020806B0(c->sub_bg);
    func_020807BC(c->sub_bg_expltt);
    func_0207FFD0(c->main_obj);
    func_020801F8(c->main_obj_expltt);
    func_0208074C(c->sub_obj);
    func_0208083C(c->sub_obj_expltt);
    func_02080294(c->teximage);
    func_0208040C(c->texpltt);
    GX_SetOBJVRamModeChar(c->main_mapping);
    GXS_SetOBJVRamModeChar(c->sub_mapping);
}


/*
 * The tail of the packet: two one-line mask-downs of the same 32-bit word
 * at +4 of the object that starts at 0x02146A48, and the wrapper that runs
 * both.  Each accessor keeps only the bits its own half owns (0x10 for the
 * first, 0x0f for the second), so calling both in sequence clears the word
 * outright; the wrapper is the reset path.
 *
 * Kept as one unit so the two `bl` sites in sub_020434CC are `local`: they
 * are that pair's only callers image-wide, and split into three files
 * neither could attest the other
 * (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md in
 * reverse).
 */
void sub_0204349C(void)
{
    g_02146A48.unk_04 = g_02146A48.unk_04 & 0x10;
}


void sub_020434B4(void)
{
    g_02146A48.unk_04 = g_02146A48.unk_04 & 0xf;
}


void sub_020434CC(void)
{
    sub_0204349C();
    sub_020434B4();
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * The engine-A visible-plane trio, against gVisiblePlane[1] and DISPCNT at
 * 0x04000000: toggle one plane only if the requested state differs, replace
 * the whole set, and reset to the one plane in bit 4.  The register address
 * is a rotated ARM immediate here (`mov r2, #0x4000000`), where the
 * engine-B twins at 0x02043598 / 0x020435F4 must pool 0x04001000.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020434DC.c \
 *       --addr 0x020434DC --arm
 */
void sub_020434DC(u32 mask, u32 enable)
{
    if (enable == 1) {
        if (gVisiblePlane[1] & mask) {
            return;
        }
    } else if (!(gVisiblePlane[1] & mask)) {
        return;
    }

    gVisiblePlane[1] ^= mask;
    *(volatile u32 *)0x04000000 =
        (*(volatile u32 *)0x04000000 & ~0x1f00) | (gVisiblePlane[1] << 8);
}


void sub_02043534(u32 planes)
{
    gVisiblePlane[1] = planes;
    *(volatile u32 *)0x04000000 =
        (*(volatile u32 *)0x04000000 & ~0x1f00) | (planes << 8);
}


void sub_02043558(void)
{
    gVisiblePlane[0] &= 0x10;
}


/*
 * Two of the engine-B visible-plane mask writers, 0x02043570-0x02043598.
 *
 *   0x02043570  keep only the four background bits of the software copy
 *               gVisiblePlane[0] (mask 0xF)
 *   0x02043588  the pair call: run the sibling at 0x02043558, which keeps
 *               only bit 4 (the OBJ plane), then the one above, so the two
 *               together clear the software copy outright
 *
 * 0x02043570 has exactly one branch reference image-wide, the `bl` at
 * 0x02043590 inside 0x02043588, so folding the two into one unit costs no
 * witness (docs/idioms/a-unit-attests-only-its-own-start-address.md): the
 * interior address is nobody else's sole witness.
 *
 * The mask constants are plain `and` immediates, not a bitfield: both fit an
 * ARM rotated immediate and neither carries a narrowing shift pair.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02043570.c \
 *       --addr 0x02043570 --cc 1.1p1 --arm
 */
void func_02043570(void)
{
    gVisiblePlane[0] &= 0xF;
}


void func_02043588(void)
{
    func_02043558();
    func_02043570();
}


/*
 * The engine-B half of the visible-plane toggle: if the requested state
 * already holds, return; otherwise flip the bit in the software copy at
 * gVisiblePlane[0] and rewrite bits 8..12 of GXS_DISPCNT (0x04001000) from
 * it.  The engine-A twin at 0x020434DC is the same code against
 * gVisiblePlane[1] and 0x04000000; that one is materialised with a `mov`
 * because 0x04000000 is an ARM rotated immediate while 0x04001000 is not
 * and costs a pool word.
 *
 * The register address is a cast constant, not a relocation, so this file's
 * only attestable site is gVisiblePlane.
 */
void sub_02043598(u32 mask, u32 enable)
{
    if (enable == 1) {
        if (gVisiblePlane[0] & mask) {
            return;
        }
    } else if (!(gVisiblePlane[0] & mask)) {
        return;
    }

    gVisiblePlane[0] ^= mask;
    *(volatile u32 *)0x04001000 =
        (*(volatile u32 *)0x04001000 & ~0x1f00) | (gVisiblePlane[0] << 8);
}


/*
 * Engine-B "replace the whole visible-plane set": store the software copy
 * and rewrite bits 8..12 of GXS_DISPCNT from it.  Twin of sub_02043534.
 */
void sub_020435F4(u32 planes)
{
    gVisiblePlane[0] = planes;
    *(volatile u32 *)0x04001000 =
        (*(volatile u32 *)0x04001000 & ~0x1f00) | (planes << 8);
}


/*
 * Three display-control leaves, 0x0204361C-0x02043668.  The two after the
 * first save no lr, so disasm.py does not label them and they print as a
 * run of `.word`s between literal pools; neither has a branch reference
 * anywhere in the image, so folding them into this unit costs no witness.
 *
 *   0x0204361C  reset the sub engine, then turn on bit 16 of GXS_DISPCNT
 *   0x0204363C  write the LCD-swap bit (bit 15) of POWCNT1 from bit 0 of
 *               the argument; the plain `orr ..., lsl #15` with no
 *               narrowing says this is arithmetic on the register word, not
 *               a one-bit bitfield (which would carry an `lsr #16` shifter
 *               operand, see the bitfield-cast idiom)
 *   0x02043658  read back gVisiblePlane[1], the engine-B software copy
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204361C.c \
 *       --addr 0x0204361C --cc 1.1p1 --arm
 */
void func_0204361C(void)
{
    func_0207D46C();
    *(volatile u32 *)0x04001000 |= 0x10000;
}


void func_0204363C(u32 swap)
{
    *(volatile u16 *)0x04000304 =
        (*(volatile u16 *)0x04000304 & ~0x8000) | (swap << 15);
}


u32 func_02043658(void)
{
    return gVisiblePlane[1];
}


/*
 * Read back gVisiblePlane[0], the engine-A software copy of the visible
 * plane set that sub_02043534 writes.  Twin of the third leaf in
 * src/matched/unit_0204361C.c, which reads element 1.  Saves no lr, so
 * disasm.py does not label it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02043668.c \
 *       --func func_02043668 --addr 0x02043668 --cc 1.1p1 --arm
 */
u32 func_02043668(void)
{
    return gVisiblePlane[0];
}



/*
 * TU: bmp.c.  The __FILE__ pointer at 0x020A7E68 reads "bmp.c", lines 97
 * and 103 here.
 *
 * Allocate a bitmap descriptor and its pixel buffer on the same heap.  The
 * width and height reach the descriptor multiplied by 8 (they arrive in
 * tiles), the buffer is width * height * depth bytes, and the descriptor is
 * allocated uncleared while the buffer is cleared.  The `__FILE__` pointer
 * is reloaded into r3 for the second call rather than kept, because r3 is
 * an argument register.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02043678.c \
 *       --func func_02043678 --addr 0x02043678 --cc 1.1p1 --arm
 */
struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap)
{
    struct Bmp *bmp;

    bmp = func_02030734(heap, sizeof(struct Bmp), 0, bmp_File, 97);

    bmp->width  = width * 8;
    bmp->height = height * 8;
    bmp->depth  = depth;

    bmp->pixels = func_02030734(heap, depth * (width * height), 1,
                                bmp_File, 103);
    bmp->kind = 0;

    return bmp;
}



/*
 * TU: bmp.c (__FILE__ 0x020A7E68, line 123).
 *
 * Wrap a pixel buffer the caller already owns in a fresh descriptor: same
 * 0xc-byte descriptor func_02043678 builds, but nothing is allocated for
 * the pixels and the kind byte at +0x0a is 1.  The heap id is the fifth
 * argument and arrives on the stack as a halfword.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020436FC.c  *       --func func_020436FC --addr 0x020436FC --cc 1.1p1 --arm
 */
struct Bmp *func_020436FC(void *pixels, u32 width, u32 height, u32 depth,
                            u16 heap)
{
    struct Bmp *bmp;

    bmp = func_02030734(heap, sizeof(struct Bmp), 0, bmp_File, 123);

    bmp->width  = width * 8;
    bmp->height = height * 8;
    bmp->pixels = pixels;
    bmp->depth  = depth;
    bmp->kind   = 1;

    return bmp;
}



/*
 * TU: bmp.c (__FILE__ 0x020A7E68, line 148).
 *
 * Wrap a pixel buffer the caller already owns in a fresh descriptor: same
 * 0xc-byte descriptor func_02043678 builds, but nothing is allocated for
 * the pixels and the kind byte at +0x0a is 2.  The heap id is the fifth
 * argument and arrives on the stack as a halfword.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02043754.c  *       --func func_02043754 --addr 0x02043754 --cc 1.1p1 --arm
 */
struct Bmp *func_02043754(void *pixels, u32 width, u32 height, u32 depth,
                            u16 heap)
{
    struct Bmp *bmp;

    bmp = func_02030734(heap, sizeof(struct Bmp), 0, bmp_File, 148);

    bmp->width  = width * 8;
    bmp->height = height * 8;
    bmp->pixels = pixels;
    bmp->depth  = depth;
    bmp->kind   = 2;

    return bmp;
}



/*
 * Destructor: release the owned buffer at +0x00 first, but only when the
 * halfword count at +0x0a is zero, then release the object itself.  The
 * guard is inverted in the original (`bne` over the first release), which
 * is the source order of a plain `if (p->unk0a == 0)` with no else.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020437AC.c \
 *       --func func_020437AC --addr 0x020437AC --cc 1.1p1 --arm
 */
void func_020437AC(struct Obj020437AC *p)
{
    if (p->unk0a == 0)
        func_020307B0(p->buffer);

    func_020307B0(p);
}



/*
 * TU: bmp.c.  Accessor for the pixel buffer of a bitmap descriptor.
 * Saves no lr, so disasm.py leaves it unlabelled and it prints inside a run
 * of `.word`s; it is kept as its own file rather than folded into a unit so
 * that its callers have a `matched` witness.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020437D4.c  *       --func func_020437D4 --addr 0x020437D4 --cc 1.1p1 --arm
 */
void *func_020437D4(const struct Bmp *bmp)
{
    return bmp->pixels;
}



/*
 * TU: bmp.c.  Accessor for the pixel width of a bitmap descriptor.
 * Saves no lr, so disasm.py leaves it unlabelled and it prints inside a run
 * of `.word`s; it is kept as its own file rather than folded into a unit so
 * that its callers have a `matched` witness.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020437DC.c  *       --func func_020437DC --addr 0x020437DC --cc 1.1p1 --arm
 */
u16 func_020437DC(const struct Bmp *bmp)
{
    return bmp->width;
}



/*
 * TU: bmp.c.  Accessor for the pixel height of a bitmap descriptor.
 * Saves no lr, so disasm.py leaves it unlabelled and it prints inside a run
 * of `.word`s; it is kept as its own file rather than folded into a unit so
 * that its callers have a `matched` witness.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020437E4.c  *       --func func_020437E4 --addr 0x020437E4 --cc 1.1p1 --arm
 */
u16 func_020437E4(const struct Bmp *bmp)
{
    return bmp->height;
}



/*
 * TU: bmp.c.  Byte size of a bitmap's pixel buffer: depth * ((width / 8) * height / 8). The first division is an `lsr` because the width comes out of a u16 field and is known non-negative; the second is a signed `asr` triple because it divides an int product.
 * Saves no lr, so disasm.py leaves it unlabelled and it prints inside a run
 * of `.word`s; it is kept as its own file rather than folded into a unit so
 * that its callers have a `matched` witness.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020437EC.c  *       --func func_020437EC --addr 0x020437EC --cc 1.1p1 --arm
 */
u32 func_020437EC(const struct Bmp *bmp)
{
    return bmp->depth * ((bmp->width / 8) * bmp->height / 8);
}



/*
 * TU: bmp.c.  Copy one bitmap's pixels over another's, clipped to whichever
 * of the two buffers is smaller.  Both sizes come from func_020437EC rather
 * than from the descriptors directly, and the comparison is unsigned
 * (`movlo`), so the sizes are u32.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02043814.c \
 *       --func func_02043814 --addr 0x02043814 --cc 1.1p1 --arm
 */
void func_02043814(struct Bmp *dst, const struct Bmp *src)
{
    u32 size;
    u32 other;

    size = func_020437EC(dst);
    other = func_020437EC(src);

    if (other < size)
        size = other;

    func_02082A90(dst->pixels, src->pixels, size);
}



/*
 * bmp.c's "load a bitmap out of an archive" entry point,
 * 0x0204384C-0x02043900 including its three pool words.  It allocates the
 * twelve-byte bitmap object ("bmp.c", line 266), opens the archive member,
 * asks 0x02062A4C for the decoded header, hands both to the constructor at
 * 0x02043900 and releases the archive handle.  A header that does not
 * resolve is fatal: `OS_Terminate` and then NULL.
 *
 * The archive-handle argument is `(heap & 0x7FFF) | 0x8000` narrowed to a
 * halfword, which is what the `and`/`orr` against the pooled 0x7FFF followed
 * by the `lsl #16`/`lsr #16` pair spells: 0x7FFF is not an ARM rotated
 * immediate and costs a pool word, 0x8000 is one.
 *
 * The zero in r4 is the allocator's alignment argument and the NULL return
 * in one register; it is materialised once, before the call, and survives to
 * the failure epilogue
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md).
 *
 * The failure arm falls through the `bne`, so the source tests `== 0` and
 * not the success condition
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * The call to the constructor at 0x02043900 resolves on the `matched` class
 * through src/matched/unit_02043900.c, which lives in this same shard, so
 * `manifest --verify --shard pkt_0204384C` has to run twice from a cold
 * shard: the first pass records 0x02043900 and the second one sees it.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204384C.c \
 *       --addr 0x0204384C --cc 1.1p1 --arm
 */
struct Bmp *func_0204384C(u32 arc, u32 member, u32 heap2, u32 heap)
{
    struct Bmp *b;
    void       *handle;
    void       *info;

    b = (struct Bmp *)func_02030734(heap, 0xC, 0, func_0204384C_File, 266);
    handle = (void *)func_0204A1BC((u32)arc, (u32)member, (u32)heap2, (u16)((heap & 0x7FFF) | 0x8000));
    if (func_02062A4C(handle, &info) == 0) {
        OS_Terminate();
        return 0;
    }
    func_02043900(b, info, heap);
    func_020307B0(handle);
    return b;
}



/*
 * bmp.c's bitmap constructor, 0x02043900-0x02043994 including its two pool
 * words.  The file-name pool word is 0x020A7E68, which spells "bmp.c", and
 * the line number is 321.  The accessor that follows at 0x02043994 is kept
 * in its own file so its manifest entry survives
 * (docs/idioms/a-unit-attests-only-its-own-start-address.md).
 *
 * The header the constructor reads is a resource record: two halfword cell
 * counts at +0 and +2 (stored back multiplied by eight, so the bitmap's +4
 * and +6 are pixel extents and the record's are tiles), a format word at +4,
 * a byte size at +0x10 and the source pointer at +0x14.  Format 3 means a
 * +8 of 0x20 and format 4 means 0x40; anything else leaves +8 untouched.
 *
 * The literal zero is written once into r6 and spends its life as three
 * different things: the allocator's alignment argument, the halfword stored
 * at +0xA, and nothing else
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md).
 *
 * The format test is a two-case `switch`, not an `if`/`else if` chain, and
 * the difference is four bytes and the whole tail's schedule: the chain
 * predicates the first arm in place (`moveq`/`strheq` then `beq` over the
 * rest) and needs no joining `b`, while the switch puts the first case out
 * of line at 0x0204396C and reaches the join with the `b` at 0x02043968.
 * With the chain the two stores after the allocation also come out in the
 * other order.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02043900.c \
 *       --addr 0x02043900 --cc 1.1p1 --arm
 */
void func_02043900(struct Bmp *b, struct BmpInfo *info, u32 heap)
{
    b->width = info->cellsY * 8;
    b->height = info->cellsX * 8;
    b->pixels = func_02030734(heap, info->size, 0, func_02043900_File, 321);
    b->kind = 0;
    switch (info->format) {
    case 3:
        b->depth = 0x20;
        break;
    case 4:
        b->depth = 0x40;
        break;
    }
    MIi_CpuCopy32(info->src, b->pixels, info->size);
}




/*
 * bmp.c's accessor for the halfword at +8, the field the blit dispatcher at
 * 0x020439A0 compares between source and destination.  The `ldrh` followed
 * by `and r0, r0, #0xff` is the field's own width against the function's:
 * the field is a halfword and the return type is a byte, so the truncation
 * is at the return, not at the load.  No relocation.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02043994.c \
 *       --func func_02043994 --addr 0x02043994 --cc 1.1p1 --arm
 */
u8 func_02043994(struct Bmp *b)
{
    return b->depth;
}



/*
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 *
 * bmp.c's nine-argument blit dispatcher.  Source and destination must agree
 * on the halfword at +8; after that the halfword at +0xA of the source picks
 * one of two families and the +8 value picks between the 0x20 member of that
 * family and the general one.
 *
 * The two families have different prototypes, and that is what the shift
 * pairs in the second arm are: the 0x020445F4 family takes the two register
 * coordinates and the last two stack arguments as `u16` and the middle two
 * as `s16`, so every one of the six is re-extended at the call
 * (docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md
 * does not apply; these are equal-amount pairs, plain narrowing casts).  The
 * 0x02043B98 family takes all nine wide and needs none of it.  This
 * function's own parameters must therefore be the wide types: a `u16`
 * parameter would arrive already extended and the call would not re-extend
 * it.
 *
 * Both branch polarities are the source order
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md): the `!= 2` arm
 * falls through, and inside each arm the `== 0x20` arm falls through.  The
 * five outgoing stack stores are written out in both arms of the first
 * family and the compiler tail-merges them ahead of the `cmp`
 * (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md); in the
 * second family it keeps two copies instead, because the narrowing makes the
 * two blocks different lengths.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020439A0.c \
 *       --func func_020439A0 --addr 0x020439A0 --cc 1.1p1 --arm
 */
void func_020439A0(struct Bmp *dst, struct Bmp *src, u32 x, u32 y,
                   int sx, int sy, u32 w, u32 h, u16 key)
{
    if (dst->depth != src->depth) {
        return;
    }
    if (src->kind != 2) {
        if (dst->depth == 0x20) {
            func_02043B98(dst, src, x, y, sx, sy, w, h, key);
        } else {
            func_02043F4C(dst, src, x, y, sx, sy, w, h, key);
        }
    } else {
        if (dst->depth == 0x20) {
            func_020445F4(dst, src, x, y, sx, sy, w, h, key);
        } else {
            func_02044954(dst, src, x, y, sx, sy, w, h, key);
        }
    }
}



/*
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 *
 * bmp.c's ten-argument forwarder onto 0x0204427C.  The first four arguments
 * pass through in their registers; the six stacked ones are copied down to
 * the outgoing frame, and the last two are re-read narrow: the ninth with a
 * plain `ldrh` (the parameter and the callee's are both halfwords, so the
 * load is the declared width and nothing else is needed) and the tenth with
 * `ldrh` plus `and ip, ip, #0xff`, which is a halfword parameter narrowed to
 * the callee's byte one.  A word parameter narrowed to a byte would have
 * been a single `ldrb` off the home slot, so the `ldrh` is what names the
 * incoming width.
 *
 * Every one of the 72 concrete bytes is reproduced.  The single relocation
 * stays wildcarded: 0x0204427C is called from here and from nowhere else in
 * the image, so the `label` class has no witness outside the compared range,
 * it is not in the manifest, and a one-function range admits no cut.  It
 * closes when 0x0204427C is matched.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02043AAC.c \
 *       --func func_02043AAC --addr 0x02043AAC --cc 1.1p1 --arm
 */
void func_02043AAC(struct Bmp *dst, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6,
                   u32 a7, u32 a8, u16 a9, u16 a10)
{
    func_0204427C((struct Bmp *)dst, (struct Bmp *)a2, a3, a4, a5, a6, a7, a8, a9, a10);
}



/*
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 *
 * bmp.c's six-argument fill dispatcher, the single-bitmap sibling of the
 * blit dispatcher at 0x020439A0: the same two-level switch on the source
 * bitmap's +0xA and +8 halfwords, over four workers, but with nothing to
 * narrow, so the two outgoing stack words are one `stm sp, {r4, lr}` written
 * out in each arm rather than a tail-merged run of `str`s.
 *
 * Both `ldrh`s are hoisted ahead of their `cmp`s and the +8 load is issued
 * even on the path that will not use it; that is scheduling, not a third
 * read of the struct.
 *
 * The fall-through arm is the source order in both tests
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md): `!= 2` first,
 * then `== 0x20`.
 *
 * Every one of the 104 concrete bytes is reproduced; all four relocations
 * stay wildcarded for the same reason as src/pending/sub_020439A0.c: each of
 * the four fill workers is called from this dispatcher and from nowhere else
 * in the image, so no site has a `label` witness outside the compared range,
 * none of the four is in the manifest, and the range is one function so
 * there is no cut.  0x02044CE0 already has a near-miss note,
 * docs/notes/sub_02044CE0.c.txt.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02043AF4.c \
 *       --func func_02043AF4 --addr 0x02043AF4 --cc 1.1p1 --arm
 */
void func_02043AF4(struct Bmp *b, u32 a2, u32 a3, u32 a4, u16 a5, u8 a6)
{
    if (b->kind != 2) {
        if (b->depth == 0x20) {
            func_02044BF0(b, a2, a3, a4, a5, a6);
        } else {
            func_02044CE0(b, a2, a3, a4, a5, a6);
        }
    } else {
        if (b->depth == 0x20) {
            func_02044D88(b, a2, a3, a4, a5, a6);
        } else {
            func_02044EBC(b, a2, a3, a4, a5, a6);
        }
    }
}


/*
 * Clears a tiled character buffer to a constant pixel value.  The tile
 * count is (width/8) * (height/8) and the byte count is that times the
 * per-tile size at +8, 0x20 for 4bpp and 0x40 for 8bpp.  In the 4bpp case
 * the fill value is a nibble, so it is replicated into both halves of the
 * byte before the fill.
 */
void sub_02043B5C(struct CharBuf *buf, u8 value)
{
    u32 size = ((u32)buf->width >> 3) * ((u32)buf->height >> 3) * buf->tileSize;

    if (buf->tileSize == 0x20) {
        value = (value & 0xf) | ((value & 0xf) << 4);
    }

    MI_CpuFill8(buf->pixels, value, size);
}


static inline s32 ClipRect(struct Bmp *src, const struct Bmp *dst, s32 *x, s32 *y,
                           s32 *dx, s32 *dy, u32 *w, u32 *h)
{
    u32 ch = *h;
    u32 cw = *w;
    if (cw > src->width)
        cw = src->width;
    if (*dx >= dst->width || *dx <= -(s32)cw)
        return 0;
    if (ch > src->height)
        ch = src->height;
    if (*dy >= dst->height || *dy <= -(s32)ch)
        return 0;
    if (*dx < 0) {
        cw += *dx;
        *x -= *dx;
        *dx = 0;
    } else if (*dx + cw > dst->width) {
        cw -= *dx + cw - dst->width;
    }
    if (*dy < 0) {
        ch += *dy;
        *y -= *dy;
        *dy = 0;
    } else if (*dy + ch > dst->height) {
        ch -= *dy + ch - dst->height;
    }
    *w = cw;
    *h = ch;
    return 1;
}


/*
 * bmp.c blit worker, 4bpp tiled source onto a 4bpp tiled destination,
 * byte read-modify-write of one nibble, optional colour key (0xFFFF =
 * none).  The 4bpp sibling of func_02043F4C (same dispatcher arm, same
 * inlined clip helper, same parameter types) and the byte-store sibling
 * of func_020445F4.
 *
 * Levers on top of func_02043F4C's, each measured:
 *   - the store is written `(v << sh) | (*p & (0xf0 >> sh))`: the other
 *     operand order lets the compiler hoist the *p load above the source
 *     read, which costs a spill slot (984 bytes against 948);
 *   - both loops read the source through a pointer q computed BEFORE the
 *     destination pointer, with the source tile-row local assigned first:
 *     the preheader then computes the source row and product first, as the
 *     image does (100 out otherwise).
 */
void func_02043B98(struct Bmp *src, struct Bmp *dst, s32 x, s32 y, s32 dx, s32 dy,
                   u32 w, u32 h, u16 key)
{
    s32 srow, drow;
    u32 i, j;
    s32 dxx, xx;
    s32 sTileY, dTileY, kTileY, lTileY;
    u32 v, sh;
    u8 *p;
    u8 *q;

    if (!ClipRect(src, dst, &x, &y, &dx, &dy, &w, &h))
        return;
    srow = (src->width + (src->width & 7)) >> 3;
    drow = (dst->width + (dst->width & 7)) >> 3;
    if (key == 0xffff) {
        for (i = 0; i < h; i++, y++, dy++)
            for (j = 0, dxx = dx, xx = x; j < w; j++, dxx++, xx++) {
                sTileY = (y * 4) & 0x3fe0;
                q = (u8 *)((u32)src->pixels + ((xx >> 1) & 3) + ((xx * 4) & 0x3fe0)
                           + sTileY * srow + ((y * 4) & 0x1c));
                dTileY = (dy * 4) & 0x3fe0;
                p = (u8 *)((u32)dst->pixels + ((dxx >> 1) & 3) + ((dxx * 4) & 0x3fe0)
                           + dTileY * drow);
                p += (dy * 4) & 0x1c;
                sh = (u32)(dxx << 31) >> 29;
                v = (*q >> ((u32)(xx << 31) >> 29)) & 0xf;
                *p = (v << sh) | (*p & (0xf0 >> sh));
            }
    } else {
        for (i = 0; i < h; i++, y++, dy++)
            for (j = 0, dxx = dx, xx = x; j < w; j++, xx++, dxx++) {
                kTileY = (y * 4) & 0x3fe0;
                q = (u8 *)((u32)src->pixels + ((xx >> 1) & 3) + ((xx * 4) & 0x3fe0)
                           + kTileY * srow + ((y * 4) & 0x1c));
                lTileY = (dy * 4) & 0x3fe0;
                p = (u8 *)((u32)dst->pixels + ((dxx >> 1) & 3) + ((dxx * 4) & 0x3fe0)
                           + lTileY * drow);
                p += (dy * 4) & 0x1c;
                v = (*q >> ((u32)(xx << 31) >> 29)) & 0xf;
                if (v != key) {
                    sh = (u32)(dxx << 31) >> 29;
                    *p = (v << sh) | (*p & (0xf0 >> sh));
                }
            }
    }
}


/*
 * bmp.c blit worker, 8bpp tiled source onto an 8bpp tiled destination,
 * byte stores, optional colour key (0xFFFF = none).  Reached from the blit
 * dispatcher func_020439A0's first arm (kind != 2), which passes all nine
 * arguments wide; the key is ldrh'd off the stack here, so it is u16 on
 * this side.
 *
 * The prologue is an inlined clip helper returning a flag (the image's
 * mov r4,#0 / mov r4,#1 / cmp r4,#0).  Width and height are clamped to the
 * source, the destination origin is rejected when fully outside, and a
 * negative origin is folded into the width/height and the source origin.
 * All the comparisons against the clipped extents are unsigned
 * (movhi/subhi) and those against the destination origin signed (bge/bgt),
 * which is what fixes the u32 extents and the s32 origins.
 *
 * Levers, each measured (compiled bytes out):
 *   - dst is `const struct Surf *` in the helper: that is what makes the
 *     compiler re-read dst->width after the clip (812 bytes without);
 *   - the helper reads *h BEFORE *w into its locals (88 out; 701 the
 *     other way);
 *   - the keyed loop reads the source through a pointer q and tests *q
 *     (14 out; a u8 temporary gives 65 and a different schedule);
 *   - the inner loop headers: dxx before xx in the initialisers, and the
 *     keyed loop steps xx before dxx (a three-register rotation, 12 -> 4
 *     -> 0);
 *   - the address arithmetic is the family's single integer sum over
 *     (u32)pixels (func_02044CE0) with one tile-row local per address.
 */
void func_02043F4C(struct Bmp *src, struct Bmp *dst, s32 x, s32 y, s32 dx, s32 dy,
                   u32 w, u32 h, u16 key)
{
    s32 srow, drow;
    u32 i, j;
    s32 dxx, xx;
    s32 sTileY, dTileY, kTileY, lTileY;
    u8 c;
    u8 *p;
    u8 *q;

    if (!ClipRect(src, dst, &x, &y, &dx, &dy, &w, &h))
        return;
    srow = (src->width + (src->width & 7)) >> 3;
    drow = (dst->width + (dst->width & 7)) >> 3;
    if (key == 0xffff) {
        for (i = 0; i < h; i++, y++, dy++)
            for (j = 0, dxx = dx, xx = x; j < w; j++, dxx++, xx++) {
                sTileY = (y * 8) & 0x7fc0;
                c = *(u8 *)((u32)src->pixels + (xx & 7) + ((xx * 8) & 0x7fc0)
                            + sTileY * srow + ((y * 8) & 0x38));
                dTileY = (dy * 8) & 0x7fc0;
                *(u8 *)((u32)dst->pixels + (dxx & 7) + ((dxx * 8) & 0x7fc0)
                        + dTileY * drow + ((dy * 8) & 0x38)) = c;
            }
    } else {
        for (i = 0; i < h; i++, y++, dy++)
            for (j = 0, dxx = dx, xx = x; j < w; j++, xx++, dxx++) {
                kTileY = (y * 8) & 0x7fc0;
                q = (u8 *)((u32)src->pixels + (xx & 7) + ((xx * 8) & 0x7fc0)
                           + kTileY * srow + ((y * 8) & 0x38));
                lTileY = (dy * 8) & 0x7fc0;
                p = (u8 *)((u32)dst->pixels + (dxx & 7) + ((dxx * 8) & 0x7fc0)
                           + lTileY * drow);
                p += (dy * 8) & 0x38;
                if (*q != key)
                    *p = *q;
            }
    }
}



/*
 * bmp.c blit worker, 4bpp tiled source expanded onto an 8bpp tiled
 * destination with a palette offset: every source nibble is widened to a
 * byte and `pal` is added to it unless it is zero.  With key == 0xFFFF every
 * pixel is stored (a zero nibble stays zero); otherwise zero nibbles are
 * skipped.  Reached only through the forwarder func_02043AAC, whose narrowing
 * loads fix the u16 key and u8 pal.  Same inlined clip helper and parameter
 * types as func_02043B98 / func_02043F4C; source-side masks are the 4bpp ones
 * (0x3fe0 / 0x1c), destination-side the 8bpp ones (0x7fc0 / 0x38).
 *
 * Three levers in the keyed loop, each measured against
 * docs/notes/pkt_02043B98.c.txt's 276-byte best:
 *   - the source pointer is computed BEFORE the destination pointer (as in
 *     func_02043B98) and the keyed store is `v += pal; *p = v;` inside the
 *     braces: 888 bytes, 114 out (q-then-p with `*p = v + pal` is 880);
 *   - `xx * 4` bound to a named temporary (`xx4`) in the keyed loop:
 *     4 out (tools/permuter.py anneal, then ablated to this one lever);
 *   - the keyed source pointer is plain pointer arithmetic on src->pixels,
 *     not the `(u32)` sum: that fixes the last `add`/`ldrb` operand order.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204427C.c \
 *       --func func_0204427C --addr 0x0204427C --cc 1.1p1 --arm
 */
void func_0204427C(struct Bmp *src, struct Bmp *dst, s32 x, s32 y, s32 dx, s32 dy,
                   u32 w, u32 h, u16 key, u8 pal)
{
    s32 srow, drow;
    u32 i, j;
    s32 dxx, xx;
    s32 sTileY, dTileY, kTileY, lTileY;
    u32 v;
    u8 *p;
    u8 *q;
    s32 xx4;

    if (!ClipRect(src, dst, &x, &y, &dx, &dy, &w, &h))
        return;
    srow = (src->width + (src->width & 7)) >> 3;
    drow = (dst->width + (dst->width & 7)) >> 3;
    if (key == 0xffff) {
        for (i = 0; i < h; i++, y++, dy++)
            for (j = 0, dxx = dx, xx = x; j < w; j++, dxx++, xx++) {
                sTileY = (y * 4) & 0x3fe0;
                q = (u8 *)((u32)src->pixels + ((xx >> 1) & 3) + ((xx * 4) & 0x3fe0)
                           + sTileY * srow + ((y * 4) & 0x1c));
                dTileY = (dy * 8) & 0x7fc0;
                p = (u8 *)((u32)dst->pixels + (dxx & 7) + ((dxx * 8) & 0x7fc0)
                           + dTileY * drow);
                p += (dy * 8) & 0x38;
                v = (*q >> ((u32)(xx << 31) >> 29)) & 0xf;
                if (v != 0)
                    v += pal;
                *p = v;
            }
    } else {
        for (i = 0; i < h; i++, y++, dy++)
            for (j = 0, dxx = dx, xx = x; j < w; j++, xx++, dxx++) {
                kTileY = (y * 4) & 0x3fe0;
                lTileY = (dy * 8) & 0x7fc0;
                xx4 = xx * 4;
                q = src->pixels + ((xx >> 1) & 3) + (xx4 & 0x3fe0) + kTileY * srow
                    + ((y * 4) & 0x1c);
                p = (u8 *)((u32)dst->pixels + (dxx & 7) + ((dxx * 8) & 0x7fc0)
                           + lTileY * drow);
                p += (dy * 8) & 0x38;
                v = (*q >> ((u32)(xx << 31) >> 29)) & 0xf;
                if (v != 0) {
                    v += pal;
                    *p = v;
                }
            }
    }
}



/*
 * bmp.c blit worker, 4bpp tiled source onto a 4bpp tiled destination that
 * is written a HALFWORD at a time (func_02044D88's read-modify-write
 * store), with an optional colour key (0xFFFF = none).  Reached from the
 * blit dispatcher func_020439A0's kind == 2 arm, whose shift pairs give
 * the narrow parameter types (x, y, w, h u16; dx, dy s16); the key is
 * loaded with ldrh here, so it is u16 on this side.  The plain and keyed
 * loops are written out in full, each with its OWN pair of tile-row
 * locals (sharing one pair across both loops costs ~150 bytes of
 * allocation).
 *
 * The clip against the destination goes through a fresh temporary t.
 * Reusing xend/yend for the difference makes the compiler emit the
 * conditional add with the reused variable as the first operand
 * (add fp, r5, r2) where the image has add fp, r2, r5; that was the
 * last 4 bytes.
 */
void func_020445F4(struct Bmp *src, struct Bmp *dst, u16 x, u16 y, s16_p07 dx, s16_p07 dy, u16 w, u16 h, u16 key)
{
    s32 xend, yend, srow, drow;
    s32 i, j, di, dj;
    s32 sTileY, dTileY, kTileY, lTileY;
    u32 s, d;
    s32 odd;
    u32 c;
    u16 hi, lo;
    s32 t, u;
    u32 v, sh;
    t = dst->width - dx;
    if (t < w)
        xend = x + t;
    else
        xend = w + x;
    t = dst->height - dy;
    if (t < h)
        yend = y + t;
    else
        yend = h + y;
    srow = (src->width + (src->width & 7)) >> 3;
    drow = (dst->width + (dst->width & 7)) >> 3;
    if (key == 0xffff) {
        for (i = y, di = dy; i < yend; i++, di++)
            for (j = x, dj = dx; j < xend; j++, dj++)
                if (dj >= 0 && di >= 0) {
                    sTileY = (i * 4) & 0x3fe0;
                    s = (u32)src->pixels + ((j >> 1) & 3) + ((j * 4) & 0x3fe0) + sTileY * srow;
                    s += (i * 4) & 0x1c;
                    dTileY = (di * 4) & 0x3fe0;
                    d = (u32)dst->pixels + ((dj >> 1) & 3) + ((dj * 4) & 0x3fe0) + dTileY * drow;
                    d += (di * 4) & 0x1c;
                    if (d & 1) {
                        d -= 1;
                        odd = 1;
                    } else
                        odd = 0;
                    c = ((struct Obj04758 *)d)->f0;
                    hi = c >> 8;
                    lo = c & 0xff;
                    v = (((struct Obj11411 *)s)->f0 >> ((u32)(j << 31) >> 29)) & 0xf;
                    sh = (u32)(dj << 31) >> 29;
                    if (odd == 0)
                        ((struct Obj04758 *)d)->f0 = (((0xf0 >> sh) & lo) | (v << sh)) | (hi << 8);
                    else
                        ((struct Obj04758 *)d)->f0 = (((hi & (0xf0 >> sh)) | (v << sh)) << 8) | lo;
                }
    } else {
        for (i = y, di = dy; i < yend; i++, di++)
            for (j = x, dj = dx; j < xend; j++, dj++)
                if (dj >= 0 && di >= 0) {
                    kTileY = (i * 4) & 0x3fe0;
                    s = (u32)src->pixels + ((j >> 1) & 3) + ((j * 4) & 0x3fe0) + kTileY * srow;
                    s += (i * 4) & 0x1c;
                    lTileY = (di * 4) & 0x3fe0;
                    d = (u32)dst->pixels + ((dj >> 1) & 3) + ((dj * 4) & 0x3fe0) + lTileY * drow;
                    d += (di * 4) & 0x1c;
                    if (d & 1) {
                        d -= 1;
                        odd = 1;
                    } else
                        odd = 0;
                    c = ((struct Obj04758 *)d)->f0;
                    hi = c >> 8;
                    lo = c & 0xff;
                    v = (((struct Obj11411 *)s)->f0 >> ((u32)(j << 31) >> 29)) & 0xf;
                    if (v != key) {
                        sh = (u32)(dj << 31) >> 29;
                        if (odd == 0)
                            ((struct Obj04758 *)d)->f0 = (((0xf0 >> sh) & lo) | (v << sh)) | (hi << 8);
                        else
                            ((struct Obj04758 *)d)->f0 = (((hi & (0xf0 >> sh)) | (v << sh)) << 8) | lo;
                    }
                }
    }
}



/*
 * bmp.c blit worker, 8bpp tiled source onto an 8bpp tiled destination
 * written a HALFWORD at a time: when the destination byte is odd the
 * store covers it and the byte before, both taken from the source pair
 * ending at the source pixel; otherwise the source pair starting at it.
 * Optional colour key (0xFFFF = none), compared against the source byte.
 * Reached from func_020439A0's kind == 2 arm (x, y, w, h u16; dx, dy s16;
 * the key is ldrh'd, so u16 here).
 *
 * The same four levers as func_020445F4, all measured:
 *   - the address is one integer sum over (u32)pixels with the in-tile
 *     row added afterwards;
 *   - each of the four tile-row masks has its own function-scope local
 *     (shared locals: 149 out; none: 31);
 *   - in the odd arm d is decremented BEFORE the two loads, which keeps
 *     the shared first load in each arm (326 out otherwise);
 *   - the clip goes through a fresh temporary t with u16 x/y; reusing
 *     xend/yend flips the operands of the conditional add (4 out), and
 *     a fresh t with s32 x/y reshuffles the allocation (167 out).
 */
void func_02044954(struct Bmp *src, struct Bmp *dst, u16 x, u16 y, s16_p07 dx, s16_p07 dy, u16 w, u16 h, u16 key)
{
    s32 xend, yend, srow, drow;
    s32 i, j, di, dj;
    s32 sTileY, dTileY, kTileY, lTileY;
    u32 s, d;
    u16 c;
    s32 t;
    t = dst->width - dx;
    if (t < w)
        xend = x + t;
    else
        xend = w + x;
    t = dst->height - dy;
    if (t < h)
        yend = y + t;
    else
        yend = h + y;
    srow = (src->width + (src->width & 7)) >> 3;
    drow = (dst->width + (dst->width & 7)) >> 3;
    if (key == 0xffff) {
        for (i = y, di = dy; i < yend; i++, di++)
            for (j = x, dj = dx; j < xend; j++, dj++)
                if (dj >= 0 && di >= 0) {
                    sTileY = (i * 8) & 0x7fc0;
                    s = (u32)src->pixels + (j & 7) + ((j * 8) & 0x7fc0) + sTileY * srow;
                    s += (i * 8) & 0x38;
                    dTileY = (di * 8) & 0x7fc0;
                    d = (u32)dst->pixels + (dj & 7) + ((dj * 8) & 0x7fc0) + dTileY * drow;
                    d += (di * 8) & 0x38;
                    if (d & 1) {
                        d -= 1;
                        c = (((u8 *)s)[0] << 8) | ((u8 *)s)[-1];
                    } else {
                        c = ((u8 *)s)[0] | (((u8 *)s)[1] << 8);
                    }
                    ((struct Obj11412 *)d)->f0 = c;
                }
    } else {
        for (i = y, di = dy; i < yend; i++, di++)
            for (j = x, dj = dx; j < xend; j++, dj++)
                if (dj >= 0 && di >= 0) {
                    kTileY = (i * 8) & 0x7fc0;
                    s = (u32)src->pixels + (j & 7) + ((j * 8) & 0x7fc0) + kTileY * srow;
                    s += (i * 8) & 0x38;
                    lTileY = (di * 8) & 0x7fc0;
                    d = (u32)dst->pixels + (dj & 7) + ((dj * 8) & 0x7fc0) + lTileY * drow;
                    d += (di * 8) & 0x38;
                    if (d & 1) {
                        d -= 1;
                        c = (((u8 *)s)[0] << 8) | ((u8 *)s)[-1];
                    } else {
                        c = ((u8 *)s)[0] | (((u8 *)s)[1] << 8);
                    }
                    if (((struct Obj03010 *)s)->f0 != key)
                        ((struct Obj11412 *)d)->f0 = c;
                }
    }
}



/*
 * bmp.c fill worker, 4bpp tiled (two pixels per byte), reached from the
 * fill dispatcher func_02043AF4.  Clips right/bottom before the loops and
 * left/top per pixel (signed cmp/cmpge/blt triple), then merges the
 * nibble: odd x takes the high nibble, even x the low one.
 *
 * THE LEVERS (2026-09-22, wave 10), each measured:
 *   - the address is one integer sum over (u32)s->pixels, with only the
 *     tile-row mask lifted into a function-scope local (same lever as
 *     func_02044CE0);
 *   - the in-tile row is added to the POINTER afterwards (`p += ...`),
 *     which is what makes the load/store `[p, row]` rather than
 *     `[row, p]` (6 out when it is a fifth term of the sum);
 *   - `hi = value << 4` is assigned INSIDE the guarded body.  LICM then
 *     hoists the shift out of both loops but the `(u8)` narrowing only
 *     one level, so the raw shift is live across the outer loop and is
 *     spilled together with tilesWide: that one extra value is the whole
 *     `sub sp, sp, #8` frame the earlier passes could not reach (208
 *     bytes with hi computed once before the loops);
 *   - the even arm's `(u8)(*p & 0xf0)` is the unfolded `and #0xff`.
 */
void func_02044BF0(struct Bmp *s, s32 x, s32 y, s32 w, u16 h, u32 value)
{
    s32 i;
    s32 j;
    s32 right = x + w;
    s32 bottom = y + h;
    s32 tilesWide;
    s32 tileY;
    u8 *p;
    u32 hi;

    if (right > s->width)
        right = s->width;
    if (bottom > s->height)
        bottom = s->height;
    tilesWide = (s->width + (s->width & 7)) >> 3;

    for (i = y; i < bottom; i++)
        for (j = x; j < right; j++)
            if (j >= 0 && i >= 0) {
                hi = value << 4;
                tileY = (i * 4) & 0x3fe0;
                p = (u8 *)((u32)s->pixels + ((j >> 1) & 3) + ((j * 4) & 0x3fe0)
                           + tileY * tilesWide);
                p += (i * 4) & 0x1c;
                if (j & 1)
                    *p = (*p & 0x0f) | (u8)hi;
                else
                    *p = (u8)(*p & 0xf0) | value;
            }
}



/*
 * bmp.c fill worker (8bpp tiled, one byte per pixel), reached from the
 * fill dispatcher func_02043AF4.  Clips right/bottom against the
 * descriptor before the loops and left/top per pixel (the signed
 * cmp/cmpge/blt triple), then stores the fill byte at the 8x8-tiled
 * address.  0x02044CE0 and 0x02044EBC are byte-identical twins.
 *
 * THE LEVER (2026-09-22, wave 10): the address is ONE integer expression
 * over the pixel pointer cast to u32, evaluated inside the guarded body,
 * with only the tile-row mask lifted into a function-scope local.  The
 * compiler hoists that local and the product out of the inner loop into
 * the preheader AFTER the entry test (the image's placement) but does not
 * fold the tile row and the in-tile row into one mla, which it does for
 * every pointer-arithmetic or subscript spelling.  Pointer arithmetic
 * (u8 *) with the same terms stays at 17 out; the per-row locals of the
 * older best source at 81.
 */
void func_02044CE0(struct Bmp *s, s32 x, s32 y, s32 w, u16 h, u8 value)
{
    s32 i;
    s32 j;
    s32 right = x + w;
    s32 bottom = y + h;
    s32 tilesWide;
    s32 tileY;

    if (right > s->width)
        right = s->width;
    if (bottom > s->height)
        bottom = s->height;
    tilesWide = (s->width + (s->width & 7)) >> 3;

    for (i = y; i < bottom; i++)
        for (j = x; j < right; j++)
            if (j >= 0 && i >= 0) {
                tileY = (i * 8) & 0x7fc0;
                *(u8 *)((u32)s->pixels + (j & 7) + ((j * 8) & 0x7fc0)
                        + tileY * tilesWide + ((i * 8) & 0x38)) = value;
            }
}



/*
 * bmp.c fill worker, 4bpp tiled plotted through a HALFWORD read-modify-
 * write (the pixel's byte is halfword-aligned downward, merged, and the
 * pair stored back with strh).  Reached from func_02043AF4.
 *
 * Levers (2026-09-22, wave 10), each measured:
 *   - the address is the family's single integer sum over (u32)s->pixels
 *     with the tile-row mask in a function-scope local and the in-tile row
 *     added afterwards (func_02044BF0);
 *   - hi/lo are u16 locals of a u32 halfword read: `hi = c >> 8` becomes
 *     the image's lsl #8 / lsr #16, and `lo = c & 0xff` its and / lsl #16
 *     with the lsr #16 folded into every use;
 *   - odd is set inside the `if (a & 1)`, which lets tst/subne and the
 *     movne/moveq pair share one flag setting;
 *   - the even arm is written first (`odd == 0`), the fall-through order;
 *   - right is computed and clamped BEFORE bottom is computed: bottom lives
 *     in its spill slot from its first store, and initialising both up
 *     front adds a reload (312 bytes).
 */
void func_02044D88(struct Bmp *s, s32 x, s32 y, s32 w, u16 h, u8 value)
{
    s32 i;
    s32 j;
    s32 right;
    s32 bottom;
    s32 tilesWide;
    s32 tileY;
    u32 a;
    s32 odd;
    u32 c;
    u16 hi, lo;
    u32 sh;

    right = x + w;
    if (right > s->width)
        right = s->width;
    bottom = y + h;
    if (bottom > s->height)
        bottom = s->height;
    tilesWide = (s->width + (s->width & 7)) >> 3;

    for (i = y; i < bottom; i++)
        for (j = x; j < right; j++)
            if (j >= 0 && i >= 0) {
                tileY = (i * 4) & 0x3fe0;
                a = (u32)s->pixels + ((j >> 1) & 3) + ((j * 4) & 0x3fe0)
                    + tileY * tilesWide;
                a += (i * 4) & 0x1c;
                if (a & 1) {
                    a -= 1;
                    odd = 1;
                } else
                    odd = 0;
                c = ((struct Obj08850 *)a)->f0;
                hi = c >> 8;
                lo = c & 0xff;
                sh = (u32)(j << 31) >> 29;
                if (odd == 0)
                    ((struct Obj08850 *)a)->f0 = (((0xf0 >> sh) & lo) | (value << sh)) | (hi << 8);
                else
                    ((struct Obj08850 *)a)->f0 = (((hi & (0xf0 >> sh)) | (value << sh)) << 8) | lo;
            }
}



void func_02044EBC(struct Bmp *s, s32 x, s32 y, s32 w, u16 h, u8 value)
{
    s32 i;
    s32 j;
    s32 right = x + w;
    s32 bottom = y + h;
    s32 tilesWide;
    s32 tileY;

    if (right > s->width)
        right = s->width;
    if (bottom > s->height)
        bottom = s->height;
    tilesWide = (s->width + (s->width & 7)) >> 3;

    for (i = y; i < bottom; i++)
        for (j = x; j < right; j++)
            if (j >= 0 && i >= 0) {
                tileY = (i * 8) & 0x7fc0;
                *(u8 *)((u32)s->pixels + (j & 7) + ((j * 8) & 0x7fc0)
                        + tileY * tilesWide + ((i * 8) & 0x38)) = value;
            }
}



/*
 * bmp.c de-tile entry point: builds a new descriptor of the same extent
 * and depth, copies the 8x8-tiled pixels of src into it in linear order,
 * and either returns it or (keep == 0) copies it back over src, frees it
 * and returns NULL.
 *
 * WHAT CLOSED IT (wave 12, 2026-09-23), after three passes stuck at 6
 * bytes on the f04/f06 load-register pair: the four extents are u16
 * LOCALS, `w = width / 8` etc.  The `lsl #13 / lsr #16` pair the older
 * sources spelled as `(u32)(f * 8192) >> 16` is simply the u16 truncation
 * of an unsigned divide by 8.  With all four u16 the residue drops to 13,
 * and assigning them in the order h, w, dep, d (height before width) is
 * what gives the image's colouring; declaration order is inert.
 */
struct Bmp *func_02044F64(struct Bmp *src, u32 keep, u16 heap)
{
    struct Bmp *dst;
    s32 i, n;
    u16 w;
    u16 h;
    u16 d;
    u16 dep;

    h = src->height / 8;
    w = src->width / 8;
    dep = src->depth;
    d = dep / 8;
    dst = func_02043678(w, h, dep, heap);
    n = w * h * dep;
    for (i = 0; i < n; i++) {
        s32 q, r, x, y;
        q = i / (w * d);
        r = i % (w * d);
        y = r % d;
        x = r / d;
        dst->pixels[i] = src->pixels[(q % 8) * d + y + (q / 8 * w + x) * dep];
    }
    if (keep == 0) {
        func_02043814(dst, src);
        func_020437AC((struct Obj020437AC *)dst);
        dst = 0;
    }
    return dst;
}



/*
 * The one-time init of the BG subsystem's heap record.  Four bytes are
 * allocated on the heap the caller names, the pointer is published in the
 * global at 0x02146A50, and the heap id itself is written back into the
 * first halfword of the block.  Every later allocation in this family reads
 * that halfword back out (see src/matched/sub_02045374.c, which spells it
 * (*g_02146A50 & 0x7fff) | 0x8000), so the block is the subsystem's record
 * of which heap it owns.
 *
 * The allocator's fourth and fifth arguments are the same debug site string
 * and tag pair used everywhere else in this file; here the tag is 0x4f.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02045088.c \
 *       --func sub_02045088 --addr 0x02045088 --cc 1.1p1 --arm
 */
void sub_02045088(u16 heapId)
{
    u16 *p = func_02030734(heapId, 4, 0, str_020A7E70, 0x4f);

    g_02146A50 = p;
    *p = heapId;
}



/*
 * The teardown that pairs with sub_02045088: free the four-byte heap record
 * published at 0x02146A50 and clear the pointer, doing nothing if it was
 * never allocated.  The idempotent shape (test, free, null out) is why the
 * global is read once into a callee-saved register and stored back through
 * the same register rather than re-loaded from the pool.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020450C8.c \
 *       --func sub_020450C8 --addr 0x020450C8 --cc 1.1p1 --arm
 */
void sub_020450C8(void)
{
    if (g_02146A50 == 0)
        return;

    func_020307B0(g_02146A50);
    g_02146A50 = 0;
}



/*
 * Set up a BG layer whose character data is placed at a VRAM offset chosen
 * by the allocator.  func_0204169C says whether the layer is 8bpp; that
 * decides both the flag handed to sub_02045210 and whether a cell costs one
 * or two units, and the unit count is scaled by 32 to bytes before
 * func_0203FA08 is asked for room.  A returned -1 (not 0) is the allocator's
 * failure answer, and the function reports failure as 0.
 *
 * sub_02045180, the next function, is the same routine for the case where
 * the caller already knows the offset: it calls func_0203FAF0 to reserve
 * that exact offset instead, passes a count rather than a byte size, and
 * forwards the caller's offset straight through as sub_02045210's seventh
 * argument.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020450F0.c \
 *       --func sub_020450F0 --addr 0x020450F0 --cc 1.1p1 --arm
 */
u32 sub_020450F0(u32 layer, u32 a, u32 b, u8 tiles, u8 c, u8 d, u8 slot)
{
    u8 is8bpp;
    u32 units;
    s32 offset;

    if (func_0204169C(layer) == 0) {
        is8bpp = 0;
        units = tiles * c;
    } else {
        is8bpp = 1;
        units = tiles * c * 2;
    }

    offset = func_0203FA08(layer, units * 32, slot);
    if (offset == -1)
        return 0;

    return (u32)sub_02045210(layer, a, b, tiles, c, d, offset, is8bpp);
}



/*
 * closed:   blocker func_0203FAF0 is now a manifest entry (matched class)
 *
 * Every concrete byte is right; the file is capped at MATCH by one
 * relocation site, the bl to func_0203FAF0 at +0x44.  Blocking evidence
 * class: none available.  0x0203FAF0 has exactly one witness image wide and
 * it is the call inside this very function (--suggest-split reports "the
 * whole range as one file is NOT viable", best partition 0 pieces), so no
 * cut of this range can attest it.  It unsticks the moment either
 * 0x0203FAF0 itself is taken EXACT (the `matched` class) or a second caller
 * of it turns up in another packet.
 *
 * The fixed-offset twin of sub_020450F0: the caller already knows where the
 * layer's character data goes, so func_0203FAF0 is asked to reserve that
 * offset (answering 0 on failure, not -1), the cell count is passed in units
 * rather than scaled to bytes, and the caller's own offset is what reaches
 * sub_02045210 as the seventh argument.
 *
 * The 8bpp test and the doubling of the unit count are identical to
 * sub_020450F0; only the missing `lsl #5` and the different failure
 * convention separate the two.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02045180.c \
 *       --func sub_02045180 --addr 0x02045180 --cc 1.1p1 --arm
 */
u32 sub_02045180(u32 layer, u32 a, u32 b, u8 tiles, u8 c, u8 d, u32 offset)
{
    u8 is8bpp;
    u32 units;

    if (func_0204169C(layer) == 0) {
        is8bpp = 0;
        units = tiles * c;
    } else {
        is8bpp = 1;
        units = tiles * c * 2;
    }

    if (func_0203FAF0(layer, offset, units) == 0)
        return 0;

    return (u32)sub_02045210(layer, a, b, tiles, c, d, offset, is8bpp);
}



/*
 * The constructor shared by sub_020450F0 and sub_02045180: build the
 * sixteen-byte descriptor for one BG layer on the subsystem heap recorded by
 * sub_02045088, fill in its geometry, and attach the tile buffer
 * func_02043678 hands back.
 *
 *   +0x00  u16  two bitfields: a 15-bit tag set to 0x7fb2, and the 8bpp
 *               flag in bit 15
 *   +0x02  u8   layer
 *   +0x03  u8   screen base
 *   +0x04  u8   character base
 *   +0x05  u8   width in tiles       (also at +0x07)
 *   +0x06  u8   height in tiles      (also at +0x08)
 *   +0x09  u8   palette
 *   +0x0a  u16  character offset in VRAM
 *   +0x0c  void *tile buffer
 *
 * The tag is one 15-bit field, not two adjacent fields of 8 and 7 bits:
 * splitting it produces two read-modify-writes (bic #0xff / orr #0xb2 then
 * bic #0x7f00 / orr #0x7f00) instead of the single masked write the original
 * has, where the constant 0x7fb2 needs two `orr`s only because it is not one
 * ARM immediate.  The 8bpp bit is a second read-modify-write because its
 * assignment is separated from the tag by the byte stores.
 *
 * The width parameter is u8, not u32: assigning a u32 to the two u8 width
 * fields makes the compiler materialise `(u8)width` once with `and #0xff`
 * and store that register twice, where the original stores the incoming
 * register directly.  Same for the width argument of func_02043678.
 *
 * The 0xffff8000 mask is materialised as `sub r0, fp, #0x8000` off the
 * register already holding the allocator's zero third argument, the
 * rematerialisation idiom in
 * docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02045210.c \
 *       --func sub_02045210 --addr 0x02045210 --cc 1.1p1 --arm
 */
struct BgLayer *sub_02045210(u32 layer, u32 screenBase, u32 charBase,
                             u8 width, u8 height, u8 palette, u32 charOffset,
                             u8 is8bpp)
{
    struct BgLayer *o;
    u32 tileSize = is8bpp == 0 ? 0x20 : 0x40;

    o = func_02030734(*g_02146A50, 0x10, 0, str_020A7E70, 0xd5);

    o->tag = 0x7fb2;
    o->layer = layer;
    o->screenBase = screenBase;
    o->charBase = charBase;
    o->width = width;
    o->height = height;
    o->width2 = width;
    o->height2 = height;
    o->palette = palette;
    o->charOffset = charOffset;
    o->is8bpp = is8bpp;

    o->tiles = func_02043678(width, height, tileSize, *g_02146A50);
    return o;
}



/*
 * The descriptor family's destructor: release the payload through
 * sub_0203FB44, release the heap handle through sub_020437AC, then free
 * the descriptor itself with the generic free at 0x020307B0 (the same
 * free sub_02045808 tail-calls).
 *
 * The payload size is (d->unk5 * d->unk6) * 32, doubled when the top bit
 * of the halfword at +0 is set. That bit is a 1-wide bitfield, not a
 * mask: `ldrh` followed by `lsl #16` / `lsrs #31` is the bitfield extract
 * shape (shift the field to the top, then all the way down by 32 minus
 * its width), and a plain `d->unk0 & 0x8000` test folds to a single
 * `tst`. Declaring the halfword as a 15-bit field plus a 1-bit field is
 * what reproduces it.
 *
 * Both arms of the doubling compute the u8 * u8 product themselves, which
 * is why `smulbb` appears twice under opposite predicates rather than
 * once before the test. Writing the shared multiply above the `if` and
 * only the doubling inside it produces one unconditional `smulbb` and a
 * different register assignment throughout; this is
 * docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md seen from
 * the entry side.
 *
 * The whole conditional is predicated, so there is no branch at all: the
 * `s` suffix on the `lsrs` is the test, and the three following
 * instructions carry `eq`/`ne`. Because there is no branch, the only
 * thing that fixes their order is source order: the `eq` arm is emitted
 * first, so the undoubled case has to be written as the `if` and the
 * doubled case as the `else`, even though `if (bit) double` reads more
 * naturally (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020452E8.c \
 *       --func sub_020452E8 --addr 0x020452E8 --cc 1.1p1 --arm
 */
u32 sub_020452E8(struct Descriptor *d)
{
    u32 size;

    if (d->unk0_15 == 0) {
        size = d->unk5 * d->unk6;
    } else {
        size = (d->unk5 * d->unk6) * 2;
    }
    sub_0203FB44(d->unk2, d->unkA, size * 32);
    sub_020437AC(d->heap);
    return sub_020307B0(d);
}



/*
 * One of the descriptor family's two teardown/commit paths (the other is
 * sub_020452E8 immediately before it). It sizes the descriptor's payload
 * as
 *
 *   sub_020416B8(d->unk2) * (d->unk5 * d->unk6)
 *
 * and passes that, the heap handle obtained from d->heap via
 * sub_020437D4, and d->unkA on to sub_02040B1C.
 *
 * The u8 * u8 product compiles to `smulbb`, not `mul`: the compiler knows
 * both operands came from `ldrb` and fit in sixteen bits, so it uses the
 * halfword multiply. The second multiply, against a call result of
 * unknown range, has to be a full `mul`.
 *
 * The product is computed before the sub_020437D4 call and so has to
 * survive it, which is what buys the callee-saved r4 and turns
 * push {r4, lr} into push {r3, r4, r5, lr}: r5 holds the descriptor
 * pointer across all three calls and r3 is the alignment filler.
 *
 * d->unk2 is loaded twice, once for each call that takes it, rather than
 * kept in a register: re-reading the field is cheaper than spending a
 * third callee-saved register on it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02045334.c \
 *       --func sub_02045334 --addr 0x02045334 --cc 1.1p1 --arm
 */
void sub_02045334(struct Descriptor_02045334 *d)
{
    u32 size;

    size = (d->unk5 * d->unk6) * sub_020416B8(d->unk2);
    sub_02040B1C(d->unk2, sub_020437D4(d->heap), size, d->unkA);
}



/*
 * Fill a rectangle of the screen described by the configuration block with
 * a run of consecutive tile numbers.  func_02041680 says whether the layer
 * is 8bpp (answer 1, one byte per cell) or 16bpp (two bytes per cell, each
 * carrying the palette number from +9 in its top nibble); either way a
 * scratch buffer of w*h cells is allocated from the heap named by the word
 * behind 0x02146A50, filled with an increasing counter seeded from +0xa,
 * handed to func_020410D0 and freed again.
 *
 * The palette nibble is hoisted as `lsl r4, r2, #0x1c` before the branch
 * and consumed as `orr r2, r5, r4, lsr #16` inside the loop: that is one
 * `(x & 0xf) << 12`, split so that only the cheap half stays in the loop,
 * not two separate shifts.
 *
 * The two allocation sites carry different line numbers, 0x133 and 0x13e,
 * and that is load-bearing: give both the same constant and the compiler
 * hoists the single pool load above the branch, which costs one
 * instruction, one pool word and shifts every later pc-relative offset.
 * Eleven source lines apart matches the two arms of one if/else.
 */
void sub_02045374(struct Cfg *cfg)
{
    u16 count = cfg->unk_05 * cfg->unk_06;
    u32 palette = (cfg->unk_09 & 0xf) << 12;
    u16 tile = cfg->unk_0a;
    void *cells;
    s32 i;

    if (func_02041680(cfg->unk_02) != 1) {
        u16 *p = func_02030734((u16)((*g_02146A50 & 0x7fff) | 0x8000),
                               count * 2, 0, str_020A7E70, 0x133);

        cells = p;
        for (i = 0; i < count; i++) {
            p[i] = tile | palette;
            tile = tile + 1;
        }
    } else {
        u8 *p = func_02030734((u16)((*g_02146A50 & 0x7fff) | 0x8000),
                              count, 0, str_020A7E70, 0x13e);

        cells = p;
        for (i = 0; i < count; i++) {
            p[i] = (u8)tile;
            tile = tile + 1;
        }
    }

    func_020410D0(cfg->unk_02, cfg->unk_03, cfg->unk_04, cfg->unk_07,
                  cfg->unk_08, (u32)cells, 0, 0, cfg->unk_05, cfg->unk_06);
    func_020307B0(cells);
}



/*
 * The eight-piece frame around a window: base tile + 0..7 drawn at the
 * corners and edges one cell outside the on-screen extent (+7/+8), with the
 * palette nibble in the top of each cell unless the layer is 8bpp
 * (func_02041680 answers 1).
 *
 * Closed in wave 15 from a 2-byte residue (`mov r6, r2` against `mov r4,
 * r2`, the image gives pal and the palette bits one register).  Two facts,
 * each flat alone: the palette bits are computed IN PLACE in the pal
 * parameter as two compound statements (`pal &= 0xf; pal <<= 12;`), which
 * is what coalesces pal with its shifted value; and base is a u16
 * parameter (tile number), which restores the image's scheduling of the
 * sixth and seventh calls that the in-place form otherwise disturbs.  A
 * single-expression `pal = (pal & 0xf) << 12` or a separate pn local keeps
 * the 2-byte tie.  Found by tools/permuter.py hill (type:p base u32->u16)
 * from the in-place source.
 */
void func_020454E0(struct Cfg *cfg, u16 base, u32 pal)
{
    if (func_02041680(cfg->unk_02) != 1) {
        pal &= 0xf;
        pal <<= 12;
    } else {
        pal = 0;
    }

    func_02041300(cfg->unk_02, (u16)(pal | base), (u8)(cfg->unk_03 - 1),
                  (u8)(cfg->unk_04 - 1), 1, 1, 0x11);
    func_02041300(cfg->unk_02, (u16)(pal | (base + 1)), cfg->unk_03,
                  (u8)(cfg->unk_04 - 1), cfg->unk_07, 1, 0x11);
    func_02041300(cfg->unk_02, (u16)(pal | (base + 2)),
                  (u8)(cfg->unk_03 + cfg->unk_07), (u8)(cfg->unk_04 - 1),
                  1, 1, 0x11);
    func_02041300(cfg->unk_02, (u16)(pal | (base + 3)),
                  (u8)(cfg->unk_03 - 1), cfg->unk_04, 1, cfg->unk_08, 0x11);
    func_02041300(cfg->unk_02, (u16)(pal | (base + 4)),
                  (u8)(cfg->unk_03 + cfg->unk_07), cfg->unk_04,
                  1, cfg->unk_08, 0x11);
    func_02041300(cfg->unk_02, (u16)(pal | (base + 5)),
                  (u8)(cfg->unk_03 - 1), (u8)(cfg->unk_04 + cfg->unk_08),
                  1, 1, 0x11);
    func_02041300(cfg->unk_02, (u16)(pal | (base + 6)), cfg->unk_03,
                  (u8)(cfg->unk_04 + cfg->unk_08), cfg->unk_07, 1, 0x11);
    func_02041300(cfg->unk_02, (u16)(pal | (base + 7)),
                  (u8)(cfg->unk_03 + cfg->unk_07),
                  (u8)(cfg->unk_04 + cfg->unk_08), 1, 1, 0x11);
}



/*
 * A seven-argument forwarder over the descriptor object whose leaf
 * accessor bank is src/matched/unit_02045730.c: it unpacks six u8 fields
 * and a constant zero out of the descriptor and hands them to
 * sub_02041300, which is where the actual work happens.
 *
 *   sub_02041300(d->unk2, 0, d->unk3, d->unk4, d->unk5, d->unk6, 0)
 *
 * Register arguments are r0..r3, and the remaining three ride the 12-byte
 * stack frame the prologue carves out with `sub sp, sp, #0xc`. The
 * compiler spots that the last two stack slots are adjacent and writes
 * d->unk5 (already in r0) and the zero (already in r1) with a single
 * `stmib sp, {r0, r1}` rather than two stores, which is what makes the
 * second and third stack argument order legible: had the zero been
 * anywhere but last, the store pair would not have fused.
 *
 * The single-register prologue is `stmdb sp!, {lr}` / `ldm sp!, {pc}`
 * rather than push/pop of a pair, because nothing here needs a
 * callee-saved register: every field load feeds its argument slot
 * directly.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020456F8.c \
 *       --func sub_020456F8 --addr 0x020456F8 --cc 1.1p1 --arm
 */
void sub_020456F8(struct Descriptor_02045334 *d)
{
    sub_02041300(d->unk2, 0, d->unk3, d->unk4, d->unk5, d->unk6, 0);
}



/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02045750, sub_02045758, sub_02045760, sub_02045768,
 *           sub_02045770, sub_02045778, sub_02045780, sub_02045788,
 *           sub_02045790, sub_02045798
 *
 * The leaf accessor bank of the allocator family's descriptor object.
 * Fourteen relocation-free 8-byte functions in a row, each one load or
 * store of a single field, which is why they can be folded into one unit
 * with no witnesses required at all.
 *
 * The descriptor they read is the argument block the surrounding
 * constructors carry around (sub_02045334, at the head of this packet,
 * uses the same offsets: +2, +5, +6, +0xa, +0xc). The fields this bank
 * exposes:
 *
 *   +0x02  u8   sub_02045730 get
 *   +0x03  u8   sub_02045758 get / sub_02045780 set
 *   +0x04  u8   sub_02045760 get / sub_02045788 set
 *   +0x05  u8   sub_02045738 get
 *   +0x06  u8   sub_02045740 get
 *   +0x07  u8   sub_02045748 get
 *   +0x08  u8   sub_02045750 get / sub_02045790 set
 *   +0x09  u8   sub_02045778 get / sub_02045798 set
 *   +0x0a  u16  sub_02045768 get
 *   +0x0c  void *  sub_02045770 get
 *
 * sub_02045770 is the heap-handle getter of this family: the pointer it
 * returns at +0xc is what sub_02045334 feeds to sub_020437D4 before the
 * allocation call at 0x02040B1C, so +0xc is the descriptor's heap /
 * owning-context handle rather than a payload pointer. It carries the
 * largest fan-in of the whole bank (1149 branch references image-wide),
 * which is consistent with every user of a descriptor reaching for its
 * heap handle.
 *
 * Only sub_02045730, sub_02045738, sub_02045740, sub_02045748,
 * sub_02045750, sub_02045758, sub_02045760, sub_02045768, sub_02045770,
 * sub_02045778 and sub_02045798 carry labels in the listing.
 * sub_02045780, sub_02045788 and sub_02045790 are unlabelled followers:
 * they save no lr, so disasm.py folds them into sub_02045778's extent
 * (see docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md). They
 * should be seeded into layout/function_starts.txt by the integrator.
 *
 * Field names are left descriptive rather than semantic: this whole
 * family is scheduled for a semantic rename once the allocator's argument
 * shapes settle.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02045730.c \
 *       --addr 0x02045730 --arm --cc 1.1p1
 */
u8 sub_02045730(struct Descriptor_02045730 *p)
{
    return p->unk2;
}


u8 sub_02045738(struct Descriptor_02045730 *p)
{
    return p->unk5;
}


u8 sub_02045740(struct Descriptor_02045730 *p)
{
    return p->unk6;
}


u8 sub_02045748(struct Descriptor_02045730 *p)
{
    return p->unk7;
}


u8 sub_02045750(struct Descriptor_02045730 *p)
{
    return p->unk8;
}


u8 sub_02045758(struct Descriptor_02045730 *p)
{
    return p->unk3;
}


u8 sub_02045760(struct Descriptor_02045730 *p)
{
    return p->unk4;
}


u16 sub_02045768(struct Descriptor_02045730 *p)
{
    return p->unkA;
}


void *sub_02045770(struct Descriptor_02045730 *p)
{
    return p->heap;
}


u8 sub_02045778(struct Descriptor_02045730 *p)
{
    return p->unk9;
}


void sub_02045780(struct Descriptor_02045730 *p, u8 v)
{
    p->unk3 = v;
}


void sub_02045788(struct Descriptor_02045730 *p, u8 v)
{
    p->unk4 = v;
}


void sub_02045790(struct Descriptor_02045730 *p, u8 v)
{
    p->unk8 = v;
}


void sub_02045798(struct Descriptor_02045730 *p, u8 v)
{
    p->unk9 = v;
}



/*
 * Setter for the allocator family's global u16 stamp at 0x020A7E7C: the
 * value every object of this family copies into its own +0x8 field when
 * it is constructed (sub_020457B0) or reset (sub_0204581C). Those two
 * functions are its readers, and their literal pools at 0x02045804 and
 * 0x02045834 are the outside witnesses for this file's own pool word,
 * which is why the three are kept in separate files rather than folded
 * into one unit: a single tu over 0x020457A0..0x02045838 would swallow
 * every pool copy of the address and cap at MATCH
 * (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md).
 *
 * 0x020A7E7C sits immediately before the __FILE__ string at 0x020A7E80
 * that sub_020457B0 passes to the allocator, so it is the last word of
 * data before the packed string area.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020457A0.c \
 *       --func sub_020457A0 --addr 0x020457A0 --cc 1.1p1 --arm
 */
void sub_020457A0(u16 stamp)
{
    g_020A7E7C.value = stamp;
}



/*
 * The constructor of the u16-array object, and a clean specimen of the
 * debug-allocator calling convention this whole family is built on:
 *
 *   sub_02030734(heapId, size, clear, site, tag)
 *
 * The fifth argument is a u16 passed on the stack, which the callee reads
 * back with a halfword load at [sp, #0x18]; here it is 100. It looks like
 * a __LINE__-style debug tag, but that is not established: the fourth
 * argument, which would be the matching __FILE__, is 0x020A7E80, and that
 * address is above the arm9 static image end (0x020A6800, from
 * layout/layout.json), so it is BSS, not a string constant in a packed
 * string area. Whatever the pair means, it is not the literal
 * __FILE__/__LINE__ shape of
 * docs/idioms/file-string-is-an-abs32-into-the-string-area.md, and it is
 * deliberately not written as such here.
 *
 * The allocation size, 2 * capacity + 0xa, is what pins the object
 * layout: a 0xa-byte header followed by capacity u16 entries.
 *
 *   +0x00  u16  capacity
 *   +0x02  u16  used
 *   +0x04  u32  magic, 0xECD2F8B6 while live
 *   +0x08  u16  stamp, copied from g_020A7E7C
 *   +0x0a  u16  entries[capacity]
 *
 * The zero that becomes the allocator's third argument is the same
 * register that later stores `used = 0`, so the two share one `mov
 * r4, #0`; writing the third argument as a named local instead splits
 * them.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020457B0.c \
 *       --func sub_020457B0 --addr 0x020457B0 --cc 1.1p1 --arm
 */
struct U16Vec *sub_020457B0(u32 capacity, u32 heapId)
{
    struct U16Vec *vec;

    vec = (struct U16Vec *)sub_02030734(heapId, capacity * 2 + 0xa, 0,
                                        g_020A7E7C.site, 100);
    vec->magic = 0xB6F8D2ECu;
    vec->capacity = (u16)capacity;
    vec->used = 0;
    vec->slots[0] = g_020A7E7C.value;
    return vec;
}



/*
 * The destructor of the u16-array object sub_020457B0 builds: it kills
 * the 0xECD2F8B6 liveness magic at +0x4 and then tail-calls the family's
 * generic free at 0x020307B0, which is the counterpart of the allocation
 * entry at 0x02030734 (it is also what sub_020452E8 finishes with).
 * Clearing the magic before the free is what makes a stale pointer
 * detectable rather than merely dangling.
 *
 * The tail call is the usual shape for this compiler: one section per
 * function means no displacement branch is available, so the target
 * becomes a pool word and a bx
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md). The pool word at
 * 0x02045818 is the whole reason the listing extent runs to 0x0204581C.
 *
 * layout/symbols_sdk.json carries the name ENV_SetResourceSet for
 * 0x020307B0. That looks like a signature-matcher false positive rather
 * than a real SDK export (0x020307B0 is game code in arm9_main and its
 * only observed role here is teardown), so the canonical sub_ name is
 * used instead.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02045808.c \
 *       --func sub_02045808 --addr 0x02045808 --cc 1.1p1 --arm
 */
void sub_02045808(struct U16Vec *vec)
{
    vec->magic = 0;
    sub_020307B0(vec);
}



/*
 * Resets one of the allocator family's u16-array objects in place: drops
 * the used count back to zero and re-stamps the object from the global at
 * 0x020A7E7C. It is the constructor body of sub_020457B0 minus the
 * allocation, the capacity store and the magic store, so it is the "reuse
 * this buffer" entry of the pair.
 *
 * The object shape, from sub_020457B0's allocation of 2 * capacity + 0xa
 * bytes:
 *
 *   +0x00  u16  capacity
 *   +0x02  u16  used
 *   +0x04  u32  magic (0xECD2F8B6 when live, 0 once sub_02045808 kills it)
 *   +0x08  u16  stamp, copied from g_020A7E7C
 *   +0x0a  u16  entries[capacity]
 *
 * The pool word is attested by the copies in sub_020457A0 and
 * sub_020457B0, which is why this function is its own file.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204581C.c \
 *       --func sub_0204581C --addr 0x0204581C --cc 1.1p1 --arm
 */
void sub_0204581C(struct U16Vec *vec)
{
    vec->used = 0;
    vec->slots[0] = g_020A7E7C.value;
}


/*
 * Copies the live part of one u16-array object into another, refusing the
 * copy if the destination cannot hold it. The guard is `capacity <=
 * used`, not `<`, so the destination needs strictly more capacity than
 * the source has entries; the extra slot is the +0x8 stamp, which the
 * copy carries along by starting two bytes before the entry array and
 * moving (used + 1) halfwords.
 *
 * See src/matched/sub_020457B0.c for the object layout. The trailing
 * `dst->used = src->used` re-reads the field rather than reusing the
 * cached value the guard and the length computation share: the two
 * objects are unrelated pointers, so the MI_CpuCopy8 call may alias
 * src->used and the load cannot be hoisted across it. Writing the tail as
 * an assignment from the cached local instead loses that reload and four
 * bytes with it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02045838.c \
 *       --func sub_02045838 --addr 0x02045838 --cc 1.1p1 --arm
 */
void sub_02045838(struct U16Vec *dst, struct U16Vec *src)
{
    u16 used;

    used = src->used;
    if (dst->capacity <= used) {
        return;
    }
    MI_CpuCopy8(&src->slots[0], &dst->slots[0], (used + 1) * 2);
    dst->used = src->used;
}


/*
 * Clones a u16-array object: allocate one with exactly enough room
 * (used + 1 slots, the +1 being the stamp slot that sub_02045838's guard
 * insists on), then copy into it.
 *
 * The heap id is never touched in this function's body. sub_020457B0
 * takes (capacity, heapId) and only r0 is set up here, so r1 arrives
 * untouched from this function's own second parameter: the shape of
 * docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md
 * read in reverse, where the "leftover" register really is a passed
 * argument and naming it is what makes the code compile to two
 * instructions instead of three.
 *
 * `used + 1` reaches sub_020457B0 with no narrowing, which is what pins
 * that function's first parameter to a full word rather than the u16 its
 * own body would suggest: see
 * docs/idioms/a-missing-truncation-at-the-call-site-widens-the-parameter.md.
 * With a u16 prototype this function comes out eight bytes long and
 * sub_020457B0 still matches, so the call site is the only evidence for
 * the width.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02045874.c  *       --func sub_02045874 --addr 0x02045874 --cc 1.1p1 --arm
 */
struct U16Vec *sub_02045874(struct U16Vec *src, u32 heapId)
{
    struct U16Vec *dst;

    dst = sub_020457B0(src->used + 1, heapId);
    sub_02045838(dst, src);
    return dst;
}


/*
 * Halfword-string equality with the buffer module's terminator stamp: the
 * first element is compared directly, then the loop walks both strings while
 * they agree, succeeding as soon as either side meets the global terminator
 * (0xFFFF) rather than the other buffer.
 *
 * Two shapes are load-bearing:
 *  - `int i = 0;` at its declaration puts the `mov ip, #0` ahead of the
 *    guard's compare; assigning i after the guard lands it after the
 *    terminator pool load instead.
 *  - The guard must NOT be a bare `if (..) return 0;`: mwcc predicates that
 *    into `movne r0, ip; popne {r3, pc}`.  Folding it into one shared exit
 *    (the `if (a->w[0] == b->w[0])` arm holding the loop, a single
 *    `return 0;` after it) makes the guard a real `bne` to that exit, which
 *    is what the image has.  The identical `goto fail` spelling compiles to
 *    the same bytes.
 *
 * The 0x020A7E7C ABS32 sits in this function's own pool (0x020458F4, inside
 * the compared range) and resolves off the `literal` class: the same word is
 * in the pools of the already-matched func_02045924, func_02045994 and
 * sub_020457A0.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204589C.c \
 *       --func func_0204589C --addr 0x0204589C --cc 1.1p1 --arm
 */
int func_0204589C(struct Buf *a, struct Buf *b)
{
    int i = 0;

    if (a->w[0] == b->w[0]) {
        do {
            if (a->w[i] == sStrbufEnd) {
                return 1;
            }
            i++;
        } while (a->w[i] == b->w[i]);
    }

    return 0;
}


/*
 * Reads the used-slot count of a u16-array object (see
 * src/matched/sub_020457B0.c for the layout). A relocation-free leaf; it
 * is the public reader for the field sub_02045900 and sub_02045838 write
 * directly.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020458F8.c  *       --func sub_020458F8 --addr 0x020458F8 --cc 1.1p1 --arm
 */
u16 sub_020458F8(struct U16Vec *vec)
{
    return vec->used;
}


/*
 * Truncates a u16-array object back to `index` slots, writing the stamp
 * into the slot that becomes the new terminator. It is the inverse of
 * whatever appends, and it is a no-op when `index` is not strictly below
 * the current count, so it can only ever shrink.
 *
 * The whole body is predicated on `lo` with no branch at all, which is
 * why the guard has to be an unsigned comparison: `index` is a full u32
 * (nothing masks it before `add r3, r0, r1, lsl #1`) while `used` is a
 * zero-extended u16, so the comparison is unsigned on both sides and a
 * signed `int` index produces `lt` instead.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02045900.c  *       --func sub_02045900 --addr 0x02045900 --cc 1.1p1 --arm
 */
void sub_02045900(struct U16Vec *vec, u32 index)
{
    if (index < vec->used) {
        vec->slots[index] = g_020A7E7C.value;
        vec->used = index;
    }
}



/*
 * strbuf.c's `strcpy`-into-a-bounded-buffer: the terminator is the halfword
 * at 0x020A7E7C (0xFFFF), the buffer's capacity is the halfword at +0 and
 * the count is kept at +2, with the halfword array starting at +8.  The
 * first copy stops on the terminator, the second on a full buffer, and the
 * terminator is always written at the end - which is why the exit block is
 * shared and why the count is re-read there.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02045924.c \
 *       --func func_02045924 --addr 0x02045924 --cc 1.1p1 --arm
 */
void func_02045924(struct Strbuf *o, const u16 *src)
{
    o->n = 0;
    while (*src != sStrbufEnd) {
        if (o->n >= o->cap - 1)
            break;
        o->buf[o->n++] = *src;
        src++;
    }
    o->buf[o->n] = sStrbufEnd;
}



/*
 * strbuf.c's bounded copy of a counted string: refuse anything longer than
 * the buffer, copy until the source's own terminator shows up or the last
 * usable slot is filled, and only when the whole source was copied (the
 * count landed exactly on n-1) append the terminator.  The `n > cap` guard
 * is a predicated `pophi`, and the final conditional store is the ARM
 * `ldreq`/`addeq`/`strheq` triple.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02045994.c \
 *       --func func_02045994 --addr 0x02045994 --cc 1.1p1 --arm
 */
void func_02045994(struct Strbuf *o, const u16 *src, u32 len)
{
    u32 i;

    if (len > o->cap)
        return;

    for (i = 0; i < len - 1; i++) {
        o->buf[i] = src[i];
        if (o->buf[i] == sStrbufEnd)
            break;
    }

    o->n = i;
    if (i == len - 1)
        o->buf[len - 1] = sStrbufEnd;
}



/*
 * Append n halfwords to a counted buffer: the count is the halfword at +2,
 * the current length is the halfword at +0, the data starts at +8, and the
 * whole thing is halfword-indexed, which is why the copy size is `n * 2`.
 * A null count and an over-long count are both refused, each as its own
 * predicated early return on the entry compare (`movs` for the first, a
 * `pophi` for the unsigned second).
 *
 * The stored count is one less than n, and it is computed from the incoming
 * value rather than by re-reading the field, so it is a subtraction on r4.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02045A00.c \
 *       --func func_02045A00 --addr 0x02045A00 --cc 1.1p1 --arm
 */
void func_02045A00(struct Buf_p12 *buf, const void *src, u32 n)
{
    if (n == 0)
        return;
    if (n > buf->len)
        return;

    MI_CpuCopy8(src, buf->data, n * 2);
    buf->count = n - 1;
}



/*
 * Copies at most `n` slots out of a u16-array object into a caller's
 * buffer, stopping after the slot that equals the stamp, and forcing a
 * stamp into the last output slot if the loop ran to the limit without
 * finding one. In other words the stamp is this container's terminator
 * value and this is its bounded, always-terminated extraction.
 *
 * Two shape tells worth keeping:
 *
 *  - The stamp is re-read from the global on every iteration
 *    (`ldrh ip, [r3]` inside the loop, from a pool base hoisted out of
 *    it). It is not volatile: the store into the caller's buffer may
 *    alias it, so the load cannot be hoisted. Caching it in a local
 *    before the loop removes the reload and shortens the body.
 *  - The final store is written as a pointer expression, not a subscript.
 *    `add r1, r1, r2, lsl #1` followed by `strh r0, [r1, #-2]` scales,
 *    adds, then subtracts the element size, which is what
 *    `*(out + n - 1)` produces; `out[n - 1]` folds to a single scaled
 *    offset instead
 *    (docs/idioms/pointer-minus-one-scales-before-the-subtraction.md).
 *
 * The loop is the compiler's usual rotation of a counted `for`: a
 * zero-trip guard at the top, the increment and the bound test at the
 * bottom, and the `break` falling straight into the `i == n` test that
 * distinguishes "found the terminator" from "ran out of room". Because
 * `break` leaves the counter un-incremented, that one comparison is the
 * whole post-condition and no separate flag is needed. The entire tail is
 * predicated on `eq`, so it costs no branch.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02045A38.c \
 *       --func sub_02045A38 --addr 0x02045A38 --cc 1.1p1 --arm
 */
void sub_02045A38(struct U16Vec *vec, u16 *out, u32 n)
{
    u32 i;
    u16 v;

    for (i = 0; i < n; i++) {
        v = vec->slots[i];
        out[i] = v;
        if (g_020A7E7C.value == v) {
            break;
        }
    }
    if (i == n) {
        *(out + n - 1) = g_020A7E7C.value;
    }
}


/*
 * Returns the address of the u16-array object's slot array, which begins
 * at +0x8 with the stamp slot. A single `add r0, r0, #8` and `bx lr`: the
 * function exists only so callers outside this file need not know the
 * header size.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02045A90.c  *       --func sub_02045A90 --addr 0x02045A90 --cc 1.1p1 --arm
 */
u16 *sub_02045A90(struct U16Vec *vec)
{
    return vec->slots;
}


/*
 * A two-instruction ARM read accessor used all over the ARM9 image (the
 * halfword at 0x020A7E7C, a UI/input mode word).  The literal pool word is
 * attested by sole-ref/data: 0x020A7E7C is a mapped pool-word object with 99
 * referring sites, none of them this 16-byte range.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02045A98.c \
 *       --func func_02045A98 --addr 0x02045A98 --cc 1.1p1 --arm --region arm9
 */
u16 func_02045A98(void)
{
    return d_020A7E7C;
}



/*
 * The two mutators of the u16 vector sub_020457B0 allocates, folded into one
 * translation unit covering 0x02045AA8..0x02045B38 (both functions and the
 * single trailing pool word).  See src/matched/sub_02045AFC.c for the object
 * layout this pair pins down, in particular why the entries begin at +0x8
 * and why one slot past `capacity` is reserved for a terminator.
 *
 * sub_02045AA8 concatenates one vector onto another, copying src->used + 1
 * halfwords so that the source's terminator becomes the destination's.
 * sub_02045AFC pushes a single entry and re-plants the terminator behind it.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02045AA8.c \
 *       --addr 0x02045AA8 --arm
 */
void sub_02045AA8(struct U16Vec *dst, struct U16Vec *src)
{
    u16 count = src->used;

    if (dst->used + count + 1 > dst->capacity)
        return;

    MI_CpuCopy8(&src->slots[0], &dst->slots[dst->used], (count + 1) * 2);
    dst->used = dst->used + src->used;
}


void sub_02045AFC(struct U16Vec *vec, u16 value)
{
    if (vec->used + 1 >= vec->capacity)
        return;

    vec->slots[vec->used++] = value;
    vec->slots[vec->used] = g_020A7E7C.value;
}



/*
 * The archive-backed constructor for the message bank whose object layout is
 * pinned by src/matched/unit_02045C44.c, and the reason that object carries
 * both a `stream` handle and a `resident` flag.  func_02045C44 builds a bank
 * over a file the caller already has; this one opens the archive, seeks the
 * member, reads its header and then decides: a resident bank allocates the
 * whole payload up front and calls func_02046110 to index it, a streamed bank
 * leaves `base` null and reads entries on demand in func_02045CAC.
 *
 * The allocation tags are 0x68 for the bank and 0x7b for the payload, both
 * passed as the fifth argument on the stack, with the same BSS provenance
 * object at 0x020A7E8C in the fourth (not a __FILE__ string; see the note in
 * unit_02045C44.c).  The provenance pointer and the constant zero are each
 * loaded once into a callee-saved register and reused at both call sites,
 * which is what pins them as plain literals at the calls rather than named
 * locals.
 *
 * The file offset returned by func_02049578 is bound to a local: the original
 * spends `mov r1, r0` on it before the store to +0x10, four bytes that vanish
 * if the store's value is re-read from the field for the func_02046084 call
 * (docs/idioms/cmp-operand-order-names-the-temporary.md, same tell).  The
 * stream handle and the file pointer are not: both are read back from the
 * field and the compiler forwards the store it just made.
 *
 * The resident arm is the fall-through, so the guard is spelled `!= 0` and the
 * one-store arm is left to be if-converted into `streq`
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02045B38.c \
 *       --func sub_02045B38 --addr 0x02045B38 --cc 1.1p1 --arm
 */
struct MsgBank_22 *sub_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId)
{
    struct MsgBank_22 *bank;
    u32 origin;

    bank = (struct MsgBank_22 *)sub_02030734(heapId, 0x1c, 0, g_020A7E8C, 0x68);
    bank->heapId = (u16)heapId;
    bank->stream = func_020490F4(arcId, heapId);
    origin = func_02049578(bank->stream, fileId);
    bank->origin = origin;
    bank->resident = (u8)resident;
    bank->file = func_02046084(bank->stream, origin, bank->heapId);
    bank->langIndex = func_020461B8((struct Header *)bank->file);

    if (bank->resident != 0) {
        bank->base = sub_02030734(bank->heapId, bank->file->size, 0,
                                  g_020A7E8C, 0x7b);
        func_02046110((struct MsgDataVol *)bank);
    } else {
        bank->base = 0;
    }
    return bank;
}



/*
 * Tear down the record: when the +0x14 handle is live, release the two
 * buffers it owns (the second only if non-NULL) and close the handle, then
 * free the record itself either way.
 *
 * The +0x14 guard reads the field once and the close reads it again, which
 * is why the original has two `ldr r0, [r4, #0x14]` around the calls: the
 * intervening frees may alias it, so no `const` local is involved.  The
 * second buffer's guard needs no register move, the guarded call consuming
 * the value the `cmp` already loaded.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02045C04.c \
 *       --func func_02045C04 --addr 0x02045C04 --cc 1.1p1 --arm
 */
u32 func_02045C04(struct Rec *rec)
{
    if (rec->unk_14 != 0) {
        func_020307B0(rec->unk_00);
        if (rec->unk_04 != 0) {
            func_020307B0(rec->unk_04);
        }
        func_02049238(rec->unk_14);
    }
    return func_020307B0(rec);
}



/*
 * The whole of pkt_02045C44, 448 bytes with both literal pools: the message
 * bank's constructor and its one reader.  Both functions are EXACT
 * individually as well (src/matched/func_02045C44.c and
 * src/matched/func_02045CAC.c); this unit is the consolidated shape.
 *
 * The object is 0x1c bytes and its layout is pinned by the pair:
 *
 *   +0x00  const MsgFile *file   the mapped message file header
 *   +0x04  void          *base   entry table plus payload, when resident
 *   +0x08  MsgEntry       cache  one streamed descriptor
 *   +0x10  u32            origin file offset of the bank inside the archive
 *   +0x14  void          *stream archive handle
 *   +0x18  u16            heapId
 *   +0x1a  u8             langIndex
 *   +0x1b  u8             resident
 *
 * func_02045CAC has two residency modes.  Resident: the entry descriptor is
 * &((MsgEntry *)(base + 4))[index] and the payload is base + e->off, handed
 * straight to func_02045A00.  Streamed: the descriptor is an 8-byte archive
 * read into the cache at +0x8, then a scratch buffer of 2 * e->len bytes is
 * allocated, filled by a second read, consumed and freed.  The allocator
 * heap id for that scratch buffer is (u16)((heapId & 0x7fff) | 0x8000), the
 * "allocate from the far end" form.
 *
 * Both file offsets are origin + file->langOff[langIndex] plus the entry's
 * own displacement, so langOff[] at +0xc of the file header is a
 * per-language section table and the entry table starts four bytes into its
 * section.
 *
 * Shape note that cost the last eleven bytes of func_02045CAC: both guards
 * test bank->resident, but the source spells them `== 0`, not `!= 0`.  That
 * puts the streamed arm on the fall-through and leaves the short arm to be
 * if-converted (ldrne/addne), per
 * docs/idioms/the-fall-through-arm-is-the-source-order.md.  The other
 * polarity emits exactly the same instructions but transposes
 * `ldr r3, [sb, #0x10]` and `lsl r0, r8, #3` in the seek block: the arm
 * linearisation order is what breaks the scheduler's tie between the two
 * ready gap fillers.
 *
 * The fourth argument of sub_02030734 is the BSS provenance object at
 * 0x020A7E8C, not a __FILE__ string: it sits above the arm9 static image
 * end and has 41 pool references image-wide.  In func_02045C44 the
 * allocator's third argument (clear) shares one `mov r5, #0` with the two
 * zero field stores, so it is written as a plain literal at the call rather
 * than bound to a named local (the shape of src/matched/sub_020457B0.c).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02045C44.c \
 *       --addr 0x02045C44 --arm
 */
struct MsgBank_23 *func_02045C44(const void *file, u32 heapId)
{
    struct MsgBank_23 *bank;

    bank = (struct MsgBank_23 *)sub_02030734(heapId, 0x1c, 0, g_020A7E8C, 0xa6);
    bank->heapId = (u16)heapId;
    bank->stream = 0;
    bank->origin = 0;
    bank->resident = 1;
    bank->file = (const struct MsgFile_p14 *)file;
    bank->langIndex = func_020461B8((struct Header *)file);
    func_02046110((struct MsgDataVol *)bank);
    return bank;
}



void func_02045CAC(struct MsgBank_23 *bank, u32 index, void *dest)
{
    u32 size;
    struct MsgEntry *e;

    if (index >= bank->file->count) {
        func_0204581C(dest);
        return;
    }

    func_02046180((struct Obj *)bank);

    if (bank->resident == 0) {
        u32 pos = bank->origin + bank->file->langOff[bank->langIndex];

        func_0204960C(bank->stream, pos + (index * 8 + 4));
        func_020495F4(bank->stream, 8, &bank->cache);
        e = &bank->cache;
    } else {
        e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
    }

    if (bank->resident == 0) {
        void *buf;

        size = e->len * 2;
        buf = sub_02030734((u16)((bank->heapId & 0x7fff) | 0x8000), size,
                           0, g_020A7E8C, 0xd6);
        if (buf != 0) {
            func_0204960C(bank->stream,
                          e->off + (bank->origin
                              + bank->file->langOff[bank->langIndex]));
            func_020495F4(bank->stream, size, buf);
            func_02045A00(dest, buf, e->len);
            func_020307B0(buf);
        }
    } else {
        func_02045A00(dest, (u8 *)bank->base + e->off, e->len);
    }

    func_02045E04(dest, index);
}



/*
 * Advance the object by one: read its current index (sub_020458F8), ask
 * sub_02045E3C for the entry one past it in the list sub_02045A90 returns,
 * and install the answer with sub_02045900.
 *
 * Three of the four calls need the object pointer, so it is pinned in r6
 * for the whole body; the incoming second argument survives in r5 across
 * two calls before reaching sub_02045E3C's r2.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02045E04.c \
 *       --func sub_02045E04 --addr 0x02045E04 --cc 1.1p1 --arm
 */
void sub_02045E04(struct Obj_02045E04 *o, u32 mode)
{
    s32 index = sub_020458F8((struct U16Vec *)o);

    sub_02045900((struct U16Vec *)o, sub_02045E3C(sub_02045A90((struct U16Vec *)o), index + 1, mode));
}



/*
 * The message-bank string cipher, decrypting a raw UTF-16-code-unit run in
 * place. This is the routine the asset lane's tools/assets/text.py was
 * reverse-engineering; the code states the scheme exactly:
 *
 *   key = (u16)((msgIndex + 3) * 0x2983)
 *   for each code unit: unit ^= key, then key = rotate_left_16(key, 3)
 *
 * The seed is derived forward from the entry's own descriptor index in the
 * message file, so no brute force or terminator-anchored back-solve is
 * needed. Decryption stops at the first unit that equals the global
 * end-of-string code func_02045A98() returns (0xFFFF in this build), and the
 * function returns the index of that unit, i.e. the decoded length; if no
 * terminator is found inside count units it returns count.
 *
 * Note for the asset side: there is no compression layer on top of this
 * cipher. Decoded streams are plain code units plus in-band control codes
 * (0xFFFF terminator, 0xFFFE line break, 0xF000 escape introducer followed
 * by a kind word, an argument count and that many argument words).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02045E3C.c \
 *       --func func_02045E3C --addr 0x02045E3C --cc 1.1p1
 */
u32 func_02045E3C(u16 *str, u32 count, u32 msgIndex)
{
    u16 eos = func_02045A98();
    u16 key = (u16)((msgIndex + 3) * 0x2983);
    u32 i;

    for (i = 0; i < count; i++) {
        *str ^= key;
        if (*str == eos) {
            return i;
        }
        str++;
        key = (u16)(((key & 0xE000) >> 13) | (u16)(key << 3));
    }

    return count;
}



/*
 * Message bank string allocator and loader: given a bank and an entry index,
 * reads the entry descriptor (from the resident array or stream), allocates
 * a buffer sized for the string length, decodes the string into it via
 * sub_02045CAC, and returns the allocated buffer.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02045EC0.c \
 *       --func sub_02045EC0 --addr 0x02045EC0 --cc 1.1p1 --arm
 */
void *sub_02045EC0(struct MsgBank_23 *bank, u32 index)
{
    struct MsgEntry *e;
    void *buf;

    sub_02046180((struct Obj *)bank);

    if (bank->resident == 0) {
        u32 pos = bank->origin + bank->file->langOff[bank->langIndex];

        sub_0204960C(bank->stream, pos + (index * 8 + 4));
        sub_020495F4(bank->stream, 8, &bank->cache);
        e = &bank->cache;
    } else {
        e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
    }

    buf = sub_020457B0(e->len, bank->heapId);
    sub_02045CAC(bank, index, buf);
    return buf;
}



/*
 * A three-instruction accessor: follow the pointer at +0 of the object and
 * return the halfword at +2 of what it points at.  It saves nothing, so
 * disasm.py never labelled it and it only shows up by sweeping the packet
 * by address (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * `ldrh` with no sign extension fixes the field as u16; an s16 would have
 * needed a register-offset `ldrsh`
 * (docs/idioms/ldrsh-register-offset-is-signedness.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02045F50.c \
 *       --func sub_02045F50 --addr 0x02045F50 --cc 1.1p1 --arm
 */
u16 sub_02045F50(const struct Obj_02045F50 *o)
{
    return o->head->unk_02;
}



/*
 * msgdata.c: read string msgIndex into str (at most maxLen characters),
 * either from the resident bank (mode != 0) or by seeking the archive file,
 * then decode it in place (func_02045E3C) and terminate it with the EOM
 * code (func_02045A98).
 *
 * The 11-byte scheduling residue of docs/notes/pkt_02045F5C.c.txt was the
 * first test's polarity: written `mode == 0` with the file arm first, the
 * compiler predicates the else arm (ldrne/addne/addne/bne) and schedules
 * the file arm's loads in the image's order.
 */
void func_02045F5C(struct MsgData *msg, u32 msgIndex, u16 *str, u32 maxLen)
{
    const struct MsgEntry_p15 *entry;
    u32 count;
    u32 len;

    func_02046180((struct Obj *)msg);

    if (msg->mode == 0) {
        u32 bankOffset = msg->archive->bankOffset[msg->bankIndex];
        func_0204960C(msg->file, (msg->baseOffset + bankOffset) + (msgIndex * 8 + 4));
        func_020495F4(msg->file, 8, &msg->entry);
        entry = &msg->entry;
    } else {
        entry = (const struct MsgEntry_p15 *)((u8 *)msg->bank + 4 + msgIndex * 8);
    }

    count = entry->count;
    if (count > maxLen) {
        count = maxLen;
    }

    if (msg->mode == 0) {
        u32 readBytes = count * 2;
        if (readBytes > maxLen * 2) {
            readBytes = maxLen * 2;
        }
        {
            u32 bankOffset = msg->archive->bankOffset[msg->bankIndex];
            func_0204960C(msg->file, (msg->baseOffset + bankOffset) + entry->offset);
            func_020495F4(msg->file, readBytes, str);
        }
    } else {
        const u16 *src = (const u16 *)((u8 *)msg->bank + entry->offset);
        u32 i;
        for (i = 0; i < count; i++) {
            str[i] = src[i];
        }
    }

    len = func_02045E3C(str, count, msgIndex);
    str[len] = func_02045A98();
}



/*
 * Read a message file's header out of the archive and keep it.  The fixed
 * twelve-byte part is read onto the stack first because its language count is
 * what sizes the real allocation, 0xc + 4 * langCount; the stack copy is then
 * moved into the front of that block and the language offset table is read
 * straight in behind it.  This is the only caller of sub_02030734 with tag
 * 0x1f3.
 *
 * The header is twelve bytes here but sixteen in the MsgFile view used by
 * src/matched/unit_02045C44.c, which declares langOff[1] inline, so the fixed
 * part gets its own struct.  The scratch is declared as a raw twelve-byte
 * buffer and cast, not as that struct: `ldrh r1, [r6]` reads the language
 * count back through the pointer the reader was handed, and a declared struct
 * local folds to `ldrh r1, [sp, #4]` instead, two bytes and the only
 * difference in the function
 * (docs/idioms/a-declared-struct-local-folds-to-sp-relative-a-cast-buffer-does-not.md).
 *
 * The shared 0xc is a single `mov r5, #0xc` feeding both the read length and
 * the copy length, and the `add r1, r1, #0xc` of the allocation size is a
 * separate literal, so the size argument is written as the literal at each
 * call and not bound to a named local.
 *
 * func_02082D44 takes source first and destination second (the MI_CpuCopy8
 * order), which is why the stack buffer is in r0 and the freshly allocated
 * block in r1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02046084.c \
 *       --func func_02046084 --addr 0x02046084 --cc 1.1p1 --arm
 */
struct MsgFile *func_02046084(void *stream, u32 origin, u16 heapId)
{
    u8 hdr[12];
    struct MsgFileHdr *hp;
    struct MsgFile *file;

    func_0204960C(stream, origin);
    hp = (struct MsgFileHdr *)hdr;
    func_020495F4(stream, sizeof(struct MsgFileHdr), hp);

    file = (struct MsgFile *)sub_02030734(heapId, hp->langCount * 4 + 0xc, 0,
                                          g_020A7E8C, 0x1f3);
    func_02082D44(hp, file, sizeof(struct MsgFileHdr));
    func_020495F4(stream, file->langCount * 4, file->langOff);
    return file;
}


/*
 * msgdata.c: point the MsgData object at the selected language bank.  The
 * archive header holds one u32 bank offset per language at +0x0C; with no
 * file handle the bank is resident and the object records archive +
 * offset, otherwise it seeks, reads the leading u32 size, seeks back and
 * reads the whole bank.
 *
 * The four bytes the earlier notes could not reach (docs/notes/
 * func_02046110.c.txt, pkt_02046110.c.txt) are the `ldreq r0, [r4]`
 * reload of the archive pointer in the resident arm.  Every plain spelling
 * CSEs it into the load already made for the offset table; declaring the
 * member `volatile` keeps both loads and leaves every other instruction,
 * the predication included, unchanged.
 */
void func_02046110(struct MsgDataVol *msg)
{
    u32 size;
    u32 offset = msg->archive->bankOffset[msg->bankIndex];

    if (msg->file == 0) {
        msg->bank = (u8 *)msg->archive + offset;
    } else {
        func_0204960C(msg->file, msg->baseOffset + offset);
        func_020495F4(msg->file, 4, &size);
        func_0204960C(msg->file, msg->baseOffset + offset);
        func_020495F4(msg->file, size, msg->bank);
    }
}


/*
 * Re-read the clamped index for the header at +0 and, if it moved, record
 * it at +0x1a and redraw through sub_02046110 when the enable byte at +0x1b
 * says so.
 *
 * The two guards do not share an exit: the first `popeq` returns from the
 * comparison itself and the second `popne` from the enable test, which is
 * what a plain chain of early returns compiles to.  The enable byte is read
 * one instruction before the store to +0x1a: both are separate fields of
 * the same struct, so the compiler is free to schedule the load first and
 * does.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02046180.c \
 *       --func sub_02046180 --addr 0x02046180 --cc 1.1p1 --arm
 */
void sub_02046180(struct Obj *o)
{
    s32 index = sub_020461B8(o->header);

    if (o->index == index) {
        return;
    }
    if (o->enabled != 1) {
        o->index = (u8)index;
        return;
    }
    o->index = (u8)index;
    sub_02046110((struct MsgData *)o);
}


/*
 * Clamp sub_020461E4's answer to the count the header keeps at +0: past the
 * end wraps back to entry zero.  The comparison is signed (`movge`), so the
 * count is read as a halfword but compared as an int.
 *
 * The verdict is EXACT*, not EXACT: the next function, the one-byte global
 * setter at 0x020461D4, saves nothing, so disasm.py folds it into this
 * function's extent and the inferred range runs sixteen bytes long.  It is
 * decompiled separately in src/matched/sub_020461D4.c and wants seeding
 * into layout/function_starts.txt, which is the integrator's file.
 *
 * `movge r0, #0` in place of a branch is the whole `if` body: one
 * conditional instruction, no shared exit block to reason about, because
 * both arms fall into the same `pop`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020461B8.c \
 *       --func sub_020461B8 --addr 0x020461B8 --cc 1.1p1 --arm
 */
s32 sub_020461B8(struct Header *h)
{
    s32 index = sub_020461E4(h);

    if (index >= h->count) {
        index = 0;
    }
    return index;
}
