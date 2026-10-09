/*
 * file:     pms_input_view.c
 * unit:     yes
 * function: func_021B95A0, func_021B95F4, func_021B9608, func_021B9654, func_021B96C0, func_021B9720, func_021B97AC, func_021B9814, func_021B98A0, func_021B98F8, func_021B999C, func_021B99A4, func_021B99C4, func_021B99D8, func_021B99E4, func_021B99F0, func_021B9A48, func_021B9A50, func_021B9B20, func_021B9BA4, func_021B9BAC, func_021B9BD0, func_021B9BEC, func_021B9C74, func_021B9C90, func_021B9CBC, func_021B9CE4, func_021B9F34, func_021B9FB4, func_021BA070, func_021BA150, func_021BA1A0, func_021BA1D8, func_021BA1F0, func_021BA208, func_021BA220, func_021BA258, func_021BA290, func_021BA2D8, func_021BA398, func_021BA3F0, func_021BA4CC, func_021BA5C4, func_021BA6BC, func_021BA7CC, func_021BA8C4, func_021BA958, func_021BA974, func_021BA998, func_021BA9B4, func_021BA9D0, func_021BAA0C, func_021BAA3C, func_021BAA8C, func_021BAAF0, func_021BAB0C, func_021BAB70, func_021BABAC, func_021BABE8, func_021BABF4, func_021BAC00, func_021BAC0C, func_021BAC30, func_021BAC3C, func_021BAC40, func_021BAC44, func_021BAC4C, func_021BAC50, func_021BAC64, func_021BAC78, func_021BACDC, func_021BAD14, func_021BAD20, func_021BAD2C, func_021BAD68, func_021BADE8, func_021BAE24, func_021BAE94, func_021BAED0, func_021BAEDC, func_021BAF4C, func_021BAF7C, func_021BAFAC, func_021BAFDC, func_021BAFE4, func_021BB00C, func_021BB054, func_021BB1C0, func_021BB1CC, func_021BB1E4, func_021BB1F4, func_021BB1F8, func_021BB214
 * address:  0x021B95A0
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020247A8 0x020247A8 thumb
 *   d_021C3B80 0x021C3B80 data a1
 *   func_020247F0 0x020247F0 thumb
 *   func_020307B0 0x020307B0 arm
 *   d_021C1E80 0x021C1E80 data a4
 *   func_02024148 0x02024148 thumb
 *   func_0200D064 0x0200D064 thumb
 *   func_02024150 0x02024150 thumb
 *   func_0202414C 0x0202414C thumb
 *   func_02024888 0x02024888 thumb
 *   func_02024994 0x02024994 thumb
 *   func_02024160 0x02024160 thumb
 *   d_021C1C88 0x021C1C88 data ov110 a4
 *   func_02024810 0x02024810 thumb
 *   d_021C3C20 0x021C3C20 data a4
 *   d_020A1448 0x020A1448 data a4
 *   d_021C3714 0x021C3714 data a4
 *   func_021BF6D4 0x021BF6D4 thumb ov110
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0207D534 0x0207D534 arm
 *   func_021BF7D0 0x021BF7D0 thumb ov110
 *   func_02030DA8 0x02030DA8 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049238 0x02049238 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_021BCA30 0x021BCA30 thumb ov110
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_0204A600 0x0204A600 arm
 *   func_021BCA84 0x021BCA84 thumb ov110
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_020419E4 0x020419E4 arm
 *   func_0204A648 0x0204A648 arm
 *   d_021C3B94 0x021C3B94 data a4
 *   func_02030EE8 0x02030EE8 arm
 *   func_0204335C 0x0204335C arm
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_021BBC5C 0x021BBC5C thumb ov110
 *   func_021BBD60 0x021BBD60 thumb ov110
 *   func_021BB290 0x021BB290 thumb ov110
 *   func_021BB328 0x021BB328 thumb ov110
 *   func_021BF844 0x021BF844 thumb ov110
 *   func_021BF8F4 0x021BF8F4 thumb ov110
 *   func_020498F4 0x020498F4 arm
 *   func_02049658 0x02049658 arm
 *   func_02040588 0x02040588 arm
 *   func_02049BDC 0x02049BDC arm
 *   func_02061CA4 0x02061CA4 arm
 *   func_020413B0 0x020413B0 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_021BF7C4 0x021BF7C4 thumb ov110
 *   func_021BF6D8 0x021BF6D8 thumb ov110
 *   func_021BC990 0x021BC990 thumb ov110
 *   func_021BCB50 0x021BCB50 thumb ov110
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_0207D46C 0x0207D46C arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_020452E8 0x020452E8 arm
 *   func_021BBCF0 0x021BBCF0 thumb ov110
 *   func_021BB2CC 0x021BB2CC thumb ov110
 *   func_021BF8BC 0x021BF8BC thumb ov110
 *   func_020403F4 0x020403F4 arm
 *   d_021C3604 0x021C3604 data a4
 *   d_021C3694 0x021C3694 data a4
 *   d_021C36B4 0x021C36B4 data a4
 *   d_021C3674 0x021C3674 data a4
 *   d_021C3614 0x021C3614 data a4
 *   d_021C36F4 0x021C36F4 data a4
 *   d_021C36D4 0x021C36D4 data a4
 *   d_021C3654 0x021C3654 data a4
 *   d_021C3634 0x021C3634 data a4
 *   func_020433E0 0x020433E0 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201C450 0x0201C450 thumb
 *   func_021BC23C 0x021BC23C thumb ov110
 *   func_021BF714 0x021BF714 thumb ov110
 *   func_021BC72C 0x021BC72C thumb ov110
 *   func_021BCCA8 0x021BCCA8 thumb ov110
 *   func_021BCD44 0x021BCD44 thumb ov110
 *   func_021BC704 0x021BC704 thumb ov110
 *   func_021BC724 0x021BC724 thumb ov110
 *   func_021BF71C 0x021BF71C thumb ov110
 *   func_021BCF7C 0x021BCF7C thumb ov110
 *   func_021BC728 0x021BC728 thumb ov110
 *   func_021BF7E0 0x021BF7E0 thumb ov110
 *   func_021BCC58 0x021BCC58 thumb ov110
 *   func_021BC6EC 0x021BC6EC thumb ov110
 *   func_021BB76C 0x021BB76C thumb ov110
 *   func_021BBEF4 0x021BBEF4 thumb ov110
 *   func_021BF6DC 0x021BF6DC thumb ov110
 *   func_021BB958 0x021BB958 thumb ov110
 *   func_021BB784 0x021BB784 thumb ov110
 *   func_021BBF54 0x021BBF54 thumb ov110
 *   func_021BF724 0x021BF724 thumb ov110
 *   func_021BB6A0 0x021BB6A0 thumb ov110
 *   func_021BB658 0x021BB658 thumb ov110
 *   func_021BB8D8 0x021BB8D8 thumb ov110
 *   func_021BB8B8 0x021BB8B8 thumb ov110
 *   func_021BB954 0x021BB954 thumb ov110
 *   func_021BCEE4 0x021BCEE4 thumb ov110
 *   func_021BB9C0 0x021BB9C0 thumb ov110
 *   func_021BBB0C 0x021BBB0C thumb ov110
 *   func_021BCF38 0x021BCF38 thumb ov110
 *   func_021BCF70 0x021BCF70 thumb ov110
 *   func_021BD000 0x021BD000 thumb ov110
 *   func_021BD028 0x021BD028 thumb ov110
 *   func_021BB7A0 0x021BB7A0 thumb ov110
 *   func_021BB7B8 0x021BB7B8 thumb ov110
 *   func_021BC6F8 0x021BC6F8 thumb ov110
 *   func_021BBC10 0x021BBC10 thumb ov110
 *   func_021BB838 0x021BB838 thumb ov110
 *   func_021BB854 0x021BB854 thumb ov110
 *   func_021BCC88 0x021BCC88 thumb ov110
 *   func_021BF9F0 0x021BF9F0 thumb ov110
 *   func_021BFAA0 0x021BFAA0 thumb ov110
 *   func_021BFB58 0x021BFB58 thumb ov110
 *   func_021BF784 0x021BF784 thumb ov110
 *   func_021BFC64 0x021BFC64 thumb ov110
 *   func_021BF7AC 0x021BF7AC thumb ov110
 *   func_021BF7B8 0x021BF7B8 thumb ov110
 *   func_021BFDB0 0x021BFDB0 thumb ov110
 *   func_021BFC20 0x021BFC20 thumb ov110
 *   func_021BF7FC 0x021BF7FC thumb ov110
 *   func_021BFB7C 0x021BFB7C thumb ov110
 *   func_021BFBA0 0x021BFBA0 thumb ov110
 *   func_021BB870 0x021BB870 thumb ov110
 *   func_021BB8AC 0x021BB8AC thumb ov110
 *   func_021C00FC 0x021C00FC thumb ov110
 *   func_021BB804 0x021BB804 thumb ov110
 *   func_021BB814 0x021BB814 thumb ov110
 *   func_021BB82C 0x021BB82C thumb ov110
 *   func_021BF7A0 0x021BF7A0 thumb ov110
 *   func_021BFCA4 0x021BFCA4 thumb ov110
 *   func_021BFD60 0x021BFD60 thumb ov110
 *   func_021BCFBC 0x021BCFBC thumb ov110
 *   func_021BCD80 0x021BCD80 thumb ov110
 *   func_021BFA40 0x021BFA40 thumb ov110
 *   func_021BF72C 0x021BF72C thumb ov110
 *   func_021BBB84 0x021BBB84 thumb ov110
 *   func_021C00AC 0x021C00AC thumb ov110
 *   func_021BC6DC  0x021BC6DC  thumb  ov110
 *   func_021BC6E0  0x021BC6E0  thumb  ov110
 *   func_021BC320  0x021BC320  thumb  ov110
 *   func_021BCFF0 0x021BCFF0 thumb ov110
 *   func_021BCF18 0x021BCF18 thumb ov110
 *   OS_DisableInterrupts 0x02087988 arm
 *   OS_RestoreInterrupts 0x0208799C arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B954 0x0204B954 arm
 *   func_021BFD94 0x021BFD94 thumb ov110
 *   func_021BFE24  0x021BFE24  thumb  ov110
 *   func_021BFE60  0x021BFE60  thumb  ov110
 *   func_020499D4 0x020499D4 arm
 *   d_021C3744 0x021C3744 data ov110 a4
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_021B6C74 0x021B6C74 thumb ov067
 *   func_020457B0 0x020457B0 arm
 *   d_021C3C34 0x021C3C34 data ov110 a1
 *   d_021C3770 0x021C3770 data a2
 *   func_021B6CCC 0x021B6CCC thumb ov067
 *   func_02045A98 0x02045A98 arm
 *   func_02045924 0x02045924 arm
 *   func_021B6CE0 0x021B6CE0 thumb ov067
 *   func_0204581C 0x0204581C arm
 *   func_02045F50 0x02045F50 arm
 *   d_021C375C 0x021C375C data a2
 *   func_02045994 0x02045994 arm
 *   d_021C37A8 0x021C37A8 data a2
 */
#include "../../matched/include/Obj05283.h"
#include "../../matched/include/Obj22311.h"
#include "../../matched/include/Obj22312.h"
#include "../../matched/include/Obj22313.h"
#include "../../matched/include/Obj07996.h"
#include "../../matched/include/Obj22314.h"
#include "../../matched/include/Obj01920.h"
#include "../../matched/include/Obj05284.h"
#include "../../matched/include/Obj06380.h"
#include "../../matched/include/Obj03239.h"
#include "../../matched/include/Obj13768.h"
#include "../../matched/include/Obj10264.h"
#include "../../matched/include/Obj00135.h"
#include "../../matched/include/Obj22315.h"
#include "../../matched/include/Obj22316.h"
#include "../../matched/include/Obj22317.h"
#include "../../matched/include/Obj22318.h"
#include "../../matched/include/Obj22319.h"
#include "../../matched/include/Obj22320.h"
#include "../../matched/include/Obj22321.h"
#include "../../matched/include/Obj22322.h"
#include "../../matched/include/Obj22323.h"
#include "../../matched/include/Obj22324.h"
#include "../../matched/include/Obj22325.h"
#include "../../matched/include/Obj22326.h"
#include "../../matched/include/Obj22327.h"
#include "../../matched/include/Obj05286.h"
#include "../../matched/include/Obj22328.h"
#include "../../matched/include/Obj04441.h"
#include "../../matched/include/Obj07997.h"
#include "../../matched/include/Obj22329.h"
#include "../../matched/include/Obj22330.h"
#include "../../matched/include/Obj22331.h"
#include "../../matched/include/Obj22332.h"
#include "../../matched/include/Obj13769.h"
#include "../../matched/include/Obj22333.h"
#include "../../matched/include/Obj10265.h"
#include "../../matched/include/Obj06381.h"
#include "../../matched/include/Obj06382.h"
#include "../../matched/include/Obj06383.h"
#include "../../matched/include/Obj05287.h"
#include "../../matched/include/Obj01921.h"
#include "../../matched/include/Obj03748.h"
#include "../../matched/include/Obj06384.h"
#include "../../matched/include/Obj06385.h"
#include "../../matched/include/Obj01711.h"
#include "../../matched/include/Obj03749.h"
#include "../../matched/include/Obj01530.h"
#include "../../matched/include/Obj03237.h"
#include "../../matched/include/Obj01142.h"
#include "../../matched/include/Obj04442.h"
#include "../../matched/include/Obj01531.h"
#include "../../matched/include/Obj02164.h"
#include "../../matched/include/Obj01247.h"
#include "../../matched/include/Obj03238.h"
#include "../../matched/include/Obj02815.h"
#include "../../matched/include/Obj05288.h"
#include "../../matched/include/Obj13770.h"
#include "../../matched/include/Obj13771.h"
#include "../../matched/include/Obj13772.h"
#include "../../matched/include/Obj13773.h"
#include "../../matched/include/Obj10266.h"
#include "../../matched/include/Obj10267.h"
#include "../../matched/include/Obj22334.h"
#include "../../matched/include/Obj13774.h"
#include "../../matched/include/Obj06386.h"
#include "../../matched/include/Obj07998.h"
#include "../../matched/include/Obj13775.h"
#include "../../matched/include/Obj04443.h"
#include "../../matched/include/Obj10268.h"
#include "../../matched/include/Obj10269.h"
#include "../../matched/include/Obj10270.h"
#include "../../matched/include/Obj10271.h"
#include "../../matched/include/Obj10272.h"
#include "../../matched/include/Obj22336.h"
#include "../../matched/include/Obj22337.h"
#include "../../matched/include/Obj22338.h"
#include "../../matched/include/Obj13776.h"
#include "../../matched/include/Obj22339.h"
#include "../../matched/include/Obj22340.h"
#include "../../matched/include/Obj22341.h"
#include "../../matched/include/Obj22342.h"
#include "../../matched/include/Obj22343.h"
#include "../../matched/include/Obj22344.h"
#include "../../matched/include/Obj22345.h"
#include "../../matched/include/Obj22346.h"
#include "../../matched/include/Obj10273.h"
#include "../../matched/include/Obj07999.h"
#include "../../matched/include/Obj13777.h"
#include "../../matched/include/Obj22347.h"
#include "../../matched/include/Obj22348.h"
#include "../../matched/include/Obj22349.h"
#include "../../matched/include/Obj02459.h"
#include "../../matched/include/Obj06387.h"
#include "../../matched/include/Obj22352.h"
#include "../../matched/include/Obj03750.h"
#include "../../matched/include/Obj13778.h"
#include "../../matched/include/Obj10274.h"
#include "../../matched/include/Obj08000.h"
#include "../../matched/include/Obj03750.h"
#include "../../matched/include/Obj01391.h"
#include "../../matched/include/Obj22355.h"
#include "../../matched/include/Obj22356.h"

struct PmsWordSys;
struct Blk37;
struct Cfg;
struct Bank;
struct Node;
struct PrintSys;
struct S02030EE8;
struct Object;
struct Descriptor;
struct CharBuf;
struct BgTemplate;
struct DispConfig;
struct DispVram;
struct GfFont;
struct Obj;
struct Actor;
struct Vec2;
struct MsgBank;
struct Rec;
struct U16Vec;
struct Strbuf;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {void *save;void *words;int counts[12];int starts[12];u16 values[1];} Object;

typedef struct {int (*fn)(Object *,const u16 *,unsigned int,u16 *); const u16 *data;unsigned int count;} Entry;

typedef short s16;

typedef signed char s8;

typedef int s32;

typedef int s32_021B99E4;

typedef struct { u32 entries[35]; } CallbackTable;

typedef struct { u8 *owner; u32 field4, field8; int id, slot, state; } Context;

typedef signed int     s32_021B9C74;

typedef enum { GX_DISP_SELECT_SUB_MAIN=0, GX_DISP_SELECT_MAIN_SUB=1 } GXDispSelect;

struct V3 { u32 a, b, c; };

typedef struct { unsigned a,b,c; } Triple;

typedef struct { short x, y, z; u8 a, b; } Position;

typedef struct { short x,y; } Vec2;

typedef struct { u32 values[6]; } Table;

typedef struct { u8 pad[0xad4]; u16 values[13]; } Input;

typedef unsigned u32_021BB054;

typedef unsigned int u32_021BB1C0;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct PmsWordSys *func_020247A8(u32 heapId);
extern void func_020247F0(char *);
extern u32 func_020307B0(void *p);
extern void *func_02024148(char *p);
extern u32 func_0200D064(struct Blk37 *p, u16 id);
extern int func_02024150(void *);
extern void *func_0202414C(char *p);
extern u16 func_02024888(u32 idx, u16 add);
extern int func_02024994(const u32 *p, u32 idx);
extern int func_02024160(void *);
extern void func_02024810(char *,int,int);
extern u8 *func_021BF6D4(u8 *);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0203F8F4(u16);
extern void func_02045088(u16);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern u32 func_021BF7D0(u8 *);
extern void *func_02030DA8(u32,u32,void *,int);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049238(void *);
extern void func_02030EAC(struct Node *n);
extern void func_021BCA30(u8 *p);
extern unsigned int func_0204B1CC(struct Bank *bank);
extern void func_0204ADA4(unsigned int);
extern void func_0204A8D4(unsigned int);
extern void func_0204AFD8(unsigned int);
extern void func_0204A5AC(void);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void *func_020056A0(void (*fn)(void *, u8 *), u8 *p, int n);
extern void func_0204A600(void);
extern void func_021BCA84(unsigned char *);
extern unsigned int func_0201C4E4(struct PrintSys *);
extern void func_020419E4(void);
extern void func_0204A648(void);
extern u32 func_02030EE8(struct S02030EE8 *p);
extern void func_0204335C(unsigned);
extern void func_020434CC(void);
extern void func_02043588(void);
extern u8 *func_021BBC5C(void *,u8 *,void *);
extern void func_021BBD60(u8 *p, u32 a);
extern u8 *func_021BB290(u32 a, u8 *b, u32 c);
extern void func_021BB328(u8 *p, u32 data);
extern u8 *func_021BF844(void *,void *,void *);
extern void func_021BF8F4(u8 *);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern int func_02061CA4(void *,u32,u32,int);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern u32 func_021BF7C4(u8 *);
extern u32 func_021BF6D8(u8 *);
extern u8 *func_021BC990(u8 *,u8 *,void *);
extern void func_021BCB50(struct Object *p);
extern void func_020434DC(u32,u32);
extern void func_02043598(u32,u32);
extern void func_0207D46C(void);
extern signed int func_0204ABF0(void *a, unsigned int b, unsigned int c, unsigned int d, u16 g);
extern s32_021B9C74 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32_021B9C74 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern u32 func_020221A4(void);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_021BBCF0(u8 *p);
extern void func_021BB2CC(u8 *p);
extern void func_021BF8BC(u8 *p);
extern u32 func_0201D83C(void *ptr);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_020403F4(u32 i);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414EC(u32 i);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern void *func_0201C450(u16,u32);
extern void func_021BC23C(void *);
extern u16 func_021BF714(u8 *);
extern void func_021BC72C(char *p, int i);
extern void func_021BCCA8(void *);
extern void func_021BCD44(u8 *p);
extern void func_021BC704(u8 *p, u32 flag);
extern void func_021BC724(u8 *);
extern u16 func_021BF71C(u8 *);
extern void func_021BCF7C(u8 *p, int n, int v);
extern void func_021BC728(u8 *);
extern void func_021BF7E0(u8 *);
extern void func_021BCC58(u8 *);
extern void func_021BC6EC(void *p);
extern void func_021BB76C(u8 *);
extern void func_021BBEF4(u8 *p, u8 value);
extern u8 func_021BF6DC(u8 *);
extern void func_021BB958(char *p);
extern int func_021BB784(u8 *);
extern int func_021BBF54(u8 *);
extern u16 func_021BF724(u8 *);
extern void func_021BB6A0(u8 *, unsigned int);
extern void func_021BB658(u8 *, int);
extern void func_021BB8D8(u8 *);
extern void func_021BB8B8(u8 *);
extern int func_021BB954(u8 *);
extern void func_021BCEE4(char *p, u32 mode);
extern void func_021BB9C0(u8 *,int);
extern int func_021BBB0C(u8 *,int);
extern int func_021BCF38(char *p, u32 mode);
extern void func_021BCF70(u8 *,int);
extern int func_021BD000(char *p);
extern int func_021BD028(u8 *);
extern void func_021BB7A0(u8 *);
extern int func_021BB7B8(u8 *);
extern void func_021BC6F8(void *);
extern int func_021BBC10(u8 *);
extern void func_021BB838(u8 *);
extern int func_021BB854(u8 *);
extern void func_021BCC88(u8 *);
extern void func_021BF9F0(u8 *);
extern void func_021BFAA0(u8 *);
extern int func_021BFB58(u8 *);
extern unsigned func_021BF784(u8 *);
extern void func_021BFC64(u8 *,unsigned);
extern unsigned func_021BF7AC(u8 *);
extern unsigned func_021BF7B8(u8 *);
extern void func_021BFDB0(u8 *,unsigned,unsigned);
extern void func_021BFC20(u8 *,unsigned);
extern u8 func_021BF7FC(u8 *);
extern void func_021BFB7C(u8 *p);
extern int func_021BFBA0(u8 *);
extern void func_021BB870(u8 *);
extern int func_021BB8AC(u8 *);
extern int func_021C00FC(u8 *);
extern void func_021BB804(u8 *);
extern void func_021BB814(u8 *p);
extern int func_021BB82C(u8 *);
extern int func_021BF7A0(u8 *);
extern void func_021BFCA4(u8 *, int);
extern int func_021BFD60(u8 *);
extern void func_021BCFBC(char *p, u32 index, int value);
extern void func_021BCD80(u8 *);
extern void func_021BFA40(u8 *,unsigned);
extern u16 func_021BF72C(u8 *);
extern void func_021BBB84(u8 *,unsigned);
extern void func_021C00AC(u8 *,unsigned);
extern unsigned int func_021BC6DC(void *p);
extern u16 func_021BC6E0(u8 *p, int i);
extern void func_021BC320(void *a, u8 *b, int n);
extern u32 func_021BCFF0(char *p, u32 index);
extern void func_021BCF18(void *,int);
extern int OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(int s);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, u16, u16);
extern void func_0204B92C(struct Obj *, u32);
extern void func_0204B954(struct Actor *a, u32 v);
extern u32 func_021BFD94(u8 *p, struct Vec2 *out);
extern void func_021BFE24(u8 *p, int y);
extern unsigned func_021BFE60(u8 *p, unsigned n);
extern u32 func_020499D4(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *);
extern u8 func_02045730(struct Descriptor *);
extern void func_02041B6C(unsigned);
extern u32 *func_021B6C74(u32 *src, u32 n, u16 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_021B6CCC(int *);
extern u16 func_02045A98(void);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void func_0204581C(struct U16Vec *vec);
extern u16 func_02045F50(const struct Obj *o);
extern u32_021BB054 func_021B6CE0(void *,u32_021BB054,u32_021BB054,u32_021BB054,void *,u32_021BB054);
extern void func_02045994(struct Strbuf *o, const u16 *src, u32_021BB1C0 len);
void *func_021B95A0(u32 heap,void *save);
void func_021B95F4(char *a);
void func_021B9608(Object *p);
u32 func_021B9654(u8 *p,const u16 *ids,u32 count,u16 *out);
u32 func_021B96C0(u8 *p,const u16 *ids,u32 count,u16 *out);
u32 func_021B9720(u8 *p, u16 *src, u32 n, u16 *out);
u32 func_021B97AC(u8 *p,const u16 *ids,u32 count,u16 *out);
u32 func_021B9814(u8 *p, u16 *src, u32 n, u16 *out);
void func_021B98A0(u8 *p);
u32 func_021B98F8(u8 *p, u16 *src, u16 *out, u32 n);
u32 func_021B999C(u8 *p, int i);
void func_021B99A4(unsigned int a,unsigned int b,unsigned int c,int d);
unsigned short func_021B99C4(unsigned int a,unsigned int b,unsigned int c);
u32 func_021B99D8(u32 a, u32 b, u32 c);
u8 *func_021B99E4(u8 *p);
u16 func_021B99F0(int unused, int id, int index);
void func_021B9A3C(u8 *p, u16 a1, int a2);
int func_021B9A48(u32 a0);
void *func_021B9A50(u8 *context,void *arg);
void func_021B9B20(u8 *p);
void *func_021B9BA4(void (*fn)(void *, u8 *), u8 *p, int n);
void func_021B9BAC(int a,unsigned char *b);
void func_021B9BD0(int a,unsigned char *b);
void func_021B9BEC(u8 *p, int id);
int func_021B9C74(unsigned int a);
int func_021B9C90(unsigned int a,int b);
void func_021B9CBC(u8 *p);
void func_021B9CE4(void *unused,u8 *p);
void func_021B9F34(u8 *p, void *archive);
void func_021B9FB4(int unused, u8 *p);
void func_021BA070(u8 *p);
void func_021BA150(int unused, u8 *p);
void func_021BA1A0(void *unused, u8 *p);
void func_021BA1D8(void *unused, u8 *p);
void func_021BA1F0(void *unused, u8 *p);
void func_021BA208(void *unused, u8 *p);
void func_021BA220(void *unused, u8 *p);
void func_021BA258(void *unused, u8 *p);
void func_021BA290(int unused, u8 *p);
void func_021BA2D8(int unused, u8 *p);
void func_021BA398(int unused, u8 *p);
void func_021BA3F0(void *unused,u8 *p);
void func_021BA4CC(void *unused,u8 *p);
void func_021BA5C4(void *unused,u8 *p);
void func_021BA6BC(void *unused, u8 *p);
void func_021BA7CC(void *unused, u8 *p);
void func_021BA8C4(void *unused,u8 *p);
void func_021BA958(void *unused, u8 *p);
void func_021BA974(void *unused, u8 *p);
void func_021BA998(void *unused, u8 *p);
void func_021BA9B4(void *unused, u8 *p);
void func_021BA9D0(void *unused, u8 *p);
void func_021BAA0C(int a,u8 *p);
void func_021BAA30(int a,u8 *p);
void func_021BAA3C(void *unused,u8 *p);
void func_021BAA5C(void *unused,u8 *p);
void func_021BAA68(void *unused,u8 *p);
void func_021BAA74(void *unused,u8 *p);
void func_021BAA80(void *unused,u8 *p);
void func_021BAA8C(void *unused,u8 *p);
void func_021BAAF0(int a,u8 *p);
void func_021BAB0C(void *unused,u8 *p);
void func_021BAB70(int a,u8 *p);
void func_021BABAC(int a,u8 *p);
int func_021BABE8(u8 *p);
int func_021BABF4(u8 *p, int i);
void func_021BAC00(u8 *p, u8 *b, u8 n);
int func_021BAC0C(u8 *p);
void func_021BAC30(u8 *p,int mode);
u32 func_021BAC3C(u8 *p);
u32 func_021BAC40(u8 *p);
u32 func_021BAC44(u8 *p);
u32 func_021BAC4C(u8 *p);
void func_021BAC50(char *p, struct V3 *out, int i);
void func_021BAC64(unsigned p, Triple *out,unsigned i);
struct Obj *func_021BAC78(char *p, u32 *r, short x, short y, u32 a, int mode);
int func_021BACDC(u8 *p,int unused,unsigned n);
void func_021BAD14(u8 *p, u32 v);
unsigned func_021BAD20(u8 *p, unsigned n);
void func_021BAD2C(u8 *p,int v);
void func_021BAD68(u8 *p,int index);
void func_021BADE8(u8 *p);
void func_021BAE24(u8 *p, u8 *a1, void *a2);
void func_021BAE94(u8 *p, u8 *q, void *a2);
void func_021BAED0(u8 *p, u8 *a1, void *a2);
u8 *func_021BAEDC(void *p,void *q,u16 heap);
void func_021BAF4C(unsigned p);
void func_021BAF7C(unsigned p,int v);
int func_021BAFAC(u32 p);
u8 func_021BAFDC(u8 *p);
void func_021BAFE4(u32 p);
void func_021BB00C(Input *p, void *q);
int func_021BB054(u8 *p);
u8 func_021BB1C0(u8 *p);
void func_021BB1CC(u8 *p, u8 i, int c);
u16 func_021BB1E4(u32_021BB1C0 p,u32_021BB1C0 i);
int func_021BB1F4(void);
void func_021BB1F8(u32_021BB1C0 i, void *dst);
u16 func_021BB214(u32_021BB1C0 i);
extern const char d_021C3B80[];
extern const Entry d_021C1E80[];
extern u8 *const d_021C1C88[];
extern const char d_021C3C20[];
extern const u8 d_020A1448[];
extern const u8 d_021C3714[];
extern const CallbackTable d_021C3B94;
extern u8 d_021C3604[];
extern const u8 d_021C3694[],d_021C36B4[],d_021C3674[],d_021C3614[];
extern const u8 d_021C36F4[],d_021C36D4[],d_021C3654[],d_021C3634[];
extern const Table d_021C3744;
extern const char d_021C3C34[];
extern const u16 d_021C3770[];
extern const u16 d_021C375C[10];
extern const u8 d_021C37A8[];





void *func_021B95A0(u32 heap,void *save)
{
    char *p;
    int i;
    p=func_02030734((u16)heap,0x1E50,0,d_021C3B80,88);
    ((struct Obj05283 *)p)->f0=save;
    ((struct Obj05283 *)p)->f4=func_020247A8(heap);
    for(i=0;i<226;i++) *(u8 *)(p+0x1D6E + i)=0;
    func_021B9608((Object *)p);
    func_021B98A0((u8 *)p);
    return p;
}





void func_021B95F4(char *a) { if(a) { func_020247F0(*(char * *)&((struct Obj22311 *)a)->f4); func_020307B0(a); } }





void func_021B9608(Object *p)
{
    int i;
    int n;
    i=0;
    n=0;
    for(;i<12;i++){
        p->starts[i]=n;
        p->counts[i]=d_021C1E80[i].fn(p,d_021C1E80[i].data,d_021C1E80[i].count,p->values+n);
        n+=p->counts[i];
    }
}





/*
 *   Verified EXACT in scratch b24148-r1.log:
 *   void *func_02024148(char *p){return *(void **)(p+8);}
 */
u32 func_021B9654(u8 *p,const u16 *ids,u32 count,u16 *out)
{
    void *save;
    u32 n;
    u32 i;
    save=func_02024148(*(void **)p);
    n=0;
    for(i=0;i<count;i++){
        if(func_0200D064(save,ids[i])){
            u32 id=ids[i];
            p[0x1D6E + (id>>3)] |= (u8)(1<<(id&7));
            *out++=id;
            n++;
        }
    }
    return n;
}





u32 func_021B96C0(u8 *p,const u16 *ids,u32 count,u16 *out)
{
    u32 i;
    if(func_02024150(*(void **)p)){
        for(i=0;i<count;i++){
            u32 id= *ids;
            p[0x1D6E + (id>>3)] |= (u8)(1<<(id&7));
            ids++;
            *out++=id;
        }
        return count;
    }
    return 0;
}




/*
 * note: 2026-10-04 (wD2 lane06): MATCH. Locals declared o, limit, count, base, i; `base = ...; count = 0; limit = ...` in that order fixed the zero register and slots. Only unresolved relocations are arm9 leaves 0x0202414C and 0x02024994, filed as src/matched/arm9 EXACT leaves this wave (need manifest witness).
 */
u32 func_021B9720(u8 *p, u16 *src, u32 n, u16 *out)
{
    void *o;
    u32 limit;
    u32 count;
    u32 base;
    u32 i;
    o = func_0202414C((char *)(*(u32 *)p));
    base = func_02024888(0x97, 0);
    count = 0;
    limit = (u16)(base + 7);
    for (i = 0; i < n; i++) {
        u32 v = src[i];
        if (v >= base && v <= limit) {
            if (func_02024994(o, v - base) == 0)
                continue;
        }
        v = src[i];
        p[0x1D6E + (v >> 3)] |= (u8)(1 << (v & 7));
        *out = v;
        out++;
        count++;
    }
    return count;
}




u32 func_021B97AC(u8 *p,const u16 *ids,u32 count,u16 *out)
{
    u32 i;
    u32 n;
    if(!func_02024160(*(void **)p))return 0;
    i=0;
    n=0;
    for(;i<count;i++){
        u32 id=ids[i];
        p[0x1D6E + (id>>3)] |= (u8)(1<<(id&7));
        *out++=i+0x801;
        n++;
    }
    return n;
}




u32 func_021B9814(u8 *p, u16 *src, u32 n, u16 *out)
{
    u32 i;
    for (i = 0; i < n; i++) {
        u32 c = *src;
        if (c == 0xFFFE) {
            u32 len;
            src++;
            len = *src++;
            while (len != 0) {
                u32 v = *src++;
                p[0x1D6E + (v >> 3)] |= (u8)(1 << (v & 7));
                len--;
            }
            *out = src[-1];
        } else {
            p[0x1D6E + (c >> 3)] |= (u8)(1 << (c & 7));
            src++;
            *out = c;
        }
        out++;
    }
    return n;
}




void func_021B98A0(u8 *p) {
    u32 a = 0xF58;
    u32 b;
    u32 c;
    u32 i;
    u32 offset = 0;
    a -= 0x6C;
    b = 0xF58;
    b -= 0xD8;
    c = 0xF58;
    c -= 0xD8;
    for (i=0; i<27; ++i) {
        u8 *src = d_021C1C88[i];
        *(u32 *)(p+i*4+a) = offset;
        *(u32 *)(p+i*4+b) = func_021B98F8(p, (u16 *)src, (u16 *)(p+0xF58), offset);
        offset += *(u32 *)(p+i*4+c);
    }
}




u32 func_021B98F8(u8 *p, u16 *src, u16 *out, u32 n)
{
    u32 count = 0;
    u32 c = *src;
    while (c != 0xFFFF) {
        if (c == 0xFFFE) {
            u32 len;
            u32 i;
            src++;
            len = *src++;
            for (i = 0; i < len; i++) {
                u32 v = src[i];
                if (p[0x1D6E + (v >> 3)] & (1 << (v & 7))) {
                    out[n++] = v;
                    count++;
                    break;
                }
            }
            src += len;
        } else {
            if (p[0x1D6E + (c >> 3)] & (1 << (c & 7))) {
                out[n++] = c;
                count++;
            }
            src++;
        }
        c = *src;
    }
    return count;
}





u32 func_021B999C(u8 *p, int i) { return *(u32 *)(p + i * 4 + 8); }



/*
 * Two-byte zero alignment padding follows the compiled function.
 */
void func_021B99A4(unsigned int a,unsigned int b,unsigned int c,int d) { unsigned int value; value=*(unsigned int *)(a+b*4+0x38); func_02024810(*(char * *)&((struct Obj22312 *)a)->f4,*(unsigned short *)(a+(value+c)*2+0x68),d); }



unsigned short func_021B99C4(unsigned int a,unsigned int b,unsigned int c) { unsigned int value; value=*(unsigned int *)(a+b*4+0x38); return *(unsigned short *)(a+(value+c)*2+0x68); }



u32 func_021B99D8(u32 a, u32 b, u32 c) { return func_021B98F8((u8 *)a, (u16 *)b, (u16 *)c, 0); }











u8 *func_021B99E4(u8 *p) { return p + 4 + (((struct Obj22313 *)p)->f2 - 1) * 2; }










u16 func_021B99F0(int unused, int id, int index) {
    u8 *p = d_021C1C88[id];
    int n = 0;
    while (((struct Obj07996 *)p)->f0 != 65535) {
        if (n == index) {
            if (((struct Obj07996 *)p)->f0 == 65534) p = func_021B99E4(p);
            return ((struct Obj07996 *)p)->f0;
        }
        if (((struct Obj07996 *)p)->f0 == 65534) {
            p = func_021B99E4(p);
            p += 2;
        } else {
            p += 2;
        }
        ++n;
    }
    return 0;
}










/*
 * lever: explicit if/else increments preserve the branch after the skip call.
 */
void func_021B9A3C(u8 *p, u16 a1, int a2) { func_02024810(*(char * *)&((struct Obj22314 *)p)->f4, a1, a2); }











int func_021B9A48(u32 a0) { return 0xffff; }










void *func_021B9A50(u8 *context,void *arg) {
    u8 *p;
    int i;
    p=func_02030734(42,0x90,0,d_021C3C20,0xdf);
    if(p!=0) {
        ((struct Obj01920 *)p)->f64=0;
        ((struct Obj01920 *)p)->f7C=0;
        *(u8 * *)&((struct Obj01920 *)p)->f18=context;
        ((struct Obj01920 *)p)->f1C=arg;
        *(u8 * *)&((struct Obj01920 *)p)->f78=func_021BF6D4(context);
        func_0204A48C((const struct Cfg *)d_020A1448,(u32)d_021C3714,42);
        ((struct Obj01920 *)p)->f20=func_0204B100(128,0,42);
        func_0203F8F4(42);
        func_02045088(42);
        func_0207D534((void *)0x0400006c,-16);
        func_0207D534((void *)0x0400106c,-16);
        ((struct Obj01920 *)p)->f0=func_02030DA8(func_021BF7D0(context),(u32)func_021B9BAC,p,2);
        ((struct Obj01920 *)p)->f4=func_021B9BA4((void (*)(void *, u8 *))func_021B9BD0,p,1);
        for(i=0;i<4;++i) *(void **)(p+8+i*4)=0;
        ((struct Obj01920 *)p)->f70=0;
        p[0x74]=0;
        ((struct Obj01920 *)p)->f84=0;
        ((struct Obj01920 *)p)->f88=0;
        ((struct Obj01920 *)p)->f8C=func_020490F4(43,42);
    }
    return p;
}










void func_021B9B20(u8 *p) {
    int i, j;
    if (p) {
        func_02049238(((struct Obj06380 *)p)->f8C);
        for (i=0; i<4; ++i) {
            void *r = *(void **)(p+8+i*4);
            if (r) func_02030EAC(r);
        }
        func_02030EAC(((struct Obj06380 *)p)->f0);
        func_02030EAC(((struct Obj06380 *)p)->f4);
        func_021BCA30(((struct Obj06380 *)p)->f64);
        func_0204B1CC(((struct Obj06380 *)p)->f20);
        for (j=0; j<2; ++j) {
            u8 *r = p+j*12;
            func_0204ADA4(((struct Obj05284 *)r)->f24);
            func_0204A8D4(((struct Obj05284 *)r)->f28);
            func_0204AFD8(((struct Obj05284 *)r)->f2C);
            func_0204ADA4(((struct Obj05284 *)r)->f3C);
            func_0204A8D4(((struct Obj05284 *)r)->f40);
            func_0204AFD8(((struct Obj05284 *)r)->f44);
        }
        func_0204A5AC();
        func_020450C8();
        func_0203F9B4();
        func_020307B0(p);
    }
}










void *func_021B9BA4(void (*fn)(void *, u8 *), u8 *p, int n) { return func_020056A0(fn, p, n); }










void func_021B9BAC(int a,unsigned char *b) { func_0204A600(); if(((struct Obj03239 *)b)->f64) func_021BCA84(((struct Obj03239 *)b)->f64); if(((struct Obj03239 *)b)->f7C) { func_0201C4E4(*(struct PrintSys * *)&((struct Obj03239 *)b)->f7C); func_021BADE8(b); } }










void func_021B9BD0(int a,unsigned char *b) { if(((struct Obj13768 *)b)->f84) ((struct Obj13768 *)b)->f84=0; func_020419E4(); func_0204A648(); }










void func_021B9BEC(u8 *p, int id) {
    CallbackTable table;
    int i;
    Context *q;
    table = d_021C3B94;
    if (id >= 35) return;
    q = func_02030734(42, 24, 0, d_021C3C20, 493);
    if (!q) return;
    q->state = 0;
    q->id = id;
    q->owner = (u8 *)p;
    q->field4 = *(u32 *)&((struct Obj10264 *)p)->f18;
    q->field8 = ((struct Obj10264 *)p)->f1C;
    for (i=0; i<4; ++i) {
        if (!*(void **)(p+i*4+8)) {
            q->slot = i;
            *(void **)((u32)p+i*4+8) = func_02030DA8(func_021BF7D0(*(u8 * *)&((struct Obj10264 *)p)->f18), table.entries[id], q, 1);
            return;
        }
    }
}









int func_021B9C74(unsigned int a) { int i; for(i=0;i<4;i++) if(*(int *)(a+(unsigned)i*4+8)) return 0; return 1; }









int func_021B9C90(unsigned int a,int b) { int i; int value; for(i=0;i<4;i++) if(*(void **)(a+(unsigned)i*4+8)) { value=*(int *)(func_02030EE8(*(void **)(a+(unsigned)i*4+8))+12); if(value==b) return 0; } return 1; }









void func_021B9CBC(u8 *p)
{
    func_02030EAC(*(void **)(*(u32 *)&((struct Obj00135 *)p)->f0 + ((struct Obj00135 *)p)->f10 * 4 + 8));
    *(u32 *)(*(u32 *)&((struct Obj00135 *)p)->f0 + ((struct Obj00135 *)p)->f10 * 4 + 8) = 0;
    func_020307B0(p);
}









void func_021B9CE4(void *unused,u8 *p) {
    void *h;
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile u32 *)0x04000000 &= ~0xe000;
    *(volatile u32 *)0x04001000 &= ~0xe000;
    func_0204335C(0);
    func_020434CC();
    func_02043588();
    *(volatile u32 *)0x04000000 &= ~0x1f00;
    *(volatile u32 *)0x04001000 &= ~0x1f00;
    h=func_020490F4(43,42);
    func_021BA070(p);
    func_021B9F34(p,(void *)h);
    *(u8 * *)&((struct Obj22315 *)(*(u8 * *)&((struct Obj00135 *)p)->f0))->f54=func_021BBC5C(*(u8 * *)&((struct Obj00135 *)p)->f0,*(u8 * *)&((struct Obj00135 *)p)->f4,((struct Obj00135 *)p)->f8);
    func_021BBD60(*(u8 * *)&((struct Obj22316 *)(*(u8 * *)&((struct Obj00135 *)p)->f0))->f54,(u32)h);
    *(u8 * *)&((struct Obj22317 *)(*(u8 * *)&((struct Obj00135 *)p)->f0))->f58=func_021BB290((u32)(*(u8 * *)&((struct Obj00135 *)p)->f0),*(u8 * *)&((struct Obj00135 *)p)->f4,(u32)(((struct Obj00135 *)p)->f8));
    func_021BB328(*(u8 * *)&((struct Obj22318 *)(*(u8 * *)&((struct Obj00135 *)p)->f0))->f58,(u32)h);
    *(u8 * *)&((struct Obj22319 *)(*(u8 * *)&((struct Obj00135 *)p)->f0))->f5C=func_021BF844(*(u8 * *)&((struct Obj00135 *)p)->f0,*(u8 * *)&((struct Obj00135 *)p)->f4,((struct Obj00135 *)p)->f8);
    func_021BF8F4(*(u8 * *)&((struct Obj22320 *)(*(u8 * *)&((struct Obj00135 *)p)->f0))->f5C);
    func_020498F4((void *)((u32)h),30,5,0,0,0,42);
    func_02049658((void *)((u32)h),18,5,0,0,0,42);
    func_020498F4((void *)((u32)h),31,6,0,0,0,42);
    func_02049658((void *)((u32)h),18,6,0,0,0,42);
    func_02040588(6,0);
    func_02049BDC((void *)((u32)h),4,4,128,160,32,42);
    ((struct Obj22321 *)(*(u8 * *)&((struct Obj00135 *)p)->f0))->f68=0x294b;
    func_02061CA4((void *)31,188,(u32)(*(u8 * *)&((struct Obj00135 *)p)->f0+0x68),2);
    ((struct Obj22322 *)(*(u8 * *)&((struct Obj00135 *)p)->f0))->f6A=0x5694;
    func_02061CA4((void *)31,190,(u32)(*(u8 * *)&((struct Obj00135 *)p)->f0+0x6a),2);
    func_02049658((void *)((u32)h),18,7,0,0,0,42);
    func_020498F4((void *)((u32)h),24,7,0,0,0,42);
    func_020413B0(7,0,0,32,32,5);
    ((struct Obj22323 *)(*(u8 * *)&((struct Obj00135 *)p)->f0))->f6C=func_020450F0(7,3,5,26,7,5,1);
    func_02043B5C(func_02045770((struct Descriptor *)((struct Obj22324 *)(*(u8 * *)&((struct Obj00135 *)p)->f0))->f6C),7);
    ((struct Obj22325 *)(*(u8 * *)&((struct Obj00135 *)p)->f0))->f70=0;
    if(func_021BF7C4(*(u8 * *)&((struct Obj00135 *)p)->f4) || func_021BF6D8(*(u8 * *)&((struct Obj00135 *)p)->f4)!=2) func_021BAD68(p,1);
    else func_021BAD68(p,0);
    func_021BAD2C(*(u8 * *)&((struct Obj00135 *)p)->f0,0);
    *(u8 * *)&((struct Obj22326 *)(*(u8 * *)&((struct Obj00135 *)p)->f0))->f64=func_021BC990(*(u8 * *)&((struct Obj00135 *)p)->f0,*(u8 * *)&((struct Obj00135 *)p)->f4,((struct Obj00135 *)p)->f8);
    func_021BCB50((struct Object *)(*(u8 * *)&((struct Obj22327 *)(*(u8 * *)&((struct Obj00135 *)p)->f0))->f64));
    func_02040588(0,1);
    func_020434DC(16,1);
    func_02043598(16,1);
    func_0207D46C();
    func_02049658((void *)((u32)h),16,3,0,0,0,42);
    func_02049658((void *)((u32)h),17,3,96,0,0,42);
    func_02049238(h);
    func_021B9CBC(p);
}









void func_021B9F34(u8 *p, void *archive) {
    u8 *q = *(u8 * *)&((struct Obj22328 *)p)->f0;
    int i;
    for (i=0; i<2; ++i) {
        u8 *r = q+i*12;
        ((struct Obj05286 *)r)->f24 = func_0204ABF0(archive, 7, i, 0, 42);
        ((struct Obj05286 *)r)->f28 = func_0204A6C8((void *)archive, 19, 0, i, 42);
        ((struct Obj05286 *)r)->f2C = func_0204AF28((void *)archive, 36, 42, 42);
        ((struct Obj05286 *)r)->f3C = func_0204ABF0(archive, 1, i, 224, 42);
        ((struct Obj05286 *)r)->f40 = func_0204A6C8((void *)archive, 46, 0, i, 42);
        ((struct Obj05286 *)r)->f44 = func_0204AF28((void *)archive, 34, 40, 42);
    }
}









/*
 * volatile: 0x021BA058 reads hardware register 0x04000304 before updating it.
 */
void func_021B9FB4(int unused, u8 *p) {
    u8 *q = *(u8 * *)&((struct Obj04441 *)p)->f0;
    switch (((struct Obj04441 *)p)->f14) {
    case 0:
        func_0202208C(0,0,0,0,5,1,42);
        ++((struct Obj04441 *)p)->f14;
        break;
    case 1:
        if (func_020221A4()) {
            func_020452E8(((struct Obj22329 *)(*(u8 * *)&((struct Obj04441 *)p)->f0))->f6C);
            func_021BBCF0(((struct Obj22330 *)(*(u8 * *)&((struct Obj04441 *)p)->f0))->f54);
            func_021BB2CC(((struct Obj22331 *)(*(u8 * *)&((struct Obj04441 *)p)->f0))->f58);
            func_021BF8BC(((struct Obj22332 *)(*(u8 * *)&((struct Obj04441 *)p)->f0))->f5C);
            func_0201D83C(((struct Obj07997 *)q)->f80);
            func_0201C6EC(((struct Obj07997 *)q)->f7C);
            func_0201C4C0(((struct Obj07997 *)q)->f7C);
            ((struct Obj07997 *)q)->f7C = 0;
            func_020403F4(0);
            func_020403F4(1);
            func_020403F4(2);
            func_020403F4(3);
            func_020403F4(4);
            func_020403F4(5);
            func_020403F4(6);
            *(volatile u16 *)0x04000304 |= 0x8000;
            func_021B9CBC(p);
        }
        break;
    }
}









static inline void GX_SetDispSelect(GXDispSelect sel) {
    *(volatile u16 *)0x04000304=(u16)((*(volatile u16 *)0x04000304 & ~0x8000) | (sel<<15));
}









/*
 * lever: GX_SetDispSelect's enum inline keeps the 0xFFFF7FFF pool mask;
 *   a direct halfword &= expression emits 0x00007FFF (two bytes differ).
 * abi: original A0E0..A0EC truncates i separately before both calls;
 *   narrow first extern parameters retain those explicit u8 argument values.
 * volatile: hardware halfword at 04000304 is read/modified at A078..A07E.
 */
void func_021BA070(u8 *p) {
    u8 *q=*(u8 * *)&((struct Obj22333 *)p)->f0;
    int i;
    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);
    func_020433E0((const struct DispVram *)d_021C3714);
    func_0203FC28((struct DispConfig *)d_021C3604);
    func_0203FCA0(0,(const struct BgTemplate *)d_021C3694,0);
    func_0203FCA0(1,(const struct BgTemplate *)d_021C36B4,0);
    func_0203FCA0(2,(const struct BgTemplate *)d_021C3674,0);
    func_0203FCA0(3,(const struct BgTemplate *)d_021C3614,0);
    func_0203FCA0(4,(const struct BgTemplate *)d_021C36F4,0);
    func_0203FCA0(5,(const struct BgTemplate *)d_021C36D4,0);
    func_0203FCA0(6,(const struct BgTemplate *)d_021C3654,0);
    func_0203FCA0(7,(const struct BgTemplate *)d_021C3634,0);
    for(i=0;i<=7;++i) {
        func_020414EC((u8)i);
        func_02040588((u8)i,1);
    }
    ((struct Obj13769 *)q)->f80=func_0201D7EC(23,0,0,0,42);
    ((struct Obj13769 *)q)->f7C=func_0201C450(0x500,42);
}









void func_021BA150(int unused, u8 *p) {
    switch (((struct Obj10265 *)p)->f14) {
    case 0:
        func_0202208C(0, 1, 1, 0, 5, 1, 42);
        ++((struct Obj10265 *)p)->f14;
        break;
    case 1:
        if (func_020221A4()) ++((struct Obj10265 *)p)->f14;
        break;
    default:
        func_021B9CBC(p);
        break;
    }
}









void func_021BA1A0(void *unused, u8 *p)
{
    u8 *q;
    q = *(u8 * *)&((struct Obj00135 *)p)->f0;
    q[0x74] = 0;
    func_021BC23C(((struct Obj06381 *)q)->f54);
    func_021BC72C((char *)(*(u8 * *)&((struct Obj06381 *)q)->f54), func_021BF714(*(u8 * *)&((struct Obj00135 *)p)->f4));
    func_021BCCA8(((struct Obj06381 *)q)->f64);
    func_021BCD44(((struct Obj06381 *)q)->f64);
    func_021B9CBC(p);
}









void func_021BA1D8(void *unused, u8 *p)
{
    func_021BAE24(((struct Obj00135 *)p)->f0, ((struct Obj00135 *)p)->f4, ((struct Obj00135 *)p)->f8);
    func_021B9CBC(p);
}









/*
 * extent: trailing two-byte zero alignment padding.
 */
void func_021BA1F0(void *unused, u8 *p)
{
    func_021BAE94(((struct Obj00135 *)p)->f0, ((struct Obj00135 *)p)->f4, ((struct Obj00135 *)p)->f8);
    func_021B9CBC(p);
}









void func_021BA208(void *unused, u8 *p)
{
    func_021BAED0(((struct Obj00135 *)p)->f0, ((struct Obj00135 *)p)->f4, ((struct Obj00135 *)p)->f8);
    func_021B9CBC(p);
}









void func_021BA220(void *unused, u8 *p)
{
    u8 *q;
    q = *(u8 * *)&((struct Obj00135 *)p)->f0;
    q[0x74] = 1;
    func_021BC704(*(u8 * *)&((struct Obj06382 *)q)->f54, 0);
    func_021BC724(*(u8 * *)&((struct Obj06382 *)q)->f54);
    func_021BCF7C(*(u8 * *)&((struct Obj06382 *)q)->f64, (u8)func_021BF71C(*(u8 * *)&((struct Obj06382 *)q)->f18), 1);
    func_021B9CBC(p);
}









void func_021BA258(void *unused, u8 *p)
{
    u8 *q;
    q = *(u8 * *)&((struct Obj00135 *)p)->f0;
    q[0x74] = 1;
    func_021BC704(*(u8 * *)&((struct Obj06383 *)q)->f54, 0);
    func_021BC724(*(u8 * *)&((struct Obj06383 *)q)->f54);
    func_021BCF7C(*(u8 * *)&((struct Obj06383 *)q)->f64, (u8)func_021BF71C(*(u8 * *)&((struct Obj06383 *)q)->f18), 0);
    func_021B9CBC(p);
}









void func_021BA290(int unused, u8 *p) {
    u8 *q = *(u8 * *)&((struct Obj00135 *)p)->f0;
    q[0x74] = 0;
    func_021BCF7C(*(u8 * *)&((struct Obj05287 *)q)->f64, (u8)func_021BF71C(*(u8 * *)&((struct Obj05287 *)q)->f18), 0);
    func_021BC728(*(u8 * *)&((struct Obj05287 *)q)->f54);
    func_021BC704(*(u8 * *)&((struct Obj05287 *)q)->f54, 1);
    func_021BC72C((char *)(*(u8 * *)&((struct Obj05287 *)q)->f54), func_021BF714(*(u8 * *)&((struct Obj00135 *)p)->f4));
    func_021B9CBC(p);
}









void func_021BA2D8(int unused, u8 *p) {
    u8 *q = *(u8 * *)&((struct Obj03748 *)p)->f0;
    int a, b;
    switch (((struct Obj03748 *)p)->f14) {
    case 0:
        func_021BC704(*(u8 * *)&((struct Obj01921 *)q)->f54, 1);
        func_021BC72C((char *)(*(u8 * *)&((struct Obj01921 *)q)->f54), func_021BF714(*(u8 * *)&((struct Obj03748 *)p)->f4));
        ++((struct Obj03748 *)p)->f14;
        break;
    case 1:
        func_021BF7E0(*(u8 * *)&((struct Obj03748 *)p)->f4);
        func_021BCC58(*(u8 * *)&((struct Obj01921 *)q)->f64);
        func_021BC6EC(*(u8 * *)&((struct Obj01921 *)q)->f54);
        func_021BC724(*(u8 * *)&((struct Obj01921 *)q)->f54);
        func_021BB76C(*(u8 * *)&((struct Obj01921 *)q)->f58);
        func_021BBEF4(*(u8 * *)&((struct Obj01921 *)q)->f54, 0);
        if (func_021BF6DC(*(u8 * *)&((struct Obj03748 *)p)->f4) == 1) func_021BB958((char *)(*(u8 * *)&((struct Obj01921 *)q)->f58));
        if (func_021BF6DC(*(u8 * *)&((struct Obj03748 *)p)->f4) == 0) func_021BAD68(p, 2);
        else func_021BAD68(p, 4);
        ++((struct Obj03748 *)p)->f14;
        break;
    case 2:
        a = func_021BB784(*(u8 * *)&((struct Obj01921 *)q)->f58);
        b = func_021BBF54(*(u8 * *)&((struct Obj01921 *)q)->f54);
        if (a && b) {
            func_021BB6A0(*(u8 * *)&((struct Obj01921 *)q)->f58, func_021BF724(*(u8 * *)&((struct Obj01921 *)q)->f18));
            func_021BB658(*(u8 * *)&((struct Obj01921 *)q)->f58, 1);
            func_021B9CBC(p);
        }
        break;
    }
}









void func_021BA398(int unused, u8 *p) {
    u8 *q = *(u8 * *)&((struct Obj06384 *)p)->f0;
    switch (((struct Obj06384 *)p)->f14) {
    case 0:
        ++((struct Obj06384 *)p)->f14;
    case 1:
        func_021BCC58(*(u8 * *)&((struct Obj06385 *)q)->f64);
        func_021BB8D8(*(u8 * *)&((struct Obj06385 *)q)->f58);
        func_021BB8B8(*(u8 * *)&((struct Obj06385 *)q)->f58);
        if (func_021BF6DC(*(u8 * *)&((struct Obj06384 *)p)->f4) == 1) func_021BB958((char *)(*(u8 * *)&((struct Obj06385 *)q)->f58));
        ++((struct Obj06384 *)p)->f14;
        break;
    case 2:
        if (func_021BB954(*(u8 * *)&((struct Obj06385 *)q)->f58)) func_021B9CBC(p);
        break;
    }
}









/*
 * abi: CF70 forwards its legacy third argument only to CE48, whose full
 *   body ignores it and calls D0F8(p,7,0); original A448 sets only r0/r1.
 */
void func_021BA3F0(void *unused,u8 *p) {
    u8 *q=*(u8 * *)&((struct Obj03749 *)p)->f0;
    int a,b;
    switch(((struct Obj03749 *)p)->f14) {
    case 0:
        func_021BCEE4((char *)(*(u8 * *)&((struct Obj01711 *)q)->f64),1);
        func_021BB9C0(*(u8 * *)&((struct Obj01711 *)q)->f58,0);
        ++((struct Obj03749 *)p)->f14;
        break;
    case 1:
        a=func_021BBB0C(*(u8 * *)&((struct Obj01711 *)q)->f58,0);
        b=func_021BCF38((char *)(*(u8 * *)&((struct Obj01711 *)q)->f64),1);
        if(a && b) {
            func_021BCF70(*(u8 * *)&((struct Obj01711 *)q)->f64,1);
            func_021BF7E0(*(u8 * *)&((struct Obj03749 *)p)->f4);
            func_021BCC58(*(u8 * *)&((struct Obj01711 *)q)->f64);
            func_021BB658(*(u8 * *)&((struct Obj01711 *)q)->f58,0);
            func_021BB8D8(*(u8 * *)&((struct Obj01711 *)q)->f58);
            func_021BB8B8(*(u8 * *)&((struct Obj01711 *)q)->f58);
            if(func_021BF6DC(*(u8 * *)&((struct Obj03749 *)p)->f4)==1) func_021BB958((char *)(*(u8 * *)&((struct Obj01711 *)q)->f58));
            if(func_021BF6DC(*(u8 * *)&((struct Obj03749 *)p)->f4)==0) func_021BAD68(p,2);
            else func_021BAD68(p,4);
            ++((struct Obj03749 *)p)->f14;
        }
        break;
    case 2:
        if(func_021BB954(*(u8 * *)&((struct Obj01711 *)q)->f58)) ++((struct Obj03749 *)p)->f14;
        break;
    case 3:
        func_021BB6A0(*(u8 * *)&((struct Obj01711 *)q)->f58,func_021BF724(*(u8 * *)&((struct Obj01711 *)q)->f18));
        func_021BB658(*(u8 * *)&((struct Obj01711 *)q)->f58,1);
        func_021B9CBC(p);
        break;
    }
}









void func_021BA4CC(void *unused,u8 *p) {
    u8 *q=*(u8 * *)&((struct Obj03237 *)p)->f0;
    int a,b;
    switch(((struct Obj03237 *)p)->f14) {
    case 0:
        if(func_021BF6DC(*(u8 * *)&((struct Obj03237 *)p)->f4)==1) {
            func_021BCEE4((char *)(*(u8 * *)&((struct Obj01530 *)q)->f64),0);
            func_021BB9C0(*(u8 * *)&((struct Obj01530 *)q)->f58,0);
        } else func_021BD000((char *)(*(u8 * *)&((struct Obj01530 *)q)->f64));
        ++((struct Obj03237 *)p)->f14;
        break;
    case 1:
        if(func_021BF6DC(*(u8 * *)&((struct Obj03237 *)p)->f4)==1) {
            a=func_021BBB0C(*(u8 * *)&((struct Obj01530 *)q)->f58,0);
            b=func_021BCF38((char *)(*(u8 * *)&((struct Obj01530 *)q)->f64),0);
        } else {
            a=func_021BD028(*(u8 * *)&((struct Obj01530 *)q)->f64);
            b=1;
        }
        if(a && b) ++((struct Obj03237 *)p)->f14;
        break;
    case 2:
        func_021BCB50((struct Object *)(*(u8 * *)&((struct Obj01530 *)q)->f64));
        func_021BB658(*(u8 * *)&((struct Obj01530 *)q)->f58,0);
        func_021BB7A0(*(u8 * *)&((struct Obj01530 *)q)->f58);
        func_021BBEF4(*(u8 * *)&((struct Obj01530 *)q)->f54,1);
        if(func_021BF7C4(*(u8 * *)&((struct Obj03237 *)p)->f4) || func_021BF6D8(*(u8 * *)&((struct Obj03237 *)p)->f4)!=2) func_021BAD68(p,1);
        else func_021BAD68(p,0);
        ++((struct Obj03237 *)p)->f14;
        break;
    case 3:
        a=func_021BB7B8(*(u8 * *)&((struct Obj01530 *)q)->f58);
        b=func_021BBF54(*(u8 * *)&((struct Obj01530 *)q)->f54);
        if(a && b) {
            func_021BC728(*(u8 * *)&((struct Obj01530 *)q)->f54);
            func_021BC6F8(*(u8 * *)&((struct Obj01530 *)q)->f54);
            q[0x74]=0;
            func_021B9CBC(p);
        }
        break;
    }
}









void func_021BA5C4(void *unused,u8 *p) {
    u8 *q=*(u8 * *)&((struct Obj04442 *)p)->f0;
    int a,b;
    switch(((struct Obj04442 *)p)->f14) {
    case 0:
        ++((struct Obj04442 *)p)->f14;
        break;
    case 1:
        if(func_021BBC10(*(u8 * *)&((struct Obj01142 *)q)->f58)) {
            func_021BB658(*(u8 * *)&((struct Obj01142 *)q)->f58,0);
            func_021BCEE4((char *)(*(u8 * *)&((struct Obj01142 *)q)->f64),3);
            ++((struct Obj04442 *)p)->f14;
        }
        break;
    case 2:
        if(func_021BCF38((char *)(*(u8 * *)&((struct Obj01142 *)q)->f64),3)) {
            func_021BB838(*(u8 * *)&((struct Obj01142 *)q)->f58);
            func_021BB9C0(*(u8 * *)&((struct Obj01142 *)q)->f58,0);
            ++((struct Obj04442 *)p)->f14;
        }
        break;
    case 3:
        a=func_021BBB0C(*(u8 * *)&((struct Obj01142 *)q)->f58,0);
        b=func_021BB854(*(u8 * *)&((struct Obj01142 *)q)->f58);
        if(a && b) {
            func_021BCC88(*(u8 * *)&((struct Obj01142 *)q)->f64);
            func_021BF9F0(*(u8 * *)&((struct Obj01142 *)q)->f5C);
            func_021BFAA0(*(u8 * *)&((struct Obj01142 *)q)->f5C);
            if(func_021BF6DC(*(u8 * *)&((struct Obj04442 *)p)->f4)==0) func_021BAD68(p,3);
            else func_021BAD68(p,5);
            ++((struct Obj04442 *)p)->f14;
        }
        break;
    case 4:
        if(func_021BFB58(*(u8 * *)&((struct Obj01142 *)q)->f5C)) {
            unsigned x;
            func_021BFC64(*(u8 * *)&((struct Obj01142 *)q)->f5C,func_021BF784(*(u8 * *)&((struct Obj01142 *)q)->f18));
            x=func_021BF7AC(*(u8 * *)&((struct Obj01142 *)q)->f18);
            func_021BFDB0(*(u8 * *)&((struct Obj01142 *)q)->f5C,x,func_021BF7B8(*(u8 * *)&((struct Obj01142 *)q)->f18));
            func_021BFC20(*(u8 * *)&((struct Obj01142 *)q)->f5C,1);
            func_021B9CBC(p);
        }
        break;
    }
}









void func_021BA6BC(void *unused, u8 *p)
{
    u8 *q;
    int a, b, flag;
    u32 enabled;
    q = *(u8 * *)&((struct Obj02164 *)p)->f0;
    enabled = func_021BF7FC(*(u8 * *)&((struct Obj02164 *)p)->f4);
    switch (((struct Obj02164 *)p)->f14) {
    case 0:
        func_021BD000((char *)(*(u8 * *)&((struct Obj01531 *)q)->f64));
        ++((struct Obj02164 *)p)->f14;
        break;
    case 1:
        if (func_021BD028(*(u8 * *)&((struct Obj01531 *)q)->f64)) ++((struct Obj02164 *)p)->f14;
        break;
    case 2:
        func_021BCC58(*(u8 * *)&((struct Obj01531 *)q)->f64);
        ++((struct Obj02164 *)p)->f14;
        break;
    case 3:
        func_021BFC20(*(u8 * *)&((struct Obj01531 *)q)->f5C, 0);
        func_021BFB7C(*(u8 * *)&((struct Obj01531 *)q)->f5C);
        ++((struct Obj02164 *)p)->f14;
        break;
    case 4:
        if (func_021BFBA0(*(u8 * *)&((struct Obj01531 *)q)->f5C)) {
            func_021BB8B8(*(u8 * *)&((struct Obj01531 *)q)->f58);
            ++((struct Obj02164 *)p)->f14;
        }
        break;
    case 5:
        func_021BAD2C(*(u8 * *)&((struct Obj02164 *)p)->f0, 0);
        flag = 0;
        func_021BB870(*(u8 * *)&((struct Obj01531 *)q)->f58);
        if (func_021BF6DC(*(u8 * *)&((struct Obj02164 *)p)->f4) == 0) {
            flag = 0;
            func_021BB9C0(*(u8 * *)&((struct Obj01531 *)q)->f58, flag);
        } else {
            if (enabled) flag = 1;
            func_021BB9C0(*(u8 * *)&((struct Obj01531 *)q)->f58, flag);
        }
        if (func_021BF6DC(*(u8 * *)&((struct Obj02164 *)p)->f4) == 0) func_021BAD68(p, 2);
        else func_021BAD68(p, 4);
        ++((struct Obj02164 *)p)->f14;
        break;
    case 6:
        a = func_021BB8AC(*(u8 * *)&((struct Obj01531 *)q)->f58);
        b = func_021BBB0C(*(u8 * *)&((struct Obj01531 *)q)->f58, enabled != 0);
        if (a && b) {
            func_021BB6A0(*(u8 * *)&((struct Obj01531 *)q)->f58, func_021BF724(*(u8 * *)&((struct Obj01531 *)q)->f18));
            func_021BB658(*(u8 * *)&((struct Obj01531 *)q)->f58, 1);
            func_021B9CBC(p);
        }
        break;
    }
}









void func_021BA7CC(void *unused, u8 *p)
{
    u8 *q;
    int a, b;
    q = *(u8 * *)&((struct Obj03238 *)p)->f0;
    switch (((struct Obj03238 *)p)->f14) {
    case 0:
        ++((struct Obj03238 *)p)->f14;
        break;
    case 1:
        if (func_021C00FC(*(u8 * *)&((struct Obj01247 *)q)->f5C)) {
            func_021BCB50((struct Object *)(*(u8 * *)&((struct Obj01247 *)q)->f64));
            func_021BFC20(*(u8 * *)&((struct Obj01247 *)q)->f5C, 0);
            func_021BFB7C(*(u8 * *)&((struct Obj01247 *)q)->f5C);
            func_021BBEF4(*(u8 * *)&((struct Obj01247 *)q)->f54, 1);
            ++((struct Obj03238 *)p)->f14;
        }
        break;
    case 2:
        a = func_021BFBA0(*(u8 * *)&((struct Obj01247 *)q)->f5C);
        b = func_021BBF54(*(u8 * *)&((struct Obj01247 *)q)->f54);
        if (a && b) {
            func_021BB804(*(u8 * *)&((struct Obj01247 *)q)->f58);
            func_021BAD2C(*(u8 * *)&((struct Obj03238 *)p)->f0, 0);
            func_021BB870(*(u8 * *)&((struct Obj01247 *)q)->f58);
            if (func_021BF7C4(*(u8 * *)&((struct Obj03238 *)p)->f4) || func_021BF6D8(*(u8 * *)&((struct Obj03238 *)p)->f4) != 2) func_021BAD68(p, 1);
            else func_021BAD68(p, 0);
            ++((struct Obj03238 *)p)->f14;
        }
        break;
    case 3:
        if (func_021BB8AC(*(u8 * *)&((struct Obj01247 *)q)->f58)) {
            func_021BB814(*(u8 * *)&((struct Obj01247 *)q)->f58);
            ++((struct Obj03238 *)p)->f14;
        }
        break;
    case 4:
        if (func_021BB82C(*(u8 * *)&((struct Obj01247 *)q)->f58)) {
            func_021BC23C(*(u8 * *)&((struct Obj01247 *)q)->f54);
            func_021BC704(*(u8 * *)&((struct Obj01247 *)q)->f54, 1);
            func_021BC728(*(u8 * *)&((struct Obj01247 *)q)->f54);
            func_021BC6F8(*(u8 * *)&((struct Obj01247 *)q)->f54);
            q[0x74] = 0;
            func_021B9CBC(p);
        }
        break;
    }
}









void func_021BA8C4(void *unused,u8 *p) {
    u8 *q;
    q=*(u8 * *)&((struct Obj05288 *)p)->f0;
    switch(((struct Obj05288 *)p)->f14) {
    case 0:
        func_021BFC20((u8 *)(*(u32 *)&((struct Obj02815 *)q)->f5C),0);
        func_021BFB7C(((struct Obj02815 *)q)->f5C);
        ++((struct Obj05288 *)p)->f14; break;
    case 1:
        if(func_021BFBA0(((struct Obj02815 *)q)->f5C)) {
            func_021BB804(((struct Obj02815 *)q)->f58);
            func_021BAD2C(*(u8 * *)&((struct Obj05288 *)p)->f0,0);
            func_021BB870(((struct Obj02815 *)q)->f58);
            ++((struct Obj05288 *)p)->f14;
        } break;
    case 2:
        if(func_021BB8AC(((struct Obj02815 *)q)->f58)) {
            func_021BB814(((struct Obj02815 *)q)->f58);
            ++((struct Obj05288 *)p)->f14;
        } break;
    case 3:
        if(func_021BB82C(((struct Obj02815 *)q)->f58)) {
            func_021BC23C(((struct Obj02815 *)q)->f54);
            func_021BC704(*(u8 * *)&((struct Obj02815 *)q)->f54,0);
            func_021B9CBC(p);
        } break;
    }
}








void func_021BA958(void *unused, u8 *p)
{
    u8 *q;
    q = *(u8 * *)&((struct Obj00135 *)p)->f0;
    func_021BC72C((char *)(*(u8 * *)&((struct Obj13770 *)q)->f54), func_021BF714(*(u8 * *)&((struct Obj13770 *)q)->f18));
    func_021B9CBC(p);
}








void func_021BA974(void *unused, u8 *p)
{
    u8 *q;
    q = *(u8 * *)&((struct Obj00135 *)p)->f0;
    func_021BCF7C(*(u8 * *)&((struct Obj13771 *)q)->f64, (u8)func_021BF71C(*(u8 * *)&((struct Obj13771 *)q)->f18), 1);
    func_021B9CBC(p);
}








void func_021BA998(void *unused, u8 *p)
{
    u8 *q;
    q = *(u8 * *)&((struct Obj00135 *)p)->f0;
    func_021BB6A0(*(u8 * *)&((struct Obj13772 *)q)->f58, func_021BF724(*(u8 * *)&((struct Obj13772 *)q)->f18));
    func_021B9CBC(p);
}








void func_021BA9B4(void *unused, u8 *p)
{
    u8 *q;
    q = *(u8 * *)&((struct Obj00135 *)p)->f0;
    func_021BFC64(*(u8 * *)&((struct Obj13773 *)q)->f5C, func_021BF784(*(u8 * *)&((struct Obj13773 *)q)->f18));
    func_021B9CBC(p);
}








void func_021BA9D0(void *unused, u8 *p)
{
    u8 *q;
    q = *(u8 * *)&((struct Obj10266 *)p)->f0;
    switch (((struct Obj10266 *)p)->f14) {
    case 0:
        func_021BFCA4(*(u8 * *)&((struct Obj10267 *)q)->f5C, func_021BF7A0(*(u8 * *)&((struct Obj10267 *)q)->f18));
        (((struct Obj10266 *)p)->f14)++;
        break;
    case 1:
        if (func_021BFD60(*(u8 * *)&((struct Obj10267 *)q)->f5C)) func_021B9CBC(p);
        break;
    }
}








void func_021BAA0C(int a,u8 *p) { u8 *q; q=*(u8 * *)&((struct Obj00135 *)p)->f0; func_021BCFBC((char *)(*(u8 * *)&((struct Obj22334 *)q)->f64),(u8)func_021BF71C(*(u8 * *)&((struct Obj00135 *)p)->f4),1); func_021B9CBC(p); }








void func_021BAA30(int a,u8 *p) { func_021B9CBC(p); }








void func_021BAA3C(void *unused,u8 *p) {
    u8 *q;
    q=*(u8 * *)&((struct Obj00135 *)p)->f0;
    if(q[0x74]!=1) func_021BC6F8(((struct Obj13774 *)q)->f54);
    func_021B9CBC(p);
}








void func_021BAA5C(void *unused,u8 *p) { func_021B9CBC(p); }








void func_021BAA68(void *unused,u8 *p) { func_021B9CBC(p); }








void func_021BAA74(void *unused,u8 *p) { func_021B9CBC(p); }








void func_021BAA80(void *unused,u8 *p) { func_021B9CBC(p); }








void func_021BAA8C(void *unused,u8 *p) {
    u8 *q;
    u32 x;
    q=*(u8 * *)&((struct Obj06386 *)p)->f0;
    x=func_021BF7FC(*(u8 * *)&((struct Obj06386 *)p)->f4);
    switch(((struct Obj06386 *)p)->f14) {
    case 0:
        func_021BCD80(*(u8 * *)&((struct Obj07998 *)q)->f64);
        func_021BB958((char *)(*(u8 * *)&((struct Obj07998 *)q)->f58));
        func_021BB9C0(*(u8 * *)&((struct Obj07998 *)q)->f58,x!=0);
        ++((struct Obj06386 *)p)->f14;
        break;
    case 1:
        if(func_021BBB0C(*(u8 * *)&((struct Obj07998 *)q)->f58,x!=0)) ++((struct Obj06386 *)p)->f14;
        break;
    case 2: func_021B9CBC(p); break;
    }
}








void func_021BAAF0(int a,u8 *p) { u8 *q; q=*(u8 * *)&((struct Obj00135 *)p)->f0; func_021BFA40(*(u8 * *)&((struct Obj13775 *)q)->f5C,func_021BF7AC(*(u8 * *)&((struct Obj13775 *)q)->f18)); func_021B9CBC(p); }








void func_021BAB0C(void *unused,u8 *p) {
    u8 *q;
    q=*(u8 * *)&((struct Obj10268 *)p)->f0;
    switch(((struct Obj10268 *)p)->f14) {
    case 0:
        func_021BCEE4((char *)(*(u8 * *)&((struct Obj04443 *)q)->f64),2);
        ++((struct Obj10268 *)p)->f14;
        break;
    case 1:
        if(func_021BCF38((char *)(*(u8 * *)&((struct Obj04443 *)q)->f64),2)) {
            if(**(u32 * *)&((struct Obj04443 *)q)->f78==0 && func_021BF724(*(u8 * *)&((struct Obj04443 *)q)->f18)==253 && func_021BF72C(*(u8 * *)&((struct Obj04443 *)q)->f18)==253)
                func_021BCF7C(*(u8 * *)&((struct Obj04443 *)q)->f64,1,1);
            else func_021BCF7C(*(u8 * *)&((struct Obj04443 *)q)->f64,0,0);
            func_021B9CBC(p);
        }
        break;
    }
}








void func_021BAB70(int a,u8 *p) { u8 *q; q=*(u8 * *)&((struct Obj10269 *)p)->f0; switch(((struct Obj10269 *)p)->f14) { case 0: func_021BBB84(*(u8 * *)&((struct Obj10270 *)q)->f58,func_021BF724(*(u8 * *)&((struct Obj10270 *)q)->f18)); (((struct Obj10269 *)p)->f14)++; break; case 1: if(func_021BBC10(*(u8 * *)&((struct Obj10270 *)q)->f58)) func_021B9CBC(p); break; } }








void func_021BABAC(int a,u8 *p) { u8 *q; q=*(u8 * *)&((struct Obj10271 *)p)->f0; switch(((struct Obj10271 *)p)->f14) { case 0: func_021C00AC(*(u8 * *)&((struct Obj10272 *)q)->f5C,func_021BF784(*(u8 * *)&((struct Obj10272 *)q)->f18)); (((struct Obj10271 *)p)->f14)++; break; case 1: if(func_021C00FC(*(u8 * *)&((struct Obj10272 *)q)->f5C)) func_021B9CBC(p); break; } }








/*
 * Byte-correct but witness-blocked (MATCH).
 * +0008 ABS32 func_021BC6DC          -> unresolved: 021BC6DC (arm, from name) has no witness outside 021BABE8..021BABF4; 16 overlays overlap this address (ov016, ov021, ov088, ov091, ov093, ov099, ov110, ov114, ov172, ov208, ov209, ov210, ov211, ov216, ov217, ov223), none resolvable without a region hint on the symbols: line
 *
 * UNBLOCKED: func_021BC6DC is now an EXACT entry in layout/matched/ov110;
 * the call site resolves as matched, verdict promoted to EXACT.
 */
int func_021BABE8(u8 *p) { return func_021BC6DC((void *)(((struct Obj22336 *)p)->f54)); }








int func_021BABF4(u8 *p, int i) { return func_021BC6E0(*(u8 * *)&((struct Obj22337 *)p)->f54, i); }








/*
 * Byte-correct but witness-blocked (MATCH).
 * +0008 ABS32 func_021BC320          -> unresolved: 021BC320 (arm, from name) has no witness outside 021BAC00..021BAC0C; 16 overlays overlap this address (ov016, ov021, ov088, ov091, ov093, ov099, ov110, ov114, ov172, ov208, ov209, ov210, ov211, ov216, ov217, ov223), none resolvable without a region hint on the symbols: line
 *
 * UNBLOCKED: func_021BC320 is now an EXACT entry in layout/matched/ov110;
 * the call site resolves as matched, verdict promoted to EXACT.
 */
void func_021BAC00(u8 *p, u8 *b, u8 n) { func_021BC320(((struct Obj22338 *)p)->f54, b, n); }








int func_021BAC0C(u8 *p) { if((int)func_021BCFF0((char *)(*(u8 * *)&((struct Obj13776 *)p)->f64),(u8)func_021BF71C(*(u8 * *)&((struct Obj13776 *)p)->f18))) return 1; return -1; }








void func_021BAC30(u8 *p,int mode)
{
    func_021BCF18(((struct Obj22339 *)p)->f64,mode);
}









u32 func_021BAC3C(u8 *p) { return ((struct Obj22340 *)p)->f64; }









u32 func_021BAC40(u8 *p) { return ((struct Obj22341 *)p)->f20; }









u32 func_021BAC44(u8 *p) { return ((struct Obj22342 *)p)->f80; }









u32 func_021BAC4C(u8 *p) { return ((struct Obj22343 *)p)->f7C; }








void func_021BAC50(char *p, struct V3 *out, int i)
{
    *out = *(struct V3 *)(p + i * 12 + 0x3c);
}








void func_021BAC64(unsigned p, Triple *out,unsigned i) { *out=*(Triple *)(p+i*12+0x24); }







/*
 * note 2026-10-05 (wD6 lane14): closed by `if (mode == 2) f = 1; else f = z;`:
 * the zero z merges into the u16 flag only in the else arm, so the narrowing
 * is emitted at the join into its own register (r4), as in the original.
 */
struct Obj *func_021BAC78(char *p, u32 *r, short x, short y, u32 a, int mode)
{
    Position pos;
    struct Obj *o;
    u16 f;
    int z;
    int s;
    pos.x = x;
    pos.y = y;
    pos.a = a;
    z = 0;
    pos.b = z;
    pos.z = z;
    if (mode == 2)
        f = 1;
    else
        f = z;
    s = OS_DisableInterrupts();
    o = func_0204B294(*(void **)(p + 0x20), r[1], r[0], r[2], &pos, f, 42);
    OS_RestoreInterrupts(s);
    if (o) {
        func_0204B92C(o, 1);
        func_0204B954((struct Actor *)o, 1 << 12);
    }
    return o;
}







int func_021BACDC(u8 *p,int unused,unsigned n) { Vec2 pos; if(func_021BFD94(*(u8 * *)&((struct Obj22344 *)p)->f5C,(struct Vec2 *)(&pos))==0) return 3; if(n<(unsigned)pos.y) return 1; if(n>(unsigned)pos.y) return 2; if(n==(unsigned)pos.y) return 0; return 3; }







void func_021BAD14(u8 *p, u32 v) { func_021BFE24((u8 *)(((struct Obj22345 *)p)->f5C), v); }







unsigned func_021BAD20(u8 *p, unsigned n) { return func_021BFE60(*(u8 * *)&((struct Obj22346 *)p)->f5C, n); }







void func_021BAD2C(u8 *p,int v) { int id,x; if(v) { id=29; x=96; } else { id=28; x=0; } func_020499D4(((struct Obj10273 *)p)->f8C,id,3,0,x,0,0,42); ((struct Obj10273 *)p)->f84=1; ((struct Obj10273 *)p)->f88=v; }







void func_021BAD68(u8 *p,int index) {
    Table table;
    void *bank,*str;
    u8 *q;
    table=d_021C3744;
    func_02043B5C(func_02045770((struct Descriptor *)((struct Obj22347 *)(*(u8 * *)&((struct Obj07999 *)p)->f0))->f6C),7);
    bank=func_02045B38(0,2,146,42);
    str=func_02045EC0(bank,table.values[index]);
    q=*(u8 * *)&((struct Obj07999 *)p)->f0;
    func_0201C724(((struct Obj22348 *)(*(u8 * *)&((struct Obj07999 *)p)->f0))->f7C,(u32)func_02045770((struct Descriptor *)((struct Obj13777 *)q)->f6C),2,4,(u32)str,((struct Obj13777 *)q)->f80,0x39e7);
    ((struct Obj22349 *)(*(u8 * *)&((struct Obj07999 *)p)->f0))->f70=1;
    func_02045808(str);
    func_02045C04(bank);
}







void func_021BADE8(u8 *p) { struct Descriptor *q; if(((struct Obj03239 *)p)->f70!=0 && func_0201C6C4((struct PrintSys *)(*(unsigned *)&((struct Obj03239 *)p)->f7C),(void *)((unsigned)func_02045770(*(struct Descriptor * *)&((struct Obj03239 *)p)->f6C)))==0) { q=*(struct Descriptor * *)&((struct Obj03239 *)p)->f6C; func_02045334(q);func_02045374((struct Cfg *)q);func_02041B6C(func_02045730(q));((struct Obj03239 *)p)->f70=0; } }







/*
 * extent: trailing two-byte zero padding
 */
void func_021BAE24(u8 *p, u8 *a1, void *a2) {
    if(**(u32 * *)&((struct Obj02459 *)p)->f78==1) {
        func_021BC704(*(u8 * *)&((struct Obj02459 *)p)->f54,0);
        func_021BCF7C(*(u8 * *)&((struct Obj02459 *)p)->f64,(u8)func_021BF71C(*(u8 * *)&((struct Obj02459 *)p)->f18),0);
    } else if(p[0x74]==1) {
        func_021BC704(*(u8 * *)&((struct Obj02459 *)p)->f54,0);
        func_021BCF7C(*(u8 * *)&((struct Obj02459 *)p)->f64,(u8)func_021BF71C(*(u8 * *)&((struct Obj02459 *)p)->f18),1);
    } else {
        func_021BC704(*(u8 * *)&((struct Obj02459 *)p)->f54,1);
        func_021BCF7C(*(u8 * *)&((struct Obj02459 *)p)->f64,(u8)func_021BF71C(*(u8 * *)&((struct Obj02459 *)p)->f18),0);
    }
}







void func_021BAE94(u8 *p, u8 *q, void *a2) { func_021BB658(*(u8 * *)&((struct Obj06387 *)p)->f58,1); if(**(int * *)&((struct Obj06387 *)p)->f78==1) { if(func_021BF6DC(q)==1) func_021BCF7C(*(u8 * *)&((struct Obj06387 *)p)->f64,0,0); } else func_021BB6A0(*(u8 * *)&((struct Obj06387 *)p)->f58,func_021BF724(*(u8 * *)&((struct Obj06387 *)p)->f18)); }







void func_021BAED0(u8 *p, u8 *a1, void *a2) { func_021BFC20((u8 *)(((struct Obj22352 *)p)->f5C), 1); }







u8 *func_021BAEDC(void *p,void *q,u16 heap) {
    int i;
    u8 *result;
    result=func_02030734(heap,0xaf4,1,d_021C3C34,137);
    ((struct Obj03750 *)result)->f0=p;
    ((struct Obj03750 *)result)->f4=q;
    ((struct Obj03750 *)result)->f8=heap;
    func_021BAFE4((u32)result);
    for(i=0;i<27;i++) *(void **)(result+12+i*4)=func_02045B38(1,2,d_021C3770[i],heap);
    ((struct Obj03750 *)result)->f78=func_021B6C74((u32 *)(result+12),27,((struct Obj03750 *)result)->f8);
    ((struct Obj03750 *)result)->fAD0=func_020457B0(27,heap);
    return result;
}







void func_021BAF4C(unsigned p) { int i; func_02045808(((struct Obj13778 *)p)->fAD0);func_021B6CCC(*(int * *)&((struct Obj13778 *)p)->f78);for(i=0;i<27;i++)func_02045C04(*(void **)(p+i*4+0xc));func_020307B0((void *)p); }






void func_021BAF7C(unsigned p,int v) { int n; *(u16 *)(p+((struct Obj10274 *)p)->fAF0*2+0xad4)=v; n=((struct Obj10274 *)p)->fAF0+1; if(n>12) n=12; else if(n<0) n=0; ((struct Obj10274 *)p)->fAF0=n; }






int func_021BAFAC(u32 p) { if (((struct Obj08000 *)p)->fAF0==0) return 0; if (((struct Obj08000 *)p)->fAEC==255) --((struct Obj08000 *)p)->fAF0; *(u16 *)(p+((struct Obj08000 *)p)->fAF0*2+0xad4)=255; return 1; }







/*
 * Byte accessor: p[0xaf0].
 */
u8 func_021BAFDC(u8 *p)
{
    return p[0xaf0];
}




void func_021BAFE4(u32 p) { int i; for(i=0;i<13;i++) *(u16 *)(p+i*2+0xad4)=255; ((struct Obj03750 *)p)->fAF0=0; ((struct Obj03750 *)p)->fAF1=0; }



/*
 * lever: struct member keeps the far offset in-loop; array store uses i++.
 */
void func_021BB00C(Input *p, void *q) {
    u16 a[14];
    int i;
    for(i=0;i<13;) {
        u16 x;
        x=p->values[i];
        if(x==255) { a[i]=func_02045A98(); break; }
        a[i++]=func_021BB214(x);
    }
    a[13]=func_02045A98();
    func_02045924(q,a);
}



/*
 * evidence: ov110 loads ov067 at 021C0134; 021BAEDC creates +78 via ov067 021B6C74.
 * lever: id/k clear order and value-before-j declaration; pooled table has alignment-only hint.
 */
int func_021BB054(u8 *p)
{
    u16 special[265];
    u16 normal[265];
    u32_021BB054 n,id;
    unsigned i,k,found;
    u32_021BB054 value;
    unsigned j;
    id=((struct Obj01391 *)p)->fAD4;
    if(id>=27) {
        p[0xaf1]=0;
        return 0;
    }
    func_0204581C(((struct Obj01391 *)p)->fAD0);
    func_021BB00C((Input *)p, ((struct Obj01391 *)p)->fAD0);
    if(id==26) {
        n=func_02045F50(*(void **)(p+0xc+id*4));
        k=0;
        __builtin__clear(special,sizeof(special));
        for(i=0;i<n;i++) {
            value=func_021B99F0(*(int *)&((struct Obj01391 *)p)->f4,id,i);
            found=0;
            for(j=0;j<10;j++) {
                if(value==d_021C375C[j]) { found=1; break; }
            }
            if(!found) {
                *(u32_021BB054 *)(p+0x7c+k*8)=id;
                *(u32_021BB054 *)(p+0x80+k*8)=i;
                special[k]=value;
                k++;
            }
        }
        special[k]=func_021B9A48(((struct Obj01391 *)p)->f4);
        p[0xaf1]=func_021B99D8(((struct Obj01391 *)p)->f4,(u32_021BB054)special,(u32_021BB054)(p+0x8bc));
        if(p[0xaf1]) return 1;
        return 0;
    } else {
        __builtin__clear(normal,sizeof(normal));
        n=func_021B6CE0(((struct Obj01391 *)p)->f78,id,0,*(u32_021BB054 *)&((struct Obj01391 *)p)->fAD0,p+0x7c,264);
        for(i=0;i<n;i++) {
            normal[i]=func_021B99F0(*(int *)&((struct Obj01391 *)p)->f4,id,*(int *)(p+0x80+i*8));
        }
        normal[n]=func_021B9A48(((struct Obj01391 *)p)->f4);
        p[0xaf1]=func_021B99D8(((struct Obj01391 *)p)->f4,(u32_021BB054)normal,(u32_021BB054)(p+0x8bc));
        if(p[0xaf1]) return 1;
        return 0;
    }
}





u8 func_021BB1C0(u8 *p) { return ((struct Obj22355 *)p)->fAF1; }




void func_021BB1CC(u8 *p, u8 i, int c) { func_021B9A3C(*(u8 * *)&((struct Obj22356 *)p)->f4,*(u16 *)(p+i*2+0x8bc),c); }




u16 func_021BB1E4(u32_021BB1C0 p,u32_021BB1C0 i) { return *(u16 *)(p+i*2+0x8bc); }





int func_021BB1F4(void) { return 0x1b; }




void func_021BB1F8(u32_021BB1C0 i, void *dst)
{
    func_02045994(dst, (const u16 *)(d_021C37A8 + i * 10), 2);
}




u16 func_021BB214(u32_021BB1C0 i) { return *(const u16 *)(d_021C37A8+i*10); }
