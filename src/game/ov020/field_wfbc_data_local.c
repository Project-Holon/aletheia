/*
 * file:     field_wfbc_data_local.c
 * unit:     yes
 * function: func_02185EB0, func_02185F18, func_02185F48, func_02185F6C, func_0218601C, func_0218604C, func_0218606C, func_0218608C, func_02186090, func_0218609C, func_021860B8, func_021860D4, func_021861BC, func_021861F4, func_0218625C, func_02186278, func_021862A8, func_02186470, func_021864DC, func_02186520, func_02186538, func_02186670, func_021866F8, func_02186748, func_02186764, func_02186770, func_0218677C, func_021867A8, func_021867B0, func_021867B4, func_021867C4, func_02186804, func_02186818, func_0218682C, func_02186830, func_0218683C, func_02186844, func_0218684C, func_02186854, func_02186878, func_02186898, func_021868A0, func_021868B8, func_021869AC, func_021869B0, func_021869B8, func_021869BC, func_021869D0, func_021869D4, func_021869D8, func_021869DC, func_021869E0, func_02186A2C, func_02186A58, func_02186AC8, func_02186B08, func_02186B2C, func_02186B60, func_02186B84, func_02186BA8, func_02186BB8, func_02186BE0, func_02186BE4, func_02186C44, func_02186CC4, func_02186D48, func_02186E94, func_02186EB8, func_02187000, func_02187098, func_021870C4, func_021871F8, func_0218741C, func_0218748C, func_02187508, func_021875B8, func_021875F4, func_02187684, func_0218768C, func_021876B0, func_021876E0, func_0218774C, func_021877A8, func_02187808, func_02187860, func_02187884, func_021878C0, func_02187914, func_02187938, func_0218793C, func_0218794C, func_02187A10, func_02187A38, func_02187B38, func_02187BBC, func_02187C20, func_02187CCC, func_02187CEC, func_02187CFC, func_02187D20, func_02187D24, func_02187D28, func_02187D30, func_02187D40, func_02187D54, func_02187D74
 * address:  0x02185EB0
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02012870  0x02012870  thumb
 *   func_0201284C  0x0201284C  thumb
 *   func_02014068  0x02014068  thumb
 *   func_020128C0  0x020128C0  thumb
 *   func_02014204  0x02014204  thumb
 *   func_02013C50  0x02013C50  thumb
 *   func_02013FEC 0x02013FEC thumb
 *   func_02012894 0x02012894 thumb
 *   func_020127A4 0x020127A4 thumb
 *   func_02012B28 0x02012B28 thumb
 *   func_02012B2C 0x02012B2C thumb
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045A38  0x02045A38  arm
 *   func_02008F08  0x02008F08  thumb
 *   func_02008F88  0x02008F88  thumb
 *   func_02008FA0  0x02008FA0  thumb
 *   func_02008FA8  0x02008FA8  thumb
 *   func_02008FB4  0x02008FB4  thumb
 *   func_02008FBC  0x02008FBC  thumb
 *   func_02008FD8  0x02008FD8  thumb
 *   func_02008FC4  0x02008FC4  thumb
 *   func_02008FEC  0x02008FEC  thumb
 *   func_0200903C  0x0200903C  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 *   d_02187DA4  0x02187DA4  data  ov020  a4
 *   d_02187DAC  0x02187DAC  data  ov020  a4
 *   d_02187DB4  0x02187DB4  data  ov020  a4
 *   func_02012EBC 0x02012EBC thumb
 *   func_0201AD0C 0x0201AD0C thumb
 *   func_02012984 0x02012984 thumb
 *   func_02008B14 0x02008B14 thumb
 *   func_0216A358 0x0216A358 thumb ov010
 *   func_02030734 0x02030734 arm
 *   d_02187EA0 0x02187EA0 data ov020 a1
 *   func_0216D588  0x0216D588  thumb
 *   func_02161E78 0x02161E78 thumb ov010
 *   func_02008530  0x02008530  thumb
 *   func_020056EC  0x020056EC  thumb
 *   func_02161E84 0x02161E84 thumb ov010
 *   func_0200855C  0x0200855C  thumb
 *   func_021584F4  0x021584F4  thumb  ov010
 *   func_02161ECC 0x02161ECC thumb ov010
 *   func_02012AC8  0x02012AC8  thumb
 *   func_020127C4  0x020127C4  thumb
 *   func_020127E0  0x020127E0  thumb
 *   func_020127F0  0x020127F0  thumb
 *   func_02013DE0  0x02013DE0  thumb
 *   func_02161E60  0x02161E60  thumb
 *   func_02161EEC  0x02161EEC  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   func_0216E618  0x0216E618  thumb  ov010
 *   d_02187EB4     0x02187EB4  data  ov020  a1
 *   d_02187DBC     0x02187DBC  data  ov020  a4
 *   func_02045A98  0x02045A98  arm
 *   func_020084F4 0x020084F4 thumb
 *   func_02082D44 0x02082D44 arm
 *   func_020490F4  0x020490F4  arm
 *   func_0204932C  0x0204932C  arm
 *   func_02049238 0x02049238 arm
 *   func_02049250  0x02049250  arm
 *   d_02187DE0     0x02187DE0  data  ov020  a4
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_0218DC70  0x0218DC70  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_021A3460  0x021A3460  thumb  ov021
 *   func_0216DDC0  0x0216DDC0  thumb  ov010
 *   func_02193B40  0x02193B40  thumb  ov021
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02193BE4  0x02193BE4  thumb  ov021
 *   func_02193BC4  0x02193BC4  thumb  ov021
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_02193B68  0x02193B68  thumb  ov021
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02193904  0x02193904  thumb  ov021
 *   func_0219390C  0x0219390C  thumb  ov021
 *   func_02193C00  0x02193C00  thumb  ov021
 *   func_02193C04  0x02193C04  thumb  ov021
 *   func_021938F4  0x021938F4  thumb  ov021
 *   func_02188C80 0x02188C80 thumb ov021
 *   func_020120F4 0x020120F4 thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0203F4E4  0x0203F4E4  arm
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0219391C  0x0219391C  thumb  ov021
 *   func_0215A5DC 0x0215A5DC thumb ov010
 *   func_0201210C 0x0201210C thumb
 *   func_0215897C 0x0215897C thumb ov010
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_02158434  0x02158434  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   func_020127D0  0x020127D0  thumb
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021620A0  0x021620A0  thumb  ov010
 *   func_02162048  0x02162048  thumb  ov010
 *   func_0216208C  0x0216208C  thumb  ov010
 *   func_0216209C  0x0216209C  thumb  ov010
 *   func_02161E4C  0x02161E4C  thumb  ov010
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 *   func_02012944  0x02012944  thumb
 *   func_02161F90  0x02161F90  thumb  ov010
 *   func_02193B20  0x02193B20  thumb  ov021
 *   func_0216CF2C  0x0216CF2C  thumb  ov010
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_0219129C  0x0219129C  thumb  ov021
 *   d_02187E04     0x02187E04  data  ov020  a2
 *   func_02191388  0x02191388  thumb  ov021
 *   func_020362DC  0x020362DC  arm
 *   func_02190BE4  0x02190BE4  thumb  ov021
 *   func_02190C78  0x02190C78  thumb  ov021
 *   func_021909BC  0x021909BC  thumb  ov021
 *   func_021912D8  0x021912D8  thumb  ov021
 *   func_021912F8  0x021912F8  thumb  ov021
 *   func_0219131C 0x0219131C thumb ov021
 *   func_0216FC4C  0x0216FC4C  thumb  ov010
 *   func_0216FAB4  0x0216FAB4  thumb  ov010
 *   d_02187EDC     0x02187EDC  data  ov020  a4
 *   func_02061CA4 0x02061CA4 arm
 *   d_02187ECC 0x02187ECC data ov020 a4
 *   func_020124EC  0x020124EC  thumb
 *   func_0202E8B8  0x0202E8B8  thumb
 *   func_02043658 0x02043658 arm
 *   func_02188DA0 0x02188DA0 thumb ov021
 *   func_02043534 0x02043534 arm
 *   func_0204047C 0x0204047C arm
 *   func_020414AC 0x020414AC arm
 *   func_020433E0  0x020433E0  arm
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   d_02187E58     0x02187E58  data  ov020
 *   d_02187E28     0x02187E28  data  ov020
 *   d_02187E38     0x02187E38  data  ov020
 *   func_02062A98  0x02062A98  arm
 *   func_02040E78  0x02040E78  arm
 *   func_02062A4C  0x02062A4C  arm
 *   func_02040B1C  0x02040B1C  arm
 *   func_02062B30  0x02062B30  arm
 *   func_020409E0  0x020409E0  arm
 *   _ffltu         0x0209BE04  arm
 *   _fdiv          0x0209CE10  arm
 *   _fmul          0x0209C77C  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   func_0207D658  0x0207D658  arm
 *   func_0207D63C  0x0207D63C  arm
 *   func_0207D534  0x0207D534  arm
 *   func_0209BE04  0x0209BE04  arm
 *   func_0209CE10  0x0209CE10  arm
 *   func_0209C77C  0x0209C77C  arm
 *   func_0209C95C  0x0209C95C  arm
 *   func_0209CB8C  0x0209CB8C  arm
 *   func_0209C494  0x0209C494  arm
 *   func_0202E8A4  0x0202E8A4  thumb
 *   func_02040588  0x02040588  arm
 *   func_02188DB0  0x02188DB0  thumb  ov021
 *   func_02187D94  0x02187D94  thumb  ov020
 *   func_02189A50 0x02189A50 thumb ov021
 */
#include "../../matched/include/Obj03572.h"
#include "../../matched/include/Obj07401.h"
#include "../../matched/include/Obj19457.h"
#include "../../matched/include/Obj12540.h"
#include "../../matched/include/Obj19460.h"
#include "../../matched/include/Obj09436.h"
#include "../../matched/include/Obj19469.h"
#include "../../matched/include/Obj19470.h"
#include "../../matched/include/Obj19474.h"
#include "../../matched/include/Obj01343.h"
#include "../../matched/include/Obj00128.h"
#include "../../matched/include/Obj02070.h"
#include "../../matched/include/Obj07404.h"
#include "../../matched/include/Obj12549.h"
#include "../../matched/include/Obj19478.h"
#include "../../matched/include/Obj01651.h"
#include "../../matched/include/Obj01207.h"
#include "../../matched/include/Obj19482.h"
#include "../../matched/include/Obj19483.h"
#include "../../matched/include/Obj12551.h"
#include "../../matched/include/Obj12552.h"

#define P(o)  (*(void **)(o))
#define P18   (*(void **)(o + 0x18))
#define P1C   (*(void **)(o + 0x1c))
#define P20   (*(void **)(o + 0x20))
#define P24   (*(void **)(o + 0x24))
#define P28   (*(void **)(o + 0x28))
#define P30   (*(void **)(o + 0x30))
#define P40   (*(void **)(o + 0x40))
#define P44   (*(void **)(o + 0x44))
#define P48   (*(void **)(o + 0x48))
#define H08   (*(u16 *)(o + 0x08))
#define H4C   (*(u16 *)(o + 0x4c))
#define H4E   (*(u16 *)(o + 0x4e))
#define H50   (*(u16 *)(o + 0x50))
#define B54   (*(u8 *)(o + 0x54))
#define B56   (*(u8 *)(o + 0x56))
struct BigObj;
struct Rec1C;
struct t;
struct Rec44;
struct SaveBlock;
struct MsgBank;
struct Rec;
struct Sub02008F80Obj;
struct U16Vec;
struct Big;
struct Sub0200852CObj;
struct ArcFile;
struct Obj00020;
struct V;
struct Ctx;
struct RtcDate;
struct Desc;
struct Obj;
struct WordSet;
struct Actor;
struct VecFx32;
struct Ent;
struct Handle;
struct TexKey;
struct BgTemplate;
struct DispConfig;
struct DispVram;
struct NitroFileHeader;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Rec1C { u32 v[7]; };

typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    u16 f8;
    u16 fA;
    int f0C[6];
} Tmpl;

struct S {
    u8 lo : 4;
    u8 hi : 4;
};

struct State { u8 pad[3]; u8 low:2; u8 flag:1; u8 high:5; };

typedef signed short   s16_02185EB0;

typedef signed char    s8;

typedef struct {
u8 a;
u8 b;
u8 c;
u8 flag : 1;
} S;

typedef struct {
    u8 lo : 4;
    u8 hi : 4;
} Nib;

typedef struct { u8 lo:4; u8 hi:4; u8 b1; u8 b2; u8 pad; u16 ids[8]; } T_02186B60;

typedef struct { u8 lo:4; u8 hi:4; u8 b1; u8 b2; u8 b3; } T_02186B84;

typedef short s16_02186B2C;

typedef struct {
    int f0;
    int f4;
} Ent;

typedef signed int     s32;

struct P {
    u16 a;
    u16 x0;
    u16 b;
    u16 x1;
    u16 c;
    u16 x2;
};

struct L {
    u16 a;
    u16 b;
    int c;
    int d;
    int e;
    int f;
};

typedef struct { int index; char *base; } Pair;

typedef struct { int a; int b; u16 c; int d; int e; u8 f; u8 g; u8 pad[10];
                 int h; int i; } T;

typedef struct {
    void *p;        /* 0x00 */
    int f04;        /* 0x04 */
    u16 f08;        /* 0x08 */
    int f0c;        /* 0x0c */
    int f10;        /* 0x10 */
    u8 f14;         /* 0x14 */
    u8 f15;         /* 0x15 */
    u8 pad16[10];
    int f20;        /* 0x20 */
    int f24;        /* 0x24 */
} Work02187808;

struct Rec1C *func_02012870(const struct BigObj *p);
struct Rec1C *func_0201284C(const struct BigObj *p);
u32 func_02014068(u32 id);
void func_020128C0(struct BigObj *p, const struct Rec1C *src);
void func_02014204(struct t *p, int id);
u32 func_02013C50(u32 id);
extern u32 func_02013FEC(u32 id);
struct Rec1C *func_02012894(const struct BigObj *p);
extern void *func_020127A4(struct SaveBlock *p);
extern u32 func_02012B28(const struct Rec44 *p);
extern void func_02012B2C(struct Rec44 *p, u32 v);
struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
void *func_02045EC0(struct MsgBank *bank, u32 index);
void func_02045A38(struct U16Vec *a, unsigned short *b, unsigned int c);
void *func_02008F08(int a0);
void func_02008F88(struct Sub02008F80Obj *obj, const void *src);
void func_02008FA0(struct Sub02008F80Obj *obj, u8 value);
void func_02008FA8(struct Sub02008F80Obj *obj, u32 value);
void func_02008FB4(struct Sub02008F80Obj *obj, u8 value);
void func_02008FBC(struct Sub02008F80Obj *obj, u8 value);
void func_02008FD8(struct Sub02008F80Obj *obj, void *arg, u32 i);
void func_02008FC4(struct Sub02008F80Obj *obj, u16 value);
struct Sub02008F80Obj *func_02008FEC(void *sys);
void func_0200903C(struct Sub02008F80Obj *arr, u32 unused, int i, const struct Sub02008F80Obj *src);
u32 func_020307B0(void *p);
void func_02045808(struct U16Vec *vec);
u32 func_02045C04(struct Rec *rec);
extern void *func_02012EBC(struct Big *p);
extern void *func_0201AD0C(void *sys);
extern u8 func_02012984(const struct BigObj *p);
extern char *func_02008B14(int);
extern int func_0216A358(int a, int b, u32 *p, int c);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
u16 func_0216D588(void *p);
extern void func_02161E78(void *a0);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern u32 func_020056EC(u32 n);
extern int func_02161E84(char *);
u8 func_0200855C(const struct Sub0200852CObj *obj);
int func_021584F4(int a, int b);
extern int func_02161ECC(char *);
extern u16 func_02012AC8(const struct Rec44 *p);
extern u8 *func_020127C4(void *p);
extern int func_020127E0(int a0);
extern int func_020127F0(int a0);
extern int func_02013DE0(u16 id);
extern void func_02161E60(char *p, int a);
extern void func_02161EEC(u32 p);
extern void func_0216E618(Tmpl *, u16, u16, int);
extern u16 func_02045A98(void);
extern const void *func_020084F4(const void *p);
extern void func_02082D44(const void *src, void *dst, u32 size);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_0204932C(struct ArcFile *arc, u32 member, void *dst);
extern void func_02049238(void *p);
extern void *func_02049250(struct ArcFile *arc, unsigned int member,
                           unsigned int heap);
extern void *func_0215A5F4(void *p);
extern int func_02158F58(int a0);
extern u32 func_02188C98(unsigned char *p);
extern void *func_0218DC70(u8 *p);
extern void *func_0215A5E4(void *a0);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_02188C7C(u8 *p);
extern int func_021A3460(u32 a, u32 b, u32 c, u32 d);
extern void *func_0216DDC0(u32 a, u32 b, u32 c, u32 d);
extern void func_02193B40(struct V *v, u32 key);
extern int func_02193BE4(void *, unsigned int);
extern void func_02193BC4(void *, unsigned int);
extern void *func_02158F74(void *);
extern unsigned int func_02159B10(void *a0, void *a1);
extern u16 func_0215A5CC(void *a0);
extern void func_02193B68(void *, void *, int, int, int);
extern u16 *func_02159AE8(void *a0, void *a1);
extern int func_02193904(void *p);
extern void *func_0219390C(void *a, unsigned int b);
extern char *func_02193C00(char *p);
extern void *func_02193C04(u8 *p);
extern int func_021938F4(unsigned char *a);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
void *func_02012934(const struct BigObj *p);
u32 func_0201AA18(void *a);
void func_0203F4E4(struct RtcDate *date);
void *func_0201AB28(void *a, u32 i);
u32 func_02017E1C(void *p, u32 id, u32 v);
extern unsigned char func_0219391C(unsigned char *);
extern void *func_0215A5DC(void *p);
extern void *func_0201210C(const struct Ctx *p);
extern void func_0215897C(void *vm, void *task);
u16 func_02188C84(u8 *p);
u32 func_02188C54(u8 *p);
unsigned int func_02012138(const struct Ctx *p);
int func_02158344(int a0);
void *func_02158434(char *p);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
struct WordSet *func_0201EC64(u32 heap);
u8 *func_020127D0(u8 *o, u32 idx);
void func_0216D88C(const struct Actor *a, struct VecFx32 *b);
int func_021620A0(int a0);
void func_02162048(u16 *a, int b, int c);
int func_0216208C(char *p, int unused);
u16 func_0216209C(char *p);
int func_02161E4C(void *a0, int id, unsigned mode);
void func_0204E720(u32 a, s32 b, s32 c, s32 d);
int func_0204E804(void);
u8 *func_02012944(void *p);
void func_02161F90(int unused, u16 *x, char *y, int z, u16 w, u16 v);
int func_02193B20(u32 a, u32 b);
void func_0216CF2C(void *a);
u32 func_0201ED04(struct WordSet *p);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern struct Ent *func_0219129C(u8 *base, int idx, u32 c, u32 d, u32 f, u32 g);
extern u32 func_02191388(u32 *a);
extern u32 func_020362DC(void);
extern u32 *func_02190BE4(u16 *a, u32 b);
extern int func_02190C78(struct Handle *h);
extern int func_021909BC(void *a);
extern int func_021912D8(u32 a);
extern int func_021912F8();
extern int func_0219131C(unsigned int a);
extern int func_0216FC4C(void);
extern int func_0216FAB4(void *file, const char *texName, void *extra, const char *plttName, u32 a4, u16 a5, u16 a6, u16 a7, u16 heap, struct TexKey *out);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
extern u32 *func_020124EC(struct Obj *p);
extern u8 func_0202E8B8(int);
extern u32 func_02043658(void);
extern void func_02188DA0(void);
extern void func_02043534(u32 planes);
extern void func_0204047C(int idx, unsigned short val);
extern void func_020414AC(int a);
void func_020433E0(const struct DispVram *c);
void func_0203F8F4(u16 heapId);
void func_0203FC28(struct DispConfig *cfg);
void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020403F4(unsigned int i);
extern void func_0203F9B4(void);
s32 func_02062A98(struct NitroFileHeader *file, void **out);
void func_02040E78(u32 r7, void *r6, u32 r5, u32 r4);
s32 func_02062A4C(struct NitroFileHeader *file, void **out);
void func_02040B1C(int index, const void *src, u32 size, u32 tile);
int func_02062B30(void *file, void **out);
void func_020409E0(u32 index, const void *src, u32 mode, u32 offset);
void func_0207D658(u32 addr, int plane, int brightness);
void func_0207D63C(u32 addr, int plane1, int plane2, int ev1, int ev2);
void func_0207D534(volatile u16 *reg, int brightness);
u32 func_0209BE04(u32 x);
u32 func_0209CE10(u32 a, u32 b);
u32 func_0209C77C(u32 a, u32 b);
u32 func_0209C95C(u32 a, u32 b);
u32 func_0209CB8C(u32 a, u32 b);
u32 func_0209C494(u32 x);
u8 func_0202E8A4(u8 x);
void func_02040588(unsigned char which, unsigned char enable);
void func_02188DB0(u8 *a);
void func_02187D94(void *o);
extern void func_02189A50(char *p, int v);
void func_02185EB0(int a, u16 *p);
void func_02185F18(struct BigObj *p, struct Rec1C *out);
void func_02185F48(void *p);
void func_02185F6C(int a);
void func_0218601C(int p);
void *func_0218604C(void);
void *func_0218606C(void);
void func_0218608C(void);
int func_02186090(void *p);
void func_0218609C(char *p);
void func_021860B8(char *p);
void func_021860D4(u16 *p, int a1, int id);
int func_021861BC(unsigned short *p);
void func_021861F4(u16 *p, int x);
int func_0218625C(unsigned short *p);
int func_02186278(char *p,int which);
void func_021862A8(int a0, int n, u32 flags);
void func_02186470(int a0);
void func_021864DC(u8 *p);
void func_02186520(char *p, int b, char *c);
Tmpl *func_02186538(u16 *p, int which, int id);
void func_02186670(char *base, char *out, u16 *cnt, int n, u16 id);
void func_021866F8(char *p);
void func_02186748(struct State *p);
void func_02186764(S *p);
int func_02186770(u8 *p);
void func_0218677C(u8 *p, void *src);
int func_021867A8(Nib *p);
int func_021867B0(u8 *p);
int func_021867B4(u8 *p);
int *func_021867C4(int a, int id);
void func_02186804(void **p);
void func_02186818(u32 *p, u32 member);
char *func_0218682C(char *p);
void *func_02186830(struct ArcFile **p, int b, unsigned int heap);
void func_0218683C(void *p);
u8 *func_02186844(u8 *t, int i);
char *func_0218684C(char *p, int i);
int func_02186854(u16 *p);
int func_02186878(u16 *p, u16 v, int i);
u16 func_02186898(u16 *p, int i);
int func_021868A0(u16 *p, int i);
Tmpl *func_021868B8(void *p, int a1, int a2, int id);
u16 func_021869AC(u16 *p);
void func_021869B0(u16 *p);
u16 func_021869B8(u16 *p);
void func_021869BC(u16 *p);
u16 func_021869D0(char *p);
void func_021869D4(char *p, u16 v);
u16 func_021869D8(u16 *p);
void func_021869DC(u16 *p, u16 v);
char *func_021869E0(char *a, int limit, char *h, int *out);
int func_02186A2C(char *p, int id);
int func_02186A58(char *p, int id);
void func_02186AC8(char *p, int b, char *c, int d);
int func_02186B08(char *p);
char *func_02186B2C(char *p, char *src);
char *func_02186B60(char *p);
void func_02186B84(T_02186B84 *p, int a, int b, int c, int d);
int func_02186BA8(u8 *p);
int func_02186BB8(u8 *p, int delta);
void func_02186BE0(char *p, int v);
int func_02186BE4(int a0, int a1);
int func_02186C44(int a0, int a1);
int func_02186CC4(int a0, int a1);
int func_02186D48(int a0, int a1);
int func_02186E94(void *unused, void *p);
int func_02186EB8(void *a0, void *a1);
int func_02187000(int a0, int a1);
int func_02187098(void *unused, void *p);
void *func_021870C4(void *a0, void *a1);
int func_021871F8(void *a, int *st, char *o);
void func_0218741C(char *p, int a1, int *out, int a3);
void func_0218748C(char *p, int a1, int *out, int a3, u16 a4);
int func_02187508(char *p);
int func_021875B8(char *p);
int *func_021875F4(int a0, int a1, int a2, int a3, struct P e);
void func_02187684(void *p);
void func_0218768C(char *p);
void func_021876B0(Pair *p, int tick);
int func_021876E0(void *unused, int *s, char *o);
void *func_0218774C(int a, int b, u8 c, u8 d);
void *func_021877A8(int a, int b, u8 c, u8 d, int e, int f);
void *func_02187808(void *p, u8 a1, u8 a2);
void func_02187860(char *p);
void func_02187884(char *unused);
void func_021878C0(char *o);
void func_02187914(char *p);
void func_02187938(char *p);
void func_0218793C(char *p);
void func_0218794C(int sel, int b);
void func_02187A10(char *p, int st);
void func_02187A38(const char *o, int st);
void func_02187B38(char *o, int st);
int func_02187BBC(char *o, int st);
void func_02187C20(char *o, int *p, int st);
void func_02187CCC(char *p, int *s);
void func_02187CEC(char *p);
void func_02187CFC(char *p);
u32 func_02187D20(char *p);
u32 func_02187D24(char *p);
void func_02187D28(u32 *p);
int func_02187D30(char *p);
int func_02187D40(char *p);
int func_02187D54(char *p);
int func_02187D74(char *p);
extern char d_02187DA4[];
extern char d_02187DAC[];
extern char d_02187DB4[];
extern char d_02187EA0[];
extern const char d_02187EB4[];
extern const Tmpl d_02187DBC;
extern const Tmpl d_02187DE0;
extern u16 d_02187E04[];
extern int d_02187EDC;
extern int d_02187ECC[];
extern char d_02187E58[];
extern char d_02187E28[];
extern char d_02187E38[];






void func_02185EB0(int a, u16 *p)
{
    int r7 = (int)func_02012870((const struct BigObj *)a);
    short *r6 = (short int *)func_0201284C((const struct BigObj *)a);
    u8 buf[0x1c];

    if (func_02014068(p[2])) {
        if (r6[2] == 0x88) {
            func_020128C0((struct BigObj *)a, (void *)r7);
        } else if (!func_02014068((u16)r6[2])) {
            func_02014204((struct t *)buf, 0xd6);
            func_020128C0((struct BigObj *)a, (const struct Rec1C *)buf);
        }
    }
    if (r6[2] == 0x9e) {
        if (func_02013C50(p[2]))
            func_020128C0((struct BigObj *)a, (void *)r7);
    }
}











void func_02185F18(struct BigObj *p, struct Rec1C *out)
{
    if (func_02013FEC(((u16 *)func_0201284C(p))[2]))
        *out = *func_02012894(p);
}











void func_02185F48(void *p) { void *q; q=func_020127A4(p); if (func_02012B28(q)!=3) func_02012B2C(q,0); else func_02012B2C(q,2); }












void func_02185F6C(int a)
{
    int r6 = (int)func_02045B38(0, 2, 0xbe, 1);
    int r7 = (int)func_02045EC0((struct MsgBank *)r6, 0x3b);
    int r4;
    char buf[0x20];

    func_02045A38((struct U16Vec *)r7, (unsigned short *)buf, 0x10);
    r4 = (int)func_02008F08(1);
    func_02008F88((struct Sub02008F80Obj *)r4, buf);
    func_02008FA0((struct Sub02008F80Obj *)r4, 1);
    func_02008FA8((struct Sub02008F80Obj *)r4, 3);
    func_02008FB4((struct Sub02008F80Obj *)r4, 2);
    func_02008FBC((struct Sub02008F80Obj *)r4, 0x15);
    func_02008FD8((struct Sub02008F80Obj *)r4, d_02187DA4, 0);
    func_02008FD8((struct Sub02008F80Obj *)r4, d_02187DAC, 1);
    func_02008FD8((struct Sub02008F80Obj *)r4, d_02187DB4, 2);
    func_02008FC4((struct Sub02008F80Obj *)r4, 0x58F);
    func_0200903C(func_02008FEC((void *)a), 0, 0, (const struct Sub02008F80Obj *)r4);
    func_020307B0((void *)r4);
    func_02045808((struct U16Vec *)r7);
    func_02045C04((struct Rec *)r6);
}











void func_0218601C(int p) { int a; int b; int c; a=(int)func_02012EBC((struct Big *)p); b=(int)func_0201AD0C((void *)a); c=func_02012984((const struct BigObj *)p); func_0216A358(p,b,(u32 *)(func_02008B14(a)+0x14),c); }











void *func_0218604C(void) { return func_02030734(0x8004,0x1000,0,d_02187EA0,0xe35); }










void *func_0218606C(void) { return func_02030734(0x8004,0x1000,0,d_02187EA0,0xe3a); }










/*
 * Unlabelled leaf: an empty function (`bx lr` plus two bytes of padding)
 * after func_0218606C.  ov020 func_021841C0 passes its address as the end
 * of the range handed to the ov230 routine func_021883CC, the same way it
 * passes func_0218604C and func_0218606C to func_021882A0 and func_02188318.
 */
void func_0218608C(void)
{
}











/*
 * extent: two zero alignment bytes after the return.
 */
int func_02186090(void *p)
{
    return func_0216D588(p) - 0x80;
}










void func_0218609C(char *p) { int i; p += 8; for (i=0;i<10;i++) func_02161E78(p+i*0x18); }










void func_021860B8(char *p) { int i; p += 0xf8; for (i=0;i<10;i++) func_02161E78(p+i*0x18); }











void func_021860D4(u16 *p, int a1, int id)
{
    int i;
    int j;
    int r;
    char *e;
    int rem;
    int flag;
    int out;
    void *slot;
    int h;
    int v;

    p[0] = 1;
    i = 0;
    p[1] = 0;
    rem = 0x1CE;
    ((struct Obj03572 *)p)->f4 = func_02008530((const struct Sub0200852CObj *)a1);
    h = (int)func_021867C4(0, (u16)((id & 0x7FFF) | 0x8000));
    func_0218682C((char *)h);
    for (i = 0; i < 10; i++) {
        r = func_020056EC(rem);
        slot = func_02186B60((char *)(p + 4));
        e = func_021869E0((char *)p, r, (char *)h, &out);
        if (p[1] == 0) {
            v = ((struct Obj07401 *)e)->f6;
            flag = 1;
        } else {
            v = ((struct Obj07401 *)e)->f4;
            flag = 0;
        }
        func_02186B84(slot, (u8)out, a1, (u16)v, flag);
        rem -= ((struct Obj07401 *)e)->f2C;
    }
    for (j = 0; j < 3; j++) {
        r = func_020056EC(rem);
        slot = func_02186B60((char *)p + 0xf8);
        e = func_021869E0((char *)p, r, (char *)h, &out);
        func_02186B84(slot, (u8)out, a1, 0, flag);
        rem -= ((struct Obj07401 *)e)->f2C;
    }
    func_02186804((void **)h);
}










int func_021861BC(unsigned short *p) { char *q; int i; if(p[0]==1 && p[1]>=2) return 0; q=(char *)p; i=0; q+=8; for(;i<10;i++) if(func_02161E84(q+i*0x18)==0) return 0; return 1; }










void func_021861F4(u16 *p, int x)
{
    int i;

    if (p[0] > 1)
        p[0] = 1;
    if (p[0] == 0 && p[1] != 2)
        p[1] = 2;
    if (p[0] == 1 && p[1] >= 2) {
        int r6 = func_0200855C((const struct Sub0200852CObj *)x);
        if (func_021584F4((u8)r6, func_02008530((const struct Sub0200852CObj *)x)) == 0x15)
            p[1] = 0;
        else
            p[1] = 1;
    }
    for (i = 0; i < 10; i++)
        func_021866F8((char *)p + 8 + i * 0x18);
}









int func_0218625C(unsigned short *p) { if (p[0]==0) return 0; if (func_021861BC(p)!=0) return 1; return 0; }









int func_02186278(char *p,int which) { char *q; int i; int count; if (which==0) q=p+8; else q=p+0xf8; count=0; for(i=0;i<10;i++) if(func_02161ECC(q+i*0x18)) count++; return count; }








/*
 * 2026-10-04 (wD3 lane 15): DIFF, 456 bytes (right size), 200 diff bytes, all from one cause. The original spills the
 * func_02012AC8 result (id) to [sp,#0x14] at once and loads it later for the u16 shift (id16 at sp24); this draft
 * keeps id in r7, so every later slot is one word lower (frame 0x2c vs 0x30). Control flow, the qq/items3 double store
 * and all calls match. Tried: id16, qq, items3 as named locals (current), compiler hoist of (u16)id (slots wrong),
 * u16 callee param for func_02186878 (extra mov). Next: find what makes id spill (a second use of id, decl order).
 *
 * Note 2026-10-05 (wD4 lane12): MATCH, all 456 bytes. Keys: no qq/id16
 * locals (base + 0xF8 and the id conversion are compiler loop hoists, which
 * spills id at once); func_02013DE0 takes u16 and gets id directly; p is set
 * inside the if; the item base is a named items = base + 8 assigned after
 * i = 0; the second loop uses base + 8 + off (hoisted copy-add at sp+0x2c);
 * the random third argument goes through a u16 local v; q[t%3] reads
 * (q + 4)[t % 3]. Only blocker: arm9 callee 0x02013DE0 had no label; filed
 * src/matched/arm9/func_02013DE0.c (EXACT). EXACT once that has a shard.
 */
void func_021862A8(int a0, int n, u32 flags)
{
    char *base;
    char *items;
    u32 p1;
    u32 p2;
    u32 id;
    u32 cnt;
    int mul;
    char *p;
    int off;
    int i;
    int j;
    int h;
    u16 *q;
    u32 acc;
    u32 t;

    id = func_02012AC8(func_020127A4((struct SaveBlock *)a0));
    base = (char *)func_020127C4((void *)a0);
    p1 = func_020127E0(a0);
    p2 = func_020127F0(a0);
    if (n <= 0) {
        n = 1;
    }
    if (n > 21) {
        n = 21;
    }
    cnt = func_02186278(base, 1);
    j = 0;
    mul = (j - 5) * n;
    i = 0;
    items = base + 8;
    for (; i < 10; i++) {
        if (func_02161ECC(items + i * 0x18) != 0) {
            int r;
            p = base + i * 0x18;
            p[0xb] = 7;
            r = func_02186BB8((u8 *)(items + i * 0x18), mul);
            if (r != 0 && cnt + j >= 10) {
                func_02186BE0(items + i * 0x18, 1);
            } else if (r != 0) {
                if (func_02013DE0(id) == 0) {
                    func_02186B2C(base + 0xF8, items + i * 0x18);
                    func_02161E78(items + i * 0x18);
                } else {
                    p[0xb] = 1;
                }
                j++;
            }
        }
    }
    i = 0;
    func_02161E60(base, 0);
    func_02161EEC(p1);
    h = (int)func_021867C4(0, (u16)((flags & 0x7FFF) | 0x8000));
    if (*(u16 *)(base + 2) == 1) {
        for (i = 0; i < 10; i++) {
            char *e = base + 8 + i * 0x18;
            if (func_02161ECC(e) != 0) {
                func_02186818((u32 *)h, *(u8 *)(base + i * 0x18 + 9));
                q = (u16 *)func_0218682C((char *)h);
                if ((u16)func_020056EC(100) < q[0x26 / 2]) {
                    u16 v = func_020056EC(10);
                    func_02186878((u16 *)p1, q[0x24 / 2], v);
                }
            }
        }
        i = 0;
        cnt = func_02186278(base, 0);
        if (cnt != 0) {
            acc = 0;
            t = func_020056EC(cnt * 3);
            for (j = 0; j < 10; j++) {
                off = j * 0x18;
                if (func_02161ECC(base + 8 + off) != 0) {
                    acc += 3;
                    if (acc > t) {
                        func_02186818((u32 *)h, *(u8 *)(base + off + 9));
                        q = (u16 *)func_0218682C((char *)h);
                        func_021869D4((char *)p2, (q + 4)[t % 3]);
                        func_021869DC((u16 *)p2, q[0x24 / 2]);
                        break;
                    }
                }
            }
        }
    }
    func_02186804((void **)h);
}







/*
 * note: 2026-10-05 (wD9r lane166): EXACT. The tests use the items local (items + i * 0x18), the body
 *   calls spell the address again as base + 8 + i * 0x18, as in the matched siblings ov010 02161DC4
 *   and ov020 021862A8 (a = p + 8 for the tests, p + 8 + i * 0x18 for the result). The second spelling
 *   is a separate invariant in the if body; LICM probably hoists it before the (u16)id conversion, so the
 *   items web is a late temp that interferes with id and takes r4 (a0 r4, id r5 as in the image).
 */
void func_02186470(int a0)
{
    char *q;
    u32 id;
    char *base;
    char *items;
    u16 key;
    int i;

    id = func_02012AC8(func_020127A4((struct SaveBlock *)a0));
    base = (char *)func_020127C4((void *)a0);
    i = 0;
    q = base + 0xF8;
    items = base + 8;
    key = id;
    for (; i < 10; i++) {
        if (func_02161ECC(items + i * 0x18) != 0 && func_02186BA8((u8 *)(items + i * 0x18)) != 0 && func_02013DE0(key) == 0) {
            func_02186B2C(q, base + 8 + i * 0x18);
            func_02161E78(base + 8 + i * 0x18);
        }
    }
    func_02161E60(base, 0);
}







static inline void clear_flag(u8 *p, unsigned int mask)
{
    unsigned int value = *p;
    value &= ~mask;
    *p = value;
}







/*
 * extent: 66 bytes of code followed by two zero alignment bytes.
 * Lever: the inline helper holds the loaded byte in a full-width unsigned
 * local before clearing its bits; the constant argument stays positive
 * and is hoisted to a spill instead of folding to the byte complement.
 */
void func_021864DC(u8 *p)
{
    int i;
    for (i = 0; i < 10; i++) {
        if (func_02161ECC((char *)(p + 8 + i * 0x18)) &&
            (*(u8 *)((unsigned int)p + i * 0x18 + 0xb) & 2)) {
            func_02186BB8(p + 8 + i * 0x18, 3);
            clear_flag((u8 *)((unsigned int)p + i * 0x18 + 0xb), 2);
        }
    }
}







void func_02186520(char *p, int b, char *c) { if (((struct Obj19457 *)p)->f2 == 0) func_02186AC8(p,b,c,1); else func_02186AC8(p,b,c,0); }








Tmpl *func_02186538(u16 *p, int which, int id)
{
    int k;
    Tmpl *buf;
    int h;
    u8 *t;
    int heap;
    int n;
    int i;
    int off;
    char *base;
    u16 *r;
    Tmpl *e;
    Tmpl tmp;

    heap = (u16)((id & 0x7FFF) | 0x8000);
    n = func_02186278((char *)p, which);
    if (n == 0)
        return 0;
    if (which == 0)
        base = (char *)p + 8;
    else
        base = (char *)p + 0xf8;
    buf = func_02030734(heap, n * 0x24, 1, d_02187EB4, 0x2E3);
    k = 0;
    h = (int)func_021867C4(0, heap);
    t = func_02186830((struct ArcFile **)h, p[1], heap);
    i = 0;
    tmp = d_02187DBC;
    for (; i < 10; i++) {
        off = i * 0x18;
        if (func_02161ECC((char *)(base + off))) {
            e = &buf[k];
            *e = tmp;
            func_02186818((u32 *)h, func_021867B0((u8 *)(base + off)));
            r = (u16 *)func_0218682C((char *)h);
            e->f0 = func_021867B0((u8 *)(base + off)) + 0x80;
            e->f2 = r[0];
            e->f4 = 3;
            if (which == 0) {
                if (p[1] == 0)
                    e->fA = r[0xf];
                else
                    e->fA = r[0xe];
            } else {
                if (p[1] == 0)
                    e->fA = r[0x11];
                else
                    e->fA = r[0x10];
            }
            func_0216E618(e, t[i * 2], t[i * 2 + 1], 0);
            k++;
        }
    }
    func_0218683C(t);
    func_02186804((void **)h);
    return buf;
}








void func_02186670(char *base, char *out, u16 *cnt, int n, u16 id)
{
    unsigned t;
    unsigned lim;
    int k;
    int num;
    int i;
    int h;
    char *r;
    char *q;

    t = func_02186278(base, 0);
    k = n * 2;
    lim = k + 2;
    if (lim > t)
        lim = t;
    num = lim - k;
    i = 0;
    h = (int)func_021867C4(0, id);
    r = func_0218682C((char *)h);
    *cnt = 0;
    if (num > 0) {
        q = base + k * 0x18;
        do {
            func_02186818((u32 *)h, (u8)q[i * 0x18 + 9]);
            *(u16 *)(out + *cnt * 8) = ((struct Obj12540 *)r)->f28;
            *(int *)(out + *cnt * 8 + 4) = ((struct Obj12540 *)r)->f2A;
            *cnt = *cnt + 1;
            i++;
        } while (i < num);
    }
    func_02186804((void **)h);
}








void func_021866F8(char *p)
{
    int i;
    int found;
    u16 v;

    v = func_02045A98();
    if ((u8)p[1] >= 0x1e)
        func_02161E78(p);
    if ((u8)p[2] > 0x64)
        func_02161E78(p);
    if (((struct S *)p)->hi != 0) {
        found = 0;
        for (i = 0; i < 8; i++) {
            if (v == *(u16 *)(p + 4 + i * 2))
                found = 1;
        }
        if (found == 0)
            func_02161E78(p);
    }
}







/*
 * Lever: raw-byte flag test, then bitfield assignment for the bics clear.
 */
void func_02186748(struct State *p) { if (((u8 *)p)[3] & 4) { func_02186BB8((u8 *)p, 10); p->flag = 0; } }








/*
 * Clear bit 0 of the byte at +3.
 *
 * Addresses are Black-image addresses.
 */
void func_02186764(S *p)
{
p->flag = 0;
}







/*
 * Test: is bit 0 of the byte at +3 set.
 *
 * Addresses are Black-image addresses.
 */
int func_02186770(u8 *p)
{
return (((struct Obj19460 *)p)->f3 & 1) != 0;
}






/*
 * Follower 021867A8 is already filed separately; 020084F4 returns its unchanged incoming r0.
 */
void func_0218677C(u8 *p, void *src) { p[0] = (p[0] & ~0xF0) | 0x10; ((struct Obj09436 *)p)->f14 = func_02008530(src); func_02082D44(func_020084F4(src), p + 4, 16); }







/*
 * Unlabelled leaf (saves nothing, so disasm.py prints it as .word data);
 * filed as the blocker of func_02186D48 (ov020).
 */
int func_021867A8(Nib *p)
{
    return p->hi;
}






/*
 * Follower 021867B4 is already filed separately.
 */
int func_021867B0(u8 *p) { return p[1]; }







int func_021867B4(u8 *p)
{
    return p[2] <= 20;
}







int *func_021867C4(int a, int id)
{
    int *p = func_02030734(id, 0x38, 1, (const char *)&d_02187EB4, 0x448);

    p[0] = (int)func_020490F4(0x9a, id);
    func_0204932C((void *)p[0], a, p + 2);
    p[1] = a;
    return p;
}






void func_02186804(void **p) { func_02049238(p[0]); func_020307B0(p); }






void func_02186818(u32 *p, u32 member) { func_0204932C((struct ArcFile *)p[0], member, p + 2); p[1] = member; }






char *func_0218682C(char *p)
{
    return p + 8;
}







void *func_02186830(struct ArcFile **p, int b, unsigned int heap)
{
    return func_02049250(*p, b + 0x22, heap);
}






/*
 * Follower 02186844 is already filed separately.
 */
void func_0218683C(void *p) { func_020307B0(p); }







/*
 * Unlabelled leaf: address of the i-th two-byte pair of a table.
 *
 * Addresses are Black-image addresses.
 */
u8 *func_02186844(u8 *t, int i)
{
    return t + i * 2;
}






char *func_0218684C(char *p, int i)
{
    return p + (i + 0xa) * 2;
}






int func_02186854(u16 *p) { int i; int n; n = 0; for (i = 0; i < 10; i++) { if (p[i] != 0xFFFF) n++; } return n; }





int func_02186878(u16 *p, u16 v, int i) { if (p[i] == 0xFFFF) { p[i] = v; return 1; } return 0; }






u16 func_02186898(u16 *p, int i)
{
    return p[i];
}





int func_021868A0(u16 *p, int i) { if (p[i] != 0xFFFF) return 1; return 0; }






Tmpl *func_021868B8(void *p, int a1, int a2, int id)
{
    Tmpl *buf;
    int h;
    u8 *t;
    u8 *q;
    int heap;
    int n;
    int k;
    Tmpl *e;
    int i;
    Tmpl tmp;

    if (a1 != 0)
        return 0;
    if (a2 == 0)
        return 0;
    heap = (u16)((id & 0x7FFF) | 0x8000);
    n = func_02186854(p);
    k = 0;
    buf = func_02030734(heap, n * 0x24, 1, d_02187EB4, 0x561);
    h = (int)func_021867C4(0, heap);
    t = func_02186830((struct ArcFile **)h, a2, heap);
    i = 0;
    tmp = d_02187DE0;
    for (; i < 10; i++) {
        if (func_021868A0(p, i)) {
            q = (u8 *)func_0218684C((char *)t, i);
            e = &buf[k];
            *e = tmp;
            e->f0 = i + 0xa0;
            e->fA = func_02186898(p, i);
            e->f8 = i + 0xaa0;
            func_0216E618(e, q[0], q[1], 0);
            k++;
        }
    }
    func_0218683C(t);
    func_02186804((void **)h);
    return buf;
}






u16 func_021869AC(u16 *p)
{
    return p[0];
}






void func_021869B0(u16 *p)
{
    (*p)++;
}






u16 func_021869B8(u16 *p)
{
    return p[1];
}






void func_021869BC(u16 *p)
{
    if (p[1] < 0x2710)
        p[1] += 10;
}






u16 func_021869D0(char *p)
{
    return ((struct Obj19469 *)p)->f2;
}






void func_021869D4(char *p, u16 v)
{
    ((struct Obj19470 *)p)->f2 = v;
}






u16 func_021869D8(u16 *p)
{
    return p[0];
}






void func_021869DC(u16 *p, u16 v)
{
    *p = v;
}






char *func_021869E0(char *a, int limit, char *h, int *out)
{
    char *q;
    int i;
    u32 sum;
    int r;

    sum = 0;
    q = func_0218682C(h);
    for (i = 0; i < 30; i++) {
        r = func_02186A2C(a, i);
        func_02186818((u32 *)h, r);
        sum += *(u16 *)(q + 0x2C);
        if (sum > limit) {
            *out = r;
            return q;
        }
    }
    return q;
}





int func_02186A2C(char *p, int id) { int i; int n; n = 0; for (i = 0; i < 30; i++) { if (func_02186A58(p, i) == 0) { if (n == id) return i; n++; } } return 0; }






int func_02186A58(char *p, int id)
{
    int i;
    char *b;
    char *a;

    i = 0;
    a = p + 8;
    for (; i < 10; i++) {
        if (func_02161ECC(a + i * 0x18) != 0 && (u8)p[i * 0x18 + 9] == id)
            return 1;
    }
    i = 0;
    b = p + 0xF8;
    for (; i < 10; i++) {
        if (func_02161ECC(b + i * 0x18) != 0 && (u8)p[i * 0x18 + 0xF9] == id)
            return 1;
    }
    return 0;
}






void func_02186AC8(char *p, int b, char *c, int d)
{
    char *q;

    if (func_02186B08(p + 8) == 1) {
        func_02186B2C(p + 0xF8, p + 0xE0);
        func_02161E78(p + 0xE0);
    }
    q = p + 8;
    q = func_02186B2C(q, c);
    if (d != 0)
        func_0218677C((u8 *)q, (void *)b);
}





int func_02186B08(char *p) { int i; for (i = 0; i < 10; i++) { if (func_02161ECC(p + i * 24) == 0) return 0; } return 1; }






/*
 * Lever: unsigned index scaling retains separate source/destination multiplies.
 */
char *func_02186B2C(char *p, char *src) { int i; for (i = 9; i > 0; i--) func_02082D44(p + (u32)(i - 1) * 24, p + (u32)i * 24, 24); func_02082D44(src, p, 24); return p; }






char *func_02186B60(char *p)
{
    int i;
    for (i = 0; i < 10; i++) {
        if (func_02161ECC((char *)(p + i * 24)) == 0)
            return p + i * 24;
    }
    return p;
}






/*
 * lever: assign the low bitfield before the byte fields; a later bitfield store changes scheduling.
 */
void func_02186B84(T_02186B84 *p, int a, int b, int c, int d)
{
    p->lo = 1;
    p->b1 = a;
    p->b3 = 7;
    p->b2 = c;
    if (d) func_0218677C((u8 *)p, (void *)b);
}






/*
 * extent: two trailing zero alignment bytes.
 */
int func_02186BA8(u8 *p)
{
    if (p[2] == 0) return 1;
    return 0;
}






int func_02186BB8(u8 *p, int delta)
{
    int ret;
    int sum;
    ret = 0;
    sum = p[2] + delta;
    if (sum > 100) p[2] = 100;
    else if (sum < 0) { p[2] = 0; ret = 1; }
    else p[2] += (u8)delta;
    return ret;
}







void func_02186BE0(char *p, int v)
{
    ((struct Obj19474 *)p)->f2 = v;
}







int func_02186BE4(int a0, int a1)
{
    int *s;
    void *a;
    void *c;
    void *d;
    int e;
    s16_02186B2C v[3];

    s = (int *)func_02158F58((int)func_0215A5F4((void *)a1));
    a = func_0218DC70((u8 *)func_02188C98((unsigned char *)s[1]));
    c = func_02188CB4((struct Obj00020 *)s[1]);
    d = func_02188C7C((u8 *)s[1]);
    func_021A3460((u32)c, (u32)(&v[2]), (u32)(&v[1]), (u32)(&v[0]));
    e = func_02186090(func_0216DDC0((u32)d, v[2], v[0], 0));
    func_02193B40(a, e);
    return 0;
}







int func_02186C44(int a0, int a1)
{
    int *s;
    void *a;
    int b;
    void *c;
    void *d;
    int e;
    s16_02186B2C v[3];

    s = (int *)func_02158F58((int)func_0215A5F4((void *)a1));
    a = func_0218DC70((u8 *)func_02188C98((unsigned char *)s[1]));
    b = func_020127F0((int)func_0215A5E4((void *)a1));
    c = func_02188CB4((struct Obj00020 *)s[1]);
    d = func_02188C7C((u8 *)s[1]);
    func_021A3460((u32)c, (u32)(&v[2]), (u32)(&v[1]), (u32)(&v[0]));
    e = func_02186090(func_0216DDC0((u32)d, v[2], v[0], 0));
    if (func_02193BE4(a, e) != 0) {
        func_02193BC4(a, e);
        func_021869B0((u16 *)b);
    }
    return 0;
}







int func_02186CC4(int a0, int a1)
{
    void *r6;
    int *s;
    void *a;
    void *b;
    void *c;
    int r5;
    int r4;
    s16_02186B2C v[3];

    r6 = func_0215A5F4((void *)a1);
    s = (int *)func_02158F58((int)r6);
    a = func_0218DC70((u8 *)func_02188C98((unsigned char *)s[1]));
    b = func_02188CB4((struct Obj00020 *)s[1]);
    c = func_02188C7C((u8 *)s[1]);
    r6 = func_02158F74(r6);
    r5 = func_02159B10((void *)a0, (void *)a1);
    r4 = func_0215A5CC((void *)a1);
    func_021A3460((u32)b, (u32)(&v[2]), (u32)(&v[1]), (u32)(&v[0]));
    func_02193B68(a, r6, func_02186090(func_0216DDC0((u32)c, v[2], v[0], 0)), r5, r4);
    return 0;
}







int func_02186D48(int a0, int a1)
{
    int cur;
    int st;
    void *id;
    int *rec;
    void *sub;
    void *b;
    void *obj;
    int c;
    void *d;
    void *w;
    int kind;
    u16 *out;
    Ent *ent;
    void *m;
    void *s;
    s16_02186B2C v[3];

    m = func_0215A5F4((void *)a1);
    b = func_0215A5E4((void *)a1);
    c = (int)func_020127C4(b);
    kind = func_02159B10((void *)a0, (void *)a1);
    out = func_02159AE8((void *)a0, (void *)a1);
    if (kind == 3) {
        *out = func_02186278((char *)c, 0);
    } else {
    ent = (Ent *)func_02158F58((int)m);
    m = func_0218DC70((u8 *)func_02188C98((u8 *)ent->f4));
    d = func_02188CB4((struct Obj00020 *)ent->f4);
    w = func_02188C7C((u8 *)ent->f4);
    s = (void *)func_020127F0((int)b);
    func_021A3460((u32)d, (u32)(&v[2]), (u32)(&v[1]), (u32)(&v[0]));
    obj = func_0216DDC0((u32)w, v[2], v[0], 0);
    if (obj != 0) {
        cur = func_02186090(obj);
        st = func_0216D588(obj);
        func_02193904(m);
        sub = func_0219390C(m, cur);
        if (sub != 0) {
            rec = (int *)func_02193C00(sub);
            id = func_02193C04(sub);
        }
    }
    switch (kind) {
    case 0:
        *out = rec[6];
        break;
    case 1:
        *out = func_021867B4(id);
        break;
    case 2:
        *out = func_021867A8(id);
        break;
    case 3:
        break;
    case 4:
        *out = func_021869AC(s);
        break;
    case 5:
        *out = func_021869B8(s);
        break;
    case 6:
        if (func_021938F4(m) == 0)
            *out = 0;
        else
            *out = 1;
        break;
    case 7:
        *out = func_021869D8(s);
        break;
    case 8:
        *out = func_021869D0(s);
        break;
    case 9:
        *out = cur;
        break;
    case 10:
        *out = func_02193BE4(m, cur);
        break;
    case 11:
        *out = st;
        break;
    }
    }
    return 0;
}





/*
 * extent: two trailing zero alignment bytes.
 * interface: 020127F0's body loads only r0, forwarding r0 through 0200A864/0200A898.
 */
int func_02186E94(void *unused, void *p)
{
    func_021869BC((void *)func_020127F0((int)func_020120F4(func_02188C80(*(void **)(func_02158F58((int)func_0215A5F4(p)) + 4)))));
    return 0;
}






int func_02186EB8(void *a0, void *a1)
{
    void *s;
    void *w;
    void *b;
    u16 *f0;
    u16 *f1;
    u16 *f2;
    u32 n;
    int key;
    int d[4];
    u32 i;
    void *e;
    int v5, v92, v93, v94, v96, v4c, v8f, v90, v91;

    func_0215A5F4(a1);
    s = func_0215A5E4(a1);
    func_020127C4(s);
    w = (void *)func_020127F0((int)s);
    b = func_02012934(s);
    f0 = func_02159AE8(a0, a1);
    f1 = func_02159AE8(a0, a1);
    f2 = func_02159AE8(a0, a1);
    n = func_0201AA18(b);
    key = func_021869D0(w);
    func_0203F4E4((struct RtcDate *)d);
    *f0 = 0;
    *f1 = 0;
    *f2 = 0xFFFF;
    for (i = 0; i < n; i++) {
        e = func_0201AB28(b, i);
        v5 = func_02017E1C(e, 5, 0);
        v92 = func_02017E1C(e, 0x92, 0);
        v93 = func_02017E1C(e, 0x93, 0);
        v94 = func_02017E1C(e, 0x94, 0);
        v96 = func_02017E1C(e, 0x96, 0);
        v4c = func_02017E1C(e, 0x4c, 0);
        v8f = func_02017E1C(e, 0x8f, 0);
        v90 = func_02017E1C(e, 0x90, 0);
        v91 = func_02017E1C(e, 0x91, 0);
        if (v5 == key && v4c == 0 && v96 == 0x33 && v8f + v91 + v90 == 0) {
            *f0 = 1;
            if (*f2 == 0xFFFF)
                *f2 = i;
            if (v92 == d[0] && v93 == d[1] && v94 == d[2]) {
                *f1 = 1;
                *f2 = i;
            }
        }
    }
    return 0;
}






int func_02187000(int a0, int a1)
{
    void *r6;
    int *s;
    void *a;
    void *b;
    void *c;
    u16 *r4;
    int r5;
    int n;
    s16_02186B2C v[3];

    r6 = func_0215A5F4((void *)a1);
    s = (int *)func_02158F58((int)r6);
    a = func_0218DC70((u8 *)func_02188C98((unsigned char *)s[1]));
    b = func_02188CB4((struct Obj00020 *)s[1]);
    c = func_02188C7C((u8 *)s[1]);
    func_02158F74(r6);
    r4 = func_02159AE8((void *)a0, (void *)a1);
    r5 = func_02159B10((void *)a0, (void *)a1);
    func_021A3460((u32)b, (u32)(&v[2]), (u32)(&v[1]), (u32)(&v[0]));
    n = func_02186090(func_0216DDC0((u32)c, v[2], v[0], 0));
    r5 = (u16)(r5 - 1);
    if (func_0219391C(a) == 0)
        *r4 = r5 + (n * 4 + 1);
    else
        *r4 = r5 + (n * 4 + 9);
    return 0;
}





int func_02187098(void *unused, void *p)
{
    void *vm;
    void *obj;
    vm = func_0215A5F4(p);
    obj = func_0215A5DC(p);
    func_0215897C(vm, func_021870C4(obj, func_0201210C(obj)));
    return 1;
}






void *func_021870C4(void *a0, void *a1)
{
    int n;
    int c54;
    void *h;
    void *w;
    void *ret;
    void *b;
    s16_02186B2C v[3];
    char *o;
    void *a;
    void *c;
    int d;
    int e;
    void *x;

    n = func_02188C84(a1);
    c54 = func_02188C54(a1);
    h = func_020120F4(a0);
    w = (void *)func_02158344((int)((void *)func_02012138(a0)));
    if (w == 0)
        return 0;
    w = func_02158434(w);
    ret = func_020122C0(a0, 0, func_021871F8, 0x58);
    o = func_020124E8(ret);
    ((struct Obj01343 *)o)->f0 = a0;
    ((struct Obj01343 *)o)->f4 = a1;
    ((struct Obj01343 *)o)->f20 = (int)func_020457B0(0x100, n);
    ((struct Obj01343 *)o)->f24 = (int)func_020457B0(0x100, n);
    ((struct Obj01343 *)o)->f18 = (int)func_02045B38(0, 3, 0x142, n);
    ((struct Obj01343 *)o)->f1C = (int)func_0201EC64(n);
    ((struct Obj01343 *)o)->fC = c54;
    ((struct Obj01343 *)o)->f40 = w;
    ((struct Obj01343 *)o)->f56 = 1;
    ((struct Obj01343 *)o)->f8 = (n & 0x7FFF) | 0x8000;
    ((struct Obj01343 *)o)->f44 = (int)func_020127D0(h, 1);
    ((struct Obj01343 *)o)->f48 = (int)func_020127D0(h, 0);
    a = func_0218DC70((u8 *)func_02188C98(a1));
    b = func_02188CB4(a1);
    c = func_02188C7C(a1);
    func_020127F0((int)func_020120F4(a0));
    func_021A3460((u32)b, (u32)(&v[2]), (u32)(&v[1]), (u32)(&v[0]));
    d = (int)func_0216DDC0((u32)c, v[2], v[0], 0);
    func_0216D88C((const struct Actor *)d, (struct VecFx32 *)(o + 0x34));
    e = func_02186090((void *)d);
    x = func_0219390C(a, e);
    ((struct Obj01343 *)o)->f28 = a;
    ((struct Obj01343 *)o)->f2C = x;
    ((struct Obj01343 *)o)->f30 = d;
    ((struct Obj01343 *)o)->f4C = e;
    return ret;
}






/*
 * The step callback func_021870C4 registers (func_020122C0's third
 * argument) for the 0x58-byte work block it fills.
 */
int func_021871F8(void *a, int *st, char *o)
{
    if (func_02158344((int)((void *)func_02012138(P(o)))) == 0 && B56 != 0)
        *st = 0x11;

    switch (*st) {
    case 0:
        func_021620A0((int)P40);
        func_02162048(P40, H4C, 0);
        *st = 1;
        break;
    case 1:
        if (func_0216208C(P40, H4C) == 0)
            break;
        if (func_0216209C(P40) == 0)
            *st = 3;
        else
            *st = 2;
        break;
    case 2:
        func_0218741C(o, 0, st, 0x11);
        break;
    case 3:
        if (((u16 *)P44)[1] != ((u16 *)P48)[1])
            *st = 5;
        else
            *st = 4;
        break;
    case 4:
        func_0218741C(o, 1, st, 0x11);
        break;
    case 5:
        if ((unsigned int)func_02186278(P44, 0) >= 10) {
            *st = 6;
            break;
        }
        if (func_02161E4C(P44, H4C, 2) != 0)
            *st = 6;
        else
            *st = 7;
        break;
    case 6:
        func_0218741C(o, 2, st, 0x11);
        break;
    case 7:
        func_0218748C(o, 3, st, 9, 8);
        break;
    case 8:
        func_0218741C(o, 4, st, 0x11);
        break;
    case 9:
        func_021620A0((int)P40);
        func_02162048(P40, H4C, 1);
        *st = 10;
        break;
    case 10:
        if (func_0216208C(P40, H4C) == 0)
            break;
        if (func_0216209C(P40) == 2)
            *st = 12;
        else
            *st = 11;
        break;
    case 11:
        B56 = 0;
        func_0218741C(o, 5, st, 0x11);
        break;
    case 12:
        func_0218741C(o, 7, st, 0xd);
        func_021620A0((int)P40);
        func_02162048(P40, H4C, 2);
        B56 = 0;
        break;
    case 13:
        func_0204E720(1, 0, 0x10, 0);
        *st = 14;
        break;
    case 14:
        if (func_0204E804() != 0)
            break;
        func_02161F90((int)P40, P44, P48, (int)func_02012944(func_020120F4(P(o))), H4C, H08);
        func_02193B20((u32)P28, H4C);
        func_0216CF2C(P30);
        func_0204E720(1, 0x10, 0, 0);
        *st = 15;
        break;
    case 15:
        if (func_0204E804() != 0)
            break;
        *st = 0x11;
        break;
    case 16:
        if (func_02187508(o) == 0)
            break;
        if (B54)
            *st = H4E;
        else
            *st = H50;
        break;
    case 17:
        if (func_021875B8(o) == 0)
            break;
        func_02045808(P20);
        func_02045808(P24);
        func_02045C04(P18);
        func_0201ED04(P1C);
        return 1;
    }
    return 0;
}





void func_0218741C(char *p, int a1, int *out, int a3)
{
    int i;

    func_02045CAC((struct MsgBank *)(((struct Obj00128 *)p)->f18),
                  (u16)(a1 + (d_02187E04[(*(u16 **)(p + 0x48))[1]] + ((struct Obj00128 *)p)->f4C * 8)),
                  (void *)(((struct Obj00128 *)p)->f24));
    func_0201F250((struct WordSet *)(((struct Obj00128 *)p)->f1C), (void *)(((struct Obj00128 *)p)->f20), (void *)(((struct Obj00128 *)p)->f24));
    i = 0;
    *(int *)&((struct Obj00128 *)p)->f10 = (int)func_0219129C((u8 *)(((struct Obj00128 *)p)->fC), 2, (u32)(p + 0x34), ((struct Obj00128 *)p)->f20, i, i);
    *out = 0x10;
    ((struct Obj00128 *)p)->f4E = a3;
    ((struct Obj00128 *)p)->f52 = 0;
    ((struct Obj00128 *)p)->f54 = 1;
    ((struct Obj00128 *)p)->f55 = 0;
}





void func_0218748C(char *p, int a1, int *out, int a3, u16 a4)
{
    int i;

    func_02045CAC((struct MsgBank *)(((struct Obj00128 *)p)->f18),
                  (u16)(a1 + (d_02187E04[(*(u16 **)(p + 0x48))[1]] + ((struct Obj00128 *)p)->f4C * 8)),
                  (void *)(((struct Obj00128 *)p)->f24));
    func_0201F250((struct WordSet *)(((struct Obj00128 *)p)->f1C), (void *)(((struct Obj00128 *)p)->f20), (void *)(((struct Obj00128 *)p)->f24));
    i = 0;
    *(int *)&((struct Obj00128 *)p)->f10 = (int)func_0219129C((u8 *)(((struct Obj00128 *)p)->fC), 2, (u32)(p + 0x34), ((struct Obj00128 *)p)->f20, i, i);
    *out = 0x10;
    ((struct Obj00128 *)p)->f4E = a3;
    ((struct Obj00128 *)p)->f50 = a4;
    ((struct Obj00128 *)p)->f52 = 0;
    ((struct Obj00128 *)p)->f54 = 1;
    ((struct Obj00128 *)p)->f55 = 1;
}





int func_02187508(char *p)
{
    int r;

    switch (((struct Obj00128 *)p)->f52) {
    case 0:
        if (func_02191388((u32 *)(*(int *)&((struct Obj00128 *)p)->f10)) == 0)
            break;
        ((struct Obj00128 *)p)->f52 = ((struct Obj00128 *)p)->f52 + 1;
        break;
    case 1:
        if ((func_020362DC() & 0xf3) == 0)
            break;
        if (((struct Obj00128 *)p)->f55 == 0)
            ((struct Obj00128 *)p)->f52 = 4;
        else
            ((struct Obj00128 *)p)->f52 = 2;
        break;
    case 2:
        *(int *)&((struct Obj00128 *)p)->f14 = (int)func_02190BE4((u16 *)(((struct Obj00128 *)p)->fC), 0);
        ((struct Obj00128 *)p)->f52 = ((struct Obj00128 *)p)->f52 + 1;
        break;
    case 3:
        r = func_02190C78((struct Handle *)(*(int *)&((struct Obj00128 *)p)->f14));
        if (r == 2)
            break;
        if (r == 0)
            ((struct Obj00128 *)p)->f54 = 1;
        else
            ((struct Obj00128 *)p)->f54 = 0;
        ((struct Obj00128 *)p)->f52 = 4;
        func_021909BC((void *)(*(int *)&((struct Obj00128 *)p)->f14));
        *(int *)&((struct Obj00128 *)p)->f14 = 0;
        break;
    case 4:
        func_021912D8(*(int *)&((struct Obj00128 *)p)->f10);
        ((struct Obj00128 *)p)->f52 = ((struct Obj00128 *)p)->f52 + 1;
        break;
    case 5:
        if (func_021912F8(*(int *)&((struct Obj00128 *)p)->f10) != 0) {
            *(int *)&((struct Obj00128 *)p)->f10 = 0;
            return 1;
        }
        break;
    }
    return 0;
}



/*
 * lever: duplicate the zero store in both arms to retain the original branch stub.
 * regargs: high r2/r3 rows are conservative SDK-depth flags in owner callee 0219131C.
 * interface: 0219131C forwards them to 02045808 -> 020307B0 only; 0203046C
 * overwrites r2/r3, while 02030164's 0202FBAC overwrites r2 and no path reads incoming r3.
 */
int func_021875B8(char *p)
{
    if (((struct Obj00128 *)p)->f10 != 0) {
        if (((struct Obj00128 *)p)->f52 == 5) {
            if (func_021912F8(((struct Obj00128 *)p)->f10) == 0) return 0;
            ((struct Obj00128 *)p)->f10 = 0;
        } else {
            func_0219131C((unsigned int)(((struct Obj00128 *)p)->f10));
            ((struct Obj00128 *)p)->f10 = 0;
        }
    }
    if (((struct Obj00128 *)p)->f14 != 0) {
        func_021909BC((void *)(((struct Obj00128 *)p)->f14));
        ((struct Obj00128 *)p)->f14 = 0;
    }
    return 1;
}




int *func_021875F4(int a0, int a1, int a2, int a3, struct P e)
{
    struct L l;
    int *p;

    p = func_02030734(((u16 *)&e)[4], 0x1c, 1, (const char *)&d_02187EDC, 0x19c);
    p[0] = 0;
    ((struct Obj02070 *)p)->f4 = func_0216FC4C() - 1;
    ((struct Obj02070 *)p)->f6 = func_0216FC4C() - 1;
    p[4] = -1;
    p[5] = -1;
    if (func_0216FAB4((void *)a0, (const char *)a1, 0, (const char *)a2, a3, ((u16 *)&e)[0], ((u16 *)&e)[2], 0xC40, ((u16 *)&e)[4], (struct TexKey *)(&l)) != 0) {
        p[2] = l.c;
        p[3] = l.d;
        p[4] = l.e;
        ((struct Obj02070 *)p)->f4 = l.a;
        ((struct Obj02070 *)p)->f6 = l.b;
        p[5] = l.f;
        p[6] = 0;
    }
    return p;
}



void func_02187684(void *p) { func_020307B0(p); }



/*
 * lever: capture the base in a local before filling the stack pair, preserving the original r3 load.
 */
void func_0218768C(char *p)
{
    Pair pair;
    char *base;
    (((struct Obj07404 *)p)->f18)++;
    base = *(char * *)&((struct Obj07404 *)p)->f14;
    if (base != (char *)-1) {
        pair.index = ((struct Obj07404 *)p)->fC;
        pair.base = base;
        func_021876B0(&pair, ((struct Obj07404 *)p)->f18);
    }
}



void func_021876B0(Pair *p, int tick)
{
    func_02061CA4((void *)1, (u32)(p->base + (u16)p->index * 8), d_02187ECC[(tick & 31) / 8], 8);
}




int func_021876E0(void *unused, int *s, char *o)
{
    switch (*s) {
    case 0: func_02187CEC(o); break;
    case 1: case 3: break;
    case 2: func_02187A10(o, *s); break;
    case 4: func_02187A10(o, *s); break;
    case 5: func_02187CFC(o); return 1;
    }
    if (func_020362DC() & 1) { if (func_02187D20(o) == 0) func_02187D28((u32 *)o); }
    ((struct Obj12549 *)o)->f18 = ((struct Obj12549 *)o)->f18 + 1;
    func_02187CCC(o, s);
    return 0;
}




/*
 * c must be u8 (as in the twin func_02187808): with an int c the scheduler
 * hoists its spilled reload above the strb of d.
 */
void *func_0218774C(int a, int b, u8 c, u8 d)
{
    void *r7 = func_020122C0((void *)a, 0, func_021876E0, 0x28);
    T *t = func_020124E8(r7);
    int x = (int)func_020124EC(r7);
    t->a = a; t->b = b; t->c = func_02188C84((u8 *)b); t->d = 0; t->e = 0;
    t->f = d; t->g = func_0202E8B8(c); t->h = 0; t->i = 0;
    func_02187C20((char *)t, (int *)x, 0);
    return r7;
}




void *func_021877A8(int a, int b, u8 c, u8 d, int e, int f)
{
    void *r7 = func_020122C0((void *)a, 0, func_021876E0, 0x28);
    T *t = func_020124E8(r7);
    int x = (int)func_020124EC(r7);
    t->a = a; t->b = b; t->c = func_02188C84((u8 *)b); t->d = 0; t->e = 0;
    t->f = d; t->g = func_0202E8B8(c); t->h = e; t->i = f;
    func_02187C20((char *)t, (int *)x, 0);
    return r7;
}




/*
 * Allocator with callback (0x28-byte work area), then field setup and a
 * state-set call. a1 must be u8: with int a1 (a2 either int or u8) the
 * scheduler hoists the spilled a1 reload above the strb of a2.
 */
void *func_02187808(void *p, u8 a1, u8 a2)
{
    void *r0v = func_020122C0(p, 0, func_021876E0, 0x28);
    Work02187808 *w = func_020124E8(r0v);
    void *h = func_020124EC(r0v);

    w->p = p;
    w->f04 = 0;
    w->f08 = 4;
    w->f0c = 1;
    w->f10 = 0;
    w->f14 = a2;
    w->f15 = func_0202E8B8(a1);
    w->f20 = 0;
    w->f24 = 0;
    func_02187C20((char *)w, h, 0);
    return r0v;
}



void func_02187860(char *p)
{
    switch (func_02187D20(p)) {
    case 0: func_02187884(p); break;
    case 1: func_021878C0(p); break;
    }
}



void func_02187884(char *unused)
{
    int n;
    n = func_02043658();
    func_02188DA0();
    func_02043534(n);
    func_0204047C(0, 1);
    func_0204047C(3, 0);
    func_0204047C(1, 3);
    func_0204047C(2, 3);
    func_020414AC(3);
}




void func_021878C0(char *o)
{
    func_020433E0((const struct DispVram *)d_02187E58);
    func_0203F8F4(((struct Obj19478 *)o)->f8);
    func_0203FC28((struct DispConfig *)d_02187E28);
    func_0203FCA0(3, (const struct BgTemplate *)d_02187E38, 0);
    func_0204047C(0, 1);
    func_0204047C(3, 0);
    func_0204047C(1, 3);
    func_0204047C(2, 3);
    func_020414AC(3);
}



void func_02187914(char *p)
{
    switch (func_02187D20(p)) {
    case 0: func_02187938(p); break;
    case 1: func_0218793C(p); break;
    }
}



void func_02187938(char *p)
{
}




/*
 * \n * symbols:\n *   func_020403F4  0x020403F4  arm\n *   func_0203F9B4  0x0203F9B4  arm\n
 */
void func_0218793C(char *p)
{
    func_020403F4(3);
    func_0203F9B4();
}




void func_0218794C(int sel, int b)
{
    int *l_c;
    int *l_8;
    int *l_4;
    void *x;
    void *v;
    int i0, i1, i2;

    switch (sel) {
    default:
    case 0:
        i0 = 0; i1 = 1; i2 = 2;
        break;
    case 1:
        i0 = 3; i1 = 4; i2 = 5;
        break;
    case 2:
        i0 = 6; i1 = 7; i2 = 8;
        break;
    case 3:
        i0 = 9; i1 = 10; i2 = 11;
        break;
    }
    x = func_020490F4(0x97, b);
    v = func_02049250(x, i0, b);
    func_02062A98(v, (void **)(&l_c));
    func_02040E78(3, (void *)l_c[3], 0x20, 0);
    func_020307B0(v);
    v = func_02049250(x, i1, b);
    func_02062A4C(v, (void **)(&l_8));
    func_02040B1C(3, (const void *)l_8[5], l_8[4], 0);
    func_020307B0(v);
    v = func_02049250(x, i2, b);
    func_02062B30(v, (void **)(&l_4));
    func_020409E0(3, l_4 + 3, l_4[2], 0);
    func_020307B0(v);
    func_02049238(x);
}



void func_02187A10(char *p, int st)
{
    switch (func_02187D20(p)) {
    case 0: func_02187A38(p, st); break;
    case 1: func_02187B38(p, st); break;
    }
}




/*
 * Blend fade on the main engine (BLDCNT 0x04000050) plus the sub engine's
 * master brightness (0x0400106C), driven by the ratio o->0x18 / o->0x1c.
 * The object pointer is `const char *`: through a const pointer mwcc lets the
 * loads after the G2x_SetBlendAlpha_ call ignore the outgoing stack-argument
 * store, so that store is scheduled last (+0x7E). With a plain `char *` it
 * moves up to +0x78 (8 bytes out); const casts on the loads alone do not.
 */
void func_02187A38(const char *o, int st)
{
    int v;

    if (st == 2) {
        func_0207D658(0x04000050, 8,
            (int)(16.0f * ((float)*(const u32 *)&((struct Obj01651 *)o)->f18 / (float)*(const u32 *)&((struct Obj01651 *)o)->f1C) + -16.0f));
    } else if (st == 4) {
        if (*(const u8 *)&((struct Obj01651 *)o)->f15 == *(const u8 *)&((struct Obj01651 *)o)->f14) {
            v = (int)(16.0f * ((float)*(const u32 *)&((struct Obj01651 *)o)->f18 / (float)*(const u32 *)&((struct Obj01651 *)o)->f1C));
            func_0207D63C(0x04000050, 8, 0x11, 16 - v, v);
            func_0207D534((volatile u16 *)0x0400106C,
                (int)(16.0f * ((float)*(const u32 *)&((struct Obj01651 *)o)->f18 / (float)*(const u32 *)&((struct Obj01651 *)o)->f1C) + -16.0f));
        } else {
            func_0207D658(0x04000050, 8,
                (int)(0.0f - 16.0f * ((float)*(const u32 *)&((struct Obj01651 *)o)->f18 / (float)*(const u32 *)&((struct Obj01651 *)o)->f1C)));
        }
    }
}




void func_02187B38(char *o, int st)
{
    u32 a, b;

    if (st == 2) {
        a = func_0209BE04(((struct Obj01651 *)o)->f18);
        b = func_0209BE04(((struct Obj01651 *)o)->f1C);
        b = func_0209CE10(a, b);
        b = func_0209C77C(0x41800000, b);
        b = func_0209C95C(0xC1800000, b);
        func_0207D658(0x04000050, 8, func_0209C494(b));
    } else if (st == 4) {
        a = func_0209BE04(((struct Obj01651 *)o)->f18);
        b = func_0209BE04(((struct Obj01651 *)o)->f1C);
        b = func_0209CE10(a, b);
        b = func_0209C77C(0x41800000, b);
        b = func_0209CB8C(0, b);
        func_0207D658(0x04000050, 8, func_0209C494(b));
    }
}




int func_02187BBC(char *o, int st)
{
    switch (st) {
    case 0:
        st = 1;
        break;
    case 1:
        st = 2;
        break;
    case 2:
        if (func_02187D30(o) == 1)
            st = 3;
        break;
    case 3:
        if (func_02187D30(o) == 1 || func_02187D24(o) == 1)
            st = 4;
        break;
    case 4:
        if (func_02187D30(o) == 1) {
            st = 5;
            if (((struct Obj01207 *)o)->f14 != ((struct Obj01207 *)o)->f15)
                st = 1;
        }
        break;
    case 5:
        break;
    }
    return st;
}




void func_02187C20(char *o, int *p, int st)
{
    switch (st) {
    case 0:
        func_02187860(o);
        break;
    case 1:
        ((struct Obj01207 *)o)->f15 = func_0202E8A4(((struct Obj01207 *)o)->f15);
        func_0218794C(((struct Obj01207 *)o)->f15, ((struct Obj01207 *)o)->f8);
        break;
    case 2:
        func_02040588(3, 1);
        func_02040588(0, 0);
        func_0207D534((volatile u16 *)0x0400006C, 0);
        func_0207D658(0x04000050, 8, -16);
        ((struct Obj01207 *)o)->f1C = func_02187D40(o);
        break;
    case 3:
        ((struct Obj01207 *)o)->f1C = func_02187D74(o);
        break;
    case 4:
        ((struct Obj01207 *)o)->f1C = func_02187D54(o);
        if (func_02187D20(o) == 0 && ((struct Obj01207 *)o)->f15 == ((struct Obj01207 *)o)->f14) {
            func_02188DB0((u8 *)(((struct Obj01207 *)o)->f4));
            func_02040588(3, 1);
            func_02187D94(o);
        }
        break;
    case 5:
        break;
    }
    *p = st;
    *(int *)&((struct Obj01207 *)o)->f18 = 0;
}



void func_02187CCC(char *p, int *s)
{
    int st;
    st = func_02187BBC(p, *s);
    if (*s != st) func_02187C20(p, s, st);
}



/*
 * sole setter body stores r1 at [r0 + 0x144], then returns. No code-start
 * witness. No owner source or ARM9/SDK matching performed.
 * 2026-10-04 (wD2 lane 02): witness filed: src/matched/ov/ov021_func_02189A50.c (EXACT, 8 bytes, str r1,[r0,#0x144]).
 * The symbols line already carries ov021. Expected EXACT after the integrator's manifest refresh.
 */
void func_02187CEC(char *p)
{
    void *q;
    q = *(void **)(p + 4);
    if (q != 0) func_02189A50(q, 1);
}



/*
 * sole setter body stores r1 at [r0 + 0x144], then returns. No code-start
 * witness. No owner source or ARM9/SDK matching performed.
 * 2026-10-04 (wD2 lane 02): witness filed: src/matched/ov/ov021_func_02189A50.c (EXACT). Compiled 34 vs listing 36
 * bytes is the trailing pool padding. Expected EXACT* after the integrator's manifest refresh.
 */
void func_02187CFC(char *p)
{
    func_02040588(3, 0);
    if (*(void **)(p + 4) != 0) func_02189A50(*(void **)(p + 4), 0);
    func_02187914(p);
}




u32 func_02187D20(char *p)
{
    return ((struct Obj19482 *)p)->fC;
}




u32 func_02187D24(char *p)
{
    return ((struct Obj19483 *)p)->f10;
}




void func_02187D28(u32 *p)
{
    p[4] = 1;
}




int func_02187D30(char *p)
{
    if (*(u32 *)&((struct Obj01207 *)p)->f1C < ((struct Obj01207 *)p)->f18)
        return 1;
    return 0;
}



int func_02187D40(char *p)
{
    if (func_02187D20(p) == 1) return 30;
    return 10;
}



int func_02187D54(char *p)
{
    if (func_02187D20(p) == 1) return 60;
    if (((struct Obj12551 *)p)->f15 == ((struct Obj12551 *)p)->f14) return 20;
    return 10;
}



int func_02187D74(char *p)
{
    if (func_02187D20(p) == 1) return 120;
    if (((struct Obj12552 *)p)->f15 == ((struct Obj12552 *)p)->f14) return 60;
    return 30;
}
