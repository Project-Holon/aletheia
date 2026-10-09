/*
 * file:     gf_font.c
 * unit:     yes
 * function: func_0201CEE0, func_0201D110, func_0201D26C, func_0201D2C8, func_0201D304, func_0201D33C, func_0201D37C, func_0201D42C, func_0201D478, func_0201D4BC, func_0201D528, func_0201D5C4, func_0201D5CC, func_0201D5F4, func_0201D60C, func_0201D658, func_0201D670, func_0201D688, func_0201D69C, func_0201D6B8, func_0201D6C4, func_0201D6D8, func_0201D768, func_0201D7C4, func_0201D7EC, func_0201D83C, func_0201D854, func_0201D9C8, func_0201DA00, func_0201DA24, func_0201DAA4, func_0201DADC, func_0201DAF0, sub_0201DB00, func_0201DB04, func_0201DB20, func_0201DBBC, func_0201DBF4, func_0201DC44, func_0201DC6C, func_0201DC80, func_0201DC88, func_0201DD58, func_0201DD60, func_0201DD68, func_0201DD78, func_0201DE00, func_0201DE18, func_0201DE40, func_0201E4C8, func_0201E4D4, func_0201E538, func_0201E738, func_0201E928, func_0201EC64, func_0201EC74, func_0201ED04, func_0201ED50, func_0201ED64, func_0201ED84, func_0201EDD0, func_0201EE0C, func_0201EE60, func_0201EE84, func_0201EEA4, func_0201EEC4, func_0201EED4, func_0201EEF4, func_0201EF14, func_0201EF34, func_0201EF40, func_0201EF4C, func_0201EF5C, func_0201EF6C, func_0201EF8C, func_0201EF98, func_0201EFA4, func_0201EFC8, func_0201EFFC, func_0201F020, func_0201F02C, func_0201F048, func_0201F094, func_0201F0F8, func_0201F104, func_0201F124, func_0201F134, func_0201F140, func_0201F14C, func_0201F158, func_0201F164, func_0201F184, func_0201F198, func_0201F1B0, func_0201F1C8, func_0201F1E0, func_0201F230, func_0201F250, func_0201F31C, func_0201F344, func_0201F35C, func_0201F41C, func_0201F448, func_0201F47C, func_0201F4A0
 * address:  0x0201CEE0
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
 *   func_020437DC  0x020437DC  arm
 *   func_020437E4  0x020437E4  arm
 *   func_020439A0  0x020439A0  arm
 *   func_02043AF4  0x02043AF4  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_0201C974  0x0201C974  thumb
 *   sub_0201CEB8   0x0201CEB8  thumb
 *   func_02013020  0x02013020  thumb
 *   func_02013050  0x02013050  thumb
 *   sub_0201CDF4   0x0201CDF4  thumb
 *   sub_0201DC6C  0x0201DC6C  thumb
 *   sub_02045A90  0x02045A90  arm
 *   sub_0204581C  0x0204581C  arm
 *   sub_02045AFC  0x02045AFC  arm
 *   sub_0201DC80  0x0201DC80  thumb
 *   func_02045A90  0x02045A90  arm
 *   memcpy         0x02082D44  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   func_02030734 0x02030734 arm
 *   func_020490F4 0x020490F4 arm
 *   lbl_020A7358  0x020A7358 data
 *   func_020307B0  0x020307B0  arm
 *   func_0201D854_File  0x020A7358  data
 *   func_0201DC88       0x0201DC88  thumb
 *   func_020494F4       0x020494F4  arm
 *   func_020493D4       0x020493D4  arm
 *   sub_0204944C        0x0204944C  arm
 *   g_0209E73C  0x0209E73C  data
 *   func_0201DA24_File  0x020A7358  data
 *   g_0209E744  0x0209E744  data
 *   func_0204960C  0x0204960C  arm
 *   func_020495F4  0x020495F4  arm
 *   g_02146578   0x02146578  data
 *   g_02146588   0x02146588  data
 *   g_0209E74C   0x0209E74C  data
 *   sFile_020A7364  0x020A7364  data  a1
 *   func_020457B0   0x020457B0  arm
 *   unk_020A7370   0x020A7370  data
 *   func_0202473C  0x0202473C  thumb
 *   func_02025B94  0x02025B94  thumb
 *   func_0204581C  0x0204581C  arm
 *   func_02045AFC  0x02045AFC  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   g_0209E784     0x0209E784  data
 *   g_0209E758     0x0209E758  data
 *   g_0209E838     0x0209E838  data
 *   func_0201F4A0_Table  0x0209E864  data
 */
#include "../../matched/include/Obj06870.h"
#include "../../matched/include/Obj07086.h"
#include "../../matched/include/Obj11722.h"

struct Bmp;
struct CharBuf;
struct Descriptor;
struct Font_0201CEE0;
struct U16Vec;
struct PrintSys;
struct Ring;
struct ArcFile;
struct Font_0201D9C8;
struct WordSet;
struct MsgBank;
struct Rec;
struct Obj;
struct Tag;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed int     s32;

struct PrintCtx {
    s16   unk00;
    s16   unk02;
    s32   unk04 : 10;
    u32   unk04b : 22;
    u16   unk08;
    u16   unk0A;
    u16   unk0C;
    u16   unk0E;
    void *unk10;
    void *unk14;
    void *unk18;
};

struct Rec {
    u32  state;        /* 0x00 */
    u32  mode;         /* 0x04 */
    u32  f08;          /* 0x08 */
    u32  win;          /* 0x0c */
    void *task;        /* 0x10 */
    u16 *cur;          /* 0x14 */
    u8   f18;
    u8   f19;
    u8   f1a;
    u8   f1b;
    u8   f1c;
    u8   f1d;
    u8   wait;         /* 0x1e */
    u8   scroll;       /* 0x1f */
    u8   color;        /* 0x20 */
    u8   cbres;        /* 0x21 */
    struct {
        u8 b0 : 1;
        u8 b1 : 1;
        u8 b2 : 1;
        u8 b3 : 1;
        u8 b4 : 1;
        u8 rest : 3;
    } flags;           /* 0x22 */
    u8   pad23;
    u8 (*cb)(u32);     /* 0x24 */
    u32  f28;
    u32  f2c;
    u32  cbarg;        /* 0x30 */
    struct PrintCtx ctx; /* 0x34 */
};

struct StrObj {
    u16 capacity;
    u16 used;
    u32 magic;
    u16 slots[1];
};

struct Ring {
    u16 head;
    u16 tail;
    u16 size;
};

typedef struct {
    u8  pad00[4];
    u16 f04;
    u8  pad06[0x10 - 6];
    void *f10;
    u32   f14;
} Blk;

struct PrintSys {
    u16 unk00;
    u16 unk02;
    u16 unk04;
    u8  unk06;
    u8  unk07;
    u32 unk08;
    u32 unk0C;
    void *unk10;
    void *unk14;
    u8  buf[4];
};

struct GfFont {
    char pad_00[0x50];
    void *field_50;
    int field_54;
};

struct Font_0201CEE0 {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    void *unk0C;
    u8  pad10[0x40];
    void *unk50;
    void *unk54;
    u8  unk58[8];
    u32 unk60;
    u32 unk64;
    u32 unk68;
    u32 unk6C;
    u16 unk70;
    u8  unk72;
    u8  pad73;
    u8  unk74;
    u8  unk75;
    u16 unk76;
    u8  pad78[4];
    u16 unk7C;
    u8  unk7E;
    u8  unk7F;
    void *unk80;
    void *unk84;
    void *unk88;
    void *unk8C;
    void *unk90;
};

struct Font_0201D9C8 {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    void *unk0C;
    u8  pad10[0x40];
    void *unk50;
    void *unk54;
    u8  unk58[8];
    void *unk60;
    void *unk64;
    void *unk68;
    u32 unk6C;
    u16 unk70;
    u8  unk72;
    u8  pad73;
    u8  unk74;
    u8  unk75;
    u16 unk76;
    u8  pad78[4];
    u16 unk7C;
    u8  unk7E;
    u8  unk7F;
    void *unk80;
    void *unk84;
    void *unk88;
    void *unk8C;
    void *unk90;
};

struct Font_0201DA00 {
    u32 unk00;
    u8  pad04[0x7A];
    u8  unk7E;
    u8  unk7F;
};

typedef void (*FontInit)(struct Font_0201DA00 *f, u32 w, u32 h, u32 heap);

struct Font_0201DA24 {
    u32   unk00;
    u32   unk04;
    u32   unk08;
    void *unk0C;
    u8    pad10[0x40];
    void *unk50;
    u32   unk54;
    u8    pad58[0x34];
    u32   unk8C;
};

typedef void (*FontFini)(struct Font_0201D9C8 *f);

struct Font_0201DAF0 {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    void *unk0C;
    u8  pad10[0x40];
    void *unk50;
    void *unk54;
    u8  unk58[8];
    void *unk60;
    void *unk64;
    void *unk68;
    u32 unk6C;
    u16 unk70;
    u8  unk72;
    u8  pad73;
    u8  unk74;
    u8  unk75;
    u16 unk76;
    u8  pad78[4];
    u16 unk7C;
    u8  unk7E;
    u8  unk7F;
    void *unk80;
    void *unk84;
    void *unk88;
    void *unk8C;
    void *unk90;
};

struct CMap {
    u16 ccodeBegin;
    u16 ccodeEnd;
    u16 mappingMethod;
    u16 reserved;
    struct CMap *pNext;
    u16 mapInfo[1];
};

struct Font_0201DB20 {
    u8  pad00[0x68];
    u8 *unk68;
    u32 pad6C;
    u16 unk70;
    u8  pad72[0x16];
    u8 *unk88;
};

struct Font_0201DBBC {
    u32   format;
    u32   measure;
    u32   decode;
    u8   *body;
    u8    pad10[0x40];
    void *handle;
    u8    pad54[0x22];
    u16   mapSize;
    u8    pad78[4];
    u16   lastCols;
    u8    tilesW;
    u8    tilesH;
    void *resHdr;
    void *bodyBuf;
    void *charMap;
    void *glyphDir;
    void *scratch;
};

struct Font_0201DBF4 {
    u32   format;
    u32   measure;
    u32   decode;
    u8   *body;
    u8    pad10[0x40];
    void *handle;
    u8    pad54[0x22];
    u16   mapSize;
    u8    pad78[4];
    u16   lastCols;
    u8    tilesW;
    u8    tilesH;
    void *resHdr;
    void *bodyBuf;
    void *charMap;
    void *glyphDir;
    void *scratch;
};

struct Font_0201DC44 {
    u32   pad00[2];
    void (*unk08)(const u8 *src, u16 w, void *dst);
    u32   pad0C[19];
    u8    pad58;
    u8    unk59;
};

struct Font_0201DC6C {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    void *unk0C;
    u8  pad10[0x40];
    void *unk50;
    void *unk54;
    u8  unk58[8];
    void *unk60;
    void *unk64;
    void *unk68;
    u32 unk6C;
    u16 unk70;
    u8  unk72;
    u8  pad73;
    u8  unk74;
    u8  unk75;
    u16 unk76;
    u8  pad78[4];
    u16 unk7C;
    u8  unk7E;
    u8  unk7F;
    void *unk80;
    void *unk84;
    void *unk88;
    void *unk8C;
    void *unk90;
};

typedef signed   char  s8;

struct Hdr0201DC88 {
    u8  dflt[3];
    u8  pad3;
    u32 bits;       /* +4 */
    u32 hash;       /* +8 */
    u32 chain;      /* +0xc */
};

struct BitReader {
    const u8 *src;
    u32       avail;
    u8        cur;
};

struct FontState {
    u8               colour[3];
    u8               pad;
    struct BitReader br;
};

struct Tag {
    u8 unk00;
    u8 unk01;
    u8 unk02;
    u8 unk03 : 7;
    u8 unk03b : 1;
    u8 unk04;
};

struct Entry {
    struct Tag tag;
    void *str;
};

struct WordSet {
    u32 count;
    u32 heap;
    struct Entry *entries;
    void *buf;
};

typedef signed int     s32_0201F0F8;

typedef int            s32_0201F35C;

typedef signed int     s32_0201F4A0;

struct Lim {
    u32 hi;
    u32 bias;
    u32 hi2;
};

extern u16 func_020437DC(const struct Bmp *bmp);
extern u16 func_020437E4(const struct Bmp *bmp);
extern void func_020439A0(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);
extern void func_02043AF4(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void  func_02045334(struct Descriptor *a);
extern u16  *func_0201C974(struct PrintCtx *c, u16 *p, u32 f);
extern void  sub_0201CEB8(struct Rec *p);
extern signed char func_02013020(void);
extern signed char func_02013050(void);
extern void sub_0201CDF4(s32 v, u8 *out);
extern u32 sub_0201DC6C(struct Font_0201CEE0 *p, u16 ch);
extern u16 *sub_02045A90(struct U16Vec *vec);
extern void sub_0204581C(struct U16Vec *vec);
extern void sub_02045AFC(struct U16Vec *vec, u16 value);
extern u32 sub_0201DC80(struct Font_0201CEE0 *p);
extern u16 *func_02045A90(struct U16Vec *vec);
extern void func_02045AFC(struct U16Vec *vec, u16 value);
extern u16 func_020458F8(struct U16Vec *vec);
extern void *memcpy(void *dst, const void *src, u32 n);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern u32 func_020307B0(void *p);
extern void sub_0204944C(struct ArcFile *arc, u32 member, u32 offset, u32 size, void *dst);
extern void func_020494F4(struct ArcFile *arc, u32 member, u32 *out);
extern u32 func_020493D4(struct ArcFile *arc, u32 member);
extern u8 func_0201DC88(u8 *obj, u32 id);
extern void func_02049238(void *p);
extern void func_0204960C(void *handle, u32 off);
extern void func_020495F4(struct ArcFile *arc, u32 size, void *dst);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void  MI_CpuFill8(void *dest, u8 data, u32 size);
extern u32   func_02017E1C(void *p, u32 id, u32 v);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern void func_02045808(struct U16Vec *vec);
extern void func_0204581C(struct U16Vec *vec);
extern void func_02045838(struct U16Vec *dst, struct U16Vec *src);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_02045C04(struct Rec *rec);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_020246C8(u16 *p, u32 mode, u32 flag);
extern u32 func_0202473C(u32 *p, u32 a);
extern void func_02024838(u32 id, void *dest, u32 heap);
extern u16 func_02045F50(const struct Obj *o);
extern void  sub_02008500(void *a, void *b);
extern u32   func_02025B94(u32 a);
extern u32 func_0202A230(void *a, u32 idx);
extern void func_0200785C(void *save, u32 box, void *dest);
extern u16  func_02045A98(void);
extern u32  _u32_div_f(u32 a, u32 b);
extern void func_02045AA8(struct U16Vec *dst, struct U16Vec *src);
void func_0201CEE0(void *task, struct Rec *p);
void sub_0201D110(struct Rec *p);
u32 sub_0201D26C(u16 *p, void *font, u32 spacing, u16 **next);
u32 sub_0201D2C8(struct StrObj *s);
u32 sub_0201D304(struct StrObj *s, u32 a, u32 b);
u32 sub_0201D33C(struct StrObj *s, u32 a, u32 b, u32 *out, u32 max);
u32 sub_0201D37C(struct StrObj *src, struct StrObj *dst, u32 n);
u32 sub_0201D42C(struct StrObj *s, void *font);
u32 func_0201D478(void *s);
u32 func_0201D4BC(void *s, u8 v);
u32 func_0201D528(void *s, u8 b, void *c, u32 d);
u32 func_0201D5C4(void);
u32 func_0201D5CC(const u16 *p);
u32 func_0201D5F4(const u16 *p);
void func_0201D60C(void *s, u32 b, u32 c, u16 n, const u16 *arr);
u32 func_0201D658(const u16 *p);
u32 func_0201D670(const u16 *p, u32 i);
u16 *func_0201D688(u16 *p);
u32 func_0201D69C(void *s);
u32 func_0201D6B8(void *s);
u32 func_0201D6C4(const struct Ring *p);
void func_0201D6D8(Blk *p, void *b, void *c);
void *func_0201D768(struct Ring *ring, const u8 *src, u16 len, u16 unit);
void *func_0201D7C4(struct PrintSys *p, void *q);
struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
u32 func_0201D83C(void *ptr);
void func_0201D854(struct Font_0201CEE0 *f, int resid, u32 flag, u32 heap);
void func_0201D9C8(struct Font_0201D9C8 *p);
void func_0201DA00(struct Font_0201DA00 *f, u32 fmt, u32 heap);
void func_0201DA24(struct Font_0201DA24 *f, u32 a, u32 b, u8 heap);
void func_0201DAA4(char *p, int a, int b);
void func_0201DADC(struct Font_0201D9C8 *f);
void func_0201DAF0(struct Font_0201DAF0 *p);
void sub_0201DB00(struct Font_0201DAF0 *p);
void func_0201DB04(struct Font_0201DAF0 *p, u16 ch, void *c, void *d);
u32 func_0201DB20(struct Font_0201DB20 *f, u16 c);
void func_0201DBBC(const struct Font_0201DBBC *f, u32 i, void *d, u8 *out);
void func_0201DBF4(const struct Font_0201DBF4 *f, u32 i, void *d, u8 *out);
void func_0201DC44(struct Font_0201DC44 *f, const u8 *g, u32 w, void *d, u8 *out);
u32 func_0201DC6C(struct Font_0201DC6C *p, u16 ch);
u32 func_0201DC80(struct Font_0201DC6C *p);
u8 sub_0201DC88(u8 *obj, u32 id);
u32 func_0201DD58(struct Font_0201DC6C *p);
void func_0201DD60(void);
void func_0201DD68(void);
void func_0201DD78(u32 r, u32 g, u32 b);
void func_0201DE00(u8 *r, u8 *g, u8 *b);
u32 func_0201DE18(u32 r, u32 g, u32 b);
void func_0201DE40(const u8 *src, u32 n, u16 *dst);
void func_0201E4C8(struct BitReader *b, const u8 *p);
u8 sub_0201E4D4(struct BitReader *r, u8 n);
void func_0201E538(const u8 *src, u32 n, u16 *dst);
void func_0201E738(const u8 *src, u32 n, u16 *dst);
void func_0201E928(const u8 *src, u32 n, u16 *dst);
struct WordSet *func_0201EC64(u16 heap);
struct WordSet *func_0201EC74(u32 n, u32 size, u16 heap);
u32 func_0201ED04(struct WordSet *p);
void func_0201ED50(struct Tag *t);
void func_0201ED64(struct WordSet *p, u32 i);
void func_0201ED84(struct WordSet *p, u32 i, const void *src, const struct Tag *tag);
void func_0201EDD0(struct WordSet *p, u32 i, u32 id, u32 v);
void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
void func_0201EE60(struct WordSet *p, u32 i, u16 v);
void func_0201EE84(struct WordSet *p, u32 i, void *mon);
void func_0201EEA4(struct WordSet *p, u32 i, void *mon);
void func_0201EEC4(struct WordSet *p, u32 i, u32 v);
void func_0201EED4(struct WordSet *p, u32 i, void *mon);
void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
void func_0201EF14(struct WordSet *p, u32 i, void *mon);
void func_0201EF34(struct WordSet *p, u32 i, u32 v);
void func_0201EF40(struct WordSet *p, u32 i, u32 v);
void func_0201EF4C(struct WordSet *p, u32 i, u32 v);
void func_0201EF5C(struct WordSet *p, u32 i, u32 v);
void func_0201EF6C(struct WordSet *p, u32 i, u32 v, u32 a, u32 b);
void func_0201EF8C(struct WordSet *p, u32 i, u32 v);
void func_0201EF98(struct WordSet *p, u32 i, u32 v);
void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
void func_0201EFC8(struct WordSet *p, u32 i, u32 v);
void func_0201EFFC(struct WordSet *p, u32 i, u32 v);
void func_0201F020(struct WordSet *p, u32 i, u32 v);
void func_0201F02C(struct WordSet *p, u32 i, void *a);
void func_0201F048(struct WordSet *p, u32 i, u32 n);
void func_0201F094(struct WordSet *p, u32 i, u32 a, u32 n);
void func_0201F0F8(struct WordSet *p, u32 i, u32 v);
void func_0201F104(struct WordSet *p, u32 i, u32 a);
void func_0201F124(struct WordSet *p, u32 i, u32 v);
void func_0201F134(struct WordSet *p, u32 i, u32 v);
void func_0201F140(struct WordSet *p, u32 i, u32 v);
void func_0201F14C(struct WordSet *p, u32 i, u32 v);
void func_0201F158(struct WordSet *p, u32 i, u32 v);
void func_0201F164(struct WordSet *p, u32 i, u32 a, u32 b);
void func_0201F184(struct WordSet *p, u32 i, s32_0201F0F8 v);
void func_0201F198(struct WordSet *p, u32 i, u32 v);
void func_0201F1B0(struct WordSet *p, u32 i, u8 v);
void func_0201F1C8(struct WordSet *p, u32 i, u32 v);
void func_0201F1E0(struct WordSet *p, u32 i, u32 v);
void func_0201F230(struct WordSet *p, u32 i, u32 v);
void func_0201F250(struct WordSet *ws, void *dst, void *src);
void func_0201F31C(struct WordSet *p);
void func_0201F344(u16 heap);
void func_0201F35C(void *ctx, s32_0201F35C n, u32 kind, u32 mode, u32 flag);
void func_0201F41C(const u16 *src, u16 *dst, u32 n);
u32 func_0201F448(const u16 *a, const u16 *b);
u32 func_0201F47C(void *s);
void func_0201F4A0(void *dest, void *src);
extern const char lbl_020A7358[];
extern const char func_0201D854_File[];
extern FontInit g_0209E73C[];
extern const char func_0201DA24_File[];
extern FontFini g_0209E744[];
extern struct FontState g_02146578;
extern u16 g_02146588[256];
extern const u8         g_0209E74C[];
extern char sFile_020A7364[];
extern void *unk_020A7370;
extern u16  g_0209E784[];
extern u16  g_0209E758[];
extern u32  g_0209E838[];
extern const u16 func_0201F4A0_Table[];









static inline u32 CtrlCode(u16 c, const u16 *p)
{
    if (c == 0xF000)
        return (u8)(p[1] >> 8);
    return 0xFF;
}









/*
 * The per-frame task callback that func_0201CD10 installs for a printsys
 * text record (the 0x50-byte object, struct PrintCtx at +0x34).  State 0
 * either scrolls the window up by at most four lines (flag bit 1) or, once
 * the wait counter at +0x1e is spent, prints up to f1b/f1d glyphs through
 * func_0201C974, handling 0xFFFF (end: state 2), 0xFFFE (line break) and
 * the 0xF000/0xBE control block (sub_0201D110).  State 1 waits on flag
 * bit 2 and then clears or scrolls the window.
 *
 * Shape facts, each measured against the bytes:
 *  - The flag byte at +0x22 is a struct of 1-bit fields.  Reads through
 *    the bitfield give the lsls/lsrs pairs off ONE cached ldrb; writes
 *    through the same bitfield reload the byte each time.  Spelled with
 *    `((u8 *)p)[0x22]` masks the tests fold to `tst` and the writes reuse
 *    the cached byte.
 *  - The two early exits are `goto end`, not `return`: they land on the
 *    function's LAST epilogue through a branch island, as a `break` would
 *    (docs/idioms/an-empty-switch-arm-breaks-to-the-last-epilogue-not-the-nearest.md).
 *  - The glyph loop is `i = 0; if (i < n) { ...; do { } while (i < n); }`
 *    with `ctx = &p->ctx;` in the guarded preheader.  A `for` loop puts
 *    the store before the guard and duplicates the test.
 *  - The dispatch is a switch on the loaded halfword, and the control-code
 *    helper takes that VALUE: its own `== 0xF000` test then reuses the
 *    switch's compare, which is the dead `bne` at 0x0201D01E.  Given the
 *    pointer it reloads the halfword and is eight bytes long.
 *  - `case 1: default:` share one arm in the inner mode switch, which is
 *    why the image has `cmp r0, #1` followed by an unconditional `b`.
 *
 * note 2026-10-05: removed the stand-in first store of the pair
 * `ctx = (struct PrintCtx *)p; ctx = &p->ctx;`. The single
 * `ctx = &p->ctx;` is EXACT in --lang c99 and --lang c.
 */
void func_0201CEE0(void *task, struct Rec *p)
{
    s32 n;
    s32 i;
    u32 w;
    s32 h;
    struct PrintCtx *ctx;
    u16 c;

    if (p->cb != 0 && p->cbres != 0) {
        p->cbres = p->cb(p->cbarg);
        if (p->cbres != 0)
            goto end;
        p->cbarg = p->f2c;
    }

    if (p->flags.b0)
        goto end;

    switch (p->state) {
    case 0:
        if (p->flags.b1) {
            if (p->scroll < 0x10) {
                u16 k = 4;
                if (p->scroll + 4 > 0x10)
                    k = 0x10 - p->scroll;
                p->scroll += (u8)k;
                w = func_020437DC((const struct Bmp *)p->win);
                h = func_020437E4((const struct Bmp *)p->win) - k;
                func_020439A0((struct Bmp *)p->win, (struct Bmp *)p->win, 0, k, 0, 0, w, h, 0xFFFF);
                func_02043AF4((struct Bmp *)p->win, 0, (s16)h, w, k, p->color);
                func_02045334((struct Descriptor *)p->f08);
                return;
            }
            p->ctx.unk00 = p->ctx.unk04;
            p->ctx.unk02 = 0x10;
            p->flags.b1 = 0;
            return;
        }
        if (p->wait == 0) {
            if (p->flags.b3)
                n = p->f1d;
            else
                n = p->f1b;
            if (p->flags.b4) {
                sub_0201CEB8(p);
                p->flags.b4 = 0;
            }
            i = 0;
            if (i < n) {
                ctx = &p->ctx;
                do {
                    c = *p->cur;
                    switch (c) {
                    case 0xFFFF:
                        p->state = 2;
                        break;
                    case 0xF000:
                        if (CtrlCode(c, p->cur) == 0xBE) {
                            sub_0201D110(p);
                            if (p->cb != 0) {
                                p->cbres = p->cb(p->cbarg);
                                if (p->cbres != 0)
                                    i = n;
                                else
                                    p->cbarg = p->f2c;
                            }
                            if (p->state != 0 || p->wait != 0)
                                i = n;
                            break;
                        }
                    default:
                        p->cur = func_0201C974(ctx, p->cur, 0);
                        c = *p->cur;
                        if (c == 0xFFFF) {
                            p->state = 2;
                        } else if (c != 0xFFFE) {
                            if (p->flags.b3)
                                p->wait = p->f1c;
                            else
                                p->wait = p->f1a;
                        }
                        func_02045334((struct Descriptor *)p->f08);
                        if (p->cb != 0) {
                            p->cbres = p->cb(p->cbarg);
                            if (p->cbres != 0)
                                i = n;
                            else
                                p->cbarg = p->f2c;
                        }
                        break;
                    }
                    i++;
                } while (i < n);
            }
        } else {
            p->wait--;
        }
        return;
    case 1:
        if (p->flags.b2) {
            switch (p->mode) {
            case 0:
                p->flags.b1 = 1;
                p->state = 0;
                return;
            case 1:
            default:
                func_02043B5C((struct CharBuf *)p->win, p->color);
                p->state = 0;
                return;
            }
        }
        return;
    }
end:
    ;
}








static inline u32 KB(const u16 *p)
{
    return (u8)p[1];
}








static inline u16 CtrlKind(u16 c, const u16 *p)
{
    if (c == 0xF000)
        return KB(p);
    return 0xFFFF;
}








static inline u16 CtrlArg(u16 c, const u16 *p, u32 i)
{
    if (c == 0xF000)
        return *(p + i + 3);
    return 0;
}








static inline u16 CtrlArgP(const u16 *p, u32 i)
{
    u16 c = p[0];
    if (c == 0xF000)
        return *(p + i + 3);
    return 0;
}








static inline u16 *CtrlSkip(u16 *p)
{
    if (p[0] == 0xF000)
        return p + 3 + p[2];
    return p;
}








static inline void SetMode(struct Rec *r, u32 m)
{
    r->state = 1;
    r->mode = m;
}







/*
 * Applies the 0xF000 control block the text record's cursor is parked on
 * and steps the cursor past it (struct Rec as in func_0201CEE0.c).  The
 * block's kind (low byte of its second halfword) is a dense 0..9 switch:
 * 0/1 pause for a key (mode 0 or 1) and home the pen, 2 sets the wait,
 * 3/4/9 set the per-glyph delay pair at +0x1a/+0x1b (9 through the
 * speed setting func_02013020 / func_02013050 and sub_0201CDF4), 5/6/7
 * set the callback argument, 8 clears the window.  A pause also skips a
 * 0xFFFE that directly follows the block.
 *
 * Shape facts measured against the bytes:
 *  - `*cur` is a named local: it is the LEFT operand of the header test
 *    (docs/idioms/cmp-operand-order-names-the-temporary.md), and the
 *    per-case argument reads reuse it.  Only case 6's second read goes
 *    back through p->cur, after the +0x2c store.
 *  - The kind helper returns u32 `(u8)p[1]` into a u16 return, which is
 *    the (u8) then (u16) shift-pair stack in the header arm only.
 *  - state/mode are written by an inline taking the record as its own
 *    parameter; written in line, mwcc hoists the flag-byte load above
 *    those two stores and cases 0/1 stop cross-jumping (20 bytes).
 *  - In the shared tail the pen x copy precedes the pen y clear.
 */
void sub_0201D110(struct Rec *p)
{
    u32 skip;
    u8 buf[2];
    u16 *cur;
    u16 c;

    cur = p->cur;
    c = cur[0];
    skip = 0;
    switch (CtrlKind(c, cur)) {
    case 0:
        skip = 1;
        SetMode(p, 0);
        p->scroll = 0;
        ((u8 *)p)[0x22] = ((u8 *)p)[0x22] & ~4u;
        p->ctx.unk00 = p->ctx.unk04;
        p->ctx.unk02 = 0;
        break;
    case 1:
        skip = 1;
        SetMode(p, 1);
        p->scroll = 0;
        ((u8 *)p)[0x22] = ((u8 *)p)[0x22] & ~4u;
        p->ctx.unk00 = p->ctx.unk04;
        p->ctx.unk02 = 0;
        break;
    case 2:
        p->wait = CtrlArg(c, cur, 0);
        break;
    case 3:
        p->f1a = CtrlArg(c, cur, 0);
        break;
    case 4:
        p->f1a = p->f18;
        break;
    case 9:
        switch ((u8)CtrlArg(c, cur, 0)) {
        case 0:
        default:
            buf[0] = p->f18;
            buf[1] = p->f19;
            break;
        case 1:
            sub_0201CDF4(func_02013020(), buf);
            break;
        case 2:
            sub_0201CDF4(func_02013050(), buf);
            break;
        }
        p->f1a = buf[0];
        p->f1b = buf[1];
        break;
    case 5:
        p->cbarg = CtrlArg(c, cur, 0);
        break;
    case 6:
        p->f2c = CtrlArg(c, cur, 0);
        p->cbarg = CtrlArgP(p->cur, 0);
        break;
    case 7:
        p->f2c = p->f28;
        p->cbarg = p->f28;
        break;
    case 8:
        func_02043B5C((struct CharBuf *)p->win, p->color);
        break;
    }

    cur = CtrlSkip(p->cur);
    p->cur = cur;
    if (skip != 0 && *cur == 0xFFFE)
        p->cur = cur + 1;
}








/*
 * printsys.c: measures one line of a string object.  It sums the per-glyph
 * advance sub_0201DC6C returns plus a fixed inter-character spacing until it
 * hits the line break 0xFFFE or the terminator 0xFFFF, steps over embedded
 * 0xF000 blocks (three header halfwords plus the payload count at +4), and,
 * when the fourth argument is non-NULL, writes back the cursor for the next
 * line (past the break, if that is what stopped it).
 *
 * 0xFFFF is not pooled: the compiler keeps the pooled 0xFFFE in a register and
 * derives the terminator as `adds r6, r0, #1`.
 *
 * The repeated `c == 0xF000` test is the source's own: the block skip re-tests
 * the code word it was selected by, and the compiler keeps the second branch
 * while folding away the second compare.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201D26C.c
 *       --func sub_0201D26C --addr 0x0201D26C --cc 1.1p1 --thumb
 */
u32 sub_0201D26C(u16 *p, void *font, u32 spacing, u16 **next)
{
    u32 sum;
    u16 c;

    sum = 0;
    while ((c = *p) != 0xFFFF && c != 0xFFFE) {
        if (c != 0xF000) {
            sum += spacing + sub_0201DC6C(font, c);
            p++;
        } else {
            if (c == 0xF000) {
                p = p + 3 + p[2];
            }
        }
    }
    if (next != 0) {
        if (c == 0xFFFE) {
            p++;
        }
        *next = p;
    }
    return sum;
}








/*
 * printsys.c: counts the lines of a string object, i.e. one plus the number
 * of 0xFFFE line-break codes before the 0xFFFF terminator.  0xF000 opens an
 * embedded block whose halfword length sits at +4, so the walker steps over
 * three header halfwords plus that many payload halfwords.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201D2C8.c
 *       --func sub_0201D2C8 --addr 0x0201D2C8 --cc 1.1p1 --thumb
 */
u32 sub_0201D2C8(struct StrObj *s)
{
    u16 *p;
    u32 n;
    u16 c;

    p = sub_02045A90((struct U16Vec *)s);
    c = *p;
    n = 1;
    while (c != 0xFFFF) {
        if (c != 0xF000) {
            if (c == 0xFFFE) {
                n++;
            }
            p++;
        } else {
            if (c == 0xF000) {
                p = p + 3 + p[2];
            }
        }
        c = *p;
    }
    return n;
}








/*
 * printsys.c: the width of the widest line of a multi-line string.  It walks
 * the string object's halfword payload one line at a time with sub_0201D26C,
 * which measures one line and writes the cursor for the next one back through
 * its fourth argument, and keeps the running maximum.  0xFFFF is the string
 * terminator (the same sentinel sub_0201C8BC stops on).
 *
 * The cursor is a local whose address is taken, so it lives on the stack and
 * the loop test reloads it every iteration.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201D304.c
 *       --func sub_0201D304 --addr 0x0201D304 --cc 1.1p1 --thumb
 */
u32 sub_0201D304(struct StrObj *s, u32 a, u32 b)
{
    u16 *p;
    u32 best;
    u32 w;

    best = 0;
    p = sub_02045A90((struct U16Vec *)s);
    while (*p != 0xFFFF) {
        w = sub_0201D26C(p, (void *)a, b, &p);
        if (w > best) {
            best = w;
        }
    }
    return best;
}








/*
 * printsys.c: fills a caller-supplied array with the pixel width of each line
 * of a string object, at most `max` of them, and returns how many were
 * written.  sub_0201D26C measures one line and hands back the cursor for the
 * next through its fourth argument; the cursor is a stack local because its
 * address is taken.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201D33C.c
 *       --func sub_0201D33C --addr 0x0201D33C --cc 1.1p1 --thumb
 */
u32 sub_0201D33C(struct StrObj *s, u32 a, u32 b, u32 *out, u32 max)
{
    u16 *p;
    u32 i;

    p = sub_02045A90((struct U16Vec *)s);
    i = 0;
    while (i < max) {
        if (*p == 0xFFFF) {
            break;
        }
        out[i] = sub_0201D26C(p, (void *)a, b, &p);
        i++;
    }
    return i;
}








/*
 * printsys.c: copies line `n` of a string object into a second, freshly
 * cleared string object and returns whether the line existed.  Phase one skips
 * n line breaks, phase two appends the line a halfword at a time and closes it
 * with the 0xFFFF terminator.  Embedded 0xF000 blocks are skipped in phase one
 * and copied verbatim in phase two.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201D37C.c
 *       --func sub_0201D37C --addr 0x0201D37C --cc 1.1p1 --thumb
 */
u32 sub_0201D37C(struct StrObj *src, struct StrObj *dst, u32 n)
{
    u16 *end;
    u16 *p;
    u16 c;

    p = sub_02045A90((struct U16Vec *)src);
    sub_0204581C((struct U16Vec *)dst);
    while (n != 0) {
        while ((c = *p) != 0xFFFF && c != 0xFFFE) {
            if (c != 0xF000) {
                p++;
            } else {
                if (c == 0xF000) {
                    p = p + 3 + p[2];
                }
            }
        }
        n--;
        if (c == 0xFFFF) {
            break;
        }
        p++;
    }
    if (n == 0 && *p != 0xFFFF) {
        while ((c = *p) != 0xFFFF && c != 0xFFFE) {
            if (c != 0xF000) {
                sub_02045AFC((struct U16Vec *)dst, *p++);
            } else {
                if (c == 0xF000) {
                    end = p + 3;
                end = end + p[2];
                } else {
                    end = p;
                }
                while (p < end) {
                    sub_02045AFC((struct U16Vec *)dst, *p++);
                }
            }
        }
        sub_02045AFC((struct U16Vec *)dst, 0xFFFF);
        return 1;
    }
    return 0;
}








/*
 * printsys.c: the pixel height of a string object, i.e. its line count times
 * the font's line height (sub_0201DC80).  The line counter is a u16, so the
 * increment carries the halfword truncation pair.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201D42C.c
 *       --func sub_0201D42C --addr 0x0201D42C --cc 1.1p1 --thumb
 */
u32 sub_0201D42C(struct StrObj *s, void *font)
{
    u16 *p;
    u16 c;
    u16 n;

    p = sub_02045A90((struct U16Vec *)s);
    c = *p;
    n = 0;
    while (c != 0xFFFF) {
        if (c == 0xFFFE) {
            n++;
        }
        if (c == 0xF000) {
            if (c == 0xF000) {
                p = p + 3 + p[2];
            }
        } else {
            p++;
        }
        c = *p;
    }
    return (n + 1) * sub_0201DC80(font);
}








/*
 * Counts the control tags of a message string for which func_0201D5CC returns
 * true.  The walk is the one every routine in this neighbourhood uses: 0xF000
 * opens a tag and func_0201D688 steps over it, anything else is one halfword,
 * and 0xFFFF ends the string.
 *
 * The counter and the cursor are interchanged unless the cursor is declared
 * first: the original keeps the cursor in r4 and the counter in r5 while the
 * counter is the one initialised first, which is
 * docs/idioms/declaration-order-decides-which-register-a-local-gets.md read in
 * the direction that costs the time.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201D478.c \
 *       --addr 0x0201D478 --thumb
 */
u32 func_0201D478(void *s)
{
    u16 *p;
    u16 n = 0;

    p = func_02045A90(s);

    while (p[0] != 0xFFFF) {
        if (p[0] == 0xF000) {
            if (func_0201D5CC(p) != 0) {
                n = (u16)(n + 1);
            }
            p = func_0201D688(p);
        } else {
            p = p + 1;
        }
    }
    return n;
}








/*
 * Finds the index of the 0xBD06 tag whose first parameter is the caller's
 * value, counting 0xFFFE separators as it goes.  The tag's parameter is read
 * with func_0201D670's body written out inline (`p[0] == 0xF000 ? p[3] : 0`),
 * including the redundant re-test of p[0] that the caller has already made: that
 * guard is in the bytes and removing it costs four instructions.
 *
 * 0xFFFE is not a second pool word.  The original loads 0xFFFF once and derives
 * 0xFFFE with `subs r4, r0, #1`, which is ordinary common subexpression
 * elimination on the constant and needs nothing in the source.
 *
 * The leading call to func_02045A90 whose result is discarded is in the original
 * and is reproduced rather than tidied.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201D4BC.c \
 *       --addr 0x0201D4BC --thumb
 */
u32 func_0201D4BC(void *s, u8 v)
{
    u16 *p;
    u16 n = 0;
    u32 t;

    func_02045A90(s);
    p = func_02045A90(s);
    while (p[0] != 0xFFFF) {
        if (p[0] == 0xFFFE) {
            n = (u16)(n + 1);
        }
        if (p[0] == 0xF000) {
            if (p[1] == 0xBD06) {
                if (p[0] == 0xF000) {
                    t = p[3];
                } else {
                    t = 0;
                }
                if (v == t) {
                    return (u8)n;
                }
            }
            p = func_0201D688(p);
        } else {
            p = p + 1;
        }
    }
    return 0;
}








/*
 * Measures a message string up to the 0xBD06 tag whose parameter is the
 * caller's value, in the font c, adding d of spacing per character.  0xFFFE
 * resets the running width, a 0xBD04 tag adds its parameter, and anything that
 * is not a tag is measured with func_0201DC6C.
 *
 * The halfword under the cursor has to be a named local.  Written as `p[0]` at
 * each of its five uses the compiler caches it in r1, which is the second
 * argument register, and the call to func_0201DC6C then needs no move; the
 * original caches it in r2 and spends `adds r1, r2, #0`, which is two bytes and
 * is the only difference between the two spellings.  That is the argument form
 * of docs/idioms/cmp-operand-order-names-the-temporary.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201D528.c \
 *       --addr 0x0201D528 --thumb
 */
u32 func_0201D528(void *s, u8 b, void *c, u32 d)
{
    u32 acc = 0;
    u16 *p;
    u32 t;
    u16 ch;

    p = func_02045A90(s);
    while (p[0] != 0xFFFF) {
        ch = p[0];
        if (p[0] == 0xFFFE) {
            acc = 0;
            p = p + 1;
        } else if (p[0] != 0xF000) {
            acc = acc + (d + func_0201DC6C((struct Font_0201DC6C *)((struct Font_0201CEE0 *)c), ch));
            p = p + 1;
        } else {
            if (p[1] == 0xBD06) {
                if (p[0] == 0xF000) {
                    t = p[3];
                } else {
                    t = 0;
                }
                if (b == t) {
                    return (u8)acc;
                }
            }
            if (p[1] == 0xBD04) {
                if (p[0] == 0xF000) {
                    t = p[3];
                } else {
                    t = 0;
                }
                acc = acc + t;
            }
            if (p[0] == 0xF000) {
                p = p + 3 + p[2];
            }
        }
    }
    return 0;
}








/*
 *           func_0201D658, func_0201D670, func_0201D688
 *
 * The message-tag primitives of the text stack, seven functions and 216 bytes.
 * A tag is a run of halfwords opening with 0xF000: the halfword at +2 packs a
 * group in its high byte and a kind in its low byte, +4 is the parameter count,
 * and the parameters follow at +6.  func_0201D688 steps a cursor over one tag
 * and is what every walker in this region loops on.
 *
 * Three of the seven carry no label in the generated listing, because a
 * two-instruction leaf saves nothing and disasm.py's prologue sweep never fires
 * on it (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md);
 * func_0201D5F4, func_0201D658 and func_0201D670 were read out of the `.word`
 * run the listing prints.
 *
 * Three details cost time and each is in an existing idiom:
 *
 *   - `k == 1 || k == 2` compiles to a `subs` / `cmp` / `bhi` range check and is
 *     two bytes short.  The original compares twice, which is what a `switch`
 *     with two empty falling case labels gives.
 *   - the group byte is `(u8)(p[1] >> 8)` and the shift is an `asrs`, because
 *     the u16 promotes to a signed int before the shift; writing the field as
 *     u32 gives `lsrs` and one wrong byte.
 *   - func_0201D670 indexes with `*(p + i + 3)`, not `p[3 + i]`.  The subscript
 *     form folds the addition into the index and scales once, the pointer form
 *     scales `i` and leaves the +3 as the load's immediate, which is
 *     docs/idioms/pointer-minus-one-scales-before-the-subtraction.md.
 *
 * func_0201D60C's parameter count is `u16`, not `u32`: it is passed straight to
 * func_02045AFC with no truncation, and a `u32` parameter costs the `lsls` /
 * `lsrs` pair there.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201D5C4.c \
 *       --addr 0x0201D5C4 --thumb
 */
u32 func_0201D5C4(void)
{
    return 0xF000;
}








u32 func_0201D5CC(const u16 *p)
{
    u32 k;

    if (p[0] == 0xF000) {
        k = (u8)(p[1] >> 8);
    } else {
        k = 0xFF;
    }
    switch (k) {
    case 1:
    case 2:
        return 1;
    }
    return 0;
}








u32 func_0201D5F4(const u16 *p)
{
    if (p[0] == 0xF000) {
        return (u8)(p[1] >> 8);
    }
    return 0xFF;
}








void func_0201D60C(void *s, u32 b, u32 c, u16 n, const u16 *arr)
{
    u32 i;

    func_02045AFC(s, 0xF000);
    func_02045AFC(s, (u16)((u16)(b << 8) | c));
    func_02045AFC(s, n);
    for (i = 0; i < n; i = (u8)(i + 1)) {
        func_02045AFC(s, arr[i]);
    }
}








u32 func_0201D658(const u16 *p)
{
    if (p[0] == 0xF000) {
        return (u8)p[1];
    }
    return 0xFF;
}








u32 func_0201D670(const u16 *p, u32 i)
{
    if (p[0] == 0xF000) {
        return *(p + i + 3);
    }
    return 0;
}








u16 *func_0201D688(u16 *p)
{
    if (p[0] == 0xF000) {
        return p + 3 + p[2];
    }
    return p;
}








/*
 * The first three functions of gf_font.c.  The file identity is in the image:
 * the constructor at 0x0201D7EC passes 0x020A7358 to the debug allocator at
 * 0x02030734 and the bytes there spell "gf_font.c"; 0x0201D9BC and 0x0201DA88
 * name the same string.  This unit stops at 0x0201D6D8 because the two
 * functions after it are an unsolved register allocation, not a missing
 * declaration; see the note at the end of this comment.
 *
 * func_0201D69C sizes a string's storage: two bytes per character plus the
 * terminator, rounded up to a multiple of four.  The rounding is a `while`
 * loop over `n & 3`, not an `& ~3` or a `+ 3 & ~3`: this front end has no
 * immediate `bic`, so either of those would materialise the mask and the
 * function would be four bytes shorter with no loop at all.  The loop really
 * is in the original.
 *
 * func_0201D6C4 is the used-byte count of a wrap-around byte ring.  The
 * fall-through arm of `cmp r1, r2` / `bhs` is the non-wrapped case, so the
 * source wrote `if (head < tail)` first
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md); written as the
 * wrapped case first it is ten of the twenty bytes wrong.
 *
 * Left open at 0x0201D6D8: func_0201D6D8 and func_0201D768 reproduce the
 * right size and the right instruction multiset but allocate registers the
 * other way round.  The original keeps the ring's write cursor in a
 * callee-saved register across the MI_CpuCopy8 call and spills the loop
 * counter; every source shape tried so far (three local layouts, six
 * declaration orders, struct against scalars, one against two assignments of
 * the buffer base) gives the opposite choice and 72 differing bytes, with no
 * variation between them.  The buffer base is assigned twice, once as the
 * object pointer and once with 0x18 added, which is the aggregate-member
 * non-folding of
 * docs/idioms/a-guard-on-a-struct-member-survives-constant-folding.md, but
 * modelling it as an aggregate member does not move the diff either.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201D69C.c \
 *       --addr 0x0201D69C --thumb
 */
u32 func_0201D69C(void *s)
{
    u32 n = (func_020458F8(s) + 1) * 2;

    while ((n & 3) != 0) {
        n++;
    }
    return n;
}








u32 func_0201D6B8(void *s)
{
    return func_0201D69C(s) + 0x20;
}








u32 func_0201D6C4(const struct Ring *p)
{
    if (p->head < p->tail) {
        return p->tail - p->head;
    }
    return p->tail + (p->size - p->head);
}









/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * 144 bytes, 0x0201D6D8..0x0201D768, one function, every concrete byte
 * reproduced (0 differing bytes of 144) -- the diff is empty apart from the
 * three wildcarded call fields.
 *
 * Blocked on the `label` class, and it is a one-address wall: all three
 * unresolved sites at +0x24, +0x32 and +0x44 call func_0201D768, which is the
 * function *immediately after this one* and whose only callers in the whole
 * image are these three.  The compared range ends where 0x0201D768 begins, so
 * shrinking the range is not possible (the callee cannot go in), and the
 * `matched` class needs an EXACT entry covering 0x0201D768 that does not
 * exist yet.  It graduates the day 0x0201D768 is matched -- nothing in this C
 * changes.
 *
 * What it is: the cache-side of a record reader.  It asks
 * func_0201D768(p, func_02045A90(c), (u16)func_0201D69C(c), 2) for a slot
 * keyed by the record at `c`, stores a second slot for `b` (0x1c/0x1c) in a
 * stack local, zero-initialises a 4-byte stack local through a third call,
 * and then walks the list hanging off p->f10 through func_0201D7C4 until it
 * runs out, rebasing the node pointer on p+0x18 and clamping the resulting
 * offset against p->f4 (u16) before a 4-byte memcpy into the local.  When
 * p->f10 is null it installs the two slots instead.
 *
 * Two details that cost a compile each: func_02045A90 is ARM, not Thumb (the
 * the offset is truncated to u16 twice -- once right after the subtraction and
 * once after the +0x1c -- which is the `(u16)(...) + 0x1c` spelling in a u16
 * local, not a single cast.
 *
 * Verified with
 *   python tools/match.py one --src src/pending/func_0201D6D8.c \
 *       --func func_0201D6D8 --addr 0x0201D6D8 --cc 1.1p1 --thumb
 */
void func_0201D6D8(Blk *p, void *b, void *c)
{
    void *e;
    void *q;
    void *t;
    u32 v;
    u32 x;

    x = (u32)func_0201D768((struct Ring *)p, (void *)func_02045A90(c),
                           (u16)func_0201D69C(c), 2);
    e = func_0201D768((struct Ring *)p, b, 0x1c, 0x1c);
    v = 0;
    func_0201D768((struct Ring *)p, (const u8 *)(&v), 4, 4);
    q = p->f10;
    if (q != 0) {
        for (;;) {
            t = func_0201D7C4((struct PrintSys *)p, q);
            if (t == 0) break;
            q = t;
        }
        {
            u16 off = (u16)((u32)q - ((u32)p + 0x18)) + 0x1c;

            if (off >= p->f04) off = 0;
            memcpy(&e, (char *)p + 0x18 + off, 4);
        }
        return;
    }
    p->f10 = e;
    p->f14 = x;
}









/*
 * printsys.c: append `len` bytes to the byte ring at +0x18 in `unit`-sized
 * copies, wrapping the head back to 0 at ring->size, and return the address
 * the first copy landed at.  The three callers are func_0201D6D8's.
 *
 * Rewritten from the start in wave 20 (lane printsys_fresh; 63 bytes out for
 * the inherited source).  What closed it: the head advance is the compound
 * `pos += unit` over a u16 `unit`.  The explicit `pos = (u16)(pos + unit)`
 * gives the loaded head and the advanced head separate webs, the loaded one
 * is cheaper than the counter and is spilled; the compound form keeps both in
 * one live range (r4 in the image), so the counter is the one spilled to
 * [sp,#4].  With a u32 `unit` the compound form truncates `unit` as a loop
 * invariant (100 bytes).  The remaining slot order is the declaration order
 * start, buf, i, pos.
 *
 * note 2026-10-05: removed the redundant first store `buf = ring;` (a
 * stand-in: arm9 game code has no line table to prove it). The single
 * `buf = (u8 *)ring + 0x18;` is EXACT in --lang c99 and --lang c; so is a
 * static inline accessor RingData(ring), so the plain form is kept.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201D768.c \
 *       --func func_0201D768 --addr 0x0201D768 --cc 1.1p1 --thumb
 */
void *func_0201D768(struct Ring *ring, const u8 *src, u16 len, u16 unit)
{
    u16 start;
    u8 *buf;
    u16 i;
    u16 pos;

    i = 0;
    buf = (u8 *)ring + 0x18;
    start = ring->head;
    while (i < len) {
        pos = ring->head;
        MI_CpuCopy8(src, buf + pos, unit);
        pos += unit;
        if (pos >= ring->size) {
            pos = 0;
        }
        ring->head = pos;
        src += unit;
        i += unit;
    }
    return buf + start;
}








/*
 * Steps the printsys.c record ring one slot on and returns the word stored
 * there, which is the next record or NULL.  The ring lives at +0x18 of the
 * object src/matched/unit_0201C450.c builds and its records are 0x1C bytes.
 *
 * Four `lsls #16` / `lsrs #16` pairs for one offset is the tell that the
 * arithmetic went through a `u16`-parameter helper the compiler inlined: the
 * argument is truncated, the parameter is truncated again on entry, the return
 * value is truncated, and the caller truncates it once more before indexing.
 * Reproducing them needs a `u32` local with an explicit `(u16)` written at each
 * of the four points; a `u16` local folds the redundant casts away and the
 * function is ten bytes short.
 *
 * func_0201D6D8 and func_0201D768, the two functions in front of this one, are
 * still open; see the note in src/matched/unit_0201D69C.c, which this work
 * narrows.  func_0201D6D8 is EXACT when it is compiled in a range with
 * func_0201D768, and func_0201D768 is four bytes short: the original spills the
 * byte counter and keeps the ring cursor in r4, and every source shape tried
 * makes the opposite choice.  Since func_0201D768's only callers are the three
 * inside func_0201D6D8 the two cannot be cut apart, so neither lands.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201D7C4.c \
 *       --addr 0x0201D7C4 --thumb
 */
void *func_0201D7C4(struct PrintSys *p, void *q)
{
    u32 off = (u16)((u8 *)q - &p->buf[0]);

    off = (u16)((u16)off + 0x1C);
    if (off >= p->unk04) {
        off = 0;
    }
    return *(void **)&p->buf[(u16)off];
}








/*
 * gf_font.c's constructor: allocates the 0x94-byte font object, opens the
 * resource handle for `a0`, records the archive id at +0x54, then hands the
 * object to func_0201D854 (metrics and buffers) and func_0201DA00 (the format
 * selector).  A null allocation returns straight out, which is why both calls
 * sit inside the one guard.
 *
 * Promoted 2026-09-21 from src/pending/func_0201D7EC.c with no change to the
 * C: both calls now resolve on the `matched` class from
 * src/matched/sub_0201D854.c and src/matched/sub_0201DA00.c, which were
 * MATCH-parked when this file was written.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201D7EC.c \
 *       --func func_0201D7EC --addr 0x0201D7EC --cc 1.1p1 --thumb
 *   EXACT, 80 bytes, 5 relocation sites, all 5 resolved.
 */
struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId)
{
    struct GfFont *font = func_02030734(heapId, 0x94, 0, lbl_020A7358, 0xC0);

    if (font != 0) {
        font->field_50 = func_020490F4(a0, heapId);
        font->field_54 = a1;
        func_0201D854((struct Font_0201CEE0 *)font, a1, a3, heapId);
        func_0201DA00((struct Font_0201DA00 *)((struct Font_0201CEE0 *)font), a2, heapId);
    }
    return font;
}








u32 func_0201D83C(void *ptr)
{
    func_0201DADC((struct Font_0201D9C8 *)ptr);
    func_0201D9C8((struct Font_0201D9C8 *)ptr);
    return func_020307B0(ptr);
}








/*
 * note:     promoted 2026-09-21: the +0x16C ABS32 to 0x0201DC88 is now
 *           attested `matched` by src/matched/sub_0201DC88.c, which closed
 *           this file's last unresolved site.  13 of 13 relocations resolve.
 *
 * gf_font.c's metrics and buffer initialiser, 372 bytes, the largest function
 * in the file and the one func_0201D7EC calls right after the allocation.  It
 * pulls five sections out of the font resource: the 0x14-byte header block at
 * +0x58, the glyph directory at +0x80, either the whole glyph body (preloaded,
 * into a buffer at +0x84) or nothing (streamed), the eight metric bytes at
 * +0x74, and the character map at +0x88.  The hook at +0x6C is set to
 * func_0201DC88 for the streamed case and func_0201DD58 for the preloaded one,
 * and that is the pointer src/matched/unit_0201DC6C.c calls through.  It
 * finishes by priming the fallback advance at +0x70 from the glyph for '?'
 * (0x3F).
 *
 * Three details cost time:
 *
 *   - **`x / 8` and `x % 8` on the same `u8` field get different signedness
 *     treatment.**  The division is a bare `lsrs #3` and the modulo is the
 *     full signed `lsls #29` / `subs` / `rors #29` sequence, in the same
 *     expression, on the same `ldrb`.  Writing the field into a `u32` local
 *     first makes mwcc lower the modulo test to `movs #7` / `tst` and the
 *     function is sixteen bytes short; writing the field expression out twice
 *     keeps the `int` promotion and reproduces both.  An `s32` local does not
 *     compile at all here.
 *   - **248, 266 and 271 are three `__LINE__` arguments and only two pool
 *     words.**  248 is small enough for `movs`; 266 takes a pool word and 271
 *     is that word plus a constant `adds #5`
 *     (docs/idioms/consecutive-line-numbers-are-one-pool-word-and-adds.md).
 *   - **The fallback advance is stored twice.**  `f->unk70 = 0;` then the
 *     result of func_0201DB20 over it; the first store is not dead, because
 *     func_0201DB20 reads the field on the path where no block matches.
 *
 * Every concrete byte is reproduced.  Three relocations stay wildcarded:
 *
 *   - func_020494F4 is an ARM SDK entry point whose only call site in the
 *     image is the one in this function, so the `label` class has nothing
 *     outside the range to point at.  This alone caps the function.
 *   - func_0201DC88 is a 64-byte unlabelled Thumb leaf, the streamed-glyph
 *     hook, and this pool word is its only reference image-wide.  It is not in
 *     any manifest entry: unit_0201DC6C stops at 0x0201DC88.  Matching it
 *     would convert this site to the `matched` class.
 *   - func_0201DD58 resolves on `matched` from src/matched/unit_0201DD58.c and
 *     is listed here only because the pool word sits inside the compared
 *     range.
 *
 * The fields at +0x60, +0x64 and +0x68 are declared `u32` here rather than the
 * `void *` src/matched/unit_0201DC6C.c gives them, because this function does
 * arithmetic on all three; the loads are identical either way.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0201D854.c  *       --func func_0201D854 --addr 0x0201D854 --cc 1.1p1 --thumb
 */
void func_0201D854(struct Font_0201CEE0 *f, int resid, u32 flag, u32 heap)
{
    u32 size;

    if (f->unk50 == 0) {
        return;
    }
    sub_0204944C(f->unk50, resid, 0x18, 0x14, f->unk58);
    func_020494F4(f->unk50, resid, (u32 *)(&f->unk80));
    f->unk72 = (u8)flag;
    if (flag != 0) {
        f->unk84 = 0;
        f->unk6C = (u32)func_0201DD58;
    } else {
        size = f->unk68 - f->unk64;
        f->unk84 = func_02030734(heap, size, 0, func_0201D854_File, 248);
        f->unk6C = (u32)func_0201DC88;
        sub_0204944C(f->unk50, resid, f->unk64, size, f->unk84);
    }
    sub_0204944C(f->unk50, resid, f->unk60, 8, &f->unk74);
    f->unk7E = (u8)(f->unk74 / 8 + ((f->unk74 % 8) ? 1 : 0));
    f->unk7F = (u8)(f->unk75 / 8 + ((f->unk75 % 8) ? 1 : 0));
    f->unk7C = (u16)((f->unk74 * 2) % 8);
    if (f->unk7C == 0) {
        f->unk7C = 8;
    }
    f->unk8C = (void *)(f->unk60 + 8);
    f->unk90 = func_02030734(heap, f->unk76, 0, func_0201D854_File, 266);
    size = func_020493D4(f->unk50, resid) - f->unk68;
    f->unk88 = func_02030734(heap, size, 0, func_0201D854_File, 271);
    sub_0204944C(f->unk50, resid, f->unk68, size, f->unk88);
    f->unk70 = 0;
    f->unk70 = (u16)func_0201DB20((struct Font_0201DB20 *)f, 0x3F);
}










/*
 * gf_font.c's buffer release: frees the three heap blocks the constructor hung
 * off the object at +0x90, +0x84 and +0x88 and closes the resource handle at
 * +0x50, each guarded by its own null check.
 *
 * All three offsets are past the reach of a Thumb `ldr` immediate, so each
 * access costs an `adds rN, #imm` that is an encoding artefact rather than a
 * pointer in the source (docs/idioms/thumb-immediate-reach-costs-an-adds.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201D9C8.c \
 *       --addr 0x0201D9C8 --thumb
 */
void func_0201D9C8(struct Font_0201D9C8 *p)
{
    if (p->unk90 != 0) {
        func_020307B0(p->unk90);
    }
    if (p->unk84 != 0) {
        func_020307B0(p->unk84);
    }
    if (p->unk88 != 0) {
        func_020307B0(p->unk88);
    }
    if (p->unk50 != 0) {
        func_02049238(p->unk50);
    }
}








/*
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 *
 * gf_font.c's format selector: it records the requested glyph format in the
 * object's first word and dispatches on it through a four-entry table of
 * initialisers, handing each the cell width and height the constructor left at
 * +0x7E and +0x7F.  func_0201DADC, src/pending/sub_0201DADC.c, is the matching
 * teardown and dispatches on the same word through the neighbouring table.
 *
 * Every concrete byte is reproduced.  The one unresolved relocation is the
 * table base 0x0209E73C: the pool word inside this function is the only word
 * in the image that holds it, so the `literal` class has no witness left once
 * the compared range is excluded, and no cut helps because the function is
 * twenty bytes of dispatch with nothing to cut away.  It needs a second
 * reference to the table, most likely from an overlay, to move.
 *
 * This is also what keeps func_0201D7EC, src/pending/sub_0201D7EC.c, out of
 * src/matched: its only witness for the call to this function would be having
 * it local in the same unit, and a unit that spans it inherits this same
 * unresolved table word.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0201DA00.c \
 *       --func func_0201DA00 --addr 0x0201DA00 --cc 1.1p1 --thumb
 */
void func_0201DA00(struct Font_0201DA00 *f, u32 fmt, u32 heap)
{
    f->unk00 = fmt;
    g_0209E73C[fmt](f, f->unk7E, f->unk7F, heap);
}








void func_0201DA24(struct Font_0201DA24 *f, u32 a, u32 b, u8 heap)
{
    u32 size;
    u32 p;

    size = func_020493D4(f->unk50, f->unk54) - f->unk8C;
    f->unk0C = func_02030734(heap, size, 0, func_0201DA24_File, 363);
    sub_0204944C(f->unk50, f->unk54, f->unk8C, size, f->unk0C);
    f->unk04 = (u32)func_0201DBBC;
    if (a == 1) {
        p = (u32)func_0201DE40;
        if (b != 1) {
            p = (u32)func_0201E538;
        }
        f->unk08 = p;
    } else {
        p = (u32)func_0201E738;
        if (b != 1) {
            p = (u32)func_0201E928;
        }
        f->unk08 = p;
    }
}









/*
 * gf_font.c's format-1 hook installer: clears +0xC, plants the shared measure
 * hook func_0201DBF4 at +4, and picks one of four glyph decoders for +8 on the
 * 2x2 cross of the two flags (a == 1 selects the first pair, b == 1 the first
 * of each pair).  src/matched/func_0201DE40.c is the (1,1) decoder.
 *
 * Promoted 2026-09-21.  The file was parked at MATCH with the last pool word
 * declared as `func_0201E938`, an address that is NOT a function start: it is
 * the first `bl` inside func_0201E928.  Because the naming convention derives
 * the address from the identifier, the extern was pinned sixteen bytes into
 * the fourth decoder, where nothing can attest it (and, being a `bl`, it was
 * even guessed ARM).  The pool word is 0x0201E929, i.e. thumb func_0201E928;
 * renaming the extern is the whole fix and the concrete bytes never changed.
 * The lesson is that a wildcarded relocation hides a wrong address as
 * effectively as a missing witness does.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201DAA4.c \
 *       --func func_0201DAA4 --addr 0x0201DAA4 --cc 1.1p1 --thumb
 *   EXACT, 56 bytes, 5 relocation sites, all 5 resolved.
 */
void func_0201DAA4(char *p, int a, int b)
{
    ((struct Obj06870 *)p)->fC = 0;
    ((struct Obj06870 *)p)->f4 = (u32)func_0201DBF4;
    if (a == 1)
        ((struct Obj06870 *)p)->f8 = (b == 1) ? (u32)func_0201DE40 : (u32)func_0201E538;
    else
        ((struct Obj06870 *)p)->f8 = (b == 1) ? (u32)func_0201E738 : (u32)func_0201E928;
}









/*
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 *
 * gf_font.c's format teardown, the mirror of func_0201DA00: it dispatches on
 * the format word the selector stored at +0 through a second four-entry table
 * that sits two words after the first one.  Twenty bytes, one indirect call.
 *
 * Every concrete byte is reproduced.  The unresolved relocation is the table
 * base 0x0209E744 and the pool word here is its only witness image-wide, the
 * same dead end as src/pending/sub_0201DA00.c.  Note that the two tables being
 * eight bytes apart is *not* usable as evidence: expressing one as an offset
 * from the other would be a claim that they are one object, and the image does
 * not say so.
 *
 * This is in turn what keeps func_0201D83C, src/pending/sub_0201D83C.c, out of
 * src/matched.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0201DADC.c \
 *       --func func_0201DADC --addr 0x0201DADC --cc 1.1p1 --thumb
 */
void func_0201DADC(struct Font_0201D9C8 *f)
{
    g_0209E744[f->unk00](f);
}








/*
 * gf_font.c's glyph-buffer release, an empty hook, and the entry point every
 * text routine in the region reaches a glyph through.
 *
 * sub_0201DB00 is two bytes, `bx lr`, which is `void f(void) {}`, a hook that
 * was never filled in.  It carries no label because it has no prologue.
 *
 * func_0201DB04 looks up the glyph with func_0201DB20 and dispatches through the
 * function pointer at +4 of the font object.  func_0201DB20 itself, the glyph
 * index lookup at 0x0201DB20, is still open: it reproduces all 154 bytes bar a
 * consistent interchange of r4 with r6, the run cursor against the two binary
 * search bounds, and no declaration order, scope or type tried moves it.  Its
 * one non-obvious detail is worth recording anyway: the base pointer at +0x88
 * has to be spelled `*(struct FontRun **)((u8 *)p + 0x88)` at the top of the
 * function and `p->unk88` at the rebasing site, or the compiler keeps one copy
 * in a register across the loop and spends an extra move; the original
 * rematerialises the address in the cold path instead.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201DAF0.c \
 *       --addr 0x0201DAF0 --thumb
 */
void func_0201DAF0(struct Font_0201DAF0 *p)
{
    func_020307B0(p->unk0C);
    p->unk0C = 0;
}







void sub_0201DB00(struct Font_0201DAF0 *p)
{
}







void func_0201DB04(struct Font_0201DAF0 *p, u16 ch, void *c, void *d)
{
    ((void (*)(struct Font_0201DAF0 *, u32, void *, void *))p->unk04)(
        p, func_0201DB20((struct Font_0201DB20 *)((struct Font_0201CEE0 *)p), ch), c, d);
}







/*
 * gf_font.c's character-to-glyph-index lookup: NitroSystem's character-map
 * search (NNSG2dFontCodeMap: ccodeBegin, ccodeEnd, mappingMethod, reserved,
 * pNext, mapInfo[]) walked Game Freak style.  The chain pointer is stored as
 * an address in the resource file and is rebased from the load address
 * (+0x68) onto the copy (+0x88); +0x70 is the font's default glyph.  Method
 * 0 is a direct run, 1 a table, 2 a binary search over (code, index) pairs.
 *
 * Two details closed it (docs/notes/sub_0201DB20.c.txt has every
 * measurement):
 *
 *   - the rebase re-reads +0x88 as `*(u8 **)((u8 *)f + 0x88)`, so it is not
 *     CSE'd with the first read (wave 15, 139 -> 15 bytes out);
 *   - the chain step goes through a second pointer local `n` and ends in the
 *     copy `m = n;`.  When m's loop-carried definition is an arithmetic
 *     result (`m = rebase(m)`, even `m = m + 4`), mwcc colours m after every
 *     other local whatever the declaration order, and m takes r6.  With the
 *     copy, m, lo and hi colour in declaration order, which is the image's
 *     m r4, lo r5, hi r6 (wave 21 lane F2, 15 -> 0).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201DB20.c \
 *       --func func_0201DB20 --addr 0x0201DB20 --cc 1.1p1 --thumb
 */
u32 func_0201DB20(struct Font_0201DB20 *f, u16 c)
{
    struct CMap *m;
    s32 lo;
    s32 hi;
    struct CMap *n;

    m = (struct CMap *)f->unk88;
    for (;;) {
        if (m->ccodeBegin <= c && m->ccodeEnd >= c) {
            switch (m->mappingMethod) {
            case 0:
                return m->mapInfo[0] + (c - m->ccodeBegin);
            case 1:
                return m->mapInfo[(u16)(c - m->ccodeBegin)];
            case 2: {
                lo = 0;
                hi = m->mapInfo[0] - 1;
                while (lo <= hi) {
                    s32 mid = lo + (hi - lo) / 2;
                    s32 j = 2 * mid + 1;
                    if (m->mapInfo[j] < c)
                        lo = mid + 1;
                    else if (c < m->mapInfo[j])
                        hi = mid - 1;
                    else
                        return m->mapInfo[j + 1];
                }
                break;
            }
            }
            return f->unk70;
        }
        n = m->pNext;
        if (n != 0)
            n = (struct CMap *)(*(u8 * *)&((struct Obj07086 *)f)->f88 + ((u8 *)n - f->unk68));
        else
            return 0;
        m = n;
    }
}







/*
 * gf_font.c's glyph fetch for a preloaded font: copy glyph record i
 * (mapSize bytes) out of the resident body into the scratch buffer, then
 * hand it to func_0201DC44 with the last-tile column count.
 *
 * The lever (wave 16) is `const` on the font parameter, which is only read
 * here.  With a plain pointer the outgoing stack argument `out` was stored
 * third in the final call's setup; with `const struct Font_0201CEE0 *` it is stored
 * last, as in the image (12 bytes out before, every spelling and 3000
 * permuter compiles flat: docs/notes/sub_0201DBBC.c.txt).  Field names
 * follow docs/families/gf_font.h.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201DBBC.c \
 *       --func func_0201DBBC --addr 0x0201DBBC --cc 1.1p1 --thumb
 */
void func_0201DBBC(const struct Font_0201DBBC *f, u32 i, void *d, u8 *out)
{
    MI_CpuCopy8(f->body + i * f->mapSize, f->scratch, f->mapSize);
    func_0201DC44((struct Font_0201DC44 *)((struct Font_0201DBBC *)f), f->scratch, f->lastCols, d, out);
}





/*
 * gf_font.c's glyph fetch for a streamed font: seek the resource handle to
 * the header base plus the glyph directory plus record i, read mapSize bytes
 * into the scratch buffer, then hand it to func_0201DC44 with the last-tile
 * column count.
 *
 * The lever (wave 16) is `const` on the font parameter, exactly as in its
 * sibling src/matched/sub_0201DBBC.c: it moves the outgoing stack argument
 * `out` from third to last in the final call's setup (12 bytes out before,
 * docs/notes/sub_0201DBBC.c.txt).  The listing extent includes the two-byte
 * alignment pad at 0x0201DC42, hence EXACT*.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201DBBC.c \
 *       --func func_0201DBF4 --addr 0x0201DBF4 --cc 1.1p1 --thumb
 */
void func_0201DBF4(const struct Font_0201DBF4 *f, u32 i, void *d, u8 *out)
{
    func_0204960C(f->handle, (u32)f->resHdr + ((u32)f->glyphDir + i * f->mapSize));
    func_020495F4(f->handle, f->mapSize, f->scratch);
    func_0201DC44((struct Font_0201DC44 *)((struct Font_0201DBBC *)((struct Font_0201DBF4 *)f)), f->scratch, f->lastCols, d, out);
}







/*
 * gf_font.c's glyph hand-off: the rendering hook installed at +8 of the font
 * object is called on the glyph bitmap, which starts three bytes into the
 * glyph record, and the record's own three metric bytes plus the byte at +0x59
 * of the font object are copied into the caller's four-byte descriptor.
 *
 * The width is a `u32` parameter and the hook takes it as `u16`, which is what
 * the single `lsls #16` / `lsrs #16` pair before the call is: a `u16`
 * parameter here would make the caller truncate instead and both callers in
 * this packet are two bytes short.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201DC44.c \
 *       --func func_0201DC44 --addr 0x0201DC44 --cc 1.1p1 --thumb
 */
void func_0201DC44(struct Font_0201DC44 *f, const u8 *g, u32 w, void *d, u8 *out)
{
    f->unk08(g + 3, (u16)w, d);
    out[0] = g[0];
    out[1] = g[1];
    out[2] = g[2];
    out[3] = f->unk59;
}






/*
 * The gf_font.c width query and the accessor for the byte at +0x59.
 *
 * func_0201DC6C returns whatever the function pointer at +0x6C returns, and the
 * tail call shape (`ldr r2, [r4, #0x6c]`, `blx r2`, `pop {r4, pc}`) is the same
 * bytes whether the C declares a return value or not, so the return type is
 * fixed by the caller instead: func_0201D528 adds the result to a running width.
 *
 * func_0201DC80 has no label in the listing; it is three halfwords between two
 * literal pools.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201DC6C.c \
 *       --addr 0x0201DC6C --thumb
 */
u32 func_0201DC6C(struct Font_0201DC6C *p, u16 ch)
{
    return ((u32 (*)(struct Font_0201DC6C *, u32))p->unk6C)(p, func_0201DB20((struct Font_0201DB20 *)p, ch));
}




u32 func_0201DC80(struct Font_0201DC6C *p)
{
    return p->unk58[1];
}





/*
 * gf_font.c streamed-glyph lookup: classify glyph `id` through a
 * 2-bit-per-glyph table, fall back to a 9-bit hash, then walk a run of
 * variable-length records for a matching 2-byte code.  See
 * docs/notes/sub_0201DC88.c.txt for the full structural derivation.
 *
 * No relocations: every table is reached through offsets stored in the
 * resource header at obj+0x84.
 *
 * EXACT*, not EXACT: func_0201DD58 immediately after this one is an
 * unlabelled leaf, so the inferred extent runs long (240 vs 208).  Report
 * the unlabelled follower at 0x0201DD58 rather than editing
 * layout/function_starts.txt.
 *
 * The closing lever (2026-09-21): the record header must be read with a
 * fused post-increment, `cnt = *p++;`.  Spelling it as the two statements
 * `cnt = *p; p++;` swaps the cursor and the scan counter between r2 and r3
 * for the whole tail, which is the 17-byte residue the note records.
 */
u8 sub_0201DC88(u8 *obj, u32 id)
{
    struct Hdr0201DC88 *h = *(struct Hdr0201DC88 * *)&((struct Obj11722 *)obj)->f84;
    u32 i = id * 2;
    u8  b = ((u8 *)h + h->bits)[i >> 3];
    u8  k = (u8)((b >> (6 - (i & 7))) & 3);
    u16 slot;
    s8  e;
    u16 n;
    u8 *p;
    u8  cnt;
    u8  idx;

    if (k < 3)
        return ((u8 *)h)[k];

    slot = (u16)(((id & 0x1ff) ^ (u16)(((((id >> 12) ^ (id >> 11)) ^ (id >> 10)) ^ (id >> 9)) & 1) << 3) & 0x1ff);

    e = ((s8 *)((u8 *)h + h->hash))[slot];
    if (e >= 0)
        return (u8)e;

    n = (u16)((u16)(-e) - 1);
    p = (u8 *)h + h->chain;
    while (n != 0) {
        u8 m = *p;
        u16 d = (u16)(n - 1);
        p += m + m * 2 + 1;
        n = d;
    }

    cnt = *p++;
    idx = 0;
    while (idx < cnt) {
        u16 key = (u16)((p[0] << 8) | p[1]);
        if (id == key)
            return p[2];
        idx = (u8)(idx + 1);
        p += 3;
    }
    return obj[0x5e];
}






/*
 * Three unlabelled leaves of gf_font.c: the accessor for the byte at +0x5E and
 * a two-step thunk that resets the text colour to (1, 2, 0).
 *
 * func_0201DD60 and func_0201DD68 are both the pool-word-and-bx shape
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md describes, and neither carries
 * a label, because a tail call saves nothing and the prologue sweep never fires.
 * The chain is real: func_0201DD60 tail-calls func_0201DD68, which tail-calls
 * func_0201DD78 with three constants.  Writing it as one function that calls
 * func_0201DD78 directly loses eight bytes.
 *
 * func_0201DD78 itself, the 4x4x4x4 colour expansion at 0x0201DD78, is still
 * open: the original keeps its two outer loop counters in ip and lr and spills
 * only the third, and no declaration order tried reproduces that split.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201DD58.c \
 *       --addr 0x0201DD58 --thumb
 */
u32 func_0201DD58(struct Font_0201DC6C *p)
{
    return p->unk58[6];
}




void func_0201DD60(void)
{
    func_0201DD68();
}






void func_0201DD68(void)
{
    func_0201DD78(1, 2, 0);
}





/*
 * gf_font.c's text-colour setter, 136 bytes.  It records the three requested
 * palette indices in g_02146578 (the three bytes src/matched/unit_0201DE00.c
 * reads back) and then rebuilds the 256-entry expansion table at 0x02146588: a
 * byte of four 2-bit pixels indexes it and the halfword it yields is the same
 * four pixels widened to a nibble each.  The four nested loops enumerate the
 * four pixels; the local array is { 0, r, g, b }, so pixel value 0 stays 0 and
 * 1..3 map to the three requested indices.
 *
 * Two details cost time:
 *
 *   - **The disjunction is written innermost-term-first.**  Spelled
 *     `c[i] | c[j] << 4 | c[k] << 8 | c[l] << 12` the left-associated prefix
 *     `c[i] | c[j] << 4` is invariant in the two inner loops, mwcc hoists it,
 *     and the function is four bytes short with the partial results living in
 *     `ip` and `lr`.  Written the other way round, `c[l] << 12` leads and no
 *     prefix of the chain is loop-invariant, so only the three shifted terms
 *     are hoisted, one per loop level, which is what the original does.
 *   - **The four loop counters are signed.**  The back edges are `blt`, not
 *     `blo`; `u32` counters cost four wrong bytes and nothing else.
 *
 * The store order in the prologue is also load-bearing: the four array slots
 * are written first, the three global bytes after them, and the flat output
 * index last.  Any other order leaves the `strb`s and the `str`s interleaved
 * differently and up to eighteen bytes differ, with the instruction multiset
 * unchanged.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201DD78.c \
 *       --func func_0201DD78 --addr 0x0201DD78 --cc 1.1p1 --thumb
 */
void func_0201DD78(u32 r, u32 g, u32 b)
{
    u32 c[4];
    s32 i;
    s32 j;
    s32 k;
    s32 l;
    u32 n;

    c[0] = 0;
    c[1] = r;
    c[2] = g;
    c[3] = b;
    g_02146578.colour[0] = (u8)r;
    g_02146578.colour[1] = (u8)g;
    g_02146578.colour[2] = (u8)b;
    n = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 4; k++) {
                for (l = 0; l < 4; l++) {
                    g_02146588[n] = (u16)((c[l] << 12) | (c[k] << 8) |
                                          (c[j] << 4) | c[i]);
                    n++;
                }
            }
        }
    }
}





/*
 * The current text colour, read back and compared.  g_02146578 is the three
 * bytes func_0201DD78 stores the last requested colour into.
 *
 * func_0201DE18 returns 1 when the colour differs, and its shape is the
 * disjunction form rather than the conjunction: the first two comparisons branch
 * to one shared `movs r0, #1` block and only the last one branches past it,
 * which is what `if (r != c[0] || g != c[1] || b != c[2]) return 1;` gives.
 * Written as `if (all equal) return 0; return 1;` the arms swap and ten of the
 * forty bytes are wrong
 * (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201DE00.c \
 *       --addr 0x0201DE00 --thumb
 */
void func_0201DE00(u8 *r, u8 *g, u8 *b)
{
    *r = g_02146578.colour[0];
    *g = g_02146578.colour[1];
    *b = g_02146578.colour[2];
}





u32 func_0201DE18(u32 r, u32 g, u32 b)
{
    if (r != g_02146578.colour[0] || g != g_02146578.colour[1] || b != g_02146578.colour[2]) {
        return 1;
    }
    return 0;
}




static inline u8 read_bits(struct BitReader *r, u8 n)
{
    u8  hi;
    u32 lo;
    u8  cur;
    u32 used;

    if (r->avail < n) {
        hi = r->cur;
        hi &= g_0209E74C[r->avail];
        used = r->avail;
        n = (u8)(n - (u8)used);
        r->src++;
        r->cur = *r->src;
        r->avail = 8;
    } else {
        hi = 0;
        used = 0;
    }

    cur = r->cur;
    lo = g_0209E74C[n] & cur;
    r->avail = r->avail - n;
    if (r->avail == 0) {
        r->src++;
        r->cur = *r->src;
        r->avail = 8;
    } else {
        r->cur = (u8)(cur << n);
    }
    return (u8)((lo >> used) | hi);
}



/*
 * gf_font.c's format-1 glyph decoder, one of the four hooks func_0201DAA4
 * installs at f->unk08 (src/pending/sub_0201DAA4.c): the one for format 1
 * with b == 1.
 *
 * Sixteen 4-pixel groups of a compressed 2bpp 8x8 glyph.  Every even group is
 * a whole literal byte (read_bits of 8 bits) and every odd one is `n` bits
 * wide; each group's byte then indexes the 256-entry 2bpp->4bpp expansion
 * table at 0x02146588 that func_0201DD78 rebuilds (src/matched/sub_0201DD78.c),
 * so the sixteen halfwords written to dst are the glyph in 4bpp.  `n` is the
 * caller's bit depth and is a runtime value, which is why the even and odd
 * reads are the same inlined reader with a constant and a variable count.
 *
 * The reader is the source of sub_0201E4D4 (src/matched/sub_0201E4D4.c), the
 * out-of-line copy of it that sits just past this function, inlined here
 * sixteen times; `static inline` is load-bearing, plain `static` compiles to
 * sixteen `bl`s and 260 bytes.  Its state is the second half of the global at
 * 0x02146578, whose first three bytes are the text colour func_0201DD78
 * stores and src/matched/unit_0201DE00.c reads back; that is why the inlined
 * field accesses sit at +4/+8/+12 rather than at +0/+4/+8 as they do in the
 * out-of-line call.
 *
 * What cost the last eight bytes: the outer parameter must be `u32 n`, not
 * `u8 n`.  With a u8 parameter mwcc treats the register as an already
 * zero-extended byte, so the inlined expansions compare `r->avail` against
 * the raw argument and keep `n` alive in two registers; the original
 * re-materialises `(u8)n` once per expansion, before the `avail < n`
 * comparison, which is what a conversion from a wider argument gives you.
 * Every block is the same length either way, so the whole difference is one
 * register choice and a pool 8 bytes further along.
 *
 * Extent note: the listing's 1672 bytes for this function run to 0x0201E4C8,
 * eight bytes past the last code byte (0x0201E4BE) - the two-word literal
 * pool at 0x0201E4C0 (g_0209E74C, g_02146588) is this function's own.  It is
 * inside this packet, not the neighbouring 0x0201E000..0x0202E000 lane; the
 * next function starts at 0x0201E4C8.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201DE40.c \
 *       --func func_0201DE40 --addr 0x0201DE40 --cc 1.1p1 --thumb
 *   EXACT, 1672 bytes, 5 relocation sites, all 5 resolved.
 */
void func_0201DE40(const u8 *src, u32 n, u16 *dst)
{
    g_02146578.br.src = src;
    g_02146578.br.cur = *src;
    g_02146578.br.avail = 8;

    dst[0] = g_02146588[read_bits(&g_02146578.br, 8)];
    dst[1] = g_02146588[read_bits(&g_02146578.br, n)];
    dst[2] = g_02146588[read_bits(&g_02146578.br, 8)];
    dst[3] = g_02146588[read_bits(&g_02146578.br, n)];
    dst[4] = g_02146588[read_bits(&g_02146578.br, 8)];
    dst[5] = g_02146588[read_bits(&g_02146578.br, n)];
    dst[6] = g_02146588[read_bits(&g_02146578.br, 8)];
    dst[7] = g_02146588[read_bits(&g_02146578.br, n)];
    dst[8] = g_02146588[read_bits(&g_02146578.br, 8)];
    dst[9] = g_02146588[read_bits(&g_02146578.br, n)];
    dst[10] = g_02146588[read_bits(&g_02146578.br, 8)];
    dst[11] = g_02146588[read_bits(&g_02146578.br, n)];
    dst[12] = g_02146588[read_bits(&g_02146578.br, 8)];
    dst[13] = g_02146588[read_bits(&g_02146578.br, n)];
    dst[14] = g_02146588[read_bits(&g_02146578.br, 8)];
    dst[15] = g_02146588[read_bits(&g_02146578.br, n)];
}





/*
 * Opens the bit reader the glyph decompressor in this packet runs on: the
 * cursor at +0 is the byte pointer, +4 is the number of bits still unread out
 * of the byte cached at +8, and the first byte is latched on the spot.
 *
 * Twelve bytes, no prologue: the function saves nothing, so disasm.py's
 * prologue sweep never labels it and it prints as part of the `.word` run in
 * front of func_0201E4D4
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * The bit count is assigned last.  Written before the cached byte the two
 * stores swap and the constant 8 is materialised earlier, four bytes wrong.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201E4C8.c \
 *       --func func_0201E4C8 --addr 0x0201E4C8 --cc 1.1p1 --thumb
 */
void func_0201E4C8(struct BitReader *b, const u8 *p)
{
    b->src = p;
    b->cur = p[0];
    b->avail = 8;
}




/*
 * The bit reader behind the compressed glyph stream: pulls `n` bits out of a
 * byte stream, most significant bit first.  The state is three fields, the
 * read pointer at +0, the number of bits still unconsumed in the byte at +4,
 * and that byte itself at +8; g_0209E74C is the 0..8 entry table of top-bit
 * masks.  When the request straddles a byte boundary the leading bits are
 * taken first, the next byte is fetched, and the two halves are OR'd back
 * together.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201E4D4.c
 *       --func sub_0201E4D4 --addr 0x0201E4D4 --cc 1.1p1 --thumb
 */
u8 sub_0201E4D4(struct BitReader *r, u8 n)
{
    u8  hi;
    u32 lo;
    u8  cur;
    u32 used;

    if (r->avail < n) {
        hi = r->cur;
        hi &= g_0209E74C[r->avail];
        used = r->avail;
        n = (u8)(n - (u8)used);
        r->src++;
        r->cur = *r->src;
        r->avail = 8;
    } else {
        hi = 0;
        used = 0;
    }

    cur = r->cur;
    lo = g_0209E74C[n] & cur;
    r->avail = r->avail - n;
    if (r->avail == 0) {
        r->src++;
        r->cur = *r->src;
        r->avail = 8;
    } else {
        r->cur = (u8)(cur << n);
    }
    return (u8)((lo >> used) | hi);
}






/*
 * One of the four compressed-glyph decoders src/matched/func_0201DAA4.c and
 * src/matched/sub_0201DA24.c install at the font object's +8.  All four read
 * the same 2bpp bit stream through the shared reader (src/matched/sub_0201E4C8.c
 * opens it, src/matched/sub_0201E4D4.c pulls bits) and expand every byte
 * through the 256-entry table src/matched/sub_0201DD78.c rebuilds, so the
 * halfwords written to dst are the glyph in 4bpp.  They differ only in how
 * many halfwords they write and in what shape.
 *
 * `n` is the caller's bit depth and is a runtime value: every second (or third)
 * group is read at that variable width while the rest are whole literal bytes,
 * which is why the argument alternates between `movs r1, #8` and the
 * `lsls`/`lsrs #24` re-materialisation of `(u8)n`.  The parameter must stay
 * `u32`; a `u8` parameter lets mwcc treat the register as already narrowed,
 * drops the per-call re-materialisation and the function comes out short.
 *
 * Unlike src/matched/func_0201DE40.c, which is the same reader inlined sixteen
 * times against the state's inline fields, these three call it out of line, so
 * the state address is a plain pool word reloaded before every call and the
 * body is a flat run of calls with no loop.
 *
 * Thirty-two halfwords, one flat 8x8-at-4bpp glyph in address order, with the
 * widths alternating 8, n, 8, n, ...  The simplest of the four: one cursor,
 * dst[0] through dst[31] in order.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201E538.c \
 *       --func func_0201E538 --addr 0x0201E538 --cc 1.1p1 --thumb
 *   EXACT, 512 bytes, 35 relocation sites, all 35 resolved.
 */
void func_0201E538(const u8 *src, u32 n, u16 *dst)
{
    func_0201E4C8(&g_02146578.br, src);
    dst[0] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[1] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[2] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[3] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[4] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[5] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[6] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[7] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[8] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[9] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[10] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[11] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[12] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[13] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[14] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[15] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[16] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[17] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[18] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[19] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[20] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[21] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[22] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[23] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[24] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[25] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[26] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[27] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[28] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[29] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[30] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[31] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
}






/*
 * One of the four compressed-glyph decoders src/matched/func_0201DAA4.c and
 * src/matched/sub_0201DA24.c install at the font object's +8.  All four read
 * the same 2bpp bit stream through the shared reader (src/matched/sub_0201E4C8.c
 * opens it, src/matched/sub_0201E4D4.c pulls bits) and expand every byte
 * through the 256-entry table src/matched/sub_0201DD78.c rebuilds, so the
 * halfwords written to dst are the glyph in 4bpp.  They differ only in how
 * many halfwords they write and in what shape.
 *
 * `n` is the caller's bit depth and is a runtime value: every second (or third)
 * group is read at that variable width while the rest are whole literal bytes,
 * which is why the argument alternates between `movs r1, #8` and the
 * `lsls`/`lsrs #24` re-materialisation of `(u8)n`.  The parameter must stay
 * `u32`; a `u8` parameter lets mwcc treat the register as already narrowed,
 * drops the per-call re-materialisation and the function comes out short.
 *
 * Unlike src/matched/func_0201DE40.c, which is the same reader inlined sixteen
 * times against the state's inline fields, these three call it out of line, so
 * the state address is a plain pool word reloaded before every call and the
 * body is a flat run of calls with no loop.
 *
 * Thirty-two halfwords in TWO interleaved cursors, `dst` and `dst2 = dst + 16`,
 * written four at a time: dst[2i], dst[2i+1], dst2[2i], dst2[2i+1], with widths
 * 8, 8, 8, n.  The second cursor is what puts dst+0x20 in r7 for the whole
 * body; written as dst[16 + k] instead the compiler recomputes the base from
 * dst at every far store and the function is longer.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201E738.c \
 *       --func func_0201E738 --addr 0x0201E738 --cc 1.1p1 --thumb
 *   EXACT, 496 bytes, 35 relocation sites, all 35 resolved.
 */
void func_0201E738(const u8 *src, u32 n, u16 *dst)
{
    u16 *dst2 = dst + 16;

    func_0201E4C8(&g_02146578.br, src);
    dst[0] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[1] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[0] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[1] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[2] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[3] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[2] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[3] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[4] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[5] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[4] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[5] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[6] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[7] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[6] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[7] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[8] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[9] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[8] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[9] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[10] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[11] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[10] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[11] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[12] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[13] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[12] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[13] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[14] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[15] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[14] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[15] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
}





/*
 * One of the four compressed-glyph decoders src/matched/func_0201DAA4.c and
 * src/matched/sub_0201DA24.c install at the font object's +8.  All four read
 * the same 2bpp bit stream through the shared reader (src/matched/sub_0201E4C8.c
 * opens it, src/matched/sub_0201E4D4.c pulls bits) and expand every byte
 * through the 256-entry table src/matched/sub_0201DD78.c rebuilds, so the
 * halfwords written to dst are the glyph in 4bpp.  They differ only in how
 * many halfwords they write and in what shape.
 *
 * `n` is the caller's bit depth and is a runtime value: every second (or third)
 * group is read at that variable width while the rest are whole literal bytes,
 * which is why the argument alternates between `movs r1, #8` and the
 * `lsls`/`lsrs #24` re-materialisation of `(u8)n`.  The parameter must stay
 * `u32`; a `u8` parameter lets mwcc treat the register as already narrowed,
 * drops the per-call re-materialisation and the function comes out short.
 *
 * Unlike src/matched/func_0201DE40.c, which is the same reader inlined sixteen
 * times against the state's inline fields, these three call it out of line, so
 * the state address is a plain pool word reloaded before every call and the
 * body is a flat run of calls with no loop.
 *
 * Forty-eight halfwords across FOUR 8x8 tiles, the widest of the four decoders.
 * The tiles are written three halfwords at a time, dst[k], dst[k+1], dst2[k],
 * with widths 8, 8, n, where `dst2 = dst + 16` is the tile below.
 *
 * WHICH INDEX GOES THROUGH WHICH CURSOR IS LOAD-BEARING, and it is what cost
 * the time here.  The second tile pair lives at halfword 32..63, and its low
 * tile (32..47) must be written as `dst[32..47]`, i.e. through the FIRST
 * cursor, while its high tile (48..63) goes through `dst2[32..47]`.  Routing
 * the whole second pair through `dst2` (dst2[16..47], which is the same
 * address arithmetic) lets mwcc keep one base live across both blocks: sixty
 * bytes short, 413 bytes out, and a clean r5/r6/r7 rotation in the permuter's
 * --explain map.  Splitting them back restores the original's recomputed
 * `adds r0, r5, #0 / adds r0, #0x40 / strh` at every far store, which is the
 * shape the image actually has.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201E928.c \
 *       --func func_0201E928 --addr 0x0201E928 --cc 1.1p1 --thumb
 *   EXACT, 828 bytes, 51 relocation sites, all 51 resolved.
 */
void func_0201E928(const u8 *src, u32 n, u16 *dst)
{
    u16 *dst2 = dst + 16;

    func_0201E4C8(&g_02146578.br, src);
    dst[0] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[1] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[0] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[2] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[3] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[2] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[4] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[5] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[4] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[6] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[7] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[6] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[8] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[9] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[8] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[10] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[11] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[10] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[12] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[13] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[12] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[14] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[15] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[14] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[32] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[33] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[32] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[34] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[35] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[34] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[36] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[37] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[36] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[38] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[39] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[38] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[40] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[41] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[40] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[42] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[43] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[42] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[44] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[45] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[44] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[46] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[47] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[46] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
}




/*
 * The first function of wordset.c.  The file identity is in the image: the
 * constructor at 0x0201EC74, immediately after this, passes 0x020A7364 to the
 * debug allocator at 0x02030734, and the bytes there spell "wordset.c".  The
 * string before it is "gf_font.c", whose terminator at 0x020A7360 plus three
 * bytes of padding fixes 0x020A7364 by construction, so the `string` class
 * carries the address; see src/matched/unit_0201ED04.c for the rest of the
 * file and the near miss at 0x0201EC74 that keeps this function on its own.
 *
 * Sixteen bytes: a pool-word-and-bx tail call
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md) that fills in the default
 * entry count 8 and the default per-entry string size 0x20.  It cannot be one
 * unit with 0x0201EC74 because that function is 14 bytes of prologue
 * scheduling away from EXACT and csrc.py refuses anything less.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201EC64.c \
 *       --addr 0x0201EC64 --thumb
 */
struct WordSet *func_0201EC64(u16 heap)
{
    return func_0201EC74(8, 0x20, heap);
}





/*
 * wordset.c's constructor, the function src/matched/unit_0201EC64.c tail
 * calls with the default counts (8 slots, 0x20 bytes of string each).  It
 * allocates a 0x10-byte header and an array of `n` 0xc-byte Entry records
 * through the debug allocator func_02030734(heap, size, flag, file, line),
 * gives the header and every entry a string object from func_020457B0, and
 * returns 0 as soon as any allocation fails.
 *
 * The `__FILE__` argument is 0x020A7364, "wordset.c", and IS attestable by
 * the `string` class: the six bytes before it are the NUL terminator of
 * "gf_font.c" plus padding, so the run start is fixed from outside this
 * range (unlike the tables of
 * docs/idioms/a-string-after-a-data-table-has-no-witness.md).
 *
 * TWO LEVERS, both of which the earlier pass in docs/notes/pkt_0201EC74.c.txt
 * missed and which together took the function from 152 bytes / 65 differing
 * rows to EXACT:
 *
 *  - **The failure path is a `goto fail;` chain with ONE `return 0;` at the
 *    end.**  Every failure return in the image lands on the single epilogue
 *    at 0x0201ECFA.  Written as four separate `return 0;` statements the
 *    compiler materialises the epilogue inline at the FIRST failure site and
 *    branches over the copy, which is eight bytes too long and reshuffles
 *    the two callee-saved slots (the pool word lands in r7 and the parameter
 *    copy of `n` in r5, the opposite of the image).  This is the explicit
 *    `goto` case of
 *    docs/idioms/guards-separated-by-statements-share-an-exit-only-through-goto.md:
 *    statements sit between the guards, so nothing else reproduces the
 *    shared exit.  That alone brings the compile to 144 bytes and 14
 *    differing bytes.
 *
 *  - **`heap` is `u8`, not `u32`.**  With `u32` the prologue schedules the
 *    three argument spills and the pool load in a different order
 *    (`ldr r5,[pc]` ahead of `adds r7,r0,#0`, and `str r1,[sp,#4]` ahead of
 *    `str r2,[sp,#8]`), fourteen bytes across the prologue and the first
 *    store pair.  Narrowing the parameter changes nothing about the code
 *    that runs -- the value is spilled to sp+8 untruncated and read back as
 *    a word for `p->heap = heap` -- but it changes the order mwccarm's value
 *    numbering creates the three incoming values in, which is what the
 *    prologue schedule follows.  This is the family's heap-id width seen
 *    once more: func_0201F344 in src/matched/unit_0201F31C.c takes its heap
 *    as u16 for the same class of reason.
 *
 *    Found by tools/permuter.py (--mode hill --budget 800 --jobs 8 --types),
 *    which reported `type:p(heap:u32->u8)` at compile 244 of 800:
 *      baseline  DIFF   asm=855  bytes-out=14  size=144/144
 *      244       EXACT  asm=0    bytes-out=0   size=144/144
 *
 * func_020457B0 is ARM, not Thumb.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table; the two counts are the caller's, not content constants.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201EC74.c \
 *       --func func_0201EC74 --addr 0x0201EC74 --cc 1.1p1 --thumb
 */
struct WordSet *func_0201EC74(u32 n, u32 size, u16 heap)
{
    struct WordSet *p;
    u32 i = 0;

    p = func_02030734(heap, 0x10, 0, sFile_020A7364, 0x9F);
    if (p == 0) {
        goto fail;
    }
    p->count = n;
    p->heap = heap;
    p->buf = func_020457B0(size, heap);
    if (p->buf == 0) {
        goto fail;
    }
    p->entries = func_02030734(heap, n * 0xc, i, sFile_020A7364, 0xA8);
    if (p->entries == 0) {
        goto fail;
    }
    while (i < n) {
        func_0201ED50(&p->entries[i].tag);
        p->entries[i].str = func_020457B0(size, heap);
        if (p->entries[i].str == 0) {
            break;
        }
        i++;
    }
    if (i != n) {
        goto fail;
    }
    return p;
fail:
    return 0;
}






/*
 * A whole translation unit, matched as one byte range.
 *
 *           func_0201EDD0, func_0201EE0C, func_0201EE60, func_0201EE84,
 *           func_0201EEA4, func_0201EEC4, func_0201EED4, func_0201EEF4,
 *           func_0201EF14, func_0201EF34, func_0201EF40, func_0201EF4C,
 *           func_0201EF5C, func_0201EF6C, func_0201EF8C, func_0201EF98,
 *           func_0201EFA4, func_0201EFC8
 *
 * 760 bytes, 0x0201ED04..0x0201EFFC, 22 functions, the body of wordset.c.
 * The file name is attested at the constructor 0x0201EC74, which is just
 * before this range and is a near miss; see src/matched/unit_0201EC64.c.
 *
 * The object is a small table of substitution slots:
 *
 *     struct WordSet { u32 count; u32 heap; struct Entry *entries;
 *                      void *buf; };
 *     struct Entry   { struct Tag tag; void *str; };     // 12 bytes
 *
 * and every setter in the file ends the same way, by handing a rendered
 * string to func_0201ED84, which copies the caller's five-byte Tag into the
 * slot (or clears it when the caller passes NULL) and then copies the string
 * itself.  The five-byte tag is not a scalar: the byte at +3 is two
 * bitfields, a seven-bit value and a one-bit flag, which is what the
 * `ldrb`/`bics #0x7F`/`orrs` and `ldrb`/`bics #0x80`/`lsls #0x1F` pairs in
 * func_0201EE0C are.  Writing that byte as a plain u8 with masks costs a pool
 * word and an `ands` for each of the two fields
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md is the same
 * effect on the reading side).
 *
 * func_0201ED50 is the tag clear and takes a `struct Tag *`, not a
 * `struct Entry *`: func_0201EE0C calls it on a bare stack local, which is
 * what fixes the parameter type.  The two are the same address for an entry,
 * so the distinction is only visible at that one call site.
 *
 * func_0201EE60 reaches a file-scope pointer at 0x020A7370.  Exactly two
 * literal pools in the image hold that address, this function's and
 * func_0201F344's in src/matched/unit_0201F0F8.c, so each file is the other's
 * `literal` witness and the two may not be merged into one range.
 *
 * func_0201EF6C is three separate early returns rather than one conjunction:
 * each `bl` is followed by its own `pop`, which is the shape
 * docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md
 * records for a chain the compiler does not tail-merge.
 *
 * Addresses are Black-image addresses.  func_02017E1C and func_02017E88 are
 * the pair of species-keyed getters this file reads names through; they are
 * not resolved here and nothing in this range reads a version flag or an
 * exclusive-species table directly, but any renaming of those two should be
 * checked against Pokemon White.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201ED04.c  *       --addr 0x0201ED04 --thumb
 */
u32 func_0201ED04(struct WordSet *p)
{
    u32 i;

    if (p->entries != 0) {
        for (i = 0; i < p->count; i++) {
            if (p->entries[i].str == 0) {
                break;
            }
            func_02045808(p->entries[i].str);
        }
        func_020307B0(p->entries);
    }
    if (p->buf != 0) {
        func_02045808(p->buf);
    }
    p->count = 0;
    return func_020307B0(p);
}




void func_0201ED50(struct Tag *t)
{
    MI_CpuFill8(t, 0, 5);
    t->unk04 = 0;
}




void func_0201ED64(struct WordSet *p, u32 i)
{
    func_0201ED50(&p->entries[i].tag);
    func_0204581C(p->entries[i].str);
}




void func_0201ED84(struct WordSet *p, u32 i, const void *src,
                   const struct Tag *tag)
{
    if (i < p->count) {
        if (tag != 0) {
            p->entries[i].tag = *tag;
        } else {
            func_0201ED50(&p->entries[i].tag);
        }
        func_02045838(p->entries[i].str, (struct U16Vec *)src);
    }
}




void func_0201EDD0(struct WordSet *p, u32 i, u32 id, u32 v)
{
    void *s = func_02045B38(0, 2, (u16)id, (u16)p->heap);

    if (s != 0) {
        func_02045CAC(s, v, p->buf);
        func_0201ED84(p, i, p->buf, 0);
        func_02045C04(s);
    }
}




void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c)
{
    struct Tag tag;

    func_0201ED50(&tag);
    tag.unk03 = n;
    tag.unk03b = (f == 0);
    func_0201ED84(p, i, src, &tag);
}




void func_0201EE60(struct WordSet *p, u32 i, u16 v)
{
    func_02045CAC(unk_020A7370, v, p->buf);
    func_0201ED84(p, i, p->buf, 0);
}




void func_0201EE84(struct WordSet *p, u32 i, void *mon)
{
    func_0201EE60(p, i, func_02017E1C(mon, 5, 0));
}




void func_0201EEA4(struct WordSet *p, u32 i, void *mon)
{
    func_0201EE60(p, i, func_02017E88(mon, 5, 0));
}




void func_0201EEC4(struct WordSet *p, u32 i, u32 v)
{
    func_0201EDD0(p, i, 0x119, v);
}




void func_0201EED4(struct WordSet *p, u32 i, void *mon)
{
    func_0201EEC4(p, i, (u16)func_02017E1C(mon, 5, 0));
}




void func_0201EEF4(struct WordSet *p, u32 i, void *mon)
{
    func_02017E1C(mon, 0x73, (u32)p->buf);
    func_0201ED84(p, i, p->buf, 0);
}




void func_0201EF14(struct WordSet *p, u32 i, void *mon)
{
    func_02017E88(mon, 0x73, (u32)p->buf);
    func_0201ED84(p, i, p->buf, 0);
}




void func_0201EF34(struct WordSet *p, u32 i, u32 v)
{
    func_0201EDD0(p, i, 0xCB, v);
}




void func_0201EF40(struct WordSet *p, u32 i, u32 v)
{
    func_0201EDD0(p, i, 0x36, v);
}




void func_0201EF4C(struct WordSet *p, u32 i, u32 v)
{
    func_0201EDD0(p, i, 0x117, v);
}




void func_0201EF5C(struct WordSet *p, u32 i, u32 v)
{
    func_0201EDD0(p, i, 0x118, v);
}




void func_0201EF6C(struct WordSet *p, u32 i, u32 v, u32 a, u32 b)
{
    if (a != 0) {
        func_0201EF5C(p, i, v);
        return;
    }
    if (b != 0) {
        func_0201EF4C(p, i, v);
        return;
    }
    func_0201EF40(p, i, v);
}




void func_0201EF8C(struct WordSet *p, u32 i, u32 v)
{
    func_0201EDD0(p, i, 0xB6, v);
}




void func_0201EF98(struct WordSet *p, u32 i, u32 v)
{
    func_0201EDD0(p, i, 0x18, v);
}




void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d)
{
    func_0201F35C(p->buf, a, b, c, d);
    func_0201ED84(p, i, p->buf, 0);
}




void func_0201EFC8(struct WordSet *p, u32 i, u32 v)
{
    u16 x = v;

    func_020246C8(&x, 0, 0);
    func_02024838((u16)x, p->buf, (u16)p->heap);
    func_0201ED84(p, i, p->buf, 0);
}





/*
 * Promoted from src/pending/sub_0201EFFC.c: every concrete byte was
 * already reproduced, and the one relocation, the call to
 * func_0202473C, was capped at MATCH because the only branch to that
 * address anywhere in the image is the one inside this function. Now
 * that src/matched/sub_0202473C.c is an EXACT entry, the `matched` class
 * attests the call without needing a second caller (docs/MATCHING.md,
 * "the matched class"), and this file closes to EXACT.
 *
 * The last function of wordset.c's body: it normalises a value through
 * func_0202473C and stores the result into the one-byte flag of the
 * slot's tag. The value is passed by address, so it lives on the stack
 * and is read back after the call; the `str r2, [sp]` before the call and
 * the `ldr r2, [sp]` after it are that, not a spill.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201EFFC.c \
 *       --func func_0201EFFC --addr 0x0201EFFC --cc 1.1p1 --thumb
 */
void func_0201EFFC(struct WordSet *p, u32 i, u32 v)
{
    u32 x = v;

    func_0202473C(&x, 0);
    if (i < p->count) {
        p->entries[i].tag.unk04 = x;
    }
}





/*
 * Three of the wordset.c setters, cut off at 0x0201F094 because the function
 * there is the only caller of 0x02025B94 anywhere in the image and so cannot
 * be attested; see src/pending/sub_0201F094.c.  The rest of the run continues
 * in src/matched/unit_0201F0F8.c.
 *
 * func_0201F048 renders message 0xE7 with an argument and falls back to
 * clearing the slot when the argument is out of the message's own range; the
 * `bhs` is the unsigned compare against func_02045F50's result, and the
 * fall-through arm is the in-range one
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * The call to func_0201ED64 is carried by the `matched` class: its only six
 * callers in the image are all inside this packet, so no cut reaches it, but
 * src/matched/unit_0201ED04.c is an EXACT entry covering that address.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201F020.c  *       --addr 0x0201F020 --thumb
 */
void func_0201F020(struct WordSet *p, u32 i, u32 v)
{
    func_0201EDD0(p, i, 0xC7, v);
}




void func_0201F02C(struct WordSet *p, u32 i, void *a)
{
    sub_02008500(a, p->buf);
    func_0201ED84(p, i, p->buf, 0);
}




void func_0201F048(struct WordSet *p, u32 i, u32 n)
{
    void *s = func_02045B38(0, 2, (u16)0xE7, (u16)p->heap);

    if (s != 0) {
        if (n < func_02045F50(s)) {
            func_02045CAC(s, n, p->buf);
            func_0201ED84(p, i, p->buf, 0);
        } else {
            func_0201ED64(p, i);
        }
        func_02045C04(s);
    }
}





/*
 * Promoted from src/pending/sub_0201F094.c: every concrete byte was
 * already reproduced, and the one relocation, the call to
 * func_02025B94, was capped at MATCH because the only branch to that
 * address anywhere in the image is the one inside this function. Now
 * that src/matched/sub_02025B94.c is an EXACT entry, the `matched` class
 * attests the call without needing a second caller, and this file closes
 * to EXACT.
 *
 * A wordset.c setter that maps a caller value to a message id through
 * func_02025B94 and renders it. That is why the wordset.c setter run is
 * committed as src/matched/unit_0201F020.c and
 * src/matched/unit_0201F0F8.c with this function left out between them;
 * it can now be folded back in on a future pass.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201F094.c \
 *       --func func_0201F094 --addr 0x0201F094 --cc 1.1p1 --thumb
 */
void func_0201F094(struct WordSet *p, u32 i, u32 a, u32 n)
{
    u32 id = func_02025B94(a);
    void *s;

    if (id != 0 && n != 0) {
        s = func_02045B38(0, 2, (u16)id, (u16)p->heap);
        if (s != 0) {
            if (n < func_02045F50(s)) {
                func_02045CAC(s, n, p->buf);
                func_0201ED84(p, i, p->buf, 0);
                func_02045C04(s);
                return;
            }
            func_02045C04(s);
        }
    }
    func_0201ED64(p, i);
}





/*
 *           func_0201F140, func_0201F14C, func_0201F158, func_0201F164,
 *           func_0201F184, func_0201F198, func_0201F1B0, func_0201F1C8,
 *           func_0201F1E0, func_0201F230
 *
 * The second half of the wordset.c setter run, 0x0201F0F8..0x0201F250.
 * Every one of these is the same shape: clamp or range-check the caller's
 * value, then render one message id through func_0201EDD0.  The constants are
 * message ids and the ones above 255 (0x116, 0x11B, 0x1CD) arrive from the
 * function's own literal pool because Thumb's `movs` immediate stops at 255;
 * they are plain numbers, not relocations, which is the negative case of
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.
 *
 * func_0201F184 clamps with a signed `blt`, so its value parameter is `s32`
 * while every other clamp in the file is an unsigned `bls`/`bhi`.
 *
 * func_0201F1E0 clears the slot unconditionally before the range check and
 * only overwrites it when the id is in range, so a caller with an
 * out-of-range id leaks the rendered string; that is what the bytes say and
 * it is reproduced here rather than tidied.
 *
 * The calls to func_0201ED64 are carried by the `matched` class through
 * src/matched/unit_0201ED04.c; all six of its callers are inside this packet.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201F0F8.c  *       --addr 0x0201F0F8 --thumb
 */
void func_0201F0F8(struct WordSet *p, u32 i, u32 v)
{
    func_0201EDD0(p, i, 0xBF, v);
}




void func_0201F104(struct WordSet *p, u32 i, u32 a)
{
    func_0201F0F8(p, i, (u8)func_0202A230((void *)a, 1));
}




void func_0201F124(struct WordSet *p, u32 i, u32 v)
{
    func_0201EDD0(p, i, 0x11B, v);
}




void func_0201F134(struct WordSet *p, u32 i, u32 v)
{
    func_0201EDD0(p, i, 0xBE, v);
}




void func_0201F140(struct WordSet *p, u32 i, u32 v)
{
    func_0201EDD0(p, i, 0xB4, v);
}




void func_0201F14C(struct WordSet *p, u32 i, u32 v)
{
    func_0201EDD0(p, i, 0x37, v);
}




void func_0201F158(struct WordSet *p, u32 i, u32 v)
{
    func_0201EDD0(p, i, 0x59, v);
}




void func_0201F164(struct WordSet *p, u32 i, u32 a, u32 b)
{
    func_0200785C((void *)a, b, p->buf);
    func_0201ED84(p, i, p->buf, 0);
}




void func_0201F184(struct WordSet *p, u32 i, s32_0201F0F8 v)
{
    if (v >= 0x30) {
        v = 0;
    }
    func_0201EDD0(p, i, 0xA0, v);
}




void func_0201F198(struct WordSet *p, u32 i, u32 v)
{
    if (v > 8) {
        func_0201ED64(p, i);
        return;
    }
    func_0201EDD0(p, i, 0x2B, v);
}




void func_0201F1B0(struct WordSet *p, u32 i, u8 v)
{
    if (v > 0x91) {
        func_0201ED64(p, i);
        return;
    }
    func_0201EDD0(p, i, 0, v);
}




void func_0201F1C8(struct WordSet *p, u32 i, u32 v)
{
    if (v > 8) {
        func_0201ED64(p, i);
        return;
    }
    func_0201EDD0(p, i, 0x38, v);
}




void func_0201F1E0(struct WordSet *p, u32 i, u32 v)
{
    void *s = func_02045B38(0, 3, (u16)0x1CD, (u16)p->heap);

    func_0201ED64(p, i);
    if (v <= 6 && s != 0) {
        func_02045CAC(s, v + 0x2B, p->buf);
        func_0201ED84(p, i, p->buf, 0);
        func_02045C04(s);
    }
}




void func_0201F230(struct WordSet *p, u32 i, u32 v)
{
    if (v < 1) {
        v = 1;
    } else if (v > 0xC) {
        v = 0xC;
    }
    func_0201EDD0(p, i, 0x116, v - 1);
}





/*
 * wordset.c's message expander, 204 bytes.  It walks the source message a
 * halfword at a time and rewrites it into the destination buffer: an ordinary
 * character is copied straight through, a 0xF000 tag that is not a word
 * reference is copied verbatim halfword by halfword, and a word reference is
 * replaced by the stored word itself.
 *
 * The tag primitives it calls are the seven of src/matched/unit_0201D5C4.c:
 * func_0201D5C4 is the 0xF000 marker, func_0201D5CC says whether the tag is a
 * word reference, func_0201D670 reads parameter 0 (the word index),
 * func_0201D60C writes a new tag, and func_0201D688 steps the cursor past a
 * tag.  The word table hangs off the object at +8 and its entries are 0xC
 * bytes: a flag at +4 and the word's own message at +8.  When the flag is set
 * the expansion is bracketed by two freshly built 0xBD tags, kinds 6 and 4,
 * whose single parameter is the word index and the constant 0x54.
 *
 * Three details cost time:
 *
 *   - **The entry pointer is a named local for the first tag write and the
 *     written-out expression for the second.**  `&tbl[i]` must be bound to a
 *     local, because the two `strh`s into the parameter buffer sit between the
 *     flag test and the first write, and the buffer has its address taken, so
 *     re-reading `ws->unk08` after them costs a reload the original does not
 *     have.  Binding it for the *second* write as well is four bytes too long
 *     the other way: the local would then be live across func_0201D60C and the
 *     index has to be spilled.  The original recomputes the address from the
 *     two callee-saved registers it already holds, which is what writing the
 *     expression out gives.
 *   - **The character copies are `*p++`, not `p[0]` then `p++`.**  With the
 *     increment spelled separately the compiler sinks it past the call and
 *     then folds the loop-bottom re-read into the copy's own load; the
 *     function is four bytes short and the bottom of the loop is wrong.
 *   - **`q` is declared before `p`.**  The two cursors are the only locals
 *     live across the inner loop, and declaring `p` first swaps r4 and r5
 *     throughout (docs/idioms/declaration-order-decides-which-register-a-local-gets.md).
 *
 * EXACT*: the two bytes after the epilogue are the unit's alignment padding
 * and 0x0201F31C, the next function, already carries a label.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201F250.c \
 *       --func func_0201F250 --addr 0x0201F250 --cc 1.1p1 --thumb
 */
void func_0201F250(struct WordSet *ws, void *dst, void *src)
{
    u16 buf[2];
    u32 term;
    u32 marker;
    u16 *q;
    u16 *p;
    u32 i;
    struct Entry *e;

    p = func_02045A90(src);
    func_0204581C(dst);
    term = func_02045A98();
    marker = func_0201D5C4();
    while (p[0] != term) {
        if (p[0] == marker) {
            if (func_0201D5CC(p) != 0) {
                i = func_0201D670(p, 0);
                e = &ws->entries[i];
                if (e->tag.unk04 != 0) {
                    buf[1] = (u16)i;
                    buf[0] = 0x54;
                    func_0201D60C(e->str, 0xBD, 6, 1, &buf[1]);
                    func_0201D60C(ws->entries[i].str, 0xBD, 4, 1, &buf[0]);
                }
                func_0201F4A0(dst, ws->entries[i].str);
                p = func_0201D688(p);
            } else {
                q = p;
                p = func_0201D688(p);
                while (q < p) {
                    func_02045AFC(dst, *q++);
                }
            }
        } else {
            func_02045AFC(dst, *p++);
        }
    }
}





/*
 * The wordset.c "clear every slot" walk and the one-line initialiser that
 * fills the file-scope template string at 0x020A7370.  That pointer is loaded
 * by func_0201EE60 in src/matched/unit_0201ED04.c and by seven functions
 * outside this region, so the `literal` class has witnesses to spare.
 *
 * func_0201F344 takes its heap id as a u16: the 4th argument of
 * func_02045B38 is a u16 and the original passes the incoming register
 * straight through with no `lsls`/`lsrs` truncation pair, which a u32
 * parameter would have cost.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201F31C.c  *       --addr 0x0201F31C --thumb
 */
void func_0201F31C(struct WordSet *p)
{
    u32 i;

    for (i = 0; i < p->count; i++) {
        func_0204581C(p->entries[i].str);
    }
}




void func_0201F344(u16 heap)
{
    unk_020A7370 = func_02045B38(0, 2, 0x46, heap);
}





/*
 *           The three data pool words -- g_0209E784, g_0209E758, g_0209E838 -- have no
 *           witness outside 0201F35C..0201F41C: each address appears in exactly one
 *           literal pool image-wide, this function's own, so the 'literal' class has
 *           nothing to offer and no other matched entry names them. A second reader of
 *           any of the three tables would release this file to EXACT.
 */
void func_0201F35C(void *ctx, s32_0201F35C n, u32 kind, u32 mode, u32 flag)
{
    u16 *tbl;
    u32 d;
    u32 q;

    if (flag == 0) {
        tbl = g_0209E784;
    } else {
        tbl = g_0209E758;
    }
    func_0204581C(ctx);

    if ((u16)(n < 0) != 0) {
        u32 ch;
        s32_0201F35C neg = ~0;
        n = neg * n;
        if (flag == 0) {
            ch = 0x30FC;
        } else {
            ch = 0x2D;
        }
        func_02045AFC(ctx, (u16)ch);
    }

    d = g_0209E838[kind];
    while (d != 0) {
        q = _u32_div_f((u32)n, d);
        q = (u16)q;
        n = n - d * q;
        if (q >= 10) {
            q = 10;
        }
        if (mode == 2) {
            func_02045AFC(ctx, tbl[q]);
        } else if (q != 0 || d == 1) {
            mode = 2;
            func_02045AFC(ctx, tbl[q]);
        } else if (mode == 1) {
            u32 ch;
            if (flag == 0) {
                ch = 0x3000;
            } else {
                ch = 0x20;
            }
            func_02045AFC(ctx, (u16)ch);
        }
        d = _u32_div_f(d, 10);
    }
}





/*
 * Decimal number printer.  func_0204581C(ctx) resets the glyph writer;
 * func_02045AFC(ctx, u16) emits one glyph; _u32_div_f is the mwccarm
 * integer-division helper (docs/idioms/runtime-helper-reloc.md).
 *
 * `flag` selects one of two glyph tables (0x0209E784 full-width,
 * 0x0209E758 half-width) and the matching minus / space glyphs
 * (0x30FC vs 0x2D, 0x3000 vs 0x20): this is the full-width/half-width
 * font pair, not a version-specific table.
 *
 * Two idioms carried the last four bytes: the negation is `~0 * n`, not
 * `-n` (which compiles to `rsbs`), and the remainder is `n - d * q`, not
 * `n - q * d` (docs/idioms/commutative-operand-order-names-the-temporary.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0201F35C.c \
 *       --func func_0201F35C --addr 0x0201F35C --cc 1.1p1 --thumb
 */


/*
 * Two wide-string helpers.  func_0201F41C is a bounded copy that always
 * terminates the destination; func_0201F448 is an equality test.  Both read
 * the terminator character from func_02045A98 rather than from a constant,
 * and both hold it in a named local, which is what puts the call result in
 * the left slot of func_0201F41C's `cmp r0, r1`
 * (docs/idioms/cmp-operand-order-names-the-temporary.md).
 *
 * The last store of func_0201F41C is `*(dst + n - 1) = eos`, not
 * `dst[n - 1] = eos`.  The two are the same value and different code: the
 * subscript form folds the subtraction into the index and scales once
 * (`subs`/`lsls`/`strh` with a register offset), while the pointer form
 * scales `n`, adds it to the base and then subtracts the element size
 * (`lsls`/`adds`/`subs #2`/`strh`).  Seven bytes, and nothing else in the
 * function moves; see
 * docs/idioms/pointer-minus-one-scales-before-the-subtraction.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201F41C.c  *       --addr 0x0201F41C --thumb
 */
void func_0201F41C(const u16 *src, u16 *dst, u32 n)
{
    u16 eos = func_02045A98();
    u32 i;

    for (i = 0; i < n; i++) {
        dst[i] = src[i];
        if (eos == src[i]) {
            break;
        }
    }
    *(dst + n - 1) = eos;
}





u32 func_0201F448(const u16 *a, const u16 *b)
{
    u16 eos = func_02045A98();

    while (*a != eos) {
        if (*a != *b) {
            return 0;
        }
        a++;
        b++;
    }
    if (*b != eos) {
        return 0;
    }
    return 1;
}





/*
 * "Is this string a packed nine-bit run", the predicate func_0201F4A0 tests
 * before unpacking.  A non-empty string whose first character is 0xF100 is
 * one; the marker is materialised as `movs r0, #0xF1` / `lsls r0, #8` rather
 * than from a pool word, so it is a plain constant.
 *
 * The two tests share one `movs r0, #0; pop` exit and neither jumps over an
 * inline epilogue, which is the single-conjunction shape of
 * docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md:
 * written as two separate early returns the function grows a second epilogue.
 *
 * This is its own file rather than part of src/pending/sub_0201F4A0.c
 * because func_0201F4A0 holds the only call to it in the image.  Matched
 * apart, that call is an ordinary `label` witness from outside this range,
 * and the `matched` class then carries the site in func_0201F4A0 itself.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201F47C.c \
 *       --addr 0x0201F47C --thumb
 */
u32 func_0201F47C(void *s)
{
    if (func_020458F8(s) != 0 && *func_02045A90(s) == 0xF100) {
        return 1;
    }
    return 0;
}





/*
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 *
 * The nine-bit unpacker.  A string whose first character is 0xF100
 * (func_0201F47C, src/matched/unit_0201F47C.c) carries its text as a run of
 * nine-bit codes packed into the halfwords after the marker; this walks them
 * and appends one character at a time to the destination.  0x1FF is the
 * terminator as well as the field mask, codes 0x100..0x131 are translated
 * through a 16-bit table and anything at or above 0x132 becomes 0x3F, '?'.
 *
 * Every concrete byte is reproduced.  The one unresolved relocation is the
 * table address 0x0209E864, and the pool word inside this function is the
 * only word in the image that holds it, so the `literal` class discards its
 * only witness and no cut helps.  Expressing the address as an offset from
 * func_0201F35C's nearby table would resolve it, but that is a claim that the
 * two are one object and the image does not say so.
 *
 * Three details cost time and are worth keeping:
 *
 *  - the bit cursor is signed.  `cmp r5, #0x10` / `blt` is a signed compare
 *    even though the value is never negative, so the local is `s32`; `u32`
 *    gives `blo` and one wrong byte.
 *  - the two range limits and the table bias live in a local aggregate, not
 *    in scalars.  Each of the two limits is stored twice, once as 0x1FF and
 *    once as 0x1FF - 0xCD, because mwccarm's value numbering follows a scalar
 *    local but stops at a member of an aggregate; written as scalars the
 *    constants fold and six instructions disappear.  That is
 *    docs/idioms/a-guard-on-a-struct-member-survives-constant-folding.md seen
 *    from the assignment side rather than the test side.
 *  - the unpacking loop is the fall-through arm and the plain-string copy is
 *    the `else`.  Written as an early return for the plain case the copy is
 *    emitted first and every branch in the function moves
 *    (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/pending/sub_0201F4A0.c  *       --addr 0x0201F4A0 --thumb
 */
void func_0201F4A0(void *dest, void *src)
{
    u32 mask = 0x1FF;
    struct Lim lim;
    const u16 *p;
    s32_0201F4A0 bit;
    u16 v;

    if (func_0201F47C(src) != 0) {
        p = func_02045A90(src) + 1;
        lim.hi = mask;
        lim.hi -= 0xCD;
        lim.hi2 = mask;
        lim.hi2 -= 0xCD;
        lim.bias = mask + 1;
        bit = 0;
        for (;;) {
            v = (*p >> bit) & mask;
            bit += 9;
            if (bit >= 16) {
                p++;
                bit -= 16;
                if (bit != 0) {
                    v |= (*p << (9 - bit)) & mask;
                }
            }
            if (v == mask) {
                return;
            }
            if (v >= 0x100 && v < lim.hi) {
                v = *(const u16 *)((const u8 *)&func_0201F4A0_Table[v]
                                   - lim.bias);
            } else if (v >= lim.hi2) {
                v = 0x3F;
            }
            func_02045AFC(dest, v);
        }
    } else {
        func_02045AA8(dest, src);
    }
}
