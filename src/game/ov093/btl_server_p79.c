/*
 * file:     btl_server_p79.c
 * unit:     yes
 * function: func_021C7D34, func_021C7D44, func_021C7D54, func_021C7DAC, func_021C7E14, func_021C7EC4, func_021C7ED8, func_021C7EEC, func_021C7F04, func_021C7F24, func_021C7F4C, func_021C7F68, func_021C7FCC, func_021C7FE0, func_021C8010, func_021C8020, func_021C8030, func_021C804C, func_021C80AC, func_021C8114, func_021C8120, func_021C812C, func_021C8130, func_021C8138, func_021C8140, func_021C814C, func_021C815C, func_021C8168, func_021C8174, func_021C8180, func_021C818C, func_021C81C8, func_021C81D0, func_021C8234, func_021C824C, func_021C8288, func_021C8290, func_021C82B8, func_021C82C4, func_021C82D0
 * address:  0x021C7D34
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
 *   func_0689D5F4 0x0689D5F4 thumb ov095
 *   func_0689D5FC 0x0689D5FC thumb ov095
 *   func_021BD2B4  0x021BD2B4  thumb  ov093
 *   func_021BD34C  0x021BD34C  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021D6C24  0x021D6C24  thumb  ov093
 *   func_021B937C  0x021B937C  thumb  ov093
 *   func_021C64B4  0x021C64B4  thumb  ov093
 *   func_021C6E3C  0x021C6E3C  thumb  ov093
 *   func_0201C314  0x0201C314  thumb
 *   func_021C1E74  0x021C1E74  thumb  ov093
 *   func_021B8DDC 0x021B8DDC thumb ov093
 *   func_021B997C 0x021B997C thumb ov093
 *   func_021BB85C 0x021BB85C thumb ov093
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021B9BC4 0x021B9BC4 thumb ov093
 *   func_021B8778   0x021B8778  thumb  ov093
 *   func_021B98A4   0x021B98A4  thumb  ov093
 *   func_021D5B68   0x021D5B68  thumb  ov093
 *   func_021B9AF8 0x021B9AF8 thumb ov093
 *   func_021B9010 0x021B9010 thumb ov093
 *   func_021B8B9C 0x021B8B9C thumb ov093
 *   func_021B8D8C 0x021B8D8C thumb ov093
 *   func_021B98AC 0x021B98AC thumb ov093
 *   func_021D80BC 0x021D80BC thumb ov093
 *   func_0689D588 0x0689D588 thumb ov095
 *   func_021B86B8  0x021B86B8  thumb  ov093
 *   func_021B8714  0x021B8714  thumb  ov093
 *   func_021B8670  0x021B8670  thumb  ov093
 *   func_021D5444 0x021D5444 thumb ov093
 *   func_0201B718 0x0201B718 thumb
 *   func_021BC948   0x021BC948  thumb ov093
 *   func_021C6F0C   0x021C6F0C  thumb  ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021EF948 0x021EF948 thumb ov093
 *   func_021C2AB0   0x021C2AB0  thumb ov093
 *   func_021BFA00 0x021BFA00 thumb ov093
 *   func_021B911C  0x021B911C  thumb  ov093
 *   func_06898CF4  0x06898CF4  thumb  ov095
 *   func_021B9AE0 0x021B9AE0 thumb ov093
 *   func_021C82E4 0x021C82E4 thumb ov093
 */
#include "../../matched/include/Obj02135.h"
#include "../../matched/include/Obj18325.h"
#include "../../matched/include/Obj21110.h"
#include "../../matched/include/Obj21111.h"
#include "../../matched/include/Obj00003.h"
#include "../../matched/include/Obj13340.h"
#include "../../matched/include/Obj18333.h"
#include "../../matched/include/Obj26329.h"
#include "../../matched/include/Obj26330.h"
#include "../../matched/include/Obj18335.h"
#include "../../matched/include/Obj18336.h"
#include "../../matched/include/Obj18337.h"
#include "../../matched/include/Obj13341.h"
#include "../../matched/include/Obj21115.h"

struct R4;
struct Out64B4;
struct Unk021B8CB0;
struct QF;
struct Unk021D62A8;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct Flag { u8 pad[0x78a]; u8 low:3; u8 set:1; u8 high:4; };

typedef struct { u32 lo : 4; u32 hi : 28; } W;

typedef union { u32 u; W w; } U;

typedef struct { u8 *a; U b; u32 c; u32 d; } E;

typedef struct { u8 pad[0x782]; u8 n; u8 pad2[0x5d]; E e[4]; } S;

/* 021C8138  ldr r0,[r0,#0x10]; lsls r0,#0x10; lsrs r0,#0x10 */
struct Q7 { u8 pad[0x10]; u32 v; };

typedef struct { u32 f0; u8 pad[60]; } E64;

extern int func_0689D5F4(u8 *p, int i);
extern int func_0689D5FC(u8 *p, int i);
extern void func_021BD2B4(u8 *it, u8 **q);
extern int func_021BD34C(u8 *it, u8 **q, u8 **x);
extern u8 func_021D5440(u8 *p);
extern int func_021B9A24(u32 a, u32 b);
extern u8 *func_021B9934(char *p, int i);
extern int func_021D6C24(struct R4 *p);
extern u8 *func_021B937C(int a, char *b, u8 *c);
extern void func_021C64B4(u8 *p, int q, u8 *a, struct Out64B4 *out);
extern int func_021C6E3C(u8 *p, u8 *a, u8 *b, u8 *q, int flag);
extern u32 func_0201C314(void *p);
extern int func_021C1E74(u8 *p, u8 *a, u8 *b, u8 *c, u32 d, u32 e, u32 f, int g, u16 *out);
extern u8 func_021B8DDC(u32 x);
extern int func_021B997C(u8 *, unsigned int);
extern u8 *func_021BB85C(u8 *, unsigned int);
extern u32 func_021B8588(void **p);
extern u8 func_021B9BC4(u8 *, int);
extern u8 func_021B8778(struct Unk021B8CB0 **p, int k, u8 *out);
extern u8 *func_021B98A4(char *const *q, u8 b);
extern int func_021D5B68(void *p);
extern char *func_021B9AF8(char *, int);
extern u8 func_021B9010(u8 *p, u8 k);
extern int func_021B8B9C(u8 *, unsigned int);
extern int func_021B8D8C(void *, void *, unsigned int);
extern u8 *func_021B98AC(char *const *q, u8 b);
extern int func_021D80BC(void *, int, int, u16);
extern int func_0689D588(u8 *, int);
extern void *func_021B86B8(void ***p);
char *func_021B8714(char **p);
unsigned int func_021B8670(unsigned int **p);
extern u16 func_021D5444(struct QF *p);
extern unsigned int func_0201B718(void *, unsigned int, unsigned int, unsigned int);
extern u16 func_021BC948(u8 *p, u8 *x, int flag);
extern int func_021C6F0C(u8 *p, u8 *a, int k);
extern int func_021D59B4(u8 *p, int k);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern int func_021EF948(int);
extern int func_021C2AB0(u8 *p);
extern int func_021BFA00(u8 *, u8 *, u8 *, void *);
void func_021B911C(int);
int func_06898CF4(int a, int b);
extern u8 func_021B9AE0(unsigned int);
extern int func_021C82E4(unsigned int, int);
int func_021C7D34(char *p, int i);
int func_021C7D44(char *p, int i);
u8 func_021C7D54(u8 *p, u8 *k, u8 *out);
int func_021C7DAC(u8 *p, int a, int b, int c);
u16 func_021C7E14(u8 *p, u8 a, u8 b, u32 c, int e0, int e1);
u32 func_021C7EC4(u8 *p);
int func_021C7ED8(u8 *p, int i);
int func_021C7EEC(u8 *p, int i);
int func_021C7F04(u8 *p, int i);
int func_021C7F24(u8 *p, int i);
int func_021C7F4C(struct Flag *p);
u8 func_021C7F68(int *p, int b, u8 *out);
char *func_021C7FCC(u8 *p, int i);
char *func_021C7FE0(u8 *p, int v);
int func_021C8010(u8 *p, unsigned int v);
u8 func_021C8020(u8 *p, u8 v);
int func_021C8030(u8 *p, int v, u16 k);
int func_021C804C(S *p, u8 key, u32 *out);
int func_021C80AC(u8 *p, int key);
u16 func_021C8114(u8 *p);
u8 *func_021C8120(u8 *p, int b);
u8 *func_021C812C(u8 *p);
u8 *func_021C8130(u8 *p);
u16 func_021C8138(struct Q7 *p);
unsigned char func_021C8140(char *p, int i);
int func_021C814C(u8 *p, int v);
int func_021C815C(int *p);
void func_021C8168(int *p);
int func_021C8174(int *p);
int func_021C8180(int *p);
int func_021C818C(u8 *p, int v);
u16 func_021C81C8(u8 *p, u8 *x, int flag);
u16 func_021C81D0(u8 *p, u8 *a, u32 y);
int func_021C8234(u8 *p, int i);
int func_021C824C(u8 *p, int v);
int func_021C8288(u8 *p);
int func_021C8290(u8 *p, int a, int b, void *item);
void func_021C82B8(int *p);
int func_021C82C4(int a, int b, int c);
int func_021C82D0(int unused, unsigned int v, int k);







/*
 * witness: owned verified ov095 leaf 0x0689D5F4 resolves the tail pool.
 * ABI: full-word r1 index is preserved; ov095 body reads r0/r1 and returns
 * the byte in r0. Tail pool target is 0x0689D5F4 + 1. This ov095 leaf
 * was authorized by root separately; no domain assumptions.
 */
int func_021C7D34(char *p, int i) { return func_0689D5F4((u8 *)(p + 0x1ab8), i); }







/*
 * witness: owned verified ov095 leaf 0x0689D5FC resolves the tail pool.
 * ABI: full-word r1 index is preserved; ov095 body reads r0/r1 and returns
 * the byte in r0. Tail pool target is 0x0689D5FC + 1. This ov095 leaf
 * was authorized by root separately; no domain assumptions.
 */
int func_021C7D44(char *p, int i) { return func_0689D5FC((u8 *)(p + 0x1ab8), i); }








u8 func_021C7D54(u8 *p, u8 *k, u8 *out)
{
    u32 it;
    u8 *x;
    u8 n = 0;
    func_021BD2B4((u8 *)&it, (u8 **)p);
    while (func_021BD34C((u8 *)&it, (u8 **)p, &x)) {
        if (func_021B9A24((u32)k, func_021D5440(x)) == 0) {
            out[n++] = func_021D5440(x);
        }
    }
    return n;
}








int func_021C7DAC(u8 *p, int a, int b, int c)
{
    int buf[5];
    int r;
    u8 *x = func_021B9934(*(char * *)&((struct Obj02135 *)p)->f8, a);
    u8 *y = func_021B9934(*(char * *)&((struct Obj02135 *)p)->f8, b);
    ((struct Obj02135 *)p)->f774 += 1;
    if (func_021D6C24((struct R4 *)y)) {
        y = func_021B937C(((struct Obj02135 *)p)->f4, *(char * *)&((struct Obj02135 *)p)->f8, y);
    }
    func_021C64B4(p, c, x, (struct Out64B4 *)buf);
    r = func_021C6E3C(p, x, y, (u8 *)buf, 0);
    ((struct Obj02135 *)p)->f774 -= 1;
    return r;
}








u16 func_021C7E14(u8 *p, u8 a, u8 b, u32 c, int e0, int e1)
{
    int buf[5];
    u16 o;
    u8 *x;
    u8 *y;
    int z;
    if (c != 0 && func_0201C314((void *)c) != 0) {
        x = func_021B9934(*(char * *)&((struct Obj02135 *)p)->f8, a);
        y = func_021B9934(*(char * *)&((struct Obj02135 *)p)->f8, b);
        ((struct Obj02135 *)p)->f774 += 1;
        if (func_021D6C24((struct R4 *)y)) {
            y = func_021B937C(((struct Obj02135 *)p)->f4, *(char * *)&((struct Obj02135 *)p)->f8, y);
        }
        if (e0) {
            z = func_021C7DAC(p, a, b, c);
        } else {
            z = 3;
        }
        func_021C64B4(p, c, x, (struct Out64B4 *)buf);
        func_021C1E74(p, x, y, (u8 *)buf, z, 0x1000, 0, e1 == 0, &o);
        ((struct Obj02135 *)p)->f774 -= 1;
        return o;
    }
    return 0;
}








/* 021C7EC4  nonzero test of the pooled offset 0x774 */
/*
 * 8 instructions, 16 bytes: ldr r1, pool_021C7ED4; ldr r0, [r0, r1]; cmp r0, #0; beq loc_021C7ED0; movs r0, #1; bx lr; movs r0, #0; bx lr.
 */
u32 func_021C7EC4(u8 *p)
{
    return (((struct Obj18325 *)p)->f774 != 0);
}







int func_021C7ED8(u8 *p, int i) { return func_021B997C(*(u8 * *)&((struct Obj21110 *)p)->f4, func_021B8DDC(i)); }







int func_021C7EEC(u8 *p, int i) { return func_021BB85C(*(u8 * *)&((struct Obj21111 *)p)->f0, func_021B8DDC(i))[9]; }







int func_021C7F04(u8 *p, int i) { if (func_021B8588(((struct Obj00003 *)p)->f4) != 3) return func_021C7EEC(p, i); return 3; }







int func_021C7F24(u8 *p, int i) { char *q = func_021C7FCC(p, i); if (func_021B9BC4((u8 *)q, func_021C7F04(p, i))) return 1; return 0; }






int func_021C7F4C(struct Flag *p) { if (p->set) return 0; p->set = 1; return 1; }







/*
 * Named by the parked ov093 file func_021D85F4.c.  Builds a candidate list in
 * a local buffer and copies the accepted entries to `out`.  EXACT*: the
 * completed extent runs into an unlabelled follower.  Three levers: `n` must
 * be volatile (it is spilled/reloaded around the loop calls), the boolean is
 * materialised through a `?:` rather than a bare `&&`, and the `u8` locals
 * are declared `j` before `i` with both initialised in the for-clause.
 */
u8 func_021C7F68(int *p, int b, u8 *out)
{
    u8 buf[8];
    volatile u32 n = (u32)func_021B8778((struct Unk021B8CB0 **)p[1], b, buf);
    u8 j;
    u8 i;

    for (i = 0, j = 0; i < n; i++) {
        u8 *x = func_021B98A4((char *const *)p[2], buf[i]);
        int ok = (x != 0) ? (func_021D5B68(x) == 0) : 0;

        if (ok)
            out[j++] = func_021D5440(x);
    }
    return j;
}






char *func_021C7FCC(u8 *p, int i) { return func_021B9AF8(*(char * *)&((struct Obj00003 *)p)->f8, func_021B8DDC(i)); }






/*
 * extent: two bytes alignment padding follow.
 * ABI: original forwards full-word B8DDC/B9010 results without narrowing;
 * widen B9010 and B8B9C input declarations relative to narrow legacy sources.
 */
char *func_021C7FE0(u8 *p, int v) { unsigned int k; k=func_021B9010(*(u8 * *)&((struct Obj00003 *)p)->f4, func_021B8DDC(v)); if(func_021B8B9C(*(u8 * *)&((struct Obj00003 *)p)->f4,k)) return func_021B9AF8(*(char * *)&((struct Obj00003 *)p)->f8,k); return 0; }






int func_021C8010(u8 *p, unsigned int v) { return func_021B8D8C(((struct Obj00003 *)p)->f4, ((struct Obj00003 *)p)->f8, v); }






/*
 * extent: two bytes alignment padding follow.
 */
u8 func_021C8020(u8 *p, u8 v) { return func_021D5440((u8 *)func_021B98AC(*(char *const * *)&((struct Obj00003 *)p)->f8, v)); }






int func_021C8030(u8 *p, int v, u16 k) { return func_021D80BC(((struct Obj00003 *)p)->f4, *(int *)&((struct Obj00003 *)p)->f8, (int)func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8,v), k); }







/*
 * Levers: the record array read as p->e[i] of the twins' S (func_021BCA08,
 * func_021BCAAC), which keeps i*16 live and recomputes p+i*16 for the second
 * load; the second word as a union of u32 and a 4-bit bitfield read in place
 * (a union local takes a stack slot); key as a u8 parameter, which puts its
 * spill ahead of the count load (int/u32 key leave it after).
 */
int func_021C804C(S *p, u8 key, u32 *out)
{
    u32 i;
    for (i = 0; i < p->n; i++) {
        if (key == func_021D5440(p->e[i].a)) {
            if (p->e[i].b.w.lo != 6) {
                *out = p->e[i].b.u;
                return 1;
            }
        }
    }
    return 0;
}







int func_021C80AC(u8 *p, int key)
{
    u32 i;
    u32 total;
    u32 flagged;
    flagged = 0;
    total = 0;
    for (i = 0; i < p[0x782]; i++) {
        u8 *e = p + i * 16;
        if (key != func_021D5440(*(u8 * *)&((struct Obj13340 *)e)->f7E0)) {
            total++;
            if (e[0x7ed] != 0) {
                flagged++;
            }
        }
    }
    return total == flagged;
}







/*
 * ldrh at #0x1f74 (pool constant)
 */
u16 func_021C8114(u8 *p)
{
    return ((struct Obj18333 *)p)->f1F74;
}







/*
 * pointer add #0x1fec
 */
u8 *func_021C8120(u8 *p, int b)
{
    return p + 0x1fec;
}







/* 021C812C  adds r0,#0x1c */
u8 *func_021C812C(u8 *p) { return p + 0x1c; }







/* 021C8130  movs r1,#0x3e; lsls r1,#4; adds r0,r0,r1 */
/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: movs r1, #0x3e; lsls r1, r1, #4; adds r0, r0, r1; bx lr.
 */
u8 *func_021C8130(u8 *p) { return p + 0x3e0; }






/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: ldr r0, [r0, #0x10]; lsls r0, r0, #0x10; lsrs r0, r0, #0x10; bx lr.
 */
u16 func_021C8138(struct Q7 *p) { return (u16)p->v; }






unsigned char func_021C8140(char *p, int i)
{
    return *(unsigned char *)(p + i + 0x7d9);
}





/*
 * ABI: ov095 D588 forwards the same table pointer and key to D5C8;
 * original keeps r1 live and has no narrowing, so retain a full-word key.
 */
int func_021C814C(u8 *p, int v) { return func_0689D588(p+0x1ab8,v); }






/*
 * Two tail thunks forwarding p->field4 to distinct callees.
 */
int func_021C815C(int *p)
{
    return func_021B8588((void **)(((struct Obj26329 *)p)->f4));
}






void func_021C8168(int *p)
{
    func_021B86B8((void ***)(((struct Obj26330 *)p)->f4));
}






int func_021C8174(int *p)
{
    return ((struct Obj18336 *)((char *)func_021B8714((char **)(((struct Obj18335 *)p)->f4))))->f4;
}






int func_021C8180(int *p)
{
    return func_021B8670((unsigned int **)(((struct Obj18337 *)p)->f4));
}





int func_021C818C(u8 *p, int v) { unsigned int species; u16 i; species=func_021D5444((struct QF *)func_021B9934(*(char * *)&((struct Obj13341 *)p)->f8,v)); for(i=0;i<7;i++) { if(func_0201B718(((struct Obj13341 *)p)->f4A4,species,0,i)) return 1; } return 0; }






u16 func_021C81C8(u8 *p, u8 *x, int flag)
{
    return func_021BC948(p, x, flag);
}






u16 func_021C81D0(u8 *p, u8 *a, u32 y)
{
    u32 it;
    u8 *x;
    u16 n;
    u32 base = func_021C81C8(p, a, y);
    int k = func_021D5440(a);
    n = 0;
    func_021BD2B4((u8 *)&it, (u8 **)p);
    while (func_021BD34C((u8 *)&it, (u8 **)p, &x)) {
        if (k != func_021D5440(x)) {
            if (func_021C81C8(p, x, y) > base) {
                n++;
            }
        }
    }
    return n;
}





/*
 * Wrapper family member; the body is the hand-checked shape of the family's first instance with only the member's constants substituted, per the family uniformity assertion in o36/report.md.
 */
int func_021C8234(u8 *p, int i) { return func_021C6F0C(p, func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, i), 1); }




int func_021C824C(u8 *p, int v) { void *m; m=func_021B9934(*(char * *)&((struct Obj21115 *)p)->f8,v); if(func_021D59B4(m,17)==103) return 0; if(func_021D62C4(m,19)) return 0; if(func_021EF948(7)==0) return 1; return 0; }





/*
 * tail-call thunk to func_021C2AB0
 */
int func_021C8288(u8 *p)
{
    return func_021C2AB0(p);
}




int func_021C8290(u8 *p, int a, int b, void *item) { u8 *x; x=func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8,a); return func_021BFA00(p,x,func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8,b),item); }




void func_021C82B8(int *p)
{
    func_021B911C(p[1]);
}




int func_021C82C4(int a, int b, int c)
{
    (void)a;
    return func_06898CF4(b, c);
}

/*
 * extent: two bytes alignment padding precede non-C veneer 021C82E4.
 */
int func_021C82D0(int unused, unsigned int v, int k) { return func_021C82E4(func_021B9AE0(v),k); }
