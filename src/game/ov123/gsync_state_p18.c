/*
 * file:     gsync_state_p18.c
 * unit:     yes
 * function: func_021D8A9C, func_021D8B0C, func_021D8B7C, func_021D8C04, func_021D8D08, func_021D8D98, func_021D8DFC, func_021D8E28, func_021D8E68, func_021D8E98, func_021D8EC4, func_021D8F3C, func_021D8F58, func_021D8FBC, func_021D9158, func_021D920C, func_021D92B8, func_021D92CC, func_021D9404, func_021D941C, func_021D9514, func_021D95B4, func_021D95F0, func_021D9634, func_021D9670, func_021D9730, func_021D97B0, func_021D97CC, func_021D9844, func_021D9918, func_021D9958, func_021D9A14, func_021D9A1C, func_021D9AE8, func_021D9D34, func_021D9D3C, func_021D9F40, func_021D9FB0, func_021D9FD4, func_021DA034, func_021DA03C, func_021DA054, func_021DA090, func_021DA0B8, func_021DA0E4, func_021DA110, func_021DA138, func_021DA16C, func_021DA1A0, func_021DA1C8, func_021DA1EC, func_021DA244, func_021DA268, func_021DA290, func_021DA2DC, func_021DA308, func_021DA328, func_021DA3A0, func_021DA408, func_021DA434, func_021DA45C, func_021DA478, func_021DA54C
 * address:  0x021D8A9C
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_021D66D0 0x021D66D0 thumb ov123
 *   func_021D57D0 0x021D57D0 thumb ov123
 *   func_021D56FC 0x021D56FC thumb ov123
 *   func_021D62B4 0x021D62B4 thumb ov123
 *   func_021D6650 0x021D6650 thumb ov123
 *   func_021D62BC 0x021D62BC thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D8A7C 0x021D8A7C thumb ov123
 *   func_0203C9AC 0x0203C9AC arm
 *   func_0203C938 0x0203C938 arm
 *   func_0203F4E4 0x0203F4E4 arm
 *   func_020093D8 0x020093D8 thumb
 *   func_02009428 0x02009428 thumb
 *   func_020093F0 0x020093F0 thumb
 *   func_021D6934 0x021D6934 thumb ov123
 *   func_021D6EA4 0x021D6EA4 thumb ov123
 *   func_021D6E70 0x021D6E70 thumb ov123
 *   func_021D5950 0x021D5950 thumb ov123
 *   func_021D59E4 0x021D59E4 thumb ov123
 *   func_021D5A60 0x021D5A60 thumb ov123
 *   func_021D6E08 0x021D6E08 thumb ov123
 *   func_021D6FF0 0x021D6FF0 thumb ov123
 *   func_021B99DC 0x021B99DC thumb ov114
 *   func_021B9790 0x021B9790 thumb ov114
 *   func_021B97F4 0x021B97F4 thumb ov114
 *   func_020071D8 0x020071D8 thumb
 *   func_021D580C 0x021D580C thumb ov123
 *   func_021B95D4 0x021B95D4 thumb ov114
 *   func_021B973C 0x021B973C thumb ov114
 *   func_021B9748 0x021B9748 thumb ov114
 *   func_021BE79C 0x021BE79C arm ov114
 *   func_021D65F4 0x021D65F4 thumb ov123
 *   func_021D57B8 0x021D57B8 thumb ov123
 *   func_021D5A7C 0x021D5A7C thumb ov123
 *   func_021D62A8 0x021D62A8 thumb ov123
 *   func_021D651C 0x021D651C thumb ov123
 *   func_020185F0 0x020185F0 thumb
 *   func_021D6458 0x021D6458 thumb ov123
 *   func_02009294 0x02009294 thumb
 *   func_020092F8 0x020092F8 thumb
 *   func_021B9774  0x021B9774  thumb  ov114
 *   func_021B9838  0x021B9838  thumb  ov114
 *   func_02009290 0x02009290 thumb
 *   func_02082D44 0x02082D44 arm
 *   ov114_id 0x00000072 data
 *   func_02034AC4 0x02034AC4 arm
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02034714 0x02034714 arm
 *   func_020092EC 0x020092EC thumb
 *   func_021D87F8 0x021D87F8 thumb ov123
 *   func_021D88A0 0x021D88A0 thumb ov123
 *   func_021D5D94 0x021D5D94 thumb ov123
 *   func_021D54F4 0x021D54F4 thumb ov123
 *   func_021B9800 0x021B9800 thumb ov114
 *   func_02156DC4 0x02156DC4 thumb ov009
 *   func_0203D34C 0x0203D34C arm
 *   d_021DABA4 0x021DABA4 data a1
 *   func_0200F7C0 0x0200F7C0 thumb
 *   func_021D5D58 0x021D5D58 thumb ov123
 *   func_02157170 0x02157170 thumb ov009
 *   func_021D5D7C 0x021D5D7C thumb ov123
 *   func_021D5E60 0x021D5E60 thumb ov123
 *   func_021D562C 0x021D562C thumb ov123
 *   func_0200FB24 0x0200FB24 thumb
 *   func_021D5644 0x021D5644 thumb ov123
 *   func_021D5E8C 0x021D5E8C thumb ov123
 *   func_021D5B70 0x021D5B70 thumb ov123
 *   func_0203CD98 0x0203CD98 arm
 *   func_02156DE0 0x02156DE0 thumb ov009
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_02051C6C  0x02051C6C  arm
 *   func_02030734 0x02030734 arm
 *   func_02045088 0x02045088 arm
 *   func_0203101C 0x0203101C arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02049B40 0x02049B40 arm
 *   d_021DABA8 0x021DABA8 data ov123 a1
 *   func_020310C4  0x020310C4  arm
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_020452E8 0x020452E8 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_02045C04 0x02045C04 arm
 *   func_02045808 0x02045808 arm
 *   func_02031140 0x02031140 arm
 *   func_020450C8 0x020450C8 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0202F038 0x0202F038 thumb
 *   func_0202EE8C 0x0202EE8C thumb
 *   func_020362DC 0x020362DC arm
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_020456F8 0x020456F8 arm
 *   func_0207D658 0x0207D658 arm
 *   func_02027778 0x02027778 thumb
 *   func_0203F1FC 0x0203F1FC arm
 *   func_0204581C 0x0204581C arm
 *   func_02045AFC 0x02045AFC arm
 *   d_021DA868 0x021DA868 data a2
 *   d_021DA864 0x021DA864 data a2
 *   ov067_id 0x00000043 data
 *   func_02043534 0x02043534 arm
 *   func_020435F4 0x020435F4 arm
 *   func_0204363C 0x0204363C arm
 *   func_0207D46C 0x0207D46C arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_020433E0 0x020433E0 arm
 *   func_0203FC28 0x0203FC28 arm
 *   d_021DABFC 0x021DABFC data a1
 *   d_021DABCC 0x021DABCC data a4
 *   d_020A1464 0x020A1464 data a4
 *   d_021DABBC 0x021DABBC data a4
 *   func_0204A600 0x0204A600 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_02040DA8 0x02040DA8 arm
 *   func_020403F4 0x020403F4 arm
 *   func_02040588 0x02040588 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   ov_id 0x00000043 data
 *   d_021DA8A8      0x021DA8A8  data
 *   func_0203FCA0   0x0203FCA0  arm
 *   func_020409B4   0x020409B4  arm
 *   func_02040C14   0x02040C14  arm
 *   func_02041300   0x02041300  arm
 *   func_0204A648 0x0204A648 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049F78 0x02049F78 arm
 *   func_02021F64 0x02021F64 thumb
 *   func_020862F0 0x020862F0 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_0207D63C 0x0207D63C arm
 *   func_02049238 0x02049238 arm
 *   func_0207E3D0 0x0207E3D0 arm
 *   func_0207E468 0x0207E468 arm
 *   func_02040618 0x02040618 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_020221A4  0x020221A4  thumb
 *   func_0202208C 0x0202208C thumb
 *   func_02005E30 0x02005E30 thumb
 *   func_02012DD0 0x02012DD0 thumb
 *   func_02012DAC 0x02012DAC thumb
 *   func_02009448 0x02009448 thumb
 *   func_020092E0 0x020092E0 thumb
 */
#include "../../matched/include/Obj02183.h"
#include "../../matched/include/Obj03272.h"
#include "../../matched/include/Obj05369.h"
#include "../../matched/include/Obj00063.h"
#include "../../matched/include/Obj22982.h"
#include "../../matched/include/Obj03798.h"
#include "../../matched/include/Obj10451.h"
#include "../../matched/include/Obj06469.h"
#include "../../matched/include/Obj08114.h"
#include "../../matched/include/Obj10452.h"
#include "../../matched/include/Obj01545.h"
#include "../../matched/include/Obj08115.h"
#include "../../matched/include/Obj02476.h"
#include "../../matched/include/Obj01059.h"
#include "../../matched/include/Obj03799.h"
#include "../../matched/include/Obj01406.h"
#include "../../matched/include/Obj22983.h"
#include "../../matched/include/Obj00990.h"
#include "../../matched/include/Obj10453.h"
#include "../../matched/include/Obj00500.h"
#include "../../matched/include/Obj13998.h"
#include "../../matched/include/Obj00534.h"
#include "../../matched/include/Obj02477.h"
#include "../../matched/include/Obj04501.h"
#include "../../matched/include/Obj06470.h"
#include "../../matched/include/Obj03800.h"
#include "../../matched/include/Obj03801.h"
#include "../../matched/include/Obj13999.h"
#include "../../matched/include/Obj01737.h"
#include "../../matched/include/Obj03273.h"
#include "../../matched/include/Obj05370.h"
#include "../../matched/include/Obj03802.h"
#include "../../matched/include/Obj03274.h"
#include "../../matched/include/Obj10454.h"
#include "../../matched/include/Obj03804.h"
#include "../../matched/include/Obj22984.h"
#include "../../matched/include/Obj22985.h"
#include "../../matched/include/Obj22986.h"
#include "../../matched/include/Obj10455.h"
#include "../../matched/include/Obj10456.h"
#include "../../matched/include/Obj14000.h"
#include "../../matched/include/Obj14001.h"
#include "../../matched/include/Obj08116.h"
#include "../../matched/include/Obj08117.h"
#include "../../matched/include/Obj03803.h"
#include "../../matched/include/Obj22987.h"
#include "../../matched/include/Obj14002.h"
#include "../../matched/include/Obj06471.h"
#include "../../matched/include/Obj10457.h"
#include "../../matched/include/Obj22988.h"
#include "../../matched/include/Obj22989.h"
#include "../../matched/include/Obj08118.h"
#include "../../matched/include/Obj08119.h"
#include "../../matched/include/Obj02478.h"
#include "../../matched/include/Obj03275.h"
#include "../../matched/include/Obj03276.h"
#include "../../matched/include/Obj22990.h"

struct Sub02009210Obj;
struct Sub02009448Obj;
struct Sub02008C20Obj;
struct Obj;
struct Ctrl020071D8;
struct Obj02181;
struct Mon;
struct Sub020079BCEntry;
struct Sav;
struct Sub020075B0Entry;
struct Obj0203159C;
struct Big;
struct BigObj;
struct Sub0200852CObj;
struct S020315D4;
struct TaskMenu;
struct GfFont;
struct R;
struct Tcbl;
struct U16Vec;
struct WordSet;
struct MsgBank;
struct PrintSys;
struct Descriptor;
struct Rec;
struct Rec3;
struct S02031140;
struct TaskMenuState;
struct Cfg;
struct CharBuf;
struct TaskMenuTmpl;
struct Bank;
struct DispConfig;
struct DispVram;
struct Node;
typedef unsigned int   u32;

typedef unsigned char  u8;

struct RtcDate { u32 year, month, day, week; };

typedef unsigned short u16;

typedef signed int     s32;

typedef struct Config { u32 size; u8 flag; u8 pad[3]; void *target; u32 mode; u8 x,y,z,w; } Config;

typedef unsigned long long u64;

typedef struct { u16 a[32]; } Table;

typedef enum { C0=0 } Counter;

struct BgTemplate {
    u32 unk_00;
    u32 unk_04;
    u32 bufSize;
    u32 unk_0c;
    u8  unk_10;
    u8  unk_11;
    u8  unk_12;
    u8  unk_13;
    u32 unk_14;
    u8  unk_18;
    u8  unk_19;
    u8  unk_1a;
    u8  unk_1b;
    u32 unk_1c;
};

typedef short s16;

extern unsigned int func_020307B0(void *p);
extern void func_021D66D0(u8 *p, int n);
extern void func_021D57D0(void *p, int msg, int n, void *mon);
extern void func_021D56FC(char *p, int mode);
extern void func_021D62B4(u8 *p, unsigned int i);
extern void func_021D6650(u8 *p, int flag);
extern void func_021D62BC(u8 *p, int i, u32 v);
extern void func_020061E4(u32 a);
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern void func_021D8A7C(char *p);
extern int func_02012DD0(u8 *p);
extern void func_0203C9AC(int a, u32 b, u32 c, u32 d);
extern u32 func_0203C938(u8 mode);
extern struct Sub02009448Obj *func_02009448(void *sys);
extern void func_0203F4E4(struct RtcDate *);
extern void func_020093CC(struct Sub02009210Obj *obj, u32 value);
extern u32 func_020093D8(const struct Sub02009210Obj *obj);
extern void func_02009428(struct Sub02009210Obj *obj, int value);
extern void func_020093F0(struct Sub02009210Obj *obj, int value);
extern void *func_02012F2C(int *p);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern int func_02012DAC(int a0);
extern void func_021D6934(struct Obj *p);
extern int func_021D6EA4(char *);
extern int func_021D6E70(u8 *p);
extern int func_021D5950(u8 *,int);
extern void func_021D59E4(char *);
extern void func_021D5A60(char *);
extern int func_021D6E08(char *,int);
extern int func_021B99DC(u8 *p);
extern int func_021B9790(u8 *p);
extern char *func_021B97F4(void *);
extern void func_021D6FF0(char *);
extern int func_021D580C(char *);
extern int func_021B95D4(int index, u8 *p);
extern int func_021B973C(char *p);
extern int func_021B9748(u8 *p);
extern int func_021BE79C(void *handle, void *value_p, unsigned long length);
extern void *func_020071D8(struct Ctrl020071D8 *ctrl, int *out);
extern void func_021D65F4(unsigned char *p);
extern void func_021D57B8(char *,int);
extern void func_021D5A7C(char *);
extern void func_021D62A8(u8 *p);
extern void func_021D651C(unsigned char *);
extern int func_020185F0(void *);
extern void func_021D6458(struct Obj02181 *p, void *n, int i);
extern struct Sub020079BCEntry *func_02007A18(void **save, u32 box, u32 slot);
extern void *func_0201747C(struct Mon *p, u32 heap);
extern void func_02009294(struct Sub02009210Obj *obj, const void *src);
extern void func_02007664(void *save, u32 box, u32 slot);
extern void func_020092F8(struct Sub02009210Obj *obj, u8 value);
extern void func_021B9774(u8 *p);
extern void func_021B9838(u8 *p);
extern u32 func_02009228(void);
extern void func_02082D44(void *, void *, int);
extern u8 *func_02009290(struct Sub02009210Obj *obj);
extern void *func_020185F4(void *);
extern int func_020075B0(void *save, u32 box, u32 slot, const struct Sub020075B0Entry *src);
extern void func_02017528(struct Sav *p);
extern int func_02034AC4(signed int);
extern void func_0203064C(u32 src, u32 dst, u32 size);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,u8,u32);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *func_02012EBC(struct Big *p);
extern u8 *func_02012944(void *p);
extern u32 func_0200853C(const struct Sub0200852CObj *obj);
extern u32 func_0201293C(const struct BigObj *p);
extern u8 func_020092EC(const struct Sub02009210Obj *obj);
extern void func_021D87F8(char *);
extern void func_021D88A0(char *);
extern u8 *func_021B9800(int,int,int);
extern void func_02156DC4(int,int);
extern u8 *func_021D5D94(u32);
extern u8 *func_021D54F4(u32,u32);
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern void func_0203D34C(u32,u32);
extern unsigned int func_020221A4(void);
extern u32 func_0200FB24(void);
extern int func_021D5D58(char *p);
extern void func_02012E08(char *p);
extern void func_0200F7C0(u32 value);
extern void func_0202223C(u32 a, u32 color);
extern int func_02157170(int a0, int a1);
extern void func_02027974(void *);
extern void func_021D5D7C(char *p);
extern void func_021D5E60(u8 *p);
extern void func_021D562C(char *p);
extern void func_02027858(struct TaskMenu *m);
extern void func_021D5644(char *p);
extern void func_021D5E8C(u8 *p);
extern void func_021D5B70(char *p);
extern int func_0203CD98(void);
extern void func_02156DE0(int,int);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern void func_02034A5C(int handle);
extern void func_02051C6C(void *);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_02045088(u16);
extern void func_0201DD60(void);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 func_0201C440(void *);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void *func_0201F5DC(void *,u32,u32,u32);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern void func_020310C4(struct Tcbl *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_0201DD68(void);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_0201CE48(struct Rec3 *p);
extern void func_0202F038(u8 *p);
extern void func_02031140(struct S02031140 *p);
extern void func_020450C8(void);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201DD78(unsigned int,unsigned int,unsigned int);
extern void *func_0201CCE4(void *,int,int,void *,void *,int,void *,int,u16,u16);
extern signed char func_02012FFC(void);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32 bit);
extern unsigned char *func_0202EE8C(unsigned int,void *,unsigned char,unsigned char,unsigned short);
extern u32 func_0201CE30(void *p);
extern void func_0201CE38(void *);
extern u32 func_020362DC(void);
extern void func_0201F7A8(void *desc, u32 kind);
extern void func_020456F8(struct Descriptor *d);
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern void func_0201C7A4(void *,short,short,void *,void *);
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern void func_0204581C(struct U16Vec *vec);
extern void func_02045AFC(struct U16Vec *vec, u16 value);
extern void func_0201D60C(void *s, u32 b, u32 c, u16 n, const u16 *arr);
extern void func_02043534(u32);
extern void func_020435F4(u32);
extern void func_0204363C(u32 swap);
extern void func_0207D46C(void);
extern void func_0203F8F4(u16 heapId);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203FC28(struct DispConfig *cfg);
extern void *func_020056A0(void *,void *,int);
extern void func_0204A600(void);
extern void func_0204ADA4(unsigned int i);
extern void func_0204A8D4(unsigned int i);
extern void func_0204AFD8(unsigned int i);
extern void func_02030EAC(struct Node *n);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void func_020403F4(unsigned int);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0203F9B4(void);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020409B4(u32);
extern void func_02040C14(u32, u32, u32, u32);
extern void func_02041300(u32, u32, u32, u32, u8, u8, u8);
extern void func_0204A648(void);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *, u32, u32, u32, u32, u16);
extern u32 func_02049658(void *, u32, u32, u32, u32, u32, u16);
extern void func_020498F4(void *, u32, u32, u32, u32, u32, u16);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02021F64(u16 *, u16 *, int, u8, u16);
extern void func_020862F0(void *, int);
extern void func_0207D63C(void *, int, int, int, int);
extern void func_02049238(void *);
extern void func_0207E3D0(void *, unsigned int, unsigned int);
extern void func_0207E468(void *, unsigned int, unsigned int);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_0204B3B4(struct Obj *p);
extern void func_02005E30(u32 a);
extern void func_020092E0(struct Sub02009210Obj *obj, u8 value);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern void func_02005D90(int,int);
void func_021D8A9C(char *p);
void func_021D8B0C(char *p);
void func_021D8B7C(char *p);
void func_021D8C04(char *p);
void func_021D8D08(char *p);
void func_021D8D98(char *p);
void func_021D8DFC(char *p);
void func_021D8E28(char *p);
void func_021D8E68(char *p);
void func_021D8E98(char *p);
void func_021D8EC4(char *p);
void func_021D8F3C(char *p);
void func_021D8F58(char *p);
int func_021D8FBC(void *a,int b,char *q);
int func_021D9158(void *a, int b, int c, char *p);
int func_021D920C(void *a, int b, int c, char *p);
void func_021D92B8(u8 *p);
u8 *func_021D92CC(u32 heap,u32 bank);
void func_021D9404(char *p);
void func_021D941C(u8 *p);
void func_021D9514(char *p, int n);
void func_021D95B4(char *p);
int func_021D95F0(char *p);
void func_021D9634(char *p);
int func_021D9670(char *p,int mode);
void func_021D9730(char *p, int n);
void func_021D97B0(char *p);
void func_021D97CC(int value, void *p);
void func_021D9844(char *p, int n, int a2);
void func_021D9918(char *p);
char *func_021D9958(int heap);
void func_021D9A14(int a0);
void func_021D9A1C(u8 *p);
void func_021D9AE8(void *a0);
void func_021D9D34(void);
void func_021D9D3C(char *p);
void func_021D9F40(void *unused, char *p);
void func_021D9FB0(unsigned int p);
int func_021D9FD4(char *p, int n);
void func_021DA030(char *p, int n, int unused);
void func_021DA034(char *p, int n, int unused);
void func_021DA03C(char *p);
void func_021DA054(char *p);
void func_021DA090(char *p);
void func_021DA0B8(char *p);
void func_021DA0E4(char *p);
void func_021DA110(char *p);
void func_021DA138(char *p);
void func_021DA16C(char *p);
void func_021DA1A0(char *p);
void func_021DA1C8(char *p);
void func_021DA1EC(char *p);
void func_021DA244(char *p);
void func_021DA268(char *p);
void func_021DA290(char *p);
void func_021DA2DC(char *p);
void func_021DA308(char *p);
void func_021DA328(char *p);
void func_021DA3A0(char *p);
void func_021DA408(char *p);
void func_021DA434(char *p);
void func_021DA45C(char *p);
int func_021DA478(void *a,int unused,char *q);
int func_021DA54C(int a,int b,char *c,char *p);
extern char ov114_id[];
extern const char d_021DABA4[];
extern const char d_021DABA8[];
extern const Table d_021DA868;
extern const u16 d_021DA864;
extern const char d_021DABFC[];
extern char ov067_id[];
extern const u32 d_021DABCC[];
extern const u32 d_020A1464[];
extern const u32 d_021DABBC[];
extern u8 ov_id[];
extern const struct BgTemplate d_021DA8A8[8];

void func_021D8A9C(char *p)
{
    if (((struct Obj02183 *)p)->f44) {
        func_020307B0(((struct Obj02183 *)p)->f44);
        ((struct Obj02183 *)p)->f44=0;
    }
    ((struct Obj02183 *)p)->f70=100;
    func_021D66D0(((struct Obj02183 *)p)->f14,100);
    func_021D57D0(((struct Obj02183 *)p)->f18,14,0,(void *)(((struct Obj02183 *)p)->fC));
    func_021D56FC(((struct Obj02183 *)p)->f18,0);
    func_021D62B4(((struct Obj02183 *)p)->f14,8);
    func_021D6650(((struct Obj02183 *)p)->f14,0);
    func_021D62B4(((struct Obj02183 *)p)->f14,0);
    func_021D62BC(((struct Obj02183 *)p)->f14,4,6);
    func_020061E4(0x658);
    func_021D6EE0((u8 *)p,(int)func_021D8A7C,0x8bd);
}

void func_021D8B0C(char *p)
{
    if (((struct Obj03272 *)p)->f70<100) ++((struct Obj03272 *)p)->f70;
    func_021D66D0(((struct Obj03272 *)p)->f14,((struct Obj03272 *)p)->f70);
    switch (func_02012DD0(((struct Obj03272 *)p)->f2C)) {
    case 1:
        if (((struct Obj03272 *)p)->f34) {
            func_020307B0(((struct Obj03272 *)p)->f34);
            ((struct Obj03272 *)p)->f34=0;
        }
        break;
    case 3:
        func_0203C9AC(0,0,0,0x3f3);
        func_0203C938(0);
        break;
    case 2:
        p[0xad]=0;
        func_021D6EE0((u8 *)p,(int)func_021D8A9C,0x8e6);
        break;
    }
}

/*
 * lever: func_02012F2C leaves its return in r0 for func_02008DF0.
 */
void func_021D8B7C(char *p)
{
    void *q;
    struct RtcDate date;
    q=func_02009448(((struct Obj05369 *)p)->f28);
    p[0xaa]=0;
    func_0203F4E4(&date);
    func_020093CC(q, (date.year << 24) | ((date.month & 255) << 16) | ((date.day & 255) << 8) | date.week);
    if (func_020093D8(q)!=127) {
        func_02009428(q,1);
        func_020093F0(q,126);
    }
    ((struct Obj05369 *)p)->f70=50;
    func_02008DF0(func_02012F2C(((struct Obj05369 *)p)->f2C),119);
    p[0xad]=1;
    func_02012DAC((int)(((struct Obj05369 *)p)->f2C));
    func_021D6EE0((u8 *)p,(int)func_021D8B0C,0x914);
}

void func_021D8C04(char *p)
{
    char *q;
    int state;
    func_02009448(((struct Obj00063 *)p)->f28);
    func_021D6934(((struct Obj00063 *)p)->f14);
    if (func_021D6EA4(p)) {
        if (((struct Obj00063 *)p)->f74==0) {
            func_021D5950(*(u8 * *)&((struct Obj00063 *)p)->f18,42);
            func_021D59E4(*(char * *)&((struct Obj00063 *)p)->f18);
        } else if (((struct Obj00063 *)p)->f74==360) {
            func_021D5950(*(u8 * *)&((struct Obj00063 *)p)->f18,43);
            func_021D59E4(*(char * *)&((struct Obj00063 *)p)->f18);
        } else if (((struct Obj00063 *)p)->f74==720) {
            func_021D5950(*(u8 * *)&((struct Obj00063 *)p)->f18,44);
            func_021D59E4(*(char * *)&((struct Obj00063 *)p)->f18);
        }
        ++((struct Obj00063 *)p)->f74;
    }
    if (func_021D6E70((u8 *)p)) {
        if (((struct Obj00063 *)p)->f70<50) ++((struct Obj00063 *)p)->f70;
        func_021D66D0(*(u8 * *)&((struct Obj00063 *)p)->f14,((struct Obj00063 *)p)->f70);
        if (func_021D6E08(p,func_021B99DC(((struct Obj00063 *)p)->f10))) return;
        if (func_021B9790(((struct Obj00063 *)p)->f10)) return;
        q=func_021B97F4(((struct Obj00063 *)p)->f10);
        if (func_021D6EA4(p)) func_021D5A60(*(char * *)&((struct Obj00063 *)p)->f18);
        state=((struct Obj22982 *)q)->f0;
        if (state==0) {
            func_021D6EE0((u8 *)p,(int)func_021D8B7C,0x955);
            return;
        }
        ((struct Obj00063 *)p)->f80=state;
        func_021D6EE0((u8 *)p,(int)func_021D6FF0,0x959);
        return;
    } else {
        func_021D66D0(*(u8 * *)&((struct Obj00063 *)p)->f14,((struct Obj00063 *)p)->f68);
        if (++((struct Obj00063 *)p)->f68==100) {
            if (func_021D6EA4(p)) func_021D5A60(*(char * *)&((struct Obj00063 *)p)->f18);
            func_021D6EE0((u8 *)p,(int)func_021D8B7C,0x967);
        }
    }
}

/*
 *   Run 2 also left ov114 0x021B973C unresolved; S23 has since verified its
 *   pkt_ov114_021B973C shard. No caller retry while ARM9 remains blocked.
 *   extern unsigned int func_02031994(void *, int *);
 *   unsigned int func_020071D8(char *p, int *out) {
 *       return func_02031994(*(void **)(p + 0x10), out);
 *   }
 */
void func_021D8D08(char *p)
{
    int x;
    unsigned int v;
    func_02009448(*(void **)(p+0x28));
    if (func_021D580C(*(char **)(p+0x18))) {
        *(int *)(p+0x74)=0;
        if (func_021D6E70((u8 *)p)) {
            if (func_021B95D4(3,*(void **)(p+0x10))) {
                v=(unsigned int)func_020071D8(*(void **)(p+0x28),&x);
                func_021BE79C((void *)func_021B973C(*(void **)(p+0x10)),(void *)v,0x80000);
                func_021D66D0(*(void **)(p+0x14),0);
                *(int *)(p+0x70)=0;
                if (!func_021B9748(*(void **)(p+0x10)))
                    func_021D6EE0((u8 *)p,(int)func_021D8C04,0x986);
            }
        } else {
            func_021D66D0(*(void **)(p+0x14),0);
            func_021D6EE0((u8 *)p,(int)func_021D8C04,0x98c);
        }
    }
}

void func_021D8D98(char *p)
{
    if (--((struct Obj03798 *)p)->f60==0) {
        func_021D65F4((unsigned char *)(*(char * *)&((struct Obj03798 *)p)->f14));
        func_021D57B8(*(char * *)&((struct Obj03798 *)p)->f18,8);
        func_021D5A7C(*(char * *)&((struct Obj03798 *)p)->f18);
        func_021D6650(((struct Obj03798 *)p)->f14,1);
        func_021D62BC(((struct Obj03798 *)p)->f14,4,5);
        func_021D62BC(((struct Obj03798 *)p)->f14,0,0);
        func_021D62B4(((struct Obj03798 *)p)->f14,12);
        func_020061E4(0x657);
        func_021D6EE0((u8 *)p,(int)func_021D8D08,0x9a8);
    }
}

void func_021D8DFC(char *p) { if(--((struct Obj10451 *)p)->f60==0) { func_021D62B4(((struct Obj10451 *)p)->f14,4); ((struct Obj10451 *)p)->f60=60; func_021D6EE0((u8 *)p,(int)func_021D8D98,0x9b9); } }

void func_021D8E28(char *p)
{
    if (--((struct Obj06469 *)p)->f60 == 0) {
        func_021D62BC(((struct Obj06469 *)p)->f14, 0, 1);
        func_021D62B4(((struct Obj06469 *)p)->f14, 2);
        func_021D62B4(((struct Obj06469 *)p)->f14, 3);
        ((struct Obj06469 *)p)->f60 = 15;
        func_021D6EE0((u8 *)p, (int)func_021D8DFC, 0x9cf);
    }
}

void func_021D8E68(char *p) { if(--((struct Obj08114 *)p)->f60==0) { func_021D62A8(((struct Obj08114 *)p)->f14); func_021D651C(((struct Obj08114 *)p)->f14); ((struct Obj08114 *)p)->f60=70; func_021D6EE0((u8 *)p,(int)func_021D8E28,0x9e4); } }

void func_021D8E98(char *p) { func_021D6458(((struct Obj10452 *)p)->f14,(void *)func_020185F0(((struct Obj10452 *)p)->fC),1); ((struct Obj10452 *)p)->f60=10; func_021D6EE0((u8 *)p,(int)func_021D8E68,0x9f6); }

void func_021D8EC4(char *p)
{
    void *v;
    void *q;
    void *t;
    v=func_02009448(((struct Obj01545 *)p)->f28);
    if (((struct Obj01545 *)p)->fC) {
        func_020307B0(((struct Obj01545 *)p)->fC);
        ((struct Obj01545 *)p)->fC=0;
    }
    t=func_02007A18(((struct Obj01545 *)p)->f24,((struct Obj01545 *)p)->f48,((struct Obj01545 *)p)->f4C);
    if (t) {
        q=func_0201747C(t,((struct Obj01545 *)p)->f0);
        func_02009294(v,q);
        ((struct Obj01545 *)p)->fC=q;
        func_02007664(((struct Obj01545 *)p)->f24,((struct Obj01545 *)p)->f48,((struct Obj01545 *)p)->f4C);
        func_020092F8(v,1);
        ((struct Obj01545 *)p)->fAA=1;
    }
    func_021D62B4(((struct Obj01545 *)p)->f14,0);
    func_021D62B4(((struct Obj01545 *)p)->f14,12);
    func_021D6EE0((u8 *)p,(int)func_021D8E98,0xa2a);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021D8F3C(char *p)
{
    if (*(u32 *)&((struct Obj08115 *)p)->f10 != 0) {
        func_021B9774(((struct Obj08115 *)p)->f10);
        func_021B9838(((struct Obj08115 *)p)->f10);
        *(u32 *)&((struct Obj08115 *)p)->f10 = 0;
    }
}

/*
 * extent: two zero alignment bytes follow the return.
 */
void func_021D8F58(char *p)
{
    void *v;
    void *q;
    v=func_02009448(((struct Obj02476 *)p)->f28);
    if (((struct Obj02476 *)p)->f34) {
        func_02082D44(((struct Obj02476 *)p)->f34,v,func_02009228());
        func_020307B0(((struct Obj02476 *)p)->f34);
        ((struct Obj02476 *)p)->f34=0;
    }
    if (((struct Obj02476 *)p)->fAA) {
        q=func_02009290(v);
        func_020075B0(((struct Obj02476 *)p)->f24,((struct Obj02476 *)p)->f48,((struct Obj02476 *)p)->f4C,func_020185F4(q));
        func_02017528(q);
        func_020092F8(v,0);
        ((struct Obj02476 *)p)->fAA=0;
    }
}

/*
 * interface: 0203159C returns the allocation live in r0 (original store
 * at 020315C0, then return); legacy matched definition says void.
 */
int func_021D8FBC(void *a,int b,char *q)
{
    char *p;
    int value;
    func_02034AC4((int)ov114_id);
    func_0203064C(1,98,0x88000);
    p=func_0203159C(a,0xb0,98);
    func_02082BCC(p,0,0xb0);
    ((struct Obj01059 *)p)->f0=98;
    if (!q) func_02034714(d_021DABA4,0,d_021DABA4);
    if (q) {
        *(char * *)&((struct Obj01059 *)p)->f20=q;
        ((struct Obj01059 *)p)->f2C=((struct Obj03799 *)q)->f4;
        ((struct Obj01059 *)p)->f28=func_02012EBC(((struct Obj03799 *)q)->f4);
        value=func_0200853C((const struct Sub0200852CObj *)func_02012944(((struct Obj03799 *)q)->f4));
        ((struct Obj01059 *)p)->f24=func_0201293C(((struct Obj03799 *)q)->f4);
        ((struct Obj01059 *)p)->f48=((struct Obj03799 *)q)->f1D0;
        ((struct Obj01059 *)p)->f4C=((struct Obj03799 *)q)->f1D2;
        ((struct Obj01059 *)p)->fAC=func_020092EC((const struct Sub02009210Obj *)func_02009448(((struct Obj01059 *)p)->f28));
        ((struct Obj01059 *)p)->fAF=((struct Obj01059 *)p)->fAC;
        func_02009448(((struct Obj01059 *)p)->f28);
        switch (((struct Obj03799 *)q)->f1C8) {
        case 0:
            if (!value) func_02034714(d_021DABA4,0,d_021DABA4);
            func_021D6EE0((u8 *)p,(int)func_021D87F8,0xa89);
            break;
        case 1:
            if (!value) func_02034714(d_021DABA4,0,d_021DABA4);
            func_021D6EE0((u8 *)p,(int)func_021D8EC4,0xa8d);
            break;
        case 2:
            if (!value) func_02034714(d_021DABA4,0,d_021DABA4);
            func_021D6EE0((u8 *)p,(int)func_021D8EC4,0xa91);
            break;
        case 3:
            if (!value) func_02034714(d_021DABA4,0,d_021DABA4);
            func_021D6EE0((u8 *)p,(int)func_021D87F8,0xa95);
            break;
        case 4:
            func_021D6EE0((u8 *)p,(int)func_021D88A0,0xa98);
            break;
        }
        if (*(int *)&((struct Obj03799 *)q)->f1C8!=4) {
            ((struct Obj01059 *)p)->f10=func_021B9800(98,value,(int)(q+0x54));
            func_02156DC4((int)func_021D8F3C,(int)p);
        }
    }
    ((struct Obj01059 *)p)->f14=func_021D5D94(((struct Obj01059 *)p)->f0);
    ((struct Obj01059 *)p)->f18=func_021D54F4(((struct Obj01059 *)p)->f0,39);
    func_0202208C(0,1,1,0,6,1,((struct Obj01059 *)p)->f0);
    func_0203D34C(0,((struct Obj01059 *)p)->f0);
    return 1;
}

int func_021D9158(void *a, int b, int c, char *p)
{
    void (*callback)(char *);
    int result;
    callback=*(void (**)(char *))(p+0x50);
    result=1;
    if (func_020221A4() && !((struct Obj01406 *)p)->fAE && func_0200FB24()) {
        if (((struct Obj01406 *)p)->f8) func_021D5D58(((struct Obj01406 *)p)->f8);
        func_021B9774(((struct Obj01406 *)p)->f10);
        if (((struct Obj01406 *)p)->fAD) {
            func_02012E08(((struct Obj01406 *)p)->f2C);
            ((struct Obj01406 *)p)->fAD=0;
        }
        func_021D8F58(p);
        if (((struct Obj01406 *)p)->fAB) func_0200F7C0(41);
        func_0202223C(0,0);
        func_0202223C(1,0);
        func_02157170(1,0);
        ((struct Obj22983 *)(*(char * *)&((struct Obj01406 *)p)->f20))->f1C8=7;
        return 1;
    }
    if (callback) { callback(p); result=0; }
    if (((struct Obj01406 *)p)->f1C) func_02027974(((struct Obj01406 *)p)->f1C);
    if (((struct Obj01406 *)p)->f8) func_021D5D7C(((struct Obj01406 *)p)->f8);
    func_021D5E60(((struct Obj01406 *)p)->f14);
    func_021D562C(((struct Obj01406 *)p)->f18);
    return result;
}

/*
 * evidence: unlabelled ov009 02156DE0 leaf filed and verified before caller rerun.
 */
int func_021D920C(void *a, int b, int c, char *p)
{
    if (!func_020221A4()) return 0;
    if (((struct Obj00990 *)p)->f1C) func_02027858(((struct Obj00990 *)p)->f1C);
    if (((struct Obj00990 *)p)->f38) {
        func_020307B0(((struct Obj00990 *)p)->f38);
        ((struct Obj00990 *)p)->f38=0;
    }
    func_021D5644(((struct Obj00990 *)p)->f18);
    func_021D5E8C(((struct Obj00990 *)p)->f14);
    func_021D5B70(((struct Obj00990 *)p)->f8);
    if (((struct Obj00990 *)p)->f30) func_020307B0(((struct Obj00990 *)p)->f30);
    if (((struct Obj00990 *)p)->f3C) func_020307B0(((struct Obj00990 *)p)->f3C);
    if (((struct Obj00990 *)p)->f40) func_020307B0(((struct Obj00990 *)p)->f40);
    if (((struct Obj00990 *)p)->fC) func_020307B0(((struct Obj00990 *)p)->fC);
    if (((struct Obj00990 *)p)->f44) func_020307B0(((struct Obj00990 *)p)->f44);
    if (func_0203CD98()) func_02156DE0(0,0);
    if (((struct Obj00990 *)p)->f10) {
        func_021B9838(((struct Obj00990 *)p)->f10);
        func_02156DC4(0,0);
    }
    func_020315D4(a);
    func_020306F0(98);
    func_02034A5C((int)ov114_id);
    return 1;
}


void func_021D92B8(u8 *p)
{
    if (((struct Obj10453 *)p)->f1C) {
        func_02051C6C(((struct Obj10453 *)p)->f1C);
        *(u32 *)&((struct Obj10453 *)p)->f1C = 0;
    }
}

u8 *func_021D92CC(u32 heap,u32 bank)
{
    u8 *p;
    p=func_02030734(heap,0xb4,1,d_021DABA8,0x9b);
    ((struct Obj00500 *)p)->fB0=heap;
    func_02045088(((struct Obj00500 *)p)->fB0);
    func_0201DD60();
    ((struct Obj00500 *)p)->f88=func_0203101C(((struct Obj00500 *)p)->fB0,((struct Obj00500 *)p)->fB0,2,0);
    ((struct Obj00500 *)p)->f8C=func_0201C440((void *)(u32)((struct Obj00500 *)p)->fB0);
    ((struct Obj00500 *)p)->f2C=func_020457B0(400,((struct Obj00500 *)p)->fB0);
    ((struct Obj00500 *)p)->f30=func_020457B0(400,((struct Obj00500 *)p)->fB0);
    ((struct Obj00500 *)p)->f28=func_0201D7EC(23,0,0,0,((struct Obj00500 *)p)->fB0);
    ((struct Obj00500 *)p)->f20=func_02045B38(0,2,(u16)bank,((struct Obj00500 *)p)->fB0);
    ((struct Obj00500 *)p)->f24=func_0201EC64(((struct Obj00500 *)p)->fB0);
    ((struct Obj00500 *)p)->fAC=func_02027F60(5,9,*(u32 *)&((struct Obj00500 *)p)->f28,((struct Obj00500 *)p)->f8C,((struct Obj00500 *)p)->fB0);
    ((struct Obj00500 *)p)->f0=func_0201F5DC((void *)1,12,0,((struct Obj00500 *)p)->fB0);
    ((struct Obj00500 *)p)->f8=func_0201F5DC((void *)5,12,0,((struct Obj00500 *)p)->fB0);
    ((struct Obj00500 *)p)->f4=func_0201F5DC((void *)6,12,0,((struct Obj00500 *)p)->fB0);
    func_02049B40(23,5,4,352,32,((struct Obj00500 *)p)->fB0);
    func_02049B40(23,5,0,352,32,((struct Obj00500 *)p)->fB0);
    return p;
}


void func_021D9404(char *p)
{
    func_020310C4(((struct Obj13998 *)p)->f88);
    func_0201C4E4(((struct Obj13998 *)p)->f8C);
}

void func_021D941C(u8 *p)
{
    u32 a;
    int i;
    func_0203FB44(1,(u16)(((struct Obj00534 *)p)->f0),(u16)(((struct Obj00534 *)p)->f0>>16));
    a=((struct Obj00534 *)p)->f8>>16;
    func_0203FB44(5,(u16)(((struct Obj00534 *)p)->f8),(u16)a);
    a=((struct Obj00534 *)p)->f4>>16;
    func_0203FB44(6,(u16)(((struct Obj00534 *)p)->f4),(u16)a);
    func_021D92B8(p);
    func_0201DD68();
    func_02045C04(((struct Obj00534 *)p)->f20);
    func_0201D83C(((struct Obj00534 *)p)->f28);
    func_02045808(((struct Obj00534 *)p)->f2C);
    func_02045808(((struct Obj00534 *)p)->f30);
    func_0201ED04(((struct Obj00534 *)p)->f24);
    func_02027FD8(((struct Obj00534 *)p)->fAC);
    func_0201C6EC(((struct Obj00534 *)p)->f8C);
    func_0201C4C0(((struct Obj00534 *)p)->f8C);
    if (((struct Obj00534 *)p)->f80) func_0201CE48(((struct Obj00534 *)p)->f80);
    if (((struct Obj00534 *)p)->f90) {
        func_0202F038(((struct Obj00534 *)p)->f90);
        ((struct Obj00534 *)p)->f90=0;
    }
    if (((struct Obj00534 *)p)->f40) func_020452E8(((struct Obj00534 *)p)->f40);
    if (((struct Obj00534 *)p)->f44) func_020452E8(((struct Obj00534 *)p)->f44);
    if (((struct Obj00534 *)p)->f48) func_020452E8(((struct Obj00534 *)p)->f48);
    if (((struct Obj00534 *)p)->f4C) func_020452E8(((struct Obj00534 *)p)->f4C);
    for(i=0;i<12;i++) if (*(void **)(p+i*4+0x50)) func_020452E8(*(void **)(p+i*4+0x50));
    func_02031140(((struct Obj00534 *)p)->f88);
    func_020450C8();
    func_020307B0(p);
}

void func_021D9514(char *p, int n)
{
    void *q;
    func_02045CAC(((struct Obj02477 *)p)->f20,n,((struct Obj02477 *)p)->f2C);
    if (!((struct Obj02477 *)p)->f48) ((struct Obj02477 *)p)->f48=(void *)func_020450F0(5,1,3,30,4,11,1);
    q=((struct Obj02477 *)p)->f48;
    func_02043B5C(func_02045770(q),15);
    func_0201DD78(1,2,15);
    ((struct Obj02477 *)p)->f80=func_0201CCE4(q,0,0,((struct Obj02477 *)p)->f2C,((struct Obj02477 *)p)->f28,func_02012FFC(),((struct Obj02477 *)p)->f88,2,((struct Obj02477 *)p)->fB0,15);
    func_0201F73C(q,1,(u16)(((struct Obj02477 *)p)->f8),12);
    func_02045334(q);
    func_02045374(q);
    func_02041B6C(5);
}

/*
 * extent: 58 compiled bytes followed by 2 bytes of zero alignment padding.
 */
void func_021D95B4(char *p) { if(((struct Obj04501 *)p)->f90) { func_0202F038(((struct Obj04501 *)p)->f90); ((struct Obj04501 *)p)->f90=0; } ((struct Obj04501 *)p)->f90=func_0202EE8C(((struct Obj04501 *)p)->f88,((struct Obj04501 *)p)->f48,15,16,((struct Obj04501 *)p)->fB0); }

int func_021D95F0(char *p)
{
    if (((struct Obj06470 *)p)->f80) {
        switch (func_0201CE30(((struct Obj06470 *)p)->f80)) {
        case 2:
            func_0201CE48(((struct Obj06470 *)p)->f80);
            ((struct Obj06470 *)p)->f80=0;
            break;
        case 1:
            if (func_020362DC()==1) func_0201CE38(((struct Obj06470 *)p)->f80);
            break;
        }
        return 0;
    }
    return 1;
}

void func_021D9634(char *p) { if(((struct Obj03800 *)p)->f90) { func_0202F038(((struct Obj03800 *)p)->f90); ((struct Obj03800 *)p)->f90=0; } if(((struct Obj03800 *)p)->f48) { func_0201F7A8(((struct Obj03800 *)p)->f48,2); func_020456F8(((struct Obj03800 *)p)->f48); func_02041B6C(5); func_020452E8(((struct Obj03800 *)p)->f48); ((struct Obj03800 *)p)->f48=0; } }

int func_021D9670(char *p,int mode) {
    Config c;
    int result;
    c.size=*(u16 *)(p+0xb0);
    c.flag=2;
    c.target=p+0x94;
    switch (mode) {
    case 0: c.x=32; c.y=14; c.mode=1; break;
    case 1: c.x=32; c.y=24; c.mode=1; break;
    }
    c.z=13;
    c.w=3;
    *(void **)(p+0x94)=func_020457B0(100,*(u16 *)(p+0xb0));
    func_02045CAC(*(void **)(p+0x20),4,*(void **)(p+0x94));
    *(u16 *)(p+0x98)=0x39e0;
    *(void **)(p+0xa0)=func_020457B0(100,*(u16 *)(p+0xb0));
    func_02045CAC(*(void **)(p+0x20),5,*(void **)(p+0xa0));
    *(u16 *)(p+0xa4)=0x39e0;
    result=(int)func_02027778((struct TaskMenuTmpl *)(&c),*(void **)(p+0xac));
    func_02045808(*(void **)(p+0x94));
    func_02045808(*(void **)(p+0xa0));
    func_0207D658(0x04001050,17,-8);
    return result;
}

void func_021D9730(char *p, int n)
{
    void *q;
    func_02045CAC(((struct Obj03801 *)p)->f20,n,((struct Obj03801 *)p)->f2C);
    if (!((struct Obj03801 *)p)->f4C) ((struct Obj03801 *)p)->f4C=(void *)func_020450F0(6,1,3,30,16,11,1);
    q=((struct Obj03801 *)p)->f4C;
    func_02043B5C(func_02045770(q),15);
    func_0201DD78(1,2,15);
    func_0201C7A4(func_02045770(q),0,0,((struct Obj03801 *)p)->f2C,((struct Obj03801 *)p)->f28);
    func_0201F73C(q,1,(u16)(((struct Obj03801 *)p)->f4),12);
    func_02045334(q);
    func_02045374(q);
    func_02041B6C(6);
}


void func_021D97B0(char *p)
{
    func_0201F7A8(((struct Obj13999 *)p)->f4C, 2);
    func_020456F8(((struct Obj13999 *)p)->f4C);
    func_02041B6C(6);
}

void func_021D97CC(int value, void *p)
{
    Table table;
    int copy;
    u32 checksum;
    u16 arg;
    u64 v;
    int i;
    table=d_021DA868;
    copy=value;
    checksum=func_0203F1FC((const u8 *)(&copy),4);
    arg=d_021DA864;
    v=(u64)(long long)copy+((u64)checksum<<32);
    func_0204581C(p);
    for (i=0;i<10;i++) {
        u16 index;
        index=(u16)(v&31);
        v>>=5;
        func_02045AFC(p,table.a[index]);
        func_0201D60C(p,189,4,1,&arg);
    }
}

void func_021D9844(char *p, int n, int a2)
{
    void *q;
    func_021D97CC(n,((struct Obj01737 *)p)->f2C);
    if (!((struct Obj01737 *)p)->f40) ((struct Obj01737 *)p)->f40=(void *)func_020450F0((int)1,(int)1,(u8)8,(int)30,4,11,1);
    q=((struct Obj01737 *)p)->f40;
    func_02043B5C(func_02045770(q),15);
    func_0201DD78(1,2,15);
    func_0201C7A4(func_02045770(q),0,0,((struct Obj01737 *)p)->f2C,((struct Obj01737 *)p)->f28);
    func_0201F73C(q,1,(u16)(((struct Obj01737 *)p)->f0),12);
    func_02045334(q);
    func_02045374(q);
    if (!((struct Obj01737 *)p)->f44) ((struct Obj01737 *)p)->f44=(void *)func_020450F0((int)1,(int)3,(u8)3,(int)22,2,11,1);
    q=((struct Obj01737 *)p)->f44;
    func_0201DD78(1,2,0);
    func_02045CAC(((struct Obj01737 *)p)->f20,10,((struct Obj01737 *)p)->f2C);
    func_0201C7A4(func_02045770(q),0,0,((struct Obj01737 *)p)->f2C,((struct Obj01737 *)p)->f28);
    func_02045334(q);
    func_02045374(q);
    func_02041B6C(5);
}

void func_021D9918(char *p)
{
    if (((struct Obj03273 *)p)->f40) {
        func_0201F7A8(((struct Obj03273 *)p)->f40,2);
        func_020456F8(((struct Obj03273 *)p)->f40);
        func_0201F7A8(((struct Obj03273 *)p)->f44,2);
        func_020456F8(((struct Obj03273 *)p)->f44);
        func_020452E8(((struct Obj03273 *)p)->f40);
        func_020452E8(((struct Obj03273 *)p)->f44);
        func_02041B6C(5);
        ((struct Obj03273 *)p)->f40=0;
        ((struct Obj03273 *)p)->f44=0;
    }
}

/*
 * evidence: ov123 021D9D34 callback stub filed and verified before caller rerun.
 * volatile: hardware register 04001000 is read then written at 021D9990/021D9994.
 */
char *func_021D9958(int heap)
{
    char *p;
    p=func_02030734(heap,0xb70,1,d_021DABFC,201);
    ((struct Obj05370 *)p)->f9E4=heap;
    func_02034AC4((int)ov067_id);
    func_02043534(0);
    func_020435F4(0);
    func_0204363C(1);
    *(volatile u32 *)0x04001000|=0x10000;
    func_0207D46C();
    func_0203F8F4(((struct Obj05370 *)p)->f9E4);
    func_0204A48C((const struct Cfg *)d_020A1464,(u32)d_021DABCC,((struct Obj05370 *)p)->f9E4);
    ((struct Obj05370 *)p)->f97C=func_0204B100(40,0,((struct Obj05370 *)p)->f9E4);
    func_020433E0((const struct DispVram *)d_021DABCC);
    func_0203FC28((struct DispConfig *)d_021DABBC);
    func_021D9AE8(p);
    func_021D9D3C(p);
    ((struct Obj05370 *)p)->f980=func_020056A0(func_021D9D34,p,0);
    func_020435F4(31);
    func_02043534(27);
    return p;
}

void func_021D9A14(int a0) { func_0204A600(); }

void func_021D9A1C(u8 *p)
{
    Counter i;
    func_021D9FB0((unsigned int)p);
    if (((struct Obj03802 *)p)->f8) {
        func_02030EAC(((struct Obj03802 *)p)->f8);
        ((struct Obj03802 *)p)->f8=0;
        ((struct Obj03802 *)p)->fC=0;
    }
    i=0;
    do { if (*(void **)(p+i*4+0x988)) func_0204ADA4((unsigned int)(*(void **)(p+i*4+0x988))); i++; } while(i<3);
    for(;i<6;i++) if (*(void **)(p+i*4+0x988)) func_0204A8D4((unsigned int)(*(void **)(p+i*4+0x988)));
    for(;i<9;i++) if (*(void **)(p+i*4+0x988)) func_0204AFD8((unsigned int)(*(void **)(p+i*4+0x988)));
    if (((struct Obj03802 *)p)->f984) func_02030EAC(((struct Obj03802 *)p)->f984);
    func_02030EAC(((struct Obj03802 *)p)->f980);
    func_0204B1CC(((struct Obj03802 *)p)->f97C);
    func_0204A5AC();
    func_02040DA8(1,1,0);
    func_02040DA8(6,1,0);
    func_020403F4(5);
    func_020403F4(4);
    func_02040588(5,0);
    func_0203F9B4();
    func_020307B0(p);
    func_02034A5C((int)ov_id);
}


/*
 * BG-layer init, same shape as func_021D6100 (ov120) with its own template
 * table at 0x021DA8A8 (index order 1,4,3,7,5,0,6,2) and slight per-layer
 * differences in the enable/fill sequence.
 */
void func_021D9AE8(void *a0)
{
    struct BgTemplate b[8];

    b[7] = d_021DA8A8[1];
    func_0203FCA0(0, &b[7], 0);
    func_02040588(0, 1);
    func_020409B4(0);

    b[6] = d_021DA8A8[4];
    func_0203FCA0(1, &b[6], 0);
    func_02040588(1, 1);
    func_02040C14(1, 0, 1, 0);
    func_02041300(1, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(1);

    b[5] = d_021DA8A8[3];
    func_0203FCA0(2, &b[5], 0);
    func_02040588(2, 1);
    func_02041300(2, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(2);

    b[4] = d_021DA8A8[7];
    func_0203FCA0(3, &b[4], 0);
    func_02040588(3, 1);
    func_02040C14(3, 0, 1, 0);
    func_02041300(3, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(3);

    b[3] = d_021DA8A8[5];
    func_0203FCA0(4, &b[3], 0);
    func_02040588(4, 1);
    func_020409B4(4);

    b[2] = d_021DA8A8[0];
    func_0203FCA0(5, &b[2], 0);
    func_02040588(5, 1);
    func_02040C14(5, 0, 1, 0);
    func_02041300(5, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(5);

    b[1] = d_021DA8A8[6];
    func_0203FCA0(6, &b[1], 0);
    func_02040588(6, 1);
    func_02040C14(6, 0, 1, 0);
    func_02041300(6, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(6);

    b[0] = d_021DA8A8[2];
    func_0203FCA0(7, &b[0], 0);
    func_02040588(7, 1);
    func_02040C14(7, 0, 1, 0);
    func_02041300(7, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(7);
}

/*
 * leaf: sole blocker of owned ov123 021D9958; parent ownership audit passed.
 * extent: 8-byte tailcall stub; next labelled function 021D9D3C follows.
 */
void func_021D9D34(void)
{
    func_0204A648();
}

/*
 * note 2026-10-05 (wD9r lane50): closed. func_02049658 returns a value (it ends in a call whose r0 it
 *   keeps; ov110 func_021BB328 declares it u32); declared void, it moved the constant 3 into r5 and
 *   tied the late zero arguments to j. The two palette bases are assigned inside the outer loop (mwcc
 *   hoists them after i = 0), and the source row is written inline in the 02021F64 call.
 */
void func_021D9D3C(char *p)
{
    void *record;
    u16 *base0;
    u16 *base1;
    void *h;
    int done;
    int k;
    int j;
    int i;
    u16 *cur;
    void *allocated;
    int m;
    int t;
    u16 *dst;
    u16 heap;
    h = func_020490F4(0x91, *(u16 *)(p + 0x9e4));
    j = 0;
    func_02049B68(h, 3, 4, 0, j, *(u16 *)(p + 0x9e4));
    func_02049658(h, 4, 4, 0, j, j, *(u16 *)(p + 0x9e4));
    func_020498F4(h, 6, 4, 0, j, j, *(u16 *)(p + 0x9e4));
    func_02049B68(h, 3, 0, 0, j, *(u16 *)(p + 0x9e4));
    func_02049658(h, 4, 0, 0, j, j, *(u16 *)(p + 0x9e4));
    func_020498F4(h, 5, 0, 0, j, j, *(u16 *)(p + 0x9e4));
    func_02049658(h, 4, 3, 0, j, j, *(u16 *)(p + 0x9e4));
    func_020498F4(h, 7, 3, 0, j, j, *(u16 *)(p + 0x9e4));
    heap = *(u16 *)(p + 0x9e4);
    func_02082BCC(p + 8, 0, 0x970);
    allocated = func_02049F78(h, 2, (u32)&record, heap);
    func_02082D44(*(void **)((u8 *)record + 0xc), p + 0x10, 0x1e0);
    func_02082D44(*(void **)((u8 *)record + 0xc), p + 0x1f0, 0x1e0);
    func_020307B0(allocated);
    for (i = 0; i < 15; i++) {
        base1 = (u16 *)(p + 0x1f0);
        base0 = (u16 *)(p + 0x10);
        t = i + 1;
        if (t >= 15) t -= 15;
        k = 0;
        done = 0;
        cur = (u16 *)(p + t * 32);
        while (1) {
            dst = base0 + i * 16;
            for (m = 4; m < 11; m++) {
                func_02021F64(dst + m, base1 + j * 16 + m, 1, (u8)(k >> 8), cur[m + 8]);
            }
            j++;
            if (done == 1) break;
            k += 0x600;
            if (k >= 0x1000) {
                k = 0x1000;
                done = 1;
            }
        }
    }
    func_020862F0(p + 0x1f0, 0x780);
    *(u32 *)(p + 0xc) = 1;
    *(void **)(p + 8) = func_020056A0((void *)func_021D9F40, p + 8, 0x14);
    func_0207D63C((void *)0x04000050, 1, 8, 8, 0x10);
    *(u8 *)(p + 0x974) = 0;
    func_02049238(h);
}

void func_021D9F40(void *unused, char *p)
{
    if (((struct Obj03274 *)p)->f4) {
        ((struct Obj03274 *)p)->f96B^=1;
        if (!(*(volatile u8 *)&((struct Obj03274 *)p)->f96B&1)) {
            func_0207E3D0(p+0x1f0+((struct Obj03274 *)p)->f968*32,40,14);
            func_0207E468(p+0x1f0+((struct Obj03274 *)p)->f968*32,40,14);
            ++((struct Obj03274 *)p)->f968;
            if (*(volatile s16 *)&((struct Obj03274 *)p)->f968>=60) ((struct Obj03274 *)p)->f968=0;
            func_02040618(((struct Obj03274 *)p)->f96C,2,7);
        }
    }
}

/*
 * lever: A named unsigned cursor q preserves counter r4 and cursor r5.
 */
void func_021D9FB0(unsigned int p) { int i; unsigned int q; for(i=0;i<13;i++) { q=p+(unsigned)i*4; if(((struct Obj10454 *)q)->f9B0) { func_0204B3B4(((struct Obj10454 *)q)->f9B0); ((struct Obj10454 *)q)->f9B0=0; } } }

/*
 * extent: lead with store-and-return follower 021DA030 and tailcall follower 021DA034.
 */
int func_021D9FD4(char *p, int n)
{
    switch (n) {
    case 503:
        ((struct Obj03804 *)p)->f70=0xfff1;
        func_021DA034(p,(int)func_021DA1EC,0x99);
        return 1;
    case 502:
        ((struct Obj03804 *)p)->f70=0xfff2;
        func_021DA034(p,(int)func_021DA1EC,0x9d);
        return 1;
    default:
        if (n>=400) {
            ((struct Obj03804 *)p)->f70=0xfff3;
            func_021DA034(p,(int)func_021DA1EC,0xa3);
            return 1;
        }
        return 0;
    }
}

void func_021DA030(char *p, int n, int unused)
{
    ((struct Obj22984 *)p)->f30=n;
}

void func_021DA034(char *p, int n, int unused)
{
    func_021DA030(p,n,unused);
}


void func_021DA03C(char *p)
{
    if (func_020221A4() != 0)
        func_021DA034(p, 0, 0xd5);
}

void func_021DA054(char *p) { func_0202208C(0,0,0,0x7fff,6,1,((struct Obj22985 *)p)->f0); func_02005E30(6); func_021DA034(p,(int)func_021DA03C,0xe7); }

void func_021DA090(char *p) { if(func_021D95F0(*(char * *)&((struct Obj22986 *)p)->f10) && func_020362DC()!=0) func_021DA034(p,(int)func_021DA054,0xf1); }

/*
 * lever: Unsigned result-minus-two range test emits subs/cmp/bhi.
 */
void func_021DA0B8(char *p) { if((unsigned int)(func_02012DD0(((struct Obj10455 *)p)->f20)-2)<=1) { ((struct Obj10455 *)p)->f6C=0; func_021D9514(*(char * *)&((struct Obj10455 *)p)->f10,11); func_021DA034(p,(int)func_021DA090,0xfe); } }

void func_021DA0E4(char *p) { if(func_021D95F0(*(char * *)&((struct Obj10456 *)p)->f10)) { ((struct Obj10456 *)p)->f6C=1; func_02012DAC(((struct Obj10456 *)p)->f20); func_021DA034(p,(int)func_021DA0B8,0x109); } }

void func_021DA110(char *p) { func_021D9514(*(char * *)&((struct Obj14000 *)p)->f10,6); func_021D95B4(*(char * *)&((struct Obj14000 *)p)->f10); func_021DA034(p,(int)func_021DA0E4,0x112); }

void func_021DA138(char *p) { if(func_020362DC()) { func_021D97B0(*(char * *)&((struct Obj14001 *)p)->f10); func_020092E0((struct Sub02009210Obj *)func_02009448(((struct Obj14001 *)p)->f1C),1); func_021DA034(p,(int)func_021DA110,0x11a); } }

void func_021DA16C(char *p) { if(func_020362DC()) { func_021D9844(*(char * *)&((struct Obj08116 *)p)->f10,((struct Obj08116 *)p)->f28,((struct Obj08116 *)p)->f28); func_021D9730(*(char * *)&((struct Obj08116 *)p)->f10,9); func_021DA034(p,(int)func_021DA138,0x12a); } }

void func_021DA1A0(char *p) { func_021D9844(*(char * *)&((struct Obj08117 *)p)->f10,((struct Obj08117 *)p)->f28,((struct Obj08117 *)p)->f28); func_021D9730(*(char * *)&((struct Obj08117 *)p)->f10,8); func_021DA034(p,(int)func_021DA16C,0x13c); }

void func_021DA1C8(char *p) { if(func_020362DC() & 3) func_021DA034(p,(int)func_021DA054,0x14b); }

void func_021DA1EC(char *p)
{
    unsigned n;
    n = ((struct Obj03803 *)p)->f70 + 11;
    if (((struct Obj03803 *)p)->f8) func_021B9774(((struct Obj03803 *)p)->f8);
    if (((struct Obj03803 *)p)->f70 == 0xfff1) n = 22;
    else if (((struct Obj03803 *)p)->f70 == 0xfff2) n = 23;
    else if (((struct Obj03803 *)p)->f70 == 0xfff3) n = 20;
    else if (((struct Obj03803 *)p)->f70 >= 10) n = 20;
    func_021D9730(((struct Obj03803 *)p)->f10,n);
    func_021DA034(p,(int)func_021DA1C8,0x167);
}

void func_021DA244(char *p) { if(func_021D95F0(*(char * *)&((struct Obj22987 *)p)->f10)) func_021DA034(p,(int)func_021DA3A0,0x172); }

void func_021DA268(char *p) { func_021D9514(*(char * *)&((struct Obj14002 *)p)->f10,3); func_021D95B4(*(char * *)&((struct Obj14002 *)p)->f10); func_021DA034(p,(int)func_021DA244,0x17b); }

void func_021DA290(char *p)
{
    if (func_020279E8(((struct Obj06471 *)p)->f14)) {
        if (!func_02027A04(((struct Obj06471 *)p)->f14))
            func_021DA034(p, (int)func_021DA268, 0x18d);
        else
            func_021DA034(p, (int)func_021DA054, 0x190);
        func_021D9634(((struct Obj06471 *)p)->f10);
        func_02027858(((struct Obj06471 *)p)->f14);
        *(int *)&((struct Obj06471 *)p)->f14 = 0;
    }
}

void func_021DA2DC(char *p) { if(func_021D95F0(*(char * *)&((struct Obj10457 *)p)->f10)) { ((struct Obj10457 *)p)->f14=func_021D9670(*(char * *)&((struct Obj10457 *)p)->f10,0); func_021DA034(p,(int)func_021DA290,0x1a6); } }

void func_021DA308(char *p) { func_021D9514(*(char * *)&((struct Obj22988 *)p)->f10,2); func_021DA034(p,(int)func_021DA2DC,0x1b7); }

void func_021DA328(char *p)
{
    int *q;
    if (func_0203CD98() && !func_021D9FD4(p,func_021B99DC(((struct Obj03804 *)p)->f8)) && !func_021B9790(((struct Obj03804 *)p)->f8)) {
        q = (int *)func_021B97F4(((struct Obj03804 *)p)->f8);
        func_021D9634(((struct Obj03804 *)p)->f10);
        if (*q == 2) { func_021DA034(p,(int)func_021DA1A0,0x1d4); return; }
        if (*q == 0) { func_021DA034(p,(int)func_021DA1A0,0x1d7); return; }
        ((struct Obj03804 *)p)->f70 = *q;
        func_021DA034(p,(int)func_021DA1EC,0x1db);
    }
}

/*
 *   in scratch blocker071d8-r1.log, 12 bytes. Ilias owns filing it.
 *   extern unsigned func_02031994(void *, unsigned *);
 * evidence: 0x021B973C ov114 Thumb leaf now has S23's verified EXACT
 *   pkt_ov114_021B973C shard; no caller retry because ARM9 still blocks it.
 */
void func_021DA3A0(char *p)
{
    int a;
    unsigned b;
    if (func_0203CD98()) {
        if (func_021B95D4(9,*(void **)(p + 8))) {
            b = (unsigned int)func_020071D8(*(void **)(p + 0x1c),&a);
            func_021BE79C((void *)func_021B973C(*(void **)(p + 8)),(void *)b,0x80000);
            if (!func_021B9748(*(void **)(p + 8))) {
                func_021DA034(p,(int)func_021DA328,0x1f6);
                return;
            }
        }
    } else if (func_020362DC()) {
        func_021DA034(p,(int)func_021DA328,0x1fc);
    }
}

void func_021DA408(char *p) { if(func_020221A4() && func_020362DC()) { func_021D9918(*(char * *)&((struct Obj22989 *)p)->f10); func_021DA034(p,(int)func_021DA054,0x22c); } }

void func_021DA434(char *p) { func_021D9844(*(char * *)&((struct Obj08118 *)p)->f10,((struct Obj08118 *)p)->f28,((struct Obj08118 *)p)->f28); func_021D9730(*(char * *)&((struct Obj08118 *)p)->f10,7); func_021DA034(p,(int)func_021DA408,0x23c); }

void func_021DA45C(char *p) { if(*(u8 * *)&((struct Obj08119 *)p)->f8) { func_021B9774(*(u8 * *)&((struct Obj08119 *)p)->f8); func_021B9838(*(u8 * *)&((struct Obj08119 *)p)->f8); *(u8 * *)&((struct Obj08119 *)p)->f8=0; } }

/*
 * interface: 0203159C retains the allocator result in r0; caller consumes that return.
 */
int func_021DA478(void *a,int unused,char *q)
{
    char *p;
    func_02034AC4((int)ov114_id);
    p=func_0203159C(a,0x74,((struct Obj03275 *)q)->f8);
    func_02082BCC(p,0,0x74);
    ((struct Obj02478 *)p)->f0=((struct Obj03275 *)q)->f8;
    ((struct Obj02478 *)p)->f1C=func_02012EBC(((struct Obj03275 *)q)->f0);
    ((struct Obj02478 *)p)->f20=((struct Obj03275 *)q)->f0;
    ((struct Obj02478 *)p)->f28=func_0200853C((const struct Sub0200852CObj *)func_02012944(((struct Obj03275 *)q)->f0));
    if(func_0203CD98()) {
        ((struct Obj02478 *)p)->f8=func_021B9800(((struct Obj03275 *)q)->f8,((struct Obj02478 *)p)->f28,((struct Obj03275 *)q)->f4);
        func_02156DC4((int)func_021DA45C,(int)p);
    }
    ((struct Obj02478 *)p)->fC=func_021D9958(((struct Obj02478 *)p)->f0);
    ((struct Obj02478 *)p)->f10=func_021D92CC(((struct Obj02478 *)p)->f0,87);
    func_0202208C(0,1,1,0,6,1,((struct Obj02478 *)p)->f0);
    func_02005D90(0x483,0xffff);
    switch(((struct Obj03275 *)q)->fC) {
    case 0: func_021DA034(p,(int)func_021DA308,0x276); break;
    case 1: func_021DA034(p,(int)func_021DA434,0x279); break;
    }
    ((struct Obj03275 *)q)->f10=0;
    return 1;
}

int func_021DA54C(int a,int b,char *c,char *p)
{
    void (*f)(char *);
    int r;
    f = *(void (**)(char *))(p + 0x30);
    r = 1;
    if (f) {
        if (!func_0200FB24()) f(p);
        r = 0;
    }
    if (((struct Obj03276 *)p)->f14) func_02027974(((struct Obj03276 *)p)->f14);
    func_021D9A14(((struct Obj03276 *)p)->fC);
    func_021D9404(((struct Obj03276 *)p)->f10);
    if (func_020221A4()) {
        if (func_0200FB24()) {
            func_021B9774(((struct Obj03276 *)p)->f8);
            if (((struct Obj03276 *)p)->f6C) {
                func_02012E08(((struct Obj03276 *)p)->f20);
                ((struct Obj03276 *)p)->f6C = 0;
            }
            func_0202223C(0,0);
            func_0202223C(1,0);
            r = 1;
            func_02157170(1,0);
            ((struct Obj22990 *)c)->f10 = 1;
        }
    } else if (func_0200FB24()) r = 1;
    return r;
}
