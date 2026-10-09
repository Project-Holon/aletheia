/*
 * file:     unit_02183B60.c
 * unit:     yes
 * function: func_02183B60, func_02183C78, func_02183CBC, func_02183CEC, func_02183D14, func_02184470, func_021844E4, func_02184558, func_021845A4, func_021845B4, func_021846B8, func_02184734, func_02184790, func_02184798, func_021848F4, func_02184968, func_021849A4, func_02184BAC, func_02184C2C, func_02184C8C, func_02184CB0, func_02184D30, func_02184D70, func_02184EAC, func_02184EC0, func_02184FC8, func_02185074, func_021850EC, func_0218516C, func_0218519C, func_02185254, func_02185310, func_0218532C, func_0218544C, func_02185580, func_0218562C, func_021856CC, func_02185728, func_02185794, func_02185824, func_02185848, func_021858BC, func_02185934, func_02185AC8, func_02185B74, func_02185C84
 * address:  0x02183B60
 * region:   ov219
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
 *   func_02012EBC 0x02012EBC thumb
 *   func_02012944 0x02012944 thumb
 *   func_02009470 0x02009470 thumb
 *   d_0209DF0C 0x0209DF0C data a1
 *   func_0200856C 0x0200856C thumb
 *   func_02008570 0x02008570 thumb
 *   func_02009524 0x02009524 thumb
 *   func_0201EC74 0x0201EC74 thumb
 *   func_0204363C 0x0204363C arm
 *   func_0203101C 0x0203101C arm
 *   func_02028590 0x02028590 thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_0203D34C 0x0203D34C arm
 *   func_02043598 0x02043598 arm
 *   func_020310C4 0x020310C4 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_02028218 0x02028218 thumb
 *   func_0202822C 0x0202822C thumb
 *   func_02028178 0x02028178 thumb
 *   func_020362DC 0x020362DC arm
 *   func_0203630C 0x0203630C arm
 *   func_02035BA4 0x02035BA4 arm
 *   func_02035CB8 0x02035CB8 arm
 *   func_02035C60 0x02035C60 arm
 *   func_02035D20 0x02035D20 arm
 *   func_02045B38 0x02045B38 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049238 0x02049238 arm
 *   func_02040588 0x02040588 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045770 0x02045770 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0202208C 0x0202208C thumb
 *   func_020221A4 0x020221A4 thumb
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_020200CC 0x020200CC thumb
 *   func_0201FDA0 0x0201FDA0 thumb
 *   func_0201FEBC 0x0201FEBC thumb
 *   func_02025BE8 0x02025BE8 thumb
 *   func_02025C44 0x02025C44 thumb
 *   func_02025B94 0x02025B94 thumb
 *   func_0200947C 0x0200947C thumb
 *   func_02027120 0x02027120 thumb
 *   func_02028230 0x02028230 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_02185CF4 0x02185CF4 thumb ov219
 *   d_02185DE6 0x02185DE6 data a1
 *   d_02185DB6 0x02185DB6 data ov219 a1
 *   d_02185E98 0x02185E98 data ov219 a4
 *   d_02185E28 0x02185E28 data ov219 a4
 *   d_02185DB0 0x02185DB0 data ov219 a1
 *   d_02185DC4 0x02185DC4 data ov219 a1
 *   d_02185ECC 0x02185ECC data ov219 a4
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_02028604 0x02028604 thumb
 *   func_02031140 0x02031140 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_0208068C 0x0208068C arm
 *   func_02082AC0 0x02082AC0 arm
 *   func_02080B98 0x02080B98 arm
 *   func_020433E0 0x020433E0 arm
 *   d_02185F4C 0x02185F4C data ov219 a4
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_02046440 0x02046440 arm
 *   func_0204044C 0x0204044C arm
 *   func_02045088 0x02045088 arm
 *   func_0204361C 0x0204361C arm
 *   d_02185F18 0x02185F18 data ov219 a4
 *   func_020450C8  0x020450C8  arm
 *   func_02046788  0x02046788  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_0204A39C 0x0204A39C arm
 *   _u32_div_f 0x0209C2B0 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02025B38 0x02025B38 thumb
 *   func_02025BD0 0x02025BD0 thumb
 *   func_02025BB8 0x02025BB8 thumb
 *   d_02185F28 0x02185F28 data a4
 *   func_0200949C 0x0200949C thumb
 *   func_02025B3C 0x02025B3C thumb
 *   d_02185E00 0x02185E00 data a4
 *   func_02035C08 0x02035C08 arm
 *   sub_020450F0 0x020450F0 arm
 *   sub_02045770 0x02045770 arm
 *   sub_02043B5C 0x02043B5C arm
 *   sub_02045374 0x02045374 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201DE00 0x0201DE00 thumb
 *   func_0201DD78 0x0201DD78 thumb
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_02049658 0x02049658 arm
 *   func_02049B68 0x02049B68 arm
 *   func_020498F4 0x020498F4 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_02049B40 0x02049B40 arm
 *   func_02040B94 0x02040B94 arm
 *   func_02040EBC 0x02040EBC arm
 *   func_0201F73C 0x0201F73C thumb
 *   d_02185E58 0x02185E58 data a4
 *   d_02185E78 0x02185E78 data a4
 *   d_02185DBD 0x02185DBD data a1
 *   func_02045EC0 0x02045EC0 arm
 *   func_02027F60 0x02027F60 thumb
 *   func_02027FEC 0x02027FEC thumb
 *   d_02185E40 0x02185E40 data ov219 a4
 *   func_02028148 0x02028148 thumb
 *   sub_02041B6C 0x02041B6C arm
 *   func_02027FD8 0x02027FD8 thumb
 *   func_02045808 0x02045808 arm
 *   func_020452E8 0x020452E8 arm
 *   func_020403F4 0x020403F4 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_0201C6FC 0x0201C6FC thumb
 *   func_020457B0 0x020457B0 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_0201CE30 0x0201CE30 thumb
 *   func_020286C4 0x020286C4 thumb
 *   func_0201CE5C 0x0201CE5C thumb
 *   func_0201CE38 0x0201CE38 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_0201F81C 0x0201F81C thumb
 *   func_0201F878 0x0201F878 thumb
 *   func_0201DC80 0x0201DC80 thumb
 *   func_0201FF30 0x0201FF30 thumb
 *   func_02020CF8 0x02020CF8 thumb
 *   d_02185F7C 0x02185F7C data a4
 *   func_0201F7A8 0x0201F7A8 thumb
 *   sub_020452E8 0x020452E8 arm
 *   func_0202020C 0x0202020C thumb
 *   func_0201F868 0x0201F868 thumb
 *   func_0201F048 0x0201F048 thumb
 *   func_0201F094 0x0201F094 thumb
 *   func_0201F250 0x0201F250 thumb
 *   d_02185DCB 0x02185DCB data ov219 a1
 *   func_02045374 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02045730 0x02045730 arm
 *   func_02185D08  0x02185D08  thumb  ov219
 *   func_02185D64  0x02185D64  thumb  ov219
 *   func_02046DB8 0x02046DB8 arm
 *   func_02046FF8 0x02046FF8 arm
 *   func_02047400 0x02047400 arm
 *   func_0204767C 0x0204767C arm
 *   d_02185E18 0x02185E18 data a2
 *   func_02048AC4 0x02048AC4 arm
 *   func_02048C4C 0x02048C4C arm
 *   func_02047738 0x02047738 arm
 *   func_02047504 0x02047504 arm
 *   func_020470D0 0x020470D0 arm
 *   func_02046EFC 0x02046EFC arm
 *   func_02048A24 0x02048A24 arm
 *   func_02048AD0 0x02048AD0 arm
 *   d_02185F00 0x02185F00 data a4
 *   d_02185E0C 0x02185E0C data a4
 *   d_02185DF4 0x02185DF4 data a4
 *   d_020A1EB8 0x020A1EB8 data a4
 *   func_02048AFC 0x02048AFC arm
 *   func_02048B44 0x02048B44 arm
 *   func_02048B80 0x02048B80 arm
 *   func_02048B94 0x02048B94 arm
 *   func_02048B60 0x02048B60 arm
 *   func_02048B6C 0x02048B6C arm
 *   d_020A1C78 0x020A1C78 data
 *   func_02048BC4 0x02048BC4 arm
 *   func_02048C58 0x02048C58 arm
 *   d_02185DD4    0x02185DD4 data ov219
 *   func_0207AF1C 0x0207AF1C thumb
 *   func_0207AF00 0x0207AF00 thumb
 *   func_0207AF38 0x0207AF38 thumb
 *   func_0207B388 0x0207B388 arm
 *   d_020A1B38 0x020A1B38 data a2
 *   func_02048AE8 0x02048AE8 arm
 *   func_02048B30 0x02048B30 arm
 *   func_0207CA00 0x0207CA00 arm
 *   func_0207CBD0 0x0207CBD0 arm
 *   func_0207CCA4 0x0207CCA4 arm
 *   func_0207CEE4 0x0207CEE4 arm
 *   func_02047964  0x02047964  arm
 *   func_02047970  0x02047970  arm
 *   func_020479D8  0x020479D8  arm
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_02047A60  0x02047A60  arm
 *   func_02025BA0 0x02025BA0 thumb
 */
#include "../../matched/include/Obj10973.h"
#include "../../matched/include/Obj14775.h"
#include "../../matched/include/Obj08450.h"
#include "../../matched/include/Obj05564.h"
#include "../../matched/include/Obj00302.h"
#include "../../matched/include/Obj01012.h"
#include "../../matched/include/Obj01439.h"
#include "../../matched/include/Obj14776.h"
#include "../../matched/include/Obj02933.h"
#include "../../matched/include/Obj02934.h"
#include "../../matched/include/Obj00927.h"
#include "../../matched/include/Obj14777.h"
#include "../../matched/include/Obj01013.h"
#include "../../matched/include/Obj08451.h"
#include "../../matched/include/Obj01984.h"
#include "../../matched/include/Obj14780.h"
#include "../../matched/include/Obj04645.h"
#include "../../matched/include/Obj04646.h"
#include "../../matched/include/Obj10975.h"
#include "../../matched/include/G_02185E0C.h"
#include "../../matched/include/G_Vec3.h"
#include "../../matched/include/Obj10976.h"
#include "../../matched/include/Obj02935.h"

#define H(o) (*(u16 *)(p + (o)))
#define B(o) (*(u8 *)(p + (o)))
struct Big;
struct Sub0200852CObj;
struct Sub02009470Obj;
struct Tcbl;
struct Obj0203159C;
struct WordSet;
struct PrintSys;
struct Obj;
struct Src_02183B60;
struct Descriptor;
struct CharBuf;
struct MsgBank;
struct Rec;
struct S02031140;
struct S020315D4;
struct Cfg;
struct BgTemplate;
struct GfFont;
struct R;
struct TaskMenuState;
struct U16Vec;
struct Ctx;
struct Rec3;
struct Font;
struct Slot;
struct Record;
struct Tagged;
struct Light;
struct LightSet;
struct LightSlot;
struct Arg;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef signed int     s32;

typedef enum {GX_VRAM_NONE=0} GXVRam;

typedef enum {GX_OBJVRAMMODE_CHAR_2D=0,GX_OBJVRAMMODE_CHAR_1D_32K=0x10,GX_OBJVRAMMODE_CHAR_1D_64K=0x100010,GX_OBJVRAMMODE_CHAR_1D_128K=0x200010,GX_OBJVRAMMODE_CHAR_1D_256K=0x300010} GXOBJVRamModeChar;

struct DispVram {GXVRam main_bg,main_bg_expltt,sub_bg,sub_bg_expltt,main_obj,main_obj_expltt,sub_obj,sub_obj_expltt,teximage,texpltt;GXOBJVRamModeChar main_mapping,sub_mapping;};

struct DispConfig {unsigned a,b,c,d;};

typedef struct {int words[9];} Matrix;

typedef struct {short x,y;Matrix matrix;u16 state,a,b,pad;} Record;

typedef struct {int words[6];Record records[];} State_02183B60;


typedef struct {unsigned heap;void *ctx,*save,*field,*data;unsigned count;Record records[];} Records;

typedef struct {unsigned heap;void *ctx,*save,*field,*data;unsigned count;char pad[0xc2dc];int x,y;char pad2[0x40];unsigned a,b;} State_02184734;

struct Entry_02183B60 {unsigned x,y,z;};

struct Record {struct Descriptor *descriptor;u8 active;};

struct Src_02183B60 {u32 w[13];};

typedef struct {u32 bank,id;} Entry_02183B60;

struct Src_02184FC8 {unsigned w[13];};

typedef struct {const void *str;unsigned param;} BmpMenuWork;

typedef short s16;

typedef struct {u16 index,member;} Entry_02185580;

typedef struct {unsigned x,y,z;} Vec3_02185728;

typedef struct {Vec3_02185728 vec;short x,y;} Config;


typedef struct {char pad[0x30]; short a, b;} Cfg;


typedef struct {long x,y,z;} Vec;

typedef struct { int x, y, z; } V3;

typedef struct { V3 a; V3 b; } Pair;

typedef struct { int m[9]; } M33;

extern void func_0203064C(u32 a, u32 b, u32 c);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,u32,u32);
extern void *func_02012EBC(struct Big *p);
extern u8 *func_02012944(void *p);
extern struct Sub02009470Obj *func_02009470(void *sys);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern u8 func_02009524(const struct Sub02009470Obj *obj);
extern struct WordSet *func_0201EC74(u32 n, u32 size, u16 heap);
extern void func_0204363C(u32);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 func_02028590(u32,u32,u32,u16);
extern u32 func_0201C440(void *);
extern void func_0203D34C(u32 a, u32 b);
extern void func_02043598(u32,u32);
extern void func_020310C4(struct Tcbl *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_02028218(struct Obj*,u32);
extern void func_0202822C(char*,int);
extern void func_02028178(u8*);
extern u32 func_020362DC(void);
extern u32 func_0203630C(void);
extern int func_02035BA4(const void *a);
extern u32 func_02035CB8(u32 *outA, u32 *outB);
extern int func_02035C60(void);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u16 fileId, u16 heapId);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049238(void *);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02043B5C(struct CharBuf *, u8);
extern void func_02045334(struct Descriptor *);
extern void *func_02045770(struct Descriptor *);
extern u32 func_02045C04(struct Rec *rec);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 func_020221A4(void);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern s32 func_020200CC(struct Obj *o);
extern void *func_0201FDA0(const void *a, int b, int c, int d, u16 heap);
extern u32 func_0201FEBC(u8 *p);
extern int func_02025BE8(void);
extern int func_02025C44(u32 a0, u32 *a1, u32 *a2);
extern u32 func_02025B94(u32 a);
extern void func_0200947C(u32 a, u32 b, u32 c, u32 d);
extern void func_02027120(u8 a, u8 b);
extern u32 func_02028230(u8 *p);
extern void func_020061E4(u32 a);
extern int func_02185CF4(int i);
extern void func_0201C6EC(struct PrintSys *),func_0201C4C0(struct PrintSys *);
extern int func_02028604(int);
extern void func_02031140(struct S02031140 *);
extern unsigned func_0201ED04(struct WordSet *);
extern void func_021845A4(int),func_020315D4(struct S020315D4 *),func_020306F0(unsigned int);
extern void func_0208068C(unsigned),func_02082AC0(unsigned,void *,unsigned),func_02080B98(void);
extern void func_020433E0(const struct DispVram *);
extern void func_0203F8F4(unsigned),func_0203FC28(struct DispConfig *);
extern void func_02046440(unsigned,unsigned,unsigned,unsigned,u16,unsigned,void (*)(void));
extern void func_0204044C(unsigned),func_02045088(unsigned),func_0204361C(void);
extern int func_020450C8(int);
extern int func_02046788(int);
extern int func_0203F9B4(int);
extern void *func_0204A39C(void *,int,int,u32,u32 *);
extern u32 func_020307B0(void *p);
extern int func_02025B38(void);
extern u32 func_02025BD0(u32),func_02025BB8(u32);
extern u32 func_0200949C(const struct Sub02009470Obj *obj, int row, int col);
extern u32 func_02025B3C(u32);
extern int func_02035C08(const void *);
extern u32 sub_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern void *sub_02045770(struct Descriptor*);
extern void sub_02043B5C(struct CharBuf*,u8);
extern void sub_02045374(struct Cfg*);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern void func_0201DE00(u8 *,u8 *,u8 *),func_0201DD78(u32,u32,u32);
extern void func_0203FCA0(u32,const struct BgTemplate *,u32),func_020414EC(u32);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern void func_020498F4(void *,u32,u32,u32,u32,u32,u16);
extern void func_0201F5BC(u32,u32,u32,u32,u16);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern void func_02040EBC(u32,u32);
extern void *func_02045EC0(struct MsgBank *,unsigned);
extern struct R *func_02027F60(u16,u16,unsigned,unsigned,u16);
extern unsigned func_02027FEC(unsigned,unsigned,unsigned,unsigned,u8,u16);
extern void func_02028148(u8*);
extern void sub_02041B6C(u32);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern void func_02045808(struct U16Vec *);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_020403F4(unsigned);
extern u32 func_0201D83C(void *ptr);
extern void func_0201C6FC(struct PrintSys *,unsigned,unsigned,unsigned,void *,unsigned);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *,u32,void *);
extern signed char func_02012FFC(void);
extern u32 func_0201CCE4(u32,u32,u32,u32,u32,u32,u32,u32,u16,u16);
extern u32 func_0201CE30(void *);
extern void func_020286C4(struct Ctx *,void *,void *);
extern void func_0201CE5C(struct Rec *,int);
extern void func_0201CE38(void *);
extern void func_0201CE48(struct Rec3 *);
extern void *func_0201F81C(u32,u32);
extern void func_0201F878(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern u32 func_0201DC80(struct Font *);
extern struct Obj *func_0201FF30(struct Src_02183B60 *src, u16 a, u16 b, u32 heap);
extern void func_02020CF8(struct Obj *,int);
extern void func_0201F73C(void *,int,int,int);
extern void func_0201F7A8(void*,u32);
extern u32 sub_020452E8(struct Descriptor *d);
extern void func_0202020C(struct Obj*,u16*,u16*);
extern u32 func_0201F868(void *p);
extern void func_0201F048(struct WordSet *,unsigned,unsigned),func_0201F094(struct WordSet *,unsigned,unsigned,unsigned);
extern void func_02045CAC(struct MsgBank *,unsigned,void *),func_0201F250(struct WordSet *,void *,void *);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(unsigned);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02185D08(int *p);
extern int func_02185D64(int *p, int *q);
extern void *func_02046DB8(unsigned,unsigned),*func_02047400(void *,unsigned,void *),*func_0204767C(unsigned,unsigned *,int);
extern int func_02046FF8(int *);
extern u32 func_02048AC4(void *ptr);
extern void func_02048C4C(void *);
extern void func_02047738(struct Rec *p);
extern void func_02047504(struct Rec *p);
extern int func_020470D0(u32 *);
extern void func_02046EFC(struct Tagged *p);
extern void *func_02048A24(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,Vec3_02185728 *,Vec3_02185728 *,Vec3_02185728 *,u16);
extern void func_02048AD0(struct Light *l);
extern void func_02048AFC(void *, Vec3_02185728 *);
extern void func_02048B44(void *, Vec3_02185728 *);
extern void func_02048B80(struct Light *l, u32 v);
extern void func_02048B94(struct Light *l, u32 v);
extern void func_02048B60(struct Light *l, const u32 *in);
extern void func_02048B6C(struct Light *l, const u32 *in);
extern struct LightSlot *func_02048BC4(const struct LightSet *s, u32 heap);
extern void func_02048C58(struct LightSlot *slots);
extern void func_0207AF1C(Matrix *,int,int),func_0207AF00(Matrix *,int,int),func_0207AF38(Matrix *,int,int);
extern void func_0207B388(const Matrix *,const Matrix *,Matrix *);
extern void func_0207CA00(const Vec *,const Vec *,Vec *),func_0207CCA4(const Vec *,Vec *),func_0207CEE4(long,const Vec *,const Vec *,Vec *);
extern long func_0207CBD0(const Vec *);
extern void func_02047964(void);
extern void func_02047970(void);
extern void func_020479D8(void);
extern void func_0207ADC4(M33 *);
extern void func_02047A60(void *a0, struct Arg *a1);
extern unsigned func_02184790(unsigned),func_02025BA0(unsigned);
int func_02183B60(void *obj,void *unused,void *ctx);
int func_02183C78(void *unused, char *state, int unused2, char *ctx);
void func_02183CBC(u8 *p,u32 i);
void func_02183CEC(u8 *p);
int func_02183D14(u8 *p, int *state);
int func_02184470(struct S020315D4 *controller,void *unused1,void *unused2,char *p);
void func_021844E4(void);
void func_02184558(unsigned heap);
void func_021845A4(int a);
void func_021845B4(char *p);
void func_021846B8(State_02183B60 *p,int index,int x,int y,u16 a,u16 b);
void func_02184734(State_02184734 *p);
u32 func_02184790(u32 key);
void func_02184798(char *p);
void func_021848F4(const char *p,int x,int y,int *xflag,int *xdistance,int *yflag,int *ydistance);
u32 func_02184968(const u8 *p,int flag);
void func_021849A4(char *p,void *arc);
void func_02184BAC(char *p);
void func_02184C2C(char *p,int i);
void func_02184C8C(u8 *p,u32 i);
void func_02184CB0(char *p);
void func_02184D30(char *p,struct Record *out,struct Descriptor *d,void *text,u8 x,u8 y);
int func_02184D70(char *p,u32 message,int force);
void func_02184EAC(int a, int b, int c);
void func_02184EC0(char *p,const unsigned char *descriptor,const struct Src_02183B60 *source,const Entry_02183B60 *entries);
void func_02184FC8(char *p,const struct Src_02184FC8 *source,unsigned count);
void func_02185074(u8 *p, const u8 *a, u32 b, u32 c);
void func_021850EC(char *p,const unsigned char *descriptor,const struct Src_02184FC8 *cfg,unsigned file,const unsigned char *ids,unsigned count);
void func_0218516C(u8*p);
void func_0218519C(char *p);
void func_02185254(char *p,unsigned key,unsigned member);
void func_02185310(char *p);
int func_0218532C(char *p, u32 *out);
void func_0218544C(char *p);
void func_02185580(char *p, void *arc);
void func_0218562C(char *p);
void func_021856CC(u8 *p);
void func_02185728(char *p);
void func_02185794(char *p);
void func_02185824(char *p);
void func_02185848(Matrix *p,int *angles);
void func_021858BC(Matrix *p,int *angles);
int func_02185934(u8 *p, u32 a, u32 b);
int func_02185AC8(char *p);
void func_02185B74(char *p);
int func_02185C84(unsigned key,unsigned optional,void *first,void *second,unsigned heap);
extern const u8 d_0209DF0C;
extern const u8 d_02185DE6[];
extern const u8 d_02185DB6[];
extern const struct Src_02183B60 d_02185E98;
extern const u8 d_02185E28[];
extern const u8 d_02185DB0[];
extern const u8 d_02185DC4[];
extern const u8 d_02185ECC[];
extern const struct DispVram d_02185F4C;
extern const struct DispConfig d_02185F18;
extern const Matrix d_02185F28;
extern const char d_02185E00[];
extern const struct BgTemplate d_02185E58,d_02185E78;
extern const u8 d_02185DBD[];
extern const struct Entry_02183B60 d_02185E40[];
extern const u32 d_02185F7C[];
extern const unsigned char d_02185DCB[];
extern const Entry_02185580 d_02185E18[];
extern struct G_02185E0C d_02185E0C;
extern struct Vec3_02185728 d_02185DF4;
extern Vec3_02185728 d_02185F00;
extern Config d_020A1EB8;
extern Cfg d_020A1C78;
extern char d_02185DD4[];
extern short d_020A1B38[];


#define W(o) (*(u32 *)(p + (o)))












int func_02183B60(void *obj,void *unused,void *ctx)
{
    char *p;
    func_0203064C((u32)((void *)1),0x7c,0x80000);
    p=func_0203159C(obj,0xc3bc,0x7c);
    func_02082BCC(p,0,0xc3bc);
    *(u32 *)p=0x7c;
    *(void **)(p+4)=ctx;
    *(void **)(p+8)=func_02012EBC(ctx);
    *(void **)(p+0xc)=func_02012944(*(void **)(p+4));
    *(void **)(p+0x10)=func_02009470(*(void **)(p+8));
    if(d_0209DF0C==1)*(u32 *)(p+0xc318)=1;
    else *(u32 *)(p+0xc318)=0;
    *(u32 *)(p+0xc33c)=func_0200856C(*(void **)(p+0xc));
    *(u32 *)(p+0xc340)=func_02008570(*(void **)(p+0xc));
    *(u32 *)(p+0xc34c)=func_02009524(*(void **)(p+0x10));
    *(u32 *)(p+0xc05c)=0;
    *(u32 *)(p+0xc060)=0;
    func_021844E4();
    func_02184558((u16)(*(u32 *)p));
    *(void **)(p+0xc0a8)=func_0201EC74(8,0x40,*(u32 *)p);
    *(u32 *)(p+0xc310)=0;
    func_0204363C(0);
    *(void **)(p+0xc0a4)=func_0203101C((u16)(*(u32 *)p),*(u32 *)p,0x20,0x20);
    *(u32 *)(p+0xc088)=func_02028590(0xf,1,0,*(u32 *)p);
    *(u32 *)(p+0xc080)=func_0201C440((void *)(u16)*(u32 *)p);
    func_0203D34C(1,(u16)(*(u32 *)p));
    func_02043598(0x10,1);
    func_021845B4(p);
    return 1;
}












int func_02183C78(void *unused, char *state, int unused2, char *ctx)
{
    int result;
    func_020310C4(((struct Obj10973 *)ctx)->fC0A4);
    result = func_02183D14((u8 *)ctx, (int *)state);
    if (((struct Obj10973 *)ctx)->fC3A4 != 0)
        func_02185B74(ctx);
    func_02183CEC((u8 *)ctx);
    func_0201C4E4(((struct Obj10973 *)ctx)->fC080);
    return result;
}












void func_02183CBC(u8 *p,u32 i){if(*(void**)(p+i*4+0xc05c)){if(i==0){func_02028218(*(struct Obj* *)&((struct Obj14775 *)p)->fC05C,1);return;}if(i==1)func_0202822C(*(char* *)&((struct Obj14775 *)p)->fC060,1);}}












void func_02183CEC(u8 *p){if(*(u8* *)&((struct Obj08450 *)p)->fC05C)func_02028178(*(u8* *)&((struct Obj08450 *)p)->fC05C);if(*(u8* *)&((struct Obj08450 *)p)->fC060)func_02028178(*(u8* *)&((struct Obj08450 *)p)->fC060);}













static inline void close_win(u8 *p, int d, int f)
{
    void *win = *(void **)(p + 0xC080);
    if (B(f) != 0 && (int)func_0201C6C4(win, func_02045770(*(struct Descriptor **)(p + d))) == 0) {
        func_02045334(*(struct Descriptor **)(p + d));
        B(f) = 0;
    }
}













/*
 * note:     2026-10-04 wave D3 lane 04: complete draft, same size (1884 bytes). The
 *           remaining residue is cross-jump (tail merge) direction only. In the original
 *           every "*state = X; SE(0x54C); break" tail (case 4 arms, case 9, case 17) jumps
 *           into the case 12 copy at 0x218400C, and the 0x551 tails jump into the case 9
 *           copy at 0x2183F8E. Natural C keeps the FIRST copy (case 4) instead. The draft
 *           uses gotos (n = X; goto snd54c / snd551) in case 4, which fixes case 4, but the
 *           case 9 0x54C tail still stays a full copy (case 12 then jumps to it); a goto in
 *           case 9 too lets the compiler thread the 0xA arm past the hop at 0x2183F8A.
 *           Tried: inner switch arm orders (case 0/default first, last, split), case 9 with
 *           SE in each arm, reversed outer case order (layout follows source, worse).
 *           Found and fixed: switch value u32 (compare tree, 0xFFFFFFFE case), switch on
 *           func_0201FEBC result cast to u32 in cases 6 and 15, case 19 written before
 *           case 18 (original block order), stack locals ids, count, tmp, old (int).
 *           d_02185xxx data words are sole references (MATCH at best once bytes agree).
 *           2026-10-05 wave D4 lane 08: still DIFF (84 lines, the draft above is unchanged). The original keeps
 *           ONE copy of `str r0,[r5]; ldr =0x54C; bl SE; b end` in case 12 (0x218400C) and every other 0x54C, 0x551,
 *           0x648, 0x649 tail jumps into it (case 17 to 0x218400E, 0x648/0x649 and case 9's 0x551 to the bl at
 *           0x2184010); case 9's arms join at a hop (0x2183F8A b 0x218400C), so case 9 had its own copy at threading
 *           time and lost it to cross-jumping later. Tried: case 9 arms `*state = X; goto se54c` (per arm, or one goto
 *           after the if) with a label on the SE call in case 12: case 12's label block then merges into case 17's
 *           copy instead (530 lines, worse). The survivor rule seems to drop the multi-predecessor label block.
 *           2026-10-05 wave D5 lane 05: unchanged DIFF (154 bytes, 84 lines). The original keeps case 12's
 *           copy for EVERY shared tail (0x54C store+call, the case 9 0x551 call, case 17), i.e. the LAST copy in
 *           source order, while every form here keeps the first. Tried: case 9 as an inner switch (default
 *           arm, case 0xFFFFFFFE arm): byte-identical output; fully natural C (no gotos): case 4 copies survive
 *           (381 bytes); case 9 arms `*state = X; goto se54c` plus case 17 `goto se54c` with se54c on the SE
 *           call in case 12: case 12 survives for 0x54C but case 9 arms skip the hop and case 12's call merges
 *           into case 9's 0x551 copy (291 bytes); case 9 arms `n = X; goto snd54c`: 6 bytes short (1004).
 *           2026-10-05 wave D6 lane 03: MATCH (0 concrete bytes differ). Two fixes. (1) Logic: the
 *           0x400 branches of case 17 test and set W(0xC350), not W(0xC33C) (the pool word read is
 *           0xC350; the old draft differed by one pool slot only). (2) Tail shape: case 9 sets n in each
 *           arm, then `*state = n; goto se54c;` (one store after the join; cross-jumping later turns
 *           that join into the hop at 0x2183F8A); se54c sits on `m = 0x54C;` in case 12, followed by
 *           a `call:` label on `func_020061E4(m)`; the case 9 0x551 path does `m = 0x551; goto call;`;
 *           case 17 writes `if (W(0xC350) != 1) break; goto se54c;`. The 0x648/0x649 calls then
 *           merge into case 12's call by themselves. d_02185DE6 hint token dropped (contested).
 *           Remaining: three callees with no witness: arm9 func_02025BE8 and func_02027120 and ov219
 *           func_021856CC. This lane filed all three EXACT (src/matched/arm9/func_02025BE8.c,
 *           src/matched/arm9/func_02027120.c, src/matched/ov/ov219_func_021856CC.c); after the
 *           manifest picks them up this should verify EXACT.
 */
int func_02183D14(u8 *p, int *state)
{
    int ret = 0;
    int n;
    u32 m;
    void *arc;
    u32 r;
    u8 *ids;
    u32 count;
    u32 tmp;
    int old;
    u32 v;
    u32 w;

    W(0xC354) = func_020362DC();
    W(0xC358) = func_0203630C();
    if (func_02035BA4(d_02185DE6) != -1) {
        W(0xC360) = (int)func_02035CB8((u32 *)(p + 0xC364), (u32 *)(p + 0xC368));
    } else {
        W(0xC360) = 0;
    }
    if (W(0xC360) == 1) {
        W(0xC35C) = func_02035C60();
    } else {
        W(0xC35C) = (int)func_02035D20((u32 *)(p + 0xC364), (u32 *)(p + 0xC368));
    }
    switch (*state) {
    case 0:
        *(void **)(p + 0xC070) = func_02045B38(0, 2, (u16)0xCF, (u16)W(0));
        arc = func_020490F4(0xC5, (u16)W(0));
        func_02185580((char *)p, arc);
        func_021849A4((char *)p, arc);
        func_02049238(arc);
        W(0xC314) = 0;
        func_0202208C(0, (int)1, (int)1, (int)0, (int)6, (int)1, W(0));
        func_02040588(6, 1);
        func_02040588(2, 1);
        func_02040588(7, 1);
        func_02040588(3, 1);
        *state = 1;
        break;
    case 1:
        if (func_020221A4() == 1) {
            *state = 2;
        }
        break;
    case 2:
        if (func_02184D70((char *)p, 0, 1) == 1) {
            if (W(0xC33C) == 0) {
                *state = 3;
            } else {
                *state = 0x10;
            }
        }
        break;
    case 3:
        if (func_02184D70((char *)p, 1, 1) == 1) {
            func_02184EC0((char *)p, d_02185DB6, (const struct Src_02183B60 *)&d_02185E98, (const Entry_02183B60 *)d_02185E28);
            *state = 4;
        }
        break;
    case 4:
        if ((int)func_0201C6B4(*(void **)(p + 0xC080)) == 0) {
            break;
        }
        r = func_020200CC(*(void **)(p + 0xC04C));
        if (r == -1) {
            break;
        }
        func_0218516C(p);
        switch (r) {
        case 0:
        default:
            n = 0x10;
            goto snd54c;
        case 1:
            n = 5;
            goto snd54c;
        case 2:
        case 0xFFFFFFFE:
            n = 0x14;
            goto snd551;
        }
        break;
    case 5:
        if (func_02184D70((char *)p, 2, 1) == 1) {
            *(void **)(p + 0xC054) = func_0201FDA0(d_02185DB0, 0x22, 7, 0, W(0));
            *state = 6;
        }
        break;
    case 6:
        switch ((u32)(int)func_0201FEBC(*(void **)(p + 0xC054))) {
        case 0:
            if (W(0xC318) == 1) {
                *(void **)(p + 0xC344) = (void *)func_02025BE8();
                *state = 0xA;
            } else {
                *state = 7;
            }
            break;
        case 0xFFFFFFFE:
            *state = 3;
            break;
        }
        break;
    case 7:
        W(0xC344) = 0;
        func_02185074(p, d_02185DC4, (u32)d_02185ECC, 0xE7);
        *state = 8;
        break;
    case 8:
        if (func_02184D70((char *)p, 3, 1) == 1) {
            *state = 9;
        }
        break;
    case 9:
        if ((int)func_0201C6B4(*(void **)(p + 0xC080)) == 0) {
            break;
        }
        r = func_020200CC(*(void **)(p + 0xC04C));
        if (r == -1) {
            break;
        }
        func_0218516C(p);
        if (r != -2) {
            W(0xC344) = r;
            if (func_02185CF4(r) == 1) {
                n = 0xA;
            } else {
                W(0xC348) = 0;
                n = 0xD;
            }
            *state = n;
            goto se54c;
        } else {
            n = 3;
        snd551:
            *state = n;
            m = 0x551;
            goto call;
        }
        break;
    case 10:
        W(0xC348) = 0;
        func_02025C44((u32)(*(void **)(p + 0xC344)), (u32 *)(&ids), &count);
        func_021850EC((char *)p, d_02185DC4, (const struct Src_02184FC8 *)((const struct Src_02183B60 *)d_02185ECC), func_02025B94((u32)(*(void **)(p + 0xC344))), ids, count);
        *state = 0xB;
        break;
    case 11:
        if (func_02184D70((char *)p, 4, 1) == 1) {
            *state = 0xC;
        }
        break;
    case 12:
        if ((int)func_0201C6B4(*(void **)(p + 0xC080)) == 0) {
            break;
        }
        r = func_020200CC(*(void **)(p + 0xC04C));
        if (r == -1) {
            break;
        }
        func_0218516C(p);
        if (r != -2) {
            W(0xC348) = r;
            n = 0xD;
        snd54c:
            *state = n;
        se54c:
            m = 0x54C;
        call:
            func_020061E4(m);
        } else {
            func_020061E4(0x551);
            if (W(0xC318) == 1) {
                *state = 3;
            } else {
                *state = 7;
            }
        }
        break;
    case 13:
        func_02185254((char *)p, W(0xC344), W(0xC348));
        *state = 0xE;
        break;
    case 14:
        if (func_02184D70((char *)p, 5, 1) == 1) {
            *(void **)(p + 0xC054) = func_0201FDA0(d_02185DB0, 0x22, 7, 0, W(0));
            *state = 0xF;
        }
        break;
    case 15:
        switch ((u32)(int)func_0201FEBC(*(void **)(p + 0xC054))) {
        case 0:
            func_02185310((char *)p);
            func_0200947C(W(0x10), W(0xC), W(0xC344), W(0xC348));
            func_02027120(W(0xC344), W(0xC348));
            W(0xC33C) = W(0xC344);
            W(0xC340) = W(0xC348);
            *state = 0x10;
            break;
        case 0xFFFFFFFE:
            func_02185310((char *)p);
            *state = 3;
            break;
        }
        break;
    case 16:
        if (W(0xC318) == 1 && W(0xC34C) == 0) {
            H(0xC31C) = 0;
        } else {
            H(0xC31C) = 1;
        }
        func_021856CC(p);
        func_02184734((State_02184734 *)p);
        func_02185794((char *)p);
        func_02043B5C(func_02045770(*(struct Descriptor **)(p + 0xC01C)), 0xF);
        func_02045334(*(struct Descriptor **)(p + 0xC01C));
        func_02184C2C((char *)p, 1);
        if (W(0xC33C) != 0) {
            func_0218519C((char *)p);
        }
        func_0218544C((char *)p);
        W(0xC350) = 0;
        W(0xC310) = 1;
        *state = 0x11;
        break;
    case 17:
        old = H(0xC30C);
        if ((int)func_0201C6B4(*(void **)(p + 0xC080)) == 0) {
            break;
        }
        func_02184798((char *)p);
        if (func_0218532C((char *)p, &tmp)) {
            func_02184C2C((char *)p, 0);
        } else {
            func_02184C8C(p, 0);
        }
        v = W(0xC354);
        if ((v & 2) || ((w = W(0xC320)) & 2)) {
            func_02184C8C(p, 0);
            func_02183CBC(p, 1);
            func_020061E4(0x551);
            func_02043B5C(func_02045770(*(struct Descriptor **)(p + 0xC01C)), 0xF);
            func_02045334(*(struct Descriptor **)(p + 0xC01C));
            *state = 0x13;
            break;
        }
        if (((v & 0x400) || (w & 0x400)) && W(0xC350) == 0) {
            W(0xC350) = 1;
            func_02183CBC(p, 0);
            func_0218544C((char *)p);
            if (W(0xC350) != 1) {
                break;
            }
            goto se54c;
        }
        if (((v & 0x403) || (w & 0x400)) && W(0xC350) == 1) {
            W(0xC350) = 0;
            func_0218544C((char *)p);
            break;
        }
        if (func_02185934(p, v, W(0xC358)) == 1 && W(0xC350) == 1) {
            W(0xC350) = 0;
            func_0218544C((char *)p);
        }
        if (old != H(0xC30C)) {
            *state = 0x12;
            if (H(0xC30C) == 0) {
                func_020061E4(0x649);
            } else {
                func_020061E4(0x648);
            }
        }
        break;
    case 19:
        if ((int)func_02028230(*(void **)(p + 0xC060)) == 0) {
            break;
        }
        if (W(0xC33C) == 0) {
            W(0xC310) = 2;
            *state = 3;
        } else {
            func_02185310((char *)p);
            *state = 0x14;
        }
        func_02184C8C(p, 1);
        break;
    case 18:
        if (func_02185AC8((char *)p) == 1) {
            *state = 0x11;
        }
        break;
    case 20:
        W(0xC314) = 0;
        func_0202208C(0, (int)0, (int)0, (int)0, (int)6, (int)1, W(0));
        *state = 0x15;
        break;
    case 21:
        if (func_020221A4() == 1) {
            ret = 1;
            W(0xC310) = 1;
            func_02184CB0((char *)p);
            func_0218562C((char *)p);
            func_02045C04(*(void **)(p + 0xC070));
            *state = 0;
        }
        break;
    }
    close_win(p, 0xC078, 0xC07C);
    close_win(p, 0xC044, 0xC048);
    close_win(p, 0xC038, 0xC03C);
    close_win(p, 0xC02C, 0xC030);
    close_win(p, 0xC020, 0xC024);
    return ret;
}












int func_02184470(struct S020315D4 *controller,void *unused1,void *unused2,char *p)
{
    unsigned heap=((struct Obj05564 *)p)->f0;
    func_0201C6EC(*(struct PrintSys * *)&((struct Obj05564 *)p)->fC080);
    func_0201C4C0(*(struct PrintSys * *)&((struct Obj05564 *)p)->fC080);
    func_02040588(6,0);func_02040588(2,0);func_02040588(7,0);func_02040588(3,0);
    func_0204363C(1);
    func_02028604(((struct Obj05564 *)p)->fC088);
    func_02031140(*(struct S02031140 * *)&((struct Obj05564 *)p)->fC0A4);
    func_021845A4(func_0201ED04(*(struct WordSet * *)&((struct Obj05564 *)p)->fC0A8));
    func_020315D4(controller);func_020306F0((u16)heap);
    return 1;
}












/*
 * prototype: 82AC0 SDK asm source reads r0 fill/r1 destination/r2 size;
 * preserve all three observed inputs despite legacy asm void(void).
 */
void func_021844E4(void)
{
    struct DispVram cfg=d_02185F4C;
    func_0208068C(0x1ff);
    func_02082AC0(0,(void *)0x06800000,0xa4000);func_02080B98();
    func_02082AC0(0xc0,(void *)0x07000000,0x400);
    func_02082AC0(0,(void *)0x05000000,0x400);
    func_02082AC0(0xc0,(void *)0x07000400,0x400);
    func_02082AC0(0,(void *)0x05000400,0x400);
    func_020433E0(&cfg);
}












/*
 * prototype: heap forwarded full-width without caller truncation to 3F8F4,
 * 46440 and 45088; widen their legacy narrow parameters accordingly.
 */
void func_02184558(unsigned heap)
{
    struct DispConfig cfg=d_02185F18;
    func_0203F8F4(heap);func_0203FC28(&cfg);
    func_02046440(0,3,0,2,0,heap,0);
    func_0204044C(1);func_02045088(heap);func_0204361C();
}











/*
 * Addresses are Black-image addresses.
 */
void func_021845A4(int a)
{
    func_0203F9B4(func_02046788(func_020450C8(a)));
}









/*
 * lever: permuter split-assign(count2) moves the otherwise swapped outer/inner count spill slots; fixed-flag one validates MATCH*258B; trailing2B alignment excluded.
 * blocker C: int func_02025B38(void){return 19;} typedef unsigned int u32; extern const unsigned char d_0209FA34[],d_0209FA35[]; u32 func_02025BB8(u32 i){if(i<19)return d_0209FA34[i*12];return 0;} u32 func_02025BD0(u32 i){if(i<19)return d_0209FA35[i*12];return 18;}
 * note 2026-10-04 (D2): still MATCH*; the three arm9 leaves 02025B38, 02025BB8, 02025BD0 are now filed EXACT in
 *   src/matched/arm9/func_<ADDR>.c (D2 lane 11). Rerun after the integrator regenerates shards: expected EXACT*.
 */
void func_021845B4(char *p)
{
    void *arc,*data,*data2;
    u32 size,size2;
    short *cursor;
    long count2;
    long count;
    int firstcount,i,j;
    arc=func_020490F4(0x35,(u16)(*(u32 *)p));
    *(u32 *)(p+0x14)=0;
    data=func_0204A39C(arc,0x12,0,*(u32 *)p,&size);
    firstcount=size/6u;
    cursor=(short *)((char *)data+6);
    for(i=1;i<firstcount;i++,cursor+=3){
        if(*(u16 *)cursor!=2){
            func_021846B8((State_02183B60 *)p, *(u32 *)(p+0x14), cursor[1], cursor[2], i, 0);
            (*(u32 *)(p+0x14))++;
        }
    }
    func_020307B0(data);
    j=1;
    count=func_02025B38();
    for(;j<count;j++){
        data2=func_0204A39C(arc,func_02025BD0(j),0,*(u32 *)p,&size2);
        count2=size2;
        count2=count2/4u;
        cursor=(short *)((char *)data2+4);
        for(i=1;i<count2;i++,cursor+=2){
            func_021846B8((State_02183B60 *)p, *(u32 *)(p+0x14), cursor[0], cursor[1], func_02025BB8(j), i);
            (*(u32 *)(p+0x14))++;
        }
        func_020307B0(data2);
    }
    func_02049238(arc);
}








/*
 * extent: lead124B followed by separately matched92B func_02184734; no unit, follower has its own shard.
 * lever: typed48-byte record members keep byte offset live rather than caching p+offset as a raw pointer.
 */
void func_021846B8(State_02183B60 *p,int index,int x,int y,u16 a,u16 b)
{
    Matrix matrix=d_02185F28;
    int angles[3];
    p->records[index].x=x;
    p->records[index].y=y;
    angles[0]=x;angles[1]=y;angles[2]=0;
    func_021858BC((Matrix *)&matrix, angles);
    p->records[index].matrix=matrix;
    p->records[index].state=func_0200949C((void *)p->words[4],a,b);
    p->records[index].a=a;
    p->records[index].b=b;
}








/*
 * lever: full context member offsets preserve the c2f4 pool base; a cast Tail pointer instead hoists p+c2f4 and raw scalar offsets pool c33c.
 * extent: unlabelled92-byte follower inside handed021846B8 extent; next labelled stub02184790 excluded.
 */
void func_02184734(State_02184734 *p)
{
    unsigned i;
    for(i=0;i<p->count;i++){
        if(((Records *)p)->records[i].a==p->a && ((Records *)p)->records[i].b==p->b){
            ((Records *)p)->records[i].state=3;
            p->x=((Records *)p)->records[i].x;
            p->y=((Records *)p)->records[i].y;
        }
    }
}








u32 func_02184790(u32 key){return func_02025B3C(key);}








void func_02184798(char *p)
{
    int flag=0;
    int result;
    int xf,dx,yf,dy;
    ((struct Obj00302 *)p)->fC320=0;
    result=func_02035C08(d_02185E00);
    if(result==0)flag=0x400;
    else if(result==1)flag=2;
    if(((struct Obj00302 *)p)->fC35C!=0){
        if(flag!=0){((struct Obj00302 *)p)->fC320=flag;return;}
        ((struct Obj00302 *)p)->fC324=0;
        ((struct Obj00302 *)p)->fC330=0;
        ((struct Obj00302 *)p)->fC334=0;
        ((struct Obj00302 *)p)->fC338=0;
        ((struct Obj00302 *)p)->fC320=0;
        ((struct Obj00302 *)p)->fC328=((struct Obj00302 *)p)->fC364;
        ((struct Obj00302 *)p)->fC32C=((struct Obj00302 *)p)->fC368;
        ((struct Obj00302 *)p)->fC338=4;
    }
    if(((struct Obj00302 *)p)->fC360!=0){
        switch(((struct Obj00302 *)p)->fC324){
        case 0:
            if(((struct Obj00302 *)p)->fC338==0)(((struct Obj00302 *)p)->fC324)++;
            else (((struct Obj00302 *)p)->fC338)--;
        case 1:
            if(flag!=0)return;
            func_021848F4(p,((struct Obj00302 *)p)->fC328,((struct Obj00302 *)p)->fC32C,&xf,&dx,&yf,&dy);
            ((struct Obj00302 *)p)->fC320=xf|yf;
            ((struct Obj00302 *)p)->fC330=dx;
            ((struct Obj00302 *)p)->fC334=dy;
            ((struct Obj00302 *)p)->fC328=((struct Obj00302 *)p)->fC364;
            ((struct Obj00302 *)p)->fC32C=((struct Obj00302 *)p)->fC368;
            return;
        default:return;
        }
    }else{
        if(flag==0 && ((struct Obj00302 *)p)->fC338!=0 && ((struct Obj00302 *)p)->fC330<4 && ((struct Obj00302 *)p)->fC334<4)
            ((struct Obj00302 *)p)->fC320=1;
        ((struct Obj00302 *)p)->fC324=0;
        ((struct Obj00302 *)p)->fC330=0;
        ((struct Obj00302 *)p)->fC334=0;
        ((struct Obj00302 *)p)->fC338=0;
    }
}








/*
 * lever: declare oldx before a named base pointer; this puts oldx in r5
 * and base in r6. Const on the parameter alone left their five-byte swap.
 */
void func_021848F4(const char *p,int x,int y,int *xflag,int *xdistance,int *yflag,int *ydistance)
{
    int oldx;
    const char *base=p;
    int xf=0,yf=0,dx=0,dy=0;
    oldx=((struct Obj00302 *)base)->fC364;
    if(oldx!=0xffff){
        dx=oldx-x;
        if(dx<0){dx^=-1;xf=0x10;}
        else if(dx>0)xf=0x20;
    }
    *xflag=xf;*xdistance=dx&63;
    if(((struct Obj00302 *)base)->fC368!=0xffff){
        dy=((struct Obj00302 *)base)->fC368-y;
        if(dy<0){dy^=-1;yf=0x80;}
        else if(dy>0)yf=0x40;
    }
    *yflag=yf;*ydistance=dy&63;
}








u32 func_02184968(const u8 *p,int flag){u32 q;q=sub_020450F0(p[0],p[1],p[2],p[3],p[4],p[5],1);sub_02043B5C((struct CharBuf*)sub_02045770((struct Descriptor*)q),15);if(flag==1)sub_02045374((struct Cfg*)q);return q;}








/*
 * prototype: explicit original heap shift pairs require narrow extern parameters for D7EC/40B94 despite their full-width own declarations;84968 returns descriptor pointer.
 */
void func_021849A4(char *p,void *arc)
{
    ((struct Obj01012 *)p)->fC06C=func_0201D7EC(0x17,0,0,0,(u16)(((struct Obj01012 *)p)->f0));
    func_0201DE00((u8 *)p+0xc084,(u8 *)p+0xc085,(u8 *)p+0xc086);
    func_0201DD78(1,2,0xf);
    func_0203FCA0(6,&d_02185E58,0);
    func_020414EC(6);
    func_0203FCA0(7,&d_02185E78,0);
    func_02049658(arc,5,7,0,0,0,((struct Obj01012 *)p)->f0);
    func_02049B68(arc,6,4,0,0x80,((struct Obj01012 *)p)->f0);
    func_020498F4(arc,7,7,0,0,0,((struct Obj01012 *)p)->f0);
    func_0201F5BC(6,4,6,0,((struct Obj01012 *)p)->f0);
    func_0201F5BC(6,0x22,7,0,((struct Obj01012 *)p)->f0);
    func_02049B40(0x17,5,4,0x80,0x20,((struct Obj01012 *)p)->f0);
    func_02040B94(6,0x20,0,(u16)(((struct Obj01012 *)p)->f0));
    func_02040EBC(6,0x4753);
    ((struct Obj01012 *)p)->fC01C=(void *)func_02184968(d_02185DBD,1);
    func_0201F73C(((struct Obj01012 *)p)->fC01C,0,4,6);
    func_02045334(((struct Obj01012 *)p)->fC01C);
    ((struct Obj01012 *)p)->fC0B0=0;
    func_0203FCA0(2,&d_02185E58,0);
    func_020414EC(2);
    func_0204044C(1);
    func_0203FCA0(3,&d_02185E78,0);
    func_02049658(arc,5,3,0,0,0,((struct Obj01012 *)p)->f0);
    func_02049B68(arc,6,0,0,0x80,((struct Obj01012 *)p)->f0);
    func_020498F4(arc,7,3,0,0,0,((struct Obj01012 *)p)->f0);
    func_0201F5BC(2,0x22,7,0,((struct Obj01012 *)p)->f0);
    func_02049B40(0x17,5,0,0x80,0x20,((struct Obj01012 *)p)->f0);
    func_02049B40(0x17,5,0,0x100,0x20,((struct Obj01012 *)p)->f0);
    func_02040B94(2,0x20,0,(u16)(((struct Obj01012 *)p)->f0));
    func_02040EBC(2,0);
    func_02184BAC(p);
}







void func_02184BAC(char *p)
{
    ((struct Obj01439 *)p)->fC064=func_02045EC0(*(struct MsgBank * *)&((struct Obj01439 *)p)->fC070,13);
    ((struct Obj01439 *)p)->fC068=func_02045EC0(*(struct MsgBank * *)&((struct Obj01439 *)p)->fC070,16);
    *(struct R * *)&((struct Obj01439 *)p)->fC058=func_02027F60(2,9,((struct Obj01439 *)p)->fC06C,((struct Obj01439 *)p)->fC080,(u16)((struct Obj01439 *)p)->f0);
    ((struct Obj01439 *)p)->fC08C=((struct Obj01439 *)p)->fC064;
    ((struct Obj01439 *)p)->fC090=0x39e3;((struct Obj01439 *)p)->fC094=0;
    ((struct Obj01439 *)p)->fC098=((struct Obj01439 *)p)->fC068;
    ((struct Obj01439 *)p)->fC09C=0x39e3;((struct Obj01439 *)p)->fC0A0=1;
}







void func_02184C2C(char *p,int i)
{
    if(*(unsigned *)(p+0xc05c+i*4)==0){
        *(unsigned *)(p+0xc05c+i*4)=func_02027FEC(((struct Obj14776 *)p)->fC058,(unsigned)(p+0xc08c+i*12),(u8)d_02185E40[i].x,(u8)d_02185E40[i].y,(u8)d_02185E40[i].z,(u16)((struct Obj14776 *)p)->f0);
    }
}







void func_02184C8C(u8 *p,u32 i){u32 off=i*4;u8 *slots=p+0xc05c;if(*(u8**)(slots+off)){func_02028148(*(u8**)(slots+off));sub_02041B6C(2);*(u8**)(slots+off)=0;}}







void func_02184CB0(char *p)
{
    func_02184C8C((u8 *)p,0);func_02184C8C((u8 *)p,1);
    func_02027FD8(*(struct TaskMenuState * *)&((struct Obj02933 *)p)->fC058);
    func_02045808(*(struct U16Vec * *)&((struct Obj02933 *)p)->fC064);func_02045808(*(struct U16Vec * *)&((struct Obj02933 *)p)->fC068);
    ((struct Obj02933 *)p)->fC05C=0;((struct Obj02933 *)p)->fC060=0;
    func_020452E8(*(struct Descriptor * *)&((struct Obj02933 *)p)->fC01C);
    func_020403F4(2);func_020403F4(6);func_020403F4(3);func_020403F4(7);
    func_0201D83C(((struct Obj02933 *)p)->fC06C);
    func_0201DD78((unsigned char)p[0xc084],(unsigned char)p[0xc085],(unsigned char)p[0xc086]);
}







void func_02184D30(char *p,struct Record *out,struct Descriptor *d,void *text,u8 x,u8 y)
{
    struct PrintSys *print;
    out->descriptor=d;out->active=0;
    print=*(struct PrintSys * *)&((struct Obj02934 *)p)->fC080;
    func_0201C6FC(print,(unsigned)func_02045770(d),x,y,text,((struct Obj02934 *)p)->fC06C);
    out->active=1;
}







/*
 * blocker-C: 02045CAC verified EXACT, 344B, scratch arm9-blocker.log;
 * copied unchanged from unit_02045C44.c, using dsi/1.1p1 -O4,p --arm.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned int u32;
 * struct MsgEntry { u32 off; u16 len; u16 pad_06; };
 * struct MsgFile {
 *     u16 langCount; u16 count; u32 unk_04; u32 unk_08; u32 langOff[1];
 * };
 * struct MsgBank {
 *     const struct MsgFile *file;
 *     void *base;
 *     struct MsgEntry cache;
 *     u32 origin;
 *     void *stream;
 *     u16 heapId;
 *     u8 langIndex;
 *     u8 resident;
 * };
 * extern char g_020A7E8C[];
 * extern void *sub_02030734(u32,u32,int,const char *,u16);
 * extern void func_020307B0(void *);
 * extern void func_020495F4(void *,u32,void *);
 * extern void func_0204960C(void *,u32);
 * extern void func_0204581C(void *);
 * extern void func_02045A00(void *,const void *,u16);
 * extern void func_02045E04(void *,u32);
 * extern void func_02046180(struct MsgBank *);
 * void func_02045CAC(struct MsgBank *bank,u32 index,void *dest)
 * {
 *     u32 size;
 *     struct MsgEntry *e;
 *     if (index >= bank->file->count) {
 *         func_0204581C(dest);
 *         return;
 *     }
 *     func_02046180(bank);
 *     if (bank->resident == 0) {
 *         u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *         func_0204960C(bank->stream,pos + (index * 8 + 4));
 *         func_020495F4(bank->stream,8,&bank->cache);
 *         e = &bank->cache;
 *     } else {
 *         e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
 *     }
 *     if (bank->resident == 0) {
 *         void *buf;
 *         size = e->len * 2;
 *         buf = sub_02030734((u16)((bank->heapId & 0x7fff) | 0x8000),size,
 *                            0,g_020A7E8C,0xd6);
 *         if (buf != 0) {
 *             func_0204960C(bank->stream,
 *                           e->off + (bank->origin
 *                               + bank->file->langOff[bank->langIndex]));
 *             func_020495F4(bank->stream,size,buf);
 *             func_02045A00(dest,buf,e->len);
 *             func_020307B0(buf);
 *         }
 *     } else {
 *         func_02045A00(dest,(u8 *)bank->base + e->off,e->len);
 *     }
 *     func_02045E04(dest,index);
 * }
 *
 * prototype: 0201CCE4's legacy void return is live r0 stored to p+C074; retain u32 return. Heap truncation at call sites uses u16.
 */
int func_02184D70(char *p,u32 message,int force)
{
    int result;
    u32 mode;
    result=0;
    switch(*(u32 *)(p+0xC0B0)) {
    case 0:
        func_02043B5C(func_02045770(*(struct Descriptor **)(p+0xC01C)),15);
        *(struct U16Vec **)(p+0xC0AC)=func_020457B0(1024,(u16)(*(u32 *)p));
        func_02045CAC(*(struct MsgBank **)(p+0xC070),message,*(struct U16Vec **)(p+0xC0AC));
        *(u32 *)(p+0xC074)=func_0201CCE4(*(u32 *)(p+0xC01C),0,0,*(u32 *)(p+0xC0AC),*(u32 *)(p+0xC06C),func_02012FFC(),*(u32 *)(p+0xC0A4),0,*(u32 *)p,15);
        *(u32 *)(p+0xC0B0)=1;
        break;
    case 1:
        mode=func_0201CE30(*(void **)(p+0xC074));
        func_020286C4(*(struct Ctx **)(p+0xC088),*(void **)(p+0xC074),*(void **)(p+0xC01C));
        switch(mode) {
        case 0:
            if(func_0203630C()&1)func_0201CE5C(*(struct Rec **)(p+0xC074),0);
            break;
        case 1:
            if((*(u32 *)(p+0xC354)&1)||(*(u32 *)(p+0xC354)&2)) {
                func_0201CE38(*(void **)(p+0xC074));
                func_020061E4(0x547);
            }
            break;
        case 2: *(u32 *)(p+0xC0B0)=2;break;
        }
        break;
    case 2:
        if(force!=0 || (*(u32 *)(p+0xC354)&1)) {
            func_02045808(*(struct U16Vec **)(p+0xC0AC));
            func_0201CE48(*(struct Rec3 **)(p+0xC074));
            *(u32 *)(p+0xC0B0)=0;
            result=1;
        }
        break;
    }
    return result;
}







void func_02184EAC(int a, int b, int c)
{
    if (c == 0)
        func_020061E4(0x547);
}






/*
 * prototype: retain 1F878 fifth u16 stack argument loaded by this caller, absent from legacy callee declaration; 1FF30 heap explicitly narrowed in caller.
 */
void func_02184EC0(char *p,const unsigned char *descriptor,const struct Src_02183B60 *source,const Entry_02183B60 *entries)
{
    int i;
    struct Src_02183B60 cfg;
    *(struct Descriptor * *)&((struct Obj00927 *)p)->fC018=(struct Descriptor *)func_02184968(descriptor,1);
    ((struct Obj00927 *)p)->fC050=func_0201F81C(((struct Obj14777 *)source)->f10,((struct Obj00927 *)p)->f0);
    for(i=0;i<((struct Obj14777 *)source)->f10;i++)
        func_0201F878(*(struct Slot * *)&((struct Obj00927 *)p)->fC050,((struct Obj00927 *)p)->fC070,entries[i].bank,entries[i].id,(u16)(((struct Obj00927 *)p)->f0));
    ((struct Obj00927 *)p)->fC078=((struct Obj00927 *)p)->fC018;
    p[0xC07C]=0;
    cfg=*source;
    cfg.w[0]=*(u32 *)&((struct Obj00927 *)p)->fC050;
    cfg.w[3]=*(u32 *)(p+0xC018);
    cfg.w[1]=(u32)func_02184EAC;
    *(u16 *)((char *)&cfg+32)=12;
    *(u16 *)((char *)&cfg+34)=func_0201DC80(*(struct Font * *)&((struct Obj00927 *)p)->fC06C);
    cfg.w[9]=((struct Obj00927 *)p)->fC070;
    cfg.w[10]=(u32)(p+0xC078);
    cfg.w[11]=((struct Obj00927 *)p)->fC080;
    cfg.w[12]=*(u32 *)&((struct Obj00927 *)p)->fC06C;
    *(struct Obj * *)&((struct Obj00927 *)p)->fC04C=func_0201FF30((struct Src_02183B60 *)&cfg, 0, 0, (u16)(((struct Obj00927 *)p)->f0));
    func_02020CF8(*(struct Obj * *)&((struct Obj00927 *)p)->fC04C,((struct Obj00927 *)p)->f0);
    func_0201F73C(((struct Obj00927 *)p)->fC018,0,34,7);
    func_02045334(*(struct Descriptor **)(p+0xC018));
}





/*
 * prototype: 20CF8 legacy one parameter; original also visibly sets r1
 * to full-width heap, retained as a second input even though body ignores it.
 */
void func_02184FC8(char *p,const struct Src_02184FC8 *source,unsigned count)
{
    struct Src_02184FC8 cfg;
    ((struct Obj01013 *)p)->fC078=((struct Obj01013 *)p)->fC018;p[0xc07c]=0;
    cfg=*source;
    cfg.w[0]=*(unsigned *)&((struct Obj01013 *)p)->fC050;
    *(u16 *)((char *)&cfg+16)=count;
    cfg.w[3]=*(unsigned *)&((struct Obj01013 *)p)->fC018;
    cfg.w[1]=(unsigned)func_02184EAC;
    *(u16 *)((char *)&cfg+32)=12;
    *(u16 *)((char *)&cfg+34)=func_0201DC80(*(struct Font * *)&((struct Obj01013 *)p)->fC06C);
    cfg.w[10]=(unsigned)(p+0xc078);
    cfg.w[11]=((struct Obj01013 *)p)->fC080;
    cfg.w[12]=*(unsigned *)&((struct Obj01013 *)p)->fC06C;
    *(struct Obj * *)&((struct Obj01013 *)p)->fC04C=func_0201FF30((struct Src_02183B60 *)&cfg, 0, 0, (u16)((struct Obj01013 *)p)->f0);
    func_02020CF8(*(struct Obj * *)&((struct Obj01013 *)p)->fC04C,((struct Obj01013 *)p)->f0);
    func_0201F73C(((struct Obj01013 *)p)->fC018,0,34,7);
    func_02045334(*(struct Descriptor * *)&((struct Obj01013 *)p)->fC018);
}





static inline u32 tb(int i) { return *(const u32 *)((const u8 *)d_02185F7C + i * 4); }






static inline u32 GetMsg(u32 idx) { return d_02185F7C[idx]; }





/*
 * 2026-10-05 (user decision): the two spellings of one table read (accessor for one argument, direct index for the other) are accepted as a real source quirk.
 * 2026-10-05 (wD9r lane130): still DIFF 17 bytes, source unchanged. New tries, all compiled: (1) a walking
 *   pointer `e = d; for (...; i++, e++) f(.., *e, *e, h)`: 43 (needs a register the image does not have; the image
 *   rematerialises the pool word and scales i every iteration, so there is no walking pointer); (2) a copy
 *   counter `j = i; f(.., d[i], d[j], h)`: 17 (copy propagation runs before the early CSE); (3) `d[i]` and
 *   `i[d]`: 17; (4) a volatile read for the fifth argument: 17 (no barrier for the CSE); (5) an assignment in
 *   the fifth argument `h = (u16)*p`: 17; (6) sized table with a sizeof bound: 46 (loop shape lost);
 *   (7) `((u32 *)d)[i]` for one argument: 61 (two loads survive). Diagnostic: with one table read and a
 *   literal fourth argument the h load comes first (10 bytes, schedule only), which confirms that the two
 *   reads are merged by the early CSE in every same-tree spelling. No real source form found.
 * 2026-10-05 (wD9r lane122): still DIFF 17 bytes, source unchanged. Data check: d_02185F7C is one u32
 *   array of 0x82 message ids (0x01..0xE3, two out of order), followed by the overlay .sinit; no pair table, no
 *   second symbol (one pool word), so both arguments really are one element. New tries: (1) pointer-typed callee
 *   parameters (void * for the index or the tag, with the table as u32 or void *const): the early CSE ignores
 *   the conversion, 17; (2) the table as a union of two same-typed members (msg/tag, also nested struct and
 *   one-element array members), one member per argument: 17 (same tree); (3) a union {u32 msg; unsigned long
 *   tag;} (or int/long), one member per argument: 4 bytes (only the lsls r3,r4,#2 / lsls r0,r0,#16 pair is
 *   swapped); a union {u32; int;} gives 61 (two loads). Finding: the early CSE keys on the element type and
 *   the address tree; any source that splits them is two spellings of one read (the D8 byte-offset form is
 *   EXACT, the u32/unsigned long view is 4 bytes). Not filed under the stand-in rule.
 * 2026-10-05 (wD9r lane113): still DIFF 17 bytes, source unchanged. New tries, all compiled: (1) loop body as a
 *   static inline taking the index, `AddOne(p, t, i)` and `AddOne(p, t, tbl, i)` reading tbl[i] twice inside (17);
 *   (2) the whole loop as a static inline `AddList(p, t, ids, n)` called with (d_02185F7C, 0x82): ternary bound 17,
 *   plain int or unsigned bound 46; (3) inline `Add(l, t, i, h)` / `Add(h, l, t, i)` / `Add(l, t, tbl, i, h)` with
 *   the table read inside the helper after the h parameter (u16 and u32 h): 17 (inline parameters are propagated, so
 *   the helper is transparent to the early CSE); (4) inline `Add(p, t, const u32 *e)` called with `d + i` and
 *   `&d[i]`, reading *e twice: 17; (5) one-word struct element copy `E e = tbl[i]; f(.., e.id, e.id, ..)`: 21;
 *   (6) loop shapes: goto loop with bottom test 46, while(1)/break 30, do-while 46, call in the for increment
 *   as a comma expression 17, `(void)` call and `if (1)` wrapper 17; (7) function-local static table
 *   (const and non-const): 17. Diagnostic only: a struct-cast read for one argument and d[i] for the other gives
 *   4 bytes (another two-spellings stand-in, not filed).
 * 2026-10-05 (wD9r lane66): still DIFF 17 bytes, source unchanged. Tried: (1) the table as a file
 *   static `static const u32 d_02185F7C[130]` defined in this unit: same CSE temp (and the data word
 *   has no witness); (2) the full shape of the matched twin ov219 021850EC (unsigned i, `(unsigned)bank`
 *   argument, prototype (Slot *, unsigned, unsigned, unsigned, u16)): the twin itself has the CSE temp
 *   form (ids load first), so the copy also gives it, plus a plain loop; (3) this function as the twin's
 *   body in a static inline Build(p, a, b, c, const u32 *ids, int count) called with (d_02185F7C, 0x82):
 *   46 bytes, CSE temp still first and the loop loses its branch to the bottom test.
 * 2026-10-05 (wD8 lane10): EXACT found but parked as DIFF under the stand-in rule. Writing the two table
 *   arguments in two different forms, `func_0201F878(..., t, d_02185F7C[i], tb(i), (u16)*(u32 *)p)` (or tb(i)
 *   third and d_02185F7C[i] fourth), gives EXACT 120 bytes: the early CSE no longer merges the two reads, so the
 *   stack argument is computed first and the late CSE shares the load. `d[i]` with `*(d + i)` does not (same
 *   tree), and tb as `return d[i]` does not. The two-form trick only exists to defeat CSE, so the integrator or
 *   the user must decide if it is acceptable. Source below is unchanged (17 bytes).
 * 2026-10-05 (wD7 lane14): still DIFF 17 bytes. Reading: the image computes the table address in r2/r3 because h (r0) and t (r1) are
 *   already live, so the table chain comes after the h load in the IR; ours computes the CSE'd table value first (temps r0/r1), so
 *   the scheduler cannot interleave. Tried: non-const extern table (same), u16 h local before the call (same, propagated),
 *   f(q, t, v, v = tb(i), h) (same), static inline Add(q, t, i, u16 h / int h) (same). The arm9 callee func_0201F878 reads only
 *   four arguments (the fifth is a dead stack argument, kept as in the matched sibling 02184EC0).
 * 2026-10-05 (wD6 lane16): still DIFF 17 bytes. Tried: static inline wrappers W(a, t, v, h) and W(h, a, t, v) calling
 *   f(a, t, v, v, h); Add(p, t, id) reading p inside; `v = d[i]` as the third argument with v as the fourth; a block
 *   with u16 h then u32 v locals. All keep the table load (CSE temp) before the stack argument.
 * 2026-10-05 (wD4 lane19): still DIFF 17 bytes, no new hypothesis beyond the 2026-10-04 notes closed it.
 * note 2026-10-04: DIFF, 17 bytes, loop body only. Original loads the u16 stack argument ((u16)*p) first,
 *   then the table pool address into r2 and indexes in r2; here the table base goes to r0 and the table
 *   load comes before the *p load. Everything else matches (u32 param c with (u16) casts in the call, loop
 *   as (i < 0x82) ? 1 : 0). Tried: locals k/w in both orders, static inline table reader, byte-offset read.
 *   2026-10-04 (D2): also tried plain d_02185F7C[i] twice, k local, callee last param u16 with u32 arg, local
 *   table pointer (59 bytes worse: hoists the pool load). Still 17 bytes: u16 stack arg must load before the table pool word.
 * 2026-10-05 (wD5 lane20): no new hypothesis closed it; the 17 byte residue is unchanged.
 * 2026-10-05 (wD9 lane11): still DIFF 17 bytes. Tried: callee prototype with mixed int/u32 index and tag
 *   parameters (int,u32 / u32,int / int,int) so the two table arguments carry different conversions; the early CSE
 *   still merges them (17 bytes, unchanged). Matched sibling 02184EC0 (same overlay) passes entries[i].bank /
 *   entries[i].id to the same callee, so a struct-table reading does not apply here (one load feeds both).
 * 2026-10-05 (wD9r lane03): still DIFF 17 bytes. Tried: the fifth argument through a static inline getter
 *   `u16 Hid(u8 *p)` (with plain d[i] twice, and with tb(i) twice): unchanged; `f(q, t, v = d[i], v, h)`
 *   (assignment in the third argument; the fourth-argument form was tried before): unchanged. The early
 *   CSE still places the table read before the stack argument.
 * 2026-10-05 (wD9r lane24): still DIFF 17 bytes. Tried an unprototyped callee `extern void func_0201F878();`
 *   (default argument promotions): unchanged. Reading kept: the image order (h load, table load, C050 load)
 *   is right-to-left argument evaluation, so in the original the two table reads were not one CSE candidate
 *   at the early stage; only the two-form D8 source reproduces that so far.
 * 2026-10-05 (wD9r lane40): still DIFF 17 bytes, source unchanged. Tried: a real struct for p (heap at 0,
 *   msg at 0xC018, list at 0xC050, as the matched sibling 02184EC0) with implicit u16 conversion of w->heap and
 *   plain d[i] twice: unchanged; an element pointer local `e = &d[i]; f(.., *e, *e, h)`: unchanged. Reading kept:
 *   the image has no statement-level CSE temp (table read after the h load, before the C050 load, i.e. in
 *   argument position); every single-tree spelling gets the temp.
 * 2026-10-05 (wD9r lane101): still DIFF 17 bytes, source unchanged. Rechecked every block against the
 *   listing: prologue, the three setup calls, the 0xC018/0xC050 offsets and the tail are byte-identical;
 *   the loop body has the same operands (q at p+0xC050, t, d[i] twice, (u16)p[0]), so no logic error.
 *   New tries, all with plain d[i] twice: sized extern `d[0x82]` (17); table as a global struct with
 *   one `ids[0x82]` member (17); `d[i], d[i++]` in the arguments (79); a bound local `n = 0x82` used in all
 *   three places, and a file-scope `const int` bound (46: the first test folds, the loop loses its branch
 *   to the bottom test); `i = 0` hoisted above the calls with a plain for (46 to 69); variadic callee
 *   prototypes `(void *, void *, u32, u32, ...)`, `(void *, void *, ...)`, `(void *, ...)` (17); a static
 *   inline 5-parameter pass-through `Add(l, m, s, v, h)` called with d[i] twice (17 with u16 h, 59 with
 *   u32 h). Diagnostic only (not filed): the plain `i < 0x82` loop at -O2,p is also 17 bytes, so the early
 *   CSE of the two table reads is present at -O2 too. Reading: the image has no early CSE temp and no
 *   loop rotation; both are global-optimizer effects, so the original may contain something that
 *   restricted that optimizer for this function. No real source form found.
 */
void func_02185074(u8 *p, const u8 *a, u32 b, u32 c)
{
    void *t;
    int i;
    *(u32 *)(p + 0xC018) = func_02184968(a, 1);
    t = func_02045B38(0, 2, (u16)c, (u16)*(u32 *)p);
    *(void **)(p + 0xC050) = func_0201F81C(0x82, *(u32 *)p);
    for (i = 0; (i < 0x82) ? 1 : 0; i++) {
        func_0201F878(*(void **)(p + 0xC050), (u32)t, GetMsg(i), d_02185F7C[i], (u16)*(u32 *)p);
    }
    func_02045C04(t);
    func_02184FC8((char *)p, (const struct Src_02184FC8 *)b, 0x82);
}





/*
 * prototype: 45B38 third/fourth original inputs explicitly narrowed u16;
 * 1F878 retains original fifth stack heap input absent from legacy source.
 */
void func_021850EC(char *p,const unsigned char *descriptor,const struct Src_02184FC8 *cfg,unsigned file,const unsigned char *ids,unsigned count)
{
    struct MsgBank *bank;
    unsigned i;
    *(struct Descriptor * *)&((struct Obj01013 *)p)->fC018=(struct Descriptor *)func_02184968(descriptor,1);
    bank=func_02045B38(0,2,(u16)file,(u16)(((struct Obj01013 *)p)->f0));
    *(BmpMenuWork * *)&((struct Obj01013 *)p)->fC050=func_0201F81C(130,((struct Obj01013 *)p)->f0);
    for(i=0;i<count;i++)func_0201F878(*(struct Slot **)(p+0xc050),(unsigned)bank,ids[i],ids[i],(u16)((struct Obj01013 *)p)->f0);
    func_02045C04((struct Rec *)bank);
    func_02184FC8(p, (const struct Src_02184FC8 *)cfg, count);
}




void func_0218516C(u8*p){func_0201F7A8(*(void* *)&((struct Obj08451 *)p)->fC018,0);sub_020452E8(*(struct Descriptor* *)&((struct Obj08451 *)p)->fC018);func_0202020C(*(struct Obj* *)&((struct Obj08451 *)p)->fC04C,0,0);func_0201F868(*(void* *)&((struct Obj08451 *)p)->fC050);}




/*
 * prototype: 457B0 heap input is explicitly narrowed to u16 in original;
 * retain all observed narrow inputs to matching4D30 stack-byte interface.
 */
void func_0218519C(char *p)
{
    struct U16Vec *dst,*src;
    dst=func_020457B0(1024,(u16)(((struct Obj01984 *)p)->f0));src=func_020457B0(1024,(u16)(((struct Obj01984 *)p)->f0));
    *(struct Descriptor * *)&((struct Obj01984 *)p)->fC040=(struct Descriptor *)func_02184968(d_02185DCB,1);
    func_0201F048(*(struct WordSet * *)&((struct Obj01984 *)p)->fC0A8,0,((struct Obj01984 *)p)->fC33C);
    func_0201F094(*(struct WordSet * *)&((struct Obj01984 *)p)->fC0A8,1,((struct Obj01984 *)p)->fC33C,((struct Obj01984 *)p)->fC340);
    func_02045CAC(*(struct MsgBank * *)&((struct Obj01984 *)p)->fC070,14,src);
    func_0201F250(*(struct WordSet * *)&((struct Obj01984 *)p)->fC0A8,dst,src);
    func_02184D30(p,(struct Record *)(p+0xc044),*(struct Descriptor * *)&((struct Obj01984 *)p)->fC040,dst,0,0);
    func_02045808(src);func_02045808(dst);
    func_0201F73C(((struct Obj01984 *)p)->fC040,0,34,7);
    func_02045334(*(struct Descriptor * *)&((struct Obj01984 *)p)->fC040);
}




/*
 * prototype: original truncates heap before 020457B0, and stack bytes before 02184D30; extern narrow widths preserve those visible operations.
 */
void func_02185254(char *p,unsigned key,unsigned member)
{
    void *first,*second,*object;
    first=func_020457B0(64,(u16)(((struct Obj02934 *)p)->f0));
    second=func_020457B0(64,(u16)(((struct Obj02934 *)p)->f0));
    ((struct Obj02934 *)p)->fC040=(void *)func_02184968(d_02185DCB,1);
    func_02185C84(key,member,first,second,((struct Obj02934 *)p)->f0);
    if(member!=0) func_02184D30(p,(struct Record *)(p+0xC044),((struct Obj02934 *)p)->fC040,second,0,16);
    func_02184D30(p,(struct Record *)(p+0xC044),((struct Obj02934 *)p)->fC040,first,0,0);
    func_02045808(second);
    func_02045808(first);
    func_0201F73C(((struct Obj02934 *)p)->fC040,0,34,7);
    object=((struct Obj02934 *)p)->fC040;
    func_02045334(object);
    func_02045374(object);
    func_02041B6C(func_02045730(object));
}





void func_02185310(char *p)
{
    char *q = p + 0xc040;
    func_0201F7A8((void *)(((struct Obj14780 *)q)->f0), 0);
    func_020452E8((struct Descriptor *)(((struct Obj14780 *)q)->f0));
}





/*
 * 2026-10-05 (wD9 lane12): EXACT. The wrap value was a ternary local t merged at a join and stored
 *   to ylo and yhi after it. Writing the stores in each arm (`if (lo2 > 0) yhi = ylo = lo2 - 0x10000;
 *   else yhi = ylo = lo2 + 0x10000;`) gives lo2 r6 and spills yhi, as in the image (tail merging
 *   rebuilds the shared two-store join). See docs/idioms/two-long-lived-values-in-each-others-registers.md.
 * 2026-10-05 (wD8 lane10): still DIFF 91 bytes. Re-read the listing: semantics match (ylo [sp,#0x10], yhi
 *   [sp,#0xc], hi2 [sp,#8], lo2 r6; wrap order lo2-=, hi2+=, ylo-=, yhi+=). No new test closed the r6 swap.
 * 2026-10-05 (wD7 lane14): still DIFF 91 bytes. Re-derived the middle part: no logic error found. Tried: ylo = ternary; yhi = ylo
 *   (no t local, same 91); ylo/yhi as a two-element local array (mwcc scalarises it, 98).
 * 2026-10-05 (wD6 lane16): still DIFF 91 bytes. Tried: else arm as lo2 = ylo; hi2 = yhi (order swap) and the abs test
 *   as a ternary inside the if: no change. Callee 02185D08 reads only r0 (no missing argument).
 * 2026-10-05 (wD5 lane05): DIFF 91 bytes (was 163). Fixes: no e record pointer local (each
 *   field read as *(T *)(p + i * 0x30 + K), loop colours now exact); no cx/cy locals; every use reads
 *   *(int *)(p + 0xC2F4/0xC2F8) directly (CSE gives the original load order; prologue now exact up to
 *   +0x3A). Residue: yhi takes r6 and lo2 is spilled to [sp,#0xc]; the original has lo2 in r6 and yhi
 *   in [sp,#0xc] (a pure swap of the two, all else follows). No change from: lo2 assigned directly
 *   (no y16 temp), declaring lo2 last or before yhi, `yhi = ylo = t`, the ternary as an if/else on
 *   ylo, a struct Ent array for the 0x30 records (worse, hoists p+0x18). lo2/hi2 set before the if
 *   (no else) does give lo2 r6 but loses the else block (257).
 * 2026-10-05 (wD4 lane19): still DIFF 163 bytes. Tried the constant in a local (int off = 0xC2F4; p[off], p[off+4], and for the reload): mwcc folds it, no change.
 * 2026-10-04 (wD2 lane 09): 284 vs 288 bytes, 163 bytes differ, same frame.
 * Semantics read from the listing (x,y at +0xC2F4/+0xC2F8, count at +0x14,
 * 0x30-byte records, s16 fields +0x18/+0x1a, u16 flag +0x40). Residue: the
 * original keeps only lo2 (r6) in a register and spills ylo/yhi/hi2; ours puts
 * yhi in r6, so the wrap test and the range test swap order, and the loop
 * colours ex/ey/e as r1/r2/r0 instead of r0/r1/r2. Tried: lo2/hi2 set through
 * y16 before the temp (89->163 bytes better than the first draft), declaring
 * lo2/hi2 first (169, worse). Not tried: wrap test through different locals.
 */
int func_0218532C(char *p, u32 *out)
{
    int ret = 0;
    int xlo, xhi, ylo, yhi, lo2, hi2;
    u32 i;
    u32 best;
    u32 bestd;
    int cur[2];

    xlo = (s16)(*(int *)(p + 0xC2F4) - 0x80);
    xhi = (s16)(*(int *)(p + 0xC2F4) + 0x80);
    ylo = (s16)(*(int *)(p + 0xC2F8) - 0x80);
    yhi = (s16)(*(int *)(p + 0xC2F8) + 0x80);
    best = *(u32 *)(p + 0x14);
    bestd = 0x100;
    cur[0] = *(int *)(p + 0xC2F4);
    cur[1] = *(int *)(p + 0xC2F8);
    func_02185D08(cur);
    {
        int d = yhi - ylo;
        if (d < 0) d = -d;
        if (d > 0x100) {
            lo2 = (s16)*(int *)(p + 0xC2F8);
            hi2 = lo2;
            if (lo2 > 0)
                yhi = ylo = lo2 - 0x10000;
            else
                yhi = ylo = lo2 + 0x10000;
            lo2 -= 0x80;
            hi2 += 0x80;
            ylo -= 0x80;
            yhi += 0x80;
        } else {
            hi2 = yhi;
            lo2 = ylo;
        }
    }
    for (i = 0; i < *(u32 *)(p + 0x14); i++) {
        int ex = *(s16 *)(p + i * 0x30 + 0x18);
        if (ex > xlo && ex < xhi) {
            int ey = *(s16 *)(p + i * 0x30 + 0x1a);
            if ((ey > ylo && ey < yhi) || (ey > lo2 && ey < hi2)) {
                if (*(u16 *)(p + i * 0x30 + 0x40) != 0) {
                    int pt[2];
                    u32 dd;
                    pt[0] = ex;
                    pt[1] = *(s16 *)(p + i * 0x30 + 0x1a);
                    func_02185D08(pt);
                    dd = func_02185D64(cur, pt);
                    if (dd < bestd) {
                        bestd = dd;
                        best = i;
                    }
                }
            }
        }
    }
    *out = best;
    if (best != *(u32 *)(p + 0x14))
        ret = 1;
    return ret;
}




/*
 * lever: distinct outer buffer and block-scoped first/second buffers settle the eight-byte r4/r6 swap.
 * blocker-C: 02045CAC verified EXACT, 344B, scratch arm9-blocker.log;
 * copied unchanged from unit_02045C44.c, using dsi/1.1p1 -O4,p --arm.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned int u32;
 * struct MsgEntry { u32 off; u16 len; u16 pad_06; };
 * struct MsgFile {
 *     u16 langCount; u16 count; u32 unk_04; u32 unk_08; u32 langOff[1];
 * };
 * struct MsgBank {
 *     const struct MsgFile *file;
 *     void *base;
 *     struct MsgEntry cache;
 *     u32 origin;
 *     void *stream;
 *     u16 heapId;
 *     u8 langIndex;
 *     u8 resident;
 * };
 * extern char g_020A7E8C[];
 * extern void *sub_02030734(u32,u32,int,const char *,u16);
 * extern void func_020307B0(void *);
 * extern void func_020495F4(void *,u32,void *);
 * extern void func_0204960C(void *,u32);
 * extern void func_0204581C(void *);
 * extern void func_02045A00(void *,const void *,u16);
 * extern void func_02045E04(void *,u32);
 * extern void func_02046180(struct MsgBank *);
 * void func_02045CAC(struct MsgBank *bank,u32 index,void *dest)
 * {
 *     u32 size;
 *     struct MsgEntry *e;
 *     if (index >= bank->file->count) {
 *         func_0204581C(dest);
 *         return;
 *     }
 *     func_02046180(bank);
 *     if (bank->resident == 0) {
 *         u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *         func_0204960C(bank->stream,pos + (index * 8 + 4));
 *         func_020495F4(bank->stream,8,&bank->cache);
 *         e = &bank->cache;
 *     } else {
 *         e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
 *     }
 *     if (bank->resident == 0) {
 *         void *buf;
 *         size = e->len * 2;
 *         buf = sub_02030734((u16)((bank->heapId & 0x7fff) | 0x8000),size,
 *                            0,g_020A7E8C,0xd6);
 *         if (buf != 0) {
 *             func_0204960C(bank->stream,
 *                           e->off + (bank->origin
 *                               + bank->file->langOff[bank->langIndex]));
 *             func_020495F4(bank->stream,size,buf);
 *             func_02045A00(dest,buf,e->len);
 *             func_020307B0(buf);
 *         }
 *     } else {
 *         func_02045A00(dest,(u8 *)bank->base + e->off,e->len);
 *     }
 *     func_02045E04(dest,index);
 * }
 *
 * prototype: caller narrows allocation heap to u16 immediately before each call.
 */
void func_0218544C(char *p)
{
    struct U16Vec *buffer;
    u32 selected;
    if(*(u32 *)(p+0xC350)==0) {
        buffer=func_020457B0(1024,(u16)(*(u32 *)p));
        func_02043B5C(func_02045770(*(struct Descriptor **)(p+0xC01C)),15);
        func_02045CAC(*(struct MsgBank **)(p+0xC070),15,buffer);
        func_02184D30(p,(struct Record *)(p+0xC020),*(struct Descriptor **)(p+0xC01C),buffer,0,0);
        func_02045808(buffer);
    } else {
        struct U16Vec *first,*second;
        if(func_0218532C(p,&selected)) {
            first=func_020457B0(64,(u16)(*(u32 *)p));
            second=func_020457B0(64,(u16)(*(u32 *)p));
            func_02043B5C(func_02045770(*(struct Descriptor **)(p+0xC01C)),15);
            func_02185C84(*(u16 *)(p+selected*48+66),*(u16 *)(p+selected*48+68),first,second,*(u32 *)p);
            if(*(u16 *)(p+selected*48+68)!=0)
                func_02184D30(p,(struct Record *)(p+0xC020),*(struct Descriptor **)(p+0xC01C),second,0,16);
            func_02184D30(p,(struct Record *)(p+0xC020),*(struct Descriptor **)(p+0xC01C),first,0,0);
            func_02045808(second);
            func_02045808(first);
            *(int *)(p+0xC2F4)=*(s16 *)(p+selected*48+24);
            *(int *)(p+0xC2F8)=*(s16 *)(p+selected*48+26);
        } else *(u32 *)(p+0xC350)=0;
    }
    func_02045334(*(struct Descriptor **)(p+0xC01C));
}



void func_02185580(char *p, void *arc)
{
    unsigned i;
    char *row;
    ((struct Obj04645 *)p)->fC374=func_02046DB8(197,0);
    func_02046FF8(*(int * *)&((struct Obj04645 *)p)->fC374);
    ((struct Obj04645 *)p)->fC38C=func_02047400(((struct Obj04645 *)p)->fC374,0,((struct Obj04645 *)p)->fC374);
    ((struct Obj04645 *)p)->fC3A4=func_0204767C(*(unsigned *)&((struct Obj04645 *)p)->fC38C,0,0);
    for(i=0;i<4;i++) {
        row=p+d_02185E18[i].index*4;
        ((struct Obj04646 *)row)->fC378=func_02046DB8(197,d_02185E18[i].member);
        func_02046FF8(*(int * *)&((struct Obj04646 *)row)->fC378);
        ((struct Obj04646 *)row)->fC390=func_02047400(((struct Obj04646 *)row)->fC378,0,((struct Obj04646 *)row)->fC378);
        ((struct Obj04646 *)row)->fC3A8=func_0204767C(*(unsigned *)&((struct Obj04646 *)row)->fC390,0,0);
    }
    func_02185728(p);
    func_02185824(p);
}



void func_0218562C(char *p)
{
    u32 i;
    char *row;
    func_02048AC4(*(void **)(p+0xC36C));
    func_02048C4C(*(void **)(p+0xC370));
    func_02047738(*(void **)(p+0xC3A4));
    func_02047504(*(void **)(p+0xC38C));
    func_020470D0(*(u32 **)(p+0xC374));
    func_02046EFC(*(void **)(p+0xC374));
    for(i=0;i<4;i++) {
        row=p+d_02185E18[i].index*4;
        func_02047738(*(void **)(row+0xC3A8));
        func_02047504(*(void **)(row+0xC390));
        func_020470D0(*(u32 **)(row+0xC378));
        func_02046EFC(*(void **)(row+0xC378));
    }
    *(u32 *)(p+0xC3A4)=0;
}




void func_021856CC(u8 *p)
{
    int k = 0xC2DC;

    *(int *)(p + k) = 0;
    *(int *)(p + k + 4) = 0;
    *(int *)(p + k + 8) = 0;
    *(int *)(p + k + 0xC) = 0x1000;
    *(int *)(p + k + 0x10) = 0x1000;
    *(int *)(p + k + 0x14) = 0x1000;
    *(int *)(p + k + 0x18) = 0x1A40;
    *(int *)(p + k + 0x1C) = 0x7C00;
    *(int *)(p + k + 0x20) = 0;
    *(int *)(p + k + 0x24) = 0x1000;
    *(int *)(p + k + 0x28) = 0x1000;
    *(int *)(p + k + 0x2C) = 0x1000;
}



void func_02185728(char *p)
{
    Vec3_02185728 vec;
    u16 heap;
    heap=((struct Obj10975 *)p)->f0;
    vec=d_02185F00;
    ((struct Obj10975 *)p)->fC36C=func_02048A24(0,d_020A1EB8.x,d_020A1EB8.y,5461,0,4096,4194304,0,((Vec3_02185728 *)&d_02185E0C),&vec,((Vec3_02185728 *)&d_02185DF4),heap);
    func_02048AD0(((struct Obj10975 *)p)->fC36C);
}




/*
 * note 2026-10-05 (wD6 lane16): EXACT. The flag block is an if/else-if chain with h == 0 first; tail merging of the duplicate stores gives the bne/b pairs.
 */
void func_02185794(char *p)
{
    u32 a = 0;
    u32 b = 0x19 << 14;
    func_02048AFC(*(void **)(p + 0xC36C), ((Vec3_02185728 *)&d_02185E0C));
    func_02048B44(*(void **)(p + 0xC36C), ((Vec3_02185728 *)&d_02185DF4));
    func_02048B80(*(void **)(p + 0xC36C), d_020A1C78.a);
    func_02048B94(*(void **)(p + 0xC36C), d_020A1C78.b);
    func_02048B60(*(void **)(p + 0xC36C), &a);
    func_02048B6C(*(void **)(p + 0xC36C), &b);
    if (*(u16 *)(p + 0xC31C) == 0)
        *(u16 *)(p + 0xC30C) = 1;
    else if (*(u32 *)(p + 0xC33C) == 0)
        *(u16 *)(p + 0xC30C) = 0;
    else if (*(u32 *)(p + 0xC33C) == 0xdc)
        *(u16 *)(p + 0xC30C) = 0;
    else
        *(u16 *)(p + 0xC30C) = 1;
    while (func_02185AC8(p) != 1)
        ;
}




void func_02185824(char *p)
{
    ((struct Obj10976 *)p)->fC370 = func_02048BC4((const struct LightSet *)d_02185DD4, (unsigned short)((struct Obj10976 *)p)->f0);
    func_02048C58(((struct Obj10976 *)p)->fC370);
}

#undef W

#define W(o) (*(int *)(p + (o)))



static inline int sine(u16 a) {return d_020A1B38[(a>>4)*2];}



static inline int cosine(u16 a) {return d_020A1B38[(a>>4)*2+1];}



void func_02185848(Matrix *p,int *angles)
{
    Matrix temp;
    func_0207AF1C(p,sine(angles[1]),cosine(angles[1]));
    func_0207AF00(&temp,sine(angles[0]),cosine(angles[0]));
    func_0207B388(p,&temp,p);
    func_0207AF38(&temp,sine(angles[2]),cosine(angles[2]));
    func_0207B388(p,&temp,p);
}



void func_021858BC(Matrix *p,int *angles)
{
    Matrix temp;
    func_0207AF1C(p,sine(angles[0]),cosine(angles[0]));
    func_0207AF00(&temp,sine(-angles[1]),cosine(-angles[1]));
    func_0207B388(p,&temp,p);
    func_0207AF38(&temp,cosine(angles[2]),sine(angles[2]));
    func_0207B388(p,&temp,p);
}




int func_02185934(u8 *p, u32 a, u32 b)
{
    int d0, d1;
    int res = 0;
    int x = (short)W(0xC2F4);
    int y = (short)W(0xC2F8);

    if ((a & 1) || (W(0xC320) & 1)) {
        if (H(0xC31C) == 1) {
            if (H(0xC30C) == 0)
                H(0xC30C) = 1;
            else
                H(0xC30C) = 0;
        }
        return 1;
    }
    if (H(0xC30C) == 0) {
        if (W(0xC330) != 0 || W(0xC334) != 0) {
            d0 = (u16)(0x55 * W(0xC330));
            d1 = (u16)(0x55 * W(0xC334));
        } else {
            d0 = 0x200;
            d1 = 0x200;
        }
    } else {
        if (W(0xC330) != 0 || W(0xC334) != 0) {
            d0 = (u16)(0xa * W(0xC330));
            d1 = (u16)(0xa * W(0xC334));
        } else {
            d0 = 0x20;
            d1 = 0x20;
        }
    }
    if ((b & 0x20) || (W(0xC320) & 0x20)) {
        if (H(0xC31C) == 1) {
            W(0xC2F8) += d0;
        } else if (y < -10208) {
            W(0xC2F8) += d0;
        }
        res = 1;
    }
    if ((b & 0x10) || (W(0xC320) & 0x10)) {
        if (H(0xC31C) == 1) {
            W(0xC2F8) -= d0;
        } else if (y > -13184) {
            W(0xC2F8) -= d0;
        }
        res = 1;
    }
    if ((b & 0x40) || (W(0xC320) & 0x40)) {
        if (H(0xC31C) == 1) {
            if (x + d1 < 0x3E00)
                W(0xC2F4) += d1;
            else
                W(0xC2F4) = 0x3E00;
        } else if (x < 0x2020) {
            W(0xC2F4) += d1;
        }
        res = 1;
    }
    if ((b & 0x80) || (W(0xC320) & 0x80)) {
        if (H(0xC31C) == 1) {
            if (x - d1 > -15872)
                W(0xC2F4) -= d1;
            else
                W(0xC2F4) = -15872;
        } else if (x > 0x1300) {
            W(0xC2F4) -= d1;
        }
        res = 1;
    }
    return res;
}



int func_02185AC8(char *p)
{
    Vec position,target,direction;
    long distance;
    int done;
    done=0;
    func_02048AE8(((struct Obj02935 *)p)->fC36C,&position);
    func_02048B30(((struct Obj02935 *)p)->fC36C,&target);
    func_0207CA00(&position,&target,&direction);
    distance=func_0207CBD0(&direction);
    func_0207CCA4(&direction,&direction);
    switch(((struct Obj02935 *)p)->fC30C) {
    case 1:
        if(distance>360448) {
            distance-=32768;
            ((struct Obj02935 *)p)->fC300-=128;
            ((struct Obj02935 *)p)->fC304=((struct Obj02935 *)p)->fC300;
        } else {distance=327680;done=1;}
        break;
    case 0:
        if(distance<1179648) {
            distance+=32768;
            ((struct Obj02935 *)p)->fC300+=128;
            ((struct Obj02935 *)p)->fC304=((struct Obj02935 *)p)->fC300;
        } else {distance=1212416;done=1;}
        break;
    }
    func_0207CEE4(distance,&direction,&target,&position);
    func_02048AFC(((struct Obj02935 *)p)->fC36C,(Vec3_02185728 *)&position);
    return done;
}




void func_02185B74(char *p)
{
    int state = *(int *)(p + 0xC310);

    switch (state) {
    case 0:
        break;
    case 2:
        func_02047964();
        func_02047970();
        *(int *)(p + 0xC310) = 0;
        break;
    case 1: {
        M33 m;
        Pair s;
        M33 m2;
        Pair s2;
        u32 i;

        func_02048C58(*(void **)(p + 0xC370));
        func_02048AD0(*(void **)(p + 0xC36C));
        func_02047964();
        func_020479D8();
        s.a = *(V3 *)(p + 0xC2DC);
        func_0207ADC4(&m);
        s.b = *(V3 *)(p + 0xC300);
        func_02047A60((void *)(*(u32 *)(p + 0xC3B8)), (struct Arg *)(&s));
        s.b = *(V3 *)(p + 0xC2E8);
        func_02185848((Matrix *)&m, (int *)(p + 0xC2F4));
        func_02047A60((void *)(*(u32 *)(p + 0xC3A4)), (struct Arg *)(&s));
        s2.a = *(V3 *)(p + 0xC2DC);
        s2.b = *(V3 *)(p + 0xC300);
        for (i = 0; i < *(u32 *)(p + 0x14); i++) {
            u16 f;
            func_0207B388((const Matrix *)(p + 0x1c + i * 0x30), (const Matrix *)&m, (Matrix *)&m2);
            f = *(u16 *)(p + i * 0x30 + 0x40);
            if (f != 0)
                func_02047A60((void *)(*(u32 *)(p + f * 4 + 0xC3A8)), (struct Arg *)(&s2));
        }
        func_02047970();
        break;
    }
    }
}



/*
 * prototype: caller explicitly truncatesB5B38 member/heap at secondsite; useu16extern for those observed narrow inputs.4790 is tailstubto02025B3C readingonlykey.
 */
int func_02185C84(unsigned key,unsigned optional,void *first,void *second,unsigned heap)
{
    unsigned index;
    void *bank;
    int found;
    index=func_02184790(key);
    found=0;
    bank=func_02045B38(0,2,231,heap);
    func_02045CAC(bank,key,first);
    func_02045C04(bank);
    if(index==0) {index=1;optional=0;}
    else found=1;
    bank=func_02045B38(0,2,func_02025BA0(index),heap);
    func_02045CAC(bank,optional,second);
    func_02045C04(bank);
    return found;
}
