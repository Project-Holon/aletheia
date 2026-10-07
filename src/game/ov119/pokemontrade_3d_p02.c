/*
 * file:     pokemontrade_3d_p02.c
 * unit:     yes
 * function: func_021DFD64, func_021DFD7C, func_021DFDA0, func_021DFE48, func_021DFF40, func_021DFFE0, func_021E0008, func_021E0030, func_021E0054, func_021E0138, func_021E017C, func_021E01A0, func_021E01E0, func_021E0200, func_021E0240, func_021E0260, func_021E02E8, func_021E0410, func_021E049C, func_021E08E8, func_021E0958, func_021E0980, func_021E0A64, func_021E0B34, func_021E0BA4, func_021E0BC4, func_021E0BE8, func_021E0C44, func_021E0C78, func_021E0CC0, func_021E0DA0, func_021E0DBC, func_021E0E4C, func_021E0E68, func_021E0EF4, func_021E0FF4, func_021E1024, func_021E1030, func_021E106C, func_021E1098, func_021E10D8, func_021E11A8, func_021E12AC, func_021E12F8, func_021E131C, func_021E1410, func_021E1430, func_021E14DC, func_021E1594, func_021E15F8, func_021E1670, func_021E1718, func_021E1778, func_021E17E8, func_021E1880, func_021E194C
 * address:  0x021DFD64
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02005E9C  0x02005E9C  thumb
 *   func_02005DE4  0x02005DE4  thumb
 *   func_02005DF8  0x02005DF8  thumb
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_021E3E60  0x021E3E60  thumb  ov119
 *   func_0204B100  0x0204B100  arm
 *   func_021DFD3C  0x021DFD3C  thumb  ov119
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021D9434  0x021D9434  thumb  ov119
 *   func_02005E64  0x02005E64  thumb
 *   func_02005E30  0x02005E30  thumb
 *   func_02005D90 0x02005D90 thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 *   func_021D8FA4 0x021D8FA4 thumb ov119
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_0201F02C 0x0201F02C thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201F5DC 0x0201F5DC thumb
 *   func_021DFD30 0x021DFD30 thumb ov119
 *   func_02040588 0x02040588 arm
 *   func_020399A8  0x020399A8  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_0200960C 0x0200960C thumb
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_02039C68 0x02039C68 arm
 *   sub_02030734   0x02030734  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_02012EBC  0x02012EBC  thumb
 *   sub_02009454  0x02009454  thumb
 *   func_02009470  0x02009470  thumb
 *   d_021E8130     0x021E8130  data  ov119
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0200C9EC  0x0200C9EC  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   sub_02009D9C  0x02009D9C  thumb
 *   func_02012F14  0x02012F14  thumb
 *   func_02009D9C 0x02009D9C thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_02008FEC 0x02008FEC thumb
 *   func_02008FFC 0x02008FFC thumb
 *   func_02012F2C 0x02012F2C thumb
 *   func_02008C20 0x02008C20 thumb
 *   func_0201AC2C 0x0201AC2C thumb
 *   func_02012FCC 0x02012FCC thumb
 *   func_020086F8 0x020086F8 thumb
 *   func_02007AEC 0x02007AEC thumb
 *   func_02007AF4 0x02007AF4 thumb
 *   func_02012F98 0x02012F98 thumb
 *   func_02007B5C 0x02007B5C thumb
 *   sub_02007B50   0x02007B50  thumb
 *   sub_02007B54   0x02007B54  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   sub_02008FFC   0x02008FFC  thumb
 *   sub_02008FEC   0x02008FEC  thumb
 *   sub_02008C20   0x02008C20  thumb
 *   sub_020086F0   0x020086F0  thumb
 *   sub_020076A4   0x020076A4  thumb
 *   func_0201A920  0x0201A920  thumb
 *   sub_02007A9C   0x02007A9C  thumb
 *   sub_02007AF4   0x02007AF4  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_0202136C  0x0202136C  thumb
 *   func_02009020  0x02009020  thumb
 *   func_02008F08  0x02008F08  thumb
 *   sub_0200903C   0x0200903C  thumb
 *   func_02008EAC  0x02008EAC  thumb
 *   func_0200856C  0x0200856C  thumb
 *   func_02008570  0x02008570  thumb
 *   func_02008564  0x02008564  thumb
 *   func_02025C1C  0x02025C1C  thumb
 *   func_02025C30  0x02025C30  thumb
 *   func_02008574  0x02008574  thumb
 *   sub_02009DE8   0x02009DE8  thumb
 *   sub_0200949C   0x0200949C  thumb
 *   sub_020094D8   0x020094D8  thumb
 *   func_0201B9F0  0x0201B9F0  thumb
 *   func_0202F190  0x0202F190  thumb
 *   sub_02008DF0   0x02008DF0  thumb
 *   func_0200CDE0  0x0200CDE0  thumb
 *   sub_02009EB0   0x02009EB0  thumb
 *   func_02017988  0x02017988  thumb
 *   sub_0201AB48   0x0201AB48  thumb
 *   sub_020185F4   0x020185F4  thumb
 *   func_020075B0  0x020075B0  thumb
 *   sub_0201283C   0x0201283C  thumb
 *   sub_02009BB8   0x02009BB8  thumb
 *   sub_02009D1C   0x02009D1C  thumb
 *   d_021E8108     0x021E8108  data  ov119
 *   d_021E811C     0x021E811C  data  ov119
 *   func_021E36D8 0x021E36D8 thumb ov119
 *   func_0201A954 0x0201A954 thumb
 *   func_0201A98C 0x0201A98C thumb
 *   func_020076A4 0x020076A4 thumb
 *   func_02012984 0x02012984 thumb
 *   func_0201B2B0 0x0201B2B0 thumb
 *   func_0203D34C 0x0203D34C arm
 *   func_0204E720 0x0204E720 arm
 *   func_020108C4 0x020108C4 thumb
 *   func_02010904 0x02010904 thumb
 *   func_02010934 0x02010934 thumb
 *   func_0202208C 0x0202208C thumb
 *   func_020221A4 0x020221A4 thumb
 *   func_0203FB44 0x0203FB44 arm
 *   func_02043534 0x02043534 arm
 *   func_020435F4 0x020435F4 arm
 *   func_021E57A4 0x021E57A4 thumb ov119
 *   func_021E53CC 0x021E53CC thumb ov119
 *   func_021E57E8 0x021E57E8 thumb ov119
 *   func_021E5680 0x021E5680 thumb ov119
 *   func_021E58A0 0x021E58A0 thumb ov119
 *   func_021E467C 0x021E467C thumb ov119
 *   func_021E4420 0x021E4420 thumb ov119
 *   func_021E3E80 0x021E3E80 thumb ov119
 *   func_021E3FE4 0x021E3FE4 thumb ov119
 *   func_021E3F74 0x021E3F74 thumb ov119
 *   func_021E3208 0x021E3208 thumb ov119
 *   func_021E3C20 0x021E3C20 thumb ov119
 *   func_021DACE4 0x021DACE4 thumb ov119
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_021B6284 0x021B6284 thumb ov067
 *   func_020275E4 0x020275E4 thumb
 *   func_020275E8 0x020275E8 thumb
 *   func_020275F8 0x020275F8 thumb
 *   func_020275FC 0x020275FC thumb
 *   func_02027600 0x02027600 thumb
 *   func_020275EC 0x020275EC thumb
 *   func_021B6208 0x021B6208 thumb ov067
 *   func_021B629C 0x021B629C thumb ov067
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_02027720 0x02027720 thumb
 *   func_0202772C 0x0202772C thumb
 *   func_02027738 0x02027738 thumb
 *   func_02027740 0x02027740 thumb
 *   func_02049B40 0x02049B40 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_02028470 0x02028470 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0202F038 0x0202F038 thumb
 *   func_0202EE8C 0x0202EE8C thumb
 *   func_020452E8 0x020452E8 arm
 *   func_020456F8 0x020456F8 arm
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_020457B0 0x020457B0 arm
 *   func_0201C440 0x0201C440 thumb
 *   func_0203101C 0x0203101C arm
 *   func_02028590 0x02028590 thumb
 *   func_02027F60 0x02027F60 thumb
 *   func_0200566C 0x0200566C thumb
 *   func_02028604 0x02028604 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02028148 0x02028148 thumb
 *   func_02027FD8 0x02027FD8 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_02045808 0x02045808 arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_02031140 0x02031140 arm
 *   func_020286C4 0x020286C4 thumb
 *   func_02028484 0x02028484 thumb
 *   func_02027858 0x02027858 thumb
 *   func_02027778 0x02027778 thumb
 *   func_0201EE84 0x0201EE84 thumb
 *   func_0201AF80 0x0201AF80 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201C7D0 0x0201C7D0 thumb
 *   d_021E7984 0x021E7984 data a4
 */
#include "../../matched/include/Obj22749.h"
#include "../../matched/include/Obj22750.h"
#include "../../matched/include/Obj00906.h"
#include "../../matched/include/Obj22751.h"
#include "../../matched/include/Obj22752.h"
#include "../../matched/include/Obj00985.h"
#include "../../matched/include/Obj01252.h"
#include "../../matched/include/Obj22753.h"
#include "../../matched/include/Obj22754.h"
#include "../../matched/include/Obj00001.h"
#include "../../matched/include/Obj01536.h"
#include "../../matched/include/Obj00589.h"
#include "../../matched/include/Obj22755.h"
#include "../../matched/include/Obj22756.h"
#include "../../matched/include/Obj22758.h"
#include "../../matched/include/Obj22759.h"
#include "../../matched/include/Obj01537.h"
#include "../../matched/include/Obj13908.h"
#include "../../matched/include/Obj22760.h"
#include "../../matched/include/Obj22761.h"
#include "../../matched/include/Obj22762.h"
#include "../../matched/include/Obj22763.h"
#include "../../matched/include/Obj22764.h"
#include "../../matched/include/Obj22765.h"
#include "../../matched/include/Obj22766.h"
#include "../../matched/include/Obj22767.h"
#include "../../matched/include/Obj22768.h"
#include "../../matched/include/Obj10371.h"
#include "../../matched/include/Obj10372.h"
#include "../../matched/include/Obj02828.h"
#include "../../matched/include/Obj10373.h"
#include "../../matched/include/Obj13909.h"
#include "../../matched/include/Obj08064.h"
#include "../../matched/include/Obj01055.h"
#include "../../matched/include/Obj05330.h"

#define I(p, o) (*(void **)((p) + (o)))
#define W(p, o) (*(int *)((p) + (o)))
#define H(p, o) (*(u16 *)((p) + (o)))
#define T(p)    (*(Trade **)((p) + 8))
struct Bank;
struct MsgBank;
struct WordSet;
struct Entry;
struct Link;
struct Big;
struct Sub02009470Obj;
struct PerapVoice;
struct PlayTime;
struct PlayTimeStamp;
struct Rec534;
struct Sub02007AC8Entry;
struct Sub02008F80Obj;
struct Blk37;
struct Party;
struct PartyMon;
struct Sub0200852CObj;
struct Sub02008EACObj;
struct Sub020097BCObj;
struct Sub02009D9CObj;
struct BigObj;
struct Sub020075B0Entry;
struct Sub02008C20Obj;
struct Sub0201088CObj;
struct Obj;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct GfFont;
struct R;
struct Tcbl;
struct U16Vec;
struct PrintSys;
struct Rec3;
struct Rec;
struct S02031140;
struct TaskMenuState;
struct Blk;
struct Ctx;
struct TaskMenu;
struct TaskMenuTmpl;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef unsigned short u16;

struct Packet {
    u32 prefix[8];
    u16 first,second;
    u8 a,b;
    u8 mode:3;
    u8 :5;
};

typedef char PacketMustBe40[sizeof(struct Packet)==40?1:-1];

typedef struct {
    u8   pad0[0x1C];
    void *party;
    u8   pad20[8];
    u16  box;
    u16  slot;
    u16  count;
} Trade;

typedef signed int     s32_021E0980;

typedef signed int     s32_021E0B34;

typedef struct Descriptor {int a,b,c,d,e,f,g;u8 h,i,j,k;} Descriptor;

typedef signed short s16_021E0EF4;

typedef short s16_021E1024;

typedef signed char s8;

typedef int s32_021E1024;

typedef signed int     s32_021E12AC;

typedef struct {u32 heap;u8 count;u8 pad[3];const void *items;u32 flag;u8 x,y,a,b;} Template;

typedef signed short   s16_021E1430;

typedef signed short   s16_021E14DC;

typedef signed short   s16_021E1594;

typedef signed short   s16_021E15F8;

typedef signed short s16_021E1718;

typedef signed short s16_021E1778;

typedef signed short s16_021E17E8;

typedef short s16_021E1880;

typedef struct { int v[5]; } T5;

typedef signed short s16_021E194C;

extern int func_02005E9C(void);
extern void func_02005DE4(void *p);
extern void func_02005DF8(u32 a);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_021E3E60(void *);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_021DFD3C(void *);
extern void func_021D8E84(void *, int);
extern void func_021D9434(void *p);
extern int func_02005E64(void);
extern void func_02005E30(u32 a);
extern void func_02005D90(int,int);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern int func_021D8AA8(void *);
extern void *func_0201F5DC(void *a0, u32 a1, u32 a2, u32 a3);
extern void *func_021D8FA4(void *,int);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021DFD30(u8 *,u32);
extern void func_02040588(unsigned char which, unsigned char enable);
extern struct Entry *func_020399A8(void);
extern unsigned int func_02039CB4(struct Link *, unsigned int, unsigned int);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02009470Obj *func_02009470(void *sys);
extern u8 *func_02012944(void *p);
extern void func_02008494(void *,void *);
extern u32 func_02017E1C(void *,u32,u32);
extern u8 func_02009628(const struct Sub02009470Obj *obj);
extern u8 func_02009584(const struct Sub02009470Obj *obj);
extern u8 func_0200960C(const struct Sub02009470Obj *obj);
extern int func_021D8A24(void *);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern void func_02039C68(struct Link *,u32,u32);
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern u32 sub_02009454(void);
extern void func_02082D44(void *, void *, int);
extern u32 func_020307B0(void *p);
extern u32 func_0200C9EC(void);
extern void *func_0200CA1C(void *p);
extern u32 sub_02009D9C(void);
extern void *func_02012F14(void **h);
extern unsigned func_02009D9C(void);
extern void func_02082BCC(void *,int,int);
extern struct Sub02008F80Obj *func_02008FEC(void *sys);
extern void *func_02012F2C(int *p);
extern int func_02012FCC(int p0);
extern struct Sub02007AC8Entry *func_02007AF4(void **save, u32 box);
extern struct Sub02007AC8Entry *func_02012F98(void *p);
extern u32 func_02008FFC(void);
extern u32 func_02008C20(void);
extern u32 func_02007AEC(void);
extern void func_0201AC2C(const struct Rec534 *src, struct Rec534 *dst);
extern void func_020086F8(struct PlayTime *p, const struct PlayTimeStamp *in);
extern void func_02007B5C(struct PerapVoice *p);
extern void *sub_02007B50(void **p);
extern void sub_02007B54(struct PerapVoice *p);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 sub_02008FFC(void);
extern struct Sub02008F80Obj *sub_02008FEC(void *sys);
extern u32 sub_02008C20(void);
extern void sub_020086F0(const struct PlayTime *p, struct PlayTimeStamp *out);
extern u8 sub_020076A4(void *save);
extern struct Party *func_0201A920(u32 heap);
extern u32 sub_02007A9C(void);
extern struct Sub02007AC8Entry *sub_02007AF4(void **save, u32 box);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_0202136C(u16 v);
extern int func_02009020(void *obj, int v);
extern void *func_02008F08(int a0);
extern void sub_0200903C(struct Sub02008F80Obj *arr, u32 unused, int i, const struct Sub02008F80Obj *src);
extern void func_02008EAC(struct Sub02008EACObj *obj);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern u8 func_02008564(const struct Sub0200852CObj *obj);
extern u32 func_02025C1C(u32 a, u32 b, u32 c);
extern u32 func_02025C30(u32 a, u32 b, u32 c);
extern void func_02008574(struct Sub0200852CObj *obj, u8 a, u8 b);
extern void sub_02009DE8(struct Sub02009D9CObj *obj, struct Sub0200852CObj *p);
extern u32 sub_0200949C(const struct Sub02009470Obj *obj, int row, int col);
extern void sub_020094D8(struct Sub02009470Obj *obj, int row, int col, int value);
extern void func_0201B9F0(void *mon);
extern void func_0202F190(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern u32 sub_02008DF0(struct Sub02008C20Obj *obj, int i);
extern void func_0200CDE0(struct Blk37 *p, void *m);
extern void sub_02009EB0(struct Sub02009D9CObj *obj);
extern u32 func_02017988(void *p, u32 a);
extern void sub_0201AB48(struct Party *p, u32 idx, const struct PartyMon *src);
extern void *sub_020185F4(void *mon);
extern int func_020075B0(void *save, u32 box, u32 slot, const struct Sub020075B0Entry *src);
extern u32 sub_0201283C(const struct BigObj *p);
extern void sub_02009BB8(struct Sub020097BCObj *obj, int i, int a, int b, int c);
extern int sub_02009D1C(struct Sub020097BCObj *obj, struct Sub0200852CObj *p, u32 *out);
extern void func_021E36D8(void *,int);
extern void func_0201A954(struct Party *p, s32_021E0980 capacity);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern u8 func_020076A4(void *);
extern u8 func_02012984(const struct BigObj *p);
extern u32 func_0201B2B0(void *party, void *mon, u32 context, u32 param, u8 timezone, u32 *methodOut, u16 heap);
extern void func_0203D34C(u32 a, u32 b);
extern void func_0204E720(u32 a, s32_021E0B34 b, s32_021E0B34 c, s32_021E0B34 d);
extern void *func_020108C4(u32 heap, u32 a1, u32 a2, u32 a3);
extern u32 func_02010904(struct Sub0201088CObj *p);
extern void func_02010934(struct Sub0201088CObj *p);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 func_020221A4(void);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_02043534(u32 planes);
extern void func_020435F4(u32 planes);
extern void func_021E57A4(int);
extern void func_021E53CC(int p);
extern void func_021E57E8(int);
extern void func_021E5680(char *p);
extern void func_021E58A0(int);
extern void func_021E467C(char *p);
extern void func_021E4420(char *p);
extern void func_021E3E80(char *);
extern void func_021E3FE4(char *p);
extern void func_021E3F74(char *p);
extern void func_021E3208(void *,int);
extern void func_021E3C20(char *p);
extern void func_021DACE4(char *p);
extern void func_0204B3B4(struct Obj *p);
extern void func_021B6284(unsigned int *p);
extern u32 func_020275E4(void);
extern u32 func_020275E8(void);
extern u32 func_020275F8(u32);
extern u32 func_020275FC(u32);
extern u32 func_02027600(u32);
extern u8 func_020275EC(int i);
extern void func_021B6208(void *,Descriptor *,int,u16);
extern int func_021B629C(void *,int,u8,u8,u8,u16);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern int func_02027720(int);
extern int func_0202772C(int);
extern int func_02027738(int,int);
extern int func_02027740(int,int);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201DD78(u32,u32,u32);
extern signed char func_02012FFC(void);
extern u32 func_0201CCE4(u32,u32,u32,u32,u32,u32,u32,u32,u16,u16);
extern void func_02028470(u8 *,u32);
extern void func_0201C7A4(void *,s16_021E0EF4,s16_021E0EF4,void *,void *);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32 bit);
extern void func_0202F038(u8 *p);
extern u8 *func_0202EE8C(u32 a, void *b, u8 c, u8 d, u16 e);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_020456F8(struct Descriptor *d);
extern void func_0201F7A8(void *desc, u32 kind);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u32 func_0201C440(void *p);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern void *func_02028590(u32,u32,u32,u32);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void func_0200566C(void);
extern int func_02028604(int a0);
extern void func_0201CE48(struct Rec3 *p);
extern void func_02028148(u8 *p);
extern unsigned int func_02027FD8(struct TaskMenuState *s);
extern unsigned int func_0201ED04(struct WordSet *p);
extern unsigned int func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_02031140(struct S02031140 *p);
extern void func_020286C4(struct Ctx *ctx, void *p, void *cell);
extern s32_021E12AC func_02028484(struct Blk *blk, void *h);
extern void func_02027858(struct TaskMenu *m);
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
extern void func_0201EE84(struct WordSet *p, u32 i, void *mon);
extern u16 *func_0201AF80(u32 heap, u16 *countOut);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201C7D0(void *,short,short,int,int,int);
extern void func_0201EF40(struct WordSet *p, u32 i, u32 v);
void func_021DFD64(void *p);
void func_021DFD7C(void *p);
void func_021DFDA0(void *p);
void func_021DFE48(char *p);
void func_021DFF40(char *p);
void func_021DFFE0(char *p);
void func_021E0008(char *p);
void func_021E0030(void *p);
void func_021E0054(char *p);
void *func_021E0138(void *sys, u16 heapId);
void func_021E017C(void *sys, void *buf);
void *func_021E01A0(void *src, u16 heapId);
void func_021E01E0(void *h, void *buf);
void *func_021E0200(void *sys, u16 heapId);
void func_021E0240(void **h, void *dst);
void func_021E0260(char *p);
void func_021E02E8(char *p);
int func_021E0410(char *p, void *party, int idx);
void func_021E049C(char *p);
void func_021E08E8(char *p);
void func_021E0958(char *p);
void func_021E0980(char *p);
void func_021E0A64(char *p);
void func_021E0B34(char *p);
void func_021E0BA4(void *p);
void func_021E0BC4(void *p);
void func_021E0BE8(char *p);
void func_021E0C44(char *p);
void func_021E0C78(char *p);
void func_021E0CC0(char *p);
void func_021E0DA0(char *p);
void func_021E0DBC(char *p,void *mon,int index,int slot,int x,int y,int a,u16 b);
void func_021E0E4C(char *p);
void func_021E0E68(char *p,void *mon,int slot,int x,int y,int a,u16 b,int c);
void func_021E0EF4(char *p,int flag,int x,int y,int w,int h);
void func_021E0FF4(void *p, int a, int flag);
void func_021E1024(void *p);
void func_021E1030(char *p);
void func_021E106C(char *p);
void func_021E1098(char *p);
void func_021E10D8(char *p);
void func_021E11A8(char *p);
int func_021E12AC(char *p);
void func_021E12F8(char *p);
void func_021E131C(char *p,int *ids,int count,int x,int y);
void func_021E1410(void *p, int *ids, int count);
void func_021E1430(void *a,void *b,int x,int y,int flag,int mode,char *p);
void func_021E14DC(void *a,void *b,int x,int y,int flag,char *p);
void func_021E1594(void *a,void *b,int x,int y,int flag,char *p);
void func_021E15F8(void *a,void *b,int x,int y,char *p);
void func_021E1670(void *a,void *b,int x,int y,char *p,int mode,int guard);
void func_021E1718(int a,int b,int x,int y,char *p);
void func_021E1778(int a,int b,int x,int y,char *p);
void func_021E17E8(int a,int b,int x,int y,char *p);
void func_021E1880(int a, int b, int c, int d, char *p);
void func_021E194C(int a,int b,int x,int y,char *p);
extern const char d_021E8130[];
extern const char d_021E8108[];
extern const char d_021E811C[];
extern const T5 d_021E7984;


void func_021DFD64(void *p)
{
    u8 *b = p;

    func_02005E9C();
    ((struct Obj22749 *)b)->f11F8 -= 1;
}


void func_021DFD7C(void *p)
{
    u8 *b = p;

    func_02005E9C();
    ((struct Obj22750 *)b)->f11F8 -= 1;
    func_02005DE4(0);
    func_02005DF8(0x18);
}


/*
 * Slot-state teardown/rebuild, dispatched on *(p+0x118c): 5 and 6 run the
 * shared +8 slot teardown and hand func_021D8E84 either func_021D9434 or
 * NULL; the default path increments the +0x11f8 byte and hands
 * func_021DFE48. Target of func_021D6C78's ABS32 callback argument (ov119).
 *
 * Addresses are Black-image addresses.
 */
void func_021DFDA0(void *p)
{
    u8 *b = p;
    int st;

    func_0204B1CC(((struct Obj00906 *)b)->f9C4);
    func_0204A5AC();
    func_021E3E60(p);
    ((struct Obj00906 *)b)->f9C4 = func_0204B100(0x154, 0, ((struct Obj00906 *)b)->f5F4);
    st = ((struct Obj00906 *)b)->f118C;
    if (st == 5) {
        func_021DFD3C(p);
        ((struct Obj22751 *)(*(int * *)&((struct Obj00906 *)b)->f8))->f8 = 3;
        func_021D8E84(p, (int)func_021D9434);
    } else if (st == 6) {
        func_021DFD3C(p);
        ((struct Obj22752 *)(*(int * *)&((struct Obj00906 *)b)->f8))->f8 = 3;
        func_021D8E84(p, 0);
    } else {
        func_021E10D8(p);
        func_02005DE4((void *)1);
        func_02005E64();
        (((struct Obj00906 *)b)->f11F8)++;
        func_02005E30(6);
        ((struct Obj00906 *)b)->fF2C = 0;
        func_021D8E84(p, (int)func_021DFE48);
    }
}

/*
 * lever: Repeat the message call in each arm; an id local factors the argument loads and is 20 bytes short.
 */
void func_021DFE48(char *p)
{
    void *mon;
    int z,state;
    if(((struct Obj00985 *)p)->fF2C<6) return;
    func_02005D90(0x518,0xffff);
    func_02005DF8(6);
    state=((struct Obj00985 *)p)->f118C;
    if(state==7) func_02045CAC((struct MsgBank *)(((struct Obj00985 *)p)->f720),153,(void *)(((struct Obj00985 *)p)->f73C));
    else if(state==8) func_02045CAC((struct MsgBank *)(((struct Obj00985 *)p)->f720),156,(void *)(((struct Obj00985 *)p)->f73C));
    else if(((struct Obj00985 *)p)->f11EE) func_02045CAC((struct MsgBank *)(((struct Obj00985 *)p)->f720),131,(void *)(((struct Obj00985 *)p)->f73C));
    else func_02045CAC((struct MsgBank *)(((struct Obj00985 *)p)->f720),48,(void *)(((struct Obj00985 *)p)->f73C));
    if(func_021D8AA8(p)) mon=func_021D8FA4(p,0);
    else mon=func_021D8FA4(p,1);
    func_0201EEF4(((struct Obj00985 *)p)->f724,1,mon);
    z=0;
    func_0201F02C((struct WordSet *)(*(int *)&((struct Obj00985 *)p)->f724),0,(void *)(((struct Obj00985 *)p)->f834));
    func_0201F250((struct WordSet *)(*(int *)&((struct Obj00985 *)p)->f724),(void *)(((struct Obj00985 *)p)->f738),(void *)(((struct Obj00985 *)p)->f73C));
    ((struct Obj00985 *)p)->f644=(int)func_0201F5DC((void *)6,15,0,((struct Obj00985 *)p)->f5F4);
    func_021E0FF4(p,1,0);
    func_021DFD30((u8 *)p,0);
    func_02040588(6,1);
    ((struct Obj00985 *)p)->fF2C=z;
    func_021D8E84(p,(int)func_021DFF40);
}

/*
 * 2026-10-02: the 02045CAC/0201F250/021E0FF4 statements are repeated in both arms of
 *  the 0x11EE test (the compiler tail-merges them), which keeps the 0x834 and 0x724
 *  constants live into the merged tail.
 */
void func_021DFF40(char *p)
{
    void *a;
    if (((struct Obj01252 *)p)->fF2C < 0xC8) {
        return;
    }
    if (func_021D8AA8(p)) {
        a = func_021D8FA4(p, 0);
    } else {
        a = func_021D8FA4(p, 1);
    }
    func_0201EEF4(((struct Obj01252 *)p)->f724, 1, a);
    func_0201F02C(((struct Obj01252 *)p)->f724, 0, (void *)(((struct Obj01252 *)p)->f834));
    if (((struct Obj01252 *)p)->f118C != 7 && ((struct Obj01252 *)p)->f118C != 8) {
        if (((struct Obj01252 *)p)->f11EE) {
            func_02045CAC(((struct Obj01252 *)p)->f720, 0x84, ((struct Obj01252 *)p)->f73C);
            func_0201F250(((struct Obj01252 *)p)->f724, ((struct Obj01252 *)p)->f738, ((struct Obj01252 *)p)->f73C);
            func_021E0FF4(p, 1, 0);
        } else {
            func_02045CAC(((struct Obj01252 *)p)->f720, 0x31, ((struct Obj01252 *)p)->f73C);
            func_0201F250(((struct Obj01252 *)p)->f724, ((struct Obj01252 *)p)->f738, ((struct Obj01252 *)p)->f73C);
            func_021E0FF4(p, 1, 0);
        }
    }
    func_021D8E84(p, (int)func_021DFFE0);
}


void func_021DFFE0(char *p)
{
    if (((struct Obj22753 *)p)->fF2C >= 0x10e) {
        func_021DFD7C(p);
        func_021D8E84(p, (int)func_021E0008);
    }
}


void func_021E0008(char *p)
{
    if (((struct Obj22754 *)p)->fF2C >= 0x1a4) {
        func_021DFD30((u8 *)p, 0);
        func_021D8E84(p, (int)func_021E08E8);
    }
}


void func_021E0030(void *p)
{
    if (func_02039CB4((struct Link *)func_020399A8(), 0x17, 8)) {
        func_021D8E84(p, (int)func_021E0980);
    }
}

void func_021E0054(char *p)
{
    struct Packet packet;
    void *saved,*first,*second;
    saved=func_02009470(func_02012EBC(((struct Obj00001 *)p)->f82C));
    if(func_021D8AA8(p)) {
        first=func_021D8FA4(p,0);
        second=func_021D8FA4(p,1);
    } else {
        first=func_021D8FA4(p,1);
        second=func_021D8FA4(p,0);
    }
    func_02008494(func_02012944(((struct Obj00001 *)p)->f82C),&packet);
    packet.first=func_02017E1C(first,5,0);
    packet.second=func_02017E1C(second,5,0);
    packet.a=func_02009628(saved);
    packet.b=func_02009584(saved);
    packet.mode=func_0200960C(saved);
    if(func_021D8A24(p)) {
        if(func_0203D3A8(func_020399A8(),0xc12,40,(u32)(&packet))) {
            func_02039C68((struct Link *)func_020399A8(),23,8);
            func_021D8E84(p,(int)func_021E0030);
            return;
        }
    } else func_021D8E84(p,(int)func_021E0C78);
}


static inline void GFL_STD_MemCopy(const void *src, void *dst, u32 size)
{
    MI_CpuCopy8(src, dst, size);
}


/*
 * Addresses are Black-image addresses.
 */
void *func_021E0138(void *sys, u16 heapId)
{
    void *h = func_02012EBC(sys);
    void *buf = sub_02030734(heapId, sub_02009454(), 0, d_021E8130, 0x1A0);

    GFL_STD_MemCopy(func_02009470(h), buf, sub_02009454());
    return buf;
}

void func_021E017C(void *sys, void *buf)
{
    void *src = func_02009470(func_02012EBC(sys));
    func_02082D44(buf, src, sub_02009454());
    func_020307B0(buf);
}


void *func_021E01A0(void *src, u16 heapId)
{
    void *buf = sub_02030734(heapId, func_0200C9EC(), 0, d_021E8130, 0x1BD);

    GFL_STD_MemCopy(func_0200CA1C(src), buf, func_0200C9EC());
    return buf;
}

void func_021E01E0(void *h, void *buf)
{
    void *src = func_0200CA1C(h);
    func_02082D44(buf, src, func_0200C9EC());
    func_020307B0(buf);
}


void *func_021E0200(void *sys, u16 heapId)
{
    void *buf = sub_02030734(heapId, sub_02009D9C(), 0, d_021E8130, 0x1DA);

    GFL_STD_MemCopy(func_02012F14(sys), buf, sub_02009D9C());
    return buf;
}

void func_021E0240(void **h, void *dst)
{
    void *src = func_02012F14(h);
    func_02082D44(dst, src, func_02009D9C());
    func_020307B0(dst);
}

void func_021E0260(char *p)
{
    int zero;
    if (((struct Obj01536 *)p)->f60C) func_020307B0(((struct Obj01536 *)p)->f60C);
    if (((struct Obj01536 *)p)->f610) func_020307B0(((struct Obj01536 *)p)->f610);
    if (((struct Obj01536 *)p)->f614) func_020307B0(((struct Obj01536 *)p)->f614);
    if (((struct Obj01536 *)p)->f618) func_020307B0(((struct Obj01536 *)p)->f618);
    if (((struct Obj01536 *)p)->f61C) func_020307B0(((struct Obj01536 *)p)->f61C);
    if (((struct Obj01536 *)p)->f620) func_020307B0(((struct Obj01536 *)p)->f620);
    if (((struct Obj01536 *)p)->f624) func_020307B0(((struct Obj01536 *)p)->f624);
    zero=0;
    func_02082BCC(p+0x60c,zero,36);
    p[0x11f7]=zero;
}

void func_021E02E8(char *p)
{
    void *dest,*src;
    u32 n;
    dest=((struct Obj00589 *)p)->f60C;
    if(dest) {
        src=((struct Obj00589 *)p)->f82C;
        func_02012EBC(src);
        src=func_02008FEC(src);
        n=func_02008FFC();
        func_02082D44(dest,src,n);
        func_020307B0(dest);
    }
    dest=((struct Obj00589 *)p)->f610;
    if(dest) {
        src=func_02012F2C(((struct Obj00589 *)p)->f82C);
        n=func_02008C20();
        func_02082D44(dest,src,n);
        func_020307B0(dest);
    }
    if(((struct Obj00589 *)p)->f614) func_021E017C(((struct Obj00589 *)p)->f82C,((struct Obj00589 *)p)->f614);
    if(((struct Obj00589 *)p)->f618) func_021E01E0(((struct Obj00589 *)p)->f82C,((struct Obj00589 *)p)->f618);
    if(((struct Obj00589 *)p)->f61C) func_021E0240(((struct Obj00589 *)p)->f82C,((struct Obj00589 *)p)->f61C);
    if(((struct Obj00589 *)p)->f620) {
        func_0201AC2C(((struct Obj00589 *)p)->f620,((struct Obj00589 *)p)->f838);
        func_020086F8((void *)func_02012FCC((int)(((struct Obj00589 *)p)->f82C)),(const struct PlayTimeStamp *)(p+0x628));
        func_020307B0(((struct Obj00589 *)p)->f620);
        *(int *)&((struct Obj00589 *)p)->f620=0;
    }
    if(((struct Obj00589 *)p)->f624) {
        n=func_02007AEC();
        src=func_02007AF4(((struct Obj00589 *)p)->f828,((struct Obj22755 *)(*(char * *)&((struct Obj00589 *)p)->f8))->f28);
        func_02082D44(((struct Obj00589 *)p)->f624,src,n);
        func_020307B0(((struct Obj00589 *)p)->f624);
    }
    if(((struct Obj00589 *)p)->f62C) func_02007B5C((struct PerapVoice *)func_02012F98(((struct Obj00589 *)p)->f82C));
    func_02082BCC(p+0x60c,0,0x24);
}


int func_021E0410(char *p, void *party, int idx)
{
    int count = 0;
    int i, n;
    void *voice = func_02012F98(((struct Obj22756 *)p)->f82C);

    if (!sub_02007B50(voice))
        return count;
    n = func_0201AA18(party);
    for (i = 0; i < n; i++) {
        if (func_02017E1C(func_0201AB28(party, i), 5, 0) == 0x1B9)
            count++;
    }
    if (count != 1)
        return 0;
    count = 0;
    if (func_02017E1C(func_0201AB28(party, idx), 5, 0) == 0x1B9) {
        sub_02007B54(voice);
        return 1;
    }
    return count;
}


static inline void *copy_a(void *sys, u16 heapId)
{
    void *buf = sub_02030734(heapId, sub_02008FFC(), 0, d_021E811C, 0x163);

    GFL_STD_MemCopy(sub_02008FEC(sys), buf, sub_02008FFC());
    return buf;
}


static inline void *copy_b(void *sys, u16 heapId)
{
    void *buf = sub_02030734(heapId, sub_02008C20(), 0, d_021E8108, 0x182);

    GFL_STD_MemCopy(func_02012F2C(sys), buf, sub_02008C20());
    return buf;
}


/*
 * closed:   blocking arm9 callees labelled and matched by seeds_3 (2026-09-28)
 *
 * pokemontrade_save.c.  The first two buffer copies are inlined statics
 * (their arguments are spilled before the body, and each carries its own
 * copy of the __FILE__ string); the rest call the out-of-line copies.
 * Every copy goes through the GFL_STD_MemCopy inline wrapper, whose
 * arguments are evaluated last to first: the size call, then the
 * destination load, then the source call.
 *
 * Addresses are Black-image addresses.
 */
void func_021E049C(char *p)
{
    void *mon;
    void *obj;
    void *list[2];
    int i;
    int out;

    if (func_021D8AA8(p) == 0) {
        I(p, 0x60C) = copy_a(I(p, 0x82C), H(p, 0x5F4));
        I(p, 0x610) = copy_b(I(p, 0x82C), H(p, 0x5F4));
        I(p, 0x614) = func_021E0138(I(p, 0x82C), H(p, 0x5F4));
        I(p, 0x618) = func_021E01A0(I(p, 0x82C), H(p, 0x5F4));
        I(p, 0x61C) = func_021E0200(I(p, 0x82C), H(p, 0x5F4));
        sub_020086F0((void *)func_02012FCC((int)I(p, 0x82C)), (struct PlayTimeStamp *)(p + 0x628));
        if (T(p)->box == sub_020076A4(I(p, 0x828))) {
            I(p, 0x620) = func_0201A920(H(p, 0x5F4));
            func_0201AC2C(I(p, 0x838), I(p, 0x620));
            W(p, 0x62C) = func_021E0410(p, I(p, 0x838), T(p)->slot);
        } else {
            I(p, 0x624) = sub_02030734(H(p, 0x5F4), sub_02007A9C(), 0, d_021E8130, 0x271);
            GFL_STD_MemCopy(sub_02007AF4(I(p, 0x828), T(p)->box), I(p, 0x624), sub_02007A9C());
        }
    } else {
        Trade *t = T(p);
        if (t->box == sub_020076A4(I(p, 0x828)))
            func_021E0410(p, I(p, 0x838), t->slot);
        p[0x11F7] = 1;
    }

    {
        Trade *t = T(p);
        if (t->box != sub_020076A4(I(p, 0x828))) {
            mon = func_0201AB28(t->party, 0);
            if (func_0202136C(func_02017E1C(mon, 6, 0))) {
                void *o = sub_02008FEC(I(p, 0x82C));
                int idx = func_02009020(o, 0);
                if (idx != -1) {
                    void *buf = func_02008F08(H(p, 0x5F4));
                    func_02017E1C(mon, 0xA7, (u32)buf);
                    sub_0200903C(o, 0, idx, buf);
                    func_02008EAC(buf);
                    func_02017E40(mon, 0xA7, (u32)buf);
                    func_02017E40(mon, 6, 0);
                    func_020307B0(buf);
                }
            }
        }
    }

    {
        u8 a = func_0200856C(I(p, 0x834));
        u8 b = func_02008570(I(p, 0x834));
        u32 ra = func_02025C1C(a, b, func_02008564(I(p, 0x834)));
        u32 rb = func_02025C30(a, b, func_02008564(I(p, 0x834)));
        if (a != ra || b != rb)
            func_02008574(I(p, 0x834), 0, 0);
    }

    sub_02009DE8(func_02012F14(I(p, 0x82C)), I(p, 0x834));
    obj = func_02009470(func_02012EBC(I(p, 0x82C)));
    list[0] = I(p, 0x830);
    list[1] = I(p, 0x834);
    for (i = 0; i < 2; i++) {
        void *q = list[i];
        if (q) {
            u8 row = func_0200856C(q);
            u8 col = func_02008570(q);
            func_02008564(q);
            if (!sub_0200949C(obj, row, col))
                sub_020094D8(obj, row, col, 1);
        }
    }

    mon = func_0201AB28(T(p)->party, 0);
    obj = func_02012F2C(I(p, 0x82C));
    func_0201B9F0(mon);
    if (func_02017E1C(mon, 0x4C, 0) == 0)
        func_02017E40(mon, 9, (u32)((void *)0x46));
    if (func_02017E1C(mon, 0x4C, 0))
        func_0202F190(mon, 6, (u32)I(p, 0x830), 0x7533, H(p, 0x5F4));
    switch (W(p, 0x118C)) {
    case 2:
    case 3:
        sub_02008DF0(obj, 0x10);
        break;
    case 1:
        sub_02008DF0(obj, 0xC);
        break;
    case 0:
        sub_02008DF0(obj, 0x24);
        break;
    }
    func_0200CDE0(func_0200CA1C(I(p, 0x82C)), mon);
    if (W(p, 0x118C) == 3)
        sub_02009EB0(func_02012F14(I(p, 0x82C)));
    if (func_02017E1C(mon, 5, 0) == 0x1EC && func_02017E1C(mon, 0x6F, 0) == 1) {
        func_02017988(mon, 0);
        func_0200CDE0(func_0200CA1C(I(p, 0x82C)), mon);
    }
    {
        Trade *t = T(p);
        if (t->box == sub_020076A4(I(p, 0x828))) {
            sub_0201AB48(I(p, 0x838), t->slot, mon);
        } else {
            t = T(p);
            func_020075B0(I(p, 0x828), t->box, t->slot, sub_020185F4(mon));
        }
    }
    switch (W(p, 0x118C)) {
    case 2:
        sub_02009BB8((void *)sub_0201283C(I(p, 0x82C)), T(p)->count - 1, 0, 0, 1);
        break;
    case 0:
    case 1:
        if (sub_02009D1C((void *)sub_0201283C(I(p, 0x82C)), I(p, 0x834), (u32 *)(&out)))
            sub_02009BB8((void *)sub_0201283C(I(p, 0x82C)), out, 0, 0, 1);
        break;
    }
}

void func_021E08E8(char *p)
{
    int state;
    func_021E36D8(p,0);func_021E36D8(p,1);
    func_021E36D8(p,2);func_021E36D8(p,3);
    state=((struct Obj00906 *)p)->f118C;
    if(state==4 || (unsigned)(state-7)<=1) {
        ((struct Obj22758 *)(*(char * *)&((struct Obj00906 *)p)->f8))->f8=3;
        func_021DFD3C(p);
        func_021D8E84(p,(int)func_021D9434);
        return;
    }
    if((unsigned)(state-1)<=2) {
        func_021D8E84(p,(int)func_021E0054);
        return;
    } else {
        func_021D8E84(p,(int)func_021E0980);
        return;
    }
}

void func_021E0958(char *p)
{
    if (func_021E12AC(p) && ((struct Obj22759 *)p)->fF2C > 0xB4) {
        func_021D8E84(p, (int)func_021E0A64);
    }
}

void func_021E0980(char *p)
{
    int i;
    void *mon;
    int z;
    char *t;
    if(func_021D8AA8(p)) {
        i=((struct Obj01537 *)p)->fFA0%3;
        mon=func_021D8FA4(p,0);
        ((struct Obj22760 *)(*(char * *)&((struct Obj01537 *)p)->f8))->f28=*(int *)(p+i*4+0xfbc);
        ((struct Obj22761 *)(*(char * *)&((struct Obj01537 *)p)->f8))->f2A=*(int *)(p+i*4+0xfa4);
    } else {
        mon=func_021D8FA4(p,1);
        ((struct Obj22762 *)(*(char * *)&((struct Obj01537 *)p)->f8))->f28=((struct Obj01537 *)p)->fF88;
        ((struct Obj22763 *)(*(char * *)&((struct Obj01537 *)p)->f8))->f2A=((struct Obj01537 *)p)->fF84;
    }
    func_0201A954(((struct Obj22764 *)(*(char * *)&((struct Obj01537 *)p)->f8))->f1C,6);
    func_0201A98C(((struct Obj22765 *)(*(char * *)&((struct Obj01537 *)p)->f8))->f1C,mon);
    func_0200CDE0(func_0200CA1C(((struct Obj01537 *)p)->f82C),mon);
    t=*(char * *)&((struct Obj01537 *)p)->f8;
    if(((struct Obj13908 *)t)->f28!=func_020076A4(((struct Obj01537 *)p)->f828)) {
        z=0;
        if(func_0202136C(func_02017E1C(func_0201AB28(((struct Obj13908 *)t)->f1C,0),6,0))) {
            func_02045CAC((struct MsgBank *)(((struct Obj01537 *)p)->f720),106,(void *)(((struct Obj01537 *)p)->f738));
            func_021E1024(p);
            func_021D8E84(p,(int)func_021E0958);
            ((struct Obj01537 *)p)->fF2C=z;
            return;
        }
    }
    func_021D8E84(p,(int)func_021E0A64);
}

/*
 * lever: Repeat callback calls, then goto the shared teardown; callback local shifts the join by two bytes.
 */
void func_021E0A64(char *p)
{
    void *a,*b;
    u32 out,result;
    if(*(int *)&((struct Obj00906 *)p)->f82C==0) {
        func_021D8E84(p,(int)func_021E0C78);
        goto exit;
    }
    else {
    if(*(int *)&((struct Obj00906 *)p)->f8!=0) {
        if(func_021D8AA8(p)) {a=func_021D8FA4(p,0);b=func_021D8FA4(p,1);}
        else {a=func_021D8FA4(p,1);b=func_021D8FA4(p,0);}
        result=func_0201B2B0(0,a,1,(u32)b,func_02012984(((struct Obj00906 *)p)->f82C),&out,((struct Obj00906 *)p)->f5F4);
        if(result) {
            ((struct Obj22766 *)(*(char * *)&((struct Obj00906 *)p)->f8))->f8=1;
            ((struct Obj22767 *)(*(char * *)&((struct Obj00906 *)p)->f8))->fC=result;
            ((struct Obj22768 *)(*(char * *)&((struct Obj00906 *)p)->f8))->f10=out;
            func_021D8E84(p,(int)func_021D9434);
            func_021DFD64(p);
            return;
        }
    }
    func_02045CAC((struct MsgBank *)(((struct Obj00906 *)p)->f720),50,(void *)(((struct Obj00906 *)p)->f738));
    func_021E1024(p);func_021E1030(p);
    func_021D8E84(p,(int)func_021E0BA4);
    }
exit:
    func_021DFD3C(p);
}

void func_021E0B34(char *p) {func_021E10D8(p);func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720),50,(void *)(*(int *)&((struct Obj00001 *)p)->f738));*(int *)&((struct Obj00001 *)p)->f644=(int)func_0201F5DC((void *)6,15,0,((struct Obj00001 *)p)->f5F4);func_021E1024(p);func_021E1030(p);func_021DFD30((u8 *)p,0);func_02040588(6,1);func_0203D34C(1,((struct Obj00001 *)p)->f5F4);func_0204E720(3,16,0,2);func_021D8E84(p,(int)func_021E0BA4);}

void func_021E0BA4(void *p)
{
    func_02039C68((struct Link *)func_020399A8(), 0x18, 8);
    func_021D8E84(p, (int)func_021E0BC4);
}

void func_021E0BC4(void *p)
{
    if (func_02039CB4((struct Link *)func_020399A8(), 0x18, 8)) {
        func_021D8E84(p, (int)func_021E0BE8);
    }
}

void func_021E0BE8(char *p) {if(func_021E12AC(p)) {if(func_021D8A24(p)) {func_021E049C(p);((struct Obj00001 *)p)->fEF8=(int)func_020108C4(((struct Obj00001 *)p)->f5F4,*(int *)&((struct Obj00001 *)p)->f82C,(u32)func_021E0260,(u32)p);func_021D8E84(p,(int)func_021E0C44);return;}func_021D8E84(p,(int)func_021E0C78);}}

/*
 * 2026-10-02: byte-correct; the call to the tail-call stub 0x02010934 (inside
 * matched unit_0201088C) now resolves since that stub was seeded as a start.
 */
void func_021E0C44(char *p)
{
    if (func_02010904(((struct Obj10371 *)p)->fEF8)) {
        func_021E02E8(p);
        func_02010934(((struct Obj10371 *)p)->fEF8);
        *(int *)&((struct Obj10371 *)p)->fEF8 = 0;
        func_021D8E84(p, (int)func_021E0C78);
    }
}

void func_021E0C78(char *p) {int z;func_0202208C(0,0,0,0,6,1,((struct Obj10372 *)p)->f5F4);z=0;((struct Obj10372 *)p)->fF2C=z;p[0x11f7]=z;func_021D8E84(p,(int)func_021E0CC0);}

void func_021E0CC0(char *p)
{
    if(((struct Obj02828 *)p)->fF2C>=6 && func_020221A4()) {
        if(((struct Obj02828 *)p)->f644) func_0203FB44((int)6,(u16)(((struct Obj02828 *)p)->f644),(u16)(((struct Obj02828 *)p)->f644>>16));
        *(int *)&((struct Obj02828 *)p)->f644=0;
        func_02043534((int)0);func_020435F4((int)0);
        func_0204B1CC(((struct Obj02828 *)p)->f9C4);
        ((struct Obj02828 *)p)->f9C4=func_0204B100(0x154,0,((struct Obj02828 *)p)->f5F4);
        func_021E106C(p);func_021E57A4((int)p);func_021E53CC((int)p);
        func_021E57E8(0);func_021E5680(p);func_021E58A0((int)p);
        func_021E467C(p);func_021E4420(p);func_021E3E80(p);
        func_021E3FE4(p);func_021E3F74(p);func_021E3208(p,0);
        func_02043534((int)31);func_020435F4((int)30);func_021E3C20(p);
        func_0203D34C(1,((struct Obj02828 *)p)->f5F4);
        ((struct Obj02828 *)p)->f11FA=0;
        func_021D8E84(p,(int)func_021DACE4);
    }
}

void func_021E0DA0(char *p)
{
    if (((struct Obj10373 *)p)->f10) {
        func_0204B3B4(((struct Obj10373 *)p)->f10);
        *(int *)&((struct Obj10373 *)p)->f10 = 0;
        func_021B6284((unsigned int *)p);
    }
}

void func_021E0DBC(char *p,void *mon,int index,int slot,int x,int y,int a,u16 b) {Descriptor d;u8 v;int z=0;v=func_02017E1C(mon,index+174,0);d.a=a;d.b=z;d.c=func_020275E4();d.d=func_020275E8();d.e=func_020275F8(v);d.f=func_020275FC(2);d.g=func_02027600(2);d.h=8;d.i=z;d.j=3;func_021B6208(p,&d,slot,b);((struct Obj13909 *)p)->f10=func_021B629C(p,slot,x,y,z,b);func_0204B6F4((struct Obj *)(((struct Obj13909 *)p)->f10),func_020275EC(v),1);}

void func_021E0E4C(char *p)
{
    if (((struct Obj08064 *)p)->f10) {
        func_0204B3B4(((struct Obj08064 *)p)->f10);
        *(int *)&((struct Obj08064 *)p)->f10 = 0;
        func_021B6284((unsigned int *)p);
    }
}

/*
 * extent: two zero alignment bytes at 0x021E0EF2, labelled next function 0x021E0EF4.
 */
void func_021E0E68(char *p,void *mon,int slot,int x,int y,int a,u16 b,int c) {Descriptor d;int v;v=func_02017E1C(mon,152,0);func_021E0E4C(p);d.a=a;d.b=0;d.c=func_020275E4();d.d=func_02027720(v);d.e=func_0202772C(v);d.f=func_02027738(v,2);d.g=func_02027740(v,2);d.h=c;d.i=0;d.j=1;func_021B6208(p,&d,slot,b);*(int *)&((struct Obj08064 *)p)->f10=func_021B629C(p,slot,x,y,0,b);}

/*
 * prototype: 0201F73C arg2 is u16 because 021E0FC4..021E0FC6 truncates the loaded full word before the call.
 * prototype: 0201CCE4 forwarding wrapper leaves r0 live; caller stores it at 021E0F94 despite legacy void declaration.
 */
void func_021E0EF4(char *p,int flag,int x,int y,int w,int h)
{
    void *v;
    func_021E106C(p);
    func_02049B40(23,5,4,448,32,((struct Obj01055 *)p)->f5F4);
    v=(void *)func_020450F0(6,(u8)x,(u8)y,(u8)w,h,(u32)14,(u32)0);
    ((struct Obj01055 *)p)->f71C=v;
    func_02043B5C(func_02045770(v),15);
    func_0201DD78(1,2,15);
    if(flag==0) {
        ((struct Obj01055 *)p)->f72C=func_0201CCE4((u32)v,0,0,*(u32 *)&((struct Obj01055 *)p)->f738,*(u32 *)&((struct Obj01055 *)p)->f728,func_02012FFC(),((struct Obj01055 *)p)->f744,2,((struct Obj01055 *)p)->f5F4,15);
        func_02028470((u8 *)p+0x11d4,2);
    } else {
        func_0201C7A4(func_02045770(v),0,0,((struct Obj01055 *)p)->f738,((struct Obj01055 *)p)->f728);
    }
    func_0201F73C(v,1,(u16)(((struct Obj01055 *)p)->f644),15);
    func_02045334(v);func_02045374(v);func_02041B6C(6);
}

void func_021E0FF4(void *p, int a, int flag)
{
    if (flag) {
        func_021E0EF4(p, a, 1, 0x12, 0x1E, 4);
        return;
    }
    func_021E0EF4(p, a, 1, 1, 0x1E, 4);
}

void func_021E1024(void *p) { func_021E0FF4(p, 0, 0); }

void func_021E1030(char *p)
{
    if (((struct Obj00001 *)p)->f5F0) {
        func_0202F038(((struct Obj00001 *)p)->f5F0);
        ((struct Obj00001 *)p)->f5F0 = 0;
    }
    ((struct Obj00001 *)p)->f5F0 = func_0202EE8C((u32)(((struct Obj00001 *)p)->f744), ((struct Obj00001 *)p)->f71C, 0xF, 0x10, ((struct Obj00001 *)p)->f5F4);
}

void func_021E106C(char *p)
{
    if (((struct Obj05330 *)p)->f5F0) {
        func_0202F038(((struct Obj05330 *)p)->f5F0);
        ((struct Obj05330 *)p)->f5F0 = 0;
    }
    if (((struct Obj05330 *)p)->f71C) {
        func_020452E8(((struct Obj05330 *)p)->f71C);
        ((struct Obj05330 *)p)->f71C = 0;
    }
}

void func_021E1098(char *p) { if(*(int *)&((struct Obj00001 *)p)->f5F0) {func_0202F038((u8 *)(*(int *)&((struct Obj00001 *)p)->f5F0));*(int *)&((struct Obj00001 *)p)->f5F0=0;} if(*(int *)&((struct Obj00001 *)p)->f71C) {func_020456F8((struct Descriptor *)(*(int *)&((struct Obj00001 *)p)->f71C));func_02041B6C(6);func_0201F7A8((void *)(*(int *)&((struct Obj00001 *)p)->f71C),2);func_020452E8((struct Descriptor *)(*(int *)&((struct Obj00001 *)p)->f71C));*(int *)&((struct Obj00001 *)p)->f71C=0;} }

void func_021E10D8(char *p)
{
    ((struct Obj00001 *)p)->f724=func_0201EC64(((struct Obj00001 *)p)->f5F4);
    ((struct Obj00001 *)p)->f720=func_02045B38(0,2,159,((struct Obj00001 *)p)->f5F4);
    ((struct Obj00001 *)p)->f728=func_0201D7EC(23,0,0,0,((struct Obj00001 *)p)->f5F4);
    ((struct Obj00001 *)p)->f730=func_020457B0(128,((struct Obj00001 *)p)->f5F4);
    ((struct Obj00001 *)p)->f734=func_020457B0(128,((struct Obj00001 *)p)->f5F4);
    ((struct Obj00001 *)p)->f738=func_020457B0(128,((struct Obj00001 *)p)->f5F4);
    ((struct Obj00001 *)p)->f73C=func_020457B0(128,((struct Obj00001 *)p)->f5F4);
    ((struct Obj00001 *)p)->f740=(void *)func_0201C440((void *)(((struct Obj00001 *)p)->f5F4));
    func_0201DD78(1,2,15);
    ((struct Obj00001 *)p)->f744=func_0203101C(((struct Obj00001 *)p)->f5F4,((struct Obj00001 *)p)->f5F4,2,0);
    ((struct Obj00001 *)p)->f74C=func_02028590(15,1,0,((struct Obj00001 *)p)->f5F4);
    ((struct Obj00001 *)p)->f6B0=func_02027F60(6,9,*(u32 *)&((struct Obj00001 *)p)->f728,*(u32 *)&((struct Obj00001 *)p)->f740,((struct Obj00001 *)p)->f5F4);
}

void func_021E11A8(char *p)
{
    int i;
    func_0200566C();
    if(*(int *)&((struct Obj00001 *)p)->f744) {
        func_02028604((int)(((struct Obj00001 *)p)->f74C));
        func_021E106C(p);
        func_021E12F8(p);
        if(((struct Obj00001 *)p)->f72C) {func_0201CE48((struct Rec3 *)(((struct Obj00001 *)p)->f72C));((struct Obj00001 *)p)->f72C=0;}
        if(((struct Obj00001 *)p)->f648) {func_02028148(((struct Obj00001 *)p)->f648);((struct Obj00001 *)p)->f648=0;}
        if(((struct Obj00001 *)p)->f6B0) {func_02027FD8(((struct Obj00001 *)p)->f6B0);((struct Obj00001 *)p)->f6B0=0;}
        if(((struct Obj00001 *)p)->f6B4) {func_020452E8(((struct Obj00001 *)p)->f6B4);((struct Obj00001 *)p)->f6B4=0;}
        for(i=0;i<2;i++) {if(*(void **)(p+i*4+0x5bc)) {func_020452E8(*(void **)(p+i*4+0x5bc));*(void **)(p+i*4+0x5bc)=0;}}
        func_0201ED04(((struct Obj00001 *)p)->f724);
        func_02045C04(((struct Obj00001 *)p)->f720);
        func_0201D83C(((struct Obj00001 *)p)->f728);
        func_02045808(((struct Obj00001 *)p)->f730);
        func_02045808(((struct Obj00001 *)p)->f734);
        func_02045808(((struct Obj00001 *)p)->f738);
        func_02045808(((struct Obj00001 *)p)->f73C);
        func_0201C6EC((struct PrintSys *)(*(unsigned *)&((struct Obj00001 *)p)->f740));
        func_0201C4C0((struct PrintSys *)(*(unsigned *)&((struct Obj00001 *)p)->f740));
        func_02031140(((struct Obj00001 *)p)->f744);
        *(int *)&((struct Obj00001 *)p)->f744=0;
    }
}

int func_021E12AC(char *p) {int v=1;if(((struct Obj00001 *)p)->f72C) {if(*(int *)&((struct Obj00001 *)p)->f71C)func_020286C4((struct Ctx *)(*(int *)&((struct Obj00001 *)p)->f74C),(void *)(((struct Obj00001 *)p)->f72C),(void *)(*(int *)&((struct Obj00001 *)p)->f71C));v=func_02028484((struct Blk *)(p+0x11d4),(void *)(((struct Obj00001 *)p)->f72C));if(v) {if(((struct Obj00001 *)p)->f72C) {func_0201CE48((struct Rec3 *)(((struct Obj00001 *)p)->f72C));((struct Obj00001 *)p)->f72C=0;}}}return v;}

void func_021E12F8(char *p)
{
    if (((struct Obj00001 *)p)->f64C) {
        *(volatile unsigned short *)0x04000050 = 0;
        func_02027858(((struct Obj00001 *)p)->f64C);
        ((struct Obj00001 *)p)->f64C = 0;
    }
}

void func_021E131C(char *p,int *ids,int count,int x,int y)
{
    Template t;
    int i;
    t.heap=((struct Obj00001 *)p)->f5F4;
    t.count=count;
    t.items=p+0x650;
    t.flag=1;
    t.x=x;t.y=y;t.a=13;t.b=3;
    for(i=0;i<count;i++) {
        *(void **)(p+(u32)i*12+0x650)=func_020457B0(100,((struct Obj00001 *)p)->f5F4);
        func_02045CAC(((struct Obj00001 *)p)->f720,ids[i],*(void **)(p+(u32)i*12+0x650));
        *(u16 *)(p+(u32)i*12+0x654)=0x39e3;
        if(ids[i]==5) *(int *)(p+(u32)i*12+0x658)=1;
        else *(int *)(p+(u32)i*12+0x658)=0;
    }
    ((struct Obj00001 *)p)->f64C=func_02027778((struct TaskMenuTmpl *)(&t),((struct Obj00001 *)p)->f6B0);
    for(i=0;i<count;i++) func_02045808(*(void **)(p+(u32)i*12+0x650));
}

void func_021E1410(void *p, int *ids, int count)
{
    if (count == 1) {
        func_021E131C(p, ids, count, 0x20, 0x15);
        return;
    }
    func_021E131C(p, ids, count, 0x20, 0x18);
}

void func_021E1430(void *a,void *b,int x,int y,int flag,int mode,char *p) {if(!flag) {if(mode) {func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720),28,(void *)(*(int *)&((struct Obj00001 *)p)->f734));func_0201EE84(((struct Obj00001 *)p)->f724,0,a);}else {func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720),29,(void *)(*(int *)&((struct Obj00001 *)p)->f734));func_0201EEF4(((struct Obj00001 *)p)->f724,0,a);}func_0201F250((struct WordSet *)(*(int *)&((struct Obj00001 *)p)->f724),(void *)(*(int *)&((struct Obj00001 *)p)->f730),(void *)(*(int *)&((struct Obj00001 *)p)->f734));}else {func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720),105,(void *)(*(int *)&((struct Obj00001 *)p)->f730));}func_0201C7A4(b,x,y,(void *)(*(int *)&((struct Obj00001 *)p)->f730),(void *)(*(int *)&((struct Obj00001 *)p)->f728));}

void func_021E14DC(void *a,void *b,int x,int y,int flag,char *p) {int v;u16 *t;if(!flag) {v=func_02017E1C(a,171,0);if(!((struct Obj00001 *)p)->f11F6) {t=func_0201AF80(((struct Obj00001 *)p)->f5F4,0);v=t[v];func_020307B0(t);}if(v==999) {func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720),162,(void *)(*(int *)&((struct Obj00001 *)p)->f730));}else {func_0201EFA4((struct WordSet *)(*(int *)&((struct Obj00001 *)p)->f724),1,v,3,1,1);func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720),27,(void *)(*(int *)&((struct Obj00001 *)p)->f734));func_0201F250((struct WordSet *)(*(int *)&((struct Obj00001 *)p)->f724),(void *)(*(int *)&((struct Obj00001 *)p)->f730),(void *)(*(int *)&((struct Obj00001 *)p)->f734));}func_0201C7A4(b,x,y,(void *)(*(int *)&((struct Obj00001 *)p)->f730),(void *)(*(int *)&((struct Obj00001 *)p)->f728));}}

void func_021E1594(void *a,void *b,int x,int y,int flag,char *p) {if(!flag) {func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720),28,(void *)(*(int *)&((struct Obj00001 *)p)->f734));func_0201EE84(((struct Obj00001 *)p)->f724,0,a);func_0201F250((struct WordSet *)(*(int *)&((struct Obj00001 *)p)->f724),(void *)(*(int *)&((struct Obj00001 *)p)->f730),(void *)(*(int *)&((struct Obj00001 *)p)->f734));func_0201C7A4(b,x,y,(void *)(*(int *)&((struct Obj00001 *)p)->f730),(void *)(*(int *)&((struct Obj00001 *)p)->f728));}}

void func_021E15F8(void *a,void *b,int x,int y,char *p) {func_02017E1C(a,171,0);func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720),18,(void *)(*(int *)&((struct Obj00001 *)p)->f734));func_0201EFA4((struct WordSet *)(*(int *)&((struct Obj00001 *)p)->f724),0,func_02017E1C(a,158,0),3,1,1);func_0201F250((struct WordSet *)(*(int *)&((struct Obj00001 *)p)->f724),(void *)(*(int *)&((struct Obj00001 *)p)->f730),(void *)(*(int *)&((struct Obj00001 *)p)->f734));func_0201C7A4(b,x,y,(void *)(*(int *)&((struct Obj00001 *)p)->f730),(void *)(*(int *)&((struct Obj00001 *)p)->f728));}

void func_021E1670(void *a,void *b,int x,int y,char *p,int mode,int guard) {int v,w,id,color;v=func_02017E1C(a,110,0);w=func_02017E1C(a,173,0);id=func_02017E1C(a,5,0);if(v<=1 && w!=0 && !(guard && id==29) && !(guard && id==32)) {if(mode) {if(v==1)color=0x31a0;else color=0x39e0;}else {if(v==1)color=0xc80;else color=0x14c0;}func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720),v+46,(void *)(*(int *)&((struct Obj00001 *)p)->f730));func_0201C7D0(b,x,y,*(int *)&((struct Obj00001 *)p)->f730,*(int *)&((struct Obj00001 *)p)->f728,color);}}

void func_021E1718(int a,int b,int x,int y,char *p)
{
    int i;
    for(i=0;i<6;i++) {
        func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720),30+i,(void *)(*(int *)&((struct Obj00001 *)p)->f730));
        func_0201C7A4(func_02045770((struct Descriptor *)b),x,y+16*i,((struct Obj00001 *)p)->f730,((struct Obj00001 *)p)->f728);
    }
}

void func_021E1778(int a,int b,int x,int y,char *p)
{
    int v;
    func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720),43,(void *)(*(int *)&((struct Obj00001 *)p)->f734));
    v=func_02017E1C((void *)a,6,0);
    if(v) {
        func_0201EF40((struct WordSet *)(*(int *)&((struct Obj00001 *)p)->f724),0,v);
        func_0201F250((struct WordSet *)(*(int *)&((struct Obj00001 *)p)->f724),(void *)(*(int *)&((struct Obj00001 *)p)->f730),(void *)(*(int *)&((struct Obj00001 *)p)->f734));
        func_0201C7A4(func_02045770((struct Descriptor *)b),x,y,((struct Obj00001 *)p)->f730,((struct Obj00001 *)p)->f728);
    }
}

void func_021E17E8(int a,int b,int x,int y,char *p)
{
    int v,w;
    func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720),39,(void *)(*(int *)&((struct Obj00001 *)p)->f734));
    v=func_02017E1C((void *)a,160,0);
    w=func_02017E1C((void *)a,161,0);
    func_0201EFA4((struct WordSet *)(*(int *)&((struct Obj00001 *)p)->f724),0,v,3,1,1);
    func_0201EFA4((struct WordSet *)(*(int *)&((struct Obj00001 *)p)->f724),1,w,3,1,1);
    func_0201F250((struct WordSet *)(*(int *)&((struct Obj00001 *)p)->f724),(void *)(*(int *)&((struct Obj00001 *)p)->f730),(void *)(*(int *)&((struct Obj00001 *)p)->f734));
    func_0201C7A4(func_02045770((struct Descriptor *)b),x,y,((struct Obj00001 *)p)->f730,((struct Obj00001 *)p)->f728);
}

void func_021E1880(int a, int b, int c, int d, char *p)
{
    int i = 0;
    T5 t = d_021E7984;
    for (; i < 5; i++) {
        func_02045CAC(((struct Obj00001 *)p)->f720, 0x28, ((struct Obj00001 *)p)->f734);
        func_0201EFA4(((struct Obj00001 *)p)->f724, 0, func_02017E1C((void *)a, t.v[i], 0), 3, 1, 1);
        func_0201F250(((struct Obj00001 *)p)->f724, ((struct Obj00001 *)p)->f730, ((struct Obj00001 *)p)->f734);
        func_0201C7A4(func_02045770((struct Descriptor *)b), (s16_021E1880)c, (s16_021E1880)(d + i * 16), ((struct Obj00001 *)p)->f730, ((struct Obj00001 *)p)->f728);
    }
}

void func_021E194C(int a,int b,int x,int y,char *p)
{
    func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720),44,(void *)(*(int *)&((struct Obj00001 *)p)->f730));
    func_0201C7A4(func_02045770((struct Descriptor *)b),x,y,((struct Obj00001 *)p)->f730,((struct Obj00001 *)p)->f728);
}
