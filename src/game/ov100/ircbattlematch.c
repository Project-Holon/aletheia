/*
 * file:     ircbattlematch.c
 * unit:     yes
 * function: func_021B95A0, func_021B95A8, func_021B95AC, func_021B95B8, func_021B95C0, func_021B95D8, func_021B95F0, func_021B967C, func_021B96B8, func_021B96EC, func_021B974C, func_021B97BC, func_021B9800, func_021B9824, func_021B9848, func_021B9888, func_021B98A8, func_021B98F4, func_021B9910, func_021B9950, func_021B99A8, func_021B99D4, func_021B99F4, func_021B9A1C, func_021B9A54, func_021B9AB4, func_021B9AD8, func_021B9B7C, func_021B9BE4, func_021B9C50, func_021B9CC4, func_021B9D6C, func_021B9DB8, func_021B9E14, func_021B9E48, func_021B9EA4, func_021B9EF8, func_021B9F80, func_021B9FBC, func_021B9FF4, func_021BA028, func_021BA1C8, func_021BA1D0, func_021BA290, func_021BA3A4, func_021BA454, func_021BA530, func_021BA5F4, func_021BA624, func_021BA640, func_021BA64C, func_021BA668, func_021BA780, func_021BAA9C, func_021BAAEC, func_021BAB08, func_021BAC08, func_021BAC80, func_021BACC8, func_021BAD1C, func_021BAD78, func_021BADB0, func_021BADFC, func_021BAE14, func_021BAE5C, func_021BAEB4, func_021BAEE0, func_021BAF4C, func_021BAFA0, func_021BAFCC, func_021BAFFC, func_021BB058, func_021BB0C4, func_021BB10C, func_021BB154, func_021BB180, func_021BB270, func_021BB414, func_021BB498
 * address:  0x021B95A0
 * region:   ov100
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021BB800  0x021BB800  data  a4
 *   GFL_NET_IRC_WIRELESS_Exit 0x0203D0D0 arm
 *   func_0203CEAC 0x0203CEAC arm
 *   func_020221A4 0x020221A4 thumb
 *   func_02021518  0x02021518  thumb
 *   func_0202155C  0x0202155C  thumb
 *   func_020216D4  0x020216D4  thumb
 *   func_02021FD8  0x02021FD8  thumb
 *   func_02021730  0x02021730  thumb
 *   func_020215A0  0x020215A0  thumb
 *   func_02021540  0x02021540  thumb
 *   func_020862F0  0x020862F0  arm
 *   func_0207E5D0  0x0207E5D0  arm
 *   func_0207E468  0x0207E468  arm
 *   func_02082D44 0x02082D44 arm
 *   func_0202208C 0x0202208C thumb
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   CLACT_SetActorAffineMode 0x0204B570 arm
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 *   func_02080D24 0x02080D24 arm
 *   func_020399A8 0x020399A8 arm
 *   func_02012950 0x02012950 thumb
 *   func_02008494 0x02008494 thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200ED48 0x0200ED48 thumb
 *   func_02008530 0x02008530 thumb
 *   func_0200ED54 0x0200ED54 thumb
 *   func_02039338 0x02039338 arm
 *   func_0200F5EC 0x0200F5EC thumb
 *   func_0203D378 0x0203D378 arm
 *   func_0203EFC8 0x0203EFC8 arm
 *   func_02035C60 0x02035C60 arm
 *   func_02039CB4 0x02039CB4 arm
 *   GFL_NET_SetAutoExit 0x0203D7B0 arm
 *   func_0203D7BC 0x0203D7BC arm
 *   func_020061E4 0x020061E4 thumb
 *   func_02039C68 0x02039C68 arm
 *   d_021BB664 0x021BB664 data a4
 *   d_021BB678 0x021BB678 data a4
 *   func_0201AA50 0x0201AA50 thumb
 *   POKE_TOOL_HealParty 0x0201BA34 thumb
 *   POKE_REGULATION_GetDataSize 0x0201A918 thumb
 *   func_0203D3F8 0x0203D3F8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_02087C6C 0x02087C6C arm
 *   func_0201283C 0x0201283C thumb
 *   func_02009CA8 0x02009CA8 thumb
 *   func_02027858 0x02027858 thumb
 *   func_02008468 0x02008468 thumb
 *   func_02012944 0x02012944 thumb
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_02041B6C 0x02041B6C arm
 *   d_021BB65C 0x021BB65C data a4
 *   func_02049B40 0x02049B40 arm
 *   func_0201DD68 0x0201DD68 thumb
 *   func_0203A574 0x0203A574 arm
 *   d_021BB6C0 0x021BB6C0 data a4
 *   GFL_NET_IRC_WIRELESS_GetMacAddress 0x0203D0B8 arm
 *   func_020433E0 0x020433E0 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_02043534 0x02043534 arm
 *   func_020435F4 0x020435F4 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02041300 0x02041300 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02040C14 0x02040C14 arm
 *   func_0204A648 0x0204A648 arm
 *   d_021BB6F0 0x021BB6F0 data a4
 *   d_021BB6B0 0x021BB6B0 data a4
 *   d_021BB720 0x021BB720 data a4
 *   d_021BB740 0x021BB740 data a4
 *   d_021BB760 0x021BB760 data a4
 *   d_021BB780 0x021BB780 data a4
 *   d_021BB7A0 0x021BB7A0 data a4
 *   d_021BB7C0 0x021BB7C0 data a4
 *   func_020457B0 0x020457B0 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02027778 0x02027778 thumb
 *   func_02027CD8 0x02027CD8 thumb
 *   func_02045808 0x02045808 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045374 0x02045374 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02009A34 0x02009A34 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   GFL_NET_IRC_WIRELESS_GetRetryCount 0x0203D170 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_0204B3B4 0x0204B3B4 arm
 *   d_021BB694 0x021BB694 data a4
 *   d_021BB690 0x021BB690 data a4
 *   d_021BB670 0x021BB670 data a4
 *   d_021BB680 0x021BB680 data a4
 *   d_021BB684 0x021BB684 data a4
 *   d_021BB67C 0x021BB67C data a4
 *   d_021BB66C 0x021BB66C data a4
 *   d_021BB6A0 0x021BB6A0 data a4
 *   d_021BB698 0x021BB698 data a4
 *   func_0201EC74 0x0201EC74 thumb
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   func_0201F5DC 0x0201F5DC thumb
 *   func_0204E720 0x0204E720 arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_02027F60 0x02027F60 thumb
 *   func_02049F78 0x02049F78 arm
 *   func_020307B0 0x020307B0 arm
 *   d_020A1448 0x020A1448 data a4
 *   func_0204E804 0x0204E804 arm
 *   d_021BB83C 0x021BB83C data a4
 *   func_0203CBAC 0x0203CBAC arm
 *   GFL_NET_IRC_WIRELESS_SetSessionParam 0x0203D0C4 arm
 *   GFL_NET_IRC_WIRELESS_SetRetryRequest 0x0203D164 arm
 *   GFL_NET_SetGameKindOverride 0x0203D0AC arm
 *   func_02040DA8 0x02040DA8 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_020403F4 0x020403F4 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_02040588 0x02040588 arm
 *   func_02027FD8 0x02027FD8 thumb
 *   func_0203CD98 0x0203CD98 arm
 *   func_021799C0 0x021799C0 thumb ov015
 *   GFL_NET_StartChangeoverEx 0x0203D060 arm
 *   GFL_NET_IRC_WIRELESS_Step 0x0203D158 arm
 *   d_021BB674 0x021BB674 data a4
 *   func_02051C6C 0x02051C6C arm
 *   d_021BB688 0x021BB688 data a4
 *   d_021BB668 0x021BB668 data a4
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   func_0204B878 0x0204B878 arm
 *   d_021BB660 0x021BB660 data a4
 *   func_0204BA00 0x0204BA00 arm
 *   d_021BB69C 0x021BB69C data a4
 *   d_021BB68C 0x021BB68C data a4
 *   GFL_NET_HANDLE_GetNegotiationState 0x020399DC arm
 *   d_021BB804 0x021BB804 data a4
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02030734  0x02030734  arm
 *   func_0207D63C  0x0207D63C  arm
 *   func_0207E3D0 0x0207E3D0 arm
 *   func_02027974 0x02027974 thumb
 *   func_02028178 0x02028178 thumb
 *   func_02040618 0x02040618 arm
 *   func_0204A600 0x0204A600 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0200FB38 0x0200FB38 thumb
 *   func_0202223C 0x0202223C thumb
 */
#include "../../matched/include/Obj22063.h"
#include "../../matched/include/Obj22064.h"
#include "../../matched/include/Obj13704.h"
#include "../../matched/include/Obj13705.h"
#include "../../matched/include/Obj22065.h"
#include "../../matched/include/Obj04419.h"
#include "../../matched/include/Obj06361.h"
#include "../../matched/include/Obj13706.h"
#include "../../matched/include/Obj03737.h"
#include "../../matched/include/Obj13707.h"
#include "../../matched/include/Obj22069.h"
#include "../../matched/include/Obj10215.h"
#include "../../matched/include/Obj22070.h"
#include "../../matched/include/Obj22071.h"
#include "../../matched/include/Obj22072.h"
#include "../../matched/include/Obj22073.h"
#include "../../matched/include/Obj22074.h"
#include "../../matched/include/Obj00060.h"
#include "../../matched/include/Obj13708.h"
#include "../../matched/include/Obj22075.h"
#include "../../matched/include/Obj22076.h"
#include "../../matched/include/Obj22077.h"
#include "../../matched/include/Obj03738.h"
#include "../../matched/include/Obj22079.h"
#include "../../matched/include/Obj13709.h"
#include "../../matched/include/Obj07961.h"
#include "../../matched/include/Obj05266.h"
#include "../../matched/include/Obj01246.h"
#include "../../matched/include/Obj13711.h"
#include "../../matched/include/Obj00178.h"
#include "../../matched/include/Obj22083.h"
#include "../../matched/include/Obj10216.h"
#include "../../matched/include/Obj05267.h"
#include "../../matched/include/Obj22085.h"
#include "../../matched/include/Obj10217.h"
#include "../../matched/include/Obj07962.h"
#include "../../matched/include/Obj07963.h"
#include "../../matched/include/Obj07964.h"
#include "../../matched/include/Obj10218.h"
#include "../../matched/include/Obj07965.h"
#include "../../matched/include/Obj22086.h"
#include "../../matched/include/Obj22087.h"
#include "../../matched/include/Obj07966.h"
#include "../../matched/include/Obj10219.h"
#include "../../matched/include/Obj10220.h"
#include "../../matched/include/Obj02449.h"

struct Chan02021FD8;
struct PalAnmSlot;
struct Obj;
struct Actor;
struct PtS;
struct Vec2;
struct Entry;
struct Big;
struct L0200ED54;
struct Rec44;
struct Sub0200852CObj;
struct Sub24;
struct Link;
struct BigObj;
struct TaskMenu;
struct DispConfig;
struct DispVram;
struct MsgBank;
struct TaskMenuTmpl;
struct U16Vec;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct Sub020097BCObj;
struct WordSet;
struct Bank;
struct GfFont;
struct R;
struct Rec;
struct TaskMenuState;
struct Cmd;
struct Obj0203159C;
struct PrintSys;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16_021B95B8;

typedef signed char s8;

typedef unsigned int u32;

typedef int s32_021B95B8;

typedef signed int     s32_021B96EC;

typedef signed short s16_021B974C;

struct Point_021B974C { s16_021B974C x,y; u16 z; u8 id,mode; };

typedef signed short s16_021B97BC;

struct Point_021B97BC { s16_021B97BC x,y; };

typedef signed short s16_021B9800;

struct Point_021B9800 { s16_021B9800 x,y; };

typedef signed int     s32_021B9950;

struct Word { int x; };

struct BgTemplate { unsigned int words[8]; };

struct Template { int heap; u8 count,pad[3]; int ptr,flag; u8 x,y,z,w; };

typedef signed short   s16_021BA3A4;

typedef signed short   s16_021BA454;

typedef signed short   s16_021BA530;

typedef short s16_021BA640;

typedef int s32_021BA640;

struct Req {
    u32 first[24];
    u8 a,b,c,d,e,mode,f,kind;
    u32 word68;
    u16 value,limit;
};

struct Task { u16 state,pad; int context; void (*callback)(int); };

extern void GFL_NET_IRC_WIRELESS_Exit(void);
extern int func_0203CEAC(int a0);
extern u32 func_020221A4(void);
extern void *func_02021518(u32 heap);
extern void func_0202155C(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void func_02021FD8(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
extern int func_02021730(char *p, int i);
extern void func_020862F0(int, int);
extern void func_0207E5D0(int, int, int);
extern void func_0207E468(int, int, int);
extern void func_020215A0(struct PalAnmSlot *slots, u32 idx);
extern u32 func_02021540(void *a0);
extern void func_02082D44(const void *,void *,u32);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void *func_020490F4(u32 id, u32 heap);
extern s32_021B96EC func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32_021B96EC func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32_021B96EC func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B92C(struct Obj *p, unsigned int v);
extern void func_0204B3DC(struct Obj *,unsigned int);
extern void CLACT_SetActorAffineMode(struct Actor *actor, u32 value);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern unsigned char func_02080D24(unsigned x);
extern struct Entry *func_020399A8(void);
extern struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
extern void func_02008494(void *src, void *dst);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200ED48(void *p);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void func_0200ED54(struct L0200ED54 *l, u32 val);
extern u16 func_02039338(void);
extern int func_0200F5EC(void *a0, void *a1, void *a2, void *a3);
extern unsigned func_0203D378(void);
extern s32_021B9950 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern int func_02035C60(void);
extern unsigned int func_02039CB4(struct Link *,unsigned int,unsigned int);
extern void GFL_NET_SetAutoExit(u8 a0);
extern void func_0203D7BC(u8 a0);
extern void func_020061E4(u32 a);
extern void func_02039C68(struct Link *,unsigned int,unsigned int);
extern u32 func_0201AA50(void *p);
extern void POKE_TOOL_HealParty(void *party);
extern int POKE_REGULATION_GetDataSize(void);
extern u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern void func_02087C6C(void *);
extern u32 func_0201283C(const struct BigObj *p);
extern void func_02009CA8(void *account, void *out);
extern void func_02027858(struct TaskMenu *m);
extern int func_02008468(void);
extern u8 *func_02012944(void *p);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern void func_02041B6C(u32 bit);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0201DD68(void);
extern void func_0203A574(unsigned,unsigned,unsigned,unsigned);
extern void GFL_NET_IRC_WIRELESS_GetMacAddress(void *,int);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_02043534(u32 planes);
extern void func_020435F4(u32 planes);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02041300(int,int,int,int,u8,u8,u8);
extern void func_020409B4(u32 index);
extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
extern void func_0204A648(void);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
extern int func_02027CD8(int a0, int a1);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02045374(struct Cfg *cfg);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201C7A4(void *x, s16_021BA3A4 y, s16_021BA3A4 z, void *s, void *w);
extern void func_02045334(struct Descriptor *);
extern u32 func_02009A34(struct Sub020097BCObj *obj);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern int GFL_NET_IRC_WIRELESS_GetRetryCount(void);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_0203F8F4(u16),func_02045088(u16);
extern void func_0201DD60(void);
extern void func_0203F9B4(void);
extern void func_020450C8(void);
extern void func_0204B3B4(struct Obj *);
extern struct WordSet *func_0201EC74(u32 n, u32 size, u16 heap);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void *func_0201F5DC(void *a0, u32 a1, u32 a2, u32 a3);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern int func_020056A0(u32,u32,u32);
extern u32 func_0201C440(void *p);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern void func_0204E720(u32,int,int,int);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern u32 func_020307B0(void *p);
extern int func_0204E804(void);
extern void func_0203CBAC(struct Req *,u32,u32);
extern void GFL_NET_IRC_WIRELESS_SetSessionParam(u32);
extern void GFL_NET_IRC_WIRELESS_SetRetryRequest(int);
extern void GFL_NET_SetGameKindOverride(int);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_020403F4(u32 i);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern void func_02040588(unsigned char which, unsigned char enable);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern int func_0203CD98(void);
extern void func_021799C0(int a);
extern void GFL_NET_StartChangeoverEx(u32 a, u32 b, u32 c);
extern int GFL_NET_IRC_WIRELESS_Step(void);
extern void func_02051C6C(void *p);
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204BA00(struct Actor *a, const struct Cmd *cmd);
extern int GFL_NET_HANDLE_GetNegotiationState(struct Entry *);
extern void func_0203064C(unsigned int, unsigned int, unsigned int);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(int, int, int);
extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern void func_0207D63C(int, int, int, int, int);
extern void func_0207E3D0(void *, int, int);
extern void func_02027974(u8 *);
extern void func_02028178(u8 *);
extern void func_02040618(u32, u32, u32);
extern void func_0204A600(void);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern u32 func_0200FB24(void);
extern void func_0200FB38(void);
extern void func_0202223C(u32, u32);
char *func_021B95A0(void);
int func_021B95A8(void);
int func_021B95AC(int a, int b);
void func_021B95B8(u8 *p, u32 v);
int func_021B95C0(u8 *p);
void func_021B95D8(u8 *p);
int func_021B95F0(int a, int b, int c);
void func_021B967C(int a,int b);
void func_021B96B8(u8 *a);
void func_021B96EC(char *p);
void func_021B974C(int a,int b,int c,int d,int e);
void func_021B97BC(int a,int b,int c,int d);
void func_021B9800(int a,int b,int c,int d);
void func_021B9824(int a,int b);
void func_021B9848(int a);
void func_021B9888(unsigned a,int b,int *c,unsigned d,void *e);
void func_021B98A8(int a,int b,int c,int d,int e);
void func_021B98F0(void);
int func_021B98F4(int a,int b);
void func_021B9910(int a,int b,int c,int d,int e);
void func_021B9950(int a,int b,void *c,int d,int e);
void func_021B99A8(int a,int b,void *c,unsigned d,void *e);
void func_021B99D4(unsigned char *a);
void func_021B99F4(unsigned a);
void func_021B9A1C(unsigned a);
void func_021B9A54(int a);
int func_021B9AB4(unsigned a);
void func_021B9AD8(int a);
void func_021B9B7C(int a);
void func_021B9BE4(int a);
void func_021B9C50(int a);
void func_021B9CC4(int a);
void func_021B9D6C(int a);
void func_021B9DB8(int a);
void func_021B9E14(unsigned a);
void func_021B9E48(int a);
void func_021B9EA4(int a);
void func_021B9EF8(u8 *a);
void func_021B9F80(unsigned a);
void func_021B9FBC(int a);
void func_021B9FF4(int a,int b);
void func_021BA028(char *a0);
void func_021BA1C8(void);
void func_021BA1D0(int a);
void func_021BA290(int a,int flag);
void func_021BA3A4(struct Word *p,int a);
void func_021BA454(int text,int a);
void func_021BA530(int b,int a);
void func_021BA5F4(unsigned a);
void func_021BA624(unsigned a);
void func_021BA640(int a0);
void func_021BA64C(unsigned a,unsigned b);
void func_021BA668(int a);
void func_021BA780(char *p);
void func_021BAA9C(int a);
int func_021BAAEC(int a,int b);
void func_021BAB08(int p);
void func_021BAC08(int a);
void func_021BAC80(int a);
void func_021BACC8(int a);
void func_021BAD1C(int a);
void func_021BAD78(unsigned a);
void func_021BADB0(int a);
void func_021BADFC(int p);
void func_021BAE14(int a);
void func_021BAE5C(int a);
void func_021BAEB4(int p);
void func_021BAEE0(int a);
void func_021BAF4C(int a);
void func_021BAFA0(int p);
void func_021BAFCC(int p);
void func_021BAFFC(int a);
void func_021BB058(int a);
void func_021BB0C4(int a);
void func_021BB10C(int a);
void func_021BB154(int p);
void func_021BB180(int p);
void func_021BB270(int p);
int func_021BB414(struct Obj0203159C *a, int b, int c);
u32 func_021BB498(u32 a, u32 b, u32 c, u8 *p);
extern char d_021BB800[];
extern const struct Word d_021BB664,d_021BB678;
extern const struct Word d_021BB65C;
extern const unsigned d_021BB6C0[];
extern const unsigned int d_021BB6F0[],d_021BB6B0[];
extern const struct BgTemplate d_021BB720,d_021BB740,d_021BB760,d_021BB780,d_021BB7A0,d_021BB7C0;
extern const struct Word d_021BB694,d_021BB690,d_021BB670,d_021BB680,d_021BB684,d_021BB67C,d_021BB66C,d_021BB6A0,d_021BB698;
extern const u32 d_020A1448[],d_021BB6F0[];
extern const struct Req d_021BB83C;
extern const struct Word d_021BB674;
extern const struct Word d_021BB688;
extern const struct Word d_021BB668;
extern const struct Word d_021BB660;
extern const struct Word d_021BB69C,d_021BB68C;
extern struct Word d_021BB804[];


char *func_021B95A0(void)
{
    return d_021BB800;
}

/*
 * Unlabelled leaf at the start of ov100 (the listing prints it as .word
 * data); referenced as 0x021B95A9 from the table word at 021BB858.
 */
int func_021B95A8(void)
{
    return 4;
}

int func_021B95AC(int a, int b)
{
    if (a == b)
        return 1;
    return 0;
}


void func_021B95B8(u8 *p, u32 v) { ((struct Obj22063 *)p)->f248 = v; }

int func_021B95C0(u8 *p) { *(int *)(((struct Obj22064 *)p)->f244+0x1c)=12; GFL_NET_IRC_WIRELESS_Exit(); return func_0203CEAC(0); }

/*
 * Extent remainder: two-byte alignment padding.
 */
void func_021B95D8(u8 *p) { if(func_020221A4()) func_021B95B8(p,0); }


/*
 *          (site +0084) have no witness outside this function's range.
 *          Both are unlabelled Thumb leaves in the ARM9 image, so neither
 *          `label` nor `sole-ref/code` can attest them; each call is their
 *          only referrer image-wide.  Every other byte is correct.
 */
int func_021B95F0(int a, int b, int c)
{
    int r4;
    int t;
    int r7;

    r4 = (int)func_02021518(((struct Obj13704 *)a)->f278);
    func_0202155C((struct PalAnmSlot *)r4, b, 0x200, ((struct Obj13704 *)a)->f278);
    t = c << 5;
    func_020216D4((struct PalAnmSlot *)r4, b, 0, t);
    func_02021FD8((struct Chan02021FD8 *)r4, b, 0, (u16)(c << 4), 6, 0);
    r7 = func_02021730((char *)r4, b);
    func_020862F0(r7, t);
    if (b != 1) {
        if (b == 3)
            func_0207E5D0(r7, 0, t);
    } else {
        func_0207E468(r7, 0, t);
    }
    func_020215A0((struct PalAnmSlot *)r4, b);
    return func_02021540((void *)r4);
}

void func_021B967C(int a,int b){if(b){func_02082D44((void *)0x05000400,((struct Obj13705 *)a)->fCB4,0x200);func_021B95F0(a,1,9);}else{func_0207E468(*(int *)&((struct Obj13705 *)a)->fCB4,0,0x120);}}

void func_021B96B8(u8 *a){func_0202208C(0,0,0,0,6,1,((struct Obj22065 *)a)->f278);func_021B95B8(a,(u32)func_021B95D8);}

/*
 * extent: 94 bytes code followed by two zero alignment bytes before 021B974C.
 */
void func_021B96EC(char *p)
{
    void *owner;
    owner = func_020490F4(28, ((struct Obj04419 *)p)->f278);
    ((struct Obj04419 *)p)->f2BC = func_0204A6C8((void *)((u32)owner), 7, 0, 0, ((struct Obj04419 *)p)->f278);
    ((struct Obj04419 *)p)->f2B8 = func_0204AC18((void *)((u32)owner), 3, 0, 0, 0, 3, ((struct Obj04419 *)p)->f278);
    ((struct Obj04419 *)p)->f2C0 = func_0204AF28((void *)((u32)owner), 9, 15, ((struct Obj04419 *)p)->f278);
    func_02049238(owner);
}

void func_021B974C(int a,int b,int c,int d,int e)
{
 struct Point_021B974C p;
 if(*(int *)(a+0x2c8+d*4)==0) {
  p.x=b; p.y=c; p.z=e; p.id=d; p.mode=2;
  *(int *)(a+0x2c8+d*4)=(int)func_0204B294((void *)((struct Obj06361 *)a)->f2B4,((struct Obj06361 *)a)->f2BC,((struct Obj06361 *)a)->f2B8,((struct Obj06361 *)a)->f2C0,&p,0,((struct Obj06361 *)a)->f278);
  func_0204B92C((struct Obj *)*(int *)(a+0x2c8+d*4),1);
  func_0204B3DC((struct Obj *)*(int *)(a+0x2c8+d*4),1);
  CLACT_SetActorAffineMode((struct Actor *)(*(int *)(a+0x2c8+d*4)),2);
 }
}

void func_021B97BC(int a,int b,int c,int d)
{
 struct Point_021B97BC p;
 if(*(int *)(a+0x2c8+d*4) != 0) {
  func_0204B454((struct Actor *)*(int *)(a+0x2c8+d*4),(struct PtS *)&p,0);
  p.x += (s16_021B97BC)b;
  p.y += (s16_021B97BC)c;
  func_0204B404((struct Obj *)(*(int *)(a+0x2c8+d*4)),(const struct Vec2 *)(&p),0);
 }
}

void func_021B9800(int a,int b,int c,int d) { struct Point_021B9800 p; int obj; obj=*(int *)(a+0x2c8+d*4); if(obj){p.x=b;p.y=c;func_0204B404((struct Obj *)obj,(const struct Vec2 *)(&p),0);} }

void func_021B9824(int a,int b)
{
 if(func_02080D24(((struct Obj13706 *)a)->f2E8 |= 1 << b)>=2) ((struct Obj13706 *)a)->f2EC=1;
}

void func_021B9848(int a)
{
 if(((struct Obj03737 *)a)->f24C!=5) {
  ((struct Obj03737 *)a)->fC80=1; ((struct Obj03737 *)a)->fC84=1; ((struct Obj03737 *)a)->fCA0=1;
 } else {
  if(((struct Obj03737 *)a)->fC7C!=0 && ((struct Obj03737 *)a)->fC98!=0) {
   ((struct Obj03737 *)a)->fC80=1; ((struct Obj03737 *)a)->fC84=1;
  }
 }
}

void func_021B9888(unsigned a,int b,int *c,unsigned d,void *e)
{
 if(e==func_020399A8()) *(int *)(d+a*4+0x250)=*c;
}

void func_021B98A8(int a,int b,int c,int d,int e)
{
 int p;
 int q;
 if(e==(int)func_020399A8()) {
  p=(int)func_02012950((struct Sub24 *)(**(int * *)&((struct Obj13707 *)d)->f244),a);
  func_02008494((void *)c,(void *)p);
  q=(int)func_0200ED48(func_02012EBC((struct Big *)(**(int * *)&((struct Obj13707 *)d)->f244)));
 func_0200ED54((struct L0200ED54 *)q,func_02008530((const struct Sub0200852CObj *)p));
 }
}

void func_021B98F0(void) {}

int func_021B98F4(int a,int b)
{
 if(a>=0 && a<4) return *(int *)(((struct Obj22069 *)b)->f244+a*4+8);
 return 0;
}

void func_021B9910(int a,int b,int c,int d,int e)
{
 int p = ((struct Obj10215 *)d)->f244;
 int q = ((struct Obj22070 *)p)->f0;
 if (e == (int)func_020399A8()) {
  if (a != func_02039338()) {
   int r = (int)func_02012950((struct Sub24 *)q,a);
   ((struct Obj10215 *)d)->fC90 = func_0200F5EC((void *)q,(void *)r,(void *)c,(void *)(((struct Obj10215 *)d)->f278));
  }
 }
}

void func_021B9950(int a,int b,void *c,int d,int e)
{
 u8 *p;
 int i;
 if(e == (int)func_020399A8()) {
  if(func_0203D378() != 0) {
   i=0;
   p = (u8 *)(d+0x260);
   for(;i<4;i++) {
    if(func_0203EFC8(p+i*6,c,6)==0) {
     *(u8 *)(((struct Obj22071 *)d)->f244+a+0x18)=i;
     return;
    }
   }
  }
 }
}

void func_021B99A8(int a,int b,void *c,unsigned d,void *e)
{
 if(e==func_020399A8()) {
  if(a!=func_02039338()) func_02082D44(c,(void *)(((struct Obj22072 *)d)->f244+0x18),4);
 }
}

void func_021B99D4(unsigned char *a)
{
 if(func_02035C60()!=0) {
  func_021B95C0(a);
  func_021B95B8((unsigned char *)a,(unsigned)func_021B96B8);
 }
}

void func_021B99F4(unsigned a)
{
 if(++((struct Obj22073 *)a)->fCAC>60) {
  func_0203CEAC(0);
  func_021B95B8((unsigned char *)a,(unsigned)func_021B99D4);
 }
}

void func_021B9A1C(unsigned a)
{
 if(func_02039CB4((struct Link *)func_020399A8(),0x7f,12)!=0) {
  GFL_NET_SetAutoExit(0); func_0203D7BC(0);
  ((struct Obj22074 *)a)->fCAC=0;
  func_021B95B8((unsigned char *)a,(unsigned)func_021B99F4);
 }
}

/*
 * lever: one-word aggregate assignment schedules the stack address before its load/store.
 */
void func_021B9A54(int a)
{
 if(((struct Obj00060 *)a)->fC90!=0) {
  struct Word x=d_021BB664;
  func_021BA3A4(&x,a);
 } else {
  struct Word x=d_021BB678;
  func_021BA3A4(&x,a);
 }
 func_021BA454(0x22,a);
 func_020061E4(0x764);
 func_02039C68((struct Link *)func_020399A8(),0x7f,12);
 func_021B95B8((u8 *)a,(u32)func_021B9A1C);
}

int func_021B9AB4(unsigned a)
{
 int x; int y;
 x=func_0201AA50((void *)(*(int *)(((struct Obj13708 *)a)->f244+8)));
 y=func_0201AA50((void *)(*(int *)(((struct Obj13708 *)a)->f244+12)));
 if(x>y) return y;
 return x;
}

void func_021B9AD8(int a)
{
 if(func_02039CB4((struct Link *)func_020399A8(),0x7a,12)!=0) {
  switch(((struct Obj22075 *)a)->f24C) {
  case 7: func_021B95B8((u8 *)a,(u32)func_021B9A54); return;
  case 1: case 2: case 3: case 4:
   POKE_TOOL_HealParty((void *)((*(int **)(a+0x244))[2]));
   POKE_TOOL_HealParty((void *)((*(int **)(a+0x244))[3]));
   switch(func_021B9AB4(a)) {
    case 0: break;
    case 1: (*(int **)(a+0x244))[7]=1; break;
    case 2: if((*(int **)(a+0x244))[7]>2) (*(int **)(a+0x244))[7]=2; break;
   }
   func_021B95B8((u8 *)a,(u32)func_021B96B8);
  default: case 0: case 5: case 6: func_021B95B8((u8 *)a,(u32)func_021B96B8); break;
  }
 }
}

void func_021B9B7C(int a)
{
 int k=12;
 if(func_02039CB4((struct Link *)func_020399A8(),0x7e,k)!=0) {
  int p=(int)func_020399A8();
  int q=POKE_REGULATION_GetDataSize();
  if(func_0203D3F8(p,0xff,0xc02,q,(*(int **)(a+0x244))[1],0,0,1)!=0) {
   func_02039C68((struct Link *)func_020399A8(),0x7a,k);
   func_021B95B8((u8 *)a,(u32)func_021B9AD8);
  }
 }
}

void func_021B9BE4(int a)
{
 int k=12;
 if(func_02039CB4((struct Link *)func_020399A8(),0x7d,k)!=0) {
  if(func_0203D378()!=0) {
   if(func_0203D3A8(func_020399A8(),0xc05,4,((struct Obj22076 *)a)->f244+0x18)!=0) {
    func_02039C68((struct Link *)func_020399A8(),0x7e,k);
    func_021B95B8((u8 *)a,(u32)func_021B9B7C);
   }
  } else {
   func_02039C68((struct Link *)func_020399A8(),0x7e,k);
   func_021B95B8((u8 *)a,(u32)func_021B9B7C);
  }
 }
}

void func_021B9C50(int a)
{
 u8 x[6];
 int k=12;
 if(func_02039CB4((struct Link *)func_020399A8(),0x79,k)!=0) {
  int t=((struct Obj22077 *)a)->f24C;
  switch(t) {
  case 9: case 10: case 11:
   func_021B95B8((u8 *)a,(u32)func_021B96B8);
   return;
  default: break;
  }
  func_02087C6C(x);
  if(func_0203D3A8(func_020399A8(),0xc04,6,(u32)x)!=0) {
   func_02039C68((struct Link *)func_020399A8(),0x7d,k);
   func_021B95B8((u8 *)a,(u32)func_021B9BE4);
  }
 }
}

void func_021B9CC4(int a)
{
 u8 x[12];
 int k=12;
 if(func_02039CB4((struct Link *)func_020399A8(),0x7b,k)!=0) {
  if(((struct Obj03738 *)a)->f24C==7) {
   func_02009CA8((void *)func_0201283C((const struct BigObj *)(**(int * *)&((struct Obj03738 *)a)->f244)),x);
   if(func_0203D3A8(func_020399A8(),0xc03,k,(u32)x)!=0) {
    func_02039C68((struct Link *)func_020399A8(),0x79,k);
    func_021B95B8((u8 *)a,(u32)func_021B9C50);
    if(((struct Obj03738 *)a)->fCC0!=0) {
     func_02027858((struct TaskMenu *)(((struct Obj03738 *)a)->fCC0));
     ((struct Obj03738 *)a)->fCC0=0;
    }
   }
  } else {
   func_02039C68((struct Link *)func_020399A8(),0x79,k);
   if(((struct Obj03738 *)a)->fCC0!=0) {
    func_02027858((struct TaskMenu *)(((struct Obj03738 *)a)->fCC0));
    ((struct Obj03738 *)a)->fCC0=0;
   }
   func_021B95B8((u8 *)a,(u32)func_021B9C50);
  }
 }
}

void func_021B9D6C(int a) {
 int p=(int)func_020399A8();
 int k=func_02008468();
 int v=(int)func_02012944((void *)(**(int * *)&((struct Obj22079 *)a)->f244));
 if(func_0203D3A8((void *)p,(u16)0xc01,(u16)k,v)!=0) {
  func_02039C68((struct Link *)func_020399A8(),0x7b,12);
  func_021B95B8((u8 *)a,(u32)((void (*)(void))func_021B9CC4));
 }
}

void func_021B9DB8(int a) {
 if(func_02039CB4((struct Link *)func_020399A8(),0x7c,12)!=0) {
  int i=func_02039338();
  int n=((struct Obj13709 *)a)->f24C;
  switch(n) {
  case 1: case 2: case 3: case 4: {
   int v=*(int *)(a+(1-i)*4+0x250);
   if(n>v) *(int *)(((struct Obj13709 *)a)->f244+0x1c)=v;
   break;
  }
  }
  func_021B95B8((u8 *)a,(u32)func_021B9D6C);
 }
}

void func_021B9E14(unsigned a)
{
 struct Word x;
 func_021BA5F4(a);
 x.x=((struct Obj00060 *)a)->fCB0;
 func_021BA3A4(&x,a);
 func_021BA290(a,0);
 func_021B95B8((unsigned char *)a,(unsigned)func_021B9EF8);
}

void func_021B9E48(int a) {
 if(func_020279E8((struct TaskMenu *)(((struct Obj07961 *)a)->fCC0))!=0) {
  int v=func_02027A04((const u8 *)(((struct Obj07961 *)a)->fCC0));
  func_02027858((struct TaskMenu *)(((struct Obj07961 *)a)->fCC0));
  ((struct Obj07961 *)a)->fCC0=0;
  func_02041B6C(6);
  if(v==0) {
   func_021BA5F4(a);
   func_021B95C0((u8 *)a);
   func_021B95B8((u8 *)a,(u32)func_021B96B8);
  } else func_021B95B8((u8 *)a,(u32)func_021B9E14);
  func_021B967C(a,0);
 }
}

void func_021B9EA4(int a) {
 struct Word x=d_021BB65C;
 int v=((struct Obj00060 *)a)->fCB0;
 func_02049B40(23,5,4,0x180,32,((struct Obj00060 *)a)->f278);
 func_021BA3A4(&x,a);
 ((struct Obj00060 *)a)->fCB0=v;
 func_021BA1D0(a);
 func_0201DD68();
 func_021B95B8((u8 *)a,(u32)func_021B9E48);
}


void func_021B9EF8(u8 *a)
{
    if (((struct Obj00060 *)a)->fCC0 != 0) {
        if (func_020279E8((struct TaskMenu *)(((struct Obj00060 *)a)->fCC0)) != 0) {
            func_02027A04((const u8 *)(((struct Obj00060 *)a)->fCC0));
            func_02027858((struct TaskMenu *)(((struct Obj00060 *)a)->fCC0));
            ((struct Obj00060 *)a)->fCC0 = 0;
            func_02041B6C(6);
            func_021B95B8(a, (u32)((void (*)(void))func_021B9EA4));
            return;
        }
    } else {
        func_021BA290((int)a, 0);
        return;
    }
    {
        int k = 0xc;

        if (func_02039CB4((struct Link *)func_020399A8(), 0x78, k) != 0) {
            if (func_0203D3A8(func_020399A8(), k << 8, 4, (u32)(a + 0x24c)) != 0) {
                func_02039C68((struct Link *)func_020399A8(), 0x7c, k);
                func_021B95B8(a, (u32)((void (*)(void))func_021B9DB8));
            }
        }
    }
}

void func_021B9F80(unsigned a)
{
 func_0203A574(0xc00,(unsigned)d_021BB6C0,6,a);
 func_02039C68((struct Link *)func_020399A8(),0x78,12);
 GFL_NET_SetAutoExit(1);func_0203D7BC(1);
 func_021B95B8((unsigned char *)a,(unsigned)func_021B9EF8);
}

void func_021B9FBC(int a) {
 if(func_0203D378()!=0) {
  char *p;
  int i=0;
  p=(char *)(a+0x260);
  for(;i<4;i++) GFL_NET_IRC_WIRELESS_GetMacAddress(p+i*6,i);
 }
 func_021B95B8((u8 *)a,(u32)func_021B9F80);
}

void func_021B9FF4(int a,int b) {
 ((struct Obj05266 *)a)->fC7C=b;
 ((struct Obj05266 *)a)->fC8C=1;
 ((struct Obj05266 *)a)->fC94=1;
 if(((struct Obj05266 *)a)->f24C==5 && b==0) {
  ((struct Obj05266 *)a)->fC80=1;
  ((struct Obj05266 *)a)->fC84=1;
 }
}

void func_021BA028(char *a0) {
 func_020433E0((const struct DispVram *)d_021BB6F0);func_0203FC28((struct DispConfig *)d_021BB6B0);
 func_02043534(0);func_020435F4(0);
 {struct BgTemplate t=d_021BB720;func_0203FCA0(0,&t,0);func_02041300(0,0,0,0,32,32,17);func_020409B4(0);}
 {struct BgTemplate t=d_021BB740;func_0203FCA0(1,&t,0);func_02041300(1,0,0,0,32,32,17);func_020409B4(1);}
 {struct BgTemplate t=d_021BB760;func_0203FCA0(4,&t,0);func_02041300(4,0,0,0,32,32,17);}
 {struct BgTemplate t=d_021BB780;func_0203FCA0(5,&t,0);func_02041300(5,0,0,0,32,32,17);func_020409B4(5);}
 {struct BgTemplate t=d_021BB7A0;func_0203FCA0(6,&t,0);func_02040C14(6,0,1,0);func_02041300(6,0,0,0,32,32,17);func_020409B4(6);}
 {struct BgTemplate t=d_021BB7C0;func_0203FCA0(7,&t,0);func_02041300(7,0,0,0,32,32,17);func_020409B4(7);}
}

void func_021BA1C8(void) { func_0204A648(); }

void func_021BA1D0(int a) {
 struct Template t;
 int v;
 t.heap=((struct Obj00060 *)a)->f278;
 t.count=2;
 t.ptr=a+0xcc8;
 t.flag=1;
 t.x=32; t.y=13; t.z=13; t.w=3;
 v=(int)func_020457B0(100,t.heap);
 ((struct Obj00060 *)a)->fCC8=v;
 func_02045CAC((struct MsgBank *)(((struct Obj00060 *)a)->f288),26,(void *)v);
 ((struct Obj00060 *)a)->fCCC=0x39e3;
 v=(int)func_020457B0(100,((struct Obj00060 *)a)->f278);
 ((struct Obj00060 *)a)->fCD4=v;
 func_02045CAC((struct MsgBank *)(((struct Obj00060 *)a)->f288),27,(void *)v);
 ((struct Obj00060 *)a)->fCD8=0x39e3;
 ((struct Obj00060 *)a)->fCD0=0;
 ((struct Obj00060 *)a)->fCDC=0;
 v=(int)func_02027778((struct TaskMenuTmpl *)(&t),(void *)(((struct Obj00060 *)a)->fCC4));
 ((struct Obj00060 *)a)->fCC0=v;
 switch(((struct Obj00060 *)a)->f24C) {case 9: case 10: case 11: break; default: func_02027CD8(v,1); break;}
 func_02045808((struct U16Vec *)(((struct Obj00060 *)a)->fCC8));
 func_02045808((struct U16Vec *)(((struct Obj00060 *)a)->fCD4));
 func_021B967C(a,1);
}

void func_021BA290(int a,int flag) {
 struct Template t;
 int v;
 t.heap=((struct Obj00060 *)a)->f278;
 t.flag=1;
 t.x=32;t.y=24;t.z=13;t.w=3;
 if(flag!=0) {
  t.count=2;t.ptr=a+0xcc8;
  v=(int)func_020457B0(100,t.heap);((struct Obj00060 *)a)->fCC8=v;
  func_02045CAC((struct MsgBank *)(((struct Obj00060 *)a)->f288),0x23,(void *)v);
  ((struct Obj00060 *)a)->fCCC=0x39e3;((struct Obj00060 *)a)->fCD0=0;
  v=(int)func_020457B0(100,((struct Obj00060 *)a)->f278);((struct Obj00060 *)a)->fCD4=v;
  func_02045CAC((struct MsgBank *)(((struct Obj00060 *)a)->f288),2,(void *)v);
  ((struct Obj00060 *)a)->fCD8=0x39e3;((struct Obj00060 *)a)->fCDC=1;
  ((struct Obj00060 *)a)->fCC0=(int)func_02027778((struct TaskMenuTmpl *)(&t),(void *)(((struct Obj00060 *)a)->fCC4));
  func_02045808((struct U16Vec *)(((struct Obj00060 *)a)->fCC8));func_02045808((struct U16Vec *)(((struct Obj00060 *)a)->fCD4));
  ((struct Obj00060 *)a)->fCBC=0;
 } else {
  t.count=1;t.ptr=a+0xcc8;
  v=(int)func_020457B0(100,t.heap);((struct Obj00060 *)a)->fCC8=v;
  func_02045CAC((struct MsgBank *)(((struct Obj00060 *)a)->f288),2,(void *)v);
  ((struct Obj00060 *)a)->fCCC=0x39e3;((struct Obj00060 *)a)->fCD0=1;
  ((struct Obj00060 *)a)->fCC0=(int)func_02027778((struct TaskMenuTmpl *)(&t),(void *)(((struct Obj00060 *)a)->fCC4));
  func_02045808((struct U16Vec *)(((struct Obj00060 *)a)->fCC8));((struct Obj00060 *)a)->fCBC=1;
 }
 switch(((struct Obj00060 *)a)->f24C) {case 9:case 10:case 11:break;default:func_02027CD8(((struct Obj00060 *)a)->fCC0,1);break;}
}

void func_021BA3A4(struct Word *p,int a) {
 func_02049B40(23,5,4,0x1a0,32,((struct Obj00060 *)a)->f278);
 if(*(int *)&((struct Obj00060 *)a)->f27C==0) {
  int v=func_020450F0(5,1,1,30,5,13,0);
  *(int *)&((struct Obj00060 *)a)->f27C=v;
  func_02045374((struct Cfg *)v);
  func_0201F73C((void *)(*(int *)&((struct Obj00060 *)a)->f27C),0,(unsigned short)(((struct Obj00060 *)a)->f304),14);
 }
 func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)*(int *)&((struct Obj00060 *)a)->f27C)),255);
 ((struct Obj00060 *)a)->fCB0=p->x;
 func_02045CAC((struct MsgBank *)(((struct Obj00060 *)a)->f288),p->x,(void *)(((struct Obj00060 *)a)->f298));
 func_0201C7A4((void *)((int)func_02045770((struct Descriptor *)*(int *)&((struct Obj00060 *)a)->f27C)),4,4,(void *)(((struct Obj00060 *)a)->f298),(void *)(((struct Obj00060 *)a)->f290));
 func_02045334((struct Descriptor *)*(int *)&((struct Obj00060 *)a)->f27C);
}

void func_021BA454(int text,int a) {
 if(((struct Obj01246 *)a)->f280==0) {
  int v=(int)func_020450F0((int)5,(int)1,(int)8,(int)18,4,13,0);
  ((struct Obj01246 *)a)->f280=v;
  func_02045374((struct Cfg *)v);
  func_0201F73C((void *)(((struct Obj01246 *)a)->f280),0,(unsigned short)(((struct Obj01246 *)a)->f304),14);
 }
 func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)((struct Obj01246 *)a)->f280)),255);
 func_02045CAC((struct MsgBank *)(((struct Obj01246 *)a)->f288),text,(void *)(((struct Obj01246 *)a)->f294));
 func_0201EFA4((struct WordSet *)(((struct Obj01246 *)a)->f28C),0,func_02009A34((struct Sub020097BCObj *)func_0201283C((const struct BigObj *)(**(int * *)&((struct Obj01246 *)a)->f244))),2,1,1);
 func_0201EFA4((struct WordSet *)(((struct Obj01246 *)a)->f28C),1,32,2,1,1);
 func_0201F250((struct WordSet *)(((struct Obj01246 *)a)->f28C),(void *)(((struct Obj01246 *)a)->f298),(void *)(((struct Obj01246 *)a)->f294));
 func_0201C7A4((void *)((int)func_02045770((struct Descriptor *)((struct Obj01246 *)a)->f280)),0,2,(void *)(((struct Obj01246 *)a)->f298),(void *)(((struct Obj01246 *)a)->f290));
 func_02045334((struct Descriptor *)((struct Obj01246 *)a)->f280);
}

/*
 *   veneer evidence cannot attest the target. the integrator owns the ARM9 fix.
 * note 2026-10-04 (wD2 lane18): still MATCH, only unresolved relocations remain: callee GFL_NET_IRC_WIRELESS_GetRetryCount (veneer to 0x0203E590) still has no witness; GFL_NET_IRC_WIRELESS_GetRetryCountValue filed EXACT as src/matched/arm9/GFL_NET_IRC_WIRELESS_GetRetryCountValue.c, integrator must regenerate labels/manifest so the veneer resolves.
 */
void func_021BA530(int b,int a) {
 if(*(int *)(a+0x280)==0) *(int *)(a+0x280)=(int)func_020450F0((int)5,(int)1,(int)8,(int)23,4,13,0);
 func_02043B5C(func_02045770((struct Descriptor *)(*(int *)(a+0x280))),(int)255);
 func_02045374((struct Cfg *)(*(int *)(a+0x280)));
 func_02045334((struct Descriptor *)(*(int *)(a+0x280)));
 func_0201F73C((void *)(*(int *)(a+0x280)),0,(unsigned short)(*(int *)(a+0x304)),14);
 func_02045CAC((struct MsgBank *)(*(int *)(a+0x288)),(int)b,(void *)(*(int *)(a+0x294)));
 func_0201EFA4((struct WordSet *)(*(int *)(a+0x28c)),(int)0,(int)GFL_NET_IRC_WIRELESS_GetRetryCount(),(int)2,(int)1,(int)1);
 func_0201F250((struct WordSet *)(*(int *)(a+0x28c)),(void *)(*(int *)(a+0x298)),(void *)(*(int *)(a+0x294)));
 func_0201C7A4(func_02045770((struct Descriptor *)(*(int *)(a+0x280))),0,2,(void *)(*(int *)(a+0x298)),(void *)(*(int *)(a+0x290)));
 func_02045334((struct Descriptor *)(*(int *)(a+0x280)));
}

void func_021BA5F4(unsigned a)
{
 if(*(unsigned *)&((struct Obj00060 *)a)->f27C!=0) func_020452E8(*(struct Descriptor * *)&((struct Obj00060 *)a)->f27C);
 if(*(unsigned *)&((struct Obj00060 *)a)->f280!=0) func_020452E8(*(struct Descriptor * *)&((struct Obj00060 *)a)->f280);
 *(unsigned *)&((struct Obj00060 *)a)->f27C=0;
 *(unsigned *)&((struct Obj00060 *)a)->f280=0;
}

void func_021BA624(unsigned a)
{
 func_0203F8F4(((struct Obj13711 *)a)->f278);
 func_02045088(((struct Obj13711 *)a)->f278);
 func_0201DD60();
}

void func_021BA640(int a0) { func_0203F9B4(); func_020450C8(); }

void func_021BA64C(unsigned a,unsigned b)
{
 if(*(unsigned *)(a+0x2c8+b*4)!=0) {
  func_0204B3B4(*(struct Obj **)(a+0x2c8+b*4));
  *(unsigned *)(a+0x2c8+b*4)=0;
 }
}

void func_021BA668(int a) {
 if(((struct Obj00060 *)a)->fCA0==1) {struct Word t=d_021BB694;func_021BA3A4(&t,a);return;}
 if(((struct Obj00060 *)a)->f24C==7) {
  if(func_02009A34((struct Sub020097BCObj *)func_0201283C((const struct BigObj *)(**(int * *)&((struct Obj00060 *)a)->f244)))==32) {struct Word t=d_021BB690;func_021BA3A4(&t,a);return;}
  else {struct Word t=d_021BB670;func_021BA3A4(&t,a);func_021BA454(0x22,a);return;}
 }
 if(((struct Obj00060 *)a)->f24C==6) {struct Word t=d_021BB680;func_021BA3A4(&t,a);return;}
 if(((struct Obj00060 *)a)->f24C==5) {struct Word t=d_021BB684;func_021BA3A4(&t,a);return;}
 if(((struct Obj00060 *)a)->f24C==9) {struct Word t=d_021BB67C;func_021BA3A4(&t,a);func_021BA530(0x27,a);return;}
 if(((struct Obj00060 *)a)->f24C==10) {struct Word t=d_021BB66C;func_021BA3A4(&t,a);return;}
 if(((struct Obj00060 *)a)->f24C==11) {struct Word t=d_021BB6A0;func_021BA3A4(&t,a);return;}
 else {struct Word t=d_021BB698;func_021BA3A4(&t,a);return;}
}

void func_021BA780(char *p) {
 void *owner;
 void *raw;
 void *resource;
 int i;
 func_0201DD68();
 ((struct Obj00178 *)p)->f28C=(int)func_0201EC74(11,200,((struct Obj00178 *)p)->f278);
 func_021BA624((unsigned int)p);func_021BA028(p);
 ((struct Obj00178 *)p)->f298=(int)func_020457B0(200,((struct Obj00178 *)p)->f278);
 ((struct Obj00178 *)p)->f294=(int)func_020457B0(200,((struct Obj00178 *)p)->f278);
 ((struct Obj00178 *)p)->f290=(int)func_0201D7EC(23,0,0,0,((struct Obj00178 *)p)->f278);
 ((struct Obj00178 *)p)->f288=(int)func_02045B38(0,2,46,((struct Obj00178 *)p)->f278);
 owner=func_020490F4(28,((struct Obj00178 *)p)->f278);
 func_02049B68(owner,1,0,0,0,((struct Obj00178 *)p)->f278);
 ((struct Obj00178 *)p)->f2FC=(int)func_02049740(owner,6,0,0,0,((struct Obj00178 *)p)->f278);
 if(((struct Obj00178 *)p)->f24C!=5) func_02049990(owner,13,1,0,(u16)(((struct Obj00178 *)p)->f2FC),0,0,((struct Obj00178 *)p)->f278);
 else {func_02049990(owner,13,0,0,(u16)(((struct Obj00178 *)p)->f2FC),0,0,((struct Obj00178 *)p)->f278);func_02049990(owner,14,1,0,(u16)(((struct Obj00178 *)p)->f2FC),0,0,((struct Obj00178 *)p)->f278);}
 func_02049238(owner);
 owner=func_020490F4(29,((struct Obj00178 *)p)->f278);
 func_02049B68(owner,1,4,0,0,((struct Obj00178 *)p)->f278);
 ((struct Obj00178 *)p)->f308=(int)func_02049740(owner,4,4,0,0,((struct Obj00178 *)p)->f278);
 func_02049990(owner,9,4,0,(u16)(((struct Obj00178 *)p)->f308),0,0,((struct Obj00178 *)p)->f278);func_02049238(owner);
 ((struct Obj00178 *)p)->f304=(int)func_0201F5DC((void *)5,14,0,((struct Obj00178 *)p)->f278);
 func_0204E720(3,16,0,2);func_021BA668((int)p);
 func_0204A48C((const struct Cfg *)d_020A1448,(u32)d_021BB6F0,((struct Obj00178 *)p)->f278);
 ((struct Obj00178 *)p)->f2B4=(int)func_0204B100(40,0,((struct Obj00178 *)p)->f278);
 ((struct Obj00178 *)p)->f2B0=func_020056A0((u32)func_021BA1C8,(u32)p,0);
 ((struct Obj00178 *)p)->fCB8=func_0201C440((void *)(((struct Obj00178 *)p)->f278));
 ((struct Obj00178 *)p)->fCC4=(int)func_02027F60(6,9,((struct Obj00178 *)p)->f290,((struct Obj00178 *)p)->fCB8,((struct Obj00178 *)p)->f278);
 func_021B96EC(p);
 if(((struct Obj00178 *)p)->f24C!=5) {
  func_021B974C((int)p,57,154,2,10);func_021B974C((int)p,128,113,4,2);func_021B974C((int)p,200,38,0,11);func_021B974C((int)p,128,77,5,3);
 } else {
  func_021B974C((int)p,57,154,0,4);func_021B974C((int)p,198,154,1,5);func_021B974C((int)p,200,38,2,6);func_021B974C((int)p,55,38,3,7);func_021B974C((int)p,152,146,6,0);func_021B974C((int)p,103,146,7,1);func_021B974C((int)p,152,46,4,0);func_021B974C((int)p,103,46,5,1);
 }
 func_02043534((int)19);func_020435F4((int)23);
 ((struct Obj00178 *)p)->f242=((struct Obj00178 *)p)->f278;
 owner=func_020490F4(28,((struct Obj00178 *)p)->f242);
 raw=func_02049F78(owner,2,(u32)(&resource),((struct Obj00178 *)p)->f242);
 func_02082D44(((struct Obj22083 *)resource)->fC,p,0x120);
 for(i=0;i<9;i++) func_02082D44(p+(8-i)*32,p+(i+9)*32,32);
 func_020307B0(raw);func_02049238(owner);func_021B95B8((u8 *)p,(u32)func_021BAA9C);
}

void func_021BAA9C(int a) {
 if(func_0204E804()!=0) {
  if(((struct Obj10216 *)a)->f24C==7) {
   if(func_02009A34((struct Sub020097BCObj *)func_0201283C((const struct BigObj *)(**(int * *)&((struct Obj10216 *)a)->f244)))==32) {
    func_021B95B8((u8 *)a,(u32)func_021BAFA0);
    ((struct Obj10216 *)a)->fCAC=180;
    return;
   }
  }
  func_021B95B8((u8 *)a,(u32)func_021BAB08);
 }
}

int func_021BAAEC(int a,int b) {
 if(a==19 && b==18) return 1;
 if(b==19 && a==18) return 1;
 return 0;
}

/*
 *   Exact non-C body: E59FC000,E12FFF1C,0203DA68; unlabelled target.
 *   Data021BB83C resolves sole-ref on the byte-correct 256-byte run.
 *   D0C4 tail-forwards r0 unchanged; full DA68 body reads only that u32,
 *   copies it unchanged to singleton+74, no arithmetic or narrowing.
 *   scratch-only DA68 one --arm (no region), fixed flags: EXACT20, literal15.
 *   Verified C (not filed ARM9): extern unsigned char *gNetIrcWirelessLink;
 *   void GFL_NET_IRC_WIRELESS_SetSessionParamValue(unsigned int value) {
 *       *(unsigned int *)(gNetIrcWirelessLink+0x74)=value;
 *   }
 *   caller-only TU suggest-split MATCH256: two witnesses, both inside this
 *   sole function; zero viable pieces. Do not file overlay leaves while capped.
 * note 2026-10-04 (wD2 lane18): still MATCH, only unresolved relocations remain: callee GFL_NET_IRC_WIRELESS_SetSessionParam (veneer to 0x0203DA68) still has no witness; GFL_NET_IRC_WIRELESS_SetSessionParamValue filed EXACT as src/matched/arm9/GFL_NET_IRC_WIRELESS_SetSessionParamValue.c, integrator must regenerate labels so the veneer resolves.
 */
void func_021BAB08(int p)
{
    struct Req req;
    int zero,q;
    req=d_021BB83C;
    req.mode=4;
    switch(*(u32 *)(p+0x24c)) {
    case 1:case 2:case 3:case 4:
        req.kind=12;
        break;
    case 5:
        req.kind=38;
        req.a=4;
        break;
    case 7:
        req.kind=29;
        break;
    case 6:
        req.kind=28;
        break;
    case 11:
        req.kind=44;
        break;
    case 9:
        req.limit=17;
        req.kind=19;
        req.e=1;
        q=*(int *)(p+0x244);
        req.a=*(u8 *)(*(int *)(q+0x20)+0x60);
        req.b=*(u8 *)(*(int *)(q+0x20)+0x61);
        req.value=*(u16 *)(*(int *)(q+0x20)+0x6c);
        *(int *)(p+0xce8)=-1;
        break;
    case 10:
        req.limit=17;
        req.kind=18;
        req.e=1;
        q=*(int *)(p+0x244);
        req.a=*(u8 *)(*(int *)(q+0x20)+0x60);
        req.b=*(u8 *)(*(int *)(q+0x20)+0x61);
        req.value=*(u16 *)(*(int *)(q+0x20)+0x6c);
        *(int *)(p+0xce8)=-1;
        break;
    }
    zero=0;
    func_0203CBAC(&req,0,p);
    switch(*(int *)(p+0x24c)) {
    case 10:
        GFL_NET_IRC_WIRELESS_SetSessionParam((u32)func_021BAAEC);
        GFL_NET_IRC_WIRELESS_SetRetryRequest(1);
        GFL_NET_SetGameKindOverride(17);
        break;
    case 9:
        GFL_NET_IRC_WIRELESS_SetSessionParam((u32)func_021BAAEC);
        GFL_NET_IRC_WIRELESS_SetRetryRequest(zero);
        GFL_NET_SetGameKindOverride(17);
        break;
    case 5:
        GFL_NET_SetGameKindOverride(37);
        break;
    }
    func_021BA290(p,0);
    func_021B95B8((u8 *)p,(u32)func_021BAC80);
}

void func_021BAC08(int a) {
 func_0201DD68();
 func_021BA5F4(a);
 func_02040DA8(5,1,0);
 {
  unsigned int v=((struct Obj05267 *)a)->f304;
  unsigned int w=v>>16;
  func_0203FB44(5,(unsigned short)v,(unsigned short)w);
 }
 func_020403F4(5);
 func_02045C04((struct Rec *)(((struct Obj05267 *)a)->f288));
 func_0201D83C((void *)(((struct Obj05267 *)a)->f290));
 func_02045808((struct U16Vec *)(((struct Obj05267 *)a)->f294));
 func_02045808((struct U16Vec *)(((struct Obj05267 *)a)->f298));
 func_02040588(5,0);
 func_02027FD8((struct TaskMenuState *)(((struct Obj05267 *)a)->fCC4));
 func_021BA640(a);
}

/*
 * evidence: 0x021799C0 is the ov015 Thumb callback setter, while ov009
 *   holds unrelated interior ARM instructions at the overlapping address.
 */
void func_021BAC80(int a) {
 if(func_0203CD98()==1) {
  switch(((struct Obj22085 *)a)->f24C) { case 9: case 10: func_021799C0((int)func_021BAAEC); break; }
  GFL_NET_StartChangeoverEx((u32)func_021B9FBC,(u32)func_021B9FF4,(u32)func_021B9848);
  func_021B95B8((u8 *)a,(u32)func_021BB270);
 }
}

void func_021BACC8(int a) {
 struct Word x;
 func_021BA5F4(a);
 x.x=((struct Obj10217 *)a)->fCB0;
 func_021BA3A4(&x,a);
 if(((struct Obj10217 *)a)->f24C==9 && ((struct Obj10217 *)a)->fCE8>0) {
  func_021BA290(a,1);
  func_021B95B8((u8 *)a,(u32)func_021BB270);
  return;
 }
 func_021BA290(a,0);
 func_021B95B8((u8 *)a,(u32)func_021BB270);
}

void func_021BAD1C(int a) {
 if(func_020279E8((struct TaskMenu *)(*(int *)&((struct Obj07962 *)a)->fCC0))!=0) {
  int v=func_02027A04(*(const u8 * *)&((struct Obj07962 *)a)->fCC0);
  func_02027858((struct TaskMenu *)(*(int *)&((struct Obj07962 *)a)->fCC0));
  *(int *)&((struct Obj07962 *)a)->fCC0=0;
  func_02041B6C(6);
  if(v==0) {
   func_021BA5F4(a); func_021B95C0((u8 *)a); func_021B95B8((u8 *)a,(u32)func_021B96B8);
  } else func_021B95B8((u8 *)a,(u32)func_021BACC8);
  func_021B967C(a,0);
 }
}

void func_021BAD78(unsigned a)
{
 if(func_020279E8((struct TaskMenu *)(*(int *)&((struct Obj07963 *)a)->fCC0))!=0) {
  func_02027A04(*(const u8 * *)&((struct Obj07963 *)a)->fCC0);
  func_02027858((struct TaskMenu *)(*(int *)&((struct Obj07963 *)a)->fCC0));
  *(unsigned *)&((struct Obj07963 *)a)->fCC0=0;
  func_02041B6C(6);
  func_021B95B8((u8 *)a,(unsigned)func_021BB058);
 }
}

void func_021BADB0(int a) {
 if(GFL_NET_IRC_WIRELESS_Step()!=0) { func_021B95B8((u8 *)a,(u32)func_021BAD78); return; }
 if(func_020279E8((struct TaskMenu *)(*(int *)&((struct Obj07964 *)a)->fCC0))!=0) {
  func_02027A04(*(const u8 * *)&((struct Obj07964 *)a)->fCC0);
  func_02027858((struct TaskMenu *)(*(int *)&((struct Obj07964 *)a)->fCC0));
  *(int *)&((struct Obj07964 *)a)->fCC0=0;
  func_02041B6C(6);
  func_021B95B8((u8 *)a,(u32)func_021BB058);
 }
}

void func_021BADFC(int p) { func_021BA290(p,0); func_021B95B8((u8 *)p,(u32)func_021BADB0); }

void func_021BAE14(int a) {
 struct Word x;
 x.x=((struct Obj10218 *)a)->fCB0;
 func_021BA3A4(&x,a);
 func_021B95B8((u8 *)a,(u32)func_021BB270);
 if(((struct Obj10218 *)a)->f24C==9 && ((struct Obj10218 *)a)->fCE8>0) { func_021BA290(a,1); return; }
 func_021BA290(a,0);
}

void func_021BAE5C(int a) {
 if(func_020279E8((struct TaskMenu *)(*(int *)&((struct Obj07965 *)a)->fCC0))!=0) {
  int v=func_02027A04(*(const u8 * *)&((struct Obj07965 *)a)->fCC0);
  func_02027858((struct TaskMenu *)(*(int *)&((struct Obj07965 *)a)->fCC0));
  *(int *)&((struct Obj07965 *)a)->fCC0=0;
  if(v==0) {
   func_021BA5F4(a); func_02041B6C(6); func_021B95B8((u8 *)a,(u32)func_021BADFC); return;
  } else { func_021BA5F4(a); func_021B95B8((u8 *)a,(u32)func_021BAE14); }
 }
}

/*
 * note: caller uses r0 after BLX; extern return retains that live value.
 */
void func_021BAEB4(int p) {
    if(func_02035C60()!=0) {
        func_021B95C0((u8 *)p);
        *(int *)(((struct Obj22086 *)p)->f244+0x1c)=13;
        func_021B95B8((u8 *)p,(u32)func_021B96B8);
    }
}

void func_021BAEE0(int a) {
 struct Word x=d_021BB674;
 int v=((struct Obj00060 *)a)->fCB0;
 func_02049B40(23,5,4,0x180,32,((struct Obj00060 *)a)->f278);
 func_021BA3A4(&x,a);
 ((struct Obj00060 *)a)->fCB0=v;
 func_021BA1D0(a);
 func_0201DD68();
 if(((struct Obj00060 *)a)->fCA4!=0) func_02051C6C((void *)(((struct Obj00060 *)a)->fCA4));
 ((struct Obj00060 *)a)->fCA4=0;
 func_021B95B8((u8 *)a,(u32)func_021BAD1C);
}

void func_021BAF4C(int a) {
 struct Word x=d_021BB688;
 int v=((struct Obj00060 *)a)->fCB0;
 func_02049B40(23,5,4,0x180,32,((struct Obj00060 *)a)->f278);
 func_021BA3A4(&x,a);
 ((struct Obj00060 *)a)->fCB0=v;
 func_021BA1D0(a);
 func_0201DD68();
 func_021B95B8((u8 *)a,(u32)func_021BAE5C);
}

void func_021BAFA0(int p) {
    if(--((struct Obj22087 *)p)->fCAC==0) {
        func_021BA5F4(p);
        func_021B95C0((u8 *)p);
        func_021B95B8((u8 *)p,(u32)func_021B96B8);
    }
}

void func_021BAFCC(int p) {
    struct Word x;
    func_021BA5F4(p);
    x.x=12;
    func_021BA3A4(&x,p);
    func_021BA290(p,0);
    func_021B95B8((u8 *)p,(u32)func_021BAD78);
}

void func_021BAFFC(int a) {
 if(func_020279E8((struct TaskMenu *)(*(int *)&((struct Obj07966 *)a)->fCC0))!=0) {
  int v=func_02027A04(*(const u8 * *)&((struct Obj07966 *)a)->fCC0);
  func_02027858((struct TaskMenu *)(*(int *)&((struct Obj07966 *)a)->fCC0));
  *(int *)&((struct Obj07966 *)a)->fCC0=0;
  func_02041B6C(6);
  if(v==0) {
   func_021BA5F4(a); func_021B95C0((u8 *)a); func_021B95B8((u8 *)a,(u32)func_021B96B8);
  } else func_021B95B8((u8 *)a,(u32)func_021BAFCC);
  func_021B967C(a,0);
 }
}

void func_021BB058(int a) {
 struct Word x=d_021BB668;
 int v=((struct Obj00060 *)a)->fCB0;
 func_02049B40(23,5,4,0x180,32,((struct Obj00060 *)a)->f278);
 func_021BA3A4(&x,a);
 ((struct Obj00060 *)a)->fCB0=v;
 func_021BA1D0(a);
 func_0201DD68();
 if(((struct Obj00060 *)a)->fCA4!=0) func_02051C6C((void *)(((struct Obj00060 *)a)->fCA4));
 ((struct Obj00060 *)a)->fCA4=0;
 func_021B95B8((u8 *)a,(u32)func_021BAFFC);
}

void func_021BB0C4(int a) {
 switch(CLACT_GetActorAnimSeq(((struct Obj10219 *)a)->f2C8)) {
 case 8:
  func_0204B878(((struct Obj10219 *)a)->f2C8,11);
  func_021B9800(a,200,38,0);
  func_021B974C(a,128,113,4,2);
  return;
 case 11: break;
 default: func_0204B878(((struct Obj10219 *)a)->f2C8,8); break;
 }
}

void func_021BB10C(int a) {
 switch(CLACT_GetActorAnimSeq(((struct Obj10220 *)a)->f2D0)) {
 case 9:
  func_0204B878(((struct Obj10220 *)a)->f2D0,10);
  func_021B9800(a,57,154,2);
  func_021B974C(a,128,77,5,3);
  return;
 case 10: break;
 default: func_0204B878(((struct Obj10220 *)a)->f2D0,9); break;
 }
}

void func_021BB154(int p) {
    struct Word x=d_021BB660;
    func_021BA5F4(p);
    func_021BA3A4(&x,p);
    func_021B95B8((u8 *)p,(u32)func_021BAEB4);
}

/*
 * evidence: BA00 tail forwards to D768; full D768 body reads state at0,
 *   words at4/8 for state0, and never the uninitialized padding at2 in that arm.
 * lever: b before a places their Word locals at sp+4 and sp+0 respectively.
 */
void func_021BB180(int p)
{
    struct Word b,a;
    struct Task task;
    func_021BA5F4(p);
    if(((struct Obj02449 *)p)->fC8C==1) {
        if(((struct Obj02449 *)p)->fC7C) {
            b=d_021BB69C;
            func_021BA3A4(&b,p);
        } else {
            a=d_021BB68C;
            func_021BA3A4(&a,p);
            func_021BA64C(p,0);
            func_021BA64C(p,2);
        }
        func_021BA64C(p,6);
        func_021BA64C(p,7);
        func_021BA64C(p,4);
        func_021BA64C(p,5);
        func_021BA64C(p,1);
        func_021BA64C(p,3);
        if(((struct Obj02449 *)p)->fC7C) {
            task.state=0;
            task.context=p;
            task.callback=func_021BB0C4;
            func_0204BA00((struct Actor *)(((struct Obj02449 *)p)->f2C8),(const struct Cmd *)(&task));
            task.callback=func_021BB10C;
            func_0204BA00((struct Actor *)(((struct Obj02449 *)p)->f2D0),(const struct Cmd *)(&task));
        }
        ((struct Obj02449 *)p)->fC8C=0;
    }
    ((struct Obj02449 *)p)->fC98=(int)(*(u32 *)&((struct Obj02449 *)p)->fC98+1);
    if(((struct Obj02449 *)p)->fC98>8 && ((struct Obj02449 *)p)->fCEC) {
        ((struct Obj02449 *)p)->fC94=0;
        func_02040588(1,0);
    }
}

void func_021BB270(int p)
{
    int value;
    if(*(int *)(p+0xc94) && *(int *)(p+0x24c)==5) {
        func_021BB180(p);
    } else if(*(int *)(p+0xc84)==1 && *(int *)(p+0x24c)!=9) {
        if(*(int *)(p+0xc80)==1) {
            func_021BA5F4(p);
            func_021BA3A4(&d_021BB804[*(int *)(p+0x24c)],p);
            func_021BA64C(p,4);
            func_021BA64C(p,5);
            *(int *)(p+0xc80)=0;
            if(*(struct Obj **)(p+0x2c8)) {
                func_0204B92C(*(struct Obj **)(p+0x2c8),0);
                func_0204B92C(*(struct Obj **)(p+0x2d0),0);
            }
        }
        func_021B97BC(p,0,-2,0);
        func_021B97BC(p,0,2,2);
        *(u32 *)(p+0xc88)=*(u32 *)(p+0xc88)+1;
        if(*(int *)(p+0xc88)>30) {
            if(*(struct Obj **)(p+0x2c8)) {
                func_0204B3DC(*(struct Obj **)(p+0x2c8),0);
                func_0204B3DC(*(struct Obj **)(p+0x2d0),0);
            }
            *(int *)(p+0xc84)=0;
        }
    }
    if(func_0203CD98() && GFL_NET_HANDLE_GetNegotiationState(func_020399A8())==7) {
        func_021B95B8((u8 *)p,(u32)func_021BB154);
        return;
    }
    if(func_020279E8(*(struct TaskMenu **)(p+0xcc0))) {
        value=func_02027A04(*(const u8 **)(p+0xcc0));
        func_02027858(*(struct TaskMenu **)(p+0xcc0));
        *(int *)(p+0xcc0)=0;
        func_02041B6C(6);
        if(*(int *)(p+0xcbc)) {
            func_021B95B8((u8 *)p,(u32)func_021BAEE0);return;
        }
        if(value==0) {
            func_021B95B8((u8 *)p,(u32)func_021BAF4C);return;
        } else {
            func_021B95B8((u8 *)p,(u32)func_021BAEE0);return;
        }
    }
    if(*(int *)(p+0x24c)==9) {
        if(*(int *)(p+0xce8)!=GFL_NET_IRC_WIRELESS_GetRetryCount()) {
            func_021BA530(0x27,p);
            *(int *)(p+0xce8)=GFL_NET_IRC_WIRELESS_GetRetryCount();
        }
        if(*(int *)(p+0xce8)>0 && *(int *)(p+0xcbc)==1) {
            func_02027858(*(struct TaskMenu **)(p+0xcc0));
            *(int *)(p+0xcc0)=0;
            func_021BA290(p,1);
        }
    }
}


int func_021BB414(struct Obj0203159C *a, int b, int c)
{
    int r5;

    func_0203064C(1, 0x1f, 0x20000);
    r5 = 0xcf0;
    a = (struct Obj0203159C *)func_0203159C(a, r5, 0x1f);
    func_02082BCC((int)a, 0, r5);
    ((struct Obj00178 *)a)->f244 = c;
    ((struct Obj00178 *)a)->f278 = 0x1f;
    ((struct Obj00178 *)a)->f24C = *(int *)(((struct Obj00178 *)a)->f244 + 0x1c);
    ((struct Obj00178 *)a)->fCB4 =
        (int)func_02030734(((struct Obj00178 *)a)->f278, 0x200, 0, (const char *)0x021BB8AC, 0xb07);
    func_021BA780((char *)a);
    GFL_NET_IRC_WIRELESS_Exit();
    func_0207D63C(0x04000050, 0x10, 3, 9, 0xe);
    return 1;
}

u32 func_021BB498(u32 a, u32 b, u32 c, u8 *p)
{
    void (*cb)(u8 *) = *(void (**)(u8 *))(p + 0x248);
    u32 ret = 1;
    u32 flag;
    if ((*(volatile u32 *)0x02FFFC3C & 7) == 1) {
        func_0207E3D0(p + *(u16 *)(p + 0x240) * 32, 0, 0x20);
        *(u16 *)(p + 0x240) = *(u16 *)(p + 0x240) + 1;
        if (*(u16 *)(p + 0x240) == 9) {
            flag = ret;
            goto L;
        }
        if (*(u16 *)(p + 0x240) >= 0x12) *(u16 *)(p + 0x240) = 0;
    }
    flag = 0;
L:
    *(u32 *)(p + 0xCEC) = flag;
    if (cb) {
        cb(p);
        if (*(u32 *)(p + 0x248)) ret = 0;
    }
    if (*(u32 *)(p + 0xCC0)) func_02027974(*(u8 **)(p + 0xCC0));
    if (*(u32 *)(p + 0xCE0)) func_02028178(*(u8 **)(p + 0xCE0));
    if (*(u32 *)(p + 0xCE4)) func_02028178(*(u8 **)(p + 0xCE4));
    func_02040618(4, 3, *(u32 *)(p + 0xC9C));
    *(u32 *)(p + 0xC9C) = *(u32 *)(p + 0xC9C) - 1;
    func_0204A600();
    func_0201C4E4((struct PrintSys *)(*(u8 **)(p + 0xCB8)));
    if (func_0200FB24()) {
        func_0200FB38();
        *(u32 *)(*(u8 **)(p + 0x244) + 0x1C) = 12;
        ret = 1;
        func_0202223C(0, 0);
        func_0202223C(1, 0);
    }
    return ret;
}
