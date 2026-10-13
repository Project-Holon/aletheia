/*
 * file:     unit_021DC860.c
 * unit:     yes
 * function: func_021DC860, func_021DC894, func_021DC8A8, func_021DC8B8, func_021DC8D4, func_021DC8E4, func_021DC910, func_021DC924, func_021DC92C, func_021DCA40, func_021DCA7C, func_021DCB70, func_021DCB8C, func_021DCBA4, func_021DCBE8, func_021DCC0C, func_021DCC24, func_021DCC88, func_021DCCC8, func_021DCE28, func_021DCE70, func_021DCEA4, func_021DCF38, func_021DCFA8, func_021DCFD4, func_021DCFF4, func_021DD0E8, func_021DD10C, func_021DD218, func_021DD38C, func_021DD3F4, func_021DD4A4, func_021DD4D0, func_021DD500, func_021DD51C, func_021DD558, func_021DD5A8, func_021DD5D4, func_021DD620, func_021DD774, func_021DD874, func_021DD8BC, func_021DD8DC, func_021DD94C, func_021DD964, func_021DDAF0, func_021DDC28, func_021DDFBC, func_021DDFE8, func_021DE014, func_021DE030, func_021DE064, func_021DE080, func_021DE0AC, func_021DE0C0, func_021DE0E4, func_021DE114, func_021DE144, func_021DE1F8, func_021DE218, func_021DE238, func_021DE258, func_021DE290, func_021DE2D4, func_021DE34C, func_021DE368, func_021DE388, func_021DE5F4, func_021DE608, func_021DE684, func_021DE76C, func_021DE80C, func_021DE884, func_021DE8A8, func_021DE914
 * address:  0x021DC860
 * region:   ov171
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_02030EAC  0x02030EAC  arm
 *   func_020419E4 0x020419E4 arm
 *   func_0204A648 0x0204A648 arm
 *   PALANM_TransferPalettes 0x02021D50 thumb
 *   d_02FE0000 0x02FE0000 data a4
 *   BG_SYS_ClearGraphicsMemory  0x0204335C  arm
 *   func_020433E0  0x020433E0  arm
 *   d_021DEB20 0x021DEB20 data a4
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   d_021DEA50 0x021DEA50 data a4
 *   d_021DEAC0 0x021DEAC0 data a4
 *   d_021DEAA0 0x021DEAA0 data a4
 *   d_021DEB00 0x021DEB00 data a4
 *   d_021DEA60 0x021DEA60 data a4
 *   d_021DEA80 0x021DEA80 data a4
 *   d_021DEAE0 0x021DEAE0 data a4
 *   func_020403F4 0x020403F4 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020490F4  0x020490F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049238  0x02049238  arm
 *   func_0204162C  0x0204162C  arm
 *   func_02041090  0x02041090  arm
 *   func_02049B40  0x02049B40  arm
 *   func_02021518  0x02021518  thumb
 *   func_0202155C  0x0202155C  thumb
 *   func_020215A0  0x020215A0  thumb
 *   func_02021540  0x02021540  thumb
 *   PALANM_BlendChannelMask 0x02022004 thumb
 *   PALANM_SetAutoTransfer 0x02021EE4 thumb
 *   PALANM_GetFadeRequestBits 0x02021ED8 thumb
 *   func_0207D63C  0x0207D63C  arm
 *   func_02045B38 0x02045B38 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_02045808 0x02045808 arm
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_02045C04 0x02045C04 arm
 *   GAME_DATA_GetSaveBlock42 0x02012F68 thumb
 *   func_0200EC14 0x0200EC14 thumb
 *   func_0200EC98 0x0200EC98 thumb
 *   func_0200EC2C 0x0200EC2C thumb
 *   func_02012EBC 0x02012EBC thumb
 *   SAVE_CONTROL_LoadExtraSave 0x0200725C thumb
 *   func_020073D8 0x020073D8 thumb
 *   func_0200ECD0 0x0200ECD0 thumb
 *   func_0200ECC4 0x0200ECC4 thumb
 *   func_0200ED14 0x0200ED14 thumb
 *   func_0200ECF0 0x0200ECF0 thumb
 *   func_020072A4 0x020072A4 thumb
 *   d_021DEB5C 0x021DEB5C data a4
 *   func_02034AC4  0x02034AC4  arm
 *   func_02043534  0x02043534  arm
 *   func_020435F4  0x020435F4  arm
 *   func_0204363C  0x0204363C  arm
 *   func_0207D534  0x0207D534  arm
 *   func_0203D34C  0x0203D34C  arm
 *   ov067_id       0x00000043  data
 *   func_02034A5C 0x02034A5C arm
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_020221A4 0x020221A4 thumb
 *   func_020061E4 0x020061E4 thumb
 *   d_021DEB50 0x021DEB50 data a4
 *   func_0202208C 0x0202208C thumb
 *   _s32_div_f 0x0209C0A4 arm
 *   d_021DEB56 0x021DEB56 data
 *   func_02045088 0x02045088 arm
 *   func_020450F0 0x020450F0 arm
 *   func_020452E8 0x020452E8 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_02045748 0x02045748 arm
 *   func_021B6AE4 0x021B6AE4 thumb ov067
 *   func_0201D304 0x0201D304 thumb
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_020257D0 0x020257D0 thumb
 *   func_0201EE60 0x0201EE60 thumb
 *   func_0201EE0C 0x0201EE0C thumb
 *   func_0201EF34 0x0201EF34 thumb
 *   func_020456F8 0x020456F8 arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   CLACT_GetActorAutoAnim 0x0204B944 arm
 *   CLACT_AddActorAnimFrame 0x0204B8D4 arm
 *   func_0204A600 0x0204A600 arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   CLACT_SetActorAnimFrame 0x0204B8C4 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B98C  0x0204B98C  arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B454  0x0204B454  arm
 *   d_021DEB88 0x021DEB88 data a4
 *   func_0204A48C 0x0204A48C arm
 *   func_020275E4 0x020275E4 thumb
 *   func_02027618 0x02027618 thumb
 *   func_02027614 0x02027614 thumb
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B100 0x0204B100 arm
 *   d_021DEBA4 0x021DEBA4 data a4
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0202D7C8 0x0202D7C8 thumb
 *   func_0202D81C 0x0202D81C thumb
 *   func_0202D7D8 0x0202D7D8 thumb
 *   func_0202D898 0x0202D898 thumb
 *   func_02017ED8 0x02017ED8 thumb
 *   func_020216D4 0x020216D4 thumb
 *   d_021DEC04 0x021DEC04 data a4
 *   d_021DEC94 0x021DEC94 data a4
 *   func_0203F6D8 0x0203F6D8 arm
 *   func_0203F684 0x0203F684 arm
 *   _ll_mul 0x0209C054 arm
 *   CLACT_SetActorDrawPriority 0x0204B800 arm
 *   func_02025538 0x02025538 thumb
 *   func_02043678 0x02043678 arm
 *   func_020255A0 0x020255A0 thumb
 *   func_02025774 0x02025774 thumb
 *   func_0202570C 0x0202570C thumb
 *   func_020437AC 0x020437AC arm
 *   func_02025588 0x02025588 thumb
 *   func_02035C08 0x02035C08 arm
 *   func_021DE960 0x021DE960 thumb ov171
 *   func_0203633C 0x0203633C arm
 *   func_020362DC 0x020362DC arm
 *   d_021DED24 0x021DED24 data a4
 */
#include "../../matched/include/Obj24047.h"
#include "../../matched/include/Obj24048.h"
#include "../../matched/include/Obj24049.h"
#include "../../matched/include/Obj24050.h"
#include "../../matched/include/Obj08249.h"
#include "../../matched/include/Obj10658.h"
#include "../../matched/include/Obj14284.h"
#include "../../matched/include/Obj03850.h"
#include "../../matched/include/Obj14285.h"
#include "../../matched/include/Obj14286.h"
#include "../../matched/include/Obj14287.h"
#include "../../matched/include/Obj14288.h"
#include "../../matched/include/Obj00347.h"
#include "../../matched/include/Obj24051.h"
#include "../../matched/include/Obj24052.h"
#include "../../matched/include/Obj01420.h"
#include "../../matched/include/Obj10659.h"
#include "../../matched/include/Obj00142.h"
#include "../../matched/include/Obj24053.h"
#include "../../matched/include/Obj24054.h"
#include "../../matched/include/Obj03310.h"
#include "../../matched/include/Obj14289.h"
#include "../../matched/include/Obj14290.h"
#include "../../matched/include/Obj14291.h"
#include "../../matched/include/Obj00210.h"
#include "../../matched/include/Obj24055.h"
#include "../../matched/include/Obj05441.h"
#include "../../matched/include/Obj08250.h"
#include "../../matched/include/Obj10660.h"
#include "../../matched/include/Obj01756.h"
#include "../../matched/include/Obj08251.h"
#include "../../matched/include/Obj24058.h"
#include "../../matched/include/Obj08252.h"
#include "../../matched/include/Obj24059.h"
#include "../../matched/include/Obj10661.h"

#define PTR(p,n) (*(void **)((p)+(n)))
struct Obj0203159C;
struct S020315D4;
struct S02021D50;
struct DispVram;
struct PalAnmSlot;
struct Obj02021EE4;
struct GfFont;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct PrintSys;
struct Rec;
struct Big;
struct Ctrl;
struct Dst0200EC2C;
struct Out0200EC98;
struct Src0200EC2C;
struct Sub020072A4Ctrl;
struct Sub020073D8Ctrl;
struct P;
struct Descriptor;
struct Cfg;
struct CharBuf;
struct Obj;
struct StrObj;
struct Actor;
struct PtS;
struct Bank;
struct Node;
struct Bmp;
struct Grid;
struct Param;
struct Sys;
struct Obj020437AC;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct DispConfig {u32 w[4];};

struct BgTemplate {u32 w[8];};

struct S { void *f0; u16 f4; };

struct Ent_021DC860 { void *a; void *b; u8 pad[0x14]; };

struct Row { struct Ent_021DC860 ents[6]; u8 hdr[0x10]; u16 cnt; u16 cnt2; };

struct P { struct S *s; u8 pad[8]; struct Row rows[15]; u8 pad2[0xC5F - 0xB10]; u8 n; };

typedef signed int     s32;

typedef signed char s8;

typedef signed short s16;

typedef struct {s16 a,b;} Outputs;

typedef struct { char pad[0xb10]; s16 previous; char gap[10]; s16 current; } Angle;

struct RowBits { u8 pad[0x13]; unsigned char low:6; unsigned char kind:2; };

typedef struct Vec2 {s16 x,y;} Vec2;

struct Cfg {u8 pad_00[8];u8 unk_08,unk_09,unk_0a,unk_0b;u32 unk_0c;u16 unk_10,unk_12,unk_14,unk_16,unk_18,unk_1a;};

struct E { u32 w[6]; };

struct Ent_021DE368 { u32 f0; u32 f4; u32 f8; u32 fc; u16 f10; u8 f12; u8 a : 6; u8 b : 2; };

typedef struct Descriptor {
    void *image;
    u16 x, y;
    void *source;
    u32 mode;
    u8 a, b;
    u16 id;
    u32 extra;
} Descriptor;

extern void func_0203064C(u32,u32,u32);
extern void *func_0203159C(struct Obj0203159C*,u32,u32);
extern void func_02082BCC(void*,u32,u32);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern int func_020056A0(void (*)(void), int *, int);
extern int func_02030EAC(int);
extern void func_020419E4(void),func_0204A648(void);
extern void PALANM_TransferPalettes(struct S02021D50*);
extern void BG_SYS_ClearGraphicsMemory(u32 keep);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203F8F4(u16);
extern void func_0203FC28(struct DispConfig *);
extern void func_0203FCA0(u32,const struct BgTemplate *,u32);
extern void func_020434DC(u32,u32),func_02043598(u32,u32);
extern void func_020403F4(unsigned),func_0203F9B4(void);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049238(u8 *p);
extern u32 func_0204162C(int a);
extern void func_02041090(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void *func_02021518(u32 heap);
extern void func_0202155C(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void func_020215A0(struct PalAnmSlot *slots, u32 idx);
extern u32 func_02021540(void *a0);
extern void PALANM_BlendChannelMask(unsigned, unsigned, u16, unsigned, unsigned);
extern void PALANM_SetAutoTransfer(struct Obj02021EE4 *o, int v);
extern u32 PALANM_GetFadeRequestBits(const char*);
extern void func_0207D63C(int, int, int, int, int);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 func_0201C440(void *p);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201C4C0(struct PrintSys *p);
extern unsigned int func_0201ED04(struct WordSet *p);
extern u32 func_0201D83C(void *ptr);
extern u32 func_02045C04(struct Rec *rec);
extern void *GAME_DATA_GetSaveBlock42(void **h);
extern int func_0200EC14(char *p);
extern void func_0200EC98(const u8 *o, struct Out0200EC98 *out);
extern void func_0200EC2C(const struct Src0200EC2C *base, int idx, struct Dst0200EC2C *dst);
extern void *func_02012EBC(struct Big *p);
extern u32 SAVE_CONTROL_LoadExtraSave(struct Ctrl *ctrl, u32 id, u8 heap);
extern void *func_020073D8(struct Sub020073D8Ctrl *ctrl, u32 id, u32 v);
extern int func_0200ECD0(char *o, int idx);
extern u32 func_0200ECC4(char *o, u32 n);
extern void func_0200ED14(u8 *o, int idx, void *out);
extern void func_0200ECF0(void *a0, u32 a1, void *a2, void *a3);
extern void func_020072A4(struct Sub020072A4Ctrl *ctrl, u32 id);
extern int func_02034AC4(s32 handle);
extern void func_02043534(u32 planes);
extern void func_020435F4(u32 planes);
extern void func_0204363C(u32 swap);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern void func_0203D34C(u32 a, u32 b);
extern void func_02034A5C(int);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern u32 func_020221A4(void);
extern void func_020061E4(u32 a);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_0202208C(void*,u32,u32,u32,u32,u32,u32);
extern int _s32_div_f(int, int);
extern void func_02045088(u16 heapId);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_020450C8(void);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void *func_02045770(struct Descriptor *);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u8 func_02045748(struct Descriptor *p);
extern void func_021B6AE4(u8 *p, void *a, u16 b, u16 c, u32 s0, u32 s1, u16 s2, u32 s3);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_0201C7D0(void *,s16,s16,void *,void *,u16);
extern void func_020257D0(struct Obj *o);
extern void func_0201EE60(struct WordSet *p, u32 i, u16 v);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_0201EF34(struct WordSet *p, u32 i, u32 v);
extern void func_020456F8(struct Descriptor *);
extern void func_0204A5AC(void);
extern u32 CLACT_GetActorAutoAnim(struct Obj *);
extern void CLACT_AddActorAnimFrame(struct Obj *,u32);
extern void func_0204A600(void);
extern void func_0204B3DC(struct Obj *, unsigned int);
extern void CLACT_SetActorAnimFrame(struct Obj *,u32);
extern void func_0204B878(struct Obj *,u16);
extern void func_0204B92C(struct Obj *,u32);
extern u32 func_0204B98C(struct Actor *a);
extern void func_0204B404(struct Obj *,const struct Vec2 *,u32);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204A48C(const struct Cfg *,u32,u32);
extern u32 func_020275E4(void);
extern u32 func_02027618(void);
extern u32 func_02027614(void);
extern u32 func_0202761C(u32 a);
extern u32 func_02027620(u32 a);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_0204A8D4(u32 v);
extern void func_0204ADA4(u32);
extern void func_0204AFD8(u32);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B3B4(struct Obj *p);
extern u32 func_0204B1CC(struct Bank *bank);
extern int func_0202D7C8(int a0);
extern u32 func_0202D81C(u32, u32, u32, u32, u32, u32, u32, u32, u32, u16);
extern u32 func_0202D7D8(u32, u32, u32, u32, u32, u32, u32, u32, u16, u16);
extern u32 func_0202D898(u32, u32, u32, u32, u32, u32, u32, u32, u16);
extern u32 func_02017ED8(u32, u32);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern s16 func_0203F6D8(s32 x);
extern short func_0203F684(unsigned short x);
extern void CLACT_SetActorDrawPriority(struct Node *node, u32 val);
extern void *func_02025538(unsigned int a0, void *a1);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern struct Grid *func_020255A0(struct Sys *sys, const struct Param *param);
extern void func_02025774(u8 *g, u32 a);
extern void func_0202570C(struct Grid *g);
extern void func_020437AC(struct Obj020437AC *p);
extern void func_02025588(void *);
extern int func_02035C08(const void *);
extern int func_021DE960(char *);
extern unsigned int func_0203633C(void);
extern u32 func_020362DC(void);
int func_021DC860(struct Obj0203159C*p,void*unused,u32 n);
int func_021DC894(int a, int b, int c, int d);
int func_021DC8A8(void *p);
void func_021DC8B8(int *p);
int func_021DC8D4(int *p);
void func_021DC8E4(void*unused,const u8*p);
void func_021DC910(void);
void *func_021DC924(void);
void func_021DC92C(void);
void func_021DCA40(void);
void func_021DCA7C(void);
void func_021DCB70(int *p);
void func_021DCB8C(int *p);
void func_021DCBA4(char *p);
int func_021DCBE8(u8*p);
void func_021DCC0C(void);
void func_021DCC24(char *p);
void func_021DCC88(char *p);
void func_021DCCC8(struct P *p);
void func_021DCE28(char *p);
int func_021DCE70(u8*p);
void func_021DCEA4(u8 *p);
int func_021DCF38(int *p);
int func_021DCFA8(u8*p);
u32 func_021DCFD4(char *p);
int func_021DCFF4(char *p);
int func_021DD0E8(u8*p);
int func_021DD10C(char *p);
int func_021DD218(char *p);
int func_021DD38C(char *p);
int func_021DD3F4(char *p);
int func_021DD498(char *p);
int func_021DD4A4(u8*p,int v);
int func_021DD4D0(u8 *p, int value);
int func_021DD500(char *p, int i, int n, int v);
int func_021DD51C(char *p, s8 step);
int func_021DD558(char *p, s8 step);
int func_021DD5A8(u8 *p,int i);
u8 func_021DD5D4(char *p, s8 i, int target, s8 step);
void func_021DD620(char *p, int step);
int func_021DD774(char *p);
void func_021DD874(char *p);
void func_021DD8BC(int *p);
void func_021DD8DC(char *p);
void func_021DD94C(int *p);
void func_021DD964(u8 *p);
void func_021DDAF0(u8 *p);
void func_021DDC28(u8 *p);
void func_021DDFBC(u8 *p);
void func_021DDFE8(u8 *p);
void func_021DE014(int *p);
void func_021DE030(u8 *p);
void func_021DE064(int *p, int i, int a);
void func_021DE080(u8 *p, int i, int value);
int func_021DE0AC(int *p, int i);
void func_021DE0C0(u8 *p, int i, int x, int y);
void func_021DE0E4(u8 *obj, int i, s16 *out1, s16 *out2);
void func_021DE114(u8 *p);
void func_021DE144(char *p);
void func_021DE1F8(char *p, int i);
void func_021DE218(char *p,int i);
void func_021DE238(char *p,int i);
void func_021DE258(char *p);
struct Obj *func_021DE290(char *p, const char *q);
void func_021DE2D4(char *p);
void func_021DE34C(char *p, int i);
void func_021DE368(char *p);
void func_021DE388(char *p);
int func_021DE5F4(char *p);
void func_021DE608(char *p, int i, int angle);
void func_021DE684(u8 *p);
void func_021DE76C(u8 *p, int mode);
void func_021DE80C(char *p);
void func_021DE884(int *p);
int func_021DE8A8(char *p);
int func_021DE914(char *p);
extern u8 d_02FE0000[];
extern char d_021DEB20[];
extern const struct DispConfig d_021DEA50;
extern const struct BgTemplate d_021DEAC0,d_021DEAA0,d_021DEB00,d_021DEA60,d_021DEA80,d_021DEAE0;
extern u8 d_021DEB5C[];
extern u8 ov067_id[];
extern const u8 d_021DEB50[];
extern const u8 d_021DEB56[];
extern const struct Cfg d_021DEB88;
extern const char d_021DEBA4[];
extern const struct E d_021DEC04[];
extern const struct E d_021DEC94[];
extern const char d_021DED24[];





int func_021DC860(struct Obj0203159C*p,void*unused,u32 n){u32*q;func_0203064C(1,0x8c,0x60000);q=func_0203159C(p,0xc78,0x8c);func_02082BCC(q,0,0xc78);*q=n;return 1;}






int func_021DC894(int a, int b, int c, int d)
{
    if (func_021DCE70((u8 *)d))
        return 0;
    return 1;
}






int func_021DC8A8(void *p)
{
    func_020315D4(p);
    func_020306F0(0x8c);
    return 1;
}






void func_021DC8B8(int *p)
{
    ((struct Obj24047 *)p)->fB28 = func_020056A0((void (*)(void))func_021DC8E4, p, 0);
}






int func_021DC8D4(int *p)
{
    return func_02030EAC(((struct Obj24048 *)p)->fB28);
}





/*
 * lever: enum address base preserves split pools; halfword offset closes r1/r2 allocation; const input retains reads.
 */
void func_021DC8E4(void*unused,const u8*p){enum Offset{check=0x3ff8};u16 off;enum Base{start=0x02fe0000};enum Base base;func_020419E4();func_0204A648();PALANM_TransferPalettes(*(struct S02021D50*const *)&((struct Obj24049 *)p)->fB30);base=start;off=check;*(u32*)((u32)base+off)|=1;}






void func_021DC910(void)
{
    BG_SYS_ClearGraphicsMemory(0);
    func_020433E0((const struct DispVram *)0x021DEB20);
}





void *func_021DC924(void){return d_021DEB20;}





void func_021DC92C(void)
{
    struct DispConfig d;
    struct BgTemplate a,b,c,e,f,g;
    func_0203F8F4(140);
    d=d_021DEA50;func_0203FC28(&d);
    a=d_021DEAC0;func_0203FCA0(0,&a,0);
    b=d_021DEAA0;func_0203FCA0(1,&b,0);
    c=d_021DEB00;func_0203FCA0(2,&c,0);
    e=d_021DEA60;func_0203FCA0(3,&e,0);
    f=d_021DEA80;func_0203FCA0(4,&f,0);
    g=d_021DEAE0;func_0203FCA0(5,&g,0);
    func_020434DC(13,1);func_02043598(3,1);
}





void func_021DCA40(void){func_020434DC(15,0);func_02043598(3,0);func_020403F4(5);func_020403F4(4);func_020403F4(3);func_020403F4(2);func_020403F4(1);func_020403F4(0);func_0203F9B4();}






void func_021DCA7C(void)
{
    u8 *p = func_020490F4(0xd5, 0x808c);

    func_02049B68(p, 1, 0, 0, 0x80, 0x8c);
    func_02049B68(p, 6, 4, 0, 0x40, 0x8c);
    func_02049658(p, 0, 0, 0, 0, 1, 0x8c);
    func_02049658(p, 5, 4, 0, 0, 1, 0x8c);
    func_020498F4(p, 2, 0, 0, 0, 1, 0x8c);
    func_020498F4(p, 3, 1, 0, 0, 1, 0x8c);
    func_020498F4(p, 4, 2, 0, 0, 1, 0x8c);
    func_020498F4(p, 7, 4, 0, 0, 1, 0x8c);
    func_02049238(p);
    func_02041090(3, func_0204162C(0) + 0x540, 0, 0x15, 0x20, 3);
    func_02049B40(0x17, 5, 0, 0x1e0, 0x20, 0x8c);
    func_02049B40(0x17, 5, 4, 0x1e0, 0x20, 0x8c);
}






void func_021DCB70(int *p)
{
    int x = (int)func_02021518(0x8c);

    ((struct Obj24050 *)p)->fB30 = x;
    func_0202155C((struct PalAnmSlot *)x, 2, 0x200, 0x8c);
}






void func_021DCB8C(int *p)
{
    func_020215A0((struct PalAnmSlot *)(((struct Obj08249 *)p)->fB30), 2);
    func_02021540((void *)(((struct Obj08249 *)p)->fB30));
}





void func_021DCBA4(char *p)
{
    unsigned i;
    for (i=0; i<6; i++)
        PALANM_BlendChannelMask(((struct Obj10658 *)p)->fB30, 2, (1<<i)|(1<<(i+6)), (unsigned char)p[0xb3a+i], 0);
    PALANM_SetAutoTransfer((struct Obj02021EE4 *)(((struct Obj10658 *)p)->fB30), 1);
}





int func_021DCBE8(u8*p){if(PALANM_GetFadeRequestBits(*(char* *)&((struct Obj14284 *)p)->fB30))return 1;PALANM_SetAutoTransfer((struct Obj02021EE4 *)(*(u32 *)&((struct Obj14284 *)p)->fB30),0);return 0;}






void func_021DCC0C(void)
{
    func_0207D63C(0x04000050, 6, 0x11, 0x10, 8);
}





void func_021DCC24(char *p)
{
    ((struct Obj03850 *)p)->fB60=func_02045B38(0,2,0x55,0x8c);
    ((struct Obj03850 *)p)->fB58=func_0201D7EC(0x17,0,0,0,0x8c);
    ((struct Obj03850 *)p)->fB5C=func_0201D7EC(0x17,3,0,0,0x8c);
    ((struct Obj03850 *)p)->fB64=func_0201EC64(0x8c);
    ((struct Obj03850 *)p)->fB6C=(void *)func_0201C440((void *)0x8c);
    ((struct Obj03850 *)p)->fB68=func_020457B0(0x400,0x8c);
}





void func_021DCC88(char *p)
{
    func_02045808(PTR(p,0xb68));
    func_0201C4C0(PTR(p,0xb6c));
    func_0201ED04(PTR(p,0xb64));
    func_0201D83C(PTR(p,0xb5c));
    func_0201D83C(PTR(p,0xb58));
    func_02045C04(PTR(p,0xb60));
}






/*
 * 2026-10-04 (wD1 lane18): control flow and registers match (r6=p, r7=row offset, p+0xC
 * temp hoisted after the guard). Residue: stack slot order of the spilled locals.
 * Original frame: temp d@0, i@4, o@8, c@0xc, j@0x10; compiled: c@0, o@4, i@8, d@0xc, j@0x10.
 * Declaration order did not change the slot order. Also the p+0xB4 operand: original
 * computes (p+0xB4) fresh then +r; compiled adds r first. Spelling p+0xB4+r hoists p+0xB4
 * into a spill (worse). Callee prototypes guessed (all thumb except func_020457B0).
 * 2026-10-04 (wD2 lane19): original temps by slot (low to high): d(p+0xC+r) @0, e(p+i*0xBC) @4, o @8, c @0xc, j @0x10.
 *   Declaring j,c,o,e,d,i,k at function scope reorders e/o/c but the d temp stays at 0xC; hoisting d before the k loop or
 *   `(u8*)((u32)(p+0xB4)+(u32)r)` grows the frame to 0x18 (worse). Residue: d temp slot and (p+0xB4)+r operand order.
 * 2026-10-05 (wD4 lane 08): DIFF, size now right (352 bytes), 49 diff lines. Found: the inner k loop has an explicit
 *   guard `if (count != 0) { for (...) ...; p[0xC5F]++; }` (original cmp r0,#0; beq past the ++, then the for guard).
 *   Residue: (1) stack slots (original d@0 i@4 o@8 c@0xc j@0x10, draft c@0 o@4 i@8 d@0xc); (2) the original forms
 *   (p+0xB4)+r and (p+0xC)+r (d computed once after the guard), the draft forms p+r first; p+0xB4+r spelling hoists both
 *   out of the j loop (364 bytes); (3) the original loads the 0xC5F pool word once for the ++, the draft twice.
 *   Tried: a Row struct array at p+0xC (stride 0xBC; ents[6] of 0x1c, hdr at +0xA8, cnt +0xB8): one pool load for the
 *   ++ but j*0xBC is computed twice (364 bytes); all accesses through the Row struct is worse (171 lines).
 * 2026-10-05 (wD5 lane 11): MATCH, all 352 bytes equal. Fix: a real struct (Row array at p+0xC, stride 0xBC:
 *   ents[6] of 0x1c, hdr[0x10] at +0xA8, cnt/cnt2 u16 at +0xB8/+0xBA; count byte at 0xC5F). &p->rows[j].hdr gives
 *   (p+0xB4)+r, &p->rows[j].ents[k] gives the hoisted (p+0xC)+r temp in the lowest slot, and locals j,c,o,i,k
 *   in that order give the frame. Only residue: func_0200ED14 (arm9, thumb) had no label. It is now filed EXACT
 *   as src/matched/arm9/func_0200ED14.c; once its shard exists this file should verify EXACT.
 */
void func_021DCCC8(struct P *p)
{
    u16 j;
    void *c;
    void *o;
    u16 i;
    u16 k;
    struct S *s;
    for (i = 0; i < 15; i++) {
        for (k = 0; k < 6; k++) {
            p->rows[i].ents[k].a = func_020457B0(0x20, 0x8c);
            p->rows[i].ents[k].b = func_020457B0(0x20, 0x8c);
        }
    }
    s = p->s;
    if (s->f4 == 0) {
        void *h = GAME_DATA_GetSaveBlock42(s->f0);
        p->rows[0].cnt = func_0200EC14(h);
        func_0200EC98(h, (struct Out0200EC98 *)p->rows[0].hdr);
        for (k = 0; k < p->rows[0].cnt; k++)
            func_0200EC2C(h, k, (struct Dst0200EC2C *)(&p->rows[0].ents[k]));
        p->n = 1;
    } else {
        u32 id;
        c = func_02012EBC(s->f0);
        id = 8;
        if (SAVE_CONTROL_LoadExtraSave(c, id, 0x8c) == 1) {
            o = func_020073D8(c, id, 0);
            if (o) {
                for (j = 0; j < 15; j++) {
                    p->rows[j].cnt = func_0200ECD0(o, j);
                    p->rows[j].cnt2 = func_0200ECC4(o, j);
                    func_0200ED14(o, j, p->rows[j].hdr);
                    if (p->rows[j].cnt != 0) {
                        for (k = 0; k < p->rows[j].cnt; k++)
                            func_0200ECF0(o, j, (void *)k, &p->rows[j].ents[k]);
                        p->n++;
                    }
                }
            }
        }
        func_020072A4(c, id);
    }
}





void func_021DCE28(char *p)
{
    unsigned short i, j;
    char *row;
    char *cell;
    for(i=0;i<15;i++) {
        row=p+i*0xbc;
        for(j=0;j<6;j++) {
            cell=row+j*0x1c;
            func_02045808(((struct Obj14285 *)cell)->fC);
            func_02045808(((struct Obj14285 *)cell)->f10);
        }
    }
}





int func_021DCE70(u8*p){typedef int(*Fn)(u8*);((struct Obj14286 *)p)->fC6C=(*(Fn*)((u32)d_021DEB5C+*(u32*)(p+0xc6c)*4))(p);if(((struct Obj14286 *)p)->fC6C==11)return 0;func_021DE030(p);func_021DD8DC((char*)p);return 1;}






void func_021DCEA4(u8 *p)
{
    func_02034AC4((int)ov067_id);
    func_02043534(0);
    func_020435F4(0);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    func_0204363C(0);
    func_0207D534((void *)0x0400006c, -0x10);
    func_0207D534((void *)0x0400106c, -0x10);
    func_021DCCC8((struct P *)p);
    func_021DC910();
    func_021DC92C();
    func_021DCA7C();
    func_021DCB70((int *)p);
    func_021DCC24((char *)p);
    func_021DD874((char *)p);
    func_021DDFE8(p);
    func_021DD0E8(p);
    func_021DCC0C();
    func_0203D34C(1, 0x8c);
    func_021DC8B8((int *)p);
    func_021DD4A4(p, 4);
}





int func_021DCF38(int *p)
{
    func_021DC8D4(p);
    func_021DE014(p);
    func_021DD8BC(p);
    func_021DCC88((char *)p);
    func_021DCB8C(p);
    func_021DCA40();
    func_021DCE28((char *)p);
    func_0207D534((void *)0x0400006c, -16);
    func_0207D534((void *)0x0400106c, -16);
    *(unsigned short *)0x04000050 = 0;
    *(unsigned short *)0x04001050 = 0;
    func_02043534(0);
    func_020435F4(0);
    func_02034A5C((int)ov067_id);
    return 11;
}





int func_021DCFA8(u8*p){if(func_0201C6B4(*(void* *)&((struct Obj14287 *)p)->fB6C)==1 && func_020221A4()==1)return ((struct Obj14287 *)p)->fC74;return 2;}






u32 func_021DCFD4(char *p)
{
    if (func_021DE0AC((int *)p, ((struct Obj14288 *)p)->fC64) == 0)
        return ((struct Obj14288 *)p)->fC68;
    return 3;
}





int func_021DCFF4(char *p) {
    int choice;
    if (!func_0201C6B4(((struct Obj00347 *)p)->fB6C)) return 4;
    choice=func_021DE8A8(p);
    switch(choice) {
    case 0:
        if (func_021DD51C(p,-1)==1) {
            func_020061E4(0x54b);
            return func_021DD500(p,12,12,5);
        }
        break;
    case 1:
        if (func_021DD51C(p,1)==1) {
            func_020061E4(0x54b);
            return func_021DD500(p,13,13,5);
        }
        break;
    case 2:
        func_020061E4(0x556);
        ((struct Obj24051 *)(*(char * *)&((struct Obj00347 *)p)->f0))->f6=1;
        return func_021DD500(p,14,8,10);
    case 3:
        func_020061E4(0x551);
        ((struct Obj24052 *)(*(char * *)&((struct Obj00347 *)p)->f0))->f6=0;
        return func_021DD500(p,15,9,10);
    case 4:
        func_020061E4(0x54c);
        ((struct Obj00347 *)p)->fC5D=((struct Obj00347 *)p)->fC5C;
        return 6;
    case 5: case 6: case 7: case 8: case 9: case 10:
        ((struct Obj00347 *)p)->fC5D=choice-5;
        func_020061E4(0x54c);
        return 6;
    }
    return 4;
}





int func_021DD0E8(u8*p){p[0xc5c]=0;func_021DE388((char *)p);func_021DD964(p);func_021DDAF0(p);return 4;}





int func_021DD10C(char *p) {
    s8 old;
    switch (((struct Obj01420 *)p)->fC70) {
    case 0:
        func_021DE080((u8 *)p,12,18);
        func_021DE080((u8 *)p,13,19);
        func_021DE080((u8 *)p,14,14);
        func_020434DC(2,1);
        func_021DE76C((u8 *)p,1);
        func_021DCBA4(p);
        (((struct Obj01420 *)p)->fC70)++;
        break;
    case 1:
        if (!func_021DCBE8((u8 *)p)) {
            ((struct Obj01420 *)p)->fC70=0;
            old=((struct Obj01420 *)p)->fC5C;
            if (((struct Obj01420 *)p)->fC5D==old) {
                ((struct Obj01420 *)p)->fC5C=((struct Obj01420 *)p)->fC5D;
                func_021DDC28((u8 *)p);
                return 7;
            }
            ((struct Obj01420 *)p)->fC5C=((struct Obj01420 *)p)->fC5D;
            if (func_021DD5A8((u8 *)p,((struct Obj01420 *)p)->fC5D)==1) {
                ((struct Obj01420 *)p)->fC61=-d_021DEB50[*(u16 *)(p+((struct Obj01420 *)p)->fC5E*0xbc+0xc4)-1];
                func_021DD620(p,(s8)(-func_021DD5D4(p,old,((struct Obj01420 *)p)->fC5D,1)));
            } else {
                ((struct Obj01420 *)p)->fC61=d_021DEB50[*(u16 *)(p+((struct Obj01420 *)p)->fC5E*0xbc+0xc4)-1];
                func_021DD620(p,(s8)func_021DD5D4(p,old,((struct Obj01420 *)p)->fC5D,-1));
            }
            func_020061E4(0x57b);
            return 9;
        }
        break;
    }
    return 6;
}





int func_021DD218(char *p) {
    int choice;
    s8 old;
    if (!func_0201C6B4(((struct Obj00347 *)p)->fB6C)) return 7;
    choice = func_021DE914(p);
    switch (choice) {
    case 0:
        if (func_021DD558(p, 1) == 1) {
            ((struct Obj00347 *)p)->fC61 = -d_021DEB50[*(u16 *)(p + ((struct Obj00347 *)p)->fC5E * 0xbc + 0xc4) - 1];
            func_021DD620(p, (s8)(-1));
            func_020061E4(0x57b);
            return 9;
        }
        break;
    case 1:
        if (func_021DD558(p, -1) == 1) {
            ((struct Obj00347 *)p)->fC61 = d_021DEB50[*(u16 *)(p + ((struct Obj00347 *)p)->fC5E * 0xbc + 0xc4) - 1];
            func_021DD620(p, (s8)1);
            func_020061E4(0x57b);
            return 9;
        }
        break;
    case 3:
        func_020061E4(0x551);
        return func_021DD500(p, 15, 9, 8);
    case 5: case 6: case 7: case 8: case 9: case 10:
        old = ((struct Obj00347 *)p)->fC5C;
        if (choice - 5 == old) break;
        ((struct Obj00347 *)p)->fC5C = choice - 5;
        if (func_021DD5A8((u8 *)p, choice - 5) == 1) {
            ((struct Obj00347 *)p)->fC61 = -d_021DEB50[*(u16 *)(p + ((struct Obj00347 *)p)->fC5E * 0xbc + 0xc4) - 1];
            func_021DD620(p, (s8)(-func_021DD5D4(p, old, (s8)(choice - 5), 1)));
        } else {
            ((struct Obj00347 *)p)->fC61 = d_021DEB50[*(u16 *)(p + ((struct Obj00347 *)p)->fC5E * 0xbc + 0xc4) - 1];
            func_021DD620(p, (s8)func_021DD5D4(p, old, (s8)(choice - 5), -1));
        }
        func_020061E4(0x57b);
        return 9;
    }
    return 7;
}





int func_021DD38C(char *p)
{
    switch (((struct Obj10659 *)p)->fC70) {
    case 0:
        func_021DE76C((unsigned char *)p, 0);
        func_021DCBA4(p);
        func_020434DC(2, 0);
        ++((struct Obj10659 *)p)->fC70;
        break;
    case 1:
        if (!func_021DCBE8((unsigned char *)p)) {
            func_021DE080((u8 *)p, 12, 4);
            func_021DE080((u8 *)p, 13, 5);
            func_021DE080((u8 *)p, 14, 0);
            func_021DDFBC((u8 *)p);
            ((struct Obj10659 *)p)->fC70 = 0;
            return 4;
        }
        break;
    }
    return 8;
}





int func_021DD3F4(char *p)
{
    unsigned i;
    if (!func_021DD774(p)) {
        for (i = 0; i < *(u16 *)(p + ((struct Obj00142 *)p)->fC5E * 0xbc + 0xc4); ++i)
            *(u8 *)(p + i + 0xb34) = *(u8 *)(p + i + 0xb40);
        func_021DCBE8((u8 *)p);
        func_021DDC28((u8 *)p);
        return 7;
    } else {
        for (i = 0; i < *(u16 *)(p + ((struct Obj00142 *)p)->fC5E * 0xbc + 0xc4); ++i) {
            if (*(u8 *)(p + i + 0xb3a) > *(u8 *)(p + i + 0xb40))
                --*(u8 *)(p + i + 0xb3a);
            else if (*(u8 *)(p + i + 0xb3a) < *(u8 *)(p + i + 0xb40))
                ++*(u8 *)(p + i + 0xb3a);
        }
        func_021DCBA4(p);
        return 9;
    }
}





int func_021DD498(char *p)
{
    return func_021DD4D0((u8 *)p, 1);
}





int func_021DD4A4(u8*p,int v){func_0202208C(0,1,1,0,6,1,0x8c);((struct Obj24053 *)p)->fC74=v;return 2;}





int func_021DD4D0(u8 *p, int value)
{
    func_0202208C(0,0,0,0,6,1,140);
    ((struct Obj24054 *)p)->fC74=value;
    return 2;
}





/*
 * trailing: larger followers 0x021DD51C and 0x021DD558 have separate files.
 */
int func_021DD500(char *p, int i, int n, int v)
{
    func_021DE080((u8 *)p, i, n);
    ((struct Obj00347 *)p)->fC64 = i;
    ((struct Obj00347 *)p)->fC68 = v;
    return 3;
}





/*
 * lever: signed byte step avoids an extra truncation before the addition.
 */
int func_021DD51C(char *p, s8 step)
{
    int old;
    old = ((struct Obj00347 *)p)->fC5E;
    ((struct Obj00347 *)p)->fC5E += step;
    if (((struct Obj00347 *)p)->fC5E < 0)
        ((struct Obj00347 *)p)->fC5E = ((struct Obj00347 *)p)->fC5F - 1;
    else if (((struct Obj00347 *)p)->fC5E >= ((struct Obj00347 *)p)->fC5F)
        ((struct Obj00347 *)p)->fC5E = 0;
    if (((struct Obj00347 *)p)->fC5E != old)
        return 1;
    return 0;
}





int func_021DD558(char *p, s8 step)
{
    int old;
    old = ((struct Obj03310 *)p)->fC5C;
    ((struct Obj03310 *)p)->fC5C += step;
    if (((struct Obj03310 *)p)->fC5C < 0)
        ((struct Obj03310 *)p)->fC5C = *(u16 *)(p + ((struct Obj03310 *)p)->fC5E * 0xbc + 0xc4) - 1;
    else if (((struct Obj03310 *)p)->fC5C >= *(u16 *)(p + ((struct Obj03310 *)p)->fC5E * 0xbc + 0xc4))
        ((struct Obj03310 *)p)->fC5C = 0;
    if (((struct Obj03310 *)p)->fC5C != old)
        return 1;
    return 0;
}





int func_021DD5A8(u8 *p,int i)
{
    Outputs out;
    func_021DE0E4(p,(int)((u32)i+(u32)func_021DE5F4((char *)p)), &out.b, &out.a);
    if(out.b<128)return 1;
    return 0;
}





/*
 * lever: signed byte step avoids an extra entry truncation.
 */
u8 func_021DD5D4(char *p, s8 i, int target, s8 step)
{
    u8 count;
    count = 1;
    do {
        i += step;
        if (i < 0)
            i = *(u16 *)(p + ((struct Obj14289 *)p)->fC5E * 0xbc + 0xc4) - 1;
        else if (i >= *(u16 *)(p + ((struct Obj14289 *)p)->fC5E * 0xbc + 0xc4))
            i = 0;
        if (i == target)
            break;
        count++;
    } while (count < 6);
    return count;
}






/*
 * lever: A u16 count preserves the word spill at sp+0; bind the final quotient
 *   before multiplying. Explicit runtime calls preserve the zero divisor path.
 */
void func_021DD620(char *p, int step) {
    s16 dst = ((struct Obj00347 *)p)->fC5C;
    s16 src = dst + step;
    unsigned i;
    int angle;
    u16 count;
    if (src < 0) {
        count = *(u16 *)(p + ((struct Obj00347 *)p)->fC5E * 0xbc + 0xc4);
        src += (s16)count;
    } else {
        count = *(u16 *)(p + ((struct Obj00347 *)p)->fC5E * 0xbc + 0xc4);
        if (src >= count) src -= (s16)count;
    }
    for (i = 0; i < (unsigned)count; i++) {
        *(s16 *)(p + dst * 2 + 0xb1c) = *(s16 *)(p + src * 2 + 0xb10);
        *(u8 *)(p + dst + 0xb40) = *(u8 *)(p + src + 0xb34);
        dst += (s16)_s32_div_f(step, step < 0 ? -step : step);
        if (dst < 0) {
            count = *(u16 *)(p + ((struct Obj00347 *)p)->fC5E * 0xbc + 0xc4);
            dst = count - 1;
        } else {
            count = *(u16 *)(p + ((struct Obj00347 *)p)->fC5E * 0xbc + 0xc4);
            if (dst >= count) dst = 0;
        }
        src += (s16)_s32_div_f(step, step < 0 ? -step : step);
        if (src < 0) src = count - 1;
        else if (src >= count) src = 0;
    }
    angle = ((struct Obj00347 *)p)->fC61;
    if (angle < 0) angle = -angle;
    if (step < 0) step = -step;
    angle = _s32_div_f(d_021DEB56[count - 1], angle);
    ((struct Obj00347 *)p)->fC62 = angle * step;
}





/*
 * lever: Access the far halfwords as struct members; cache only the guard value, and retain field updates and reads.
 */
int func_021DD774(char *p) {
    int base;
    unsigned i;
    Angle *a;
    int angle;
    base=func_021DE5F4(p);
    if (((struct Obj00142 *)p)->fC62==0) {
        for(i=0;i<*(u16 *)(p+((struct Obj00142 *)p)->fC5E*0xbc+0xc4);i++) {
            a=(Angle *)(p+i*2);
            a->previous=a->current;
            func_021DE608(p,base+i,a->previous);
        }
        func_021DE684((u8 *)p);
        return 0;
    } else {
        for(i=0;i<*(u16 *)(p+((struct Obj00142 *)p)->fC5E*0xbc+0xc4);i++) {
            a=(Angle *)(p+i*2);
            a->previous+=((struct Obj00142 *)p)->fC61;
            angle=a->previous;
            if (angle<0) a->previous+=360;
            else if (angle>=360) a->previous-=360;
            func_021DE608(p,base+i,a->previous);
        }
        func_021DE684((u8 *)p);
        (((struct Obj00142 *)p)->fC62)--;
        return 1;
    }
}





/*
 * lever: the first creation call passes 3 in r0, shared with its stack argument.
 */
void func_021DD874(char *p)
{
    func_02045088(0x8c);
    ((struct Obj03850 *)p)->fB48 = func_020450F0(3, 1, 0, 30, 2, 3, 1);
    ((struct Obj03850 *)p)->fB50 = func_020450F0(5, 4, 7, 24, 15, 1, 1);
}





void func_021DD8BC(int *p)
{
    func_020452E8(*(struct Descriptor * *)&((struct Obj08249 *)p)->fB48);
    func_020452E8(*(struct Descriptor * *)&((struct Obj08249 *)p)->fB50);
    func_020450C8();
}





/*
 * lever: offset locals carry both their initial and replacement constants.
 * note 2026-10-05 (wave D9r lane 131): removed the 4 dead first assignments
 * (`a = 0xb6c;` before `a = 0xb48;`; `b = 0xb6c;` before `b = 0xb4c;` and 2
 * more). Game code has no line table, so these were stand-ins. The plain
 * single assignment gives EXACT in --lang c99 and --lang c: the output bytes
 * do not change. Older text in this header that asks for the double
 * assignment is superseded.
 */
void func_021DD8DC(char *p)
{
    int a, b, c, d;
    unsigned i;
    int obj;
    char *q;
    func_0201C4E4((struct PrintSys *)(((struct Obj14290 *)p)->fB6C));
    a = 0xb48;
    b = 0xb4c;
    c = 0xb48;
    d = 0xb4c;
    for (i = 0; i < 2; ++i) {
        obj = ((struct Obj14290 *)p)->fB6C;
        q = p + i * 8;
        if (*(unsigned char *)(q + d)) {
            if (!func_0201C6C4((struct PrintSys *)obj, (void *)((int)func_02045770((struct Descriptor *)*(int *)(q + c))))) {
                func_02045334((struct Descriptor *)*(int *)(q + a));
                *(unsigned char *)(q + b) = 0;
            }
        }
    }
}






void func_021DD94C(int *p)
{
    func_02045374((struct Cfg *)(((struct Obj14291 *)p)->f0));
    func_02041B6C(func_02045730((struct Descriptor *)(((struct Obj14291 *)p)->f0)));
}





void func_021DD964(u8 *p)
{
    u32 offset;
    u8 *group;
    void *s0,*s1,*s2;
    u32 width;
    offset=((struct Obj00210 *)p)->fC5E*0xbc;
    group=p+0xc;
    func_02043B5C(func_02045770(((struct Obj00210 *)p)->fB48),0);
    if(((struct Obj24055 *)(*(u8 * *)&((struct Obj00210 *)p)->f0))->f4==0) {
        s0=func_02045EC0(((struct Obj00210 *)p)->fB60,0);
        func_021B6AE4(p+0xb48,(void *)(((struct Obj00210 *)p)->fB6C),0,0,(u32)s0,*(u32 *)&((struct Obj00210 *)p)->fB58,0x440,0);
        func_02045808(s0);
    } else {
        s1=func_02045EC0(((struct Obj00210 *)p)->fB60,1);
        func_0201EFA4(((struct Obj00210 *)p)->fB64,0,*(u16 *)(group+offset+0xba),4,0,1);
        func_0201F250(((struct Obj00210 *)p)->fB64,((struct Obj00210 *)p)->fB68,s1);
        func_021B6AE4(p+0xb48,(void *)(((struct Obj00210 *)p)->fB6C),0,0,*(u32 *)&((struct Obj00210 *)p)->fB68,*(u32 *)&((struct Obj00210 *)p)->fB58,0x440,0);
        func_02045808(s1);
    }
    s2=func_02045EC0(((struct Obj00210 *)p)->fB60,2);
    func_0201EFA4(((struct Obj00210 *)p)->fB64,0,*(u32 *)(group+offset+0xa8),2,2,1);
    func_0201EFA4(((struct Obj00210 *)p)->fB64,1,*(u32 *)(group+offset+0xac),2,2,1);
    func_0201EFA4(((struct Obj00210 *)p)->fB64,2,*(u32 *)(group+offset+0xb0),2,2,1);
    func_0201F250(((struct Obj00210 *)p)->fB64,((struct Obj00210 *)p)->fB68,s2);
    width=func_02045748(((struct Obj00210 *)p)->fB48);
    func_021B6AE4(p+0xb48,(void *)(((struct Obj00210 *)p)->fB6C),width<<3,0,*(u32 *)&((struct Obj00210 *)p)->fB68,*(u32 *)&((struct Obj00210 *)p)->fB58,0x14c0,1);
    func_02045808(s2);
    func_021DD94C((int *)(p+0xb48));
}





void func_021DDAF0(u8 *p)
{
    void *s1,*s2,*font,*text;
    u8 width,x;
    u32 w;
    if(p[0xc5f]==1) return;
    func_02043B5C(((struct Obj00210 *)p)->fC58,0);
    s1=func_02045EC0(((struct Obj00210 *)p)->fB60,3);
    width=func_0201D304(s1,*(u32 *)&((struct Obj00210 *)p)->fB58,0);
    x=(40-width)/2;
    func_0201C7D0(((struct Obj00210 *)p)->fC58,x,4,s1,((struct Obj00210 *)p)->fB58,0x1900);
    func_02045808(s1);
    s2=func_02045EC0(((struct Obj00210 *)p)->fB60,4);
    func_0201EFA4(((struct Obj00210 *)p)->fB64,0,((struct Obj00210 *)p)->fC5E + 1,2,0,1);
    func_0201F250(((struct Obj00210 *)p)->fB64,((struct Obj00210 *)p)->fB68,s2);
    font=((struct Obj00210 *)p)->fB58;
    text=((struct Obj00210 *)p)->fB68;
    w=func_0201D304(text,(u32)font,0);
    func_0201C7D0(((struct Obj00210 *)p)->fC58,x-w,4,text,font,0x1900);
    func_0201EFA4(((struct Obj00210 *)p)->fB64,0,p[0xc5f],2,0,1);
    func_0201F250(((struct Obj00210 *)p)->fB64,((struct Obj00210 *)p)->fB68,s2);
    func_0201C7D0(((struct Obj00210 *)p)->fC58,x+width,4,((struct Obj00210 *)p)->fB68,((struct Obj00210 *)p)->fB58,0x1900);
    func_02045808(s2);
    func_020257D0(((struct Obj00210 *)p)->fC54);
}





void func_021DDC28(u8 *p)
{
    u8 *row;
    void *s0,*s1,*s2,*s3,*s4,*s5,*s6,*s7;
    u32 width,i;
    row=p+0xc+((struct Obj00142 *)p)->fC5E*0xbc+((struct Obj00142 *)p)->fC5C*0x1c;
    func_02043B5C(func_02045770(((struct Obj00142 *)p)->fB50),0);
    s0=func_02045EC0(((struct Obj00142 *)p)->fB60,5);
    func_0201EE60(((struct Obj00142 *)p)->fB64,0,((struct Obj05441 *)row)->f10);
    func_0201F250(((struct Obj00142 *)p)->fB64,((struct Obj00142 *)p)->fB68,s0);
    func_021B6AE4(p+0xb50,(void *)(((struct Obj00142 *)p)->fB6C),0,0,*(u32 *)&((struct Obj00142 *)p)->fB68,((struct Obj00142 *)p)->fB58,0x440,0);
    func_02045808(s0);
    if(((struct RowBits *)row)->kind==0) {
      if(((struct Obj05441 *)row)->f10!=32) {
        s1=func_02045EC0(((struct Obj00142 *)p)->fB60,6);
        func_021B6AE4(p+0xb50,(void *)(((struct Obj00142 *)p)->fB6C),64,0,(u32)s1,((struct Obj00142 *)p)->fB58,0xc80,0);
        func_02045808(s1);
      }
    } else if(((struct RowBits *)row)->kind==1) {
      if(((struct Obj05441 *)row)->f10!=29) {
        s2=func_02045EC0(((struct Obj00142 *)p)->fB60,7);
        func_021B6AE4(p+0xb50,(void *)(((struct Obj00142 *)p)->fB6C),64,0,(u32)s2,((struct Obj00142 *)p)->fB58,0x14c0,0);
        func_02045808(s2);
      }
    }
    s3=func_02045EC0(((struct Obj00142 *)p)->fB60,11);
    width=func_0201D304(s3,((struct Obj00142 *)p)->fB5C,0);
    func_021B6AE4(p+0xb50,(void *)(((struct Obj00142 *)p)->fB6C),80,4,(u32)s3,((struct Obj00142 *)p)->fB5C,0x440,0);
    func_02045808(s3);
    s4=func_02045EC0(((struct Obj00142 *)p)->fB60,8);
    func_0201EFA4(((struct Obj00142 *)p)->fB64,0,row[0x12],3,0,1);
    func_0201F250(((struct Obj00142 *)p)->fB64,((struct Obj00142 *)p)->fB68,s4);
    func_021B6AE4(p+0xb50,(void *)(((struct Obj00142 *)p)->fB6C),width+80,0,*(u32 *)&((struct Obj00142 *)p)->fB68,((struct Obj00142 *)p)->fB58,0x440,0);
    func_02045808(s4);
    s5=func_02045EC0(((struct Obj00142 *)p)->fB60,9);
    func_0201EE0C(((struct Obj00142 *)p)->fB64,0,(const void *)(((struct Obj05441 *)row)->f0),0,1,2);
    func_0201F250(((struct Obj00142 *)p)->fB64,((struct Obj00142 *)p)->fB68,s5);
    func_021B6AE4(p+0xb50,(void *)(((struct Obj00142 *)p)->fB6C),0,24,*(u32 *)&((struct Obj00142 *)p)->fB68,((struct Obj00142 *)p)->fB58,0x440,0);
    func_02045808(s5);
    s6=func_02045EC0(((struct Obj00142 *)p)->fB60,10);
    func_0201EE0C(((struct Obj00142 *)p)->fB64,0,(const void *)(((struct Obj05441 *)row)->f4),0,1,2);
    func_0201F250(((struct Obj00142 *)p)->fB64,((struct Obj00142 *)p)->fB68,s6);
    func_021B6AE4(p+0xb50,(void *)(((struct Obj00142 *)p)->fB6C),0,48,*(u32 *)&((struct Obj00142 *)p)->fB68,((struct Obj00142 *)p)->fB58,0x440,0);
    func_02045808(s6);
    for(i=0;i<4;i++) {
        s7=func_02045EC0(((struct Obj00142 *)p)->fB60,i+12);
        func_0201EF34(((struct Obj00142 *)p)->fB64,0,*(u16 *)(row+i*2+0x14));
        func_0201F250(((struct Obj00142 *)p)->fB64,((struct Obj00142 *)p)->fB68,s7);
        func_021B6AE4(p+0xb50,(void *)(((struct Obj00142 *)p)->fB6C),(i&1)*96,(i>>1)*16+88,*(u32 *)&((struct Obj00142 *)p)->fB68,((struct Obj00142 *)p)->fB58,0x440,0);
        func_02045808(s7);
    }
    func_021DD94C((int *)(p+0xb50));
}





void func_021DDFBC(u8 *p)
{
    func_020456F8(*(struct Descriptor * *)&((struct Obj08250 *)p)->fB50);
    func_02041B6C(func_02045730(*(struct Descriptor * *)&((struct Obj08250 *)p)->fB50));
    func_02043B5C(func_02045770(*(struct Descriptor * *)&((struct Obj08250 *)p)->fB50),0);
    func_02045334(*(struct Descriptor * *)&((struct Obj08250 *)p)->fB50);
}





void func_021DDFE8(u8 *p)
{
    func_021DE114(p);
    func_021DE144((char *)p);
    func_021DE2D4((char *)p);
    func_021DE80C((char *)p);
    func_020434DC(16,1);
    func_02043598(16,1);
}






void func_021DE014(int *p)
{
    func_021DE884(p);
    func_021DE368((char *)p);
    func_021DE258((char *)p);
    func_0204A5AC();
}





void func_021DE030(u8 *p)
{
    unsigned i;
    u8 *element;
    for(i=0;i<16;i++) {
        element=p+i*4;
        if(((struct Obj10660 *)element)->fB74!=0 && CLACT_GetActorAutoAnim(*(struct Obj * *)&((struct Obj10660 *)element)->fB74)!=1)
            CLACT_AddActorAnimFrame(*(struct Obj * *)&((struct Obj10660 *)element)->fB74,4096);
    }
    func_0204A600();
}






void func_021DE064(int *p, int i, int a)
{
    int v = *(int *)((char *)p + i * 4 + 0xB74);

    if (v)
        func_0204B3DC((struct Obj *)v, a);
}





void func_021DE080(u8 *p, int i, int value)
{
    struct Obj **base=(struct Obj **)(p+0xb74);
    CLACT_SetActorAnimFrame(*(struct Obj **)((u32)base+i*4),0);
    func_0204B878(*(struct Obj **)((u32)base+i*4),value);
    func_0204B92C(*(struct Obj **)((u32)base+i*4),1);
}






int func_021DE0AC(int *p, int i)
{
    return func_0204B98C((struct Actor *)(*(int *)((char *)p + i * 4 + 0xB74)));
}





void func_021DE0C0(u8 *p, int i, int x, int y)
{
    Vec2 pos;
    pos.x=x; pos.y=y;
    func_0204B404(*(struct Obj **)((u32)p+i*4+0xb74), &pos,0);
}






/*
 * Recursive MATCH unblocker: unresolved dep named by the parked func_021DE960
 * (func_021DE0E4(obj, i, &win[1], &win[0])).  Reads the 0xb74-indexed word and
 * expands it through the arm9 helper at 0x0204B454 into the two signed shorts.
 *
 * Addresses are Black-image addresses.
 */
void func_021DE0E4(u8 *obj, int i, s16 *out1, s16 *out2)
{
    int v = *(int *)(obj + i * 4 + 0xb74);
    s16 tmp[2];

    func_0204B454((struct Actor *)v, (struct PtS *)tmp, 0);
    *out1 = tmp[0];
    *out2 = tmp[1];
}




void func_021DE114(u8 *p)
{
    struct Cfg cfg=d_021DEB88;
    func_0204A48C(&cfg,(u32)func_021DC924(),140);
}




void func_021DE144(char *p)
{
    unsigned i;
    u8 *s;
    int a;
    for (i = 0; i < 13; ++i)
        *(int *)(p + 0xbb4 + i * 4) = -1;
    for (i = 0; i < 13; ++i)
        *(int *)(p + 0xbe8 + i * 4) = -1;
    for (i = 0; i < 13; ++i)
        *(int *)(p + 0xc1c + i * 4) = -1;
    s = func_020490F4(func_020275E4(), 0x808c);
    ((struct Obj01756 *)p)->fBE4 = func_0204A6C8(s, func_02027618(), 0, 0, 0x8c);
    *(int *)&((struct Obj01756 *)p)->fC18 = func_0204ABF0(s, func_02027614(), 0, 0x180, 0x8c);
    a = func_0202761C(2);
    ((struct Obj01756 *)p)->fC4C = func_0204AF28(s, a, func_02027620(2), 0x8c);
    func_02049238(s);
}





void func_021DE1F8(char *p, int i)
{
    if (*(u32 *)(p + 0xbb4 + i * 4) != 0xffffffffu) {
        func_0204A8D4(*(u32 *)(p + 0xbb4 + i * 4));
        *(u32 *)(p + 0xbb4 + i * 4) = 0xffffffffu;
    }
}




void func_021DE218(char *p,int i)
{
    if(*(u32 *)((u32)p+0xbe8+(u32)i*4)!=(u32)-1) {
        func_0204ADA4(*(u32 *)((u32)p+0xbe8+(u32)i*4));
        *(u32 *)((u32)p+0xbe8+(u32)i*4)=(u32)-1;
    }
}




void func_021DE238(char *p,int i)
{
    if(*(u32 *)((u32)p+0xc1c+(u32)i*4)!=(u32)-1) {
        func_0204AFD8(*(u32 *)((u32)p+0xc1c+(u32)i*4));
        *(u32 *)((u32)p+0xc1c+(u32)i*4)=(u32)-1;
    }
}




void func_021DE258(char *p)
{
    unsigned i;
    for(i=0;i<13;i++)func_021DE1F8(p,i);
    for(i=0;i<13;i++)func_021DE218(p,i);
    for(i=0;i<13;i++)func_021DE238(p,i);
}




/*
 * trailing: two zero alignment bytes at 0x021DE2D2.
 */
struct Obj *func_021DE290(char *p, const char *q)
{
    return func_0204B294((void *)((struct Obj24058 *)p)->fB70, *(int *)(p + 0xbb4 + ((struct Obj08251 *)q)->f8 * 4),
        *(int *)(p + 0xbe8 + ((struct Obj08251 *)q)->fC * 4), *(int *)(p + 0xc1c + ((struct Obj08251 *)q)->f10 * 4),
        q, ((struct Obj08251 *)q)->f16, 0x8c);
}




/*
 * lever: group the integer table offset before adding its symbol base.
 */
void func_021DE2D4(char *p)
{
    unsigned i;
    *(int *)&((struct Obj01756 *)p)->fB70 = (int)func_0204B100(31, 0, 0x8c);
    for (i = 0; i < 16; ++i)
        *(int *)(p + 0xb74 + i * 4) = 0;
    for (i = 12; i <= 15; ++i)
        *(int *)(p + 0xb74 + i * 4) = (int)func_021DE290(p, d_021DEBA4 + (i * 24 - 0x120));
    if (((struct Obj01756 *)p)->fC5F == 1) {
        func_021DE064((int *)p, 12, 0);
        func_021DE064((int *)p, 13, 0);
    }
}





void func_021DE34C(char *p, int i)
{
    if (*(int *)(p + 0xb74 + i * 4) != 0) {
        func_0204B3B4((struct Obj *)(*(int *)(p + 0xb74 + i * 4)));
        *(int *)(p + 0xb74 + i * 4) = 0;
    }
}



void func_021DE368(char *p) { u32 i; for(i=0;i<16;i++) func_021DE34C(p,i); func_0204B1CC(((struct Obj08252 *)p)->fB70); }



void func_021DE388(char *p) {
    u32 i;
    u32 h;
    char *rec;
    u32 *slot;
    u32 v;
    struct Ent_021DE368 *r;
    u32 x;
    struct E e;
    for (i = 0; i <= 11; i++) func_021DE064((int *)p, i, 0);
    rec = p + 0xc + (s8)p[0xC5E] * 0xbc;
    h = func_0202D7C8(0x808C);
    {
        for (i = 0; i < *(u16 *)(rec + 0xb8); i++) {
            e = d_021DEC04[i];
            r = (struct Ent_021DE368 *)(rec + i * 0x1c);
            x = func_02017ED8(r->fc, r->f8);
            if (*(u8 *)(p + 0xC60) == 1) {
                e.w[2] += 6;
                e.w[3] += 6;
                e.w[4] += 6;
                v = (u16)(i + 6);
                slot = (u32 *)(p + 0xB74 + v * 4);
            } else {
                v = (u16)i;
                slot = (u32 *)(p + 0xB74 + v * 4);
            }
            *(u32 *)(p + e.w[2] * 4 + 0xBB4) = func_0202D81C(h, r->f10, r->a, r->b, x, 0, 0, r->f8, 0, 0x8c);
            *(u32 *)(p + e.w[3] * 4 + 0xBE8) = func_0202D7D8(h, r->f10, r->a, r->b, x, 0, 0, 0, (u16)(v << 5), 0x8c);
            *(u32 *)(p + e.w[4] * 4 + 0xC1C) = func_0202D898(r->f10, r->a, r->b, x, 0, 0, 2, 0, 0x8c);
            *slot = (u32)func_021DE290(p, (const char *)(&e));
            func_021DE608(p, v, *(u16 *)((char *)d_021DEC94 + *(u16 *)(rec + 0xb8) * 0x18 + i * 4 - 0x18));
            *(u16 *)(p + i * 2 + 0xB10) = *(u16 *)((char *)d_021DEC94 + *(u16 *)(rec + 0xb8) * 0x18 + i * 4 - 0x18);
        }
    }
    func_020216D4(*(void **)(p + 0xB30), 2, 0, 0x200);
    func_02049238((u8 *)h);
    if (*(u8 *)(p + 0xC60) == 1) {
        for (i = 0; i <= 5; i++) func_021DE34C(p, i);
        for (i = 0; i <= 5; i++) func_021DE1F8(p, i);
        for (i = 0; i <= 5; i++) func_021DE218(p, i);
        for (i = 0; i <= 5; i++) func_021DE238(p, i);
    } else {
        for (i = 6; i <= 11; i++) func_021DE34C(p, i);
        for (i = 6; i <= 11; i++) func_021DE1F8(p, i);
        for (i = 6; i <= 11; i++) func_021DE218(p, i);
        for (i = 6; i <= 11; i++) func_021DE238(p, i);
    }
    *(u8 *)(p + 0xC60) ^= 1;
    func_021DE684((u8 *)p);
}




int func_021DE5F4(char *p)
{
    if (((struct Obj24059 *)p)->fC60 == 0)
        return 6;
    return 0;
}



/*
 * lever: mask each translated fixed point coordinate before shifting and narrowing.
 */
void func_021DE608(char *p, int i, int angle)
{
    int x, y;
    x = (int)(((long long)func_0203F6D8((u16)angle) * 0x64000 + 0x800) >> 12);
    y = (int)(((long long)func_0203F684((u16)angle) * 0x2c000 + 0x800) >> 12);
    x += 0x80000;
    y += 0x58000;
    func_021DE0C0((u8 *)p, i, (short)((x & 0x7ffff000) >> 12),
        (short)((y & 0x7ffff000) >> 12));
}



void func_021DE684(u8 *p)
{
    u8 order[6];
    s16 a[2],b[2];
    int start=func_021DE5F4((char *)p);
    u8 i,j,t;
    void *r;
    for(i=0;i<6;i++) order[i]=start+i;
    for(i=0;i<*(u16 *)(p+((struct Obj10661 *)p)->fC5E*0xbc+0xc4)-1;i++) {
        func_021DE0E4(p,order[i],&a[1],&a[0]);
        for(j=i+1;j<*(u16 *)(p+((struct Obj10661 *)p)->fC5E*0xbc+0xc4);j++) {
            func_021DE0E4(p,order[j],&b[1],&b[0]);
            if(a[0]<b[0]) {t=order[i];order[i]=order[j];order[j]=t;a[0]=b[0];}
        }
    }
    for(i=0;i<*(u16 *)(p+((struct Obj10661 *)p)->fC5E*0xbc+0xc4);i++) {
        r=*(void **)(p+order[i]*4+0xb74);
        if(r) CLACT_SetActorDrawPriority(r,i);
    }
}



/*
 * note: 2026-10-05 (wD7 lane16): EXACT. cur and i are both set before n (`u16 i = 0;` at the
 *   declaration, loop with an empty init), so r0/r1 are live while n is computed; the scheduler then sinks them.
 */
void func_021DE76C(u8 *p, int mode)
{
    u16 cur = *(s8 *)(p + 0xC5C);
    u16 i = 0;
    u16 n = *(u16 *)(p + *(s8 *)(p + 0xC5E) * 0xBC + 0xC4);
    for (; i < n; ) {
        if (mode == 1) {
            u8 *q = p + cur;
            q[0xB34] = *(u16 *)((char *)d_021DEC94 + n * 0x18 + i * 4 - 0x16);
            q[0xB3A] = q[0xB34];
            cur++;
            if (cur >= *(u16 *)(p + *(s8 *)(p + 0xC5E) * 0xBC + 0xC4))
                cur = 0;
        } else {
            u8 *q = p + i;
            q[0xB34] = 0;
            q[0xB3A] = 0;
        }
        i++;
        n = *(u16 *)(p + *(s8 *)(p + 0xC5E) * 0xBC + 0xC4);
    }
}


void func_021DE80C(char *p)
{
    Descriptor descriptor;
    ((struct Obj01756 *)p)->fC50 = func_02025538(0x8C, ((struct Obj01756 *)p)->fB70);
    ((struct Obj01756 *)p)->fC58 = func_02043678(5, 3, 0x20, 0x8C);
    descriptor.image = ((struct Obj01756 *)p)->fC58;
    descriptor.x = 0x28;
    descriptor.y = 0xA8;
    descriptor.source = ((struct Obj01756 *)p)->fC18;
    descriptor.mode = 1;
    descriptor.a = 0;
    descriptor.b = 0;
    descriptor.id = 0xFFFF;
    descriptor.extra = 0;
    ((struct Obj01756 *)p)->fC54 = func_020255A0(((struct Obj01756 *)p)->fC50, (const struct Param *)(&descriptor));
    if (((struct Obj01756 *)p)->fC5F == 1) func_02025774(((struct Obj01756 *)p)->fC54, 0);
}


void func_021DE884(int *p) { func_0202570C(((struct Obj08252 *)p)->fC54); func_020437AC(((struct Obj08252 *)p)->fC58); func_02025588(((struct Obj08252 *)p)->fC50); }


int func_021DE8A8(char *p)
{
    int result = func_02035C08(d_021DED24);
    if (result == -1) {
        result = func_021DE960(p);
        if (result == 0xFF) {
            if (func_0203633C() & 0x220) return 0;
            if (func_0203633C() & 0x110) return 1;
            if (func_020362DC() & 1) return 4;
            if (func_020362DC() & 2) return 3;
            return (func_020362DC() & 0x400) ? 2 : 0xFF;
        }
    }
    return result;
}


int func_021DE914(char *p)
{
    int result = func_02035C08(d_021DED24);
    if (result != 3) {
        result = func_021DE960(p);
        if (result == 0xFF) {
            if (func_0203633C() & 0x220) return 0;
            if (func_0203633C() & 0x110) return 1;
            if (func_020362DC() & 2) return 3;
            return 0xFF;
        }
    }
    return result;
}
