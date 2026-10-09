/*
 * file:     gimmick_obj_elboard.c
 * unit:     yes
 * function: func_021F3D38, func_021F3D78, func_021F3DA8, func_021F3DF0, func_021F3E2C, func_021F3E6C, func_021F3EE8, func_021F4058, func_021F4104, func_021F4188, func_021F420C, func_021F4290, func_021F4314, func_021F43E4, func_021F440C, func_021F4454, func_021F4488, func_021F44B8, func_021F44D8, func_021F4590, func_021F45F0, func_021F4650, func_021F4698, func_021F472C, func_021F474C, func_021F4784, func_021F47B0, func_021F47B4, func_021F47B8, func_021F47BC, func_021F4948, func_021F4B40, func_021F4B54, func_021F4B7C, func_021F4BF0, func_021F4C10, func_021F4C20, func_021F4DBC, func_021F4DE4, func_021F4DF4, func_021F4E3C
 * address:  0x021F3D38
 * region:   ov048
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F3A50  0x021F3A50  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_0201433C  0x0201433C  thumb
 *   func_021F3A70  0x021F3A70  thumb
 *   func_021F3D24  0x021F3D24  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_02088864  0x02088864  arm
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F230  0x0201F230  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   d_021F50C0     0x021F50C0  data  a4
 *   func_0201EC74  0x0201EC74  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_02013E4C  0x02013E4C  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_020457B0  0x020457B0  arm
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 *   d_021F5124     0x021F5124  data  a4
 *   func_021A9810  0x021A9810  thumb  ov021
 *   func_02012984  0x02012984  thumb
 *   func_021F3AB4  0x021F3AB4  thumb  ov048
 *   func_021F3AD4  0x021F3AD4  thumb  ov048
 *   func_021F3B64  0x021F3B64  thumb  ov048
 *   func_0201EE60  0x0201EE60  thumb
 *   func_02012944  0x02012944  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_021F3C2C 0x021F3C2C thumb ov048
 *   d_021F50C4     0x021F50C4  data  a2
 *   d_021F50EC     0x021F50EC  data  a4
 *   d_021F5108     0x021F5108  data  a4
 *   func_021F3CB0 0x021F3CB0 thumb ov048
 *   d_021F4E84 0x021F4E84 data a4
 *   func_02188C70  0x02188C70  thumb  ov021
 *   d_021F4E5C     0x021F4E5C  data  a2
 *   d_021F4E5E     0x021F4E5E  data  a1
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200D418  0x0200D418  thumb
 *   func_0215E404  0x0215E404  thumb  ov010
 *   func_0215E3E4  0x0215E3E4  thumb  ov010
 *   func_020111E8  0x020111E8  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_020061E4  0x020061E4  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   d_021F523C     0x021F523C  data  a1
 *   func_0201D83C 0x0201D83C thumb
 *   func_020307B0 0x020307B0 arm
 *   func_0209C0A4  0x0209C0A4  arm
 *   func_0204784C  0x0204784C  arm
 *   func_020477A4  0x020477A4  arm
 *   func_020477D4  0x020477D4  arm
 *   func_0201D304  0x0201D304  thumb
 *   func_02047788  0x02047788  arm
 *   func_02047554  0x02047554  arm
 *   func_021875F4  0x021875F4  thumb  ov020
 *   func_02047790  0x02047790  arm
 *   func_02047674  0x02047674  arm
 *   func_02047804  0x02047804  arm
 *   _fflt          0x0209BDBC  arm
 *   _fdiv          0x0209CE10  arm
 *   _fgr           0x0209BBB0  arm
 *   _fmul          0x0209C77C  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   _ll_mul        0x0209C054  arm
 *   func_02187684 0x02187684 thumb ov020
 *   func_0218768C  0x0218768C  thumb  ov020
 *   func_020478B8  0x020478B8  arm
 *   func_02048F74 0x02048F74 arm
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_0218ED2C  0x0218ED2C  thumb  ov021
 *   func_0218ED40  0x0218ED40  thumb  ov021
 *   func_0218ED54  0x0218ED54  thumb  ov021
 *   func_0218ECC4  0x0218ECC4  thumb  ov021
 *   func_021F3790  0x021F3790  thumb  ov048
 *   func_021C6F00  0x021C6F00  thumb  ov021
 *   func_021C7058  0x021C7058  thumb  ov021
 *   func_021C701C  0x021C701C  thumb  ov021
 *   func_021C7AE4  0x021C7AE4  thumb  ov021
 *   func_021C6DE0  0x021C6DE0  thumb  ov021
 *   func_021C6E48  0x021C6E48  thumb  ov021
 *   func_020362DC  0x020362DC  arm
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 */
#include "../../matched/include/Obj00270.h"
#include "../../matched/include/Obj20535.h"
#include "../../matched/include/Obj20536.h"
#include "../../matched/include/Obj20537.h"
#include "../../matched/include/G_T.h"
#include "../../matched/include/Obj02413.h"
#include "../../matched/include/Obj13107.h"
#include "../../matched/include/Obj02414.h"
#include "../../matched/include/Obj02415.h"
#include "../../matched/include/Obj01224.h"
#include "../../matched/include/Obj06156.h"
#include "../../matched/include/Obj09839.h"
#include "../../matched/include/Obj20545.h"
#include "../../matched/include/Obj20546.h"
#include "../../matched/include/Obj20547.h"
#include "../../matched/include/Obj03648.h"
#include "../../matched/include/Obj01678.h"
#include "../../matched/include/Obj05134.h"
#include "../../matched/include/Obj09840.h"

#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? ((x) * (1 << 12) + 0.5f) : ((x) * (1 << 12) - 0.5f)))
#define FX_Mul(a, b) ((fx32)(((s64)(a) * (b) + 0x800LL) >> 12))
struct BigObj;
struct WordSet;
struct RTCDate;
struct MsgBank;
struct Rec;
struct U16Vec;
struct Big;
struct Ctx;
struct GfFont;
struct P;
struct Q;
struct R;
struct AnmCtl;
struct G3dSys;
struct Owner;
struct StrObj;
struct Desc;
struct Obj;
struct W;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

struct Date { int a, b, c, d; };

struct Rec { u16 h; u32 f4, f8, fc, f10, f14, f18; };

struct Tab { u16 pad[2]; u16 h4; };

typedef struct {
    u16 h[4];
    u8  b[4];
} Slots;

struct E {
    u8 b0;
    int f4;
    int f8;
    int fC;
    u32 f10;
    u16 h14;
    int f18;
    int f1C;
    int f20;
};

struct M {
    u16 h0;
    u8 b2;
    int f4;
    struct E **f8;
    int *fC;
    int f10;
    int f14;
    int f18;
};

typedef signed int     s32;

typedef int            fx32;

typedef long long      s64;

typedef struct P {
    u16 h0;
    u16 h2;
    u8 b4;
    u8 b5;
    u8 pad6[10];
    u32 f10;
    u32 f14;
} P;

typedef struct Q {
    u16 h0;
    u16 h2;
    int f4;
    int f8;
    u32 fC;
    u32 f10;
    u32 f14;
    u32 f18;
} Q;

typedef struct R {
    u8 b0;
    int f4;
    int f8;
    int fC;
    u32 f10;
    u16 h14;
    int f18;
    fx32 f1C;
    fx32 f20;
} R;

typedef struct { u16 h0; u16 h2; u16 h4; } Dim;

typedef struct { int f0; int f4; Dim *f8; } Img;

typedef struct { int x; int y; int z; } Vec;

typedef struct W {
    int f0;
    u32 f4;
    u16 h8;
    u16 hA;
    u16 hC;
    u16 hE;
    u32 f10;
    Vec v14;
} W;

extern void func_021F3A50(char *p, int a, int b);
extern u32 func_0201296C(const struct BigObj *p);
extern void func_0201433C(char *a0, int a1);
extern int func_021F3A70(u8 *p);
extern int  func_021F3D24(void *p);
extern struct WordSet *func_0201EC64(u32 heap);
extern int func_02088864(struct RTCDate *date);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F230(struct WordSet *p, u32 i, u32 v);
extern u32 func_0201ED04(struct WordSet *p);
extern struct WordSet *func_0201EC74(u32 n, u32 size, u16 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_02013E4C(u32 id);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(struct Rec *rec);
extern u16 func_021A9810(int a);
extern u8 func_02012984(const struct BigObj *p);
extern int func_021F3AB4(void *p);
extern void func_021F3AD4(const u16 *p, u32 *out, int *cnt);
extern void func_021F3B64(u16 *p, u32 *out, int *cnt);
extern void func_0201EE60(struct WordSet *p, u32 i, u16 v);
extern u8 *func_02012944(void *p);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern u8 *func_021F3C2C(u8 *p);
extern int *func_021F3CB0(int *p);
extern int func_02188C70(int *p, int b);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200D418(void *sys);
extern int func_0215E404(int a);
extern u32 func_020111E8(void);
extern u32 func_0215E3E4(void *p, u32 slot);
extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(const struct Ctx *p);
extern unsigned int func_02159B10(void *a, void *b);
extern void func_020061E4(u32 a);
extern void func_0215897C(void *a, void *b);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern unsigned int func_0201D83C(void *ptr);
extern u32 func_020307B0(void *p);
extern int func_0209C0A4(int a, int b);
extern u32 func_0204784C(struct AnmCtl *c, u16 idx, s32 *frame);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
extern int func_020477D4(struct Owner *owner, u32 index);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern int func_02047788(int *p);
extern int func_02047554(int *p);
extern int func_021875F4(int a0, int a1, int a2, u32 a3, u16 e0, u16 e1, u16 e2);
extern int func_02047790(int *p, int i);
extern Img *func_02047674(u32 a);
extern u32 func_02047804(struct AnmCtl *c, u16 idx);
extern void func_02187684(void *p);
extern void func_0218768C(char *p);
extern int func_020478B8(void *a, int idx, int amount);
extern void func_02048F74(void *dst, u32 archive_id, u32 member, u32 mode, u32 *size_out);
extern void *func_02188C58(void *p);
extern u32 func_02188D38(u8 *p);
extern u16 func_0218ED2C(u8 *p);
extern u16 func_0218ED40(u8 *p);
extern u32 func_0218ED54(u8 *p);
extern void func_0218ECC4(u32 a, void *b);
extern u8 func_021F3790(char *p);
extern u32 func_021C6F00(u32 a, u16 b, u32 c);
extern u32 func_021C7058(u32 a, u16 b, u16 c);
extern u32 func_021C701C(u32 a, u16 b, u16 c);
extern u32 func_021C7AE4(u32 a, u16 b, void *c);
extern void func_021C6DE0(u8 *p, u32 *a, u32 b);
extern int func_021C6E48(u32 a);
extern u32 func_020362DC(void);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
void func_021F3D38(int *p, int a, int b, int *c);
void func_021F3D78(void *p);
void func_021F3DA8(u8 *p);
void func_021F3DF0(u8 *p);
void func_021F3E2C(u8 *p);
void func_021F3E6C(int *p);
void func_021F3EE8(int *p);
void func_021F4058(int *p);
void func_021F4104(int *p);
void func_021F4188(int *p);
void func_021F420C(int *p);
void func_021F4290(int *p);
void func_021F4314(int *p);
void func_021F43E4(int *p);
void func_021F440C(int *p, int *q, int i);
void func_021F4454(int *p);
int func_021F4488(unsigned char *p);
void func_021F44B8(u8 *p);
void func_021F44D8(int *p, Slots *q);
void func_021F4590(int *p, u8 *out);
void func_021F45F0(int *a, void *b);
int func_021F4650(int a, int b);
void *func_021F4698(unsigned char *p);
void func_021F472C(unsigned char *p,const void *q);
void func_021F474C(unsigned char *p);
void func_021F4784(unsigned char *p,int c);
int func_021F47B0(void *p);
int func_021F47B4(void *p);
int func_021F47B8(void *p);
void func_021F47BC(struct M *p, int v);
R *func_021F4948(P *p, const Q *q, int c);
void func_021F4B40(int *p);
void func_021F4B54(int *p);
void func_021F4B7C(int *a, int *b, int c);
void func_021F4BF0(int *p);
int func_021F4C10(int a,int b,int c);
int func_021F4C20(int a0, int *state, W *w);
void *func_021F4DBC(int a, int b, int c);
int func_021F4DE4(int a,int b,int c);
int func_021F4DF4(int *p, int v);
extern struct T d_021F50C0;
extern u32 d_021F5124[];
extern u16 d_021F50C4[];
extern int d_021F50EC[];
extern int d_021F5108[];
extern const int d_021F4E84[];
extern u16 d_021F4E5C[1];
extern u8 d_021F4E5E[3];
extern const char d_021F523C[];


void func_021F3D38(int *p, int a, int b, int *c)
{
    func_021F472C((unsigned char *)p[5], (const void *)a);
    if (b == 8)
        func_021F3A50((char *)p, b, c[1]);
    else
        func_021F3A50((char *)p, b, 0);
    if (b == 8 && c[2] == 1) {
        func_0201433C((char *)func_0201296C((const struct BigObj *)p[2]), (unsigned short)c[1]);
    }
}


void func_021F3D78(void *p)
{
    if (func_021F3A70(p) == 1) {
        func_021F3DF0(p);
        return;
    }
    if (func_021F3D24(p) != 0) {
        func_021F3E2C(p);
        return;
    }
    func_021F3DA8(p);
}


void func_021F3DA8(u8 *p)
{
    if (func_021F47B8((void *)(((struct Obj00270 *)p)->f14)) == 0) {
        u32 q = *(u32 *)&((struct Obj00270 *)p)->f1C;

        if (q != 0 && ((struct Obj20535 *)q)->f78 != 0) {
            func_021F4058((int *)p);
            func_021F3E6C((int *)p);
            func_021F3EE8((int *)p);
            func_021F4104((int *)p);
            func_021F4188((int *)p);
            func_021F420C((int *)p);
            func_021F4290((int *)p);
        }
    }
}


void func_021F3DF0(u8 *p)
{
    if (func_021F47B8((void *)(((struct Obj00270 *)p)->f14)) == 0) {
        u32 q = *(u32 *)&((struct Obj00270 *)p)->f1C;

        if (q != 0 && ((struct Obj20536 *)q)->f78 != 0) {
            func_021F4058((int *)p);
            func_021F3E6C((int *)p);
            func_021F3EE8((int *)p);
            func_021F4314((int *)p);
            func_021F4290((int *)p);
        }
    }
}


void func_021F3E2C(u8 *p)
{
    if (func_021F47B8((void *)(((struct Obj00270 *)p)->f14)) == 0) {
        if (((struct Obj00270 *)p)->f20 != 0) {
            u32 q = *(u32 *)&((struct Obj00270 *)p)->f1C;

            if (q != 0 && ((struct Obj20537 *)q)->f78 != 0) {
                func_021F4058((int *)p);
                func_021F3E6C((int *)p);
                func_021F3EE8((int *)p);
                func_021F43E4((int *)p);
                func_021F4290((int *)p);
            }
        }
    }
}


void func_021F3E6C(int *p)
{
    struct { struct Date d; struct Rec r; } L;
    struct WordSet *w;

    w = func_0201EC64(*(u16 *)p);
    func_02088864((struct RTCDate *)(&L.d));
    func_0201EFA4(w, 2, L.d.a, 2, 2, 1);
    func_0201F230(w, 0, L.d.b);
    func_0201EFA4(w, 1, L.d.c, 2, 0, 1);
    L.r.h = d_021F50C0.h;
    L.r.f4 = d_021F50C0.f2c;
    L.r.f8 = d_021F50C0.f48;
    L.r.fc = 2;
    L.r.f10 = 0x26;
    L.r.f14 = *(u32 *)(*(u32 *)((u32)p + 0x1c) + 0x18);
    L.r.f18 = (u32)w;
    func_021F3D38(p, (int)(&L.r), 1, 0);
    func_0201ED04(w);
}


/*
 * `sz = 4; sz = 0x100;` is the original's str/adds #0xfc/str pair into one
 * spill slot (a dead store survives in a stack-homed local); f declared
 * before h1 puts its slot highest.
 *
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`sz = 4;` before `sz = 0x100;`). Game code has no line table, so these
 * were stand-ins. The plain single assignment gives EXACT in --lang c99 and
 * --lang c: the output bytes do not change. Older text in this header that
 * asks for the double assignment is superseded.
 */
void func_021F3EE8(int *p)
{
    struct { u16 a; int b, c, d, e, f, g; } m;
    Slots s;
    int sz;
    int f;
    void *h1;
    u32 a;
    u32 b;
    int i;
    int c;
    u32 s1;
    u32 s2;
    void *h2;
    u32 s3;
    void *buf;

    func_021F44D8(p, &s);
    sz = 0x100;
    h1 = func_0201EC74(4, sz, ((struct Obj02413 *)p)->f0);
    a = (u32)func_02045B38(0, 2, 0x59, ((struct Obj02413 *)p)->f0);
    b = (u32)func_02045B38(0, 2, 0x26, ((struct Obj02413 *)p)->f0);
    for (i = 0; i < 4; i++) {
        if (s.h[i] == 0x1AB)
            continue;
        c = s.b[i];
        s1 = (u32)func_02045EC0((struct MsgBank *)a, func_02013E4C(s.h[i]));
        s2 = (u32)func_02045EC0((struct MsgBank *)b, d_021F5124[c]);
        h2 = func_0201EC74(2, sz, ((struct Obj02413 *)p)->f0);
        s3 = (u32)func_02045EC0((struct MsgBank *)b, 0xc0);
        buf = func_020457B0(0x40, ((struct Obj02413 *)p)->f0);
        func_0201EE0C(h2, 0, (const void *)s1, 0, 1, 0);
        func_0201EE0C(h2, 1, (const void *)s2, 0, 1, 0);
        func_0201F250(h2, buf, (void *)s3);
        func_02045808((struct U16Vec *)s3);
        func_0201ED04(h2);
        func_0201EE0C(h1, i, (const void *)buf, 0, 1, 0);
        func_02045808((struct U16Vec *)s1);
        func_02045808((struct U16Vec *)s2);
        func_02045808((struct U16Vec *)((u32)buf));
    }
    func_02045C04((struct Rec *)b);
    func_02045C04((struct Rec *)a);
    switch (func_021F4488((unsigned char *)(&s))) {
    case 0:
        break;
    case 1:
        f = 0xc1;
        break;
    case 2:
        f = 0xc2;
        break;
    case 3:
        f = 0xc3;
        break;
    case 4:
        f = 0xc4;
        break;
    }
    m.a = *(u16 *)(((u8 *)&d_021F50C0) + 6);
    m.b = *(int *)(((u8 *)&d_021F50C0) + 0x30);
    m.c = *(int *)(((u8 *)&d_021F50C0) + 0x4c);
    m.d = 2;
    m.e = 0x26;
    m.f = f;
    m.g = (int)h1;
    func_021F3D38(p, (int)&m, 2, 0);
    func_0201ED04(h1);
}


void func_021F4058(int *p)
{
    struct { u16 a; int b, c, d, e, f, g; } s;
    int k;
    void *h;
    u32 r7, r6;

    k = func_021A9810(p[2]);
    if (k == 0xFFFF)
        return;
    if (k == 0x159 && func_02012984((const struct BigObj *)p[2]) == 3)
        return;
    h = func_0201EC64(((struct Obj00270 *)p)->f0);
    r7 = (u32)func_02045B38(0, 2, 0x59, ((struct Obj00270 *)p)->f0);
    r6 = (u32)func_02045EC0((struct MsgBank *)r7, func_02013E4C(k));
    func_0201EE0C(h, 0, (const void *)r6, 0, 1, 0);
    func_02045808((struct U16Vec *)r6);
    func_02045C04((struct Rec *)r7);
    s.a = *(u16 *)(((u8 *)&d_021F50C0) + 8);
    s.b = *(int *)(((u8 *)&d_021F50C0) + 0x34);
    s.c = *(int *)(((u8 *)&d_021F50C0) + 0x50);
    s.d = 2;
    s.e = 0x26;
    s.f = *(int *)(p[7] + 0x20);
    s.g = (int)h;
    func_021F3D38(p, (int)&s, 3, 0);
    func_0201ED04(h);
}


void func_021F4104(int *p)
{
    struct { u16 a; int b, c, d, e, f, g; } s;
    int buf[4];

    func_02088864((struct RTCDate *)buf);
    switch (buf[3]) {
    case 0: s.f = *(int *)(p[7] + 0x3c); break;
    case 1: s.f = *(int *)(p[7] + 0x30); break;
    case 2: s.f = *(int *)(p[7] + 0x24); break;
    case 3: s.f = *(int *)(p[7] + 0x34); break;
    case 4: s.f = *(int *)(p[7] + 0x28); break;
    case 5: s.f = *(int *)(p[7] + 0x38); break;
    case 6: s.f = *(int *)(p[7] + 0x2c); break;
    }
    s.a = *(u16 *)(((u8 *)&d_021F50C0) + 0xa);
    s.b = *(int *)(((u8 *)&d_021F50C0) + 0x38);
    s.c = *(int *)(((u8 *)&d_021F50C0) + 0x54);
    s.d = 2;
    s.e = 0x26;
    s.g = 0;
    func_021F3D38(p, (int)&s, 4, 0);
}


void func_021F4188(int *p)
{
    struct { u16 a; int b, c, d, e, f, g; } s;
    int buf[4];

    func_02088864((struct RTCDate *)buf);
    switch (buf[3]) {
    case 0: s.f = *(int *)(p[7] + 0x40); break;
    case 1: s.f = *(int *)(p[7] + 0x34); break;
    case 2: s.f = *(int *)(p[7] + 0x28); break;
    case 3: s.f = *(int *)(p[7] + 0x38); break;
    case 4: s.f = *(int *)(p[7] + 0x2c); break;
    case 5: s.f = *(int *)(p[7] + 0x3c); break;
    case 6: s.f = *(int *)(p[7] + 0x30); break;
    }
    s.a = *(u16 *)(((u8 *)&d_021F50C0) + 0xc);
    s.b = *(int *)(((u8 *)&d_021F50C0) + 0x3c);
    s.c = *(int *)(((u8 *)&d_021F50C0) + 0x58);
    s.d = 2;
    s.e = 0x26;
    s.g = 0;
    func_021F3D38(p, (int)&s, 5, 0);
}


void func_021F420C(int *p)
{
    struct { u16 a; int b, c, d, e, f, g; } s;
    int buf[4];

    func_02088864((struct RTCDate *)buf);
    switch (buf[3]) {
    case 0: s.f = *(int *)(p[7] + 0x44); break;
    case 1: s.f = *(int *)(p[7] + 0x38); break;
    case 2: s.f = *(int *)(p[7] + 0x2c); break;
    case 3: s.f = *(int *)(p[7] + 0x3c); break;
    case 4: s.f = *(int *)(p[7] + 0x30); break;
    case 5: s.f = *(int *)(p[7] + 0x40); break;
    case 6: s.f = *(int *)(p[7] + 0x34); break;
    }
    s.a = *(u16 *)(((u8 *)&d_021F50C0) + 0xe);
    s.b = *(int *)(((u8 *)&d_021F50C0) + 0x40);
    s.c = *(int *)(((u8 *)&d_021F50C0) + 0x5c);
    s.d = 2;
    s.e = 0x26;
    s.g = 0;
    func_021F3D38(p, (int)&s, 6, 0);
}


void func_021F4290(int *p)
{
    struct { u16 a; int b, c, d, e, f, g; } s;
    int buf[4];

    func_02088864((struct RTCDate *)buf);
    switch (buf[3]) {
    case 0: s.f = *(int *)(p[7] + 0x60); break;
    case 1: s.f = *(int *)(p[7] + 0x48); break;
    case 2: s.f = *(int *)(p[7] + 0x4c); break;
    case 3: s.f = *(int *)(p[7] + 0x50); break;
    case 4: s.f = *(int *)(p[7] + 0x54); break;
    case 5: s.f = *(int *)(p[7] + 0x58); break;
    case 6: s.f = *(int *)(p[7] + 0x5c); break;
    }
    s.a = *(u16 *)(((u8 *)&d_021F50C0) + 0x10);
    s.b = *(int *)(((u8 *)&d_021F50C0) + 0x44);
    s.c = *(int *)(((u8 *)&d_021F50C0) + 0x60);
    s.d = 2;
    s.e = 0x26;
    s.g = 0;
    func_021F3D38(p, (int)&s, 7, 0);
}


void func_021F4314(int *p)
{
    struct { u16 a; int b, c, d, e, f, g; } s;
    u32 buf[6];
    int cnt;
    void *h;
    int i;
    int f;

    h = func_0201EC64(func_021F47B4((void *)p[5]));
    if (func_021F3AB4(p))
        func_021F3AD4((const u16 *)p, buf, &cnt);
    else
        func_021F3B64((u16 *)p, buf, &cnt);
    switch (cnt) {
    case 0: break;
    case 1: f = 0xcd; break;
    case 2: f = 0xce; break;
    case 3: f = 0xcf; break;
    case 4: f = 0xd0; break;
    case 5: f = 0xd1; break;
    case 6: f = 0xd2; break;
    }
    for (i = 0; i < cnt; i++)
        func_0201EE60(h, i, buf[i]);
    func_0201F02C(h, 6, func_02012944((void *)p[2]));
    s.a = *(u16 *)(((u8 *)&d_021F50C0) + 0xa);
    s.b = *(int *)(((u8 *)&d_021F50C0) + 0x38);
    s.c = *(int *)(((u8 *)&d_021F50C0) + 0x54);
    s.d = 2;
    s.e = 0x26;
    s.f = f;
    s.g = (int)h;
    func_021F3D38(p, (int)&s, 9, 0);
    func_0201ED04(h);
}

void func_021F43E4(int *p) { int *q; q=(int *)func_021F3C2C((u8 *)p); switch(q[4]) {case 0:func_021F440C(p,q,3);break;case 2:func_021F4454(p);break;} }


void func_021F440C(int *p, int *q, int i)
{
    struct { u16 a; int b, c, d, e, f, g; } s;

    s.a = d_021F50C4[i];
    s.b = d_021F50EC[i];
    s.c = d_021F5108[i];
    s.d = 2;
    s.e = 0x26;
    s.f = q[3];
    s.g = 0;
    func_021F3D38(p, (int)&s, 8, q);
}

/*
 * lever: Post-increment in the table subscript schedules the counter update before the call.
 */
void func_021F4454(int *p) { int i; int *q; i=0; q=func_021F3CB0(p); while(q && i<4) {func_021F440C(p,q,d_021F4E84[i++]);q=func_021F3CB0(p);} }

int func_021F4488(unsigned char *p) { int i; int n; n=0; for(i=0;i<4;i++) if(((unsigned short *)p)[i]!=0x1ab && p[8+i]!=0xffff) n++; return n; }


/*
 * Unlabelled leaf: fills four halfwords with 0x1AB and four bytes at +8 with 0xFF.
 */
void func_021F44B8(u8 *p)
{
    int i;

    for (i = 0; i < 4; i++) {
        ((u16 *)p)[i] = 0x1AB;
        p[8 + i] = 0xFF;
    }
}


void func_021F44D8(int *p, Slots *q)
{
    Slots s2;
    Slots s1;
    int n, j, k;

    n = 0;
    func_021F44B8((u8 *)q);
    func_021F4590(p, (u8 *)(&s2));
    func_021F45F0(p, &s1);
    for (j = 0; j < 4; j++) {
        if (s1.h[j] == 0x1AB)
            break;
        if (s1.b[j] == 0xFFFF)
            break;
        if (n >= 2)
            break;
        q->h[n] = s1.h[j];
        q->b[n] = s1.b[j];
        n++;
    }
    for (j = 0; j < 4; j++) {
        if (s2.h[j] == 0x1AB)
            break;
        if (s2.b[j] == 0xFFFF)
            break;
        if (n >= 2)
            break;
        q->h[n] = s2.h[j];
        q->b[n] = s2.b[j];
        n++;
    }
    if (n == 0) {
        int *r = (int *)p[7];

        q->h[0] = r[0x64 / 4];
        q->h[1] = r[0x68 / 4];
        q->h[2] = r[0x6c / 4];
        q->h[3] = r[0x70 / 4];
    }
    for (k = 0; k < 4; k++)
        q->b[k] = func_02188C70((int *)p[1], q->h[k]);
}


/*
 * The one-trip outer loop survives only because its int counter is compared
 * against an unsigned (sizeof) bound: `i < 1` or an unsigned counter is
 * folded away as a single pass. Tables: d_021F4E5C = {0x0071} (u16),
 * d_021F4E5E = {6,7,8} (u8). func_02188C70 returns int (its own file); the
 * u8 local is what emits the lsls/lsrs #24.
 */
void func_021F4590(int *p, u8 *out)
{
    int i, j, n;

    func_021F44B8(out);
    n = 0;
    for (i = 0; i < sizeof(d_021F4E5C) / sizeof(d_021F4E5C[0]); i++) {
        u16 v = d_021F4E5C[i];
        u8 r = func_02188C70((int *)p[1], v);

        for (j = 0; j < sizeof(d_021F4E5E); j++) {
            if (r == d_021F4E5E[j]) {
                if (n >= 4)
                    break;
                ((u16 *)out)[n] = v;
                out[8 + n] = r;
                n++;
            }
        }
    }
}


void func_021F45F0(int *a, void *b)
{
    int r7;
    int r4;
    int r6;
    int r0;

    r7 = (int)func_0200D418(func_02012EBC((struct Big *)a[2]));
    func_021F44B8(b);
    if (func_0215E404(r7)) {
        r0 = func_020111E8();
        switch (r0) {
        case 0x14:
            r4 = 0;
            break;
        case 0x15:
            r4 = 1;
            break;
        }
        switch (r4) {
        case 0:
            r6 = 6;
            break;
        case 1:
            r6 = 7;
            break;
        }
        r0 = (int)func_0215E3E4((void *)r7, (unsigned char)r4);
        if (r0 != 0xFFFF) {
            ((struct Obj13107 *)b)->f0 = r0;
            *((unsigned char *)b + 8) = r6;
        }
    }
}


int func_021F4650(int a, int b)
{
    void *r6;
    void *r7;
    void *sp;
    int r4;

    r6 = func_0215A5F4((void *)b);
    r7 = func_0215A5DC((void *)b);
    sp = func_0201210C((void *)r7);
    r4 = (int)func_02159B10((void *)a, (void *)b);
    func_020061E4(0x547);
    func_0215897C(r6, func_021F4DBC((int)r7, (int)sp, r4));
    return 1;
}


void *func_021F4698(unsigned char *p)
{
    int i;
    unsigned char *r5;

    r5 = func_02030734(((struct Obj02414 *)p)->f0, 0x1c, 0, d_021F523C, 0x60);
    i = 0;
    ((struct Obj02415 *)r5)->f0 = ((struct Obj02414 *)p)->f0;
    r5[2] = i;
    r5[3] = p[2];
    r5[4] = p[3];
    r5[5] = p[4];
    ((struct Obj02415 *)r5)->f10 = ((struct Obj02414 *)p)->f8;
    ((struct Obj02415 *)r5)->f18 = i;
    ((struct Obj02415 *)r5)->f8 = (int)func_02030734(((struct Obj02414 *)p)->f0, p[2] * 4, 0, d_021F523C, 0x6d);
    ((struct Obj02415 *)r5)->fC = (int)func_02030734(((struct Obj02414 *)p)->f0, p[2] * 4, 0, d_021F523C, 0x6f);
    for (i = 0; i < p[2]; i++) {
        (*(int **)(r5 + 8))[i] = 0;
        (*(int **)(r5 + 0xc))[i] = 0;
    }
    (*(int **)(r5 + 0xc))[0] = 1;
    ((struct Obj02415 *)r5)->f14 = (int)func_0201D7EC(0x17, 0, 0, 0, ((struct Obj02415 *)r5)->f0);
    return r5;
}

void func_021F472C(unsigned char *p,const void *q) { if(p[3]>p[2]) { ((void **)((struct Obj01224 *)p)->f8)[p[2]]=func_021F4948((struct P *)p,q,p[2]); p[2]++; } }

void func_021F474C(unsigned char *p) { int i; func_0201D83C((void *)(((struct Obj06156 *)p)->f14)); for(i=0;i<p[2];i++) func_021F4B40(((int **)((struct Obj06156 *)p)->f8)[i]); func_020307B0(((struct Obj06156 *)p)->f8); func_020307B0(((struct Obj06156 *)p)->fC); func_020307B0(p); }

void func_021F4784(unsigned char *p,int c) { int i; for(i=0;i<p[2];i++) func_021F4B7C((int *)p,((int **)((struct Obj09839 *)p)->f8)[i],c); ((struct Obj09839 *)p)->f18+=c; }


/*
 * int getter, u16 getter, u8 getter.
 */
int func_021F47B0(void *p)
{
    return ((struct Obj20545 *)p)->f18;
}


int func_021F47B4(void *p)
{
    return ((struct Obj20546 *)p)->f0;
}


int func_021F47B8(void *p)
{
    return ((struct Obj20547 *)p)->f2;
}


void func_021F47BC(struct M *p, int v)
{
    int *a;
    int *b;
    int i, sum, q, j, t;
    struct E *e;

    q = v >> 12;
    sum = 0;
    a = (int *)func_02030734((u16)((p->h0 & 0x7FFF) | 0x8000), p->b2 * 4, 0, d_021F523C, 0x11A);
    b = (int *)func_02030734((u16)((p->h0 & 0x7FFF) | 0x8000), p->b2 * 4, 0, d_021F523C, 0x11C);
    p->f18 = v;
    for (i = 0; i < p->b2; i++) {
        p->fC[i] = 0;
        sum += p->f8[i]->f1C >> 12;
        if (i == 0) {
            a[i] = 0;
        } else {
            a[i] = a[i - 1] + (p->f8[i - 1]->f1C >> 12);
        }
    }
    for (i = 0; i < p->b2; i++) {
        e = p->f8[i];
        b[i] = q % sum - a[i];
        t = 0;
        if (b[i] > 0 && b[i] < (e->f20 >> 12)) {
            t = 1;
        }
        e->f4 = t;
        t = 0;
        if ((e->f1C >> 12) < b[i] && b[i] < (e->f20 >> 12)) {
            t = 1;
        }
        e->f8 = t;
        if (b[i] < 0) {
            b[i] = 0;
        }
        e->f18 = b[i] << 12;
        func_0204784C((struct AnmCtl *)e->f10, e->h14, &e->f18);
        if (e->f4) {
            func_020477A4((struct G3dSys *)e->f10, e->h14);
        } else {
            func_020477D4((struct Owner *)e->f10, e->h14);
        }
    }
    if (p->b2 != 0 && q == 0) {
        e = p->f8[0];
        e->f4 = 1;
        func_020477A4((struct G3dSys *)e->f10, e->h14);
    }
    for (i = 0; i < p->b2; i++) {
        j = (i + 1) % p->b2;
        t = 0;
        if (p->f8[i]->f8 != 0 && p->f8[j]->f4 == 0) {
            t = 1;
        }
        p->fC[j] = t;
    }
    func_020307B0(a);
    func_020307B0(b);
}


R *func_021F4948(P *p, const Q *q, int c)
{
    R *r;
    u32 arc;
    u32 str;
    u32 tmp;
    int width;
    int tot;
    int m;
    int a;
    int x;
    fx32 w;

    r = func_02030734(p->h0, 0x24, 0, d_021F523C, 0x180);
    arc = (u32)func_02045B38(0, (u16)q->fC, (u16)q->f10, p->h0);
    if (q->f18 != 0) {
        str = (u32)func_020457B0(0xC0, p->h0);
        tmp = (u32)func_02045EC0((struct MsgBank *)arc, q->f14);
        func_0201F250((struct WordSet *)q->f18, (void *)str, (void *)tmp);
        func_020307B0((void *)tmp);
    } else {
        str = (u32)func_02045EC0((struct MsgBank *)arc, q->f14);
    }
    width = func_0201D304((struct StrObj *)str, p->f14, 1);
    r->fC = func_021875F4(func_02047554((int *)func_02047788((int *)p->f10)), q->f4, q->f8, str, p->b4 * 14, 1, p->h0);
    func_020307B0((void *)str);
    func_02045C04((struct Rec *)arc);
    w = func_02047674(func_02047790((int *)p->f10, q->h0))->f8->h4 << 12;
    m = p->b4 * 13;
    tot = m + width;
    a = tot - m;
    x = a + p->b5 * 13;
    r->f18 = 0;
    r->f1C = FX_F32_TO_FX32((float)x / 1024.0f);
    r->f1C = FX_Mul(r->f1C, w);
    r->f20 = FX_F32_TO_FX32((float)tot / 1024.0f);
    r->f20 = FX_Mul(r->f20, w);
    r->b0 = c;
    r->f4 = 0;
    r->f8 = 0;
    r->f10 = p->f10;
    r->h14 = q->h0;
    func_020477D4((struct Owner *)r->f10, r->h14);
    func_02047804((struct AnmCtl *)r->f10, r->h14);
    return r;
}

void func_021F4B40(int *p) { func_02187684((void *)p[3]); func_020307B0(p); }

void func_021F4B54(int *p) { if(p[1]!=1) { p[1]=1; p[2]=0; p[6]=0; func_020477A4((void *)p[4],((struct Obj03648 *)p)->f14); func_02047804((struct AnmCtl *)p[4],((struct Obj03648 *)p)->f14); } }


void func_021F4B7C(int *a, int *b, int c)
{
    int t;

    if (b[1] == 1) {
        func_0218768C((char *)b[3]);
        func_020478B8((void *)b[4], *(unsigned short *)&b[5], c);
        t = b[6] + c;
        b[6] = t;
        if (b[7] < t) {
            if (b[2] != 1) {
                ((int *)a[3])[(((struct Obj01678 *)b)->f0 + 1) % *((unsigned char *)a + 2)] = 1;
                b[2] = 1;
            }
        }
        if (b[8] < b[6]) {
            func_021F4BF0(b);
            return;
        }
    } else {
        if (((int *)a[3])[((struct Obj01678 *)b)->f0] == 1) {
            func_021F4B54(b);
            ((int *)a[3])[((struct Obj01678 *)b)->f0] = 0;
        }
    }
}

void func_021F4BF0(int *p) { if(p[1]==1) { p[1]=0; func_020477D4((struct Owner *)p[4],((struct Obj05134 *)p)->f14); func_02047804((struct AnmCtl *)p[4],((struct Obj05134 *)p)->f14); } }

int func_021F4C10(int a,int b,int c) { func_02048F74((void *)a,b,c,0,(u32 *)0x7c); return 1; }


int func_021F4C20(int a0, int *state, W *w)
{
    u32 cam;
    u32 obj;
    u32 h;
    u32 v;

    cam = w->f4;
    obj = (u32)func_02188C58((void *)cam);
    h = func_02188D38((u8 *)cam);
    switch (*state) {
    case 0:
        w->hA = func_0218ED2C((u8 *)obj);
        w->hC = func_0218ED40((u8 *)obj);
        w->f10 = func_0218ED54((u8 *)obj);
        func_0218ECC4(obj, &w->v14);
        (*state)++;
        break;
    case 1: {
        Vec vec;
        int ang1;
        int ang2;
        u32 dist;
        u32 r0;
        u32 r1;
        u32 r2;
        u32 r3;

        switch (func_021F3790((char *)cam)) {
        case 1:
        default:
            ang1 = 0xEE5;
            dist = 0x86000;
            ang2 = 0;
            vec.x = 0;
            vec.y = 0x1B000;
            vec.z = -0x6C000;
            break;
        case 3:
            ang1 = 0xEE5;
            dist = 0x86000;
            ang2 = 0x3FFF;
            vec.x = -0x6C000;
            vec.y = 0x1B000;
            vec.z = 0;
            break;
        }
        r0 = func_021C6F00(cam, w->h8, dist);
        r1 = func_021C7058(cam, w->h8, ang1);
        r2 = func_021C701C(cam, w->h8, ang2);
        r3 = func_021C7AE4(cam, w->h8, &vec);
        func_021C6DE0((u8 *)h, (u32 *)r0, 0);
        func_021C6DE0((u8 *)h, (u32 *)r1, 0);
        func_021C6DE0((u8 *)h, (u32 *)r2, 0);
        func_021C6DE0((u8 *)h, (u32 *)r3, 0);
        (*state)++;
        break;
    }
    case 2:
        if (func_021C6E48(h))
            (*state)++;
        break;
    case 3:
        v = func_020362DC();
        if ((v & 0x20) || (v & 0x10) || (v & 0x80) || (v & 2))
            (*state)++;
        break;
    case 4: {
        u32 r0;
        u32 r1;
        u32 r2;
        u32 r3;

        r0 = func_021C6F00(cam, w->h8, w->f10);
        r1 = func_021C7058(cam, w->h8, w->hA);
        r2 = func_021C701C(cam, w->h8, w->hC);
        r3 = func_021C7AE4(cam, w->h8, &w->v14);
        func_021C6DE0((u8 *)h, (u32 *)r0, 0);
        func_021C6DE0((u8 *)h, (u32 *)r1, 0);
        func_021C6DE0((u8 *)h, (u32 *)r2, 0);
        func_021C6DE0((u8 *)h, (u32 *)r3, 0);
        (*state)++;
        break;
    }
    case 5:
        if (func_021C6E48(h))
            (*state)++;
        break;
    case 6:
        return 1;
    }
    return 0;
}

void *func_021F4DBC(int a, int b, int c) { void *d; unsigned char *p; d=func_020122C0((void *)a,0,(void *)func_021F4C20,0x20); p=func_020124E8(d); ((struct Obj09840 *)p)->f0=a; ((struct Obj09840 *)p)->f4=b; ((struct Obj09840 *)p)->f8=c; return d; }

int func_021F4DE4(int a,int b,int c) { func_02048F74((void *)a,b,c,0,(u32 *)0x24); return 1; }

/*
 * Sentinel-0x1ab test on four consecutive words; then a value match.
 */
int func_021F4DF4(int *p, int v)
{
    if (p[5] == 0x1ab && p[6] == 0x1ab && p[7] == 0x1ab && p[8] == 0x1ab)
        return 1;
    if (p[5] == v || p[6] == v || p[7] == v || p[8] == v)
        return 1;
    return 0;
}

extern u32 func_020111E8(void);

int func_021F4E3C(int *p)
{
    if (p[0] == 0)
        return 1;
    if (p[0] == func_020111E8())
        return 1;
    return 0;
}

