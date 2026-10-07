/*
 * file:     trcard_sys_p04.c
 * unit:     yes
 * function: func_0216F07C, func_0216F088, func_0216F0AC, func_0216F144, func_0216F174, func_0216F1E0, func_0216F228, func_0216F244
 * address:  0x0216F07C
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
 *   func_0203F0A8  0x0203F0A8  arm
 *   func_02031330  0x02031330  arm
 *   func_0203133C  0x0203133C  arm
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02030734  0x02030734  arm
 *   func_0216F40C  0x0216F40C  thumb  ov010
 *   d_02172B64     0x02172B64  data  ov010
 *   func_0216F288  0x0216F288  thumb
 *   func_0216F2B4  0x0216F2B4  thumb
 *   func_0216F2E0  0x0216F2E0  thumb
 *   func_0216F31C  0x0216F31C  thumb
 *   func_0216F378  0x0216F378  thumb
 *   func_0216F3B0  0x0216F3B0  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008554  0x02008554  thumb
 *   func_02027174  0x02027174  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 */
#include "../../matched/include/Obj09170.h"
#include "../../matched/include/Obj19150.h"
#include "../../matched/include/Obj07206.h"
#include "../../matched/include/Obj07207.h"
#include "../../matched/include/Obj09171.h"
#include "../../matched/include/Obj19151.h"
#include "../../matched/include/Obj01640.h"
#include "../../matched/include/Obj12408.h"
#include "../../matched/include/Obj19152.h"

struct Obj0203159C;
struct Profile;
struct Sub0200852CObj;
struct S020315D4;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    int w[6];
} T24;

typedef struct {
    u32 f00;
    u8 pad04[0x14];
    T24 *f18;
    int f1c;
} W_0216F0AC;

typedef struct { int w[8]; } W_0216F144;

extern u32 func_0203F0A8(void);
extern unsigned int func_02031330(void *p);
extern int func_0203133C();
extern void func_0203064C(unsigned int a, unsigned int b, unsigned int c);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *p, int v, int n);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_0216F40C(struct Profile *out, void *save, int mode, int flag, volatile u16 heap);
extern int func_0216F288(int *p);
extern int func_0216F2B4(char *p);
extern int func_0216F2E0(char *p);
extern int func_0216F31C(char *a);
extern int func_0216F378(char *p);
extern int func_0216F3B0(char *p);
extern u8 *func_02012944(void *p);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern int func_02027174();
extern int func_020307B0();
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
int func_0216F07C(int a0);
int func_0216F088(int a0);
int func_0216F0AC(void *a, int b, T24 *c);
int func_0216F144(void *a,int b,int c);
int func_0216F174(int a, int *b, int c, int d);
int func_0216F1E0(int a0, int a1, int a2, int a3);
int func_0216F228(void *a, int b, int c, char *d);
int func_0216F244(char *a, char *b);
extern char d_02172B64[];


int func_0216F07C(int a0)
{

    a0 = func_0203F0A8();
loc_0216F082:
    a0 = func_0203F0A8();
loc_0216F086:
    return a0;}


int func_0216F088(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj09170 *)((char *)t4))->f0;
    if (a0 == 0) goto loc_0216F0A8;
loc_0216F092:
    a0 = func_02031330((void *)a0);
loc_0216F096:
    if (a0 != 0) goto loc_0216F0A8;
loc_0216F09A:
a0 = ((struct Obj09170 *)((char *)t4))->f0;
    a0 = func_0203133C(a0);
loc_0216F0A0:
a0 = 0;
((struct Obj09170 *)((char *)t4))->f0 = a0;
a0 = 1;
    return a0;
loc_0216F0A8:
a0 = 0;
    return a0;}


int func_0216F0AC(void *a, int b, T24 *c)
{
    W_0216F0AC *w;

    func_0203064C(1, 0x26, 0x18000);
    w = func_0203159C(a, 0x20, 0x26);
    func_02082BCC(w, 0, 0x20);
    w->f00 = 0x26;
    w->f18 = func_02030734((u16)w->f00, 0x18, 1, d_02172B64, 0x9f);
    *w->f18 = *c;
    *(void **)w->f18 = func_02030734((u16)w->f00, 0x678, 1, d_02172B64, 0xa1);
    func_0216F40C(*(void **)w->f18, (void *)c->w[1], 0, w->f18->w[2], (u16)w->f00);
    w->f1c = ((struct Obj19150 *)(*(char **)w->f18))->f6;
    return 1;
}

int func_0216F144(void *a,int b,int c) { W_0216F144 *w; func_0203064C(1,38,0x18000); w=func_0203159C(a,32,38); func_02082BCC(w,0,32); w->w[0]=38; w->w[6]=c; return 1; }


int func_0216F174(int a, int *b, int c, int d)
{
    switch (*b) {
    case 0:
        *b = func_0216F244((char *)d, (char *)c);
        break;
    case 1:
        *b = func_0216F288((int *)d);
        break;
    case 2:
        *b = func_0216F2B4((char *)d);
        break;
    case 3:
        *b = func_0216F2E0((char *)d);
        break;
    case 4:
        *b = func_0216F31C((char *)d);
        break;
    case 5:
        *b = func_0216F378((char *)d);
        break;
    case 6:
        *b = func_0216F3B0((char *)d);
        break;
    case 7:
    default:
        return 1;
    }
    return 0;
}


/*
 * blocked:  listing 72 compiled 70
 */
int func_0216F1E0(int a0, int a1, int a2, int a3)
{
    int t4;
    int t5;
    int t6;
    u8 *p;

t5 = a2 + 0;
t6 = a0 + 0;
a0 = ((struct Obj09171 *)t5)->f8;
t4 = a3 + 0;
    if (a0 == 0) goto loc_0216F202;
loc_0216F1EE:
a0 = ((struct Obj09171 *)t5)->f4;
    p = func_02012944((void *)a0);
loc_0216F1F4:
    a0 = func_02008554((const struct Sub0200852CObj *)p);
loc_0216F1F8:
a1 = ((struct Obj07207 *)t4)->f1C;
    if (a1 == a0) goto loc_0216F202;
loc_0216F1FE:
    a0 = func_02027174(a0);
loc_0216F202:
a0 = ((struct Obj07207 *)t4)->f18;
a0 = ((struct Obj07206 *)a0)->f10;
((struct Obj09171 *)t5)->f10 = a0;
a0 = ((struct Obj07207 *)t4)->f18;
a0 = ((struct Obj07206 *)((char *)a0))->f0;
    a0 = func_020307B0(a0);
loc_0216F210:
a0 = ((struct Obj07207 *)t4)->f18;
    a0 = func_020307B0(a0);
loc_0216F216:
a0 = t6 + 0;
    func_020315D4((struct S020315D4 *)a0);
loc_0216F21C:
a0 = 0x26;
    func_020306F0(a0);
loc_0216F222:
a0 = 1;
    return a0;}


int func_0216F228(void *a, int b, int c, char *d)
{
    func_020307B0(((struct Obj19151 *)d)->f18);
    func_020315D4(a);
    func_020306F0(0x26);
    return 1;
}


int func_0216F244(char *a, char *b)
{
    char *q;

    switch (((struct Obj19152 *)b)->f14) {
    case 1:
        return 1;
    case 2:
        return 1;
    case 3:
        return 5;
    case 0:
    default:
        q = **(char ** *)&((struct Obj01640 *)a)->f18;
        if (((struct Obj12408 *)q)->f33 == 0 && ((struct Obj12408 *)q)->f1C != 0)
            return 5;
        return 1;
    }
}
