/*
 * file:     zknsearch_main.c
 * unit:     yes
 * function: func_021BC3F0, func_021BC578, func_021BC5B4, func_021BC5C8, func_021BC5DC, func_021BC790, func_021BC800, func_021BC82C, func_021BC8B4, func_021BC8EC, func_021BC92C, func_021BC940, func_021BC99C, func_021BC9D0, func_021BCA10, func_021BCA20, func_021BCA78, func_021BCA84, func_021BCAC8, func_021BCAF8, func_021BCB28, func_021BCB58, func_021BCB88, func_021BCBB8, func_021BCC1C, func_021BCC2C, func_021BCCA8, func_021BCD30, func_021BCD3C, func_021BCDA4, func_021BCE0C, func_021BCE58, func_021BCEEC, func_021BCEF0, func_021BCEF4, func_021BCF00, func_021BCF0C, func_021BCF38, func_021BCF50, func_021BCF8C, func_021BD064, func_021BD100, func_021BD118, func_021BD19C, func_021BD36C, func_021BD388, func_021BD3AC, func_021BD4AC, func_021BD500, func_021BD568, func_021BD640, func_021BD658, func_021BD6C4, func_021BD898, func_021BD8B0, func_021BD920, func_021BDB1C, func_021BDB34, func_021BDBA4, func_021BDD78, func_021BDD90, func_021BDE00, func_021BDFA8, func_021BDFC0, func_021BE010, func_021BE0C4, func_021BE0E4, func_021BE110, func_021BE12C, func_021BE178, func_021BE190, func_021BE20C, func_021BE22C, func_021BE278, func_021BE290, func_021BE2DC, func_021BE2F4, func_021BE314, func_021BE324, func_021BE368, func_021BE3B4, func_021BE3D4, func_021BE44C, func_021BE49C, func_021BE4B4, func_021BE564, func_021BE7E4, func_021BE820, func_021BE83C, func_021BE8B8, func_021BE8F8, func_021BE978, func_021BE9D4, func_021BEA54, func_021BEB0C, func_021BEB8C, func_021BEBE8, func_021BEC60, func_021BECAC, func_021BECB8, func_021BECF8, func_021BED04, func_021BED10, func_021BED1C, func_021BED2C, func_021BED54, func_021BED68, func_021BED98, func_021BEDB8, func_021BEDD0, func_021BEDE0, func_021BEDF0, func_021BEE04, func_021BEE14, func_021BEE38, func_021BEE58, func_021BEE80, func_021BEE94, func_021BEEC4, func_021BF080, func_021BF0DC, func_021BF358, func_021BF370, func_021BF38C, func_021BF418, func_021BF480, func_021BF4A4, func_021BF500, func_021BF55C, func_021BF5B8, func_021BF618, func_021BF658, func_021BF6E0, func_021BF728, func_021BF7B0, func_021BF81C, func_021BF85C, func_021BF89C, func_021BFA14, func_021BFA7C, func_021BFABC, func_021BFB24, func_021BFB8C, func_021BFBF8, func_021BFCE4, func_021BFE84, func_021BFEAC, func_021BFF18, func_021BFF30, func_021BFF68, func_021C003C, func_021C006C, func_021C0098, func_021C00B4, func_021C00D8, func_021C00FC, func_021C014C, func_021C01C0
 * address:  0x021BC3F0
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   g_0784 0x021C0784 data
 *   g_0814 0x021C0814 data
 *   g_07F4 0x021C07F4 data
 *   g_0854 0x021C0854 data
 *   g_0874 0x021C0874 data
 *   g_0834 0x021C0834 data
 *   g_07D4 0x021C07D4 data
 *   g_07B4 0x021C07B4 data
 *   g_0794 0x021C0794 data
 *   func_020403F4  0x020403F4  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_020275E4 0x020275E4 thumb
 *   func_02027628 0x02027628 thumb
 *   func_02027624 0x02027624 thumb
 *   func_0202762C 0x0202762C thumb
 *   func_020413B0 0x020413B0 arm
 *   func_0204162C 0x0204162C arm
 *   func_02049B40 0x02049B40 arm
 *   func_02021518 0x02021518 thumb
 *   func_0202155C 0x0202155C thumb
 *   func_020216D4 0x020216D4 thumb
 *   func_020215A0  0x020215A0  thumb
 *   func_02021540  0x02021540  thumb
 *   func_020056BC 0x020056BC thumb
 *   func_0202173C 0x0202173C thumb
 *   func_0207D63C  0x0207D63C  arm
 *   func_02045B38 0x02045B38 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_02045808  0x02045808  arm
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_0201D83C  0x0201D83C  thumb
 *   func_02045C04  0x02045C04  arm
 *   func_0202E940 0x0202E940 thumb
 *   func_0202E9AC 0x0202E9AC thumb
 *   func_0202C9B4 0x0202C9B4 thumb
 *   func_0202CA3C 0x0202CA3C thumb
 *   func_0202CAC4 0x0202CAC4 thumb
 *   func_02041300 0x02041300 arm
 *   func_0202CA0C  0x0202CA0C  thumb
 *   func_02030734 0x02030734 arm
 *   func_02049EF4 0x02049EF4 arm
 *   func_02082A60 0x02082A60 arm
 *   func_020307B0 0x020307B0 arm
 *   d_021C0E80 0x021C0E80 data a4
 *   func_02041090 0x02041090 arm
 *   func_02012BF8 0x02012BF8 thumb
 *   func_02041EE4 0x02041EE4 arm
 *   func_0202CB4C 0x0202CB4C thumb
 *   func_0202CD94 0x0202CD94 thumb
 *   func_0202CD64 0x0202CD64 thumb
 *   d_021C072E  0x021C072E  data  a2
 *   d_021C0720  0x021C0720  data  a1
 *   d_021C0894  0x021C0894  data  a4
 *   func_021C93E4  0x021C93E4  thumb  ov212
 *   func_02034AC4  0x02034AC4  arm
 *   ov067_id  0x00000043  data
 *   func_02043534  0x02043534  arm
 *   func_020435F4  0x020435F4  arm
 *   func_0204363C  0x0204363C  arm
 *   func_0207D534  0x0207D534  arm
 *   func_0200CA70  0x0200CA70  thumb
 *   func_0203D34C  0x0203D34C  arm
 *   func_021BC3D4  0x021BC3D4  thumb  ov210
 *   func_021BC294  0x021BC294  thumb  ov210
 *   func_021BC318  0x021BC318  thumb  ov210
 *   func_02021ED8 0x02021ED8 thumb
 *   func_021BC330 0x021BC330 thumb ov210
 *   func_021BC2AC 0x021BC2AC thumb ov210
 *   func_02034A5C 0x02034A5C arm
 *   func_020061E4  0x020061E4  thumb
 *   func_0202EA40  0x0202EA40  thumb
 *   func_021C9380  0x021C9380  thumb  ov212
 *   func_02006210  0x02006210  thumb
 *   func_021C9428  0x021C9428  thumb  ov212
 *   func_021C9460  0x021C9460  thumb  ov212
 *   func_021C9468  0x021C9468  thumb  ov212
 *   func_020355C4 0x020355C4 arm
 *   func_020260F4 0x020260F4 thumb
 *   func_021C0234 0x021C0234 thumb ov210
 *   func_021B7A64 0x021B7A64 thumb ov067
 *   func_021B7AB0  0x021B7AB0  thumb  ov067
 *   func_021C0550  0x021C0550  thumb  ov210
 *   func_021C02DC 0x021C02DC thumb ov210
 *   func_021C0384 0x021C0384 thumb ov210
 *   func_021C0434 0x021C0434 thumb ov210
 *   func_021C04CC 0x021C04CC thumb ov210
 *   func_021B93D4  0x021B93D4  thumb  ov067
 *   func_021B93B8 0x021B93B8 thumb ov067
 *   func_02012BE0 0x02012BE0 thumb
 *   func_02045088 0x02045088 arm
 *   func_020450F0 0x020450F0 arm
 *   d_021C0900 0x021C0900 data a1
 *   func_020452E8 0x020452E8 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_021B6AE4 0x021B6AE4 thumb ov067
 *   func_02043B5C 0x02043B5C arm
 *   func_0201D304 0x0201D304 thumb
 *   func_021B9394 0x021B9394 thumb ov067
 *   func_02045738 0x02045738 arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_0204B944 0x0204B944 arm
 *   func_0204B8D4 0x0204B8D4 arm
 *   func_0204A600 0x0204A600 arm
 *   func_0204B8C4 0x0204B8C4 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B898 0x0204B898 arm
 *   func_0204B98C  0x0204B98C  arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_0204B688 0x0204B688 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B454 0x0204B454 arm
 *   func_0204B84C 0x0204B84C arm
 *   func_021BC3E8 0x021BC3E8 thumb ov210
 *   func_0204A48C 0x0204A48C arm
 *   d_021C0990 0x021C0990 data a4 ov210
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02027618 0x02027618 thumb
 *   func_02027614 0x02027614 thumb
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B100 0x0204B100 arm
 *   func_021C940C 0x021C940C thumb ov212
 *   data_021C09AC 0x021C09AC data
 *   data_021C0978 0x021C0978 data
 *   data_021C0960 0x021C0960 data
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_021B8AE4 0x021B8AE4 thumb ov067
 *   func_021B93B0  0x021B93B0  thumb ov067
 *   func_021B93C0  0x021B93C0  thumb ov067
 *   func_02025CD0 0x02025CD0 thumb
 *   func_02025D1C 0x02025D1C thumb
 *   d_021C0B60 0x021C0B60 data a4
 *   d_021C0B14 0x021C0B14 data a4
 *   func_02025D14 0x02025D14 thumb
 *   func_02025DE8 0x02025DE8 thumb
 *   func_020362DC 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   func_020260E0 0x020260E0 thumb
 *   func_020260E4 0x020260E4 thumb
 *   func_0202EB04 0x0202EB04 thumb
 *   func_02035C60 0x02035C60 arm
 *   func_02035C08 0x02035C08 arm
 *   func_021B940C 0x021B940C thumb ov067
 *   d_021C0B3C 0x021C0B3C data a4
 *   d_021C0B24 0x021C0B24 data a4
 */
#include "../../matched/include/Obj03370.h"
#include "../../matched/include/Obj00085.h"
#include "../../matched/include/Obj01779.h"
#include "../../matched/include/Obj06693.h"
#include "../../matched/include/Obj14671.h"
#include "../../matched/include/Obj25586.h"
#include "../../matched/include/Obj10914.h"
#include "../../matched/include/Obj05546.h"
#include "../../matched/include/Obj25587.h"
#include "../../matched/include/Obj14672.h"
#include "../../matched/include/Obj25589.h"
#include "../../matched/include/Obj14673.h"
#include "../../matched/include/Obj25593.h"
#include "../../matched/include/Obj25594.h"
#include "../../matched/include/Obj08413.h"
#include "../../matched/include/Obj25595.h"
#include "../../matched/include/Obj25596.h"
#include "../../matched/include/Obj25597.h"
#include "../../matched/include/Obj25598.h"
#include "../../matched/include/Obj25599.h"
#include "../../matched/include/Obj25600.h"
#include "../../matched/include/Obj25601.h"
#include "../../matched/include/Obj14675.h"
#include "../../matched/include/Obj25602.h"
#include "../../matched/include/Obj25603.h"
#include "../../matched/include/Obj25604.h"
#include "../../matched/include/Obj00222.h"
#include "../../matched/include/Obj03936.h"
#include "../../matched/include/Obj14677.h"
#include "../../matched/include/Obj06694.h"
#include "../../matched/include/Obj06695.h"
#include "../../matched/include/Obj06696.h"
#include "../../matched/include/Obj06697.h"
#include "../../matched/include/Obj06698.h"
#include "../../matched/include/Obj04618.h"
#include "../../matched/include/Obj25605.h"
#include "../../matched/include/Obj10915.h"
#include "../../matched/include/Obj25606.h"
#include "../../matched/include/Obj25607.h"
#include "../../matched/include/Obj04619.h"
#include "../../matched/include/Obj25608.h"
#include "../../matched/include/Obj25609.h"
#include "../../matched/include/Obj10917.h"
#include "../../matched/include/Obj25610.h"
#include "../../matched/include/Obj25611.h"
#include "../../matched/include/Obj10919.h"
#include "../../matched/include/Obj25612.h"
#include "../../matched/include/Obj14678.h"
#include "../../matched/include/Obj25613.h"
#include "../../matched/include/Obj10921.h"
#include "../../matched/include/Obj14680.h"
#include "../../matched/include/Obj25617.h"
#include "../../matched/include/Obj25618.h"
#include "../../matched/include/Obj14681.h"
#include "../../matched/include/Obj04620.h"
#include "../../matched/include/Obj25626.h"
#include "../../matched/include/Obj25627.h"
#include "../../matched/include/Obj25628.h"
#include "../../matched/include/Obj25629.h"
#include "../../matched/include/Obj08414.h"
#include "../../matched/include/Obj25630.h"
#include "../../matched/include/Obj25631.h"
#include "../../matched/include/Obj10923.h"
#include "../../matched/include/Obj25635.h"

struct PalAnmSlot;
struct PalAnmObj;
struct MsgBank;
struct GfFont;
struct WordSet;
struct U16Vec;
struct PrintSys;
struct Rec;
struct CodeIn;
struct Obj0202EA20;
struct WinMgr;
struct Blk37;
struct Row;
struct Search;
struct Struct_02025CD0;
struct S;
struct Descriptor;
struct Cfg;
struct CharBuf;
struct StrObj;
struct Obj021BF0DC;
struct Res021BEEC4;
struct Obj;
struct Actor;
struct Vec2;
struct PtS;
struct Bank;
struct Struct_02025D1C;
struct Sound;
typedef unsigned short u16;

typedef unsigned int u32;

struct DispConfig { u32 w[4]; };

struct BgTemplate { u32 w[8]; };

typedef unsigned char  u8;

typedef signed short   s16;

typedef signed char    s8;

typedef signed int     s32;

typedef u32 (*StateFn)(u8 *);

struct Record { u8 a, b, c, d, e, f; };

typedef unsigned int   u32_021BE3B4;

typedef unsigned u32_021BE44C;

typedef unsigned int   u32_021BE49C;

typedef unsigned int  u32_021BE4B4;

typedef unsigned int u32_021BE564;

typedef unsigned int   u32_021BE7E4;

typedef unsigned int   u32_021BE820;

typedef unsigned int  u32_021BE8F8;

typedef unsigned int  u32_021BE9D4;

typedef unsigned int  u32_021BEA54;

typedef unsigned int  u32_021BEB0C;

typedef unsigned int  u32_021BEB8C;

typedef unsigned int u32_021BEC60;

typedef enum { off_ECB8 = 0x1c4 } Offset;

typedef unsigned int   u32_021BED2C;

typedef unsigned int   u32_021BED68;

typedef unsigned int   u32_021BED98;

typedef unsigned int   u32_021BEDE0;

typedef unsigned int   u32_021BEE04;

typedef unsigned int   u32_021BEE14;

typedef unsigned int u32_021BEE94;

typedef struct { u32_021BEE94 w[7]; } Tbl;

typedef unsigned int u32_021BEEC4;

struct Res021BEEC4 {
    u8 pad[0x10C];
    int a[6];
    int b[6];
    int c[4];
};

struct Tpl021BF0DC {
    int f0;
    u16 id;
    u16 f6;
    int a;
    int b;
    int c;
    u16 f14;
    u16 f16;
};

struct Obj021BF0DC {
    void **sys;
    u8 pad04[0x20];
    void *set;
    void *objs[57];
    int a[6];
    int b[6];
    int c[4];
};

typedef enum Y { YMin = -2147483647, YMax = 2147483647 } Y;

extern void func_0203F8F4(u16);
extern void func_0203FC28(struct DispConfig *);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414EC(u32);
extern void func_02041B6C(u32);
extern void func_020434DC(u32, u32);
extern void func_02043598(u32, u32);
extern void func_020403F4(u32 a);
extern void func_0203F9B4(void);
extern void func_0204047C(int idx, unsigned short val);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049238(void *h);
extern u32 func_020275E4(void);
extern u32 func_02027628(void);
extern u32 func_02027624(void);
extern u32 func_0202762C(void);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern u32 func_0204162C(int channel);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void *func_02021518(unsigned);
extern void func_0202155C(struct PalAnmSlot *,unsigned,unsigned,unsigned);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void func_020215A0(struct PalAnmSlot *slots, u32 idx);
extern u32 func_02021540(void *a0);
extern u32 func_020056BC(void);
extern int func_0202173C(struct PalAnmObj *,u16,u16,s16,u8,u8,u16,void *);
extern void func_0207D63C(u32 reg, u32 a, u32 b, u32 c, u32 d);
extern struct MsgBank *func_02045B38(u32, u32, u32, u32);
extern struct GfFont *func_0201D7EC(int, int, int, int, u32);
extern struct WordSet *func_0201EC64(u32);
extern u32 func_0201C440(void *);
extern struct U16Vec *func_020457B0(u32, u32);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_0201D83C(void *ptr);
extern u32 func_02045C04(struct Rec *rec);
extern struct CodeIn *func_0202E940(u16 a0, u16 a1, u32 a2, u16 heap);
extern void func_0202E9AC(struct CodeIn *p, u8 *a1, u32 a2, u32 a3, u32 a4);
extern u32 func_0202EA20(struct Obj0202EA20 *p);
extern struct WinMgr *func_0202C9B4(u32 a0, u32 a1, u32 heap);
extern void func_0202CA3C(struct WinMgr *mgr, u32 idx, u32 bg, u32 w, u32 h);
extern void func_0202CAC4(struct WinMgr *mgr, u32 idx, const void *src);
extern void func_02041300(u32, int, int, int, u8, u8, u8);
extern void func_0202CA0C(struct WinMgr *mgr);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void *func_02049EF4(void *, u32, u32, void **, u16);
extern void func_02082A60(const void *, void *, u32);
extern u32 func_020307B0(void *p);
extern void func_02041090(u32, u32, u32, u32, u8, u8);
extern int func_02012BF8(int, int);
extern void func_02041EE4(u32, u32, u32);
extern void func_0202CB4C(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern void func_0202CD94(struct WinMgr *mgr);
extern void func_0202CD64(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames);
extern void func_021C93E4(u32 a, u32 b, u32 *counter);
extern int func_02034AC4(s32 handle);
extern void func_02043534(u32 a);
extern void func_020435F4(u32 a);
extern void func_0204363C(u32 a);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern u32 func_0200CA70(struct Blk37 *p);
extern void func_0203D34C(u32 a, u32 b);
extern void func_021BC3D4(void);
extern void func_021BC294(u8 *p);
extern void func_021BC318(u8 *p);
extern u32 func_02021ED8(const char *);
extern u32 func_021BC330(u8 *p);
extern u32 func_021BC2AC(u8 *p);
extern void func_02034A5C(int);
extern void func_020061E4(u32 id);
extern s32 func_0202EA40(struct Row *p);
extern void func_021C9380(struct Blk37 *p, u8 *out);
extern void func_02006210(void);
extern int func_021C9428(int, int, int);
extern void func_021C9460(int);
extern int func_021C9468(struct Search *p, u16 heap, u16 *outCount, u16 **out);
extern u8 func_020355C4(void);
extern void func_020260F4(struct Struct_02025CD0 *obj, u32 state);
extern void func_021C0234(char *ctx);
extern int func_021B7A64(struct S *p);
extern int func_021B7AB0(struct S *p);
extern void func_021C0550(int p);
extern void func_021C02DC(char *ctx);
extern void func_021C0384(char *ctx);
extern void func_021C0434(char *ctx);
extern void func_021C04CC(char *ctx);
extern void func_021B93D4(struct S *s, int v);
extern int func_021B93B8(char *p);
extern void func_02012BE0(void *, unsigned, unsigned);
extern void func_02045088(unsigned short);
extern unsigned func_020450F0(unsigned, unsigned, unsigned, unsigned, u8, u8, u8);
extern u32_021BE3B4 func_020452E8(struct Descriptor *d);
extern void func_020450C8(void);
extern unsigned func_0201C4E4(struct PrintSys *);
extern void *func_02045770(struct Descriptor *);
extern unsigned func_0201C6C4(struct PrintSys *, void *);
extern void func_02045334(struct Descriptor *);
extern void *func_02045EC0(struct MsgBank *, u32_021BE44C);
extern void func_021B6AE4(u8 *p, void *a, u16 b, u16 c, u32_021BE44C s0, u32_021BE44C s1, u16 s2, u32_021BE44C s3);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern u32_021BE564 func_0201D304(struct StrObj *s, u32_021BE564 a, u32_021BE564 b);
extern u32_021BEC60 func_021B9394(char *p);
extern u8 func_02045738(struct Descriptor *p);
extern void func_0204A5AC(void);
extern u32_021BED68 func_0204B944(struct Obj *p);
extern void func_0204B8D4(struct Obj *p, u32_021BED68 arg);
extern void func_0204A600(void);
extern void func_0204B8C4(struct Obj *p, u32_021BED98 value);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B92C(struct Obj *p, unsigned int v);
extern u16 func_0204B898(struct Obj *p);
extern u32_021BEDE0 func_0204B98C(struct Actor *a);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern u32_021BEE04 func_0204B3F4(struct Obj *p);
extern void func_0204B688(struct Actor *actor, u32_021BEE14 value);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32_021BEE14 which);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B84C(int h, unsigned v);
extern void *func_021BC3E8(void);
extern void func_0204A48C(const struct Cfg *cfg, u32_021BEE94 arg, u32_021BEE94 heapId);
extern int func_0204A6C8(void *arc, u32_021BEEC4 idx, u32_021BEEC4 a, u32_021BEEC4 b, u16 heap);
extern int func_0204ABF0(void *arc, u32_021BEEC4 idx, u32_021BEEC4 a, u32_021BEEC4 b, u16 heap);
extern int func_0204AF28(void *arc, u32_021BEEC4 a, u32_021BEEC4 b, u32_021BEEC4 heap);
extern u32_021BEEC4 func_02027618(void);
extern u32_021BEEC4 func_02027614(void);
extern u32_021BEEC4 func_0202761C(u32_021BEEC4 a);
extern u32_021BEEC4 func_02027620(u32_021BEEC4 a);
extern void func_0204A8D4(unsigned);
extern void func_0204ADA4(unsigned);
extern void func_0204AFD8(unsigned);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern struct Obj *func_021C940C(u32 bank, const u8 *t, u16 heap);
extern void func_0204B3B4(struct Obj *p);
extern u32 func_0204B1CC(struct Bank *bank);
extern int func_021B8AE4(struct S *, unsigned int);
extern int func_021B93B0(char *p);
extern int func_021B93C0(char *p);
extern struct Struct_02025CD0 *func_02025CD0(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u16 heapId);
extern void func_02025D1C(struct Struct_02025D1C *obj);
extern void func_02025D14(void);
extern void *func_0202616C(void **obj, unsigned int idx);
extern int func_02025DE8(struct Sound *obj);
extern unsigned func_020362DC(void);
extern void func_020355D8(u8 v);
extern u8 func_020260E0(struct Sound *obj);
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void func_0202EB04(struct CodeIn *p);
extern int func_02035C60(void);
extern int func_02035C08(const void *);
extern void func_021B940C(struct S *s);
void func_021BC3F0(void);
void func_021BC578(u32 a0);
void func_021BC5B4(u32 a0);
void func_021BC5C8(void);
void func_021BC5DC(void);
void func_021BC790(char *p);
void func_021BC800(u8 *p);
void func_021BC82C(char *p,u8 b,u8 c);
void func_021BC8B4(int mode);
void func_021BC8EC(void);
void func_021BC92C(u32 a0);
void func_021BC940(char *p);
u32 func_021BC99C(u8 *p);
void func_021BC9D0(int p);
u32 func_021BCA10(u8 *p);
void func_021BCA20(char *p);
void func_021BCA78(u8 *p);
void func_021BCA84(void *a0);
void func_021BCAC8(u8 *a0);
void func_021BCAF8(u8 *a0);
void func_021BCB28(u8 *a0);
void func_021BCB58(u8 *a0);
void func_021BCB88(u8 *a0);
void func_021BCBB8(char *p);
u32 func_021BCC1C(u8 *p);
void func_021BCC2C(char *p);
void func_021BCCA8(char *p);
void func_021BCD30(u8 *p);
void func_021BCD3C(u8 *p);
void func_021BCDA4(char *p);
void func_021BCE0C(char *p, int delta);
int func_021BCE58(char *p);
u32 func_021BCEEC(u32 a, u32 b);
u32 func_021BCEF0(u32 a, u32 b);
u16 func_021BCEF4(int a0, int a1);
u16 func_021BCF00(int a0, int a1);
void func_021BCF0C(u8 *p);
void func_021BCF38(u8 *p);
u32 func_021BCF50(u8 *p);
u32 func_021BCF8C(u8 *p);
int func_021BD064(char *p);
u32 func_021BD100(u8 *p);
int func_021BD118(u8 *p);
u32 func_021BD19C(u8 *p);
u32 func_021BD36C(u8 *p);
u32 func_021BD388(u8 *p);
int func_021BD3AC(unsigned char *p);
int func_021BD4AC(u8 *p);
int func_021BD500(u8 *p);
u32 func_021BD568(u8 *p);
u32 func_021BD640(u32 p);
int func_021BD658(u8 *p);
u32 func_021BD6C4(u8 *p);
u32 func_021BD898(u8 *p);
int func_021BD8B0(u8 *p);
u32 func_021BD920(u8 *p);
u32 func_021BDB1C(u8 *p);
int func_021BDB34(u8 *p);
u32 func_021BDBA4(u8 *p);
u32 func_021BDD78(u8 *p);
int func_021BDD90(u8 *p);
u32 func_021BDE00(u8 *p);
u32 func_021BDFA8(u8 *p);
int func_021BDFC0(u8 *p);
int func_021BE010(u8 *p);
u32 func_021BE0C4(u8 *p);
void func_021BE0E4(u8 *p, u32 v);
void func_021BE110(u8 *p);
void func_021BE12C(u8 *p, int n);
void func_021BE178(u8 *p);
void func_021BE190(u8 *p, int n);
void func_021BE20C(u8 *p);
void func_021BE22C(u8 *p, int index);
void func_021BE278(u8 *p);
void func_021BE290(u8 *p, int index);
void func_021BE2DC(u8 *p);
u32 func_021BE2F4(u8 *p, u32 a, u32 b, u32 c);
u32 func_021BE314(u8 *p, u32 a);
void func_021BE324(u8 *p);
void func_021BE368(u8 *p);
void func_021BE3B4(char *p);
void func_021BE3D4(u8 *p);
void func_021BE44C(u8 *p, int slot, u32_021BE44C message, int x, int y, u16 color, u32_021BE44C mode);
void func_021BE49C(u8 *p);
void func_021BE4B4(u8 *p);
void func_021BE564(u8 *p);
void func_021BE7E4(u8 *p);
void func_021BE820(u8 *p);
void func_021BE83C(u8 *p);
void func_021BE8B8(u8 *p);
void func_021BE8F8(u8 *p);
void func_021BE978(u8 *p);
void func_021BE9D4(u8 *p);
void func_021BEA54(u8 *p);
void func_021BEB0C(u8 *p);
void func_021BEB8C(u8 *p);
void func_021BEBE8(u8 *p);
void func_021BEC60(int p, int *a, u32_021BEC60 b);
void func_021BECAC(int a, unsigned *p);
void func_021BECB8(u8 *p, unsigned message);
void func_021BECF8(void *a);
void func_021BED04(void *a);
void func_021BED10(void *a);
void func_021BED1C(int p);
void func_021BED2C(int p);
void func_021BED54(int p);
void func_021BED68(int p);
void func_021BED98(char *p, int idx, int v);
void func_021BEDB8(int p, int i, int v);
int func_021BEDD0(int p, int i);
int func_021BEDE0(int a0, int a1);
void func_021BEDF0(int p, int i, int v);
int func_021BEE04(int p, int i);
void func_021BEE14(char *p, int idx, int flag);
void func_021BEE38(char *p, int idx, int a, short b, unsigned short c);
void func_021BEE58(char *p, int idx, short *outA, short *outB, unsigned short in);
void func_021BEE80(int p, int i, unsigned v);
void func_021BEE94(void);
void func_021BEEC4(struct Res021BEEC4 *p);
void func_021BF080(u8 *p);
void func_021BF0DC(struct Obj021BF0DC *p);
void func_021BF358(int p, int i);
void func_021BF370(int p);
void func_021BF38C(u8 *p);
unsigned func_021BF418(u8 *p);
void func_021BF480(int p);
void func_021BF4A4(char *p);
void func_021BF500(char *p);
void func_021BF55C(char *p);
void func_021BF5B8(char *p);
void func_021BF618(char *p);
void func_021BF658(char *p);
void func_021BF6E0(char *p);
void func_021BF728(u8 *p, int a);
void func_021BF7B0(char *p, int idx, int y, int flag);
void func_021BF81C(char *p);
void func_021BF85C(char *p, int i, int flag);
void func_021BF89C(char *p, u8 a, u8 b);
void func_021BFA14(char *p, int y, int flag);
void func_021BFA7C(char *p, int i, int flag);
void func_021BFABC(char *ctx, int slot, int index);
void func_021BFB24(char *ctx);
void func_021BFB8C(char *ctx, unsigned long slot, Y y, int flag);
void func_021BFBF8(int p, int v);
void func_021BFCE4(char *p, int dx);
void func_021BFE84(int p, int n);
void func_021BFEAC(char *ctx, int index);
void func_021BFF18(int p);
void func_021BFF30(int p, unsigned int a, unsigned int b);
u32 func_021BFF68(int p);
void func_021C003C(int p, unsigned b);
void func_021C006C(int p, unsigned b);
void func_021C0098(int p, unsigned a, unsigned b);
void func_021C00B4(int p, unsigned a, unsigned b);
void func_021C00D8(int p, unsigned a, unsigned b);
int func_021C00FC(unsigned char *ctx);
int func_021C014C(char *ctx);
int func_021C01C0(char *ctx);
extern const struct DispConfig g_0784;
extern const struct BgTemplate g_0814;
extern const struct BgTemplate g_07F4;
extern const struct BgTemplate g_0854;
extern const struct BgTemplate g_0874;
extern const struct BgTemplate g_0834;
extern const struct BgTemplate g_07D4;
extern const struct BgTemplate g_07B4;
extern const struct BgTemplate g_0794;
extern const char d_021C0E80[];
extern u16 d_021C072E[];
extern u8 d_021C0720[];
extern StateFn d_021C0894[];
extern u8 ov067_id[];
extern const struct Record d_021C0900[];
extern const Tbl d_021C0990;
extern const struct Tpl021BF0DC data_021C09AC[15];
extern const struct Tpl021BF0DC data_021C0978;
extern const struct Tpl021BF0DC data_021C0960;
extern const unsigned d_021C0B60[], d_021C0B14[];
extern const unsigned d_021C0B3C[];
extern const unsigned d_021C0B24[];






void func_021BC3F0(void)
{
    func_0203F8F4(0x7B);
    {
        struct DispConfig d = g_0784;
        func_0203FC28(&d);
    }
    {
        struct BgTemplate t = g_0814;
        func_0203FCA0(0, &t, 0);
    }
    {
        struct BgTemplate t = g_07F4;
        func_0203FCA0(1, &t, 0);
        func_020414EC(1);
        func_02041B6C(1);
    }
    {
        struct BgTemplate t = g_0854;
        func_0203FCA0(2, &t, 0);
    }
    {
        struct BgTemplate t = g_0874;
        func_0203FCA0(3, &t, 0);
        func_020414EC(3);
        func_02041B6C(3);
    }
    {
        struct BgTemplate t = g_0834;
        func_0203FCA0(4, &t, 0);
    }
    {
        struct BgTemplate t = g_07D4;
        func_0203FCA0(5, &t, 0);
        func_020414EC(5);
        func_02041B6C(5);
    }
    {
        struct BgTemplate t = g_07B4;
        func_0203FCA0(6, &t, 0);
    }
    {
        struct BgTemplate t = g_0794;
        func_0203FCA0(7, &t, 0);
        func_020414EC(7);
        func_02041B6C(7);
    }
    func_020434DC(0xF, 1);
    func_02043598(0xF, 1);
}






void func_021BC578(u32 a0)
{
    func_020434DC(15, 0);
    func_02043598(15, 0);
    func_020403F4(6);
    func_020403F4(5);
    func_020403F4(4);
    func_020403F4(2);
    func_020403F4(1);
    func_020403F4(0);
    func_0203F9B4();
}






/*
 * Addresses are Black-image addresses.
 */
void func_021BC5B4(u32 a0)
{
    func_0204047C(0, 1);
    func_0204047C(1, 0);
}






void func_021BC5C8(void)
{
    func_0204047C(0, 0);
    func_0204047C(1, 1);
}






/*
 * note 2026-10-05 (wD9r lane54): closed. func_02049658 returns a value (as in the matched
 *   ov123 021D9D3C and ov110 021BB328); declared void, it let mwcc pool the 4s and zeros into r7/r5
 *   copies and took r7 from 0x807B. With the u32 return and an uninitialised u32 i set by the for statement it is EXACT.
 */
void func_021BC5DC(void)
{
    void *h;
    u32 base;
    u32 i;
    u8 *scr;

    h = func_020490F4(0x9F, 0x807B);
    func_02049B68(h, 0x49, 0, 0, 0xC0, 0x7B);
    func_02049B68(h, 0x4A, 4, 0, 0xA0, 0x7B);
    func_02049740(h, 0x51, 0, 0, 0, 0x7B);
    func_02049658(h, 0x51, 1, 0, 0, 0, 0x7B);
    func_02049658(h, 0x51, 3, 0, 0, 0, 0x7B);
    func_02049658(h, 0x4F, 2, 0, 0, 0, 0x7B);
    func_02049658(h, 0x51, 5, 0, 0, 0, 0x7B);
    func_02049658(h, 0x50, 6, 0, 0, 0, 0x7B);
    func_02049658(h, 0x50, 4, 0, 0, 0, 0x7B);
    func_020498F4(h, 0x5F, 2, 0, 0, 0, 0x7B);
    func_020498F4(h, 0x5E, 4, 0, 0, 0, 0x7B);
    func_020498F4(h, 0x60, 6, 0, 0, 0, 0x7B);
    func_02049238(h);
    h = func_020490F4(func_020275E4(), 0x807B);
    base = func_02049740(h, func_02027628(), 0, 0, 0, 0x7B);
    func_02049B68(h, func_02027624(), 0, 0x1C0, 0x20, 0x7B);
    func_020498F4(h, func_0202762C(), 0, 0, 0, 0, 0x7B);
    func_020413B0(0, 0, 0x15, 0x20, 3, 0xE);
    func_02041B6C(0);
    func_02049238(h);
    scr = (u8 *)func_0204162C(0);
    for (i = 0; i < 0x60; i++) {
        ((u16 *)scr)[i + 0x2A0] += (u16)base;
    }
    func_02041B6C(0);
    func_02049B40(0x17, 5, 0, 0x1E0, 0x20, 0x7B);
    func_02049B40(0x17, 5, 4, 0x1E0, 0x20, 0x7B);
}





void func_021BC790(char *p)
{
    ((struct Obj03370 *)p)->fC=func_02021518(123);
    func_0202155C(*(struct PalAnmSlot * *)&((struct Obj03370 *)p)->fC,0,512,123);
    func_0202155C(*(struct PalAnmSlot * *)&((struct Obj03370 *)p)->fC,1,512,123);
    func_0202155C(*(struct PalAnmSlot * *)&((struct Obj03370 *)p)->fC,2,512,123);
    func_0202155C(*(struct PalAnmSlot * *)&((struct Obj03370 *)p)->fC,3,512,123);
    func_020216D4((struct PalAnmSlot *)(*(unsigned *)&((struct Obj03370 *)p)->fC),0,0,512);
    func_020216D4((struct PalAnmSlot *)(*(unsigned *)&((struct Obj03370 *)p)->fC),1,0,512);
    func_020216D4((struct PalAnmSlot *)(*(unsigned *)&((struct Obj03370 *)p)->fC),2,0,512);
    func_020216D4((struct PalAnmSlot *)(*(unsigned *)&((struct Obj03370 *)p)->fC),3,0,512);
}






void func_021BC800(u8 *p)
{
    func_020215A0((struct PalAnmSlot *)(*(u32 *)&((struct Obj00085 *)p)->fC), 0);
    func_020215A0((struct PalAnmSlot *)(*(u32 *)&((struct Obj00085 *)p)->fC), 1);
    func_020215A0((struct PalAnmSlot *)(*(u32 *)&((struct Obj00085 *)p)->fC), 2);
    func_020215A0((struct PalAnmSlot *)(*(u32 *)&((struct Obj00085 *)p)->fC), 3);
    func_02021540((void *)(*(u32 *)&((struct Obj00085 *)p)->fC));
}





void func_021BC82C(char *p,u8 b,u8 c)
{
    func_0202173C(*(struct PalAnmObj * *)&((struct Obj01779 *)p)->fC,1,0xbfff,-14,b,c,0,(void *)func_020056BC());
    func_0202173C(*(struct PalAnmObj * *)&((struct Obj01779 *)p)->fC,2,0x7fef,-14,b,c,0,(void *)func_020056BC());
    func_0202173C(*(struct PalAnmObj * *)&((struct Obj01779 *)p)->fC,4,0xfe1f,-14,b,c,0,(void *)func_020056BC());
    func_0202173C(*(struct PalAnmObj * *)&((struct Obj01779 *)p)->fC,8,0xbfff,-14,b,c,0,(void *)func_020056BC());
}






void func_021BC8B4(int mode)
{
    if (mode == 1) {
        func_0207D63C(0x04000050, 8, 4, 16, 6);
        func_0207D63C(0x04001050, 2, 6, 6, 10);
        return;
    }
    *(volatile u16 *)0x04001050 = 0;
}





static inline void inside(int wnd,int effect)
{
    u32 tmp=(*(volatile u16 *)0x0400104a & ~0x3f00) | ((u32)wnd<<8);
    if (effect) tmp|=0x20<<8;
    *(volatile u16 *)0x0400104a=(u16)tmp;
}





static inline void outside(int wnd,int effect)
{
    u32 tmp=(*(volatile u16 *)0x0400104a & ~0x3f) | (u32)wnd;
    if (effect) tmp|=0x20;
    *(volatile u16 *)0x0400104a=(u16)tmp;
}





static inline void visible(int window)
{
    *(volatile u32 *)0x04001000=(*(volatile u32 *)0x04001000 & ~0xe000) | (window<<13);
}





void func_021BC8EC(void)
{
    inside(29,1);
    outside(31,1);
    visible(4);
}






void func_021BC92C(u32 a0)
{
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
}





void func_021BC940(char *p)
{
    *(struct MsgBank * *)&((struct Obj06693 *)p)->f1D0 = func_02045B38(0, 2, 277, 123);
    *(struct GfFont * *)&((struct Obj06693 *)p)->f1CC = func_0201D7EC(23, 0, 0, 0, 123);
    *(struct WordSet * *)&((struct Obj06693 *)p)->f1D4 = func_0201EC64(123);
    ((struct Obj06693 *)p)->f1DC = func_0201C440((void *)123);
    *(struct U16Vec * *)&((struct Obj06693 *)p)->f1D8 = func_020457B0(128, 123);
}






u32 func_021BC99C(u8 *p)
{
    func_02045808((struct U16Vec *)(((struct Obj00085 *)p)->f1D8));
    func_0201C4C0((struct PrintSys *)(((struct Obj00085 *)p)->f1DC));
    func_0201ED04((struct WordSet *)(((struct Obj00085 *)p)->f1D4));
    func_0201D83C((void *)(((struct Obj00085 *)p)->f1CC));
    return func_02045C04((struct Rec *)(((struct Obj00085 *)p)->f1D0));
}






void func_021BC9D0(int p)
{
    void *h = func_020490F4(0x9f, 0x807b);

    ((struct Obj14671 *)p)->f2B4 = (int)func_0202E940(0x30, 0x10, 1, 0x7b);
    func_0202E9AC((struct CodeIn *)(((struct Obj14671 *)p)->f2B4), h, 0x49, 0x20, 0x30);
    func_02049238(h);
}






u32 func_021BCA10(u8 *p)
{
    return func_0202EA20((struct Obj0202EA20 *)(((struct Obj25586 *)p)->f2B4));
}





void func_021BCA20(char *p)
{
    u32 base = func_0204162C(0);
    *(struct WinMgr * *)&((struct Obj10914 *)p)->f20 = func_0202C9B4(2, 1, 123);
    func_0202CA3C(*(struct WinMgr * *)&((struct Obj10914 *)p)->f20, 0, 0, 32, 3);
    func_0202CAC4(*(struct WinMgr * *)&((struct Obj10914 *)p)->f20, 0, (void *)(base + 0x540));
    func_02041300(0, 0, 0, 21, 32, 3, 0);
    func_02041B6C(0);
}






void func_021BCA78(u8 *p)
{
    func_0202CA0C(*(struct WinMgr * *)&((struct Obj00085 *)p)->f20);
}





void func_021BCA84(void *a0)
{
    void *h = func_020490F4(159, 0x807b);
    func_020498F4(h, 93, 0, 0, 0, 0, 123);
    func_020498F4(h, 92, 3, 0, 0, 0, 123);
    func_02049238(h);
}






void func_021BCAC8(u8 *a0)
{
    void *h = func_020490F4(159, 0x807b);
    func_020498F4(h, 89, 3, 0, 0, 0, 123);
    func_02049238(h);
}






void func_021BCAF8(u8 *a0)
{
    void *h = func_020490F4(159, 0x807b);
    func_020498F4(h, 88, 3, 0, 0, 0, 123);
    func_02049238(h);
}






void func_021BCB28(u8 *a0)
{
    void *h = func_020490F4(159, 0x807b);
    func_020498F4(h, 90, 3, 0, 0, 0, 123);
    func_02049238(h);
}






void func_021BCB58(u8 *a0)
{
    void *h = func_020490F4(159, 0x807b);
    func_020498F4(h, 86, 3, 0, 0, 0, 123);
    func_02049238(h);
}






void func_021BCB88(u8 *a0)
{
    void *h = func_020490F4(159, 0x807b);
    func_020498F4(h, 87, 3, 0, 0, 0, 123);
    func_02049238(h);
}





void func_021BCBB8(char *p)
{
    void *out;
    void *h;
    void *blob;
    ((struct Obj05546 *)p)->f2BC = func_02030734(123, 384, 0, d_021C0E80, 0x3b0);
    h = func_020490F4(159, 0x807b);
    blob = func_02049EF4(h, 91, 0, (void **)&out, 0x807b);
    func_02082A60((char *)out + 12, ((struct Obj05546 *)p)->f2BC, 384);
    func_020307B0(blob);
    func_02049238(h);
}






u32 func_021BCC1C(u8 *p)
{
    return func_020307B0((void *)(((struct Obj25587 *)p)->f2BC));
}





void func_021BCC2C(char *p)
{
    func_02041090(1, ((struct Obj14672 *)p)->f2BC, 0, 17, 32, 6);
    func_02041B6C(1);
    func_021BEDB8((int)p, 2, 15);
    func_021BEDB8((int)p, 3, 14);
    if (func_02012BF8(**(int * *)&((struct Obj14672 *)p)->f0, 16) == 1)
        func_021BEDB8((int)p, 4, 22);
    else
        func_021BEDB8((int)p, 4, 21);
    func_021BEE80((int)p, 2, 1);
    func_021BEE80((int)p, 3, 1);
    func_021BEE80((int)p, 4, 1);
}





void func_021BCCA8(char *p)
{
    func_021BEDF0((int)((u8 *)p), 8, 0);
    func_02041300(1, 0, 0, 17, 32, 6, 0);
    func_02041B6C(1);
    func_021BEDB8((int)p, 2, 1);
    func_021BEDB8((int)p, 3, 0);
    if (func_02012BF8(**(int * *)&((struct Obj25589 *)p)->f0, 16) == 1)
        func_021BEDB8((int)p, 4, 7);
    else
        func_021BEDB8((int)p, 4, 6);
    func_021BEE80((int)p, 2, 0);
    func_021BEE80((int)p, 3, 0);
    func_021BEE80((int)p, 4, 0);
    func_021BED1C((int)p);
}





void func_021BCD30(u8 *p)
{
    p[0x2b8] = 1;
}





/*
 * trailing: 2-byte alignment padding at 0x021BCDA2.
 */
void func_021BCD3C(u8 *p)
{
    p[0x2b8] = 2;
    func_020414EC(1);
    func_020414EC(3);
    func_020414EC(5);
    func_02041B6C(1);
    func_02041B6C(3);
    func_02041B6C(5);
    func_02041300(0, 0, 0, 0, 32, 21, 0);
    func_02041B6C(0);
    func_02041EE4(1, 3, 0);
    func_02041EE4(5, 3, 0);
}





/*
 * trailing: 2-byte alignment padding at 0x021BCE0A.
 * BEE38 parameters widened: original call uses signed full-width loads.
 */
void func_021BCDA4(char *p)
{
    unsigned int i;
    short x, y;
    func_02041EE4(4, 3, 48);
    func_02041EE4(7, 3, 48);
    func_0202CB4C(*(struct WinMgr * *)&((struct Obj14673 *)p)->f20, 0, 0, 27);
    func_0202CD94(*(struct WinMgr * *)&((struct Obj14673 *)p)->f20);
    for (i = 2; i <= 4; i++) {
        func_021BEE58(p, i, &x, &y, 0);
        y += 48;
        func_021BEE38(p, i, x, y, 0);
    }
}





void func_021BCE0C(char *p, int delta)
{
    int magnitude;
    int direction;
    ((struct Obj01779 *)p)->f2C8 = 48;
    ((struct Obj01779 *)p)->f2CA = delta;
    magnitude = delta < 0 ? -delta : delta;
    direction = delta / (delta < 0 ? -delta : delta);
    func_0202CD64(*(struct WinMgr * *)&((struct Obj01779 *)p)->f20, 0, 0, direction, 48 / magnitude);
}





/*
 * BEE38 parameters widened: original call uses signed full-width loads.
 */
int func_021BCE58(char *p)
{
    unsigned int i;
    short x, y;
    int magnitude;
    if (((struct Obj00085 *)p)->f2C8 == 0) return 0;
    func_0202CD94(*(struct WinMgr * *)&((struct Obj00085 *)p)->f20);
    func_02041EE4(4, 4, ((struct Obj00085 *)p)->f2CA);
    func_02041EE4(7, 4, ((struct Obj00085 *)p)->f2CA);
    for (i = 2; i <= 4; i++) {
        func_021BEE58(p, i, &x, &y, 0);
        y += ((struct Obj00085 *)p)->f2CA;
        func_021BEE38(p, i, x, y, 0);
    }
    magnitude = ((struct Obj00085 *)p)->f2CA;
    if (magnitude < 0) magnitude = -magnitude;
    ((struct Obj00085 *)p)->f2C8 -= (u16)magnitude;
    return 1;
}





u32 func_021BCEEC(u32 a, u32 b)
{
    return b;
}





u32 func_021BCEF0(u32 a, u32 b)
{
    return b;
}






u16 func_021BCEF4(int a0, int a1)
{
    (void)a0;
    return d_021C072E[a1];
}






/*
 * Meeting-room / map index helper: halfword lookup into the table at
 * 0x021C072E by the second argument.  Blocker target of func_021BEA54.
 *
 * Addresses are Black-image addresses.
 */
u16 func_021BCF00(int a0, int a1)
{
    (void)a0;
    return d_021C072E[a1];
}






/*
 * 2026-10-05 (wD5 lane01): EXACT. The three co-live values are coloured in declaration order
 *   (lowest register first): declare i, v, rec in that order at the top.
 * 2026-10-05 (wD4 lane16): also tried a do/while with u32 counter declared after the pointer, and a u8 counter with break: both worse (17 and 27 bytes). Residue unchanged (rec=r4/counter=r2 in image).
 * 2026-10-04 (wave D2 lane 08): re-tested, still DIFF (8 bytes): image rec=r4, counter=r2; ours rec=r2, counter=r4. Colouring looks priority ordered (counter gets the callee-saved register in ours); no source form found that lowers the pointer's priority.
 *
 * 2026-10-02: 44 bytes, size exact, one relocation resolved.  Only the colours
 * differ: the image keeps the record pointer in r4 and the loop counter in r2;
 * the compile swaps them (counter r4, pointer r2).  Tried: counter declared
 * first, int counter, do/while, break form, u32 value local, early return.
 *
 * Addresses are Black-image addresses.
 */
void func_021BCF0C(u8 *p)
{
    u32 i;
    u8 v;
    u8 *rec;

    rec = *(u8 **)(*(u8 **)p + 8);
    v = rec[6];
    if (v != 0xff) {
        for (i = 0; i < 14; i++) {
            if (v == d_021C0720[i]) {
                rec[6] = i;
                return;
            }
        }
    }
}






void func_021BCF38(u8 *p)
{
    u8 *r0 = *(u8 * *)&((struct Obj25593 *)p)->f0;
    u8 *r2 = *(u8 * *)&((struct Obj25594 *)r0)->f8;
    u8 r1 = r2[6];

    if (r1 != 0xff) {
        r2[6] = d_021C0720[r1];
    }
}






u32 func_021BCF50(u8 *p)
{
    u32 s = ((struct Obj08413 *)p)->f10;

    s = d_021C0894[s](p);
    ((struct Obj08413 *)p)->f10 = s;
    if (s == 0x1b) {
        return 0;
    }
    func_021BED68((int)p);
    func_021BE3D4(p);
    func_021C93E4(2, 6, (u32 *)(p + 0x2c4));
    return 1;
}






u32 func_021BCF8C(u8 *p)
{
    u32 z;
    u32 ra = 0x04000050;
    u32 rb = 0x04001050;
    int m;

    func_02034AC4((u32)ov067_id);
    z = 0;
    func_02043534(0);
    func_020435F4(0);
    *(volatile u16 *)&((struct Obj25595 *)ra)->f0 = z;
    *(volatile u16 *)&((struct Obj25596 *)rb)->f0 = z;
    func_0204363C(0);
    m = -16;
    func_0207D534((volatile u16 *)(ra + 0x1c), m);
    func_0207D534((volatile u16 *)(rb + 0x1c), m);
    if (func_0200CA70((struct Blk37 *)(((struct Obj25597 *)(*(u8 * *)&((struct Obj05546 *)p)->f0))->f4)) == 1) {
        ((struct Obj25599 *)(*(u8 * *)&((struct Obj25598 *)(*(u8 * *)&((struct Obj05546 *)p)->f0))->f8))->f0 = z;
    } else {
        ((struct Obj25601 *)(*(u8 * *)&((struct Obj25600 *)(*(u8 * *)&((struct Obj05546 *)p)->f0))->f8))->f0 = 1;
    }
    func_021BC3D4();
    func_021BC3F0();
    func_021BC5DC();
    func_021BC940((char *)p);
    func_021BE368(p);
    func_021BED2C((int)p);
    func_021BC9D0((int)p);
    func_0203D34C(1, 0x7b);
    func_021BCA20((char *)p);
    func_021BCDA4((char *)p);
    func_021BC790((char *)p);
    func_021BC82C((char *)p, 16, 16);
    func_021BCBB8((char *)p);
    func_021BC8EC();
    func_021BC294(p);
    func_021BC318(p);
    p[0x2b9] = 0xff;
    func_021BCF0C(p);
    return 3;
}





/*
 * volatile: hardware stores at 0x021BD0D8 and 0x021BD0DC.
 */
int func_021BD064(char *p)
{
    if (func_021BCE58(p) == 1 || func_02021ED8(*(char * *)&((struct Obj00085 *)p)->fC) != 0) return 1;
    func_021BC330((u8 *)p);
    func_021BC92C(func_021BC2AC((u8 *)p));
    func_021BCC1C((u8 *)p);
    func_021BCA78((u8 *)p);
    func_021BC800((u8 *)p);
    func_021BCA10((u8 *)p);
    func_021BED54((int)p);
    func_021BE3B4(p);
    func_021BC578(func_021BC99C((u8 *)p));
    func_0207D534((void *)0x0400006c, -16);
    func_0207D534((void *)0x0400106c, -16);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    func_02043534(0);
    func_020435F4(0);
    func_02034A5C((int)ov067_id);
    return 27;
}






u32 func_021BD100(u8 *p)
{
    if (func_02021ED8((const char *)(((struct Obj14675 *)p)->fC)) == 0) {
        return ((struct Obj14675 *)p)->f1C;
    }
    return 2;
}





int func_021BD118(u8 *p)
{
    if (func_02021ED8(*(char * *)&((struct Obj01779 *)p)->fC) != 0) return 3;
    func_021BC8B4(1);
    func_021BCA84(p);
    func_021BE564(p);
    func_021BC5B4(func_021BF418(p));
    func_021BCD30(p);
    if (p[0x2b9] == 255) {
        func_021BFEAC((char *)p, 0);
        func_0207D534((void *)0x0400006c, 0);
        func_0207D534((void *)0x0400106c, 0);
        func_021BCE0C((char *)p, -8);
        func_021BC82C((char *)p, 16, 0);
        return 4;
    } else {
        func_021BFEAC((char *)p, p[0x2b9]);
        return 4;
    }
}






u32 func_021BD19C(u8 *p)
{
    if (func_021BCE58((char *)p) == 1 || func_02021ED8((const char *)(*(u32 *)&((struct Obj00085 *)p)->fC)) != 0) {
        return 4;
    }
    switch (func_021BFF68((int)p)) {
    case 0:
        func_020061E4(0x54c);
        return func_021BE2F4(p, 0, 0, func_021BE314(p, 9));
    case 1:
        func_020061E4(0x54c);
        return func_021BE2F4(p, 0, 1, func_021BE314(p, 12));
    case 2:
        func_020061E4(0x54c);
        return func_021BE2F4(p, 0, 2, func_021BE314(p, 15));
    case 3:
        func_020061E4(0x54c);
        return func_021BE2F4(p, 0, 3, func_021BE314(p, 18));
    case 4:
        func_020061E4(0x54c);
        return func_021BE2F4(p, 0, 4, func_021BE314(p, 21));
    case 5:
        func_020061E4(0x54c);
        return func_021BE2F4(p, 0, 5, 7);
    case 6:
        func_020061E4(0x54c);
        return func_021BE2F4(p, 0, 6, 6);
    case 7:
        func_020061E4(0x646);
        func_021BE324(p);
        break;
    case 8:
        func_020061E4(0x556);
        ((struct Obj25602 *)(*(u8 * *)&((struct Obj00085 *)p)->f0))->fC = 2;
        func_021BEDB8((int)p, 3, 8);
        return func_021BE2F4(p, 1, 3, 0x1a);
    case 9:
        func_020061E4(0x551);
        func_021BCF38(p);
        ((struct Obj25603 *)(*(u8 * *)&((struct Obj00085 *)p)->f0))->fC = 1;
        func_021BEDB8((int)p, 2, 9);
        return func_021BE2F4(p, 1, 2, 0x1a);
    case (u32)-4:
        func_020061E4(0x548);
        break;
    case (u32)-3:
        func_020061E4(0x548);
        break;
    case (u32)-2:
        func_020061E4(0x551);
        func_021BCF38(p);
        ((struct Obj25604 *)(*(u8 * *)&((struct Obj00085 *)p)->f0))->fC = 1;
        func_021BEDB8((int)p, 2, 9);
        return func_021BE2F4(p, 1, 2, 0x1a);
    }
    func_0202EA40((struct Row *)(((struct Obj00085 *)p)->f2B4));
    return 4;
}






u32 func_021BD36C(u8 *p)
{
    func_021BCD3C(p);
    func_021BEDF0((int)p, 7, 0);
    func_021BFF18((int)p);
    return ((struct Obj01779 *)p)->f18;
}






u32 func_021BD388(u8 *p)
{
    u32 *ctx = *(u32 * *)&((struct Obj00222 *)p)->f0;

    func_021C9380((struct Blk37 *)ctx[1], (u8 *)ctx[2]);
    func_021BE564(p);
    func_021BEDF0((int)p, 7, 0);
    return 4;
}






/*
 * 2026-10-05 (wD5 lane14): EXACT. func_021BFE84 takes the state byte as a
 *   second argument (its matched body uses n); the r1 load was that argument.
 * 2026-10-05 (wD4 lane16): re-read; still the single r1/r0 load at the 0x79 test after func_021C9460. No change tried that moved it (callee arity cannot explain it: the load is after the call).
 * 2026-10-04 (wave D2 lane 08): re-tested, still DIFF (2 bytes: ldrb r1/cmp r1,#0x79 in the image, r0 in ours). Also tried the 0x79 test through a u32 local and p[0x2BB]++ for the tail; no change. Lesson from func_021BE010 (same overlay): a callee that takes the byte as a second argument with r0 untouched explains an r1 load, but no call here does.
 *
 * 2026-10-02 (wave C2 lane 03): re-checked, still the same two bytes at
 * 0x021BD448: the image loads the 0x2bb byte into r1 before `cmp #0x79`.
 * The path into this compare falls through from `func_021C9460(p[0x2cc])`;
 * no later call takes the byte as a second argument (checked
 * 021BED04, 021BED10, 021BFE84).  Next idea: look at the callers' use of
 * func_021C9460 with a second argument.
 *
 * Re-verified 2026-09-27 (DIFF fixer lane): size-exact, 2 concrete bytes.
 * The three func_021C94xx symbols were wrongly hinted ov210; they live in
 * ov212's window (ov212 is co-resident with ov210), so the hints are
 * corrected to ov212 and 13 of 14 relocations now resolve.  The two differing
 * bytes are the image's `ldrb r1,[r4,r5] / cmp r1,#0x79` versus the compile's
 * `ldrb r0,... / cmp r0,#0x79` (the dead argument register is reused for the
 * load) -- the same allocator tell as func_021B6984/func_021BEA54.  The last
 * site, func_021C9460, is a Thumb-shaped linker stub (`ldr r3,[pc,#0];
 * bx r3; .word 0x020307B0`) that disasm emits as an unlabelled .word run, so
 * the `veneer` class cannot attest it; only the ARM stub shape attests
 * (docs/idioms/a-veneer-call-is-an-ordinary-extern-at-the-veneer-address.md).
 *
 * Update 2026-09-27 (recursive MATCH unblocker): 0x021C9460 was matched
 * bottom-up as src/matched/ov212_func_021C9460.c (EXACT, pkt_ov212_021C9460),
 * so the +0096 site now resolves `matched` and all 14 relocations resolve.
 * The verdict is unchanged DIFF on the same two concrete bytes (the r1/r0
 * allocator tell above); target matching cannot promote it.
 */
int func_021BD3AC(unsigned char *p)
{
    unsigned short v;
    int w;
    int r;

    if (p[0x2BB] == 0) {
        func_020061E4(0x63F);
        func_021BCC2C((char *)p);
        func_021BECF8(p);
        func_021BE820(p);
    }
    if (p[0x2BB] == 0x64)
        func_02006210();
    if (p[0x2BB] == 1) {
        func_021BCF38(p);
        *(int *)(p + 0x2CC) =
            func_021C9428(*(int *)(*(int *)p + 4), *(int *)(*(int *)p + 8), 0x807B);
        *(int *)(p + 0x2D0) = 0;
    }
    if (p[0x2BB] >= 2) {
        if (*(int *)(p + 0x2D0) == 0) {
            r = func_021C9468((struct Search *)(*(int *)(p + 0x2CC)), 0x69, &v, (u16 **)(&w));
            *(int *)(p + 0x2D0) = r;
            if (r == 1) {
                *(unsigned short *)(*(int *)p + 0x14) = v;
                *(int *)(*(int *)p + 0x10) = w;
                func_021C9460(*(int *)(p + 0x2CC));
            }
        }
    }
    if (p[0x2BB] == 0x79) {
        if (*(int *)(p + 0x2D0) == 1) {
            if (*(unsigned short *)(*(int *)p + 0x14) != 0) {
                func_020061E4(0x76F);
                func_021BED04(p);
            } else {
                func_020061E4(0x557);
                func_021BED10(p);
            }
            p[0x2BB] = 0;
            return 8;
        }
    } else {
        func_021BFE84((int)p, p[0x2BB]);
        p[0x2BB] = p[0x2BB] + 1;
    }
    return 7;
}





int func_021BD4AC(u8 *p)
{
    if (func_021C00FC(p) == 1) {
        u8 *head = *(u8 * *)&((struct Obj03936 *)p)->f0;
        if (((struct Obj14677 *)head)->f14 != 0) {
            ((struct Obj14677 *)head)->fC = 0;
            return 26;
        }
        func_021BCCA8((char *)p);
        func_021BE7E4(p);
        if (func_020355C4() == 1)
            func_020260F4(((struct Obj03936 *)p)->f2B0, 0);
        else
            func_020260F4(((struct Obj03936 *)p)->f2B0, 1);
        func_021BCF0C(p);
        return 4;
    }
    return 8;
}





int func_021BD500(u8 *p)
{
    switch (p[0x2BA]) {
    case 0:
        p[0x2B9] = 0;
        func_021BC8B4(1);
        func_021BE83C(p);
        func_021C0234((char *)p);
        p[0x2BA]++;
    case 1:
        if (func_021B7A64(((struct Obj06694 *)p)->f1E0) == 0) {
            func_021BF480((int)p);
            func_021BCAC8(p);
            func_021BC5C8();
            func_021BCD30(p);
            p[0x2BA] = 0;
            return 10;
        }
    }
    return 9;
}






u32 func_021BD568(u8 *p)
{
    int r5 = func_021B7AB0((struct S *)(*(u32 *)&((struct Obj00085 *)p)->f1E0));

    if (r5 != -1) {
        switch (r5) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            if (func_020355C4() == 0) {
                func_020061E4(0x54c);
                func_021BE0E4(p, r5);
            }
            break;
        }
    } else {
    r5 = func_021C014C((char *)p);
    switch (r5) {
    case 0:
        func_020061E4(0x551);
        func_021BEDB8((int)p, 2, 9);
        return func_021BE2F4(p, 1, 2, 11);
    case 8:
        func_020061E4(0x551);
        func_021BEDB8((int)p, 2, 9);
        return func_021BE2F4(p, 1, 2, 11);
    case 9:
        func_020061E4(0x54c);
        func_021BE110(p);
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        func_020061E4(0x54c);
        func_021BE0E4(p, r5 - 1);
        break;
    }
    }
    return 10;
}






u32 func_021BD640(u32 p)
{
    func_021BCD3C((u8 *)p);
    func_021BF38C((u8 *)p);
    func_021C0550(p);
    return 3;
}





/*
 * prototype: 021BCAF8 receives the caller's explicit r0 even though its body ignores it; BC5C8 reads no inputs.
 */
int func_021BD658(u8 *p)
{
    switch (p[0x2BA]) {
    case 0:
        p[0x2B9] = 1;
        func_021BC8B4(1);
        func_021BE8F8(p);
        func_021C02DC((char *)p);
        p[0x2BA]++;
    case 1:
        if (func_021B7A64(((struct Obj06695 *)p)->f1E0) == 0) {
            func_021BF728(p, 0);
            func_021BF4A4((char *)p);
            func_021BCAF8(p);
            func_021BC5C8();
            func_021BCD30(p);
            p[0x2BA] = 0;
            return 13;
        }
    }
    return 12;
}






u32 func_021BD6C4(u8 *p)
{
    u32 ret = 13;
    u32 r5 = func_021B7AB0((struct S *)(*(u32 *)&((struct Obj00085 *)p)->f1E0));

    switch (r5) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        if (func_020355C4() == 0) {
            func_020061E4(0x54c);
            func_021BE12C(p, r5);
        }
        break;
    case (u32)-12:
        break;
    case (u32)-11:
    case (u32)-10:
    case (u32)-9:
    case (u32)-8:
        func_021BF728(p, 0);
        break;
    case (u32)-7:
        func_021BEDB8((int)p, 6, 12);
        p[0x2c1] = 6;
        ((struct Obj00085 *)p)->f14 = 0;
        ((struct Obj00085 *)p)->f18 = ret;
        ret = 0x18;
        break;
    case (u32)-6:
        func_021BEDB8((int)p, 5, 13);
        p[0x2c1] = 5;
        ((struct Obj00085 *)p)->f14 = 0;
        ((struct Obj00085 *)p)->f18 = ret;
        ret = 0x18;
        break;
    case (u32)-5:
        func_021BEDB8((int)p, 6, 12);
        return func_021BE2F4(p, 1, 6, 13);
    case (u32)-4:
        func_021BEDB8((int)p, 5, 13);
        return func_021BE2F4(p, 1, 5, 13);
    case (u32)-3:
    case (u32)-2:
        func_021BF81C((char *)p);
        func_021BFABC((char *)p, 0, (*(u8 **)(*(u8 * *)&((struct Obj00085 *)p)->f0 + 8))[2]);
        p[0x2c1] = 0x39;
        ((struct Obj00085 *)p)->f14 = 1;
        ((struct Obj00085 *)p)->f18 = ret;
        ret = 0x18;
        break;
    case (u32)-1:
        r5 = func_021C014C((char *)p);
        switch (r5) {
        case 0:
            func_020061E4(0x551);
            func_021BEDB8((int)p, 2, 9);
            return func_021BE2F4(p, 1, 2, 14);
        case 8:
            func_020061E4(0x551);
            func_021BEDB8((int)p, 2, 9);
            return func_021BE2F4(p, 1, 2, 14);
        case 9:
            func_020061E4(0x54c);
            func_021BE178(p);
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            func_020061E4(0x54c);
            func_021BF728(p, 0);
            func_021BE12C(p, r5 - 1);
            break;
        }
        break;
    }
    func_021BF6E0((char *)p);
    return ret;
}






u32 func_021BD898(u8 *p)
{
    func_021BCD3C(p);
    func_021BF38C(p);
    func_021C0550((int)p);
    return 3;
}





int func_021BD8B0(u8 *p)
{
    switch (p[0x2BA]) {
    case 0:
        p[0x2B9] = 2;
        func_021BC8B4(1);
        func_021BE9D4(p);
        func_021C0384((char *)p);
        p[0x2BA]++;
    case 1:
        if (func_021B7A64(((struct Obj06696 *)p)->f1E0) == 0) {
            func_021BF728(p, 0);
            func_021BF500((char *)p);
            func_021BCB28(p);
            func_021BC5C8();
            func_021BCD30(p);
            p[0x2BA] = 0;
            return 16;
        }
    }
    return 15;
}






u32 func_021BD920(u8 *p)
{
    u32 ret = 16;
    u32 r5 = func_021B7AB0((struct S *)(*(u32 *)&((struct Obj00085 *)p)->f1E0));

    switch (r5) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        if (func_020355C4() == 0) {
            func_020061E4(0x54c);
            func_021BE190(p, r5);
        }
        break;
    case (u32)-12:
        break;
    case (u32)-11:
    case (u32)-10:
    case (u32)-9:
    case (u32)-8:
        func_021BF728(p, 0);
        break;
    case (u32)-7:
        func_021BEDB8((int)p, 6, 12);
        p[0x2c1] = 6;
        ((struct Obj00085 *)p)->f14 = 0;
        ((struct Obj00085 *)p)->f18 = ret;
        ret = 0x18;
        break;
    case (u32)-6:
        func_021BEDB8((int)p, 5, 13);
        p[0x2c1] = 5;
        ((struct Obj00085 *)p)->f14 = 0;
        ((struct Obj00085 *)p)->f18 = ret;
        ret = 0x18;
        break;
    case (u32)-5:
        func_021BEDB8((int)p, 6, 12);
        return func_021BE2F4(p, 1, 6, 16);
    case (u32)-4:
        func_021BEDB8((int)p, 5, 13);
        return func_021BE2F4(p, 1, 5, 16);
    case (u32)-3:
    case (u32)-2:
        func_021BF81C((char *)p);
        func_021BFABC((char *)p, 0, (u16)func_021BCEF0((u32)p, (*(u8 **)(*(u8 * *)&((struct Obj00085 *)p)->f0 + 8))[3]));
        func_021BFABC((char *)p, 1, (u16)func_021BCEF0((u32)p, (*(u8 **)(*(u8 * *)&((struct Obj00085 *)p)->f0 + 8))[4]));
        p[0x2c1] = 0x39;
        ((struct Obj00085 *)p)->f14 = 1;
        ((struct Obj00085 *)p)->f18 = ret;
        ret = 0x18;
        break;
    case (u32)-1:
        r5 = func_021C014C((char *)p);
        switch (r5) {
        case 0:
            func_020061E4(0x551);
            func_021BEDB8((int)p, 2, 9);
            return func_021BE2F4(p, 1, 2, 0x11);
        case 8:
            func_020061E4(0x551);
            func_021BEDB8((int)p, 2, 9);
            return func_021BE2F4(p, 1, 2, 0x11);
        case 9:
            func_020061E4(0x54c);
            func_021BE20C(p);
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            func_020061E4(0x54c);
            func_021BF728(p, 0);
            func_021BE190(p, r5 - 1);
            break;
        }
        break;
    }
    func_021BF6E0((char *)p);
    return ret;
}






u32 func_021BDB1C(u8 *p)
{
    func_021BCD3C(p);
    func_021BF38C(p);
    func_021C0550((int)p);
    return 3;
}





/*
 * prototype: 021BCB58 receives the caller's explicit r0 even though its body ignores it; BC5C8 reads no inputs.
 */
int func_021BDB34(u8 *p)
{
    switch (p[0x2BA]) {
    case 0:
        p[0x2B9] = 3;
        func_021BC8B4(1);
        func_021BEB0C(p);
        func_021C0434((char *)p);
        p[0x2BA]++;
    case 1:
        if (func_021B7A64(((struct Obj06697 *)p)->f1E0) == 0) {
            func_021BF728(p, 0);
            func_021BF55C((char *)p);
            func_021BCB58(p);
            func_021BC5C8();
            func_021BCD30(p);
            p[0x2BA] = 0;
            return 19;
        }
    }
    return 18;
}






u32 func_021BDBA4(u8 *p)
{
    u32 ret = 19;
    u32 r5 = func_021B7AB0((struct S *)(*(u32 *)&((struct Obj00085 *)p)->f1E0));

    switch (r5) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        if (func_020355C4() == 0) {
            func_020061E4(0x54c);
            func_021BE22C(p, r5);
        }
        break;
    case (u32)-12:
        break;
    case (u32)-11:
    case (u32)-10:
    case (u32)-9:
    case (u32)-8:
        func_021BF728(p, 0);
        break;
    case (u32)-7:
        func_021BEDB8((int)p, 6, 12);
        p[0x2c1] = 6;
        ((struct Obj00085 *)p)->f14 = 0;
        ((struct Obj00085 *)p)->f18 = ret;
        ret = 0x18;
        break;
    case (u32)-6:
        func_021BEDB8((int)p, 5, 13);
        p[0x2c1] = 5;
        ((struct Obj00085 *)p)->f14 = 0;
        ((struct Obj00085 *)p)->f18 = ret;
        ret = 0x18;
        break;
    case (u32)-5:
        func_021BEDB8((int)p, 6, 12);
        return func_021BE2F4(p, 1, 6, 19);
    case (u32)-4:
        func_021BEDB8((int)p, 5, 13);
        return func_021BE2F4(p, 1, 5, 19);
    case (u32)-3:
    case (u32)-2:
        func_021BF81C((char *)p);
        func_021BFABC((char *)p, 0, (*(u8 **)(*(u8 * *)&((struct Obj00085 *)p)->f0 + 8))[5]);
        p[0x2c1] = 0x39;
        ((struct Obj00085 *)p)->f14 = 1;
        ((struct Obj00085 *)p)->f18 = ret;
        ret = 0x18;
        break;
    case (u32)-1:
        r5 = func_021C014C((char *)p);
        switch (r5) {
        case 0:
            func_020061E4(0x551);
            func_021BEDB8((int)p, 2, 9);
            return func_021BE2F4(p, 1, 2, 0x14);
        case 8:
            func_020061E4(0x551);
            func_021BEDB8((int)p, 2, 9);
            return func_021BE2F4(p, 1, 2, 0x14);
        case 9:
            func_020061E4(0x54c);
            func_021BE278(p);
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            func_020061E4(0x54c);
            func_021BF728(p, 0);
            func_021BE22C(p, r5 - 1);
            break;
        }
        break;
    }
    func_021BF6E0((char *)p);
    return ret;
}






u32 func_021BDD78(u8 *p)
{
    func_021BCD3C(p);
    func_021BF38C(p);
    func_021C0550((int)p);
    return 3;
}





/*
 * prototype: 021BCB88 receives the caller's explicit r0 even though its body ignores it; BC5C8 reads no inputs.
 */
int func_021BDD90(u8 *p)
{
    switch (p[0x2BA]) {
    case 0:
        p[0x2B9] = 4;
        func_021BC8B4(1);
        func_021BEBE8(p);
        func_021C04CC((char *)p);
        p[0x2BA]++;
    case 1:
        if (func_021B7A64(((struct Obj06698 *)p)->f1E0) == 0) {
            func_021BF728(p, 0);
            func_021BF5B8((char *)p);
            func_021BCB88(p);
            func_021BC5C8();
            func_021BCD30(p);
            p[0x2BA] = 0;
            return 22;
        }
    }
    return 21;
}






u32 func_021BDE00(u8 *p)
{
    u32 r5;
    u32 ret = 22;

    r5 = func_021B7AB0((struct S *)(*(u32 *)&((struct Obj00085 *)p)->f1E0));

    switch (r5) {
    case 0:
    case 1:
    case 2:
    case 3:
        if (func_020355C4() == 0) {
            func_020061E4(0x54c);
            func_021BE290(p, r5);
        }
        break;
    case (u32)-12:
        break;
    case (u32)-11:
    case (u32)-10:
    case (u32)-9:
    case (u32)-8:
        func_021BF728(p, 0);
        break;
    case (u32)-7:
        func_021BEDB8((int)p, 6, 12);
        p[0x2c1] = 6;
        ((struct Obj00085 *)p)->f14 = 0;
        ((struct Obj00085 *)p)->f18 = ret;
        ret = 0x18;
        break;
    case (u32)-6:
        func_021BEDB8((int)p, 5, 13);
        p[0x2c1] = 5;
        ((struct Obj00085 *)p)->f14 = 0;
        ((struct Obj00085 *)p)->f18 = ret;
        ret = 0x18;
        break;
    case (u32)-5:
        func_021BEDB8((int)p, 6, 12);
        return func_021BE2F4(p, 1, 6, 22);
    case (u32)-4:
        func_021BEDB8((int)p, 5, 13);
        return func_021BE2F4(p, 1, 5, 22);
    case (u32)-3:
    case (u32)-2:
        func_021BF658((char *)p);
        func_021BF81C((char *)p);
        func_021BFB24((char *)p);
        p[0x2c1] = 0x39;
        ((struct Obj00085 *)p)->f14 = 1;
        ((struct Obj00085 *)p)->f18 = ret;
        ret = 0x18;
        break;
    case (u32)-1:
        r5 = func_021C01C0((char *)p);
        switch (r5) {
        case 0:
            func_020061E4(0x551);
            func_021BEDB8((int)p, 2, 9);
            return func_021BE2F4(p, 1, 2, 0x17);
        case 8:
            func_020061E4(0x551);
            func_021BEDB8((int)p, 2, 9);
            return func_021BE2F4(p, 1, 2, 0x17);
        case 9:
            func_020061E4(0x54c);
            func_021BE2DC(p);
            break;
        case 1:
        case 2:
        case 3:
        case 4:
            func_020061E4(0x54c);
            func_021BF728(p, 0);
            func_021BE290(p, r5 - 1);
            break;
        }
        break;
    }
    func_021BF6E0((char *)p);
    return ret;
}






u32 func_021BDFA8(u8 *p)
{
    func_021BCD3C(p);
    func_021BF38C(p);
    func_021C0550((int)p);
    return 3;
}





int func_021BDFC0(u8 *p)
{
    switch (((struct Obj04618 *)p)->f14) {
    case 0:
        if (func_021B7AB0(((struct Obj04618 *)p)->f1E0) == -1)
            ++((struct Obj04618 *)p)->f14;
        break;
    case 1:
        if (p[0x2C1] != 57 && func_021BEDE0((int)p, p[0x2C1]) != 0)
            break;
        ((struct Obj04618 *)p)->f14 = 0;
        func_021BF728(p, 0);
        return ((struct Obj04618 *)p)->f18;
    }
    return 24;
}






int func_021BE010(u8 *p)
{
    if (*(u8 *)(p + 0x2C0) == 0) {
        switch (*(u8 *)(p + 0x2C2)) {
        case 0:
        case 2:
            if (*(u8 *)(p + 0x2C3) == 0) {
                func_021BFF30((int)p, *(u8 *)(p + 0x2C1), 1);
                *(u8 *)(p + 0x2C3) = 4;
                (*(u8 *)(p + 0x2C2))++;
            } else {
                (*(u8 *)(p + 0x2C3))--;
            }
            break;
        case 1:
        case 3:
            if (*(u8 *)(p + 0x2C3) == 0) {
                func_021BFF30((int)p, *(u8 *)(p + 0x2C1), 2);
                *(u8 *)(p + 0x2C3) = 4;
                (*(u8 *)(p + 0x2C2))++;
            } else {
                (*(u8 *)(p + 0x2C3))--;
            }
            break;
        case 4:
            if (func_020355C4() == 1)
                func_021BFF30((int)p, *(u8 *)(p + 0x2C1), 1);
            else
                func_021BFF30((int)p, *(u8 *)(p + 0x2C1), 3);
            return *(u32 *)(p + 0x1C);
        }
    } else if (func_021BEDE0((int)p, *(u8 *)(p + 0x2C1)) == 0) {
        if (*(u32 *)(p + 0x1E0) != 0)
            func_021BF728(p, 0);
        return *(u32 *)(p + 0x1C);
    }
    return 0x19;
}






u32 func_021BE0C4(u8 *p)
{
    func_021BFF18((int)p);
    func_021BCE0C((char *)p, 8);
    func_021BC82C((char *)p, 0, 16);
    return 1;
}






void func_021BE0E4(u8 *p, u32 v)
{
    (*(u8 **)(*(u8 * *)&((struct Obj00085 *)p)->f0 + 8))[1] = v;
    func_021B93D4(((struct Obj00085 *)p)->f1E0, v);
    func_021BE8B8(p);
    func_021BF85C((char *)p, (u16)v, 1);
}






void func_021BE110(u8 *p)
{
    u32 t = *(u32 *)&((struct Obj00222 *)p)->f0;
    *(u8 *)(((struct Obj25605 *)t)->f8 + 1) = 0;
    func_021BE8B8(p);
    func_021BF85C((char *)p, 0, 1);
}





void func_021BE12C(u8 *p, int n)
{
    int value = n + func_021B93B8(((struct Obj10915 *)p)->f1E0);
    u8 *data = *(u8 * *)&((struct Obj25606 *)(*(u8 * *)&((struct Obj10915 *)p)->f0))->f8;
    if (data[2] == value) {
        data[2] = 255;
        func_021BF85C((char *)p, (u16)n, (unsigned int)0);
    } else {
        data[2] = value;
        func_021BF85C((char *)p, (u16)n, (unsigned int)1);
    }
    func_021B93D4(((struct Obj10915 *)p)->f1E0, n);
    func_021BE978(p);
}






void func_021BE178(u8 *p)
{
    u32 t = *(u32 *)&((struct Obj00222 *)p)->f0;
    *(u8 *)(((struct Obj25607 *)t)->f8 + 2) = 0xff;
    func_021BE978(p);
    func_021BF81C((char *)p);
}





/*
 * extent: compiled through 021BE20A; remaining 00 00 at 021BE20A is two-byte alignment padding before 021BE20C.
 * prototype: 93D4's s16 parameter widened because the original forwards full r4 without truncation.
 */
void func_021BE190(u8 *p, int n)
{
    int value = func_021BCEEC((u32)p, n + func_021B93B8(((struct Obj04619 *)p)->f1E0));
    u8 *data = *(u8 * *)&((struct Obj25608 *)(*(u8 * *)&((struct Obj04619 *)p)->f0))->f8;
    if (data[3] == 255) {
        data[3] = value;
    } else if (data[4] == 255) {
        if (data[3] == value)
            data[3] = 255;
        else
            data[4] = value;
    } else if (data[3] == value) {
        data[3] = data[4];
        (*(u8 **)(*(u8 * *)&((struct Obj04619 *)p)->f0 + 8))[4] = 255;
    } else if (data[4] == value) {
        data[4] = 255;
    } else {
        data[3] = data[4];
        (*(u8 **)(*(u8 * *)&((struct Obj04619 *)p)->f0 + 8))[4] = value;
    }
    func_021B93D4(((struct Obj04619 *)p)->f1E0, n);
    func_021BEA54(p);
    data = *(u8 * *)&((struct Obj25609 *)(*(u8 * *)&((struct Obj04619 *)p)->f0))->f8;
    func_021BF89C((char *)p, data[3], data[4]);
}






void func_021BE20C(u8 *p)
{
    (*(u8 **)(*(u8 * *)&((struct Obj00222 *)p)->f0 + 8))[3] = 0xff;
    (*(u8 **)(*(u8 * *)&((struct Obj00222 *)p)->f0 + 8))[4] = 0xff;
    func_021BEA54(p);
    func_021BF81C((char *)p);
}





/*
 * ABI: 93D4 receives full entry index in r1 without caller-side truncation;
 *      widen its legacy s16 declaration. F85C explicitly narrows r1 to u16.
 */
void func_021BE22C(u8 *p, int index)
{
    int sum = index + func_021B93B8(*(char * *)&((struct Obj10917 *)p)->f1E0);
    u8 *data = *(u8 * *)&((struct Obj25610 *)(*(u8 * *)&((struct Obj10917 *)p)->f0))->f8;
    if (data[5] == sum) {
        data[5] = 255;
        func_021BF85C((char *)p, (u16)index, 0);
    } else {
        data[5] = sum;
        func_021BF85C((char *)p, (u16)index, 1);
    }
    func_021B93D4(*(struct S * *)&((struct Obj10917 *)p)->f1E0, index);
    func_021BEB8C(p);
}






void func_021BE278(u8 *p)
{
    u32 t = *(u32 *)&((struct Obj00222 *)p)->f0;
    *(u8 *)(((struct Obj25611 *)t)->f8 + 5) = 0xff;
    func_021BEB8C(p);
    func_021BF81C((char *)p);
}





/*
 * ABI: 93D4 receives full entry index in r1 without caller-side truncation;
 *      widen its legacy s16 declaration. FA7C explicitly narrows r1 to u16.
 */
void func_021BE290(u8 *p, int index)
{
    int sum = index + func_021B93B8(*(char * *)&((struct Obj10919 *)p)->f1E0);
    u8 *data = *(u8 * *)&((struct Obj25612 *)(*(u8 * *)&((struct Obj10919 *)p)->f0))->f8;
    if (data[6] == sum) {
        data[6] = 255;
        func_021BFA7C((char *)p, (u16)index, 0);
    } else {
        data[6] = sum;
        func_021BFA7C((char *)p, (u16)index, 1);
    }
    func_021B93D4(*(struct S * *)&((struct Obj10919 *)p)->f1E0, index);
    func_021BF618((char *)p);
}






void func_021BE2DC(u8 *p)
{
    u32 t = *(u32 *)&((struct Obj14678 *)p)->f0;
    *(u8 *)(((struct Obj25613 *)t)->f8 + 6) = 0xff;
    func_021BF618((char *)p);
    func_021BF81C((char *)p);
}





u32 func_021BE2F4(u8 *p, u32 a, u32 b, u32 c)
{
    p[0x2c0] = a;
    p[0x2c1] = b;
    p[0x2c2] = 0;
    p[0x2c3] = 0;
    ((struct Obj00085 *)p)->f1C = c;
    return 25;
}





u32 func_021BE314(u8 *p, u32 a)
{
    p[0x2ba] = 0;
    ((struct Obj00085 *)p)->f18 = a;
    return 5;
}





/*
 * tail: 021BE366..021BE368 is zero alignment padding.
 * proof: 071CC forwards to 0319A4, which forwards fixed r1=0x36 to
 *        033B68; their full matched bodies use no incoming r2/r3.
 * ABI: 02012BF8's full 20-byte body preserves r1 across EC0/C404 and
 *      supplies only r0/r1 to C44C. EC0 reads only r0; C404 forwards r0
 *      through C40C/071CC with fixed r1=0x36. C44C reads r0/r1 only.
 *      Legacy trailing a2/a3 are omitted; all original visible inputs remain.
 */
void func_021BE324(u8 *p)
{
    if (func_02012BF8((int)(**(void ** *)&((struct Obj10921 *)p)->f0), 16) == 1) {
        func_02012BE0(**(void ** *)&((struct Obj10921 *)p)->f0, 16, 0);
        func_021BEDB8((int)p, 4, 6);
    } else {
        func_02012BE0(**(void ** *)&((struct Obj10921 *)p)->f0, 16, 1);
        func_021BEDB8((int)p, 4, 7);
    }
}





void func_021BE368(u8 *p)
{
    unsigned i;
    func_02045088(123);
    for (i = 0; i < 16; i++) {
        const struct Record *r = &d_021C0900[i];
        *(unsigned *)(p + i * 8 + 0x14c) = func_020450F0(r->a, r->b, r->c, r->d, r->e, r->f, 1);
    }
    func_021BE4B4(p);
}






void func_021BE3B4(char *p)
{
    unsigned int i;
    for (i = 0; i < 0x10; i++)
    {
        func_020452E8(*(void **)(p + 0x14c + i * 8));
    }
    func_020450C8();
}





/*
 * lever: each int offset is assigned 0x1DC, then its final literal;
 *        spilled locals retain both stores without a reload.
 * note 2026-10-05 (wave D9r lane 131): removed the 4 dead first assignments
 * (`release = 0x1dc;` before `release = 0x14c;`; `clear = 0x1dc;` before
 * `clear = 0x150;` and 2 more). Game code has no line table, so these were
 * stand-ins. The plain single assignment gives EXACT in --lang c99 and
 * --lang c: the output bytes do not change. Older text in this header that
 * asks for the double assignment is superseded.
 */
void func_021BE3D4(u8 *p)
{
    int release, clear, get, flag;
    unsigned i;
    func_0201C4E4(*(struct PrintSys * *)&((struct Obj08413 *)p)->f1DC);
    release = 0x14c;
    clear = 0x150;
    get = 0x14c;
    flag = 0x150;
    for (i = 0; i < 16; i++) {
        struct PrintSys *ps = *(struct PrintSys * *)&((struct Obj08413 *)p)->f1DC;
        u8 *record = p + i * 8;
        if (record[flag] != 0 && func_0201C6C4(ps, func_02045770(*(struct Descriptor **)(record + get))) == 0) {
            func_02045334(*(struct Descriptor **)(record + release));
            record[clear] = 0;
        }
    }
}





void func_021BE44C(u8 *p, int slot, u32_021BE44C message, int x, int y, u16 color, u32_021BE44C mode)
{
    struct U16Vec *text = func_02045EC0(*(struct MsgBank * *)&((struct Obj00222 *)p)->f1D0, message);
    func_021B6AE4(p + 0x14c + slot * 8, (void *)(((struct Obj00222 *)p)->f1DC), x, y, (u32_021BE44C)text, ((struct Obj00222 *)p)->f1CC, color, mode);
    func_02045808(text);
}






void func_021BE49C(u8 *p)
{
    func_02045374((struct Cfg *)(((struct Obj14680 *)p)->f0));
    func_02041B6C(func_02045730((struct Descriptor *)(((struct Obj14680 *)p)->f0)));
}






void func_021BE4B4(u8 *p)
{
    if (*(u8 *)(*(u32_021BE4B4 *)(*(u32_021BE4B4 *)&((struct Obj00222 *)p)->f0 + 8)) == 0)
        func_021BE44C(p, 0, 0x12, 0, 4, 0x3C40, 0);
    else
        func_021BE44C(p, 0, 0x11, 0, 4, 0x3C40, 0);
    func_021BE44C(p, 2, 0xC, 0x28, 4, 0x3C40, 2);
    func_021BE44C(p, 3, 0xD, 0x28, 4, 0x3C40, 2);
    func_021BE44C(p, 4, 0xE, 0x28, 4, 0x3C40, 2);
    func_021BE44C(p, 5, 0xF, 0x28, 4, 0x3C40, 2);
    func_021BE44C(p, 6, 0x10, 0x28, 4, 0x3C40, 2);
    func_021BE44C(p, 0xB, 0x14, 0x28, 4, 0x3C40, 2);
}






static inline u8 *Bytes021BE564(u8 *p)
{
    return *(u8 * *)&((struct Obj25618 *)(*(u8 * *)&((struct Obj25617 *)p)->f0))->f8;
}






void func_021BE564(u8 *p)
{
    u32_021BE564 v;
    u32_021BE564 s1;
    u32_021BE564 s2;
    u32_021BE564 s3;
    u8 w;
    u8 x;

    func_021BE49C(p + 0x14C);
    func_021BE49C(p + 0x15C);
    func_021BE49C(p + 0x164);
    func_021BE49C(p + 0x16C);
    func_021BE49C(p + 0x174);
    func_021BE49C(p + 0x17C);
    func_021BE49C(p + 0x1A4);
    func_021BE7E4(p);

    func_02043B5C((struct CharBuf *)((u32_021BE564)func_02045770((struct Descriptor *)((struct Obj00222 *)p)->f184)), 0);
    func_021BE44C(p, 7, Bytes021BE564(p)[1] + 0x19, 0x28, 4, 0x3C40, 2);
    func_021BE49C(p + 0x184);

    func_02043B5C((struct CharBuf *)((u32_021BE564)func_02045770((struct Descriptor *)((struct Obj00222 *)p)->f18C)), 0);
    v = Bytes021BE564(p)[2];
    if (v == 0xFF)
        func_021BE44C(p, 8, 0x5F, 8, 4, 0x3C40, 2);
    else
        func_021BE44C(p, 8, v + 0x33, 8, 4, 0x3C40, 2);
    func_021BE49C(p + 0x18C);

    func_02043B5C((struct CharBuf *)((u32_021BE564)func_02045770((struct Descriptor *)((struct Obj00222 *)p)->f194)), 0);
    if (Bytes021BE564(p)[3] == 0xFF) {
        func_021BE44C(p, 9, 0x30, 0x40, 4, 0x3C40, 2);
    } else if (Bytes021BE564(p)[4] == 0xFF) {
        func_021BE44C(p, 9, func_021BCF00((int)p, Bytes021BE564(p)[3]), 0x40, 4, 0x3C40, 2);
    } else {
        s1 = (u32_021BE564)func_02045EC0((struct MsgBank *)(*(u32_021BE564 *)&((struct Obj00222 *)p)->f1D0), 0x31);
        func_021B6AE4(p + 0x194, (void *)(((struct Obj00222 *)p)->f1DC), 0x42, 4, s1, ((struct Obj00222 *)p)->f1CC, 0x3C40, 2);
        w = func_0201D304((struct StrObj *)s1, ((struct Obj00222 *)p)->f1CC, 0);
        func_02045808((struct U16Vec *)s1);
        x = 0x40 - (u8)(w / 2);
        s2 = (u32_021BE564)func_02045EC0((struct MsgBank *)(*(u32_021BE564 *)&((struct Obj00222 *)p)->f1D0), func_021BCF00((int)p, Bytes021BE564(p)[3]));
        func_021B6AE4(p + 0x194, (void *)(((struct Obj00222 *)p)->f1DC), x + 2, 4, s2, ((struct Obj00222 *)p)->f1CC, 0x3C40, 1);
        func_02045808((struct U16Vec *)s2);
        x += w;
        s3 = (u32_021BE564)func_02045EC0((struct MsgBank *)(*(u32_021BE564 *)&((struct Obj00222 *)p)->f1D0), func_021BCF00((int)p, Bytes021BE564(p)[4]));
        func_021B6AE4(p + 0x194, (void *)(((struct Obj00222 *)p)->f1DC), x + 2, 4, s3, ((struct Obj00222 *)p)->f1CC, 0x3C40, 0);
        func_02045808((struct U16Vec *)s3);
    }
    func_021BE49C(p + 0x194);

    func_02043B5C((struct CharBuf *)((u32_021BE564)func_02045770((struct Descriptor *)((struct Obj00222 *)p)->f19C)), 0);
    v = Bytes021BE564(p)[5];
    if (v == 0xFF)
        func_021BE44C(p, 10, 0x6A, 0x28, 4, 0x3C40, 2);
    else
        func_021BE44C(p, 10, v + 0x60, 0x28, 4, 0x3C40, 2);
    func_021BE49C(p + 0x19C);
}






void func_021BE7E4(u8 *p)
{
    u32_021BE7E4 z = 0;

    func_02043B5C((struct CharBuf *)((u32_021BE7E4)func_02045770((struct Descriptor *)*(u32_021BE7E4 *)&((struct Obj00222 *)p)->f154)), 0);
    func_021BE44C(p, 1, 1, 0, 4, 0x440, z);
    func_021BE49C(p + 0x154);
}






void func_021BE820(u8 *p)
{
    func_02043B5C((struct CharBuf *)((u32_021BE820)func_02045770((struct Descriptor *)((struct Obj14681 *)p)->f154)), 0);
    func_02045334((struct Descriptor *)((struct Obj14681 *)p)->f154);
}





void func_021BE83C(u8 *p)
{
    func_021BE49C(p + 0x14c);
    func_02043B5C(func_02045770(*(struct Descriptor * *)&((struct Obj00222 *)p)->f154), 0);
    func_021BE44C(p, 1, 4, 0, 4, 0x440, 0);
    func_021BE49C(p + 0x154);
    func_02043B5C(func_02045770(*(struct Descriptor * *)&((struct Obj00222 *)p)->f1AC), 0);
    func_021BE44C(p, 12, 12, 40, 0, 0x3c40, 2);
    func_021BE49C(p + 0x1ac);
    func_021BE8B8(p);
}





void func_021BE8B8(u8 *p)
{
    func_02043B5C(func_02045770(*(struct Descriptor * *)&((struct Obj00222 *)p)->f1B4), 0);
    func_021BE44C(p, 13, (*(u8 **)(*(u8 * *)&((struct Obj00222 *)p)->f0 + 8))[1] + 25, 48, 0, 0x3c40, 2);
    func_021BE49C(p + 0x1b4);
}






void func_021BE8F8(u8 *p)
{
    func_021BE49C(p + 0x14C);
    func_02043B5C((struct CharBuf *)((u32_021BE8F8)func_02045770((struct Descriptor *)*(u32_021BE8F8 *)&((struct Obj00222 *)p)->f154)), 0);
    func_021BE44C(p, 1, 5, 0, 4, 0x440, 0);
    func_021BE49C(p + 0x154);
    func_02043B5C((struct CharBuf *)((u32_021BE8F8)func_02045770((struct Descriptor *)*(u32_021BE8F8 *)&((struct Obj00222 *)p)->f1AC)), 0);
    func_021BE44C(p, 0xC, 0xD, 0x28, 0, 0x3C40, 2);
    func_021BE49C(p + 0x1AC);
    func_021BE978(p);
}





/*
 * tail: 021BE9D2..021BE9D4 is zero alignment padding.
 */
void func_021BE978(u8 *p)
{
    unsigned message;
    func_02043B5C(func_02045770(*(struct Descriptor * *)&((struct Obj00222 *)p)->f1B4), 0);
    message = (*(u8 **)(*(u8 * *)&((struct Obj00222 *)p)->f0 + 8))[2];
    if (message != 255) func_021BE44C(p, 13, message + 51, 48, 0, 0x3c40, 2);
    else func_021BE44C(p, 13, 95, 48, 0, 0x3c40, 2);
    func_021BE49C(p + 0x1b4);
}






void func_021BE9D4(u8 *p)
{
    func_021BE49C(p + 0x14C);
    func_02043B5C((struct CharBuf *)((u32_021BE9D4)func_02045770((struct Descriptor *)*(u32_021BE9D4 *)&((struct Obj00222 *)p)->f154)), 0);
    func_021BE44C(p, 1, 6, 0, 4, 0x440, 0);
    func_021BE49C(p + 0x154);
    func_02043B5C((struct CharBuf *)((u32_021BE9D4)func_02045770((struct Descriptor *)*(u32_021BE9D4 *)&((struct Obj00222 *)p)->f1AC)), 0);
    func_021BE44C(p, 0xC, 0xE, 0x28, 0, 0x3C40, 2);
    func_021BE49C(p + 0x1AC);
    func_021BEA54(p);
}






void func_021BEA54(u8 *p)
{
    u8 c;

    func_02043B5C((struct CharBuf *)((u32_021BEA54)func_02045770((struct Descriptor *)*(u32_021BEA54 *)&((struct Obj00222 *)p)->f1B4)), 0);
    func_02043B5C((struct CharBuf *)((u32_021BEA54)func_02045770((struct Descriptor *)((struct Obj00222 *)p)->f1BC)), 0);
    c = ((u8 *)*(u32_021BEA54 *)(*(u32_021BEA54 *)&((struct Obj00222 *)p)->f0 + 8))[3];
    if (c != 0xFF)
        func_021BE44C(p, 0xD, func_021BCF00((int)p, c), 0x30, 0, 0x3C40, 2);
    else
        func_021BE44C(p, 0xD, 0x30, 0x30, 0, 0x3C40, 2);
    c = ((u8 *)*(u32_021BEA54 *)(*(u32_021BEA54 *)&((struct Obj00222 *)p)->f0 + 8))[4];
    if (c != 0xFF)
        func_021BE44C(p, 0xE, func_021BCF00((int)p, c), 0x30, 0, 0x3C40, 2);
    else
        func_021BE44C(p, 0xE, 0x30, 0x30, 0, 0x3C40, 2);
    func_021BE49C(p + 0x1B4);
    func_021BE49C(p + 0x1BC);
}






void func_021BEB0C(u8 *p)
{
    func_021BE49C(p + 0x14C);
    func_02043B5C((struct CharBuf *)((u32_021BEB0C)func_02045770((struct Descriptor *)*(u32_021BEB0C *)&((struct Obj00222 *)p)->f154)), 0);
    func_021BE44C(p, 1, 8, 0, 4, 0x440, 0);
    func_021BE49C(p + 0x154);
    func_02043B5C((struct CharBuf *)((u32_021BEB0C)func_02045770((struct Descriptor *)*(u32_021BEB0C *)&((struct Obj00222 *)p)->f1AC)), 0);
    func_021BE44C(p, 0xC, 0xF, 0x28, 0, 0x3C40, 2);
    func_021BE49C(p + 0x1AC);
    func_021BEB8C(p);
}






void func_021BEB8C(u8 *p)
{
    u32_021BEB8C v;
    u8 *b;

    func_02043B5C((struct CharBuf *)((u32_021BEB8C)func_02045770((struct Descriptor *)*(u32_021BEB8C *)&((struct Obj00222 *)p)->f1B4)), 0);
    b = (u8 *)*(u32_021BEB8C *)(*(u32_021BEB8C *)&((struct Obj00222 *)p)->f0 + 8);
    v = b[5];
    if (v != 0xFF)
        func_021BE44C(p, 0xD, v + 0x60, 0x30, 0, 0x3C40, 2);
    else
        func_021BE44C(p, 0xD, 0x6A, 0x30, 0, 0x3C40, 2);
    func_021BE49C(p + 0x1B4);
}






void func_021BEBE8(u8 *p)
{
    func_021BE49C(p + 0x14c);
    func_02043B5C(func_02045770(*(struct Descriptor * *)&((struct Obj00222 *)p)->f154), 0);
    func_021BE44C(p, 1, 7, 0, 4, 0x440, 0);
    func_021BE49C(p + 0x154);
    func_02043B5C(func_02045770(*(struct Descriptor * *)&((struct Obj00222 *)p)->f1AC), 0);
    func_021BE44C(p, 12, 16, 40, 0, 0x3c40, 2);
    func_021BE49C(p + 0x1ac);
}






void func_021BEC60(int p, int *a, u32_021BEC60 b)
{
    u32_021BEC60 x = func_021B9394(*(char * *)&((struct Obj04620 *)p)->f1E0);

    func_021B6AE4((u8 *)a, (void *)x, (u16)(func_02045738((struct Descriptor *)(*a)) * 8 / 2), 4, b,
                  ((struct Obj04620 *)p)->f1CC, 0x39e0, 2);
}






void func_021BECAC(int a, unsigned *p)
{
    func_02045334((struct Descriptor *)*p);
}





void func_021BECB8(u8 *p, unsigned message)
{
    Offset offset = off_ECB8;
    func_02043B5C(func_02045770(*(struct Descriptor **)(p + offset)), 6);
    func_021BE44C(p, 15, message, 120, 0, 0x446, 2);
    func_021BE49C(p + offset);
}






void func_021BECF8(void *a)
{
    func_021BECB8((u8 *)a, 0xb);
}






void func_021BED04(void *a)
{
    func_021BECB8((u8 *)a, 9);
}






void func_021BED10(void *a)
{
    func_021BECB8((u8 *)a, 0xa);
}






void func_021BED1C(int p)
{
    func_021BE49C((u8 *)(p + 0x1a4));
}






void func_021BED2C(int p)
{
    func_021BEE94();
    func_021BEEC4((struct Res021BEEC4 *)p);
    func_021BF0DC((struct Obj021BF0DC *)p);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}






void func_021BED54(int p)
{
    func_021BF370(p);
    func_021BF080((u8 *)p);
    func_0204A5AC();
}






void func_021BED68(int p)
{
    unsigned i;

    for (i = 0; i < 0x39; i++) {
        int *q = (int *)(p + i * 4);

        if (q[0xa] != 0 && func_0204B944((struct Obj *)q[0xa]) != 1)
            func_0204B8D4((struct Obj *)q[0xa], 0x1000);
    }
    func_0204A600();
}






void func_021BED98(char *p, int idx, int v)
{
    func_0204B8C4(*(void **)(p + 0x28 + idx * 4), 0);
    func_0204B878(*(void **)(p + 0x28 + idx * 4), (unsigned short)v);
}






void func_021BEDB8(int p, int i, int v)
{
    func_021BED98((char *)p, i, v);
    func_0204B92C((struct Obj *)((int *)(p + i * 4))[0xa], 1);
}






int func_021BEDD0(int p, int i)
{
    return func_0204B898((struct Obj *)(((int *)(p + i * 4))[0xa]));
}






int func_021BEDE0(int a0, int a1)
{
    int *p = (int *)(a0 + a1 * 4);

    return func_0204B98C((struct Actor *)p[0xa]);
}






void func_021BEDF0(int p, int i, int v)
{
    int h = ((int *)(p + i * 4))[0xa];

    if (h != 0)
        func_0204B3DC((struct Obj *)h, v);
}






int func_021BEE04(int p, int i)
{
    return func_0204B3F4((struct Obj *)(((int *)(p + i * 4))[0xa]));
}






void func_021BEE14(char *p, int idx, int flag)
{
    if (flag == 1)
    {
        func_0204B688(*(void **)(p + 0x28 + idx * 4), 1);
    }
    else
    {
        func_0204B688(*(void **)(p + 0x28 + idx * 4), 0);
    }
}






void func_021BEE38(char *p, int idx, int a, short b, unsigned short c)
{
    unsigned short buf[2];
    buf[0] = a;
    buf[1] = b;
    func_0204B404(*(void **)(p + idx * 4 + 0x28), (const struct Vec2 *)buf, c);
}






void func_021BEE58(char *p, int idx, short *outA, short *outB, unsigned short in)
{
    short buf[2];
    func_0204B454(*(void **)(p + idx * 4 + 0x28), (struct PtS *)buf, in);
    *outA = buf[0];
    *outB = buf[1];
}






void func_021BEE80(int p, int i, unsigned v)
{
    func_0204B84C(((int *)(p + i * 4))[0xa], (unsigned char)v);
}






void func_021BEE94(void)
{
    Tbl tbl = d_021C0990;

    func_0204A48C((const struct Cfg *)(&tbl), (u32_021BEE94)func_021BC3E8(), 0x7b);
}






void func_021BEEC4(struct Res021BEEC4 *p)
{
    u32_021BEEC4 i;
    void *arc;
    void *arc2;

    for (i = 0; i < 6; i++)
        p->a[i] = -1;
    for (i = 0; i < 6; i++)
        p->b[i] = -1;
    for (i = 0; i < 4; i++)
        p->c[i] = -1;

    arc = func_020490F4(0x9F, 0x807B);
    p->a[1] = func_0204A6C8(arc, 0x4E, 0, 0, 0x7B);
    p->b[1] = func_0204ABF0(arc, 0x4B, 0, 0, 0x7B);
    p->c[1] = func_0204AF28(arc, 0x54, 0x64, 0x7B);
    p->a[2] = func_0204A6C8(arc, 0x4E, 0, 1, 0x7B);
    p->b[2] = func_0204ABF0(arc, 0x4B, 1, 0, 0x7B);
    p->a[5] = func_0204A6C8(arc, 0x4D, 0, 0, 0x7B);
    p->b[5] = func_0204ABF0(arc, 0x48, 0, 0x60, 0x7B);
    p->c[3] = func_0204AF28(arc, 0x53, 0x63, 0x7B);
    p->a[3] = func_0204A6C8(arc, 0x52, 0, 0, 0x7B);
    p->b[3] = func_0204ABF0(arc, 0x4C, 0, 0x80, 0x7B);
    p->c[2] = func_0204AF28(arc, 0x55, 0x65, 0x7B);
    p->a[4] = func_0204A6C8(arc, 0x52, 0, 1, 0x7B);
    p->b[4] = func_0204ABF0(arc, 0x4C, 1, 0x60, 0x7B);
    func_02049238(arc);

    arc2 = func_020490F4(func_020275E4(), 0x807B);
    p->a[0] = func_0204A6C8(arc2, func_02027618(), 0, 0, 0x7B);
    p->b[0] = func_0204ABF0(arc2, func_02027614(), 0, 0xA0, 0x7B);
    p->c[0] = func_0204AF28(arc2, func_0202761C(2), func_02027620(2), 0x7B);
    func_02049238(arc2);
}




void func_021BF080(u8 *p)
{
    unsigned i;
    for (i = 0; i < 6; i++) {
        unsigned v = *(unsigned *)(p + i * 4 + 0x10c);
        if (v != -1) func_0204A8D4(v);
    }
    for (i = 0; i < 6; i++) {
        unsigned v = *(unsigned *)(p + i * 4 + 0x124);
        if (v != -1) func_0204ADA4(v);
    }
    for (i = 0; i < 4; i++) {
        unsigned v = *(unsigned *)(p + i * 4 + 0x13c);
        if (v != -1) func_0204AFD8(v);
    }
}





void func_021BF0DC(struct Obj021BF0DC *p)
{
    u32 i;
    struct Tpl021BF0DC t0;
    struct Tpl021BF0DC t;
    struct Tpl021BF0DC ta;
    struct Tpl021BF0DC tb;

    p->set = func_0204B100(0x39, 0, 0x7B);
    for (i = 0; i < 0x39; i++)
        p->objs[i] = 0;

    for (i = 0; i <= 14; i++) {
        t0 = data_021C09AC[i];
        t0.a = p->a[t0.a];
        t0.b = p->b[t0.b];
        t0.c = p->c[t0.c];
        p->objs[i] = func_021C940C((u32)p->set, (const u8 *)(&t0), 0x7B);
    }

    if (func_02012BF8((int)(*p->sys), 0x10) == 1)
        func_021BEDB8((int)p, 4, 7);
    func_021BEDF0((int)p, 5, 0);
    func_021BEDF0((int)p, 6, 0);
    func_021BEDF0((int)p, 0, 0);
    func_021BEDF0((int)p, 1, 0);
    func_021BEDF0((int)p, 7, 0);
    func_021BEDF0((int)p, 8, 0);
    func_021BEDF0((int)p, 9, 0);
    func_021BEDF0((int)p, 10, 0);
    func_021BEDF0((int)p, 11, 0);
    func_021BEDF0((int)p, 12, 0);
    func_021BEDF0((int)p, 13, 0);
    func_021BEDF0((int)p, 14, 0);
    func_0204B688(p->objs[13], 2);
    func_0204B688(p->objs[14], 2);
    func_021BEE14((char *)p, 11, 1);
    func_021BEE14((char *)p, 12, 1);

    ta = data_021C0978;
    tb = data_021C0960;
    for (i = 0; i < 14; i++) {
        t = ta;
        t.a = p->a[t.a];
        t.b = p->b[t.b];
        t.c = p->c[t.c];
        t.id = i;
        p->objs[15 + i] = func_021C940C((u32)p->set, (const u8 *)(&t), 0x7B);
        func_021BEDF0((int)p, i + 15, 0);

        t = tb;
        t.a = p->a[t.a];
        t.b = p->b[t.b];
        t.c = p->c[t.c];
        t.id = i;
        p->objs[29 + i] = func_021C940C((u32)p->set, (const u8 *)(&t), 0x7B);
        func_021BEDF0((int)p, i + 29, 0);
        func_021BEE14((char *)p, (int)i + 29, 1);
        p->objs[43 + i] = func_021C940C((u32)p->set, (const u8 *)(&t), 0x7B);
        func_021BEDF0((int)p, i + 43, 0);
        func_0204B688(p->objs[43 + i], 2);
    }
}





void func_021BF358(int p, int i)
{
    int o = i * 4;
    int *q = (int *)(p + 0x28);

    if (*(int *)((int)q + o) != 0) {
        func_0204B3B4((struct Obj *)(*(int *)((int)q + o)));
        *(int *)((int)q + o) = 0;
    }
}





void func_021BF370(int p)
{
    unsigned i;

    for (i = 0; i < 0x39; i++)
        func_021BF358(p, i);
    func_0204B1CC((struct Bank *)(((int *)p)[9]));
}



void func_021BF38C(u8 *p)
{
    unsigned int i;

    func_021BEDF0((int)p, 0, 0);
    func_021BEDF0((int)p, 1, 0);
    func_021BEDF0((int)p, 9, 0);
    func_021BEDF0((int)p, 0xA, 0);
    func_021BEDF0((int)p, 0xB, 0);
    func_021BEDF0((int)p, 0xC, 0);
    func_021BEDF0((int)p, 0xD, 0);
    func_021BEDF0((int)p, 0xE, 0);
    for (i = 0; i < 0xE; i++) {
        func_021BEDF0((int)p, i + 0xF, 0);
        func_021BEDF0((int)p, i + 0x1D, 0);
        func_021BEDF0((int)p, i + 0x2B, 0);
    }
    func_021BEDF0((int)p, 7, 0);
}




/*
 * ABI: matched caller BD118 consumes r0. The inactive arm retains the
 *      nested object pointer; the active arm retains BEDF0's return register.
 *      Declare BEDF0's observable r0 return despite void legacy declarations.
 */
unsigned func_021BF418(u8 *p)
{
    u8 *data;
    func_021BEDF0((int)p, 6, 0);
    func_021BEDF0((int)p, 5, 0);
    func_021BEDF0((int)p, 2, 1);
    func_021BEDF0((int)p, 3, 1);
    func_021BEDF0((int)p, 4, 1);
    data = *(u8 * *)&((struct Obj25627 *)(*(u8 * *)&((struct Obj25626 *)p)->f0))->f8;
    if (data[6] == 255)
        return (unsigned)data;
    func_021BED98((char *)p, 7, data[6]);
    func_021BEE38((char *)p, 7, 192, 116, 0);
    func_021BEDF0((int)p, 7, 1);
}






void func_021BF480(int p)
{
    func_021BEDF0((int)p, 3, 0);
    func_021BEDF0((int)p, 4, 0);
    func_021BEDF0((int)p, 2, 1);
}





void func_021BF4A4(char *p)
{
    func_021BEDF0((int)p, 3, 0);
    func_021BEDF0((int)p, 4, 0);
    func_021BEDF0((int)p, 2, 1);
    func_021BEDF0((int)p, 5, 1);
    func_021BEDF0((int)p, 6, 1);
    func_021BEDF0((int)p, 0, 1);
    func_021BEDF0((int)p, 1, 1);
    func_021BEE38(p, 0, 0xfc, 12, 0);
}





void func_021BF500(char *p)
{
    func_021BEDF0((int)p, 3, 0);
    func_021BEDF0((int)p, 4, 0);
    func_021BEDF0((int)p, 2, 1);
    func_021BEDF0((int)p, 5, 1);
    func_021BEDF0((int)p, 6, 1);
    func_021BEDF0((int)p, 0, 1);
    func_021BEDF0((int)p, 1, 1);
    func_021BEE38(p, 0, 0xfc, 12, 0);
}




void func_021BF55C(char *p)
{
    func_021BEDF0((int)p, 3, 0);
    func_021BEDF0((int)p, 4, 0);
    func_021BEDF0((int)p, 2, 1);
    func_021BEDF0((int)p, 5, 1);
    func_021BEDF0((int)p, 6, 1);
    func_021BEDF0((int)p, 0, 1);
    func_021BEDF0((int)p, 1, 1);
    func_021BEE38(p, 0, 0xfc, 12, 0);
}




void func_021BF5B8(char *p)
{
    func_021BEDF0((int)p, 3, 0);
    func_021BEDF0((int)p, 4, 0);
    func_021BEDF0((int)p, 2, 1);
    func_021BEDF0((int)p, 5, 1);
    func_021BEDF0((int)p, 6, 1);
    func_021BEDF0((int)p, 0, 1);
    func_021BEDF0((int)p, 1, 1);
    func_021BEE38(p, 0, 0xfc, 12, 0);
    func_021BF618(p);
}




void func_021BF618(char *p)
{
    unsigned char v = (*(unsigned char **)(*(char * *)&((struct Obj14678 *)p)->f0 + 8))[6];
    if (v != 0xff) {
        func_021BED98(p, 7, v);
        func_021BEE38(p, 7, 0x40, 0x68, 0);
        func_021BEDF0((int)p, 7, 1);
    } else {
        func_021BEDF0((int)p, 7, 0);
    }
}




void func_021BF658(char *p)
{
    short base = func_021B93B8(*(char * *)&((struct Obj25628 *)p)->f1E0);
    short i;
    for (i = 0; i < 14; i++) {
        func_021BEDF0((int)p, i + 15, 0);
        func_021BEDF0((int)p, i + 29, 0);
        func_021BEDF0((int)p, i + 43, 0);
    }
    for (i = 0; i < 5; i++) {
        func_021BFB8C(p, (unsigned short)(base + i), (short)(i * 40), 1);
        if (base - (i + 1) >= 0)
            func_021BFB8C(p, (unsigned short)(base - (i + 1)), (short)(192 - (i + 1) * 40), 0);
    }
}




void func_021BF6E0(char *p)
{
    short pos[2];
    unsigned int y;
    func_021BEE58(p, 0, &pos[1], &pos[0], 0);
    y = func_021B8AE4(*(struct S * *)&((struct Obj25629 *)p)->f1E0, pos[0]);
    if (y < 12) y = 12;
    else if (y > 156) y = 156;
    func_021BEE38(p, 0, 0xfc, (short)y, 0);
}





void func_021BF728(u8 *p, int a)
{
    int r6 = func_021B93B0((char *)(((struct Obj08414 *)p)->f1E0));

    if (func_021BEDD0((int)p, 6) != 0xC || a == 0) {
        if (func_021B93B8((char *)(((struct Obj08414 *)p)->f1E0)) == 0 && r6 == 0)
            func_021BEDB8((int)p, 6, 0x12);
        else
            func_021BEDB8((int)p, 6, 4);
    }
    if (func_021BEDD0((int)p, 5) != 0xD || a == 0) {
        if (func_021B93C0((char *)(((struct Obj08414 *)p)->f1E0)) == 0 &&
            r6 == ((struct Obj08414 *)p)->f2AC - 1)
            func_021BEDB8((int)p, 5, 0x13);
        else
            func_021BEDB8((int)p, 5, 5);
    }
}




void func_021BF7B0(char *p, int idx, int y, int flag)
{
    int index;
    int coord;
    if (flag == 1) {
        index = idx + 9;
        func_021BEDF0((int)p, index, 1);
        coord = y + 12;
        func_021BEE38(p, index, 0x8c, coord, 0);
    } else {
        int other = idx + 11;
        func_021BEDF0((int)p, other, 1);
        coord = y + 12;
        func_021BEE38(p, other, 0x8c, coord, 1);
        index = idx + 13;
        func_021BEDF0((int)p, index, 1);
        func_021BEE38(p, index, 0x8c, coord, 1);
    }
}




void func_021BF81C(char *p)
{
    func_021BEDF0((int)p, 9, 0);
    func_021BEDF0((int)p, 10, 0);
    func_021BEDF0((int)p, 11, 0);
    func_021BEDF0((int)p, 12, 0);
    func_021BEDF0((int)p, 13, 0);
    func_021BEDF0((int)p, 14, 0);
}




/*
 * Caller sign-extends r3 to 16 bits before EE38; existing callee uses u16.
 */
void func_021BF85C(char *p, int i, int flag)
{
    func_021BEDF0((int)p, 9, flag);
    func_021BEDF0((int)p, 11, 0);
    func_021BEDF0((int)p, 13, 0);
    if (flag == 1)
        func_021BEE38(p, 9, 0x8c, (short)(i * 24 + 12), 0);
}





void func_021BF89C(char *p, u8 a, u8 b)
{
    u8 cur = (u8)func_021B93B8(((struct Obj04619 *)p)->f1E0);
    u8 d;
    int y;

    func_021BEDF0((int)p, 9, 0);
    func_021BEDF0((int)p, 0xA, 0);
    func_021BEDF0((int)p, 0xB, 0);
    func_021BEDF0((int)p, 0xC, 0);
    func_021BEDF0((int)p, 0xD, 0);
    func_021BEDF0((int)p, 0xE, 0);
    if (a != 0xFF) {
        a = (u8)func_021BCEF0((u32)p, a);
        d = (u8)(a - cur < 0 ? -(a - cur) : a - cur);
        if (a < cur) {
            if (d <= 8) {
                func_021BEDF0((int)p, 0xB, 1);
                y = (8 - d) * 0x18 + 0xC;
                func_021BEE38(p, 0xB, 0x8C, (s16)y, 1);
                func_021BEDF0((int)p, 0xD, 1);
                func_021BEE38(p, 0xD, 0x8C, (s16)y, 1);
            }
        } else if (d <= 7) {
            func_021BEDF0((int)p, 9, 1);
            func_021BEE38(p, 9, 0x8C, (s16)(d * 0x18 + 0xC), 0);
        }
    }
    if (b != 0xFF) {
        b = (u8)func_021BCEF0((u32)p, b);
        d = (u8)(b - cur < 0 ? -(b - cur) : b - cur);
        if (b < cur) {
            if (d <= 8) {
                func_021BEDF0((int)p, 0xC, 1);
                y = (8 - d) * 0x18 + 0xC;
                func_021BEE38(p, 0xC, 0x8C, (s16)y, 1);
                func_021BEDF0((int)p, 0xE, 1);
                func_021BEE38(p, 0xE, 0x8C, (s16)y, 1);
            }
        } else if (d <= 7) {
            func_021BEDF0((int)p, 0xA, 1);
            func_021BEE38(p, 0xA, 0x8C, (s16)(d * 0x18 + 0xC), 0);
        }
    }
}



void func_021BFA14(char *p, int y, int flag)
{
    int coord;
    if (flag == 1) {
        func_021BEDF0((int)p, 9, 1);
        coord = y + 20;
        func_021BEE38(p, 9, 0x8c, coord, 0);
    } else {
        func_021BEDF0((int)p, 11, 1);
        coord = y + 20;
        func_021BEE38(p, 11, 0x8c, coord, 1);
        func_021BEDF0((int)p, 13, 1);
        func_021BEE38(p, 13, 0x8c, coord, 1);
    }
}



void func_021BFA7C(char *p, int i, int flag)
{
    func_021BEDF0((int)p, 9, flag);
    func_021BEDF0((int)p, 11, 0);
    func_021BEDF0((int)p, 13, 0);
    if (flag == 1)
        func_021BEE38(p, 9, 0x8c, (short)(i * 40 + 20), 0);
}



void func_021BFABC(char *ctx, int slot, int index)
{
    unsigned center = func_021B93B8(*(char * *)&((struct Obj25630 *)ctx)->f1E0);
    signed short lower = center - 7;
    signed short upper = center + 7;
    if (lower < 0) lower = 0;
    if (index >= lower && index < center) {
        func_021BF7B0(ctx, slot, (signed short)(192 - (center - index) * 24), 0);
    } else if (index >= center && index < upper) {
        func_021BF7B0(ctx, slot, (signed short)((index - center) * 24), 1);
    }
}



void func_021BFB24(char *ctx)
{
    unsigned center = func_021B93B8(*(char * *)&((struct Obj25631 *)ctx)->f1E0);
    int index = (*(unsigned char ***)(ctx))[2][6];
    signed short lower = index - 4;
    signed short upper = index + 4;
    if (lower < 0) lower = 0;
    if (index >= lower && index < center) {
        func_021BFA14(ctx, (signed short)(192 - (center - index) * 40), 0);
    } else if (index >= center && index < upper) {
        func_021BFA14(ctx, (signed short)((index - center) * 40), 1);
    }
}



/*
 * lever: unsigned long slot keeps updates in its home; enum y keeps the wide updated value and repeats s16 call truncation. int/short variants sank or cached updates (110–118 B); check3b EXACT 108 B.
 */
void func_021BFB8C(char *ctx, unsigned long slot, Y y, int flag)
{
    unsigned long second;
    if (flag == 1) {
        slot += 15;
        func_021BEDF0((int)ctx, (unsigned)slot, (unsigned)1);
        y += 20;
        func_021BEE38(ctx, (unsigned)slot, (unsigned short)204, y, 0);
    } else {
        second = slot + 29;
        func_021BEDF0((int)ctx, (unsigned)second, (unsigned)1);
        y += 20;
        func_021BEE38(ctx, (unsigned)second, (unsigned short)204, y, 1);
        slot += 43;
        func_021BEDF0((int)ctx, (unsigned)slot, (unsigned)1);
        func_021BEE38(ctx, (unsigned)slot, (unsigned short)204, y, 1);
    }
}




void func_021BFBF8(int p, int v)
{
    unsigned i;
    short pos[2];

    for (i = 9; i <= 10; i++) {
        if (func_021BEE04(p, i) != 0) {
            int t;

            func_021BEE58((char *)p, i, &pos[1], &pos[0], 0);
            func_021BEE38((char *)p, i, (short)pos[1], (short)(pos[0] + v), (int)0);
            t = pos[0] + v;
            if (t <= -12 || t >= 0xcc)
                func_021BEDF0((int)p, i, 0);
        }
    }
    for (i = 11; i <= 12; i++) {
        if (func_021BEE04(p, i) != 0) {
            int t;

            func_021BEE58((char *)p, i, &pos[1], &pos[0], 1);
            func_021BEE38((char *)p, i, (short)pos[1], (short)(pos[0] + v), (int)1);
            func_021BEE38((char *)p, i + 2, (short)pos[1], (short)(pos[0] + v), (int)1);
            t = pos[0] + v;
            if (t <= -12 || t >= 0xcc) {
                func_021BEDF0((int)p, i, 0);
                func_021BEDF0((int)p, i + 2, 0);
            }
        }
    }
}




void func_021BFCE4(char *p, int dx)
{
    u32 i;
    struct { short x; short y; } pos;

    for (i = 0xF; i < 0x1D; i++) {
        if (func_021BEE04((int)p, i)) {
            func_021BEE58(p, i, &pos.y, &pos.x, 0);
            func_021BEE38(p, i, pos.y, (short)(pos.x + dx), 0);
            if (pos.x + dx <= -20 || pos.x + dx >= 0xDC) {
                func_021BEDF0((int)p, i, 0);
            }
        }
    }
    func_021BEE58(p, 9, &pos.y, &pos.x, 0);
    func_021BEE38(p, 9, pos.y, (short)(pos.x + dx), 0);
    if (pos.x + dx <= -20 || pos.x + dx >= 0xDC) {
        func_021BEDF0((int)p, 9, 0);
    }
    for (i = 0x1D; i < 0x2B; i++) {
        if (func_021BEE04((int)p, i)) {
            func_021BEE58(p, i, &pos.y, &pos.x, 1);
            func_021BEE38(p, i, pos.y, (short)(pos.x + dx), 1);
            func_021BEE38(p, i + 0xE, pos.y, (short)(pos.x + dx), 1);
            if (pos.x + dx <= -28 || pos.x + dx >= 0xD4) {
                func_021BEDF0((int)p, i, 0);
                func_021BEDF0((int)p, (int)i + 0xE, 0);
            }
        }
    }
    func_021BEE58(p, 0xB, &pos.y, &pos.x, 1);
    func_021BEE38(p, 0xB, pos.y, (short)(pos.x + dx), 1);
    func_021BEE38(p, 0xD, pos.y, (short)(pos.x + dx), 1);
    if (pos.x + dx <= -28 || pos.x + dx >= 0xD4) {
        func_021BEDF0((int)p, 0xB, 0);
        func_021BEDF0((int)p, 0xD, 0);
    }
}




void func_021BFE84(int p, int n)
{
    func_021BEDF0((int)p, 8, 1);
    func_021BEE38((char *)p, 8, (short)(n * 2 + 8), 0xa8, (int)0);
}



void func_021BFEAC(char *ctx, int index)
{
    if (func_020355C4() == 1) {
        ((struct Obj10923 *)ctx)->f2B0 = func_02025CD0((unsigned)d_021C0B60, (unsigned)d_021C0B14, (unsigned)ctx, 0, index, 123);
    } else {
        ((struct Obj10923 *)ctx)->f2B0 = func_02025CD0((unsigned)d_021C0B60, (unsigned)d_021C0B14, (unsigned)ctx, 1, index, 123);
        func_021BFF30((int)ctx, index, 3);
    }
    func_02025D1C(((struct Obj10923 *)ctx)->f2B0);
}




void func_021BFF18(int p)
{
    int *q = (int *)p;

    if (q[0xac] != 0) {
        func_02025D14();
        q[0xac] = 0;
    }
}




/*
 * note:     func_0202616C takes (record, a); passing a as the second argument keeps r1 live,
 *           so the 0x2B0 offset lands in r2.
 */
void func_021BFF30(int p, unsigned int a, unsigned int b)
{
    u8 *t;
    int *q = (int *)p;

    if (a > 6)
        return;
    t = (u8 *)func_0202616C((void **)q[0xac], a);
    func_020413B0(0, t[0], t[1], t[2], t[3], (u8)b);
    func_02041B6C(0);
}




u32 func_021BFF68(int p)
{
    int *q = (int *)p;
    int r = func_02025DE8((struct Sound *)q[0xac]);
    unsigned k;

    if (r != -1)
        return r;
    k = func_020362DC();
    if (k & 0x400) {
        func_020355D8(0);
        return 8;
    }
    k = func_020362DC();
    if (k & 0x800) {
        if (func_020355C4() == 1)
            func_020260F4((struct Struct_02025CD0 *)q[0xac], 1);
        func_020355D8(0);
        return 7;
    }
    k = func_020362DC();
    if (k & 8) {
        if (func_020355C4() == 1)
            func_020260F4((struct Struct_02025CD0 *)q[0xac], 1);
        func_020355D8(0);
        func_021C003C(p, 5);
        return 5;
    }
    k = func_020362DC();
    if (k & 4) {
        if (func_020355C4() == 1)
            func_020260F4((struct Struct_02025CD0 *)q[0xac], 1);
        func_020355D8(0);
        func_021C003C(p, 6);
        return 6;
    }
    if (func_020362DC() != 0 && func_020355C4() == 1) {
        func_020355D8(0);
        func_020260F4((struct Struct_02025CD0 *)q[0xac], 1);
        return -4;
    }
    return r;
}




void func_021C003C(int p, unsigned b)
{
    int *q = (int *)p;

    func_021BFF30(p, func_020260E0((struct Sound *)q[0xac]), 1);
    func_021BFF30(p, b, 3);
    func_020260E4((struct Sound *)q[0xac], (unsigned char)b);
}




void func_021C006C(int p, unsigned b)
{
    unsigned r = func_020362DC();

    if ((r & 2) && !(r & 0xf1))
        return;
    func_021BFF30(p, b, 3);
    func_0202EB04((struct CodeIn *)(((int *)p)[0xad]));
}




void func_021C0098(int p, unsigned a, unsigned b)
{
    func_021BFF30(p, b, 1);
    func_021BFF30(p, a, 1);
}




void func_021C00B4(int p, unsigned a, unsigned b)
{
    func_021BFF30(p, b, 1);
    func_021BFF30(p, a, 3);
    func_0202EB04((struct CodeIn *)(((int *)p)[0xad]));
}




void func_021C00D8(int p, unsigned a, unsigned b)
{
    func_021BFF30(p, b, 1);
    if (a == 7)
        func_020260E4((struct Sound *)(((int *)p)[0xac]), (unsigned char)b);
}



int func_021C00FC(unsigned char *ctx)
{
    if (ctx[0x2bb] == 90) {
        ctx[0x2bb] = 0;
        return 1;
    }
    ctx[0x2bb]++;
    if (func_02035C60()) {
        func_020355D8(1);
        ctx[0x2bb] = 0;
        return 1;
    }
    if (func_020362DC() & 3) {
        func_020355D8(0);
        ctx[0x2bb] = 0;
        return 1;
    }
    return 0;
}



int func_021C014C(char *ctx)
{
    int result = func_02035C08(d_021C0B3C);
    if (result != -1) {
        func_020355D8(1);
        return result;
    }
    if (func_020362DC() & 2) {
        func_020355D8(0);
        return 8;
    }
    if (func_020362DC() & 8) {
        func_020355D8(0);
        return 8;
    }
    if (func_020362DC() & 4) {
        if (func_020355C4() == 1) {
            func_020355D8(0);
            func_021B940C(((struct Obj00085 *)ctx)->f1E0);
        }
        return 9;
    }
    return result;
}



int func_021C01C0(char *ctx)
{
    int result = func_02035C08(d_021C0B24);
    if (result != -1) { func_020355D8(1); return result; }
    if (func_020362DC() & 2) { func_020355D8(0); return 8; }
    if (func_020362DC() & 8) { func_020355D8(0); return 8; }
    if (func_020362DC() & 4) {
        if (func_020355C4() == 1) {
            func_020355D8(0);
            func_021B940C(((struct Obj25635 *)ctx)->f1E0);
        }
        return 9;
    }
    return result;
}
