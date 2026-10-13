/*
 * file:     unit_021C6180.c
 * unit:     yes
 * function: func_021C6180, func_021C6208, func_021C6304, func_021C6354, func_021C6360, func_021C6390, func_021C63AC, func_021C63EC, func_021C6420, func_021C6438, func_021C6440, func_021C6460, func_021C6520, func_021C658C, func_021C6638, func_021C665C, func_021C6664, func_021C6698, func_021C66A8, func_021C6790, func_021C67A8, func_021C68C4, func_021C692C, func_021C6980, func_021C69C4, func_021C6A5C, func_021C6A84, func_021C6AC0, func_021C6ADC, func_021C6B38, func_021C6B50, func_021C6BCC, func_021C6C20, func_021C6C94, func_021C6CB0, func_021C6DAC, func_021C6DD8, func_021C6DF8, func_021C6E18, func_021C6E3C, func_021C6E74, func_021C6EA0, func_021C6EC0, func_021C7138, func_021C7140, func_021C72A0, func_021C72E4, func_021C734C, func_021C7460, func_021C74C4, func_021C7500, func_021C7558, func_021C7600, func_021C7674, func_021C7694, func_021C76BC, func_021C76F0, func_021C76F8, func_021C7ACC, func_021C7D48, func_021C7E0C, func_021C7E48, func_021C7E78, func_021C7F14, func_021C8100, func_021C81C8, func_021C81FC, func_021C8240, func_021C8354, func_021C8388, func_021C83B0, func_021C83DC, func_021C8470, func_021C84E8, func_021C8548, func_021C8574, func_021C85A4, func_021C860C, func_021C867C, func_021C873C, func_021C875C, func_021C8784, func_021C87A0, func_021C87B0, func_021C8850, func_021C8880, func_021C88AC, func_021C88BC, func_021C88C0, func_021C8904, func_021C899C, func_021C89C4, func_021C8A50, func_021C8A80, func_021C8B90, func_021C8C04
 * address:  0x021C6180
 * region:   ov128
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   id127 0x0000007F data
 *   id67 0x00000043 data
 *   func_02034AC4 0x02034AC4 arm
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_020056A0 0x020056A0 thumb
 *   func_021C8E2C 0x021C8E2C thumb ov128
 *   func_021C9244 0x021C9244 thumb ov128
 *   func_02030EAC 0x02030EAC arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   id43 0x00000043 data
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_021CA458 0x021CA458 thumb ov128
 *   func_020457B0 0x020457B0 arm
 *   func_020355C4 0x020355C4 arm
 *   func_02012FFC 0x02012FFC thumb
 *   func_020355D8 0x020355D8 arm
 *   func_02045808 0x02045808 arm
 *   func_02045838 0x02045838 arm
 *   func_0201283C 0x0201283C thumb
 *   func_02009860 0x02009860 thumb
 *   DWC_CreateFriendKey 0x0205994C arm
 *   func_02009A1C 0x02009A1C thumb
 *   func_021CA014 0x021CA014 thumb ov128
 *   func_02059354 0x02059354 arm
 *   func_0200F43C 0x0200F43C thumb
 *   func_020099C8 0x020099C8 thumb
 *   DWC_CreateFriendKeyToken 0x02059980 arm
 *   func_02009A00 0x02009A00 thumb
 *   func_02009918 0x02009918 thumb
 *   func_02009864 0x02009864 thumb
 *   func_02043534 0x02043534 arm
 *   func_020435F4 0x020435F4 arm
 *   func_0207D534 0x0207D534 arm
 *   func_0204363C 0x0204363C arm
 *   func_020490F4 0x020490F4 arm
 *   func_021CA0BC 0x021CA0BC thumb ov128
 *   func_0203D34C 0x0203D34C arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021CA478 0x021CA478 thumb ov128
 *   func_020310C4 0x020310C4 arm
 *   func_0204A600 0x0204A600 arm
 *   func_0204A648 0x0204A648 arm
 *   func_021CA10C 0x021CA10C thumb ov128
 *   func_02049238 0x02049238 arm
 *   func_020433E0  0x020433E0  arm
 *   d_021CA5CC     0x021CA5CC  data
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02040B94 0x02040B94 arm
 *   func_0204152C 0x0204152C arm
 *   func_02040588 0x02040588 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   d_021CA664 0x021CA664 data a4
 *   d_021CA718 0x021CA718 data a4
 *   func_020403F4  0x020403F4  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   func_0204B034 0x0204B034 arm
 *   func_0204B258 0x0204B258 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_020275E4 0x020275E4 thumb
 *   func_02027618 0x02027618 thumb
 *   func_02027614 0x02027614 thumb
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 *   d_020A1448 0x020A1448 data a4
 *   d_021CA7D0 0x021CA7D0 data a4
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204B084 0x0204B084 arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_0201DD68 0x0201DD68 thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0203101C 0x0203101C arm
 *   func_0201C440 0x0201C440 thumb
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02031140 0x02031140 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02049B40 0x02049B40 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_02045088 0x02045088 arm
 *   func_020452E8 0x020452E8 arm
 *   func_020450C8 0x020450C8 arm
 *   func_02049EF4 0x02049EF4 arm
 *   d_021CA4F5 0x021CA4F5 data a1
 *   func_020307B0  0x020307B0  arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F250 0x0201F250 thumb
 *   func_021B6AE4 0x021B6AE4 thumb ov067
 *   func_021CA4B4 0x021CA4B4 thumb ov128
 *   func_020456F8  0x020456F8  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   _ll_udiv 0x0209C00C arm
 *   _ull_mod 0x0209C018 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0200846C 0x0200846C thumb
 *   func_020099D4 0x020099D4 thumb
 *   func_02045924 0x02045924 arm
 *   func_020084E4 0x020084E4 thumb
 *   func_0201F02C 0x0201F02C thumb
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   d_021CA800 0x021CA800 data a2
 *   d_021CA810 0x021CA810 data a2
 *   d_021CA818 0x021CA818 data a2
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B9A0 0x0204B9A0 arm
 *   func_02027778 0x02027778 thumb
 *   func_02027974 0x02027974 thumb
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_02027858 0x02027858 thumb
 *   func_021CA3A0 0x021CA3A0 thumb ov128
 *   func_021CA3C4 0x021CA3C4 thumb ov128
 *   func_021CA1E0 0x021CA1E0 thumb ov128
 *   func_021CA084 0x021CA084 thumb ov128
 *   func_021CA19C 0x021CA19C thumb ov128
 *   func_0202208C 0x0202208C thumb
 *   func_020221A4 0x020221A4 thumb
 *   BLINK_PALANM_Update 0x0202EA40 thumb
 *   func_0204B98C 0x0204B98C arm
 *   d_021CA4F9 0x021CA4F9 data a1
 *   func_02012944 0x02012944 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_02027F60 0x02027F60 thumb
 *   func_021CA444 0x021CA444 thumb ov128
 *   func_02027FD8 0x02027FD8 thumb
 *   func_02041090 0x02041090 arm
 *   func_02040618 0x02040618 arm
 *   func_021CA16C 0x021CA16C thumb ov128
 *   func_020362DC 0x020362DC arm
 *   func_0203633C 0x0203633C arm
 *   func_020061E4 0x020061E4 thumb
 *   BLINK_PALANM_ResetPhase 0x0202EB04 thumb
 *   func_021CA154 0x021CA154 thumb ov128
 *   func_021CA184 0x021CA184 thumb ov128
 *   d_021CA58A 0x021CA58A data a1
 *   func_02035C08 0x02035C08 arm
 *   d_021CA51C 0x021CA51C data a4
 *   func_02041300 0x02041300 arm
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045374 0x02045374 arm
 *   func_021CA3E8 0x021CA3E8 thumb ov128
 *   func_02035C60 0x02035C60 arm
 *   func_0203630C 0x0203630C arm
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_021CA40C 0x021CA40C thumb ov128
 *   func_021CA320 0x021CA320 thumb ov128
 *   func_02009A74 0x02009A74 thumb
 *   func_021C3EE0 0x021C3EE0 thumb ov127
 *   func_021C4044 0x021C4044 thumb ov127
 *   d_021CA564 0x021CA564 data a4
 *   d_021CA688 0x021CA688 data a4
 *   d_021CA650 0x021CA650 data a4
 *   d_021CA638 0x021CA638 data a4
 *   func_021C4080 0x021C4080 thumb ov127
 *   func_021C3F80 0x021C3F80 thumb ov127
 *   func_021CA2C4 0x021CA2C4 thumb ov128
 *   func_021CA294 0x021CA294 thumb ov128
 *   d_021CA5FC 0x021CA5FC data a1
 *   func_0204B09C 0x0204B09C arm
 *   func_02041EE4 0x02041EE4 arm
 *   d_021CA7C0 0x021CA7C0 data a4
 *   cb_021CA7C0 0x021CA7C0 data a4
 *   func_0201C6B4 0x0201C6B4 thumb
 *   DWC_GetFriendKey 0x020598C4 arm
 *   d_021CA68C 0x021CA68C data a4
 *   func_021CA2DC 0x021CA2DC thumb ov128
 *   func_021CA42C 0x021CA42C thumb ov128
 *   func_0204B404 0x0204B404 arm
 *   d_021CA6C8 0x021CA6C8 data a2
 *   CLACT_GetActorAnimFrame 0x0204B8F4 arm
 *   func_021C41BC 0x021C41BC thumb ov127
 *   func_021C40BC 0x021C40BC thumb ov127
 *   func_021C42A8 0x021C42A8 thumb ov127
 *   PROCSYS_Create 0x02031324 arm
 *   PROCSYS_Main 0x02031330 arm
 *   func_0203133C 0x0203133C arm
 *   PROCSYS_Push 0x02031348 arm
 *   func_021C8DA0 0x021C8DA0 thumb ov128
 *   func_0216C0C0 0x0216C0C0 thumb ov010
 *   id194 0x000000C2 data
 *   id129 0x00000081 data
 *   d_021F5580 0x021F5580 data ov194 a4
 *   d_021DA62C 0x021DA62C data ov129 a4
 *   CODEIN_PARAM_Create  0x0202E4EC  thumb  arm9
 */
#include "../../matched/include/Obj06476.h"
#include "../../matched/include/Obj03279.h"
#include "../../matched/include/Obj23062.h"
#include "../../matched/include/Obj23063.h"
#include "../../matched/include/Obj10480.h"
#include "../../matched/include/Obj08125.h"
#include "../../matched/include/Obj04503.h"
#include "../../matched/include/Obj10482.h"
#include "../../matched/include/Obj00227.h"
#include "../../matched/include/Obj00298.h"
#include "../../matched/include/Obj23065.h"
#include "../../matched/include/Obj03808.h"
#include "../../matched/include/Obj03812.h"
#include "../../matched/include/Obj06477.h"
#include "../../matched/include/Obj00725.h"
#include "../../matched/include/Obj04504.h"
#include "../../matched/include/Obj01936.h"
#include "../../matched/include/Obj05377.h"
#include "../../matched/include/Obj08126.h"
#include "../../matched/include/Obj23068.h"
#include "../../matched/include/Obj00329.h"
#include "../../matched/include/Obj05378.h"
#include "../../matched/include/Obj14046.h"
#include "../../matched/include/Obj10485.h"
#include "../../matched/include/Obj10483.h"
#include "../../matched/include/Obj23069.h"
#include "../../matched/include/Obj02481.h"
#include "../../matched/include/Obj14034.h"
#include "../../matched/include/Obj02482.h"
#include "../../matched/include/Obj02841.h"
#include "../../matched/include/Obj04505.h"
#include "../../matched/include/Obj14035.h"
#include "../../matched/include/Obj23075.h"
#include "../../matched/include/Obj03280.h"
#include "../../matched/include/Obj05379.h"
#include "../../matched/include/Obj23077.h"
#include "../../matched/include/Obj14037.h"
#include "../../matched/include/Obj23079.h"
#include "../../matched/include/Obj00179.h"
#include "../../matched/include/Obj03809.h"
#include "../../matched/include/Obj03281.h"
#include "../../matched/include/Obj23080.h"
#include "../../matched/include/Obj03810.h"
#include "../../matched/include/Obj10484.h"
#include "../../matched/include/Obj23081.h"
#include "../../matched/include/Obj23082.h"
#include "../../matched/include/Obj08130.h"
#include "../../matched/include/Obj06478.h"
#include "../../matched/include/Obj23084.h"
#include "../../matched/include/Obj14039.h"
#include "../../matched/include/Obj03811.h"
#include "../../matched/include/Obj23087.h"
#include "../../matched/include/Obj23088.h"
#include "../../matched/include/Obj14040.h"
#include "../../matched/include/Obj23089.h"
#include "../../matched/include/Obj05381.h"
#include "../../matched/include/Obj23090.h"
#include "../../matched/include/Obj23091.h"
#include "../../matched/include/Obj03282.h"
#include "../../matched/include/Obj05380.h"
#include "../../matched/include/Obj05381.h"
#include "../../matched/include/Obj05382.h"
#include "../../matched/include/Obj05382.h"
#include "../../matched/include/Obj14043.h"
#include "../../matched/include/Obj23097.h"
#include "../../matched/include/Obj23098.h"
#include "../../matched/include/Obj23099.h"
#include "../../matched/include/Obj23100.h"
#include "../../matched/include/Obj23101.h"

struct Obj0203159C;
struct Node;
struct S020315D4;
struct Descriptor;
struct CharBuf;
struct U16Vec;
struct BigObj;
struct Sub020097BCObj;
struct DWCstAccUserData;
struct Sub020097BCFriend;
struct PrintSys;
struct Tcbl;
struct DispVram;
struct BgTemplate;
struct DispConfig;
struct Cfg;
struct Bank;
struct Obj;
struct GfFont;
struct MsgBank;
struct WordSet;
struct Rec;
struct Rec3;
struct S02031140;
struct Sub020097BCEnt;
struct Strbuf;
struct Actor;
struct TaskMenu;
struct TaskMenuTmpl;
struct P;
struct Row;
struct R;
struct StrObj;
struct TaskMenuState;
struct CodeIn;
struct Vec2;
struct obj;
struct Obj0202E54C;
struct Param;
struct S020314B8;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

typedef signed int     s32;

typedef unsigned long long u64;

typedef struct {u32 a,b,c,d;} DispConfig;

typedef struct {u32 a,b;u8 c,d,e,f;u32 g;u16 h[6];} Config_021C6180;

typedef struct {s16 x,y,z;u8 a,b;} Point_021C6180;

typedef struct {int heap;u8 count;u8 pad[3];void *entries;int mode;u8 x,y,a,b;} TextConfig_021C6180;

struct P {
    u8 pad00[44];
    void *buf;
    void *text1;
    u16 color1;
    u16 pad36;
    u32 flag1;
    void *text2;
    u16 color2;
    u16 pad42;
    u32 flag2;
    void *menu;
};

typedef signed char s8;

typedef struct { u16 a, b, c, d; } Rect;

typedef struct { s16 x, y, z; } V3;

typedef struct { u32 a, b; } W2;

typedef struct { s16 x, y; } Pair;

typedef void (*Callback)(u8 *, u8 *, int, int);

typedef struct { Callback cb[4]; Pair pos; } Config_021C76F8;

typedef struct TextConfig_021C76F8 {int heap; u8 count; u8 pad[3]; void *entries; int mode; u8 x,y,a,b;} TextConfig_021C76F8;

typedef struct Point_021C76F8 {s16 x,y;} Point_021C76F8;

typedef struct Entry_021C6180 {s16 x,y; s16 rest[3];} Entry_021C6180;

typedef struct { s16 x, y, rest[3]; } Entry_021C8850;

typedef struct {s16 x,y,z;u8 a,b;} Point;

extern int func_02034AC4(s32 handle);
extern void func_0203064C(u32,u32,u32);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,int,int);
extern void *func_020056A0(void *,void *,int);
extern int func_021C8E2C(void *p, u8 *q, u8 *r, int heap);
extern int func_021C9244(u8 *p, u8 *q, u8 *r, u16 heap);
extern void func_02030EAC(struct Node *n);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(u32 heap);
extern void func_02034A5C(s32 handle);
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_021CA458(char *p, void *q);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u8 func_020355C4(void);
extern signed char func_02012FFC(void);
extern void func_020355D8(int);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045838(struct U16Vec *dst, struct U16Vec *src);
extern u32 func_0201283C(const struct BigObj *p);
extern struct Sub020097BCObj *func_02009860(struct Sub020097BCObj *obj);
extern unsigned long long DWC_CreateFriendKey(struct DWCstAccUserData *userdata);
extern int func_02009A1C(struct Sub020097BCObj *obj, u32 i);
extern u64 func_021CA014(void *,int *);
extern int func_02059354(void *,u32,u32);
extern int func_0200F43C(void *,u32,u32,int *);
extern struct Sub020097BCFriend *func_020099C8(struct Sub020097BCObj *obj, int i);
extern void DWC_CreateFriendKeyToken(void *,u32,u32);
extern void func_02009A00(struct Sub020097BCObj *obj, int i, void *dest);
extern void func_02009918(struct Sub020097BCObj *obj, u32 i, u32 field, u32 value);
extern int func_02009864(const struct Sub020097BCObj *obj, int i, int field);
extern void func_02043534(u32 planes);
extern void func_020435F4(u32 planes);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern void func_0204363C(u32 swap);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_021CA0BC(void *,int);
extern void func_0203D34C(u32 a, u32 b);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_021CA478(char *p);
extern void func_020310C4(struct Tcbl *p);
extern void func_0204A600(void);
extern void func_0204A648(void);
extern void func_021CA10C(u8 *);
extern void func_02049238(void *);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203F8F4(u32);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040B94(u8,u32,u32,u32);
extern void func_0204152C(int channel, u16 val);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02049B68(void *,u32,u32,u32,u32,u32);
extern void func_02049658(void *,u32,u32,u32,u32,u32,u32);
extern void func_020498F4(void *,u32,u32,u32,u32,u32,u32);
extern void func_020403F4(u32 i);
extern void func_0203F9B4(void);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern struct Obj *func_0204B034(u8 *a0, u32 a1, u32 heap);
extern void func_0204B258(struct Bank *bank, void *p);
extern int func_0204A6C8(void *,u32,u32,u32,u32);
extern int func_0204ABF0(void *,u32,u32,u32,u32);
extern int func_0204AF28(void *,u32,u32,u32);
extern u32 func_020275E4(void);
extern u32 func_02027618(void);
extern u32 func_02027614(void);
extern u32 func_0202761C(u32);
extern u32 func_02027620(u32);
extern void func_0204A8D4(u32);
extern void func_0204ADA4(u32);
extern void func_0204AFD8(u32);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204B084(u32);
extern void func_0204A5AC(void);
extern void func_0201DD68(void);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern void *func_0203101C(unsigned,unsigned,unsigned,unsigned);
extern u32 func_0201C440(void *p);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_0201CE48(struct Rec3 *p);
extern void func_02031140(struct S02031140 *p);
extern u32 func_0201D83C(void *ptr);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern void func_02045088(u16 heapId);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_020450C8(void);
extern void *func_02049EF4(void *, u32, u32, void **, u16);
extern u32 func_020307B0(void *p);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021B6AE4(u8 *p, void *a, u16 b, u16 c, u32 s0, u32 s1, u16 s2, u32 s3);
extern void func_021CA4B4(char *p);
extern void func_020456F8(struct Descriptor *d);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void *func_0200846C(int);
extern struct Sub020097BCEnt *func_020099D4(struct Sub020097BCObj *obj, int i);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void func_020084E4(u16 *out, struct U16Vec *vec);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void *func_0204B294(u32,u32,u32,u32,const void *,u16,u16);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B9A0(struct Actor *a);
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
extern void func_02027974(void *);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *);
extern void func_02027858(struct TaskMenu *m);
extern void func_021CA3A0(char *);
extern void func_021CA3C4(char *);
extern int func_021CA1E0(char *p);
extern int func_021CA084(int *p);
extern void func_021CA19C(unsigned *p);
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern u32 func_020221A4(void);
extern s32 BLINK_PALANM_Update(struct Row *p);
extern u32 func_0204B98C(struct Actor *a);
extern u8 *func_02012944(void *p);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void func_021CA444(char *);
extern unsigned int func_02027FD8(struct TaskMenuState *s);
extern void func_02041090(unsigned int index, unsigned int a1, unsigned int a2, unsigned int a3, u8 a4, u8 a5);
extern void func_02040618(unsigned,unsigned,unsigned);
extern void func_021CA16C(u8 *,int);
extern u32 func_020362DC(void);
extern u32 func_0203633C(void);
extern void func_020061E4(u32 a);
extern void BLINK_PALANM_ResetPhase(struct CodeIn *p);
extern void func_021CA154(u8 *, int);
extern void func_021CA184(u8 *, int, int);
extern int func_02035C08(const void *p);
extern void func_02041300(unsigned,int,u8,u8,u8,u8,u8);
extern void *func_0201CCE4(void *,int,int,void *,void *,void *,void *,int,u16,u16);
extern void func_0201F73C(void *,int,int,int);
extern void func_02045374(struct Cfg *cfg);
extern void func_021CA3E8(int);
extern u32 func_0201CE30(void *p);
extern void func_0201CE5C(struct Rec *p, s32 v);
extern void func_0201CE38(void *);
extern int func_02035C60(void);
extern unsigned int func_0203630C(void);
extern void func_0201F7A8(void *,u32);
extern void func_021CA40C(char *p, int n);
extern void func_02009A74(struct Sub020097BCObj *obj, u32 i);
extern void *func_021C3EE0(void *, void *, u32, u32);
extern void func_021C4044(u8 *, int, int, int, int);
extern void func_021C4080(u8 *p);
extern void func_021C3F80(u8 *);
extern void func_021CA2C4(u8 *,int,int);
extern void func_021CA294(u8 *p, int a);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_0204B09C(void *, int, Pair *);
extern void func_02041EE4(u32 index, u32 a, u32 b);
extern unsigned long long DWC_GetFriendKey(void *);
extern void func_021CA2DC(char *p);
extern void func_021CA42C(char *);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern u32 CLACT_GetActorAnimFrame(struct Obj *);
extern void func_021C41BC(u8 *p);
extern void *func_021C40BC(void *, s16 *, int, u32);
extern void func_021C42A8(struct obj *p, int idx, int a);
extern void *PROCSYS_Create(int);
extern u32 PROCSYS_Main(void *);
extern void func_0203133C(struct S020314B8 *p);
extern void PROCSYS_Push(void *, u32, void *, void *);
extern char *func_021C8DA0(void *unused, char *q, int mode, int heap);
extern struct Param *CODEIN_PARAM_Create(u32 heap, u32 a1, u32 a2, u32 a3, u32 *src);
extern void func_0202E54C(struct Obj0202E54C *p);
extern int func_0216C0C0(int a0);
int func_021C6180(void *p,int unused,void *q);
int func_021C6208(int result,int *stage,int unused,char *p);
int func_021C6304(void *p,int a,int b,char *q);
void func_021C6354(void *p,char *q);
void func_021C6360(char *p,u16 heap);
void func_021C6390(u8 *p);
void func_021C63AC(void *p,u32 *out,u32 a,u32 b,u8 c,u8 d,u8 e,u8 f,u32 unused,u8 g);
void func_021C63EC(u8 *p, const u32 *q, int heap);
void func_021C6420(u8 *p, void *a1);
void func_021C6438(u8 *p, u8 a, u8 b);
void func_021C6440(u8 *p,void *a,void *b);
int func_021C6460(char *p,void *q,u32 arg);
void func_021C6514(char *p,int x);
void func_021C651C(char *p,int x);
void func_021C6520(char *p);
void func_021C658C(char *p,void *q,u16 heap);
void func_021C6638(u8 *p);
void func_021C665C(void *p);
void func_021C6664(u8 *p);
void func_021C6698(void *a0);
void func_021C66A8(char *p,int heap);
void func_021C6790(u8 *a0);
void func_021C67A8(char *p,int heap);
void func_021C68C4(char *p);
void func_021C692C(u8 *p, int heap);
void func_021C6980(u8 *p);
void func_021C69C4(u8 *p,const u8 *q,u16 heap);
void func_021C6A5C(u8 *p);
void func_021C6A84(u8 *p,u16 heap);
void func_021C6AC0(u8 *p);
void func_021C6ADC(u8 *p,u8 *q,unsigned v);
void func_021C6B38(u8 *p);
void func_021C6B50(void **p,u64 value);
void func_021C6BCC(u8 *p,u8 *q,int idx,unsigned heap);
int func_021C6C20(u8 *p,u8 *q,int idx);
void func_021C6C94(char **p, int a);
void func_021C6CB0(char *p,u16 heap);
void func_021C6DAC(u8 *p);
void func_021C6DD8(u8 *p,u32 a);
void func_021C6DF8(u8 *p,u32 a);
void func_021C6E18(u8 *p,int i,u16 a);
void *func_021C6E3C(void *p,void **q,int a,int heap);
int func_021C6E74(u8 *p);
void func_021C6EA0(u8 *p,u8 *q,u8 *r,u16 heap);
int func_021C6EC0(u8 *p, u8 *q, u8 *ctx, int heap);
void func_021C7138(u8 *p,u8 *q,u8 *ctx);
void func_021C7140(struct P *p, u8 *a, u8 *ctx, u16 heap);
void func_021C72A0(u8 *p, u8 *unused, u8 *q);
void func_021C72E4(u8 *p,int *q,u8 *ctx);
int func_021C734C(u32 *p, int *q, u8 *ctx);
int func_021C7460(int *p,int *q,u8 *ctx);
int func_021C74C4(int *p,int *q,u8 *r);
void func_021C74E8(u32 *p,u8 *q);
void func_021C7500(u8 *p,u8 *q);
void func_021C7558(u8 *p,u8 *ctx,unsigned v,unsigned heap);
int func_021C7600(void *p, int *q);
int func_021C7674(void *p,int *q,u8 *r);
void func_021C7694(u8 *p, void *ctx);
int func_021C76BC(int *p,u8 *q);
void func_021C76F0(u8 *p,u8 *q,u8 *ctx,u16 value);
int func_021C76F8(u8 *p,u8 *q,u8 *ctx,u16 heap);
void func_021C7AC4(u8 *p,u8 *q,u8 *ctx);
void func_021C7ACC(u8 *p, void *unused, u8 *ctx, u16 heap);
void func_021C7D48(u8 *p, void *unused, u8 *a);
void func_021C7E0C(u8 *p,u8 *q,u8 *r,u16 heap);
void func_021C7E48(u8 *p,void *q,u8 *r);
int func_021C7E78(s16 *p, u8 *a, void *b, int n);
int func_021C7F14(s16 *p, u8 *a, u8 *ctx);
int func_021C8100(s16 *p, void *a, void *b, int *changed);
int func_021C81C8(s16 *p,u8 *q,u8 *r);
void func_021C81FC(u8 *p, void *a, u8 *b, u16 c);
int func_021C8240(u8 *p, u8 *a, u8 *b, u16 h);
int func_021C8354(u8 *p,u8 *q);
unsigned long long func_021C8388(s16 *p,u8 *q);
void func_021C83B0(s16 *p,u8 *q,u8 *r,u16 heap);
void func_021C83DC(u8 *p, u8 *a, void *unused, int heap);
int func_021C8470(u8 *p, int *a, void *b);
int func_021C84E8(u8 *p, u8 *a, u8 *b, int c);
void func_021C8548(s16 *p,u8 *q,u8 *r,u16 heap);
int func_021C8574(u8 *p,int *q,u8 *r,int heap);
void func_021C85A4(u8 *p, u8 *a, u8 *b, int x, int y, int n, u16 c);
void func_021C860C(u8 *p, u8 *a, u8 *b, int x, int y, u16 c);
void func_021C8660(void);
void func_021C8664(void);
void func_021C8668(u8 *p, u8 *a, int n);
void func_021C867C(u8 *p, u8 *a, int n, int heap);
int func_021C873C(void *p,int *state,u8 *q);
void func_021C875C(char *p,char *q);
void func_021C8784(char *p);
int func_021C87A0(s16 *p);
void func_021C87B0(u8 *p, u8 *a1);
int func_021C8850(u8 *p, u8 *a1);
void func_021C8880(u8 *p, u8 *unused);
void func_021C88AC(u16 *d, u16 *unused, u16 *s, u32 unused2, u16 heap);
void func_021C88BC(void *a0, void *a1);
void func_021C88C0(s16 *p, void *unused, u8 *q);
void func_021C8904(char *p,char *q,void *r,void *s,int t,char *table,int page,u16 heap);
void func_021C899C(char *p,char *q,void *r,void *s,int t,char *table,int page,u16 heap);
void func_021C89C4(char *p, void *q, void *a2);
void func_021C8A50(char *p,int unused);
void func_021C8A80(u8 *p, void *a, u8 *b, int unused, int i, void *base, int idx, u16 heap);
void func_021C8B90(char *p,char *q,int unused,int i,u16 h);
int func_021C8C04(void **p, u8 *a, u8 *b, void *unused, u16 heap);
extern char id127[];
extern char id67[];
extern char id43[];
extern char d_021CA5CC[];
extern const DispConfig d_021CA664;
extern const u8 d_021CA718[][32];
extern const Config_021C6180 d_020A1448;
extern u8 d_021CA7D0[];
extern const u8 d_021CA4F5[];
extern const Point_021C6180 d_021CA800[];
extern const Point_021C6180 d_021CA810;
extern const Point_021C6180 d_021CA818;
extern const u8 d_021CA4F9[];
extern const char d_021CA58A[];
extern const u8 d_021CA51C[];
extern const V3 d_021CA564[];
extern const W2 d_021CA688[];
extern const Rect d_021CA650;
extern const Rect d_021CA638;
extern const unsigned char d_021CA5FC[];
extern Config_021C76F8 d_021CA7C0;
extern Callback cb_021CA7C0[];
extern const int d_021CA68C[][8];
extern const Entry_021C6180 d_021CA6C8[];
extern char id194[];
extern char id129[];
extern char d_021F5580[];
extern char d_021DA62C[];






int func_021C6180(void *p,int unused,void *q)
{
    char *v;
    func_02034AC4((u32)id127); func_02034AC4((u32)id67);
    func_0203064C(1,52,0xc0000);
    v=func_0203159C(p,0x5b0,52);
    func_02082BCC(v,0,0x5b0);
    ((struct Obj06476 *)v)->f1F8=q; ((struct Obj06476 *)v)->f5A8=0;
    func_021C63EC((u8 *)(v+0x190),((struct Obj06476 *)v)->f1F8,52);
    func_021C658C(v+4,v+0x190,52);
    if(((struct Obj06476 *)v)->f5A8==0) ((struct Obj06476 *)v)->f5A8=func_020056A0(func_021C6354,v,16);
    return 1;
}






int func_021C6208(int result,int *stage,int unused,char *p)
{
    switch(*stage) {
    case 0:
        switch(((struct Obj03279 *)p)->f0) {
        case 0: result=func_021C6EC0((u8 *)(p+0x1fc),(u8 *)(p+0x190),(u8 *)(p+4),52); break;
        case 1: result=func_021C76F8((u8 *)(p+0x24c),(u8 *)(p+0x190),(u8 *)(p+4),52); break;
        case 2: result=func_021C8C04((void **)(p+0x3f8),(u8 *)p,(u8 *)(p+0x190),p+4,52); break;
        case 3: result=func_021C8E2C(p+0x404,(u8 *)(p+0x190),(u8 *)(p+4),52); break;
        case 4: result=func_021C9244((u8 *)(p+0x420),(u8 *)(p+0x190),(u8 *)(p+4),52); break;
        case 5: ((struct Obj23062 *)(*(char * *)&((struct Obj03279 *)p)->f1F8))->f4=0; return 1;
        case 6: ((struct Obj23063 *)(*(char * *)&((struct Obj03279 *)p)->f1F8))->f4=1; return 1;
        }
        if(result==1) {
            *(int *)&((struct Obj03279 *)p)->f0=((struct Obj03279 *)p)->f199;
            ((struct Obj03279 *)p)->f198=((struct Obj03279 *)p)->f19A;
            ((struct Obj03279 *)p)->f5AC=4;
            *stage=1;
        }
        break;
    case 1:
        if(--((struct Obj03279 *)p)->f5AC<=0) *stage=0;
        break;
    }
    func_021C6638((u8 *)(p+4));
    return 0;
}






int func_021C6304(void *p,int a,int b,char *q)
{
    func_02030EAC(((struct Obj10480 *)q)->f5A8); ((struct Obj10480 *)q)->f5A8=0;
    func_021C6664((u8 *)(q+4));
    func_021C6420((u8 *)(q+0x190),((struct Obj10480 *)q)->f1F8);
    func_020315D4(p); func_020306F0(52);
    func_02034A5C((u32)id43); func_02034A5C((u32)id127);
    return 1;
}






void func_021C6354(void *p,char *q) { func_021C665C(q+4); }






void func_021C6360(char *p,u16 heap) {func_021C658C(p+4,p+0x190,heap); if(!((struct Obj08125 *)p)->f5A8) ((struct Obj08125 *)p)->f5A8=func_020056A0(func_021C6354,p,16);}







/*
 * Addresses are Black-image addresses.
 */
void func_021C6390(u8 *p)
{
    func_02030EAC(((struct Obj08125 *)p)->f5A8);
    *(u32 *)&((struct Obj08125 *)p)->f5A8 = 0;
    func_021C6664(p + 4);
}






void func_021C63AC(void *p,u32 *out,u32 a,u32 b,u8 c,u8 d,u8 e,u8 f,u32 unused,u8 g)
{
    *out=func_020450F0(a,b,c,d,e,f,1);
    func_02043B5C(func_02045770((struct Descriptor *)*out),g);
    func_02045334((struct Descriptor *)*out);
    func_021CA458(p,out);
}






void func_021C63EC(u8 *p, const u32 *q, int heap) {((struct Obj04503 *)p)->f4=*q;((struct Obj04503 *)p)->f58=func_020457B0(128,heap);((struct Obj04503 *)p)->f5C=func_020457B0(128,heap);((struct Obj04503 *)p)->f0=func_020355C4();p[12]=func_02012FFC();p[13]=0;p[14]=1;}






void func_021C6420(u8 *p, void *a1) { func_020355D8(((struct Obj10482 *)p)->f0); func_02045808(((struct Obj10482 *)p)->f58); func_02045808(((struct Obj10482 *)p)->f5C); }






/*
 * extent: Six code bytes followed by two zero alignment bytes.
 */
void func_021C6438(u8 *p, u8 a, u8 b)
{
    p[9] = a;
    p[10] = b;
}






void func_021C6440(u8 *p,void *a,void *b) { if(a) func_02045838(((struct Obj00227 *)p)->f58,a); if(b) func_02045838(((struct Obj00227 *)p)->f5C,b); }






int func_021C6460(char *p,void *q,u32 arg)
{
    int i;
    void *v;
    u64 old,id;
    int valid,result;
    v=(void *)func_0201283C(((struct Obj23065 *)p)->f4);
    old=DWC_CreateFriendKey((struct DWCstAccUserData *)func_02009860(v));
    for(i=0;i<32;i++) {
        if(func_02009A1C(v,i)==0) {
            id=func_021CA014(q,&valid);
            if(valid==1 && id!=old) {
            if(func_02059354(func_02009860(v),(u32)id,(u32)(id>>32))==0) return 1;
            if(func_0200F43C(v,(u32)id,(u32)(id>>32),&result)==0) return 2;
            DWC_CreateFriendKeyToken(func_020099C8(v,i),(u32)id,(u32)(id>>32));
            func_02009A00(v,i,(void *)arg);
            func_02009918(v,i,9,2);
            return 0;
            }
            return 1;
        }
    }
    return 0;
}






void func_021C6514(char *p,int x) { ((struct Obj00298 *)p)->f60=x; ((struct Obj00298 *)p)->f64=1; }






void func_021C651C(char *p,int x) { p[11]=x; }






/*
 * lever: direct assignment from postincrement preserves the old count load;
 *   the two-byte tail at 021C658A is zero padding.
 */
void func_021C6520(char *p)
{
    int i;
    void *v;
    func_02082BCC(p+16,0,72);
    v=(void *)func_0201283C(((struct Obj03808 *)p)->f4);
    ((struct Obj03808 *)p)->f10=0;
    for(i=0;i<32;i++) {
        if(func_02009A1C(v,i)==1) {
            *(u8 *)(p+((struct Obj03808 *)p)->f10+24)=i;
            if(func_02009864(v,i,9)==2) *(u8 *)(p+((struct Obj03808 *)p)->f10+56)=255;
            else *(u8 *)(p+((struct Obj03808 *)p)->f10+56)=(((struct Obj03808 *)p)->f14)++;
            ((struct Obj03808 *)p)->f10=((struct Obj03808 *)p)->f10+1;
        }
    }
}






/*
 * calls: 021C6698 receives live r0=0x180 although its own body ignores it;
 *   021CA0BC heap is widened because this caller has no truncation.
 * volatile: hardware register stores at 021C65A6 and 021C65A8
 */
void func_021C658C(char *p,void *q,u16 heap)
{
    func_02043534(0); func_020435F4(0);
    *(volatile u16 *)0x04000050=0; *(volatile u16 *)0x04001050=0;
    func_0207D534((void *)0x0400006c,-16); func_0207D534((void *)0x0400106c,-16);
    func_0204363C(0);
    ((struct Obj03812 *)p)->f8=func_020490F4(63,heap); ((struct Obj03812 *)p)->f180=heap;
    func_021C6698((void *)0x180);
    func_021C66A8(p,heap); func_021C67A8(p,heap); func_021C692C((u8 *)p,heap);
    func_021C69C4((u8 *)p,q,heap); func_021C6CB0(p,heap); func_021C6A84((u8 *)p,heap); func_021CA0BC(p,heap);
    func_0203D34C(1,52); func_020434DC(16,1); func_02043598(16,1);
}






void func_021C6638(u8 *p) { if(((struct Obj06477 *)p)->f34) { func_0201C4E4(((struct Obj06477 *)p)->f34);func_021CA478((char *)p); } if(((struct Obj06477 *)p)->f28) func_020310C4(((struct Obj06477 *)p)->f28);func_0204A600(); }






/*
 * calls: preserves incoming r0 at the tail call; callers load its argument
 *   even though func_0204A648's own body ignores that register.
 */
void func_021C665C(void *p) { func_0204A648(); }






void func_021C6664(u8 *p) {func_021CA10C(p);func_021C6DAC(p);func_021C6AC0(p);func_021C6A5C(p);func_021C6980(p);func_021C68C4((char *)p);func_021C6790(p);func_02049238(((struct Obj00725 *)p)->f8);}







void func_021C6698(void *a0)
{
    func_020433E0((const struct DispVram *)d_021CA5CC);
}








void func_021C66A8(char *p,int heap)
{
    DispConfig config;
    int i;
    func_0203F8F4(heap);
    config=d_021CA664;
    func_0203FC28((struct DispConfig *)(&config));
    for(i=0;i<5;i++) {
        func_0203FCA0((u8)i,(const struct BgTemplate *)d_021CA718[i],0);
        func_02040B94(i,32,0,heap);
        func_0204152C((u8)i,0);
        func_02040588(i,1);
    }
    func_02049B68(((struct Obj04504 *)p)->f8,0,0,0,192,heap);
    func_02049B68(((struct Obj04504 *)p)->f8,0,4,0,192,heap);
    func_02049658(((struct Obj04504 *)p)->f8,3,0,0,0,0,heap);
    func_02049658(((struct Obj04504 *)p)->f8,3,2,0,0,0,heap);
    func_02049658(((struct Obj04504 *)p)->f8,3,4,0,0,0,heap);
    func_020498F4(((struct Obj04504 *)p)->f8,5,0,0,0,0,heap);
    func_020498F4(((struct Obj04504 *)p)->f8,14,4,0,0,0,heap);
}









void func_021C6790(u8 *a0)
{
    int i;
    for (i = 0; i < 5; i++)
        func_020403F4((u8)i);
    func_0203F9B4();
}








void func_021C67A8(char *p,int heap)
{
    Config_021C6180 config=d_020A1448;
    void *bank,*archive;
    u32 first,second;
    config.c=16;
    config.d=112;
    func_0204A48C((const struct Cfg *)(&config),(u32)d_021CA5CC,heap);
    bank=func_0204B100(32,0,heap);
    ((struct Obj01936 *)p)->f138=bank;
    CLACT_SetUnitDefaultRenderer(bank);
    ((struct Obj01936 *)p)->f140=func_0204B034(d_021CA7D0,1,heap);
    bank=func_0204B100(18,1,heap);
    ((struct Obj01936 *)p)->f13C=bank;
    func_0204B258(bank,((struct Obj01936 *)p)->f140);
    ((struct Obj01936 *)p)->f144=func_0204A6C8(((struct Obj01936 *)p)->f8,4,0,0,heap);
    ((struct Obj01936 *)p)->f14C=func_0204ABF0(((struct Obj01936 *)p)->f8,1,0,0,heap);
    ((struct Obj01936 *)p)->f154=func_0204AF28(((struct Obj01936 *)p)->f8,15,16,heap);
    archive=func_020490F4(func_020275E4(),heap);
    ((struct Obj01936 *)p)->f148=func_0204A6C8(archive,func_02027618(),0,0,heap);
    ((struct Obj01936 *)p)->f150=func_0204ABF0(archive,func_02027614(),0,96,heap);
    first=func_0202761C(2);
    second=func_02027620(2);
    ((struct Obj01936 *)p)->f158=func_0204AF28(archive,first,second,heap);
    func_02049238(archive);
}








void func_021C68C4(char *p)
{
    unsigned i;
    for(i=0;i<2;i++) func_0204A8D4(*(u32 *)(p+i*4+0x144));
    for(i=0;i<2;i++) func_0204ADA4(*(u32 *)(p+i*4+0x14c));
    for(i=0;i<2;i++) func_0204AFD8(*(u32 *)(p+i*4+0x154));
    func_0204B1CC((struct Bank *)(((struct Obj00725 *)p)->f13C));
    func_0204B084(((struct Obj00725 *)p)->f140);
    func_0204B1CC((struct Bank *)(((struct Obj00725 *)p)->f138));
    func_0204A5AC();
}








void func_021C692C(u8 *p, int heap)
{
    func_0201DD68();
    ((struct Obj05377 *)p)->f0=func_0201EC64(heap);
    ((struct Obj05377 *)p)->f4=func_02045B38(0,2,211,heap);
    ((struct Obj05377 *)p)->f17C=func_0201D7EC(23,0,0,0,heap);
    ((struct Obj05377 *)p)->f28=func_0203101C(heap,heap,3,256);
    ((struct Obj05377 *)p)->f2C=0;
    ((struct Obj05377 *)p)->f34=(void *)func_0201C440((void *)heap);
}








void func_021C6980(u8 *p)
{
    func_0201C6EC(((struct Obj00725 *)p)->f34);
    func_0201C4C0(((struct Obj00725 *)p)->f34);
    ((struct Obj00725 *)p)->f34=0;
    if (((struct Obj00725 *)p)->f2C) {
        func_0201CE48(((struct Obj00725 *)p)->f2C);
        ((struct Obj00725 *)p)->f2C=0;
    }
    func_02031140(((struct Obj00725 *)p)->f28);
    ((struct Obj00725 *)p)->f28=0;
    func_0201D83C(((struct Obj00725 *)p)->f17C);
    func_02045C04(((struct Obj00725 *)p)->f4);
    func_0201ED04(((struct Obj00725 *)p)->f0);
}








void func_021C69C4(u8 *p,const u8 *q,u16 heap)
{
    func_02049B40(23,5,0,320,32,heap);
    func_02049B40(23,5,4,448,32,heap);
    func_0201F5BC(1,70,11,q[13],heap);
    func_02045088(heap);
    func_021C63AC(p,(u32 *)(p+12),1,1,0,24,3,10,100,0);
    ((struct Obj08126 *)p)->f14=func_020457B0(128,heap);
    ((struct Obj08126 *)p)->f18=func_020457B0(128,heap);
    ((struct Obj08126 *)p)->f1C=func_020457B0(128,heap);
    ((struct Obj08126 *)p)->f20=func_020457B0(128,heap);
}








void func_021C6A5C(u8 *p) { func_02045808(((struct Obj00725 *)p)->f1C);func_02045808(((struct Obj00725 *)p)->f20);func_02045808(((struct Obj00725 *)p)->f14);func_02045808(((struct Obj00725 *)p)->f18);func_020452E8(((struct Obj00725 *)p)->fC);func_020450C8(); }








void func_021C6A84(u8 *p,u16 heap) {int i;for(i=0;i<2;i++) *(void **)(p+0x16c+i*4)=func_02049EF4(((struct Obj23068 *)p)->f8,d_021CA4F5[i],0,(void **)(p+0x174+i*4),heap);}









void func_021C6AC0(u8 *p)
{
    int i;
    for (i = 0; i < 2; i++)
        func_020307B0(*(void **)(p + 0x16c + i * 4));
}








void func_021C6ADC(u8 *p,u8 *q,unsigned v)
{
    func_02043B5C(func_02045770(((struct Obj05378 *)q)->f0),0);
    func_02045334(((struct Obj05378 *)q)->f0);
    func_02045CAC(((struct Obj00329 *)p)->f4,v,((struct Obj00329 *)p)->f18);
    func_0201F250(((struct Obj00329 *)p)->f0,((struct Obj00329 *)p)->f14,((struct Obj00329 *)p)->f18);
    func_021B6AE4(q,(void *)(((struct Obj00329 *)p)->f34),0,4,(u32)(((struct Obj00329 *)p)->f14),(u32)(((struct Obj00329 *)p)->f17C),0x3c40,0);
    func_021CA4B4(((struct Obj05378 *)q)->f0);
}









void func_021C6B38(u8 *p)
{
    void *q = ((struct Obj14046 *)p)->fC;
    func_020456F8(q);
    func_02041B6C(func_02045730(q));
}








void func_021C6B50(void **p,u64 value)
{
    func_0201EFA4(*p,1,(unsigned)(value/100000000ULL),4,2,1);
    func_0201EFA4(*p,2,(unsigned)(value/10000ULL%10000ULL),4,2,1);
    func_0201EFA4(*p,3,(unsigned)(value%10000ULL),4,2,1);
}








void func_021C6BCC(u8 *p,u8 *q,int idx,unsigned heap)
{
    void *base;
    void *obj;
    void *str;
    base=(void *)func_0201283C(((struct Obj10485 *)q)->f4);
    obj=func_0200846C(heap);
    str=func_020457B0(10,heap);
    func_02045924(str,(const u16 *)func_020099D4(base,idx));
    func_020084E4(obj,str);
    func_02045808(str);
    func_0201F02C(((struct Obj00329 *)p)->f0,0,obj);
    func_020307B0(obj);
}








int func_021C6C20(u8 *p,u8 *q,int idx)
{
    void *base;
    unsigned v;
    int result;
    base=(void *)func_0201283C(((struct Obj23069 *)q)->f4);
    result=1;
    v=func_02009864(base,idx,7);
    if(v==0) result=0;
    func_0201EFA4(((struct Obj10483 *)p)->f0,2,v,2,0,1);
    v=func_02009864(base,idx,5);
    func_0201EFA4(((struct Obj10483 *)p)->f0,0,v,4,1,1);
    v=func_02009864(base,idx,6);
    func_0201EFA4(((struct Obj10483 *)p)->f0,1,v,2,0,1);
    return result;
}









void func_021C6C94(char **p, int a)
{
    func_0201EFA4((struct WordSet *)(*p), 0, a, 4, 1, 1);
}








/*
 * calls: 0204B294 returns the handle read in r0; heap is not truncated.
 * note 2026-10-05 (wave D9r lane 131): removed the 6 dead first assignments
 * (`a=0x138;` before `a=0x148;`; `b=0x138;` before `b=0x150;` and 4 more).
 * Game code has no line table, so these were stand-ins. The plain single
 * assignment gives EXACT in --lang c99 and --lang c: the output bytes do not
 * change. Older text in this header that asks for the double assignment is
 * superseded.
 */
void func_021C6CB0(char *p,u16 heap)
{
    int a,b,c,d,e,f,i;
    char *q;
    void *handle;
    a=0x148;
    b=0x150;
    c=0x158;
    d=0x15c;
    e=0x15c;
    f=0x15c;
    for(i=0;i<2;i++) {
        q=p+i*4;
        *(void **)(q+d)=func_0204B294(((struct Obj02481 *)p)->f138,*(u32 *)(p+a),*(u32 *)(p+b),*(u32 *)(p+c),&d_021CA800[i],0,heap);
        func_0204B92C(*(void **)(q+e),1);
        func_0204B3DC(*(void **)(q+f),0);
    }
    handle=func_0204B294(((struct Obj02481 *)p)->f138,((struct Obj02481 *)p)->f148,((struct Obj02481 *)p)->f150,((struct Obj02481 *)p)->f158,&d_021CA810,0,heap);
    ((struct Obj02481 *)p)->f164=handle;
    func_0204B3DC(handle,1);
    handle=func_0204B294(((struct Obj02481 *)p)->f138,((struct Obj02481 *)p)->f148,((struct Obj02481 *)p)->f150,((struct Obj02481 *)p)->f158,&d_021CA818,0,heap);
    ((struct Obj02481 *)p)->f168=handle;
    func_0204B3DC(handle,1);
}








void func_021C6DAC(u8 *p) {int i;func_0204B3B4(((struct Obj00725 *)p)->f168);func_0204B3B4(((struct Obj00725 *)p)->f164);for(i=0;i<2;i++) func_0204B3B4(*(void **)((u32)p+i*4+0x15c));}








void func_021C6DD8(u8 *p,u32 a) {int i; for(i=0;i<2;i++) func_0204B3DC(*(void **)((u32)p+i*4+0x15c),a);}








void func_021C6DF8(u8 *p,u32 a) {int i; for(i=0;i<2;i++) func_0204B92C(*(void **)((u32)p+i*4+0x15c),a);}








void func_021C6E18(u8 *p,int i,u16 a) {func_0204B92C(*(void **)((u32)p+0x15c+i*4),1);func_0204B878(*(void **)((u32)p+0x15c+i*4),a);func_0204B9A0(*(void **)((u32)p+0x15c+i*4));}








void *func_021C6E3C(void *p,void **q,int a,int heap) {TextConfig_021C6180 c;c.heap=heap;c.count=2;c.entries=p;c.mode=1;c.x=32;if(a==1)c.y=18;else c.y=12;c.a=8;c.b=3;return func_02027778((struct TaskMenuTmpl *)(&c),*q);}








int func_021C6E74(u8 *p) {int n;func_02027974(p);if(func_020279E8((struct TaskMenu *)p)==1) {n=func_02027A04(p);func_02027858((struct TaskMenu *)p);return n;}return -1;}








void func_021C6EA0(u8 *p,u8 *q,u8 *r,u16 heap) {((struct Obj14034 *)q)->f0=func_020355C4();func_021C7140((struct P *)p,q,r,heap);}








/*
 * note: 2026-10-05 lane P24L6. Bytes equal to the original (632 B function, 640 B listing
 * extent includes the 8 B stub func_021C7138). Only the two func_021C7138 relocations
 * lack a witness: the stub is now filed as src/matched/ov/ov128_func_021C7138.c (EXACT),
 * so this file should become EXACT after the next manifest refresh. Recoup trail: the
 * condition chain on *p (3,4,1) is an if/else-if chain with q[8]=5 repeated in each arm
 * (bne over b); the shared finish block (func_021C7694 with ctx as 2nd argument,
 * func_021CA19C, q[8]=3) is written out in each of its three arms (case 10 arm 0, case 10
 * arm 1, case 11) and case 10 is an inner switch on the menu status. A goto finish form
 * and a return-0 form were each 4 to 70 bytes off. Callee problem: matched func_021C7694
 * takes one parameter but this caller passes two (p, ctx).
 */
int func_021C6EC0(u8 *p, u8 *q, u8 *ctx, int heap)
{
    int result;
    void *text;
    u64 number;
    switch(q[8]) {
    case 0:
        func_021C6EA0(p,q,ctx,52);
        func_021C72E4(p,(int *)q,ctx);
        func_0202208C(0,1,1,0,6,1,heap);
        q[8]=1;
        break;
    case 1:
        if(func_020221A4()!=0) q[8]=3;
        break;
    case 2:
        func_021C6EA0(p,q,ctx,52);
        func_021C72E4(p,(int *)q,ctx);
        q[8]=3;
        break;
    case 3:
        BLINK_PALANM_Update(*(void **)(ctx+0x184));
        result=func_021C74C4((int *)p,(int *)q,ctx);
        if(result!=0) {
            if(*(u32 *)p==3) func_021CA3A0((char *)ctx);
            else if(*(u32 *)p==4) func_021CA3C4((char *)ctx);
            else *(u16 *)(p+8)=0;
            q[8]=4;
        }
        break;
    case 4:
        if(*(u32 *)p==3) {
            if(func_0204B98C(*(void **)(ctx+0x164))==1) break;
        } else if(*(u32 *)p==4) {
            if(func_0204B98C(*(void **)(ctx+0x168))==1) break;
        } else {
            if(func_021CA1E0((char *)p)==1) break;
        }
        if(func_021C76BC((int *)p,q)==1) {
            func_021C74E8((u32 *)p,q);
            if(*(u32 *)p==3) q[8]=5;
            else if(*(u32 *)p==4) q[8]=5;
            else if(*(u32 *)p==1) q[8]=5;
            else {
                func_021C7500(p,ctx);
                func_021C7138(p,q,ctx);
                return 1;
            }
        } else {
            func_021C7558(p,ctx,58,heap);
            q[8]=11;
        }
        break;
    case 5:
        func_0202208C(0,0,0,0,6,1,heap);
        q[8]++;
        break;
    case 6:
        if(func_020221A4()==1) {
            func_021C7138(p,q,ctx);
            return 1;
        }
        break;
    case 7:
        func_021C6EA0(p,q,ctx,52);
        func_021C72E4(p,(int *)q,ctx);
        func_0202208C(0,1,1,0,6,1,heap);
        q[8]=8;
        break;
    case 8:
        if(func_020221A4()!=0) {
            text=func_0200846C(heap);
            func_020084E4(text,*(void **)(q+0x58));
            func_0201F02C(*(void **)ctx,0,text);
            func_020307B0(text);
            number=func_021CA014(*(void **)(q+0x5C),&result);
            if(result!=0) {
                func_021C6B50((void **)ctx,number);
                func_021C7558(p,ctx,55,heap);
                q[8]=9;
            } else {
                func_021C7558(p,ctx,56,heap);
                q[8]=11;
            }
        }
        break;
    case 9:
        if(func_021C7674(p,(int *)q,ctx)!=0) {
            *(void **)(p+0x4C)=func_021C6E3C(p+0x30,(void **)(p+0x48),1,heap);
            q[8]=10;
        }
        break;
    case 10:
        switch(func_021C6E74(*(void **)(p+0x4C))) {
        case 0:
            {
            int submission;
            *(u32 *)q=func_020355C4();
            submission=func_021C6460((char *)q,*(void **)(q+0x5C),*(u32 *)(q+0x58));
            if(submission==0) {
                func_021C7694(p,ctx);
                func_021CA19C((unsigned int *)p);
                q[8]=3;
            } else {
                func_021C7558(p,ctx,d_021CA4F9[submission],heap);
                q[8]=11;
            }
            }
            break;
        case 1:
            *(u32 *)q=func_020355C4();
            func_021C7694(p,ctx);
            func_021CA19C((unsigned int *)p);
            q[8]=3;
            break;
        }
        break;
    case 11:
        if(func_021C7674(p,(int *)q,ctx)!=0 && func_021CA084((int *)q)==1) {
            func_021C7694(p,ctx);
            func_021CA19C((unsigned int *)p);
            q[8]=3;
        }
        break;
    default:
        break;
    }
    return 0;
}








void func_021C7138(u8 *p,u8 *q,u8 *ctx) { func_021C72A0(p,q,ctx); }








void func_021C7140(struct P *p, u8 *a, u8 *ctx, u16 heap)
{
    int i;
    void *buf;
    void *text;
    u32 width;
    func_021C63AC(ctx,(u32 *)((u8 *)p+12),3,4,5,24,20,10,1,0);
    func_021C63AC(ctx,(u32 *)((u8 *)p+28),1,2,19,27,4,10,172,0);
    p->buf=func_020457B0(128,heap);
    buf=func_020457B0(128,heap);
    text=func_020457B0(128,heap);
    func_0201F02C(((struct Obj02482 *)ctx)->f0,0,func_02012944(((struct Obj14034 *)a)->f4));
    for(i=0;i<3;i++) {
        func_02045CAC(((struct Obj02482 *)ctx)->f4,i+1,text);
        func_0201F250(((struct Obj02482 *)ctx)->f0,buf,text);
        width=func_0201D304((struct StrObj *)((u32)buf),((struct Obj02482 *)ctx)->f17C,0);
        func_021B6AE4((u8 *)p+12,(void *)(((struct Obj02482 *)ctx)->f34),(192-width)/2,i*40+8,(u32)buf,((struct Obj02482 *)ctx)->f17C,0x440,0);
    }
    func_021CA4B4(((struct Obj02841 *)p)->fC);
    func_02045808(buf);
    func_02045808(text);
    ((struct Obj02841 *)p)->f14=func_02049EF4(((struct Obj02482 *)ctx)->f8,13,0,(void **)((u8 *)p+24),heap);
    p->text1=func_02045EC0(((struct Obj02482 *)ctx)->f4,66);
    p->color1=0x39e3;
    p->flag1=0;
    p->text2=func_02045EC0(((struct Obj02482 *)ctx)->f4,67);
    p->color2=0x39e3;
    p->flag2=0;
    p->menu=func_02027F60(1,14,((struct Obj02482 *)ctx)->f17C,((struct Obj02482 *)ctx)->f34,heap);
}








void func_021C72A0(u8 *p, u8 *unused, u8 *q)
{
    func_021CA444((char *)q);
    func_021CA458((char *)q,q+12);
    func_02027FD8(((struct Obj04505 *)p)->f48);
    func_02045808(((struct Obj04505 *)p)->f30);
    func_02045808(((struct Obj04505 *)p)->f3C);
    func_02045808(((struct Obj04505 *)p)->f2C);
    func_020452E8(((struct Obj04505 *)p)->f1C);
    func_020452E8(((struct Obj04505 *)p)->fC);
    func_020307B0(((struct Obj04505 *)p)->f14);
}








void func_021C72E4(u8 *p,int *q,u8 *ctx)
{
    u16 *data;
    func_021C6ADC(ctx,ctx+12,0);
    data=*(u16 * *)&((struct Obj14035 *)p)->f18;
    func_02041090(2,(unsigned int)((u8 *)data+12),0,0,data[0]>>3,data[1]>>3);
    func_02040618(2,0,0);
    func_02040618(2,3,0);
    if(*q==0) func_021CA16C(ctx,((struct Obj14035 *)p)->f0);
    else func_02041B6C(2);
}








int func_021C734C(u32 *p, int *q, u8 *ctx)
{
    if (func_020362DC() & 2) {
        func_020061E4(0x551);
        func_021CA154(ctx, *p);
        func_020355D8(0);
        *q = 0;
        *p = 3;
        return 1;
    }
    if (func_020362DC() & 1024) {
        func_020061E4(0x556);
        func_021CA154(ctx, *p);
        func_020355D8(0);
        *q = 0;
        *p = 4;
        return 1;
    }
    if (*q == 1) {
        if (func_020362DC() & 0xcf3) {
            func_020061E4(0x548);
            func_021CA184(ctx, *p, *p);
            func_020355D8(0);
            *q = 0;
        }
        return 0;
    }
    if (func_020362DC() & 1) {
        func_020061E4(0x54c);
        BLINK_PALANM_ResetPhase(((struct Obj00329 *)ctx)->f184);
        return 1;
    }
    if (func_0203633C() & 64) {
        if (*p != 0) {
            func_020061E4(0x548);
            func_021CA184(ctx, *p - 1, *p);
            --*p;
            return 0;
        }
    } else if (func_0203633C() & 128) {
        if (*p < 2) {
            func_020061E4(0x548);
            func_021CA184(ctx, *p + 1, *p);
            ++*p;
            return 0;
        }
    }
    return 0;
}







int func_021C7460(int *p,int *q,u8 *ctx)
{
    int v;
    v=func_02035C08(d_021CA58A);
    if(v!=-1) {
        if(v==3) {
            func_020061E4(1361);
            func_021CA154(ctx,*p);
        } else if(v==4) {
            func_020061E4(1366);
            func_021CA154(ctx,*p);
        } else {
            func_020061E4(1356);
            func_021CA184(ctx,v,*p);
        }
        *p=v;
        func_020355D8(1);
        *q=1;
    }
    return v;
}







int func_021C74C4(int *p,int *q,u8 *r) {if(func_021C7460(p,q,r)!=-1) return 1;return func_021C734C((u32 *)p,q,r);}







void func_021C74E8(u32 *p,u8 *q) {func_021C6438(q,d_021CA51C[*p],0);}







void func_021C7500(u8 *p,u8 *q)
{
    void *obj;
    func_021C6B38(q);
    func_02041300(2,0,0,0,32,24,16);
    func_02041B6C(2);
    func_02041300(3,0,0,0,32,24,16);
    func_02041B6C(3);
    obj=((struct Obj23075 *)p)->fC;
    func_020456F8(obj);
    func_02041B6C(func_02045730(obj));
}







void func_021C7558(u8 *p,u8 *ctx,unsigned v,unsigned heap)
{
    void *buf;
    void *obj;
    int font;
    if(((struct Obj03280 *)ctx)->f2C) {
        func_0201CE48(((struct Obj03280 *)ctx)->f2C);
        ((struct Obj03280 *)ctx)->f2C=0;
    }
    buf=func_020457B0(128,heap);
    func_02043B5C(func_02045770(((struct Obj05379 *)p)->f1C),15);
    func_02045CAC(((struct Obj03280 *)ctx)->f4,v,buf);
    func_0201F250(((struct Obj03280 *)ctx)->f0,((struct Obj05379 *)p)->f2C,buf);
    font=func_02012FFC();
    ((struct Obj03280 *)ctx)->f2C=func_0201CCE4(((struct Obj05379 *)p)->f1C,0,0,((struct Obj05379 *)p)->f2C,((struct Obj03280 *)ctx)->f17C,(void *)font,((struct Obj03280 *)ctx)->f28,10,((struct Obj03280 *)ctx)->f180,0);
    func_0201F73C(((struct Obj05379 *)p)->f1C,2,70,11);
    obj=((struct Obj05379 *)p)->f1C;
    func_02045334(obj);
    func_02045374(obj);
    func_02041B6C(func_02045730(obj));
    func_02045808(buf);
    func_021CA3E8(0);
}







int func_021C7600(void *p, int *q)
{
    switch (func_0201CE30(p)) {
    case 0:
        if (func_02035C60() == 1 || (func_0203630C() & 3)) func_0201CE5C(p, 0);
        *q = 0;
        break;
    case 1:
        if (*q == 0 && (func_02035C60() == 1 || (func_020362DC() & 3))) {
            func_020061E4(0x547);
            func_0201CE38(p);
            *q = 1;
        }
        break;
    case 2:
        func_0201CE48(p);
        *q = 0;
        return 0;
    }
    return 1;
}







int func_021C7674(void *p,int *q,u8 *r) {if(func_021C7600(((struct Obj23077 *)r)->f2C,(int *)(r+48))==0) {*q=0;return 1;}return 0;}






void func_021C7694(u8 *p, void *ctx) {void *q;func_021CA3E8(1);func_0201F7A8(((struct Obj14037 *)p)->f1C,0);q=((struct Obj14037 *)p)->f1C;func_020456F8(q);func_02041B6C(func_02045730(q));}






int func_021C76BC(int *p,u8 *q) {int i;void *v;if(*p==1) {v=(void *)func_0201283C(((struct Obj23079 *)q)->f4);for(i=0;i<32;i++) {if(func_02009A1C(v,i)==0) return 1;}}else return 1;return 0;}






/*
 * leaf: sole unresolved overlay blocker of handed 021C76F8.
 */
void func_021C76F0(u8 *p,u8 *q,u8 *ctx,u16 value)
{
    func_021C7ACC(p,q,ctx,value);
}






/*
 * extent: 021C7AC4 is the eight-byte tail stub to 021C7D48.
 * calls: Entry_021C6180 r0-r3 stay live into argumentless switch-arm calls.
 * Original explicit r1=ctx on 021C87B0/8850/8880 is retained even
 * where the callee reads only r0. All signed indexed reads are modular.
 */
/*
 * extent: 021C7AC4 is the eight-byte tail stub to 021C7D48.
 * calls: Entry r0-r3 stay live into argumentless switch-arm calls.
 * Original explicit r1=ctx on 021C87B0/8850/8880 is retained even
 * where the callee reads only r0. All signed indexed reads are modular.
 */
int func_021C76F8(u8 *p,u8 *q,u8 *ctx,u16 heap)
{
    int idx;
    u32 base;
    switch(q[8]) {
    case 0:
        *(u16 *)&((struct Obj00179 *)p)->f0=0; ((struct Obj00179 *)p)->f2=0; *(u16 *)&((struct Obj00179 *)p)->f4=0; ((struct Obj00179 *)p)->f6=0;
    case 1:
        func_021C76F0(p,q,ctx,52);
        func_021C6520((char *)q);
        func_021C7E0C(p,q,ctx,heap);
        q[8]=2;
        break;
    case 2:
        BLINK_PALANM_Update(((struct Obj03809 *)ctx)->f184);
        BLINK_PALANM_Update(((struct Obj03809 *)ctx)->f188);
        switch(func_021C81C8((s16 *)p,q,ctx)) {
        case 0: break;
        case 1:
            func_021C8668(p,q,2);
            func_021CA40C((char *)p,((struct Obj00179 *)p)->f0);
            BLINK_PALANM_ResetPhase(((struct Obj03809 *)ctx)->f188);
            BLINK_PALANM_Update(((struct Obj03809 *)ctx)->f188);
            break;
        case 2:
            func_021C8668(p,q,3);
            func_021CA40C((char *)p,((struct Obj00179 *)p)->f0);
            BLINK_PALANM_ResetPhase(((struct Obj03809 *)ctx)->f188);
            BLINK_PALANM_Update(((struct Obj03809 *)ctx)->f188);
            break;
        case 3: q[8]=25; break;
        case 4: q[8]=26; break;
        case 5: q[8]=6; break;
        }
        break;
    case 3: func_021C81FC(p,q,ctx,heap); q[8]=4; break;
    case 4: if(func_021C8240(p,q,ctx,heap)==1) q[8]=5; break;
    case 5: if(func_021C8354(p,ctx)==1) q[8]=2; break;
    case 6:
        if(func_021CA320((char *)p)!=1) {
            func_021C651C((char *)q,func_021C87A0((s16 *)p));
            func_021C83B0((s16 *)p,q,ctx,heap); q[8]=7;
        }
        break;
    case 7:
        if(func_021C873C(p,(int *)q,ctx)==1) {func_021C83DC(p,q,ctx,heap);q[8]=8;}
        break;
    case 8: q[8]=func_021C8470(p,(int *)q,ctx); break;
    case 9: ((struct Obj00179 *)p)->f19C=8; q[8]=10; break;
    case 10:
        (((struct Obj00179 *)p)->f19C)--;
        if(((struct Obj00179 *)p)->f19C<=0) {
            func_021C7E48(p,q,ctx);func_021C6438(q,4,0);func_021C7AC4(p,q,ctx);return 1;
        }
        break;
    case 11:
        ((struct Obj00179 *)p)->f0=((struct Obj00298 *)q)->fB/8;
        ((struct Obj00179 *)p)->f4=((struct Obj00298 *)q)->fB%8;
        q[8]=1;
        break;
    case 12:
        func_0202208C(0,0,0,0,6,1,heap);
        idx=func_021C87A0((s16 *)p);
        base=func_0201283C(((struct Obj00298 *)q)->f4);
        func_021C6514((char *)q,(int)func_020099D4((void *)base,*(u8 *)((u32)q+(u32)idx+24)));
        q[8]=13;
        break;
    case 13:
        if(func_020221A4()!=0) {
            func_021C7E48(p,q,ctx);func_021C6438(q,2,4);func_021C7AC4(p,q,ctx);return 1;
        }
        break;
    case 14:
        idx=func_021C87A0((s16 *)p);
        base=func_0201283C(((struct Obj00298 *)q)->f4);
        func_02009A00((void *)base,*(u8 *)((u32)q+(u32)idx+24),((struct Obj00298 *)q)->f58);
    case 15:
        func_021C76F0(p,q,ctx,52);func_021C7E0C(p,q,ctx,heap);
        func_0202208C(0,1,1,0,6,1,heap);q[8]=16;
        break;
    case 16: if(func_020221A4()!=0) q[8]=2; break;
    case 17: func_021C8548((s16 *)p,q,ctx,heap);q[8]=18;break;
    case 18: if(func_021C8574(p,(int *)q,ctx,heap)==1) q[8]=19;break;
    case 19:
        switch(func_021C6E74(((struct Obj00179 *)p)->f194)) {
        case 0:
            ((struct Obj00298 *)q)->f0=func_020355C4();func_021C875C((char *)p,(char *)ctx);q[8]=20;break;
        case 1:
            ((struct Obj00298 *)q)->f0=func_020355C4();func_021C875C((char *)p,(char *)ctx);q[8]=2;break;
        }
        break;
    case 20: func_021C87B0(p,ctx);q[8]=21;break;
    case 21:
        if(func_021C8850(p,ctx)==1) {
            base=func_0201283C(((struct Obj00298 *)q)->f4);
            idx=func_021C87A0((s16 *)p);
            func_02009A74((void *)base,*(u8 *)((u32)q+(u32)idx+24));
            func_021C6520((char *)q);
            func_021C85A4(p,q,ctx,((struct Obj00179 *)p)->f0,((struct Obj00179 *)p)->f4,0,heap);q[8]=22;
        }
        break;
    case 22: func_021C8880(p,ctx);q[8]=2;break;
    case 23:
        if(func_021C84E8(p,q,ctx,heap)==1) q[8]=24;
        else q[8]=2;
        break;
    case 24:
        if(func_021C873C(p,(int *)q,ctx)!=0 && func_021CA084((int *)q)==1) {q[8]=2;func_021C875C((char *)p,(char *)ctx);}
        break;
    case 25:
        if(func_0204B98C(((struct Obj03809 *)ctx)->f164)!=1) {
            func_021C7E48(p,q,ctx);func_021C6438(q,0,2);func_021C7AC4(p,q,ctx);return 1;
        }
        break;
    case 26: if(func_0204B98C(((struct Obj03809 *)ctx)->f168)!=1) q[8]=27;break;
    case 27: func_0202208C(0,0,0,0,6,1,heap);q[8]=28;break;
    case 28:
        if(func_020221A4()!=0) {func_021C6438(q,6,0);func_021C7AC4(p,q,ctx);return 1;}
        break;
    }
    return 0;
}






void func_021C7AC4(u8 *p,u8 *q,u8 *ctx) {func_021C7D48(p,q,ctx);}






static inline int iabs(int v)
{
    return v < 0 ? -v : v;
}






void func_021C7ACC(u8 *p, void *unused, u8 *ctx, u16 heap)
{
    int i;
    int j;
    Rect r1;
    Rect r2;
    for (i = 0; i < 2; i++) {
        func_021C63AC(ctx, (u32 *)(p + 0xf0 + i * 8), 3,
            (u8)(iabs(d_021CA564[i].x) + 4), (u8)(iabs(d_021CA564[i].y) + 4), 0x1a, 0x11, 0xa, 0, 0);
    }
    for (j = 0; j < 3; j++)
        func_021C88AC((u16 *)(p + 12 + j * 0x4c), (u16 *)ctx, (u16 *)((const void *)&d_021CA564[j]), 0, heap);
    *(u8 **)(p + 0x14) = p + 0xf0;
    *(u8 **)(p + 0xac) = p + 0xf8;
    *(u8 **)(p + 0x60) = p + 0xf8;
    *(void **)(p + 0x104) = func_021C3EE0(*(void **)(ctx + 0x13c), 0, 0x10, heap);
    func_021C4044(*(u8 **)(p + 0x104), 0, 2, 0xe0, heap);
    for (i = 0; i < 4; i++) {
        const W2 *e = &d_021CA688[i];
        *(void **)(p + i * 12 + 0x118) = func_02045EC0(*(struct MsgBank **)(ctx + 4), d_021CA688[i].a);
        *(u16 *)(p + i * 12 + 0x11c) = 0x39e3;
        *(u32 *)(p + i * 12 + 0x120) = 0;
        *(void **)(p + i * 12 + 0x148) = func_02045EC0(*(struct MsgBank **)(ctx + 4), e[4].a);
        *(u16 *)(p + i * 12 + 0x14c) = 0x39e3;
        *(u32 *)(p + i * 12 + 0x150) = 0;
    }
    *(u32 *)(p + 0x144) = 1;
    *(u32 *)(p + 0x174) = 1;
    *(void **)(p + 0x178) = func_02045EC0(*(struct MsgBank **)(ctx + 4), 0x42);
    *(u16 *)(p + 0x17c) = 0x39e3;
    *(u32 *)(p + 0x180) = 0;
    *(void **)(p + 0x184) = func_02045EC0(*(struct MsgBank **)(ctx + 4), 0x43);
    *(u16 *)(p + 0x188) = 0x39e3;
    *(u32 *)(p + 0x18c) = 0;
    *(struct R **)(p + 0x190) = func_02027F60(1, 14, *(u32 *)(ctx + 0x17c), *(u32 *)(ctx + 0x34), heap);
    func_021C63AC(ctx, (u32 *)(p + 0x108), 1, 2, 1, 0x1b, 4, 0xa, 0, 0xf);
    *(struct U16Vec **)(p + 0x110) = func_020457B0(0x80, heap);
    r1 = d_021CA650;
    *(struct Obj **)(p + 0x1a0) = func_0204B294(*(u32 *)(ctx + 0x138), *(u32 *)(ctx + 0x144), *(u32 *)(ctx + 0x14c), *(u32 *)(ctx + 0x154), &r1, 0, heap);
    func_0204B3DC(*(struct Obj **)(p + 0x1a0), 0);
    r2 = d_021CA638;
    *(struct Obj **)(p + 0x1a4) = func_0204B294(*(u32 *)(ctx + 0x138), *(u32 *)(ctx + 0x144), *(u32 *)(ctx + 0x14c), *(u32 *)(ctx + 0x154), &r2, 0, heap);
}






void func_021C7D48(u8 *p, void *unused, u8 *a)
{
    int i;
    int offset;
    func_021CA444((char *)a);
    func_021CA458((char *)a,a + 12);
    func_0204B3B4(((struct Obj03281 *)p)->f1A4);
    func_0204B3B4(((struct Obj03281 *)p)->f1A0);
    func_020452E8(((struct Obj03281 *)p)->f108);
    func_02045808(((struct Obj03281 *)p)->f110);
    func_02027FD8(((struct Obj03281 *)p)->f190);
    func_02045808(((struct Obj03281 *)p)->f178);
    func_02045808(((struct Obj03281 *)p)->f184);
    offset=0x1a4;
    i=0;
    offset=0x118;
    for (; i < 4; i++) {
        func_02045808(*(void **)(p + i * 12 + offset));
        func_02045808(*(void **)(p + i * 12 + 0x148));
    }
    func_021C4080(((struct Obj03281 *)p)->f104);
    func_021C3F80(*(u8 * *)&((struct Obj03281 *)p)->f104);
    for(i=0;i<3;i++) func_021C88BC(p + 12 + i * 0x4c,a);
    for(i=0;i<2;i++) func_020452E8(*(void **)(p + i * 8 + 0xf0));
}






void func_021C7E0C(u8 *p,u8 *q,u8 *r,u16 heap) {func_021C6ADC(r,r+12,5);func_02041B6C(0);func_021C85A4(p,q,r,((struct Obj00179 *)p)->f0,((struct Obj00179 *)p)->f4,0,heap);}






void func_021C7E48(u8 *p,void *q,u8 *r) {int i;func_021C6B38(r);for(i=0;i<3;i++)func_021C89C4((char *)(p+12+i*76),r,r+364);func_02041B6C(0);}






int func_021C7E78(s16 *p, u8 *a, void *b, int n)
{
    if (n == 0) {
        func_020061E4(0x551); func_021CA3A0(b); return 3;
    }
    if (n == 6) {
        func_020061E4(0x556); func_021CA3C4(b); return 4;
    }
    if (n == 5) {
        if (p[2] == 8) { func_020061E4(0x551); func_021CA3A0(b); return 3; }
        if (p[2] == 9) { func_020061E4(0x556); func_021CA3C4(b); return 4; }
        if (((struct Obj23080 *)a)->f10 <= (unsigned int)(p[2] + p[0] * 8)) return 0;
        func_020061E4(0x54c);
        p[4] = 0;
        return 5;
    }
    if (n == 1) return 1;
    return n == 2 ? 2 : 0;
}






int func_021C7F14(s16 *p, u8 *a, u8 *ctx)
{
    u16 old;
    int moved;
    int page;
    int dir;
    if(func_020362DC() & 2) {
        func_020355D8(0);
        ((struct Obj03810 *)a)->f0=0;
        return func_021C7E78(p,a,ctx,0);
    }
    if(func_020362DC() & 1024) {
        func_020355D8(0);
        ((struct Obj03810 *)a)->f0=0;
        return func_021C7E78(p,a,ctx,6);
    }
    if(((struct Obj03810 *)a)->f0==1) {
        if(func_020362DC() & 0xcf3) {
            func_020061E4(0x548);
            func_021CA2C4(ctx,p[2],p[2]);
            func_020355D8(0);
            ((struct Obj03810 *)a)->f0=0;
        }
        return 0;
    }
    if(func_020362DC() & 1) return func_021C7E78(p,a,ctx,5);
    old=p[2];
    moved=0;
    page=0;
    if(func_0203633C() & 64) {
        if(p[2]==0) p[2]=3;
        else if(p[2]==4) p[2]=7;
        else --p[2];
        moved=1;
    } else if(func_0203633C() & 128) {
        if(p[2]==3) p[2]=0;
        else if(p[2]==7) p[2]=4;
        else ++p[2];
        moved=1;
    } else if(func_0203633C() & 32) {
        if(p[2]<4) {
            p[2]+=4;
            page=1;
            dir=0;
        } else p[2]-=4;
        moved=1;
    } else if(func_0203633C() & 16) {
        if(p[2]<4) p[2]+=4;
        else {
            p[2]-=4;
            page=1;
            dir=1;
        }
        moved=1;
    } else if(a[14]) {
        if(a[14] && (func_0203633C() & 512)) {
            page=1;
            dir=0;
        } else if(a[14] && (func_0203633C() & 256)) {
            page=1;
            dir=1;
        }
    }
    if(page==1) {
        if(dir) {
            p[1]=p[0];
            p[0]=(p[0]+1)%4;
            return func_021C7E78(p,a,ctx,2);
        } else {
            p[1]=p[0];
            --p[0];
            if(p[0]<0) p[0]+=4;
            return func_021C7E78(p,a,ctx,1);
        }
    }
    if(moved==1) {
        func_020061E4(0x548);
        func_021CA2C4(ctx,p[2],old);
        p[3]=old;
    }
    return 0;
}






int func_021C8100(s16 *p, void *a, void *b, int *changed)
{
    u32 v = func_02035C08(d_021CA5FC);
    s8 delta;
    if (v == (u32)-1) return 0;
    if (v <= 7) {
        *changed = 1;
        func_021CA294(b, p[2]);
        p[2] = v;
        return func_021C7E78(p, a, b, 5);
    }
    if (v == 8) {
        *changed = 1;
        p[2] = v;
        return func_021C7E78(p, a, b, 5);
    }
    if (v == 9) {
        *changed = 1;
        p[2] = v;
        return func_021C7E78(p, a, b, 5);
    }
    delta = (v - 10) - p[0];
    if (delta != 0) {
        *changed = 1;
        p[1] = p[0];
        p[0] += delta;
        if (delta >= 0) {
            p[0] %= 4;
            return func_021C7E78(p, a, b, 2);
        } else {
            if (p[0] < 0) p[0] += 4;
            return func_021C7E78(p, a, b, 1);
        }
    }
    return 0;
}






int func_021C81C8(s16 *p,u8 *q,u8 *r) {int changed=0;int ret=func_021C8100(p,q,r,&changed);if(changed) {func_020355D8(1);((struct Obj03810 *)q)->f0=1;return ret;}return func_021C7F14(p,q,r);}






void func_021C81FC(u8 *p, void *a, u8 *b, u16 c)
{
    int n = ((struct Obj00179 *)p)->f102 == 2 ? 2 : 1;
    func_021C85A4(p, a, b, ((struct Obj00179 *)p)->f0, ((struct Obj00179 *)p)->f4, n, c);
    func_021CA294(b, ((struct Obj00179 *)p)->f4);
    func_020061E4(0x548);
}






/*
 * lever: Two names reproduce the duplicate 0x021CA7C0 pool words; the
 * mutable config declaration preserves sequential halfword loads/stores.
 */
int func_021C8240(u8 *p, u8 *a, u8 *b, u16 h)
{
    Pair pos;
    int delta;
    Callback cb;
    int mode;
    if (func_0201C6B4(((struct Obj10484 *)b)->f34) == 0) return 0;
    if (((struct Obj00179 *)p)->f100 > 24) {
        pos.x = d_021CA7C0.pos.x;
        pos.y = d_021CA7C0.pos.y;
        func_0204B09C(((struct Obj10484 *)b)->f140, 0, &pos);
        mode = ((struct Obj00179 *)p)->f102 == 2 ? 2 : 1;
        func_021C8A50((char *)(p + 12 + mode * 76), (int)b);
        func_021C860C(p, a, b, ((struct Obj00179 *)p)->f0, ((struct Obj00179 *)p)->f4, h);
        return 1;
    }
    delta = (((struct Obj00179 *)p)->f100 * 256) / 24;
    if (((struct Obj00179 *)p)->f102 == 2) delta = -delta;
    func_02041EE4(2, 0, delta);
    func_02041EE4(3, 0, delta);
    pos.x = d_021CA7C0.pos.x;
    pos.y = d_021CA7C0.pos.y;
    pos.x += (s16)delta;
    func_0204B09C(((struct Obj10484 *)b)->f140, 0, &pos);
    mode = ((struct Obj00179 *)p)->f100;
    if (mode % 6 != 0) {
        cb = cb_021CA7C0[mode / 6];
        if (cb != 0) cb(p, b, ((struct Obj00179 *)p)->f0, *(s16 *)&((struct Obj00179 *)p)->f2);
    }
    (((struct Obj00179 *)p)->f100)++;
    return 0;
}






/*
 * extent: two zero alignment bytes follow the compiled function.
 */
int func_021C8354(u8 *p,u8 *q) {if(func_0201C6B4(*(const struct PrintSys * *)&((struct Obj23082 *)q)->f34)==1) {func_02041EE4(2,0,0);func_02041EE4(3,0,0);func_021CA4B4(**(char ** *)&((struct Obj23081 *)p)->f14);return 1;}return 0;}






unsigned long long func_021C8388(s16 *p,u8 *q) {u32 base;base=func_0201283C(*(const struct BigObj * *)&((struct Obj10485 *)q)->f4);return DWC_GetFriendKey(func_020099C8((struct Sub020097BCObj *)base,*(u8 *)(q+24+func_021C87A0(p))));}






void func_021C83B0(s16 *p,u8 *q,u8 *r,u16 heap) {func_021C6BCC(r,q,*(u8 *)(q+24+func_021C87A0(p)),heap);func_021C867C((u8 *)p,r,12,heap);}






void func_021C83DC(u8 *p, u8 *a, void *unused, int heap)
{
    TextConfig_021C76F8 config;
    void *q = (void *)func_0201283C(((struct Obj10485 *)a)->f4);
    int result = func_02009864(q, (a + func_021C87A0((s16 *)p))[24], 9);
    config.heap = heap;
    config.count = 4;
    if (result == 2) {
        config.entries = p + (func_021C8388((s16 *)p, a) != 0 ? 0x148 : 0x118);
        ((struct Obj08130 *)p)->f198 = 1;
    } else {
        config.entries = p + 0x118;
        ((struct Obj08130 *)p)->f198 = 0;
    }
    config.mode = 1;
    config.x = 32; config.y = 24; config.a = 17; config.b = 3;
    ((struct Obj08130 *)p)->f194 = func_02027778((struct TaskMenuTmpl *)(&config), ((struct Obj08130 *)p)->f190);
}





int func_021C8470(u8 *p, int *a, void *b)
{
    int n;
    int result;
    func_02027974(((struct Obj06478 *)p)->f194);
    if (func_020279E8(((struct Obj06478 *)p)->f194) == 1) {
        n = func_02027A04(*(u8 * *)&((struct Obj06478 *)p)->f194);
        func_02027858(((struct Obj06478 *)p)->f194);
    } else return 8;
    if (n == 3) {
        *a = func_020355C4();
        result = 2;
    } else {
        *a = func_020355C4();
        result = d_021CA68C[((struct Obj06478 *)p)->f198][n * 2];
    }
    if (result == 2) func_021C875C((char *)p, b);
    else if (result == 9 || result == 12) func_021C875C((char *)p, b);
    else func_021C8784((char *)p);
    return result;
}





int func_021C84E8(u8 *p, u8 *a, u8 *b, int c)
{
    u64 value = func_021C8388((s16 *)p, a);
    func_021C6BCC(b, a, (a + func_021C87A0((s16 *)p))[0x18], c);
    if (value != 0) {
        func_021C6B50((void **)b, value);
        func_021C867C(p, b, 0x3c, c);
    } else {
        func_021C867C(p, b, 0x44, c);
    }
    return 1;
}





void func_021C8548(s16 *p,u8 *q,u8 *r,u16 heap) {func_021C6BCC(r,q,*(u8 *)(q+24+func_021C87A0(p)),heap);func_021C867C((u8 *)p,r,57,heap);}





int func_021C8574(u8 *p,int *q,u8 *r,int heap) {if(func_021C873C(p,q,r)==0)return 0;((struct Obj23084 *)p)->f194=func_021C6E3C(p+376,(void **)(p+400),0,heap);return 1;}





void func_021C85A4(u8 *p, u8 *a, u8 *b, int x, int y, int n, u16 c)
{
    int offset;
    u8 *base;
    if (n == 0) {
        ((struct Obj00179 *)p)->f0 = x;
        ((struct Obj00179 *)p)->f4 = y;
        func_021CA40C((char *)p, x);
    }
    offset = n * 0x4c;
    base = p + 12;
    func_021C88C0((s16 *)(base + offset), b, b + 0x16c);
    func_021C899C((char *)(base + offset), (char *)a, b, ((struct Obj00179 *)p)->f104, (int)(b + 0x16c), (char *)(a + 16), x, c);
    func_021CA2DC((char *)p);
}





void func_021C860C(u8 *p, u8 *a, u8 *b, int x, int y, u16 c)
{
    ((struct Obj00179 *)p)->f4 = y;
    ((struct Obj00179 *)p)->f0 = x;
    func_021CA40C((char *)p, x);
    func_021C88C0((s16 *)(p + 12), b, b + 0x16c);
    func_021C8904((char *)(p + 12), (char *)a, b, ((struct Obj00179 *)p)->f104, (int)(b + 0x16c), (char *)(a + 16), x, c);
    func_021CA2DC((char *)p);
}





void func_021C8660(void) {}





void func_021C8664(void) {}





void func_021C8668(u8 *p, u8 *a, int n)
{
    a[8] = 3;
    ((struct Obj14039 *)p)->f102 = n;
    ((struct Obj14039 *)p)->f100 = 0;
}





void func_021C867C(u8 *p, u8 *a, int n, int heap)
{
    void *text;
    void *q;
    if (((struct Obj00329 *)a)->f2C) {
        func_0201CE48(((struct Obj00329 *)a)->f2C);
        ((struct Obj00329 *)a)->f2C = 0;
    }
    func_02043B5C(func_02045770(((struct Obj03811 *)p)->f108),15);
    text=func_020457B0(128,heap);
    func_02045CAC(((struct Obj00329 *)a)->f4,n,text);
    func_0201F250(((struct Obj00329 *)a)->f0,((struct Obj03811 *)p)->f110,text);
    ((struct Obj00329 *)a)->f2C=func_0201CCE4(((struct Obj03811 *)p)->f108,0,0,((struct Obj03811 *)p)->f110,((struct Obj00329 *)a)->f17C,(void *)func_02012FFC(),((struct Obj00329 *)a)->f28,10,((struct Obj00329 *)a)->f180,0);
    func_0201F73C(((struct Obj03811 *)p)->f108,2,70,11);
    q=((struct Obj03811 *)p)->f108;
    func_02045334(q);
    func_02045374(q);
    func_02041B6C(func_02045730(q));
    func_02045808(text);
    func_021CA3E8(0);
}





int func_021C873C(void *p,int *state,u8 *q) {if(func_021C7600(((struct Obj23087 *)q)->f2C,(int *)(q+48))==0) {*state=0;return 1;}return 0;}





void func_021C875C(char *p,char *q) {func_0201F7A8(((struct Obj23088 *)p)->f108,1);func_021CA42C(q);func_021CA2DC(p);func_021CA3E8(1);}






void func_021C8784(char *p)
{
    func_02043B5C(func_02045770(((struct Obj14040 *)p)->f108), 0xf);
    func_02045334(((struct Obj14040 *)p)->f108);
}






int func_021C87A0(s16 *p)
{
    int a = p[0] * 8;

    return a + p[2];
}





static inline void Outside(int wnd,int effect)
{
    u32 tmp=(*(volatile u16 *)0x0400004A & ~0x3F) | wnd;
    if(effect) tmp |= 0x20;
    *(volatile u16 *)0x0400004A=(u16)tmp;
}





/*
 * volatile: 021C8808, 021C8814 read WINOUT; 021C8828 reads DISPCNT.
 */
void func_021C87B0(u8 *p, u8 *a1)
{
    Point_021C76F8 pos;
    func_0204B3DC(((struct Obj00179 *)p)->f1A0,1);
    func_0204B878(((struct Obj00179 *)p)->f1A0,1);
    func_0204B9A0(((struct Obj00179 *)p)->f1A0);
    *(int *)&((struct Obj00179 *)p)->f1A8=0;
    func_0204B92C(((struct Obj00179 *)p)->f1A0,1);
    pos.x=d_021CA6C8[*(s16 *)(p + 4)].x * 8;
    pos.y=d_021CA6C8[*(s16 *)(p + 4)].y * 8 - 4;
    func_0204B404(((struct Obj00179 *)p)->f1A0,(const struct Vec2 *)(&pos),0);
    *(volatile u16 *)0x0400004A=(u16)((*(volatile u16 *)0x0400004A & ~0x3F00) | 0x700);
    Outside(31,1);
    *(volatile u32 *)0x04000000=(*(volatile u32 *)0x04000000 & ~0xe000) | 0x8000;
    func_020061E4(0x668);
}





int func_021C8850(u8 *p, u8 *a1) {u32 n;if(func_0204B98C(*(struct Actor * *)&((struct Obj00179 *)p)->f1A0)==0)return 1;n=CLACT_GetActorAnimFrame(*(struct Obj * *)&((struct Obj00179 *)p)->f1A0);if(n-((struct Obj00179 *)p)->f1A8>=2) ((struct Obj00179 *)p)->f1A8=n;return 0;}





/*
 * volatile: display control MMIO 0x04000000 read/write at 021C888A and 021C8892.
 */
void func_021C8880(u8 *p, u8 *unused) {*(volatile u32 *)0x04000000 &= ~0xe000u;func_0204B3DC(*(struct Obj * *)&((struct Obj00179 *)p)->f1A0,0);func_0204B92C(*(struct Obj * *)&((struct Obj00179 *)p)->f1A0,0);}






void func_021C88AC(u16 *d, u16 *unused, u16 *s, u32 unused2, u16 heap)
{
    d[0] = s[0];
    d[1] = s[1];
    d[2] = s[2];
}





/*
 * extent: bx lr followed by two zero alignment bytes.
 */
void func_021C88BC(void *a0, void *a1) {}





void func_021C88C0(s16 *p, void *unused, u8 *q)
{
    int y = p[1];
    int x;
    u16 *t;
    if (y < 0) y = -y;
    x = p[0];
    if (x < 0) x = -x;
    t = *(u16 * *)&((struct Obj23089 *)q)->f8;
    func_02041090((int)2, (u32)((u8 *)t + 12), (u8)x, (u8)y, (t[0] >> 3) & 255, (t[1] >> 3) & 255);
    func_02041B6C(2);
}





void func_021C8904(char *p,char *q,void *r,void *s,int t,char *table,int page,u16 heap) {
 int i;int offset;void *base;int found;char *row;void *v;
 base=(void *)func_0201283C(((struct Obj23090 *)q)->f4);
 v=func_02045770(**(void ** *)&((struct Obj05381 *)p)->f8);
 found=0;
 func_02043B5C(v,0);
 func_021C8A50(p,(int)r);
 offset=page*8;i=0;row=table+offset;
 for(;i<8;i++) {
  if(((struct Obj23091 *)table)->f0 > offset+i) {
   func_021C8A80((u8 *)p,s,r,t,i,base,(u8)row[i+8],heap);found=1;
  } else func_021C8B90(p,r,t,i,heap);
 }
 if(!found)func_02045334(**(void ** *)&((struct Obj05381 *)p)->f8);
}





void func_021C899C(char *p,char *q,void *r,void *s,int t,char *table,int page,u16 heap) {func_021C8904(p,q,r,s,t,table,page,heap);func_021CA4B4(**(char ** *)&((struct Obj05381 *)p)->f8);}





static inline int ab(int v) {return v<0?-v:v;}





/*
 * extent: trailing two-byte zero padding at 0x021C8A4E; next label 0x021C8A50.
 */
void func_021C89C4(char *p, void *q, void *a2) {
 void *v;
 func_021C8A50(p,(int)q);
 v=**(void ** *)&((struct Obj03282 *)p)->f8;func_020456F8(v);func_02041B6C(func_02045730(v));
 func_02041300(2,0,ab(((struct Obj03282 *)p)->f0),ab(((struct Obj03282 *)p)->f2),p[4],p[5],0);
 func_02041B6C(2);
 func_02041300(3,0,ab(((struct Obj03282 *)p)->f0),ab(((struct Obj03282 *)p)->f2),p[4],p[5],0);
 func_02041B6C(3);
}





void func_021C8A50(char *p,int unused) {int i;char *q;for(i=0;i<8;i++) {q=p+i*4;if(((struct Obj05380 *)q)->fC){func_021C41BC(((struct Obj05380 *)q)->fC);*(u32 *)&((struct Obj05380 *)q)->fC=0;} if(((struct Obj05380 *)q)->f2C){func_0204B3B4(((struct Obj05380 *)q)->f2C);*(u32 *)&((struct Obj05380 *)q)->f2C=0;}}}



/*
 * lever: The colors and four-halfword position descriptor are fields of
 * one stack aggregate, fixing their 0x28 and 0x2E frame positions.
 * bounds: 02009864 field 9 reads the two-bit value at entry+0x2f,
 * so 3 also reads the initialized position halfword at aggregate+6.
 * heap: 021C8644 and 021C89B0 load the incoming heap as a halfword;
 * 021C8904 forwards that value to this eighth argument at 021C896A.
 */
void func_021C8A80(u8 *p, void *a, u8 *b, int unused, int i, void *base, int idx, u16 heap)
{
    struct { u16 colors[3]; s16 pos[4]; } local;
    int result8, result9;
    void *str;
    local.colors[0] = 0x14c0;
    local.colors[1] = 0xc80;
    local.colors[2] = 0x440;
    result8 = func_02009864(base, idx, 8);
    result9 = func_02009864(base, idx, 9);
    if (result9 == 2) {
        func_021C8B90((char *)p, (char *)b, unused, i, heap);
    } else {
        local.pos[0] = (((struct Obj05381 *)p)->f0 + d_021CA6C8[i].x) * 8 + 8;
        local.pos[1] = (((struct Obj05381 *)p)->f2 + d_021CA6C8[i].y) * 8 + 10;
        local.pos[2] = 8;
        local.pos[3] = 1;
        *(void **)(p + 12 + (int)((u32)i * 4u)) = func_021C40BC(a, local.pos, result8, heap);
        func_021C42A8(*(void **)(p + 12 + (int)((u32)i * 4u)), 0, 1);
    }
    str = func_020457B0(128, heap);
    func_02045924(str, (const u16 *)func_020099D4(base, idx));
    func_021B6AE4(*(u8 * *)&((struct Obj05381 *)p)->f8, (void *)(((struct Obj05382 *)b)->f34), d_021CA6C8[i].x * 8,
                 d_021CA6C8[i].y * 8 - 24, (u32)str, ((struct Obj05382 *)b)->f17C, *(u16 *)((u8 *)&local + result9 * 2), 0);
    func_02045808(str);
}


void func_021C8B90(char *p,char *q,int unused,int i,u16 h) {
 Point pt;
 pt.x=(((struct Obj14043 *)p)->f0+d_021CA6C8[i].x)*8+16;
 pt.y=(((struct Obj14043 *)p)->f2+d_021CA6C8[i].y)*8+16;
 pt.z=0;pt.a=8;pt.b=1;
 *(void **)(p+44+i*4)=func_0204B294((u32)((struct Obj05382 *)q)->f13C,((struct Obj05382 *)q)->f144,((struct Obj05382 *)q)->f14C,((struct Obj05382 *)q)->f154,&pt,0,h);
}


/*
 * interface: 02031324 forwards heap to 02031354 and returns its node;
 * 02031348 forwards all four inputs to 020314F4 despite legacy void(void).
 * data: Process setup loads ov194/ov129 and receives their callback tables.
 */
int func_021C8C04(void **p, u8 *a, u8 *b, void *unused, u16 heap)
{
    u32 sizes[3];
    switch (b[8]) {
    case 0:
        func_02034A5C((u32)id67);
        p[1] = func_021C8DA0(p, (char *)b, 1, heap);
        sizes[0] = 4; sizes[1] = 4; sizes[2] = 4;
        p[2] = CODEIN_PARAM_Create(heap, 0, 0, 12, sizes);
        func_021C6390(a);
        p[0] = PROCSYS_Create(heap);
        PROCSYS_Push(p[0], (u32)id194, d_021F5580, p[1]);
        b[8] = 1;
        break;
    case 1:
        if (PROCSYS_Main(p[0]) == 0) {
            if (((struct Obj23097 *)((u8 *)p[1]))->f1C == 0) {
                PROCSYS_Push(p[0], (u32)id129, d_021DA62C, p[2]);
                b[8] = 2;
            } else {
                func_0203133C(p[0]);
                func_021C6438(b, 0, 0);
                b[8] = 3;
            }
        }
        break;
    case 2:
        if (PROCSYS_Main(p[0]) == 0) {
            func_0203133C(p[0]);
            func_021C6440(b, ((struct Obj23098 *)((u8 *)p[1]))->f20, ((struct Obj23099 *)((u8 *)p[2]))->f20);
            func_021C6438(b, 0, 7);
            b[8] = 3;
        }
        break;
    case 3:
        func_0216C0C0((int)p[1]);
        func_0202E54C(p[2]);
        func_02034AC4((u32)id67);
        func_021C6360((char *)a, heap);
        return 1;
    case 4:
        func_02034A5C((u32)id67);
        p[1] = func_021C8DA0(p, (char *)b, 0, heap);
        func_021C6390(a);
        p[0] = PROCSYS_Create(heap);
        PROCSYS_Push(p[0], (u32)id194, d_021F5580, p[1]);
        b[8] = 5;
        break;
    case 5:
        if (PROCSYS_Main(p[0]) == 0) {
            func_0203133C(p[0]);
            *(int *)b = func_020355C4();
            if (((struct Obj23100 *)((u8 *)p[1]))->f1C == 0) {
                func_021C6438(b, 1, 14);
                func_021C6440(b, ((struct Obj23101 *)((u8 *)p[1]))->f20, 0);
                b[8] = 6;
            } else {
                func_021C6438(b, 1, 15);
                b[8] = 6;
            }
        }
        break;
    case 6:
        func_0216C0C0((int)p[1]);
        func_02034AC4((u32)id67);
        func_021C6360((char *)a, heap);
        return 1;
    }
    return 0;
}
