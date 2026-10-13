/*
 * file:     fldmmdl_blact.c
 * unit:     yes
 * function: func_0219C4AC, func_0219C52C, func_0219C554, func_0219C5D0, func_0219C5FC, func_0219C624, func_0219C630, func_0219C648, func_0219C658, func_0219C680, func_0219C6B8, func_0219C74C, func_0219C780, func_0219C7B4, func_0219C7EC, func_0219C814, func_0219C880, func_0219C8D4, func_0219C928, func_0219C98C, func_0219C9D0, func_0219C9DC, func_0219C9E0, func_0219CA00, func_0219CA34, func_0219CA40, func_0219CA6C, func_0219CA98, func_0219CAD8, func_0219CAF4, func_0219CB24, func_0219CB64, func_0219CB98, func_0219CBD4, func_0219CBE0, func_0219CC80, func_0219CCF0, func_0219CD68, func_0219CDAC, func_0219CE60, func_0219CEAC, func_0219CF00, func_0219CF54, func_0219CFB0, func_0219D064, func_0219D0F4, func_0219D144, func_0219D184, func_0219D1F8, func_0219D208, func_0219D2CC, func_0219D2F4, func_0219D324, func_0219D390, func_0219D3B4, func_0219D3E4, func_0219D3F0
 * address:  0x0219C4AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from fldmmdl_blact.c at 0x0219D448 (__FILE__ anchor boundary, certain cut).
 *
 * symbols:
 *   func_02046FF8  0x02046FF8  arm
 *   func_02050080  0x02050080  arm
 *   func_02047388  0x02047388  arm
 *   func_020473B8  0x020473B8  arm
 *   func_0204F044  0x0204F044  arm
 *   func_02050238  0x02050238  arm
 *   func_02046EFC  0x02046EFC  arm
 *   d_021D75C4     0x021D75C4  data  a4
 *   d_021D8064     0x021D8064  data  a4
 *   func_02050330  0x02050330  arm
 *   func_02050304  0x02050304  arm
 *   func_0204F214  0x0204F214  arm
 *   func_0216D4F8  0x0216D4F8  thumb  ov010
 *   sub_02030734   0x02030734  arm
 *   func_0216D51C  0x0216D51C  thumb  ov010
 *   func_0204ED70  0x0204ED70  arm
 *   func_0204EDB0  0x0204EDB0  arm
 *   d_021DDD70     0x021DDD70  data  a1
 *   d_021D8058     0x021D8058  data  a4
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216E2E8  0x0216E2E8  thumb  ov010
 *   func_0216E2E0  0x0216E2E0  thumb  ov010
 *   func_0216E2AC  0x0216E2AC  thumb  ov010
 *   func_02050340  0x02050340  arm
 *   func_02050804  0x02050804  arm
 *   func_0205082C  0x0205082C  arm
 *   func_020507F0  0x020507F0  arm
 *   d_021D75D0     0x021D75D0  data  a4
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   func_02197CCC  0x02197CCC  thumb  ov021
 *   func_02050894  0x02050894  arm
 *   func_020508D8  0x020508D8  arm
 *   func_02050278  0x02050278  arm
 *   func_0216DFC4  0x0216DFC4  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_02050468  0x02050468  arm
 *   func_02030734  0x02030734  arm
 *   func_0216E3C8  0x0216E3C8  thumb  ov010
 *   func_0216D518  0x0216D518  thumb  ov010
 *   func_02046E24  0x02046E24  arm
 *   func_0216D4F0  0x0216D4F0  thumb  ov010
 *   func_0216D758  0x0216D758  thumb  ov010
 *   func_02082BCC  0x02082BCC  arm
 *   func_0216D7A8  0x0216D7A8  thumb  ov010
 *   func_0216E204  0x0216E204  thumb  ov010
 *   func_0216DA30  0x0216DA30  thumb  ov010
 *   d_021D7F68  0x021D7F68  data  ov021
 *   func_020500F0  0x020500F0  arm
 */
#include "../../matched/include/Obj03116.h"
#include "../../matched/include/Obj03579.h"
#include "../../matched/include/Obj17967.h"
#include "../../matched/include/Obj07474.h"
#include "../../matched/include/Obj00429.h"
#include "../../matched/include/Obj03118.h"
#include "../../matched/include/Obj09509.h"
#include "../../matched/include/Obj17968.h"
#include "../../matched/include/Obj17969.h"
#include "../../matched/include/Obj17970.h"
#include "../../matched/include/Obj19659.h"
#include "../../matched/include/Obj02077.h"
#include "../../matched/include/Obj02698.h"
#include "../../matched/include/Obj04225.h"
#include "../../matched/include/Obj06000.h"
#include "../../matched/include/Obj19662.h"
#include "../../matched/include/Obj12672.h"
#include "../../matched/include/Obj04224.h"
#include "../../matched/include/Obj05011.h"
#include "../../matched/include/Obj19665.h"
#include "../../matched/include/Obj03580.h"
#include "../../matched/include/Obj12673.h"
#include "../../matched/include/Obj03117.h"
#include "../../matched/include/Obj07477.h"
#include "../../matched/include/Obj09512.h"
#include "../../matched/include/Obj12675.h"
#include "../../matched/include/Obj06001.h"
#include "../../matched/include/Obj12676.h"
#include "../../matched/include/Obj01353.h"
#include "../../matched/include/Obj07478.h"
#include "../../matched/include/Obj02699.h"
#include "../../matched/include/Obj03119.h"
#include "../../matched/include/Obj02700.h"

struct Board;
struct Layer;
struct Tagged;
struct Blk3;
struct Record;
struct BbActDesc;
struct BbActSys;
struct BbActRec;
struct Desc;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 a, b, c; } T12;

typedef struct { int x, y, z; } V3_0219C4AC;

typedef struct {
    u16 slot;
    u16 v12;
    u16 v14;
    u8 k;
    u8 pad;
    u32 flag;
    u32 w;
    V3_0219C4AC pos;
    void (*f1c)(u32, u32, u8 *);
    u32 f20;
} Desc;

typedef signed int     s32;

typedef struct { u16 a; u16 b; u16 c; u16 pad; } Ent;

typedef struct { int n; Ent *e; } Tbl;

typedef struct { int f0; int f4; u8 pad8[0xc]; Tbl tbl; } BlactSys;

typedef struct { u16 id; u8 pad[5]; u8 f7; u8 f8; } D;

typedef struct { u16 id; u8 pad[10]; } A;

typedef struct { u8 pad[16]; u32 f10; } B;

typedef struct { u32 f0; u8 pad[12]; u32 f10; u8 pad2[20]; } C;

typedef struct { u8 pad[4]; u16 n0; u16 n1; u16 n2; u16 pad2; A *a; B *b; C *c; } R;

typedef struct { int a; int b; int c; } S3;

typedef struct { u32 p; u16 id; u16 pad; u32 x; } Slot;

extern int func_02046FF8(int *self);
extern u32 func_02050080(u32 *p);
extern u32 func_02047388(struct Layer *layer);
extern u32 func_020473B8(struct Layer *layer);
extern int func_0204F044(struct Board *b, int w, int h, int a3, u32 a4, u8 a5, u8 a6);
extern u32 func_02050238(void *p, u32 b, u32 c);
extern void func_02046EFC(struct Tagged *p);
extern u16 func_02050330(u8 *p, int i);
extern int func_02050304(int a0, int a1);
extern void func_0204F214(u8 *a0, int i);
extern u32 func_0216D4F8(u8 *p);
extern void *sub_02030734(u32, u32, int, const char *, u16);
extern void func_0216D51C(u8 *p, u32 v);
extern void func_0204ED70(u8 *dst, struct Blk3 *src);
extern void func_0204EDB0(u8 *dst, u8 *src);
extern u32 func_0216D520(void *p);
extern u32 func_020307B0(void *p);
extern void *func_0216D67C(void *a0);
extern void func_0216E2E8(const char *ctx, u32 id, struct Record *out);
extern u16 func_0216E2E0(void *p);
extern void func_0216E2AC(u32, int, u8 *);
extern u16 func_02050340(struct BbActSys *o, u16 base, const struct BbActDesc *d, u32 count, u32 mode);
extern void func_02050804(void *p, int idx, u32 v, u16 h);
extern void func_0205082C(void *p, int idx, u32 h);
extern void func_020507F0(void *p, int idx, u32 v);
extern void *func_0216E3C4(void *p);
extern void func_02197CCC(u8 *p, s32 *out);
extern int func_02050894(void *p, int idx, int j);
extern u32 func_020508D8(u8 *o, u32 i);
extern void func_02050278(struct BbActSys *o, u32 first, u32 count);
extern int func_0216DFC4(void *a, u32 id);
extern u16 func_0216D598(void *p);
extern void func_02050468(struct BbActSys *o, u16 first, u32 count);
extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern void *func_0216E3C8(void *p);
extern u32 func_0216D518(u8 *p);
extern void *func_02046E24(u32 a0, u32 a1);
extern u16 func_0216D4F0(void *p);
extern void func_0216D758(void *a0);
extern void func_02082BCC(u8 *p, u32 a, u32 b);
extern int func_0216D7A8(void *p, unsigned int v);
extern void func_0216E204(char *a, u32 v);
extern int func_0216DA30(int a0, int a1);
extern u16 func_020500F0(struct BbActSys *o, const struct BbActRec *recs, u32 n);
int func_0219C4AC(u32 a, u32 b, u32 c, u32 d);
void func_0219C52C(u32 a, u32 b);
void func_0219C554(u32 a, u32 b, u32 c);
void func_0219C5D0(u32 a);
void func_0219C5FC(u32 a);
int func_0219C624(void *p);
int func_0219C630(void *p);
int func_0219C648(u32 a);
void func_0219C658(u32 a, u32 b);
void func_0219C680(u32 a);
u32 func_0219C6B8(u32 a, V3_0219C4AC *b, int c, u32 d, u16 e);
u32 func_0219C74C(u32 a, u16 e);
u32 func_0219C780(u32 a, V3_0219C4AC *b, int c, u32 d, u16 e, u16 g);
u32 func_0219C7B4(u32 a, u16 e, u16 g);
u32 func_0219C7EC(u32 a, u32 b);
int func_0219C814(u32 a, u16 *b);
void func_0219C880(u8 *o, u32 a, u32 b, u16 c);
void func_0219C8D4(u32 o, u32 a);
int func_0219C928(u32 a, const u8 *b, u16 *c, V3_0219C4AC *d, u32 s0, u32 s1);
void func_0219C98C(u32 a, u16 *b);
void func_0219C9D0(u32 a, u32 b, u8 *p);
u32 func_0219C9DC(u8 *p);
void func_0219C9E0(u32 a, u16 *x, u16 *y);
void func_0219CA00(u32 *s, u32 n, u32 heap);
void func_0219CA34(u8 *p);
void func_0219CA40(Tbl *t, u16 a, u16 b, u16 c);
void func_0219CA6C(Tbl *t, u16 k);
int func_0219CA98(u32 *o, u32 key, u16 *a, u16 *b);
void func_0219CAD8(u8 *a, u32 b);
void func_0219CAF4(BlactSys *s);
void func_0219CB24(BlactSys *o, u32 a, u16 b, u32 c, u8 s0, u32 s1);
void func_0219CB64(u8 *s, const D *d, u32 g);
void func_0219CB98(BlactSys *s, u16 k);
int func_0219CBD4(u32 a, u32 b, u32 c, u32 d);
void func_0219CBE0(u8 *o);
void func_0219CC80(u8 *o);
int func_0219CCF0(u8 *s);
void func_0219CD68(u8 *o, u16 a, u8 b, u8 c, u16 d, u32 e);
void func_0219CDAC(u8 *o);
int func_0219CE60(u8 *o, u32 a, u32 b, u32 c, u16 e, u32 w);
void func_0219CEAC(int *obj);
int func_0219CF00(int *t, unsigned int id, unsigned short *out);
int func_0219CF54(int *t, unsigned int id);
void func_0219CFB0(int *obj, int a1, unsigned char *src, int a3, int a5, int a6, S3 *a7);
typedef struct BlactEntry {
    u16 *res;
    int f4;
    u16 f8;
    u8 fA;
    u8 fB;
    u8 fC;
    u8 fD;
    u8 pad_E[2];
    int f10;
    void (*f14)(u32, int);
    int f18;
    V3_0219C4AC pos;
} BlactEntry;

void func_0219D064(int *obj, BlactEntry *rec);
void func_0219D0F4(int *obj);
int func_0219D144(int *obj, unsigned int a, int b);
void func_0219D184(int *obj, int key);
void func_0219D1F8(u8 *p);
void func_0219D208(int a, unsigned int id);
void func_0219D2CC(int *obj);
void func_0219D2F4(u8 *s);
void func_0219D324(int *obj, int *rec);
void func_0219D390(u8 *s);
int func_0219D3B4(u8 *s, u32 p, u16 id);
char *func_0219D3E4(int i);
unsigned short func_0219D3F0(int *o, int a1, int a2, int a3, int a4, int a5);
extern u16 d_021D75C4[][2];
extern u16 d_021D8064[];
extern unsigned char d_021DDD70[];
extern T12 d_021D8058;
extern u16 d_021D75D0[][2];
extern char d_021D7F68[];
















/*
 * Former blocker (now filed in src/matched/arm9): func_02050080 (0x02050080) is an unlabelled arm9 leaf with no witness
 * outside this range (the integrator's). Verified C, EXACT under --arm --region arm9:
 *     u32 func_02050080(u32 *p) { return p[1]; }
 */
int func_0219C4AC(u32 a, u32 b, u32 c, u32 d)
{
    int r = -1;
    if (func_02046FF8((int *)b) == 1) {
        u32 x = func_02050080((u32 *)a);
        u16 *e = d_021D75C4[c];
        u32 w = func_02047388((struct Layer *)b);
        r = func_02050238((void *)a, func_0204F044((struct Board *)x, w, func_020473B8((struct Layer *)b), 0, d_021D8064[d], (u8)e[0], (u8)e[1]), 0);
        func_02046EFC((struct Tagged *)b);
    }
    return r;
}
















void func_0219C52C(u32 a, u32 b)
{
    u32 x = func_02050330((u8 *)a, b);
    u32 y = func_02050080((u32 *)a);
    func_02050304(a, b);
    func_0204F214((u8 *)y, x);
}
















void func_0219C554(u32 a, u32 b, u32 c)
{
    u8 *p = sub_02030734(func_0216D4F8((u8 *)a), 0x24, 1, (const char *)d_021DDD70, 360);
    u32 h;
    T12 t;
    u8 z;
    ((struct Obj03116 *)p)->f10 = a;
    ((struct Obj03116 *)p)->f4 = b;
    ((struct Obj03116 *)p)->f2 = c;
    func_0216D51C((u8 *)a, (u32)p);
    func_0219CAD8(p, c);
    func_0219CBE0(p);
    func_0219D2CC((int *)p);
    h = func_02050080((u32 *)b);
    t = d_021D8058;
    func_0204ED70((u8 *)h, (struct Blk3 *)(&t));
    z = 0;
    func_0204EDB0((u8 *)h, &z);
}
















void func_0219C5D0(u32 a)
{
    u32 s = func_0216D520((void *)a);
    func_0219D2F4((u8 *)s);
    func_0219CC80((u8 *)s);
    func_0219CAF4((BlactSys *)s);
    func_020307B0((void *)s);
    func_0216D51C((u8 *)a, 0);
}
















void func_0219C5FC(u32 a)
{
    u8 *s = (u8 *)func_0216D520((void *)a);
    if (s != 0) {
        if (*(u32 *)&((struct Obj03579 *)s)->f1C != 0) {
            func_0219D0F4((int *)s);
            func_0219CDAC(s);
        }
        func_0219D390(s);
        s[0] = 0;
    }
}
















/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219C624(void *p)
{
func_0219CEAC((int *)func_0216D520(p));
}
















int func_0219C630(void *p)
{
if (func_0219CCF0((u8 *)func_0216D520(p)) == 1) {
    return 1;
}
return 0;
}
















int func_0219C648(u32 a)
{
return ((struct Obj17967 *)((u8 *)(func_0216D520(func_0216D67C((void *)a)))))->f0;
}
















void func_0219C658(u32 a, u32 b)
{
    u8 buf[28];
    u8 *s = (u8 *)func_0216D520((void *)a);
    func_0216E2E8((const char *)a, b, (struct Record *)buf);
    func_0219CB64(s, (const D *)buf, 0);
}
















/*
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 */
void func_0219C680(u32 a)
{
    u8 buf[28];
    u8 *s = (u8 *)func_0216D520((void *)a);
    int n = func_0216E2E0((void *)a);
    int i;
    for (i = 0; i < n; i++) {
        func_0216E2AC(a, i, buf);
        func_0219CB64(s, (const D *)buf, 0);
    }
}
















/*
 * Former blocker (now filed in src/matched/arm9): func_0205082C (0x0205082C) and func_020507F0 (0x020507F0) are
 * unlabelled arm9 leaves (the integrator's), no witness outside this range. Verified C,
 * both EXACT under --arm --region arm9 (func_020500A0 is the arm9 label at 0x020500A0):
 *     void func_020507F0(void *p, int idx, u32 v)
 *     { char *e = (char *)(*(u32 *)((char *)p + 24) + idx * 40); *(u32 *)(e + 24) = v; }
 *     void func_0205082C(void *p, int idx, u16 h)
 *     { char *e = (char *)(*(u32 *)((char *)p + 24) + idx * 40); *(u16 *)(e + 14) = h; func_020500A0(e); }
 * func_0219C9D0 (function pointer word) is filed as pkt_ov021_0219C9D0.
 */
u32 func_0219C6B8(u32 a, V3_0219C4AC *b, int c, u32 d, u16 e)
{
    u8 *m = (u8 *)func_0216D520((void *)a);
    Desc s;
    u32 r;
    u32 *q;
    u16 *t = d_021D75D0[c];
    u32 h;
    s.slot = e;
    s.v12 = d_021D75D0[c][0];
    s.v14 = t[1];
    s.pos = *b;
    s.k = 0x1f;
    s.flag = 1;
    s.w = 1;
    s.f1c = func_0219C9D0;
    s.f20 = (u32)m;
    r = func_02050340((struct BbActSys *)(((struct Obj07474 *)m)->f4), ((struct Obj07474 *)m)->f8, (const struct BbActDesc *)(&s), 1, 0);
    q = (u32 *)func_0219D3E4(d);
    if (q[0] != 0) {
        func_02050804((void *)(((struct Obj07474 *)m)->f4), r, q[0], (u16)q[1]);
        h = ((struct Obj07474 *)m)->f4;
        func_0205082C((void *)h, r, 0);
        func_020507F0((void *)h, r, 1);
    }
    return r;
}
















u32 func_0219C74C(u32 a, u16 e)
{
    u32 o = (u32)func_0216D67C((void *)a);
    u8 *d = func_0216E3C4((void *)a);
    V3_0219C4AC v;
    func_02197CCC((u8 *)a, (s32 *)(&v));
    return func_0219C6B8(o, &v, d[7], d[9], e);
}
















u32 func_0219C780(u32 a, V3_0219C4AC *b, int c, u32 d, u16 e, u16 g)
{
    u32 r = func_0219C6B8(a, b, c, d, e);
    if (g != 0xFFFF) {
        func_02050894((void *)(*(u32 *)(func_0216D520((void *)a) + 4)), r, g);
    }
    return r;
}
















u32 func_0219C7B4(u32 a, u16 e, u16 g)
{
    u32 o = (u32)func_0216D67C((void *)a);
    u8 *d = func_0216E3C4((void *)a);
    V3_0219C4AC v;
    func_02197CCC((u8 *)a, (s32 *)(&v));
    return func_0219C780(o, &v, d[7], d[9], e, g);
}
















u32 func_0219C7EC(u32 a, u32 b)
{
    u16 t[2];
    func_0219CBD4(func_0216D520(func_0216D67C((void *)a)), b, (u32)(&t[1]), (u32)(&t[0]));
    return func_0219C74C(a, t[1]);
}

















int func_0219C814(u32 a, u16 *b)
{
    u32 m = func_0216D520(func_0216D67C((void *)a));
    u16 *p = func_0216E3C4((void *)a);
    u16 loc[2];
    func_0219CBD4(m, *p, (u32)(&loc[1]), (u32)(&loc[0]));
    if (loc[1] != 0xFFFF && (2 & loc[0]) == 0) {
        *b = func_0219C7EC(a, *p);
        return 1;
    }
    *b = 0xFFFF;
    func_0219CFB0((int *)m, a, (u8 *)p, (int)b, 0, 0, 0);
    return 0;
}

















/*
 * Former blocker (now filed in src/matched/arm9): the only unresolved site is the call to func_020508D8
 * (0x020508D8, arm, arm9), an unlabelled arm9 leaf with no witness (the integrator's).
 * Verified C for the leaf (EXACT, dsi/1.1p1 -O4,p --arm --region arm9):
 *     u32 func_020508D8(u8 *o, u32 i)
 *     {
 *         return *(u16 *)(*(u8 **)(o + 0x18) + i * 0x28 + 4);
 *     }
 *
 * Addresses are Black-image addresses.
 */
void func_0219C880(u8 *o, u32 a, u32 b, u16 c)
{
    u16 v[2];
    if (func_0219CBD4((u32)o, c, (u32)(&v[1]), (u32)(&v[0])) == 1) {
        if (v[0] & 2) {
            u32 t = func_020508D8((u8 *)(((struct Obj00429 *)o)->f4), b);
            func_02050278((struct BbActSys *)(((struct Obj00429 *)o)->f4), t, 1);
        }
        if (v[0] & 1) {
            if (func_0216DFC4((void *)a, c) == 0)
                func_0219CB98((BlactSys *)o, c);
        }
    }
}

















/*
 * Addresses are Black-image addresses.
 */
void func_0219C8D4(u32 o, u32 a)
{
    u16 t = func_0216D598((void *)o);
    u8 *c = (u8 *)func_0216D520(func_0216D67C((void *)o));
    if (a == 0xFFFF) {
        func_0219D184((int *)c, (u32)o);
        return;
    }
    if (func_0219D3B4(c, o, a) != 1) {
        func_0219C880(c, o, (u16)a, t);
        func_02050468((struct BbActSys *)(((struct Obj00429 *)c)->f4), a, 1);
    }
}

















/* b is const: that is what lets the b[7]/b[9] loads schedule above the
 * outgoing stack-argument store of v. */
int func_0219C928(u32 a, const u8 *b, u16 *c, V3_0219C4AC *d, u32 s0, u32 s1)
{
    u16 v;
    u32 t = func_0216D520((void *)a);
    func_0219CBD4(t, *(const u16 *)&((struct Obj03118 *)b)->f0, (u32)(&v), (u32)c);
    if (!(*c & 2)) {
        c[1] = func_0219C6B8(a, d, b[7], b[9], v);
        return 1;
    }
    c[1] = 0xFFFF;
    func_0219CFB0((int *)t, 0, (u8 *)b, (int)&c[1], s0, s1, (S3 *)d);
    return 0;
}

















void func_0219C98C(u32 a, u16 *b)
{
    u8 *c = (u8 *)func_0216D520((void *)a);
    if (b[1] != 0xFFFF) {
        if (b[0] & 2) {
            u32 t = func_020508D8((u8 *)(((struct Obj09509 *)c)->f4), b[1]);
            func_02050278((struct BbActSys *)(((struct Obj09509 *)c)->f4), t, 1);
        }
        func_02050468((struct BbActSys *)(((struct Obj09509 *)c)->f4), b[1], 1);
    }
    b[0] = 0;
    b[1] = 0xFFFF;
}

















void func_0219C9D0(u32 a, u32 b, u8 *p)
{
    *p |= 1;
}

















/*
 * Loads the 32-bit word at byte +0x4 of the object.
 */
u32 func_0219C9DC(u8 *p)
{
    return ((struct Obj17968 *)p)->f4;
}

















void func_0219C9E0(u32 a, u16 *x, u16 *y)
{
    u8 *d = func_0216E3C4((void *)a);
    u16 *t = d_021D75D0[d[7]];
    *x = t[0];
    *y = t[1];
}

















void func_0219CA00(u32 *s, u32 n, u32 heap)
{
    u16 *p = (u16 *)func_02030734(heap, n * 8, 1, (const char *)d_021DDD70, 0x484);
    s[0] = n;
    s[1] = (u32)p;
    do {
        p[0] = 0xFFFF;
        p[1] = 0xFFFF;
        p += 4;
    } while (--n);
}

















/*
 * Tail-call thunk: the object's word at +0x4.
 *
 * Addresses are Black-image addresses.
 */
void func_0219CA34(u8 *p)
{
    func_020307B0((void *)(((struct Obj17969 *)p)->f4));
}
















void func_0219CA40(Tbl *t, u16 a, u16 b, u16 c)
{
    int i;
    Ent *e = t->e;
    i = 0;
    do {
        if (e->a == 0xFFFF) {
            e->a = a;
            e->b = b;
            e->c = c;
            return;
        }
        i++;
        e++;
    } while (i < t->n);
}
















void func_0219CA6C(Tbl *t, u16 k)
{
    int i;
    Ent *e = t->e;
    i = 0;
    do {
        if (e->a == k) {
            e->a = 0xFFFF;
            e->b = 0xFFFF;
            e->c = 0;
            return;
        }
        i++;
        e++;
    } while (i < t->n);
}
















/*
 * Linear search of an 8-byte-entry table (count at +0, entries at *(+4)).
 *
 * Addresses are Black-image addresses.
 */
int func_0219CA98(u32 *o, u32 key, u16 *a, u16 *b)
{
    int i = 0;
    u16 *e = (u16 *)o[1];
    if (a) *a = 0xFFFF;
    do {
        if (e[0] == key) {
            if (a) *a = e[1];
            if (b) *b = e[2];
            return 1;
        }
        i++;
        e += 4;
    } while (i < (int)o[0]);
    return 0;
}














/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216D4F8 (0x0216D4F8) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
void func_0219CAD8(u8 *a, u32 b)
{
    func_0219CA00((u32 *)(a + 20), b, func_0216D4F8((u8 *)((struct Obj17970 *)a)->f10));
}














void func_0219CAF4(BlactSys *s)
{
    int i;
    Ent *e = s->tbl.e;
    i = 0;
    do {
        if (e->a != 0xFFFF) {
            func_0219CB98(s, e->a);
        }
        i++;
        e++;
    } while (i < s->tbl.n);
    func_0219CA34((u8 *)&s->tbl);
}














/*
 * Addresses are Black-image addresses.
 */
void func_0219CB24(BlactSys *o, u32 a, u16 b, u32 c, u8 s0, u32 s1)
{
    int r = -1;
    u16 t;
    if (s1 & 2) r = 2;
    t = func_0219D3F0((int *)o, b, c, s0, a, r);
    func_0219CA40(&o->tbl, b, t, (u16)s1);
}





















void func_0219CB64(u8 *s, const D *d, u32 g)
{
    u16 *q = func_0216E3C8((void *)d);
    func_0219CB24((BlactSys *)s, (u32)func_02046E24(func_0216D518((u8 *)(((struct Obj19659 *)s)->f10)), *q), d->id, d->f7, d->f8, g);
}





















void func_0219CB98(BlactSys *s, u16 k)
{
    u16 t[2];
    func_0219CA98((u32 *)&s->tbl, k, &t[0], &t[1]);
    if (t[1] & 2) {
        func_02050278((struct BbActSys *)(s->f4), t[0], 1);
    } else {
        func_0219C52C(s->f4, t[0]);
    }
    func_0219CA6C(&s->tbl, k);
}





















/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219CBD4(u32 a, u32 b, u32 c, u32 d)
{
return func_0219CA98((u32 *)(a + 20), b, (u16 *)c, (u16 *)d);
}





















/*
 * Addresses are Black-image addresses.
 */
void func_0219CBE0(u8 *o)
{
    u32 h = func_0216D4F8((u8 *)(((struct Obj03116 *)o)->f10));
    u8 *p = func_02030734(h, 0x18, 1, (const char *)d_021DDD70, 1491);
    u16 *e;
    int i;
    ((struct Obj02077 *)p)->f4 = ((struct Obj03116 *)o)->f2;
    ((struct Obj02077 *)p)->f8 = func_0216D4F0((void *)(((struct Obj03116 *)o)->f10));
    ((struct Obj02077 *)p)->f6 = 1;
    e = (u16 *)func_02030734(h, 0xc * ((struct Obj02077 *)p)->f4, 1, (const char *)d_021DDD70, 1498);
    *(u16 * *)&((struct Obj02077 *)p)->fC = e;
    i = 0;
    if (i < ((struct Obj02077 *)p)->f4) {
        for (; i < ((struct Obj02077 *)p)->f4; i++, e += 6)
            *e = 0xFFFF;
    }
    ((struct Obj02077 *)p)->f10 = (u32)func_02030734(h, 0x14 * ((struct Obj02077 *)p)->f6, 1, (const char *)d_021DDD70, 1511);
    ((struct Obj02077 *)p)->f14 = (u32)func_02030734(h, 0x28 * ((struct Obj02077 *)p)->f8, 1, (const char *)d_021DDD70, 1513);
    ((struct Obj02077 *)p)->f0 = 1;
    *(u8 * *)&((struct Obj03116 *)o)->f1C = p;
}





















void func_0219CC80(u8 *o)
{
    u8 *c = *(u8 * *)&((struct Obj04225 *)o)->f1C;
    u32 i;
    u32 n;
    u8 *p;
    if (c == 0) return;
    i = 0;
    ((struct Obj02698 *)c)->f0 = i;
    func_020307B0((void *)(((struct Obj02698 *)c)->fC));
    p = *(u8 * *)&((struct Obj02698 *)c)->f10;
    if (i < ((struct Obj02698 *)c)->f6) {
        for (; i < ((struct Obj02698 *)c)->f6; i++, p += 0x14) {
            if (((struct Obj06000 *)p)->f10 != 0)
                func_02046EFC((struct Tagged *)(((struct Obj06000 *)p)->f10));
        }
    }
    func_020307B0((void *)(*(u32 *)&((struct Obj02698 *)c)->f10));
    i = 0;
    p = *(u8 * *)&((struct Obj02698 *)c)->f14;
    if (i < ((struct Obj02698 *)c)->f8) {
        for (; i < ((struct Obj02698 *)c)->f8; i++, p += 0x28) {
            if (((struct Obj06000 *)p)->f0 != 0 && ((struct Obj06000 *)p)->f10 != 0)
                func_02046EFC((struct Tagged *)(((struct Obj06000 *)p)->f10));
        }
    }
    func_020307B0((void *)(*(u32 *)&((struct Obj02698 *)c)->f14));
    func_020307B0((void *)((u32)c));
    *(u32 *)&((struct Obj04225 *)o)->f1C = 0;
}





















/*
 * The record pointers are const: mwcc then rereads each u16 count inside its
 * loop and keeps r in r0 instead of hoisting the count into a register.
 */
int func_0219CCF0(u8 *s)
{
    const R *r = *(const R * *)&((struct Obj19662 *)s)->f1C;
    u32 i;
    const A *a;
    const B *b;
    const C *c;

    a = r->a;
    for (i = 0; i < r->n0; i++, a++) {
        if (a->id != 0xFFFF) {
            return 1;
        }
    }
    b = r->b;
    for (i = 0; i < r->n1; i++, b++) {
        if (b->f10 != 0) {
            return 1;
        }
    }
    c = r->c;
    for (i = 0; i < r->n2; i++, c++) {
        if (c->f0 != 0 && c->f10 != 0) {
            return 1;
        }
    }
    return 0;
}





















/*
 * Fills the first free 0xC-byte entry (tag 0xFFFF... see pool) of the table.
 *
 * Addresses are Black-image addresses.
 */
void func_0219CD68(u8 *o, u16 a, u8 b, u8 c, u16 d, u32 e)
{
    u8 *ctx = *(u8 * *)&((struct Obj00429 *)o)->f1C;
    u32 i;
    u32 n = ((struct Obj12672 *)ctx)->f4;
    o = *(u8 * *)&((struct Obj12672 *)ctx)->fC;
    for (i = 0; i < n; i++, o += 0xc) {
        if (((struct Obj00429 *)o)->f0 == 0xFFFF) {
            ((struct Obj00429 *)o)->f0 = a;
            *(u8 *)&((struct Obj00429 *)o)->f4 = b;
            *(u8 *)(o + 5) = c;
            ((struct Obj00429 *)o)->f2 = d;
            ((struct Obj00429 *)o)->f8 = e;
            return;
        }
    }
}





















/*
 * Commits pending 0xC-byte entries through func_0219CE60, then compacts the
 * table so the free (0xFFFF) entries sit at the end.
 *
 * Addresses are Black-image addresses.
 */
void func_0219CDAC(u8 *o)
{
    u8 *ctx = *(u8 * *)&((struct Obj03579 *)o)->f1C;
    u32 j = 0;
    u32 k = 0;
    u8 *e = *(u8 * *)&((struct Obj05011 *)ctx)->fC;
    u8 *base;
    for (; j < ((struct Obj05011 *)ctx)->f4; j++, e += 0xc) {
        if (((struct Obj04224 *)e)->f0 != 0xFFFF) {
            if (func_0219CE60(o, ((struct Obj04224 *)e)->f0, e[4], e[5], ((struct Obj04224 *)e)->f2, ((struct Obj04224 *)e)->f8) == 0)
                break;
            ((struct Obj04224 *)e)->f0 = 0xFFFF;
            k++;
            if (k >= ((struct Obj05011 *)ctx)->f6)
                break;
        }
    }
    if (k != 0) {
        j = 0;
        base = *(u8 * *)&((struct Obj05011 *)ctx)->fC;
        for (; j < (u32)((struct Obj05011 *)ctx)->f4 - 1; j++) {
            T12 *ent = (T12 *)(base + 12 * j);
            if (((struct Obj19665 *)ent)->f0 == 0xFFFF) {
                for (k = j + 1; k < ((struct Obj05011 *)ctx)->f4; k++) {
                    if (*(u16 *)(base + 12 * k) != 0xFFFF) {
                        *ent = *(T12 *)(base + 12 * k);
                        *(u16 *)(base + 12 * k) = 0xFFFF;
                        break;
                    }
                }
            }
        }
    }
}





















/*
 * Claims the first free 0x14-byte slot of the table at *(*(+0x1c)+0x10).
 *
 * Addresses are Black-image addresses.
 */
int func_0219CE60(u8 *o, u32 a, u32 b, u32 c, u16 e, u32 w)
{
    u8 *ctx = *(u8 * *)&((struct Obj03579 *)o)->f1C;
    u8 *p = *(u8 * *)&((struct Obj12673 *)ctx)->f10;
    u32 i;
    for (i = 0; i < ((struct Obj12673 *)ctx)->f6; i++, p += 0x14) {
        if (((struct Obj03580 *)p)->f10 == 0) {
            ((struct Obj03580 *)p)->f0 = 0;
            ((struct Obj03580 *)p)->f8 = a;
            ((struct Obj03580 *)p)->fA = b;
            ((struct Obj03580 *)p)->fB = c;
            ((struct Obj03580 *)p)->f4 = w;
            ((struct Obj03580 *)p)->f10 = (u32)func_02046E24(func_0216D518((u8 *)(((struct Obj03579 *)o)->f10)), e);
            ((struct Obj03580 *)p)->f0 = 1;
            return 1;
        }
    }
    return 0;
}





















void func_0219CEAC(int *obj)
{
    unsigned int i;
    int *p;
    int *t;

    t = (int *)obj[7];
    if (t != 0 && t[0] == 1) {
        i = 0;
        p = (int *)t[4];
        if (!(i < ((struct Obj07477 *)t)->f6)) {
            return;
        }
        for (; i < ((struct Obj07477 *)t)->f6; i++, p += 5) {
            if (p[4] != 0 && ((struct Obj03117 *)p)->f0 == 1) {
                ((struct Obj03117 *)p)->f0 = 0;
                func_0219CB24((BlactSys *)obj, p[4], ((struct Obj03117 *)p)->f8, *((unsigned char *)p + 0xa),
                              *((unsigned char *)p + 0xb), p[1]);
                p[4] = 0;
            }
        }
    }
}





















int func_0219CF00(int *t, unsigned int id, unsigned short *out)
{
    unsigned int i;
    unsigned char *p;
    unsigned int n;
    unsigned int j;
    unsigned char *q;
    unsigned int m;

    t = (int *)t[7];
    i = 0;
    n = *(unsigned short *)&((struct Obj00429 *)t)->f4;
    p = (unsigned char *)t[3];
    for (; i < n; i++, p += 12) {
        if (((struct Obj12675 *)p)->f0 == id) {
            *out = ((struct Obj12675 *)p)->f8;
            return 1;
        }
    }
    m = *(unsigned short *)((char *)t + 6);
    j = 0;
    q = (unsigned char *)t[4];
    for (; j < m; j++, q += 20) {
        if (((struct Obj09512 *)q)->f8 == id && ((struct Obj09512 *)q)->f10 != 0) {
            *out = ((struct Obj09512 *)q)->f4;
            return 1;
        }
    }
    return 0;
}





















int func_0219CF54(int *t, unsigned int id)
{
    unsigned int i;
    unsigned char *p;
    unsigned int n;
    unsigned int j;
    unsigned char *q;
    unsigned int m;

    t = (int *)t[7];
    i = 0;
    n = *(unsigned short *)&((struct Obj00429 *)t)->f4;
    p = (unsigned char *)t[3];
    for (; i < n; i++, p += 12) {
        if (((struct Obj12676 *)p)->f0 == id) {
            ((struct Obj12676 *)p)->f0 = 0xFFFF;
            return 1;
        }
    }
    m = *(unsigned short *)((char *)t + 6);
    j = 0;
    q = (unsigned char *)t[4];
    for (; j < m; j++, q += 20) {
        if (*(int *)&((struct Obj06001 *)q)->f10 != 0 && ((struct Obj06001 *)q)->f8 == id) {
            *q = 0;
            func_02046EFC(((struct Obj06001 *)q)->f10);
            *(int *)&((struct Obj06001 *)q)->f10 = 0;
            return 1;
        }
    }
    return 0;
}





















void func_0219CFB0(int *obj, int a1, unsigned char *src, int a3, int a5, int a6, S3 *a7)
{
    unsigned int i;
    unsigned int n;
    int *p;
    unsigned short v[2];
    unsigned short *t;

    i = 0;
    n = func_0216D4F0((void *)obj[4]);
    p = *(int **)(obj[7] + 0x14);
    for (; i < n; i++, p += 10) {
        if (p[0] == 0) {
            *((unsigned char *)p + 0xd) = 0;
            p[1] = a1;
            p[0] = a3;
            ((struct Obj01353 *)p)->f8 = ((struct Obj03118 *)src)->f0;
            *((unsigned char *)p + 0xa) = src[7];
            *((unsigned char *)p + 0xb) = src[8];
            *((unsigned char *)p + 0xc) = src[9];
            func_0219CBD4((u32)obj, ((struct Obj01353 *)p)->f8, (u32)(&v[1]), (u32)(&v[0]));
            if (v[1] == 0xFFFF && func_0219CF00(obj, ((struct Obj01353 *)p)->f8, &v[0]) == 0) {
                t = func_0216E3C8(src);
                v[0] = 1;
                func_0219CD68((u8 *)obj, ((struct Obj01353 *)p)->f8, *((unsigned char *)p + 0xa),
                              *((unsigned char *)p + 0xb), *t, 1);
            }
            p[5] = a5;
            p[6] = a6;
            if (a7 != 0) {
                *(S3 *)(p + 7) = *a7;
            }
            *((unsigned char *)p + 0xd) = 1;
            return;
        }
    }
}





















void func_0219D064(int *obj, BlactEntry *rec)
{
    unsigned short x[3];
    u32 r;

    x[0] = 0xFFFF;
    rec->fD = 0;
    if (rec->f10 != 0) {
        x[2] = func_0219D3F0(obj, rec->f8, rec->fA,
                             rec->fB, rec->f10, 1);
        rec->f10 = 0;
        func_0219CBD4((u32)obj, rec->f8, (u32)(&x[0]), (u32)(&x[1]));
    } else {
        func_0219CBD4((u32)obj, rec->f8, (u32)(&x[2]), (u32)(&x[1]));
    }
    if (rec->f4 != 0) {
        r = func_0219C7B4(rec->f4, x[2], x[0]);
    } else {
        r = func_0219C780(obj[4], &rec->pos, rec->fA,
                          rec->fC, x[2], x[0]);
    }
    *rec->res = r;
    if (rec->f14 != 0) {
        rec->f14(*rec->res, rec->f18);
    }
    if (rec->f4 != 0) {
        func_0216D758((void *)rec->f4);
    }
}





















void func_0219D0F4(int *obj)
{
    unsigned int i;
    unsigned int n;
    BlactEntry *p;
    unsigned short sp[2];

    i = 0;
    n = func_0216D4F0((void *)obj[4]);
    p = *(BlactEntry **)(obj[7] + 0x14);
    if (n == 0) {
        return;
    }
    for (; i < n; i++, p++) {
        if (p->res != 0 && p->fD == 1) {
            if (func_0219CBD4((u32)obj, p->f8, (u32)(&sp[0]), (u32)(&sp[1])) == 1) {
                func_0219D064(obj, p);
                func_0219D1F8((u8 *)p);
            }
        }
    }
}





















int func_0219D144(int *obj, unsigned int a, int b)
{
    unsigned int i;
    unsigned int n;
    int *p;

    i = 0;
    n = func_0216D4F0((void *)obj[4]);
    p = *(int **)(obj[7] + 0x14);
    for (; i < n; i++, p += 10) {
        if (p[0] != 0 && p[1] != 0 && p[1] != b && ((struct Obj07478 *)p)->f8 == a) {
            return 1;
        }
    }
    return 0;
}





















void func_0219D184(int *obj, int key)
{
    unsigned int i;
    unsigned int n;
    int *p;
    unsigned short s;

    i = 0;
    n = func_0216D4F0((void *)obj[4]);
    p = *(int **)(obj[7] + 0x14);
    for (; i < n; i++, p += 10) {
        if (p[0] != 0 && p[1] == key) {
            *((unsigned char *)p + 0xd) = 0;
            if (func_0219CF00(obj, ((struct Obj02699 *)p)->f8, &s) == 1 && (s & 1)) {
                if (func_0219D144(obj, ((struct Obj02699 *)p)->f8, p[1]) == 0) {
                    func_0219CF54(obj, ((struct Obj02699 *)p)->f8);
                }
            }
            if (p[4] != 0) {
                func_02046EFC((void *)p[4]);
                p[4] = 0;
            }
            func_0219D1F8((u8 *)p);
            return;
        }
    }
}





















/*
 * Clears the byte at +0xd, then tail calls with 0 and 0x28.
 *
 * Addresses are Black-image addresses.
 */
void func_0219D1F8(u8 *p)
{
    p[0xd] = 0;
    func_02082BCC(p, 0, 0x28);
}





















void func_0219D208(int a, unsigned int id)
{
    int *ctx;
    int i;
    unsigned char *r;
    unsigned short h;
    unsigned short v[2];

    ctx = (int *)func_0216D520(func_0216D67C((void *)a));
    r = (unsigned char *)ctx[8];
    func_0219CBD4((u32)ctx, id, (u32)(&v[1]), (u32)(&v[0]));
    if (v[1] != 0xFFFF && !(v[0] & 2)) {
        func_0216E204((char *)a, id);
        return;
    }
    i = 0;
    h = func_0216D7A8((void *)a, 0);
    if (h == 0xFFFF) {
        func_0216E204((char *)a, id);
        return;
    }
    for (; i < 4; i++) {
        if (((struct Obj03119 *)r)->f0 == 0) {
            break;
        }
    }
    if (i >= 4) {
        func_0216E204((char *)a, id);
        return;
    }
    ((struct Obj03119 *)r)->f0 = a;
    ((struct Obj03119 *)r)->f4 = h;
    ((struct Obj03119 *)r)->f6 = func_0216D598((void *)a);
    ((struct Obj03119 *)r)->f8 = id;
    func_0216E204((char *)a, id);
    i = 0;
    if (func_0216D7A8((void *)a, 0) != 0xFFFF) {
        func_0219C880((u8 *)ctx, a, ((struct Obj03119 *)r)->f4, ((struct Obj03119 *)r)->f6);
        func_02050468((struct BbActSys *)ctx[1], ((struct Obj03119 *)r)->f4, 1);
        ((struct Obj03119 *)r)->f0 = i;
    }
}




















/*
 * Promoted 2026-09-27 (lane ov010 blocker tree).  The call at +0x08 is a
 * Thumb `bl` (d0 f7 10 f9), not an interworking `blx`: the target must be
 * Thumb.  The old header called 0x0216D4F8 `arm ov009`, but ov009's byte
 * there is an ARM fragment with no start, while ov010 holds an EXACT Thumb
 * getter (src/matched/func_0216D4F8.c, shard layout/matched/ov010/
 * pkt_0216D4F8.json).  With the region/ISA hint fixed to `thumb ov010` the
 * site resolves as `matched` and the entry is EXACT.
 */
void func_0219D2CC(int *obj)
{
    ((struct Obj03116 *)obj)->f20 =
        (int)func_02030734(func_0216D4F8((u8 *)obj[4]), 0x30, 1, (const char *)d_021DDD70, 0x979);
}




















void func_0219D2F4(u8 *s)
{
    Slot *e = *(Slot * *)&((struct Obj04225 *)s)->f20;
    int i;
    if (e != 0) {
        for (i = 0; i < 4; i++, e++) {
            if (e->p != 0) {
                func_02050468((struct BbActSys *)(((struct Obj04225 *)s)->f4), e->id, 1);
                e->p = 0;
            }
        }
        func_020307B0(((struct Obj04225 *)s)->f20);
    }
}




















void func_0219D324(int *obj, int *rec)
{
    int h;
    unsigned short n;

    h = rec[0];
    if (func_0216DA30(h, (int)rec) == 0) {
        func_0219C880((u8 *)obj, h, ((struct Obj02700 *)rec)->f4, *((unsigned short *)(rec + 1) + 1));
        func_02050468((struct BbActSys *)obj[1], ((struct Obj02700 *)rec)->f4, 1);
        rec[0] = 0;
        return;
    }
    if ((unsigned short)func_0216D7A8((void *)h, 0) != 0xFFFF) {
        n = *((unsigned short *)(rec + 1) + 1);
        if (n != func_0216D598((void *)h)) {
            func_0219C880((u8 *)obj, h, ((struct Obj02700 *)rec)->f4, n);
        }
        func_02050468((struct BbActSys *)obj[1], ((struct Obj02700 *)rec)->f4, 1);
        rec[0] = 0;
    }
}




















void func_0219D390(u8 *s)
{
    Slot *e = *(Slot * *)&((struct Obj03579 *)s)->f20;
    int i;
    if (e != 0) {
        for (i = 0; i < 4; i++, e++) {
            if (e->p != 0) {
                func_0219D324((int *)s, (int *)e);
            }
        }
    }
}




















int func_0219D3B4(u8 *s, u32 p, u16 id)
{
    Slot *e = *(Slot * *)&((struct Obj00429 *)s)->f20;
    int i;
    if (e != 0) {
        for (i = 0; i < 4; i++, e++) {
            if (e->p != 0 && e->p == p && e->id == id) {
                return 1;
            }
        }
    }
    return 0;
}




















/*
 * Indexes an array of 8-byte records based at 0x021D7F68.
 */
char *func_0219D3E4(int i)
{
    return d_021D7F68 + i * 8;
}




















unsigned short func_0219D3F0(int *o, int a1, int a2, int a3, int a4, int a5)
{
    unsigned short *q;
    struct {
        int w0;
        unsigned char b4;
        unsigned char b5;
        unsigned char b6;
        unsigned char b7;
        int w2;
    } s;

    if (a5 == -1) {
        return (unsigned short)func_0219C4AC(o[1], a4, a2, a3);
    }
    s.w0 = a4;
    s.b4 = 0;
    s.b5 = d_021D8064[a3];
    q = d_021D75C4[a2];
    s.b6 = q[0];
    s.b7 = q[1];
    s.w2 = a5;
    return func_020500F0((struct BbActSys *)o[1], (const struct BbActRec *)(&s), 1);
}
