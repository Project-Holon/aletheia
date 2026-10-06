/*
 * file:     iss_switch_sys.c
 * unit:     yes
 * function: func_0202C070, func_0202C08C, func_0202C09C, func_0202C0B8, func_0202C0C0, func_0202C0C8, func_0202C0D0, func_0202C0E4, func_0202C0F8, func_0202C110, func_0202C118, func_0202C124, func_0202C140, func_0202C148, func_0202C198, func_0202C1C4, func_0202C1D4, func_0202C204, func_0202C218, func_0202C240, func_0202C244, func_0202C24C, func_0202C250, func_0202C268, func_0202C29C, func_0202C2C0, func_0202C2D0, func_0202C2D8, func_0202C2DC, func_0202C2EC, func_0202C308, func_0202C318, func_0202C320, func_0202C328, func_0202C330, func_0202C338, func_0202C340, func_0202C348, func_0202C350, func_0202C358, func_0202C360, func_0202C384, func_0202C3A0, func_0202C3A8, func_0202C3C4, func_0202C3E0, func_0202C470, func_0202C48C, func_0202C498, func_0202C4A4, func_0202C4C8, func_0202C4CC, func_0202C4D0, func_0202C4D8, func_0202C504, func_0202C510, func_0202C518, func_0202C538, func_0202C548, func_0202C550, func_0202C558, func_0202C560, func_0202C568, func_0202C570, func_0202C578, func_0202C580, func_0202C588, func_0202C590, func_0202C5AC, func_0202C5B4, func_0202C5C4, func_0202C5CC, func_0202C5E0, func_0202C5F0, func_0202C630, func_0202C634, func_0202C638, func_0202C654, func_0202C670, func_0202C688, func_0202C6A0, func_0202C6AC, func_0202C6B8, func_0202C6BC, func_0202C6C4, func_0202C710, func_0202C72C, func_0202C760, func_0202C794, func_0202C824, func_0202C83C, func_0202C860, func_0202C8B8, func_0202C934, func_0202C970, func_0202C9B4, func_0202CA0C, func_0202CA3C, func_0202CAC4, func_0202CAE4, func_0202CB18, func_0202CB4C, func_0202CC58, func_0202CC70, func_0202CD64, func_0202CD94, func_0202CDD4, func_0202CE40, func_0202CE50, func_0202CEBC, func_0202CF84, func_0202CF8C, func_0202CF98, func_0202CFC0, func_0202CFEC, func_0202D018, func_0202D01C, func_0202D034, func_0202D060, func_0202D064, func_0202D09C, func_0202D0D4, func_0202D110, func_0202D144, func_0202D178, func_0202D1AC, func_0202D1E0, func_0202D214, func_0202D2EC, func_0202D3D0, func_0202D4A8, func_0202D5CC, func_0202D5D8, func_0202D5F8, func_0202D61C, func_0202D640, func_0202D664, func_0202D688, func_0202D6AC, func_0202D6D0, func_0202D6F4, func_0202D760, func_0202D7C8, func_0202D7D8, func_0202D81C, func_0202D898, func_0202D8D0, func_0202D934, func_0202D9A4, func_0202DA04, func_0202DA18, func_0202DA48, func_0202DA6C, func_0202DAA4, func_0202DB0C, func_0202DBC4, func_0202DC08, func_0202DC48, func_0202DC60, func_0202DC98, func_0202DC9C, func_0202DCB0, func_0202DCC4, func_0202DCD4, func_0202DCFC, func_0202DD24, func_0202DE5C, func_0202DE64, func_0202DE68, func_0202DE6C, func_0202DE9C, func_0202DEE0, func_0202DF24, func_0202DF68, func_0202DFD4, func_0202DFEC, func_0202E040, func_0202E09C, func_0202E0C8, func_0202E0E0, func_0202E1F0, func_0202E38C, func_0202E3E4, func_0202E430, func_0202E43C, func_0202E448, func_0202E474
 * address:  0x0202C070
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by hand from the verified parts of tools/restructure.py.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   g_020A7758     0x020A7758  data
 *   func_020307B0  0x020307B0  arm
 *   func_02005C44  0x02005C44  thumb
 *   g_020A776C     0x020A776C  data
 *   FSi_ConvertStringSjisToUnicode  0x02048F74  arm
 *   g_020A7780      0x020A7780  data
 *   _s32_div_f    0x0209C0A4  arm
 *   func_02005F24  0x02005F24  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0201297C  0x0201297C  thumb
 *   func_0215E6A8  0x0215E6A8  thumb
 *   func_021647E8  0x021647E8  thumb  ov010
 *   func_02013C10  0x02013C10  thumb
 *   func_0215E6F8  0x0215E6F8  thumb ov010
 *   func_02012994  0x02012994  thumb
 *   func_020129A0  0x020129A0  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02013D74  0x02013D74  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_0215843C  0x0215843C  thumb
 *   gTbl_0209FFF4  0x0209FFF4  data
 *   func_020111E8  0x020111E8  thumb
 *   func_02014044   0x02014044  thumb
 *   func_0203F4E4  0x0203F4E4  arm
 *   func_0202EB60   0x0202EB60  thumb
 *   bgwinfrm_File  0x020A7790  data
 *   str_020A7790   0x020A7790  data
 *   MIi_CpuCopy16  0x02082A60  arm
 *   func_02049EB4       0x02049EB4  arm
 *   func_02049EF4       0x02049EF4  arm
 *   func_020410D0  0x020410D0  arm
 *   g_020A0058     0x020A0058  data
 *   func_02041300 0x02041300 arm
 *   func_02045768  0x02045768  arm
 *   func_02045778  0x02045778  arm
 *   func_02045738  0x02045738  arm
 *   func_02045740  0x02045740  arm
 *   func_02045758  0x02045758  arm
 *   func_02045760  0x02045760  arm
 *   _u32_div_f  0x0209C2B0  arm
 *   str_020A77AC    0x020A77AC  data
 *   MIi_CpuCopyFast 0x02082B0C  arm
 *   sFile_020A77AC  0x020A77AC  data
 *   tile_tables  0x020A779C  data
 *   func_02019C90  0x02019C90  thumb
 *   func_020490A8  0x020490A8  arm
 *   sub_0202D5D8_Table  0x020A023C  data
 *   func_02017E88   0x02017E88  thumb
 *   func_02017EB4   0x02017EB4  thumb
 *   func_02049E34   0x02049E34  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8   0x0204A6C8  arm
 *   func_0204A9D0   0x0204A9D0  arm
 *   func_02027710   0x02027710  thumb
 *   func_02027714   0x02027714  thumb
 *   func_020275E4   0x020275E4  thumb
 *   func_020490F4   0x020490F4  arm
 *   func_0204AF28   0x0204AF28  arm
 *   func_02049238   0x02049238  arm
 *   func_02049250  0x02049250  arm
 *   func_02049E74  0x02049E74  arm
 *   func_0204ADEC  0x0204ADEC  arm
 *   func_02062A98  0x02062A98  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   s_pms_draw_c   0x020A77B8  data  a1
 *   func_0204B688  0x0204B688  arm
 *   func_02045770  0x02045770  arm
 *   func_02043814  0x02043814  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_0204B454  0x0204B454  arm
 *   func_0204B404  0x0204B404  arm
 *   func_0204B898  0x0204B898  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_02035630  0x02035630  arm
 *   func_0204B954  0x0204B954  arm
 *   func_020416D4  0x020416D4  arm
 *   func_0204B84C  0x0204B84C  arm
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02041648  0x02041648  arm
 *   func_02041664  0x02041664  arm
 *   func_0204B53C  0x0204B53C  arm
 *   func_0204B528  0x0204B528  arm
 *   func_02024570  0x02024570  thumb
 *   func_0202465C  0x0202465C  thumb
 *   func_0202441C  0x0202441C  thumb
 *   func_0201D478  0x0201D478  thumb
 *   func_020244F8  0x020244F8  thumb
 *   func_020244D4  0x020244D4  thumb
 *   func_02024368  0x02024368  thumb
 *   func_0201D528  0x0201D528  thumb
 *   func_0201D4BC  0x0201D4BC  thumb
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_02043AF4  0x02043AF4  arm
 *   func_02045808  0x02045808  arm
 *   func_020456F8  0x020456F8  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02082BCC  0x02082BCC  arm
 *   sub_0202E448_Table  0x020A02A8  data
 *   data_020A77C4  0x020A77C4  data
 */
#include "../../matched/include/Obj04107.h"
#include "../../matched/include/Obj04107.h"
#include "../../matched/include/Obj04743.h"
#include "../../matched/include/Obj15848.h"
#include "../../matched/include/Obj16765.h"
#include "../../matched/include/Obj13942.h"
#include "../../matched/include/Obj11318.h"
#include "../../matched/include/Obj04060.h"

struct Obj0202C244;
struct Obj0202C360;
struct Obj0202C3E0;
struct Arr0202C510;
struct Arr0202C4D0;
struct Obj0202C4CC;
struct Counter0202C5B4;
struct Obj0202C6B8;
struct BigObj;
struct Ctx;
struct Descriptor;
struct Obj0202D3D0;
struct Sub0204A9D0;
struct ArcFile;
struct NitroFileHeader;
struct Res;
struct Actor;
struct PmsDraw;
struct PmsElem;
struct Cfg;
struct Bmp;
struct PtS;
struct Vec2;
struct Pos0202DE6C;
struct PrintSys;
struct Container;
struct Pos;
struct Rec8;
struct Struct_0202441C;
struct T;
struct CharBuf;
struct U16Vec;
struct Big;
struct SaveBlock;
struct Sub02008700Obj;
struct Rec44;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int  u32;

struct Obj0202C244 {
    u32 unk00;
    u32 unk04;
    u32 *unk08;
    u32 unk0c;
};

struct Obj0202C360 {
    u32 unk00;
    u16 shorts[9];
    u8  unk16;
    u8  pad17;
    void *words[9];
};

struct Obj0202C3E0 {
    u8 pad04[4];
    u16 unk04[9];
    u8 unk16;
};

typedef signed int s32;

struct Obj0202C4CC {
    u8 pad[0x16];
    u8 unk16;
};

struct Arr0202C510 {
    u8 pad[0x18];
    u32 unk18[1];
};

struct Arr0202C4D0 {
    u8 pad[4];
    u16 unk04[1];
};

struct Counter0202C5B4 {
    u32 unk00;
    u16 unk04;
    u16 unk06;
    u16 unk08;
};

struct Obj0202C5C4 {
    u8 pad[6];
    u16 unk06;
    u16 unk08;
};

struct Obj0202C6B8 {
    u32 unk00;
    u16 unk04;
};

struct Pair {
    u16 a;
    u16 b;
};

struct RtcDate {
    u32 year;
    u32 month;
    u32 day;
    u32 week;
};

typedef signed char    s8;

struct Win {
    u16 *tiles;
    u16 w:6;
    u16 h:6;
    u16 dirty:1;
    u16 unk04_13:3;
    s8 x;
    s8 y;
    s8 dx;
    s8 dy;
    u8 bg;
    u8 frames;
    s8 xmin;
    s8 xmax;
    s8 ymin;
    s8 ymax;
};

struct WinMgr {
    struct Win *wins;
    u16 count;
    u16 mode : 15;
    u16 flag : 1;
    u32 heap;
};

struct Obj0202D3D0 {
    u8  pad[0x14];
    u8 *blob;
};

typedef enum { PAL_0 } Pal;

struct PmsFlagBits {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 rest : 29;
};

union PmsFlags {
    u32 word;
    struct PmsFlagBits bits;
};

struct PmsElem {
    void *handle;
    u8    live;
    u8    pad05[3];
    struct Actor *actor[2];
    s32   x;
    s32   y;
    union PmsFlags flags;
    u32   unk1c;
    u32   enabled[2];
};

struct PmsDraw {
    u16   heap;
    u8    pad02[2];
    u32   unk04;
    void *unk08;
    struct PmsElem *elems;
    u32   res[5];
    u16   unk24;
    u8    pad26[2];
    u32   selected;
    u32   unk2c;
    u8    count;
    u8    unk31;
};

typedef signed short   s16;

struct Pt_0202DD24 { s16 x; s16 y; };

struct Pos0202DE6C {
    u32 x;
    u32 y;
};

typedef volatile unsigned int vu32;

struct Zero4 { u16 a; u16 b; u16 c; u16 d; };

struct Res {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
};

struct Pos { u32 x; u32 y; };

struct Pt_0202E040  { u16 x; u16 y; };

struct Pt_0202E0E0 {
    s16 x;
    s16 y;
};

typedef struct { u16 arc; u16 str; u16 code[2]; } MSGPARAM;

typedef struct { s32 x; s32 y; } BLINKPOS;

struct Ent0202E448 {
    u16 id  : 10;
    u16 val : 6;
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern u32 func_02049030(u32 a);
extern u16 func_02005C44(void);
extern u32 FSi_ConvertStringSjisToUnicode(void *dst, u32 term, void *src,
                                           u32 srcOffset, u32 dstSize);
extern void func_02005F24(u32 a0, u32 a1);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_0201297C(const struct BigObj *p);
extern u32 func_0215E6A8(void *a, u16 b);
extern u32 func_021647E8(void *arg, unsigned int b);
extern u32 func_02013C10(u32 id);
extern void func_020129A0(struct BigObj *p, u8 v);
extern int func_0215E6F8(int a0);
extern u8 func_02012994(const struct BigObj *p);
extern u32 func_0201296C(const struct BigObj *p);
extern u32 func_02012138(const struct Ctx *p);
extern int func_02013D74(u32 key);
extern u32 func_020142E8(void *bitmap, s32 id);
extern s32 func_0215843C(u32 a);
extern u32 func_020111E8(void);
extern u32 func_02014044(u32 id);
extern void func_0203F4E4(struct RtcDate *date);
extern void func_0202EB60(u8 *out1, u8 *out2);
extern void MIi_CpuCopy16(const void *src, void *dst, u32 size);
extern void *func_02049EB4(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void *func_02049EF4(void *arc, u32 member, u32 alloc, void **out,
                           u16 heap);
extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, const u16 *a5,
                          u8 a6, u8 a7, u8 a8, u8 a9);
extern void (*g_020A0058[])(u32);
extern void func_02041300(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
extern u16 func_02045768(struct Descriptor *p);
extern u8 func_02045778(struct Descriptor *p);
extern u8 func_02045738(struct Descriptor *p);
extern u8 func_02045740(struct Descriptor *p);
extern u8 func_02045758(struct Descriptor *p);
extern u8 func_02045760(struct Descriptor *p);
extern void  MIi_CpuCopyFast(void *dst, const void *src, u32 size);
extern u32 func_02019C90(u16 a, u16 b, u32 k);
extern u32 func_020490A8(u32 a, u32 b);
extern u32 func_02017E88(void *mon, u32 id, u32 v);
extern u32 func_02017EB4(void *mon);
extern void *func_02049E34(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern u32 func_0204AC18(void *h, u32 a1, u32 engine, u32 a3, u32 s0, u32 s1, u32 s2);
extern u32 func_0204A6C8(void *h, u32 a1, u32 a2, u32 engine, u32 s0);
extern void func_0204A9D0(int a, struct Sub0204A9D0 *b);
extern void *func_020490F4(u32 id, u32 heap);
extern int func_02027710(int a);
extern int func_02027714(int a);
extern u32   func_020275E4(void);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void  func_02049238(void *h);
extern int func_02027718(int a);
extern int func_0202771C(int a);
extern void *func_02049250(struct ArcFile *arc, u32 member, u32 heap);
extern void *func_02049E74(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void  func_0204ADEC(void *dst, void *src, u32 flag);
extern s32 func_02062A98(struct NitroFileHeader *file, void **out);
extern void  MI_CpuFill8(void *p, u32 v, u32 n);
extern void func_0204B688(struct Actor *actor, u32 val);
extern void *func_02045770(struct Descriptor *h);
extern void func_02043814(struct Bmp *dst, const struct Bmp *src);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B404(struct Actor *p, const struct Vec2 *delta, u32 which);
extern u16 func_0204B898(struct Actor *p);
extern void func_0204B878(struct Actor *p, u16 value);
extern void func_0204B3DC(struct Actor *p, u32 v);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern struct Actor *func_0204B294(void *a, u32 b, u32 c, u32 d,
                                const void *e, u16 f, u16 g);
extern void func_0204B92C(struct Actor *p, u32 v);
extern u8 func_02035630(void);
extern void func_0204B954(struct Actor *a, u32 v);
extern u8 func_020416D4(u32 layer);
extern void  func_0204B84C(void *h, u32 a);
extern void func_0204B3B4(struct Actor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern u32 func_02041648(u8 channel);
extern u32 func_02041664(u8 channel);
extern void func_0204B53C(const struct Actor *actor, struct Pt_0202E0E0 *out);
extern void func_0204B528(struct Actor *actor, const struct Pt_0202E0E0 *src);
extern void func_02024570(struct Rec8 *dst, const struct Rec8 *src);
extern u32 func_0202465C(struct T *p, u32 a1, u32 a2);
extern void *func_0202441C(const struct Struct_0202441C *obj, u32 heapId);
extern u32   func_0201D478(void *str);
extern u32 func_020244F8(struct Container *p, u32 idx);
extern u16 func_020244D4(void *obj, u32 idx);
extern void *func_02024368(u16 *slots, u32 heap, int count);
extern u32 func_0201D528(void *s, u8 b, void *c, u32 d);
extern u32   func_0201D4BC(void *s, u8 idx);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void  func_02043AF4(u32 a, u32 b, s16 c, u32 d, u32 e, u8 f);
extern void func_02045808(struct U16Vec *vec);
extern void func_020456F8(struct Descriptor *d);
extern void func_020409B4(u32 index);
extern void func_02082BCC(void *p, u32 a, u32 b);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern u8 *func_02012944(void *p);
extern unsigned int func_02012924(const struct BigObj *p);
extern void *func_0201292C(const struct BigObj *p);
extern void  func_02082D44(void *src, void *dst, int n);
extern void *func_020127A4(struct SaveBlock *p);
extern u32 func_02012B28(const struct Rec44 *p);
u8 *func_0202C070(u16 heap);
void func_0202C08C(u8 *p);
void func_0202C09C(u8 *p);
void func_0202C0B8(u8 *p);
void func_0202C0C0(u32 *p);
void func_0202C0C8(u32 *p, u32 v);
void func_0202C0D0(u8 *p, u32 a);
void func_0202C0E4(u8 *p, u32 a);
u32 func_0202C0F8(struct Obj0202C244 *p, u32 idx);
void func_0202C110(void *p);
void func_0202C118(void *obj);
void *func_0202C124(u32 heap);
void func_0202C140(void *ptr);
void func_0202C148(u8 *p, u16 heapId);
void func_0202C198(u8 *p);
u32 func_0202C1C4(struct Obj0202C244 *p);
void func_0202C1D4(u8 *p);
void func_0202C204(u32 *p);
void func_0202C218(u32 *p, u32 v);
u32 func_0202C240(void *obj);
u32 func_0202C244(struct Obj0202C244 *p, u32 idx);
u32 func_0202C24C(struct Obj0202C244 *p);
u32 func_0202C250(u32 *p, u32 v);
u32 func_0202C268(u8 *p, u32 v);
int func_0202C29C(u32 *p, u32 v);
void func_0202C2C0(void *p);
u32 func_0202C2D0(u32 v);
u32 func_0202C2D8(u32 *p);
void func_0202C2DC(void *p);
u32 func_0202C2EC(void *heap);
void func_0202C308(void *p);
u32 func_0202C318(void *a, u32 b, u32 c);
u32 func_0202C320(void *p);
u32 func_0202C328(void *p, u32 idx);
u32 func_0202C330(void *p, u32 idx);
void func_0202C338(void *p);
u32 func_0202C340(void *p);
u32 func_0202C348(void *a, void *b);
u32 func_0202C350(void *p, u32 idx);
void func_0202C358(void *p);
void func_0202C360(struct Obj0202C360 *p);
void *func_0202C384(void *heap);
u32 func_0202C3A0(void *p);
void func_0202C3A8(char *p, int a1);
void func_0202C3C4(struct Obj0202C360 *p);
u32 func_0202C3E0(struct Obj0202C3E0 *a, void *b);
u32 func_0202C470(void *p);
u32 func_0202C48C(void *p, u32 idx);
u32 func_0202C498(void *p, u32 idx);
void func_0202C4A4(void *p);
u32 func_0202C4C8(u32 *p);
u32 func_0202C4CC(struct Obj0202C4CC *p);
u32 func_0202C4D0(struct Arr0202C4D0 *p, u32 idx);
u32 func_0202C4D8(void *a, u32 b);
u32 func_0202C504(void *p, u32 idx);
u32 func_0202C510(struct Arr0202C510 *p, u32 idx);
void func_0202C518(void *p);
void *func_0202C538(u32 heapId);
u32 func_0202C548(void *p);
u32 func_0202C550(void *p, u16 a, u16 b);
u32 func_0202C558(void *p);
u32 func_0202C560(void *p);
u32 func_0202C568(void *p);
u32 func_0202C570(void *p);
u32 func_0202C578(void *p);
void func_0202C580(void *p);
void func_0202C588(void *p, u32 v);
void *func_0202C590(u32 heapId);
u32 func_0202C5AC(void *p);
void func_0202C5B4(struct Counter0202C5B4 *p);
u32 func_0202C5C4(struct Obj0202C5C4 *p, u16 a, u16 b);
void func_0202C5CC(struct Counter0202C5B4 *p);
u32 func_0202C5E0(struct Counter0202C5B4 *p);
void func_0202C5F0(void *p);
void func_0202C630(void *p);
void func_0202C634(void *p);
u32 func_0202C638(void *p);
u32 func_0202C654(void *p);
u32 func_0202C670(void *p);
u32 func_0202C688(void *p);
u32 func_0202C6A0(void *p);
u32 func_0202C6AC(void *p);
u32 func_0202C6B8(struct Obj0202C6B8 *p);
struct Obj0202C6B8 *func_0202C6BC(struct Obj0202C6B8 *p, u32 v);
s32 func_0202C6C4(struct Counter0202C5B4 *p);
void func_0202C710(struct Counter0202C5B4 *p, s32 n);
u32 func_0202C72C(void *p);
u32 func_0202C760(void *p);
u32 func_0202C794(void *a0, u32 a1);
int func_0202C824(int a0);
void func_0202C83C(struct Ctx *p, u32 a1);
void func_0202C860(u8 *a0, int a1);
s32 func_0202C8B8(void *a0, u32 a1, u32 a2);
s32 func_0202C934(void *a0, u32 a1, u32 a2);
u32 func_0202C970(void *a, void *b, u32 c);
struct WinMgr *func_0202C9B4(u32 a0, u32 a1, u32 heap);
void func_0202CA0C(struct WinMgr *obj);
void func_0202CA3C(struct WinMgr *mgr, u32 idx, u32 bg, u32 w, u32 h);
void func_0202CAC4(struct WinMgr *mgr, u32 idx, const void *src);
void func_0202CAE4(struct WinMgr *mgr, u32 idx, u32 arc, u32 member, u32 alloc);
void func_0202CB18(struct WinMgr *mgr, u32 idx, void *arc, u32 member, u32 alloc);
void func_0202CB4C(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
void func_0202CC58(struct WinMgr *mgr, u32 idx);
void func_0202CC70(struct WinMgr *mgr, u32 idx);
void func_0202CD64(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames);
void func_0202CD94(struct WinMgr *mgr);
u32 func_0202CDD4(struct WinMgr *mgr, u32 idx);
u32 func_0202CE40(struct WinMgr *mgr, u32 idx);
void func_0202CE50(struct WinMgr *mgr, u32 idx, s32 x, s32 y, u8 w, u8 h, u8 pal);
void func_0202CEBC(struct WinMgr *mgr, u32 idx, void *a);
u16 *func_0202CF84(struct WinMgr *mgr, u32 idx);
u8 func_0202CF8C(struct WinMgr *mgr, u32 idx);
void func_0202CF98(struct WinMgr *mgr, u32 idx, s8 *x, s8 *y);
void func_0202CFC0(struct WinMgr *mgr, u32 idx, u16 *w, u16 *h);
void func_0202CFEC(struct WinMgr *mgr, u32 idx, s8 xmin, s8 xmax, s8 ymin, s8 ymax);
void func_0202D018(void);
u8 func_0202D01C(u32 a, u32 b, u32 c);
int func_0202D034(u32 a, u32 b);
int func_0202D060(void);
s32 func_0202D064(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
s32 func_0202D09C(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
s32 func_0202D0D4(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
s32 func_0202D110(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
s32 func_0202D144(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
s32 func_0202D178(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
s32 func_0202D1AC(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
s32 func_0202D1E0(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
void func_0202D214(void *p, u32 v);
void func_0202D2EC(u32 *obj, u32 heap);
void func_0202D3D0(struct Obj0202D3D0 *obj, u32 a1);
void func_0202D4A8(void *narc, u32 species, s32 form, s32 mode, u32 base, u32 shiny, u32 egg, u32 *out_index, u32 *out_pal, u32 *out_mode, u32 *out_base, u32 **out_ptr, u32 female);
u32 func_0202D5CC(u32 a);
u32 func_0202D5D8(u32 id, u32 flags);
u32 func_0202D5F8(u32 id, u32 flags);
u32 func_0202D61C(u32 id, u32 flags);
u32 func_0202D640(u32 id, u32 flags);
u32 func_0202D664(u32 id, u32 flags);
u32 func_0202D688(u32 id, u32 flags);
u32 func_0202D6AC(u32 id, u32 flags);
u32 func_0202D6D0(u32 id, u32 flags);
void *func_0202D6F4(u32 *a0, void *mon, u32 a2, u16 a3);
void *func_0202D760(u32 *out, u32 a1, u32 a2, u32 a3, u32 s0, u32 s1, u32 s2, u32 s3, volatile u16 s4);
void *func_0202D7C8(u32 heap);
int func_0202D7D8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, unsigned short a8, unsigned short a9);
u32 func_0202D81C(u32 a0, u32 a1, u32 a2, u32 a3, volatile u32 s0, volatile u32 s1, volatile u32 s2, volatile u32 s3, volatile u32 s4, volatile u16 key);
u32 func_0202D898(u32 a0, u32 a1, u32 a2, u32 a3, volatile u32 w0, volatile u32 w1, volatile u32 w2, volatile u32 w3, volatile u16 key);
int func_0202D8D0(int a0, void *a1, int a2, int a3, unsigned short a8, unsigned short a9);
int func_0202D934(int a0, void *a1, int a2, int a3, unsigned short a9);
u32 func_0202D9A4(u32 h, u32 b1, u32 b2, u32 b3, u16 key);
void *func_0202DA04(u32 heap);
s32 func_0202DA18(u32 a, u32 b, u32 c, u32 d, u16 e);
void func_0202DA48(u32 a, u32 b, u32 c, u32 d);
s32 func_0202DA6C(u32 a0, u32 a1, u32 a2, u16 a3);
void func_0202DAA4(void *set, u32 id, void *dstA, void *dstB, volatile u16 which);
struct PmsDraw *func_0202DB0C(u32 a, u32 b, u32 c, u32 d, u8 e0, u8 e1, u16 heap);
void func_0202DBC4(struct PmsDraw *p);
void func_0202DC08(struct PmsDraw *p);
void func_0202DC48(u32 a, u32 b, u32 c, u32 d);
void func_0202DC60(struct PmsDraw *p, void *a, void *w, u32 i, const void *e);
u32 func_0202DC98(struct PmsDraw *o);
void func_0202DC9C(struct PmsDraw *o, int i, u32 a1);
void func_0202DCB0(struct PmsDraw *o, int i, u32 a1);
u32 func_0202DCC4(const struct PmsDraw *p, u32 i);
void func_0202DCD4(struct PmsDraw *p, u32 i, u32 val);
void func_0202DCFC(struct PmsDraw *p, u32 i, u32 val);
void func_0202DD24(struct PmsDraw *p, u32 i, u32 j);
void func_0202DE5C(struct PmsDraw *p, u8 v);
void func_0202DE64(struct PmsDraw *p, u16 v);
void func_0202DE68(struct PmsDraw *p, u32 v);
void func_0202DE6C(u32 a, u32 b, u32 c, const struct Pos0202DE6C *base, struct Pos0202DE6C *out);
u32 func_0202DE9C(u32 engine);
u32 func_0202DEE0(u32 engine);
u32 func_0202DF24(u32 engine);
void func_0202DF68(u32 *o, u32 a1, u32 heap);
void func_0202DFD4(struct Res *p);
void *func_0202DFEC(struct Res *r, u16 a);
void func_0202E040(void *h, struct Descriptor *cell, u32 b, u32 c, u32 n, const struct Pos *base);
void func_0202E09C(struct PmsElem *o, struct Res *a, u16 b);
void func_0202E0C8(struct PmsElem *p);
int func_0202E0E0(struct PmsElem *a0, void *a1, int a2);
void func_0202E1F0(struct PmsElem *wk, void *owner, u32 a2, struct Descriptor *a3, const MSGPARAM *param, const BLINKPOS *pos, u16 pri, u8 pal, u16 heap);
void func_0202E38C(struct PmsElem *obj, u32 a1);
void func_0202E3E4(struct PmsElem *obj, u32 a1);
u32 func_0202E430(u32 id);
void func_0202E43C(void *p);
u32 func_0202E448(u32 id);
void *func_0202E474(const struct BigObj *a0, int a1, int a2, int a3);
extern const char g_020A7758[];
extern const char g_020A776C[];
extern char g_020A7780[];
extern struct Pair gTbl_0209FFF4[];
extern const char bgwinfrm_File[];
extern const char str_020A7790[];
extern const char str_020A77AC[];
extern char  sFile_020A77AC[];
extern const u8 *const tile_tables[4];
extern const u8 sub_0202D5D8_Table[];
extern char  s_pms_draw_c[];
extern const struct Ent0202E448 sub_0202E448_Table[];
extern char data_020A77C4[];

/*
 * Blocked: the THM_CALL at +0012 to func_0202C148 has no manifest entry.
 * 0x0202C148 (76 bytes, pkt_0202C148, still open) is byte-correct except an
 * eight-instruction schedule permutation in its prologue: 15 C spellings were
 * measured and every one emits the same permuted block, so it is a DIFF and
 * cannot be filed - see docs/notes/pkt_0202C148.c.txt.  The other two sites
 * (func_0202C124, func_0202C118) resolve as `matched`.  Every concrete byte
 * reproduces.
 *
 * Creates a node through func_0202C124, prepares it with func_0202C118 and
 * binds the argument with func_0202C148.
 */
u8 *func_0202C070(u16 heap)
{
    u8 *r = func_0202C124(heap);

    func_0202C118(r);
    func_0202C148(r, heap);
    return r;
}

/*
 * closed:   blocker func_0202B6AC.c is now a manifest entry (matched class)
 *
 * Runs func_0202C198 then func_0202C140 over the object.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202C08C.c \
 *       --func func_0202C08C --addr 0x0202C08C --thumb --cc 1.1p1
 */
void func_0202C08C(u8 *p)
{
    func_0202C198(p);
    func_0202C140(p);
}

/*
 * When func_0202C2D8 reports true, runs func_0202C1C4 and func_0202C2C0.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202C09C.c \
 *       --func func_0202C09C --addr 0x0202C09C --thumb --cc 1.1p1
 */
void func_0202C09C(u8 *p)
{
    if (func_0202C2D8((u32 *)p) != 0) {
        func_0202C1C4((struct Obj0202C244 *)p);
        func_0202C2C0(p);
    }
}

/*
 * An eight-byte tail-call thunk: the pool word at +4 holds 0x0202C1D4, the callee's
 * address with its Thumb bit set (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 * Unlabelled in the listing and absent from the worklist - found by scanning
 * the image for the `ldr r3, [pc, #0]; bx r3` shape whose following word names
 * an existing manifest entry - and filed from the bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202C0B8.c \
 *       --func func_0202C0B8 --addr 0x0202C0B8 --thumb --cc 1.1p1
 */
void func_0202C0B8(u8 *p)
{
    func_0202C1D4(p);
}

/*
 * An eight-byte tail-call thunk into func_0202C204, with the callee's ISA
 * carried in the low bit of the pool word (docs/idioms/
 * tail-call-is-a-pool-word-and-bx.md).  Unlabelled in the listing and absent
 * from the worklist; filed from the bytes.  src/pending/func_0202B704.c is
 * blocked on this address and now has it as a `matched` witness.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202C0C0.c \
 *       --func func_0202C0C0 --addr 0x0202C0C0 --thumb --cc 1.1p1
 */
void func_0202C0C0(u32 *p)
{
    func_0202C204(p);
}

/*
 * An eight-byte tail-call thunk into func_0202C218.  Unlabelled in the listing
 * and absent from the worklist; filed from the bytes.  src/pending/
 * func_0202B7E0.c is blocked on this address and now has it as a `matched`
 * witness.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202C0C8.c \
 *       --func func_0202C0C8 --addr 0x0202C0C8 --thumb --cc 1.1p1
 */
void func_0202C0C8(u32 *p, u32 v)
{
    func_0202C218(p, v);
}

/*
 * Resolves the object through func_0202C24C and, when found, forwards the
 * argument through func_0202C328.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202C0D0.c \
 *       --func func_0202C0D0 --addr 0x0202C0D0 --thumb --cc 1.1p1
 */
void func_0202C0D0(u8 *p, u32 a)
{
    u32 r = func_0202C24C((struct Obj0202C244 *)p);

    if (r != 0) {
        func_0202C328((void *)r, a);
    }
}

/*
 * Resolves the object through func_0202C24C and, when found, forwards the
 * argument through func_0202C330.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202C0E4.c \
 *       --func func_0202C0E4 --addr 0x0202C0E4 --thumb --cc 1.1p1
 */
void func_0202C0E4(u8 *p, u32 a)
{
    u32 r = func_0202C24C((struct Obj0202C244 *)p);

    if (r != 0) {
        func_0202C330((void *)r, a);
    }
}

u32 func_0202C0F8(struct Obj0202C244 *p, u32 idx)
{
    u32 r = func_0202C24C(p);

    if (r != 0) {
        return func_0202C350((void *)r, idx);
    }
    return 0;
}

/*
 * An eight-byte tail-call thunk: the pool word at +4 holds 0x0202C2DC, the callee's
 * address with its Thumb bit set (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 * Unlabelled in the listing and absent from the worklist - found by scanning
 * the image for the `ldr r3, [pc, #0]; bx r3` shape whose following word names
 * an existing manifest entry - and filed from the bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202C110.c \
 *       --func func_0202C110 --addr 0x0202C110 --thumb --cc 1.1p1
 */
void func_0202C110(void *p)
{
    func_0202C2DC(p);
}

void func_0202C118(void *obj)
{
    ((struct Obj04107 *)obj)->f0 = 0;
    ((struct Obj04107 *)obj)->f4 = 0;
    ((struct Obj04107 *)obj)->f8 = 0;
    ((struct Obj04107 *)obj)->fC = 0;
}

/*
 * Allocates 16 bytes from heap with tracking file and line.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202C124.c \
 *       --func func_0202C124 --addr 0x0202C124 --cc 1.1p1 --thumb
 */
void *func_0202C124(u32 heap)
{
    return func_02030734(heap, 0x10, 0, g_020A7758, 0x10A);
}

void func_0202C140(void *ptr)
{
    func_020307B0(ptr);
}

/*
 * Build the unit table of a block: n = func_02049030(0x93) members, the
 * count stored at +4, an n-word pointer array allocated from heapId at +8
 * (file word 0x020A7758, line 0x13A), then one unit per slot from
 * func_0202C2EC(heapId), initialised by func_0202C318(unit, i, heapId).
 *
 * What closed it (wave 17, from 17 out): heapId is a u16 PARAMETER.  With
 * a u32 heapId 1.1p1 hoists the heapId reload and the file pool word above
 * the `strb` of the count; narrowed, its home store `str r1, [sp, #4]`
 * sits at the front of the prologue and the image's order falls out
 * (docs/idioms/a-narrow-parameter-pins-its-home-store-to-the-front-of-the-prologue.md).
 * The callee prototypes take the same u16 heap id.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202C148.c \
 *       --func func_0202C148 --addr 0x0202C148 --cc 1.1p1 --thumb
 */
void func_0202C148(u8 *p, u16 heapId)
{
    u32 i;
    int n;

    n = func_02049030(0x93);
    p[4] = (u8)n;
    ((struct Obj04107 *)p)->f8 = (u32)func_02030734(heapId, (u32)(n << 2), 0,
                                         (const void *)0x020A7758, 0x13a);
    for (i = 0; (int)i < n; i++) {
        u8 *r = (u8 *)func_0202C2EC((void *)heapId);
        func_0202C318(r, i, heapId);
        *(u32 *)(((struct Obj04107 *)p)->f8 + (i << 2)) = (u32)r;
    }
}

/*
 * closed:   blocker  is now a manifest entry (matched class)
 *
 * Teardown for the list node func_0202C148 builds: walk the pointer array and
 * release each element, then free the array and clear all three headers.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0202C198.c \
 *       --func func_0202C198 --addr 0x0202C198 --thumb --cc 1.1p1
 */
void func_0202C198(u8 *p)
{
    int n = p[4];
    int i;

    for (i = 0; i < n; i++) {
        func_0202C308(*(u8 **)(*(u32 *)&((struct Obj04743 *)p)->f8 + (i << 2)));
    }
    func_020307B0(((struct Obj04743 *)p)->f8);
    p[4] = 0;
    *(u32 *)&((struct Obj04743 *)p)->f8 = 0;
    ((struct Obj04743 *)p)->fC = 0;
}

u32 func_0202C1C4(struct Obj0202C244 *p)
{
    u32 r = func_0202C24C(p);

    if (r != 0) {
        return func_0202C320((void *)r);
    }
    return r;
}

void func_0202C1D4(u8 *p)
{
    if (func_0202C2D8((u32 *)p) == 1) {
        return;
    }
    ((struct Obj15848 *)p)->f0 = 1;
    if (func_0202C29C((u32 *)p, func_0202C2D0(1)) != 1) {
        return;
    }
    func_0202C2DC(p);
    func_0202C2C0(p);
}

/*
 * Clears the object's first word when it is non-zero.  Unlabelled in the
 * listing (no lr save) and absent from the worklist; filed from the bytes.
 * It is the tail-call target of the thunk at 0x0202C0C0, which is what
 * src/pending/func_0202B704.c is blocked on.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202C204.c \
 *       --func func_0202C204 --addr 0x0202C204 --thumb --cc 1.1p1
 */
void func_0202C204(u32 *p)
{
    if (func_0202C2D8(p) != 0) {
        *p = 0;
    }
}

/*
 * Clears the record through func_0202C204 when the object is live and the
 * lookup fails.  Unlabelled in the listing (no lr save of its own beyond the
 * callee-saved set) and absent from the worklist; filed from the bytes.  It is
 * the tail-call target of the thunk at 0x0202C0C8, which is what
 * src/pending/func_0202B7E0.c is blocked on.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202C218.c \
 *       --func func_0202C218 --addr 0x0202C218 --thumb --cc 1.1p1
 */
void func_0202C218(u32 *p, u32 v)
{
    if (func_0202C2D8(p) == 0) {
        return;
    }
    if (func_0202C250(p, v) != 0) {
        return;
    }
    func_0202C2DC(p);
    func_0202C204(p);
}

u32 func_0202C240(void *obj)
{
    return ((struct Obj16765 *)obj)->f4;
}

u32 func_0202C244(struct Obj0202C244 *p, u32 idx)
{
    return p->unk08[idx];
}

u32 func_0202C24C(struct Obj0202C244 *p)
{
    return p->unk0c;
}

/*
 * When the object's +0xc field is set, hands that field (not the object) to
 * sub_0202C348 together with the caller's second argument.  Unlabelled in the
 * listing and absent from the worklist; filed from the bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202C250.c \
 *       --func func_0202C250 --addr 0x0202C250 --thumb --cc 1.1p1
 */
u32 func_0202C250(u32 *p, u32 v)
{
    u32 f = func_0202C24C((struct Obj0202C244 *)p);

    if (f == 0) {
        return 0;
    }
    return func_0202C348((void *)f, (void *)v);
}

/*
 * Scans the object's count entries (func_0202C240 is the count) looking for
 * the one whose sub_0202C340 value equals the caller's second argument, and
 * returns the entry's sub_0202C244 value.  The index is truncated to a byte
 * before it is passed, which is what the lsls/lsrs pair says.  Unlabelled in
 * the listing and absent from the worklist; filed from the bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202C268.c \
 *       --func func_0202C268 --addr 0x0202C268 --thumb --cc 1.1p1
 */
u32 func_0202C268(u8 *p, u32 v)
{
    int n = func_0202C240(p);
    int i;

    for (i = 0; i < n; i++) {
        u32 r = func_0202C244((struct Obj0202C244 *)p, (u8)i);

        if (v == func_0202C340((void *)r)) {
            return r;
        }
    }
    return 0;
}

/*
 * Looks the caller's second argument up with func_0202C268; if the result
 * differs from the object's current +0xc field, installs it there and reports
 * success.  Unlabelled in the listing and absent from the worklist; filed from
 * the bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202C29C.c \
 *       --func func_0202C29C --addr 0x0202C29C --thumb --cc 1.1p1
 */
int func_0202C29C(u32 *p, u32 v)
{
    u32 f = func_0202C24C((struct Obj0202C244 *)p);
    u32 x = func_0202C268((u8 *)p, v);

    if (f == x) {
        return 0;
    }
    p[3] = x;
    return 1;
}

void func_0202C2C0(void *p)
{
    u32 v = func_0202C24C(p);

    if (v != 0) {
        func_0202C358((void *)v);
    }
}

u32 func_0202C2D0(u32 v)
{
    return func_02005C44();
}

u32 func_0202C2D8(u32 *p)
{
    return *p;
}

void func_0202C2DC(void *p)
{
    u32 v = func_0202C24C(p);

    if (v != 0) {
        func_0202C338((void *)v);
    }
}

/*
 * Closed: func_0202C384 became an EXACT manifest entry, so the matched class attests the call at 0x0202C2F0.
 */
u32 func_0202C2EC(void *heap)
{
    u32 r = (u32)func_0202C384(heap);

    func_0202C360((void *)r);
    func_0202C3A8((char *)r, (int)heap);
    return r;
}

void func_0202C308(void *p)
{
    func_0202C3C4(p);
    func_0202C3A0(p);
}

u32 func_0202C318(void *a, u32 b, u32 c)
{
    return func_0202C3E0(a, (void *)b);
}

u32 func_0202C320(void *p)
{
    return func_0202C470(p);
}

u32 func_0202C328(void *p, u32 idx)
{
    return func_0202C48C(p, idx);
}

u32 func_0202C330(void *p, u32 idx)
{
    return func_0202C498(p, idx);
}

void func_0202C338(void *p)
{
    func_0202C4A4(p);
}

u32 func_0202C340(void *p)
{
    return func_0202C4C8(p);
}

u32 func_0202C348(void *a, void *b)
{
    return func_0202C4D8(a, (u32)b);
}

u32 func_0202C350(void *p, u32 idx)
{
    return func_0202C504(p, idx);
}

void func_0202C358(void *p)
{
    func_0202C518(p);
}

void func_0202C360(struct Obj0202C360 *p)
{
    int i;

    p->unk00 = 0;
    p->unk16 = 0;

    for (i = 0; i < 9; i++) {
        p->shorts[i] = 0;
    }

    for (i = 0; i < 9; i++) {
        p->words[i] = 0;
    }
}

void *func_0202C384(void *heap)
{
    return func_02030734((u32)heap, 0x3c, 0, g_020A776C, 0x12a);
}

u32 func_0202C3A0(void *p)
{
    return func_020307B0(p);
}

void func_0202C3A8(char *p, int a1)
{
    int i;
    for (i = 0; i < 9; i++)
        *(int *)(p + 0x18 + i * 4) = (int)func_0202C538(a1);
}

void func_0202C3C4(struct Obj0202C360 *p)
{
    int i;

    for (i = 0; i < 9; i++) {
        func_0202C548(p->words[i]);
        p->words[i] = 0;
    }
}

u32 func_0202C3E0(struct Obj0202C3E0 *a, void *b)
{
    u16 digits[9];
    u16 sep;
    int i;
    u32 off;
    u32 ret;

    i = 0;
    off = 0;
    FSi_ConvertStringSjisToUnicode(a, 0x93, b, off, 4);
    off += 4;

    for (; i < 9; i++, off += 2) {
        FSi_ConvertStringSjisToUnicode(&digits[i], 0x93, b, off, 2);
    }

    FSi_ConvertStringSjisToUnicode(&sep, 0x93, b, off, 2);
    FSi_ConvertStringSjisToUnicode(&a->unk16, 0x93, b, off + 2, 1);
    FSi_ConvertStringSjisToUnicode(a->unk04, 0x93, b, off + 3, a->unk16 * 2);

    i = 0;
    for (; i < 9; i++) {
        ret = func_0202C550((void *)func_0202C510((struct Arr0202C510 *)a, i), sep, digits[i]);
    }

    return ret;
}

u32 func_0202C470(void *p)
{
    s32 i;

    for (i = 0; i < 9; i++) {
        func_0202C580((void *)func_0202C510(p, i));
    }
}

u32 func_0202C48C(void *p, u32 idx)
{
    return func_0202C560((void *)func_0202C510(p, idx));
}

u32 func_0202C498(void *p, u32 idx)
{
    return func_0202C568((void *)func_0202C510(p, idx));
}

void func_0202C4A4(void *p)
{
    s32 i;

    func_0202C570((void *)func_0202C510(p, 0));
    for (i = 1; i < 9; i++) {
        func_0202C578((void *)func_0202C510(p, i));
    }
}

/*
 * An unlabelled leaf sitting in the four bytes between sub_0202C4A4's last
 * instruction and func_0202C4CC's first
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md): no
 * register-saving prologue, so disasm.py's sweep never marks it. It is a
 * plain read of the object's first word, reached only through
 * sub_0202C340's pool-word-and-bx tail call
 * (src/matched/unit_0202C318.c, parked at MATCH because this address is
 * its only caller anywhere in the image).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202C4C8.c \
 *       --func func_0202C4C8 --addr 0x0202C4C8 --cc 1.1p1 --thumb
 */
u32 func_0202C4C8(u32 *p)
{
    return *p;
}

u32 func_0202C4CC(struct Obj0202C4CC *p)
{
    return p->unk16;
}

u32 func_0202C4D0(struct Arr0202C4D0 *p, u32 idx)
{
    return p->unk04[idx];
}

u32 func_0202C4D8(void *a, u32 b)
{
    int count = func_0202C4CC(a);
    int i;

    for (i = 0; i < count; i++) {
        if (b == func_0202C4D0(a, i)) {
            return 1;
        }
    }
    return 0;
}

u32 func_0202C504(void *p, u32 idx)
{
    return func_0202C558((void *)func_0202C510(p, idx));
}

u32 func_0202C510(struct Arr0202C510 *p, u32 idx)
{
    return p->unk18[idx];
}

void func_0202C518(void *p)
{
    s32 i;

    for (i = 0; i < 9; i++) {
        func_0202C588((void *)func_0202C510(p, i), 0x7F);
    }
}

void *func_0202C538(u32 heapId)
{
    void *r = func_0202C590(heapId);

    func_0202C5B4(r);
    return r;
}

u32 func_0202C548(void *p)
{
    return func_0202C5AC(p);
}

u32 func_0202C550(void *p, u16 a, u16 b)
{
    return func_0202C5C4(p, a, b);
}

u32 func_0202C558(void *p)
{
    return func_0202C72C(p);
}

u32 func_0202C560(void *p)
{
    return func_0202C670(p);
}

u32 func_0202C568(void *p)
{
    return func_0202C688(p);
}

u32 func_0202C570(void *p)
{
    return func_0202C6A0(p);
}

u32 func_0202C578(void *p)
{
    return func_0202C6AC(p);
}

void func_0202C580(void *p)
{
    func_0202C5F0(p);
}

void func_0202C588(void *p, u32 v)
{
    func_0202C710(p, v);
}

void *func_0202C590(u32 heapId)
{
    return func_02030734(heapId, 0xc, 0, g_020A7780, 0x115);
}

/*
 * An unlabelled leaf sitting inside sub_0202C590's own literal pool
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md): a
 * pool-word-and-bx tail call into the ARM SDK function ENV_SetResourceSet
 * (docs/idioms/a-veneer-call-is-an-ordinary-extern-at-the-veneer-address.md
 * covers the shape, though this is a genuine tail call rather than a
 * linker veneer). Reached only through sub_0202C548's own
 * pool-word-and-bx tail call.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202C5AC.c \
 *       --func func_0202C5AC --addr 0x0202C5AC --cc 1.1p1 --thumb
 */
u32 func_0202C5AC(void *p)
{
    return func_020307B0(p);
}

void func_0202C5B4(struct Counter0202C5B4 *p)
{
    p->unk00 = 1;
    p->unk04 = 0;
    p->unk06 = 0;
    p->unk08 = 0;
}

/*
 * An unlabelled leaf, six bytes padded to eight, sitting between
 * sub_0202C5B4's trailing padding and func_0202C5CC's label
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md): a plain
 * two-field setter with no prologue at all, reached only through
 * sub_0202C550's pool-word-and-bx tail call.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202C5C4.c \
 *       --func func_0202C5C4 --addr 0x0202C5C4 --cc 1.1p1 --thumb
 */
u32 func_0202C5C4(struct Obj0202C5C4 *p, u16 a, u16 b)
{
    p->unk06 = a;
    p->unk08 = b;
}

void func_0202C5CC(struct Counter0202C5B4 *p)
{
    p->unk04 = p->unk04 + 1;
    if (p->unk06 < p->unk04) {
        p->unk04 = p->unk06;
    }
}

u32 func_0202C5E0(struct Counter0202C5B4 *p)
{
    if (p->unk06 > p->unk04) {
        return 0;
    }
    return 1;
}

void func_0202C5F0(void *p)
{
    switch (func_0202C6B8(p)) {
    case 0:
        func_0202C630(p);
        break;
    case 1:
        func_0202C634(p);
        break;
    case 2:
        func_0202C638(p);
        break;
    case 3:
        func_0202C654(p);
        break;
    }
}

void func_0202C630(void *p)
{
}

void func_0202C634(void *p)
{
}

u32 func_0202C638(void *p)
{
    func_0202C5CC(p);
    if (func_0202C5E0(p) == 1) {
        func_0202C6BC(p, 0);
    }
}

u32 func_0202C654(void *p)
{
    func_0202C5CC(p);
    if (func_0202C5E0(p) == 1) {
        func_0202C6BC(p, 1);
    }
}

u32 func_0202C670(void *p)
{
    if (func_0202C72C(p) != 1) {
        func_0202C6BC(p, 2);
    }
}

u32 func_0202C688(void *p)
{
    if (func_0202C760(p) != 1) {
        func_0202C6BC(p, 3);
    }
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * Two unlabelled leaves, back to back
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md): each is a
 * three-instruction, six-byte forwarding call with a literal second
 * argument, padded to eight with a `nop` and its own pool word. Reached
 * only through sub_0202C570 and sub_0202C578's pool-word-and-bx tail
 * calls (src/matched/unit_0202C548.c). Neither carries a
 * register-saving prologue, so neither is in the worklist's function
 * list; both sit exactly between func_0202C688's last instruction and
 * sub_0202C6B8's label.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202C6A0.c \
 *       --addr 0x0202C6A0 --thumb
 */
u32 func_0202C6A0(void *p)
{
    return (u32)func_0202C6BC(p, 0);
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * Two unlabelled leaves, back to back
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md): each is a
 * three-instruction, six-byte forwarding call with a literal second
 * argument, padded to eight with a `nop` and its own pool word. Reached
 * only through sub_0202C570 and sub_0202C578's pool-word-and-bx tail
 * calls (src/matched/unit_0202C548.c). Neither carries a
 * register-saving prologue, so neither is in the worklist's function
 * list; both sit exactly between func_0202C688's last instruction and
 * sub_0202C6B8's label.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202C6A0.c \
 *       --addr 0x0202C6A0 --thumb
 */
u32 func_0202C6AC(void *p)
{
    return (u32)func_0202C6BC(p, 1);
}

u32 func_0202C6B8(struct Obj0202C6B8 *p)
{
    return p->unk00;
}

struct Obj0202C6B8 *func_0202C6BC(struct Obj0202C6B8 *p, u32 v)
{
    p->unk00 = v;
    p->unk04 = 0;
    return p;
}

s32 func_0202C6C4(struct Counter0202C5B4 *p)
{
    s32 v;

    switch (func_0202C6B8((struct Obj0202C6B8 *)p)) {
    case 0:
        return 0x7F;
    case 1:
        return 0;
    case 2:
        v = p->unk04 * 0x7F / p->unk06;
        break;
    case 3:
        v = 0x7F - p->unk04 * 0x7F / p->unk06;
        break;
    }
    return v;
}

void func_0202C710(struct Counter0202C5B4 *p, s32 n)
{
    func_02005F24(p->unk08, n * func_0202C6C4(p) / 0x7F);
}

u32 func_0202C72C(void *p)
{
    switch (func_0202C6B8(p)) {
    case 0:
        return 1;
    case 1:
        return 0;
    case 2:
        return 1;
    case 3:
        return 0;
    }
    return 0;
}

u32 func_0202C760(void *p)
{
    switch (func_0202C6B8(p)) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 0;
    case 3:
        return 1;
    }
    return 0;
}

/*
 * note:     wave 16: promoted.  0x021647E8 is the unlabelled ov010 tail-call
 *           thunk matched in src/matched/func_021647E8.c (`matched, overlay`
 *           under the ov010 hint); 0x0202C8B8 now resolves as `matched`.
 *
 * A chain of four probes, each returning a u8 reason code unless it comes
 * back 0xffff ("nothing to say"); the sentinel is kept in a callee-saved
 * register, which is why it is one pool word and four `cmp r0, r7`.
 */
u32 func_0202C794(void *a0, u32 a1)
{
    u32 ctx = (u32)func_020120F4(a0);
    u32 saved = func_0201297C((const struct BigObj *)ctx);
    u32 r;

    r = func_0215E6A8((void *)ctx, (u16)a1);
    if (r != 0xffff) {
        return (u8)r;
    }
    r = func_0202C8B8(a0, ctx, a1);
    if (r != 0xffff) {
        return (u8)r;
    }
    r = func_0202C934(a0, ctx, a1);
    if (r != 0xffff) {
        return (u8)r;
    }
    r = func_0202C970(a0, (void *)ctx, a1);
    if (r != 0xffff) {
        return (u8)r;
    }
    if (func_0202C824(ctx) != 0) {
        return (u8)func_021647E8((void *)saved, (u16)a1);
    }
    return (u8)func_02013C10((u16)a1);
}

int func_0202C824(int a0){ int t0, t1; t0 = func_02012984(a0); t1 = func_0202E888((int)t0); if ((unsigned int)((t0 + 0)) == (unsigned int)(t1)) {  return 1; } else {  return 0; } }

void func_0202C83C(struct Ctx *p, u32 a1)
{
    struct BigObj *obj = func_020120F4(p);
    u32 r = func_0202C794(p, a1);

    func_020129A0(obj, (u8)r);
}

/*
 * note:     2026-09-23 (wave 15): EXACT with no C change; the ov010 call
 *           at +0x34 now resolves sole-ref/code.  The MATCH text below is history.
 *
 * Blocked at MATCH on the `label`/`matched` classes: all 82 concrete bytes
 * are correct (88-byte extent, the last 6 bytes being the pool word 0xffff),
 * but the PC-relative call at +0x0034 to func_0215E6F8 in ov010 has no
 * witness: 0x0215E6F8 has exactly one branch reference image-wide and it is
 * that call, so no cut frees it, and the address is inside BOTH ov009's and
 * ov010's windows, so the `label` class refuses it even with the ov010 hint
 * on the symbols: line.  The unblock is a `matched` entry at 0x0215E6F8
 * (or any additional caller of it anywhere in the image).
 *
 * The range check must wrap in 32 bits: `(u32)(r - 6) > 1`, `(r - 6) > 1u`
 * and `(unsigned)(r - 6) > 1` all give the original's bare
 * `subs r0, r1, #6; cmp r0, #1; bhi`.  The u16-cast spelling
 * `(u16)(r - 6) > 1` is wrong by two instructions: it re-truncates the
 * difference with `lsls r0, r0, #0x10; lsrs r0, r0, #0x10` first.
 *
 * The first call takes the actor pointer as well as the truncated id,
 * `func_0215E6A8(a0, (u16)a1)`: r0 is still r0 at the call and the id is
 * built in r1.  Declaring it as a one-argument call puts the id in r0 and
 * shifts the whole prologue.
 */
void func_0202C860(u8 *a0, int a1)
{
    u32 v;
    u16 r;

    v = func_0215E6A8(a0, (u16)a1);
    r = (u16)(u32)func_02012994((const struct BigObj *)a0);
    if (v != 0xffff) {
        func_020129A0((struct BigObj *)a0, (u8)v);
        return;
    }
    if ((u32)(r - 6) > 1) {
        return;
    }
    if (func_0215E6F8((int)a0) != 1) {
        return;
    }
    func_020129A0((struct BigObj *)a0, (u8)func_02013C10((u16)a1));
}

/*
 * The two ABS32 pool words holding 0x0209FFF4 / 0x0209FFF6 are both inside
 * this function; grep over asm/ finds no third pool word anywhere in the
 * image, so the data table has no witness outside the compared range and
 * both relocation sites stay wildcarded. Unstuck by any other function that
 * also points at gTbl_0209FFF4, or by a data-symbol table entry.
 */
s32 func_0202C8B8(void *a0, u32 a1, u32 a2)
{
    u32 r6;
    u32 r4;
    u32 i;

    r6 = func_0201296C((const struct BigObj *)a1);
    r4 = func_02012138(a0);
    if (func_02013D74((u16)a2) == 0 || r4 == 0) {
        goto done;
    }
    for (i = 0; i < 0x19; i++) {
        if (a2 == gTbl_0209FFF4[i].a) {
            if (func_020142E8((void *)r6, gTbl_0209FFF4[i].b) == 0) {
                if (func_0215843C(r4) == 0x14) return 0xd;
                return 0xe;
            }
            if (func_0215843C(r4) == 0x14) return 0xa;
            return 0xb;
        }
    }
done:
    return 0xffff;
}

s32 func_0202C934(void *a0, u32 a1, u32 a2)
{
    u32 r = func_0201296C((const struct BigObj *)a1);

    if (a2 == 0x151) {
        if (func_020142E8((void *)r, 0x96f) != 0) {
            if (func_020111E8() == 0x15) return 7;
            return 6;
        }
    }
    return 0xffff;
}

u32 func_0202C970(void *a, void *b, u32 c)
{
    u8 buf[2];
    struct RtcDate date;

    if (!func_02014044((u16)c)) {
        goto fail;
    }
    func_0203F4E4(&date);
    func_0202EB60(&buf[1], &buf[0]);
    if (date.month != buf[1]) {
        goto fail;
    }
    if (date.day != buf[0]) {
        goto fail;
    }
    return 0;

fail:
    return 0xFFFF;
}

/*
 * TU: bgwinfrm.c (__FILE__ 0x020A7790, lines 0x56 and 0x5d).
 */
struct WinMgr *func_0202C9B4(u32 a0, u32 a1, u32 heap)
{
    struct WinMgr *p;

    p = func_02030734(heap, sizeof(struct WinMgr), 0, bgwinfrm_File, 0x56);
    p->count = a1;
    p->heap = heap;
    p->mode = a0;
    p->flag = 0;
    p->wins = func_02030734(heap, a1 << 4, 1, bgwinfrm_File, 0x5d);

    return p;
}

void func_0202CA0C(struct WinMgr *obj)
{
    u32 i;

    for (i = 0; i < obj->count; i++) {
        if (obj->wins[i].tiles != 0) {
            func_020307B0(obj->wins[i].tiles);
        }
    }
    func_020307B0(obj->wins);
    func_020307B0(obj);
}

/*
 * Initialises one 16-byte window record: allocates w*h*2 bytes of tile
 * storage from the debug allocator on the manager's own heap id, then
 * writes the two 6-bit size bitfields, the bg index, the scroll pair, the
 * dirty bit and the default clip box (0, 0x20, 0, 0x18).  Same struct Win
 * as src/matched/sub_0202CAC4.c and src/matched/func_0202CDD4.c.
 *
 * The __FILE__ pool word 0x020A7790 spells "bgwinfrm.c"
 * (layout/file_anchors.txt line 119), which names this unit's source file.
 */
void func_0202CA3C(struct WinMgr *mgr, u32 idx, u32 bg, u32 w, u32 h)
{
    struct Win *win = &mgr->wins[idx];

    win->tiles = func_02030734((u16)mgr->heap, w * h * 2, 1,
                                    str_020A7790, 0x8a);
    win->w = (u16)w;
    win->h = (u16)h;
    win->bg = (u8)bg;
    win->x = 0;
    win->y = 0;
    win->unk04_13 = 0;
    win->dirty = 1;
    win->xmin = 0;
    win->xmax = 0x20;
    win->ymin = 0;
    win->ymax = 0x18;
}

void func_0202CAC4(struct WinMgr *mgr, u32 idx, const void *src)
{
    MIi_CpuCopy16(src, (void *)mgr->wins[idx].tiles,
                  mgr->wins[idx].w * mgr->wins[idx].h * 2);
}

void func_0202CAE4(struct WinMgr *mgr, u32 idx, u32 arc, u32 member, u32 alloc)
{
    void *buf;
    void *res;

    res = func_02049EB4(arc, member, alloc, (u32)(&buf), mgr->heap);
    func_0202CAC4(mgr, idx, (char *)buf + 0xc);
    func_020307B0(res);
}

void func_0202CB18(struct WinMgr *mgr, u32 idx, void *arc, u32 member, u32 alloc)
{
    void *buf;
    void *res;

    res = func_02049EF4(arc, member, alloc, &buf, mgr->heap);
    func_0202CAC4(mgr, idx, (char *)buf + 0xc);
    func_020307B0(res);
}

void func_0202CB4C(struct WinMgr *mgr, u32 idx, s8 x, s8 y)
{
    struct Win *win = &mgr->wins[idx];
    u8 sx, ow, ox;
    u8 sy, oh, oy;
    s32 x1, y1;

    win->x = x;
    win->y = y;
    if (x >= win->xmax) {
        return;
    }
    if (y >= win->ymax) {
        return;
    }
    x1 = x + win->w;
    if (x1 < win->xmin) {
        return;
    }
    y1 = y + win->h;
    if (y1 < win->ymin) {
        return;
    }

    sx = x;
    ow = win->w;
    ox = 0;
    if (x < win->xmin) {
        sx = win->xmin;
        ox = win->xmin - x;
        ow = ow - ox;
    }
    if (x1 >= win->xmax) {
        ow = ow - (u8)(x1 - win->xmax);
    }

    sy = y;
    oh = win->h;
    oy = 0;
    if (y < win->ymin) {
        sy = win->ymin;
        oy = win->ymin - y;
        oh = oh - oy;
    }
    if (y1 >= win->ymax) {
        oh = oh - (u8)(y1 - win->ymax);
    }

    func_020410D0(win->bg, sx, sy, ow, oh, win->tiles, ox, oy, win->w, win->h);
    g_020A0058[mgr->mode](win->bg);
    win->dirty = 0;
}

void func_0202CC58(struct WinMgr *mgr, u32 idx)
{
    func_0202CB4C(mgr, idx, mgr->wins[idx].x, mgr->wins[idx].y);
}

/*
 * bgwinfrm.c.  Marks a window record dirty, rejects it when it lies wholly
 * outside its clip box (xmin..xmax, ymin..ymax), clips the origin and the
 * size against the box, then blits it through func_02041300 and runs the
 * manager's mode callback.  Same struct Win as src/matched/func_0202CD64.c.
 *
 * What closed it (wave 19): four spelling choices, all required.
 *  - xmax is a named local; the first guard and the right-edge clip read it.
 *  - sx = win->x is written before ow = w, so the sx spill store lands
 *    ahead of ow's sign extension.
 *  - sy is s8: it only ever holds win->y or win->ymin, both s8 fields, so
 *    the narrow type is value-preserving.  With s32 sy the clip copies ymin
 *    between registers; with s8 sy it reloads ymin from its spill slot, as
 *    the image does, and the call's argument stores fall into order.
 *  - Declarations with oh first and sy last.  mwcc numbers spill slots from
 *    the last declared local upward, so sx, h, y, sy must keep that relative
 *    order (slots 0x20, 0x1c, 0x18, 0x14).
 * The callee prototype is the one func_02041300's own body declares.
 */
void func_0202CC70(struct WinMgr *mgr, u32 idx)
{
    struct Win *win = &mgr->wins[idx];
    s8 oh, ow;
    s32 sx;
    s32 w, h;
    s32 x1, xmax;
    s32 y, y1;
    s8 sy;

    win->dirty = 1;
    xmax = win->xmax;
    if (win->x >= xmax) {
        return;
    }
    if (win->y >= win->ymax) {
        return;
    }
    w = win->w;
    x1 = win->x + w;
    if (x1 < win->xmin) {
        return;
    }
    h = win->h;
    sy = win->y;
    y = sy;
    y1 = y + h;
    if (y1 < win->ymin) {
        return;
    }

    sx = win->x;
    ow = w;
    if (win->x < win->xmin) {
        sx = win->xmin;
        ow = ow - (s8)(win->xmin - win->x);
    }
    if (x1 >= xmax) {
        ow = ow - (s8)(x1 - xmax);
    }

    oh = h;
    if (sy < win->ymin) {
        sy = win->ymin;
        oh = oh - (s8)(win->ymin - y);
    }
    if (y1 >= win->ymax) {
        oh = oh - (s8)(y1 - win->ymax);
    }

    func_02041300(win->bg, 0, (u8)sx, (u8)sy, (u8)ow, (u8)oh, 0x10);
    g_020A0058[mgr->mode](win->bg);
}

/*
 * bgwinfrm.c.  Arms the scroll animation on one window record: stores the
 * per-frame delta pair and the frame count, sets the 3-bit unk04_13 field
 * to 1, and raises the manager's top bit at offset 6.  Same struct Win as
 * src/matched/func_0202CDD4.c, same struct WinMgr as
 * src/matched/sub_0202CB4C.c.
 */
void func_0202CD64(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames)
{
    struct Win *win = &mgr->wins[idx];

    win->dx = dx;
    win->dy = dy;
    win->frames = frames;
    win->unk04_13 = 1;
    mgr->flag = 1;
}

void func_0202CD94(struct WinMgr *mgr)
{
    u32 i;

    if (!mgr->flag) return;
    mgr->flag = 0;
    for (i = 0; i < mgr->count; i++) {
        if (func_0202CDD4(mgr, i) == 1) mgr->flag = 1;
    }
}

u32 func_0202CDD4(struct WinMgr *mgr, u32 idx)
{
    if (mgr->wins[idx].unk04_13 == 0) {
        return 0;
    }

    func_0202CC70(mgr, idx);
    mgr->wins[idx].x = mgr->wins[idx].x + mgr->wins[idx].dx;
    mgr->wins[idx].y = mgr->wins[idx].y + mgr->wins[idx].dy;
    func_0202CC58(mgr, idx);
    mgr->wins[idx].frames = mgr->wins[idx].frames - 1;
    if (mgr->wins[idx].frames == 0) {
        mgr->wins[idx].unk04_13 = 0;
        return 0;
    }
    return 1;
}

u32 func_0202CE40(struct WinMgr *mgr, u32 idx)
{
    return mgr->wins[idx].unk04_13;
}

void func_0202CE50(struct WinMgr *mgr, u32 idx, s32 x, s32 y,
                   u8 w, u8 h, u8 pal)
{
    u16 *tiles = mgr->wins[idx].tiles;
    u32 stride = mgr->wins[idx].w;
    s32 yend = y + h;
    s32 i;

    if (y < yend) {
        u32 bits = pal << 12;
        s32 xend = x + w;

        do {
            for (i = x; i < xend; i = (u16)(i + 1)) {
                tiles[y * stride + i] = (tiles[y * stride + i] & 0x0fff)
                                      | bits;
            }
            y = (u16)(y + 1);
        } while (y < yend);
    }
}

void func_0202CEBC(struct WinMgr *mgr, u32 idx, void *a)
{
    u16 *tiles = mgr->wins[idx].tiles;
    u32 stride = mgr->wins[idx].w;
    u32 row;
    u32 oy;
    u32 ox;
    u32 bits;
    u16 *dst;
    s32 ch;
    u32 base;
    s32 cw;

    base = func_02045768(a);
    bits = ((u32)func_02045778(a) << 0x1c) >> 0x10;
    cw = func_02045738(a);
    ch = func_02045740(a);
    ox = func_02045758(a);
    oy = func_02045760(a);
    row = 0;

    if (ch > 0) {
        dst = tiles + ox;

        do {
            s32 y = oy + row;
            s32 col;

            if (y >= mgr->wins[idx].h) {
                break;
            }
            col = 0;
            if (cw > 0) {
                u16 *line = dst + stride * y;

                do {
                    if ((s32)(ox + col) >= (s32)mgr->wins[idx].w) {
                        break;
                    }
                    line[col] = bits + (base + col);
                    col = (u16)(col + 1);
                } while (col < cw);
            }
            base = (u16)(base + cw);
            row = (u16)(row + 1);
        } while ((s32)row < ch);
    }
}

/*
 * bgwinfrm.c window-record accessors, 0x0202CF84..0x0202D01A: tile
 * pointer, bg index, scroll pair, the two 6-bit size bitfields, the clip
 * box setter and one empty function.  Same struct Win as
 * src/matched/func_0202CDD4.c.  All leaves; the unit calls nothing.
 */
u16 *func_0202CF84(struct WinMgr *mgr, u32 idx)
{
    return mgr->wins[idx].tiles;
}

/*
 * bgwinfrm.c window-record accessors, 0x0202CF84..0x0202D01A: tile
 * pointer, bg index, scroll pair, the two 6-bit size bitfields, the clip
 * box setter and one empty function.  Same struct Win as
 * src/matched/func_0202CDD4.c.  All leaves; the unit calls nothing.
 */
u8 func_0202CF8C(struct WinMgr *mgr, u32 idx)
{
    return mgr->wins[idx].bg;
}

/*
 * bgwinfrm.c window-record accessors, 0x0202CF84..0x0202D01A: tile
 * pointer, bg index, scroll pair, the two 6-bit size bitfields, the clip
 * box setter and one empty function.  Same struct Win as
 * src/matched/func_0202CDD4.c.  All leaves; the unit calls nothing.
 */
void func_0202CF98(struct WinMgr *mgr, u32 idx, s8 *x, s8 *y)
{
    if (x != 0) {
        *x = mgr->wins[idx].x;
    }
    if (y != 0) {
        *y = mgr->wins[idx].y;
    }
}

/*
 * bgwinfrm.c window-record accessors, 0x0202CF84..0x0202D01A: tile
 * pointer, bg index, scroll pair, the two 6-bit size bitfields, the clip
 * box setter and one empty function.  Same struct Win as
 * src/matched/func_0202CDD4.c.  All leaves; the unit calls nothing.
 */
void func_0202CFC0(struct WinMgr *mgr, u32 idx, u16 *w, u16 *h)
{
    if (w != 0) {
        *w = mgr->wins[idx].w;
    }
    if (h != 0) {
        *h = mgr->wins[idx].h;
    }
}

void func_0202CFEC(struct WinMgr *mgr, u32 idx, s8 xmin, s8 xmax,
                   s8 ymin, s8 ymax)
{
    mgr->wins[idx].xmin = xmin;
    mgr->wins[idx].xmax = xmax;
    mgr->wins[idx].ymin = ymin;
    mgr->wins[idx].ymax = ymax;
}

/*
 * bgwinfrm.c window-record accessors, 0x0202CF84..0x0202D01A: tile
 * pointer, bg index, scroll pair, the two 6-bit size bitfields, the clip
 * box setter and one empty function.  Same struct Win as
 * src/matched/func_0202CDD4.c.  All leaves; the unit calls nothing.
 */
void func_0202D018(void)
{
}

u8 func_0202D01C(u32 a, u32 b, u32 c)
{
    u8 res = (a * c) / b;

    if (res != 0 || a == 0) {
        return res;
    }
    return 1;
}

int func_0202D034(u32 a, u32 b)
{
    a <<= 8;
    b <<= 8;

    if (a > b / 2) {
        return 0;
    }
    if (a > b / 5) {
        return 1;
    }
    if (a != 0) {
        return 2;
    }
    return 3;
}

int func_0202D060(void){ return 4; }

/*
 * The two consecutive three-out-pointer wrappers around the 13-argument
 * text/window measurement routine at 0x0202D4A8, folded into one
 * translation unit. The first sets the trailing flag to one and returns the
 * plain sum of the three accumulators; the second leaves every flag zero
 * and adds two.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202D064.c \
 *       --addr 0x0202D064 --cc 1.1p1 --thumb
 */
s32 func_0202D064(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7)
{
    s32 b;
    s32 a;
    s32 c;

    func_0202D4A8((void *)a0, a1, a2, a3, s5, s6, s7, (u32 *)(&b), (u32 *)(&a), (u32 *)(&c), 0, 0, 1);
    return c + (b + a);
}

/*
 * The two consecutive three-out-pointer wrappers around the 13-argument
 * text/window measurement routine at 0x0202D4A8, folded into one
 * translation unit. The first sets the trailing flag to one and returns the
 * plain sum of the three accumulators; the second leaves every flag zero
 * and adds two.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202D064.c \
 *       --addr 0x0202D064 --cc 1.1p1 --thumb
 */
s32 func_0202D09C(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7)
{
    s32 b;
    s32 a;
    s32 c;

    func_0202D4A8((void *)a0, a1, a2, a3, s5, s6, s7, (u32 *)(&b), (u32 *)(&a), (u32 *)(&c), 0, 0, 0);
    return c + (b + a + 2);
}

/*
 * One of a family of thin wrappers around the 13-argument text/window
 * measurement routine at 0x0202D4A8: it forwards its own three stack
 * arguments, hands the callee out-pointers for two width accumulators and
 * a status word, and folds the results into a single returned extent.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202D0D4.c \
 *       --func func_0202D0D4 --addr 0x0202D0D4 --cc 1.1p1 --thumb
 */
s32 func_0202D0D4(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7)
{
    s32 b;
    s32 a;
    s32 r;

    r = 0;
    func_0202D4A8((void *)a0, a1, a2, a3, s5, s6, s7, (u32 *)(&b), 0, 0, (u32 *)(&a), (u32 **)(&r), 0);
    if (r == 0) {
        r = b + 0x12 + a;
    }
    return r;
}

/*
 * The three consecutive wrappers around the 13-argument text/window
 * measurement routine at 0x0202D4A8, folded into one translation unit.
 * Each forwards its three stack arguments, hands the callee two
 * out-pointers and returns their sum plus a per-function constant
 * (4, 5, 6).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202D110.c \
 *       --addr 0x0202D110 --cc 1.1p1 --thumb
 */
s32 func_0202D110(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7)
{
    s32 b;
    s32 a;

    func_0202D4A8((void *)a0, a1, a2, a3, s5, s6, s7, (u32 *)(&b), (u32 *)(&a), 0, 0, 0, 0);
    return b + a + 4;
}

/*
 * The three consecutive wrappers around the 13-argument text/window
 * measurement routine at 0x0202D4A8, folded into one translation unit.
 * Each forwards its three stack arguments, hands the callee two
 * out-pointers and returns their sum plus a per-function constant
 * (4, 5, 6).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202D110.c \
 *       --addr 0x0202D110 --cc 1.1p1 --thumb
 */
s32 func_0202D144(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7)
{
    s32 b;
    s32 a;

    func_0202D4A8((void *)a0, a1, a2, a3, s5, s6, s7, (u32 *)(&b), (u32 *)(&a), 0, 0, 0, 0);
    return b + a + 5;
}

/*
 * The three consecutive wrappers around the 13-argument text/window
 * measurement routine at 0x0202D4A8, folded into one translation unit.
 * Each forwards its three stack arguments, hands the callee two
 * out-pointers and returns their sum plus a per-function constant
 * (4, 5, 6).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202D110.c \
 *       --addr 0x0202D110 --cc 1.1p1 --thumb
 */
s32 func_0202D178(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7)
{
    s32 b;
    s32 a;

    func_0202D4A8((void *)a0, a1, a2, a3, s5, s6, s7, (u32 *)(&b), (u32 *)(&a), 0, 0, 0, 0);
    return b + a + 6;
}

/*
 * The two consecutive wrappers around the 13-argument text/window
 * measurement routine at 0x0202D4A8, folded into one translation unit.
 * Each forwards its three stack arguments, hands the callee two
 * out-pointers and returns their sum plus a per-function constant
 * (7, 8).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202D1AC.c \
 *       --addr 0x0202D1AC --cc 1.1p1 --thumb
 */
s32 func_0202D1AC(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7)
{
    s32 b;
    s32 a;

    func_0202D4A8((void *)a0, a1, a2, a3, s5, s6, s7, (u32 *)(&b), (u32 *)(&a), 0, 0, 0, 0);
    return b + a + 7;
}

/*
 * The two consecutive wrappers around the 13-argument text/window
 * measurement routine at 0x0202D4A8, folded into one translation unit.
 * Each forwards its three stack arguments, hands the callee two
 * out-pointers and returns their sum plus a per-function constant
 * (7, 8).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202D1AC.c \
 *       --addr 0x0202D1AC --cc 1.1p1 --thumb
 */
s32 func_0202D1E0(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7)
{
    s32 b;
    s32 a;

    func_0202D4A8((void *)a0, a1, a2, a3, s5, s6, s7, (u32 *)(&b), (u32 *)(&a), 0, 0, 0, 0);
    return b + a + 8;
}

void func_0202D214(void *p, u32 v)
{
    u8 *base = *(u8 * *)&((struct Obj13942 *)p)->f14;
    u8 *buf;
    u32 size;
    int i;
    u32 off;

    buf = func_02030734((u16)((v & 0x7fff) | 0x8000), 0x1200, 1, str_020A77AC, 0x100);
    MIi_CpuCopyFast(base, buf, 0x1200);

    size = 0x180;
    off = 0;
    for (i = 0; i < 8; i++) {
        MIi_CpuCopyFast(buf + off, base + i * size, 0x100);
        off += 0x100;
    }
    for (i = 0; i < 8; i++) {
        MIi_CpuCopyFast(buf + off, base + (i * 12 + 8) * 32, 0x80);
        off += 0x80;
    }

    for (i = 0; i < 4; i++) {
        MIi_CpuCopyFast(buf + off, base + (i * size + 0xc00), 0x100);
        off += 0x100;
    }
    for (i = 0; i < 4; i++) {
        MIi_CpuCopyFast(buf + off, base + (i * 12 + 0x68) * 32, 0x80);
        off += 0x80;
    }
    func_020307B0(buf);
}

void func_0202D2EC(u32 *obj, u32 heap)
{
    u8 *dst;
    u8 *buf;
    s32 i;
    s32 off;

    dst = (u8 *)obj[5];
    buf = (u8 *)func_02030734((u16)((heap & 0x7fff) | 0x8000), 0x1200,
                              1, sFile_020A77AC, 313);
    MIi_CpuCopyFast(dst, buf, 0x1200);

    off = 0;
    for (i = 0; i < 8; i++) {
        MIi_CpuCopyFast(buf + i * 0x180, dst + off, 0x100);
        off += 0x100;
    }
    for (i = 0; i < 8; i++) {
        MIi_CpuCopyFast(buf + (i * 12 + 8) * 32, dst + off, 0x80);
        off += 0x80;
    }
    for (i = 0; i < 4; i++) {
        MIi_CpuCopyFast(buf + (0xc00 + i * 0x180), dst + off, 0x100);
        off += 0x100;
    }
    for (i = 0; i < 4; i++) {
        MIi_CpuCopyFast(buf + (i * 12 + 0x68) * 32, dst + off, 0x80);
        off += 0x80;
    }
    func_020307B0(buf);
}

/*
 * pokegra.c (wave 13): stamp four shape tables into a 4bpp tile image.  For
 * each of the four 0xff-terminated (x, y) pair tables at 0x020A779C, offset
 * by the low nibble pair of a1 (minus 8 each, a1 then shifted down a byte per
 * table), locate the pixel's byte in a 12-tile-wide 8x8 tile layout and, when
 * its nibble is colour 1..3, move it to 6..8 (+5 low, +0x50 high).
 *
 * WHAT CLOSED IT (docs/notes/func_0202D3D0.c.txt: 216 against 216, 29 to 39
 * bytes out, "idx in r0 / v in r2" allocation never reached by sixteen
 * spellings, permuter flat): there is NO hoisted byte local.  Each arm reads
 * the pixel byte itself and updates it with a compound assignment,
 * `n = blob[idx] & 0xf0; if (...) blob[idx] += 0x50;`.  The compiler hoists
 * the common load itself, after the `x & 1` test, and that is the register
 * assignment the image has.  The note's "v read inside each arm" attempt
 * (212 bytes) wrote `v = blob[idx]` per arm; the compound `+=` is what makes
 * the two arms' loads identical expressions the compiler can merge.  The
 * quotient locals cx/cy (second pass) and `j = 0` above the terminator test
 * (first pass) stand.
 */
void func_0202D3D0(struct Obj0202D3D0 *obj, u32 a1)
{
    u8 *blob = obj->blob;
    int i;
    int j;
    const u8 *tab;
    s32 x, y, cx, cy, idx, n;

    for (i = 0; i < 4; i++) {
        tab = tile_tables[i];
        j = 0;
        if (tab[0] != 0xff) {
            s32 bx = (s32)(a1 & 0xf) - 8;
            s32 by = (s32)((a1 & 0xf0) >> 4) - 8;
            do {
                x = bx + (tab[j * 2] + 0x16);
                y = by + (tab[j * 2 + 1] + 0x10);
                cx = x / 8;
                cy = y / 8;
                idx = ((x % 8) + (y % 8) * 8 + (cx + cy * 12) * 64) / 2;
                if (x & 1) {
                    n = blob[idx] & 0xf0;
                    if (n >= 0x10 && n <= 0x30)
                        blob[idx] += 0x50;
                } else {
                    n = blob[idx] & 0xf;
                    if (n >= 1 && n <= 3)
                        blob[idx] += 5;
                }
                j++;
            } while (tab[j * 2] != 0xff);
        }
        a1 >>= 8;
    }
}

/*
 * pokegra.c: resolve a species/form/egg to its graphics archive index, the
 * shiny palette flag (0 or 9), the draw mode and base, checking the
 * narc for the gendered palette variant when mode 1 asks.
 *
 * The 4-byte residue that held through five lanes and 2320 permuter
 * compiles (docs/notes/func_0202D4A8.c.txt: the two spilled values got
 * sp+4/sp+8 the wrong way round) is a declaration: the 2-way shiny value
 * written to *out_pal is an enum, which changes where the frame allocator
 * puts its spill slot (docs/idioms/an-enum-type-keeps-values-out-of-constant-folding.md;
 * the permuter's `type` mutation only cycles integer types).  `case 1`
 * is written before `case 2`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202D4A8.c  *       --func func_0202D4A8 --addr 0x0202D4A8 --thumb --cc 1.1p1
 */
void func_0202D4A8(void *narc, u32 species, s32 form, s32 mode,
                   u32 base, u32 shiny, u32 egg,
                   u32 *out_index, u32 *out_pal, u32 *out_mode, u32 *out_base,
                   u32 **out_ptr, u32 female)
{
    s32 idx;
    s32 count;
    s32 first;
    s32 hidden;
    Pal mode2;
    s32 pal;

    idx = species * 0x14;

    if (shiny == 0) {
        mode2 = 0;
    } else {
        mode2 = 9;
    }

    if (female != 0) {
        if (shiny == 0) {
            pal = 0;
        } else {
            pal = 9;
        }
    } else {
        if (shiny == 0) {
            pal = 2;
        } else {
            pal = 0xb;
        }
    }

    if (egg != 0) {
        s32 t;

        if (species == 0x1ea) {
            t = 1;
        } else {
            t = 0;
        }
        idx = (t + 0x28a) * 0x14;
    } else if (form != 0) {
        first = (s32)func_02019C90((u16)species, 0, 0x1f);
        hidden = (s32)func_02019C90((u16)species, 0, 0x23);
        count = (s32)func_02019C90((u16)species, 0, 0x20);
        if (form >= count) {
            form = 0;
        }
        if (hidden != 0) {
            if (out_ptr != 0 && form != 0) {
                *out_ptr = (u32 *)(base + (u32)((first + form - 1) * 2 + 0x37ad));
            }
        } else if (form != 0) {
            idx = (first + form - 1) * 0x14 + 0x32f0;
        }
    }

    switch (mode) {
    case 0:
        break;
    case 1:
        count = func_020490A8((u32)narc, (u32)(idx + pal + 1));
        mode = 1;
        if (count == 0) {
            mode = 0;
        }
        break;
    case 2:
        mode = 0;
        break;
    default:
        break;
    }

    if (out_index != 0) {
        *out_index = (u32)idx;
    }
    if (out_pal != 0) {
        *out_pal = (u32)mode2;
    }
    if (out_mode != 0) {
        *out_mode = (u32)mode;
    }
    if (out_base != 0) {
        *out_base = base;
    }
}

u32 func_0202D5CC(u32 a)
{
    if (a != 0) {
        return 0x49;
    }
    return 0x48;
}

u32 func_0202D5D8(u32 id, u32 flags)
{
    u32 v;

    if (flags & 1) {
        v = (u8)id;
    } else if (id > 0x69) {
        v = 0;
    } else {
        v = sub_0202D5D8_Table[id];
    }
    return v * 8;
}

u32 func_0202D5F8(u32 id, u32 flags)
{
    u32 v;

    if (flags & 1) {
        v = (u8)id;
    } else if (id > 0x69) {
        v = 0;
    } else {
        v = sub_0202D5D8_Table[id];
    }
    return v * 8 + 1;
}

u32 func_0202D61C(u32 id, u32 flags)
{
    u32 v;

    if (flags & 1) {
        v = (u8)id;
    } else if (id > 0x69) {
        v = 0;
    } else {
        v = sub_0202D5D8_Table[id];
    }
    return v * 8 + 7;
}

u32 func_0202D640(u32 id, u32 flags)
{
    u32 v;

    if (flags & 1) {
        v = (u8)id;
    } else if (id > 0x69) {
        v = 0;
    } else {
        v = sub_0202D5D8_Table[id];
    }
    return v * 8 + 2;
}

u32 func_0202D664(u32 id, u32 flags)
{
    u32 v;

    if (flags & 1) {
        v = (u8)id;
    } else if (id > 0x69) {
        v = 0;
    } else {
        v = sub_0202D5D8_Table[id];
    }
    return v * 8 + 3;
}

u32 func_0202D688(u32 id, u32 flags)
{
    u32 v;

    if (flags & 1) {
        v = (u8)id;
    } else if (id > 0x69) {
        v = 0;
    } else {
        v = sub_0202D5D8_Table[id];
    }
    return v * 8 + 4;
}

u32 func_0202D6AC(u32 id, u32 flags)
{
    u32 v;

    if (flags & 1) {
        v = (u8)id;
    } else if (id > 0x69) {
        v = 0;
    } else {
        v = sub_0202D5D8_Table[id];
    }
    return v * 8 + 5;
}

u32 func_0202D6D0(u32 id, u32 flags)
{
    u32 v;

    if (flags & 1) {
        v = (u8)id;
    } else if (id > 0x69) {
        v = 0;
    } else {
        v = sub_0202D5D8_Table[id];
    }
    return v * 8 + 6;
}

/*
 * Unpacks a party mon into the nine-argument sprite request of
 * func_0202D760: species (5), form (0x6F), gender (0x6E), the shiny
 * predicate func_02017EB4, isEgg (0x4C) and the personality word (id 0)
 * are read in that order, then forwarded along with the caller's own
 * a2/a3 pass-throughs.
 */
void *func_0202D6F4(u32 *a0, void *mon, u32 a2, u16 a3)
{
    u32 species;
    u32 form;
    u32 gender;
    u32 shiny;
    u32 isEgg;

    species = func_02017E88(mon, 5, 0);
    form = func_02017E88(mon, 0x6F, 0);
    gender = func_02017E88(mon, 0x6E, 0);
    shiny = func_02017EB4(mon);
    isEgg = func_02017E88(mon, 0x4C, 0);
    return func_0202D760(a0, species, form, gender, shiny, a2, isEgg,
                         func_02017E88(mon, 0, 0), a3);
}

/*
 * Builds a sprite/resource request: func_0202D064 turns the mon
 * descriptor (species/form/gender plus the three stack words) into a
 * resource id, which func_02049E34 instantiates with the caller's
 * out-slot `a0` as its a3 payload.  When the species word a1 is the
 * sentinel 0x147 the freshly filled *a0 is additionally run through the
 * func_0202D214 / func_0202D3D0 / func_0202D2EC triple, which is why
 * `*a0` is re-read before each of them (func_0202D3D0 may store through
 * it, so the load cannot be cached).  This answers the open question in
 * docs/notes/func_0202D81C.c.txt: a0 is a genuine out-parameter, written
 * by func_02049E34 via its a3, not read-only.
 *
 * Blocked at MATCH: every concrete byte is identical.  2026-09-21, unblock
 * lane: ONE OF THE TWO BLOCKING SITES IS NOW CLEARED.  func_0202D2EC was
 * filed EXACT (src/matched/func_0202D2EC.c, shard arm9/pkt_0202D2EC.json),
 * so the +0x58 THM_CALL resolves `matched`.  Only +0x50, the call to
 * func_0202D3D0, is still wildcarded: this function is that address's only
 * caller image-wide, so no evidence class (label/matched) can attest it and
 * nothing but an EXACT at 0x0202D3D0 will promote this file.  That function
 * is a documented near miss, now at 29 concrete mismatches (down from 41)
 * and stuck on one register-assignment decision -- see
 * docs/notes/func_0202D3D0.c.txt, which records the lever that halved it
 * and the twelve spellings that do not move it further.
 */
void *func_0202D760(u32 *out, u32 a1, u32 a2, u32 a3,
                    u32 s0, u32 s1, u32 s2, u32 s3, volatile u16 s4)
{
    u32 id;
    void *res;

    id = func_0202D064(func_0202D060(), a1, a2, a3, s0, s1, s2);
    res = func_02049E34(func_0202D060(), id, 1, (u32)out, s4);
    if (a1 == 0x147) {
        func_0202D214((void *)(*out), s4);
        func_0202D3D0((struct Obj0202D3D0 *)(*out), s3);
        func_0202D2EC((u32 *)(*out), s4);
    }
    return res;
}

void *func_0202D7C8(u32 heap)
{
    return func_020490F4(func_0202D060(), heap);
}

int func_0202D7D8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7,
                   unsigned short a8, unsigned short a9)
{
    int t0 = func_0202D060();
    int t1 = func_0202D0D4(t0, a1, a2, a3, a4, a5, a6);
    return func_0204AC18((void *)a0, t1, a7, a8, 0, 1, a9);
}

/*
 * Issues a request through func_0204A6C8 built from a by-value tail struct
 * in the caller's frame (five words plus a u16 key at +0x14) and the
 * context func_0202D060()/func_0202D064() pair; when a1 is the sentinel
 * 0x147 it additionally runs the same tail through func_0202D760 with the
 * address of a local out-slot, hands that slot's word to func_0204A9D0
 * alongside the request handle, and releases func_0202D760's result through
 * func_020307B0. The request handle is returned either way.
 *
 * Three things the C has to say exactly, all found this session (the
 * earlier DIFF is docs/notes/func_0202D81C.c.txt):
 *   - the tail parameter must be `volatile`. Without it the front end
 *     re-homes the register arguments into the frame, grows `sub sp` from
 *     0x18 to 0x28 and 89 bytes differ.
 *   - the key sits at +0x14 of the tail, not +0x10: the struct carries five
 *     u32 words (s0..s4) ahead of it, and s4 is func_0204A6C8's own stack
 *     argument read from [sp,#0x40].
 *   - `k` and `v` must be separate named locals read in that order just
 *     before the func_0204A6C8 call. Passing `t.key`/`t.s4` inline (in
 *     either order, with or without a cast away from volatile, and with the
 *     stack arg typed u16) schedules `ldr r3,[sp,#0x40]` after the
 *     `movs r2,#1`/`str r0,[sp]` pair instead of before it: the last 6 bytes
 *     of the DIFF, and the only thing that moves them.
 *
 * The out-slot at sp+0x14 is real: func_0202D760 reads `*a0` three times and
 * never stores through it, so the `ldr r1,[sp,#0x14]` after the call reads
 * back an uninitialised local. That is what the original does; the note's
 * open question about a hidden write inside func_0202D760 is resolved as
 * "there is none, and the C does not need one".
 */
u32 func_0202D81C(u32 a0, u32 a1, u32 a2, u32 a3, volatile u32 s0, volatile u32 s1,
                  volatile u32 s2, volatile u32 s3, volatile u32 s4, volatile u16 key)
{
    u32 r;
    u32 h;
    u32 x;
    u32 k;
    u32 v;
    void *slot;

    x = func_0202D064(func_0202D060(), a1, a2, a3, s0, s1, s2);
    k = key;
    v = s4;
    h = func_0204A6C8((void *)a0, x, 1, v, k);
    if (a1 == 0x147) {
        r = (u32)func_0202D760((u32 *)(&slot), a1, a2, a3, s0, s1, s2, s3, key);
        func_0204A9D0(h, (struct Sub0204A9D0 *)((u32)slot));
        func_020307B0((void *)r);
    }
    return h;
}

/*
 * Builds a record out of an argument struct passed by value in the caller's
 * frame: both cursors come from func_02027710/func_02027714 on the same +8
 * word, the handle from func_020490F4 keyed on the +0x10 halfword with the
 * mode word from func_020275E4, and func_0204AF28 assembles the pair into
 * it; the handle is released before the assembled record is returned.
 *
 * The `volatile` on the by-value struct parameter is load-bearing, not
 * decoration: without it this front end proves the two callees cannot touch
 * the caller's frame, keeps args.w2 live in r5 across the first call and
 * drops the second `ldr r0,[sp,#0x20]`, and it also hoists the `ldrh` of
 * args.key above the inline func_020275E4() call. Qualifying the whole
 * parameter (rather than aliasing it through a volatile pointer, which
 * turns the two w2 loads into `[r5,#8]` and loses the `add r7,sp,#0x18`)
 * reproduces the reload, the argument scheduling and both `ldrh`s exactly.
 * See docs/notes/func_0202D898.c.txt for the DIFF this replaces.
 *
 * EXACT* only: the follower at 0x0202D8D0 is unlabelled, so the inferred
 * extent runs 2 bytes long over the alignment halfword. Never a byte
 * difference.
 */
u32 func_0202D898(u32 a0, u32 a1, u32 a2, u32 a3, volatile u32 w0, volatile u32 w1,
                  volatile u32 w2, volatile u32 w3, volatile u16 key)
{
    u32 p;
    u32 q;
    void *h;
    u32 r;

    p = func_02027710(w2);
    q = func_02027714(w2);
    h = func_020490F4(func_020275E4(), key);
    r = func_0204AF28(h, p, q, key);
    func_02049238(h);
    return r;
}

int func_0202D8D0(int a0, void *a1, int a2, int a3, unsigned short a8, unsigned short a9)
{
    int v1 = func_02017E88(a1, 5, 0);
    int v2 = func_02017E88(a1, 0x6f, 0);
    int v3 = func_02017E88(a1, 0x6e, 0);
    int v4 = func_02017EB4(a1);
    int v5 = func_02017E88(a1, 0x4c, 0);

    return func_0202D7D8(a0, v1, v2, v3, v4, a2, v5, a3, a8, a9);
}

int func_0202D934(int a0, void *a1, int a2, int a3, unsigned short a9)
{
    int v1 = func_02017E88(a1, 5, 0);
    int v2 = func_02017E88(a1, 0x6f, 0);
    int v3 = func_02017E88(a1, 0x6e, 0);
    int v_eb4 = func_02017EB4(a1);
    int v4 = func_02017E88(a1, 0x4c, 0);
    int v5 = func_02017E88(a1, 0, 0);

    return func_0202D81C(a0, v1, v2, v3, v_eb4, a2, v4, v5, a3, a9);
}

/*
 * Collects five properties off the handle (func_02017E88 with selectors 5,
 * 0x6f, 0x6e and 0x4c, plus func_02017EB4) and forwards them into
 * func_0202D898 together with this function's own three trailing words and
 * its u16 key, tail-position, returning what func_0202D898 returns.
 *
 * Arity note (this is what the earlier note was blocked on): func_0202D898
 * itself is written with a by-value `volatile struct Args` trailing
 * parameter, because that is the only shape that reproduces ITS body -- but
 * the caller must NOT be written that way. Declaring the extern with the
 * aggregate, and building it in a named local (volatile or not), makes the
 * front end materialise the struct in the frame and copy it out with
 * ldm/stm: `sub sp` grows 0x24 -> 0x38 and 49 bytes differ. A C99 compound
 * literal at the call site is worse still (zero-fills first, 77 bytes).
 * Spelling the same five trailing words as plain scalars in this
 * translation unit's own prototype writes them straight into the outgoing
 * block and is EXACT. The two spellings agree on the ABI, so both files are
 * correct about the boundary; only the callee's side needs the aggregate.
 *
 * EXACT* only: the follower at 0x0202DA04 is unlabelled, so the inferred
 * extent runs over the trailing alignment halfword. Never a byte difference.
 */
u32 func_0202D9A4(u32 h, u32 b1, u32 b2, u32 b3, u16 key)
{
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;

    v1 = func_02017E88((void *)h, 5, 0);
    v2 = func_02017E88((void *)h, 0x6f, 0);
    v3 = func_02017E88((void *)h, 0x6e, 0);
    v4 = func_02017EB4((void *)h);

    return func_0202D898(v1, v2, v3, v4,
                         b1, func_02017E88((void *)h, 0x4c, 0), b2, b3, key);
}

void *func_0202DA04(u32 heap)
{
    return func_020490F4(func_0202D5CC(0), heap);
}

s32 func_0202DA18(u32 a, u32 b, u32 c, u32 d, u16 e)
{
    return func_0204AC18((void *)a, func_0202D61C(b, 0), c, d, 0, 1, e);
}

void func_0202DA48(u32 a, u32 b, u32 c, u32 d)
{
    func_0204A6C8((void *)a, func_0202D5D8(b, 0), 1, c, d);
}

s32 func_0202DA6C(u32 a0, u32 a1, u32 a2, u16 a3)
{
    u32 p;
    u32 q;
    void *h;
    s32 r;

    p = func_02027718(a1);
    q = func_0202771C(a1);
    h = func_020490F4(func_020275E4(), a3);
    r = func_0204AF28(h, p, q, a3);
    func_02049238(h);
    return r;
}

/*
 * Loads two archived resources into a pair of consumers.  Each half
 * turns the caller's id into an archive entry index (func_0202D61C for
 * the first, func_0202D5D8 for the second), pulls the entry out of the
 * archive set named by the fifth, stack-passed u16 argument, hands the
 * unpacked payload to its consumer and then frees the container with
 * the common finalizer func_020307B0.
 *
 * The u16 fifth argument is re-read from the incoming argument area for
 * the second call rather than cached, so it is spelled as a `volatile
 * u16' stack parameter.
 */
void func_0202DAA4(void *set, u32 id, void *dstA, void *dstB, volatile u16 which)
{
    void *res;
    void *b;
    void *a;

    res = func_02049250(set, func_0202D61C(id, 0), which);
    func_02062A98(res, &b);
    func_0204ADEC(dstB, b, 1);
    func_020307B0(res);

    res = func_02049E74(set, func_0202D5D8(id, 0), 1, (u32)(&a), which);
    func_0204A9D0((int)dstA, a);
    func_020307B0(res);
}

/*
 * The PmsDraw constructor.  Closed 2026-09-23 from the 68-byte near miss
 * in docs/notes/pkt_0202DB0C.c.txt by two changes:
 *   - the second allocator's heap is a named u16 local read back from
 *     p->heap IMMEDIATELY after the store (`h = p->heap;`), so it is the
 *     same value as the strh operand and stays in r0 across the three
 *     field stores; `p->heap` written at the call re-reads it, the `heap`
 *     parameter makes it a callee-saved copy from the prologue;
 *   - the fifth parameter is u8 after all (`ldrb` at the func_0202DF68
 *     site); it only looked like it cost four bytes while the heap value
 *     was wrong.
 * The allocator result still has to go through a named local before p.
 */
struct PmsDraw *func_0202DB0C(u32 a, u32 b, u32 c, u32 d, u8 e0, u8 e1, u16 heap)
{
    struct PmsDraw *p;
    u32 n;
    u16 h;
    int i;
    struct PmsDraw *tmp = func_02030734(heap, 0x34, 1, s_pms_draw_c, 0x81);

    p = tmp;
    MI_CpuFill8(p, 0, 0x34);
    p->heap = heap;
    h = p->heap;
    p->unk08 = (void *)c;
    p->unk04 = d;
    p->count = e1;
    p->unk31 = 0xf;
    p->unk2c = 0;
    n = e1 * 0x28;
    p->elems = func_02030734(h, n, 1, s_pms_draw_c, 0x8c);
    MI_CpuFill8(p->elems, 0, n);
    p->res[0] = a;
    p->res[1] = b;
    p->unk24 = 0x11 << 6;
    func_0202DF68(p->res, e0, p->heap);
    for (i = 0; i < p->count; i++) {
        func_0202E09C(&p->elems[i], (struct Res *)p->res, p->heap);
    }
    return p;
}

/*
 * Picks the selected entry of the 0x28-byte element array hung off +0xc:
 * the selection at +0x28 is primed to 1, then every element whose +0x18
 * bit 0 is set is offered to func_0202E0E0 along with the two cursor
 * words at +8 and +0x2c; the first one that answers non-zero resets the
 * selection to 0.  The count at +0x30 is a signed char and is re-read at
 * the top of every iteration (the call may change it), which is what
 * keeps the `adds r0, r5, #0x30; ldrb` pair inside the loop -- 0x30 is
 * past the Thumb `ldrb` immediate reach of +31.
 */
void func_0202DBC4(struct PmsDraw *p)
{
    s32 i;

    p->selected = 1;
    for (i = 0; i < (s32)p->count; i++) {
        struct PmsElem *e = p->elems + i;
        if (e->flags.bits.b0 != 0) {
            if (func_0202E0E0(e, p->unk08, p->unk2c) != 0) {
                p->selected = 0;
            }
        }
    }
}

void func_0202DC08(struct PmsDraw *p)
{
    int i;

    for (i = 0; i < p->count; i++) {
        func_0202E0C8(p->elems + i);
    }

    func_020307B0(p->elems);
    func_0202DFD4((struct Res *)p->res);
    func_020307B0(p);
}

void func_0202DC48(u32 a, u32 b, u32 c, u32 d)
{
    u32 buf[2] = { 0, 0 };

    func_0202DC60((struct PmsDraw *)a, (void *)b, (void *)c, d, buf);
}

/*
 * The forwarding shim in front of func_0202E1F0: it copies four of the
 * object's own fields into the callee's five stack arguments and clears
 * the selection word at +0x28 afterwards.
 *
 * The ARGUMENT ORDER is what this function pins, and it corrects the
 * reading in docs/notes/pkt_0202E1F0.c.txt: r1 is the object pointer at
 * +8, r2 the word at +4 and r3 the caller's own `a`, which the prologue
 * parks in r4 (`adds r4, r1, #0`) precisely because it is consumed LAST.
 * Spelling the call (e, a, p->f08, p->f04, ...) instead leaves `a` in r1
 * and loses the r4 copy, four bytes short.
 *
 * The five stack words are four plain u32 arguments behind `w`, not a
 * 16-byte struct passed by value: a by-value struct makes the compiler
 * build a local and ldm/stm it into the outgoing area (18 bytes more),
 * whereas the original stores each field straight to its slot. The
 * halfword fields at +0x24, +0x31 and +0x00 are widened to words at the
 * call, so the parameters are u32.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0202DC60.c \
 *       --func func_0202DC60 --addr 0x0202DC60 --cc 1.1p1 --thumb
 */
void func_0202DC60(struct PmsDraw *p, void *a, void *w, u32 i, const void *e)
{
    func_0202E1F0(p->elems + i, p->unk08, p->unk04, a, w,
                  e, p->unk24, p->unk31, p->heap);
    p->selected = 0;
}

/*
 * Three leaves before func_0202DCC4 over an object with a count at +0x28 and
 * an array of 0x28-byte elements at +0xc: the count getter, and two
 * forwarders that pass element i and one argument to func_0202E38C and
 * func_0202E3E4.  Seeded from ov031 0x021F069A, ov110 0x021C0CC6, ov111
 * 0x021C61D2, ov216 0x021BD12A.
 *
 * Addresses are Black-image addresses.
 */
u32 func_0202DC98(struct PmsDraw *o)
{
    return o->selected;
}

/*
 * Three leaves before func_0202DCC4 over an object with a count at +0x28 and
 * an array of 0x28-byte elements at +0xc: the count getter, and two
 * forwarders that pass element i and one argument to func_0202E38C and
 * func_0202E3E4.  Seeded from ov031 0x021F069A, ov110 0x021C0CC6, ov111
 * 0x021C61D2, ov216 0x021BD12A.
 *
 * Addresses are Black-image addresses.
 */
void func_0202DC9C(struct PmsDraw *o, int i, u32 a1)
{
    func_0202E38C(&o->elems[i], a1);
}

/*
 * Three leaves before func_0202DCC4 over an object with a count at +0x28 and
 * an array of 0x28-byte elements at +0xc: the count getter, and two
 * forwarders that pass element i and one argument to func_0202E38C and
 * func_0202E3E4.  Seeded from ov031 0x021F069A, ov110 0x021C0CC6, ov111
 * 0x021C61D2, ov216 0x021BD12A.
 *
 * Addresses are Black-image addresses.
 */
void func_0202DCB0(struct PmsDraw *o, int i, u32 a1)
{
    func_0202E3E4(&o->elems[i], a1);
}

u32 func_0202DCC4(const struct PmsDraw *p, u32 i)
{
    return p->elems[i].flags.bits.b0;
}

void func_0202DCD4(struct PmsDraw *p, u32 i, u32 val)
{
    if (func_0202DCC4(p, i) != 0) {
        p->elems[i].flags.bits.b2 = val;
    }
}

void func_0202DCFC(struct PmsDraw *p, u32 i, u32 val)
{
    int k;

    for (k = 0; k < 2; k++) {
        func_0204B688(p->elems[i].actor[k], val);
    }
}

/*
 * Copies element i onto element j of the pms_draw owner, sprite state
 * included (docs/families/pms_draw.h). EXACT* only because the listing
 * extent runs on over the three unlabelled setters at 0x0202DE5C
 * (src/matched/unit_0202DE5C.c); the function itself is 310 bytes.
 *
 * Closed in wave 14 from the wave-12 note (8 bytes, dst/dy spill slots):
 *   - the handles are read through the element pointers, src->handle and
 *     dst->handle, not e[i]/e[j]; the compiler still folds them to the
 *     image's `ldr r0,[r6,r7]` / `ldr r0,[r6,dj]`, but dst now stays a
 *     named value and takes the image's slot sp+8;
 *   - no `e` local: src = &p->elems[i]; dst = &p->elems[j];
 *   - dx declared before dy (dx at sp+4, dy at sp+0);
 *   - the loop counter k declared FIRST: with src declared ahead of it,
 *     src takes r4 and the call temporaries/k take r5, the mirror image.
 */
void func_0202DD24(struct PmsDraw *p, u32 i, u32 j)
{
    int k;
    struct PmsElem *src;
    struct PmsElem *dst;
    s32 dx;
    s32 dy;
    u32 v;
    struct Pt_0202DD24 pt;
    void *h;

    src = &p->elems[i];
    dst = &p->elems[j];
    dx = func_02045758(dst->handle) - func_02045758(src->handle);
    dy = func_02045760(dst->handle) - func_02045760(src->handle);
    func_02043814((struct Bmp *)((u32)func_02045770((struct Descriptor *)src->handle)), (const struct Bmp *)((u32)func_02045770((struct Descriptor *)dst->handle)));
    h = dst->handle;
    func_02045334(h);
    func_02045374(h);
    func_02041B6C(func_02045730(h));

    for (k = 0; k < 2; k++) {
        v = func_0202E430(func_02045730(src->handle));
        func_0204B454(src->actor[k], (struct PtS *)&pt, (u16)v);
        pt.x += dx * 8;
        pt.y += dy * 8;
        func_0204B404(dst->actor[k], (const struct Vec2 *)(&pt), (u16)v);
        func_0204B878(dst->actor[k], func_0204B898(src->actor[k]));
        func_0204B3DC(dst->actor[k], src->enabled[k]);
    }
    dst->live = src->live;
    dst->flags.bits.b0 = src->flags.bits.b0;
    dst->flags.bits.b1 = src->flags.bits.b1;
    for (k = 0; k < 2; k++) {
        dst->enabled[k] = src->enabled[k];
    }
}

void func_0202DE5C(struct PmsDraw *p, u8 v)
{
    p->unk31 = v;
}

void func_0202DE64(struct PmsDraw *p, u16 v)
{
    p->unk24 = v;
}

void func_0202DE68(struct PmsDraw *p, u32 v)
{
    p->unk2c = v;
}

void func_0202DE6C(u32 a, u32 b, u32 c, const struct Pos0202DE6C *base,
                  struct Pos0202DE6C *out)
{
    out->x = base->x + (b + func_02045758((struct Descriptor *)a) * 8);
    out->y = base->y + ((c << 4) + func_02045760((struct Descriptor *)a) * 8);
}

u32 func_0202DE9C(u32 engine)
{
    vu32 *reg;

    if (engine == 0) {
        reg = (vu32 *)0x04000000;
    } else {
        reg = (vu32 *)0x04001000;
    }
    switch (*reg & 0x00300010) {
    case 0x00000010:
        return 0x21;
    case 0x00100010:
        return 0x22;
    case 0x00200010:
        return 0x20;
    }
    return 0x20;
}

u32 func_0202DEE0(u32 engine)
{
    vu32 *reg;

    if (engine == 0) {
        reg = (vu32 *)0x04000000;
    } else {
        reg = (vu32 *)0x04001000;
    }
    switch (*reg & 0x00300010) {
    case 0x00000010:
        return 0x27;
    case 0x00100010:
        return 0x28;
    case 0x00200010:
        return 0x26;
    }
    return 0x26;
}

u32 func_0202DF24(u32 engine)
{
    vu32 *reg;

    if (engine == 0) {
        reg = (vu32 *)0x04000000;
    } else {
        reg = (vu32 *)0x04001000;
    }
    switch (*reg & 0x00300010) {
    case 0x00000010:
        return 0x2D;
    case 0x00100010:
        return 0x2E;
    case 0x00200010:
        return 0x2C;
    }
    return 0x26;
}

/*
 * Builds the four handles of the pms_draw sub-object at +0x10 of its
 * owner: the three VRAM-bank queries of unit_0202DE9C are taken first
 * (off the engine word at +4), a 0x2b resource set is opened on the
 * caller's heap, and ENV_SetResourceSet / func_0204A6C8 / func_0204AF28
 * fill +8, +0xc and +0x10 before the set is closed again.
 *
 * The screen-size argument to ENV_SetResourceSet is `(u16)(a1 << 5)`, the
 * unequal shift pair lsls #0x15 / lsrs #0x10 -- a narrowing cast folded
 * with the shift, not an 11-bit bitfield.
 */
void func_0202DF68(u32 *o, u32 a1, u32 heap)
{
    u32 b0;
    u32 b1;
    u32 b2;
    void *h;

    b0 = func_0202DE9C(o[1]);
    b1 = func_0202DEE0(o[1]);
    b2 = func_0202DF24(o[1]);
    h = func_020490F4(0x2b, heap);
    o[2] = func_0204AC18(h, 1, o[1], (u16)(a1 << 5), 0, 5, heap);
    o[3] = func_0204A6C8(h, b2, 0, o[1], heap);
    o[4] = func_0204AF28(h, b0, b1, heap);
    func_02049238(h);
}

void func_0202DFD4(struct Res *p)
{
    func_0204ADA4(p->f08);
    func_0204A8D4(p->f0c);
    func_0204AFD8(p->f10);
}

/*
 * Creates one actor out of the five-word resource record the owner keeps
 * at +0x10 (func_0202DF68 is what fills it), disables it, enables its
 * second flag, and adds the 0x2000 bit only for language 0x1e.
 *
 * The four zero halfwords at sp+0xc must be written as a BRACE
 * INITIALISER, `struct Zero4 z = { 0, 0, 0, 0 };`.  Assigning the four
 * fields as statements -- with or without the address bound to a named
 * pointer local -- swaps r0 and r2 throughout the block (the compiler
 * materialises the zero first and the frame address second, and then
 * re-materialises `add r0, sp, #0xc` for the outgoing slot), which is
 * seventy concrete bytes out and is the whole residue this function had.
 * The permuter (hill and anneal, 3800 compiles, --types) could not reach
 * it from the statement form: no body mutation moves an initialiser's
 * definition order.
 *
 * `one` exists because the original materialises 1 twice, once as the
 * r1 argument to func_0204B92C and once into r4 to survive the
 * func_02035630 call and become `lsls r1, r4, #0xd`; writing the shift
 * as a bare `0x2000` costs a pool word instead.
 *
 * The follower at 0x0202E040 is reached across two bytes of linker fill
 * at 0x0202E03E, which is the 82-against-84 the star records.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0202DFEC.c \
 *       --func func_0202DFEC --addr 0x0202DFEC --cc 1.1p1 --thumb
 */
void *func_0202DFEC(struct Res *r, u16 a)
{
    struct Zero4 z = { 0, 0, 0, 0 };
    void *o;
    u32 one;

    o = func_0204B294((void *)r->f00, r->f0c, r->f08, r->f10, &z, (u16)r->f04, a);
    func_0204B3DC(o, 0);
    one = 1;
    func_0204B92C(o, 1);
    if (func_02035630() == 0x1e) {
        func_0204B954(o, one << 0xd);
    }
    return o;
}

/*
 * Places one element sprite: sub_0202DE6C resolves the cell offset into a
 * pair of u32s, which are narrowed into the adjacent u16 pair the
 * func_0204B404 setter wants, then the cell's own id decides the priority
 * word through sub_0202E430 and the last stack argument (a 1-based index)
 * is passed on as `(u16)(n - 1)`.
 */
void func_0202E040(void *h, struct Descriptor *cell, u32 b, u32 c,
                   u32 n, const struct Pos *base)
{
    struct Pos pos;
    struct Pt_0202E040 pt;
    u32 t;

    func_0202DE6C((u32)cell, b, c, (const struct Pos0202DE6C *)base, (struct Pos0202DE6C *)(&pos));
    pt.x = (u16)pos.x;
    pt.y = (u16)pos.y;
    t = func_02045730(cell);
    func_0204B404(h, (const struct Vec2 *)(&pt), (u16)func_0202E430(t));
    func_0204B84C(h, func_020416D4(t));
    func_0204B878(h, (u16)(n - 1));
}

/*
 * note:     closed 2026-09-21 by tools/permuter.py (hill, --types): the loop counter is signed,
 *           the image compares with blt; u32 gave blo (1 byte)
 */
void func_0202E09C(struct PmsElem *o, struct Res *a, u16 b)
{
    int i;

    for (i = 0; i < 2; i++) {
        o->actor[i] = func_0202DFEC(a, b);
    }
    o->flags.word = (o->flags.word & ~1) | 4;
}

void func_0202E0C8(struct PmsElem *p)
{
    s32 i;

    for (i = 0; i < 2; i++) {
        func_0204B3B4(p->actor[i]);
    }
}

int func_0202E0E0(struct PmsElem *a0, void *a1, int a2)
{
    int ret;
    s32 i;

    if (a0->live != 0) {
        if (func_0201C6C4(a1, func_02045770(a0->handle)) == 0) {
            func_02045334(a0->handle);
            a0->live = 0;
        }
    }

    ret = (a0->live != 0) ? 1 : 0;
    if (ret == 0) {
        if (a0->flags.bits.b1) {
            for (i = 0; i < 2; i++) {
                if (a0->enabled[i] != 0 && a0->flags.bits.b2) {
                    func_0204B3DC(a0->actor[i], 1);
                } else {
                    func_0204B3DC(a0->actor[i], 0);
                }
            }
        }
    }

    if (a2 != 0) {
        s32 v = (s32)func_02045730(a0->handle);
        struct Pt_0202E0E0 diff = { 0, 0 };
        struct Pt_0202E0E0 pos;
        s32 nx;
        s32 ny;
        nx = func_02041648((u8)v);
        ny = func_02041664((u8)v);

        if (nx != a0->x) {
            diff.x = a0->x - nx;
            a0->x = nx;
        }

        if (ny != a0->y) {
            diff.y = a0->y - ny;
            a0->y = ny;
        }

        if (diff.x != 0 || diff.y != 0) {
            for (i = 0; i < 2; i++) {
                func_0204B53C(a0->actor[i], &pos);
                pos.x += diff.x;
                pos.y += diff.y;
                func_0204B528(a0->actor[i], &pos);
            }
        }
    }

    return ret;
}

/*
 * blink_palanm: set up a message's blink palette animation.  Copy the
 * caller's MSGPARAM into a local, build the string, mark which characters
 * blink (wk->blink[i]) or are blank (mark[i]), draw the window, then start
 * a palette animation (func_0202E040) on every blinking character and clear
 * every blank one.  Only caller: func_0202DC60, which passes the five stack
 * words (param, pos, pri, pal, heap).
 *
 * Closed 2026-09-24 (wave 21, lane E12) from DIFF 2
 * (docs/notes/pkt_0202E1F0.c.txt, waves 5-21).  Two things together,
 * neither enough on its own:
 *   - the parameter `param` is reused as `param = &mp` after the copy, and
 *     every later call, including func_02024368 after loop 1, takes
 *     `param` (with `&mp` there the image's `adds r0, r7, #0` at +0x8E is
 *     rematerialised as `add r0, sp, #0x38`, 2 out);
 *   - the two stores after func_0202465C are written msg first, then
 *     active.  In the other order the compile puts wk in r7 and param in r6
 *     (21 out).  The scheduler emits the strb before the str in both
 *     orders, so the listing only shows the order through the allocation.
 * The lane-E7 draft (callee widths read from the callees' matched bodies)
 * is the starting point; only those two lines differ from it.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0202E1F0.c \
 *       --func func_0202E1F0 --addr 0x0202E1F0 --cc 1.1p1 --thumb
 */
void func_0202E1F0(struct PmsElem *wk, void *owner, u32 a2, struct Descriptor *a3,
                   const MSGPARAM *param, const BLINKPOS *pos,
                   u16 pri, u8 pal, u16 heap)
{
    u32 mark[2] = {0, 0};
    MSGPARAM mp;
    void *str;
    void *buf;
    int i;
    u16 heapID;
    int n;

    func_02024570((struct Rec8 *)(&mp), (const struct Rec8 *)param);
    param = &mp;
    func_0202465C((struct T *)(&mp), 1, heap);
    wk->handle = a3;
    wk->live = 0;
    heapID = *(u16 *)&heap;
    str = func_0202441C((const struct Struct_0202441C *)param, heapID);
    n = (u8)func_0201D478(str);
    for (i = 0; i < n; i++) {
        if (func_020244F8((struct Container *)param, i)) {
            wk->enabled[i] = 1;
        } else if (func_020244D4((void *)param, i) == 0xffff) {
            mark[i] = 1;
        }
    }
    buf = func_02024368((u16 *)param, heapID, n);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)wk->handle)), pal);
    func_0201C724(owner, (u32)func_02045770((struct Descriptor *)wk->handle), (s16)pos->x, (s16)pos->y, (u32)buf, a2, pri);
    wk->live = 1;
    for (i = 0; i < n; i++) {
        if (wk->enabled[i] == 1) {
            u32 x = func_0201D528(buf, i, (void *)a2, 0);
            u32 y = func_0201D4BC(buf, i);
            func_0202E040(wk->actor[i], a3, x, y, func_020244D4((void *)param, i), (const struct Pos *)pos);
        } else if (mark[i] == 1) {
            u32 x = func_0201D528(buf, i, (void *)a2, 0);
            u32 y = func_0201D4BC(buf, i);
            func_02043AF4((u32)func_02045770((struct Descriptor *)a3), x, y << 4, 0x54, 0x10, pal);
        }
    }
    func_02045808(buf);
    func_02045808(str);
    func_02045374((struct Cfg *)wk->handle);
    func_02041B6C(func_02045730((struct Descriptor *)wk->handle));
    wk->flags.bits.b0 = 1;
    wk->flags.bits.b1 = 1;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202E38C.c \
 *       --func func_0202E38C --addr 0x0202E38C --cc 1.1p1 --thumb
 */
void func_0202E38C(struct PmsElem *obj, u32 a1)
{
    void *h;
    int i;

    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)obj->handle)), 0);
    if (a1 != 0) {
        func_02045334((struct Descriptor *)obj->handle);
        h = obj->handle;
        func_020456F8((struct Descriptor *)h);
        func_020409B4(func_02045730((struct Descriptor *)h));
    }
    for (i = 0; i < 2; i++) {
        func_0204B3DC(obj->actor[i], 0);
        obj->enabled[i] = 0;
    }
    obj->x = 0;
    obj->y = 0;
    obj->flags.word &= ~1;
    obj->flags.word &= ~2;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202E3E4.c \
 *       --func func_0202E3E4 --addr 0x0202E3E4 --cc 1.1p1 --thumb
 */
void func_0202E3E4(struct PmsElem *obj, u32 a1)
{
    int i;

    obj->flags.word = (obj->flags.word & ~2) | ((a1 & 1) << 1);
    if (a1 != 0)
        func_02045374((struct Cfg *)obj->handle);
    else
        func_020456F8((struct Descriptor *)obj->handle);
    func_02041B6C(func_02045730((struct Descriptor *)obj->handle));
    for (i = 0; i < 2; i++) {
        if (obj->enabled[i] != 0)
            func_0204B3DC(obj->actor[i], a1);
    }
}

u32 func_0202E430(u32 id)
{
    if (id >= 4) {
        return 1;
    }
    return 0;
}

void func_0202E43C(void *p)
{
    func_02082BCC(p, 0, 4);
}

u32 func_0202E448(u32 id)
{
    u32 i;

    for (i = 0; i < 7; i++) {
        if (id == sub_0202E448_Table[i].id) {
            return sub_0202E448_Table[i].val;
        }
    }
    return 0x19;
}

/*
 * Allocates and fills one record of a per-something description list,
 * followed by eight "read the sub-object" calls.  The fifth argument to
 * func_02030734 is the pool-relative caller tag (0x37 here, the same 0x3c/
 * 0x3d/0x83/0x84 tags in the neighbours are the same convention).
 *
 * Argument order of func_02082D44 is (src, dst, n): the original loads r1
 * with `p + 0x14` *before* r0 with a1, so r1 - the second slot - is the
 * destination.  Writing the copy as `func_02082D44(dst, src, n)` reverses the
 * two registers and costs seven bytes.
 *
 * The pool word 0x020A77C4 is a `string` site: it is the `__FILE__`-style
 * name run whose start is pinned by the terminator of the string before it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202E474.c \
 *       --func func_0202E474 --addr 0x0202E474 --cc 1.1p1 --thumb
 */
void *func_0202E474(const struct BigObj *a0, int a1, int a2, int a3)
{
    int   v = (int)func_02012EBC((struct Big *)a0);
    char *p = func_02030734(a3, 0x3c, 1, data_020A77C4, 0x37);

    ((struct Obj04060 *)p)->f0 = (int)a0;
    ((struct Obj04060 *)p)->f4 = (int)func_0200873C((void *)v);
    ((struct Obj04060 *)p)->f8 = (int)func_02012944((void *)a0);
    ((struct Obj04060 *)p)->fC = func_02012924(a0);
    ((struct Obj04060 *)p)->f10 = func_0201292C((const struct BigObj *)a0);
    if (a1 != 0) {
        func_02082D44((void *)a1, p + 0x14, 0x18);
    }
    ((struct Obj04060 *)p)->f2C = a2;
    ((struct Obj04060 *)p)->f30 = func_02012B28(func_020127A4((struct SaveBlock *)a0)) == 1;
    return p;
}
