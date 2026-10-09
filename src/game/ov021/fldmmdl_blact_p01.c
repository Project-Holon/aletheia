/*
 * file:     fldmmdl_blact_p01.c
 * unit:     yes
 * function: func_0219C4AC, func_0219C52C, func_0219C554, func_0219C5D0, func_0219C5FC, func_0219C624, func_0219C630, func_0219C648, func_0219C658, func_0219C680, func_0219C6B8, func_0219C74C, func_0219C780, func_0219C7B4, func_0219C7EC
 * address:  0x0219C4AC
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
 *   func_0219CAD8  0x0219CAD8  thumb  ov021
 *   func_0219CBE0  0x0219CBE0  thumb  ov021
 *   func_0219D2CC  0x0219D2CC  thumb  ov021
 *   func_0204ED70  0x0204ED70  arm
 *   func_0204EDB0  0x0204EDB0  arm
 *   d_021DDD70     0x021DDD70  data  a1
 *   d_021D8058     0x021D8058  data  a4
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_0219D2F4  0x0219D2F4  thumb  ov021
 *   func_0219CC80  0x0219CC80  thumb  ov021
 *   func_0219CAF4  0x0219CAF4  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_0219D0F4  0x0219D0F4  thumb  ov021
 *   func_0219CDAC  0x0219CDAC  thumb  ov021
 *   func_0219D390  0x0219D390  thumb  ov021
 *   func_0219CEAC  0x0219CEAC  thumb  ov021
 *   func_0219CCF0  0x0219CCF0  thumb  ov021
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216E2E8  0x0216E2E8  thumb  ov010
 *   func_0219CB64  0x0219CB64  thumb  ov021
 *   func_0216E2E0  0x0216E2E0  thumb  ov010
 *   func_0216E2AC  0x0216E2AC  thumb  ov010
 *   func_02050340  0x02050340  arm
 *   func_0219D3E4  0x0219D3E4  thumb  ov021
 *   func_02050804  0x02050804  arm
 *   func_0205082C  0x0205082C  arm
 *   func_020507F0  0x020507F0  arm
 *   func_0219C9D0  0x0219C9D0  thumb  ov021
 *   d_021D75D0     0x021D75D0  data  a4
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   func_02197CCC  0x02197CCC  thumb  ov021
 *   func_02050894  0x02050894  arm
 *   func_0219CBD4  0x0219CBD4  thumb  ov021
 */
#include "../../matched/include/Obj03116.h"
#include "../../matched/include/Obj03579.h"
#include "../../matched/include/Obj17967.h"
#include "../../matched/include/Obj07474.h"

struct Board;
struct Layer;
struct Tagged;
struct Blk3;
struct Record;
struct BbActDesc;
struct BbActSys;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef signed char    s8;

typedef struct { u32 a, b, c; } T12;

typedef struct { int x, y, z; } V3;

typedef struct {
    u16 slot;
    u16 v12;
    u16 v14;
    u8 k;
    u8 pad;
    u32 flag;
    u32 w;
    V3 pos;
    void (*f1c)(void);
    u32 f20;
} Desc;

typedef signed int     s32;

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
extern void func_0219CAD8(void *, u32);
extern void func_0219CBE0(u8 *o);
extern void func_0219D2CC(int *obj);
extern void func_0204ED70(u8 *dst, struct Blk3 *src);
extern void func_0204EDB0(u8 *dst, u8 *src);
extern u32 func_0216D520(void *p);
extern void func_0219D2F4(u8 *s);
extern void func_0219CC80(u8 *o);
extern void func_0219CAF4(u8 *s);
extern u32 func_020307B0(void *p);
extern void func_0219D0F4(int *obj);
extern void func_0219CDAC(u8 *);
extern void func_0219D390(u8 *);
extern u32 func_0219CEAC(u32);
extern int func_0219CCF0(u8 *s);
extern void *func_0216D67C(void *a0);
extern void func_0216E2E8(const char *ctx, u32 id, struct Record *out);
extern void func_0219CB64(u32, u8 *, u32);
extern u16 func_0216E2E0(void *p);
extern void func_0216E2AC(u32, int, u8 *);
extern u16 func_02050340(struct BbActSys *o, u16 base, const struct BbActDesc *d, u32 count, u32 mode);
extern char *func_0219D3E4(int i);
extern void func_02050804(void *p, int idx, u32 v, u16 h);
extern void func_0205082C(void *p, int idx, u32 h);
extern void func_020507F0(void *p, int idx, u32 v);
extern void func_0219C9D0(u32 a, u32 b, u8 *p);
extern void *func_0216E3C4(void *p);
extern void func_02197CCC(u8 *p, s32 *out);
extern int func_02050894(void *p, int idx, int j);
extern int func_0219CBD4(u32 a, u32 b, u32 c, u32 d);
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
u32 func_0219C6B8(u32 a, V3 *b, int c, u32 d, u16 e);
void func_0219C74C(u32 a, u16 e);
u32 func_0219C780(u32 a, V3 *b, int c, u32 d, u16 e, u16 g);
void func_0219C7B4(u32 a, u16 e, u16 g);
void func_0219C7EC(u32 a, u32 b);
extern u16 d_021D75C4[][2];
extern u16 d_021D8064[];
extern int d_021DDD70;
extern T12 d_021D8058;
extern u16 d_021D75D0[][2];



/*
 * Former blocker (now filed in src/matched/arm9): func_02050080 (0x02050080) is an unlabelled arm9 leaf with no witness
 * outside this range (Ilias's). Verified C, EXACT under --arm --region arm9:
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
    u8 *p = sub_02030734(func_0216D4F8((u8 *)a), 0x24, 1, (const char *)&d_021DDD70, 360);
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
    func_0219CAF4((u8 *)s);
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
return func_0219CEAC(func_0216D520(p));
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
    u32 s = func_0216D520((void *)a);
    func_0216E2E8((const char *)a, b, (struct Record *)buf);
    func_0219CB64(s, buf, 0);
}



/*
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 */
void func_0219C680(u32 a)
{
    u8 buf[28];
    u32 s = func_0216D520((void *)a);
    int n = func_0216E2E0((void *)a);
    int i;
    for (i = 0; i < n; i++) {
        func_0216E2AC(a, i, buf);
        func_0219CB64(s, buf, 0);
    }
}



/*
 * Former blocker (now filed in src/matched/arm9): func_0205082C (0x0205082C) and func_020507F0 (0x020507F0) are
 * unlabelled arm9 leaves (Ilias's), no witness outside this range. Verified C,
 * both EXACT under --arm --region arm9 (func_020500A0 is the arm9 label at 0x020500A0):
 *     void func_020507F0(void *p, int idx, u32 v)
 *     { char *e = (char *)(*(u32 *)((char *)p + 24) + idx * 40); *(u32 *)(e + 24) = v; }
 *     void func_0205082C(void *p, int idx, u16 h)
 *     { char *e = (char *)(*(u32 *)((char *)p + 24) + idx * 40); *(u16 *)(e + 14) = h; func_020500A0(e); }
 * func_0219C9D0 (function pointer word) is filed as pkt_ov021_0219C9D0.
 */
u32 func_0219C6B8(u32 a, V3 *b, int c, u32 d, u16 e)
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
    s.f1c = (void (*)(void))func_0219C9D0;
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



void func_0219C74C(u32 a, u16 e)
{
    u32 o = (u32)func_0216D67C((void *)a);
    u8 *d = func_0216E3C4((void *)a);
    V3 v;
    func_02197CCC((u8 *)a, (s32 *)(&v));
    func_0219C6B8(o, &v, d[7], d[9], e);
}



u32 func_0219C780(u32 a, V3 *b, int c, u32 d, u16 e, u16 g)
{
    u32 r = func_0219C6B8(a, b, c, d, e);
    if (g != 0xFFFF) {
        func_02050894((void *)(*(u32 *)(func_0216D520((void *)a) + 4)), r, g);
    }
    return r;
}



void func_0219C7B4(u32 a, u16 e, u16 g)
{
    u32 o = (u32)func_0216D67C((void *)a);
    u8 *d = func_0216E3C4((void *)a);
    V3 v;
    func_02197CCC((u8 *)a, (s32 *)(&v));
    func_0219C780(o, &v, d[7], d[9], e, g);
}



void func_0219C7EC(u32 a, u32 b)
{
    u16 t[2];
    func_0219CBD4(func_0216D520(func_0216D67C((void *)a)), b, (u32)(&t[1]), (u32)(&t[0]));
    func_0219C74C(a, t[1]);
}
