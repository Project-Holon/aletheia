/*
 * file:     scrcmd_c03center.c
 * unit:     yes
 * function: func_021B5A18, func_021B5B0C, func_021B5B4C, func_021B5B8C, func_021B5BFC, func_021B5C80, func_021B5CE8, func_021B5DD0, func_021B5DF8, func_021B5EB8, func_021B5F24, func_021B5FB4, func_021B5FB8, func_021B6048, func_021B60F4, func_021B6124, func_021B6164, func_021B61E8, func_021B627C, func_021B62C8, func_021B631C, func_021B636C, func_021B63D4, func_021B647C, func_021B654C, func_021B6590, func_021B65D8, func_021B6628, func_021B66B8, func_021B6708, func_021B6850, func_021B6904, func_021B6934, func_021B69B0, func_021B69D8, func_021B6A78, func_021B6AA4, func_021B6AAC, func_021B6AB0, func_021B6AE0, func_021B6AFC, func_021B6B6C, func_021B6BDC
 * address:  0x021B5A18
 * region:   ov021
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
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0216CDB8  0x0216CDB8  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D30  0x02188D30  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0218ED50  0x0218ED50  thumb  ov021
 *   func_0218FE70  0x0218FE70  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   d_021DE25C     0x021DE25C  data  a1
 *   g_021EE724     0x021EE724  data  a2
 *   g_021EE724_ref 0x021EE724  data  a2
 *   _s32_div_f     0x0209C0A4  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A07C  0x0215A07C  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_0215B4AC  0x0215B4AC  thumb  ov010
 *   func_02012F08  0x02012F08  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0200C11C  0x0200C11C  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_0200C2B0  0x0200C2B0  thumb
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_0200C2D0  0x0200C2D0  thumb
 *   func_0201EE60  0x0201EE60  thumb
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CA38  0x0200CA38  thumb
 *   func_0200CF08  0x0200CF08  thumb
 *   func_0200D298  0x0200D298  thumb
 *   func_0200D0F8  0x0200D0F8  thumb
 *   func_0200D2C4  0x0200D2C4  thumb
 *   func_0200CF54  0x0200CF54  thumb
 *   func_0200D2B0  0x0200D2B0  thumb
 *   d_021D98DC     0x021D98DC  data  a4
 *   d_021D9904     0x021D9904  data  a4
 *   d_021D992C     0x021D992C  data  a4
 *   func_0201891C  0x0201891C  thumb
 *   func_0215B500  0x0215B500  thumb  ov010
 *   func_0215A0E8  0x0215A0E8  thumb  ov010
 *   func_0202130C  0x0202130C  thumb
 *   func_020188AC  0x020188AC  thumb
 *   func_02018790  0x02018790  thumb
 *   func_021C5AAC  0x021C5AAC  thumb  ov021
 *   func_0215A2E4  0x0215A2E4  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02166C4C  0x02166C4C  thumb  ov010
 *   func_021CBFB0  0x021CBFB0  thumb  ov021
 *   func_021CC040  0x021CC040  thumb  ov021
 *   func_021CC060  0x021CC060  thumb  ov021
 *   func_021CC068  0x021CC068  thumb  ov021
 *   func_021CC500  0x021CC500  thumb  ov021
 *   func_0201292C  0x0201292C  thumb
 *   func_02007FA0  0x02007FA0  thumb
 *   func_020056EC  0x020056EC  thumb
 *   func_020081DC  0x020081DC  thumb
 *   func_020212B0  0x020212B0  thumb
 *   func_02012FD8  0x02012FD8  thumb
 *   func_0200E7BC  0x0200E7BC  thumb
 *   func_02158F7C  0x02158F7C  thumb ov010
 *   func_0200E740  0x0200E740  thumb
 *   func_0200E7AC  0x0200E7AC  thumb
 *   func_02045A98  0x02045A98  arm
 *   func_02045924  0x02045924  arm
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_0201293C  0x0201293C  thumb
 *   func_020173EC  0x020173EC  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_0202136C  0x0202136C  thumb
 *   func_02008FEC  0x02008FEC  thumb
 *   func_02008F08  0x02008F08  thumb
 *   func_02009020  0x02009020  thumb
 *   func_0200903C  0x0200903C  thumb
 *   func_02008EAC  0x02008EAC  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_02017988  0x02017988  thumb
 *   func_020185C4  0x020185C4  thumb
 *   func_02007A18  0x02007A18  thumb
 *   func_0201747C  0x0201747C  thumb
 *   func_0201AB48  0x0201AB48  thumb
 *   func_020185F0  0x020185F0  thumb
 *   func_020075B0  0x020075B0  thumb
 *   d_021DE270     0x021DE270  data   ov021  a1
 *   func_02007698  0x02007698  thumb
 *   func_02008530  0x02008530  thumb
 *   func_020079BC  0x020079BC  thumb
 *   func_0201AB8C  0x0201AB8C  thumb
 *   func_02158F58  0x02158F58  thumb ov010
 *   func_02188D24  0x02188D24  thumb ov021
 *   func_021BB990  0x021BB990  thumb ov021
 *   ov055_id       0x00000037  data  a1
 *   d_021F45F0     0x021F45F0  data  ov055  a4
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200A8A0  0x0200A8A0  thumb
 *   func_021690A4  0x021690A4  thumb  ov010
 *   func_02087C88  0x02087C88  arm
 *   func_0200A940  0x0200A940  thumb
 *   func_0200A8F8  0x0200A8F8  thumb
 *   func_0200A8C8  0x0200A8C8  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045808  0x02045808  arm
 *   func_0200A8AC  0x0200A8AC  thumb
 *   func_0201134C  0x0201134C  thumb
 *   func_0215A6D0  0x0215A6D0  thumb ov010
 *   func_0215A6C4  0x0215A6C4  thumb  ov010
 *   func_02158F78  0x02158F78  thumb  ov010
 *   func_0215A5D0  0x0215A5D0  thumb  ov010
 *   func_0215A7F0  0x0215A7F0  thumb  ov010
 *   func_02158F54  0x02158F54  thumb  ov010
 *   func_021854B0  0x021854B0  thumb  ov020
 *   func_0200A300  0x0200A300  thumb
 *   func_0200A338  0x0200A338  thumb
 *   func_021B7834  0x021B7834  thumb  ov021
 *   func_021B7864  0x021B7864  thumb  ov021
 *   func_021B785C  0x021B785C  thumb  ov021
 *   func_021B6D0C  0x021B6D0C  thumb  ov021
 *   func_021B6D30  0x021B6D30  thumb  ov021
 *   func_021B6D64  0x021B6D64  thumb  ov021
 *   func_021B6D98  0x021B6D98  thumb  ov021
 *   func_021B6DC0  0x021B6DC0  thumb  ov021
 *   func_021B6DE4  0x021B6DE4  thumb  ov021
 *   func_021B6E0C  0x021B6E0C  thumb  ov021
 *   func_021B6EB0  0x021B6EB0  thumb  ov021
 *   func_0216BF74  0x0216BF74  thumb  ov010
 *   d_021D9970     0x021D9970  data   ov021  a4
 */
#include "../../matched/include/Obj20016.h"

struct Ctx;
struct Node;
struct Blk34;
struct BigObj;
struct WordSet;
struct Blk37;
struct Obj;
struct Rec0200E7BC;
struct Strbuf;
struct Party;
struct PartyMon;
struct Sub020075B0Entry;
struct Sub020079BCEntry;
struct Sub02008EACObj;
struct Sub02008F80Obj;
struct Mon;
struct Sub0200852CObj;
struct Big;
struct Rec;
struct U16Vec;
struct Entry;
struct OSOwnerInfo;
struct Cursor;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
} Ramp;

typedef struct { u16 a; u16 b; } Ent_021B5A18;

typedef signed int     s32;

typedef signed short   s16;

typedef signed char    s8;

struct Owner {
    u8 f0;
    u8 f1;
    u8 month;
    u8 day;
    u8 rest[0x50];
};

typedef struct {
    u8 pad[0x14];
    u8 *p;
} Ctx;

typedef struct { int x, y, z; } Vec3;

typedef struct { u16 id, f1, f2, f3, f4; } Rec10;

typedef struct Ent_021B6AFC {
    int id;
    u32 f4[5];
} Ent_021B6AFC;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_0215A5E4(void *a0);
extern u16 func_02159B10(void *, void *);
extern void func_0216CDB8(u8 *p, u32 v);
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_02188D30(u8 *p);
extern u16 func_02188C84(u8 *p);
extern void *func_02188C58(void *p);
extern void *func_02188C7C(u8 *p);
extern u8 *func_0218ED50(u8 *p);
extern u8 *func_0218FE70(u8 *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02030DA8(u32, void (*)(), void *, u32);
extern u32 func_020307B0(void *p);
extern void func_02030EAC(struct Node *n);
extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_0215A07C(int a, u16 *b, u16 *c);
extern void func_0215897C(void *vm, void *task);
extern int func_0215B4AC(void *a0, unsigned int a1, void **out);
extern void *func_02012F08(int *p);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_0200C11C(struct Blk34 *p, u16 a, u32 b, u32 c, u32 d);
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0201AA18(void *a0);
extern void *func_0201AB28(void *p, u32 idx);
extern void func_0200C2B0(struct Blk34 *p, u32 i, const u16 *src);
extern void *func_02158F74(void *p);
extern void func_0200C2D0(struct Blk34 *p, u32 i, u16 *dest);
extern void func_0201EE60(struct WordSet *p, u32 i, u16 v);
extern u16 func_0215A5CC(void *a0);
extern void *func_0200CA1C(void *a);
extern u32 func_0200CA38(struct Blk37 *p);
extern u16 func_0200CF08(struct Blk37 *p, u32 heap);
extern int func_0200D298(void *a0);
extern u16 func_0200D0F8(struct Blk37 *p, u32 heap);
extern int func_0200D2C4(void *p, unsigned int heap);
extern u16 func_0200CF54(struct Blk37 *p, u32 heap);
extern int func_0200D2B0(void *a0, int a1);
extern u32 func_0201891C(void *p, s32 v);
extern int func_0215B500(int a0, int a1);
extern void *func_0215A0E8(void *t, u16 *o1, u16 *o2, u8 c, u32 v);
extern u32 func_0202130C(u32 id);
extern u32 func_020188AC(void *p, int v);
extern u32 func_02018790(void *p);
extern int func_021C5AAC(void *a, int b, int c, int d);
extern int func_0215A2E4(int a, int b, int c, int d, int e, int f, unsigned short g);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012944(void *p);
extern void *func_02166C4C(void *a, void *b, void *c);
extern struct Obj *func_021CBFB0(u32 a, u32 b);
extern void func_021CC040(struct Obj *o);
extern u32 func_021CC060(u8 *p);
extern u32 func_021CC068(u8 *p);
extern void *func_021CC500(void *a, u32 b, u32 c);
extern void *func_0201292C(const struct BigObj *p);
extern u32 func_02007FA0(u8 *base, u32 id);
extern u32 func_020056EC(u32);
extern u16 *func_020081DC(void *, int, u16);
extern u16 func_020212B0(u16);
extern void *func_02012FD8(void **p);
extern void func_0200E7BC(struct Rec0200E7BC *o, int idx, void *mon);
extern u32 func_02158F7C(u8 *p);
extern u32 func_0200E740(const void *obj, u32 idx);
extern void *func_0200E7AC(void *obj, u32 idx);
extern u16 func_02045A98(void);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern u32 func_0201293C(const struct BigObj *p);
extern u32 func_020173EC(void);
extern void func_02082D44(void *src, void *dst, u32 n);
extern u32 func_0202136C(u16 v);
extern struct Sub02008F80Obj *func_02008FEC(void *sys);
extern void *func_02008F08(int a0);
extern int func_02009020(void *obj, int v);
extern void func_0200903C(struct Sub02008F80Obj *arr, u32 unused, int i, const struct Sub02008F80Obj *src);
extern void func_02008EAC(struct Sub02008EACObj *obj);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_02017988(void *p, u32 a);
extern void func_020185C4(void *mon);
extern struct Sub020079BCEntry *func_02007A18(void **save, u32 box, u32 slot);
extern void *func_0201747C(struct Mon *p, u32 heap);
extern void func_0201AB48(struct Party *p, u32 idx, const struct PartyMon *src);
extern void *func_020185F0(void *mon);
extern int func_020075B0(void *save, u32 box, u32 slot, const struct Sub020075B0Entry *src);
extern int func_02007698(void);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern int func_020079BC(void **save, u32 box, u32 slot, int field, int arg);
extern u32 func_0201AB8C(struct Party *p, u32 i, u32 j, u32 heap);
extern int func_02158F58(int a0);
extern u32 func_02188D24(u8 *p);
extern int *func_021BB990(int, int *, const int *);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200A8A0(void *);
extern void *func_021690A4(int a0);
extern void func_02087C88(struct OSOwnerInfo *info);
extern int func_0200A940(void *, int, int, void *);
extern u32 func_0200A8F8(struct Rec *r, u32 index);
extern struct Entry *func_0200A8C8(struct Rec *r, u32 index);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045808(struct U16Vec *vec);
extern s32 func_0200A8AC(struct Rec *r);
extern u32 func_0201134C(struct Cursor *p);
extern void func_0215A6D0(void *p, u32 v);
extern u32 func_0215A6C4(void *p);
extern u32 func_02158F78(u8 *p);
extern u16 func_0215A5D0(void *);
extern void func_0215A7F0(unsigned short *p, int a, int b, int c, struct U16Vec *s0, void *s1);
extern void *func_02158F54(void *);
extern int func_021854B0(void *, void *, int, Vec3 *, int);
extern void *func_0200A300(void *a0, void *a1, void *a2);
extern void func_0200A338(void *h);
extern void *func_021B7834(void *a, int *out, void *buf);
extern u8 func_021B7864(void *a);
extern void func_021B785C(u8 *p, u32 i);
extern int func_021B6D0C(int idx, void *x, void *y, void *z);
extern int func_021B6D30(int idx, void *x, void *c);
extern int func_021B6D64(int idx, void *x, void *c);
extern int func_021B6D98(int idx, void *x, void *y, void *z);
extern int func_021B6DC0(int idx, void *x, void *y, void *z);
extern u16 func_021B6DE4(void *a, void *sv);
extern u16 func_021B6E0C(void *a);
extern int func_021B6EB0(u32 *o, int k);
extern void func_0216BF74(void *a, int i, void *b);
int func_021B5A18(void *a, void *b);
void func_021B5B0C(int a0, Ramp *p);
int func_021B5B4C(void *a0, void *a1);
int func_021B5B8C(void *a, void *b);
int func_021B5BFC(void *a, void *b);
int func_021B5C80(void *a, void *b);
int func_021B5CE8(void *a, void *b);
u32 func_021B5DD0(Ent_021B5A18 *t, int k);
int func_021B5DF8(u32 a, u32 b);
int func_021B5EB8(u32 a, u32 b);
int func_021B5F24(u32 a, int sel);
int func_021B5FB4(u32 a);
int func_021B5FB8(u32 a, int sel);
int func_021B6048(u32 a, u32 b, u32 key, u8 *mask, u32 flag);
int func_021B60F4(void *a, void *b);
int func_021B6124(u32 a, u32 b);
int func_021B6164(u32 a, u32 b);
int func_021B61E8(u32 a, u32 b);
int func_021B627C(u32 a, u32 b);
int func_021B62C8(void *a, void *b);
int func_021B631C(u32 a, u32 b);
int func_021B636C(void *a, void *b);
u32 func_021B63D4(void *a, void *b);
int func_021B647C(void *a, void *b);
u32 func_021B654C(void *a, void *b);
u32 func_021B6590(void *a, void *b);
u32 func_021B65D8(void *a, void *b);
int func_021B6628(void *a, void *b);
u32 func_021B66B8(void *a, void *b);
void func_021B6708(u32 a, int idx);
int func_021B6850(u32 a, u16 b, u16 *c, u16 *d);
void func_021B6904(void *a);
int func_021B6934(void *a);
int func_021B69B0(void *a, void *b);
u32 func_021B69D8(void *a, void *b);
int func_021B6A78(void *a, void *b);
Rec10 *func_021B6AA4(Rec10 *a, u32 b);
void func_021B6AAC(u16 *a0);
int func_021B6AB0(void *a);
int func_021B6AE0(Ctx *c, void *b);
u32 func_021B6AFC(void *a, void *b);
u32 func_021B6B6C(void *a, void *b);
int func_021B6BDC(u32 a, u32 b);
extern const char d_021DE25C[];
extern u16 g_021EE724;
extern u16 g_021EE724_ref;
extern u16 d_021D98DC[];
extern u16 d_021D9904[];
extern u16 d_021D992C[];
extern u8 d_021DE270[];
extern u8 ov055_id[];
extern const int d_021F45F0[];
extern Ent_021B6AFC d_021D9970[];








/*
 * Allocates the Ramp record func_021B5B0C steps (its own matched source
 * names the fields) and starts it as a task.
 *
 * Addresses are Black-image addresses.
 */
int func_021B5A18(void *a, void *b)
{
    void *sys;
    u32 task;
    u32 heap;
    u8 *obj;
    u8 *snd;
    Ramp *p;
    u32 n;
    u8 *q;
    int v;
    u32 m;
    int d;

    func_0215A5F4(b);
    sys = func_0215A5DC(b);
    func_0215A5E4(b);
    sys = func_0201210C(sys);
    task = func_02188D30(sys);
    heap = func_02188C84(sys);
    obj = func_02188C58(sys);
    snd = func_02188C7C(sys);
    n = func_02159B10(a, b);
    p = func_02030734(heap, 0x10, 1, d_021DE25C, 0x5d);
    g_021EE724 = *(u16 *)func_0218ED50(obj);
    func_0216CDB8(snd, (u32)&g_021EE724_ref);
    q = func_0218FE70(obj);
    p->f0 = g_021EE724;
    v = ((struct Obj20016 *)q)->f26;
    p->f4 = v;
    m = v % 0x4000;
    if (m >= 0x2000) {
        p->f4 = v + (0x4000 - m);
    } else {
        p->f4 = v - m;
    }
    p->f4 -= p->f0;
    d = p->f4;
    if ((d < 0 ? -d : d) >= 0x8000) {
        if (d > 0) {
            p->f4 -= 0x10000;
        } else {
            p->f4 += 0x10000;
        }
    }
    p->f8 = 0;
    p->fc = n;
    func_02030DA8(task, (void (*)())func_021B5B0C, p, 0);
    return 0;
}








void func_021B5B0C(int a0, Ramp *p)
{
    p->f8++;
    g_021EE724 = (p->f4 * p->f8) / p->fc;
    g_021EE724 = g_021EE724 + (u16)p->f0;
    if (p->f8 >= p->fc) {
        func_020307B0(p);
        func_02030EAC((struct Node *)a0);
    }
}








int func_021B5B4C(void *a0, void *a1)
{
    u16 *a = func_02159AE8(a0, a1);
    u16 *b = func_02159AE8(a0, a1);
    void *r4;

    func_02159B10(a0, a1);
    r4 = func_0215A5F4(a1);
    func_0215897C(r4, func_0215A07C((int)func_0215A5DC(a1), a, b));
    return 1;
}








/*
 * Addresses are Black-image addresses.
 */
int func_021B5B8C(void *a, void *b)
{
    void *rec;
    struct Blk34 *x;
    u16 v5, v6f, v4c, v6e;

    if (func_0215B4AC(b, func_02159B10(a, b), &rec) == 1) {
        x = func_02012F08(func_0215A5E4(b));
        v5 = func_02017E1C(rec, 5, 0);
        v6f = func_02017E1C(rec, 0x6f, 0);
        v4c = func_02017E1C(rec, 0x4c, 0);
        v6e = func_02017E1C(rec, 0x6e, 0);
        func_0200C11C(x, v5, v6f, v4c, v6e);
    }
    return 0;
}








int func_021B5BFC(void *a, void *b)
{
    u16 buf[6];
    void *sav;
    unsigned int r;
    void *bag;
    void *mon;
    int i;
    int j;
    int n;

    sav = func_0215A5E4(b);
    bag = func_02012934(sav);
    r = func_02159B10(a, b);
    for (i = 0; i < 6; i++)
        buf[i] = 0;
    for (j = 0, n = 0; j < (int)func_0201AA18(bag); j++) {
        mon = func_0201AB28(bag, j);
        if (func_02017E1C(mon, 0x4C, 0) == 0)
            buf[n++] = func_02017E1C(mon, 5, 0);
    }
    func_0200C2B0(func_02012F08(sav), r, buf);
    return 0;
}








int func_021B5C80(void *a, void *b)
{
    void *t;
    struct WordSet *w;
    unsigned int k;
    u16 *out;
    int i;
    int n;
    u16 arr[6];

    t = func_0215A5E4(b);
    w = func_02158F74(func_0215A5F4(b));
    k = func_02159B10(a, b);
    out = func_02159AE8(a, b);
    func_0200C2D0(func_02012F08(t), k, arr);
    for (i = 0, n = 0; i < 6; i++) {
        if (arr[i] != 0) {
            func_0201EE60(w, n, arr[i]);
            n++;
        }
    }
    *out = n;
    return 0;
}








int func_021B5CE8(void *a, void *b)
{
    u16 v[6];
    void *mon;
    u32 slot;
    u32 which;
    u16 *out;
    u16 sum;
    u16 max;
    u32 i;

    slot = func_02159B10(a, b);
    which = func_02159B10(a, b);
    out = func_02159AE8(a, b);
    if (func_0215B4AC(b, slot, &mon) == 0) {
        *out = 0;
        return 0;
    }
    sum = 0;
    v[0] = func_02017E1C(mon, 0x46, 0);
    v[1] = func_02017E1C(mon, 0x47, 0);
    v[2] = func_02017E1C(mon, 0x48, 0);
    v[3] = func_02017E1C(mon, 0x49, 0);
    v[4] = func_02017E1C(mon, 0x4a, 0);
    v[5] = func_02017E1C(mon, 0x4b, 0);
    max = 0;
    for (i = 0; i < 6; i++) {
        sum += v[i];
        if (max < v[i]) {
            max = v[i];
        }
    }
    switch (which) {
    case 0:
        *out = sum;
        break;
    case 1:
        *out = max;
        break;
    case 2:
        *out = v[0];
        break;
    case 3:
        *out = v[1];
        break;
    case 4:
        *out = v[2];
        break;
    case 5:
        *out = v[3];
        break;
    case 6:
        *out = v[4];
        break;
    case 7:
        *out = v[5];
        break;
    }
    return 0;
}






/*
 * Unlabelled leaf (saves no lr), called by func_021B5DF8.
 * Addresses are Black-image addresses.
 */
u32 func_021B5DD0(Ent_021B5A18 *t, int k)
{
    int i;
    u32 th;

    for (i = 0; ; i++) {
        th = t[i].a;
        if (th == 0)
            return t[i].b;
        if (k <= (int)th)
            return t[i].b;
    }
}






/*
 * Case blocks are in source order 3, 2, 1; per-case stores to *o1 but a
 * single *o2 store after the switch is what spills o2 (register pressure)
 * and gives o1 r4.
 *
 * Case 3 reads d_021D98DC and case 1 d_021D992C (pool words in that order);
 * the earlier draft had the two swapped, which only the relocation check saw.
 *
 * Addresses are Black-image addresses.
 */
int func_021B5DF8(u32 a, u32 b)
{
    u32 mode;
    u16 *o1;
    u16 *o2;
    u32 id;
    u32 w;
    u32 x;

    mode = func_02159B10((void *)a, (void *)b);
    o1 = func_02159AE8((void *)a, (void *)b);
    o2 = func_02159AE8((void *)a, (void *)b);
    id = func_0215A5CC((void *)b);
    w = (u32)func_0200CA1C(func_0215A5E4((void *)b));
    func_0200CA38((struct Blk37 *)w);
    *o1 = 5;
    *o2 = 0;
    switch (mode) {
    case 3:
        x = func_0200CF54((struct Blk37 *)w, id);
        if (func_0200D2B0((void *)w, id) == 1)
            *o1 = 0x1e;
        else
            *o1 = func_021B5DD0((Ent_021B5A18 *)d_021D98DC, x);
        break;
    case 2:
        x = func_0200D0F8((struct Blk37 *)w, id);
        if (func_0200D2C4((void *)w, id) == 1)
            *o1 = 0xd;
        else
            *o1 = func_021B5DD0((Ent_021B5A18 *)d_021D9904, x);
        break;
    case 1:
        x = func_0200CF08((struct Blk37 *)w, id);
        if (func_0200D298((void *)w) == 1)
            *o1 = 0x32;
        else
            *o1 = func_021B5DD0((Ent_021B5A18 *)d_021D992C, x);
        break;
    default:
        return 0;
    }
    *o2 = x;
    return 0;
}






int func_021B5EB8(u32 a, u32 b)
{
    u32 w;
    void *s;
    u16 *out;

    w = (u32)func_0200CA1C(func_0215A5E4((void *)b));
    s = func_0201210C(func_0215A5DC((void *)b));
    out = func_02159AE8((void *)a, (void *)b);
    switch (func_02159B10((void *)a, (void *)b)) {
    case 1:
        *out = func_0200D298((void *)w);
        break;
    case 3:
        *out = func_0200D2B0((void *)w, func_02188C84(s));
        break;
    case 2:
        *out = func_0200D2C4((void *)w, func_02188C84(s));
        break;
    }
    return 0;
}





int func_021B5F24(u32 a, int sel)
{
    switch (sel) {
    case 1:
        if (func_0201891C((void *)a, 3))
            return 0x152;
        if (func_0201891C((void *)a, 4))
            return 0x133;
        if (func_0201891C((void *)a, 5))
            return 0x134;
        break;
    case 0:
        return 0x1b2;
    case 2:
        if (func_0201891C((void *)a, 0))
            return 0x208;
        if (func_0201891C((void *)a, 1))
            return 0x207;
        if (func_0201891C((void *)a, 2))
            return 0x206;
        break;
    }
    return 0x133;
}





/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021B5FB4(u32 a)
{
return 255;
}





int func_021B5FB8(u32 a, int sel)
{
    switch (sel) {
    case 1:
        if (func_0201891C((void *)a, 3))
            return 1;
        if (func_0201891C((void *)a, 4))
            return 1;
        if (func_0201891C((void *)a, 5))
            return 1;
        return 0;
    case 0:
        if (func_0201891C((void *)a, 6))
            return 1;
        return 0;
    case 2:
        if (func_0201891C((void *)a, 0))
            return 1;
        if (func_0201891C((void *)a, 1))
            return 1;
        if (func_0201891C((void *)a, 2))
            return 1;
        return 0;
    }
    return 0;
}





int func_021B6048(u32 a, u32 b, u32 key, u8 *mask, u32 flag)
{
    void *lst;
    int n;
    int i;
    int found;
    int all;
    u32 item;

    lst = func_02012934(func_0215A5E4((void *)b));
    n = func_0201AA18(lst);
    found = 0;
    all = 0;
    *mask = found;
    for (i = 0; i < n; i++) {
        item = (u32)func_0201AB28(lst, i);
        if (func_02017E1C((void *)item, 0x4c, 0) == 1)
            continue;
        if (func_021B5FB8(item, key) == 0)
            continue;
        found = 1;
        if (flag != 0) {
            item = func_02017E1C((void *)item, 9, 0);
            if (item < func_021B5FB4(key))
                continue;
        }
        all = 1;
        *mask = *mask | (u8)(1 << i);
    }
    if (found == 0)
        return 1;
    if (all == 0)
        return 2;
    return 0;
}





int func_021B60F4(void *a, void *b)
{
    u32 v;
    u16 *p;
    u32 tmp;

    v = func_02159B10(a, b);
    p = func_02159AE8(a, b);
    *p = func_021B6048((u32)a, (u32)b, v, (u8 *)(&tmp), 1);
    return 0;
}





int func_021B6124(u32 a, u32 b)
{
    u32 x;
    u32 y;
    u16 *o;
    u32 rec;
    int v;

    x = func_02159B10((void *)a, (void *)b);
    y = func_02159B10((void *)a, (void *)b);
    o = func_02159AE8((void *)a, (void *)b);
    if (func_0215B4AC((void *)b, y, (void **)(&rec)) == 1)
        v = func_021B5F24(rec, x);
    else
        v = 0;
    *o = v;
    return 0;
}





int func_021B6164(u32 a, u32 b)
{
    u32 x;
    u32 y;
    u16 *o;
    u32 rec;

    x = func_02159B10((void *)a, (void *)b);
    y = func_02159B10((void *)a, (void *)b);
    o = func_02159AE8((void *)a, (void *)b);
    *o = 1;
    if (func_0215B4AC((void *)b, y, (void **)(&rec)) == 0)
        return 0;
    if (func_021B5FB8(rec, x) == 0) {
        *o = 1;
    } else if (func_0215B500(rec, func_021B5F24(rec, x)) == 1) {
        *o = 3;
    } else if (func_02017E1C((void *)rec, 9, 0) < func_021B5FB4(x)) {
        *o = 2;
    } else {
        *o = 0;
    }
    return 0;
}





int func_021B61E8(u32 a, u32 b)
{
    u32 mode;
    u16 *o1;
    u16 *o2;
    void *s;
    void *t;
    u32 v;
    u8 c;

    mode = func_02159B10((void *)a, (void *)b);
    o1 = func_02159AE8((void *)a, (void *)b);
    o2 = func_02159AE8((void *)a, (void *)b);
    s = func_0215A5F4((void *)b);
    t = func_0215A5DC((void *)b);
    if (func_021B6048(a, b, mode, &c, 0)) {
        *o1 = 0;
    } else {
        switch (mode) {
        case 1:
            v = 0xfffe;
            break;
        case 2:
            v = 0xfffd;
            break;
        case 0:
            v = 0x1b2;
            break;
        default:
            v = 0xa5;
            break;
        }
        func_0215897C(s, func_0215A0E8(t, o1, o2, c, v));
    }
    return 1;
}





int func_021B627C(u32 a, u32 b)
{
    u16 *o;
    void *lst;
    u32 n;
    u32 i;

    o = func_02159AE8((void *)a, (void *)b);
    *o = 0;
    lst = func_02012934(func_0215A5E4((void *)b));
    n = func_0201AA18(lst);
    for (i = 0; i < n; i++) {
        if (func_02017E1C(func_0201AB28(lst, i), 0x97, 0) != 0) {
            *o = 1;
            break;
        }
    }
    return 0;
}





int func_021B62C8(void *a, void *b)
{
    u16 *p;
    u32 v;
    u32 w;
    u32 x;
    u16 r;

    p = func_02159AE8(a, b);
    v = func_02159B10(a, b);
    w = func_0202130C(0x151);
    if (func_0215B4AC(b, v, (void **)(&x)) == 0) {
        *p = 0xFFFF;
    } else if (func_020188AC((void *)x, w) == 0) {
        *p = 0xFFFF;
    } else {
        *p = func_02018790((void *)x);
    }
    return 0;
}





int func_021B631C(u32 a, u32 b)
{
    void *x;
    void *y;
    u16 *p;
    u32 q;

    x = func_0215A5F4((void *)b);
    y = func_0215A5DC((void *)b);
    p = func_02159AE8((void *)a, (void *)b);
    q = func_02159B10((void *)a, (void *)b);
    func_0215897C(x, (void *)func_021C5AAC(y, (int)p, q, func_02159B10((void *)a, (void *)b)));
    return 1;
}






int func_021B636C(void *a, void *b)
{
    u16 *t10;
    u16 *t6;
    u16 tc;
    u16 t4;
    void *p7;
    void *p5;

    t10 = func_02159AE8(a, b);
    t6 = func_02159AE8(a, b);
    tc = func_02159B10(a, b);
    t4 = func_02159B10(a, b);
    p7 = func_0215A5F4(b);
    p5 = func_0215A5DC(b);
    func_0215897C(p7, (void *)func_0215A2E4((int)p5, (int)func_0201210C(p5), tc, (int)t10, (int)t6, t4 == 0, t4));
    return 1;
}






u32 func_021B63D4(void *a, void *b)
{
    u16 *out = func_02159AE8(a, b);
    void *p10 = func_0215A5F4(b);
    void *pc = func_0215A5DC(b);
    void *t8 = func_0201210C(pc);
    void *t;
    void *party;
    int n;
    int i;

    func_02188C84(t8);
    t = func_020120F4(pc);
    func_02012944(t);
    party = func_02012934(t);
    n = func_0201AA18(party);
    for (i = 0; i < n; i++) {
        void *mon = func_0201AB28(party, i);
        u32 x = func_02017E1C(mon, 0x4c, 0);
        u32 y = func_02017E1C(mon, 3, 0);
        u32 z = func_02017E1C(mon, 9, 0);

        if (x != 0 && y == 0 && z == 0) {
            func_0215897C(p10, func_02166C4C(pc, t8, mon));
            *out = i;
            return 1;
        }
    }
    return 0;
}






int func_021B647C(void *a, void *b)
{
    void *sys;
    void *w;
    u32 heap;
    u16 *out;
    u32 i2;
    u32 idx;
    void *mon;
    void *obj;
    u32 v;

    func_0215A5F4(b);
    sys = func_0215A5DC(b);
    w = func_020120F4(sys);
    heap = func_02188C84(func_0201210C(sys));
    out = func_02159AE8(a, b);
    i2 = func_02159B10(a, b);
    idx = func_02159B10(a, b);
    mon = func_0201AB28(func_02012934(w), idx);
    obj = func_021CBFB0(heap, i2);
    *out = 0;
    if (*out == 0 && func_02017E1C(mon, 0x4c, 0) == 1) {
        *out = 1;
    }
    if (*out == 0) {
        v = func_02017E1C(mon, 5, 0);
        if (v != func_021CC060(obj)) {
            *out = 2;
        }
    }
    if (*out == 0 && func_021CC068(obj) != 2) {
        v = func_02017E1C(mon, 0x6e, 0);
        if (v != func_021CC068(obj)) {
            *out = 3;
        }
    }
    func_021CC040(obj);
    return 0;
}






u32 func_021B654C(void *a, void *b)
{
    void *r7 = func_0215A5F4(b);
    void *x = func_0215A5DC(b);
    u32 t = func_02159B10(a, b);
    u32 u = func_02159B10(a, b);
    func_0215897C(r7, func_021CC500(x, (u8)t, (u8)u));
    return 1;
}






u32 func_021B6590(void *a, void *b)
{
    u16 *out = func_02159AE8(a, b);
    void *sv = func_0201292C(func_0215A5E4(b));
    int k = 2;
    u32 t = func_02007FA0(sv, 2);
    u32 id = func_020056EC(t);
    u16 v;

    if (t == 0)
        v = 0;
    else
        v = func_020212B0(*func_020081DC(sv, k, id));
    *out = v;
    return 0;
}






u32 func_021B65D8(void *a, void *b)
{
    void *t;
    void *w;
    int i;
    int j;

    func_0215A5F4(b);
    t = func_020120F4(func_0215A5DC(b));
    w = func_02012FD8(t);
    t = func_02012934(t);
    i = func_02159B10(a, b);
    j = func_02159B10(a, b);
    func_0200E7BC(w, j, func_0201AB28(t, i));
    return 0;
}






/*
 * The else arm zero is an array initialiser: `u16 s[1] = {0}` keeps &s in r6
 * for the call argument while the result store gets a fresh add sp.
 */
int func_021B6628(void *a, void *b)
{
    void *t;
    void *w;
    u32 i;
    u32 j;
    void *x;
    void *y;

    t = func_0215A5F4(b);
    w = func_02012FD8(func_020120F4(func_0215A5DC(b)));
    i = func_02159B10(a, b);
    j = func_02159B10(a, b);
    x = (void *)func_02158F7C(t);
    y = func_02158F74(t);
    if (func_0200E740(w, i)) {
        func_02045924(x, func_0200E7AC(w, i));
    } else {
        u16 s[1] = {0};
        s[0] = func_02045A98();
        func_02045924(x, s);
    }
    func_0201EE0C(y, j, x, 0, 1, 2);
    return 0;
}






u32 func_021B66B8(void *a, void *b)
{
    u32 op = func_02159B10(a, b);
    u16 *out = func_02159AE8(a, b);
    void *x = func_0215A5E4(b);

    switch (op) {
    case 0:
        if (func_021B6934(x) < 0)
            *out = 0;
        else
            *out = 1;
        break;
    case 1:
        func_021B6904(b);
        break;
    case 2:
        func_021B6708((u32)b, *out);
        func_021B6904(b);
        break;
    }
    return 0;
}






void func_021B6708(u32 a, int idx)
{
    void *sv;
    void *party;
    u32 heap;
    void *save;
    void *mon;
    u32 sz;
    void *o;
    void *buf;
    int i;
    void *m;
    u16 pos[2];

    sv = func_0215A5E4((void *)a);
    party = func_02012934((void *)sv);
    if (func_021B6850((u32)sv, 0x283, &pos[1], &pos[0]) == 0) {
        return;
    }
    heap = func_0215A5CC((void *)a);
    save = (void *)func_0201293C(sv);
    mon = func_02030734(heap, func_020173EC(), 1, (const char *)d_021DE270, 0x4c7);
    sz = func_020173EC();
    func_02082D44(func_0201AB28(party, idx), mon, sz);
    if (func_0202136C(func_02017E1C(mon, 6, 0)) == 1) {
        o = func_02008FEC(sv);
        buf = func_02008F08(func_0215A5CC((void *)a));
        i = func_02009020(o, 0);
        func_02017E1C(mon, 0xa7, (u32)buf);
        func_02012944(sv);
        if (i >= 0) {
            func_0200903C(o, 0, i, buf);
        }
        func_02008EAC(buf);
        func_02017E40(mon, 0xa7, (u32)buf);
        func_02017E40(mon, 6, 0);
        func_020307B0(buf);
    }
    if (func_02017E1C(mon, 0xab, 0) == 0x1ec) {
        func_02017988(mon, 0);
        func_020185C4(mon);
    }
    m = func_0201747C((struct Mon *)func_02007A18(save, pos[1], pos[0]), heap);
    func_0201AB48(party, idx, m);
    func_020307B0(m);
    func_020075B0(save, pos[1], pos[0], func_020185F0(mon));
    func_020307B0(mon);
}






int func_021B6850(u32 a, u16 b, u16 *c, u16 *d)
{
    int base;
    int i;
    u32 t10;
    int j;
    int m;
    u32 r4;
    u32 r6;

    func_02012934((void *)a);
    r4 = (u32)func_02012944((void *)a);
    r6 = func_0201293C((const struct BigObj *)a);
    base = func_02007698();
    t10 = func_02008530((const struct Sub0200852CObj *)r4);
    for (i = 0; i < 24; i++) {
        m = (i + base) % 24;
        for (j = 0; j < 30; j++) {
            if (func_020079BC((void **)r6, m, j, 0xa9, 0) != 0
                && t10 == func_020079BC((void **)r6, m, j, 7, 0)
                && b == func_020079BC((void **)r6, m, j, 5, 0)
                && func_020079BC((void **)r6, m, j, 0x4c, 0) == 0) {
                *c = m;
                *d = j;
                return 1;
            }
        }
    }
    return 0;
}






void func_021B6904(void *a)
{
    void *t;
    void *u;
    int r;

    t = func_0215A5E4(a);
    u = func_02012934(t);
    r = func_021B6934(t);
    if (r >= 0) {
        func_0201AB8C(u, r, 0, func_0215A5CC(a));
    }
}






int func_021B6934(void *a)
{
    void *party = func_02012934(a);
    void *p = func_02012944(a);
    int n = func_0201AA18(party);
    u32 t0 = func_02008530(p);
    int i;

    for (i = 0; i < n; i++) {
        void *mon = func_0201AB28(party, i);

        if (t0 == func_02017E1C(mon, 7, 0)
            && func_02017E1C(mon, 5, 0) == 0x283
            && func_02017E1C(mon, 0x4c, 0) == 0)
            return i;
    }
    return -1;
}






/*
 * d_021F45F0 is the ov055 proc table (ov055 is the overlay id passed to
 * func_021BB990), hence the ov055 token on its symbols: line.
 */
int func_021B69B0(void *a, void *b)
{
    func_021BB990((int)ov055_id, (int *)func_02188D24((u8 *)(((u32 *)func_02158F58((int)func_0215A5F4(b)))[1])), d_021F45F0);
    return 0;
}






u32 func_021B69D8(void *a, void *b)
{
    void *r5 = func_0215A5E4(b);
    u32 s8 = func_02159B10(a, b);
    void *r4;
    int r6;
    int fl;
    void *v;
    u32 r7;
    struct Owner o;

    r4 = func_0200A8A0(func_02012EBC(r5));
    r5 = func_021690A4((int)r5);
    func_02087C88((struct OSOwnerInfo *)(&o));
    r6 = func_0200A940(r4, o.month, o.day, r5);
    fl = func_0200A8F8(r4, r6);
    fl = fl != 1;
    r6 = (int)func_0200A8C8(r4, r6);
    r7 = (u32)func_02158F74(func_0215A5F4(b));
    v = func_020457B0(8, 0x8001);
    func_02045924(v, (const u16 *)r6);
    func_0201EE0C((struct WordSet *)r7, s8, v, fl, 1, 2);
    func_02045808(v);
    return 0;
}






int func_021B6A78(void *a, void *b)
{
    void *t;
    u16 *p;

    t = func_0215A5E4(b);
    p = func_02159AE8(a, b);
    *p = func_0200A8AC(func_0200A8A0(func_02012EBC(t)));
    return 0;
}






Rec10 *func_021B6AA4(Rec10 *a, u32 b)
{
    return a + b;
}





void func_021B6AAC(u16 *a0)
{
}





int func_021B6AB0(void *a)
{
    int i;
    u16 *p;

    for (i = 0; i < 8; i++) {
        p = (u16 *)func_021B6AA4((Rec10 *)a, i);
        func_021B6AAC(p);
        if (*p == 0xFFFF) {
            return i;
        }
    }
    return 0;
}





/*
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 */
int func_021B6AE0(Ctx *c, void *b)
{
    func_0215A6D0(b, (u32)(c->p + func_0201134C((struct Cursor *)c)));
    return 0;
}



u32 func_021B6AFC(void *a, void *b)
{
    Rec10 *tab = (Rec10 *)func_0215A6C4(b);
    void *r4 = func_0215A5F4(b);
    int s0c = func_02158F78(r4);
    int s8 = func_02158F7C(r4);
    u16 id = func_0215A5D0(b);
    u32 n = func_021B6AB0(tab);
    u32 i = 0;

    for (; i < n; i++) {
        Rec10 *e = func_021B6AA4(tab, i);

        if (id != e->f1)
            func_0215A7F0(b, e->id, 0xffff, i, (struct U16Vec *)s0c, (void *)s8);
    }
    return 0;
}




u32 func_021B6B6C(void *a, void *b)
{
    u32 idx = func_02159B10(a, b);
    Rec10 *tab = (Rec10 *)func_0215A6C4(b);

    func_0215A5D0(b);
    if (idx < func_021B6AB0(tab)) {
        const Rec10 *e = func_021B6AA4(tab, idx);
        void *r5 = func_0215A5F4(b);
        void *r6 = func_02158F54(r5);
        void *cur = func_0201210C(r6);
        Vec3 v;
        u32 f3 = e->f3;
        u32 f4 = e->f4;
        u32 f1 = e->f1;
        u32 f2 = e->f2;

        v.x = f2 << 16;
        v.y = f3 << 16;
        v.z = f4 << 16;
        func_0215897C(r5, (void *)func_021854B0(r6, cur, f1, &v, 1));
    }
    return 1;
}




int func_021B6BDC(u32 a, u32 b)
{
    int mode;
    u16 *out;
    void *sv;
    void *h;
    u32 heap;
    u8 *p;
    int k;
    u8 buf[0xcc];
    u32 x;

    mode = func_02159B10((void *)a, (void *)b);
    out = func_02159AE8((void *)a, (void *)b);
    sv = func_0215A5E4((void *)b);
    heap = func_0215A5CC((void *)b);
    h = func_0200A300(func_02012EBC(sv), 0, (void *)heap);
    p = func_021B7834(h, (int *)(&x), buf);
    k = func_021B7864(h);
    if (k != d_021D9970[k].id) {
        func_0200A338(h);
        return 0;
    }
    switch (mode) {
    case 0:
        if (k != 0) {
            *out = 1;
        } else {
            *out = 0;
        }
        break;
    case 1:
        *out = func_021B6D0C(k, (void *)b, sv, p);
        break;
    case 2:
        *out = func_021B6D30(k, p, (void *)b);
        break;
    case 3:
        *out = func_021B6D64(k, p, (void *)b);
        break;
    case 4:
        if (func_021B6D98(k, (void *)b, sv, p) == 1) {
            func_021B785C(h, x);
            if (func_021B6EB0((u32 *)p, k) == 1) {
                func_0216BF74(func_02012F08(sv), 1, func_02012944(sv));
            }
        }
        *out = 0;
        break;
    case 5:
        *out = func_021B6DE4(func_0201210C(func_0215A5DC((void *)b)), sv);
        break;
    case 6:
        *out = func_021B6E0C(func_0201210C(func_0215A5DC((void *)b)));
        break;
    case 7:
        *out = func_021B6DC0(k, (void *)b, sv, p);
        break;
    }
    func_0200A338(h);
    return 0;
}
