/*
 * file:     zknsearch_main_p01.c
 * unit:     yes
 * function: func_021BC3F0, func_021BC578, func_021BC5B4, func_021BC5C8, func_021BC5DC, func_021BC790, func_021BC800, func_021BC82C, func_021BC8B4, func_021BC8EC, func_021BC92C, func_021BC940, func_021BC99C, func_021BC9D0, func_021BCA10, func_021BCA20, func_021BCA78, func_021BCA84, func_021BCAC8, func_021BCAF8, func_021BCB28, func_021BCB58, func_021BCB88, func_021BCBB8, func_021BCC1C, func_021BCC2C, func_021BCCA8, func_021BCD30, func_021BCD3C, func_021BCDA4, func_021BCE0C, func_021BCE58, func_021BCEEC, func_021BCEF0, func_021BCEF4, func_021BCF00, func_021BCF0C, func_021BCF38, func_021BCF50, func_021BCF8C, func_021BD064, func_021BD100, func_021BD118, func_021BD19C, func_021BD36C, func_021BD388, func_021BD3AC, func_021BD4AC, func_021BD500, func_021BD568, func_021BD640, func_021BD658, func_021BD6C4, func_021BD898, func_021BD8B0, func_021BD920, func_021BDB1C, func_021BDB34, func_021BDBA4, func_021BDD78, func_021BDD90, func_021BDE00, func_021BDFA8, func_021BDFC0, func_021BE010, func_021BE0C4, func_021BE0E4, func_021BE110, func_021BE12C, func_021BE178, func_021BE190, func_021BE20C, func_021BE22C, func_021BE278, func_021BE290, func_021BE2DC, func_021BE2F4, func_021BE314
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
 *   func_021BEDB8 0x021BEDB8 thumb ov210
 *   func_021BEE80 0x021BEE80 thumb ov210
 *   func_021BEDF0 0x021BEDF0 thumb ov210
 *   func_021BED1C 0x021BED1C thumb ov210
 *   func_02041EE4 0x02041EE4 arm
 *   func_0202CB4C 0x0202CB4C thumb
 *   func_0202CD94 0x0202CD94 thumb
 *   func_021BEE58 0x021BEE58 thumb ov210
 *   func_021BEE38 0x021BEE38 thumb ov210
 *   func_0202CD64 0x0202CD64 thumb
 *   d_021C072E  0x021C072E  data  a2
 *   d_021C0720  0x021C0720  data  a1
 *   d_021C0894  0x021C0894  data  a4
 *   func_021BED68  0x021BED68  thumb  ov210
 *   func_021BE3D4  0x021BE3D4  thumb  ov210
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
 *   func_021BE368  0x021BE368  thumb  ov210
 *   func_021BED2C  0x021BED2C  thumb  ov210
 *   func_021BC294  0x021BC294  thumb  ov210
 *   func_021BC318  0x021BC318  thumb  ov210
 *   func_02021ED8 0x02021ED8 thumb
 *   func_021BC330 0x021BC330 thumb ov210
 *   func_021BC2AC 0x021BC2AC thumb ov210
 *   func_021BED54 0x021BED54 thumb ov210
 *   func_021BE3B4 0x021BE3B4 thumb ov210
 *   func_02034A5C 0x02034A5C arm
 *   func_021BE564 0x021BE564 thumb ov210
 *   func_021BF418 0x021BF418 thumb ov210
 *   func_021BFEAC 0x021BFEAC thumb ov210
 *   func_021BFF68  0x021BFF68  thumb  ov210
 *   func_020061E4  0x020061E4  thumb
 *   func_021BE324  0x021BE324  thumb  ov210
 *   func_0202EA40  0x0202EA40  thumb
 *   func_021BFF18  0x021BFF18  thumb  ov210
 *   func_021C9380  0x021C9380  thumb  ov212
 *   func_02006210  0x02006210  thumb
 *   func_021BECF8  0x021BECF8  thumb  ov210
 *   func_021BED04  0x021BED04  thumb  ov210
 *   func_021BED10  0x021BED10  thumb  ov210
 *   func_021BE820  0x021BE820  thumb  ov210
 *   func_021BFE84  0x021BFE84  thumb  ov210
 *   func_021C9428  0x021C9428  thumb  ov212
 *   func_021C9460  0x021C9460  thumb  ov212
 *   func_021C9468  0x021C9468  thumb  ov212
 *   func_021C00FC 0x021C00FC thumb ov210
 *   func_021BE7E4 0x021BE7E4 thumb ov210
 *   func_020355C4 0x020355C4 arm
 *   func_020260F4 0x020260F4 thumb
 *   func_021BE83C 0x021BE83C thumb ov210
 *   func_021C0234 0x021C0234 thumb ov210
 *   func_021B7A64 0x021B7A64 thumb ov067
 *   func_021BF480 0x021BF480 thumb ov210
 *   func_021B7AB0  0x021B7AB0  thumb  ov067
 *   func_021C014C  0x021C014C  thumb  ov210
 *   func_021BF38C  0x021BF38C  thumb  ov210
 *   func_021C0550  0x021C0550  thumb  ov210
 *   func_021BE8F8 0x021BE8F8 thumb ov210
 *   func_021C02DC 0x021C02DC thumb ov210
 *   func_021BF728 0x021BF728 thumb ov210
 *   func_021BF4A4 0x021BF4A4 thumb ov210
 *   func_021BF81C  0x021BF81C  thumb  ov210
 *   func_021BFABC  0x021BFABC  thumb  ov210
 *   func_021BF6E0  0x021BF6E0  thumb  ov210
 *   func_021BE9D4 0x021BE9D4 thumb ov210
 *   func_021C0384 0x021C0384 thumb ov210
 *   func_021BF500 0x021BF500 thumb ov210
 *   func_021BEB0C 0x021BEB0C thumb ov210
 *   func_021C0434 0x021C0434 thumb ov210
 *   func_021BF55C 0x021BF55C thumb ov210
 *   func_021BEBE8 0x021BEBE8 thumb ov210
 *   func_021C04CC 0x021C04CC thumb ov210
 *   func_021BF5B8 0x021BF5B8 thumb ov210
 *   func_021BF658  0x021BF658  thumb  ov210
 *   func_021BFB24  0x021BFB24  thumb  ov210
 *   func_021C01C0  0x021C01C0  thumb  ov210
 *   func_021BEDE0 0x021BEDE0 thumb ov210
 *   func_021BFF30  0x021BFF30  thumb ov210
 *   func_021B93D4  0x021B93D4  thumb  ov067
 *   func_021BE8B8  0x021BE8B8  thumb  ov210
 *   func_021BF85C  0x021BF85C  thumb  ov210
 *   func_021B93B8 0x021B93B8 thumb ov067
 *   func_021BE978 0x021BE978 thumb ov210
 *   func_021BEA54 0x021BEA54 thumb ov210
 *   func_021BF89C 0x021BF89C thumb ov210
 *   func_021BEB8C 0x021BEB8C thumb ov210
 *   func_021BFA7C 0x021BFA7C thumb ov210
 *   func_021BF618 0x021BF618 thumb ov210
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
typedef unsigned short u16;

typedef unsigned int u32;

struct DispConfig { u32 w[4]; };

struct BgTemplate { u32 w[8]; };

typedef unsigned char  u8;

typedef signed short   s16;

typedef signed char    s8;

typedef signed int     s32;

typedef u32 (*StateFn)(u8 *);

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
extern void func_021BEDB8(int p, int i, int v);
extern void func_021BEE80(int p, int i, unsigned v);
extern void func_021BEDF0(int p, int i, int v);
extern void func_021BED1C(int p);
extern void func_02041EE4(u32, u32, u32);
extern void func_0202CB4C(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern void func_0202CD94(struct WinMgr *mgr);
extern void func_021BEE58(char *, int, short *, short *, unsigned short);
extern void func_021BEE38(char *p, int idx, int a, short b, unsigned short c);
extern void func_0202CD64(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames);
extern void func_021BED68(int p);
extern void func_021BE3D4(u8 *p);
extern void func_021C93E4(u32 a, u32 b, u32 *counter);
extern int func_02034AC4(s32 handle);
extern void func_02043534(u32 a);
extern void func_020435F4(u32 a);
extern void func_0204363C(u32 a);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern u32 func_0200CA70(struct Blk37 *p);
extern void func_0203D34C(u32 a, u32 b);
extern void func_021BC3D4(void);
extern void func_021BE368(u8 *p);
extern void func_021BED2C(int p);
extern void func_021BC294(u8 *p);
extern void func_021BC318(u8 *p);
extern u32 func_02021ED8(const char *);
extern u32 func_021BC330(u8 *p);
extern u32 func_021BC2AC(u8 *p);
extern void func_021BED54(int p);
extern void func_021BE3B4(char *);
extern void func_02034A5C(int);
extern void func_021BE564(u8 *);
extern u32 func_021BF418(u8 *);
extern void func_021BFEAC(char *ctx, int index);
extern u32 func_021BFF68(int p);
extern void func_020061E4(u32 id);
extern void func_021BE324(u8 *p);
extern s32 func_0202EA40(struct Row *p);
extern void func_021BFF18(int p);
extern void func_021C9380(struct Blk37 *p, u8 *out);
extern void func_02006210(void);
extern void func_021BECF8(void *);
extern void func_021BED04(void *);
extern void func_021BED10(void *);
extern void func_021BE820(u8 *p);
extern void func_021BFE84(int p, int n);
extern int func_021C9428(int, int, int);
extern void func_021C9460(int);
extern int func_021C9468(struct Search *p, u16 heap, u16 *outCount, u16 **out);
extern int func_021C00FC(u8 *);
extern void func_021BE7E4(u8 *);
extern u8 func_020355C4(void);
extern void func_020260F4(struct Struct_02025CD0 *obj, u32 state);
extern void func_021BE83C(u8 *);
extern void func_021C0234(char *ctx);
extern int func_021B7A64(struct S *p);
extern void func_021BF480(int p);
extern int func_021B7AB0(struct S *p);
extern int func_021C014C(char *ctx);
extern void func_021BF38C(u8 *p);
extern void func_021C0550(int p);
extern void func_021BE8F8(u8 *);
extern void func_021C02DC(char *ctx);
extern void func_021BF728(u8 *, int);
extern void func_021BF4A4(char *p);
extern void func_021BF81C(char *p);
extern void func_021BFABC(char *ctx, int slot, int index);
extern void func_021BF6E0(char *p);
extern void func_021BE9D4(u8 *);
extern void func_021C0384(char *ctx);
extern void func_021BF500(char *p);
extern void func_021BEB0C(u8 *);
extern void func_021C0434(char *ctx);
extern void func_021BF55C(char *p);
extern void func_021BEBE8(u8 *);
extern void func_021C04CC(char *ctx);
extern void func_021BF5B8(char *p);
extern void func_021BFB24(char *ctx);
extern void func_021BF658(char *p);
extern int func_021C01C0(char *ctx);
extern int func_021BEDE0(int, int);
extern void func_021BFF30(int p, unsigned int a, unsigned int b);
extern void func_021B93D4(struct S *s, int v);
extern void func_021BE8B8(u8 *p);
extern void func_021BF85C(char *p, int i, int flag);
extern int func_021B93B8(char *p);
extern void func_021BE978(u8 *);
extern void func_021BEA54(u8 *p);
extern void func_021BF89C(char *p, u8 a, u8 b);
extern void func_021BEB8C(u8 *);
extern void func_021BFA7C(char *p, int i, int flag);
extern void func_021BF618(char *p);
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
