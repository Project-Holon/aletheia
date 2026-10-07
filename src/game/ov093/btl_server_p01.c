/*
 * file:     btl_server_p01.c
 * unit:     yes
 * function: func_021B8CB0, func_021B8CE8, func_021B8CFC, func_021B8D08, func_021B8D38, func_021B8D8C, func_021B8DC0, func_021B8DDC, func_021B8DE4, func_021B8DEC, func_021B8E28, func_021B8E70, func_021B8ED8, func_021B8F38, func_021B8F5C, func_021B8F7C, func_021B8FC0, func_021B8FE4, func_021B8FF4, func_021B9000, func_021B9010, func_021B902C, func_021B904C, func_021B9064, func_021B9090, func_021B90BC, func_021B90E8, func_021B90F0, func_021B90F8, func_021B9114, func_021B911C, func_021B9120, func_021B916C, func_021B917C, func_021B9184, func_021B919C, func_021B91E4, func_021B9210, func_021B9234, func_021B9244, func_021B92A0, func_021B92B0, func_021B92D4, func_021B9358, func_021B937C, func_021B93E0, func_021B9424, func_021B9460, func_021B9634, func_021B9674, func_021B969C, func_021B97A0, func_021B985C, func_021B9864, func_021B98A4, func_021B98AC, func_021B990C, func_021B9920, func_021B9934
 * address:  0x021B8CB0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   data_021EFCF0  0x021EFCF0  data  ov093
 *   func_021B8778  0x021B8778  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021B8BEC  0x021B8BEC  thumb  ov093
 *   d_021EFCF4  0x021EFCF4  data  ov093  a1
 *   d_021EFCFA  0x021EFCFA  data  ov093  a1
 *   func_021B86C8 0x021B86C8 thumb ov093
 *   func_021B86B8 0x021B86B8 thumb ov093
 *   func_021B8B9C  0x021B8B9C  thumb  ov093
 *   func_02007F1C 0x02007F1C thumb
 *   func_02007E50 0x02007E50 thumb
 *   func_021BA54C   0x021BA54C  thumb ov093
 *   func_0201119C  0x0201119C  thumb
 *   func_02012F08  0x02012F08  thumb
 *   func_0200C274  0x0200C274  thumb
 *   func_021B9AF8  0x021B9AF8  thumb  ov093
 *   func_021D7FF8  0x021D7FF8  thumb  ov093
 *   func_021B9940  0x021B9940  thumb  ov093
 *   func_021D5844  0x021D5844  thumb  ov093
 *   func_021B8714  0x021B8714  thumb  ov093
 *   func_0201B7A0  0x0201B7A0  thumb
 *   func_021D54F4 0x021D54F4 thumb ov093
 *   func_021D6C24  0x021D6C24  thumb  ov093
 *   func_021D5864  0x021D5864  thumb  ov093
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   func_021B9C00  0x021B9C00  thumb  ov093
 *   func_021B9B40  0x021B9B40  thumb  ov093
 *   func_021D53B8 0x021D53B8 thumb ov093
 *   func_021BA178 0x021BA178 thumb ov093
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_021D4D84 0x021D4D84 thumb ov093
 *   func_021B9B54 0x021B9B54 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021D5848 0x021D5848 thumb ov093
 *   func_021D5444 0x021D5444 thumb ov093
 *   func_02017E1C 0x02017E1C thumb
 *   func_020173F0 0x020173F0 thumb
 *   func_021B9B60 0x021B9B60 thumb ov093
 *   func_021B9AEC 0x021B9AEC thumb ov093
 *   func_0201A948 0x0201A948 thumb
 *   func_021B9BF0 0x021B9BF0 thumb ov093
 *   func_021D6B84 0x021D6B84 thumb ov093
 *   func_0201A98C 0x0201A98C thumb
 *   func_0201AC2C 0x0201AC2C thumb
 *   func_021D6C3C 0x021D6C3C thumb ov093
 *   func_021D67D0  0x021D67D0  thumb  ov093
 */
#include "../../matched/include/Obj13271.h"
#include "../../matched/include/Obj07744.h"
#include "../../matched/include/Obj18132.h"
#include "../../matched/include/Obj09938.h"
#include "../../matched/include/Obj13272.h"
#include "../../matched/include/Obj09939.h"
#include "../../matched/include/Obj13273.h"
#include "../../matched/include/Obj18134.h"
#include "../../matched/include/Obj18136.h"
#include "../../matched/include/Obj13274.h"
#include "../../matched/include/Obj20977.h"
#include "../../matched/include/Obj18137.h"
#include "../../matched/include/Obj13275.h"
#include "../../matched/include/Obj06219.h"
#include "../../matched/include/Obj07745.h"
#include "../../matched/include/Obj20979.h"
#include "../../matched/include/Obj04354.h"
#include "../../matched/include/Obj20982.h"
#include "../../matched/include/Obj20983.h"
#include "../../matched/include/Obj07746.h"
#include "../../matched/include/Obj13276.h"
#include "../../matched/include/Obj13277.h"
#include "../../matched/include/Obj13278.h"
#include "../../matched/include/Obj09940.h"
#include "../../matched/include/Obj07747.h"

struct Unk021B8CB0;
struct Blk34;
struct Work;
struct R4;
struct S2;
struct Q1;
struct QF;
struct QH;
struct S;
struct Party;
struct PartyMon;
struct Rec534;
struct R3;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct Unk021B8CB0 { u32 f0; u32 mode; };

typedef struct { u8 pad[0xC1]; unsigned char flag:1; unsigned char rest:7; } Flags_021B9184;

typedef struct {
    u8 pad[0x473];
    u8 a : 1;
    u8 b : 1;
    u8 c : 1;
    u8 d : 1;
    u8 e : 1;
    u8 f : 1;
    u8 g : 1;
} B;

typedef struct { u8 lo:6; u8 flag:1; u8 hi:1; } Flags_021B9210;

typedef unsigned long long u64;

extern u8 func_021B8778(struct Unk021B8CB0 **p, int k, u8 *out);
extern int func_021D5B68(void *m);
extern u8 func_021D5440(u8 *p);
extern u8 func_021B8BEC(u8 *p, u32 k, u8 n);
extern int func_021B86C8(unsigned char **p);
extern void *func_021B86B8(void ***p);
extern int func_021B8B9C(u8 *p, u32 k);
extern int func_02007F1C(void *,u32,int,u16);
extern int func_02007E50(void *,u32,int,u16);
extern int func_021BA54C(char *p);
extern u32 func_0201119C(u32 v);
extern void *func_02012F08(int *p);
extern u32 func_0200C274(struct Blk34 *p);
extern char *func_021B9AF8(char *p, int i);
extern u32 func_021D7FF8(u32 a, void *b);
extern u8 *func_021B9940(char *p, u8 i);
extern void *func_021D5844(void *m);
extern char *func_021B8714(char **p);
extern void func_0201B7A0(void *a0, int a1, int a2, int a3);
extern void func_021D54F4(struct Work *, struct Work *);
extern int func_021D6C24(struct R4 *p);
extern void *func_021D5864(struct Work *p);
extern u8 func_021B9B94(struct Q1 *p);
extern u8 *func_021B9C00(struct S2 *p, u32 i);
extern void func_021B9B40(u8 *p);
extern void func_021D53B8(void *);
extern void *func_021BA178(void *p, int i, int mode);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern struct S *func_021D4D84(void *a, u8 b, u32 c);
extern void func_021B9B54(struct Q1 *p, u32 v);
extern int func_021D59B4(u8 *p, int k);
extern void func_021D5848(struct QH *p, void *v);
extern u16 func_021D5444(struct QF *p);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void *func_020173F0(u16 species, u16 level, u64 id, u16 heap);
extern void func_021B9B60(u8 *p);
extern char *func_021B9AEC(char *, int);
extern void func_0201A948(struct Party *p);
extern u32 func_021B9BF0(struct S2 *p, u32 i);
extern void func_021D6B84(void *, int);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern void func_0201AC2C(const struct Rec534 *src, struct Rec534 *dst);
extern void func_021D6C3C(void **p, void *q);
extern int func_021D67D0(struct R3 *p);
u8 func_021B8CB0(struct Unk021B8CB0 **p, u8 x);
int func_021B8CE8(int a, int b, int c);
unsigned char func_021B8CFC(char *p, int i);
u8 func_021B8D08(u32 x);
u8 func_021B8D38(void *p, int a, int k, u8 *out);
int func_021B8D8C(void *p, void *a, u32 b);
unsigned char func_021B8DC0(unsigned char *p,void *a,unsigned int b);
u8 func_021B8DDC(u32 x);
u8 func_021B8DE4(char *p, int i);
unsigned char func_021B8DEC(char *p,unsigned char k);
void func_021B8E28(u8 *p, u8 n, u8 *out, u8 *cnt_out);
u8 func_021B8E70(u8 *p, u32 k);
u8 func_021B8ED8(u8 *p, u8 k);
int func_021B8F38(unsigned char *p);
int func_021B8F5C(char *p,int k);
int func_021B8F7C(u8 *p, u32 k);
unsigned char func_021B8FC0(unsigned char *p,unsigned int k);
u8 func_021B8FE4(u8 *p);
u8 func_021B8FF4(u8 *p);
u8 func_021B9000(u8 *p);
u8 func_021B9010(u8 *p, u8 k);
int func_021B902C(int a, int b);
u8 func_021B904C(u8 *p,int k);
u32 func_021B9064(u8 *p, int k, int x);
void func_021B9090(u8 *p, u32 k, u32 x);
void func_021B90BC(u8 *p,u8 k,u32 x);
u32 func_021B90E8(void **p);
u32 func_021B90F0(void **p);
int func_021B90F8(u8 *p);
/* 021B9114 ldr r0,[r0]; adds r0,#0x23; ldrb r0,[r0] */ u8 func_021B9114(u8 **p);
/* 021B911C movs r0,#0; bx lr */ int func_021B911C(void);
void func_021B9120(u8 *p, u8 n);
void func_021B916C(u8 *p,u32 x);
int func_021B917C(char *p);
void func_021B9184(Flags_021B9184 **p);
u32 func_021B919C(u8 *p);
void func_021B91E4(void *p, int add);
u32 func_021B9210(u8 *p);
void func_021B9234(unsigned char *p);
u32 func_021B9244(char *p);
void func_021B92A0(u8 *p);
void func_021B92B0(char *p,void *m,int k);
void func_021B92D4(char *p, void *m, int c);
void func_021B9358(char *p, int i);
u8 *func_021B937C(int a, char *b, u8 *c);
void func_021B93E0(char *p, u32 a, u32 b);
void func_021B9424(char *p);
void func_021B9460(char *a, char *b, u8 c);
int func_021B9634(void *a);
void func_021B9674(char *p);
void func_021B969C(char *a, char *b, int k, int flag);
void func_021B97A0(char *a, char *b, int k);
int func_021B985C(char *p, int i);
int func_021B9864(int a, int b, int c);
u8 *func_021B98A4(char *const *q, u8 b);
u8 *func_021B98AC(char *const *q, u8 b);
void *func_021B990C(char *p, unsigned int i, unsigned int j);
u8 *func_021B9920(void *p, u32 i, u8 j);
u8 *func_021B9934(char *p, int i);
extern const u8 data_021EFCF0[4];
extern u8 d_021EFCF4[2][3];
extern u8 d_021EFCFA[2][3];


u8 func_021B8CB0(struct Unk021B8CB0 **p, u8 x)
{
    switch ((*p)->mode) {
    case 0:
        return x;
    case 3:
        return x;
    case 1:
        return (x + 2) & 3;
    case 2:
        return x;
    }
    return x;
}

int func_021B8CE8(int a, int b, int c) { int r=1; if ((b&1)==(c&1)) r=0; return r; }

unsigned char func_021B8CFC(char *p, int i)
{
    return *(unsigned char *)(p + i + 0x428);
}


u8 func_021B8D08(u32 x)
{
    u8 i;
    for (i = 0; i < 4; i++) {
        u8 lo = data_021EFCF0[i];
        u8 hi = lo + 5;
        if (x >= lo && x <= hi) return i;
    }
    return 0;
}


u8 func_021B8D38(void *p, int a, int k, u8 *out)
{
    u8 buf[8];
    u8 n;
    u8 cnt;
    u8 i;
    u8 *m;

    n = func_021B8778(p, k, buf);
    i = 0;
    cnt = 0;
    for (; i < n; i++) {
        m = func_021B98A4((char *const *)a, buf[i]);
        if (m && !func_021D5B68(m)) {
            out[cnt++] = func_021D5440(m);
        }
    }
    return cnt;
}


int func_021B8D8C(void *p, void *a, u32 b)
{
    u8 i = func_021B8D08(b);
    int r = func_021B9864((int)a, i, b);

    if (r >= 0) {
        r = func_021B8BEC(p, i, r);
        if (r != 6) return r;
    }
    return 6;
}

unsigned char func_021B8DC0(unsigned char *p,void *a,unsigned int b) { int k=func_021B8D8C(p,a,b); if(k!=6) return func_021B8E70(p,k); return 255; }


/*
 * tail-call thunk to func_021B8D08
 */
u8 func_021B8DDC(u32 x)
{
    return func_021B8D08(x);
}


u8 func_021B8DE4(char *p, int i)
{
    return func_021B8CFC(p, i);
}

unsigned char func_021B8DEC(char *p,unsigned char k) { unsigned char i,v,n; i=k; v=func_021B8CFC(p,k); n=0; while(i--!=0) { if(v==(unsigned char)p[i+0x428]) n++; } return n; }


void func_021B8E28(u8 *p, u8 n, u8 *out, u8 *cnt_out)
{
    u8 i = n;
    u8 cnt;
    *out = func_021B8CFC((char *)p, n);
    cnt = 0;
    while (i-- != 0) {
        if (*out == p[i + 0x428]) {
            cnt++;
        }
    }
    *cnt_out = cnt;
}


u8 func_021B8E70(u8 *p, u32 k)
{
    int s0 = 1;
    u8 s;
    u32 mode;
    int r;
    if ((p[0x46d] & 1) != (k & 1)) {
        s0 = 0;
    }
    s = s0;
    mode = *(u32 *)(((struct Obj13271 *)p)->f0 + 4);
    if (mode == 0) {
        r = 0;
        if (s == 0) {
            r = 1;
        }
        return r;
    }
    if (mode == 1) {
        return d_021EFCF4[s][(u8)(k >> 1)];
    }
    return d_021EFCFA[s][(u8)(k >> 1)];
}


u8 func_021B8ED8(u8 *p, u8 k)
{
    u8 par = k & 1;
    u32 mode = *(u32 *)(((struct Obj07744 *)p)->f0 + 4);
    u8 t;
    int r;
    if (mode == 0) {
        if (par != 0) {
            r = 1;
            if (p[0x46d] != 0) {
                r = 0;
            }
            return r;
        }
        return p[0x46d];
    }
    t = p[0x46d] & 1;
    if (par != 0) {
        return (t ^ 1) + (k - 3);
    }
    return t + (k - 2);
}

int func_021B8F38(unsigned char *p) { unsigned int v; if(func_021B86C8((unsigned char **)p)) { v=(unsigned int)func_021B86B8((void ***)p); if(v!=1 && v!=0) return 1; } return 0; }

int func_021B8F5C(char *p,int k) { func_021B969C(p+0xc8,p,k,0); return func_021B985C(p+0xc8,k); }


int func_021B8F7C(u8 *p, u32 k)
{
    if (func_021B86C8((unsigned char **)p)) {
        k = (u8)((k + 2) & 3);
        if (func_021B8B9C(p, k)) {
            func_021B969C((char *)(p + 0xc8), (char *)p, k, 0);
            return func_021B985C((char *)(p + 0xc8), k);
        }
    }
    return 0;
}

unsigned char func_021B8FC0(unsigned char *p,unsigned int k) { if(func_021B86C8((unsigned char **)p)) return (unsigned char)((k&2)!=0); return 0; }

u8 func_021B8FE4(u8 *p)
{
    return func_021B8FC0(p, p[0x46c]);
}


u8 func_021B8FF4(u8 *p)
{
    return ((struct Obj18132 *)p)->f46C;
}

u8 func_021B9000(u8 *p) { return func_021B9010(p,p[0x46c]); }

u8 func_021B9010(u8 *p, u8 k) { u8 n; n=(k+2)&3; if(!func_021B8B9C(p,n)) n=4; return n; }

int func_021B902C(int a, int b) { if(a==b) return 1; if(a==(u8)((b+2)&3)) return 1; return 0; }

u8 func_021B904C(u8 *p,int k) { return func_021B9064(p,p[0x46c],k); }

u32 func_021B9064(u8 *p, int k, int x) { u8 m; k &= 1; k ^= 1; if(x) { m=k+((x&1)<<1); if(func_021B8B9C(p,m)) k=m; } return k; }

void func_021B9090(u8 *p, u32 k, u32 x) { u8 *q; q=*(u8 * *)&((struct Obj09938 *)p)->f0; if(q[0x23]==0 && k==p[0x46c]) func_02007F1C(((struct Obj13272 *)q)->f60,x,1,((struct Obj09938 *)p)->f468); }

void func_021B90BC(u8 *p,u8 k,u32 x) { u8 *q; q=*(u8 * *)&((struct Obj09939 *)p)->f0; if(q[0x23]==0 && k==p[0x46c]) func_02007E50(((struct Obj13273 *)q)->f60,x,1,((struct Obj09939 *)p)->f468); }


/*
 * double deref: *(u32*)(*p + 0x60)
 */
u32 func_021B90E8(void **p)
{
    return ((struct Obj18134 *)((u8 *)*p))->f60;
}


/*
 * double deref: *(u32*)(*p + 0x64)
 */
u32 func_021B90F0(void **p)
{
    return ((struct Obj18136 *)((u8 *)*p))->f64;
}

int func_021B90F8(u8 *p) { u8 *q; q=*(u8 * *)&((struct Obj20977 *)p)->f0; if(((struct Obj13274 *)q)->f94!=0 && q[0x23]==0) return 1; return 0; }


/* 021B9114  ldr r0,[r0]; adds r0,#0x23; ldrb r0,[r0] */
/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: ldr r0, [r0]; adds r0, #0x23; ldrb r0, [r0]; bx lr.
 */
u8 func_021B9114(u8 **p) { return ((struct Obj18137 *)(*p))->f23; }


/* 021B911C  movs r0,#0; bx lr */
/*
 * Returns the constant #0.
 */
int func_021B911C(void) { return 0; }

void func_021B9120(u8 *p, u8 n)
{
    u8 cnt;
    u8 t;
    u8 m;
    if (*(u8 *)(*(u32 *)p + 0x90) == 6) {
        m = n;
        t = func_021B8CFC((char *)p, n);
        cnt = 0;
        while (m--) {
            if (t == *(u8 *)(p + m + 0x428))
                cnt++;
        }
        *(u8 *)(*(u32 *)p + 0x90) = cnt;
    }
}

void func_021B916C(u8 *p,u32 x) { if(((struct Obj13275 *)p)->f444==7) ((struct Obj13275 *)p)->f444=x; }


/*
 * tail-call thunk to func_021BA54C
 */
int func_021B917C(char *p)
{
    return func_021BA54C(p);
}

void func_021B9184(Flags_021B9184 **p)
{
    (*p)->flag = 1;
}


u32 func_021B919C(u8 *p)
{
    if (((B *)p)->d == 0) {
        if (((B *)p)->g) {
            ((struct Obj06219 *)p)->f430 = ((struct Obj06219 *)p)->f430 << 1;
        }
        ((struct Obj06219 *)p)->f430 = func_0201119C(((struct Obj06219 *)p)->f430);
        ((B *)p)->d = 1;
    }
    return ((struct Obj06219 *)p)->f430;
}


/*
 * Unlabelled Thumb leaf in a .word run.  If bit 3 of p[0x473] is clear,
 * adds `add` to the word at p+0x434 and clamps it to 0x1869f.
 * The bit test is a lsls #0x1c / lsrs #0x1f pair, so the promoted value
 * must stay unsigned.
 */
void func_021B91E4(void *p, int add)
{
    if (((unsigned int)((struct Obj07745 *)p)->f473 << 28 >> 31) != 0)
        return;
    ((struct Obj07745 *)p)->f434 += add;
    if (((struct Obj07745 *)p)->f434 > 0x1869f)
        ((struct Obj07745 *)p)->f434 = 0x1869f;
}

u32 func_021B9210(u8 *p) { u32 n; n=((struct Obj20979 *)p)->f434; if(((Flags_021B9210 *)(p+0x473))->flag) { n*=2; if(n>99999) n=99999; } return n; }

/*
 * Unlabelled Thumb leaf in a .word run:
 *   ldr r2,[pc,#8]; movs r1,#0x40; ldrb r3,[r0,r2]; orrs r1,r3; strb r1,[r0,r2]; bx lr
 * with pool word 0x473.  Sets bit 6 of the byte at p+0x473.
 */
void func_021B9234(unsigned char *p)
{
    p[0x473] |= 0x40;
}


u32 func_021B9244(char *p)
{
    u32 r;
    u32 m;
    u32 c;

    r = 0;
    if (((u32)((struct Obj04354 *)p)->f473 << 27 >> 31) == 0) {
        if (**(u32 * *)&((struct Obj04354 *)p)->f0 <= 1) {
            m = func_0200C274(func_02012F08(((struct Obj20982 *)(*(char * *)&((struct Obj04354 *)p)->f0))->f58));
            c = func_021D7FF8(((struct Obj20983 *)(*(char * *)&((struct Obj04354 *)p)->f0))->f80, func_021B9AF8(p + 0x1b0, ((struct Obj04354 *)p)->f46C));
            if (c > m)
                c = m;
            r = c;
            ((struct Obj04354 *)p)->f438 = r;
        }
        ((struct Obj04354 *)p)->f473 |= 0x10;
    }
    return r;
}

void func_021B92A0(u8 *p) { p[0x473]|=32; }

void func_021B92B0(char *p,void *m,int k) { u8 *q; q=*(u8 * *)&((struct Obj07746 *)p)->f0; if(((struct Obj13276 *)q)->f0<=1 && q[0x23]==0) func_021B92D4(p,m,k?5:4); }


void func_021B92D4(char *p, void *m, int c)
{
    u8 i;
    void *x;
    void *y;
    char *e;

    i = func_021D5440(m);
    x = func_021B9940(p + 0x1b0, i);
    y = func_021B9940(p + 0xc8, i);
    x = func_021D5844(x);
    y = func_021D5844(y);
    e = func_021B8714((char **)p);
    func_0201B7A0(x, c, ((struct Obj13277 *)e)->fA, (u16)((((struct Obj07746 *)p)->f468 & 0x7fff) | 0x8000));
    func_0201B7A0(y, c, ((struct Obj13277 *)e)->fA, (u16)((((struct Obj07746 *)p)->f468 & 0x7fff) | 0x8000));
}

void func_021B9358(char *p, int i)
{
    u8 *dst = func_021B9934(p + 0x1b0, i);
    u8 *src = func_021B9934(p + 0xc8, i);
    func_021D54F4((struct Work *)src, (struct Work *)dst);
}


u8 *func_021B937C(int a, char *b, u8 *c)
{
    u8 *t;
    void *v;
    void *k;
    int e;
    char *g;
    u32 n;
    u32 i;

    if (func_021D6C24((struct R4 *)c)) {
        e = func_021B8DDC(func_021D5440(c));
        k = func_021D5864((struct Work *)c);
        g = func_021B9AF8(b, e);
        n = func_021B9B94((struct Q1 *)g);
        for (i = 0; i < n; i++) {
            t = func_021B9C00((struct S2 *)g, (u8)i);
            v = func_021D5844(t);
            if (v == k)
                return t;
        }
    }
    return c;
}


void func_021B93E0(char *p, u32 a, u32 b)
{
    u32 i;
    u32 j;
    u32 k;

    ((struct Obj13278 *)p)->f0 = a;
    ((struct Obj13278 *)p)->fE4 = b;
    for (i = 0; i < 4; i++)
        func_021B9B40((u8 *)(p + 4 + i * 0x1c));
    for (j = 0; j < 0x18; j++)
        *(u32 *)(p + 0x84 + j * 4) = 0;
    for (k = 0; k < 4; k++)
        *(u32 *)(p + 0x74 + k * 4) = 0;
}

void func_021B9424(char *p)
{
    unsigned int i;
    for (i = 0; i < 24; i++) {
        if (*(void **)(p + i * 4 + 0x84) != 0) {
            func_021D53B8(*(void **)(p + i * 4 + 0x84));
            *(void **)(p + i * 4 + 0x84) = 0;
        }
    }
    for (i = 0; i < 4; i++) func_021B9B40((u8 *)(p + 4 + i * 28));
}

#pragma opt_lifetimes off

/*
 * 2026-10-05 (wave P5, pengy share): EXACT. Needs #pragma opt_lifetimes off (per-function
 * pragma) and the clear of nw written AFTER the func_021BA178 call (l2 = f(...); nw = 0;).
 * Written before the call, the zero took r0 instead of the original r1. Other levers: raw
 * offsets, early locals qs = a + 4 and qo = c * 0x1c, declaration order qo, qs, list, n, v, nw,
 * x, j, i, y, cnt, comma-form loop headers, e = func_0201AB28() as its own statement.
 */
void func_021B9460(char *a, char *b, u8 c)
{
    u32 qo;
    char *qs;
    void *list;
    u32 n;
    u8 *v;
    void *e;
    u8 nw;
    u8 x;
    u32 j;
    int i;
    u8 y;
    int cnt;
    list = func_021BA178(b, c, *(u32 *)(a + 0xe4));
    qs = a + 4;
    qo = c * 0x1c;
    n = func_0201AA18(list);
    x = data_021EFCF0[c];
    *(void **)(a + c * 4 + 0x74) = list;
    for (i = 0, y = x; i < n; i++, y++) {
        e = func_0201AB28(list, i);
        *(void **)(a + y * 4 + 0x84) = func_021D4D84(e, y, 0x12);
        func_021B9B54((struct Q1 *)(qs + qo), (u32)(*(void **)(a + y * 4 + 0x84)));
    }
    cnt = func_021B9634(list);
    if (cnt > 0) {
        for (i = 0, y = x; i < cnt; i++, y++) {
                if (func_021D59B4(*(u8 **)(a + y * 4 + 0x84), 0x11) == 0x95)
                    func_021D5848(*(void **)(a + y * 4 + 0x84), func_0201AB28(list, cnt));
            }
    }
    if (func_021B86B8((void ***)b) == 0 && c == 1) {
        for (j = 0; j < n; j++, x++) {
            v = *(u8 **)(a + x * 4 + 0x84);
            if (func_021D5444((struct QF *)v) == 0x23B && func_021D59B4(v, 0x11) == 0x95) {
                void *l2;
                u8 m, q;
                l2 = func_021BA178(b, 0, *(u32 *)(a + 0xe4));
                nw = 0;
                m = func_0201AA18(l2);
                for (q = 0; q < m; q++) {
                    u16 s = func_02017E1C(func_0201AB28(l2, q), 5, 0);
                    if (s == 0xf3) { nw = 0xf4; break; }
                    if (s == 0xf4) { nw = 0xf5; break; }
                    if (s == 0xf5) { nw = 0xf3; break; }
                }
                if (nw != 0) {
                    if (*(void **)(b + 0x2c0) == 0)
                        *(void **)(b + 0x2c0) = func_020173F0(nw, func_021D59B4(v, 0xf), 0, *(u16 *)(b + 0x468));
                    func_021D5848((struct QH *)v, *(void **)(b + 0x2c0));
                }
            }
        }
    }
    func_021B9B60((u8 *)(qs + qo));
}

#pragma opt_lifetimes reset


int func_021B9634(void *a)
{
    int i;
    void *e;

    for (i = func_0201AA18(a) - 1; i >= 0; i--) {
        e = func_0201AB28(a, i);
        if (func_02017E1C(e, 0x4c, 0) == 0 && func_02017E1C(e, 0xa0, 0) != 0)
            return i;
    }
    return -1;
}

void func_021B9674(char *p)
{
    unsigned int i;
    for (i = 0; i < 24; i++) {
        if (*(void **)(p + i * 4 + 0x84) != 0) {
            func_021D53B8(*(void **)(p + i * 4 + 0x84));
            *(void **)(p + i * 4 + 0x84) = 0;
        }
    }
}

void func_021B969C(char *a, char *b, int k, int flag)
{
    void *list;
    char *g;
    u32 n, i, j;
    void *m, *e;
    void *h;
    u8 links[6];
    list = (void *)func_021B985C(a, k);
    g = func_021B9AEC(a, k);
    n = func_0201AA18(list);
    func_0201A948(((struct Obj09940 *)b)->f2B8);
    for (i = 0; i < 6; i++) links[i] = 6;
    for (i = 0; i < n; i++) {
        m = (void *)func_021B9BF0((struct S2 *)g, (u8)i);
        func_021D6B84(m, flag);
        func_0201A98C(((struct Obj09940 *)b)->f2B8, func_021D5844(m));
        if (func_021D6C24(m)) {
            h = func_021D5864(m);
            for (j = 0; j < n; j++) {
                if (h == func_021D5844((void *)func_021B9BF0((struct S2 *)g, (u8)j))) {
                    links[i] = j;
                    break;
                }
            }
        }
    }
    func_0201AC2C(((struct Obj09940 *)b)->f2B8, list);
    for (i = 0; i < n; i++) {
        e = func_0201AB28(list, i);
        m = (void *)func_021B9BF0((struct S2 *)g, (u8)i);
        func_021D6C3C(m, e);
        if (links[i] != 6)
            func_021D5848(m, func_0201AB28(list, links[i]));
    }
}


void func_021B97A0(char *a, char *b, int k)
{
    void *list;
    char *g;
    u32 n;
    u32 t;
    u32 i;
    u32 j;
    void *m;

    list = (void *)func_021B985C(a, k);
    g = func_021B9AEC(a, k);
    n = func_0201AA18(list);
    func_0201A948(((struct Obj07747 *)b)->f2B8);
    t = data_021EFCF0[k];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            m = (void *)func_021B9BF0((struct S2 *)g, (u8)j);
            if (t + i == func_021D5440(m)) {
                func_021D6B84(m, 1);
                func_0201A98C(((struct Obj07747 *)b)->f2B8, func_021D5844(m));
                if (func_021D67D0(m) != 0)
                    *(u8 *)(*(char * *)&((struct Obj07747 *)b)->f0 + i + 0xc2) = 1;
                break;
            }
        }
    }
    func_0201AC2C(((struct Obj07747 *)b)->f2B8, list);
}

int func_021B985C(char *p, int i)
{
    return *(int *)(p + i * 4 + 0x74);
}


int func_021B9864(int a, int b, int c)
{
    char *p = (char *)(a + 4) + b * 0x1c;
    unsigned int n = func_021B9B94((struct Q1 *)p);
    unsigned int i;
    for (i = 0; i < n; i++) {
        if (c == func_021D5440((u8 *)func_021B9C00((struct S2 *)p, (unsigned char)i)))
            return i;
    }
    return -1;
}


/*
 * tail-call thunk to func_021B98AC
 */
u8 *func_021B98A4(char *const *q, u8 b)
{
    return func_021B98AC(q, b);
}


u8 *func_021B98AC(char *const *q, u8 b)
{
    u8 i = b;
    char *p = *q;
    u8 a;
    u8 cnt;
    char *g;

    a = func_021B8CFC(p, b);
    cnt = 0;
    while (i-- != 0) {
        if (a == *(u8 *)(p + i + 0x428))
            cnt++;
    }
    g = (char *)q + 4 + a * 0x1c;
    if (cnt < func_021B9B94((struct Q1 *)g))
        return func_021B9C00((struct S2 *)g, cnt);
    return 0;
}

void *func_021B990C(char *p, unsigned int i, unsigned int j)
{
    return (void *)func_021B9BF0((void *)((unsigned int)p + 4 + i * 28), j);
}

u8 *func_021B9920(void *p, u32 i, u8 j)
{
    return func_021B9C00((void *)((unsigned int)p + 4 + i * 28), j);
}


u8 *func_021B9934(char *p, int i)
{
    return *(u8 **)(p + i * 4 + 0x84);
}
