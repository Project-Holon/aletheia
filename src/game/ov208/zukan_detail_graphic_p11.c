/*
 * file:     zukan_detail_graphic_p11.c
 * unit:     yes
 * function: func_021BD844, func_021BD848, func_021BD868, func_021BD878, func_021BD880, func_021BD89C, func_021BD8C0, func_021BD954, func_021BD974, func_021BDAAC, func_021BDAD0, func_021BDAD4, func_021BDAE8
 * address:  0x021BD844
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B878 0x0204B878 arm
 *   func_02030734 0x02030734 arm
 *   func_02040618 0x02040618 arm
 *   func_0204047C 0x0204047C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_021BDCF8 0x021BDCF8 thumb ov208
 *   func_021BD358 0x021BD358 thumb ov208
 *   func_021BDD48 0x021BDD48 thumb ov208
 *   func_021BDCDC 0x021BDCDC thumb ov208
 *   func_020056A0 0x020056A0 thumb
 *   d_021C8DE4 0x021C8DE4 data a1
 *   func_02030EAC 0x02030EAC arm
 *   func_021BDD24 0x021BDD24 thumb
 *   func_0204B1CC 0x0204B1CC arm
 *   func_020307B0 0x020307B0 arm
 *   func_02040804 0x02040804 arm
 *   func_02041EE4 0x02041EE4 arm
 *   func_021BD23C 0x021BD23C thumb
 *   func_021BDFDC 0x021BDFDC thumb
 *   func_021BE20C 0x021BE20C thumb
 *   func_021BE6A8 0x021BE6A8 thumb
 *   d_021C8388 0x021C8388 data a4
 *   d_021C8384 0x021C8384 data a1
 */
#include "../../matched/include/Obj18242.h"
#include "../../matched/include/Obj05536.h"
#include "../../matched/include/Obj14647.h"
#include "../../matched/include/Obj18243.h"
#include "../../matched/include/Obj05866.h"
#include "../../matched/include/Obj12118.h"
#include "../../matched/include/Obj01080.h"
#include "../../matched/include/Obj02345.h"

struct Obj;
struct Bank;
struct Ov208Scene;
struct Node;
struct Ov208Menu;
struct Ov208Pal;
typedef unsigned short u16;

typedef unsigned int   u32;

struct Ov208Mgr { char pad[0x28]; void *f28; void *f2c; };

typedef unsigned char u8;

typedef short s16_021BD974;

struct Ov208Fade_021BD974 {
    int f0; int f4; int state; int fc; int mode; int f14; int f18; int f1c;
    int idx;
    u8 cnt;
    char pad25[0x0b];
    void *f30; int f34; char pad38[0x7c];
    s16_021BD974 pos;
};

typedef signed int     s32;

typedef signed short   s16_021BDAAC;

struct Ov208ActDesc {
    int f0;
    s16_021BDAAC x;
    s16_021BDAAC y;
    u16 h8;
    u16 ha;
    u16 hc;
    u16 he;
    u16 h10;
    u16 h12;
    u16 h14;
    u16 h16;
    u32 f18;
    u32 f1c;
};

struct Ov208ActList {
    struct Ov208ActDesc *descs;
    u32 count;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
};

struct Ov208ActSrc {
    int id;
    u16 x;
    u16 y;
    u16 h8;
    u16 pad;
    u32 fc;
    u32 f10;
};

struct Ov208Slot {
    struct Ov208ActSrc *src;
    u32 obj;
};

struct Ov208Scene {
    u16 heap;
    u16 pad2;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 mgr;
    u32 f34;
    u32 f38;
    u32 f3c;
    u32 f40;
    u32 f44;
    u32 f48;
    u32 f4c;
    u32 f50;
    u32 f54;
    u32 f58;
    u32 f5c;
    u32 f60;
    u32 f64;
    u8  count;
    u8  pad69[3];
    struct Ov208Slot slots[10];
};

struct Ov208Fade_021BDAD0 {
    u32 f0;
    u32 f4;
    int state;
};

struct Ov208Fade_021BDAD4 {
    u32 f0;
    u32 f4;
    int state;
    u32 pad[5];
    int arg;
    u8  step;
};

extern void func_0204B878(struct Obj *p, u16 value);
extern void func_020061E4(u32 a);
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void func_02040618(unsigned,unsigned,unsigned);
extern void func_0204047C(int,u16);
extern struct Bank *func_0204B100(int,unsigned char,unsigned);
extern void func_0204B270(struct Bank *);
extern void func_021BDCF8(struct Ov208Scene *);
extern void func_021BD358(char *p, int v);
extern void func_021BDD48(char *,short);
extern void func_021BDCDC(int,char *);
extern void *func_020056A0(unsigned,unsigned,unsigned);
extern void func_02030EAC(struct Node *n);
extern void func_021BDD24(char *p);
extern unsigned int func_0204B1CC(struct Bank *bank);
extern u32 func_020307B0(void *p);
extern u32 func_02040804(u32 layer);
extern void func_02041EE4(u32 index, u32 a, u32 b);
extern void func_021BD23C(char *p);
extern void func_021BDFDC(struct Ov208Menu *m);
extern s32 func_021BE20C(struct Ov208Pal *m);
extern void func_021BE6A8(char *p);
void func_021BD844(char *p, int v);
void func_021BD848(char *p, int which);
int func_021BD868(const void *p);
void func_021BD878(char *p);
void func_021BD880(char *p);
void func_021BD89C(char *p);
char *func_021BD8C0(u16 heap,unsigned arg);
void func_021BD954(struct Ov208Mgr *m);
void func_021BD974(struct Ov208Fade_021BD974 *m);
void ov208_func_021BDAAC(struct Ov208Scene *p, u32 mode, u32 kind, u32 flag);
int ov208_func_021BDAD0(struct Ov208Fade_021BDAD0 *p);
void ov208_func_021BDAD4(struct Ov208Fade_021BDAD4 *p, int v);
void func_021BDAE8(char *p, int v);
extern const char d_021C8DE4[];
extern const int d_021C8388[];
extern const u8 d_021C8384[];



void func_021BD844(char *p, int v)
{
    ((struct Obj18242 *)p)->f2C = v;
}


void func_021BD848(char *p, int which)
{
    if (which != 0)
    {
        ((struct Obj05536 *)p)->f8 = ((struct Obj05536 *)p)->f28;
    }
    else
    {
        ((struct Obj05536 *)p)->f8 = ((struct Obj05536 *)p)->f24;
    }
    func_0204B878(((struct Obj05536 *)p)->f0, (unsigned short)((struct Obj05536 *)p)->f8);
}


int func_021BD868(const void *p)
{
    u32 r1 = ((struct Obj14647 *)p)->f8;
    u32 r0 = ((struct Obj14647 *)p)->f28;
    return r1 == r0;
}



/*
 * Clears the word at +0x34.
 */
void func_021BD878(char *p)
{
    ((struct Obj18243 *)p)->f34 = 0;
}


/*
 * Re-verified 2026-09-27 (DIFF fixer lane): the +8 store in the image is a
 * full word, `str r1,[r4,#8]`, not `strh`: the zero-extended u16 is written
 * through an int lvalue.  With `*(int *)(p + 8) = h;` the whole function
 * reproduces, including `ldrh r1,[r4,#0x28]; ldr r0,[r4]; str r1,[r4,#8]`.
 * EXACT*: the inferred extent runs 2 bytes past `pop` (an unlabelled
 * follower/alignment word), never a byte difference.
 */
void func_021BD880(char *p)
{
    unsigned short h = ((struct Obj05866 *)p)->f28;
    int v = ((struct Obj05866 *)p)->f0;

    ((struct Obj05866 *)p)->f8 = h;
    func_0204B878((struct Obj *)v, h);
    if (((struct Obj05866 *)p)->f30 != 0)
        func_020061E4(((struct Obj05866 *)p)->f30);
}


void func_021BD89C(char *p)
{
    int f = func_021BD868(p) == 0;

    func_021BD848(p, f);
    if (((struct Obj12118 *)p)->f30 != 0)
        func_020061E4(((struct Obj12118 *)p)->f30);
}

char *func_021BD8C0(u16 heap,unsigned arg)
{
    char *p=func_02030734(heap,0x11c,1,d_021C8DE4,0x148);
    ((struct Obj01080 *)p)->f0=heap;((struct Obj01080 *)p)->f4=arg;
    ((struct Obj01080 *)p)->f8=0;((struct Obj01080 *)p)->fC=0;((struct Obj01080 *)p)->f10=0;
    ((struct Obj01080 *)p)->f14=1;((struct Obj01080 *)p)->f18=0;((struct Obj01080 *)p)->f1C=0;((struct Obj01080 *)p)->f20=0;
    func_02040618(1,3,-24);func_0204047C(1,0);
    p[0x38]=0;((struct Obj01080 *)p)->f3C=0;
    *(struct Bank * *)&((struct Obj01080 *)p)->f28=func_0204B100(16,0,((struct Obj01080 *)p)->f0);
    func_0204B270(*(struct Bank * *)&((struct Obj01080 *)p)->f28);
    *(unsigned *)&((struct Obj01080 *)p)->f30=0;func_021BDCF8((struct Ov208Scene *)p);
    func_021BD358(((struct Obj01080 *)p)->f30,0);
    ((struct Obj01080 *)p)->fB4=24;func_021BDD48(p,((struct Obj01080 *)p)->fB4);
    ((struct Obj01080 *)p)->f2C=func_020056A0((unsigned)func_021BDCDC,(unsigned)p,1);
    return p;
}

/*
 * tail: two zero alignment bytes after the function (listing extent is 2 bytes longer).
 */
void func_021BD954(struct Ov208Mgr *m)
{
    func_02030EAC(m->f2c);
    func_021BDD24((char *)m);
    func_0204B1CC(m->f28);
    func_020307B0(m);
}

void func_021BD974(struct Ov208Fade_021BD974 *m)
{
    int v;
    switch (m->state) {
    case 0:
    case 2:
        break;
    case 1:
        if (m->cnt == 0) {
            if ((int)func_02040804((int)1) >= 0) {
                func_02041EE4(1, 3, 0);
                m->pos = 0;
                func_021BDD48((char *)m, m->pos);
                m->state = 2;
                if (m->f34 != 0)
                    func_021BD358(m->f30, 1);
                break;
            }
            func_02041EE4(1, 4, d_021C8388[m->idx]);
            m->pos = m->pos - (s16_021BD974)d_021C8388[m->idx];
            func_021BDD48((char *)m, m->pos);
            m->cnt = d_021C8384[m->idx];
        } else {
            m->cnt--;
        }
        break;
    case 3:
        if (m->cnt == 0) {
            if ((int)func_02040804((int)1) <= -24) {
                func_02041EE4(1, 3, -24);
                m->pos = 24;
                func_021BDD48((char *)m, m->pos);
                m->state = 0;
            } else {
                func_02041EE4(1, 5, d_021C8388[m->idx]);
                m->pos = m->pos + (s16_021BD974)d_021C8388[m->idx];
                func_021BDD48((char *)m, m->pos);
                m->cnt = d_021C8384[m->idx];
            }
        } else {
            m->cnt--;
        }
        break;
    }
    func_021BD23C(m->f30);
    if (m->mode == 0) {
        func_021BDFDC((struct Ov208Menu *)m);
        func_021BE20C((struct Ov208Pal *)m);
    } else if (m->mode == 2) {
        func_021BE6A8((char *)m);
    }
}


void ov208_func_021BDAAC(struct Ov208Scene *p, u32 mode, u32 kind, u32 flag)
{
    p->fc = p->f10;
    p->f10 = mode;
    p->f14 = p->f18;
    p->f18 = kind;
    p->f40 = flag;
    func_021BDD24((char *)p);
    p->f1c = p->f18;
    func_021BDCF8(p);
}


int ov208_func_021BDAD0(struct Ov208Fade_021BDAD0 *p)
{
    return p->state;
}


void ov208_func_021BDAD4(struct Ov208Fade_021BDAD4 *p, int v)
{
    p->arg = v;
    if (p->state != 2) {
        p->state = 1;
        p->step = 0;
    }
}


/*
 * Stores the argument at +0x20 and, when +8 is set, restarts it at state 3.
 */
void func_021BDAE8(char *p, int v)
{
    ((struct Obj02345 *)p)->f20 = v;
    if (((struct Obj02345 *)p)->f8 != 0) {
        ((struct Obj02345 *)p)->f8 = 3;
        p[0x24] = 0;
        func_021BD358(*(char * *)&((struct Obj02345 *)p)->f30, 0);
    }
}
