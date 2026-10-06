/*
 * file:     btl_setup_p01.c
 * unit:     yes
 * function: func_02012914, func_02012924, func_0201292C, func_02012934, func_0201293C, func_02012944, func_02012950, func_0201295C, func_02012964, func_0201296C, func_02012974, func_0201297C, func_02012984, func_0201298C, func_02012994, func_020129A0, func_020129AC, func_020129B8, func_020129C4, func_020129D0, func_020129DC, func_020129F0, func_020129FC, func_02012A24, func_02012A30, func_02012A38, func_02012A44, func_02012A4C, func_02012A54, func_02012A60, func_02012A90, func_02012AA0, func_02012AA4, func_02012AB8, func_02012ABC, func_02012AC0, func_02012AC4, func_02012AC8, func_02012ACC, func_02012AD0, func_02012AD4, func_02012AE4, func_02012B28, func_02012B2C, func_02012B30, func_02012B34, func_02012B38, func_02012B40, func_02012B4C, func_02012B58, func_02012B64, func_02012B70, func_02012B78, func_02012B80, func_02012B8C, func_02012B98, func_02012BA4, func_02012BB0, func_02012BC8, func_02012BE0, func_02012BF8, func_02012C0C, func_02012C18, func_02012CE0, func_02012DAC, func_02012DD0, func_02012E08, sub_02012E40, func_02012E4C, func_02012E7C, sub_02012EBC, sub_02012EC0, sub_02012EC4, sub_02012ED0, sub_02012ED8, func_02012EE4, func_02012EF0, func_02012EFC, func_02012F08, func_02012F14, func_02012F20, func_02012F2C, func_02012F38, func_02012F44, func_02012F50, func_02012F5C, func_02012F68, func_02012F74, func_02012F80, func_02012F8C, func_02012F98, func_02012FA4, func_02012FB0, func_02012FBC, func_02012FCC, func_02012FD8, func_02012FE4, sub_02012FF0, sub_02012FFC, sub_02013020, sub_02013050, sub_02013080, func_02013090, func_020130B4, func_020130C4, sub_020130DC, func_02013128, func_0201313C, func_02013144, func_02013158, func_02013160, func_0201320C, func_02013220, func_02013234, func_02013270, func_02013284, func_0201333C, func_02013360, func_0201347C, func_020134F4
 * address:  0x02012914
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02008850  0x02008850  thumb
 *   func_020127A4         0x020127A4  thumb
 *   data_0209DFA8  0x0209DFA8  data  a2
 *   func_02008448  0x02008448  thumb
 *   func_02008450  0x02008450  thumb
 *   func_0200C40C  0x0200C40C  thumb
 *   func_0200C418  0x0200C418  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_020071E4  0x020071E4  thumb
 *   func_02008808  0x02008808  thumb
 *   func_020088B8  0x020088B8  thumb
 *   func_020071CC  0x020071CC  thumb
 *   func_0200EEAC  0x0200EEAC  thumb
 *   func_020127B8  0x020127B8  thumb
 *   func_0200BE6C  0x0200BE6C  thumb
 *   func_020127C4  0x020127C4  thumb
 *   func_0200A864  0x0200A864  thumb
 *   func_0200A884  0x0200A884  thumb
 *   func_0200B3C8  0x0200B3C8  thumb
 *   func_0200893C  0x0200893C  thumb
 *   func_02008954  0x02008954  thumb
 *   func_02009D08  0x02009D08  thumb
 *   func_020097F0  0x020097F0  thumb
 *   func_02008964  0x02008964  thumb
 *   func_0200E89C  0x0200E89C  thumb
 *   func_02008748  0x02008748  thumb
 *   func_0200863C  0x0200863C  thumb
 *   func_020087E8  0x020087E8  thumb
 *   func_02008860  0x02008860  thumb
 *   func_0200EE64  0x0200EE64  thumb
 *   func_0200BE54  0x0200BE54  thumb
 *   func_0200A870  0x0200A870  thumb
 *   func_0200B3B0  0x0200B3B0  thumb
 *   func_0200892C  0x0200892C  thumb
 *   func_0200894C  0x0200894C  thumb
 *   func_0200895C  0x0200895C  thumb
 *   func_0200E884  0x0200E884  thumb
 *   func_02008658  0x02008658  thumb
 *   sub_020071CC  0x020071CC  thumb
 *   func_02009EC8  0x02009EC8  thumb
 *   func_020089C0  0x020089C0  thumb
 *   func_02009448  0x02009448  thumb
 *   func_02007B44  0x02007B44  thumb
 *   ptr_020A7298  0x020A7298  data
 *   data_0209DFB0 0x0209DFB0  data
 *   sub_0200873C  0x0200873C  thumb
 *   sub_02008374  0x02008374  thumb
 *   sZonedataFile  0x020A729C  data
 *   func_0201AC2C  0x0201AC2C  thumb
 *   func_0200AE54   0x0200AE54  thumb
 *   func_0200B040   0x0200B040  thumb
 *   func_0201A2A8   0x0201A2A8  thumb
 *   func_0201A30C   0x0201A30C  thumb
 *   func_0201A920   0x0201A920  thumb
 *   func_0202A3FC   0x0202A3FC  thumb
 *   func_0202A440   0x0202A440  thumb
 *   func_0202A4B4   0x0202A4B4  thumb
 *   func_0216AAE4   0x0216AAE4  thumb
 *   func_0200873C   0x0200873C  thumb
 *   func_0200C0E8   0x0200C0E8  thumb
 *   func_0200C258   0x0200C258  thumb
 *   func_0200CA1C   0x0200CA1C  thumb
 *   func_020142E8   0x020142E8  thumb
 *   func_02082D44   0x02082D44  arm
 *   func_020076D0   0x020076D0  thumb
 *   func_0201AA14   0x0201AA14  thumb
 *   func_0201AA18   0x0201AA18  thumb
 */
#include "../../matched/include/Obj15629.h"
#include "../../matched/include/Obj15630.h"
#include "../../matched/include/Obj00054.h"
#include "../../matched/include/Obj11252.h"
#include "../../matched/include/Obj08745.h"
#include "../../matched/include/Obj16727.h"
#include "../../matched/include/Obj15631.h"
#include "../../matched/include/Obj17167.h"
#include "../../matched/include/Obj15637.h"
#include "../../matched/include/Obj15639.h"
#include "../../matched/include/Obj15640.h"
#include "../../matched/include/Obj15642.h"
#include "../../matched/include/Obj15643.h"
#include "../../matched/include/Obj01199.h"
#include "../../matched/include/Obj08746.h"
#include "../../matched/include/Obj04040.h"
#include "../../matched/include/Obj04041.h"
#include "../../matched/include/Obj15644.h"
#include "../../matched/include/Obj00155.h"
#include "../../matched/include/Obj00155.h"

struct Flags02008450;
struct Big;
struct PlayTime;
struct Rec2Head;
struct Rec94;
struct SaveBlock;
struct Sub020071E4Ctrl;
struct Sub020087E8Arg;
struct Sub02008828Obj;
struct Sub02008860Buf;
struct Sub020097BCObj;
struct BigObj;
struct Sub020071CCCtrl;
struct BigObj_0201283C;
struct Sub02007168;
struct Sub020089A8Obj;
struct Sub02009448Obj;
struct Sub02007AC8Entry;
struct Sub02008700Obj;
struct Rec534;
struct Reg;
struct RegAC;
struct U16Vec;
struct Out;
struct Party;
struct Blk34;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Rec1C {
    u32 v[7];
};

struct BigObj_0201283C {
    u8  unk000[0x158];
    u32 unk158;
    u32 unk15C;
    struct Rec1C *unk160;
    struct Rec1C *unk164;
    struct Rec1C *unk168;
    struct Rec1C *unk16C;
    struct Rec1C unk170;
    u8  unk18C[0x14];
    u32 unk1A0;
};

struct BigObj_02012914 {
    u8  unk000[0x15C];
    u32 unk15C;
};

typedef signed int     s32;

struct Vec12 {
    u32 x;
    u32 y;
    u32 z;
};

struct H4 {
    u16 v[4];
};

union U10 {
    struct H4 all;
    struct {
        u16 a;
        u8  b;
        u8  c;
        u16 d;
        u16 e;
    } f;
};

struct Rec44_0 {
    u16 unk00;
    u16 unk02;
    struct Vec12 unk04;
    union U10 unk10;
    u16 unk18;
    u8  unk1A;
    u8  unk1B;
    u16 unk1C;
    u8  unk1E[0x12];
    u32 unk30;
    u8  unk34[6];
    u8  unk3A;
    u8  unk3B;
    u8  unk3C;
    u8  unk3D;
    u8  unk3E[2];
    u32 unk40;
};

struct Sub24 {
    u8 unk00[0x24];
    struct Rec44_0 unk24[8];
};

struct BigObj {
    u8  unk000[0x18C];
    u32 unk18C;
    void *unk190;
    void *unk194;
    u32 unk198;
    u32 unk19C;
    u32 unk1A0;
    u32 unk1A4;
    u32 unk1A8;
    u32 unk1AC;
    u32 unk1B0;
    u32 unk1B4;
    u32 unk1B8;
    u32 unk1BC;
    u8  unk1C0[4];
    u8  unk1C4;
    u8  unk1C5;
    u8  unk1C6;
    u8  unk1C7;
    u8  unk1C8;
    u8  unk1C9;
    u8  unk1CA;
    u8  unk1CB;
    u8  unk1CC;
    u8  unk1CD;
    u8  unk1CE;
    u8  unk1CF;
    u8  unk1D0[0x414];
    u32 unk5E4;
    u8  unk5E8[0xA4];
    u32 unk68C;
    u32 unk690;
};

struct Rec44_1 {
    u8  unk00[0x18];
    u16 unk18;
    u8  unk1A;
    u8  unk1B;
    u16 unk1C;
    u8  unk1E[0x22];
    u32 unk40;
};

struct BigObj_02012AE4 {
    u8  unk000[0x198];
    void *unk198;
    u8  unk19C[0x1C];
    void *unk1B8;
    u8  unk1BC[0xC];
    u8  unk1C8;
    u8  unk1C9;
    u8  unk1CA;
    u8  unk1CB;
    u8  unk1CC;
    u8  unk1CD;
    u8  unk1CE;
    u8  unk1CF;
    u8  unk1D0[0x414];
};

struct BigObj_02012C0C {
    u8 unk000[0x5E8];
    u8 unk5E8[4];
};

typedef signed short s16;

typedef signed char s8;

struct Big {
    void *unk_00;
    u8   pad_04[0x5e8];
    u8   unk_5ec;
    u8   pad_5ed[0x93];
    u8   unk_680;
    u8   pad_681[7];
    void *unk_688;
};

typedef struct {
    char pad0[0x24];
    void *a24[4];
    void *a34[4];
    char pad1[4];
    void *a48[4];
    char pad2[0x3c];
    void *a94;
} S;

struct Obj {
    u32  unk00;
    u8   pad04[0x10];
    void *unk14;
    u8   pad18[0x18];
};

extern u16 *func_02008850(void *p);
extern u8 *func_020127A4(void *p);
extern unsigned int func_02008448(int a0);
extern void func_02008450(struct Flags02008450 *flags, int on);
extern void *func_0200C40C(void *p);
extern void func_0200C418(u8 *a, u32 id, u32 on);
extern void *func_02012EBC(struct Big *p);
extern u8 func_020071E4(const struct Sub020071E4Ctrl *ctrl);
extern void func_02008808(void *sys, struct Sub020087E8Arg *dest);
extern void func_020088B8(void *sys, struct Sub02008860Buf *dest);
extern void *func_020071CC(struct Sub020071CCCtrl *h, u32 id);
extern void func_0200EEAC(void *ctx, void *list);
extern void *func_020127B8(void *p);
extern void func_0200BE6C(void *sys, u16 *dest);
extern u8 *func_020127C4(void *p);
extern void *func_0200A864(void *sys);
extern void func_0200A884(const struct Rec2Head *src, struct Rec2Head *dest);
extern void func_0200B3C8(void *sys, const struct Rec94 *src);
extern void func_0200893C(const struct Sub02008828Obj *obj, void *dest);
extern void func_02008954(const struct Sub02008828Obj *obj, u8 *out);
extern struct Sub020097BCObj *func_02009D08(void *sys);
extern void func_020097F0(const struct Sub020097BCObj *src, struct Sub020097BCObj *dest);
extern void func_02008964(const struct Sub02008828Obj *obj, u8 *out);
extern void func_0200E89C(void *sys, void *dest);
extern struct PlayTime *func_02008748(void *sys);
extern void func_0200863C(struct PlayTime *dest, const struct PlayTime *src);
extern void func_020087E8(void *sys, const struct Sub020087E8Arg *src);
extern void func_02008860(void *sys, const struct Sub02008860Buf *src);
extern void func_0200EE64(u32 a0, u8 *a1);
extern void func_0200BE54(void *sys, const u16 *src);
extern void func_0200A870(struct Rec2Head *dest, const struct Rec2Head *src);
extern void func_0200B3B0(struct Rec94 *dest, void *sys);
extern void func_0200892C(struct Sub02008828Obj *obj, const void *src);
extern void func_0200894C(struct Sub02008828Obj *obj, u8 value);
extern void func_0200895C(struct Sub02008828Obj *obj, u8 value);
extern void func_0200E884(void *sys, void *src);
extern void func_02008658(struct PlayTime *p);
extern void func_0201042C(void);
extern void func_0203516C();
extern int func_02007150(void *a0);
extern int  func_02005C64(void);
extern u32 func_02007168(struct Sub02007168 *p);
extern int func_020351A0(u32 v);
extern void func_02010444(void);
extern int func_020071A8(int a0);
extern int  func_02034FE8(u32 a);
extern void func_02034FB8(u32 a);
extern void func_02034F84(int v);
extern void func_02007374(char *a0, u32 a1);
extern int func_020073B0(char *a0, u32 a1);
extern void *sub_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern void *func_0200C0F0(void *sys);
extern void *func_02009EC8(void *sys);
extern struct Sub020089A8Obj *func_020089C0(void *sys);
extern struct Sub02009448Obj *func_02009448(void *sys);
extern struct Sub02007AC8Entry *func_02007B44(void *sys);
extern u32 func_020085D4(u32 v, u32 x);
extern struct Sub02008700Obj *sub_0200873C(void *sys);
extern unsigned int sub_02008374(int a0);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *dst, int c, u32 n);
extern u32 sub_020307B0(void *p);
extern int sub_02013270(int a0);
extern void sub_02082BCC(void *p, int c, int n);
extern void func_0201AC2C(const struct Rec534 *src, struct Rec534 *dst);
extern u32 func_0200AE54(struct Reg *p, u32 id);
extern void func_0200B040(struct Reg *p, struct RegAC *out);
extern void func_0201A2A8(void *a0, void *a1);
extern void func_0201A30C(void *a0, void *a1, u32 c);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void  func_0202428C(void *p);
extern struct Party *func_0201A920(u32 heap);
extern void func_0202A440(u32 id, struct Out *out, u32 heap);
extern void func_0202A4B4(u32 a, u32 b, u32 c);
extern void func_0216AAE4(u32 a, u32 b, u32 c);
extern u8 func_0202A3FC(u32 key);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern void *func_0200C0E8(void *sys);
extern u32 func_0200C258(struct Blk34 *p);
extern void *func_0200CA1C(void *a);
extern u32 func_020142E8(void *bitmap, s32 id);
extern void func_02082D44(const void *src, void *dst, u32 n);
extern u32  func_0201AA18(void *p);
extern u32 func_0201AA14(void *p);
extern int func_020076D0(void *save, int *pbox, int *pslot);
u32 func_0201283C(const struct BigObj_0201283C *p);
u16 func_02012914(const struct BigObj_02012914 *p);
u32 func_02012924(const struct BigObj *p);
void *func_0201292C(const struct BigObj *p);
void *func_02012934(const struct BigObj *p);
u32 func_0201293C(const struct BigObj *p);
u8 *func_02012944(void *p);
struct Rec44_0 *func_02012950(struct Sub24 *p, u32 i);
u32 func_0201295C(const struct BigObj *p);
u32 func_02012964(const struct BigObj *p);
u32 func_0201296C(const struct BigObj *p);
u32 func_02012974(const struct BigObj *p);
u32 func_0201297C(const struct BigObj *p);
u8 func_02012984(const struct BigObj *p);
void func_0201298C(struct BigObj *p, u8 v);
u8 func_02012994(const struct BigObj *p);
void func_020129A0(struct BigObj *p, u8 v);
u8 func_020129AC(const struct BigObj *p);
void func_020129B8(struct BigObj *p, u32 v);
u8 func_020129C4(const struct BigObj *p);
void func_020129D0(struct BigObj *p, u8 v);
void func_020129DC(struct BigObj *p, u8 v);
void func_020129F0(struct BigObj *p);
u8 func_020129FC(struct BigObj *p);
u8 func_02012A24(const struct BigObj *p);
u32 func_02012A30(const struct BigObj *p);
u32 func_02012A38(const struct BigObj *p);
u32 func_02012A44(const struct BigObj *p);
void func_02012A4C(struct BigObj *p, u32 v);
u32 func_02012A54(const struct BigObj *p);
void func_02012A60(struct Rec44_0 *p);
void func_02012A90(struct Rec44_0 *p, const struct Vec12 *src);
struct Vec12 *func_02012AA0(struct Rec44_0 *p);
void func_02012AA4(struct Rec44_0 *p, const struct H4 *src);
struct H4 *func_02012AB8(struct Rec44_0 *p);
void func_02012ABC(struct Rec44_0 *p, u8 v);
u8 func_02012AC0(const struct Rec44_0 *p);
struct Rec44_0 *func_02012AC4(struct Rec44_0 *p, u16 v);
u16 func_02012AC8(const struct Rec44_0 *p);
void func_02012ACC(struct Rec44_0 *p, int v);
u16 func_02012AD0(const struct Rec44_0 *p);
void func_02012AD4(u8 *p, int i);
u32 func_02012AE4(const struct Rec44_1 *p);
u32 func_02012B28(const struct Rec44_1 *p);
void func_02012B2C(struct Rec44_1 *p, u32 v);
void func_02012B30(struct Rec44_1 *p, u16 v);
u16 func_02012B34(const struct Rec44_1 *p);
void *func_02012B38(const struct BigObj_02012AE4 *p);
u8 func_02012B40(const struct BigObj_02012AE4 *p);
void func_02012B4C(struct BigObj_02012AE4 *p, u8 v);
u8 func_02012B58(const struct BigObj_02012AE4 *p);
void func_02012B64(struct BigObj_02012AE4 *p, u8 v);
int func_02012B70(const struct BigObj_02012AE4 *p);
struct BigObj_02012AE4 *func_02012B78(struct BigObj_02012AE4 *p, u8 v);
u8 func_02012B80(const struct BigObj_02012AE4 *p);
void func_02012B8C(struct BigObj_02012AE4 *p, u32 v);
u8 func_02012B98(const struct BigObj_02012AE4 *p, u32 i);
void func_02012BA4(struct BigObj_02012AE4 *p, int i, u8 v);
u32 func_02012BB0(const struct BigObj_02012AE4 *p);
void func_02012BC8(u8 *p, int on);
void func_02012BE0(void *p, u32 a, u32 b);
int func_02012BF8(int a0, int a1);
u8 *func_02012C0C(struct BigObj_02012C0C *p);
void func_02012C18(u8 *p);
void func_02012CE0(u8 *p);
int func_02012DAC(u8 *p);
int func_02012DD0(u8 *p);
void func_02012E08(char *p);
u8 sub_02012E40(const u8 *o);
void func_02012E4C(u8 *p, u32 id);
int func_02012E7C(char *p, int a1);
void *sub_02012EBC(struct Big *p);
void *sub_02012EC0(struct Big *p);
u8 *sub_02012EC4(struct Big *p);
u8 *sub_02012ED0(struct Big *p);
void *sub_02012ED8(struct Big *p);
char *func_02012EE4(char *base, int v);
void *func_02012EF0(void **p);
void *func_02012EFC(void **p);
void *func_02012F08(int *p);
void *func_02012F14(void **h);
int func_02012F20(int p0);
void *func_02012F2C(int *p);
int func_02012F38(int base);
void *func_02012F44(void *p);
void *func_02012F50(void *base);
void *func_02012F5C(void **h);
void *func_02012F68(void **h);
void func_02012F74(void *h, void *w);
int func_02012F80(char *base);
u32 func_02012F8C(u32 *p);
struct Sub02007AC8Entry *func_02012F98(void *p);
void func_02012FA4(char *p, unsigned char v);
int func_02012FB0(unsigned char *base);
u32 func_02012FBC(u8 *p, u32 x);
int func_02012FCC(int p0);
void *func_02012FD8(void **p);
void *func_02012FE4(struct Sub020071CCCtrl *a0);
void sub_02012FF0(void *val);
signed char sub_02012FFC(void);
signed char sub_02013020(void);
signed char sub_02013050(void);
signed char sub_02013080(u32 idx);
void *func_02013090(u32 heap);
int func_020130B4(int a0);
void func_020130C4(u8 *p);
void sub_020130DC(S *p);
void func_02013128(void *p, void *src, int i);
void *func_0201313C(void *p, int i);
void func_02013144(char *p, int v);
int func_02013158(char *base, int m);
void func_02013160(u8 *o, void *a1, u32 a2);
void func_0201320C(int p0);
void func_02013220(char *p);
void *func_02013234(u32 heap);
int func_02013270(int a0);
void func_02013284(u8 *o, u32 *a1, u32 n, u32 *dst, u32 v, u32 h);
void func_0201333C(u8 *o, void *a1, int a2);
void func_02013360(u8 *o, void *a1, const void *a2);
void func_0201347C(u8 *a0, void *a1, u32 a2, u32 a3, u32 a4, u16 a5);
void func_020134F4(u8 *p, u32 a1, u32 a2, u32 a3, u16 h);
extern const u16 data_0209DFA8[];
extern void *ptr_020A7298;
extern const signed char data_0209DFB0[];
extern u8    sZonedataFile;


/*
 * Sixteen bytes.  The other half of the cut described in the header of
 * src/matched/unit_0201283C.c: this call site and the one at 0x0201290A are
 * the only two references to func_02008850 in the image, so they have to sit
 * in different ranges for either of them to be attested.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012914.c \
 *       --addr 0x02012914 --thumb
 */
u16 func_02012914(const struct BigObj_02012914 *p)
{
    return *func_02008850((void *)p->unk15C);
}


/*
 *           func_02012944, func_02012950, func_0201295C, func_02012964,
 *           func_0201296C, func_02012974, func_0201297C, func_02012984,
 *           func_0201298C, func_02012994, func_020129A0, func_020129AC,
 *           func_020129B8, func_020129C4, func_020129D0, func_020129DC,
 *           func_020129F0, func_020129FC, func_02012A24, func_02012A30,
 *           func_02012A38, func_02012A44, func_02012A4C, func_02012A54,
 *           func_02012A60, func_02012A90, func_02012AA0, func_02012AA4,
 *           func_02012AB8, func_02012ABC, func_02012AC0, func_02012AC4,
 *           func_02012AC8, func_02012ACC, func_02012AD0
 *
 * 432 bytes, 0x02012924..0x02012AD4, 39 functions, only nine of which carry a
 * label in the generated listing: the rest are leaf accessors that save no lr
 * and arrive in asm/arm9/src/004_02010BB8.s as runs of .word, which is
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Two objects are accessed here and they are not the same struct.
 *
 *  - BigObj is reached through a plain pointer argument and every field this
 *    file touches is past +0x18C, so each access is a register offset built
 *    with movs/lsls (0x63 << 2 is +0x18C) or, where the constant is not of
 *    that shape, out of the function's own literal pool (+0x1C5 .. +0x1CD).
 *    Those pool words are plain constants and carry no relocation.
 *  - Rec44 is the 0x44-byte record func_02012950 indexes, and func_02012A60
 *    onwards are its constructor and accessors.  func_02012A60 is the
 *    constructor: its store order is the source's statement order, and the
 *    two strb at +0x12 and +0x13 next to the strh at +0x10, +0x14 and +0x16
 *    are what make +0x10 a union of a four-halfword view (the one
 *    func_02012AA4 copies whole) and a five-field view.
 *
 * func_020129FC is a post-increment and not an assignment:
 * `return p->unk1C8++;` spends an extra `adds r1, r4, #0` copy that
 * `n = p->unk1C8; p->unk1C8 = n + 1; return n;` does not, and the two are
 * otherwise the same eighteen instructions.  See
 * docs/idioms/post-increment-of-a-field-spends-a-copy.md.
 *
 * The file stops at 0x02012AD4 because func_02012AD4 cannot be attested; see
 * the header of src/matched/unit_02012AE4.c for that near miss.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table, so none of it looks version specific.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012924.c \
 *       --addr 0x02012924 --thumb
 */
u32 func_02012924(const struct BigObj *p)
{
    return p->unk18C;
}


/*
 *           func_02012944, func_02012950, func_0201295C, func_02012964,
 *           func_0201296C, func_02012974, func_0201297C, func_02012984,
 *           func_0201298C, func_02012994, func_020129A0, func_020129AC,
 *           func_020129B8, func_020129C4, func_020129D0, func_020129DC,
 *           func_020129F0, func_020129FC, func_02012A24, func_02012A30,
 *           func_02012A38, func_02012A44, func_02012A4C, func_02012A54,
 *           func_02012A60, func_02012A90, func_02012AA0, func_02012AA4,
 *           func_02012AB8, func_02012ABC, func_02012AC0, func_02012AC4,
 *           func_02012AC8, func_02012ACC, func_02012AD0
 *
 * 432 bytes, 0x02012924..0x02012AD4, 39 functions, only nine of which carry a
 * label in the generated listing: the rest are leaf accessors that save no lr
 * and arrive in asm/arm9/src/004_02010BB8.s as runs of .word, which is
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Two objects are accessed here and they are not the same struct.
 *
 *  - BigObj is reached through a plain pointer argument and every field this
 *    file touches is past +0x18C, so each access is a register offset built
 *    with movs/lsls (0x63 << 2 is +0x18C) or, where the constant is not of
 *    that shape, out of the function's own literal pool (+0x1C5 .. +0x1CD).
 *    Those pool words are plain constants and carry no relocation.
 *  - Rec44 is the 0x44-byte record func_02012950 indexes, and func_02012A60
 *    onwards are its constructor and accessors.  func_02012A60 is the
 *    constructor: its store order is the source's statement order, and the
 *    two strb at +0x12 and +0x13 next to the strh at +0x10, +0x14 and +0x16
 *    are what make +0x10 a union of a four-halfword view (the one
 *    func_02012AA4 copies whole) and a five-field view.
 *
 * func_020129FC is a post-increment and not an assignment:
 * `return p->unk1C8++;` spends an extra `adds r1, r4, #0` copy that
 * `n = p->unk1C8; p->unk1C8 = n + 1; return n;` does not, and the two are
 * otherwise the same eighteen instructions.  See
 * docs/idioms/post-increment-of-a-field-spends-a-copy.md.
 *
 * The file stops at 0x02012AD4 because func_02012AD4 cannot be attested; see
 * the header of src/matched/unit_02012AE4.c for that near miss.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table, so none of it looks version specific.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012924.c \
 *       --addr 0x02012924 --thumb
 */
void *func_0201292C(const struct BigObj *p)
{
    return p->unk190;
}


/*
 *           func_02012944, func_02012950, func_0201295C, func_02012964,
 *           func_0201296C, func_02012974, func_0201297C, func_02012984,
 *           func_0201298C, func_02012994, func_020129A0, func_020129AC,
 *           func_020129B8, func_020129C4, func_020129D0, func_020129DC,
 *           func_020129F0, func_020129FC, func_02012A24, func_02012A30,
 *           func_02012A38, func_02012A44, func_02012A4C, func_02012A54,
 *           func_02012A60, func_02012A90, func_02012AA0, func_02012AA4,
 *           func_02012AB8, func_02012ABC, func_02012AC0, func_02012AC4,
 *           func_02012AC8, func_02012ACC, func_02012AD0
 *
 * 432 bytes, 0x02012924..0x02012AD4, 39 functions, only nine of which carry a
 * label in the generated listing: the rest are leaf accessors that save no lr
 * and arrive in asm/arm9/src/004_02010BB8.s as runs of .word, which is
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Two objects are accessed here and they are not the same struct.
 *
 *  - BigObj is reached through a plain pointer argument and every field this
 *    file touches is past +0x18C, so each access is a register offset built
 *    with movs/lsls (0x63 << 2 is +0x18C) or, where the constant is not of
 *    that shape, out of the function's own literal pool (+0x1C5 .. +0x1CD).
 *    Those pool words are plain constants and carry no relocation.
 *  - Rec44 is the 0x44-byte record func_02012950 indexes, and func_02012A60
 *    onwards are its constructor and accessors.  func_02012A60 is the
 *    constructor: its store order is the source's statement order, and the
 *    two strb at +0x12 and +0x13 next to the strh at +0x10, +0x14 and +0x16
 *    are what make +0x10 a union of a four-halfword view (the one
 *    func_02012AA4 copies whole) and a five-field view.
 *
 * func_020129FC is a post-increment and not an assignment:
 * `return p->unk1C8++;` spends an extra `adds r1, r4, #0` copy that
 * `n = p->unk1C8; p->unk1C8 = n + 1; return n;` does not, and the two are
 * otherwise the same eighteen instructions.  See
 * docs/idioms/post-increment-of-a-field-spends-a-copy.md.
 *
 * The file stops at 0x02012AD4 because func_02012AD4 cannot be attested; see
 * the header of src/matched/unit_02012AE4.c for that near miss.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table, so none of it looks version specific.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012924.c \
 *       --addr 0x02012924 --thumb
 */
void *func_02012934(const struct BigObj *p)
{
    return p->unk194;
}


/*
 *           func_02012944, func_02012950, func_0201295C, func_02012964,
 *           func_0201296C, func_02012974, func_0201297C, func_02012984,
 *           func_0201298C, func_02012994, func_020129A0, func_020129AC,
 *           func_020129B8, func_020129C4, func_020129D0, func_020129DC,
 *           func_020129F0, func_020129FC, func_02012A24, func_02012A30,
 *           func_02012A38, func_02012A44, func_02012A4C, func_02012A54,
 *           func_02012A60, func_02012A90, func_02012AA0, func_02012AA4,
 *           func_02012AB8, func_02012ABC, func_02012AC0, func_02012AC4,
 *           func_02012AC8, func_02012ACC, func_02012AD0
 *
 * 432 bytes, 0x02012924..0x02012AD4, 39 functions, only nine of which carry a
 * label in the generated listing: the rest are leaf accessors that save no lr
 * and arrive in asm/arm9/src/004_02010BB8.s as runs of .word, which is
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Two objects are accessed here and they are not the same struct.
 *
 *  - BigObj is reached through a plain pointer argument and every field this
 *    file touches is past +0x18C, so each access is a register offset built
 *    with movs/lsls (0x63 << 2 is +0x18C) or, where the constant is not of
 *    that shape, out of the function's own literal pool (+0x1C5 .. +0x1CD).
 *    Those pool words are plain constants and carry no relocation.
 *  - Rec44 is the 0x44-byte record func_02012950 indexes, and func_02012A60
 *    onwards are its constructor and accessors.  func_02012A60 is the
 *    constructor: its store order is the source's statement order, and the
 *    two strb at +0x12 and +0x13 next to the strh at +0x10, +0x14 and +0x16
 *    are what make +0x10 a union of a four-halfword view (the one
 *    func_02012AA4 copies whole) and a five-field view.
 *
 * func_020129FC is a post-increment and not an assignment:
 * `return p->unk1C8++;` spends an extra `adds r1, r4, #0` copy that
 * `n = p->unk1C8; p->unk1C8 = n + 1; return n;` does not, and the two are
 * otherwise the same eighteen instructions.  See
 * docs/idioms/post-increment-of-a-field-spends-a-copy.md.
 *
 * The file stops at 0x02012AD4 because func_02012AD4 cannot be attested; see
 * the header of src/matched/unit_02012AE4.c for that near miss.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table, so none of it looks version specific.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012924.c \
 *       --addr 0x02012924 --thumb
 */
u32 func_0201293C(const struct BigObj *p)
{
    return p->unk19C;
}


/*
 *           func_02012944, func_02012950, func_0201295C, func_02012964,
 *           func_0201296C, func_02012974, func_0201297C, func_02012984,
 *           func_0201298C, func_02012994, func_020129A0, func_020129AC,
 *           func_020129B8, func_020129C4, func_020129D0, func_020129DC,
 *           func_020129F0, func_020129FC, func_02012A24, func_02012A30,
 *           func_02012A38, func_02012A44, func_02012A4C, func_02012A54,
 *           func_02012A60, func_02012A90, func_02012AA0, func_02012AA4,
 *           func_02012AB8, func_02012ABC, func_02012AC0, func_02012AC4,
 *           func_02012AC8, func_02012ACC, func_02012AD0
 *
 * 432 bytes, 0x02012924..0x02012AD4, 39 functions, only nine of which carry a
 * label in the generated listing: the rest are leaf accessors that save no lr
 * and arrive in asm/arm9/src/004_02010BB8.s as runs of .word, which is
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Two objects are accessed here and they are not the same struct.
 *
 *  - BigObj is reached through a plain pointer argument and every field this
 *    file touches is past +0x18C, so each access is a register offset built
 *    with movs/lsls (0x63 << 2 is +0x18C) or, where the constant is not of
 *    that shape, out of the function's own literal pool (+0x1C5 .. +0x1CD).
 *    Those pool words are plain constants and carry no relocation.
 *  - Rec44 is the 0x44-byte record func_02012950 indexes, and func_02012A60
 *    onwards are its constructor and accessors.  func_02012A60 is the
 *    constructor: its store order is the source's statement order, and the
 *    two strb at +0x12 and +0x13 next to the strh at +0x10, +0x14 and +0x16
 *    are what make +0x10 a union of a four-halfword view (the one
 *    func_02012AA4 copies whole) and a five-field view.
 *
 * func_020129FC is a post-increment and not an assignment:
 * `return p->unk1C8++;` spends an extra `adds r1, r4, #0` copy that
 * `n = p->unk1C8; p->unk1C8 = n + 1; return n;` does not, and the two are
 * otherwise the same eighteen instructions.  See
 * docs/idioms/post-increment-of-a-field-spends-a-copy.md.
 *
 * The file stops at 0x02012AD4 because func_02012AD4 cannot be attested; see
 * the header of src/matched/unit_02012AE4.c for that near miss.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table, so none of it looks version specific.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012924.c \
 *       --addr 0x02012924 --thumb
 */
u8 *func_02012944(void *p)
{
    return func_020127A4(p) + 0x20;
}


/*
 *           func_02012944, func_02012950, func_0201295C, func_02012964,
 *           func_0201296C, func_02012974, func_0201297C, func_02012984,
 *           func_0201298C, func_02012994, func_020129A0, func_020129AC,
 *           func_020129B8, func_020129C4, func_020129D0, func_020129DC,
 *           func_020129F0, func_020129FC, func_02012A24, func_02012A30,
 *           func_02012A38, func_02012A44, func_02012A4C, func_02012A54,
 *           func_02012A60, func_02012A90, func_02012AA0, func_02012AA4,
 *           func_02012AB8, func_02012ABC, func_02012AC0, func_02012AC4,
 *           func_02012AC8, func_02012ACC, func_02012AD0
 *
 * 432 bytes, 0x02012924..0x02012AD4, 39 functions, only nine of which carry a
 * label in the generated listing: the rest are leaf accessors that save no lr
 * and arrive in asm/arm9/src/004_02010BB8.s as runs of .word, which is
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Two objects are accessed here and they are not the same struct.
 *
 *  - BigObj is reached through a plain pointer argument and every field this
 *    file touches is past +0x18C, so each access is a register offset built
 *    with movs/lsls (0x63 << 2 is +0x18C) or, where the constant is not of
 *    that shape, out of the function's own literal pool (+0x1C5 .. +0x1CD).
 *    Those pool words are plain constants and carry no relocation.
 *  - Rec44 is the 0x44-byte record func_02012950 indexes, and func_02012A60
 *    onwards are its constructor and accessors.  func_02012A60 is the
 *    constructor: its store order is the source's statement order, and the
 *    two strb at +0x12 and +0x13 next to the strh at +0x10, +0x14 and +0x16
 *    are what make +0x10 a union of a four-halfword view (the one
 *    func_02012AA4 copies whole) and a five-field view.
 *
 * func_020129FC is a post-increment and not an assignment:
 * `return p->unk1C8++;` spends an extra `adds r1, r4, #0` copy that
 * `n = p->unk1C8; p->unk1C8 = n + 1; return n;` does not, and the two are
 * otherwise the same eighteen instructions.  See
 * docs/idioms/post-increment-of-a-field-spends-a-copy.md.
 *
 * The file stops at 0x02012AD4 because func_02012AD4 cannot be attested; see
 * the header of src/matched/unit_02012AE4.c for that near miss.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table, so none of it looks version specific.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012924.c \
 *       --addr 0x02012924 --thumb
 */
struct Rec44_0 *func_02012950(struct Sub24 *p, u32 i)
{
    return &p->unk24[i];
}


/*
 *           func_02012944, func_02012950, func_0201295C, func_02012964,
 *           func_0201296C, func_02012974, func_0201297C, func_02012984,
 *           func_0201298C, func_02012994, func_020129A0, func_020129AC,
 *           func_020129B8, func_020129C4, func_020129D0, func_020129DC,
 *           func_020129F0, func_020129FC, func_02012A24, func_02012A30,
 *           func_02012A38, func_02012A44, func_02012A4C, func_02012A54,
 *           func_02012A60, func_02012A90, func_02012AA0, func_02012AA4,
 *           func_02012AB8, func_02012ABC, func_02012AC0, func_02012AC4,
 *           func_02012AC8, func_02012ACC, func_02012AD0
 *
 * 432 bytes, 0x02012924..0x02012AD4, 39 functions, only nine of which carry a
 * label in the generated listing: the rest are leaf accessors that save no lr
 * and arrive in asm/arm9/src/004_02010BB8.s as runs of .word, which is
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Two objects are accessed here and they are not the same struct.
 *
 *  - BigObj is reached through a plain pointer argument and every field this
 *    file touches is past +0x18C, so each access is a register offset built
 *    with movs/lsls (0x63 << 2 is +0x18C) or, where the constant is not of
 *    that shape, out of the function's own literal pool (+0x1C5 .. +0x1CD).
 *    Those pool words are plain constants and carry no relocation.
 *  - Rec44 is the 0x44-byte record func_02012950 indexes, and func_02012A60
 *    onwards are its constructor and accessors.  func_02012A60 is the
 *    constructor: its store order is the source's statement order, and the
 *    two strb at +0x12 and +0x13 next to the strh at +0x10, +0x14 and +0x16
 *    are what make +0x10 a union of a four-halfword view (the one
 *    func_02012AA4 copies whole) and a five-field view.
 *
 * func_020129FC is a post-increment and not an assignment:
 * `return p->unk1C8++;` spends an extra `adds r1, r4, #0` copy that
 * `n = p->unk1C8; p->unk1C8 = n + 1; return n;` does not, and the two are
 * otherwise the same eighteen instructions.  See
 * docs/idioms/post-increment-of-a-field-spends-a-copy.md.
 *
 * The file stops at 0x02012AD4 because func_02012AD4 cannot be attested; see
 * the header of src/matched/unit_02012AE4.c for that near miss.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table, so none of it looks version specific.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012924.c \
 *       --addr 0x02012924 --thumb
 */
u32 func_0201295C(const struct BigObj *p)
{
    return p->unk1A4;
}


/*
 *           func_02012944, func_02012950, func_0201295C, func_02012964,
 *           func_0201296C, func_02012974, func_0201297C, func_02012984,
 *           func_0201298C, func_02012994, func_020129A0, func_020129AC,
 *           func_020129B8, func_020129C4, func_020129D0, func_020129DC,
 *           func_020129F0, func_020129FC, func_02012A24, func_02012A30,
 *           func_02012A38, func_02012A44, func_02012A4C, func_02012A54,
 *           func_02012A60, func_02012A90, func_02012AA0, func_02012AA4,
 *           func_02012AB8, func_02012ABC, func_02012AC0, func_02012AC4,
 *           func_02012AC8, func_02012ACC, func_02012AD0
 *
 * 432 bytes, 0x02012924..0x02012AD4, 39 functions, only nine of which carry a
 * label in the generated listing: the rest are leaf accessors that save no lr
 * and arrive in asm/arm9/src/004_02010BB8.s as runs of .word, which is
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Two objects are accessed here and they are not the same struct.
 *
 *  - BigObj is reached through a plain pointer argument and every field this
 *    file touches is past +0x18C, so each access is a register offset built
 *    with movs/lsls (0x63 << 2 is +0x18C) or, where the constant is not of
 *    that shape, out of the function's own literal pool (+0x1C5 .. +0x1CD).
 *    Those pool words are plain constants and carry no relocation.
 *  - Rec44 is the 0x44-byte record func_02012950 indexes, and func_02012A60
 *    onwards are its constructor and accessors.  func_02012A60 is the
 *    constructor: its store order is the source's statement order, and the
 *    two strb at +0x12 and +0x13 next to the strh at +0x10, +0x14 and +0x16
 *    are what make +0x10 a union of a four-halfword view (the one
 *    func_02012AA4 copies whole) and a five-field view.
 *
 * func_020129FC is a post-increment and not an assignment:
 * `return p->unk1C8++;` spends an extra `adds r1, r4, #0` copy that
 * `n = p->unk1C8; p->unk1C8 = n + 1; return n;` does not, and the two are
 * otherwise the same eighteen instructions.  See
 * docs/idioms/post-increment-of-a-field-spends-a-copy.md.
 *
 * The file stops at 0x02012AD4 because func_02012AD4 cannot be attested; see
 * the header of src/matched/unit_02012AE4.c for that near miss.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table, so none of it looks version specific.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012924.c \
 *       --addr 0x02012924 --thumb
 */
u32 func_02012964(const struct BigObj *p)
{
    return p->unk1A8;
}


/*
 *           func_02012944, func_02012950, func_0201295C, func_02012964,
 *           func_0201296C, func_02012974, func_0201297C, func_02012984,
 *           func_0201298C, func_02012994, func_020129A0, func_020129AC,
 *           func_020129B8, func_020129C4, func_020129D0, func_020129DC,
 *           func_020129F0, func_020129FC, func_02012A24, func_02012A30,
 *           func_02012A38, func_02012A44, func_02012A4C, func_02012A54,
 *           func_02012A60, func_02012A90, func_02012AA0, func_02012AA4,
 *           func_02012AB8, func_02012ABC, func_02012AC0, func_02012AC4,
 *           func_02012AC8, func_02012ACC, func_02012AD0
 *
 * 432 bytes, 0x02012924..0x02012AD4, 39 functions, only nine of which carry a
 * label in the generated listing: the rest are leaf accessors that save no lr
 * and arrive in asm/arm9/src/004_02010BB8.s as runs of .word, which is
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Two objects are accessed here and they are not the same struct.
 *
 *  - BigObj is reached through a plain pointer argument and every field this
 *    file touches is past +0x18C, so each access is a register offset built
 *    with movs/lsls (0x63 << 2 is +0x18C) or, where the constant is not of
 *    that shape, out of the function's own literal pool (+0x1C5 .. +0x1CD).
 *    Those pool words are plain constants and carry no relocation.
 *  - Rec44 is the 0x44-byte record func_02012950 indexes, and func_02012A60
 *    onwards are its constructor and accessors.  func_02012A60 is the
 *    constructor: its store order is the source's statement order, and the
 *    two strb at +0x12 and +0x13 next to the strh at +0x10, +0x14 and +0x16
 *    are what make +0x10 a union of a four-halfword view (the one
 *    func_02012AA4 copies whole) and a five-field view.
 *
 * func_020129FC is a post-increment and not an assignment:
 * `return p->unk1C8++;` spends an extra `adds r1, r4, #0` copy that
 * `n = p->unk1C8; p->unk1C8 = n + 1; return n;` does not, and the two are
 * otherwise the same eighteen instructions.  See
 * docs/idioms/post-increment-of-a-field-spends-a-copy.md.
 *
 * The file stops at 0x02012AD4 because func_02012AD4 cannot be attested; see
 * the header of src/matched/unit_02012AE4.c for that near miss.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table, so none of it looks version specific.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012924.c \
 *       --addr 0x02012924 --thumb
 */
u32 func_0201296C(const struct BigObj *p)
{
    return p->unk1AC;
}


/*
 *           func_02012944, func_02012950, func_0201295C, func_02012964,
 *           func_0201296C, func_02012974, func_0201297C, func_02012984,
 *           func_0201298C, func_02012994, func_020129A0, func_020129AC,
 *           func_020129B8, func_020129C4, func_020129D0, func_020129DC,
 *           func_020129F0, func_020129FC, func_02012A24, func_02012A30,
 *           func_02012A38, func_02012A44, func_02012A4C, func_02012A54,
 *           func_02012A60, func_02012A90, func_02012AA0, func_02012AA4,
 *           func_02012AB8, func_02012ABC, func_02012AC0, func_02012AC4,
 *           func_02012AC8, func_02012ACC, func_02012AD0
 *
 * 432 bytes, 0x02012924..0x02012AD4, 39 functions, only nine of which carry a
 * label in the generated listing: the rest are leaf accessors that save no lr
 * and arrive in asm/arm9/src/004_02010BB8.s as runs of .word, which is
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Two objects are accessed here and they are not the same struct.
 *
 *  - BigObj is reached through a plain pointer argument and every field this
 *    file touches is past +0x18C, so each access is a register offset built
 *    with movs/lsls (0x63 << 2 is +0x18C) or, where the constant is not of
 *    that shape, out of the function's own literal pool (+0x1C5 .. +0x1CD).
 *    Those pool words are plain constants and carry no relocation.
 *  - Rec44 is the 0x44-byte record func_02012950 indexes, and func_02012A60
 *    onwards are its constructor and accessors.  func_02012A60 is the
 *    constructor: its store order is the source's statement order, and the
 *    two strb at +0x12 and +0x13 next to the strh at +0x10, +0x14 and +0x16
 *    are what make +0x10 a union of a four-halfword view (the one
 *    func_02012AA4 copies whole) and a five-field view.
 *
 * func_020129FC is a post-increment and not an assignment:
 * `return p->unk1C8++;` spends an extra `adds r1, r4, #0` copy that
 * `n = p->unk1C8; p->unk1C8 = n + 1; return n;` does not, and the two are
 * otherwise the same eighteen instructions.  See
 * docs/idioms/post-increment-of-a-field-spends-a-copy.md.
 *
 * The file stops at 0x02012AD4 because func_02012AD4 cannot be attested; see
 * the header of src/matched/unit_02012AE4.c for that near miss.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table, so none of it looks version specific.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012924.c \
 *       --addr 0x02012924 --thumb
 */
u32 func_02012974(const struct BigObj *p)
{
    return p->unk1B0;
}


/*
 *           func_02012944, func_02012950, func_0201295C, func_02012964,
 *           func_0201296C, func_02012974, func_0201297C, func_02012984,
 *           func_0201298C, func_02012994, func_020129A0, func_020129AC,
 *           func_020129B8, func_020129C4, func_020129D0, func_020129DC,
 *           func_020129F0, func_020129FC, func_02012A24, func_02012A30,
 *           func_02012A38, func_02012A44, func_02012A4C, func_02012A54,
 *           func_02012A60, func_02012A90, func_02012AA0, func_02012AA4,
 *           func_02012AB8, func_02012ABC, func_02012AC0, func_02012AC4,
 *           func_02012AC8, func_02012ACC, func_02012AD0
 *
 * 432 bytes, 0x02012924..0x02012AD4, 39 functions, only nine of which carry a
 * label in the generated listing: the rest are leaf accessors that save no lr
 * and arrive in asm/arm9/src/004_02010BB8.s as runs of .word, which is
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Two objects are accessed here and they are not the same struct.
 *
 *  - BigObj is reached through a plain pointer argument and every field this
 *    file touches is past +0x18C, so each access is a register offset built
 *    with movs/lsls (0x63 << 2 is +0x18C) or, where the constant is not of
 *    that shape, out of the function's own literal pool (+0x1C5 .. +0x1CD).
 *    Those pool words are plain constants and carry no relocation.
 *  - Rec44 is the 0x44-byte record func_02012950 indexes, and func_02012A60
 *    onwards are its constructor and accessors.  func_02012A60 is the
 *    constructor: its store order is the source's statement order, and the
 *    two strb at +0x12 and +0x13 next to the strh at +0x10, +0x14 and +0x16
 *    are what make +0x10 a union of a four-halfword view (the one
 *    func_02012AA4 copies whole) and a five-field view.
 *
 * func_020129FC is a post-increment and not an assignment:
 * `return p->unk1C8++;` spends an extra `adds r1, r4, #0` copy that
 * `n = p->unk1C8; p->unk1C8 = n + 1; return n;` does not, and the two are
 * otherwise the same eighteen instructions.  See
 * docs/idioms/post-increment-of-a-field-spends-a-copy.md.
 *
 * The file stops at 0x02012AD4 because func_02012AD4 cannot be attested; see
 * the header of src/matched/unit_02012AE4.c for that near miss.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table, so none of it looks version specific.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012924.c \
 *       --addr 0x02012924 --thumb
 */
u32 func_0201297C(const struct BigObj *p)
{
    return p->unk690;
}


/*
 *           func_02012944, func_02012950, func_0201295C, func_02012964,
 *           func_0201296C, func_02012974, func_0201297C, func_02012984,
 *           func_0201298C, func_02012994, func_020129A0, func_020129AC,
 *           func_020129B8, func_020129C4, func_020129D0, func_020129DC,
 *           func_020129F0, func_020129FC, func_02012A24, func_02012A30,
 *           func_02012A38, func_02012A44, func_02012A4C, func_02012A54,
 *           func_02012A60, func_02012A90, func_02012AA0, func_02012AA4,
 *           func_02012AB8, func_02012ABC, func_02012AC0, func_02012AC4,
 *           func_02012AC8, func_02012ACC, func_02012AD0
 *
 * 432 bytes, 0x02012924..0x02012AD4, 39 functions, only nine of which carry a
 * label in the generated listing: the rest are leaf accessors that save no lr
 * and arrive in asm/arm9/src/004_02010BB8.s as runs of .word, which is
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Two objects are accessed here and they are not the same struct.
 *
 *  - BigObj is reached through a plain pointer argument and every field this
 *    file touches is past +0x18C, so each access is a register offset built
 *    with movs/lsls (0x63 << 2 is +0x18C) or, where the constant is not of
 *    that shape, out of the function's own literal pool (+0x1C5 .. +0x1CD).
 *    Those pool words are plain constants and carry no relocation.
 *  - Rec44 is the 0x44-byte record func_02012950 indexes, and func_02012A60
 *    onwards are its constructor and accessors.  func_02012A60 is the
 *    constructor: its store order is the source's statement order, and the
 *    two strb at +0x12 and +0x13 next to the strh at +0x10, +0x14 and +0x16
 *    are what make +0x10 a union of a four-halfword view (the one
 *    func_02012AA4 copies whole) and a five-field view.
 *
 * func_020129FC is a post-increment and not an assignment:
 * `return p->unk1C8++;` spends an extra `adds r1, r4, #0` copy that
 * `n = p->unk1C8; p->unk1C8 = n + 1; return n;` does not, and the two are
 * otherwise the same eighteen instructions.  See
 * docs/idioms/post-increment-of-a-field-spends-a-copy.md.
 *
 * The file stops at 0x02012AD4 because func_02012AD4 cannot be attested; see
 * the header of src/matched/unit_02012AE4.c for that near miss.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table, so none of it looks version specific.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012924.c \
 *       --addr 0x02012924 --thumb
 */
u8 func_02012984(const struct BigObj *p)
{
    return p->unk1C4;
}


/*
 *           func_02012944, func_02012950, func_0201295C, func_02012964,
 *           func_0201296C, func_02012974, func_0201297C, func_02012984,
 *           func_0201298C, func_02012994, func_020129A0, func_020129AC,
 *           func_020129B8, func_020129C4, func_020129D0, func_020129DC,
 *           func_020129F0, func_020129FC, func_02012A24, func_02012A30,
 *           func_02012A38, func_02012A44, func_02012A4C, func_02012A54,
 *           func_02012A60, func_02012A90, func_02012AA0, func_02012AA4,
 *           func_02012AB8, func_02012ABC, func_02012AC0, func_02012AC4,
 *           func_02012AC8, func_02012ACC, func_02012AD0
 *
 * 432 bytes, 0x02012924..0x02012AD4, 39 functions, only nine of which carry a
 * label in the generated listing: the rest are leaf accessors that save no lr
 * and arrive in asm/arm9/src/004_02010BB8.s as runs of .word, which is
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Two objects are accessed here and they are not the same struct.
 *
 *  - BigObj is reached through a plain pointer argument and every field this
 *    file touches is past +0x18C, so each access is a register offset built
 *    with movs/lsls (0x63 << 2 is +0x18C) or, where the constant is not of
 *    that shape, out of the function's own literal pool (+0x1C5 .. +0x1CD).
 *    Those pool words are plain constants and carry no relocation.
 *  - Rec44 is the 0x44-byte record func_02012950 indexes, and func_02012A60
 *    onwards are its constructor and accessors.  func_02012A60 is the
 *    constructor: its store order is the source's statement order, and the
 *    two strb at +0x12 and +0x13 next to the strh at +0x10, +0x14 and +0x16
 *    are what make +0x10 a union of a four-halfword view (the one
 *    func_02012AA4 copies whole) and a five-field view.
 *
 * func_020129FC is a post-increment and not an assignment:
 * `return p->unk1C8++;` spends an extra `adds r1, r4, #0` copy that
 * `n = p->unk1C8; p->unk1C8 = n + 1; return n;` does not, and the two are
 * otherwise the same eighteen instructions.  See
 * docs/idioms/post-increment-of-a-field-spends-a-copy.md.
 *
 * The file stops at 0x02012AD4 because func_02012AD4 cannot be attested; see
 * the header of src/matched/unit_02012AE4.c for that near miss.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table, so none of it looks version specific.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012924.c \
 *       --addr 0x02012924 --thumb
 */
void func_0201298C(struct BigObj *p, u8 v)
{
    p->unk1C4 = v;
}


/*
 *           func_02012944, func_02012950, func_0201295C, func_02012964,
 *           func_0201296C, func_02012974, func_0201297C, func_02012984,
 *           func_0201298C, func_02012994, func_020129A0, func_020129AC,
 *           func_020129B8, func_020129C4, func_020129D0, func_020129DC,
 *           func_020129F0, func_020129FC, func_02012A24, func_02012A30,
 *           func_02012A38, func_02012A44, func_02012A4C, func_02012A54,
 *           func_02012A60, func_02012A90, func_02012AA0, func_02012AA4,
 *           func_02012AB8, func_02012ABC, func_02012AC0, func_02012AC4,
 *           func_02012AC8, func_02012ACC, func_02012AD0
 *
 * 432 bytes, 0x02012924..0x02012AD4, 39 functions, only nine of which carry a
 * label in the generated listing: the rest are leaf accessors that save no lr
 * and arrive in asm/arm9/src/004_02010BB8.s as runs of .word, which is
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Two objects are accessed here and they are not the same struct.
 *
 *  - BigObj is reached through a plain pointer argument and every field this
 *    file touches is past +0x18C, so each access is a register offset built
 *    with movs/lsls (0x63 << 2 is +0x18C) or, where the constant is not of
 *    that shape, out of the function's own literal pool (+0x1C5 .. +0x1CD).
 *    Those pool words are plain constants and carry no relocation.
 *  - Rec44 is the 0x44-byte record func_02012950 indexes, and func_02012A60
 *    onwards are its constructor and accessors.  func_02012A60 is the
 *    constructor: its store order is the source's statement order, and the
 *    two strb at +0x12 and +0x13 next to the strh at +0x10, +0x14 and +0x16
 *    are what make +0x10 a union of a four-halfword view (the one
 *    func_02012AA4 copies whole) and a five-field view.
 *
 * func_020129FC is a post-increment and not an assignment:
 * `return p->unk1C8++;` spends an extra `adds r1, r4, #0` copy that
 * `n = p->unk1C8; p->unk1C8 = n + 1; return n;` does not, and the two are
 * otherwise the same eighteen instructions.  See
 * docs/idioms/post-increment-of-a-field-spends-a-copy.md.
 *
 * The file stops at 0x02012AD4 because func_02012AD4 cannot be attested; see
 * the header of src/matched/unit_02012AE4.c for that near miss.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table, so none of it looks version specific.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012924.c \
 *       --addr 0x02012924 --thumb
 */
u8 func_02012994(const struct BigObj *p)
{
    return p->unk1C5;
}


/*
 *           func_02012944, func_02012950, func_0201295C, func_02012964,
 *           func_0201296C, func_02012974, func_0201297C, func_02012984,
 *           func_0201298C, func_02012994, func_020129A0, func_020129AC,
 *           func_020129B8, func_020129C4, func_020129D0, func_020129DC,
 *           func_020129F0, func_020129FC, func_02012A24, func_02012A30,
 *           func_02012A38, func_02012A44, func_02012A4C, func_02012A54,
 *           func_02012A60, func_02012A90, func_02012AA0, func_02012AA4,
 *           func_02012AB8, func_02012ABC, func_02012AC0, func_02012AC4,
 *           func_02012AC8, func_02012ACC, func_02012AD0
 *
 * 432 bytes, 0x02012924..0x02012AD4, 39 functions, only nine of which carry a
 * label in the generated listing: the rest are leaf accessors that save no lr
 * and arrive in asm/arm9/src/004_02010BB8.s as runs of .word, which is
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Two objects are accessed here and they are not the same struct.
 *
 *  - BigObj is reached through a plain pointer argument and every field this
 *    file touches is past +0x18C, so each access is a register offset built
 *    with movs/lsls (0x63 << 2 is +0x18C) or, where the constant is not of
 *    that shape, out of the function's own literal pool (+0x1C5 .. +0x1CD).
 *    Those pool words are plain constants and carry no relocation.
 *  - Rec44 is the 0x44-byte record func_02012950 indexes, and func_02012A60
 *    onwards are its constructor and accessors.  func_02012A60 is the
 *    constructor: its store order is the source's statement order, and the
 *    two strb at +0x12 and +0x13 next to the strh at +0x10, +0x14 and +0x16
 *    are what make +0x10 a union of a four-halfword view (the one
 *    func_02012AA4 copies whole) and a five-field view.
 *
 * func_020129FC is a post-increment and not an assignment:
 * `return p->unk1C8++;` spends an extra `adds r1, r4, #0` copy that
 * `n = p->unk1C8; p->unk1C8 = n + 1; return n;` does not, and the two are
 * otherwise the same eighteen instructions.  See
 * docs/idioms/post-increment-of-a-field-spends-a-copy.md.
 *
 * The file stops at 0x02012AD4 because func_02012AD4 cannot be attested; see
 * the header of src/matched/unit_02012AE4.c for that near miss.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table, so none of it looks version specific.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012924.c \
 *       --addr 0x02012924 --thumb
 */
void func_020129A0(struct BigObj *p, u8 v)
{
    p->unk1C5 = v;
}


/*
 *           func_02012944, func_02012950, func_0201295C, func_02012964,
 *           func_0201296C, func_02012974, func_0201297C, func_02012984,
 *           func_0201298C, func_02012994, func_020129A0, func_020129AC,
 *           func_020129B8, func_020129C4, func_020129D0, func_020129DC,
 *           func_020129F0, func_020129FC, func_02012A24, func_02012A30,
 *           func_02012A38, func_02012A44, func_02012A4C, func_02012A54,
 *           func_02012A60, func_02012A90, func_02012AA0, func_02012AA4,
 *           func_02012AB8, func_02012ABC, func_02012AC0, func_02012AC4,
 *           func_02012AC8, func_02012ACC, func_02012AD0
 *
 * 432 bytes, 0x02012924..0x02012AD4, 39 functions, only nine of which carry a
 * label in the generated listing: the rest are leaf accessors that save no lr
 * and arrive in asm/arm9/src/004_02010BB8.s as runs of .word, which is
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Two objects are accessed here and they are not the same struct.
 *
 *  - BigObj is reached through a plain pointer argument and every field this
 *    file touches is past +0x18C, so each access is a register offset built
 *    with movs/lsls (0x63 << 2 is +0x18C) or, where the constant is not of
 *    that shape, out of the function's own literal pool (+0x1C5 .. +0x1CD).
 *    Those pool words are plain constants and carry no relocation.
 *  - Rec44 is the 0x44-byte record func_02012950 indexes, and func_02012A60
 *    onwards are its constructor and accessors.  func_02012A60 is the
 *    constructor: its store order is the source's statement order, and the
 *    two strb at +0x12 and +0x13 next to the strh at +0x10, +0x14 and +0x16
 *    are what make +0x10 a union of a four-halfword view (the one
 *    func_02012AA4 copies whole) and a five-field view.
 *
 * func_020129FC is a post-increment and not an assignment:
 * `return p->unk1C8++;` spends an extra `adds r1, r4, #0` copy that
 * `n = p->unk1C8; p->unk1C8 = n + 1; return n;` does not, and the two are
 * otherwise the same eighteen instructions.  See
 * docs/idioms/post-increment-of-a-field-spends-a-copy.md.
 *
 * The file stops at 0x02012AD4 because func_02012AD4 cannot be attested; see
 * the header of src/matched/unit_02012AE4.c for that near miss.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table, so none of it looks version specific.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012924.c \
 *       --addr 0x02012924 --thumb
 */
u8 func_020129AC(const struct BigObj *p)
{
    return p->unk1C6;
}


/*
 *           func_02012944, func_02012950, func_0201295C, func_02012964,
 *           func_0201296C, func_02012974, func_0201297C, func_02012984,
 *           func_0201298C, func_02012994, func_020129A0, func_020129AC,
 *           func_020129B8, func_020129C4, func_020129D0, func_020129DC,
 *           func_020129F0, func_020129FC, func_02012A24, func_02012A30,
 *           func_02012A38, func_02012A44, func_02012A4C, func_02012A54,
 *           func_02012A60, func_02012A90, func_02012AA0, func_02012AA4,
 *           func_02012AB8, func_02012ABC, func_02012AC0, func_02012AC4,
 *           func_02012AC8, func_02012ACC, func_02012AD0
 *
 * 432 bytes, 0x02012924..0x02012AD4, 39 functions, only nine of which carry a
 * label in the generated listing: the rest are leaf accessors that save no lr
 * and arrive in asm/arm9/src/004_02010BB8.s as runs of .word, which is
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Two objects are accessed here and they are not the same struct.
 *
 *  - BigObj is reached through a plain pointer argument and every field this
 *    file touches is past +0x18C, so each access is a register offset built
 *    with movs/lsls (0x63 << 2 is +0x18C) or, where the constant is not of
 *    that shape, out of the function's own literal pool (+0x1C5 .. +0x1CD).
 *    Those pool words are plain constants and carry no relocation.
 *  - Rec44 is the 0x44-byte record func_02012950 indexes, and func_02012A60
 *    onwards are its constructor and accessors.  func_02012A60 is the
 *    constructor: its store order is the source's statement order, and the
 *    two strb at +0x12 and +0x13 next to the strh at +0x10, +0x14 and +0x16
 *    are what make +0x10 a union of a four-halfword view (the one
 *    func_02012AA4 copies whole) and a five-field view.
 *
 * func_020129FC is a post-increment and not an assignment:
 * `return p->unk1C8++;` spends an extra `adds r1, r4, #0` copy that
 * `n = p->unk1C8; p->unk1C8 = n + 1; return n;` does not, and the two are
 * otherwise the same eighteen instructions.  See
 * docs/idioms/post-increment-of-a-field-spends-a-copy.md.
 *
 * The file stops at 0x02012AD4 because func_02012AD4 cannot be attested; see
 * the header of src/matched/unit_02012AE4.c for that near miss.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table, so none of it looks version specific.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012924.c \
 *       --addr 0x02012924 --thumb
 */
void func_020129B8(struct BigObj *p, u32 v)
{
    p->unk1C6 = v;
}


/*
 *           func_02012944, func_02012950, func_0201295C, func_02012964,
 *           func_0201296C, func_02012974, func_0201297C, func_02012984,
 *           func_0201298C, func_02012994, func_020129A0, func_020129AC,
 *           func_020129B8, func_020129C4, func_020129D0, func_020129DC,
 *           func_020129F0, func_020129FC, func_02012A24, func_02012A30,
 *           func_02012A38, func_02012A44, func_02012A4C, func_02012A54,
 *           func_02012A60, func_02012A90, func_02012AA0, func_02012AA4,
 *           func_02012AB8, func_02012ABC, func_02012AC0, func_02012AC4,
 *           func_02012AC8, func_02012ACC, func_02012AD0
 *
 * 432 bytes, 0x02012924..0x02012AD4, 39 functions, only nine of which carry a
 * label in the generated listing: the rest are leaf accessors that save no lr
 * and arrive in asm/arm9/src/004_02010BB8.s as runs of .word, which is
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Two objects are accessed here and they are not the same struct.
 *
 *  - BigObj is reached through a plain pointer argument and every field this
 *    file touches is past +0x18C, so each access is a register offset built
 *    with movs/lsls (0x63 << 2 is +0x18C) or, where the constant is not of
 *    that shape, out of the function's own literal pool (+0x1C5 .. +0x1CD).
 *    Those pool words are plain constants and carry no relocation.
 *  - Rec44 is the 0x44-byte record func_02012950 indexes, and func_02012A60
 *    onwards are its constructor and accessors.  func_02012A60 is the
 *    constructor: its store order is the source's statement order, and the
 *    two strb at +0x12 and +0x13 next to the strh at +0x10, +0x14 and +0x16
 *    are what make +0x10 a union of a four-halfword view (the one
 *    func_02012AA4 copies whole) and a five-field view.
 *
 * func_020129FC is a post-increment and not an assignment:
 * `return p->unk1C8++;` spends an extra `adds r1, r4, #0` copy that
 * `n = p->unk1C8; p->unk1C8 = n + 1; return n;` does not, and the two are
 * otherwise the same eighteen instructions.  See
 * docs/idioms/post-increment-of-a-field-spends-a-copy.md.
 *
 * The file stops at 0x02012AD4 because func_02012AD4 cannot be attested; see
 * the header of src/matched/unit_02012AE4.c for that near miss.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table, so none of it looks version specific.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012924.c \
 *       --addr 0x02012924 --thumb
 */
u8 func_020129C4(const struct BigObj *p)
{
    return p->unk1C7;
}


/*
 *           func_02012944, func_02012950, func_0201295C, func_02012964,
 *           func_0201296C, func_02012974, func_0201297C, func_02012984,
 *           func_0201298C, func_02012994, func_020129A0, func_020129AC,
 *           func_020129B8, func_020129C4, func_020129D0, func_020129DC,
 *           func_020129F0, func_020129FC, func_02012A24, func_02012A30,
 *           func_02012A38, func_02012A44, func_02012A4C, func_02012A54,
 *           func_02012A60, func_02012A90, func_02012AA0, func_02012AA4,
 *           func_02012AB8, func_02012ABC, func_02012AC0, func_02012AC4,
 *           func_02012AC8, func_02012ACC, func_02012AD0
 *
 * 432 bytes, 0x02012924..0x02012AD4, 39 functions, only nine of which carry a
 * label in the generated listing: the rest are leaf accessors that save no lr
 * and arrive in asm/arm9/src/004_02010BB8.s as runs of .word, which is
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Two objects are accessed here and they are not the same struct.
 *
 *  - BigObj is reached through a plain pointer argument and every field this
 *    file touches is past +0x18C, so each access is a register offset built
 *    with movs/lsls (0x63 << 2 is +0x18C) or, where the constant is not of
 *    that shape, out of the function's own literal pool (+0x1C5 .. +0x1CD).
 *    Those pool words are plain constants and carry no relocation.
 *  - Rec44 is the 0x44-byte record func_02012950 indexes, and func_02012A60
 *    onwards are its constructor and accessors.  func_02012A60 is the
 *    constructor: its store order is the source's statement order, and the
 *    two strb at +0x12 and +0x13 next to the strh at +0x10, +0x14 and +0x16
 *    are what make +0x10 a union of a four-halfword view (the one
 *    func_02012AA4 copies whole) and a five-field view.
 *
 * func_020129FC is a post-increment and not an assignment:
 * `return p->unk1C8++;` spends an extra `adds r1, r4, #0` copy that
 * `n = p->unk1C8; p->unk1C8 = n + 1; return n;` does not, and the two are
 * otherwise the same eighteen instructions.  See
 * docs/idioms/post-increment-of-a-field-spends-a-copy.md.
 *
 * The file stops at 0x02012AD4 because func_02012AD4 cannot be attested; see
 * the header of src/matched/unit_02012AE4.c for that near miss.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table, so none of it looks version specific.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012924.c \
 *       --addr 0x02012924 --thumb
 */
void func_020129D0(struct BigObj *p, u8 v)
{
    p->unk1C7 = v;
}


/*
 *           func_02012944, func_02012950, func_0201295C, func_02012964,
 *           func_0201296C, func_02012974, func_0201297C, func_02012984,
 *           func_0201298C, func_02012994, func_020129A0, func_020129AC,
 *           func_020129B8, func_020129C4, func_020129D0, func_020129DC,
 *           func_020129F0, func_020129FC, func_02012A24, func_02012A30,
 *           func_02012A38, func_02012A44, func_02012A4C, func_02012A54,
 *           func_02012A60, func_02012A90, func_02012AA0, func_02012AA4,
 *           func_02012AB8, func_02012ABC, func_02012AC0, func_02012AC4,
 *           func_02012AC8, func_02012ACC, func_02012AD0
 *
 * 432 bytes, 0x02012924..0x02012AD4, 39 functions, only nine of which carry a
 * label in the generated listing: the rest are leaf accessors that save no lr
 * and arrive in asm/arm9/src/004_02010BB8.s as runs of .word, which is
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Two objects are accessed here and they are not the same struct.
 *
 *  - BigObj is reached through a plain pointer argument and every field this
 *    file touches is past +0x18C, so each access is a register offset built
 *    with movs/lsls (0x63 << 2 is +0x18C) or, where the constant is not of
 *    that shape, out of the function's own literal pool (+0x1C5 .. +0x1CD).
 *    Those pool words are plain constants and carry no relocation.
 *  - Rec44 is the 0x44-byte record func_02012950 indexes, and func_02012A60
 *    onwards are its constructor and accessors.  func_02012A60 is the
 *    constructor: its store order is the source's statement order, and the
 *    two strb at +0x12 and +0x13 next to the strh at +0x10, +0x14 and +0x16
 *    are what make +0x10 a union of a four-halfword view (the one
 *    func_02012AA4 copies whole) and a five-field view.
 *
 * func_020129FC is a post-increment and not an assignment:
 * `return p->unk1C8++;` spends an extra `adds r1, r4, #0` copy that
 * `n = p->unk1C8; p->unk1C8 = n + 1; return n;` does not, and the two are
 * otherwise the same eighteen instructions.  See
 * docs/idioms/post-increment-of-a-field-spends-a-copy.md.
 *
 * The file stops at 0x02012AD4 because func_02012AD4 cannot be attested; see
 * the header of src/matched/unit_02012AE4.c for that near miss.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table, so none of it looks version specific.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012924.c \
 *       --addr 0x02012924 --thumb
 */
void func_020129DC(struct BigObj *p, u8 v)
{
    p->unk1C9 = v;
    if (v != 0) {
        p->unk1C8 = 0;
    }
}


/*
 *           func_02012944, func_02012950, func_0201295C, func_02012964,
 *           func_0201296C, func_02012974, func_0201297C, func_02012984,
 *           func_0201298C, func_02012994, func_020129A0, func_020129AC,
 *           func_020129B8, func_020129C4, func_020129D0, func_020129DC,
 *           func_020129F0, func_020129FC, func_02012A24, func_02012A30,
 *           func_02012A38, func_02012A44, func_02012A4C, func_02012A54,
 *           func_02012A60, func_02012A90, func_02012AA0, func_02012AA4,
 *           func_02012AB8, func_02012ABC, func_02012AC0, func_02012AC4,
 *           func_02012AC8, func_02012ACC, func_02012AD0
 *
 * 432 bytes, 0x02012924..0x02012AD4, 39 functions, only nine of which carry a
 * label in the generated listing: the rest are leaf accessors that save no lr
 * and arrive in asm/arm9/src/004_02010BB8.s as runs of .word, which is
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Two objects are accessed here and they are not the same struct.
 *
 *  - BigObj is reached through a plain pointer argument and every field this
 *    file touches is past +0x18C, so each access is a register offset built
 *    with movs/lsls (0x63 << 2 is +0x18C) or, where the constant is not of
 *    that shape, out of the function's own literal pool (+0x1C5 .. +0x1CD).
 *    Those pool words are plain constants and carry no relocation.
 *  - Rec44 is the 0x44-byte record func_02012950 indexes, and func_02012A60
 *    onwards are its constructor and accessors.  func_02012A60 is the
 *    constructor: its store order is the source's statement order, and the
 *    two strb at +0x12 and +0x13 next to the strh at +0x10, +0x14 and +0x16
 *    are what make +0x10 a union of a four-halfword view (the one
 *    func_02012AA4 copies whole) and a five-field view.
 *
 * func_020129FC is a post-increment and not an assignment:
 * `return p->unk1C8++;` spends an extra `adds r1, r4, #0` copy that
 * `n = p->unk1C8; p->unk1C8 = n + 1; return n;` does not, and the two are
 * otherwise the same eighteen instructions.  See
 * docs/idioms/post-increment-of-a-field-spends-a-copy.md.
 *
 * The file stops at 0x02012AD4 because func_02012AD4 cannot be attested; see
 * the header of src/matched/unit_02012AE4.c for that near miss.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table, so none of it looks version specific.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012924.c \
 *       --addr 0x02012924 --thumb
 */
void func_020129F0(struct BigObj *p)
{
    p->unk1C8 = 0;
}


/*
 *           func_02012944, func_02012950, func_0201295C, func_02012964,
 *           func_0201296C, func_02012974, func_0201297C, func_02012984,
 *           func_0201298C, func_02012994, func_020129A0, func_020129AC,
 *           func_020129B8, func_020129C4, func_020129D0, func_020129DC,
 *           func_020129F0, func_020129FC, func_02012A24, func_02012A30,
 *           func_02012A38, func_02012A44, func_02012A4C, func_02012A54,
 *           func_02012A60, func_02012A90, func_02012AA0, func_02012AA4,
 *           func_02012AB8, func_02012ABC, func_02012AC0, func_02012AC4,
 *           func_02012AC8, func_02012ACC, func_02012AD0
 *
 * 432 bytes, 0x02012924..0x02012AD4, 39 functions, only nine of which carry a
 * label in the generated listing: the rest are leaf accessors that save no lr
 * and arrive in asm/arm9/src/004_02010BB8.s as runs of .word, which is
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Two objects are accessed here and they are not the same struct.
 *
 *  - BigObj is reached through a plain pointer argument and every field this
 *    file touches is past +0x18C, so each access is a register offset built
 *    with movs/lsls (0x63 << 2 is +0x18C) or, where the constant is not of
 *    that shape, out of the function's own literal pool (+0x1C5 .. +0x1CD).
 *    Those pool words are plain constants and carry no relocation.
 *  - Rec44 is the 0x44-byte record func_02012950 indexes, and func_02012A60
 *    onwards are its constructor and accessors.  func_02012A60 is the
 *    constructor: its store order is the source's statement order, and the
 *    two strb at +0x12 and +0x13 next to the strh at +0x10, +0x14 and +0x16
 *    are what make +0x10 a union of a four-halfword view (the one
 *    func_02012AA4 copies whole) and a five-field view.
 *
 * func_020129FC is a post-increment and not an assignment:
 * `return p->unk1C8++;` spends an extra `adds r1, r4, #0` copy that
 * `n = p->unk1C8; p->unk1C8 = n + 1; return n;` does not, and the two are
 * otherwise the same eighteen instructions.  See
 * docs/idioms/post-increment-of-a-field-spends-a-copy.md.
 *
 * The file stops at 0x02012AD4 because func_02012AD4 cannot be attested; see
 * the header of src/matched/unit_02012AE4.c for that near miss.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table, so none of it looks version specific.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012924.c \
 *       --addr 0x02012924 --thumb
 */
u8 func_020129FC(struct BigObj *p)
{
    if (p->unk1C9 != 0) {
        return p->unk1C8++;
    }
    return 0;
}


/*
 *           func_02012944, func_02012950, func_0201295C, func_02012964,
 *           func_0201296C, func_02012974, func_0201297C, func_02012984,
 *           func_0201298C, func_02012994, func_020129A0, func_020129AC,
 *           func_020129B8, func_020129C4, func_020129D0, func_020129DC,
 *           func_020129F0, func_020129FC, func_02012A24, func_02012A30,
 *           func_02012A38, func_02012A44, func_02012A4C, func_02012A54,
 *           func_02012A60, func_02012A90, func_02012AA0, func_02012AA4,
 *           func_02012AB8, func_02012ABC, func_02012AC0, func_02012AC4,
 *           func_02012AC8, func_02012ACC, func_02012AD0
 *
 * 432 bytes, 0x02012924..0x02012AD4, 39 functions, only nine of which carry a
 * label in the generated listing: the rest are leaf accessors that save no lr
 * and arrive in asm/arm9/src/004_02010BB8.s as runs of .word, which is
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Two objects are accessed here and they are not the same struct.
 *
 *  - BigObj is reached through a plain pointer argument and every field this
 *    file touches is past +0x18C, so each access is a register offset built
 *    with movs/lsls (0x63 << 2 is +0x18C) or, where the constant is not of
 *    that shape, out of the function's own literal pool (+0x1C5 .. +0x1CD).
 *    Those pool words are plain constants and carry no relocation.
 *  - Rec44 is the 0x44-byte record func_02012950 indexes, and func_02012A60
 *    onwards are its constructor and accessors.  func_02012A60 is the
 *    constructor: its store order is the source's statement order, and the
 *    two strb at +0x12 and +0x13 next to the strh at +0x10, +0x14 and +0x16
 *    are what make +0x10 a union of a four-halfword view (the one
 *    func_02012AA4 copies whole) and a five-field view.
 *
 * func_020129FC is a post-increment and not an assignment:
 * `return p->unk1C8++;` spends an extra `adds r1, r4, #0` copy that
 * `n = p->unk1C8; p->unk1C8 = n + 1; return n;` does not, and the two are
 * otherwise the same eighteen instructions.  See
 * docs/idioms/post-increment-of-a-field-spends-a-copy.md.
 *
 * The file stops at 0x02012AD4 because func_02012AD4 cannot be attested; see
 * the header of src/matched/unit_02012AE4.c for that near miss.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table, so none of it looks version specific.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012924.c \
 *       --addr 0x02012924 --thumb
 */
u8 func_02012A24(const struct BigObj *p)
{
    return p->unk1C9;
}


/*
 *           func_02012944, func_02012950, func_0201295C, func_02012964,
 *           func_0201296C, func_02012974, func_0201297C, func_02012984,
 *           func_0201298C, func_02012994, func_020129A0, func_020129AC,
 *           func_020129B8, func_020129C4, func_020129D0, func_020129DC,
 *           func_020129F0, func_020129FC, func_02012A24, func_02012A30,
 *           func_02012A38, func_02012A44, func_02012A4C, func_02012A54,
 *           func_02012A60, func_02012A90, func_02012AA0, func_02012AA4,
 *           func_02012AB8, func_02012ABC, func_02012AC0, func_02012AC4,
 *           func_02012AC8, func_02012ACC, func_02012AD0
 *
 * 432 bytes, 0x02012924..0x02012AD4, 39 functions, only nine of which carry a
 * label in the generated listing: the rest are leaf accessors that save no lr
 * and arrive in asm/arm9/src/004_02010BB8.s as runs of .word, which is
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Two objects are accessed here and they are not the same struct.
 *
 *  - BigObj is reached through a plain pointer argument and every field this
 *    file touches is past +0x18C, so each access is a register offset built
 *    with movs/lsls (0x63 << 2 is +0x18C) or, where the constant is not of
 *    that shape, out of the function's own literal pool (+0x1C5 .. +0x1CD).
 *    Those pool words are plain constants and carry no relocation.
 *  - Rec44 is the 0x44-byte record func_02012950 indexes, and func_02012A60
 *    onwards are its constructor and accessors.  func_02012A60 is the
 *    constructor: its store order is the source's statement order, and the
 *    two strb at +0x12 and +0x13 next to the strh at +0x10, +0x14 and +0x16
 *    are what make +0x10 a union of a four-halfword view (the one
 *    func_02012AA4 copies whole) and a five-field view.
 *
 * func_020129FC is a post-increment and not an assignment:
 * `return p->unk1C8++;` spends an extra `adds r1, r4, #0` copy that
 * `n = p->unk1C8; p->unk1C8 = n + 1; return n;` does not, and the two are
 * otherwise the same eighteen instructions.  See
 * docs/idioms/post-increment-of-a-field-spends-a-copy.md.
 *
 * The file stops at 0x02012AD4 because func_02012AD4 cannot be attested; see
 * the header of src/matched/unit_02012AE4.c for that near miss.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table, so none of it looks version specific.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012924.c \
 *       --addr 0x02012924 --thumb
 */
u32 func_02012A30(const struct BigObj *p)
{
    return p->unk1B4;
}


/*
 *           func_02012944, func_02012950, func_0201295C, func_02012964,
 *           func_0201296C, func_02012974, func_0201297C, func_02012984,
 *           func_0201298C, func_02012994, func_020129A0, func_020129AC,
 *           func_020129B8, func_020129C4, func_020129D0, func_020129DC,
 *           func_020129F0, func_020129FC, func_02012A24, func_02012A30,
 *           func_02012A38, func_02012A44, func_02012A4C, func_02012A54,
 *           func_02012A60, func_02012A90, func_02012AA0, func_02012AA4,
 *           func_02012AB8, func_02012ABC, func_02012AC0, func_02012AC4,
 *           func_02012AC8, func_02012ACC, func_02012AD0
 *
 * 432 bytes, 0x02012924..0x02012AD4, 39 functions, only nine of which carry a
 * label in the generated listing: the rest are leaf accessors that save no lr
 * and arrive in asm/arm9/src/004_02010BB8.s as runs of .word, which is
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Two objects are accessed here and they are not the same struct.
 *
 *  - BigObj is reached through a plain pointer argument and every field this
 *    file touches is past +0x18C, so each access is a register offset built
 *    with movs/lsls (0x63 << 2 is +0x18C) or, where the constant is not of
 *    that shape, out of the function's own literal pool (+0x1C5 .. +0x1CD).
 *    Those pool words are plain constants and carry no relocation.
 *  - Rec44 is the 0x44-byte record func_02012950 indexes, and func_02012A60
 *    onwards are its constructor and accessors.  func_02012A60 is the
 *    constructor: its store order is the source's statement order, and the
 *    two strb at +0x12 and +0x13 next to the strh at +0x10, +0x14 and +0x16
 *    are what make +0x10 a union of a four-halfword view (the one
 *    func_02012AA4 copies whole) and a five-field view.
 *
 * func_020129FC is a post-increment and not an assignment:
 * `return p->unk1C8++;` spends an extra `adds r1, r4, #0` copy that
 * `n = p->unk1C8; p->unk1C8 = n + 1; return n;` does not, and the two are
 * otherwise the same eighteen instructions.  See
 * docs/idioms/post-increment-of-a-field-spends-a-copy.md.
 *
 * The file stops at 0x02012AD4 because func_02012AD4 cannot be attested; see
 * the header of src/matched/unit_02012AE4.c for that near miss.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table, so none of it looks version specific.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012924.c \
 *       --addr 0x02012924 --thumb
 */
u32 func_02012A38(const struct BigObj *p)
{
    return p->unk5E4;
}


/*
 *           func_02012944, func_02012950, func_0201295C, func_02012964,
 *           func_0201296C, func_02012974, func_0201297C, func_02012984,
 *           func_0201298C, func_02012994, func_020129A0, func_020129AC,
 *           func_020129B8, func_020129C4, func_020129D0, func_020129DC,
 *           func_020129F0, func_020129FC, func_02012A24, func_02012A30,
 *           func_02012A38, func_02012A44, func_02012A4C, func_02012A54,
 *           func_02012A60, func_02012A90, func_02012AA0, func_02012AA4,
 *           func_02012AB8, func_02012ABC, func_02012AC0, func_02012AC4,
 *           func_02012AC8, func_02012ACC, func_02012AD0
 *
 * 432 bytes, 0x02012924..0x02012AD4, 39 functions, only nine of which carry a
 * label in the generated listing: the rest are leaf accessors that save no lr
 * and arrive in asm/arm9/src/004_02010BB8.s as runs of .word, which is
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Two objects are accessed here and they are not the same struct.
 *
 *  - BigObj is reached through a plain pointer argument and every field this
 *    file touches is past +0x18C, so each access is a register offset built
 *    with movs/lsls (0x63 << 2 is +0x18C) or, where the constant is not of
 *    that shape, out of the function's own literal pool (+0x1C5 .. +0x1CD).
 *    Those pool words are plain constants and carry no relocation.
 *  - Rec44 is the 0x44-byte record func_02012950 indexes, and func_02012A60
 *    onwards are its constructor and accessors.  func_02012A60 is the
 *    constructor: its store order is the source's statement order, and the
 *    two strb at +0x12 and +0x13 next to the strh at +0x10, +0x14 and +0x16
 *    are what make +0x10 a union of a four-halfword view (the one
 *    func_02012AA4 copies whole) and a five-field view.
 *
 * func_020129FC is a post-increment and not an assignment:
 * `return p->unk1C8++;` spends an extra `adds r1, r4, #0` copy that
 * `n = p->unk1C8; p->unk1C8 = n + 1; return n;` does not, and the two are
 * otherwise the same eighteen instructions.  See
 * docs/idioms/post-increment-of-a-field-spends-a-copy.md.
 *
 * The file stops at 0x02012AD4 because func_02012AD4 cannot be attested; see
 * the header of src/matched/unit_02012AE4.c for that near miss.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table, so none of it looks version specific.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012924.c \
 *       --addr 0x02012924 --thumb
 */
u32 func_02012A44(const struct BigObj *p)
{
    return p->unk1BC;
}


/*
 *           func_02012944, func_02012950, func_0201295C, func_02012964,
 *           func_0201296C, func_02012974, func_0201297C, func_02012984,
 *           func_0201298C, func_02012994, func_020129A0, func_020129AC,
 *           func_020129B8, func_020129C4, func_020129D0, func_020129DC,
 *           func_020129F0, func_020129FC, func_02012A24, func_02012A30,
 *           func_02012A38, func_02012A44, func_02012A4C, func_02012A54,
 *           func_02012A60, func_02012A90, func_02012AA0, func_02012AA4,
 *           func_02012AB8, func_02012ABC, func_02012AC0, func_02012AC4,
 *           func_02012AC8, func_02012ACC, func_02012AD0
 *
 * 432 bytes, 0x02012924..0x02012AD4, 39 functions, only nine of which carry a
 * label in the generated listing: the rest are leaf accessors that save no lr
 * and arrive in asm/arm9/src/004_02010BB8.s as runs of .word, which is
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Two objects are accessed here and they are not the same struct.
 *
 *  - BigObj is reached through a plain pointer argument and every field this
 *    file touches is past +0x18C, so each access is a register offset built
 *    with movs/lsls (0x63 << 2 is +0x18C) or, where the constant is not of
 *    that shape, out of the function's own literal pool (+0x1C5 .. +0x1CD).
 *    Those pool words are plain constants and carry no relocation.
 *  - Rec44 is the 0x44-byte record func_02012950 indexes, and func_02012A60
 *    onwards are its constructor and accessors.  func_02012A60 is the
 *    constructor: its store order is the source's statement order, and the
 *    two strb at +0x12 and +0x13 next to the strh at +0x10, +0x14 and +0x16
 *    are what make +0x10 a union of a four-halfword view (the one
 *    func_02012AA4 copies whole) and a five-field view.
 *
 * func_020129FC is a post-increment and not an assignment:
 * `return p->unk1C8++;` spends an extra `adds r1, r4, #0` copy that
 * `n = p->unk1C8; p->unk1C8 = n + 1; return n;` does not, and the two are
 * otherwise the same eighteen instructions.  See
 * docs/idioms/post-increment-of-a-field-spends-a-copy.md.
 *
 * The file stops at 0x02012AD4 because func_02012AD4 cannot be attested; see
 * the header of src/matched/unit_02012AE4.c for that near miss.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table, so none of it looks version specific.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012924.c \
 *       --addr 0x02012924 --thumb
 */
void func_02012A4C(struct BigObj *p, u32 v)
{
    p->unk1BC = v;
}


/*
 *           func_02012944, func_02012950, func_0201295C, func_02012964,
 *           func_0201296C, func_02012974, func_0201297C, func_02012984,
 *           func_0201298C, func_02012994, func_020129A0, func_020129AC,
 *           func_020129B8, func_020129C4, func_020129D0, func_020129DC,
 *           func_020129F0, func_020129FC, func_02012A24, func_02012A30,
 *           func_02012A38, func_02012A44, func_02012A4C, func_02012A54,
 *           func_02012A60, func_02012A90, func_02012AA0, func_02012AA4,
 *           func_02012AB8, func_02012ABC, func_02012AC0, func_02012AC4,
 *           func_02012AC8, func_02012ACC, func_02012AD0
 *
 * 432 bytes, 0x02012924..0x02012AD4, 39 functions, only nine of which carry a
 * label in the generated listing: the rest are leaf accessors that save no lr
 * and arrive in asm/arm9/src/004_02010BB8.s as runs of .word, which is
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Two objects are accessed here and they are not the same struct.
 *
 *  - BigObj is reached through a plain pointer argument and every field this
 *    file touches is past +0x18C, so each access is a register offset built
 *    with movs/lsls (0x63 << 2 is +0x18C) or, where the constant is not of
 *    that shape, out of the function's own literal pool (+0x1C5 .. +0x1CD).
 *    Those pool words are plain constants and carry no relocation.
 *  - Rec44 is the 0x44-byte record func_02012950 indexes, and func_02012A60
 *    onwards are its constructor and accessors.  func_02012A60 is the
 *    constructor: its store order is the source's statement order, and the
 *    two strb at +0x12 and +0x13 next to the strh at +0x10, +0x14 and +0x16
 *    are what make +0x10 a union of a four-halfword view (the one
 *    func_02012AA4 copies whole) and a five-field view.
 *
 * func_020129FC is a post-increment and not an assignment:
 * `return p->unk1C8++;` spends an extra `adds r1, r4, #0` copy that
 * `n = p->unk1C8; p->unk1C8 = n + 1; return n;` does not, and the two are
 * otherwise the same eighteen instructions.  See
 * docs/idioms/post-increment-of-a-field-spends-a-copy.md.
 *
 * The file stops at 0x02012AD4 because func_02012AD4 cannot be attested; see
 * the header of src/matched/unit_02012AE4.c for that near miss.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table, so none of it looks version specific.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012924.c \
 *       --addr 0x02012924 --thumb
 */
u32 func_02012A54(const struct BigObj *p)
{
    return p->unk68C;
}


/*
 *           func_02012944, func_02012950, func_0201295C, func_02012964,
 *           func_0201296C, func_02012974, func_0201297C, func_02012984,
 *           func_0201298C, func_02012994, func_020129A0, func_020129AC,
 *           func_020129B8, func_020129C4, func_020129D0, func_020129DC,
 *           func_020129F0, func_020129FC, func_02012A24, func_02012A30,
 *           func_02012A38, func_02012A44, func_02012A4C, func_02012A54,
 *           func_02012A60, func_02012A90, func_02012AA0, func_02012AA4,
 *           func_02012AB8, func_02012ABC, func_02012AC0, func_02012AC4,
 *           func_02012AC8, func_02012ACC, func_02012AD0
 *
 * 432 bytes, 0x02012924..0x02012AD4, 39 functions, only nine of which carry a
 * label in the generated listing: the rest are leaf accessors that save no lr
 * and arrive in asm/arm9/src/004_02010BB8.s as runs of .word, which is
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Two objects are accessed here and they are not the same struct.
 *
 *  - BigObj is reached through a plain pointer argument and every field this
 *    file touches is past +0x18C, so each access is a register offset built
 *    with movs/lsls (0x63 << 2 is +0x18C) or, where the constant is not of
 *    that shape, out of the function's own literal pool (+0x1C5 .. +0x1CD).
 *    Those pool words are plain constants and carry no relocation.
 *  - Rec44 is the 0x44-byte record func_02012950 indexes, and func_02012A60
 *    onwards are its constructor and accessors.  func_02012A60 is the
 *    constructor: its store order is the source's statement order, and the
 *    two strb at +0x12 and +0x13 next to the strh at +0x10, +0x14 and +0x16
 *    are what make +0x10 a union of a four-halfword view (the one
 *    func_02012AA4 copies whole) and a five-field view.
 *
 * func_020129FC is a post-increment and not an assignment:
 * `return p->unk1C8++;` spends an extra `adds r1, r4, #0` copy that
 * `n = p->unk1C8; p->unk1C8 = n + 1; return n;` does not, and the two are
 * otherwise the same eighteen instructions.  See
 * docs/idioms/post-increment-of-a-field-spends-a-copy.md.
 *
 * The file stops at 0x02012AD4 because func_02012AD4 cannot be attested; see
 * the header of src/matched/unit_02012AE4.c for that near miss.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table, so none of it looks version specific.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012924.c \
 *       --addr 0x02012924 --thumb
 */
void func_02012A60(struct Rec44_0 *p)
{
    p->unk3D = 0;
    p->unk3A = 0;
    p->unk00 = 0;
    p->unk04.x = 0;
    p->unk04.y = 0;
    p->unk04.z = 0;
    p->unk18 = 0;
    p->unk1B = 0;
    p->unk30 = 0;
    p->unk10.f.b = 0;
    p->unk10.f.c = 0;
    p->unk10.f.a = 0;
    p->unk10.f.e = 0;
    p->unk10.f.d = 0;
    p->unk1C = 0xFFFF;
}


/*
 *           func_02012944, func_02012950, func_0201295C, func_02012964,
 *           func_0201296C, func_02012974, func_0201297C, func_02012984,
 *           func_0201298C, func_02012994, func_020129A0, func_020129AC,
 *           func_020129B8, func_020129C4, func_020129D0, func_020129DC,
 *           func_020129F0, func_020129FC, func_02012A24, func_02012A30,
 *           func_02012A38, func_02012A44, func_02012A4C, func_02012A54,
 *           func_02012A60, func_02012A90, func_02012AA0, func_02012AA4,
 *           func_02012AB8, func_02012ABC, func_02012AC0, func_02012AC4,
 *           func_02012AC8, func_02012ACC, func_02012AD0
 *
 * 432 bytes, 0x02012924..0x02012AD4, 39 functions, only nine of which carry a
 * label in the generated listing: the rest are leaf accessors that save no lr
 * and arrive in asm/arm9/src/004_02010BB8.s as runs of .word, which is
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Two objects are accessed here and they are not the same struct.
 *
 *  - BigObj is reached through a plain pointer argument and every field this
 *    file touches is past +0x18C, so each access is a register offset built
 *    with movs/lsls (0x63 << 2 is +0x18C) or, where the constant is not of
 *    that shape, out of the function's own literal pool (+0x1C5 .. +0x1CD).
 *    Those pool words are plain constants and carry no relocation.
 *  - Rec44 is the 0x44-byte record func_02012950 indexes, and func_02012A60
 *    onwards are its constructor and accessors.  func_02012A60 is the
 *    constructor: its store order is the source's statement order, and the
 *    two strb at +0x12 and +0x13 next to the strh at +0x10, +0x14 and +0x16
 *    are what make +0x10 a union of a four-halfword view (the one
 *    func_02012AA4 copies whole) and a five-field view.
 *
 * func_020129FC is a post-increment and not an assignment:
 * `return p->unk1C8++;` spends an extra `adds r1, r4, #0` copy that
 * `n = p->unk1C8; p->unk1C8 = n + 1; return n;` does not, and the two are
 * otherwise the same eighteen instructions.  See
 * docs/idioms/post-increment-of-a-field-spends-a-copy.md.
 *
 * The file stops at 0x02012AD4 because func_02012AD4 cannot be attested; see
 * the header of src/matched/unit_02012AE4.c for that near miss.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table, so none of it looks version specific.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012924.c \
 *       --addr 0x02012924 --thumb
 */
void func_02012A90(struct Rec44_0 *p, const struct Vec12 *src)
{
    p->unk04 = *src;
}


/*
 *           func_02012944, func_02012950, func_0201295C, func_02012964,
 *           func_0201296C, func_02012974, func_0201297C, func_02012984,
 *           func_0201298C, func_02012994, func_020129A0, func_020129AC,
 *           func_020129B8, func_020129C4, func_020129D0, func_020129DC,
 *           func_020129F0, func_020129FC, func_02012A24, func_02012A30,
 *           func_02012A38, func_02012A44, func_02012A4C, func_02012A54,
 *           func_02012A60, func_02012A90, func_02012AA0, func_02012AA4,
 *           func_02012AB8, func_02012ABC, func_02012AC0, func_02012AC4,
 *           func_02012AC8, func_02012ACC, func_02012AD0
 *
 * 432 bytes, 0x02012924..0x02012AD4, 39 functions, only nine of which carry a
 * label in the generated listing: the rest are leaf accessors that save no lr
 * and arrive in asm/arm9/src/004_02010BB8.s as runs of .word, which is
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Two objects are accessed here and they are not the same struct.
 *
 *  - BigObj is reached through a plain pointer argument and every field this
 *    file touches is past +0x18C, so each access is a register offset built
 *    with movs/lsls (0x63 << 2 is +0x18C) or, where the constant is not of
 *    that shape, out of the function's own literal pool (+0x1C5 .. +0x1CD).
 *    Those pool words are plain constants and carry no relocation.
 *  - Rec44 is the 0x44-byte record func_02012950 indexes, and func_02012A60
 *    onwards are its constructor and accessors.  func_02012A60 is the
 *    constructor: its store order is the source's statement order, and the
 *    two strb at +0x12 and +0x13 next to the strh at +0x10, +0x14 and +0x16
 *    are what make +0x10 a union of a four-halfword view (the one
 *    func_02012AA4 copies whole) and a five-field view.
 *
 * func_020129FC is a post-increment and not an assignment:
 * `return p->unk1C8++;` spends an extra `adds r1, r4, #0` copy that
 * `n = p->unk1C8; p->unk1C8 = n + 1; return n;` does not, and the two are
 * otherwise the same eighteen instructions.  See
 * docs/idioms/post-increment-of-a-field-spends-a-copy.md.
 *
 * The file stops at 0x02012AD4 because func_02012AD4 cannot be attested; see
 * the header of src/matched/unit_02012AE4.c for that near miss.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table, so none of it looks version specific.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012924.c \
 *       --addr 0x02012924 --thumb
 */
struct Vec12 *func_02012AA0(struct Rec44_0 *p)
{
    return &p->unk04;
}


/*
 *           func_02012944, func_02012950, func_0201295C, func_02012964,
 *           func_0201296C, func_02012974, func_0201297C, func_02012984,
 *           func_0201298C, func_02012994, func_020129A0, func_020129AC,
 *           func_020129B8, func_020129C4, func_020129D0, func_020129DC,
 *           func_020129F0, func_020129FC, func_02012A24, func_02012A30,
 *           func_02012A38, func_02012A44, func_02012A4C, func_02012A54,
 *           func_02012A60, func_02012A90, func_02012AA0, func_02012AA4,
 *           func_02012AB8, func_02012ABC, func_02012AC0, func_02012AC4,
 *           func_02012AC8, func_02012ACC, func_02012AD0
 *
 * 432 bytes, 0x02012924..0x02012AD4, 39 functions, only nine of which carry a
 * label in the generated listing: the rest are leaf accessors that save no lr
 * and arrive in asm/arm9/src/004_02010BB8.s as runs of .word, which is
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Two objects are accessed here and they are not the same struct.
 *
 *  - BigObj is reached through a plain pointer argument and every field this
 *    file touches is past +0x18C, so each access is a register offset built
 *    with movs/lsls (0x63 << 2 is +0x18C) or, where the constant is not of
 *    that shape, out of the function's own literal pool (+0x1C5 .. +0x1CD).
 *    Those pool words are plain constants and carry no relocation.
 *  - Rec44 is the 0x44-byte record func_02012950 indexes, and func_02012A60
 *    onwards are its constructor and accessors.  func_02012A60 is the
 *    constructor: its store order is the source's statement order, and the
 *    two strb at +0x12 and +0x13 next to the strh at +0x10, +0x14 and +0x16
 *    are what make +0x10 a union of a four-halfword view (the one
 *    func_02012AA4 copies whole) and a five-field view.
 *
 * func_020129FC is a post-increment and not an assignment:
 * `return p->unk1C8++;` spends an extra `adds r1, r4, #0` copy that
 * `n = p->unk1C8; p->unk1C8 = n + 1; return n;` does not, and the two are
 * otherwise the same eighteen instructions.  See
 * docs/idioms/post-increment-of-a-field-spends-a-copy.md.
 *
 * The file stops at 0x02012AD4 because func_02012AD4 cannot be attested; see
 * the header of src/matched/unit_02012AE4.c for that near miss.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table, so none of it looks version specific.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012924.c \
 *       --addr 0x02012924 --thumb
 */
void func_02012AA4(struct Rec44_0 *p, const struct H4 *src)
{
    p->unk10.all = *src;
}


/*
 *           func_02012944, func_02012950, func_0201295C, func_02012964,
 *           func_0201296C, func_02012974, func_0201297C, func_02012984,
 *           func_0201298C, func_02012994, func_020129A0, func_020129AC,
 *           func_020129B8, func_020129C4, func_020129D0, func_020129DC,
 *           func_020129F0, func_020129FC, func_02012A24, func_02012A30,
 *           func_02012A38, func_02012A44, func_02012A4C, func_02012A54,
 *           func_02012A60, func_02012A90, func_02012AA0, func_02012AA4,
 *           func_02012AB8, func_02012ABC, func_02012AC0, func_02012AC4,
 *           func_02012AC8, func_02012ACC, func_02012AD0
 *
 * 432 bytes, 0x02012924..0x02012AD4, 39 functions, only nine of which carry a
 * label in the generated listing: the rest are leaf accessors that save no lr
 * and arrive in asm/arm9/src/004_02010BB8.s as runs of .word, which is
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Two objects are accessed here and they are not the same struct.
 *
 *  - BigObj is reached through a plain pointer argument and every field this
 *    file touches is past +0x18C, so each access is a register offset built
 *    with movs/lsls (0x63 << 2 is +0x18C) or, where the constant is not of
 *    that shape, out of the function's own literal pool (+0x1C5 .. +0x1CD).
 *    Those pool words are plain constants and carry no relocation.
 *  - Rec44 is the 0x44-byte record func_02012950 indexes, and func_02012A60
 *    onwards are its constructor and accessors.  func_02012A60 is the
 *    constructor: its store order is the source's statement order, and the
 *    two strb at +0x12 and +0x13 next to the strh at +0x10, +0x14 and +0x16
 *    are what make +0x10 a union of a four-halfword view (the one
 *    func_02012AA4 copies whole) and a five-field view.
 *
 * func_020129FC is a post-increment and not an assignment:
 * `return p->unk1C8++;` spends an extra `adds r1, r4, #0` copy that
 * `n = p->unk1C8; p->unk1C8 = n + 1; return n;` does not, and the two are
 * otherwise the same eighteen instructions.  See
 * docs/idioms/post-increment-of-a-field-spends-a-copy.md.
 *
 * The file stops at 0x02012AD4 because func_02012AD4 cannot be attested; see
 * the header of src/matched/unit_02012AE4.c for that near miss.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table, so none of it looks version specific.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012924.c \
 *       --addr 0x02012924 --thumb
 */
struct H4 *func_02012AB8(struct Rec44_0 *p)
{
    return &p->unk10.all;
}


/*
 *           func_02012944, func_02012950, func_0201295C, func_02012964,
 *           func_0201296C, func_02012974, func_0201297C, func_02012984,
 *           func_0201298C, func_02012994, func_020129A0, func_020129AC,
 *           func_020129B8, func_020129C4, func_020129D0, func_020129DC,
 *           func_020129F0, func_020129FC, func_02012A24, func_02012A30,
 *           func_02012A38, func_02012A44, func_02012A4C, func_02012A54,
 *           func_02012A60, func_02012A90, func_02012AA0, func_02012AA4,
 *           func_02012AB8, func_02012ABC, func_02012AC0, func_02012AC4,
 *           func_02012AC8, func_02012ACC, func_02012AD0
 *
 * 432 bytes, 0x02012924..0x02012AD4, 39 functions, only nine of which carry a
 * label in the generated listing: the rest are leaf accessors that save no lr
 * and arrive in asm/arm9/src/004_02010BB8.s as runs of .word, which is
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Two objects are accessed here and they are not the same struct.
 *
 *  - BigObj is reached through a plain pointer argument and every field this
 *    file touches is past +0x18C, so each access is a register offset built
 *    with movs/lsls (0x63 << 2 is +0x18C) or, where the constant is not of
 *    that shape, out of the function's own literal pool (+0x1C5 .. +0x1CD).
 *    Those pool words are plain constants and carry no relocation.
 *  - Rec44 is the 0x44-byte record func_02012950 indexes, and func_02012A60
 *    onwards are its constructor and accessors.  func_02012A60 is the
 *    constructor: its store order is the source's statement order, and the
 *    two strb at +0x12 and +0x13 next to the strh at +0x10, +0x14 and +0x16
 *    are what make +0x10 a union of a four-halfword view (the one
 *    func_02012AA4 copies whole) and a five-field view.
 *
 * func_020129FC is a post-increment and not an assignment:
 * `return p->unk1C8++;` spends an extra `adds r1, r4, #0` copy that
 * `n = p->unk1C8; p->unk1C8 = n + 1; return n;` does not, and the two are
 * otherwise the same eighteen instructions.  See
 * docs/idioms/post-increment-of-a-field-spends-a-copy.md.
 *
 * The file stops at 0x02012AD4 because func_02012AD4 cannot be attested; see
 * the header of src/matched/unit_02012AE4.c for that near miss.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table, so none of it looks version specific.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012924.c \
 *       --addr 0x02012924 --thumb
 */
void func_02012ABC(struct Rec44_0 *p, u8 v)
{
    p->unk1B = v;
}


/*
 *           func_02012944, func_02012950, func_0201295C, func_02012964,
 *           func_0201296C, func_02012974, func_0201297C, func_02012984,
 *           func_0201298C, func_02012994, func_020129A0, func_020129AC,
 *           func_020129B8, func_020129C4, func_020129D0, func_020129DC,
 *           func_020129F0, func_020129FC, func_02012A24, func_02012A30,
 *           func_02012A38, func_02012A44, func_02012A4C, func_02012A54,
 *           func_02012A60, func_02012A90, func_02012AA0, func_02012AA4,
 *           func_02012AB8, func_02012ABC, func_02012AC0, func_02012AC4,
 *           func_02012AC8, func_02012ACC, func_02012AD0
 *
 * 432 bytes, 0x02012924..0x02012AD4, 39 functions, only nine of which carry a
 * label in the generated listing: the rest are leaf accessors that save no lr
 * and arrive in asm/arm9/src/004_02010BB8.s as runs of .word, which is
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Two objects are accessed here and they are not the same struct.
 *
 *  - BigObj is reached through a plain pointer argument and every field this
 *    file touches is past +0x18C, so each access is a register offset built
 *    with movs/lsls (0x63 << 2 is +0x18C) or, where the constant is not of
 *    that shape, out of the function's own literal pool (+0x1C5 .. +0x1CD).
 *    Those pool words are plain constants and carry no relocation.
 *  - Rec44 is the 0x44-byte record func_02012950 indexes, and func_02012A60
 *    onwards are its constructor and accessors.  func_02012A60 is the
 *    constructor: its store order is the source's statement order, and the
 *    two strb at +0x12 and +0x13 next to the strh at +0x10, +0x14 and +0x16
 *    are what make +0x10 a union of a four-halfword view (the one
 *    func_02012AA4 copies whole) and a five-field view.
 *
 * func_020129FC is a post-increment and not an assignment:
 * `return p->unk1C8++;` spends an extra `adds r1, r4, #0` copy that
 * `n = p->unk1C8; p->unk1C8 = n + 1; return n;` does not, and the two are
 * otherwise the same eighteen instructions.  See
 * docs/idioms/post-increment-of-a-field-spends-a-copy.md.
 *
 * The file stops at 0x02012AD4 because func_02012AD4 cannot be attested; see
 * the header of src/matched/unit_02012AE4.c for that near miss.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table, so none of it looks version specific.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012924.c \
 *       --addr 0x02012924 --thumb
 */
u8 func_02012AC0(const struct Rec44_0 *p)
{
    return p->unk1B;
}


/*
 *           func_02012944, func_02012950, func_0201295C, func_02012964,
 *           func_0201296C, func_02012974, func_0201297C, func_02012984,
 *           func_0201298C, func_02012994, func_020129A0, func_020129AC,
 *           func_020129B8, func_020129C4, func_020129D0, func_020129DC,
 *           func_020129F0, func_020129FC, func_02012A24, func_02012A30,
 *           func_02012A38, func_02012A44, func_02012A4C, func_02012A54,
 *           func_02012A60, func_02012A90, func_02012AA0, func_02012AA4,
 *           func_02012AB8, func_02012ABC, func_02012AC0, func_02012AC4,
 *           func_02012AC8, func_02012ACC, func_02012AD0
 *
 * 432 bytes, 0x02012924..0x02012AD4, 39 functions, only nine of which carry a
 * label in the generated listing: the rest are leaf accessors that save no lr
 * and arrive in asm/arm9/src/004_02010BB8.s as runs of .word, which is
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Two objects are accessed here and they are not the same struct.
 *
 *  - BigObj is reached through a plain pointer argument and every field this
 *    file touches is past +0x18C, so each access is a register offset built
 *    with movs/lsls (0x63 << 2 is +0x18C) or, where the constant is not of
 *    that shape, out of the function's own literal pool (+0x1C5 .. +0x1CD).
 *    Those pool words are plain constants and carry no relocation.
 *  - Rec44 is the 0x44-byte record func_02012950 indexes, and func_02012A60
 *    onwards are its constructor and accessors.  func_02012A60 is the
 *    constructor: its store order is the source's statement order, and the
 *    two strb at +0x12 and +0x13 next to the strh at +0x10, +0x14 and +0x16
 *    are what make +0x10 a union of a four-halfword view (the one
 *    func_02012AA4 copies whole) and a five-field view.
 *
 * func_020129FC is a post-increment and not an assignment:
 * `return p->unk1C8++;` spends an extra `adds r1, r4, #0` copy that
 * `n = p->unk1C8; p->unk1C8 = n + 1; return n;` does not, and the two are
 * otherwise the same eighteen instructions.  See
 * docs/idioms/post-increment-of-a-field-spends-a-copy.md.
 *
 * The file stops at 0x02012AD4 because func_02012AD4 cannot be attested; see
 * the header of src/matched/unit_02012AE4.c for that near miss.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table, so none of it looks version specific.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012924.c \
 *       --addr 0x02012924 --thumb
 */
struct Rec44_0 *func_02012AC4(struct Rec44_0 *p, u16 v)
{
    p->unk00 = v;
    return p;
}


/*
 *           func_02012944, func_02012950, func_0201295C, func_02012964,
 *           func_0201296C, func_02012974, func_0201297C, func_02012984,
 *           func_0201298C, func_02012994, func_020129A0, func_020129AC,
 *           func_020129B8, func_020129C4, func_020129D0, func_020129DC,
 *           func_020129F0, func_020129FC, func_02012A24, func_02012A30,
 *           func_02012A38, func_02012A44, func_02012A4C, func_02012A54,
 *           func_02012A60, func_02012A90, func_02012AA0, func_02012AA4,
 *           func_02012AB8, func_02012ABC, func_02012AC0, func_02012AC4,
 *           func_02012AC8, func_02012ACC, func_02012AD0
 *
 * 432 bytes, 0x02012924..0x02012AD4, 39 functions, only nine of which carry a
 * label in the generated listing: the rest are leaf accessors that save no lr
 * and arrive in asm/arm9/src/004_02010BB8.s as runs of .word, which is
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Two objects are accessed here and they are not the same struct.
 *
 *  - BigObj is reached through a plain pointer argument and every field this
 *    file touches is past +0x18C, so each access is a register offset built
 *    with movs/lsls (0x63 << 2 is +0x18C) or, where the constant is not of
 *    that shape, out of the function's own literal pool (+0x1C5 .. +0x1CD).
 *    Those pool words are plain constants and carry no relocation.
 *  - Rec44 is the 0x44-byte record func_02012950 indexes, and func_02012A60
 *    onwards are its constructor and accessors.  func_02012A60 is the
 *    constructor: its store order is the source's statement order, and the
 *    two strb at +0x12 and +0x13 next to the strh at +0x10, +0x14 and +0x16
 *    are what make +0x10 a union of a four-halfword view (the one
 *    func_02012AA4 copies whole) and a five-field view.
 *
 * func_020129FC is a post-increment and not an assignment:
 * `return p->unk1C8++;` spends an extra `adds r1, r4, #0` copy that
 * `n = p->unk1C8; p->unk1C8 = n + 1; return n;` does not, and the two are
 * otherwise the same eighteen instructions.  See
 * docs/idioms/post-increment-of-a-field-spends-a-copy.md.
 *
 * The file stops at 0x02012AD4 because func_02012AD4 cannot be attested; see
 * the header of src/matched/unit_02012AE4.c for that near miss.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table, so none of it looks version specific.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012924.c \
 *       --addr 0x02012924 --thumb
 */
u16 func_02012AC8(const struct Rec44_0 *p)
{
    return p->unk00;
}


/*
 *           func_02012944, func_02012950, func_0201295C, func_02012964,
 *           func_0201296C, func_02012974, func_0201297C, func_02012984,
 *           func_0201298C, func_02012994, func_020129A0, func_020129AC,
 *           func_020129B8, func_020129C4, func_020129D0, func_020129DC,
 *           func_020129F0, func_020129FC, func_02012A24, func_02012A30,
 *           func_02012A38, func_02012A44, func_02012A4C, func_02012A54,
 *           func_02012A60, func_02012A90, func_02012AA0, func_02012AA4,
 *           func_02012AB8, func_02012ABC, func_02012AC0, func_02012AC4,
 *           func_02012AC8, func_02012ACC, func_02012AD0
 *
 * 432 bytes, 0x02012924..0x02012AD4, 39 functions, only nine of which carry a
 * label in the generated listing: the rest are leaf accessors that save no lr
 * and arrive in asm/arm9/src/004_02010BB8.s as runs of .word, which is
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Two objects are accessed here and they are not the same struct.
 *
 *  - BigObj is reached through a plain pointer argument and every field this
 *    file touches is past +0x18C, so each access is a register offset built
 *    with movs/lsls (0x63 << 2 is +0x18C) or, where the constant is not of
 *    that shape, out of the function's own literal pool (+0x1C5 .. +0x1CD).
 *    Those pool words are plain constants and carry no relocation.
 *  - Rec44 is the 0x44-byte record func_02012950 indexes, and func_02012A60
 *    onwards are its constructor and accessors.  func_02012A60 is the
 *    constructor: its store order is the source's statement order, and the
 *    two strb at +0x12 and +0x13 next to the strh at +0x10, +0x14 and +0x16
 *    are what make +0x10 a union of a four-halfword view (the one
 *    func_02012AA4 copies whole) and a five-field view.
 *
 * func_020129FC is a post-increment and not an assignment:
 * `return p->unk1C8++;` spends an extra `adds r1, r4, #0` copy that
 * `n = p->unk1C8; p->unk1C8 = n + 1; return n;` does not, and the two are
 * otherwise the same eighteen instructions.  See
 * docs/idioms/post-increment-of-a-field-spends-a-copy.md.
 *
 * The file stops at 0x02012AD4 because func_02012AD4 cannot be attested; see
 * the header of src/matched/unit_02012AE4.c for that near miss.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table, so none of it looks version specific.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012924.c \
 *       --addr 0x02012924 --thumb
 */
void func_02012ACC(struct Rec44_0 *p, int v)
{
    p->unk18 = v;
}


/*
 *           func_02012944, func_02012950, func_0201295C, func_02012964,
 *           func_0201296C, func_02012974, func_0201297C, func_02012984,
 *           func_0201298C, func_02012994, func_020129A0, func_020129AC,
 *           func_020129B8, func_020129C4, func_020129D0, func_020129DC,
 *           func_020129F0, func_020129FC, func_02012A24, func_02012A30,
 *           func_02012A38, func_02012A44, func_02012A4C, func_02012A54,
 *           func_02012A60, func_02012A90, func_02012AA0, func_02012AA4,
 *           func_02012AB8, func_02012ABC, func_02012AC0, func_02012AC4,
 *           func_02012AC8, func_02012ACC, func_02012AD0
 *
 * 432 bytes, 0x02012924..0x02012AD4, 39 functions, only nine of which carry a
 * label in the generated listing: the rest are leaf accessors that save no lr
 * and arrive in asm/arm9/src/004_02010BB8.s as runs of .word, which is
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Two objects are accessed here and they are not the same struct.
 *
 *  - BigObj is reached through a plain pointer argument and every field this
 *    file touches is past +0x18C, so each access is a register offset built
 *    with movs/lsls (0x63 << 2 is +0x18C) or, where the constant is not of
 *    that shape, out of the function's own literal pool (+0x1C5 .. +0x1CD).
 *    Those pool words are plain constants and carry no relocation.
 *  - Rec44 is the 0x44-byte record func_02012950 indexes, and func_02012A60
 *    onwards are its constructor and accessors.  func_02012A60 is the
 *    constructor: its store order is the source's statement order, and the
 *    two strb at +0x12 and +0x13 next to the strh at +0x10, +0x14 and +0x16
 *    are what make +0x10 a union of a four-halfword view (the one
 *    func_02012AA4 copies whole) and a five-field view.
 *
 * func_020129FC is a post-increment and not an assignment:
 * `return p->unk1C8++;` spends an extra `adds r1, r4, #0` copy that
 * `n = p->unk1C8; p->unk1C8 = n + 1; return n;` does not, and the two are
 * otherwise the same eighteen instructions.  See
 * docs/idioms/post-increment-of-a-field-spends-a-copy.md.
 *
 * The file stops at 0x02012AD4 because func_02012AD4 cannot be attested; see
 * the header of src/matched/unit_02012AE4.c for that near miss.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table, so none of it looks version specific.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012924.c \
 *       --addr 0x02012924 --thumb
 */
u16 func_02012AD0(const struct Rec44_0 *p)
{
    return p->unk18;
}


void func_02012AD4(u8 *p, int i)
{
    ((struct Obj15629 *)p)->f18 = data_0209DFA8[i];
}


/*
 *           func_02012B34, func_02012B38, func_02012B40, func_02012B4C,
 *           func_02012B58, func_02012B64, func_02012B70, func_02012B78,
 *           func_02012B80, func_02012B8C, func_02012B98, func_02012BA4,
 *           func_02012BB0
 *
 * 228 bytes, 0x02012AE4..0x02012BC8, 17 functions, the continuation of
 * src/matched/unit_02012924.c across two near misses.  The same two objects:
 * Rec44 for func_02012AE4 .. func_02012B34 and BigObj from func_02012B38 on.
 *
 * func_02012AE4 buckets the Rec44 field at +0x18 into 0, 1, 2 or 3.  The
 * result local has to be declared **before** the field is read into its own
 * local, or the compiler puts the result in r0, keeps its scratch in r1 and
 * duplicates `bx lr` into every arm instead of branching to one
 * `adds r0, r1, #0; bx lr` tail; that spelling is 28 concrete bytes wrong and
 * two bytes short with identical control flow.  Seven source shapes were
 * compiled and only the two with the result declared first are EXACT.
 *
 * Two near misses bracket this file, and neither is a codegen failure: both
 * reproduce every concrete byte and are held at MATCH by the honesty rule.
 *
 *  - 0x02012AD4, 16 bytes, `p->unk18 = Table[i];` over a u16 table at
 *    0x0209DFA8.  That address appears in exactly one literal pool in the
 *    image, the one inside this function, so the `literal` class discards its
 *    only witness and no cut helps.  It is data, so no label will ever exist
 *    for it.  The source is
 *
 *        void func_02012AD4(struct Rec44 *p, u32 i)
 *        {
 *            p->unk18 = func_02012AD4_Table[i];
 *        }
 *
 *    with `func_02012AD4_Table 0x0209DFA8 data`.  Evidence class: literal, 0
 *    witnesses outside.
 *  - 0x02012BC8, 24 bytes, a tail call through a pool word holding
 *    0x02008451.  0x02008450 is a real Thumb function (the setter whose
 *    getter is the labelled func_02008448 four bytes earlier) but it opens
 *    with no register-saving prologue, so disasm.py never labelled it, and
 *    this pool word is the only reference to it anywhere in the image.  The
 *    source is
 *
 *        void func_02012BC8(struct BigObj *p, u32 v)
 *        {
 *            func_02008450(p->unk198, v != 0);
 *        }
 *
 *    0x02008450 goes into layout/function_starts.txt with a branch that
 *    attests it, which this file cannot provide because it is the only user.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012AE4.c \
 *       --addr 0x02012AE4 --thumb
 */
u32 func_02012AE4(const struct Rec44_1 *p)
{
    u32 r = 0;
    u16 v = p->unk18;

    if (v > 0x2000 && v < 0x6000) {
        r = 2;
    } else if (v >= 0x6000 && v <= 0xA000) {
        r = 1;
    } else if (v > 0xA000 && v < 0xE000) {
        r = 3;
    }
    return r;
}


/*
 *           func_02012B34, func_02012B38, func_02012B40, func_02012B4C,
 *           func_02012B58, func_02012B64, func_02012B70, func_02012B78,
 *           func_02012B80, func_02012B8C, func_02012B98, func_02012BA4,
 *           func_02012BB0
 *
 * 228 bytes, 0x02012AE4..0x02012BC8, 17 functions, the continuation of
 * src/matched/unit_02012924.c across two near misses.  The same two objects:
 * Rec44 for func_02012AE4 .. func_02012B34 and BigObj from func_02012B38 on.
 *
 * func_02012AE4 buckets the Rec44 field at +0x18 into 0, 1, 2 or 3.  The
 * result local has to be declared **before** the field is read into its own
 * local, or the compiler puts the result in r0, keeps its scratch in r1 and
 * duplicates `bx lr` into every arm instead of branching to one
 * `adds r0, r1, #0; bx lr` tail; that spelling is 28 concrete bytes wrong and
 * two bytes short with identical control flow.  Seven source shapes were
 * compiled and only the two with the result declared first are EXACT.
 *
 * Two near misses bracket this file, and neither is a codegen failure: both
 * reproduce every concrete byte and are held at MATCH by the honesty rule.
 *
 *  - 0x02012AD4, 16 bytes, `p->unk18 = Table[i];` over a u16 table at
 *    0x0209DFA8.  That address appears in exactly one literal pool in the
 *    image, the one inside this function, so the `literal` class discards its
 *    only witness and no cut helps.  It is data, so no label will ever exist
 *    for it.  The source is
 *
 *        void func_02012AD4(struct Rec44 *p, u32 i)
 *        {
 *            p->unk18 = func_02012AD4_Table[i];
 *        }
 *
 *    with `func_02012AD4_Table 0x0209DFA8 data`.  Evidence class: literal, 0
 *    witnesses outside.
 *  - 0x02012BC8, 24 bytes, a tail call through a pool word holding
 *    0x02008451.  0x02008450 is a real Thumb function (the setter whose
 *    getter is the labelled func_02008448 four bytes earlier) but it opens
 *    with no register-saving prologue, so disasm.py never labelled it, and
 *    this pool word is the only reference to it anywhere in the image.  The
 *    source is
 *
 *        void func_02012BC8(struct BigObj *p, u32 v)
 *        {
 *            func_02008450(p->unk198, v != 0);
 *        }
 *
 *    0x02008450 goes into layout/function_starts.txt with a branch that
 *    attests it, which this file cannot provide because it is the only user.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012AE4.c \
 *       --addr 0x02012AE4 --thumb
 */
u32 func_02012B28(const struct Rec44_1 *p)
{
    return p->unk40;
}


/*
 *           func_02012B34, func_02012B38, func_02012B40, func_02012B4C,
 *           func_02012B58, func_02012B64, func_02012B70, func_02012B78,
 *           func_02012B80, func_02012B8C, func_02012B98, func_02012BA4,
 *           func_02012BB0
 *
 * 228 bytes, 0x02012AE4..0x02012BC8, 17 functions, the continuation of
 * src/matched/unit_02012924.c across two near misses.  The same two objects:
 * Rec44 for func_02012AE4 .. func_02012B34 and BigObj from func_02012B38 on.
 *
 * func_02012AE4 buckets the Rec44 field at +0x18 into 0, 1, 2 or 3.  The
 * result local has to be declared **before** the field is read into its own
 * local, or the compiler puts the result in r0, keeps its scratch in r1 and
 * duplicates `bx lr` into every arm instead of branching to one
 * `adds r0, r1, #0; bx lr` tail; that spelling is 28 concrete bytes wrong and
 * two bytes short with identical control flow.  Seven source shapes were
 * compiled and only the two with the result declared first are EXACT.
 *
 * Two near misses bracket this file, and neither is a codegen failure: both
 * reproduce every concrete byte and are held at MATCH by the honesty rule.
 *
 *  - 0x02012AD4, 16 bytes, `p->unk18 = Table[i];` over a u16 table at
 *    0x0209DFA8.  That address appears in exactly one literal pool in the
 *    image, the one inside this function, so the `literal` class discards its
 *    only witness and no cut helps.  It is data, so no label will ever exist
 *    for it.  The source is
 *
 *        void func_02012AD4(struct Rec44 *p, u32 i)
 *        {
 *            p->unk18 = func_02012AD4_Table[i];
 *        }
 *
 *    with `func_02012AD4_Table 0x0209DFA8 data`.  Evidence class: literal, 0
 *    witnesses outside.
 *  - 0x02012BC8, 24 bytes, a tail call through a pool word holding
 *    0x02008451.  0x02008450 is a real Thumb function (the setter whose
 *    getter is the labelled func_02008448 four bytes earlier) but it opens
 *    with no register-saving prologue, so disasm.py never labelled it, and
 *    this pool word is the only reference to it anywhere in the image.  The
 *    source is
 *
 *        void func_02012BC8(struct BigObj *p, u32 v)
 *        {
 *            func_02008450(p->unk198, v != 0);
 *        }
 *
 *    0x02008450 goes into layout/function_starts.txt with a branch that
 *    attests it, which this file cannot provide because it is the only user.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012AE4.c \
 *       --addr 0x02012AE4 --thumb
 */
void func_02012B2C(struct Rec44_1 *p, u32 v)
{
    p->unk40 = v;
}


/*
 *           func_02012B34, func_02012B38, func_02012B40, func_02012B4C,
 *           func_02012B58, func_02012B64, func_02012B70, func_02012B78,
 *           func_02012B80, func_02012B8C, func_02012B98, func_02012BA4,
 *           func_02012BB0
 *
 * 228 bytes, 0x02012AE4..0x02012BC8, 17 functions, the continuation of
 * src/matched/unit_02012924.c across two near misses.  The same two objects:
 * Rec44 for func_02012AE4 .. func_02012B34 and BigObj from func_02012B38 on.
 *
 * func_02012AE4 buckets the Rec44 field at +0x18 into 0, 1, 2 or 3.  The
 * result local has to be declared **before** the field is read into its own
 * local, or the compiler puts the result in r0, keeps its scratch in r1 and
 * duplicates `bx lr` into every arm instead of branching to one
 * `adds r0, r1, #0; bx lr` tail; that spelling is 28 concrete bytes wrong and
 * two bytes short with identical control flow.  Seven source shapes were
 * compiled and only the two with the result declared first are EXACT.
 *
 * Two near misses bracket this file, and neither is a codegen failure: both
 * reproduce every concrete byte and are held at MATCH by the honesty rule.
 *
 *  - 0x02012AD4, 16 bytes, `p->unk18 = Table[i];` over a u16 table at
 *    0x0209DFA8.  That address appears in exactly one literal pool in the
 *    image, the one inside this function, so the `literal` class discards its
 *    only witness and no cut helps.  It is data, so no label will ever exist
 *    for it.  The source is
 *
 *        void func_02012AD4(struct Rec44 *p, u32 i)
 *        {
 *            p->unk18 = func_02012AD4_Table[i];
 *        }
 *
 *    with `func_02012AD4_Table 0x0209DFA8 data`.  Evidence class: literal, 0
 *    witnesses outside.
 *  - 0x02012BC8, 24 bytes, a tail call through a pool word holding
 *    0x02008451.  0x02008450 is a real Thumb function (the setter whose
 *    getter is the labelled func_02008448 four bytes earlier) but it opens
 *    with no register-saving prologue, so disasm.py never labelled it, and
 *    this pool word is the only reference to it anywhere in the image.  The
 *    source is
 *
 *        void func_02012BC8(struct BigObj *p, u32 v)
 *        {
 *            func_02008450(p->unk198, v != 0);
 *        }
 *
 *    0x02008450 goes into layout/function_starts.txt with a branch that
 *    attests it, which this file cannot provide because it is the only user.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012AE4.c \
 *       --addr 0x02012AE4 --thumb
 */
void func_02012B30(struct Rec44_1 *p, u16 v)
{
    p->unk1C = v;
}


/*
 *           func_02012B34, func_02012B38, func_02012B40, func_02012B4C,
 *           func_02012B58, func_02012B64, func_02012B70, func_02012B78,
 *           func_02012B80, func_02012B8C, func_02012B98, func_02012BA4,
 *           func_02012BB0
 *
 * 228 bytes, 0x02012AE4..0x02012BC8, 17 functions, the continuation of
 * src/matched/unit_02012924.c across two near misses.  The same two objects:
 * Rec44 for func_02012AE4 .. func_02012B34 and BigObj from func_02012B38 on.
 *
 * func_02012AE4 buckets the Rec44 field at +0x18 into 0, 1, 2 or 3.  The
 * result local has to be declared **before** the field is read into its own
 * local, or the compiler puts the result in r0, keeps its scratch in r1 and
 * duplicates `bx lr` into every arm instead of branching to one
 * `adds r0, r1, #0; bx lr` tail; that spelling is 28 concrete bytes wrong and
 * two bytes short with identical control flow.  Seven source shapes were
 * compiled and only the two with the result declared first are EXACT.
 *
 * Two near misses bracket this file, and neither is a codegen failure: both
 * reproduce every concrete byte and are held at MATCH by the honesty rule.
 *
 *  - 0x02012AD4, 16 bytes, `p->unk18 = Table[i];` over a u16 table at
 *    0x0209DFA8.  That address appears in exactly one literal pool in the
 *    image, the one inside this function, so the `literal` class discards its
 *    only witness and no cut helps.  It is data, so no label will ever exist
 *    for it.  The source is
 *
 *        void func_02012AD4(struct Rec44 *p, u32 i)
 *        {
 *            p->unk18 = func_02012AD4_Table[i];
 *        }
 *
 *    with `func_02012AD4_Table 0x0209DFA8 data`.  Evidence class: literal, 0
 *    witnesses outside.
 *  - 0x02012BC8, 24 bytes, a tail call through a pool word holding
 *    0x02008451.  0x02008450 is a real Thumb function (the setter whose
 *    getter is the labelled func_02008448 four bytes earlier) but it opens
 *    with no register-saving prologue, so disasm.py never labelled it, and
 *    this pool word is the only reference to it anywhere in the image.  The
 *    source is
 *
 *        void func_02012BC8(struct BigObj *p, u32 v)
 *        {
 *            func_02008450(p->unk198, v != 0);
 *        }
 *
 *    0x02008450 goes into layout/function_starts.txt with a branch that
 *    attests it, which this file cannot provide because it is the only user.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012AE4.c \
 *       --addr 0x02012AE4 --thumb
 */
u16 func_02012B34(const struct Rec44_1 *p)
{
    return p->unk1C;
}


/*
 *           func_02012B34, func_02012B38, func_02012B40, func_02012B4C,
 *           func_02012B58, func_02012B64, func_02012B70, func_02012B78,
 *           func_02012B80, func_02012B8C, func_02012B98, func_02012BA4,
 *           func_02012BB0
 *
 * 228 bytes, 0x02012AE4..0x02012BC8, 17 functions, the continuation of
 * src/matched/unit_02012924.c across two near misses.  The same two objects:
 * Rec44 for func_02012AE4 .. func_02012B34 and BigObj from func_02012B38 on.
 *
 * func_02012AE4 buckets the Rec44 field at +0x18 into 0, 1, 2 or 3.  The
 * result local has to be declared **before** the field is read into its own
 * local, or the compiler puts the result in r0, keeps its scratch in r1 and
 * duplicates `bx lr` into every arm instead of branching to one
 * `adds r0, r1, #0; bx lr` tail; that spelling is 28 concrete bytes wrong and
 * two bytes short with identical control flow.  Seven source shapes were
 * compiled and only the two with the result declared first are EXACT.
 *
 * Two near misses bracket this file, and neither is a codegen failure: both
 * reproduce every concrete byte and are held at MATCH by the honesty rule.
 *
 *  - 0x02012AD4, 16 bytes, `p->unk18 = Table[i];` over a u16 table at
 *    0x0209DFA8.  That address appears in exactly one literal pool in the
 *    image, the one inside this function, so the `literal` class discards its
 *    only witness and no cut helps.  It is data, so no label will ever exist
 *    for it.  The source is
 *
 *        void func_02012AD4(struct Rec44 *p, u32 i)
 *        {
 *            p->unk18 = func_02012AD4_Table[i];
 *        }
 *
 *    with `func_02012AD4_Table 0x0209DFA8 data`.  Evidence class: literal, 0
 *    witnesses outside.
 *  - 0x02012BC8, 24 bytes, a tail call through a pool word holding
 *    0x02008451.  0x02008450 is a real Thumb function (the setter whose
 *    getter is the labelled func_02008448 four bytes earlier) but it opens
 *    with no register-saving prologue, so disasm.py never labelled it, and
 *    this pool word is the only reference to it anywhere in the image.  The
 *    source is
 *
 *        void func_02012BC8(struct BigObj *p, u32 v)
 *        {
 *            func_02008450(p->unk198, v != 0);
 *        }
 *
 *    0x02008450 goes into layout/function_starts.txt with a branch that
 *    attests it, which this file cannot provide because it is the only user.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012AE4.c \
 *       --addr 0x02012AE4 --thumb
 */
void *func_02012B38(const struct BigObj_02012AE4 *p)
{
    return p->unk1B8;
}


/*
 *           func_02012B34, func_02012B38, func_02012B40, func_02012B4C,
 *           func_02012B58, func_02012B64, func_02012B70, func_02012B78,
 *           func_02012B80, func_02012B8C, func_02012B98, func_02012BA4,
 *           func_02012BB0
 *
 * 228 bytes, 0x02012AE4..0x02012BC8, 17 functions, the continuation of
 * src/matched/unit_02012924.c across two near misses.  The same two objects:
 * Rec44 for func_02012AE4 .. func_02012B34 and BigObj from func_02012B38 on.
 *
 * func_02012AE4 buckets the Rec44 field at +0x18 into 0, 1, 2 or 3.  The
 * result local has to be declared **before** the field is read into its own
 * local, or the compiler puts the result in r0, keeps its scratch in r1 and
 * duplicates `bx lr` into every arm instead of branching to one
 * `adds r0, r1, #0; bx lr` tail; that spelling is 28 concrete bytes wrong and
 * two bytes short with identical control flow.  Seven source shapes were
 * compiled and only the two with the result declared first are EXACT.
 *
 * Two near misses bracket this file, and neither is a codegen failure: both
 * reproduce every concrete byte and are held at MATCH by the honesty rule.
 *
 *  - 0x02012AD4, 16 bytes, `p->unk18 = Table[i];` over a u16 table at
 *    0x0209DFA8.  That address appears in exactly one literal pool in the
 *    image, the one inside this function, so the `literal` class discards its
 *    only witness and no cut helps.  It is data, so no label will ever exist
 *    for it.  The source is
 *
 *        void func_02012AD4(struct Rec44 *p, u32 i)
 *        {
 *            p->unk18 = func_02012AD4_Table[i];
 *        }
 *
 *    with `func_02012AD4_Table 0x0209DFA8 data`.  Evidence class: literal, 0
 *    witnesses outside.
 *  - 0x02012BC8, 24 bytes, a tail call through a pool word holding
 *    0x02008451.  0x02008450 is a real Thumb function (the setter whose
 *    getter is the labelled func_02008448 four bytes earlier) but it opens
 *    with no register-saving prologue, so disasm.py never labelled it, and
 *    this pool word is the only reference to it anywhere in the image.  The
 *    source is
 *
 *        void func_02012BC8(struct BigObj *p, u32 v)
 *        {
 *            func_02008450(p->unk198, v != 0);
 *        }
 *
 *    0x02008450 goes into layout/function_starts.txt with a branch that
 *    attests it, which this file cannot provide because it is the only user.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012AE4.c \
 *       --addr 0x02012AE4 --thumb
 */
u8 func_02012B40(const struct BigObj_02012AE4 *p)
{
    return p->unk1CA;
}


/*
 *           func_02012B34, func_02012B38, func_02012B40, func_02012B4C,
 *           func_02012B58, func_02012B64, func_02012B70, func_02012B78,
 *           func_02012B80, func_02012B8C, func_02012B98, func_02012BA4,
 *           func_02012BB0
 *
 * 228 bytes, 0x02012AE4..0x02012BC8, 17 functions, the continuation of
 * src/matched/unit_02012924.c across two near misses.  The same two objects:
 * Rec44 for func_02012AE4 .. func_02012B34 and BigObj from func_02012B38 on.
 *
 * func_02012AE4 buckets the Rec44 field at +0x18 into 0, 1, 2 or 3.  The
 * result local has to be declared **before** the field is read into its own
 * local, or the compiler puts the result in r0, keeps its scratch in r1 and
 * duplicates `bx lr` into every arm instead of branching to one
 * `adds r0, r1, #0; bx lr` tail; that spelling is 28 concrete bytes wrong and
 * two bytes short with identical control flow.  Seven source shapes were
 * compiled and only the two with the result declared first are EXACT.
 *
 * Two near misses bracket this file, and neither is a codegen failure: both
 * reproduce every concrete byte and are held at MATCH by the honesty rule.
 *
 *  - 0x02012AD4, 16 bytes, `p->unk18 = Table[i];` over a u16 table at
 *    0x0209DFA8.  That address appears in exactly one literal pool in the
 *    image, the one inside this function, so the `literal` class discards its
 *    only witness and no cut helps.  It is data, so no label will ever exist
 *    for it.  The source is
 *
 *        void func_02012AD4(struct Rec44 *p, u32 i)
 *        {
 *            p->unk18 = func_02012AD4_Table[i];
 *        }
 *
 *    with `func_02012AD4_Table 0x0209DFA8 data`.  Evidence class: literal, 0
 *    witnesses outside.
 *  - 0x02012BC8, 24 bytes, a tail call through a pool word holding
 *    0x02008451.  0x02008450 is a real Thumb function (the setter whose
 *    getter is the labelled func_02008448 four bytes earlier) but it opens
 *    with no register-saving prologue, so disasm.py never labelled it, and
 *    this pool word is the only reference to it anywhere in the image.  The
 *    source is
 *
 *        void func_02012BC8(struct BigObj *p, u32 v)
 *        {
 *            func_02008450(p->unk198, v != 0);
 *        }
 *
 *    0x02008450 goes into layout/function_starts.txt with a branch that
 *    attests it, which this file cannot provide because it is the only user.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012AE4.c \
 *       --addr 0x02012AE4 --thumb
 */
void func_02012B4C(struct BigObj_02012AE4 *p, u8 v)
{
    p->unk1CA = v;
}


/*
 *           func_02012B34, func_02012B38, func_02012B40, func_02012B4C,
 *           func_02012B58, func_02012B64, func_02012B70, func_02012B78,
 *           func_02012B80, func_02012B8C, func_02012B98, func_02012BA4,
 *           func_02012BB0
 *
 * 228 bytes, 0x02012AE4..0x02012BC8, 17 functions, the continuation of
 * src/matched/unit_02012924.c across two near misses.  The same two objects:
 * Rec44 for func_02012AE4 .. func_02012B34 and BigObj from func_02012B38 on.
 *
 * func_02012AE4 buckets the Rec44 field at +0x18 into 0, 1, 2 or 3.  The
 * result local has to be declared **before** the field is read into its own
 * local, or the compiler puts the result in r0, keeps its scratch in r1 and
 * duplicates `bx lr` into every arm instead of branching to one
 * `adds r0, r1, #0; bx lr` tail; that spelling is 28 concrete bytes wrong and
 * two bytes short with identical control flow.  Seven source shapes were
 * compiled and only the two with the result declared first are EXACT.
 *
 * Two near misses bracket this file, and neither is a codegen failure: both
 * reproduce every concrete byte and are held at MATCH by the honesty rule.
 *
 *  - 0x02012AD4, 16 bytes, `p->unk18 = Table[i];` over a u16 table at
 *    0x0209DFA8.  That address appears in exactly one literal pool in the
 *    image, the one inside this function, so the `literal` class discards its
 *    only witness and no cut helps.  It is data, so no label will ever exist
 *    for it.  The source is
 *
 *        void func_02012AD4(struct Rec44 *p, u32 i)
 *        {
 *            p->unk18 = func_02012AD4_Table[i];
 *        }
 *
 *    with `func_02012AD4_Table 0x0209DFA8 data`.  Evidence class: literal, 0
 *    witnesses outside.
 *  - 0x02012BC8, 24 bytes, a tail call through a pool word holding
 *    0x02008451.  0x02008450 is a real Thumb function (the setter whose
 *    getter is the labelled func_02008448 four bytes earlier) but it opens
 *    with no register-saving prologue, so disasm.py never labelled it, and
 *    this pool word is the only reference to it anywhere in the image.  The
 *    source is
 *
 *        void func_02012BC8(struct BigObj *p, u32 v)
 *        {
 *            func_02008450(p->unk198, v != 0);
 *        }
 *
 *    0x02008450 goes into layout/function_starts.txt with a branch that
 *    attests it, which this file cannot provide because it is the only user.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012AE4.c \
 *       --addr 0x02012AE4 --thumb
 */
u8 func_02012B58(const struct BigObj_02012AE4 *p)
{
    return p->unk1CB;
}


/*
 *           func_02012B34, func_02012B38, func_02012B40, func_02012B4C,
 *           func_02012B58, func_02012B64, func_02012B70, func_02012B78,
 *           func_02012B80, func_02012B8C, func_02012B98, func_02012BA4,
 *           func_02012BB0
 *
 * 228 bytes, 0x02012AE4..0x02012BC8, 17 functions, the continuation of
 * src/matched/unit_02012924.c across two near misses.  The same two objects:
 * Rec44 for func_02012AE4 .. func_02012B34 and BigObj from func_02012B38 on.
 *
 * func_02012AE4 buckets the Rec44 field at +0x18 into 0, 1, 2 or 3.  The
 * result local has to be declared **before** the field is read into its own
 * local, or the compiler puts the result in r0, keeps its scratch in r1 and
 * duplicates `bx lr` into every arm instead of branching to one
 * `adds r0, r1, #0; bx lr` tail; that spelling is 28 concrete bytes wrong and
 * two bytes short with identical control flow.  Seven source shapes were
 * compiled and only the two with the result declared first are EXACT.
 *
 * Two near misses bracket this file, and neither is a codegen failure: both
 * reproduce every concrete byte and are held at MATCH by the honesty rule.
 *
 *  - 0x02012AD4, 16 bytes, `p->unk18 = Table[i];` over a u16 table at
 *    0x0209DFA8.  That address appears in exactly one literal pool in the
 *    image, the one inside this function, so the `literal` class discards its
 *    only witness and no cut helps.  It is data, so no label will ever exist
 *    for it.  The source is
 *
 *        void func_02012AD4(struct Rec44 *p, u32 i)
 *        {
 *            p->unk18 = func_02012AD4_Table[i];
 *        }
 *
 *    with `func_02012AD4_Table 0x0209DFA8 data`.  Evidence class: literal, 0
 *    witnesses outside.
 *  - 0x02012BC8, 24 bytes, a tail call through a pool word holding
 *    0x02008451.  0x02008450 is a real Thumb function (the setter whose
 *    getter is the labelled func_02008448 four bytes earlier) but it opens
 *    with no register-saving prologue, so disasm.py never labelled it, and
 *    this pool word is the only reference to it anywhere in the image.  The
 *    source is
 *
 *        void func_02012BC8(struct BigObj *p, u32 v)
 *        {
 *            func_02008450(p->unk198, v != 0);
 *        }
 *
 *    0x02008450 goes into layout/function_starts.txt with a branch that
 *    attests it, which this file cannot provide because it is the only user.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012AE4.c \
 *       --addr 0x02012AE4 --thumb
 */
void func_02012B64(struct BigObj_02012AE4 *p, u8 v)
{
    p->unk1CB = v;
}


/*
 *           func_02012B34, func_02012B38, func_02012B40, func_02012B4C,
 *           func_02012B58, func_02012B64, func_02012B70, func_02012B78,
 *           func_02012B80, func_02012B8C, func_02012B98, func_02012BA4,
 *           func_02012BB0
 *
 * 228 bytes, 0x02012AE4..0x02012BC8, 17 functions, the continuation of
 * src/matched/unit_02012924.c across two near misses.  The same two objects:
 * Rec44 for func_02012AE4 .. func_02012B34 and BigObj from func_02012B38 on.
 *
 * func_02012AE4 buckets the Rec44 field at +0x18 into 0, 1, 2 or 3.  The
 * result local has to be declared **before** the field is read into its own
 * local, or the compiler puts the result in r0, keeps its scratch in r1 and
 * duplicates `bx lr` into every arm instead of branching to one
 * `adds r0, r1, #0; bx lr` tail; that spelling is 28 concrete bytes wrong and
 * two bytes short with identical control flow.  Seven source shapes were
 * compiled and only the two with the result declared first are EXACT.
 *
 * Two near misses bracket this file, and neither is a codegen failure: both
 * reproduce every concrete byte and are held at MATCH by the honesty rule.
 *
 *  - 0x02012AD4, 16 bytes, `p->unk18 = Table[i];` over a u16 table at
 *    0x0209DFA8.  That address appears in exactly one literal pool in the
 *    image, the one inside this function, so the `literal` class discards its
 *    only witness and no cut helps.  It is data, so no label will ever exist
 *    for it.  The source is
 *
 *        void func_02012AD4(struct Rec44 *p, u32 i)
 *        {
 *            p->unk18 = func_02012AD4_Table[i];
 *        }
 *
 *    with `func_02012AD4_Table 0x0209DFA8 data`.  Evidence class: literal, 0
 *    witnesses outside.
 *  - 0x02012BC8, 24 bytes, a tail call through a pool word holding
 *    0x02008451.  0x02008450 is a real Thumb function (the setter whose
 *    getter is the labelled func_02008448 four bytes earlier) but it opens
 *    with no register-saving prologue, so disasm.py never labelled it, and
 *    this pool word is the only reference to it anywhere in the image.  The
 *    source is
 *
 *        void func_02012BC8(struct BigObj *p, u32 v)
 *        {
 *            func_02008450(p->unk198, v != 0);
 *        }
 *
 *    0x02008450 goes into layout/function_starts.txt with a branch that
 *    attests it, which this file cannot provide because it is the only user.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012AE4.c \
 *       --addr 0x02012AE4 --thumb
 */
int func_02012B70(const struct BigObj_02012AE4 *p)
{
    return p->unk1CC;
}


/*
 *           func_02012B34, func_02012B38, func_02012B40, func_02012B4C,
 *           func_02012B58, func_02012B64, func_02012B70, func_02012B78,
 *           func_02012B80, func_02012B8C, func_02012B98, func_02012BA4,
 *           func_02012BB0
 *
 * 228 bytes, 0x02012AE4..0x02012BC8, 17 functions, the continuation of
 * src/matched/unit_02012924.c across two near misses.  The same two objects:
 * Rec44 for func_02012AE4 .. func_02012B34 and BigObj from func_02012B38 on.
 *
 * func_02012AE4 buckets the Rec44 field at +0x18 into 0, 1, 2 or 3.  The
 * result local has to be declared **before** the field is read into its own
 * local, or the compiler puts the result in r0, keeps its scratch in r1 and
 * duplicates `bx lr` into every arm instead of branching to one
 * `adds r0, r1, #0; bx lr` tail; that spelling is 28 concrete bytes wrong and
 * two bytes short with identical control flow.  Seven source shapes were
 * compiled and only the two with the result declared first are EXACT.
 *
 * Two near misses bracket this file, and neither is a codegen failure: both
 * reproduce every concrete byte and are held at MATCH by the honesty rule.
 *
 *  - 0x02012AD4, 16 bytes, `p->unk18 = Table[i];` over a u16 table at
 *    0x0209DFA8.  That address appears in exactly one literal pool in the
 *    image, the one inside this function, so the `literal` class discards its
 *    only witness and no cut helps.  It is data, so no label will ever exist
 *    for it.  The source is
 *
 *        void func_02012AD4(struct Rec44 *p, u32 i)
 *        {
 *            p->unk18 = func_02012AD4_Table[i];
 *        }
 *
 *    with `func_02012AD4_Table 0x0209DFA8 data`.  Evidence class: literal, 0
 *    witnesses outside.
 *  - 0x02012BC8, 24 bytes, a tail call through a pool word holding
 *    0x02008451.  0x02008450 is a real Thumb function (the setter whose
 *    getter is the labelled func_02008448 four bytes earlier) but it opens
 *    with no register-saving prologue, so disasm.py never labelled it, and
 *    this pool word is the only reference to it anywhere in the image.  The
 *    source is
 *
 *        void func_02012BC8(struct BigObj *p, u32 v)
 *        {
 *            func_02008450(p->unk198, v != 0);
 *        }
 *
 *    0x02008450 goes into layout/function_starts.txt with a branch that
 *    attests it, which this file cannot provide because it is the only user.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012AE4.c \
 *       --addr 0x02012AE4 --thumb
 */
struct BigObj_02012AE4 *func_02012B78(struct BigObj_02012AE4 *p, u8 v)
{
    p->unk1CC = v;
    return p;
}


/*
 *           func_02012B34, func_02012B38, func_02012B40, func_02012B4C,
 *           func_02012B58, func_02012B64, func_02012B70, func_02012B78,
 *           func_02012B80, func_02012B8C, func_02012B98, func_02012BA4,
 *           func_02012BB0
 *
 * 228 bytes, 0x02012AE4..0x02012BC8, 17 functions, the continuation of
 * src/matched/unit_02012924.c across two near misses.  The same two objects:
 * Rec44 for func_02012AE4 .. func_02012B34 and BigObj from func_02012B38 on.
 *
 * func_02012AE4 buckets the Rec44 field at +0x18 into 0, 1, 2 or 3.  The
 * result local has to be declared **before** the field is read into its own
 * local, or the compiler puts the result in r0, keeps its scratch in r1 and
 * duplicates `bx lr` into every arm instead of branching to one
 * `adds r0, r1, #0; bx lr` tail; that spelling is 28 concrete bytes wrong and
 * two bytes short with identical control flow.  Seven source shapes were
 * compiled and only the two with the result declared first are EXACT.
 *
 * Two near misses bracket this file, and neither is a codegen failure: both
 * reproduce every concrete byte and are held at MATCH by the honesty rule.
 *
 *  - 0x02012AD4, 16 bytes, `p->unk18 = Table[i];` over a u16 table at
 *    0x0209DFA8.  That address appears in exactly one literal pool in the
 *    image, the one inside this function, so the `literal` class discards its
 *    only witness and no cut helps.  It is data, so no label will ever exist
 *    for it.  The source is
 *
 *        void func_02012AD4(struct Rec44 *p, u32 i)
 *        {
 *            p->unk18 = func_02012AD4_Table[i];
 *        }
 *
 *    with `func_02012AD4_Table 0x0209DFA8 data`.  Evidence class: literal, 0
 *    witnesses outside.
 *  - 0x02012BC8, 24 bytes, a tail call through a pool word holding
 *    0x02008451.  0x02008450 is a real Thumb function (the setter whose
 *    getter is the labelled func_02008448 four bytes earlier) but it opens
 *    with no register-saving prologue, so disasm.py never labelled it, and
 *    this pool word is the only reference to it anywhere in the image.  The
 *    source is
 *
 *        void func_02012BC8(struct BigObj *p, u32 v)
 *        {
 *            func_02008450(p->unk198, v != 0);
 *        }
 *
 *    0x02008450 goes into layout/function_starts.txt with a branch that
 *    attests it, which this file cannot provide because it is the only user.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012AE4.c \
 *       --addr 0x02012AE4 --thumb
 */
u8 func_02012B80(const struct BigObj_02012AE4 *p)
{
    return p->unk1CD;
}


/*
 *           func_02012B34, func_02012B38, func_02012B40, func_02012B4C,
 *           func_02012B58, func_02012B64, func_02012B70, func_02012B78,
 *           func_02012B80, func_02012B8C, func_02012B98, func_02012BA4,
 *           func_02012BB0
 *
 * 228 bytes, 0x02012AE4..0x02012BC8, 17 functions, the continuation of
 * src/matched/unit_02012924.c across two near misses.  The same two objects:
 * Rec44 for func_02012AE4 .. func_02012B34 and BigObj from func_02012B38 on.
 *
 * func_02012AE4 buckets the Rec44 field at +0x18 into 0, 1, 2 or 3.  The
 * result local has to be declared **before** the field is read into its own
 * local, or the compiler puts the result in r0, keeps its scratch in r1 and
 * duplicates `bx lr` into every arm instead of branching to one
 * `adds r0, r1, #0; bx lr` tail; that spelling is 28 concrete bytes wrong and
 * two bytes short with identical control flow.  Seven source shapes were
 * compiled and only the two with the result declared first are EXACT.
 *
 * Two near misses bracket this file, and neither is a codegen failure: both
 * reproduce every concrete byte and are held at MATCH by the honesty rule.
 *
 *  - 0x02012AD4, 16 bytes, `p->unk18 = Table[i];` over a u16 table at
 *    0x0209DFA8.  That address appears in exactly one literal pool in the
 *    image, the one inside this function, so the `literal` class discards its
 *    only witness and no cut helps.  It is data, so no label will ever exist
 *    for it.  The source is
 *
 *        void func_02012AD4(struct Rec44 *p, u32 i)
 *        {
 *            p->unk18 = func_02012AD4_Table[i];
 *        }
 *
 *    with `func_02012AD4_Table 0x0209DFA8 data`.  Evidence class: literal, 0
 *    witnesses outside.
 *  - 0x02012BC8, 24 bytes, a tail call through a pool word holding
 *    0x02008451.  0x02008450 is a real Thumb function (the setter whose
 *    getter is the labelled func_02008448 four bytes earlier) but it opens
 *    with no register-saving prologue, so disasm.py never labelled it, and
 *    this pool word is the only reference to it anywhere in the image.  The
 *    source is
 *
 *        void func_02012BC8(struct BigObj *p, u32 v)
 *        {
 *            func_02008450(p->unk198, v != 0);
 *        }
 *
 *    0x02008450 goes into layout/function_starts.txt with a branch that
 *    attests it, which this file cannot provide because it is the only user.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012AE4.c \
 *       --addr 0x02012AE4 --thumb
 */
void func_02012B8C(struct BigObj_02012AE4 *p, u32 v)
{
    p->unk1CD = v;
}


/*
 *           func_02012B34, func_02012B38, func_02012B40, func_02012B4C,
 *           func_02012B58, func_02012B64, func_02012B70, func_02012B78,
 *           func_02012B80, func_02012B8C, func_02012B98, func_02012BA4,
 *           func_02012BB0
 *
 * 228 bytes, 0x02012AE4..0x02012BC8, 17 functions, the continuation of
 * src/matched/unit_02012924.c across two near misses.  The same two objects:
 * Rec44 for func_02012AE4 .. func_02012B34 and BigObj from func_02012B38 on.
 *
 * func_02012AE4 buckets the Rec44 field at +0x18 into 0, 1, 2 or 3.  The
 * result local has to be declared **before** the field is read into its own
 * local, or the compiler puts the result in r0, keeps its scratch in r1 and
 * duplicates `bx lr` into every arm instead of branching to one
 * `adds r0, r1, #0; bx lr` tail; that spelling is 28 concrete bytes wrong and
 * two bytes short with identical control flow.  Seven source shapes were
 * compiled and only the two with the result declared first are EXACT.
 *
 * Two near misses bracket this file, and neither is a codegen failure: both
 * reproduce every concrete byte and are held at MATCH by the honesty rule.
 *
 *  - 0x02012AD4, 16 bytes, `p->unk18 = Table[i];` over a u16 table at
 *    0x0209DFA8.  That address appears in exactly one literal pool in the
 *    image, the one inside this function, so the `literal` class discards its
 *    only witness and no cut helps.  It is data, so no label will ever exist
 *    for it.  The source is
 *
 *        void func_02012AD4(struct Rec44 *p, u32 i)
 *        {
 *            p->unk18 = func_02012AD4_Table[i];
 *        }
 *
 *    with `func_02012AD4_Table 0x0209DFA8 data`.  Evidence class: literal, 0
 *    witnesses outside.
 *  - 0x02012BC8, 24 bytes, a tail call through a pool word holding
 *    0x02008451.  0x02008450 is a real Thumb function (the setter whose
 *    getter is the labelled func_02008448 four bytes earlier) but it opens
 *    with no register-saving prologue, so disasm.py never labelled it, and
 *    this pool word is the only reference to it anywhere in the image.  The
 *    source is
 *
 *        void func_02012BC8(struct BigObj *p, u32 v)
 *        {
 *            func_02008450(p->unk198, v != 0);
 *        }
 *
 *    0x02008450 goes into layout/function_starts.txt with a branch that
 *    attests it, which this file cannot provide because it is the only user.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012AE4.c \
 *       --addr 0x02012AE4 --thumb
 */
u8 func_02012B98(const struct BigObj_02012AE4 *p, u32 i)
{
    return p->unk1D0[i];
}


/*
 *           func_02012B34, func_02012B38, func_02012B40, func_02012B4C,
 *           func_02012B58, func_02012B64, func_02012B70, func_02012B78,
 *           func_02012B80, func_02012B8C, func_02012B98, func_02012BA4,
 *           func_02012BB0
 *
 * 228 bytes, 0x02012AE4..0x02012BC8, 17 functions, the continuation of
 * src/matched/unit_02012924.c across two near misses.  The same two objects:
 * Rec44 for func_02012AE4 .. func_02012B34 and BigObj from func_02012B38 on.
 *
 * func_02012AE4 buckets the Rec44 field at +0x18 into 0, 1, 2 or 3.  The
 * result local has to be declared **before** the field is read into its own
 * local, or the compiler puts the result in r0, keeps its scratch in r1 and
 * duplicates `bx lr` into every arm instead of branching to one
 * `adds r0, r1, #0; bx lr` tail; that spelling is 28 concrete bytes wrong and
 * two bytes short with identical control flow.  Seven source shapes were
 * compiled and only the two with the result declared first are EXACT.
 *
 * Two near misses bracket this file, and neither is a codegen failure: both
 * reproduce every concrete byte and are held at MATCH by the honesty rule.
 *
 *  - 0x02012AD4, 16 bytes, `p->unk18 = Table[i];` over a u16 table at
 *    0x0209DFA8.  That address appears in exactly one literal pool in the
 *    image, the one inside this function, so the `literal` class discards its
 *    only witness and no cut helps.  It is data, so no label will ever exist
 *    for it.  The source is
 *
 *        void func_02012AD4(struct Rec44 *p, u32 i)
 *        {
 *            p->unk18 = func_02012AD4_Table[i];
 *        }
 *
 *    with `func_02012AD4_Table 0x0209DFA8 data`.  Evidence class: literal, 0
 *    witnesses outside.
 *  - 0x02012BC8, 24 bytes, a tail call through a pool word holding
 *    0x02008451.  0x02008450 is a real Thumb function (the setter whose
 *    getter is the labelled func_02008448 four bytes earlier) but it opens
 *    with no register-saving prologue, so disasm.py never labelled it, and
 *    this pool word is the only reference to it anywhere in the image.  The
 *    source is
 *
 *        void func_02012BC8(struct BigObj *p, u32 v)
 *        {
 *            func_02008450(p->unk198, v != 0);
 *        }
 *
 *    0x02008450 goes into layout/function_starts.txt with a branch that
 *    attests it, which this file cannot provide because it is the only user.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012AE4.c \
 *       --addr 0x02012AE4 --thumb
 */
void func_02012BA4(struct BigObj_02012AE4 *p, int i, u8 v)
{
    p->unk1D0[i] = v;
}


/*
 *           func_02012B34, func_02012B38, func_02012B40, func_02012B4C,
 *           func_02012B58, func_02012B64, func_02012B70, func_02012B78,
 *           func_02012B80, func_02012B8C, func_02012B98, func_02012BA4,
 *           func_02012BB0
 *
 * 228 bytes, 0x02012AE4..0x02012BC8, 17 functions, the continuation of
 * src/matched/unit_02012924.c across two near misses.  The same two objects:
 * Rec44 for func_02012AE4 .. func_02012B34 and BigObj from func_02012B38 on.
 *
 * func_02012AE4 buckets the Rec44 field at +0x18 into 0, 1, 2 or 3.  The
 * result local has to be declared **before** the field is read into its own
 * local, or the compiler puts the result in r0, keeps its scratch in r1 and
 * duplicates `bx lr` into every arm instead of branching to one
 * `adds r0, r1, #0; bx lr` tail; that spelling is 28 concrete bytes wrong and
 * two bytes short with identical control flow.  Seven source shapes were
 * compiled and only the two with the result declared first are EXACT.
 *
 * Two near misses bracket this file, and neither is a codegen failure: both
 * reproduce every concrete byte and are held at MATCH by the honesty rule.
 *
 *  - 0x02012AD4, 16 bytes, `p->unk18 = Table[i];` over a u16 table at
 *    0x0209DFA8.  That address appears in exactly one literal pool in the
 *    image, the one inside this function, so the `literal` class discards its
 *    only witness and no cut helps.  It is data, so no label will ever exist
 *    for it.  The source is
 *
 *        void func_02012AD4(struct Rec44 *p, u32 i)
 *        {
 *            p->unk18 = func_02012AD4_Table[i];
 *        }
 *
 *    with `func_02012AD4_Table 0x0209DFA8 data`.  Evidence class: literal, 0
 *    witnesses outside.
 *  - 0x02012BC8, 24 bytes, a tail call through a pool word holding
 *    0x02008451.  0x02008450 is a real Thumb function (the setter whose
 *    getter is the labelled func_02008448 four bytes earlier) but it opens
 *    with no register-saving prologue, so disasm.py never labelled it, and
 *    this pool word is the only reference to it anywhere in the image.  The
 *    source is
 *
 *        void func_02012BC8(struct BigObj *p, u32 v)
 *        {
 *            func_02008450(p->unk198, v != 0);
 *        }
 *
 *    0x02008450 goes into layout/function_starts.txt with a branch that
 *    attests it, which this file cannot provide because it is the only user.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012AE4.c \
 *       --addr 0x02012AE4 --thumb
 */
u32 func_02012BB0(const struct BigObj_02012AE4 *p)
{
    if (func_02008448((int)p->unk198) == 1) {
        return 1;
    }
    return 0;
}


/*
 * Forward a boolean-normalised flag to func_02008450 on the object held at
 * +0x198 of the game-data object (func_0200873C(handle) in func_020124F4).
 *
 * The tail call's pool word names 0x02008450, an unlabelled Thumb leaf
 * (the bit-10 setter beside the labelled getter func_02008448); this
 * pool word is its only reference in the image.  It is attested by the
 * compiled witness src/matched/func_02008450.c (class `matched`).
 */
void func_02012BC8(u8 *p, int on)
{
    func_02008450((struct Flags02008450 *)((struct Obj15630 *)p)->f198, on ? 1 : 0);
}


/*
 * One function, 24 bytes, because the function immediately after it is a near
 * miss and the one after that is src/matched/unit_02012C0C.c.
 *
 * 0x02012BF8, 20 bytes, is the twin of this one and reproduces every concrete
 * byte:
 *
 *     void func_02012BF8(void *p, u32 a)
 *     {
 *         func_0200C44C(func_0200C404(func_02012EC0(p)), a);
 *     }
 *
 * with `func_0200C404 0x0200C404 thumb`, `func_0200C44C 0x0200C44C thumb` and
 * `func_02012EC0 0x02012EC0 thumb`.  It caps at MATCH because the `bl` at
 * 0x02012C06 is the only branch to func_0200C44C anywhere in the image, so the
 * `label` class has no witness outside the range and, this being the only
 * caller, no cut can create one.  Evidence class: label, 0 witnesses outside.
 * The other five call targets here all have witnesses elsewhere.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012BE0.c \
 *       --addr 0x02012BE0 --thumb
 */
void func_02012BE0(void *p, u32 a, u32 b)
{
    func_0200C418(func_0200C40C(func_02012EBC(p)), a, b);
}


int func_02012BF8(int a0, int a1){ int t0, t1, t2; t0 = func_02012EC0(a0); t1 = func_0200C404((int)t0); t2 = func_0200C44C((int)t1, (int)((a1 + 0) + 0)); return t2; }


/*
 * Twelve bytes: the address of the BigObj sub-object at +0x5E8, reached
 * through a literal pool word holding the plain constant 0x5E8 rather than a
 * relocation.  It is a file of its own because the function in front of it,
 * 0x02012BF8, is a documented near miss; see the header of
 * src/matched/unit_02012BE0.c.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012C0C.c \
 *       --addr 0x02012C0C --thumb
 */
u8 *func_02012C0C(struct BigObj_02012C0C *p)
{
    return p->unk5E8;
}


/*
 * 204 bytes, 0x02012C18..0x02012CDC (the listing extent 204 includes the
 * 0x5EC pool word at 0x02012CDC).  Sibling of func_02012CE0, same shape plus
 * an opening guard `if (func_020071E4(*(u32 *)p) == 1) return;`.
 *
 * docs/notes/pkt_02012C18.c.txt recorded this as an unmovable register
 * rotation (r4/r6/r7) -- it was not.  The rotation was downstream of ONE
 * wrong argument order: the original is
 *     func_020097F0(func_02009D08(*(u32 *)p), v);
 * i.e. the inner call's result is argument 1 and the 0x0201283C result is
 * argument 2, the OPPOSITE of the sibling's func_020097F0(v, func_02009D08())
 * at 0x02012D6E.  With the arguments the sibling's way, mwcc needs an extra
 * `adds r0, r7, #0` at the call, which shifts everything after it by two
 * bytes, forces the trailing `c046` pool-alignment nop, and reallocates the
 * three callee-saved registers -- which is what the note saw and read as the
 * whole residue.  Swapping them alone takes the file from that DIFF to EXACT
 * with no other change.  (docs/idioms/cmp-operand-order-names-the-temporary.md
 * generalised: the call-result operand order names which value gets the
 * named-local treatment.)
 */
void func_02012C18(u8 *p)
{
    u32 v;
    u32 h;

    if (func_020071E4((const struct Sub020071E4Ctrl *)(*(u32 *)&((struct Obj00054 *)p)->f0)) == 1) {
        return;
    }

    v = (u32)func_020127A4((struct SaveBlock *)p);
    func_02008808((void *)(*(u32 *)&((struct Obj00054 *)p)->f0), (struct Sub020087E8Arg *)v);
    func_020088B8((void *)(*(u32 *)&((struct Obj00054 *)p)->f0), (struct Sub02008860Buf *)v);

    v = func_02012964((const struct BigObj *)p);
    func_0200EEAC((void *)v, (void *)((u32)func_020071CC((struct Sub020071CCCtrl *)*(u32 *)&((struct Obj00054 *)p)->f0, 0x29)));

    func_0200BE6C((void *)(*(u32 *)&((struct Obj00054 *)p)->f0), (u16 *)func_020127B8(p));

    v = (u32)func_020127C4(p);
    func_0200A884(func_0200A864((void *)(*(u32 *)&((struct Obj00054 *)p)->f0)), (struct Rec2Head *)v);

    func_0200B3C8((void *)(*(u32 *)&((struct Obj00054 *)p)->f0), (const struct Rec94 *)(p + 0x5EC));

    h = ((struct Obj00054 *)p)->f15C;
    func_0200893C((const struct Sub02008828Obj *)h, (void *)(*(u32 *)&((struct Obj00054 *)p)->f1B8));
    func_02008954((const struct Sub02008828Obj *)h, p + 0x1C4);

    v = func_0201283C((const struct BigObj_0201283C *)p);
    func_020097F0(func_02009D08((void *)(*(u32 *)&((struct Obj00054 *)p)->f0)), (struct Sub020097BCObj *)v);

    func_02008964((const struct Sub02008828Obj *)(((struct Obj00054 *)p)->f15C), p + 0x1C5);

    func_0200E89C((void *)(*(u32 *)&((struct Obj00054 *)p)->f0), p + 0x694);

    v = (u32)func_02008748((void *)(*(u32 *)&((struct Obj00054 *)p)->f0));
    func_0200863C((struct PlayTime *)(((struct Obj00054 *)p)->f6AC), (const struct PlayTime *)v);
}


/*
 * 204 bytes, 0x02012CE0..0x02012DAC, EXACT on the first run after the one
 * change that mattered: the u32 at p+0x15C is read once into a NAMED local and
 * handed to both 0x0200892C and 0x0200894C.  Spelled inline at each call site
 * the compiler re-materialises the address per site (`adds r1, r6, #0;
 * adds r1, #0x5c; ldr r0, [r5, r6]`) and loses four bytes; with the local it
 * keeps the value live in r7 across the two calls, exactly as the original
 * does.  The third use (0x0200895C, after two more calls) re-reads it, which
 * is also what the original does.
 *
 * p is a byte pointer: the offsets 0x15C / 0x1B8 / 0x1C4 / 0x1C5 / 0x5EC /
 * 0x694 / 0x6AC are plain byte displacements, and mwcc materialises 0x5EC as
 * a pool word (it is not a single-instruction ARM immediate).
 */
void func_02012CE0(u8 *p)
{
    u32 v;
    u32 h;

    v = (u32)func_020127A4((struct SaveBlock *)p);
    func_020087E8((void *)(*(u32 *)&((struct Obj00054 *)p)->f0), (const struct Sub020087E8Arg *)v);
    func_02008860((void *)(*(u32 *)&((struct Obj00054 *)p)->f0), (const struct Sub02008860Buf *)v);

    v = func_02012964((const struct BigObj *)p);
    func_0200EE64(v, (u8 *)((u32)func_020071CC((struct Sub020071CCCtrl *)*(u32 *)&((struct Obj00054 *)p)->f0, 0x29)));

    func_0200BE54((void *)(*(u32 *)&((struct Obj00054 *)p)->f0), (const u16 *)func_020127B8(p));

    v = (u32)func_020127C4(p);
    func_0200A870(func_0200A864((void *)(*(u32 *)&((struct Obj00054 *)p)->f0)), (const struct Rec2Head *)v);

    func_0200B3B0((struct Rec94 *)(p + 0x5EC), (void *)(*(u32 *)&((struct Obj00054 *)p)->f0));

    h = ((struct Obj00054 *)p)->f15C;
    func_0200892C((struct Sub02008828Obj *)h, (const void *)(*(u32 *)&((struct Obj00054 *)p)->f1B8));
    func_0200894C((struct Sub02008828Obj *)h, ((struct Obj00054 *)p)->f1C4);

    v = func_0201283C((const struct BigObj_0201283C *)p);
    func_020097F0((const struct Sub020097BCObj *)v, func_02009D08((void *)(*(u32 *)&((struct Obj00054 *)p)->f0)));

    func_0200895C((struct Sub02008828Obj *)(((struct Obj00054 *)p)->f15C), ((struct Obj00054 *)p)->f1C5);

    func_0200E884(p + 0x694, (void *)(*(u32 *)&((struct Obj00054 *)p)->f0));

    v = (u32)func_02008748((void *)(*(u32 *)&((struct Obj00054 *)p)->f0));
    func_02008658((struct PlayTime *)(((struct Obj00054 *)p)->f6AC));
    func_0200863C((struct PlayTime *)v, (const struct PlayTime *)(((struct Obj00054 *)p)->f6AC));
}


int func_02012DAC(u8 *p)
{
    func_02012CE0(p);
    func_0201042C();
    ((struct Obj00054 *)p)->f1CE = 1;
    func_0203516C(2, 1);
    return func_02007150(((struct Obj00054 *)p)->f0);
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02012DD0.c \
 *       --func func_02012DD0 --addr 0x02012DD0 --cc 1.1p1 --thumb
 */
int func_02012DD0(u8 *p)
{
    int r;

    if (func_02005C64() == 1) {
        return 0;
    }
    r = func_02007168((struct Sub02007168 *)(((struct Obj11252 *)p)->f0));
    if ((u32)(r - 2) <= 1) {
        func_020351A0(2);
        func_02010444();
        ((struct Obj11252 *)p)->f1CE = 0;
    }
    return r;
}


void func_02012E08(char *p)
{
    u32 x;

    if (((struct Obj08745 *)p)->f1CE != 1)
        return;
    func_020351A0(2);
    func_02010444();
    ((struct Obj08745 *)p)->f1CE = 0;
    func_020071A8(((struct Obj08745 *)p)->f0);
    x = 0x80;
    if (func_02034FE8(x) == 1)
        func_02034FB8(x);
}


/*
 * A one-byte getter for the field at +0x1CE, entry attested by the pool word
 * 0x02012E41 that the sibling setter pair loads.  0x1CE does not fit a Thumb
 * immediate, so the offset comes from the function's own literal pool while
 * the pointer stays in r0.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02012E40.c \
 *       --func sub_02012E40 --addr 0x02012E40 --cc 1.1p1 --thumb
 */
u8 sub_02012E40(const u8 *o)
{
    return *(const u8 *)&((struct Obj16727 *)o)->f1CE;
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02012E4C.c \
 *       --func func_02012E4C --addr 0x02012E4C --cc 1.1p1 --thumb
 */
void func_02012E4C(u8 *p, u32 id)
{
    func_02034F84(0x80);
    func_02012CE0(p);
    func_0201042C();
    ((struct Obj00054 *)p)->f1CE = 1;
    func_0203516C(2);
    func_02007374((char *)*(u32 *)&((struct Obj00054 *)p)->f0, id);
}


int func_02012E7C(char *p, int a1)
{
    int r;

    if (func_02005C64() == 1)
        return 0;
    r = func_020073B0((char *)(*(u32 *)&((struct Obj00054 *)p)->f0), a1);
    if (r == 2 || r == 3) {
        func_020351A0(2);
        func_02010444();
        ((struct Obj00054 *)p)->f1CE = 0;
        func_02034FB8(0x80);
    }
    return r;
}


/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02012ED8
 *
 * Five leaf accessors on one large record.  Offsets 0x5ec and 0x688 are out
 * of Thumb immediate reach so each costs a pool word, while 0x680 is
 * 0x1a << 6 and is rematerialised with `movs`/`lsls` instead.  Two of the
 * five read the same word at +0, which the compiler keeps as two separate
 * sections rather than folding.  None saves lr, so none is labelled.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012EBC.c \
 *       --addr 0x02012EBC --thumb
 */
void *sub_02012EBC(struct Big *p)
{
    return p->unk_00;
}


/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02012ED8
 *
 * Five leaf accessors on one large record.  Offsets 0x5ec and 0x688 are out
 * of Thumb immediate reach so each costs a pool word, while 0x680 is
 * 0x1a << 6 and is rematerialised with `movs`/`lsls` instead.  Two of the
 * five read the same word at +0, which the compiler keeps as two separate
 * sections rather than folding.  None saves lr, so none is labelled.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012EBC.c \
 *       --addr 0x02012EBC --thumb
 */
void *sub_02012EC0(struct Big *p)
{
    return p->unk_00;
}


/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02012ED8
 *
 * Five leaf accessors on one large record.  Offsets 0x5ec and 0x688 are out
 * of Thumb immediate reach so each costs a pool word, while 0x680 is
 * 0x1a << 6 and is rematerialised with `movs`/`lsls` instead.  Two of the
 * five read the same word at +0, which the compiler keeps as two separate
 * sections rather than folding.  None saves lr, so none is labelled.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012EBC.c \
 *       --addr 0x02012EBC --thumb
 */
u8 *sub_02012EC4(struct Big *p)
{
    return &p->unk_5ec;
}


/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02012ED8
 *
 * Five leaf accessors on one large record.  Offsets 0x5ec and 0x688 are out
 * of Thumb immediate reach so each costs a pool word, while 0x680 is
 * 0x1a << 6 and is rematerialised with `movs`/`lsls` instead.  Two of the
 * five read the same word at +0, which the compiler keeps as two separate
 * sections rather than folding.  None saves lr, so none is labelled.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012EBC.c \
 *       --addr 0x02012EBC --thumb
 */
u8 *sub_02012ED0(struct Big *p)
{
    return &p->unk_680;
}


/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02012ED8
 *
 * Five leaf accessors on one large record.  Offsets 0x5ec and 0x688 are out
 * of Thumb immediate reach so each costs a pool word, while 0x680 is
 * 0x1a << 6 and is rematerialised with `movs`/`lsls` instead.  Two of the
 * five read the same word at +0, which the compiler keeps as two separate
 * sections rather than folding.  None saves lr, so none is labelled.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012EBC.c \
 *       --addr 0x02012EBC --thumb
 */
void *sub_02012ED8(struct Big *p)
{
    return p->unk_688;
}


/*
 * Unlabelled leaf accessor: stores v at base + 0x688.
 */
char *func_02012EE4(char *base, int v)
{
    ((struct Obj15631 *)base)->f688 = v;
    return base;
}


/*
 * Unlabelled Thumb tail-call thunk: sub_020071CC(*p, 0x3a).
 */
void *func_02012EF0(void **p)
{
    return sub_020071CC(*p, 0x3a);
}


/*
 * Unlabelled Thumb tail-call thunk: sub_020071CC(*p, 0x3b).
 */
void *func_02012EFC(void **p)
{
    return sub_020071CC(*p, 0x3b);
}


void *func_02012F08(int *p)
{
    return func_0200C0F0((void *)(*p));
}


/*
 * Save-block getter through the handle's first word: tail call to
 * func_02009EC8 (block 0x1f).  Seeded from ov119 0x021E0226, 0x021E06D0,
 * 0x021E080C (tree_ov170_3).
 *
 * Addresses are Black-image addresses.
 */
void *func_02012F14(void **h)
{
    return func_02009EC8(*h);
}


int func_02012F20(int p0){ return *(int *)((p0 + (0x684 << 0))); }


void *func_02012F2C(int *p)
{
    return func_020071CC((struct Sub020071CCCtrl *)*p, 0x26);
}


/*
 * Unlabelled leaf accessor: base + 0x694.
 */
int func_02012F38(int base)
{
    return base + 0x694;
}


/*
 * Unlabelled leaf: tail-calls func_020071CC(*(void **)p, 0x2a).
 */
void *func_02012F44(void *p)
{
    return func_020071CC(((struct Obj00054 *)p)->f0, 0x2a);
}


/*
 * Unlabelled leaf accessor: base + 0x6A4.  No register-saving prologue, so
 * disasm.py never traced a func_ label here; matching it gives the overlay
 * call sites a `matched` witness.
 */
void *func_02012F50(void *base)
{
    return (char *)base + 0x6A4;
}


/*
 * Save-block getter through the handle's first word: tail call to
 * sub_020089C0 (block 0x21, src/matched/unit_020089A8.c).  Seeded from ov111
 * 0x021C40FC, 0x021C4126, 0x021C6208 and ov010 0x0215AC8E.
 *
 * Addresses are Black-image addresses.
 */
void *func_02012F5C(void **h)
{
    return func_020089C0(*h);
}


/*
 * Two leaves before func_02012F80 (the +0x6a8 getter): save-block getter
 * for block 0x42 through the handle's first word, and the +0x6a8 setter.
 * Seeded from ov048/ov171/ov205 (0x02012F68) and ov010 func_0215DDC8 and
 * func_0215DE0C (0x02012F74).
 */
void *func_02012F68(void **h)
{
    return func_020071CC(*h, 0x42);
}


/*
 * Two leaves before func_02012F80 (the +0x6a8 getter): save-block getter
 * for block 0x42 through the handle's first word, and the +0x6a8 setter.
 * Seeded from ov048/ov171/ov205 (0x02012F68) and ov010 func_0215DDC8 and
 * func_0215DE0C (0x02012F74).
 */
void func_02012F74(void *h, void *w)
{
    ((struct Obj17167 *)h)->f6A8 = w;
}


/*
 * Unlabelled leaf accessor: reads the word at base + 0x6A8.  No
 * register-saving prologue, so disasm.py never traced a func_ label here;
 * matching it gives the overlay call sites a `matched` witness.
 */
int func_02012F80(char *base)
{
    return ((struct Obj15637 *)base)->f6A8;
}


/*
 * Unlabelled leaf: tail-calls func_02009448(*p).  Filed as the witness for
 * ov021 func_021D1670, func_021D16D8 and func_021D179C.
 */
u32 func_02012F8C(u32 *p)
{
    return (u32)func_02009448((void *)(*p));
}


/*
 * Unlabelled leaf: tail-calls func_02007B44(*(void **)p).
 */
struct Sub02007AC8Entry *func_02012F98(void *p)
{
    return func_02007B44(((struct Obj00054 *)p)->f0);
}


/*
 * Unlabelled Thumb leaf: stores a byte at +0x1CF.
 */
void func_02012FA4(char *p, unsigned char v)
{
    *(char *)(p + 0x1cf) = v;
}


/*
 * Unlabelled leaf accessor: reads the byte at base + 0x1CF.
 */
int func_02012FB0(unsigned char *base)
{
    return ((struct Obj15639 *)base)->f1CF;
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02012FBC.c \
 *       --func func_02012FBC --addr 0x02012FBC --cc 1.1p1 --thumb
 */
u32 func_02012FBC(u8 *p, u32 x)
{
    return func_020085D4(((struct Obj15640 *)p)->f6AC, x);
}


int func_02012FCC(int p0){ return *(int *)((p0 + (0x6AC << 0))); }


void *func_02012FD8(void **p)
{
    return func_020071CC(*p, 0x43);
}


void *func_02012FE4(struct Sub020071CCCtrl *a0)
{
    return func_020071CC(a0, 0x2d);
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * Battle setup global pointer setter and clamped index lookup into data_0209DFB0.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012FF0.c \
 *       --addr 0x02012FF0 --thumb
 */
void sub_02012FF0(void *val)
{
    ptr_020A7298 = val;
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * Battle setup global pointer setter and clamped index lookup into data_0209DFB0.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012FF0.c \
 *       --addr 0x02012FF0 --thumb
 */
signed char sub_02012FFC(void)
{
    u32 val = sub_02008374((int)sub_0200873C(ptr_020A7298));
    if (val >= 5) {
        val = 4;
    }
    return data_0209DFB0[val];
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * Mode mapping helpers calling clamped lookup sub_02013080.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02013020.c \
 *       --addr 0x02013020 --thumb
 */
signed char sub_02013020(void)
{
    u32 val = sub_02008374((int)sub_0200873C(ptr_020A7298));
    switch (val) {
    case 0:
        val = 1;
        break;
    case 1:
        val = 2;
        break;
    case 2:
        val = 3;
        break;
    }
    return sub_02013080(val);
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * Mode mapping helpers calling clamped lookup sub_02013080.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02013020.c \
 *       --addr 0x02013020 --thumb
 */
signed char sub_02013050(void)
{
    u32 val = sub_02008374((int)sub_0200873C(ptr_020A7298));
    switch (val) {
    case 0:
        val = 4;
        break;
    case 1:
        val = 0;
        break;
    case 2:
        val = 1;
        break;
    }
    return sub_02013080(val);
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * Mode mapping helpers calling clamped lookup sub_02013080.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02013020.c \
 *       --addr 0x02013020 --thumb
 */
signed char sub_02013080(u32 idx)
{
    if (idx >= 5) {
        idx = 4;
    }
    return data_0209DFB0[idx];
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02013090.c \
 *       --func func_02013090 --addr 0x02013090 --cc 1.1p1 --thumb
 */
void *func_02013090(u32 heap)
{
    void *p;

    p = func_02030734(heap, 0xf0, 0, (const char *)&sZonedataFile, 0x31);
    func_020130C4(p);
    return p;
}


int func_020130B4(int a0){ int t0 = func_020130DC(a0); int t1 = func_020307B0((int)((a0 + 0) + 0)); return t1; }


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020130C4.c \
 *       --func func_020130C4 --addr 0x020130C4 --cc 1.1p1 --thumb
 */
void func_020130C4(u8 *p)
{
    func_02082BCC(p, 0, 0xf0);
    func_02013220((char *)(p + 8));
}


/*
 * verdict is EXACT* : all 74 code bytes reproduce (5 of 5 relocation sites
 * resolved), the inferred extent only ran long by the follower at 0x02013128
 * (28 bytes, a tail-call wrapper into 0x0201AC2C|1) which has no label
 * because it saves nothing -- report it for layout/function_starts.txt
 * rather than editing that file here.
 */
void sub_020130DC(S *p)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (p->a24[i] != 0)
            sub_020307B0(p->a24[i]);
        if (p->a48[i] != 0)
            sub_02013270((int)p->a48[i]);
        if (i != 0 && p->a34[i] != 0)
            sub_020307B0(p->a34[i]);
    }
    if (p->a94 != 0)
        sub_020307B0(p->a94);
    sub_02082BCC(p, 0, 0xf0);
}


/*
 * Unlabelled Thumb thunk in the ARM9 module (zonedata.c). Tail-calls
 * func_0201AC2C (the 0x534-byte container copy in unit_0201AC2C.c,
 * prototype (src, dst)) with the second argument as source and the i-th
 * pointer of the table at +0x24 as destination.
 *
 * Addresses are Black-image addresses.
 */
void func_02013128(void *p, void *src, int i)
{
    func_0201AC2C(src, ((void **)((char *)p + 0x24))[i]);
}


/*
 * Unlabelled Thumb leaf: the i-th pointer of the table at +0x24.
 */
void *func_0201313C(void *p, int i)
{
    return ((void **)((char *)p + 0x24))[i];
}


void func_02013144(char *p, int v)
{
    ((struct Obj15642 *)p)->f82 |= (unsigned short)v;
}


/*
 * Unlabelled leaf accessor: returns m & *(u16 *)(base + 0x82).
 */
int func_02013158(char *base, int m)
{
    return ((struct Obj15643 *)base)->f82 & m;
}


/*
 * btl_setup.c.  The per-battle settings copier: two timer fields in seconds,
 * a name block, a three-way flag decision, and a pass over the four +0x24
 * slots binding each to the caller's third argument.
 *
 * This closes the near miss in docs/notes/pkt_02013160.c.txt, which compiled
 * 162 bytes against 172 with 77 concrete bytes out.  Three findings, in
 * descending order of how much each was worth.
 *
 * (1) THE SWITCH NEEDS AN EXPLICIT EMPTY `case 0:`.  This is the whole
 * function.  The image dispatches through a PC-relative halfword table of
 * four entries with a `cmp r0, #3 / bhi` range check, and that table only
 * exists if the case labels are dense from zero; with cases 1, 2 and 3 only,
 * the compiler emits a compare chain instead and the function comes out 12
 * bytes short.  Adding `case 0: break;` took the residue from 80 concrete
 * bytes out to ONE and the permuter's instruction score from 820 to 110, with
 * the size going from 160 to the correct 170.  See
 * docs/idioms/empty-switch-arms-are-what-make-the-table.md and
 * docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md.
 *
 * (2) THE LOOP COUNTER IS SIGNED.  The last byte was `blt` against `blo`:
 * `int i` rather than `u32 i` for the four-slot loop.  Nothing else in the
 * function distinguishes them.
 *
 * (3) 0x10 and 0x3C are named locals, not literals.  `movs r5, #0x10` is
 * hoisted to the prologue, before the first func_0200AE54 call, and r5 is
 * then shifted left by 6 and by 7 to build the two flag masks; `movs r7,
 * #0x3c` is materialised once and reused as the multiplier for both timer
 * fields.  Spelling the masks as the constants 0x400 and 0x800, or the
 * multiplier as a literal 0x3c at each site, rematerialises them per use.
 * The multiplication is written `sec * f(...)` and not `f(...) * sec`: the
 * accumulator of a commutative chain is its second operand, so the operand
 * order here is what puts the call result in r1 and the constant in r7.
 *
 * The three switch arms tail-merge: case 3 falls into case 1's body rather
 * than duplicating the store, which is why the `b` at the end of case 2
 * targets the middle of case 1's block.  Writing the two ORs of case 3 as
 * two separate statements in source order is what produces that, not a
 * combined `|= (bit << 6) | (bit << 7)`.
 *
 * EXACT*: all 170 code bytes reproduce (4 of 4 relocation sites resolved);
 * the inferred extent ran two bytes long only on the `movs r0, r0` alignment
 * pad at 0x0201320A before func_0201320C.  Never a byte difference.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02013160.c \
 *       --func func_02013160 --addr 0x02013160 --cc 1.1p1 --thumb
 */
void func_02013160(u8 *o, void *a1, u32 a2)
{
    u32 bit = 0x10;
    u32 sec = 0x3c;
    int i;

    ((struct Obj01199 *)o)->f76 = (u16)(sec * func_0200AE54(a1, 0x10));
    ((struct Obj01199 *)o)->f74 = (u16)(sec * func_0200AE54(a1, 0xf));
    func_0200B040(a1, (struct RegAC *)(o + 0x78));
    switch (func_0200AE54(a1, 0x12)) {
    case 0:
        break;
    case 1:
        ((struct Obj01199 *)o)->f82 |= (u16)(bit << 7);
        break;
    case 2:
        ((struct Obj01199 *)o)->f82 |= (u16)(bit << 6);
        break;
    case 3:
        ((struct Obj01199 *)o)->f82 |= (u16)(bit << 6);
        ((struct Obj01199 *)o)->f82 |= (u16)(bit << 7);
        break;
    }
    for (i = 0; i < 4; i++) {
        u8 *e = o + i * 4;
        if (((struct Obj08746 *)e)->f24 != 0) {
            func_0201A30C(a1, (void *)(((struct Obj08746 *)e)->f24), a2);
            func_0201A2A8(a1, (void *)(((struct Obj08746 *)e)->f24));
        }
    }
}


void func_0201320C(int p0){ ((struct Obj04040 *)p0)->f0 = (int)9; ((struct Obj04040 *)p0)->f4 = (int)0; ((struct Obj04040 *)p0)->f8 = (unsigned char)0; ((struct Obj04040 *)p0)->fA = (unsigned short)0; ((struct Obj04040 *)p0)->fC = (unsigned char)0; ((struct Obj04040 *)p0)->fD = (unsigned char)0; ((struct Obj04040 *)p0)->f9 = (unsigned char)0; }


void func_02013220(char *p)
{
    ((struct Obj04041 *)p)->f0 = 0;
    ((struct Obj04041 *)p)->f4 = 0;
    ((struct Obj04041 *)p)->f9 = 0;
    ((struct Obj04041 *)p)->f8 = 0;
    ((struct Obj04041 *)p)->fA = 0;
    ((struct Obj04041 *)p)->fC = 0xa;
    ((struct Obj04041 *)p)->fD = 0;
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02013234.c \
 *       --func func_02013234 --addr 0x02013234 --cc 1.1p1 --thumb
 */
void *func_02013234(u32 heap)
{
    struct Obj *p;

    p = func_02030734(heap, 0x28, 1, (const char *)&sZonedataFile, 0xef);
    p->unk14 = func_020457B0(0x10, heap);
    p->unk00 = 0;
    func_0202428C(&p->pad18[0]);
    func_0202428C(&p->pad18[8]);
    return p;
}


int func_02013270(int a0){ int t0 = func_02045808((int)((struct Obj15644 *)((char *)((a0 + 0))))->f14); int t1 = func_020307B0((int)((a0 + 0) + 0)); return t1; }


/*
 * btl_setup.c.  The sub-block filler, and the most-called function of the
 * family: every builder in the range (func_02013610, func_02013644,
 * func_02013678, func_020136AC, func_020136E0, func_02013734, func_02013810,
 * all EXACT) calls it once or three times.  It lazily fills two slots - the
 * caller's own out-pointer and the object's +0x48 array entry - then, only if
 * the value argument is non-zero, binds them together and picks the object's
 * +0x1a code from a twelve-way switch.
 *
 * This closes the near miss in docs/notes/pkt_02013284.c.txt, which sat at 48
 * concrete bytes out with the size already exact.  Two things closed it.
 *
 * (1) THE ARITY IS SIX, NOT SEVEN.  The note gave it seven parameters
 * (a0..a6).  The six-parameter form is fixed from outside this function by
 * the matched callers, every one of which passes exactly six
 * (o, a1, n, dst, v, h).  Re-spelling the signature that way took the
 * residue from 48 concrete bytes out to 15 and halved the permuter's
 * instruction score, 525 -> 280, with the size unchanged at 184.
 *
 * (2) THE +0x48 SLOT IS REGISTER-OFFSET ADDRESSED, so its base and its
 * scaled index have to be two separate live values.  The image loads it with
 * `ldr r0, [r7, r6]` where r7 is o+0x48 and r6 is n*4; writing the access as
 * a single pointer, `slot = (u32 *)(o + 0x48 + n * 4)`, folds the two into
 * one value and the allocator then has one fewer value to colour, which is
 * what produced the r5/r6/r7 rotation the permuter reported.  Splitting it
 * into a `u8 *base` and a separate `u32 off`, and indexing as
 * `*(u32 *)(base + off)`, keeps both values live and gives the original
 * registers and the original `lsls` / `adds` order.  A `u32 *` base with a
 * divided index (`base[off / 4]`) does NOT work: the compiler folds the
 * scaling back out and the rotation returns.
 *
 * The permuter was the diagnostic here rather than the fix.  `--explain` on
 * the seven-parameter source printed a clean three-way register rotation
 * (r7->r6, r6->r7, r5->...), which is what said the residue was an allocation
 * tie and not a mistranslation, and on the six-parameter source it printed
 * the same rotation at 15 bytes out with every instruction aligned - which
 * localised the fix to the one value that was missing.  Its own best results
 * were rejected on both passes: hill found temp(tmp=*slot) at 11 bytes out
 * but with the instruction score RISING 280 -> 460, the signature of a
 * coincidental byte alignment rather than a real fix.
 *
 * The switch is dense from 2 to 11 with 0, 1, 5 and 10 falling to the
 * default, which is what makes the PC-relative halfword table exist; the
 * `cmp r0, #0xb / bhi` pair is the table's range check.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02013284.c \
 *       --func func_02013284 --addr 0x02013284 --cc 1.1p1 --thumb
 */
void func_02013284(u8 *o, u32 *a1, u32 n, u32 *dst, u32 v, u32 h)
{
    u8 *base;
    u32 off;

    if (*dst == 0) {
        *dst = (u32)func_0201A920(h);
    }
    off = n * 4;
    base = o + 0x48;
    if (*(u32 *)(base + off) == 0) {
        *(u32 *)(base + off) = (u32)func_02013234(h);
    }
    if (v == 0) {
        return;
    }
    func_0202A440(v, (struct Out *)(*(u32 *)(base + off)), h);
    func_0202A4B4(v, *dst, h);
    func_0216AAE4((u32)a1, *dst, func_02012984((const struct BigObj *)((u32)a1)));
    switch (func_0202A3FC(*(u32 *)(*(u32 *)(base + off) + 4))) {
    case 2:
    case 3:
        ((struct Obj00155 *)o)->f1A = 0x47e;
        break;
    case 7:
    case 8:
        ((struct Obj00155 *)o)->f1A = 0x47f;
        break;
    case 4:
    case 11:
        ((struct Obj00155 *)o)->f1A = 0x480;
        break;
    case 6:
    case 9:
        ((struct Obj00155 *)o)->f1A = 0x491;
        break;
    default:
        ((struct Obj00155 *)o)->f1A = 0x47d;
        break;
    }
}


void func_0201333C(u8 *o, void *a1, int a2)
{
    func_020127A4(a1);
    ((struct Obj00155 *)o)->f24 = (u32)func_0201A920(a2);
    func_0201AC2C((const struct Rec534 *)func_02012934((const struct BigObj *)a1),
                  (struct Rec534 *)((struct Obj00155 *)o)->f24);
}


/*
 * btl_setup.c.  The shared setup-object initialiser every builder of the
 * family calls with (o, a1, sub): reset the flag and slot fields, read the
 * per-battle values out of the game-data object a1, and copy the 0x10-byte
 * sub-block a2 to +8.
 *
 * Two facts closed it (docs/notes/pkt_02013360.c.txt had it at 266 bytes
 * out, every line phase-shifted from the head):
 *  - 0x02082D44 is MI_CpuCopy8 (layout/symbols_sdk.txt), whose order is
 *    (src, dst, size): the image computes o + 8 into r1 and a2 into r0.
 *    With that order the whole body is byte-exact and only the head differs.
 *  - The first loop counter is initialised at its declaration, ahead of the
 *    store run.  That puts the constant 0 (shared by the zero stores and the
 *    counter) before the 0xffff store in the IR, so the zero takes r0 and
 *    the 0x84 base is built in r1 from the o copy, which is the image's
 *    head.  With `for (i = 0; ...)` the base coalesces into r0 instead and
 *    every later line is displaced.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02013360.c  *       --func func_02013360 --addr 0x02013360 --cc 1.1p1 --thumb
 */
void func_02013360(u8 *o, void *a1, const void *a2)
{
    u32 i = 0;
    u32 j;
    u32 t;
    u32 u;

    ((struct Obj00155 *)o)->f84 = 0xffff;
    *(o + 0x20) = 0;
    *(o + 0x21) = 0;
    *(o + 0x22) = 0;
    ((struct Obj00155 *)o)->f94 = 0;
    *(o + 0x23) = 0;
    *(o + 0xc1) = *(o + 0xc1) & ~1;
    ((struct Obj00155 *)o)->f1C = 0;
    *(o + 0xc1) = *(o + 0xc1) & ~2;
    ((struct Obj00155 *)o)->f58 = (u32)a1;
    for (; i < 4; i++) {
        *(u32 *)(o + i * 4 + 0x24) = 0;
        *(u32 *)(o + i * 4 + 0x34) = 0;
    }
    for (j = 0; j < 6; j++) {
        *(o + j + 0xc2) = 0;
    }
    *(o + 0x7f) = 1;
    for (i = 0; i < 7; i++) {
        *(o + i + 0x78) = 0;
    }
    ((struct Obj00155 *)o)->f34 = (u32)func_02012944(a1);
    ((struct Obj00155 *)o)->f60 = func_0201292C(a1);
    ((struct Obj00155 *)o)->f64 = func_02012924(a1);
    ((struct Obj00155 *)o)->f68 = (u32)func_0200CA1C(a1);
    ((struct Obj00155 *)o)->f70 = func_02012F20((int)a1);
    ((struct Obj00155 *)o)->f6C = (u32)func_02012F2C(a1);
    t = (u32)func_02012EBC(a1);
    u = (u32)func_0200C0E8((void *)t);
    ((struct Obj00155 *)o)->f5C = (u32)func_0200873C((void *)t);
    *(o + 0x80) = (u8)func_0200C258((struct Blk34 *)u);
    func_02082D44(a2, o + 8, 0x10);
    ((struct Obj00155 *)o)->f18 = 0x468;
    ((struct Obj00155 *)o)->f1A = 0x468 + 0x14;
    ((struct Obj00155 *)o)->f8C = 1;
    if (func_020142E8((void *)func_0201296C(a1), 0x96d) != 0) {
        func_02013144((char *)o, 2);
    }
}


/*
 * btl_setup.c.  The link-battle variant of the setup builder: the same
 * three shared writers as func_020135C0, then the object is put in mode 0
 * and a consistency check on the +0x24 slot decides whether flag 0x40 is
 * set.
 *
 * The documented near miss in docs/notes/pkt_02013360.c.txt compiled 122
 * bytes against 120 and missed on 108 of them.  Two leftover-register
 * readings are what close it, and both are the same idiom, see
 * docs/idioms/a-loop-carried-value-in-a-callees-argument-register-names-the-arity.md.
 *
 * (1) func_0201AC2C takes the func_0201A920 result as a second argument.
 * The original writes `adds r1, r0, #0; str r1, [r4, #0x28]`, which reads
 * as a gratuitous register copy before the store.  It is not: r1 is the
 * second argument of the guarded func_0201AC2C call below, so the value has
 * to reach r1 anyway and the store then sources it from there.  The
 * declaration has to be variadic, `void func_0201AC2C(u32 a, ...)`, because
 * the other call site of this family (in func_020135C0, EXACT) passes two
 * registers while some pass one; a fixed two-parameter declaration emits a
 * spurious `movs r1, #0`.  This is the same finding
 * docs/notes/pkt_02013528.c.txt reached for func_020135C0.
 *
 * (2) func_020076D0 takes THREE arguments, and its first is the return
 * value of the func_0201293C call immediately above it.  The original sets
 * only r1 and r2 (`add r1, sp, #4; add r2, sp, #0`) and leaves r0 holding
 * what func_0201293C returned.  Declaring it with two parameters puts the
 * two pointers in r0/r1 and is a two-byte, two-instruction miss; declaring
 * func_0201293C as returning u32 and passing that result explicitly gives
 * the original bytes with no extra `adds`, because the value is already in
 * r0 and the compiler elides the copy.
 *
 * The two out-parameters are declared x then y but passed &x as the SECOND
 * argument and &y as the third: x lives at sp+4 and y at sp+0, which is the
 * later-declaration-at-the-lower-address rule, see
 * docs/idioms/local-declaration-order-is-stack-order.md.
 *
 * EXACT*: all 118 code bytes reproduce (10 of 10 relocation sites
 * resolved); the inferred extent ran two bytes long only on the
 * `movs r0, r0` alignment pad at 0x020134F2 before func_020134F4.  Never a
 * byte difference.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201347C.c \
 *       --func func_0201347C --addr 0x0201347C --cc 1.1p1 --thumb
 */
void func_0201347C(u8 *a0, void *a1, u32 a2, u32 a3, u32 a4, u16 a5)
{
    u32 x;
    u32 y;
    u32 r;
    u32 t;
    u32 u;

    func_020130C4(a0);
    func_02013360(a0, a1, (const void *)a3);
    func_0201333C(a0, a1, a5);
    r = (u32)func_0201A920(a5);
    ((struct Obj00155 *)a0)->f28 = r;
    if (a2 != 0) {
        func_0201AC2C((const struct Rec534 *)a2, (struct Rec534 *)r);
    }
    ((struct Obj00155 *)a0)->f4 = a4;
    ((struct Obj00155 *)a0)->f0 = 0;
    t = func_0201AA18((void *)((struct Obj00155 *)a0)->f24);
    if (t != func_0201AA14((void *)(((struct Obj00155 *)a0)->f24))) {
        return;
    }
    u = func_0201293C(a1);
    x = 0;
    y = 0;
    if (func_020076D0((void *)u, (int *)(&x), (int *)(&y)) == 0) {
        func_02013144((char *)a0, 0x40);
    }
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020134F4.c \
 *       --func func_020134F4 --addr 0x020134F4 --cc 1.1p1 --thumb
 */
void func_020134F4(u8 *p, u32 a1, u32 a2, u32 a3, u16 h)
{
    func_020130C4(p);
    func_02013360(p, (void *)a1, (const void *)a3);
    func_0201333C(p, (void *)a1, h);
    ((struct Obj00155 *)p)->f0 = 1;
    ((struct Obj00155 *)p)->f4 = a2;
    ((struct Obj00155 *)p)->f1A = 0x47d;
}
