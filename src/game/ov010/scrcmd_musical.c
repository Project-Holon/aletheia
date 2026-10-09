/*
 * file:     scrcmd_musical.c
 * unit:     yes
 * function: func_0215D34C, func_0215D468, func_0215D504, func_0215D7D4, func_0215D864, func_0215D884, func_0215DADC, func_0215DB00, func_0215DB38, func_0215DDC8, func_0215DE0C, func_0215DE38, func_0215DE44, func_0215DE58, func_0215DEF0, func_0215DF6C, func_0215DF78, func_0215DFB4, func_0215E010, func_0215E068, func_0215E0B0, func_0215E0EC, func_0215E130, func_0215E184, func_0215E1C0, func_0215E2B8, func_0215E31C, func_0215E334, func_0215E33C, func_0215E34C, func_0215E358, func_0215E364, func_0215E3A0, func_0215E3E4, func_0215E404, func_0215E428, func_0215E440, func_0215E580, func_0215E5B0, func_0215E6A8, func_0215E6F8, func_0215E724, func_0215E740, func_0215E7DC, func_0215E804, func_0215E840, func_0215EA14, func_0215EA30, func_0215EA38, func_0215EA58, func_0215EA6C, func_0215EA94, func_0215EAC8, func_0215EAF0, func_0215EB18, func_0215EB4C, func_0215EB60, func_0215EB88, func_0215EBBC, func_0215EBD0, func_0215EBF8, func_0215EC2C
 * address:  0x0215D34C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02012F80  0x02012F80  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_02155A98  0x02155A98  thumb  ov010
 *   func_0215898C  0x0215898C  thumb  ov010
 *   func_02012A30  0x02012A30  thumb
 *   func_02011290  0x02011290  thumb
 *   func_02012F44  0x02012F44  thumb
 *   func_02030734  0x02030734  arm
 *   func_0200A640  0x0200A640  thumb
 *   func_02014808  0x02014808  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 *   ov112_id       0x00000070  data
 *   d_02172914     0x02172914  data
 *   d_021F8360     0x021F8360  data
 *   func_02012934  0x02012934  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_021F675C  0x021F675C  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_021568E0  0x021568E0  thumb  ov010
 *   func_02156954  0x02156954  thumb  ov010
 *   func_02156978  0x02156978  thumb  ov010
 *   func_02156934  0x02156934  thumb  ov010
 *   func_021568E8  0x021568E8  thumb  ov010
 *   func_02156908  0x02156908  thumb  ov010
 *   func_0215699C  0x0215699C  thumb  ov010
 *   func_021569A4  0x021569A4  thumb  ov010
 *   func_021569EC  0x021569EC  thumb  ov010
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0200A628  0x0200A628  thumb
 *   func_0200A644  0x0200A644  thumb
 *   func_0200A75C  0x0200A75C  thumb
 *   func_0200A780  0x0200A780  thumb
 *   func_0200A7A0  0x0200A7A0  thumb
 *   func_0200A7B8  0x0200A7B8  thumb
 *   func_0200A7C8  0x0200A7C8  thumb
 *   func_0200A7D4  0x0200A7D4  thumb
 *   func_0200A7E0  0x0200A7E0  thumb
 *   func_021F6744  0x021F6744  thumb  ov112
 *   func_0200A750  0x0200A750  thumb
 *   func_0200A6BC   0x0200A6BC  thumb
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_02156914  0x02156914  thumb  ov010
 *   func_02156A3C  0x02156A3C  thumb  ov010
 *   func_02156AD4  0x02156AD4  thumb  ov010
 *   func_0200A7F8  0x0200A7F8  thumb
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045994  0x02045994  arm
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 *   func_0215A168 0x0215A168 thumb ov010
 *   func_02156BAC  0x02156BAC  thumb  ov010
 *   func_02156BCC  0x02156BCC  thumb  ov010
 *   func_02012124  0x02012124  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02012944  0x02012944  thumb
 *   func_020113D0  0x020113D0  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_021CD48C  0x021CD48C  thumb  ov021
 *   func_021FCDEC  0x021FCDEC  thumb  ov132
 *   func_021FDA6C  0x021FDA6C  thumb  ov132
 *   d_021BB6A4     0x021BB6A4  data  ov100
 *   ov100_id       0x00000064  data
 *   func_02012F74  0x02012F74  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   ov132_id       0x00000084  data
 *   func_020307B0  0x020307B0  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_021FC644  0x021FC644  thumb  ov132
 *   func_021FC684  0x021FC684  thumb
 *   func_020124E4 0x020124E4 thumb
 *   func_020120F4 0x020120F4 thumb
 *   func_02012374 0x02012374 thumb
 *   func_02026454 0x02026454 thumb
 *   func_0203CDBC 0x0203CDBC arm
 *   func_020121CC 0x020121CC thumb
 *   func_020120B4  0x020120B4  thumb
 *   func_020120F0  0x020120F0  thumb
 *   d_02172724     0x02172724  data
 *   func_021FC81C  0x021FC81C  thumb
 *   func_021CD688  0x021CD688  thumb
 *   func_021FC804  0x021FC804  thumb
 *   func_021CD5A4  0x021CD5A4  thumb
 *   func_021FCE00  0x021FCE00  thumb
 *   func_021FD844  0x021FD844  thumb
 *   func_02026474  0x02026474  thumb
 *   func_021FD910  0x021FD910  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02009448  0x02009448  thumb
 *   func_02009370  0x02009370  thumb
 *   func_021B76F8  0x021B76F8  thumb  ov021
 *   func_021B7794  0x021B7794  thumb  ov021
 *   func_021B76B4  0x021B76B4  thumb  ov021
 *   func_021B7740  0x021B7740  thumb  ov021
 *   func_0201EF5C  0x0201EF5C  thumb
 *   func_02013EC0  0x02013EC0  thumb
 *   func_020493D4  0x020493D4  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   func_0204944C  0x0204944C  arm
 *   d_02172928 0x02172928 data a1
 *   func_02188CE8  0x02188CE8  thumb
 *   func_021AA7DC  0x021AA7DC  thumb
 *   func_02012A38  0x02012A38  thumb
 *   func_0200D418 0x0200D418 thumb
 *   func_02012984 0x02012984 thumb
 *   func_0200D488 0x0200D488 thumb
 *   func_0200D4AC  0x0200D4AC  thumb
 *   func_0200D478 0x0200D478 thumb
 *   d_021711C6 0x021711C6 data a2
 *   func_0200D45C  0x0200D45C  thumb
 *   func_0200D50C  0x0200D50C  thumb
 *   func_020173EC  0x020173EC  thumb
 *   func_02008530  0x02008530  thumb
 *   func_02017588  0x02017588  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0200CA10  0x0200CA10  thumb
 *   func_0200CFA0  0x0200CFA0  thumb
 *   func_0200D470  0x0200D470  thumb
 *   d_0217293C     0x0217293C  data
 *   func_0200D468 0x0200D468 thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_0201313C  0x0201313C  thumb
 *   func_02005728  0x02005728  thumb
 *   func_0200D494  0x0200D494  thumb
 *   func_0200D480  0x0200D480  thumb
 *   func_020113D8 0x020113D8 thumb
 *   d_021711A8 0x021711A8 data ov010 a2
 *   func_0200D4B8  0x0200D4B8  thumb
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_021A3098  0x021A3098  thumb  ov021
 *   func_021A3250  0x021A3250  thumb  ov021
 *   func_021A3050  0x021A3050  thumb  ov021
 *   func_021A30C8  0x021A30C8  thumb  ov021
 *   func_021A3128  0x021A3128  thumb  ov021
 *   func_021A3504  0x021A3504  thumb  ov021
 *   func_021A3524  0x021A3524  thumb  ov021
 *   func_021A35FC  0x021A35FC  thumb  ov021
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216E5FC  0x0216E5FC  thumb  ov010
 *   func_0216E5B0  0x0216E5B0  thumb  ov010
 *   func_0215F118  0x0215F118  thumb  ov010
 *   func_02013C40  0x02013C40  thumb
 *   func_02013C50  0x02013C50  thumb
 *   func_02012B38  0x02012B38  thumb
 *   func_02014470  0x02014470  thumb
 *   func_021CD440  0x021CD440  thumb
 *   func_02013FFC  0x02013FFC  thumb
 *   func_0201400C  0x0201400C  thumb
 *   func_02014018  0x02014018  thumb
 *   func_02013E04  0x02013E04  thumb
 *   func_02012B70  0x02012B70  thumb
 *   d_021711EC     0x021711EC  data
 *   d_021711F4     0x021711F4  data
 *   func_0215F088  0x0215F088  thumb  ov010
 *   func_0215F0B8  0x0215F0B8  thumb  ov010
 *   func_0215F104  0x0215F104  thumb  ov010
 *   func_0215F0E8 0x0215F0E8 thumb ov010
 *   func_0201296C 0x0201296C thumb
 *   func_021587B0 0x021587B0 thumb ov010
 *   func_02159058 0x02159058 thumb ov010
 *   func_021C6078 0x021C6078 thumb ov021
 */
#include "../../matched/include/Obj12042.h"
#include "../../matched/include/Obj00005.h"
#include "../../matched/include/Obj09156.h"
#include "../../matched/include/Obj02658.h"
#include "../../matched/include/Obj17696.h"
#include "../../matched/include/Obj17697.h"
#include "../../matched/include/Obj02057.h"
#include "../../matched/include/Obj12311.h"
#include "../../matched/include/Obj17698.h"
#include "../../matched/include/Obj12312.h"
#include "../../matched/include/Obj12313.h"
#include "../../matched/include/Obj12314.h"
#include "../../matched/include/Obj12315.h"

struct BigObj;
struct Desc;
struct Obj;
struct ScriptVm;
struct Link;
struct Ctx_0215D468;
struct Big;
struct Work;
struct BigSub4;
struct MsgBank;
struct Rec_0215D7D4;
struct U16Vec;
struct WordSet;
struct Strbuf;
struct Ctx;
struct IcaAnime;
struct Evt;
struct Sub02009448Obj;
struct Sub02009210Obj;
struct ArcFile;
struct Blk38;
struct GdsEnt;
struct Blk37;
struct Mon;
struct Sub0200852CObj;
struct Rec44;
struct SaveBlock;
struct Actor;
struct Sub02014444Obj;
struct Obj00020;
struct Pair;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Ctx {
    u8 pad00[0x14];
    u8 *pc;             /* 0x14 */
} Ctx;

typedef struct Starter {
    void *seq;          /* 0x00 */
    void *link;         /* 0x04 */
    u32 mode;           /* 0x08 */
} Starter;

typedef struct Args {
    u32 f00;            /* 0x00 */
    u32 f04;            /* 0x04 */
    void *f08;          /* 0x08 */
} Args;

typedef struct Box {
    Args *args;         /* 0x00 */
} Box;

typedef u32 (*TaskFn)(void *task, u32 *state, void *work);

typedef struct { u32 f0; u32 f4; u32 f8; } S;

typedef struct { S *p; } Ctx_0215D468;

typedef struct Ctx_0215D504 {
    u8 pad00[0x14];
    u8 *pc;             /* 0x14 */
} Ctx_0215D504;

typedef struct Rec_0215D468 {
    u8 kind;
    u8 pad01[5];
} Rec_0215D468;

typedef struct Flags {
    u32 pad0 : 16;
    u32 n : 5;
    u32 pad1 : 11;
} Flags;

typedef struct {
    u8 pad[0x14];
    u8 *f14;
} Cur;

typedef struct {
    u8 b0;
    u8 b1;
    u16 h2;
} Rec_0215D7D4;

typedef struct Link {
    void *f00;          /* 0x00 */
    void *sess;         /* 0x04 */
    u32 f08;            /* 0x08 */
    void *f0c;          /* 0x0C */
    u8 pad10[0x28 - 0x10];
    u32 f28;            /* 0x28 */
    u32 f2c;            /* 0x2C */
    u16 *f30;           /* 0x30 */
    u16 f34;            /* 0x34 */
} Link;

typedef struct Wait {
    void *vm;
    Link *link;
} Wait;

typedef signed char s8;

typedef short s16;

typedef struct Work {
    int f00;            /* 0x00 */
    int f04;            /* 0x04 */
    u8 pad08[0x8C - 0x08];
    int f8c;            /* 0x8C */
} Work;

typedef signed int     s32_0215D34C;

typedef struct { u32 f0; u32 f4; u32 f8; } Ctx_0215DE58;

typedef struct { u32 f0; } Ctx_0215DEF0;

struct W {
    u8 pad00[4];
    void *f4;
    void *f8;
    u8 pad0c[0x24];
    u16 *f30;
};

struct R {
    u8 pad00[7];
    u8 f7;
};

typedef unsigned long long u64;

struct Ent { u16 n; u8 v[4]; };

typedef int s32_0215E364;

typedef s32_0215E364 fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct Area {
    u16 x;
    u16 z;
    u16 w;
    u16 h;
} Area;

typedef struct Info {
    u16 id;             /* 0x00 */
    u16 flags;          /* 0x02 */
    u32 f04;            /* 0x04 */
    u32 f08;            /* 0x08 */
    void *obj;          /* 0x0C */
    void *field;        /* 0x10 */
} Info;

typedef struct Query {
    u16 a;              /* 0x00 */
    u16 b;              /* 0x02 */
    u32 c;              /* 0x04 */
} Query;

typedef enum { B_FALSE, B_TRUE } Bool;

extern void *func_0215A5F4(void *vm);
extern void *func_0215A5DC(void *vm);
extern void *func_0215A5E4(void *vm);
extern void *func_0201210C(const struct Ctx *);
extern int func_02158F58(int a0);
extern u16 func_02159B10(void *, void *);
extern int func_02012F80(char *base);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void *func_02155A98(void *a, void *b, u8 c, u32 d, struct Link *link);
extern void func_0215898C(void *a, void *task);
extern u32 func_02012A30(const struct BigObj *p);
extern struct ScriptVm *func_02011290(struct ScriptVm *vm);
extern void *func_02012F44(void *sys);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
extern Flags *func_0200A640(void *sv);
extern void *func_02014808(char *a0, int a1, int a2, int a3, int a4, int a5, int a6);
extern void func_0215897C(void *a, void *task);
extern void *func_02012934(const struct BigObj *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_021F675C(void *, int);
extern void func_02082BCC(void *, int, int);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u8 func_021568E0(struct Work *w);
extern u16 func_02156954(struct Work *w);
extern u16 func_02156978(struct Work *w);
extern u8 func_02156934(struct Work *w, u8 idx);
extern int func_021568E8(int a0, u8 a1);
extern u8 func_02156908(struct Work *w);
extern u8 func_0215699C(struct Work *w, u8 i);
extern u8 func_021569A4(struct Work *w, u8 idx);
extern u8 func_021569EC(struct Work *w, u8 j);
extern u32 func_0201AA18(void *list);
extern u8 *func_0200A628(struct Big *p);
extern u32 func_0200A644(struct Big *p, u8 index);
extern u16 func_0200A75C(struct Big *p);
extern u16 func_0200A780(struct Big *p);
extern u8 func_0200A7A0(struct Big *p, u32 index);
extern u8 func_0200A7B8(struct Big *p);
extern u8 func_0200A7C8(struct Big *p);
extern void func_0200A7D4(struct Big *p, u8 value);
extern u8 func_0200A7E0(struct Big *p);
extern int func_021F6744(void *p);
extern struct BigSub4 *func_0200A750(struct Big *p, u32 index);
extern void func_0200A6BC(struct Big *p, u32 index);
extern u16 func_0215A5CC(void *a0);
extern void *func_02158F74(void *p);
extern void *func_02156914(int a0, int a1);
extern void func_02156A3C(struct Work *w, u8 j, void *ws, u32 slot);
extern void func_02156AD4(struct Work *w, u8 j, void *ws, u32 slot);
extern u8 *func_0200A7F8(struct Big *p);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045994(struct Strbuf *dest, const u16 *src, u32 size);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(struct Rec_0215D7D4 *rec);
extern void *func_0215A168(int a, int b, int c);
extern int func_02156BAC(void *);
extern u32 func_02156BCC(void *p);
extern void func_02012124(struct Ctx *p, u32 v);
extern u32 func_02012138(const struct Ctx *p);
extern u8 *func_02012944(void *p);
extern void func_020113D0(char *p, int val);
extern u32 func_0200FB24(void);
extern u32 func_021CD48C(void *a, void *sys, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_021FCDEC(int a, int b);
extern unsigned char *func_021FDA6C(void *h);
extern void func_02012F74(void *h, void *w);
extern int func_02034AC4(s32_0215D34C handle);
extern u32 func_020307B0(void *p);
extern void func_02034A5C(s32_0215D34C handle);
extern void func_021FC644(int a, void *b, void *c, int d);
extern int func_021FC684(int a0);
extern void *func_020124E4(struct Obj *p);
extern void *func_020120F4(const struct Ctx *);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern u32 func_02026454(void *obj);
extern int func_0203CDBC(void);
extern u32 func_020121CC(struct IcaAnime *p);
extern void func_020120B4(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 func_020120F0(const struct Ctx_0215DEF0 *p);
extern int func_021FC81C();
extern int func_021CD688();
extern int func_021FC804();
extern int func_021CD5A4();
extern int func_021FCE00();
extern int func_021FD844();
extern u32 func_02026474(void *obj);
extern int func_021FD910();
extern void *func_02012EBC(struct Big *p);
extern struct Sub02009448Obj *func_02009448(void *sys);
extern u32 func_02009370(const struct Sub02009210Obj *obj);
extern int func_021B76F8(void *p, int key, void *q);
extern void *func_021B7794(void *p);
extern void func_021B76B4(void *a0, int a1, int a2);
extern void *func_021B7740(void *p, int key, void *q, int idx);
extern void func_0201EF5C(struct WordSet *p, u32 i, u32 v);
extern u32 func_02013EC0(u32 id);
extern u32 func_020493D4(struct ArcFile *arc, u32 member);
extern void func_0204944C(struct ArcFile *a, u32 b, u32 c, u32 d, void *e);
extern int func_02188CE8();
extern int func_021AA7DC();
extern u32 func_02012A38(const struct BigObj *p);
extern void *func_0200D418(void *);
extern u8 func_02012984(const struct BigObj *p);
extern u8 func_0200D488(struct Blk38 *p, u32 i);
extern struct GdsEnt *func_0200D4AC(struct Blk38 *p, u32 i);
extern u8 func_0200D478(struct Blk38 *p, u32 i);
extern int func_0200D45C();
extern void func_0200D50C(struct GdsEnt *e, u32 i, u32 v);
extern u32 func_020173EC(void);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void func_02017588(struct Mon *p, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void *func_0200CA10(void *save);
extern void func_0200CFA0(struct Blk37 *p, void *m);
extern void func_0200D470(struct Blk38 *p, u32 i, u32 v);
extern u8 func_0200D468(struct Blk38 *p, u32 i);
extern void *func_020127A4(struct SaveBlock *p);
extern u16 func_02012AC8(const struct Rec44 *p);
extern void *func_0201313C(void *p, int v);
extern u32 func_02005728(u32 v);
extern void func_0200D494(struct GdsEnt *e);
extern void func_0200D480(struct Blk38 *p, u32 i, u8 v);
extern u32 func_020113D8(u32 b);
extern u32 func_0200D4B8(const struct GdsEnt *e, u32 i);
extern u16 func_02188C9C(u8 *p);
extern void *func_02188C80(void *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_02188C7C(u8 *p);
extern u32 func_021A3098(u8 *p);
extern void *func_021A3250(void *q);
extern u16 func_021A3050(u8 *p);
extern u32 func_021A30C8(void **ctx);
extern u32 func_021A3128(u32 *a, u32 b);
extern int func_021A3504(u8 *a, int b, int c);
extern int func_021A3524(u8 *a, int b, int c);
extern void func_021A35FC(unsigned char **p, u16 *a, u16 *b, u16 *c);
extern u16 func_0216D598(void *obj);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
extern int func_0216E5FC(u16 kind);
extern int func_0216E5B0(void *map, const VecFx32 *pos);
extern int func_0215F118(const Area *a, u16 x, u16 z, u32 flag, void *field);
extern u32 func_02013C40(u32 id);
extern u32 func_02013C50(u32 id);
extern void *func_02012B38(const struct BigObj *p);
extern u16 func_02014470(struct Sub02014444Obj *o);
extern int func_021CD440(void *field, u16 *out);
extern u32 func_02013FFC(u32 id);
extern u32 func_0201400C(u32 id);
extern u32 func_02014018(u32 id);
extern u32 func_02013E04(u32 id);
extern int func_02012B70(const struct BigObj *p);
extern int func_0215F088(u16 *p, int i);
extern int func_0215F0B8(u16 *p, int i);
extern int func_0215F104(int a0, int a1);
extern void func_0215F0E8(u32 *out, const struct Pair *in, u32 *ctx);
extern u32 func_0201296C(const struct BigObj *p);
extern int func_021587B0(int a0, int a1, int a2, int a3);
extern int func_02159058(int a, int b, int c, int d, u16 e);
extern void *func_021C6078(void *, void *, u8);
int func_0215D34C(Ctx *c, void *vm);
int func_0215D468(void *a, void *b);
int func_0215D504(Ctx_0215D504 *c, void *vm);
int func_0215D7D4(Cur *a, void *b);
int func_0215D864(void *a0, void *a1);
int func_0215D884(Ctx *c, void *vm);
int func_0215DADC(void *a,void *b);
int func_0215DB00(void *a,void *b);
int func_0215DB38(void *c, void *vm);
void func_0215DDC8(void *unused, void *h);
void func_0215DE0C(void *w, void *h);
void func_0215DE38(int a, void *b, void *c, int d);
void func_0215DE44(int a0);
int func_0215DE58(void *a, u32 *st, Ctx_0215DE58 *c);
int func_0215DEF0(void *a, u32 *st, u32 *c);
void func_0215DF6C(void **p);
void func_0215DF78(int a0, int a1, int a2);
int func_0215DFB4(int a0, int a1);
int func_0215E010(void *a, void *b);
int func_0215E068(int a0, int a1);
int func_0215E0B0(int a0, int a1);
int func_0215E0EC(int a0, int a1);
int func_0215E130(void *a, void *b);
int func_0215E184(int a0, int a1);
int func_0215E1C0(void *c, void *vm);
int func_0215E2B8(struct R *r, int a, int b, int n);
void *func_0215E31C(u32 heap);
void func_0215E334(void *ptr);
int func_0215E33C(int a0);
int func_0215E34C(int a0);
void func_0215E358(void *a, u32 b, u16 c);
void func_0215E364(void *a);
void func_0215E3A0(void *a);
u32 func_0215E3E4(void *p, u32 slot);
int func_0215E404(int a0);
void func_0215E428(int a0, int a1);
void func_0215E440(void *sys, u8 which);
void func_0215E580(void *a);
void func_0215E5B0(void *a0, Work *w);
int func_0215E6A8(void *a, int x);
int func_0215E6F8(int a0);
int func_0215E724(int species);
void func_0215E740(void *a, u32 b, u16 c, int d);
void func_0215E7DC(void *p,u32 i,u8 v,u32 n);
struct GdsEnt *func_0215E804(int a0, int a1);
void func_0215E840(void *field, Info *out);
int func_0215EA14(int a0, int a1);
void func_0215EA30(Query *q, u16 a, u16 b, u32 c);
int func_0215EA38(int a0, int a1, int a2);
int func_0215EA58(int a0, int a1);
void *func_0215EA6C(void *a,void *b);
int func_0215EA94(void *a,void *b,void *c);
int func_0215EAC8(int a0, int a1);
void *func_0215EAF0(void *a, void *b);
int func_0215EB18(void *a, int *state, void *b);
int func_0215EB4C(void *p);
void *func_0215EB60(void *a, void *b);
int func_0215EB88(void *a, int *state, void *b);
int func_0215EBBC(void *p);
void *func_0215EBD0(void *a, void *b);
int func_0215EBF8(void *a, int *state, void *b);
int func_0215EC2C(void *p);
void *func_0215EC40(u16 *a, void *b);
extern u8 ov112_id[];
extern const char d_02172914[];
extern u8 d_021F8360[];
extern u8 d_021BB6A4[];
extern u8 ov100_id[];
extern u8 ov132_id[];
extern const char d_02172724[];
extern const char d_02172928[];
extern const u16 d_021711C6[];
extern const char d_0217293C[];
extern struct Ent d_021711A8[];
extern const Area d_021711EC;
extern const Area d_021711F4;



/*
 * closed 2026-10-05: the unlabelled leaves it calls are now matched files, so every relocation resolves.
 * checks: 1 own 02159B10 and 0215901C prove full-width fallback return; corrected extern u32 and arg u32 produce27/284, old17 invalid; other own/caller arities reviewed; 2 D468 no closing twin; 3 typed context copy27/284, u16 mode with narrow arg228/288; 4 width/homing idioms read; 5 refreshed idioms/neighbours, no local aggregate.
 * renewed-pass: vm reused as mode and u32 vm both unchanged; no repeated permuter (old seed 9604 already consumed).
 *
 * Script command: start the ov010 link sequence (func_02155A98) for mode
 * 0/1, or push the ov112 proc through func_02014808 otherwise.
 * Size-exact, 27 bytes out with corrected full-width return: the image keeps vm in r4 and c in r5 (the
 * mode byte, the task work and the box then reuse r4); this C swaps them.
 * Old 17-byte score used an unjustified u16 return extern and is superseded.
 * Cursor idiom applied; historical declaration orders and seed9604 remain spent.
 * ov112_id now resolves as overlay_id at func_02014808; the pooled
 * callback 0x0215DF6C still lacks a witness. No leaf filed while DIFF.
 *
 * wave76: Five compiles: widened arg27/284; u16 mode plus corrected u32 extern228/288; u32 extern/arg with u8 mode27/284; byte context parameter copied to typed local27/284; observed u8 call parameter instead of inline cast27/284. Final authorized retry exhausted; seed9604 permuter remains spent.
 * evidence76: scratchpad/overlay-newpass-20261003-w76/R2/; each log awaited to terminal exit.
 *
 * recoup 2026-10-05 (lane X1, wave P9): MATCH, 284/284 bytes, only the pooled callback
 * 0x0215DF6C lacks a witness (12-byte Thumb tail stub before 0215DF78, looks like a veneer into
 * arm9 020307B0; not filed). Same bytes at --lang c99 and --lang c.
 * Two changes versus the DIFF draft: (1) `d = (mode == 0) ? 0 : 1;` instead of `d = 1; if (mode == 0) d = 0;`
 * removed the vm/c register swap (27 B to 10 B); (2) func_02159B10 declared `u16` and `arg` held in a
 * u16 local moved the outgoing `str r7,[sp]` ahead of the reloads (10 B to 0), per
 * docs/idioms/a-u16-accessor-result-held-in-a-u16-local-moves-the-stack-argument-stores.md.
 * The matched definition of func_02159B10 returns u32 (tail value of func_0215901C); the u16
 * prototype is the one six matched files already use, so the callee is declared as its callers see it.
 * Tried and inert: pragmas (six, all 27 B), `*c->pc++` (31 B), pc pointer local (27 B), reversed
 * declaration order (40 B), `u8 d` (165 B), `u32 link` (10 B).
 * Callee arity: func_02158F58 returns a+0x18 (result ignored); func_02012F44 is void in its matched
 * file but its result (sv) is used here, so the caller treats it as returning a pointer.
 * No void-return problem found on the other callees.
 */
int func_0215D34C(Ctx *c, void *vm)
{
    void *a;
    void *evt;
    void *sys;
    void *proc;
    u16 arg;
    u8 mode;

    a = func_0215A5F4(vm);
    evt = func_0215A5DC(vm);
    sys = func_0215A5E4(vm);
    proc = func_0201210C(evt);
    func_02158F58((int)a);
    arg = func_02159B10(c, vm);
    mode = *c->pc;
    c->pc++;
    if (mode <= 1) {
        void *link = (void *)func_02012F80(sys);
        u32 d;
        void *task;
        Starter *s;

        d = (mode == 0) ? 0 : 1;
        task = func_020122C0(evt, 0, func_0215DE58, sizeof(Starter));
        s = func_020124E8(task);
        MI_CpuFill8(s, 0, sizeof(Starter));
        s->seq = func_02155A98(evt, sys, arg, d, link);
        s->link = link;
        s->mode = d;
        func_0215898C(a, task);
        func_02012A30(sys);
        func_02011290((struct ScriptVm *)c);
        return 1;
    } else {
        void *sv = func_02012F44(sys);
        Box *box;

        box = func_02030734(4, sizeof(Box), 1, d_02172914, 0xA9);
        box->args = func_02030734(4, 0x14, 1, d_02172914, 0xAA);
        box->args->f00 = 0;
        box->args->f08 = func_0200A640(sv);
        box->args->f04 = 1;
        func_0215897C(a, func_02014808(evt, (int)proc, (u32)ov112_id, (int)d_021F8360, (int)box->args, (int)func_0215DF6C, (int)box));
        return 1;
    }
}







int func_0215D468(void *a, void *b)
{
    void *t = func_0215A5F4(b);
    void *h = func_0215A5DC(b);
    void *q = func_0215A5E4(b);
    int f;
    u32 g, k;
    void *r;
    Ctx_0215D468 *c;
    func_0201210C(h);
    f = func_02159B10(a, b);
    g = (u32)func_02012F44(q);
    k = func_021F675C(func_0201AB28(func_02012934(q), f), 4);
    r = func_020122C0(h, 0, (void *)func_0215DEF0, 4);
    c = func_020124E8(r);
    func_02082BCC(c, 0, 4);
    c->p = func_02030734(4, 0xc, 1, d_02172914, 0xd7);
    c->p->f4 = k;
    c->p->f8 = g;
    c->p->f0 = 0;
    func_0215897C(t, r);
    return 1;
}







/*
 * Script command: read a one-byte query id from the script cursor, one
 * argument word and a result slot, and store the answer of the query
 * (save-data counters 0..15, link-result queries 30..39) into the slot.
 *
 * Closed once the tool accepted the sole-ref witnesses of func_021569A4
 * and func_021569EC. Levers: the per-case
 * best/second locals at function scope in declaration order with op
 * declared last (sets the stack slots), max initialised before best,
 * case 10 loops over its own block-local j, case 7 tests == 0 first.
 */
int func_0215D504(Ctx_0215D504 *c, void *vm)
{
    u32 arg;
    u16 *dst;
    void *h;
    void *sv;
    void *w;
    u8 i;
    u8 max;
    u8 best3;
    u8 best8;
    u8 best9;
    u8 best10;
    u8 second;
    u8 next;
    void *list;
    u8 op;

    func_0215A5F4(vm);
    op = *c->pc;
    c->pc++;
    arg = func_02159B10(c, vm);
    dst = func_02159AE8(c, vm);
    h = func_0215A5E4(vm);
    sv = func_02012F44(h);
    w = 0;
    if (op >= 30) {
        void **pw = (void **)func_02012F80(h);

        if (pw == 0) {
            *dst = 0;
            return 0;
        }
        w = *pw;
    }
    switch (op) {
    case 0:
        *dst = func_0200A75C(sv);
        break;
    case 1:
        *dst = func_0200A780(sv);
        break;
    case 2:
        *dst = func_0200A7B8(sv);
        break;
    case 3: {
        max = 0;
        best3 = 4;

        for (i = 0; i < 4; i++) {
            u8 v = func_0200A7A0(sv, i);

            if (v > max) {
                max = v;
                best3 = i;
            } else if (v == max) {
                best3 = 4;
            }
        }
        *dst = best3;
        break;
    }
    case 4:
        *dst = func_0200A7C8(sv);
        break;
    case 5:
        func_0200A7D4(sv, arg);
        break;
    case 6:
        *dst = 0;
        for (i = 0; i < 4; i++) {
            if (func_0200A7A0(sv, i) != 0)
                *dst = 1;
        }
        break;
    case 7:
        if (func_0200A640(sv)->n == 0)
            *dst = 0;
        else
            *dst = 1;
        break;
    case 8: {
        max = 0xFF;
        best8 = 4;

        for (i = 0; i < 4; i++) {
            u8 v = func_0200A7A0(sv, i);

            if (v <= max) {
                max = v;
                best8 = i;
            }
        }
        *dst = best8;
        break;
    }
    case 9: {
        max = 0;
        best9 = 4;

        for (i = 0; i < 4; i++) {
            u8 v = func_0200A7A0(sv, i);

            if (v > max) {
                max = v;
                best9 = i;
            }
        }
        *dst = best9;
        break;
    }
    case 10: {
        u8 j;

        best10 = 4;
        second = 0;
        max = 0;
        next = 4;

        for (j = 0; j < 4; j++) {
            u8 v = func_0200A7A0(sv, j);

            if (v > max) {
                if (second == max) {
                    next = 4;
                } else {
                    second = max;
                    next = best10;
                }
                max = v;
                best10 = j;
            }
        }
        *dst = next;
        break;
    }
    case 11: {
        u8 count = 0;
        u8 n;

        list = func_02012934(h);
        n = func_0201AA18(list);

        for (i = 0; i < n; i++) {
            if ((u32)func_021F6744(func_0201AB28(list, (int)i)) == 1)
                count++;
        }
        *dst = count;
        break;
    }
    case 12:
        if ((u32)func_021F6744(func_0201AB28(func_02012934(h), (int)arg)) == 1)
            *dst = 1;
        else
            *dst = 0;
        break;
    case 13: {
        Rec_0215D468 *r = (Rec_0215D468 *)func_0200A628(sv);

        *dst = 0;
        for (i = 0; i < 8; i++) {
            if (r[i].kind != 10)
                *dst = 1;
        }
        break;
    }
    case 14:
        if (func_0200A7E0(sv) == 1)
            *dst = 1;
        else
            *dst = 0;
        break;
    case 15:
        if (func_0200A644(sv, (u8)arg) == 1)
            *dst = 1;
        else
            *dst = 0;
        break;
    case 30:
        *dst = func_021568E0(w);
        break;
    case 31:
        *dst = func_02156954(w);
        break;
    case 32:
        *dst = func_02156978(w);
        break;
    case 33:
        *dst = func_02156934(w, arg);
        break;
    case 35:
        *dst = func_021568E8((int)w, arg);
        break;
    case 36:
        *dst = func_02156908(w);
        break;
    case 37:
        *dst = func_0215699C(w, arg);
        break;
    case 38:
        *dst = func_021569A4(w, arg);
        break;
    case 39:
        *dst = func_021569EC(w, arg);
        break;
    }
    return 0;
}







int func_0215D7D4(Cur *a, void *b)
{
    int f;
    u32 k;
    u16 *out;
    Rec_0215D7D4 *r;
    f = func_02159B10(a, b);
    k = *a->f14;
    a->f14++;
    out = func_02159AE8(a, b);
    r = (Rec_0215D7D4 *)func_0200A750(func_02012F44(func_0215A5E4(b)), (u8)f);
    switch (k) {
    case 0:
        switch (r->b0) {
        case 0: *out = 0x18; break;
        case 1: *out = 0xf; break;
        case 2: *out = 0x2d; break;
        case 3: *out = 0xc; break;
        case 4: *out = 0; break;
        }
        break;
    case 1:
        *out = f + 5;
        break;
    case 2:
        f += 0xf;
        *out = f;
        break;
    case 3:
        *out = r->b1;
        break;
    case 4:
        *out = r->h2;
        break;
    }
    return 0;
}







/*
 * blocked:   wild=4
 *
 * The slot index is truncated to a byte before the arm9 pair call.
 */
int func_0215D864(void *a0, void *a1)
{
    int v = func_02159B10(a0, a1);

    func_0200A6BC((struct Big *)func_02012F44(func_0215A5E4(a1)), (u8)v);

    return 0;
}







/*
 * Script command: read a one-byte string kind and a word-set slot from the
 * script cursor, one argument word, and buffer the matching string into
 * the slot (player name, message-bank entries, link member names, or the
 * three placement labels of a four-way ranking).
 */
int func_0215D884(Ctx *c, void *vm)
{
    void *wsx = func_0215A5F4(vm);
    void *h = func_0215A5E4(vm);
    u32 heap = func_0215A5CC(vm);
    void *ws = func_02158F74(wsx);
    u8 op;
    u8 slot;
    u32 arg;
    void *bank;
    void *str;

    op = *c->pc;
    c->pc++;
    slot = *c->pc;
    c->pc++;
    arg = func_02159B10(c, vm);

    switch (op) {
    case 0: {
        void *sv = func_02012F44(func_0215A5E4(vm));

        str = func_020457B0(0x26, heap);
        func_02045994(str, (const u16 *)func_0200A7F8(sv), 0x26);
        func_0201EE0C(ws, slot, str, 0, 1, 2);
        func_02045808(str);
        break;
    }
    case 1:
    case 8:
        if (op == 1)
            bank = func_02045B38(0, 2, 0x4F, heap);
        else
            bank = func_02045B38(0, 2, 0x11A, heap);
        str = func_02045EC0(bank, arg + 3);
        func_0201EE0C(ws, slot, str, 0, 1, 2);
        func_02045808(str);
        func_02045C04(bank);
        break;
    case 2:
        str = func_02156914((int)(*((void **)func_02012F80(h))), heap);
        func_0201EE0C(ws, slot, str, 0, 1, 2);
        func_02045808(str);
        break;
    case 3:
        bank = func_02045B38(0, 2, 0x4B, heap);
        str = func_02045EC0(bank, arg);
        func_0201EE0C(ws, slot, str, 0, 1, 2);
        func_02045808(str);
        func_02045C04(bank);
        break;
    case 4:
        bank = func_02045B38(0, 2, 0x4B, heap);
        str = func_02045EC0(bank, arg + 4);
        func_0201EE0C(ws, slot, str, 0, 1, 2);
        func_02045808(str);
        func_02045C04(bank);
        break;
    case 5:
        func_02156A3C(*((void **)func_02012F80(h)), arg, ws, slot);
        break;
    case 6:
        func_02156AD4(*((void **)func_02012F80(h)), arg, ws, slot);
        break;
    case 7: {
        void *sv = func_02012F44(func_0215A5E4(vm));
        u16 ids[3];
        u8 idx[4];
        u8 val[4];
        u8 i;
        u8 j;

        for (i = 0; i < 4; i++) {
            idx[i] = i;
            val[i] = func_0200A7A0(sv, i);
        }
        for (i = 1; i < 4; i++) {
            for (j = 0; j < 4 - i; j++) {
                u8 n = j + 1;

                if (val[j] < val[n]) {
                    u8 t = val[j];

                    val[j] = val[n];
                    val[n] = t;
                    t = idx[j];
                    idx[j] = idx[n];
                    idx[n] = t;
                }
            }
        }
        if (val[0] == val[1] && val[0] == val[2]) {
            ids[0] = 9;
            ids[1] = 8;
        } else {
            ids[0] = idx[0] + 4;
            if (val[1] == val[2])
                ids[1] = 8;
            else
                ids[1] = idx[1] + 4;
        }
        if (val[1] == val[3])
            ids[2] = idx[1] + 4;
        else if (val[2] == val[3])
            ids[2] = idx[2] + 4;
        else
            ids[2] = idx[3] + 4;
        bank = func_02045B38(0, 2, 0x4B, heap);
        for (i = 0; i < 3; i++) {
            str = func_02045EC0(bank, ids[i]);
            func_0201EE0C(ws, i, str, 0, 1, 2);
            func_02045808(str);
        }
        func_02045C04(bank);
        break;
    }
    }
    return 0;
}






int func_0215DADC(void *a,void *b)
{
 int i = func_02159B10(a,b);
 u8 *p = (u8 *)func_0200A750(func_02012F44(func_0215A5E4(b)), (u8)i);
 p[1] = 0;
 return 0;
}






int func_0215DB00(void *a,void *b)
{
 int x = (int)func_02159AE8(a,b);
 int y = (int)func_02159AE8(a,b);
 void *p = func_0215A5F4(b);
 func_0215897C(p,func_0215A168((int)func_0215A5DC(b),x,y));
 return 1;
}







/*
 * Script command: link-session control. Reads a sub-command, an argument
 * and a result slot, then opens or closes the link work (0, 1), starts the
 * ov132 session steps (10..18, most of which install a wait callback and
 * suspend the script) or reports the session state into the slot (19..21).
 *
 * Byte-correct (first draft plus ov100_id for the pooled 0x64). Evidence
 * gaps, not C: 0x021FDA6C (ov132) has no func_ label; ov100_id is passed to
 * func_02014808 (r2), which is not in the overlay_id consumer list;
 * d_021BB6A4 is another overlay's proc data (same gap as func_02155478).
 * The empty `case 100: break;` is what leaves the lone `cmp r6, #0x64`.
 *
 * 2026-10-05 (wave D9): EXACT. d_021BB6A4 (ov100 process data) resolves with the ov100 token on its symbols line.
 */
int func_0215DB38(void *c, void *vm)
{
    void *evt;
    void *proc;
    void *h;
    void *sys;
    u16 cmd;
    u16 arg;
    u16 *dst;
    int busy;
    Link *l;

    evt = func_0215A5F4(vm);
    proc = func_0215A5DC(vm);
    h = func_0215A5E4(vm);
    sys = func_0201210C(proc);
    cmd = func_02159B10(c, vm);
    arg = func_02159B10(c, vm);
    func_02159B10(c, vm);
    dst = func_02159AE8(c, vm);
    busy = 0;
    l = 0;
    if (cmd != 0 && cmd != 0x15) {
        l = (Link *)func_02012F80(h);
        if (l->f00 != 0) {
            func_02156BAC(l->f00);
            if (func_02156BCC(l->f00) == 1)
                busy = 1;
        }
    }
    switch (cmd) {
    case 0:
        func_0215DDC8(evt, h);
        break;
    case 1:
        func_0215DE0C(l, h);
        break;
    case 10:
        func_0215DE38((int)l, proc, (void *)func_02012138(proc), arg);
        break;
    case 11:
        func_0215DE44((int)l);
        func_020113D0(c, (int)func_0215E130);
        return 1;
    case 12:
        l->f30 = dst;
        l->f08 = func_021CD48C(func_02012944(h), sys, 2, 4, 4, 0, 1, 0);
        func_020113D0(c, (int)func_0215DFB4);
        return 1;
    case 13:
        l->f30 = dst;
        l->f08 = func_021CD48C(func_02012944(h), sys, 2, 4, 4, 1, 1, 0);
        func_020113D0(c, (int)func_0215E010);
        return 1;
    case 14:
        if (l->sess == 0 || busy != 0)
            break;
        l->f34 = arg;
        func_021FCDEC((int)l->sess, (u8)l->f34);
        func_020113D0(c, (int)func_0215E068);
        return 1;
    case 15:
        if (l->sess == 0 || busy != 0)
            break;
        func_020113D0(c, (int)func_0215E0B0);
        return 1;
    case 16:
        func_020113D0(c, (int)func_0215E0EC);
        return 1;
    case 17:
        if (l->sess == 0 || busy != 0)
            break;
        func_020113D0(c, (int)func_0215E184);
        return 1;
    case 18: {
        Wait *w = func_02030734(0x8004, 8, (u32)1, d_02172914, (u32)0x3C8);

        w->vm = vm;
        w->link = l;
        l->f30 = dst;
        l->f0c = h;
        l->f2c = (u32)func_021FDA6C(h);
        l->f28 = arg == 0 ? 9 : 10;
        func_0215897C(evt, func_02014808(proc, (int)sys, (u32)ov100_id, (int)d_021BB6A4, (int)(&l->f0c), (int)func_0215DF78, (int)w));
        return 1;
    }
    case 19:
        if (l->sess != 0 && busy == 1)
            *dst = 1;
        else
            *dst = 0;
        break;
    case 20:
        if (l->sess != 0)
            *dst = 1;
        else
            *dst = 0;
        break;
    case 21:
        if (func_0200FB24() != 0) {
            func_02012124(proc, 1);
            *dst = 1;
        } else {
            *dst = 0;
        }
        break;
    case 100:
        break;
    }
    return 0;
}







/*
 * Allocate the 0x38-byte link work, clear its first two words, attach
 * it to the save handle and load overlays 132 and 112.
 *
 * The call to arm9 0x02012F74 (the +0x6A8 setter beside func_02012F80)
 * resolves since seeds_2 labelled and matched it (src/matched/unit_02012F68.c).
 */
void func_0215DDC8(void *unused, void *h)
{
    Work *w = func_02030734(4, 0x38, 1, d_02172914, 0x413);

    w->f00 = 0;
    w->f04 = 0;
    func_02012F74(h, w);
    func_02034AC4((u32)ov132_id);
    func_02034AC4((u32)ov112_id);
}







/*
 * Unload overlays 112 and 132, free the link work and detach it.
 *
 * The call to arm9 0x02012F74 (the +0x6A8 setter beside func_02012F80)
 * resolves since seeds_2 labelled and matched it (src/matched/unit_02012F68.c).
 */
void func_0215DE0C(void *w, void *h)
{
    func_02034A5C((u32)ov112_id);
    func_02034A5C((u32)ov132_id);
    func_020307B0(w);
    func_02012F74(h, 0);
}







/*
 * Forwards three of its four incoming argument registers to a callee whose
 * first parameter is the constant 4. The callee takes four arguments, so a
 * tail call is impossible (bx would spend an argument register on the
 * target), which is why the image keeps a frame and emits a direct bl.
 * The listing extent is two bytes long because of the trailing alignment
 * padding.
 */
void func_0215DE38(int a, void *b, void *c, int d)
{
    func_021FC644(4, (void *)b, (void *)c, d);
}







void func_0215DE44(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj12042 *)t4)->f4;
    if (a0 == 0) goto loc_0215DE56;
loc_0215DE4E:
    a0 = func_021FC684(a0);
loc_0215DE52:
a0 = 0;
((struct Obj12042 *)t4)->f4 = a0;
loc_0215DE56:
    return;}






/*
 * Padding: two zero alignment bytes after the 150-byte function.
 * Lever: context remains live in r0 across the switch for func_02012A30(p).
 */
int func_0215DE58(void *a, u32 *st, Ctx_0215DE58 *c)
{
    void *p;
    p = func_020120F4(func_020124E4(a));
    switch (*st) {
    case 0:
        func_02012374(a, (struct Evt **)c->f0);
        (*st)++;
        break;
    case 1:
        func_02012A30(p);
        func_0215DE44(c->f4);
        (*st)++;
        break;
    case 2:
        {
            void *q = (void *)func_02012138(func_020124E4(a));
            if (c->f8 != 0) {
                if (func_02026454(q) != 0)
                    break;
            }
        }
        (*st)++;
        break;
    case 3:
        if (func_0203CDBC() != 1) {
            if (c->f8 != 0)
                break;
        }
        if (c->f8 == 1) {
            func_020121CC(func_020124E4(a));
        }
        func_0215DE0C((void *)c->f4, p);
        (*st)++;
        return 1;
    }
    return 0;
}







int func_0215DEF0(void *a, u32 *st, u32 *c)
{
    void *h = func_020124E4(a);
    func_020120F4(h);
    func_0201210C(h);
    switch (*st) {
    case 0:
        (*st)++;
        break;
    case 1:
        (*st)++;
        break;
    case 2:
        (*st)++;
        break;
    case 3:
        func_020120B4(h, -1, (void *)d_02172724, (void *)(*c));
        (*st)++;
        break;
    case 4:
        if (func_020120F0(h) != 0)
            break;
        (*st)++;
        break;
    case 5:
        (*st)++;
        break;
    case 6:
        func_020307B0(((void **)*c)[1]);
        func_020307B0((void *)*c);
        return 1;
    }
    return 0;
}







void func_0215DF6C(void **p) { func_020307B0(*p); }








void func_0215DF78(int a0, int a1, int a2)
{
    int t4;
    void *v0;
    void *v1;

t4 = a0 + 0;
a0 = *(int *)&((struct Obj00005 *)((char *)t4))->f0;
    v0 = func_0215A5DC((void *)a0);
loc_0215DF82:
a0 = *(int *)&((struct Obj00005 *)((char *)t4))->f0;
    v1 = func_0215A5E4((void *)a0);
loc_0215DF8A:
    a0 = func_02012138(v0);
loc_0215DF90:
a2 = *(int *)&((struct Obj00005 *)t4)->f4;
a0 = ((struct Obj09156 *)a2)->f28;
    if (a0 == 0xc) goto loc_0215DFAC;
loc_0215DF98:
    if (a0 == 0xd) goto loc_0215DFAC;
loc_0215DF9C:
a0 = ((struct Obj09156 *)a2)->f30;
a1 = 1;
*(u16 *)&((struct Obj00005 *)((char *)a0))->f0 = a1;
a0 = *(int *)&((struct Obj00005 *)t4)->f4;
a0 = *(int *)&((struct Obj00005 *)a0)->f4;
    a0 = func_021FC81C(a0, a1);
loc_0215DFAA:
    return;
loc_0215DFAC:
a0 = ((struct Obj09156 *)a2)->f30;
a1 = 0;
*(u16 *)&((struct Obj00005 *)((char *)a0))->f0 = a1;
    return;}








/*
 * blocked:  listing 92 compiled 90
 */
int func_0215DFB4(int a0, int a1)
{
    int t4;
    int t5;
    void *v0;
    void *v1;

t4 = a1 + 0;
a0 = t4 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0215DFBE:
a0 = t4 + 0;
    v1 = func_0215A5E4((void *)a0);
loc_0215DFC4:
    a0 = func_02012F80(v1);
loc_0215DFC8:
t4 = a0 + 0;
a0 = ((struct Obj02658 *)t4)->f8;
    a0 = func_021CD688(a0);
loc_0215DFD0:
t5 = 0;
    if (a0 == 1) goto loc_0215DFE0;
loc_0215DFD6:
    if (a0 == 2) goto loc_0215DFEC;
loc_0215DFDA:
    if (a0 == 4) goto loc_0215DFF4;
loc_0215DFDE:
    goto loc_0215DFFC;
loc_0215DFE0:
a0 = ((struct Obj02658 *)t4)->f30;
((struct Obj02658 *)((char *)a0))->f0 = t5;
a0 = ((struct Obj02658 *)t4)->f4;
    a0 = func_021FC804(a0);
loc_0215DFEA:
    goto loc_0215DFFA;
loc_0215DFEC:
a0 = ((struct Obj02658 *)t4)->f30;
t5 = 1;
((struct Obj02658 *)((char *)a0))->f0 = t5;
    goto loc_0215DFFC;
loc_0215DFF4:
a0 = ((struct Obj02658 *)t4)->f30;
a1 = 2;
((struct Obj02658 *)((char *)a0))->f0 = a1;
loc_0215DFFA:
t5 = 1;
loc_0215DFFC:
    if (t5 != 1) goto loc_0215E00A;
loc_0215E000:
a0 = ((struct Obj02658 *)t4)->f8;
    a0 = func_021CD5A4(a0);
loc_0215E006:
a0 = 0;
((struct Obj02658 *)t4)->f8 = a0;
loc_0215E00A:
a0 = t5 + 0;
    return a0;}








int func_0215E010(void *a, void *b)
{
    struct W *w;
    int r;
    int v;

    func_0215A5F4(b);
    w = (struct W *)func_02012F80(func_0215A5E4(b));
    r = 0;
    switch (func_021CD688(w->f8)) {
    case 1:
        *w->f30 = 3;
        func_021FC804(w->f4);
        r = 1;
        break;
    case 2:
        v = 4;
        *w->f30 = v;
        r = 1;
        break;
    case 4:
        v = 2;
        *w->f30 = v;
        r = 1;
        break;
    }
    if (r == 1) {
        func_021CD5A4(w->f8);
        w->f8 = 0;
    }
    return r;
}







/*
 * blocked:  listing 72 compiled 70
 */
int func_0215E068(int a0, int a1)
{
    int t4;
    void *v0;
    void *v1;

t4 = a1 + 0;
a0 = t4 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0215E072:
a0 = t4 + 0;
    v1 = func_0215A5E4((void *)a0);
loc_0215E078:
    a0 = func_02012F80(v1);
loc_0215E07C:
t4 = a0 + 0;
a0 = *(int *)&((struct Obj00005 *)((char *)t4))->f0;
    if (a0 == 0) goto loc_0215E096;
loc_0215E084:
    func_02156BAC((void *)a0);
loc_0215E088:
a0 = *(int *)&((struct Obj00005 *)((char *)t4))->f0;
    a0 = func_02156BCC((void *)a0);
loc_0215E08E:
    if (a0 != 1) goto loc_0215E096;
loc_0215E092:
a0 = 1;
    return a0;
loc_0215E096:
a1 = ((struct Obj00005 *)t4)->f34;
a0 = *(int *)&((struct Obj00005 *)t4)->f4;
a1 = a1 << 0x18;
a1 = (unsigned)a1 >> 0x18;
    a0 = func_021FCE00(a0, a1);
loc_0215E0A2:
    if (a0 != 1) goto loc_0215E0AA;
loc_0215E0A6:
a0 = 1;
    return a0;
loc_0215E0AA:
a0 = 0;
    return a0;}







int func_0215E0B0(int a0, int a1)
{
    int t4;
    void *v0;
    void *v1;

t4 = a1 + 0;
a0 = t4 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0215E0BA:
a0 = t4 + 0;
    v1 = func_0215A5E4((void *)a0);
loc_0215E0C0:
    a0 = func_02012F80(v1);
loc_0215E0C4:
t4 = a0 + 0;
a0 = *(int *)&((struct Obj00005 *)((char *)t4))->f0;
    a0 = func_02156BAC((void *)a0);
loc_0215E0CC:
a0 = *(int *)&((struct Obj00005 *)((char *)t4))->f0;
    a0 = func_02156BCC((void *)a0);
loc_0215E0D2:
    if (a0 != 1) goto loc_0215E0DA;
loc_0215E0D6:
a0 = 1;
    return a0;
loc_0215E0DA:
a0 = *(int *)&((struct Obj00005 *)t4)->f4;
    a0 = func_021FD844(a0);
loc_0215E0E0:
    if (a0 != 1) goto loc_0215E0E8;
loc_0215E0E4:
a0 = 1;
    return a0;
loc_0215E0E8:
a0 = 0;
    return a0;}








/*
 * blocked:
 */
int func_0215E0EC(int a0, int a1)
{
    int t4;
    int t5;
    void *v0;
    void *v1;
    void *v2;

t4 = a1 + 0;
a0 = t4 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0215E0F6:
a0 = t4 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0215E0FC:
a0 = t4 + 0;
    v2 = func_0215A5E4((void *)a0);
loc_0215E104:
    a0 = func_02012138(v1);
loc_0215E10C:
t5 = a0 + 0;
    a0 = func_02012F80(v2);
loc_0215E114:
t4 = a0 + 0;
a0 = t5 + 0;
    a0 = func_02026454((void *)a0);
loc_0215E11C:
    if (a0 != 4) goto loc_0215E12C;
loc_0215E120:
a0 = t5 + 0;
    a0 = func_02026474((void *)a0);
loc_0215E126:
*(int *)&((struct Obj00005 *)t4)->f4 = a0;
a0 = 1;
    return a0;
loc_0215E12C:
a0 = 0;
    return a0;}








int func_0215E130(void *a, void *b)
{
    void *t;
    void *s;
    int *w;

    func_0215A5F4(b);
    t = func_0215A5DC(b);
    s = func_0215A5E4(b);
    t = (void *)func_02012138(t);
    w = (int *)func_02012F80(s);
    if (*w != 0) {
        func_02156BAC((void *)(*w));
        if (func_02156BCC((void *)(*w)) == 1) {
            return 1;
        }
    }
    if (func_02026454(t) == 0) {
        return 1;
    }
    return 0;
}







int func_0215E184(int a0, int a1)
{
    int t4;
    void *v0;
    void *v1;

t4 = a1 + 0;
a0 = t4 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0215E18E:
a0 = t4 + 0;
    v1 = func_0215A5E4((void *)a0);
loc_0215E194:
    a0 = func_02012F80(v1);
loc_0215E198:
t4 = a0 + 0;
a0 = *(int *)&((struct Obj00005 *)((char *)t4))->f0;
    a0 = func_02156BAC((void *)a0);
loc_0215E1A0:
a0 = *(int *)&((struct Obj00005 *)((char *)t4))->f0;
    a0 = func_02156BCC((void *)a0);
loc_0215E1A6:
    if (a0 != 1) goto loc_0215E1AE;
loc_0215E1AA:
a0 = 1;
    return a0;
loc_0215E1AE:
a0 = *(int *)&((struct Obj00005 *)t4)->f4;
    a0 = func_021FD910(a0);
loc_0215E1B4:
    if (a0 != 1) goto loc_0215E1BC;
loc_0215E1B8:
a0 = 1;
    return a0;
loc_0215E1BC:
a0 = 0;
    return a0;}







/*
 * Script command with a six-way sub-command switch over an ov021 service
 * (0x021B76B4..0x021B7794) on the save-data block func_02009448 returns;
 * sub-commands 0, 1 and 4 write a halfword result through the destination
 * variable, 5 formats a value into the word set.
 */
int func_0215E1C0(void *c, void *vm)
{
    u32 cmd;
    u16 *dst;
    u16 v;
    void *sys;
    void *x;
    void *blk;
    u32 lim;
    void *t;
    void *ws;

    cmd = func_02159B10(c, vm);
    dst = func_02159AE8(c, vm);
    v = func_0215A5CC(vm);
    sys = func_0215A5DC(vm);
    x = func_0215A5E4(vm);
    blk = func_02009448(func_02012EBC(x));
    lim = (int)func_02009370(blk);
    if (func_0201210C(sys) == 0 && cmd != 0) {
        return 0;
    }
    switch (cmd) {
    case 0:
        *dst = (int)func_02009370(blk) > 0 ? 1 : 0;
        break;
    case 1:
        if (func_021B76F8(x, v, blk) < lim) {
            *dst = 1;
        } else {
            *dst = 0;
        }
        break;
    case 2:
        t = func_021B7794(sys);
        func_0215897C(func_0215A5F4(vm), t);
        return 1;
    case 3:
        func_021B76B4(x, v, (int)blk);
        break;
    case 5:
        ws = func_02158F74(func_0215A5F4(vm));
        func_0201EF5C(ws, 0, (u32)func_021B7740(x, v, blk, *dst));
        break;
    case 4:
        *dst = func_021B76F8(x, v, blk);
        break;
    }
    return 0;
}







int func_0215E2B8(struct R *r, int a, int b, int n)
{
    u32 q;
    int v;

    func_02082BCC(r, 0, 0xe8);
    v = func_02013EC0(b);
    if (v == 0xffff) {
        return 0;
    }
    q = func_020493D4((struct ArcFile *)a, v) / 0xe8;
    if (q != 1 && q != 4) {
        return 0;
    }
    if (q == 1) {
        n = 0;
    }
    func_0204944C((struct ArcFile *)a, v, n * 0xe8, 0xe8, r);
    r->f7 |= 0x80;
    return 1;
}


void *func_0215E31C(u32 heap)
{
    return func_02030734(heap, 32, 1, d_02172928, 45);
}




void func_0215E334(void *ptr)
{
    func_020307B0(ptr);
}




int func_0215E33C(int a0)
{
    int a1;

    a0 = func_02188CE8(a0);
loc_0215E342:
a1 = ((struct Obj17696 *)a0)->f10;
    a0 = func_021AA7DC(a0, a1);
loc_0215E348:
    return a0;}




int func_0215E34C(int a0)
{
    int a1;

    a0 = func_02012A38((const struct BigObj *)a0);
loc_0215E352:
a1 = 0;
((struct Obj17697 *)a0)->fC = a1;
    return a0;}




void func_0215E358(void *a, u32 b, u16 c)
{
    func_0215E740(a, b, c, 0xff);
}


void func_0215E364(void *a)
{
    u8 i;
    void *q;
    void *p;
    p = func_0200D418(func_02012EBC(a));
    q = (void *)func_02012984(a);
    for (i = 0; i < 2; i++) {
        if (func_0200D488(p, i) != 0) func_0215E358((void *)p, (u32)q, i);
    }
}



void func_0215E3A0(void *a)
{
    u8 i;
    void *q;
    void *p;

    p = func_0200D418(func_02012EBC(a));
    q = (void *)func_02012984(a);
    for (i = 0; i < 2; i++) {
        func_0200D4AC(p, i);
        if (func_0200D488(p, i) != 0) {
            func_0215E358((void *)p, (u32)q, i);
        }
    }
}


u32 func_0215E3E4(void *p, u32 slot)
{
    u32 i = func_0200D478(p, slot);
    if (i > 16) return 319;
    return d_021711C6[i];
}



int func_0215E404(int a0)
{
    int a1;
    int t4;
    int t5;

t4 = a0 + 0;
t5 = 0;
loc_0215E40A:
a0 = t4 + 0;
a1 = t5 + 0;
    a0 = func_0200D488((struct Blk38 *)a0, a1);
loc_0215E412:
    if (a0 == 0) goto loc_0215E41A;
loc_0215E416:
a0 = 1;
    return a0;
loc_0215E41A:
a0 = t5 + 1;
a0 = a0 << 0x18;
t5 = (unsigned)a0 >> 0x18;
    if ((unsigned)t5 < (unsigned)2) goto loc_0215E40A;
loc_0215E424:
a0 = 0;
    return a0;}



void func_0215E428(int a0, int a1)
{
    int t4;
    int t5;

t5 = a0 + 0;
t4 = a1 + 0;
    a0 = func_0215E404(a0);
loc_0215E432:
    if (a0 == 0) goto loc_0215E43E;
loc_0215E436:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_0200D45C(a0, a1);
loc_0215E43E:
    return;}



/*
 * Hand out the legendary for slot `which` (Thundurus 642 or Tornadus
 * 641 at level 40): fill the event record, create the Pokemon into the
 * box, and mark the slot. Levers: level and the record flag assigned the
 * same value in both switch arms (the tail-merged assignments keep them
 * as variables: level spilled to the frame, the flag in r6), species as
 * u32 truncated at the call, `a` declared before `save`.
 */
void func_0215E440(void *sys, u8 which)
{
    void *a;
    void *save;
    void *rec;
    void *party;
    void *mon;
    u32 species;
    u16 level;
    u32 flag;

    save = func_02012EBC(sys);
    a = func_0200D418(save);
    rec = func_0200D4AC(a, which);
    switch (which) {
    case 0:
        species = 642;
        level = 40;
        flag = 1;
        break;
    case 1:
        species = 641;
        level = 40;
        flag = 1;
        break;
    default:
        return;
    }
    func_0200D50C(rec, 4, species);
    func_0200D50C(rec, 6, level);
    func_0200D50C(rec, 9, flag);
    party = func_02012944(sys);
    mon = func_02030734(0x8003, func_020173EC(), 1, d_0217293C, 0x12E);
    func_02017588(mon, species, level, func_02008530(party), 0xFFFFFFFF, 0xFFFFFFFF00000000ULL);
    func_0200D50C(rec, 7, 0);
    func_0200D50C(rec, 8, 1);
    func_0200D50C(rec, 2, func_02017E1C(mon, 0xAC, 0));
    func_0200D50C(rec, 3, func_02017E1C(mon, 0, 0));
    func_0200D50C(rec, 10, func_02017E1C(mon, 0x70, 0));
    func_0200D50C(rec, 5, func_02017E1C(mon, 0xA1, 0));
    func_0200CFA0(func_0200CA10(save), mon);
    func_020307B0(mon);
    func_0215E740(a, (u32)((void *)func_02012984(sys)), which, 5);
    func_0200D470(a, which, 1);
}


void func_0215E580(void *a)
{
 int i;
 void *p = func_0200D418(func_02012EBC(a));
 for(i=0;i<2;i++) {
  if(func_0200D468(p,(u8)i)==2) func_0215E440(a,i);
 }
}



/*
 * Reads species (5), a word at 0xA0 and a byte at 0x9D of the lead party
 * member, looks up a record for the species (func_0215E804) and either
 * rolls a 30% chance of func_0215E364 when there is none, sets one of two
 * states on it for modes 1-2 (with field 0xA0 clear) or 5, or copies the two
 * values into it and calls func_0215E364.
 *
 * MATCH, bytes exact. Blocker: func_0201313C (arm9, Thumb) is an unlabelled
 * leaf (a .word after func_02013128's pool), so neither label nor
 * sole-ref/code reaches it. It is EXACT from
 *     void *func_0201313C(void *p, int i)
 *     { return ((void **)((char *)p + 0x24))[i]; }
 * as src/matched/arm9/func_0201313C.c (pkt_0201313C), outside this ov lane's
 * write set; once that shard exists this file verifies EXACT.
 * The local declaration order (mon, species, v, idx, tbl, b) is load-bearing.
 *
 * 2026-10-05 (wave D8): The arm9 leaf func_0201313C now has an EXACT witness src/matched/arm9/func_0201313C.c (pkt_0201313C); once its shard exists this file verifies EXACT.
 */
void func_0215E5B0(void *a0, Work *w)
{
    void *mon;
    u16 species;
    u16 v;
    u32 idx;
    void *tbl;
    u8 b;

    if (w->f04 != 0 || w->f00 != 0) {
        return;
    }
    func_02012AC8(func_020127A4(a0));
    mon = func_0201AB28(func_0201313C(w, 1), 0);
    species = func_02017E1C(mon, 5, 0);
    v = func_02017E1C(mon, 0xA0, 0);
    b = func_02017E1C(mon, 0x9D, 0);
    tbl = func_0200D418(func_02012EBC(a0));
    mon = func_0215E804((int)tbl, species);
    if (mon == 0) {
        if (func_02005728(100) < 30) {
            func_0215E364(a0);
        }
        return;
    }
    idx = func_0215E724(species);
    if ((w->f8c == 1 || w->f8c == 2) && v == 0) {
        func_0200D494(mon);
        func_0200D480(tbl, idx, 0x10);
        func_0200D470(tbl, idx, 2);
        return;
    }
    if (w->f8c == 5) {
        func_0200D494(mon);
        func_0200D480(tbl, idx, 0x10);
        func_0200D470(tbl, idx, 3);
        return;
    }
    func_0200D50C(mon, 5, v);
    func_0200D50C(mon, 7, b);
    func_0215E364(a0);
}



int func_0215E6A8(void *a, int x)
{
    u8 i;
    void *p;

    p = func_0200D418(func_02012EBC(a));
    i = 0;
    if (func_0200D488(p, 0) != 0 && x == func_0215E3E4(p, i)) {
        return 6;
    }
    i = 1;
    if (func_0200D488(p, 1) != 0 && x == func_0215E3E4(p, i)) {
        return 7;
    }
    return 0xffff;
}



int func_0215E6F8(int a0)
{
    int a1;
    int t4;
    void *p;
    void *t5;

    p = func_02012EBC((struct Big *)a0);
loc_0215E6FE:
    t5 = func_0200D418(p);
loc_0215E702:
a1 = 0;
t4 = 0;
    a0 = func_0200D488(t5, a1);
loc_0215E70C:
    if (a0 != 0) goto loc_0215E71C;
loc_0215E710:
a1 = 1;
    a0 = func_0200D488(t5, a1);
loc_0215E718:
    if (a0 == 0) goto loc_0215E720;
loc_0215E71C:
a0 = 1;
    return a0;
loc_0215E720:
a0 = t4 + 0;
    return a0;}


int func_0215E724(int species)
{
    switch(species) {
    case 642: return 0;
    case 641: return 1;
    }
    return 2;
}


/*
 * Lever: slot c is u16 in the function and both receiving externs,
 * causing its immediate home reload; the selected byte remains u8.
 */
void func_0215E740(void *a, u32 b, u16 c, int d)
{
    struct Ent *e;
    int s;
    u8 buf[4];
    u8 w;
    int v;
    int k;
    int i;
    s = func_0200D478(a, c);
    e = &d_021711A8[(u16)func_020113D8(b)];
    if (s != 0x10 && func_02005728(100) < 20) {
        func_0215E7DC(a, c, 0x10, 0xffff);
        return;
    }
    k = 0;
    for (i = 0; i < e->n; i++) {
        v = e->v[i];
        if (v != s && v != d) {
            buf[k++] = v;
        }
    }
    w = buf[func_02005728(k)];
    func_0215E7DC(a, c, w, w > 0x10 ? 0x13f : d_021711C6[w]);
}


void func_0215E7DC(void *p,u32 i,u8 v,u32 n)
{
 void *rec = func_0200D4AC(p,i);
 func_0200D480(p,i,v);
 func_0200D50C(rec,1,n);
}



struct GdsEnt *func_0215E804(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    struct GdsEnt *t7;

t5 = a0 + 0;
t6 = a1 + 0;
t4 = 0;
loc_0215E80C:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_0200D488((struct Blk38 *)a0, a1);
loc_0215E814:
    if (a0 == 0) goto loc_0215E830;
loc_0215E818:
a0 = t5 + 0;
a1 = t4 + 0;
    t7 = func_0200D4AC((struct Blk38 *)a0, a1);
loc_0215E820:
a1 = 4;
    a0 = func_0200D4B8(t7, a1);
loc_0215E828:
    if (t6 != a0) goto loc_0215E830;
loc_0215E82C:
    return t7;
loc_0215E830:
a0 = t4 + 1;
a0 = a0 << 0x18;
t4 = (unsigned)a0 >> 0x18;
    if ((unsigned)t4 < (unsigned)2) goto loc_0215E80C;
loc_0215E83A:
    return 0;}



/*
 * Fill the 0x14-byte Info for the field: id, the ov021 handles, and the
 * flags word from the object kind, the map tests and the save flags.
 * One lever: the u16 for func_021CD440 is declared before x (stack order).
 */
void func_0215E840(void *field, Info *out)
{
    VecFx32 pos;
    u16 v;
    u16 x;
    u16 y;
    u16 z;
    void *q;
    void *obj;
    void *map;
    u16 kind;
    u32 a;
    u32 b;
    u32 c;

    MI_CpuFill8(out, 0, sizeof(Info));
    out->id = func_02188C9C(field);
    out->f08 = (u32)func_02188C80(field);
    out->field = field;
    q = func_02188CB4(field);
    out->f04 = func_021A3098(q);
    obj = func_021A3250(q);
    out->obj = obj;
    if (obj != 0) {
        kind = func_0216D598(obj);
        map = func_02188C7C(field);
        func_0216D88C(obj, &pos);
        if (func_0216E5FC(kind) && func_0216E5B0(map, &pos) == 0)
            out->flags |= 8;
        if (kind == 0x6C)
            out->flags |= 1;
    }
    a = func_021A3050(q);
    b = func_021A30C8(q);
    c = func_021A3128(q, a);
    if (func_021A3504((u8 *)q, b, c) == 1)
        out->flags |= 2;
    if (func_021A3524((u8 *)q, b, c) == 1)
        out->flags |= 4;
    if (func_02013C40(out->id) == 1) {
        out->flags |= 0x10;
        out->flags |= 0x40;
    }
    if (func_02013C50(out->id) == 1)
        out->flags |= 0x80;
    if (func_02014470(func_02012B38(func_020120F4((const struct Ctx *)out->f08))) & 1)
        out->flags |= 0x20;
    if (func_021CD440(field, &v) == 1)
        out->flags |= 0x400;
    if (func_02013FFC(out->id)) {
        func_021A35FC(func_02188CB4(out->field), &x, &y, &z);
        if (func_0201400C(out->id) && func_0215F118(&d_021711EC, x, z, 0x113, field))
            out->flags |= 0x20;
        if (func_02014018(out->id) && func_0215F118(&d_021711F4, x, z, 0x112, field))
            out->flags |= 8;
    }
    if (func_02013E04(out->id) == 0) {
        out->flags = 0;
    } else {
        out->flags |= 0x100;
        out->flags |= 0x200;
    }
    if (func_02012B70(func_020120F4((const struct Ctx *)out->f08)) == 1)
        out->flags = 0;
}



int func_0215EA14(int a0, int a1)
{
    int a2;
    int t4;

a2 = a0 + 0;
t4 = a1 + 0;
a0 = t4 + 0;
a1 = a2 + 0;
    a0 = func_0215F088((u16 *)a0, a1);
loc_0215EA22:
a1 = a0 + 0;
    if (a1 != 0) goto loc_0215EA2A;
loc_0215EA26:
a0 = 1;
    return a0;
loc_0215EA2A:
a0 = t4 + 0;
    a0 = ((int (*)())a1)(a0);
loc_0215EA2E:
    return a0;}



/*
 * Unlabelled leaf after func_0215E840's pool (bl from 0x0215FE3C).
 */
void func_0215EA30(Query *q, u16 a, u16 b, u32 c)
{
    q->a = a;
    q->b = b;
    q->c = c;
}



int func_0215EA38(int a0, int a1, int a2)
{
    int a3;
    int t4;
    int t5;

a3 = a0 + 0;
t4 = a2 + 0;
t5 = a1 + 0;
a0 = t4 + 0;
a1 = a3 + 0;
    a0 = func_0215F0B8((u16 *)a0, a1);
loc_0215EA48:
a2 = a0 + 0;
    if (a2 != 0) goto loc_0215EA50;
loc_0215EA4C:
a0 = 0;
    return a0;
loc_0215EA50:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = ((int (*)())a2)(a0, a1);
loc_0215EA56:
    return a0;}



int func_0215EA58(int a0, int a1)
{
    int t4;

a1 = 0;
t4 = 0;
    a0 = func_0215F104(a0, a1);
loc_0215EA62:
    if (a0 != 0) goto loc_0215EA68;
loc_0215EA66:
t4 = 1;
loc_0215EA68:
a0 = t4 + 0;
    return a0;}


void *func_0215EA6C(void *a,void *b)
{
 void *t = func_020122C0(((struct Obj02057 *)b)->f8,0,func_0215EA94,20);
 func_0215F0E8(func_020124E8(t),a,b);
 return t;
}


int func_0215EA94(void *a,void *b,void *c)
{
 int h;
 int t;
 func_0201296C(func_020120F4(((struct Obj12311 *)c)->f8));
 h = ((struct Obj12311 *)c)->fC;
 t = func_021587B0((int)a,0x2715,0,0);
 func_02159058(t,h,0,0,0);
 return 0;
}



int func_0215EAC8(int a0, int a1)
{
    int t4;

a1 = ((struct Obj17698 *)a0)->f4;
    if (a1 != 2) goto loc_0215EAD4;
loc_0215EAD0:
a0 = 4;
    return a0;
loc_0215EAD4:
    if (a1 != 3) goto loc_0215EADC;
loc_0215EAD8:
a0 = 1;
    return a0;
loc_0215EADC:
a1 = 1;
t4 = 1;
    a0 = func_0215F104(a0, a1);
loc_0215EAE4:
    if (a0 == 0) goto loc_0215EAEA;
loc_0215EAE8:
t4 = 0;
loc_0215EAEA:
a0 = t4 + 0;
    return a0;}


void *func_0215EAF0(void *a, void *b)
{
    void *task;
    task = func_020122C0(((struct Obj02057 *)b)->f8, 0, (void *)func_0215EB18, 20);
    func_0215F0E8(func_020124E8(task), a, b);
    return task;
}


/*
 * Interface: 021587B0 returns its final ldr r0,[r4] at 021587DC;
 * caller consumes that result despite older callers declaring void.
 */
int func_0215EB18(void *a, int *state, void *b)
{
    int h;
    int t;
    func_0201296C(func_020120F4(((struct Obj12312 *)b)->f8));
    h = ((struct Obj12312 *)b)->fC;
    t = func_021587B0((int)a, 0x2713, 0, 0);
    func_02159058(t, h, 0, 0, 0);
    return 0;
}


int func_0215EB4C(void *p)
{
    return func_0215F104((int)p, 2) != 0 ? B_FALSE : B_TRUE;
}


void *func_0215EB60(void *a, void *b)
{
    void *task;
    task = func_020122C0(((struct Obj02057 *)b)->f8, 0, (void *)func_0215EB88, 20);
    func_0215F0E8(func_020124E8(task), a, b);
    return task;
}


int func_0215EB88(void *a, int *state, void *b)
{
    int h;
    int t;
    func_0201296C(func_020120F4(((struct Obj12313 *)b)->f8));
    h = ((struct Obj12313 *)b)->fC;
    t = func_021587B0((int)a, 0x2717, 0, 0);
    func_02159058(t, h, 0, 0, 0);
    return 0;
}


int func_0215EBBC(void *p)
{
    return func_0215F104((int)p, 3) != 0 ? B_FALSE : B_TRUE;
}


void *func_0215EBD0(void *a, void *b)
{
    void *task;
    task = func_020122C0(((struct Obj02057 *)b)->f8, 0, (void *)func_0215EBF8, 20);
    func_0215F0E8(func_020124E8(task), a, b);
    return task;
}


int func_0215EBF8(void *a, int *state, void *b)
{
    int h;
    int t;
    func_0201296C(func_020120F4(((struct Obj12314 *)b)->f8));
    h = ((struct Obj12314 *)b)->fC;
    t = func_021587B0((int)a, 0x2711, 0, 0);
    func_02159058(t, h, 0, 0, 0);
    return 0;
}


int func_0215EC2C(void *p)
{
    return func_0215F104((int)p, 8) != 0 ? B_FALSE : B_TRUE;
}


void *func_0215EC40(u16 *a, void *b)
{
    return func_021C6078(((struct Obj12315 *)b)->f8, ((struct Obj12315 *)b)->f10, *a);
}
