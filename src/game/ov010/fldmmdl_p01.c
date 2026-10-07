/*
 * file:     fldmmdl_p01.c
 * unit:     yes
 * function: func_0216BF38, func_0216BF74, func_0216BF9C, func_0216BFD4, func_0216C028, func_0216C0A4, func_0216C0C0, func_0216C0D4
 * address:  0x0216BF38
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
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200D418  0x0200D418  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0200D468  0x0200D468  thumb
 *   func_02008530 0x02008530 thumb
 *   func_0200C38C 0x0200C38C thumb
 *   d_02172508 0x02172508 data a4
 *   func_0200C39C 0x0200C39C thumb
 *   func_02030734  0x02030734  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02045838  0x02045838  arm
 *   d_02172A60     0x02172A60  data  ov010  a1
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02045808  0x02045808  arm
 *   func_020307B0  0x020307B0  arm
 */
#include "../../matched/include/Obj00005.h"
#include "../../matched/include/Obj03544.h"
#include "../../matched/include/Obj02352.h"
#include "../../matched/include/Obj17766.h"

struct Big;
struct Blk38;
struct Blk34;
struct Sub0200852CObj;
struct U16Vec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

extern void *func_0215A5E4(void *a0);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200D418(void *sys);
extern unsigned int func_02159B10(void *, void *);
extern unsigned short *func_02159AE8(void *a0, void *a1);
extern u8 func_0200D468(struct Blk38 *p, u32 i);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void func_0200C38C(struct Blk34 *p, s32 i, u32 v);
extern u32 func_0200C39C(struct Blk34 *p, s32 i);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *, int, int);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045838(struct U16Vec *dst, struct U16Vec *src);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern int func_02045808();
extern int func_020307B0();
int func_0216BF38(int a0, int a1);
void func_0216BF74(void *a, int i, void *b);
int func_0216BF9C(void *a, int i, void *b);
int *func_0216BFD4(unsigned short a0, int a1, short a2, short a3, int s0, int s1, int s2);
int *func_0216C028(unsigned short a0, int a1, int a2, int a3, int s0);
int *func_0216C0A4(unsigned short a, int b, int c, int d, int e, int f, int g, int h);
int func_0216C0C0(int a0);
void func_0216C0D4(int *p, int a1);
extern const u32 d_02172508[];
extern char d_02172A60[];


int func_0216BF38(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    void *t7;
    void *p;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    p = func_0215A5E4((void *)a0);
loc_0216BF44:
    p = func_02012EBC((struct Big *)p);
loc_0216BF48:
    t7 = func_0200D418(p);
loc_0216BF4C:
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_0216BF56:
a0 = a0 << 0x18;
t4 = (unsigned)a0 >> 0x18;
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = (int)func_02159AE8((void *)a0, (void *)a1); /* int-typed on purpose: pointer local changes codegen */
loc_0216BF62:
t5 = a0 + 0;
a1 = t4 + 0;
    a0 = func_0200D468(t7, a1);
loc_0216BF6C:
*(u16 *)&((struct Obj00005 *)((char *)t5))->f0 = a0;
a0 = 0;
    return a0;}

void func_0216BF74(void *a, int i, void *b) {
    if(i<8) func_0200C38C(a,i,func_02008530(b)^*(const u32 *)((u32)d_02172508+(u32)i*4));
}

/*
 * lever: named second call-result local preserves the original comparison registers.
 */
int func_0216BF9C(void *a, int i, void *b) {
    u32 v; u32 x;
    if(i>=8) return 0;
    v=func_02008530(b);
    x=func_0200C39C(a,i);
    if((x^v)==*(const u32 *)((u32)d_02172508+(u32)i*4)) return 1;
    return 0;
}


/*
 * The heap id is a u16: as an int its entry spill (str r0,[sp,#4]) sinks
 * below the stack-argument setup. func_02045838 takes the flag as its second
 * argument, which is why the image loads it into r1 ahead of the p[8] store.
 */
int *func_0216BFD4(unsigned short a0, int a1, short a2, short a3, int s0, int s1, int s2)
{
    int *p = (int *)func_02030734(a0, 0x2c, 0, d_02172A60, 0x37);
    func_02082BCC(p, 0, 0x2c);
    p[0] = a1;
    p[6] = s0;
    ((struct Obj03544 *)p)->f4 = a2;
    ((struct Obj03544 *)p)->f6 = a3;
    p[10] = s2;
    p[8] = (int)func_020457B0(0xb, a0);
    if (s1)
        func_02045838((struct U16Vec *)p[8], (struct U16Vec *)s1);
    return p;
}


/*
 * The heap id is a u16, as in func_0216BFD4; that keeps its entry spill
 * at the front of the prologue.
 */
int *func_0216C028(unsigned short a0, int a1, int a2, int a3, int s0)
{
    int *p = (int *)func_02030734(a0, 0x2c, 0, d_02172A60, 0x59);
    func_02082BCC(p, 0, 0x2c);
    p[0] = 1;
    p[6] = a2;
    p[2] = a1;
    p[10] = s0;
    if (a1) {
        int t;
        ((struct Obj02352 *)p)->f4 = func_02017E1C((void *)a1, 5, 0);
        t = func_02017E1C((void *)a1, 0x6f, 0);
        ((struct Obj02352 *)p)->f6 = (func_02017E1C((void *)a1, 0x6e, 0) << 8) | t;
    }
    p[8] = (int)func_020457B0(0xb, a0);
    if (a3)
        func_02045838((struct U16Vec *)p[8], (struct U16Vec *)a3);
    return p;
}

int *func_0216C0A4(unsigned short a, int b, int c, int d, int e, int f, int g, int h) {
    int *p;
    p = func_0216C028(a,b,c,d,h);
    p[3]=e; p[4]=f; p[5]=g;
    return p;
}


int func_0216C0C0(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj17766 *)t4)->f20;
    a0 = func_02045808(a0);
loc_0216C0CA:
a0 = t4 + 0;
    a0 = func_020307B0(a0);
loc_0216C0D0:
    return a0;}


void func_0216C0D4(int *p, int a1)
{
    func_02045838((struct U16Vec *)a1, (struct U16Vec *)p[8]);
}
